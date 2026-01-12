#include "CTextMsgHandler.h"

// Definitions for class CTextMsgHandler

// address=[0x14cf8e0]
// Decompiled from char CTextMsgHandler::Init()
static void __cdecl CTextMsgHandler::Init(void) {
  
  return IEventEngine::RegisterHandle(g_pEvnEngine, (struct IEvn_Handle *)&g_cTextMsgHandler);
}


// address=[0x14cf900]
// Decompiled from char __cdecl CTextMsgHandler::AddChatMsg(char *Str, int a2)
static bool __cdecl CTextMsgHandler::AddChatMsg(char const *,int) {
  
  size_t v2; // eax
  int PlayerIcon; // [esp+4h] [ebp-Ch]
  _DWORD *v5; // [esp+Ch] [ebp-4h]

  if ( !Str && BBSupportDbgReport(2, "Main\\TextMsgHandler.cpp", 128, "_pcacMessage") == 1 )
    __debugbreak();
  PlayerIcon = CTextMsgHandler::GetPlayerIcon(a2);
  v5 = operator new(0x24u);
  memset(v5, 0, 0x24u);
  *v5 = 679;
  v5[1] = a2;
  v5[3] = -1;
  v5[6] = PlayerIcon;
  v5[4] = 0;
  v5[5] = 0;
  v2 = j__strlen(Str);
  v5[8] = operator new[](v2 + 1);
  j__strcpy_0((char *)v5[8], Str);
  CTextMsgHandler::AddMsgToVector((char)v5);
  CTextMsgHandler::SendAllMessages(0, 1, 1);
  return 1;
}


// address=[0x14cf9f0]
// Decompiled from char CTextMsgHandler::AddTextMsg(int a1, int a2, int a3, int a4, bool a5, bool a6, ...)
static bool __cdecl CTextMsgHandler::AddTextMsg(int,int,int,int,bool,bool,...) {
  
  char *Format; // [esp+10h] [ebp-18h]
  int v8; // [esp+14h] [ebp-14h] BYREF
  int v9; // [esp+18h] [ebp-10h]
  const char *StringName; // [esp+1Ch] [ebp-Ch]
  void *v11; // [esp+20h] [ebp-8h]
  char v12; // [esp+27h] [ebp-1h]
  va_list va; // [esp+48h] [ebp+20h] BYREF

  va_start(va, a6);
  v12 = 0;
  if ( (a2 & 0x10000000) != 0 )
  {
    a2 &= ~0x10000000u;
    v12 = 1;
  }
  StringName = (const char *)CS4DefineNames::GetStringName(a1);
  v8 = 165;
  if ( a5 && !CTextMsgHandler::CheckWarning(StringName, &v8) )
    return 0;
  Format = g_pStringEngine->GetString(g_pStringEngine, a1);
  if ( Format )
  {
    v11 = operator new(0x24u);
    memset(v11, 0, 0x24u);
    *(_DWORD *)v11 = a1;
    *((_DWORD *)v11 + 1) = a2;
    if ( v12 )
      v9 = -1;
    else
      v9 = CStaticConfigVarInt::operator int(&unk_403221C) / 2;
    *((_DWORD *)v11 + 3) = v9;
    *((_DWORD *)v11 + 4) = a3;
    *((_DWORD *)v11 + 5) = a4;
    *((_BYTE *)v11 + 28) = 1;
    *((_BYTE *)v11 + 29) = a5;
    *((_DWORD *)v11 + 6) = v8;
    *((_DWORD *)v11 + 8) = operator new[](0x200u);
    __vcrt_va_start_verify_argument_type<bool>();
    if ( j___vsnprintf(*((char *const *)v11 + 8), 0x200u, Format, va) < 0 )
    {
      BBSupportTracePrintF(0, "CTextMsgHandler::AddWarningMsg (multiple args) : Array for msg too small.");
      *(_BYTE *)(*((_DWORD *)v11 + 8) + 511) = 0;
    }
    if ( !(unsigned __int8)CTextMsgHandler::CheckExists(v11) || a6 )
    {
      CTextMsgHandler::AddMsgToVector((char)v11);
      CTextMsgHandler::SendAllMessages(a6, 1, 1);
      return 1;
    }
    else
    {
      operator delete(v11);
      return 1;
    }
  }
  else
  {
    BBSupportTracePrintF(0, "CTextMsgHandler::AddTextMsg : Couldn't get string for %s", StringName);
    return 0;
  }
}


