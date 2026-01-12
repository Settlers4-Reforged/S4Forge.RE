#include "CVCRecorder.h"

// Definitions for class CVCRecorder

// address=[0x2fd71f0]
// Decompiled from CVCRecorder *__thiscall CVCRecorder::CVCRecorder(CVCRecorder *this)

 CVCRecorder::CVCRecorder(void) {
  
  *(_DWORD *)this = &CVCRecorder::_vftable_;
  *((_BYTE *)this + 96) = 0;
  *((_BYTE *)this + 98) = 0;
  *((_BYTE *)this + 97) = 1;
  *((_BYTE *)this + 99) = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 2) = -1;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  return this;
}


// address=[0x2fd72b0]
// Decompiled from void __thiscall CVCRecorder::~CVCRecorder(void **this)

 CVCRecorder::~CVCRecorder(void) {
  
  int i; // [esp+10h] [ebp-14h]

  *this = &CVCRecorder::_vftable_;
  CVCRecorder::Shutdown((CVCRecorder *)this);
  if ( this[1] )
  {
    for ( i = 0; i < (int)this[9]; ++i )
    {
      if ( *((_DWORD *)this[1] + i) )
      {
        operator delete[](*((void **)this[1] + i));
        *((_DWORD *)this[1] + i) = 0;
      }
    }
    operator delete[](this[1]);
    this[1] = 0;
  }
}


// address=[0x2fd7380]
// Decompiled from char __thiscall CVCRecorder::Start(CVCRecorder *this, int a2, char *a3, int a4, struct _DIG_DRIVER *a5)

bool  CVCRecorder::Start(int,char *,int,struct _DIG_DRIVER *) {
  
  int i; // [esp+8h] [ebp-8h]

  *((_DWORD *)this + 9) = a2;
  *((_DWORD *)this + 13) = a5;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 2) = -1;
  if ( !CVCRecorder::InitEncoder(this, a3) )
    return 0;
  *((_DWORD *)this + 4) = 4 * *((_DWORD *)this + 8);
  *((_DWORD *)this + 1) = operator new[](4 * *((_DWORD *)this + 9));
  for ( i = 0; i < *((_DWORD *)this + 9); ++i )
    *(_DWORD *)(*((_DWORD *)this + 1) + 4 * i) = operator new[](*((_DWORD *)this + 4));
  if ( !CVCRecorder::InitInputDriver(this, a4) )
    return 0;
  BBSupportTracePrintF(0, (char *)&dword_3AD5B84[1], a4, *((_DWORD *)this + 7), *((unsigned __int8 *)this + 97));
  return 1;
}


// address=[0x2fd7490]
// Decompiled from int __stdcall CVCRecorder::EncodeDataCB(int a1, void *a2, size_t a3, int a4)

static long __stdcall CVCRecorder::EncodeDataCB(unsigned long,void *,long,long) {
  
  return CVCRecorder::CopyDataToEncoder(a2, a3, a4);
}


// address=[0x2fd74c0]
// Decompiled from int __stdcall CVCRecorder::RecordInputCB(void *Src, size_t Size, int a3)

static void __stdcall CVCRecorder::RecordInputCB(void const *,long,unsigned long) {
  
  return CVCRecorder::RecordInput(Src, Size);
}


// address=[0x2fd74e0]
// Decompiled from int __thiscall CVCRecorder::CopyDataToEncoder(int this, void *a2, int a3, int a4)

