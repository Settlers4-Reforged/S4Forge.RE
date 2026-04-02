#if FALSE
#include "CErrorMessageId.h"

// Definitions for class CErrorMessageId

// address=[0x14810b0]
// Decompiled from CErrorMessageId *__thiscall CErrorMessageId::CErrorMessageId(CErrorMessageId *this, char *Str1)
 CErrorMessageId::CErrorMessageId(char const * Str1) {
  
  int i; // [esp+8h] [ebp-4h]

  this->m_uMessageId = 0;
  if ( Str1 && *Str1 )
  {
    for ( i = 1; i <= 1; ++i )
    {
      if ( !j__strcmp(Str1, s_aErrorMessages[i].m_uName) )
      {
        this->m_uMessageId = i;
        return this;
      }
    }
  }
  ++s_uUnknownErrorMessageCount;
  if ( Str1 )
    BBSupportTracePrintF(3, "Unkwown error message <%s>!", Str1);
  else
    BBSupportTracePrintF(3, "Unkwown error message <%s>!", "NULL");
  return this;
}


// address=[0x1481160]
// Decompiled from CErrorMessageId *__thiscall CErrorMessageId::CErrorMessageId(CErrorMessageId *this, const struct CErrorMessageId *a2)
 CErrorMessageId::CErrorMessageId(class CErrorMessageId const & a2) {
  
  this->m_uMessageId = a2->m_uMessageId;
  return this;
}


// address=[0x1481180]
// Decompiled from int __thiscall CErrorMessageId::GetId(CErrorMessageId *this)
int  CErrorMessageId::GetId(void)const {
  
  return this->m_uMessageId;
}


#endif // Already implemented
