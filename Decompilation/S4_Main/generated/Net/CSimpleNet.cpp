#include "CSimpleNet.h"

// Definitions for class CSimpleNet

// address=[0x15ccbf0]
// Decompiled from CSimpleNet *__thiscall CSimpleNet::CSimpleNet(CSimpleNet *this)
CSimpleNet::CSimpleNet(void) {

    ISimpleNet::ISimpleNet(this);
    this->__vftable = (CSimpleNet_vtbl *)&CSimpleNet::_vftable_;
    std::list<SLocalAddress>::list<SLocalAddress>(&this->m_vLocalAddresses);
    std::list<SMessage>::list<SMessage>(&this->m_vResendMessages);
    std::string::string(&this->m_sError);
    this->m_iMessageCounter = 0;
    this->m_iLastTraceRun = 0;
    this->m_iSentBytes = 0;
    this->m_iSentCompressedBytes = 0;
    this->m_iLastDataLength = 0;
    this->m_iCompressedBytesPerSecond = 0;
    memset(this->field_184, 0, sizeof(this->field_184));
    this->m_iAdditionalLocalAddress = 0;
    this->m_iLastSenderPeerId = -1;
    CSimpleNet::ClearErrorString(this);
    if(CSimpleNet::LaunchWinsock(this) && CSimpleNet::EnumerateLocalIP(this))
        CSimpleNet::ConnectSocket(this);
    return this;
}

// address=[0x15ccd30]
// Decompiled from int __thiscall CSimpleNet::~CSimpleNet(CSimpleNet *this)
CSimpleNet::~CSimpleNet(void) {

    int v2; // [esp+0h] [ebp-18h]
    int v3; // [esp+0h] [ebp-18h]
    int v4; // [esp+0h] [ebp-18h]
    int v5; // [esp+0h] [ebp-18h]
    int i;  // [esp+4h] [ebp-14h]

    *(_DWORD *)this = &CSimpleNet::_vftable_;
    for(i = 0; i < *((_DWORD *)this + 59); ++i) {
        BBSupportTracePrintF(1, "Simplenet: Shutting down receiver socket %u", i);
        shutdown(*((_DWORD *)this + i + 60), 2);
        closesocket(*((_DWORD *)this + i + 60));
    }
    shutdown(*((_DWORD *)this + 92), 2);
    closesocket(*((_DWORD *)this + 92));
    std::list<SMessage>::clear(v2);
    std::list<SLocalAddress>::clear(v3);
    WSACleanup();
    std::string::~string((char *)this + 208);
    std::list<SMessage>::~list<SMessage>(v4);
    return std::list<SLocalAddress>::~list<SLocalAddress>(v5);
}

// address=[0x15cce40]
// Decompiled from std::string *__thiscall CSimpleNet::GetCurrentLocalIPString(CSimpleNet *this, std::string *a2)
std::string CSimpleNet::GetCurrentLocalIPString(void a2) {

    std::string::string(a2, this->m_sCurrentLocalIPString);
    return a2;
}

// address=[0x15cce80]
// Decompiled from char __thiscall CSimpleNet::Run(CSimpleNet *this)
bool CSimpleNet::Run(void) {

    float v1;            // xmm0_4
    float v2;            // xmm0_4
    int iBytesPerSecond; // [esp+10h] [ebp-18h]
    int iElapsedTimeMS;  // [esp+14h] [ebp-14h]
    DWORD Time;          // [esp+20h] [ebp-8h]

    Time = timeGetTime();
    if(this->m_iLastTraceRun + 20000 >= Time)
        return 1;
    iElapsedTimeMS = Time - this->m_iLastTraceRun;
    v1 = (float)(unsigned int)this->m_iSentBytes;
    iBytesPerSecond = (int)(float)(v1 / (float)((float)iElapsedTimeMS / 1000.0));
    v2 = (float)(unsigned int)this->m_iSentCompressedBytes;
    this->m_iCompressedBytesPerSecond = (unsigned int)(float)(v2 / (float)((float)iElapsedTimeMS / 1000.0));
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

    OnlineManager *Instance; // eax
    unsigned int v4;         // [esp+4h] [ebp-8h] BYREF

    Instance = (OnlineManager *)OnlineManager::GetInstance();
    OnlineManager::GetMessageCount(Instance, &v4);
    return v4 != 0;
}

