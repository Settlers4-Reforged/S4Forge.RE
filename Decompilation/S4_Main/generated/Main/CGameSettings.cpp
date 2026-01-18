#include "CGameSettings.h"

// Definitions for class CGameSettings

// address=[0x13558a0]
// Decompiled from void CGameSettings::Save()
void __cdecl CGameSettings::Save(void) {
  
  _DWORD *v0; // eax
  _DWORD v1[5]; // [esp+0h] [ebp-44h] BYREF
  int v2[9]; // [esp+14h] [ebp-30h] BYREF
  int v3; // [esp+40h] [ebp-4h]

  v2[8] = (int)v1;
  v3 = 0;
  v1[4] = CGameSettings::GetConfigFilePath((int)v2, (wchar_t *)L"GameSettings", 1);
  LOBYTE(v3) = 1;
  v0 = std::wstring::c_str((_Cnd_internal_imp_t *)v2);
  ((void (__thiscall *)(CConfigManager *, const char *, _DWORD *))g_pCfgMgr->j_?SaveSection@CConfigManager@@UAE_NPBDPB_W@Z)(
    g_pCfgMgr,
    "GAMESETTINGS",
    v0);
  LOBYTE(v3) = 0;
  std::wstring::~wstring(v2);
}


// address=[0x1355980]
// Decompiled from int __cdecl CGameSettings::SetGfxFullscreenEnabled(bool a1)
void __cdecl CGameSettings::SetGfxFullscreenEnabled(bool a1) {
  
  CStaticConfigVarInt::operator=(CGameSettings::m_iFullscreenEnabled, a1);
  return CGameSettings::Save();
}


// address=[0x13559a0]
// Decompiled from int __cdecl CGameSettings::SetWindowsDimensions(int a1, int a2, int a3, int a4)
void __cdecl CGameSettings::SetWindowsDimensions(int a1, int a2, int a3, int a4) {
  
  CStaticConfigVarInt::operator=(CGameSettings::m_iWindowPosX, a1);
  CStaticConfigVarInt::operator=(CGameSettings::m_iWindowPosY, a2);
  CStaticConfigVarInt::operator=(CGameSettings::m_iWindowWidth, a3);
  CStaticConfigVarInt::operator=(CGameSettings::m_iWindowHeight, a4);
  return CGameSettings::Save();
}


// address=[0x135df70]
// Decompiled from int CGameSettings::GetGfxFullscreenEnabled()
int __cdecl CGameSettings::GetGfxFullscreenEnabled(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iFullscreenEnabled);
}


// address=[0x135df90]
// Decompiled from int CGameSettings::GetGfxHeight()
int __cdecl CGameSettings::GetGfxHeight(void) {
  
  return CStaticConfigVarInt::operator int(CGameSettings::m_iWindowHeight);
}


// address=[0x135dfb0]
// Decompiled from int CGameSettings::GetGfxWidth()
int __cdecl CGameSettings::GetGfxWidth(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iWindowWidth);
}


// address=[0x135dfd0]
// Decompiled from int CGameSettings::GetLanguage()
int __cdecl CGameSettings::GetLanguage(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iLanguage);
}


// address=[0x135e030]
// Decompiled from int CGameSettings::GetWindowsPosX()
int __cdecl CGameSettings::GetWindowsPosX(void) {
  
  return CStaticConfigVarInt::operator int(CGameSettings::m_iWindowPosX);
}


// address=[0x135e050]
// Decompiled from int CGameSettings::GetWindowsPosY()
int __cdecl CGameSettings::GetWindowsPosY(void) {
  
  return CStaticConfigVarInt::operator int(CGameSettings::m_iWindowPosY);
}


// address=[0x146ad50]
// Decompiled from int CGameSettings::GetUserMP3()
int __cdecl CGameSettings::GetUserMP3(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iUserMP3);
}


