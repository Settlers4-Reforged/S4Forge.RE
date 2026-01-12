#ifndef CFERRYSHIP_CCARGO_H
#define CFERRYSHIP_CCARGO_H

namespace CFerryShip {

class CCargo {
public:
    // address=[0x159af90]
     CCargo(class CFerryShip::CCargo const &);

    // address=[0x159b010]
     CCargo(int,int,int,int);

    // address=[0x159b070]
     CCargo(void);

    // address=[0x159bab0]
    int  GetCargoSize(void);

};

} // namespace CFerryShip

#endif // CFERRYSHIP_CCARGO_H
