#ifndef SSQUADVALUE_H
#define SSQUADVALUE_H

#include "defines.h"

class SSquadValue {
public:
    // address=[0x1301060]
    bool  operator<(struct SSquadValue const & a2)const;

    // address=[0x1301570]
    void  MaxItem(void);

};


#endif // SSQUADVALUE_H
