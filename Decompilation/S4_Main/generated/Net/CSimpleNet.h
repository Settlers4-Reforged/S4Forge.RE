#ifndef CSIMPLENET_H
#define CSIMPLENET_H

#include "defines.h"

class CSimpleNet : public ISimpleNet {
public:
    // address=[0x15ccbf0]
     CSimpleNet(void);

    // address=[0x15ccd30]
     ~CSimpleNet(void);

    // address=[0x15cce40]
    virtual std::string  GetCurrentLocalIPString(void a2);

    // address=[0x15cce80]
    virtual bool  Run(void);

    // address=[0x15ccf90]
    virtual bool  IsMessage(int a2);

    // address=[0x15ccfd0]
    virtual bool  PopMessage(void * & _rMessage, unsigned int & a3, unsigned int & _iPeerId);

    // address=[0x15cd190]
    virtual bool  PushMessage(unsigned int _iPeerId, unsigned int _iIp, unsigned short _iMessageId, void * _pData, unsigned int _iDataLength, bool _bTryResend, bool _bCompress);

    // address=[0x15cd490]
    virtual char *  GetIPString(unsigned int a2);

    // address=[0x15cd4d0]
    virtual void  RemoveMsgsForIP(unsigned int _iAddress);

    // address=[0x15cd6a0]
    virtual bool  IsLocalIP(unsigned int _iAddress);

    // address=[0x15d1290]
    virtual void  Delete(void);

    // address=[0x15d12e0]
    virtual unsigned int  GetBytesPerSecond(void);

    // address=[0x15d1300]
    virtual long  GetCurrentLocalIPLong(void);

    // address=[0x15d1320]
    virtual unsigned int  GetIPLong(std::string a1);

    // address=[0x15d13a0]
    virtual unsigned int  GetLastDataLength(void);

    // address=[0x15d13c0]
    virtual std::string  GetLastErrorString(void a2);

    // address=[0x15d1400]
    virtual long  GetLastSenderIP(void);

    // address=[0x15d1420]
    virtual unsigned int  GetLastSenderPeerId(void);

    // address=[0x15d1440]
    virtual void  RemoveAllResendMsgs(void);

    // address=[0x15d1490]
    virtual void  SetAdditionalLocalAddress(unsigned int a2);

    // address=[0x15d1520]
    virtual bool  WasError(void);

protected:
    // address=[0x15cd7d0]
    virtual bool  SendMessageA(unsigned int _iPeerId, struct SMessage & _rMessage);

    // address=[0x15cdc40]
    virtual bool  RealSendMessage(unsigned int a2, struct SMessage & a3);

    // address=[0x15cdd50]
    virtual bool  RemoveMsgFromResendList(unsigned short a2);

    // address=[0x15cdea0]
    virtual bool  LaunchWinsock(void);

    // address=[0x15ce080]
    virtual bool  EnumerateLocalIP(void);

    // address=[0x15ce3c0]
    virtual bool  ConnectSocket(void);

    // address=[0x15d1220]
    virtual void  ClearErrorString(void);

    // address=[0x15d14b0]
    virtual void  SetErrorString(char const * Str, bool a3);

    // Type information members
public:
    std::list m_vLocalAddresses;
    _DWORD m_iReceiverSocketAddress;
    char[160] m_sCurrentLocalIPString;
    _DWORD m_iAdditionalLocalAddress;
    std::list m_vResendMessages;
    WORD m_iMessageCounter;
    _BYTE[6] gap_C6;
    bool m_bHasError;
    _BYTE[3] gap_CD;
    std::string m_sError;
    int m_iNumberReceiverSockets;
    DWORD[32] m_pReceiverSockets;
    _DWORD m_pSenderSocket;
    sockaddr_in m_sReceiverSocketConfig;
    sockaddr_in m_sSenderSocketConfig;
    int m_iLastSenderPeerId;
    _BYTE[4] gap_198;
    _DWORD m_iSentBytes;
    _DWORD m_iSentCompressedBytes;
    _DWORD m_iLastTraceRun;
    _DWORD m_iCompressedBytesPerSecond;
    _DWORD m_iLastDataLength;
    _BYTE[1024] m_sErrorFormatBuffer;
    BYTE[1024] m_vCompressedMessageBuffer;
    SMessageBuffer m_vRawMessageBuffer;
    LZHLCompressor * m_pCompressor;
    LZHLDecompressor * m_pDecompressor;

};


#endif // CSIMPLENET_H
