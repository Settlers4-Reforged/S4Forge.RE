#include "CMapGeneratorHost.h"

// Definitions for class CMapGeneratorHost

// address=[0x1498520]
// Decompiled from void *__thiscall CMapGeneratorHost::Init(void **this, int a2)
void  CMapGeneratorHost::Init(int a2) {
  
  void *result; // eax
  int i; // [esp+8h] [ebp-8h]

  CMapGeneratorHost::CleanUp((CMapGeneratorHost *)this);
  *((_BYTE *)this + 4) = 1;
  this[2] = (void *)((_DWORD)this[5] * (_DWORD)this[5]);
  CMapGeneratorHost::ClearRandomMapInfo((CMapGeneratorHost *)this);
  this[52] = this[5];
  this[53] = this[11];
  memset(this + 72, 0, 0x18u);
  this[75] = this[5];
  this[73] = this[11];
  this[78] = operator new[](4 * (_DWORD)this[2]);
  memset(this[78], 0, 4 * (_DWORD)this[2]);
  this[79] = operator new[](4 * (_DWORD)this[2]);
  result = memset(this[79], 0, 4 * (_DWORD)this[2]);
  for ( i = 0; i < (int)this[2]; ++i )
  {
    *((_BYTE *)this[78] + 4 * i + 1) = 7;
    result = (void *)(i + 1);
  }
  return result;
}


// address=[0x1498680]
// Decompiled from CMapGeneratorHost *__thiscall CMapGeneratorHost::UpdateGroundInformation(CMapGeneratorHost **this)
void  CMapGeneratorHost::UpdateGroundInformation(void) {
  
  CMapGeneratorHost *result; // eax
  CMapGeneratorHost *v2; // [esp+0h] [ebp-10h]
  CMapGeneratorHost *v3; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]

  result = (CMapGeneratorHost *)this;
  if ( !*((_BYTE *)this + 4) )
    return result;
  result = this[78];
  v2 = result;
  v3 = this[79];
  for ( i = 0; i < (int)this[2]; ++i )
  {
    CMapGeneratorHost::RefreshShading((CMapGeneratorHost *)this, i);
    if ( CLandscapeProperties::IsBlockedLand(
           (CLandscapeProperties *)&g_cLandscapeProperties,
           *((unsigned __int8 *)v2 + 1)) )
    {
      *((_BYTE *)v3 + 2) |= 1u;
    }
    v2 = (CMapGeneratorHost *)((char *)v2 + 4);
    v3 = (CMapGeneratorHost *)((char *)v3 + 4);
    result = (CMapGeneratorHost *)(i + 1);
  }
  return result;
}


