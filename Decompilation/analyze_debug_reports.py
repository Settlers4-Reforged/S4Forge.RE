#!/usr/bin/env python3
"""
Analyzes .cpp files to find BBSupportDbgReport calls and verifies that the
file path in the second argument matches the actual file path.
"""

import os
import re
import sys
from pathlib import Path
from typing import List, Tuple, Dict
from collections import defaultdict


def find_bbsupport_calls(file_path: Path, content: str) -> List[Tuple[int, str, str]]:
    """
    Find all BBSupportDbgReport calls in the file content.
    
    Returns:
        List of tuples: (line_number, reported_path, full_match)
    """
    results = []
    
    # Pattern to match BBSupportDbgReport with the file path as second argument
    # BBSupportDbgReport(number, "path/to/file", line_num, "condition")
    pattern = r'BBSupportDbgReport\s*\(\s*\d+\s*,\s*(?:\(\w+\))?"([^"]+)"'
    
    lines = content.split('\n')
    for line_num, line in enumerate(lines, 1):
        matches = re.finditer(pattern, line)
        for match in matches:
            reported_path = match.group(1)
            results.append((line_num, reported_path, match.group(0)))
    
    return results


def normalize_path(path_str: str) -> str:
    """Normalize a path string for comparison (forward slashes, lowercase)."""
    return path_str.replace('\\', '/').lower()


def normalize_folder_to_pascalcase(folder_path: str) -> str:
    """
    Normalize a folder path to PascalCase format.
    Example: "main//states//" -> "Main/States/"
    """
    # Replace backslashes with forward slashes
    folder_path = folder_path.replace('\\', '/')
    
    # Remove trailing slash if present
    folder_path = folder_path.rstrip('/')
    
    # Split into path segments
    segments = [seg for seg in folder_path.split('/') if seg]
    
    # Capitalize first letter of each segment
    normalized_segments = []
    for segment in segments:
        # Handle special cases like "AI" which should stay uppercase
        if segment.upper() == segment and len(segment) <= 3:
            # Likely an acronym, keep as is
            normalized_segments.append(segment)
        else:
            # Capitalize first letter, keep rest as is (to preserve camelCase)
            normalized_segments.append(segment[0].upper() + segment[1:] if segment else segment)
    
    # Join back with single slashes and add trailing slash
    return '/'.join(normalized_segments) + '/' if normalized_segments else ''


def analyze_file(file_path: Path, base_dir: Path) -> Tuple[List[dict], List[str]]:
    """
    Analyze a single .cpp file for BBSupportDbgReport mismatches.
    
    Returns:
        Tuple of (mismatches list, reported_paths list)
    """
    mismatches = []
    reported_paths = []
    
    try:
        with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
    except Exception as e:
        print(f"Error reading {file_path}: {e}", file=sys.stderr)
        return mismatches, reported_paths
    
    calls = find_bbsupport_calls(file_path, content)
    
    # Get relative path from base directory
    try:
        relative_path = file_path.relative_to(base_dir)
    except ValueError:
        # File is not relative to base_dir, use absolute path
        relative_path = file_path
    
    relative_path_str = str(relative_path)
    normalized_actual = normalize_path(relative_path_str)
    
    for line_num, reported_path, full_match in calls:
        reported_paths.append(reported_path)
        normalized_reported = normalize_path(reported_path)
        
        # Check if paths match
        if normalized_actual != normalized_reported:
            # Also check if the reported path is a suffix of actual path
            # (in case of different base directories)
            if not normalized_actual.endswith(normalized_reported):
                mismatches.append({
                    'file': str(file_path),
                    'line': line_num,
                    'actual_path': relative_path_str,
                    'reported_path': reported_path,
                    'match_text': full_match
                })
    
    return mismatches, reported_paths


def analyze_directory(directory: Path, recursive: bool = True) -> dict:
    """
    Analyze all .cpp files in a directory.
    
    Returns:
        Dictionary with statistics and list of all mismatches
    """
    results = {
        'files_analyzed': 0,
        'files_with_calls': 0,
        'total_calls': 0,
        'mismatches': [],
        'files_with_mismatches': set(),
        'folder_map': defaultdict(list)
    }
    
    # Find all .cpp files
    if recursive:
        cpp_files = list(directory.rglob('*.cpp'))
    else:
        cpp_files = list(directory.glob('*.cpp'))
    
    for cpp_file in cpp_files:
        results['files_analyzed'] += 1
        mismatches, reported_paths = analyze_file(cpp_file, directory)
        
        if mismatches:
            results['files_with_mismatches'].add(str(cpp_file))
            results['mismatches'].extend(mismatches)
        
        # Build folder map from reported paths
        if reported_paths:
            # Extract class name from filename (remove .cpp extension)
            class_name = cpp_file.stem
            
            # Use the first reported path to determine folder
            # (assuming all paths in a file should be the same)
            if reported_paths:
                reported_path = reported_paths[0]
                # Normalize to forward slashes
                folder = reported_path.replace('\\', '/')
                # Extract directory part
                folder_parts = folder.rsplit('/', 1)
                if len(folder_parts) == 2:
                    folder_dir = normalize_folder_to_pascalcase(folder_parts[0])
                    results['folder_map'][folder_dir].append(class_name)
    
    return results


