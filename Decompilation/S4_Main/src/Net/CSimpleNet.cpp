#include "CSimpleNet.h"

#include "CBB/CBBSupport.h"
#include "Compression/LZHL.h"
#include "Debug/CTrace.h"

// Definitions for class CSimpleNet

// address=[0x15ccbf0]
// Decompiled from CSimpleNet *__thiscall CSimpleNet::CSimpleNet(CSimpleNet *this)
CSimpleNet::CSimpleNet(void) : ISimpleNet(), m_vLocalAddresses(), m_vResendMessages(), m_sError() {
    this->m_iMessageCounter = 0;
    this->m_iLastTraceRun = 0;
    this->m_iSentBytes = 0;
    this->m_iSentCompressedBytes = 0;
    this->m_iLastDataLength = 0;
    this->m_iCompressedBytesPerSecond = 0;
    memset(&this->m_sSenderSocketConfig, 0, sizeof(this->m_sSenderSocketConfig));
    this->m_iAdditionalLocalAddress = 0;
    this->m_iLastSenderPeerId = -1;
    CSimpleNet::ClearErrorString();
    if(CSimpleNet::LaunchWinsock() && CSimpleNet::EnumerateLocalIP())
        CSimpleNet::ConnectSocket();
}

// address=[0x15ccd30]
// Decompiled from int __thiscall CSimpleNet::~CSimpleNet(CSimpleNet *this)
CSimpleNet::~CSimpleNet(void) {
    // [esp+4h] [ebp-14h]

    for(int i = 0; i < this->m_iNumberReceiverSockets; ++i) {
        BBSupportTracePrintF(1, "Simplenet: Shutting down receiver socket %u", i);
        shutdown(this->m_pReceiverSockets[i], 2);
        closesocket(this->m_pReceiverSockets[i]);
    }
    shutdown(this->m_pSenderSocket, 2);
    closesocket(this->m_pSenderSocket);
    this->m_vResendMessages.clear();
    this->m_vLocalAddresses.clear();
    WSACleanup();
}

// address=[0x15cce40]
// Decompiled from std::string *__thiscall CSimpleNet::GetCurrentLocalIPString(CSimpleNet *this, std::string *a2)
std::string CSimpleNet::GetCurrentLocalIPString(void) { // TODO: probably best as a reference
    return m_sCurrentLocalIPString;
}

// address=[0x15cce80]
// Decompiled from char __thiscall CSimpleNet::Run(CSimpleNet *this)
bool CSimpleNet::Run(void) {
    DWORD Time = timeGetTime();
    if(this->m_iLastTraceRun + 20000 >= Time)
        return 1;
    int iElapsedTimeMS = Time - this->m_iLastTraceRun;
    int iBytesPerSecond = static_cast<int>(this->m_iSentBytes / (iElapsedTimeMS / 1000.0));
    this->m_iCompressedBytesPerSecond = static_cast<unsigned int>(this->m_iSentCompressedBytes / (iElapsedTimeMS / 1000.0));
    this->m_iSentBytes = 0;
    this->m_iSentCompressedBytes = 0;
    this->m_iLastTraceRun = Time;
    BBSupportTracePrintF(
        1,
        "SimpleNet: Bytes/sec: Uncompressed %u, Compressed %u",
        iBytesPerSecond,
        this->m_iCompressedBytesPerSecond);
    return 1;
}

// address=[0x15ccf90]
// Decompiled from bool __thiscall CSimpleNet::IsMessage(CSimpleNet *this, int a2)
bool CSimpleNet::IsMessage(int a2) {
    unsigned int v4; // [esp+4h] [ebp-8h] BYREF
    OnlineManager::GetInstance()->GetMessageCount(Instance, &v4);
    return v4 != 0;
}