long  CVCRecorder::CopyDataToEncoder(void *,long,long) {
  
  size_t v5; // [esp+4h] [ebp-Ch]

  if ( *(_DWORD *)(this + 8) == *(_DWORD *)(this + 12) || *(_DWORD *)(this + 8) == -1 )
  {
    if ( *(_BYTE *)(this + 98) )
    {
      return 0;
    }
    else
    {
      j__memset(a2, 0, a3);
      return a3;
    }
  }
  else
  {
    if ( a3 >= *(_DWORD *)(this + 16) - *(_DWORD *)(this + 20) )
      v5 = *(_DWORD *)(this + 16) - *(_DWORD *)(this + 20);
    else
      v5 = a3;
    j__memcpy(
      a2,
      (const void *)(*(_DWORD *)(this + 20) + *(_DWORD *)(*(_DWORD *)(this + 4) + 4 * *(_DWORD *)(this + 8))),
      v5);
    *(_DWORD *)(this + 20) += v5;
    if ( *(_DWORD *)(this + 20) != *(_DWORD *)(this + 16) )
      return v5;
    if ( *(_DWORD *)(this + 8) == *(_DWORD *)(this + 36) - 1 )
      *(_DWORD *)(this + 8) = 0;
    else
      ++*(_DWORD *)(this + 8);
    *(_DWORD *)(this + 20) = 0;
    return v5;
  }
}


// address=[0x2fd75f0]
// Decompiled from int __thiscall CVCRecorder::GetEncodedData(CVCRecorder *this, signed __int8 *a2, int a3)

int  CVCRecorder::GetEncodedData(signed char *,int) {
  
  if ( !*((_DWORD *)this + 20) && BBSupportDbgReport(2, "VCRecorder.cpp", 425, "m_hTransmitStream") == 1 )
    __debugbreak();
  if ( *((_DWORD *)this + 2) == *((_DWORD *)this + 3) || *((_DWORD *)this + 2) == -1 )
    return 0;
  else
    return (*((int (__stdcall **)(_DWORD, signed __int8 *, int))this + 23))(*((_DWORD *)this + 20), a2, a3);
}


// address=[0x2fd7660]
// Decompiled from CVCRecorder *__thiscall CVCRecorder::Shutdown(CVCRecorder *this)

void  CVCRecorder::Shutdown(void) {
  
  CVCRecorder *result; // eax

  result = this;
  *((_BYTE *)this + 98) = 0;
  if ( *((_DWORD *)this + 20) )
  {
    (*((void (__stdcall **)(_DWORD))this + 22))(*((_DWORD *)this + 20));
    result = this;
    *((_DWORD *)this + 20) = 0;
  }
  if ( !*((_DWORD *)this + 12) )
    return result;
  AIL_set_input_state(*((_DWORD *)this + 12), 0);
  AIL_close_input(*((_DWORD *)this + 12));
  result = this;
  *((_DWORD *)this + 12) = 0;
  return result;
}


// address=[0x2fd76d0]
// Decompiled from // MFC 3.1-14.0 32bit
int __thiscall CVCRecorder::GetFrameSize(CVCRecorder *this)

int  CVCRecorder::GetFrameSize(void) {
  
  return *((_DWORD *)this + 8);
}


// address=[0x2fd76f0]
// Decompiled from CVCRecorder *__thiscall CVCRecorder::ToggleRecording(CVCRecorder *this, bool a2)

