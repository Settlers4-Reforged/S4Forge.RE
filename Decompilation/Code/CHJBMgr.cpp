#include "CHJBMgr.h"

// Definitions for class CHJBMgr

// address=[0x1574510]
// Decompiled from bool __thiscall CHJBMgr::LocalLoadHJBGfxFileIfNecessary(CHJBMgr *this)

bool  CHJBMgr::LocalLoadHJBGfxFileIfNecessary(void) {
  
  bool v2; // [esp+Fh] [ebp-1h]

  if ( IHJBMgr::m_iLocalHJBGfxLoaded >= 0 )
    return IHJBMgr::m_iLocalHJBGfxLoaded > 0;
  v2 = 0;
  if ( g_pGfxManager )
    v2 = CGfxManager::EnableGfxFile((CGfxManager *)g_pGfxManager, 0x19u, 0, 1, 0x3Au);
  IHJBMgr::m_iLocalHJBGfxLoaded = v2;
  if ( v2 )
    g_bGfxHJBLoadSpecialGfx = 1;
  return IHJBMgr::m_iLocalHJBGfxLoaded > 0;
}


// address=[0x15745a0]
// Decompiled from bool __thiscall CHJBMgr::StaticCheckHJBCommand(CHJBMgr *this, const char *a2)

bool  CHJBMgr::StaticCheckHJBCommand(char const *) {
  
  if ( !a2 )
    return 0;
  return *a2 == 33 && a2[1] == 104 && a2[2] == 106 && a2[3] == 98 && !a2[4];
}


// address=[0x1574630]
// Decompiled from char __stdcall CHJBMgr::StaticCheckHJBPlayerName(int a1)

bool  CHJBMgr::StaticCheckHJBPlayerName(std::wstring const &) {
  
  int v2; // [esp+4h] [ebp-28h]
  char v3; // [esp+Bh] [ebp-21h]
  _BYTE v4[28]; // [esp+Ch] [ebp-20h] BYREF

  v2 = std::wstring::wstring(v4, (wchar_t *)L"Jodowein");
  v3 = std::operator==<wchar_t>(a1, v2);
  std::wstring::~wstring(v4);
  return v3;
}


// address=[0x1574690]
// Decompiled from void __thiscall CHJBMgr::ProcessHJBRequest(CHJBMgr *this, int a2)

void  CHJBMgr::ProcessHJBRequest(int) {
  
  int v2; // [esp+0h] [ebp-10h]
  unsigned int v3; // [esp+0h] [ebp-10h]
  int LocalPlayerId; // [esp+4h] [ebp-Ch]

  if ( a2 >= 1 && a2 <= 8 && !IHJBMgr::m_iHJBPlayerId )
  {
    CHJBMgr::ClearRequest(this);
    *((_DWORD *)this + 1) = a2;
    LocalPlayerId = CPlayerManager::GetLocalPlayerId(v2);
    v3 = (**(unsigned __int8 (__thiscall ***)(CHJBMgr *))this)(this) != 0;
    INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, 0x13BCu, v3, 0, LocalPlayerId);
  }
}


// address=[0x1574720]
// Decompiled from void __thiscall CHJBMgr::ProcessHJBAcknowledgement(CHJBMgr *this, int a2, int a3)

void  CHJBMgr::ProcessHJBAcknowledgement(int,int) {
  
  int PlayerId; // [esp+0h] [ebp-10h]
  int i; // [esp+4h] [ebp-Ch]
  char v6; // [esp+Fh] [ebp-1h]

  if ( a2 >= 1 && a2 <= 8 && !IHJBMgr::m_iHJBPlayerId && *((_DWORD *)this + 1) )
  {
    if ( a3 )
    {
      v6 = 1;
      *((_BYTE *)this + a2 + 8) = 1;
      PlayerId = CPlayerManager::LastPlayerId();
      for ( i = 1; i <= PlayerId; ++i )
      {
        if ( !*((_BYTE *)this + i + 8) && !CPlayerManager::IsAI(i) )
        {
          v6 = 0;
          break;
        }
      }
      if ( v6 )
      {
        CTextMsgHandler::AddTextMsg("Attention! Beware of HJB...", IHJBMgr::m_iHJBPlayerId - 1, 0, 0, 1);
        CHJBMgr::ActivateHJB(this, *((_DWORD *)this + 1));
        CHJBMgr::ClearRequest(this);
      }
    }
    else
    {
      CTextMsgHandler::AddTextMsg("Ups! There will be no HJB in this game...", IHJBMgr::m_iHJBPlayerId - 1, 0, 0, 1);
      CHJBMgr::ClearRequest(this);
    }
  }
}


// address=[0x15748b0]
// Decompiled from CHJBMgr *__thiscall CHJBMgr::CHJBMgr(CHJBMgr *this)

 CHJBMgr::CHJBMgr(void) {
  
  IHJBMgr::IHJBMgr(this);
  *(_DWORD *)this = &CHJBMgr::_vftable_;
  IHJBMgr::m_iHJBPlayerId = 0;
  IHJBMgr::m_iHJBEntityId = -1;
  CHJBMgr::ClearRequest(this);
  return this;
}


