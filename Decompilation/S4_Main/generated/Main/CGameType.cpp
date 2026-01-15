#include "CGameType.h"

// Definitions for class CGameType

// address=[0x1361450]
// Decompiled from char __thiscall CGameType::IsLadderGame(CGameType *this)
bool  CGameType::IsLadderGame(void)const {
  
  return *((_BYTE *)this + 1545);
}


// address=[0x13a4100]
// Decompiled from CGameType *__thiscall CGameType::ChangeLocalSlot(CGameType *this, signed __int8 a2)
void  CGameType::ChangeLocalSlot(signed char) {
  
  CGameType *result; // eax

  result = this;
  *((_BYTE *)this + 1537) = a2;
  return result;
}


// address=[0x13a4140]
// Decompiled from char __thiscall CGameType::IsClanGame(CGameType *this)
bool const  CGameType::IsClanGame(void) {
  
  return *((_BYTE *)this + 1544);
}


// address=[0x13a4160]
// Decompiled from char __thiscall sub_17A4160(_BYTE *this)
bool const  CGameType::IsSaveGame(void)const {
  
  return this[696];
}


// address=[0x13a4180]
// Decompiled from bool __thiscall CGameType::IsSlotChangable(CGameType *this, int a2, bool *a3)
bool  CGameType::IsSlotChangable(int,bool *) {
  
  bool v4; // [esp+4h] [ebp-8h]

  if ( (unsigned __int8)CGameType::IsSaveGame(this) )
    return 0;
  if ( !a3 )
    return *((_BYTE *)this + a2 + 600) == 0;
  v4 = *((_BYTE *)this + a2 + 440) || *((_DWORD *)this + a2 + 29) != 1;
  *a3 = v4;
  return *((_BYTE *)this + a2 + 600) == 0;
}


// address=[0x13a8490]
// Decompiled from char __thiscall CGameType::IsAddOnMap(CGameType *this)
bool  CGameType::IsAddOnMap(void) {
  
  return *((_BYTE *)this + 1546);
}


// address=[0x13a84b0]
// Decompiled from bool __thiscall CGameType::IsEmptyMap(CGameType *this)
bool  CGameType::IsEmptyMap(void) {
  
  return *((_DWORD *)this + 15) == 1;
}


// address=[0x1486e10]
// Decompiled from int __thiscall CGameType::GetLocalSlot(CGameType *this)
int const  CGameType::GetLocalSlot(void) {
  
  return *((char *)this + 1537);
}


// address=[0x1486e30]
// Decompiled from int __thiscall CGameType::GetMapBuildingXMLVersion(CGameType *this)
int  CGameType::GetMapBuildingXMLVersion(void)const {
  
  return *((_DWORD *)this + 389);
}


// address=[0x1486e50]
// Decompiled from int __thiscall CGameType::GetMapObjectXMLVersion(CGameType *this)
int  CGameType::GetMapObjectXMLVersion(void)const {
  
  return *((_DWORD *)this + 388);
}


// address=[0x1486e70]
// Decompiled from int __thiscall CGameType::GetMultiPlayerGameID(CGameType *this)
unsigned int const  CGameType::GetMultiPlayerGameID(void) {
  
  return *((_DWORD *)this + 383);
}


// address=[0x1486ef0]
// Decompiled from int __thiscall CGameType::GetRealPlayerName(void *this, unsigned int a2)
std::wstring &  CGameType::GetRealPlayerName(int) {
  
  if ( a2 >= 0xA
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\main\\GameType.h",
         298,
         "(_iPlayerIndex>=0) && (_iPlayerIndex<=PLAYER_MAX)") == 1 )
  {
    __debugbreak();
  }
  return (int)this + 28 * a2 + 1028;
}


// address=[0x1486fe0]
// Decompiled from char __thiscall CGameType::IsBlueByteAddOnMap(CGameType *this)
bool  CGameType::IsBlueByteAddOnMap(void) {
  
  return *((_BYTE *)this + 1547);
}


// address=[0x1487000]
// Decompiled from char __thiscall CGameType::IsBlueByteMCD2Map(CGameType *this)
bool  CGameType::IsBlueByteMCD2Map(void) {
  
  return *((_BYTE *)this + 1548);
}


// address=[0x1487020]
// Decompiled from char __thiscall CGameType::IsCampaignMap(CGameType *this)
bool  CGameType::IsCampaignMap(void) {
  
  return *((_BYTE *)this + 997);
}


// address=[0x1487040]
// Decompiled from char __thiscall CGameType::IsHost(CGameType *this)
bool const  CGameType::IsHost(void) {
  
  return *((_BYTE *)this + 1538);
}


// address=[0x1487060]
// Decompiled from char __thiscall CGameType::IsMCD2TextureSet(CGameType *this)
bool  CGameType::IsMCD2TextureSet(void) {
  
  return *((_BYTE *)this + 1549);
}


// address=[0x1487080]
// Decompiled from bool __thiscall CGameType::IsMultiplayerGame(CGameType *this)
bool const  CGameType::IsMultiplayerGame(void) {
  
  return *((_DWORD *)this + 173) == 2;
}


// address=[0x14873d0]
// Decompiled from CGameType *__thiscall CGameType::SetBlueByteMCD2Map(CGameType *this, bool a2)
void  CGameType::SetBlueByteMCD2Map(bool) {
  
  CGameType *result; // eax

  result = this;
  *((_BYTE *)this + 1548) = a2;
  return result;
}


// address=[0x14873f0]
// Decompiled from CGameType *__thiscall CGameType::SetClanGame(CGameType *this, bool a2)
void  CGameType::SetClanGame(bool) {
  
  CGameType *result; // eax

  result = this;
  *((_BYTE *)this + 1544) = a2;
  return result;
}


// address=[0x1487410]
// Decompiled from CGameType *__thiscall CGameType::SetHost(CGameType *this, bool a2)
void  CGameType::SetHost(bool) {
  
  CGameType *result; // eax

  result = this;
  *((_BYTE *)this + 1538) = a2;
  return result;
}


// address=[0x1487430]
// Decompiled from int __thiscall CGameType::SetLocalSlot(CGameType *this, signed __int8 a2)
void  CGameType::SetLocalSlot(signed char) {
  
  int result; // eax

  if ( *((char *)this + 1537) != -1 )
    CTrace::Print("overwirte m_iLocalPlayerSlot");
  if ( (unsigned int)a2 > 8
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\main\\GameType.h",
         470,
         "_iLocalSlotNr>=0 && _iLocalSlotNr<=MAX_PLAYER") == 1 )
  {
    __debugbreak();
  }
  result = *((char *)this + 1537);
  if ( result == -1 )
    *((_BYTE *)this + 1537) = a2;
  return result;
}


