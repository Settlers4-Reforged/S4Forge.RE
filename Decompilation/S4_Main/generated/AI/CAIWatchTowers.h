#ifndef CAIWATCHTOWERS_H
#define CAIWATCHTOWERS_H

#include "defines.h"

class CAIWatchTowers : public IAIWatchTowers {
public:
    // address=[0x132f0e0]
     CAIWatchTowers(void);

    // address=[0x132f120]
    virtual void  Init(void);

    // address=[0x132f1a0]
    virtual void  Done(void);

    // address=[0x132f1c0]
    virtual int  AddWatchTower(int a2, int a3, int a4);

    // address=[0x132f230]
    virtual void  DelWatchTower(int a2);

    // address=[0x132f2c0]
    virtual void  RegisterCallback(void (__cdecl*)(int,int) a2);

    // address=[0x132f320]
    virtual void  UnregisterCallback(void);

    // address=[0x132f340]
    virtual void  CalculateAndCallback(void);

    // address=[0x132f420]
    virtual void  CalculateAll(void);

protected:
    // address=[0x132f480]
    int  NextUsedWatchTower(int a2);

    // address=[0x132f540]
    int  PushUndef(void);

    // address=[0x132f580]
    void  Remove(int a2);

    // address=[0x132f5f0]
    bool  ValidIndex(int a2)const;

    // address=[0x132f620]
    static void __cdecl DefaultCallback(int,int);

    // address=[0x132f840]
    int  Count(void)const;

    // address=[0x132f860]
    int  First(void)const;

    // address=[0x132f880]
    int  Last(void)const;

    // address=[0x132f980]
    bool  ValidUsedWatchTower(int a2)const;

    // address=[0x132fa10]
    class CAIWatchTowerEx &  WatchTower(int a2);

    // address=[0x132fa30]
    class CAIWatchTower const &  WatchTower(int a2)const;

};


#endif // CAIWATCHTOWERS_H
