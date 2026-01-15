#include "CSimpleNet.h"

// Definitions for class CSimpleNet

// address=[0x15ccbf0]
// Decompiled from CSimpleNet *__thiscall CSimpleNet::CSimpleNet(CSimpleNet *this)
 CSimpleNet::CSimpleNet(void) {
  
  ISimpleNet::ISimpleNet(this);
  *(_DWORD *)this = &CSimpleNet::_vftable_;
  std::list<SLocalAddress>::list<SLocalAddress>((char *)this + 4);
  std::list<SMessage>::list<SMessage>((char *)this + 184);
  std::string::string();
  *((_WORD *)this + 98) = 0;
  *((_DWORD *)this + 105) = 0;
  *((_DWORD *)this + 103) = 0;
  *((_DWORD *)this + 104) = 0;
  *((_DWORD *)this + 107) = 0;
  *((_DWORD *)this + 106) = 0;
  memset((char *)this + 388, 0, 0x10u);
  *((_DWORD *)this + 45) = 0;
  *((_DWORD *)this + 101) = -1;
  CSimpleNet::ClearErrorString(this);
  if ( CSimpleNet::LaunchWinsock(this) && CSimpleNet::EnumerateLocalIP(this) )
    CSimpleNet::ConnectSocket(this);
  return this;
}


// address=[0x15ccd30]
// Decompiled from int __thiscall CSimpleNet::~CSimpleNet(CSimpleNet *this)
 CSimpleNet::~CSimpleNet(void) {
  
  int v2; // [esp-4h] [ebp-1Ch]
  int v3; // [esp-4h] [ebp-1Ch]
  int v4; // [esp-4h] [ebp-1Ch]
  int i; // [esp+4h] [ebp-14h]

  *(_DWORD *)this = &CSimpleNet::_vftable_;
  for ( i = 0; i < *((_DWORD *)this + 59); ++i )
  {
    BBSupportTracePrintF(1, "Simplenet: Shutting down receiver socket %u", i);
    dword_415B98C(*((_DWORD *)this + i + 60));
    dword_415B988(*((_DWORD *)this + i + 60));
  }
  dword_415B98C(*((_DWORD *)this + 92));
  dword_415B988(*((_DWORD *)this + 92));
  std::list<SMessage>::clear(2);
  std::list<SLocalAddress>::clear(v2);
  dword_415B97C();
  std::string::~string((char *)this + 208);
  std::list<SMessage>::~list<SMessage>(v3);
  return std::list<SLocalAddress>::~list<SLocalAddress>(v4);
}


// address=[0x15cce40]
// Decompiled from void *__thiscall CSimpleNet::GetCurrentLocalIPString(char *this, void *a2)
std::string  CSimpleNet::GetCurrentLocalIPString(void) {
  
  std::string::string(a2, this + 20);
  return a2;
}


// address=[0x15cce80]
// Decompiled from char __thiscall CSimpleNet::Run(CSimpleNet *this)
bool  CSimpleNet::Run(void) {
  
  float v1; // xmm0_4
  float v2; // xmm0_4
  int v4; // [esp+10h] [ebp-18h]
  int v5; // [esp+14h] [ebp-14h]
  DWORD Time; // [esp+20h] [ebp-8h]

  Time = timeGetTime();
  if ( *((_DWORD *)this + 105) + 20000 >= Time )
    return 1;
  v5 = Time - *((_DWORD *)this + 105);
  v1 = (float)*((unsigned int *)this + 103);
  v4 = (int)(float)(v1 / (float)((float)v5 / 1000.0));
  v2 = (float)*((unsigned int *)this + 104);
  *((_DWORD *)this + 106) = (unsigned int)(float)(v2 / (float)((float)v5 / 1000.0));
  *((_DWORD *)this + 103) = 0;
  *((_DWORD *)this + 104) = 0;
  *((_DWORD *)this + 105) = Time;
  BBSupportTracePrintF(1, "SimpleNet: Bytes/sec: Uncompressed %u, Compressed %u", v4, *((_DWORD *)this + 106));
  return 1;
}


