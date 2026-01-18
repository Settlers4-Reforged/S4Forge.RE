#ifndef CQUICKSCAN_H
#define CQUICKSCAN_H

#include "defines.h"

class CQuickScan {
public:
    // address=[0x1305850]
     CQuickScan(int a2, int a3, unsigned int a4, unsigned int a5);

    // address=[0x1305900]
     CQuickScan(int a2, unsigned int a3, unsigned int a4);

    // address=[0x13059c0]
    bool  NextPosition(int & a2, int & a3);

    // address=[0x1306470]
    int  CenterSectorId(void)const;

};


#endif // CQUICKSCAN_H
