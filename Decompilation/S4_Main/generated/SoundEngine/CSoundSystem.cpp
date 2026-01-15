#include "CSoundSystem.h"

// Definitions for class CSoundSystem

// address=[0x2fd9bc0]
// Decompiled from CSoundSystem *__thiscall CSoundSystem::CSoundSystem(CSoundSystem *this)
 CSoundSystem::CSoundSystem(void) {
  
  unsigned int v1; // eax

  *(_DWORD *)this = &CSoundSystem::_vftable_;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 3;
  *((_DWORD *)this + 4) = 44100;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = -1;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 8) = 1;
  v1 = sub_2FD8D10(0);
  j__srand(v1);
  return this;
}


// address=[0x2fd9c90]
// Decompiled from void __thiscall CSoundSystem::~CSoundSystem(CSoundSystem::SSoundCardData **this)
 CSoundSystem::~CSoundSystem(void) {
  
  CSoundSystem::SSoundCardData *v1; // [esp+14h] [ebp-20h]
  CSoundSystem::SSoundCardData *v2; // [esp+20h] [ebp-14h]

  *this = (CSoundSystem::SSoundCardData *)&CSoundSystem::_vftable_;
  CSoundSystem::Shutdown((CSoundSystem *)this);
  if ( this[14] )
  {
    v2 = this[14];
    if ( v2 )
    {
      if ( *((_DWORD *)v2 - 1) )
        (**(void (__thiscall ***)(CSoundSystem::SSoundCardData *, int))v2)(v2, 3);
      else
        operator delete[]((char *)v2 - 4);
    }
    this[14] = 0;
  }
  if ( this[13] )
  {
    v1 = this[13];
    if ( v1 )
      CSoundSystem::SSoundCardData::`vector deleting destructor'(v1, 3u);
    this[13] = 0;
  }
}


// address=[0x2fd9d90]
// Decompiled from char __thiscall CSoundSystem::Init(CSoundSystem *this, const char *a2, int a3, bool a4, int a5, int a6, int a7)
bool  CSoundSystem::Init(char const *,int,bool,int,int,int) {
  
  *((_DWORD *)this + 4) = a3;
  if ( a4 )
  {
    if ( a5 == 16 )
      *((_DWORD *)this + 3) = 3;
    else
      *((_DWORD *)this + 3) = 2;
  }
  else
  {
    *((_DWORD *)this + 3) = a5 == 16;
  }
  *((_DWORD *)this + 2) = a6;
  *((_DWORD *)this + 1) = a7;
  AIL_set_preference(1, *((_DWORD *)this + 2) + *((_DWORD *)this + 1) + 8);
  AIL_set_file_callbacks(sub_2FDBB20, sub_2FDBC20, sub_2FDBC40, sub_2FDBCA0);
  AIL_set_redist_directory(a2);
  j__MSS_auto_cleanup();
  AIL_startup();
  if ( !CSoundSystem::InitOutputDriver(this) )
    return 0;
  CSoundSystem::AllocateSampleHandles(this);
  return 1;
}


// address=[0x2fd9e60]
// Decompiled from CSoundSystem *__thiscall CSoundSystem::StopPlayback(CSoundSystem *this)
void  CSoundSystem::StopPlayback(void) {
  
  CSoundSystem *result; // eax
  int i; // [esp+4h] [ebp-4h]
  int j; // [esp+4h] [ebp-4h]

  result = this;
  if ( !*((_DWORD *)this + 9) )
    return result;
  if ( *((_DWORD *)this + 10) )
  {
    for ( i = 0; i < *((_DWORD *)this + 2); ++i )
    {
      if ( *(_DWORD *)(*((_DWORD *)this + 10) + 16 * i) )
      {
        CSoundSystem::StopSample(this, *(_DWORD *)(*((_DWORD *)this + 10) + 16 * i));
        *(_DWORD *)(*((_DWORD *)this + 10) + 16 * i) = 0;
      }
    }
  }
  result = this;
  if ( *((_DWORD *)this + 11) )
  {
    for ( j = 0; ; ++j )
    {
      result = (CSoundSystem *)j;
      if ( j >= *((_DWORD *)this + 1) )
        break;
      if ( *(_DWORD *)(*((_DWORD *)this + 11) + 16 * j + 8) )
      {
        AIL_register_stream_callback(*(_DWORD *)(*((_DWORD *)this + 11) + 16 * j + 8), 0);
        AIL_pause_stream(*(_DWORD *)(*((_DWORD *)this + 11) + 16 * j + 8), 1);
        *(_DWORD *)(*((_DWORD *)this + 11) + 16 * j) = 0;
      }
    }
  }
  return result;
}


// address=[0x2fd9f60]
// Decompiled from int __thiscall CSoundSystem::GetNumberOfPlayingVoices(_DWORD *this)
int  CSoundSystem::GetNumberOfPlayingVoices(void) {
  
  int v3; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]
  int j; // [esp+8h] [ebp-4h]

  v3 = 0;
  for ( i = 0; i < this[2]; ++i )
  {
    if ( AIL_sample_status(*(_DWORD *)(this[10] + 16 * i + 8)) == 4 )
      ++v3;
  }
  for ( j = 0; j < this[1]; ++j )
  {
    if ( AIL_stream_status(*(_DWORD *)(this[11] + 16 * j + 8)) == 4 )
      ++v3;
  }
  return v3;
}


// address=[0x2fda000]
// Decompiled from int __thiscall CSoundSystem::Shutdown(CSoundSystem *this)
void  CSoundSystem::Shutdown(void) {
  
  CSoundSystem::StopPlayback(this);
  CSoundSystem::FreeMemory(this);
  return AIL_shutdown();
}


// address=[0x2fda030]
// Decompiled from int __thiscall CSoundSystem::GetCpuUsage(CSoundSystem *this)
int  CSoundSystem::GetCpuUsage(void) {
  
  if ( *((_DWORD *)this + 9) )
    return AIL_digital_CPU_percent(*((_DWORD *)this + 9));
  else
    return -1;
}


// address=[0x2fda060]
// Decompiled from int __thiscall CSoundSystem::PlaySoundFile(CSoundSystem *this, const char *a2, unsigned int a3, unsigned int a4)
unsigned int  CSoundSystem::PlaySoundFile(char const *,int,int) {
  
  const char *error; // eax
  int v6; // [esp+0h] [ebp-Ch]
  int FreeSoundHandle; // [esp+4h] [ebp-8h]

  if ( a3 >= 0x80 && BBSupportDbgReport(2, "SoundSystem.cpp", 539, "(_iVolume>=0) && (_iVolume<=127)") == 1 )
    __debugbreak();
  if ( a4 >= 0x80 && BBSupportDbgReport(2, "SoundSystem.cpp", 541, "(_iPan>=0) && (_iPan<=127)") == 1 )
    __debugbreak();
  if ( *((_DWORD *)this + 9) )
  {
    FreeSoundHandle = CSoundSystem::GetFreeSoundHandle(this);
    if ( FreeSoundHandle == -1 )
    {
      BBSupportTracePrintF(0, "CSoundSystem::PlaySound: no free sound handle avaiable for %s", a2);
      return 0;
    }
    else
    {
      *(_DWORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle + 12) = AIL_file_read(a2, -1);
      if ( *(_DWORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle + 12) )
      {
        v6 = AIL_file_size(a2);
        AIL_init_sample(*(_DWORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle + 8));
        if ( AIL_set_named_sample_file(
               *(_DWORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle + 8),
               a2,
               *(_DWORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle + 12),
               v6,
               0) )
        {
          *(_DWORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle) = (*((_DWORD *)this + 8))++;
          *(_WORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle + 4) = a3;
          AIL_set_sample_volume(*(_DWORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle + 8), a3);
          *(_WORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle + 6) = a4;
          AIL_set_sample_pan(*(_DWORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle + 8), a4);
          AIL_start_sample(*(_DWORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle + 8));
          return *(_DWORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle);
        }
        else
        {
          BBSupportTracePrintF(0, "CSoundSystem::PlaySound: No ASI provider available for file type.");
          return 0;
        }
      }
      else
      {
        error = (const char *)AIL_last_error();
        BBSupportTracePrintF(0, "CSoundSystem::PlaySound : Failed to load sound :%s, %s", a2, error);
        return 0;
      }
    }
  }
  else
  {
    BBSupportTracePrintF(0, "CSoundSystem::PlaySound: no digital driver available");
    return 0;
  }
}


// address=[0x2fda280]
// Decompiled from int __thiscall sub_33DA280(_DWORD *this, const char *a2, unsigned int a3, unsigned int a4, char a5, int a6)
unsigned int  CSoundSystem::PlayStream(char const *,int,int,bool,int) {
  
  const char *error; // eax
  int v8; // [esp+0h] [ebp-8h]

  if ( a3 >= 0x80 && BBSupportDbgReport(2, "SoundSystem.cpp", 450, "(_iVolume>=0) && (_iVolume<=127)") == 1 )
    __debugbreak();
  if ( a4 >= 0x80 && BBSupportDbgReport(2, "SoundSystem.cpp", 452, "(_iPan>=0) && (_iPan<=127)") == 1 )
    __debugbreak();
  v8 = CSoundSystem::GetFreeStreamHandle(this);
  if ( v8 == -1 )
  {
    BBSupportTracePrintF(0, "CSoundSystem::PlayStream : No free stream handle for %s", a2);
    return 0;
  }
  else
  {
    *(_DWORD *)(this[11] + 16 * v8 + 8) = AIL_open_stream(this[9], a2, 0);
    if ( *(_DWORD *)(this[11] + 16 * v8 + 8) )
    {
      *(_DWORD *)(this[11] + 16 * v8) = this[8]++;
      *(_BYTE *)(this[11] + 16 * v8 + 12) = 1;
      *(_WORD *)(this[11] + 16 * v8 + 14) = a6;
      *(_WORD *)(this[11] + 16 * v8 + 4) = a3;
      AIL_set_stream_volume(*(_DWORD *)(this[11] + 16 * v8 + 8), a3);
      *(_WORD *)(this[11] + 16 * v8 + 6) = a4;
      AIL_set_stream_pan(*(_DWORD *)(this[11] + 16 * v8 + 8), a4);
      AIL_set_stream_position(*(_DWORD *)(this[11] + 16 * v8 + 8), 0);
      if ( a5 )
        AIL_register_stream_callback(*(_DWORD *)(this[11] + 16 * v8 + 8), &CSoundSystem::LoopStreamCB);
      if ( a6 >= 0 )
      {
        AIL_register_stream_callback(*(_DWORD *)(this[11] + 16 * v8 + 8), PlaylistCallback);
        CPlaylist::SetTrackID(*(_DWORD *)(this[11] + 16 * v8));
        CPlaylist::SetHandle((CMFCCaptionButton *)(this[14] + 48 * a6), *(_DWORD *)(this[11] + 16 * v8 + 8));
      }
      AIL_start_stream(*(_DWORD *)(this[11] + 16 * v8 + 8));
      return *(_DWORD *)(this[11] + 16 * v8);
    }
    else
    {
      error = (const char *)AIL_last_error();
      BBSupportTracePrintF(0, "CSoundSystem::PlayStream : Failed to load stream :%s,%s", a2, error);
      return 0;
    }
  }
}


// address=[0x2fda4e0]
// Decompiled from int __thiscall CSoundSystem::PlaySoundFromMemory(  CSoundSystem *this,  unsigned int *a2,  char *a3,  unsigned int a4,  int a5,  int a6,  int a7,  bool a8)
unsigned int  CSoundSystem::PlaySoundFromMemory(unsigned int *,char *,unsigned int,int,int,int,bool) {
  
  int v9; // [esp+0h] [ebp-Ch]
  int FreeSoundHandle; // [esp+4h] [ebp-8h]

  if ( *((_DWORD *)this + 9) )
  {
    FreeSoundHandle = CSoundSystem::GetFreeSoundHandle(this);
    if ( FreeSoundHandle >= 0 )
    {
      AIL_init_sample(*(_DWORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle + 8));
      if ( AIL_set_named_sample_file(*(_DWORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle + 8), a3, a2, a4, 0) )
      {
        *(_DWORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle) = (*((_DWORD *)this + 8))++;
        *(_WORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle + 4) = a5;
        AIL_set_sample_volume(*(_DWORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle + 8), a5);
        *(_WORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle + 6) = a6;
        AIL_set_sample_pan(*(_DWORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle + 8), a6);
        v9 = a7 * AIL_sample_playback_rate(*(_DWORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle + 8)) / 100;
        AIL_set_sample_playback_rate(*(_DWORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle + 8), v9);
        if ( a8 )
          AIL_register_EOS_callback(
            *(_DWORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle + 8),
            CSoundSystem::LoopSampleCB);
        AIL_start_sample(*(_DWORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle + 8));
        return *(_DWORD *)(*((_DWORD *)this + 10) + 16 * FreeSoundHandle);
      }
      else
      {
        BBSupportTracePrintF(0, "CSoundSystem::PlaySoundFromMemory: No ASI provider available for file type.");
        return 0;
      }
    }
    else
    {
      BBSupportTracePrintF(11, "CSoundSystem::PlaySoundFromMemory: No free sound handle.");
      return 0;
    }
  }
  else
  {
    BBSupportTracePrintF(0, "CSoundSystem::PlaySoundFromMemory: no digital driver available");
    return 0;
  }
}


// address=[0x2fda6a0]
// Decompiled from char __thiscall CSoundSystem::ChangeVolume(CSoundSystem *this, unsigned int a2, unsigned int a3)
bool  CSoundSystem::ChangeVolume(unsigned int,int) {
  
  int StreamIndex; // [esp+4h] [ebp-4h]
  int SoundIndex; // [esp+4h] [ebp-4h]

  if ( a3 >= 0x80 && BBSupportDbgReport(2, "SoundSystem.cpp", 824, "(_iVolume>=0) && (_iVolume<=127)") == 1 )
    __debugbreak();
  StreamIndex = CSoundSystem::GetStreamIndex(this, a2);
  if ( StreamIndex < 0 )
  {
    SoundIndex = CSoundSystem::GetSoundIndex(this, a2);
    if ( SoundIndex < 0 )
    {
      return 0;
    }
    else
    {
      AIL_set_sample_volume(*(_DWORD *)(*((_DWORD *)this + 10) + 16 * SoundIndex + 8), a3);
      *(_WORD *)(*((_DWORD *)this + 10) + 16 * SoundIndex + 4) = a3;
      if ( a3 )
        return 1;
      CSoundSystem::StopSample(this, a2);
      *(_DWORD *)(*((_DWORD *)this + 10) + 16 * SoundIndex) = 0;
      return 1;
    }
  }
  else
  {
    AIL_set_stream_volume(*(_DWORD *)(*((_DWORD *)this + 11) + 16 * StreamIndex + 8), a3);
    *(_WORD *)(*((_DWORD *)this + 11) + 16 * StreamIndex + 4) = a3;
    return 1;
  }
}


// address=[0x2fda7a0]
// Decompiled from int __thiscall CSoundSystem::GetVolume(CSoundSystem *this, unsigned int a2)
int  CSoundSystem::GetVolume(unsigned int) {
  
  int StreamIndex; // [esp+4h] [ebp-4h]
  int SoundIndex; // [esp+4h] [ebp-4h]

  StreamIndex = CSoundSystem::GetStreamIndex(this, a2);
  if ( StreamIndex >= 0 )
    return *(__int16 *)(*((_DWORD *)this + 11) + 16 * StreamIndex + 4);
  SoundIndex = CSoundSystem::GetSoundIndex(this, a2);
  if ( SoundIndex >= 0 )
    return *(__int16 *)(*((_DWORD *)this + 10) + 16 * SoundIndex + 4);
  BBSupportTracePrintF(0, "CSoundSystem::GetVolume : Unknown ID : %i", a2);
  return 0;
}


// address=[0x2fda820]
// Decompiled from char __thiscall CSoundSystem::ChangePan(CSoundSystem *this, unsigned int a2, unsigned int a3)
bool  CSoundSystem::ChangePan(unsigned int,int) {
  
  int StreamIndex; // [esp+4h] [ebp-4h]
  int SoundIndex; // [esp+4h] [ebp-4h]

  if ( a3 >= 0x80 && BBSupportDbgReport(2, "SoundSystem.cpp", 869, "(_iPan>=0) && (_iPan<=127)") == 1 )
    __debugbreak();
  StreamIndex = CSoundSystem::GetStreamIndex(this, a2);
  if ( StreamIndex < 0 )
  {
    SoundIndex = CSoundSystem::GetSoundIndex(this, a2);
    if ( SoundIndex < 0 )
    {
      return 0;
    }
    else
    {
      AIL_set_sample_pan(*(_DWORD *)(*((_DWORD *)this + 10) + 16 * SoundIndex + 8), a3);
      return 1;
    }
  }
  else
  {
    AIL_set_stream_pan(*(_DWORD *)(*((_DWORD *)this + 11) + 16 * StreamIndex + 8), a3);
    return 1;
  }
}


// address=[0x2fda8d0]
// Decompiled from char __thiscall CSoundSystem::Fade(CSoundSystem *this, unsigned int a2, int a3, int a4)
bool  CSoundSystem::Fade(unsigned int,int,int) {
  
  double Volume; // [esp+8h] [ebp-1Ch]
  int v6; // [esp+14h] [ebp-10h]
  int v7; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  int j; // [esp+1Ch] [ebp-8h]

  v7 = -1;
  if ( !*((_DWORD *)this + 5) )
  {
    BBSupportTracePrintF(0, "CSoundSystem::Fade no timer interval set");
    return 0;
  }
  for ( i = 0; i < *((_DWORD *)this + 1) + *((_DWORD *)this + 2); ++i )
  {
    if ( *(_DWORD *)(*((_DWORD *)this + 12) + 4 * i) && **(_DWORD **)(*((_DWORD *)this + 12) + 4 * i) == a2 )
    {
      Volume = *(double *)(*(_DWORD *)(*((_DWORD *)this + 12) + 4 * i) + 8);
      v7 = i;
      break;
    }
  }
  if ( v7 < 0 )
  {
    for ( j = 0; j < *((_DWORD *)this + 1) + *((_DWORD *)this + 2); ++j )
    {
      if ( !*(_DWORD *)(*((_DWORD *)this + 12) + 4 * j) )
      {
        v7 = j;
        break;
      }
    }
    if ( v7 < 0 )
    {
      BBSupportTracePrintF(0, "SoundEngine : CSoundSystem::Fade() no free fade jobs");
      return 0;
    }
    Volume = (double)(int)CSoundSystem::GetVolume(this, a2);
    *(_DWORD *)(*((_DWORD *)this + 12) + 4 * v7) = operator new(0x20u);
  }
  v6 = *(_DWORD *)(*((_DWORD *)this + 12) + 4 * v7);
  *(_DWORD *)v6 = a2;
  *(double *)(v6 + 8) = Volume;
  *(double *)(v6 + 16) = (double)a3;
  *(double *)(v6 + 24) = (*(double *)(v6 + 16) - *(double *)(v6 + 8)) / ((double)a4 / (double)*((int *)this + 5));
  return 1;
}


// address=[0x2fdaa80]
// Decompiled from int __thiscall CSoundSystem::SetTimerInterval(CSoundSystem *this, int a2)
void  CSoundSystem::SetTimerInterval(int) {
  
  int result; // eax

  if ( a2 < 0 && BBSupportDbgReport(2, "SoundSystem.cpp", 1015, "_iInterval >= 0") == 1 )
    __debugbreak();
  result = 0;
  *((_DWORD *)this + 5) = a2;
  return result;
}


// address=[0x2fdaac0]
// Decompiled from void __thiscall CSoundSystem::Update(CSoundSystem *this)
void  CSoundSystem::Update(void) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < *((_DWORD *)this + 1); ++i )
  {
    if ( *(_DWORD *)(*((_DWORD *)this + 11) + 16 * i + 8) )
    {
      if ( !*(_BYTE *)(*((_DWORD *)this + 11) + 16 * i + 12) )
      {
        AIL_close_stream(*(_DWORD *)(*((_DWORD *)this + 11) + 16 * i + 8));
        *(_DWORD *)(*((_DWORD *)this + 11) + 16 * i + 8) = 0;
      }
    }
  }
  CSoundSystem::UpdateFades(this);
}


// address=[0x2fdab50]
// Decompiled from int __thiscall CSoundSystem::StopSample(CSoundSystem *this, unsigned int a2)
void  CSoundSystem::StopSample(unsigned int) {
  
  int result; // eax
  int StreamIndex; // [esp+4h] [ebp-4h]
  int v5; // [esp+4h] [ebp-4h]

  StreamIndex = CSoundSystem::GetStreamIndex(this, a2);
  if ( StreamIndex < 0 )
  {
    result = CSoundSystem::GetSoundIndex(this, a2);
    v5 = result;
    if ( result >= 0 )
    {
      if ( *(_DWORD *)(*((_DWORD *)this + 10) + 16 * result + 12) )
      {
        AIL_mem_free_lock(*(_DWORD *)(*((_DWORD *)this + 10) + 16 * result + 12));
        *(_DWORD *)(*((_DWORD *)this + 10) + 16 * v5 + 12) = 0;
      }
      if ( *(_DWORD *)(*((_DWORD *)this + 10) + 16 * v5 + 8) )
        AIL_stop_sample(*(_DWORD *)(*((_DWORD *)this + 10) + 16 * v5 + 8));
      result = (int)this;
      *(_DWORD *)(*((_DWORD *)this + 10) + 16 * v5) = 0;
    }
  }
  else
  {
    if ( *(__int16 *)(*((_DWORD *)this + 11) + 16 * StreamIndex + 14) >= 0 )
      CPlaylist::StoreStreamPos((CPlaylist *)(*((_DWORD *)this + 14)
                                            + 48 * *(__int16 *)(*((_DWORD *)this + 11) + 16 * StreamIndex + 14)));
    AIL_close_stream(*(_DWORD *)(*((_DWORD *)this + 11) + 16 * StreamIndex + 8));
    *(_DWORD *)(*((_DWORD *)this + 11) + 16 * StreamIndex + 8) = 0;
    result = (int)this;
    *(_DWORD *)(*((_DWORD *)this + 11) + 16 * StreamIndex) = 0;
  }
  return result;
}


// address=[0x2fdac80]
// Decompiled from int __thiscall CSoundSystem::GetSampleID(CSoundSystem *this, struct _SAMPLE *a2)
int  CSoundSystem::GetSampleID(struct _SAMPLE *) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < *((_DWORD *)this + 2); ++i )
  {
    if ( *(struct _SAMPLE **)(*((_DWORD *)this + 10) + 16 * i + 8) == a2 )
      return *(_DWORD *)(*((_DWORD *)this + 10) + 16 * i);
  }
  return 0;
}


// address=[0x2fdace0]
// Decompiled from CSoundSystem *__thiscall CSoundSystem::StopStreams(CSoundSystem *this)
void  CSoundSystem::StopStreams(void) {
  
  CSoundSystem *result; // eax
  int i; // [esp+4h] [ebp-4h]

  result = this;
  if ( *((_DWORD *)this + 11) )
  {
    for ( i = 0; ; ++i )
    {
      result = (CSoundSystem *)i;
      if ( i >= *((_DWORD *)this + 1) )
        break;
      if ( *(_DWORD *)(*((_DWORD *)this + 11) + 16 * i + 8) )
      {
        AIL_register_stream_callback(*(_DWORD *)(*((_DWORD *)this + 11) + 16 * i + 8), 0);
        AIL_pause_stream(*(_DWORD *)(*((_DWORD *)this + 11) + 16 * i + 8), 1);
        AIL_close_stream(*(_DWORD *)(*((_DWORD *)this + 11) + 16 * i + 8));
        *(_DWORD *)(*((_DWORD *)this + 11) + 16 * i + 8) = 0;
        *(_DWORD *)(*((_DWORD *)this + 11) + 16 * i) = 0;
      }
    }
  }
  return result;
}


// address=[0x2fdadb0]
// Decompiled from CSoundSystem *__thiscall CSoundSystem::StopSounds(CSoundSystem *this)
void  CSoundSystem::StopSounds(void) {
  
  CSoundSystem *result; // eax
  int i; // [esp+4h] [ebp-4h]

  result = this;
  if ( *((_DWORD *)this + 10) )
  {
    for ( i = 0; ; ++i )
    {
      result = (CSoundSystem *)i;
      if ( i >= *((_DWORD *)this + 2) )
        break;
      if ( *(_DWORD *)(*((_DWORD *)this + 10) + 16 * i) )
        CSoundSystem::StopSample(this, *(_DWORD *)(*((_DWORD *)this + 10) + 16 * i));
    }
  }
  return result;
}


// address=[0x2fdae10]
// Decompiled from CSoundSystem *__thiscall CSoundSystem::PausePlayback(CSoundSystem *this)
void  CSoundSystem::PausePlayback(void) {
  
  CSoundSystem *result; // eax
  int i; // [esp+4h] [ebp-4h]
  int j; // [esp+4h] [ebp-4h]

  result = this;
  if ( !*((_DWORD *)this + 9) )
    return result;
  if ( *((_DWORD *)this + 10) )
  {
    for ( i = 0; i < *((_DWORD *)this + 2); ++i )
    {
      if ( *(_DWORD *)(*((_DWORD *)this + 10) + 16 * i + 8) )
        AIL_stop_sample(*(_DWORD *)(*((_DWORD *)this + 10) + 16 * i + 8));
    }
  }
  result = this;
  if ( *((_DWORD *)this + 11) )
  {
    for ( j = 0; ; ++j )
    {
      result = (CSoundSystem *)j;
      if ( j >= *((_DWORD *)this + 1) )
        break;
      if ( *(_DWORD *)(*((_DWORD *)this + 11) + 16 * j + 8) )
        AIL_pause_stream(*(_DWORD *)(*((_DWORD *)this + 11) + 16 * j + 8), 1);
    }
  }
  return result;
}


// address=[0x2fdaed0]
// Decompiled from CSoundSystem *__thiscall CSoundSystem::ResumePlayback(CSoundSystem *this)
void  CSoundSystem::ResumePlayback(void) {
  
  CSoundSystem *result; // eax
  int i; // [esp+4h] [ebp-4h]
  int j; // [esp+4h] [ebp-4h]

  result = this;
  if ( !*((_DWORD *)this + 9) )
    return result;
  if ( *((_DWORD *)this + 10) )
  {
    for ( i = 0; i < *((_DWORD *)this + 2); ++i )
    {
      if ( *(_DWORD *)(*((_DWORD *)this + 10) + 16 * i + 8) )
        AIL_resume_sample(*(_DWORD *)(*((_DWORD *)this + 10) + 16 * i + 8));
    }
  }
  result = this;
  if ( *((_DWORD *)this + 11) )
  {
    for ( j = 0; ; ++j )
    {
      result = (CSoundSystem *)j;
      if ( j >= *((_DWORD *)this + 1) )
        break;
      if ( *(_DWORD *)(*((_DWORD *)this + 11) + 16 * j + 8) )
        AIL_pause_stream(*(_DWORD *)(*((_DWORD *)this + 11) + 16 * j + 8), 0);
    }
  }
  return result;
}


// address=[0x2fdaf90]
// Decompiled from int __thiscall CSoundSystem::InitPlaylist(CSoundSystem *this, int a2, int a3)
void  CSoundSystem::InitPlaylist(int,int) {
  
  if ( (a3 < 0 || a2 >= *((_DWORD *)this + 15))
    && BBSupportDbgReport(2, "SoundSystem.cpp", 1150, "(_iTimesToPlay >= 0) && (_iListID < m_iPlaylistNumber)") == 1 )
  {
    __debugbreak();
  }
  return CPlaylist::Init((CPlaylist *)(*((_DWORD *)this + 14) + 48 * a2), a3);
}


// address=[0x2fdaff0]
// Decompiled from char __thiscall CSoundSystem::AddTitleToPlaylist(_DWORD *this, int a2, int a3, int a4)
bool  CSoundSystem::AddTitleToPlaylist(int,std::string const *,int) {
  
  if ( !this[14] )
    return 0;
  if ( (!a3 || a2 >= this[15])
    && BBSupportDbgReport(2, "SoundSystem.cpp", 1170, "_pstrTitle && (_iListID < m_iPlaylistNumber )") == 1 )
  {
    __debugbreak();
  }
  CPlaylist::AddTitle((_DWORD *)(this[14] + 48 * a2), a3, a4);
  return 1;
}


// address=[0x2fdb060]
// Decompiled from int __stdcall CSoundSystem::LoopStreamCB(int a1)
static void __stdcall CSoundSystem::LoopStreamCB(struct _STREAM *) {
  
  return AIL_start_stream(a1);
}


// address=[0x2fdb080]
// Decompiled from int __stdcall CSoundSystem::LoopSampleCB(struct _SAMPLE *a1)
static void __stdcall CSoundSystem::LoopSampleCB(struct _SAMPLE *) {
  
  int result; // eax

  if ( !g_pcSoundSystem )
    return AIL_start_sample(a1);
  result = CSoundSystem::GetSampleID((CSoundSystem *)g_pcSoundSystem, a1);
  if ( result )
    return AIL_start_sample(a1);
  return result;
}


// address=[0x2fdb0c0]
// Decompiled from _DWORD *__thiscall CSoundSystem::CreatePlaylists(CSoundSystem *this, unsigned int a2)
void  CSoundSystem::CreatePlaylists(int) {
  
  int v2; // ecx
  _DWORD *result; // eax
  _DWORD *v4; // [esp+14h] [ebp-28h]
  void (__thiscall ***v5)(_DWORD, int); // [esp+24h] [ebp-18h]
  _DWORD *v7; // [esp+2Ch] [ebp-10h]

  if ( *((_DWORD *)this + 14) )
  {
    v5 = (void (__thiscall ***)(_DWORD, int))*((_DWORD *)this + 14);
    if ( v5 )
    {
      if ( *(v5 - 1) )
        (**v5)(v5, 3);
      else
        operator delete[](v5 - 1);
    }
  }
  *((_DWORD *)this + 15) = a2;
  v2 = (48 * (unsigned __int64)a2) >> 32 != 0 ? -1 : 48 * a2;
  v7 = operator new[](__CFADD__(v2, 4) ? -1 : v2 + 4);
  if ( v7 )
  {
    *v7 = a2;
    `eh vector constructor iterator'(
      v7 + 1,
      0x30u,
      a2,
      CPlaylist::CPlaylist,
      (void (__thiscall *)(void *))CPlaylist::~CPlaylist);
    v4 = v7 + 1;
  }
  else
  {
    v4 = 0;
  }
  result = v4;
  *((_DWORD *)this + 14) = v4;
  return result;
}


