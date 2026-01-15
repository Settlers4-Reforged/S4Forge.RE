#include "CEntityTask.h"

// Definitions for class CEntityTask

// address=[0x14007c0]
// Decompiled from int __cdecl CEntityTask::New(int a1)
static class CPersistence * __cdecl CEntityTask::New(std::istream &) {
  
  if ( operator new(0x18u) )
    return CEntityTask::CEntityTask(a1);
  else
    return 0;
}


// address=[0x14d7e80]
// Decompiled from CEntityTask *__thiscall CEntityTask::CEntityTask(CEntityTask *this, CEntityTask *cloneSource)
 CEntityTask::CEntityTask(class CEntityTask const &) {
  
  CPersistence::CPersistence((CPersistence *)this);
  *(_DWORD *)this = &CEntityTask::_vftable_;
  *((_BYTE *)this + 4) = *((_BYTE *)cloneSource + 4);
  *((_BYTE *)this + 5) = *((_BYTE *)cloneSource + 5);
  *((_BYTE *)this + 6) = *((_BYTE *)cloneSource + 6);
  *((_BYTE *)this + 7) = *((_BYTE *)cloneSource + 7);
  *((_BYTE *)this + 8) = *((_BYTE *)cloneSource + 8);
  *((_BYTE *)this + 9) = *((_BYTE *)cloneSource + 9);
  *((_WORD *)this + 5) = *((_WORD *)cloneSource + 5);
  *((_WORD *)this + 6) = *((_WORD *)cloneSource + 6);
  *((_WORD *)this + 7) = *((_WORD *)cloneSource + 7);
  *((_WORD *)this + 8) = *((_WORD *)cloneSource + 8);
  *((_WORD *)this + 9) = *((_WORD *)cloneSource + 9);
  *((_BYTE *)this + 20) = *((_BYTE *)cloneSource + 20);
  *((_BYTE *)this + 21) = *((_BYTE *)cloneSource + 21);
  return this;
}


// address=[0x14d8620]
// Decompiled from int __thiscall CEntityTask::ClassID(CEntityTask *this)
unsigned long  CEntityTask::ClassID(void)const {
  
  return CEntityTask::m_iClassID;
}


// address=[0x14dfb60]
// Decompiled from CEntityTask *__thiscall CEntityTask::CEntityTask(  CEntityTask *this,  char a2,  __int16 a3,  __int16 a4,  __int16 a5,  char a6,  char a7,  char a8,  bool a9,  bool a10,  char a11,  __int16 a12,  __int16 a13,  char a14)
 CEntityTask::CEntityTask(int,int,int,int,int,int,int,bool,bool,int,unsigned int,unsigned int,unsigned int) {
  
  CPersistence::CPersistence(this);
  *(_DWORD *)this = &CEntityTask::_vftable_;
  *((_BYTE *)this + 4) = a2;
  *((_BYTE *)this + 5) = a11;
  *((_BYTE *)this + 6) = a8;
  *((_BYTE *)this + 7) = a6;
  *((_BYTE *)this + 8) = a7;
  *((_BYTE *)this + 9) = a14;
  *((_WORD *)this + 5) = a4;
  *((_WORD *)this + 6) = a5;
  *((_WORD *)this + 7) = a3;
  *((_WORD *)this + 8) = a12;
  *((_WORD *)this + 9) = a13;
  *((_BYTE *)this + 20) = a10;
  *((_BYTE *)this + 21) = a9;
  return this;
}


// address=[0x154c2d0]
// Decompiled from char *__thiscall CEntityTask::CEntityTask(char *this, int a2)
 CEntityTask::CEntityTask(std::istream &) {
  
  int v3; // [esp+4h] [ebp-Ch] BYREF
  int pExceptionObject; // [esp+8h] [ebp-8h] BYREF
  char *v5; // [esp+Ch] [ebp-4h]

  v5 = this;
  CPersistence::CPersistence(this);
  *(_DWORD *)v5 = &CEntityTask::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CEntityTask");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a2, v5 + 4);
  operator^<unsigned char>(a2, v5 + 5);
  operator^<signed char>(a2, v5 + 6);
  operator^<signed char>(a2, v5 + 7);
  operator^<signed char>(a2, v5 + 8);
  operator^<unsigned char>(a2, v5 + 9);
  operator^<short>(a2, v5 + 10);
  operator^<short>(a2, v5 + 12);
  operator^<unsigned short>(a2, v5 + 14);
  operator^<unsigned short>(a2, v5 + 16);
  operator^<unsigned short>(a2, v5 + 18);
  operator^<bool>(a2, v5 + 20);
  operator^<bool>(a2, v5 + 21);
  return v5;
}


// address=[0x154c440]
// Decompiled from int __thiscall CEntityTask::Store(struct CPersistence *this, struct std::ostream *a2)
void  CEntityTask::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  __int16 *v4; // [esp+4h] [ebp-4h]

  v4 = (__int16 *)this;
  CPersistence::Store(this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  operator^<unsigned char>(a2, (int)(v4 + 2));
  operator^<unsigned char>(a2, (int)v4 + 5);
  operator^<signed char>(a2, v4 + 3);
  operator^<signed char>(a2, (char *)v4 + 7);
  operator^<signed char>(a2, v4 + 4);
  operator^<unsigned char>(a2, (int)v4 + 9);
  operator^<short>((int)a2, v4 + 5);
  operator^<short>((int)a2, v4 + 6);
  operator^<unsigned short>((int)a2, v4 + 7);
  operator^<unsigned short>((int)a2, v4 + 8);
  operator^<unsigned short>((int)a2, v4 + 9);
  operator^<bool>((int)a2, (int)(v4 + 10));
  return operator^<bool>((int)a2, (int)v4 + 21);
}


// address=[0x154ecd0]
// Decompiled from int __thiscall CEntityTask::CEntityTask(int this, struct boost::exception_detail::clone_base *a2)
 CEntityTask::CEntityTask(class CEntityTask &&) {
  
  CPersistence::CPersistence((boost::exception_detail::clone_base *)this, a2);
  *(_DWORD *)this = &CEntityTask::_vftable_;
  *(_BYTE *)(this + 4) = *((_BYTE *)a2 + 4);
  *(_BYTE *)(this + 5) = *((_BYTE *)a2 + 5);
  *(_BYTE *)(this + 6) = *((_BYTE *)a2 + 6);
  *(_BYTE *)(this + 7) = *((_BYTE *)a2 + 7);
  *(_BYTE *)(this + 8) = *((_BYTE *)a2 + 8);
  *(_BYTE *)(this + 9) = *((_BYTE *)a2 + 9);
  *(_WORD *)(this + 10) = *((_WORD *)a2 + 5);
  *(_WORD *)(this + 12) = *((_WORD *)a2 + 6);
  *(_WORD *)(this + 14) = *((_WORD *)a2 + 7);
  *(_WORD *)(this + 16) = *((_WORD *)a2 + 8);
  *(_WORD *)(this + 18) = *((_WORD *)a2 + 9);
  *(_BYTE *)(this + 20) = *((_BYTE *)a2 + 20);
  *(_BYTE *)(this + 21) = *((_BYTE *)a2 + 21);
  return this;
}


// address=[0x1568830]
// Decompiled from int __cdecl CEntityTask::Load(int a1)
static class CEntityTask * __cdecl CEntityTask::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CEntityTask__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bb24]
// [Decompilation failed for static unsigned long CEntityTask::m_iClassID]