// address=[0x14878c0]
// Decompiled from void CGameSettings::LoadCommandLineValues()
void __cdecl CGameSettings::LoadCommandLineValues(void) {
  
  int v0; // eax
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  char v16; // [esp-1Ch] [ebp-7B8h] BYREF
  int v17; // [esp-18h] [ebp-7B4h]
  size_t v18; // [esp-4h] [ebp-7A0h]
  int v19; // [esp+4h] [ebp-798h]
  char *v20; // [esp+8h] [ebp-794h]
  void *v21; // [esp+Ch] [ebp-790h]
  void *v22; // [esp+10h] [ebp-78Ch]
  void *v23; // [esp+14h] [ebp-788h]
  void *v24; // [esp+18h] [ebp-784h]
  void *v25; // [esp+1Ch] [ebp-780h]
  void *v26; // [esp+20h] [ebp-77Ch]
  void *v27; // [esp+24h] [ebp-778h]
  void *v28; // [esp+28h] [ebp-774h]
  void *v29; // [esp+2Ch] [ebp-770h]
  void *v30; // [esp+30h] [ebp-76Ch]
  void *v31; // [esp+34h] [ebp-768h]
  void *v32; // [esp+38h] [ebp-764h]
  void *v33; // [esp+3Ch] [ebp-760h]
  void *v34; // [esp+40h] [ebp-75Ch]
  void *v35; // [esp+44h] [ebp-758h]
  void *v36; // [esp+48h] [ebp-754h]
  void *v37; // [esp+4Ch] [ebp-750h]
  void *v38; // [esp+50h] [ebp-74Ch]
  void *v39; // [esp+54h] [ebp-748h]
  void *v40; // [esp+58h] [ebp-744h]
  void *v41; // [esp+5Ch] [ebp-740h]
  void *v42; // [esp+60h] [ebp-73Ch]
  void *v43; // [esp+64h] [ebp-738h]
  void *v44; // [esp+68h] [ebp-734h]
  void *v45; // [esp+6Ch] [ebp-730h]
  void *v46; // [esp+70h] [ebp-72Ch]
  void *v47; // [esp+74h] [ebp-728h]
  void *v48; // [esp+78h] [ebp-724h]
  void *v49; // [esp+7Ch] [ebp-720h]
  void *v50; // [esp+80h] [ebp-71Ch]
  void *v51; // [esp+84h] [ebp-718h]
  size_t v52; // [esp+88h] [ebp-714h]
  void *v53; // [esp+8Ch] [ebp-710h]
  DWORD pcbBuffer; // [esp+90h] [ebp-70Ch] BYREF
  void *v55; // [esp+94h] [ebp-708h]
  void *v56; // [esp+98h] [ebp-704h]
  void *v57; // [esp+9Ch] [ebp-700h]
  void *v58; // [esp+A0h] [ebp-6FCh]
  void *v59; // [esp+A4h] [ebp-6F8h]
  void *v60; // [esp+A8h] [ebp-6F4h]
  void *v61; // [esp+ACh] [ebp-6F0h]
  void *v62; // [esp+B0h] [ebp-6ECh]
  void *v63; // [esp+B4h] [ebp-6E8h]
  void *v64; // [esp+B8h] [ebp-6E4h]
  void *v65; // [esp+BCh] [ebp-6E0h]
  void *v66; // [esp+C0h] [ebp-6DCh]
  unsigned int v67; // [esp+C4h] [ebp-6D8h]
  char v68; // [esp+CAh] [ebp-6D2h]
  char v69; // [esp+CBh] [ebp-6D1h]
  char v70; // [esp+CCh] [ebp-6D0h]
  char v71; // [esp+CDh] [ebp-6CFh]
  char v72; // [esp+CEh] [ebp-6CEh]
  char v73; // [esp+CFh] [ebp-6CDh]
  char v74; // [esp+D0h] [ebp-6CCh]
  char v75; // [esp+D1h] [ebp-6CBh]
  char v76; // [esp+D2h] [ebp-6CAh]
  char v77; // [esp+D3h] [ebp-6C9h]
  _BYTE v78[28]; // [esp+D4h] [ebp-6C8h] BYREF
  _BYTE v79[28]; // [esp+F0h] [ebp-6ACh] BYREF
  _BYTE v80[28]; // [esp+10Ch] [ebp-690h] BYREF
  _BYTE v81[28]; // [esp+128h] [ebp-674h] BYREF
  _BYTE v82[28]; // [esp+144h] [ebp-658h] BYREF
  _BYTE v83[28]; // [esp+160h] [ebp-63Ch] BYREF
  _BYTE v84[28]; // [esp+17Ch] [ebp-620h] BYREF
  _BYTE v85[28]; // [esp+198h] [ebp-604h] BYREF
  _BYTE v86[28]; // [esp+1B4h] [ebp-5E8h] BYREF
  _BYTE v87[28]; // [esp+1D0h] [ebp-5CCh] BYREF
  _BYTE v88[28]; // [esp+1ECh] [ebp-5B0h] BYREF
  _BYTE v89[28]; // [esp+208h] [ebp-594h] BYREF
  _BYTE v90[28]; // [esp+224h] [ebp-578h] BYREF
  _BYTE v91[28]; // [esp+240h] [ebp-55Ch] BYREF
  _BYTE v92[28]; // [esp+25Ch] [ebp-540h] BYREF
  _BYTE v93[28]; // [esp+278h] [ebp-524h] BYREF
  _BYTE v94[28]; // [esp+294h] [ebp-508h] BYREF
  _BYTE v95[28]; // [esp+2B0h] [ebp-4ECh] BYREF
  _BYTE v96[28]; // [esp+2CCh] [ebp-4D0h] BYREF
  _BYTE v97[28]; // [esp+2E8h] [ebp-4B4h] BYREF
  _BYTE v98[28]; // [esp+304h] [ebp-498h] BYREF
  _BYTE v99[28]; // [esp+320h] [ebp-47Ch] BYREF
  _BYTE v100[28]; // [esp+33Ch] [ebp-460h] BYREF
  _BYTE v101[28]; // [esp+358h] [ebp-444h] BYREF
  _BYTE v102[28]; // [esp+374h] [ebp-428h] BYREF
  _BYTE v103[28]; // [esp+390h] [ebp-40Ch] BYREF
  _BYTE v104[28]; // [esp+3ACh] [ebp-3F0h] BYREF
  _BYTE v105[28]; // [esp+3C8h] [ebp-3D4h] BYREF
  _BYTE v106[28]; // [esp+3E4h] [ebp-3B8h] BYREF
  _BYTE v107[28]; // [esp+400h] [ebp-39Ch] BYREF
  _BYTE v108[28]; // [esp+41Ch] [ebp-380h] BYREF
  _BYTE v109[28]; // [esp+438h] [ebp-364h] BYREF
  _BYTE v110[28]; // [esp+454h] [ebp-348h] BYREF
  _BYTE v111[28]; // [esp+470h] [ebp-32Ch] BYREF
  wchar_t Dest[256]; // [esp+48Ch] [ebp-310h] BYREF
  CHAR Buffer[256]; // [esp+68Ch] [ebp-110h] BYREF
  int v114; // [esp+798h] [ebp-4h]

  v0 = CStaticConfigVarInt::operator int(&CGameSettings::m_iWindowWidth);
  v1 = (*(int (__thiscall **)(int, const char *, const char *, int))(*(_DWORD *)g_pCfgMgr + 12))(
         g_pCfgMgr,
         "COMMANDLINE",
         "gfxwidth",
         v0);
  CStaticConfigVarInt::operator=(v1);
  v2 = CStaticConfigVarInt::operator int(&CGameSettings::m_iWindowHeight);
  v3 = (*(int (__thiscall **)(int, const char *, const char *, int))(*(_DWORD *)g_pCfgMgr + 12))(
         g_pCfgMgr,
         "COMMANDLINE",
         "gfxheight",
         v2);
  CStaticConfigVarInt::operator=(v3);
  v4 = CStaticConfigVarInt::operator int(&CGameSettings::m_iWindowPosX);
  v5 = (*(int (__thiscall **)(int, const char *, const char *, int))(*(_DWORD *)g_pCfgMgr + 12))(
         g_pCfgMgr,
         "COMMANDLINE",
         "WindowPosX",
         v4);
  CStaticConfigVarInt::operator=(v5);
  v6 = CStaticConfigVarInt::operator int(&CGameSettings::m_iWindowPosY);
  v7 = (*(int (__thiscall **)(int, const char *, const char *, int))(*(_DWORD *)g_pCfgMgr + 12))(
         g_pCfgMgr,
         "COMMANDLINE",
         "WindowPosY",
         v6);
  CStaticConfigVarInt::operator=(v7);
  v8 = CStaticConfigVarInt::operator int(&CGameSettings::m_iFullscreenEnabled);
  v9 = (*(int (__thiscall **)(int, const char *, const char *, int))(*(_DWORD *)g_pCfgMgr + 12))(
         g_pCfgMgr,
         "COMMANDLINE",
         "Fullscreen",
         v8);
  CStaticConfigVarInt::operator=(v9);
  v10 = CStaticConfigVarInt::operator int(&CGameSettings::m_iBorderScroll);
  v11 = (*(int (__thiscall **)(int, const char *, const char *, int))(*(_DWORD *)g_pCfgMgr + 12))(
          g_pCfgMgr,
          "COMMANDLINE",
          "borderscroll",
          v10);
  CStaticConfigVarInt::operator=(v11);
  v12 = CStaticConfigVarInt::operator int(&CGameSettings::m_iScrollStepValue);
  v13 = (*(int (__thiscall **)(int, const char *, const char *, int))(*(_DWORD *)g_pCfgMgr + 12))(
          g_pCfgMgr,
          "COMMANDLINE",
          "scrollstepvalue",
          v12);
  CStaticConfigVarInt::operator=(v13);
  std::string::string();
  v114 = 0;
  v66 = std::string::string(v99, "Player1");
  v56 = v66;
  LOBYTE(v114) = 1;
  v55 = (void *)(*(int (__thiscall **)(int, _BYTE *, const char *, const char *, void *))(*(_DWORD *)g_pCfgMgr + 20))(
                  g_pCfgMgr,
                  v100,
                  "GAMESETTINGS",
                  "PlayerName",
                  v66);
  std::string::operator=(v111, v55);
  std::string::~string(v100);
  LOBYTE(v114) = 0;
  std::string::~string(v99);
  if ( !std::string::compare("Player1") )
  {
    memset(Buffer, 0, sizeof(Buffer));
    pcbBuffer = 256;
    GetUserNameA(Buffer, &pcbBuffer);
    if ( j__strlen(Buffer) )
      std::string::operator=(v111, Buffer);
  }
  v53 = (void *)(*(int (__thiscall **)(int, _BYTE *, const char *, const char *, _BYTE *))(*(_DWORD *)g_pCfgMgr + 20))(
                  g_pCfgMgr,
                  v98,
                  "COMMANDLINE",
                  "playername",
                  v111);
  std::string::operator=(v111, v53);
  std::string::~string(v98);
  v14 = (const char *)std::string::c_str(v111);
  v18 = j__strlen(v14);
  v15 = (const char *)std::string::c_str(v111);
  v52 = j__mbstowcs(Dest, v15, v18);
  v67 = 2 * v52;
  if ( 2 * v52 >= 0x200 )
    j____report_rangecheckfailure();
  Dest[v67 / 2] = 0;
  v20 = &v16;
  v19 = std::wstring::wstring(&v16, Dest);
  CGameSettings::SetPlayerName(v16, v17);
  CGameSettings::LoadAINames();
  v51 = std::string::string(v96, (char *)&byte_36C2633);
  v50 = v51;
  LOBYTE(v114) = 2;
  v49 = (void *)(*(int (__thiscall **)(int, _BYTE *, const char *, const char *, void *))(*(_DWORD *)g_pCfgMgr + 20))(
                  g_pCfgMgr,
                  v97,
                  "WEB",
                  "HelpURLenglish",
                  v51);
  std::string::operator=(&CGameSettings::m_strHelpURLenglish, v49);
  std::string::~string(v97);
  LOBYTE(v114) = 0;
  std::string::~string(v96);
  v48 = std::string::string(v95, (char *)&byte_36C2641);
  v77 = std::operator==<char>(&CGameSettings::m_strHelpURLenglish, v48);
  std::string::~string(v95);
  if ( v77 )
    CTrace::Print("GameSettings.cpp: No 'HelpURLenglish' given! Check 'Web.cfg'!");
  v47 = std::string::string(v93, (char *)&byte_36C2642);
  v46 = v47;
  LOBYTE(v114) = 3;
  v45 = (void *)(*(int (__thiscall **)(int, _BYTE *, const char *, const char *, void *))(*(_DWORD *)g_pCfgMgr + 20))(
                  g_pCfgMgr,
                  v94,
                  "WEB",
                  "NormURLenglish",
                  v47);
  std::string::operator=(&CGameSettings::m_strNormURLenglish, v45);
  std::string::~string(v94);
  LOBYTE(v114) = 0;
  std::string::~string(v93);
  v44 = std::string::string(v92, (char *)&byte_36C2643);
  v76 = std::operator==<char>(&CGameSettings::m_strNormURLenglish, v44);
  std::string::~string(v92);
  if ( v76 )
    CTrace::Print("GameSettings.cpp: No 'm_strNormURLenglish' given! Check 'Web.cfg'!");
  v43 = std::string::string(v105, (char *)&byte_36C264A);
  v42 = v43;
  LOBYTE(v114) = 4;
  v41 = (void *)(*(int (__thiscall **)(int, _BYTE *, const char *, const char *, void *))(*(_DWORD *)g_pCfgMgr + 20))(
                  g_pCfgMgr,
                  v91,
                  "WEB",
                  "HelpURLgerman",
                  v43);
  std::string::operator=(&CGameSettings::m_strHelpURLgerman, v41);
  std::string::~string(v91);
  LOBYTE(v114) = 0;
  std::string::~string(v105);
  v40 = std::string::string(v89, (char *)&byte_36C264B);
  v75 = std::operator==<char>(&CGameSettings::m_strHelpURLgerman, v40);
  std::string::~string(v89);
  if ( v75 )
    CTrace::Print("GameSettings.cpp: No 'm_strHelpURLgerman' given! Check 'Web.cfg'!");
  v39 = std::string::string(v88, (char *)&byte_36C2672);
  v38 = v39;
  LOBYTE(v114) = 5;
  v37 = (void *)(*(int (__thiscall **)(int, _BYTE *, const char *, const char *, void *))(*(_DWORD *)g_pCfgMgr + 20))(
                  g_pCfgMgr,
                  v101,
                  "WEB",
                  "NormURLgerman",
                  v39);
  std::string::operator=(&CGameSettings::m_strNormURLgerman, v37);
  std::string::~string(v101);
  LOBYTE(v114) = 0;
  std::string::~string(v88);
  v36 = std::string::string(v87, (char *)&byte_36C2673);
  v74 = std::operator==<char>(&CGameSettings::m_strNormURLgerman, v36);
  std::string::~string(v87);
  if ( v74 )
    CTrace::Print("GameSettings.cpp: No 'm_strNormURLgerman' given! Check 'Web.cfg'!");
  v35 = std::string::string(v85, (char *)&byte_36C267D);
  v34 = v35;
  LOBYTE(v114) = 6;
  v33 = (void *)(*(int (__thiscall **)(int, _BYTE *, const char *, const char *, void *))(*(_DWORD *)g_pCfgMgr + 20))(
                  g_pCfgMgr,
                  v86,
                  "MISCDATA1",
                  "ManualURL_DE",
                  v35);
  std::string::operator=(&CGameSettings::m_strManualURL_DE, v33);
  std::string::~string(v86);
  LOBYTE(v114) = 0;
  std::string::~string(v85);
  v31 = std::string::string(v84, (char *)&byte_36C267E);
  v73 = std::operator==<char>(&CGameSettings::m_strManualURL_DE, v31);
  std::string::~string(v84);
  if ( v73 )
    CTrace::Print("GameSettings.cpp: No 'm_strManualURL_DE' given! Check 'Web.cfg'!");
  v30 = std::string::string(v82, (char *)&byte_36C267F);
  v29 = v30;
  LOBYTE(v114) = 7;
  v28 = (void *)(*(int (__thiscall **)(int, _BYTE *, const char *, const char *, void *))(*(_DWORD *)g_pCfgMgr + 20))(
                  g_pCfgMgr,
                  v83,
                  "MISCDATA1",
                  "ManualURL_FR",
                  v30);
  std::string::operator=(&CGameSettings::m_strManualURL_FR, v28);
  std::string::~string(v83);
  LOBYTE(v114) = 0;
  std::string::~string(v82);
  v27 = std::string::string(v81, (char *)&byte_36C268A);
  v68 = std::operator==<char>(&CGameSettings::m_strManualURL_FR, v27);
  std::string::~string(v81);
  if ( v68 )
    CTrace::Print("GameSettings.cpp: No 'm_strManualURL_FR' given! Check 'Web.cfg'!");
  v26 = std::string::string(v79, (char *)&byte_36C268B);
  v25 = v26;
  LOBYTE(v114) = 8;
  v24 = (void *)(*(int (__thiscall **)(int, _BYTE *, const char *, const char *, void *))(*(_DWORD *)g_pCfgMgr + 20))(
                  g_pCfgMgr,
                  v80,
                  "MISCDATA1",
                  "ManualURL_EN",
                  v26);
  std::string::operator=(&CGameSettings::m_strManualURL_EN, v24);
  std::string::~string(v80);
  LOBYTE(v114) = 0;
  std::string::~string(v79);
  v23 = std::string::string(v102, (char *)&byte_36C269A);
  v72 = std::operator==<char>(&CGameSettings::m_strManualURL_EN, v23);
  std::string::~string(v102);
  if ( v72 )
    CTrace::Print("GameSettings.cpp: No 'm_strManualURL_EN' given! Check 'Web.cfg'!");
  v22 = std::string::string(v110, (char *)&byte_36C269B);
  v21 = v22;
  LOBYTE(v114) = 9;
  v32 = (void *)(*(int (__thiscall **)(int, _BYTE *, const char *, const char *, void *))(*(_DWORD *)g_pCfgMgr + 20))(
                  g_pCfgMgr,
                  v78,
                  "MISCDATA1",
                  "TipsURL_DE",
                  v22);
  std::string::operator=(&CGameSettings::m_strTipsURL_DE, v32);
  std::string::~string(v78);
  LOBYTE(v114) = 0;
  std::string::~string(v110);
  v65 = std::string::string(v109, (char *)&byte_36C26CE);
  v71 = std::operator==<char>(&CGameSettings::m_strTipsURL_DE, v65);
  std::string::~string(v109);
  if ( v71 )
    CTrace::Print("GameSettings.cpp: No 'TipsURL_DE' given! Check 'Web.cfg'!");
  v64 = std::string::string(v107, (char *)&byte_36C26CF);
  v63 = v64;
  LOBYTE(v114) = 10;
  v62 = (void *)(*(int (__thiscall **)(int, _BYTE *, const char *, const char *, void *))(*(_DWORD *)g_pCfgMgr + 20))(
                  g_pCfgMgr,
                  v108,
                  "MISCDATA1",
                  "TipsURL_FR",
                  v64);
  std::string::operator=(&CGameSettings::m_strTipsURL_FR, v62);
  std::string::~string(v108);
  LOBYTE(v114) = 0;
  std::string::~string(v107);
  v61 = std::string::string(v90, (char *)&byte_36C26E6);
  v70 = std::operator==<char>(&CGameSettings::m_strTipsURL_FR, v61);
  std::string::~string(v90);
  if ( v70 )
    CTrace::Print("GameSettings.cpp: No 'TipsURL_FR' given! Check 'Web.cfg'!");
  v60 = std::string::string(v104, (char *)&byte_36C26E7);
  v59 = v60;
  LOBYTE(v114) = 11;
  v58 = (void *)(*(int (__thiscall **)(int, _BYTE *, const char *, const char *, void *))(*(_DWORD *)g_pCfgMgr + 20))(
                  g_pCfgMgr,
                  v106,
                  "MISCDATA1",
                  "TipsURL_EN",
                  v60);
  std::string::operator=(&CGameSettings::m_strTipsURL_EN, v58);
  std::string::~string(v106);
  LOBYTE(v114) = 0;
  std::string::~string(v104);
  v57 = std::string::string(v103, (char *)&byte_36C26EF);
  v69 = std::operator==<char>(&CGameSettings::m_strTipsURL_EN, v57);
  std::string::~string(v103);
  if ( v69 )
    CTrace::Print("GameSettings.cpp: No 'TipsURL_EN' given! Check 'Web.cfg'!");
  CGameSettings::Save();
  v114 = -1;
  std::string::~string(v111);
}


