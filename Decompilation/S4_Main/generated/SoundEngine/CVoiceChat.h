#ifndef CVOICECHAT_H
#define CVOICECHAT_H

#include "defines.h"

class CVoiceChat {
public:
    // address=[0x2fd4650]
     CVoiceChat(int a2, int a3, class IEventEngine * a4);

    // address=[0x2fd47a0]
     ~CVoiceChat(void);

    // address=[0x2fd4920]
    bool  Init(int a2, unsigned int a3, char * Str);

    // address=[0x2fd4af0]
    void  Stop(void);

    // address=[0x2fd4bb0]
    bool  ReceivePacket(signed char * Src, int a3);

    // address=[0x2fd4c50]
    int  GetInputSamplingRate(void);

    // address=[0x2fd4c70]
    void  ToggleRecording(bool a2);

    // address=[0x2fd4cb0]
    bool  IsRecording(void);

    // address=[0x2fd4cd0]
    void  Run(void);

    // address=[0x2fd4d30]
    bool  UsesFullDuplex(void);

    // address=[0x2fd4d50]
    void  CalcBaseNoise(void);

    // address=[0x2fd4d70]
    void  SetOperationMode(bool a2);

    // address=[0x2fd4d90]
    void  SetTestMode(bool a2);

    // address=[0x2fd4db0]
    bool  OnEvent(class CEvn_Event & a2);

    // address=[0x2fd4e30]
    void  SetVolume(int a2);

    // address=[0x2fd4ec0]
    void  SetMicVolume(int a2);

    // address=[0x2fd4f60]
    int  GetMicVolume(void);

private:
    // address=[0x2fd3d50]
    void  SendPacket(void);

    // address=[0x2fd3ea0]
    bool  SetWindowsMicVolume(int a2);

    // address=[0x2fd4290]
    bool  GetWindowsMicVolume(int * a2);

};


#endif // CVOICECHAT_H
