#include "IEntity.h"

// Definitions for class IEntity

// address=[0x12fd110]
// Decompiled from int __thiscall IEntity::FlagBits(_DWORD *this, EntityFlag a2)
int  IEntity::FlagBits(int)const {
  
  return a2 & this[5];
}


// address=[0x12fd480]
// Decompiled from int __thiscall IEntity::ObjType(unsigned __int8 *this)
int  IEntity::ObjType(void)const {
  
  return this[10];
}


// address=[0x1309650]
// Decompiled from struct IEntityVtbl *__thiscall IEntity::PackedXY(IEntity *this)
int  IEntity::PackedXY(void)const {
  
  return this[6].lpVtbl;
}


// address=[0x130e8a0]
// Decompiled from struct IEntityVtbl *__thiscall IEntity::AIEntityInfoPtr(IEntity *this)
class CAIEntityInfo *  IEntity::AIEntityInfoPtr(void)const {
  
  return this[4].lpVtbl;
}


// address=[0x130ea10]
// Decompiled from int __thiscall IEntity::ClearFlagBits(_DWORD *this, EntityFlag a2)
void  IEntity::ClearFlagBits(int) {
  
  int result; // eax

  result = this[5] & ~a2;
  this[5] = result;
  return result;
}


// address=[0x130eb60]
// Decompiled from int __thiscall IEntity::Flags(_DWORD *this)
int  IEntity::Flags(void)const {
  
  return this[5];
}


// address=[0x130f060]
// Decompiled from int __thiscall IEntity::ID(unsigned __int16 *this)
int  IEntity::ID(void)const {
  
  return this[4];
}


// address=[0x130f250]
// Decompiled from int __thiscall IEntity::OwnerId(unsigned __int8 *this)
int  IEntity::OwnerId(void)const {
  
  return (int)this[32] >> 4;
}


// address=[0x130f390]
// Decompiled from _DWORD *__thiscall IEntity::SetFlagBits(_DWORD *this, EntityFlag a2)
void  IEntity::SetFlagBits(int) {
  
  _DWORD *result; // eax

  result = this;
  this[5] |= a2;
  return result;
}


// address=[0x130f420]
// Decompiled from int __thiscall IEntity::Type(unsigned __int16 *this)
int  IEntity::Type(void)const {
  
  return this[6];
}


// address=[0x130f440]
// Decompiled from int __thiscall IEntity::UniqueId(_DWORD *this)
int  IEntity::UniqueId(void)const {
  
  return this[1];
}


// address=[0x130f520]
// Decompiled from int __thiscall IEntity::WarriorType(_DWORD *this)
int  IEntity::WarriorType(void)const {
  
  return this[5] & 0xF;
}


// address=[0x130f550]
// Decompiled from int __thiscall sub_170F550(_DWORD *this)
int  IEntity::X(void)const {
  
  return Y16X16::UnpackXFast(this[6]);
}


// address=[0x130f570]
// Decompiled from int __thiscall sub_170F570(_DWORD *this)
int  IEntity::Y(void)const {
  
  return Y16X16::UnpackYFast(this[6]);
}


// address=[0x1336860]
// Decompiled from struct CPtrList *__thiscall IEntity::WarMapNode(CPropertySet *this)
class CWarMapNode const &  IEntity::WarMapNode(void)const {
  
  return (CPropertySet *)((char *)this + 28);
}


// address=[0x13469e0]
// Decompiled from struct CPtrList *__thiscall IEntity::WarMapNode(CPropertySet *this)
class CWarMapNode &  IEntity::WarMapNode(void) {
  
  return (CPropertySet *)((char *)this + 28);
}


// address=[0x141d8b0]
// Decompiled from int __thiscall IEntity::EntityId(USHORT *this)
int  IEntity::EntityId(void)const {
  
  return this[4];
}


// address=[0x141da20]
// Decompiled from int __thiscall sub_181DA20(_BYTE *this)
int  IEntity::Race(void)const {
  
  return this[32] & 0xF;
}


// address=[0x1460630]
// Decompiled from int __thiscall IEntity::Hitpoints(IEntity *this)
int  IEntity::Hitpoints(void)const {
  
  return BYTE1(this[8].lpVtbl);
}


// address=[0x14d8640]
// Decompiled from void *__thiscall IEntity::ClearGroupFlagBits(std::_Ref_count_base *this, const struct type_info *a2)
int  IEntity::ClearGroupFlagBits(int) {
  
  return 0;
}


// address=[0x14d8670]
// Decompiled from int __thiscall IEntity::GetGoodType(IEntity *this)
int  IEntity::GetGoodType(void)const {
  
  return 0;
}


