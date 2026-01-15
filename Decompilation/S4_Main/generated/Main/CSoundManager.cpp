#include "CSoundManager.h"

// Definitions for class CSoundManager

// address=[0x149bd80]
// Decompiled from CSoundManager *__thiscall CSoundManager::CSoundManager(CSoundManager *this)
 CSoundManager::CSoundManager(void) {
  
  int i; // [esp+0h] [ebp-8h]

  String::String((CSoundManager *)((char *)this + 444));
  *(_DWORD *)this = 64;
  *((_DWORD *)this + 3) = -2;
  *((_DWORD *)this + 118) = 0;
  *((_DWORD *)this + 119) = 0;
  *((_DWORD *)this + 120) = 0;
  *((_DWORD *)this + 2) = 100;
  *((_DWORD *)this + 1) = 100;
  *((_DWORD *)this + 6) = 100;
  *((_DWORD *)this + 5) = 100;
  *((_DWORD *)this + 4) = 100;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  for ( i = 0; i < 101; ++i )
    *((float *)this + i + 10) = (float)i * 0.0099999998;
  return this;
}


// address=[0x149be60]
// Decompiled from void __thiscall CSoundManager::~CSoundManager(CSoundManager *this)
 CSoundManager::~CSoundManager(void) {
  
  int v1; // [esp+18h] [ebp-18h]

  if ( g_pSoundEngine )
    ISoundEngine::StopPlayback((ISoundEngine *)g_pSoundEngine);
  if ( *((_DWORD *)this + 119) )
  {
    (*(void (__thiscall **)(int, const char *, int))(*(_DWORD *)(*((_DWORD *)this + 119)
                                                               + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 119) + 72)
                                                                           + 4)
                                                               + 72)
                                                   + 32))(
      *((_DWORD *)this + 119) + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 119) + 72) + 4) + 72,
      "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\FileEx.h",
      146);
    operator delete[](*((void **)this + 118));
    *((_DWORD *)this + 118) = 0;
    v1 = *((_DWORD *)this + 119);
    if ( v1 )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v1 + 24))(v1, 1);
    *((_DWORD *)this + 119) = 0;
  }
  if ( *((_DWORD *)this + 7) )
    operator delete[](*((void **)this + 7));
  if ( *((_DWORD *)this + 8) )
    operator delete[](*((void **)this + 8));
  String::~String((CSoundManager *)((char *)this + 444));
}


// address=[0x149bfb0]
// Decompiled from char __thiscall CSoundManager::OpenSoundFiles(CSoundManager *this)
bool  CSoundManager::OpenSoundFiles(void) {
  
  int v1; // eax
  const char *SoundName; // eax
  int v3; // eax
  _DWORD v5[5]; // [esp+0h] [ebp-C8h] BYREF
  void *v6; // [esp+14h] [ebp-B4h]
  void *v7; // [esp+18h] [ebp-B0h]
  CFileEx *v8; // [esp+1Ch] [ebp-ACh]
  void *v9; // [esp+20h] [ebp-A8h]
  unsigned int v10; // [esp+24h] [ebp-A4h]
  CFileEx *v11; // [esp+28h] [ebp-A0h]
  void *C; // [esp+2Ch] [ebp-9Ch]
  size_t ElementCount; // [esp+30h] [ebp-98h]
  int v14; // [esp+34h] [ebp-94h]
  int v15; // [esp+38h] [ebp-90h]
  char v16; // [esp+3Dh] [ebp-8Bh]
  unsigned int i; // [esp+40h] [ebp-88h]
  CSoundManager *v18; // [esp+44h] [ebp-84h]
  _DWORD v19[26]; // [esp+48h] [ebp-80h] BYREF
  _DWORD v20[3]; // [esp+B0h] [ebp-18h] BYREF
  int v21; // [esp+C4h] [ebp-4h]

  v20[2] = v5;
  v18 = this;
  CFileEx::CFileEx((CFileEx *)v19, 1);
  v21 = 1;
  CFileEx::Open(v20, (wchar_t *)L"snd\\0.sil", 6, 0, UNUSED_ARG(), UNUSED_ARG());
  v21 = 0;
  ElementCount = CFileEx::Size(v19);
  *((_DWORD *)v18 + 9) = (ElementCount - 20) >> 2;
  if ( *((_DWORD *)v18 + 9) != dword_3737E6C[324] + *(&dword_3737E68 + 324) )
    CTrace::Print(
      "CSoundManager::OpenSoundFiles : Number of items differs read %d expected %d",
      *((_DWORD *)v18 + 9),
      dword_3737E6C[324] + *(&dword_3737E68 + 324));
  v9 = operator new[](4 * (ElementCount >> 2));
  *((_DWORD *)v18 + 118) = v9;
  v5[4] = CFileEx::Read(v20, *((void **)v18 + 118), 1, ElementCount, "Main\\SoundManager.cpp", 958);
  C = operator new(0x6Cu);
  LOBYTE(v21) = 3;
  if ( C )
    v11 = CFileEx::CFileEx((CFileEx *)C, 1);
  else
    v11 = 0;
  v8 = v11;
  *((_DWORD *)v18 + 119) = v11;
  LOBYTE(v21) = 4;
  v15 = *((_DWORD *)v18 + 119);
  (**(void (__thiscall ***)(int, const wchar_t *, int, int, const char *, int))(v15
                                                                              + *(_DWORD *)(*(_DWORD *)(v15 + 72) + 4)
                                                                              + 72))(
    v15 + *(_DWORD *)(*(_DWORD *)(v15 + 72) + 4) + 72,
    L"snd\\0.snd",
    6,
    1,
    "Main\\SoundManager.cpp",
    971);
  v21 = 0;
  v7 = operator new[](4 * *((_DWORD *)v18 + 9));
  *((_DWORD *)v18 + 7) = v7;
  v6 = operator new[](4 * *((_DWORD *)v18 + 9));
  *((_DWORD *)v18 + 8) = v6;
  v14 = *((_DWORD *)v18 + 119);
  v1 = (*(int (__thiscall **)(int))(*(_DWORD *)(v14 + *(_DWORD *)(*(_DWORD *)(v14 + 72) + 4) + 72) + 12))(v14 + *(_DWORD *)(*(_DWORD *)(v14 + 72) + 4) + 72);
  *((_DWORD *)v18 + 120) = v1;
  for ( i = 0; i < *((_DWORD *)v18 + 9); ++i )
  {
    v10 = *(_DWORD *)(*((_DWORD *)v18 + 118) + 4 * i + 20);
    if ( v10 )
      *(_DWORD *)(*((_DWORD *)v18 + 7) + 4 * i) = *((_DWORD *)v18 + 120) + 4 * (v10 >> 2);
    else
      *(_DWORD *)(*((_DWORD *)v18 + 7) + 4 * i) = 0;
    SoundName = CS4DefineNames::GetSoundName(i);
    v3 = ((int (__thiscall *)(CConfigManager *, const char *, const char *, int))g_pCfgMgr->GetIntValue)(
           g_pCfgMgr,
           "SOUND_VOLUMES",
           SoundName,
           100);
    *(_DWORD *)(*((_DWORD *)v18 + 8) + 4 * i) = v3;
  }
  v16 = 1;
  v21 = -1;
  CFileEx::~CFileEx(v19);
  return v16;
}


