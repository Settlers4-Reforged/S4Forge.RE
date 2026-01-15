#include "CTimeInfo.h"

// Definitions for class CTimeInfo

// address=[0x14d31b0]
// Decompiled from void *__cdecl CTimeInfo::GetDateTimeString(void *a1, int a2)
static std::string __cdecl CTimeInfo::GetDateTimeString(int) {
  
  __time64_t Time; // [esp+0h] [ebp-11Ch] BYREF
  size_t v4; // [esp+8h] [ebp-114h]
  int v5; // [esp+Ch] [ebp-110h]
  char Destination[4]; // [esp+10h] [ebp-10Ch] BYREF
  _DWORD *v7; // [esp+14h] [ebp-108h]
  char Str[256]; // [esp+18h] [ebp-104h] BYREF

  v5 = 0;
  strcpy(Destination, "AM");
  sub_14D3360(&Time);
  v7 = (_DWORD *)sub_14D33F0(&Time);
  if ( a2 )
  {
    j__sprintf(Str, "%d. %s, %d, %02i:%02i", v7[3], &g_aszMonthNamesDe[6 * v7[4]], v7[5] + 1900, v7[2], v7[1]);
  }
  else
  {
    if ( (int)v7[2] > 12 )
      j__strcpy_0(Destination, "PM");
    if ( (int)v7[2] > 12 )
      v7[2] -= 12;
    if ( !v7[2] )
      v7[2] = 12;
    j__sprintf(
      Str,
      "%s %dth, %d, %02i:%02i%s",
      &g_aszMonthNamesEn[6 * v7[4]],
      v7[3],
      v7[5] + 1900,
      v7[2],
      v7[1],
      Destination);
  }
  v4 = j__strlen(Str);
  std::string::string(a1, Str);
  return a1;
}


