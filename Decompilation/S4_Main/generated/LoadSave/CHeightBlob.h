#ifndef CHEIGHTBLOB_H
#define CHEIGHTBLOB_H

class CHeightBlob : public CBlob {
public:
    // address=[0x2fccbb0]
     CHeightBlob(int,int,int,int,int,int,class CCheckLayer *);

protected:
    // address=[0x2fccce0]
    virtual void  fillBlob(int,int);

    // address=[0x2fcd100]
    virtual void  processFillPoint(int,int);

};


#endif // CHEIGHTBLOB_H