// address=[0x149c410]
// Decompiled from int __thiscall CSoundManager::PlaySoundFX(_DWORD *this, int a2)
unsigned int  CSoundManager::PlaySoundFX(enum SIV_SOUNDS) {
  
  if ( a2 >= 109 && BBSupportDbgReport(2, "Main\\SoundManager.cpp", 240, "_iSoundID < SOUND_MAX") == 1 )
    __debugbreak();
  if ( a2 )
    return CSoundManager::PlaySoundFX(this, a2, 100, *this, 100, 0);
  else
    return 0;
}


// address=[0x149c470]
// Decompiled from int __thiscall CSoundManager::PlaySoundFXLooped(_DWORD *this, int a2)
unsigned int  CSoundManager::PlaySoundFXLooped(enum SIV_SOUNDS) {
  
  if ( a2 >= 109 && BBSupportDbgReport(2, "Main\\SoundManager.cpp", 256, "_iSoundID < SOUND_MAX") == 1 )
    __debugbreak();
  if ( a2 )
    return CSoundManager::PlaySoundFX(this, a2, 100, *this, 100, 1);
  else
    return 0;
}


// address=[0x149c4d0]
// Decompiled from unsigned int __thiscall CSoundManager::PlaySoundFX(  CSoundManager *this,  unsigned int a2,  int a3,  int a4,  int a5,  bool a6)
unsigned int  CSoundManager::PlaySoundFX(enum SIV_SOUNDS,int,int,int,bool) {
  
  const char *v7; // eax
  const char *SoundName; // eax
  unsigned int v9; // [esp+4h] [ebp-18h]
  int v10; // [esp+8h] [ebp-14h]
  unsigned int v11; // [esp+Ch] [ebp-10h]
  int v12; // [esp+10h] [ebp-Ch]
  _DWORD *v14; // [esp+18h] [ebp-4h]
  unsigned int *v15; // [esp+18h] [ebp-4h]

  if ( !a2 )
    return 0;
  if ( a2 < 0x6D )
  {
    if ( g_pSoundEngine )
    {
      if ( !dword_3737E6C[3 * a2]
        && BBSupportDbgReport(2, "Main\\SoundManager.cpp", 291, "g_sSoundLUT[_iSoundID].uNumSounds > 0") == 1 )
      {
        __debugbreak();
      }
      v11 = dword_3737E68[3 * a2] + j__rand() % (unsigned int)dword_3737E6C[3 * a2];
      if ( v11 <= *((_DWORD *)this + 9) )
      {
        v14 = *(_DWORD **)(*((_DWORD *)this + 7) + 4 * v11);
        if ( v14 )
        {
          v12 = CSoundManager::CalcFinalVolume(
                  this,
                  *((_DWORD *)this + 5),
                  *(_DWORD *)(*((_DWORD *)this + 8) + 4 * a2),
                  a3);
          v10 = *v14;
          v9 = v14[1];
          v15 = v14 + 2;
          if ( v10 == 1 )
          {
            return ISoundEngine::PlaySoundFromMemory((ISoundEngine *)g_pSoundEngine, v15, ".wav", v9, v12, a4, a5, a6);
          }
          else
          {
            SoundName = CS4DefineNames::GetSoundName(a2);
            CTrace::Print("CSoundManager::PlaySoundFX : Sound %s has unknown Type %d.", SoundName, v10);
            return 0;
          }
        }
        else
        {
          v7 = CS4DefineNames::GetSoundName(a2);
          CTrace::Print("CSoundManager::PlaySoundFX : Sound %s isn't mapped.", v7);
          return 0;
        }
      }
      else
      {
        if ( BBSupportDbgReportF(
               1,
               "Main\\SoundManager.cpp",
               295,
               "CSoundManager::PlaySoundFX(): Invalid sound id %i!",
               a2) == 1 )
          __debugbreak();
        return 0;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    if ( BBSupportDbgReportF(1, "Main\\SoundManager.cpp", 278, "CSoundManager::PlaySoundFX(): Invalid sound id %i!", a2) == 1 )
      __debugbreak();
    if ( BBSupportDbgReportF(1, "Main\\SoundManager.cpp", 280, "CSoundManager::PlaySoundFX(): Invalid sound id %i!", a2) == 1 )
      __debugbreak();
    return 0;
  }
}


// address=[0x149c6b0]
// Decompiled from int __thiscall CSoundManager::PlayEnvironmentSound(CSoundManager *this, int a2, int a3, int a4, unsigned __int8 a5)
unsigned int  CSoundManager::PlayEnvironmentSound(enum SIV_SOUNDS,int,int,bool) {
  
  int v6; // [esp+0h] [ebp-Ch] BYREF
  int v7; // [esp+4h] [ebp-8h] BYREF
  CSoundManager *v8; // [esp+8h] [ebp-4h]

  v8 = this;
  if ( !a2 )
    return 0;
  if ( a2 >= 109 && BBSupportDbgReport(2, "Main\\SoundManager.cpp", 197, "_iSoundID < SOUND_MAX") == 1 )
    __debugbreak();
  CSoundManager::CalcPanningAndVolume(v8, a3, a4, &v6, &v7);
  return CSoundManager::PlaySoundFX(v8, a2, v6, v7, 100, a5);
}


// address=[0x149c730]
// Decompiled from unsigned int __thiscall CSoundManager::PlaySoundFile(CSoundManager *this, const wchar_t *a2, int a3, int a4)
unsigned int  CSoundManager::PlaySoundFile(wchar_t const *,int,int) {
  
  if ( g_pSoundEngine )
    return ISoundEngine::PlaySoundFile((ISoundEngine *)g_pSoundEngine, a2, a3, a4);
  else
    return 0;
}


// address=[0x149c770]
// Decompiled from int __thiscall CSoundManager::PlayBackgroundMusic(CSoundManager *this, int a2, int a3, wchar_t *String)
unsigned int  CSoundManager::PlayBackgroundMusic(int,enum SIV_MUSICSTYLES,wchar_t const *) {
  
  if ( !g_pSoundEngine )
    return 0;
  if ( *((_DWORD *)this + 3) == a2 )
    return dword_3D89CCC;
  if ( String && a2 < 0 )
  {
    if ( !(unsigned __int8)CSoundManager::CreateDirPlaylist(String) )
      return 0;
    a3 = 0;
  }
  else if ( !CSoundManager::CreatePlaylists(this, a2, String) )
  {
    return 0;
  }
  *((_DWORD *)this + 3) = a2;
  dword_3D89CCC = ISoundEngine::StartPlaylist((ISoundEngine *)g_pSoundEngine, a3, *((_DWORD *)this + 1));
  return dword_3D89CCC;
}


// address=[0x149c810]
// Decompiled from int __stdcall CSoundManager::PlayDirectory(wchar_t *String)
unsigned int  CSoundManager::PlayDirectory(wchar_t const *) {
  
  return CSoundManager::PlayBackgroundMusic(-1, 0, String);
}


// address=[0x149c830]
// Decompiled from unsigned int __thiscall CSoundManager::ChangeMusicStyle(_DWORD *this, int a2)
unsigned int  CSoundManager::ChangeMusicStyle(enum SIV_MUSICSTYLES) {
  
  if ( g_pSoundEngine )
    return ISoundEngine::ChangePlaylist((ISoundEngine *)g_pSoundEngine, a2, this[1]);
  else
    return 0;
}


// address=[0x149c860]
// Decompiled from unsigned int __thiscall CSoundManager::FadeInSound(CSoundManager *this, signed int a2, int a3, int a4, int a5)
unsigned int  CSoundManager::FadeInSound(enum SIV_SOUNDS,int,int,int) {
  
  const char *SoundName; // eax
  unsigned int v7; // [esp+0h] [ebp-Ch]
  int v8; // [esp+4h] [ebp-8h]

  if ( !g_pSoundEngine )
    return 0;
  if ( a2 >= 109 && BBSupportDbgReport(2, "Main\\SoundManager.cpp", 876, "_iSoundID < SOUND_MAX") == 1 )
    __debugbreak();
  v7 = CSoundManager::PlaySoundFX(this, a2, a3, *(_DWORD *)this, 100, 1);
  if ( v7 )
  {
    v8 = CSoundManager::CalcFinalVolume(this, *((_DWORD *)this + 5), *(_DWORD *)(*((_DWORD *)this + 8) + 4 * a2), a4);
    if ( ISoundEngine::Fade((ISoundEngine *)g_pSoundEngine, v7, v8, a5) )
    {
      return v7;
    }
    else
    {
      CTrace::Print("CSounManager::FadeInSound : Failed to fade sound.");
      return 0;
    }
  }
  else
  {
    SoundName = CS4DefineNames::GetSoundName(a2);
    CTrace::Print("CSounManager::FadeInSound : Failed to play sound %s", SoundName);
    return 0;
  }
}


// address=[0x149c950]
// Decompiled from unsigned int __thiscall CSoundManager::CrossFade(CSoundManager *this, unsigned int a2, int a3, int a4, int a5)
unsigned int  CSoundManager::CrossFade(unsigned int,enum SIV_SOUNDS,int,int) {
  
  int v6; // eax
  unsigned int v7; // [esp+0h] [ebp-Ch]
  int v8; // [esp+4h] [ebp-8h]

  if ( !g_pSoundEngine )
    return 0;
  v7 = CSoundManager::PlaySoundFX(this, a3, 0, 64, 100, 1);
  if ( v7 )
  {
    ISoundEngine::Fade((ISoundEngine *)g_pSoundEngine, a2, 0, a5);
    v6 = ((int (__thiscall *)(CConfigManager *, const char *, char *, _DWORD))g_pCfgMgr->GetIntValue)(
           g_pCfgMgr,
           "SOUND_VOLUMES",
           (&off_3737164)[2 * a2],
           0);
    v8 = CSoundManager::CalcFinalVolume(this, *((_DWORD *)this + 5), v6, a4);
    ISoundEngine::Fade((ISoundEngine *)g_pSoundEngine, v7, v8, a5);
    return v7;
  }
  else
  {
    CTrace::Print("SoundManager::CrossFade : Failed to play new sound");
    return 0;
  }
}


// address=[0x149ca10]
// Decompiled from bool __stdcall CSoundManager::FadeOutSound(unsigned int a1, int a2, int a3)
bool  CSoundManager::FadeOutSound(unsigned int,int,int) {
  
  return g_pSoundEngine && ISoundEngine::Fade((ISoundEngine *)g_pSoundEngine, a1, a2, a3);
}


// address=[0x149ca50]
// Decompiled from void __thiscall CSoundManager::SetMusicVolume(CSoundManager *this, int a2)
void  CSoundManager::SetMusicVolume(int) {
  
  if ( g_pSoundEngine )
  {
    *((_DWORD *)this + 4) = a2;
    *((_DWORD *)this + 1) = a2 * *((_DWORD *)this + 6) / 100;
    if ( *((int *)this + 1) <= 127 )
    {
      if ( *((int *)this + 1) < 0 )
        *((_DWORD *)this + 1) = 0;
    }
    else
    {
      *((_DWORD *)this + 1) = 127;
    }
    ISoundEngine::ChangeStreamVolume((ISoundEngine *)g_pSoundEngine, *((_DWORD *)this + 1));
  }
}


// address=[0x149cad0]
// Decompiled from void __thiscall CSoundManager::SetSoundVolume(CSoundManager *this, int a2)
void  CSoundManager::SetSoundVolume(int) {
  
  if ( g_pSoundEngine )
  {
    *((_DWORD *)this + 5) = a2;
    *((_DWORD *)this + 2) = a2 * *((_DWORD *)this + 6) / 100;
    if ( *((int *)this + 2) <= 127 )
    {
      if ( *((int *)this + 2) < 0 )
        *((_DWORD *)this + 2) = 0;
    }
    else
    {
      *((_DWORD *)this + 2) = 127;
    }
    ISoundEngine::ChangeSoundVolume((ISoundEngine *)g_pSoundEngine, *((_DWORD *)this + 2));
  }
}


// address=[0x149cb50]
// Decompiled from void __thiscall CSoundManager::Mute(CSoundManager *this, bool a2)
void  CSoundManager::Mute(bool) {
  
  int v2; // [esp+4h] [ebp-8h]

  if ( g_pSoundEngine )
  {
    if ( a2 )
      v2 = 0;
    else
      v2 = 100;
    if ( v2 != *((_DWORD *)this + 6) )
    {
      *((_DWORD *)this + 6) = v2;
      CSoundManager::SetSoundVolume(this, *((_DWORD *)this + 5));
      CSoundManager::SetMusicVolume(this, *((_DWORD *)this + 4));
    }
  }
}


// address=[0x149cbc0]
// Decompiled from void __stdcall CSoundManager::PausePlayback(bool a1)
void  CSoundManager::PausePlayback(bool) {
  
  if ( g_pSoundEngine )
    ISoundEngine::PausePlayback((ISoundEngine *)g_pSoundEngine, a1);
}


// address=[0x149cbf0]
// Decompiled from CSoundManager *__thiscall CSoundManager::StopMusic(CSoundManager *this)
void  CSoundManager::StopMusic(void) {
  
  CSoundManager *result; // eax

  if ( g_pSoundEngine )
    ISoundEngine::StopStreams((ISoundEngine *)g_pSoundEngine);
  result = this;
  *((_DWORD *)this + 3) = -2;
  return result;
}


// address=[0x149cc20]
// Decompiled from void __thiscall CSoundManager::StopSounds(CSoundManager *this)
void  CSoundManager::StopSounds(void) {
  
  int i; // [esp+4h] [ebp-4h]

  if ( g_pSoundEngine )
  {
    for ( i = 0; i < 6; ++i )
    {
      if ( ISoundEngine::IsRunning((ISoundEngine *)g_pSoundEngine, dword_3D89C6C[3 * i]) )
        ISoundEngine::StopSample((ISoundEngine *)g_pSoundEngine, dword_3D89C6C[3 * i]);
    }
    ISoundEngine::StopPlayback((ISoundEngine *)g_pSoundEngine);
  }
}


// address=[0x149cc90]
// Decompiled from void __thiscall CSoundManager::StopSound(CSoundManager *this, unsigned int a2)
void  CSoundManager::StopSound(unsigned int) {
  
  if ( g_pSoundEngine )
    ISoundEngine::StopSample((ISoundEngine *)g_pSoundEngine, a2);
}


// address=[0x149ccc0]
// Decompiled from bool __thiscall CSoundManager::IsPlaying(CSoundManager *this, unsigned int a2)
bool  CSoundManager::IsPlaying(unsigned int) {
  
  return !g_pSoundEngine || ISoundEngine::IsRunning((ISoundEngine *)g_pSoundEngine, a2);
}


// address=[0x149cd00]
// Decompiled from void __thiscall CSoundManager::Update(CSoundManager *this)
void  CSoundManager::Update(void) {
  
  int OutputWidth; // eax
  int v2; // eax
  int Volume; // eax
  int v4; // [esp-Ch] [ebp-34h]
  CAIResourceData *v5; // [esp+0h] [ebp-28h]
  int v6; // [esp+4h] [ebp-24h]
  int v7; // [esp+8h] [ebp-20h]
  int v8; // [esp+Ch] [ebp-1Ch] BYREF
  int v9; // [esp+10h] [ebp-18h]
  CSoundManager *v10; // [esp+14h] [ebp-14h]
  Squares *v11; // [esp+18h] [ebp-10h] BYREF
  Squares *v12; // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp-8h] BYREF
  int i; // [esp+24h] [ebp-4h]

  v10 = this;
  if ( g_pSoundEngine )
  {
    v4 = IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine) >> 1;
    OutputWidth = IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
    IGfxEngine::GetClosestMapPoint((IGfxEngine *)g_pGfxEngine, OutputWidth >> 1, v4, (int *)&v11, (int *)&v12);
    v6 = Squares::XYToVW(v11);
    v7 = Squares::XYToVW(v12);
    v5 = CAIResourceMap::ResourceDataVW(v6, v7);
    CSoundManager::CalcPanningAndVolume(v10, v11, v12, &v13, &v8);
    if ( v13 < 5 )
      v13 = 0;
    for ( i = 0; i < 6; ++i )
    {
      v2 = CAIResourceData::Flags1(v5);
      if ( (dword_3D89C38[i] & v2) != 0 )
      {
        if ( ISoundEngine::IsRunning((ISoundEngine *)g_pSoundEngine, dword_3D89C6C[3 * i]) )
        {
          Volume = ISoundEngine::GetVolume((ISoundEngine *)g_pSoundEngine, dword_3D89C6C[3 * i]);
          if ( v13 <= Volume )
            byte_3D89C71[12 * i] = 0;
          if ( !byte_3D89C71[12 * i] )
          {
            ISoundEngine::ChangePan((ISoundEngine *)g_pSoundEngine, dword_3D89C6C[3 * i], v8);
            ISoundEngine::ChangeVolume((ISoundEngine *)g_pSoundEngine, dword_3D89C6C[3 * i], v13);
          }
        }
        else
        {
          v9 = CSoundManager::PlaySoundFX(v10, dword_3D89C50[i], 0, v8, 100, 1);
          if ( v9 <= 0 )
          {
            dword_3D89C6C[3 * i] = -1;
          }
          else
          {
            dword_3D89C6C[3 * i] = v9;
            ISoundEngine::Fade((ISoundEngine *)g_pSoundEngine, dword_3D89C6C[3 * i], v13, 500);
            byte_3D89C71[12 * i] = 1;
          }
        }
        byte_3D89C70[12 * i] = 0;
      }
      else if ( ISoundEngine::IsRunning((ISoundEngine *)g_pSoundEngine, dword_3D89C6C[3 * i]) && !byte_3D89C70[12 * i] )
      {
        ISoundEngine::Fade((ISoundEngine *)g_pSoundEngine, dword_3D89C6C[3 * i], 0, 500);
        byte_3D89C70[12 * i] = 1;
        byte_3D89C71[12 * i] = 0;
      }
      if ( !ISoundEngine::IsRunning((ISoundEngine *)g_pSoundEngine, dword_3D89C6C[3 * i]) )
      {
        ISoundEngine::StopSample((ISoundEngine *)g_pSoundEngine, dword_3D89C6C[3 * i]);
        byte_3D89C70[12 * i] = 0;
        byte_3D89C71[12 * i] = 0;
        dword_3D89C6C[3 * i] = -1;
      }
    }
  }
}


// address=[0x149b280]
// Decompiled from char __thiscall CSoundManager::CreatePlaylists(CSoundManager *this, int a2, const wchar_t *a3)
bool  CSoundManager::CreatePlaylists(int,wchar_t const *) {
  
  int i; // [esp+4h] [ebp-4h]

  if ( !g_pSoundEngine )
    return 0;
  CSoundManager::StopMusic(this);
  ISoundEngine::CreatePlaylists((ISoundEngine *)g_pSoundEngine, 6);
  if ( a2 >= 0 )
  {
    CSoundManager::LoadRaceTitles(this, a2, a3);
    CSoundManager::LoadRaceTitles(this, 5, a3);
  }
  else
  {
    for ( i = 0; i < 6; ++i )
      CSoundManager::LoadRaceTitles(this, i, a3);
  }
  return 1;
}


// address=[0x149b310]
// Decompiled from int __thiscall CSoundManager::CalcFinalVolume(CSoundManager *this, int a2, int a3, int a4)
int  CSoundManager::CalcFinalVolume(int,int,int) {
  
  int v5; // [esp+4h] [ebp-4h]

  v5 = (int)(float)((float)(a4 * a3 * a2 * *((_DWORD *)this + 6)) * 0.000001);
  if ( v5 > 127 )
    return 127;
  if ( v5 < 0 )
    return 0;
  return v5;
}


// address=[0x149b370]
// Decompiled from char __thiscall CSoundManager::LoadRaceTitles(CSoundManager *this, int a2, const wchar_t *a3)
bool  CSoundManager::LoadRaceTitles(int,wchar_t const *) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v7; // [esp-8h] [ebp-4A0h]
  int v8; // [esp-8h] [ebp-4A0h]
  _DWORD v9[5]; // [esp+0h] [ebp-498h] BYREF
  int v10; // [esp+14h] [ebp-484h]
  int v11; // [esp+18h] [ebp-480h]
  void *v12; // [esp+1Ch] [ebp-47Ch]
  void *v13; // [esp+20h] [ebp-478h]
  void *v14; // [esp+24h] [ebp-474h]
  int v15; // [esp+28h] [ebp-470h]
  int v16; // [esp+2Ch] [ebp-46Ch]
  void *v17; // [esp+30h] [ebp-468h]
  int v18; // [esp+34h] [ebp-464h]
  int v19; // [esp+38h] [ebp-460h]
  int j; // [esp+3Ch] [ebp-45Ch]
  int i; // [esp+40h] [ebp-458h]
  char v22; // [esp+45h] [ebp-453h]
  char v23; // [esp+46h] [ebp-452h]
  char v24; // [esp+47h] [ebp-451h]
  char v25[88]; // [esp+48h] [ebp-450h] BYREF
  _BYTE v26[28]; // [esp+A0h] [ebp-3F8h] BYREF
  int v27[7]; // [esp+BCh] [ebp-3DCh] BYREF
  int v28[7]; // [esp+D8h] [ebp-3C0h] BYREF
  int v29[7]; // [esp+F4h] [ebp-3A4h] BYREF
  int v30[7]; // [esp+110h] [ebp-388h] BYREF
  int v31[7]; // [esp+12Ch] [ebp-36Ch] BYREF
  _BYTE v32[72]; // [esp+148h] [ebp-350h] BYREF
  _BYTE v33[28]; // [esp+190h] [ebp-308h] BYREF
  _BYTE v34[28]; // [esp+1ACh] [ebp-2ECh] BYREF
  int v35[7]; // [esp+1C8h] [ebp-2D0h] BYREF
  _BYTE v36[28]; // [esp+1E4h] [ebp-2B4h] BYREF
  _BYTE v37[28]; // [esp+200h] [ebp-298h] BYREF
  int v38[7]; // [esp+21Ch] [ebp-27Ch] BYREF
  int v39[7]; // [esp+238h] [ebp-260h] BYREF
  int v40[7]; // [esp+254h] [ebp-244h] BYREF
  char Str[12]; // [esp+478h] [ebp-20h] BYREF
  _DWORD *v42; // [esp+488h] [ebp-10h]
  int v43; // [esp+494h] [ebp-4h]

  v42 = v9;
  v9[4] = this;
  v23 = 1;
  std::string::string();
  v43 = 0;
  v18 = a2;
  switch ( a2 )
  {
    case 0:
      std::string::operator=(v40, "ROMAN");
      break;
    case 1:
      std::string::operator=(v40, "VIKING");
      break;
    case 2:
      std::string::operator=(v40, "MAYA");
      break;
    case 3:
      std::string::operator=(v40, "DARK");
      break;
    case 4:
      std::string::operator=(v40, "TROJAN");
      break;
    case 5:
      std::string::operator=(v40, "MENU");
      break;
    default:
      BBSupportTracePrintF(3, "CSoundManager::LoadRaceTitles(): Unknown Race %i!", a2);
      v23 = 0;
      break;
  }
  if ( v23 && !g_pSoundEngine )
    BBSupportTracePrintF(0, "CSoundManager::LoadRaceTitles(): SoundEngine not initialized!");
  if ( v23 )
  {
    v19 = 0;
    std::string::string(v33, (char *)byte_37370E2);
    LOBYTE(v43) = 1;
    std::string::string();
    LOBYTE(v43) = 2;
    std::string::string();
    LOBYTE(v43) = 3;
    std::string::string();
    LOBYTE(v43) = 4;
    std::string::string();
    LOBYTE(v43) = 5;
    std::wstring::wstring(v39);
    LOBYTE(v43) = 6;
    v17 = (void *)std::operator+<char>((int)v31, (int)v40, "SOUNDTRACKS");
    std::string::operator=(v35, v17);
    std::string::~string(v31);
    for ( i = 0; i < 6; ++i )
    {
      v16 = std::operator+<char>((int)v29, (int)v35, "_");
      v15 = v16;
      LOBYTE(v43) = 7;
      v14 = (void *)std::operator+<char>((int)v30, v16, (&aacMusicStyles)[i]);
      std::string::operator=(v38, v14);
      std::string::~string(v30);
      LOBYTE(v43) = 6;
      std::string::~string(v29);
      v13 = (void *)std::operator+<char>((int)v28, (int)v38, "_FADETIME");
      std::string::operator=(v36, v13);
      std::string::~string(v28);
      v3 = std::string::c_str(v38);
      v19 = ((int (__thiscall *)(CConfigManager *, int))g_pCfgMgr->j_?GetSectionEntryCount@CConfigManager@@UAEHPBD@Z)(
              g_pCfgMgr,
              v3);
      if ( v19 > 0 )
      {
        ISoundEngine::InitPlaylist((ISoundEngine *)g_pSoundEngine, i, 0);
        for ( j = 0; j < v19; ++j )
        {
          j__sprintf(Str, "%d", j);
          v12 = (void *)std::operator+<char>((int)v27, (int)v40, Str);
          std::string::operator=(v37, v12);
          std::string::~string(v27);
          v7 = std::string::c_str(v37);
          v4 = std::string::c_str(v38);
          ((void (__thiscall *)(CConfigManager *, _BYTE *, int, int, _BYTE *))g_pCfgMgr->GetStringValue)(
            g_pCfgMgr,
            v34,
            v4,
            v7,
            v33);
          LOBYTE(v43) = 8;
          std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v25);
          LOBYTE(v43) = 9;
          v11 = std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::from_bytes(
                  v26,
                  v34);
          std::wstring::operator=(v11);
          std::wstring::~wstring(v26);
          if ( (unsigned __int8)std::operator!=<wchar_t>(v39, word_3738860) )
          {
            CFile::CFile((CFile *)v32);
            LOBYTE(v43) = 11;
            CFile::Open((int)v39, 6, "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h", 0);
            CFile::Close((CFile *)v32, "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h", 0);
            v24 = 1;
            v43 = 10;
            v8 = std::string::c_str(v37);
            v5 = std::string::c_str(v36);
            v10 = ((int (__thiscall *)(CConfigManager *, int, int, _DWORD))g_pCfgMgr->GetIntValue)(g_pCfgMgr, v5, v8, 0);
            ISoundEngine::AddTitleToPlaylist(i, v39, v10);
            LOBYTE(v43) = 9;
            CFile::~CFile();
          }
          LOBYTE(v43) = 8;
          std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v25);
          LOBYTE(v43) = 6;
          std::string::~string(v34);
        }
      }
    }
    LOBYTE(v43) = 5;
    std::wstring::~wstring(v39);
    LOBYTE(v43) = 4;
    std::string::~string(v36);
    LOBYTE(v43) = 3;
    std::string::~string(v38);
    LOBYTE(v43) = 2;
    std::string::~string(v35);
    LOBYTE(v43) = 1;
    std::string::~string(v37);
    LOBYTE(v43) = 0;
    std::string::~string(v33);
  }
  v22 = v23;
  v43 = -1;
  std::string::~string(v40);
  return v22;
}


