#include "CErrorMessageId.h"

#include "CBB/CBBSupport.h"
#include "Defines/Errors.h"

// Definitions for class CErrorMessageId

int s_uUnknownErrorMessageCount;

// address=[0x14810b0]
// Decompiled from int *__thiscall CErrorMessageId::CErrorMessageId(int *this, char *Str1)
CErrorMessageId::CErrorMessageId(char const *Str1) {
  this->m_uMessageId = 0;
 if(Str1 && *Str1) {
    for(int i = 1; i <= 1; ++i) {
      if(!strcmp(Str1, s_aErrorMessages[i].m_uName)) {
        this->m_uMessageId = i;
        return;
      }
    }
  }

  ++s_uUnknownErrorMessageCount;
  if(Str1)
    BBSupportTracePrintF(3, "Unkwown error message <%s>!", Str1);
  else
    BBSupportTracePrintF(3, "Unkwown error message <%s>!", "NULL");

  return;
}


// address=[0x1481160]
// Decompiled from CErrorMessageId *__thiscall CErrorMessageId::CErrorMessageId(CErrorMessageId *this, const struct CErrorMessageId *a2)
CErrorMessageId::CErrorMessageId(class CErrorMessageId const &a2) {
  this->m_uMessageId = a2.m_uMessageId;
}


// address=[0x1481180]
// Decompiled from int __thiscall CErrorMessageId::GetId(CErrorMessageId *this)
int CErrorMessageId::GetId(void) const {
  return this->m_uMessageId;
}


