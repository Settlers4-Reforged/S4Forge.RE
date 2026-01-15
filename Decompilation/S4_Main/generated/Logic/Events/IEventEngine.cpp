#include "IEventEngine.h"

// Definitions for class IEventEngine

// address=[0x1352c00]
// Decompiled from IEventEngine *__thiscall IEventEngine::IEventEngine(IEventEngine *this)
 IEventEngine::IEventEngine(void) {
  
  this->__vftable = &IEventEngine::_vftable_;
  this->EventHandleList = 0;
  if ( g_pEvnEngine && BBSupportDbgReport(2, "EventEngine\\EventEngine.cpp", 336, "g_pEvnEngine == 0") == 1 )
    __debugbreak();
  g_pEvnEngine = this;
  this->logFileHandle = 0;
  this->pad_15[0] = 0;
  this->loggingEnabled = 0;
  this->tick = 0;
  this->enabled = 0;
  this->activePrimaryHandler = 0;
  this->field_20 = 0;
  return this;
}


// address=[0x1352c90]
// Decompiled from IEventEngine *__thiscall IEventEngine::~IEventEngine(IEventEngine *this)
 IEventEngine::~IEventEngine(void) {
  
  IEventEngine *result; // eax
  _BYTE v2[12]; // [esp+4h] [ebp-2Ch] BYREF
  IEventEngine *v3; // [esp+10h] [ebp-20h]
  struct CEvn_HandleList *EventHandleList; // [esp+14h] [ebp-1Ch]
  int v5; // [esp+18h] [ebp-18h] BYREF
  struct CEvn_HandleList *v6; // [esp+1Ch] [ebp-14h]
  IEventEngine *v7; // [esp+20h] [ebp-10h]

  v7 = this;
  result = this;
  this->__vftable = &IEventEngine::_vftable_;
  g_pEvnEngine = 0;
  if ( !v7->EventHandleList )
    return result;
  while ( !(unsigned __int8)std::list<IEvn_Handle *>::empty((char *)v7->EventHandleList + 4) )
  {
    std::list<IEvn_Handle *>::begin(v2);
    v5 = *(_DWORD *)std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::operator*(v2);
    std::list<IEvn_Handle *>::remove(&v5);
    std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::~_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>(v2);
  }
  result = v7;
  EventHandleList = v7->EventHandleList;
  v6 = EventHandleList;
  if ( EventHandleList )
  {
    result = (IEventEngine *)(**(int (__thiscall ***)(struct CEvn_HandleList *, int))v6)(v6, 1);
    v3 = result;
  }
  else
  {
    v3 = 0;
  }
  v7->EventHandleList = 0;
  return result;
}


// address=[0x1352d70]
// Decompiled from int (__stdcall *__thiscall IEventEngine::GetEventFunction(  IEventEngine *this))(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
void *  IEventEngine::GetEventFunction(void) {
  
  return WndMsgProc;
}


