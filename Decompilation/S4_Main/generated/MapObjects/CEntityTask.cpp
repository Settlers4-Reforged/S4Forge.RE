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
  this->m_iTask = _rCloneSource->m_iTask;
  this->m_iEntity = _rCloneSource->m_iEntity;
  this->m_iDir = _rCloneSource->m_iDir;
  this->m_iDuration = _rCloneSource->m_iDuration;
  this->m_iFrameCount = _rCloneSource->m_iFrameCount;
  this->m_iTrigger = _rCloneSource->m_iTrigger;
  this->m_iX = _rCloneSource->m_iX;
  this->m_iY = _rCloneSource->m_iY;
  this->m_iJobNr = _rCloneSource->m_iJobNr;
  this->m_uData9 = _rCloneSource->m_uData9;
  this->m_uData10 = _rCloneSource->m_uData10;
  this->m_bVisible = _rCloneSource->m_bVisible;
  this->m_bForward = _rCloneSource->m_bForward;
  return this;
}


// address=[0x14d8620]
// Decompiled from int __thiscall CEntityTask::ClassID(CEntityTask *this)
unsigned long  CEntityTask::ClassID(void)const {
  
  return CEntityTask::m_iClassID;
}


// address=[0x14dfb60]
// Decompiled from CEntityTask *__thiscall CEntityTask::CEntityTask(  CEntityTask *this,  int _iTask,  int _iJobNr,  int _iX,  int _iY,  int _iDuration,  int _iFrameCount,  int _iDir,  bool _bForward,  bool _bVisible,  int _iEntity,  unsigned int a12,  unsigned int a13,  unsigned int _iTrigger)
 CEntityTask::CEntityTask(int _iTask, int _iJobNr, int _iX, int _iY, int _iDuration, int _iFrameCount, int _iDir, bool _bForward, bool _bVisible, int _iEntity, unsigned int a12, unsigned int a13, unsigned int _iTrigger) {
  
  CPersistence::CPersistence(this);
  this->__vftable = (CPersistence_vtbl *)&CEntityTask::_vftable_;
  this->m_iTask = _iTask;
  this->m_iEntity = _iEntity;
  this->m_iDir = _iDir;
  this->m_iDuration = _iDuration;
  this->m_iFrameCount = _iFrameCount;
  this->m_iTrigger = _iTrigger;
  this->m_iX = _iX;
  this->m_iY = _iY;
  this->m_iJobNr = _iJobNr;
  this->m_uData9 = a12;
  this->m_uData10 = a13;
  this->m_bVisible = _bVisible;
  this->m_bForward = _bForward;
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
  operator^<unsigned char>(a2, &this->m_iTask);
  operator^<unsigned char>(a2, &this->m_iEntity);
  operator^<signed char>(a2, &this->m_iDir);
  operator^<signed char>(a2, &this->m_iDuration);
  operator^<signed char>(a2, &this->m_iFrameCount);
  operator^<unsigned char>(a2, &this->m_iTrigger);
  operator^<short>(a2, &this->m_iX);
  operator^<short>(a2, &this->m_iY);
  operator^<unsigned short>(a2, &this->m_iJobNr);
  operator^<unsigned short>(a2, &this->m_uData9);
  operator^<unsigned short>(a2, &this->m_uData10);
  operator^<bool>(a2, &this->m_bVisible);
  operator^<bool>(a2, &this->m_bForward);
  return this;
}


// address=[0x154c440]
// Decompiled from void __thiscall CEntityTask::Store(CEntityTask *this, struct std::ostream *a1)
void  CEntityTask::Store(std::ostream & a1) {
  
  int v2; // [esp+0h] [ebp-8h] BYREF

  CPersistence::Store(this, a1);
  v2 = 1;
  operator^<unsigned int>(a1, &v2);
  operator^<unsigned char>(a1, &this->m_iTask);
  operator^<unsigned char>(a1, &this->m_iEntity);
  operator^<signed char>(a1, &this->m_iDir);
  operator^<signed char>(a1, &this->m_iDuration);
  operator^<signed char>(a1, &this->m_iFrameCount);
  operator^<unsigned char>(a1, &this->m_iTrigger);
  operator^<short>(a1, &this->m_iX);
  operator^<short>(a1, &this->m_iY);
  operator^<unsigned short>(a1, &this->m_iJobNr);
  operator^<unsigned short>(a1, &this->m_uData9);
  operator^<unsigned short>(a1, &this->m_uData10);
  operator^<bool>(a1, &this->m_bVisible);
  operator^<bool>(a1, &this->m_bForward);
}


// address=[0x154ecd0]
// Decompiled from CEntityTask *__thiscall CEntityTask::CEntityTask(CEntityTask *this, struct CEntityTask *a2)
 CEntityTask::CEntityTask(class CEntityTask && a2) {
  
  CPersistence::CPersistence(
    (boost::exception_detail::clone_base *)this,
    (const struct boost::exception_detail::clone_base *)a2);
  this->__vftable = (CPersistence_vtbl *)&CEntityTask::_vftable_;
  this->m_iTask = a2->m_iTask;
  this->m_iEntity = a2->m_iEntity;
  this->m_iDir = a2->m_iDir;
  this->m_iDuration = a2->m_iDuration;
  this->m_iFrameCount = a2->m_iFrameCount;
  this->m_iTrigger = a2->m_iTrigger;
  this->m_iX = a2->m_iX;
  this->m_iY = a2->m_iY;
  this->m_iJobNr = a2->m_iJobNr;
  this->m_uData9 = a2->m_uData9;
  this->m_uData10 = a2->m_uData10;
  this->m_bVisible = a2->m_bVisible;
  this->m_bForward = a2->m_bForward;
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