void  CVCRecorder::ToggleRecording(bool) {
  
  CVCRecorder *result; // eax

  result = this;
  if ( *((_BYTE *)this + 98) == a2 )
    return result;
  result = this;
  if ( *((_BYTE *)this + 97) )
  {
    if ( *((_DWORD *)this + 12) )
    {
      if ( a2 )
      {
        if ( !AIL_set_input_state(*((_DWORD *)this + 12), 1) )
        {
          AIL_close_input(*((_DWORD *)this + 12));
          *((_DWORD *)this + 12) = AIL_open_input((char *)this + 56);
          if ( !*((_DWORD *)this + 12) )
            BBSupportTracePrintF(0, "VoiceChat : VCRecorder::ToggleRecording : Failed to re-open input driver");
          if ( !AIL_set_input_state(*((_DWORD *)this + 12), 1) )
            BBSupportTracePrintF(0, "VoiceChat : VCRecorder::ToggleRecording : Failed to start recording");
        }
        *((_BYTE *)this + 98) = 1;
        return (CVCRecorder *)BBSupportTracePrintF(0, "VoiceChat : VCRecorder::ToggleRecording : Recording started");
      }
      else
      {
        *((_BYTE *)this + 98) = 0;
      }
    }
  }
  else if ( a2 )
  {
    *((_BYTE *)this + 98) = 1;
    AIL_digital_handle_release(*((_DWORD *)this + 13));
    *((_DWORD *)this + 12) = AIL_open_input((char *)this + 56);
    result = (CVCRecorder *)AIL_set_input_state(*((_DWORD *)this + 12), 1);
    if ( !result )
      return (CVCRecorder *)BBSupportTracePrintF(
                              0,
                              "VoiceChat : VCRecorder::ToggleRecording : Failed to start recording ( half duplex )");
  }
  else
  {
    result = this;
    if ( *((_DWORD *)this + 12) )
    {
      *((_BYTE *)this + 98) = 0;
      AIL_set_input_state(*((_DWORD *)this + 12), 0);
      AIL_close_input(*((_DWORD *)this + 12));
      *((_DWORD *)this + 12) = 0;
      return (CVCRecorder *)AIL_digital_handle_reacquire(*((_DWORD *)this + 13));
    }
  }
  return result;
}


// address=[0x2fd7870]
// Decompiled from char __thiscall CVCRecorder::IsRecording(CVCRecorder *this)

bool  CVCRecorder::IsRecording(void) {
  
  return *((_BYTE *)this + 98);
}


// address=[0x2fd7890]
// Decompiled from char __thiscall CVCRecorder::UsesFullDuplex(CVCRecorder *this)

bool  CVCRecorder::UsesFullDuplex(void) {
  
  return *((_BYTE *)this + 97);
}


// address=[0x2fd78b0]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
int __thiscall CVCRecorder::GetInputRate(CVCRecorder *this)

int  CVCRecorder::GetInputRate(void) {
  
  return *((_DWORD *)this + 7);
}


// address=[0x2fd78d0]
// Decompiled from int __thiscall CVCRecorder::CalcNoiseVol(CVCRecorder *this)

void  CVCRecorder::CalcNoiseVol(void) {
  
  int result; // eax

  *((_DWORD *)this + 26) = 40;
  while ( *((_DWORD *)this + 26) )
    Sleep(5u);
  result = *((_DWORD *)this + 25) / 40;
  *((_DWORD *)this + 25) = result;
  return result;
}


// address=[0x2fd7910]
// Decompiled from CVCRecorder *__thiscall CVCRecorder::SetOperationMode(CVCRecorder *this, bool a2)

void  CVCRecorder::SetOperationMode(bool) {
  
  CVCRecorder *result; // eax

  result = this;
  *((_BYTE *)this + 99) = a2;
  return result;
}


// address=[0x2fd6990]
// Decompiled from char __thiscall CVCRecorder::InitEncoder(CVCRecorder *this, char *a2)

