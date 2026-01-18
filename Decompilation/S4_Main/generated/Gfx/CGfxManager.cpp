#include "CGfxManager.h"

// Definitions for class CGfxManager

// address=[0x1361470]
// Decompiled from CGfxManager *__thiscall CGfxManager::CGfxManager(CGfxManager *this, bool a2, bool a3, bool a4)
 CGfxManager::CGfxManager(bool a2, bool a3, bool a4) {
  
  int v5; // [esp+4h] [ebp-34h]
  _BYTE v7[28]; // [esp+Ch] [ebp-2Ch] BYREF
  int v8; // [esp+34h] [ebp-4h]

  *(_DWORD *)this = &CGfxManager::_vftable_;
  _vec_ctor_no((char *)this + 4, 0x10u, 0x2Au, (void *(__thiscall *)(void *))CGfxManager::SGFXINFO::SGFXINFO);
  _vec_ctor_no((char *)this + 2188, 0x10u, 0x2Au, (void *(__thiscall *)(void *))CGfxManager::SGFXINFO::SGFXINFO);
  std::wstring::wstring((char *)this + 3196);
  v8 = 1;
  String::String((CGfxManager *)((char *)this + 3232));
  *((_BYTE *)this + 3224) = a2;
  memset((char *)this + 2188, 0, 0x2A0u);
  memset((char *)this + 4, 0, 0x2A0u);
  memset((char *)this + 676, 0, 0xA8u);
  memset((char *)this + 844, 0, 0x150u);
  memset((char *)this + 1180, 0, 0x150u);
  memset((char *)this + 1516, 0, 0x150u);
  memset((char *)this + 1852, 0, 0x150u);
  memset((char *)this + 2860, 0, 0xA8u);
  v5 = std::wstring::wstring(v7, (wchar_t *)L"Gfx");
  std::wstring::operator=(v5);
  std::wstring::~wstring(v7);
  *((_DWORD *)this + 807) = -1;
  memset(byte_3ECDBF4, 0, 0x2Au);
  *((_BYTE *)this + 3260) = a3;
  *((_BYTE *)this + 3261) = a4;
  *((_BYTE *)this + 3262) = 0;
  return this;
}


// address=[0x1361660]
// Decompiled from void __thiscall CGfxManager::~CGfxManager(CGfxManager *this)
 CGfxManager::~CGfxManager(void) {
  
  *(_DWORD *)this = &CGfxManager::_vftable_;
  CGfxManager::RemoveAllGFX(this, -1);
  String::~String((CGfxManager *)((char *)this + 3232));
  std::wstring::~wstring((char *)this + 3196);
}


// address=[0x13616d0]
// Decompiled from char __thiscall CGfxManager::OpenGFXFiles(CGfxManager *this)
bool  CGfxManager::OpenGFXFiles(void) {
  
  CGfxManager::EnableGfxFile(this, 0x14u, 0, 1, 0x3Au);
  CGfxManager::EnableGfxFile(this, 0x16u, 0, 1, 0x3Au);
  CGfxManager::EnableGfxFile(this, 0x15u, 0, 1, 0x3Au);
  CGfxManager::EnableGfxFile(this, 0x17u, 0, 1, 0x3Au);
  CGfxManager::EnableGfxFile(this, 0x18u, 0, 1, 0x3Au);
  if ( g_bGfxHJBLoadSpecialGfx )
    CGfxManager::EnableGfxFile(this, 0x19u, 0, 1, 0x3Au);
  CGfxManager::EnableGfxFile(this, 0xAu, 1, 1, 0x3Fu);
  CGfxManager::EnableGfxFile(this, 0xCu, 1, 1, 0x3Fu);
  CGfxManager::EnableGfxFile(this, 0xBu, 1, 1, 0x3Fu);
  CGfxManager::EnableGfxFile(this, 0xDu, 1, 1, 0x3Fu);
  CGfxManager::EnableGfxFile(this, 0xEu, 1, 1, 0x3Fu);
  CGfxManager::EnableGfxFile(this, 3u, 2, 1, 0xAu);
  CGfxManager::EnableGfxFile(this, 5u, 3, 1, 0x55u);
  CGfxManager::EnableGfxFile(this, 7u, 6, 1, 0x1Au);
  CGfxManager::EnableGfxFile(this, 8u, 5, 1, 0xDu);
  if ( IGfxEngine::Use4444Palettes((IGfxEngine *)g_pGfxEngine) )
  {
    CGfxManager::EnableGfxFile(this, 4u, 7, 1, 0x21u);
    if ( *((_BYTE *)this + 3260) || *((_BYTE *)this + 3261) )
      CGfxManager::EnableGfxFile(this, 0x24u, 7, 1, 0xCu);
  }
  else
  {
    CGfxManager::EnableGfxFile(this, 6u, 7, 1, 0x21u);
    if ( *((_BYTE *)this + 3260) || *((_BYTE *)this + 3261) )
      CGfxManager::EnableGfxFile(this, 0x25u, 7, 1, 0xCu);
  }
  CGfxManager::EnableGfxFile(this, 0x1Eu, 4, 1, 9u);
  CGfxManager::EnableGfxFile(this, 0x20u, 4, 1, 9u);
  CGfxManager::EnableGfxFile(this, 0x1Fu, 4, 1, 9u);
  CGfxManager::EnableGfxFile(this, 0x22u, 4, 1, 9u);
  CGfxManager::Reload(1, 1, *((_BYTE *)this + 3224) == 0);
  return 1;
}


// address=[0x13618d0]
// Decompiled from void __thiscall CGfxManager::GetGuiGfxInfo(CGfxManager *this, struct SGfxObjectInfo *a2, unsigned int a3)
void  CGfxManager::GetGuiGfxInfo(struct SGfxObjectInfo & a2, unsigned int a3) {
  
  unsigned int v3; // [esp+0h] [ebp-8h]

  v3 = *((_DWORD *)this + 807);
  if ( !*((_DWORD *)this + 2 * v3 + 211)
    && BBSupportDbgReport(2, "GfxManager.cpp", 913, "m_pFileGfxFrames[ iGfxFile ].pItem") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + v3 + 169) && BBSupportDbgReport(2, "GfxManager.cpp", 914, "m_pFilePalIndex[ iGfxFile ]") == 1 )
    __debugbreak();
  if ( a3 <= *((_DWORD *)this + 2 * v3 + 212) )
  {
    *(_DWORD *)a2 = *(_DWORD *)(*((_DWORD *)this + 2 * v3 + 211) + 4 * a3 + 20);
    *((_DWORD *)a2 + 1) = *(_DWORD *)(*((_DWORD *)this + v3 + 169) + 4 * a3 + 20);
    j__sprintf(byte_3ECDC20, "Gui Element: %u", a3);
    CGfxManager::Debug_Check_LayerBlock(this, v3, a2);
  }
  else
  {
    memset(a2, 0, 0x2D0u);
  }
}


// address=[0x13619d0]
// Decompiled from void __thiscall CGfxManager::GetUserLogoGfxInfo(  CGfxManager *this,  struct SGfxObjectInfo *userLogoGfxInfo,  unsigned int logoNr,  unsigned int direction)
void  CGfxManager::GetUserLogoGfxInfo(struct SGfxObjectInfo & userLogoGfxInfo, unsigned int logoNr, unsigned int direction) {
  
  int logoIndex; // [esp+18h] [ebp+Ch]

  if ( direction >= 2 && BBSupportDbgReport(2, "GfxManager.cpp", 938, "_iDir < MAX_LOGO_DIRECTIONS") == 1 )
    __debugbreak();
  if ( !*((_DWORD *)this + 0xD5)
    && BBSupportDbgReport(2, "GfxManager.cpp", 941, "m_pFileGfxFrames[ iGfxFile ].pItem") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 0xAA) && BBSupportDbgReport(2, "GfxManager.cpp", 942, "m_pFilePalIndex[ iGfxFile ]") == 1 )
    __debugbreak();
  logoIndex = logoNr - 1;
  *(_DWORD *)userLogoGfxInfo = *(_DWORD *)(*((_DWORD *)this + 0xD5) + 8 * logoIndex + 20);
  *((_DWORD *)userLogoGfxInfo + 1) = *(_DWORD *)(*((_DWORD *)this + 0xAA) + 8 * logoIndex + 20);
  j__sprintf(byte_3ECDC20, "Logo Player Nr: %u, Direction: %u", logoIndex, 0);
  CGfxManager::Debug_Check_LayerBlock(this, 1u, userLogoGfxInfo);
}


// address=[0x1361af0]
// Decompiled from void __thiscall CGfxManager::GetBuildingGfxInfo(  CGfxManager *this,  struct SGfxObjectInfo *a2,  unsigned int a3,  unsigned int a4,  int a5,  int a6)
void  CGfxManager::GetBuildingGfxInfo(struct SGfxObjectInfo & a2, unsigned int a3, unsigned int a4, unsigned int a5, struct SBuildingFX * a6) {
  
  unsigned int v7; // [esp+20h] [ebp-8h]
  unsigned int i; // [esp+24h] [ebp-4h]
  unsigned int v9; // [esp+38h] [ebp+10h]

  v7 = a3 + 10;
  if ( !*((_DWORD *)this + 2 * a3 + 399)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 1330, "m_pFileGfxJobs[ %u ].pItem", v7) == 1 )
  {
    __debugbreak();
  }
  if ( a4 >= *((_DWORD *)this + 2 * v7 + 380)
    && BBSupportDbgReport(2, "GfxManager.cpp", 1331, "_iBuilding < m_pFileGfxJobs[ iGfxFile ].iCount") == 1 )
  {
    __debugbreak();
  }
  v9 = a4 >= *((_DWORD *)this + 2 * v7 + 380) ? 0 : a4;
  dword_3ECDD6C = *(_DWORD *)(*((_DWORD *)this + 2 * v7 + 379) + 4 * v9 + 20);
  if ( (a5 & 1) != 0 && (a5 & 2) != 0 )
  {
    dword_3ECDD74 = *(_DWORD *)(dword_3ECDD6C + 4);
    dword_3ECDD70 = *(_DWORD *)dword_3ECDD74;
    *(_DWORD *)a2 = dword_3ECDD70;
    dword_3ECDD74 = *(_DWORD *)dword_3ECDD6C;
    dword_3ECDD70 = *(_DWORD *)dword_3ECDD74;
    *((_DWORD *)a2 + 22) = dword_3ECDD70;
  }
  else
  {
    if ( (a5 & 1) != 0 )
    {
      dword_3ECDD74 = *(_DWORD *)(dword_3ECDD6C + 4);
      dword_3ECDD70 = *(_DWORD *)dword_3ECDD74;
      *(_DWORD *)a2 = dword_3ECDD70;
    }
    if ( (a5 & 2) != 0 )
    {
      dword_3ECDD74 = *(_DWORD *)dword_3ECDD6C;
      dword_3ECDD70 = *(_DWORD *)dword_3ECDD74;
      *(_DWORD *)a2 = dword_3ECDD70;
    }
  }
  if ( a6 )
  {
    for ( i = 0; i < 0xA; ++i )
    {
      if ( *(_DWORD *)(a6 + 8 * i) )
      {
        if ( *(_DWORD *)(a6 + 8 * i) >= *((_DWORD *)this + 2 * v7 + 296)
          && BBSupportDbgReport(
               2,
               "GfxManager.cpp",
               1379,
               "_argBuildingFX[ i ].iBuildingDefine < m_pFileGfxDirections[ iGfxFile ].iCount") == 1 )
        {
          __debugbreak();
        }
        *(_DWORD *)(a6 + 8 * i) &= (*(_DWORD *)(a6 + 8 * i) >= *((_DWORD *)this + 2 * v7 + 296)) - 1;
        if ( *(_DWORD *)(a6 + 8 * i + 4) >= CGfxManager::GetBuildingJobFrameCount(this, a3, *(_DWORD *)(a6 + 8 * i))
          && BBSupportDbgReport(
               2,
               "GfxManager.cpp",
               1383,
               "_argBuildingFX[ i ].iFrame < GetBuildingJobFrameCount( _iRace, _argBuildingFX[ i ].iBuildingDefine )") == 1 )
        {
          __debugbreak();
        }
        *(_DWORD *)(a6 + 8 * i + 4) &= (*(_DWORD *)(a6 + 8 * i + 4) >= CGfxManager::GetBuildingJobFrameCount(
                                                                         this,
                                                                         a3,
                                                                         *(_DWORD *)(a6 + 8 * i)))
                                     - 1;
        dword_3ECDD70 = *(_DWORD *)(*((_DWORD *)this + 2 * v7 + 295) + 4 * *(_DWORD *)(a6 + 8 * i) + 20);
        dword_3ECDD74 = *(_DWORD *)(dword_3ECDD70 + 4 * *(_DWORD *)(a6 + 8 * i + 4));
        *((_DWORD *)a2 + i + 8) = dword_3ECDD74;
      }
    }
  }
  if ( (a5 & 8) != 0 )
  {
    dword_3ECDD74 = *(_DWORD *)(dword_3ECDD6C + 8);
    dword_3ECDD70 = *(_DWORD *)dword_3ECDD74;
    *((_DWORD *)a2 + 13) = dword_3ECDD70;
  }
  if ( !*((_DWORD *)this + v7 + 169) && BBSupportDbgReportF(2, "GfxManager.cpp", 1407, "m_pFilePalIndex[ %u ]", v7) == 1 )
    __debugbreak();
  *((_DWORD *)a2 + 1) = *(_DWORD *)(*((_DWORD *)this + v7 + 169) + 4 * v9 + 20);
  j__sprintf(byte_3ECDC20, "Building Race: %u, Building: %u, Flags: 0x%x", a3, v9, a5);
  CGfxManager::Debug_Check_LayerBlock(this, v7, a2);
}


// address=[0x1361f10]
// Decompiled from int __thiscall CGfxManager::GetBuildingFirstJob(CGfxManager *this, unsigned int a2, unsigned int a3)
unsigned int  CGfxManager::GetBuildingFirstJob(unsigned int a2, unsigned int a3) {
  
  int v4; // [esp+0h] [ebp-10h] BYREF
  int v5; // [esp+4h] [ebp-Ch] BYREF
  CGfxManager *v6; // [esp+8h] [ebp-8h]
  unsigned int v7; // [esp+Ch] [ebp-4h]

  v6 = this;
  v7 = a2 + 10;
  if ( !*((_DWORD *)this + 2 * a2 + 399)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 1127, "m_pFileGfxJobs[ %u ].pItem", v7) == 1 )
  {
    __debugbreak();
  }
  CGfxManager::GetJobIndices(v6, v7, a3, &v5, &v4);
  return v5;
}


// address=[0x1361f80]
// Decompiled from void __thiscall CGfxManager::GetObjectGfxInfo(  CGfxManager *this,  struct SGfxObjectInfo *a2,  unsigned int a3,  unsigned int a4,  int a5)
void  CGfxManager::GetObjectGfxInfo(struct SGfxObjectInfo & a2, unsigned int a3, unsigned int a4, unsigned int a5) {
  
  unsigned int v6; // [esp+24h] [ebp+Ch]
  unsigned int v7; // [esp+28h] [ebp+10h]
  int v8; // [esp+2Ch] [ebp+14h]

  if ( !*((_DWORD *)this + 2 * dword_3D7AB18 + 379)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 1424, "m_pFileGfxJobs[ %u ].pItem", dword_3D7AB18) == 1 )
  {
    __debugbreak();
  }
  if ( a3 >= 0x228 && BBSupportDbgReportF(2, "GfxManager.cpp", 1425, "%u < SIV_OBJECT_MAX", a3) == 1 )
    __debugbreak();
  v6 = a3 >= 0x228 ? 0 : a3;
  if ( a4 >= CGfxManager::GetObjectFrameCount(this, v6)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 1429, "%u < GetObjectFrameCount( %u )", a4, v6) == 1 )
  {
    __debugbreak();
  }
  v7 = a4 >= CGfxManager::GetObjectFrameCount(this, v6) ? 0 : a4;
  if ( !a5 && BBSupportDbgReportF(2, "GfxManager.cpp", 1432, "_iAmount : %u", 0) == 1 )
    __debugbreak();
  v8 = a5 - 1;
  *(_DWORD *)a2 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2 * dword_3D7AB18 + 379) + 4 * v6 + 20) + 4 * v8)
                            + 4 * v7);
  if ( !*((_DWORD *)this + dword_3D7AB18 + 169)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 1446, "m_pFilePalIndex[ %u ]", dword_3D7AB18) == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)a2 + 1) = *(_DWORD *)(*((_DWORD *)this + dword_3D7AB18 + 169) + 4 * v6 + 20);
  j__sprintf(byte_3ECDC20, "Object: %u, Frame: %u, Amount: %u", v6, v7, v8);
  CGfxManager::Debug_Check_LayerBlock(this, dword_3D7AB18, a2);
}


