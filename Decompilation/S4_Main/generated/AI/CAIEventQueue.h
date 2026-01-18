#ifndef CAIEVENTQUEUE_H
#define CAIEVENTQUEUE_H

#include "defines.h"

class CAIEventQueue : public IAIEventQueue {
public:
    // address=[0x130a0d0]
     ~CAIEventQueue(void);

    // address=[0x130a240]
    void  Clear(void);

    // address=[0x130f720]
     CAIEventQueue(void);

    // address=[0x130f7a0]
    virtual bool  PeekAIEvent(class CAIEvent & a2, bool a3);

    // address=[0x130f830]
    class CAIEvent const *  PeekAIEvent(bool a2);

    // address=[0x130f8a0]
    virtual void  Load(class IS4Chunk & a2);

    // address=[0x130f9a0]
    virtual void  Save(class IS4Chunk & a2);

    // address=[0x1319880]
    void  PostAIEvent(int a2, int a3, int a4, int a5);

};


#endif // CAIEVENTQUEUE_H
