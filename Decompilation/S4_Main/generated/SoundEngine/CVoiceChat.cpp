#include "CVoiceChat.h"

// Definitions for class CVoiceChat

// address=[0x2fd4650]
// Decompiled from CVoiceChat *__thiscall CVoiceChat::CVoiceChat(CVoiceChat *this, int a2, int a3, struct IEventEngine *a4)
 CVoiceChat::CVoiceChat(int a2, int a3, class IEventEngine * a4) {
  
  int i; // [esp+8h] [ebp-14h]

  CVCRecorder::CVCRecorder((CVoiceChat *)((char *)this + 24));
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 2) = a2 + 1;
  *((_DWORD *)this + 1) = 0;
  *((_BYTE *)this + 20) = 1;
  *((_BYTE *)this + 136) = 0;
  g_pEvnEngine = a4;
  CVC_EventHandle::RegisterVC((CVC_EventHandle *)&g_cVC_EventHandle, this);
  *((_DWORD *)this + 38) = a3;
  *((_DWORD *)this + 3) = operator new[](4 * *((_DWORD *)this + 2));
  for ( i = 0; i < *((_DWORD *)this + 2); ++i )
    *(_DWORD *)(*((_DWORD *)this + 3) + 4 * i) = 0;
  *((_DWORD *)this + 36) = 0;
  *((_DWORD *)this + 35) = 0;
  *((_DWORD *)this + 39) = 100;
  *((_DWORD *)this + 40) = 0;
  *((_DWORD *)this + 41) = 0;
  return this;
}


// address=[0x2fd47a0]
// Decompiled from void __thiscall CVoiceChat::~CVoiceChat(void **this)
 CVoiceChat::~CVoiceChat(void) {
  
  void (__thiscall ***v1)(_DWORD, int); // [esp+18h] [ebp-18h]
  int i; // [esp+1Ch] [ebp-14h]

  if ( CVCRecorder::IsRecording((CVCRecorder *)(this + 6)) )
    CVoiceChat::ToggleRecording((CVoiceChat *)this, 0);
  CVC_EventHandle::UnregisterVC((CVC_EventHandle *)&g_cVC_EventHandle);
  if ( (int)this[40] >= 0 )
    CVoiceChat::SetWindowsMicVolume((CVoiceChat *)this, this[40]);
  if ( this[3] )
  {
    for ( i = 0; i < (int)this[2]; ++i )
    {
      if ( *((_DWORD *)this[3] + i) )
      {
        v1 = (void (__thiscall ***)(_DWORD, int))*((_DWORD *)this[3] + i);
        if ( v1 )
          (**v1)(v1, 1);
        *((_DWORD *)this[3] + i) = 0;
      }
    }
    operator delete[](this[3]);
    this[3] = 0;
  }
  if ( this[4] )
  {
    operator delete[](this[4]);
    this[4] = 0;
  }
  if ( this[35] )
  {
    operator delete[](this[35]);
    this[35] = 0;
  }
  CVCRecorder::~CVCRecorder((CVCRecorder *)(this + 6));
}


// address=[0x2fd4920]
// Decompiled from char __thiscall CVoiceChat::Init(int *this, int a2, int a3, char *Str)
bool  CVoiceChat::Init(int a2, unsigned int a3, char * Str) {
  
  size_t v4; // eax
  int InputRate; // eax
  struct _DIG_DRIVER *v7; // [esp-Ch] [ebp-38h]
  int v8; // [esp-8h] [ebp-34h]
  char *v9; // [esp-4h] [ebp-30h]
  CVCClient *v10; // [esp+10h] [ebp-1Ch]
  CVCClient *C; // [esp+14h] [ebp-18h]
  int i; // [esp+18h] [ebp-14h]

  *this = a2;
  this[1] = a3;
  v4 = j__strlen(Str);
  this[4] = (int)operator new[](v4 + 1);
  j__strcpy_0((char *)this[4], Str);
  if ( !CVoiceChat::GetWindowsMicVolume((CVoiceChat *)this, this + 40) )
    this[40] = -1;
  if ( CVCRecorder::Start((CVCRecorder *)(this + 6), 4, (char *)this[4], *this, (struct _DIG_DRIVER *)this[1]) )
  {
    this[33] = CVCRecorder::GetFrameSize((CVCRecorder *)(this + 6));
    this[35] = (int)operator new[](this[33]);
    for ( i = 0; i < this[2]; ++i )
    {
      C = (CVCClient *)operator new(0x78u);
      if ( C )
        v10 = CVCClient::CVCClient(C);
      else
        v10 = 0;
      *(_DWORD *)(this[3] + 4 * i) = v10;
      v9 = (char *)this[4];
      v8 = this[33];
      v7 = (struct _DIG_DRIVER *)this[1];
      InputRate = CVCRecorder::GetInputRate((CVCRecorder *)(this + 6));
      CVCClient::Start(*(CVCClient **)(this[3] + 4 * i), InputRate, v7, v8, v9);
    }
    return 1;
  }
  else
  {
    BBSupportTracePrintF(0, "VoiceChat :\tCVoiceChat::Init() : Failed to start Recorder");
    return 0;
  }
}