bool  CVCRecorder::InitEncoder(char *) {
  
  int v3; // eax
  int v4; // eax
  _DWORD v5[8]; // [esp+0h] [ebp-60h] BYREF
  int (__stdcall *v6)(int); // [esp+20h] [ebp-40h] BYREF
  int v7; // [esp+24h] [ebp-3Ch] BYREF
  CVCRecorder *v8; // [esp+28h] [ebp-38h]
  _DWORD v9[12]; // [esp+2Ch] [ebp-34h] BYREF

  v8 = this;
  *((_DWORD *)this + 11) = RIB_find_file_provider("ASI codec", "Output file types", a2);
  if ( *((_DWORD *)v8 + 11) )
  {
    v9[0] = 0;
    v9[1] = "ASI_stream_open";
    v9[2] = (char *)v8 + 84;
    v9[3] = 0;
    v9[4] = 0;
    v9[5] = "ASI_stream_close";
    v9[6] = (char *)v8 + 88;
    v9[7] = 0;
    v9[8] = 0;
    v9[9] = "ASI_stream_process";
    v9[10] = (char *)v8 + 92;
    v9[11] = 0;
    if ( RIB_request_interface(*((_DWORD *)v8 + 11), "ASI stream", 3, v9) )
    {
      BBSupportTracePrintF(0, "VoiceChat : CVCRecorder::InitEncoder : Failed getting first RIB_INTERFACE");
      return 0;
    }
    else
    {
      v5[0] = 0;
      v5[1] = "PROVIDER_query_attribute";
      v5[2] = &v6;
      v5[3] = 0;
      v5[4] = 1;
      v5[5] = "Maximum frame size";
      v5[6] = &v7;
      v5[7] = 0;
      if ( RIB_request_interface(*((_DWORD *)v8 + 11), "ASI codec", 2, v5) )
      {
        BBSupportTracePrintF(0, "VoiceChat : CVCRecorder::InitEncoder : Failed getting second RIB_INTERFACE");
        return 0;
      }
      else
      {
        v3 = v6(v7);
        *((_DWORD *)v8 + 8) = v3;
        v4 = (*((int (__stdcall **)(CVCRecorder *, int (__stdcall *)(int, void *, size_t, int), _DWORD))v8 + 21))(
               v8,
               CVCRecorder::EncodeDataCB,
               0);
        *((_DWORD *)v8 + 20) = v4;
        if ( *((_DWORD *)v8 + 20) )
        {
          return 1;
        }
        else
        {
          BBSupportTracePrintF(0, "VoiceChat : CVCRecorder::InitEncoder : Failed getting first RIB_INTERFACE");
          return 0;
        }
      }
    }
  }
  else
  {
    BBSupportTracePrintF(0, "VoiceChat : CVCRecorder::InitEncoder : Couldn't load ASI provider for %s.", a2);
    return 0;
  }
}


// address=[0x2fd6b30]
// Decompiled from char __thiscall CVCRecorder::RecordInput(int this, __int16 *Src, int Size)

void  CVCRecorder::RecordInput(void const *,long) {
  
  int v3; // eax
  void *v5; // [esp+0h] [ebp-18h]
  __int16 *v6; // [esp+4h] [ebp-14h]
  int i; // [esp+8h] [ebp-10h]
  int v8; // [esp+Ch] [ebp-Ch]
  char v10; // [esp+17h] [ebp-1h]

  v10 = 0;
  if ( !*(_BYTE *)(this + 98) )
  {
    AIL_set_input_state(*(_DWORD *)(this + 48), 0);
    BBSupportTracePrintF(0, "VoiceChat : VCRecorder::RecordInput : Recording ended");
    v10 = 1;
  }
  if ( !*(_BYTE *)(this + 99) )
    goto LABEL_13;
  v8 = 0;
  if ( !v10 )
  {
    v6 = Src;
    for ( i = 0; i < Size / 2; ++i )
      v8 += j__abs(*v6++);
    v8 /= Size;
    if ( *(_DWORD *)(this + 104) )
    {
      *(_DWORD *)(this + 100) += v8;
      --*(_DWORD *)(this + 104);
    }
  }
  if ( v8 < *(_DWORD *)(this + 100) )
  {
    LOBYTE(v3) = this;
    if ( !*(_DWORD *)(this + 20) )
      return v3;
  }
LABEL_13:
  if ( !*(_BYTE *)(this + 96) || v10 )
  {
    v5 = *(void **)(*(_DWORD *)(this + 4) + 4 * *(_DWORD *)(this + 12));
    if ( Size < *(_DWORD *)(this + 16) )
      j__memset(v5, 0, *(_DWORD *)(this + 16));
    if ( v10 )
      j__memset(v5, 0, Size);
    else
      j__memcpy(v5, Src, Size);
    LOBYTE(v3) = this;
    if ( *(_DWORD *)(this + 12) == *(_DWORD *)(this + 36) - 1 )
    {
      *(_DWORD *)(this + 12) = 0;
    }
    else
    {
      v3 = *(_DWORD *)(this + 12) + 1;
      *(_DWORD *)(this + 12) = v3;
    }
    if ( *(_DWORD *)(this + 8) == -1 )
    {
      LOBYTE(v3) = this;
      *(_DWORD *)(this + 8) = 0;
      *(_DWORD *)(this + 20) = 0;
    }
  }
  else
  {
    LOBYTE(v3) = CVCRecorder::Downsample((CVCRecorder *)this, Src, Size);
  }
  return v3;
}