// address=[0x15ccfd0]
// Decompiled from char __thiscall CSimpleNet::PopMessage(CSimpleNet *this, void **_rMessage, unsigned int *a3, unsigned int *_iPeerId)
bool CSimpleNet::PopMessage(void *&_rMessage, unsigned int &_iLength, unsigned int &_iPeerId) {

    OnlineManager *Instance; // eax
    int Error;               // eax
    char *iReceivedData;     // [esp-Ch] [ebp-1Ch]
    int v8;                  // [esp+0h] [ebp-10h] BYREF
    int iCompressedSize;     // [esp+4h] [ebp-Ch] BYREF
    int v10;                 // [esp+8h] [ebp-8h] BYREF

    *_rMessage = 0;
    *_iLength = 0;
    v10 = 0;
    iReceivedData = (char *)&this->m_vRawMessageBuffer;
    Instance = (OnlineManager *)OnlineManager::GetInstance();
    OnlineManager::Receive(Instance, iReceivedData, &v10, _iPeerId, (_DWORD *)v8);
    this->m_iLastSenderPeerId = *_iPeerId;
    if(v10 && v10 != -1) {
        if(((this->m_vRawMessageBuffer.m_iSize >> 12) & 0x3FF) != 0) // (m_iSize / 4096) % 1024
        {
            iCompressedSize = (this->m_vRawMessageBuffer.m_iSize >> 12) & 0x3FF;
            v8 = v10 - 4;
            this->m_iLastDataLength = iCompressedSize;
            this->m_pDecompressor = j__LZHLCreateDecompressor();
            memset(this->m_vCompressedMessageBuffer, 0, sizeof(this->m_vCompressedMessageBuffer));
            j__LZHLDecompress(
                this->m_pDecompressor,
                this->m_vCompressedMessageBuffer,
                &iCompressedSize,
                this->m_vRawMessageBuffer.m_vBuffer,
                &v8);
            j__LZHLDestroyDecompressor(this->m_pDecompressor);
            *_rMessage = this->m_vCompressedMessageBuffer;
            *_iLength = (this->m_vRawMessageBuffer.m_iSize >> 12) & 0x3FF;
        } else {
            *_rMessage = this->m_vRawMessageBuffer.m_vBuffer;
            *_iLength = v10 - 4;
            this->m_iLastDataLength = *_iLength;
        }
        return 1;
    } else {
        Error = WSAGetLastError();
        sprintf(this->m_sErrorFormatBuffer, "::recvfrom() failed: LastWSAError: %d!", Error);
        this->SetErrorString(this->m_sErrorFormatBuffer, 1);
        return 0;
    }
}

