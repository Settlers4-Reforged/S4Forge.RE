#if FALSE
#include "CEntityTask.h"

// Definitions for class CEntityTask

// address=[0x14007c0]
// Decompiled from CEntityTask *__cdecl CEntityTask::New(int a1)
class CPersistence * __cdecl CEntityTask::New(std::istream & a1) {
  
  CEntityTask *C; // [esp+Ch] [ebp-10h]

  C = (CEntityTask *)operator new(24u);
  if ( C )
    return CEntityTask::CEntityTask(C, a1);
  else
    return 0;
}


// address=[0x14d7e80]
// Decompiled from CEntityTask *__thiscall CEntityTask::CEntityTask(CEntityTask *this, CEntityTask *_rCloneSource)
 CEntityTask::CEntityTask(class CEntityTask const & _rCloneSource) {
  
  CPersistence::CPersistence(this);
  this->__vftable = (CPersistence_vtbl *)&CEntityTask::_vftable_;
  this->m_uData0 = _rCloneSource->m_uData0;
  this->m_uData1 = _rCloneSource->m_uData1;
  this->m_iData2 = _rCloneSource->m_iData2;
  this->m_iData3 = _rCloneSource->m_iData3;
  this->m_iData4 = _rCloneSource->m_iData4;
  this->m_uData5 = _rCloneSource->m_uData5;
  this->m_iData6 = _rCloneSource->m_iData6;
  this->m_iData7 = _rCloneSource->m_iData7;
  this->m_uData8 = _rCloneSource->m_uData8;
  this->m_uData9 = _rCloneSource->m_uData9;
  this->m_uData10 = _rCloneSource->m_uData10;
  this->m_bData11 = _rCloneSource->m_bData11;
  this->m_bData12 = _rCloneSource->m_bData12;
  return this;
}


// address=[0x14d8620]
// Decompiled from int __thiscall CEntityTask::ClassID(CEntityTask *this)
unsigned long  CEntityTask::ClassID(void)const {
  
  return CEntityTask::m_iClassID;
}


// address=[0x14dfb60]
// Decompiled from CEntityTask *__thiscall CEntityTask::CEntityTask(  CEntityTask *this,  unsigned __int8 a2,  unsigned __int16 a3,  __int16 a4,  __int16 a5,  char a6,  char a7,  char a8,  bool a9,  bool a10,  unsigned __int8 a11,  unsigned __int16 a12,  unsigned __int16 a13,  unsigned __int8 a14)
 CEntityTask::CEntityTask(int a2, int a3, int a4, int a5, int a6, int a7, int a8, bool a9, bool a10, int a11, unsigned int a12, unsigned int a13, unsigned int a14) {
  
  CPersistence::CPersistence(this);
  this->__vftable = (CPersistence_vtbl *)&CEntityTask::_vftable_;
  this->m_uData0 = a2;
  this->m_uData1 = a11;
  this->m_iData2 = a8;
  this->m_iData3 = a6;
  this->m_iData4 = a7;
  this->m_uData5 = a14;
  this->m_iData6 = a4;
  this->m_iData7 = a5;
  this->m_uData8 = a3;
  this->m_uData9 = a12;
  this->m_uData10 = a13;
  this->m_bData11 = a10;
  this->m_bData12 = a9;
  return this;
}


// address=[0x154c2d0]
// Decompiled from CEntityTask *__thiscall CEntityTask::CEntityTask(CEntityTask *this, int a2)
 CEntityTask::CEntityTask(std::istream & a2) {
  
  int v3; // [esp+4h] [ebp-Ch] BYREF
  int pExceptionObject; // [esp+8h] [ebp-8h] BYREF

  CPersistence::CPersistence(this);
  this->__vftable = (CPersistence_vtbl *)&CEntityTask::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CEntityTask");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a2, &this->m_uData0);
  operator^<unsigned char>(a2, &this->m_uData1);
  operator^<signed char>(a2, &this->m_iData2);
  operator^<signed char>(a2, &this->m_iData3);
  operator^<signed char>(a2, &this->m_iData4);
  operator^<unsigned char>(a2, &this->m_uData5);
  operator^<short>(a2, &this->m_iData6);
  operator^<short>(a2, &this->m_iData7);
  operator^<unsigned short>(a2, &this->m_uData8);
  operator^<unsigned short>(a2, &this->m_uData9);
  operator^<unsigned short>(a2, &this->m_uData10);
  operator^<bool>(a2, &this->m_bData11);
  operator^<bool>(a2, &this->m_bData12);
  return this;
}


// address=[0x154c440]
// Decompiled from void __thiscall CEntityTask::Store(CEntityTask *this, struct std::ostream *a1)
void  CEntityTask::Store(std::ostream & a1) {
  
  int v2; // [esp+0h] [ebp-8h] BYREF

  CPersistence::Store(this, a1);
  v2 = 1;
  operator^<unsigned int>(a1, &v2);
  operator^<unsigned char>(a1, &this->m_uData0);
  operator^<unsigned char>(a1, &this->m_uData1);
  operator^<signed char>(a1, &this->m_iData2);
  operator^<signed char>(a1, &this->m_iData3);
  operator^<signed char>(a1, &this->m_iData4);
  operator^<unsigned char>(a1, &this->m_uData5);
  operator^<short>(a1, &this->m_iData6);
  operator^<short>(a1, &this->m_iData7);
  operator^<unsigned short>(a1, &this->m_uData8);
  operator^<unsigned short>(a1, &this->m_uData9);
  operator^<unsigned short>(a1, &this->m_uData10);
  operator^<bool>(a1, &this->m_bData11);
  operator^<bool>(a1, &this->m_bData12);
}


// address=[0x154ecd0]
// Decompiled from CEntityTask *__thiscall CEntityTask::CEntityTask(CEntityTask *this, struct CEntityTask *a2)
 CEntityTask::CEntityTask(class CEntityTask && a2) {
  
  CPersistence::CPersistence(
    (boost::exception_detail::clone_base *)this,
    (const struct boost::exception_detail::clone_base *)a2);
  this->__vftable = (CPersistence_vtbl *)&CEntityTask::_vftable_;
  this->m_uData0 = a2->m_uData0;
  this->m_uData1 = a2->m_uData1;
  this->m_iData2 = a2->m_iData2;
  this->m_iData3 = a2->m_iData3;
  this->m_iData4 = a2->m_iData4;
  this->m_uData5 = a2->m_uData5;
  this->m_iData6 = a2->m_iData6;
  this->m_iData7 = a2->m_iData7;
  this->m_uData8 = a2->m_uData8;
  this->m_uData9 = a2->m_uData9;
  this->m_uData10 = a2->m_uData10;
  this->m_bData11 = a2->m_bData11;
  this->m_bData12 = a2->m_bData12;
  return this;
}


// address=[0x1568830]
// Decompiled from struct CEntityTask *__cdecl CEntityTask::Load(struct std::istream *a1)
class CEntityTask * __cdecl CEntityTask::Load(std::istream & a1) {
  
  void **v1; // eax

  v1 = (void **)CPersistence::New(a1);
  return (struct CEntityTask *)j____RTDynamicCast(
                                 v1,
                                 0,
                                 &CPersistence__RTTI_Type_Descriptor_,
                                 &CEntityTask__RTTI_Type_Descriptor_,
                                 1);
}


// address=[0x3d8bb24]
// [Decompilation failed for static unsigned long CEntityTask::m_iClassID]

#endif // Already implemented
