#ifndef CFILTERCUSTOMER_H
#define CFILTERCUSTOMER_H

class CFilterCustomer : public IFilterEntry {
public:
    // address=[0x2f589d0]
     CFilterCustomer(class CProductivityControll *,class CProductivityControll *);

    // address=[0x2f58a60]
    virtual  ~CFilterCustomer(void);

    // address=[0x2f58a80]
    virtual float  GetFilterValue(void);

};


#endif // CFILTERCUSTOMER_H
