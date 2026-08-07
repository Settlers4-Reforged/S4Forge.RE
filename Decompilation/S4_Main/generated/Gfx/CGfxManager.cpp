#include "CGfxManager.h"

// Definitions for class CGfxManager

// address=[0x1361470]
// Decompiled from CGfxManager *__thiscall CGfxManager::CGfxManager(CGfxManager *this, BYTE a2, bool a3, bool a4)
 CGfxManager::CGfxManager(bool a2, bool a3, bool a4) {
  
  std::wstring *a2a; // [esp+4h] [ebp-34h]
  std::wstring v7; // [esp+Ch] [ebp-2Ch] BYREF
  int v8; // [esp+34h] [ebp-4h]

  this->__vftable = (CGfxManager_vtbl *)&CGfxManager::_vftable_;
  _vec_ctor_no(this->m_sFilePal, 16u, 42u, (void *(__thiscall *)(void *))CGfxManager::SGFXINFO::SGFXINFO);
  _vec_ctor_no(this->m_sFileGfx, 0x10u, 42u, (void *(__thiscall *)(void *))CGfxManager::SGFXINFO::SGFXINFO);
  std::wstring::wstring(&this->m_swGfxFolderName);
  v8 = 1;
  String::String((String *)&this->m_sLastError);
  this->m_bUse6Palette = a2;
  memset(this->m_sFileGfx, 0, sizeof(this->m_sFileGfx));
  memset(this->m_sFilePal, 0, sizeof(this->m_sFilePal));
  memset(this->m_pFilePalIndex, 0, sizeof(this->m_pFilePalIndex));
  memset(this->m_pFileGfxFrames, 0, sizeof(this->m_pFileGfxFrames));
  memset(this->m_pFileGfxDirections, 0, sizeof(this->m_pFileGfxDirections));
  memset(this->m_pFileGfxJobs, 0, sizeof(this->m_pFileGfxJobs));
  memset(this->m_pFileGfxJobCodes, 0, sizeof(this->m_pFileGfxJobCodes));
  memset(this->field_B2C, 0, 0xA8u);
  a2a = (std::wstring *)std::wstring::wstring(&v7, (wchar_t *)L"Gfx");
  std::wstring::operator=(&this->m_swGfxFolderName, a2a);
  std::wstring::~wstring(&v7);
  this->m_iActiveGfxFile = -1;
  memset(byte_3ECDBF4, 0, sizeof(byte_3ECDBF4));
  this->field_cbc = a3;
  this->field_cbd = a4;
  this->m_bUseHighTerrain = 0;
  return this;
}


// address=[0x1361660]
// Decompiled from void __thiscall CGfxManager::~CGfxManager(CGfxManager *this)
 CGfxManager::~CGfxManager(void) {
  
  this->__vftable = (CGfxManager_vtbl *)&CGfxManager::_vftable_;
  CGfxManager::RemoveAllGFX(this, -1);
  String::~String((String *)&this->m_sLastError);
  std::wstring::~wstring(&this->m_swGfxFolderName);
}


// address=[0x13616d0]
// Decompiled from char __thiscall CGfxManager::OpenGFXFiles(CGfxManager *this)
bool  CGfxManager::OpenGFXFiles(void) {
  
  CGfxManager::EnableGfxFile(this, 20u, 0, 1u, 58);
  CGfxManager::EnableGfxFile(this, 22u, 0, 1u, 58);
  CGfxManager::EnableGfxFile(this, 21u, 0, 1u, 58);
  CGfxManager::EnableGfxFile(this, 23u, 0, 1u, 58);
  CGfxManager::EnableGfxFile(this, 24u, 0, 1u, 58);
  if ( g_bGfxHJBLoadSpecialGfx )
  {
    CGfxManager::EnableGfxFile(this, 25u, 0, 1u, 58);
  }
  CGfxManager::EnableGfxFile(this, 10u, 1, 1u, 63);
  CGfxManager::EnableGfxFile(this, 12u, 1, 1u, 63);
  CGfxManager::EnableGfxFile(this, 11u, 1, 1u, 63);
  CGfxManager::EnableGfxFile(this, 13u, 1, 1u, 63);
  CGfxManager::EnableGfxFile(this, 14u, 1, 1u, 63);
  CGfxManager::EnableGfxFile(this, 3u, 2, 1u, 10);
  CGfxManager::EnableGfxFile(this, 5u, 3, 1u, 85);
  CGfxManager::EnableGfxFile(this, 7u, 6, 1u, 26);
  CGfxManager::EnableGfxFile(this, 8u, 5, 1u, 13);
  if ( IGfxEngine::Use4444Palettes(g_pGfxEngine) )
  {
    CGfxManager::EnableGfxFile(this, 4u, 7, 1u, 33);
    if ( this->field_cbc || this->field_cbd )
    {
      CGfxManager::EnableGfxFile(this, 36u, 7, 1u, 12);
    }
  }
  else
  {
    CGfxManager::EnableGfxFile(this, 6u, 7, 1u, 33);
    if ( this->field_cbc || this->field_cbd )
    {
      CGfxManager::EnableGfxFile(this, 37u, 7, 1u, 12);
    }
  }
  CGfxManager::EnableGfxFile(this, 30u, 4, 1u, 9);
  CGfxManager::EnableGfxFile(this, 32u, 4, 1u, 9);
  CGfxManager::EnableGfxFile(this, 31u, 4, 1u, 9);
  CGfxManager::EnableGfxFile(this, 34u, 4, 1u, 9);
  CGfxManager::Reload(1, 1, this->m_bUse6Palette == 0);
  return 1;
}


// address=[0x13618d0]
// Decompiled from void __thiscall CGfxManager::GetGuiGfxInfo(CGfxManager *this, struct SGfxObjectInfo *a2, unsigned int a3)
void  CGfxManager::GetGuiGfxInfo(struct SGfxObjectInfo & a2, unsigned int a3) {
  
  unsigned int iGfxFile; // [esp+0h] [ebp-8h]

  iGfxFile = this->m_iActiveGfxFile;
  if ( !this->m_pFileGfxFrames[iGfxFile].m_pItem && BBSupportDbgReport(2, "GfxManager.cpp", 913, "m_pFileGfxFrames[ iGfxFile ].pItem") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pFilePalIndex[iGfxFile] && BBSupportDbgReport(2, "GfxManager.cpp", 914, "m_pFilePalIndex[ iGfxFile ]") == 1 )
  {
    __debugbreak();
  }
  if ( (char *)a3 <= this->m_pFileGfxFrames[iGfxFile].m_iCount )
  {
    a2->m_pGfxData = this->m_pFileGfxFrames[iGfxFile].m_pItem[a3 + 5];
    a2->m_pPalData = this->m_pFilePalIndex[iGfxFile][a3 + 5];
    sprintf(sGfxDebugBuffer, "Gui Element: %u", a3);
    CGfxManager::Debug_Check_LayerBlock(this, iGfxFile, a2);
  }
  else
  {
    memset(a2, 0, 0x2D0u);
  }
}


// address=[0x13619d0]
// Decompiled from void __thiscall CGfxManager::GetUserLogoGfxInfo(CGfxManager *this, struct SGfxObjectInfo *userLogoGfxInfo, unsigned int logoNr, unsigned int _iDir)
void  CGfxManager::GetUserLogoGfxInfo(struct SGfxObjectInfo & userLogoGfxInfo, unsigned int logoNr, unsigned int _iDir) {
  
  int logoIndex; // [esp+18h] [ebp+Ch]

  if ( _iDir >= 2 && BBSupportDbgReport(2, "GfxManager.cpp", 938, "_iDir < MAX_LOGO_DIRECTIONS") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pFileGfxFrames[1].m_pItem && BBSupportDbgReport(2, "GfxManager.cpp", 941, "m_pFileGfxFrames[ iGfxFile ].pItem") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pFilePalIndex[1] && BBSupportDbgReport(2, "GfxManager.cpp", 942, "m_pFilePalIndex[ iGfxFile ]") == 1 )
  {
    __debugbreak();
  }
  logoIndex = logoNr - 1;
  userLogoGfxInfo->m_pGfxData = (BYTE *)this->m_pFileGfxFrames[1].m_pItem[2 * logoIndex + 5];
  userLogoGfxInfo->m_pPalData = this->m_pFilePalIndex[1][2 * logoIndex + 5];
  sprintf(sGfxDebugBuffer, "Logo Player Nr: %u, Direction: %u", logoIndex, 0);
  CGfxManager::Debug_Check_LayerBlock(this, 1u, userLogoGfxInfo);
}


// address=[0x1361af0]
// Decompiled from void __thiscall CGfxManager::GetBuildingGfxInfo(CGfxManager *this, SGfxObjectInfo *_rInfo, uint _iRace, uint _iBuilding, uint _iFlags, CGfxManager::SBuildingFX *_argBuildingFX)
void  CGfxManager::GetBuildingGfxInfo(struct SGfxObjectInfo & _rInfo, unsigned int _iRace, unsigned int _iBuilding, unsigned int _iFlags, struct SBuildingFX * _argBuildingFX) {
  
  unsigned int iGfxFile; // [esp+20h] [ebp-8h]
  unsigned int i; // [esp+24h] [ebp-4h]
  uint iBuilding; // [esp+38h] [ebp+10h]

  iGfxFile = _iRace + 10;
  if ( !this->m_pFileGfxJobs[_iRace + 10].m_pItem && BBSupportDbgReportF(2, "GfxManager.cpp", 1330, "m_pFileGfxJobs[ %u ].pItem", iGfxFile) == 1 )
  {
    __debugbreak();
  }
  if ( _iBuilding >= this->m_pFileGfxJobs[iGfxFile].m_iCount && BBSupportDbgReport(2, "GfxManager.cpp", 1331, "_iBuilding < m_pFileGfxJobs[ iGfxFile ].iCount") == 1 )
  {
    __debugbreak();
  }
  iBuilding = _iBuilding >= this->m_pFileGfxJobs[iGfxFile].m_iCount ? 0 : _iBuilding;
  dword_3ECDD6C = (int)this->m_pFileGfxJobs[iGfxFile].m_pItem[iBuilding + 5];
  if ( (_iFlags & 1) != 0 && (_iFlags & 2) != 0 )
  {
    dword_3ECDD74 = *(_DWORD *)(dword_3ECDD6C + 4);
    dword_3ECDD70 = *(_DWORD *)dword_3ECDD74;
    _rInfo->m_pGfxData = (BYTE *)dword_3ECDD70;
    dword_3ECDD74 = *(_DWORD *)dword_3ECDD6C;
    dword_3ECDD70 = *(_DWORD *)dword_3ECDD74;
    _rInfo->m_pBuildLayerGfxData = dword_3ECDD70;
  }
  else
  {
    if ( (_iFlags & 1) != 0 )
    {
      dword_3ECDD74 = *(_DWORD *)(dword_3ECDD6C + 4);
      dword_3ECDD70 = *(_DWORD *)dword_3ECDD74;
      _rInfo->m_pGfxData = (BYTE *)dword_3ECDD70;
    }
    if ( (_iFlags & 2) != 0 )
    {
      dword_3ECDD74 = *(_DWORD *)dword_3ECDD6C;
      dword_3ECDD70 = *(_DWORD *)dword_3ECDD74;
      _rInfo->m_pGfxData = (BYTE *)dword_3ECDD70;
    }
  }
  if ( _argBuildingFX )
  {
    for ( i = 0;
          i < 10;
          ++i )
    {
      if ( _argBuildingFX[i].m_iBuildingDefine )
      {
        if ( _argBuildingFX[i].m_iBuildingDefine >= (unsigned int)this->m_pFileGfxDirections[iGfxFile].m_iCount && BBSupportDbgReport(2, "GfxManager.cpp", 1379, "_argBuildingFX[ i ].iBuildingDefine < m_pFileGfxDirections[ iGfxFile ].iCount") == 1 )
        {
          __debugbreak();
        }
        _argBuildingFX[i].m_iBuildingDefine &= (_argBuildingFX[i].m_iBuildingDefine >= (unsigned int)this->m_pFileGfxDirections[iGfxFile].m_iCount) - 1;
        if ( _argBuildingFX[i].m_iFrame >= CGfxManager::GetBuildingJobFrameCount(this, _iRace, _argBuildingFX[i].m_iBuildingDefine) && BBSupportDbgReport(2, "GfxManager.cpp", 1383, "_argBuildingFX[ i ].iFrame < GetBuildingJobFrameCount( _iRace, _argBuildingFX[ i ].iBuildingDefine )") == 1 )
        {
          __debugbreak();
        }
        _argBuildingFX[i].m_iFrame &= (_argBuildingFX[i].m_iFrame >= CGfxManager::GetBuildingJobFrameCount(this, _iRace, _argBuildingFX[i].m_iBuildingDefine)) - 1;
        dword_3ECDD70 = (int)this->m_pFileGfxDirections[iGfxFile].m_pItem[_argBuildingFX[i].m_iBuildingDefine + 5];
        dword_3ECDD74 = *(_DWORD *)(dword_3ECDD70 + 4 * _argBuildingFX[i].m_iFrame);
        _rInfo->m_vFXFrameData[i] = dword_3ECDD74;
      }
    }
  }
  if ( (_iFlags & 8) != 0 )
  {
    dword_3ECDD74 = *(_DWORD *)(dword_3ECDD6C + 8);
    dword_3ECDD70 = *(_DWORD *)dword_3ECDD74;
    _rInfo->m_vFXFrameData[5] = dword_3ECDD70;
  }
  if ( !this->m_pFilePalIndex[iGfxFile] && BBSupportDbgReportF(2, "GfxManager.cpp", 1407, "m_pFilePalIndex[ %u ]", iGfxFile) == 1 )
  {
    __debugbreak();
  }
  _rInfo->m_pPalData = this->m_pFilePalIndex[iGfxFile][iBuilding + 5];
  sprintf(sGfxDebugBuffer, "Building Race: %u, Building: %u, Flags: 0x%x", _iRace, iBuilding, _iFlags);
  CGfxManager::Debug_Check_LayerBlock(this, iGfxFile, _rInfo);
}


