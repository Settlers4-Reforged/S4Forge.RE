#if FALSE
#include "CLandscapeProperties.h"

// Definitions for class CLandscapeProperties

// address=[0x141d960]
// Decompiled from bool __thiscall CLandscapeProperties::IsBlockedLand(CLandscapeProperties *this, int a2)
bool  CLandscapeProperties::IsBlockedLand(int a2) {
  
  return (this->m_uLandscapeProperty[a2] & LANDSCAPE_BLOCKED) != 0;
}


// address=[0x141d9a0]
// Decompiled from bool __cdecl CLandscapeProperties::IsWater(int a1)
bool __cdecl CLandscapeProperties::IsWater(int a1) {
  
  return a1 <= 8;
}


// address=[0x15f5960]
// Decompiled from int __thiscall CLandscapeProperties::TileType(CLandscapeProperties *this, int a2)
unsigned int  CLandscapeProperties::TileType(int a2) {
  
  return (unsigned __int8)this->m_uLandscapeProperty[a2] << 28;
}


// address=[0x16a5e60]
// Decompiled from CLandscapeProperties *__thiscall CLandscapeProperties::CLandscapeProperties(CLandscapeProperties *this)
 CLandscapeProperties::CLandscapeProperties(void) {
  
  this->m_uLandscapeProperty[GROUND_GRASS] = 1;
  this->m_uLandscapeProperty[0] = 18;
  this->m_uLandscapeProperty[GROUND_WATER2] = 18;
  this->m_uLandscapeProperty[GROUND_WATER3] = 18;
  this->m_uLandscapeProperty[GROUND_WATER4] = 18;
  this->m_uLandscapeProperty[GROUND_WATER5] = 18;
  this->m_uLandscapeProperty[GROUND_WATER6] = 18;
  this->m_uLandscapeProperty[GROUND_WATER7] = 18;
  this->m_uLandscapeProperty[GROUND_WATER8] = 18;
  this->m_uLandscapeProperty[GROUND_BEACH] = 1;
  this->m_uLandscapeProperty[GROUND_WATER_BEACH] = 18;
  this->m_uLandscapeProperty[GROUND_MOUNTAIN] = 5;
  this->m_uLandscapeProperty[GROUND_GRASS_MOUNTAIN] = 5;
  this->m_uLandscapeProperty[GROUND_MOUNTAIN_GRASS] = 5;
  this->m_uLandscapeProperty[GROUND_SNOW_MOUNTAIN] = 17;
  this->m_uLandscapeProperty[GROUND_MOUNTAIN_SNOW] = 5;
  this->m_uLandscapeProperty[GROUND_GRASS_DARK] = 1;
  this->m_uLandscapeProperty[GROUND_GRASS_WEIRD] = 1;
  this->m_uLandscapeProperty[GROUND_GRASS_ISLAND] = 1;
  this->m_uLandscapeProperty[GROUND_SNOW] = 17;
  this->m_uLandscapeProperty[GROUND_SWAMP] = 17;
  this->m_uLandscapeProperty[GROUND_SWAMP_GRASS] = 17;
  this->m_uLandscapeProperty[GROUND_GRASS_SWAMP] = 1;
  this->m_uLandscapeProperty[GROUND_DESERT] = 1;
  this->m_uLandscapeProperty[GROUND_DESERT_GRASS] = 1;
  this->m_uLandscapeProperty[GROUND_GRASS_DESERT] = 1;
  this->m_uLandscapeProperty[GROUND_MUD] = 1;
  this->m_uLandscapeProperty[GROUND_MUD_GRASS] = 1;
  this->m_uLandscapeProperty[GROUND_GRASS_MUD] = 1;
  this->m_uLandscapeProperty[GROUND_RIVER1] = 1;
  this->m_uLandscapeProperty[GROUND_RIVER2] = 1;
  this->m_uLandscapeProperty[GROUND_RIVER3] = 1;
  this->m_uLandscapeProperty[GROUND_RIVER4] = 1;
  this->m_uLandscapeProperty[GROUND_GRASS_DUSTY] = 1;
  this->m_uLandscapeProperty[GROUND_GRASS_PAVEMENT] = 1;
  return this;
}


// address=[0x16a7200]
// Decompiled from bool __thiscall CLandscapeProperties::IsSlowType(CLandscapeProperties *this, int a2)
bool  CLandscapeProperties::IsSlowType(int a2) {
  
  return (this->m_uLandscapeProperty[a2] & LANDSCAPE_SLOW) != 0;
}


#endif // Already implemented