// address=[0x14884c0]
// Decompiled from void CGameSettings::Validate()
void __cdecl CGameSettings::Validate(void) {
  
  ;
}


// address=[0x14884d0]
// Decompiled from BOOL CGameSettings::DetermineHighestResolution()
void __cdecl CGameSettings::DetermineHighestResolution(void) {
  
  BOOL result; // eax

  if ( !g_pGfxEngine && BBSupportDbgReport(2, "main\\GameSettings.cpp", 227, "g_pGfxEngine") == 1 )
    __debugbreak();
  result = 0;
  for ( CGameSettings::m_iHighestPossibleResolution = 1;
        CGameSettings::m_iHighestPossibleResolution <= 3;
        ++CGameSettings::m_iHighestPossibleResolution )
  {
    result = IGfxEngine::IsResolutionPossible((IGfxEngine *)g_pGfxEngine, CGameSettings::m_iHighestPossibleResolution);
    if ( !result )
    {
      --CGameSettings::m_iHighestPossibleResolution;
      return result;
    }
  }
  --CGameSettings::m_iHighestPossibleResolution;
  return result;
}


// address=[0x1488560]
// Decompiled from int __cdecl CGameSettings::GetUserConfigDirectory(int a1)
std::wstring __cdecl CGameSettings::GetUserConfigDirectory(void a1) {
  
  void *UserDirectoryPath; // [esp+4h] [ebp-38h]
  _BYTE v3[28]; // [esp+10h] [ebp-2Ch] BYREF
  int v4; // [esp+38h] [ebp-4h]

  UserDirectoryPath = FilePaths::GetUserDirectoryPath(v3);
  v4 = 0;
  std::operator+<wchar_t>(a1, (int)UserDirectoryPath, (wchar_t *)L"Config\\");
  v4 = -1;
  std::wstring::~wstring(v3);
  return a1;
}


