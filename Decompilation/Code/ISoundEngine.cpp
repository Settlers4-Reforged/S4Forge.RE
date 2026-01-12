#include "ISoundEngine.h"

// Definitions for class ISoundEngine

// address=[0x2fd5550]
// Decompiled from ISoundEngine *__thiscall ISoundEngine::ISoundEngine(ISoundEngine *this)

 ISoundEngine::ISoundEngine(void) {
  
  CSoundSystem *v3; // [esp+Ch] [ebp-14h]
  CSoundSystem *C; // [esp+10h] [ebp-10h]

  *(_DWORD *)this = &ISoundEngine::_vftable_;
  BBSupportTracePrintF(0, "ISoundEngine::ISoundEngine() called.");
  if ( g_pcSoundSystem && BBSupportDbgReport(2, "SoundEngineInterface.cpp", 48, "g_pcSoundSystem == 0") == 1 )
    __debugbreak();
  if ( !g_pcSoundSystem )
  {
    C = (CSoundSystem *)operator new(0x44u);
    if ( C )
      v3 = CSoundSystem::CSoundSystem(C);
    else
      v3 = 0;
    g_pcSoundSystem = v3;
  }
  BBSupportTracePrintF(0, "ISoundEngine::ISoundEngine() finished.");
  return this;
}