// address=[0x15cd190]
// Decompiled from int __thiscall CSimpleNet::PushMessage(  CSimpleNet *this,  uint _iPeerId,  uint _iId,  u_short _iReceiver,  void *_pData,  size_t _iDataLength,  char _bTryResend,  char a8)
bool CSimpleNet::PushMessage(unsigned int _iPeerId, unsigned int _iId, unsigned short _iReceiver, void *_pData, unsigned int _iDataLength, bool _bTryResend, bool a8) {

    __int16 iCompressedSize; // [esp+4h] [ebp-434h]
    uint8_t sz[1056];        // [esp+14h] [ebp-424h] BYREF

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
        if(j__LZHLCompressorCalcMaxBuf(_iDataLength) >= 0x800 && BBSupportDbgReport(2, "net\\SimpleNet.cpp", 999, "iBufferLen < sizeof( sMessage.m_sMessage.m_cDataBuffer )") == 1) {
            __debugbreak();
        }
        this->m_pCompressor = j__LZHLCreateCompressor();
        memset(sMessage.m_cDataBuffer, 0, sizeof(sMessage.m_cDataBuffer));
        iCompressedSize = j__LZHLCompress(this->m_pCompressor, sMessage.m_cDataBuffer, sz, _iDataLength);
        j__LZHLDestroyCompressor(this->m_pCompressor);
        sMessage.m_iFlags = ((_iDataLength & 0x3FF) << 12) | sMessage.m_iFlags & 0xFFC00FFF;
        sMessage.m_iFlags = ((iCompressedSize & 0x3FF) << 22) | sMessage.m_iFlags & 0x3FFFFF;
    } else {
        memcpy(sMessage.m_cDataBuffer, _pData, _iDataLength);
        sMessage.m_iFlags = ((_iDataLength & 0x3FF) << 22) | sMessage.m_iFlags & 0x3FFFFF;
        sMessage.m_iFlags &= 0xFFC00FFF;
    }
    sMessage.m_iFlags = (4 * (this->m_iMessageCounter++ & 0x3FF)) | sMessage.m_iFlags & 0xFFFFF003;
    if(this->m_iMessageCounter == 1024)
        this->m_iMessageCounter = 0;
    sMessage.m_iFlags &= 0xFFFFFFFC;
    sMessage.m_iFlags = (_bTryResend != 0) | sMessage.m_iFlags & 3 | sMessage.m_iFlags & 0xFFFFFFFC;
    if((sMessage.m_iFlags & 1) != 0)
        std::list<SMessage>::push_back(&this->m_vResendMessages, (int)&sMessage);
    return this->SendMessageA(this, _iPeerId, &sMessage);
}

// address=[0x15cd490]
// Decompiled from char *__thiscall CSimpleNet::GetIPString(CSimpleNet *this, struct in_addr a2)
char *CSimpleNet::GetIPString(unsigned int a2) {

    in = a2;
    return inet_ntoa(a2);
}

// address=[0x15cd4d0]
// Decompiled from int __thiscall CSimpleNet::RemoveMsgsForIP(CSimpleNet *this, ULONG _iAddress)
void CSimpleNet::RemoveMsgsForIP(unsigned int _iAddress) {

    const char *v2;             // eax
    const char *v4;             // eax
    char v5;                    // [esp-Ch] [ebp-80h] BYREF
    int v6;                     // [esp-8h] [ebp-7Ch]
    int v7;                     // [esp-4h] [ebp-78h]
    _BYTE v8[12];               // [esp+4h] [ebp-70h] BYREF
    _BYTE v9[12];               // [esp+10h] [ebp-64h] BYREF
    _BYTE v10[12];              // [esp+1Ch] [ebp-58h] BYREF
    _BYTE v11[12];              // [esp+28h] [ebp-4Ch] BYREF
    _BYTE v12[12];              // [esp+34h] [ebp-40h] BYREF
    int v13;                    // [esp+40h] [ebp-34h]
    int v14;                    // [esp+44h] [ebp-30h]
    char *v15;                  // [esp+48h] [ebp-2Ch]
    int v16;                    // [esp+4Ch] [ebp-28h]
    int v17;                    // [esp+50h] [ebp-24h]
    std::_Iterator_base12 *v18; // [esp+54h] [ebp-20h]
    std::_Iterator_base12 *v19; // [esp+58h] [ebp-1Ch]
    int v20;                    // [esp+5Ch] [ebp-18h]
    char v22;                   // [esp+67h] [ebp-Dh]
    int v23;                    // [esp+70h] [ebp-4h]

    v20 = 0;
    if(std::list<SMessage>::size(&this->m_vResendMessages)) {
        std::list<SMessage>::begin(v12);
        v23 = 0;
        while(1) {
            v19 = (std::_Iterator_base12 *)std::list<SMessage>::end(v11);
            v18 = v19;
            LOBYTE(v23) = 1;
            v22 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::operator!=(v19);
            LOBYTE(v23) = 0;
            std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>(v11);
            if(!v22)
                break;
            if(*(_DWORD *)(std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::operator->(v12) + 8) == _iAddress) {
                v15 = &v5;
                v14 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<SMessage>>>(v12);
                v13 = std::list<SMessage>::erase(v10, v5, v6, v7);
                std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>(v10);
                if(!std::list<SMessage>::size(&this->m_vResendMessages))
                    break;
                v17 = std::list<SMessage>::begin(v9);
                v16 = v17;
                LOBYTE(v23) = 2;
                std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::operator=(v17);
                LOBYTE(v23) = 0;
                std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>(v9);
                ++v20;
            } else {
                std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::operator++(v8, 0);
                std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>(v8);
            }
        }
        v23 = -1;
        std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>(v12);
    }
    if(v20) {
        v2 = this->GetIPString(this, _iAddress);
        return CTrace::Print("SimpleNet.cpp: Removed %d msgs for IP %s!", v20, v2);
    } else {
        v4 = this->GetIPString(this, _iAddress);
        return CTrace::Print("SimpleNet.cpp: No msgs could be removed for IP %s!", v4);
    }
}