// address=[0x14cfbe0]
// Decompiled from char CTextMsgHandler::AddTextMsg(int a1, int a2, bool a3, bool a4, ...)
static bool __cdecl CTextMsgHandler::AddTextMsg(int,int,bool,bool,...) {
  
  int v5; // eax
  char *Format; // [esp+10h] [ebp-10h]
  int v7; // [esp+14h] [ebp-Ch] BYREF
  const char *StringName; // [esp+18h] [ebp-8h]
  void *v9; // [esp+1Ch] [ebp-4h]
  va_list va; // [esp+38h] [ebp+18h] BYREF

  va_start(va, a4);
  StringName = (const char *)CS4DefineNames::GetStringName(a1);
  v7 = 165;
  if ( a3 && !CTextMsgHandler::CheckWarning(StringName, &v7) )
    return 0;
  Format = g_pStringEngine->GetString(g_pStringEngine, a1);
  if ( Format )
  {
    v9 = operator new(0x24u);
    memset(v9, 0, 0x24u);
    *(_DWORD *)v9 = a1;
    *((_DWORD *)v9 + 1) = a2;
    v5 = CStaticConfigVarInt::operator int(&unk_403221C);
    *((_DWORD *)v9 + 3) = v5 / 2;
    *((_BYTE *)v9 + 29) = a3;
    *((_DWORD *)v9 + 6) = v7;
    *((_DWORD *)v9 + 8) = operator new[](0x200u);
    __vcrt_va_start_verify_argument_type<bool>();
    if ( j___vsnprintf(*((char *const *)v9 + 8), 0x200u, Format, va) < 0 )
    {
      BBSupportTracePrintF(0, "CTextMsgHandler::AddWarningMsg (multiple args) : Array for msg too small.");
      *(_BYTE *)(*((_DWORD *)v9 + 8) + 511) = 0;
    }
    if ( !(unsigned __int8)CTextMsgHandler::CheckExists(v9) || a4 )
    {
      CTextMsgHandler::AddMsgToVector((char)v9);
      CTextMsgHandler::SendAllMessages(a4, 1, 1);
      return 1;
    }
    else
    {
      operator delete(v9);
      return 1;
    }
  }
  else
  {
    BBSupportTracePrintF(0, "CTextMsgHandler::AddTextMsg : Couldn't get string for %s", StringName);
    return 0;
  }
}


// address=[0x14cfd80]
// Decompiled from char __cdecl CTextMsgHandler::AddTextMsg(int a1, int a2, bool a3)
static bool __cdecl CTextMsgHandler::AddTextMsg(int,int,bool) {
  
  const char *StringName; // [esp+Ch] [ebp-Ch]
  int *v5; // [esp+14h] [ebp-4h]

  StringName = (const char *)CS4DefineNames::GetStringName(a1);
  if ( g_pStringEngine->GetString(g_pStringEngine, a1) )
  {
    v5 = (int *)operator new(0x24u);
    memset(v5, 0, 0x24u);
    *v5 = a1;
    v5[1] = a2;
    v5[3] = CStaticConfigVarInt::operator int(&unk_403221C) / 2;
    v5[6] = 165;
    if ( !(unsigned __int8)CTextMsgHandler::CheckExists(v5) || a3 )
    {
      CTextMsgHandler::AddMsgToVector((char)v5);
      CTextMsgHandler::SendAllMessages(a3, 1, 1);
      return 1;
    }
    else
    {
      operator delete(v5);
      return 1;
    }
  }
  else
  {
    BBSupportTracePrintF(0, "CTextMsgHandler::AddTextMsg : Couldn't get string for %s", StringName);
    return 0;
  }
}


// address=[0x14cfe80]
// Decompiled from char __cdecl CTextMsgHandler::AddTextMsg(char *Str, int a2, int a3, int a4, char a5)
static bool __cdecl CTextMsgHandler::AddTextMsg(char const *,int,int,int,bool) {
  
  size_t v5; // eax
  int PlayerIcon; // [esp+4h] [ebp-Ch]
  _DWORD *v8; // [esp+Ch] [ebp-4h]

  if ( !Str && BBSupportDbgReport(2, "Main\\TextMsgHandler.cpp", 159, "_pcacMessage") == 1 )
    __debugbreak();
  PlayerIcon = CTextMsgHandler::GetPlayerIcon(a2);
  v8 = operator new(0x24u);
  memset(v8, 0, 0x24u);
  *v8 = 3837;
  v8[1] = a2;
  v8[3] = -1;
  v8[6] = PlayerIcon;
  v8[4] = a3;
  v8[5] = a4;
  v5 = j__strlen(Str);
  v8[8] = operator new[](v5 + 1);
  j__strcpy_0((char *)v8[8], Str);
  CTextMsgHandler::AddMsgToVector((char)v8);
  CTextMsgHandler::SendAllMessages(a5, 1, 1);
  return 1;
}


