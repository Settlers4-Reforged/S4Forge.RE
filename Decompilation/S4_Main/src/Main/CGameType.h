#ifndef CGAMETYPE_H
#define CGAMETYPE_H

#include "defines.h"

extern class CGameType *g_pGameType;

class CGameType {
  public:
    // address=[0x1361450]
    bool IsLadderGame(void) const;

    // address=[0x13a4100]
    void ChangeLocalSlot(signed char a2);

    // address=[0x13a4140]
    bool const IsClanGame(void);

    // address=[0x13a4160]
    bool const IsSaveGame(void) const;

    // address=[0x13a4180]
    bool IsSlotChangable(int a2, bool *a3);

    // address=[0x13a8490]
    bool IsAddOnMap(void);

    // address=[0x13a84b0]
    bool IsEmptyMap(void);

    // address=[0x1486e10]
    int const GetLocalSlot(void);

    // address=[0x1486e30]
    int GetMapBuildingXMLVersion(void) const;

    // address=[0x1486e50]
    int GetMapObjectXMLVersion(void) const;

    // address=[0x1486e70]
    unsigned int const GetMultiPlayerGameID(void);

    // address=[0x1486ef0]
    std::wstring &GetRealPlayerName(int _iPlayerIndex);

    // address=[0x1486fe0]
    bool IsBlueByteAddOnMap(void);

    // address=[0x1487000]
    bool IsBlueByteMCD2Map(void);

    // address=[0x1487020]
    bool IsCampaignMap(void);

    // address=[0x1487040]
    bool const IsHost(void);

    // address=[0x1487060]
    bool IsMCD2TextureSet(void);

    // address=[0x1487080]
    bool const IsMultiplayerGame(void);

    // address=[0x14873d0]
    void SetBlueByteMCD2Map(bool a2);

    // address=[0x14873f0]
    void SetClanGame(bool a2);

    // address=[0x1487410]
    void SetHost(bool a2);

    // address=[0x1487430]
    void SetLocalSlot(signed char _iLocalSlotNr);

    // address=[0x14874d0]
    void SetMCD2TextureSet(bool a2);

    // address=[0x14874f0]
    void SetMPSavegameID(int a2);

    // address=[0x1487510]
    void SetMultiPlayerGameID(unsigned int a2);

    // address=[0x1487530]
    void SetPlayerName(int _iPlayerIndex, std::wstring &_swpPlayerName);

    // address=[0x1490f90]
    CGameType(void);

    // address=[0x1491360]
    ~CGameType(void);

    // address=[0x1491490]
    bool LoadMapData(std::wstring _sMapName, bool _bAIActive, unsigned int a4, bool a5, bool a6, int _iSetupIndex, int _iAIDifficulty, int a9, bool _bIsLadderGame, bool _bIsClanGame);

    // address=[0x1492f70]
    bool IsMapAvailable(std::wstring &a2, int _iCRC);

    // address=[0x1493090]
    void SetMapCRC(std::wstring &a2);

    // address=[0x1493190]
    int HumanPlayers(void);

    // address=[0x14931e0]
    void Init(void);

    // address=[0x1493620]
    std::wstring ConvertMapNameToMPGameName(void);

    // address=[0x1493660]
    static std::wstring __cdecl ConvertMapNameToMPGameName(std::wstring &a1);

    // address=[0x14936f0]
    std::wstring GetPlayerName(int a2);

    // address=[0x1493810]
    void SetPlayerClanShortcut(int _iPlayerIndex, std::wstring &_swpPlayerClanShortcut);

    // address=[0x1493870]
    int const GetNumberHumanPlayers(void);

    // address=[0x14bce00]
    bool const IsMapLoaded(void);

    // address=[0x14bce20]
    bool const IsWebGame(void);

    // address=[0x15c4a50]
    int const GetMPSavegameID(void);

    // address=[0x15c4ae0]
    std::wstring GetPlayerClanShortcut(int a2);

    // address=[0x15c4dd0]
    void SetLadderGame(bool a2);

    // address=[0x15c4e90]
    void SetWebGame(bool a2);

  private:
    // address=[0x14938c0]
    void PatchMaps(bool a2);

