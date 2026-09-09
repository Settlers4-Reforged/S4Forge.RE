#include "MapAccess.h"
#include <comutil.h>

#include "LoadSave/Crc.h"
#include "LoadSave/Cryptor.h"
#include "LoadSave/SMapChunkHeader.h"
#include "Main/Players/CPlayerData.h"
#include "SEditorGlobalMapData.h"

struct EDITOR_INFO {
    _BYTE gap_0[2];
    unsigned __int16 m_iMapChecksum1;
    unsigned __int16 m_iMapChecksum2;
    _BYTE gap_6[14];
};

// address=[0x4727584]
bool g_bMapIsLoaded;
// address=[0x4727588]
short *g_pPreviewGfx;
// address=[0x472758c]
char *g_pTextDescription;
// address=[0x4727590]
char *g_pTextTandT;
// address=[0x4727594]
char *g_pTextEnglishDescription;
// address=[0x4727598]
char *g_pTextEnglishTandT;
// address=[0x472759c]
int g_bEditorMap;
// address=[0x47275a0]
int g_bAddOnMap;
// address=[0x47275a4]
int g_bCampaign;
// address=[0x47275a8]
int g_bSettlersAvailable;
// address=[0x47275ac]
int g_bBuildingsAvailable;
// address=[0x47275b0]
int g_bPilesAvailable;
// address=[0x47275b8]
CPlayerData g_cPlayerAndTeamData{};
// address=[0x472756c]
SEditorGlobalMapData g_sGeneralMapData{};
// address=[0x4727558]
EDITOR_INFO g_sEditorInfo;
// address=[0x3e3133c]
int g_iPreviewSize;

// address=[0x2fbbdb0]
// Decompiled from unsigned int __cdecl CalcChecksumOfFile(HANDLE hFile, _DWORD *a2)
unsigned long __cdecl CalcChecksumOfFile(void *hFile, int *a2) {

    DWORD NumberOfBytesRead; // [esp+0h] [ebp-18h] BYREF
                             // [esp+4h] [ebp-14h]
                             // [esp+8h] [ebp-10h]
                             // [esp+Ch] [ebp-Ch]
                             // [esp+10h] [ebp-8h]
                             // [esp+14h] [ebp-4h]

    *a2 = 0;
    SetFilePointer(hFile, 0, 0, 0);
    DWORD nNumberOfBytesToRead = GetFileSize(hFile, 0);
    void *v6 = operator new[](nNumberOfBytesToRead);
    LPVOID lpBuffer = v6;
    if(v6) {
        ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, &NumberOfBytesRead, 0);
        unsigned int v4 = Crc((unsigned __int8 *)lpBuffer + 8, nNumberOfBytesToRead - 8);
        void *C = lpBuffer;
        operator delete[](lpBuffer);
        return v4;
    } else {
        *a2 = 1;
        return 0;
    }
}

// address=[0x2fbbe50]
// Decompiled from int GetMapAccessInterfaceVersion()
int MA_API GetMapAccessInterfaceVersion(void) {

    return 105;
}

void MA_API MA_OpenMapFile(unsigned short *a, int *b, int *c, int d) {
    MA_OpenMapFile((wchar_t *)(a), b, c, d);
}

