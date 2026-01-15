#include "IVehicleInfoMgr.h"

// Definitions for class IVehicleInfoMgr

// address=[0x152f270]
// Decompiled from char *__cdecl IVehicleInfoMgr::VehicleProperties(unsigned int a1, unsigned int a2)
static struct SVehicleProperties const * __cdecl IVehicleInfoMgr::VehicleProperties(unsigned int,unsigned int) {
  
  if ( !IVehicleInfoMgr::m_bInitialized
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\VehicleProperties.h",
         138,
         "m_bInitialized") == 1 )
  {
    __debugbreak();
  }
  if ( a1 >= 5
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\VehicleProperties.h",
         139,
         "_uRace < RACE_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a2 >= 6
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\VehicleProperties.h",
         140,
         "_uVehicleType < VEHICLE_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( !byte_4158F88[552 * a1 + 92 * a2]
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\VehicleProperties.h",
         141,
         "m_sVehicleProperties[_uRace][_uVehicleType].m_bInitialized") == 1 )
  {
    __debugbreak();
  }
  return (char *)&IVehicleInfoMgr::m_sVehicleProperties + 552 * a1 + 92 * a2;
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

