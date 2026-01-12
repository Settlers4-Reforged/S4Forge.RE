#ifndef CPREVIEWBLOB_H
#define CPREVIEWBLOB_H

class CPreviewBlob : public CBlob {
public:
    // address=[0x2fcca60]
     CPreviewBlob(int,int,int,int,int,int,int,class CCheckLayer *);

protected:
    // address=[0x2fccb20]
    virtual void  processFillPoint(int,int);

};


#endif // CPREVIEWBLOB_H
