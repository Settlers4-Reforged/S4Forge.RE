#include "IEntity.h"

#include <iostream>

#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"

#include "World/CWorldManager.h"
#include "World/helper.h"
#include "MapObjects/CMapObjectMgr.h"
#include "MapObjects/CGroupMgr.h"
#include "Pathing/CWarMap.h"
#include "Pathing/CWarMapNode.h"

// Definitions for class IEntity

// address=[0x12fd110]
// Decompiled from int __thiscall IEntity::FlagBits(IEntity *this, EntityFlag a2)
int IEntity::FlagBits(int a2) const
{
  return a2 & this->m_iFlags;
}

// address=[0x12fd480]
// Decompiled from int __thiscall IEntity::ObjType(IEntity *this)
int IEntity::ObjType(void) const
{
  return this->m_objType;
}

// address=[0x1309650]
// Decompiled from int __thiscall IEntity::PackedXY(IEntity *this)
int IEntity::PackedXY(void) const
{
  return this->m_uPackedXY;
}

// address=[0x130e8a0]
// Decompiled from struct CAIEntityInfo *__thiscall IEntity::AIEntityInfoPtr(IEntity *this)
class CAIEntityInfo *IEntity::AIEntityInfoPtr(void) const
{
  return this->m_psAIEntityInfo;
}

// address=[0x130ea10]
// Decompiled from void __thiscall IEntity::ClearFlagBits(IEntity *this, EntityFlag a2)
void IEntity::ClearFlagBits(int a2)
{
  this->m_iFlags &= ~a2;
}

// address=[0x130eb60]
// Decompiled from int __thiscall IEntity::Flags(IEntity *this)
int IEntity::Flags(void) const
{
  return this->m_iFlags;
}

// address=[0x130f060]
// Decompiled from int __thiscall IEntity::ID(IEntity *this)
int IEntity::ID(void) const
{
  return this->m_nEntityId;
}

// address=[0x130f250]
// Decompiled from int __thiscall IEntity::OwnerId(IEntity *this)
int IEntity::OwnerId(void) const
{
  return this->m_packedTribePlayer.m_cPlayer;
}

// address=[0x130f390]
// Decompiled from void __thiscall IEntity::SetFlagBits(IEntity *this, EntityFlag a2)
void IEntity::SetFlagBits(int a2)
{
  this->m_iFlags |= a2;
}

// address=[0x130f420]
// Decompiled from int __thiscall IEntity::Type(IEntity *this)
int IEntity::Type(void) const
{
  return this->m_nType;
}

// address=[0x130f440]
// Decompiled from DWORD __thiscall IEntity::UniqueId(IEntity *this)
int IEntity::UniqueId(void) const
{
  return this->m_iUniqueId;
}

// address=[0x130f520]
// Decompiled from DWORD __thiscall IEntity::WarriorType(IEntity *this)
int IEntity::WarriorType(void) const
{
  return this->m_iFlags & 0xF;
}

// address=[0x130f550]
// Decompiled from int __thiscall IEntity::X(IEntity *this)
int IEntity::X(void) const
{
  return Y16X16::UnpackXFast(this->m_uPackedXY);
}

// address=[0x130f570]
// Decompiled from int __thiscall IEntity::Y(IEntity *this)
int IEntity::Y(void) const
{
  return Y16X16::UnpackYFast(this->m_uPackedXY);
}

// address=[0x1336860]
// Decompiled from CWarMapNode *__thiscall IEntity::WarMapNode(IEntity *this)
class CWarMapNode const *IEntity::WarMapNode(void) const
{
  return &this->m_warMapNode;
}

// address=[0x13469e0]
// Decompiled from struct CWarMapNode *__thiscall IEntity::WarMapNode(IEntity *this)
class CWarMapNode *IEntity::WarMapNode(void)
{
  return &this->m_warMapNode;
}

// address=[0x141d8b0]
// Decompiled from int __thiscall IEntity::EntityId(IEntity *this)
int IEntity::EntityId(void) const
{
  return this->m_nEntityId;
}

// address=[0x141da20]
// Decompiled from int __thiscall IEntity::Race(IEntity *this)
int IEntity::Race(void) const
{
  return this->m_packedTribePlayer.m_cRace;
}