// address=[0x14cff70]
// Decompiled from char __cdecl CTextMsgHandler::AddWarningMsg(int a1, int a2, int a3, int a4)
static bool __cdecl CTextMsgHandler::AddWarningMsg(int,int,int,int) {
  
  int v5; // eax
  int v6; // [esp+4h] [ebp-14h] BYREF
  void *v7; // [esp+8h] [ebp-10h]
  const char *StringName; // [esp+10h] [ebp-8h]
  void *v10; // [esp+14h] [ebp-4h]

  StringName = (const char *)CS4DefineNames::GetStringName(a1);
  if ( !(unsigned __int8)CTextMsgHandler::CheckWarning(StringName, &v6) )
    return 0;
  if ( (*(int (__thiscall **)(int, int))(*(_DWORD *)g_pStringEngine + 4))(g_pStringEngine, a1) )
  {
    v7 = operator new(0x24u);
    v10 = v7;
    memset(v7, 0, 0x24u);
    *(_DWORD *)v10 = a1;
    *((_DWORD *)v10 + 1) = a2;
    v5 = CStaticConfigVarInt::operator int(&unk_403221C);
    *((_DWORD *)v10 + 3) = v5 / 2;
    *((_DWORD *)v10 + 4) = a3;
    *((_DWORD *)v10 + 5) = a4;
    *((_BYTE *)v10 + 28) = 1;
    *((_BYTE *)v10 + 29) = 1;
    *((_DWORD *)v10 + 6) = v6;
    if ( (unsigned __int8)CTextMsgHandler::CheckExists(v10) )
    {
      operator delete(v10);
    }
    else
    {
      CTextMsgHandler::AddMsgToVector((char)v10);
      CTextMsgHandler::SendAllMessages(0, 1, 1);
    }
    return 1;
  }
  else
  {
    BBSupportTracePrintF(0, "CTextMsgHandler::AddWarningMsg : Couldn't get string for %s", StringName);
    return 0;
  }
}


// address=[0x14d00a0]
// Decompiled from char __cdecl CTextMsgHandler::AddWarningMsg_0(int a1, int a2)
static bool __cdecl CTextMsgHandler::AddWarningMsg(int,int) {
  
  int v3; // eax
  int v4; // [esp+4h] [ebp-14h] BYREF
  void *v5; // [esp+8h] [ebp-10h]
  const char *StringName; // [esp+10h] [ebp-8h]
  void *v8; // [esp+14h] [ebp-4h]

  StringName = (const char *)CS4DefineNames::GetStringName(a1);
  if ( !CTextMsgHandler::CheckWarning(StringName, &v4) )
    return 0;
  if ( g_pStringEngine->GetString(g_pStringEngine, a1) )
  {
    v5 = operator new(0x24u);
    v8 = v5;
    memset(v5, 0, 0x24u);
    *(_DWORD *)v8 = a1;
    *((_DWORD *)v8 + 1) = a2;
    v3 = CStaticConfigVarInt::operator int(&unk_403221C);
    *((_DWORD *)v8 + 3) = v3 / 2;
    *((_BYTE *)v8 + 29) = 1;
    *((_DWORD *)v8 + 6) = v4;
    if ( (unsigned __int8)CTextMsgHandler::CheckExists(v8) )
    {
      operator delete(v8);
    }
    else
    {
      CTextMsgHandler::AddMsgToVector((char)v8);
      CTextMsgHandler::SendAllMessages(0, 1, 1);
    }
    return 1;
  }
  else
  {
    BBSupportTracePrintF(0, "CTextMsgHandler::AddWarningMsg : Couldn't get string for %s", StringName);
    return 0;
  }
}


// address=[0x14d01c0]
// Decompiled from void __cdecl CTextMsgHandler::ExecuteMsg(int a1)
static void __cdecl CTextMsgHandler::ExecuteMsg(int) {
  
  CEvn_Event *v1; // [esp+4h] [ebp-40h]
  int v2; // [esp+Ch] [ebp-38h]
  int v3; // [esp+10h] [ebp-34h]
  int v4; // [esp+14h] [ebp-30h]
  int v5; // [esp+18h] [ebp-2Ch]
  _DWORD v6[6]; // [esp+1Ch] [ebp-28h] BYREF
  int v7; // [esp+40h] [ebp-4h]

  v3 = std::vector<STextMessage *>::size(&CTextMsgHandler::m_vMsgs);
  if ( a1 < v3 && a1 >= 0 && v3 )
  {
    v5 = -1;
    v2 = -1;
    while ( ++v5 < v3 )
    {
      if ( !*(_BYTE *)(*(_DWORD *)std::vector<STextMessage *>::operator[](v5) + 30) )
        ++v2;
      if ( v2 == a1 )
      {
        v4 = *(_DWORD *)std::vector<STextMessage *>::operator[](v5);
        if ( *(_BYTE *)(v4 + 28) )
        {
          v1 = CEvn_Event::CEvn_Event((CEvn_Event *)v6, 0x13u, *(_DWORD *)(v4 + 20), *(_DWORD *)(v4 + 16), 0);
          v7 = 0;
          IEventEngine::SendAMessage(g_pEvnEngine, v1);
          v7 = -1;
          CEvn_Event::~CEvn_Event(v6);
        }
        if ( *(_DWORD *)(v4 + 12) == -1 )
          return;
        *(_BYTE *)(v4 + 30) = 1;
        CTextMsgHandler::SendAllMessages(0, 0, 1);
        return;
      }
    }
  }
  else
  {
    BBSupportTracePrintF(0, "CTextMsgHandler::ExecuteMessage : Undefined index : %d", a1);
  }
}


