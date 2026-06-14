#ifndef CSTATISTIC_H
#define CSTATISTIC_H

#include "CConfigManager/Var/CStaticConfigVarInt.h"
#include "LoadSave/IS4ChunkObject.h"
#include "defines.h"

extern class CStatistic g_cStatistic;

// address=[0x3F29D98]
extern CStaticConfigVarInt g_iDbgIgnoreFightingStrength;
// address=[0x3F29DA4]
extern CStaticConfigVarInt g_iFightingStrengthDivisor;

class CStatistic : public IS4ChunkObject {
  public:
    // address=[0x13adcc0]
    int DefenceStrength100Max(int _iPlayerId) const;

    // address=[0x13add30]
    int GetDontShowLastNPlayers(void);

    // address=[0x13add50]
    int OffenceStrength100Max(int _iPlayerId) const;

    // address=[0x1475d60]
    CStatistic(void);

    // address=[0x1475d90]
    void Clear(void);

    // address=[0x1475dc0]
    void Init(void);

    // address=[0x1475df0]
    void Update(void);

    // address=[0x1475e80]
    void Update(class CStatistic &a2);

    // address=[0x1475ed0]
    virtual void Load(class IS4Chunk &a2);

    // address=[0x1475fc0]
    virtual void Save(class IS4Chunk &a2);

    // address=[0x1476040]
    void DecSettler(int _iPlayerId, int _iSettlerType);

    // address=[0x14762c0]
    void AddSettler(int _iPlayerId, int _iSettlerType);

    // address=[0x1476410]
    int GetSettler(int _iPlayerId, int _iSettlerType) const;

    // address=[0x1476490]
    int GetTotalSettler(int _iPlayerId) const;

    // address=[0x14764f0]
    int GetCivilian(int _iPlayerId) const;

    // address=[0x1476540]
    int GetSoldiers(int _iPlayerId) const;

    // address=[0x14765e0]
    int GetNrOfSoldiers(int _iPlayerId) const;

    // address=[0x1476630]
    void AddProducedSettler(int _iPlayerId, int _iSettlerType);

    // address=[0x14766f0]
    int GetProducedSettler(int _iPlayerId, int _iSettlerType) const;

    // address=[0x1476770]
    int GetTotalProducedSettler(int _iPlayerId) const;

    // address=[0x14767c0]
    int GetBuildingProductivity(int _iPlayerId, int _iBuildingType) const;

    // address=[0x14767f0]
    void AddBuilding(int a2, int a3, int a4);

    // address=[0x1476880]
    void DecBuilding(int _iPlayerId, int _iBuildingType, int _iAmount);

    // address=[0x1476960]
    int GetBuildings(int _iPlayerId, int _iBuildingType) const;

    // address=[0x1476990]
    void AddProducedBuilding(int _iPlayerId, int _iBuilding, int a4);

    // address=[0x1476a50]
    int GetProducedBuildings(int _iPlayerId, int _iBuilding) const;

    // address=[0x1476ad0]
    int GetTotalBuildings(int a2) const;

    // address=[0x1476af0]
    int GetTotalProducedBuildings(int a2) const;

    // address=[0x1476b10]
    int GetTotalBuildingsOfType(int _iPlayerId, int _iBuilding) const;

    // address=[0x1476b50]
    void AddCaptureBuilding(int _iPlayer, int _iTarget, int _iBuilding);

    // address=[0x1476bd0]
    int GetCapturedTowers(int _iPlayerId);

    // address=[0x1476c70]
    int GetLossesTowers(int a2);

    // address=[0x1476ce0]
    void AddConstruction(int _iPlayerId, int _iBuildingType, int _iCount);

    // address=[0x1476d50]
    void DecConstruction(int _iPlayerId, int _iBuildingType, int _iAmount);

    // address=[0x1476e00]
    int GetTotalBuildingsUnderConstruction(int a2) const;

    // address=[0x1476e20]
    int GetConstructions(int _iPlayerId, int _iBuildingType) const;

    // address=[0x1476e50]
    void ChangeResidenceNeed(int _iPlayerId, int _iCount);

    // address=[0x1476e90]
    int GetResidenceNeed(int a2) const;

    // address=[0x1476ec0]
    void ChangeResidenceSpace(int a2, int a3);