// address=[0x13621a0]
// Decompiled from unsigned int __thiscall CGfxManager::GetObjectFirstJob(CGfxManager *this, unsigned int a2)
unsigned int  CGfxManager::GetObjectFirstJob(unsigned int a2) {
  
  if ( !*((_DWORD *)this + 473)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 1085, "m_pFileGfxJobCodes[ %u ].pItem", 5) == 1 )
  {
    __debugbreak();
  }
  return (unsigned int)(*(_DWORD *)(*((_DWORD *)this + 473) + 4 * a2 + 20) - 20) >> 2;
}


// address=[0x1362210]
// Decompiled from void __thiscall CGfxManager::GetSettlerGfxInfo(  CGfxManager *this,  struct SGfxObjectInfo *a2,  unsigned int a3,  unsigned int a4,  unsigned int a5,  unsigned int a6)
void  CGfxManager::GetSettlerGfxInfo(struct SGfxObjectInfo & a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6) {
  
  unsigned int v7; // [esp+Ch] [ebp-8h]
  unsigned int v8; // [esp+24h] [ebp+10h]
  unsigned int v9; // [esp+28h] [ebp+14h]

  v7 = a3 + 20;
  if ( !*((_DWORD *)this + 2 * a3 + 419)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 967, "m_pFileGfxJobs[ %u ].pItem", v7) == 1 )
  {
    __debugbreak();
  }
  if ( a4 >= 0x16F && BBSupportDbgReport(2, "GfxManager.cpp", 968, "_iJob < SIV_MAX_JOB") == 1 )
    __debugbreak();
  v8 = a4 >= 0x16F ? 0 : a4;
  if ( a5 >= CGfxManager::GetSettlerJobFrameCount(this, a3, v8, 2u)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 972, "Invalid frame %i, job %i, race %i", a5, v8, a3) == 1 )
  {
    __debugbreak();
  }
  v9 = a5 >= CGfxManager::GetSettlerJobFrameCount(this, a3, v8, 2u) ? 0 : a5;
  dword_3ECDD5C = *(_DWORD *)(*((_DWORD *)this + 2 * v7 + 379) + 4 * v8 + 20);
  dword_3ECDD60 = *(_DWORD *)(dword_3ECDD5C + 4 * a6);
  dword_3ECDD5C = *(_DWORD *)(dword_3ECDD60 + 4 * v9);
  *(_DWORD *)a2 = dword_3ECDD5C;
  if ( !*((_DWORD *)this + v7 + 169) && BBSupportDbgReportF(2, "GfxManager.cpp", 985, "m_pFilePalIndex[ %u ]", v7) == 1 )
    __debugbreak();
  *((_DWORD *)a2 + 1) = *(_DWORD *)(*((_DWORD *)this + v7 + 169) + 4 * v8 + 20);
  j__sprintf(byte_3ECDC20, "Settler Race: %u, Job: %u, Frame: %u, Direction: %u", a3, v8, v9, a6);
  CGfxManager::Debug_Check_LayerBlock(this, v7, a2);
}


// address=[0x1362410]
// Decompiled from unsigned int __thiscall CGfxManager::GetSettlerFirstJob(_DWORD *this, int a2, int a3)
unsigned int  CGfxManager::GetSettlerFirstJob(unsigned int a2, unsigned int a3) {
  
  int v4; // [esp+Ch] [ebp-4h]

  v4 = a2 + 20;
  if ( this[2 * a2 + 503] )
  {
    if ( *(_DWORD *)(this[2 * v4 + 379]
                   + 4 * ((unsigned int)(*(_DWORD *)(this[2 * v4 + 463] + 4 * a3 + 20) - 20) >> 2)
                   + 20) == this[2 * v4 + 295] + 20 )
      return 0;
    else
      return (unsigned int)(*(_DWORD *)(this[2 * v4 + 463] + 4 * a3 + 20) - 20) >> 2;
  }
  else
  {
    if ( byte_3ECDBF4[v4] )
      return 1;
    BBSupportTracePrintF(2, "GfxManager.cpp: !!! GetSettlerFirstJob() for unloaded gfx %d file called !!", v4);
    byte_3ECDBF4[v4] = 1;
    return 1;
  }
}


// address=[0x13624d0]
// Decompiled from void __thiscall CGfxManager::GetPatchSettlerGfxInfo(  CGfxManager *this,  struct SGfxPatchObject *a2,  unsigned int a3,  unsigned int a4,  unsigned int a5,  unsigned int a6)
void  CGfxManager::GetPatchSettlerGfxInfo(struct SGfxPatchObject & a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6) {
  
  unsigned int v7; // [esp+4h] [ebp-4h]

  v7 = a3 + 20;
  if ( !*((_DWORD *)this + 2 * a3 + 419)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 1008, "m_pFileGfxJobs[ %u ].pItem", v7) == 1 )
  {
    __debugbreak();
  }
  if ( a4 >= 0x16F )
  {
    BBSupportTracePrintF(2, "GfxManager: Invalid Settler Job#%d for Race#%d, Direction#%d, Frame#%d", a4, a3, a6, a5);
    a4 = 0;
  }
  dword_3ECDD64 = *(_DWORD *)(*((_DWORD *)this + 2 * v7 + 379) + 4 * a4 + 20);
  dword_3ECDD68 = *(_DWORD *)(dword_3ECDD64 + 4 * a6);
  dword_3ECDD64 = *(_DWORD *)(dword_3ECDD68 + 4 * a5);
  *(_DWORD *)a2 = dword_3ECDD64;
  if ( !*((_DWORD *)this + v7 + 169) && BBSupportDbgReportF(2, "GfxManager.cpp", 1025, "m_pFilePalIndex[ %u ]", v7) == 1 )
    __debugbreak();
  *((_DWORD *)a2 + 1) = *(_DWORD *)(*((_DWORD *)this + v7 + 169) + 4 * a4 + 20);
  j__sprintf(byte_3ECDC20, "Patch Settler Race: %u, Job: %u, Frame: %u, Direction: %u", a3, a4, a5, a6);
  CGfxManager::Debug_Check_PatchLayerBlock(this, v7, a2);
}


// address=[0x1362620]
// Decompiled from void __thiscall CGfxManager::GetPileGfxInfo(  CGfxManager *this,  struct SGfxObjectInfo *a2,  int a3,  int a4,  unsigned int a5)
void  CGfxManager::GetPileGfxInfo(struct SGfxObjectInfo & a2, unsigned int a3, unsigned int a4, unsigned int a5) {
  
  unsigned int v6; // [esp+24h] [ebp+10h]
  int v7; // [esp+24h] [ebp+10h]
  unsigned int v8; // [esp+28h] [ebp+14h]

  if ( !*((_DWORD *)this + 2 * dword_3D7AB1C + 379)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 1463, "m_pFileGfxJobs[ %u ].pItem", dword_3D7AB1C) == 1 )
  {
    __debugbreak();
  }
  if ( !a4 && BBSupportDbgReportF(2, "GfxManager.cpp", 1464, "_iAmount %u", 0) == 1 )
    __debugbreak();
  v6 = a4 - 1;
  if ( v6 >= 0x10 && BBSupportDbgReportF(2, "GfxManager.cpp", 1468, "%u < 16", v6) == 1 )
    __debugbreak();
  v7 = v6 & 0xF;
  if ( a5 >= CGfxManager::GetPileFrameCount(a3)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 1471, "%u < GetPileFrameCount( %u )", a5, a3) == 1 )
  {
    __debugbreak();
  }
  v8 = a5 >= CGfxManager::GetPileFrameCount(a3) ? 0 : a5;
  *(_DWORD *)a2 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2 * dword_3D7AB1C + 379) + 4 * a3 + 20) + 4 * v7)
                            + 4 * v8);
  if ( !*((_DWORD *)this + dword_3D7AB1C + 169)
    && BBSupportDbgReport(2, "GfxManager.cpp", 1484, "m_pFilePalIndex[ iGfxFile ]") == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)a2 + 1) = *(_DWORD *)(*((_DWORD *)this + dword_3D7AB1C + 169) + 4 * a3 + 20);
  j__sprintf(byte_3ECDC20, "Pile: %u, Amount: %u, Frame: %u", a3, v7, v8);
  CGfxManager::Debug_Check_LayerBlock(this, dword_3D7AB1C, a2);
}


// address=[0x1362810]
// Decompiled from void __thiscall CGfxManager::GetPatchPileGfxInfo(  CGfxManager *this,  struct SGfxPatchObject *a2,  int a3,  unsigned int a4,  unsigned int a5)
void  CGfxManager::GetPatchPileGfxInfo(struct SGfxPatchObject & a2, unsigned int a3, unsigned int a4, unsigned int a5) {
  
  unsigned int v6; // [esp+24h] [ebp+10h]
  unsigned int v7; // [esp+28h] [ebp+14h]

  if ( !a4 && BBSupportDbgReportF(2, "GfxManager.cpp", 1501, "_iAmount %u", 0) == 1 )
    __debugbreak();
  v6 = a4 - 1;
  if ( v6 >= 0x10 && BBSupportDbgReportF(2, "GfxManager.cpp", 1505, "%u < 16", v6) == 1 )
    __debugbreak();
  if ( !*((_DWORD *)this + 2 * dword_3D7AB20 + 379)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 1507, "m_pFileGfxJobs[ %u ].pItem", v6) == 1 )
  {
    __debugbreak();
  }
  if ( a5 >= CGfxManager::GetPileFrameCount(a3)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 1508, "%u < GetPileFrameCount( %u )", a5, a3) == 1 )
  {
    __debugbreak();
  }
  v7 = a5 >= CGfxManager::GetPileFrameCount(a3) ? 0 : a5;
  *(_DWORD *)a2 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2 * dword_3D7AB20 + 379) + 4 * a3 + 20) + 4 * v6)
                            + 4 * v7);
  if ( !*((_DWORD *)this + dword_3D7AB20 + 169)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 1521, "m_pFilePalIndex[ %u ]", dword_3D7AB20) == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)a2 + 1) = *(_DWORD *)(*((_DWORD *)this + dword_3D7AB20 + 169) + 4 * a3 + 20);
  j__sprintf(byte_3ECDC20, "PatchPile: %u, Amount: %u, Frame: %u", a3, v6, v7);
  CGfxManager::Debug_Check_PatchLayerBlock(this, dword_3D7AB20, a2);
}


// address=[0x1362a00]
// Decompiled from void __thiscall CGfxManager::GetVehicleGfxInfo(  CGfxManager *this,  struct SGfxObjectInfo *a2,  unsigned int a3,  unsigned int a4,  unsigned int a5,  unsigned int a6,  unsigned int a7,  unsigned int a8)
void  CGfxManager::GetVehicleGfxInfo(struct SGfxObjectInfo & a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7, unsigned int a8) {
  
  unsigned int v9; // [esp+1Ch] [ebp-8h]
  unsigned int v10; // [esp+34h] [ebp+10h]
  unsigned int v11; // [esp+3Ch] [ebp+18h]

  v9 = a3 + 30;
  if ( !*((_DWORD *)this + 2 * a3 + 439)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 1538, "m_pFileGfxJobs[ %u ].pItem", v9) == 1 )
  {
    __debugbreak();
  }
  if ( a4 >= *((_DWORD *)this + 2 * v9 + 380)
    && BBSupportDbgReport(2, "GfxManager.cpp", 1539, "_iJob < m_pFileGfxJobs[ iGfxFile ].iCount") == 1 )
  {
    __debugbreak();
  }
  v10 = a4 >= *((_DWORD *)this + 2 * v9 + 380) ? 0 : a4;
  if ( a6 >= CGfxManager::GetVehicleFrameCount(this, a3, v10)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 1543, "_iFrame < GetVehicleFrameCount( %u, %u )", a3, v10) == 1 )
  {
    __debugbreak();
  }
  v11 = a6 >= CGfxManager::GetVehicleFrameCount(this, a3, v10) ? 0 : a6;
  *(_DWORD *)a2 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2 * v9 + 379) + 4 * v10 + 20) + 4 * a5)
                            + 4 * v11);
  if ( !*((_DWORD *)this + v9 + 169) && BBSupportDbgReportF(2, "GfxManager.cpp", 1555, "m_pFilePalIndex[ %u ]", v9) == 1 )
    __debugbreak();
  *((_DWORD *)a2 + 1) = *(_DWORD *)(*((_DWORD *)this + v9 + 169) + 4 * v10 + 20);
  if ( a7 )
  {
    if ( a7 >= *((_DWORD *)this + 2 * v9 + 380)
      && BBSupportDbgReport(2, "GfxManager.cpp", 1561, "_iJobPatch < m_pFileGfxJobs[ iGfxFile ].iCount") == 1 )
    {
      __debugbreak();
    }
    a7 &= (a7 >= *((_DWORD *)this + 2 * v9 + 380)) - 1;
    if ( v11 >= CGfxManager::GetVehicleFrameCount(this, a3, a7)
      && BBSupportDbgReportF(2, "GfxManager.cpp", 1565, "_iFrame < GetVehicleFrameCount( %u, %u )", a3, a7) == 1 )
    {
      __debugbreak();
    }
    v11 &= (v11 >= CGfxManager::GetVehicleFrameCount(this, a3, a7)) - 1;
    *((_DWORD *)a2 + 3) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2 * v9 + 379) + 4 * a7 + 20) + 4 * a5)
                                    + 4 * a8);
    *((_DWORD *)a2 + 4) = *(_DWORD *)(*((_DWORD *)this + v9 + 169) + 4 * a7 + 20);
  }
  j__sprintf(
    byte_3ECDC20,
    "Vehicle Race: %u, Job: %u, Direction: %u, Frame: %u, JobPatch: %u, FramePatch: %u",
    a3,
    v10,
    a5,
    v11,
    a7,
    a8);
  CGfxManager::Debug_Check_LayerBlock(this, v9, a2);
}


// address=[0x1362d50]
// Decompiled from unsigned int __thiscall CGfxManager::GetVehicleFirstJob(CGfxManager *this, unsigned int a2, unsigned int a3)
unsigned int  CGfxManager::GetVehicleFirstJob(unsigned int a2, unsigned int a3) {
  
  int v5; // [esp+8h] [ebp-4h]

  v5 = a2 + 30;
  if ( !*((_DWORD *)this + 2 * a2 + 523)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 1113, "m_pFileGfxJobCodes[ %u ].pItem", v5) == 1 )
  {
    __debugbreak();
  }
  return (unsigned int)(*(_DWORD *)(*((_DWORD *)this + 2 * v5 + 463) + 4 * a3 + 20) - 20) >> 2;
}


// address=[0x1362dc0]
// Decompiled from void __thiscall CGfxManager::GetAnimalGfxInfo(  CGfxManager *this,  struct SGfxObjectInfo *a2,  unsigned int a3,  int a4,  unsigned int a5)
void  CGfxManager::GetAnimalGfxInfo(struct SGfxObjectInfo & a2, unsigned int a3, unsigned int a4, unsigned int a5) {
  
  unsigned int v6; // [esp+28h] [ebp+Ch]
  unsigned int v7; // [esp+30h] [ebp+14h]

  if ( !*((_DWORD *)this + 395)
    && BBSupportDbgReport(2, "GfxManager.cpp", 1593, "m_pFileGfxJobs[ iGfxFile ].pItem") == 1 )
  {
    __debugbreak();
  }
  if ( a3 >= *((_DWORD *)this + 396)
    && BBSupportDbgReport(2, "GfxManager.cpp", 1594, "_iJob < m_pFileGfxJobs[ iGfxFile ].iCount") == 1 )
  {
    __debugbreak();
  }
  v6 = a3 >= *((_DWORD *)this + 396) ? 0 : a3;
  if ( a5 >= CGfxManager::GetAnimalFrameCount(this, v6)
    && BBSupportDbgReport(2, "GfxManager.cpp", 1598, "_iFrame < GetAnimalFrameCount( _iJob )") == 1 )
  {
    __debugbreak();
  }
  v7 = a5 >= CGfxManager::GetAnimalFrameCount(this, v6) ? 0 : a5;
  if ( v6 > *((_DWORD *)this + 396) )
  {
    BBSupportTracePrintF(2, "GfxManager: Invalid Animal Job#%d for Direction#%d, Frame#%d", v6, a4, v7);
    v6 = 0;
  }
  *(_DWORD *)a2 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 395) + 4 * v6 + 20) + 4 * a4) + 4 * v7);
  if ( !*((_DWORD *)this + 177) && BBSupportDbgReport(2, "GfxManager.cpp", 1616, "m_pFilePalIndex[ iGfxFile ]") == 1 )
    __debugbreak();
  *((_DWORD *)a2 + 1) = *(_DWORD *)(*((_DWORD *)this + 177) + 4 * v6 + 20);
  j__sprintf(byte_3ECDC20, "Animal %u, Direction: %u, Frame: %u", v6, a4, v7);
  CGfxManager::Debug_Check_LayerBlock(this, 8u, a2);
}


