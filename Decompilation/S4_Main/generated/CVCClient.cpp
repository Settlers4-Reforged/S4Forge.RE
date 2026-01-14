#include "all_headers.h"

// Definitions for class CVCClient

// address=[0x2fd8220]
// Decompiled from CVCClient *__thiscall CVCClient::CVCClient(CVCClient *this)
 CVCClient::CVCClient(void) {
  
  *(_DWORD *)this = &CVCClient::_vftable_;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 24) = 2;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = -1;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 25) = 3;
  *((_DWORD *)this + 20) = -1;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 28) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 29) = 0;
  return this;
}


// address=[0x2fd8300]
// Decompiled from void __thiscall CVCClient::~CVCClient(void **this)
 CVCClient::~CVCClient(void) {
  
  int i; // [esp+20h] [ebp-14h]
  int j; // [esp+20h] [ebp-14h]
  int k; // [esp+20h] [ebp-14h]

  *this = &CVCClient::_vftable_;
  CVCClient::Shutdown((CVCClient *)this);
  if ( this[26] )
  {
    for ( i = 0; i < (int)this[25]; ++i )
    {
      if ( *((_DWORD *)this[26] + i) )
      {
        operator delete[](*((void **)this[26] + i));
        *((_DWORD *)this[26] + i) = 0;
      }
    }
    operator delete[](this[26]);
    this[26] = 0;
  }
  if ( this[16] )
  {
    operator delete[](this[16]);
    this[16] = 0;
  }
  if ( this[17] )
  {
    for ( j = 0; j < (int)this[24]; ++j )
    {
      if ( *((_DWORD *)this[17] + j) )
      {
        operator delete[](*((void **)this[17] + j));
        *((_DWORD *)this[17] + j) = 0;
      }
    }
    operator delete[](this[17]);
    this[17] = 0;
  }
  if ( this[15] )
  {
    operator delete[](this[15]);
    this[15] = 0;
  }
  if ( this[11] )
  {
    ((void (__stdcall *)(void *))this[4])(this[11]);
    this[11] = 0;
  }
  if ( this[28] )
  {
    AIL_release_sample_handle(this[28]);
    this[28] = 0;
  }
  for ( k = 0; k < 2; ++k )
  {
    if ( this[k + 12] )
    {
      operator delete[](this[k + 12]);
      this[k + 12] = 0;
    }
  }
}


// address=[0x2fd8530]
// Decompiled from char __thiscall CVCClient::Start(CVCClient *this, char a2, struct _DIG_DRIVER *a3, int a4, char *a5)
bool  CVCClient::Start(int,struct _DIG_DRIVER *,int,char *) {
  
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = -1;
  *((_DWORD *)this + 20) = -1;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 23) = a4;
  *((_DWORD *)this + 28) = AIL_allocate_sample_handle(a3);
  if ( !*((_DWORD *)this + 28) )
    return 0;
  AIL_init_sample(*((_DWORD *)this + 28));
  AIL_set_sample_playback_rate(*((_DWORD *)this + 28), 8000);
  AIL_set_sample_type(*((_DWORD *)this + 28), 1, 0);
  AIL_set_sample_volume(*((_DWORD *)this + 28), 100);
  *((_DWORD *)this + 14) = 2 * AIL_minimum_sample_buffer_size(a3, 8000, 1);
  *((_DWORD *)this + 12) = operator new[](*((_DWORD *)this + 14));
  *((_DWORD *)this + 13) = operator new[](*((_DWORD *)this + 14));
  CVCClient::InitDecoder(this, a2, a5);
  return 1;
}


// address=[0x2fd8650]
// Decompiled from CVCClient *__thiscall CVCClient::Shutdown(CVCClient *this)
void  CVCClient::Shutdown(void) {
  
  CVCClient *result; // eax

  result = this;
  if ( !*((_DWORD *)this + 11) )
    return result;
  result = (CVCClient *)(*((int (__stdcall **)(_DWORD))this + 4))(*((_DWORD *)this + 11));
  *((_DWORD *)this + 11) = 0;
  return result;
}


// address=[0x2fd8680]
// Decompiled from char __thiscall CVCClient::ReceivePackage(_DWORD *this, void *Src)
bool  CVCClient::ReceivePackage(signed char *) {
  
  if ( *(_BYTE *)(this[15] + this[21]) )
    return 1;
  j__memcpy(*(void **)(this[17] + 4 * this[21]), Src, this[23]);
  *(_BYTE *)(this[15] + this[21]) = 1;
  if ( this[20] == -1 )
    this[20] = 0;
  if ( this[21] == this[24] - 1 )
    this[21] = 0;
  else
    ++this[21];
  return 1;
}