// address=[0x149b9f0]
// Decompiled from char __thiscall CSoundManager::CreateDirPlaylist(_DWORD *this, wchar_t *String)
bool  CSoundManager::CreateDirPlaylist(wchar_t const *) {
  
  HANDLE hFindFile; // [esp+8h] [ebp-4A8h]
  struct _WIN32_FIND_DATAW FindFileData; // [esp+10h] [ebp-4A0h] BYREF
  _BYTE v5[28]; // [esp+260h] [ebp-250h] BYREF
  _BYTE v6[28]; // [esp+27Ch] [ebp-234h] BYREF
  WCHAR FileName[260]; // [esp+298h] [ebp-218h] BYREF
  int v8; // [esp+4ACh] [ebp-4h]

  if ( !g_pSoundEngine )
    return 0;
  this[3] = -1;
  CSoundManager::StopMusic(this);
  ISoundEngine::CreatePlaylists((ISoundEngine *)g_pSoundEngine, 1);
  ISoundEngine::InitPlaylist((ISoundEngine *)g_pSoundEngine, 0, 0);
  std::wstring::wstring(v6);
  v8 = 0;
  std::wstring::wstring(v5, String);
  LOBYTE(v8) = 1;
  j__wcscpy(FileName, String);
  if ( String[j__wcslen(String) - 1] == 92 )
  {
    j__wcscat(FileName, L"*.mp3");
  }
  else
  {
    j__wcscat(FileName, L"\\*.mp3");
    std::wstring::operator+=(92);
  }
  hFindFile = FindFirstFileW(FileName, &FindFileData);
  if ( hFindFile == (HANDLE)-1 )
  {
    LOBYTE(v8) = 0;
    std::wstring::~wstring(v5);
    v8 = -1;
    std::wstring::~wstring(v6);
    return 0;
  }
  else
  {
    do
    {
      std::wstring::operator=((int)v5);
      std::wstring::operator+=(v6, FindFileData.cFileName);
      ISoundEngine::AddTitleToPlaylist(0, v6, 2500);
    }
    while ( FindNextFileW(hFindFile, &FindFileData) );
    FindClose(hFindFile);
    LOBYTE(v8) = 0;
    std::wstring::~wstring(v5);
    v8 = -1;
    std::wstring::~wstring(v6);
    return 1;
  }
}


