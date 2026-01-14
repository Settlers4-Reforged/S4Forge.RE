#ifndef COBJECTBLOB_H
#define COBJECTBLOB_H

class CObjectBlob : public CBlob {
public:
    // address=[0x2fca1a0]
     CObjectBlob(int,int,int,int,int,int,int,int,int,int,class CCheckLayer *);

protected:
    // address=[0x2fca200]
    virtual void  processFillPoint(int,int);

};


#endif // COBJECTBLOB_H