// address=[0x14874d0]
// Decompiled from CGameType *__thiscall CGameType::SetMCD2TextureSet(CGameType *this, bool a2)
void  CGameType::SetMCD2TextureSet(bool) {
  
  CGameType *result; // eax

  result = this;
  *((_BYTE *)this + 1549) = a2;
  return result;
}


// address=[0x14874f0]
// Decompiled from CGameType *__thiscall CGameType::SetMPSavegameID(CGameType *this, int a2)
void  CGameType::SetMPSavegameID(int) {
  
  CGameType *result; // eax

  result = this;
  *((_DWORD *)this + 385) = a2;
  return result;
}


// address=[0x1487510]
// Decompiled from CGameType *__thiscall CGameType::SetMultiPlayerGameID(CGameType *this, unsigned int a2)
void  CGameType::SetMultiPlayerGameID(unsigned int) {
  
  CGameType *result; // eax

  result = this;
  *((_DWORD *)this + 383) = a2;
  return result;
}


// address=[0x1487530]
// Decompiled from int __stdcall CGameType::SetPlayerName(unsigned int a1, int a2)
void  CGameType::SetPlayerName(int,std::wstring &) {
  
  if ( a1 >= 0xA
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\main\\GameType.h",
         305,
         "(_iPlayerIndex>=0) && (_iPlayerIndex<=PLAYER_MAX)") == 1 )
  {
    __debugbreak();
  }
  return std::wstring::operator=(a2);
}


