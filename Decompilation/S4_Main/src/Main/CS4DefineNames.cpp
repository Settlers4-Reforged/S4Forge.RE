#include "CS4DefineNames.h"

#include "Defines/Animals.h"
#include "Defines/Buildings.h"
#include "Defines/Goods.h"
#include "Defines/Object.h"
#include "Defines/Races.h"
#include "Defines/Settlers.h"
#include "Defines/Sound.h"
#include "Defines/Translations.h"

// Definitions for class CS4DefineNames

// address=[0x149ab50]
// Decompiled from const char *__cdecl CS4DefineNames::GetAnimalName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetAnimalName(int a1) {
  if(a1 >= 18)
    return "<INVALID>";
  else
    return s_sAnimalDefines[a1].m_spName;
}


// address=[0x149ab70]
// Decompiled from const char *__cdecl CS4DefineNames::GetBuildingName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetBuildingName(int a1) {
  if(a1 >= 83)
    return "<INVALID>";
  else
    return s_sBuildingDefines[a1].m_spName;
}


// address=[0x149ab90]
// Decompiled from const char *__cdecl CS4DefineNames::GetGoodName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetGoodName(int a1) {
  if(a1 >= 0x2B)
    return "<INVALID>";
  else
    return s_sGoodDefines[a1].m_spName;
}


// address=[0x149abb0]
// Decompiled from const char *__cdecl CS4DefineNames::GetObjectName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetObjectName(int a1) {
  if(a1 >= 291) // TODO: Actually a bug - 291 is not defined in the original list!
    return "<INVALID>";
  else
    return s_sObjectDefines[a1].m_spName;
}


// address=[0x149abe0]
// Decompiled from const char *__cdecl CS4DefineNames::GetRaceName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetRaceName(int a1) {
  if(a1 >= 5)
    return "<INVALID>";
  else
    return s_spRaceNames[a1];
}


// address=[0x149ac00]
// Decompiled from const char *__cdecl CS4DefineNames::GetSettlerName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetSettlerName(int a1) {
  if(a1 >= 67) // TODO: again, off by one...
    return "<INVALID>";
  else
    return s_sSettlerDefines[a1].m_spName;
}


// address=[0x149ac20]
// Decompiled from const char *__cdecl CS4DefineNames::GetSettlerJobName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetSettlerJobName(int a1) {
  if(a1 >= 367)
    return "<INVALID>";
  else
    return s_sSettlerJobDefines[a1].m_spName;
}


// address=[0x149ac60]
// Decompiled from const char *__cdecl CS4DefineNames::GetSoundName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetSoundName(int a1) {
  if(a1 >= 109)
    return "<INVALID>";
  else
    return s_sSoundDefines[a1].m_spName;
}


// address=[0x149ac80]
// Decompiled from const char *__cdecl CS4DefineNames::GetStringName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetStringName(int a1) {
  if(a1 >= STRINGID_MAX)
    return "<INVALID>";
  else
    return s_TranslationDefines[a1].m_spName;
}


// address=[0x149acb0]
// Decompiled from int __cdecl CS4DefineNames::GetStringId(char *Str1)
int __cdecl CS4DefineNames::GetStringId(char const *Str1) {
  int i; // [esp+4h] [ebp-4h]

  if(!Str1 || !*Str1)
    return -1;
  for(i = 0; i < 3837; ++i) {
    if(!strcmp(Str1, s_TranslationDefines[i].m_spName))
      return s_TranslationDefines[i].m_iId;
  }
  return -1;
}


