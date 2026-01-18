#ifndef CPROFILE_H
#define CPROFILE_H

#include "defines.h"

class CProfile {
public:
    // address=[0x2efd820]
     CProfile(void);

    // address=[0x2efd850]
    void  Clear(void);

    // address=[0x2efd880]
    void  Begin(void);

    // address=[0x2efd8a0]
    void  End(void);

    // address=[0x2efd920]
    double  TimeMs(void)const;

    // address=[0x2efd990]
    char const *  InfoStr(void)const;

    // address=[0x2efda70]
    char const *  TraceStr(void)const;

};


#endif // CPROFILE_H
