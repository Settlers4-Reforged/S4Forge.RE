#ifndef CVCRECORDER_H
#define CVCRECORDER_H

class CVCRecorder {
public:
    // address=[0x2fd71f0]
     CVCRecorder(void);

    // address=[0x2fd72b0]
    virtual  ~CVCRecorder(void);

    // address=[0x2fd7380]
    bool  Start(int,char *,int,struct _DIG_DRIVER *);

    // address=[0x2fd7490]
    static long __stdcall EncodeDataCB(unsigned long,void *,long,long);

    // address=[0x2fd74c0]
    static void __stdcall RecordInputCB(void const *,long,unsigned long);

    // address=[0x2fd74e0]
    long  CopyDataToEncoder(void *,long,long);

    // address=[0x2fd75f0]
    int  GetEncodedData(signed char *,int);

    // address=[0x2fd7660]
    void  Shutdown(void);

    // address=[0x2fd76d0]
    int  GetFrameSize(void);

    // address=[0x2fd76f0]
    void  ToggleRecording(bool);

    // address=[0x2fd7870]
    bool  IsRecording(void);

    // address=[0x2fd7890]
    bool  UsesFullDuplex(void);

    // address=[0x2fd78b0]
    int  GetInputRate(void);

    // address=[0x2fd78d0]
    void  CalcNoiseVol(void);

    // address=[0x2fd7910]
    void  SetOperationMode(bool);

private:
    // address=[0x2fd6990]
    bool  InitEncoder(char *);

    // address=[0x2fd6b30]
    void  RecordInput(void const *,long);

    // address=[0x2fd6cf0]
    bool  Downsample(void const *,int);

    // address=[0x2fd6e60]
    bool  InitInputDriver(int);

    // address=[0x2fd7090]
    int  CalcInputBufferSize(int);

};


#endif // CVCRECORDER_H
