#ifndef CMANYSETTLERTYPESITERATOR_H
#define CMANYSETTLERTYPESITERATOR_H

#include "defines.h"

class CManySettlerTypesIterator {
public:
    // address=[0x13151c0]
    void  Init(int a2, int a3, int a4);

    // address=[0x1315200]
    int  FirstSettler(void);

    // address=[0x1315280]
    int  NextSettler(void);

    // address=[0x1315320]
    int  NextSettlerIfCurrentIsNotValid(void);

    // address=[0x1317210]
     CManySettlerTypesIterator(void);

};


#endif // CMANYSETTLERTYPESITERATOR_H
