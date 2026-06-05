#ifndef CGAMECHUNKGENERAL_H
#define CGAMECHUNKGENERAL_H

#include "defines.h"

class CGameChunkGeneral : public IS4ChunkObject {
public:
    // address=[0x13eb8a0]
     CGameChunkGeneral(void);

    // address=[0x13eb9f0]
    virtual void  Load(class IS4Chunk & a2);

    // address=[0x13ec060]
    virtual void  Save(class IS4Chunk & a2);

    // address=[0x13ec470]
    void  GenerateCRC(void);

    // Type information members
public:
    _DWORD m_uMapFlags;
    _DWORD m_uCampaignType;
    _DWORD dwordC;
    _DWORD dword10;
    _DWORD m_iVersionMajor;
    _DWORD m_iVersionMinor;
    _DWORD m_iVersionBuild;
    _DWORD m_iWidthHeight;
    _BYTE[64] gap24;
    wchar_t[256] m_swUnknown;
    _BYTE[26] byte264;
    _DWORD m_iMapMaxNumPlayers;
    _DWORD m_uiPlayerCount;
    CSavedPlayer[8] m_sPlayers;
    _DWORD m_uMultiPlayerGameID;
    _BYTE[1024] byte52C;
    _BYTE byte92C;
    _BYTE[7] m_pEconomyGoodsArray;
    _BYTE byte934;
    _BYTE[3] gap935;
    _DWORD m_iTeamWon;
    _BYTE m_cLocalSlot;
    _BYTE m_bIsHost;
    _BYTE[2] gap93E;
    _DWORD m_uSavegameId;
    _BYTE m_bIsClanGame;
    _BYTE[3] gap945;
    _DWORD m_uiTickCounter;
    _DWORD m_iNetworkTimeDelta;
    _DWORD dword950;
    _DWORD dword954;
    _DWORD dword958;
    _DWORD dword95C;
    _DWORD dword960;
    _BYTE byte964;

};


#endif // CGAMECHUNKGENERAL_H