    // address=[0x1476f00]
    int GetResidenceSpace(int _iPlayerId) const;

    // address=[0x1476f20]
    void AddGood(int _iPlayerId, int _iGood, int a4);

    // address=[0x1477020]
    void DecGood(int _iPlayerId, int _iGood, int _iCount);

    // address=[0x1477120]
    int GetGood(int _iPlayerId, int _iGood) const;

    // address=[0x14771a0]
    int GetWinGood(int _iPlayerId, int _iGood) const;

    // address=[0x1477220]
    int GetTotalGood(int _iPlayerId) const;

    // address=[0x1477270]
    void AddProducedGoods(int _iPlayerId, int _iGood, int _iCount);

    // address=[0x1477330]
    int GetProducedGoods(int _iPlayerId, int _iGood) const;

    // address=[0x14773b0]
    int GetTotalProducedGood(int _iPlayerId) const;

    // address=[0x1477400]
    void AddVehicle(int _iPlayerId, int _iVehicleType, int _iCount);

    // address=[0x14774c0]
    void DecVehicle(int _iPlayerId, int _iVehicleType, int _iCount);

    // address=[0x1477570]
    int GetVehicle(int a2, int a3) const;

    // address=[0x14775a0]
    int GetTotalVehicle(int _iPlayerId) const;

    // address=[0x14775f0]
    void AddProducedVehicle(int _iPlayerId, int _iVehicleType, int _iCount);

    // address=[0x14776b0]
    int GetProducedVehicle(int _iPlayerId, int _iVehicleType) const;

    // address=[0x1477730]
    int GetTotalProducedVehicled(int _iPlayerId) const;

    // address=[0x1477780]
    int GetMana(int _iPlayerId) const;

    // address=[0x14777d0]
    int GetProducedMana(int _iPlayerId) const;

    // address=[0x1477820]
    void IncKillsOfType(int _iPlayerId, int _iSettlerType);

    // address=[0x14778e0]
    int GetKillsOfType(int _iPlayerId, int _iSettlerType) const;

    // address=[0x1477910]
    int GetKills(int _iPlayerId) const;

    // address=[0x1477930]
    void IncLossesOfType(int _iPlayerId, int _iSettlerType);

    // address=[0x14779f0]
    int GetLossesOfType(int _iPlayerId, int _iSettlerType) const;

    // address=[0x1477a20]
    int GetLosses(int _iPlayerId) const;

    // address=[0x1477a40]
    void IncKillsVehicleOfType(int _iPlayerId, int _iVehicleType);

    // address=[0x1477b00]
    int GetKillsVehicleOfType(int _iPlayerId, int _iVehicleType) const;

    // address=[0x1477b30]
    int GetKillsVehicle(int _iPlayerId) const;

    // address=[0x1477b50]
    void IncLossesVehicleOfType(int _iPlayerId, int _iVehicleType);

    // address=[0x1477c10]
    int GetLossesVehicleOfType(int _iPlayerId, int _iVehicleType) const;

    // address=[0x1477c40]
    int GetLossesVehicle(int _iPlayerId) const;

    // address=[0x1477c60]
    void IncBuildingLosses(int _iPlayerId);

    // address=[0x1477ca0]
    int GetBuildingLosses(int _iPlayerId);

    // address=[0x1477cc0]
    void DecLandSize(int a2, int a3);

    // address=[0x1477cd0]
    void IncLandSize(int a2, int a3);

    // address=[0x1477ce0]
    int GetLandSize(int a2) const;

    // address=[0x1477d00]
    int GetMaxLandSize(int a2) const;

    // address=[0x1477d20]
    int GetLandSizePercent(int a2);

    // address=[0x1477d50]
    void SetOffenceStrength100(int _iPlayerId, int a3);

    // address=[0x1477e10]
    virtual int UsedBuildingMaterial(int _iPlayerId) const;

    // address=[0x1477e60]
    int GetTotalTowers(int _iPlayerId);

    // address=[0x1477f00]
    int GetTotalMineProduction(int _iPlayerId);

    // address=[0x1477fb0]
    int GetTotalFood(int _iPlayerId);

    // address=[0x1478050]
    void SetPlayerExitTime(int _iPlayerId, unsigned int _iExitTime);

    // address=[0x14780a0]
    unsigned int GetPlayerExitTime(int _iPlayerId);