// address=[0x15ccf90]
// Decompiled from bool __thiscall CSimpleNet::IsMessage(CSimpleNet *this, int a2)
bool  CSimpleNet::IsMessage(int) {
  
  OnlineManager *Instance; // eax
  unsigned int v4; // [esp+4h] [ebp-8h] BYREF

  Instance = (OnlineManager *)OnlineManager::GetInstance();
  OnlineManager::GetMessageCount(Instance, &v4);
  return v4 != 0;
}


// address=[0x15ccfd0]
// Decompiled from char __thiscall CSimpleNet::PopMessage(CSimpleNet *this, void **a2, unsigned int *a3, unsigned int *a4)
bool  CSimpleNet::PopMessage(void * &,unsigned int &,unsigned int &) {
  
  int v4; // eax
  int v6; // eax
  void *v7; // [esp-Ch] [ebp-1Ch]
  int v8; // [esp+0h] [ebp-10h] BYREF
  int v9; // [esp+4h] [ebp-Ch] BYREF
  int v10; // [esp+8h] [ebp-8h] BYREF
  CSimpleNet *v11; // [esp+Ch] [ebp-4h]

  v11 = this;
  *a2 = 0;
  *a3 = 0;
  v10 = 0;
  v7 = (char *)v11 + 2480;
  OnlineManager::GetInstance();
  OnlineManager::Receive(v7, (int)&v10, (int)a4);
  *((_DWORD *)v11 + 101) = *a4;
  if ( v10 && v10 != -1 )
  {
    if ( ((*((_DWORD *)v11 + 620) >> 12) & 0x3FF) != 0 )
    {
      v9 = (*((_DWORD *)v11 + 620) >> 12) & 0x3FF;
      v8 = v10 - 4;
      *((_DWORD *)v11 + 107) = v9;
      v6 = j__LZHLCreateDecompressor(v8, v9);
      *((_DWORD *)v11 + 1134) = v6;
      memset((char *)v11 + 1456, 0, 0x400u);
      j__LZHLDecompress(*((_DWORD *)v11 + 1134), (char *)v11 + 1456, &v9, (char *)v11 + 2484, &v8);
      j__LZHLDestroyDecompressor(*((_DWORD *)v11 + 1134));
      *a2 = (char *)v11 + 1456;
      *a3 = (*((_DWORD *)v11 + 620) >> 12) & 0x3FF;
    }
    else
    {
      *a2 = (char *)v11 + 2484;
      *a3 = v10 - 4;
      *((_DWORD *)v11 + 107) = *a3;
    }
    return 1;
  }
  else
  {
    v4 = dword_415B980();
    j__sprintf((char *const)v11 + 432, "::recvfrom() failed: LastWSAError: %d!", v4);
    (*(void (__thiscall **)(CSimpleNet *, int, int))(*(_DWORD *)v11 + 88))(v11, (int)v11 + 432, 1);
    return 0;
  }
}