// address=[0x15ccfd0]
// Decompiled from char __thiscall CSimpleNet::PopMessage(CSimpleNet *this, void **_rMessage, unsigned int *a3, unsigned int *_iPeerId)
bool CSimpleNet::PopMessage(void *&_rMessage, unsigned int &_riLength, unsigned int &_riPeerId) {
    size_t v8;                    // [esp+0h] [ebp-10h] BYREF
    unsigned int iCompressedSize; // [esp+4h] [ebp-Ch] BYREF
    int v10;                      // [esp+8h] [ebp-8h] BYREF

    _rMessage = 0;
    _riLength = 0;
    v10 = 0;
    char *iReceivedData = (char *)&this->m_vRawMessageBuffer;

    OnlineManager::GetInstance()->Receive(Instance, iReceivedData, &v10, _riPeerId, v8);
    this->m_iLastSenderPeerId = _riPeerId;
    if(v10 && v10 != -1) {
        if(((this->m_vRawMessageBuffer.m_iHeader >> 12) & 0x3FF) != 0) // (m_iSize / 4096) % 1024
        {
            iCompressedSize = (this->m_vRawMessageBuffer.m_iHeader >> 12) & 0x3FF;
            v8 = v10 - 4;
            this->m_iLastDataLength = iCompressedSize;
            this->m_pDecompressor = LZHLCreateDecompressor();
            memset(this->m_vCompressedMessageBuffer, 0, sizeof(this->m_vCompressedMessageBuffer));
            LZHLDecompress(
                this->m_pDecompressor,
                this->m_vCompressedMessageBuffer,
                &iCompressedSize,
                this->m_vRawMessageBuffer.m_cDataBuffer,
                &v8);
            LZHLDestroyDecompressor(this->m_pDecompressor);
            _rMessage = this->m_vCompressedMessageBuffer;
            _riLength = (this->m_vRawMessageBuffer.m_iHeader >> 12) & 0x3FF;
        } else {
            _rMessage = this->m_vRawMessageBuffer.m_cDataBuffer;
            _riLength = v10 - 4;
            this->m_iLastDataLength = _riLength;
        }
        return 1;
    } else {
        int Error = WSAGetLastError();
        sprintf(this->m_sErrorFormatBuffer, "::recvfrom() failed: LastWSAError: %d!", Error);
        this->SetErrorString(this->m_sErrorFormatBuffer, 1);
        return 0;
    }
}

SMessage sMessage;

// address=[0x15cd190]
// Decompiled from int __thiscall CSimpleNet::PushMessage(  CSimpleNet *this,  uint _iPeerId,  uint _iId,  u_short _iReceiver,  void *_pData,  size_t _iDataLength,  char _bTryResend,  char a8)
bool CSimpleNet::PushMessage(unsigned int _iPeerId, unsigned int _iId, unsigned short _iReceiver, void *_pData, unsigned int _iDataLength, bool _bTryResend, bool a8) {
    uint8_t sz[1056]; // [esp+14h] [ebp-424h] BYREF

    sMessage.m_iTime = timeGetTime();
    sMessage.m_iReceiverId = htons(_iReceiver);
    sMessage.m_iId = _iId;
    sMessage.m_iU = 0;
    if(_iDataLength > 0x400 && BBSupportDbgReport(2, "net\\SimpleNet.cpp", 978, "_iDataLength <= MESSAGE_LENGTH") == 1)
        __debugbreak();
    if(a8) {
        if(_iDataLength > 1024)
            _iDataLength = 1024;
        memcpy(sz, _pData, _iDataLength);
        memset(&sz[_iDataLength], 0, 32u);
        int iBufferLen = LZHLCompressorCalcMaxBuf(_iDataLength);
        BB_ASSERT(iBufferLen < sizeof(sMessage.m_sMessage.m_cDataBuffer))
        static_assert(sizeof(sMessage.m_sMessage.m_cDataBuffer) == 0x800, "Size of m_cDataBuffer is not correct");

        this->m_pCompressor = LZHLCreateCompressor();
        memset(sMessage.m_sMessage.m_cDataBuffer, 0, sizeof(sMessage.m_sMessage.m_cDataBuffer));
        int iCompressedSize = LZHLCompress(this->m_pCompressor, sMessage.m_sMessage.m_cDataBuffer, sz, _iDataLength);
        LZHLDestroyCompressor(this->m_pCompressor);
        sMessage.m_sMessage.m_iHeader = ((_iDataLength & 0x3FF) << 12) | sMessage.m_sMessage.m_iHeader & 0xFFC00FFF;
        sMessage.m_sMessage.m_iHeader = ((iCompressedSize & 0x3FF) << 22) | sMessage.m_sMessage.m_iHeader & 0x3FFFFF;
    } else {
        memcpy(sMessage.m_sMessage.m_cDataBuffer, _pData, _iDataLength);
        sMessage.m_sMessage.m_iHeader = ((_iDataLength & 0x3FF) << 22) | sMessage.m_sMessage.m_iHeader & 0x3FFFFF;
        sMessage.m_sMessage.m_iHeader &= 0xFFC00FFF;
    }
    sMessage.m_sMessage.m_iHeader = (4 * (this->m_iMessageCounter++ & 0x3FF)) | sMessage.m_sMessage.m_iHeader & 0xFFFFF003;
    if(this->m_iMessageCounter == 1024)
        this->m_iMessageCounter = 0;
    sMessage.m_sMessage.m_iHeader &= 0xFFFFFFFC;
    sMessage.m_sMessage.m_iHeader = (_bTryResend != 0) | sMessage.m_sMessage.m_iHeader & 3 | sMessage.m_sMessage.m_iHeader & 0xFFFFFFFC;
    if((sMessage.m_sMessage.m_iHeader & 1) != 0)
        this->m_vResendMessages.push_back(sMessage);
    return this->SendMessageA(_iPeerId, sMessage);
}

