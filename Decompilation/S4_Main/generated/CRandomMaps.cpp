#include "all_headers.h"

// Definitions for class CRandomMaps

// address=[0x1499230]
// Decompiled from CRandomMaps *__thiscall CRandomMaps::CRandomMaps(CRandomMaps *this)
 CRandomMaps::CRandomMaps(void) {
  
  IRandomMaps::IRandomMaps(this);
  *(_DWORD *)this = &CRandomMaps::_vftable_;
  *((_BYTE *)this + 4) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  return this;
}


// address=[0x1499280]
// Decompiled from void __thiscall CRandomMaps::~CRandomMaps(CRandomMaps *this)
 CRandomMaps::~CRandomMaps(void) {
  
  *(_DWORD *)this = &CRandomMaps::_vftable_;
  CRandomMaps::CleanUp(this);
}


// address=[0x14992d0]
// Decompiled from CRandomMaps *__thiscall CRandomMaps::CleanUp(CRandomMaps *this)
void  CRandomMaps::CleanUp(void) {
  
  CRandomMaps *result; // eax
  int v2; // [esp+18h] [ebp-8h]

  *((_BYTE *)this + 4) = 0;
  if ( *((_DWORD *)this + 2) )
  {
    v2 = *((_DWORD *)this + 2);
    if ( v2 )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v2 + 36))(v2, 1);
    *((_DWORD *)this + 2) = 0;
  }
  if ( *((_DWORD *)this + 3) )
  {
    operator delete[](*((void **)this + 3));
    *((_DWORD *)this + 3) = 0;
  }
  result = this;
  if ( !*((_DWORD *)this + 4) )
    return result;
  result = (CRandomMaps *)*((_DWORD *)this + 4);
  if ( result )
    result = (CRandomMaps *)(***((int (__thiscall ****)(_DWORD, int))this + 4))(*((_DWORD *)this + 4), 1);
  *((_DWORD *)this + 4) = 0;
  return result;
}


// address=[0x14993a0]
// Decompiled from int __thiscall CRandomMaps::GetRandomMapFile(CRandomMaps *this)
class S4::CMapFile *  CRandomMaps::GetRandomMapFile(void) {
  
  return *((_DWORD *)this + 4);
}


// address=[0x14993c0]
// Decompiled from S4::CMapFile *__thiscall CRandomMaps::InitRandomMap(CRandomMaps *this, struct SRandomMapParams *a2)
void  CRandomMaps::InitRandomMap(struct SRandomMapParams &) {
  
  struct CMapFile *v3; // [esp+10h] [ebp-20h]
  CHandleMap *v4; // [esp+14h] [ebp-1Ch]
  CMapGeneratorHost *v5; // [esp+18h] [ebp-18h]
  CMapGeneratorHost *C; // [esp+1Ch] [ebp-14h]

  (*(void (__thiscall **)(CRandomMaps *))(*(_DWORD *)this + 4))(this);
  *((_BYTE *)this + 4) = 1;
  C = (CMapGeneratorHost *)operator new(0x140u);
  if ( C )
    v5 = CMapGeneratorHost::CMapGeneratorHost(C, a2);
  else
    v5 = 0;
  *((_DWORD *)this + 2) = v5;
  *((_DWORD *)this + 3) = operator new[](0xC800u);
  v4 = (CHandleMap *)operator new(0x498u);
  if ( v4 )
    v3 = S4::CMapFile::CMapFile(v4, 0);
  else
    v3 = 0;
  *((_DWORD *)this + 4) = v3;
  InitRandomMap(*((struct IMapGeneratorHost **)this + 2), a2);
  CreatePreview(*((struct IMapGeneratorHost **)this + 2), *((unsigned __int16 **)this + 3), 160);
  return S4::CMapFile::Virtualize(*((S4::CMapFile **)this + 4));
}


