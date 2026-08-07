#ifndef CBLOB_H
#define CBLOB_H

#include "defines.h"

class CBlob {
public:
    // address=[0x2fc88f0]
     CBlob(void);

    // address=[0x2fc8910]
     CBlob(int a2, int a3, int a4, int a5, int a6, int a7, int a8, class CCheckLayer * a9);

    // address=[0x2fc8be0]
    void  drawBlob(void);

protected:
    // address=[0x2fc9100]
    virtual void  fillBlob(int a2, int a3);

    // address=[0x2fc9490]
    int  getNextDirection(int a2, int a3);

    // address=[0x2fc95d0]
    virtual void  processPoint(int _iX, int _iY);

    // Type information members
public:
    int m_iU1;
    int m_iU2;
    int m_iWorldSize;
    int m_iMinX;
    int m_iMinY;
    int m_iMaxX;
    int m_iMaxY;
    CCheckLayer * m_pCheckLayer;
    int m_iU3;
    int m_iU4;

};


#endif // CBLOB_H