// address=[0x2fd4af0]
// Decompiled from _DWORD *__thiscall CVoiceChat::Stop(_DWORD *this)
void  CVoiceChat::Stop(void) {
  
  _DWORD *result; // eax
  void (__thiscall ***v2)(_DWORD, int); // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]

  CVC_EventHandle::UnregisterVC((CVC_EventHandle *)&g_cVC_EventHandle);
  CVCRecorder::Shutdown((CVCRecorder *)(this + 6));
  result = this;
  if ( this[3] )
  {
    for ( i = 0; ; ++i )
    {
      result = (_DWORD *)i;
      if ( i >= this[2] )
        break;
      if ( *(_DWORD *)(this[3] + 4 * i) )
      {
        CVCClient::Shutdown(*(CVCClient **)(this[3] + 4 * i));
        if ( *(_DWORD *)(this[3] + 4 * i) )
        {
          v2 = *(void (__thiscall ****)(_DWORD, int))(this[3] + 4 * i);
          (**v2)(v2, 1);
        }
        *(_DWORD *)(this[3] + 4 * i) = 0;
      }
    }
  }
  return result;
}


// address=[0x2fd4bb0]
// Decompiled from char __thiscall sub_33D4BB0(int this, void *Src, int a3)
bool  CVoiceChat::ReceivePacket(signed char * Src, int a3) {
  
  int v4; // [esp+0h] [ebp-8h]

  if ( !*(_DWORD *)(this + 12) && BBSupportDbgReport(2, "VoiceChat.cpp", 260, "m_papcClients != NULL") == 1 )
    __debugbreak();
  if ( !*(_BYTE *)(this + 20) )
    return 0;
  v4 = a3 - *(_DWORD *)(this + 152);
  if ( v4 >= 0 && v4 < *(_DWORD *)(this + 8) )
  {
    CVCClient::ReceivePackage(Src);
    return 1;
  }
  else
  {
    BBSupportTracePrintF(0, "CVoiceChat::ReceivePackage : no valid player ID %d", a3);
    return 0;
  }
}


// address=[0x2fd4c50]
// Decompiled from int __thiscall CVoiceChat::GetInputSamplingRate(CVoiceChat *this)
int  CVoiceChat::GetInputSamplingRate(void) {
  
  return CVCRecorder::GetInputRate((CVoiceChat *)((char *)this + 24));
}


// address=[0x2fd4c70]
// Decompiled from void __thiscall CVoiceChat::ToggleRecording(CVoiceChat *this, bool a2)
void  CVoiceChat::ToggleRecording(bool a2) {
  
  if ( !CVCRecorder::UsesFullDuplex((CVoiceChat *)((char *)this + 24)) )
    *((_BYTE *)this + 20) = a2;
  CVCRecorder::ToggleRecording((CVoiceChat *)((char *)this + 24), a2);
}


// address=[0x2fd4cb0]
// Decompiled from bool __thiscall CVoiceChat::IsRecording(CVoiceChat *this)
bool  CVoiceChat::IsRecording(void) {
  
  return CVCRecorder::IsRecording((CVoiceChat *)((char *)this + 24));
}


