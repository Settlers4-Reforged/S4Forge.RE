#if FALSE
#include "CS4DefineNames.h"

// Definitions for class CS4DefineNames

// address=[0x149ab50]
// Decompiled from const char *__cdecl CS4DefineNames::GetAnimalName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetAnimalName(int a1) {
  
  if ( a1 >= 18 )
    return "<INVALID>";
  else
    return s_sAnimalDefines[a1].m_spName;
}


// address=[0x149ab70]
// Decompiled from const char *__cdecl CS4DefineNames::GetBuildingName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetBuildingName(int a1) {
  
  if ( a1 >= 83 )
    return "<INVALID>";
  else
    return s_sBuildingNames[a1].m_spName;
}


// address=[0x149ab90]
// Decompiled from const char *__cdecl CS4DefineNames::GetGoodName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetGoodName(int a1) {
  
  if ( a1 >= 43 )
    return "<INVALID>";
  else
    return s_sGoodName[a1].m_spName;
}


// address=[0x149abb0]
// Decompiled from const char *__cdecl CS4DefineNames::GetObjectName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetObjectName(int a1) {
  
  if ( a1 >= 291 )
    return "<INVALID>";
  else
    return s_sObjectNames[a1].m_spName;
}


// address=[0x149abe0]
// Decompiled from const char *__cdecl CS4DefineNames::GetRaceName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetRaceName(int a1) {
  
  if ( a1 >= 5 )
    return "<INVALID>";
  else
    return s_spRaceNames[a1];
}


// address=[0x149ac00]
// Decompiled from const char *__cdecl CS4DefineNames::GetSettlerName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetSettlerName(int a1) {
  
  if ( a1 >= 67 )
    return "<INVALID>";
  else
    return s_sSettlerName[a1].m_spName;
}


// address=[0x149ac20]
// Decompiled from const char *__cdecl CS4DefineNames::GetSettlerJobName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetSettlerJobName(int a1) {
  
  if ( a1 >= 367 )
    return "<INVALID>";
  else
    return s_sSettlerJobName[a1].m_spName;
}


// address=[0x149ac60]
// Decompiled from const char *__cdecl CS4DefineNames::GetSoundName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetSoundName(int a1) {
  
  if ( a1 >= 109 )
    return "<INVALID>";
  else
    return s_sSoundNames[a1].m_spName;
}


// address=[0x149ac80]
// Decompiled from const char *__cdecl CS4DefineNames::GetStringName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetStringName(int a1) {
  
  if ( a1 >= 3837 )
    return "<INVALID>";
  else
    return s_sStringNames[a1].m_spName;
}


// address=[0x149acb0]
// Decompiled from int __cdecl CS4DefineNames::GetStringId(char *Str1)
int __cdecl CS4DefineNames::GetStringId(char const * Str1) {
  
  int i; // [esp+4h] [ebp-4h]

  if ( !Str1 || !*Str1 )
    return -1;
  for ( i = 0; i < 3837; ++i )
  {
    if ( !j__strcmp(Str1, s_sStringNames[i].m_spName) )
      return s_sStringNames[i].m_iNr;
  }
  return -1;
}


#endif // Already implemented
