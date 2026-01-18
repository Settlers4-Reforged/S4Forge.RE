#ifndef CFILTER_H
#define CFILTER_H

#include "defines.h"

class CFilter {
public:
    // address=[0x2f393d0]
     CFilter(int a2);

    // address=[0x2f39480]
    virtual  ~CFilter(void);

    // address=[0x2f394d0]
    bool  AddFilterEntry(class IFilterEntry * a2);

    // address=[0x2f396b0]
    class IFilterEntry *  GetFilterEntry(int a2);

};


#endif // CFILTER_H