// address=[0x14d8680]
// Decompiled from int IEntity::GetGroupFlags()
int  IEntity::GetGroupFlags(void)const {
  
  return 0;
}


// address=[0x14d8720]
// Decompiled from bool __thiscall IEntity::IsVisible(_DWORD *this)
bool  IEntity::IsVisible(void)const {
  
  return (this[5] & 0x80100) == 256;
}


// address=[0x14d8790]
// Decompiled from void *__thiscall IEntity::SetGroupFlagBits(std::_Ref_count_base *this, const struct type_info *a2)
int  IEntity::SetGroupFlagBits(int) {
  
  return 0;
}


// address=[0x14d87b0]
// Decompiled from void *__thiscall IEntity::SetGroupFlags(std::_Ref_count_base *this, const struct type_info *a2)
int  IEntity::SetGroupFlags(int) {
  
  return 0;
}


// address=[0x14d8810]
// Decompiled from struct IEntityVtbl *__thiscall IEntity::SetPosition(IEntity *this, int a2, int a3)
void  IEntity::SetPosition(int,int) {
  
  struct IEntityVtbl *result; // eax

  result = (struct IEntityVtbl *)Y16X16::PackXYFast(a2, a3);
  this[6].lpVtbl = result;
  return result;
}


// address=[0x14e4af0]
// Decompiled from void IEntity::Delete()
void  IEntity::Delete(void) {
  
  ;
}


// address=[0x14e4bf0]
// Decompiled from void __stdcall IEntity::Take(int a1)
void  IEntity::Take(int) {
  
  ;
}


// address=[0x14eb780]
// Decompiled from IEntity *__thiscall IEntity::SetOwnerId(IEntity *this, unsigned __int8 a2)
void  IEntity::SetOwnerId(unsigned char) {
  
  IEntity *result; // eax

  result = this;
  LOBYTE(this[8].lpVtbl) = (16 * a2) | (int)this[8].lpVtbl & 0xF;
  return result;
}


// address=[0x14eb7e0]
// Decompiled from IEntity *__thiscall IEntity::SetRace(IEntity *this, unsigned __int8 a2)
void  IEntity::SetRace(unsigned char) {
  
  IEntity *result; // eax

  result = this;
  LOBYTE(this[8].lpVtbl) = a2 | (int)this[8].lpVtbl & 0xF0;
  return result;
}


// address=[0x1508220]
// Decompiled from void __thiscall IEntity::SetPosition(CPaneContainer *this, struct CPaneContainer *a2)
void  IEntity::SetPosition(int) {
  
  *((_DWORD *)this + 6) = a2;
}


// address=[0x15191b0]
// Decompiled from bool __thiscall IEntity::IsSelected(IEntity *this)
bool  IEntity::IsSelected(void)const {
  
  return ((int)this[5].lpVtbl & 0x200) != 0;
}


// address=[0x154b3d0]
// Decompiled from IEntity *__thiscall IEntity::IEntity(IEntity *this, int a2)
 IEntity::IEntity(int) {
  
  CPersistence::CPersistence(this);
  this->lpVtbl = (struct IEntityVtbl *)&IEntity::_vftable_;
  this[1].lpVtbl = (struct IEntityVtbl *)-1;
  LOWORD(this[2].lpVtbl) = a2;
  BYTE2(this[2].lpVtbl) = 0;
  LOWORD(this[3].lpVtbl) = 0;
  this[4].lpVtbl = 0;
  this[5].lpVtbl = 0;
  this[6].lpVtbl = 0;
  CWarMapNode::CWarMapNode((CWarMapNode *)&this[7]);
  LOBYTE(this[8].lpVtbl) = 0;
  BYTE1(this[8].lpVtbl) = 0;
  CMapObjectMgr::RegisterEntity(a2, this, 1);
  return this;
}