// address=[0x1352d80]
// Decompiled from char __thiscall IEventEngine::OnEvent(_BYTE *this, _DWORD *a2)
bool  IEventEngine::OnEvent(class CEvn_Event &) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-74h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-68h] BYREF
  std::_Iterator_base12 *v5; // [esp+1Ch] [ebp-5Ch]
  std::_Iterator_base12 *v6; // [esp+20h] [ebp-58h]
  int v7; // [esp+24h] [ebp-54h]
  int v8; // [esp+28h] [ebp-50h]
  DWORD NumberOfBytesWritten; // [esp+2Ch] [ebp-4Ch] BYREF
  _BYTE v10[12]; // [esp+30h] [ebp-48h] BYREF
  unsigned __int8 (__thiscall ***v11)(_DWORD, _DWORD *); // [esp+3Ch] [ebp-3Ch]
  _DWORD *v12; // [esp+40h] [ebp-38h]
  char v13; // [esp+46h] [ebp-32h]
  char v14; // [esp+47h] [ebp-31h]
  _BYTE *v15; // [esp+48h] [ebp-30h]
  _BYTE Buffer[28]; // [esp+4Ch] [ebp-2Ch] BYREF
  int v17; // [esp+74h] [ebp-4h]

  v15 = this;
  if ( this[20] && a2[1] < 0x7Au && a2[1] != 1 && *((_DWORD *)v15 + 6) )
  {
    CEvn_Window::CEvn_Window((CEvn_Window *)Buffer, 0, a2[1], a2[2], a2[3]);
    WriteFile(*((HANDLE *)v15 + 4), *((LPCVOID *)v15 + 6), 4u, &NumberOfBytesWritten, 0);
    WriteFile(*((HANDLE *)v15 + 4), Buffer, 0x1Cu, &NumberOfBytesWritten, 0);
    CEvn_Window::~CEvn_Window(Buffer);
  }
  if ( *((_DWORD *)v15 + 9) )
  {
    v12 = a2 ? a2 + 1 : 0;
    if ( (*((unsigned __int8 (__cdecl **)(_DWORD *))v15 + 9))(v12) )
      return 1;
  }
  if ( !*((_DWORD *)v15 + 1) || (unsigned __int8)std::list<IEvn_Handle *>::empty(*((_DWORD *)v15 + 1) + 4) )
    return 0;
  std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>(v10);
  v17 = 0;
  v8 = std::list<IEvn_Handle *>::begin(v4);
  v7 = v8;
  LOBYTE(v17) = 1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::operator=(v8);
  LOBYTE(v17) = 0;
  std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::~_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>(v4);
  while ( 1 )
  {
    v6 = (std::_Iterator_base12 *)std::list<IEvn_Handle *>::end(v3);
    v5 = v6;
    LOBYTE(v17) = 2;
    v14 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::operator!=(v6);
    LOBYTE(v17) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::~_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>(v3);
    if ( !v14 )
      break;
    v11 = *(unsigned __int8 (__thiscall ****)(_DWORD, _DWORD *))std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::operator*(v10);
    if ( (**v11)(v11, a2) )
    {
      v13 = 1;
      v17 = -1;
      std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::~_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>(v10);
      return v13;
    }
    std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::operator++(v10);
  }
  v17 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::~_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>(v10);
  return 0;
}


// address=[0x1352f90]
// Decompiled from char __thiscall IEventEngine::SendRawWindowEvent(IEventEngine *this, int a2, int a3, int a4, int a5)
bool  IEventEngine::SendRawWindowEvent(unsigned int,unsigned int,unsigned int,unsigned int) {
  
  if ( dword_3ECDA30 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_3ECDA30);
    if ( dword_3ECDA30 == -1 )
    {
      CEvn_Window::CEvn_Window((CEvn_Window *)&dword_3ECDA0C, 0, 0, 0, 0);
      j__atexit(sub_3663A90);
      j___Init_thread_footer(&dword_3ECDA30);
    }
  }
  dword_3ECDA24 = a2;
  dword_3ECDA18 = a5;
  dword_3ECDA10 = a3;
  dword_3ECDA14 = a4;
  byte_3ECDA20 = 0;
  if ( this->tick )
    dword_3ECDA1C = *(_DWORD *)this->tick;
  return IEventEngine::OnEvent(this, &dword_3ECDA0C);
}


// address=[0x1353090]
// Decompiled from char __thiscall IEventEngine::SendRawLogicEvent(  IEventEngine *this,  int a2,  int a3,  int a4,  char a5,  int a6,  __int16 a7)
bool  IEventEngine::SendRawLogicEvent(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int) {
  
  if ( dword_3ECDA08 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_3ECDA08);
    if ( dword_3ECDA08 == -1 )
    {
      CEvn_Logic::CEvn_Logic(&dword_3ECD9E0);
      j__atexit(sub_3663A70);
      j___Init_thread_footer(&dword_3ECDA08);
    }
  }
  dword_3ECD9F8 = a6;
  word_3ECD9FC = a7;
  byte_3ECD9FE = a5;
  dword_3ECD9EC = a4;
  dword_3ECD9E4 = a2;
  dword_3ECD9E8 = a3;
  byte_3ECD9F4 = 0;
  if ( this->tick )
    dword_3ECD9F0 = *(_DWORD *)this->tick;
  return IEventEngine::OnEvent(this, &dword_3ECD9E0);
}


