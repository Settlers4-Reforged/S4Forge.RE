#ifndef CSCROLLMULTILINE_H
#define CSCROLLMULTILINE_H

#include "defines.h"

class CScrollMultiline {
public:
    // address=[0x1377dc0]
     ~CScrollMultiline(void);

    // address=[0x13da4c0]
     CScrollMultiline(int a2, int a3, int a4, int a5, int a6);

    // address=[0x13da540]
    void  ScrollUp(void);

    // address=[0x13da5a0]
    void  ScrollDown(void);

    // address=[0x13da610]
    void  SetText(char const * a2);

private:
    // address=[0x13da090]
    unsigned char *  GetWrapPointer(unsigned char * Str);

    // address=[0x13da3c0]
    unsigned char *  GetCRLFWrapPointer(unsigned char *,unsigned char *);

    // address=[0x13da440]
    void  SplitText(void);

};


#endif // CSCROLLMULTILINE_H
