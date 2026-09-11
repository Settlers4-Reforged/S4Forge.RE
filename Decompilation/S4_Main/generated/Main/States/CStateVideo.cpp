#include "CStateVideo.h"

// Definitions for class CStateVideo

// address=[0x14cbb00]
// Decompiled from CStateVideo *__cdecl CStateVideo::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CStateVideo::DynamicCreateFunc(void * a1) {
  
  CStateVideo *C; // [esp+Ch] [ebp-10h]

  C = (CStateVideo *)operator new(0xCu);
  if ( C != 0 )
  {
    return CStateVideo::CStateVideo(C, a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x14cbb80]
// Decompiled from CStateVideo *__thiscall CStateVideo::CStateVideo(CStateVideo *this, void *a2)
 CStateVideo::CStateVideo(void * a2) {
  
  int Language; // [esp+28h] [ebp-34h]
  unsigned int DigitalDriver; // [esp+34h] [ebp-28h]
  IVideoEngine *v5; // [esp+38h] [ebp-24h]
  IVideoEngine *v6; // [esp+3Ch] [ebp-20h]
  int GfxMode; // [esp+44h] [ebp-18h]

  CGameState::CGameState((CGameState *)this);
  *(_DWORD *)this = &CStateVideo::_vftable_;
  if ( g_pGUIEngine != 0 )
  {
    delete g_pGUIEngine;
    g_pGUIEngine = 0;
  }
  if ( g_pDialogData != 0 )
  {
    operator delete[](g_pDialogData);
    g_pDialogData = 0;
  }
  *((_DWORD *)this + 1) = a2;
  if ( *((_DWORD *)this + 1) >= 0xBu && BBSupportDbgReport(2, "Main\\States\\StateVideo.cpp", 176, "m_iVideoIndex < sizeof( g_pszVideoName_DE ) / 4") == 1 )
  {
    __debugbreak();
  }
  DigitalDriver = 0;
  CSoundManager::StopMusic(g_pSoundManager);
  if ( g_pSoundEngine != 0 )
  {
    DigitalDriver = ISoundEngine::GetDigitalDriver(g_pSoundEngine);
  }
  if ( g_pGfxEngine == 0 && BBSupportDbgReport(2, "Main\\States\\StateVideo.cpp", 187, "g_pGfxEngine") == 1 )
  {
    __debugbreak();
  }
  *((_BYTE *)this + 8) = 0;
  *((_BYTE *)this + 9) = 0;
  v6 = (IVideoEngine *)operator new(1u);
  if ( v6 != 0 )
  {
    v5 = IVideoEngine::IVideoEngine(v6);
  }
  else
  {
    v5 = 0;
  }
  g_pVideoEngine = (int)v5;
  IVideoEngine::Init(v5, DigitalDriver);
  if ( (unsigned __int8)sub_14CC580(1) != 0 )
  {
    CStateVideo::AlignVideoSurface(this);
    GfxMode = IGfxEngine::GetGfxMode(g_pGfxEngine);
    if ( GfxMode != 0 )
    {
      if ( GfxMode == 1 )
      {
        IVideoEngine::Set_555_GfxMode((IVideoEngine *)g_pVideoEngine);
      }
      else if ( GfxMode == 2 )
      {
        IVideoEngine::Set_565_GfxMode((IVideoEngine *)g_pVideoEngine);
      }
      Language = CGameSettings::GetLanguage();
      if ( Language == 1 )
      {
        CStateVideo::StartVideo(this, off_3D8A638[*((_DWORD *)this + 1)]);
      }
      else if ( Language == 2 )
      {
        CStateVideo::StartVideo(this, off_3D8A690[*((_DWORD *)this + 1)]);
      }
      else
      {
        CStateVideo::StartVideo(this, off_3D8A664[*((_DWORD *)this + 1)]);
      }
    }
    else
    {
      CTrace::Print("VideoPlayer :\t CStateVideo::StartVideo : Unknown Gfx mode ");
      if ( g_pVideoEngine != 0 )
      {
        delete (IVideoEngine *)g_pVideoEngine;
      }
      g_pVideoEngine = 0;
    }
  }
  else
  {
    if ( g_pVideoEngine != 0 )
    {
      delete (IVideoEngine *)g_pVideoEngine;
    }
    g_pVideoEngine = 0;
  }
  return this;
}


// address=[0x14cbe60]
// Decompiled from void __thiscall CStateVideo::~CStateVideo(CGameState *this)
 CStateVideo::~CStateVideo(void) {
  
  this->__vftable = (CGameState_vtbl *)&CStateVideo::_vftable_;
  if ( g_pVideoEngine != 0 )
  {
    delete (IVideoEngine *)g_pVideoEngine;
    g_pVideoEngine = 0;
  }
  CGameState::~CGameState(this);
}


// address=[0x14cbec0]
// Decompiled from char __thiscall CStateVideo::Perform(CStateVideo *this)
bool  CStateVideo::Perform(void) {
  
  unsigned int v2; // [esp+Ch] [ebp-40h] BYREF
  unsigned __int16 *v3; // [esp+10h] [ebp-3Ch]
  CStateVideo *v4; // [esp+14h] [ebp-38h]
  char v5; // [esp+1Bh] [ebp-31h]
  struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION v6; // [esp+1Ch] [ebp-30h] BYREF
  int v7; // [esp+38h] [ebp-14h]
  int v8; // [esp+3Ch] [ebp-10h]
  int v9; // [esp+40h] [ebp-Ch]
  int v10; // [esp+44h] [ebp-8h]

  v4 = this;
  if ( g_pGfxEngine == 0 && BBSupportDbgReport(2, "Main\\States\\StateVideo.cpp", 273, "g_pGfxEngine") == 1 )
  {
    __debugbreak();
  }
  if ( g_pVideoEngine != 0 )
  {
    if ( *((_BYTE *)v4 + 8) != 0 )
    {
      v5 = 0;
      if ( IVideoEngine::IsReadyForNextFrame((IVideoEngine *)g_pVideoEngine) )
      {
        v3 = IGfxEngine::BeginWriteToSurface(g_pGfxEngine, 0, &v2);
        if ( v3 == 0 )
        {
          v6.m_bDirty = 0;
          v6.m_iWidth = 640;
          v6.m_iHeight = 480;
          v7 = 0;
          v8 = 0;
          v9 = 640;
          v10 = 480;
          v6.m_sDestinationRect.left = 0;
          v6.m_sDestinationRect.top = 0;
          v6.m_sDestinationRect.right = 640;
          v6.m_sDestinationRect.bottom = 480;
          if ( IGfxEngine::CreateGuiSurface(g_pGfxEngine, 0, &v6) == 0 )
          {
            CStateVideo::AlignVideoSurface(v4);
            IGfxEngine::SetVisibilityOfGuiSurface(g_pGfxEngine, 0, 1);
            v3 = IGfxEngine::BeginWriteToSurface(g_pGfxEngine, 0, &v2);
          }
        }
        v5 = IVideoEngine::RenderToSurface((IVideoEngine *)g_pVideoEngine, v3, v2);
        IGfxEngine::EndWriteToSurface(g_pGfxEngine, 0);
        IGfxEngine::RenderFrame(g_pGfxEngine, 0, 0);
        IGfxEngine::ShowFrame(g_pGfxEngine);
        if ( v5 == 0 )
        {
          CStateVideo::EndVideo(v4);
        }
      }
    }
    else
    {
      CStateVideo::EndVideo(v4);
      CGameStateHandler::Next();
    }
    return 1;
  }
  else
  {
    CGameStateHandler::Next();
    return 1;
  }
}


// address=[0x14cc060]
// Decompiled from char __thiscall CStateVideo::OnEvent(CStateVideo *this, struct CEvn_Event *a2)
bool  CStateVideo::OnEvent(class CEvn_Event & a2) {
  
  char result; // al

  switch ( a2->m_iEventId )
  {
    case 3:
      if ( *((_BYTE *)this + 8) != 0 )
      {
        CStateVideo::EndVideo(this);
      }
      result = 1;
      break;
    case 8:
      if ( *((_BYTE *)this + 8) != 0 )
      {
        CStateVideo::EndVideo(this);
      }
      result = 1;
      break;
    case 0xD:
      if ( a2->m_wParam == 27 )
      {
        if ( *((_BYTE *)this + 8) != 0 )
        {
          CStateVideo::EndVideo(this);
        }
        result = 1;
      }
      else
      {
        result = 1;
      }
      break;
    case 0x16:
      if ( *((_BYTE *)this + 8) != 0 )
      {
        if ( a2->m_wParam != 0 )
        {
          CStateVideo::UnPauseVideo(this);
        }
        else
        {
          CStateVideo::PauseVideo(this);
        }
      }
      goto CStateVideo__OnEvent___def_18CC08F;
    default:
CStateVideo__OnEvent___def_18CC08F:
      result = 1;
      break;
  }
  return result;
}


// address=[0x14cc150]
// Decompiled from char __thiscall CStateVideo::StartVideo(CStateVideo *this, char *a2)
bool  CStateVideo::StartVideo(void * a2) {
  
  int CursorShape; // eax
  char *v4; // eax
  char v6[88]; // [esp+Ch] [ebp-A0h] BYREF
  std::string v7; // [esp+64h] [ebp-48h] BYREF
  std::wstring v8; // [esp+80h] [ebp-2Ch] BYREF
  int v9; // [esp+A8h] [ebp-4h]

  if ( g_pGfxEngine == 0 && BBSupportDbgReport(2, "Main\\States\\StateVideo.cpp", 411, "g_pGfxEngine") == 1 )
  {
    __debugbreak();
  }
  if ( g_pVideoEngine == 0 )
  {
    return 0;
  }
  CursorShape = IGfxEngine::GetCursorShape(g_pGfxEngine);
  IGfxEngine::SetCursorShape(g_pGfxEngine, 0, CursorShape);
  std::wstring::wstring(&v8);
  v9 = 0;
  if ( g_pCDDrive->GetCDPath(g_pCDDrive, (char *)&v8, a2, 4194305) != 0 )
  {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v6);
    LOBYTE(v9) = 1;
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes((int)&v7, &v8);
    LOBYTE(v9) = 2;
    v4 = std::string::c_str(&v7);
    if ( IVideoEngine::StartVideo((IVideoEngine *)g_pVideoEngine, v4, 0x280u, 0x1E0u) )
    {
      *((_BYTE *)this + 8) = 1;
      *((_BYTE *)this + 9) = 0;
      LOBYTE(v9) = 1;
      std::string::~string(&v7);
      LOBYTE(v9) = 0;
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v6);
      v9 = -1;
      std::wstring::~wstring(&v8);
      return 1;
    }
    else
    {
      LOBYTE(v9) = 1;
      std::string::~string(&v7);
      LOBYTE(v9) = 0;
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v6);
      v9 = -1;
      std::wstring::~wstring(&v8);
      return 0;
    }
  }
  else
  {
    v9 = -1;
    std::wstring::~wstring(&v8);
    return 0;
  }
}


