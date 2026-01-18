#include "CBuildingManagerTask.h"

// Definitions for class CBuildingManagerTask

// address=[0x2f4f710]
// Decompiled from CBuildingManagerTask *__thiscall CBuildingManagerTask::CBuildingManagerTask(CBuildingManagerTask *this)
 CBuildingManagerTask::CBuildingManagerTask(void) {
  
  _DWORD *v1; // eax
  _DWORD *v2; // ecx
  _DWORD *v3; // eax
  _DWORD *v4; // ecx
  _DWORD *v5; // eax
  _DWORD *v6; // edx
  _DWORD *v7; // eax
  _DWORD *v8; // ecx
  _DWORD *v9; // eax
  _DWORD *v10; // edx
  _DWORD *v11; // eax
  _DWORD *v12; // ecx
  _DWORD *v13; // eax
  _DWORD *v14; // ecx
  _DWORD *v15; // eax
  _DWORD *v16; // edx
  _DWORD *v17; // eax
  _DWORD *v18; // ecx
  _DWORD *v19; // eax
  _DWORD *v20; // edx
  _DWORD *v21; // eax
  _DWORD *v22; // ecx
  _DWORD v24[4]; // [esp+4h] [ebp-F0h] BYREF
  _DWORD v25[4]; // [esp+14h] [ebp-E0h] BYREF
  _DWORD v26[4]; // [esp+24h] [ebp-D0h] BYREF
  _DWORD v27[4]; // [esp+34h] [ebp-C0h] BYREF
  _DWORD v28[4]; // [esp+44h] [ebp-B0h] BYREF
  _DWORD v29[4]; // [esp+54h] [ebp-A0h] BYREF
  _DWORD v30[4]; // [esp+64h] [ebp-90h] BYREF
  _DWORD v31[4]; // [esp+74h] [ebp-80h] BYREF
  _DWORD v32[4]; // [esp+84h] [ebp-70h] BYREF
  _DWORD v33[4]; // [esp+94h] [ebp-60h] BYREF
  _DWORD v34[6]; // [esp+A4h] [ebp-50h] BYREF
  _DWORD *v35; // [esp+BCh] [ebp-38h]
  _DWORD *v36; // [esp+C0h] [ebp-34h]
  _DWORD *v37; // [esp+C4h] [ebp-30h]
  _DWORD *v38; // [esp+C8h] [ebp-2Ch]
  _DWORD *v39; // [esp+CCh] [ebp-28h]
  _DWORD *v40; // [esp+D0h] [ebp-24h]
  _DWORD *v41; // [esp+D4h] [ebp-20h]
  _DWORD *v42; // [esp+D8h] [ebp-1Ch]
  _DWORD *v43; // [esp+DCh] [ebp-18h]
  int i; // [esp+E0h] [ebp-14h]
  CBuildingManagerTask *v45; // [esp+E4h] [ebp-10h]
  int v46; // [esp+F0h] [ebp-4h]

  v45 = this;
  IScheduleEntry::IScheduleEntry(this);
  v46 = 0;
  *(_DWORD *)v45 = &CBuildingManagerTask::_vftable_;
  _vec_ctor((char *)v45 + 96, 0x10u, 0xBu, CRequire::CRequire, CRequire::~CRequire);
  LOBYTE(v46) = 1;
  *((_DWORD *)v45 + 4) = 3;
  *((_DWORD *)v45 + 22) = 0;
  *((_DWORD *)v45 + 5) = 2;
  *((_DWORD *)v45 + 13) = 2;
  *((_DWORD *)v45 + 15) = 0;
  *((_DWORD *)v45 + 14) = 0;
  *((_DWORD *)v45 + 12) = 0;
  v43 = CRequire::CRequire(v34, 7);
  v1 = (_DWORD *)((char *)v45 + 96);
  v2 = v43;
  *((_DWORD *)v45 + 24) = *v43;
  v1[1] = v2[1];
  v1[2] = v2[2];
  v1[3] = v2[3];
  CRequire::~CRequire(v34);
  v3 = CRequire::CRequire(v33, 32);
  v42 = v3;
  v4 = (_DWORD *)((char *)v45 + 112);
  *((_DWORD *)v45 + 28) = *v3;
  v4[1] = v3[1];
  v4[2] = v3[2];
  v4[3] = v3[3];
  CRequire::~CRequire(v33);
  v5 = CRequire::CRequire(v32, 14);
  v41 = v5;
  v6 = (_DWORD *)((char *)v45 + 128);
  *((_DWORD *)v45 + 32) = *v5;
  v6[1] = v5[1];
  v6[2] = v5[2];
  v6[3] = v5[3];
  CRequire::~CRequire(v32);
  v7 = CRequire::CRequire(v31, 4);
  v40 = v7;
  v8 = (_DWORD *)((char *)v45 + 144);
  *((_DWORD *)v45 + 36) = *v7;
  v8[1] = v7[1];
  v8[2] = v7[2];
  v8[3] = v7[3];
  CRequire::~CRequire(v31);
  v9 = CRequire::CRequire(v30, 18);
  v39 = v9;
  v10 = (_DWORD *)((char *)v45 + 160);
  *((_DWORD *)v45 + 40) = *v9;
  v10[1] = v9[1];
  v10[2] = v9[2];
  v10[3] = v9[3];
  CRequire::~CRequire(v30);
  v11 = CRequire::CRequire(v29, 25);
  v38 = v11;
  v12 = (_DWORD *)((char *)v45 + 176);
  *((_DWORD *)v45 + 44) = *v11;
  v12[1] = v11[1];
  v12[2] = v11[2];
  v12[3] = v11[3];
  CRequire::~CRequire(v29);
  v37 = CRequire::CRequire(v28, 31);
  v13 = (_DWORD *)((char *)v45 + 192);
  v14 = v37;
  *((_DWORD *)v45 + 48) = *v37;
  v13[1] = v14[1];
  v13[2] = v14[2];
  v13[3] = v14[3];
  CRequire::~CRequire(v28);
  v15 = CRequire::CRequire(v27, 28);
  v36 = v15;
  v16 = (_DWORD *)((char *)v45 + 208);
  *((_DWORD *)v45 + 52) = *v15;
  v16[1] = v15[1];
  v16[2] = v15[2];
  v16[3] = v15[3];
  CRequire::~CRequire(v27);
  v35 = CRequire::CRequire(v26, 29);
  v17 = (_DWORD *)((char *)v45 + 224);
  v18 = v35;
  *((_DWORD *)v45 + 56) = *v35;
  v17[1] = v18[1];
  v17[2] = v18[2];
  v17[3] = v18[3];
  CRequire::~CRequire(v26);
  v19 = CRequire::CRequire(v25, 27);
  v34[5] = v19;
  v20 = (_DWORD *)((char *)v45 + 240);
  *((_DWORD *)v45 + 60) = *v19;
  v20[1] = v19[1];
  v20[2] = v19[2];
  v20[3] = v19[3];
  CRequire::~CRequire(v25);
  v21 = CRequire::CRequire(v24, 8);
  v34[4] = v21;
  v22 = (_DWORD *)((char *)v45 + 256);
  *((_DWORD *)v45 + 64) = *v21;
  v22[1] = v21[1];
  v22[2] = v21[2];
  v22[3] = v21[3];
  CRequire::~CRequire(v24);
  *((_DWORD *)v45 + 23) = 0;
  for ( i = 0; i < 5; ++i )
    *((_DWORD *)v45 + i + 68) = 0;
  for ( i = 0; i < 10; ++i )
    *((_DWORD *)v45 + i + 73) = 0;
  return v45;
}


