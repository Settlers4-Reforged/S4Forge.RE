#ifndef FILEPATHS_H
#define FILEPATHS_H

#include <string>

#include "PathSplitResult.h"

namespace FilePaths {
    // address=[0x2efe0d0]
    PathSplitResult __cdecl SplitPath(std::wstring const &);

    // address=[0x2efe3b0]
    std::wstring __cdecl GetCurrentWorkingDirectory();

    // address=[0x2efe3e0]
    std::wstring __cdecl GetUserDirectoryPath();

    // address=[0x2efe550]
    void __cdecl EnsurePathExists(std::wstring const &);

    // address=[0x2efe8b0]
    bool __cdecl FileExists(std::wstring const &);
} // namespace FilePaths

#endif // FILEPATHS_H