// address=[0x15cd6a0]
// Decompiled from char __thiscall CSimpleNet::IsLocalIP(CSimpleNet *this, unsigned int _iAddress)
bool CSimpleNet::IsLocalIP(unsigned int _iAddress) {

    _BYTE v3[12];              // [esp+4h] [ebp-48h] BYREF
    _BYTE v4[12];              // [esp+10h] [ebp-3Ch] BYREF
    _BYTE v5[12];              // [esp+1Ch] [ebp-30h] BYREF
    struct SLocalAddress *v6;  // [esp+28h] [ebp-24h]
    std::_Iterator_base12 *v7; // [esp+2Ch] [ebp-20h]
    std::_Iterator_base12 *v8; // [esp+30h] [ebp-1Ch]
    char v11;                  // [esp+3Eh] [ebp-Eh]
    bool v12;                  // [esp+3Fh] [ebp-Dh]
    int v13;                   // [esp+48h] [ebp-4h]

    if(!std::list<SLocalAddress>::size(&this->m_vLocalAddresses))
        return this->m_iAdditionalLocalAddress && _iAddress == this->m_iAdditionalLocalAddress;
    std::list<SLocalAddress>::begin(&this->m_vLocalAddresses, (int)v5);
    v13 = 0;
    while(1) {
        v8 = (std::_Iterator_base12 *)std::list<SLocalAddress>::end(&this->m_vLocalAddresses, (int)v3);
        v7 = v8;
        LOBYTE(v13) = 1;
        v12 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::operator!=(
            (std::_Iterator_base12 *)v5,
            v8);
        LOBYTE(v13) = 0;
        std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>(v3);
        if(!v12)
            break;
        v6 = std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::operator*(v5);
        if(v6->m_iAddress.S_un.S_addr == _iAddress) {
            v11 = 1;
            v13 = -1;
            std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>(v5);
            return v11;
        }
        std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::operator++((int)v4, 0);
        std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>(v4);
    }
    v13 = -1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>(v5);
    return this->m_iAdditionalLocalAddress && _iAddress == this->m_iAdditionalLocalAddress;
}

// address=[0x15d1290]
// Decompiled from void __thiscall CSimpleNet::Delete(CSimpleNet *this)
void CSimpleNet::Delete(void) {

    if(this)
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

    char *v1;        // eax
    unsigned int v3; // [esp+8h] [ebp-10h]

    v1 = std::string::c_str(&a1);
    v3 = inet_addr(v1);
    std::string::~string(&a1);
    return v3;
}

// address=[0x15d13a0]
// Decompiled from int __thiscall CSimpleNet::GetLastDataLength(CSimpleNet *this)
unsigned int CSimpleNet::GetLastDataLength(void) {

    return this->m_iLastDataLength;
}

// address=[0x15d13c0]
// Decompiled from std::string *__thiscall CSimpleNet::GetLastErrorString(CSimpleNet *this, std::string *a2)
std::string CSimpleNet::GetLastErrorString(void a2) {

    std::string::string(a2, (int)&this->m_sError);
    return a2;
}

