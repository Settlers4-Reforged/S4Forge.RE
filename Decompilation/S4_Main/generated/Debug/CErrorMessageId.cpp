#include "CErrorMessageId.h"

// Definitions for class CErrorMessageId

// address=[0x14810b0]
// Decompiled from int *__thiscall CErrorMessageId::CErrorMessageId(int *this, char *Str1)
 CErrorMessageId::CErrorMessageId(char const *) {
  
  int i; // [esp+8h] [ebp-4h]

  *this = 0;
  if ( Str1 && *Str1 )
  {
    for ( i = 1; i <= 1; ++i )
    {
      if ( !j__strcmp(Str1, (&Str2)[2 * i]) )
      {
        *this = i;
        return this;
      }
    }
  }
  ++dword_3F45094;
  if ( Str1 )
    BBSupportTracePrintF(3, "Unkwown error message <%s>!", Str1);
  else
    BBSupportTracePrintF(3, "Unkwown error message <%s>!", "NULL");
  return this;
}


// address=[0x1481160]
// Decompiled from CErrorMessageId *__thiscall CErrorMessageId::CErrorMessageId(CErrorMessageId *this, const struct CErrorMessageId *a2)
 CErrorMessageId::CErrorMessageId(class CErrorMessageId const &) {
  
  *(_DWORD *)this = *(_DWORD *)a2;
  return this;
}


// address=[0x1481180]
// Decompiled from int __thiscall CErrorMessageId::GetId(CErrorMessageId *this)
int  CErrorMessageId::GetId(void)const {
  
  return *(_DWORD *)this;
}


