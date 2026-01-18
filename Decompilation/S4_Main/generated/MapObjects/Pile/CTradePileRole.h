#ifndef CTRADEPILEROLE_H
#define CTRADEPILEROLE_H

#include "defines.h"

class CTradePileRole : public IPileRole {
public:
    // address=[0x14023e0]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x1560480]
    static class CTradePileRole * __cdecl Load(std::istream & a1);

    // address=[0x1561a70]
    virtual void  Increase(class CPile * a2, int a3);

    // address=[0x1561b70]
    virtual void  Decrease(class CPile * a2, int a3);

    // address=[0x1561c90]
    virtual void  Empty(class CPile * a2);

    // address=[0x1561d60]
    virtual void  Init(class CPile * a2);

    // address=[0x1561de0]
    virtual void  LogicUpdate(class CPile * a2);

    // address=[0x1561f40]
    virtual void  Occupied(class CPile * a2, int a3);

    // address=[0x1561fc0]
    virtual bool  SetFree(class CPile * a2, int a3);

    // address=[0x1562050]
    virtual void  NotifyChangeEcoSector(class CPile * a2, int a3, int a4);

    // address=[0x15620c0]
    virtual void  SubjectDie(class CPile * a2, int a3);

    // address=[0x15621c0]
    virtual void  SubjectStopped(class CPile * a2);

    // address=[0x1562230]
    virtual void  SubjectStarted(class CPile * a2);

    // address=[0x1562290]
    virtual bool  ChangeGoodTypeUnforseen(class CPile * a2, int a3);

    // address=[0x1562340]
    void  SetTradeRoleType(enum CTradePileRole::TRADEPILE_ROLE a2);

    // address=[0x1562440]
    int  GetTradeRoleType(void);

    // address=[0x1562460]
    void  SetExpectedAmount(int a2);

    // address=[0x1562480]
    int  GetExpectedAmount(void);

    // address=[0x15624a0]
    virtual void  IncAmoutLeaving(class CPile * a2);

    // address=[0x1562500]
    virtual void  DecAmountLeaving(class CPile * a2);

    // address=[0x1562560]
    virtual void  IncAmountComing(class CPile * a2);

    // address=[0x1562590]
    virtual void  DecAmountComing(class CPile * a2);

    // address=[0x15625e0]
    int  ReservesGood(int a2, enum PILE_TYPES a3, class CPile * a4);

    // address=[0x15626d0]
    int  GetReserveAmount(void);

    // address=[0x1562710]
     CTradePileRole(std::istream & a2);

    // address=[0x1562810]
    virtual void  Store(std::ostream & a2);

    // address=[0x1562d70]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d8bea0]
    static unsigned long m_iClassID;

private:
    // address=[0x1562890]
     CTradePileRole(void);

    // address=[0x1562920]
    virtual  ~CTradePileRole(void);

};


#endif // CTRADEPILEROLE_H
