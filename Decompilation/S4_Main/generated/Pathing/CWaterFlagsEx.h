#ifndef CWATERFLAGSEX_H
#define CWATERFLAGSEX_H

class CWaterFlagsEx {
public:
    // address=[0x15fd780]
    static void __cdecl BlockRowPrimary(unsigned char *,int);

    // address=[0x15fd7f0]
    static void __cdecl BlockColPrimary(unsigned char *,int);

    // address=[0x15fd870]
    static void __cdecl CalcWaterFlags(void);

};


#endif // CWATERFLAGSEX_H