// address=[0x149bc00]
// Decompiled from int __thiscall CSoundManager::CalcPanningAndVolume(CSoundManager *this, int a2, int a3, int *a4, int *a5)
void  CSoundManager::CalcPanningAndVolume(int,int,int &,int &) {
  
  int result; // eax
  float ZoomFactor; // [esp+4h] [ebp-2Ch]
  int v7; // [esp+8h] [ebp-28h]
  int v8; // [esp+Ch] [ebp-24h] BYREF
  int v9; // [esp+10h] [ebp-20h]
  int v10; // [esp+14h] [ebp-1Ch]
  int v11; // [esp+18h] [ebp-18h] BYREF
  CSoundManager *v12; // [esp+1Ch] [ebp-14h]
  int v13; // [esp+20h] [ebp-10h] BYREF
  int v14; // [esp+24h] [ebp-Ch] BYREF
  int OutputHeight; // [esp+28h] [ebp-8h]
  int OutputWidth; // [esp+2Ch] [ebp-4h]

  v12 = this;
  result = (*(unsigned __int8 (__thiscall **)(void *, int, int))(*(_DWORD *)g_pFogging + 32))(g_pFogging, a2, a3);
  if ( (_BYTE)result )
  {
    result = IGfxEngine::GetScreenOffsetsByMapIndices(a2, a3, &v13, &v11);
    if ( v13 >= 0 && v11 >= 0 )
    {
      OutputWidth = IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
      OutputHeight = IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine);
      v10 = (OutputWidth >> 1) - v13;
      v9 = (OutputHeight >> 1) - v11;
      v7 = v9 * v9 + v10 * v10;
      v14 = (OutputHeight * OutputHeight + OutputWidth * OutputWidth) >> 2;
      v8 = 1;
      v14 = *(_DWORD *)std::max<int>(&v8, &v14);
      *a4 = 100 - 100 * v7 / v14;
      ZoomFactor = CStateGame::GetZoomFactor((CStateGame *)g_pGame);
      *a4 = (int)(float)((float)((int)(float)(ZoomFactor + 20.0) * *a4) * 0.0099999998);
      *a5 = 127 * v13 / OutputWidth;
      result = CSoundManager::CalcFinalVolume(v12, *((_DWORD *)v12 + 5), *a4, *((_DWORD *)v12 + 5));
      *a4 = result;
    }
    else
    {
      *a4 = 0;
      *a5 = 127;
    }
  }
  else
  {
    *a4 = 0;
    *a5 = 127;
  }
  return result;
}


