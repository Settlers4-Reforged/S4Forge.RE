#include "IVideoEngine.h"

// Definitions for class IVideoEngine

// address=[0x16a20b0]
// Decompiled from IVideoEngine *__thiscall IVideoEngine::IVideoEngine(IVideoEngine *this)
 IVideoEngine::IVideoEngine(void) {
  
  CBinkInterface *v3; // [esp+Ch] [ebp-14h]
  CBinkInterface *C; // [esp+10h] [ebp-10h]

  if ( g_pVideo && BBSupportDbgReport(2, "VideoEngine\\VideoEngineInterface.cpp", 36, "g_pVideo == NULL") == 1 )
    __debugbreak();
  C = (CBinkInterface *)operator new(8u);
  if ( C )
    v3 = CBinkInterface::CBinkInterface(C);
  else
    v3 = 0;
  g_pVideo = (int)v3;
  return this;
}


// address=[0x16a2160]
// Decompiled from void __thiscall IVideoEngine::~IVideoEngine(IVideoEngine *this)
 IVideoEngine::~IVideoEngine(void) {
  
  if ( g_pVideo )
  {
    CBinkInterface::CloseBink((CBinkInterface *)g_pVideo);
    if ( g_pVideo )
      CBinkInterface::`scalar deleting destructor'((CBinkInterface *)g_pVideo, 1u);
    g_pVideo = 0;
  }
}


// address=[0x16a21e0]
// Decompiled from char __thiscall IVideoEngine::Init(IVideoEngine *this, unsigned int a2)
bool  IVideoEngine::Init(unsigned int) {
  
  if ( !g_pVideo && BBSupportDbgReport(2, "VideoEngine\\VideoEngineInterface.cpp", 59, "g_pVideo") == 1 )
    __debugbreak();
  if ( !a2 )
    return 0;
  CBinkInterface::UseMiles((CBinkInterface *)g_pVideo, a2);
  return 1;
}


// address=[0x16a2230]
// Decompiled from char __thiscall IVideoEngine::StartVideo(IVideoEngine *this, char *a2, unsigned int a3, unsigned int a4)
bool  IVideoEngine::StartVideo(char *,unsigned int,unsigned int) {
  
  return CBinkInterface::OpenVideo((CBinkInterface *)g_pVideo, a2, a3, a4);
}


// address=[0x16a2260]
// Decompiled from char __thiscall IVideoEngine::StopVideo(IVideoEngine *this)
bool  IVideoEngine::StopVideo(void) {
  
  CBinkInterface::CloseBink((CBinkInterface *)g_pVideo);
  return 1;
}


// address=[0x16a2280]
// Decompiled from int __thiscall IVideoEngine::PauseVideo(IVideoEngine *this)
void  IVideoEngine::PauseVideo(void) {
  
  return CBinkInterface::StartPause((CBinkInterface *)g_pVideo);
}


// address=[0x16a22a0]
// Decompiled from int __thiscall IVideoEngine::UnPauseVideo(IVideoEngine *this)
void  IVideoEngine::UnPauseVideo(void) {
  
  return CBinkInterface::StopPause((CBinkInterface *)g_pVideo);
}


// address=[0x16a22c0]
// Decompiled from int IVideoEngine::GetVideoHeight()
int  IVideoEngine::GetVideoHeight(void) {
  
  if ( !g_pVideo && BBSupportDbgReport(2, "VideoEngine\\VideoEngineInterface.cpp", 116, "g_pVideo") == 1 )
    __debugbreak();
  return CBinkInterface::GetHeight((CBinkInterface *)g_pVideo);
}


// address=[0x16a2300]
// Decompiled from int IVideoEngine::GetVideoWidth()
int  IVideoEngine::GetVideoWidth(void) {
  
  if ( !g_pVideo && BBSupportDbgReport(2, "VideoEngine\\VideoEngineInterface.cpp", 126, "g_pVideo") == 1 )
    __debugbreak();
  return CBinkInterface::GetWidth((CBinkInterface *)g_pVideo);
}


// address=[0x16a2340]
// Decompiled from CBinkInterface *__thiscall IVideoEngine::Set_555_GfxMode(IVideoEngine *this)
void  IVideoEngine::Set_555_GfxMode(void) {
  
  if ( !g_pVideo && BBSupportDbgReport(2, "VideoEngine\\VideoEngineInterface.cpp", 146, "g_pVideo") == 1 )
    __debugbreak();
  return CBinkInterface::Set_555_GfxMode((CBinkInterface *)g_pVideo);
}


// address=[0x16a2380]
// Decompiled from CBinkInterface *__thiscall IVideoEngine::Set_565_GfxMode(IVideoEngine *this)
void  IVideoEngine::Set_565_GfxMode(void) {
  
  if ( !g_pVideo && BBSupportDbgReport(2, "VideoEngine\\VideoEngineInterface.cpp", 153, "g_pVideo") == 1 )
    __debugbreak();
  return CBinkInterface::Set_565_GfxMode((CBinkInterface *)g_pVideo);
}


// address=[0x16a23c0]
// Decompiled from char __thiscall IVideoEngine::RenderToSurface(IVideoEngine *this, unsigned __int16 *a2, unsigned int a3)
bool  IVideoEngine::RenderToSurface(unsigned short *,unsigned int) {
  
  if ( !g_pVideo && BBSupportDbgReport(2, "VideoEngine\\VideoEngineInterface.cpp", 136, "g_pVideo") == 1 )
    __debugbreak();
  return CBinkInterface::RenderToSurface((CBinkInterface *)g_pVideo, a2, a3);
}


// address=[0x16a2410]
// Decompiled from bool __thiscall IVideoEngine::IsReadyForNextFrame(IVideoEngine *this)
bool  IVideoEngine::IsReadyForNextFrame(void) {
  
  if ( !g_pVideo && BBSupportDbgReport(2, "VideoEngine\\VideoEngineInterface.cpp", 163, "g_pVideo") == 1 )
    __debugbreak();
  return CBinkInterface::IsReadyForNextFrame((CBinkInterface *)g_pVideo);
}