// address=[0x2fbbe60]
// Decompiled from void __cdecl MA_OpenMapFile(wchar_t *_swpName, int *_pFileBuffer, int *_iErrorCode, int _bReadToBuffer)
void MA_API MA_OpenMapFile(wchar_t *_swpName, int *_pFileBuffer, int *_iErrorCode, int _bReadToBuffer) {
    // eax
    unsigned int iCalculatedCRC;  // [esp+1CCh] [ebp-A0h]
    int iFileVersion;             // [esp+224h] [ebp-48h] MAPDST BYREF
    int iFileCRC;                 // [esp+22Ch] [ebp-40h] BYREF
    DWORD NumberOfBytesRead;      // [esp+230h] [ebp-3Ch] BYREF
    BOOL bHasData;                // [esp+234h] [ebp-38h]
    SMapChunkHeader sChunkHeader; // [esp+244h] [ebp-28h] BYREF

    ReleaseMemory();
    InitVariables();
    g_bBuildingsAvailable = 0;
    g_bPilesAvailable = 0;
    g_bSettlersAvailable = 0;
    if(g_bMapIsLoaded) {
        *_iErrorCode = 7;
        return;
    }
    g_bAddOnMap = 0;
    g_bEditorMap = 0;
    g_bCampaign = 0;
    *_pFileBuffer = 0;
    _bstr_t swName(_swpName);
    unsigned __int8 *lpBuffer = new unsigned __int8[0x40018u];
    if(!lpBuffer) {
        *_iErrorCode = 2;
        return;
    }

    g_pTextDescription = new char[0x2001u];
    if(!g_pTextDescription) {
        operator delete[](lpBuffer);
        lpBuffer = 0;
        *_iErrorCode = 2;
        return;
    }
    memset(g_pTextDescription, 0, 0x2001u);

    g_pTextEnglishDescription = new char[0x2001u];
    if(!g_pTextEnglishDescription) {
        operator delete[](lpBuffer);
        operator delete[](g_pTextDescription);
        lpBuffer = 0;
        g_pTextDescription = 0;
        *_iErrorCode = 2;
        return;
    }
    memset(g_pTextEnglishDescription, 0, 0x2001u);

    g_pTextTandT = new char[0x2001u];
    if(!g_pTextTandT) {
        operator delete[](lpBuffer);
        operator delete[](g_pTextDescription);
        operator delete[](g_pTextEnglishDescription);
        lpBuffer = 0;
        g_pTextDescription = 0;
        g_pTextEnglishDescription = 0;
        *_iErrorCode = 2;
        return;
    }
    memset(g_pTextTandT, 0, 0x2001u);

    g_pTextEnglishTandT = new char[0x2001u];
    if(!g_pTextEnglishTandT) {
        operator delete[](lpBuffer);
        operator delete[](g_pTextDescription);
        operator delete[](g_pTextEnglishDescription);
        operator delete[](g_pTextTandT);
        lpBuffer = 0;
        g_pTextDescription = 0;
        g_pTextEnglishDescription = 0;
        g_pTextTandT = 0;
        *_iErrorCode = 2;
        return;
    }
    memset(g_pTextEnglishTandT, 0, 0x2001u);
    HANDLE hFile = CreateFileA(swName, 0x80000000, 1u, 0, 3u, 0x80u, 0);
    if(hFile == (HANDLE)-1) {
        operator delete[](lpBuffer);
        operator delete[](g_pTextDescription);
        operator delete[](g_pTextEnglishDescription);
        operator delete[](g_pTextTandT);
        operator delete[](g_pTextEnglishTandT);
        lpBuffer = 0;
        g_pTextDescription = 0;
        g_pTextEnglishDescription = 0;
        g_pTextTandT = 0;
        g_pTextEnglishTandT = 0;
        *_iErrorCode = 5;
        return;
    }

    ReadFile(hFile, &iFileCRC, 4u, &NumberOfBytesRead, 0);
    *_pFileBuffer = iFileCRC;
    if(!_bReadToBuffer) {
        goto LABEL_19;
    }

    int iChecksumFailed; // [esp+1E4h] [ebp-88h] BYREF
    iCalculatedCRC = CalcChecksumOfFile(hFile, &iChecksumFailed);
    if(iChecksumFailed) {
    LABEL_16:
        CloseHandle(hFile);
        operator delete[](lpBuffer);
        operator delete[](g_pTextDescription);
        operator delete[](g_pTextEnglishDescription);
        operator delete[](g_pTextTandT);
        operator delete[](g_pTextEnglishTandT);
        lpBuffer = 0;
        g_pTextDescription = 0;
        g_pTextEnglishDescription = 0;
        g_pTextTandT = 0;
        g_pTextEnglishTandT = 0;
        *_iErrorCode = 2;
        return;
    }
    if(iCalculatedCRC == iFileCRC) {
    LABEL_19:
        SetFilePointer(hFile, 4, 0, FILE_BEGIN);
        ReadFile(hFile, &iFileVersion, 4u, &NumberOfBytesRead, 0);
        g_cPlayerAndTeamData.Init();
        if(iFileVersion != 31 && iFileVersion != 40) {
        LABEL_59:
            CloseHandle(hFile);
            operator delete[](lpBuffer);
            operator delete[](g_pTextDescription);
            operator delete[](g_pTextEnglishDescription);
            operator delete[](g_pTextTandT);
            operator delete[](g_pTextEnglishTandT);
            lpBuffer = 0;
            g_pTextDescription = 0;
            g_pTextEnglishDescription = 0;
            g_pTextTandT = 0;
            g_pTextEnglishTandT = 0;
            *_iErrorCode = 4;
            return;
        }

        if(iFileVersion == 40) {
            g_bAddOnMap = 1;
        }
        while(2) {
            bHasData = ReadFile(hFile, &sChunkHeader, sizeof(SMapChunkHeader), &NumberOfBytesRead, 0);
            Cryption(reinterpret_cast<unsigned __int8 *>(&sChunkHeader), sizeof(SMapChunkHeader));
            if(bHasData) {
                switch(sChunkHeader.m_iChunkId) {
                case MAP_CHUNK_DUMMY:
                    goto LABEL_72;
                case MAP_CHUNK_GENERAL:
                    bHasData = ReadFile(hFile, lpBuffer, sChunkHeader.m_iSize, &NumberOfBytesRead, 0);
                    ReadChunk((char *)lpBuffer, sChunkHeader.m_iSize, sChunkHeader.m_iDecompressedSize);
                    memcpy(&g_sGeneralMapData, lpBuffer, sizeof(g_sGeneralMapData));
                    if(!bHasData) {
                        goto LABEL_46;
                    }
                    goto LABEL_72;
                case MAP_CHUNK_PLAYER:
                    bHasData = g_cPlayerAndTeamData.Load(lpBuffer, hFile, sChunkHeader);
                    g_sGeneralMapData.m_uNumberOfPlayers = g_cPlayerAndTeamData.GetNumberOfPlayers();
                    if(!bHasData) {
                        goto LABEL_46;
                    }
                    goto LABEL_72;
                case MAP_CHUNK_TEAM:
                    bHasData = g_cPlayerAndTeamData.LoadTeamData(lpBuffer, hFile, sChunkHeader);
                    if(!bHasData) {
                        goto LABEL_46;
                    }
                    goto LABEL_72;
                case MAP_CHUNK_PREVIEW:
                    if(_bReadToBuffer) {
                        g_iPreviewSize = sChunkHeader.m_iNumberOfPlayers;
                        if(sChunkHeader.m_iNumberOfPlayers < 128 || g_iPreviewSize > 1024) {
                            goto LABEL_46;
                        }
                        if(g_pPreviewGfx) {
                            operator delete[](g_pPreviewGfx);
                        }
                        g_pPreviewGfx = new short[g_iPreviewSize * g_iPreviewSize];
                        if(!g_pPreviewGfx) {
                            goto LABEL_16;
                        }
                        bHasData = ReadFile(hFile, g_pPreviewGfx, sChunkHeader.m_iSize, &NumberOfBytesRead, 0);
                        ReadChunk(g_pPreviewGfx, sChunkHeader.m_iSize, sChunkHeader.m_iDecompressedSize);
                        if(!bHasData) {
                            goto LABEL_46;
                        }
                    } else if(SetFilePointer(hFile, sChunkHeader.m_iSize, 0, FILE_CURRENT) == -1) {
                        goto LABEL_59;
                    }
                LABEL_72:
                    if(sChunkHeader.m_iChunkId) {
                        continue;
                    }
                LABEL_75:
                    CloseHandle(hFile);
                    operator delete[](lpBuffer);
                    g_bMapIsLoaded = 1;
                    *_iErrorCode = 0;
                    break;
                case MAP_CHUNK_DUMMY_2:
                    goto LABEL_75;
                case MAP_CHUNK_SETTLERS:
                    g_bSettlersAvailable = 1;
                    if(SetFilePointer(hFile, sChunkHeader.m_iSize, 0, FILE_CURRENT) == -1) {
                        goto LABEL_59;
                    }
                    goto LABEL_72;
                case MAP_CHUNK_BUILDINGS:
                    g_bBuildingsAvailable = 1;
                    if(SetFilePointer(hFile, sChunkHeader.m_iSize, 0, FILE_CURRENT) == -1) {
                        goto LABEL_59;
                    }
                    goto LABEL_72;
                case MAP_CHUNK_PILES:
                    g_bPilesAvailable = 1;
                    if(SetFilePointer(hFile, sChunkHeader.m_iSize, 0, FILE_CURRENT) == -1) {
                        goto LABEL_59;
                    }
                    goto LABEL_72;
                case MAP_CHUNK_DESCRIPTION:
                    bHasData = ReadFile(hFile, lpBuffer, sChunkHeader.m_iSize, &NumberOfBytesRead, 0);
                    ReadChunk((char *)lpBuffer, sChunkHeader.m_iSize, sChunkHeader.m_iDecompressedSize);
                    if(!bHasData) {
                        goto LABEL_59;
                    }
                    memcpy(g_pTextDescription, lpBuffer, sChunkHeader.m_iDecompressedSize);
                    goto LABEL_72;
                case MAP_CHUNK_TIPS:
                    bHasData = ReadFile(hFile, lpBuffer, sChunkHeader.m_iSize, &NumberOfBytesRead, 0);
                    ReadChunk((char *)lpBuffer, sChunkHeader.m_iSize, sChunkHeader.m_iDecompressedSize);
                    if(!bHasData) {
                        goto LABEL_59;
                    }
                    memcpy(g_pTextTandT, lpBuffer, sChunkHeader.m_iDecompressedSize);
                    goto LABEL_72;
                case MAP_CHUNK_ENGLISH_DESCRIPTION:
                    bHasData = ReadFile(hFile, lpBuffer, sChunkHeader.m_iSize, &NumberOfBytesRead, 0);
                    ReadChunk((char *)lpBuffer, sChunkHeader.m_iSize, sChunkHeader.m_iDecompressedSize);
                    if(!bHasData) {
                        goto LABEL_59;
                    }
                    memcpy(g_pTextEnglishDescription, lpBuffer, sChunkHeader.m_iDecompressedSize);
                    goto LABEL_72;
                case MAP_CHUNK_ENGLISH_TIPS:
                    bHasData = ReadFile(hFile, lpBuffer, sChunkHeader.m_iSize, &NumberOfBytesRead, 0);
                    ReadChunk((char *)lpBuffer, sChunkHeader.m_iSize, sChunkHeader.m_iDecompressedSize);
                    if(!bHasData) {
                        goto LABEL_59;
                    }
                    memcpy(g_pTextEnglishTandT, lpBuffer, sChunkHeader.m_iDecompressedSize);
                    goto LABEL_72;
                case MAP_CHUNK_IS_EDITOR:
                    g_bEditorMap = 1;
                    if(SetFilePointer(hFile, sChunkHeader.m_iSize, 0, FILE_CURRENT) == -1) {
                        goto LABEL_59;
                    }
                    goto LABEL_72;
                case MAP_CHUNK_IS_CAMPAIGN:
                    g_bCampaign = 1;
                    if(SetFilePointer(hFile, sChunkHeader.m_iSize, 0, FILE_CURRENT) == -1) {
                        goto LABEL_59;
                    }
                    goto LABEL_72;
                case MAP_CHUNK_EDITOR_DATA:
                    bHasData = ReadFile(hFile, lpBuffer, sChunkHeader.m_iSize, &NumberOfBytesRead, 0);
                    ReadChunk((char *)lpBuffer, sChunkHeader.m_iSize, sChunkHeader.m_iDecompressedSize);
                    memcpy(&g_sEditorInfo, lpBuffer, 0x14u);
                    if(!bHasData) {
                        goto LABEL_46;
                    }
                    goto LABEL_72;
                default:
                    if(SetFilePointer(hFile, sChunkHeader.m_iSize, 0, FILE_CURRENT) == -1) {
                        goto LABEL_59;
                    }
                    goto LABEL_72;
                }
            } else {
            LABEL_46:
                CloseHandle(hFile);
                operator delete[](lpBuffer);
                operator delete[](g_pTextDescription);
                operator delete[](g_pTextEnglishDescription);
                operator delete[](g_pTextTandT);
                operator delete[](g_pTextEnglishTandT);
                lpBuffer = 0;
                g_pTextDescription = 0;
                g_pTextEnglishDescription = 0;
                g_pTextTandT = 0;
                g_pTextEnglishTandT = 0;
                *_iErrorCode = 3;
            }
            break;
        }
    } else {
        CloseHandle(hFile);
        operator delete[](lpBuffer);
        operator delete[](g_pTextDescription);
        operator delete[](g_pTextEnglishDescription);
        operator delete[](g_pTextTandT);
        operator delete[](g_pTextEnglishTandT);
        lpBuffer = 0;
        g_pTextDescription = 0;
        g_pTextEnglishDescription = 0;
        g_pTextTandT = 0;
        g_pTextEnglishTandT = 0;
        *_iErrorCode = 1;
    }
}

