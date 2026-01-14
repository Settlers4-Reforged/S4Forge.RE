#include "all_headers.h"

// Definitions for class CStateSlideshow

// address=[0x14ca870]
// Decompiled from CStateSlideshow *__cdecl CStateSlideshow::DynamicCreateFunc(void *a1)
static class CGameState * __cdecl CStateSlideshow::DynamicCreateFunc(void *) {
  
  CStateSlideshow *C; // [esp+Ch] [ebp-10h]

  C = (CStateSlideshow *)operator new(0x18u);
  if ( C )
    return CStateSlideshow::CStateSlideshow(C, a1);
  else
    return 0;
}


// address=[0x14ca8f0]
// Decompiled from CStateSlideshow *__thiscall CStateSlideshow::CStateSlideshow(CStateSlideshow *this, void *a2)
 CStateSlideshow::CStateSlideshow(void *) {
  
  CGameState::CGameState(this);
  *(_DWORD *)this = &CStateSlideshow::_vftable_;
  *((_BYTE *)this + 4) = 0;
  *((_DWORD *)this + 2) = a2;
  CSlideshow::CSlideshow((CStateSlideshow *)((char *)this + 12), *((_DWORD *)this + 2));
  if ( !g_pGfxEngine || !(unsigned __int8)IGfxEngine::IsGuiMode(g_pGfxEngine) )
    CGameStateHandler::RebuildGfxEngine(1);
  if ( !CSlideshow::Advance((CStateSlideshow *)((char *)this + 12)) )
    *((_BYTE *)this + 4) = 1;
  return this;
}


// address=[0x14ca9b0]
// Decompiled from void __thiscall CStateSlideshow::~CStateSlideshow(CStateSlideshow *this)
 CStateSlideshow::~CStateSlideshow(void) {
  
  char v1; // [esp-38h] [ebp-74h] BYREF
  int v2; // [esp-34h] [ebp-70h]
  int v3; // [esp-30h] [ebp-6Ch]
  int v4; // [esp-2Ch] [ebp-68h]
  int v5; // [esp-28h] [ebp-64h]
  int v6; // [esp-24h] [ebp-60h]
  int v7; // [esp-20h] [ebp-5Ch]
  char v8[32]; // [esp-1Ch] [ebp-58h] BYREF
  char *v9; // [esp+4h] [ebp-38h]
  char *v10; // [esp+8h] [ebp-34h]
  CGameState *v11; // [esp+Ch] [ebp-30h]
  _BYTE v12[28]; // [esp+10h] [ebp-2Ch] BYREF

  v11 = this;
  *(_DWORD *)this = &CStateSlideshow::_vftable_;
  if ( *((_DWORD *)v11 + 2) == 1 )
  {
    std::string::string(v12, (char *)&dword_3755768[1]);
    v10 = v8;
    std::string::string(v8, (char *)off_3755774 + 1);
    v9 = &v1;
    std::string::string(v12);
    CGameStateHandler::ShowHTMLPage(v1, v2, v3, v4, v5, v6, v7, v8[0]);
    std::string::~string(v12);
  }
  CSlideshow::~CSlideshow((CGameState *)((char *)v11 + 12));
  CGameState::~CGameState(v11);
}


// address=[0x14caa60]
// Decompiled from char __thiscall CStateSlideshow::Perform(CStateSlideshow *this)
bool  CStateSlideshow::Perform(void) {
  
  DWORD v2; // esi
  CEvn_Event *v3; // [esp+8h] [ebp-34h]
  CEvn_Event v5; // [esp+14h] [ebp-28h] BYREF
  int v6; // [esp+38h] [ebp-4h]

  if ( *((_BYTE *)this + 4) && *((_DWORD *)this + 2) == 1 )
    return 0;
  if ( *((_BYTE *)this + 4) )
  {
    v3 = CEvn_Event::CEvn_Event(&v5, 0xDu, 0x20u, 0, 0);
    v6 = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, v3);
    v6 = -1;
    CEvn_Event::~CEvn_Event(&v5);
    *((_BYTE *)this + 4) = 0;
  }
  if ( dword_40320B0 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_40320B0);
    if ( dword_40320B0 == -1 )
    {
      dword_40320AC = timeGetTime();
      j___Init_thread_footer(&dword_40320B0);
    }
  }
  v2 = dword_40320AC + 30;
  if ( v2 >= timeGetTime() )
    return 1;
  dword_40320AC = timeGetTime();
  IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
  IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
  return 1;
}


// address=[0x14caba0]
// Decompiled from char __thiscall CStateSlideshow::OnEvent(CStateSlideshow *this, struct CEvn_Event *a2)
bool  CStateSlideshow::OnEvent(class CEvn_Event &) {
  
  CEvn_Event *v3; // [esp+8h] [ebp-38h]
  int event; // [esp+14h] [ebp-2Ch]
  CEvn_Event v5; // [esp+18h] [ebp-28h] BYREF
  int v6; // [esp+3Ch] [ebp-4h]

  event = a2->event;
  if ( event == 7 )
  {
    v3 = CEvn_Event::CEvn_Event(&v5, 0xDu, 0x20u, 0, 0);
    v6 = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, v3);
    v6 = -1;
    CEvn_Event::~CEvn_Event(&v5);
    return 1;
  }
  else if ( event == 13 )
  {
    if ( a2->wparam == 32 )
    {
      if ( !CSlideshow::Advance((CStateSlideshow *)((char *)this + 12)) )
        CGameStateHandler::Next();
      return 1;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    return CGameState::OnEvent((int)a2);
  }
}


