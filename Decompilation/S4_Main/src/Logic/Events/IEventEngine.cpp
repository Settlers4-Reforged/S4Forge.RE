#include "IEventEngine.h"

#include <windows.h>
#include "Debug/CTrace.h"
#include "CBB/CBBSupport.h"
#include "./CEvn_Event.h"
#include "./CEvn_Logic.h"
#include "./CEvn_Window.h"
#include "./IEvn_Handle.h"
#include "Framework.h"

// Definitions for class IEventEngine

IEventEngine *g_pEvnEngine;

int GetEvnInterfaceVersion() {
  return 5;
}

// address=[0x1358690]
void IEventEngine::Init() {
  IEventEngine *engine; // [esp+8h] [ebp-14h]
  IEventEngine *C;      // [esp+Ch] [ebp-10h]

  if(!g_pEvnEngine) {
    if(GetEvnInterfaceVersion() == 5) {
      g_pEvnEngine = new IEventEngine();
      g_pEvnEngine->SetGuiEventProc(GuiEngine2_EventProc);
    } else {
      MessageBoxA(g_hWnd, "Wrong version of event engine!", "Error:", 48u);
      CTrace::Print("Wrong version of evn engine!");
    }
  }
}

// address=[0x1352c00]
// Decompiled from IEventEngine *__thiscall IEventEngine::IEventEngine(IEventEngine *this)
IEventEngine::IEventEngine(void) {
  this->m_pEventHandleList = 0;
  if(g_pEvnEngine && BBSupportDbgReport(2, "EventEngine\\EventEngine.cpp", 336, "g_pEvnEngine == 0") == 1)
    __debugbreak();
  g_pEvnEngine = this;
  this->m_hReplayFile = 0;
  this->m_bIsEventPlaying = 0;
  this->m_bIsEventRecording = 0;
  this->m_pTick = 0;
  this->m_bLocked = 0;
  this->m_pGuiEventProc = 0;
  this->m_uLastReplayTick = 0;
}

// address=[0x1352c90]
// Decompiled from void __thiscall IEventEngine::~IEventEngine(IEventEngine *this)
IEventEngine::~IEventEngine(void) {
  g_pEvnEngine = 0;
  if(this->m_pEventHandleList) {
    this->m_pEventHandleList->clear();
    delete this->m_pEventHandleList;
    this->m_pEventHandleList = 0;
  }
}

// address=[0x1352d70]
// Decompiled from int (__stdcall *__thiscall IEventEngine::GetEventFunction(  IEventEngine *this))(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
void *IEventEngine::GetEventFunction(void) {
  return WndMsgProc;
}

// address=[0x1352d80]
// Decompiled from char __thiscall IEventEngine::OnEvent(IEventEngine *this, struct CEvn_Event *a2)
bool IEventEngine::OnEvent(class CEvn_Event &_rEvent) {
  if(this->m_bIsEventRecording && _rEvent.m_iEventId < 0x7Au && _rEvent.m_iEventId != 1 && this->m_pTick) {
    DWORD       NumberOfBytesWritten = 0;
    CEvn_Window windowEvent = CEvn_Window(0, _rEvent.m_iEventId, _rEvent.m_wParam, _rEvent.m_lParam);
    WriteFile(this->m_hReplayFile, this->m_pTick, 4u, &NumberOfBytesWritten, 0);
    WriteFile(this->m_hReplayFile, &windowEvent, 0x1Cu, &NumberOfBytesWritten, 0);
  }
  if(this->m_pGuiEventProc) {
    if(this->m_pGuiEventProc(static_cast<SEventStruct &>(_rEvent)))
      return 1;
  }
  if(!this->m_pEventHandleList || this->m_pEventHandleList->empty()) {
    return 0;
  }

  for(auto handler: *this->m_pEventHandleList) {
    if(handler->OnEvent(_rEvent)) {
      return true;
    }
  }

  return 0;
}

