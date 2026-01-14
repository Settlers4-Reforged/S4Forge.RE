#ifndef CLANDBLOB_H
#define CLANDBLOB_H

class CLandBlob : public CBlob {
public:
    // address=[0x2fc9de0]
     CLandBlob(int,int,int,int,bool,int,int,int,class CCheckLayer *);

protected:
    // address=[0x2fc9eb0]
    virtual void  processPoint(int,int);

    // address=[0x2fc9f50]
    virtual void  processFillPoint(int,int);

};


#endif // CLANDBLOB_H
