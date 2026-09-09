#ifndef MAPACCESS_S4_H
#define MAPACCESS_S4_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <functional>

#include "../../S4_Main/src/MapAccess/MapAccess.h"

#include <optional>

using OpenMapFileFT = void __stdcall(unsigned short *, int *, int *, int);
using GetPlayerDataFT = void __stdcall(int, int, int *, int *, int *, unsigned short **, unsigned short **, int *, int *, int *);
struct MapAccessS4 {
    std::function<decltype(GetMapAccessInterfaceVersion)> _GetMapAccessInterfaceVersion;
    std::function<OpenMapFileFT> _OpenMapFile;
    std::function<decltype(MA_GetMapData)> _GetMapData;
    std::function<GetPlayerDataFT> _GetPlayerData;
};

inline std::optional<MapAccessS4> LoadOriginalLibrary() {
    const auto sPath = MA_TEST_FIXTURE_DIR "/MapAccess.S4.dll";
    auto hLib = LoadLibrary(sPath);
    if(!hLib) {
        FAIL("Failed to load MapAccess.S4.dll" << " Error: " << std::hex << GetLastError());
        return std::nullopt;
    }

    MapAccessS4 sLib;
    sLib._GetMapAccessInterfaceVersion = GetProcAddress(hLib, "?GetMapAccessInterfaceVersion@@YGHXZ");
    sLib._OpenMapFile = reinterpret_cast<OpenMapFileFT *>(GetProcAddress(hLib, "?MA_OpenMapFile@@YGXPAGPAH1H@Z"));
    sLib._GetMapData = reinterpret_cast<decltype(MA_GetMapData) *>(GetProcAddress(hLib, "?MA_GetMapData@@YGXPAH0000@Z"));
    sLib._GetPlayerData = reinterpret_cast<GetPlayerDataFT *>(GetProcAddress(hLib, "?MA_GetPlayerData@@YGXHHPAH00PAPAG1000@Z"));

    return sLib;
}

#endif // MAPACCESS_S4_H