// address=[0x1362fc0]
// Decompiled from unsigned int __thiscall CGfxManager::GetAnimalFirstJob(CGfxManager *this, unsigned int a2)
unsigned int  CGfxManager::GetAnimalFirstJob(unsigned int a2) {
  
  if ( !*((_DWORD *)this + 479)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 1099, "m_pFileGfxJobCodes[ %u ].pItem", 8) == 1 )
  {
    __debugbreak();
  }
  return (unsigned int)(*(_DWORD *)(*((_DWORD *)this + 479) + 4 * a2 + 20) - 20) >> 2;
}


// address=[0x1363030]
// Decompiled from void __thiscall CGfxManager::GetEffectGfxInfo(  CGfxManager *this,  struct SGfxObjectInfo *a2,  unsigned int a3,  unsigned int a4,  unsigned int a5)
void  CGfxManager::GetEffectGfxInfo(struct SGfxObjectInfo & a2, unsigned int a3, unsigned int a4, unsigned int a5) {
  
  unsigned int v5; // [esp+Ch] [ebp-24h]
  int v6; // [esp+18h] [ebp-18h]
  int v7; // [esp+1Ch] [ebp-14h]
  unsigned int v9; // [esp+28h] [ebp-8h]
  BOOL v10; // [esp+2Ch] [ebp-4h]
  unsigned int v11; // [esp+3Ch] [ebp+Ch]
  unsigned int v12; // [esp+44h] [ebp+14h]

  if ( a3 >= 0x64 )
  {
    if ( IGfxEngine::Use4444Palettes((IGfxEngine *)g_pGfxEngine) )
      v6 = 36;
    else
      v6 = 37;
    v9 = v6;
  }
  else
  {
    if ( IGfxEngine::Use4444Palettes((IGfxEngine *)g_pGfxEngine) )
      v7 = 4;
    else
      v7 = 6;
    v9 = v7;
  }
  if ( !*((_DWORD *)this + 2 * v9 + 379)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 1686, "m_pFileGfxJobs[%d].pItem", v9) == 1 )
  {
    __debugbreak();
  }
  if ( a3 >= 0x64 )
  {
    if ( a3 >= 0x74 && BBSupportDbgReportF(2, "GfxManager.cpp", 1694, "_iJob < EFFECT_2_MAX: iJob %u", a3) == 1 )
      __debugbreak();
    v10 = a3 >= 0x74;
  }
  else
  {
    if ( a3 >= 0x56 && BBSupportDbgReportF(2, "GfxManager.cpp", 1689, "_iJob < EFFECT_MAX: iJob %u", a3) == 1 )
      __debugbreak();
    v10 = a3 >= 0x56;
  }
  if ( a3 >= 0x64 )
    v5 = a3 - 100;
  else
    v5 = a3;
  v11 = v10 ? 0 : a3;
  if ( a5 >= CGfxManager::GetEffectFrameCount(this, v11)
    && BBSupportDbgReportF(
         2,
         "GfxManager.cpp",
         1702,
         "_iFrame < GetEffectFrameCount( _iJob ): Job %u, Dir %u, Frame %u",
         v11,
         a4,
         a5) == 1 )
  {
    __debugbreak();
  }
  v12 = a5 >= CGfxManager::GetEffectFrameCount(this, v11) ? 0 : a5;
  *(_DWORD *)a2 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2 * v9 + 379) + 4 * v5 + 20) + 4 * a4) + 4 * v12);
  if ( !*((_DWORD *)this + v9 + 169)
    && BBSupportDbgReport(2, "GfxManager.cpp", 1715, "m_pFilePalIndex[ iGfxFile ]") == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)a2 + 1) = *(_DWORD *)(*((_DWORD *)this + v9 + 169) + 4 * v5 + 20);
  j__sprintf(byte_3ECDC20, "Effect: %u, Direction: %u, Frame: %u", v11, a4, v12);
  CGfxManager::Debug_Check_LayerBlock(this, v9, a2);
}


// address=[0x13632c0]
// Decompiled from void __thiscall CGfxManager::GetAccessoryGfxInfo(CGfxManager *this, struct SGfxObjectInfo *a2, unsigned int a3)
void  CGfxManager::GetAccessoryGfxInfo(struct SGfxObjectInfo & a2, unsigned int a3) {
  
  unsigned int v4; // [esp+20h] [ebp+Ch]

  if ( !*((_DWORD *)this + 2 * dword_3D7AB24 + 211)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 1634, "m_pFileGfxFrames[ %u ].pItem", dword_3D7AB24) == 1 )
  {
    __debugbreak();
  }
  if ( a3 >= 0x60 && BBSupportDbgReportF(2, "GfxManager.cpp", 1635, "_iAccessory < ACCESSORY_MAX: %u", a3) == 1 )
    __debugbreak();
  v4 = a3 >= 0x60 ? 0 : a3;
  *(_DWORD *)a2 = ***(_DWORD ***)(*((_DWORD *)this + 2 * dword_3D7AB24 + 379) + 4 * v4 + 20);
  if ( !*((_DWORD *)this + dword_3D7AB24 + 169)
    && BBSupportDbgReport(2, "GfxManager.cpp", 1649, "m_pFilePalIndex[ iGfxFile ]") == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)a2 + 1) = *(_DWORD *)(*((_DWORD *)this + dword_3D7AB24 + 169) + 4 * v4 + 20);
  j__sprintf(byte_3ECDC20, "Accessory: %u", v4);
  CGfxManager::Debug_Check_LayerBlock(this, dword_3D7AB24, a2);
}


// address=[0x1363410]
// Decompiled from int __thiscall CGfxManager::GetSettlerJobFrameCount(CGfxManager *this, unsigned int a2, int a3, int a4)
unsigned int  CGfxManager::GetSettlerJobFrameCount(unsigned int a2, unsigned int a3, unsigned int a4) {
  
  return CGfxManager::GetJobFrameCount(a2 + 20, a3, a4);
}


// address=[0x1363440]
// Decompiled from int __thiscall CGfxManager::GetObjectFrameCount(CGfxManager *this, int a2)
unsigned int  CGfxManager::GetObjectFrameCount(unsigned int a2) {
  
  return CGfxManager::GetJobFrameCount(5, a2, 0);
}


// address=[0x1363470]
// Decompiled from int __stdcall sub_1763470(int a1)
unsigned int  CGfxManager::GetPileFrameCount(unsigned int a1) {
  
  return CGfxManager::GetJobFrameCount(3, a1, 0);
}


// address=[0x13634a0]
// Decompiled from int __thiscall CGfxManager::GetVehicleFrameCount(CGfxManager *this, unsigned int a2, int a3)
unsigned int  CGfxManager::GetVehicleFrameCount(unsigned int a2, unsigned int a3) {
  
  return CGfxManager::GetJobFrameCount(a2 + 30, a3, 2);
}


// address=[0x13634e0]
// Decompiled from int __thiscall CGfxManager::GetAnimalFrameCount(CGfxManager *this, int a2)
unsigned int  CGfxManager::GetAnimalFrameCount(unsigned int a2) {
  
  return CGfxManager::GetJobFrameCount(8, a2, 2);
}


// address=[0x1363510]
// Decompiled from int __thiscall CGfxManager::GetEffectFrameCount(CGfxManager *this, unsigned int a2)
unsigned int  CGfxManager::GetEffectFrameCount(unsigned int a2) {
  
  int v3; // [esp+4h] [ebp-10h]
  int v4; // [esp+Ch] [ebp-8h]
  int v5; // [esp+10h] [ebp-4h]

  if ( a2 >= 0x64 )
  {
    if ( IGfxEngine::Use4444Palettes((IGfxEngine *)g_pGfxEngine) )
      v4 = 36;
    else
      v4 = 37;
    v3 = v4;
  }
  else
  {
    if ( IGfxEngine::Use4444Palettes((IGfxEngine *)g_pGfxEngine) )
      v5 = 4;
    else
      v5 = 6;
    v3 = v5;
  }
  if ( a2 >= 0x64 )
    return CGfxManager::GetJobFrameCount(v3, a2 - 100, 0);
  else
    return CGfxManager::GetJobFrameCount(v3, a2, 0);
}


// address=[0x13635a0]
// Decompiled from int __thiscall CGfxManager::GetBuildingJobFrameCount(CGfxManager *this, unsigned int a2, int a3)
unsigned int  CGfxManager::GetBuildingJobFrameCount(unsigned int a2, unsigned int a3) {
  
  return CGfxManager::GetJobFrameCount(a2 + 10, a3, 0);
}


// address=[0x13635d0]
// Decompiled from struct SGfxBoundingBox *__thiscall CGfxManager::GetBoundingBox(  CGfxManager *this,  struct SGfxBoundingBox *a2,  unsigned int a3,  unsigned int a4,  unsigned int a5)
void  CGfxManager::GetBoundingBox(struct SGfxBoundingBox & a2, unsigned int a3, unsigned int a4, unsigned int a5) {
  
  struct SGfxBoundingBox *result; // eax
  float v6; // [esp+0h] [ebp-2F0h]
  float v7; // [esp+4h] [ebp-2ECh]
  float v8; // [esp+8h] [ebp-2E8h]
  float v9; // [esp+Ch] [ebp-2E4h]
  float CurrentZoomFactor; // [esp+14h] [ebp-2DCh]
  _DWORD v11[180]; // [esp+1Ch] [ebp-2D4h] BYREF

  switch ( a3 )
  {
    case 1u:
      CGfxManager::GetSettlerGfxInfo(this, (struct SGfxObjectInfo *)v11, a4, a5, 1u, 0);
      v9 = FLOAT_25_0;
      v8 = (float)*(unsigned __int8 *)(v11[0] + 1);
      v7 = 25.0 / 2.0;
      v6 = (float)*(unsigned __int8 *)(v11[0] + 3);
      break;
    case 2u:
    case 4u:
    case 8u:
      if ( a3 == 8 )
        CGfxManager::GetBuildingGfxInfo((int)v11, a4, a5, 1, 0);
      else
        CGfxManager::GetVehicleGfxInfo(this, (struct SGfxObjectInfo *)v11, a4, a5, 0, 0, 0, 0);
      v9 = (float)*(unsigned __int16 *)v11[0];
      v8 = (float)*(unsigned __int16 *)(v11[0] + 2);
      v7 = (float)*(__int16 *)(v11[0] + 4);
      v6 = (float)*(__int16 *)(v11[0] + 6);
      break;
    default:
      break;
  }
  CurrentZoomFactor = IGfxEngine::GetCurrentZoomFactor((IGfxEngine *)g_pGfxEngine);
  *((_DWORD *)a2 + 1) = (int)(float)(v8 * CurrentZoomFactor);
  *(_DWORD *)a2 = (int)(float)(v9 * CurrentZoomFactor);
  result = a2;
  *((_DWORD *)a2 + 2) = (int)(float)(v7 * CurrentZoomFactor);
  *((_DWORD *)a2 + 3) = (int)(float)(v6 * CurrentZoomFactor);
  return result;
}


