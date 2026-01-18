#ifndef ISOUNDENGINE_H
#define ISOUNDENGINE_H

#include "defines.h"

class ISoundEngine {
public:
    // address=[0x2fd5550]
     ISoundEngine(void);

    // address=[0x2fd5630]
    virtual  ~ISoundEngine(void);

    // address=[0x2fd5720]
    bool  Init(wchar_t * a2, int a3, bool a4, int a5, int a6, int a7);

    // address=[0x2fd5840]
    void  SetTimerInterval(int a2);

    // address=[0x2fd5890]
    int  GetNumberOfSoundCards(void);

    // address=[0x2fd58c0]
    void  SetSoundCard(int a1);

    // address=[0x2fd58f0]
    std::string  GetSoundCardName(int a1);

    // address=[0x2fd5950]
    unsigned int  PlaySoundFile(wchar_t const * a2, int a3, int a4);

    // address=[0x2fd5a40]
    unsigned int  PlayStream(wchar_t const * a2, int a3, int a4);

    // address=[0x2fd5b30]
    unsigned int  PlaySoundFromMemory(unsigned int * a2, char * a3, unsigned int a4, int a5, int a6, int a7, bool a8);

    // address=[0x2fd5b90]
    bool  ChangeVolume(unsigned int a2, int a3);

    // address=[0x2fd5be0]
    int  GetVolume(unsigned int a2);

    // address=[0x2fd5c30]
    bool  ChangePan(unsigned int a2, int a3);

    // address=[0x2fd5c80]
    bool  Fade(unsigned int a2, int a3, int a4);

    // address=[0x2fd5cd0]
    void  StopSample(unsigned int a2);

    // address=[0x2fd5d20]
    void  StopStreams(void);

    // address=[0x2fd5d60]
    void  StopSounds(void);

    // address=[0x2fd5da0]
    void  StopPlayback(void);

    // address=[0x2fd5de0]
    void  ChangeStreamVolume(int a2);

    // address=[0x2fd5e10]
    void  ChangeSoundVolume(int a2);

    // address=[0x2fd5e40]
    void  PausePlayback(bool a2);

    // address=[0x2fd5e80]
    void  Perform(void);

    // address=[0x2fd5ee0]
    void  Shutdown(void);

    // address=[0x2fd5f40]
    int  GetCpuUsage(void);

    // address=[0x2fd5f80]
    unsigned int  GetDigitalDriver(void);

    // address=[0x2fd5fc0]
    bool  IsRunning(unsigned int a2);

    // address=[0x2fd6010]
    void  CreatePlaylists(int a2);

    // address=[0x2fd6040]
    void  InitPlaylist(int a2, int a3);

    // address=[0x2fd6090]
    bool  AddTitleToPlaylist(int a1, std::wstring * a2, int a3);

    // address=[0x2fd6170]
    unsigned int  StartPlaylist(int a2, int a3);

    // address=[0x2fd61a0]
    unsigned int  ChangePlaylist(int a2, int a3);

    // address=[0x2fd61d0]
    void  SkipTitle(void);

    // address=[0x2fd61f0]
    void  VCToggleRecording(bool a1);

    // address=[0x2fd6220]
    bool  VCStart(class IEventEngine * a2, int a3);

    // address=[0x2fd6330]
    void  VCStop(void);

    // address=[0x2fd6380]
    bool  VCReceivePackage(signed char * Src, int a2);

    // address=[0x2fd63b0]
    int  VCGetInputRate(void);

    // address=[0x2fd63e0]
    bool  VCUsesFullDuplex(void);

    // address=[0x2fd6410]
    bool  VCIsRecording(void);

    // address=[0x2fd6440]
    void  VCCalcBaseNoise(void);

    // address=[0x2fd6460]
    void  VCSetTestMode(bool a1);

    // address=[0x2fd6490]
    void  VCSetVolume(int a2);

    // address=[0x2fd64c0]
    void  VCSetMicVolume(int a2);

    // address=[0x2fd64f0]
    int  VCGetMicVolume(void);

};


#endif // ISOUNDENGINE_H
