#ifndef CSETTLERSPIRALWALK_H
#define CSETTLERSPIRALWALK_H

class CSettlerSpiralWalk {
public:
    // address=[0x1470530]
     CSettlerSpiralWalk(int,int,int);

    // address=[0x1470940]
    int  CurrentX(void)const;

    // address=[0x1470960]
    int  CurrentY(void)const;

    // address=[0x1513a40]
    bool  NextSettlerId(int &);

};


#endif // CSETTLERSPIRALWALK_H
