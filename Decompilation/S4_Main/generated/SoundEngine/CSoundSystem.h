#ifndef CSOUNDSYSTEM_H
#define CSOUNDSYSTEM_H

#include "defines.h"

class CSoundSystem {
public:
    // address=[0x2fd9bc0]
     CSoundSystem(void);

    // address=[0x2fd9c90]
    virtual  ~CSoundSystem(void);

    // address=[0x2fd9d90]
    bool  Init(char const * a2, int a3, bool a4, int a5, int a6, int a7);

    // address=[0x2fd9e60]
    void  StopPlayback(void);

    // address=[0x2fd9f60]
    int  GetNumberOfPlayingVoices(void);

    // address=[0x2fda000]
    void  Shutdown(void);

    // address=[0x2fda030]
    int  GetCpuUsage(void);

    // address=[0x2fda060]
    unsigned int  PlaySoundFile(char const * a2, int a3, int a4);

    // address=[0x2fda280]
    unsigned int  PlayStream(char const * a2, int a3, int a4, bool a5, int a6);

    // address=[0x2fda4e0]
    unsigned int  PlaySoundFromMemory(unsigned int * a2, char * a3, unsigned int a4, int a5, int a6, int a7, bool a8);

    // address=[0x2fda6a0]
    bool  ChangeVolume(unsigned int a2, int a3);

    // address=[0x2fda7a0]
    int  GetVolume(unsigned int a2);

    // address=[0x2fda820]
    bool  ChangePan(unsigned int a2, int a3);

    // address=[0x2fda8d0]
    bool  Fade(unsigned int a2, int a3, int a4);

    // address=[0x2fdaa80]
    void  SetTimerInterval(int a2);

    // address=[0x2fdaac0]
    void  Update(void);

    // address=[0x2fdab50]
    void  StopSample(unsigned int a2);

    // address=[0x2fdac80]
    int  GetSampleID(struct _SAMPLE * a2);

    // address=[0x2fdace0]
    void  StopStreams(void);

    // address=[0x2fdadb0]
    void  StopSounds(void);

    // address=[0x2fdae10]
    void  PausePlayback(void);

    // address=[0x2fdaed0]
    void  ResumePlayback(void);

    // address=[0x2fdaf90]
    void  InitPlaylist(int a2, int a3);

    // address=[0x2fdaff0]
    bool  AddTitleToPlaylist(int a2, std::string const * a3, int a4);

    // address=[0x2fdb060]
    static void __stdcall LoopStreamCB(struct _STREAM * a1);

    // address=[0x2fdb080]
    static void __stdcall LoopSampleCB(struct _SAMPLE * a1);

    // address=[0x2fdb0c0]
    void  CreatePlaylists(int a2);

    // address=[0x2fdb200]
    unsigned int  StartPlaylist(int a2, int a3);

    // address=[0x2fdb280]
    unsigned int  ChangePlaylist(int a2, int a3);

    // address=[0x2fdb440]
    void  PlaylistTitleEnded(struct _STREAM * a2);

    // address=[0x2fdb5b0]
    void  SampleEnded(struct _SAMPLE * a2);

    // address=[0x2fdb610]
    void  ChangeStreamVolume(int a2);

    // address=[0x2fdb6e0]
    void  ChangeSoundVolume(int a2);

    // address=[0x2fdb770]
    unsigned int  GetDigitalDriver(void);

    // address=[0x2fdb790]
    int  GetSamplingRate(void);

    // address=[0x2fdb7b0]
    int  GetHWFormat(void);

    // address=[0x2fdb7d0]
    bool  IsRunning(unsigned int a2);

    // address=[0x2fdb820]
    int  EnumSoundCards(void);

    // address=[0x2fdb860]
    std::string  GetSoundCardName(int a2);

    // address=[0x2fdb8d0]
    void  SetSoundCard(int a2);

    // address=[0x2fdb920]
    void  AddSoundCard(struct _GUID * a2, char const * Str);

    // address=[0x2fdba90]
    void  SkipTitle(void);

private:
    // address=[0x2fd9280]
    bool  InitOutputDriver(void);

    // address=[0x2fd93d0]
    void  AllocateSampleHandles(void);

    // address=[0x2fd9560]
    int  GetFreeStreamHandle(void);

    // address=[0x2fd95b0]
    int  GetFreeSoundHandle(void);

    // address=[0x2fd9660]
    void  FreeMemory(void);

    // address=[0x2fd9850]
    int  GetSoundIndex(unsigned int a2);

    // address=[0x2fd98c0]
    int  GetStreamIndex(unsigned int a2);

    // address=[0x2fd9950]
    void  UpdateFades(void);

};


#endif // CSOUNDSYSTEM_H