// address=[0x154b4a0]
// Decompiled from int __thiscall IEntity::_IEntity(_DWORD *this)
 IEntity::~IEntity(void) {
  
  *this = &IEntity::_vftable_;
  if ( CWarMapNode::IsInWarMap((_anonymous_namespace_::_GetFileInfoByHandleEx *)(this + 7)) )
    CWarMap::RemoveEntity((CPropertySet *)this);
  if ( this[4] )
  {
    CAIEntityInfo::`scalar deleting destructor'(1);
    this[4] = 0;
  }
  this[1] |= 0x40000000u;
  this[5] = 0;
  return CWarMapNode::~CWarMapNode();
}


// address=[0x154b570]
// Decompiled from struct IEntity *__thiscall IEntity::IEntity(struct IEntity *this, struct std::istream *a2)
 IEntity::IEntity(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  struct IEntity *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  CPersistence::CPersistence(this);
  v5->lpVtbl = (struct IEntityVtbl *)&IEntity::_vftable_;
  CWarMapNode::CWarMapNode((CWarMapNode *)&v5[7]);
  v6 = 0;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 2 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for IEntity");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned short>(a2, &v5[2]);
  operator^<unsigned short>(a2, &v5[3]);
  operator^<int>((int)a2, (int)&v5[6]);
  operator^<unsigned char>(a2, (char *)&v5[8].lpVtbl + 1);
  operator^<unsigned char>(a2, (char *)&v5[2].lpVtbl + 2);
  operator^<unsigned char>(a2, &v5[8]);
  operator^<int>((int)a2, (int)&v5[5]);
  operator^<int>((int)a2, (int)&v5[1]);
  v5[4].lpVtbl = 0;
  CMapObjectMgr::RegisterEntity(LOWORD(v5[2].lpVtbl), v5, 0);
  v6 = -1;
  return v5;
}


// address=[0x154b6e0]
// Decompiled from int __thiscall IEntity::Store(char *this, struct std::ostream *a2)
void  IEntity::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF

  CPersistence::Store((struct CPersistence *)this, a2);
  v3 = 2;
  operator^<unsigned int>(a2, &v3);
  operator^<unsigned short>((int)a2, (__int16 *)this + 4);
  operator^<unsigned short>((int)a2, (__int16 *)this + 6);
  operator^<int>((int)a2, (int *)this + 6);
  operator^<unsigned char>(a2, (int)(this + 33));
  operator^<unsigned char>(a2, (int)(this + 10));
  operator^<unsigned char>(a2, (int)(this + 32));
  operator^<int>((int)a2, (int *)this + 5);
  return operator^<int>((int)a2, (int *)this + 1);
}


// address=[0x154b7b0]
// Decompiled from int IEntity::PostLoadInit()
void  IEntity::PostLoadInit(void) {
  
  IEntity::ClearFlagBits(0x200);
  return IEntity::ClearFlagBits(0x400);
}


// address=[0x154b7e0]
// Decompiled from int __thiscall IEntity::WorldIdx(_DWORD *this)
int  IEntity::WorldIdx(void)const {
  
  return CWorldManager::Index(this[6]);
}


// address=[0x154b800]
// Decompiled from int __thiscall IEntity::Increase(_BYTE *this, int a2)
int  IEntity::Increase(int) {
  
  if ( a2 + (unsigned __int8)this[33] <= 255 )
    this[33] += a2;
  else
    this[33] = -1;
  return (unsigned __int8)this[33];
}


// address=[0x154b850]
// Decompiled from int __thiscall Damage(int this, int a2)
void  IEntity::Decrease(int) {
  
  int result; // eax

  if ( a2 <= 0 )
    return result;
  if ( a2 < *(unsigned __int8 *)(this + 33) )
  {
    result = this;
    *(_BYTE *)(this + 33) -= a2;
  }
  else
  {
    *(_BYTE *)(this + 33) = 0;
    return CMapObjectMgr::Kill(*(unsigned __int16 *)(this + 8), dword_40FE24C);
  }
  return result;
}


// address=[0x154b8b0]
// Decompiled from int __thiscall IEntity::Decrease(void *this, int a2, int a3)
void  IEntity::Decrease(int,int) {
  
  int result; // eax

  dword_40FE24C = a3;
  result = (*(int (__thiscall **)(void *, int))(*(_DWORD *)this + 32))(this, a2);
  dword_40FE24C = 0;
  return result;
}


// address=[0x154b8e0]
// Decompiled from int __thiscall sub_194B8E0(unsigned __int8 *this)
int  IEntity::Amount(void)const {
  
  return this[33];
}


// address=[0x154b900]
// Decompiled from int IEntity::MaxHitpoints()
int  IEntity::MaxHitpoints(void)const {
  
  return 0;
}


// address=[0x154b910]
// Decompiled from void *__thiscall IEntity::SetAIEntityInfoPtr(IEntity *this, struct IEntityVtbl *a2)
void  IEntity::SetAIEntityInfoPtr(class CAIEntityInfo *) {
  
  void *result; // eax

  result = this;
  if ( this[4].lpVtbl )
  {
    result = this[4].lpVtbl;
    if ( result )
      result = CAIEntityInfo::`scalar deleting destructor'((CAIEntityInfo *)this[4].lpVtbl, 1u);
  }
  this[4].lpVtbl = a2;
  return result;
}