// address=[0x1499500]
// Decompiled from char __thiscall CRandomMaps::GenerateRandomMap(CRandomMaps *this)
bool  CRandomMaps::GenerateRandomMap(void) {
  
  if ( !*((_BYTE *)this + 4) )
    return 0;
  GenerateRandomMap(*((struct IMapGeneratorHost **)this + 2));
  CMapGeneratorHost::UploadChunks(*((void ***)this + 2), *((struct S4::CMapFile **)this + 4));
  return 1;
}


// address=[0x1499540]
// Decompiled from int __thiscall CRandomMaps::GetParamsFromMapKey(void *this, int a2, _Cnd_internal_imp_t *a3)
bool  CRandomMaps::GetParamsFromMapKey(struct SRandomMapParams *,std::wstring const &) {
  
  _DWORD *v3; // eax

  v3 = std::wstring::c_str(a3);
  return (*(int (__thiscall **)(void *, int, _DWORD *))(*(_DWORD *)this + 20))(this, a2, v3);
}


// address=[0x1499570]
// Decompiled from char __stdcall CRandomMaps::GetParamsFromMapKey(void *a1, wchar_t *Source)
bool  CRandomMaps::GetParamsFromMapKey(struct SRandomMapParams *,wchar_t const *) {
  
  wchar_t Destination[1024]; // [esp+Ch] [ebp-804h] BYREF

  if ( !a1 )
    return 0;
  memset(a1, 0, 0xB8u);
  j__wcsncpy(Destination, Source, 0x3FFu);
  Destination[1023] = 0;
  if ( !(unsigned __int8)IsValidMapKey(Destination) )
    return 0;
  DecodeMapKey(a1, Destination);
  return 1;
}


// address=[0x1499640]
// Decompiled from void *__thiscall CRandomMaps::GetMapKeyFromParams(void *this, int a2, void *a3)
void  CRandomMaps::GetMapKeyFromParams(struct SRandomMapParams *,std::wstring &) {
  
  wchar_t String[1024]; // [esp+8h] [ebp-804h] BYREF

  (*(void (__thiscall **)(void *, int, wchar_t *))(*(_DWORD *)this + 28))(this, a2, String);
  String[1023] = 0;
  return std::wstring::operator=(a3, String);
}


// address=[0x14996d0]
// Decompiled from void __thiscall CRandomMaps::GetMapKeyFromParams(CRandomMaps *this, struct SRandomMapParams *a2, wchar_t *a3)
void  CRandomMaps::GetMapKeyFromParams(struct SRandomMapParams *,wchar_t *) {
  
  if ( a3 )
  {
    if ( a2 )
      GenerateMapKey(a2, a3);
    else
      *a3 = 0;
  }
}


// address=[0x1499710]
// Decompiled from char __stdcall CRandomMaps::IsRandomMapFileName(wchar_t *String, void *a2)
bool  CRandomMaps::IsRandomMapFileName(wchar_t const *,std::wstring *) {
  
  int v3; // eax
  int v4; // eax
  signed int v5; // [esp+4h] [ebp-8h]

  if ( !String )
    goto LABEL_21;
  v5 = j__wcslen(String);
  if ( v5 >= 3 && *String == 82 && String[1] == 68 && String[2] == 95 )
  {
    if ( a2 )
      std::wstring::operator=(a2, String + 3);
    return 1;
  }
  if ( v5 >= 2 && *String == 91 && String[v5 - 1] == 93 )
  {
    if ( !a2 )
      return 1;
    std::wstring::operator=(a2, String + 1);
    v3 = std::wstring::size(a2);
    std::wstring::resize(v3 - 1);
    return 1;
  }
  if ( v5 >= 2 && *String == 60 && String[v5 - 1] == 62 )
  {
    if ( !a2 )
      return 1;
    std::wstring::operator=(a2, String + 1);
    v4 = std::wstring::size(a2);
    std::wstring::resize(v4 - 1);
    return 1;
  }
  else
  {
LABEL_21:
    if ( a2 )
      std::wstring::operator=(a2, (wchar_t *)L"random map");
    return 0;
  }
}


