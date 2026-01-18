#ifndef COPENLISTENTRY24_H
#define COPENLISTENTRY24_H

#include "defines.h"

class COpenListEntry24 {
public:
    // address=[0x15d60d0]
    bool  operator<(class COpenListEntry24 const & a2)const;

    // address=[0x15d65c0]
    int  G(void)const;

    // address=[0x15d6660]
    int  Index(void)const;

    // address=[0x15d6760]
    void  MaxItem(void);

    // address=[0x15d6d50]
    void  Set(int a2, int a3, int a4);

};


#endif // COPENLISTENTRY24_H
