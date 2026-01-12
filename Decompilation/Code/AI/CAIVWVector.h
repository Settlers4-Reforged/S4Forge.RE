#ifndef CAIVWVECTOR_H
#define CAIVWVECTOR_H

class CAIVWVector {
public:
    // address=[0x1334d40]
     CAIVWVector(void);

    // address=[0x1335450]
     ~CAIVWVector(void);

    // address=[0x1335ee0]
    int  At(int)const;

    // address=[0x1335f30]
    void  Clear(void);

    // address=[0x1336240]
    int  Index(int)const;

    // address=[0x1336440]
    void  PushBack(int);

    // address=[0x13365a0]
    void  Remove(int);

    // address=[0x1336820]
    int  Size(void)const;

};


#endif // CAIVWVECTOR_H
