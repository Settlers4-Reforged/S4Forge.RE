#include "CAIConfigIntEx.h"

// Definitions for class CAIConfigIntEx

// address=[0x131e810]
// Decompiled from CAIConfigIntEx *__thiscall CAIConfigIntEx::CAIConfigIntEx(CAIConfigIntEx *this, const char *a2, int a3, int a4, int a5)
CAIConfigIntEx::CAIConfigIntEx(char const *_spVarName,
                               int         _iDefault0,
                               int         _iDefault1,
                               int         _iDefault2)
    : TStaticConfigIntArray<3>(
          "AI",
          _spVarName,
          _iDefault0,
          // Dont ask.. dont know...
          (_iDefault1 == 0x80000000 ? _iDefault0 : _iDefault1),
          (_iDefault2 != 0x80000000
               ? _iDefault2
               : (_iDefault1 != 0x80000000 ? _iDefault1 : _iDefault0))
      ),
      m_spName(_spVarName) {}

// {
//   int v6; // [esp+4h] [ebp-Ch]
//   int v7; // [esp+8h] [ebp-8h]
//
//   if(_iDefault2 == 0x80000000) {
//     if(_iDefault1 == 0x80000000)
//       v7 = _iDefault0;
//     else
//       v7 = _iDefault1;
//     v6 = v7;
//   } else {
//     v6 = _iDefault2;
//   }
//   if(_iDefault1 == 0x80000000)
//     TStaticConfigIntArray<3>("AI", _spVarName, _iDefault0, _iDefault0, v6);
//   else
//     TStaticConfigIntArray<3>("AI", _spVarName, _iDefault0, _iDefault1, v6);
//
//   // NOTE: I don't know why the name is only here and not further up the stream in the other ConfigVar base classes...
//   this->m_spName = _spVarName;
// }


// address=[0x131ea80]
// Decompiled from int __thiscall CAIConfigIntEx::~CAIConfigIntEx(CAIConfigIntEx *this)
CAIConfigIntEx::~CAIConfigIntEx(void) = default;

// address=[0x131ecd0]
// Decompiled from int __thiscall CAIConfigIntEx::Name(CAIConfigIntEx *this)
char const *CAIConfigIntEx::Name(void) const {
    return this->m_spName;
}