// address=[0x14d0310]
// Decompiled from void CTextMsgHandler::ExecuteLastMsg()
static void __cdecl CTextMsgHandler::ExecuteLastMsg(void) {
  
  int v0; // [esp+0h] [ebp-Ch]
  int v1; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  if ( std::vector<STextMessage *>::size(&CTextMsgHandler::m_vMsgs) )
  {
    v0 = std::vector<STextMessage *>::size(&CTextMsgHandler::m_vMsgs);
    v1 = -1;
    for ( i = 0; i < v0; ++i )
    {
      if ( !*(_BYTE *)(*(_DWORD *)std::vector<STextMessage *>::operator[](i) + 30) )
        ++v1;
    }
    if ( v1 >= 0 )
      CTextMsgHandler::ExecuteMsg(v1);
  }
}


// address=[0x14d0390]
// Decompiled from int CTextMsgHandler::Update()
static void __cdecl CTextMsgHandler::Update(void) {
  
  _DWORD v1[2]; // [esp-Ch] [ebp-6Ch] BYREF
  int v2; // [esp-4h] [ebp-64h]
  _BYTE v3[12]; // [esp+4h] [ebp-5Ch] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-50h] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-44h] BYREF
  int v6; // [esp+28h] [ebp-38h]
  _DWORD *v7; // [esp+2Ch] [ebp-34h]
  int v8; // [esp+30h] [ebp-30h]
  int v9; // [esp+34h] [ebp-2Ch]
  void *v10; // [esp+38h] [ebp-28h]
  void *C; // [esp+3Ch] [ebp-24h]
  std::_Iterator_base12 *v12; // [esp+40h] [ebp-20h]
  std::_Iterator_base12 *v13; // [esp+44h] [ebp-1Ch]
  int v14; // [esp+48h] [ebp-18h]
  void *v15; // [esp+4Ch] [ebp-14h]
  char v16; // [esp+52h] [ebp-Eh]
  char v17; // [esp+53h] [ebp-Dh]
  int v18; // [esp+5Ch] [ebp-4h]

  v14 = 0;
  v17 = 0;
  std::vector<STextMessage *>::begin(v5);
  v18 = 0;
  while ( 1 )
  {
    v13 = (std::_Iterator_base12 *)std::vector<STextMessage *>::end(v4);
    v12 = v13;
    LOBYTE(v18) = 1;
    v16 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator!=(v13);
    LOBYTE(v18) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>(v4);
    if ( !v16 )
      break;
    v15 = *(void **)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v5);
    if ( *((int *)v15 + 3) > 0 )
      --*((_DWORD *)v15 + 3);
    if ( *((_DWORD *)v15 + 3) )
    {
      ++v14;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator++(v5);
    }
    else
    {
      if ( !*((_BYTE *)v15 + 30) )
        v17 = 1;
      if ( *((_DWORD *)v15 + 8) )
      {
        C = (void *)*((_DWORD *)v15 + 8);
        operator delete[](C);
        *((_DWORD *)v15 + 8) = 0;
      }
      v10 = v15;
      v2 = 36;
      operator delete(v15);
      v7 = v1;
      v6 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>((struct std::_Iterator_base12 *)v5);
      v9 = std::vector<STextMessage *>::erase(v3, v1[0], v1[1], v2);
      v8 = v9;
      LOBYTE(v18) = 2;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator=(v9);
      LOBYTE(v18) = 0;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>(v3);
    }
  }
  if ( v17 )
    CTextMsgHandler::SendAllMessages(0, 0, 1);
  v18 = -1;
  return std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>(v5);
}