// address=[0x1490f90]
// Decompiled from CGameType *__thiscall CGameType::CGameType(CGameType *this)
 CGameType::CGameType(void) {
  
  std::wstring::wstring(this);
  std::wstring::wstring((char *)this + 28);
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 28) = 0;
  *((_BYTE *)this + 560) = 0;
  *((_BYTE *)this + 609) = 0;
  *((_DWORD *)this + 153) = 0;
  *((_DWORD *)this + 154) = 0;
  *((_DWORD *)this + 155) = 0;
  *((_DWORD *)this + 165) = 0;
  std::string::string();
  *((_BYTE *)this + 696) = 0;
  *((_BYTE *)this + 697) = 0;
  *((_DWORD *)this + 175) = 0;
  std::wstring::wstring((char *)this + 704);
  *((_BYTE *)this + 732) = 0;
  *((_DWORD *)this + 184) = 0;
  *((_DWORD *)this + 186) = 0;
  *((_BYTE *)this + 748) = 0;
  *((_DWORD *)this + 188) = 0;
  std::string::string();
  std::string::string();
  std::string::string();
  *((_WORD *)this + 424) = 0;
  *((_DWORD *)this + 213) = 0;
  *((_DWORD *)this + 214) = 0;
  *((_BYTE *)this + 860) = 0;
  *((_BYTE *)this + 861) = 0;
  *((_DWORD *)this + 216) = 0;
  *((_BYTE *)this + 868) = 0;
  *((_BYTE *)this + 869) = 0;
  *((_BYTE *)this + 870) = 0;
  *((_BYTE *)this + 871) = 0;
  *((_BYTE *)this + 872) = 0;
  *((_BYTE *)this + 873) = 0;
  *((_BYTE *)this + 874) = 0;
  *((_BYTE *)this + 875) = 0;
  *((_BYTE *)this + 876) = 0;
  *((_DWORD *)this + 220) = 0;
  std::string::string();
  std::string::string();
  std::string::string();
  std::string::string();
  *((_BYTE *)this + 996) = 0;
  *((_BYTE *)this + 997) = 0;
  *((_DWORD *)this + 254) = 0;
  *((_DWORD *)this + 255) = 0;
  *((_DWORD *)this + 256) = 0;
  _vec_ctor((char *)this + 1028, 0x1Cu, 9u, std::wstring::wstring, std::wstring::~wstring);
  _vec_ctor((char *)this + 1280, 0x1Cu, 9u, std::wstring::wstring, std::wstring::~wstring);
  *((_DWORD *)this + 383) = 0;
  *((_BYTE *)this + 1536) = 0;
  *((_BYTE *)this + 1537) = 0;
  *((_BYTE *)this + 1538) = 0;
  *((_BYTE *)this + 1539) = 0;
  *((_DWORD *)this + 385) = 0;
  *((_BYTE *)this + 1544) = 0;
  *((_BYTE *)this + 1545) = 0;
  *((_BYTE *)this + 1546) = 0;
  *((_BYTE *)this + 1547) = 0;
  *((_BYTE *)this + 1548) = 0;
  *((_BYTE *)this + 1549) = 0;
  *((_DWORD *)this + 388) = 0;
  *((_DWORD *)this + 389) = 0;
  *((_DWORD *)this + 390) = 0;
  *((_DWORD *)this + 391) = 0;
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
// Decompiled from char __thiscall CGameType::LoadMapData(  CGameType *this,  char a2,  int a3,  int a4,  int a5,  int a6,  int a7,  int a8,  bool a9,  int a10,  unsigned __int8 a11,  char a12,  int a13,  int a14,  int a15,  unsigned __int8 a16,  char a17)
bool  CGameType::LoadMapData(std::wstring,bool,unsigned int,bool,bool,int,int,int,bool,bool) {
  
  OLECHAR *v18; // eax
  int v19; // eax
  int v20; // eax
  _DWORD *v21; // eax
  char *v22; // [esp-Ch] [ebp-8D24h]
  int v23; // [esp-4h] [ebp-8D1Ch]
  struct tagVARIANT v24; // [esp+8h] [ebp-8D10h] BYREF
  int v25; // [esp+18h] [ebp-8D00h]
  int v26; // [esp+1Ch] [ebp-8CFCh]
  signed int v27; // [esp+20h] [ebp-8CF8h]
  signed int v28; // [esp+24h] [ebp-8CF4h]
  void *v29; // [esp+28h] [ebp-8CF0h]
  int v30; // [esp+2Ch] [ebp-8CECh] BYREF
  void *v31; // [esp+30h] [ebp-8CE8h]
  void *v32; // [esp+34h] [ebp-8CE4h]
  void *C; // [esp+38h] [ebp-8CE0h]
  size_t v34; // [esp+3Ch] [ebp-8CDCh]
  int AIName; // [esp+40h] [ebp-8CD8h]
  S4::CMapFile *v36; // [esp+44h] [ebp-8CD4h]
  BOOL v37; // [esp+48h] [ebp-8CD0h]
  BSTR v38; // [esp+4Ch] [ebp-8CCCh] BYREF
  BOOL v39; // [esp+50h] [ebp-8CC8h]
  size_t v40; // [esp+54h] [ebp-8CC4h]
  int v41; // [esp+58h] [ebp-8CC0h]
  int v42; // [esp+5Ch] [ebp-8CBCh]
  int v43; // [esp+60h] [ebp-8CB8h]
  int StringId; // [esp+64h] [ebp-8CB4h]
  int v45; // [esp+68h] [ebp-8CB0h]
  BOOL v46; // [esp+6Ch] [ebp-8CACh]
  int v47; // [esp+70h] [ebp-8CA8h]
  int v48; // [esp+74h] [ebp-8CA4h] BYREF
  _BYTE *v49; // [esp+78h] [ebp-8CA0h]
  wchar_t *String1; // [esp+7Ch] [ebp-8C9Ch] BYREF
  int v51; // [esp+80h] [ebp-8C98h]
  int v52; // [esp+84h] [ebp-8C94h] BYREF
  int v53; // [esp+88h] [ebp-8C90h] BYREF
  int v54; // [esp+8Ch] [ebp-8C8Ch] BYREF
  char *v55; // [esp+90h] [ebp-8C88h]
  signed int v56; // [esp+94h] [ebp-8C84h]
  char *Source; // [esp+98h] [ebp-8C80h]
  _BYTE *v58; // [esp+9Ch] [ebp-8C7Ch]
  _DWORD *Chunk; // [esp+A0h] [ebp-8C78h]
  int v60; // [esp+A4h] [ebp-8C74h] BYREF
  int n; // [esp+A8h] [ebp-8C70h]
  int v62; // [esp+ACh] [ebp-8C6Ch]
  BSTR pbstr; // [esp+B0h] [ebp-8C68h] BYREF
  int k; // [esp+B4h] [ebp-8C64h]
  int v65; // [esp+B8h] [ebp-8C60h] BYREF
  BSTR bstrString; // [esp+BCh] [ebp-8C5Ch] BYREF
  char v67; // [esp+C3h] [ebp-8C55h]
  char *v68; // [esp+C4h] [ebp-8C54h]
  BSTR v69; // [esp+C8h] [ebp-8C50h]
  int v70; // [esp+CCh] [ebp-8C4Ch] BYREF
  char v71; // [esp+D0h] [ebp-8C48h]
  signed int j; // [esp+D4h] [ebp-8C44h]
  char v73; // [esp+DBh] [ebp-8C3Dh]
  bool v74; // [esp+DCh] [ebp-8C3Ch]
  bool v75; // [esp+DDh] [ebp-8C3Bh]
  bool v76; // [esp+DEh] [ebp-8C3Ah]
  bool v77; // [esp+DFh] [ebp-8C39h]
  int v78; // [esp+E0h] [ebp-8C38h] BYREF
  OLECHAR v79; // [esp+E4h] [ebp-8C34h]
  int i; // [esp+E8h] [ebp-8C30h]
  bool v81; // [esp+EFh] [ebp-8C29h]
  int m; // [esp+F0h] [ebp-8C28h]
  CGameType *v83; // [esp+F4h] [ebp-8C24h]
  _BYTE v84[184]; // [esp+F8h] [ebp-8C20h] BYREF
  _BYTE v85[72]; // [esp+1B0h] [ebp-8B68h] BYREF
  _BYTE v86[28]; // [esp+1F8h] [ebp-8B20h] BYREF
  _BYTE v87[28]; // [esp+214h] [ebp-8B04h] BYREF
  _BYTE v88[28]; // [esp+230h] [ebp-8AE8h] BYREF
  char v89[28]; // [esp+24Ch] [ebp-8ACCh] BYREF
  char Buffer[2048]; // [esp+268h] [ebp-8AB0h] BYREF
  char Destination[16384]; // [esp+A68h] [ebp-82B0h] BYREF
  char Dest[16384]; // [esp+4A68h] [ebp-42B0h] BYREF
  char v93[256]; // [esp+8A68h] [ebp-2B0h] BYREF
  char v94[144]; // [esp+8B68h] [ebp-1B0h] BYREF
  char v95[144]; // [esp+8BF8h] [ebp-120h] BYREF
  char Str[128]; // [esp+8C88h] [ebp-90h] BYREF
  int v97; // [esp+8D14h] [ebp-4h]

  v83 = this;
  v97 = 0;
  CGameType::Init(this);
  v54 = 0;
  v53 = 0;
  v52 = 0;
  v78 = 0;
  *((_BYTE *)v83 + 732) = a9;
  *((_DWORD *)v83 + 17) = a10;
  if ( a14 != -1 )
  {
    if ( a14 )
      a14 = 3;
    else
      a14 = 2;
  }
  std::wstring::wstring(v89);
  LOBYTE(v97) = 1;
  *((_DWORD *)v83 + 153) = 0;
  *((_DWORD *)v83 + 154) = 0;
  if ( (*(unsigned __int8 (__thiscall **)(void *, char *, char *))(*(_DWORD *)g_pRandomMaps + 32))(
         g_pRandomMaps,
         &a2,
         v89) )
  {
    std::string::operator=(&unk_402C998, (char *)&byte_36FE4FB);
    std::string::operator=(&unk_402C9D0, (char *)&byte_36FE50F);
    std::string::operator=(&unk_402C97C, (char *)&byte_36FE5B2);
    std::string::operator=(&unk_402C9B4, (char *)&byte_36FE5B3);
    std::wstring::operator=((int)&a2);
    if ( !(*(unsigned __int8 (__thiscall **)(void *, _BYTE *, char *))(*(_DWORD *)g_pRandomMaps + 16))(
            g_pRandomMaps,
            v84,
            v89) )
    {
      BBSupportTracePrintF(0, "[MM] LoadMapData: couldn't GetParamsFromMapKey");
      LOBYTE(v97) = 0;
      std::wstring::~wstring(v89);
      v97 = -1;
      std::wstring::~wstring(&a2);
      return 0;
    }
    (**(void (__thiscall ***)(void *, _BYTE *))g_pRandomMaps)(g_pRandomMaps, v84);
    if ( !(*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)g_pRandomMaps + 8))(g_pRandomMaps) )
    {
      BBSupportTracePrintF(0, "[MM] LoadMapData: couldn't GenereateRandomMap");
      LOBYTE(v97) = 0;
      std::wstring::~wstring(v89);
      v97 = -1;
      std::wstring::~wstring(&a2);
      return 0;
    }
    v36 = (S4::CMapFile *)(*(int (__thiscall **)(void *))(*(_DWORD *)g_pRandomMaps + 12))(g_pRandomMaps);
    if ( !v36 )
    {
      BBSupportTracePrintF(0, "[MM] LoadMapData: pMapFile == 0");
      LOBYTE(v97) = 0;
      std::wstring::~wstring(v89);
      v97 = -1;
      std::wstring::~wstring(&a2);
      return 0;
    }
    Chunk = S4::CMapFile::LoadChunk(v36, 220, 0);
    *((_BYTE *)v83 + 997) = 0;
    *((_BYTE *)v83 + 996) = 0;
    *((_DWORD *)v83 + 14) = Chunk[3];
    *((_DWORD *)v83 + 16) = 1;
    *((_DWORD *)v83 + 15) = 1;
    *((_DWORD *)v83 + 216) = 1;
    *((_BYTE *)v83 + 872) = 1;
    *((_BYTE *)v83 + 871) = 1;
    std::string::operator=((char *)v83 + 968, (char *)&byte_36FE5D1);
    std::string::operator=((char *)v83 + 884, (char *)&byte_36FE5D2);
    std::string::operator=((char *)v83 + 912, (char *)&byte_36FE5D3);
    std::string::operator=((char *)v83 + 940, (char *)&byte_36FE5FA);
    *((_DWORD *)v83 + 220) = 1;
    *((_DWORD *)v83 + 213) = Chunk[4];
    *((_BYTE *)v83 + 874) = 1;
    *((_BYTE *)v83 + 875) = 1;
    *((_BYTE *)v83 + 876) = 1;
    *((_BYTE *)v83 + 873) = 1;
    for ( i = 0; i < *((_DWORD *)v83 + 213); ++i )
    {
      *((_BYTE *)v83 + i + 600) = 0;
      *((_DWORD *)v83 + i + 101) = 5;
      *((_DWORD *)v83 + i + 65) = Chunk[i + 6];
      *((_DWORD *)v83 + i + 74) = Chunk[i + 15];
      *((_DWORD *)v83 + i + 38) = i;
      *((_BYTE *)v83 + i + 998) = 1;
      *((_BYTE *)v83 + i + 1007) = 1;
      if ( i && a9 )
      {
        if ( a14 == -1 )
          *((_DWORD *)v83 + i + 29) = 2;
        else
          *((_DWORD *)v83 + i + 29) = a14;
      }
      else
      {
        *((_DWORD *)v83 + i + 29) = 1;
      }
      if ( *((_DWORD *)v83 + i + 29) != 1 )
      {
        AIName = CGameSettings::GetAIName((int)v86, i);
        std::wstring::operator=(AIName);
        std::wstring::~wstring(v86);
      }
    }
    *((_DWORD *)v83 + 18) = *((_DWORD *)v83 + 213);
    *((_BYTE *)v83 + 861) = 1;
    *((_BYTE *)v83 + 860) = 1;
    *((_DWORD *)v83 + 214) = 0;
  }
  else
  {
    std::wstring::operator=((int)&a2);
    v23 = a11;
    v22 = (char *)v83 + 612;
    v18 = (OLECHAR *)std::wstring::c_str((CGameType *)((char *)v83 + 28));
    MA_OpenMapFile(v18, (int)v22, (int)&v48, v23);
    if ( v48 )
    {
      CTrace::Print("CGameType.cpp: Unable to open Map via Mapreader. Reported error %d", v48);
      v67 = 0;
      LOBYTE(v97) = 0;
      std::wstring::~wstring(v89);
      v97 = -1;
      std::wstring::~wstring(&a2);
      return v67;
    }
    MA_GetDataChecksums(&v54, &v53);
    if ( a12 )
    {
      *((_DWORD *)v83 + 389) = v54;
      *((_DWORD *)v83 + 388) = v53;
    }
    else
    {
      *((_DWORD *)v83 + 389) = 0;
      *((_DWORD *)v83 + 388) = 0;
    }
    MA_IsCampaignMap(&v70);
    v77 = v70 != 0;
    *((_BYTE *)v83 + 997) = v70 != 0;
    MA_IsEditorMap(&v70);
    v76 = v70 != 0;
    *((_BYTE *)v83 + 996) = v70 != 0;
    MA_GetMapProperty(1, &v70);
    v75 = v70 != 0;
    *((_BYTE *)v83 + 1546) = v70 != 0;
    MA_GetMapProperty(2, &v70);
    v74 = v70 != 0;
    *((_BYTE *)v83 + 1547) = v70 != 0;
    MA_GetMapData((int)v83 + 56, (int)&v52, (int)&v78, (int)v83 + 64, (int)v83 + 60);
    if ( (v52 & 2) != 0 )
      v47 = 2;
    else
      v47 = 1;
    *((_DWORD *)v83 + 216) = v47;
    if ( *((_DWORD *)v83 + 216) == 2 )
      *((_BYTE *)v83 + 872) = 1;
    else
      *((_BYTE *)v83 + 871) = 1;
    std::string::operator=((char *)v83 + 968, (char *)&byte_36FE5FB);
    std::string::operator=((char *)v83 + 884, (char *)&byte_36FE61F);
    std::string::operator=((char *)v83 + 912, (char *)&byte_36FE682);
    std::string::operator=((char *)v83 + 940, (char *)&byte_36FE683);
    memset(Destination, 0, sizeof(Destination));
    memset(Dest, 0, sizeof(Dest));
    v81 = 0;
    pbstr = 0;
    MA_GetDescriptionText(0, &pbstr);
    if ( pbstr )
    {
      memset(Str, 0, sizeof(Str));
      v69 = pbstr;
      for ( j = SysStringLen(pbstr); j > 0 && *v69 <= 0x20u; --j )
        ++v69;
      while ( j > 0 && v69[j - 1] <= 0x20u )
        --j;
      v46 = j >= 2 && (unsigned int)j < 0x80 && *v69 == 36 && v69[j - 1] == 36;
      v81 = v46;
      if ( v46 )
      {
        for ( k = 1; k < j - 1; ++k )
        {
          v79 = v69[k];
          if ( (v79 < 0x41u || v79 > 0x5Au) && (v79 < 0x30u || v79 > 0x39u) && v79 != 95 )
          {
            v81 = 0;
            break;
          }
          v95[k + 143] = v79;
        }
      }
      if ( v81 )
      {
        v56 = j__strlen(Str);
        if ( v56 > 5 && !j__strcmp(&v95[v56 + 139], "_DESC") && CS4DefineNames::GetStringId(Str) >= 0 )
        {
          v45 = v56 - 5;
          if ( (unsigned int)(v56 - 5) >= 0x80 )
            j____report_rangecheckfailure();
          Str[v45] = 0;
        }
        j___snprintf(v94, 0x90u, "%s_DESC", Str);
        j___snprintf(v95, 0x90u, "%s_TIPS", Str);
        StringId = CS4DefineNames::GetStringId(v94);
        v43 = CS4DefineNames::GetStringId(v95);
        if ( StringId >= 0 )
        {
          Source = g_pStringEngine->GetString(g_pStringEngine, StringId);
          if ( Source )
          {
            if ( *Source )
              j__strncpy(Destination, Source, 0x3FFFu);
          }
        }
        if ( v43 >= 0 )
        {
          v55 = g_pStringEngine->GetString(g_pStringEngine, v43);
          if ( v55 )
          {
            if ( *v55 )
              j__strncpy(Dest, v55, 0x3FFFu);
          }
        }
      }
      SysFreeString(pbstr);
    }
    if ( !v81 )
    {
      if ( CGameSettings::GetLanguage() == 1 )
        v42 = 0;
      else
        v42 = 2;
      v41 = v42;
      bstrString = 0;
      MA_GetDescriptionText(v42, &bstrString);
      v27 = j__wcstombs(Destination, bstrString, 0x3FFEu);
      if ( v27 <= 0 )
        memset(Destination, 0, sizeof(Destination));
      SysFreeString(bstrString);
      MA_GetDescriptionText(v41 + 1, &bstrString);
      v28 = j__wcstombs(Dest, bstrString, 0x3FFEu);
      if ( v28 <= 0 )
        memset(Dest, 0, sizeof(Dest));
      SysFreeString(bstrString);
    }
    if ( Destination[0] )
    {
      v68 = Destination;
      v58 = (_BYTE *)_mbsstr((int)Destination, "@");
      if ( v58 )
      {
        *v58 = 0;
        std::string::operator=((char *)v83 + 940, v68);
        v68 = v58 + 1;
        v49 = (_BYTE *)_mbsstr((int)(v58 + 1), "@");
        if ( v49 )
        {
          *v49 = 0;
          std::string::operator=((char *)v83 + 968, v68);
          v68 = v49 + 1;
        }
      }
      std::string::operator=((char *)v83 + 884, v68);
    }
    if ( Dest[0] )
      std::string::operator=((char *)v83 + 912, Dest);
    MA_GetNumberOfSetups((int *)v83 + 220);
    MA_GetNumberOfPlayers((int)v83 + 852);
    v51 = 0;
    *((_BYTE *)v83 + 874) = (v78 & 1) != 0 && CGameType::IsEmptyMap(v83);
    *((_BYTE *)v83 + 875) = (v78 & 2) != 0;
    *((_BYTE *)v83 + 876) = (v78 & 4) == 0 && CGameType::IsEmptyMap(v83);
    *((_BYTE *)v83 + 873) = (v78 & 8) == 0;
    *((_BYTE *)v83 + 1547) = (v78 & 0x40) != 0;
    *((_BYTE *)v83 + 1548) = (v78 & 0x100) != 0;
    *((_BYTE *)v83 + 1549) = (v78 & 0x200) != 0;
    v73 = 0;
    v62 = 0;
    for ( m = 0; m < *((_DWORD *)v83 + 213); ++m )
    {
      MA_GetPlayerData(
        m + 1,
        a13,
        (int *)v83 + m + 101,
        (int *)v83 + m + 65,
        (int *)v83 + m + 74,
        &String1,
        &v38,
        &v60,
        &v30,
        &v65);
      if ( v65 >= 0 )
      {
        if ( v65 > 8 )
          v65 = 0;
      }
      else
      {
        v65 = 0;
      }
      *((_DWORD *)v83 + m + 38) = v65;
      v34 = j__wcstombs(v93, v38, 0x100u);
      v40 = v34;
      if ( v34 >= 0x100 )
        j____report_rangecheckfailure();
      v93[v40] = 0;
      v29 = std::string::string(v87, v93);
      std::string::operator=((char *)v83 + 756, v29);
      std::string::~string(v87);
      if ( j__wcscmp(String1, &String2) )
        std::wstring::operator=((char *)v83 + 28 * m + 1028, String1);
      v39 = v60 == 2;
      *((_BYTE *)v83 + m + 600) = v39;
      if ( v60 )
      {
        if ( v60 != 2 )
        {
          if ( m )
            v73 = 1;
          ++v62;
        }
        *((_BYTE *)v83 + m + 998) = 0;
        if ( v60 == 2 )
        {
          if ( a14 == -1 )
            *((_DWORD *)v83 + m + 29) = 2;
          else
            *((_DWORD *)v83 + m + 29) = a14;
        }
        else
        {
          *((_DWORD *)v83 + m + 29) = 1;
        }
      }
      else
      {
        ++v62;
        *((_BYTE *)v83 + m + 998) = 1;
        *((_DWORD *)v83 + m + 29) = 1;
        if ( a9 )
        {
          if ( a14 == -1 )
            *((_DWORD *)v83 + m + 29) = 2;
          else
            *((_DWORD *)v83 + m + 29) = a14;
        }
      }
      if ( (*((_DWORD *)v83 + m + 29) == 2 || *((_DWORD *)v83 + m + 29) == 3)
        && (unsigned __int8)std::operator==<wchar_t>((int)v83 + 28 * m + 1028, (wchar_t *)&word_36FEE98) )
      {
        v26 = CGameSettings::GetAIName((int)v88, m);
        std::wstring::operator=(v26);
        std::wstring::~wstring(v88);
      }
      if ( *((_DWORD *)v83 + m + 38) > v51 )
        v51 = *((_DWORD *)v83 + m + 38);
      if ( *((_DWORD *)v83 + m + 101) == 255 )
      {
        *((_BYTE *)v83 + m + 1007) = 1;
        *((_DWORD *)v83 + m + 101) = 5;
      }
      else
      {
        *((_BYTE *)v83 + m + 1007) = 0;
      }
      if ( *((_BYTE *)v83 + 997) )
        *((_BYTE *)v83 + m + 440) = 0;
      SysFreeString(v38);
      SysFreeString(String1);
    }
    if ( *((_DWORD *)v83 + 213) == 1 || *((_BYTE *)v83 + 875) && *((_BYTE *)v83 + 876) || !v73 )
      *((_BYTE *)v83 + 861) = 1;
    if ( v62 >= 2 )
      *((_BYTE *)v83 + 860) = 1;
    *((_DWORD *)v83 + 18) = v51 + 1;
    for ( m = 0; m < *((_DWORD *)v83 + 213); ++m )
    {
      if ( *((int *)v83 + m + 38) < 9 )
        ++*((_DWORD *)v83 + *((_DWORD *)v83 + m + 38) + 19);
    }
    if ( *((_DWORD *)v83 + 18) == 1 )
    {
      *((_BYTE *)v83 + 871) = 0;
    }
    else
    {
      *((_BYTE *)v83 + 868) = (v78 & 0x10) != 0;
      *((_BYTE *)v83 + 869) = (v78 & 0x20) != 0;
    }
    if ( !a13 && *((_DWORD *)v83 + 254) )
    {
      C = (void *)*((_DWORD *)v83 + 254);
      operator delete[](C);
      *((_DWORD *)v83 + 254) = 0;
    }
    if ( *((_BYTE *)v83 + 873) && a11 )
    {
      if ( !a13 && *((_DWORD *)v83 + 254) )
      {
        v32 = (void *)*((_DWORD *)v83 + 254);
        operator delete[](v32);
        *((_DWORD *)v83 + 254) = 0;
      }
      MA_GetPreviewMapRawData((int *)v83 + 255, (int *)v83 + 256, &v24);
      if ( v24.lVal )
      {
        v31 = operator new[](2 * *((_DWORD *)v83 + 256) * *((_DWORD *)v83 + 255));
        *((_DWORD *)v83 + 254) = v31;
        j__memcpy(*((void **)v83 + 254), v24.bstrVal, 2 * *((_DWORD *)v83 + 256) * *((_DWORD *)v83 + 255));
      }
    }
    MA_CloseMapFile();
    CFile::CFile((CFile *)v85);
    LOBYTE(v97) = 2;
    CFile::Open((int)v83 + 28, 6, "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h", 0);
    v19 = CFile::Size(v85);
    *((_DWORD *)v83 + 214) = v19;
    CFile::Close((CFile *)v85, "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h", 0);
    LOBYTE(v97) = 1;
    CFile::~CFile();
  }
  for ( n = 0; n < *((_DWORD *)v83 + 213); ++n )
    *((_DWORD *)v83 + n + 83) = n;
  if ( *((_DWORD *)v83 + 18) == 1
    || *((_BYTE *)v83 + 876) && *((_BYTE *)v83 + 875) && !*((_BYTE *)v83 + 997) && *((_BYTE *)v83 + 732) )
  {
    *((_BYTE *)v83 + 870) = 1;
  }
  if ( !*((_BYTE *)v83 + 871) && *((_BYTE *)v83 + 870) && !*((_BYTE *)v83 + 872) )
  {
    if ( a15 == 8 || (v78 & 0x80) != 0 )
    {
      *((_DWORD *)v83 + 216) = 1;
      *((_BYTE *)v83 + 871) = 1;
      *((_BYTE *)v83 + 870) = 0;
    }
    else
    {
      *((_DWORD *)v83 + 216) = 5;
      *((_BYTE *)v83 + 870) = 1;
    }
  }
  *((_BYTE *)v83 + 869) = 0;
  if ( !*((_BYTE *)v83 + 870)
    && !*((_BYTE *)v83 + 871)
    && !*((_BYTE *)v83 + 869)
    && !*((_BYTE *)v83 + 868)
    && !*((_BYTE *)v83 + 872)
    && BBSupportDbgReport(
         2,
         "main\\GameType.cpp",
         1032,
         "m_bFreeSettlePossible || m_bConflictPossible || m_bCompetetivePossible || m_bEconomyPossible || m_bCooperationPossible") == 1 )
  {
    __debugbreak();
  }
  *((_BYTE *)v83 + 1536) = 1;
  v20 = (**(int (__thiscall ***)(void *, _DWORD, _DWORD, _DWORD, int, int))g_pMapCheck)(
          g_pMapCheck,
          *((_DWORD *)v83 + 153),
          *((_DWORD *)v83 + 213),
          *((_DWORD *)v83 + 14),
          v52,
          v78);
  *((_DWORD *)v83 + 154) = v20;
  v25 = 1024;
  v21 = std::wstring::c_str((_Cnd_internal_imp_t *)&a2);
  j___snwprintf(Buffer, 0x400u, L"\"%s\",", v21);
  BBSupportTracePrintF(
    1,
    "Map info: %-53s  0x%08x, %8i, %4i / %4i",
    Buffer,
    *((_DWORD *)v83 + 154),
    *((_DWORD *)v83 + 214),
    v54,
    v53);
  CGameType::PatchMaps(v83, a9);
  v37 = a17 == 0;
  if ( (v37 & a16) != 0 )
  {
    *((_BYTE *)v83 + 876) = 0;
    *((_BYTE *)v83 + 875) = 0;
    *((_DWORD *)v83 + 213) = 2;
    *((_DWORD *)v83 + 18) = 2;
    *((_DWORD *)v83 + 38) = 0;
    *((_DWORD *)v83 + 39) = 1;
  }
  v71 = 1;
  LOBYTE(v97) = 0;
  std::wstring::~wstring(v89);
  v97 = -1;
  std::wstring::~wstring(&a2);
  return v71;
}