// address=[0x1460630]
// Decompiled from int __thiscall IEntity::Hitpoints(IEntity *this)
int IEntity::Hitpoints(void) const
{
  return this->m_cHealth;
}

// address=[0x14d8640]
// Decompiled from int __thiscall IEntity::ClearGroupFlagBits(IEntity *this, DWORD a2)
int IEntity::ClearGroupFlagBits(int a2)
{
  return 0;
}

// address=[0x14d8670]
// Decompiled from int __thiscall IEntity::GetGoodType(IEntity *this)
int IEntity::GetGoodType(void) const
{
  return 0;
}

// address=[0x14d8680]
// Decompiled from int IEntity::GetGroupFlags()
int IEntity::GetGroupFlags(void) const
{
  return 0;
}

// address=[0x14d8720]
// Decompiled from bool __thiscall IEntity::IsVisible(IEntity *this)
bool IEntity::IsVisible(void) const
{
  return (this->m_iFlags & 0x80100) == 256;
}

// address=[0x14d8790]
// Decompiled from void *__thiscall IEntity::SetGroupFlagBits(std::_Ref_count_base *this, const struct type_info *a2)
int IEntity::SetGroupFlagBits(int arg1)
{
  return 0;
}

// address=[0x14d87b0]
// Decompiled from void *__thiscall IEntity::SetGroupFlags(std::_Ref_count_base *this, const struct type_info *a2)
int IEntity::SetGroupFlags(int arg1)
{
  return 0;
}

// address=[0x14d8810]
// Decompiled from void __thiscall IEntity::SetPosition(IEntity *this, int x, int y)
void IEntity::SetPosition(int x, int y)
{
  this->m_uPackedXY = Y16X16::PackXYFast(x, y);
}

// address=[0x14e4af0]
// Decompiled from void IEntity::Delete()
void IEntity::Delete(void)
{
}

// address=[0x14e4bf0]
// Decompiled from void __stdcall IEntity::Take(int a1)
void IEntity::Take(int arg0)
{
}

// address=[0x14eb780]
// Decompiled from void __thiscall IEntity::SetOwnerId(IEntity *this, unsigned __int8 owner)
void IEntity::SetOwnerId(unsigned char owner)
{
  this->m_packedTribePlayer.m_cPlayer = owner;
}

// address=[0x14eb7e0]
// Decompiled from void __thiscall IEntity::SetRace(IEntity *this, unsigned __int8 a2)
void IEntity::SetRace(unsigned char a2)
{
  this->m_packedTribePlayer.m_cRace = a2;
}

// address=[0x1508220]
// Decompiled from void __thiscall IEntity::SetPosition(IEntity *this, int a2)
void IEntity::SetPosition(int newPosition)
{
  this->m_uPackedXY = newPosition;
}

// address=[0x15191b0]
// Decompiled from bool __thiscall IEntity::IsSelected(IEntity *this)
bool IEntity::IsSelected(void) const
{
  return (this->m_iFlags & static_cast<int>(EntityFlag_Selected)) != 0;
}

// address=[0x154b3d0]
// Decompiled from IEntity *__thiscall IEntity::IEntity(IEntity *this, int id)
IEntity::IEntity(int id)
{
  this->m_iUniqueId = -1;
  this->m_nEntityId = id;
  this->m_objType = 0;
  this->m_nType = 0;
  this->m_psAIEntityInfo = 0;
  this->m_iFlags = 0;
  this->m_uPackedXY = 0;
  this->m_warMapNode = CWarMapNode{};
  this->m_packedTribePlayer.m_cPacked = 0;
  this->m_cHealth = 0;
  CMapObjectMgr::RegisterEntity(id, this, 1);
}

// address=[0x154b4a0]
// Decompiled from void __thiscall IEntity::~IEntity(IEntity *this)
IEntity::~IEntity(void)
{
  CAIEntityInfo *m_psAIEntityInfo; // [esp+Ch] [ebp-14h]

  if (this->m_warMapNode.IsInWarMap())
    CWarMap::RemoveEntity(*this);

  if (this->m_psAIEntityInfo)
  {
    m_psAIEntityInfo = this->m_psAIEntityInfo;
    if (m_psAIEntityInfo)
      delete m_psAIEntityInfo;
    this->m_psAIEntityInfo = 0;
  }
  this->m_iUniqueId |= 0x40000000u;
  this->m_iFlags = 0;
}

