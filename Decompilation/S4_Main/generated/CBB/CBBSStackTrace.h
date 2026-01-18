#ifndef BBSUPPORTLIB_CBBSSTACKTRACE_H
#define BBSUPPORTLIB_CBBSSTACKTRACE_H

#include "defines.h"

namespace BBSupportLib {

class CBBSStackTrace {
public:
    // address=[0x2f30fa0]
     CBBSStackTrace(void * a2, void * a3, struct _CONTEXT const & a4);

    // address=[0x2f30ff0]
    char const *  GetNextTraceStr(void);

};

} // namespace BBSupportLib

#endif // BBSUPPORTLIB_CBBSSTACKTRACE_H