// address=[0x1492f70]
// Decompiled from bool __thiscall CGameType::IsMapAvailable(char *this, int a2, int a3)
bool  CGameType::IsMapAvailable(std::wstring &,int) {
  
  OLECHAR *v4; // eax
  int v5; // [esp+0h] [ebp-2Ch]
  int v6; // [esp+4h] [ebp-28h] BYREF
  int v7; // [esp+8h] [ebp-24h] BYREF
  int v8; // [esp+Ch] [ebp-20h] BYREF
  int v9; // [esp+14h] [ebp-18h] BYREF
  int v10; // [esp+18h] [ebp-14h] BYREF
  int v11; // [esp+1Ch] [ebp-10h] BYREF
  int v12; // [esp+20h] [ebp-Ch] BYREF
  int v13; // [esp+24h] [ebp-8h] BYREF
  char *v14; // [esp+28h] [ebp-4h]

  v14 = this;
  if ( (*(unsigned __int8 (__thiscall **)(void *, int, _DWORD))(*(_DWORD *)g_pRandomMaps + 32))(g_pRandomMaps, a2, 0) )
    return 1;
  std::wstring::operator=(a2);
  v4 = (OLECHAR *)std::wstring::c_str((_Cnd_internal_imp_t *)(v14 + 28));
  MA_OpenMapFile(v4, (int)&v6, (int)&v13, 1);
  if ( v13 )
  {
    CTrace::Print("CGameType.cpp: Unable to open Map via Mapreader. Reported error %d", v13);
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
// Decompiled from void __thiscall CGameType::SetMapCRC(_DWORD *this, int a2)
void  CGameType::SetMapCRC(std::wstring &) {
  
  OLECHAR *v2; // eax
  int v3; // eax
  int v4; // [esp-Ch] [ebp-2Ch]
  int v5; // [esp+0h] [ebp-20h] BYREF
  int v6; // [esp+4h] [ebp-1Ch] BYREF
  int v7; // [esp+8h] [ebp-18h] BYREF
  int v8; // [esp+Ch] [ebp-14h] BYREF
  int v9; // [esp+10h] [ebp-10h] BYREF
  int v10; // [esp+14h] [ebp-Ch] BYREF
  int v11; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v12; // [esp+1Ch] [ebp-4h]

  v12 = this;
  this[153] = 0;
  v12[154] = 0;
  std::wstring::operator=(a2);
  v4 = (int)(v12 + 153);
  v2 = (OLECHAR *)std::wstring::c_str((_Cnd_internal_imp_t *)(v12 + 7));
  MA_OpenMapFile(v2, v4, (int)&v7, 1);
  if ( v7 )
  {
    v12[153] = 0;
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
           v12[153],
           v8,
           v9,
           v10,
           v11);
    v12[154] = v3;
    MA_CloseMapFile();
  }
}


// address=[0x1493190]
// Decompiled from int __thiscall CGameType::HumanPlayers(CGameType *this)
int  CGameType::HumanPlayers(void) {
  
  int v2; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  for ( i = 0; i < *((_DWORD *)this + 213); ++i )
  {
    if ( *((_DWORD *)this + i + 29) == 1 )
      ++v2;
  }
  return v2;
}


// address=[0x14931e0]
// Decompiled from CGameType *__thiscall CGameType::Init(CGameType *this)
void  CGameType::Init(void) {
  
  CGameType *result; // eax
  int i; // [esp+0h] [ebp-8h]
  int j; // [esp+0h] [ebp-8h]

  *((_BYTE *)this + 1536) = 0;
  std::wstring::operator=(this, (wchar_t *)&word_36FE958);
  std::wstring::operator=((char *)this + 28, (wchar_t *)&word_36FE95C);
  *((_DWORD *)this + 14) = 0;
  *((_BYTE *)this + 732) = 1;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 28) = 0;
  *((_BYTE *)this + 560) = 0;
  *((_DWORD *)this + 254) = 0;
  *((_DWORD *)this + 255) = 0;
  *((_DWORD *)this + 256) = 0;
  *((_DWORD *)this + 213) = 0;
  *((_DWORD *)this + 216) = 0;
  *((_BYTE *)this + 868) = 0;
  *((_BYTE *)this + 869) = 0;
  *((_BYTE *)this + 873) = 0;
  *((_BYTE *)this + 874) = 0;
  *((_BYTE *)this + 875) = 0;
  *((_BYTE *)this + 876) = 0;
  *((_BYTE *)this + 996) = 0;
  *((_BYTE *)this + 997) = 0;
  *((_DWORD *)this + 220) = 0;
  *((_BYTE *)this + 860) = 0;
  *((_BYTE *)this + 861) = 0;
  *((_DWORD *)this + 185) = 0;
  *((_BYTE *)this + 609) = 1;
  *((_DWORD *)this + 155) = 0;
  *((_DWORD *)this + 165) = 0;
  *((_DWORD *)this + 383) = -1;
  std::string::operator=((char *)this + 664, (char *)&byte_36FE4FA);
  *((_DWORD *)this + 173) = 1;
  *((_BYTE *)this + 696) = 0;
  std::wstring::operator=((char *)this + 704, (wchar_t *)&word_36FE960);
  *((_DWORD *)this + 184) = 0;
  *((_BYTE *)this + 748) = 0;
  *((_DWORD *)this + 188) = -1;
  *((_BYTE *)this + 870) = 0;
  *((_BYTE *)this + 871) = 0;
  *((_BYTE *)this + 872) = 0;
  *((_DWORD *)this + 14) = 0;
  for ( i = 0; i < 9; ++i )
    *((_DWORD *)this + i + 19) = 0;
  for ( j = 0; j < 9; ++j )
  {
    *((_DWORD *)this + j + 29) = 0;
    std::wstring::operator=((char *)this + 28 * j + 1028, (wchar_t *)&word_36FE964);
    *((_DWORD *)this + j + 38) = 0;
    *((_DWORD *)this + j + 47) = 0;
    *((_DWORD *)this + j + 56) = -1;
    *((_DWORD *)this + j + 65) = 0;
    *((_DWORD *)this + j + 74) = 0;
    *((_DWORD *)this + j + 101) = 5;
    *((_DWORD *)this + j + 83) = 0;
    *((_DWORD *)this + j + 92) = j;
    *((_DWORD *)this + j + 156) = 0;
    *((_BYTE *)this + j + 440) = 1;
    *((_DWORD *)this + j + 113) = 0;
    *((_DWORD *)this + j + 122) = 0;
    *((_DWORD *)this + j + 131) = -1;
    std::wstring::operator=((char *)this + 28 * j + 1280, (wchar_t *)&word_36FE968);
    *((_DWORD *)this + j + 141) = -1;
  }
  *((_DWORD *)this + 165) = CStaticConfigVarInt::operator int(&g_iNetworkTimeDelta);
  *((_DWORD *)this + 175) = 0;
  *((_WORD *)this + 424) = 0;
  memset((char *)this + 784, 0, 7u);
  *((_BYTE *)this + 1537) = -1;
  *((_BYTE *)this + 1538) = 0;
  *((_BYTE *)this + 1539) = 0;
  *((_DWORD *)this + 385) = 0;
  *((_BYTE *)this + 1544) = 0;
  *((_BYTE *)this + 1545) = 0;
  *((_BYTE *)this + 1546) = 0;
  *((_BYTE *)this + 1547) = 0;
  *((_BYTE *)this + 1548) = 0;
  *((_BYTE *)this + 1549) = 0;
  *((_DWORD *)this + 388) = 0;
  *((_DWORD *)this + 389) = 0;
  result = this;
  *((_DWORD *)this + 390) = 0;
  *((_DWORD *)this + 391) = 0;
  return result;
}