// address=[0x1498720]
// Decompiled from char __thiscall CMapGeneratorHost::SetObject(CMapGeneratorHost *this, Grid *a2, unsigned int a3, int a4)
bool  CMapGeneratorHost::SetObject(int a2, int a3, int a4) {
  
  char *v5; // [esp+4h] [ebp-6Ch]
  unsigned int v6; // [esp+8h] [ebp-68h]
  int v7; // [esp+Ch] [ebp-64h]
  int v8; // [esp+10h] [ebp-60h]
  char *v9; // [esp+14h] [ebp-5Ch]
  unsigned int v10; // [esp+18h] [ebp-58h]
  int v11; // [esp+1Ch] [ebp-54h]
  int v12; // [esp+24h] [ebp-4Ch]
  int v13; // [esp+28h] [ebp-48h]
  int v14; // [esp+2Ch] [ebp-44h]
  int v15; // [esp+34h] [ebp-3Ch] BYREF
  char *v16; // [esp+38h] [ebp-38h]
  int v17; // [esp+3Ch] [ebp-34h]
  unsigned int v18; // [esp+40h] [ebp-30h]
  int v19; // [esp+44h] [ebp-2Ch]
  int v20; // [esp+48h] [ebp-28h]
  unsigned int v21; // [esp+4Ch] [ebp-24h]
  int m; // [esp+50h] [ebp-20h]
  char *v23; // [esp+54h] [ebp-1Ch]
  int k; // [esp+58h] [ebp-18h]
  int j; // [esp+5Ch] [ebp-14h]
  int i; // [esp+60h] [ebp-10h]
  int v27; // [esp+64h] [ebp-Ch] BYREF
  CMapGeneratorHost *v28; // [esp+68h] [ebp-8h]
  bool v29; // [esp+6Fh] [ebp-1h] BYREF

  v28 = this;
  if ( !Grid::InQuadrat((int)a2, a3, *((_DWORD *)this + 52)) )
    return 0;
  v23 = (char *)a2 + *((_DWORD *)v28 + 52) * a3;
  if ( *(_BYTE *)(*((_DWORD *)v28 + 79) + 4 * (_DWORD)v23) )
    return 0;
  if ( (*(_BYTE *)(*((_DWORD *)v28 + 79) + 4 * (_DWORD)v23 + 2) & 0x43) != 0 )
    return 0;
  CDecoObjMgr::GetDecoObjectFlagsInfo((CDecoObjMgr *)&g_cDecoObjMgr, a4, &v29, &v27, &v15);
  if ( v29 )
  {
    if ( v27 != 1 && BBSupportDbgReport(2, "main\\RandomMapHost.cpp", 317, (const char *)&dword_37039A0[1]) == 1 )
      __debugbreak();
  }
  else
  {
    v14 = CSpiralOffsets::First(v27);
    for ( i = 0; i < v14; ++i )
    {
      v20 = (int)a2 + CSpiralOffsets::DeltaX(i);
      v21 = a3 + CSpiralOffsets::DeltaY(i);
      if ( !Grid::InQuadrat(v20, v21, *((_DWORD *)v28 + 52)) )
        return 0;
      v19 = v20 + *((_DWORD *)v28 + 52) * v21;
      if ( *(_BYTE *)(*((_DWORD *)v28 + 79) + 4 * v19) )
        return 0;
      if ( (*(_BYTE *)(*((_DWORD *)v28 + 79) + 4 * v19 + 2) & 0x43) != 0 )
        return 0;
    }
  }
  v13 = CSpiralOffsets::First(v27);
  v12 = CSpiralOffsets::First(v15);
  for ( j = v13; j < v12; ++j )
  {
    v17 = (int)a2 + CSpiralOffsets::DeltaX(j);
    v18 = a3 + CSpiralOffsets::DeltaY(j);
    if ( !Grid::InQuadrat(v17, v18, *((_DWORD *)v28 + 52)) )
      return 0;
    if ( (*(_BYTE *)(*((_DWORD *)v28 + 79) + 4 * (v17 + *((_DWORD *)v28 + 52) * v18) + 2) & 0x43) != 0 )
      return 0;
  }
  *(_BYTE *)(*((_DWORD *)v28 + 79) + 4 * (_DWORD)v23) = a4;
  if ( v29 )
  {
    if ( v27 != 1 && BBSupportDbgReport(2, "main\\RandomMapHost.cpp", 370, "iTotalBlockingOrRepellingRings == 1") == 1 )
      __debugbreak();
    *(_BYTE *)(*((_DWORD *)v28 + 79) + 4 * (_DWORD)v23 + 2) |= 0x42u;
  }
  else
  {
    v11 = CSpiralOffsets::First(v27);
    for ( k = 0; k < v11; ++k )
    {
      v9 = (char *)a2 + CSpiralOffsets::DeltaX(k);
      v10 = a3 + CSpiralOffsets::DeltaY(k);
      v16 = &v9[*((_DWORD *)v28 + 52) * v10];
      *(_BYTE *)(*((_DWORD *)v28 + 79) + 4 * (_DWORD)v16 + 2) |= 0x41u;
    }
  }
  v8 = CSpiralOffsets::First(v27);
  v7 = CSpiralOffsets::First(v15);
  for ( m = v8; m < v7; ++m )
  {
    v5 = (char *)a2 + CSpiralOffsets::DeltaX(m);
    v6 = a3 + CSpiralOffsets::DeltaY(m);
    *(_BYTE *)(*((_DWORD *)v28 + 79) + 4 * (_DWORD)&v5[*((_DWORD *)v28 + 52) * v6] + 2) |= 0x40u;
  }
  return 1;
}