// address=[0x13637e0]
// Decompiled from char __thiscall CGfxManager::EnableGfxFile(CGfxManager *this, unsigned int a2, int a3, bool a4, unsigned int a5)
bool  CGfxManager::EnableGfxFile(unsigned int a2, int a3, bool a4, unsigned int a5) {
  
  char result; // al

  BBSupportTracePrintF(2, "GfxManager.cpp: Enabling GfxFile %d", a2);
  switch ( a3 )
  {
    case 0:
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
      if ( CGfxManager::LoadGfxFile(this, a2, a4, a5) )
      {
        if ( CGfxManager::LoadGilFile(this, a2, a5) )
        {
          if ( CGfxManager::LoadDilFile(this, a2, a5) )
          {
            if ( CGfxManager::LoadJilFile(this, a2, a5) )
            {
              if ( CGfxManager::LoadSilFile(this, a2, a5) )
              {
                if ( CGfxManager::LoadPalFile(this, a2, a5, 0) )
                {
                  if ( CGfxManager::LoadPilFile(this, a2, a5, 0) )
                    goto LABEL_52;
                  result = 0;
                }
                else
                {
                  result = 0;
                }
              }
              else
              {
                result = 0;
              }
            }
            else
            {
              result = 0;
            }
          }
          else
          {
            result = 0;
          }
        }
        else
        {
          result = 0;
        }
      }
      else
      {
        result = 0;
      }
      break;
    case 2:
      if ( CGfxManager::LoadGfxFile(this, a2, a4, a5) )
      {
        if ( CGfxManager::LoadGilFile(this, a2, a5) )
        {
          if ( CGfxManager::LoadDilFile(this, a2, a5) )
          {
            if ( CGfxManager::LoadJilFile(this, a2, a5) )
            {
              if ( CGfxManager::LoadPalFile(this, a2, a5, 0) )
              {
                if ( CGfxManager::LoadPilFile(this, a2, a5, 0) )
                  goto LABEL_52;
                result = 0;
              }
              else
              {
                result = 0;
              }
            }
            else
            {
              result = 0;
            }
          }
          else
          {
            result = 0;
          }
        }
        else
        {
          result = 0;
        }
      }
      else
      {
        result = 0;
      }
      break;
    case 8:
      if ( CGfxManager::LoadGfxFile(this, a2, a4, a5) )
      {
        if ( CGfxManager::LoadGilFile(this, a2, a5) )
        {
          if ( CGfxManager::LoadPalFile(this, a2, a5, 0) )
          {
            if ( CGfxManager::LoadPilFile(this, a2, a5, 0) )
              goto LABEL_52;
            result = 0;
          }
          else
          {
            result = 0;
          }
        }
        else
        {
          result = 0;
        }
      }
      else
      {
        result = 0;
      }
      break;
    case 9:
      if ( CGfxManager::LoadGfxFile(this, a2, a4, a5) )
      {
        if ( CGfxManager::LoadGilFile(this, a2, a5) )
        {
          if ( CGfxManager::LoadPalFile(this, a2, a5, 1) )
          {
            if ( CGfxManager::LoadPilFile(this, a2, a5, 1) )
            {
              *((_DWORD *)this + 807) = a2;
              goto LABEL_52;
            }
            result = 0;
          }
          else
          {
            result = 0;
          }
        }
        else
        {
          result = 0;
        }
      }
      else
      {
        result = 0;
      }
      break;
    case 10:
      if ( CGfxManager::LoadGfxFile(this, a2, a4, a5) )
LABEL_52:
        result = 1;
      else
        result = 0;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}


// address=[0x1363b20]
// Decompiled from int __cdecl CGfxManager::Reload(int a1, bool a2, bool a3)
void * __cdecl CGfxManager::Reload(int a1, bool a2, bool a3) {
  
  int v4; // [esp+4h] [ebp-4h]

  v4 = 0;
  if ( !g_pGfxManager )
    return 0;
  *(_BYTE *)(g_pGfxManager + 3224) = !a3;
  *(_BYTE *)(g_pGfxManager + 3225) = a2;
  if ( *(_DWORD *)(g_pGfxManager + 2300) )
    CGfxManager::MoveAccessoriesToGfxEngine((CGfxManager *)g_pGfxManager);
  if ( *(_DWORD *)(g_pGfxManager + 2268) )
    CGfxManager::MoveWavesToGfxEngine((CGfxManager *)g_pGfxManager);
  if ( a1 == 1 )
  {
    if ( *(_BYTE *)(g_pGfxManager + 3262) )
    {
      if ( !CGfxManager::EnableGfxFile((CGfxManager *)g_pGfxManager, 0x29u, 10, 1, 0xFFFFFFFF)
        && BBSupportDbgReport(1, "GfxManager.cpp", 2234, aCouldNotOpenAl_1) == 1 )
      {
        __debugbreak();
      }
      v4 = *(_DWORD *)(g_pGfxManager + 2844);
      if ( !v4 && BBSupportDbgReport(1, "GfxManager.cpp", 2237, aCouldNotOpenAl_2) == 1 )
        __debugbreak();
    }
    else
    {
      if ( !CGfxManager::EnableGfxFile((CGfxManager *)g_pGfxManager, 2u, 10, 1, 0xFFFFFFFF)
        && BBSupportDbgReport(1, "GfxManager.cpp", 2242, aCouldNotOpenAl) == 1 )
      {
        __debugbreak();
      }
      v4 = *(_DWORD *)(g_pGfxManager + 2220);
      if ( !v4 && BBSupportDbgReport(1, "GfxManager.cpp", 2245, aCouldNotOpenAl_0) == 1 )
        __debugbreak();
    }
    if ( v4 )
      v4 += 20;
  }
  else if ( !a1 )
  {
    if ( *(_BYTE *)(g_pGfxManager + 3262) )
      CGfxManager::DisableGfxFile((CGfxManager *)g_pGfxManager, 41);
    else
      CGfxManager::DisableGfxFile((CGfxManager *)g_pGfxManager, 2);
  }
  return v4;
}


// address=[0x1363d10]
// Decompiled from unsigned int __thiscall CGfxManager::GetJobFrameCount(  CGfxManager *this,  unsigned int a2,  unsigned int a3,  unsigned int a4)
unsigned int  CGfxManager::GetJobFrameCount(unsigned int a2, unsigned int a3, unsigned int a4) {
  
  int v6; // [esp+30h] [ebp-28h]
  int v7; // [esp+34h] [ebp-24h]
  int v8; // [esp+38h] [ebp-20h]
  int v9; // [esp+40h] [ebp-18h]
  _DWORD *v10; // [esp+44h] [ebp-14h]
  unsigned int i; // [esp+48h] [ebp-10h]
  unsigned int v12; // [esp+4Ch] [ebp-Ch]
  int v13; // [esp+50h] [ebp-8h]
  _DWORD *v14; // [esp+50h] [ebp-8h]

  if ( a2 == *((_DWORD *)this + 807) )
    return 1;
  if ( *((_DWORD *)this + 2 * a2 + 379) )
  {
    if ( a4 >= 6 && BBSupportDbgReport(2, "GfxManager.cpp", 1203, "_iDir < 6") == 1 )
      __debugbreak();
    if ( a2 < 0xA || a2 >= 0x14 )
    {
      if ( a3 >= *((_DWORD *)this + 2 * a2 + 380) )
      {
        BBSupportTracePrintF(2, "GfxManager: Invalid Job#%d for GfxFile#%d and Direction#%d", a3, a2, a4);
        a3 = 0;
      }
      v8 = *(_DWORD *)(*((_DWORD *)this + 2 * a2 + 379) + 20);
      v6 = *(_DWORD *)(*((_DWORD *)this + 2 * a2 + 295) + 20);
      v12 = a4;
      v13 = *(_DWORD *)(*((_DWORD *)this + 2 * a2 + 379) + 4 * a3 + 20);
      if ( v13 == v8 )
      {
        return 1;
      }
      else
      {
        v14 = (_DWORD *)(v13 + 4 * a4);
        v10 = v14;
        if ( *v14 == v6 )
        {
          return 1;
        }
        else
        {
          do
          {
            if ( ++v12 == CGfxManager::GetNrDirection(this, a2) )
            {
              if ( ++a3 >= *((_DWORD *)this + 2 * a2 + 380) )
                return *((_DWORD *)this + 2 * a2 + 212)
                     - ((unsigned int)(*v14 - (*((_DWORD *)this + 2 * a2 + 211) + 20)) >> 2);
              v12 = 0;
            }
            v7 = *(_DWORD *)(*((_DWORD *)this + 2 * a2 + 379) + 4 * a3 + 20);
            if ( v7 == v8 )
            {
              v12 = -1;
              if ( ++a3 >= *((_DWORD *)this + 2 * a2 + 380) )
                return *((_DWORD *)this + 2 * a2 + 212)
                     - ((unsigned int)(*v14 - (*((_DWORD *)this + 2 * a2 + 211) + 20)) >> 2);
            }
            else
            {
              v10 = (_DWORD *)(v7 + 4 * v12);
            }
          }
          while ( *v10 == v6 || *v10 == *v14 );
          if ( (unsigned int)(*v10 - *v14) >> 2 )
            return (unsigned int)(*v10 - *v14) >> 2;
          else
            return 1;
        }
      }
    }
    else
    {
      if ( a3 >= *((_DWORD *)this + 2 * a2 + 296) )
      {
        BBSupportTracePrintF(2, "GfxManager: Invalid Job#%d for GfxFile#%d and Direction#%d", a3, a2, a4);
        a3 = 0;
      }
      v9 = 0;
      for ( i = a3 + 1; i < *((_DWORD *)this + 2 * a2 + 296); ++i )
      {
        if ( *(_DWORD *)(*((_DWORD *)this + 2 * a2 + 295) + 4 * i + 20) != *((_DWORD *)this + 2 * a2 + 211) + 20 )
        {
          v9 = *(_DWORD *)(*((_DWORD *)this + 2 * a2 + 295) + 4 * i + 20);
          break;
        }
      }
      if ( !v9 )
        v9 = *((_DWORD *)this + 2 * a2 + 211) + *((_DWORD *)this + 2 * a2 + 212) + 5;
      return (unsigned int)(v9 - *(_DWORD *)(*((_DWORD *)this + 2 * a2 + 295) + 4 * a3 + 20)) >> 2;
    }
  }
  else
  {
    if ( byte_3ECDBF4[a2] )
      return 1;
    byte_3ECDBF4[a2] = 1;
    BBSupportTracePrintF(2, "GfxManager.cpp: !!! GetJobFrameCount() for unloaded gfx %d file called !!", a2);
    return 1;
  }
}


// address=[0x13640d0]
// Decompiled from bool __thiscall CGfxManager::IsDirectionAvailable(_DWORD *this, unsigned int a2, int a3, int a4)
bool  CGfxManager::IsDirectionAvailable(unsigned int a2, unsigned int a3, unsigned int a4) {
  
  if ( a2 == this[807] )
    return a4 == 0;
  if ( a2 < 0xA || a2 >= 0x13 )
  {
    if ( *(_DWORD *)(*(_DWORD *)(this[2 * a2 + 379] + 4 * a3 + 20) + 4 * a4) == *(_DWORD *)(this[2 * a2 + 295] + 20) )
      return 0;
  }
  else
  {
    if ( a4 )
      return 0;
    if ( *(_DWORD *)(this[2 * a2 + 295] + 4 * a3 + 20) == this[2 * a2 + 211] + 20 )
      return 0;
  }
  return 1;
}


// address=[0x1364190]
// Decompiled from int __thiscall CGfxManager::GetRawGfxInfo(  CGfxManager *this,  _DWORD *a2,  unsigned int a3,  unsigned int a4,  int a5,  int a6)
void  CGfxManager::GetRawGfxInfo(struct SGfxObjectInfo & a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6) {
  
  int result; // eax
  int v7; // [esp+0h] [ebp-1Ch] BYREF
  int v8; // [esp+4h] [ebp-18h] BYREF
  int v9; // [esp+8h] [ebp-14h] BYREF
  int v10; // [esp+Ch] [ebp-10h] BYREF
  unsigned int v11; // [esp+10h] [ebp-Ch]
  int v12; // [esp+14h] [ebp-8h]
  CGfxManager *v13; // [esp+18h] [ebp-4h]

  v13 = this;
  if ( !*((_DWORD *)this + 2 * a3 + 379)
    && BBSupportDbgReport(2, "GfxManager.cpp", 2419, "m_pFileGfxJobs[ _iGfxFile ].pItem") == 1 )
  {
    __debugbreak();
  }
  if ( a4 >= 0x16E )
    a4 = 0;
  if ( a3 < 0xA || a3 >= 0x13 )
  {
    dword_3ECDD78 = *(_DWORD *)(*((_DWORD *)v13 + 2 * a3 + 379) + 4 * a4 + 20);
    dword_3ECDD7C = *(_DWORD *)(dword_3ECDD78 + 4 * a5);
    dword_3ECDD78 = *(_DWORD *)(dword_3ECDD7C + 4 * a6);
    *a2 = dword_3ECDD78;
    if ( !*((_DWORD *)v13 + a3 + 169)
      && BBSupportDbgReport(2, "GfxManager.cpp", 2454, "m_pFilePalIndex[ _iGfxFile ]") == 1 )
    {
      __debugbreak();
    }
    result = (int)a2;
    a2[1] = *(_DWORD *)(*((_DWORD *)v13 + a3 + 169) + 4 * a4 + 20);
  }
  else
  {
    dword_3ECDD78 = *(_DWORD *)(*((_DWORD *)v13 + 2 * a3 + 295) + 4 * a4 + 20);
    dword_3ECDD7C = *(_DWORD *)(dword_3ECDD78 + 4 * a6);
    v12 = dword_3ECDD78 + 4 * a6;
    v11 = (v12 - (*((_DWORD *)v13 + 2 * a3 + 211) + 20)) >> 2;
    *a2 = dword_3ECDD7C;
    if ( !*((_DWORD *)v13 + a3 + 169)
      && BBSupportDbgReport(2, "GfxManager.cpp", 2439, "m_pFilePalIndex[ _iGfxFile ]") == 1 )
    {
      __debugbreak();
    }
    CGfxManager::GetImageInfo(v13, a3, v11, &v10, &v7, &v8, &v9);
    result = v10;
    a2[1] = *(_DWORD *)(*((_DWORD *)v13 + a3 + 169) + 4 * v10 + 20);
  }
  return result;
}


// address=[0x1364360]
// Decompiled from char __thiscall CGfxManager::GetRawGfxInfo_0(CGfxManager *this, _DWORD *a2, unsigned int a3, unsigned int a4)
void  CGfxManager::GetRawGfxInfo(struct SGfxObjectInfo & a2, unsigned int a3, unsigned int a4) {
  
  int v4; // eax
  int v6; // [esp+0h] [ebp-14h] BYREF
  int v7; // [esp+4h] [ebp-10h] BYREF
  int v8; // [esp+8h] [ebp-Ch] BYREF
  int v9; // [esp+Ch] [ebp-8h] BYREF
  CGfxManager *v10; // [esp+10h] [ebp-4h]

  v10 = this;
  if ( a4 >= *((_DWORD *)this + 2 * a3 + 212)
    && BBSupportDbgReport(2, "GfxManager.cpp", 2465, "_iGfxID < m_pFileGfxFrames[ _iGfxFile ].iCount") == 1 )
  {
    __debugbreak();
  }
  *a2 = *(_DWORD *)(*((_DWORD *)v10 + 2 * a3 + 211) + 4 * a4 + 20);
  if ( !*((_DWORD *)v10 + a3 + 169)
    && BBSupportDbgReport(2, "GfxManager.cpp", 2473, "m_pFilePalIndex[ _iGfxFile ]") == 1 )
  {
    __debugbreak();
  }
  LOBYTE(v4) = CGfxManager::GetImageInfo(v10, a3, a4, &v9, &v6, &v7, &v8);
  if ( v9 == -1 )
    return v4;
  v4 = *(_DWORD *)(*((_DWORD *)v10 + a3 + 169) + 4 * v9 + 20);
  a2[1] = v4;
  return v4;
}


// address=[0x1364430]
// Decompiled from char __thiscall CGfxManager::GetImageInfo(  CGfxManager *this,  unsigned int a2,  unsigned int a3,  int *a4,  int *a5,  int *a6,  int *a7)
bool  CGfxManager::GetImageInfo(unsigned int a2, unsigned int a3, int & a4, int & a5, int & a6, int & a7) {
  
  unsigned int v8; // [esp+18h] [ebp-20h]
  unsigned int i; // [esp+1Ch] [ebp-1Ch]
  unsigned int k; // [esp+24h] [ebp-14h]
  unsigned int v11; // [esp+28h] [ebp-10h]
  unsigned int v12; // [esp+2Ch] [ebp-Ch]
  unsigned int m; // [esp+30h] [ebp-8h]
  unsigned int j; // [esp+30h] [ebp-8h]

  *a5 = -1;
  if ( a2 == *((_DWORD *)this + 807) )
  {
    *a4 = a3;
    return 1;
  }
  else
  {
    *a4 = -1;
    if ( a2 < 0xA || a2 >= 0x14 )
    {
      v8 = 0;
LABEL_30:
      if ( v8 >= *((_DWORD *)this + 2 * a2 + 380) )
      {
        if ( *a5 == -1 )
        {
          *a5 = *((_DWORD *)this + 2 * a2 + 380) - 1;
          *a6 = *((_DWORD *)this + 2 * a2 + 296) - 1;
          *a7 = CGfxManager::GetJobFrameCount(a2, *a5, *a6) - 1;
        }
        if ( CGfxManager::HasSil(this, a2) )
          *a4 = *((_DWORD *)this + 2 * a2 + 464) - 1;
        else
          *a4 = -1;
        return 1;
      }
      else
      {
        for ( i = 0; ; ++i )
        {
          if ( i >= CGfxManager::GetNrDirection(this, a2) - 1 )
          {
            ++v8;
            goto LABEL_30;
          }
          v12 = (*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2 * a2 + 379) + 4 * v8 + 20) + 4 * i)
               - (*((_DWORD *)this + 2 * a2 + 211)
                + 20))
              / 4;
          if ( v12 >= a3 )
            break;
        }
        *a6 = i;
        *a5 = v8;
        if ( v12 != a3 )
        {
          if ( *a6 )
            --*a6;
          else
            --*a5;
        }
        *a7 = a3
            - (*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2 * a2 + 379) + 4 * *a5 + 20) + 4 * *a6)
             - (*((_DWORD *)this + 2 * a2 + 211)
              + 20))
            / 4;
        if ( CGfxManager::HasSil(this, a2) )
        {
          for ( j = 0; j < *((_DWORD *)this + 2 * a2 + 464); ++j )
          {
            if ( (unsigned int)(*(_DWORD *)(*((_DWORD *)this + 2 * a2 + 463) + 4 * j + 20) - 20) >> 2 > *a5 )
            {
              *a4 = j - 1;
              break;
            }
          }
          if ( *a4 == -1 )
            *a4 = j - 1;
        }
        else
        {
          *a4 = -1;
        }
        return 1;
      }
    }
    else
    {
      for ( k = 0; ; ++k )
      {
        if ( k >= *((_DWORD *)this + 2 * a2 + 296) )
        {
          if ( *a5 == -1 )
          {
            *a5 = *((_DWORD *)this + 2 * a2 + 296) - 1;
            *a6 = 0;
            *a7 = CGfxManager::GetJobFrameCount(a2, *a5, *a6) - 1;
          }
          if ( CGfxManager::HasSil(this, a2) )
            *a4 = *((_DWORD *)this + 2 * a2 + 380) - 1;
          else
            *a4 = -1;
          return 1;
        }
        v11 = (*(_DWORD *)(*((_DWORD *)this + 2 * a2 + 295) + 4 * k + 20) - (*((_DWORD *)this + 2 * a2 + 211) + 20)) / 4;
        if ( v11 >= a3 )
          break;
      }
      *a5 = k;
      if ( v11 != a3 )
      {
        --*a5;
        while ( *(_DWORD *)(*((_DWORD *)this + 2 * a2 + 295) + 4 * *a5 + 20) == *((_DWORD *)this + 2 * a2 + 211) + 20 )
          --*a5;
      }
      if ( CGfxManager::HasSil(this, a2) )
      {
        for ( m = 0; m < *((_DWORD *)this + 2 * a2 + 380); ++m )
        {
          if ( (*(_DWORD *)(*((_DWORD *)this + 2 * a2 + 379) + 4 * m + 20) - (*((_DWORD *)this + 2 * a2 + 295) + 20))
             / 4 > *a5 )
          {
            *a4 = m - 1;
            break;
          }
        }
        if ( *a4 == -1 )
          *a4 = m - 1;
      }
      else
      {
        *a4 = -1;
      }
      *a7 = 0;
      *a7 = (*(_DWORD *)(*((_DWORD *)this + 2 * a2 + 295) + 4 * *a5 + 20) - (*((_DWORD *)this + 2 * a2 + 211) + 20)) / 4
          - a3;
      *a6 = 0;
      return 1;
    }
  }
}


// address=[0x1364940]
// Decompiled from char __thiscall CGfxManager::GetImageInfo_0(  CGfxManager *this,  unsigned int a2,  unsigned int a3,  int *a4,  int *a5,  int *a6)
bool  CGfxManager::GetImageInfo(unsigned int a2, unsigned int a3, int & a4, int & a5, int & a6) {
  
  int v7; // [esp+4h] [ebp-4h] BYREF

  v7 = 0;
  return CGfxManager::GetImageInfo(this, a2, a3, &v7, a4, a5, a6);
}