// address=[0x2fd4cd0]
// Decompiled from int __thiscall CVoiceChat::Run(CVoiceChat *this)
void  CVoiceChat::Run(void) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  CVoiceChat::SendPacket(this);
  for ( i = 0; i < *((_DWORD *)this + 2); ++i )
  {
    if ( *(_DWORD *)(*((_DWORD *)this + 3) + 4 * i) )
      CVCClient::Run(*(CVCClient **)(*((_DWORD *)this + 3) + 4 * i));
    result = i + 1;
  }
  return result;
}


// address=[0x2fd4d30]
// Decompiled from bool __thiscall CVoiceChat::UsesFullDuplex(CVoiceChat *this)
bool  CVoiceChat::UsesFullDuplex(void) {
  
  return CVCRecorder::UsesFullDuplex((CVoiceChat *)((char *)this + 24));
}


// address=[0x2fd4d50]
// Decompiled from void __thiscall CVoiceChat::CalcBaseNoise(CVoiceChat *this)
void  CVoiceChat::CalcBaseNoise(void) {
  
  CVCRecorder::CalcNoiseVol((CVoiceChat *)((char *)this + 24));
}


// address=[0x2fd4d70]
// Decompiled from CVCRecorder *__thiscall CVoiceChat::SetOperationMode(int this, bool a2)
void  CVoiceChat::SetOperationMode(bool a2) {
  
  return CVCRecorder::SetOperationMode((CVCRecorder *)(this + 24), a2);
}


// address=[0x2fd4d90]
// Decompiled from CVoiceChat *__thiscall CVoiceChat::SetTestMode(CVoiceChat *this, bool a2)
void  CVoiceChat::SetTestMode(bool a2) {
  
  CVoiceChat *result; // eax

  result = this;
  *((_BYTE *)this + 136) = a2;
  return result;
}


// address=[0x2fd4db0]
// Decompiled from char __thiscall CVoiceChat::OnEvent(CVoiceChat *this, struct CEvn_Event *a2)
bool  CVoiceChat::OnEvent(class CEvn_Event & a2) {
  
  int event; // [esp+8h] [ebp-8h]

  event = a2->event;
  if ( event == 107 )
  {
    CVoiceChat::ToggleRecording(this, a2->wparam != 0);
    return 1;
  }
  else if ( event == 4004 )
  {
    CVoiceChat::ReceivePacket(a2[1].__vftable, BYTE2(a2[1].event));
    return 1;
  }
  else
  {
    return 0;
  }
}


// address=[0x2fd4e30]
// Decompiled from CVoiceChat *__thiscall CVoiceChat::SetVolume(CVoiceChat *this, int a2)
void  CVoiceChat::SetVolume(int a2) {
  
  CVoiceChat *result; // eax
  int i; // [esp+4h] [ebp-8h]
  int v5; // [esp+8h] [ebp-4h]

  v5 = a2 * *((_DWORD *)this + 39) / 100;
  if ( v5 <= 127 )
  {
    if ( v5 < 0 )
      v5 = 0;
  }
  else
  {
    v5 = 127;
  }
  for ( i = 0; ; ++i )
  {
    result = this;
    if ( i >= *((_DWORD *)this + 2) )
      break;
    if ( *(_DWORD *)(*((_DWORD *)this + 3) + 4 * i) )
      CVCClient::SetVolume(*(CVCClient **)(*((_DWORD *)this + 3) + 4 * i), v5);
  }
  return result;
}


// address=[0x2fd4ec0]
// Decompiled from char __thiscall CVoiceChat::SetMicVolume(CVoiceChat *this, unsigned int a2)
void  CVoiceChat::SetMicVolume(int a2) {
  
  char result; // al

  if ( *((int *)this + 41) < 0 && BBSupportDbgReport(2, "VoiceChat.cpp", 825, "m_iMaxMicVol >= 0") == 1 )
    __debugbreak();
  if ( a2 > 0x64 && BBSupportDbgReport(2, "VoiceChat.cpp", 826, "(_iVolPercent>= 0) && (_iVolPercent<= 100)") == 1 )
    __debugbreak();
  result = CVoiceChat::SetWindowsMicVolume(this, (int)(a2 * *((_DWORD *)this + 41)) / 100);
  if ( !result )
    return BBSupportTracePrintF(0, "VoiceChat :\tCVoiceChat::SetMicVolume() : Failed to set volume");
  return result;
}