    // address=[0x14780f0]
    void UpdateStartStatistic(void);

    // address=[0x1478330]
    void FillExtraInfo(void);

    // address=[0x1478720]
    static void __cdecl FillEconomyGameMenu(class CInfoExchange *a1, bool a2, bool a3);

    // address=[0x1478890]
    void FreezeEcoStatistic(void);

    // address=[0x147a280]
    int DefenceStrength100(int _iPlayerId) const;

    // address=[0x147a3b0]
    int OffenceStrength100(int _iPlayerId) const;

    // address=[0x14aa6b0]
    CStatistic(class CStatistic const &a2);

    // address=[0x1592160]
    int DefenceStrength256(int _iPlayerId) const;

    // address=[0x1592220]
    int OffenceStrength256(int _iPlayerId) const;

    // address=[0x160db70]
    void SetDontShowLastNPlayers(int _iPlayers);

  protected:
    // address=[0x1478900]
    void CalcPlayerOffenceStrengthBaseValues(void);

    // address=[0x1478a00]
    void UpdateFightingStrength(int _iPlayerId, int _iRace, int _iBuildingType, int a5);

    // address=[0x1478b20]
    void CalculateFightingStrengths(void);

    // address=[0x1478b70]
    void CalculateLandSize(void);

  private:
    // address=[0x1478c50]
    void CalculateMana(void);

    // address=[0x3f20320]
    static bool m_bWonStateSaved;

    // Type information members
  public:
    class SPlayerStatistic {
      public:
        // address=[0x1478cc0]
        void UpdateFightingStrength(int _iPlayerId, int _iBoards, int _iStone, int _iGold, bool _bEyeCatcher);

        // address=[0x1478da0]
        void CalculateFightingStrength(int _iOwnerId);

        int m_iNrOfSettler[67];
        int m_iTotalNrOfSettler;
        int m_iTotalOfSettler[67];
        int m_iProducedSettlers;
        int m_iNrOfCivilian;
        int m_iNrOfSoldier;
        int m_iNrOfBuilding[83];
        int m_iNrOfCapturedBuilding[83];
        int m_iNrOfLostBuilding[83];
        int m_iTotalOfBuilding;
        int m_iNrOfProducedBuilding[83];
        int m_iProducedBuildings;
        int m_iNrOfBuildingSites[83];
        int m_iTotalBuildingSites;
        _BYTE gap_8B0[332];
        int m_iResidenceNeed;
        int m_iResidenceSpace;
        int m_iNrOfGood[43];
        int m_iTotalGoods;
        int m_iNrOfProducedGoods[43];
        int m_iTotalProducedGoods;
        int m_iNrOfVehicle[6];
        int m_iTotalVehicles;
        int m_iNrOfProducedVehicle[6];
        int m_iTotalProducedVehicles;
        int m_iLandSize;
        int m_iOffenceStrengthBase256;
        int m_iTotalBuiltWood;
        int m_iTotalBuildStone;
        int m_iTotalBuiltGold;
        int m_iTotalBuiltEyecatcherWood;
        int m_iTotalBuiltEyecatcherStone;
        int m_iTotalBuiltEyecatcherGold;
        int m_iEffectiveDefenceStrength256;
        int m_iEffectiveOffenceStrength256;
        int m_iTotalUsedBuildingMaterial;
        unsigned char m_iBuildingProductivity[83];
        unsigned char m_iTotalBuildingProductivity;
        int m_iNrOfKill[67];
        int m_iTotalKills;
        int m_iNrOfLoss[67];
        int m_iTotalLosses;
        int m_iTotalBuildingLosses;
        int m_iNrOfVehicleKill[6];
        _BYTE gap_E58[244];
        int m_iTotalVehicleKills;
        int m_iNrOfVehicleLoss[6];
        _BYTE gap_F68[244];
        int m_iTotalVehicleLosses;
        int m_iMana;
        int m_iProducedMana;
        int m_iExitTime;
        int m_iMaxLandSize;
        int m_iDefenceStrength100;
        int m_iOffenceStrength100;
        int m_iWinGoods[43];
        int m_iOffenceStrength100_2;
    };

    SPlayerStatistic m_sPlayerStats[9];
    DWORD m_iDontShowLastNPlayers;
};

#endif // CSTATISTIC_H
