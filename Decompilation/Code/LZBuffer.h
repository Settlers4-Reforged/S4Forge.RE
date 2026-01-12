#ifndef LZBUFFER_H
#define LZBUFFER_H

class LZBuffer {
protected:
    // address=[0x2f2a330]
     LZBuffer(void);

    // address=[0x2f2a400]
     ~LZBuffer(void);

    // address=[0x2f2a4a0]
    static int __cdecl _distance(int);

    // address=[0x2f2a4b0]
    int  _nMatch(int,unsigned char const *,int);

    // address=[0x2f2a640]
    void  _toBuf(unsigned char);

    // address=[0x2f2a690]
    void  _toBuf(unsigned char const *,unsigned int);

    // address=[0x2f2a920]
    static int __cdecl _wrap(unsigned long);

    // address=[0x2f2c400]
    void  _bufCpy(unsigned char *,int,unsigned int);

};


#endif // LZBUFFER_H
