#if FALSE
#include "IEventEngine.h"

// Definitions for class IEventEngine

// address=[0x1352c00]
// Decompiled from IEventEngine *__thiscall IEventEngine::IEventEngine(IEventEngine *this)
 IEventEngine::IEventEngine(void) {
  
  this->__vftable = &IEventEngine::_vftable_;
  this->m_pEventHandleList = 0;
  if ( g_pEvnEngine && BBSupportDbgReport(2, "EventEngine\\EventEngine.cpp", 336, "g_pEvnEngine == 0") == 1 )
    __debugbreak();
  g_pEvnEngine = this;
  this->m_hReplayFile = 0;
  this->m_bIsEventPlaying = 0;
  this->m_bIsEventRecording = 0;
  this->m_pTick = 0;
  this->m_bLocked = 0;
  this->m_pGuiEventProc = 0;
  this->field_20 = 0;
  return this;
}


// address=[0x1352c90]
// Decompiled from void __thiscall IEventEngine::~IEventEngine(IEventEngine *this)
 IEventEngine::~IEventEngine(void) {
  
  _BYTE v1[12]; // [esp+4h] [ebp-2Ch] BYREF
  int v2; // [esp+10h] [ebp-20h]
  struct CEvn_HandleList *pEventHandleList; // [esp+14h] [ebp-1Ch] MAPDST
  int v4; // [esp+18h] [ebp-18h] BYREF

  this->__vftable = &IEventEngine::_vftable_;
  g_pEvnEngine = 0;
  if ( this->m_pEventHandleList )
  {
    while ( !(unsigned __int8)std::list<IEvn_Handle *>::empty((char *)this->m_pEventHandleList + 4) )
    {
      std::list<IEvn_Handle *>::begin((char *)this->m_pEventHandleList + 4, (int)v1);
      v4 = *(_DWORD *)std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::operator*((std::_Iterator_base12 *)v1);
      std::list<IEvn_Handle *>::remove((char *)this->m_pEventHandleList + 4, &v4);
      std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::~_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>(v1);
    }
    pEventHandleList = this->m_pEventHandleList;
    if ( pEventHandleList )
      v2 = (**(int (__thiscall ***)(struct CEvn_HandleList *, int))pEventHandleList)(pEventHandleList, 1);
    else
      v2 = 0;
    this->m_pEventHandleList = 0;
  }
}


// address=[0x1352d70]
// Decompiled from int (__stdcall *__thiscall IEventEngine::GetEventFunction(  IEventEngine *this))(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
void *  IEventEngine::GetEventFunction(void) {
  
  return WndMsgProc;
}


