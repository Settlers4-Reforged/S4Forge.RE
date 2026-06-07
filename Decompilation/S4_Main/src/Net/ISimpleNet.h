#ifndef ISIMPLENET_H
#define ISIMPLENET_H

#include "defines.h"

class ISimpleNet {
  public:
    // address=[0x15d0400]
    ISimpleNet(void);

    virtual void Delete(void) = 0;
    virtual bool WasError(void) = 0;
    virtual std::string GetLastErrorString(void) = 0;
    virtual std::string GetCurrentLocalIPString(void) = 0;
    virtual long GetCurrentLocalIPLong(void) = 0;
    virtual bool Run(void) = 0;
    virtual bool IsMessage(int a2) = 0;
    virtual bool PopMessage(void *&a2, unsigned int &a3, unsigned int &a4) = 0;
    virtual bool PushMessage(unsigned int a2, unsigned int a3, unsigned short a4, void *Src, unsigned int Size, bool a7, bool a8) = 0;
    virtual long GetLastSenderIP(void) = 0;
    virtual unsigned int GetLastSenderPeerId(void) = 0;
    virtual unsigned int GetLastDataLength(void) = 0;
    virtual char *GetIPString(unsigned int a2) = 0;
    virtual unsigned int GetBytesPerSecond(void) = 0;
    virtual void RemoveMsgsForIP(unsigned int a2) = 0;
    virtual void RemoveAllResendMsgs(void) = 0;
    virtual bool IsLocalIP(unsigned int a2) = 0;
    virtual unsigned int GetIPLong(std::string a1) = 0;
    virtual void SetAdditionalLocalAddress(unsigned int a2) = 0;
};

#endif // ISIMPLENET_H
