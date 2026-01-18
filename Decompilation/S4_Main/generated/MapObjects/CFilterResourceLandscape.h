#ifndef CFILTERRESOURCELANDSCAPE_H
#define CFILTERRESOURCELANDSCAPE_H

#include "defines.h"

class CFilterResourceLandscape : public IFilterEntry {
public:
    // address=[0x2f527d0]
     CFilterResourceLandscape(int a2, int a3, int a4, int a5, int a6);

    // address=[0x2f52820]
    virtual  ~CFilterResourceLandscape(void);

    // address=[0x2f52840]
    virtual float  GetFilterValue(void);

};


#endif // CFILTERRESOURCELANDSCAPE_H
