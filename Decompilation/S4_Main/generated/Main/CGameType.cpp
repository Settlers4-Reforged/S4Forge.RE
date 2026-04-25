#include "CGameType.h"

// Definitions for class CGameType

// address=[0x1361450]
// Decompiled from char __thiscall CGameType::IsLadderGame(CGameType *this)
bool  CGameType::IsLadderGame(void)const {
  
  return this->m_bIsLadderGame;
}


// address=[0x13a4100]
// Decompiled from void __thiscall CGameType::ChangeLocalSlot(CGameType *this, signed __int8 a2)
void  CGameType::ChangeLocalSlot(signed char a2) {
  
  this->m_cLocalSlot = a2;
}


// address=[0x13a4140]
// Decompiled from char __thiscall CGameType::IsClanGame(CGameType *this)
bool const  CGameType::IsClanGame(void) {
  
  return this->m_bIsClanGame;
}


// address=[0x13a4160]
// Decompiled from char __thiscall CGameType::IsSaveGame(CGameType *this)
bool const  CGameType::IsSaveGame(void)const {
  
  return this->m_bIsSaveGame;
}


// address=[0x13a4180]
// Decompiled from bool __thiscall CGameType::IsSlotChangable(CGameType *this, int a2, bool *a3)
bool  CGameType::IsSlotChangable(int a2, bool * a3) {
  
  bool v4; // [esp+4h] [ebp-8h]

  if ( CGameType::IsSaveGame(this) )
    return 0;
  if ( !a3 )
    return this->m_sPlayerSlot16[a2] == 0;
  v4 = this->m_sPlayerSlot10[a2] || this->m_sPlayerType[a2] != 1;
  *a3 = v4;
  return this->m_sPlayerSlot16[a2] == 0;
}


// address=[0x13a8490]
// Decompiled from char __thiscall CGameType::IsAddOnMap(CGameType *this)
bool  CGameType::IsAddOnMap(void) {
  
  return this->m_bIsAddOnMap;
}


// address=[0x13a84b0]
// Decompiled from bool __thiscall CGameType::IsEmptyMap(CGameType *this)
bool  CGameType::IsEmptyMap(void) {
  
  return this->m_bIsEmptyMap == 1;
}


// address=[0x1486e10]
// Decompiled from int __thiscall CGameType::GetLocalSlot(CGameType *this)
int const  CGameType::GetLocalSlot(void) {
  
  return this->m_cLocalSlot;
}


// address=[0x1486e30]
// Decompiled from int __thiscall CGameType::GetMapBuildingXMLVersion(CGameType *this)
int  CGameType::GetMapBuildingXMLVersion(void)const {
  
  return this->m_iMapBuildingXMLVersion;
}


// address=[0x1486e50]
// Decompiled from int __thiscall CGameType::GetMapObjectXMLVersion(CGameType *this)
int  CGameType::GetMapObjectXMLVersion(void)const {
  
  return this->m_iMapObjectXMLVersion;
}


// address=[0x1486e70]
// Decompiled from int __thiscall CGameType::GetMultiPlayerGameID(CGameType *this)
unsigned int const  CGameType::GetMultiPlayerGameID(void) {
  
  return this->m_iMultiPlayerGameID;
}


// address=[0x1486ef0]
// Decompiled from std::wstring *__thiscall CGameType::GetRealPlayerName(CGameType *this, unsigned int _iPlayerIndex)
std::wstring &  CGameType::GetRealPlayerName(int _iPlayerIndex) {
  
  if ( _iPlayerIndex >= 0xA
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\main\\GameType.h",
         298,
         "(_iPlayerIndex>=0) && (_iPlayerIndex<=PLAYER_MAX)") == 1 )
  {
    __debugbreak();
  }
  return &this->m_swpRealPlayerNames[_iPlayerIndex];
}


// address=[0x1486fe0]
// Decompiled from char __thiscall CGameType::IsBlueByteAddOnMap(CGameType *this)
bool  CGameType::IsBlueByteAddOnMap(void) {
  
  return this->m_bBlueByteAddOnMap;
}


// address=[0x1487000]
// Decompiled from char __thiscall CGameType::IsBlueByteMCD2Map(CGameType *this)
bool  CGameType::IsBlueByteMCD2Map(void) {
  
  return this->m_bBlueByteMCD2Map;
}


// address=[0x1487020]
// Decompiled from char __thiscall CGameType::IsCampaignMap(CGameType *this)
bool  CGameType::IsCampaignMap(void) {
  
  return this->m_bIsCampaignMap;
}


// address=[0x1487040]
// Decompiled from char __thiscall CGameType::IsHost(CGameType *this)
bool const  CGameType::IsHost(void) {
  
  return this->m_bIsHost;
}


// address=[0x1487060]
// Decompiled from char __thiscall CGameType::IsMCD2TextureSet(CGameType *this)
bool  CGameType::IsMCD2TextureSet(void) {
  
  return this->m_bIsMCD2TextureSet;
}


// address=[0x1487080]
// Decompiled from bool __thiscall CGameType::IsMultiplayerGame(CGameType *this)
bool const  CGameType::IsMultiplayerGame(void) {
  
  return this->m_iGameType == 2;
}


// address=[0x14873d0]
// Decompiled from void __thiscall CGameType::SetBlueByteMCD2Map(CGameType *this, bool a2)
void  CGameType::SetBlueByteMCD2Map(bool a2) {
  
  this->m_bBlueByteMCD2Map = a2;
}


// address=[0x14873f0]
// Decompiled from void __thiscall CGameType::SetClanGame(CGameType *this, bool a2)
void  CGameType::SetClanGame(bool a2) {
  
  this->m_bIsClanGame = a2;
}


// address=[0x1487410]
// Decompiled from void __thiscall CGameType::SetHost(CGameType *this, bool a2)
void  CGameType::SetHost(bool a2) {
  
  this->m_bIsHost = a2;
}


// address=[0x1487430]
// Decompiled from void __thiscall CGameType::SetLocalSlot(CGameType *this, signed __int8 _iLocalSlotNr)
void  CGameType::SetLocalSlot(signed char _iLocalSlotNr) {
  
  if ( this->m_cLocalSlot != -1 )
    CTrace::Print("overwirte m_iLocalPlayerSlot");
  if ( (unsigned int)_iLocalSlotNr > 8
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\main\\GameType.h",
         470,
         "_iLocalSlotNr>=0 && _iLocalSlotNr<=MAX_PLAYER") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_cLocalSlot == -1 )
    this->m_cLocalSlot = _iLocalSlotNr;
}


// address=[0x14874d0]
// Decompiled from void __thiscall CGameType::SetMCD2TextureSet(CGameType *this, bool a2)
void  CGameType::SetMCD2TextureSet(bool a2) {
  
  this->m_bIsMCD2TextureSet = a2;
}