// address=[0x2fdb200]
// Decompiled from int __thiscall CSoundSystem::StartPlaylist(CSoundSystem *this, int a2, unsigned int a3)
unsigned int  CSoundSystem::StartPlaylist(int,int) {
  
  const char *ActiveTitle; // eax

  if ( a2 >= *((_DWORD *)this + 15)
    && BBSupportDbgReport(2, "SoundSystem.cpp", 1476, "_iListID < m_iPlaylistNumber") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 14) )
    return 0;
  CPlaylist::SetTitle((CPlaylist *)(*((_DWORD *)this + 14) + 48 * a2), 0);
  ActiveTitle = (const char *)CPlaylist::GetActiveTitle((CPlaylist *)(*((_DWORD *)this + 14) + 48 * a2));
  return CSoundSystem::PlayStream(this, ActiveTitle, a3, 0x40u, 0, a2);
}


// address=[0x2fdb280]
// Decompiled from unsigned int __thiscall CSoundSystem::ChangePlaylist(CSoundSystem *this, int a2, int a3)
unsigned int  CSoundSystem::ChangePlaylist(int,int) {
  
  int v4; // eax
  int v5; // [esp+0h] [ebp-20h]
  int PlayingTitleNum; // [esp+4h] [ebp-1Ch]
  int FadeInTime; // [esp+8h] [ebp-18h]
  int StreamIndex; // [esp+Ch] [ebp-14h]
  char *ActiveTitle; // [esp+10h] [ebp-10h]
  unsigned int TrackID; // [esp+14h] [ebp-Ch]
  unsigned int v11; // [esp+18h] [ebp-8h]

  if ( *((_DWORD *)this + 14) )
  {
    if ( a2 < *((_DWORD *)this + 15) )
    {
      TrackID = CPlaylist::GetTrackID((CPlaylist *)(*((_DWORD *)this + 14) + 48 * *((_DWORD *)this + 16)));
      v11 = 0;
      PlayingTitleNum = CPlaylist::GetPlayingTitleNum((CPlaylist *)(*((_DWORD *)this + 14) + 48 * *((_DWORD *)this + 16)));
      v5 = CPlaylist::GetPlayingTitleNum((CPlaylist *)(*((_DWORD *)this + 14) + 48 * a2));
      CPlaylist::SetTitle((CPlaylist *)(*((_DWORD *)this + 14) + 48 * a2), PlayingTitleNum);
      ActiveTitle = (char *)CPlaylist::GetActiveTitle((CPlaylist *)(*((_DWORD *)this + 14) + 48 * a2));
      if ( ActiveTitle )
        v11 = CSoundSystem::PlayStream(this, ActiveTitle, 0, 0x40u, 0, a2);
      else
        BBSupportTracePrintF(
          0,
          "SoundEngine : CSoundSystem::ChangePlaylist : Couldn't get valid filename of active title");
      if ( v11 )
      {
        if ( TrackID && TrackID != v11 )
        {
          StreamIndex = CSoundSystem::GetStreamIndex(this, TrackID);
          if ( StreamIndex >= 0 )
            *(_WORD *)(*((_DWORD *)this + 11) + 16 * StreamIndex + 14) = -1;
        }
        CPlaylist::ResumeOnLastPos((CPlaylist *)(*((_DWORD *)this + 14) + 48 * a2));
        *((_DWORD *)this + 16) = a2;
        v4 = CPlaylist::GetPlayingTitleNum((CPlaylist *)(*((_DWORD *)this + 14) + 48 * a2));
        FadeInTime = CPlaylist::GetFadeInTime((CPlaylist *)(*((_DWORD *)this + 14) + 48 * a2), v4);
        CSoundSystem::Fade(this, TrackID, 0, FadeInTime);
        CSoundSystem::Fade(this, v11, a3, FadeInTime);
        return v11;
      }
      else
      {
        CPlaylist::SetTitle((CPlaylist *)(*((_DWORD *)this + 14) + 48 * a2), v5);
        return 0;
      }
    }
    else
    {
      BBSupportTracePrintF(
        0,
        "SoundEngine : CSoundSystem::ChangePlaylist : ListID is bigger than number of playlists (ignore this msg, when pl"
        "aying own mp3s) : %d",
        a2);
      return 0;
    }
  }
  else
  {
    BBSupportTracePrintF(0, "SoundEngine : CSoundSystem::ChangePlaylist : No playlists defined");
    return 0;
  }
}