// address=[0x1488600]
// Decompiled from int __cdecl CGameSettings::GetConfigFilePath(int a1, wchar_t *String, char a3)
std::wstring __cdecl CGameSettings::GetConfigFilePath(wchar_t const * a1, bool String) {
  
  int v4; // [esp+4h] [ebp-A4h]
  int v5; // [esp+Ch] [ebp-9Ch]
  int v6; // [esp+14h] [ebp-94h]
  int UserConfigDirectory; // [esp+1Ch] [ebp-8Ch]
  _BYTE v8[28]; // [esp+28h] [ebp-80h] BYREF
  int v9[7]; // [esp+44h] [ebp-64h] BYREF
  _BYTE v10[28]; // [esp+60h] [ebp-48h] BYREF
  int v11[7]; // [esp+7Ch] [ebp-2Ch] BYREF
  int v12; // [esp+A4h] [ebp-4h]

  if ( a3
    && (*(unsigned __int8 (__thiscall **)(void *, wchar_t *))(*(_DWORD *)g_pInstallationInfo + 20))(
         g_pInstallationInfo,
         String) )
  {
    UserConfigDirectory = CGameSettings::GetUserConfigDirectory((int)v10);
    v12 = 0;
    v6 = std::operator+<wchar_t>((int)v11, UserConfigDirectory, String);
    LOBYTE(v12) = 1;
    std::operator+<wchar_t>(a1, v6, (wchar_t *)L".cfg");
    LOBYTE(v12) = 0;
    std::wstring::~wstring(v11);
    v12 = -1;
    std::wstring::~wstring(v10);
    return a1;
  }
  else
  {
    v5 = std::wstring::wstring(v8, (wchar_t *)L"Config\\");
    v12 = 2;
    v4 = std::operator+<wchar_t>((int)v9, v5, String);
    LOBYTE(v12) = 3;
    std::operator+<wchar_t>(a1, v4, (wchar_t *)L".cfg");
    LOBYTE(v12) = 2;
    std::wstring::~wstring(v9);
    v12 = -1;
    std::wstring::~wstring(v8);
    return a1;
  }
}


// address=[0x14887b0]
// Decompiled from void __cdecl CGameSettings::SetPlayerName(char a1)
void __cdecl CGameSettings::SetPlayerName(std::wstring a1) {
  
  const wchar_t *v1; // eax
  const wchar_t *v2; // eax
  size_t v3; // [esp-4h] [ebp-148h]
  void *v4; // [esp+4h] [ebp-140h]
  int v5; // [esp+10h] [ebp-134h]
  size_t v6; // [esp+14h] [ebp-130h]
  char v7[28]; // [esp+18h] [ebp-12Ch] BYREF
  char Dest[256]; // [esp+34h] [ebp-110h] BYREF
  int v9; // [esp+140h] [ebp-4h]

  v9 = 0;
  std::wstring::operator=((int)&a1);
  v1 = (const wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)&a1);
  v3 = j__wcslen(v1);
  v2 = (const wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)&a1);
  v6 = j__wcstombs(Dest, v2, v3);
  if ( v6 >= 0x100 )
    j____report_rangecheckfailure();
  Dest[v6] = 0;
  v5 = ((int (__thiscall *)(CConfigManager *, const char *))g_pCfgMgr->GetConfigVar)(g_pCfgMgr, "GAMESETTINGS");
  v4 = std::string::string(v7, Dest);
  LOBYTE(v9) = 1;
  (*(void (__thiscall **)(int, void *))(*(_DWORD *)v5 + 20))(v5, v4);
  LOBYTE(v9) = 0;
  std::string::~string(v7);
  CGameSettings::Save();
  v9 = -1;
  std::wstring::~wstring(&a1);
}


// address=[0x14888f0]
// Decompiled from int __cdecl CGameSettings::GetManualURL(int a1)
std::string __cdecl CGameSettings::GetManualURL(void a1) {
  
  int Language; // [esp+0h] [ebp-8h]

  Language = CGameSettings::GetLanguage();
  if ( Language == 1 )
  {
    std::string::string(&CGameSettings::m_strManualURL_DE);
    return a1;
  }
  else
  {
    if ( Language == 2 )
      std::string::string(&CGameSettings::m_strManualURL_FR);
    else
      std::string::string(&CGameSettings::m_strManualURL_EN);
    return a1;
  }
}


// address=[0x1488970]
// Decompiled from int __cdecl CGameSettings::GetTipsURL(int a1)
std::string __cdecl CGameSettings::GetTipsURL(void a1) {
  
  int Language; // [esp+0h] [ebp-8h]

  Language = CGameSettings::GetLanguage();
  if ( Language == 1 )
  {
    std::string::string(&CGameSettings::m_strTipsURL_DE);
    return a1;
  }
  else
  {
    if ( Language == 2 )
      std::string::string(&CGameSettings::m_strTipsURL_FR);
    else
      std::string::string(&CGameSettings::m_strTipsURL_EN);
    return a1;
  }
}


// address=[0x14889f0]
// Decompiled from int __cdecl CGameSettings::GetCampaignStatus(int a1)
int __cdecl CGameSettings::GetCampaignStatus(int a1) {
  
  unsigned int v2; // eax
  _DWORD v3[7]; // [esp+1Ch] [ebp-24h] BYREF
  unsigned int i; // [esp+38h] [ebp-8h]
  char v5; // [esp+3Fh] [ebp-1h]
  int v6; // [esp+48h] [ebp+8h]

  if ( a1 < 5 || a1 >= 11 )
  {
    if ( a1 < 11 || a1 >= 17 )
    {
      if ( a1 < 17 || a1 >= 21 )
      {
        if ( a1 < 21 || a1 >= 25 )
        {
          if ( (!a1 || a1 >= 5)
            && BBSupportDbgReport(
                 2,
                 "main\\GameSettings.cpp",
                 345,
                 "_iCampaignType && _iCampaignType < CAMPAIGN_MAX_MAIN") == 1 )
          {
            __debugbreak();
          }
          v6 = a1 - 1;
          CGameSettings::m_uiCampaignSave[0] = ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValue)(
                                                 g_pCfgMgr,
                                                 "MISCDATA2",
                                                 "Data01",
                                                 0);
          CGameSettings::m_uiCampaignSave[1] = ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValue)(
                                                 g_pCfgMgr,
                                                 "MISCDATA2",
                                                 "Data02",
                                                 0);
          CGameSettings::m_uiCampaignSave[2] = ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValue)(
                                                 g_pCfgMgr,
                                                 "MISCDATA2",
                                                 "Data03",
                                                 0);
          CGameSettings::m_uiCampaignSave[3] = ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValue)(
                                                 g_pCfgMgr,
                                                 "MISCDATA2",
                                                 "Data04",
                                                 0);
          v5 = 0;
          for ( i = 0; i < 0x10; ++i )
            v5 |= *((_BYTE *)CGameSettings::m_uiCampaignSave + i);
          if ( v5 )
          {
            CGameSettings::Cryption((unsigned __int8 *)CGameSettings::m_uiCampaignSave, 0x10u);
            v3[0] = 0;
            v3[6] = v3;
            LOBYTE(v3[0]) = HIBYTE(CGameSettings::m_uiCampaignSave[0]);
            BYTE1(v3[0]) = BYTE2(CGameSettings::m_uiCampaignSave[1]);
            BYTE2(v3[0]) = BYTE1(CGameSettings::m_uiCampaignSave[2]);
            HIBYTE(v3[0]) = BYTE2(CGameSettings::m_uiCampaignSave[3]);
            v3[4] = 3;
            HIBYTE(CGameSettings::m_uiCampaignSave[0]) = 0;
            v3[3] = 6;
            BYTE2(CGameSettings::m_uiCampaignSave[1]) = 0;
            v3[2] = 9;
            BYTE1(CGameSettings::m_uiCampaignSave[2]) = 0;
            v3[1] = 14;
            BYTE2(CGameSettings::m_uiCampaignSave[3]) = 0;
            v2 = CGameSettings::Crc((unsigned __int8 *)CGameSettings::m_uiCampaignSave, 0x10u);
            if ( v3[0] == v2 )
            {
              return LOBYTE(CGameSettings::m_uiCampaignSave[v6]);
            }
            else
            {
              CTrace::Print("CGameSettings.cpp: CRC of campaign save invalid !!");
              return 0;
            }
          }
          else
          {
            return 0;
          }
        }
        else
        {
          return 15;
        }
      }
      else
      {
        CGameSettings::m_uiMD2CampaignSave = ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValue)(
                                               g_pCfgMgr,
                                               "MISCDATA2",
                                               "Data07",
                                               0);
        return ((unsigned int)CGameSettings::m_uiMD2CampaignSave >> (4 * a1 - 68)) & 0xF;
      }
    }
    else
    {
      CGameSettings::m_uiAOCampaignSave = ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValue)(
                                            g_pCfgMgr,
                                            "MISCDATA2",
                                            "Data06",
                                            0);
      return ((unsigned int)CGameSettings::m_uiAOCampaignSave >> (4 * a1 - 44)) & 0xF;
    }
  }
  else
  {
    CGameSettings::m_uiMDCampaignSave = ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValue)(
                                          g_pCfgMgr,
                                          "MISCDATA2",
                                          "Data05",
                                          0);
    if ( a1 == 10 )
      return CGameSettings::m_uiMDCampaignSave < 0;
    else
      return ((unsigned int)CGameSettings::m_uiMDCampaignSave >> (4 * a1 - 20)) & 0xF;
  }
}