// address=[0x2fbdbf0]
// Decompiled from void MA_CloseMapFile()
void MA_API MA_CloseMapFile(void) {

    ReleaseMemory();
    InitVariables();
}

// address=[0x2fbdc00]
// Decompiled from int *__cdecl MA_IsCampaignMap(int *a1)
void MA_API MA_IsCampaignMap(int *a1) {
    *a1 = g_bCampaign;
}

// address=[0x2fbdc10]
// Decompiled from int *__cdecl MA_IsEditorMap(int *a1)
void MA_API MA_IsEditorMap(int *a1) {
    *a1 = g_bEditorMap;
}

// address=[0x2fbdc20]
// Decompiled from void __cdecl MA_GetNumberOfPlayers(int *a1)
void MA_API MA_GetNumberOfPlayers(int *a1) {
    if(g_bMapIsLoaded) {
        *a1 = g_sGeneralMapData.m_uNumberOfPlayers;
    } else {
        *a1 = 0;
    }
}

// address=[0x2fbdc50]
// Decompiled from int __cdecl MA_GetNumberOfSetups(int *a1)
void MA_API MA_GetNumberOfSetups(int *a1) {
    if(g_bMapIsLoaded) {
        *a1 = g_cPlayerAndTeamData.GetNumberOfSetups();
    } else {
        *a1 = 0;
    }
}