// address=[0x1493620]
// Decompiled from int __thiscall CGameType::ConvertMapNameToMPGameName(char *this, int a2)
std::wstring  CGameType::ConvertMapNameToMPGameName(void) {
  
  CGameType::ConvertMapNameToMPGameName(a2, this + 28);
  return a2;
}


// address=[0x1493660]
// Decompiled from void *__cdecl CGameType::ConvertMapNameToMPGameName(void *a1, _Cnd_internal_imp_t *a2)
static std::wstring __cdecl CGameType::ConvertMapNameToMPGameName(std::wstring &) {
  
  const wchar_t *v2; // eax
  wchar_t Dir[256]; // [esp+4h] [ebp-814h] BYREF
  wchar_t Ext[256]; // [esp+204h] [ebp-614h] BYREF
  wchar_t Destination[260]; // [esp+404h] [ebp-414h] BYREF
  wchar_t Filename[256]; // [esp+60Ch] [ebp-20Ch] BYREF
  wchar_t Drive[4]; // [esp+80Ch] [ebp-Ch] BYREF

  v2 = (const wchar_t *)std::wstring::c_str(a2);
  j__wcscpy(Destination, v2);
  j___wsplitpath(Destination, Drive, Dir, Filename, Ext);
  std::wstring::wstring(a1, Filename);
  return a1;
}


