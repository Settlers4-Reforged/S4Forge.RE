#include "CPersistence.h"

#include <istream>
#include <ostream>

#include "Logic/CGoodTransportPriority.h"
#include "Logic/CBuildingSupplyPriority.h"
#include "Logic/Events/CEntityEvent.h"
#include "Logic/EcoSector/CEcoSector.h"

#include "MapObjects/CStone.h"
#include "MapObjects/CTree.h"
#include "MapObjects/CEntityTask.h"

#include "MapObjects/Building/CBuilding.h"
#include "MapObjects/Building/CAnimalRanchRole.h"
#include "MapObjects/Building/CBarrackRole.h"
#include "MapObjects/Building/CBigTempleRole.h"
#include "MapObjects/Building/CBuildingSiteRole.h"
#include "MapObjects/Building/CCastleRole.h"
#include "MapObjects/Building/CDarkTempleRole.h"
#include "MapObjects/Building/CEyeCatcherRole.h"
#include "MapObjects/Building/CFarmBuildingRole.h"
#include "MapObjects/Building/CGatherBuildingRole.h"
#include "MapObjects/Building/CLookoutTowerRole.h"
#include "MapObjects/Building/CMilitaryBuildingRole.h"
#include "MapObjects/Building/CMineRole.h"
#include "MapObjects/Building/CProductionBuildingRole.h"
#include "MapObjects/Building/CResidenceBuildingRole.h"
#include "MapObjects/Building/CSimpleBuildingRole.h"
#include "MapObjects/Building/CSmallTempleRole.h"
#include "MapObjects/Building/CStorageBuildingRole.h"
#include "MapObjects/Building/CTradingBuildingRole.h"
#include "MapObjects/Building/CWorkUpBuildingRole.h"
#include "MapObjects/Building/CWorkshopBuildingRole.h"
#include "MapObjects/Building/CManakopterHallRole.h"
#include "MapObjects/Building/CDarkMushroomFarmRole.h"

#include "MapObjects/Settler/CSettler.h"
#include "MapObjects/Settler/CBuilderRole.h"
#include "MapObjects/Settler/CSquadLeaderRole.h"
#include "MapObjects/Settler/CCarrierRole.h"
#include "MapObjects/Settler/CDarkGardenerRole.h"
#include "MapObjects/Settler/CDiggerRole.h"
#include "MapObjects/Settler/CHunterRole.h"
#include "MapObjects/Settler/CDonkeyRole.h"
#include "MapObjects/Settler/CDoorRole.h"
#include "MapObjects/Settler/CFleeRole.h"
#include "MapObjects/Settler/CFreeWorkerRole.h"
#include "MapObjects/Settler/CGardenerRole.h"
#include "MapObjects/Settler/CGeologistRole.h"
#include "MapObjects/Settler/CHouseWorkerRole.h"
#include "MapObjects/Settler/CMushroomFarmerRole.h"
#include "MapObjects/Settler/CPioneerRole.h"
#include "MapObjects/Settler/CPriestRole.h"
#include "MapObjects/Settler/CSaboteurRole.h"
#include "MapObjects/Settler/CShamanRole.h"
#include "MapObjects/Settler/CSlaveRole.h"
#include "MapObjects/Settler/CSoldierRole.h"
#include "MapObjects/Settler/CThiefRole.h"
#include "MapObjects/Settler/CTowerSoldier.h"
#include "MapObjects/Settler/CHJBRole.h"

#include "MapObjects/Flying/CManakopter.h"

#include "MapObjects/Vehicle/CCart.h"

#include "MapObjects/Ship/CRomanWarShip.h"
#include "MapObjects/Ship/CMayaWarShip.h"
#include "MapObjects/Ship/CVikingWarShip.h"
#include "MapObjects/Ship/CTrojanWarShip.h"

#include "MapObjects/Catapult/CCatapult.h"
#include "MapObjects/Catapult/CRomanCatapult.h"
#include "MapObjects/Catapult/CMayaCatapult.h"
#include "MapObjects/Catapult/CVikingCatapult.h"
#include "MapObjects/Catapult/CTrojanCatapult.h"

#include "MapObjects/Ship/CShip.h"
#include "MapObjects/Ship/CFerryShip.h"
#include "MapObjects/Ship/CTransportShip.h"
#include "MapObjects/Ship/CWarShip.h"

