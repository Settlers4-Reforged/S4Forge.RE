#ifndef BBSUPPORTLIB_CBBSSTACKTRACE_H
#define BBSUPPORTLIB_CBBSSTACKTRACE_H

namespace BBSupportLib {

class CBBSStackTrace {
public:
    // address=[0x2f30fa0]
     CBBSStackTrace(void *,void *,struct _CONTEXT const &);

    // address=[0x2f30ff0]
    char const *  GetNextTraceStr(void);

};

} // namespace BBSupportLib

#endif // BBSUPPORTLIB_CBBSSTACKTRACE_H
