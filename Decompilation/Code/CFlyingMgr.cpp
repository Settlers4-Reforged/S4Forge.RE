#include "CFlyingMgr.h"

// Definitions for class CFlyingMgr

// address=[0x1303860]
// Decompiled from int __thiscall CFlyingMgr::GetNumberOfEntities(CFlyingMgr *this, int a2, int a3)
int  CFlyingMgr::GetNumberOfEntities(int,int) {
  
  return *((_DWORD *)this + 2 * a2 + a3 + 19);
}


// address=[0x150ddc0]
// Decompiled from int __thiscall CFlyingMgr::GetFirstEntityId(CFlyingMgr *this, int a2, int a3)
int  CFlyingMgr::GetFirstEntityId(int,int) {
  
  if ( a2 >= 9
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\FlyingMgr.h",
         69,
         "_iPlayer < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a3 >= 2
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\FlyingMgr.h",
         70,
         "_iEntityType < FLYING_ENTITY_MAX") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + 2 * a2 + a3 + 1);
}


// address=[0x154f490]
// Decompiled from CFlyingMgr *__thiscall CFlyingMgr::CFlyingMgr(CFlyingMgr *this)
 CFlyingMgr::CFlyingMgr(void) {
  
  CFlyingMgr::Clear(this);
  return this;
}


// address=[0x154f4b0]
// Decompiled from char __thiscall CFlyingMgr::AddFlyingEntity(CFlyingMgr *this, int a2, int a3, int a4, int a5, bool a6)
bool  CFlyingMgr::AddFlyingEntity(int,int,int,int,bool) {
  
  CManakopter *C; // [esp+10h] [ebp-18h]
  int FreeSlot; // [esp+14h] [ebp-14h]

  FreeSlot = CMapObjectMgr::GetFreeSlot();
  if ( a2 != 1 )
    return 0;
  C = (CManakopter *)operator new(0x94u);
  if ( C )
    CManakopter::CManakopter(C, FreeSlot, a3, a4, a5);
  *(_DWORD *)this = FreeSlot;
  CFlyingMgr::AttachFlyingEntity(this, a5, 1, FreeSlot);
  ++*((_DWORD *)this + 2 * a5 + 20);
  if ( a6 )
    (*(void (__thiscall **)(void *, int, int, int, _DWORD))(*(_DWORD *)off_3D7A3D8 + 44))(
      off_3D7A3D8,
      20,
      a5,
      FreeSlot,
      0);
  return 1;
}


// address=[0x154f5c0]
// Decompiled from int __thiscall CFlyingMgr::DeleteFlyingEntity(CFlyingMgr *this, int a2)
void  CFlyingMgr::DeleteFlyingEntity(int) {
  
  unsigned __int8 *v2; // eax
  int v3; // eax
  unsigned __int8 *v5; // [esp+4h] [ebp-10h]
  int v6; // [esp+8h] [ebp-Ch]
  int v8; // [esp+10h] [ebp-4h]

  v2 = (unsigned __int8 *)CMapObjectMgr::Entity(a2);
  if ( IEntity::ObjType(v2) != 64
    && BBSupportDbgReport(2, "mapobjects\\FlyingMgr.cpp", 271, "g_pMapObjectMgr->Entity(_iId).ObjType() == DECO_OBJ") == 1 )
  {
    __debugbreak();
  }
  v5 = (unsigned __int8 *)CFlyingMgr::operator[](a2);
  v8 = IEntity::OwnerId(v5);
  v6 = IEntity::Type((unsigned __int16 *)v5);
  CFlyingMgr::DetachFlyingEntity(this, v8, v6, a2);
  --*((_DWORD *)this + 2 * v8 + v6 + 19);
  v3 = CMapObjectMgr::EntityPtr(a2);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 16))(v3, v3);
  return CMapObjectMgr::Kill(a2, 0);
}