// address=[0x1353190]
// Decompiled from char __thiscall IEventEngine::SendRawEvent(IEventEngine *this, int a2, int a3, int a4)
bool  IEventEngine::SendRawEvent(unsigned int,unsigned int,unsigned int) {
  
  if ( dword_3ECDA50 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_3ECDA50);
    if ( dword_3ECDA50 == -1 )
    {
      CEvn_Event::CEvn_Event((CEvn_Event *)&unk_3ECDA34, 0, 0, 0, 0);
      j__atexit(sub_3663A50);
      j___Init_thread_footer(&dword_3ECDA50);
    }
  }
  dword_3ECDA40 = a4;
  dword_3ECDA38 = a2;
  dword_3ECDA3C = a3;
  byte_3ECDA48 = 0;
  if ( this->tick )
    dword_3ECDA44 = *(_DWORD *)this->tick;
  return IEventEngine::OnEvent(this, &unk_3ECDA34);
}


// address=[0x1353280]
// Decompiled from char __thiscall IEventEngine::RegisterHandle(IEventEngine *this, struct IEvn_Handle *a2)
bool  IEventEngine::RegisterHandle(class IEvn_Handle *) {
  
  _DWORD v3[3]; // [esp-10h] [ebp-5Ch] BYREF
  struct IEvn_Handle **v4; // [esp-4h] [ebp-50h]
  _BYTE v5[12]; // [esp+4h] [ebp-48h] BYREF
  _BYTE v6[12]; // [esp+10h] [ebp-3Ch] BYREF
  int v7; // [esp+1Ch] [ebp-30h]
  int v8; // [esp+20h] [ebp-2Ch]
  _DWORD *v9; // [esp+24h] [ebp-28h]
  int v10; // [esp+28h] [ebp-24h]
  int v11; // [esp+2Ch] [ebp-20h]
  CDaoIndexFieldInfo *v12; // [esp+30h] [ebp-1Ch]
  CDaoIndexFieldInfo *v13; // [esp+34h] [ebp-18h]
  CDaoIndexFieldInfo *v14; // [esp+38h] [ebp-14h]
  IEventEngine *v15; // [esp+3Ch] [ebp-10h]
  int v16; // [esp+48h] [ebp-4h]

  v15 = this;
  if ( !a2 )
    return 0;
  if ( !v15->EventHandleList )
  {
    v14 = (CDaoIndexFieldInfo *)operator new(0x10u);
    v16 = 0;
    if ( v14 )
      v13 = CEvn_HandleList::CEvn_HandleList(v14);
    else
      v13 = 0;
    v12 = v13;
    v16 = -1;
    v15->EventHandleList = v13;
  }
  if ( !v15->EventHandleList )
    return 0;
  v4 = &a2;
  v11 = std::list<IEvn_Handle *>::begin(v5);
  v10 = v11;
  v16 = 1;
  v9 = v3;
  v8 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>(v11);
  v7 = std::list<IEvn_Handle *>::insert(v6, v3[0], v3[1], v3[2], v4);
  std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::~_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>(v6);
  v16 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::~_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>(v5);
  return 1;
}


// address=[0x1353390]
// Decompiled from char __thiscall IEventEngine::SendAMessage(_BYTE *this, _DWORD *a2)
bool  IEventEngine::SendAMessage(class CEvn_Event &) {
  
  return IEventEngine::OnEvent(this, a2);
}


// address=[0x13533b0]
// Decompiled from char __thiscall IEventEngine::UnRegisterHandle(IEventEngine *this, struct IEvn_Handle *a2)
bool  IEventEngine::UnRegisterHandle(class IEvn_Handle *) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-4Ch] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-40h] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-34h] BYREF
  std::_Iterator_base12 *v6; // [esp+28h] [ebp-28h]
  std::_Iterator_base12 *v7; // [esp+2Ch] [ebp-24h]
  int v8; // [esp+30h] [ebp-20h]
  int v9; // [esp+34h] [ebp-1Ch]
  struct IEvn_Handle *v10; // [esp+38h] [ebp-18h] BYREF
  IEventEngine *v11; // [esp+3Ch] [ebp-14h]
  char v12; // [esp+42h] [ebp-Eh]
  char v13; // [esp+43h] [ebp-Dh]
  int v14; // [esp+4Ch] [ebp-4h]

  v11 = this;
  if ( !a2 || (unsigned __int8)std::list<IEvn_Handle *>::empty((char *)v11->EventHandleList + 4) )
    return 0;
  std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>(v5);
  v14 = 0;
  v9 = std::list<IEvn_Handle *>::begin(v4);
  v8 = v9;
  LOBYTE(v14) = 1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::operator=(v9);
  LOBYTE(v14) = 0;
  std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::~_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>(v4);
  while ( 1 )
  {
    v7 = (std::_Iterator_base12 *)std::list<IEvn_Handle *>::end(v3);
    v6 = v7;
    LOBYTE(v14) = 2;
    v13 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::operator!=(v7);
    LOBYTE(v14) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::~_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>(v3);
    if ( !v13 )
      break;
    v10 = *(struct IEvn_Handle **)std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::operator*(v5);
    if ( v10 == a2 )
    {
      std::list<IEvn_Handle *>::remove(&v10);
      v12 = 1;
      v14 = -1;
      std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::~_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>(v5);
      return v12;
    }
    std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::operator++(v5);
  }
  v14 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::~_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>(v5);
  return 0;
}