// address=[0x14cc320]
// Decompiled from char __thiscall CStateVideo::EndVideo(CStateVideo *this)
bool  CStateVideo::EndVideo(void) {
  
  if ( g_pGfxEngine == 0 && BBSupportDbgReport(2, "Main\\States\\StateVideo.cpp", 447, "g_pGfxEngine") == 1 )
  {
    __debugbreak();
  }
  if ( g_pVideoEngine == 0 && BBSupportDbgReport(2, "Main\\States\\StateVideo.cpp", 448, "g_pVideoEngine") == 1 )
  {
    __debugbreak();
  }
  if ( *((_BYTE *)this + 8) != 0 )
  {
    *((_BYTE *)this + 8) = 0;
    *((_BYTE *)this + 9) = 0;
    IVideoEngine::StopVideo((IVideoEngine *)g_pVideoEngine);
  }
  sub_14CC580(0);
  return 1;
}


// address=[0x14cc3b0]
// Decompiled from void __thiscall CStateVideo::PauseVideo(CStateVideo *this)
void  CStateVideo::PauseVideo(void) {
  
  if ( g_pGfxEngine == 0 && BBSupportDbgReport(2, "Main\\States\\StateVideo.cpp", 470, "g_pGfxEngine") == 1 )
  {
    __debugbreak();
  }
  if ( g_pVideoEngine == 0 && BBSupportDbgReport(2, "Main\\States\\StateVideo.cpp", 471, "g_pVideoEngine") == 1 )
  {
    __debugbreak();
  }
  if ( *((_BYTE *)this + 8) != 0 && *((_BYTE *)this + 9) == 0 )
  {
    *((_BYTE *)this + 9) = 1;
    IVideoEngine::PauseVideo((IVideoEngine *)g_pVideoEngine);
  }
}