// address=[0x1364980]
// Decompiled from char __thiscall CGfxManager::GetJobIndices(  CGfxManager *this,  unsigned int a2,  unsigned int a3,  unsigned int *a4,  int *a5)
bool  CGfxManager::GetJobIndices(unsigned int a2, unsigned int a3, int & a4, int & a5) {
  
  int i; // [esp+0h] [ebp-Ch]
  int j; // [esp+4h] [ebp-8h]

  if ( !byte_3687DFC[a2] && BBSupportDbgReport(2, "GfxManager.cpp", 2271, "g_bSilPerFile[ _iGfxFile ]") == 1 )
    __debugbreak();
  if ( a2 < 0xA || a2 >= 0x14 )
  {
    *a4 = (unsigned int)(*(_DWORD *)(*((_DWORD *)this + 2 * a2 + 463) + 4 * a3 + 20) - 20) >> 2;
    if ( a3 == *((_DWORD *)this + 2 * a2 + 464) - 1 )
      *a5 = *((_DWORD *)this + 2 * a2 + 380);
    else
      *a5 = ((unsigned int)(*(_DWORD *)(*((_DWORD *)this + 2 * a2 + 463) + 4 * a3 + 24) - 20) >> 2) - 1;
    for ( i = *a4; i <= *a5; ++i )
    {
      if ( *(_DWORD *)(*((_DWORD *)this + 2 * a2 + 379) + 20) != *(_DWORD *)(*((_DWORD *)this + 2 * a2 + 379)
                                                                           + 4 * i
                                                                           + 20) )
        return 1;
    }
  }
  else
  {
    *a4 = *(_DWORD *)(*((_DWORD *)this + 2 * a2 + 379) + 4 * a3 + 20);
    *a4 -= *((_DWORD *)this + 2 * a2 + 295) + 20;
    *a4 = (int)*a4 / 4;
    if ( a3 == *((_DWORD *)this + 2 * a2 + 380) - 1 )
    {
      *a5 = *((_DWORD *)this + 2 * a2 + 296);
    }
    else
    {
      *a5 = *(_DWORD *)(*((_DWORD *)this + 2 * a2 + 379) + 4 * a3 + 24);
      *a5 -= *((_DWORD *)this + 2 * a2 + 295) + 20;
      *a5 /= 4;
      --*a5;
    }
    for ( j = *a4; j <= *a5; ++j )
    {
      if ( *(_DWORD *)(*((_DWORD *)this + 2 * a2 + 295) + 20) != *(_DWORD *)(*((_DWORD *)this + 2 * a2 + 295)
                                                                           + 4 * j
                                                                           + 20) )
        return 1;
    }
  }
  return 0;
}


// address=[0x1364ba0]
// Decompiled from bool __thiscall CGfxManager::DisableGfxFile(CGfxManager *this, int a2)
void  CGfxManager::DisableGfxFile(int a2) {
  
  return CGfxManager::RemoveAllGFX(this, a2);
}


// address=[0x1364bc0]
// Decompiled from CGfxManager *__thiscall CGfxManager::EnableMCD2Textures(CGfxManager *this, bool a2)
void  CGfxManager::EnableMCD2Textures(bool a2) {
  
  CGfxManager *result; // eax

  result = this;
  *((_BYTE *)this + 3262) = a2;
  return result;
}


// address=[0x136a1e0]
// Decompiled from int __thiscall CGfxManager::GetNrDirection(CGfxManager *this, unsigned int a2)
unsigned int  CGfxManager::GetNrDirection(unsigned int a2) {
  
  return dword_3687E28[a2];
}


// address=[0x136a200]
// Decompiled from char __thiscall CGfxManager::HasSil(CGfxManager *this, unsigned int a2)
bool  CGfxManager::HasSil(unsigned int a2) {
  
  return byte_3687DFC[a2];
}


// address=[0x13d8be0]
// Decompiled from bool __thiscall CGfxManager::IsGfxFileEnabled(CGfxManager *this, int a2)
bool  CGfxManager::IsGfxFileEnabled(int a2) {
  
  return *((_DWORD *)this + 4 * a2 + 547) != 0;
}


// address=[0x1364be0]
// Decompiled from char __thiscall CGfxManager::RemoveAllGFX(CGfxManager *this, int a2)
bool  CGfxManager::RemoveAllGFX(int a2) {
  
  int v3; // [esp+30h] [ebp-20h]
  int v4; // [esp+34h] [ebp-1Ch]
  int v5; // [esp+38h] [ebp-18h]
  int v6; // [esp+3Ch] [ebp-14h]
  int i; // [esp+4Ch] [ebp-4h]

  if ( a2 == -1 )
  {
    v4 = 0;
  }
  else
  {
    BBSupportTracePrintF(2, "GfxManager.cpp: Disabling GfxFile %d", a2);
    v4 = a2;
  }
  if ( a2 == -1 )
    v3 = 42;
  else
    v3 = a2 + 1;
  for ( i = v4; i < v3; ++i )
  {
    if ( *((_DWORD *)this + 4 * i + 547) )
    {
      if ( *((_BYTE *)this + 16 * i + 2192) == 1 )
      {
        (*(void (__thiscall **)(int, const char *, int))(*(_DWORD *)(*((_DWORD *)this + 4 * i + 549)
                                                                   + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this
                                                                                             + 4 * i
                                                                                             + 549)
                                                                                           + 72)
                                                                               + 4)
                                                                   + 72)
                                                       + 32))(
          *((_DWORD *)this + 4 * i + 549) + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4 * i + 549) + 72) + 4) + 72,
          "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\FileEx.h",
          146);
        v6 = *((_DWORD *)this + 4 * i + 549);
        if ( v6 )
          (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 24))(v6, 1);
      }
      else
      {
        operator delete[](*((void **)this + 4 * i + 547));
      }
      *((_BYTE *)this + 16 * i + 2192) = 0;
      *((_DWORD *)this + 4 * i + 549) = 0;
      *((_DWORD *)this + 4 * i + 547) = 0;
    }
    if ( *((_DWORD *)this + 4 * i + 1) )
    {
      (*(void (__thiscall **)(int, const char *, int))(*(_DWORD *)(*((_DWORD *)this + 4 * i + 3)
                                                                 + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4 * i + 3)
                                                                                         + 72)
                                                                             + 4)
                                                                 + 72)
                                                     + 32))(
        *((_DWORD *)this + 4 * i + 3) + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4 * i + 3) + 72) + 4) + 72,
        "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\FileEx.h",
        146);
      v5 = *((_DWORD *)this + 4 * i + 3);
      if ( v5 )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 24))(v5, 1);
      *((_BYTE *)this + 16 * i + 8) = 0;
      *((_DWORD *)this + 4 * i + 3) = 0;
      *((_DWORD *)this + 4 * i + 1) = 0;
    }
    if ( *((_DWORD *)this + i + 169) )
    {
      operator delete[](*((void **)this + i + 169));
      *((_DWORD *)this + i + 169) = 0;
    }
    if ( *((_DWORD *)this + 2 * i + 211) )
    {
      operator delete[](*((void **)this + 2 * i + 211));
      *((_DWORD *)this + 2 * i + 211) = 0;
    }
    if ( *((_DWORD *)this + 2 * i + 295) )
    {
      operator delete[](*((void **)this + 2 * i + 295));
      *((_DWORD *)this + 2 * i + 295) = 0;
    }
    if ( *((_DWORD *)this + 2 * i + 379) )
    {
      operator delete[](*((void **)this + 2 * i + 379));
      *((_DWORD *)this + 2 * i + 379) = 0;
    }
    if ( *((_DWORD *)this + 2 * i + 463) )
    {
      operator delete[](*((void **)this + 2 * i + 463));
      *((_DWORD *)this + 2 * i + 463) = 0;
    }
  }
  if ( a2 != -1 && a2 == *((_DWORD *)this + 807) )
    *((_DWORD *)this + 807) = -1;
  return 1;
}


// address=[0x1364f80]
// Decompiled from void __stdcall CGfxManager::ErrorMessageBox(char a1, int a2, int a3, int a4, int a5, int a6, int a7)
void  CGfxManager::ErrorMessageBox(class String a1) {
  
  HWND ActiveWindow; // eax
  const CHAR *v8; // [esp-Ch] [ebp-20h]

  v8 = (const CHAR *)String::c_str((String *)&a1);
  ActiveWindow = GetActiveWindow();
  MessageBoxA(ActiveWindow, v8, "Error!", 0x30u);
  String::~String((String *)&a1);
}


// address=[0x1364ff0]
// Decompiled from int *__thiscall CGfxManager::LoadFile(  char *this,  char a2,  int a3,  int a4,  int a5,  int a6,  int a7,  int a8,  size_t *a9,  int a10)
void *  CGfxManager::LoadFile(std::wstring a2, unsigned long * a3, unsigned int a4) {
  
  wchar_t *v10; // eax
  const char *v11; // eax
  const char *v13; // eax
  char *v14; // eax
  _DWORD v15[5]; // [esp-1Ch] [ebp-154h] BYREF
  int v16; // [esp-8h] [ebp-140h]
  int v17; // [esp-4h] [ebp-13Ch]
  _DWORD v18[7]; // [esp+0h] [ebp-138h] BYREF
  int *v21; // [esp+28h] [ebp-110h] MAPDST
  int v22; // [esp+2Ch] [ebp-10Ch]
  signed int v23; // [esp+30h] [ebp-108h]
  size_t Size; // [esp+3Ch] [ebp-FCh]
  char *v27; // [esp+40h] [ebp-F8h]
  char v28[88]; // [esp+44h] [ebp-F4h] BYREF
  _DWORD v29[26]; // [esp+9Ch] [ebp-9Ch] BYREF
  int v30; // [esp+104h] [ebp-34h] BYREF
  _BYTE v31[28]; // [esp+108h] [ebp-30h] BYREF
  _DWORD *v32; // [esp+128h] [ebp-10h]
  int v33; // [esp+134h] [ebp-4h]

  v32 = v18;
  v27 = this;
  v33 = 1;
  v18[6] = CFileEx::CFileEx((CFileEx *)v29, 1);
  LOBYTE(v33) = 2;
  v10 = (wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)&a2);
  CFileEx::Open(&v30, v10, 6, 0, UNUSED_ARG(), UNUSED_ARG());
  v23 = CFileEx::Size(v29);
  Size = v23;
  if ( v23 > 0 )
  {
    v21 = (int *)operator new[](Size);
    CFileEx::Read(&v30, v21, 1, Size, "GfxManager.cpp", 1848);
    CFileEx::Close((CFileEx *)&v30, UNUSED_ARG(), UNUSED_ARG());
    if ( a9 )
      *a9 = Size;
    LOBYTE(v33) = 1;
    CFileEx::~CFileEx(v29);
    v33 = 0;
    if ( a10 != -1 && v21[4] != a10 )
    {
      v17 = v21[4];
      v16 = a10;
      v13 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)&a2);
      BBSupportTracePrintF(2, "Version incorrect for file \"%s\"!\nNeeded: %d, Got: %d !", v13, v16, v17);
      if ( !byte_3ECDBF0 )
      {
        String::operator=("Wrong version of file \"");
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v28);
        LOBYTE(v33) = 4;
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
          v31,
          &a2);
        LOBYTE(v33) = 5;
        v14 = (char *)std::string::c_str(v31);
        String::operator+=(v14);
        String::operator+=("\"!");
        v18[5] = v15;
        v18[4] = String::String((String *)v15, (const struct String *)(v27 + 3232), 0, 0xFFFFFFFF);
        CGfxManager::ErrorMessageBox(v27, v15[0], v15[1], v15[2], v15[3], v15[4], v16, v17);
        byte_3ECDBF0 = 1;
        LOBYTE(v33) = 4;
        std::string::~string(v31);
        LOBYTE(v33) = 0;
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v28);
      }
    }
    v33 = -1;
    std::wstring::~wstring(&a2);
    return v21;
  }
  else
  {
    v11 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)&a2);
    BBSupportTracePrintF(2, "CGfxManager::LoadFile : Couldn't get size of : %s", v11);
    v22 = 0;
    LOBYTE(v33) = 1;
    CFileEx::~CFileEx(v29);
    v33 = -1;
    std::wstring::~wstring(&a2);
    return (int *)v22;
  }
}


// address=[0x1365310]
// Decompiled from CFileEx *__thiscall CGfxManager::MapFullFile(  char *this,  char a2,  int a3,  int a4,  int a5,  int a6,  int a7,  int a8,  int a9)
class CFileEx *  CGfxManager::MapFullFile(std::wstring a2, unsigned int a3) {
  
  _DWORD *v9; // eax
  const char *v10; // eax
  char *v11; // eax
  const char *v13; // eax
  char *v14; // eax
  int v15; // [esp-1Ch] [ebp-16Ch] BYREF
  int v16; // [esp-18h] [ebp-168h]
  int v17; // [esp-14h] [ebp-164h]
  int v18; // [esp-10h] [ebp-160h]
  int v19; // [esp-Ch] [ebp-15Ch]
  int v20; // [esp-8h] [ebp-158h]
  DWORD LastError; // [esp-4h] [ebp-154h]
  _DWORD v22[8]; // [esp+0h] [ebp-150h] BYREF
  CFileEx *v23; // [esp+20h] [ebp-130h]
  int v24; // [esp+24h] [ebp-12Ch]
  int v25; // [esp+28h] [ebp-128h]
  CFileEx *v26; // [esp+2Ch] [ebp-124h]
  CFileEx *v27; // [esp+34h] [ebp-11Ch]
  int v28; // [esp+38h] [ebp-118h]
  int v29; // [esp+3Ch] [ebp-114h]
  CFileEx *v30; // [esp+40h] [ebp-110h]
  void *C; // [esp+44h] [ebp-10Ch]
  CFileEx *v32; // [esp+48h] [ebp-108h]
  char *v33; // [esp+4Ch] [ebp-104h]
  CFileEx *v34; // [esp+50h] [ebp-100h]
  char v35[88]; // [esp+54h] [ebp-FCh] BYREF
  char v36[88]; // [esp+ACh] [ebp-A4h] BYREF
  _BYTE v37[28]; // [esp+104h] [ebp-4Ch] BYREF
  _BYTE v38[28]; // [esp+120h] [ebp-30h] BYREF
  _DWORD *v39; // [esp+140h] [ebp-10h]
  int v40; // [esp+14Ch] [ebp-4h]

  v39 = v22;
  v33 = this;
  v40 = 0;
  C = operator new(0x6Cu);
  LOBYTE(v40) = 1;
  if ( C )
    v30 = CFileEx::CFileEx((CFileEx *)C, 1);
  else
    v30 = 0;
  v27 = v30;
  v34 = v30;
  LOBYTE(v40) = 2;
  v9 = std::wstring::c_str((_Cnd_internal_imp_t *)&a2);
  (**(void (__thiscall ***)(int, _DWORD *, int, int, const char *, int))((char *)v34
                                                                       + *(_DWORD *)(*((_DWORD *)v34 + 18) + 4)
                                                                       + 72))(
    (int)v34 + *(_DWORD *)(*((_DWORD *)v34 + 18) + 4) + 72,
    v9,
    6,
    1,
    "GfxManager.cpp",
    1911);
  v40 = 0;
  v29 = (*(int (__thiscall **)(int))(*(_DWORD *)((char *)v34 + *(_DWORD *)(*((_DWORD *)v34 + 18) + 4) + 72) + 12))((int)v34 + *(_DWORD *)(*((_DWORD *)v34 + 18) + 4) + 72);
  if ( v29 )
  {
    if ( a9 != -1 )
    {
      v28 = v29;
      if ( *(_DWORD *)(v29 + 16) != a9 )
      {
        LastError = *(_DWORD *)(v28 + 16);
        v20 = a9;
        v13 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)&a2);
        BBSupportTracePrintF(2, "Version incorrect for file \"%s\"!\nNeeded: %d, Got: %d !", v13, v20, LastError);
        if ( !byte_3ECDBF0 )
        {
          String::operator=("Wrong version of file \"");
          std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v35);
          LOBYTE(v40) = 6;
          std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
            v37,
            &a2);
          LOBYTE(v40) = 7;
          v14 = (char *)std::string::c_str(v37);
          String::operator+=(v33 + 3232, v14);
          String::operator+=(v33 + 3232, "\"!");
          v22[5] = &v15;
          v22[4] = String::String((String *)&v15, (const struct String *)(v33 + 3232), 0, 0xFFFFFFFF);
          CGfxManager::ErrorMessageBox(v33, v15, v16, v17, v18, v19, v20, LastError);
          byte_3ECDBF0 = 1;
          LOBYTE(v40) = 6;
          std::string::~string(v37);
          LOBYTE(v40) = 0;
          std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v35);
        }
      }
    }
    v23 = v34;
    v40 = -1;
    std::wstring::~wstring(&a2);
    return v23;
  }
  else
  {
    LastError = GetLastError();
    v10 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)&a2);
    BBSupportTracePrintF(2, "Unable map view of file %s. LastError was: %d", v10, LastError);
    (*(void (__thiscall **)(int, const char *, int))(*(_DWORD *)((char *)v34
                                                               + *(_DWORD *)(*((_DWORD *)v34 + 18) + 4)
                                                               + 72)
                                                   + 32))(
      (int)v34 + *(_DWORD *)(*((_DWORD *)v34 + 18) + 4) + 72,
      "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\FileEx.h",
      146);
    v26 = v34;
    v32 = v34;
    if ( v34 )
      v25 = (*(int (__thiscall **)(CFileEx *, int))(*(_DWORD *)v32 + 24))(v32, 1);
    else
      v25 = 0;
    String::operator=("Unable to open file \"");
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v36);
    LOBYTE(v40) = 4;
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
      v38,
      &a2);
    LOBYTE(v40) = 5;
    v11 = (char *)std::string::c_str(v38);
    String::operator+=(v33 + 3232, v11);
    String::operator+=(v33 + 3232, "\"!");
    v22[7] = &v15;
    v22[6] = String::String((String *)&v15, (const struct String *)(v33 + 3232), 0, 0xFFFFFFFF);
    CGfxManager::ErrorMessageBox(v33, v15, v16, v17, v18, v19, v20, LastError);
    v24 = 0;
    LOBYTE(v40) = 4;
    std::string::~string(v38);
    LOBYTE(v40) = 0;
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v36);
    v40 = -1;
    std::wstring::~wstring(&a2);
    return (CFileEx *)v24;
  }
}


