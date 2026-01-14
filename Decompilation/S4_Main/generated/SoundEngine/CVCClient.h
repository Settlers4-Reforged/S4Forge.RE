#ifndef CVCCLIENT_H
#define CVCCLIENT_H

class CVCClient {
public:
    // address=[0x2fd8220]
     CVCClient(void);

    // address=[0x2fd8300]
    virtual  ~CVCClient(void);

    // address=[0x2fd8530]
    bool  Start(int,struct _DIG_DRIVER *,int,char *);

    // address=[0x2fd8650]
    void  Shutdown(void);

    // address=[0x2fd8680]
    bool  ReceivePackage(signed char *);

    // address=[0x2fd8720]
    void  PlayStream(void);

    // address=[0x2fd8820]
    static long __stdcall DecodeDataCB(unsigned long,void *,long,long);

    // address=[0x2fd8850]
    long  CopyDataToDecoder(void *,long,long);

    // address=[0x2fd8970]
    void  Run(void);

    // address=[0x2fd8990]
    void  SetVolume(int);

private:
    // address=[0x2fd7d50]
    void  DecodeData(void);

    // address=[0x2fd7e40]
    bool  InitDecoder(int,char *);

};


#endif // CVCCLIENT_H