// address=[0x14874f0]
// Decompiled from void __thiscall CGameType::SetMPSavegameID(CGameType *this, int a2)
void  CGameType::SetMPSavegameID(int a2) {
  
  this->m_iMPSavegameID = a2;
}


// address=[0x1487510]
// Decompiled from void __thiscall CGameType::SetMultiPlayerGameID(CGameType *this, unsigned int a2)
void  CGameType::SetMultiPlayerGameID(unsigned int a2) {
  
  this->m_iMultiPlayerGameID = a2;
}


// address=[0x1487530]
// Decompiled from void __thiscall CGameType::SetPlayerName(CGameType *this, unsigned int _iPlayerIndex, std::wstring *_swpPlayerName)
void  CGameType::SetPlayerName(int _iPlayerIndex, std::wstring & _swpPlayerName) {
  
  if ( _iPlayerIndex >= 10
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\main\\GameType.h",
         305,
         "(_iPlayerIndex>=0) && (_iPlayerIndex<=PLAYER_MAX)") == 1 )
  {
    __debugbreak();
  }
  std::wstring::operator=(&this->m_swpRealPlayerNames[_iPlayerIndex], _swpPlayerName);
}


// address=[0x1490f90]
// Decompiled from CGameType *__thiscall CGameType::CGameType(CGameType *this)
 CGameType::CGameType(void) {
  
  std::wstring::wstring(&this->string0);
  std::wstring::wstring(&this->m_swMapName);
  this->m_iWidthHeight = 0;
  this->m_bIsEmptyMap = 0;
  this->m_iStartResources = 0;
  this->dword44 = 0;
  this->m_uiNumberAlliances = 0;
  this->m_iActualPlayerCount = 0;
  this->byte230 = 0;
  this->byte261 = 0;
  this->dword264 = 0;
  this->m_iMapCRC = 0;
  this->dword26C = 0;
  this->m_iNetworkTimeDelta = 0;
  std::string::string(&this->std__string298);
  this->m_bIsSaveGame = 0;
  this->byte2B9 = 0;
  this->m_uiTickCounter = 0;
  std::wstring::wstring(&this->m_swSaveFile);
  this->m_bAIActive = 0;
  this->dword2E0 = 0;
  this->dword2E8 = 0;
  this->m_bIsGameWon = 0;
  this->m_iTeamWon = 0;
  std::string::string(&this->m_swpTeamName);
  std::string::string(&this->std__string318);
  std::string::string(&this->std__string334);
  this->word350 = 0;
  this->m_iMapMaxNumPlayers = 0;
  this->m_iFileSize = 0;
  this->byte35C = 0;
  this->byte35D = 0;
  this->m_iMode = 0;
  this->m_bEconomyPossible = 0;
  this->m_bCompetetivePossible = 0;
  this->m_bFreeSettlePossible = 0;
  this->m_bConflictPossible = 0;
  this->m_bCooperationPossible = 0;
  this->byte369 = 0;
  this->byte36A = 0;
  this->byte36B = 0;
  this->byte36C = 0;
  this->m_iNumberOfSetups = 0;
  std::string::string(&this->std__string374);
  std::string::string(&this->std__string390);
  std::string::string(&this->std__string3AC);
  std::string::string(&this->std__string3C8);
  this->m_bIsEditorMap = 0;
  this->m_bIsCampaignMap = 0;
  this->dword3F8 = 0;
  this->dword3FC = 0;
  this->dword400 = 0;
  _vec_ctor(
    (char *)this->m_swpRealPlayerNames,
    28u,
    9u,
    (void (__thiscall *)(void *))std::wstring::wstring,
    (void (__thiscall *)(void *))std::wstring::~wstring);
  _vec_ctor(
    (char *)this->m_swPlayerClanShortcut,
    28u,
    9u,
    (void (__thiscall *)(void *))std::wstring::wstring,
    (void (__thiscall *)(void *))std::wstring::~wstring);
  this->m_iMultiPlayerGameID = 0;
  this->m_bIsMapLoaded = 0;
  this->m_cLocalSlot = 0;
  this->m_bIsHost = 0;
  this->m_bIsWebGame = 0;
  this->m_iMPSavegameID = 0;
  this->m_bIsClanGame = 0;
  this->m_bIsLadderGame = 0;
  this->m_bIsAddOnMap = 0;
  this->m_bBlueByteAddOnMap = 0;
  this->m_bBlueByteMCD2Map = 0;
  this->m_bIsMCD2TextureSet = 0;
  this->m_iMapObjectXMLVersion = 0;
  this->m_iMapBuildingXMLVersion = 0;
  this->dword618 = 0;
  this->dword61C = 0;
  CGameType::Init(this);
  return this;
}


// address=[0x1491360]
// Decompiled from void __thiscall CGameType::~CGameType(void **this)
 CGameType::~CGameType(void) {
  
  if ( this[254] )
  {
    operator delete[](this[254]);
    this[254] = 0;
  }
  `eh vector destructor iterator'(this + 320, 0x1Cu, 9u, std::wstring::~wstring);
  `eh vector destructor iterator'(this + 257, 0x1Cu, 9u, std::wstring::~wstring);
  std::string::~string(this + 242);
  std::string::~string(this + 235);
  std::string::~string(this + 228);
  std::string::~string(this + 221);
  std::string::~string(this + 205);
  std::string::~string(this + 198);
  std::string::~string(this + 189);
  std::wstring::~wstring(this + 176);
  std::string::~string(this + 166);
  std::wstring::~wstring(this + 7);
  std::wstring::~wstring(this);
}


