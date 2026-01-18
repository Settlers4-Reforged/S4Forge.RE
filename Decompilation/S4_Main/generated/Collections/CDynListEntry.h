#ifndef CDYNLISTENTRY_H
#define CDYNLISTENTRY_H

#include "defines.h"

class CDynListEntry {
public:
    // address=[0x2f3b640]
    virtual  ~CDynListEntry(void);

    // address=[0x2f3c790]
     CDynListEntry(void);

    // address=[0x2f3c7c0]
    virtual float  SortValue(int a2);

    // address=[0x2f4c910]
    int  GetIndex(void);

    // address=[0x2f4c9e0]
    class CDynListEntry *  Next(void);

};


#endif // CDYNLISTENTRY_H
