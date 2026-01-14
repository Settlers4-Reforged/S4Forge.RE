#ifndef CRIVER_H
#define CRIVER_H

class CRiver {
public:
    // address=[0x2fcb5a0]
     CRiver(int,int);

    // address=[0x2fcb760]
     CRiver(int,int,int);

    // address=[0x2fcbbf0]
     ~CRiver(void);

    // address=[0x2fcbc30]
    void  drawRiver(void);

protected:
    // address=[0x2fcbca0]
    void  drawRiverPart(int,int,int,int);

    // address=[0x2fcc380]
    int  findBorder(int,int);

};


#endif // CRIVER_H