// address=[0x1352d80]
// Decompiled from char __thiscall IEventEngine::OnEvent(IEventEngine *this, struct CEvn_Event *a2)
bool  IEventEngine::OnEvent(class CEvn_Event & a2) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-74h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-68h] BYREF
  std::_Iterator_base12 *v5; // [esp+1Ch] [ebp-5Ch]
  std::_Iterator_base12 *v6; // [esp+20h] [ebp-58h]
  int v7; // [esp+24h] [ebp-54h]
  int v8; // [esp+28h] [ebp-50h]
  DWORD NumberOfBytesWritten; // [esp+2Ch] [ebp-4Ch] BYREF
  _BYTE v10[12]; // [esp+30h] [ebp-48h] BYREF
  unsigned __int8 (__thiscall ***v11)(_DWORD, struct CEvn_Event *); // [esp+3Ch] [ebp-3Ch]
  struct SEventStruct *v12; // [esp+40h] [ebp-38h]
  char v13; // [esp+46h] [ebp-32h]
  char v14; // [esp+47h] [ebp-31h]
  CEvn_Window Buffer; // [esp+4Ch] [ebp-2Ch] BYREF
  int v17; // [esp+74h] [ebp-4h]

  if ( this->m_bIsEventRecording && a2->m_iEventId < 0x7Au && a2->m_iEventId != 1 && this->m_pTick )
  {
    CEvn_Window::CEvn_Window(&Buffer, 0, a2->m_iEventId, a2->m_wParam, a2->m_lParam);
    WriteFile(this->m_hReplayFile, this->m_pTick, 4u, &NumberOfBytesWritten, 0);
    WriteFile(this->m_hReplayFile, &Buffer, 0x1Cu, &NumberOfBytesWritten, 0);
    CEvn_Window::~CEvn_Window(&Buffer);
  }
  if ( this->m_pGuiEventProc )
  {
    v12 = a2 ? &a2->SEventStruct : 0;
    if ( this->m_pGuiEventProc(v12) )
      return 1;
  }
  if ( !this->m_pEventHandleList
    || (unsigned __int8)std::list<IEvn_Handle *>::empty((char *)this->m_pEventHandleList + 4) )
  {
    return 0;
  }
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
    v11 = *(unsigned __int8 (__thiscall ****)(_DWORD, struct CEvn_Event *))std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::operator*(v10);
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
// Decompiled from char __thiscall IEventEngine::SendRawWindowEvent(IEventEngine *this, HWND a2, int a3, int a4, int a5)
bool  IEventEngine::SendRawWindowEvent(unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5) {
  
  if ( dword_3ECDA30 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_3ECDA30);
    if ( dword_3ECDA30 == -1 )
    {
      CEvn_Window::CEvn_Window(&s_sRawWindowEvent, 0, 0, 0, 0);
      j__atexit(sub_3663A90);
      j___Init_thread_footer(&dword_3ECDA30);
    }
  }
  s_sRawWindowEvent.m_hWnd = (struct HNWD *)a2;
  s_sRawWindowEvent.m_lParam = a5;
  s_sRawWindowEvent.m_iEventId = a3;
  s_sRawWindowEvent.m_wParam = a4;
  s_sRawWindowEvent.m_iMsgNr = 0;
  if ( this->m_pTick )
    s_sRawWindowEvent.m_iTick = *this->m_pTick;
  return IEventEngine::OnEvent(this, &s_sRawWindowEvent);
}


// address=[0x1353090]
// Decompiled from char __thiscall IEventEngine::SendRawLogicEvent(IEventEngine *this, int a2, int a3, int a4, BYTE a5, BYTE *a6, WORD a7)
bool  IEventEngine::SendRawLogicEvent(unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7) {
  
  if ( dword_3ECDA08 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_3ECDA08);
    if ( dword_3ECDA08 == -1 )
    {
      CEvn_Logic::CEvn_Logic(&s_sRawLogicEvent);
      j__atexit(sub_3663A70);
      j___Init_thread_footer(&dword_3ECDA08);
    }
  }
  s_sRawLogicEvent.m_iData = a6;
  s_sRawLogicEvent.m_iDataSize = a7;
  s_sRawLogicEvent.m_iOwner = a5;
  s_sRawLogicEvent.m_lParam = a4;
  s_sRawLogicEvent.m_iEventId = a2;
  s_sRawLogicEvent.m_wParam = a3;
  s_sRawLogicEvent.m_iMsgNr = 0;
  if ( this->m_pTick )
    s_sRawLogicEvent.m_iTick = *this->m_pTick;
  return IEventEngine::OnEvent(this, &s_sRawLogicEvent);
}


// address=[0x1353190]
// Decompiled from char __thiscall IEventEngine::SendRawEvent(IEventEngine *this, int a2, int a3, int a4)
bool  IEventEngine::SendRawEvent(unsigned int a2, unsigned int a3, unsigned int a4) {
  
  if ( dword_3ECDA50 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_3ECDA50);
    if ( dword_3ECDA50 == -1 )
    {
      CEvn_Event::CEvn_Event(&s_sRawEvent, 0, 0, 0, 0);
      j__atexit(sub_3663A50);
      j___Init_thread_footer(&dword_3ECDA50);
    }
  }
  s_sRawEvent.m_lParam = a4;
  s_sRawEvent.m_iEventId = a2;
  s_sRawEvent.m_wParam = a3;
  s_sRawEvent.m_iMsgNr = 0;
  if ( this->m_pTick )
    s_sRawEvent.m_iTick = *this->m_pTick;
  return IEventEngine::OnEvent(this, &s_sRawEvent);
}