// address=[0x2fd4f60]
// Decompiled from int __thiscall CVoiceChat::GetMicVolume(CVoiceChat *this)
int  CVoiceChat::GetMicVolume(void) {
  
  int v2; // [esp+0h] [ebp-8h] BYREF
  CVoiceChat *v3; // [esp+4h] [ebp-4h]

  v3 = this;
  if ( CVoiceChat::GetWindowsMicVolume(this, &v2) )
    return 100 * v2 / *((_DWORD *)v3 + 41);
  BBSupportTracePrintF(0, "VoiceChat :\tCVoiceChat::GetMicVolume() : Failed to get volume");
  return 0;
}


// address=[0x2fd3d50]
// Decompiled from void __thiscall CVoiceChat::SendPacket(CVoiceChat *this)
void  CVoiceChat::SendPacket(void) {
  
  CEvn_Logic *v1; // [esp+4h] [ebp-3Ch]
  _BYTE v3[32]; // [esp+10h] [ebp-30h] BYREF
  int v4; // [esp+3Ch] [ebp-4h]

  if ( CVCRecorder::IsRecording((CVoiceChat *)((char *)this + 24)) || *((_DWORD *)this + 36) )
  {
    *((_DWORD *)this + 36) += CVCRecorder::GetEncodedData(
                                (CVoiceChat *)((char *)this + 24),
                                (signed __int8 *)(*((_DWORD *)this + 36) + *((_DWORD *)this + 35)),
                                *((_DWORD *)this + 33) - *((_DWORD *)this + 36));
    if ( *((_DWORD *)this + 36) == *((_DWORD *)this + 33) )
    {
      *((_DWORD *)this + 36) = 0;
      if ( *((_BYTE *)this + 136) )
      {
        CVoiceChat::ReceivePacket(*((void **)this + 35), *((_DWORD *)this + 2) - 1);
      }
      else
      {
        v1 = CEvn_Logic::CEvn_Logic((CEvn_Logic *)v3, 0x25u, 0, 0, 0, *((_DWORD *)this + 35), *((_WORD *)this + 66));
        v4 = 0;
        IEventEngine::SendAMessage(g_pEvnEngine, v1);
        v4 = -1;
        CEvn_Logic::~CEvn_Logic(v3);
      }
    }
  }
}