// address=[0x2fdb440]
// Decompiled from void __thiscall CSoundSystem::PlaylistTitleEnded(CSoundSystem *this, struct _STREAM *a2)
void  CSoundSystem::PlaylistTitleEnded(struct _STREAM *) {
  
  unsigned int v2; // [esp+4h] [ebp-18h]
  char *ActiveTitle; // [esp+8h] [ebp-14h]
  unsigned int v4; // [esp+Ch] [ebp-10h]
  int v5; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]

  for ( i = 0; i < *((_DWORD *)this + 1); ++i )
  {
    if ( *(struct _STREAM **)(*((_DWORD *)this + 11) + 16 * i + 8) == a2 )
    {
      v2 = *(_DWORD *)(*((_DWORD *)this + 11) + 16 * i);
      v5 = *(__int16 *)(*((_DWORD *)this + 11) + 16 * i + 14);
      if ( v5 == -1 )
      {
        v4 = 0;
      }
      else
      {
        CPlaylist::TitleEnded((CPlaylist *)(*((_DWORD *)this + 14) + 48 * v5));
        ActiveTitle = (char *)CPlaylist::GetActiveTitle((CPlaylist *)(*((_DWORD *)this + 14) + 48 * v5));
        if ( ActiveTitle )
          v4 = CSoundSystem::PlayStream(
                 this,
                 ActiveTitle,
                 *(__int16 *)(*((_DWORD *)this + 11) + 16 * i + 4),
                 *(__int16 *)(*((_DWORD *)this + 11) + 16 * i + 6),
                 0,
                 v5);
        else
          BBSupportTracePrintF(
            0,
            "SoundEngine : CSoundSystem::PlaylistTitleEnded : Couldn't get valid filename of active title");
      }
      *(_BYTE *)(*((_DWORD *)this + 11) + 16 * i + 12) = 0;
      *(_DWORD *)(*((_DWORD *)this + 11) + 16 * i) = 0;
      *(_WORD *)(*((_DWORD *)this + 11) + 16 * i + 14) = -1;
      if ( !v4 )
        return;
      *(_DWORD *)(*((_DWORD *)this + 11) + 16 * CSoundSystem::GetStreamIndex(this, v4)) = v2;
      CPlaylist::SetTrackID((CPlaylist *)(*((_DWORD *)this + 14) + 48 * v5), v2);
      return;
    }
  }
}