// address=[0x15cd490]
// Decompiled from char *__thiscall CSimpleNet::GetIPString(CSimpleNet *this, struct in_addr a2)
char *CSimpleNet::GetIPString(unsigned int a2) {
    in_addr addr{};
    addr.S_un.S_addr = a2;
    return inet_ntoa(addr);
}

// address=[0x15cd4d0]
// Decompiled from int __thiscall CSimpleNet::RemoveMsgsForIP(CSimpleNet *this, ULONG _iAddress)
void CSimpleNet::RemoveMsgsForIP(unsigned int _iAddress) {
    int iCount = 0;
    if(!this->m_vResendMessages.empty()) {
        auto pIt = this->m_vResendMessages.begin();

        while(pIt != this->m_vResendMessages.end()) {
            if(pIt->m_iId == _iAddress) {
                pIt = this->m_vResendMessages.erase(pIt);
                ++iCount;
            } else {
                ++pIt;
            }
        }
    }
    if(iCount) {
        CTrace::Print("SimpleNet.cpp: Removed %d msgs for IP %s!", iCount, this->GetIPString(_iAddress));
    } else {
        CTrace::Print("SimpleNet.cpp: No msgs could be removed for IP %s!", this->GetIPString(_iAddress));
    }
}

// address=[0x15cd6a0]
// Decompiled from char __thiscall CSimpleNet::IsLocalIP(CSimpleNet *this, unsigned int _iAddress)
bool CSimpleNet::IsLocalIP(unsigned int _iAddress) {
    if(this->m_vLocalAddresses.empty())
        return this->m_iAdditionalLocalAddress && _iAddress == this->m_iAdditionalLocalAddress;

    for(const auto &rIt : this->m_vLocalAddresses) {
        if(rIt.m_iAddress.S_un.S_addr == _iAddress)
            return true;
    }

    return this->m_iAdditionalLocalAddress && _iAddress == this->m_iAdditionalLocalAddress;
}

// address=[0x15d1290]
// Decompiled from void __thiscall CSimpleNet::Delete(CSimpleNet *this)
void CSimpleNet::Delete(void) {
    delete this;
}

// address=[0x15d12e0]
// Decompiled from int __thiscall CSimpleNet::GetBytesPerSecond(CSimpleNet *this)
unsigned int CSimpleNet::GetBytesPerSecond(void) {
    return this->m_iCompressedBytesPerSecond;
}