// address=[0x1352f90]
// Decompiled from char __thiscall IEventEngine::SendRawWindowEvent(IEventEngine *this, struct HNWD *a2, int a3, int a4, int a5)
bool IEventEngine::SendRawWindowEvent(unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5) {
  static CEvn_Window s_sRawWindowEvent = CEvn_Window(0, 0, 0, 0);
  s_sRawWindowEvent.m_hWnd = reinterpret_cast<HWND>(a2);
  s_sRawWindowEvent.m_lParam = a5;
  s_sRawWindowEvent.m_iEventId = a3;
  s_sRawWindowEvent.m_wParam = a4;
  s_sRawWindowEvent.m_iFlags = 0;
  if(this->m_pTick)
    s_sRawWindowEvent.m_iTick = *this->m_pTick;
  return this->OnEvent(s_sRawWindowEvent);
}

// address=[0x1353090]
// Decompiled from char __thiscall IEventEngine::SendRawLogicEvent(IEventEngine *this, int a2, int a3, int a4, BYTE a5, BYTE *a6, WORD a7)
bool IEventEngine::SendRawLogicEvent(unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7) {
  static CEvn_Logic s_sRawLogicEvent = CEvn_Logic();
  s_sRawLogicEvent.m_iData = reinterpret_cast<void *>(a6);
  s_sRawLogicEvent.m_iDataSize = a7;
  s_sRawLogicEvent.m_iOwner = a5;
  s_sRawLogicEvent.m_lParam = a4;
  s_sRawLogicEvent.m_iEventId = a2;
  s_sRawLogicEvent.m_wParam = a3;
  s_sRawLogicEvent.m_iFlags = 0;
  if(this->m_pTick)
    s_sRawLogicEvent.m_iTick = *this->m_pTick;
  return this->OnEvent(s_sRawLogicEvent);
}

// address=[0x1353190]
// Decompiled from char __thiscall IEventEngine::SendRawEvent(IEventEngine *this, int a2, int a3, int a4)
bool IEventEngine::SendRawEvent(unsigned int a2, unsigned int a3, unsigned int a4) {
  static CEvn_Event s_sRawEvent = CEvn_Event(0, 0, 0, 0);
  s_sRawEvent.m_lParam = a4;
  s_sRawEvent.m_iEventId = a2;
  s_sRawEvent.m_wParam = a3;
  s_sRawEvent.m_iFlags = 0;
  if(this->m_pTick)
    s_sRawEvent.m_iTick = *this->m_pTick;
  return this->OnEvent(s_sRawEvent);
}

// address=[0x1353280]
// Decompiled from char __thiscall IEventEngine::RegisterHandle(IEventEngine *this, struct IEvn_Handle *a2)
bool IEventEngine::RegisterHandle(class IEvn_Handle *_pHandle) {
  if(!_pHandle)
    return false;

  if(!this->m_pEventHandleList) {
    this->m_pEventHandleList = new CEvn_HandleList();
  }

  if(!this->m_pEventHandleList)
    return false;

  this->m_pEventHandleList->push_front(_pHandle);
  return true;
}

// address=[0x1353390]
// Decompiled from char __thiscall IEventEngine::SendAMessage(IEventEngine *this, struct CEvn_Event *_rEvent)
bool IEventEngine::SendAMessage(class CEvn_Event &_rEvent) {
  return this->OnEvent(_rEvent);
}