// address=[0x1488dc0]
// Decompiled from void __cdecl CGameSettings::SetCampaignStatus(int a1, int a2)
void __cdecl CGameSettings::SetCampaignStatus(int a1, int a2) {
  
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  _Cnd_internal_imp_t *v7; // [esp+Ch] [ebp-108h]
  _Cnd_internal_imp_t *ConfigFilePath; // [esp+14h] [ebp-100h]
  _DWORD v9[3]; // [esp+1Ch] [ebp-F8h] BYREF
  _Cnd_internal_imp_t *v10; // [esp+28h] [ebp-ECh]
  int v11; // [esp+2Ch] [ebp-E8h]
  _Cnd_internal_imp_t *v12; // [esp+30h] [ebp-E4h]
  _Cnd_internal_imp_t *v13; // [esp+34h] [ebp-E0h]
  int v14; // [esp+38h] [ebp-DCh]
  _Cnd_internal_imp_t *v15; // [esp+3Ch] [ebp-D8h]
  int v16; // [esp+40h] [ebp-D4h]
  int v17; // [esp+44h] [ebp-D0h]
  int v18; // [esp+48h] [ebp-CCh]
  int v19; // [esp+4Ch] [ebp-C8h]
  int v20; // [esp+50h] [ebp-C4h]
  int v21; // [esp+54h] [ebp-C0h]
  int v22; // [esp+58h] [ebp-BCh]
  int v23; // [esp+5Ch] [ebp-B8h]
  int v24; // [esp+60h] [ebp-B4h]
  int v25; // [esp+64h] [ebp-B0h]
  int v26; // [esp+68h] [ebp-ACh]
  int v27; // [esp+6Ch] [ebp-A8h]
  int CampaignStatus; // [esp+70h] [ebp-A4h]
  _BYTE *v29; // [esp+74h] [ebp-A0h]
  int v30[7]; // [esp+78h] [ebp-9Ch] BYREF
  int v31[7]; // [esp+94h] [ebp-80h] BYREF
  int v32[7]; // [esp+B0h] [ebp-64h] BYREF
  int v33[7]; // [esp+CCh] [ebp-48h] BYREF
  int v34[7]; // [esp+E8h] [ebp-2Ch] BYREF
  int v35; // [esp+110h] [ebp-4h]

  CampaignStatus = CGameSettings::GetCampaignStatus(a1);
  if ( CampaignStatus > a2 )
    CTrace::Print(
      "CGameSettings.cpp: Campaign state was already higher... Old %d, New %d, Campaign %d ",
      CampaignStatus,
      a2,
      a1);
  if ( a1 < 5 || a1 >= 11 )
  {
    if ( a1 < 11 || a1 >= 17 )
    {
      if ( a1 < 17 || a1 >= 21 )
      {
        if ( (!a1 || a1 >= 5)
          && BBSupportDbgReport(
               2,
               "main\\GameSettings.cpp",
               487,
               "_iCampaignType && _iCampaignType < CAMPAIGN_MAX_MAIN") == 1 )
        {
          __debugbreak();
        }
        v9[1] = 3;
        LOBYTE(CGameSettings::m_uiCampaignSave[a1 - 1]) = a2;
        v9[0] = CGameSettings::Crc((unsigned __int8 *)CGameSettings::m_uiCampaignSave, 0x10u);
        v23 = 3;
        HIBYTE(CGameSettings::m_uiCampaignSave[0]) = 0;
        v22 = 6;
        BYTE2(CGameSettings::m_uiCampaignSave[1]) = 0;
        v21 = 9;
        BYTE1(CGameSettings::m_uiCampaignSave[2]) = 0;
        v20 = 14;
        BYTE2(CGameSettings::m_uiCampaignSave[3]) = 0;
        v29 = v9;
        HIBYTE(CGameSettings::m_uiCampaignSave[0]) = v9[0];
        BYTE2(CGameSettings::m_uiCampaignSave[1]) = v29[1];
        BYTE1(CGameSettings::m_uiCampaignSave[2]) = v29[2];
        BYTE2(CGameSettings::m_uiCampaignSave[3]) = v29[3];
        CGameSettings::Cryption((unsigned __int8 *)CGameSettings::m_uiCampaignSave, 0x10u);
        v19 = g_pCfgMgr->GetConfigVar(g_pCfgMgr, "MISCDATA2", "Data01");
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v19 + 32))(v19, CGameSettings::m_uiCampaignSave[0]);
        v18 = g_pCfgMgr->GetConfigVar(g_pCfgMgr, "MISCDATA2", "Data02");
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v18 + 32))(v18, CGameSettings::m_uiCampaignSave[1]);
        v17 = g_pCfgMgr->GetConfigVar(g_pCfgMgr, "MISCDATA2", "Data03");
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v17 + 32))(v17, CGameSettings::m_uiCampaignSave[2]);
        v16 = g_pCfgMgr->GetConfigVar(g_pCfgMgr, "MISCDATA2", "Data04");
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v16 + 32))(v16, CGameSettings::m_uiCampaignSave[3]);
        ConfigFilePath = (_Cnd_internal_imp_t *)CGameSettings::GetConfigFilePath((int)v34, (wchar_t *)L"MiscData2", 1);
        v35 = 4;
        v6 = std::wstring::c_str(ConfigFilePath);
        ((void (__thiscall *)(CConfigManager *, const char *, _DWORD *))g_pCfgMgr->j_?SaveSection@CConfigManager@@UAE_NPBDPB_W@Z)(
          g_pCfgMgr,
          "MISCDATA2",
          v6);
        v35 = -1;
        std::wstring::~wstring(v34);
      }
      else
      {
        v11 = 15 << (4 * a1 - 68);
        CGameSettings::m_uiMD2CampaignSave &= ~v11;
        CGameSettings::m_uiMD2CampaignSave |= a2 << (4 * a1 - 68);
        v24 = g_pCfgMgr->GetConfigVar(g_pCfgMgr, "MISCDATA2", "Data07");
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v24 + 32))(v24, CGameSettings::m_uiMD2CampaignSave);
        v10 = (_Cnd_internal_imp_t *)CGameSettings::GetConfigFilePath((int)v33, (wchar_t *)L"MiscData2", 1);
        v9[2] = v10;
        v35 = 3;
        v5 = std::wstring::c_str(v10);
        ((void (__thiscall *)(CConfigManager *, const char *, _DWORD *))g_pCfgMgr->j_?SaveSection@CConfigManager@@UAE_NPBDPB_W@Z)(
          g_pCfgMgr,
          "MISCDATA2",
          v5);
        v35 = -1;
        std::wstring::~wstring(v33);
      }
    }
    else
    {
      v14 = 15 << (4 * a1 - 44);
      CGameSettings::m_uiAOCampaignSave &= ~v14;
      CGameSettings::m_uiAOCampaignSave |= a2 << (4 * a1 - 44);
      v25 = g_pCfgMgr->GetConfigVar(g_pCfgMgr, "MISCDATA2", "Data06");
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v25 + 32))(v25, CGameSettings::m_uiAOCampaignSave);
      v13 = (_Cnd_internal_imp_t *)CGameSettings::GetConfigFilePath((int)v32, (wchar_t *)L"MiscData2", 1);
      v12 = v13;
      v35 = 2;
      v4 = std::wstring::c_str(v13);
      ((void (__thiscall *)(CConfigManager *, const char *, _DWORD *))g_pCfgMgr->j_?SaveSection@CConfigManager@@UAE_NPBDPB_W@Z)(
        g_pCfgMgr,
        "MISCDATA2",
        v4);
      v35 = -1;
      std::wstring::~wstring(v32);
    }
  }
  else if ( a1 == 10 )
  {
    if ( a2 )
    {
      CGameSettings::m_uiMDCampaignSave |= 0x80000000;
      v27 = g_pCfgMgr->GetConfigVar(g_pCfgMgr, "MISCDATA2", "Data05");
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v27 + 32))(v27, CGameSettings::m_uiMDCampaignSave);
      v7 = (_Cnd_internal_imp_t *)CGameSettings::GetConfigFilePath((int)v30, (wchar_t *)L"MiscData2", 1);
      v35 = 0;
      v2 = std::wstring::c_str(v7);
      ((void (__thiscall *)(CConfigManager *, const char *, _DWORD *))g_pCfgMgr->j_?SaveSection@CConfigManager@@UAE_NPBDPB_W@Z)(
        g_pCfgMgr,
        "MISCDATA2",
        v2);
      v35 = -1;
      std::wstring::~wstring(v30);
    }
  }
  else
  {
    CGameSettings::m_uiMDCampaignSave &= ~(15 << (4 * a1 - 20));
    CGameSettings::m_uiMDCampaignSave |= a2 << (4 * a1 - 20);
    v26 = g_pCfgMgr->GetConfigVar(g_pCfgMgr, "MISCDATA2", "Data05");
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v26 + 32))(v26, CGameSettings::m_uiMDCampaignSave);
    v15 = (_Cnd_internal_imp_t *)CGameSettings::GetConfigFilePath((int)v31, (wchar_t *)L"MiscData2", 1);
    v35 = 1;
    v3 = std::wstring::c_str(v15);
    ((void (__thiscall *)(CConfigManager *, const char *, _DWORD *))g_pCfgMgr->j_?SaveSection@CConfigManager@@UAE_NPBDPB_W@Z)(
      g_pCfgMgr,
      "MISCDATA2",
      v3);
    v35 = -1;
    std::wstring::~wstring(v31);
    if ( (CGameSettings::m_uiMDCampaignSave & 0x7FFFFFFF) == 0x33555 )
      CGameSettings::SetCampaignStatus(10, 1);
  }
}


