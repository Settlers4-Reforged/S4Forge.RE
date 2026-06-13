#include "CGameChunkGeneral.h"

#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"
#include "Crc.h"
#include "Defines/Campaign.h"

#include <codecvt>

// Definitions for class CGameChunkGeneral

// address=[0x13eb8a0]
// Decompiled from CGameChunkGeneral *__thiscall CGameChunkGeneral::CGameChunkGeneral(CGameChunkGeneral *this)
CGameChunkGeneral::CGameChunkGeneral(void) : IS4ChunkObject() {
    this->m_uMapFlags = 0;
    this->m_uCampaneID = 0;
    this->m_iMissionId = 0;
    this->m_iGameType = 0;
    this->m_iVersionMajor = 0;
    this->m_iVersionMinor = 0;
    this->m_iVersionBuild = 0;
    this->m_iWidthHeight = 0;
    this->m_iMapMaxNumPlayers = 0;
    this->m_uiPlayerCount = 0;
    this->m_uMultiPlayerGameID = 0;
    this->byte92C = 0;
    this->m_iMode = 0;
    this->m_iTeamWon = 0;
    this->m_cLocalSlot = 0;
    this->m_bIsHost = 0;
    this->m_uSavegameId = 0;
    this->m_bIsClanGame = 0;
    this->m_uiTickCounter = 0;
    this->m_iNetworkTimeDelta = 0;
    this->m_iSeed = 0;
    this->m_iRandCalls = 0;
    this->m_uCamX = 0;
    this->m_uCamY = 0;
    this->m_uZoom = 0;
    this->m_bNewVersion = 0;
}

// address=[0x13eb9f0]
// Decompiled from void __thiscall CGameChunkGeneral::Load(CGameChunkGeneral *this, struct IS4Chunk *a2)
void CGameChunkGeneral::Load(class IS4Chunk &a2) {
    int uGameChunkVersion;         // [esp+Ch] [ebp-490h] BYREF
    unsigned __int8 uCampaignType; // [esp+13h] [ebp-489h] BYREF
    memset(this->m_spDesciptionText, 0, sizeof(this->m_spDesciptionText));
    this->m_iMode = 0;
    this->byte92C = 0;
    memset(this->m_pEconomyGoodsArray, 0, sizeof(this->m_pEconomyGoodsArray));
    this->m_cLocalSlot = -1;
    this->m_bIsHost = 0;
    this->m_uSavegameId = 0;
    this->m_bIsClanGame = 0;
    this->m_iSeed = 0x1BB7353;
    this->m_iRandCalls = 0;
    a2.LoadSignature(761539483);
    uGameChunkVersion = 0;
    a2.Load(&uGameChunkVersion, 4);
    if(uGameChunkVersion >= 3) {
        a2.Load(&this->m_uMapFlags, 4);
        a2.Load(&this->m_iGameType, 4);
        a2.Load(&this->m_iVersionMajor, 4);
        a2.Load(&this->m_iVersionMinor, 4);
        a2.Load(&this->m_iVersionBuild, 4);
        a2.Load(&this->m_iWidthHeight, 4);
        a2.Load(this->m_spGameName, 64);
        if(uGameChunkVersion < 10) {
            char Str[1024]; // [esp+8Ch] [ebp-410h] BYREF
            a2.Load(Str, 1024);
            std::wstring_convert<std::codecvt_utf8<wchar_t>> sConv; // TODO: replace with non-deprecated version
            wcscpy(this->m_swMapName, sConv.from_bytes(Str).c_str());
        } else {
            a2.Load(this->m_swMapName, 512);
        }
        a2.Load(this->m_spSaveDateTime, 26);
        a2.Load(&this->m_iMapMaxNumPlayers, 4);
        a2.Load(&this->m_uiPlayerCount, 4);
        for(int i = 0; i < 8; ++i)
            this->m_sPlayers[i].Load(a2);
        a2.Load(&this->m_uMultiPlayerGameID, 4);
        a2.Load(&this->m_iTeamWon, 4);
        a2.Load(&this->m_uiTickCounter, 4);
        a2.Load(&this->m_iNetworkTimeDelta, 4);
        uCampaignType = 0;
        a2.Load(&uCampaignType, 1);
        if(uCampaignType >= 0x19u) {
            BB_REPORT("Load(): Invalid campaign type!")
            uCampaignType = 0;
        }
        this->m_uCampaneID = uCampaignType;
        a2.Load(&this->m_iMissionId, 4);
        a2.LoadSignature(761539484);
    }
    if(uGameChunkVersion >= 4) {
        a2.LoadSignature(0x7D642B9B);
        a2.Load(this->m_spDesciptionText, 1024);
        a2.LoadSignature(0x8D642B9C);
    }
    if(uGameChunkVersion >= 5) {
        a2.LoadSignature(0xD642B9B);
        a2.Load(&this->m_iMode, 1);
        a2.Load(&this->byte92C, 1);
        a2.Load(this->m_pEconomyGoodsArray, 7);
        a2.LoadSignature(493104027);
    }
    if(uGameChunkVersion >= 6) {
        a2.Load(&this->m_cLocalSlot, 1);
        a2.Load(&this->m_bIsHost, 1);
        a2.Load(&this->m_uSavegameId, 4);
        a2.LoadSignature(493104029);
    }
    if(uGameChunkVersion >= 7) {
        a2.Load(&this->m_bIsClanGame, 1);
        a2.LoadSignature(493104030);
    }
    if(uGameChunkVersion >= 8) {
        this->m_iSeed = a2.LoadUnsigned32();
        this->m_iRandCalls = a2.LoadUnsigned32();
        a2.LoadSignature(493104031);
    }
    if(uGameChunkVersion >= 9) {
        this->m_uCamX = a2.LoadUnsigned32();
        this->m_uCamY = a2.LoadUnsigned32();
        this->m_uZoom = a2.LoadUnsigned32();
        this->m_bNewVersion = 1;
        a2.LoadSignature(493104032);
    }
    if(uGameChunkVersion < 1 || uGameChunkVersion > 10) {
        BBSupportTracePrintF(3, "Defect CGameChunkGeneral data!");
        throw CS4InvalidMapException();
    }
}

