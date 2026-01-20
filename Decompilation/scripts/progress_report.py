#!/usr/bin/env python3
"""
Progress Report Generator
Creates a visual progress report image showing decompilation progress.
"""

import os
from pathlib import Path
from PIL import Image, ImageDraw, ImageFont
import argparse


def count_files_recursively(directory):
    """Count all files recursively in a directory."""
    count = 0
    path = Path(directory)
    if path.exists():
        for item in path.rglob('*'):
            if item.is_file():
                count += 1
    return count


def get_file_paths_recursively(directory):
    """Get all file paths recursively in a directory."""
    paths = set()
    path = Path(directory)
    if path.exists():
        for item in path.rglob('*'):
            if item.is_file():
                paths.add(item.relative_to(path))
    return paths


def calculate_progress(generated_dir, src_dir):
    """
    Calculate progress based on files in generated vs src.
    Only files that exist in generated count towards completion.
    
    Returns:
        tuple: (completed_count, total_count, percentage)
    """
    # Get all files in generated directory
    generated_files = get_file_paths_recursively(generated_dir)
    total = len(generated_files)
    
    if total == 0:
        return 0, 0, 0.0
    
    # Count how many of those files exist in src
    completed = 0
    src_path = Path(src_dir)
    
    for rel_path in generated_files:
        src_file = src_path / rel_path
        exists = src_file.exists()

        print(f"File {src_file} found: {exists}")

        if exists:
            completed += 1
    
    percentage = (completed / total) * 100 if total > 0 else 0
    
    return completed, total, percentage


def create_progress_image(header_image_path, completed, total, output_path, 
                          bar_width=500, bar_height=60, padding=20):
    """
    Create a progress report image with header image and progress bar.
    
    Args:
        header_image_path: Path to the header image
        completed: Number of completed files
        total: Total number of files
        output_path: Path to save the output image
        bar_width: Width of the progress bar
        bar_height: Height of the progress bar
        padding: Padding around elements
    """
    # Load header image
    header = Image.open(header_image_path)
    
    header = header.resize((bar_width - 2*padding, int(bar_width / header.width * header.height)))

    # Calculate dimensions
    img_width = max(header.width, bar_width + 2 * padding)
    bar_section_height = bar_height + 2 * padding
    img_height = header.height + bar_section_height
    
    # Create new image with white background
    img = Image.new('RGBA', (img_width, img_height), color=(0,0,0,0))
    
    # Paste header image centered
    header_x = (img_width - header.width) // 2
    img.paste(header, (header_x, 0))
    
    # Draw progress bar
    draw = ImageDraw.Draw(img)
    
    # Calculate bar position (centered)
    bar_x = (img_width - bar_width) // 2
    bar_y = header.height + padding
    
    # Draw bar background (white with black border)
    draw.rectangle(
        [(bar_x, bar_y), (bar_x + bar_width, bar_y + bar_height)],
        fill='white',
        outline='black',
        width=3
    )
    
    # Draw progress fill (black)
    if total > 0:
        progress_ratio = completed / total
        fill_width = int((bar_width - 6) * progress_ratio)  # -6 for border
        if fill_width > 0:
            draw.rectangle(
                [(bar_x + 3, bar_y + 3), 
                 (bar_x + 3 + fill_width, bar_y + bar_height - 3)],
                fill='black'
            )
    
    # Draw progress text
    percentage = (completed / total * 100) if total > 0 else 0
    progress_text = f"{completed}/{total} ({percentage:.1f}%)"
    
    # Try to load a nice font, fall back to default if not available
    font = None
    font_candidates = [
        "consola.ttf",  # Windows Consolas
        "Consola.ttf",  # Windows Consolas (alt case)
        "/usr/share/fonts/truetype/inconsolata/Inconsolata-Regular.ttf",  # Linux Inconsolata
        "/usr/share/fonts/truetype/liberation/LiberationMono-Regular.ttf",  # Linux Liberation Mono
        "/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf",  # Linux DejaVu Sans Mono
        "Arial.ttf",  # Generic fallback
    ]
    
    for font_path in font_candidates:
        try:
            font = ImageFont.truetype(font_path, 32)
            break
        except:
            continue
    
    if font is None:
        font = ImageFont.load_default(32)
    
    # Get text bounding box for centering
    bbox = draw.textbbox((0, 0), progress_text, font=font)
    text_width = bbox[2] - bbox[0]
    text_height = bbox[3] - bbox[1]
    
    text_x = bar_x + (bar_width - text_width) // 2
    text_y = bar_y + (bar_height - text_height) // 2
    
    # Draw text with outline for better visibility
    # Determine text color based on progress (white on black fill, black on white)
    if total > 0 and (completed / total) > 0.5:
        # If more than 50% filled, use both colors
        # Draw black text on white part
        outline_color = 'white'
        text_color = 'black'
        
        # Draw white outline
        for offset_x in [-2, -1, 0, 1, 2]:
            for offset_y in [-2, -1, 0, 1, 2]:
                if offset_x != 0 or offset_y != 0:
                    draw.text((text_x + offset_x, text_y + offset_y), 
                            progress_text, font=font, fill=outline_color)
        
        # Draw main text
        draw.text((text_x, text_y), progress_text, font=font, fill=text_color)
    else:
        # Just draw black text for simplicity
        draw.text((text_x, text_y), progress_text, font=font, fill='black')
    
    # Save the image
    img.save(output_path)
    print(f"Progress report saved to: {output_path}")


def main():
    parser = argparse.ArgumentParser(
        description='Generate a progress report image for S4 decompilation project'
    )
    parser.add_argument(
        'header_image',
        default='./report/logo.png',
        help='Path to the header image to use'
    )
    parser.add_argument(
        '-o', '--output',
        default='./report/report.png',
        help='Output image path (default: ./report/report.png)'
    )
    parser.add_argument(
        '--generated-dir',
        default='../S4_Main/generated',
        help='Path to generated directory (default: ../S4_Main/generated)'
    )
    parser.add_argument(
        '--src-dir',
        default='../S4_Main/src',
        help='Path to src directory (default: ../S4_Main/src)'
    )
    parser.add_argument(
        '--bar-width',
        type=int,
        default=500,
        help='Width of progress bar in pixels (default: 500)'
    )
    parser.add_argument(
        '--bar-height',
        type=int,
        default=60,
        help='Height of progress bar in pixels (default: 60)'
    )
    
    args = parser.parse_args()
    
    # Resolve paths relative to script location
    script_dir = Path(__file__).parent
    generated_dir = (script_dir / args.generated_dir).resolve()
    src_dir = (script_dir / args.src_dir).resolve()
    
    print(f"Counting files in generated: {generated_dir}")
    print(f"Checking against src: {src_dir}")
    
    # Calculate progress
    completed, total, percentage = calculate_progress(generated_dir, src_dir)
    
    print(f"\nProgress: {completed}/{total} files ({percentage:.1f}%)")
    
    # Create progress image
    create_progress_image(
        args.header_image,
        completed,
        total,
        args.output,
        bar_width=args.bar_width,
        bar_height=args.bar_height
    )


if __name__ == '__main__':
    main()
