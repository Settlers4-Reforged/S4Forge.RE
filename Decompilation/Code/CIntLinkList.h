#ifndef CINTLINKLIST_H
#define CINTLINKLIST_H

class CIntLinkList {
public:
    // address=[0x15e2e50]
    void  Init(int);

    // address=[0x15e2e70]
    bool  SearchBackwards(int);

    // address=[0x15e6f60]
    int const &  operator[](int)const;

    // address=[0x15e72c0]
    int  OwnerTileId(void)const;

    // address=[0x15e7430]
    int  Size(void)const;

    // address=[0x15f3ea0]
     CIntLinkList(int);

    // address=[0x15f4010]
    int &  operator[](int);

    // address=[0x15f40e0]
    void  `default constructor closure'(void);

    // address=[0x15f5620]
    void  PushBack(int);

    // address=[0x15f5820]
    void  SetOwnerTileId(int);

};


#endif // CINTLINKLIST_H
