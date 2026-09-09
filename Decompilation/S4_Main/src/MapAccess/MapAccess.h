#ifndef MAPACCESS_H
#define MAPACCESS_H

#include "defines.h"

#include <functional>

// address=[0x4727584]
extern bool g_bMapIsLoaded;

// address=[0x4727588]
extern short *g_pPreviewGfx;

// address=[0x472758c]
extern char *g_pTextDescription;

// address=[0x4727590]
extern char *g_pTextTandT;

// address=[0x4727594]
extern char *g_pTextEnglishDescription;

// address=[0x4727598]
extern char *g_pTextEnglishTandT;

// address=[0x472759c]
extern int g_bEditorMap;

// address=[0x47275a0]
extern int g_bAddOnMap;

// address=[0x47275a4]
extern int g_bCampaign;

// address=[0x47275a8]
extern int g_bSettlersAvailable;

// address=[0x47275ac]
extern int g_bBuildingsAvailable;

// address=[0x47275b0]
extern int g_bPilesAvailable;

// address=[0x47275b8]
extern class CPlayerData g_cPlayerAndTeamData;

// address=[0x3e3133c]
extern int g_iPreviewSize;

// address=[0x472756c]
extern struct SEditorGlobalMapData g_sGeneralMapData;

// address=[0x4727558]
extern struct EDITOR_INFO g_sEditorInfo;

#ifdef EXPORT_MA
#define MA_API __declspec(dllexport) __stdcall
#elif defined(IMPORT_MA)
#define MA_API __declspec(dllimport) __stdcall
#else
#define MA_API __cdecl
#endif

// address=[0x2fbbdb0]
unsigned long __cdecl CalcChecksumOfFile(void *, int *);

// address=[0x2fbbe50]
int MA_API GetMapAccessInterfaceVersion(void);

// address=[0x2fbbe60]
void MA_API MA_OpenMapFile(wchar_t *, int *, int *, int);
void MA_API MA_OpenMapFile(unsigned short *a, int *b, int *c, int d);

// address=[0x2fbdbf0]
void MA_API MA_CloseMapFile(void);

// address=[0x2fbdc00]
void MA_API MA_IsCampaignMap(int *);

// address=[0x2fbdc10]
void MA_API MA_IsEditorMap(int *);

// address=[0x2fbdc20]
void MA_API MA_GetNumberOfPlayers(int *);

// address=[0x2fbdc50]
void MA_API MA_GetNumberOfSetups(int *);

// address=[0x2fbdc80]
void MA_API MA_GetMapData(int *, int *, int *, int *, int *);

// address=[0x2fbdd10]
void MA_API MA_GetPlayerData(int, int, int *, int *, int *, wchar_t **, wchar_t **, int *, int *, int *);
void MA_API MA_GetPlayerData(int, int, int *, int *, int *, unsigned short **, unsigned short **, int *, int *, int *);

// address=[0x2fbdf20]
void MA_API MA_GetDataChecksums(int *, int *);

// address=[0x2fbdf60]
void MA_API MA_GetDescriptionText(int, wchar_t **);
void MA_API MA_GetDescriptionText(int, unsigned short **);

// address=[0x2fbe080]
void MA_API MA_GetPreviewMapRawData(int *, int *, struct tagVARIANT *);

// address=[0x2fbe0f0]
void MA_API MA_GetMapProperty(int, int *);

// address=[0x2fbe180]
void __cdecl InitVariables(void);

// address=[0x2fbe220]
void __cdecl ReleaseMemory(void);

// address=[0x2fbfeb0]
unsigned int __cdecl Crc(unsigned char *, unsigned long);

// address=[0x2fbff00]
void __cdecl Cryption(unsigned char *, unsigned long);

#endif // MAPACCESS_H
