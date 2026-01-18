#ifndef CNOTIFYEXCEPTMUSHROOMFARMER_H
#define CNOTIFYEXCEPTMUSHROOMFARMER_H

#include "defines.h"

class CNotifyExceptMushroomfarmer : public INotifyFilter {
public:
    // address=[0x1508120]
     CNotifyExceptMushroomfarmer(void);

    // address=[0x1508190]
    virtual bool  NotifyEntity(class IEntity const & a2);

};


#endif // CNOTIFYEXCEPTMUSHROOMFARMER_H
