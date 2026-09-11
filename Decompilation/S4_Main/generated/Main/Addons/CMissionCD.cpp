#include "CMissionCD.h"

// Definitions for class CMissionCD

// address=[0x1481b40]
// Decompiled from char __thiscall CMissionCD::IsExtraInstalledEx(CMissionCD *this)
bool  CMissionCD::IsExtraInstalledEx(void) {
  
  return CExtraCD::ExistsFiles(s_pMissionDiskFiles);
}


// address=[0x1481b60]
// Decompiled from char __thiscall CMissionCD::EnsureExtraGUI(CMissionCD *this, int a2, bool (__cdecl *a3)(int, int, int))
void  CMissionCD::EnsureExtraGUI(int a2, bool (__cdecl*)(int,int,int) a3) {
  
  if ( this->m_u4 == 0 )
  {
    ((void (__stdcall *)(wchar_t *))CExtraCD::LoadMenuData)((wchar_t *)L"Menu\\GuiSetMDStartscreens.dat");
  }
  return CExtraCD::EnsureGuiEngineHasGfxFileLoaded(this, 0x12u, this->m_u4, a2, a3, 0);
}


// address=[0x1481f80]
// Decompiled from CMissionCD *__thiscall CMissionCD::CMissionCD(CMissionCD *this)
 CMissionCD::CMissionCD(void) {
  
  CExtraCD::CExtraCD(this);
  this->__vftable = (CMissionCD_vtbl *)&CMissionCD::_vftable_;
  return this;
}


// address=[0x1482030]
// Decompiled from IExtraCD *__thiscall CMissionCD::~CMissionCD(void **this)
 CMissionCD::~CMissionCD(void) {
  
  return CExtraCD::~CExtraCD(this);
}


