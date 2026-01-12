#ifndef CONEVEHICLETYPEITERATOR_H
#define CONEVEHICLETYPEITERATOR_H

class COneVehicleTypeIterator {
public:
    // address=[0x1315590]
    void  Init(int,int);

    // address=[0x13155c0]
    int  FirstVehicle(void);

    // address=[0x13155f0]
    int  NextVehicle(void);

    // address=[0x1315640]
    int  NextVehicleIfCurrentIsNotValid(void);

    // address=[0x1317290]
     COneVehicleTypeIterator(void);

};


#endif // CONEVEHICLETYPEITERATOR_H