#include "MapObjects/Pile/CPile.h"
#include "MapObjects/Pile/CTradePileRole.h"
#include "MapObjects/Pile/CProductionPileRole.h"
#include "MapObjects/Pile/CDeliverPileRole.h"
#include "MapObjects/Pile/CBuildingSitePileRole.h"
#include "MapObjects/Pile/CAnyWherePileRole.h"
#include "MapObjects/Pile/CStoragePileRole.h"

#include "MapObjects/Animal/CLandAnimal.h"

#include "MapObjects/DecoObj/CDecoObject.h"
#include "MapObjects/DecoObj/CPlant.h"
#include "MapObjects/DecoObj/CHive.h"
#include "MapObjects/DecoObj/CMushroom.h"
#include "MapObjects/DecoObj/CShadowHerb.h"

// Definitions for class CPersistence

std::map<unsigned long, DeserializerFunc> g_mPersistenceClassDeserializer;

bool s_bSetPersistenceClasses = false;
void RegisterClasses()
{
  if ( !s_bSetPersistenceClasses )
  {
    CPersistence::RegisterClassWhithId(CBuilding::m_iClassID, CBuilding::New, 0);
    CPersistence::RegisterClassWhithId(CSettler::m_iClassID, CSettler::New, 0);
    CPersistence::RegisterClassWhithId(CPile::m_iClassID, CPile::New, 0);
    CPersistence::RegisterClassWhithId(CLandAnimal::m_iClassID, CLandAnimal::New, 0);
    CPersistence::RegisterClassWhithId(CPlant::m_iClassID, CPlant::New, 0);
    CPersistence::RegisterClassWhithId(CStone::m_iClassID, CStone::New, 0);
    CPersistence::RegisterClassWhithId(CTree::m_iClassID, CTree::New, 0);
    CPersistence::RegisterClassWhithId(CShadowHerb::m_iClassID, CShadowHerb::New, 0);
    CPersistence::RegisterClassWhithId(CDecoObject::m_iClassID, CDecoObject::New, 0);
    CPersistence::RegisterClassWhithId(CAnyWherePileRole::m_iClassID, CAnyWherePileRole::New, 0);
    CPersistence::RegisterClassWhithId(CBuildingSitePileRole::m_iClassID, CBuildingSitePileRole::New, 0);
    CPersistence::RegisterClassWhithId(CDeliverPileRole::m_iClassID, CDeliverPileRole::New, 0);
    CPersistence::RegisterClassWhithId(CProductionPileRole::m_iClassID, CProductionPileRole::New, 0);
    CPersistence::RegisterClassWhithId(CStoragePileRole::m_iClassID, CStoragePileRole::New, 0);
    CPersistence::RegisterClassWhithId(CTradePileRole::m_iClassID, CTradePileRole::New, 0);
    CPersistence::RegisterClassWhithId(CAnimalRanchRole::m_iClassID, CAnimalRanchRole::New, 0);
    CPersistence::RegisterClassWhithId(CBarrackRole::m_iClassID, CBarrackRole::New, 0);
    CPersistence::RegisterClassWhithId(CBigTempleRole::m_iClassID, CBigTempleRole::New, 0);
    CPersistence::RegisterClassWhithId(CBuildingSiteRole::m_iClassID, CBuildingSiteRole::New, 0);
    CPersistence::RegisterClassWhithId(CCastleRole::m_iClassID, CCastleRole::New, 0);
    CPersistence::RegisterClassWhithId(CDarkTempleRole::m_iClassID, CDarkTempleRole::New, 0);
    CPersistence::RegisterClassWhithId(CEyeCatcherRole::m_iClassID, CEyeCatcherRole::New, 0);
    CPersistence::RegisterClassWhithId(CFarmBuildingRole::m_iClassID, CFarmBuildingRole::New, 0);
    CPersistence::RegisterClassWhithId(CGatherBuildingRole::m_iClassID, CGatherBuildingRole::New, 0);
    CPersistence::RegisterClassWhithId(CLookoutTowerRole::m_iClassID, CLookoutTowerRole::New, 0);
    CPersistence::RegisterClassWhithId(CMilitaryBuildingRole::m_iClassID, CMilitaryBuildingRole::New, 0);
    CPersistence::RegisterClassWhithId(CMineRole::m_iClassID, CMineRole::New, 0);
    CPersistence::RegisterClassWhithId(CProductionBuildingRole::m_iClassID, CProductionBuildingRole::New, 0);
    CPersistence::RegisterClassWhithId(CResidenceBuildingRole::m_iClassID, CResidenceBuildingRole::New, 0);
    CPersistence::RegisterClassWhithId(CSimpleBuildingRole::m_iClassID, CSimpleBuildingRole::New, 0);
    CPersistence::RegisterClassWhithId(CSmallTempleRole::m_iClassID, CSmallTempleRole::New, 0);
    CPersistence::RegisterClassWhithId(CStorageBuildingRole::m_iClassID, CStorageBuildingRole::New, 0);
    CPersistence::RegisterClassWhithId(CTradingBuildingRole::m_iClassID, CTradingBuildingRole::New, 0);
    CPersistence::RegisterClassWhithId(CWorkshopBuildingRole::m_iClassID, CWorkshopBuildingRole::New, 0);
    CPersistence::RegisterClassWhithId(CWorkUpBuildingRole::m_iClassID, CWorkUpBuildingRole::New, 0);
    CPersistence::RegisterClassWhithId(CBuilderRole::m_iClassID, CBuilderRole::New, 0);
    CPersistence::RegisterClassWhithId(CCarrierRole::m_iClassID, CCarrierRole::New, 0);
    CPersistence::RegisterClassWhithId(CDarkGardenerRole::m_iClassID, CDarkGardenerRole::New, 0);
    CPersistence::RegisterClassWhithId(CDiggerRole::m_iClassID, CDiggerRole::New, 0);
    CPersistence::RegisterClassWhithId(CHunterRole::m_iClassID, CHunterRole::New, 0);
    CPersistence::RegisterClassWhithId(CDonkeyRole::m_iClassID, CDonkeyRole::New, 0);
    CPersistence::RegisterClassWhithId(CDoorRole::m_iClassID, CDoorRole::New, 0);
    CPersistence::RegisterClassWhithId(CFleeRole::m_iClassID, CFleeRole::New, 0);
    CPersistence::RegisterClassWhithId(CFreeWorkerRole::m_iClassID, CFreeWorkerRole::New, 0);
    CPersistence::RegisterClassWhithId(CGardenerRole::m_iClassID, CGardenerRole::New, 0);
    CPersistence::RegisterClassWhithId(CGeologistRole::m_iClassID, CGeologistRole::New, 0);
    CPersistence::RegisterClassWhithId(CHouseWorkerRole::m_iClassID, CHouseWorkerRole::New, 0);
    CPersistence::RegisterClassWhithId(CMushroomFarmerRole::m_iClassID, CMushroomFarmerRole::New, 0);
    CPersistence::RegisterClassWhithId(CPioneerRole::m_iClassID, CPioneerRole::New, 0);
    CPersistence::RegisterClassWhithId(CPriestRole::m_iClassID, CPriestRole::New, 0);
    CPersistence::RegisterClassWhithId(CSaboteurRole::m_iClassID, CSaboteurRole::New, 0);
    CPersistence::RegisterClassWhithId(CShamanRole::m_iClassID, CShamanRole::New, 0);
    CPersistence::RegisterClassWhithId(CSlaveRole::m_iClassID, CSlaveRole::New, 0);
    CPersistence::RegisterClassWhithId(CSoldierRole::m_iClassID, CSoldierRole::New, 0);
    CPersistence::RegisterClassWhithId(CThiefRole::m_iClassID, CThiefRole::New, 0);
    CPersistence::RegisterClassWhithId(CTowerSoldier::m_iClassID, CTowerSoldier::New, 0);
    CPersistence::RegisterClassWhithId(CCart::m_iClassID, CCart::New, 0);
    CPersistence::RegisterClassWhithId(CRomanCatapult::m_iClassID, CRomanCatapult::New, 0);
    CPersistence::RegisterClassWhithId(CMayaCatapult::m_iClassID, CMayaCatapult::New, 0);
    CPersistence::RegisterClassWhithId(CVikingCatapult::m_iClassID, CVikingCatapult::New, 0);
    CPersistence::RegisterClassWhithId(CTrojanCatapult::m_iClassID, CTrojanCatapult::New, 0);
    CPersistence::RegisterClassWhithId(CFerryShip::m_iClassID, CFerryShip::New, 0);
    CPersistence::RegisterClassWhithId(CTransportShip::m_iClassID, CTransportShip::New, 0);
    CPersistence::RegisterClassWhithId(CWarShip::m_iClassID, CWarShip::New, 0);
    CPersistence::RegisterClassWhithId(CEntityTask::m_iClassID, CEntityTask::New, 0);
    CPersistence::RegisterClassWhithId(CEntityEvent::m_iClassID, CEntityEvent::New, 0);
    CPersistence::RegisterClassWhithId(CEcoSector::m_iClassID, CEcoSector::New, 0);
    CPersistence::RegisterClassWhithId(CGoodTransportPriority::m_iClassID, CGoodTransportPriority::New, 0);
    CPersistence::RegisterClassWhithId(CBuildingSupplyPriority::m_iClassID, CBuildingSupplyPriority::New, 0);
    CPersistence::RegisterClassWhithId(CDarkMushroomFarmRole::m_iClassID, CDarkMushroomFarmRole::New, 0);
    CPersistence::RegisterClassWhithId(CRomanWarShip::m_iClassID, CRomanWarShip::New, 0);
    CPersistence::RegisterClassWhithId(CMayaWarShip::m_iClassID, CMayaWarShip::New, 0);
    CPersistence::RegisterClassWhithId(CVikingWarShip::m_iClassID, CVikingWarShip::New, 0);
    CPersistence::RegisterClassWhithId(CTrojanWarShip::m_iClassID, CTrojanWarShip::New, 0);
    CPersistence::RegisterClassWhithId(CSquadLeaderRole::m_iClassID, CSquadLeaderRole::New, 0);
    CPersistence::RegisterClassWhithId(CManakopter::m_iClassID, CManakopter::New, 0);
    CPersistence::RegisterClassWhithId(CManakopterHallRole::m_iClassID, CManakopterHallRole::New, 0);
    CPersistence::RegisterClassWhithId(CHJBRole::m_iClassID, CHJBRole::New, 0);
    s_bSetPersistenceClasses = 1;
  }
}