// address=[0x154b570]
// Decompiled from struct IEntity *__thiscall IEntity::IEntity(struct IEntity *this, struct std::istream *inputFile)
IEntity::IEntity(std::istream &inputFile)
{
  this->m_warMapNode = CWarMapNode{};

  int fileFormatVersion;
  inputFile >> fileFormatVersion;
  if (fileFormatVersion != IEntity::FILE_FORMAT_VERSION)
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for IEntity");
    throw new CS4InvalidMapException();
  }

  inputFile >> this->m_nEntityId;
  inputFile >> this->m_nType;
  inputFile >> this->m_uPackedXY;
  inputFile >> this->m_cHealth;
  inputFile >> this->m_objType;
  inputFile >> this->m_packedTribePlayer.m_cPacked;
  inputFile >> this->m_iFlags;
  inputFile >> this->m_iUniqueId;
  this->m_psAIEntityInfo = 0;
  CMapObjectMgr::RegisterEntity(this->m_nEntityId, this, 0);
}

// address=[0x154b6e0]
// Decompiled from void __thiscall IEntity::Store(IEntity *this, struct std::ostream *outputFile)
void IEntity::Store(std::ostream &outputFile)
{
  CPersistence::Store(outputFile);
  outputFile << IEntity::FILE_FORMAT_VERSION;
  outputFile << this->m_nEntityId;
  outputFile << this->m_nType;
  outputFile << this->m_uPackedXY;
  outputFile << this->m_cHealth;
  outputFile << this->m_objType;
  outputFile << this->m_packedTribePlayer.m_cPacked;
  outputFile << this->m_iFlags;
  outputFile << this->m_iUniqueId;
}

// address=[0x154b7b0]
// Decompiled from void __thiscall IEntity::PostLoadInit(IEntity *this)
void IEntity::PostLoadInit(void)
{
  IEntity::ClearFlagBits(EntityFlag_Selected);
  IEntity::ClearFlagBits((EntityFlag)0x400);
}

// address=[0x154b7e0]
// Decompiled from int __thiscall IEntity::WorldIdx(IEntity *this)
int IEntity::WorldIdx(void) const
{
  return CWorldManager::Index(this->m_uPackedXY);
}

// address=[0x154b800]
// Decompiled from int __thiscall IEntity::Increase(IEntity *this, int byAmount)
int IEntity::Increase(int byAmount)
{

  if (byAmount + this->m_cHealth <= 255)
    this->m_cHealth += byAmount;
  else
    this->m_cHealth = -1;
  return this->m_cHealth;
}

// address=[0x154b850]
// Decompiled from void __thiscall IEntity::Decrease(IEntity *this, int byAmount)
void IEntity::Decrease(int byAmount)
{

  if (byAmount > 0)
  {
    if (byAmount < this->m_cHealth)
    {
      this->m_cHealth -= byAmount;
    }
    else
    {
      this->m_cHealth = 0;
      g_pMapObjectMgr->Kill(this->m_nEntityId, g_CurrentEntityAttacker);
    }
  }
}

// address=[0x154b8b0]
// Decompiled from void __thiscall IEntity::Decrease(IEntity *this, int a2, int attackerId)
void IEntity::Decrease(int a2, int attackerId)
{

  g_CurrentEntityAttacker = attackerId;
  this->Decrease(a2);
  g_CurrentEntityAttacker = 0;
}

// address=[0x154b8e0]
// Decompiled from int __thiscall IEntity::Amount(IEntity *this)
int IEntity::Amount(void) const
{
  return this->m_cHealth;
}

// address=[0x154b900]
// Decompiled from int IEntity::MaxHitpoints()
int IEntity::MaxHitpoints(void) const
{
  return 0;
}

// address=[0x154b910]
// Decompiled from void __thiscall IEntity::SetAIEntityInfoPtr(IEntity *this, struct CAIEntityInfo *a2)
void IEntity::SetAIEntityInfoPtr(class CAIEntityInfo *a2)
{

  if (this->m_psAIEntityInfo)
    delete this->m_psAIEntityInfo;
  this->m_psAIEntityInfo = a2;
}

