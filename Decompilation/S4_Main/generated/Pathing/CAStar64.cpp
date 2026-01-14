#include "all_headers.h"

// Definitions for class CAStar64

// address=[0x15d3820]
// Decompiled from char __thiscall CAStar64::FindPath(CAStar64 *this, int a2, int a3, struct CDirCache *a4)
bool  CAStar64::FindPath(int,int,class CDirCache &) {
  
  _DWORD *v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // eax
  int v9; // esi
  _DWORD *v10; // eax
  int v11; // edx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // esi
  int v16; // eax
  int v17; // [esp-4h] [ebp-74h]
  Grid *v18; // [esp-4h] [ebp-74h]
  _BYTE v19[8]; // [esp+4h] [ebp-6Ch] BYREF
  _BYTE v20[8]; // [esp+Ch] [ebp-64h] BYREF
  _DWORD v21[2]; // [esp+14h] [ebp-5Ch] BYREF
  _DWORD v22[2]; // [esp+1Ch] [ebp-54h] BYREF
  int v23; // [esp+24h] [ebp-4Ch]
  int v24; // [esp+28h] [ebp-48h]
  int v25; // [esp+2Ch] [ebp-44h]
  int v26; // [esp+30h] [ebp-40h]
  int v27; // [esp+34h] [ebp-3Ch]
  int v28; // [esp+38h] [ebp-38h]
  BOOL v29; // [esp+3Ch] [ebp-34h]
  int v30; // [esp+40h] [ebp-30h]
  int v31; // [esp+44h] [ebp-2Ch]
  int v32; // [esp+48h] [ebp-28h]
  CAStar64 *v33; // [esp+4Ch] [ebp-24h]
  int v34; // [esp+50h] [ebp-20h]
  int v35; // [esp+54h] [ebp-1Ch]
  int v36; // [esp+58h] [ebp-18h]
  int v37; // [esp+5Ch] [ebp-14h]
  Grid *v38; // [esp+60h] [ebp-10h]
  int i; // [esp+64h] [ebp-Ch]
  int v40; // [esp+68h] [ebp-8h]
  int v41; // [esp+6Ch] [ebp-4h]

  v33 = this;
  CDirCache::Init(a4);
  dword_415C76C = 0;
  dword_415C770 = 0;
  if ( (unsigned __int8)sub_15D5300(a2, a3) )
  {
    if ( (**(unsigned __int8 (__thiscall ***)(CAStar64 *))v33)(v33) )
    {
      if ( !dword_415C76C && BBSupportDbgReport(2, "Pathing\\AStar.cpp", 1999, "s_pIsNotBlocked != 0") == 1 )
        __debugbreak();
      if ( !dword_415C770 && BBSupportDbgReport(2, "Pathing\\AStar.cpp", 2000, "s_pMoveCost != 0") == 1 )
        __debugbreak();
      v5 = (_DWORD *)TPriorityQueue<COpenListEntry24,8192>::Top(&unk_415C788);
      v6 = v5[1];
      v21[0] = *v5;
      v21[1] = v6;
      TPriorityQueue<COpenListEntry24,8192>::Pop(&unk_415C788);
      v26 = COpenListEntry24::Index((COpenListEntry24 *)v21);
      for ( i = 0; i < 6; ++i )
      {
        v7 = CY6R1X6::NeighborRelPackedIdx(i);
        v40 = v26 + v7;
        if ( CY6R1X6::Valid(v26 + v7) )
        {
          if ( v40 == dword_4174BC8 )
          {
            v17 = i;
            v8 = COpenListEntry24::G((COpenListEntry24 *)v21);
            CG24Closed1Parent7::Set((CG24Closed1Parent7 *)((char *)&unk_416CBC0 + 4 * v40), v8, 0, v17);
            sub_15D5530(a4);
            return 1;
          }
          v32 = dword_4174BC0 + CY6R1X6::WorldIdx(v40);
          if ( (unsigned __int8)dword_415C76C(v32) )
          {
            v9 = COpenListEntry24::G((COpenListEntry24 *)v21);
            v31 = v9 + 8 * dword_415C770(v32, 0) + 1;
            TBitArray<8192>::Set(v40);
            CG24Closed1Parent7::Set((CG24Closed1Parent7 *)((char *)&unk_416CBC0 + 4 * v40), v31, 0, i);
            v25 = sub_15D55C0(v40, dword_4174BC8);
            COpenListEntry24::Set((COpenListEntry24 *)v20, v40, v31, v25);
            TPriorityQueue<COpenListEntry24,8192>::Push(v20);
          }
        }
      }
      v35 = 3;
      while ( !(unsigned __int8)TPriorityQueue<COpenListEntry24,8192>::Empty(&unk_415C788) )
      {
        v10 = (_DWORD *)TPriorityQueue<COpenListEntry24,8192>::Top(&unk_415C788);
        v11 = v10[1];
        v22[0] = *v10;
        v22[1] = v11;
        TPriorityQueue<COpenListEntry24,8192>::Pop(&unk_415C788);
        v34 = COpenListEntry24::Index((COpenListEntry24 *)v22);
        CG24Closed1Parent7::SetClosedFlag((CG24Closed1Parent7 *)((char *)&unk_416CBC0 + 4 * v34));
        v30 = CG24Closed1Parent7::Parent((CG24Closed1Parent7 *)((char *)&unk_416CBC0 + 4 * v34));
        v38 = (Grid *)Grid::TurnLeft((Grid *)(v30 & 7));
        while ( v35 > 0 )
        {
          v12 = CY6R1X6::NeighborRelPackedIdx(v38);
          v41 = v34 + v12;
          if ( CY6R1X6::Valid(v34 + v12) )
          {
            if ( v41 == dword_4174BC8 )
            {
              v18 = v38;
              v13 = COpenListEntry24::G((COpenListEntry24 *)v22);
              CG24Closed1Parent7::Set((CG24Closed1Parent7 *)((char *)&unk_416CBC0 + 4 * v41), v13, 0, v18);
              sub_15D5530(a4);
              return 1;
            }
            v27 = dword_4174BC0 + CY6R1X6::WorldIdx(v41);
            if ( (unsigned __int8)dword_415C76C(v27) )
            {
              v37 = (int)v38 - v30;
              v37 += v37 < 0 ? 6 : 0;
              v24 = dword_37D81B0[v37];
              LOBYTE(v28) = COpenListEntry24::G((COpenListEntry24 *)v22) & 7;
              v28 = (unsigned __int8)v28;
              v29 = (unsigned __int8)v28 != 7;
              v14 = COpenListEntry24::G((COpenListEntry24 *)v22);
              v15 = v29 + v14;
              v16 = dword_415C770(v27, v28);
              v36 = v15 + 8 * (v24 + v16);
              if ( v36 >= 0x100000 && BBSupportDbgReport(2, "Pathing\\AStar.cpp", 2111, "iNeighborG < (1 << 20)") == 1 )
                __debugbreak();
              if ( (unsigned __int8)sub_15D55E0(v41, v36) )
              {
                TBitArray<8192>::Set(v41);
                CG24Closed1Parent7::Set((CG24Closed1Parent7 *)((char *)&unk_416CBC0 + 4 * v41), v36, 0, v38);
                v23 = sub_15D55C0(v41, dword_4174BC8);
                COpenListEntry24::Set((COpenListEntry24 *)v19, v41, v36, v23);
                TPriorityQueue<COpenListEntry24,8192>::Push(v19);
              }
            }
          }
          --v35;
          v38 = (Grid *)Grid::TurnRight(v38);
        }
        v35 = 3;
      }
      BBSupportTracePrintF(0, "CAStar64::FindPath() failed, because no path was found!");
      return 0;
    }
    else
    {
      BBSupportTracePrintF(0, "CAStar64::FindPath() failed, because CAStar64::InitFindPath() failed!");
      return 0;
    }
  }
  else
  {
    BBSupportTracePrintF(0, "CAStar64::FindPath() failed, because CAStar64::Init() failed!");
    return 0;
  }
}