// address=[0x130e9f0]
// Decompiled from int CPersistence::ClassID()
unsigned long CPersistence::ClassID(void) const
{
  return CPersistence::m_iClassID;
}

// address=[0x13ed840]
// Decompiled from void __thiscall CPersistence::Store(struct CPersistence *this, struct std::ostream *a2)
void CPersistence::Store(std::ostream &a2)
{

  unsigned int classId; // [esp+0h] [ebp-8h] BYREF
  classId = this->ClassID();
  a2 << classId;
}

// address=[0x13ed870]
// Decompiled from void __cdecl CPersistence::RegisterClassWhithId(  unsigned int *_rClassId,  struct CPersistence *(__cdecl *_rClassDeserializer)(struct std::istrstream *),  unsigned int _iOverrideClassId)
void __cdecl CPersistence::RegisterClassWhithId(unsigned long &_rClassId, DeserializerFunc _rClassDeserializer, unsigned long _iOverrideClassId)
{

  if (!_iOverrideClassId)
    _iOverrideClassId = CPersistence::m_iNextClassID++;
  _rClassId = _iOverrideClassId;
  g_mPersistenceClassDeserializer[_iOverrideClassId] = _rClassDeserializer;
}

// address=[0x13ed8b0]
// Decompiled from int __cdecl CPersistence::New(struct std::istream *stream)
class CPersistence *__cdecl CPersistence::New(std::istream &stream)
{
  unsigned long classId = 0;
  stream >> classId;
  if (stream.fail())
  {
    throw new CPersistence::SerialError();
  }

