#ifndef CSTATISTIC_H
#define CSTATISTIC_H

class CStatistic : public IS4ChunkObject {
public:
    // address=[0x13adcc0]
    int  DefenceStrength100Max(int)const;

    // address=[0x13add30]
    int  GetDontShowLastNPlayers(void);

    // address=[0x13add50]
    int  OffenceStrength100Max(int)const;

    // address=[0x1475d60]
     CStatistic(void);

    // address=[0x1475d90]
    void  Clear(void);

    // address=[0x1475dc0]
    void  Init(void);

    // address=[0x1475df0]
    void  Update(void);

    // address=[0x1475e80]
    void  Update(class CStatistic &);

    // address=[0x1475ed0]
    virtual void  Load(class IS4Chunk &);

    // address=[0x1475fc0]
    virtual void  Save(class IS4Chunk &);

    // address=[0x1476040]
    void  DecSettler(int,int);

    // address=[0x14762c0]
    void  AddSettler(int,int);

    // address=[0x1476410]
    int  GetSettler(int,int)const;

    // address=[0x1476490]
    int  GetTotalSettler(int)const;

    // address=[0x14764f0]
    int  GetCivilian(int)const;

    // address=[0x1476540]
    int  GetSoldiers(int)const;

    // address=[0x14765e0]
    int  GetNrOfSoldiers(int)const;

    // address=[0x1476630]
    void  AddProducedSettler(int,int);

    // address=[0x14766f0]
    int  GetProducedSettler(int,int)const;

    // address=[0x1476770]
    int  GetTotalProducedSettler(int)const;

    // address=[0x14767c0]
    int  GetBuildingProductivity(int,int)const;

    // address=[0x14767f0]
    void  AddBuilding(int,int,int);

    // address=[0x1476880]
    void  DecBuilding(int,int,int);

    // address=[0x1476960]
    int  GetBuildings(int,int)const;

    // address=[0x1476990]
    void  AddProducedBuilding(int,int,int);

    // address=[0x1476a50]
    int  GetProducedBuildings(int,int)const;

    // address=[0x1476ad0]
    int  GetTotalBuildings(int)const;

    // address=[0x1476af0]
    int  GetTotalProducedBuildings(int)const;

    // address=[0x1476b10]
    int  GetTotalBuildingsOfType(int,int)const;

    // address=[0x1476b50]
    void  AddCaptureBuilding(int,int,int);

    // address=[0x1476bd0]
    int  GetCapturedTowers(int);

    // address=[0x1476c70]
    int  GetLossesTowers(int);

    // address=[0x1476ce0]
    void  AddConstruction(int,int,int);

    // address=[0x1476d50]
    void  DecConstruction(int,int,int);

    // address=[0x1476e00]
    int  GetTotalBuildingsUnderConstruction(int)const;

    // address=[0x1476e20]
    int  GetConstructions(int,int)const;

    // address=[0x1476e50]
    void  ChangeResidenceNeed(int,int);

    // address=[0x1476e90]
    int  GetResidenceNeed(int)const;

    // address=[0x1476ec0]
    void  ChangeResidenceSpace(int,int);

    // address=[0x1476f00]
    int  GetResidenceSpace(int)const;

    // address=[0x1476f20]
    void  AddGood(int,int,int);

    // address=[0x1477020]
    void  DecGood(int,int,int);

    // address=[0x1477120]
    int  GetGood(int,int)const;

    // address=[0x14771a0]
    int  GetWinGood(int,int)const;

    // address=[0x1477220]
    int  GetTotalGood(int)const;

    // address=[0x1477270]
    void  AddProducedGoods(int,int,int);

    // address=[0x1477330]
    int  GetProducedGoods(int,int)const;

    // address=[0x14773b0]
    int  GetTotalProducedGood(int)const;

    // address=[0x1477400]
    void  AddVehicle(int,int,int);

    // address=[0x14774c0]
    void  DecVehicle(int,int,int);