// address=[0x15d5ea0]
// Decompiled from CAStar64 *__thiscall CAStar64::CAStar64(CAStar64 *this)
 CAStar64::CAStar64(void) {
  
  *(_DWORD *)this = &CAStar64::_vftable_;
  return this;
}


// address=[0x15d6de0]
// Decompiled from int __cdecl CAStar64::SettlerDisplacementCosts(int a1, int a2)
static int __cdecl CAStar64::SettlerDisplacementCosts(int,int) {
  
  int v2; // eax
  IMovingEntity *v4; // [esp+0h] [ebp-Ch]
  int v6; // [esp+8h] [ebp-4h]

  v2 = CWorldManager::SettlerId(a1);
  v4 = (IMovingEntity *)CMapObjectMgr::EntityPtr(v2);
  v6 = 1 << IMovingEntity::DisplacementCosts(v4) >> (a2 >> 1);
  if ( v6 <= 256 )
    return v6;
  else
    return 256;
}


// address=[0x15d7130]
// Decompiled from int __cdecl CAStar64::WorldMoveCosts(int a1)
static int __cdecl CAStar64::WorldMoveCosts(int) {
  
  return 4 * CWorldManager::MoveCostsBits(a1) + 8;
}


// address=[0x15d7150]
// Decompiled from int __cdecl CAStar64::WorldMoveCostsNoRoad(int a1)
static int __cdecl CAStar64::WorldMoveCostsNoRoad(int) {
  
  return 4 * (CWorldManager::MoveCostsBits(a1) | 2) + 8;
}