// address=[0x1353500]
// Decompiled from char __thiscall IEventEngine::DispatchSystemMessages(IEventEngine *this)
bool  IEventEngine::DispatchSystemMessages(void) {
  
  tagMSG Msg; // [esp+4h] [ebp-80h] BYREF
  CEvn_Event *v3; // [esp+20h] [ebp-64h]
  CEvn_Event *v4; // [esp+24h] [ebp-60h]
  struct tagPOINT Point; // [esp+28h] [ebp-5Ch] BYREF
  unsigned int Buffer; // [esp+30h] [ebp-54h] BYREF
  DWORD NumberOfBytesRead; // [esp+34h] [ebp-50h] BYREF
  char v8; // [esp+39h] [ebp-4Bh]
  char v9; // [esp+3Ah] [ebp-4Ah]
  char v10; // [esp+3Bh] [ebp-49h]
  IEventEngine *v11; // [esp+3Ch] [ebp-48h]
  int v12; // [esp+40h] [ebp-44h] BYREF
  int v13; // [esp+44h] [ebp-40h]
  unsigned __int16 v14; // [esp+4Ch] [ebp-38h]
  unsigned __int16 v15; // [esp+4Eh] [ebp-36h]
  int hwnd; // [esp+58h] [ebp-2Ch]
  CEvn_Event v17; // [esp+5Ch] [ebp-28h] BYREF
  int v18; // [esp+80h] [ebp-4h]

  v11 = this;
  Msg.hwnd = (HWND)this->hwnd;
  while ( PeekMessageA(&Msg, 0, 0, 0, 0) )
  {
    if ( !GetMessageA(&Msg, 0, 0, 0) )
      return 0;
    TranslateMessage(&Msg);
    DispatchMessageA(&Msg);
  }
  if ( !v11->pad_15[0] )
    return 1;
  CEvn_Window::CEvn_Window((CEvn_Window *)&v12, 0, 0, 0, 0);
  v18 = 0;
  ReadFile((HANDLE)v11->logFileHandle, &Buffer, 4u, &NumberOfBytesRead, 0);
  if ( NumberOfBytesRead != 4 )
  {
    v11->pad_15[0] = 0;
    CloseHandle((HANDLE)v11->logFileHandle);
    v11->logFileHandle = 0;
    v10 = 1;
    v18 = -1;
    CEvn_Window::~CEvn_Window(&v12);
    return v10;
  }
  if ( v11->tick )
  {
    if ( *(_DWORD *)v11->tick > v11->field_20 )
    {
      v11->pad_15[0] = 0;
      CloseHandle((HANDLE)v11->logFileHandle);
      v11->logFileHandle = 0;
      v4 = CEvn_Event::CEvn_Event(&v17, 0xBu, 0x6Eu, 0, 0);
      v3 = v4;
      LOBYTE(v18) = 1;
      IEventEngine::SendAMessage(v11, v4);
      LOBYTE(v18) = 0;
      CEvn_Event::~CEvn_Event(&v17);
      v9 = 1;
      v18 = -1;
      CEvn_Window::~CEvn_Window(&v12);
      return v9;
    }
    while ( Buffer <= *(_DWORD *)v11->tick )
    {
      ReadFile((HANDLE)v11->logFileHandle, &v12, 0x1Cu, &NumberOfBytesRead, 0);
      if ( NumberOfBytesRead != 28 )
      {
        v11->pad_15[0] = 0;
        CloseHandle((HANDLE)v11->logFileHandle);
        v11->logFileHandle = 0;
        v8 = 1;
        v18 = -1;
        CEvn_Window::~CEvn_Window(&v12);
        return v8;
      }
      hwnd = v11->hwnd;
      if ( v13 != 3 && v13 != 2 )
      {
        if ( v13 == 5 )
        {
          Point.x = v14;
          Point.y = v15;
          ClientToScreen((HWND)v11->hwnd, &Point);
          SetCursorPos(Point.x, Point.y);
        }
        IEventEngine::SendAMessage(v11, &v12);
      }
      ReadFile((HANDLE)v11->logFileHandle, &Buffer, 4u, &NumberOfBytesRead, 0);
      if ( NumberOfBytesRead != 4 )
      {
        v11->pad_15[0] = 0;
        break;
      }
    }
  }
  SetFilePointer((HANDLE)v11->logFileHandle, -4, 0, 1u);
  v18 = -1;
  CEvn_Window::~CEvn_Window(&v12);
  return 1;
}


