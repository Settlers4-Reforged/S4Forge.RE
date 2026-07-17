#ifndef CFOGGING_H
#define CFOGGING_H

#include "defines.h"

class CFogging : public IFogging {
public:
    // address=[0x15d71d0]
    virtual void  Load(class IS4Chunk & a2);

    // address=[0x15d7390]
    virtual void  Save(class IS4Chunk & a2);

    // address=[0x15d7590]
    virtual void  Init(struct T_GFX_MAP_ELEMENT * a2, unsigned char * a3);

    // address=[0x15d76c0]
    virtual void  Done(void);

    // address=[0x15d7770]
    virtual void  Start(void);

    // address=[0x15d7870]
    virtual void  Update(void);

    // address=[0x15d7ce0]
    virtual void  ResetGfxFogLayer(bool a2);

    // address=[0x15d7da0]
    virtual void  UpdateOwnerFogging(int a2, int a3, int a4);

    // address=[0x15d80d0]
    virtual bool  IsPositionVisible(int a2, int a3)const;

    // address=[0x15d81c0]
    virtual bool  RWM(void)const;

    // address=[0x15d8200]
    virtual void  SetRWM(bool a2);

    // address=[0x15d8260]
    virtual void  SetAlliesDontRevealFog(bool a2);

    // address=[0x15d8290]
    virtual void  ResetFogging(void);

    // address=[0x15d82d0]
    virtual void  EnableOrDisableLandExploredCheck(bool a2);

    // address=[0x15d8300]
    virtual bool  IsAlmostAllLandExplored(void);

    // address=[0x15d8350]
    virtual void  LiftFogAtSpot(int a2, int a3, unsigned int a4, int a5);

    // address=[0x15d83e0]
    virtual int  DbgStaticFogValue(int a2)const;

    // address=[0x15d8400]
    virtual int  DbgDynamicFogValue(int a2)const;

    // address=[0x15d8420]
    virtual int  DbgOldFogValue(int a2)const;

    // address=[0x15d8440]
    virtual int  DbgNewFogValue(int a2)const;

    // address=[0x15d8460]
     CFogging(void);

    // address=[0x15dacc0]
     ~CFogging(void);

protected:
    // address=[0x15d8530]
    void  ClearDynamicFoggingAndCalcStatic(void);

    // address=[0x15d8950]
    void  UpdateEntityFogging(int a2, int a3, int a4);

    // address=[0x15d8b70]
    void  CalcYRange(unsigned int a2, unsigned int a3, int & a4, int & a5);

    // address=[0x15d8bf0]
    void  InitializeDynamicLayer(int a2, int a3);

    // address=[0x15d8c90]
    void  SetDynamicLayerToFullBright(int a2, int a3);

    // address=[0x15d8d00]
    void  CalculateDynamicLayer(int a2);

    // address=[0x15d9120]
    void  UpdateGfxLayerAndInitializeDynamicLayer(int a2, int a3);

    // address=[0x15d93d0]
    void  SetWholeGfxLayerAndInitializeDynamicLayer(void);

    // address=[0x15d9490]
    void  SmoothFullBrightStaticFog(int a2, int a3);

    // address=[0x15d9550]
    void  UpdateLandExplorationState(void);

    // address=[0x15d95f0]
    bool  IsSquareLandExploredVW(int a2, int a3);

    // address=[0x15db200]
    bool  RWMEx(void);

    // address=[0x15db310]
    void  UpdateRWM(void);

    // Type information members
public:
    bool dword4;
    _DWORD dword8;
    _DWORD dwordC;
    _DWORD dword10;
    _DWORD dword14;
    _DWORD dword18;
    _DWORD dword1C;
    _DWORD dword20;
    _DWORD dword24;
    _DWORD dword28;
    _DWORD dword2C;
    _DWORD dword30;
    bool dword34;
    _DWORD dword38;
    _DWORD dword3C;
    _DWORD sFogSpotInfo;
    _DWORD dword44;
    _DWORD dword48;
    BYTE dword4c;
    BYTE dword4d;
    BYTE dword4e;

};


#endif // CFOGGING_H
