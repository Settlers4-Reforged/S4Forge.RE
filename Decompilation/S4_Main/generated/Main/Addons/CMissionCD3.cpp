#include "CMissionCD3.h"

// Definitions for class CMissionCD3

// address=[0x1481c60]
// Decompiled from char __thiscall CMissionCD3::IsExtraInstalledEx(CMissionCD3 *this)
bool  CMissionCD3::IsExtraInstalledEx(void) {
  
  return CExtraCD::ExistsFiles(s_pMissionDisk3Files);
}


// address=[0x1481c80]
// Decompiled from char __thiscall CMissionCD3::EnsureExtraGUI(CMissionCD3 *this, int a2, bool (__cdecl *a3)(int, int, int))
void  CMissionCD3::EnsureExtraGUI(int,bool (__cdecl*)(int,int,int)) {
  
  if ( !*((_DWORD *)this + 1) )
    CExtraCD::LoadMenuData((wchar_t *)L"Menu\\GuiSetXMD3Startscreens.dat");
  return CExtraCD::EnsureGuiEngineHasGfxFileLoaded(this, 0x28u, *((_DWORD *)this + 1), a2, a3, 0);
}


// address=[0x1481f50]
// Decompiled from CMissionCD3 *__thiscall CMissionCD3::CMissionCD3(CMissionCD3 *this)
 CMissionCD3::CMissionCD3(void) {
  
  CExtraCD::CExtraCD(this);
  *(_DWORD *)this = &CMissionCD3::_vftable_;
  return this;
}


// address=[0x1482010]
// Decompiled from IExtraCD *__thiscall CMissionCD3::~CMissionCD3(void **this)
 CMissionCD3::~CMissionCD3(void) {
  
  return CExtraCD::~CExtraCD(this);
}