def print_results(results: dict, verbose: bool = False):
    """Print analysis results in a readable format."""
    print("=" * 80)
    print("BBSupportDbgReport File Path Analysis")
    print("=" * 80)
    print(f"\nFiles analyzed: {results['files_analyzed']}")
    print(f"Files with mismatches: {len(results['files_with_mismatches'])}")
    print(f"Total mismatches found: {len(results['mismatches'])}")
    
    if results['mismatches']:
        print("\n" + "=" * 80)
        print("MISMATCHES FOUND:")
        print("=" * 80)
        
        # Group by file
        by_file = {}
        for mismatch in results['mismatches']:
            file_path = mismatch['file']
            if file_path not in by_file:
                by_file[file_path] = []
            by_file[file_path].append(mismatch)
        
        for file_path in sorted(by_file.keys()):
            print(f"\n[FILE] {file_path}")
            for mismatch in by_file[file_path]:
                print(f"  Line {mismatch['line']}:")
                print(f"    Actual path:   {mismatch['actual_path']}")
                print(f"    Reported path: {mismatch['reported_path']}")
                if verbose:
                    print(f"    Match: {mismatch['match_text']}")
    else:
        print("\n✓ All BBSupportDbgReport calls have correct file paths!")


def print_folder_map(folder_map: Dict[str, List[str]]):
    """Print the folder map in Python dictionary format."""
    print("\n" + "=" * 80)
    print("FOLDER_MAP (Python format):")
    print("=" * 80)
    print("\nFOLDER_MAP = {")
    
    for folder in sorted(folder_map.keys()):
        classes = sorted(folder_map[folder])
        print(f'    "{folder}": [')
        for class_name in classes:
            print(f'        "{class_name}",')
        print("    ],")
        print()
    
    print("}")
    print("\nCopy this FOLDER_MAP into your class_creator.py file.")


def main():
    """Main entry point."""
    import argparse
    
    parser = argparse.ArgumentParser(
        description='Analyze .cpp files for BBSupportDbgReport file path mismatches'
    )
    parser.add_argument(
        'directory',
        type=str,
        nargs='?',
        default='.',
        help='Directory to analyze (default: current directory)'
    )
    parser.add_argument(
        '--no-recursive',
        action='store_true',
        help='Do not search recursively'
    )
    parser.add_argument(
        '-v', '--verbose',
        action='store_true',
        help='Show verbose output including match text'
    )
    parser.add_argument(
        '--export',
        type=str,
        help='Export results to a JSON file'
    )
    parser.add_argument(
        '--show-folder-map',
        action='store_true',
        help='Display FOLDER_MAP in Python format for class_creator.py'
    )
    parser.add_argument(
        '--export-folder-map',
        type=str,
        help='Export FOLDER_MAP to a Python file'
    )
    
    args = parser.parse_args()
    
    directory = Path(args.directory).resolve()
    
    if not directory.exists():
        print(f"Error: Directory '{directory}' does not exist", file=sys.stderr)
        sys.exit(1)
    
    if not directory.is_dir():
        print(f"Error: '{directory}' is not a directory", file=sys.stderr)
        sys.exit(1)
    
    print(f"Analyzing directory: {directory}")
    print(f"Recursive: {not args.no_recursive}\n")
    
    results = analyze_directory(directory, recursive=not args.no_recursive)
    
    # Convert set to list for JSON serialization
    results['files_with_mismatches'] = list(results['files_with_mismatches'])
    
    # Convert defaultdict to regular dict for JSON serialization
    folder_map = dict(results['folder_map'])
    results['folder_map'] = folder_map
    
    print_results(results, verbose=args.verbose)
    
    # Show folder map if requested
    if args.show_folder_map and folder_map:
        print_folder_map(folder_map)
    
    if args.export:
        import json
        export_path = Path(args.export)
        with open(export_path, 'w', encoding='utf-8') as f:
            json.dump(results, f, indent=2)
        print(f"\n\nResults exported to: {export_path}")
    
    if args.export_folder_map and folder_map:
        export_path = Path(args.export_folder_map)
        with open(export_path, 'w', encoding='utf-8') as f:
            f.write("# Generated FOLDER_MAP from BBSupportDbgReport analysis\n")
            f.write("# Copy this into your class_creator.py file\n\n")
            f.write("FOLDER_MAP = {\n")
            for folder in sorted(folder_map.keys()):
                classes = sorted(folder_map[folder])
                f.write(f'    "{folder}": [\n')
                for class_name in classes:
                    f.write(f'        "{class_name}",\n')
                f.write("    ],\n\n")
            f.write("}\n")
        print(f"\nFOLDER_MAP exported to: {export_path}")
    
    # Exit with error code if mismatches found
    sys.exit(0 if not results['mismatches'] else 1)


if __name__ == '__main__':
    main()