// address=[0x1353280]
// Decompiled from char __thiscall IEventEngine::RegisterHandle(IEventEngine *this, struct IEvn_Handle *a2)
bool  IEventEngine::RegisterHandle(class IEvn_Handle * a2) {
  
  int v3[3]; // [esp-10h] [ebp-5Ch] BYREF
  struct IEvn_Handle **v4; // [esp-4h] [ebp-50h]
  _BYTE v5[12]; // [esp+4h] [ebp-48h] BYREF
  _BYTE v6[12]; // [esp+10h] [ebp-3Ch] BYREF
  int v7; // [esp+1Ch] [ebp-30h]
  _DWORD *v8; // [esp+20h] [ebp-2Ch]
  int *v9; // [esp+24h] [ebp-28h]
  struct std::_Iterator_base12 *v10; // [esp+28h] [ebp-24h]
  struct std::_Iterator_base12 *v11; // [esp+2Ch] [ebp-20h]
  struct CEvn_HandleList *v12; // [esp+30h] [ebp-1Ch]
  struct CEvn_HandleList *v13; // [esp+34h] [ebp-18h]
  CDaoIndexFieldInfo *v14; // [esp+38h] [ebp-14h]
  int v16; // [esp+48h] [ebp-4h]

  if ( !a2 )
    return 0;
  if ( !this->m_pEventHandleList )
  {
    v14 = (CDaoIndexFieldInfo *)operator new(0x10u);
    v16 = 0;
    if ( v14 )
      v13 = CEvn_HandleList::CEvn_HandleList(v14);
    else
      v13 = 0;
    v12 = v13;
    v16 = -1;
    this->m_pEventHandleList = v13;
  }
  if ( !this->m_pEventHandleList )
    return 0;
  v4 = &a2;
  v11 = (struct std::_Iterator_base12 *)std::list<IEvn_Handle *>::begin((char *)this->m_pEventHandleList + 4, (int)v5);
  v10 = v11;
  v16 = 1;
  v9 = v3;
  v8 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>(
         v3,
         v11);
  v7 = std::list<IEvn_Handle *>::insert((int)v6, v3[0], v3[1], v3[2], (int)v4);
  std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::~_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>(v6);
  v16 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::~_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>(v5);
  return 1;
}


// address=[0x1353390]
// Decompiled from char __thiscall IEventEngine::SendAMessage(IEventEngine *this, struct CEvn_Event *_rEvent)
bool  IEventEngine::SendAMessage(class CEvn_Event & _rEvent) {
  
  return IEventEngine::OnEvent(this, _rEvent);
}


