#include "CMissionCD2.h"

// Definitions for class CMissionCD2

// address=[0x1481c00]
// Decompiled from char __thiscall CMissionCD2::IsExtraInstalledEx(CMissionCD2 *this)
bool  CMissionCD2::IsExtraInstalledEx(void) {
  
  return CExtraCD::ExistsFiles(s_pMissionDisk2Files);
}


// address=[0x1481c20]
// Decompiled from char __thiscall CMissionCD2::EnsureExtraGUI(CMissionCD2 *this, int a2, bool (__cdecl *a3)(int, int, int))
void  CMissionCD2::EnsureExtraGUI(int,bool (__cdecl*)(int,int,int)) {
  
  if ( !*((_DWORD *)this + 1) )
    CExtraCD::LoadMenuData((wchar_t *)L"Menu\\GuiSetMD2Startscreens.dat");
  return CExtraCD::EnsureGuiEngineHasGfxFileLoaded(this, 0x28u, *((_DWORD *)this + 1), a2, a3, 0);
}


// address=[0x1481f20]
// Decompiled from CMissionCD2 *__thiscall CMissionCD2::CMissionCD2(CMissionCD2 *this)
 CMissionCD2::CMissionCD2(void) {
  
  CExtraCD::CExtraCD(this);
  *(_DWORD *)this = &CMissionCD2::_vftable_;
  return this;
}


// address=[0x1481ff0]
// Decompiled from IExtraCD *__thiscall CMissionCD2::~CMissionCD2(void **this)
 CMissionCD2::~CMissionCD2(void) {
  
  return CExtraCD::~CExtraCD(this);
}