// address=[0x1361f10]
// Decompiled from unsigned int __thiscall CGfxManager::GetBuildingFirstJob(CGfxManager *this, unsigned int _iRace, unsigned int a3)
unsigned int  CGfxManager::GetBuildingFirstJob(unsigned int _iRace, unsigned int a3) {
  
  int v4; // [esp+0h] [ebp-10h] BYREF
  unsigned int v5; // [esp+4h] [ebp-Ch] BYREF
  unsigned int v7; // [esp+Ch] [ebp-4h]

  v7 = _iRace + 10;
  if ( !this->m_pFileGfxJobs[_iRace + 10].m_pItem && BBSupportDbgReportF(2, "GfxManager.cpp", 1127, "m_pFileGfxJobs[ %u ].pItem", v7) == 1 )
  {
    __debugbreak();
  }
  CGfxManager::GetJobIndices(this, v7, a3, &v5, &v4);
  return v5;
}


// address=[0x1361f80]
// Decompiled from void __thiscall CGfxManager::GetObjectGfxInfo(CGfxManager *this, struct SGfxObjectInfo *a2, unsigned int a3, unsigned int a4, int _iAmount)
void  CGfxManager::GetObjectGfxInfo(struct SGfxObjectInfo & a2, unsigned int a3, unsigned int a4, unsigned int _iAmount) {
  
  int v6; // [esp+24h] [ebp+Ch]
  unsigned int v7; // [esp+28h] [ebp+10h]
  int _iAmounta; // [esp+2Ch] [ebp+14h]

  if ( !this->m_pFileGfxJobs[s_iActiveGfx].m_pItem && BBSupportDbgReportF(2, "GfxManager.cpp", 1424, "m_pFileGfxJobs[ %u ].pItem", s_iActiveGfx) == 1 )
  {
    __debugbreak();
  }
  if ( a3 >= 552 && BBSupportDbgReportF(2, "GfxManager.cpp", 1425, "%u < SIV_OBJECT_MAX", a3) == 1 )
  {
    __debugbreak();
  }
  v6 = a3 >= 552 ? 0 : a3;
  if ( a4 >= CGfxManager::GetObjectFrameCount(this, v6) && BBSupportDbgReportF(2, "GfxManager.cpp", 1429, "%u < GetObjectFrameCount( %u )", a4, v6) == 1 )
  {
    __debugbreak();
  }
  v7 = a4 >= CGfxManager::GetObjectFrameCount(this, v6) ? 0 : a4;
  if ( !_iAmount && BBSupportDbgReportF(2, "GfxManager.cpp", 1432, "_iAmount : %u", 0) == 1 )
  {
    __debugbreak();
  }
  _iAmounta = _iAmount - 1;
  a2->m_pGfxData = *(BYTE **)(*(_DWORD *)&this->m_pFileGfxJobs[s_iActiveGfx].m_pItem[v6 + 5][4 * _iAmounta] + 4 * v7);
  if ( !this->m_pFilePalIndex[s_iActiveGfx] && BBSupportDbgReportF(2, "GfxManager.cpp", 1446, "m_pFilePalIndex[ %u ]", s_iActiveGfx) == 1 )
  {
    __debugbreak();
  }
  a2->m_pPalData = this->m_pFilePalIndex[s_iActiveGfx][v6 + 5];
  sprintf(sGfxDebugBuffer, "Object: %u, Frame: %u, Amount: %u", v6, v7, _iAmounta);
  CGfxManager::Debug_Check_LayerBlock(this, s_iActiveGfx, a2);
}


// address=[0x13621a0]
// Decompiled from unsigned int __thiscall CGfxManager::GetObjectFirstJob(CGfxManager *this, unsigned int a2)
unsigned int  CGfxManager::GetObjectFirstJob(unsigned int a2) {
  
  if ( !this->m_pFileGfxJobCodes[5].m_pItem && BBSupportDbgReportF(2, "GfxManager.cpp", 1085, "m_pFileGfxJobCodes[ %u ].pItem", 5) == 1 )
  {
    __debugbreak();
  }
  return (unsigned int)(this->m_pFileGfxJobCodes[5].m_pItem[a2 + 5] - 20) >> 2;
}


// address=[0x1362210]
// Decompiled from void __thiscall CGfxManager::GetSettlerGfxInfo(CGfxManager *this, struct SGfxObjectInfo *_rInfo, unsigned int _iRace, unsigned int _iJob, unsigned int _iFrame, unsigned int _iDir)
void  CGfxManager::GetSettlerGfxInfo(struct SGfxObjectInfo & _rInfo, unsigned int _iRace, unsigned int _iJob, unsigned int _iFrame, unsigned int _iDir) {
  
  unsigned int iGfxFile; // [esp+Ch] [ebp-8h]
  int iJob; // [esp+24h] [ebp+10h]
  unsigned int iFrame; // [esp+28h] [ebp+14h]

  iGfxFile = _iRace + 20;
  if ( !this->m_pFileGfxJobs[_iRace + 20].m_pItem && BBSupportDbgReportF(2, "GfxManager.cpp", 967, "m_pFileGfxJobs[ %u ].pItem", iGfxFile) == 1 )
  {
    __debugbreak();
  }
  if ( _iJob >= 0x16F && BBSupportDbgReport(2, "GfxManager.cpp", 968, "_iJob < SIV_MAX_JOB") == 1 )
  {
    __debugbreak();
  }
  iJob = _iJob >= 0x16F ? 0 : _iJob;
  if ( _iFrame >= CGfxManager::GetSettlerJobFrameCount(this, _iRace, iJob, 2) && BBSupportDbgReportF(2, "GfxManager.cpp", 972, "Invalid frame %i, job %i, race %i", _iFrame, iJob, _iRace) == 1 )
  {
    __debugbreak();
  }
  iFrame = _iFrame >= CGfxManager::GetSettlerJobFrameCount(this, _iRace, iJob, 2) ? 0 : _iFrame;
  dword_3ECDD5C = (int *)this->m_pFileGfxJobs[iGfxFile].m_pItem[iJob + 5];
  dword_3ECDD60 = (int *)dword_3ECDD5C[_iDir];
  dword_3ECDD5C = (int *)dword_3ECDD60[iFrame];
  _rInfo->m_pGfxData = (BYTE *)dword_3ECDD5C;
  if ( !this->m_pFilePalIndex[iGfxFile] && BBSupportDbgReportF(2, "GfxManager.cpp", 985, "m_pFilePalIndex[ %u ]", iGfxFile) == 1 )
  {
    __debugbreak();
  }
  _rInfo->m_pPalData = this->m_pFilePalIndex[iGfxFile][iJob + 5];
  sprintf(sGfxDebugBuffer, "Settler Race: %u, Job: %u, Frame: %u, Direction: %u", _iRace, iJob, iFrame, _iDir);
  CGfxManager::Debug_Check_LayerBlock(this, iGfxFile, _rInfo);
}


// address=[0x1362410]
// Decompiled from unsigned int __thiscall CGfxManager::GetSettlerFirstJob(CGfxManager *this, int _iRace, int a3)
unsigned int  CGfxManager::GetSettlerFirstJob(unsigned int _iRace, unsigned int a3) {
  
  int v4; // [esp+Ch] [ebp-4h]

  v4 = _iRace + 20;
  if ( this->m_pFileGfxJobCodes[_iRace + 20].m_pItem )
  {
    if ( this->m_pFileGfxJobs[v4].m_pItem[((unsigned int)(this->m_pFileGfxJobCodes[v4].m_pItem[a3 + 5] - 20) >> 2) + 5] == (char *)(*(_DWORD *)&this->m_pFileGfxDirections[8 * v4] + 20) )
    {
      return 0;
    }
    else
    {
      return (unsigned int)(this->m_pFileGfxJobCodes[v4].m_pItem[a3 + 5] - 20) >> 2;
    }
  }
  else
  {
    if ( byte_3ECDBF4[v4] )
    {
      return 1;
    }
    BBSupportTracePrintF(2, "GfxManager.cpp: !!! GetSettlerFirstJob() for unloaded gfx %d file called !!", v4);
    byte_3ECDBF4[v4] = 1;
    return 1;
  }
}


// address=[0x13624d0]
// Decompiled from struct SGfxPatchObject *__thiscall CGfxManager::GetPatchSettlerGfxInfo(CGfxManager *this, struct SGfxPatchObject *a2, unsigned int _iRace, unsigned int _iJob, unsigned int _iFrame, unsigned int _iDir)
void  CGfxManager::GetPatchSettlerGfxInfo(struct SGfxPatchObject & a2, unsigned int _iRace, unsigned int _iJob, unsigned int _iFrame, unsigned int _iDir) {
  
  unsigned int iGfxFile; // [esp+4h] [ebp-4h]

  iGfxFile = _iRace + 20;
  if ( !this->m_pFileGfxJobs[_iRace + 20].m_pItem && BBSupportDbgReportF(2, "GfxManager.cpp", 1008, "m_pFileGfxJobs[ %u ].pItem", iGfxFile) == 1 )
  {
    __debugbreak();
  }
  if ( _iJob >= 0x16F )
  {
    BBSupportTracePrintF(2, "GfxManager: Invalid Settler Job#%d for Race#%d, Direction#%d, Frame#%d", _iJob, _iRace, _iDir, _iFrame);
    _iJob = 0;
  }
  dword_3ECDD64 = (int *)this->m_pFileGfxJobs[iGfxFile].m_pItem[_iJob + 5];
  dword_3ECDD68 = (int *)dword_3ECDD64[_iDir];
  dword_3ECDD64 = (int *)dword_3ECDD68[_iFrame];
  a2->m_pGfxData = (char *)dword_3ECDD64;
  if ( !this->m_pFilePalIndex[iGfxFile] && BBSupportDbgReportF(2, "GfxManager.cpp", 1025, "m_pFilePalIndex[ %u ]", iGfxFile) == 1 )
  {
    __debugbreak();
  }
  a2->m_pPalData = this->m_pFilePalIndex[iGfxFile][_iJob + 5];
  sprintf(sGfxDebugBuffer, "Patch Settler Race: %u, Job: %u, Frame: %u, Direction: %u", _iRace, _iJob, _iFrame, _iDir);
  return CGfxManager::Debug_Check_PatchLayerBlock(this, iGfxFile, a2);
}


// address=[0x1362620]
// Decompiled from void __thiscall CGfxManager::GetPileGfxInfo(CGfxManager *this, struct SGfxObjectInfo *a2, int iPile, int _iAmount, unsigned int a5)
void  CGfxManager::GetPileGfxInfo(struct SGfxObjectInfo & a2, unsigned int iPile, unsigned int _iAmount, unsigned int a5) {
  
  unsigned int _iAmounta; // [esp+24h] [ebp+10h]
  int _iAmountb; // [esp+24h] [ebp+10h]
  unsigned int v8; // [esp+28h] [ebp+14h]

  if ( !this->m_pFileGfxJobs[s_iActivePileGfx].m_pItem && BBSupportDbgReportF(2, "GfxManager.cpp", 1463, "m_pFileGfxJobs[ %u ].pItem", s_iActivePileGfx) == 1 )
  {
    __debugbreak();
  }
  if ( !_iAmount && BBSupportDbgReportF(2, "GfxManager.cpp", 1464, "_iAmount %u", 0) == 1 )
  {
    __debugbreak();
  }
  _iAmounta = _iAmount - 1;
  if ( _iAmounta >= 0x10 && BBSupportDbgReportF(2, "GfxManager.cpp", 1468, "%u < 16", _iAmounta) == 1 )
  {
    __debugbreak();
  }
  _iAmountb = _iAmounta & 0xF;
  if ( a5 >= CGfxManager::GetPileFrameCount(iPile) && BBSupportDbgReportF(2, "GfxManager.cpp", 1471, "%u < GetPileFrameCount( %u )", a5, iPile) == 1 )
  {
    __debugbreak();
  }
  v8 = a5 >= CGfxManager::GetPileFrameCount(iPile) ? 0 : a5;
  a2->m_pGfxData = *(char **)(*(_DWORD *)&this->m_pFileGfxJobs[s_iActivePileGfx].m_pItem[iPile + 5][4 * _iAmountb] + 4 * v8);
  if ( !this->m_pFilePalIndex[s_iActivePileGfx] && BBSupportDbgReport(2, "GfxManager.cpp", 1484, "m_pFilePalIndex[ iGfxFile ]") == 1 )
  {
    __debugbreak();
  }
  a2->m_pPalData = this->m_pFilePalIndex[s_iActivePileGfx][iPile + 5];
  sprintf(sGfxDebugBuffer, "Pile: %u, Amount: %u, Frame: %u", iPile, _iAmountb, v8);
  CGfxManager::Debug_Check_LayerBlock(this, s_iActivePileGfx, a2);
}


