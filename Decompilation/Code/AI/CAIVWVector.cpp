#include "CAIVWVector.h"

// Definitions for class CAIVWVector

// address=[0x1334d40]
// Decompiled from CAIVWVector *__thiscall CAIVWVector::CAIVWVector(CAIVWVector *this)

 CAIVWVector::CAIVWVector(void) {
  
  std::vector<int>::vector<int>(this);
  std::vector<int>::reserve(256);
  CAIVWVector::Clear(this);
  return this;
}


// address=[0x1335450]
// Decompiled from int __thiscall CAIVWVector::~CAIVWVector(CAIVWVector *this)

 CAIVWVector::~CAIVWVector(void) {
  
  return std::vector<int>::~vector<int>();
}


// address=[0x1335ee0]
// Decompiled from int __thiscall CAIVWVector::At(CAIVWVector *this, unsigned int a2)

int  CAIVWVector::At(int)const {
  
  if ( a2 >= std::vector<int>::size(this) )
    return 0;
  else
    return *(_DWORD *)std::vector<int>::operator[](a2);
}


// address=[0x1335f30]
// Decompiled from void *__thiscall CAIVWVector::Clear(CAIVWVector *this)

void  CAIVWVector::Clear(void) {
  
  std::vector<int>::clear();
  return j__memset((char *)this + 16, 0, 0x2000u);
}


// address=[0x1336240]
// Decompiled from int __thiscall CAIVWVector::Index(CAIVWVector *this, int a2)

int  CAIVWVector::Index(int)const {
  
  Grid *v4; // [esp+4h] [ebp-8h]
  int v5; // [esp+8h] [ebp-4h]

  v4 = (Grid *)Y16X16::UnpackXFast(a2);
  v5 = Y16X16::UnpackYFast(a2);
  if ( !Grid::InQuadrat(v4, v5, 64)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\AI\\AI_VWVector.h",
         41,
         (const char *)&dword_367DE24[1]) == 1 )
  {
    __debugbreak();
  }
  return *((unsigned __int16 *)this + 64 * v5 + (_DWORD)v4 + 8) - 1;
}


// address=[0x1336440]
// Decompiled from Grid *__thiscall CAIVWVector::PushBack(CAIVWVector *this, int a2)

void  CAIVWVector::PushBack(int) {
  
  Grid *result; // eax
  _DWORD *v3; // eax
  int v4; // [esp+0h] [ebp-10h]
  Grid *v5; // [esp+4h] [ebp-Ch]
  int v6; // [esp+8h] [ebp-8h]

  v5 = (Grid *)Y16X16::UnpackXFast(a2);
  v6 = Y16X16::UnpackYFast(a2);
  if ( !Grid::InQuadrat(v5, v6, 64)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\AI\\AI_VWVector.h",
         53,
         (const char *)&dword_367DE24[1]) == 1 )
  {
    __debugbreak();
  }
  if ( *((_WORD *)this + 64 * v6 + (_DWORD)v5 + 8)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\AI\\AI_VWVector.h",
         54,
         "m_uIndices[iW][iV] == 0") == 1 )
  {
    __debugbreak();
  }
  result = v5;
  if ( *((_WORD *)this + 64 * v6 + (_DWORD)v5 + 8) )
    return result;
  v4 = std::vector<int>::size(this);
  std::vector<int>::push_back(&a2);
  v3 = (_DWORD *)std::vector<int>::operator[](v4);
  if ( *v3 != a2
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\AI\\AI_VWVector.h",
         62,
         "m_cVWVector[iNewIndex] == _iPackedVW") == 1 )
  {
    __debugbreak();
  }
  result = (Grid *)(v4 + 1);
  *((_WORD *)this + 64 * v6 + (_DWORD)v5 + 8) = v4 + 1;
  return result;
}


// address=[0x13365a0]
// Decompiled from int __thiscall CAIVWVector::Remove(CAIVWVector *this, unsigned int a2)

void  CAIVWVector::Remove(int) {
  
  int result; // eax
  int v3; // [esp+0h] [ebp-24h]
  int v4; // [esp+4h] [ebp-20h]
  unsigned int v5; // [esp+8h] [ebp-1Ch]
  int v6; // [esp+Ch] [ebp-18h]
  int v7; // [esp+10h] [ebp-14h]
  int v8; // [esp+14h] [ebp-10h]
  int v9; // [esp+18h] [ebp-Ch]

  v5 = std::vector<int>::size(this);
  result = a2;
  if ( a2 >= v5 )
    return result;
  v8 = *(_DWORD *)std::vector<int>::operator[](a2);
  v6 = Y16X16::UnpackXFast(v8);
  v7 = Y16X16::UnpackYFast(v8);
  if ( *((unsigned __int16 *)this + 64 * v7 + v6 + 8) != a2 + 1
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\AI\\AI_VWVector.h",
         79,
         "m_uIndices[iRemoveW][iRemoveV] == _iIndex + 1") == 1 )
  {
    __debugbreak();
  }
  *((_WORD *)this + 64 * v7 + v6 + 8) = 0;
  if ( (int)a2 >= (int)(v5 - 1) )
    return std::vector<int>::pop_back(this);
  v9 = *(_DWORD *)std::vector<int>::operator[](v5 - 1);
  v3 = Y16X16::UnpackXFast(v9);
  v4 = Y16X16::UnpackYFast(v9);
  if ( *((unsigned __int16 *)this + 64 * v4 + v3 + 8) != v5
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\AI\\AI_VWVector.h",
         92,
         "m_uIndices[iLastW][iLastV] == iLastIndex + 1") == 1 )
  {
    __debugbreak();
  }
  *(_DWORD *)std::vector<int>::operator[](a2) = v9;
  *((_WORD *)this + 64 * v4 + v3 + 8) = a2 + 1;
  return std::vector<int>::pop_back(this);
}


// address=[0x1336820]
// Decompiled from int __thiscall CAIVWVector::Size(CAIVWVector *this)

int  CAIVWVector::Size(void)const {
  
  return std::vector<int>::size(this);
}