// address=[0x1498b10]
// Decompiled from int __thiscall CMapGeneratorHost::SetPlayerStartPosition(CMapGeneratorHost *this, int a2, int a3, int a4)
void  CMapGeneratorHost::SetPlayerStartPosition(int a2, int a3, int a4) {
  
  int result; // eax

  if ( a2 < 1 || a2 > 8 )
    return result;
  *((_DWORD *)this + a2 + 54) = a3;
  result = a2;
  *((_DWORD *)this + a2 + 63) = a4;
  return result;
}


// address=[0x1498b50]
// Decompiled from CMapGeneratorHost *__thiscall CMapGeneratorHost::CMapGeneratorHost(  CMapGeneratorHost *this,  const struct SRandomMapParams *a2)
 CMapGeneratorHost::CMapGeneratorHost(struct SRandomMapParams const & a2) {
  
  IMapGeneratorHost::IMapGeneratorHost(this);
  *(_DWORD *)this = &CMapGeneratorHost::_vftable_;
  CDecoObjMgr::LoadInfo((CDecoObjMgr *)&g_cDecoObjMgr);
  *((_BYTE *)this + 4) = 0;
  *((_DWORD *)this + 2) = 0;
  CMapGeneratorHost::ClearRandomMapInfo(this);
  *((_DWORD *)this + 78) = 0;
  *((_DWORD *)this + 79) = 0;
  qmemcpy((char *)this + 12, a2, 0xB8u);
  if ( *((int *)this + 5) >= 64 )
  {
    if ( *((int *)this + 5) > 1024 )
      *((_DWORD *)this + 5) = 1024;
  }
  else
  {
    *((_DWORD *)this + 5) = 64;
  }
  *((_DWORD *)this + 5) &= 0xFFFFFFC0;
  if ( *((int *)this + 11) >= 1 )
  {
    if ( *((int *)this + 11) > 9 )
      *((_DWORD *)this + 11) = 9;
  }
  else
  {
    *((_DWORD *)this + 11) = 1;
  }
  return this;
}


// address=[0x1498c30]
// Decompiled from void __thiscall CMapGeneratorHost::~CMapGeneratorHost(CMapGeneratorHost *this)
 CMapGeneratorHost::~CMapGeneratorHost(void) {
  
  *(_DWORD *)this = &CMapGeneratorHost::_vftable_;
  CMapGeneratorHost::CleanUp(this);
}


// address=[0x1498c80]
// Decompiled from CMapGeneratorHost *__thiscall CMapGeneratorHost::CleanUp(void **this)
void  CMapGeneratorHost::CleanUp(void) {
  
  CMapGeneratorHost *result; // eax

  result = (CMapGeneratorHost *)this;
  if ( !*((_BYTE *)this + 4) )
    return result;
  if ( this[79] )
  {
    operator delete[](this[79]);
    this[79] = 0;
  }
  if ( this[78] )
  {
    operator delete[](this[78]);
    this[78] = 0;
  }
  CMapGeneratorHost::ClearRandomMapInfo((CMapGeneratorHost *)this);
  result = (CMapGeneratorHost *)this;
  this[2] = 0;
  *((_BYTE *)this + 4) = 0;
  return result;
}


// address=[0x1498d20]
// Decompiled from CMapGeneratorHost *__thiscall CMapGeneratorHost::ClearRandomMapInfo(CMapGeneratorHost *this)
void  CMapGeneratorHost::ClearRandomMapInfo(void) {
  
  CMapGeneratorHost *result; // eax

  memset((char *)this + 196, 0, 0x5Cu);
  *((_DWORD *)this + 49) = 92;
  *((_DWORD *)this + 50) = 1;
  result = this;
  *((_DWORD *)this + 51) = 9;
  return result;
}