// address=[0x2fdb5b0]
// Decompiled from int __thiscall CSoundSystem::SampleEnded(CSoundSystem *this, struct _SAMPLE *a2)
void  CSoundSystem::SampleEnded(struct _SAMPLE *) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < *((_DWORD *)this + 2); ++i )
  {
    if ( *(struct _SAMPLE **)(*((_DWORD *)this + 10) + 16 * i + 8) == a2 )
      *(_DWORD *)(*((_DWORD *)this + 10) + 16 * i) = 0;
    result = i + 1;
  }
  return result;
}


// address=[0x2fdb610]
// Decompiled from int __thiscall CSoundSystem::ChangeStreamVolume(CSoundSystem *this, int a2)
void  CSoundSystem::ChangeStreamVolume(int) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < *((_DWORD *)this + 1); ++i )
  {
    if ( *(_DWORD *)(*((_DWORD *)this + 11) + 16 * i + 8) )
    {
      if ( a2 )
      {
        if ( !*(_WORD *)(*((_DWORD *)this + 11) + 16 * i + 4) )
          AIL_pause_stream(*(_DWORD *)(*((_DWORD *)this + 11) + 16 * i + 8), 0);
      }
      else
      {
        AIL_pause_stream(*(_DWORD *)(*((_DWORD *)this + 11) + 16 * i + 8), 1);
      }
      *(_WORD *)(*((_DWORD *)this + 11) + 16 * i + 4) = a2;
      AIL_set_stream_volume(*(_DWORD *)(*((_DWORD *)this + 11) + 16 * i + 8), a2);
    }
    result = i + 1;
  }
  return result;
}