// address=[0x1362810]
// Decompiled from void __thiscall CGfxManager::GetPatchPileGfxInfo(CGfxManager *this, struct SGfxPatchObject *a2, int iPile, unsigned int _iAmount, unsigned int a5)
void  CGfxManager::GetPatchPileGfxInfo(struct SGfxPatchObject & a2, unsigned int iPile, unsigned int _iAmount, unsigned int a5) {
  
  unsigned int iAmount; // [esp+24h] [ebp+10h]
  unsigned int iFrame; // [esp+28h] [ebp+14h]

  if ( !_iAmount && BBSupportDbgReportF(2, "GfxManager.cpp", 1501, "_iAmount %u", 0) == 1 )
  {
    __debugbreak();
  }
  iAmount = _iAmount - 1;
  if ( iAmount >= 0x10 && BBSupportDbgReportF(2, "GfxManager.cpp", 1505, "%u < 16", iAmount) == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pFileGfxJobs[dword_3D7AB20].m_pItem && BBSupportDbgReportF(2, "GfxManager.cpp", 1507, "m_pFileGfxJobs[ %u ].pItem", iAmount) == 1 )
  {
    __debugbreak();
  }
  if ( a5 >= CGfxManager::GetPileFrameCount(iPile) && BBSupportDbgReportF(2, "GfxManager.cpp", 1508, "%u < GetPileFrameCount( %u )", a5, iPile) == 1 )
  {
    __debugbreak();
  }
  iFrame = a5 >= CGfxManager::GetPileFrameCount(iPile) ? 0 : a5;
  *(_DWORD *)a2 = *(_DWORD *)(*(_DWORD *)&this->m_pFileGfxJobs[dword_3D7AB20].m_pItem[iPile + 5][4 * iAmount] + 4 * iFrame);
  if ( !this->m_pFilePalIndex[dword_3D7AB20] && BBSupportDbgReportF(2, "GfxManager.cpp", 1521, "m_pFilePalIndex[ %u ]", dword_3D7AB20) == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)a2 + 1) = this->m_pFilePalIndex[dword_3D7AB20][iPile + 5];
  sprintf(sGfxDebugBuffer, "PatchPile: %u, Amount: %u, Frame: %u", iPile, iAmount, iFrame);
  CGfxManager::Debug_Check_PatchLayerBlock(this, dword_3D7AB20, a2);
}


// address=[0x1362a00]
// Decompiled from void __thiscall CGfxManager::GetVehicleGfxInfo(CGfxManager *this, struct SGfxObjectInfo *a2, unsigned int iRace, unsigned int a4, unsigned int _iDir, unsigned int _iFrame, unsigned int _iJobPatch, unsigned int _iFramePatch)
void  CGfxManager::GetVehicleGfxInfo(struct SGfxObjectInfo & a2, unsigned int iRace, unsigned int a4, unsigned int _iDir, unsigned int _iFrame, unsigned int _iJobPatch, unsigned int _iFramePatch) {
  
  unsigned int iGfxFile; // [esp+1Ch] [ebp-8h]
  int iJob; // [esp+34h] [ebp+10h]

  iGfxFile = iRace + 30;
  if ( !this->m_pFileGfxJobs[iRace + 30].m_pItem && BBSupportDbgReportF(2, "GfxManager.cpp", 1538, "m_pFileGfxJobs[ %u ].pItem", iGfxFile) == 1 )
  {
    __debugbreak();
  }
  if ( a4 >= this->m_pFileGfxJobs[iGfxFile].m_iCount && BBSupportDbgReport(2, "GfxManager.cpp", 1539, "_iJob < m_pFileGfxJobs[ iGfxFile ].iCount") == 1 )
  {
    __debugbreak();
  }
  iJob = a4 >= this->m_pFileGfxJobs[iGfxFile].m_iCount ? 0 : a4;
  if ( _iFrame >= CGfxManager::GetVehicleFrameCount(this, iRace, iJob) && BBSupportDbgReportF(2, "GfxManager.cpp", 1543, "_iFrame < GetVehicleFrameCount( %u, %u )", iRace, iJob) == 1 )
  {
    __debugbreak();
  }
  _iFrame &= (_iFrame >= CGfxManager::GetVehicleFrameCount(this, iRace, iJob)) - 1;
  a2->m_pGfxData = *(char **)(*(_DWORD *)&this->m_pFileGfxJobs[iGfxFile].m_pItem[iJob + 5][4 * _iDir] + 4 * _iFrame);
  if ( !this->m_pFilePalIndex[iGfxFile] && BBSupportDbgReportF(2, "GfxManager.cpp", 1555, "m_pFilePalIndex[ %u ]", iGfxFile) == 1 )
  {
    __debugbreak();
  }
  a2->m_pPalData = this->m_pFilePalIndex[iGfxFile][iJob + 5];
  if ( _iJobPatch )
  {
    if ( _iJobPatch >= this->m_pFileGfxJobs[iGfxFile].m_iCount && BBSupportDbgReport(2, "GfxManager.cpp", 1561, "_iJobPatch < m_pFileGfxJobs[ iGfxFile ].iCount") == 1 )
    {
      __debugbreak();
    }
    _iJobPatch &= (_iJobPatch >= this->m_pFileGfxJobs[iGfxFile].m_iCount) - 1;
    if ( _iFrame >= CGfxManager::GetVehicleFrameCount(this, iRace, _iJobPatch) && BBSupportDbgReportF(2, "GfxManager.cpp", 1565, "_iFrame < GetVehicleFrameCount( %u, %u )", iRace, _iJobPatch) == 1 )
    {
      __debugbreak();
    }
    _iFrame &= (_iFrame >= CGfxManager::GetVehicleFrameCount(this, iRace, _iJobPatch)) - 1;
    a2->m_pPatchGfxData = *(char **)(*(_DWORD *)&this->m_pFileGfxJobs[iGfxFile].m_pItem[_iJobPatch + 5][4 * _iDir] + 4 * _iFramePatch);
    a2->m_pPatchPalData = this->m_pFilePalIndex[iGfxFile][_iJobPatch + 5];
  }
  sprintf(sGfxDebugBuffer, "Vehicle Race: %u, Job: %u, Direction: %u, Frame: %u, JobPatch: %u, FramePatch: %u", iRace, iJob, _iDir, _iFrame, _iJobPatch, _iFramePatch);
  CGfxManager::Debug_Check_LayerBlock(this, iGfxFile, a2);
}


// address=[0x1362d50]
// Decompiled from unsigned int __thiscall CGfxManager::GetVehicleFirstJob(CGfxManager *this, unsigned int _iRace, unsigned int a3)
unsigned int  CGfxManager::GetVehicleFirstJob(unsigned int _iRace, unsigned int a3) {
  
  int v5; // [esp+8h] [ebp-4h]

  v5 = _iRace + 30;
  if ( !this->m_pFileGfxJobCodes[_iRace + 30].m_pItem && BBSupportDbgReportF(2, "GfxManager.cpp", 1113, "m_pFileGfxJobCodes[ %u ].pItem", v5) == 1 )
  {
    __debugbreak();
  }
  return (unsigned int)(this->m_pFileGfxJobCodes[v5].m_pItem[a3 + 5] - 20) >> 2;
}


// address=[0x1362dc0]
// Decompiled from void __thiscall CGfxManager::GetAnimalGfxInfo(CGfxManager *this, struct SGfxObjectInfo *a2, uint _iJob, uint _iDirection, uint _iFrame)
void  CGfxManager::GetAnimalGfxInfo(struct SGfxObjectInfo & a2, unsigned int a3, unsigned int a4, unsigned int a5) {
  
  uint iAnimal; // [esp+28h] [ebp+Ch]
  uint frame; // [esp+30h] [ebp+14h]

  if ( !this->m_pFileGfxJobs[8].m_pItem && BBSupportDbgReport(2, "GfxManager.cpp", 1593, "m_pFileGfxJobs[ iGfxFile ].pItem") == 1 )
  {
    __debugbreak();
  }
  if ( _iJob >= this->m_pFileGfxJobs[8].m_iCount && BBSupportDbgReport(2, "GfxManager.cpp", 1594, "_iJob < m_pFileGfxJobs[ iGfxFile ].iCount") == 1 )
  {
    __debugbreak();
  }
  iAnimal = _iJob >= this->m_pFileGfxJobs[8].m_iCount ? 0 : _iJob;
  if ( _iFrame >= CGfxManager::GetAnimalFrameCount(this, iAnimal) && BBSupportDbgReport(2, "GfxManager.cpp", 1598, "_iFrame < GetAnimalFrameCount( _iJob )") == 1 )
  {
    __debugbreak();
  }
  frame = _iFrame >= CGfxManager::GetAnimalFrameCount(this, iAnimal) ? 0 : _iFrame;
  if ( iAnimal > this->m_pFileGfxJobs[8].m_iCount )
  {
    BBSupportTracePrintF(2, "GfxManager: Invalid Animal Job#%d for Direction#%d, Frame#%d", iAnimal, _iDirection, frame);
    iAnimal = 0;
  }
  a2->m_pGfxData = *(char **)(*(_DWORD *)&this->m_pFileGfxJobs[8].m_pItem[iAnimal + 5][4 * _iDirection] + 4 * frame);
  if ( !this->m_pFilePalIndex[8] && BBSupportDbgReport(2, "GfxManager.cpp", 1616, "m_pFilePalIndex[ iGfxFile ]") == 1 )
  {
    __debugbreak();
  }
  a2->m_pPalData = this->m_pFilePalIndex[8][iAnimal + 5];
  sprintf(sGfxDebugBuffer, "Animal %u, Direction: %u, Frame: %u", iAnimal, _iDirection, frame);
  CGfxManager::Debug_Check_LayerBlock(this, 8u, a2);
}


// address=[0x1362fc0]
// Decompiled from unsigned int __thiscall CGfxManager::GetAnimalFirstJob(CGfxManager *this, unsigned int a2)
unsigned int  CGfxManager::GetAnimalFirstJob(unsigned int a2) {
  
  if ( !this->m_pFileGfxJobCodes[8].m_pItem && BBSupportDbgReportF(2, "GfxManager.cpp", 1099, "m_pFileGfxJobCodes[ %u ].pItem", 8) == 1 )
  {
    __debugbreak();
  }
  return (unsigned int)(this->m_pFileGfxJobCodes[8].m_pItem[a2 + 5] - 20) >> 2;
}


// address=[0x1363030]
// Decompiled from void __thiscall CGfxManager::GetEffectGfxInfo(CGfxManager *this, struct SGfxObjectInfo *a2, unsigned int _iJob, unsigned int _iDir, unsigned int _iFrame)
void  CGfxManager::GetEffectGfxInfo(struct SGfxObjectInfo & a2, unsigned int _iJob, unsigned int _iDir, unsigned int _iFrame) {
  
  unsigned int v5; // [esp+Ch] [ebp-24h]
  int v6; // [esp+18h] [ebp-18h]
  int v7; // [esp+1Ch] [ebp-14h]
  unsigned int v9; // [esp+28h] [ebp-8h]
  BOOL v10; // [esp+2Ch] [ebp-4h]
  unsigned int iJob; // [esp+3Ch] [ebp+Ch]
  unsigned int _iFramea; // [esp+44h] [ebp+14h]

  if ( _iJob >= 0x64 )
  {
    if ( IGfxEngine::Use4444Palettes(g_pGfxEngine) )
    {
      v6 = 36;
    }
    else
    {
      v6 = 37;
    }
    v9 = v6;
  }
  else
  {
    if ( IGfxEngine::Use4444Palettes(g_pGfxEngine) )
    {
      v7 = 4;
    }
    else
    {
      v7 = 6;
    }
    v9 = v7;
  }
  if ( !this->m_pFileGfxJobs[v9].m_pItem && BBSupportDbgReportF(2, "GfxManager.cpp", 1686, "m_pFileGfxJobs[%d].pItem", v9) == 1 )
  {
    __debugbreak();
  }
  if ( _iJob >= 0x64 )
  {
    if ( _iJob >= 0x74 && BBSupportDbgReportF(2, "GfxManager.cpp", 1694, "_iJob < EFFECT_2_MAX: iJob %u", _iJob) == 1 )
    {
      __debugbreak();
    }
    v10 = _iJob >= 0x74;
  }
  else
  {
    if ( _iJob >= 0x56 && BBSupportDbgReportF(2, "GfxManager.cpp", 1689, "_iJob < EFFECT_MAX: iJob %u", _iJob) == 1 )
    {
      __debugbreak();
    }
    v10 = _iJob >= 0x56;
  }
  if ( _iJob >= 0x64 )
  {
    v5 = _iJob - 100;
  }
  else
  {
    v5 = _iJob;
  }
  iJob = v10 ? 0 : _iJob;
  if ( _iFrame >= CGfxManager::GetEffectFrameCount(this, iJob) && BBSupportDbgReportF(2, "GfxManager.cpp", 1702, "_iFrame < GetEffectFrameCount( _iJob ): Job %u, Dir %u, Frame %u", iJob, _iDir, _iFrame) == 1 )
  {
    __debugbreak();
  }
  _iFramea = _iFrame >= CGfxManager::GetEffectFrameCount(this, iJob) ? 0 : _iFrame;
  a2->m_pGfxData = *(char **)(*(_DWORD *)&this->m_pFileGfxJobs[v9].m_pItem[v5 + 5][4 * _iDir] + 4 * _iFramea);
  if ( !this->m_pFilePalIndex[v9] && BBSupportDbgReport(2, "GfxManager.cpp", 1715, "m_pFilePalIndex[ iGfxFile ]") == 1 )
  {
    __debugbreak();
  }
  a2->m_pPalData = this->m_pFilePalIndex[v9][v5 + 5];
  sprintf(sGfxDebugBuffer, "Effect: %u, Direction: %u, Frame: %u", iJob, _iDir, _iFramea);
  CGfxManager::Debug_Check_LayerBlock(this, v9, a2);
}


