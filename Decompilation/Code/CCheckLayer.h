#ifndef CCHECKLAYER_H
#define CCHECKLAYER_H

class CCheckLayer {
public:
    // address=[0x2fc85d0]
     CCheckLayer(int);

    // address=[0x2fc8630]
     ~CCheckLayer(void);

    // address=[0x2fc8660]
    unsigned short  getPoint(int,int);

    // address=[0x2fc8740]
    void  setPoint(int,int,unsigned short);

    // address=[0x2fc8820]
    void  clear(void);

};


#endif // CCHECKLAYER_H