// address=[0x14d0530]
// Decompiled from int __cdecl CTextMsgHandler::SendAllMessages(bool a1, bool a2, bool a3)
static void __cdecl CTextMsgHandler::SendAllMessages(bool,bool,bool) {
  
  int v3; // eax
  int **v4; // eax
  char *v5; // eax
  int v6; // eax
  _BYTE v8[12]; // [esp+4h] [ebp-90h] BYREF
  _BYTE v9[12]; // [esp+10h] [ebp-84h] BYREF
  _BYTE v10[12]; // [esp+1Ch] [ebp-78h] BYREF
  CEvn_Event *v11; // [esp+28h] [ebp-6Ch]
  CEvn_Event *v12; // [esp+2Ch] [ebp-68h]
  std::_Iterator_base12 *v13; // [esp+30h] [ebp-64h]
  std::_Iterator_base12 *v14; // [esp+34h] [ebp-60h]
  std::_Iterator_base12 *v15; // [esp+38h] [ebp-5Ch]
  std::_Iterator_base12 *v16; // [esp+3Ch] [ebp-58h]
  unsigned int v17; // [esp+40h] [ebp-54h]
  unsigned int v18; // [esp+44h] [ebp-50h]
  BOOL v19; // [esp+48h] [ebp-4Ch]
  BOOL v20; // [esp+4Ch] [ebp-48h]
  _BYTE v21[12]; // [esp+50h] [ebp-44h] BYREF
  unsigned int v22; // [esp+5Ch] [ebp-38h]
  int v23; // [esp+60h] [ebp-34h]
  int v24; // [esp+64h] [ebp-30h]
  bool v25; // [esp+69h] [ebp-2Bh]
  char v26; // [esp+6Ah] [ebp-2Ah]
  bool v27; // [esp+6Bh] [ebp-29h]
  CEvn_Event v28; // [esp+6Ch] [ebp-28h] BYREF
  int v29; // [esp+90h] [ebp-4h]

  v23 = 0;
  if ( MAX_LISTENTRIES_COUNT != 200
    && BBSupportDbgReport(2, "Main\\TextMsgHandler.cpp", 775, "MAX_LISTENTRIES_COUNT == MAX_MESSAGE_LIST_ENTRIES") == 1 )
  {
    __debugbreak();
  }
  v24 = 0;
  std::vector<STextMessage *>::begin(v21);
  v29 = 0;
  std::vector<STextMessage *>::end(v10);
  LOBYTE(v29) = 1;
  while ( 1 )
  {
    v16 = (std::_Iterator_base12 *)std::vector<STextMessage *>::end(v9);
    v15 = v16;
    LOBYTE(v29) = 2;
    v26 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator!=(v16);
    LOBYTE(v29) = 1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>(v9);
    if ( !v26 )
      break;
    if ( !*(_BYTE *)(*(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v21)
                   + 30) )
    {
      if ( *(_DWORD *)(*(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v21)
                     + 32) )
      {
        v3 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v21);
        dword_4032248[2 * v24] = *(_DWORD *)(*(_DWORD *)v3 + 32);
      }
      else
      {
        v4 = (int **)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v21);
        v5 = g_pStringEngine->GetString(g_pStringEngine, **v4);
        dword_4032248[2 * v24] = (int)v5;
      }
      v6 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v21);
      dword_403224C[2 * v24++] = *(_DWORD *)(*(_DWORD *)v6 + 24);
    }
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator=(v21);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator++(v21);
  }
  v14 = (std::_Iterator_base12 *)std::vector<STextMessage *>::end(v8);
  v13 = v14;
  LOBYTE(v29) = 3;
  v23 |= 1u;
  v20 = (unsigned __int8)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator!=(v14)
     && (**(_DWORD **)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v10) == 2261
      || **(_DWORD **)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v10) == 679);
  v25 = v20;
  v29 = 1;
  if ( (v23 & 1) != 0 )
  {
    v23 &= ~1u;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>(v8);
  }
  v19 = a3 && !v25;
  v27 = v19;
  v22 = 0;
  if ( (unsigned __int8)CGameSettings::GetAlwaysUrgentMsg() || a1 )
  {
    if ( v27 )
      v18 = 616;
    else
      v18 = 633;
    v22 = v18;
  }
  else
  {
    if ( v27 )
      v17 = 615;
    else
      v17 = 634;
    v22 = v17;
  }
  v12 = CEvn_Event::CEvn_Event(&v28, v22, (unsigned int)dword_4032248, v24 | (a2 << 16), 0);
  v11 = v12;
  LOBYTE(v29) = 4;
  IEventEngine::SendAMessage(g_pEvnEngine, v12);
  LOBYTE(v29) = 1;
  CEvn_Event::~CEvn_Event(&v28);
  LOBYTE(v29) = 0;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>(v10);
  v29 = -1;
  return std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>(v21);
}


// address=[0x14d0830]
// Decompiled from int CTextMsgHandler::RefreshList()
static void __cdecl CTextMsgHandler::RefreshList(void) {
  
  int **v0; // eax
  _DWORD v2[2]; // [esp-Ch] [ebp-68h] BYREF
  int v3; // [esp-4h] [ebp-60h]
  _BYTE v4[12]; // [esp+4h] [ebp-58h] BYREF
  _BYTE v5[12]; // [esp+10h] [ebp-4Ch] BYREF
  _BYTE v6[12]; // [esp+1Ch] [ebp-40h] BYREF
  int v7; // [esp+28h] [ebp-34h]
  _DWORD *v8; // [esp+2Ch] [ebp-30h]
  int v9; // [esp+30h] [ebp-2Ch]
  int v10; // [esp+34h] [ebp-28h]
  void *v11; // [esp+38h] [ebp-24h]
  void *C; // [esp+3Ch] [ebp-20h]
  const char *StringName; // [esp+40h] [ebp-1Ch]
  std::_Iterator_base12 *v14; // [esp+44h] [ebp-18h]
  std::_Iterator_base12 *v15; // [esp+48h] [ebp-14h]
  char v16; // [esp+4Eh] [ebp-Eh]
  char v17; // [esp+4Fh] [ebp-Dh]
  int v18; // [esp+58h] [ebp-4h]

  v17 = 0;
  std::vector<STextMessage *>::begin(v6);
  v18 = 0;
  while ( 1 )
  {
    v15 = (std::_Iterator_base12 *)std::vector<STextMessage *>::end(v5);
    v14 = v15;
    LOBYTE(v18) = 1;
    v16 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator!=(v15);
    LOBYTE(v18) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>(v5);
    if ( !v16 )
      break;
    if ( !*(_BYTE *)(*(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v6)
                   + 29)
      || (v0 = (int **)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v6),
          StringName = (const char *)CS4DefineNames::GetStringName(**v0),
          CTextMsgHandler::CheckWarning(StringName, 0)) )
    {
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator++(v6);
    }
    else
    {
      if ( *(_DWORD *)(*(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v6)
                     + 32) )
      {
        C = *(void **)(*(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v6)
                     + 32);
        operator delete[](C);
        *(_DWORD *)(*(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v6)
                  + 32) = 0;
      }
      v11 = *(void **)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v6);
      v3 = 36;
      operator delete(v11);
      v8 = v2;
      v7 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>((struct std::_Iterator_base12 *)v6);
      v10 = std::vector<STextMessage *>::erase(v4, v2[0], v2[1], v3);
      v9 = v10;
      LOBYTE(v18) = 2;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator=(v10);
      LOBYTE(v18) = 0;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>(v4);
      v17 = 1;
    }
  }
  if ( v17 )
    CTextMsgHandler::SendAllMessages(0, 0, 1);
  v18 = -1;
  return std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>(v6);
}


