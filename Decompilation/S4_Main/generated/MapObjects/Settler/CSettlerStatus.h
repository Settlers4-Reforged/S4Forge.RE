#ifndef CMANAKOPTER_CSETTLERSTATUS_H
#define CMANAKOPTER_CSETTLERSTATUS_H

#include "defines.h"

namespace CManakopter {

class CSettlerStatus {
public:
    // address=[0x1554910]
     CSettlerStatus(class CManakopter::CSettlerStatus const & a2);

    // address=[0x1554950]
     CSettlerStatus(int a2, enum SETTLER_TYPES a3, int a4);

    // address=[0x1554990]
     CSettlerStatus(void);

    // address=[0x1554b60]
     ~CSettlerStatus(void);

};

} // namespace CManakopter

#endif // CMANAKOPTER_CSETTLERSTATUS_H
