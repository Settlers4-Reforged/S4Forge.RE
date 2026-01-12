#include "CAddOn.h"

// Definitions for class CAddOn

// address=[0x1481ba0]
// Decompiled from char __thiscall CAddOn::IsExtraInstalledEx(CAddOn *this)

bool  CAddOn::IsExtraInstalledEx(void) {
  
  return CExtraCD::ExistsFiles(s_pAddOnDiskFiles);
}


// address=[0x1481bc0]
// Decompiled from char __thiscall CAddOn::EnsureExtraGUI(CAddOn *this, int a2, bool (__cdecl *a3)(int, int, int))

void  CAddOn::EnsureExtraGUI(int,bool (__cdecl*)(int,int,int)) {
  
  CExtraCD::LoadMenuData((wchar_t *)L"Menu\\GuiSetAOStartscreens.dat");
  return CExtraCD::EnsureGuiEngineHasGfxFileLoaded(this, 0x1Cu, *((_DWORD *)this + 1), a2, a3, 1);
}


// address=[0x1481ef0]
// Decompiled from CAddOn *__thiscall CAddOn::CAddOn(CAddOn *this)

 CAddOn::CAddOn(void) {
  
  CExtraCD::CExtraCD(this);
  *(_DWORD *)this = &CAddOn::_vftable_;
  return this;
}


// address=[0x1481fd0]
// Decompiled from IExtraCD *__thiscall CAddOn::~CAddOn(void **this)

 CAddOn::~CAddOn(void) {
  
  return CExtraCD::~CExtraCD(this);
}