// address=[0x2fbdc80]
// Decompiled from void __cdecl MA_GetMapData(int *_pWidthHeight, int *_pGameType, int *_pMapFlags, int *_pStartResources, int *_pIsEmptyMap)
void MA_API MA_GetMapData(int *_pWidthHeight, int *_pGameType, int *_pMapFlags, int *_pStartResources, int *_pIsEmptyMap) {
    if(g_bMapIsLoaded) {
        *_pWidthHeight = g_sGeneralMapData.m_iWidthHeight;
        *_pGameType = g_sGeneralMapData.m_iGameType;
        *_pMapFlags = g_sGeneralMapData.m_iFlags;
        *_pStartResources = g_sGeneralMapData.m_iStartResources;
        *_pIsEmptyMap = !g_bSettlersAvailable && !g_bBuildingsAvailable;
    } else {
        *_pStartResources = 0;
        *_pMapFlags = 0;
        *_pGameType = 0;
        *_pWidthHeight = 0;
        *_pIsEmptyMap = 0;
    }
}

void MA_API MA_GetPlayerData(int a, int b, int *c, int *d, int *e, unsigned short **f, unsigned short **g, int *h, int *i, int *j) {
    MA_GetPlayerData(a, b, c, d, e, (wchar_t **)(f), (wchar_t **)(g), h, i, j);
}