// address=[0x154b960]
// Decompiled from void __thiscall IEntity::DbgPrint(IEntity *this, int logLevel, const char *customMessage)
void IEntity::DbgPrint(int logLevel, char const *customMessage)
{
  const char *typeName; // [esp-24h] [ebp-2Ch]
  int entityId;         // [esp-20h] [ebp-28h]
  int objType;          // [esp-1Ch] [ebp-24h]
  int type;             // [esp-18h] [ebp-20h]
  int race;             // [esp-14h] [ebp-1Ch]
  int ownerId;          // [esp-10h] [ebp-18h]
  int flags;            // [esp-Ch] [ebp-14h]
  int x;                // [esp-8h] [ebp-10h]
  int y;                // [esp-4h] [ebp-Ch]
  const char *message;  // [esp+0h] [ebp-8h]

  if (customMessage)
    message = customMessage;
  else
    message = "IEntity::DbgPrint()";
  y = this->Y();
  x = this->X();
  flags = this->Flags();
  ownerId = this->OwnerId();
  race = this->Race();
  type = this->Type();
  objType = this->ObjType();
  entityId = this->EntityId();
  const std::type_info &typeInfo = typeid(*this);
  typeName = typeInfo.name();
  BBSupportTracePrintF(
      logLevel,
      "%s: %s, id %i, obj type %02x, type %i, race %i, owner %i, flags 0x%08x, pos (%i, %i).",
      message,
      typeName,
      entityId,
      objType,
      type,
      race,
      ownerId,
      flags,
      x,
      y);
}

// address=[0x154ba00]
// Decompiled from void __thiscall IEntity::PlaceInMapObjectLayer(IEntity *this, int packedXY)
void IEntity::PlaceInMapObjectLayer(int packedXY)
{

  __int16 v2;     // ax
  int worldIndex; // [esp+0h] [ebp-10h]
  int x;          // [esp+4h] [ebp-Ch]
  int y;          // [esp+8h] [ebp-8h]

  if ((this->m_iFlags & 0x8000) == 0 && BBSupportDbgReport(2, "MapObjects\\Entity.cpp", 284, "(m_iFlags & ENTITY_FLAG_ON_BOARD) != 0") == 1)
  {
    __debugbreak();
  }
  this->m_iFlags &= ~0x8000u;
  if (packedXY >= 0)
  {
    if (!CWorldManager::InWorldPackedXY(packedXY) && BBSupportDbgReport(2, "MapObjects\\Entity.cpp", 290, "g_cWorld.InWorldPackedXY(_iPackedXY)") == 1)
    {
      __debugbreak();
    }
    this->SetPosition(packedXY);
  }
  x = this->X();
  y = this->Y();
  if (!CWorldManager::InWorld(x, y) && BBSupportDbgReport(2, "MapObjects\\Entity.cpp", 298, "g_cWorld.InWorld(iEntityX, iEntityY)") == 1)
  {
    __debugbreak();
  }
  worldIndex = CWorldManager::Index(x, y);
  if (CWorldManager::MapObjectId(worldIndex) && BBSupportDbgReport(2, "MapObjects\\Entity.cpp", 302, "g_cWorld.MapObjectId(iEntityWorldIdx) == 0") == 1)
  {
    __debugbreak();
  }
  v2 = this->EntityId();
  CWorldManager::SetMapObjectId(worldIndex, v2);
  CWarMap::AddEntity(*this);
}

