#ifndef CSIEDLERAI_H
#define CSIEDLERAI_H

class CSiedlerAI : public IAI_Module {
public:
    // address=[0x2f34cd0]
    void  InitNetAI(int);

    // address=[0x2f34d60]
     CSiedlerAI(class CEcoSectorAI *,int);

    // address=[0x2f34e50]
     ~CSiedlerAI(void);

    // address=[0x2f34e70]
    virtual class CParameterSet *  GenerateAlternatives(int,class CParam *);

    // address=[0x2f37a70]
    virtual class CConditionSet *  Condition(int,class CParam *);

    // address=[0x2f389f0]
    virtual double  Valuation(int,class CParam *,int,int);

    // address=[0x2f38ca0]
    virtual int  RepeatingBehaviour(int,class CParam *);

    // address=[0x2f38cd0]
    virtual int  PreferExternSolution(int,class CParam *);

    // address=[0x2f38d10]
    virtual class CSolutionTree *  ImportSolution(int,class CParam *);

    // address=[0x2f38da0]
    virtual void  Consequence(int,class CParam *);

    // address=[0x2f38db0]
    virtual void  ExecuteAction(int,class CParam *);

    // address=[0x2f38f70]
    virtual void  PreExecuteAction(int,class CParam *);

    // address=[0x2f38f90]
    void  GetInvokeBuildingType(class IScheduleEntry *,enum BUILDING_TYPES *);

    // address=[0x2f39150]
    int  GetInvokePosition(int,int,int,int,int);

    // address=[0x2f39260]
    int  GetBestBuilding(struct SBUILDINFODATA *,int,int &);

    // address=[0x2f392f0]
    int  ScoringBuilding(struct SBUILDINFODATA *);

    // address=[0x2f39310]
    double  GeneralValuation(enum BUILDING_TYPES,int,int,bool);

    // address=[0x2f393a0]
    class CDynList *  CloneMemory(void);

    // address=[0x2f393b0]
    virtual class tmp_mem *  tmp_speichern(void);

    // address=[0x2f393c0]
    virtual void  tmp_rueckspeichern(class tmp_mem *);

};


#endif // CSIEDLERAI_H
