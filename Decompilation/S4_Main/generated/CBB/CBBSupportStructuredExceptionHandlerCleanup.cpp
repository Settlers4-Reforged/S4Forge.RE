#include "all_headers.h"

// Definitions for class CBBSupportStructuredExceptionHandlerCleanup

// address=[0x2f33240]
// Decompiled from int __thiscall CBBSupportStructuredExceptionHandlerCleanup::~CBBSupportStructuredExceptionHandlerCleanup(  CBBSupportStructuredExceptionHandlerCleanup *this)
 CBBSupportStructuredExceptionHandlerCleanup::~CBBSupportStructuredExceptionHandlerCleanup(void) {
  
  SetUnhandledExceptionFilter(0);
  return j___set_se_translator(0);
}