// address=[0x1491490]
// Decompiled from char __thiscall CGameType::LoadMapData(  CGameType *this,  std::wstring a2,  bool _bAIActive,  int a4,  unsigned __int8 a5,  char a6,  int _iSetupIndex,  DWORD _iAIDifficulty,  int a9,  unsigned __int8 a10,  char a11)
bool  CGameType::LoadMapData(std::wstring a2, bool _bAIActive, unsigned int a4, bool a5, bool a6, int _iSetupIndex, int _iAIDifficulty, int a9, bool a10, bool a11) {
  
  wchar_t *v12; // eax
  int v13; // eax
  int v14; // eax
  wchar_t *v15; // eax
  _DWORD *p_dword264; // [esp-Ch] [ebp-8D24h]
  int v17; // [esp-4h] [ebp-8D1Ch]
  struct tagVARIANT v18; // [esp+8h] [ebp-8D10h] BYREF
  int v19; // [esp+18h] [ebp-8D00h]
  std::wstring *v20; // [esp+1Ch] [ebp-8CFCh]
  signed int v21; // [esp+20h] [ebp-8CF8h]
  signed int v22; // [esp+24h] [ebp-8CF4h]
  struct std::string *v23; // [esp+28h] [ebp-8CF0h]
  int iHasTeam; // [esp+2Ch] [ebp-8CECh] BYREF
  void *v25; // [esp+30h] [ebp-8CE8h]
  void *dword3F8; // [esp+34h] [ebp-8CE4h]
  void *C; // [esp+38h] [ebp-8CE0h]
  size_t v28; // [esp+3Ch] [ebp-8CDCh]
  std::wstring *AIName; // [esp+40h] [ebp-8CD8h]
  S4::CMapFile *pMapFile; // [esp+44h] [ebp-8CD4h]
  BOOL v31; // [esp+48h] [ebp-8CD0h]
  BSTR swpSetupName; // [esp+4Ch] [ebp-8CCCh] BYREF
  BOOL v33; // [esp+50h] [ebp-8CC8h]
  size_t v34; // [esp+54h] [ebp-8CC4h]
  unsigned int v35; // [esp+58h] [ebp-8CC0h]
  unsigned int v36; // [esp+5Ch] [ebp-8CBCh]
  int v37; // [esp+60h] [ebp-8CB8h]
  int StringId; // [esp+64h] [ebp-8CB4h]
  int v39; // [esp+68h] [ebp-8CB0h]
  BOOL v40; // [esp+6Ch] [ebp-8CACh]
  int v41; // [esp+70h] [ebp-8CA8h]
  int reportedError; // [esp+74h] [ebp-8CA4h] BYREF
  _BYTE *v43; // [esp+78h] [ebp-8CA0h]
  wchar_t *swpPlayerName; // [esp+7Ch] [ebp-8C9Ch] BYREF
  int v45; // [esp+80h] [ebp-8C98h]
  int v46; // [esp+84h] [ebp-8C94h] BYREF
  int v47; // [esp+88h] [ebp-8C90h] BYREF
  int v48; // [esp+8Ch] [ebp-8C8Ch] BYREF
  char *v49; // [esp+90h] [ebp-8C88h]
  signed int v50; // [esp+94h] [ebp-8C84h]
  char *Source; // [esp+98h] [ebp-8C80h]
  _BYTE *v52; // [esp+9Ch] [ebp-8C7Ch]
  _DWORD *Chunk; // [esp+A0h] [ebp-8C78h]
  int iPlayerControl; // [esp+A4h] [ebp-8C74h] BYREF
  signed int n; // [esp+A8h] [ebp-8C70h]
  int v56; // [esp+ACh] [ebp-8C6Ch]
  BSTR pbstr; // [esp+B0h] [ebp-8C68h] BYREF
  int k; // [esp+B4h] [ebp-8C64h]
  int iTeam; // [esp+B8h] [ebp-8C60h] BYREF
  BSTR bstrString; // [esp+BCh] [ebp-8C5Ch] BYREF
  char v61; // [esp+C3h] [ebp-8C55h]
  char *v62; // [esp+C4h] [ebp-8C54h]
  BSTR v63; // [esp+C8h] [ebp-8C50h]
  int v64; // [esp+CCh] [ebp-8C4Ch] BYREF
  char v65; // [esp+D0h] [ebp-8C48h]
  signed int j; // [esp+D4h] [ebp-8C44h]
  char v67; // [esp+DBh] [ebp-8C3Dh]
  bool v68; // [esp+DCh] [ebp-8C3Ch]
  bool v69; // [esp+DDh] [ebp-8C3Bh]
  bool v70; // [esp+DEh] [ebp-8C3Ah]
  bool v71; // [esp+DFh] [ebp-8C39h]
  int v72; // [esp+E0h] [ebp-8C38h] BYREF
  OLECHAR v73; // [esp+E4h] [ebp-8C34h]
  int i; // [esp+E8h] [ebp-8C30h]
  bool v75; // [esp+EFh] [ebp-8C29h]
  int m; // [esp+F0h] [ebp-8C28h]
  _BYTE v78[184]; // [esp+F8h] [ebp-8C20h] BYREF
  CFile v79; // [esp+1B0h] [ebp-8B68h] BYREF
  std::wstring v80; // [esp+1F8h] [ebp-8B20h] BYREF
  std::string v81; // [esp+214h] [ebp-8B04h] BYREF
  std::wstring v82; // [esp+230h] [ebp-8AE8h] BYREF
  std::wstring v83; // [esp+24Ch] [ebp-8ACCh] BYREF
  char Buffer[2048]; // [esp+268h] [ebp-8AB0h] BYREF
  char Destination[16384]; // [esp+A68h] [ebp-82B0h] BYREF
  char Dest[16384]; // [esp+4A68h] [ebp-42B0h] BYREF
  char v87[256]; // [esp+8A68h] [ebp-2B0h] BYREF
  char v88[144]; // [esp+8B68h] [ebp-1B0h] BYREF
  char v89[144]; // [esp+8BF8h] [ebp-120h] BYREF
  char Str[128]; // [esp+8C88h] [ebp-90h] BYREF
  int v91; // [esp+8D14h] [ebp-4h]

  v91 = 0;
  CGameType::Init(this);
  v48 = 0;
  v47 = 0;
  v46 = 0;
  v72 = 0;
  this->m_bAIActive = _bAIActive;
  this->dword44 = a4;
  if ( _iAIDifficulty != -1 )
  {
    if ( _iAIDifficulty )
      _iAIDifficulty = 3;
    else
      _iAIDifficulty = 2;
  }
  std::wstring::wstring(&v83);
  LOBYTE(v91) = 1;
  this->dword264 = 0;
  this->m_iMapCRC = 0;
  if ( (*(unsigned __int8 (__thiscall **)(void *, std::wstring *, std::wstring *))(*(_DWORD *)g_pRandomMaps + 32))(
         g_pRandomMaps,
         &a2,
         &v83) )
  {
    std::string::operator=(&stru_402C998, (char *)&byte_36FE4FB);
    std::string::operator=(&stru_402C9D0, (char *)&byte_36FE50F);
    std::string::operator=(&stru_402C97C, (char *)&byte_36FE5B2);
    std::string::operator=(&stru_402C9B4, (char *)&byte_36FE5B3);
    std::wstring::operator=(&this->m_swMapName, &a2);
    if ( !(*(unsigned __int8 (__thiscall **)(void *, _BYTE *, std::wstring *))(*(_DWORD *)g_pRandomMaps + 16))(
            g_pRandomMaps,
            v78,
            &v83) )
    {
      BBSupportTracePrintF(0, "[MM] LoadMapData: couldn't GetParamsFromMapKey");
      LOBYTE(v91) = 0;
      std::wstring::~wstring(&v83);
      v91 = -1;
      std::wstring::~wstring(&a2);
      return 0;
    }
    (**(void (__thiscall ***)(void *, _BYTE *))g_pRandomMaps)(g_pRandomMaps, v78);
    if ( !(*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)g_pRandomMaps + 8))(g_pRandomMaps) )
    {
      BBSupportTracePrintF(0, "[MM] LoadMapData: couldn't GenereateRandomMap");
      LOBYTE(v91) = 0;
      std::wstring::~wstring(&v83);
      v91 = -1;
      std::wstring::~wstring(&a2);
      return 0;
    }
    pMapFile = (S4::CMapFile *)(*(int (__thiscall **)(void *))(*(_DWORD *)g_pRandomMaps + 12))(g_pRandomMaps);
    if ( !pMapFile )
    {
      BBSupportTracePrintF(0, "[MM] LoadMapData: pMapFile == 0");
      LOBYTE(v91) = 0;
      std::wstring::~wstring(&v83);
      v91 = -1;
      std::wstring::~wstring(&a2);
      return 0;
    }
    Chunk = S4::CMapFile::LoadChunk(pMapFile, 0xDCu, 0);
    this->m_bIsCampaignMap = 0;
    this->m_bIsEditorMap = 0;
    this->m_iWidthHeight = Chunk[3];
    this->m_iStartResources = 1;
    this->m_bIsEmptyMap = 1;
    this->m_iMode = 1;
    this->m_bCooperationPossible = 1;
    this->m_bConflictPossible = 1;
    std::string::operator=(&this->std__string3C8, (char *)&byte_36FE5D1);
    std::string::operator=(&this->std__string374, (char *)&byte_36FE5D2);
    std::string::operator=(&this->std__string390, (char *)&byte_36FE5D3);
    std::string::operator=(&this->std__string3AC, (char *)&byte_36FE5FA);
    this->m_iNumberOfSetups = 1;
    this->m_iMapMaxNumPlayers = Chunk[4];
    this->byte36A = 1;
    this->byte36B = 1;
    this->byte36C = 1;
    this->byte369 = 1;
    for ( i = 0; i < this->m_iMapMaxNumPlayers; ++i )
    {
      this->m_sPlayerSlot16[i] = 0;
      this->m_sPlayerRaces[i] = 5;
      this->m_sPlayerStartX[i] = Chunk[i + 6];
      this->m_sPlayerStartY[i] = Chunk[i + 15];
      this->m_sPlayerTeam[i] = i;
      this->gap3E6[i] = 1;
      this->gap3E6[i + 9] = 1;
      if ( i && _bAIActive )
      {
        if ( _iAIDifficulty == -1 )
          this->m_sPlayerType[i] = 2;
        else
          this->m_sPlayerType[i] = _iAIDifficulty;
      }
      else
      {
        this->m_sPlayerType[i] = 1;
      }
      if ( this->m_sPlayerType[i] != 1 )
      {
        AIName = (std::wstring *)CGameSettings::GetAIName((int)&v80, i);
        std::wstring::operator=(&this->m_swpRealPlayerNames[i], AIName);
        std::wstring::~wstring(&v80);
      }
    }
    this->m_uiNumberAlliances = this->m_iMapMaxNumPlayers;
    this->byte35D = 1;
    this->byte35C = 1;
    this->m_iFileSize = 0;
  }
  else
  {
    std::wstring::operator=(&this->m_swMapName, &a2);
    v17 = a5;
    p_dword264 = &this->dword264;
    v12 = std::wstring::c_str(&this->m_swMapName);
    MA_OpenMapFile(v12, (int)p_dword264, (int)&reportedError, v17);
    if ( reportedError )
    {
      CTrace::Print("CGameType.cpp: Unable to open Map via Mapreader. Reported error %d", reportedError);
      v61 = 0;
      LOBYTE(v91) = 0;
      std::wstring::~wstring(&v83);
      v91 = -1;
      std::wstring::~wstring(&a2);
      return v61;
    }
    MA_GetDataChecksums(&v48, &v47);
    if ( a6 )
    {
      this->m_iMapBuildingXMLVersion = v48;
      this->m_iMapObjectXMLVersion = v47;
    }
    else
    {
      this->m_iMapBuildingXMLVersion = 0;
      this->m_iMapObjectXMLVersion = 0;
    }
    MA_IsCampaignMap(&v64);
    v71 = v64 != 0;
    this->m_bIsCampaignMap = v64 != 0;
    MA_IsEditorMap(&v64);
    v70 = v64 != 0;
    this->m_bIsEditorMap = v64 != 0;
    MA_GetMapProperty(1, &v64);
    v69 = v64 != 0;
    this->m_bIsAddOnMap = v64 != 0;
    MA_GetMapProperty(2, &v64);
    v68 = v64 != 0;
    this->m_bBlueByteAddOnMap = v64 != 0;
    MA_GetMapData(
      (int)&this->m_iWidthHeight,
      (int)&v46,
      (int)&v72,
      (int)&this->m_iStartResources,
      (int)&this->m_bIsEmptyMap);
    if ( (v46 & 2) != 0 )
      v41 = 2;
    else
      v41 = 1;
    this->m_iMode = v41;
    if ( this->m_iMode == 2 )
      this->m_bCooperationPossible = 1;
    else
      this->m_bConflictPossible = 1;
    std::string::operator=(&this->std__string3C8, (char *)&byte_36FE5FB);
    std::string::operator=(&this->std__string374, (char *)&byte_36FE61F);
    std::string::operator=(&this->std__string390, (char *)&byte_36FE682);
    std::string::operator=(&this->std__string3AC, (char *)&byte_36FE683);
    memset(Destination, 0, sizeof(Destination));
    memset(Dest, 0, sizeof(Dest));
    v75 = 0;
    pbstr = 0;
    MA_GetDescriptionText(0, &pbstr);
    if ( pbstr )
    {
      memset(Str, 0, sizeof(Str));
      v63 = pbstr;
      for ( j = SysStringLen(pbstr); j > 0 && *v63 <= 0x20u; --j )
        ++v63;
      while ( j > 0 && v63[j - 1] <= 0x20u )
        --j;
      v40 = j >= 2 && (unsigned int)j < 0x80 && *v63 == 36 && v63[j - 1] == 36;
      v75 = v40;
      if ( v40 )
      {
        for ( k = 1; k < j - 1; ++k )
        {
          v73 = v63[k];
          if ( (v73 < 0x41u || v73 > 0x5Au) && (v73 < 0x30u || v73 > 0x39u) && v73 != 95 )
          {
            v75 = 0;
            break;
          }
          v89[k + 143] = v73;
        }
      }
      if ( v75 )
      {
        v50 = strlen(Str);
        if ( v50 > 5 && !j__strcmp(&v89[v50 + 139], "_DESC") && CS4DefineNames::GetStringId(Str) >= 0 )
        {
          v39 = v50 - 5;
          if ( (unsigned int)(v50 - 5) >= 0x80 )
            report_rangecheckfailure();
          Str[v39] = 0;
        }
        snprintf(v88, 0x90u, "%s_DESC", Str);
        snprintf(v89, 0x90u, "%s_TIPS", Str);
        StringId = CS4DefineNames::GetStringId(v88);
        v37 = CS4DefineNames::GetStringId(v89);
        if ( StringId >= 0 )
        {
          Source = g_pStringEngine->GetString(g_pStringEngine, StringId);
          if ( Source )
          {
            if ( *Source )
              j__strncpy(Destination, Source, 0x3FFFu);
          }
        }
        if ( v37 >= 0 )
        {
          v49 = g_pStringEngine->GetString(g_pStringEngine, v37);
          if ( v49 )
          {
            if ( *v49 )
              j__strncpy(Dest, v49, 0x3FFFu);
          }
        }
      }
      SysFreeString(pbstr);
    }
    if ( !v75 )
    {
      if ( CGameSettings::GetLanguage() == 1 )
        v36 = 0;
      else
        v36 = 2;
      v35 = v36;
      bstrString = 0;
      MA_GetDescriptionText(v36, &bstrString);
      v21 = j__wcstombs(Destination, bstrString, 0x3FFEu);
      if ( v21 <= 0 )
        memset(Destination, 0, sizeof(Destination));
      SysFreeString(bstrString);
      MA_GetDescriptionText(v35 + 1, &bstrString);
      v22 = j__wcstombs(Dest, bstrString, 0x3FFEu);
      if ( v22 <= 0 )
        memset(Dest, 0, sizeof(Dest));
      SysFreeString(bstrString);
    }
    if ( Destination[0] )
    {
      v62 = Destination;
      v52 = (_BYTE *)_mbsstr((int)Destination, "@");
      if ( v52 )
      {
        *v52 = 0;
        std::string::operator=(&this->std__string3AC, v62);
        v62 = v52 + 1;
        v43 = (_BYTE *)_mbsstr((int)(v52 + 1), "@");
        if ( v43 )
        {
          *v43 = 0;
          std::string::operator=(&this->std__string3C8, v62);
          v62 = v43 + 1;
        }
      }
      std::string::operator=(&this->std__string374, v62);
    }
    if ( Dest[0] )
      std::string::operator=(&this->std__string390, Dest);
    MA_GetNumberOfSetups(&this->m_iNumberOfSetups);
    MA_GetNumberOfPlayers((int)&this->m_iMapMaxNumPlayers);
    v45 = 0;
    this->byte36A = (v72 & 1) != 0 && CGameType::IsEmptyMap(this);
    this->byte36B = (v72 & 2) != 0;
    this->byte36C = (v72 & 4) == 0 && CGameType::IsEmptyMap(this);
    this->byte369 = (v72 & 8) == 0;
    this->m_bBlueByteAddOnMap = (v72 & 0x40) != 0;
    this->m_bBlueByteMCD2Map = (v72 & 0x100) != 0;
    this->m_bIsMCD2TextureSet = (v72 & 0x200) != 0;
    v67 = 0;
    v56 = 0;
    for ( m = 0; m < this->m_iMapMaxNumPlayers; ++m )
    {
      MA_GetPlayerData(
        m + 1,
        _iSetupIndex,
        &this->m_sPlayerRaces[m],
        &this->m_sPlayerStartX[m],
        &this->m_sPlayerStartY[m],
        &swpPlayerName,
        &swpSetupName,
        &iPlayerControl,
        &iHasTeam,
        &iTeam);
      if ( iTeam >= 0 )
      {
        if ( iTeam > 8 )
          iTeam = 0;
      }
      else
      {
        iTeam = 0;
      }
      this->m_sPlayerTeam[m] = iTeam;
      v28 = j__wcstombs(v87, swpSetupName, 0x100u);
      v34 = v28;
      if ( v28 >= 0x100 )
        report_rangecheckfailure();
      v87[v34] = 0;
      v23 = std::string::string(&v81, v87);
      std::string::operator=(&this->m_swpTeamName, v23);
      std::string::~string(&v81);
      if ( j__wcscmp(swpPlayerName, &String2) ) // Empty?
        std::wstring::operator=(&this->m_swpRealPlayerNames[m], swpPlayerName);
      v33 = iPlayerControl == 2;
      this->m_sPlayerSlot16[m] = v33;
      if ( iPlayerControl )
      {
        if ( iPlayerControl != 2 )
        {
          if ( m )
            v67 = 1;
          ++v56;
        }
        this->gap3E6[m] = 0;
        if ( iPlayerControl == 2 )
        {
          if ( _iAIDifficulty == -1 )
            this->m_sPlayerType[m] = 2;
          else
            this->m_sPlayerType[m] = _iAIDifficulty;
        }
        else
        {
          this->m_sPlayerType[m] = 1;
        }
      }
      else
      {
        ++v56;
        this->gap3E6[m] = 1;
        this->m_sPlayerType[m] = 1;
        if ( _bAIActive )
        {
          if ( _iAIDifficulty == -1 )
            this->m_sPlayerType[m] = 2;
          else
            this->m_sPlayerType[m] = _iAIDifficulty;
        }
      }
      if ( (this->m_sPlayerType[m] == 2 || this->m_sPlayerType[m] == 3)
        && (unsigned __int8)std::operator==<wchar_t>((int)this->m_swpRealPlayerNames[m].m_u, (wchar_t *)&word_36FEE98) )
      {
        v20 = (std::wstring *)CGameSettings::GetAIName((int)&v82, m);
        std::wstring::operator=(&this->m_swpRealPlayerNames[m], v20);
        std::wstring::~wstring(&v82);
      }
      if ( this->m_sPlayerTeam[m] > v45 )
        v45 = this->m_sPlayerTeam[m];
      if ( this->m_sPlayerRaces[m] == 255 )
      {
        this->gap3E6[m + 9] = 1;
        this->m_sPlayerRaces[m] = 5;
      }
      else
      {
        this->gap3E6[m + 9] = 0;
      }
      if ( this->m_bIsCampaignMap )
        this->m_sPlayerSlot10[m] = 0;
      SysFreeString(swpSetupName);
      SysFreeString(swpPlayerName);
    }
    if ( this->m_iMapMaxNumPlayers == 1 || this->byte36B && this->byte36C || !v67 )
      this->byte35D = 1;
    if ( v56 >= 2 )
      this->byte35C = 1;
    this->m_uiNumberAlliances = v45 + 1;
    for ( m = 0; m < this->m_iMapMaxNumPlayers; ++m )
    {
      if ( this->m_sPlayerTeam[m] < 9 )
        ++this->ptr4c[this->m_sPlayerTeam[m]];
    }
    if ( this->m_uiNumberAlliances == 1 )
    {
      this->m_bConflictPossible = 0;
    }
    else
    {
      this->m_bEconomyPossible = (v72 & 0x10) != 0;
      this->m_bCompetetivePossible = (v72 & 0x20) != 0;
    }
    if ( !_iSetupIndex && this->dword3F8 )
    {
      C = (void *)this->dword3F8;
      operator delete[](C);
      this->dword3F8 = 0;
    }
    if ( this->byte369 && a5 )
    {
      if ( !_iSetupIndex && this->dword3F8 )
      {
        dword3F8 = (void *)this->dword3F8;
        operator delete[](dword3F8);
        this->dword3F8 = 0;
      }
      MA_GetPreviewMapRawData(&this->dword3FC, &this->dword400, &v18);
      if ( v18.lVal )
      {
        v25 = operator new[](2 * this->dword400 * this->dword3FC);
        this->dword3F8 = v25;
        memcpy((void *)this->dword3F8, v18.bstrVal, 2 * this->dword400 * this->dword3FC);
      }
    }
    MA_CloseMapFile();
    CFile::CFile(&v79);
    LOBYTE(v91) = 2;
    CFile::Open(&v79, &this->m_swMapName, CFile_BINARY|CFile_READ, UNUSED_ARG(), UNUSED_ARG());
    v13 = CFile::Size(&v79);
    this->m_iFileSize = v13;
    CFile::Close(&v79, UNUSED_ARG(), UNUSED_ARG());
    LOBYTE(v91) = 1;
    CFile::~CFile(&v79);
  }
  for ( n = 0; n < this->m_iMapMaxNumPlayers; ++n )
    this->m_sPlayerColor[n] = n;
  if ( this->m_uiNumberAlliances == 1 || this->byte36C && this->byte36B && !this->m_bIsCampaignMap && this->m_bAIActive )
    this->m_bFreeSettlePossible = 1;
  if ( !this->m_bConflictPossible && this->m_bFreeSettlePossible && !this->m_bCooperationPossible )
  {
    if ( a9 == 8 || (v72 & 0x80) != 0 )
    {
      this->m_iMode = 1;
      this->m_bConflictPossible = 1;
      this->m_bFreeSettlePossible = 0;
    }
    else
    {
      this->m_iMode = 5;
      this->m_bFreeSettlePossible = 1;
    }
  }
  this->m_bCompetetivePossible = 0;
  if ( !this->m_bFreeSettlePossible
    && !this->m_bConflictPossible
    && !this->m_bCompetetivePossible
    && !this->m_bEconomyPossible
    && !this->m_bCooperationPossible
    && BBSupportDbgReport(
         2,
         "main\\GameType.cpp",
         1032,
         "m_bFreeSettlePossible || m_bConflictPossible || m_bCompetetivePossible || m_bEconomyPossible || m_bCooperationPossible") == 1 )
  {
    __debugbreak();
  }
  this->m_bIsMapLoaded = 1;
  v14 = (**(int (__thiscall ***)(void *, _DWORD, _DWORD, _DWORD, int, int))g_pMapCheck)(
          g_pMapCheck,
          this->dword264,
          this->m_iMapMaxNumPlayers,
          this->m_iWidthHeight,
          v46,
          v72);
  this->m_iMapCRC = v14;
  v19 = 1024;
  v15 = std::wstring::c_str(&a2);
  snwprintf(Buffer, 0x400u, L"\"%s\",", v15);
  BBSupportTracePrintF(
    1,
    "Map info: %-53s  0x%08x, %8i, %4i / %4i",
    Buffer,
    this->m_iMapCRC,
    this->m_iFileSize,
    v48,
    v47);
  CGameType::PatchMaps(this, _bAIActive);
  v31 = a11 == 0;
  if ( (v31 & a10) != 0 )
  {
    this->byte36C = 0;
    this->byte36B = 0;
    this->m_iMapMaxNumPlayers = 2;
    this->m_uiNumberAlliances = 2;
    this->m_sPlayerTeam[0] = 0;
    this->m_sPlayerTeam[1] = 1;
  }
  v65 = 1;
  LOBYTE(v91) = 0;
  std::wstring::~wstring(&v83);
  v91 = -1;
  std::wstring::~wstring(&a2);
  return v65;
}