// address=[0x15cd190]
// Decompiled from int __thiscall CSimpleNet::PushMessage(  _DWORD *this,  int a2,  int a3,  unsigned __int16 a4,  void *Src,  size_t Size,  char a7,  char a8)
bool  CSimpleNet::PushMessage(unsigned int,unsigned int,unsigned short,void *,unsigned int,bool,bool) {
  
  __int16 v9; // [esp+4h] [ebp-434h]
  _BYTE v11[1056]; // [esp+14h] [ebp-424h] BYREF

  dword_415B9E8 = timeGetTime();
  word_415B9F4 = dword_415B9AC(a4);
  dword_415B9F0 = a3;
  dword_415B9EC = 0;
  if ( Size > 0x400 && BBSupportDbgReport(2, "net\\SimpleNet.cpp", 978, "_iDataLength <= MESSAGE_LENGTH") == 1 )
    __debugbreak();
  if ( a8 )
  {
    if ( Size > 0x400 )
      Size = 1024;
    j__memcpy(v11, Src, Size);
    memset(&v11[Size], 0, 0x20u);
    if ( j__LZHLCompressorCalcMaxBuf(Size) >= 0x800u
      && BBSupportDbgReport(2, "net\\SimpleNet.cpp", 999, "iBufferLen < sizeof( sMessage.m_sMessage.m_cDataBuffer )") == 1 )
    {
      __debugbreak();
    }
    this[1133] = j__LZHLCreateCompressor(0, 32);
    memset(&unk_415B9FA, 0, 0x800u);
    v9 = j__LZHLCompress(this[1133], &unk_415B9FA, v11, Size);
    j__LZHLDestroyCompressor(this[1133]);
    dword_415B9F6 = ((Size & 0x3FF) << 12) | dword_415B9F6 & 0xFFC00FFF;
    dword_415B9F6 = ((v9 & 0x3FF) << 22) | dword_415B9F6 & 0x3FFFFF;
  }
  else
  {
    j__memcpy(&unk_415B9FA, Src, Size);
    dword_415B9F6 = ((Size & 0x3FF) << 22) | dword_415B9F6 & 0x3FFFFF;
    dword_415B9F6 &= 0xFFC00FFF;
  }
  dword_415B9F6 = (4 * ((*((_WORD *)this + 98))++ & 0x3FF)) | dword_415B9F6 & 0xFFFFF003;
  if ( *((_WORD *)this + 98) == 1024 )
    *((_WORD *)this + 98) = 0;
  dword_415B9F6 &= 0xFFFFFFFC;
  dword_415B9F6 = (a7 != 0) | dword_415B9F6 & 3 | dword_415B9F6 & 0xFFFFFFFC;
  if ( (dword_415B9F6 & 1) != 0 )
    std::list<SMessage>::push_back(&dword_415B9E8);
  return (*(int (__thiscall **)(_DWORD *, int, int *))(*this + 76))(this, a2, &dword_415B9E8);
}


// address=[0x15cd490]
// Decompiled from int __thiscall CSimpleNet::GetIPString(CSimpleNet *this, int a2)
char *  CSimpleNet::GetIPString(unsigned int) {
  
  dword_415C3AC = a2;
  return dword_415B990(a2);
}


// address=[0x15cd4d0]
// Decompiled from int __thiscall CSimpleNet::RemoveMsgsForIP(CSimpleNet *this, unsigned int a2)
void  CSimpleNet::RemoveMsgsForIP(unsigned int) {
  
  const char *v2; // eax
  const char *v4; // eax
  char v5; // [esp-Ch] [ebp-80h] BYREF
  int v6; // [esp-8h] [ebp-7Ch]
  int v7; // [esp-4h] [ebp-78h]
  _BYTE v8[12]; // [esp+4h] [ebp-70h] BYREF
  _BYTE v9[12]; // [esp+10h] [ebp-64h] BYREF
  _BYTE v10[12]; // [esp+1Ch] [ebp-58h] BYREF
  _BYTE v11[12]; // [esp+28h] [ebp-4Ch] BYREF
  _BYTE v12[12]; // [esp+34h] [ebp-40h] BYREF
  int v13; // [esp+40h] [ebp-34h]
  int v14; // [esp+44h] [ebp-30h]
  char *v15; // [esp+48h] [ebp-2Ch]
  int v16; // [esp+4Ch] [ebp-28h]
  int v17; // [esp+50h] [ebp-24h]
  std::_Iterator_base12 *v18; // [esp+54h] [ebp-20h]
  std::_Iterator_base12 *v19; // [esp+58h] [ebp-1Ch]
  int v20; // [esp+5Ch] [ebp-18h]
  CSimpleNet *v21; // [esp+60h] [ebp-14h]
  char v22; // [esp+67h] [ebp-Dh]
  int v23; // [esp+70h] [ebp-4h]

  v21 = this;
  v20 = 0;
  if ( std::list<SMessage>::size((char *)this + 184) )
  {
    std::list<SMessage>::begin(v12);
    v23 = 0;
    while ( 1 )
    {
      v19 = (std::_Iterator_base12 *)std::list<SMessage>::end(v11);
      v18 = v19;
      LOBYTE(v23) = 1;
      v22 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::operator!=(v19);
      LOBYTE(v23) = 0;
      std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>(v11);
      if ( !v22 )
        break;
      if ( *(_DWORD *)(std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::operator->(v12) + 8) == a2 )
      {
        v15 = &v5;
        v14 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<SMessage>>>(v12);
        v13 = std::list<SMessage>::erase(v10, v5, v6, v7);
        std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>(v10);
        if ( !std::list<SMessage>::size((char *)v21 + 184) )
          break;
        v17 = std::list<SMessage>::begin(v9);
        v16 = v17;
        LOBYTE(v23) = 2;
        std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::operator=(v17);
        LOBYTE(v23) = 0;
        std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>(v9);
        ++v20;
      }
      else
      {
        std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::operator++(v8, 0);
        std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>(v8);
      }
    }
    v23 = -1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>(v12);
  }
  if ( v20 )
  {
    v2 = (const char *)(*(int (__thiscall **)(CSimpleNet *, unsigned int))(*(_DWORD *)v21 + 48))(v21, a2);
    return CTrace::Print("SimpleNet.cpp: Removed %d msgs for IP %s!", v20, v2);
  }
  else
  {
    v4 = (const char *)(*(int (__thiscall **)(CSimpleNet *, unsigned int))(*(_DWORD *)v21 + 48))(v21, a2);
    return CTrace::Print("SimpleNet.cpp: No msgs could be removed for IP %s!", v4);
  }
}


