#ifndef CSIMPLENET_H
#define CSIMPLENET_H

class CSimpleNet : public ISimpleNet {
public:
    // address=[0x15ccbf0]
     CSimpleNet(void);

    // address=[0x15ccd30]
     ~CSimpleNet(void);

    // address=[0x15cce40]
    virtual std::string  GetCurrentLocalIPString(void);

    // address=[0x15cce80]
    virtual bool  Run(void);

    // address=[0x15ccf90]
    virtual bool  IsMessage(int);

    // address=[0x15ccfd0]
    virtual bool  PopMessage(void * &,unsigned int &,unsigned int &);

    // address=[0x15cd190]
    virtual bool  PushMessage(unsigned int,unsigned int,unsigned short,void *,unsigned int,bool,bool);

    // address=[0x15cd490]
    virtual char *  GetIPString(unsigned int);

    // address=[0x15cd4d0]
    virtual void  RemoveMsgsForIP(unsigned int);

    // address=[0x15cd6a0]
    virtual bool  IsLocalIP(unsigned int);

    // address=[0x15d1290]
    virtual void  Delete(void);

    // address=[0x15d12e0]
    virtual unsigned int  GetBytesPerSecond(void);

    // address=[0x15d1300]
    virtual long  GetCurrentLocalIPLong(void);

    // address=[0x15d1320]
    virtual unsigned int  GetIPLong(std::string);

    // address=[0x15d13a0]
    virtual unsigned int  GetLastDataLength(void);

    // address=[0x15d13c0]
    virtual std::string  GetLastErrorString(void);

    // address=[0x15d1400]
    virtual long  GetLastSenderIP(void);

    // address=[0x15d1420]
    virtual unsigned int  GetLastSenderPeerId(void);

    // address=[0x15d1440]
    virtual void  RemoveAllResendMsgs(void);

    // address=[0x15d1490]
    virtual void  SetAdditionalLocalAddress(unsigned int);

    // address=[0x15d1520]
    virtual bool  WasError(void);

protected:
    // address=[0x15cd7d0]
    virtual bool  SendMessageA(unsigned int,struct SMessage &);

    // address=[0x15cdc40]
    virtual bool  RealSendMessage(unsigned int,struct SMessage &);

    // address=[0x15cdd50]
    virtual bool  RemoveMsgFromResendList(unsigned short);

    // address=[0x15cdea0]
    virtual bool  LaunchWinsock(void);

    // address=[0x15ce080]
    virtual bool  EnumerateLocalIP(void);

    // address=[0x15ce3c0]
    virtual bool  ConnectSocket(void);

    // address=[0x15d1220]
    virtual void  ClearErrorString(void);

    // address=[0x15d14b0]
    virtual void  SetErrorString(char const *,bool);

};


#endif // CSIMPLENET_H