// address=[0x1492f70]
// Decompiled from bool __thiscall CGameType::IsMapAvailable(CGameType *this, std::wstring *a2, int a3)
bool  CGameType::IsMapAvailable(std::wstring & a2, int a3) {
  
  wchar_t *v4; // eax
  int v5; // [esp+0h] [ebp-2Ch]
  int v6; // [esp+4h] [ebp-28h] BYREF
  int v7; // [esp+8h] [ebp-24h] BYREF
  int v8; // [esp+Ch] [ebp-20h] BYREF
  int v9; // [esp+14h] [ebp-18h] BYREF
  int v10; // [esp+18h] [ebp-14h] BYREF
  int v11; // [esp+1Ch] [ebp-10h] BYREF
  int v12; // [esp+20h] [ebp-Ch] BYREF
  int iError; // [esp+24h] [ebp-8h] BYREF

  if ( (*(unsigned __int8 (__thiscall **)(void *, std::wstring *, _DWORD))(*(_DWORD *)g_pRandomMaps + 32))(
         g_pRandomMaps,
         a2,
         0) )
  {
    return 1;
  }
  std::wstring::operator=(&this->m_swMapName, a2);
  v4 = std::wstring::c_str(&this->m_swMapName);
  MA_OpenMapFile(v4, (int)&v6, (int)&iError, 1);
  if ( iError )
  {
    CTrace::Print("CGameType.cpp: Unable to open Map via Mapreader. Reported error %d", iError);
    return 0;
  }
  else
  {
    v9 = 0;
    v10 = 0;
    v11 = 0;
    v12 = 0;
    v7 = 0;
    v8 = 0;
    MA_GetNumberOfPlayers((int)&v9);
    MA_GetMapData((int)&v10, (int)&v11, (int)&v12, (int)&v7, (int)&v8);
    v5 = (**(int (__thiscall ***)(void *, int, int, int, int, int))g_pMapCheck)(g_pMapCheck, v6, v9, v10, v11, v12);
    MA_CloseMapFile();
    return a3 == v5;
  }
}