// address=[0x154f6a0]
// Decompiled from unsigned __int8 *__thiscall CFlyingMgr::GetEntityPtr(CFlyingMgr *this, int a2)
class IFlyingEntity *  CFlyingMgr::GetEntityPtr(int) {
  
  unsigned __int8 *v4; // [esp+Ch] [ebp-4h]

  v4 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(a2);
  if ( v4 && IEntity::ObjType(v4) == 64 )
    return v4;
  else
    return 0;
}


// address=[0x154f6f0]
// Decompiled from unsigned __int8 *__thiscall CFlyingMgr::GetManakopterPtr(CFlyingMgr *this, int a2)
class CManakopter *  CFlyingMgr::GetManakopterPtr(int) {
  
  unsigned __int8 *v4; // [esp+Ch] [ebp-4h]

  v4 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(a2);
  if ( v4 && IEntity::ObjType(v4) == 64 )
    return v4;
  else
    return 0;
}


// address=[0x154f740]
// Decompiled from int __thiscall CFlyingMgr::AttachFlyingEntity(CFlyingMgr *this, int a2, int a3, int a4)
void  CFlyingMgr::AttachFlyingEntity(int,int,int) {
  
  IAnimatedEntity *v4; // eax
  IAnimatedEntity *v5; // eax
  _WORD *v6; // eax
  int result; // eax
  int v9; // [esp+4h] [ebp-4h]

  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "mapobjects\\FlyingMgr.cpp", 322, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a3 != 1
    && BBSupportDbgReport(2, "mapobjects\\FlyingMgr.cpp", 323, "_iEntityType>0 && _iEntityType < FLYING_ENTITY_MAX") == 1 )
  {
    __debugbreak();
  }
  v4 = (IAnimatedEntity *)CFlyingMgr::operator[](a4);
  IAnimatedEntity::SetPrevious(v4, 0);
  v9 = *((_DWORD *)this + 2 * a2 + a3 + 1);
  if ( v9 )
  {
    v5 = (IAnimatedEntity *)CFlyingMgr::operator[](v9);
    IAnimatedEntity::SetPrevious(v5, a4);
  }
  v6 = (_WORD *)CFlyingMgr::operator[](a4);
  IAnimatedEntity::SetNext(v6, v9);
  result = a3;
  *((_DWORD *)this + 2 * a2 + a3 + 1) = a4;
  return result;
}


// address=[0x154f820]
// Decompiled from void __thiscall CFlyingMgr::DetachFlyingEntity(CFlyingMgr *this, int a2, int a3, int a4)
void  CFlyingMgr::DetachFlyingEntity(int,int,int) {
  
  int v4; // eax
  _WORD *v5; // eax
  int v6; // eax
  IAnimatedEntity *v7; // eax
  int v8; // [esp-4h] [ebp-Ch]
  int v9; // [esp-4h] [ebp-Ch]
  IAnimatedEntity *v11; // [esp+4h] [ebp-4h]

  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "mapobjects\\FlyingMgr.cpp", 349, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a3 != 1
    && BBSupportDbgReport(2, "mapobjects\\FlyingMgr.cpp", 350, "_iEntityType>0 && _iEntityType<FLYING_ENTITY_MAX") == 1 )
  {
    __debugbreak();
  }
  v11 = (IAnimatedEntity *)CFlyingMgr::operator[](a4);
  if ( IAnimatedEntity::Previous(v11) )
  {
    v8 = IAnimatedEntity::Next(v11);
    v4 = IAnimatedEntity::Previous(v11);
    v5 = (_WORD *)CFlyingMgr::operator[](v4);
    IAnimatedEntity::SetNext(v5, v8);
  }
  else
  {
    if ( *((_DWORD *)this + 2 * a2 + a3 + 1) != a4
      && BBSupportDbgReport(
           2,
           "mapobjects\\FlyingMgr.cpp",
           363,
           "m_iFirstEntityIds[_iOwnerId][_iEntityType] == _iEntityId") == 1 )
    {
      __debugbreak();
    }
    *((_DWORD *)this + 2 * a2 + a3 + 1) = IAnimatedEntity::Next(v11);
  }
  if ( IAnimatedEntity::Next(v11) )
  {
    v9 = IAnimatedEntity::Previous(v11);
    v6 = IAnimatedEntity::Next(v11);
    v7 = (IAnimatedEntity *)CFlyingMgr::operator[](v6);
    IAnimatedEntity::SetPrevious(v7, v9);
  }
  IAnimatedEntity::SetNext(v11, 0);
  IAnimatedEntity::SetPrevious(v11, 0);
}