// address=[0x15cd6a0]
// Decompiled from bool __thiscall CSimpleNet::IsLocalIP(CSimpleNet *this, unsigned int a2)
bool  CSimpleNet::IsLocalIP(unsigned int) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-48h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-3Ch] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-30h] BYREF
  _DWORD *v6; // [esp+28h] [ebp-24h]
  std::_Iterator_base12 *v7; // [esp+2Ch] [ebp-20h]
  std::_Iterator_base12 *v8; // [esp+30h] [ebp-1Ch]
  CSimpleNet *v10; // [esp+38h] [ebp-14h]
  char v11; // [esp+3Eh] [ebp-Eh]
  char v12; // [esp+3Fh] [ebp-Dh]
  int v13; // [esp+48h] [ebp-4h]

  v10 = this;
  if ( !std::list<SLocalAddress>::size((char *)this + 4) )
    return *((_DWORD *)v10 + 45) && a2 == *((_DWORD *)v10 + 45);
  std::list<SLocalAddress>::begin(v5);
  v13 = 0;
  while ( 1 )
  {
    v8 = (std::_Iterator_base12 *)std::list<SLocalAddress>::end(v3);
    v7 = v8;
    LOBYTE(v13) = 1;
    v12 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::operator!=(v8);
    LOBYTE(v13) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>(v3);
    if ( !v12 )
      break;
    v6 = (_DWORD *)std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::operator*(v5);
    if ( *v6 == a2 )
    {
      v11 = 1;
      v13 = -1;
      std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>(v5);
      return v11;
    }
    std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::operator++(v4, 0);
    std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>(v4);
  }
  v13 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>(v5);
  return *((_DWORD *)v10 + 45) && a2 == *((_DWORD *)v10 + 45);
}


