#ifndef SBUILDINFODATA_H
#define SBUILDINFODATA_H

#include "defines.h"

class SBUILDINFODATA {
public:
    // address=[0x1345840]
     SBUILDINFODATA(struct SBUILDINFODATA && a2);

    // address=[0x13458f0]
     SBUILDINFODATA(struct SBUILDINFODATA const & a2);

    // address=[0x13459a0]
     SBUILDINFODATA(void);

    // address=[0x1345e70]
     ~SBUILDINFODATA(void);

    // address=[0x13461d0]
    struct SBUILDINFODATA &  operator=(struct SBUILDINFODATA const & a2);

};


#endif // SBUILDINFODATA_H