// address=[0x14936f0]
// Decompiled from void *__thiscall CGameType::GetPlayerName(void *this, void *a2, unsigned int a3)
std::wstring  CGameType::GetPlayerName(int) {
  
  _BYTE v5[28]; // [esp+Ch] [ebp-2Ch] BYREF
  int v6; // [esp+34h] [ebp-4h]

  if ( a3 >= 0xA
    && BBSupportDbgReport(2, "main\\GameType.cpp", 1114, "(_iPlayerIndex>=0) && (_iPlayerIndex<=PLAYER_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( (unsigned __int8)CGameType::IsClanGame(this) )
  {
    std::wstring::wstring((int)this + 28 * a3 + 1280);
    v6 = 0;
    std::wstring::operator+=(v5, (wchar_t *)asc_36FF06C);
    std::wstring::operator+=((int)this + 28 * a3 + 1028);
    std::wstring::wstring(a2, v5);
    v6 = -1;
    std::wstring::~wstring(v5);
  }
  else
  {
    std::wstring::wstring((int)this + 28 * a3 + 1028);
  }
  return a2;
}


// address=[0x1493810]
// Decompiled from int __thiscall CGameType::SetPlayerClanShortcut(void *this, unsigned int a2, int a3)
void  CGameType::SetPlayerClanShortcut(int,std::wstring &) {
  
  int result; // eax

  if ( a2 >= 0xA
    && BBSupportDbgReport(2, "main\\GameType.cpp", 1106, "(_iPlayerIndex>=0) && (_iPlayerIndex<=PLAYER_MAX)") == 1 )
  {
    __debugbreak();
  }
  result = CGameType::IsClanGame(this);
  if ( (_BYTE)result )
    return std::wstring::operator=(a3);
  return result;
}


// address=[0x1493870]
// Decompiled from int __thiscall CGameType::GetNumberHumanPlayers(CGameType *this)
int const  CGameType::GetNumberHumanPlayers(void) {
  
  int v2; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  for ( i = 0; i < *((_DWORD *)this + 213); ++i )
  {
    if ( *((_DWORD *)this + i + 29) == 1 )
      ++v2;
  }
  return v2;
}


// address=[0x14bce00]
// Decompiled from char __thiscall CGameType::IsMapLoaded(CGameType *this)
bool const  CGameType::IsMapLoaded(void) {
  
  return *((_BYTE *)this + 1536);
}


// address=[0x14bce20]
// Decompiled from char __thiscall CGameType::IsWebGame(CGameType *this)
bool const  CGameType::IsWebGame(void) {
  
  return *((_BYTE *)this + 1539);
}


// address=[0x15c4a50]
// Decompiled from int __thiscall CGameType::GetMPSavegameID(CGameType *this)
int const  CGameType::GetMPSavegameID(void) {
  
  return *((_DWORD *)this + 385);
}


// address=[0x15c4ae0]
// Decompiled from void *__thiscall CGameType::GetPlayerClanShortcut(void *this, void *a2, unsigned int a3)
std::wstring  CGameType::GetPlayerClanShortcut(int) {
  
  _BYTE v5[28]; // [esp+Ch] [ebp-2Ch] BYREF
  int v6; // [esp+34h] [ebp-4h]

  std::wstring::wstring(v5);
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
  if ( (unsigned __int8)CGameType::IsClanGame(this) )
    std::wstring::wstring((int)this + 28 * a3 + 1280);
  else
    std::wstring::wstring(a2, v5);
  v6 = -1;
  std::wstring::~wstring(v5);
  return a2;
}


// address=[0x15c4dd0]
// Decompiled from CGameType *__thiscall CGameType::SetLadderGame(CGameType *this, bool a2)
void  CGameType::SetLadderGame(bool) {
  
  CGameType *result; // eax

  result = this;
  *((_BYTE *)this + 1545) = a2;
  return result;
}


// address=[0x15c4e90]
// Decompiled from CGameType *__thiscall CGameType::SetWebGame(CGameType *this, bool a2)
void  CGameType::SetWebGame(bool) {
  
  CGameType *result; // eax

  result = this;
  *((_BYTE *)this + 1539) = a2;
  return result;
}


// address=[0x14938c0]
// Decompiled from int __thiscall CGameType::PatchMaps(CGameType *this, bool a2)
void  CGameType::PatchMaps(bool) {
  
  _DWORD *v2; // eax
  int result; // eax
  int v4; // [esp-8h] [ebp-10h]
  int v5; // [esp-4h] [ebp-Ch]

  if ( !g_pMapCheck && BBSupportDbgReport(2, "main\\GameType.cpp", 1141, "g_pMapCheck != 0") == 1 )
    __debugbreak();
  v5 = *((_DWORD *)this + 214);
  v4 = *((_DWORD *)this + 154);
  v2 = std::wstring::c_str((CGameType *)((char *)this + 28));
  result = (*(int (__thiscall **)(void *, _DWORD *, int, int))(*(_DWORD *)g_pMapCheck + 4))(g_pMapCheck, v2, v4, v5);
  if ( result == 1 )
  {
    *((_BYTE *)this + 860) = 1;
    *((_BYTE *)this + 998) = 1;
    *((_BYTE *)this + 999) = 1;
    *((_BYTE *)this + 1007) = 1;
    result = 1;
    *((_BYTE *)this + 1008) = 1;
    if ( !a2 )
    {
      *((_DWORD *)this + 29) = 1;
      result = 4;
      *((_DWORD *)this + 30) = 1;
    }
  }
  else if ( result == 2 )
  {
    return (int)std::wstring::operator=((char *)this + 1056, (wchar_t *)L"Aeneas");
  }
  return result;
}


