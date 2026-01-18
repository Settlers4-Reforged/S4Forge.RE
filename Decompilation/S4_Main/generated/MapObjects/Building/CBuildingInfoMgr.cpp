#include "CBuildingInfoMgr.h"

// Definitions for class CBuildingInfoMgr

// address=[0x133ac00]
// Decompiled from char *__cdecl CBuildingInfoMgr::GetBuildingInfo(int a1, int a2)
struct CBuildingInfoMgr::SBuildingInfos const & __cdecl CBuildingInfoMgr::GetBuildingInfo(int a1, int a2) {
  
  if ( CBuildingInfoMgr::m_bInit != 1
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\mapobjects\\building\\BuildingInfoMgr.h",
         312,
         "m_bInit == true") == 1 )
  {
    __debugbreak();
  }
  return (char *)&CBuildingInfoMgr::m_vBuildingInfos + 70384 * a1 + 848 * a2;
}


// address=[0x1486f70]
// Decompiled from int __thiscall CBuildingInfoMgr::GetXMLVersion(CBuildingInfoMgr *this)
int  CBuildingInfoMgr::GetXMLVersion(void)const {
  
  return *(_DWORD *)this;
}


// address=[0x14eb8f0]
// Decompiled from CBuildingInfoMgr *__thiscall CBuildingInfoMgr::CBuildingInfoMgr(CBuildingInfoMgr *this)
 CBuildingInfoMgr::CBuildingInfoMgr(void) {
  
  CBuildingInfoMgr::ClearInfo(this);
  return this;
}


// address=[0x14eb910]
// Decompiled from void __thiscall CBuildingInfoMgr::~CBuildingInfoMgr(CBuildingInfoMgr *this)
 CBuildingInfoMgr::~CBuildingInfoMgr(void) {
  
  CBuildingInfoMgr::m_bInit = 0;
}


// address=[0x14eb930]
// Decompiled from void __thiscall CBuildingInfoMgr::LoadInfo(CBuildingInfoMgr *this, bool a2)
void  CBuildingInfoMgr::LoadInfo(bool a2) {
  
  if ( a2 )
    CBuildingInfoMgr::ClearInfo(this);
  if ( !CBuildingInfoMgr::m_bInit )
  {
    CBuildingInfoMgr::ReadBuildingInfo(this);
    CBuildingInfoMgr::m_bInit = 1;
  }
}