// address=[0x1493090]
// Decompiled from void __thiscall CGameType::SetMapCRC(CGameType *this, std::wstring *a2)
void  CGameType::SetMapCRC(std::wstring & a2) {
  
  wchar_t *v2; // eax
  int v3; // eax
  _DWORD *p_dword264; // [esp-Ch] [ebp-2Ch]
  int v5; // [esp+0h] [ebp-20h] BYREF
  int v6; // [esp+4h] [ebp-1Ch] BYREF
  int v7; // [esp+8h] [ebp-18h] BYREF
  int v8; // [esp+Ch] [ebp-14h] BYREF
  int v9; // [esp+10h] [ebp-10h] BYREF
  int v10; // [esp+14h] [ebp-Ch] BYREF
  int v11; // [esp+18h] [ebp-8h] BYREF

  this->dword264 = 0;
  this->m_iMapCRC = 0;
  std::wstring::operator=(&this->m_swMapName, a2);
  p_dword264 = &this->dword264;
  v2 = std::wstring::c_str(&this->m_swMapName);
  MA_OpenMapFile(v2, (int)p_dword264, (int)&v7, 1);
  if ( v7 )
  {
    this->dword264 = 0;
  }
  else
  {
    v8 = 0;
    v9 = 0;
    v10 = 0;
    v11 = 0;
    v5 = 0;
    v6 = 0;
    MA_GetNumberOfPlayers((int)&v8);
    MA_GetMapData((int)&v9, (int)&v10, (int)&v11, (int)&v5, (int)&v6);
    v3 = (**(int (__thiscall ***)(void *, _DWORD, int, int, int, int))g_pMapCheck)(
           g_pMapCheck,
           this->dword264,
           v8,
           v9,
           v10,
           v11);
    this->m_iMapCRC = v3;
    MA_CloseMapFile();
  }
}