// address=[0x1489530]
// Decompiled from void __cdecl CGameSettings::Cryption(unsigned __int8 *a1, unsigned int a2)
void __cdecl CGameSettings::Cryption(unsigned char *,unsigned long) {
  
  unsigned int i; // [esp+4h] [ebp-7Ch]
  _BYTE v3[76]; // [esp+8h] [ebp-78h] BYREF
  _BYTE v4[28]; // [esp+54h] [ebp-2Ch] BYREF
  int v5; // [esp+7Ch] [ebp-4h]

  Cryptor::Cryptor((Cryptor *)v3);
  v5 = 0;
  std::string::string(v4, "19283746574839201324");
  LOBYTE(v5) = 1;
  Cryptor::Set_Key(v4);
  for ( i = 0; i < a2; ++i )
    Cryptor::Transform_Char((Cryptor *)v3, &a1[i]);
  LOBYTE(v5) = 0;
  std::string::~string(v4);
  v5 = -1;
  Cryptor::~Cryptor((Cryptor *)v3);
}


// address=[0x14895f0]
// Decompiled from unsigned int __cdecl CGameSettings::Crc(unsigned __int8 *a1, unsigned int a2)
unsigned int __cdecl CGameSettings::Crc(unsigned char *,unsigned long) {
  
  unsigned int NormalCRC; // [esp+0h] [ebp-8h]
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::CRCGenerator<16,32773,0,0,1,1>(v4);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process(a1, a2);
  NormalCRC = cdm_crc::CRCGenerator<16,32773,0,0,1,1>::GetNormalCRC(v4);
  return NormalCRC >> (32 - cdm_crc::CRCGenerator<16,32773,0,0,1,1>::GetWidth(v4));
}


// address=[0x148abd0]
// Decompiled from int CGameSettings::GetWebHelpMode()
int __cdecl CGameSettings::GetWebHelpMode(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iWebHelpMode);
}


// address=[0x148abf0]
// Decompiled from int __cdecl CGameSettings::SetWebHelpMode(int a1)
void __cdecl CGameSettings::SetWebHelpMode(int a1) {
  
  CStaticConfigVarInt::operator=(CGameSettings::m_iWebHelpMode, a1);
  return CGameSettings::Save();
}


// address=[0x148fd60]
// Decompiled from bool CGameSettings::GetGfxFiltering()
bool __cdecl CGameSettings::GetGfxFiltering(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iFiltering) == 1;
}


// address=[0x148fd90]
// Decompiled from int CGameSettings::GetGfxForceBlit()
int __cdecl CGameSettings::GetGfxForceBlit(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iForceBlit);
}


// address=[0x148fdb0]
// Decompiled from char CGameSettings::GetGfxLandscapeHardware()
bool __cdecl CGameSettings::GetGfxLandscapeHardware(void) {
  
  return 1;
}


// address=[0x148fdc0]
// Decompiled from char CGameSettings::GetGfxObjectHardware()
bool __cdecl CGameSettings::GetGfxObjectHardware(void) {
  
  return 1;
}


// address=[0x148fdd0]
// Decompiled from int CGameSettings::GetGfxPureSoftwareMode()
int __cdecl CGameSettings::GetGfxPureSoftwareMode(void) {
  
  return 0;
}


// address=[0x148fde0]
// Decompiled from int CGameSettings::GetGfxTextureQuality()
int __cdecl CGameSettings::GetGfxTextureQuality(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iTextureQuality);
}


// address=[0x148fe00]
// Decompiled from char CGameSettings::GetShowVideos()
bool __cdecl CGameSettings::GetShowVideos(void) {
  
  return 0;
}


// address=[0x148ff20]
// Decompiled from BOOL __cdecl CGameSettings::SetAlwaysHardwareImpossible(bool a1)
void __cdecl CGameSettings::SetAlwaysHardwareImpossible(bool a1) {
  
  BOOL result; // eax

  result = a1;
  CGameSettings::m_iHardwareAlwaysImpossible = a1;
  return result;
}


// address=[0x148ff40]
// Decompiled from BOOL __cdecl CGameSettings::SetAlwaysHardwareObjectImpossible(bool a1)
void __cdecl CGameSettings::SetAlwaysHardwareObjectImpossible(bool a1) {
  
  BOOL result; // eax

  result = a1;
  CGameSettings::m_iHardwareObjectAlwaysImpossible = a1;
  return result;
}


// address=[0x148ff60]
// Decompiled from int __cdecl CGameSettings::SetGfxFiltering(bool a1)
void __cdecl CGameSettings::SetGfxFiltering(bool a1) {
  
  CStaticConfigVarInt::operator=(CGameSettings::m_iFiltering, a1);
  return CGameSettings::Save();
}


// address=[0x148ffa0]
// Decompiled from int __cdecl CGameSettings::SetGfxTextureQuality(int a1)
void __cdecl CGameSettings::SetGfxTextureQuality(int a1) {
  
  CStaticConfigVarInt::operator=(CGameSettings::m_iTextureQuality, a1);
  return CGameSettings::Save();
}


// address=[0x1494480]
// Decompiled from int __cdecl CGameSettings::GetAIName(int a1, int a2)
std::wstring __cdecl CGameSettings::GetAIName(int a1) {
  
  std::wstring::wstring((int)&CGameSettings::m_wstrAINames + 28 * a2);
  return a1;
}


