#ifndef CINTLINKLIST_H
#define CINTLINKLIST_H

#include "defines.h"

class CIntLinkList {
public:
    // address=[0x15e2e50]
    void  Init(int a2);

    // address=[0x15e2e70]
    bool  SearchBackwards(int a2);

    // address=[0x15e6f60]
    int const &  operator[](int a2)const;

    // address=[0x15e72c0]
    int  OwnerTileId(void)const;

    // address=[0x15e7430]
    int  Size(void)const;

    // address=[0x15f3ea0]
     CIntLinkList(int a2);

    // address=[0x15f4010]
    int &  operator[](int a2);

    // address=[0x15f40e0]
    void  `default constructor closure'(void);

    // address=[0x15f5620]
    void  PushBack(int a2);

    // address=[0x15f5820]
    void  SetOwnerTileId(int a2);

};


#endif // CINTLINKLIST_H
