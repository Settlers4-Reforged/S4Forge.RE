#ifndef IAIEVENTQUEUE_H
#define IAIEVENTQUEUE_H

#include <LoadSave/IS4ChunkObject.h>

#include "defines.h"

class IAIEventQueue : public IS4ChunkObject {
public:
    // address=[0x1310260]
    IAIEventQueue(void);

    virtual bool PeekAIEvent(class CAIEvent &a2, bool a3) = 0;
};


#endif // IAIEVENTQUEUE_H
