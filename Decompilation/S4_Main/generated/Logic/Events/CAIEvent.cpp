#if FALSE
#include "CAIEvent.h"

// Definitions for class CAIEvent

// address=[0x13095e0]
// Decompiled from unsigned int __cdecl CAIEvent::Pack(unsigned int _uDataA, unsigned int _uDataB)
int __cdecl CAIEvent::Pack(unsigned int _uDataA, unsigned int _uDataB) {
  
  if ( _uDataA > 0xFFFF && BBSupportDbgReport(2, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\LibraryDistribution\\Include\\AI_Event.h", 102, "_uDataA <= 0xFFFF") == 1 )
  {
    __debugbreak();
  }
  if ( _uDataB > 0xFFFF && BBSupportDbgReport(2, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\LibraryDistribution\\Include\\AI_Event.h", 103, "_uDataB <= 0xFFFF") == 1 )
  {
    __debugbreak();
  }
  return _uDataA | (_uDataB << 16);
}


// address=[0x1310220]
// Decompiled from CAIEvent *__thiscall CAIEvent::CAIEvent(CAIEvent *this, int _iType, int _iData1, int _iData2, int _iData3)
 CAIEvent::CAIEvent(int _iType, int _iData1, int _iData2, int _iData3) {
  
  this->m_iType = _iType;
  this->m_iData1 = _iData1;
  this->m_iData2 = _iData2;
  this->m_iData3 = _iData3;
  return this;
}


// address=[0x13140a0]
// Decompiled from int __cdecl CAIEvent::UnpackA(unsigned __int16 _iDataA)
unsigned int __cdecl CAIEvent::UnpackA(int _iDataA) {
  
  return _iDataA;
}


// address=[0x13140b0]
// Decompiled from int __cdecl CAIEvent::UnpackB(int _iDataB)
unsigned int __cdecl CAIEvent::UnpackB(int _iDataB) {
  
  return _iDataB >> 16;
}


// address=[0x1319600]
// Decompiled from int __thiscall CAIEvent::Data1(CAIEvent *this)
int  CAIEvent::Data1(void)const {
  
  return this->m_iData1;
}


// address=[0x1319620]
// Decompiled from int __thiscall CAIEvent::Data2(CAIEvent *this)
int  CAIEvent::Data2(void)const {
  
  return this->m_iData2;
}


// address=[0x1319640]
// Decompiled from int __thiscall CAIEvent::Data3(struct CAIEvent *this)
int  CAIEvent::Data3(void)const {
  
  return this->m_iData3;
}


// address=[0x1319b30]
// Decompiled from int __thiscall CAIEvent::Type(CAIEvent *this)
int  CAIEvent::Type(void)const {
  
  return this->m_iType;
}


#endif // Already implemented
