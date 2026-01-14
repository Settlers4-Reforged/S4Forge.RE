#ifndef CVOICECHAT_H
#define CVOICECHAT_H

class CVoiceChat {
public:
    // address=[0x2fd4650]
     CVoiceChat(int,int,class IEventEngine *);

    // address=[0x2fd47a0]
     ~CVoiceChat(void);

    // address=[0x2fd4920]
    bool  Init(int,unsigned int,char *);

    // address=[0x2fd4af0]
    void  Stop(void);

    // address=[0x2fd4bb0]
    bool  ReceivePacket(signed char *,int);

    // address=[0x2fd4c50]
    int  GetInputSamplingRate(void);

    // address=[0x2fd4c70]
    void  ToggleRecording(bool);

    // address=[0x2fd4cb0]
    bool  IsRecording(void);

    // address=[0x2fd4cd0]
    void  Run(void);

    // address=[0x2fd4d30]
    bool  UsesFullDuplex(void);

    // address=[0x2fd4d50]
    void  CalcBaseNoise(void);

    // address=[0x2fd4d70]
    void  SetOperationMode(bool);

    // address=[0x2fd4d90]
    void  SetTestMode(bool);

    // address=[0x2fd4db0]
    bool  OnEvent(class CEvn_Event &);

    // address=[0x2fd4e30]
    void  SetVolume(int);

    // address=[0x2fd4ec0]
    void  SetMicVolume(int);

    // address=[0x2fd4f60]
    int  GetMicVolume(void);

private:
    // address=[0x2fd3d50]
    void  SendPacket(void);

    // address=[0x2fd3ea0]
    bool  SetWindowsMicVolume(int);

    // address=[0x2fd4290]
    bool  GetWindowsMicVolume(int *);

};


#endif // CVOICECHAT_H
