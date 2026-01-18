#ifndef CPLAYERINFO_H
#define CPLAYERINFO_H

#include "defines.h"

class CPlayerInfo : public IS4ChunkObject {
public:
    // address=[0x1373730]
    int  Race(void)const;

    // address=[0x1397b20]
    int  StartX(void)const;

    // address=[0x1397b40]
    int  StartY(void)const;

    // address=[0x13d1290]
    std::wstring  Name(void)const;

    // address=[0x14972c0]
    void  Clear(void);

    // address=[0x1497320]
    virtual void  Load(class IS4Chunk & a2);

    // address=[0x1497360]
    virtual void  Save(class IS4Chunk & a2);

    // address=[0x14980c0]
     CPlayerInfo(void);

    // address=[0x14982e0]
     ~CPlayerInfo(void);

    // Type information members
private:
    DWORD race;
    DWORD startX;
    DWORD startY;
    DWORD unk_10;
    DWORD unk_14;
    DWORD unk_18;
    DWORD name;
    DWORD unk_20;
    DWORD unk_24;
    DWORD unk_28;
    DWORD unk_2c;
    DWORD unk_30;
    DWORD unk_34;
    DWORD unk_38;
    DWORD unk_3c;

};


#endif // CPLAYERINFO_H
