#include "IVehicleInfoMgr.h"

// Definitions for class IVehicleInfoMgr

// address=[0x152f270]
// Decompiled from SVehicleProperties *__cdecl IVehicleInfoMgr::VehicleProperties(unsigned int _uRace, unsigned int _uVehicleType)
struct SVehicleProperties const * __cdecl IVehicleInfoMgr::VehicleProperties(unsigned int _uRace, unsigned int _uVehicleType) {
  
  if ( !IVehicleInfoMgr::m_bInitialized && BBSupportDbgReport(2, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\VehicleProperties.h", 138, "m_bInitialized") == 1 )
  {
    __debugbreak();
  }
  if ( _uRace >= 5 && BBSupportDbgReport(2, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\VehicleProperties.h", 139, "_uRace < RACE_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( _uVehicleType >= 6 && BBSupportDbgReport(2, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\VehicleProperties.h", 140, "_uVehicleType < VEHICLE_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( !IVehicleInfoMgr::m_sVehicleProperties[_uRace][_uVehicleType].m_bInitialized && BBSupportDbgReport(2, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\VehicleProperties.h", 141, "m_sVehicleProperties[_uRace][_uVehicleType].m_bInitialized") == 1 )
  {
    __debugbreak();
  }
  return &IVehicleInfoMgr::m_sVehicleProperties[_uRace][_uVehicleType];
}


// address=[0x15ac380]
// Decompiled from IVehicleInfoMgr *__thiscall IVehicleInfoMgr::IVehicleInfoMgr(IVehicleInfoMgr *this)
 IVehicleInfoMgr::IVehicleInfoMgr(void) {
  
  *(_DWORD *)this = &IVehicleInfoMgr::_vftable_;
  return this;
}


// address=[0x4158f28]
// [Decompilation failed for static bool IVehicleInfoMgr::m_bInitialized]

// address=[0x4158f30]
// [Decompilation failed for static struct SVehicleProperties (* IVehicleInfoMgr::m_sVehicleProperties)[6]]

