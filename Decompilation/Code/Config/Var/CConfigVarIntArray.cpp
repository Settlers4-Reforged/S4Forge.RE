#include "CConfigVarIntArray.h"

// Definitions for class CConfigVarIntArray

// address=[0x2efa070]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
int __thiscall CConfigVarIntArray::GetIntArray(CConfigVarIntArray *this)

int *  CConfigVarIntArray::GetIntArray(void) {
  
  return *((_DWORD *)this + 2);
}


// address=[0x2efa090]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
int __thiscall CConfigVarIntArray::GetIntArray(CConfigVarIntArray *this)

int const *  CConfigVarIntArray::GetIntArray(void)const {
  
  return *((_DWORD *)this + 2);
}


// address=[0x2eeef30]
// Decompiled from void **__thiscall CConfigVarIntArray::CConfigVarIntArray(void **this, void *Src, int a3)

 CConfigVarIntArray::CConfigVarIntArray(int const *,int) {
  
  CDynamicConfigVar::CDynamicConfigVar(this, 2, a3);
  *this = &CConfigVarIntArray::_vftable_;
  if ( a3 <= 0 && BBSupportDbgReport(2, "Source\\ConfigManager\\ConfigManager.cpp", 1352, "_iSize > 0") == 1 )
    __debugbreak();
  if ( a3 >= 256 && BBSupportDbgReport(2, "Source\\ConfigManager\\ConfigManager.cpp", 1353, "_iSize < 256") == 1 )
    __debugbreak();
  this[2] = operator new[](
              (unsigned __int64)(unsigned int)a3 >> 30 != 0 ? -1 : 4 * a3,
              1,
              "Source\\ConfigManager\\ConfigManager.cpp",
              1355);
  if ( Src )
    j__memcpy(this[2], Src, 4 * a3);
  else
    j__memset(this[2], 0, 4 * a3);
  return this;
}


// address=[0x2eef050]
// Decompiled from void __thiscall CConfigVarIntArray::~CConfigVarIntArray(void **this)

 CConfigVarIntArray::~CConfigVarIntArray(void) {
  
  *this = &CConfigVarIntArray::_vftable_;
  operator delete(this[2]);
  CDynamicConfigVar::~CDynamicConfigVar((CDynamicConfigVar *)this);
}


