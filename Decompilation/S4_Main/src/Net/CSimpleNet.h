#ifndef CSIMPLENET_H
#define CSIMPLENET_H

#include "defines.h"

#include "ISimpleNet.h"

class LZHLDecompressor;
class LZHLCompressor;

struct SLocalAddress {
    IN_ADDR m_iAddress;
    char m_sIp[154];
    _BYTE gap9E[2];
    bool m_bU;
};

struct SMessageBuffer {
    unsigned int m_iHeader;
    uint8_t m_cDataBuffer[2048];
};

struct [[gnu::packed]] SMessage {
    int m_iTime;
    int m_iU;
    int m_iId;
    __int16 m_iReceiverId;
    SMessageBuffer m_sMessage;
};

static_assert(sizeof(SMessage) == 0x812, "Size of SMessage is not correct");

class CSimpleNet : public ISimpleNet {
  public:
    // address=[0x15ccbf0]
    CSimpleNet(void);

    // address=[0x15ccd30]
    ~CSimpleNet(void);

    // address=[0x15cce40]
    virtual std::string GetCurrentLocalIPString(void);

    // address=[0x15cce80]
    virtual bool Run(void);

    // address=[0x15ccf90]
    virtual bool IsMessage(int a2);

    // address=[0x15ccfd0]
    virtual bool PopMessage(void *&_rMessage, unsigned int &_riLength, unsigned int &_riPeerId);

    // address=[0x15cd190]
    virtual bool PushMessage(unsigned int _iPeerId, unsigned int _iId, unsigned short _iReceiver, void *_pData, unsigned int _iDataLength, bool _bTryResend, bool a8);

    // address=[0x15cd490]
    virtual char *GetIPString(unsigned int a2);

    // address=[0x15cd4d0]
    virtual void RemoveMsgsForIP(unsigned int _iAddress);

    // address=[0x15cd6a0]
    virtual bool IsLocalIP(unsigned int _iAddress);

    // address=[0x15d1290]
    virtual void Delete(void);

    // address=[0x15d12e0]
    virtual unsigned int GetBytesPerSecond(void);

    // address=[0x15d1300]
    virtual long GetCurrentLocalIPLong(void);

    // address=[0x15d1320]
    virtual unsigned int GetIPLong(std::string a1);

    // address=[0x15d13a0]
    virtual unsigned int GetLastDataLength(void);

    // address=[0x15d13c0]
    virtual std::string GetLastErrorString(void);

    // address=[0x15d1400]
    virtual long GetLastSenderIP(void);

    // address=[0x15d1420]
    virtual unsigned int GetLastSenderPeerId(void);

    // address=[0x15d1440]
    virtual void RemoveAllResendMsgs(void);

    // address=[0x15d1490]
    virtual void SetAdditionalLocalAddress(unsigned int a2);

    // address=[0x15d1520]
    virtual bool WasError(void);

  protected:
    // address=[0x15cd7d0]
    virtual bool SendMessageA(unsigned int _iPeerId, struct SMessage &_rMessage);

    // address=[0x15cdc40]
    virtual bool RealSendMessage(unsigned int a2, struct SMessage &a3);

    // address=[0x15cdd50]
    virtual bool RemoveMsgFromResendList(unsigned short a2);

    // address=[0x15cdea0]
    virtual bool LaunchWinsock(void);

    // address=[0x15ce080]
    virtual bool EnumerateLocalIP(void);

    // address=[0x15ce3c0]
    virtual bool ConnectSocket(void);

    // address=[0x15d1220]
    virtual void ClearErrorString(void);

    // address=[0x15d14b0]
    virtual void SetErrorString(char const *Str, bool a3);

    // Type information members
  public:
    std::list<SLocalAddress> m_vLocalAddresses;
    long m_iReceiverSocketAddress;
    char m_sCurrentLocalIPString[160];
    _DWORD m_iAdditionalLocalAddress;
    std::list<SMessage> m_vResendMessages;
    WORD m_iMessageCounter;
    _BYTE gap_C6[6];
    bool m_bHasError;
    _BYTE gap_CD[3];
    std::string m_sError;
    int m_iNumberReceiverSockets;
    DWORD m_pReceiverSockets[32];
    _DWORD m_pSenderSocket;
    sockaddr_in m_sReceiverSocketConfig;
    BYTE field_184[16];
    int m_iLastSenderPeerId;
    _BYTE gap_198[4];
    _DWORD m_iSentBytes;
    _DWORD m_iSentCompressedBytes;
    _DWORD m_iLastTraceRun;
    _DWORD m_iCompressedBytesPerSecond;
    _DWORD m_iLastDataLength;
    char m_sErrorFormatBuffer[128];
    _BYTE gap_230[896];
    BYTE m_vCompressedMessageBuffer[1024];
    SMessageBuffer m_vRawMessageBuffer;
    LZHLCompressor *m_pCompressor;
    LZHLDecompressor *m_pDecompressor;
};

#endif // CSIMPLENET_H