    // Type information members
  public:
    std::wstring m_swGameName;
    std::wstring m_swMapName;
    int m_iWidthHeight;
    int m_bIsEmptyMap;
    int m_iStartResources;
    _DWORD m_iHostAddress;
    _DWORD m_uiNumberAlliances;
    int m_iAllianceSizes[9];
    _DWORD m_iActualPlayerCount;
    DWORD m_sPlayerType[9];
    int m_sPlayerTeam[9];
    DWORD m_uiIPPlayer[9];
    DWORD m_sPlayerPeerId[9];
    int m_sPlayerStartX[9];
    int m_sPlayerStartY[9];
    DWORD m_sPlayerColor[9];
    DWORD m_sPlayerSlot8[9];
    int m_sPlayerRaces[9];
    BYTE m_sPlayerExclusiveColor[9];
    DWORD m_sPlayerMapUploadStarted[9];
    DWORD m_sPlayerSlot12[9];
    DWORD m_sPlayerValidTicks[9];
    unsigned __int8 m_uExtraFlags;
    //_BYTE gap231[3];
    DWORD m_sPlayerSlot15[9];
    _BYTE m_sPlayerSlot16[9];
    _BYTE byte261;
    void *m_pMapData;
    _DWORD m_iMapCRC;
    _DWORD m_iHumanPlayers;
    DWORD m_sPlayerAckDelta[9];
    _DWORD m_iNetworkTimeDelta;
    std::string std__string298;
    int m_iGameType;
    _BYTE m_bIsSaveGame;
    _BYTE bIsAutosave;
    _DWORD m_uiTickCounter;
    std::wstring m_swSaveFile;
    _BYTE m_bAIActive;
    _DWORD dword2E0;
    _DWORD m_iCampaignType;
    _DWORD m_iMissionId;
    _BYTE m_bIsGameWon;
    _DWORD m_iTeamWon;
    std::string m_sTeamName;
    char m_pEconomyGoodsArray[7];
    std::string m_sSessionId;
    std::string m_sProcedureServer;
    _WORD m_iProcedureServerPort;
    _DWORD m_iMapMaxNumPlayers;
    _DWORD m_iFileSize;
    _BYTE m_bHasOpponents;
    _BYTE m_bIsSoloMap;
    _DWORD m_iMode;
    _BYTE m_bEconomyPossible;
    _BYTE m_bCompetetivePossible;
    bool m_bFreeSettlePossible;
    _BYTE m_bConflictPossible;
    _BYTE m_bCooperationPossible;
    _BYTE m_bMapFlagU3;
    _BYTE m_bMapFlagU0;
    _BYTE m_bMapFlagU1;
    _BYTE m_bMapFlagU2;
    _DWORD m_iNumberOfSetups;
    std::string m_sDesciptionText3;
    std::string m_sDesciptionText0;
    std::string m_sDesciptionText1;
    std::string m_sDesciptionText2;
    _BYTE m_bIsEditorMap;
    _BYTE m_bIsCampaignMap;
    BYTE m_bPlayerSlotEmpty[9];
    BYTE m_bDarkTribe[9];
    void *m_pMapPreview;
    _DWORD m_iMapPreviewWidth;
    _DWORD m_iMapPreviewHeight;
    std::wstring m_swpRealPlayerNames[9];
    std::wstring m_swPlayerClanShortcut[9];
    _DWORD m_iMultiPlayerGameID;
    _BYTE m_bIsMapLoaded;
    char m_cLocalSlot;
    _BYTE m_bIsHost;
    _BYTE m_bIsWebGame;
    _DWORD m_iMPSavegameID;
    _BYTE m_bIsClanGame;
    _BYTE m_bIsLadderGame;
    _BYTE m_bIsAddOnMap;
    _BYTE m_bBlueByteAddOnMap;
    _BYTE m_bBlueByteMCD2Map;
    _BYTE m_bIsMCD2TextureSet;
    _DWORD m_iMapObjectXMLVersion;
    _DWORD m_iMapBuildingXMLVersion;
    _DWORD dword618;
    _DWORD dword61C;
};

#endif // CGAMETYPE_H
