#ifndef CFILTER_H
#define CFILTER_H

class CFilter {
public:
    // address=[0x2f393d0]
     CFilter(int);

    // address=[0x2f39480]
    virtual  ~CFilter(void);

    // address=[0x2f394d0]
    bool  AddFilterEntry(class IFilterEntry *);

    // address=[0x2f396b0]
    class IFilterEntry *  GetFilterEntry(int);

};


#endif // CFILTER_H