// address=[0x1499870]
// Decompiled from int __thiscall CRandomMaps::IsRandomMapFileName(void *this, void *a2, int a3)
bool  CRandomMaps::IsRandomMapFileName(std::wstring const &,std::wstring *) {
  
  _DWORD *v5; // [esp+4h] [ebp-4h]

  if ( !std::wstring::length(a2) )
    return (*(int (__thiscall **)(void *, _DWORD, int))(*(_DWORD *)this + 36))(this, 0, a3);
  v5 = std::wstring::c_str((_Cnd_internal_imp_t *)a2);
  return (*(int (__thiscall **)(void *, _DWORD *, int))(*(_DWORD *)this + 36))(this, v5, a3);
}


// address=[0x14998c0]
// Decompiled from void __stdcall CRandomMaps::GenerateRandomMapFileName(int a1, wchar_t *String)
void  CRandomMaps::GenerateRandomMapFileName(std::wstring &,wchar_t const *) {
  
  int v2; // [esp+8h] [ebp-78h]
  int v3; // [esp+Ch] [ebp-74h]
  int v4; // [esp+14h] [ebp-6Ch]
  _BYTE v5[28]; // [esp+1Ch] [ebp-64h] BYREF
  _BYTE v6[28]; // [esp+38h] [ebp-48h] BYREF
  _BYTE v7[28]; // [esp+54h] [ebp-2Ch] BYREF
  int v8; // [esp+7Ch] [ebp-4h]

  if ( !String || !*String )
    String = L"random map";
  v4 = std::wstring::wstring(v5, String);
  v8 = 0;
  v3 = std::wstring::wstring(v6, (wchar_t *)L"RD_");
  LOBYTE(v8) = 1;
  v2 = std::operator+<wchar_t>(v7, v3, v4);
  std::wstring::operator=(v2);
  std::wstring::~wstring(v7);
  LOBYTE(v8) = 0;
  std::wstring::~wstring(v6);
  v8 = -1;
  std::wstring::~wstring(v5);
}


// address=[0x14999b0]
// Decompiled from void __stdcall CRandomMaps::GenerateRandomMapFileName(int a1, _Cnd_internal_imp_t *a2)
void  CRandomMaps::GenerateRandomMapFileName(std::wstring &,std::wstring const &) {
  
  void *v2; // [esp+8h] [ebp-54h]
  void *v3; // [esp+Ch] [ebp-50h]
  _BYTE v4[28]; // [esp+14h] [ebp-48h] BYREF
  _BYTE v5[28]; // [esp+30h] [ebp-2Ch] BYREF
  int v6; // [esp+58h] [ebp-4h]

  v3 = (void *)std::wstring::wstring(v4, (wchar_t *)L"RD_");
  v6 = 0;
  v2 = std::operator+<wchar_t>(v5, v3, a2);
  std::wstring::operator=(v2);
  std::wstring::~wstring(v5);
  v6 = -1;
  std::wstring::~wstring(v4);
}


// address=[0x1499a50]
// Decompiled from void __thiscall CRandomMaps::GenerateRandomMapFileName(void *this, int a2, const void *a3)
void  CRandomMaps::GenerateRandomMapFileName(std::wstring &,struct SRandomMapParams const &) {
  
  _BYTE v4[184]; // [esp+10h] [ebp-E4h] BYREF
  _BYTE v5[28]; // [esp+C8h] [ebp-2Ch] BYREF
  int v6; // [esp+F0h] [ebp-4h]

  qmemcpy(v4, a3, sizeof(v4));
  std::wstring::wstring(v5);
  v6 = 0;
  (*(void (__thiscall **)(void *, _BYTE *, _BYTE *))(*(_DWORD *)this + 24))(this, v4, v5);
  (*(void (__thiscall **)(void *, int, _BYTE *))(*(_DWORD *)this + 44))(this, a2, v5);
  v6 = -1;
  std::wstring::~wstring(v5);
}


