#include "all_headers.h"

// Definitions for class IGroupMgr

// address=[0x1550a40]
// Decompiled from int __cdecl IGroupMgr::FillGroupSideBar(void **a1, char a2, int a3)
static void __cdecl IGroupMgr::FillGroupSideBar(class CInfoExchange *,bool,int) {
  
  return CGroupMgr::FillGroupSideBarEx(a1, a2, a3);
}


// address=[0x1550a60]
// Decompiled from int __cdecl IGroupMgr::FillMagicSideBar(void **a1, char a2, int a3)
static void __cdecl IGroupMgr::FillMagicSideBar(class CInfoExchange *,bool,int) {
  
  return CGroupMgr::FillMagicSideBarEx(a1, a2, a3);
}


// address=[0x15525e0]
// Decompiled from IGroupMgr *__thiscall IGroupMgr::IGroupMgr(IGroupMgr *this)
 IGroupMgr::IGroupMgr(void) {
  
  IS4ChunkObject::IS4ChunkObject(this);
  *(_DWORD *)this = IGroupMgr::_vftable_;
  return this;
}