// address=[0x149f540]
// Decompiled from int __cdecl CGameSettings::GetPlayerName(int a1)
std::wstring __cdecl CGameSettings::GetPlayerName(void a1) {
  
  std::wstring::wstring((int)&CGameSettings::m_wstrPlayerName);
  return a1;
}


// address=[0x14a0ab0]
// Decompiled from int CGameSettings::GetAIDifficulty()
int __cdecl CGameSettings::GetAIDifficulty(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iAIDifficulty);
}


// address=[0x14a0ad0]
// Decompiled from int __cdecl CGameSettings::SetAIDifficulty(int a1)
void __cdecl CGameSettings::SetAIDifficulty(int a1) {
  
  CStaticConfigVarInt::operator=(CGameSettings::m_iAIDifficulty, a1);
  return CGameSettings::Save();
}


// address=[0x14aaa90]
// Decompiled from bool CGameSettings::GetAlwaysUrgentMsg()
bool __cdecl CGameSettings::GetAlwaysUrgentMsg(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iAlwaysUrgentMsg) != 0;
}


// address=[0x14aaac0]
// Decompiled from int CGameSettings::GetAutosaveInterval()
int __cdecl CGameSettings::GetAutosaveInterval(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iAutoSaveInterval);
}


// address=[0x14aaae0]
// Decompiled from bool CGameSettings::GetBorderScrollEnabled()
bool __cdecl CGameSettings::GetBorderScrollEnabled(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iBorderScroll) != 0;
}


// address=[0x14aab80]
// Decompiled from int CGameSettings::GetChatMessageFilter()
int __cdecl CGameSettings::GetChatMessageFilter(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iChatMessageFilter);
}


// address=[0x14aabf0]
// Decompiled from int CGameSettings::GetExtendedTooltip()
int __cdecl CGameSettings::GetExtendedTooltip(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iExtendedTooltip);
}


// address=[0x14aac10]
// Decompiled from int CGameSettings::GetGfxHighestResolution()
int __cdecl CGameSettings::GetGfxHighestResolution(void) {
  
  return CGameSettings::m_iHighestPossibleResolution;
}


// address=[0x14aac80]
// Decompiled from int CGameSettings::GetMsgHistory()
int __cdecl CGameSettings::GetMsgHistory(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iMsgHistory);
}


// address=[0x14aaca0]
// Decompiled from int CGameSettings::GetMsgLevelMask()
int __cdecl CGameSettings::GetMsgLevelMask(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iMsgLevelMask);
}


// address=[0x14aacc0]
// Decompiled from int CGameSettings::GetMusicOn()
int __cdecl CGameSettings::GetMusicOn(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iMusicOn);
}


// address=[0x14aace0]
// Decompiled from int CGameSettings::GetMusicVolume()
int __cdecl CGameSettings::GetMusicVolume(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iMusicVolume);
}


// address=[0x14aad00]
// Decompiled from int CGameSettings::GetScrollStepValue()
int __cdecl CGameSettings::GetScrollStepValue(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iScrollStepValue);
}


// address=[0x14aad20]
// Decompiled from int CGameSettings::GetSoundFXVolume()
int __cdecl CGameSettings::GetSoundFXVolume(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iSoundFXVolume);
}


// address=[0x14aad40]
// Decompiled from int CGameSettings::GetSoundFxOn()
int __cdecl CGameSettings::GetSoundFxOn(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iSoundFXOn);
}


// address=[0x14aadc0]
// Decompiled from int CGameSettings::GetVoiceChatMicro()
int __cdecl CGameSettings::GetVoiceChatMicro(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iVoiceChatMicro);
}


// address=[0x14aade0]
// Decompiled from int CGameSettings::GetVoiceChatOn()
int __cdecl CGameSettings::GetVoiceChatOn(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iVoiceChatOn);
}


// address=[0x14aae00]
// Decompiled from int CGameSettings::GetVoiceChatVolume()
int __cdecl CGameSettings::GetVoiceChatVolume(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_iVoiceChatVolume);
}


// address=[0x14aaeb0]
// Decompiled from _DWORD *__cdecl CGameSettings::SetAlwaysUrgentMsg(bool a1)
void __cdecl CGameSettings::SetAlwaysUrgentMsg(bool a1) {
  
  return CStaticConfigVarInt::operator=(CGameSettings::m_iAlwaysUrgentMsg, a1);
}


// address=[0x14aaed0]
// Decompiled from int __cdecl CGameSettings::SetBorderScrollEnabled(bool a1)
void __cdecl CGameSettings::SetBorderScrollEnabled(bool a1) {
  
  CStaticConfigVarInt::operator=(CGameSettings::m_iBorderScroll, a1);
  return CGameSettings::Save();
}


// address=[0x14aaef0]
// Decompiled from _DWORD *__cdecl CGameSettings::SetChatMessageFilter(int a1)
void __cdecl CGameSettings::SetChatMessageFilter(int a1) {
  
  return CStaticConfigVarInt::operator=(CGameSettings::m_iChatMessageFilter, a1);
}


// address=[0x14aaf10]
// Decompiled from _DWORD *__cdecl CGameSettings::SetExtendedTooltip(int a1)
void __cdecl CGameSettings::SetExtendedTooltip(int a1) {
  
  return CStaticConfigVarInt::operator=(CGameSettings::m_iExtendedTooltip, a1);
}


// address=[0x14aaf50]
// Decompiled from int __cdecl CGameSettings::SetMsgHistory(int a1)
void __cdecl CGameSettings::SetMsgHistory(int a1) {
  
  CStaticConfigVarInt::operator=(CGameSettings::m_iMsgHistory, a1);
  return CGameSettings::Save();
}


// address=[0x14aaf70]
// Decompiled from int __cdecl CGameSettings::SetMsgLevelMask(int a1)
void __cdecl CGameSettings::SetMsgLevelMask(int a1) {
  
  CStaticConfigVarInt::operator=(CGameSettings::m_iMsgLevelMask, a1);
  return CGameSettings::Save();
}


// address=[0x14aaf90]
// Decompiled from int __cdecl CGameSettings::SetMusicOn(int a1)
void __cdecl CGameSettings::SetMusicOn(int a1) {
  
  CStaticConfigVarInt::operator=(CGameSettings::m_iMusicOn, a1);
  return CGameSettings::Save();
}


// address=[0x14aafb0]
// Decompiled from int __cdecl CGameSettings::SetMusicVolume(int a1)
void __cdecl CGameSettings::SetMusicVolume(int a1) {
  
  CStaticConfigVarInt::operator=(CGameSettings::m_iMusicVolume, a1);
  return CGameSettings::Save();
}


// address=[0x14aafd0]
// Decompiled from int __cdecl CGameSettings::SetScrollStepValue(int a1)
void __cdecl CGameSettings::SetScrollStepValue(int a1) {
  
  CStaticConfigVarInt::operator=(CGameSettings::m_iScrollStepValue, a1);
  return CGameSettings::Save();
}


// address=[0x14aaff0]
// Decompiled from int __cdecl CGameSettings::SetSoundFXOn(int a1)
void __cdecl CGameSettings::SetSoundFXOn(int a1) {
  
  CStaticConfigVarInt::operator=(CGameSettings::m_iSoundFXOn, a1);
  return CGameSettings::Save();
}


// address=[0x14ab010]
// Decompiled from int __cdecl CGameSettings::SetSoundFXVolume(int a1)
void __cdecl CGameSettings::SetSoundFXVolume(int a1) {
  
  CStaticConfigVarInt::operator=(CGameSettings::m_iSoundFXVolume, a1);
  return CGameSettings::Save();
}


// address=[0x14ab050]
// Decompiled from _DWORD *__cdecl CGameSettings::SetUserMP3(int a1)
void __cdecl CGameSettings::SetUserMP3(int a1) {
  
  return CStaticConfigVarInt::operator=(CGameSettings::m_iUserMP3, a1);
}


// address=[0x14ab070]
// Decompiled from int __cdecl CGameSettings::SetVoiceChatMicro(int a1)
void __cdecl CGameSettings::SetVoiceChatMicro(int a1) {
  
  CStaticConfigVarInt::operator=(CGameSettings::m_iVoiceChatMicro, a1);
  return CGameSettings::Save();
}


// address=[0x14ab090]
// Decompiled from int __cdecl CGameSettings::SetVoiceChatOn(int a1)
void __cdecl CGameSettings::SetVoiceChatOn(int a1) {
  
  CStaticConfigVarInt::operator=(CGameSettings::m_iVoiceChatOn, a1);
  return CGameSettings::Save();
}


