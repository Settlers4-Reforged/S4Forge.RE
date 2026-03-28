#include "CErrorMessages.h"

#include "Defines/Errors.h"

// Definitions for class CErrorMessages

CErrorMessages  s_cErrorMessages{};
CErrorMessages *g_pErrorMessages = &s_cErrorMessages;

// address=[0x14812a0]
// Decompiled from char *__thiscall CErrorMessages::GetErrorMessage(CErrorMessages *this, struct CErrorMessageId *a2)
char const *CErrorMessages::GetErrorMessage(CErrorMessageId const &a2) const {
  // [esp+4h] [ebp-4h]

  int Id = a2.GetId();
  if(Id != 1)
    Id = 0;
  return s_aErrorMessages[Id].m_uMessage;
}


// address=[0x1481360]
// Decompiled from CErrorMessages *__thiscall CErrorMessages::CErrorMessages(CErrorMessages *this)
CErrorMessages::CErrorMessages(void) : IErrorMessages() {}