// address=[0x15d1400]
// Decompiled from int __thiscall CSimpleNet::GetLastSenderIP(CSimpleNet *this)
long CSimpleNet::GetLastSenderIP(void) {

    return *(_DWORD *)&this->field_184[4];
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
    if(std::list<SMessage>::size(&this->m_vResendMessages))
        std::list<SMessage>::clear(&this->m_vResendMessages);
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
bool CSimpleNet::SendMessageA(unsigned int _iPeerId, struct SMessage &_rMessage) {

    return this->RealSendMessage(this, _iPeerId, _rMessage) != 0;
}

// address=[0x15cdc40]
// Decompiled from char __thiscall CSimpleNet::RealSendMessage(CSimpleNet *this, unsigned int a2, struct SMessage *a3)
bool CSimpleNet::RealSendMessage(unsigned int a2, struct SMessage &a3) {

    OnlineManager *Instance; // eax
    OnlineManager *v4;       // eax
    size_t v6;               // [esp+4h] [ebp-8h]

    word_415C398 = 2;
    word_415C39A = a3->m_iReceiverId;
    dword_415C39C = a3->m_iId;
    v6 = ((unsigned __int16)HIWORD(a3->m_iFlags) >> 6) + 4;
    if(a3->m_iId == -1) {
        Instance = (OnlineManager *)OnlineManager::GetInstance();
        OnlineManager::Send(Instance, &a3->m_iFlags, v6);
    } else {
        v4 = (OnlineManager *)OnlineManager::GetInstance();
        OnlineManager::Send(v4, a2, &a3->m_iFlags, v6);
    }
    this->m_iSentBytes += v6;
    this->m_iSentCompressedBytes += v6;
    if((((unsigned int)a3->m_iFlags >> 12) & 0x3FF) != 0)
        this->m_iSentBytes += (((unsigned int)a3->m_iFlags >> 12) & 0x3FF) - ((unsigned __int16)HIWORD(a3->m_iFlags) >> 6);
    return 1;
}

// address=[0x15cdd50]
// Decompiled from char __thiscall CSimpleNet::RemoveMsgFromResendList(CSimpleNet *this, unsigned __int16 a2)
bool CSimpleNet::RemoveMsgFromResendList(unsigned short a2) {

    char v3;                    // [esp-Ch] [ebp-68h] BYREF
    int v4;                     // [esp-8h] [ebp-64h]
    int v5;                     // [esp-4h] [ebp-60h]
    _BYTE v6[12];               // [esp+4h] [ebp-58h] BYREF
    _BYTE v7[12];               // [esp+10h] [ebp-4Ch] BYREF
    _BYTE v8[12];               // [esp+1Ch] [ebp-40h] BYREF
    _BYTE v9[12];               // [esp+28h] [ebp-34h] BYREF
    int v10;                    // [esp+34h] [ebp-28h]
    int v11;                    // [esp+38h] [ebp-24h]
    char *v12;                  // [esp+3Ch] [ebp-20h]
    std::_Iterator_base12 *v13; // [esp+40h] [ebp-1Ch]
    std::_Iterator_base12 *v14; // [esp+44h] [ebp-18h]
    char v16;                   // [esp+4Eh] [ebp-Eh]
    char v17;                   // [esp+4Fh] [ebp-Dh]
    int v18;                    // [esp+58h] [ebp-4h]

    if(!std::list<SMessage>::size(&this->m_vResendMessages))
        return 1;
    std::list<SMessage>::begin(v9);
    v18 = 0;
    while(1) {
        v14 = (std::_Iterator_base12 *)std::list<SMessage>::end(v8);
        v13 = v14;
        LOBYTE(v18) = 1;
        v17 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::operator!=(v14);
        LOBYTE(v18) = 0;
        std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>(v8);
        if(!v17)
            break;
        if(((*(_DWORD *)(std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::operator->(v9) + 14) >> 2) & 0x3FF) == a2) {
            v12 = &v3;
            v11 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<SMessage>>>(v9);
            v10 = std::list<SMessage>::erase(v7, v3, v4, v5);
            std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>(v7);
            v16 = 1;
            v18 = -1;
            std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>(v9);
            return v16;
        }
        std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::operator++(v6, 0);
        std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>(v6);
    }
    v18 = -1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>(v9);
    return 0;
}

// address=[0x15cdea0]
// Decompiled from bool __thiscall CSimpleNet::LaunchWinsock(CSimpleNet *this)
bool CSimpleNet::LaunchWinsock(void) {

    struct WSAData WSAData; // [esp+10h] [ebp-194h] BYREF

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

    return 1;
}

// address=[0x15ce3c0]
// Decompiled from bool __thiscall CSimpleNet::ConnectSocket(CSimpleNet *this)
bool CSimpleNet::ConnectSocket(void) {

    struct SLocalAddress *rLocalAddress; // eax
    struct SLocalAddress *v2;            // eax
    const char *sIp;                     // eax MAPDST
    int v5;                              // eax
    int v6;                              // eax
    int v7;                              // eax
    int Error;                           // [esp-4h] [ebp-80h]
    int iPort;                           // [esp-4h] [ebp-80h] MAPDST
    _BYTE v12[12];                       // [esp+4h] [ebp-78h] BYREF
    _BYTE pEnd_[12];                     // [esp+10h] [ebp-6Ch] BYREF
    _BYTE v14[12];                       // [esp+1Ch] [ebp-60h] BYREF
    int namelen;                         // [esp+28h] [ebp-54h] BYREF
    int v16;                             // [esp+2Ch] [ebp-50h] BYREF
    int optval;                          // [esp+30h] [ebp-4Ch] BYREF
    int v19;                             // [esp+38h] [ebp-44h] MAPDST
    std::_Iterator_base12 *pEnd;         // [esp+40h] [ebp-3Ch] MAPDST
    _BYTE pIt[12];                       // [esp+44h] [ebp-38h] BYREF
    bool bIsEnd;                         // [esp+57h] [ebp-25h]
    struct sockaddr_in name;             // [esp+5Ch] [ebp-20h] BYREF
    int exceptionBlock;                  // [esp+78h] [ebp-4h]

    this->m_iNumberReceiverSockets = 0;
    std::list<SLocalAddress>::begin(&this->m_vLocalAddresses, (int)pIt);
    exceptionBlock = 0;
    while(1) {
        pEnd = (std::_Iterator_base12 *)std::list<SLocalAddress>::end(&this->m_vLocalAddresses, (int)pEnd_);
        LOBYTE(exceptionBlock) = 1;
        bIsEnd = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::operator!=(
            (std::_Iterator_base12 *)pIt,
            pEnd);
        LOBYTE(exceptionBlock) = 0;
        std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>(pEnd_);
        if(!bIsEnd)
            break;
        if(this->m_iNumberReceiverSockets >= 32 && BBSupportDbgReport(2, "net\\SimpleNet.cpp", 614, "m_iNumberReceiverSockets < MAX_RECEIVER_SOCKETS") == 1) {
            __debugbreak();
        }
        if(this->m_iNumberReceiverSockets == 32) {
            v19 = std::list<SLocalAddress>::end(&this->m_vLocalAddresses, (int)v12);
            LOBYTE(exceptionBlock) = 2;
            std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::operator=(pIt, v19);
            LOBYTE(exceptionBlock) = 0;
            std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>(v12);
        } else if(std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::operator*(pIt) -> m_bU) {
            this->m_pReceiverSockets[this->m_iNumberReceiverSockets] = socket(2, 2, 0);
            if(this->m_pReceiverSockets[this->m_iNumberReceiverSockets] == -1) {
                this->SetErrorString("Unable to create socket!", 1);
                BBSupportTracePrintF(3, "Unable to create socket!");
            } else {
                this->m_sReceiverSocketConfig.sin_family = 2;
                this->m_sReceiverSocketConfig.sin_port = htons(3105u);
                rLocalAddress = std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::operator*(pIt);
                this->m_sReceiverSocketConfig.sin_addr.S_un.S_addr = rLocalAddress->m_iAddress.S_un.S_addr;
                if(bind(
                       this->m_pReceiverSockets[this->m_iNumberReceiverSockets],
                       (const struct sockaddr *)&this->m_sReceiverSocketConfig,
                       16) == -1) {
                    Error = WSAGetLastError();
                    v2 = std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::operator*(pIt);
                    sprintf(this->m_sErrorFormatBuffer, "SimpleNet: ::bind() to %s failed: LastWSAError: %d!", v2->m_sIp, Error);
                    this->SetErrorString(this->m_sErrorFormatBuffer, 1);
                    BBSupportTracePrintF(3, this->m_sErrorFormatBuffer);
                } else {
                    iPort = htons(this->m_sReceiverSocketConfig.sin_port);
                    sIp = this->GetIPString(this, this->m_sReceiverSocketConfig.sin_addr.S_un.S_addr);
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
        std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::operator++((int)v14, 0);
        std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>(v14);
    }
    exceptionBlock = -1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>(pIt);
    if(this->m_iNumberReceiverSockets) {
        this->m_pSenderSocket = socket(2, 2, 0);
        if(this->m_pSenderSocket == -1) {
            this->SetErrorString("Unable to create sender socket!", 1);
            return 0;
        } else {
            optval = 1;
            v16 = 1;
            if(setsockopt(this->m_pSenderSocket, 0xFFFF, SO_BROADCAST, (const char *)&optval, 4) == -1) {
                v5 = WSAGetLastError();
                BBSupportTracePrintF(3, "::setsocketopt(SO_BROADCAST) failed: LastWSAError: %d!", v5);
                this->SetErrorString("SetSockOpt() failed", 1);
            }
            if(setsockopt(this->m_pSenderSocket, 0xFFFF, SO_REUSEADDR, (const char *)&v16, 4) == -1) {
                v6 = WSAGetLastError();
                BBSupportTracePrintF(3, "::setsocketopt(SO_REUSEADDR) failed: LastWSAError: %d!", v6);
                this->SetErrorString("SetSockOpt() failed", 1);
            }
            this->m_sReceiverSocketConfig.sin_port = htons(3105u);
            this->m_sReceiverSocketConfig.sin_addr.S_un.S_addr = this->m_iReceiverSocketAddress;
            memset(&name, 0, sizeof(name));
            namelen = 16;
            if(getsockname(this->m_pSenderSocket, (struct sockaddr *)&name, &namelen) == -1) {
                v7 = WSAGetLastError();
                BBSupportTracePrintF(3, "::getsocketname SenderSocket failed: LastWSAError: %d!", v7);
            }
            iPort = htons(name.sin_port);
            sIp = this->GetIPString(this, name.sin_addr.S_un.S_addr);
            BBSupportTracePrintF(1, "Simplenet.cpp: Sendersocket named %s:%d", sIp, iPort);
            return !this->m_bHasError;
        }
    } else {
        this->SetErrorString("No Receiver socket could be bound! Aborting!", 1);
        return 0;
    }
}

// address=[0x15d1220]
// Decompiled from void __thiscall CSimpleNet::ClearErrorString(CSimpleNet *this)
void CSimpleNet::ClearErrorString(void) {

    struct std::string *v1; // [esp+0h] [ebp-28h]
    std::string v3;         // [esp+8h] [ebp-20h] BYREF

    v1 = std::string::string(&v3, (char *)&off_366DCF4);
    std::string::operator=(&this->m_sError, v1);
    std::string::~string(&v3);
    this->m_bHasError = 0;
}

// address=[0x15d14b0]
// Decompiled from void __thiscall CSimpleNet::SetErrorString(CSimpleNet *this, char *Str, char a3)
void CSimpleNet::SetErrorString(char const *Str, bool a3) {

    struct std::string *v3; // [esp+0h] [ebp-28h]
    std::string v5;         // [esp+8h] [ebp-20h] BYREF

    v3 = std::string::string(&v5, Str);
    std::string::operator=(&this->m_sError, v3);
    std::string::~string(&v5);
    this->m_bHasError = a3;
}
