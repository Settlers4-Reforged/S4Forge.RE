#ifndef IANIMATEDENTITY_H
#define IANIMATEDENTITY_H

#include "IEntity.h"
#include "defines.h"

class IAnimatedEntity : public IEntity {
  public:
    // address=[0x1307150]
    int Next(void) const;

    // address=[0x1351b10]
    int Frame(void) const;

    // address=[0x1351b30]
    int GetLastLogicUpdateTick(void) const;

    // address=[0x1439c70]
    int Previous(void) const;

    // address=[0x1439e10]
    void SetNext(int _id);

    // address=[0x1439eb0]
    void SetPrevious(int a2);

    // address=[0x14d87d0]
    void SetLastUpdateTick(unsigned int a2);

    // address=[0x14e31a0]
    int RegisterForLogicUpdate(int _iDeltaTicks);

    // address=[0x14e31d0]
    void UnRegisterFromLogicUpdate(void);

    // address=[0x14e3210]
    virtual void SetEvent(class CEntityEvent const &a1);

    // address=[0x14e3270]
    virtual void ClearAllQueuedEvents(void);

    // address=[0x14e3290]
    void BoxSelection(void);

    // address=[0x14e46c0]
    virtual ~IAnimatedEntity(void);

    // address=[0x14eb000]
    IAnimatedEntity(int id);

    // address=[0x14eb2a0]
    int AttackerPlayerId(void) const;

    // address=[0x1501170]
    unsigned int LastUpdateTick(void) const;

    // address=[0x1548370]
    int JobPart(void) const;

    // address=[0x15639c0]
    void SetFrame(int a2);

    // address=[0x15670a0]
    bool EventQueueEmpty(void) const;

    // address=[0x1567140]
    void SetJobPart(int a2);

  protected:
    // address=[0x14e3460]
    IAnimatedEntity(std::istream &_rStream);

    // address=[0x14e35f0]
    virtual void Store(std::ostream &_rStream);

    // address=[0x14e3780]
    bool ProcessAllEvents(void);

    // address=[0x14e4ae0]
    virtual void ConvertEventIntoGoal(class CEntityEvent *a1);

    // address=[0x14e4b90]
    int SetLastLogicUpdate(int a2);

    // Type information members
  public:
    BYTE m_cFrame;
    BYTE m_cAttackerPlayerId;
    WORD m_iJobPart;
    WORD m_wPrevEntity;
    WORD m_wNextEntity;
    DWORD m_uLastUpdateTick;
    int m_uLastLogicUpdate;
    std::vector<CEntityEvent> m_iEventQueue;
};

#endif // IANIMATEDENTITY_H
