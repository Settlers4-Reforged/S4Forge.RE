#ifndef CSPIRALWALK_H
#define CSPIRALWALK_H

class CSpiralWalk {
public:
    // address=[0x1306230]
     CSpiralWalk(int,int,int);

    // address=[0x1306800]
    bool  NextXY(int &,int &);

    // address=[0x1509f30]
    int  CurrentRadius(void)const;

};


#endif // CSPIRALWALK_H
