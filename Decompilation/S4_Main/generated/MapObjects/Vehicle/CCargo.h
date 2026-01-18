#ifndef CFERRYSHIP_CCARGO_H
#define CFERRYSHIP_CCARGO_H

#include "defines.h"

namespace CFerryShip {

class CCargo {
public:
    // address=[0x159af90]
     CCargo(class CFerryShip::CCargo const & a2);

    // address=[0x159b010]
     CCargo(int a2, int a3, int a4, int a5);

    // address=[0x159b070]
     CCargo(void);

    // address=[0x159bab0]
    int  GetCargoSize(void);

};

} // namespace CFerryShip

#endif // CFERRYSHIP_CCARGO_H