// address=[0x15d1300]
// Decompiled from int __thiscall CSimpleNet::GetCurrentLocalIPLong(CSimpleNet *this)
long CSimpleNet::GetCurrentLocalIPLong(void) {
    return this->m_iReceiverSocketAddress;
}

// address=[0x15d1320]
// Decompiled from unsigned int __stdcall CSimpleNet::GetIPLong(std::string a1)
unsigned int CSimpleNet::GetIPLong(std::string a1) {
    return inet_addr(a1.c_str());
}

// address=[0x15d13a0]
// Decompiled from int __thiscall CSimpleNet::GetLastDataLength(CSimpleNet *this)
unsigned int CSimpleNet::GetLastDataLength(void) {
    return this->m_iLastDataLength;
}

// address=[0x15d13c0]
// Decompiled from std::string *__thiscall CSimpleNet::GetLastErrorString(CSimpleNet *this, std::string *a2)
std::string CSimpleNet::GetLastErrorString(void) {
    return this->m_sError; // TODO: reference?
}

// address=[0x15d1400]
// Decompiled from int __thiscall CSimpleNet::GetLastSenderIP(CSimpleNet *this)
long CSimpleNet::GetLastSenderIP(void) {
    return this->m_sSenderSocketConfig.sin_addr.S_un.S_addr;
}

// address=[0x15d1420]
// Decompiled from int __thiscall CSimpleNet::GetLastSenderPeerId(CSimpleNet *this)
unsigned int CSimpleNet::GetLastSenderPeerId(void) {
    return this->m_iLastSenderPeerId;
}

// address=[0x15d1440]
// Decompiled from void __thiscall CSimpleNet::RemoveAllResendMsgs(CSimpleNet *this)
void CSimpleNet::RemoveAllResendMsgs(void) {
    CTrace::Print("SimpleNet: Clearing resend list!");
    this->m_vResendMessages.clear();
}

// address=[0x15d1490]
// Decompiled from void __thiscall CSimpleNet::SetAdditionalLocalAddress(CSimpleNet *this, unsigned int a2)
void CSimpleNet::SetAdditionalLocalAddress(unsigned int a2) {
    this->m_iAdditionalLocalAddress = a2;
}

// address=[0x15d1520]
// Decompiled from bool __thiscall CSimpleNet::WasError(CSimpleNet *this)
bool CSimpleNet::WasError(void) {
    return this->m_bHasError;
}

// address=[0x15cd7d0]
// Decompiled from bool __thiscall CSimpleNet::SendMessageA(CSimpleNet *this, unsigned int _iPeerId, struct SMessage *_rMessage)
bool CSimpleNet::SendMessageA(unsigned int _iPeerId, SMessage &_rMessage) {
    return this->RealSendMessage(_iPeerId, _rMessage) != 0;
}

// address=[0415C398]
int s_Unknown2;

// address=[0415C39A]
int s_iLastReceiverId;
// address=[0415C39C]
int s_iLastReceiverIp;

// address=[0x15cdc40]
// Decompiled from char __thiscall CSimpleNet::RealSendMessage(CSimpleNet *this, unsigned int a2, struct SMessage *a3)
bool CSimpleNet::RealSendMessage(unsigned int a2, SMessage &a3) {
    s_Unknown2 = 2;
    s_iLastReceiverId = a3.m_iReceiverId;
    s_iLastReceiverIp = a3.m_iId;
    size_t v6 = ((a3.m_sMessage.m_iHeader >> 22) & 0x3FF) + 4;
    if(a3.m_iId == -1) {
        OnlineManager::GetInstance()->Send(&a3.m_sMessage, v6);
    } else {
        OnlineManager::GetInstance()->Send(a2, &a3.m_sMessage, v6);
    }
    this->m_iSentBytes += v6;
    this->m_iSentCompressedBytes += v6;
    if(((a3.m_sMessage.m_iHeader >> 12) & 0x3FF) != 0)
        this->m_iSentBytes += ((a3.m_sMessage.m_iHeader >> 12) & 0x3FF) - (HIWORD(a3.m_sMessage.m_iHeader) >> 6);
    return 1;
}

