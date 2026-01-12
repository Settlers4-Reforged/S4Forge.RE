#include "IHJBMgr.h"

// Definitions for class IHJBMgr

// address=[0x14b4790]
// Decompiled from char IHJBMgr::LocalIsHJBAllowed()

static bool __cdecl IHJBMgr::LocalIsHJBAllowed(void) {
  
  if ( IHJBMgr::m_iLocalHJBAllowed < 0 )
    return (*(int (__thiscall **)(void *))(*(_DWORD *)g_pHJBMgr + 24))(g_pHJBMgr);
  else
    return IHJBMgr::m_iLocalHJBAllowed > 0;
}


// address=[0x1574d70]
// Decompiled from IHJBMgr *__thiscall IHJBMgr::IHJBMgr(IHJBMgr *this)

 IHJBMgr::IHJBMgr(void) {
  
  *(_DWORD *)this = IHJBMgr::_vftable_;
  return this;
}


// address=[0x1575bd0]
// Decompiled from int IHJBMgr::GetHJBEntityId()

static int __cdecl IHJBMgr::GetHJBEntityId(void) {
  
  return IHJBMgr::m_iHJBEntityId;
}


// address=[0x1575be0]
// Decompiled from int IHJBMgr::GetHJBPlayerId()

static int __cdecl IHJBMgr::GetHJBPlayerId(void) {
  
  return IHJBMgr::m_iHJBPlayerId;
}


// address=[0x1580100]
// Decompiled from bool IHJBMgr::LocalIsHJBGfxLoaded()

static bool __cdecl IHJBMgr::LocalIsHJBGfxLoaded(void) {
  
  return IHJBMgr::m_iLocalHJBGfxLoaded > 0;
}


// address=[0x1575c30]
// Decompiled from void __cdecl IHJBMgr::SetHJBEntityId(struct CFrameWnd *a1)

static void __cdecl IHJBMgr::SetHJBEntityId(int) {
  
  IHJBMgr::m_iHJBEntityId = (int)a1;
}


// address=[0x1575c40]
// Decompiled from void __cdecl IHJBMgr::SetHJBPlayerId(struct CFrameWnd *a1)

static void __cdecl IHJBMgr::SetHJBPlayerId(int) {
  
  IHJBMgr::m_iHJBPlayerId = (int)a1;
}


// address=[0x3d8bed0]
// [Decompilation failed for static int IHJBMgr::m_iLocalHJBAllowed]

// address=[0x3d8bed4]
// [Decompilation failed for static int IHJBMgr::m_iLocalHJBGfxLoaded]

// address=[0x3d8bed8]
// [Decompilation failed for static int IHJBMgr::m_iHJBEntityId]

// address=[0x41520d0]
// [Decompilation failed for static int IHJBMgr::m_iHJBPlayerId]

