#include "CShipList.h"

// Definitions for class CShipList

// address=[0x15fd5b0]
// Decompiled from void __thiscall CShipList::PushNeighborShips(CShipList *this, int a2)

void  CShipList::PushNeighborShips(int) {
  
  Squares *v2; // eax
  Squares *v3; // eax
  int v5; // [esp+4h] [ebp-8h]
  int v6; // [esp+8h] [ebp-4h]

  v2 = (Squares *)Y16X16::UnpackXFast(a2);
  v6 = Squares::XYToVW(v2);
  v3 = (Squares *)Y16X16::UnpackYFast(a2);
  v5 = Squares::XYToVW(v3);
  CShipList::PushSquareVW(this, v6, v5, a2);
  CShipList::PushSquareVW(this, v6, v5 - 1, a2);
  CShipList::PushSquareVW(this, v6, v5 + 1, a2);
  if ( v6 > 0 )
  {
    CShipList::PushSquareVW(this, v6 - 1, v5, a2);
    CShipList::PushSquareVW(this, v6 - 1, v5 - 1, a2);
    CShipList::PushSquareVW(this, v6 - 1, v5 + 1, a2);
  }
  if ( v6 < 63 )
  {
    CShipList::PushSquareVW(this, v6 + 1, v5, a2);
    CShipList::PushSquareVW(this, v6 + 1, v5 - 1, a2);
    CShipList::PushSquareVW(this, v6 + 1, v5 + 1, a2);
  }
}


// address=[0x15fd6e0]
// Decompiled from int __thiscall CShipList::Nearest(CShipList *this, Y16X16 *a2)

int  CShipList::Nearest(int) {
  
  int i; // eax
  const struct CShipInfo *v3; // eax
  int v6; // [esp+4h] [ebp-10h]
  int v7; // [esp+8h] [ebp-Ch]
  int v8; // [esp+Ch] [ebp-8h]
  int v9; // [esp+10h] [ebp-4h]

  v7 = 10;
  v6 = 10;
  v8 = 0;
  for ( i = CShipList::NumberOfShips(this); v8 < i; i = CShipList::NumberOfShips(this) )
  {
    v3 = CShipList::ShipInfo(this, v8);
    v9 = Y16X16::DistanceFast(a2, *(_DWORD *)v3);
    if ( v9 < 10 )
    {
      if ( v9 >= v7 )
      {
        if ( v9 < v6 )
          v6 = v9;
      }
      else
      {
        v6 = v7;
        v7 = v9;
      }
    }
    ++v8;
  }
  return (16 * (10 - v6)) | (10 - v7);
}


// address=[0x15fe630]
// Decompiled from CShipList *__thiscall CShipList::CShipList(CShipList *this, int a2)

 CShipList::CShipList(int) {
  
  *(_DWORD *)this = 0;
  CShipList::PushNeighborShips(this, a2);
  return this;
}


// address=[0x15fe6a0]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
int __thiscall CShipList::NumberOfShips(CShipList *this)

int  CShipList::NumberOfShips(void)const {
  
  return *(_DWORD *)this;
}


// address=[0x15fe6c0]
// Decompiled from int __thiscall CShipList::PushShip(CShipList *this, int a2)

void  CShipList::PushShip(int) {
  
  int result; // eax

  *((_DWORD *)this + *(_DWORD *)this + 1) = a2;
  result = *(_DWORD *)this + 1;
  *(_DWORD *)this = result;
  return result;
}


// address=[0x15fe700]
// Decompiled from int __thiscall CShipList::PushSquareVW(CShipList *this, int a2, int a3, int a4)

void  CShipList::PushSquareVW(int,int,int) {
  
  int result; // eax
  Y16X16 *v6; // [esp+4h] [ebp-Ch]
  int v7; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  result = (int)CShipMap::ShipListVW(a2, a3);
  v7 = result;
  for ( i = 0; i < 4; ++i )
  {
    result = i;
    if ( !*(_DWORD *)(v7 + 4 * i) )
      break;
    v6 = *(Y16X16 **)(v7 + 4 * i);
    result = Y16X16::DistanceFast(v6, a4);
    if ( result <= 18 )
      result = CShipList::PushShip(this, (int)v6);
  }
  return result;
}


// address=[0x15fe7c0]
// Decompiled from char *__thiscall CShipList::ShipInfo(CShipList *this, int a2)

class CShipInfo const &  CShipList::ShipInfo(int)const {
  
  return (char *)this + 4 * a2 + 4;
}


