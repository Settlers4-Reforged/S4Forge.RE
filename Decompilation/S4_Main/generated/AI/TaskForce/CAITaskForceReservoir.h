#ifndef CAITASKFORCERESERVOIR_H
#define CAITASKFORCERESERVOIR_H

class CAITaskForceReservoir : public CAITaskForce {
public:
    // address=[0x13191d0]
     CAITaskForceReservoir(int);

    // address=[0x13192d0]
    virtual  ~CAITaskForceReservoir(void);

    // address=[0x13196a0]
    virtual void  Execute(void);

};


#endif // CAITASKFORCERESERVOIR_H