// address=[0x1365750]
// Decompiled from char __thiscall CGfxManager::LoadGfxFile(CGfxManager *this, unsigned int a2, bool a3, unsigned int a4)
bool  CGfxManager::LoadGfxFile(unsigned int a2, bool a3, unsigned int a4) {
  
  char v4; // al
  char v5; // al
  char v6; // al
  char v7; // al
  char v8; // al
  int v9; // eax
  int v11; // eax
  char v12; // [esp-24h] [ebp-280h] BYREF
  int v13; // [esp-20h] [ebp-27Ch] BYREF
  int v14; // [esp-1Ch] [ebp-278h]
  int v15; // [esp-18h] [ebp-274h]
  int v16; // [esp-14h] [ebp-270h]
  int v17; // [esp-10h] [ebp-26Ch]
  int v18; // [esp-Ch] [ebp-268h]
  int v19; // [esp-8h] [ebp-264h]
  unsigned int v20; // [esp-4h] [ebp-260h]
  int v21; // [esp+4h] [ebp-258h]
  char *v22; // [esp+8h] [ebp-254h]
  int v23; // [esp+Ch] [ebp-250h]
  int *v24; // [esp+10h] [ebp-24Ch]
  int File; // [esp+14h] [ebp-248h]
  _DWORD *v26; // [esp+18h] [ebp-244h]
  char v27; // [esp+1Eh] [ebp-23Eh]
  char v28; // [esp+1Fh] [ebp-23Dh]
  _DWORD *v29; // [esp+20h] [ebp-23Ch]
  char v31[28]; // [esp+28h] [ebp-234h] BYREF
  wchar_t Buffer[260]; // [esp+44h] [ebp-218h] BYREF
  int v33; // [esp+258h] [ebp-4h]

  if ( a2 == 2 || a2 == 41 )
  {
    if ( *((_BYTE *)this + 0xC99) )
    {
      if ( *((_BYTE *)this + 0xC98) )
      {
        v20 = a2;
        v4 = (unsigned __int8)std::wstring::c_str((CGfxManager *)((char *)this + 0xC7C));
        swprintf((char *)Buffer, (char *)L"%s\\%d.gh6", v4);
      }
      else
      {
        v20 = a2;
        v5 = (unsigned __int8)std::wstring::c_str((CGfxManager *)((char *)this + 0xC7C));
        swprintf((char *)Buffer, (char *)L"%s\\%d.gh5", v5);
      }
    }
    else if ( *((_BYTE *)this + 0xC98) )
    {
      v20 = a2;
      v6 = (unsigned __int8)std::wstring::c_str((CGfxManager *)((char *)this + 3196));
      swprintf((char *)Buffer, (char *)L"%s\\%d.gl6", v6);
    }
    else
    {
      v20 = a2;
      v7 = (unsigned __int8)std::wstring::c_str((CGfxManager *)((char *)this + 3196));
      swprintf((char *)Buffer, (char *)L"%s\\%d.gl5", v7);
    }
  }
  else
  {
    v20 = a2;
    v8 = (unsigned __int8)std::wstring::c_str((CGfxManager *)((char *)this + 3196));
    swprintf((char *)Buffer, (char *)L"%s\\%d.gfx", v8);
  }
  std::wstring::wstring(v31, Buffer);
  v33 = 0;
  v29 = 0;
  if ( a3 )
  {
    v20 = a4;
    v24 = &v13;
    v23 = std::wstring::wstring((int)v31);
    v26 = (_DWORD *)CGfxManager::MapFullFile(v13, v14, v15, v16, v17, v18, v19, v20);
    v29 = v26;
    if ( v26 )
    {
      v9 = (*(int (__thiscall **)(int))(*(_DWORD *)((char *)v29 + *(_DWORD *)(v29[18] + 4) + 72) + 12))((int)v29 + *(_DWORD *)(v29[18] + 4) + 72);
      *((_DWORD *)this + 4 * a2 + 547) = v9;
    }
  }
  else
  {
    v20 = a4;
    v19 = 0;
    v22 = &v12;
    v21 = std::wstring::wstring((int)v31);
    File = CGfxManager::LoadFile(v12, v13, v14, v15, v16, v17, v18, v19, v20);
    *((_DWORD *)this + 4 * a2 + 547) = File;
  }
  if ( *((_DWORD *)this + 4 * a2 + 547) )
  {
    *((_BYTE *)this + 16 * a2 + 2192) = a3;
    *((_DWORD *)this + 4 * a2 + 549) = v29;
    v11 = (*(int (__thiscall **)(_DWORD *))(*v29 + 16))(v29);
    *((_DWORD *)this + 4 * a2 + 550) = v11;
    v27 = 1;
    v33 = -1;
    std::wstring::~wstring(v31);
    return v27;
  }
  else
  {
    v28 = 0;
    v33 = -1;
    std::wstring::~wstring(v31);
    return v28;
  }
}


// address=[0x1365a70]
// Decompiled from char __thiscall CGfxManager::LoadGfxColorFile(CGfxManager *this, int a2, char a3, int a4)
bool  CGfxManager::LoadGfxColorFile(unsigned int a2, bool a3, unsigned int a4) {
  
  char v4; // al
  char v5; // al
  int v6; // eax
  int v8; // eax
  char v9; // [esp-24h] [ebp-280h] BYREF
  int v10; // [esp-20h] [ebp-27Ch] BYREF
  int v11; // [esp-1Ch] [ebp-278h]
  int v12; // [esp-18h] [ebp-274h]
  int v13; // [esp-14h] [ebp-270h]
  int v14; // [esp-10h] [ebp-26Ch]
  int v15; // [esp-Ch] [ebp-268h]
  int v16; // [esp-8h] [ebp-264h]
  int v17; // [esp-4h] [ebp-260h]
  int v18; // [esp+4h] [ebp-258h]
  char *v19; // [esp+8h] [ebp-254h]
  int v20; // [esp+Ch] [ebp-250h]
  int *v21; // [esp+10h] [ebp-24Ch]
  int File; // [esp+14h] [ebp-248h]
  CFileEx *v23; // [esp+18h] [ebp-244h]
  char v24; // [esp+1Eh] [ebp-23Eh]
  char v25; // [esp+1Fh] [ebp-23Dh]
  CFileEx *v26; // [esp+20h] [ebp-23Ch]
  char *v27; // [esp+24h] [ebp-238h]
  char v28[28]; // [esp+28h] [ebp-234h] BYREF
  wchar_t Buffer[260]; // [esp+44h] [ebp-218h] BYREF
  int v30; // [esp+258h] [ebp-4h]

  v27 = (char *)this;
  if ( *((_BYTE *)this + 3224) )
  {
    v17 = a2;
    v4 = (unsigned __int8)std::wstring::c_str((_Cnd_internal_imp_t *)(v27 + 3196));
    swprintf((char *)Buffer, (char *)L"%s\\%d.gf6", v4);
  }
  else
  {
    v17 = a2;
    v5 = (unsigned __int8)std::wstring::c_str((_Cnd_internal_imp_t *)(v27 + 3196));
    swprintf((char *)Buffer, (char *)L"%s\\%d.gf5", v5);
  }
  std::wstring::wstring(v28, Buffer);
  v30 = 0;
  v26 = 0;
  if ( a3 == 1 )
  {
    v17 = a4;
    v21 = &v10;
    v20 = std::wstring::wstring((int)v28);
    v23 = CGfxManager::MapFullFile(v27, v10, v11, v12, v13, v14, v15, v16, v17);
    v26 = v23;
    if ( v23 )
    {
      v6 = (*(int (__thiscall **)(int))(*(_DWORD *)((char *)v26 + *(_DWORD *)(*((_DWORD *)v26 + 18) + 4) + 72) + 12))((int)v26 + *(_DWORD *)(*((_DWORD *)v26 + 18) + 4) + 72);
      *(_DWORD *)&v27[16 * a2 + 2188] = v6;
    }
  }
  else
  {
    v17 = a4;
    v16 = 0;
    v19 = &v9;
    v18 = std::wstring::wstring((int)v28);
    File = CGfxManager::LoadFile(v9, v10, v11, v12, v13, v14, v15, v16, v17);
    *(_DWORD *)&v27[16 * a2 + 2188] = File;
  }
  if ( *(_DWORD *)&v27[16 * a2 + 2188] )
  {
    v27[16 * a2 + 2192] = a3;
    *(_DWORD *)&v27[16 * a2 + 2196] = v26;
    v8 = (*(int (__thiscall **)(CFileEx *))(*(_DWORD *)v26 + 16))(v26);
    *(_DWORD *)&v27[16 * a2 + 2200] = v8;
    v24 = 1;
    v30 = -1;
    std::wstring::~wstring(v28);
    return v24;
  }
  else
  {
    v25 = 0;
    v30 = -1;
    std::wstring::~wstring(v28);
    return v25;
  }
}


// address=[0x1365ce0]
// Decompiled from char __thiscall CGfxManager::LoadGilFile(CGfxManager *this, unsigned int a2, int a3)
bool  CGfxManager::LoadGilFile(unsigned int a2, unsigned int a3) {
  
  char v3; // al
  char v5; // [esp-24h] [ebp-288h] BYREF
  int v6; // [esp-20h] [ebp-284h]
  int v7; // [esp-1Ch] [ebp-280h]
  int v8; // [esp-18h] [ebp-27Ch]
  int v9; // [esp-14h] [ebp-278h]
  int v10; // [esp-10h] [ebp-274h]
  int v11; // [esp-Ch] [ebp-270h]
  int *v12; // [esp-8h] [ebp-26Ch]
  int v13; // [esp-4h] [ebp-268h]
  int v14; // [esp+4h] [ebp-260h]
  char *v15; // [esp+8h] [ebp-25Ch]
  int v16; // [esp+Ch] [ebp-258h]
  int v17; // [esp+10h] [ebp-254h] BYREF
  int File; // [esp+14h] [ebp-250h]
  int v19; // [esp+18h] [ebp-24Ch]
  signed int v20; // [esp+1Ch] [ebp-248h]
  int v21; // [esp+20h] [ebp-244h]
  signed int i; // [esp+24h] [ebp-240h]
  char v23; // [esp+2Ah] [ebp-23Ah]
  char v24; // [esp+2Bh] [ebp-239h]
  CGfxManager *v25; // [esp+2Ch] [ebp-238h]
  char v26[28]; // [esp+30h] [ebp-234h] BYREF
  wchar_t Buffer[260]; // [esp+4Ch] [ebp-218h] BYREF
  int v28; // [esp+260h] [ebp-4h]

  v25 = this;
  v3 = (unsigned __int8)std::wstring::c_str((CGfxManager *)((char *)this + 3196));
  swprintf((char *)Buffer, (char *)L"%s\\%d.gil", v3);
  std::wstring::wstring(v26, Buffer);
  v28 = 0;
  v13 = a3;
  v12 = &v17;
  v15 = &v5;
  v14 = std::wstring::wstring((int)v26);
  File = CGfxManager::LoadFile(v5, v6, v7, v8, v9, v10, v11, (int)v12, v13);
  *((_DWORD *)v25 + 2 * a2 + 211) = File;
  if ( *((_DWORD *)v25 + 2 * a2 + 211) )
  {
    if ( !*((_DWORD *)v25 + 4 * a2 + 547)
      && BBSupportDbgReport(2, "GfxManager.cpp", 531, "m_sFileGfx[ nGfxFile ].pFileGfx") == 1 )
    {
      __debugbreak();
    }
    v16 = *((_DWORD *)v25 + 4 * a2 + 547);
    v20 = (unsigned int)(v17 - 20) >> 2;
    *((_DWORD *)v25 + 2 * a2 + 212) = v20;
    for ( i = 0; i < v20; ++i )
    {
      v21 = *(_DWORD *)(*((_DWORD *)v25 + 2 * a2 + 211) + 4 * i + 20);
      if ( v21 )
        v19 = v21;
      else
        v19 = 20;
      v21 = v19;
      *(_DWORD *)(*((_DWORD *)v25 + 2 * a2 + 211) + 4 * i + 20) = v19 + v16;
    }
    v23 = 1;
    v28 = -1;
    std::wstring::~wstring(v26);
    return v23;
  }
  else
  {
    v24 = 0;
    v28 = -1;
    std::wstring::~wstring(v26);
    return v24;
  }
}


// address=[0x1365f30]
// Decompiled from char __thiscall CGfxManager::LoadDilFile(CGfxManager *this, unsigned int a2, int a3)
bool  CGfxManager::LoadDilFile(unsigned int a2, unsigned int a3) {
  
  char v3; // al
  char v5; // [esp-24h] [ebp-288h] BYREF
  int v6; // [esp-20h] [ebp-284h]
  int v7; // [esp-1Ch] [ebp-280h]
  int v8; // [esp-18h] [ebp-27Ch]
  int v9; // [esp-14h] [ebp-278h]
  int v10; // [esp-10h] [ebp-274h]
  int v11; // [esp-Ch] [ebp-270h]
  int *v12; // [esp-8h] [ebp-26Ch]
  int v13; // [esp-4h] [ebp-268h]
  int v14; // [esp+4h] [ebp-260h]
  char *v15; // [esp+8h] [ebp-25Ch]
  int v16; // [esp+Ch] [ebp-258h]
  int v17; // [esp+10h] [ebp-254h] BYREF
  int File; // [esp+14h] [ebp-250h]
  int v19; // [esp+18h] [ebp-24Ch]
  signed int v20; // [esp+1Ch] [ebp-248h]
  int v21; // [esp+20h] [ebp-244h]
  signed int i; // [esp+24h] [ebp-240h]
  char v23; // [esp+2Ah] [ebp-23Ah]
  char v24; // [esp+2Bh] [ebp-239h]
  CGfxManager *v25; // [esp+2Ch] [ebp-238h]
  char v26[28]; // [esp+30h] [ebp-234h] BYREF
  wchar_t Buffer[260]; // [esp+4Ch] [ebp-218h] BYREF
  int v28; // [esp+260h] [ebp-4h]

  v25 = this;
  v3 = (unsigned __int8)std::wstring::c_str((CGfxManager *)((char *)this + 3196));
  swprintf((char *)Buffer, (char *)L"%s\\%d.dil", v3);
  std::wstring::wstring(v26, Buffer);
  v28 = 0;
  v13 = a3;
  v12 = &v17;
  v15 = &v5;
  v14 = std::wstring::wstring((int)v26);
  File = CGfxManager::LoadFile(v5, v6, v7, v8, v9, v10, v11, (int)v12, v13);
  *((_DWORD *)v25 + 2 * a2 + 295) = File;
  if ( *((_DWORD *)v25 + 2 * a2 + 295) )
  {
    if ( !*((_DWORD *)v25 + 2 * a2 + 211)
      && BBSupportDbgReport(2, "GfxManager.cpp", 573, "m_pFileGfxFrames[ nGfxFile ].pItem") == 1 )
    {
      __debugbreak();
    }
    v16 = *((_DWORD *)v25 + 2 * a2 + 211);
    v20 = (unsigned int)(v17 - 20) >> 2;
    *((_DWORD *)v25 + 2 * a2 + 296) = v20;
    for ( i = 0; i < v20; ++i )
    {
      v21 = *(_DWORD *)(*((_DWORD *)v25 + 2 * a2 + 295) + 4 * i + 20);
      if ( v21 )
        v19 = v21;
      else
        v19 = 20;
      v21 = v19;
      *(_DWORD *)(*((_DWORD *)v25 + 2 * a2 + 295) + 4 * i + 20) = v19 + v16;
    }
    v23 = 1;
    v28 = -1;
    std::wstring::~wstring(v26);
    return v23;
  }
  else
  {
    v24 = 0;
    v28 = -1;
    std::wstring::~wstring(v26);
    return v24;
  }
}


