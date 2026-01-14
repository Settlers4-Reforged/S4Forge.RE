#ifndef IVIDEOENGINE_H
#define IVIDEOENGINE_H

class IVideoEngine {
public:
    // address=[0x16a20b0]
     IVideoEngine(void);

    // address=[0x16a2160]
     ~IVideoEngine(void);

    // address=[0x16a21e0]
    bool  Init(unsigned int);

    // address=[0x16a2230]
    bool  StartVideo(char *,unsigned int,unsigned int);

    // address=[0x16a2260]
    bool  StopVideo(void);

    // address=[0x16a2280]
    void  PauseVideo(void);

    // address=[0x16a22a0]
    void  UnPauseVideo(void);

    // address=[0x16a22c0]
    int  GetVideoHeight(void);

    // address=[0x16a2300]
    int  GetVideoWidth(void);

    // address=[0x16a2340]
    void  Set_555_GfxMode(void);

    // address=[0x16a2380]
    void  Set_565_GfxMode(void);

    // address=[0x16a23c0]
    bool  RenderToSurface(unsigned short *,unsigned int);

    // address=[0x16a2410]
    bool  IsReadyForNextFrame(void);

};


#endif // IVIDEOENGINE_H