// address=[0x154bb50]
// Decompiled from void __thiscall IEntity::RemoveFromMapObjectLayer(IEntity *this)
void IEntity::RemoveFromMapObjectLayer(void)
{

  int mapId;      // esi
  int worldIndex; // [esp+4h] [ebp-10h]
  int x;          // [esp+8h] [ebp-Ch]
  int y;          // [esp+Ch] [ebp-8h]

  if ((this->m_iFlags & 0x8000) != 0)
  {
    BBSupportDbgReport(2, "MapObjects\\Entity.cpp", 316, "(m_iFlags & ENTITY_FLAG_ON_BOARD) == 0");
    __debugbreak();
  }
  this->m_iFlags |= 0x8000u;
  x = this->X();
  y = this->Y();

  if (!CWorldManager::InWorld(x, y))
  {
    BBSupportDbgReport(2, "MapObjects\\Entity.cpp", 323, "g_cWorld.InWorld(iEntityX, iEntityY)");
    __debugbreak();
  }
  worldIndex = CWorldManager::Index(x, y);
  mapId = CWorldManager::MapObjectId(worldIndex);
  if (mapId != this->EntityId())
  {
    BBSupportDbgReport(2, "MapObjects\\Entity.cpp", 327, "g_cWorld.MapObjectId(iEntityWorldIdx) == EntityId()");
    __debugbreak();
  }
  CWorldManager::SetMapObjectId(worldIndex, 0);
  CWarMap::RemoveEntity(*this);
}

// address=[0x154bc60]
// Decompiled from void __thiscall IEntity::RemoveFromMapObjectLayerIfNecessary(IEntity *this)
void IEntity::RemoveFromMapObjectLayerIfNecessary(void)
{

  int x;     // eax MAPDST
  int mapId; // esi
  int y;     // [esp-4h] [ebp-Ch] MAPDST

  if ((this->m_iFlags & 0x8000) == 0)
  {
    this->RemoveFromMapObjectLayer();
    return;
  }

  y = this->Y();
  x = this->X();
  if (CWorldManager::InWorld(x, y))
  {
    y = this->Y();
    x = this->X();
    mapId = CWorldManager::MapObjectId(x, y);
    if (mapId == this->EntityId())
    {
      BBSupportDbgReport(2, "MapObjects\\Entity.cpp", 348, "!g_cWorld.InWorld(X(), Y()) || (g_cWorld.MapObjectId(X(), Y()) != EntityId())");
      __debugbreak();
    }
  }
}

// address=[0x154bd00]
// Decompiled from void __stdcall IEntity::Detach(IEntity *a1)
void IEntity::Detach(int a1)
{

  if (BBSupportDbgReport(1, "MapObjects\\Entity.cpp", 360, "IEntity::Detach() called!") == 1)
    __debugbreak();
}

// address=[0x154bd30]
// Decompiled from void __stdcall IEntity::SetObserverTarget(int a1, int a2)
void IEntity::SetObserverTarget(enum T_OBSERVER_TARGET arg0, int arg1)
{
}

// address=[0x154bd40]
// Decompiled from void *__thiscall IEntity::GetObserverTarget(std::_Ref_count_base *this, const struct type_info *a2)
int IEntity::GetObserverTarget(enum T_OBSERVER_TARGET arg1)
{
  return 0;
}

// address=[0x154bd50]
// Decompiled from void __thiscall IEntity::AddToWarMap(IEntity *this)
void IEntity::AddToWarMap(void)
{

  if (this->FlagBits(EntityFlag_Ready))
    CWarMap::AddEntity(*this);
}

// address=[0x154bd80]
// Decompiled from void __thiscall IEntity::RemoveFromAllGroups(IEntity *this)
void IEntity::RemoveFromAllGroups(void)
{

  int entityId; // eax

  entityId = this->EntityId();
  g_pGroupMgr->DetachEntityFromAllGroups(entityId);
}

// address=[0x154c100]
// Decompiled from void __stdcall IEntity::SetEvent(int a1)
void IEntity::SetEvent(class CEntityEvent const &arg0)
{
}

// address=[0x1552650]
// Decompiled from BOOL __thiscall IEntity::CheckType(IEntity *this, char a2, int a3)
bool IEntity::CheckType(int a2, int a3) const
{

  return this->m_nType == a3 && (unsigned __int8)(a2 & this->m_objType) != 0;
}

// address=[0x156d340]
// Decompiled from void __thiscall IEntity::SetHitpoints(IEntity *this, char hp)
void IEntity::SetHitpoints(unsigned int hp)
{

  this->m_cHealth = hp;
}

// address=[0x40fe240]
// [Decompilation failed for static struct SGfxColor IEntity::m_sGfxColor]

// address=[0x40fe250]
// [Decompilation failed for static struct SGfxObjectInfo IEntity::m_sGfxInfo]
