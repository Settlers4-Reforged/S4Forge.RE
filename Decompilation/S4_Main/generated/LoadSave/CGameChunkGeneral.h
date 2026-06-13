#ifndef CGAMECHUNKGENERAL_H
#define CGAMECHUNKGENERAL_H

#include "defines.h"

class CGameChunkGeneral : public IS4ChunkObject {
  public:
    // address=[0x13eb8a0]
    CGameChunkGeneral(void);

    // address=[0x13eb9f0]
    virtual void Load(class IS4Chunk &a2);

    // address=[0x13ec060]
    virtual void Save(class IS4Chunk &a2);

    // address=[0x13ec470]
    void GenerateCRC(void);

    // Type information members
  public:
    _DWORD m_uMapFlags;
    _DWORD m_uCampaneID;
    _DWORD m_iMissionId;
    _DWORD m_iGameType;
    _DWORD m_iVersionMajor;
    _DWORD m_iVersionMinor;
    _DWORD m_iVersionBuild;
    _DWORD m_iWidthHeight;
    wchar_t[32] m_spGameName;
    wchar_t[256] m_swMapName;
    char[26] m_spSaveDateTime;
    _DWORD m_iMapMaxNumPlayers;
    _DWORD m_uiPlayerCount;
    CSavedPlayer[8] m_sPlayers;
    _DWORD m_uMultiPlayerGameID;
    _BYTE[1024] m_spDesciptionText;
    _BYTE byte92C;
    _BYTE[7] m_pEconomyGoodsArray;
    _BYTE m_iMode;
    _DWORD m_iTeamWon;
    _BYTE m_cLocalSlot;
    _BYTE m_bIsHost;
    _DWORD m_uSavegameId;
    _BYTE m_bIsClanGame;
    _DWORD m_uiTickCounter;
    _DWORD m_iNetworkTimeDelta;
    _DWORD m_iSeed;
    _DWORD m_iRandCalls;
    _DWORD m_uCamX;
    _DWORD m_uCamY;
    _DWORD m_uZoom;
    bool m_bNewVersion;
};

#endif // CGAMECHUNKGENERAL_H
