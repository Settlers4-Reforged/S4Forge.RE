#ifndef CLINKLIST_H
#define CLINKLIST_H

class CLinkList {
public:
    // address=[0x1346460]
    unsigned short const &  operator[](int)const;

    // address=[0x13469a0]
    int  Size(void)const;

    // address=[0x15e2ec0]
    void  DbgPrint(void)const;

    // address=[0x15e6e60]
    class CLinkList &  operator=(class CLinkList const &);

    // address=[0x15e6ed0]
    class CLinkList &  operator=(class CIntLinkList const &);

    // address=[0x15e7230]
    class CLink const &  Link(int)const;

    // address=[0x15e72e0]
    int  OwnerTileId(void)const;

    // address=[0x15e7300]
    bool  SearchForLinkTileId(int)const;

    // address=[0x15f49c0]
    int  Marker(void)const;

};


#endif // CLINKLIST_H
