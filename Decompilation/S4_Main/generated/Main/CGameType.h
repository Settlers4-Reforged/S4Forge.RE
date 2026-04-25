#ifndef CGAMETYPE_H
#define CGAMETYPE_H

#include "defines.h"

class CGameType {
public:
    // address=[0x1361450]
    bool  IsLadderGame(void)const;

    // address=[0x13a4100]
    void  ChangeLocalSlot(signed char a2);

    // address=[0x13a4140]
    bool const  IsClanGame(void);

    // address=[0x13a4160]
    bool const  IsSaveGame(void)const;

    // address=[0x13a4180]
    bool  IsSlotChangable(int a2, bool * a3);

    // address=[0x13a8490]
    bool  IsAddOnMap(void);

    // address=[0x13a84b0]
    bool  IsEmptyMap(void);

    // address=[0x1486e10]
    int const  GetLocalSlot(void);

    // address=[0x1486e30]
    int  GetMapBuildingXMLVersion(void)const;

    // address=[0x1486e50]
    int  GetMapObjectXMLVersion(void)const;

    // address=[0x1486e70]
    unsigned int const  GetMultiPlayerGameID(void);

    // address=[0x1486ef0]
    std::wstring &  GetRealPlayerName(int _iPlayerIndex);

    // address=[0x1486fe0]
    bool  IsBlueByteAddOnMap(void);

    // address=[0x1487000]
    bool  IsBlueByteMCD2Map(void);

    // address=[0x1487020]
    bool  IsCampaignMap(void);

    // address=[0x1487040]
    bool const  IsHost(void);

    // address=[0x1487060]
    bool  IsMCD2TextureSet(void);

    // address=[0x1487080]
    bool const  IsMultiplayerGame(void);

    // address=[0x14873d0]
    void  SetBlueByteMCD2Map(bool a2);

    // address=[0x14873f0]
    void  SetClanGame(bool a2);

    // address=[0x1487410]
    void  SetHost(bool a2);

    // address=[0x1487430]
    void  SetLocalSlot(signed char _iLocalSlotNr);

    // address=[0x14874d0]
    void  SetMCD2TextureSet(bool a2);

    // address=[0x14874f0]
    void  SetMPSavegameID(int a2);

    // address=[0x1487510]
    void  SetMultiPlayerGameID(unsigned int a2);

    // address=[0x1487530]
    void  SetPlayerName(int _iPlayerIndex, std::wstring & _swpPlayerName);

    // address=[0x1490f90]
     CGameType(void);

    // address=[0x1491360]
     ~CGameType(void);

    // address=[0x1491490]
    bool  LoadMapData(std::wstring a2, bool _bAIActive, unsigned int a4, bool a5, bool a6, int _iSetupIndex, int _iAIDifficulty, int a9, bool a10, bool a11);

    // address=[0x1492f70]
    bool  IsMapAvailable(std::wstring & a2, int a3);

    // address=[0x1493090]
    void  SetMapCRC(std::wstring & a2);

    // address=[0x1493190]
    int  HumanPlayers(void);

    // address=[0x14931e0]
    void  Init(void);

    // address=[0x1493620]
    std::wstring  ConvertMapNameToMPGameName(void a2);

    // address=[0x1493660]
    static std::wstring __cdecl ConvertMapNameToMPGameName(std::wstring & a1);

    // address=[0x14936f0]
    std::wstring  GetPlayerName(int a2);

    // address=[0x1493810]
    void  SetPlayerClanShortcut(int _iPlayerIndex, std::wstring & _swpPlayerClanShortcut);

    // address=[0x1493870]
    int const  GetNumberHumanPlayers(void);

    // address=[0x14bce00]
    bool const  IsMapLoaded(void);

    // address=[0x14bce20]
    bool const  IsWebGame(void);

    // address=[0x15c4a50]
    int const  GetMPSavegameID(void);

    // address=[0x15c4ae0]
    std::wstring  GetPlayerClanShortcut(int a2);

    // address=[0x15c4dd0]
    void  SetLadderGame(bool a2);

    // address=[0x15c4e90]
    void  SetWebGame(bool a2);

private:
    // address=[0x14938c0]
    void  PatchMaps(bool a2);

    // Type information members
public:
    std::wstring string0;
    std::wstring m_swMapName;
    _DWORD m_iWidthHeight;
    _DWORD m_bIsEmptyMap;
    _DWORD m_iStartResources;
    _DWORD dword44;
    _DWORD m_uiNumberAlliances;
    int[9] ptr4c;
    _DWORD m_iActualPlayerCount;
    DWORD[9] m_sPlayerType;
    int[9] m_sPlayerTeam;
    DWORD[9] m_sPlayerIP;
    DWORD[9] m_sPlayerPeerId;
    int[9] m_sPlayerStartX;
    int[9] m_sPlayerStartY;
    DWORD[9] m_sPlayerColor;
    DWORD[9] m_sPlayerSlot8;
    int[9] m_sPlayerRaces;
    BYTE[9] m_sPlayerSlot10;
    DWORD[9] m_sPlayerSlot11;
    DWORD[9] m_sPlayerSlot12;
    DWORD[9] m_sPlayerSlot13;
    _BYTE byte230;
    _BYTE[3] gap231;
    DWORD[9] m_sPlayerSlot15;
    _BYTE[9] m_sPlayerSlot16;
    _BYTE byte261;
    _DWORD dword264;
    _DWORD m_iMapCRC;
    _DWORD dword26C;
    DWORD[9] m_sPlayerSlot14;
    _DWORD m_iNetworkTimeDelta;
    std::string std__string298;
    _DWORD m_iGameType;
    _BYTE m_bIsSaveGame;
    _BYTE byte2B9;
    _DWORD m_uiTickCounter;
    std::wstring m_swSaveFile;
    _BYTE m_bAIActive;
    _DWORD dword2E0;
    _DWORD m_iCampaignType;
    _DWORD dword2E8;
    _BYTE m_bIsGameWon;
    _DWORD m_iTeamWon;
    std::string m_swpTeamName;
    char[7] m_pEconomyGoodsArray;
    std::string std__string318;
    std::string std__string334;
    _WORD word350;
    _DWORD m_iMapMaxNumPlayers;
    _DWORD m_iFileSize;
    _BYTE byte35C;
    _BYTE byte35D;
    _DWORD m_iMode;
    _BYTE m_bEconomyPossible;
    _BYTE m_bCompetetivePossible;
    _BYTE m_bFreeSettlePossible;
    _BYTE m_bConflictPossible;
    _BYTE m_bCooperationPossible;
    _BYTE byte369;
    _BYTE byte36A;
    _BYTE byte36B;
    _BYTE byte36C;
    _DWORD m_iNumberOfSetups;
    std::string std__string374;
    std::string std__string390;
    std::string std__string3AC;
    std::string std__string3C8;
    _BYTE m_bIsEditorMap;
    _BYTE m_bIsCampaignMap;
    _BYTE[18] gap3E6;
    _DWORD dword3F8;
    _DWORD dword3FC;
    _DWORD dword400;
    std::wstring[9] m_swpRealPlayerNames;
    std::wstring[9] m_swPlayerClanShortcut;
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