// address=[0x154b960]
// Decompiled from int __thiscall IEntity::DbgPrint(_DWORD *this, int a2, const char *a3)
void  IEntity::DbgPrint(int,char const *) {
  
  void *v3; // eax
  const char *v4; // eax
  int v6; // [esp-20h] [ebp-28h]
  int v7; // [esp-1Ch] [ebp-24h]
  int v8; // [esp-18h] [ebp-20h]
  int v9; // [esp-14h] [ebp-1Ch]
  int v10; // [esp-10h] [ebp-18h]
  int v11; // [esp-Ch] [ebp-14h]
  int v12; // [esp-8h] [ebp-10h]
  int v13; // [esp-4h] [ebp-Ch]
  const char *v14; // [esp+0h] [ebp-8h]

  if ( a3 )
    v14 = a3;
  else
    v14 = "IEntity::DbgPrint()";
  v13 = IEntity::Y(this);
  v12 = IEntity::X(this);
  v11 = IEntity::Flags(this);
  v10 = IEntity::OwnerId((unsigned __int8 *)this);
  v9 = IEntity::Race(this);
  v8 = IEntity::Type((unsigned __int16 *)this);
  v7 = IEntity::ObjType((unsigned __int8 *)this);
  v6 = IEntity::EntityId((unsigned __int16 *)this);
  v3 = (void *)j____RTtypeid(this);
  v4 = (const char *)type_info::name(v3);
  return BBSupportTracePrintF(
           a2,
           "%s: %s, id %i, obj type %02x, type %i, race %i, owner %i, flags 0x%08x, pos (%i, %i).",
           v14,
           v4,
           v6,
           v7,
           v8,
           v9,
           v10,
           v11,
           v12,
           v13);
}


// address=[0x154ba00]
// Decompiled from int __thiscall sub_194BA00(CPaneContainer *this, struct CPaneContainer *a2)
void  IEntity::PlaceInMapObjectLayer(int) {
  
  __int16 v2; // ax
  int v4; // [esp+0h] [ebp-10h]
  int v5; // [esp+4h] [ebp-Ch]
  int v6; // [esp+8h] [ebp-8h]

  if ( (*((_DWORD *)this + 5) & 0x8000) == 0
    && BBSupportDbgReport(2, "MapObjects\\Entity.cpp", 284, "(m_iFlags & ENTITY_FLAG_ON_BOARD) != 0") == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)this + 5) &= ~0x8000u;
  if ( (int)a2 >= 0 )
  {
    if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(a2)
      && BBSupportDbgReport(2, "MapObjects\\Entity.cpp", 290, "g_cWorld.InWorldPackedXY(_iPackedXY)") == 1 )
    {
      __debugbreak();
    }
    IEntity::SetPosition(this, a2);
  }
  v5 = IEntity::X(this);
  v6 = IEntity::Y(this);
  if ( !(unsigned __int8)CWorldManager::InWorld(v5, v6)
    && BBSupportDbgReport(2, "MapObjects\\Entity.cpp", 298, "g_cWorld.InWorld(iEntityX, iEntityY)") == 1 )
  {
    __debugbreak();
  }
  v4 = CWorldManager::Index(v5, v6);
  if ( CWorldManager::MapObjectId(v4)
    && BBSupportDbgReport(2, "MapObjects\\Entity.cpp", 302, "g_cWorld.MapObjectId(iEntityWorldIdx) == 0") == 1 )
  {
    __debugbreak();
  }
  v2 = IEntity::EntityId(this);
  CWorldManager::SetMapObjectId(v4, v2);
  return CWarMap::AddEntity(this);
}


// address=[0x154bb50]
// Decompiled from int __thiscall sub_194BB50(CPropertySet *this)
void  IEntity::RemoveFromMapObjectLayer(void) {
  
  int v1; // esi
  int v3; // [esp+4h] [ebp-10h]
  int v4; // [esp+8h] [ebp-Ch]
  int v5; // [esp+Ch] [ebp-8h]

  if ( (*((_DWORD *)this + 5) & 0x8000) != 0
    && BBSupportDbgReport(2, "MapObjects\\Entity.cpp", 316, "(m_iFlags & ENTITY_FLAG_ON_BOARD) == 0") == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)this + 5) |= 0x8000u;
  v4 = IEntity::X(this);
  v5 = IEntity::Y(this);
  if ( !(unsigned __int8)CWorldManager::InWorld(v4, v5)
    && BBSupportDbgReport(2, "MapObjects\\Entity.cpp", 323, "g_cWorld.InWorld(iEntityX, iEntityY)") == 1 )
  {
    __debugbreak();
  }
  v3 = CWorldManager::Index(v4, v5);
  v1 = CWorldManager::MapObjectId(v3);
  if ( v1 != IEntity::EntityId(this)
    && BBSupportDbgReport(2, "MapObjects\\Entity.cpp", 327, "g_cWorld.MapObjectId(iEntityWorldIdx) == EntityId()") == 1 )
  {
    __debugbreak();
  }
  CWorldManager::SetMapObjectId(v3, 0);
  return CWarMap::RemoveEntity(this);
}


