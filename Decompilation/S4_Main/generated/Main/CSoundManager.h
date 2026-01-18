#ifndef CSOUNDMANAGER_H
#define CSOUNDMANAGER_H

#include "defines.h"

class CSoundManager {
public:
    // address=[0x149bd80]
     CSoundManager(void);

    // address=[0x149be60]
     ~CSoundManager(void);

    // address=[0x149bfb0]
    bool  OpenSoundFiles(void);

    // address=[0x149c410]
    unsigned int  PlaySoundFX(enum SIV_SOUNDS a2);

    // address=[0x149c470]
    unsigned int  PlaySoundFXLooped(enum SIV_SOUNDS a2);

    // address=[0x149c4d0]
    unsigned int  PlaySoundFX(enum SIV_SOUNDS a2, int a3, int a4, int a5, bool a6);

    // address=[0x149c6b0]
    unsigned int  PlayEnvironmentSound(enum SIV_SOUNDS a2, int a3, int a4, bool a5);

    // address=[0x149c730]
    unsigned int  PlaySoundFile(wchar_t const * a2, int a3, int a4);

    // address=[0x149c770]
    unsigned int  PlayBackgroundMusic(int a2, enum SIV_MUSICSTYLES a3, wchar_t const * String);

    // address=[0x149c810]
    unsigned int  PlayDirectory(wchar_t const * String);

    // address=[0x149c830]
    unsigned int  ChangeMusicStyle(enum SIV_MUSICSTYLES a2);

    // address=[0x149c860]
    unsigned int  FadeInSound(enum SIV_SOUNDS a2, int a3, int a4, int a5);

    // address=[0x149c950]
    unsigned int  CrossFade(unsigned int a2, enum SIV_SOUNDS a3, int a4, int a5);

    // address=[0x149ca10]
    bool  FadeOutSound(unsigned int a1, int a2, int a3);

    // address=[0x149ca50]
    void  SetMusicVolume(int a2);

    // address=[0x149cad0]
    void  SetSoundVolume(int a2);

    // address=[0x149cb50]
    void  Mute(bool);

    // address=[0x149cbc0]
    void  PausePlayback(bool a1);

    // address=[0x149cbf0]
    void  StopMusic(void);

    // address=[0x149cc20]
    void  StopSounds(void);

    // address=[0x149cc90]
    void  StopSound(unsigned int);

    // address=[0x149ccc0]
    bool  IsPlaying(unsigned int);

    // address=[0x149cd00]
    void  Update(void);

private:
    // address=[0x149b280]
    bool  CreatePlaylists(int a2, wchar_t const * a3);

    // address=[0x149b310]
    int  CalcFinalVolume(int a2, int a3, int a4);

    // address=[0x149b370]
    bool  LoadRaceTitles(int a2, wchar_t const * a3);

    // address=[0x149b9f0]
    bool  CreateDirPlaylist(wchar_t const * String);

    // address=[0x149bc00]
    void  CalcPanningAndVolume(int a2, int a3, int & a4, int & a4);

};


#endif // CSOUNDMANAGER_H
