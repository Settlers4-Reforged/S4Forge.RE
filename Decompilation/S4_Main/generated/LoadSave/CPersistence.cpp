#include "CPersistence.h"

// Definitions for class CPersistence

// address=[0x130e9f0]
// Decompiled from int CPersistence::ClassID()
unsigned long  CPersistence::ClassID(void)const {
  
  return CPersistence::m_iClassID;
}


// address=[0x13ed840]
// Decompiled from struct std::ostream *__thiscall CPersistence::Store(struct CPersistence *this, struct std::ostream *a2)
void  CPersistence::Store(std::ostream &) {
  
  unsigned int v3[2]; // [esp+0h] [ebp-8h] BYREF

  v3[1] = (unsigned int)this;
  v3[0] = (**(int (__thiscall ***)(struct CPersistence *))this)(this);
  return operator^<unsigned long>(a2, v3);
}


// address=[0x13ed870]
// Decompiled from _DWORD *__cdecl CPersistence::RegisterClassWhithId(int *a1, int a2, int a3)
static void __cdecl CPersistence::RegisterClassWhithId(unsigned long &,class CPersistence * (__cdecl*)(std::istream &),unsigned long) {
  
  _DWORD *result; // eax

  if ( !a3 )
    a3 = CPersistence::m_iNextClassID++;
  *a1 = a3;
  result = (_DWORD *)std::map<unsigned long,CPersistence * (__cdecl *)(std::istream &),std::less<unsigned long>,std::allocator<std::pair<unsigned long const,CPersistence * (__cdecl *)(std::istream &)>>>::operator[](&a3);
  *result = a2;
  return result;
}


// address=[0x13ed8b0]
// Decompiled from int __cdecl CPersistence::New(int a1)
static class CPersistence * __cdecl CPersistence::New(std::istream &) {
  
  _BYTE v2[12]; // [esp+4h] [ebp-44h] BYREF
  _BYTE v3[12]; // [esp+10h] [ebp-38h] BYREF
  int v4; // [esp+1Ch] [ebp-2Ch]
  int (__cdecl *v5)(int); // [esp+20h] [ebp-28h]
  std::_Iterator_base12 *v6; // [esp+24h] [ebp-24h]
  std::_Iterator_base12 *v7; // [esp+28h] [ebp-20h]
  _BYTE v8[4]; // [esp+2Ch] [ebp-1Ch] BYREF
  int v9; // [esp+30h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+34h] [ebp-14h] BYREF
  char v11; // [esp+3Bh] [ebp-Dh]
  int v12; // [esp+44h] [ebp-4h]

  operator^<unsigned long>(a1, v8);
  if ( (unsigned __int8)std::ios_base::operator!(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1) )
  {
    pExceptionObject = 0;
    CPersistence::SerialError::SerialError((CPersistence::SerialError *)&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVSerialError_CPersistence__);
  }
  std::_Tree<std::_Tmap_traits<unsigned long,CPersistence * (__cdecl *)(std::istream &),std::less<unsigned long>,std::allocator<std::pair<unsigned long const,CPersistence * (__cdecl *)(std::istream &)>>,0>>::find(
    v3,
    v8);
  v12 = 0;
  v7 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned long,CPersistence * (__cdecl *)(std::istream &),std::less<unsigned long>,std::allocator<std::pair<unsigned long const,CPersistence * (__cdecl *)(std::istream &)>>,0>>::end(v2);
  v6 = v7;
  LOBYTE(v12) = 1;
  v11 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CPersistence * (__cdecl *)(std::istream &)>>>>::operator==(v7);
  LOBYTE(v12) = 0;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CPersistence * (__cdecl *)(std::istream &)>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CPersistence * (__cdecl *)(std::istream &)>>>>(v2);
  if ( v11 )
  {
    v9 = 0;
    CPersistence::BadClassID::BadClassID((CPersistence::BadClassID *)&v9);
    _CxxThrowException(&v9, (_ThrowInfo *)&_TI2_AVBadClassID_CPersistence__);
  }
  v5 = *(int (__cdecl **)(int))(std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CPersistence * (__cdecl *)(std::istream &)>>>>::operator*(v3)
                              + 4);
  v4 = v5(a1);
  v12 = -1;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CPersistence * (__cdecl *)(std::istream &)>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CPersistence * (__cdecl *)(std::istream &)>>>>(v3);
  return v4;
}


// address=[0x13ed9d0]
// Decompiled from int __cdecl CPersistence::New_HACK_VERSION(int a1)
static class CPersistence * __cdecl CPersistence::New_HACK_VERSION(std::istream &) {
  
  _BYTE v2[4]; // [esp+4h] [ebp-20h] BYREF
  void *C; // [esp+10h] [ebp-14h]
  _DWORD pExceptionObject[4]; // [esp+14h] [ebp-10h] BYREF

