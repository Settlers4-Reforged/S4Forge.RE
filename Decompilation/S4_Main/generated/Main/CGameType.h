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
    std::wstring &  GetRealPlayerName(int a2);

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
    void  SetLocalSlot(signed char a2);

    // address=[0x14874d0]
    void  SetMCD2TextureSet(bool a2);

    // address=[0x14874f0]
    void  SetMPSavegameID(int a2);

    // address=[0x1487510]
    void  SetMultiPlayerGameID(unsigned int a2);

    // address=[0x1487530]
    void  SetPlayerName(int a1, std::wstring & a2);

    // address=[0x1490f90]
     CGameType(void);

    // address=[0x1491360]
     ~CGameType(void);

    // address=[0x1491490]
    bool  LoadMapData(std::wstring a2, bool a3, unsigned int a4, bool a5, bool a6, int a7, int a8, int a9, bool a10, bool a11);

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
    void  SetPlayerClanShortcut(int a2, std::wstring & a3);

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

};


#endif // CGAMETYPE_H