// address=[0x13533b0]
// Decompiled from char __thiscall IEventEngine::UnRegisterHandle(IEventEngine *this, struct IEvn_Handle *a2)
bool  IEventEngine::UnRegisterHandle(class IEvn_Handle * a2) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-4Ch] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-40h] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-34h] BYREF
  std::_Iterator_base12 *v6; // [esp+28h] [ebp-28h]
  std::_Iterator_base12 *v7; // [esp+2Ch] [ebp-24h]
  int v8; // [esp+30h] [ebp-20h]
  int v9; // [esp+34h] [ebp-1Ch]
  struct IEvn_Handle *v10; // [esp+38h] [ebp-18h] BYREF
  char v12; // [esp+42h] [ebp-Eh]
  char v13; // [esp+43h] [ebp-Dh]
  int v14; // [esp+4Ch] [ebp-4h]

  if ( !a2 || (unsigned __int8)std::list<IEvn_Handle *>::empty((char *)this->m_pEventHandleList + 4) )
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
  _DWORD *v3; // [esp+20h] [ebp-64h]
  CEvn_Event *v4; // [esp+24h] [ebp-60h]
  struct tagPOINT Point; // [esp+28h] [ebp-5Ch] BYREF
  unsigned int Buffer; // [esp+30h] [ebp-54h] BYREF
  DWORD NumberOfBytesRead; // [esp+34h] [ebp-50h] BYREF
  char v8; // [esp+39h] [ebp-4Bh]
  char v9; // [esp+3Ah] [ebp-4Ah]
  char v10; // [esp+3Bh] [ebp-49h]
  CEvn_Window v12; // [esp+40h] [ebp-44h] BYREF
  CEvn_Event v13; // [esp+5Ch] [ebp-28h] BYREF
  int ExceptionBlock; // [esp+80h] [ebp-4h]

  Msg.hwnd = (HWND)this->m_hWnd;
  while ( PeekMessageA(&Msg, 0, 0, 0, 0) )
  {
    if ( !GetMessageA(&Msg, 0, 0, 0) )
      return 0;
    TranslateMessage(&Msg);
    DispatchMessageA(&Msg);
  }
  if ( !this->m_bIsEventPlaying )
    return 1;
  CEvn_Window::CEvn_Window(&v12, 0, 0, 0, 0);
  ExceptionBlock = 0;
  ReadFile(this->m_hReplayFile, &Buffer, 4u, &NumberOfBytesRead, 0);
  if ( NumberOfBytesRead != 4 )
  {
    this->m_bIsEventPlaying = 0;
    CloseHandle(this->m_hReplayFile);
    this->m_hReplayFile = 0;
    v10 = 1;
    ExceptionBlock = -1;
    CEvn_Window::~CEvn_Window(&v12);
    return v10;
  }
  if ( this->m_pTick )
  {
    if ( *this->m_pTick > (unsigned int)this->field_20 )
    {
      this->m_bIsEventPlaying = 0;
      CloseHandle(this->m_hReplayFile);
      this->m_hReplayFile = 0;
      v4 = CEvn_Event::CEvn_Event(&v13, 0xBu, 0x6Eu, 0, 0);
      v3 = &v4->__vftable;
      LOBYTE(ExceptionBlock) = 1;
      IEventEngine::SendAMessage(this, v4);
      LOBYTE(ExceptionBlock) = 0;
      CEvn_Event::~CEvn_Event(&v13);
      v9 = 1;
      ExceptionBlock = -1;
      CEvn_Window::~CEvn_Window(&v12);
      return v9;
    }
    while ( Buffer <= *this->m_pTick )
    {
      ReadFile(this->m_hReplayFile, &v12, 0x1Cu, &NumberOfBytesRead, 0);
      if ( NumberOfBytesRead != 28 )
      {
        this->m_bIsEventPlaying = 0;
        CloseHandle(this->m_hReplayFile);
        this->m_hReplayFile = 0;
        v8 = 1;
        ExceptionBlock = -1;
        CEvn_Window::~CEvn_Window(&v12);
        return v8;
      }
      v12.m_hWnd = this->m_hWnd;
      if ( v12.m_iEventId != 3 && v12.m_iEventId != 2 )
      {
        if ( v12.m_iEventId == 5 )
        {
          Point.x = LOWORD(v12.m_lParam);
          Point.y = HIWORD(v12.m_lParam);
          ClientToScreen((HWND)this->m_hWnd, &Point);
          SetCursorPos(Point.x, Point.y);
        }
        IEventEngine::SendAMessage(this, &v12);
      }
      ReadFile(this->m_hReplayFile, &Buffer, 4u, &NumberOfBytesRead, 0);
      if ( NumberOfBytesRead != 4 )
      {
        this->m_bIsEventPlaying = 0;
        break;
      }
    }
  }
  SetFilePointer(this->m_hReplayFile, -4, 0, FILE_CURRENT);
  ExceptionBlock = -1;
  CEvn_Window::~CEvn_Window(&v12);
  return 1;
}