// address=[0x13533b0]
// Decompiled from char __thiscall IEventEngine::UnRegisterHandle(IEventEngine *this, struct IEvn_Handle *a2)
bool IEventEngine::UnRegisterHandle(class IEvn_Handle *a2) {
  _BYTE                  v3[12];              // [esp+4h] [ebp-4Ch] BYREF
  _BYTE                  v4[12];              // [esp+10h] [ebp-40h] BYREF
  _BYTE                  v5[12];              // [esp+1Ch] [ebp-34h] BYREF
  std::_Iterator_base12 *v6; // [esp+28h] [ebp-28h]
  std::_Iterator_base12 *v7; // [esp+2Ch] [ebp-24h]
  int                    v8;                    // [esp+30h] [ebp-20h]
  int                    v9;                    // [esp+34h] [ebp-1Ch]
  struct IEvn_Handle *   v10;   // [esp+38h] [ebp-18h] BYREF
  char                   v12;                  // [esp+42h] [ebp-Eh]
  char                   v13;                  // [esp+43h] [ebp-Dh]
  int                    v14;                   // [esp+4Ch] [ebp-4h]

  if(!a2 || this->m_pEventHandleList->empty())
    return false;


  for(auto it = this->m_pEventHandleList->begin(); it != this->m_pEventHandleList->end(); ++it) {
    IEvn_Handle *handle = *it;
    if(handle == a2) {
      this->m_pEventHandleList->remove(handle);
      return true;
    }
  }

  return false;
}

// address=[0x1353500]
// Decompiled from char __thiscall IEventEngine::DispatchSystemMessages(IEventEngine *this)
bool IEventEngine::DispatchSystemMessages(void) {
  tagMSG          Msg;              // [esp+4h] [ebp-80h] BYREF
  _DWORD *        v3;              // [esp+20h] [ebp-64h]
  struct tagPOINT Point;   // [esp+28h] [ebp-5Ch] BYREF
  char            v8;                 // [esp+39h] [ebp-4Bh]
  char            v9;                 // [esp+3Ah] [ebp-4Ah]
  char            v10;                // [esp+3Bh] [ebp-49h]
  int             ExceptionBlock;      // [esp+80h] [ebp-4h]

  Msg.hwnd = (HWND) this->m_hWnd;
  while(PeekMessageA(&Msg, 0, 0, 0, 0)) {
    if(!GetMessageA(&Msg, 0, 0, 0))
      return 0;
    TranslateMessage(&Msg);
    DispatchMessageA(&Msg);
  }

  if(!this->m_bIsEventPlaying)
    return 1;

  // EVENT REPLAY:

  CEvn_Window capturedWindowEvent = CEvn_Window(0, 0, 0, 0);
  // EXCEPTION HANDLING

  DWORD NumberOfBytesRead = 0;

  unsigned int iTicksinReplay = 0;
  ReadFile(this->m_hReplayFile, &iTicksinReplay, 4u, &NumberOfBytesRead, 0);
  if(NumberOfBytesRead != 4) {
    this->m_bIsEventPlaying = 0;
    CloseHandle(this->m_hReplayFile);
    this->m_hReplayFile = 0;
    // EXCEPTION HANDLING
    return true;
  }

  if(this->m_pTick) {
    if(*this->m_pTick > this->m_uLastReplayTick) {
      this->m_bIsEventPlaying = 0;
      CloseHandle(this->m_hReplayFile);
      this->m_hReplayFile = 0;
      CEvn_Event v4 = CEvn_Event(0xBu, 0x6Eu, 0, 0);
      // EXCEPTION HANDLING
      this->SendAMessage(v4);
      // EXCEPTION HANDLING
      // EXCEPTION HANDLING
      return true;
    }
    while(iTicksinReplay <= *this->m_pTick) {
      ReadFile(this->m_hReplayFile, &capturedWindowEvent, 0x1Cu, &NumberOfBytesRead, 0);
      if(NumberOfBytesRead != 28) {
        this->m_bIsEventPlaying = 0;
        CloseHandle(this->m_hReplayFile);
        this->m_hReplayFile = 0;
        // EXCEPTION HANDLING
        return true;
      }
      capturedWindowEvent.m_hWnd = reinterpret_cast<HWND>(this->m_hWnd);
      if(capturedWindowEvent.m_iEventId != 3 && capturedWindowEvent.m_iEventId != 2) {
        if(capturedWindowEvent.m_iEventId == 5) {
          Point.x = LOWORD(capturedWindowEvent.m_lParam);
          Point.y = HIWORD(capturedWindowEvent.m_lParam);
          ClientToScreen(reinterpret_cast<HWND>(this->m_hWnd), &Point);
          SetCursorPos(Point.x, Point.y);
        }
        this->SendAMessage(capturedWindowEvent);
      }
      ReadFile(this->m_hReplayFile, &iTicksinReplay, 4u, &NumberOfBytesRead, 0);
      if(NumberOfBytesRead != 4) {
        this->m_bIsEventPlaying = 0;
        break;
      }
    }
  }
  SetFilePointer(this->m_hReplayFile, -4, 0, FILE_CURRENT);
  // EXCEPTION HANDLING
  return true;
}

