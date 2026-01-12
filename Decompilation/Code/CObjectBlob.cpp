#include "CObjectBlob.h"

// Definitions for class CObjectBlob

// address=[0x2fca1a0]
// Decompiled from CObjectBlob *__thiscall CObjectBlob::CObjectBlob(
        CObjectBlob *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        struct CCheckLayer *a12)

 CObjectBlob::CObjectBlob(int,int,int,int,int,int,int,int,int,int,class CCheckLayer *) {
  
  CBlob::CBlob(this, a2, a3, a4, a5, a9, a10, a11, a12);
  *(_DWORD *)this = &CObjectBlob::_vftable_;
  *((_DWORD *)this + 11) = a6;
  *((_DWORD *)this + 12) = a7;
  *((_DWORD *)this + 13) = a8;
  return this;
}


// address=[0x2fca200]
// Decompiled from int __thiscall CObjectBlob::processFillPoint(CCheckLayer **this, int a2, int a3)

void  CObjectBlob::processFillPoint(int,int) {
  
  unsigned int v3; // eax
  unsigned int v4; // ecx
  int result; // eax
  int v6; // et2
  unsigned int v7; // eax
  int v8; // [esp+4h] [ebp-18h] BYREF
  int v9; // [esp+8h] [ebp-14h] BYREF
  int v10; // [esp+Ch] [ebp-10h]
  int i; // [esp+10h] [ebp-Ch]
  CCheckLayer **v12; // [esp+14h] [ebp-8h]
  char v13; // [esp+1Bh] [ebp-1h]

  v12 = this;
  CCheckLayer::setPoint(this[8], a2 - (_DWORD)this[9], a3 - (_DWORD)this[10], 1u);
  v3 = CRandom16::Rand((CRandom16 *)g_pRand);
  v4 = 100 - (_DWORD)v12[13];
  v6 = v3 % v4;
  result = v3 / v4;
  if ( v6 )
    return result;
  v13 = 0;
  for ( i = 0; ; ++i )
  {
    result = (unsigned __int8)g_iNumPlayers;
    if ( i >= (unsigned __int8)g_iNumPlayers )
      break;
    v9 = 0;
    v8 = 0;
    CPlayerData::getStartPos_Real(*(CPlayerData **)(g_pPlayerData + 4 * i), &v9, &v8);
    if ( j__abs(a2 - v9) < 7 || j__abs(a3 - v8) < 7 )
      v13 = 1;
  }
  if ( v13 )
    return result;
  result = (int)v12;
  if ( (CCheckLayer *)(*(_BYTE *)(g_pMapElement + 4 * (a2 + (_DWORD)v12[3] * a3) + 1) & 0xF0) != v12[1] )
    return result;
  v7 = CRandom16::Rand((CRandom16 *)g_pRand);
  v10 = v7 % (unsigned int)v12[12];
  (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)g_pHost + 24))(g_pHost, a2, a3, (int)v12[11] + v10);
  if ( (g_iFlags & 1) != 0 )
    (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)g_pHost + 24))(g_pHost, a3, a2, (int)v12[11] + v10);
  if ( (g_iFlags & 2) != 0 )
    (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)g_pHost + 24))(
      g_pHost,
      (int)v12[3] - a3 - 1,
      (int)v12[3] - a2 - 1,
      (int)v12[11] + v10);
  result = g_iFlags & 1;
  if ( (g_iFlags & 1) != 0 && (g_iFlags & 2) != 0 )
    return (*(int (__thiscall **)(int, int, int, int))(*(_DWORD *)g_pHost + 24))(
             g_pHost,
             (int)v12[3] - a2 - 1,
             (int)v12[3] - a3 - 1,
             (int)v12[11] + v10);
  return result;
}


