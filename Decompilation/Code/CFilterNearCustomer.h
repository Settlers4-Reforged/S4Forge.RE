#ifndef CFILTERNEARCUSTOMER_H
#define CFILTERNEARCUSTOMER_H

class CFilterNearCustomer : public IFilterEntry {
public:
    // address=[0x2f58ab0]
     CFilterNearCustomer(int,int,enum T_BUILD_LEVEL,int);

    // address=[0x2f58b00]
    virtual float  GetFilterValue(void);

    // address=[0x2f5a090]
    virtual  ~CFilterNearCustomer(void);

};


#endif // CFILTERNEARCUSTOMER_H
