#ifndef CBLOB_H
#define CBLOB_H

class CBlob {
public:
    // address=[0x2fc88f0]
     CBlob(void);

    // address=[0x2fc8910]
     CBlob(int,int,int,int,int,int,int,class CCheckLayer *);

    // address=[0x2fc8be0]
    void  drawBlob(void);

protected:
    // address=[0x2fc9100]
    virtual void  fillBlob(int,int);

    // address=[0x2fc9490]
    int  getNextDirection(int,int);

    // address=[0x2fc95d0]
    virtual void  processPoint(int,int);

};


#endif // CBLOB_H