// address=[0x15cdd50]
// Decompiled from char __thiscall CSimpleNet::RemoveMsgFromResendList(CSimpleNet *this, unsigned __int16 a2)
bool CSimpleNet::RemoveMsgFromResendList(unsigned short a2) {

    char v3;      // [esp-Ch] [ebp-68h] BYREF
    int v4;       // [esp-8h] [ebp-64h]
    int v5;       // [esp-4h] [ebp-60h]
    _BYTE v6[12]; // [esp+4h] [ebp-58h] BYREF
    _BYTE v7[12]; // [esp+10h] [ebp-4Ch] BYREF
    _BYTE v8[12]; // [esp+1Ch] [ebp-40h] BYREF
    _BYTE v9[12]; // [esp+28h] [ebp-34h] BYREF

    if(!this->m_vResendMessages.size())
        return 1;

    auto pIt = this->m_vResendMessages.begin();
    while(pIt != this->m_vResendMessages.end()) {
        if((pIt->m_sMessage.m_iHeader >> 2 & 0x3FF) == a2) {
            this->m_vResendMessages.erase(pIt);
            return true;
        }

        ++pIt;
    }

    return false;
}

// address=[0x15cdea0]
// Decompiled from bool __thiscall CSimpleNet::LaunchWinsock(CSimpleNet *this)
bool CSimpleNet::LaunchWinsock(void) {

    WSAData WSAData{}; // [esp+10h] [ebp-194h] BYREF

    BBSupportTracePrintF(1, "SimpleNet: Requesting Winsock Version %d.%d!", 1, 1);
    switch(WSAStartup(0x101u, &WSAData)) {
    case 10036:
        this->SetErrorString("Winsock general failure!", 1);
        break;
    case 10067:
        this->SetErrorString("Winsock task limit reached. Please close other Applications and try again!", 1);
        break;
    case 10091:
        this->SetErrorString("Winsock not ready!", 1);
        break;
    case 10092:
        this->SetErrorString("Requested Winsock Version not available!", 1);
        break;
    default:
        break;
    }
    BBSupportTracePrintF(1, "SimpleNet: Got Winsock Version %d.%d", HIBYTE(WSAData.wVersion), LOBYTE(WSAData.wVersion));
    BBSupportTracePrintF(1, "SimpleNet: Info: %s", WSAData.szDescription);
    BBSupportTracePrintF(1, "SimpleNet: Info: %s", WSAData.szSystemStatus);
    return !this->m_bHasError;
}

// address=[0x15ce080]
// Decompiled from char __thiscall CSimpleNet::EnumerateLocalIP(CSimpleNet *this)
bool CSimpleNet::EnumerateLocalIP(void) {
    return 1; // TODO: removed in HE, needs to be readded for real local p2p multiplayer
}