// address=[0x154f960]
// Decompiled from void __thiscall CFlyingMgr::CheckOutFlyingEntity(CFlyingMgr *this, int a2)
void  CFlyingMgr::CheckOutFlyingEntity(int) {
  
  unsigned __int8 *v2; // [esp+0h] [ebp-10h]
  int v4; // [esp+8h] [ebp-8h]
  int v5; // [esp+Ch] [ebp-4h]

  v2 = (unsigned __int8 *)CFlyingMgr::operator[](a2);
  v4 = IEntity::OwnerId(v2);
  v5 = IEntity::Type((unsigned __int16 *)v2);
  --*((_DWORD *)this + 2 * v4 + v5 + 19);
  CFlyingMgr::DetachFlyingEntity(this, v4, v5, a2);
}


// address=[0x154f9d0]
// Decompiled from int __thiscall CFlyingMgr::GetNearestEntity(CFlyingMgr *this, int a2, int a3, int a4, int a5, int a6)
int  CFlyingMgr::GetNearestEntity(int,int,int,int,int) {
  
  int v6; // eax
  int v8; // [esp-4h] [ebp-1Ch]
  int v10; // [esp+4h] [ebp-14h]
  unsigned int v11; // [esp+8h] [ebp-10h]
  unsigned int v12; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  _DWORD *v14; // [esp+14h] [ebp-4h]

  if ( (a2 <= 0 || a2 > CPlayerManager::LastPlayerId())
    && BBSupportDbgReport(
         2,
         "mapobjects\\FlyingMgr.cpp",
         398,
         "_iOwnerId>0 && _iOwnerId <= g_cPlayerMgr.LastPlayerId()") == 1 )
  {
    __debugbreak();
  }
  if ( a3 != 1
    && BBSupportDbgReport(2, "mapobjects\\FlyingMgr.cpp", 399, "_iEntityType>0 && _iEntityType<FLYING_ENTITY_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)CWorldManager::InWorld(a4, a5)
    && BBSupportDbgReport(2, "mapobjects\\FlyingMgr.cpp", 400, "g_cWorld.InWorld( _iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  v11 = -1;
  v10 = 0;
  for ( i = *((_DWORD *)this + 2 * a2 + a3 + 1); i; i = IAnimatedEntity::Next(v14) )
  {
    v14 = (_DWORD *)CFlyingMgr::operator[](i);
    v8 = a5 - IEntity::Y(v14);
    v6 = IEntity::X(v14);
    v12 = Grid::Distance((Grid *)(a4 - v6), v8);
    if ( v12 < v11 && (!a6 || IFlyingEntity::FlyingFlagBits((IFlyingEntity *)v14, a6)) )
    {
      v11 = v12;
      v10 = i;
    }
  }
  return v10;
}


// address=[0x154fb10]
// Decompiled from void __thiscall CFlyingMgr::Store(CFlyingMgr *this, struct S4::CMapFile *a2)
void  CFlyingMgr::Store(class S4::CMapFile &) {
  
  std::strstreambuf *v2; // eax
  void *v3; // eax
  int v4; // [esp+0h] [ebp-334h] BYREF
  _DWORD v5[43]; // [esp+10h] [ebp-324h] BYREF
  size_t Size; // [esp+BCh] [ebp-278h]
  void *Src; // [esp+C0h] [ebp-274h]
  unsigned __int8 *v8; // [esp+C4h] [ebp-270h]
  unsigned __int8 *v9; // [esp+C8h] [ebp-26Ch]
  unsigned __int8 *EntityPtr; // [esp+CCh] [ebp-268h]
  int UsedId; // [esp+D0h] [ebp-264h]
  int v12; // [esp+D4h] [ebp-260h] BYREF
  int v13; // [esp+D8h] [ebp-25Ch]
  unsigned __int8 *v14; // [esp+DCh] [ebp-258h]
  int v15; // [esp+E0h] [ebp-254h] BYREF
  int m; // [esp+E4h] [ebp-250h]
  CFlyingMgr *v17; // [esp+E8h] [ebp-24Ch]
  int k; // [esp+ECh] [ebp-248h]
  int j; // [esp+F0h] [ebp-244h]
  int i; // [esp+F4h] [ebp-240h]
  int *v21; // [esp+324h] [ebp-10h]
  int v22; // [esp+330h] [ebp-4h]

  v21 = &v4;
  v17 = this;
  std::ostrstream::ostrstream(0, 0x40000, 0, 2, 1);
  v22 = 0;
  v5[42] = std::ios_base::exceptions((char *)v5 + *(_DWORD *)(v5[0] + 4));
  std::ios_base::exceptions((std::ios_base *)((char *)v5 + *(_DWORD *)(v5[0] + 4)), 6);
  LOBYTE(v22) = 1;
  v12 = 1;
  operator^<unsigned int>((struct std::ostream *)v5, &v12);
  UsedId = CMapObjectMgr::LastUsedId();
  v13 = UsedId;
  v15 = 0;
  for ( i = 1; i <= v13; ++i )
  {
    EntityPtr = CFlyingMgr::GetEntityPtr(v17, i);
    v9 = EntityPtr;
    if ( EntityPtr )
      ++v15;
  }
  operator^<unsigned int>((struct std::ostream *)v5, &v15);
  for ( i = 1; i <= v13; ++i )
  {
    v8 = CFlyingMgr::GetEntityPtr(v17, i);
    v14 = v8;
    if ( v8 )
      (*(void (__thiscall **)(unsigned __int8 *, _DWORD *))(*(_DWORD *)v14 + 4))(v14, v5);
  }
  for ( j = 0; j < 9; ++j )
  {
    for ( k = 0; k < 2; ++k )
      operator^<int>((int)v5, (int *)v17 + 2 * j + k + 1);
  }
  for ( j = 0; j < 9; ++j )
  {
    for ( m = 0; m < 2; ++m )
      operator^<int>((int)v5, (int *)v17 + 2 * j + m + 19);
  }
  v22 = 0;
  std::ostrstream::freeze((std::ostrstream *)v5, 1);
  v2 = std::ostrstream::rdbuf((std::ostrstream *)v5);
  Size = std::strstreambuf::pcount(v2);
  std::ostrstream::str((CDaoIndexFieldInfo *)v5);
  Src = v3;
  S4::CMapFile::SaveChunk(168, 0, Size, v3, 0);
  std::ostrstream::freeze((std::ostrstream *)v5, 0);
  v22 = -1;
  std::ostrstream::`vbase destructor'((std::ostrstream *)v5);
}


// address=[0x154fe90]
// Decompiled from void __thiscall CFlyingMgr::Load(CFlyingMgr *this, struct S4::CMapFile *a2)
void  CFlyingMgr::Load(class S4::CMapFile &) {
  
  int v2; // [esp+0h] [ebp-118h] BYREF
  _DWORD v3[44]; // [esp+10h] [ebp-108h] BYREF
  unsigned int v4; // [esp+C0h] [ebp-58h]
  int v5; // [esp+C4h] [ebp-54h]
  int v6; // [esp+C8h] [ebp-50h]
  int v7; // [esp+CCh] [ebp-4Ch]
  int v8; // [esp+D0h] [ebp-48h]
  int v9; // [esp+D4h] [ebp-44h]
  unsigned __int8 *v10; // [esp+D8h] [ebp-40h]
  int v11; // [esp+DCh] [ebp-3Ch]
  int v12; // [esp+E0h] [ebp-38h] BYREF
  int v13; // [esp+E4h] [ebp-34h] BYREF
  unsigned int v14; // [esp+E8h] [ebp-30h] BYREF
  int pExceptionObject; // [esp+ECh] [ebp-2Ch] BYREF
  char *Str; // [esp+F0h] [ebp-28h]
  int k; // [esp+F4h] [ebp-24h]
  int j; // [esp+F8h] [ebp-20h]
  CFlyingMgr *v19; // [esp+FCh] [ebp-1Ch]
  unsigned __int16 *v20; // [esp+100h] [ebp-18h]
  int i; // [esp+104h] [ebp-14h]
  int *v22; // [esp+108h] [ebp-10h]
  int v23; // [esp+114h] [ebp-4h]

  v22 = &v2;
  v19 = this;
  CTrace::Print("CFlyingMgr load");
  CFlyingMgr::Clear(v19);
  v13 = 0;
  Str = (char *)S4::CMapFile::LoadChunk(a2, 0xA8u, 0, &v13, 0);
  if ( Str )
  {
    std::istrstream::istrstream(Str, 1);
    v23 = 0;
    v4 = std::ios_base::exceptions((char *)v3 + *(_DWORD *)(v3[0] + 4));
    std::ios_base::exceptions((std::ios_base *)((char *)v3 + *(_DWORD *)(v3[0] + 4)), 6);
    LOBYTE(v23) = 1;
    operator^<unsigned int>(v3, &v12);
    v11 = v12;
    if ( v12 != 1 )
    {
      BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CSettlerMgr");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    v14 = 0;
    operator^<unsigned int>(v3, &v14);
    for ( i = 0; i < v14; ++i )
    {
      v10 = (unsigned __int8 *)CPersistence::New(v3, v2);
      v20 = (unsigned __int16 *)v10;
      if ( !v10 )
      {
        v9 = BBSupportDbgReport(2, "mapobjects\\FlyingMgr.cpp", 186, "pFlyingEntity != NULL");
        if ( v9 == 1 )
          __debugbreak();
      }
      v8 = IEntity::ID();
      v7 = IEntity::Type(v20);
      v6 = IEntity::OwnerId((unsigned __int8 *)v20);
      CFlyingMgr::AttachFlyingEntity(v19, v6, v7, v8);
      v5 = IEntity::ID();
      *(_DWORD *)v19 = v5;
    }
    for ( i = 0; i < 9; ++i )
    {
      for ( j = 0; j < 2; ++j )
        operator^<int>((int)v3, (int)v19 + 8 * i + 4 * j + 4);
    }
    for ( i = 0; i < 9; ++i )
    {
      for ( k = 0; k < 2; ++k )
        operator^<int>((int)v3, (int)v19 + 8 * i + 4 * k + 76);
    }
    v23 = 0;
    std::ios_base::exceptions((std::ios_base *)((char *)v3 + *(_DWORD *)(v3[0] + 4)), v4);
    v23 = -1;
    std::istrstream::`vbase destructor'((std::istrstream *)v3);
  }
}


// address=[0x1550170]
// Decompiled from void *__thiscall CFlyingMgr::Clear(CFlyingMgr *this)
void  CFlyingMgr::Clear(void) {
  
  memset((char *)this + 4, 0, 0x48u);
  return memset((char *)this + 76, 0, 0x48u);
}


// address=[0x15506f0]
// Decompiled from int __stdcall CFlyingMgr::operator[](int a1)
class IFlyingEntity &  CFlyingMgr::operator[](int) {
  
  return CMapObjectMgr::EntityPtr(a1);
}


