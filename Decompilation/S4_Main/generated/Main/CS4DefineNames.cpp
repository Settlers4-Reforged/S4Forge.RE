#include "CS4DefineNames.h"

// Definitions for class CS4DefineNames

// address=[0x149ab50]
// Decompiled from const char *__cdecl CS4DefineNames::GetAnimalName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetAnimalName(int a1) {
  
  if ( a1 >= 0x12 )
    return "<INVALID>";
  else
    return (&off_37206FC)[2 * a1];
}


// address=[0x149ab70]
// Decompiled from const char *__cdecl CS4DefineNames::GetBuildingName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetBuildingName(int a1) {
  
  if ( a1 >= 0x53 )
    return "<INVALID>";
  else
    return (&off_370724C)[2 * a1];
}


// address=[0x149ab90]
// Decompiled from const char *__cdecl CS4DefineNames::GetGoodName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetGoodName(int a1) {
  
  if ( a1 >= 0x2B )
    return "<INVALID>";
  else
    return (&off_3715304)[2 * a1];
}


// address=[0x149abb0]
// Decompiled from const char *__cdecl CS4DefineNames::GetObjectName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetObjectName(int a1) {
  
  if ( a1 >= 0x123 )
    return "<INVALID>";
  else
    return (&off_3722104)[2 * a1];
}


// address=[0x149abe0]
// Decompiled from const char *__cdecl CS4DefineNames::GetRaceName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetRaceName(int a1) {
  
  if ( a1 >= 5 )
    return "<INVALID>";
  else
    return off_3D89C08[a1];
}


// address=[0x149ac00]
// Decompiled from const char *__cdecl CS4DefineNames::GetSettlerName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetSettlerName(int a1) {
  
  if ( a1 >= 0x43 )
    return "<INVALID>";
  else
    return (&off_3716B6C)[2 * a1];
}


// address=[0x149ac20]
// Decompiled from const char *__cdecl CS4DefineNames::GetSettlerJobName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetSettlerJobName(int a1) {
  
  if ( a1 >= 0x16F )
    return "<INVALID>";
  else
    return (&off_3716D84)[2 * a1];
}


// address=[0x149ac60]
// Decompiled from const char *__cdecl CS4DefineNames::GetSoundName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetSoundName(int a1) {
  
  if ( a1 >= 0x6D )
    return "<INVALID>";
  else
    return (&off_371D624)[2 * a1];
}


// address=[0x149ac80]
// Decompiled from const char *__cdecl CS4DefineNames::GetStringName(unsigned int a1)
char const * __cdecl CS4DefineNames::GetStringName(int a1) {
  
  if ( a1 >= 0xEFD )
    return "<INVALID>";
  else
    return (&off_3725E64)[2 * a1];
}


// address=[0x149acb0]
// Decompiled from int __cdecl CS4DefineNames::GetStringId(char *Str1)
int __cdecl CS4DefineNames::GetStringId(char const * Str1) {
  
  int i; // [esp+4h] [ebp-4h]

  if ( !Str1 || !*Str1 )
    return -1;
  for ( i = 0; i < 3837; ++i )
  {
    if ( !j__strcmp(Str1, (&off_3725E64)[2 * i]) )
      return dword_3725E60[2 * i];
  }
  return -1;
}