// address=[0x15ce3c0]
// Decompiled from bool __thiscall CSimpleNet::ConnectSocket(CSimpleNet *this)
bool CSimpleNet::ConnectSocket(void) {
    const char *sIp;    // eax MAPDST
    int iPort;          // [esp-4h] [ebp-80h] MAPDST
    int namelen;        // [esp+28h] [ebp-54h] BYREF
    sockaddr_in name{}; // [esp+5Ch] [ebp-20h] BYREF

    this->m_iNumberReceiverSockets = 0;
    for(auto &rAddr : this->m_vLocalAddresses) {
        BB_ASSERT(m_iNumberReceiverSockets < MAX_RECEIVER_SOCKETS)

        if(this->m_iNumberReceiverSockets == MAX_RECEIVER_SOCKETS) {
            break;
        }

        if(!rAddr.m_bU)
            continue;

        this->m_pReceiverSockets[this->m_iNumberReceiverSockets] = socket(2, 2, 0);
        if(this->m_pReceiverSockets[this->m_iNumberReceiverSockets] == -1) {
            this->SetErrorString("Unable to create socket!", 1);
            BBSupportTracePrintF(3, "Unable to create socket!");
        } else {
            this->m_sReceiverSocketConfig.sin_family = 2;
            this->m_sReceiverSocketConfig.sin_port = htons(3105u);
            this->m_sReceiverSocketConfig.sin_addr.S_un.S_addr = rAddr.m_iAddress.S_un.S_addr;
            if(bind(this->m_pReceiverSockets[this->m_iNumberReceiverSockets],
                    reinterpret_cast<const sockaddr *>(&this->m_sReceiverSocketConfig),
                    16) == -1) {
                int Error = WSAGetLastError();
                sprintf(this->m_sErrorFormatBuffer, "SimpleNet: ::bind() to %s failed: LastWSAError: %d!", rAddr.m_sIp, Error);
                this->SetErrorString(this->m_sErrorFormatBuffer, 1);
                BBSupportTracePrintF(3, this->m_sErrorFormatBuffer);
            } else {
                iPort = htons(this->m_sReceiverSocketConfig.sin_port);
                sIp = this->GetIPString(this->m_sReceiverSocketConfig.sin_addr.S_un.S_addr);
                BBSupportTracePrintF(
                    1,
                    "Simplenet.cpp: Receiver socket %d named %s:%d",
                    this->m_iNumberReceiverSockets,
                    sIp,
                    iPort);
                ++this->m_iNumberReceiverSockets;
            }
        }
    }

    if(!this->m_iNumberReceiverSockets) {
        this->SetErrorString("No Receiver socket could be bound! Aborting!", 1);
        return 0;
    }

    this->m_pSenderSocket = socket(2, 2, 0);
    if(this->m_pSenderSocket == -1) {
        this->SetErrorString("Unable to create sender socket!", 1);
        return 0;
    }

    if(setsockopt(this->m_pSenderSocket, 0xFFFF, SO_BROADCAST, reinterpret_cast<const char *>(1), 4) == -1) {
        int v5 = WSAGetLastError();
        BBSupportTracePrintF(3, "::setsocketopt(SO_BROADCAST) failed: LastWSAError: %d!", v5);
        this->SetErrorString("SetSockOpt() failed", 1);
    }
    if(setsockopt(this->m_pSenderSocket, 0xFFFF, SO_REUSEADDR, reinterpret_cast<const char *>(1), 4) == -1) {
        int v6 = WSAGetLastError();
        BBSupportTracePrintF(3, "::setsocketopt(SO_REUSEADDR) failed: LastWSAError: %d!", v6);
        this->SetErrorString("SetSockOpt() failed", 1);
    }
    this->m_sReceiverSocketConfig.sin_port = htons(3105u);
    this->m_sReceiverSocketConfig.sin_addr.S_un.S_addr = this->m_iReceiverSocketAddress;
    memset(&name, 0, sizeof(name));
    namelen = 16;
    if(getsockname(this->m_pSenderSocket, reinterpret_cast<sockaddr *>(&name), &namelen) == -1) {
        int v7 = WSAGetLastError();
        BBSupportTracePrintF(3, "::getsocketname SenderSocket failed: LastWSAError: %d!", v7);
    }
    iPort = htons(name.sin_port);
    sIp = this->GetIPString(name.sin_addr.S_un.S_addr);
    BBSupportTracePrintF(1, "Simplenet.cpp: Sendersocket named %s:%d", sIp, iPort);
    return !this->m_bHasError;
}

// address=[0x15d1220]
// Decompiled from void __thiscall CSimpleNet::ClearErrorString(CSimpleNet *this)
void CSimpleNet::ClearErrorString(void) {
    this->m_sError = "";
    this->m_bHasError = 0;
}

// address=[0x15d14b0]
// Decompiled from void __thiscall CSimpleNet::SetErrorString(CSimpleNet *this, char *Str, char a3)
void CSimpleNet::SetErrorString(char const *Str, bool a3) {
    this->m_sError = Str;
    this->m_bHasError = a3;
}
