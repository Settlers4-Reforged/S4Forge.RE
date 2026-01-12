#ifndef CFOGGING_H
#define CFOGGING_H

class CFogging : public IFogging {
public:
    // address=[0x15d71d0]
    virtual void  Load(class IS4Chunk &);

    // address=[0x15d7390]
    virtual void  Save(class IS4Chunk &);

    // address=[0x15d7590]
    virtual void  Init(struct T_GFX_MAP_ELEMENT *,unsigned char *);

    // address=[0x15d76c0]
    virtual void  Done(void);

    // address=[0x15d7770]
    virtual void  Start(void);

    // address=[0x15d7870]
    virtual void  Update(void);

    // address=[0x15d7ce0]
    virtual void  ResetGfxFogLayer(bool);

    // address=[0x15d7da0]
    virtual void  UpdateOwnerFogging(int,int,int);

    // address=[0x15d80d0]
    virtual bool  IsPositionVisible(int,int)const;

    // address=[0x15d81c0]
    virtual bool  RWM(void)const;

    // address=[0x15d8200]
    virtual void  SetRWM(bool);

    // address=[0x15d8260]
    virtual void  SetAlliesDontRevealFog(bool);

    // address=[0x15d8290]
    virtual void  ResetFogging(void);

    // address=[0x15d82d0]
    virtual void  EnableOrDisableLandExploredCheck(bool);

    // address=[0x15d8300]
    virtual bool  IsAlmostAllLandExplored(void);

    // address=[0x15d8350]
    virtual void  LiftFogAtSpot(int,int,unsigned int,int);

    // address=[0x15d83e0]
    virtual int  DbgStaticFogValue(int)const;

    // address=[0x15d8400]
    virtual int  DbgDynamicFogValue(int)const;

    // address=[0x15d8420]
    virtual int  DbgOldFogValue(int)const;

    // address=[0x15d8440]
    virtual int  DbgNewFogValue(int)const;

    // address=[0x15d8460]
     CFogging(void);

    // address=[0x15dacc0]
     ~CFogging(void);

protected:
    // address=[0x15d8530]
    void  ClearDynamicFoggingAndCalcStatic(void);

    // address=[0x15d8950]
    void  UpdateEntityFogging(int,int,int);

    // address=[0x15d8b70]
    void  CalcYRange(unsigned int,unsigned int,int &,int &);

    // address=[0x15d8bf0]
    void  InitializeDynamicLayer(int,int);

    // address=[0x15d8c90]
    void  SetDynamicLayerToFullBright(int,int);

    // address=[0x15d8d00]
    void  CalculateDynamicLayer(int);

    // address=[0x15d9120]
    void  UpdateGfxLayerAndInitializeDynamicLayer(int,int);

    // address=[0x15d93d0]
    void  SetWholeGfxLayerAndInitializeDynamicLayer(void);

    // address=[0x15d9490]
    void  SmoothFullBrightStaticFog(int,int);

    // address=[0x15d9550]
    void  UpdateLandExplorationState(void);

    // address=[0x15d95f0]
    bool  IsSquareLandExploredVW(int,int);

    // address=[0x15db200]
    bool  RWMEx(void);

    // address=[0x15db310]
    void  UpdateRWM(void);

};


#endif // CFOGGING_H