// address=[0x14d09f0]
// Decompiled from int CTextMsgHandler::Kill()
static void __cdecl CTextMsgHandler::Kill(void) {
  
  int result; // eax
  _DWORD v1[2]; // [esp-Ch] [ebp-48h] BYREF
  int v2; // [esp-4h] [ebp-40h]
  _BYTE v3[12]; // [esp+4h] [ebp-38h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-2Ch] BYREF
  int v5; // [esp+1Ch] [ebp-20h]
  int v6; // [esp+20h] [ebp-1Ch]
  _DWORD *v7; // [esp+24h] [ebp-18h]
  void *v8; // [esp+28h] [ebp-14h]
  void *C; // [esp+2Ch] [ebp-10h]
  int v10; // [esp+38h] [ebp-4h]

  while ( 1 )
  {
    result = std::vector<STextMessage *>::size(&CTextMsgHandler::m_vMsgs);
    if ( !result )
      break;
    std::vector<STextMessage *>::begin(v4);
    v10 = 0;
    if ( *(_DWORD *)(*(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v4)
                   + 32) )
    {
      C = *(void **)(*(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v4)
                   + 32);
      operator delete[](C);
    }
    v8 = *(void **)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v4);
    v2 = 36;
    operator delete(v8);
    v7 = v1;
    v6 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>((struct std::_Iterator_base12 *)v4);
    v5 = std::vector<STextMessage *>::erase(v3, v1[0], v1[1], v2);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>(v3);
    v10 = -1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>(v4);
  }
  return result;
}


// address=[0x14d0ae0]
// Decompiled from unsigned int __cdecl CTextMsgHandler::SetMaxMsgCount(int a1)
static void __cdecl CTextMsgHandler::SetMaxMsgCount(int) {
  
  unsigned int result; // eax
  _DWORD v2[2]; // [esp-Ch] [ebp-6Ch] BYREF
  int v3; // [esp-4h] [ebp-64h]
  _BYTE v4[12]; // [esp+4h] [ebp-5Ch] BYREF
  _BYTE v5[12]; // [esp+10h] [ebp-50h] BYREF
  _BYTE v6[12]; // [esp+1Ch] [ebp-44h] BYREF
  int v7; // [esp+28h] [ebp-38h]
  _DWORD *v8; // [esp+2Ch] [ebp-34h]
  int v9; // [esp+30h] [ebp-30h]
  int v10; // [esp+34h] [ebp-2Ch]
  void *v11; // [esp+38h] [ebp-28h]
  void *C; // [esp+3Ch] [ebp-24h]
  std::_Iterator_base12 *v13; // [esp+40h] [ebp-20h]
  std::_Iterator_base12 *v14; // [esp+44h] [ebp-1Ch]
  BOOL v15; // [esp+48h] [ebp-18h]
  int v16; // [esp+4Ch] [ebp-14h]
  bool v17; // [esp+53h] [ebp-Dh]
  int v18; // [esp+5Ch] [ebp-4h]

  v16 = 0;
  result = CTextMsgHandler::m_iMaxMsgs;
  if ( CTextMsgHandler::m_iMaxMsgs == a1 )
    return result;
  CTextMsgHandler::m_iMaxMsgs = a1;
  result = std::vector<STextMessage *>::size(&CTextMsgHandler::m_vMsgs);
  if ( result < CTextMsgHandler::m_iMaxMsgs )
    return result;
  std::vector<STextMessage *>::begin(v6);
  v18 = 0;
  while ( 1 )
  {
    v14 = (std::_Iterator_base12 *)std::vector<STextMessage *>::end(v5);
    v13 = v14;
    LOBYTE(v18) = 1;
    v16 |= 1u;
    v15 = (unsigned __int8)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator!=(v14)
       && std::vector<STextMessage *>::size(&CTextMsgHandler::m_vMsgs) > (unsigned int)CTextMsgHandler::m_iMaxMsgs;
    v17 = v15;
    v18 = 0;
    if ( (v16 & 1) != 0 )
    {
      v16 &= ~1u;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>(v5);
    }
    if ( !v17 )
      break;
    if ( *(_DWORD *)(*(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v6)
                   + 32) )
    {
      C = *(void **)(*(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v6)
                   + 32);
      operator delete[](C);
      *(_DWORD *)(*(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v6)
                + 32) = 0;
    }
    v11 = *(void **)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v6);
    v3 = 36;
    operator delete(v11);
    v8 = v2;
    v7 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>((struct std::_Iterator_base12 *)v6);
    v10 = std::vector<STextMessage *>::erase(v4, v2[0], v2[1], v3);
    v9 = v10;
    LOBYTE(v18) = 2;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator=(v10);
    LOBYTE(v18) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>(v4);
  }
  v18 = -1;
  return std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>(v6);
}