// address=[0x2fbdd10]
// Decompiled from wchar_t *__cdecl MA_GetPlayerData(int _iPlayerIndex, int _iSetupIndex, int *_iPlayerRace, int *_iPlayerX, int *_iPlayerY, wchar_t **_swpPlayerName, wchar_t **_swpSetupName, int *_iPlayerControl, int *_iHasTeam, int *_iPlayerTeam)
void MA_API MA_GetPlayerData(int _iPlayerIndex, int _iSetupIndex, int *_iPlayerRace, int *_iPlayerX, int *_iPlayerY, wchar_t **_swpPlayerName, wchar_t **_swpSetupName, int *_iPlayerControl, int *_iHasTeam, int *_iPlayerTeam) {

    // eax
    // eax
    wchar_t *result;        // eax
    WCHAR psz[160];         // [esp+4h] [ebp-284h] BYREF
    WCHAR WideCharStr[160]; // [esp+144h] [ebp-144h] BYREF

    if(g_bMapIsLoaded && _iPlayerIndex > 0 && _iPlayerIndex <= g_cPlayerAndTeamData.GetNumberOfPlayers() && _iSetupIndex >= 0 && _iSetupIndex < g_cPlayerAndTeamData.GetNumberOfSetups()) {
        *_iPlayerRace = g_cPlayerAndTeamData.GetRaceOfPlayer(_iPlayerIndex);
        *_iPlayerX = g_cPlayerAndTeamData.GetXOfPlayer(_iPlayerIndex);
        *_iPlayerY = g_cPlayerAndTeamData.GetYOfPlayer(_iPlayerIndex);
        *_iPlayerControl = g_cPlayerAndTeamData.GetControlOfPlayer(_iPlayerIndex, _iSetupIndex);
        *_iHasTeam = g_cPlayerAndTeamData.GetTeamOfPlayer(_iPlayerIndex, _iSetupIndex) == 255;
        *_iPlayerTeam = g_cPlayerAndTeamData.GetTeamOfPlayer(_iPlayerIndex, _iSetupIndex);
        char *NameOfPlayer = g_cPlayerAndTeamData.GetNameOfPlayer(_iPlayerIndex);
        MultiByteToWideChar(0, 1u, NameOfPlayer, -1, WideCharStr, 80);
        char *SetupName = g_cPlayerAndTeamData.GetSetupName(_iSetupIndex);
        MultiByteToWideChar(0, 1u, SetupName, -1, psz, 80);
        *_swpPlayerName = SysAllocString(WideCharStr);
        *_swpSetupName = SysAllocString(psz);
    } else {
        *_iHasTeam = *_iPlayerTeam;
        *_iPlayerControl = *_iHasTeam;
        *_iPlayerY = *_iPlayerControl;
        *_iPlayerX = *_iPlayerY;
        *_iPlayerRace = *_iPlayerX;
        MultiByteToWideChar(0, 1u, "", -1, WideCharStr, 80);
        MultiByteToWideChar(0, 1u, "", -1, psz, 80);
        *_swpPlayerName = SysAllocString(WideCharStr);
        *_swpSetupName = SysAllocString(psz);
    }
}