  operator^<unsigned long>(a1, v2);
  if ( (unsigned __int8)std::ios_base::operator!(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1) )
  {
    pExceptionObject[0] = 0;
    CPersistence::SerialError::SerialError((CPersistence::SerialError *)pExceptionObject);
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVSerialError_CPersistence__);
  }
  C = operator new(0x74u);
  pExceptionObject[3] = 0;
  if ( C )
    return CSquadLeaderRole::CSquadLeaderRole(a1);
  else
    return 0;
}


// address=[0x14d7f80]
// Decompiled from CPersistence *__thiscall CPersistence::CPersistence(CPersistence *this)
 CPersistence::CPersistence(class CPersistence const &) {
  
  this->__vftable = (CPersistence_vtbl *)&CPersistence::_vftable_;
  return this;
}


// address=[0x14e4760]
// Decompiled from void *__thiscall CPersistence::operator=(void *this, int a2)
class CPersistence &  CPersistence::operator=(class CPersistence const &) {
  
  return this;
}


// address=[0x154edd0]
// Decompiled from CPersistence *__thiscall CPersistence::CPersistence(  CPersistence *this,  const struct boost::exception_detail::clone_base *a2)
 CPersistence::CPersistence(class CPersistence &&) {
  
  *(_DWORD *)this = &CPersistence::_vftable_;
  return this;
}


// address=[0x130e3c0]
// Decompiled from CPersistence *__thiscall CPersistence::CPersistence(CPersistence *this)
 CPersistence::CPersistence(void) {
  
  this->__vftable = (CPersistence_vtbl *)&CPersistence::_vftable_;
  return this;
}


// address=[0x13eda90]
// Decompiled from char __cdecl CPersistence::LOAD_UINT8(int a1)
static unsigned char __cdecl CPersistence::LOAD_UINT8(std::istream &) {
  
  int pExceptionObject; // [esp+0h] [ebp-8h] BYREF
  char v3; // [esp+7h] [ebp-1h] BYREF

  operator^<unsigned char>(a1, &v3);
  if ( !(unsigned __int8)std::ios_base::operator!(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1) )
    return v3;
  pExceptionObject = 0;
  CPersistence::SerialError::SerialError((CPersistence::SerialError *)&pExceptionObject);
  _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVSerialError_CPersistence__);
  return v3;
}


// address=[0x13edae0]
// Decompiled from __int16 __cdecl CPersistence::LOAD_UINT16(int a1)
static unsigned short __cdecl CPersistence::LOAD_UINT16(std::istream &) {
  
  int pExceptionObject; // [esp+0h] [ebp-8h] BYREF
  __int16 v3; // [esp+4h] [ebp-4h] BYREF

  operator^<unsigned short>(a1, &v3);
  if ( !(unsigned __int8)std::ios_base::operator!(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1) )
    return v3;
  pExceptionObject = 0;
  CPersistence::SerialError::SerialError((CPersistence::SerialError *)&pExceptionObject);
  _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVSerialError_CPersistence__);
  return v3;
}


// address=[0x13edb30]
// Decompiled from int __cdecl CPersistence::LOAD_UINT32(int a1)
static unsigned int __cdecl CPersistence::LOAD_UINT32(std::istream &) {
  
  int v2; // [esp+0h] [ebp-8h] BYREF
  int pExceptionObject; // [esp+4h] [ebp-4h] BYREF

  operator^<unsigned int>(a1, &v2);
  if ( !(unsigned __int8)std::ios_base::operator!(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1) )
    return v2;
  pExceptionObject = 0;
  CPersistence::SerialError::SerialError((CPersistence::SerialError *)&pExceptionObject);
  _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVSerialError_CPersistence__);
  return v2;
}


// address=[0x13edb80]
// Decompiled from char __cdecl CPersistence::LOAD_INT8(int a1)
static signed char __cdecl CPersistence::LOAD_INT8(std::istream &) {
  
  int pExceptionObject; // [esp+0h] [ebp-8h] BYREF
  char v3; // [esp+7h] [ebp-1h] BYREF

  operator^<signed char>(a1, &v3);
  if ( !(unsigned __int8)std::ios_base::operator!(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1) )
    return v3;
  pExceptionObject = 0;
  CPersistence::SerialError::SerialError((CPersistence::SerialError *)&pExceptionObject);
  _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVSerialError_CPersistence__);
  return v3;
}


// address=[0x13edbd0]
// Decompiled from __int16 __cdecl CPersistence::LOAD_INT16(int a1)
static short __cdecl CPersistence::LOAD_INT16(std::istream &) {
  
  int pExceptionObject; // [esp+0h] [ebp-8h] BYREF
  __int16 v3; // [esp+4h] [ebp-4h] BYREF

  operator^<short>(a1, &v3);
  if ( !(unsigned __int8)std::ios_base::operator!(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1) )
    return v3;
  pExceptionObject = 0;
  CPersistence::SerialError::SerialError((CPersistence::SerialError *)&pExceptionObject);
  _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVSerialError_CPersistence__);
  return v3;
}