// address=[0x14cc440]
// Decompiled from void __thiscall CStateVideo::UnPauseVideo(CStateVideo *this)
void  CStateVideo::UnPauseVideo(void) {
  
  if ( g_pGfxEngine == 0 && BBSupportDbgReport(2, "Main\\States\\StateVideo.cpp", 485, "g_pGfxEngine") == 1 )
  {
    __debugbreak();
  }
  if ( g_pVideoEngine == 0 && BBSupportDbgReport(2, "Main\\States\\StateVideo.cpp", 486, "g_pVideoEngine") == 1 )
  {
    __debugbreak();
  }
  if ( *((_BYTE *)this + 8) != 0 && *((_BYTE *)this + 9) == 1 )
  {
    *((_BYTE *)this + 9) = 0;
    IVideoEngine::UnPauseVideo((IVideoEngine *)g_pVideoEngine);
  }
}


// address=[0x14cc4d0]
// Decompiled from void __thiscall CStateVideo::AlignVideoSurface(CStateVideo *this)
void  CStateVideo::AlignVideoSurface(void) {
  
  int OutputWidth; // [esp+8h] [ebp-24h]
  LONG OutputHeight; // [esp+10h] [ebp-1Ch]
  int v3; // [esp+14h] [ebp-18h]
  struct tagRECT v4; // [esp+18h] [ebp-14h] BYREF

  if ( g_pGfxEngine != 0 )
  {
    OutputWidth = IGfxEngine::GetOutputWidth(g_pGfxEngine);
    OutputHeight = IGfxEngine::GetOutputHeight(g_pGfxEngine);
    v3 = (int)(float)((float)OutputHeight * (float)(640.0 / 480.0));
    v4.left = (OutputWidth - v3) / 2;
    v4.top = 0;
    v4.right = v3 + v4.left;
    v4.bottom = OutputHeight;
    IGfxEngine::SetGuiSurfaceDestinationRect(g_pGfxEngine, 0, &v4);
  }
}