// address=[0x14d0ca0]
// Decompiled from int __thiscall CTextMsgHandler::GetEventFunction(CTextMsgHandler *this)
void *  CTextMsgHandler::GetEventFunction(void) {
  
  return 0;
}


// address=[0x14d1b20]
// Decompiled from CTextMsgHandler *__thiscall CTextMsgHandler::CTextMsgHandler(CTextMsgHandler *this)
 CTextMsgHandler::CTextMsgHandler(void) {
  
  IEvn_Handle::IEvn_Handle(this);
  *(_DWORD *)this = &CTextMsgHandler::_vftable_;
  return this;
}


// address=[0x3d8a80c]
// [Decompilation failed for static int CTextMsgHandler::m_iMaxMsgs]

// address=[0x4032218]
// [Decompilation failed for static int CTextMsgHandler::m_iUpdateTrigger]

// address=[0x4032228]
// [Decompilation failed for static class std::vector<struct STextMessage *,class std::allocator<struct STextMessage *> > CTextMsgHandler::m_vMsgs]

// address=[0x14cf3e0]
// Decompiled from bool __cdecl CTextMsgHandler::CheckWarning(const char *a1, int *a2)
static bool __cdecl CTextMsgHandler::CheckWarning(char const *,int *) {
  
  int MsgLevelMask; // [esp+0h] [ebp-8h]
  unsigned int v4; // [esp+4h] [ebp-4h]

  if ( ((unsigned __int8 (__thiscall *)(CConfigManager *, const char *, const char *))g_pCfgMgr->j_?DoesExist@CConfigManager@@UAE_NPBD0@Z)(
         g_pCfgMgr,
         "WARNINGMSG_CLASSIFICATION",
         a1) )
  {
    v4 = ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValue)(
           g_pCfgMgr,
           "WARNINGMSG_CLASSIFICATION",
           a1,
           0);
    if ( a2 )
    {
      if ( ((unsigned int)&dword_F29144[220079] & v4) != 0 )
      {
        *a2 = 168;
      }
      else if ( (v4 & 0x10000) != 0 )
      {
        *a2 = 166;
      }
      else if ( (v4 & 0x100) != 0 )
      {
        *a2 = 167;
      }
      else if ( (v4 & 1) != 0 )
      {
        *a2 = 165;
      }
    }
    MsgLevelMask = CGameSettings::GetMsgLevelMask();
    return (v4 & MsgLevelMask) != 0 && (MsgLevelMask & CTextMsgHandler::GetSwitchMask(v4)) != 0;
  }
  else
  {
    BBSupportTracePrintF(0, "CTextMsgHandler::CheckWarning : TextWarningMsg not defined in ConfigMgr :%s", a1);
    return 0;
  }
}


// address=[0x14cf4d0]
// Decompiled from char __cdecl CTextMsgHandler::CheckExists(struct STextMessage *a1)
static bool __cdecl CTextMsgHandler::CheckExists(struct STextMessage *) {
  
  _BYTE v2[12]; // [esp+4h] [ebp-3Ch] BYREF
  _BYTE v3[12]; // [esp+10h] [ebp-30h] BYREF
  _BYTE v4[12]; // [esp+1Ch] [ebp-24h] BYREF
  std::_Iterator_base12 *v5; // [esp+28h] [ebp-18h]
  std::_Iterator_base12 *v6; // [esp+2Ch] [ebp-14h]
  char v7; // [esp+31h] [ebp-Fh]
  char v8; // [esp+32h] [ebp-Eh]
  char v9; // [esp+33h] [ebp-Dh]
  int v10; // [esp+3Ch] [ebp-4h]

  std::vector<STextMessage *>::begin(v4);
  v10 = 0;
  while ( 1 )
  {
    v6 = (std::_Iterator_base12 *)std::vector<STextMessage *>::end(v3);
    v5 = v6;
    LOBYTE(v10) = 1;
    v9 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator!=(v6);
    LOBYTE(v10) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>(v3);
    if ( !v9 )
      break;
    if ( *(_DWORD *)a1 == **(_DWORD **)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v4)
      && *((_DWORD *)a1 + 1) == *(_DWORD *)(*(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v4)
                                          + 4)
      && *((_DWORD *)a1 + 4) == *(_DWORD *)(*(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v4)
                                          + 16)
      && *((_DWORD *)a1 + 5) == *(_DWORD *)(*(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v4)
                                          + 20) )
    {
      v8 = 1;
      v10 = -1;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>(v4);
      return v8;
    }
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator++(v2, 0);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>(v2);
  }
  v7 = 0;
  v10 = -1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>(v4);
  return v7;
}