// address=[0x13537d0]
// Decompiled from IEventEngine *__thiscall IEventEngine::SetOSParam(IEventEngine *this, unsigned int a2)
void  IEventEngine::SetOSParam(unsigned int) {
  
  IEventEngine *result; // eax

  result = this;
  *(_DWORD *)this->gap_8 = a2;
  return result;
}


// address=[0x13537f0]
// Decompiled from char __thiscall IEventEngine::PlayEvents(void *this, void *a2, int a3)
bool  IEventEngine::PlayEvents(std::string const &,int) {
  
  const CHAR *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  DWORD lDistanceToMove; // [esp+0h] [ebp-118h]
  int v11; // [esp+4h] [ebp-114h] BYREF
  int v12; // [esp+8h] [ebp-110h] BYREF
  DWORD NumberOfBytesRead; // [esp+Ch] [ebp-10Ch] BYREF
  void *v14; // [esp+10h] [ebp-108h]
  char Buffer[256]; // [esp+14h] [ebp-104h] BYREF

  v14 = this;
  if ( std::string::length(a2) && !*((_DWORD *)v14 + 4) )
  {
    v3 = (const CHAR *)std::string::c_str(a2);
    *((_DWORD *)v14 + 4) = CreateFileA(v3, 0x80000000, 0, 0, 3u, 0x80u, 0);
    if ( *((_DWORD *)v14 + 4) == -1 )
    {
      v4 = (const char *)std::string::c_str(a2);
      BBSupportTracePrintF(2, "Could not open Event Recorder Slot File \"%s\"!", v4);
      return 0;
    }
    else
    {
      ReadFile(*((HANDLE *)v14 + 4), Buffer, 0x13u, &NumberOfBytesRead, 0);
      if ( strstr(Buffer, "RECORDED S4 EVENTS") && NumberOfBytesRead == 19 )
      {
        ReadFile(*((HANDLE *)v14 + 4), &v12, 4u, &NumberOfBytesRead, 0);
        if ( v12 == 28 )
        {
          lDistanceToMove = SetFilePointer(*((HANDLE *)v14 + 4), 0, 0, 1u);
          SetFilePointer(*((HANDLE *)v14 + 4), -32, 0, 2u);
          ReadFile(*((HANDLE *)v14 + 4), &v11, 4u, &NumberOfBytesRead, 0);
          if ( NumberOfBytesRead == 4 )
          {
            *((_DWORD *)v14 + 8) = v11 - a3;
            SetFilePointer(*((HANDLE *)v14 + 4), lDistanceToMove, 0, 0);
            *((_BYTE *)v14 + 21) = 1;
            v8 = (const char *)std::string::c_str(a2);
            BBSupportTracePrintF(2, "Playing event from file \"%s\"!", v8);
            return 1;
          }
          else
          {
            v7 = (const char *)std::string::c_str(a2);
            BBSupportTracePrintF(2, "-3- Incompatible Event Recorder Slot File \"%s\"!", v7);
            return 0;
          }
        }
        else
        {
          v6 = (const char *)std::string::c_str(a2);
          BBSupportTracePrintF(2, "-2- Incompatible Event Recorder Slot File \"%s\"!", v6);
          return 0;
        }
      }
      else
      {
        v5 = (const char *)std::string::c_str(a2);
        BBSupportTracePrintF(2, "-1- Incompatible Event Recorder Slot File \"%s\"!", v5);
        return 0;
      }
    }
  }
  else
  {
    *((_BYTE *)v14 + 21) = 0;
    if ( !*((_DWORD *)v14 + 4) )
      return 1;
    CloseHandle(*((HANDLE *)v14 + 4));
    *((_DWORD *)v14 + 4) = 0;
    BBSupportTracePrintF(2, "EventEngine.cpp: Replay of events stopped!", 0);
    return 1;
  }
}


