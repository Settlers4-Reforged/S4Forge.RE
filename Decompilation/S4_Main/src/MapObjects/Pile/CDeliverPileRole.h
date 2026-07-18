#ifndef CDELIVERPILEROLE_H
#define CDELIVERPILEROLE_H

#include "IPileRole.h"
#include "defines.h"

class CDeliverPileRole : public IPileRole {
  public:
    // address=[0x1400400]
    static class CPersistence *__cdecl New(std::istream &a1);

    // address=[0x155b880]
    virtual void Init(class CPile *_pPile);

    // address=[0x155b920]
    virtual void LogicUpdate(class CPile *_pPile);

    // address=[0x155ba20]
    virtual void Increase(class CPile *_pPile, int _iAmount);

    // address=[0x155bae0]
    virtual void SubjectStopped(class CPile *_pPile);

    // address=[0x155bb10]
    virtual void SubjectStarted(class CPile *_pPile);

    // address=[0x155bb50]
    CDeliverPileRole(std::istream &_rStream);

    // address=[0x155bc00]
    virtual void Store(std::ostream &_rStream);

    // address=[0x155bd20]
    virtual ~CDeliverPileRole(void);

    // address=[0x155bd80]
    virtual unsigned long ClassID(void) const;

    // address=[0x15603c0]
    static class CDeliverPileRole *__cdecl Load(std::istream &a1);

    // address=[0x3d8bbbc]
    static unsigned long m_iClassID;

  private:
    friend class CPileMgr;

    // address=[0x1560170]
    CDeliverPileRole(void);
};

#endif // CDELIVERPILEROLE_H