// address=[0x2f4fb00]
// Decompiled from void __thiscall CBuildingManagerTask::~CBuildingManagerTask(CBuildingManagerTask *this)
 CBuildingManagerTask::~CBuildingManagerTask(void) {
  
  *(_DWORD *)this = &CBuildingManagerTask::_vftable_;
  `eh vector destructor iterator'((char *)this + 96, 0x10u, 0xBu, CRequire::~CRequire);
  IScheduleEntry::~IScheduleEntry(this);
}


// address=[0x2f4fb60]
// Decompiled from char __thiscall CBuildingManagerTask::IsShooting(CSchedule **this)
bool  CBuildingManagerTask::IsShooting(void) {
  
  _DWORD *v2; // eax
  int v3; // eax
  int v4; // eax
  _BYTE v5[16]; // [esp+8h] [ebp-48h] BYREF
  struct IAIEcoManager *v6; // [esp+18h] [ebp-38h]
  struct IAIEcoManager *v7; // [esp+1Ch] [ebp-34h]
  struct IAIEcoManager *v8; // [esp+20h] [ebp-30h]
  struct IAIEcoManager *v9; // [esp+24h] [ebp-2Ch]
  struct IAIEcoManager *v10; // [esp+28h] [ebp-28h]
  struct IAIEcoManager *v11; // [esp+2Ch] [ebp-24h]
  struct IAIEcoManager *EcoSector; // [esp+30h] [ebp-20h]
  CSchedule *v13; // [esp+34h] [ebp-1Ch]
  int i; // [esp+38h] [ebp-18h]
  CSchedule **v15; // [esp+3Ch] [ebp-14h]
  char v16; // [esp+42h] [ebp-Eh]
  char v17; // [esp+43h] [ebp-Dh]
  int v18; // [esp+4Ch] [ebp-4h]

  v15 = this;
  std::vector<int>::vector<int>(v5);
  v18 = 0;
  std::vector<int>::clear();
  CBuildingManagerTask::UpdateRequireGoods((CBuildingManagerTask *)v15, 1);
  if ( CSchedule::GetNumberOfBuildingType(v15[10], 21) || CSchedule::GetNumberOfBuildingType(v15[10], 20) <= 0 )
  {
    EcoSector = CSchedule::GetEcoSector(v15[10]);
    if ( (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)EcoSector + 156))(EcoSector, 21) > 0
      && !v15[23] )
    {
      v11 = CSchedule::GetEcoSector(v15[10]);
      (*(void (__thiscall **)(struct IAIEcoManager *, int, _BYTE *))(*(_DWORD *)v11 + 160))(v11, 21, v5);
      if ( std::vector<int>::size(v5) )
      {
        v10 = CSchedule::GetEcoSector(v15[10]);
        v2 = (_DWORD *)std::vector<int>::operator[](0);
        if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v10 + 76))(v10, *v2) )
          v15[23] = *(CSchedule **)std::vector<int>::operator[](0);
      }
    }
    for ( i = 0; i < 11; ++i )
    {
      if ( (int)v15[4 * i + 25] > (int)v15[4 * i + 26] )
      {
        v13 = v15[4 * i + 24];
        v13 = (CSchedule *)((char *)v13 - 4);
        switch ( (unsigned int)v13 )
        {
          case 0u:
          case 0x15u:
          case 0x17u:
          case 0x18u:
          case 0x19u:
          case 0x1Bu:
            goto LABEL_15;
          case 0xEu:
            v9 = CSchedule::GetEcoSector(v15[10]);
            v8 = CSchedule::GetEcoSector(v15[10]);
            v7 = CSchedule::GetEcoSector(v15[10]);
            v3 = (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v9 + 128))(v9, 0);
            v4 = (*(int (__thiscall **)(struct IAIEcoManager *, int, int))(*(_DWORD *)v8 + 132))(v8, 3, v3);
            (*(void (__thiscall **)(struct IAIEcoManager *, int, int))(*(_DWORD *)v7 + 280))(v7, 5027, v4);
LABEL_15:
            if ( v15[23] )
            {
              v6 = CSchedule::GetEcoSector(v15[10]);
              (*(void (__thiscall **)(struct IAIEcoManager *, CSchedule *, CSchedule *, int))(*(_DWORD *)v6 + 268))(
                v6,
                v15[23],
                v15[4 * i + 24],
                v15[4 * i + 25] - v15[4 * i + 26]);
            }
            break;
          default:
            continue;
        }
      }
    }
    v16 = 0;
    v18 = -1;
    std::vector<int>::~vector<int>();
    return v16;
  }
  else
  {
    v17 = 1;
    v18 = -1;
    std::vector<int>::~vector<int>();
    return v17;
  }
}


// address=[0x2f4fe10]
// Decompiled from char __thiscall CBuildingManagerTask::action(CSchedule **this)
bool  CBuildingManagerTask::action(void) {
  
  int GoodPositionForBuilding; // [esp+8h] [ebp-1Ch]
  struct IScheduleEntry *v3; // [esp+Ch] [ebp-18h]
  CMainProblemSolveEvent *C; // [esp+10h] [ebp-14h]

  GoodPositionForBuilding = CSchedule::GetGoodPositionForBuilding(this[10], 21);
  C = (CMainProblemSolveEvent *)operator new(0x70u);
  if ( C )
    v3 = CMainProblemSolveEvent::CMainProblemSolveEvent(C, this[3], 9, 21, GoodPositionForBuilding, 0, 0);
  else
    v3 = 0;
  this[8] = (CSchedule *)CSchedule::NewSchedEntry(this[10], v3);
  this[5] = (CSchedule *)1;
  return 0;
}


// address=[0x2f4fed0]
// Decompiled from char __thiscall CBuildingManagerTask::IsAlive(CBuildingManagerTask *this)
bool  CBuildingManagerTask::IsAlive(void) {
  
  return 1;
}


// address=[0x2f4fee0]
// Decompiled from bool __thiscall CBuildingManagerTask::WaitFor(CBuildingManagerTask *this)
bool  CBuildingManagerTask::WaitFor(void) {
  
  CBuildingManagerTask::UpdateRequireGoods(this, 0);
  return *((_DWORD *)this + 22) != 0;
}


// address=[0x2f4ff10]
// Decompiled from char __thiscall CBuildingManagerTask::UpdateRequireGoods(CBuildingManagerTask *this, bool a2)
void  CBuildingManagerTask::UpdateRequireGoods(bool a2) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  struct IAIEcoManager *v8; // [esp+8h] [ebp-A8h]
  struct IAIEcoManager *v9; // [esp+Ch] [ebp-A4h]
  struct IAIEcoManager *v10; // [esp+10h] [ebp-A0h]
  struct IAIEcoManager *v11; // [esp+14h] [ebp-9Ch]
  struct IAIEcoManager *v12; // [esp+18h] [ebp-98h]
  struct IAIEcoManager *v13; // [esp+1Ch] [ebp-94h]
  struct IAIEcoManager *v14; // [esp+20h] [ebp-90h]
  struct IAIEcoManager *v15; // [esp+24h] [ebp-8Ch]
  struct IAIEcoManager *v16; // [esp+28h] [ebp-88h]
  struct IAIEcoManager *v17; // [esp+2Ch] [ebp-84h]
  struct IAIEcoManager *v18; // [esp+30h] [ebp-80h]
  struct IAIEcoManager *v19; // [esp+34h] [ebp-7Ch]
  struct IAIEcoManager *v20; // [esp+38h] [ebp-78h]
  struct IAIEcoManager *v21; // [esp+3Ch] [ebp-74h]
  struct IAIEcoManager *v22; // [esp+40h] [ebp-70h]
  struct IAIEcoManager *v23; // [esp+44h] [ebp-6Ch]
  struct IAIEcoManager *v24; // [esp+48h] [ebp-68h]
  _DWORD *v25; // [esp+4Ch] [ebp-64h]
  struct IAIEcoManager *v26; // [esp+50h] [ebp-60h]
  struct IAIEcoManager *v27; // [esp+54h] [ebp-5Ch]
  _DWORD *v28; // [esp+58h] [ebp-58h]
  int v29; // [esp+5Ch] [ebp-54h]
  struct IAIEcoManager *v30; // [esp+60h] [ebp-50h]
  struct IAIEcoManager *v31; // [esp+64h] [ebp-4Ch]
  struct IAIEcoManager *v32; // [esp+68h] [ebp-48h]
  struct IAIEcoManager *v33; // [esp+6Ch] [ebp-44h]
  struct IAIEcoManager *v34; // [esp+70h] [ebp-40h]
  struct IAIEcoManager *v35; // [esp+74h] [ebp-3Ch]
  struct IAIEcoManager *v36; // [esp+78h] [ebp-38h]
  struct IAIEcoManager *EcoSector; // [esp+7Ch] [ebp-34h]
  int v38; // [esp+80h] [ebp-30h]
  int v39; // [esp+84h] [ebp-2Ch]
  int v40; // [esp+88h] [ebp-28h]
  int v41; // [esp+8Ch] [ebp-24h]
  int Tool; // [esp+90h] [ebp-20h]
  int v43; // [esp+90h] [ebp-20h]
  int v44; // [esp+94h] [ebp-1Ch]
  int i; // [esp+9Ch] [ebp-14h]
  int j; // [esp+9Ch] [ebp-14h]
  char v47; // [esp+A3h] [ebp-Dh]
  struct CDynListEntry *ProductivityControll; // [esp+A4h] [ebp-Ch]
  int k; // [esp+A8h] [ebp-8h]
  int m; // [esp+A8h] [ebp-8h]

  *((_DWORD *)this + 12) = 0;
  EcoSector = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
  *((_DWORD *)this + 21) = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)EcoSector + 152))(
                             EcoSector,
                             2);
  v36 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
  *((_DWORD *)this + 20) = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v36 + 152))(v36, 3);
  v35 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
  *((_DWORD *)this + 19) = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v35 + 152))(v35, 1);
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  if ( *((_DWORD *)this + 23) )
  {
    v34 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
    if ( !(*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v34 + 304))(
            v34,
            *((_DWORD *)this + 23)) )
      *((_DWORD *)this + 23) = 0;
  }
  for ( i = 0; i < 11; ++i )
  {
    *((_DWORD *)this + 4 * i + 25) = 0;
    v33 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
    *((_DWORD *)this + 4 * i + 26) = (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v33 + 144))(
                                       v33,
                                       *((_DWORD *)this + 4 * i + 24));
  }
  for ( j = 0; j < CDynList::size(*(CDynList **)(*((_DWORD *)this + 10) + 4)); ++j )
  {
    v44 = CDynList::elementAt(*(CDynList **)(*((_DWORD *)this + 10) + 4), j);
    if ( *(_DWORD *)(v44 + 20) != 3 )
    {
      if ( *(_DWORD *)(v44 + 16) == 9 )
      {
        if ( *(_DWORD *)(v44 + 52) == 1 )
        {
          for ( k = 0; k < 3; ++k )
          {
            v32 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
            *((_DWORD *)this + 4 * k + 25) += (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD, int))(*(_DWORD *)v32 + 60))(
                                                v32,
                                                *(_DWORD *)(v44 + 44),
                                                k);
          }
        }
        else
        {
          v31 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
          if ( !(*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v31 + 304))(
                  v31,
                  *(_DWORD *)(v44 + 48)) )
            continue;
          ++*((_DWORD *)this + 12);
          v47 = 1;
          for ( m = 0; m < 3; ++m )
          {
            v30 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
            v29 = (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD, int))(*(_DWORD *)v30 + 64))(
                    v30,
                    *(_DWORD *)(v44 + 48),
                    m);
            *((_DWORD *)this + 4 * m + 25) += v29;
            if ( v29 > 0 )
              v47 = 0;
          }
          if ( v47 )
          {
            ++*((_DWORD *)this + 16);
            ++*((_DWORD *)this + 17);
          }
          else
          {
            ++*((_DWORD *)this + 18);
          }
        }
        Tool = CProductionDataTab::GetTool(*(void **)(*((_DWORD *)this + 10) + 40), *(_DWORD *)(v44 + 44));
        if ( Tool )
        {
          ProductivityControll = CSchedule::GetProductivityControll(
                                   *((CDynList ***)this + 10),
                                   *(_DWORD *)(v44 + 48),
                                   *(_DWORD *)(v44 + 52));
          if ( ProductivityControll )
          {
            if ( !*((_BYTE *)ProductivityControll + 101) && *((_DWORD *)this + 23) )
            {
              if ( a2 )
                *((_BYTE *)ProductivityControll + 101) = 1;
              v28 = (_DWORD *)((char *)this + 16 * CBuildingManagerTask::GetToolRequireIndex(this, Tool) + 100);
              ++*v28;
            }
          }
        }
      }
      if ( *(_DWORD *)(v44 + 16) == 2 && *(_DWORD *)(v44 + 48) == 3 )
      {
        v27 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
        if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v27 + 304))(
               v27,
               *(_DWORD *)(v44 + 44)) )
        {
          if ( !*(_BYTE *)(v44 + 101) )
          {
            if ( *((_DWORD *)this + 23) )
            {
              v43 = CProductionDataTab::GetTool(*(void **)(*((_DWORD *)this + 10) + 40), *(_DWORD *)(v44 + 84));
              if ( v43 )
              {
                CProductionDataTab::GetNeededSettler(*(void **)(*((_DWORD *)this + 10) + 40), *(_DWORD *)(v44 + 84));
                v26 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
                if ( !(*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v26 + 84))(
                        v26,
                        *(_DWORD *)(v44 + 44)) )
                {
                  v25 = (_DWORD *)((char *)this + 16 * CBuildingManagerTask::GetToolRequireIndex(this, v43) + 100);
                  ++*v25;
                  if ( a2 )
                    *(_BYTE *)(v44 + 101) = 1;
                }
              }
            }
          }
        }
      }
    }
  }
  if ( CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 10), 21) )
  {
    v40 = 10 - *((_DWORD *)this + 21);
    v38 = 15 - *((_DWORD *)this + 20);
    if ( *((_DWORD *)this + 23) )
    {
      v24 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
      (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD, int, int))(*(_DWORD *)v24 + 268))(
        v24,
        *((_DWORD *)this + 23),
        31,
        v40 - *((_DWORD *)this + 21));
    }
    if ( *((_DWORD *)this + 23) )
    {
      v23 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
      (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD, int, int))(*(_DWORD *)v23 + 268))(
        v23,
        *((_DWORD *)this + 23),
        18,
        v38 - *((_DWORD *)this + 20));
    }
  }
  else
  {
    v40 = 7;
    v38 = 7;
  }
  if ( *((_DWORD *)this + 21) < v40 )
  {
    v22 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
    if ( !(*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v22 + 148))(v22, 2) )
    {
      v21 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
      v41 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v21 + 144))(v21, 31);
      if ( v41 <= 0 )
      {
        if ( *((_DWORD *)this + 23) )
        {
          v17 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
          (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD, int, int))(*(_DWORD *)v17 + 268))(
            v17,
            *((_DWORD *)this + 23),
            31,
            v40 - *((_DWORD *)this + 21));
        }
      }
      else
      {
        if ( v41 > 5 )
          v41 = 5;
        v20 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
        v19 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
        v18 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
        v2 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v20 + 128))(v20, v41);
        v3 = (*(int (__thiscall **)(struct IAIEcoManager *, int, int))(*(_DWORD *)v19 + 132))(v19, 2, v2);
        (*(void (__thiscall **)(struct IAIEcoManager *, int, int))(*(_DWORD *)v18 + 280))(v18, 5027, v3);
      }
    }
  }
  if ( *((_DWORD *)this + 20) < v38 )
  {
    v16 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
    if ( !(*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v16 + 148))(v16, 3) )
    {
      v15 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
      v39 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v15 + 144))(v15, 18) - 2;
      if ( v39 > 0 )
      {
        if ( v39 > 5 )
          v39 = 5;
        v14 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
        v13 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
        v12 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
        v4 = (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v14 + 128))(v14, v39);
        v5 = (*(int (__thiscall **)(struct IAIEcoManager *, int, int))(*(_DWORD *)v13 + 132))(v13, 3, v4);
        (*(void (__thiscall **)(struct IAIEcoManager *, int, int))(*(_DWORD *)v12 + 280))(v12, 5027, v5);
      }
    }
  }
  if ( *((_DWORD *)this + 13) || !*((_DWORD *)this + 15) )
  {
LABEL_68:
    if ( *((_DWORD *)this + 13) == 1 && *((_DWORD *)this + 15) )
    {
      v9 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
      if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v9 + 304))(
             v9,
             *((_DWORD *)this + 15)) )
      {
        v8 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
        v6 = (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v8 + 68))(v8, *((_DWORD *)this + 15));
        if ( v6 < 100 )
          return v6;
      }
      *((_DWORD *)this + 13) = 2;
      *((_DWORD *)this + 14) = 0;
      *((_DWORD *)this + 15) = 0;
    }
    LOBYTE(v6) = CBuildingManagerTask::AlertLevelZero(this);
    if ( (unsigned __int8)v6 != 1 )
      LOBYTE(v6) = CBuildingManagerTask::AlertLevelOne(this);
  }
  else
  {
    v11 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
    if ( !(*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v11 + 304))(
            v11,
            *((_DWORD *)this + 15))
      || (v10 = CSchedule::GetEcoSector(*((CSchedule **)this + 10)),
          v6 = (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v10 + 68))(
                 v10,
                 *((_DWORD *)this + 15)),
          v6 >= 100) )
    {
      *((_DWORD *)this + 13) = 2;
      *((_DWORD *)this + 14) = 0;
      *((_DWORD *)this + 15) = 0;
      goto LABEL_68;
    }
  }
  return v6;
}


// address=[0x2f50810]
// Decompiled from int __thiscall CBuildingManagerTask::GetToolRequireIndex(_DWORD *this, int a2)
int  CBuildingManagerTask::GetToolRequireIndex(enum PILE_TYPES a2) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 11; ++i )
  {
    if ( this[4 * i + 24] == a2 )
      return i;
  }
  return 11;
}


// address=[0x2f50860]
// Decompiled from char __thiscall CBuildingManagerTask::GetBuildingPermission(CSchedule **this, struct CBuildingEvent *a2)
bool  CBuildingManagerTask::GetBuildingPermission(class CBuildingEvent * a2) {
  
  int v3; // esi
  struct IAIEcoManager *v4; // [esp+28h] [ebp-34h]
  struct IAIEcoManager *v5; // [esp+2Ch] [ebp-30h]
  int NeededSettler; // [esp+30h] [ebp-2Ch]
  struct IAIEcoManager *EcoSector; // [esp+34h] [ebp-28h]
  int Tool; // [esp+3Ch] [ebp-20h]
  bool SeperateBuildingPermission; // [esp+48h] [ebp-14h]
  bool v11; // [esp+4Bh] [ebp-11h]

  std::vector<SBuildId>::vector<SBuildId>();
  CBuildingManagerTask::UpdateRequireGoods((CBuildingManagerTask *)this, 0);
  if ( !this[13] )
  {
    if ( *((_DWORD *)a2 + 11) != 46 )
    {
      if ( this[14] != *((CSchedule **)a2 + 11) || this[15] && this[15] != *((CSchedule **)a2 + 12) )
      {
        std::vector<SBuildId>::~vector<SBuildId>();
        return 0;
      }
      if ( *((_DWORD *)a2 + 13) != 1 )
        this[15] = (CSchedule *)*((_DWORD *)a2 + 12);
    }
LABEL_14:
    std::vector<SBuildId>::~vector<SBuildId>();
    return 1;
  }
  if ( *((_DWORD *)a2 + 13) == 1 )
  {
    v11 = (int)this[12] < 15;
    std::vector<SBuildId>::~vector<SBuildId>();
    return v11;
  }
  EcoSector = CSchedule::GetEcoSector(this[10]);
  if ( (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)EcoSector + 68))(
         EcoSector,
         *((_DWORD *)a2 + 12)) > 1 )
    goto LABEL_14;
  if ( !*((_BYTE *)a2 + 85) )
  {
    Tool = CProductionDataTab::GetTool(*((void **)this[10] + 10), *((_DWORD *)a2 + 11));
    *((_BYTE *)a2 + 85) = 1;
    if ( Tool )
    {
      NeededSettler = CProductionDataTab::GetNeededSettler(*((void **)this[10] + 10), *((_DWORD *)a2 + 11));
      v3 = 4 * CBuildingManagerTask::GetToolRequireIndex(this, Tool);
      if ( (int)this[v3 + 25] >= (int)this[4 * CBuildingManagerTask::GetToolRequireIndex(this, Tool) + 26] )
      {
        v5 = CSchedule::GetEcoSector(this[10]);
        if ( (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v5 + 152))(v5, NeededSettler) <= 0 )
        {
          if ( !this[23] )
          {
            *((_BYTE *)a2 + 85) = 0;
            std::vector<SBuildId>::~vector<SBuildId>();
            return 0;
          }
          *((_BYTE *)a2 + 85) = 1;
          v4 = CSchedule::GetEcoSector(this[10]);
          (*(void (__thiscall **)(struct IAIEcoManager *, CSchedule *, int, int))(*(_DWORD *)v4 + 268))(
            v4,
            this[23],
            Tool,
            1);
        }
      }
    }
  }
  SeperateBuildingPermission = CBuildingManagerTask::GetSeperateBuildingPermission((CBuildingManagerTask *)this, a2);
  std::vector<SBuildId>::~vector<SBuildId>();
  return SeperateBuildingPermission;
}


// address=[0x2f50b50]
// Decompiled from char __thiscall CBuildingManagerTask::GetSeperateBuildingPermission(  CBuildingManagerTask *this,  struct CBuildingEvent *a2)
bool  CBuildingManagerTask::GetSeperateBuildingPermission(class CBuildingEvent * a2) {
  
  char result; // al

  switch ( *((_DWORD *)a2 + 11) )
  {
    case 5:
      if ( CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 10), 9)
        || CSchedule::GetNumberOfBuildingTypeAtBuilding(*((CDynList ***)this + 10), 12, 0, 1) )
      {
        goto CBuildingManagerTask__GetSeperateBuildingPermission___def_3350B7F;
      }
      result = 0;
      break;
    case 8:
      if ( CSchedule::GetNumberOfBuildingTypeAtBuilding(*((CDynList ***)this + 10), 12, 10, 1) )
      {
        if ( CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 10), 22) )
          goto CBuildingManagerTask__GetSeperateBuildingPermission___def_3350B7F;
        result = 0;
      }
      else
      {
        result = 0;
      }
      break;
    case 9:
    case 0xC:
      if ( CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 10), 11) )
        goto CBuildingManagerTask__GetSeperateBuildingPermission___def_3350B7F;
      result = 0;
      break;
    case 0xA:
      if ( CSchedule::GetNumberOfBuildingTypeAtBuilding(*((CDynList ***)this + 10), 9, 5, 1) )
      {
        if ( CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 10), 22) )
          goto CBuildingManagerTask__GetSeperateBuildingPermission___def_3350B7F;
        result = 0;
      }
      else
      {
        result = 0;
      }
      break;
    case 0x10:
      if ( CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 10), 24) )
        goto CBuildingManagerTask__GetSeperateBuildingPermission___def_3350B7F;
      result = 0;
      break;
    case 0x13:
      if ( CSchedule::GetNumberOfBuildingTypeAtBuilding(*((CDynList ***)this + 10), 16, 15, 1) )
        goto CBuildingManagerTask__GetSeperateBuildingPermission___def_3350B7F;
      result = 0;
      break;
    case 0x14:
      if ( CSchedule::GetNumberOfBuildingTypeAtBuilding(*((CDynList ***)this + 10), 17, 0, 1)
        && CSchedule::GetNumberOfBuildingTypeAtBuilding(*((CDynList ***)this + 10), 15, 0, 1) )
      {
        goto CBuildingManagerTask__GetSeperateBuildingPermission___def_3350B7F;
      }
      result = 0;
      break;
    case 0x15:
      if ( CSchedule::GetNumberOfBuildingTypeAtBuilding(*((CDynList ***)this + 10), 20, 15, 1) )
        goto CBuildingManagerTask__GetSeperateBuildingPermission___def_3350B7F;
      result = 0;
      break;
    case 0x16:
      if ( CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 10), 20) )
        goto CBuildingManagerTask__GetSeperateBuildingPermission___def_3350B7F;
      result = 0;
      break;
    case 0x18:
      if ( CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 10), 22) )
        goto CBuildingManagerTask__GetSeperateBuildingPermission___def_3350B7F;
      result = 0;
      break;
    case 0x2B:
      if ( CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 10), 19) )
        goto CBuildingManagerTask__GetSeperateBuildingPermission___def_3350B7F;
      result = 0;
      break;
    case 0x2C:
      if ( CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 10), 43) )
        goto CBuildingManagerTask__GetSeperateBuildingPermission___def_3350B7F;
      result = 0;
      break;
    default:
CBuildingManagerTask__GetSeperateBuildingPermission___def_3350B7F:
      result = 1;
      break;
  }
  return result;
}


// address=[0x2f50db0]
// Decompiled from int __thiscall CBuildingManagerTask::SetRejectedBuilding(_DWORD *this, int a2)
void  CBuildingManagerTask::SetRejectedBuilding(enum BUILDING_TYPES a2) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 5; ++i )
  {
    if ( !this[i + 68] )
    {
      result = i;
      this[i + 68] = a2;
      return result;
    }
    result = i + 1;
  }
  return result;
}


// address=[0x2f50e00]
// Decompiled from char __thiscall CBuildingManagerTask::IsRejectedBuilding(_DWORD *this, int a2, char a3)
bool  CBuildingManagerTask::IsRejectedBuilding(enum BUILDING_TYPES a2, bool a3) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    if ( i >= 5 )
      return 0;
    if ( this[i + 68] == a2 )
      break;
  }
  if ( a3 )
    this[i + 68] = 0;
  return 1;
}


// address=[0x2f50e60]
// Decompiled from char __thiscall CBuildingManagerTask::SetBuildingAtPlanning(_DWORD *this, int a2)
bool  CBuildingManagerTask::SetBuildingAtPlanning(enum BUILDING_TYPES a2) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 10; ++i )
  {
    if ( !this[i + 73] )
    {
      this[i + 73] = a2;
      return 1;
    }
  }
  return 0;
}


// address=[0x2f50eb0]
// Decompiled from char __thiscall CBuildingManagerTask::IsBuildingAtPlanning(_DWORD *this, int a2)
bool  CBuildingManagerTask::IsBuildingAtPlanning(enum BUILDING_TYPES a2) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 10; ++i )
  {
    if ( this[i + 73] == a2 )
      return 1;
  }
  return 0;
}


// address=[0x2f50f00]
// Decompiled from char __thiscall CBuildingManagerTask::RemoveBuildingAtPlanning(_DWORD *this, int a2)
bool  CBuildingManagerTask::RemoveBuildingAtPlanning(enum BUILDING_TYPES a2) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 10; ++i )
  {
    if ( this[i + 73] == a2 )
    {
      this[i + 73] = 0;
      return 1;
    }
  }
  return 0;
}


// address=[0x2f50f60]
// Decompiled from char __thiscall CBuildingManagerTask::AlertLevelZero(CBuildingManagerTask *this)
bool  CBuildingManagerTask::AlertLevelZero(void) {
  
  struct IAIEcoManager *v2; // [esp+10h] [ebp-30h]
  struct IAIEcoManager *v3; // [esp+14h] [ebp-2Ch]
  struct IAIEcoManager *v4; // [esp+1Ch] [ebp-24h]
  struct IAIEcoManager *v5; // [esp+20h] [ebp-20h]
  struct IAIEcoManager *v6; // [esp+24h] [ebp-1Ch]
  struct IAIEcoManager *v7; // [esp+28h] [ebp-18h]
  struct IAIEcoManager *v8; // [esp+2Ch] [ebp-14h]
  struct IAIEcoManager *EcoSector; // [esp+30h] [ebp-10h]
  int v10; // [esp+34h] [ebp-Ch]
  int v11; // [esp+38h] [ebp-8h]

  v11 = 0;
  v10 = *((_DWORD *)this + 25) - *((_DWORD *)this + 26);
  if ( v10 <= 0 )
    goto LABEL_21;
  EcoSector = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
  if ( v10 > (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)EcoSector + 144))(EcoSector, 22)
    && !CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 10), 1) )
  {
    *((_DWORD *)this + 13) = 0;
    *((_DWORD *)this + 14) = 1;
    *((_DWORD *)this + 15) = 0;
    return 1;
  }
  if ( CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 10), 3) )
  {
LABEL_21:
    if ( *((_DWORD *)this + 30) - *((_DWORD *)this + 29) >= 0
      || CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 10), 4) )
    {
      if ( !*((_DWORD *)this + 14) )
        return 0;
      if ( *((_DWORD *)this + 15) )
      {
        v8 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
        v11 = (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD, int))(*(_DWORD *)v8 + 60))(
                v8,
                *((_DWORD *)this + 14),
                1);
        v7 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
        (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD, _DWORD))(*(_DWORD *)v7 + 60))(
          v7,
          *((_DWORD *)this + 14),
          0);
      }
      else
      {
        v6 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
        if ( (*(unsigned __int8 (__thiscall **)(struct IAIEcoManager *, _DWORD))(*(_DWORD *)v6 + 304))(
               v6,
               *((_DWORD *)this + 15)) )
        {
          v5 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
          v11 = (*(int (__thiscall **)(struct IAIEcoManager *, _DWORD, int))(*(_DWORD *)v5 + 64))(
                  v5,
                  *((_DWORD *)this + 15),
                  1);
          v4 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
          (*(void (__thiscall **)(struct IAIEcoManager *, _DWORD, _DWORD))(*(_DWORD *)v4 + 64))(
            v4,
            *((_DWORD *)this + 15),
            0);
        }
      }
      v3 = CSchedule::GetEcoSector(*((CSchedule **)this + 10));
      if ( v11 > (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v3 + 144))(v3, 32)
        || (v2 = CSchedule::GetEcoSector(*((CSchedule **)this + 10)),
            v11 > (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)v2 + 144))(v2, 32)) )
      {
        CSchedule::DestroySeveralBuildings(*((CSchedule **)this + 10));
      }
      return 0;
    }
    else
    {
      *((_DWORD *)this + 13) = 0;
      *((_DWORD *)this + 14) = 4;
      *((_DWORD *)this + 15) = 0;
      return 1;
    }
  }
  else
  {
    *((_DWORD *)this + 13) = 0;
    *((_DWORD *)this + 14) = 3;
    *((_DWORD *)this + 15) = 0;
    return 1;
  }
}


// address=[0x2f511f0]
// Decompiled from char __thiscall CBuildingManagerTask::AlertLevelOne(CBuildingManagerTask *this)
bool  CBuildingManagerTask::AlertLevelOne(void) {
  
  return 0;
}


