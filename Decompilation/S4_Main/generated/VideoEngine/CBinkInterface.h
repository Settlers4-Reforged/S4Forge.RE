#ifndef CBINKINTERFACE_H
#define CBINKINTERFACE_H

class CBinkInterface {
public:
    // address=[0x16a1c40]
     CBinkInterface(void);

    // address=[0x16a1c70]
     ~CBinkInterface(void);

    // address=[0x16a1cb0]
    bool  OpenVideo(char *,unsigned int,unsigned int);

    // address=[0x16a1d40]
    void  StartPause(void);

    // address=[0x16a1d80]
    void  StopPause(void);

    // address=[0x16a1dc0]
    int  GetHeight(void);

    // address=[0x16a1e00]
    int  GetWidth(void);

    // address=[0x16a1e40]
    void  UseMiles(unsigned long);

    // address=[0x16a1e60]
    void  CloseBink(void);

    // address=[0x16a1e90]
    bool  RenderToSurface(unsigned short *,unsigned int);

    // address=[0x16a1f50]
    void  Set_555_GfxMode(void);

    // address=[0x16a1f70]
    void  Set_565_GfxMode(void);

    // address=[0x16a1f90]
    bool  IsReadyForNextFrame(void);

};


#endif // CBINKINTERFACE_H