// address=[0x14eb970]
// Decompiled from char __thiscall CBuildingInfoMgr::DbgCheckBuildingBits(CBuildingInfoMgr *this, int a2, int a3)
bool  CBuildingInfoMgr::DbgCheckBuildingBits(int a2, int a3) {
  
  int v3; // eax
  _OWORD *v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  const char *BuildingName; // eax
  const char *v12; // eax
  const char *v13; // eax
  unsigned int v15; // [esp-8h] [ebp-4C00h]
  const char *RaceName; // [esp-4h] [ebp-4BFCh]
  const char *v17; // [esp-4h] [ebp-4BFCh]
  const char *v18; // [esp-4h] [ebp-4BFCh]
  _DWORD v19[7]; // [esp+4h] [ebp-4BF4h] BYREF
  _DWORD v20[7]; // [esp+20h] [ebp-4BD8h] BYREF
  _DWORD v21[7]; // [esp+3Ch] [ebp-4BBCh] BYREF
  _DWORD v22[8]; // [esp+58h] [ebp-4BA0h] BYREF
  _DWORD v23[8]; // [esp+78h] [ebp-4B80h] BYREF
  int v24; // [esp+98h] [ebp-4B60h]
  int v25; // [esp+9Ch] [ebp-4B5Ch]
  int v26; // [esp+A0h] [ebp-4B58h]
  int v27; // [esp+A4h] [ebp-4B54h]
  int v28; // [esp+A8h] [ebp-4B50h]
  int v29; // [esp+ACh] [ebp-4B4Ch]
  int v30; // [esp+B0h] [ebp-4B48h]
  int v31; // [esp+B4h] [ebp-4B44h]
  BOOL v32; // [esp+B8h] [ebp-4B40h]
  int v33; // [esp+BCh] [ebp-4B3Ch]
  int v34; // [esp+C0h] [ebp-4B38h]
  int i; // [esp+C4h] [ebp-4B34h]
  int v36; // [esp+C8h] [ebp-4B30h]
  char v37; // [esp+CFh] [ebp-4B29h]
  int v38; // [esp+D0h] [ebp-4B28h]
  int v39; // [esp+D4h] [ebp-4B24h]
  int v40; // [esp+D8h] [ebp-4B20h]
  int v41; // [esp+DCh] [ebp-4B1Ch]
  int j; // [esp+E0h] [ebp-4B18h]
  char v43; // [esp+E7h] [ebp-4B11h]
  char v44; // [esp+E8h] [ebp-4B10h]
  char v45; // [esp+E9h] [ebp-4B0Fh]
  char v46; // [esp+EAh] [ebp-4B0Eh]
  char v47; // [esp+EBh] [ebp-4B0Dh]
  char v48; // [esp+ECh] [ebp-4B0Ch]
  char v49; // [esp+EDh] [ebp-4B0Bh]
  char v50; // [esp+EEh] [ebp-4B0Ah]
  char v51; // [esp+EFh] [ebp-4B09h]
  char *v52; // [esp+F0h] [ebp-4B08h]
  _OWORD v53[400]; // [esp+F4h] [ebp-4B04h] BYREF
  _OWORD v54[400]; // [esp+19F4h] [ebp-3204h] BYREF
  _OWORD v55[400]; // [esp+32F4h] [ebp-1904h] BYREF

  v22[7] = this;
  v51 = 1;
  CBuildingBits::CBuildingBits((CBuildingBits *)v54);
  CBuildingBits::CBuildingBits((CBuildingBits *)v55);
  CBuildingBits::CBuildingBits((CBuildingBits *)v53);
  if ( a2 < 0 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingInfoMgr.cpp", 198, "_iRace >= RACE_FIRST") == 1 )
    __debugbreak();
  if ( a2 >= 5 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingInfoMgr.cpp", 199, "_iRace < RACE_MAX") == 1 )
    __debugbreak();
  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingInfoMgr.cpp", 200, "_iBuildingType > 0") == 1 )
    __debugbreak();
  if ( a3 >= 83
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingInfoMgr.cpp", 201, "_iBuildingType < BUILDING_MAX") == 1 )
  {
    __debugbreak();
  }
  v52 = (char *)&CBuildingInfoMgr::m_vBuildingInfos + 70384 * a2 + 848 * a3;
  v46 = 1;
  CBuildingFlagsWalk::CBuildingFlagsWalk((CBuildingFlagsWalk *)v22, 0, 0, *v52, v52[1], (int)(v52 + 736));
  while ( (unsigned __int8)CBuildingFlagsWalk::NextPosition(v22) )
  {
    v15 = CBuildingFlagsWalk::CurrentY(v22) + 15;
    v3 = CBuildingFlagsWalk::CurrentX(v22);
    if ( !Grid::InQuadrat(v3 + 15, v15, 0x1Fu) )
    {
      v46 = 0;
      break;
    }
  }
  if ( !v46 )
  {
    v51 = 0;
    BBSupportTracePrintF(3, "Invalid digging bits for building %i (%s) of race %i!", a3, (&off_377C0D4)[2 * a3], a2);
  }
  v37 = 1;
  if ( !v52[6] && (v52[52] < -15 || v52[53] > 15 || v52[54] < -15 || v52[55] > 15) )
  {
    v37 = 0;
    BBSupportTracePrintF(
      3,
      "Invalid size of bounding box for building %i (%s) of race %i!",
      a3,
      (&off_377C0D4)[2 * a3],
      a2);
  }
  v45 = 1;
  v44 = 1;
  CBuildingFlagsWalk::CBuildingFlagsWalk((CBuildingFlagsWalk *)v23, 0, 0, *v52, v52[1], (int)(v52 + 720));
  while ( (unsigned __int8)CBuildingFlagsWalk::NextPosition(v23) )
  {
    v4 = &v54[5 * CBuildingFlagsWalk::CurrentY(v23) + 200];
    *((_BYTE *)v4 + CBuildingFlagsWalk::CurrentX(v23) + 40) = 1;
    v5 = CBuildingFlagsWalk::CurrentX(v23);
    if ( v5 < v52[52]
      || (v6 = CBuildingFlagsWalk::CurrentX(v23), v6 > v52[53])
      || (v7 = CBuildingFlagsWalk::CurrentY(v23), v7 < v52[54])
      || (v8 = CBuildingFlagsWalk::CurrentY(v23), v8 > v52[55]) )
    {
      v45 = 0;
    }
    if ( CBuildingFlagsWalk::CurrentX(v23) < -15
      || CBuildingFlagsWalk::CurrentX(v23) > 15
      || CBuildingFlagsWalk::CurrentY(v23) < -15
      || CBuildingFlagsWalk::CurrentY(v23) > 15 )
    {
      v44 = 0;
    }
  }
  if ( !v45 )
  {
    v51 = 0;
    BBSupportTracePrintF(3, "Invalid bounding box for building %i (%s) of race %i!", a3, (&off_377C0D4)[2 * a3], a2);
  }
  if ( !v44 )
  {
    v51 = 0;
    BBSupportTracePrintF(
      3,
      "Building bits out of range (-15..15) for building %i (%s) of race %i!",
      a3,
      (&off_377C0D4)[2 * a3],
      a2);
  }
  v47 = 1;
  v48 = 0;
  CBuildingFlagsWalk::CBuildingFlagsWalk((CBuildingFlagsWalk *)v21, 0, 0, *v52, v52[1], (int)(v52 + 752));
  while ( (unsigned __int8)CBuildingFlagsWalk::NextPosition(v21) )
  {
    v33 = CBuildingFlagsWalk::CurrentX(v21);
    v34 = CBuildingFlagsWalk::CurrentY(v21);
    *((_BYTE *)&v55[5 * v34 + 202] + v33 + 8) = 1;
    v32 = !v33 && !v34;
    v48 |= v32;
    for ( i = 0; i <= 6; ++i )
    {
      v9 = CSpiralOffsets::DeltaX(i);
      v29 = v33 + v9;
      v10 = CSpiralOffsets::DeltaY(i);
      v23[7] = v34 + v10;
      if ( !*((_BYTE *)&v54[5 * v34 + 202 + 5 * v10] + v29 + 8) )
      {
        BBSupportTracePrintF(3, "No building bits around blocking bit at (%i, %i)!", v33, v34);
        v47 = 0;
      }
    }
  }
  if ( !v48 )
  {
    BBSupportTracePrintF(3, "Hotspot not blocked!");
    v47 = 0;
  }
  if ( !v47 )
  {
    v51 = 0;
    BBSupportTracePrintF(3, "Invalid blocking bits for building %i (%s) of race %i!", a3, (&off_377C0D4)[2 * a3], a2);
  }
  v49 = 1;
  v28 = v52[57];
  for ( j = 0; j < v28; ++j )
  {
    v36 = v52[16 * j + 62];
    v40 = v52[16 * j + 60];
    v41 = v52[16 * j + 61];
    if ( v36 > 0 && v36 < 43 || a3 == 13 )
    {
      if ( v40 >= -15 && v40 <= 15 && v41 >= -15 && v41 <= 15 )
      {
        if ( *((_BYTE *)&v54[5 * v41 + 202] + v40 + 8) )
        {
          if ( *((_BYTE *)&v55[5 * v41 + 202] + v40 + 8) )
          {
            BBSupportTracePrintF(3, "Pile %i, good %i, position (%i, %i): Position is blocked!", j, v36, v40, v41);
            v49 = 0;
          }
        }
        else
        {
          BBSupportTracePrintF(3, "Pile %i, good %i, position (%i, %i): No building bit at position!", j, v36, v40, v41);
          v49 = 0;
        }
      }
      else
      {
        BBSupportTracePrintF(3, "Pile %i, good %i, position (%i, %i): Out of area!", j, v36, v40, v41);
        v49 = 0;
      }
    }
    else
    {
      BBSupportTracePrintF(3, "Pile %i, good %i, position (%i, %i): Invalid good type!", j, v36, v40, v41);
      v49 = 0;
    }
  }
  if ( !v49 )
  {
    v51 = 0;
    BBSupportTracePrintF(3, "Invalid piles for building %i (%s) of race %i!", a3, (&off_377C0D4)[2 * a3], a2);
  }
  v50 = 1;
  v38 = v52[38];
  v39 = v52[39];
  if ( v38 >= -15 && v38 <= 15 && v39 >= -15 && v39 <= 15 )
  {
    if ( !*((_BYTE *)&v54[5 * v39 + 202] + v38 + 7) )
    {
      BBSupportTracePrintF(3, "No building bit at flag position (-1, 0)!");
      v50 = 0;
    }
    if ( !*((_BYTE *)&v54[5 * v39 + 202] + v38 + 9) )
    {
      BBSupportTracePrintF(3, "No building bit at flag position (+1, 0)!");
      v50 = 0;
    }
    if ( !*((_BYTE *)&v54[5 * v39 + 202] + v38 + 8) )
    {
      BBSupportTracePrintF(3, "No building bit at flag position!");
      v50 = 0;
    }
    if ( *((_BYTE *)&v55[5 * v39 + 202] + v38 + 7) )
    {
      BBSupportTracePrintF(3, "Flag position (-1, 0) is blocked!");
      v50 = 0;
    }
    if ( *((_BYTE *)&v55[5 * v39 + 202] + v38 + 9) )
    {
      BBSupportTracePrintF(3, "Flag position (+1, 0) is blocked!");
      v50 = 0;
    }
    if ( *((_BYTE *)&v55[5 * v39 + 202] + v38 + 8) )
    {
      BBSupportTracePrintF(3, "Flag position is blocked!");
      v50 = 0;
    }
  }
  else
  {
    BBSupportTracePrintF(3, "Invalid flag position!");
    v50 = 0;
  }
  if ( !v50 )
    v51 = 0;
  if ( v52[6] )
  {
    v43 = 0;
    v30 = v52[42];
    v31 = v52[43];
    CBuildingFlagsWalk::CBuildingFlagsWalk((CBuildingFlagsWalk *)v20, 0, 0, *v52, v52[1], (int)(v52 + 752));
    while ( (unsigned __int8)CBuildingFlagsWalk::NextPosition(v20) )
    {
      v27 = CBuildingFlagsWalk::CurrentX(v20);
      v26 = CBuildingFlagsWalk::CurrentY(v20);
      if ( v27 == v30 && v26 == v31 )
      {
        v43 = 1;
        break;
      }
    }
    if ( v43 )
    {
      BBSupportTracePrintF(
        3,
        "Invalid working position (%i, %i) for building %i (%s) of race %i!",
        v30,
        v31,
        a3,
        (&off_377C0D4)[2 * a3],
        a2);
      v51 = 0;
    }
  }
  if ( v52[6] )
  {
    CBuildingFlagsWalk::CBuildingFlagsWalk((CBuildingFlagsWalk *)v19, 0, 0, *v52, v52[1], (int)(v52 + 816));
    while ( (unsigned __int8)CBuildingFlagsWalk::NextPosition(v19) )
    {
      v24 = CBuildingFlagsWalk::CurrentX(v19);
      v25 = CBuildingFlagsWalk::CurrentY(v19);
      *((_BYTE *)&v53[5 * v25 + 202] + v24 + 8) = 1;
    }
  }
  RaceName = CS4DefineNames::GetRaceName(a2);
  BuildingName = CS4DefineNames::GetBuildingName(a3);
  BBSupportTracePrintF(-2147483641, "%s (%s)", BuildingName, RaceName);
  BBSupportTracePrintF(-2147483641, "Hotspot: ( %i, %i )", *v52, v52[1]);
  BBSupportTracePrintF(-2147483641, "B U I L D I N G   B I T S");
  CBuildingBits::PrintToTraceFile((CBuildingBits *)v54, -2147483641);
  v17 = CS4DefineNames::GetRaceName(a2);
  v12 = CS4DefineNames::GetBuildingName(a3);
  BBSupportTracePrintF(-2147483641, "%s (%s)", v12, v17);
  BBSupportTracePrintF(-2147483641, "B L O C K I N G   B I T S");
  CBuildingBits::PrintToTraceFile((CBuildingBits *)v55, -2147483641);
  if ( !v52[6] )
    return v51;
  v18 = CS4DefineNames::GetRaceName(a2);
  v13 = CS4DefineNames::GetBuildingName(a3);
  BBSupportTracePrintF(-2147483641, "%s (%s)", v13, v18);
  BBSupportTracePrintF(-2147483641, "W A T E R   B I T S");
  CBuildingBits::PrintToTraceFile((CBuildingBits *)v53, -2147483641);
  return v51;
}


// address=[0x14ec5d0]
// Decompiled from int __thiscall CBuildingInfoMgr::DbgTraceProductionDelays(CBuildingInfoMgr *this)
void  CBuildingInfoMgr::DbgTraceProductionDelays(void) {
  
  int result; // eax
  const char *BuildingName; // eax
  int v3; // [esp-10h] [ebp-34h]
  int v4; // [esp-Ch] [ebp-30h]
  int v5; // [esp-8h] [ebp-2Ch]
  int v6; // [esp-4h] [ebp-28h]
  int i; // [esp+4h] [ebp-20h]
  int j; // [esp+8h] [ebp-1Ch]
  _DWORD v9[5]; // [esp+Ch] [ebp-18h]

  result = BBSupportTracePrintF(1, "%-30s  %-7s %-7s %-7s %-7s", "Building", "Roman", "Viking", "Maya", "Trojan");
  for ( i = 1; i < 83; ++i )
  {
    for ( j = 0; j < 5; ++j )
      v9[j] = (unsigned __int8)byte_4035480[70384 * j + 848 * i];
    v6 = v9[4];
    v5 = v9[2];
    v4 = v9[1];
    v3 = v9[0];
    BuildingName = CS4DefineNames::GetBuildingName(i);
    BBSupportTracePrintF(1, "%-30s  %3i     %3i     %3i     %3i", BuildingName, v3, v4, v5, v6);
    result = i + 1;
  }
  return result;
}


// address=[0x14f3cc0]
// Decompiled from bool __cdecl CBuildingInfoMgr::BuildingTypeExIsPort(int a1)
bool __cdecl CBuildingInfoMgr::BuildingTypeExIsPort(int a1) {
  
  return a1 >= 52 && a1 <= 57 || a1 >= 78 && a1 <= 79;
}


// address=[0x14f3d00]
// Decompiled from bool __cdecl CBuildingInfoMgr::BuildingTypeExIsShipyard(int a1)
bool __cdecl CBuildingInfoMgr::BuildingTypeExIsShipyard(int a1) {
  
  return a1 >= 58 && a1 <= 63 || a1 >= 76 && a1 <= 77;
}


// address=[0x1501110]
// Decompiled from char *__cdecl CBuildingInfoMgr::GetTriggerInfo(int a1, int a2)
struct CBuildingInfoMgr::STriggerInfos const & __cdecl CBuildingInfoMgr::GetTriggerInfo(int a1, int a2) {
  
  if ( CBuildingInfoMgr::m_bInit != 1
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\mapobjects\\building\\BuildingInfoMgr.h",
         351,
         "m_bInit == true") == 1 )
  {
    __debugbreak();
  }
  return (char *)&CBuildingInfoMgr::m_vTriggerInfos + 1692 * a1 + 36 * a2;
}


// address=[0x14ec6c0]
// Decompiled from void *__thiscall CBuildingInfoMgr::ClearInfo(CBuildingInfoMgr *this)
void  CBuildingInfoMgr::ClearInfo(void) {
  
  void *result; // eax
  CBuildingInfoMgr *v2; // [esp+0h] [ebp-14h]
  int v3; // [esp+0h] [ebp-14h]
  int v4; // [esp+0h] [ebp-14h]
  int v5; // [esp+0h] [ebp-14h]
  int v6; // [esp+0h] [ebp-14h]
  int v7; // [esp+0h] [ebp-14h]
  int v8; // [esp+0h] [ebp-14h]
  int v9; // [esp+0h] [ebp-14h]
  int v10; // [esp+0h] [ebp-14h]
  int Size; // [esp+4h] [ebp-10h]
  size_t Sizea; // [esp+4h] [ebp-10h]
  size_t Sizeb; // [esp+4h] [ebp-10h]
  size_t Sizec; // [esp+4h] [ebp-10h]
  size_t Sized; // [esp+4h] [ebp-10h]
  size_t Sizee; // [esp+4h] [ebp-10h]
  size_t Sizef; // [esp+4h] [ebp-10h]
  size_t Sizeg; // [esp+4h] [ebp-10h]
  size_t Sizeh; // [esp+4h] [ebp-10h]
  int j; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]

  v2 = this;
  CBuildingInfoMgr::m_bInit = 0;
  Size = &unk_4035560 - &CBuildingInfoMgr::m_vBuildingInfos;
  for ( i = 0; i < 5; ++i )
  {
    for ( j = 0; j < 83; ++j )
    {
      memset((char *)&CBuildingInfoMgr::m_vBuildingInfos + 70384 * i + 848 * j, 0, Size);
      std::vector<unsigned char>::clear(v2, Size);
      std::vector<unsigned int>::clear(v3, Sizea);
      std::vector<unsigned int>::clear(v4, Sizeb);
      std::vector<unsigned int>::clear(v5, Sizec);
      std::vector<unsigned int>::clear(v6, Sized);
      std::vector<unsigned int>::clear(v7, Sizee);
      std::vector<unsigned int>::clear(v8, Sizef);
      std::vector<unsigned int>::clear(v9, Sizeg);
      std::vector<unsigned int>::clear(v10, Sizeh);
    }
  }
  result = memset(&CBuildingInfoMgr::m_vTriggerInfos, 0, 0x210Cu);
  *(_DWORD *)v2 = 0;
  return result;
}


// address=[0x14ec810]
// Decompiled from char *__thiscall CBuildingInfoMgr::ReadBuildingInfo(CBuildingInfoMgr *this)
void  CBuildingInfoMgr::ReadBuildingInfo(void) {
  
  char *result; // eax
  int v2; // eax
  const char *v3; // eax
  int v4; // eax
  int v5; // eax
  const char *v6; // eax
  char v7; // al
  const char *v8; // eax
  char v9; // al
  const char *v10; // eax
  char v11; // al
  const char *v12; // eax
  char v13; // al
  const char *v14; // eax
  char v15; // al
  const char *v16; // eax
  char v17; // al
  const char *v18; // eax
  const char *v19; // eax
  const char *v20; // eax
  const char *v21; // eax
  const char *v22; // eax
  const char *v23; // eax
  const char *v24; // eax
  const char *v25; // eax
  char v26; // al
  const char *v27; // eax
  char v28; // al
  const char *v29; // eax
  char v30; // al
  const char *v31; // eax
  char v32; // al
  const char *v33; // eax
  char v34; // al
  const char *v35; // eax
  char v36; // al
  const char *v37; // eax
  char v38; // al
  const char *v39; // eax
  char v40; // al
  const char *v41; // eax
  char v42; // al
  const char *v43; // eax
  char v44; // al
  const char *v45; // eax
  char v46; // al
  const char *v47; // eax
  char v48; // al
  const char *v49; // eax
  char v50; // al
  const char *v51; // eax
  char v52; // al
  const char *v53; // eax
  char v54; // al
  const char *v55; // eax
  char v56; // al
  const char *v57; // eax
  char v58; // al
  int v59; // eax
  const char *v60; // eax
  char v61; // al
  const char *v62; // eax
  char v63; // al
  const char *v64; // eax
  char v65; // al
  const char *v66; // eax
  int v67; // eax
  const char *v68; // eax
  int v69; // eax
  const char *v70; // eax
  char v71; // al
  const char *v72; // eax
  int v73; // eax
  const char *v74; // eax
  int v75; // eax
  const char *v76; // eax
  char v77; // al
  const char *v78; // eax
  const char *v79; // eax
  const char *v80; // eax
  char v81; // al
  const char *v82; // eax
  int v83; // eax
  const char *v84; // eax
  int v85; // eax
  char *v86; // eax
  char *v87; // eax
  int v88; // eax
  int v89; // eax
  char *v90; // eax
  const char *v91; // eax
  const char *v92; // eax
  int v93; // eax
  const char *v94; // eax
  int v95; // eax
  const char *v96; // eax
  int v97; // eax
  const char *v98; // eax
  int v99; // eax
  char *v100; // eax
  const char *v101; // eax
  int v102; // eax
  const char *v103; // eax
  char v104; // al
  char *v105; // eax
  int v106; // eax
  char *v107; // eax
  int v108; // eax
  const char *v109; // eax
  char *v110; // eax
  char *v111; // eax
  const char *v112; // eax
  char v113; // al
  const char *v114; // eax
  char v115; // al
  int v116; // eax
  const char *v117; // eax
  char v118; // al
  const char *v119; // eax
  char v120; // al
  const char *v121; // eax
  char *v122; // eax
  char *v123; // eax
  int v124; // eax
  char *v125; // eax
  int v126; // eax
  const char *v127; // eax
  char v128; // al
  const char *v129; // eax
  char v130; // al
  char *v131; // eax
  char *v132; // eax
  char *v133; // eax
  int v134; // eax
  const char *v135; // eax
  char v136; // al
  const char *v137; // eax
  char v138; // al
  int v139; // eax
  const char *v140; // eax
  __int16 v141; // ax
  const char *v142; // eax
  __int16 v143; // ax
  const char *v144; // eax
  char v145; // al
  const char *v146; // eax
  char v147; // al
  int v148; // eax
  const char *v149; // eax
  char v150; // al
  const char *v151; // eax
  char v152; // al
  int v153; // [esp-4h] [ebp-1B34h]
  int v154; // [esp-4h] [ebp-1B34h]
  const char *v155; // [esp-4h] [ebp-1B34h]
  int v156; // [esp+0h] [ebp-1B30h] BYREF
  int v157; // [esp+4h] [ebp-1B2Ch]
  _BYTE v158[28]; // [esp+10h] [ebp-1B20h] BYREF
  _BYTE v159[28]; // [esp+2Ch] [ebp-1B04h] BYREF
  _BYTE v160[16]; // [esp+58h] [ebp-1AD8h] BYREF
  _BYTE v161[16]; // [esp+68h] [ebp-1AC8h] BYREF
  _BYTE v162[16]; // [esp+78h] [ebp-1AB8h] BYREF
  _BYTE v163[16]; // [esp+88h] [ebp-1AA8h] BYREF
  _BYTE v164[16]; // [esp+98h] [ebp-1A98h] BYREF
  _BYTE v165[16]; // [esp+B8h] [ebp-1A78h] BYREF
  _BYTE v166[16]; // [esp+C8h] [ebp-1A68h] BYREF
  _BYTE v167[16]; // [esp+D8h] [ebp-1A58h] BYREF
  _BYTE v168[16]; // [esp+E8h] [ebp-1A48h] BYREF
  _BYTE v169[16]; // [esp+F8h] [ebp-1A38h] BYREF
  _BYTE v170[16]; // [esp+108h] [ebp-1A28h] BYREF
  _BYTE v171[16]; // [esp+118h] [ebp-1A18h] BYREF
  _BYTE v172[16]; // [esp+128h] [ebp-1A08h] BYREF
  _BYTE v173[16]; // [esp+138h] [ebp-19F8h] BYREF
  _BYTE v174[16]; // [esp+148h] [ebp-19E8h] BYREF
  _BYTE v175[16]; // [esp+158h] [ebp-19D8h] BYREF
  _BYTE v176[16]; // [esp+168h] [ebp-19C8h] BYREF
  _BYTE v177[16]; // [esp+178h] [ebp-19B8h] BYREF
  _BYTE v178[16]; // [esp+188h] [ebp-19A8h] BYREF
  _BYTE v179[16]; // [esp+198h] [ebp-1998h] BYREF
  _BYTE v180[16]; // [esp+1A8h] [ebp-1988h] BYREF
  void *v181; // [esp+1B8h] [ebp-1978h]
  int v182; // [esp+1BCh] [ebp-1974h]
  int v183; // [esp+1C0h] [ebp-1970h]
  void *v184; // [esp+1C4h] [ebp-196Ch]
  void *v185; // [esp+1C8h] [ebp-1968h]
  int v186; // [esp+1CCh] [ebp-1964h]
  int v187; // [esp+1D0h] [ebp-1960h]
  void *v188; // [esp+1D4h] [ebp-195Ch]
  int v189; // [esp+1D8h] [ebp-1958h]
  int v190; // [esp+1DCh] [ebp-1954h]
  void *v191; // [esp+1E0h] [ebp-1950h]
  void *v192; // [esp+1E4h] [ebp-194Ch]
  void *v193; // [esp+1E8h] [ebp-1948h]
  void *v194; // [esp+1ECh] [ebp-1944h]
  void *v195; // [esp+1F0h] [ebp-1940h]
  int v196; // [esp+1F4h] [ebp-193Ch]
  int v197; // [esp+1F8h] [ebp-1938h]
  int v198; // [esp+1FCh] [ebp-1934h]
  int v199; // [esp+200h] [ebp-1930h]
  int v200; // [esp+204h] [ebp-192Ch]
  int v201; // [esp+208h] [ebp-1928h]
  int v202; // [esp+20Ch] [ebp-1924h]
  void *v203; // [esp+210h] [ebp-1920h]
  void *v204; // [esp+214h] [ebp-191Ch]
  void *v205; // [esp+218h] [ebp-1918h]
  void *v206; // [esp+21Ch] [ebp-1914h]
  int v207; // [esp+220h] [ebp-1910h]
  int v208; // [esp+224h] [ebp-190Ch]
  int v209; // [esp+228h] [ebp-1908h]
  int v210; // [esp+22Ch] [ebp-1904h]
  int v211; // [esp+230h] [ebp-1900h]
  int v212; // [esp+234h] [ebp-18FCh]
  int v213; // [esp+238h] [ebp-18F8h]
  int v214; // [esp+23Ch] [ebp-18F4h]
  void *v215; // [esp+240h] [ebp-18F0h]
  _BYTE v216[16]; // [esp+244h] [ebp-18ECh] BYREF
  _BYTE v217[16]; // [esp+254h] [ebp-18DCh] BYREF
  _BYTE v218[16]; // [esp+264h] [ebp-18CCh] BYREF
  int v219; // [esp+274h] [ebp-18BCh]
  void *v220; // [esp+278h] [ebp-18B8h]
  int v221; // [esp+27Ch] [ebp-18B4h]
  int v222; // [esp+280h] [ebp-18B0h]
  void *v223; // [esp+284h] [ebp-18ACh]
  int v224; // [esp+288h] [ebp-18A8h]
  int v225; // [esp+28Ch] [ebp-18A4h]
  int v226; // [esp+290h] [ebp-18A0h]
  void *v227; // [esp+294h] [ebp-189Ch]
  int v228; // [esp+298h] [ebp-1898h]
  int v229; // [esp+29Ch] [ebp-1894h]
  int v230; // [esp+2A0h] [ebp-1890h]
  void *v231; // [esp+2A4h] [ebp-188Ch]
  int v232; // [esp+2A8h] [ebp-1888h]
  int v233; // [esp+2ACh] [ebp-1884h]
  int v234; // [esp+2B0h] [ebp-1880h]
  CConfigManager *v235; // [esp+2B4h] [ebp-187Ch]
  void *v236; // [esp+2B8h] [ebp-1878h]
  void *v237; // [esp+2BCh] [ebp-1874h]
  int v238; // [esp+2C0h] [ebp-1870h]
  int v239; // [esp+2C4h] [ebp-186Ch]
  int v240; // [esp+2C8h] [ebp-1868h]
  int v241; // [esp+2CCh] [ebp-1864h]
  void *v242; // [esp+2D0h] [ebp-1860h]
  int v243; // [esp+2D4h] [ebp-185Ch]
  int v244; // [esp+2D8h] [ebp-1858h]
  int v245; // [esp+2DCh] [ebp-1854h]
  void *v246; // [esp+2E0h] [ebp-1850h]
  int v247; // [esp+2E4h] [ebp-184Ch]
  int v248; // [esp+2E8h] [ebp-1848h]
  int v249; // [esp+2ECh] [ebp-1844h]
  void *v250; // [esp+2F0h] [ebp-1840h]
  int v251; // [esp+2F4h] [ebp-183Ch]
  int v252; // [esp+2F8h] [ebp-1838h]
  int v253; // [esp+2FCh] [ebp-1834h]
  void *v254; // [esp+300h] [ebp-1830h]
  int v255; // [esp+304h] [ebp-182Ch]
  int v256; // [esp+308h] [ebp-1828h]
  int v257; // [esp+30Ch] [ebp-1824h]
  void *v258; // [esp+310h] [ebp-1820h]
  int v259; // [esp+314h] [ebp-181Ch]
  int v260; // [esp+318h] [ebp-1818h]
  void *v261; // [esp+31Ch] [ebp-1814h]
  int v262; // [esp+320h] [ebp-1810h]
  int v263; // [esp+324h] [ebp-180Ch]
  int v264; // [esp+328h] [ebp-1808h]
  int v265; // [esp+32Ch] [ebp-1804h]
  void *v266; // [esp+330h] [ebp-1800h]
  int v267; // [esp+334h] [ebp-17FCh]
  int v268; // [esp+338h] [ebp-17F8h]
  int v269; // [esp+33Ch] [ebp-17F4h]
  void *v270; // [esp+340h] [ebp-17F0h]
  int v271; // [esp+344h] [ebp-17ECh]
  int v272; // [esp+348h] [ebp-17E8h]
  int v273; // [esp+34Ch] [ebp-17E4h]
  void *v274; // [esp+350h] [ebp-17E0h]
  int v275; // [esp+354h] [ebp-17DCh]
  int v276; // [esp+358h] [ebp-17D8h]
  int v277; // [esp+35Ch] [ebp-17D4h]
  int v278; // [esp+360h] [ebp-17D0h]
  int v279; // [esp+364h] [ebp-17CCh]
  int v280; // [esp+368h] [ebp-17C8h]
  int v281; // [esp+36Ch] [ebp-17C4h]
  int v282; // [esp+370h] [ebp-17C0h]
  void *v283; // [esp+374h] [ebp-17BCh]
  int v284; // [esp+378h] [ebp-17B8h]
  int v285; // [esp+37Ch] [ebp-17B4h]
  int v286; // [esp+380h] [ebp-17B0h]
  void *v287; // [esp+384h] [ebp-17ACh]
  int v288; // [esp+388h] [ebp-17A8h]
  int v289; // [esp+38Ch] [ebp-17A4h]
  int v290; // [esp+390h] [ebp-17A0h]
  void *v291; // [esp+394h] [ebp-179Ch]
  int v292; // [esp+398h] [ebp-1798h]
  int v293; // [esp+39Ch] [ebp-1794h]
  void *v294; // [esp+3A0h] [ebp-1790h]
  void *v295; // [esp+3A4h] [ebp-178Ch]
  int v296; // [esp+3A8h] [ebp-1788h]
  int v297; // [esp+3ACh] [ebp-1784h]
  int v298; // [esp+3B0h] [ebp-1780h]
  int v299; // [esp+3B4h] [ebp-177Ch]
  void *v300; // [esp+3B8h] [ebp-1778h]
  void *v301; // [esp+3BCh] [ebp-1774h]
  CConfigManager *v302; // [esp+3C0h] [ebp-1770h]
  int v303; // [esp+3C4h] [ebp-176Ch]
  int v304; // [esp+3C8h] [ebp-1768h]
  int v305; // [esp+3CCh] [ebp-1764h]
  CConfigManager *v306; // [esp+3D0h] [ebp-1760h]
  void *v307; // [esp+3D4h] [ebp-175Ch]
  void *v308; // [esp+3D8h] [ebp-1758h]
  int v309; // [esp+3DCh] [ebp-1754h]
  int v310; // [esp+3E0h] [ebp-1750h]
  int v311; // [esp+3E4h] [ebp-174Ch]
  int v312; // [esp+3E8h] [ebp-1748h]
  void *v313; // [esp+3ECh] [ebp-1744h]
  void *v314; // [esp+3F0h] [ebp-1740h]
  int v315; // [esp+3F4h] [ebp-173Ch]
  int v316; // [esp+3F8h] [ebp-1738h]
  int v317; // [esp+3FCh] [ebp-1734h]
  void *v318; // [esp+400h] [ebp-1730h]
  int v319; // [esp+404h] [ebp-172Ch]
  int v320; // [esp+408h] [ebp-1728h]
  _BYTE v321[16]; // [esp+40Ch] [ebp-1724h] BYREF
  void *v322; // [esp+41Ch] [ebp-1714h]
  int v323; // [esp+420h] [ebp-1710h]
  void *v324; // [esp+424h] [ebp-170Ch]
  void *v325; // [esp+428h] [ebp-1708h]
  void *v326; // [esp+42Ch] [ebp-1704h]
  int v327; // [esp+430h] [ebp-1700h]
  int v328; // [esp+434h] [ebp-16FCh]
  int v329; // [esp+438h] [ebp-16F8h]
  int v330; // [esp+43Ch] [ebp-16F4h]
  void *v331; // [esp+440h] [ebp-16F0h]
  int v332; // [esp+444h] [ebp-16ECh]
  int v333; // [esp+448h] [ebp-16E8h]
  int v334; // [esp+44Ch] [ebp-16E4h]
  int v335; // [esp+450h] [ebp-16E0h]
  int v336; // [esp+454h] [ebp-16DCh]
  void *v337; // [esp+458h] [ebp-16D8h]
  void *v338; // [esp+45Ch] [ebp-16D4h]
  CConfigManager *v339; // [esp+460h] [ebp-16D0h]
  int v340; // [esp+464h] [ebp-16CCh]
  int v341; // [esp+468h] [ebp-16C8h]
  int v342; // [esp+46Ch] [ebp-16C4h]
  int v343; // [esp+470h] [ebp-16C0h]
  void *v344; // [esp+474h] [ebp-16BCh]
  int v345; // [esp+478h] [ebp-16B8h]
  int v346; // [esp+47Ch] [ebp-16B4h]
  int v347; // [esp+480h] [ebp-16B0h]
  void *v348; // [esp+484h] [ebp-16ACh]
  int v349; // [esp+488h] [ebp-16A8h]
  int v350; // [esp+48Ch] [ebp-16A4h]
  int v351; // [esp+490h] [ebp-16A0h]
  void *v352; // [esp+494h] [ebp-169Ch]
  int v353; // [esp+498h] [ebp-1698h]
  int v354; // [esp+49Ch] [ebp-1694h]
  int v355; // [esp+4A0h] [ebp-1690h]
  void *v356; // [esp+4A4h] [ebp-168Ch]
  int v357; // [esp+4A8h] [ebp-1688h]
  int v358; // [esp+4ACh] [ebp-1684h]
  int v359; // [esp+4B0h] [ebp-1680h]
  int v360; // [esp+4B4h] [ebp-167Ch]
  void *v361; // [esp+4B8h] [ebp-1678h]
  void *v362; // [esp+4BCh] [ebp-1674h]
  CConfigManager *v363; // [esp+4C0h] [ebp-1670h]
  int v364; // [esp+4C4h] [ebp-166Ch]
  int v365; // [esp+4C8h] [ebp-1668h]
  int v366; // [esp+4CCh] [ebp-1664h]
  void *v367; // [esp+4D0h] [ebp-1660h]
  int v368; // [esp+4D4h] [ebp-165Ch]
  int v369; // [esp+4D8h] [ebp-1658h]
  int v370; // [esp+4DCh] [ebp-1654h]
  int v371; // [esp+4E0h] [ebp-1650h]
  void *v372; // [esp+4E4h] [ebp-164Ch]
  int v373; // [esp+4E8h] [ebp-1648h]
  int v374; // [esp+4ECh] [ebp-1644h]
  int v375; // [esp+4F0h] [ebp-1640h]
  int v376; // [esp+4F4h] [ebp-163Ch]
  int v377; // [esp+4F8h] [ebp-1638h]
  CConfigManager *v378; // [esp+4FCh] [ebp-1634h]
  void *v379; // [esp+500h] [ebp-1630h]
  void *v380; // [esp+504h] [ebp-162Ch]
  int v381; // [esp+508h] [ebp-1628h]
  int v382; // [esp+50Ch] [ebp-1624h]
  int v383; // [esp+510h] [ebp-1620h]
  int v384; // [esp+514h] [ebp-161Ch]
  int v385; // [esp+518h] [ebp-1618h]
  int v386; // [esp+51Ch] [ebp-1614h]
  void *v387; // [esp+520h] [ebp-1610h]
  void *v388; // [esp+524h] [ebp-160Ch]
  int v389; // [esp+528h] [ebp-1608h]
  int v390; // [esp+52Ch] [ebp-1604h]
  void *v391; // [esp+530h] [ebp-1600h]
  int v392; // [esp+534h] [ebp-15FCh]
  int v393; // [esp+538h] [ebp-15F8h]
  int v394; // [esp+53Ch] [ebp-15F4h]
  void *v395; // [esp+540h] [ebp-15F0h]
  int v396; // [esp+544h] [ebp-15ECh]
  int v397; // [esp+548h] [ebp-15E8h]
  int v398; // [esp+54Ch] [ebp-15E4h]
  int v399; // [esp+550h] [ebp-15E0h]
  CConfigManager *v400; // [esp+554h] [ebp-15DCh]
  void *v401; // [esp+558h] [ebp-15D8h]
  void *v402; // [esp+55Ch] [ebp-15D4h]
  int v403; // [esp+560h] [ebp-15D0h]
  int v404; // [esp+564h] [ebp-15CCh]
  int v405; // [esp+568h] [ebp-15C8h]
  int v406; // [esp+56Ch] [ebp-15C4h]
  int v407; // [esp+570h] [ebp-15C0h]
  int v408; // [esp+574h] [ebp-15BCh]
  int v409; // [esp+578h] [ebp-15B8h]
  int v410; // [esp+57Ch] [ebp-15B4h]
  int v411; // [esp+580h] [ebp-15B0h]
  int v412; // [esp+584h] [ebp-15ACh]
  int v413; // [esp+588h] [ebp-15A8h]
  int v414; // [esp+58Ch] [ebp-15A4h]
  int v415; // [esp+590h] [ebp-15A0h]
  int v416; // [esp+594h] [ebp-159Ch]
  int v417; // [esp+598h] [ebp-1598h]
  int v418; // [esp+59Ch] [ebp-1594h]
  int v419; // [esp+5A0h] [ebp-1590h]
  int v420; // [esp+5A4h] [ebp-158Ch]
  int v421; // [esp+5A8h] [ebp-1588h]
  int v422; // [esp+5ACh] [ebp-1584h]
  int v423; // [esp+5B0h] [ebp-1580h]
  int v424; // [esp+5B4h] [ebp-157Ch]
  int v425; // [esp+5B8h] [ebp-1578h]
  struct Document *v426; // [esp+5BCh] [ebp-1574h]
  void *C; // [esp+5C0h] [ebp-1570h]
  int v428; // [esp+5C4h] [ebp-156Ch]
  const char *RaceName; // [esp+5C8h] [ebp-1568h]
  int v430; // [esp+5CCh] [ebp-1564h]
  signed int v431; // [esp+5D0h] [ebp-1560h]
  int v432; // [esp+5D4h] [ebp-155Ch]
  Grid *v433; // [esp+5D8h] [ebp-1558h]
  int v434; // [esp+5DCh] [ebp-1554h]
  int *v435; // [esp+5E0h] [ebp-1550h]
  int v436; // [esp+5E4h] [ebp-154Ch]
  int v437; // [esp+5E8h] [ebp-1548h]
  int v438; // [esp+5ECh] [ebp-1544h]
  int v439; // [esp+5F0h] [ebp-1540h]
  int v440; // [esp+5F4h] [ebp-153Ch]
  void *v441; // [esp+5F8h] [ebp-1538h]
  void *v442; // [esp+5FCh] [ebp-1534h]
  int v443; // [esp+600h] [ebp-1530h]
  int v444; // [esp+604h] [ebp-152Ch]
  void *v445; // [esp+608h] [ebp-1528h]
  int v446; // [esp+60Ch] [ebp-1524h]
  int v447; // [esp+610h] [ebp-1520h]
  int v448; // [esp+614h] [ebp-151Ch]
  int v449; // [esp+618h] [ebp-1518h]
  int v450; // [esp+61Ch] [ebp-1514h]
  int v451; // [esp+620h] [ebp-1510h]
  int v452; // [esp+624h] [ebp-150Ch]
  int v453; // [esp+628h] [ebp-1508h]
  int v454; // [esp+62Ch] [ebp-1504h]
  int v455; // [esp+630h] [ebp-1500h]
  void *v456; // [esp+634h] [ebp-14FCh]
  int v457; // [esp+638h] [ebp-14F8h]
  int v458; // [esp+63Ch] [ebp-14F4h]
  int v459; // [esp+640h] [ebp-14F0h]
  void *v460; // [esp+644h] [ebp-14ECh]
  int v461; // [esp+648h] [ebp-14E8h]
  int v462; // [esp+64Ch] [ebp-14E4h]
  int v463; // [esp+650h] [ebp-14E0h]
  int v464; // [esp+654h] [ebp-14DCh]
  void *v465; // [esp+658h] [ebp-14D8h]
  void *v466; // [esp+65Ch] [ebp-14D4h]
  CConfigManager *v467; // [esp+660h] [ebp-14D0h]
  int v468; // [esp+664h] [ebp-14CCh]
  int v469; // [esp+668h] [ebp-14C8h]
  int v470; // [esp+66Ch] [ebp-14C4h]
  void *v471; // [esp+670h] [ebp-14C0h]
  int v472; // [esp+674h] [ebp-14BCh]
  int v473; // [esp+678h] [ebp-14B8h]
  void *v474; // [esp+67Ch] [ebp-14B4h]
  int v475; // [esp+680h] [ebp-14B0h]
  int v476; // [esp+684h] [ebp-14ACh]
  int v477; // [esp+688h] [ebp-14A8h]
  int v478; // [esp+68Ch] [ebp-14A4h]
  void *v479; // [esp+690h] [ebp-14A0h]
  void *v480; // [esp+694h] [ebp-149Ch]
  int v481; // [esp+698h] [ebp-1498h]
  int v482; // [esp+69Ch] [ebp-1494h]
  int v483; // [esp+6A0h] [ebp-1490h]
  int v484; // [esp+6A4h] [ebp-148Ch]
  void *v485; // [esp+6A8h] [ebp-1488h]
  void *v486; // [esp+6ACh] [ebp-1484h]
  CConfigManager *v487; // [esp+6B0h] [ebp-1480h]
  int v488; // [esp+6B4h] [ebp-147Ch]
  int v489; // [esp+6B8h] [ebp-1478h]
  int v490; // [esp+6BCh] [ebp-1474h]
  void *v491; // [esp+6C0h] [ebp-1470h]
  void *v492; // [esp+6C4h] [ebp-146Ch]
  int v493; // [esp+6C8h] [ebp-1468h]
  int v494; // [esp+6CCh] [ebp-1464h]
  int v495; // [esp+6D0h] [ebp-1460h]
  int v496; // [esp+6D4h] [ebp-145Ch]
  int v497; // [esp+6D8h] [ebp-1458h]
  int v498; // [esp+6DCh] [ebp-1454h]
  int v499; // [esp+6E0h] [ebp-1450h]
  int v500; // [esp+6E4h] [ebp-144Ch]
  int v501; // [esp+6E8h] [ebp-1448h]
  int v502; // [esp+6ECh] [ebp-1444h]
  int v503; // [esp+6F0h] [ebp-1440h]
  int v504; // [esp+6F4h] [ebp-143Ch]
  CConfigManager *v505; // [esp+6F8h] [ebp-1438h]
  void *v506; // [esp+6FCh] [ebp-1434h]
  void *v507; // [esp+700h] [ebp-1430h]
  int v508; // [esp+704h] [ebp-142Ch]
  int v509; // [esp+708h] [ebp-1428h]
  int v510; // [esp+70Ch] [ebp-1424h]
  int v511; // [esp+710h] [ebp-1420h]
  int v512; // [esp+714h] [ebp-141Ch]
  int v513; // [esp+718h] [ebp-1418h]
  int v514; // [esp+71Ch] [ebp-1414h]
  int v515; // [esp+720h] [ebp-1410h]
  int v516; // [esp+724h] [ebp-140Ch]
  int v517; // [esp+728h] [ebp-1408h]
  int v518; // [esp+72Ch] [ebp-1404h]
  int v519; // [esp+730h] [ebp-1400h]
  int v520; // [esp+734h] [ebp-13FCh]
  void *v521; // [esp+738h] [ebp-13F8h]
  int v522; // [esp+73Ch] [ebp-13F4h]
  int v523; // [esp+740h] [ebp-13F0h]
  void *v524; // [esp+744h] [ebp-13ECh]
  int v525; // [esp+748h] [ebp-13E8h]
  int v526; // [esp+74Ch] [ebp-13E4h]
  int v527; // [esp+750h] [ebp-13E0h]
  int v528; // [esp+754h] [ebp-13DCh]
  void *v529; // [esp+758h] [ebp-13D8h]
  void *v530; // [esp+75Ch] [ebp-13D4h]
  int v531; // [esp+760h] [ebp-13D0h]
  int v532; // [esp+764h] [ebp-13CCh]
  void *v533; // [esp+768h] [ebp-13C8h]
  int v534; // [esp+76Ch] [ebp-13C4h]
  int v535; // [esp+770h] [ebp-13C0h]
  int v536; // [esp+774h] [ebp-13BCh]
  int v537; // [esp+778h] [ebp-13B8h]
  void *v538; // [esp+77Ch] [ebp-13B4h]
  int v539; // [esp+780h] [ebp-13B0h]
  int v540; // [esp+784h] [ebp-13ACh]
  int v541; // [esp+788h] [ebp-13A8h]
  void *v542; // [esp+78Ch] [ebp-13A4h]
  int v543; // [esp+790h] [ebp-13A0h]
  int v544; // [esp+794h] [ebp-139Ch]
  int v545; // [esp+798h] [ebp-1398h]
  void *v546; // [esp+79Ch] [ebp-1394h]
  int v547; // [esp+7A0h] [ebp-1390h]
  int v548; // [esp+7A4h] [ebp-138Ch]
  int v549; // [esp+7A8h] [ebp-1388h]
  void *v550; // [esp+7ACh] [ebp-1384h]
  int v551; // [esp+7B0h] [ebp-1380h]
  int v552; // [esp+7B4h] [ebp-137Ch]
  int v553; // [esp+7B8h] [ebp-1378h]
  void *v554; // [esp+7BCh] [ebp-1374h]
  int v555; // [esp+7C0h] [ebp-1370h]
  int v556; // [esp+7C4h] [ebp-136Ch]
  int v557; // [esp+7C8h] [ebp-1368h]
  void *v558; // [esp+7CCh] [ebp-1364h]
  int v559; // [esp+7D0h] [ebp-1360h]
  int v560; // [esp+7D4h] [ebp-135Ch]
  int v561; // [esp+7D8h] [ebp-1358h]
  void *v562; // [esp+7DCh] [ebp-1354h]
  int v563; // [esp+7E0h] [ebp-1350h]
  int v564; // [esp+7E4h] [ebp-134Ch]
  int v565; // [esp+7E8h] [ebp-1348h]
  void *v566; // [esp+7ECh] [ebp-1344h]
  int v567; // [esp+7F0h] [ebp-1340h]
  int v568; // [esp+7F4h] [ebp-133Ch]
  int v569; // [esp+7F8h] [ebp-1338h]
  void *v570; // [esp+7FCh] [ebp-1334h]
  int v571; // [esp+800h] [ebp-1330h]
  int v572; // [esp+804h] [ebp-132Ch]
  int v573; // [esp+808h] [ebp-1328h]
  void *v574; // [esp+80Ch] [ebp-1324h]
  int v575; // [esp+810h] [ebp-1320h]
  int v576; // [esp+814h] [ebp-131Ch]
  int v577; // [esp+818h] [ebp-1318h]
  void *v578; // [esp+81Ch] [ebp-1314h]
  int v579; // [esp+820h] [ebp-1310h]
  int v580; // [esp+824h] [ebp-130Ch]
  int v581; // [esp+828h] [ebp-1308h]
  void *v582; // [esp+82Ch] [ebp-1304h]
  int v583; // [esp+830h] [ebp-1300h]
  int v584; // [esp+834h] [ebp-12FCh]
  int v585; // [esp+838h] [ebp-12F8h]
  void *v586; // [esp+83Ch] [ebp-12F4h]
  int v587; // [esp+840h] [ebp-12F0h]
  int v588; // [esp+844h] [ebp-12ECh]
  int v589; // [esp+848h] [ebp-12E8h] BYREF
  int v590; // [esp+84Ch] [ebp-12E4h]
  void *v591; // [esp+850h] [ebp-12E0h]
  int v592; // [esp+854h] [ebp-12DCh]
  int v593; // [esp+858h] [ebp-12D8h]
  int v594; // [esp+85Ch] [ebp-12D4h]
  int v595; // [esp+860h] [ebp-12D0h] BYREF
  int v596; // [esp+864h] [ebp-12CCh] BYREF
  void *v597; // [esp+868h] [ebp-12C8h]
  int v598; // [esp+86Ch] [ebp-12C4h]
  int v599; // [esp+870h] [ebp-12C0h]
  int v600; // [esp+874h] [ebp-12BCh]
  int v601; // [esp+878h] [ebp-12B8h] BYREF
  void *v602; // [esp+87Ch] [ebp-12B4h]
  int v603; // [esp+880h] [ebp-12B0h]
  int v604; // [esp+884h] [ebp-12ACh]
  int v605; // [esp+888h] [ebp-12A8h]
  int v606; // [esp+88Ch] [ebp-12A4h] BYREF
  void *v607; // [esp+890h] [ebp-12A0h]
  int v608; // [esp+894h] [ebp-129Ch]
  int v609; // [esp+898h] [ebp-1298h]
  int v610; // [esp+89Ch] [ebp-1294h]
  int v611; // [esp+8A0h] [ebp-1290h] BYREF
  void *v612; // [esp+8A4h] [ebp-128Ch]
  int v613; // [esp+8A8h] [ebp-1288h]
  int v614; // [esp+8ACh] [ebp-1284h]
  int v615; // [esp+8B0h] [ebp-1280h]
  int v616; // [esp+8B4h] [ebp-127Ch] BYREF
  void *v617; // [esp+8B8h] [ebp-1278h]
  int v618; // [esp+8BCh] [ebp-1274h]
  int v619; // [esp+8C0h] [ebp-1270h]
  int v620; // [esp+8C4h] [ebp-126Ch]
  int v621; // [esp+8C8h] [ebp-1268h] BYREF
  void *v622; // [esp+8CCh] [ebp-1264h]
  int v623; // [esp+8D0h] [ebp-1260h]
  int v624; // [esp+8D4h] [ebp-125Ch]
  int v625; // [esp+8D8h] [ebp-1258h]
  void *v626; // [esp+8DCh] [ebp-1254h]
  int v627; // [esp+8E0h] [ebp-1250h]
  int v628; // [esp+8E4h] [ebp-124Ch]
  void *v629; // [esp+8E8h] [ebp-1248h]
  int v630; // [esp+8ECh] [ebp-1244h]
  int v631; // [esp+8F0h] [ebp-1240h]
  void *v632; // [esp+8F4h] [ebp-123Ch]
  int v633; // [esp+8F8h] [ebp-1238h]
  int v634; // [esp+8FCh] [ebp-1234h]
  void *v635; // [esp+900h] [ebp-1230h]
  int v636; // [esp+904h] [ebp-122Ch]
  int v637; // [esp+908h] [ebp-1228h]
  void *v638; // [esp+90Ch] [ebp-1224h]
  int v639; // [esp+910h] [ebp-1220h]
  int v640; // [esp+914h] [ebp-121Ch]
  void *v641; // [esp+918h] [ebp-1218h]
  int v642; // [esp+91Ch] [ebp-1214h]
  int v643; // [esp+920h] [ebp-1210h]
  int v644; // [esp+924h] [ebp-120Ch]
  int v645; // [esp+928h] [ebp-1208h]
  CConfigManager *Instance; // [esp+92Ch] [ebp-1204h]
  int v647; // [esp+930h] [ebp-1200h]
  int v648; // [esp+934h] [ebp-11FCh]
  int v649; // [esp+938h] [ebp-11F8h]
  int v650; // [esp+93Ch] [ebp-11F4h]
  int v651; // [esp+940h] [ebp-11F0h]
  int v652; // [esp+944h] [ebp-11ECh]
  int v653; // [esp+948h] [ebp-11E8h]
  int v654; // [esp+94Ch] [ebp-11E4h]
  int v655; // [esp+950h] [ebp-11E0h]
  int ValueOfDefine; // [esp+954h] [ebp-11DCh]
  int v657; // [esp+958h] [ebp-11D8h]
  int v658; // [esp+95Ch] [ebp-11D4h]
  int v659; // [esp+960h] [ebp-11D0h]
  void *v660; // [esp+964h] [ebp-11CCh]
  int Name; // [esp+968h] [ebp-11C8h]
  int v662; // [esp+96Ch] [ebp-11C4h]
  int v663; // [esp+970h] [ebp-11C0h]
  int v664; // [esp+974h] [ebp-11BCh]
  int v665; // [esp+978h] [ebp-11B8h]
  int v666; // [esp+97Ch] [ebp-11B4h]
  int v667; // [esp+980h] [ebp-11B0h]
  int Root; // [esp+984h] [ebp-11ACh]
  struct Document *v669; // [esp+988h] [ebp-11A8h]
  _BYTE v670[16]; // [esp+98Ch] [ebp-11A4h] BYREF
  int v671; // [esp+99Ch] [ebp-1194h]
  _BYTE v672[4]; // [esp+9A0h] [ebp-1190h] BYREF
  int v673; // [esp+9A4h] [ebp-118Ch]
  int v674; // [esp+9A8h] [ebp-1188h]
  CConfigManager *v675; // [esp+9ACh] [ebp-1184h]
  int v676; // [esp+9B0h] [ebp-1180h]
  int v677; // [esp+9B4h] [ebp-117Ch]
  int v678; // [esp+9B8h] [ebp-1178h]
  int v679; // [esp+9BCh] [ebp-1174h]
  int v680; // [esp+9C0h] [ebp-1170h]
  CConfigManager *v681; // [esp+9C4h] [ebp-116Ch]
  int v682; // [esp+9C8h] [ebp-1168h]
  int v683; // [esp+9CCh] [ebp-1164h]
  int v684; // [esp+9D0h] [ebp-1160h]
  CConfigManager *v685; // [esp+9D4h] [ebp-115Ch]
  int v686; // [esp+9D8h] [ebp-1158h]
  int v687; // [esp+9DCh] [ebp-1154h]
  int v688; // [esp+9E0h] [ebp-1150h]
  int v689; // [esp+9E4h] [ebp-114Ch]
  CConfigManager *v690; // [esp+9E8h] [ebp-1148h]
  int v691; // [esp+9ECh] [ebp-1144h]
  int v692; // [esp+9F0h] [ebp-1140h]
  int v693; // [esp+9F4h] [ebp-113Ch]
  int v694; // [esp+9F8h] [ebp-1138h]
  int v695; // [esp+9FCh] [ebp-1134h]
  _BYTE v696[4]; // [esp+A00h] [ebp-1130h] BYREF
  CBuildingInfoMgr *v697; // [esp+A04h] [ebp-112Ch]
  unsigned int v698; // [esp+A08h] [ebp-1128h]
  int v699; // [esp+A0Ch] [ebp-1124h]
  int v700; // [esp+A10h] [ebp-1120h]
  int v701; // [esp+A14h] [ebp-111Ch]
  int v702; // [esp+A18h] [ebp-1118h]
  CConfigManager *v703; // [esp+A1Ch] [ebp-1114h]
  int v704; // [esp+A20h] [ebp-1110h]
  int v705; // [esp+A24h] [ebp-110Ch]
  int v706; // [esp+A28h] [ebp-1108h]
  int v707; // [esp+A2Ch] [ebp-1104h]
  const char *v708; // [esp+A30h] [ebp-1100h]
  CConfigManager *v709; // [esp+A34h] [ebp-10FCh]
  int v710; // [esp+A38h] [ebp-10F8h]
  int v711; // [esp+A3Ch] [ebp-10F4h]
  CConfigManager *v712; // [esp+A40h] [ebp-10F0h]
  int v713; // [esp+A44h] [ebp-10ECh]
  int v714; // [esp+A48h] [ebp-10E8h]
  int v715; // [esp+A4Ch] [ebp-10E4h]
  int v716; // [esp+A50h] [ebp-10E0h]
  int v717; // [esp+A54h] [ebp-10DCh]
  int v718; // [esp+A58h] [ebp-10D8h]
  int v719; // [esp+A5Ch] [ebp-10D4h]
  int v720; // [esp+A60h] [ebp-10D0h]
  int v721; // [esp+A64h] [ebp-10CCh]
  int v722; // [esp+A68h] [ebp-10C8h]
  CConfigManager *v723; // [esp+A6Ch] [ebp-10C4h]
  int v724; // [esp+A70h] [ebp-10C0h]
  CConfigManager *v725; // [esp+A74h] [ebp-10BCh]
  int v726; // [esp+A78h] [ebp-10B8h]
  int v727; // [esp+A7Ch] [ebp-10B4h]
  int v728; // [esp+A80h] [ebp-10B0h]
  int v729; // [esp+A84h] [ebp-10ACh]
  int v730; // [esp+A88h] [ebp-10A8h]
  int v731; // [esp+A8Ch] [ebp-10A4h]
  BOOL v732; // [esp+A90h] [ebp-10A0h]
  int v733; // [esp+A94h] [ebp-109Ch]
  int v734; // [esp+A98h] [ebp-1098h]
  int v735; // [esp+A9Ch] [ebp-1094h]
  int v736; // [esp+AA0h] [ebp-1090h]
  int v737; // [esp+AA4h] [ebp-108Ch]
  int v738; // [esp+AA8h] [ebp-1088h]
  int v739; // [esp+AACh] [ebp-1084h]
  int v740; // [esp+AB0h] [ebp-1080h]
  int v741; // [esp+AB4h] [ebp-107Ch]
  int v742; // [esp+AB8h] [ebp-1078h]
  CConfigManager *v743; // [esp+ABCh] [ebp-1074h]
  int v744; // [esp+AC0h] [ebp-1070h]
  int v745; // [esp+AC4h] [ebp-106Ch]
  int v746; // [esp+AC8h] [ebp-1068h]
  int v747; // [esp+ACCh] [ebp-1064h]
  int v748; // [esp+AD0h] [ebp-1060h]
  int v749; // [esp+AD4h] [ebp-105Ch]
  int v750; // [esp+AD8h] [ebp-1058h]
  int v751; // [esp+ADCh] [ebp-1054h]
  int v752; // [esp+AE0h] [ebp-1050h]
  int v753; // [esp+AE4h] [ebp-104Ch]
  int v754; // [esp+AE8h] [ebp-1048h]
  int v755; // [esp+AECh] [ebp-1044h]
  int v756; // [esp+AF0h] [ebp-1040h]
  int v757; // [esp+AF4h] [ebp-103Ch]
  int v758; // [esp+AF8h] [ebp-1038h]
  int v759; // [esp+AFCh] [ebp-1034h]
  int v760; // [esp+B00h] [ebp-1030h]
  int v761; // [esp+B04h] [ebp-102Ch]
  int v762; // [esp+B08h] [ebp-1028h]
  int v763; // [esp+B0Ch] [ebp-1024h]
  int v764; // [esp+B10h] [ebp-1020h]
  int v765; // [esp+B14h] [ebp-101Ch]
  int v766; // [esp+B18h] [ebp-1018h]
  int v767; // [esp+B1Ch] [ebp-1014h]
  int v768; // [esp+B20h] [ebp-1010h]
  int v769; // [esp+B24h] [ebp-100Ch]
  int v770; // [esp+B28h] [ebp-1008h]
  int v771; // [esp+B2Ch] [ebp-1004h]
  int v772; // [esp+B30h] [ebp-1000h]
  int v773; // [esp+B34h] [ebp-FFCh]
  int v774; // [esp+B38h] [ebp-FF8h]
  int v775; // [esp+B3Ch] [ebp-FF4h]
  int v776; // [esp+B40h] [ebp-FF0h]
  CConfigManager *v777; // [esp+B44h] [ebp-FECh]
  int v778; // [esp+B48h] [ebp-FE8h]
  int v779; // [esp+B4Ch] [ebp-FE4h]
  int v780; // [esp+B50h] [ebp-FE0h]
  Grid *v781; // [esp+B54h] [ebp-FDCh]
  int v782; // [esp+B58h] [ebp-FD8h]
  int v783; // [esp+B5Ch] [ebp-FD4h]
  _BYTE v784[16]; // [esp+B60h] [ebp-FD0h] BYREF
  int v785; // [esp+B70h] [ebp-FC0h]
  int v786; // [esp+B74h] [ebp-FBCh]
  int v787; // [esp+B78h] [ebp-FB8h] BYREF
  unsigned int v788; // [esp+B7Ch] [ebp-FB4h]
  int jj; // [esp+B80h] [ebp-FB0h]
  int ii; // [esp+B84h] [ebp-FACh]
  int v791; // [esp+B88h] [ebp-FA8h]
  int j; // [esp+B8Ch] [ebp-FA4h]
  int i; // [esp+B90h] [ebp-FA0h]
  char *v795; // [esp+B98h] [ebp-F98h]
  int v796; // [esp+B9Ch] [ebp-F94h]
  int v797; // [esp+BA0h] [ebp-F90h]
  char v803; // [esp+BA9h] [ebp-F87h] BYREF
  bool IsPort; // [esp+BACh] [ebp-F84h]
  bool IsShipyard; // [esp+BADh] [ebp-F83h]
  int k; // [esp+BB0h] [ebp-F80h]
  int v811; // [esp+BB4h] [ebp-F7Ch]
  int v812; // [esp+BB8h] [ebp-F78h]
  int n; // [esp+BBCh] [ebp-F74h]
  _BYTE v814[16]; // [esp+BC0h] [ebp-F70h] BYREF
  int m; // [esp+BD0h] [ebp-F60h]
  char *v816; // [esp+BD4h] [ebp-F5Ch]
  char *v817; // [esp+BD8h] [ebp-F58h]
  _BYTE v818[28]; // [esp+102Ch] [ebp-B04h] BYREF
  _BYTE v819[28]; // [esp+1048h] [ebp-AE8h] BYREF
  _BYTE v820[28]; // [esp+1064h] [ebp-ACCh] BYREF
  _BYTE v821[28]; // [esp+1080h] [ebp-AB0h] BYREF
  _BYTE v822[28]; // [esp+109Ch] [ebp-A94h] BYREF
  _BYTE v823[28]; // [esp+10B8h] [ebp-A78h] BYREF
  _BYTE v824[28]; // [esp+10D4h] [ebp-A5Ch] BYREF
  _BYTE v825[28]; // [esp+10F0h] [ebp-A40h] BYREF
  _BYTE v826[28]; // [esp+110Ch] [ebp-A24h] BYREF
  _BYTE v827[28]; // [esp+1128h] [ebp-A08h] BYREF
  _BYTE v828[28]; // [esp+1144h] [ebp-9ECh] BYREF
  _BYTE v829[28]; // [esp+1160h] [ebp-9D0h] BYREF
  _BYTE v830[28]; // [esp+117Ch] [ebp-9B4h] BYREF
  _BYTE v831[28]; // [esp+1198h] [ebp-998h] BYREF
  _BYTE v832[28]; // [esp+11B4h] [ebp-97Ch] BYREF
  _BYTE v833[28]; // [esp+11D0h] [ebp-960h] BYREF
  _BYTE v834[28]; // [esp+11ECh] [ebp-944h] BYREF
  _BYTE v835[28]; // [esp+1208h] [ebp-928h] BYREF
  _BYTE v836[28]; // [esp+1224h] [ebp-90Ch] BYREF
  _BYTE v837[28]; // [esp+1240h] [ebp-8F0h] BYREF
  _BYTE v838[28]; // [esp+125Ch] [ebp-8D4h] BYREF
  _BYTE v839[28]; // [esp+1278h] [ebp-8B8h] BYREF
  _BYTE v840[28]; // [esp+1294h] [ebp-89Ch] BYREF
  _BYTE v841[28]; // [esp+12B0h] [ebp-880h] BYREF
  _BYTE v842[28]; // [esp+12CCh] [ebp-864h] BYREF
  _BYTE v843[28]; // [esp+12E8h] [ebp-848h] BYREF
  _BYTE v844[28]; // [esp+1304h] [ebp-82Ch] BYREF
  _BYTE v845[28]; // [esp+1320h] [ebp-810h] BYREF
  _BYTE v846[28]; // [esp+133Ch] [ebp-7F4h] BYREF
  _BYTE v847[28]; // [esp+1358h] [ebp-7D8h] BYREF
  _BYTE v848[28]; // [esp+1374h] [ebp-7BCh] BYREF
  _BYTE v849[28]; // [esp+1390h] [ebp-7A0h] BYREF
  _BYTE v850[28]; // [esp+13ACh] [ebp-784h] BYREF
  _BYTE v851[28]; // [esp+13C8h] [ebp-768h] BYREF
  _BYTE v852[28]; // [esp+13E4h] [ebp-74Ch] BYREF
  _BYTE v853[28]; // [esp+1400h] [ebp-730h] BYREF
  _BYTE v854[28]; // [esp+141Ch] [ebp-714h] BYREF
  _BYTE v855[28]; // [esp+1438h] [ebp-6F8h] BYREF
  _BYTE v856[28]; // [esp+1454h] [ebp-6DCh] BYREF
  _BYTE v857[28]; // [esp+1470h] [ebp-6C0h] BYREF
  _BYTE v858[28]; // [esp+148Ch] [ebp-6A4h] BYREF
  _BYTE v859[28]; // [esp+14A8h] [ebp-688h] BYREF
  _BYTE v860[28]; // [esp+14C4h] [ebp-66Ch] BYREF
  _BYTE v861[28]; // [esp+14E0h] [ebp-650h] BYREF
  _BYTE v862[28]; // [esp+14FCh] [ebp-634h] BYREF
  _BYTE v863[28]; // [esp+1518h] [ebp-618h] BYREF
  _BYTE v864[28]; // [esp+1534h] [ebp-5FCh] BYREF
  _BYTE v865[28]; // [esp+1550h] [ebp-5E0h] BYREF
  _BYTE v866[28]; // [esp+156Ch] [ebp-5C4h] BYREF
  _BYTE v867[28]; // [esp+1588h] [ebp-5A8h] BYREF
  _BYTE v868[28]; // [esp+15A4h] [ebp-58Ch] BYREF
  _BYTE v869[28]; // [esp+15C0h] [ebp-570h] BYREF
  _BYTE v870[28]; // [esp+15DCh] [ebp-554h] BYREF
  _BYTE v871[28]; // [esp+15F8h] [ebp-538h] BYREF
  _BYTE v872[28]; // [esp+1614h] [ebp-51Ch] BYREF
  _BYTE v873[28]; // [esp+1630h] [ebp-500h] BYREF
  _BYTE v874[28]; // [esp+164Ch] [ebp-4E4h] BYREF
  _BYTE v875[28]; // [esp+1668h] [ebp-4C8h] BYREF
  _BYTE v876[28]; // [esp+1684h] [ebp-4ACh] BYREF
  _BYTE v877[28]; // [esp+16A0h] [ebp-490h] BYREF
  _BYTE v878[28]; // [esp+16BCh] [ebp-474h] BYREF
  _BYTE v879[28]; // [esp+16D8h] [ebp-458h] BYREF
  _BYTE v880[28]; // [esp+16F4h] [ebp-43Ch] BYREF
  _BYTE v881[28]; // [esp+1710h] [ebp-420h] BYREF
  _BYTE v882[28]; // [esp+172Ch] [ebp-404h] BYREF
  _BYTE v883[28]; // [esp+1748h] [ebp-3E8h] BYREF
  _BYTE v884[28]; // [esp+1764h] [ebp-3CCh] BYREF
  _BYTE v885[28]; // [esp+1780h] [ebp-3B0h] BYREF
  _BYTE v886[28]; // [esp+179Ch] [ebp-394h] BYREF
  _BYTE v887[28]; // [esp+17B8h] [ebp-378h] BYREF
  _BYTE v888[28]; // [esp+17D4h] [ebp-35Ch] BYREF
  _BYTE v889[28]; // [esp+17F0h] [ebp-340h] BYREF
  _BYTE v890[28]; // [esp+180Ch] [ebp-324h] BYREF
  _BYTE v891[28]; // [esp+1828h] [ebp-308h] BYREF
  _BYTE v892[28]; // [esp+1844h] [ebp-2ECh] BYREF
  _BYTE v893[28]; // [esp+1860h] [ebp-2D0h] BYREF
  _BYTE v894[28]; // [esp+187Ch] [ebp-2B4h] BYREF
  _BYTE v895[28]; // [esp+1898h] [ebp-298h] BYREF
  _BYTE v896[28]; // [esp+18B4h] [ebp-27Ch] BYREF
  _BYTE v897[28]; // [esp+18D0h] [ebp-260h] BYREF
  _BYTE v898[28]; // [esp+18ECh] [ebp-244h] BYREF
  _BYTE v899[28]; // [esp+1908h] [ebp-228h] BYREF
  _BYTE v900[28]; // [esp+1924h] [ebp-20Ch] BYREF
  _BYTE v901[28]; // [esp+1940h] [ebp-1F0h] BYREF
  _BYTE v902[28]; // [esp+195Ch] [ebp-1D4h] BYREF
  _BYTE v903[28]; // [esp+1978h] [ebp-1B8h] BYREF
  _BYTE v904[28]; // [esp+1994h] [ebp-19Ch] BYREF
  _BYTE v905[28]; // [esp+19B0h] [ebp-180h] BYREF
  _BYTE v906[28]; // [esp+19CCh] [ebp-164h] BYREF
  _BYTE v907[28]; // [esp+19E8h] [ebp-148h] BYREF
  _BYTE v908[28]; // [esp+1A04h] [ebp-12Ch] BYREF
  _BYTE v909[28]; // [esp+1A20h] [ebp-110h] BYREF
  _BYTE v910[28]; // [esp+1A3Ch] [ebp-F4h] BYREF
  _BYTE v911[28]; // [esp+1A58h] [ebp-D8h] BYREF
  _BYTE v912[28]; // [esp+1A74h] [ebp-BCh] BYREF
  _BYTE v913[28]; // [esp+1A90h] [ebp-A0h] BYREF
  int v914[7]; // [esp+1AACh] [ebp-84h] BYREF
  _BYTE v915[28]; // [esp+1AC8h] [ebp-68h] BYREF
  _BYTE v916[28]; // [esp+1AE4h] [ebp-4Ch] BYREF
  _BYTE v917[28]; // [esp+1B00h] [ebp-30h] BYREF
  int *v918; // [esp+1B20h] [ebp-10h]
  int v919; // [esp+1B2Ch] [ebp-4h]

  v918 = &v156;
  v697 = this;
  v787 = 0;
  result = AdvXMLParser::Parser::OpenXMLFile(aGamedataBuildi, &v787);
  v795 = result;
  if ( !result )
    return result;
  v919 = 0;
  v202 = AdvXMLParser::Parser::Parser(v158);
  LOBYTE(v919) = 1;
  v669 = AdvXMLParser::Parser::Parse((AdvXMLParser::Parser *)v158, v795, v787);
  std::auto_ptr<AdvXMLParser::Document>::auto_ptr<AdvXMLParser::Document>(v669);
  LOBYTE(v919) = 2;
  v2 = std::auto_ptr<AdvXMLParser::Document>::operator->(v156, v157);
  Root = AdvXMLParser::Document::GetRoot(v2);
  v780 = Root;
  v667 = CDefineTranslator::Instance();
  v657 = v667;
  v666 = AdvXMLParser::NodeContainer::Begin(v780, v173);
  v665 = v666;
  LOBYTE(v919) = 3;
  v201 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v666);
  LOBYTE(v919) = 5;
  AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v173);
  v664 = AdvXMLParser::NodeContainer::End(v780, v172);
  v663 = v664;
  LOBYTE(v919) = 6;
  v198 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v664);
  LOBYTE(v919) = 8;
  AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v172);
  while ( (unsigned __int8)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v178) )
  {
    v662 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v321);
    v783 = v662;
    Name = AdvXMLParser::Node::GetName(v662);
    if ( std::operator==<char>(Name, "BuildingXMLVersion") )
    {
      v660 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v783 + 8))(v783, v849);
      v3 = (const char *)std::string::c_str(v660);
      v4 = j__atoi(v3);
      *(_DWORD *)v697 = v4;
      std::string::~string(v849);
    }
    else
    {
      v659 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v321);
      v658 = AdvXMLParser::Element::operator[]("id");
      v779 = v658;
      v200 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v658 + 8))(v658, v915);
      LOBYTE(v919) = 9;
      if ( std::string::length(v915) )
      {
        ValueOfDefine = CDefineTranslator::GetValueOfDefine(v915);
        v791 = ValueOfDefine;
        v655 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v321);
        v654 = AdvXMLParser::NodeContainer::Begin(v655, v162);
        v653 = v654;
        LOBYTE(v919) = 10;
        v199 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v654);
        LOBYTE(v919) = 12;
        AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v162);
        v652 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v321);
        v651 = AdvXMLParser::NodeContainer::End(v652, v171);
        v650 = v651;
        LOBYTE(v919) = 13;
        v197 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v651);
        LOBYTE(v919) = 15;
        AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v171);
        while ( (unsigned __int8)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v179) )
        {
          v649 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
          v648 = AdvXMLParser::Element::operator[]("id");
          v778 = v648;
          v196 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v648 + 8))(v648, v917);
          LOBYTE(v919) = 16;
          if ( !std::string::length(v917) )
          {
            v647 = BBSupportDbgReport(
                     2,
                     "MapObjects\\Building\\BuildingInfoMgr.cpp",
                     609,
                     "strBuildingName.length() > 0");
            if ( v647 == 1 )
              __debugbreak();
          }
          if ( !std::string::length(v917) )
            goto LABEL_16;
          Instance = CConfigManagerPtr::GetInstance();
          v777 = Instance;
          v5 = std::string::c_str(v917);
          v645 = ((int (__thiscall *)(CConfigManager *, int))v777->GetDefineValue)(v777, v5);
          v811 = v645;
          if ( v645 <= 0 )
          {
            v644 = BBSupportDbgReport(2, "MapObjects\\Building\\BuildingInfoMgr.cpp", 618, "buildingIdx > 0");
            if ( v644 == 1 )
              __debugbreak();
          }
          if ( v811 > 0 )
          {
            v817 = (char *)&CBuildingInfoMgr::m_vBuildingInfos + 70384 * v791 + 848 * v811;
            v643 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v642 = AdvXMLParser::Element::operator()("iHotSpotX", 0);
            v776 = v642;
            v641 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v642 + 8))(v642, v850);
            v6 = (const char *)std::string::c_str(v641);
            v7 = j__atoi(v6);
            *v817 = v7;
            std::string::~string(v850);
            v640 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v639 = AdvXMLParser::Element::operator()("iHotSpotY", 0);
            v775 = v639;
            v638 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v639 + 8))(v639, v851);
            v8 = (const char *)std::string::c_str(v638);
            v9 = j__atoi(v8);
            v817[1] = v9;
            std::string::~string(v851);
            v637 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v636 = AdvXMLParser::Element::operator()("stone", 0);
            v774 = v636;
            v635 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v636 + 8))(v636, v852);
            v10 = (const char *)std::string::c_str(v635);
            v11 = j__atoi(v10);
            v817[2] = v11;
            std::string::~string(v852);
            v634 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v633 = AdvXMLParser::Element::operator()("boards", 0);
            v773 = v633;
            v632 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v633 + 8))(v633, v853);
            v12 = (const char *)std::string::c_str(v632);
            v13 = j__atoi(v12);
            v817[3] = v13;
            std::string::~string(v853);
            v631 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v630 = AdvXMLParser::Element::operator()("gold", 0);
            v772 = v630;
            v629 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v630 + 8))(v630, v854);
            v14 = (const char *)std::string::c_str(v629);
            v15 = j__atoi(v14);
            v817[4] = v15;
            std::string::~string(v854);
            v628 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v627 = AdvXMLParser::Element::operator()("lines", 0);
            v771 = v627;
            v626 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v627 + 8))(v627, v855);
            v16 = (const char *)std::string::c_str(v626);
            v17 = j__atoi(v16);
            v817[5] = v17;
            std::string::~string(v855);
            for ( i = 0; i < (unsigned __int8)v817[5]; ++i )
            {
              v625 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
              v624 = AdvXMLParser::Element::operator()("buildingPosLines", 0);
              v623 = AdvXMLParser::Element::operator()("value", i);
              v770 = v623;
              v622 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v623 + 8))(v623, v856);
              v18 = (const char *)std::string::c_str(v622);
              v797 = j__atoi(v18);
              std::string::~string(v856);
              v621 = v797;
              std::vector<unsigned int>::push_back(&v621);
              v620 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
              v619 = AdvXMLParser::Element::operator()("digPosLines", 0);
              v618 = AdvXMLParser::Element::operator()("value", i);
              v769 = v618;
              v617 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v618 + 8))(v618, v857);
              v19 = (const char *)std::string::c_str(v617);
              v797 = j__atoi(v19);
              std::string::~string(v857);
              v616 = v797;
              std::vector<unsigned int>::push_back(&v616);
              v615 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
              v614 = AdvXMLParser::Element::operator()("blockPosLines", 0);
              v613 = AdvXMLParser::Element::operator()("value", i);
              v768 = v613;
              v612 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v613 + 8))(v613, v858);
              v20 = (const char *)std::string::c_str(v612);
              v797 = j__atoi(v20);
              std::string::~string(v858);
              v611 = v797;
              std::vector<unsigned int>::push_back(&v611);
              v610 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
              v609 = AdvXMLParser::Element::operator()("repealingPosLines", 0);
              v608 = AdvXMLParser::Element::operator()("value", i);
              v767 = v608;
              v607 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v608 + 8))(v608, v859);
              v21 = (const char *)std::string::c_str(v607);
              v797 = j__atoi(v21);
              std::string::~string(v859);
              v606 = v797;
              std::vector<unsigned int>::push_back(&v606);
            }
            IsShipyard = CBuildingInfoMgr::BuildingTypeExIsShipyard(v811);
            if ( IsShipyard || (IsPort = CBuildingInfoMgr::BuildingTypeExIsPort(v811)) )
            {
              v817[6] = 1;
              for ( j = 0; j < (unsigned __int8)v817[5]; ++j )
              {
                v605 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
                v604 = AdvXMLParser::Element::operator()("waterPosLines", 0);
                v603 = AdvXMLParser::Element::operator()("value", j);
                v766 = v603;
                v602 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v603 + 8))(v603, v860);
                v22 = (const char *)std::string::c_str(v602);
                v764 = j__atoi(v22);
                std::string::~string(v860);
                v601 = v764;
                std::vector<unsigned int>::push_back(&v601);
                v600 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
                v599 = AdvXMLParser::Element::operator()("waterBlockPosLines", 0);
                v598 = AdvXMLParser::Element::operator()("value", j);
                v765 = v598;
                v597 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v598 + 8))(v598, v861);
                v23 = (const char *)std::string::c_str(v597);
                v763 = j__atoi(v23);
                std::string::~string(v861);
                v596 = v763;
                std::vector<unsigned int>::push_back(&v596);
                v595 = v763 | v764;
                std::vector<unsigned int>::push_back(&v595);
                v594 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
                v593 = AdvXMLParser::Element::operator()("waterFreePosLines", 0);
                v592 = AdvXMLParser::Element::operator()("value", j);
                v762 = v592;
                v591 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v592 + 8))(v592, v862);
                v24 = (const char *)std::string::c_str(v591);
                v590 = j__atoi(v24);
                std::string::~string(v862);
                v589 = v590;
                std::vector<unsigned int>::push_back(&v589);
              }
            }
            v588 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v587 = AdvXMLParser::Element::operator()("builderNumber", 0);
            v761 = v587;
            v586 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v587 + 8))(v587, v863);
            v25 = (const char *)std::string::c_str(v586);
            v26 = j__atoi(v25);
            v817[7] = v26;
            std::string::~string(v863);
            for ( k = 0; k < v817[7]; ++k )
            {
              v585 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
              v584 = AdvXMLParser::Element::operator()("builderInfo", k);
              v583 = AdvXMLParser::Element::operator()("xOffset", 0);
              v760 = v583;
              v582 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v583 + 8))(v583, v864);
              v27 = (const char *)std::string::c_str(v582);
              v28 = j__atoi(v27);
              v817[3 * k + 8] = v28;
              std::string::~string(v864);
              v581 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
              v580 = AdvXMLParser::Element::operator()("builderInfo", k);
              v579 = AdvXMLParser::Element::operator()("yOffset", 0);
              v759 = v579;
              v578 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v579 + 8))(v579, v865);
              v29 = (const char *)std::string::c_str(v578);
              v30 = j__atoi(v29);
              v817[3 * k + 9] = v30;
              std::string::~string(v865);
              v577 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
              v576 = AdvXMLParser::Element::operator()("builderInfo", k);
              v575 = AdvXMLParser::Element::operator()("dir", 0);
              v758 = v575;
              v574 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v575 + 8))(v575, v866);
              v31 = (const char *)std::string::c_str(v574);
              v32 = j__atoi(v31);
              v817[3 * k + 10] = v32;
              std::string::~string(v866);
            }
            v573 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v572 = AdvXMLParser::Element::operator()("flag", 0);
            v571 = AdvXMLParser::Element::operator()("xOffset", 0);
            v757 = v571;
            v570 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v571 + 8))(v571, v867);
            v33 = (const char *)std::string::c_str(v570);
            v34 = j__atoi(v33);
            v817[38] = v34;
            std::string::~string(v867);
            v569 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v568 = AdvXMLParser::Element::operator()("flag", 0);
            v567 = AdvXMLParser::Element::operator()("yOffset", 0);
            v756 = v567;
            v566 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v567 + 8))(v567, v868);
            v35 = (const char *)std::string::c_str(v566);
            v36 = j__atoi(v35);
            v817[39] = v36;
            std::string::~string(v868);
            v565 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v564 = AdvXMLParser::Element::operator()("door", 0);
            v563 = AdvXMLParser::Element::operator()("xOffset", 0);
            v755 = v563;
            v562 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v563 + 8))(v563, v869);
            v37 = (const char *)std::string::c_str(v562);
            v38 = j__atoi(v37);
            v817[40] = v38;
            std::string::~string(v869);
            v561 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v560 = AdvXMLParser::Element::operator()("door", 0);
            v559 = AdvXMLParser::Element::operator()("yOffset", 0);
            v754 = v559;
            v558 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v559 + 8))(v559, v870);
            v39 = (const char *)std::string::c_str(v558);
            v40 = j__atoi(v39);
            v817[41] = v40;
            std::string::~string(v870);
            v557 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v556 = AdvXMLParser::Element::operator()("workingpos", 0);
            v555 = AdvXMLParser::Element::operator()("xOffset", 0);
            v753 = v555;
            v554 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v555 + 8))(v555, v871);
            v41 = (const char *)std::string::c_str(v554);
            v42 = j__atoi(v41);
            v817[42] = v42;
            std::string::~string(v871);
            v553 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v552 = AdvXMLParser::Element::operator()("workingpos", 0);
            v551 = AdvXMLParser::Element::operator()("yOffset", 0);
            v752 = v551;
            v550 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v551 + 8))(v551, v872);
            v43 = (const char *)std::string::c_str(v550);
            v44 = j__atoi(v43);
            v817[43] = v44;
            std::string::~string(v872);
            v549 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v548 = AdvXMLParser::Element::operator()("bitBoundingRect", 0);
            v547 = AdvXMLParser::Element::operator()("minX", 0);
            v751 = v547;
            v546 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v547 + 8))(v547, v873);
            v45 = (const char *)std::string::c_str(v546);
            v46 = j__atoi(v45);
            v817[52] = v46;
            std::string::~string(v873);
            v545 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v544 = AdvXMLParser::Element::operator()("bitBoundingRect", 0);
            v543 = AdvXMLParser::Element::operator()("maxX", 0);
            v750 = v543;
            v542 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v543 + 8))(v543, v874);
            v47 = (const char *)std::string::c_str(v542);
            v48 = j__atoi(v47);
            v817[53] = v48;
            std::string::~string(v874);
            v541 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v540 = AdvXMLParser::Element::operator()("bitBoundingRect", 0);
            v539 = AdvXMLParser::Element::operator()("minY", 0);
            v749 = v539;
            v538 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v539 + 8))(v539, v875);
            v49 = (const char *)std::string::c_str(v538);
            v50 = j__atoi(v49);
            v817[54] = v50;
            std::string::~string(v875);
            v537 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v536 = AdvXMLParser::Element::operator()("bitBoundingRect", 0);
            v219 = AdvXMLParser::Element::operator()("maxY", 0);
            v748 = v219;
            v220 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v219 + 8))(v219, v876);
            v51 = (const char *)std::string::c_str(v220);
            v52 = j__atoi(v51);
            v817[55] = v52;
            std::string::~string(v876);
            v221 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v222 = AdvXMLParser::Element::operator()("pileNumber", 0);
            v747 = v222;
            v223 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v222 + 8))(v222, v877);
            v53 = (const char *)std::string::c_str(v223);
            v54 = j__atoi(v53);
            v817[57] = v54;
            std::string::~string(v877);
            for ( m = 0; m < v817[57]; ++m )
            {
              v224 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
              v225 = AdvXMLParser::Element::operator()("pile", m);
              v226 = AdvXMLParser::Element::operator()("xOffset", 0);
              v746 = v226;
              v227 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v226 + 8))(v226, v878);
              v55 = (const char *)std::string::c_str(v227);
              v56 = j__atoi(v55);
              v817[16 * m + 60] = v56;
              std::string::~string(v878);
              v228 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
              v229 = AdvXMLParser::Element::operator()("pile", m);
              v230 = AdvXMLParser::Element::operator()("yOffset", 0);
              v745 = v230;
              v231 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v230 + 8))(v230, v879);
              v57 = (const char *)std::string::c_str(v231);
              v58 = j__atoi(v57);
              v817[16 * m + 61] = v58;
              std::string::~string(v879);
              v232 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
              v233 = AdvXMLParser::Element::operator()("pile", m);
              v234 = AdvXMLParser::Element::operator()("good", 0);
              v744 = v234;
              v235 = CConfigManagerPtr::GetInstance();
              v743 = v235;
              v236 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v744 + 8))(v744, v880);
              v237 = v236;
              LOBYTE(v919) = 17;
              v59 = std::string::c_str(v236);
              v238 = ((int (__thiscall *)(CConfigManager *, int))v743->GetDefineValue)(v743, v59);
              v817[16 * m + 62] = v238;
              LOBYTE(v919) = 16;
              std::string::~string(v880);
              v239 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
              v240 = AdvXMLParser::Element::operator()("pile", m);
              v241 = AdvXMLParser::Element::operator()("type", 0);
              v742 = v241;
              v242 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v241 + 8))(v241, v881);
              v60 = (const char *)std::string::c_str(v242);
              v61 = j__atoi(v60);
              v817[16 * m + 63] = v61;
              std::string::~string(v881);
              v243 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
              v244 = AdvXMLParser::Element::operator()("pile", m);
              v245 = AdvXMLParser::Element::operator()("patch", 0);
              v741 = v245;
              v246 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v245 + 8))(v245, v883);
              v62 = (const char *)std::string::c_str(v246);
              v63 = j__atoi(v62);
              v817[16 * m + 65] = v63;
              std::string::~string(v883);
              v247 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
              v248 = AdvXMLParser::Element::operator()("pile", m);
              v249 = AdvXMLParser::Element::operator()("appearance", 0);
              v740 = v249;
              v250 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v249 + 8))(v249, v848);
              v64 = (const char *)std::string::c_str(v250);
              v65 = j__atoi(v64);
              v817[16 * m + 64] = v65;
              std::string::~string(v848);
              v251 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
              v252 = AdvXMLParser::Element::operator()("pile", m);
              v253 = AdvXMLParser::Element::operator()("xPixelOffset", 0);
              v739 = v253;
              v254 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v253 + 8))(v253, v884);
              v66 = (const char *)std::string::c_str(v254);
              v67 = j__atoi(v66);
              *(_DWORD *)&v817[16 * m + 68] = v67;
              std::string::~string(v884);
              v255 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
              v256 = AdvXMLParser::Element::operator()("pile", m);
              v257 = AdvXMLParser::Element::operator()("yPixelOffset", 0);
              v738 = v257;
              v258 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v257 + 8))(v257, v885);
              v68 = (const char *)std::string::c_str(v258);
              v69 = j__atoi(v68);
              *(_DWORD *)&v817[16 * m + 72] = v69;
              std::string::~string(v885);
            }
            v259 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v260 = AdvXMLParser::Element::operator()("settlerNumber", 0);
            v737 = v260;
            v261 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v260 + 8))(v260, v886);
            v70 = (const char *)std::string::c_str(v261);
            v71 = j__atoi(v70);
            v817[220] = v71;
            std::string::~string(v886);
            if ( (unsigned __int8)v817[220] >= 0x15u )
            {
              v262 = BBSupportDbgReport(
                       2,
                       "MapObjects\\Building\\BuildingInfoMgr.cpp",
                       738,
                       "bI.m_uWarriorNumber < MAX_NUMBER_OF_BUILDING_SETTLERS");
              if ( v262 == 1 )
                __debugbreak();
            }
            for ( n = 0; n < (unsigned __int8)v817[220]; ++n )
            {
              v263 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
              v264 = AdvXMLParser::Element::operator()("settler", n);
              v265 = AdvXMLParser::Element::operator()("xOffset", 0);
              v736 = v265;
              v266 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v265 + 8))(v265, v887);
              v72 = (const char *)std::string::c_str(v266);
              v73 = j__atoi(v72);
              *(_DWORD *)&v817[12 * n + 224] = v73;
              std::string::~string(v887);
              v267 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
              v268 = AdvXMLParser::Element::operator()("settler", n);
              v269 = AdvXMLParser::Element::operator()("yOffset", 0);
              v735 = v269;
              v270 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v269 + 8))(v269, v888);
              v74 = (const char *)std::string::c_str(v270);
              v75 = j__atoi(v74);
              *(_DWORD *)&v817[12 * n + 228] = v75;
              std::string::~string(v888);
              v271 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
              v272 = AdvXMLParser::Element::operator()("settler", n);
              v273 = AdvXMLParser::Element::operator()("direction", 0);
              v734 = v273;
              v274 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v273 + 8))(v273, v889);
              v76 = (const char *)std::string::c_str(v274);
              v77 = j__atoi(v76);
              v817[12 * n + 232] = v77;
              std::string::~string(v889);
              v195 = std::string::string(v902, "true");
              LOBYTE(v919) = 18;
              v275 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
              v276 = AdvXMLParser::Element::operator()("settler", n);
              v277 = AdvXMLParser::Element::operator()("top", 0);
              v733 = v277;
              v278 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v277 + 8))(v277, v890);
              v732 = std::string::compare(v278) == 0;
              v817[12 * n + 233] = v732;
              std::string::~string(v890);
              LOBYTE(v919) = 16;
              std::string::~string(v902);
            }
            v731 = (unsigned __int8)v817[220];
            v817[221] = 0;
            v817[222] = 0;
            v817[223] = -1;
            if ( v731 > 0 )
            {
              for ( ii = 0; ii < v731; ++ii )
              {
                if ( v817[12 * ii + 233] == 1 )
                {
                  ++v817[222];
                  if ( v817[223] < 0 )
                    v817[223] = ii;
                }
                else
                {
                  ++v817[221];
                }
              }
              if ( !v817[222] )
              {
                v153 = v791;
                v78 = (const char *)std::string::c_str(v917);
                v279 = BBSupportDbgReportF(
                         2,
                         "MapObjects\\Building\\BuildingInfoMgr.cpp",
                         783,
                         "Bowman number == 0 for building %i (%s) of race %i!",
                         v811,
                         v78,
                         v153);
                if ( v279 == 1 )
                  __debugbreak();
              }
              if ( !v817[221] )
              {
                v154 = v791;
                v79 = (const char *)std::string::c_str(v917);
                v280 = BBSupportDbgReportF(
                         2,
                         "MapObjects\\Building\\BuildingInfoMgr.cpp",
                         784,
                         "Swordsman number == 0 for building %i (%s) of race %i!",
                         v811,
                         v79,
                         v154);
                if ( v280 == 1 )
                  __debugbreak();
              }
            }
            v281 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v320 = AdvXMLParser::Element::operator()("patchSettlerSlot", 0);
            v730 = v320;
            v283 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v320 + 8))(v320, v891);
            v80 = (const char *)std::string::c_str(v283);
            v81 = j__atoi(v80);
            v817[476] = v81;
            std::string::~string(v891);
            v284 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v285 = AdvXMLParser::Element::operator()("miniflag", 0);
            v286 = AdvXMLParser::Element::operator()("xOffset", 0);
            v729 = v286;
            v287 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v286 + 8))(v286, v892);
            v82 = (const char *)std::string::c_str(v287);
            v83 = j__atoi(v82);
            *((_DWORD *)v817 + 11) = v83;
            std::string::~string(v892);
            v288 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v289 = AdvXMLParser::Element::operator()("miniflag", 0);
            v290 = AdvXMLParser::Element::operator()("yOffset", 0);
            v728 = v290;
            v291 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v290 + 8))(v290, v893);
            v84 = (const char *)std::string::c_str(v291);
            v85 = j__atoi(v84);
            *((_DWORD *)v817 + 12) = v85;
            std::string::~string(v893);
            v292 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v293 = AdvXMLParser::Element::operator()("kind", 0);
            v727 = v293;
            v294 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v293 + 8))(v293, v894);
            v295 = v294;
            LOBYTE(v919) = 19;
            v86 = (char *)std::string::c_str(v294);
            v194 = std::string::string(v903, v86);
            LOBYTE(v919) = 20;
            v296 = CDefineTranslator::Instance();
            v297 = CDefineTranslator::GetValueOfDefine(v903);
            v817[477] = v297;
            LOBYTE(v919) = 19;
            std::string::~string(v903);
            LOBYTE(v919) = 16;
            std::string::~string(v894);
            v298 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v299 = AdvXMLParser::Element::operator()("inhabitant", 0);
            v726 = v299;
            v300 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v299 + 8))(v299, v895);
            v301 = v300;
            LOBYTE(v919) = 21;
            v87 = (char *)std::string::c_str(v300);
            v193 = std::string::string(v914, v87);
            LOBYTE(v919) = 23;
            std::string::~string(v895);
            if ( std::operator==<char>((int)v914, (char *)&byte_3778517) )
            {
              v817[478] = 0;
            }
            else
            {
              v302 = CConfigManagerPtr::GetInstance();
              v725 = v302;
              v88 = std::string::c_str(v914);
              v303 = ((int (__thiscall *)(CConfigManager *, int))v725->GetDefineValue)(v725, v88);
              v817[478] = v303;
            }
            v304 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v305 = AdvXMLParser::Element::operator()("tool", 0);
            v724 = v305;
            v306 = CConfigManagerPtr::GetInstance();
            v723 = v306;
            v307 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v724 + 8))(v724, v896);
            v308 = v307;
            LOBYTE(v919) = 24;
            v89 = std::string::c_str(v307);
            v309 = ((int (__thiscall *)(CConfigManager *, int))v723->GetDefineValue)(v723, v89);
            v817[479] = v309;
            LOBYTE(v919) = 23;
            std::string::~string(v896);
            v310 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v312 = AdvXMLParser::Element::operator()("productiondelay", 0);
            v722 = v312;
            v313 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v312 + 8))(v312, v897);
            v314 = v313;
            LOBYTE(v919) = 25;
            v90 = (char *)std::string::c_str(v313);
            v192 = std::string::string(v908, v90);
            LOBYTE(v919) = 27;
            std::string::~string(v897);
            v91 = (const char *)std::string::c_str(v908);
            v796 = j__atoi(v91);
            if ( (unsigned int)v796 >= 0x100 )
            {
              v315 = BBSupportDbgReport(
                       2,
                       "MapObjects\\Building\\BuildingInfoMgr.cpp",
                       816,
                       "(iProductionDelay >= 0) && (iProductionDelay <= 255)");
              if ( v315 == 1 )
                __debugbreak();
            }
            if ( v796 >= 0 )
            {
              if ( v796 > 255 )
                v796 = 255;
            }
            else
            {
              v796 = 0;
            }
            v817[480] = v796;
            v316 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v317 = AdvXMLParser::Element::operator()("dummyValue", 0);
            v721 = v317;
            v318 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v317 + 8))(v317, v898);
            v92 = (const char *)std::string::c_str(v318);
            v93 = j__atoi(v92);
            *((_DWORD *)v817 + 124) = v93;
            std::string::~string(v898);
            v319 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v323 = AdvXMLParser::Element::operator()("influenceRadius", 0);
            v671 = v323;
            v324 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v323 + 8))(v323, v899);
            v94 = (const char *)std::string::c_str(v324);
            v95 = j__atoi(v94);
            *((_DWORD *)v817 + 121) = v95;
            std::string::~string(v899);
            v346 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v311 = AdvXMLParser::Element::operator()("explorerRadius", 0);
            v720 = v311;
            v322 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v311 + 8))(v311, v818);
            v96 = (const char *)std::string::c_str(v322);
            v97 = j__atoi(v96);
            *((_DWORD *)v817 + 122) = v97;
            std::string::~string(v818);
            v535 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v534 = AdvXMLParser::Element::operator()("workingAreaRadius", 0);
            v719 = v534;
            v533 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v534 + 8))(v534, v819);
            v98 = (const char *)std::string::c_str(v533);
            v99 = j__atoi(v98);
            *((_DWORD *)v817 + 123) = v99;
            std::string::~string(v819);
            v532 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v531 = AdvXMLParser::Element::operator()("searchType", 0);
            v718 = v531;
            v530 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v531 + 8))(v531, v820);
            v529 = v530;
            LOBYTE(v919) = 28;
            v100 = (char *)std::string::c_str(v530);
            v191 = std::string::string(v904, v100);
            LOBYTE(v919) = 29;
            v528 = CDefineTranslator::Instance();
            v527 = CDefineTranslator::GetValueOfDefine(v904);
            v817[481] = v527;
            LOBYTE(v919) = 28;
            std::string::~string(v904);
            LOBYTE(v919) = 27;
            std::string::~string(v820);
            v526 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v525 = AdvXMLParser::Element::operator()("Hitpoints", 0);
            v717 = v525;
            v524 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v525 + 8))(v525, v821);
            v101 = (const char *)std::string::c_str(v524);
            v102 = j__atoi(v101);
            v817[500] = v102 / 2;
            std::string::~string(v821);
            v523 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v522 = AdvXMLParser::Element::operator()("Armor", 0);
            v716 = v522;
            v521 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v522 + 8))(v522, v822);
            v103 = (const char *)std::string::c_str(v521);
            v104 = j__atoi(v103);
            v817[501] = v104;
            std::string::~string(v822);
            if ( !v817[500] )
            {
              v520 = v817[2];
              v519 = v817[3];
              v518 = v817[4];
              v517 = v518 + v519 + v520;
              v715 = 8 * v517 / 2;
              if ( v715 >= 250 )
                v714 = 250;
              else
                v714 = v715;
              v817[500] = v714;
            }
            v516 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v515 = AdvXMLParser::Element::operator()("animLists", 0);
            v514 = AdvXMLParser::NodeContainer::Begin(v515, v170);
            v513 = v514;
            LOBYTE(v919) = 30;
            v190 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v514);
            LOBYTE(v919) = 32;
            AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v170);
            v512 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v511 = AdvXMLParser::Element::operator()("animLists", 0);
            v510 = AdvXMLParser::NodeContainer::End(v511, v169);
            v509 = v510;
            LOBYTE(v919) = 33;
            v189 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v510);
            LOBYTE(v919) = 35;
            AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v169);
            while ( (unsigned __int8)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v180) )
            {
              v508 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v216);
              v713 = v508;
              v507 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v508 + 8))(v508, v823);
              v506 = v507;
              LOBYTE(v919) = 36;
              v105 = (char *)std::string::c_str(v507);
              v188 = std::string::string(v905, v105);
              LOBYTE(v919) = 38;
              std::string::~string(v823);
              v505 = CConfigManagerPtr::GetInstance();
              v712 = v505;
              v106 = std::string::c_str(v905);
              v504 = ((int (__thiscall *)(CConfigManager *, int))v712->GetDefineValue)(v712, v106);
              v503 = v504;
              v803 = v504;
              std::vector<unsigned char>::push_back(&v803);
              LOBYTE(v919) = 35;
              std::string::~string(v905);
              AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v216);
            }
            v812 = 0;
            v502 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v501 = AdvXMLParser::Element::operator()("patches", 0);
            v500 = AdvXMLParser::NodeContainer::Begin(v501, v168);
            v499 = v500;
            LOBYTE(v919) = 39;
            v208 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v500);
            LOBYTE(v919) = 41;
            AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v168);
            v498 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v497 = AdvXMLParser::Element::operator()("patches", 0);
            v496 = AdvXMLParser::NodeContainer::End(v497, v167);
            v495 = v496;
            LOBYTE(v919) = 42;
            v186 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v496);
            LOBYTE(v919) = 44;
            AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v167);
            while ( (unsigned __int8)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v174) )
            {
              v494 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v670);
              v493 = AdvXMLParser::Element::operator()("job", 0);
              v711 = v493;
              v492 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v493 + 8))(v493, v824);
              v491 = v492;
              LOBYTE(v919) = 45;
              v107 = (char *)std::string::c_str(v492);
              v185 = std::string::string(v916, v107);
              LOBYTE(v919) = 47;
              std::string::~string(v824);
              if ( !std::string::length(v916) )
              {
                v490 = BBSupportDbgReport(2, "MapObjects\\Building\\BuildingInfoMgr.cpp", 864, "patchName.length() > 0");
                if ( v490 == 1 )
                  __debugbreak();
              }
              v489 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v670);
              v488 = AdvXMLParser::Element::operator()("job", 0);
              v710 = v488;
              v487 = CConfigManagerPtr::GetInstance();
              v709 = v487;
              v486 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v710 + 8))(v710, v825);
              v485 = v486;
              LOBYTE(v919) = 48;
              v108 = std::string::c_str(v486);
              v484 = ((int (__thiscall *)(CConfigManager *, int))v709->GetDefineValue)(v709, v108);
              v786 = v484;
              LOBYTE(v919) = 47;
              std::string::~string(v825);
              if ( v786 < 0 )
              {
                v708 = std::string::length(v916) ? (const char *)std::string::c_str(v916) : (const char *)&unk_3778527;
                v155 = (const char *)std::string::c_str(v915);
                v109 = (const char *)std::string::c_str(v917);
                v483 = BBSupportDbgReportF(
                         2,
                         "MapObjects\\Building\\BuildingInfoMgr.cpp",
                         868,
                         "Patch job \"%s\" not valid for building %s for race %s!",
                         v708,
                         v109,
                         v155);
                if ( v483 == 1 )
                  __debugbreak();
              }
              *(_DWORD *)&v817[16 * v812 + 504] = v786;
              v482 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v670);
              v481 = AdvXMLParser::Element::operator()("type", 0);
              v707 = v481;
              v480 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v481 + 8))(v481, v826);
              v479 = v480;
              LOBYTE(v919) = 49;
              v110 = (char *)std::string::c_str(v480);
              std::string::operator=(v916, v110);
              LOBYTE(v919) = 47;
              std::string::~string(v826);
              v111 = (char *)std::string::c_str(v916);
              v184 = std::string::string(v901, v111);
              LOBYTE(v919) = 50;
              v478 = CDefineTranslator::Instance();
              v477 = CDefineTranslator::GetValueOfDefine(v901);
              v786 = v477;
              LOBYTE(v919) = 47;
              std::string::~string(v901);
              v817[16 * v812 + 509] = v786;
              v476 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v670);
              v475 = AdvXMLParser::Element::operator()("ticks", 0);
              v706 = v475;
              v474 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v475 + 8))(v475, v827);
              v112 = (const char *)std::string::c_str(v474);
              v113 = j__atoi(v112);
              v817[16 * v812 + 510] = v113;
              std::string::~string(v827);
              v473 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v670);
              v472 = AdvXMLParser::Element::operator()("slot", 0);
              v705 = v472;
              v471 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v472 + 8))(v472, v828);
              v114 = (const char *)std::string::c_str(v471);
              v115 = j__atoi(v114);
              v817[16 * v812 + 508] = v115;
              std::string::~string(v828);
              v470 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v670);
              v469 = AdvXMLParser::Element::operator()("sound", 0);
              v468 = AdvXMLParser::Element::operator()("def", 0);
              v704 = v468;
              v467 = CConfigManagerPtr::GetInstance();
              v703 = v467;
              v466 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v704 + 8))(v704, v829);
              v465 = v466;
              LOBYTE(v919) = 51;
              v116 = std::string::c_str(v466);
              v464 = ((int (__thiscall *)(CConfigManager *, int))v703->GetDefineValue)(v703, v116);
              v782 = v464;
              LOBYTE(v919) = 47;
              std::string::~string(v829);
              if ( v782 < 0 )
                v782 = 0;
              *(_DWORD *)&v817[16 * v812 + 512] = v782;
              v463 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v670);
              v462 = AdvXMLParser::Element::operator()("sound", 0);
              v461 = AdvXMLParser::Element::operator()("frame", 0);
              v702 = v461;
              v460 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v461 + 8))(v461, v830);
              v117 = (const char *)std::string::c_str(v460);
              v118 = j__atoi(v117);
              v817[16 * v812 + 517] = v118;
              std::string::~string(v830);
              v459 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v670);
              v458 = AdvXMLParser::Element::operator()("sound", 0);
              v457 = AdvXMLParser::Element::operator()("random", 0);
              v701 = v457;
              v456 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v457 + 8))(v457, v831);
              v119 = (const char *)std::string::c_str(v456);
              v120 = j__atoi(v119);
              v817[16 * v812 + 516] = v120;
              std::string::~string(v831);
              if ( !v817[16 * v812 + 516] )
                v817[16 * v812 + 516] = 100;
              ++v812;
              LOBYTE(v919) = 44;
              std::string::~string(v916);
              AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v670);
            }
            v455 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v454 = AdvXMLParser::Element::operator()("triggers", 0);
            v453 = AdvXMLParser::NodeContainer::Begin(v454, v166);
            v452 = v453;
            LOBYTE(v919) = 52;
            v183 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v453);
            LOBYTE(v919) = 54;
            AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v166);
            v451 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v814);
            v450 = AdvXMLParser::Element::operator()("triggers", 0);
            v449 = AdvXMLParser::NodeContainer::End(v450, v165);
            v448 = v449;
            LOBYTE(v919) = 55;
            v182 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v449);
            LOBYTE(v919) = 57;
            AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v165);
            while ( (unsigned __int8)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v175) )
            {
              v447 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v217);
              v446 = AdvXMLParser::Element::operator()("slot", 0);
              v700 = v446;
              v445 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v446 + 8))(v446, v832);
              v121 = (const char *)std::string::c_str(v445);
              v438 = j__atoi(v121);
              std::string::~string(v832);
              v444 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v217);
              v443 = AdvXMLParser::Element::operator()("job", 0);
              v699 = v443;
              v442 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v443 + 8))(v443, v833);
              v441 = v442;
              LOBYTE(v919) = 58;
              v122 = (char *)std::string::c_str(v442);
              v181 = std::string::string(v907, v122);
              LOBYTE(v919) = 60;
              std::string::~string(v833);
              v123 = (char *)std::string::c_str(v907);
              v215 = std::string::string(v906, v123);
              LOBYTE(v919) = 61;
              v440 = CDefineTranslator::Instance();
              v439 = CDefineTranslator::GetValueOfDefine(v906);
              v437 = v439;
              LOBYTE(v919) = 60;
              std::string::~string(v906);
              *(_DWORD *)&v817[4 * v438 + 664] = v437;
              LOBYTE(v919) = 57;
              std::string::~string(v907);
              AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v217);
            }
            v788 = 0;
            v433 = (Grid *)-*v817;
            v434 = -v817[1];
            v436 = (unsigned __int8)v817[5];
            for ( jj = 0; jj < v436; ++jj )
            {
              v435 = (int *)std::vector<unsigned int>::operator[](jj);
              v785 = *v435;
              v432 = jj + v434;
              v781 = v433;
              while ( v785 )
              {
                if ( v785 < 0 )
                {
                  v431 = Grid::DistanceInline(v781, v432);
                  v698 = v431;
                  if ( v431 > (int)v788 )
                    v788 = v698;
                }
                v781 = (Grid *)((char *)v781 + 1);
                v785 *= 2;
              }
            }
            if ( v788 >= 0x40 )
            {
              v430 = BBSupportDbgReport(
                       2,
                       "MapObjects\\Building\\BuildingInfoMgr.cpp",
                       952,
                       "(iMaxDistance >= 0) && (iMaxDistance < 64)");
              if ( v430 == 1 )
                __debugbreak();
            }
            v817[56] = v788;
            if ( !CBuildingInfoMgr::DbgCheckBuildingBits(v697, v791, v811) )
            {
              RaceName = CS4DefineNames::GetRaceName(v791);
              v428 = BBSupportDbgReportF(
                       2,
                       "MapObjects\\Building\\BuildingInfoMgr.cpp",
                       956,
                       "Invalid building info for building %i (%s) of race %i (%s)!",
                       v811,
                       (&off_377C0D4)[2 * v811],
                       v791,
                       RaceName);
              if ( v428 == 1 )
                __debugbreak();
            }
            LOBYTE(v919) = 54;
            AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v175);
            LOBYTE(v919) = 44;
            AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v217);
            LOBYTE(v919) = 41;
            AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v174);
            LOBYTE(v919) = 35;
            AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v670);
            LOBYTE(v919) = 32;
            AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v180);
            LOBYTE(v919) = 27;
            AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v216);
            LOBYTE(v919) = 23;
            std::string::~string(v908);
            LOBYTE(v919) = 16;
            std::string::~string(v914);
            LOBYTE(v919) = 15;
            std::string::~string(v917);
          }
          else
          {
LABEL_16:
            LOBYTE(v919) = 15;
            std::string::~string(v917);
          }
          AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v814);
        }
        LOBYTE(v919) = 12;
        AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v179);
        LOBYTE(v919) = 9;
        AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v814);
        LOBYTE(v919) = 8;
        std::string::~string(v915);
      }
      else
      {
        LOBYTE(v919) = 8;
        std::string::~string(v915);
      }
    }
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v321);
  }
  LOBYTE(v919) = 5;
  AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v178);
  LOBYTE(v919) = 2;
  AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v321);
  LOBYTE(v919) = 1;
  std::auto_ptr<AdvXMLParser::Document>::~auto_ptr<AdvXMLParser::Document>(v696);
  LOBYTE(v919) = 0;
  AdvXMLParser::Parser::~Parser(v158);
  v919 = -1;
  C = v795;
  operator delete[](v795);
  if ( *(&byte_403537D + 39008) != 1
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         973,
         "m_vBuildingInfos[RACE_ROMAN][BUILDING_GUARDTOWERSMALL].m_uSwordsmanNumber == 1") == 1 )
  {
    __debugbreak();
  }
  if ( *(&byte_403537E + 39008) != 2
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         974,
         "m_vBuildingInfos[RACE_ROMAN][BUILDING_GUARDTOWERSMALL].m_uBowmanNumber == 2") == 1 )
  {
    __debugbreak();
  }
  if ( *(&byte_403537D + 39856) != 3
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         976,
         "m_vBuildingInfos[RACE_ROMAN][BUILDING_GUARDTOWERBIG].m_uSwordsmanNumber == 3") == 1 )
  {
    __debugbreak();
  }
  if ( *(&byte_403537E + 39856) != 3
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         977,
         "m_vBuildingInfos[RACE_ROMAN][BUILDING_GUARDTOWERBIG].m_uBowmanNumber == 3") == 1 )
  {
    __debugbreak();
  }
  if ( *(&byte_403537D + 40704) != 4
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         979,
         "m_vBuildingInfos[RACE_ROMAN][BUILDING_CASTLE].m_uSwordsmanNumber == 4") == 1 )
  {
    __debugbreak();
  }
  if ( *(&byte_403537E + 40704) != 5
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         980,
         "m_vBuildingInfos[RACE_ROMAN][BUILDING_CASTLE].m_uBowmanNumber == 5") == 1 )
  {
    __debugbreak();
  }
  if ( *(&byte_403537D + 109392) != 1
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         982,
         "m_vBuildingInfos[RACE_VIKING][BUILDING_GUARDTOWERSMALL].m_uSwordsmanNumber == 1") == 1 )
  {
    __debugbreak();
  }
  if ( *(&byte_403537E + 109392) != 2
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         983,
         "m_vBuildingInfos[RACE_VIKING][BUILDING_GUARDTOWERSMALL].m_uBowmanNumber == 2") == 1 )
  {
    __debugbreak();
  }
  if ( *(&byte_403537D + 110240) != 3
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         985,
         "m_vBuildingInfos[RACE_VIKING][BUILDING_GUARDTOWERBIG].m_uSwordsmanNumber == 3") == 1 )
  {
    __debugbreak();
  }
  if ( *(&byte_403537E + 110240) != 3
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         986,
         "m_vBuildingInfos[RACE_VIKING][BUILDING_GUARDTOWERBIG].m_uBowmanNumber == 3") == 1 )
  {
    __debugbreak();
  }
  if ( *(&byte_403537D + 111088) != 4
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         988,
         "m_vBuildingInfos[RACE_VIKING][BUILDING_CASTLE].m_uSwordsmanNumber == 4") == 1 )
  {
    __debugbreak();
  }
  if ( *(&byte_403537E + 111088) != 5
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         989,
         "m_vBuildingInfos[RACE_VIKING][BUILDING_CASTLE].m_uBowmanNumber == 5") == 1 )
  {
    __debugbreak();
  }
  if ( *(&byte_403537D + 179776) != 1
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         991,
         "m_vBuildingInfos[RACE_MAYA][BUILDING_GUARDTOWERSMALL].m_uSwordsmanNumber == 1") == 1 )
  {
    __debugbreak();
  }
  if ( *(&byte_403537E + 179776) != 2
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         992,
         "m_vBuildingInfos[RACE_MAYA][BUILDING_GUARDTOWERSMALL].m_uBowmanNumber == 2") == 1 )
  {
    __debugbreak();
  }
  if ( *(&byte_403537D + 180624) != 3
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         994,
         "m_vBuildingInfos[RACE_MAYA][BUILDING_GUARDTOWERBIG].m_uSwordsmanNumber == 3") == 1 )
  {
    __debugbreak();
  }
  if ( *(&byte_403537E + 180624) != 3
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         995,
         "m_vBuildingInfos[RACE_MAYA][BUILDING_GUARDTOWERBIG].m_uBowmanNumber == 3") == 1 )
  {
    __debugbreak();
  }
  if ( *(&byte_403537D + 181472) != 4
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         997,
         "m_vBuildingInfos[RACE_MAYA][BUILDING_CASTLE].m_uSwordsmanNumber == 4") == 1 )
  {
    __debugbreak();
  }
  if ( *(&byte_403537E + 181472) != 5
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         998,
         "m_vBuildingInfos[RACE_MAYA][BUILDING_CASTLE].m_uBowmanNumber == 5") == 1 )
  {
    __debugbreak();
  }
  if ( *(&byte_403537D + 320544) != 1
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         1000,
         "m_vBuildingInfos[RACE_TROJAN][BUILDING_GUARDTOWERSMALL].m_uSwordsmanNumber == 1") == 1 )
  {
    __debugbreak();
  }
  if ( *(&byte_403537E + 320544) != 2
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         1001,
         "m_vBuildingInfos[RACE_TROJAN][BUILDING_GUARDTOWERSMALL].m_uBowmanNumber == 2") == 1 )
  {
    __debugbreak();
  }
  if ( *(&byte_403537D + 321392) != 3
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         1003,
         "m_vBuildingInfos[RACE_TROJAN][BUILDING_GUARDTOWERBIG].m_uSwordsmanNumber == 3") == 1 )
  {
    __debugbreak();
  }
  if ( *(&byte_403537E + 321392) != 3
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         1004,
         "m_vBuildingInfos[RACE_TROJAN][BUILDING_GUARDTOWERBIG].m_uBowmanNumber == 3") == 1 )
  {
    __debugbreak();
  }
  if ( *(&byte_403537D + 322240) != 4
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         1006,
         "m_vBuildingInfos[RACE_TROJAN][BUILDING_CASTLE].m_uSwordsmanNumber == 4") == 1 )
  {
    __debugbreak();
  }
  if ( *(&byte_403537E + 322240) != 5
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingInfoMgr.cpp",
         1007,
         "m_vBuildingInfos[RACE_TROJAN][BUILDING_CASTLE].m_uBowmanNumber == 5") == 1 )
  {
    __debugbreak();
  }
  memset(&CBuildingInfoMgr::m_vTriggerInfos, 0, 0x210Cu);
  v787 = 0;
  result = AdvXMLParser::Parser::OpenXMLFile(aGamedataBuildi_0, &v787);
  v795 = result;
  if ( !result )
    return result;
  v919 = 64;
  v214 = AdvXMLParser::Parser::Parser(v159);
  LOBYTE(v919) = 65;
  v426 = AdvXMLParser::Parser::Parse((AdvXMLParser::Parser *)v159, v795, v787);
  std::auto_ptr<AdvXMLParser::Document>::auto_ptr<AdvXMLParser::Document>(v426);
  LOBYTE(v919) = 66;
  v124 = std::auto_ptr<AdvXMLParser::Document>::operator->(v156, v157);
  v425 = AdvXMLParser::Document::GetRoot(v124);
  v695 = v425;
  v424 = CDefineTranslator::Instance();
  v692 = v424;
  v213 = 0;
  v423 = AdvXMLParser::NodeContainer::Begin(v695, v164);
  v422 = v423;
  LOBYTE(v919) = 67;
  v212 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v423);
  LOBYTE(v919) = 69;
  AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v164);
  v421 = AdvXMLParser::NodeContainer::End(v695, v163);
  v420 = v421;
  LOBYTE(v919) = 70;
  v211 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v421);
  LOBYTE(v919) = 72;
  AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v163);
  while ( (unsigned __int8)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v176) )
  {
    v419 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v218);
    v418 = AdvXMLParser::Element::operator[]("id");
    v694 = v418;
    v210 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v418 + 8))(v418, v900);
    LOBYTE(v919) = 73;
    v417 = CDefineTranslator::GetValueOfDefine(v900);
    v406 = v417;
    v416 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v218);
    v415 = AdvXMLParser::NodeContainer::Begin(v416, v160);
    v414 = v415;
    LOBYTE(v919) = 74;
    v209 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v415);
    LOBYTE(v919) = 76;
    AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v160);
    v413 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v218);
    v412 = AdvXMLParser::NodeContainer::End(v413, v161);
    v411 = v412;
    LOBYTE(v919) = 77;
    v207 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v412);
    LOBYTE(v919) = 79;
    AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v161);
    while ( (unsigned __int8)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v177) )
    {
      v410 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v784);
      v409 = AdvXMLParser::Element::operator[]("id");
      v693 = v409;
      v187 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v409 + 8))(v409, v913);
      LOBYTE(v919) = 80;
      v408 = CDefineTranslator::GetValueOfDefine(v913);
      v407 = v408;
      v816 = (char *)&CBuildingInfoMgr::m_vTriggerInfos + 1692 * v406 + 36 * v408;
      v405 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v784);
      v404 = AdvXMLParser::Element::operator()("patch", 0);
      v403 = AdvXMLParser::Element::operator()("def", 0);
      v691 = v403;
      v402 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v403 + 8))(v403, v834);
      v401 = v402;
      LOBYTE(v919) = 81;
      v125 = (char *)std::string::c_str(v402);
      v206 = std::string::string(v912, v125);
      LOBYTE(v919) = 83;
      std::string::~string(v834);
      v400 = CConfigManagerPtr::GetInstance();
      v690 = v400;
      v126 = std::string::c_str(v912);
      v399 = ((int (__thiscall *)(CConfigManager *, int))v690->GetDefineValue)(v690, v126);
      *(_DWORD *)v816 = v399;
      v398 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v784);
      v397 = AdvXMLParser::Element::operator()("patch", 0);
      v396 = AdvXMLParser::Element::operator()("slot", 0);
      v689 = v396;
      v395 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v396 + 8))(v396, v882);
      v127 = (const char *)std::string::c_str(v395);
      v128 = j__atoi(v127);
      v816[4] = v128;
      std::string::~string(v882);
      v394 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v784);
      v393 = AdvXMLParser::Element::operator()("patch", 0);
      v392 = AdvXMLParser::Element::operator()("duration", 0);
      v688 = v392;
      v391 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v392 + 8))(v392, v835);
      v129 = (const char *)std::string::c_str(v391);
      v130 = j__atoi(v129);
      v816[6] = v130;
      std::string::~string(v835);
      v390 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v784);
      v389 = AdvXMLParser::Element::operator()("type", 0);
      v687 = v389;
      v388 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v389 + 8))(v389, v836);
      v387 = v388;
      LOBYTE(v919) = 84;
      v131 = (char *)std::string::c_str(v388);
      v205 = std::string::string(v911, v131);
      LOBYTE(v919) = 86;
      std::string::~string(v836);
      v132 = (char *)std::string::c_str(v911);
      v204 = std::string::string(v909, v132);
      LOBYTE(v919) = 87;
      v386 = CDefineTranslator::Instance();
      v385 = CDefineTranslator::GetValueOfDefine(v909);
      v816[5] = v385;
      LOBYTE(v919) = 86;
      std::string::~string(v909);
      v384 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v784);
      v383 = AdvXMLParser::Element::operator()("patch", 0);
      v382 = AdvXMLParser::Element::operator()("sound", 0);
      v381 = AdvXMLParser::Element::operator()("def", 0);
      v686 = v381;
      v380 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v381 + 8))(v381, v837);
      v379 = v380;
      LOBYTE(v919) = 88;
      v133 = (char *)std::string::c_str(v380);
      v203 = std::string::string(v910, v133);
      LOBYTE(v919) = 90;
      std::string::~string(v837);
      v378 = CConfigManagerPtr::GetInstance();
      v685 = v378;
      v134 = std::string::c_str(v910);
      v377 = ((int (__thiscall *)(CConfigManager *, int))v685->GetDefineValue)(v685, v134);
      *((_DWORD *)v816 + 2) = v377;
      if ( *((_DWORD *)v816 + 2) == -1 )
        *((_DWORD *)v816 + 2) = 0;
      v376 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v784);
      v375 = AdvXMLParser::Element::operator()("patch", 0);
      v374 = AdvXMLParser::Element::operator()("sound", 0);
      v373 = AdvXMLParser::Element::operator()("random", 0);
      v684 = v373;
      v372 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v373 + 8))(v373, v838);
      v135 = (const char *)std::string::c_str(v372);
      v136 = j__atoi(v135);
      v816[12] = v136;
      std::string::~string(v838);
      if ( !v816[12] )
        v816[12] = 100;
      v371 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v784);
      v370 = AdvXMLParser::Element::operator()("patch", 0);
      v369 = AdvXMLParser::Element::operator()("sound", 0);
      v368 = AdvXMLParser::Element::operator()("frame", 0);
      v683 = v368;
      v367 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v368 + 8))(v368, v839);
      v137 = (const char *)std::string::c_str(v367);
      v138 = j__atoi(v137);
      v816[13] = v138;
      std::string::~string(v839);
      v366 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v784);
      v365 = AdvXMLParser::Element::operator()("effect", 0);
      v364 = AdvXMLParser::Element::operator()("def", 0);
      v682 = v364;
      v363 = CConfigManagerPtr::GetInstance();
      v681 = v363;
      v362 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v682 + 8))(v682, v840);
      v361 = v362;
      LOBYTE(v919) = 91;
      v139 = std::string::c_str(v362);
      v360 = ((int (__thiscall *)(CConfigManager *, int))v681->GetDefineValue)(v681, v139);
      *((_DWORD *)v816 + 4) = v360;
      LOBYTE(v919) = 90;
      std::string::~string(v840);
      v359 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v784);
      v358 = AdvXMLParser::Element::operator()("effect", 0);
      v357 = AdvXMLParser::Element::operator()("x", 0);
      v680 = v357;
      v356 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v357 + 8))(v357, v841);
      v140 = (const char *)std::string::c_str(v356);
      v141 = j__atoi(v140);
      *((_WORD *)v816 + 10) = v141;
      std::string::~string(v841);
      v355 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v784);
      v354 = AdvXMLParser::Element::operator()("effect", 0);
      v353 = AdvXMLParser::Element::operator()("y", 0);
      v679 = v353;
      v352 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v353 + 8))(v353, v842);
      v142 = (const char *)std::string::c_str(v352);
      v143 = j__atoi(v142);
      *((_WORD *)v816 + 11) = v143;
      std::string::~string(v842);
      v351 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v784);
      v350 = AdvXMLParser::Element::operator()("effect", 0);
      v349 = AdvXMLParser::Element::operator()("smoke", 0);
      v678 = v349;
      v348 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v349 + 8))(v349, v843);
      v144 = (const char *)std::string::c_str(v348);
      v145 = j__atoi(v144);
      v816[25] = v145;
      std::string::~string(v843);
      v347 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v784);
      v282 = AdvXMLParser::Element::operator()("effect", 0);
      v345 = AdvXMLParser::Element::operator()("duration", 0);
      v677 = v345;
      v344 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v345 + 8))(v345, v844);
      v146 = (const char *)std::string::c_str(v344);
      v147 = j__atoi(v146);
      v816[24] = v147;
      std::string::~string(v844);
      v343 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v784);
      v342 = AdvXMLParser::Element::operator()("effect", 0);
      v341 = AdvXMLParser::Element::operator()("sound", 0);
      v340 = AdvXMLParser::Element::operator()("def", 0);
      v676 = v340;
      v339 = CConfigManagerPtr::GetInstance();
      v675 = v339;
      v338 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v676 + 8))(v676, v845);
      v337 = v338;
      LOBYTE(v919) = 92;
      v148 = std::string::c_str(v338);
      v336 = ((int (__thiscall *)(CConfigManager *, int))v675->GetDefineValue)(v675, v148);
      *((_DWORD *)v816 + 7) = v336;
      LOBYTE(v919) = 90;
      std::string::~string(v845);
      if ( *((_DWORD *)v816 + 7) == -1 )
        *((_DWORD *)v816 + 7) = 0;
      v335 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v784);
      v334 = AdvXMLParser::Element::operator()("effect", 0);
      v333 = AdvXMLParser::Element::operator()("sound", 0);
      v332 = AdvXMLParser::Element::operator()("random", 0);
      v674 = v332;
      v331 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v332 + 8))(v332, v846);
      v149 = (const char *)std::string::c_str(v331);
      v150 = j__atoi(v149);
      v816[32] = v150;
      std::string::~string(v846);
      if ( !v816[12] )
        v816[12] = 100;
      v330 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v784);
      v329 = AdvXMLParser::Element::operator()("effect", 0);
      v328 = AdvXMLParser::Element::operator()("sound", 0);
      v327 = AdvXMLParser::Element::operator()("frame", 0);
      v673 = v327;
      v326 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v327 + 8))(v327, v847);
      v151 = (const char *)std::string::c_str(v326);
      v152 = j__atoi(v151);
      v816[13] = v152;
      std::string::~string(v847);
      LOBYTE(v919) = 86;
      std::string::~string(v910);
      LOBYTE(v919) = 83;
      std::string::~string(v911);
      LOBYTE(v919) = 80;
      std::string::~string(v912);
      LOBYTE(v919) = 79;
      std::string::~string(v913);
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v784);
    }
    LOBYTE(v919) = 76;
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v177);
    LOBYTE(v919) = 73;
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v784);
    LOBYTE(v919) = 72;
    std::string::~string(v900);
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v218);
  }
  LOBYTE(v919) = 69;
  AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v176);
  LOBYTE(v919) = 66;
  AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v218);
  LOBYTE(v919) = 65;
  std::auto_ptr<AdvXMLParser::Document>::~auto_ptr<AdvXMLParser::Document>(v672);
  LOBYTE(v919) = 64;
  AdvXMLParser::Parser::~Parser(v159);
  v919 = -1;
  v325 = v795;
  return (char *)operator delete[](v795);
}


// address=[0x4033188]
// [Decompilation failed for static struct CBuildingInfoMgr::STriggerInfos (* CBuildingInfoMgr::m_vTriggerInfos)[47]]

// address=[0x4035294]
// [Decompilation failed for static bool CBuildingInfoMgr::m_bInit]

// address=[0x40352a0]
// [Decompilation failed for static struct CBuildingInfoMgr::SBuildingInfos (* CBuildingInfoMgr::m_vBuildingInfos)[83]]

