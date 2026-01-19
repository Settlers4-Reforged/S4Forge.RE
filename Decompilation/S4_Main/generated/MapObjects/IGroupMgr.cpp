#if FALSE
#include "IGroupMgr.h"

// Definitions for class IGroupMgr

// address=[0x1550a40]
// Decompiled from void __cdecl IGroupMgr::FillGroupSideBar(struct CInfoExchange *pInfoExchange, char a2, int a4)
void __cdecl IGroupMgr::FillGroupSideBar(class CInfoExchange * pInfoExchange, bool a2, int a3) {
  
  CGroupMgr::FillGroupSideBarEx((CGroupMgr *)&g_sGroupManager, pInfoExchange, a2, a4);
}


// address=[0x1550a60]
// Decompiled from void __cdecl IGroupMgr::FillMagicSideBar(struct CInfoExchange *_pInfoExchange, char _bSpecialSidebar, int unused)
void __cdecl IGroupMgr::FillMagicSideBar(class CInfoExchange * _pInfoExchange, bool _bSpecialSidebar, int unused) {
  
  CGroupMgr::FillMagicSideBarEx(_pInfoExchange, _bSpecialSidebar, unused);
}


// address=[0x15525e0]
// Decompiled from IGroupMgr *__thiscall IGroupMgr::IGroupMgr(IGroupMgr *this)
 IGroupMgr::IGroupMgr(void) {
  
  IS4ChunkObject::IS4ChunkObject(this);
  this->__vftable = (IGroupMgr_vtbl *)IGroupMgr::_vftable_;
  return this;
}


#endif // Already implemented