// address=[0x1493190]
// Decompiled from int __thiscall CGameType::HumanPlayers(CGameType *this)
int  CGameType::HumanPlayers(void) {
  
  int v2; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  for ( i = 0; i < this->m_iMapMaxNumPlayers; ++i )
  {
    if ( *(_DWORD *)&this->m_sPlayerType[4 * i] == 1 )
      ++v2;
  }
  return v2;
}


// address=[0x14931e0]
// Decompiled from void __thiscall CGameType::Init(CGameType *this)
void  CGameType::Init(void) {
  
  int i; // [esp+0h] [ebp-8h]
  int j; // [esp+0h] [ebp-8h]

  this->m_bIsMapLoaded = 0;
  std::wstring::operator=(this, (wchar_t *)&emptyString);
  std::wstring::operator=(&this->m_swMapName, (wchar_t *)&emptyString2);
  this->m_iWidthHeight = 0;
  this->m_bAIActive = 1;
  this->dword44 = 0;
  this->m_uiNumberAlliances = 0;
  this->m_iActualPlayerCount = 0;
  this->byte230 = 0;
  this->dword3F8 = 0;
  this->dword3FC = 0;
  this->dword400 = 0;
  this->m_iMapMaxNumPlayers = 0;
  this->m_iMode = 0;
  this->m_bEconomyPossible = 0;
  this->m_bCompetetivePossible = 0;
  this->byte369 = 0;
  this->byte36A = 0;
  this->byte36B = 0;
  this->byte36C = 0;
  this->m_bIsEditorMap = 0;
  this->m_bIsCampaignMap = 0;
  this->m_iNumberOfSetups = 0;
  this->byte35C = 0;
  this->byte35D = 0;
  this->m_iCampaignType = 0;
  this->byte261 = 1;
  this->dword26C = 0;
  this->m_iNetworkTimeDelta = 0;
  this->m_iMultiPlayerGameID = -1;
  std::string::operator=(&this->std__string298, (char *)&byte_36FE4FA);
  this->m_iGameType = 1;
  this->m_bIsSaveGame = 0;
  std::wstring::operator=(&this->m_swSaveFile, (wchar_t *)&word_36FE960);
  this->dword2E0 = 0;
  this->m_bIsGameWon = 0;
  this->m_iTeamWon = -1;
  this->m_bFreeSettlePossible = 0;
  this->m_bConflictPossible = 0;
  this->m_bCooperationPossible = 0;
  this->m_iWidthHeight = 0;
  for ( i = 0; i < 9; ++i )
    this->ptr4c[i] = 0;
  for ( j = 0; j < 9; ++j )
  {
    this->m_sPlayerType[j] = 0;
    std::wstring::operator=(&this->m_swpRealPlayerNames[j], (wchar_t *)&emptyString3);
    this->m_sPlayerTeam[j] = 0;
    this->m_sPlayerIP[j] = 0;
    this->m_sPlayerPeerId[j] = -1;
    this->m_sPlayerStartX[j] = 0;
    this->m_sPlayerStartY[j] = 0;
    this->m_sPlayerRaces[j] = 5;
    this->m_sPlayerColor[j] = 0;
    this->m_sPlayerSlot8[j] = j;
    this->m_sPlayerSlot14[j] = 0;
    this->m_sPlayerSlot10[j] = 1;
    this->m_sPlayerSlot11[j] = 0;
    this->m_sPlayerSlot12[j] = 0;
    this->m_sPlayerSlot13[j] = -1;
    std::wstring::operator=(&this->m_swPlayerClanShortcut[j], (wchar_t *)&emptyString4);
    this->m_sPlayerSlot15[j] = -1;
  }
  this->m_iNetworkTimeDelta = CStaticConfigVarInt::operator int(&g_iNetworkTimeDelta);
  this->m_uiTickCounter = 0;
  this->word350 = 0;
  memset(this->m_pEconomyGoodsArray, 0, 7u);
  this->m_cLocalSlot = -1;
  this->m_bIsHost = 0;
  this->m_bIsWebGame = 0;
  this->m_iMPSavegameID = 0;
  this->m_bIsClanGame = 0;
  this->m_bIsLadderGame = 0;
  this->m_bIsAddOnMap = 0;
  this->m_bBlueByteAddOnMap = 0;
  this->m_bBlueByteMCD2Map = 0;
  this->m_bIsMCD2TextureSet = 0;
  this->m_iMapObjectXMLVersion = 0;
  this->m_iMapBuildingXMLVersion = 0;
  this->dword618 = 0;
  this->dword61C = 0;
}