// address=[0x1366180]
// Decompiled from char __thiscall CGfxManager::LoadJilFile(CGfxManager *this, unsigned int a2, int a3)
bool  CGfxManager::LoadJilFile(unsigned int a2, unsigned int a3) {
  
  char v3; // al
  char v5; // [esp-24h] [ebp-288h] BYREF
  int v6; // [esp-20h] [ebp-284h]
  int v7; // [esp-1Ch] [ebp-280h]
  int v8; // [esp-18h] [ebp-27Ch]
  int v9; // [esp-14h] [ebp-278h]
  int v10; // [esp-10h] [ebp-274h]
  int v11; // [esp-Ch] [ebp-270h]
  int *v12; // [esp-8h] [ebp-26Ch]
  int v13; // [esp-4h] [ebp-268h]
  int v14; // [esp+4h] [ebp-260h]
  char *v15; // [esp+8h] [ebp-25Ch]
  int v16; // [esp+Ch] [ebp-258h]
  int v17; // [esp+10h] [ebp-254h] BYREF
  int File; // [esp+14h] [ebp-250h]
  int v19; // [esp+18h] [ebp-24Ch]
  signed int v20; // [esp+1Ch] [ebp-248h]
  int v21; // [esp+20h] [ebp-244h]
  signed int i; // [esp+24h] [ebp-240h]
  char v23; // [esp+2Ah] [ebp-23Ah]
  char v24; // [esp+2Bh] [ebp-239h]
  CGfxManager *v25; // [esp+2Ch] [ebp-238h]
  char v26[28]; // [esp+30h] [ebp-234h] BYREF
  wchar_t Buffer[260]; // [esp+4Ch] [ebp-218h] BYREF
  int v28; // [esp+260h] [ebp-4h]

  v25 = this;
  v3 = (unsigned __int8)std::wstring::c_str((CGfxManager *)((char *)this + 3196));
  swprintf((char *)Buffer, (char *)L"%s\\%d.jil", v3);
  std::wstring::wstring(v26, Buffer);
  v28 = 0;
  v13 = a3;
  v12 = &v17;
  v15 = &v5;
  v14 = std::wstring::wstring((int)v26);
  File = CGfxManager::LoadFile(v5, v6, v7, v8, v9, v10, v11, (int)v12, v13);
  *((_DWORD *)v25 + 2 * a2 + 379) = File;
  if ( *((_DWORD *)v25 + 2 * a2 + 379) )
  {
    if ( !*((_DWORD *)v25 + 2 * a2 + 295)
      && BBSupportDbgReport(2, "GfxManager.cpp", 612, "m_pFileGfxDirections[ nGfxFile ].pItem") == 1 )
    {
      __debugbreak();
    }
    v16 = *((_DWORD *)v25 + 2 * a2 + 295);
    v20 = (unsigned int)(v17 - 20) >> 2;
    *((_DWORD *)v25 + 2 * a2 + 380) = v20;
    for ( i = 0; i < v20; ++i )
    {
      v21 = *(_DWORD *)(*((_DWORD *)v25 + 2 * a2 + 379) + 4 * i + 20);
      if ( v21 )
        v19 = v21;
      else
        v19 = 20;
      v21 = v19;
      *(_DWORD *)(*((_DWORD *)v25 + 2 * a2 + 379) + 4 * i + 20) = v19 + v16;
    }
    v23 = 1;
    v28 = -1;
    std::wstring::~wstring(v26);
    return v23;
  }
  else
  {
    v24 = 0;
    v28 = -1;
    std::wstring::~wstring(v26);
    return v24;
  }
}


// address=[0x13663d0]
// Decompiled from char __thiscall CGfxManager::LoadSilFile(CGfxManager *this, unsigned int a2, int a3)
bool  CGfxManager::LoadSilFile(unsigned int a2, unsigned int a3) {
  
  char v3; // al
  char v5; // [esp-24h] [ebp-274h] BYREF
  int v6; // [esp-20h] [ebp-270h]
  int v7; // [esp-1Ch] [ebp-26Ch]
  int v8; // [esp-18h] [ebp-268h]
  int v9; // [esp-14h] [ebp-264h]
  int v10; // [esp-10h] [ebp-260h]
  int v11; // [esp-Ch] [ebp-25Ch]
  int *v12; // [esp-8h] [ebp-258h]
  int v13; // [esp-4h] [ebp-254h]
  int v14; // [esp+4h] [ebp-24Ch]
  char *v15; // [esp+8h] [ebp-248h]
  int v16; // [esp+Ch] [ebp-244h] BYREF
  int File; // [esp+10h] [ebp-240h]
  CGfxManager *v18; // [esp+14h] [ebp-23Ch]
  char v19; // [esp+1Ah] [ebp-236h]
  char v20; // [esp+1Bh] [ebp-235h]
  char v21[28]; // [esp+1Ch] [ebp-234h] BYREF
  wchar_t Buffer[260]; // [esp+38h] [ebp-218h] BYREF
  int v23; // [esp+24Ch] [ebp-4h]

  v18 = this;
  v3 = (unsigned __int8)std::wstring::c_str((CGfxManager *)((char *)this + 3196));
  swprintf((char *)Buffer, (char *)L"%s\\%d.sil", v3);
  std::wstring::wstring(v21, Buffer);
  v23 = 0;
  v13 = a3;
  v12 = &v16;
  v15 = &v5;
  v14 = std::wstring::wstring((int)v21);
  File = CGfxManager::LoadFile(v5, v6, v7, v8, v9, v10, v11, (int)v12, v13);
  *((_DWORD *)v18 + 2 * a2 + 463) = File;
  if ( *((_DWORD *)v18 + 2 * a2 + 463) )
  {
    *((_DWORD *)v18 + 2 * a2 + 464) = (unsigned int)(v16 - 20) >> 2;
    v19 = 1;
    v23 = -1;
    std::wstring::~wstring(v21);
    return v19;
  }
  else
  {
    v20 = 0;
    v23 = -1;
    std::wstring::~wstring(v21);
    return v20;
  }
}


// address=[0x1366520]
// Decompiled from char __thiscall CGfxManager::LoadPilFile(CGfxManager *this, int a2, int a3, bool a4)
bool  CGfxManager::LoadPilFile(unsigned int a2, unsigned int a3, bool a4) {
  
  char v4; // al
  char v6; // [esp-24h] [ebp-288h] BYREF
  int v7; // [esp-20h] [ebp-284h]
  int v8; // [esp-1Ch] [ebp-280h]
  int v9; // [esp-18h] [ebp-27Ch]
  int v10; // [esp-14h] [ebp-278h]
  int v11; // [esp-10h] [ebp-274h]
  int v12; // [esp-Ch] [ebp-270h]
  int *v13; // [esp-8h] [ebp-26Ch]
  int v14; // [esp-4h] [ebp-268h]
  int v15; // [esp+4h] [ebp-260h]
  char *v16; // [esp+8h] [ebp-25Ch]
  int v17; // [esp+Ch] [ebp-258h]
  signed int v18; // [esp+10h] [ebp-254h]
  int v19; // [esp+14h] [ebp-250h] BYREF
  int File; // [esp+18h] [ebp-24Ch]
  int v21; // [esp+1Ch] [ebp-248h]
  int v22; // [esp+20h] [ebp-244h]
  signed int i; // [esp+24h] [ebp-240h]
  char v24; // [esp+2Ah] [ebp-23Ah]
  char v25; // [esp+2Bh] [ebp-239h]
  CGfxManager *v26; // [esp+2Ch] [ebp-238h]
  _BYTE v27[28]; // [esp+30h] [ebp-234h] BYREF
  wchar_t Buffer[260]; // [esp+4Ch] [ebp-218h] BYREF
  int v29; // [esp+260h] [ebp-4h]

  v26 = this;
  std::wstring::wstring(v27);
  v29 = 0;
  v14 = a2;
  v4 = (unsigned __int8)std::wstring::c_str((CGfxManager *)((char *)v26 + 3196));
  if ( a4 )
    swprintf((char *)Buffer, (char *)L"%s\\%d.pil", v4);
  else
    swprintf((char *)Buffer, (char *)L"%s\\%d.pi2", v4);
  std::wstring::operator=(v27, Buffer);
  v14 = a3;
  v13 = &v19;
  v16 = &v6;
  v15 = std::wstring::wstring((int)v27);
  File = CGfxManager::LoadFile(v6, v7, v8, v9, v10, v11, v12, (int)v13, v14);
  *((_DWORD *)v26 + a2 + 169) = File;
  if ( *((_DWORD *)v26 + a2 + 169) )
  {
    if ( !*((_DWORD *)v26 + 4 * a2 + 1)
      && BBSupportDbgReport(2, "GfxManager.cpp", 798, "m_sFilePal[ nGfxFile ].pFileGfx") == 1 )
    {
      __debugbreak();
    }
    v17 = *((_DWORD *)v26 + 4 * a2 + 1);
    v18 = (unsigned int)(v19 - 20) >> 2;
    for ( i = 0; i < v18; ++i )
    {
      v22 = *(_DWORD *)(*((_DWORD *)v26 + a2 + 169) + 4 * i + 20);
      if ( v22 )
        v21 = v22;
      else
        v21 = 20;
      v22 = v21;
      *(_DWORD *)(*((_DWORD *)v26 + a2 + 169) + 4 * i + 20) = v21 + v17;
    }
    v24 = 1;
    v29 = -1;
    std::wstring::~wstring(v27);
    return v24;
  }
  else
  {
    v25 = 0;
    v29 = -1;
    std::wstring::~wstring(v27);
    return v25;
  }
}


// address=[0x1366790]
// Decompiled from char __thiscall CGfxManager::LoadPalFile(CGfxManager *this, int a2, int a3, bool a4)
bool  CGfxManager::LoadPalFile(unsigned int a2, unsigned int a3, bool a4) {
  
  char v4; // al
  char v6; // al
  char v7; // al
  int v8; // eax
  int v9; // eax
  char v10; // [esp-20h] [ebp-298h] BYREF
  int v11; // [esp-1Ch] [ebp-294h]
  int v12; // [esp-18h] [ebp-290h]
  int v13; // [esp-14h] [ebp-28Ch]
  int v14; // [esp-10h] [ebp-288h]
  int v15; // [esp-Ch] [ebp-284h]
  int v16; // [esp-8h] [ebp-280h]
  int v17; // [esp-4h] [ebp-27Ch]
  _DWORD v18[8]; // [esp+0h] [ebp-278h] BYREF
  CFileEx *v19; // [esp+20h] [ebp-258h]
  int v20; // [esp+24h] [ebp-254h]
  int v21; // [esp+28h] [ebp-250h]
  CFileEx *v22; // [esp+2Ch] [ebp-24Ch]
  char v23; // [esp+32h] [ebp-246h]
  char v24; // [esp+33h] [ebp-245h]
  CFileEx *v25; // [esp+34h] [ebp-244h]
  CFileEx *v26; // [esp+38h] [ebp-240h]
  char *v27; // [esp+3Ch] [ebp-23Ch]
  char v28[28]; // [esp+40h] [ebp-238h] BYREF
  wchar_t Buffer[260]; // [esp+5Ch] [ebp-21Ch] BYREF
  _DWORD *v30; // [esp+268h] [ebp-10h]
  int v31; // [esp+274h] [ebp-4h]

  v30 = v18;
  v27 = (char *)this;
  std::wstring::wstring(v28);
  v31 = 0;
  if ( (!(unsigned __int8)IGfxEngine::IsGuiMode(g_pGfxEngine, v18[0]) || a2 != 1)
    && IGfxEngine::Use4444Palettes((IGfxEngine *)g_pGfxEngine) )
  {
    v4 = (unsigned __int8)std::wstring::c_str((_Cnd_internal_imp_t *)(v27 + 3196));
    swprintf((char *)Buffer, (char *)L"%s\\%d.p24", v4);
    LOBYTE(v31) = 1;
    std::wstring::operator=(v28, Buffer);
    v26 = 0;
    v17 = a3;
    v18[7] = &v10;
    v18[6] = std::wstring::wstring((int)v28);
    v22 = CGfxManager::MapFullFile(v27, v10, v11, v12, v13, v14, v15, v16, v17);
    v26 = v22;
    if ( v22 )
    {
      v21 = (*(int (__thiscall **)(int))(*(_DWORD *)((char *)v26 + *(_DWORD *)(*((_DWORD *)v26 + 18) + 4) + 72) + 12))((int)v26 + *(_DWORD *)(*((_DWORD *)v26 + 18) + 4) + 72);
      *(_DWORD *)&v27[16 * a2 + 4] = v21;
      *(_DWORD *)&v27[16 * a2 + 12] = v26;
      v20 = (*(int (__thiscall **)(CFileEx *))(*(_DWORD *)v26 + 16))(v26);
      *(_DWORD *)&v27[16 * a2 + 16] = v20;
    }
    v31 = 0;
    if ( *(_DWORD *)&v27[16 * a2 + 4] )
    {
      v24 = 1;
      v31 = -1;
      std::wstring::~wstring(v28);
      return v24;
    }
    BBSupportTracePrintF(2, "WARNING: 4444 RGBA file %s not found!*****************", (const char *)Buffer);
  }
  if ( v27[3224] )
  {
    v17 = a2;
    v6 = (unsigned __int8)std::wstring::c_str((_Cnd_internal_imp_t *)(v27 + 3196));
    if ( a4 )
      swprintf((char *)Buffer, (char *)L"%s\\%d.pa6", v6);
    else
      swprintf((char *)Buffer, (char *)L"%s\\%d.p26", v6);
  }
  else
  {
    v17 = a2;
    v7 = (unsigned __int8)std::wstring::c_str((_Cnd_internal_imp_t *)(v27 + 3196));
    if ( a4 )
      swprintf((char *)Buffer, (char *)L"%s\\%d.pa5", v7);
    else
      swprintf((char *)Buffer, (char *)L"%s\\%d.p25", v7);
  }
  std::wstring::operator=(v28, Buffer);
  v25 = 0;
  v17 = a3;
  v18[5] = &v10;
  v18[4] = std::wstring::wstring((int)v28);
  v19 = CGfxManager::MapFullFile(v27, v10, v11, v12, v13, v14, v15, v16, v17);
  v25 = v19;
  if ( v19 )
  {
    v8 = (*(int (__thiscall **)(int))(*(_DWORD *)((char *)v25 + *(_DWORD *)(*((_DWORD *)v25 + 18) + 4) + 72) + 12))((int)v25 + *(_DWORD *)(*((_DWORD *)v25 + 18) + 4) + 72);
    *(_DWORD *)&v27[16 * a2 + 4] = v8;
    *(_DWORD *)&v27[16 * a2 + 12] = v25;
    v9 = (*(int (__thiscall **)(CFileEx *))(*(_DWORD *)v25 + 16))(v25);
    *(_DWORD *)&v27[16 * a2 + 16] = v9;
  }
  v23 = 1;
  v31 = -1;
  std::wstring::~wstring(v28);
  return v23;
}


// address=[0x1366b90]
// Decompiled from char __thiscall CGfxManager::MoveAccessoriesToGfxEngine(CGfxManager *this)
bool  CGfxManager::MoveAccessoriesToGfxEngine(void) {
  
  unsigned int i; // [esp+Ch] [ebp-4h]

  if ( !*((_DWORD *)this + 225)
    && BBSupportDbgReport(2, "GfxManager.cpp", 1975, "m_pFileGfxFrames[ iGfxFile ].pItem") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 176) && BBSupportDbgReport(2, "GfxManager.cpp", 1976, "m_pFilePalIndex[ iGfxFile ]") == 1 )
    __debugbreak();
  for ( i = 0; i < 0x60; ++i )
    IGfxEngine::PutAccessoryIcon(
      (IGfxEngine *)g_pGfxEngine,
      i,
      *(void **)(*((_DWORD *)this + 225) + 4 * i + 20),
      *(void **)(*((_DWORD *)this + 176) + 4 * i + 20));
  return 1;
}


