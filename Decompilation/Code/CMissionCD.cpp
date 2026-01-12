#include "CMissionCD.h"

// Definitions for class CMissionCD

// address=[0x1481b40]
// Decompiled from char __thiscall CMissionCD::IsExtraInstalledEx(CMissionCD *this)
bool  CMissionCD::IsExtraInstalledEx(void) {
  
  return CExtraCD::ExistsFiles(s_pMissionDiskFiles);
}


// address=[0x1481b60]
// Decompiled from char __thiscall CMissionCD::EnsureExtraGUI(CMissionCD *this, int a2, bool (__cdecl *a3)(int, int, int))
void  CMissionCD::EnsureExtraGUI(int,bool (__cdecl*)(int,int,int)) {
  
  if ( !*((_DWORD *)this + 1) )
    CExtraCD::LoadMenuData((wchar_t *)L"Menu\\GuiSetMDStartscreens.dat");
  return CExtraCD::EnsureGuiEngineHasGfxFileLoaded(this, 0x12u, *((_DWORD *)this + 1), a2, a3, 0);
}


// address=[0x1481f80]
// Decompiled from CMissionCD *__thiscall CMissionCD::CMissionCD(CMissionCD *this)
 CMissionCD::CMissionCD(void) {
  
  CExtraCD::CExtraCD(this);
  *(_DWORD *)this = &CMissionCD::_vftable_;
  return this;
}


// address=[0x1482030]
// Decompiled from IExtraCD *__thiscall CMissionCD::~CMissionCD(void **this)
 CMissionCD::~CMissionCD(void) {
  
  return CExtraCD::~CExtraCD(this);
}


