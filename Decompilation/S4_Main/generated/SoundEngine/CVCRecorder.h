#ifndef CVCRECORDER_H
#define CVCRECORDER_H

#include "defines.h"

class CVCRecorder {
public:
    // address=[0x2fd71f0]
     CVCRecorder(void);

    // address=[0x2fd72b0]
    virtual  ~CVCRecorder(void);

    // address=[0x2fd7380]
    bool  Start(int a2, char * a3, int a4, struct _DIG_DRIVER * a5);

    // address=[0x2fd7490]
    static long __stdcall EncodeDataCB(unsigned long a1, void * a2, long a3, long a4);

    // address=[0x2fd74c0]
    static void __stdcall RecordInputCB(void const * Src, long Size, unsigned long a3);

    // address=[0x2fd74e0]
    long  CopyDataToEncoder(void * a2, long a3, long a4);

    // address=[0x2fd75f0]
    int  GetEncodedData(signed char * a2, int a3);

    // address=[0x2fd7660]
    void  Shutdown(void);

    // address=[0x2fd76d0]
    int  GetFrameSize(void);

    // address=[0x2fd76f0]
    void  ToggleRecording(bool a2);

    // address=[0x2fd7870]
    bool  IsRecording(void);

    // address=[0x2fd7890]
    bool  UsesFullDuplex(void);

    // address=[0x2fd78b0]
    int  GetInputRate(void);

    // address=[0x2fd78d0]
    void  CalcNoiseVol(void);

    // address=[0x2fd7910]
    void  SetOperationMode(bool a2);

private:
    // address=[0x2fd6990]
    bool  InitEncoder(char * a2);

    // address=[0x2fd6b30]
    void  RecordInput(void const * Src, long Size);

    // address=[0x2fd6cf0]
    bool  Downsample(void const * a2, int a3);

    // address=[0x2fd6e60]
    bool  InitInputDriver(int a2);

    // address=[0x2fd7090]
    int  CalcInputBufferSize(int a2);

};


#endif // CVCRECORDER_H