// address=[0x13ec060]
// Decompiled from void __thiscall CGameChunkGeneral::Save(CGameChunkGeneral *this, struct IS4Chunk *a2)
void CGameChunkGeneral::Save(class IS4Chunk &a2) {
    // [esp+0h] [ebp-Ch]
    char m_uCampaignType; // [esp+Bh] [ebp-1h] BYREF

    BB_ASSERT(m_uCampaneID >= CAMPAIGN_NONE && m_uCampaneID < CAMPAIGN_MAX)
    a2.SaveSignature(761539483);
    a2.SaveUnsigned32(10);
    a2.Save(&this->m_uMapFlags, 4);
    a2.Save(&this->m_iGameType, 4);
    a2.Save(&this->m_iVersionMajor, 4);
    a2.Save(&this->m_iVersionMinor, 4);
    a2.Save(&this->m_iVersionBuild, 4);
    a2.Save(&this->m_iWidthHeight, 4);
    a2.Save(this->m_spGameName, 64);
    a2.Save(this->m_swMapName, 512);
    a2.Save(this->m_spSaveDateTime, 26);
    a2.Save(&this->m_iMapMaxNumPlayers, 4);
    a2.Save(&this->m_uiPlayerCount, 4);
    for(int i = 0; i < 8; ++i)
        this->m_sPlayers[i].Save(a2);
    a2.Save(&this->m_uMultiPlayerGameID, 4);
    a2.Save(&this->m_iTeamWon, 4);
    a2.Save(&this->m_uiTickCounter, 4);
    a2.Save(&this->m_iNetworkTimeDelta, 4);
    a2.Save(&this->m_uCampaneID, 1);
    a2.Save(&this->m_iMissionId, 4);
    a2.SaveSignature(761539484);
    a2.SaveSignature(2103716763);
    a2.Save(this->m_spDesciptionText, 1024);
    a2.SaveSignature(-1922815076);
    a2.SaveSignature(224668571);
    a2.Save(&this->m_iMode, 1);
    a2.Save(&this->byte92C, 1);
    a2.Save(this->m_pEconomyGoodsArray, 7);
    a2.SaveSignature(493104027);
    a2.Save(&this->m_cLocalSlot, 1);
    a2.Save(&this->m_bIsHost, 1);
    a2.Save(&this->m_uSavegameId, 4);
    a2.SaveSignature(493104029);
    a2.Save(&this->m_bIsClanGame, 1);
    a2.SaveSignature(493104030);
    a2.SaveUnsigned32(this->m_iSeed);
    a2.SaveUnsigned32(this->m_iRandCalls);
    a2.SaveSignature(493104031);
    a2.SaveUnsigned32(this->m_uCamX);
    a2.SaveUnsigned32(this->m_uCamY);
    a2.SaveUnsigned32(this->m_uZoom);
    a2.SaveSignature(493104032);
}

// address=[0x13ec470]
// Decompiled from CGameChunkGeneral *__thiscall CGameChunkGeneral::GenerateCRC(CGameChunkGeneral *this)
void CGameChunkGeneral::GenerateCRC(void) {
    cdm_crc::CRCGenerator<16, 32773, 0, 0, 1, 1> v6{};
    v6.Process(reinterpret_cast<unsigned char *>(&this->m_uMapFlags), 4);
    v6.Process(reinterpret_cast<unsigned char *>(&this->m_iGameType), 4);
    v6.Process(reinterpret_cast<unsigned char *>(&this->m_iVersionMajor), 4);
    v6.Process(reinterpret_cast<unsigned char *>(&this->m_iVersionMinor), 4);
    v6.Process(reinterpret_cast<unsigned char *>(&this->m_iVersionBuild), 4);
    v6.Process(reinterpret_cast<unsigned char *>(&this->m_iWidthHeight), 4);
    v6.Process(reinterpret_cast<unsigned char *>(&this->m_uMultiPlayerGameID), 4);
    v6.Process(reinterpret_cast<unsigned char *>(&this->m_spGameName), 64);
    v6.Process(reinterpret_cast<unsigned char *>(&this->m_iMapMaxNumPlayers), 4);
    v6.Process(reinterpret_cast<unsigned char *>(&this->m_uiPlayerCount), 4);
    v6.Process(reinterpret_cast<unsigned char *>(&this->m_uiTickCounter), 4);
    v6.Process(reinterpret_cast<unsigned char *>(&this->m_iNetworkTimeDelta), 4);
    for(int i = 0; i < this->m_uiPlayerCount; ++i) {
        v6.Process(reinterpret_cast<unsigned char *>(&this->m_sPlayers[i]), 4);
        v6.Process(reinterpret_cast<unsigned char *>(&this->m_sPlayers[i].m_uColor), 4);
        v6.Process(reinterpret_cast<unsigned char *>(&this->m_sPlayers[i].m_uTeam), 1);
        v6.Process(reinterpret_cast<unsigned char *>(this->m_sPlayers[i].m_swName), 64);
    }
    v6.Process(reinterpret_cast<unsigned char *>(&this->m_iSeed), 4);
    v6.Process(reinterpret_cast<unsigned char *>(&this->m_iRandCalls), 4);
    this->m_uSavegameId = v6.GetNormalCRC() >> (32 - v6.GetWidth());
}