// address=[0x1493620]
// Decompiled from std::wstring *__thiscall CGameType::ConvertMapNameToMPGameName(CGameType *this, std::wstring *a2)
std::wstring  CGameType::ConvertMapNameToMPGameName(void a2) {
  
  CGameType::ConvertMapNameToMPGameName(a2, &this->m_swMapName);
  return a2;
}


// address=[0x1493660]
// Decompiled from void *__cdecl CGameType::ConvertMapNameToMPGameName(std::wstring *a1, std::wstring *a2)
std::wstring __cdecl CGameType::ConvertMapNameToMPGameName(std::wstring & a1) {
  
  wchar_t *v2; // eax
  wchar_t Dir[256]; // [esp+4h] [ebp-814h] BYREF
  wchar_t Ext[256]; // [esp+204h] [ebp-614h] BYREF
  wchar_t Destination[260]; // [esp+404h] [ebp-414h] BYREF
  wchar_t Filename[256]; // [esp+60Ch] [ebp-20Ch] BYREF
  wchar_t Drive[4]; // [esp+80Ch] [ebp-Ch] BYREF

  v2 = std::wstring::c_str(a2);
  wcscpy(Destination, v2);
  j___wsplitpath(Destination, Drive, Dir, Filename, Ext);
  std::wstring::wstring(a1, Filename);
  return a1;
}