// address=[0x2fbdf20]
// Decompiled from void __cdecl MA_GetDataChecksums(int *a1, int *a2)
void MA_API MA_GetDataChecksums(int *a1, int *a2) {
    if(g_bMapIsLoaded) {
        *a1 = g_sEditorInfo.m_iMapChecksum1;
        *a2 = g_sEditorInfo.m_iMapChecksum2;
    } else {
        *a2 = 0;
        *a1 = 0;
    }
}

void MA_API MA_GetDescriptionText(int a, unsigned short **b) {
    MA_GetDescriptionText(a, (wchar_t **)(b));
}

// address=[0x2fbdf60]
// Decompiled from void __cdecl MA_GetDescriptionText(int a1, wchar_t **a2)
void MA_API MA_GetDescriptionText(int a1, wchar_t **a2) {

    // eax
    // [esp+4h] [ebp-800Ch]
    WCHAR WideCharStr[16386]; // [esp+8h] [ebp-8008h] BYREF

    const CHAR *lpMultiByteStr = 0;
    if(g_bMapIsLoaded && (unsigned int)a1 < 4) {
        switch(a1) {
        case 0:
            lpMultiByteStr = (const CHAR *)g_pTextDescription;
            break;
        case 1:
            lpMultiByteStr = (const CHAR *)g_pTextTandT;
            break;
        case 2:
            lpMultiByteStr = (const CHAR *)g_pTextEnglishDescription;
            break;
        case 3:
            lpMultiByteStr = (const CHAR *)g_pTextEnglishTandT;
            break;
        default:
            break;
        }
    }
    if(lpMultiByteStr) {
        MultiByteToWideChar(0, 1u, "", -1, WideCharStr, 0x4000);
    } else {
        MultiByteToWideChar(0, 1u, "", -1, WideCharStr, 80);
    }
    *a2 = SysAllocString(WideCharStr);
}