// address=[0x13edc20]
// Decompiled from int __cdecl CPersistence::LOAD_INT32(int a1)
static int __cdecl CPersistence::LOAD_INT32(std::istream &) {
  
  int v2; // [esp+0h] [ebp-8h] BYREF
  int pExceptionObject; // [esp+4h] [ebp-4h] BYREF

  operator^<int>(a1, (int)&v2);
  if ( !(unsigned __int8)std::ios_base::operator!(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1) )
    return v2;
  pExceptionObject = 0;
  CPersistence::SerialError::SerialError((CPersistence::SerialError *)&pExceptionObject);
  _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVSerialError_CPersistence__);
  return v2;
}


// address=[0x13edc70]
// Decompiled from int __cdecl CPersistence::LOAD_ID(int a1)
static unsigned long __cdecl CPersistence::LOAD_ID(std::istream &) {
  
  int v2; // [esp+0h] [ebp-8h] BYREF
  int pExceptionObject; // [esp+4h] [ebp-4h] BYREF

  operator^<unsigned long>(a1, &v2);
  if ( !(unsigned __int8)std::ios_base::operator!(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1) )
    return v2;
  pExceptionObject = 0;
  CPersistence::SerialError::SerialError((CPersistence::SerialError *)&pExceptionObject);
  _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVSerialError_CPersistence__);
  return v2;
}


// address=[0x13edcc0]
// Decompiled from double __cdecl CPersistence::LOAD_FLOAT64(int a1)
static double __cdecl CPersistence::LOAD_FLOAT64(std::istream &) {
  
  double v2; // [esp+0h] [ebp-Ch] BYREF
  int pExceptionObject; // [esp+8h] [ebp-4h] BYREF

  operator^<double>(a1, &v2);
  if ( !(unsigned __int8)std::ios_base::operator!(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1) )
    return v2;
  pExceptionObject = 0;
  CPersistence::SerialError::SerialError((CPersistence::SerialError *)&pExceptionObject);
  _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVSerialError_CPersistence__);
  return v2;
}


// address=[0x13edd10]
// Decompiled from double __cdecl CPersistence::LOAD_FLOAT32(int a1)
static float __cdecl CPersistence::LOAD_FLOAT32(std::istream &) {
  
  float v2; // [esp+0h] [ebp-8h] BYREF
  int pExceptionObject; // [esp+4h] [ebp-4h] BYREF

  operator^<float>(a1, &v2);
  if ( !(unsigned __int8)std::ios_base::operator!(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1) )
    return v2;
  pExceptionObject = 0;
  CPersistence::SerialError::SerialError((CPersistence::SerialError *)&pExceptionObject);
  _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVSerialError_CPersistence__);
  return v2;
}


// address=[0x13edd60]
// Decompiled from char __cdecl CPersistence::LOAD_char(int a1)
static char __cdecl CPersistence::LOAD_char(std::istream &) {
  
  int pExceptionObject; // [esp+0h] [ebp-8h] BYREF
  char v3; // [esp+7h] [ebp-1h] BYREF

  operator^<char>(a1, &v3);
  if ( !(unsigned __int8)std::ios_base::operator!(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1) )
    return v3;
  pExceptionObject = 0;
  CPersistence::SerialError::SerialError((CPersistence::SerialError *)&pExceptionObject);
  _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVSerialError_CPersistence__);
  return v3;
}


// address=[0x13eddb0]
// Decompiled from int __cdecl CPersistence::LOAD_string(int a1, int a2)
static std::string __cdecl CPersistence::LOAD_string(std::istream &) {
  
  int pExceptionObject; // [esp+8h] [ebp-30h] BYREF
  _BYTE v4[28]; // [esp+Ch] [ebp-2Ch] BYREF
  int v5; // [esp+34h] [ebp-4h]

  std::string::string();
  v5 = 0;
  operator^<std::string>(a2, v4);
  if ( (unsigned __int8)std::ios_base::operator!(*(_DWORD *)(*(_DWORD *)a2 + 4) + a2) )
  {
    pExceptionObject = 0;
    CPersistence::SerialError::SerialError((CPersistence::SerialError *)&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVSerialError_CPersistence__);
  }
  std::string::string(v4);
  v5 = -1;
  std::string::~string(v4);
  return a1;
}


// address=[0x13ede70]
// Decompiled from char __cdecl CPersistence::LOAD_bool(int a1)
static bool __cdecl CPersistence::LOAD_bool(std::istream &) {
  
  int pExceptionObject; // [esp+0h] [ebp-8h] BYREF
  char v3; // [esp+7h] [ebp-1h] BYREF

  operator^<bool>(a1, &v3);
  if ( !(unsigned __int8)std::ios_base::operator!(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1) )
    return v3;
  pExceptionObject = 0;
  CPersistence::SerialError::SerialError((CPersistence::SerialError *)&pExceptionObject);
  _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVSerialError_CPersistence__);
  return v3;
}


// address=[0x3d89400]
// [Decompilation failed for static unsigned long CPersistence::m_iNextClassID]

// address=[0x3efe474]
// [Decompilation failed for static unsigned long CPersistence::m_iClassID]

