#ifndef CVCCLIENT_H
#define CVCCLIENT_H

#include "defines.h"

class CVCClient {
public:
    // address=[0x2fd8220]
     CVCClient(void);

    // address=[0x2fd8300]
    virtual  ~CVCClient(void);

    // address=[0x2fd8530]
    bool  Start(int a2, struct _DIG_DRIVER * a3, int a4, char * a5);

    // address=[0x2fd8650]
    void  Shutdown(void);

    // address=[0x2fd8680]
    bool  ReceivePackage(signed char * Src);

    // address=[0x2fd8720]
    void  PlayStream(void);

    // address=[0x2fd8820]
    static long __stdcall DecodeDataCB(unsigned long a1, void * a2, long a3, long a4);

    // address=[0x2fd8850]
    long  CopyDataToDecoder(void * a2, long a3, long a4);

    // address=[0x2fd8970]
    void  Run(void);

    // address=[0x2fd8990]
    void  SetVolume(int a2);

private:
    // address=[0x2fd7d50]
    void  DecodeData(void);

    // address=[0x2fd7e40]
    bool  InitDecoder(int a2, char * a3);

};


#endif // CVCCLIENT_H
