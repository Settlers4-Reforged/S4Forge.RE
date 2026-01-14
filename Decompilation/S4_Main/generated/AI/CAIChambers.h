#ifndef CAICHAMBERS_H
#define CAICHAMBERS_H

class CAIChambers {
public:
    // address=[0x1314700]
     CAIChambers(int);

    // address=[0x1314770]
    void  Push(int,int);

    // address=[0x1314880]
    void  PushTaskForce(class CAITaskForce &);

    // address=[0x13148e0]
    void  PushTaskForceEx(class CAITaskForce &,int);

    // address=[0x1314960]
    int  Next(void);

    // address=[0x1321b60]
    void  Clear(void);

    // address=[0x1321b90]
    int  Current(void);

    // address=[0x1321bd0]
    int  First(void);

};


#endif // CAICHAMBERS_H
