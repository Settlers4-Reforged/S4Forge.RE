#include "CAStarTiling.h"

// Definitions for class CAStarTiling

// address=[0x15d4050]
// Decompiled from int __cdecl CAStarTiling::FindPath(int a1, int a2, struct CWaypoints *a3, __int16 a4)

static int __cdecl CAStarTiling::FindPath(int,int,class CWaypoints &,int) {
  
  int v4; // eax
  int v5; // eax
  struct CTile *v7; // eax
  const struct CTile *v8; // eax
  Y16X16 *v9; // eax
  int v10; // eax
  _DWORD *v11; // eax
  int v12; // edx
  int v13; // eax
  int v14; // eax
  struct CTile *v15; // eax
  int v16; // eax
  struct CTile *v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  COpenListEntry16 *v21; // eax
  int v22; // eax
  const struct CTile *v23; // eax
  Y16X16 *v24; // eax
  const struct CTile *v25; // eax
  int v26; // eax
  const struct CTile *v27; // eax
  int v28; // eax
  int v29[2]; // [esp+0h] [ebp-81098h] BYREF
  _BYTE v30[8]; // [esp+8h] [ebp-81090h] BYREF
  int v31; // [esp+10h] [ebp-81088h]
  int v32; // [esp+14h] [ebp-81084h]
  int v33; // [esp+18h] [ebp-81080h]
  int v34; // [esp+1Ch] [ebp-8107Ch]
  int v35; // [esp+20h] [ebp-81078h]
  int v36; // [esp+24h] [ebp-81074h]
  BOOL v37; // [esp+28h] [ebp-81070h]
  BOOL v38; // [esp+2Ch] [ebp-8106Ch]
  _DWORD v39[2]; // [esp+30h] [ebp-81068h] BYREF
  BOOL v40; // [esp+38h] [ebp-81060h]
  BOOL v41; // [esp+3Ch] [ebp-8105Ch]
  int v42; // [esp+40h] [ebp-81058h]
  int v43; // [esp+44h] [ebp-81054h]
  int v44; // [esp+48h] [ebp-81050h]
  unsigned __int8 *v45; // [esp+4Ch] [ebp-8104Ch]
  unsigned int v46; // [esp+50h] [ebp-81048h]
  unsigned int v47; // [esp+54h] [ebp-81044h]
  int (__cdecl *v48)(int, int); // [esp+58h] [ebp-81040h]
  BOOL v49; // [esp+5Ch] [ebp-8103Ch]
  BOOL v50; // [esp+60h] [ebp-81038h]
  char v51[4]; // [esp+64h] [ebp-81034h] BYREF
  BOOL v52; // [esp+68h] [ebp-81030h]
  int v53; // [esp+6Ch] [ebp-8102Ch]
  int k; // [esp+70h] [ebp-81028h]
  int v55; // [esp+74h] [ebp-81024h]
  int v56; // [esp+78h] [ebp-81020h]
  int i; // [esp+7Ch] [ebp-8101Ch]
  int v58; // [esp+80h] [ebp-81018h]
  _crt_argv_mode j; // [esp+84h] [ebp-81014h]
  int v60; // [esp+88h] [ebp-81010h]
  char v61; // [esp+8Fh] [ebp-81009h]
  char v62[4096]; // [esp+90h] [ebp-81008h] BYREF
  _BYTE v63[262148]; // [esp+1090h] [ebp-80008h] BYREF
  _QWORD v64[32768]; // [esp+41094h] [ebp-40004h] BYREF

  if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(a1)
    && BBSupportDbgReport(2, "Pathing\\AStar.cpp", 1384, "g_cWorld.InWorldPackedXY(_iStartXY)") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(a2)
    && BBSupportDbgReport(2, "Pathing\\AStar.cpp", 1385, "g_cWorld.InWorldPackedXY(_iEndXY)") == 1 )
  {
    __debugbreak();
  }
  CWaypoints::Init(a3);
  dword_416C7A4 = a1;
  dword_416C7A8 = a2;
  v52 = (a4 & 0x700) == 512;
  CTileIdRef::CTileIdRef(v51, v52, 0);
  v4 = CWorldManager::Index(a1);
  dword_416C7AC = CTileIdRef::TileId((CTileIdRef *)v51, v4);
  v5 = CWorldManager::Index(a2);
  dword_416C7B0 = CTileIdRef::TileId((CTileIdRef *)v51, v5);
  if ( dword_416C7AC && (v50 = (a4 & 0x40) == 0, v49 = dword_416C7B0 == 0, !v49 || !v50) )
  {
    if ( dword_416C7AC == dword_416C7B0 )
    {
      CWaypoints::PushBack(a3, a2);
      return 1;
    }
    else
    {
      v48 = sub_15D4B80;
      if ( (a4 & 0x20) != 0 )
      {
        v48 = sub_15D4C30;
        dword_416C78C = CAlliances::AllianceId(a4 & 0xF);
      }
      dword_416C790 = v48;
      v47 = (a4 & 0x700) >> 8;
      if ( v47 > 7 && BBSupportDbgReport(2, "Pathing\\AStar.cpp", 1435, "uAStarMode <= ASTAR_MODE_LAST") == 1 )
        __debugbreak();
      v46 = v47;
      switch ( v47 )
      {
        case 0u:
          dword_416C7A0 = CTile::TileTypeOwnerCheckMask(a4 & 0xF, a4 & 0x10) | 0x2C000000;
          dword_416C794 = (int (__cdecl *)(_DWORD, _DWORD))__scrt_stub_for_initialize_mta_1;
          dword_416C798 = sub_15D4DD0;
          dword_416C79C = (int)&dword_416C7A0;
          break;
        case 1u:
          dword_416C7A0 = CTile::TileTypeOwnerCheckMask(a4 & 0xF, a4 & 0x10) | 0x1C000000;
          dword_416C794 = (int (__cdecl *)(_DWORD, _DWORD))__scrt_stub_for_initialize_mta_1;
          dword_416C798 = sub_15D4DD0;
          dword_416C79C = (int)&dword_416C7A0;
          break;
        case 2u:
          dword_416C7A0 = CTile::TileTypeOwnerCheckMask(a4 & 0xF, a4 & 0x10) | 0x34000000;
          dword_416C794 = (int (__cdecl *)(_DWORD, _DWORD))__scrt_stub_for_initialize_mta_1;
          dword_416C798 = sub_15D4DD0;
          dword_416C79C = (int)&dword_416C7A0;
          break;
        case 3u:
          dword_416C794 = sub_15D5170;
          dword_416C798 = sub_15D50B0;
          dword_416C79C = (int)&unk_37D7D28;
          break;
        case 4u:
          dword_416C794 = sub_15D51E0;
          dword_416C798 = sub_15D5000;
          dword_416C79C = (int)&unk_37D7D48;
          break;
        case 5u:
          dword_416C7A0 = 738197504;
          dword_416C794 = (int (__cdecl *)(_DWORD, _DWORD))__scrt_stub_for_initialize_mta_1;
          dword_416C798 = sub_15D4FD0;
          dword_416C79C = (int)&dword_416C7A0;
          dword_416C790 = sub_15D4CC0;
          dword_416C7B4 = a4 & 0xF;
          dword_416C7B8 = CAlliances::PlayerEnemyBits(a4 & 0xF);
          break;
        case 6u:
          dword_416C7A0 = 738197504;
          dword_416C794 = (int (__cdecl *)(_DWORD, _DWORD))__scrt_stub_for_initialize_mta_1;
          dword_416C798 = sub_15D4FD0;
          dword_416C79C = (int)&dword_416C7A0;
          dword_416C790 = sub_15D4D50;
          dword_416C7BC = CAlliances::PlayerAllyBits(a4 & 0xF);
          dword_416C7B8 = CAlliances::PlayerEnemyBits(a4 & 0xF);
          break;
        default:
          v35 = a4 & 0xF;
          v34 = CAlliances::PlayerAllyBits(v35);
          v33 = CTile::TileTypeOwnerCheckMaskFromPlayerBits(v34);
          dword_416C7A0 = v33 | 0x2C000000;
          dword_416C794 = (int (__cdecl *)(_DWORD, _DWORD))__scrt_stub_for_initialize_mta_1;
          dword_416C798 = sub_15D4DD0;
          dword_416C79C = (int)&dword_416C7A0;
          break;
      }
      v37 = dword_416C798 == sub_15D4DD0;
      v38 = (a4 & 0x80u) != 0;
      if ( v38 && v37 )
        dword_416C798 = (int (__cdecl *)(_DWORD, _DWORD))sub_15D4EA0;
      v7 = (struct CTile *)ITiling::Tile(dword_416C7AC);
      if ( (*(_DWORD *)dword_416C79C & CTile::Type(v7, v29[0])) != 0 )
      {
        CTrace::Print("AStarTiling::FindPath() failed: Start tile failed type check!");
        return 0;
      }
      else
      {
        TPriorityQueue<COpenListEntry16,32768>::TPriorityQueue<COpenListEntry16,32768>(v63);
        v58 = 0;
        if ( (a4 & 0x40) != 0 )
          v36 = 80;
        else
          v36 = 0;
        v43 = v36;
        TBitArray<32768>::ClearArray(v62);
        TBitArray<32768>::Set(dword_416C7AC);
        CG24Closed1Parent16::Set((CG24Closed1Parent16 *)&v64[dword_416C7AC], 0, 0, 0, 0);
        v8 = ITiling::Tile(dword_416C7AC);
        v9 = (Y16X16 *)CTile::CenterXY(v8);
        v10 = Y16X16::DistanceFast(v9, a2);
        COpenListEntry16::Set((COpenListEntry16 *)v30, dword_416C7AC, 0, v10);
        TPriorityQueue<COpenListEntry16,32768>::Push(v30);
        while ( !(unsigned __int8)TPriorityQueue<COpenListEntry16,32768>::Empty(v63) )
        {
          v11 = (_DWORD *)TPriorityQueue<COpenListEntry16,32768>::Top(v63);
          v12 = v11[1];
          v39[0] = *v11;
          v39[1] = v12;
          TPriorityQueue<COpenListEntry16,32768>::Pop(v63);
          v13 = COpenListEntry16::Index((COpenListEntry16 *)v39);
          CG24Closed1Parent16::SetClosedFlag((CG24Closed1Parent16 *)&v64[v13]);
          v56 = COpenListEntry16::Index((COpenListEntry16 *)v39);
          v31 = COpenListEntry16::G((COpenListEntry16 *)v39);
          v14 = COpenListEntry16::Index((COpenListEntry16 *)v39);
          v44 = CG24Closed1Parent16::State((CG24Closed1Parent16 *)&v64[v14]);
          v32 = *(_DWORD *)(dword_416C79C + 4 * v44);
          v15 = (struct CTile *)ITiling::Tile(v56);
          v45 = (unsigned __int8 *)CTile::LinkList(v15);
          for ( i = 0; ; ++i )
          {
            v16 = CLinkList::Size(v45);
            if ( i >= v16 )
              break;
            v60 = *(unsigned __int16 *)CLinkList::operator[](v45, i);
            v17 = (struct CTile *)ITiling::Tile(v60);
            v18 = CTile::Type(v17, v29[0]);
            if ( (v32 & v18) == 0 )
            {
              v19 = dword_416C790(v56, v60);
              v55 = v31 + v19;
              if ( v60 == dword_416C7B0 )
              {
                CG24Closed1Parent16::Set((CG24Closed1Parent16 *)&v64[v60], v55, v56, 0, 0);
                return dword_416C798(v64, a3);
              }
              v61 = 0;
              v42 = dword_416C794(v44, v60);
              if ( v42 != 7 )
              {
                if ( (unsigned __int8)TBitArray<32768>::operator[](v60) )
                {
                  v20 = CG24Closed1Parent16::G((CG24Closed1Parent16 *)&v64[v60]);
                  if ( v55 < v20 )
                  {
                    v61 = 1;
                    if ( !CG24Closed1Parent16::Closed((CG24Closed1Parent16 *)&v64[v60]) )
                    {
                      for ( j = TPriorityQueue<COpenListEntry16,32768>::Last(v63);
                            j >= TPriorityQueue<COpenListEntry16,32768>::First();
                            --j )
                      {
                        v21 = (COpenListEntry16 *)TPriorityQueue<COpenListEntry16,32768>::operator[](j);
                        v22 = COpenListEntry16::Index(v21);
                        if ( v22 == v60 )
                          break;
                      }
                      if ( j > _crt_argv_no_arguments )
                        TPriorityQueue<COpenListEntry16,32768>::Remove(j);
                    }
                  }
                }
                else
                {
                  v61 = 1;
                }
              }
              if ( v61 )
              {
                v23 = ITiling::Tile(v60);
                v24 = (Y16X16 *)CTile::CenterXY(v23);
                v53 = Y16X16::DistanceFast(v24, a2);
                if ( v53 < v43 )
                {
                  v58 = v60;
                  v43 = v53;
                }
                COpenListEntry16::Set((COpenListEntry16 *)v29, v60, v55, v53);
                TPriorityQueue<COpenListEntry16,32768>::Push(v29);
                TBitArray<32768>::Set(v60);
                CG24Closed1Parent16::Set((CG24Closed1Parent16 *)&v64[v60], v55, v56, 0, v42);
              }
            }
          }
        }
        v41 = v58 != 0;
        v40 = v58 != dword_416C7AC;
        if ( v40 && v41 )
        {
          v25 = ITiling::Tile(v58);
          v26 = CTile::CenterXY(v25);
          CWaypoints::PushGoal(a3, v26, 0);
          for ( k = v58; k != dword_416C7AC; k = CG24Closed1Parent16::Parent((CG24Closed1Parent16 *)&v64[k]) )
          {
            v27 = ITiling::Tile(k);
            v28 = CTile::CenterXY(v27);
            CWaypoints::PushBack(a3, v28);
          }
          return -1;
        }
        else
        {
          CTrace::Print("AStarTiling::FindPath() failed: No path found!");
          return 0;
        }
      }
    }
  }
  else
  {
    CTrace::Print("AStarTiling::FindPath() failed: Invalid start or end tile.");
    return 0;
  }
}


