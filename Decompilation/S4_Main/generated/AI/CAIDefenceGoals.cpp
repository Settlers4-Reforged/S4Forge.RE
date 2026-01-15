#include "CAIDefenceGoals.h"

// Definitions for class CAIDefenceGoals

// address=[0x1309340]
// Decompiled from CAIDefenceGoals *__thiscall CAIDefenceGoals::CAIDefenceGoals(CAIDefenceGoals *this)
 CAIDefenceGoals::CAIDefenceGoals(void) {
  
  CAIDefenceGoals::Clear(this);
  return this;
}


// address=[0x13093e0]
// Decompiled from void *__thiscall CAIDefenceGoals::Clear(CAIDefenceGoals *this)
void  CAIDefenceGoals::Clear(void) {
  
  *(_DWORD *)this = 0;
  return memset((char *)this + 4, 0, 0x3C0u);
}


// address=[0x1309540]
// Decompiled from char *__thiscall CAIDefenceGoals::Goal(CAIDefenceGoals *this, int a2)
class CAIDefenceGoal &  CAIDefenceGoals::Goal(int) {
  
  return (char *)this + 20 * a2 + 4;
}


// address=[0x13095c0]
// Decompiled from int __thiscall CAIDefenceGoals::NumberOfGoals(CAIDefenceGoals *this)
int  CAIDefenceGoals::NumberOfGoals(void)const {
  
  return *(_DWORD *)this;
}


// address=[0x1314a30]
// Decompiled from int __thiscall CAIDefenceGoals::Search(CAIDefenceGoals *this, int a2)
int  CAIDefenceGoals::Search(int) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < *(_DWORD *)this; ++i )
  {
    if ( *((unsigned __int16 *)this + 10 * i + 2) == a2 )
      return i;
  }
  return -1;
}


// address=[0x1314a80]
// Decompiled from int __thiscall CAIDefenceGoals::SetFlagBitsId(CAIDefenceGoals *this, int a2, char a3)
int  CAIDefenceGoals::SetFlagBitsId(int,int) {
  
  int v5; // [esp+4h] [ebp-4h]

  v5 = CAIDefenceGoals::Search(this, a2);
  if ( v5 >= 0 )
    *((_BYTE *)this + 20 * v5 + 6) |= a3;
  return v5;
}


// address=[0x1314ad0]
// Decompiled from int __thiscall CAIDefenceGoals::Insert(CAIDefenceGoals *this, int a2, int a3, int a4, int a5)
void  CAIDefenceGoals::Insert(int,int,int,int) {
  
  int result; // eax
  int v6; // [esp+0h] [ebp-10h]
  int v7; // [esp+0h] [ebp-10h]
  char *v8; // [esp+8h] [ebp-8h]

  v6 = CAIDefenceGoals::Search(this, a2);
  if ( v6 >= 0 )
  {
    if ( *((_DWORD *)this + 5 * v6 + 2) < a3 )
      *((_DWORD *)this + 5 * v6 + 2) = a3;
    if ( *((_DWORD *)this + 5 * v6 + 3) < a4 )
      *((_DWORD *)this + 5 * v6 + 3) = a4;
    result = (int)this + 20 * v6 + 4;
    if ( *((_DWORD *)this + 5 * v6 + 4) < a5 )
    {
      result = a5;
      *((_DWORD *)this + 5 * v6 + 4) = a5;
    }
  }
  else
  {
    result = CAIDefenceGoals::NumberOfGoals(this);
    if ( result < 48 )
    {
      v7 = (*(_DWORD *)this)++;
      v8 = (char *)this + 20 * v7 + 4;
      *(_WORD *)v8 = a2;
      v8[2] = 0;
      *((_DWORD *)v8 + 1) = a3;
      *((_DWORD *)v8 + 2) = a4;
      *((_DWORD *)v8 + 3) = a5;
      result = (int)v8;
      *((_DWORD *)v8 + 4) = 0;
    }
  }
  return result;
}


// address=[0x1314bb0]
// Decompiled from int __thiscall CAIDefenceGoals::NextUnprotectedGoalIdx(CAIDefenceGoals *this, int a2)
int  CAIDefenceGoals::NextUnprotectedGoalIdx(int) {
  
  while ( a2 < *(_DWORD *)this )
  {
    if ( (*((_BYTE *)this + 20 * a2 + 6) & 1) == 0 )
      return a2;
    ++a2;
  }
  return -1;
}


