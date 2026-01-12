#ifndef LZHLENCODERSTAT_H
#define LZHLENCODERSTAT_H

class LZHLEncoderStat {
public:
    // address=[0x2f2aa40]
     LZHLEncoderStat(void);

    // address=[0x2f2aad0]
     ~LZHLEncoderStat(void);

    // address=[0x2f2ab00]
    void  calcStat(int *);

    // address=[0x3e2d390]
    static struct Symbol * LZHLEncoderStat::symbolTable0;

private:
    // address=[0x2f2c360]
    static void __cdecl _addGroup(int *,int,int);

};


#endif // LZHLENCODERSTAT_H
