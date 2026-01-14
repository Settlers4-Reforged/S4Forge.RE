#ifndef CSOUNDMANAGER_H
#define CSOUNDMANAGER_H

class CSoundManager {
public:
    // address=[0x149bd80]
     CSoundManager(void);

    // address=[0x149be60]
     ~CSoundManager(void);

    // address=[0x149bfb0]
    bool  OpenSoundFiles(void);

    // address=[0x149c410]
    unsigned int  PlaySoundFX(enum SIV_SOUNDS);

    // address=[0x149c470]
    unsigned int  PlaySoundFXLooped(enum SIV_SOUNDS);

    // address=[0x149c4d0]
    unsigned int  PlaySoundFX(enum SIV_SOUNDS,int,int,int,bool);

    // address=[0x149c6b0]
    unsigned int  PlayEnvironmentSound(enum SIV_SOUNDS,int,int,bool);

    // address=[0x149c730]
    unsigned int  PlaySoundFile(wchar_t const *,int,int);

    // address=[0x149c770]
    unsigned int  PlayBackgroundMusic(int,enum SIV_MUSICSTYLES,wchar_t const *);

    // address=[0x149c810]
    unsigned int  PlayDirectory(wchar_t const *);

    // address=[0x149c830]
    unsigned int  ChangeMusicStyle(enum SIV_MUSICSTYLES);

    // address=[0x149c860]
    unsigned int  FadeInSound(enum SIV_SOUNDS,int,int,int);

    // address=[0x149c950]
    unsigned int  CrossFade(unsigned int,enum SIV_SOUNDS,int,int);

    // address=[0x149ca10]
    bool  FadeOutSound(unsigned int,int,int);

    // address=[0x149ca50]
    void  SetMusicVolume(int);

    // address=[0x149cad0]
    void  SetSoundVolume(int);

    // address=[0x149cb50]
    void  Mute(bool);

    // address=[0x149cbc0]
    void  PausePlayback(bool);

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
    bool  CreatePlaylists(int,wchar_t const *);

    // address=[0x149b310]
    int  CalcFinalVolume(int,int,int);

    // address=[0x149b370]
    bool  LoadRaceTitles(int,wchar_t const *);

    // address=[0x149b9f0]
    bool  CreateDirPlaylist(wchar_t const *);

    // address=[0x149bc00]
    void  CalcPanningAndVolume(int,int,int &,int &);

};


#endif // CSOUNDMANAGER_H
