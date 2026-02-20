#if FALSE
#include "CConfigVarIntArray.h"

// Definitions for class CConfigVarIntArray

// address=[0x2efa070]
// Decompiled from int *__thiscall CConfigVarIntArray::GetIntArray(CConfigVarIntArray *this)
int *  CConfigVarIntArray::GetIntArray(void) {
  
  return this->value;
}


// address=[0x2efa090]
// Decompiled from int *__thiscall CConfigVarIntArray::GetIntArray(CConfigVarIntArray *this)
int const *  CConfigVarIntArray::GetIntArray(void)const {
  
  return this->value;
}


// address=[0x2eeef30]
// Decompiled from CConfigVarIntArray *__thiscall CConfigVarIntArray::CConfigVarIntArray(CConfigVarIntArray *this, void *Src, int _iSize)
 CConfigVarIntArray::CConfigVarIntArray(int const * Src, int _iSize) {
  
  CDynamicConfigVar::CDynamicConfigVar(this, CONFIGVAR_TYPE_INT_ARRAY, _iSize);
  this->__vftable = (CConfigVar_vtbl *)&CConfigVarIntArray::_vftable_;
  if ( _iSize <= 0 && BBSupportDbgReport(2, "Source\\ConfigManager\\ConfigManager.cpp", 1352, "_iSize > 0") == 1 )
    __debugbreak();
  if ( _iSize >= 256 && BBSupportDbgReport(2, "Source\\ConfigManager\\ConfigManager.cpp", 1353, "_iSize < 256") == 1 )
    __debugbreak();
  this->value = (int *)operator new[](
                         (unsigned __int64)(unsigned int)_iSize >> 0x1E != 0 ? -1 : 4 * _iSize,
                         1,
                         "Source\\ConfigManager\\ConfigManager.cpp",
                         1355);
  if ( Src )
    memcpy(this->value, Src, 4 * _iSize);
  else
    memset(this->value, 0, 4 * _iSize);
  return this;
}


// address=[0x2eef050]
// Decompiled from void __thiscall CConfigVarIntArray::~CConfigVarIntArray(void **this)
 CConfigVarIntArray::~CConfigVarIntArray(void) {
  
  *this = &CConfigVarIntArray::_vftable_;
  operator delete(this[2]);
  CDynamicConfigVar::~CDynamicConfigVar((CDynamicConfigVar *)this);
}


#endif // Already implemented