// address=[0x13537d0]
// Decompiled from IEventEngine *__thiscall IEventEngine::SetOSParam(IEventEngine *this, DWORD a2)
void IEventEngine::SetOSParam(unsigned int a2) {
  this->m_pOSParam = a2;
}

// address=[0x13537f0]
// Decompiled from char __thiscall IEventEngine::PlayEvents(IEventEngine *this, void *_pReplayFile, int a3)
bool IEventEngine::PlayEvents(std::string const &_pReplayFile, int _iReplayStopOffset) {
  const CHAR *v3;          // eax
  const char *v4;          // eax
  const char *v5;          // eax
  const char *v6;          // eax
  const char *v7;          // eax
  const char *v8;          // eax
  DWORD       lDistanceToMove;   // [esp+0h] [ebp-118h]
  int         iReplayFileLastTick;                 // [esp+4h] [ebp-114h] BYREF
  int         readFileVersion;   // [esp+8h] [ebp-110h] BYREF
  DWORD       NumberOfBytesRead; // [esp+Ch] [ebp-10Ch] BYREF
  char        Buffer[256];        // [esp+14h] [ebp-104h] BYREF

  if(_pReplayFile.length() && !this->m_hReplayFile) {
    v3 = _pReplayFile.c_str();
    this->m_hReplayFile = CreateFileA(v3, 0x80000000, 0, 0, 3u, 0x80u, 0);
    if(this->m_hReplayFile == (HANDLE) -1) {
      v4 = _pReplayFile.c_str();
      BBSupportTracePrintF(2, "Could not open Event Recorder Slot File \"%s\"!", v4);
      return 0;
    } else {
      ReadFile(this->m_hReplayFile, Buffer, 19u, &NumberOfBytesRead, 0);
      if(strstr(Buffer, "RECORDED S4 EVENTS") && NumberOfBytesRead == 19) {
        ReadFile(this->m_hReplayFile, &readFileVersion, 4u, &NumberOfBytesRead, 0);
        if(readFileVersion == replayFileVersion) {
          lDistanceToMove = SetFilePointer(this->m_hReplayFile, 0, 0, FILE_CURRENT);
          SetFilePointer(this->m_hReplayFile, -32, 0, FILE_END);
          ReadFile(this->m_hReplayFile, &iReplayFileLastTick, 4u, &NumberOfBytesRead, 0);
          if(NumberOfBytesRead == 4) {
            this->m_uLastReplayTick = iReplayFileLastTick - _iReplayStopOffset;
            SetFilePointer(this->m_hReplayFile, lDistanceToMove, 0, FILE_BEGIN);
            this->m_bIsEventPlaying = 1;
            v8 = _pReplayFile.c_str();
            BBSupportTracePrintF(2, "Playing event from file \"%s\"!", v8);
            return 1;
          } else {
            v7 = _pReplayFile.c_str();
            BBSupportTracePrintF(2, "-3- Incompatible Event Recorder Slot File \"%s\"!", v7);
            return 0;
          }
        } else {
          v6 = _pReplayFile.c_str();
          BBSupportTracePrintF(2, "-2- Incompatible Event Recorder Slot File \"%s\"!", v6);
          return 0;
        }
      } else {
        v5 = _pReplayFile.c_str();
        BBSupportTracePrintF(2, "-1- Incompatible Event Recorder Slot File \"%s\"!", v5);
        return 0;
      }
    }
  } else {
    this->m_bIsEventPlaying = 0;
    if(!this->m_hReplayFile)
      return 1;
    CloseHandle(this->m_hReplayFile);
    this->m_hReplayFile = 0;
    BBSupportTracePrintF(2, "EventEngine.cpp: Replay of events stopped!", 0);
    return 1;
  }
}