// address=[0x1498d70]
// Decompiled from int __thiscall CMapGeneratorHost::UploadChunks(void **this, struct S4::CMapFile *a2)
void  CMapGeneratorHost::UploadChunks(class S4::CMapFile & a2) {
  
  S4::CMapFile::UploadBuffer(1, 0, this + 72, 0x18u, 0);
  S4::CMapFile::UploadBuffer(13, 0, this[78], 4 * (_DWORD)this[2], 0);
  S4::CMapFile::UploadBuffer(6, 0, this[79], 4 * (_DWORD)this[2], 0);
  return S4::CMapFile::UploadBuffer(220, 0, this + 49, 0x5Cu, 0);
}


// address=[0x1498e00]
// Decompiled from int __thiscall CMapGeneratorHost::RefreshShading(CMapGeneratorHost *this, int a2)
void  CMapGeneratorHost::RefreshShading(int a2) {
  
  int result; // eax
  int v3; // [esp+0h] [ebp-1Ch]
  int v4; // [esp+4h] [ebp-18h]
  unsigned __int8 *v5; // [esp+Ch] [ebp-10h]
  int v6; // [esp+10h] [ebp-Ch]
  int v7; // [esp+14h] [ebp-8h]

  v5 = (unsigned __int8 *)(*((_DWORD *)this + 78) + 4 * a2);
  if ( a2 >= *((_DWORD *)this + 5) )
    v3 = v5[-4 * *((_DWORD *)this + 5)];
  else
    v3 = *v5;
  if ( a2 < *((_DWORD *)this + 2) - *((_DWORD *)this + 5) )
    v4 = v5[4 * *((_DWORD *)this + 5)];
  else
    v4 = *v5;
  v7 = v3 - v4;
  LOBYTE(v6) = 8;
  if ( v3 - v4 <= 0 )
  {
    if ( v7 < 0 )
      v6 = (v7 >> 1) + 8;
  }
  else
  {
    v6 = (v7 >> 1) + 8;
  }
  result = v6 & 0xF;
  v5[2] = result | v5[2] & 0xF0;
  return result;
}


// address=[0x14991b0]
// Decompiled from int __thiscall CMapGeneratorHost::GetEditorLayer(CMapGeneratorHost *this)
struct SEditorElementMap *  CMapGeneratorHost::GetEditorLayer(void) {
  
  return *((_DWORD *)this + 79);
}


// address=[0x14991d0]
// Decompiled from int __thiscall CMapGeneratorHost::GetGfxLayer(CMFCBaseTabCtrl *this)
struct T_GFX_MAP_ELEMENT *  CMapGeneratorHost::GetGfxLayer(void) {
  
  return *((_DWORD *)this + 78);
}


// address=[0x14991f0]
// Decompiled from int __stdcall CMapGeneratorHost::GetInterfaceVersion(CMapGeneratorHost *this)
int __stdcall CMapGeneratorHost::GetInterfaceVersion(void) {
  
  return 2;
}


// address=[0x1499200]
// Decompiled from int __thiscall CMapGeneratorHost::GetMapWidthHeight(CMapGeneratorHost *this)
int  CMapGeneratorHost::GetMapWidthHeight(void) {
  
  return *((_DWORD *)this + 52);
}


// address=[0x1499220]
// Decompiled from char __thiscall CMapGeneratorHost::IsEditorHost(CMapGeneratorHost *this)
bool  CMapGeneratorHost::IsEditorHost(void) {
  
  return 0;
}


// address=[0x149a7a0]
// Decompiled from char *__thiscall CMapGeneratorHost::GetRandomMapInfo(CMapGeneratorHost *this)
struct SRandomMapInfo const *  CMapGeneratorHost::GetRandomMapInfo(void)const {
  
  return (char *)this + 196;
}