// address=[0x1366c80]
// Decompiled from char __thiscall CGfxManager::MoveWavesToGfxEngine(CGfxManager *this)
bool  CGfxManager::MoveWavesToGfxEngine(void) {
  
  unsigned int ObjectFrameCount; // eax
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int i7; // [esp+40h] [ebp-2E8h]
  unsigned int v20; // [esp+44h] [ebp-2E4h]
  unsigned int v21; // [esp+44h] [ebp-2E4h]
  unsigned int v22; // [esp+44h] [ebp-2E4h]
  unsigned int v23; // [esp+44h] [ebp-2E4h]
  unsigned int v24; // [esp+44h] [ebp-2E4h]
  unsigned int v25; // [esp+44h] [ebp-2E4h]
  unsigned int v26; // [esp+44h] [ebp-2E4h]
  unsigned int v27; // [esp+44h] [ebp-2E4h]
  unsigned int v28; // [esp+44h] [ebp-2E4h]
  unsigned int v29; // [esp+44h] [ebp-2E4h]
  unsigned int v30; // [esp+44h] [ebp-2E4h]
  unsigned int v31; // [esp+44h] [ebp-2E4h]
  unsigned int v32; // [esp+44h] [ebp-2E4h]
  unsigned int v33; // [esp+44h] [ebp-2E4h]
  unsigned int v34; // [esp+44h] [ebp-2E4h]
  unsigned int v35; // [esp+44h] [ebp-2E4h]
  unsigned int v36; // [esp+44h] [ebp-2E4h]
  unsigned int i; // [esp+4Ch] [ebp-2DCh]
  unsigned int j; // [esp+4Ch] [ebp-2DCh]
  unsigned int k; // [esp+4Ch] [ebp-2DCh]
  unsigned int m; // [esp+4Ch] [ebp-2DCh]
  unsigned int n; // [esp+4Ch] [ebp-2DCh]
  unsigned int ii; // [esp+4Ch] [ebp-2DCh]
  unsigned int jj; // [esp+4Ch] [ebp-2DCh]
  unsigned int kk; // [esp+4Ch] [ebp-2DCh]
  unsigned int mm; // [esp+4Ch] [ebp-2DCh]
  unsigned int nn; // [esp+4Ch] [ebp-2DCh]
  unsigned int i1; // [esp+4Ch] [ebp-2DCh]
  unsigned int i2; // [esp+4Ch] [ebp-2DCh]
  unsigned int i3; // [esp+4Ch] [ebp-2DCh]
  unsigned int i4; // [esp+4Ch] [ebp-2DCh]
  unsigned int i5; // [esp+4Ch] [ebp-2DCh]
  unsigned int i6; // [esp+4Ch] [ebp-2DCh]
  unsigned int v54; // [esp+50h] [ebp-2D8h]
  unsigned int v55; // [esp+50h] [ebp-2D8h]
  unsigned int v56; // [esp+50h] [ebp-2D8h]
  unsigned int v57; // [esp+50h] [ebp-2D8h]
  unsigned int v58; // [esp+50h] [ebp-2D8h]
  unsigned int v59; // [esp+50h] [ebp-2D8h]
  unsigned int v60; // [esp+50h] [ebp-2D8h]
  unsigned int v61; // [esp+50h] [ebp-2D8h]
  unsigned int v62; // [esp+50h] [ebp-2D8h]
  unsigned int v63; // [esp+50h] [ebp-2D8h]
  int v64; // [esp+50h] [ebp-2D8h]
  int v65; // [esp+50h] [ebp-2D8h]
  int v66; // [esp+50h] [ebp-2D8h]
  int v67; // [esp+50h] [ebp-2D8h]
  int v68; // [esp+50h] [ebp-2D8h]
  int v69; // [esp+50h] [ebp-2D8h]
  int v70; // [esp+50h] [ebp-2D8h]
  void *v71; // [esp+54h] [ebp-2D4h] BYREF
  void *v72; // [esp+58h] [ebp-2D0h]

  ObjectFrameCount = CGfxManager::GetObjectFrameCount(this, 0x20Du);
  IGfxEngine::SetIndexWave1((IGfxEngine *)g_pGfxEngine, 4096, ObjectFrameCount);
  v54 = CGfxManager::GetObjectFrameCount(this, 0x20Du) + 4096;
  v2 = CGfxManager::GetObjectFrameCount(this, 0x20Cu);
  IGfxEngine::SetIndexWave2((IGfxEngine *)g_pGfxEngine, v54, v2);
  v55 = v54 + CGfxManager::GetObjectFrameCount(this, 0x20Cu);
  v3 = CGfxManager::GetObjectFrameCount(this, 0x211u);
  IGfxEngine::SetIndexWave3((IGfxEngine *)g_pGfxEngine, v55, v3);
  v56 = v55 + CGfxManager::GetObjectFrameCount(this, 0x211u);
  v4 = CGfxManager::GetObjectFrameCount(this, 0x210u);
  IGfxEngine::SetIndexWave4((IGfxEngine *)g_pGfxEngine, v56, v4);
  v57 = v56 + CGfxManager::GetObjectFrameCount(this, 0x210u);
  v5 = CGfxManager::GetObjectFrameCount(this, 0x20Fu);
  IGfxEngine::SetIndexWave5((IGfxEngine *)g_pGfxEngine, v57, v5);
  v58 = v57 + CGfxManager::GetObjectFrameCount(this, 0x20Fu);
  v6 = CGfxManager::GetObjectFrameCount(this, 0x20Eu);
  IGfxEngine::SetIndexWave6((IGfxEngine *)g_pGfxEngine, v58, v6);
  v59 = v58 + CGfxManager::GetObjectFrameCount(this, 0x20Eu);
  v7 = CGfxManager::GetObjectFrameCount(this, 0x212u);
  IGfxEngine::SetIndexWave7((IGfxEngine *)g_pGfxEngine, v59, v7);
  v60 = v59 + CGfxManager::GetObjectFrameCount(this, 0x212u);
  v8 = CGfxManager::GetObjectFrameCount(this, 0x213u);
  IGfxEngine::SetIndexWave8((IGfxEngine *)g_pGfxEngine, v60, v8);
  v61 = v60 + CGfxManager::GetObjectFrameCount(this, 0x213u);
  v9 = CGfxManager::GetObjectFrameCount(this, 0x214u);
  IGfxEngine::SetIndexWave9((IGfxEngine *)g_pGfxEngine, v61, v9);
  v62 = v61 + CGfxManager::GetObjectFrameCount(this, 0x214u);
  v10 = CGfxManager::GetObjectFrameCount(this, 0x205u);
  IGfxEngine::SetIndexWave10((IGfxEngine *)g_pGfxEngine, v62, v10);
  v63 = v62 + CGfxManager::GetObjectFrameCount(this, 0x205u);
  v11 = CGfxManager::GetObjectFrameCount(this, 0x206u);
  IGfxEngine::SetIndexWave11((IGfxEngine *)g_pGfxEngine, v63, v11);
  v64 = v63 + CGfxManager::GetObjectFrameCount(this, 0x206u);
  v12 = CGfxManager::GetObjectFrameCount(this, 0x207u);
  IGfxEngine::SetIndexWave12((IGfxEngine *)g_pGfxEngine, v64, v12);
  v65 = v64 + CGfxManager::GetObjectFrameCount(this, 0x207u);
  v13 = CGfxManager::GetObjectFrameCount(this, 0x208u);
  IGfxEngine::SetIndexWave13((IGfxEngine *)g_pGfxEngine, v65, v13);
  v66 = v65 + CGfxManager::GetObjectFrameCount(this, 0x208u);
  v14 = CGfxManager::GetObjectFrameCount(this, 0x208u);
  IGfxEngine::SetIndexWave14((IGfxEngine *)g_pGfxEngine, v66, v14);
  v67 = v66 + CGfxManager::GetObjectFrameCount(this, 0x208u);
  v15 = CGfxManager::GetObjectFrameCount(this, 0x20Au);
  IGfxEngine::SetIndexWave15((IGfxEngine *)g_pGfxEngine, v67, v15);
  v68 = v67 + CGfxManager::GetObjectFrameCount(this, 0x20Au);
  v16 = CGfxManager::GetObjectFrameCount(this, 0x20Bu);
  IGfxEngine::SetIndexWave16((IGfxEngine *)g_pGfxEngine, v68, v16);
  v69 = v68 + CGfxManager::GetObjectFrameCount(this, 0x20Bu);
  v17 = CGfxManager::GetObjectFrameCount(this, 0x215u);
  IGfxEngine::SetIndexBorderstone((IGfxEngine *)g_pGfxEngine, v69, v17);
  CGfxManager::GetObjectFrameCount(this, 0x215u);
  v70 = 4096;
  v20 = CGfxManager::GetObjectFrameCount(this, 0x20Du);
  for ( i = 0; i < v20; ++i )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 525, i, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v21 = CGfxManager::GetObjectFrameCount(this, 0x20Cu);
  for ( j = 0; j < v21; ++j )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 524, j, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v22 = CGfxManager::GetObjectFrameCount(this, 0x211u);
  for ( k = 0; k < v22; ++k )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 529, k, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v23 = CGfxManager::GetObjectFrameCount(this, 0x210u);
  for ( m = 0; m < v23; ++m )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 528, m, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v24 = CGfxManager::GetObjectFrameCount(this, 0x20Fu);
  for ( n = 0; n < v24; ++n )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 527, n, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v25 = CGfxManager::GetObjectFrameCount(this, 0x20Eu);
  for ( ii = 0; ii < v25; ++ii )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 526, ii, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v26 = CGfxManager::GetObjectFrameCount(this, 0x212u);
  for ( jj = 0; jj < v26; ++jj )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 530, jj, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v27 = CGfxManager::GetObjectFrameCount(this, 0x213u);
  for ( kk = 0; kk < v27; ++kk )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 531, kk, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v28 = CGfxManager::GetObjectFrameCount(this, 0x214u);
  for ( mm = 0; mm < v28; ++mm )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 532, mm, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v29 = CGfxManager::GetObjectFrameCount(this, 0x205u);
  for ( nn = 0; nn < v29; ++nn )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 517, nn, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v30 = CGfxManager::GetObjectFrameCount(this, 0x206u);
  for ( i1 = 0; i1 < v30; ++i1 )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 518, i1, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v31 = CGfxManager::GetObjectFrameCount(this, 0x207u);
  for ( i2 = 0; i2 < v31; ++i2 )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 519, i2, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v32 = CGfxManager::GetObjectFrameCount(this, 0x208u);
  for ( i3 = 0; i3 < v32; ++i3 )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 520, i3, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v33 = CGfxManager::GetObjectFrameCount(this, 0x209u);
  for ( i4 = 0; i4 < v33; ++i4 )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 521, i4, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v34 = CGfxManager::GetObjectFrameCount(this, 0x20Au);
  for ( i5 = 0; i5 < v34; ++i5 )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 522, i5, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v35 = CGfxManager::GetObjectFrameCount(this, 0x20Bu);
  for ( i6 = 0; i6 < v35; ++i6 )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 523, i6, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v36 = CGfxManager::GetObjectFrameCount(this, 0x215u);
  if ( v36 != 8 )
    BBSupportTracePrintF(2, "GfxManager.cpp: Number of boundary stones != 8 !!!!");
  for ( i7 = v70; i7 < v36 + v70; ++i7 )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 533, i7 - v70, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, i7, v71, v72);
  }
  return 1;
}


// address=[0x1367b70]
// Decompiled from __int16 *__thiscall CGfxManager::Debug_Check_LayerBlock(CGfxManager *this, unsigned int a2, struct SGfxObjectInfo *a3)
void  CGfxManager::Debug_Check_LayerBlock(unsigned int a2, struct SGfxObjectInfo & a3) {
  
  __int16 *result; // eax
  int v4; // [esp+0h] [ebp-Ch]
  int v5; // [esp+4h] [ebp-8h]

  if ( !*((_DWORD *)this + 4 * a2 + 547)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 72, "m_sFileGfx[ %u ].pPileGfx", a2) == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 4 * a2 + 550)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 73, "m_sFileGfx[ %u ].iLength", a2) == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 4 * a2 + 1)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 74, "m_sFilePal[ %u ].pPileGfx", a2) == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 4 * a2 + 4)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 75, "m_sFilePal[ %u ].iLength", a2) == 1 )
  {
    __debugbreak();
  }
  if ( (*(_DWORD *)a3 < *((_DWORD *)this + 4 * a2 + 547)
     || *(_DWORD *)a3 >= (unsigned int)(*((_DWORD *)this + 4 * a2 + 550) + *((_DWORD *)this + 4 * a2 + 547)))
    && BBSupportDbgReportF(
         2,
         "GfxManager.cpp",
         87,
         "GfxFile: %u, Base: 0x%x, Len: 0x%x, Access: 0x%x\n%s",
         a2,
         *((_DWORD *)this + 4 * a2 + 547),
         *((_DWORD *)this + 4 * a2 + 550),
         *(_DWORD *)a3,
         byte_3ECDC20) == 1 )
  {
    __debugbreak();
  }
  if ( (*((_DWORD *)a3 + 1) < *((_DWORD *)this + 4 * a2 + 1)
     || *((_DWORD *)a3 + 1) >= (unsigned int)(*((_DWORD *)this + 4 * a2 + 4) + *((_DWORD *)this + 4 * a2 + 1)))
    && BBSupportDbgReportF(
         2,
         "GfxManager.cpp",
         98,
         "PalFile: %u, Base: 0x%x, Len: 0x%x, Access: 0x%x\n%s",
         a2,
         *((_DWORD *)this + 4 * a2 + 1),
         *((_DWORD *)this + 4 * a2 + 4),
         *((_DWORD *)a3 + 1),
         byte_3ECDC20) == 1 )
  {
    __debugbreak();
  }
  if ( a2 < 0x14 || a2 > 0x1D )
  {
    v5 = **(__int16 **)a3;
    result = *(__int16 **)a3;
    v4 = *(__int16 *)(*(_DWORD *)a3 + 2);
  }
  else
  {
    v5 = **(char **)a3;
    result = *(__int16 **)a3;
    v4 = *(char *)(*(_DWORD *)a3 + 1);
  }
  if ( !a2 || a2 == 9 || a2 == 19 || a2 == 29 || a2 == 18 || a2 == 28 || a2 == 39 || a2 == 40 || v5 <= 512 && v4 <= 512 )
    return result;
  result = (__int16 *)BBSupportDbgReportF(2, "GfxManager.cpp", 125, "Width or height > 512! [%s]", byte_3ECDC20);
  if ( result == (__int16 *)1 )
    __debugbreak();
  return result;
}


// address=[0x1367e50]
// Decompiled from struct SGfxPatchObject *__thiscall CGfxManager::Debug_Check_PatchLayerBlock(  CGfxManager *this,  unsigned int a2,  struct SGfxPatchObject *a3)
void  CGfxManager::Debug_Check_PatchLayerBlock(unsigned int a2, struct SGfxPatchObject & a3) {
  
  struct SGfxPatchObject *result; // eax

  if ( !*((_DWORD *)this + 4 * a2 + 547)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 178, "m_sFileGfx[ %u ].pPileGfx", a2) == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 4 * a2 + 550)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 179, "m_sFileGfx[ %u ].iLength", a2) == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 4 * a2 + 1)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 180, "m_sFilePal[ %u ].pPileGfx", a2) == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 4 * a2 + 4)
    && BBSupportDbgReportF(2, "GfxManager.cpp", 181, "m_sFilePal[ %u ].iLength", a2) == 1 )
  {
    __debugbreak();
  }
  if ( (*(_DWORD *)a3 < *((_DWORD *)this + 4 * a2 + 547)
     || *(_DWORD *)a3 >= (unsigned int)(*((_DWORD *)this + 4 * a2 + 550) + *((_DWORD *)this + 4 * a2 + 547)))
    && BBSupportDbgReportF(
         2,
         "GfxManager.cpp",
         193,
         "GfxFile: %u, Base: 0x%x, Len: ux%x, Access: 0x%x\n%s",
         a2,
         *((_DWORD *)this + 4 * a2 + 547),
         *((_DWORD *)this + 4 * a2 + 550),
         *(_DWORD *)a3,
         byte_3ECDC20) == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)a3 + 1) >= *((_DWORD *)this + 4 * a2 + 1) )
  {
    result = a3;
    if ( *((_DWORD *)a3 + 1) < (unsigned int)(*((_DWORD *)this + 4 * a2 + 4) + *((_DWORD *)this + 4 * a2 + 1)) )
      return result;
  }
  result = (struct SGfxPatchObject *)BBSupportDbgReportF(
                                       2,
                                       "GfxManager.cpp",
                                       204,
                                       "PalFile: %u, Base: 0x%x, Len: ux%x, Access: 0x%x\n%s",
                                       a2,
                                       *((_DWORD *)this + 4 * a2 + 1),
                                       *((_DWORD *)this + 4 * a2 + 4),
                                       *((_DWORD *)a3 + 1),
                                       byte_3ECDC20);
  if ( result == (struct SGfxPatchObject *)1 )
    __debugbreak();
  return result;
}