// address=[0x2fd8720]
// Decompiled from CVCClient *__fastcall CVCClient::PlayStream(size_t *this)
void  CVCClient::PlayStream(void) {
  
  CVCClient *result; // eax
  CVCClient *v2; // [esp+0h] [ebp-8h]

  result = (CVCClient *)this;
  if ( (this[19] & 0x80000000) != 0 )
    return result;
  result = (CVCClient *)AIL_sample_buffer_ready(this[28]);
  v2 = result;
  if ( result == (CVCClient *)-1 )
    return result;
  if ( *(_BYTE *)(this[16] + this[19]) )
  {
    j__memcpy((void *)this[(_DWORD)result + 12], *(const void **)(this[26] + 4 * this[19]), this[14]);
    *(_BYTE *)(this[16] + this[19]) = 0;
    if ( this[19] == this[25] - 1 )
      this[19] = 0;
    else
      ++this[19];
  }
  else
  {
    memset((void *)this[(_DWORD)result + 12], 0, this[14]);
  }
  return (CVCClient *)AIL_load_sample_buffer(this[28], v2, this[(_DWORD)v2 + 12], this[14]);
}


// address=[0x2fd8820]
// Decompiled from int __stdcall CVCClient::DecodeDataCB(int a1, void *a2, int a3, int a4)
static long __stdcall CVCClient::DecodeDataCB(unsigned long,void *,long,long) {
  
  return CVCClient::CopyDataToDecoder(a2, a3, a4);
}


// address=[0x2fd8850]
// Decompiled from size_t __thiscall CVCClient::CopyDataToDecoder(_DWORD *this, char *a2, int a3, int a4)
long  CVCClient::CopyDataToDecoder(void *,long,long) {
  
  size_t v5; // [esp+0h] [ebp-Ch]
  size_t Size; // [esp+4h] [ebp-8h]
  int v8; // [esp+18h] [ebp+Ch]

  if ( !*(_BYTE *)(this[15] + this[20]) )
    return 0;
  if ( a3 >= this[23] - this[22] )
    v5 = this[23] - this[22];
  else
    v5 = a3;
  Size = v5;
  j__memcpy(a2, (const void *)(this[22] + *(_DWORD *)(this[17] + 4 * this[20])), v5);
  this[22] += v5;
  if ( this[22] == this[23] )
  {
    this[22] = 0;
    *(_BYTE *)(this[15] + this[20]) = 0;
    if ( this[20] == this[24] - 1 )
      this[20] = 0;
    else
      ++this[20];
  }
  v8 = a3 - v5;
  if ( v8 )
    return v5 + CVCClient::CopyDataToDecoder(&a2[v5], v8, a4);
  return Size;
}


// address=[0x2fd8970]
// Decompiled from CVCClient *__thiscall CVCClient::Run(CVCClient *this)
void  CVCClient::Run(void) {
  
  CVCClient::DecodeData(this);
  return CVCClient::PlayStream((size_t *)this);
}


// address=[0x2fd8990]
// Decompiled from int __thiscall CVCClient::SetVolume(CVCClient *this, int a2)
void  CVCClient::SetVolume(int) {
  
  return AIL_set_sample_volume(*((_DWORD *)this + 28), a2);
}


// address=[0x2fd7d50]
// Decompiled from CVCClient *__thiscall CVCClient::DecodeData(CVCClient *this)
void  CVCClient::DecodeData(void) {
  
  CVCClient *result; // eax

  result = (CVCClient *)*((_DWORD *)this + 16);
  if ( *((_BYTE *)result + *((_DWORD *)this + 18)) || *((_DWORD *)this + 20) == -1 )
    return result;
  result = (CVCClient *)*((_DWORD *)this + 15);
  if ( !*((_BYTE *)result + *((_DWORD *)this + 20)) )
    return result;
  *((_DWORD *)this + 29) += (*((int (__stdcall **)(_DWORD, int, int))this + 2))(
                              *((_DWORD *)this + 11),
                              *((_DWORD *)this + 29) + *(_DWORD *)(*((_DWORD *)this + 26) + 4 * *((_DWORD *)this + 18)),
                              *((_DWORD *)this + 14) - *((_DWORD *)this + 29));
  result = this;
  if ( *((_DWORD *)this + 29) != *((_DWORD *)this + 14) )
    return result;
  *((_DWORD *)this + 29) = 0;
  *(_BYTE *)(*((_DWORD *)this + 16) + *((_DWORD *)this + 18)) = 1;
  if ( *((int *)this + 19) < 0 )
    *((_DWORD *)this + 19) = 0;
  result = this;
  if ( *((_DWORD *)this + 18) == *((_DWORD *)this + 25) - 1 )
  {
    *((_DWORD *)this + 18) = 0;
  }
  else
  {
    result = (CVCClient *)(*((_DWORD *)this + 18) + 1);
    *((_DWORD *)this + 18) = result;
  }
  return result;
}