// address=[0x13632c0]
// Decompiled from void __thiscall CGfxManager::GetAccessoryGfxInfo(CGfxManager *this, struct SGfxObjectInfo *a2, unsigned int _iAccessory)
void  CGfxManager::GetAccessoryGfxInfo(struct SGfxObjectInfo & a2, unsigned int _iAccessory) {
  
  unsigned int _iAccessorya; // [esp+20h] [ebp+Ch]

  if ( !this->m_pFileGfxFrames[s_iActiveAccGfx].m_pItem && BBSupportDbgReportF(2, "GfxManager.cpp", 1634, "m_pFileGfxFrames[ %u ].pItem", s_iActiveAccGfx) == 1 )
  {
    __debugbreak();
  }
  if ( _iAccessory >= 0x60 && BBSupportDbgReportF(2, "GfxManager.cpp", 1635, "_iAccessory < ACCESSORY_MAX: %u", _iAccessory) == 1 )
  {
    __debugbreak();
  }
  _iAccessorya = _iAccessory >= 0x60 ? 0 : _iAccessory;
  a2->m_pGfxData = **(char ***)this->m_pFileGfxJobs[s_iActiveAccGfx].m_pItem[_iAccessorya + 5];
  if ( !this->m_pFilePalIndex[s_iActiveAccGfx] && BBSupportDbgReport(2, "GfxManager.cpp", 1649, "m_pFilePalIndex[ iGfxFile ]") == 1 )
  {
    __debugbreak();
  }
  a2->m_pPalData = this->m_pFilePalIndex[s_iActiveAccGfx][_iAccessorya + 5];
  sprintf(sGfxDebugBuffer, "Accessory: %u", _iAccessorya);
  CGfxManager::Debug_Check_LayerBlock(this, s_iActiveAccGfx, a2);
}