// address=[0x1574820]
// Decompiled from void __thiscall CHJBMgr::InitHJBManager(CHJBMgr *this)

void  CHJBMgr::InitHJBManager(void) {
  
  IHJBMgr::m_iHJBPlayerId = 0;
  IHJBMgr::m_iHJBEntityId = -1;
  CHJBMgr::ClearRequest(this);
}


// address=[0x1574850]
// Decompiled from char __thiscall CHJBMgr::LocalIsHJBAllowedEx(CHJBMgr *this)

bool  CHJBMgr::LocalIsHJBAllowedEx(void) {
  
  int v2; // [esp+0h] [ebp-Ch]
  char v4; // [esp+Bh] [ebp-1h]

  v4 = (**(int (__thiscall ***)(CHJBMgr *))this)(this);
  if ( v4 )
  {
    v4 = CHJBMgr::CheckHJBDatFile(this);
    if ( v4 )
      v2 = 1;
    else
      v2 = -1;
    IHJBMgr::m_iLocalHJBAllowed = v2;
  }
  else
  {
    IHJBMgr::m_iLocalHJBAllowed = 0;
  }
  return v4;
}


// address=[0x15748f0]
// Decompiled from void __thiscall CHJBMgr::ActivateHJB(CHJBMgr *this, int a2)

void  CHJBMgr::ActivateHJB(int) {
  
  if ( a2 >= 1 && a2 <= 8 && !IHJBMgr::m_iHJBPlayerId )
  {
    if ( IHJBMgr::m_iHJBEntityId != -1
      && BBSupportDbgReport(2, "mapobjects\\settler\\HJBMgr.cpp", 291, "m_iHJBEntityId == -1") == 1 )
    {
      __debugbreak();
    }
    IHJBMgr::m_iHJBPlayerId = a2;
    IHJBMgr::m_iHJBEntityId = 0;
    (**(void (__thiscall ***)(CHJBMgr *))this)(this);
  }
}


// address=[0x1574960]
// Decompiled from char __thiscall CHJBMgr::CheckHJBDatFile(CHJBMgr *this)

bool  CHJBMgr::CheckHJBDatFile(void) {
  
  wchar_t *v2; // eax
  _DWORD v3[11]; // [esp+0h] [ebp-CCh] BYREF
  unsigned int v4; // [esp+2Ch] [ebp-A0h]
  void *v5; // [esp+30h] [ebp-9Ch]
  void *Buffer; // [esp+34h] [ebp-98h]
  char v7; // [esp+39h] [ebp-93h]
  char v8; // [esp+3Ah] [ebp-92h]
  char v9; // [esp+3Bh] [ebp-91h]
  _BYTE v10[72]; // [esp+3Ch] [ebp-90h] BYREF
  _BYTE v11[28]; // [esp+84h] [ebp-48h] BYREF
  _DWORD v12[8]; // [esp+A0h] [ebp-2Ch] BYREF
  int v13; // [esp+C8h] [ebp-4h]

  v12[7] = v3;
  v3[8] = this;
  v12[0] = &dword_420320[130890];
  v12[1] = 3276866;
  v12[2] = 3145776;
  v12[3] = 3014705;
  v12[4] = &dword_600000[16409];
  v12[5] = 116;
  v3[7] = 0x400000;
  v3[6] = 0x4000;
  v3[5] = -1293418438;
  std::wstring::wstring(v11);
  v13 = 0;
  (*(void (__thiscall **)(void *, _BYTE *, _DWORD *, int))(*(_DWORD *)g_pCDDrive + 8))(g_pCDDrive, v11, v12, 1048592);
  if ( std::wstring::length(v11) )
  {
    v9 = 1;
    v5 = operator new[](0x4000u);
    Buffer = v5;
    j__memset(v5, 0, 0x4000u);
    LOBYTE(v13) = 1;
    v3[4] = CFile::CFile((CFile *)v10);
    LOBYTE(v13) = 2;
    v2 = (wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v11);
    CFile::Open(v2, 6, "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h", 0);
    CFile::Seek(0x400000, 0, (int)"d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h", 0);
    CFile::Read(Buffer, 1u, 0x4000u, (int)"d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h", 0);
    CFile::Close((CFile *)v10, "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h", 0);
    v4 = Adler32(Buffer, 0x4000u, 1u);
    v3[10] = v4;
    if ( v4 != -1293418438 )
      v9 = 0;
    LOBYTE(v13) = 1;
    CFile::~CFile();
    v13 = 0;
    v3[9] = Buffer;
    operator delete[](Buffer);
    v7 = v9;
    v13 = -1;
    std::wstring::~wstring(v11);
    return v7;
  }
  else
  {
    v8 = 0;
    v13 = -1;
    std::wstring::~wstring(v11);
    return v8;
  }
}


// address=[0x1574d90]
// Decompiled from void *__thiscall CHJBMgr::ClearRequest(CHJBMgr *this)

void  CHJBMgr::ClearRequest(void) {
  
  *((_DWORD *)this + 1) = 0;
  return j__memset((char *)this + 8, 0, 9u);
}