// address=[0x1353a60]
// Decompiled from char __thiscall IEventEngine::RecordEvents(void *this, void *a2)
bool  IEventEngine::RecordEvents(std::string const &) {
  
  const CHAR *v3; // eax
  const char *v4; // eax
  int Buffer; // [esp+0h] [ebp-Ch] BYREF
  DWORD NumberOfBytesWritten; // [esp+4h] [ebp-8h] BYREF

  if ( std::string::length(a2) && !*((_DWORD *)this + 4) )
  {
    v3 = (const CHAR *)std::string::c_str(a2);
    *((_DWORD *)this + 4) = CreateFileA(v3, 0x40000000u, 0, 0, 2u, 0x80u, 0);
    if ( *((_DWORD *)this + 4) == -1 )
    {
      BBSupportTracePrint(2, "Could not open Event Recorder Slot File!");
      return 0;
    }
    WriteFile(*((HANDLE *)this + 4), "RECORDED S4 EVENTS", 0x13u, &NumberOfBytesWritten, 0);
    Buffer = 28;
    WriteFile(*((HANDLE *)this + 4), &Buffer, 4u, &NumberOfBytesWritten, 0);
    *((_BYTE *)this + 20) = 1;
  }
  else
  {
    *((_BYTE *)this + 20) = 0;
    if ( !*((_DWORD *)this + 4) )
      return 1;
    CloseHandle(*((HANDLE *)this + 4));
    *((_DWORD *)this + 4) = 0;
    BBSupportTracePrint(2, "EventEngine.cpp: Event recording stopped!");
  }
  v4 = (const char *)std::string::c_str(a2);
  BBSupportTracePrintF(2, "Recording successfully started into file \"%s\"!", v4);
  return 1;
}


// address=[0x1353b60]
// Decompiled from void __thiscall IEventEngine::SetGuiEventProc(IEventEngine *this, unsigned int a2)
void  IEventEngine::SetGuiEventProc(bool (__cdecl*)(struct SEventStruct &)) {
  
  this->activePrimaryHandler = (unsigned __int8 (__cdecl *)(struct SEventStruct *))a2;
}


// address=[0x1355880]
// Decompiled from bool __thiscall IEventEngine::IsEventEngineLocked(ATL::CImage *this)
bool  IEventEngine::IsEventEngineLocked(void) {
  
  return *((_BYTE *)this + 28);
}


// address=[0x135e0f0]
// Decompiled from void __thiscall IEventEngine::SetOSParam1(IEventEngine *this, HWND a2)
void  IEventEngine::SetOSParam1(unsigned int) {
  
  this->hwnd = a2;
}


// address=[0x148fed0]
// Decompiled from IEventEngine *__thiscall IEventEngine::LockEventEngine(IEventEngine *this, char a2)
void  IEventEngine::LockEventEngine(bool) {
  
  IEventEngine *result; // eax

  result = this;
  this->enabled = a2;
  return result;
}


// address=[0x14aaba0]
// Decompiled from int __thiscall IEventEngine::GetCurrentTickCounter(IEventEngine *this)
unsigned int  IEventEngine::GetCurrentTickCounter(void) {
  
  if ( this->tick )
    return *(_DWORD *)this->tick;
  else
    return 0;
}


// address=[0x14ab030]
// Decompiled from void __thiscall IEventEngine::SetTickPointer(IEventEngine *this, struct CPaneContainer *a2)
void  IEventEngine::SetTickPointer(unsigned int *) {
  
  this->tick = (int)a2;
}


// address=[0x14b4720]
// Decompiled from char __thiscall IEventEngine::IsEventPlaying(IEventEngine *this)
bool  IEventEngine::IsEventPlaying(void) {
  
  return this->pad_15[0];
}


// address=[0x14b4740]
// Decompiled from char __thiscall IEventEngine::IsEventRecording(IEventEngine *this)
bool  IEventEngine::IsEventRecording(void) {
  
  return *((_BYTE *)this + 20);
}