// address=[0x2fd3ea0]
// Decompiled from char __thiscall CVoiceChat::SetWindowsMicVolume(CVoiceChat *this, int a2)
bool  CVoiceChat::SetWindowsMicVolume(int a2) {
  
  tagMIXERLINECONTROLSA pmxlc; // [esp+4h] [ebp-1C0h] BYREF
  tMIXERCONTROLDETAILS pmxcd; // [esp+1Ch] [ebp-1A8h] BYREF
  int v5; // [esp+34h] [ebp-190h] BYREF
  signed int cConnections; // [esp+3Ch] [ebp-188h]
  signed int j; // [esp+40h] [ebp-184h]
  DWORD i; // [esp+44h] [ebp-180h]
  HMIXER phmx; // [esp+48h] [ebp-17Ch] BYREF
  MMRESULT DevCapsA; // [esp+4Ch] [ebp-178h]
  char v12; // [esp+53h] [ebp-171h]
  char v13; // [esp+54h] [ebp-170h] BYREF
  DWORD v14; // [esp+58h] [ebp-16Ch]
  tagMIXERCAPSA pmxcaps; // [esp+E8h] [ebp-DCh] BYREF
  tagMIXERLINEA pmxl; // [esp+118h] [ebp-ACh] BYREF

  j = 0;
  i = 0;
  cConnections = 0;
  v12 = 0;
  if ( mixerGetNumDevs() )
  {
    DevCapsA = mixerOpen(&phmx, 0, 0, 0, 0);
    if ( DevCapsA )
    {
      BBSupportTracePrintF(0, "CVoiceChat::SetWindowsMicVolume : Failed to open mixer");
      return 0;
    }
    else
    {
      DevCapsA = mixerGetDevCapsA((UINT_PTR)phmx, &pmxcaps, 0x30u);
      if ( DevCapsA )
      {
        BBSupportTracePrintF(0, "CVoiceChat::SetWindowsMicVolume : Failed to get mixer device caps");
        return 0;
      }
      else
      {
        pmxl.cbStruct = 168;
        for ( i = 0; i < pmxcaps.cDestinations; ++i )
        {
          pmxl.dwDestination = i;
          DevCapsA = mixerGetLineInfoA((HMIXEROBJ)phmx, &pmxl, 0);
          if ( DevCapsA )
          {
            BBSupportTracePrintF(0, "CVoiceChat::SetWindowsMicVolume : Failed to get mixer line info");
            mixerClose(phmx);
            return 0;
          }
          if ( pmxl.dwComponentType != 4 )
          {
            cConnections = pmxl.cConnections;
            for ( j = 0; j < cConnections; ++j )
            {
              pmxl.dwSource = j;
              pmxl.dwDestination = i;
              DevCapsA = mixerGetLineInfoA((HMIXEROBJ)phmx, &pmxl, 1u);
              if ( DevCapsA )
              {
                BBSupportTracePrintF(0, "CVoiceChat::SetWindowsMicVolume : Failed to get mic line info.");
                mixerClose(phmx);
                return 0;
              }
              if ( pmxl.dwComponentType == 4099 )
              {
                v12 = 1;
                break;
              }
            }
            if ( v12 )
              break;
          }
        }
        if ( v12 )
        {
          pmxlc.dwLineID = pmxl.dwLineID;
          pmxlc.dwControlID = 1342373889;
          pmxlc.cbmxctrl = 148;
          pmxlc.cbStruct = 24;
          pmxlc.cControls = 1;
          pmxlc.pamxctrl = (LPMIXERCONTROLA)&v13;
          DevCapsA = mixerGetLineControlsA((HMIXEROBJ)phmx, &pmxlc, 2u);
          if ( DevCapsA )
          {
            BBSupportTracePrintF(0, "CVoiceChat::SetWindowsMicVolume : Failed to get microphon control");
            mixerClose(phmx);
            return 0;
          }
          else
          {
            pmxcd.cbStruct = 24;
            pmxcd.cChannels = pmxl.cChannels;
            pmxcd.cMultipleItems = 0;
            pmxcd.dwControlID = v14;
            pmxcd.cbDetails = 4;
            pmxcd.paDetails = &v5;
            DevCapsA = mixerGetControlDetailsA((HMIXEROBJ)phmx, &pmxcd, 0);
            if ( DevCapsA )
            {
              BBSupportTracePrintF(0, "CVoiceChat::SetWindowsMicVolume : Failed to get control details.");
              mixerClose(phmx);
              return 0;
            }
            else
            {
              v5 = a2;
              DevCapsA = mixerSetControlDetails((HMIXEROBJ)phmx, &pmxcd, 0);
              if ( DevCapsA )
              {
                BBSupportTracePrintF(0, "CVoiceChat::SetWindowsMicVolume : Failed to set control details.");
                mixerClose(phmx);
                return 0;
              }
              else
              {
                mixerClose(phmx);
                return 1;
              }
            }
          }
        }
        else
        {
          BBSupportTracePrintF(0, "CVoiceChat::SetWindowsMicVolume : Haven't found a mic in mixer line.");
          mixerClose(phmx);
          return 0;
        }
      }
    }
  }
  else
  {
    BBSupportTracePrintF(0, "CVoiceChat::SetWindowsMicVolume : No mixer controls available.");
    return 0;
  }
}


