#ifndef CFILTERRESOURCELANDSCAPE_H
#define CFILTERRESOURCELANDSCAPE_H

class CFilterResourceLandscape : public IFilterEntry {
public:
    // address=[0x2f527d0]
     CFilterResourceLandscape(int,int,int,int,int);

    // address=[0x2f52820]
    virtual  ~CFilterResourceLandscape(void);

    // address=[0x2f52840]
    virtual float  GetFilterValue(void);

};


#endif // CFILTERRESOURCELANDSCAPE_H