// address=[0x1353a60]
// Decompiled from char __thiscall IEventEngine::RecordEvents(IEventEngine *this, void *_pTargetFile)
bool IEventEngine::RecordEvents(std::string const &_pTargetFile) {
  const CHAR *v3;             // eax
  const char *v4;             // eax
  DWORD       NumberOfBytesWritten; // [esp+4h] [ebp-8h] BYREF

  if(_pTargetFile.length() && !this->m_hReplayFile) {
    v3 = _pTargetFile.c_str();
    this->m_hReplayFile = CreateFileA(v3, 0x40000000u, 0, 0, 2u, 0x80u, 0);
    if(this->m_hReplayFile == (HANDLE) -1) {
      BBSupportTracePrint(2, "Could not open Event Recorder Slot File!");
      return 0;
    }
    WriteFile(this->m_hReplayFile, "RECORDED S4 EVENTS", 0x13u, &NumberOfBytesWritten, 0);

    WriteFile(this->m_hReplayFile, &replayFileVersion, 4u, &NumberOfBytesWritten, 0);
    this->m_bIsEventRecording = 1;
  } else {
    this->m_bIsEventRecording = 0;
    if(!this->m_hReplayFile)
      return 1;
    CloseHandle(this->m_hReplayFile);
    this->m_hReplayFile = 0;
    BBSupportTracePrint(2, "EventEngine.cpp: Event recording stopped!");
  }
  v4 = _pTargetFile.c_str();
  BBSupportTracePrintF(2, "Recording successfully started into file \"%s\"!", v4);
  return 1;
}

// address=[0x1353b60]
// Decompiled from void __thiscall IEventEngine::SetGuiEventProc(IEventEngine *this, bool (__cdecl *a2)(struct SEventStruct *))
void IEventEngine::SetGuiEventProc(bool (__cdecl *a2)(struct SEventStruct &)) {
  this->m_pGuiEventProc = a2;
}

// address=[0x1355880]
// Decompiled from bool __thiscall IEventEngine::IsEventEngineLocked(struct IEventEngine *this)
bool IEventEngine::IsEventEngineLocked(void) {
  return this->m_bLocked;
}

// address=[0x135e0f0]
// Decompiled from void __thiscall IEventEngine::SetOSParam1(IEventEngine *this, HWND a2)
void IEventEngine::SetOSParam1(unsigned int a2) {
  this->m_hWnd = a2;
}

// address=[0x148fed0]
// Decompiled from void __thiscall IEventEngine::LockEventEngine(IEventEngine *this, char a2)
void IEventEngine::LockEventEngine(bool a2) {
  this->m_bLocked = a2;
}

// address=[0x14aaba0]
// Decompiled from int __thiscall IEventEngine::GetCurrentTickCounter(IEventEngine *this)
unsigned int IEventEngine::GetCurrentTickCounter(void) {
  if(this->m_pTick)
    return *this->m_pTick;
  else
    return 0;
}

// address=[0x14ab030]
// Decompiled from void __thiscall IEventEngine::SetTickPointer(IEventEngine *this, struct CPaneContainer *a2)
void IEventEngine::SetTickPointer(unsigned int *a2) {
  this->m_pTick = a2;
}

// address=[0x14b4720]
// Decompiled from bool __thiscall IEventEngine::IsEventPlaying(IEventEngine *this)
bool IEventEngine::IsEventPlaying(void) {
  return this->m_bIsEventPlaying;
}

// address=[0x14b4740]
// Decompiled from BYTE __thiscall IEventEngine::IsEventRecording(IEventEngine *this)
bool IEventEngine::IsEventRecording(void) {
  return this->m_bIsEventRecording;
}
