#ifndef CVC_EVENTHANDLE_H
#define CVC_EVENTHANDLE_H

#include "defines.h"

class CVC_EventHandle : public IEvn_Handle {
public:
    // address=[0x2fd4fb0]
    void  RegisterVC(class CVoiceChat * a2);

    // address=[0x2fd4fe0]
    void  UnregisterVC(void);

    // address=[0x2fd5000]
    virtual bool  OnEvent(class CEvn_Event & a2);

    // address=[0x2fd54d0]
     CVC_EventHandle(void);

};


#endif // CVC_EVENTHANDLE_H