// address=[0x2fdb6e0]
// Decompiled from CSoundSystem *__thiscall CSoundSystem::ChangeSoundVolume(CSoundSystem *this, int a2)
void  CSoundSystem::ChangeSoundVolume(int) {
  
  CSoundSystem *result; // eax
  int i; // [esp+4h] [ebp-4h]

  if ( !a2 )
    return CSoundSystem::StopSounds(this);
  for ( i = 0; i < *((_DWORD *)this + 1); ++i )
  {
    if ( *(_DWORD *)(*((_DWORD *)this + 10) + 16 * i + 8) )
    {
      AIL_set_sample_volume(*(_DWORD *)(*((_DWORD *)this + 10) + 16 * i + 8), a2);
      *(_WORD *)(*((_DWORD *)this + 10) + 16 * i + 4) = a2;
    }
    result = (CSoundSystem *)(i + 1);
  }
  return result;
}


// address=[0x2fdb770]
// Decompiled from int __thiscall CSoundSystem::GetDigitalDriver(CSoundSystem *this)
unsigned int  CSoundSystem::GetDigitalDriver(void) {
  
  return *((_DWORD *)this + 9);
}


// address=[0x2fdb790]
// Decompiled from int __thiscall CSoundSystem::GetSamplingRate(CSoundSystem *this)
int  CSoundSystem::GetSamplingRate(void) {
  
  return *((_DWORD *)this + 4);
}