// address=[0x1499b10]
// Decompiled from void __thiscall CRandomMaps::AdjustRandomMapFileName(void *this, void *a2)
void  CRandomMaps::AdjustRandomMapFileName(std::wstring &) {
  
  int v2; // [esp+4h] [ebp-11Ch]
  int v3; // [esp+8h] [ebp-118h]
  int v4; // [esp+Ch] [ebp-114h]
  int v5; // [esp+10h] [ebp-110h]
  int v6; // [esp+14h] [ebp-10Ch]
  bool v8; // [esp+20h] [ebp-100h]
  unsigned int v9; // [esp+24h] [ebp-FCh]
  char v10; // [esp+2Ch] [ebp-F4h]
  _BYTE v11[28]; // [esp+30h] [ebp-F0h] BYREF
  _BYTE v12[28]; // [esp+4Ch] [ebp-D4h] BYREF
  int v13[7]; // [esp+68h] [ebp-B8h] BYREF
  _BYTE v14[28]; // [esp+84h] [ebp-9Ch] BYREF
  int v15[7]; // [esp+A0h] [ebp-80h] BYREF
  _BYTE v16[28]; // [esp+BCh] [ebp-64h] BYREF
  _BYTE v17[28]; // [esp+D8h] [ebp-48h] BYREF
  _BYTE v18[28]; // [esp+F4h] [ebp-2Ch] BYREF
  int v19; // [esp+11Ch] [ebp-4h]

  v10 = 0;
  std::wstring::wstring((int)a2);
  v19 = 0;
  std::wstring::wstring(v17, (wchar_t *)&word_3703AD8);
  LOBYTE(v19) = 1;
  v9 = std::wstring::length(a2);
  v8 = 0;
  if ( v9 > 4 )
  {
    v6 = std::wstring::wstring(v14, (wchar_t *)L".sav");
    LOBYTE(v19) = 2;
    v5 = std::wstring::substr((int)v15, v9 - 4, 4u);
    v10 = 3;
    if ( (unsigned __int8)std::operator==<wchar_t>(v5, v6) )
      v8 = 1;
  }
  if ( (v10 & 2) != 0 )
  {
    v10 &= ~2u;
    std::wstring::~wstring(v15);
  }
  v19 = 1;
  if ( (v10 & 1) != 0 )
    std::wstring::~wstring(v14);
  if ( v8 )
  {
    v4 = std::wstring::substr((int)v13, 0, v9 - 4);
    std::wstring::operator=(v4);
    std::wstring::~wstring(v13);
    v3 = std::wstring::wstring(v12, (wchar_t *)L".sav");
    std::wstring::operator=(v3);
    std::wstring::~wstring(v12);
  }
  std::wstring::wstring(v18);
  LOBYTE(v19) = 3;
  if ( (*(unsigned __int8 (__thiscall **)(void *, _BYTE *, _BYTE *))(*(_DWORD *)this + 32))(this, v16, v18) )
  {
    v2 = std::operator+<wchar_t>(v11, v18, v17);
    std::wstring::operator=(v2);
    std::wstring::~wstring(v11);
  }
  LOBYTE(v19) = 1;
  std::wstring::~wstring(v18);
  LOBYTE(v19) = 0;
  std::wstring::~wstring(v17);
  v19 = -1;
  std::wstring::~wstring(v16);
}


// address=[0x1499d90]
// Decompiled from int __thiscall CRandomMaps::GetPreviewData(CRandomMaps *this)
unsigned short const *  CRandomMaps::GetPreviewData(void) {
  
  if ( *((_BYTE *)this + 4) )
    return *((_DWORD *)this + 3);
  else
    return 0;
}


// address=[0x1499dc0]
// Decompiled from char *__thiscall CRandomMaps::GetRandomMapInfo(CMapGeneratorHost **this)
struct SRandomMapInfo const *  CRandomMaps::GetRandomMapInfo(void) {
  
  if ( *((_BYTE *)this + 4) && this[2] )
    return CMapGeneratorHost::GetRandomMapInfo(this[2]);
  else
    return 0;
}