// address=[0x2fd5630]
// Decompiled from int __thiscall ISoundEngine::~ISoundEngine(ISoundEngine *this)

 ISoundEngine::~ISoundEngine(void) {
  
  *(_DWORD *)this = &ISoundEngine::_vftable_;
  BBSupportTracePrintF(0, "ISoundEngine::~ISoundEngine() called.");
  if ( g_pcVoiceChat )
  {
    CVoiceChat::`scalar deleting destructor'((CVoiceChat *)g_pcVoiceChat, 1u);
    g_pcVoiceChat = 0;
  }
  if ( !g_pcSoundSystem )
    return BBSupportTracePrintF(0, "ISoundEngine::~ISoundEngine() finished.");
  CSoundSystem::Shutdown((CSoundSystem *)g_pcSoundSystem);
  if ( g_pcSoundSystem )
    (*(void (__thiscall **)(_DWORD *, int))*g_pcSoundSystem)(g_pcSoundSystem, 1);
  g_pcSoundSystem = 0;
  return BBSupportTracePrintF(0, "ISoundEngine::~ISoundEngine() finished.");
}


// address=[0x2fd5720]
// Decompiled from bool __thiscall ISoundEngine::Init(ISoundEngine *this, wchar_t *a2, int a3, bool a4, int a5, int a6, int a7)

bool  ISoundEngine::Init(wchar_t *,int,bool,int,int,int) {
  
  const char *v7; // eax
  bool v9; // [esp+Bh] [ebp-85h]
  char v10[88]; // [esp+Ch] [ebp-84h] BYREF
  _BYTE v11[28]; // [esp+64h] [ebp-2Ch] BYREF
  int v12; // [esp+8Ch] [ebp-4h]

  BBSupportTracePrintF(0, "ISoundEngine::Init() called.");
  if ( !g_pcSoundSystem && BBSupportDbgReport(2, "SoundEngineInterface.cpp", 89, "g_pcSoundSystem") == 1 )
    __debugbreak();
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v10);
  v12 = 0;
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
    v11,
    a2);
  LOBYTE(v12) = 1;
  v7 = (const char *)std::string::c_str(v11);
  v9 = CSoundSystem::Init((CSoundSystem *)g_pcSoundSystem, v7, a3, a4, a5, a6, a7);
  BBSupportTracePrintF(0, "ISoundEngine::Init() finished (result %i).", v9);
  LOBYTE(v12) = 0;
  std::string::~string(v11);
  v12 = -1;
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v10);
  return v9;
}


// address=[0x2fd5840]
// Decompiled from void __thiscall ISoundEngine::SetTimerInterval(ISoundEngine *this, int a2)

void  ISoundEngine::SetTimerInterval(int) {
  
  if ( !g_pcSoundSystem && BBSupportDbgReport(2, "SoundEngineInterface.cpp", 222, "g_pcSoundSystem") == 1 )
    __debugbreak();
  CSoundSystem::SetTimerInterval((CSoundSystem *)g_pcSoundSystem, a2);
}


// address=[0x2fd5890]
// Decompiled from // public: int __thiscall ISoundEngine::GetNumberOfSoundCards(void)
int ISoundEngine::GetNumberOfSoundCards()

int  ISoundEngine::GetNumberOfSoundCards(void) {
  
  if ( g_pcSoundSystem )
    return CSoundSystem::EnumSoundCards((CSoundSystem *)g_pcSoundSystem);
  else
    return 0;
}


// address=[0x2fd58c0]
// Decompiled from // public: void __thiscall ISoundEngine::SetSoundCard(int)
CSoundSystem *__stdcall ISoundEngine::SetSoundCard(int a1)

void  ISoundEngine::SetSoundCard(int) {
  
  CSoundSystem *result; // eax

  if ( g_pcSoundSystem )
    return CSoundSystem::SetSoundCard((CSoundSystem *)g_pcSoundSystem, a1);
  return result;
}


// address=[0x2fd58f0]
// Decompiled from // public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > __thiscall ISoundEngine::GetSoundCardName(int)
void *__stdcall ISoundEngine::GetSoundCardName(void *a1, int a2)

std::string  ISoundEngine::GetSoundCardName(int) {
  
  if ( g_pcSoundSystem )
    CSoundSystem::GetSoundCardName(g_pcSoundSystem, (int)a1, a2);
  else
    std::string::string(a1, byte_3AD55A5);
  return a1;
}


// address=[0x2fd5950]
// Decompiled from unsigned int __thiscall ISoundEngine::PlaySoundFile(ISoundEngine *this, const wchar_t *a2, int a3, int a4)

unsigned int  ISoundEngine::PlaySoundFile(wchar_t const *,int,int) {
  
  const char *v4; // eax
  unsigned int v6; // [esp+8h] [ebp-88h]
  char v7[88]; // [esp+Ch] [ebp-84h] BYREF
  _BYTE v8[28]; // [esp+64h] [ebp-2Ch] BYREF
  int v9; // [esp+8Ch] [ebp-4h]

  if ( !g_pcSoundSystem && BBSupportDbgReport(2, "SoundEngineInterface.cpp", 148, "g_pcSoundSystem") == 1 )
    __debugbreak();
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v7);
  v9 = 0;
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
    v8,
    a2);
  LOBYTE(v9) = 1;
  v4 = (const char *)std::string::c_str(v8);
  v6 = CSoundSystem::PlaySoundFile((CSoundSystem *)g_pcSoundSystem, v4, a3, a4);
  LOBYTE(v9) = 0;
  std::string::~string(v8);
  v9 = -1;
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v7);
  return v6;
}


// address=[0x2fd5a40]
// Decompiled from int __thiscall ISoundEngine::PlayStream(ISoundEngine *this, const wchar_t *a2, unsigned int a3, unsigned int a4)

unsigned int  ISoundEngine::PlayStream(wchar_t const *,int,int) {
  
  const char *v4; // eax
  int v6; // [esp+8h] [ebp-88h]
  char v7[88]; // [esp+Ch] [ebp-84h] BYREF
  _BYTE v8[28]; // [esp+64h] [ebp-2Ch] BYREF
  int v9; // [esp+8Ch] [ebp-4h]

  if ( !g_pcSoundSystem && BBSupportDbgReport(2, "SoundEngineInterface.cpp", 164, "g_pcSoundSystem") == 1 )
    __debugbreak();
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v7);
  v9 = 0;
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
    v8,
    a2);
  LOBYTE(v9) = 1;
  v4 = (const char *)std::string::c_str(v8);
  v6 = CSoundSystem::PlayStream(g_pcSoundSystem, v4, a3, a4, 0, -1);
  LOBYTE(v9) = 0;
  std::string::~string(v8);
  v9 = -1;
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v7);
  return v6;
}


// address=[0x2fd5b30]
// Decompiled from unsigned int __thiscall ISoundEngine::PlaySoundFromMemory(
        ISoundEngine *this,
        unsigned int *a2,
        char *a3,
        unsigned int a4,
        int a5,
        int a6,
        int a7,
        bool a8)

unsigned int  ISoundEngine::PlaySoundFromMemory(unsigned int *,char *,unsigned int,int,int,int,bool) {
  
  if ( !g_pcSoundSystem && BBSupportDbgReport(2, "SoundEngineInterface.cpp", 279, "g_pcSoundSystem") == 1 )
    __debugbreak();
  return CSoundSystem::PlaySoundFromMemory((CSoundSystem *)g_pcSoundSystem, a2, a3, a4, a5, a6, a7, a8);
}


// address=[0x2fd5b90]
// Decompiled from bool __thiscall ISoundEngine::ChangeVolume(ISoundEngine *this, unsigned int a2, int a3)

bool  ISoundEngine::ChangeVolume(unsigned int,int) {
  
  if ( !g_pcSoundSystem && BBSupportDbgReport(2, "SoundEngineInterface.cpp", 182, "g_pcSoundSystem") == 1 )
    __debugbreak();
  return CSoundSystem::ChangeVolume((CSoundSystem *)g_pcSoundSystem, a2, a3);
}


// address=[0x2fd5be0]
// Decompiled from int __thiscall ISoundEngine::GetVolume(ISoundEngine *this, unsigned int a2)

int  ISoundEngine::GetVolume(unsigned int) {
  
  if ( !g_pcSoundSystem && BBSupportDbgReport(2, "SoundEngineInterface.cpp", 192, "g_pcSoundSystem") == 1 )
    __debugbreak();
  return CSoundSystem::GetVolume((CSoundSystem *)g_pcSoundSystem, a2);
}


// address=[0x2fd5c30]
// Decompiled from bool __thiscall ISoundEngine::ChangePan(ISoundEngine *this, unsigned int a2, int a3)

bool  ISoundEngine::ChangePan(unsigned int,int) {
  
  if ( !g_pcSoundSystem && BBSupportDbgReport(2, "SoundEngineInterface.cpp", 202, "g_pcSoundSystem") == 1 )
    __debugbreak();
  return CSoundSystem::ChangePan((CSoundSystem *)g_pcSoundSystem, a2, a3);
}


// address=[0x2fd5c80]
// Decompiled from bool __thiscall ISoundEngine::Fade(ISoundEngine *this, unsigned int a2, int a3, int a4)

bool  ISoundEngine::Fade(unsigned int,int,int) {
  
  if ( !g_pcSoundSystem && BBSupportDbgReport(2, "SoundEngineInterface.cpp", 212, "g_pcSoundSystem") == 1 )
    __debugbreak();
  return CSoundSystem::Fade((CSoundSystem *)g_pcSoundSystem, a2, a3, a4);
}


// address=[0x2fd5cd0]
// Decompiled from void __thiscall ISoundEngine::StopSample(ISoundEngine *this, unsigned int a2)

void  ISoundEngine::StopSample(unsigned int) {
  
  if ( !g_pcSoundSystem && BBSupportDbgReport(2, "SoundEngineInterface.cpp", 289, "g_pcSoundSystem") == 1 )
    __debugbreak();
  CSoundSystem::StopSample((CSoundSystem *)g_pcSoundSystem, a2);
}


// address=[0x2fd5d20]
// Decompiled from void __thiscall ISoundEngine::StopStreams(ISoundEngine *this)

void  ISoundEngine::StopStreams(void) {
  
  if ( !g_pcSoundSystem && BBSupportDbgReport(2, "SoundEngineInterface.cpp", 299, "g_pcSoundSystem") == 1 )
    __debugbreak();
  CSoundSystem::StopStreams((CSoundSystem *)g_pcSoundSystem);
}


// address=[0x2fd5d60]
// Decompiled from // public: void __thiscall ISoundEngine::StopSounds(void)
CSoundSystem *ISoundEngine::StopSounds()

void  ISoundEngine::StopSounds(void) {
  
  if ( !g_pcSoundSystem && BBSupportDbgReport(2, "SoundEngineInterface.cpp", 309, "g_pcSoundSystem") == 1 )
    __debugbreak();
  return CSoundSystem::StopSounds((CSoundSystem *)g_pcSoundSystem);
}


// address=[0x2fd5da0]
// Decompiled from void __thiscall ISoundEngine::StopPlayback(ISoundEngine *this)

void  ISoundEngine::StopPlayback(void) {
  
  if ( !g_pcSoundSystem && BBSupportDbgReport(2, "SoundEngineInterface.cpp", 114, "g_pcSoundSystem") == 1 )
    __debugbreak();
  CSoundSystem::StopPlayback((CSoundSystem *)g_pcSoundSystem);
}


// address=[0x2fd5de0]
// Decompiled from void __thiscall ISoundEngine::ChangeStreamVolume(ISoundEngine *this, int a2)

void  ISoundEngine::ChangeStreamVolume(int) {
  
  if ( g_pcSoundSystem )
    CSoundSystem::ChangeStreamVolume((CSoundSystem *)g_pcSoundSystem, a2);
}


// address=[0x2fd5e10]
// Decompiled from void __thiscall ISoundEngine::ChangeSoundVolume(ISoundEngine *this, int a2)

void  ISoundEngine::ChangeSoundVolume(int) {
  
  if ( g_pcSoundSystem )
    CSoundSystem::ChangeSoundVolume((CSoundSystem *)g_pcSoundSystem, a2);
}


// address=[0x2fd5e40]
// Decompiled from void __thiscall ISoundEngine::PausePlayback(ISoundEngine *this, bool a2)

void  ISoundEngine::PausePlayback(bool) {
  
  if ( g_pcSoundSystem )
  {
    if ( a2 )
      CSoundSystem::PausePlayback((CSoundSystem *)g_pcSoundSystem);
    else
      CSoundSystem::ResumePlayback((CSoundSystem *)g_pcSoundSystem);
  }
}


// address=[0x2fd5e80]
// Decompiled from void __thiscall ISoundEngine::Perform(ISoundEngine *this)

void  ISoundEngine::Perform(void) {
  
  if ( !g_pcSoundSystem && BBSupportDbgReport(2, "SoundEngineInterface.cpp", 232, "g_pcSoundSystem") == 1 )
    __debugbreak();
  CSoundSystem::Update((CSoundSystem *)g_pcSoundSystem);
  if ( g_pcVoiceChat )
    CVoiceChat::Run((CVoiceChat *)g_pcVoiceChat);
}


// address=[0x2fd5ee0]
// Decompiled from // public: void __thiscall ISoundEngine::Shutdown(void)
int ISoundEngine::Shutdown()

void  ISoundEngine::Shutdown(void) {
  
  if ( !g_pcSoundSystem && BBSupportDbgReport(2, "SoundEngineInterface.cpp", 124, "g_pcSoundSystem") == 1 )
    __debugbreak();
  BBSupportTracePrintF(0, "ISoundEngine::Shutdown() called.");
  CSoundSystem::Shutdown((CSoundSystem *)g_pcSoundSystem);
  return BBSupportTracePrintF(0, "ISoundEngine::Shutdown() finished.");
}


// address=[0x2fd5f40]
// Decompiled from // public: int __thiscall ISoundEngine::GetCpuUsage(void)
int ISoundEngine::GetCpuUsage()

int  ISoundEngine::GetCpuUsage(void) {
  
  if ( !g_pcSoundSystem && BBSupportDbgReport(2, "SoundEngineInterface.cpp", 138, "g_pcSoundSystem") == 1 )
    __debugbreak();
  return CSoundSystem::GetCpuUsage((CSoundSystem *)g_pcSoundSystem);
}


// address=[0x2fd5f80]
// Decompiled from unsigned int __thiscall ISoundEngine::GetDigitalDriver(ISoundEngine *this)

unsigned int  ISoundEngine::GetDigitalDriver(void) {
  
  if ( !g_pcSoundSystem && BBSupportDbgReport(2, "SoundEngineInterface.cpp", 319, "g_pcSoundSystem") == 1 )
    __debugbreak();
  return CSoundSystem::GetDigitalDriver((CSoundSystem *)g_pcSoundSystem);
}


// address=[0x2fd5fc0]
// Decompiled from bool __thiscall ISoundEngine::IsRunning(ISoundEngine *this, unsigned int a2)

bool  ISoundEngine::IsRunning(unsigned int) {
  
  if ( !g_pcSoundSystem && BBSupportDbgReport(2, "SoundEngineInterface.cpp", 329, "g_pcSoundSystem") == 1 )
    __debugbreak();
  return CSoundSystem::IsRunning((CSoundSystem *)g_pcSoundSystem, a2);
}


// address=[0x2fd6010]
// Decompiled from void __thiscall ISoundEngine::CreatePlaylists(ISoundEngine *this, int a2)

void  ISoundEngine::CreatePlaylists(int) {
  
  if ( g_pcSoundSystem )
    CSoundSystem::CreatePlaylists((CSoundSystem *)g_pcSoundSystem, a2);
}


// address=[0x2fd6040]
// Decompiled from void __thiscall ISoundEngine::InitPlaylist(ISoundEngine *this, int a2, int a3)

void  ISoundEngine::InitPlaylist(int,int) {
  
  if ( !g_pcSoundSystem && BBSupportDbgReport(2, "SoundEngineInterface.cpp", 251, "g_pcSoundSystem") == 1 )
    __debugbreak();
  CSoundSystem::InitPlaylist((CSoundSystem *)g_pcSoundSystem, a2, a3);
}


// address=[0x2fd6090]
// Decompiled from char __stdcall ISoundEngine::AddTitleToPlaylist(int a1, int a2, int a3)

bool  ISoundEngine::AddTitleToPlaylist(int,std::wstring *,int) {
  
  char v4; // [esp+Bh] [ebp-85h]
  char v5[88]; // [esp+Ch] [ebp-84h] BYREF
  _BYTE v6[28]; // [esp+64h] [ebp-2Ch] BYREF
  int v7; // [esp+8Ch] [ebp-4h]

  if ( !g_pcSoundSystem && BBSupportDbgReport(2, "SoundEngineInterface.cpp", 266, "g_pcSoundSystem") == 1 )
    __debugbreak();
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v5);
  v7 = 0;
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
    v6,
    a2);
  LOBYTE(v7) = 1;
  v4 = CSoundSystem::AddTitleToPlaylist(a1, v6, a3);
  LOBYTE(v7) = 0;
  std::string::~string(v6);
  v7 = -1;
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v5);
  return v4;
}


// address=[0x2fd6170]
// Decompiled from unsigned int __thiscall ISoundEngine::StartPlaylist(ISoundEngine *this, int a2, int a3)

unsigned int  ISoundEngine::StartPlaylist(int,int) {
  
  if ( g_pcSoundSystem )
    return CSoundSystem::StartPlaylist((CSoundSystem *)g_pcSoundSystem, a2, a3);
  else
    return 0;
}


// address=[0x2fd61a0]
// Decompiled from unsigned int __thiscall ISoundEngine::ChangePlaylist(ISoundEngine *this, int a2, int a3)

unsigned int  ISoundEngine::ChangePlaylist(int,int) {
  
  if ( g_pcSoundSystem )
    return CSoundSystem::ChangePlaylist((CSoundSystem *)g_pcSoundSystem, a2, a3);
  else
    return 0;
}


// address=[0x2fd61d0]
// Decompiled from // public: void __thiscall ISoundEngine::SkipTitle(void)
int ISoundEngine::SkipTitle()

void  ISoundEngine::SkipTitle(void) {
  
  int result; // eax

  if ( g_pcSoundSystem )
    return CSoundSystem::SkipTitle((CPlaylist **)g_pcSoundSystem);
  return result;
}


// address=[0x2fd61f0]
// Decompiled from // public: void __thiscall ISoundEngine::VCToggleRecording(bool)
void __stdcall ISoundEngine::VCToggleRecording(bool a1)

void  ISoundEngine::VCToggleRecording(bool) {
  
  if ( g_pcVoiceChat )
    CVoiceChat::ToggleRecording((CVoiceChat *)g_pcVoiceChat, a1);
}


// address=[0x2fd6220]
// Decompiled from char __thiscall ISoundEngine::VCStart(ISoundEngine *this, struct IEventEngine *a2, int a3)

bool  ISoundEngine::VCStart(class IEventEngine *,int) {
  
  int SamplingRate; // eax
  int DigitalDriver; // [esp-8h] [ebp-34h]
  CVoiceChat *v6; // [esp+18h] [ebp-14h]
  CVoiceChat *C; // [esp+1Ch] [ebp-10h]

  if ( !g_pcVoiceChat )
  {
    C = (CVoiceChat *)operator new(0xA8u);
    if ( C )
      v6 = CVoiceChat::CVoiceChat(C, 8, a3, a2);
    else
      v6 = 0;
    g_pcVoiceChat = (int)v6;
  }
  if ( !g_pcVoiceChat )
    return 0;
  DigitalDriver = CSoundSystem::GetDigitalDriver((CSoundSystem *)g_pcSoundSystem);
  SamplingRate = CSoundSystem::GetSamplingRate((CSoundSystem *)g_pcSoundSystem);
  if ( (unsigned __int8)CVoiceChat::Init(SamplingRate, DigitalDriver, ".v29") )
    return 1;
  if ( g_pcVoiceChat )
    CVoiceChat::`scalar deleting destructor'((CVoiceChat *)g_pcVoiceChat, 1u);
  g_pcVoiceChat = 0;
  return 0;
}


// address=[0x2fd6330]
// Decompiled from // public: void __thiscall ISoundEngine::VCStop(void)
void ISoundEngine::VCStop()

void  ISoundEngine::VCStop(void) {
  
  if ( g_pcVoiceChat )
  {
    CVoiceChat::`scalar deleting destructor'((CVoiceChat *)g_pcVoiceChat, 1u);
    g_pcVoiceChat = 0;
  }
}


// address=[0x2fd6380]
// Decompiled from // public: bool __thiscall ISoundEngine::VCReceivePackage(signed char *,int)
char __stdcall ISoundEngine::VCReceivePackage(void *Src, int a2)

bool  ISoundEngine::VCReceivePackage(signed char *,int) {
  
  if ( g_pcVoiceChat )
    return CVoiceChat::ReceivePacket(Src, a2);
  else
    return 0;
}


// address=[0x2fd63b0]
// Decompiled from // public: int __thiscall ISoundEngine::VCGetInputRate(void)
int ISoundEngine::VCGetInputRate()

int  ISoundEngine::VCGetInputRate(void) {
  
  if ( g_pcVoiceChat )
    return CVoiceChat::GetInputSamplingRate((CVoiceChat *)g_pcVoiceChat);
  else
    return 0;
}


// address=[0x2fd63e0]
// Decompiled from // public: bool __thiscall ISoundEngine::VCUsesFullDuplex(void)
bool ISoundEngine::VCUsesFullDuplex()

bool  ISoundEngine::VCUsesFullDuplex(void) {
  
  return g_pcVoiceChat && CVoiceChat::UsesFullDuplex((CVoiceChat *)g_pcVoiceChat);
}


// address=[0x2fd6410]
// Decompiled from // public: bool __thiscall ISoundEngine::VCIsRecording(void)
bool ISoundEngine::VCIsRecording()

bool  ISoundEngine::VCIsRecording(void) {
  
  return g_pcVoiceChat && CVoiceChat::IsRecording((CVoiceChat *)g_pcVoiceChat);
}


// address=[0x2fd6440]
// Decompiled from // public: void __thiscall ISoundEngine::VCCalcBaseNoise(void)
void ISoundEngine::VCCalcBaseNoise()

void  ISoundEngine::VCCalcBaseNoise(void) {
  
  if ( g_pcVoiceChat )
    CVoiceChat::CalcBaseNoise((CVoiceChat *)g_pcVoiceChat);
}


// address=[0x2fd6460]
// Decompiled from // public: void __thiscall ISoundEngine::VCSetTestMode(bool)
CVoiceChat *__stdcall ISoundEngine::VCSetTestMode(bool a1)

void  ISoundEngine::VCSetTestMode(bool) {
  
  CVoiceChat *result; // eax

  if ( g_pcVoiceChat )
    return CVoiceChat::SetTestMode((CVoiceChat *)g_pcVoiceChat, a1);
  return result;
}


// address=[0x2fd6490]
// Decompiled from CVoiceChat *__thiscall ISoundEngine::VCSetVolume(ISoundEngine *this, int a2)

void  ISoundEngine::VCSetVolume(int) {
  
  CVoiceChat *result; // eax

  if ( g_pcVoiceChat )
    return CVoiceChat::SetVolume((CVoiceChat *)g_pcVoiceChat, a2);
  return result;
}


// address=[0x2fd64c0]
// Decompiled from char __thiscall ISoundEngine::VCSetMicVolume(ISoundEngine *this, unsigned int a2)

void  ISoundEngine::VCSetMicVolume(int) {
  
  char result; // al

  if ( g_pcVoiceChat )
    return CVoiceChat::SetMicVolume((CVoiceChat *)g_pcVoiceChat, a2);
  return result;
}


// address=[0x2fd64f0]
// Decompiled from // public: int __thiscall ISoundEngine::VCGetMicVolume(void)
int ISoundEngine::VCGetMicVolume()

int  ISoundEngine::VCGetMicVolume(void) {
  
  if ( g_pcVoiceChat )
    return CVoiceChat::GetMicVolume((CVoiceChat *)g_pcVoiceChat);
  else
    return 0;
}