// address=[0x2fd4290]
// Decompiled from char __thiscall CVoiceChat::GetWindowsMicVolume(CVoiceChat *this, int *a2)
bool  CVoiceChat::GetWindowsMicVolume(int * a2) {
  
  struct tagMIXERLINECONTROLSA pmxlc; // [esp+0h] [ebp-1C4h] BYREF
  struct tMIXERCONTROLDETAILS pmxcd; // [esp+18h] [ebp-1ACh] BYREF
  int v5; // [esp+30h] [ebp-194h] BYREF
  CVoiceChat *v6; // [esp+34h] [ebp-190h]
  signed int cConnections; // [esp+3Ch] [ebp-188h]
  signed int j; // [esp+40h] [ebp-184h]
  DWORD i; // [esp+44h] [ebp-180h]
  HMIXER phmx; // [esp+48h] [ebp-17Ch] BYREF
  MMRESULT DevCapsA; // [esp+4Ch] [ebp-178h]
  char v13; // [esp+53h] [ebp-171h]
  char v14; // [esp+54h] [ebp-170h] BYREF
  DWORD v15; // [esp+58h] [ebp-16Ch]
  char v16[84]; // [esp+68h] [ebp-15Ch] BYREF
  int v17; // [esp+BCh] [ebp-108h]
  struct tagMIXERCAPSA pmxcaps; // [esp+E8h] [ebp-DCh] BYREF
  struct tagMIXERLINEA pmxl; // [esp+118h] [ebp-ACh] BYREF

  v6 = this;
  j = 0;
  i = 0;
  cConnections = 0;
  v13 = 0;
  if ( mixerGetNumDevs() )
  {
    DevCapsA = mixerOpen(&phmx, 0, 0, 0, 0);
    if ( DevCapsA )
    {
      BBSupportTracePrintF(0, "CVoiceChat::GetWindowsMicVolume : Failed to open mixer");
      return 0;
    }
    else
    {
      DevCapsA = mixerGetDevCapsA((UINT_PTR)phmx, &pmxcaps, 0x30u);
      if ( DevCapsA )
      {
        BBSupportTracePrintF(0, "CVoiceChat::GetWindowsMicVolume : Failed to get mixer device caps");
        return 0;
      }
      else
      {
        pmxl.cbStruct = 168;
        for ( i = 0; i < pmxcaps.cDestinations; ++i )
        {
          pmxl.dwDestination = i;
          DevCapsA = mixerGetLineInfoA((HMIXEROBJ)phmx, &pmxl, 0);
          if ( DevCapsA )
          {
            BBSupportTracePrintF(0, "CVoiceChat::GetWindowsMicVolume : Failed to get mixer line info");
            mixerClose(phmx);
            return 0;
          }
          if ( pmxl.dwComponentType != 4 )
          {
            cConnections = pmxl.cConnections;
            for ( j = 0; j < cConnections; ++j )
            {
              pmxl.dwSource = j;
              pmxl.dwDestination = i;
              DevCapsA = mixerGetLineInfoA((HMIXEROBJ)phmx, &pmxl, 1u);
              if ( DevCapsA )
              {
                BBSupportTracePrintF(0, "CVoiceChat::GetWindowsMicVolume : Failed to get mic line info.");
                mixerClose(phmx);
                return 0;
              }
              if ( pmxl.dwComponentType == 4099 )
              {
                v13 = 1;
                break;
              }
            }
            if ( v13 )
              break;
          }
        }
        if ( v13 )
        {
          pmxlc.dwLineID = pmxl.dwLineID;
          pmxlc.dwControlID = 1342373889;
          pmxlc.cbmxctrl = 148;
          pmxlc.cbStruct = 24;
          pmxlc.cControls = 1;
          pmxlc.pamxctrl = (LPMIXERCONTROLA)&v14;
          DevCapsA = mixerGetLineControlsA((HMIXEROBJ)phmx, &pmxlc, 2u);
          if ( DevCapsA )
          {
            BBSupportTracePrintF(0, "CVoiceChat::GetWindowsMicVolume : Failed to get microphon control");
            mixerClose(phmx);
            return 0;
          }
          else
          {
            pmxcd.cbStruct = 24;
            pmxcd.cChannels = pmxl.cChannels;
            pmxcd.cMultipleItems = 0;
            pmxcd.dwControlID = v15;
            pmxcd.cbDetails = 4;
            pmxcd.paDetails = &v5;
            DevCapsA = mixerGetControlDetailsA((HMIXEROBJ)phmx, &pmxcd, 0);
            if ( DevCapsA )
            {
              BBSupportTracePrintF(0, "CVoiceChat::GetWindowsMicVolume : Failed to get mixer control details, %s", v16);
              mixerClose(phmx);
              return 0;
            }
            else
            {
              *((_DWORD *)v6 + 41) = v17;
              *a2 = v5;
              mixerClose(phmx);
              return 1;
            }
          }
        }
        else
        {
          BBSupportTracePrintF(0, "CVoiceChat::GetWindowsMicVolume : Haven't found a mic in mixer line.");
          mixerClose(phmx);
          return 0;
        }
      }
    }
  }
  else
  {
    BBSupportTracePrintF(0, "CVoiceChat::GetWindowsMicVolume : No mixer controls available.");
    return 0;
  }
}