// address=[0x154bc60]
// Decompiled from int __thiscall IEntity::RemoveFromMapObjectLayerIfNecessary(IEntity *this)
void  IEntity::RemoveFromMapObjectLayerIfNecessary(void) {
  
  int result; // eax
  int v2; // eax
  int v3; // eax
  int v4; // esi
  int v5; // [esp-4h] [ebp-Ch]
  int v6; // [esp-4h] [ebp-Ch]

  if ( ((int)this[5].lpVtbl & 0x8000) == 0 )
    return ((int (__thiscall *)(IEntity *))this->lpVtbl[1].Name)(this);
  v5 = IEntity::Y(this);
  v2 = IEntity::X(this);
  result = (unsigned __int8)CWorldManager::InWorld(v2, v5);
  if ( !(_BYTE)result )
    return result;
  v6 = IEntity::Y(this);
  v3 = IEntity::X(this);
  v4 = CWorldManager::MapObjectId(v3, v6);
  result = IEntity::EntityId((unsigned __int16 *)this);
  if ( v4 != result )
    return result;
  result = BBSupportDbgReport(
             2,
             "MapObjects\\Entity.cpp",
             348,
             "!g_cWorld.InWorld(X(), Y()) || (g_cWorld.MapObjectId(X(), Y()) != EntityId())");
  if ( result == 1 )
    __debugbreak();
  return result;
}


// address=[0x154bd00]
// Decompiled from int __stdcall sub_194BD00(int a1)
void  IEntity::Detach(int) {
  
  if ( BBSupportDbgReport(1, "MapObjects\\Entity.cpp", 360, "IEntity::Detach() called!") == 1 )
    __debugbreak();
  return 0;
}


// address=[0x154bd30]
// Decompiled from void __stdcall IEntity::SetObserverTarget(int a1, int a2)
void  IEntity::SetObserverTarget(enum T_OBSERVER_TARGET,int) {
  
  ;
}


// address=[0x154bd40]
// Decompiled from void *__thiscall IEntity::GetObserverTarget(std::_Ref_count_base *this, const struct type_info *a2)
int  IEntity::GetObserverTarget(enum T_OBSERVER_TARGET) {
  
  return 0;
}


// address=[0x154bd50]
// Decompiled from int __thiscall sub_194BD50(CPropertySet *this)
void  IEntity::AddToWarMap(void) {
  
  int result; // eax

  result = IEntity::FlagBits(&loc_1C00000);
  if ( result )
    return CWarMap::AddEntity(this);
  return result;
}


// address=[0x154bd80]
// Decompiled from int __thiscall IEntity::RemoveFromAllGroups(unsigned __int16 *this)
void  IEntity::RemoveFromAllGroups(void) {
  
  int v1; // eax

  v1 = IEntity::EntityId(this);
  return (*(int (__thiscall **)(void *, int))(*(_DWORD *)g_pGroupMgr + 28))(g_pGroupMgr, v1);
}


// address=[0x154c100]
// Decompiled from void __stdcall IEntity::SetEvent(int a1)
void  IEntity::SetEvent(class CEntityEvent const &) {
  
  ;
}


// address=[0x1552650]
// Decompiled from BOOL __thiscall IEntity::CheckType(IEntity *this, char a2, int a3)
bool  IEntity::CheckType(int,int)const {
  
  return LOWORD(this[3].lpVtbl) == a3 && (unsigned __int8)(a2 & BYTE2(this[2].lpVtbl)) != 0;
}


// address=[0x156d340]
// Decompiled from IEntity *__thiscall IEntity::SetHitpoints(IEntity *this, char a2)
void  IEntity::SetHitpoints(unsigned int) {
  
  IEntity *result; // eax

  result = this;
  BYTE1(this[8].lpVtbl) = a2;
  return result;
}


// address=[0x40fe240]
// [Decompilation failed for static struct SGfxColor IEntity::m_sGfxColor]

// address=[0x40fe250]
// [Decompilation failed for static struct SGfxObjectInfo IEntity::m_sGfxInfo]

