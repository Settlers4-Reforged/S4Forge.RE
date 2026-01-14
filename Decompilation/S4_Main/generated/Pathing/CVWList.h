#ifndef CVWLIST_H
#define CVWLIST_H

class CVWList {
public:
    // address=[0x1334ec0]
     CVWList(int,int,int);

    // address=[0x1335b10]
    struct SVW const &  CVWList::operator[](int)const;

    // address=[0x1336840]
    int  Size(void)const;

    // address=[0x15de830]
    void  CalculateOverlappingSquares(int,int,int);

protected:
    // address=[0x15e2cf0]
    void  PushEx(int &,int,int);

};


#endif // CVWLIST_H