// address=[0x2fdb7b0]
// Decompiled from int __thiscall CSoundSystem::GetHWFormat(pairNode *this)
int  CSoundSystem::GetHWFormat(void) {
  
  return *((_DWORD *)this + 3);
}


// address=[0x2fdb7d0]
// Decompiled from bool __thiscall CSoundSystem::IsRunning(CSoundSystem *this, unsigned int a2)
bool  CSoundSystem::IsRunning(unsigned int) {
  
  return (int)CSoundSystem::GetStreamIndex(this, a2) >= 0 || CSoundSystem::GetSoundIndex(this, a2) != -1;
}


// address=[0x2fdb820]
// Decompiled from int __thiscall CSoundSystem::EnumSoundCards(CSoundSystem *this)
int  CSoundSystem::EnumSoundCards(void) {
  
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = -1;
  DirectSoundEnumerateA(SoundEnumCallback, 0);
  return *((_DWORD *)this + 6);
}


// address=[0x2fdb860]
// Decompiled from int __thiscall CSoundSystem::GetSoundCardName(_DWORD *this, int a2, int a3)
std::string  CSoundSystem::GetSoundCardName(int) {
  
  if ( (a3 >= this[6] || a3 < 0)
    && BBSupportDbgReport(2, "SoundSystem.cpp", 1842, "(_iIdx<m_iSoundCards ) &&( _iIdx>=0 )") == 1 )
  {
    __debugbreak();
  }
  std::string::string(this[13] + 32 * a3 + 4);
  return a2;
}


// address=[0x2fdb8d0]
// Decompiled from CSoundSystem *__thiscall CSoundSystem::SetSoundCard(CSoundSystem *this, int a2)
void  CSoundSystem::SetSoundCard(int) {
  
  CSoundSystem *result; // eax

  if ( (a2 >= *((_DWORD *)this + 6) || a2 < 0)
    && BBSupportDbgReport(2, "SoundSystem.cpp", 1853, "(_iIdx<m_iSoundCards ) &&( _iIdx>=0 )") == 1 )
  {
    __debugbreak();
  }
  result = this;
  *((_DWORD *)this + 7) = a2;
  return result;
}