// address=[0x15d1290]
// Decompiled from CSimpleNet *__thiscall CSimpleNet::Delete(CSimpleNet *this)
void  CSimpleNet::Delete(void) {
  
  CSimpleNet *result; // eax

  result = this;
  if ( this )
    return (CSimpleNet *)CSimpleNet::`scalar deleting destructor'(this, 1u);
  return result;
}


// address=[0x15d12e0]
// Decompiled from int __thiscall CSimpleNet::GetBytesPerSecond(CSimpleNet *this)
unsigned int  CSimpleNet::GetBytesPerSecond(void) {
  
  return *((_DWORD *)this + 106);
}


// address=[0x15d1300]
// Decompiled from int __thiscall CSimpleNet::GetCurrentLocalIPLong(CSimpleNet *this)
long  CSimpleNet::GetCurrentLocalIPLong(void) {
  
  return *((_DWORD *)this + 4);
}


// address=[0x15d1320]
// Decompiled from int __stdcall CSimpleNet::GetIPLong(char a1, int a2, int a3, int a4, int a5, int a6, int a7)
unsigned int  CSimpleNet::GetIPLong(std::string) {
  
  int v7; // eax
  int v9; // [esp+8h] [ebp-10h]

  v7 = std::string::c_str(&a1);
  v9 = dword_415B984(v7);
  std::string::~string(&a1);
  return v9;
}


// address=[0x15d13a0]
// Decompiled from int __thiscall CSimpleNet::GetLastDataLength(CSimpleNet *this)
unsigned int  CSimpleNet::GetLastDataLength(void) {
  
  return *((_DWORD *)this + 107);
}


// address=[0x15d13c0]
// Decompiled from int __thiscall CSimpleNet::GetLastErrorString(char *this, int a2)
std::string  CSimpleNet::GetLastErrorString(void) {
  
  std::string::string(this + 208);
  return a2;
}


// address=[0x15d1400]
// Decompiled from int __thiscall CSimpleNet::GetLastSenderIP(CSimpleNet *this)
long  CSimpleNet::GetLastSenderIP(void) {
  
  return *((_DWORD *)this + 98);
}


// address=[0x15d1420]
// Decompiled from int __thiscall CSimpleNet::GetLastSenderPeerId(CSimpleNet *this)
unsigned int  CSimpleNet::GetLastSenderPeerId(void) {
  
  return *((_DWORD *)this + 101);
}


// address=[0x15d1440]
// Decompiled from int __thiscall CSimpleNet::RemoveAllResendMsgs(CSimpleNet *this)
void  CSimpleNet::RemoveAllResendMsgs(void) {
  
  int result; // eax

  CTrace::Print("SimpleNet: Clearing resend list!");
  result = std::list<SMessage>::size((char *)this + 184);
  if ( result )
    return std::list<SMessage>::clear(this);
  return result;
}


// address=[0x15d1490]
// Decompiled from CSimpleNet *__thiscall CSimpleNet::SetAdditionalLocalAddress(CSimpleNet *this, unsigned int a2)
void  CSimpleNet::SetAdditionalLocalAddress(unsigned int) {
  
  CSimpleNet *result; // eax

  result = this;
  *((_DWORD *)this + 45) = a2;
  return result;
}


// address=[0x15d1520]
// Decompiled from char __thiscall CSimpleNet::WasError(CSimpleNet *this)
bool  CSimpleNet::WasError(void) {
  
  return *((_BYTE *)this + 204);
}


// address=[0x15cd7d0]
// Decompiled from bool __thiscall CSimpleNet::SendMessageA(CSimpleNet *this, unsigned int a2, struct SMessage *a3)
bool  CSimpleNet::SendMessageA(unsigned int,struct SMessage &) {
  
  return (*(unsigned __int8 (__thiscall **)(CSimpleNet *, unsigned int, struct SMessage *))(*(_DWORD *)this + 80))(
           this,
           a2,
           a3) != 0;
}


// address=[0x15cdc40]
// Decompiled from char __thiscall CSimpleNet::RealSendMessage(CSimpleNet *this, unsigned int a2, struct SMessage *a3)
bool  CSimpleNet::RealSendMessage(unsigned int,struct SMessage &) {
  
  OnlineManager *Instance; // eax
  OnlineManager *v4; // eax
  unsigned int v6; // [esp+4h] [ebp-8h]

  word_415C398 = 2;
  word_415C39A = *((_WORD *)a3 + 6);
  dword_415C39C = *((_DWORD *)a3 + 2);
  v6 = ((unsigned __int16)HIWORD(*(_DWORD *)((char *)a3 + 14)) >> 6) + 4;
  if ( *((_DWORD *)a3 + 2) == -1 )
  {
    Instance = (OnlineManager *)OnlineManager::GetInstance();
    OnlineManager::Send(Instance, (char *)a3 + 14, v6);
  }
  else
  {
    v4 = (OnlineManager *)OnlineManager::GetInstance();
    OnlineManager::Send(v4, a2, (char *)a3 + 14, v6);
  }
  *((_DWORD *)this + 103) += v6;
  *((_DWORD *)this + 104) += v6;
  if ( ((*(_DWORD *)((char *)a3 + 14) >> 12) & 0x3FF) != 0 )
    *((_DWORD *)this + 103) += ((*(_DWORD *)((char *)a3 + 14) >> 12) & 0x3FF)
                             - ((unsigned __int16)HIWORD(*(_DWORD *)((char *)a3 + 14)) >> 6);
  return 1;
}


// address=[0x15cdd50]
// Decompiled from char __thiscall CSimpleNet::RemoveMsgFromResendList(CSimpleNet *this, unsigned __int16 a2)
bool  CSimpleNet::RemoveMsgFromResendList(unsigned short) {
  
  char v3; // [esp-Ch] [ebp-68h] BYREF
  int v4; // [esp-8h] [ebp-64h]
  int v5; // [esp-4h] [ebp-60h]
  _BYTE v6[12]; // [esp+4h] [ebp-58h] BYREF
  _BYTE v7[12]; // [esp+10h] [ebp-4Ch] BYREF
  _BYTE v8[12]; // [esp+1Ch] [ebp-40h] BYREF
  _BYTE v9[12]; // [esp+28h] [ebp-34h] BYREF
  int v10; // [esp+34h] [ebp-28h]
  int v11; // [esp+38h] [ebp-24h]
  char *v12; // [esp+3Ch] [ebp-20h]
  std::_Iterator_base12 *v13; // [esp+40h] [ebp-1Ch]
  std::_Iterator_base12 *v14; // [esp+44h] [ebp-18h]
  CSimpleNet *v15; // [esp+48h] [ebp-14h]
  char v16; // [esp+4Eh] [ebp-Eh]
  char v17; // [esp+4Fh] [ebp-Dh]
  int v18; // [esp+58h] [ebp-4h]

  v15 = this;
  if ( !std::list<SMessage>::size((char *)this + 184) )
    return 1;
  std::list<SMessage>::begin(v9);
  v18 = 0;
  while ( 1 )
  {
    v14 = (std::_Iterator_base12 *)std::list<SMessage>::end(v8);
    v13 = v14;
    LOBYTE(v18) = 1;
    v17 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::operator!=(v14);
    LOBYTE(v18) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>(v8);
    if ( !v17 )
      break;
    if ( ((*(_DWORD *)(std::_List_iterator<std::_List_val<std::_List_simple_types<SMessage>>>::operator->(v9) + 14) >> 2) & 0x3FF) == a2 )
    {
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
bool  CSimpleNet::LaunchWinsock(void) {
  
  _BYTE v3[4]; // [esp+10h] [ebp-194h] BYREF
  char v4[257]; // [esp+14h] [ebp-190h] BYREF
  char v5[139]; // [esp+115h] [ebp-8Fh] BYREF

  BBSupportTracePrintF(1, "SimpleNet: Requesting Winsock Version %d.%d!", 1, 1);
  switch ( dword_415B978(257, v3) )
  {
    case 10036:
      (*(void (__thiscall **)(CSimpleNet *, const char *, int))(*(_DWORD *)this + 88))(
        this,
        "Winsock general failure!",
        1);
      break;
    case 10067:
      (*(void (__thiscall **)(CSimpleNet *, const char *, int))(*(_DWORD *)this + 88))(
        this,
        "Winsock task limit reached. Please close other Applications and try again!",
        1);
      break;
    case 10091:
      (*(void (__thiscall **)(CSimpleNet *, const char *, int))(*(_DWORD *)this + 88))(this, "Winsock not ready!", 1);
      break;
    case 10092:
      (*(void (__thiscall **)(CSimpleNet *, const char *, int))(*(_DWORD *)this + 88))(
        this,
        "Requested Winsock Version not available!",
        1);
      break;
    default:
      break;
  }
  BBSupportTracePrintF(1, "SimpleNet: Got Winsock Version %d.%d", v3[1], v3[0]);
  BBSupportTracePrintF(1, "SimpleNet: Info: %s", v4);
  BBSupportTracePrintF(1, "SimpleNet: Info: %s", v5);
  return *((_BYTE *)this + 204) == 0;
}


// address=[0x15ce080]
// Decompiled from char __thiscall CSimpleNet::EnumerateLocalIP(CSimpleNet *this)
bool  CSimpleNet::EnumerateLocalIP(void) {
  
  return 1;
}


// address=[0x15ce3c0]
// Decompiled from bool __thiscall CSimpleNet::ConnectSocket(CSimpleNet *this)
bool  CSimpleNet::ConnectSocket(void) {
  
  _DWORD *v1; // eax
  int v2; // eax
  unsigned __int16 v3; // ax
  const char *v4; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  unsigned __int16 v9; // ax
  const char *v10; // eax
  int v11; // [esp-4h] [ebp-80h]
  int v12; // [esp-4h] [ebp-80h]
  int v13; // [esp-4h] [ebp-80h]
  _BYTE v14[12]; // [esp+4h] [ebp-78h] BYREF
  _BYTE v15[12]; // [esp+10h] [ebp-6Ch] BYREF
  _BYTE v16[12]; // [esp+1Ch] [ebp-60h] BYREF
  int v17; // [esp+28h] [ebp-54h] BYREF
  int v18; // [esp+2Ch] [ebp-50h] BYREF
  _DWORD v19[2]; // [esp+30h] [ebp-4Ch] BYREF
  int v20; // [esp+38h] [ebp-44h]
  std::_Iterator_base12 *v21; // [esp+3Ch] [ebp-40h]
  std::_Iterator_base12 *v22; // [esp+40h] [ebp-3Ch]
  _BYTE v23[12]; // [esp+44h] [ebp-38h] BYREF
  char v24; // [esp+57h] [ebp-25h]
  CSimpleNet *v25; // [esp+58h] [ebp-24h]
  _DWORD v26[4]; // [esp+5Ch] [ebp-20h] BYREF
  int v27; // [esp+78h] [ebp-4h]

  v25 = this;
  *((_DWORD *)this + 59) = 0;
  std::list<SLocalAddress>::begin(v23);
  v27 = 0;
  while ( 1 )
  {
    v22 = (std::_Iterator_base12 *)std::list<SLocalAddress>::end(v15);
    v21 = v22;
    LOBYTE(v27) = 1;
    v24 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::operator!=(v22);
    LOBYTE(v27) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>(v15);
    if ( !v24 )
      break;
    if ( *((int *)v25 + 59) >= 32
      && BBSupportDbgReport(2, "net\\SimpleNet.cpp", 614, "m_iNumberReceiverSockets < MAX_RECEIVER_SOCKETS") == 1 )
    {
      __debugbreak();
    }
    if ( *((_DWORD *)v25 + 59) == 32 )
    {
      v20 = std::list<SLocalAddress>::end(v14);
      v19[1] = v20;
      LOBYTE(v27) = 2;
      std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::operator=(v20);
      LOBYTE(v27) = 0;
      std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>(v14);
    }
    else if ( *(_BYTE *)(std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::operator*(v23)
                       + 160) )
    {
      *((_DWORD *)v25 + *((_DWORD *)v25 + 59) + 60) = dword_415B998(2, 2, 0);
      if ( *((_DWORD *)v25 + *((_DWORD *)v25 + 59) + 60) == -1 )
      {
        (*(void (__thiscall **)(CSimpleNet *, const char *, int))(*(_DWORD *)v25 + 88))(
          v25,
          "Unable to create socket!",
          1);
        BBSupportTracePrintF(3, "Unable to create socket!");
      }
      else
      {
        *((_WORD *)v25 + 186) = 2;
        *((_WORD *)v25 + 187) = dword_415B9AC(3105);
        v1 = (_DWORD *)std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::operator*(v23);
        *((_DWORD *)v25 + 94) = *v1;
        if ( dword_415B9A8(*((_DWORD *)v25 + *((_DWORD *)v25 + 59) + 60), (char *)v25 + 372, 16) == -1 )
        {
          v11 = dword_415B980();
          v2 = std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::operator*(v23);
          j__sprintf(
            (char *const)v25 + 432,
            "SimpleNet: ::bind() to %s failed: LastWSAError: %d!",
            (const char *)(v2 + 4),
            v11);
          (*(void (__thiscall **)(CSimpleNet *, int, int))(*(_DWORD *)v25 + 88))(v25, (int)v25 + 432, 1);
          BBSupportTracePrintF(3, (char *)v25 + 432);
        }
        else
        {
          v3 = dword_415B9AC(*((unsigned __int16 *)v25 + 187));
          v4 = (const char *)(*(int (__thiscall **)(CSimpleNet *, _DWORD, _DWORD))(*(_DWORD *)v25 + 48))(
                               v25,
                               *((_DWORD *)v25 + 94),
                               v3);
          BBSupportTracePrintF(1, "Simplenet.cpp: Receiver socket %d named %s:%d", *((_DWORD *)v25 + 59), v4, v12);
          ++*((_DWORD *)v25 + 59);
        }
      }
    }
    std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::operator++(v16, 0);
    std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>(v16);
  }
  v27 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SLocalAddress>>>(v23);
  if ( *((_DWORD *)v25 + 59) )
  {
    *((_DWORD *)v25 + 92) = dword_415B998(2, 2, 0);
    if ( *((_DWORD *)v25 + 92) == -1 )
    {
      (*(void (__thiscall **)(CSimpleNet *, const char *, int))(*(_DWORD *)v25 + 88))(
        v25,
        "Unable to create sender socket!",
        1);
      return 0;
    }
    else
    {
      v19[0] = 1;
      v18 = 1;
      if ( dword_415B9A4(*((_DWORD *)v25 + 92), 0xFFFF, 32, v19, 4) == -1 )
      {
        v6 = dword_415B980();
        BBSupportTracePrintF(3, "::setsocketopt(SO_BROADCAST) failed: LastWSAError: %d!", v6);
        (*(void (__thiscall **)(CSimpleNet *, const char *, int))(*(_DWORD *)v25 + 88))(v25, "SetSockOpt() failed", 1);
      }
      if ( dword_415B9A4(*((_DWORD *)v25 + 92), 0xFFFF, 4, &v18, 4) == -1 )
      {
        v7 = dword_415B980();
        BBSupportTracePrintF(3, "::setsocketopt(SO_REUSEADDR) failed: LastWSAError: %d!", v7);
        (*(void (__thiscall **)(CSimpleNet *, const char *, int))(*(_DWORD *)v25 + 88))(v25, "SetSockOpt() failed", 1);
      }
      *((_WORD *)v25 + 187) = dword_415B9AC(3105);
      *((_DWORD *)v25 + 94) = *((_DWORD *)v25 + 4);
      memset(v26, 0, sizeof(v26));
      v17 = 16;
      if ( dword_415B99C(*((_DWORD *)v25 + 92), v26, &v17) == -1 )
      {
        v8 = dword_415B980();
        BBSupportTracePrintF(3, "::getsocketname SenderSocket failed: LastWSAError: %d!", v8);
      }
      v9 = dword_415B9AC(HIWORD(v26[0]));
      v10 = (const char *)(*(int (__thiscall **)(CSimpleNet *, _DWORD, _DWORD))(*(_DWORD *)v25 + 48))(v25, v26[1], v9);
      BBSupportTracePrintF(1, "Simplenet.cpp: Sendersocket named %s:%d", v10, v13);
      return *((_BYTE *)v25 + 204) == 0;
    }
  }
  else
  {
    (*(void (__thiscall **)(CSimpleNet *, const char *, int))(*(_DWORD *)v25 + 88))(
      v25,
      "No Receiver socket could be bound! Aborting!",
      1);
    return 0;
  }
}


// address=[0x15d1220]
// Decompiled from void __thiscall CSimpleNet::ClearErrorString(CSimpleNet *this)
void  CSimpleNet::ClearErrorString(void) {
  
  void *v1; // [esp+0h] [ebp-28h]
  _BYTE v3[28]; // [esp+8h] [ebp-20h] BYREF

  v1 = std::string::string(v3, (char *)&off_366DCF4);
  std::string::operator=((char *)this + 208, v1);
  std::string::~string(v3);
  *((_BYTE *)this + 204) = 0;
}


// address=[0x15d14b0]
// Decompiled from char __thiscall CSimpleNet::SetErrorString(_BYTE *this, char *Str, char a3)
void  CSimpleNet::SetErrorString(char const *,bool) {
  
  char result; // al
  void *v4; // [esp+0h] [ebp-28h]
  _BYTE v6[28]; // [esp+8h] [ebp-20h] BYREF

  v4 = std::string::string(v6, Str);
  std::string::operator=(this + 208, v4);
  std::string::~string(v6);
  result = a3;
  this[204] = a3;
  return result;
}


