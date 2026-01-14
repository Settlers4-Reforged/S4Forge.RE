#ifndef CPARAM_H
#define CPARAM_H

class CParam : public CDynListEntry {
public:
    // address=[0x2f3e8a0]
     CParam(void);

    // address=[0x2f3e8f0]
     CParam(int,int,int,int);

    // address=[0x2f3e940]
     CParam(class CParam *);

    // address=[0x2f3e9a0]
    virtual  ~CParam(void);

    // address=[0x2f3e9c0]
    void  SetParameter(int,int,int,int);

    // address=[0x2f3ea00]
    void  SetParameterX(int,int);

    // address=[0x2f3ea70]
    int  ParamAreEqual(class CParam *);

};


#endif // CPARAM_H
