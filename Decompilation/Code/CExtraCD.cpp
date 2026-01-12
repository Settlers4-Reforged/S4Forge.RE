#include "CExtraCD.h"

// Definitions for class CExtraCD

// address=[0x1481700]
// Decompiled from CExtraCD *__thiscall CExtraCD::CExtraCD(CExtraCD *this)
 CExtraCD::CExtraCD(void) {
  
  IExtraCD::IExtraCD(this);
  *(_DWORD *)this = &CExtraCD::_vftable_;
  *((_DWORD *)this + 1) = 0;
  *((_BYTE *)this + 8) = 0;
  *((_BYTE *)this + 9) = 0;
  return this;
}


// address=[0x1481740]
// Decompiled from IExtraCD *__thiscall CExtraCD::~CExtraCD(void **this)
 CExtraCD::~CExtraCD(void) {
  
  *this = &CExtraCD::_vftable_;
  if ( this[1] )
  {
    operator delete[](this[1]);
    this[1] = 0;
  }
  *((_BYTE *)this + 8) = 0;
  *((_BYTE *)this + 9) = 0;
  return IExtraCD::~IExtraCD((IExtraCD *)this);
}


// address=[0x14817a0]
// Decompiled from char __thiscall CExtraCD::IsExtraInstalled(CExtraCD *this)
bool  CExtraCD::IsExtraInstalled(void) {
  
  if ( *((_BYTE *)this + 8) )
    return *((_BYTE *)this + 9);
  *((_BYTE *)this + 8) = 1;
  *((_BYTE *)this + 9) = (*(int (__thiscall **)(CExtraCD *))(*(_DWORD *)this + 16))(this);
  return *((_BYTE *)this + 9);
}


// address=[0x14817e0]
// Decompiled from char __thiscall CExtraCD::EnsureMainGUI(CExtraCD *this, int a2, bool (__cdecl *a3)(int, int, int))
void  CExtraCD::EnsureMainGUI(int,bool (__cdecl*)(int,int,int)) {
  
  return CExtraCD::EnsureGuiEngineHasGfxFileLoaded(this, 0, (int)g_pDialogData, a2, a3, 0);
}


// address=[0x1481810]
// Decompiled from char __thiscall CExtraCD::EnsureGuiEngineHasGfxFileLoaded(  CExtraCD *this,  unsigned int a2,  int a3,  int a4,  bool (__cdecl *a5)(int, int, int),  bool a6)
void  CExtraCD::EnsureGuiEngineHasGfxFileLoaded(unsigned int,void *,int,bool (__cdecl*)(int,int,int),bool) {
  
  unsigned int ActiveGUIGFXFile; // eax
  CGUIWrapper *Instance; // [esp+4h] [ebp-4h]

  Instance = (CGUIWrapper *)CGUIWrapper::GetInstance(this);
  if ( !Instance
    && BBSupportDbgReportF(2, "main\\ExtraCD.cpp", 286, "CExtraCD::EnsureMainGUI: couldn't get GUIWrapper!") == 1 )
  {
    __debugbreak();
  }
  if ( !a3 && BBSupportDbgReport(2, "main\\ExtraCD.cpp", 288, "_pMenuData") == 1 )
    __debugbreak();
  if ( !a6 )
  {
    ActiveGUIGFXFile = CGUIWrapper::GetActiveGUIGFXFile(Instance);
    if ( ActiveGUIGFXFile == a2 )
      return ActiveGUIGFXFile;
  }
  LOBYTE(ActiveGUIGFXFile) = CGUIWrapper::RebuildGuiEngineWithGfxFile(Instance, a2, a3, a4, a5);
  if ( (_BYTE)ActiveGUIGFXFile )
    return ActiveGUIGFXFile;
  if ( BBSupportDbgReportF(2, "main\\ExtraCD.cpp", 301, "CExtraCD::EnsureMainGUI: couldn't activate Main GUI file!") == 1 )
    __debugbreak();
  LOBYTE(ActiveGUIGFXFile) = 0;
  return ActiveGUIGFXFile;
}


// address=[0x14818e0]
// Decompiled from char __cdecl CExtraCD::ExistsFile(wchar_t *FileName)
static bool __cdecl CExtraCD::ExistsFile(wchar_t const *) {
  
  int v2; // [esp+0h] [ebp-94h] BYREF
  char v3; // [esp+12h] [ebp-82h]
  char v4; // [esp+13h] [ebp-81h]
  _DWORD v5[26]; // [esp+14h] [ebp-80h] BYREF
  _DWORD v6[3]; // [esp+7Ch] [ebp-18h] BYREF
  int v7; // [esp+90h] [ebp-4h]

  v6[2] = &v2;
  v4 = 1;
  CFileEx::CFileEx((CFileEx *)v5, 1);
  v7 = 1;
  CFileEx::Open(v6, FileName, 6, 0, UNUSED_ARG(), UNUSED_ARG());
  CFileEx::Close((CFileEx *)v6, UNUSED_ARG(), UNUSED_ARG());
  v3 = v4;
  v7 = -1;
  CFileEx::~CFileEx(v5);
  return v3;
}


// address=[0x14819b0]
// Decompiled from char __cdecl CExtraCD::ExistsFiles(wchar_t **a1)
static bool __cdecl CExtraCD::ExistsFiles(wchar_t const * *) {
  
  wchar_t **i; // [esp+0h] [ebp-4h]
  int v3; // [esp+0h] [ebp-4h]

  if ( !a1 )
    return 0;
  for ( i = a1; *i; i = (wchar_t **)(v3 + 4) )
  {
    if ( !(unsigned __int8)CExtraCD::ExistsFile(*i, (int)i) )
      return 0;
  }
  return 1;
}


// address=[0x1481a00]
// Decompiled from int __thiscall CExtraCD::LoadMenuData(void **this, wchar_t *FileName)
void  CExtraCD::LoadMenuData(wchar_t const *) {
  
  size_t v2; // eax
  int v3; // eax
  int v5; // [esp+4h] [ebp-8Ch]
  _DWORD v7[26]; // [esp+14h] [ebp-7Ch] BYREF
  int v8; // [esp+7Ch] [ebp-14h] BYREF
  int v9; // [esp+8Ch] [ebp-4h]

  if ( this[1] )
  {
    operator delete[](this[1]);
    this[1] = 0;
  }
  CFileEx::CFileEx((CFileEx *)v7, 1);
  v9 = 0;
  CFileEx::Open(&v8, FileName, 6, 0, UNUSED_ARG(), UNUSED_ARG());
  v2 = CFileEx::Size(v7);
  this[1] = operator new[](v2);
  v3 = CFileEx::Size(v7);
  v5 = CFileEx::Read(&v8, this[1], 1, v3, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\FileEx.h", 110);
  if ( v5 != CFileEx::Size(v7) && BBSupportDbgReport(2, "main\\ExtraCD.cpp", 246, "iSize == cFile.Size()") == 1 )
    __debugbreak();
  CFileEx::Close((CFileEx *)&v8, UNUSED_ARG(), UNUSED_ARG());
  v9 = -1;
  return CFileEx::~CFileEx(v7);
}