  auto it = g_mPersistenceClassDeserializer.find(classId);

  if (it == g_mPersistenceClassDeserializer.end())
  {
    throw new CPersistence::BadClassID();
  }

  return it->second(stream);
}

// address=[0x13ed9d0]
// Decompiled from struct CPersistence *__cdecl CPersistence::New_HACK_VERSION(struct std::istream *stream)
class CPersistence *__cdecl CPersistence::New_HACK_VERSION(std::istream &stream)
{
  unsigned long classId = 0;
  stream >> classId;
  if (stream.fail())
  {
    throw new CPersistence::SerialError();
  }

  // TODO: This is so weird... The hack should not be necessary, as the class ID should be correctly set...

  return new CSquadLeaderRole(stream);
}

// address=[0x14d7f80]
// Decompiled from CPersistence *__thiscall CPersistence::CPersistence(CPersistence *this)
// CPersistence::CPersistence(class CPersistence const &){}

// address=[0x14e4760]
// Decompiled from void *__thiscall CPersistence::operator=(void *this, int a2)
// class CPersistence &CPersistence::operator=(class CPersistence const &a2){}

// address=[0x154edd0]
// Decompiled from CPersistence *__thiscall CPersistence::CPersistence(  CPersistence *this,  const struct boost::exception_detail::clone_base *a2)
// CPersistence::CPersistence(class CPersistence &&a2){}

