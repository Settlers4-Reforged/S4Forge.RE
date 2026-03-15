#ifndef CAIEVENTQUEUE_H
#define CAIEVENTQUEUE_H

#include "CAIEvent.h"
#include "defines.h"
#include "IAIEventQueue.h"


class CAIEventQueue : public IAIEventQueue {
public:
    // address=[0x130a0d0]
    ~CAIEventQueue(void);

    // address=[0x130a240]
    void Clear(void);

    // address=[0x130f720]
    CAIEventQueue(void);

    // address=[0x130f7a0]
    virtual bool PeekAIEvent(class CAIEvent &a2, bool _bClearOnEnd);

    // address=[0x130f830]
    class CAIEvent const *PeekAIEvent(bool _bIncrementReadCounter);

    // address=[0x130f8a0]
    virtual void Load(class IS4Chunk &a2);

    // address=[0x130f9a0]
    virtual void Save(class IS4Chunk &a2);

    // address=[0x1319880]
    void PostAIEvent(int _iType, int _iX, int _iY, int _iDark);

    // Type information members
public:
    DWORD                 m_uReadCounter;
    std::vector<CAIEvent> m_vEvents;
};


#endif // CAIEVENTQUEUE_H