// address=[0x13537d0]
// Decompiled from IEventEngine *__thiscall IEventEngine::SetOSParam(IEventEngine *this, DWORD a2)
void  IEventEngine::SetOSParam(unsigned int a2) {
  
  IEventEngine *result; // eax

  result = this;
  this->m_pOSParam = a2;
  return result;
}


// address=[0x13537f0]
// Decompiled from char __thiscall IEventEngine::PlayEvents(IEventEngine *this, std::string *_pReplayFile, int a3)
bool  IEventEngine::PlayEvents(std::string const & _pReplayFile, int a3) {
  
  char *v3; // eax
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  DWORD lDistanceToMove; // [esp+0h] [ebp-118h]
  int v11; // [esp+4h] [ebp-114h] BYREF
  int replayFileVersion; // [esp+8h] [ebp-110h] BYREF
  DWORD NumberOfBytesRead; // [esp+Ch] [ebp-10Ch] BYREF
  char Buffer[256]; // [esp+14h] [ebp-104h] BYREF

  if ( std::string::length(_pReplayFile) && !this->m_hReplayFile )
  {
    v3 = std::string::c_str(_pReplayFile);
    this->m_hReplayFile = CreateFileA(v3, 0x80000000, 0, 0, 3u, 0x80u, 0);
    if ( this->m_hReplayFile == (HANDLE)-1 )
    {
      v4 = std::string::c_str(_pReplayFile);
      BBSupportTracePrintF(2, "Could not open Event Recorder Slot File \"%s\"!", v4);
      return 0;
    }
    else
    {
      ReadFile(this->m_hReplayFile, Buffer, 19u, &NumberOfBytesRead, 0);
      if ( strstr(Buffer, "RECORDED S4 EVENTS") && NumberOfBytesRead == 19 )
      {
        ReadFile(this->m_hReplayFile, &replayFileVersion, 4u, &NumberOfBytesRead, 0);
        if ( replayFileVersion == 0x1C )
        {
          lDistanceToMove = SetFilePointer(this->m_hReplayFile, 0, 0, FILE_CURRENT);
          SetFilePointer(this->m_hReplayFile, -32, 0, FILE_END);
          ReadFile(this->m_hReplayFile, &v11, 4u, &NumberOfBytesRead, 0);
          if ( NumberOfBytesRead == 4 )
          {
            this->field_20 = v11 - a3;
            SetFilePointer(this->m_hReplayFile, lDistanceToMove, 0, FILE_BEGIN);
            this->m_bIsEventPlaying = 1;
            v8 = std::string::c_str(_pReplayFile);
            BBSupportTracePrintF(2, "Playing event from file \"%s\"!", v8);
            return 1;
          }
          else
          {
            v7 = std::string::c_str(_pReplayFile);
            BBSupportTracePrintF(2, "-3- Incompatible Event Recorder Slot File \"%s\"!", v7);
            return 0;
          }
        }
        else
        {
          v6 = std::string::c_str(_pReplayFile);
          BBSupportTracePrintF(2, "-2- Incompatible Event Recorder Slot File \"%s\"!", v6);
          return 0;
        }
      }
      else
      {
        v5 = std::string::c_str(_pReplayFile);
        BBSupportTracePrintF(2, "-1- Incompatible Event Recorder Slot File \"%s\"!", v5);
        return 0;
      }
    }
  }
  else
  {
    this->m_bIsEventPlaying = 0;
    if ( !this->m_hReplayFile )
      return 1;
    CloseHandle(this->m_hReplayFile);
    this->m_hReplayFile = 0;
    BBSupportTracePrintF(2, "EventEngine.cpp: Replay of events stopped!", 0);
    return 1;
  }
}


