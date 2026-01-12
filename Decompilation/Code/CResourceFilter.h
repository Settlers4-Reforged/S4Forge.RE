#ifndef CRESOURCEFILTER_H
#define CRESOURCEFILTER_H

class CResourceFilter : public IFilterEntry {
public:
    // address=[0x2f56770]
     CResourceFilter(int,int,int);

    // address=[0x2f567b0]
    virtual  ~CResourceFilter(void);

    // address=[0x2f567d0]
    virtual float  GetFilterValue(void);

};


#endif // CRESOURCEFILTER_H