// address=[0x2fbe080]
// Decompiled from void __cdecl MA_GetPreviewMapRawData(int *_iWidth, int *_iHeight, struct tagVARIANT *a3)
void MA_API MA_GetPreviewMapRawData(int *_iWidth, int *_iHeight, struct tagVARIANT *a3) {

    if(g_pPreviewGfx && g_iPreviewSize) {
        *_iHeight = g_iPreviewSize;
        *_iWidth = g_iPreviewSize;
        a3->lVal = (LONG)g_pPreviewGfx;
        a3->vt = 16402;
    } else {
        a3->lVal = 0;
        a3->vt = 0;
        *_iHeight = 0;
        *_iWidth = 0;
    }
}

// address=[0x2fbe0f0]
// Decompiled from void __cdecl MA_GetMapProperty(int a1, int *a2)
void MA_API MA_GetMapProperty(int a1, int *a2) {

    // [esp+0h] [ebp-Ch]
    // [esp+4h] [ebp-8h]

    if(a1 == 1) {
        BOOL v3 = g_bAddOnMap && g_bMapIsLoaded;
        *a2 = v3;
    } else if(a1 == 2) {
        BOOL v2 = (g_sGeneralMapData.m_iFlags & 0x40) != 0 && g_bMapIsLoaded;
        *a2 = v2;
    } else {
        *a2 = -1;
    }
    *a2 = g_bAddOnMap;
}

// address=[0x2fbe180]
// Decompiled from void *sub_33BE180()
void __cdecl InitVariables(void) {
    g_bMapIsLoaded = 0;
    g_pPreviewGfx = 0;
    g_pTextDescription = 0;
    g_pTextTandT = 0;
    g_pTextEnglishDescription = 0;
    g_pTextEnglishTandT = 0;
    g_iPreviewSize = 256;
    g_bEditorMap = 0;
    g_bAddOnMap = 0;
    g_bCampaign = 0;
    g_bPilesAvailable = 0;
    g_bBuildingsAvailable = 0;
    g_bSettlersAvailable = 0;
    memset(&g_sEditorInfo, 0, 0x14u);
    static_assert(sizeof(g_sEditorInfo) == 0x14u, "g_sEditorInfo size mismatch");
}

// address=[0x2fbe220]
// Decompiled from int sub_33BE220()
void __cdecl ReleaseMemory(void) {
    // TODO: remove ifs, as delete is safe on nullptr
    g_bEditorMap = 0;
    g_bCampaign = 0;
    g_bMapIsLoaded = 0;
    if(g_pPreviewGfx) {
        operator delete[](g_pPreviewGfx);
        g_pPreviewGfx = 0;
    }
    if(g_pTextDescription) {
        operator delete[](g_pTextDescription);
        g_pTextDescription = 0;
    }
    if(g_pTextTandT) {
        operator delete[](g_pTextTandT);
        g_pTextTandT = 0;
    }
    if(g_pTextEnglishDescription) {
        operator delete[](g_pTextEnglishDescription);
        g_pTextEnglishDescription = 0;
    }
    if(g_pTextEnglishTandT) {
        operator delete[](g_pTextEnglishTandT);
        g_pTextEnglishTandT = 0;
    }
}

// address=[0x2fbfeb0]
// Decompiled from unsigned int __cdecl Crc(unsigned __int8 *a1, unsigned int a2)
unsigned int __cdecl Crc(unsigned char *a1, unsigned long a2) {
    cdm_crc::CRCGenerator<16, 32773, 0, 0, 1, 1> cGenerator{};
    cGenerator.Process(a1, a2);
    unsigned int NormalCRC = cGenerator.GetNormalCRC();
    return NormalCRC >> (32 - cGenerator.GetWidth());
}

// address=[0x2fbff00]
// Decompiled from void __cdecl Cryption(unsigned __int8 *a1, unsigned int a2)
void __cdecl Cryption(unsigned char *a1, unsigned long a2) {
    Cryptor cCryptor{};
    cCryptor.Set_Key("01234567890123456789");
    for(unsigned int i = 0;
        i < a2;
        ++i) {
        cCryptor.Transform_Char(a1[i]);
    }
}