    // address=[0x1477570]
    int  GetVehicle(int,int)const;

    // address=[0x14775a0]
    int  GetTotalVehicle(int)const;

    // address=[0x14775f0]
    void  AddProducedVehicle(int,int,int);

    // address=[0x14776b0]
    int  GetProducedVehicle(int,int)const;

    // address=[0x1477730]
    int  GetTotalProducedVehicled(int)const;

    // address=[0x1477780]
    int  GetMana(int)const;

    // address=[0x14777d0]
    int  GetProducedMana(int)const;

    // address=[0x1477820]
    void  IncKillsOfType(int,int);

    // address=[0x14778e0]
    int  GetKillsOfType(int,int)const;

    // address=[0x1477910]
    int  GetKills(int)const;

    // address=[0x1477930]
    void  IncLossesOfType(int,int);

    // address=[0x14779f0]
    int  GetLossesOfType(int,int)const;

    // address=[0x1477a20]
    int  GetLosses(int)const;

    // address=[0x1477a40]
    void  IncKillsVehicleOfType(int,int);

    // address=[0x1477b00]
    int  GetKillsVehicleOfType(int,int)const;

    // address=[0x1477b30]
    int  GetKillsVehicle(int)const;

    // address=[0x1477b50]
    void  IncLossesVehicleOfType(int,int);

    // address=[0x1477c10]
    int  GetLossesVehicleOfType(int,int)const;

    // address=[0x1477c40]
    int  GetLossesVehicle(int)const;

    // address=[0x1477c60]
    void  IncBuildingLosses(int);

    // address=[0x1477ca0]
    int  GetBuildingLosses(int);

    // address=[0x1477cc0]
    void  DecLandSize(int,int);

    // address=[0x1477cd0]
    void  IncLandSize(int,int);

    // address=[0x1477ce0]
    int  GetLandSize(int)const;

    // address=[0x1477d00]
    int  GetMaxLandSize(int)const;

    // address=[0x1477d20]
    int  GetLandSizePercent(int);

    // address=[0x1477d50]
    void  SetOffenceStrength100(int,int);

    // address=[0x1477e10]
    virtual int  UsedBuildingMaterial(int)const;

    // address=[0x1477e60]
    int  GetTotalTowers(int);

    // address=[0x1477f00]
    int  GetTotalMineProduction(int);

    // address=[0x1477fb0]
    int  GetTotalFood(int);

    // address=[0x1478050]
    void  SetPlayerExitTime(int,unsigned int);

    // address=[0x14780a0]
    unsigned int  GetPlayerExitTime(int);

    // address=[0x14780f0]
    void  UpdateStartStatistic(void);

    // address=[0x1478330]
    void  FillExtraInfo(void);

    // address=[0x1478720]
    static void __cdecl FillEconomyGameMenu(class CInfoExchange *,bool,bool);

    // address=[0x1478890]
    void  FreezeEcoStatistic(void);

    // address=[0x147a280]
    int  DefenceStrength100(int)const;

    // address=[0x147a3b0]
    int  OffenceStrength100(int)const;

    // address=[0x14aa6b0]
     CStatistic(class CStatistic const &);

    // address=[0x1592160]
    int  DefenceStrength256(int)const;

    // address=[0x1592220]
    int  OffenceStrength256(int)const;

    // address=[0x160db70]
    void  SetDontShowLastNPlayers(int);

protected:
    // address=[0x1478900]
    void  CalcPlayerOffenceStrengthBaseValues(void);

    // address=[0x1478a00]
    void  UpdateFightingStrength(int,int,int,int);

    // address=[0x1478b20]
    void  CalculateFightingStrengths(void);

    // address=[0x1478b70]
    void  CalculateLandSize(void);

private:
    // address=[0x1478c50]
    void  CalculateMana(void);

    // address=[0x3f20320]
    static bool m_bWonStateSaved;

};


#endif // CSTATISTIC_H