// address=[0x1363410]
// Decompiled from unsigned int __thiscall CGfxManager::GetSettlerJobFrameCount(CGfxManager *this, unsigned int iRace, unsigned int iJob, unsigned int iDir)
unsigned int  CGfxManager::GetSettlerJobFrameCount(unsigned int iRace, unsigned int iJob, unsigned int iDir) {
  
  return CGfxManager::GetJobFrameCount(this, iRace + 20, iJob, iDir);
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
// Decompiled from unsigned int __thiscall CGfxManager::GetEffectFrameCount(CGfxManager *this, unsigned int a2)
unsigned int  CGfxManager::GetEffectFrameCount(unsigned int a2) {
  
  unsigned int iGfxFile; // [esp+4h] [ebp-10h]
  int v5; // [esp+Ch] [ebp-8h]
  int v6; // [esp+10h] [ebp-4h]

  if ( a2 >= 0x64 )
  {
    if ( IGfxEngine::Use4444Palettes(g_pGfxEngine) )
    {
      v5 = 36;
    }
    else
    {
      v5 = 37;
    }
    iGfxFile = v5;
  }
  else
  {
    if ( IGfxEngine::Use4444Palettes(g_pGfxEngine) )
    {
      v6 = 4;
    }
    else
    {
      v6 = 6;
    }
    iGfxFile = v6;
  }
  if ( a2 >= 0x64 )
  {
    return CGfxManager::GetJobFrameCount(this, iGfxFile, a2 - 100, 0);
  }
  else
  {
    return CGfxManager::GetJobFrameCount(this, iGfxFile, a2, 0);
  }
}


// address=[0x13635a0]
// Decompiled from unsigned int __thiscall CGfxManager::GetBuildingJobFrameCount(CGfxManager *this, unsigned int _iRace, int _iJob)
unsigned int  CGfxManager::GetBuildingJobFrameCount(unsigned int _iRace, unsigned int _iJob) {
  
  return CGfxManager::GetJobFrameCount(this, _iRace + 10, _iJob, 0);
}


// address=[0x13635d0]
// Decompiled from struct SGfxBoundingBox *__thiscall CGfxManager::GetBoundingBox(CGfxManager *this, struct SGfxBoundingBox *a2, unsigned int a3, unsigned int a4, unsigned int a5)
void  CGfxManager::GetBoundingBox(struct SGfxBoundingBox & a2, unsigned int a3, unsigned int a4, unsigned int a5) {
  
  struct SGfxBoundingBox *result; // eax
  float v6; // [esp+0h] [ebp-2F0h]
  float v7; // [esp+4h] [ebp-2ECh]
  float v8; // [esp+8h] [ebp-2E8h]
  float v9; // [esp+Ch] [ebp-2E4h]
  float CurrentZoomFactor; // [esp+14h] [ebp-2DCh]
  struct SGfxObjectInfo v11; // [esp+1Ch] [ebp-2D4h] BYREF

  switch ( a3 )
  {
    case SETTLER_OBJ:
      CGfxManager::GetSettlerGfxInfo(this, &v11, a4, a5, 1u, 0);
      v9 = FLOAT_25_0;
      v8 = (float)v11.m_pGfxData[1];
      v7 = 25.0 / 2.0;
      v6 = (float)v11.m_pGfxData[3];
      break;
    case SHIP_OBJ:
    case CATAPULT_OBJ:
    case BUILDING_OBJ:
      if ( a3 == BUILDING_OBJ )
      {
        CGfxManager::GetBuildingGfxInfo(this, &v11, a4, a5, 1, 0);
      }
      else
      {
        CGfxManager::GetVehicleGfxInfo(this, &v11, a4, a5, 0, 0, 0, 0);
      }
      v9 = (float)*(unsigned __int16 *)v11.m_pGfxData;
      v8 = (float)*((unsigned __int16 *)v11.m_pGfxData + 1);
      v7 = (float)*((__int16 *)v11.m_pGfxData + 2);
      v6 = (float)*((__int16 *)v11.m_pGfxData + 3);
      break;
    default:
      break;
  }
  CurrentZoomFactor = IGfxEngine::GetCurrentZoomFactor(g_pGfxEngine);
  *((_DWORD *)a2 + 1) = (int)(float)(v8 * CurrentZoomFactor);
  *(_DWORD *)a2 = (int)(float)(v9 * CurrentZoomFactor);
  result = a2;
  *((_DWORD *)a2 + 2) = (int)(float)(v7 * CurrentZoomFactor);
  *((_DWORD *)a2 + 3) = (int)(float)(v6 * CurrentZoomFactor);
  return result;
}


// address=[0x13637e0]
// Decompiled from char __thiscall CGfxManager::EnableGfxFile(CGfxManager *this, unsigned int _iGfxFile, int _iType, BYTE _bMapFile, int _iFileVersion)
bool  CGfxManager::EnableGfxFile(unsigned int _iGfxFile, int _iType, bool _bMapFile, unsigned int _iFileVersion) {
  
  char result; // al

  BBSupportTracePrintF(2, "GfxManager.cpp: Enabling GfxFile %d", _iGfxFile);
  switch ( _iType )
  {
    case 0:
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
      if ( !CGfxManager::LoadGfxFile(this, _iGfxFile, _bMapFile, _iFileVersion) )
      {
        result = 0;
      }
      else if ( !CGfxManager::LoadGilFile(this, _iGfxFile, _iFileVersion) )
      {
        result = 0;
      }
      else if ( !CGfxManager::LoadDilFile(this, _iGfxFile, _iFileVersion) )
      {
        result = 0;
      }
      else if ( !CGfxManager::LoadJilFile(this, _iGfxFile, _iFileVersion) )
      {
        result = 0;
      }
      else if ( !CGfxManager::LoadSilFile(this, _iGfxFile, _iFileVersion) )
      {
        result = 0;
      }
      else if ( CGfxManager::LoadPalFile(this, _iGfxFile, _iFileVersion, 0) )
      {
        if ( CGfxManager::LoadPilFile(this, _iGfxFile, _iFileVersion, 0) )
        {
          goto LABEL_52;
        }
        result = 0;
      }
      else
      {
        result = 0;
      }
      break;
    case 2:
      if ( !CGfxManager::LoadGfxFile(this, _iGfxFile, _bMapFile, _iFileVersion) )
      {
        result = 0;
      }
      else if ( !CGfxManager::LoadGilFile(this, _iGfxFile, _iFileVersion) )
      {
        result = 0;
      }
      else if ( !CGfxManager::LoadDilFile(this, _iGfxFile, _iFileVersion) )
      {
        result = 0;
      }
      else if ( !CGfxManager::LoadJilFile(this, _iGfxFile, _iFileVersion) )
      {
        result = 0;
      }
      else if ( CGfxManager::LoadPalFile(this, _iGfxFile, _iFileVersion, 0) )
      {
        if ( CGfxManager::LoadPilFile(this, _iGfxFile, _iFileVersion, 0) )
        {
          goto LABEL_52;
        }
        result = 0;
      }
      else
      {
        result = 0;
      }
      break;
    case 8:
      if ( !CGfxManager::LoadGfxFile(this, _iGfxFile, _bMapFile, _iFileVersion) )
      {
        result = 0;
      }
      else if ( !CGfxManager::LoadGilFile(this, _iGfxFile, _iFileVersion) )
      {
        result = 0;
      }
      else if ( !CGfxManager::LoadPalFile(this, _iGfxFile, _iFileVersion, 0) )
      {
        result = 0;
      }
      else
      {
        if ( CGfxManager::LoadPilFile(this, _iGfxFile, _iFileVersion, 0) )
        {
          goto LABEL_52;
        }
        result = 0;
      }
      break;
    case 9:
      if ( !CGfxManager::LoadGfxFile(this, _iGfxFile, _bMapFile, _iFileVersion) )
      {
        result = 0;
      }
      else if ( !CGfxManager::LoadGilFile(this, _iGfxFile, _iFileVersion) )
      {
        result = 0;
      }
      else if ( !CGfxManager::LoadPalFile(this, _iGfxFile, _iFileVersion, 1) )
      {
        result = 0;
      }
      else
      {
        if ( CGfxManager::LoadPilFile(this, _iGfxFile, _iFileVersion, 1) )
        {
          this->m_iActiveGfxFile = _iGfxFile;
          goto LABEL_52;
        }
        result = 0;
      }
      break;
    case 10:
      if ( CGfxManager::LoadGfxFile(this, _iGfxFile, _bMapFile, _iFileVersion) )
      {
LABEL_52:
        result = 1;
      }
      else
      {
        result = 0;
      }
      break;
    default:
      result = 0;
      break;
  }
  return result;
}


// address=[0x1363b20]
// Decompiled from char *__cdecl CGfxManager::Reload(int a1, BYTE a2, bool a3)
void * __cdecl CGfxManager::Reload(int a1, bool a2, bool a3) {
  
  char *pPileGfx; // [esp+4h] [ebp-4h]

  pPileGfx = 0;
  if ( !g_pGfxManager )
  {
    return 0;
  }
  g_pGfxManager->m_bUse6Palette = !a3;
  g_pGfxManager->m_bUseHighPalette = a2;
  if ( g_pGfxManager->m_sFileGfx[7].pPileGfx )
  {
    CGfxManager::MoveAccessoriesToGfxEngine(g_pGfxManager);
  }
  if ( g_pGfxManager->m_sFileGfx[5].pPileGfx )
  {
    CGfxManager::MoveWavesToGfxEngine(g_pGfxManager);
  }
  if ( a1 == 1 )
  {
    if ( g_pGfxManager->m_bUseHighTerrain )
    {
      if ( !CGfxManager::EnableGfxFile(g_pGfxManager, 0x29u, 10, 1u, -1) && BBSupportDbgReport(1, "GfxManager.cpp", 2234, aCouldNotOpenAl_1) == 1 )
      {
        __debugbreak();
      }
      pPileGfx = g_pGfxManager->m_sFileGfx[41].pPileGfx;
      if ( !pPileGfx && BBSupportDbgReport(1, "GfxManager.cpp", 2237, aCouldNotOpenAl_2) == 1 )
      {
        __debugbreak();
      }
    }
    else
    {
      if ( !CGfxManager::EnableGfxFile(g_pGfxManager, 2u, 10, 1u, -1) && BBSupportDbgReport(1, "GfxManager.cpp", 2242, aCouldNotOpenAl) == 1 )
      {
        __debugbreak();
      }
      pPileGfx = g_pGfxManager->m_sFileGfx[2].pPileGfx;
      if ( !pPileGfx && BBSupportDbgReport(1, "GfxManager.cpp", 2245, aCouldNotOpenAl_0) == 1 )
      {
        __debugbreak();
      }
    }
    if ( pPileGfx )
    {
      pPileGfx += 20;
    }
  }
  else if ( !a1 )
  {
    if ( g_pGfxManager->m_bUseHighTerrain )
    {
      CGfxManager::DisableGfxFile(g_pGfxManager, 41);
    }
    else
    {
      CGfxManager::DisableGfxFile(g_pGfxManager, 2);
    }
  }
  return pPileGfx;
}


// address=[0x1363d10]
// Decompiled from unsigned int __thiscall CGfxManager::GetJobFrameCount(CGfxManager *this, unsigned int _iGfxFile, unsigned int _iJob, unsigned int _iDir)
unsigned int  CGfxManager::GetJobFrameCount(unsigned int _iGfxFile, unsigned int _iJob, unsigned int _iDir) {
  
  int v6; // [esp+30h] [ebp-28h]
  char *v7; // [esp+34h] [ebp-24h]
  char *v8; // [esp+38h] [ebp-20h]
  char *v9; // [esp+40h] [ebp-18h]
  char *v10; // [esp+44h] [ebp-14h]
  unsigned int i; // [esp+48h] [ebp-10h]
  unsigned int iDir; // [esp+4Ch] [ebp-Ch]
  char *v13; // [esp+50h] [ebp-8h]
  char *v14; // [esp+50h] [ebp-8h]

  if ( _iGfxFile == this->m_iActiveGfxFile )
  {
    return 1;
  }
  if ( this->m_pFileGfxJobs[_iGfxFile].m_pItem )
  {
    if ( _iDir >= 6 && BBSupportDbgReport(2, "GfxManager.cpp", 1203, "_iDir < 6") == 1 )
    {
      __debugbreak();
    }
    if ( _iGfxFile < 0xA || _iGfxFile >= 0x14 )
    {
      if ( _iJob >= this->m_pFileGfxJobs[_iGfxFile].m_iCount )
      {
        BBSupportTracePrintF(2, "GfxManager: Invalid Job#%d for GfxFile#%d and Direction#%d", _iJob, _iGfxFile, _iDir);
        _iJob = 0;
      }
      v8 = (char *)*((_DWORD *)this->m_pFileGfxJobs[_iGfxFile].m_pItem + 5);
      v6 = *((_DWORD *)this->m_pFileGfxDirections[_iGfxFile].m_pItem + 5);
      iDir = _iDir;
      v13 = this->m_pFileGfxJobs[_iGfxFile].m_pItem[_iJob + 5];
      if ( v13 == v8 )
      {
        return 1;
      }
      else
      {
        v14 = &v13[4 * _iDir];
        v10 = v14;
        if ( *(_DWORD *)v14 == v6 )
        {
          return 1;
        }
        else
        {
          do
          {
            if ( ++iDir == CGfxManager::GetNrDirection(this, _iGfxFile) )
            {
              if ( ++_iJob >= this->m_pFileGfxJobs[_iGfxFile].m_iCount )
              {
                return this->m_pFileGfxFrames[_iGfxFile].m_iCount - ((*(_DWORD *)v14 - (unsigned int)(this->m_pFileGfxFrames[_iGfxFile].m_pItem + 5)) >> 2);
              }
              iDir = 0;
            }
            v7 = this->m_pFileGfxJobs[_iGfxFile].m_pItem[_iJob + 5];
            if ( v7 == v8 )
            {
              iDir = -1;
              if ( ++_iJob >= this->m_pFileGfxJobs[_iGfxFile].m_iCount )
              {
                return this->m_pFileGfxFrames[_iGfxFile].m_iCount - ((*(_DWORD *)v14 - (unsigned int)(this->m_pFileGfxFrames[_iGfxFile].m_pItem + 5)) >> 2);
              }
            }
            else
            {
              v10 = &v7[4 * iDir];
            }
          }
          while ( *(_DWORD *)v10 == v6 || *(_DWORD *)v10 == *(_DWORD *)v14 );
          if ( (unsigned int)(*(_DWORD *)v10 - *(_DWORD *)v14) >> 2 )
          {
            return (unsigned int)(*(_DWORD *)v10 - *(_DWORD *)v14) >> 2;
          }
          else
          {
            return 1;
          }
        }
      }
    }
    else
    {
      if ( _iJob >= this->m_pFileGfxDirections[_iGfxFile].m_iCount )
      {
        BBSupportTracePrintF(2, "GfxManager: Invalid Job#%d for GfxFile#%d and Direction#%d", _iJob, _iGfxFile, _iDir);
        _iJob = 0;
      }
      v9 = 0;
      for ( i = _iJob + 1;
            i < this->m_pFileGfxDirections[_iGfxFile].m_iCount;
            ++i )
      {
        if ( this->m_pFileGfxDirections[_iGfxFile].m_pItem[i + 5] != (char *)this->m_pFileGfxFrames[_iGfxFile].m_pItem + 20 )
        {
          v9 = this->m_pFileGfxDirections[_iGfxFile].m_pItem[i + 5];
          break;
        }
      }
      if ( !v9 )
      {
        v9 = (char *)this->m_pFileGfxFrames[_iGfxFile].m_pItem + this->m_pFileGfxFrames[_iGfxFile].m_iCount + 5;
      }
      return (unsigned int)(v9 - this->m_pFileGfxDirections[_iGfxFile].m_pItem[_iJob + 5]) >> 2;
    }
  }
  else
  {
    if ( byte_3ECDBF4[_iGfxFile] )
    {
      return 1;
    }
    byte_3ECDBF4[_iGfxFile] = 1;
    BBSupportTracePrintF(2, "GfxManager.cpp: !!! GetJobFrameCount() for unloaded gfx %d file called !!", _iGfxFile);
    return 1;
  }
}


// address=[0x13640d0]
// Decompiled from bool __thiscall CGfxManager::IsDirectionAvailable(CGfxManager *this, unsigned int _iGfxFile, int a3, int a4)
bool  CGfxManager::IsDirectionAvailable(unsigned int _iGfxFile, unsigned int a3, unsigned int a4) {
  
  if ( _iGfxFile == this->m_iActiveGfxFile )
  {
    return a4 == 0;
  }
  if ( _iGfxFile < 0xA || _iGfxFile >= 0x13 )
  {
    if ( *(_DWORD *)&this->m_pFileGfxJobs[_iGfxFile].m_pItem[a3 + 5][4 * a4] == *(_DWORD *)(*(_DWORD *)&this->m_pFileGfxDirections[8 * _iGfxFile] + 20) )
    {
      return 0;
    }
  }
  else
  {
    if ( a4 )
    {
      return 0;
    }
    if ( *(char ***)(*(_DWORD *)&this->m_pFileGfxDirections[8 * _iGfxFile] + 4 * a3 + 20) == this->m_pFileGfxFrames[_iGfxFile].m_pItem + 5 )
    {
      return 0;
    }
  }
  return 1;
}


// address=[0x1364190]
// Decompiled from void __thiscall CGfxManager::GetRawGfxInfo(CGfxManager *this, SGfxObjectInfo *a2, unsigned int a3, unsigned int a4, int a5, int a6)
void  CGfxManager::GetRawGfxInfo(struct SGfxObjectInfo & a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6) {
  
  int v6; // [esp+0h] [ebp-1Ch] BYREF
  int v7; // [esp+4h] [ebp-18h] BYREF
  int v8; // [esp+8h] [ebp-14h] BYREF
  int v9; // [esp+Ch] [ebp-10h] BYREF
  unsigned int v10; // [esp+10h] [ebp-Ch]
  int v11; // [esp+14h] [ebp-8h]

  if ( !this->m_pFileGfxJobs[a3].m_pItem && BBSupportDbgReport(2, "GfxManager.cpp", 2419, "m_pFileGfxJobs[ _iGfxFile ].pItem") == 1 )
  {
    __debugbreak();
  }
  if ( a4 >= 0x16E )
  {
    a4 = 0;
  }
  if ( a3 < 0xA || a3 >= 0x13 )
  {
    dword_3ECDD78 = (int)this->m_pFileGfxJobs[a3].m_pItem[a4 + 5];
    dword_3ECDD7C = *(_DWORD *)(dword_3ECDD78 + 4 * a5);
    dword_3ECDD78 = *(_DWORD *)(dword_3ECDD7C + 4 * a6);
    a2->m_pGfxData = (BYTE *)dword_3ECDD78;
    if ( !this->m_pFilePalIndex[a3] && BBSupportDbgReport(2, "GfxManager.cpp", 2454, "m_pFilePalIndex[ _iGfxFile ]") == 1 )
    {
      __debugbreak();
    }
    a2->m_pPalData = this->m_pFilePalIndex[a3][a4 + 5];
  }
  else
  {
    dword_3ECDD78 = *(_DWORD *)(*(_DWORD *)&this->m_pFileGfxDirections[8 * a3] + 4 * a4 + 20);
    dword_3ECDD7C = *(_DWORD *)(dword_3ECDD78 + 4 * a6);
    v11 = dword_3ECDD78 + 4 * a6;
    v10 = (signed int)(v11 - (unsigned int)(this->m_pFileGfxFrames[a3].m_pItem + 5)) >> 2;
    a2->m_pGfxData = (BYTE *)dword_3ECDD7C;
    if ( !this->m_pFilePalIndex[a3] && BBSupportDbgReport(2, "GfxManager.cpp", 2439, "m_pFilePalIndex[ _iGfxFile ]") == 1 )
    {
      __debugbreak();
    }
    CGfxManager::GetImageInfo(this, a3, v10, &v9, &v6, &v7, &v8);
    a2->m_pPalData = this->m_pFilePalIndex[a3][v9 + 5];
  }
}


// address=[0x1364360]
// Decompiled from char __thiscall CGfxManager::GetRawGfxInfo_0(CGfxManager *this, _DWORD *a2, unsigned int a3, unsigned int a4)
void  CGfxManager::GetRawGfxInfo(struct SGfxObjectInfo & a2, unsigned int a3, unsigned int a4) {
  
  char *v4; // eax
  int v6; // [esp+0h] [ebp-14h] BYREF
  int v7; // [esp+4h] [ebp-10h] BYREF
  int v8; // [esp+8h] [ebp-Ch] BYREF
  int v9; // [esp+Ch] [ebp-8h] BYREF

  if ( a4 >= this->m_pFileGfxFrames[a3].m_iCount && BBSupportDbgReport(2, "GfxManager.cpp", 2465, "_iGfxID < m_pFileGfxFrames[ _iGfxFile ].iCount") == 1 )
  {
    __debugbreak();
  }
  *a2 = this->m_pFileGfxFrames[a3].m_pItem[a4 + 5];
  if ( !this->m_pFilePalIndex[a3] && BBSupportDbgReport(2, "GfxManager.cpp", 2473, "m_pFilePalIndex[ _iGfxFile ]") == 1 )
  {
    __debugbreak();
  }
  LOBYTE(v4) = CGfxManager::GetImageInfo(this, a3, a4, &v9, &v6, &v7, &v8);
  if ( v9 == -1 )
  {
    return (char)v4;
  }
  v4 = this->m_pFilePalIndex[a3][v9 + 5];
  a2[1] = v4;
  return (char)v4;
}


// address=[0x1364430]
// Decompiled from char __thiscall CGfxManager::GetImageInfo(CGfxManager *this, unsigned int _iGfxFile, unsigned int a3, int *a4, unsigned int *a5, unsigned int *a6, int *a7)
bool  CGfxManager::GetImageInfo(unsigned int _iGfxFile, unsigned int a3, int & a4, int & a5, int & a6, int & a7) {
  
  unsigned int v8; // [esp+18h] [ebp-20h]
  unsigned int i; // [esp+1Ch] [ebp-1Ch]
  unsigned int k; // [esp+24h] [ebp-14h]
  unsigned int v11; // [esp+28h] [ebp-10h]
  unsigned int v12; // [esp+2Ch] [ebp-Ch]
  unsigned int m; // [esp+30h] [ebp-8h]
  unsigned int j; // [esp+30h] [ebp-8h]

  *a5 = -1;
  if ( _iGfxFile == this->m_iActiveGfxFile )
  {
    *a4 = a3;
    return 1;
  }
  else
  {
    *a4 = -1;
    if ( _iGfxFile < 0xA || _iGfxFile >= 0x14 )
    {
      v8 = 0;
LABEL_30:
      if ( v8 >= this->m_pFileGfxJobs[_iGfxFile].m_iCount )
      {
        if ( *a5 == -1 )
        {
          *a5 = this->m_pFileGfxJobs[_iGfxFile].m_iCount - 1;
          *a6 = *(_DWORD *)&this->m_pFileGfxDirections[8 * _iGfxFile + 4] - 1;
          *a7 = CGfxManager::GetJobFrameCount(this, _iGfxFile, *a5, *a6) - 1;
        }
        if ( CGfxManager::HasSil(this, _iGfxFile) )
        {
          *a4 = this->m_pFileGfxJobCodes[_iGfxFile].m_iCount - 1;
        }
        else
        {
          *a4 = -1;
        }
        return 1;
      }
      else
      {
        for ( i = 0;
              ;
              ++i )
        {
          if ( i >= CGfxManager::GetNrDirection(this, _iGfxFile) - 1 )
          {
            ++v8;
            goto LABEL_30;
          }
          v12 = (signed int)(*(_DWORD *)&this->m_pFileGfxJobs[_iGfxFile].m_pItem[v8 + 5][4 * i] - (unsigned int)(this->m_pFileGfxFrames[_iGfxFile].m_pItem + 5)) / 4;
          if ( v12 >= a3 )
          {
            break;
          }
        }
        *a6 = i;
        *a5 = v8;
        if ( v12 != a3 )
        {
          if ( *a6 )
          {
            --*a6;
          }
          else
          {
            --*a5;
          }
        }
        *a7 = a3 - (signed int)(*(_DWORD *)&this->m_pFileGfxJobs[_iGfxFile].m_pItem[*a5 + 5][4 * *a6] - (unsigned int)(this->m_pFileGfxFrames[_iGfxFile].m_pItem + 5)) / 4;
        if ( CGfxManager::HasSil(this, _iGfxFile) )
        {
          for ( j = 0;
                j < this->m_pFileGfxJobCodes[_iGfxFile].m_iCount;
                ++j )
          {
            if ( (unsigned int)(this->m_pFileGfxJobCodes[_iGfxFile].m_pItem[j + 5] - 20) >> 2 > *a5 )
            {
              *a4 = j - 1;
              break;
            }
          }
          if ( *a4 == -1 )
          {
            *a4 = j - 1;
          }
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
      for ( k = 0;
            ;
            ++k )
      {
        if ( k >= *(_DWORD *)&this->m_pFileGfxDirections[8 * _iGfxFile + 4] )
        {
          if ( *a5 == -1 )
          {
            *a5 = *(_DWORD *)&this->m_pFileGfxDirections[8 * _iGfxFile + 4] - 1;
            *a6 = 0;
            *a7 = CGfxManager::GetJobFrameCount(this, _iGfxFile, *a5, *a6) - 1;
          }
          if ( CGfxManager::HasSil(this, _iGfxFile) )
          {
            *a4 = this->m_pFileGfxJobs[_iGfxFile].m_iCount - 1;
          }
          else
          {
            *a4 = -1;
          }
          return 1;
        }
        v11 = (signed int)(*(_DWORD *)(*(_DWORD *)&this->m_pFileGfxDirections[8 * _iGfxFile] + 4 * k + 20) - (unsigned int)(this->m_pFileGfxFrames[_iGfxFile].m_pItem + 5)) / 4;
        if ( v11 >= a3 )
        {
          break;
        }
      }
      *a5 = k;
      if ( v11 != a3 )
      {
        --*a5;
        while ( *(char ***)(*(_DWORD *)&this->m_pFileGfxDirections[8 * _iGfxFile] + 4 * *a5 + 20) == this->m_pFileGfxFrames[_iGfxFile].m_pItem + 5 )
        {
          --*a5;
        }
      }
      if ( CGfxManager::HasSil(this, _iGfxFile) )
      {
        for ( m = 0;
              m < this->m_pFileGfxJobs[_iGfxFile].m_iCount;
              ++m )
        {
          if ( (int)&this->m_pFileGfxJobs[_iGfxFile].m_pItem[m + 5][-*(_DWORD *)&this->m_pFileGfxDirections[8 * _iGfxFile] - 20] / 4 > (int)*a5 )
          {
            *a4 = m - 1;
            break;
          }
        }
        if ( *a4 == -1 )
        {
          *a4 = m - 1;
        }
      }
      else
      {
        *a4 = -1;
      }
      *a7 = 0;
      *a7 = (signed int)(*(_DWORD *)(*(_DWORD *)&this->m_pFileGfxDirections[8 * _iGfxFile] + 4 * *a5 + 20) - (unsigned int)(this->m_pFileGfxFrames[_iGfxFile].m_pItem + 5)) / 4 - a3;
      *a6 = 0;
      return 1;
    }
  }
}


// address=[0x1364940]
// Decompiled from char __thiscall CGfxManager::GetImageInfo_0(CGfxManager *this, unsigned int a2, unsigned int a3, int *a4, int *a5, int *a6)
bool  CGfxManager::GetImageInfo(unsigned int a2, unsigned int a3, int & a4, int & a5, int & a6) {
  
  int v7; // [esp+4h] [ebp-4h] BYREF

  v7 = 0;
  return CGfxManager::GetImageInfo(this, a2, a3, &v7, a4, a5, a6);
}


// address=[0x1364980]
// Decompiled from char __thiscall CGfxManager::GetJobIndices(CGfxManager *this, unsigned int _iGfxFile, unsigned int a3, unsigned int *a4, int *a5)
bool  CGfxManager::GetJobIndices(unsigned int _iGfxFile, unsigned int a3, int & a4, int & a5) {
  
  int i; // [esp+0h] [ebp-Ch]
  int j; // [esp+4h] [ebp-8h]

  if ( !g_bSilPerFile[_iGfxFile] && BBSupportDbgReport(2, "GfxManager.cpp", 2271, "g_bSilPerFile[ _iGfxFile ]") == 1 )
  {
    __debugbreak();
  }
  if ( _iGfxFile < 0xA || _iGfxFile >= 0x14 )
  {
    *a4 = (unsigned int)(this->m_pFileGfxJobCodes[_iGfxFile].m_pItem[a3 + 5] - 20) >> 2;
    if ( a3 == this->m_pFileGfxJobCodes[_iGfxFile].m_iCount - 1 )
    {
      *a5 = this->m_pFileGfxJobs[_iGfxFile].m_iCount;
    }
    else
    {
      *a5 = ((unsigned int)(this->m_pFileGfxJobCodes[_iGfxFile].m_pItem[a3 + 6] - 20) >> 2) - 1;
    }
    for ( i = *a4;
          i <= *a5;
          ++i )
    {
      if ( (char *)*((_DWORD *)this->m_pFileGfxJobs[_iGfxFile].m_pItem + 5) != this->m_pFileGfxJobs[_iGfxFile].m_pItem[i + 5] )
      {
        return 1;
      }
    }
  }
  else
  {
    *a4 = (unsigned int)this->m_pFileGfxJobs[_iGfxFile].m_pItem[a3 + 5];
    *a4 -= *(_DWORD *)&this->m_pFileGfxDirections[8 * _iGfxFile] + 20;
    *a4 = (int)*a4 / 4;
    if ( a3 == this->m_pFileGfxJobs[_iGfxFile].m_iCount - 1 )
    {
      *a5 = *(_DWORD *)&this->m_pFileGfxDirections[8 * _iGfxFile + 4];
    }
    else
    {
      *a5 = (int)this->m_pFileGfxJobs[_iGfxFile].m_pItem[a3 + 6];
      *a5 -= *(_DWORD *)&this->m_pFileGfxDirections[8 * _iGfxFile] + 20;
      *a5 /= 4;
      --*a5;
    }
    for ( j = *a4;
          j <= *a5;
          ++j )
    {
      if ( *(_DWORD *)(*(_DWORD *)&this->m_pFileGfxDirections[8 * _iGfxFile] + 20) != *(_DWORD *)(*(_DWORD *)&this->m_pFileGfxDirections[8 * _iGfxFile] + 4 * j + 20) )
      {
        return 1;
      }
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
  
  return s_iDirectionNumbers[a2];
}


// address=[0x136a200]
// Decompiled from char __thiscall CGfxManager::HasSil(CGfxManager *this, unsigned int a2)
bool  CGfxManager::HasSil(unsigned int a2) {
  
  return g_bSilPerFile[a2];
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
  CFileEx *v5; // [esp+38h] [ebp-18h]
  CFileEx *m_pFile; // [esp+3Ch] [ebp-14h]
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
  {
    v3 = 42;
  }
  else
  {
    v3 = a2 + 1;
  }
  for ( i = v4;
        i < v3;
        ++i )
  {
    if ( this->m_sFileGfx[i].pPileGfx )
    {
      if ( this->m_sFileGfx[i].m_bFileMapped == 1 )
      {                                         // IFileEx.Close
        ((void (__thiscall *)(char *, const char *, int))(*(vbtable::CFileEx **)((char *)&this->m_sFileGfx[i].m_pFile->m_pVbtable + (unsigned int)this->m_sFileGfx[i].m_pFile->m_pVbtable->offsetIFileEx))[2].offsetCFile)((char *)&this->m_sFileGfx[i].m_pFile->m_pVbtable + (unsigned int)this->m_sFileGfx[i].m_pFile->m_pVbtable->offsetIFileEx, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\FileEx.h", 146);
        m_pFile = this->m_sFileGfx[i].m_pFile;
        if ( m_pFile )
        {
          m_pFile->CFile.dtor(m_pFile, 1);
        }
      }
      else
      {
        operator delete[](this->m_sFileGfx[i].pPileGfx);
      }
      this->m_sFileGfx[i].m_bFileMapped = 0;
      this->m_sFileGfx[i].m_pFile = 0;
      this->m_sFileGfx[i].pPileGfx = 0;
    }
    if ( this->m_sFilePal[i].pPileGfx )
    {                                           // Close()
      ((void (__thiscall *)(char *, const char *, int))(*(vbtable::CFileEx **)((char *)&this->m_sFilePal[i].m_pFile->m_pVbtable + (unsigned int)this->m_sFilePal[i].m_pFile->m_pVbtable->offsetIFileEx))[2].offsetCFile)((char *)&this->m_sFilePal[i].m_pFile->m_pVbtable + (unsigned int)this->m_sFilePal[i].m_pFile->m_pVbtable->offsetIFileEx, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\FileEx.h", 146);
      v5 = this->m_sFilePal[i].m_pFile;
      if ( v5 )
      {
        v5->CFile.dtor(v5, 1);
      }
      this->m_sFilePal[i].m_bFileMapped = 0;
      this->m_sFilePal[i].m_pFile = 0;
      this->m_sFilePal[i].pPileGfx = 0;
    }
    if ( this->m_pFilePalIndex[i] )
    {
      operator delete[](this->m_pFilePalIndex[i]);
      this->m_pFilePalIndex[i] = 0;
    }
    if ( this->m_pFileGfxFrames[i].m_pItem )
    {
      operator delete[](this->m_pFileGfxFrames[i].m_pItem);
      this->m_pFileGfxFrames[i].m_pItem = 0;
    }
    if ( this->m_pFileGfxDirections[i].m_pItem )
    {
      operator delete[](this->m_pFileGfxDirections[i].m_pItem);
      this->m_pFileGfxDirections[i].m_pItem = 0;
    }
    if ( this->m_pFileGfxJobs[i].m_pItem )
    {
      operator delete[](this->m_pFileGfxJobs[i].m_pItem);
      this->m_pFileGfxJobs[i].m_pItem = 0;
    }
    if ( this->m_pFileGfxJobCodes[i].m_pItem )
    {
      operator delete[](this->m_pFileGfxJobCodes[i].m_pItem);
      this->m_pFileGfxJobCodes[i].m_pItem = 0;
    }
  }
  if ( a2 != -1 && a2 == this->m_iActiveGfxFile )
  {
    this->m_iActiveGfxFile = -1;
  }
  return 1;
}


// address=[0x1364f80]
// Decompiled from void __stdcall CGfxManager::ErrorMessageBox(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
void  CGfxManager::ErrorMessageBox(class String a1) {
  
  HWND ActiveWindow; // eax
  const CHAR *v8; // [esp-Ch] [ebp-20h]

  v8 = (const CHAR *)String::c_str((String *)&a1);
  ActiveWindow = GetActiveWindow();
  MessageBoxA(ActiveWindow, v8, "Error!", 0x30u);
  String::~String((String *)&a1);
}


// address=[0x1364ff0]
// Decompiled from int *__thiscall CGfxManager::LoadFile(CGfxManager *this, std::wstring a2, unsigned int *a3, unsigned int a4)
void *  CGfxManager::LoadFile(std::wstring a2, unsigned long * a3, unsigned int a4) {
  
  wchar_t *v4; // eax
  wchar_t *v5; // eax
  wchar_t *v7; // eax
  char *v8; // eax
  int v9[5]; // [esp-1Ch] [ebp-154h] BYREF
  unsigned int v10; // [esp-8h] [ebp-140h]
  int v11; // [esp-4h] [ebp-13Ch]
  _DWORD v12[7]; // [esp+0h] [ebp-138h] BYREF
  void *v15; // [esp+28h] [ebp-110h] MAPDST
  int *v16; // [esp+2Ch] [ebp-10Ch]
  signed int v17; // [esp+30h] [ebp-108h]
  size_t Size; // [esp+3Ch] [ebp-FCh]
  char v22[88]; // [esp+44h] [ebp-F4h] BYREF
  CFileEx v23; // [esp+9Ch] [ebp-9Ch] BYREF
  std::string v24; // [esp+108h] [ebp-30h] BYREF
  _DWORD *v25; // [esp+128h] [ebp-10h]
  int v26; // [esp+134h] [ebp-4h]

  v25 = v12;
  v26 = 1;
  v12[6] = CFileEx::CFileEx(&v23, UNUSED_ARG());
  LOBYTE(v26) = 2;
  v4 = std::wstring::c_str(&a2);
  CFileEx::Open(&v23.IFileEx, v4, CFile_BINARY|CFile_READ, 0, UNUSED_ARG(), UNUSED_ARG());
  v17 = CFileEx::Size(&v23);
  Size = v17;
  if ( v17 > 0 )
  {
    v15 = operator new[](Size);
    CFileEx::Read(&v23.IFileEx.__vftable, v15, 1, Size, UNUSED_ARG(), UNUSED_ARG());
    CFileEx::Close(&v23.IFileEx, UNUSED_ARG(), UNUSED_ARG());
    if ( a3 )
    {
      *a3 = Size;
    }
    LOBYTE(v26) = 1;
    CFileEx::~CFileEx(&v23);
    v26 = 0;
    if ( a4 != -1 && *((_DWORD *)v15 + 4) != a4 )
    {
      v11 = *((_DWORD *)v15 + 4);
      v10 = a4;
      v7 = std::wstring::c_str(&a2);
      BBSupportTracePrintF(2, "Version incorrect for file \"%s\"!\nNeeded: %d, Got: %d !", (const char *)v7, v10, v11);
      if ( !byte_3ECDBF0 )
      {
        String::operator=(&this->m_sLastError, "Wrong version of file \"");
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v22);
        LOBYTE(v26) = 4;
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(&v24, &a2);
        LOBYTE(v26) = 5;
        v8 = std::string::c_str(&v24);
        String::operator+=(&this->m_sLastError, v8);
        String::operator+=(&this->m_sLastError, "\"!");
        v12[5] = v9;
        v12[4] = String::String((String *)v9, (const struct String *)&this->m_sLastError, 0, 0xFFFFFFFF);
        CGfxManager::ErrorMessageBox(this, v9[0], v9[1], v9[2], v9[3], v9[4], v10, v11);
        byte_3ECDBF0 = 1;
        LOBYTE(v26) = 4;
        std::string::~string(&v24);
        LOBYTE(v26) = 0;
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v22);
      }
    }
    v26 = -1;
    std::wstring::~wstring(&a2);
    return (int *)v15;
  }
  else
  {
    v5 = std::wstring::c_str(&a2);
    BBSupportTracePrintF(2, "CGfxManager::LoadFile : Couldn't get size of : %s", (const char *)v5);
    v16 = 0;
    LOBYTE(v26) = 1;
    CFileEx::~CFileEx(&v23);
    v26 = -1;
    std::wstring::~wstring(&a2);
    return v16;
  }
}


// address=[0x1365310]
// Decompiled from CFileEx *__thiscall CGfxManager::MapFullFile(CGfxManager *this, std::wstring a2, int _iFileVersion)
class CFileEx *  CGfxManager::MapFullFile(std::wstring a2, unsigned int _iFileVersion) {
  
  wchar_t *v3; // eax
  wchar_t *v4; // eax
  char *v5; // eax
  wchar_t *v7; // eax
  char *v8; // eax
  int v9; // [esp-1Ch] [ebp-16Ch] BYREF
  int v10; // [esp-18h] [ebp-168h]
  int v11; // [esp-14h] [ebp-164h]
  int v12; // [esp-10h] [ebp-160h]
  int v13; // [esp-Ch] [ebp-15Ch]
  int v14; // [esp-8h] [ebp-158h]
  DWORD LastError; // [esp-4h] [ebp-154h]
  _DWORD v16[8]; // [esp+0h] [ebp-150h] BYREF
  CFileEx *v17; // [esp+20h] [ebp-130h]
  CFileEx *v18; // [esp+24h] [ebp-12Ch]
  int v19; // [esp+28h] [ebp-128h]
  CFileEx *v20; // [esp+2Ch] [ebp-124h]
  int pMapFile; // [esp+3Ch] [ebp-114h] MAPDST
  CFileEx *v24; // [esp+40h] [ebp-110h] MAPDST
  void *C; // [esp+44h] [ebp-10Ch]
  CFileEx *v26; // [esp+48h] [ebp-108h]
  CGfxManager *v27; // [esp+4Ch] [ebp-104h]
  char v29[88]; // [esp+54h] [ebp-FCh] BYREF
  char v30[88]; // [esp+ACh] [ebp-A4h] BYREF
  std::string v31; // [esp+104h] [ebp-4Ch] BYREF
  std::string v32; // [esp+120h] [ebp-30h] BYREF
  _DWORD *v33; // [esp+140h] [ebp-10h]
  int v34; // [esp+14Ch] [ebp-4h]

  v33 = v16;
  v27 = this;
  v34 = 0;
  C = operator new(0x6Cu);
  LOBYTE(v34) = 1;
  if ( C )
  {
    v24 = CFileEx::CFileEx((CFileEx *)C, UNUSED_ARG());
  }
  else
  {
    v24 = 0;
  }
  LOBYTE(v34) = 2;
  v3 = std::wstring::c_str(&a2);                // Call to IFileEx.Open(std::wstring const &a2, unsigned int a3, bool a4, char *a5, int a6) 
  (**(void (__thiscall ***)(int, wchar_t *, int, int, const char *, int))((char *)&v24->m_pVbtable + (unsigned int)v24->m_pVbtable->offsetIFileEx))((int)&v24->m_pVbtable + (unsigned int)v24->m_pVbtable->offsetIFileEx, v3, 6, 1, "GfxManager.cpp", 1911);
  v34 = 0;                                      // GetMapFilePtr
  pMapFile = ((int (__thiscall *)(unsigned int))(*(vbtable::CFileEx **)((char *)&v24->m_pVbtable + (unsigned int)v24->m_pVbtable->offsetIFileEx))[1].topOffset)((int)&v24->m_pVbtable + (unsigned int)v24->m_pVbtable->offsetIFileEx);
  if ( pMapFile )
  {
    if ( _iFileVersion != -1 && *(_DWORD *)(pMapFile + 16) != _iFileVersion )
    {
      LastError = *(_DWORD *)(pMapFile + 16);
      v14 = _iFileVersion;
      v7 = std::wstring::c_str(&a2);
      BBSupportTracePrintF(2, "Version incorrect for file \"%s\"!\nNeeded: %d, Got: %d !", (const char *)v7, v14, LastError);
      if ( !byte_3ECDBF0 )
      {
        String::operator=(&v27->m_sLastError, "Wrong version of file \"");
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v29);
        LOBYTE(v34) = 6;
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(&v31, &a2);
        LOBYTE(v34) = 7;
        v8 = std::string::c_str(&v31);
        String::operator+=(&v27->m_sLastError, v8);
        String::operator+=(&v27->m_sLastError, "\"!");
        v16[5] = &v9;
        v16[4] = String::String((String *)&v9, (const struct String *)&v27->m_sLastError, 0, 0xFFFFFFFF);
        CGfxManager::ErrorMessageBox(v27, v9, v10, v11, v12, v13, v14, LastError);
        byte_3ECDBF0 = 1;
        LOBYTE(v34) = 6;
        std::string::~string(&v31);
        LOBYTE(v34) = 0;
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v29);
      }
    }
    v17 = v24;
    v34 = -1;
    std::wstring::~wstring(&a2);
    return v17;
  }
  else
  {
    LastError = GetLastError();
    v4 = std::wstring::c_str(&a2);
    BBSupportTracePrintF(2, "Unable map view of file %s. LastError was: %d", (const char *)v4, LastError);
    ((void (__thiscall *)(unsigned int, const char *, int))(*(vbtable::CFileEx **)((char *)&v24->m_pVbtable + (unsigned int)v24->m_pVbtable->offsetIFileEx))[2].offsetCFile)((int)&v24->m_pVbtable + (unsigned int)v24->m_pVbtable->offsetIFileEx, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\FileEx.h", 146);
    v20 = v24;
    v26 = v24;
    if ( v24 )
    {
      v19 = ((int (__thiscall *)(CFileEx *, int))v26->CFile.dtor)(v26, 1);
    }
    else
    {
      v19 = 0;
    }
    String::operator=(&v27->m_sLastError, "Unable to open file \"");
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v30);
    LOBYTE(v34) = 4;
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(&v32, &a2);
    LOBYTE(v34) = 5;
    v5 = std::string::c_str(&v32);
    String::operator+=(&v27->m_sLastError, v5);
    String::operator+=(&v27->m_sLastError, "\"!");
    v16[7] = &v9;
    v16[6] = String::String((String *)&v9, (const struct String *)&v27->m_sLastError, 0, 0xFFFFFFFF);
    CGfxManager::ErrorMessageBox(v27, v9, v10, v11, v12, v13, v14, LastError);
    v18 = 0;
    LOBYTE(v34) = 4;
    std::string::~string(&v32);
    LOBYTE(v34) = 0;
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v30);
    v34 = -1;
    std::wstring::~wstring(&a2);
    return v18;
  }
}


// address=[0x1365750]
// Decompiled from char __thiscall CGfxManager::LoadGfxFile(CGfxManager *this, int a2, BYTE _bMapFile, int _iFileVersion)
bool  CGfxManager::LoadGfxFile(unsigned int a2, bool _bMapFile, unsigned int _iFileVersion) {
  
  WCHAR *v4; // eax
  WCHAR *v5; // eax
  WCHAR *v6; // eax
  WCHAR *v7; // eax
  WCHAR *v8; // eax
  void *v9; // eax
  int v11; // eax
  std::wstring v12; // [esp-24h] [ebp-280h] OVERLAPPED BYREF
  unsigned int *v13; // [esp-8h] [ebp-264h]
  int iFileVersion; // [esp-4h] [ebp-260h]
  void *v15; // [esp+4h] [ebp-258h]
  std::wstring *v16; // [esp+8h] [ebp-254h]
  void *v17; // [esp+Ch] [ebp-250h]
  int *v18; // [esp+10h] [ebp-24Ch]
  int *File; // [esp+14h] [ebp-248h]
  CFileEx *v20; // [esp+18h] [ebp-244h]
  char v21; // [esp+1Eh] [ebp-23Eh]
  char v22; // [esp+1Fh] [ebp-23Dh]
  CFileEx *v23; // [esp+20h] [ebp-23Ch]
  std::wstring v25; // [esp+28h] [ebp-234h] BYREF
  wchar_t Buffer[260]; // [esp+44h] [ebp-218h] BYREF
  int v27; // [esp+258h] [ebp-4h]

  if ( a2 == 2 || a2 == 41 )
  {
    if ( this->m_bUseHighPalette )
    {
      if ( this->m_bUse6Palette )
      {
        v4 = std::wstring::c_str(&this->m_swGfxFolderName);
        swprintf(Buffer, L"%s\\%d.gh6", v4, a2);
      }
      else
      {
        v5 = std::wstring::c_str(&this->m_swGfxFolderName);
        swprintf(Buffer, L"%s\\%d.gh5", v5, a2);
      }
    }
    else if ( this->m_bUse6Palette )
    {
      v6 = std::wstring::c_str(&this->m_swGfxFolderName);
      swprintf(Buffer, L"%s\\%d.gl6", v6, a2);
    }
    else
    {
      v7 = std::wstring::c_str(&this->m_swGfxFolderName);
      swprintf(Buffer, L"%s\\%d.gl5", v7, a2);
    }
  }
  else
  {
    v8 = std::wstring::c_str(&this->m_swGfxFolderName);
    swprintf(Buffer, L"%s\\%d.gfx", v8, a2);
  }
  std::wstring::wstring(&v25, Buffer);
  v27 = 0;
  v23 = 0;
  if ( _bMapFile == 1 )
  {
    iFileVersion = _iFileVersion;
    v18 = &v12.m_u[1];
    v17 = std::wstring::wstring((std::wstring *)&v12.m_u[1], &v25);
    v20 = CGfxManager::MapFullFile(this, *(std::wstring *)((char *)&v12 + 4), iFileVersion);
    v23 = v20;
    if ( v20 )
    {
      v9 = (void *)((int (__thiscall *)(unsigned int))(*(vbtable::CFileEx **)((char *)&v23->m_pVbtable + (unsigned int)v23->m_pVbtable->offsetIFileEx))[1].topOffset)((int)&v23->m_pVbtable + (unsigned int)v23->m_pVbtable->offsetIFileEx);
      this->m_sFileGfx[a2].pPileGfx = v9;
    }
  }
  else
  {
    iFileVersion = _iFileVersion;
    v13 = 0;
    v16 = &v12;
    v15 = std::wstring::wstring(&v12, &v25);
    File = CGfxManager::LoadFile(this, v12, v13, iFileVersion);
    this->m_sFileGfx[a2].pPileGfx = File;
  }
  if ( this->m_sFileGfx[a2].pPileGfx )
  {
    this->m_sFileGfx[a2].m_bFileMapped = _bMapFile;
    this->m_sFileGfx[a2].m_pFile = v23;
    v11 = v23->CFile.Size(v23);
    this->m_sFileGfx[a2].iLength = v11;
    v21 = 1;
    v27 = -1;
    std::wstring::~wstring(&v25);
    return v21;
  }
  else
  {
    v22 = 0;
    v27 = -1;
    std::wstring::~wstring(&v25);
    return v22;
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
    if ( !*((_DWORD *)v25 + 4 * a2 + 547) && BBSupportDbgReport(2, "GfxManager.cpp", 531, "m_sFileGfx[ nGfxFile ].pFileGfx") == 1 )
    {
      __debugbreak();
    }
    v16 = *((_DWORD *)v25 + 4 * a2 + 547);
    v20 = (unsigned int)(v17 - 20) >> 2;
    *((_DWORD *)v25 + 2 * a2 + 212) = v20;
    for ( i = 0;
          i < v20;
          ++i )
    {
      v21 = *(_DWORD *)(*((_DWORD *)v25 + 2 * a2 + 211) + 4 * i + 20);
      if ( v21 )
      {
        v19 = v21;
      }
      else
      {
        v19 = 20;
      }
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
    if ( !*((_DWORD *)v25 + 2 * a2 + 211) && BBSupportDbgReport(2, "GfxManager.cpp", 573, "m_pFileGfxFrames[ nGfxFile ].pItem") == 1 )
    {
      __debugbreak();
    }
    v16 = *((_DWORD *)v25 + 2 * a2 + 211);
    v20 = (unsigned int)(v17 - 20) >> 2;
    *((_DWORD *)v25 + 2 * a2 + 296) = v20;
    for ( i = 0;
          i < v20;
          ++i )
    {
      v21 = *(_DWORD *)(*((_DWORD *)v25 + 2 * a2 + 295) + 4 * i + 20);
      if ( v21 )
      {
        v19 = v21;
      }
      else
      {
        v19 = 20;
      }
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
    if ( !*((_DWORD *)v25 + 2 * a2 + 295) && BBSupportDbgReport(2, "GfxManager.cpp", 612, "m_pFileGfxDirections[ nGfxFile ].pItem") == 1 )
    {
      __debugbreak();
    }
    v16 = *((_DWORD *)v25 + 2 * a2 + 295);
    v20 = (unsigned int)(v17 - 20) >> 2;
    *((_DWORD *)v25 + 2 * a2 + 380) = v20;
    for ( i = 0;
          i < v20;
          ++i )
    {
      v21 = *(_DWORD *)(*((_DWORD *)v25 + 2 * a2 + 379) + 4 * i + 20);
      if ( v21 )
      {
        v19 = v21;
      }
      else
      {
        v19 = 20;
      }
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
  {
    swprintf((char *)Buffer, (char *)L"%s\\%d.pil", v4);
  }
  else
  {
    swprintf((char *)Buffer, (char *)L"%s\\%d.pi2", v4);
  }
  std::wstring::operator=(v27, Buffer);
  v14 = a3;
  v13 = &v19;
  v16 = &v6;
  v15 = std::wstring::wstring((int)v27);
  File = CGfxManager::LoadFile(v6, v7, v8, v9, v10, v11, v12, (int)v13, v14);
  *((_DWORD *)v26 + a2 + 169) = File;
  if ( *((_DWORD *)v26 + a2 + 169) )
  {
    if ( !*((_DWORD *)v26 + 4 * a2 + 1) && BBSupportDbgReport(2, "GfxManager.cpp", 798, "m_sFilePal[ nGfxFile ].pFileGfx") == 1 )
    {
      __debugbreak();
    }
    v17 = *((_DWORD *)v26 + 4 * a2 + 1);
    v18 = (unsigned int)(v19 - 20) >> 2;
    for ( i = 0;
          i < v18;
          ++i )
    {
      v22 = *(_DWORD *)(*((_DWORD *)v26 + a2 + 169) + 4 * i + 20);
      if ( v22 )
      {
        v21 = v22;
      }
      else
      {
        v21 = 20;
      }
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
  if ( (!(unsigned __int8)IGfxEngine::IsGuiMode(g_pGfxEngine, v18[0]) || a2 != 1) && IGfxEngine::Use4444Palettes((IGfxEngine *)g_pGfxEngine) )
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
    {
      swprintf((char *)Buffer, (char *)L"%s\\%d.pa6", v6);
    }
    else
    {
      swprintf((char *)Buffer, (char *)L"%s\\%d.p26", v6);
    }
  }
  else
  {
    v17 = a2;
    v7 = (unsigned __int8)std::wstring::c_str((_Cnd_internal_imp_t *)(v27 + 3196));
    if ( a4 )
    {
      swprintf((char *)Buffer, (char *)L"%s\\%d.pa5", v7);
    }
    else
    {
      swprintf((char *)Buffer, (char *)L"%s\\%d.p25", v7);
    }
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

  if ( !this->m_pFileGfxFrames[7].m_pItem && BBSupportDbgReport(2, "GfxManager.cpp", 1975, "m_pFileGfxFrames[ iGfxFile ].pItem") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pFilePalIndex[7] && BBSupportDbgReport(2, "GfxManager.cpp", 1976, "m_pFilePalIndex[ iGfxFile ]") == 1 )
  {
    __debugbreak();
  }
  for ( i = 0;
        i < 0x60;
        ++i )
  {
    IGfxEngine::PutAccessoryIcon(g_pGfxEngine, i, (int)this->m_pFileGfxFrames[7].m_pItem[i + 5], (int)this->m_pFilePalIndex[7][i + 5]);
  }
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
  for ( i = 0;
        i < v20;
        ++i )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 525, i, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v21 = CGfxManager::GetObjectFrameCount(this, 0x20Cu);
  for ( j = 0;
        j < v21;
        ++j )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 524, j, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v22 = CGfxManager::GetObjectFrameCount(this, 0x211u);
  for ( k = 0;
        k < v22;
        ++k )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 529, k, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v23 = CGfxManager::GetObjectFrameCount(this, 0x210u);
  for ( m = 0;
        m < v23;
        ++m )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 528, m, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v24 = CGfxManager::GetObjectFrameCount(this, 0x20Fu);
  for ( n = 0;
        n < v24;
        ++n )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 527, n, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v25 = CGfxManager::GetObjectFrameCount(this, 0x20Eu);
  for ( ii = 0;
        ii < v25;
        ++ii )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 526, ii, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v26 = CGfxManager::GetObjectFrameCount(this, 0x212u);
  for ( jj = 0;
        jj < v26;
        ++jj )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 530, jj, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v27 = CGfxManager::GetObjectFrameCount(this, 0x213u);
  for ( kk = 0;
        kk < v27;
        ++kk )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 531, kk, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v28 = CGfxManager::GetObjectFrameCount(this, 0x214u);
  for ( mm = 0;
        mm < v28;
        ++mm )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 532, mm, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v29 = CGfxManager::GetObjectFrameCount(this, 0x205u);
  for ( nn = 0;
        nn < v29;
        ++nn )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 517, nn, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v30 = CGfxManager::GetObjectFrameCount(this, 0x206u);
  for ( i1 = 0;
        i1 < v30;
        ++i1 )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 518, i1, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v31 = CGfxManager::GetObjectFrameCount(this, 0x207u);
  for ( i2 = 0;
        i2 < v31;
        ++i2 )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 519, i2, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v32 = CGfxManager::GetObjectFrameCount(this, 0x208u);
  for ( i3 = 0;
        i3 < v32;
        ++i3 )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 520, i3, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v33 = CGfxManager::GetObjectFrameCount(this, 0x209u);
  for ( i4 = 0;
        i4 < v33;
        ++i4 )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 521, i4, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v34 = CGfxManager::GetObjectFrameCount(this, 0x20Au);
  for ( i5 = 0;
        i5 < v34;
        ++i5 )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 522, i5, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v35 = CGfxManager::GetObjectFrameCount(this, 0x20Bu);
  for ( i6 = 0;
        i6 < v35;
        ++i6 )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 523, i6, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, v70++, v71, v72);
  }
  v36 = CGfxManager::GetObjectFrameCount(this, 0x215u);
  if ( v36 != 8 )
  {
    BBSupportTracePrintF(2, "GfxManager.cpp: Number of boundary stones != 8 !!!!");
  }
  for ( i7 = v70;
        i7 < v36 + v70;
        ++i7 )
  {
    CGfxManager::GetObjectGfxInfo((int)&v71, 533, i7 - v70, 1);
    IGfxEngine::PutLandscapeObject((IGfxEngine *)g_pGfxEngine, i7, v71, v72);
  }
  return 1;
}


// address=[0x1367b70]
// Decompiled from void __thiscall CGfxManager::Debug_Check_LayerBlock(CGfxManager *this, unsigned int _iGfxFile, struct SGfxObjectInfo *a3)
void  CGfxManager::Debug_Check_LayerBlock(unsigned int _iGfxFile, struct SGfxObjectInfo & a3) {
  
  int iHeight; // [esp+0h] [ebp-Ch]
  int iWidth; // [esp+4h] [ebp-8h]

  if ( !this->m_sFileGfx[_iGfxFile].pPileGfx && BBSupportDbgReportF(2, "GfxManager.cpp", 72, "m_sFileGfx[ %u ].pPileGfx", _iGfxFile) == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_sFileGfx[_iGfxFile].iLength && BBSupportDbgReportF(2, "GfxManager.cpp", 73, "m_sFileGfx[ %u ].iLength", _iGfxFile) == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_sFilePal[_iGfxFile].pPileGfx && BBSupportDbgReportF(2, "GfxManager.cpp", 74, "m_sFilePal[ %u ].pPileGfx", _iGfxFile) == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_sFilePal[_iGfxFile].iLength && BBSupportDbgReportF(2, "GfxManager.cpp", 75, "m_sFilePal[ %u ].iLength", _iGfxFile) == 1 )
  {
    __debugbreak();
  }
  if ( (a3->m_pGfxData < this->m_sFileGfx[_iGfxFile].pPileGfx || a3->m_pGfxData >= &this->m_sFileGfx[_iGfxFile].pPileGfx[this->m_sFileGfx[_iGfxFile].iLength]) && BBSupportDbgReportF(2, "GfxManager.cpp", 87, "GfxFile: %u, Base: 0x%x, Len: 0x%x, Access: 0x%x\n%s", _iGfxFile, this->m_sFileGfx[_iGfxFile].pPileGfx, this->m_sFileGfx[_iGfxFile].iLength, a3->m_pGfxData, sGfxDebugBuffer) == 1 )
  {
    __debugbreak();
  }
  if ( (a3->m_pPalData < this->m_sFilePal[_iGfxFile].pPileGfx || a3->m_pPalData >= &this->m_sFilePal[_iGfxFile].pPileGfx[this->m_sFilePal[_iGfxFile].iLength]) && BBSupportDbgReportF(2, "GfxManager.cpp", 98, "PalFile: %u, Base: 0x%x, Len: 0x%x, Access: 0x%x\n%s", _iGfxFile, this->m_sFilePal[_iGfxFile].pPileGfx, this->m_sFilePal[_iGfxFile].iLength, a3->m_pPalData, sGfxDebugBuffer) == 1 )
  {
    __debugbreak();
  }
  if ( _iGfxFile < 20 || _iGfxFile > 29 )
  {
    iWidth = *(__int16 *)a3->m_pGfxData;
    iHeight = *((__int16 *)a3->m_pGfxData + 1);
  }
  else
  {
    iWidth = *a3->m_pGfxData;
    iHeight = a3->m_pGfxData[1];
  }
  if ( _iGfxFile && _iGfxFile != 9 && _iGfxFile != 19 && _iGfxFile != 29 && _iGfxFile != 18 && _iGfxFile != 28 && _iGfxFile != 39 && _iGfxFile != 40 && (iWidth > 512 || iHeight > 512) && BBSupportDbgReportF(2, "GfxManager.cpp", 125, "Width or height > 512! [%s]", sGfxDebugBuffer) == 1 )
  {
    __debugbreak();
  }
}


// address=[0x1367e50]
// Decompiled from struct SGfxPatchObject *__thiscall CGfxManager::Debug_Check_PatchLayerBlock(CGfxManager *this, unsigned int a2, struct SGfxPatchObject *a3)
void  CGfxManager::Debug_Check_PatchLayerBlock(unsigned int a2, struct SGfxPatchObject & a3) {
  
  struct SGfxPatchObject *result; // eax

  if ( !*((_DWORD *)this + 4 * a2 + 547) && BBSupportDbgReportF(2, "GfxManager.cpp", 178, "m_sFileGfx[ %u ].pPileGfx", a2) == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 4 * a2 + 550) && BBSupportDbgReportF(2, "GfxManager.cpp", 179, "m_sFileGfx[ %u ].iLength", a2) == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 4 * a2 + 1) && BBSupportDbgReportF(2, "GfxManager.cpp", 180, "m_sFilePal[ %u ].pPileGfx", a2) == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 4 * a2 + 4) && BBSupportDbgReportF(2, "GfxManager.cpp", 181, "m_sFilePal[ %u ].iLength", a2) == 1 )
  {
    __debugbreak();
  }
  if ( (*(_DWORD *)a3 < *((_DWORD *)this + 4 * a2 + 547) || *(_DWORD *)a3 >= (unsigned int)(*((_DWORD *)this + 4 * a2 + 550) + *((_DWORD *)this + 4 * a2 + 547))) && BBSupportDbgReportF(2, "GfxManager.cpp", 193, "GfxFile: %u, Base: 0x%x, Len: ux%x, Access: 0x%x\n%s", a2, *((_DWORD *)this + 4 * a2 + 547), *((_DWORD *)this + 4 * a2 + 550), *(_DWORD *)a3, sGfxDebugBuffer) == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)a3 + 1) >= *((_DWORD *)this + 4 * a2 + 1) )
  {
    result = a3;
    if ( *((_DWORD *)a3 + 1) < (unsigned int)(*((_DWORD *)this + 4 * a2 + 4) + *((_DWORD *)this + 4 * a2 + 1)) )
    {
      return result;
    }
  }
  result = (struct SGfxPatchObject *)BBSupportDbgReportF(2, "GfxManager.cpp", 204, "PalFile: %u, Base: 0x%x, Len: ux%x, Access: 0x%x\n%s", a2, *((_DWORD *)this + 4 * a2 + 1), *((_DWORD *)this + 4 * a2 + 4), *((_DWORD *)a3 + 1), sGfxDebugBuffer);
  if ( result == (struct SGfxPatchObject *)1 )
  {
    __debugbreak();
  }
  return result;
}