// address=[0x2fd6cf0]
// Decompiled from char __thiscall CVCRecorder::Downsample(CVCRecorder *this, const void *a2, int a3)

bool  CVCRecorder::Downsample(void const *,int) {
  
  int v4; // [esp+4h] [ebp-88h]
  int v5; // [esp+8h] [ebp-84h]
  _DWORD v7[2]; // [esp+10h] [ebp-7Ch] BYREF
  int v8; // [esp+18h] [ebp-74h]
  int v9; // [esp+1Ch] [ebp-70h]
  int v10; // [esp+20h] [ebp-6Ch]
  int v11; // [esp+24h] [ebp-68h]
  const void *v12; // [esp+30h] [ebp-5Ch]

  v9 = *((_DWORD *)this + 7);
  v10 = 16;
  v11 = 1;
  v7[0] = 1;
  v7[1] = a2;
  v12 = a2;
  v8 = a3;
  v5 = *((_DWORD *)this + 6) + *(_DWORD *)(*((_DWORD *)this + 1) + 4 * *((_DWORD *)this + 3));
  while ( v8 )
  {
    v4 = AIL_process_digital_audio(v5, *((_DWORD *)this + 4) - *((_DWORD *)this + 6), 8000, 1, 1, v7);
    if ( !v4 )
      return 0;
    *((_DWORD *)this + 6) += v4;
    if ( *((_DWORD *)this + 6) == *((_DWORD *)this + 4) )
    {
      *((_DWORD *)this + 6) = 0;
      if ( *((_DWORD *)this + 3) == *((_DWORD *)this + 9) - 1 )
        *((_DWORD *)this + 3) = 0;
      else
        ++*((_DWORD *)this + 3);
      if ( *((_DWORD *)this + 2) == -1 )
      {
        *((_DWORD *)this + 2) = 0;
        *((_DWORD *)this + 5) = 0;
      }
      v5 = *(_DWORD *)(*((_DWORD *)this + 1) + 4 * *((_DWORD *)this + 3));
    }
    else
    {
      v5 += v4;
    }
  }
  return 1;
}


// address=[0x2fd6e60]
// Decompiled from char __thiscall CVCRecorder::InitInputDriver(CVCRecorder *this, int a2)

