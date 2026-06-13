#ifndef MAPFILEPATHS_H
#define MAPFILEPATHS_H

#include <string>

namespace MapFilePaths {
    // address=[0x136b250]
    std::wstring __cdecl GetMapDirectoryPath(int);

    // address=[0x136b340]
    std::wstring __cdecl GetMapFilePatternOfDirectory(int);

    // address=[0x136b3e0]
    std::wstring __cdecl GetFilePathForMapName(std::wstring const &);

} // namespace MapFilePaths

#endif // MAPFILEPATHS_H
