#ifndef BBSUPPORTLIB_CBBSUPPORTTRACEFILEPTR_H
#define BBSUPPORTLIB_CBBSUPPORTTRACEFILEPTR_H

namespace BBSupportLib {

class CBBSupportTraceFilePtr {
public:
    // address=[0x2f2f940]
    class BBSupportLib::IBBSupportTraceFile *  operator->(void);

private:
    // address=[0x4686d54]
    static class BBSupportLib::IBBSupportTraceFile * m_pTraceFile;

};

} // namespace BBSupportLib

#endif // BBSUPPORTLIB_CBBSUPPORTTRACEFILEPTR_H