// address=[0x14cf600]
// Decompiled from char __thiscall CTextMsgHandler::OnEvent(CTextMsgHandler *this, struct CEvn_Event *a2)
bool  CTextMsgHandler::OnEvent(class CEvn_Event &) {
  
  unsigned int event; // [esp+8h] [ebp-8h]

  event = a2->event;
  if ( event > 0x1773 )
  {
    if ( event != 6004 )
      return 0;
    CTextMsgHandler::RefreshList(this);
    return 1;
  }
  if ( event == 6003 )
  {
    CTextMsgHandler::SendAllMessages(0, 0, a2->wparam != 0);
    return 1;
  }
  if ( event != 21 )
  {
    if ( event != 6001 )
      return 0;
    CTextMsgHandler::ExecuteMsg(a2->wparam);
    return 1;
  }
  if ( ++CTextMsgHandler::m_iUpdateTrigger < 20 )
    return 0;
  CTextMsgHandler::m_iUpdateTrigger = 0;
  CTextMsgHandler::Update();
  return 0;
}


// address=[0x14cf6d0]
// Decompiled from void __cdecl CTextMsgHandler::AddMsgToVector(struct STextMessage *a1)
static void __cdecl CTextMsgHandler::AddMsgToVector(struct STextMessage *) {
  
  _DWORD v1[2]; // [esp-Ch] [ebp-4Ch] BYREF
  int v2; // [esp-4h] [ebp-44h]
  _BYTE v3[12]; // [esp+4h] [ebp-3Ch] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-30h] BYREF
  int v5; // [esp+1Ch] [ebp-24h]
  _DWORD *v6; // [esp+20h] [ebp-20h]
  int v7; // [esp+24h] [ebp-1Ch]
  int v8; // [esp+28h] [ebp-18h]
  void *v9; // [esp+2Ch] [ebp-14h]
  void *C; // [esp+30h] [ebp-10h]
  int v11; // [esp+3Ch] [ebp-4h]

  if ( std::vector<STextMessage *>::size(&CTextMsgHandler::m_vMsgs) >= (unsigned int)CTextMsgHandler::m_iMaxMsgs )
  {
    std::vector<STextMessage *>::begin(v4);
    v11 = 0;
    if ( *(_DWORD *)(*(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v4)
                   + 32) )
    {
      C = *(void **)(*(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v4)
                   + 32);
      operator delete[](C);
      *(_DWORD *)(*(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v4)
                + 32) = 0;
    }
    v9 = *(void **)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator*(v4);
    v2 = 36;
    operator delete(v9);
    v6 = v1;
    v5 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>((struct std::_Iterator_base12 *)v4);
    v8 = std::vector<STextMessage *>::erase(v3, v1[0], v1[1], v2);
    v7 = v8;
    LOBYTE(v11) = 1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::operator=(v8);
    LOBYTE(v11) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>(v3);
    v11 = -1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<STextMessage *>>>(v4);
  }
  std::vector<STextMessage *>::push_back(&a1);
  CTextMsgHandler::SendAllMessages(0, 1, 1);
}


// address=[0x14cf800]
// Decompiled from int __cdecl CTextMsgHandler::GetPlayerIcon(int a1)
static int __cdecl CTextMsgHandler::GetPlayerIcon(int) {
  
  int result; // eax

  switch ( a1 )
  {
    case 0:
      result = 505;
      break;
    case 1:
      result = 506;
      break;
    case 2:
      result = 507;
      break;
    case 3:
      result = 508;
      break;
    case 4:
      result = 509;
      break;
    case 5:
      result = 510;
      break;
    case 6:
      result = 511;
      break;
    case 7:
      result = 512;
      break;
    default:
      result = 165;
      break;
  }
  return result;
}


// address=[0x14cf890]
// Decompiled from int __cdecl CTextMsgHandler::GetSwitchMask(unsigned int a1)
static unsigned int __cdecl CTextMsgHandler::GetSwitchMask(unsigned int) {
  
  if ( (_BYTE)a1 )
    return 1;
  if ( (a1 & 0xFF00) != 0 )
    return 256;
  if ( ((unsigned int)&dword_F29144[203695] & a1) != 0 )
    return 0x10000;
  if ( (a1 & 0xFF000000) != 0 )
    return (int)&dword_F29144[220079];
  return 0;
}