// address=[0x130e3c0]
// Decompiled from CPersistence *__thiscall CPersistence::CPersistence(CPersistence *this)
// CPersistence::CPersistence(void){}

// address=[0x13eda90]
// Decompiled from char __cdecl CPersistence::LOAD_UINT8(int a1)
unsigned char __cdecl CPersistence::LOAD_UINT8(std::istream &a1)
{
  uint8_t loadedValue;
  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x13edae0]
// Decompiled from __int16 __cdecl CPersistence::LOAD_UINT16(int a1)
unsigned short __cdecl CPersistence::LOAD_UINT16(std::istream &a1)
{
  uint16_t loadedValue;
  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x13edb30]
// Decompiled from int __cdecl CPersistence::LOAD_UINT32(int a1)
unsigned int __cdecl CPersistence::LOAD_UINT32(std::istream &a1)
{
  uint32_t loadedValue;
  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x13edb80]
// Decompiled from char __cdecl CPersistence::LOAD_INT8(int a1)
signed char __cdecl CPersistence::LOAD_INT8(std::istream &a1)
{
  int8_t loadedValue;
  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x13edbd0]
// Decompiled from __int16 __cdecl CPersistence::LOAD_INT16(int a1)
short __cdecl CPersistence::LOAD_INT16(std::istream &a1)
{
  int16_t loadedValue;
  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x13edc20]
// Decompiled from int __cdecl CPersistence::LOAD_INT32(int a1)
int __cdecl CPersistence::LOAD_INT32(std::istream &a1)
{
  int32_t loadedValue;
  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x13edc70]
// Decompiled from int __cdecl CPersistence::LOAD_ID(int a1)
unsigned long __cdecl CPersistence::LOAD_ID(std::istream &a1)
{
  int32_t loadedValue;
  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x13edcc0]
// Decompiled from double __cdecl CPersistence::LOAD_FLOAT64(int a1)
double __cdecl CPersistence::LOAD_FLOAT64(std::istream &a1)
{
  double_t loadedValue;
  static_assert(sizeof(loadedValue) == 8, "Size mismatch");

  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x13edd10]
// Decompiled from double __cdecl CPersistence::LOAD_FLOAT32(int a1)
float __cdecl CPersistence::LOAD_FLOAT32(std::istream &a1)
{
  float_t loadedValue;
  static_assert(sizeof(loadedValue) == 4, "Size mismatch");

  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x13edd60]
// Decompiled from char __cdecl CPersistence::LOAD_char(int a1)
char __cdecl CPersistence::LOAD_char(std::istream &a1)
{
  int8_t loadedValue;
  static_assert(sizeof(loadedValue) == 1, "Size mismatch");

  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x13eddb0]
// Decompiled from int __cdecl CPersistence::LOAD_string(int a1, int a2)
std::string __cdecl CPersistence::LOAD_string(std::istream &a1)
{
  std::string loadedValue;
  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x13ede70]
// Decompiled from char __cdecl CPersistence::LOAD_bool(int a1)
bool __cdecl CPersistence::LOAD_bool(std::istream &a1)
{
  bool loadedValue;
  static_assert(sizeof(loadedValue) == 1, "Size mismatch");

  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x3d89400]
// [Decompilation failed for static unsigned long CPersistence::m_iNextClassID]

// address=[0x3efe474]
// [Decompilation failed for static unsigned long CPersistence::m_iClassID]
