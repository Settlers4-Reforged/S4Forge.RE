#ifndef CPRODUCTIONPILEROLE_H
#define CPRODUCTIONPILEROLE_H

#include "defines.h"

class CProductionPileRole : public IPileRole {
public:
    // address=[0x14018a0]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x1560240]
    virtual  ~CProductionPileRole(void);

    // address=[0x1560300]
    virtual unsigned long  ClassID(void)const;

    // address=[0x1560400]
    static class CProductionPileRole * __cdecl Load(std::istream & a1);

    // address=[0x15615d0]
    virtual void  Init(class CPile * a2);

    // address=[0x1561680]
    virtual void  LogicUpdate(class CPile * a2);

    // address=[0x15616d0]
    virtual void  Increase(class CPile * a2, int a3);

    // address=[0x1561750]
    virtual void  ReassessDistance(class CPile * a2, int & a3);

    // address=[0x1561770]
     CProductionPileRole(std::istream & a2);

    // address=[0x1561820]
    virtual void  Store(std::ostream & a2);

    // address=[0x3d8be98]
    static unsigned long m_iClassID;

private:
    // address=[0x15601a0]
     CProductionPileRole(void);

};


#endif // CPRODUCTIONPILEROLE_H
