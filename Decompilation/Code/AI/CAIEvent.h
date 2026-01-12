#ifndef CAIEVENT_H
#define CAIEVENT_H

class CAIEvent {
public:
    // address=[0x13095e0]
    static int __cdecl Pack(unsigned int,unsigned int);

    // address=[0x1310220]
     CAIEvent(int,int,int,int);

    // address=[0x13140a0]
    static unsigned int __cdecl UnpackA(int);

    // address=[0x13140b0]
    static unsigned int __cdecl UnpackB(int);

    // address=[0x1319600]
    int  Data1(void)const;

    // address=[0x1319620]
    int  Data2(void)const;

    // address=[0x1319640]
    int  Data3(void)const;

    // address=[0x1319b30]
    int  Type(void)const;

};


#endif // CAIEVENT_H