// address=[0x1353a60]
// Decompiled from char __thiscall IEventEngine::RecordEvents(IEventEngine *this, void *_pTargetFile)
bool  IEventEngine::RecordEvents(std::string const & _pTargetFile) {
  
  const CHAR *v3; // eax
  const char *v4; // eax
  int replayFileVersion; // [esp+0h] [ebp-Ch] BYREF
  DWORD NumberOfBytesWritten; // [esp+4h] [ebp-8h] BYREF

  if ( std::string::length(_pTargetFile) && !this->m_hReplayFile )
  {
    v3 = (const CHAR *)std::string::c_str(_pTargetFile);
    this->m_hReplayFile = CreateFileA(v3, 0x40000000u, 0, 0, 2u, 0x80u, 0);
    if ( this->m_hReplayFile == (HANDLE)-1 )
    {
      BBSupportTracePrint(2, "Could not open Event Recorder Slot File!");
      return 0;
    }
    WriteFile(this->m_hReplayFile, "RECORDED S4 EVENTS", 0x13u, &NumberOfBytesWritten, 0);
    replayFileVersion = 0x1C;
    WriteFile(this->m_hReplayFile, &replayFileVersion, 4u, &NumberOfBytesWritten, 0);
    this->m_bIsEventRecording = 1;
  }
  else
  {
    this->m_bIsEventRecording = 0;
    if ( !this->m_hReplayFile )
      return 1;
    CloseHandle(this->m_hReplayFile);
    this->m_hReplayFile = 0;
    BBSupportTracePrint(2, "EventEngine.cpp: Event recording stopped!");
  }
  v4 = (const char *)std::string::c_str(_pTargetFile);
  BBSupportTracePrintF(2, "Recording successfully started into file \"%s\"!", v4);
  return 1;
}


// address=[0x1353b60]
// Decompiled from void __thiscall IEventEngine::SetGuiEventProc(IEventEngine *this, bool (__cdecl *a2)(struct SEventStruct *))
void  IEventEngine::SetGuiEventProc(bool (__cdecl*)(struct SEventStruct &) a2) {
  
  this->m_pGuiEventProc = a2;
}


// address=[0x1355880]
// Decompiled from bool __thiscall IEventEngine::IsEventEngineLocked(struct IEventEngine *this)
bool  IEventEngine::IsEventEngineLocked(void) {
  
  return this->m_bLocked;
}


// address=[0x135e0f0]
// Decompiled from void __thiscall IEventEngine::SetOSParam1(IEventEngine *this, HWND a2)
void  IEventEngine::SetOSParam1(unsigned int a2) {
  
  this->m_hWnd = (struct HNWD *)a2;
}


// address=[0x148fed0]
// Decompiled from void __thiscall IEventEngine::LockEventEngine(IEventEngine *this, char a2)
void  IEventEngine::LockEventEngine(bool a2) {
  
  this->m_bLocked = a2;
}


// address=[0x14aaba0]
// Decompiled from int __thiscall IEventEngine::GetCurrentTickCounter(IEventEngine *this)
unsigned int  IEventEngine::GetCurrentTickCounter(void) {
  
  if ( this->m_pTick )
    return *(_DWORD *)this->m_pTick;
  else
    return 0;
}


// address=[0x14ab030]
// Decompiled from void __thiscall IEventEngine::SetTickPointer(IEventEngine *this, _DWORD *a2)
void  IEventEngine::SetTickPointer(unsigned int * a2) {
  
  this->m_pTick = a2;
}


// address=[0x14b4720]
// Decompiled from bool __thiscall IEventEngine::IsEventPlaying(IEventEngine *this)
bool  IEventEngine::IsEventPlaying(void) {
  
  return this->m_bIsEventPlaying;
}


// address=[0x14b4740]
// Decompiled from BYTE __thiscall IEventEngine::IsEventRecording(IEventEngine *this)
bool  IEventEngine::IsEventRecording(void) {
  
  return this->m_bIsEventRecording;
}


#endif // Already implemented
