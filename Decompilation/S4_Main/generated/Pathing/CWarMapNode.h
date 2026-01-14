#ifndef CWARMAPNODE_H
#define CWARMAPNODE_H

class CWarMapNode {
public:
    // address=[0x13363e0]
    int  Next(void)const;

    // address=[0x154c020]
     CWarMapNode(void);

    // address=[0x154c0c0]
    bool  IsInWarMap(void)const;

    // address=[0x15fb590]
     ~CWarMapNode(void);

    // address=[0x15fc730]
    int  Prev(void)const;

protected:
    // address=[0x15fc750]
    void  SetNext(int);

    // address=[0x15fc770]
    void  SetPrev(int);

    // address=[0x15fc790]
    void  SetPrevNext(int,int);

};


#endif // CWARMAPNODE_H