bool  CVCRecorder::InitInputDriver(int) {
  
  const char *error; // eax

  *((_DWORD *)this + 14) = -1;
  *((_DWORD *)this + 15) = 1;
  *((_DWORD *)this + 17) = CVCRecorder::RecordInputCB;
  *((_DWORD *)this + 18) = *((_DWORD *)this + 4);
  *((_DWORD *)this + 19) = this;
  *((_DWORD *)this + 16) = 8000;
  *((_DWORD *)this + 12) = AIL_open_input((char *)this + 56);
  if ( *((_DWORD *)this + 12) )
  {
    *((_DWORD *)this + 7) = 8000;
    return 1;
  }
  else
  {
    BBSupportTracePrintF(
      0,
      "VoiceChat : VCRecorder::InitInputDriver : Couldn't start with 8000 kHz and full duplex. Retry output rate.");
    *((_DWORD *)this + 16) = a2;
    *((_DWORD *)this + 18) = CVCRecorder::CalcInputBufferSize(this, a2);
    *((_DWORD *)this + 12) = AIL_open_input((char *)this + 56);
    if ( *((_DWORD *)this + 12) )
    {
      *((_DWORD *)this + 7) = a2;
      if ( *((int *)this + 7) > 8000 )
        *((_BYTE *)this + 96) = 1;
      return 1;
    }
    else
    {
      BBSupportTracePrintF(
        0,
        "VoiceChat : VCRecorder::InitInputDriver : Couldn't start with output rate and full duplex. Retry half duplex and 8000 kHz.");
      *((_BYTE *)this + 97) = 0;
      AIL_digital_handle_release(*((_DWORD *)this + 13));
      *((_DWORD *)this + 16) = 8000;
      *((_DWORD *)this + 18) = *((_DWORD *)this + 4);
      *((_DWORD *)this + 12) = AIL_open_input((char *)this + 56);
      if ( *((_DWORD *)this + 12) )
      {
        *((_DWORD *)this + 7) = 8000;
        AIL_close_input(*((_DWORD *)this + 12));
        *((_DWORD *)this + 12) = 0;
        AIL_digital_handle_reacquire(*((_DWORD *)this + 13));
        return 1;
      }
      else
      {
        BBSupportTracePrintF(
          0,
          "VoiceChat : VCRecorder::InitInputDriver : Couldn't start with 8000 kHz and half duplex. Retry output rate.");
        *((_DWORD *)this + 16) = a2;
        *((_DWORD *)this + 18) = CVCRecorder::CalcInputBufferSize(this, a2);
        *((_DWORD *)this + 12) = AIL_open_input((char *)this + 56);
        if ( *((_DWORD *)this + 12) )
        {
          *((_DWORD *)this + 7) = a2;
          if ( *((int *)this + 7) > 8000 )
            *((_BYTE *)this + 96) = 0;
          AIL_close_input(*((_DWORD *)this + 12));
          *((_DWORD *)this + 12) = 0;
          AIL_digital_handle_reacquire(*((_DWORD *)this + 13));
          return 1;
        }
        else
        {
          error = (const char *)AIL_last_error();
          BBSupportTracePrintF(
            0,
            "VoiceChat : VCRecorder::InitInputDriver : Couldn't start with output rate and half duplex. Can't record. %s",
            error);
          AIL_digital_handle_reacquire(*((_DWORD *)this + 13));
          return 0;
        }
      }
    }
  }
}


// address=[0x2fd7090]
// Decompiled from size_t __thiscall CVCRecorder::CalcInputBufferSize(CVCRecorder *this, int a2)

int  CVCRecorder::CalcInputBufferSize(int) {
  
  void *v3; // [esp+10h] [ebp-8Ch]
  void *v4; // [esp+14h] [ebp-88h]
  size_t Size; // [esp+18h] [ebp-84h]
  size_t Sizea; // [esp+18h] [ebp-84h]
  int v8; // [esp+20h] [ebp-7Ch] BYREF
  void *v9; // [esp+24h] [ebp-78h]
  size_t v10; // [esp+28h] [ebp-74h]
  int v11; // [esp+2Ch] [ebp-70h]
  int v12; // [esp+30h] [ebp-6Ch]
  int v13; // [esp+34h] [ebp-68h]
  void *v14; // [esp+40h] [ebp-5Ch]

  v11 = 8000;
  v12 = 16;
  v13 = 1;
  v8 = 1;
  v9 = (void *)**((_DWORD **)this + 1);
  v14 = (void *)**((_DWORD **)this + 1);
  v10 = *((_DWORD *)this + 4);
  Size = AIL_size_processed_digital_audio(a2, 1, 1, &v8);
  v4 = operator new[](Size);
  v3 = operator new[](*((_DWORD *)this + 4));
  v11 = a2;
  v9 = v4;
  v14 = v4;
  v10 = Size;
  AIL_process_digital_audio(v3, *((_DWORD *)this + 4), 8000, 1, 1, &v8);
  Sizea = Size - v10;
  operator delete[](v4);
  operator delete[](v3);
  return Sizea;
}


