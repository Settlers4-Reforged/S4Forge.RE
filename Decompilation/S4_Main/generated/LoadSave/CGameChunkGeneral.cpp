#include "CGameChunkGeneral.h"

// Definitions for class CGameChunkGeneral

// address=[0x13eb8a0]
// Decompiled from CGameChunkGeneral *__thiscall CGameChunkGeneral::CGameChunkGeneral(CGameChunkGeneral *this)
 CGameChunkGeneral::CGameChunkGeneral(void) {
  
  IS4ChunkObject::IS4ChunkObject(this);
  this->__vftable = (IS4ChunkObject_vtbl *)CGameChunkGeneral::_vftable_;
  this->m_uMapFlags = 0;
  this->m_uCampaignType = 0;
  this->dwordC = 0;
  this->dword10 = 0;
  this->m_iVersionMajor = 0;
  this->m_iVersionMinor = 0;
  this->m_iVersionBuild = 0;
  this->m_iWidthHeight = 0;
  this->m_iMapMaxNumPlayers = 0;
  this->m_uiPlayerCount = 0;
  this->m_uMultiPlayerGameID = 0;
  this->byte92C = 0;
  this->byte934 = 0;
  this->m_iTeamWon = 0;
  this->m_cLocalSlot = 0;
  this->m_bIsHost = 0;
  this->m_uSavegameId = 0;
  this->m_bIsClanGame = 0;
  this->m_uiTickCounter = 0;
  this->m_iNetworkTimeDelta = 0;
  this->dword950 = 0;
  this->dword954 = 0;
  this->dword958 = 0;
  this->dword95C = 0;
  this->dword960 = 0;
  this->byte964 = 0;
  return this;
}


// address=[0x13eb9f0]
// Decompiled from void __thiscall CGameChunkGeneral::Load(CGameChunkGeneral *this, struct IS4Chunk *a2)
void  CGameChunkGeneral::Load(class IS4Chunk & a2) {
  
  wchar_t *v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int pExceptionObject; // [esp+4h] [ebp-498h] BYREF
  int i; // [esp+8h] [ebp-494h]
  int uGameChunkVersion; // [esp+Ch] [ebp-490h] BYREF
  unsigned __int8 uCampaignType; // [esp+13h] [ebp-489h] BYREF
  char v13[88]; // [esp+18h] [ebp-484h] BYREF
  std::wstring v14; // [esp+70h] [ebp-42Ch] BYREF
  char Str[1024]; // [esp+8Ch] [ebp-410h] BYREF
  int v16; // [esp+498h] [ebp-4h]

  memset(this->byte52C, 0, sizeof(this->byte52C));
  this->byte934 = 0;
  this->byte92C = 0;
  memset(this->m_pEconomyGoodsArray, 0, sizeof(this->m_pEconomyGoodsArray));
  this->m_cLocalSlot = -1;
  this->m_bIsHost = 0;
  this->m_uSavegameId = 0;
  this->m_bIsClanGame = 0;
  this->dword950 = 0x1BB7353;
  this->dword954 = 0;
  a2->LoadSignature(761539483);
  uGameChunkVersion = 0;
  a2->Load(&uGameChunkVersion, 4);
  if ( uGameChunkVersion >= 3 )
  {
    a2->Load(&this->m_uMapFlags, 4);
    a2->Load(&this->dword10, 4);
    a2->Load(&this->m_iVersionMajor, 4);
    a2->Load(&this->m_iVersionMinor, 4);
    a2->Load(&this->m_iVersionBuild, 4);
    a2->Load(&this->m_iWidthHeight, 4);
    a2->Load(this->gap24, 64);
    if ( uGameChunkVersion < 10 )
    {
      a2->Load(Str, 1024);
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v13);
      v16 = 0;
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::from_bytes(
        (int)&v14,
        Str);
      v2 = std::wstring::c_str(&v14);
      wcscpy(this->m_swUnknown, v2);
      std::wstring::~wstring(&v14);
      v16 = -1;
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v13);
    }
    else
    {
      a2->Load(this->m_swUnknown, 512);
    }
    a2->Load(this->byte264, 26);
    a2->Load(&this->m_iMapMaxNumPlayers, 4);
    a2->Load(&this->m_uiPlayerCount, 4);
    for ( i = 0; i < 8; ++i )
      CSavedPlayer::Load(&this->m_sPlayers[i], a2);
    a2->Load(&this->m_uMultiPlayerGameID, 4);
    a2->Load(&this->m_iTeamWon, 4);
    a2->Load(&this->m_uiTickCounter, 4);
    a2->Load(&this->m_iNetworkTimeDelta, 4);
    uCampaignType = 0;
    a2->Load(&uCampaignType, 1);
    if ( uCampaignType >= 0x19u )
    {
      if ( BBSupportDbgReport(1, "LoadSave\\GeneralChunk.cpp", 143, "Load(): Invalid campaign type!") == 1 )
        __debugbreak();
      uCampaignType = 0;
    }
    this->m_uCampaignType = uCampaignType;
    a2->Load(&this->dwordC, 4);
    a2->LoadSignature(761539484);
  }
  if ( uGameChunkVersion >= 4 )
  {
    a2->LoadSignature(0x7D642B9B);
    a2->Load(this->byte52C, 1024);
    a2->LoadSignature(0x8D642B9C);
  }
  if ( uGameChunkVersion >= 5 )
  {
    a2->LoadSignature(0xD642B9B);
    a2->Load(&this->byte934, 1);
    a2->Load(&this->byte92C, 1);
    a2->Load(this->m_pEconomyGoodsArray, 7);
    a2->LoadSignature(493104027);
  }
  if ( uGameChunkVersion >= 6 )
  {
    a2->Load(&this->m_cLocalSlot, 1);
    a2->Load(&this->m_bIsHost, 1);
    a2->Load(&this->m_uSavegameId, 4);
    a2->LoadSignature(493104029);
  }
  if ( uGameChunkVersion >= 7 )
  {
    a2->Load(&this->m_bIsClanGame, 1);
    a2->LoadSignature(493104030);
  }
  if ( uGameChunkVersion >= 8 )
  {
    v3 = a2->LoadUnsigned32_(a2);
    this->dword950 = v3;
    v4 = a2->LoadUnsigned32_(a2);
    this->dword954 = v4;
    a2->LoadSignature(493104031);
  }
  if ( uGameChunkVersion >= 9 )
  {
    v5 = a2->LoadUnsigned32_(a2);
    this->dword958 = v5;
    v6 = a2->LoadUnsigned32_(a2);
    this->dword95C = v6;
    v7 = a2->LoadUnsigned32_(a2);
    this->dword960 = v7;
    this->byte964 = 1;
    a2->LoadSignature(493104032);
  }
  if ( uGameChunkVersion < 1 || uGameChunkVersion > 10 )
  {
    BBSupportTracePrintF(3, "Defect CGameChunkGeneral data!");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
}