// address=[0x2fdb920]
// Decompiled from void *__thiscall CSoundSystem::AddSoundCard(CSoundSystem *this, struct _GUID *a2, char *Str)
void  CSoundSystem::AddSoundCard(struct _GUID *,char const *) {
  
  int v3; // ecx
  _DWORD *v5; // [esp+10h] [ebp-18h]
  unsigned int v6; // [esp+18h] [ebp-10h]
  _DWORD *v7; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]

  v6 = ++*((_DWORD *)this + 6);
  v3 = (unsigned __int64)v6 >> 27 != 0 ? -1 : 32 * v6;
  v7 = operator new[](__CFADD__(v3, 4) ? -1 : v3 + 4);
  if ( v7 )
  {
    *v7 = v6;
    `eh vector constructor iterator'(
      v7 + 1,
      0x20u,
      v6,
      CSoundSystem::SSoundCardData::SSoundCardData,
      CSoundSystem::SSoundCardData::~SSoundCardData);
    v5 = v7 + 1;
  }
  else
  {
    v5 = 0;
  }
  if ( *((_DWORD *)this + 13) )
  {
    for ( i = 0; i < *((_DWORD *)this + 6) - 1; ++i )
    {
      v5[8 * i] = *(_DWORD *)(*((_DWORD *)this + 13) + 32 * i);
      std::string::operator=(*((_DWORD *)this + 13) + 32 * i + 4);
    }
    if ( *((_DWORD *)this + 13) )
      CSoundSystem::SSoundCardData::`vector deleting destructor'(*((CSoundSystem::SSoundCardData **)this + 13), 3u);
  }
  *((_DWORD *)this + 13) = v5;
  *(_DWORD *)(*((_DWORD *)this + 13) + 32 * (*((_DWORD *)this + 6) - 1)) = a2;
  return std::string::operator=((void *)(*((_DWORD *)this + 13) + 32 * (*((_DWORD *)this + 6) - 1) + 4), Str);
}


// address=[0x2fdba90]
// Decompiled from int __thiscall CSoundSystem::SkipTitle(CPlaylist **this)
void  CSoundSystem::SkipTitle(void) {
  
  return CPlaylist::SkipTitle(this[14]);
}


// address=[0x2fd9280]
// Decompiled from char __thiscall CSoundSystem::InitOutputDriver(CSoundSystem *this)
bool  CSoundSystem::InitOutputDriver(void) {
  
  const char *error; // eax
  int v3; // [esp+0h] [ebp-2Ch]
  __int16 v4; // [esp+4h] [ebp-28h]
  __int16 v5; // [esp+8h] [ebp-24h]
  __int16 v6; // [esp+Ch] [ebp-20h]
  __int16 v7; // [esp+10h] [ebp-1Ch]
  _WORD v9[2]; // [esp+18h] [ebp-14h] BYREF
  int v10; // [esp+1Ch] [ebp-10h]
  int v11; // [esp+20h] [ebp-Ch]
  __int16 v12; // [esp+24h] [ebp-8h]
  __int16 v13; // [esp+26h] [ebp-6h]

  AIL_set_preference(15, 0);
  v9[0] = 1;
  if ( (*((_DWORD *)this + 3) & 2) != 0 )
    v7 = 2;
  else
    v7 = 1;
  v9[1] = v7;
  v10 = *((_DWORD *)this + 4);
  if ( (*((_DWORD *)this + 3) & 1) != 0 )
    v6 = 2;
  else
    v6 = 1;
  if ( (*((_DWORD *)this + 3) & 2) != 0 )
    v5 = 2;
  else
    v5 = 1;
  v12 = v5 * v6;
  v11 = *((_DWORD *)this + 4) * (unsigned __int16)(v5 * v6);
  if ( (*((_DWORD *)this + 3) & 1) != 0 )
    v4 = 16;
  else
    v4 = 8;
  v13 = v4;
  if ( *((int *)this + 7) >= 0 )
    v3 = AIL_waveOutOpen((char *)this + 36, 0, *(_DWORD *)(*((_DWORD *)this + 13) + 32 * *((_DWORD *)this + 7)), v9);
  else
    v3 = AIL_waveOutOpen((char *)this + 36, 0, -1, v9);
  if ( !v3 )
    return 1;
  error = (const char *)AIL_last_error();
  BBSupportTracePrintF(0, "SoundEngine : CSoundSystem::InitOutputDriver : %s ", error);
  *((_DWORD *)this + 9) = 0;
  return 0;
}


// address=[0x2fd93d0]
// Decompiled from CSoundSystem *__thiscall CSoundSystem::AllocateSampleHandles(CSoundSystem *this)
void  CSoundSystem::AllocateSampleHandles(void) {
  
  CSoundSystem *result; // eax
  int i; // [esp+Ch] [ebp-8h]
  int j; // [esp+Ch] [ebp-8h]
  int k; // [esp+Ch] [ebp-8h]

  CSoundSystem::FreeMemory(this);
  *((_DWORD *)this + 10) = operator new[](16 * *((_DWORD *)this + 2));
  for ( i = 0; i < *((_DWORD *)this + 2); ++i )
  {
    *(_DWORD *)(*((_DWORD *)this + 10) + 16 * i + 8) = AIL_allocate_sample_handle(*((_DWORD *)this + 9));
    *(_DWORD *)(*((_DWORD *)this + 10) + 16 * i + 12) = 0;
    *(_DWORD *)(*((_DWORD *)this + 10) + 16 * i) = -1;
  }
  *((_DWORD *)this + 11) = operator new[](16 * *((_DWORD *)this + 1));
  for ( j = 0; j < *((_DWORD *)this + 1); ++j )
  {
    *(_DWORD *)(*((_DWORD *)this + 11) + 16 * j + 8) = 0;
    *(_DWORD *)(*((_DWORD *)this + 11) + 16 * j) = -1;
    *(_WORD *)(*((_DWORD *)this + 11) + 16 * j + 14) = -1;
  }
  *((_DWORD *)this + 12) = operator new[](4 * (*((_DWORD *)this + 1) + *((_DWORD *)this + 2)));
  for ( k = 0; ; ++k )
  {
    result = this;
    if ( k >= *((_DWORD *)this + 1) + *((_DWORD *)this + 2) )
      break;
    *(_DWORD *)(*((_DWORD *)this + 12) + 4 * k) = 0;
  }
  return result;
}


// address=[0x2fd9560]
// Decompiled from int __thiscall CSoundSystem::GetFreeStreamHandle(CSoundSystem *this)
int  CSoundSystem::GetFreeStreamHandle(void) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < *((_DWORD *)this + 1); ++i )
  {
    if ( !*(_DWORD *)(*((_DWORD *)this + 11) + 16 * i + 8) )
      return i;
  }
  return -1;
}


// address=[0x2fd95b0]
// Decompiled from int __thiscall CSoundSystem::GetFreeSoundHandle(CSoundSystem *this)
int  CSoundSystem::GetFreeSoundHandle(void) {
  
  int v2; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    if ( i >= *((_DWORD *)this + 2) )
      return -1;
    v2 = AIL_sample_status(*(_DWORD *)(*((_DWORD *)this + 10) + 16 * i + 8));
    if ( v2 == 2 || v2 == 8 || v2 == 1 )
      break;
  }
  if ( !*(_DWORD *)(*((_DWORD *)this + 10) + 16 * i + 12) )
    return i;
  AIL_mem_free_lock(*(_DWORD *)(*((_DWORD *)this + 10) + 16 * i + 12));
  *(_DWORD *)(*((_DWORD *)this + 10) + 16 * i + 12) = 0;
  return i;
}


