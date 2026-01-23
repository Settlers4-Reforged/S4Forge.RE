#include "CInfoExchangeEx.h"

CInfoExchangeEx g_cInfoExchange{};

// Definitions for class CInfoExchangeEx

// address=[0x1454680]
// Decompiled from CInfoExchangeEx *__thiscall CInfoExchangeEx::CInfoExchangeEx(CInfoExchangeEx *this)
CInfoExchangeEx::CInfoExchangeEx(void) : CInfoExchange() {}

// address=[0x1454c50]
// Decompiled from int __thiscall CInfoExchangeEx::Size(CInfoExchangeEx *this)
unsigned int CInfoExchangeEx::Size(void) const
{
  return 8;
}
