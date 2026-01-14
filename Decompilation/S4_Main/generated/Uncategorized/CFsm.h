#ifndef CFSM_H
#define CFSM_H

class CFsm {
public:
    // address=[0x1460490]
    int  CurrentState(void)const;

    // address=[0x2f05d80]
     CFsm(class IEventHandler *,int,int);

    // address=[0x2f05e40]
     ~CFsm(void);

    // address=[0x2f05e80]
    int  DefineTransition(int,int,int,int);

    // address=[0x2f05f00]
    int  Control(int,void *);

    // address=[0x2f06060]
    void  GenerateEvent(int,void *);

private:
    // address=[0x2f06080]
    void  InsertInQueue(int,void *);

    // address=[0x2f060f0]
    int  Hash(int,int);

    // address=[0x2f06170]
    int  Hash(int);

};


#endif // CFSM_H