// address=[0x13ec060]
// Decompiled from void __thiscall CGameChunkGeneral::Save(CGameChunkGeneral *this, struct IS4Chunk *a2)
void  CGameChunkGeneral::Save(class IS4Chunk & a2) {
  
  int i; // [esp+0h] [ebp-Ch]
  char v4; // [esp+Bh] [ebp-1h] BYREF

  if ( *((_DWORD *)this + 2) > 0x18u
    && BBSupportDbgReport(
         2,
         "LoadSave\\GeneralChunk.cpp",
         206,
         "m_uCampaneID >= CAMPAIGN_NONE && m_uCampaneID<CAMPAIGN_MAX") == 1 )
  {
    __debugbreak();
  }
  a2->SaveSignature(761539483);
  a2->SaveUnsigned32(10);
  a2->Save((char *)this + 4, 4);
  a2->Save((char *)this + 16, 4);
  a2->Save((char *)this + 20, 4);
  a2->Save((char *)this + 24, 4);
  a2->Save((char *)this + 28, 4);
  a2->Save((char *)this + 32, 4);
  a2->Save((char *)this + 36, 64);
  a2->Save((char *)this + 100, 512);
  a2->Save((char *)this + 612, 26);
  a2->Save((char *)this + 640, 4);
  a2->Save((char *)this + 644, 4);
  for ( i = 0; i < 8; ++i )
    CSavedPlayer::Save((CGameChunkGeneral *)((char *)this + 84 * i + 648), a2);
  a2->Save((char *)this + 1320, 4);
  a2->Save((char *)this + 2360, 4);
  a2->Save((char *)this + 2376, 4);
  a2->Save((char *)this + 2380, 4);
  v4 = *((_BYTE *)this + 8);
  a2->Save(&v4, 1);
  a2->Save((char *)this + 12, 4);
  a2->SaveSignature(761539484);
  a2->SaveSignature(2103716763);
  a2->Save((char *)this + 1324, 1024);
  a2->SaveSignature(-1922815076);
  a2->SaveSignature(224668571);
  a2->Save((char *)this + 2356, 1);
  a2->Save((char *)this + 2348, 1);
  a2->Save((char *)this + 2349, 7);
  a2->SaveSignature(493104027);
  a2->Save((char *)this + 2364, 1);
  a2->Save((char *)this + 2365, 1);
  a2->Save((char *)this + 2368, 4);
  a2->SaveSignature(493104029);
  a2->Save((char *)this + 2372, 1);
  a2->SaveSignature(493104030);
  a2->SaveUnsigned32(*((_DWORD *)this + 596));
  a2->SaveUnsigned32(*((_DWORD *)this + 597));
  a2->SaveSignature(493104031);
  a2->SaveUnsigned32(*((_DWORD *)this + 598));
  a2->SaveUnsigned32(*((_DWORD *)this + 599));
  a2->SaveUnsigned32(*((_DWORD *)this + 600));
  a2->SaveSignature(493104032);
}


// address=[0x13ec470]
// Decompiled from CGameChunkGeneral *__thiscall CGameChunkGeneral::GenerateCRC(CGameChunkGeneral *this)
void  CGameChunkGeneral::GenerateCRC(void) {
  
  CGameChunkGeneral *result; // eax
  unsigned int NormalCRC; // [esp+0h] [ebp-14h]
  unsigned int v3; // [esp+0h] [ebp-14h]
  unsigned int i; // [esp+8h] [ebp-Ch]
  _BYTE v6[4]; // [esp+10h] [ebp-4h] BYREF

  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::CRCGenerator<16,32773,0,0,1,1>(v6);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 4, 4);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 16, 4);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 20, 4);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 24, 4);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 28, 4);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 32, 4);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 1320, 4);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 36, 64);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 640, 4);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 644, 4);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 2376, 4);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 2380, 4);
  for ( i = 0; i < *((_DWORD *)this + 161); ++i )
  {
    cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 84 * i + 648, 4);
    cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 84 * i + 716, 4);
    cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 84 * i + 728, 1);
    cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 84 * i + 652, 64);
  }
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 2384, 4);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 2388, 4);
  NormalCRC = cdm_crc::CRCGenerator<16,32773,0,0,1,1>::GetNormalCRC(v6);
  v3 = NormalCRC >> (32 - cdm_crc::CRCGenerator<16,32773,0,0,1,1>::GetWidth(v6));
  result = this;
  *((_DWORD *)this + 592) = v3;
  return result;
}


