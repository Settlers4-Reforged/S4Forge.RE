#ifndef IPILEROLE_H
#define IPILEROLE_H

#include "LoadSave/CPersistence.h"
#include "defines.h"

class IPileRole : public CPersistence {
  public:
    // address=[0x155b1e0]
    virtual ~IPileRole(void);

    // address=[0x155b280]
    virtual bool ChangeGoodTypeUnforseen(class CPile *a2, int a3);

    // address=[0x155b2c0]
    virtual void DecAmountComing(class CPile *a2);

    // address=[0x155b2d0]
    virtual void Empty(class CPile *a2);

    // address=[0x155b2e0]
    virtual void IncAmountComing(class CPile *a2);

    // address=[0x155b2f0]
    virtual void LogicUpdate(class CPile *a2);

    // address=[0x155b330]
    virtual void ReassessDistance(class CPile *a2, int &a3);

    // address=[0x1560f00]
    virtual void Increase(class CPile *_pPile, int _iAmount);

    // address=[0x1560fc0]
    virtual void Decrease(class CPile *_pPile, int _iAmount);

    // address=[0x1561050]
    virtual void IncAmoutLeaving(class CPile *_pPile);

    // address=[0x15610b0]
    virtual void DecAmountLeaving(class CPile *_pPile);

    // address=[0x1561140]
    virtual void Init(class CPile *_pPile);

    // address=[0x1561160]
    virtual void Occupied(class CPile *a2, int a3);

    // address=[0x1561190]
    virtual bool SetFree(class CPile *_pPile, int a3);

    // address=[0x1561210]
    virtual void NotifyChangeEcoSector(class CPile *_pPile, int a3, int a4);

    // address=[0x1561250]
    virtual void SubjectDie(class CPile *_pPile, int a3);

    // address=[0x1561350]
    virtual void SubjectStopped(class CPile *a2);

    // address=[0x1561360]
    virtual void SubjectStarted(class CPile *a2);

    // address=[0x1561370]
    IPileRole(std::istream &_rStream);

    // address=[0x15613f0]
    virtual void Store(std::ostream &_rStream);

    // address=[0x1561440]
    bool ExecuteChangeGoodTypeUnforseen(class CPile *_pPile, int a3);

    enum T_S4_PILE_ROLE_TYPE {
        PILE_PRODUCTION = 0,
        PILE_DELIVER = 1,
        PILE_STORAGE = 2,
        PILE_ANYWHERE = 3,
        PILE_TRADE = 4,
        PILE_BUILDINGSITE = 5
    };

  protected:
    // address=[0x1560200]
    IPileRole(void);

  protected:
    unsigned __int16 m_uPileId;
};

#endif // IPILEROLE_H
