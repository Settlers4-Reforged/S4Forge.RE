#ifndef CGAMERUN_H
#define CGAMERUN_H

#include "defines.h"

class CGameRun {
public:
    // address=[0x14821f0]
    static bool __cdecl Init(void);

    // address=[0x14828c0]
    static bool __cdecl Run(void);

    // address=[0x1482c40]
    static bool __cdecl Exit(void);

    // address=[0x1482e30]
    static bool __cdecl LoadGame(std::wstring & a1);

    // address=[0x1483510]
    static bool __cdecl SaveGame(std::wstring & a1);

    // address=[0x1483ab0]
    static bool __cdecl LoadGeneralInfo(class S4::CMapFile & a1, class CGameChunkGeneral * a2);

    // address=[0x1483d50]
    static bool __cdecl LoadGeneralInfo(wchar_t const * String, class CGameChunkGeneral & a2);

    // address=[0x1483f20]
    static void __cdecl FillGameType(std::wstring & a1, class CGameType & a2, class CGameChunkGeneral & a3);

private:
    // address=[0x14845a0]
    static void __cdecl SetupPlayersAndAlliances(void);

    // address=[0x14847b0]
    static void __cdecl RemoveEmptyTeamSlot(int a1);

    // address=[0x1484820]
    static void __cdecl GetUsedTeam(int a1, int * a2);

    // address=[0x1484890]
    static bool __cdecl LoadGeneralEditorInfo(class S4::CMapFile & a1);

    // address=[0x14848f0]
    static bool __cdecl SaveGeneralInfo(class S4::CMapFile & a1);

    // address=[0x1484e90]
    static bool __cdecl RandomMap(void);

    // address=[0x1484f50]
    static bool __cdecl LoadEditorMap(std::wstring & a1, bool a2);

    // address=[0x1485180]
    static void __cdecl ActivateAIs(void);

    // address=[0x1485210]
    static bool __cdecl SaveCurrentData(class S4::CMapFile & a1);

    // address=[0x1485260]
    static void __cdecl SaveInfoAndUpdateGUI(class S4::CMapFile &,char const *,char const *);

    // address=[0x1485300]
    static void __cdecl SaveChunkObject(class S4::CMapFile & a1, unsigned short a2, unsigned short a3, class IS4ChunkObject & a4, char const * a5, char const * a6);

    // address=[0x3d89b28]
    static int m_iSaveTotal;

    // address=[0x3f450b8]
    static bool m_bInitialized;

    // address=[0x3f450bc]
    static int m_iSaveCounter;

};


#endif // CGAMERUN_H