// address=[0x2fd9660]
// Decompiled from CSoundSystem *__thiscall CSoundSystem::FreeMemory(void **this)
void  CSoundSystem::FreeMemory(void) {
  
  CSoundSystem *result; // eax
  int i; // [esp+10h] [ebp-8h]
  int j; // [esp+10h] [ebp-8h]
  int k; // [esp+10h] [ebp-8h]

  result = (CSoundSystem *)this;
  if ( this[10] )
  {
    for ( i = 0; i < (int)this[2]; ++i )
    {
      if ( *((_DWORD *)this[10] + 4 * i + 3) )
      {
        AIL_mem_free_lock(*((_DWORD *)this[10] + 4 * i + 3));
        *((_DWORD *)this[10] + 4 * i + 3) = 0;
      }
      if ( *((_DWORD *)this[10] + 4 * i + 2) )
      {
        AIL_release_sample_handle(*((_DWORD *)this[10] + 4 * i + 2));
        *((_DWORD *)this[10] + 4 * i + 2) = 0;
      }
    }
    operator delete[](this[10]);
    result = (CSoundSystem *)this;
    this[10] = 0;
  }
  if ( this[11] )
  {
    for ( j = 0; j < (int)this[1]; ++j )
    {
      if ( *((_DWORD *)this[11] + 4 * j + 2) )
      {
        AIL_close_stream(*((_DWORD *)this[11] + 4 * j + 2));
        *((_DWORD *)this[11] + 4 * j + 2) = 0;
      }
    }
    operator delete[](this[11]);
    result = (CSoundSystem *)this;
    this[11] = 0;
  }
  if ( !this[12] )
    return result;
  for ( k = 0; k < (int)this[2] + (int)this[1]; ++k )
  {
    if ( *((_DWORD *)this[12] + k) )
    {
      operator delete(*((void **)this[12] + k));
      *((_DWORD *)this[12] + k) = 0;
    }
  }
  result = (CSoundSystem *)operator delete[](this[12]);
  this[12] = 0;
  return result;
}


// address=[0x2fd9850]
// Decompiled from int __thiscall CSoundSystem::GetSoundIndex(CSoundSystem *this, unsigned int a2)
int  CSoundSystem::GetSoundIndex(unsigned int) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < *((_DWORD *)this + 2); ++i )
  {
    if ( *(_DWORD *)(*((_DWORD *)this + 10) + 16 * i) == a2
      && AIL_sample_status(*(_DWORD *)(*((_DWORD *)this + 10) + 16 * i + 8)) == 4 )
    {
      return i;
    }
  }
  return -1;
}


// address=[0x2fd98c0]
// Decompiled from int __thiscall CSoundSystem::GetStreamIndex(CSoundSystem *this, unsigned int a2)
int  CSoundSystem::GetStreamIndex(unsigned int) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < *((_DWORD *)this + 1); ++i )
  {
    if ( *(_DWORD *)(*((_DWORD *)this + 11) + 16 * i) == a2
      && (AIL_stream_status(*(_DWORD *)(*((_DWORD *)this + 11) + 16 * i + 8)) == 4
       || AIL_stream_status(*(_DWORD *)(*((_DWORD *)this + 11) + 16 * i + 8)) == 2) )
    {
      return i;
    }
  }
  return -1;
}


// address=[0x2fd9950]
// Decompiled from CSoundSystem *__fastcall CSoundSystem::UpdateFades(CSoundSystem *this)
void  CSoundSystem::UpdateFades(void) {
  
  CSoundSystem *result; // eax
  int StreamIndex; // [esp+Ch] [ebp-10h]
  int SoundIndex; // [esp+Ch] [ebp-10h]
  int v4; // [esp+10h] [ebp-Ch]
  CSoundSystem *i; // [esp+14h] [ebp-8h]

  result = this;
  if ( *((_DWORD *)this + 12) )
  {
    for ( i = 0; ; i = (CSoundSystem *)((char *)i + 1) )
    {
      result = (CSoundSystem *)(*((_DWORD *)this + 1) + *((_DWORD *)this + 2));
      if ( (int)i >= (int)result )
        break;
      if ( *(_DWORD *)(*((_DWORD *)this + 12) + 4 * (_DWORD)i) )
      {
        *(double *)(*(_DWORD *)(*((_DWORD *)this + 12) + 4 * (_DWORD)i) + 8) = *(double *)(*(_DWORD *)(*((_DWORD *)this + 12) + 4 * (_DWORD)i)
                                                                                         + 8)
                                                                             + *(double *)(*(_DWORD *)(*((_DWORD *)this + 12) + 4 * (_DWORD)i)
                                                                                         + 24);
        v4 = (int)*(double *)(*(_DWORD *)(*((_DWORD *)this + 12) + 4 * (_DWORD)i) + 8);
        if ( v4 >= 0 )
        {
          if ( v4 > 127 )
            v4 = 127;
        }
        else
        {
          v4 = 0;
        }
        StreamIndex = CSoundSystem::GetStreamIndex(this, **(_DWORD **)(*((_DWORD *)this + 12) + 4 * (_DWORD)i));
        if ( StreamIndex < 0 )
        {
          SoundIndex = CSoundSystem::GetSoundIndex(this, **(_DWORD **)(*((_DWORD *)this + 12) + 4 * (_DWORD)i));
          if ( SoundIndex < 0 )
          {
            operator delete(*(void **)(*((_DWORD *)this + 12) + 4 * (_DWORD)i));
            result = i;
            *(_DWORD *)(*((_DWORD *)this + 12) + 4 * (_DWORD)i) = 0;
            return result;
          }
          AIL_set_sample_volume(*(_DWORD *)(*((_DWORD *)this + 10) + 16 * SoundIndex + 8), v4);
          *(_WORD *)(*((_DWORD *)this + 10) + 16 * SoundIndex + 4) = v4;
        }
        else
        {
          AIL_set_stream_volume(*(_DWORD *)(*((_DWORD *)this + 11) + 16 * StreamIndex + 8), v4);
          *(_WORD *)(*((_DWORD *)this + 11) + 16 * StreamIndex + 4) = v4;
        }
        if ( *(double *)(*(_DWORD *)(*((_DWORD *)this + 12) + 4 * (_DWORD)i) + 24) > 0.0 )
        {
          if ( *(double *)(*(_DWORD *)(*((_DWORD *)this + 12) + 4 * (_DWORD)i) + 8) >= *(double *)(*(_DWORD *)(*((_DWORD *)this + 12) + 4 * (_DWORD)i)
                                                                                                 + 16) )
          {
            operator delete(*(void **)(*((_DWORD *)this + 12) + 4 * (_DWORD)i));
            *(_DWORD *)(*((_DWORD *)this + 12) + 4 * (_DWORD)i) = 0;
          }
        }
        else if ( *(double *)(*(_DWORD *)(*((_DWORD *)this + 12) + 4 * (_DWORD)i) + 16) >= *(double *)(*(_DWORD *)(*((_DWORD *)this + 12) + 4 * (_DWORD)i) + 8) )
        {
          CSoundSystem::StopSample(this, **(_DWORD **)(*((_DWORD *)this + 12) + 4 * (_DWORD)i));
          operator delete(*(void **)(*((_DWORD *)this + 12) + 4 * (_DWORD)i));
          *(_DWORD *)(*((_DWORD *)this + 12) + 4 * (_DWORD)i) = 0;
        }
      }
    }
  }
  return result;
}


