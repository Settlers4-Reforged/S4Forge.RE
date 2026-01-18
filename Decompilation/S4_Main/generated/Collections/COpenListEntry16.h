#ifndef COPENLISTENTRY16_H
#define COPENLISTENTRY16_H

#include "defines.h"

class COpenListEntry16 {
public:
    // address=[0x15d6090]
    bool  operator<(class COpenListEntry16 const & a2)const;

    // address=[0x15d65a0]
    int  G(void)const;

    // address=[0x15d6640]
    int  Index(void)const;

    // address=[0x15d6740]
    void  MaxItem(void);

    // address=[0x15d6d20]
    void  Set(int a2, int a3, int a4);

};


#endif // COPENLISTENTRY16_H
