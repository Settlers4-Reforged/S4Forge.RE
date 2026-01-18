#ifndef CSIEDLERAI_H
#define CSIEDLERAI_H

#include "defines.h"

class CSiedlerAI : public IAI_Module {
public:
    // address=[0x2f34cd0]
    void  InitNetAI(int a2);

    // address=[0x2f34d60]
     CSiedlerAI(class CEcoSectorAI * a2, int a3);

    // address=[0x2f34e50]
     ~CSiedlerAI(void);

    // address=[0x2f34e70]
    virtual class CParameterSet *  GenerateAlternatives(int a2, class CParam * a3);

    // address=[0x2f37a70]
    virtual class CConditionSet *  Condition(int a2, class CParam * a3);

    // address=[0x2f389f0]
    virtual double  Valuation(int a2, class CParam * a3, int a4, int a5);

    // address=[0x2f38ca0]
    virtual int  RepeatingBehaviour(int a2, class CParam * a3);

    // address=[0x2f38cd0]
    virtual int  PreferExternSolution(int a2, class CParam * a3);

    // address=[0x2f38d10]
    virtual class CSolutionTree *  ImportSolution(int a2, class CParam * a3);

    // address=[0x2f38da0]
    virtual void  Consequence(int a2, class CParam * a3);

    // address=[0x2f38db0]
    virtual void  ExecuteAction(int a2, class CParam * a3);

    // address=[0x2f38f70]
    virtual void  PreExecuteAction(int a2, class CParam * a3);

    // address=[0x2f38f90]
    void  GetInvokeBuildingType(class IScheduleEntry * a2, enum BUILDING_TYPES * a3);

    // address=[0x2f39150]
    int  GetInvokePosition(int a2, int a3, int a4, int a5, int a6);

    // address=[0x2f39260]
    int  GetBestBuilding(struct SBUILDINFODATA * a2, int a3, int & a4);

    // address=[0x2f392f0]
    int  ScoringBuilding(struct SBUILDINFODATA * a2);

    // address=[0x2f39310]
    double  GeneralValuation(enum BUILDING_TYPES a2, int a3, int a4, bool a5);

    // address=[0x2f393a0]
    class CDynList *  CloneMemory(void);

    // address=[0x2f393b0]
    virtual class tmp_mem *  tmp_speichern(void);

    // address=[0x2f393c0]
    virtual void  tmp_rueckspeichern(class tmp_mem * a2);

};


#endif // CSIEDLERAI_H
