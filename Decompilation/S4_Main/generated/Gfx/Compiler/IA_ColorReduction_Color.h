#ifndef IA_COLORREDUCTION_COLOR_H
#define IA_COLORREDUCTION_COLOR_H

#include "defines.h"

class IA_ColorReduction_Color {
public:
    // address=[0x2fd3640]
     IA_ColorReduction_Color(void);

    // address=[0x2fd3660]
     IA_ColorReduction_Color(unsigned char a2, unsigned char a3, unsigned char a4);

    // address=[0x2fd3690]
    void  SetValues(unsigned char a2, unsigned char a3, unsigned char a4, unsigned char a5);

    // address=[0x2fd36c0]
    void  SetRed(unsigned char a2);

    // address=[0x2fd36e0]
    unsigned char  GetRed(void);

    // address=[0x2fd36f0]
    void  SetGreen(unsigned char a2);

    // address=[0x2fd3710]
    unsigned char  GetGreen(void);

    // address=[0x2fd3730]
    void  SetBlue(unsigned char a2);

    // address=[0x2fd3750]
    unsigned char  GetBlue(void);

    // address=[0x2fd3770]
    void  SetAlpha(unsigned char a2);

    // address=[0x2fd3790]
    unsigned char  GetAlpha(void);

};


#endif // IA_COLORREDUCTION_COLOR_H