// address=[0x14936f0]
// Decompiled from std::wstring *__thiscall CGameType::GetPlayerName(CGameType *this, std::wstring *a2, unsigned int _iPlayerIndex)
std::wstring  CGameType::GetPlayerName(int a2) {
  
  std::wstring v5; // [esp+Ch] [ebp-2Ch] BYREF
  int v6; // [esp+34h] [ebp-4h]

  if ( _iPlayerIndex >= 10
    && BBSupportDbgReport(2, "main\\GameType.cpp", 1114, "(_iPlayerIndex>=0) && (_iPlayerIndex<=PLAYER_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( CGameType::IsClanGame(this) )
  {
    std::wstring::wstring(&v5, &this->m_swPlayerClanShortcut[_iPlayerIndex]);
    v6 = 0;
    std::wstring::operator+=(&v5, (wchar_t *)singleSpaceString);
    std::wstring::operator+=(&v5, &this->m_swpRealPlayerNames[_iPlayerIndex]);
    std::wstring::wstring(a2, &v5);
    v6 = -1;
    std::wstring::~wstring(&v5);
  }
  else
  {
    std::wstring::wstring(a2, &this->m_swpRealPlayerNames[_iPlayerIndex]);
  }
  return a2;
}


// address=[0x1493810]
// Decompiled from void __thiscall CGameType::SetPlayerClanShortcut(  CGameType *this,  unsigned int _iPlayerIndex,  std::wstring *_swpPlayerClanShortcut)
void  CGameType::SetPlayerClanShortcut(int _iPlayerIndex, std::wstring & _swpPlayerClanShortcut) {
  
  if ( _iPlayerIndex >= 0xA
    && BBSupportDbgReport(2, "main\\GameType.cpp", 1106, "(_iPlayerIndex>=0) && (_iPlayerIndex<=PLAYER_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( CGameType::IsClanGame(this) )
    std::wstring::operator=(&this->m_swPlayerClanShortcut[_iPlayerIndex], _swpPlayerClanShortcut);
}


// address=[0x1493870]
// Decompiled from int __thiscall CGameType::GetNumberHumanPlayers(CGameType *this)
int const  CGameType::GetNumberHumanPlayers(void) {
  
  int v2; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  for ( i = 0; i < this->m_iMapMaxNumPlayers; ++i )
  {
    if ( *(_DWORD *)&this->m_sPlayerType[4 * i] == 1 )
      ++v2;
  }
  return v2;
}


// address=[0x14bce00]
// Decompiled from char __thiscall CGameType::IsMapLoaded(CGameType *this)
bool const  CGameType::IsMapLoaded(void) {
  
  return this->m_bIsMapLoaded;
}


// address=[0x14bce20]
// Decompiled from char __thiscall CGameType::IsWebGame(CGameType *this)
bool const  CGameType::IsWebGame(void) {
  
  return this->m_bIsWebGame;
}


// address=[0x15c4a50]
// Decompiled from int __thiscall CGameType::GetMPSavegameID(CGameType *this)
int const  CGameType::GetMPSavegameID(void) {
  
  return this->m_iMPSavegameID;
}


// address=[0x15c4ae0]
// Decompiled from std::wstring *__thiscall CGameType::GetPlayerClanShortcut(CGameType *this, std::wstring *a2, unsigned int a3)
std::wstring  CGameType::GetPlayerClanShortcut(int a2) {
  
  std::wstring v5; // [esp+Ch] [ebp-2Ch] BYREF
  int v6; // [esp+34h] [ebp-4h]

  std::wstring::wstring(&v5);
  v6 = 0;
  if ( a3 >= 0xA
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\net\\..\\main\\GameType.h",
         316,
         "(_iPlayerIndex>=0) && (_iPlayerIndex<=PLAYER_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( CGameType::IsClanGame(this) )
    std::wstring::wstring(a2, &this->m_swPlayerClanShortcut[a3]);
  else
    std::wstring::wstring(a2, &v5);
  v6 = -1;
  std::wstring::~wstring(&v5);
  return a2;
}


// address=[0x15c4dd0]
// Decompiled from void __thiscall CGameType::SetLadderGame(CGameType *this, bool a2)
void  CGameType::SetLadderGame(bool a2) {
  
  this->m_bIsLadderGame = a2;
}


// address=[0x15c4e90]
// Decompiled from void __thiscall CGameType::SetWebGame(CGameType *this, bool a2)
void  CGameType::SetWebGame(bool a2) {
  
  this->m_bIsWebGame = a2;
}


// address=[0x14938c0]
// Decompiled from int __thiscall CGameType::PatchMaps(CGameType *this, bool a2)
void  CGameType::PatchMaps(bool a2) {
  
  wchar_t *v2; // eax
  int result; // eax
  int m_iMapCRC; // [esp-8h] [ebp-10h]
  int dword358; // [esp-4h] [ebp-Ch]

  if ( !g_pMapCheck && BBSupportDbgReport(2, "main\\GameType.cpp", 1141, "g_pMapCheck != 0") == 1 )
    __debugbreak();
  dword358 = this->m_iFileSize;
  m_iMapCRC = this->m_iMapCRC;
  v2 = std::wstring::c_str(&this->m_swMapName);
  result = (*(int (__thiscall **)(void *, wchar_t *, int, int))(*(_DWORD *)g_pMapCheck + 4))(
             g_pMapCheck,
             v2,
             m_iMapCRC,
             dword358);
  if ( result == 1 )
  {
    this->byte35C = 1;
    this->gap3E6[0] = 1;
    this->gap3E6[1] = 1;
    this->gap3E6[9] = 1;
    result = 1;
    this->gap3E6[10] = 1;
    if ( !a2 )
    {
      *(_DWORD *)this->m_sPlayerType = 1;
      result = 4;
      *(_DWORD *)&this->m_sPlayerType[4] = 1;
    }
  }
  else if ( result == 2 )
  {
    return (int)std::wstring::operator=(&this->m_swpRealPlayerNames[1], (wchar_t *)L"Aeneas");
  }
  return result;
}


