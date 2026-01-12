#ifndef CMOUNTAINBLOB_H
#define CMOUNTAINBLOB_H

class CMountainBlob : public CHeightBlob {
public:
    // address=[0x2fc9ac0]
     CMountainBlob(int,int,int,int,int,int,class CCheckLayer *);

protected:
    // address=[0x2fc9b00]
    virtual void  processFillPoint(int,int);

    // address=[0x2fc9c90]
    virtual void  processPoint(int,int);

};


#endif // CMOUNTAINBLOB_H
