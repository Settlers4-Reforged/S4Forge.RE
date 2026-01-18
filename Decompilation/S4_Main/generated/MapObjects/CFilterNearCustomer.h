#ifndef CFILTERNEARCUSTOMER_H
#define CFILTERNEARCUSTOMER_H

#include "defines.h"

class CFilterNearCustomer : public IFilterEntry {
public:
    // address=[0x2f58ab0]
     CFilterNearCustomer(int a2, int a3, enum T_BUILD_LEVEL a4, int a5);

    // address=[0x2f58b00]
    virtual float  GetFilterValue(void);

    // address=[0x2f5a090]
    virtual  ~CFilterNearCustomer(void);

};


#endif // CFILTERNEARCUSTOMER_H