// address=[0x2fd7e40]
// Decompiled from char __thiscall CVCClient::InitDecoder(CVCClient *this, char a2, char *a3)
bool  CVCClient::InitDecoder(int,char *) {
  
  int i; // [esp+18h] [ebp-ACh]
  int j; // [esp+18h] [ebp-ACh]
  _DWORD v7[40]; // [esp+20h] [ebp-A4h] BYREF

  *((_DWORD *)this + 27) = RIB_find_file_provider("ASI codec", "Input file types", a3);
  if ( !*((_DWORD *)this + 27) )
    return 0;
  v7[0] = 0;
  v7[1] = "ASI_stream_attribute";
  v7[2] = (char *)this + 20;
  v7[3] = 0;
  v7[4] = 0;
  v7[5] = "ASI_stream_open";
  v7[6] = (char *)this + 4;
  v7[7] = 0;
  v7[8] = 0;
  v7[9] = "ASI_stream_seek";
  v7[10] = (char *)this + 12;
  v7[11] = 0;
  v7[12] = 0;
  v7[13] = "ASI_stream_close";
  v7[14] = (char *)this + 16;
  v7[15] = 0;
  v7[16] = 0;
  v7[17] = "ASI_stream_process";
  v7[18] = (char *)this + 8;
  v7[19] = 0;
  v7[20] = 0;
  v7[21] = "ASI_stream_set_preference";
  v7[22] = (char *)this + 24;
  v7[23] = 0;
  v7[24] = 1;
  v7[25] = "Output sample rate";
  v7[26] = (char *)this + 28;
  v7[27] = 0;
  v7[28] = 1;
  v7[29] = "Output sample width";
  v7[30] = (char *)this + 32;
  v7[31] = 0;
  v7[32] = 1;
  v7[33] = "Output channels";
  v7[34] = (char *)this + 36;
  v7[35] = 0;
  v7[36] = 2;
  v7[37] = "Requested sample rate";
  v7[38] = (char *)this + 40;
  v7[39] = 0;
  RIB_request_interface(*((_DWORD *)this + 27), "ASI stream", 10, v7);
  *((_DWORD *)this + 11) = (*((int (__stdcall **)(CVCClient *, int (__stdcall *)(int, void *, int, int), _DWORD))this + 1))(
                             this,
                             CVCClient::DecodeDataCB,
                             0);
  if ( !*((_DWORD *)this + 11) )
    return 0;
  (*((void (__stdcall **)(_DWORD, _DWORD, char *))this + 6))(*((_DWORD *)this + 11), *((_DWORD *)this + 10), &a2);
  *((_DWORD *)this + 17) = operator new[](4 * *((_DWORD *)this + 24));
  *((_DWORD *)this + 15) = operator new[](*((_DWORD *)this + 24));
  for ( i = 0; i < *((_DWORD *)this + 24); ++i )
  {
    *(_DWORD *)(*((_DWORD *)this + 17) + 4 * i) = operator new[](*((_DWORD *)this + 23));
    *(_BYTE *)(*((_DWORD *)this + 15) + i) = 0;
  }
  *((_DWORD *)this + 26) = operator new[](4 * *((_DWORD *)this + 25));
  *((_DWORD *)this + 16) = operator new[](*((_DWORD *)this + 25));
  for ( j = 0; j < *((_DWORD *)this + 25); ++j )
  {
    *(_DWORD *)(*((_DWORD *)this + 26) + 4 * j) = operator new[](*((_DWORD *)this + 14));
    *(_BYTE *)(*((_DWORD *)this + 16) + j) = 0;
  }
  return 1;
}