// address=[0x14ab0b0]
// Decompiled from int __cdecl CGameSettings::SetVoiceChatVolume(int a1)
void __cdecl CGameSettings::SetVoiceChatVolume(int a1) {
  
  CStaticConfigVarInt::operator=(CGameSettings::m_iVoiceChatVolume, a1);
  return CGameSettings::Save();
}


// address=[0x14c1000]
// Decompiled from int __cdecl CGameSettings::GetHelpURLenglish(int a1)
std::string __cdecl CGameSettings::GetHelpURLenglish(void a1) {
  
  std::string::string(&CGameSettings::m_strHelpURLenglish);
  return a1;
}


// address=[0x14c1040]
// Decompiled from int __cdecl CGameSettings::GetHelpURLgerman(int a1)
std::string __cdecl CGameSettings::GetHelpURLgerman(void a1) {
  
  std::string::string(&CGameSettings::m_strHelpURLgerman);
  return a1;
}


// address=[0x14c1080]
// Decompiled from int __cdecl CGameSettings::GetNormURLenglish(int a1)
std::string __cdecl CGameSettings::GetNormURLenglish(void a1) {
  
  std::string::string(&CGameSettings::m_strNormURLenglish);
  return a1;
}


// address=[0x14c10c0]
// Decompiled from int __cdecl CGameSettings::GetNormURLgerman(int a1)
std::string __cdecl CGameSettings::GetNormURLgerman(void a1) {
  
  std::string::string(&CGameSettings::m_strNormURLgerman);
  return a1;
}


// address=[0x14cb750]
// Decompiled from int CGameSettings::GetTutorialStatus()
int __cdecl CGameSettings::GetTutorialStatus(void) {
  
  return CStaticConfigVarInt::operator int(&CGameSettings::m_uiTutorialSave);
}


// address=[0x1487680]
// Decompiled from int CGameSettings::LoadAINames()
void __cdecl CGameSettings::LoadAINames(void) {
  
  int result; // eax
  const char *v1; // eax
  const char *v2; // eax
  const char *v3; // eax
  size_t v4; // [esp-4h] [ebp-170h]
  int v5; // [esp+4h] [ebp-168h]
  void *v6; // [esp+Ch] [ebp-160h]
  void *v7; // [esp+10h] [ebp-15Ch]
  size_t v8; // [esp+18h] [ebp-154h]
  int i; // [esp+1Ch] [ebp-150h]
  _BYTE v10[28]; // [esp+20h] [ebp-14Ch] BYREF
  int v11[7]; // [esp+3Ch] [ebp-130h] BYREF
  _BYTE v12[28]; // [esp+58h] [ebp-114h] BYREF
  int v13[7]; // [esp+74h] [ebp-F8h] BYREF
  wchar_t Dest[64]; // [esp+90h] [ebp-DCh] BYREF
  char Buffer[64]; // [esp+110h] [ebp-5Ch] BYREF
  char Format[12]; // [esp+150h] [ebp-1Ch] BYREF
  int v17; // [esp+168h] [ebp-4h]

  result = 2036427856;
  strcpy(Format, "Player%d");
  for ( i = 0; i < 9; ++i )
  {
    j__sprintf(Buffer, Format, i + 1);
    v7 = std::string::string(v12, "AI Player");
    v17 = 0;
    ((void (__thiscall *)(CConfigManager *, int *, const char *, char *, void *))g_pCfgMgr->GetStringValue)(
      g_pCfgMgr,
      v13,
      "AINAMES",
      Buffer,
      v7);
    LOBYTE(v17) = 2;
    std::string::~string(v12);
    v6 = (void *)std::operator+<char>((int)v11, "(AI) ", (int)v13);
    std::string::operator=(v13, v6);
    std::string::~string(v11);
    v1 = (const char *)std::string::c_str(v13);
    if ( j__strlen(v1) >= 0x20
      && BBSupportDbgReport(2, "main\\GameSettings.cpp", 275, "strlen( strTemp.c_str() ) < MAX_PLAYERNAME_LENGTH") == 1 )
    {
      __debugbreak();
    }
    v2 = (const char *)std::string::c_str(v13);
    v4 = j__strlen(v2);
    v3 = (const char *)std::string::c_str(v13);
    v8 = j__mbstowcs(Dest, v3, v4);
    if ( v8 >= 64 )
      j____report_rangecheckfailure();
    Dest[v8] = 0;
    v5 = std::wstring::wstring(v10, Dest);
    std::wstring::operator=(v5);
    std::wstring::~wstring(v10);
    v17 = -1;
    std::string::~string(v13);
    result = i + 1;
  }
  return result;
}


// address=[0x3f45118]
// [Decompilation failed for static int CGameSettings::m_iHardwareAlwaysImpossible]

// address=[0x3f4511c]
// [Decompilation failed for static int CGameSettings::m_iHardwareObjectAlwaysImpossible]

// address=[0x3f45120]
// [Decompilation failed for static int CGameSettings::m_iHighestPossibleResolution]

// address=[0x3f45124]
// [Decompilation failed for static unsigned char * CGameSettings::m_uiCampaignSave]

// address=[0x3f45134]
// [Decompilation failed for static unsigned int CGameSettings::m_uiMDCampaignSave]

// address=[0x3f45138]
// [Decompilation failed for static unsigned int CGameSettings::m_uiAOCampaignSave]

// address=[0x3f4513c]
// [Decompilation failed for static unsigned int CGameSettings::m_uiMD2CampaignSave]

// address=[0x3f45140]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iFullscreenEnabled]

// address=[0x3f4514c]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iTextureQuality]

// address=[0x3f45158]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iFiltering]

// address=[0x3f45164]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iWindowWidth]

// address=[0x3f45170]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iWindowHeight]

// address=[0x3f4517c]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iWindowPosX]

// address=[0x3f45188]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iWindowPosY]

// address=[0x3f45194]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iForceBlit]

// address=[0x3f451a0]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iShowVideos]

// address=[0x3f451ac]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iMsgLevelMask]

// address=[0x3f451b8]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iMsgHistory]

// address=[0x3f451c4]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iBorderScroll]

// address=[0x3f451d0]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iExtendedTooltip]

// address=[0x3f451dc]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iScrollStepValue]

// address=[0x3f451e8]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iChatMessageFilter]

// address=[0x3f451f4]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iWebHelpMode]

// address=[0x3f45200]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iAIDifficulty]

// address=[0x3f4520c]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iAlwaysUrgentMsg]

// address=[0x3f45218]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iLanguage]

// address=[0x3f45224]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iAutoSaveInterval]

// address=[0x3f45230]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iMusicVolume]

// address=[0x3f4523c]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iMusicOn]

// address=[0x3f45248]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iSoundFXVolume]

// address=[0x3f45254]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iSoundFXOn]

// address=[0x3f45260]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iVoiceChatOn]

// address=[0x3f4526c]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iVoiceChatVolume]

// address=[0x3f45278]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iVoiceChatMicro]

// address=[0x3f45284]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_iUserMP3]

// address=[0x3f45290]
// [Decompilation failed for static std::wstring CGameSettings::m_wstrPlayerName]

// address=[0x3f452ac]
// [Decompilation failed for static std::string CGameSettings::m_strHelpURLenglish]

// address=[0x3f452c8]
// [Decompilation failed for static std::wstring * CGameSettings::m_wstrAINames]

// address=[0x3f453c4]
// [Decompilation failed for static std::string CGameSettings::m_strHelpURLgerman]

// address=[0x3f453e0]
// [Decompilation failed for static std::string CGameSettings::m_strNormURLenglish]

// address=[0x3f453fc]
// [Decompilation failed for static std::string CGameSettings::m_strNormURLgerman]

// address=[0x3f45418]
// [Decompilation failed for static std::string CGameSettings::m_strManualURL_DE]

// address=[0x3f45434]
// [Decompilation failed for static std::string CGameSettings::m_strManualURL_FR]

// address=[0x3f45450]
// [Decompilation failed for static std::string CGameSettings::m_strManualURL_EN]

// address=[0x3f4546c]
// [Decompilation failed for static std::string CGameSettings::m_strTipsURL_DE]

// address=[0x3f45488]
// [Decompilation failed for static std::string CGameSettings::m_strTipsURL_FR]

// address=[0x3f454a4]
// [Decompilation failed for static std::string CGameSettings::m_strTipsURL_EN]

// address=[0x3f454c0]
// [Decompilation failed for static class CStaticConfigVarInt CGameSettings::m_uiTutorialSave]

