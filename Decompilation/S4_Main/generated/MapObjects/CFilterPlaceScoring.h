#ifndef CFILTERPLACESCORING_H
#define CFILTERPLACESCORING_H

#include "defines.h"

class CFilterPlaceScoring : public IFilterEntry {
public:
    // address=[0x2f39700]
     CFilterPlaceScoring(void);

    // address=[0x2f39720]
     CFilterPlaceScoring(class CSchedule * a2, struct SBUILDINFODATA * a3, int a4, int a5, int a6);

    // address=[0x2f39800]
    virtual  ~CFilterPlaceScoring(void);

    // address=[0x2f39820]
    virtual float  GetFilterValue(void);

};


#endif // CFILTERPLACESCORING_H
