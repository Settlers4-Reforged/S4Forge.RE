#include "CGameSettings.h"

#include "CBB/CBBSupport.h"
#include "../CConfigManager/IConfigManager.h"
#include "../CConfigManager/CConfigManager.h"
#include "../CConfigManager/CConfigManagerPtr.h"
#include "../CConfigManager/Var/CConfigVar.h"
#include "Gfx/Render/IGfxEngine.h"
#include "Debug/CTrace.h"
#include "File/FilePaths.h"

#include <algorithm>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <cstring>

std::wstring ToWide(std::string const &src)
{
  wchar_t buffer[256] = {};
  const size_t n = std::mbstowcs(buffer, src.c_str(), std::size(buffer) - 1);
  if (n == static_cast<size_t>(-1))
    return L"";
  buffer[n] = L'\0';
  return std::wstring(buffer);
}

std::string ToNarrow(std::wstring const &src)
{
  char buffer[256] = {};
  const size_t n = std::wcstombs(buffer, src.c_str(), std::size(buffer) - 1);
  if (n == static_cast<size_t>(-1))
    return std::string();
  buffer[n] = '\0';
  return std::string(buffer);
}

void __SaveMiscData2()
{
  IConfigManager *cfg = CConfigManagerPtr::GetInstance();
  if (!cfg)
    return;
  cfg->SaveSection("MISCDATA2", CGameSettings::GetConfigFilePath(L"MiscData2", true).c_str());
}

// address=[0x13558a0]
void __cdecl CGameSettings::Save(void)
{
  IConfigManager *cfg = CConfigManagerPtr::GetInstance();
  if (!cfg)
    return;
  cfg->SaveSection("GAMESETTINGS", CGameSettings::GetConfigFilePath(L"GameSettings", true).c_str());
}

// address=[0x1355980]
void __cdecl CGameSettings::SetGfxFullscreenEnabled(bool a1)
{
  CGameSettings::m_iFullscreenEnabled = a1;
  CGameSettings::Save();
}

// address=[0x13559a0]
void __cdecl CGameSettings::SetWindowsDimensions(int a1, int a2, int a3, int a4)
{
  CGameSettings::m_iWindowPosX = a1;
  CGameSettings::m_iWindowPosY = a2;
  CGameSettings::m_iWindowWidth = a3;
  CGameSettings::m_iWindowHeight = a4;
  CGameSettings::Save();
}

// address=[0x13558a0]
void __cdecl CGameSettings::Save(void)
{
  IConfigManager *cfg = CConfigManagerPtr::GetInstance();
  if (!cfg)
    return;
  cfg->SaveSection("GAMESETTINGS", CGameSettings::GetConfigFilePath(L"GameSettings", true).c_str());
}

// address=[0x1355980]
void __cdecl CGameSettings::SetGfxFullscreenEnabled(bool a1)
{
  CGameSettings::m_iFullscreenEnabled = a1;
  CGameSettings::Save();
}

// address=[0x13559a0]
void __cdecl CGameSettings::SetWindowsDimensions(int a1, int a2, int a3, int a4)
{
  CGameSettings::m_iWindowPosX = a1;
  CGameSettings::m_iWindowPosY = a2;
  CGameSettings::m_iWindowWidth = a3;
  CGameSettings::m_iWindowHeight = a4;
  CGameSettings::Save();
}

// address=[0x135df70]
int __cdecl CGameSettings::GetGfxFullscreenEnabled(void) { return CGameSettings::m_iFullscreenEnabled; }
// address=[0x135df90]
int __cdecl CGameSettings::GetGfxHeight(void) { return CGameSettings::m_iWindowHeight; }
// address=[0x135dfb0]
int __cdecl CGameSettings::GetGfxWidth(void) { return CGameSettings::m_iWindowWidth; }
// address=[0x135dfd0]
int __cdecl CGameSettings::GetLanguage(void) { return CGameSettings::m_iLanguage; }
// address=[0x135e030]
int __cdecl CGameSettings::GetWindowsPosX(void) { return CGameSettings::m_iWindowPosX; }
// address=[0x135e050]
int __cdecl CGameSettings::GetWindowsPosY(void) { return CGameSettings::m_iWindowPosY; }
// address=[0x146ad50]
int __cdecl CGameSettings::GetUserMP3(void) { return CGameSettings::m_iUserMP3; }

// address=[0x14878c0]
void __cdecl CGameSettings::LoadCommandLineValues(void)
{
  IConfigManager *cfg = CConfigManagerPtr::GetInstance();
  if (!cfg)
    return;

  m_iWindowWidth = cfg->GetIntValue("COMMANDLINE", "gfxwidth", m_iWindowWidth);
  m_iWindowHeight = cfg->GetIntValue("COMMANDLINE", "gfxheight", m_iWindowHeight);
  m_iWindowPosX = cfg->GetIntValue("COMMANDLINE", "WindowPosX", m_iWindowPosX);
  m_iWindowPosY = cfg->GetIntValue("COMMANDLINE", "WindowPosY", m_iWindowPosY);
  m_iFullscreenEnabled = cfg->GetIntValue("COMMANDLINE", "Fullscreen", m_iFullscreenEnabled);
  m_iBorderScroll = cfg->GetIntValue("COMMANDLINE", "borderscroll", m_iBorderScroll);
  m_iScrollStepValue = cfg->GetIntValue("COMMANDLINE", "scrollstepvalue", m_iScrollStepValue);

  std::string playerName = cfg->GetStringValue("GAMESETTINGS", "PlayerName", "Player1");
  if (playerName == "Player1")
  {
    char userName[256] = {};
    DWORD size = static_cast<DWORD>(std::size(userName));
    if (GetUserNameA(userName, &size) && std::strlen(userName) > 0)
      playerName = userName;
  }
  playerName = cfg->GetStringValue("COMMANDLINE", "playername", playerName);
  CGameSettings::SetPlayerName(ToWide(playerName));

  CGameSettings::LoadAINames();

  m_strHelpURLenglish = cfg->GetStringValue("WEB", "HelpURLenglish", "");
  if (m_strHelpURLenglish.empty())
    CTrace::Print("GameSettings.cpp: No 'HelpURLenglish' given! Check 'Web.cfg'!");

  m_strNormURLenglish = cfg->GetStringValue("WEB", "NormURLenglish", "");
  if (m_strNormURLenglish.empty())
    CTrace::Print("GameSettings.cpp: No 'm_strNormURLenglish' given! Check 'Web.cfg'!");

  m_strHelpURLgerman = cfg->GetStringValue("WEB", "HelpURLgerman", "");
  if (m_strHelpURLgerman.empty())
    CTrace::Print("GameSettings.cpp: No 'm_strHelpURLgerman' given! Check 'Web.cfg'!");

  m_strNormURLgerman = cfg->GetStringValue("WEB", "NormURLgerman", "");
  if (m_strNormURLgerman.empty())
    CTrace::Print("GameSettings.cpp: No 'm_strNormURLgerman' given! Check 'Web.cfg'!");

  m_strManualURL_DE = cfg->GetStringValue("MISCDATA1", "ManualURL_DE", "");
  if (m_strManualURL_DE.empty())
    CTrace::Print("GameSettings.cpp: No 'm_strManualURL_DE' given! Check 'Web.cfg'!");

  m_strManualURL_FR = cfg->GetStringValue("MISCDATA1", "ManualURL_FR", "");
  if (m_strManualURL_FR.empty())
    CTrace::Print("GameSettings.cpp: No 'm_strManualURL_FR' given! Check 'Web.cfg'!");

  m_strManualURL_EN = cfg->GetStringValue("MISCDATA1", "ManualURL_EN", "");
  if (m_strManualURL_EN.empty())
    CTrace::Print("GameSettings.cpp: No 'm_strManualURL_EN' given! Check 'Web.cfg'!");

  m_strTipsURL_DE = cfg->GetStringValue("MISCDATA1", "TipsURL_DE", "");
  if (m_strTipsURL_DE.empty())
    CTrace::Print("GameSettings.cpp: No 'TipsURL_DE' given! Check 'Web.cfg'!");

  m_strTipsURL_FR = cfg->GetStringValue("MISCDATA1", "TipsURL_FR", "");
  if (m_strTipsURL_FR.empty())
    CTrace::Print("GameSettings.cpp: No 'TipsURL_FR' given! Check 'Web.cfg'!");

  m_strTipsURL_EN = cfg->GetStringValue("MISCDATA1", "TipsURL_EN", "");
  if (m_strTipsURL_EN.empty())
    CTrace::Print("GameSettings.cpp: No 'TipsURL_EN' given! Check 'Web.cfg'!");

  CGameSettings::Save();
}

// address=[0x14884c0]
void __cdecl CGameSettings::Validate(void) {}
// address=[0x14884d0]
void __cdecl CGameSettings::DetermineHighestResolution(void)
{
  if (!g_pGfxEngine && BBSupportDbgReport(2, "main\\GameSettings.cpp", 227, "g_pGfxEngine") == 1)
    __debugbreak();
  for (CGameSettings::m_iHighestPossibleResolution = 1;
       CGameSettings::m_iHighestPossibleResolution <= 3;
       ++CGameSettings::m_iHighestPossibleResolution)
  {
    if (!g_pGfxEngine->IsResolutionPossible(CGameSettings::m_iHighestPossibleResolution))
    {
      --CGameSettings::m_iHighestPossibleResolution;
      return;
    }
  }
  --CGameSettings::m_iHighestPossibleResolution;
}

// address=[0x1488560]
std::wstring __cdecl CGameSettings::GetUserConfigDirectory(void)
{
  return FilePaths::GetUserDirectoryPath() + L"Config\\";
}

// address=[0x1488600]
std::wstring __cdecl CGameSettings::GetConfigFilePath(wchar_t const *ret, bool swpConfig)
{
  const std::wstring fileName = std::wstring(ret) + L".cfg";
  if (swpConfig)
  {
    const std::wstring userPath = CGameSettings::GetUserConfigDirectory() + fileName;
    if (FilePaths::FileExists(userPath))
      return userPath;
  }
  return std::wstring(L"Config\\") + fileName;
}

// address=[0x14887b0]
void __cdecl CGameSettings::SetPlayerName(std::wstring a1)
{
  CGameSettings::m_wstrPlayerName = a1;

  IConfigManager *cfg = CConfigManagerPtr::GetInstance();
  if (cfg)
  {
    const std::string asciiName = ToNarrow(a1);
    if (CConfigVar *var = cfg->GetConfigVar("GAMESETTINGS", "PlayerName"))
      var->SetValue(asciiName);
    else
      cfg->GetStringValue("GAMESETTINGS", "PlayerName", asciiName);
  }

  CGameSettings::Save();
}

// address=[0x14888f0]
std::string __cdecl CGameSettings::GetManualURL(void)
{
  const int language = CGameSettings::GetLanguage();
  if (language == 1)
    return CGameSettings::m_strManualURL_DE;
  if (language == 2)
    return CGameSettings::m_strManualURL_FR;
  return CGameSettings::m_strManualURL_EN;
}

// address=[0x1488970]
std::string __cdecl CGameSettings::GetTipsURL(void)
{
  const int language = CGameSettings::GetLanguage();
  if (language == 1)
    return CGameSettings::m_strTipsURL_DE;
  if (language == 2)
    return CGameSettings::m_strTipsURL_FR;
  return CGameSettings::m_strTipsURL_EN;
}

// address=[0x14889f0]
int __cdecl CGameSettings::GetCampaignStatus(int _iCampaignType)
{
  IConfigManager *cfg = CConfigManagerPtr::GetInstance();
  if (!cfg)
    return 0;

  if (_iCampaignType >= 5 && _iCampaignType < 11)
  {
    CGameSettings::m_uiMDCampaignSave = cfg->GetIntValue("MISCDATA2", "Data05", 0);
    if (_iCampaignType == 10)
      return CGameSettings::m_uiMDCampaignSave < 0;
    return (CGameSettings::m_uiMDCampaignSave >> (4 * _iCampaignType - 20)) & 0xF;
  }

  if (_iCampaignType >= 11 && _iCampaignType < 17)
  {
    CGameSettings::m_uiAOCampaignSave = cfg->GetIntValue("MISCDATA2", "Data06", 0);
    return (CGameSettings::m_uiAOCampaignSave >> (4 * _iCampaignType - 44)) & 0xF;
  }

  if (_iCampaignType >= 17 && _iCampaignType < 21)
  {
    CGameSettings::m_uiMD2CampaignSave = cfg->GetIntValue("MISCDATA2", "Data07", 0);
    return (CGameSettings::m_uiMD2CampaignSave >> (4 * _iCampaignType - 68)) & 0xF;
  }

  if (_iCampaignType >= 21 && _iCampaignType < 25)
    return 15;

  if ((!_iCampaignType || _iCampaignType >= 5) &&
      BBSupportDbgReport(2, "main\\GameSettings.cpp", 345, "_iCampaignType && _iCampaignType < CAMPAIGN_MAX_MAIN") == 1)
  {
    __debugbreak();
  }

  const int campaignIndex = _iCampaignType - 1;

  unsigned int *campaignSave = reinterpret_cast<unsigned int *>(CGameSettings::m_uiCampaignSave);
  campaignSave[0] = cfg->GetIntValue("MISCDATA2", "Data01", 0);
  campaignSave[1] = cfg->GetIntValue("MISCDATA2", "Data02", 0);
  campaignSave[2] = cfg->GetIntValue("MISCDATA2", "Data03", 0);
  campaignSave[3] = cfg->GetIntValue("MISCDATA2", "Data04", 0);

  unsigned char any = 0;
  for (unsigned int i = 0; i < 16; ++i)
    any |= reinterpret_cast<unsigned char *>(campaignSave)[i];

  if (!any)
    return 0;

  CGameSettings::Cryption(reinterpret_cast<unsigned char *>(campaignSave), 16u);

  unsigned int expectedCrc = 0;
  reinterpret_cast<unsigned char *>(&expectedCrc)[0] = reinterpret_cast<unsigned char *>(&campaignSave[0])[3];
  reinterpret_cast<unsigned char *>(&expectedCrc)[1] = reinterpret_cast<unsigned char *>(&campaignSave[1])[2];
  reinterpret_cast<unsigned char *>(&expectedCrc)[2] = reinterpret_cast<unsigned char *>(&campaignSave[2])[1];
  reinterpret_cast<unsigned char *>(&expectedCrc)[3] = reinterpret_cast<unsigned char *>(&campaignSave[3])[2];

  reinterpret_cast<unsigned char *>(&campaignSave[0])[3] = 0;
  reinterpret_cast<unsigned char *>(&campaignSave[1])[2] = 0;
  reinterpret_cast<unsigned char *>(&campaignSave[2])[1] = 0;
  reinterpret_cast<unsigned char *>(&campaignSave[3])[2] = 0;

  if (expectedCrc != CGameSettings::Crc(reinterpret_cast<unsigned char *>(campaignSave), 16))
  {
    CTrace::Print("CGameSettings.cpp: CRC of campaign save invalid !!");
    return 0;
  }

  return static_cast<unsigned char>(campaignSave[campaignIndex]);
}

// address=[0x1488dc0]
void __cdecl CGameSettings::SetCampaignStatus(int a1, int a2)
{
  const int oldStatus = CGameSettings::GetCampaignStatus(a1);
  if (oldStatus > a2)
    CTrace::Print("CGameSettings.cpp: Campaign state was already higher... Old %d, New %d, Campaign %d ", oldStatus, a2, a1);

  unsigned int *campaignSave = reinterpret_cast<unsigned int *>(CGameSettings::m_uiCampaignSave);
  IConfigManager *cfg = CConfigManagerPtr::GetInstance();
  if (!cfg)
    return;

  if (a1 >= 5 && a1 < 11)
  {
    if (a1 == 10)
    {
      if (a2)
      {
        CGameSettings::m_uiMDCampaignSave |= 0x80000000;
        if (CConfigVar *v = cfg->GetConfigVar("MISCDATA2", "Data05"))
          v->SetValue(static_cast<int>(CGameSettings::m_uiMDCampaignSave));
        cfg->SaveSection("MISCDATA2", CGameSettings::GetConfigFilePath(L"MiscData2", true).c_str());
      }
      return;
    }

    CGameSettings::m_uiMDCampaignSave &= ~(15 << (4 * a1 - 20));
    CGameSettings::m_uiMDCampaignSave |= (a2 << (4 * a1 - 20));
    if (CConfigVar *v = cfg->GetConfigVar("MISCDATA2", "Data05"))
      v->SetValue(static_cast<int>(CGameSettings::m_uiMDCampaignSave));
    cfg->SaveSection("MISCDATA2", CGameSettings::GetConfigFilePath(L"MiscData2", true).c_str());

    if ((CGameSettings::m_uiMDCampaignSave & 0x7FFFFFFF) == 0x33555)
      CGameSettings::SetCampaignStatus(10, 1);
    return;
  }

  if (a1 >= 11 && a1 < 17)
  {
    const int mask = 15 << (4 * a1 - 44);
    CGameSettings::m_uiAOCampaignSave &= ~mask;
    CGameSettings::m_uiAOCampaignSave |= (a2 << (4 * a1 - 44));
    if (CConfigVar *v = cfg->GetConfigVar("MISCDATA2", "Data06"))
      v->SetValue(static_cast<int>(CGameSettings::m_uiAOCampaignSave));

    cfg->SaveSection("MISCDATA2", CGameSettings::GetConfigFilePath(L"MiscData2", true).c_str());
    return;
  }

  if (a1 >= 17 && a1 < 21)
  {
    const int mask = 15 << (4 * a1 - 68);
    CGameSettings::m_uiMD2CampaignSave &= ~mask;
    CGameSettings::m_uiMD2CampaignSave |= (a2 << (4 * a1 - 68));
    if (CConfigVar *v = cfg->GetConfigVar("MISCDATA2", "Data07"))
      v->SetValue(static_cast<int>(CGameSettings::m_uiMD2CampaignSave));

    cfg->SaveSection("MISCDATA2", CGameSettings::GetConfigFilePath(L"MiscData2", true).c_str());
    return;
  }

  if ((!a1 || a1 >= 5) &&
      BBSupportDbgReport(2, "main\\GameSettings.cpp", 487, "_iCampaignType && _iCampaignType < CAMPAIGN_MAX_MAIN") == 1)
  {
    __debugbreak();
  }

  reinterpret_cast<unsigned char &>(campaignSave[a1 - 1]) = static_cast<unsigned char>(a2);

  unsigned int crc = CGameSettings::Crc(reinterpret_cast<unsigned char *>(campaignSave), 16);
  reinterpret_cast<unsigned char *>(&campaignSave[0])[3] = 0;
  reinterpret_cast<unsigned char *>(&campaignSave[1])[2] = 0;
  reinterpret_cast<unsigned char *>(&campaignSave[2])[1] = 0;
  reinterpret_cast<unsigned char *>(&campaignSave[3])[2] = 0;

  reinterpret_cast<unsigned char *>(&campaignSave[0])[3] = reinterpret_cast<unsigned char *>(&crc)[0];
  reinterpret_cast<unsigned char *>(&campaignSave[1])[2] = reinterpret_cast<unsigned char *>(&crc)[1];
  reinterpret_cast<unsigned char *>(&campaignSave[2])[1] = reinterpret_cast<unsigned char *>(&crc)[2];
  reinterpret_cast<unsigned char *>(&campaignSave[3])[2] = reinterpret_cast<unsigned char *>(&crc)[3];

  CGameSettings::Cryption(reinterpret_cast<unsigned char *>(campaignSave), 16);

  if (CConfigVar *v = cfg->GetConfigVar("MISCDATA2", "Data01"))
    v->SetValue(static_cast<int>(campaignSave[0]));
  if (CConfigVar *v = cfg->GetConfigVar("MISCDATA2", "Data02"))
    v->SetValue(static_cast<int>(campaignSave[1]));
  if (CConfigVar *v = cfg->GetConfigVar("MISCDATA2", "Data03"))
    v->SetValue(static_cast<int>(campaignSave[2]));
  if (CConfigVar *v = cfg->GetConfigVar("MISCDATA2", "Data04"))
    v->SetValue(static_cast<int>(campaignSave[3]));

  cfg->SaveSection("MISCDATA2", CGameSettings::GetConfigFilePath(L"MiscData2", true).c_str());
}

// address=[0x1489530]
void __cdecl CGameSettings::Cryption(unsigned char *a1, unsigned long a2)
{
  static constexpr char kKey[] = "19283746574839201324";
  for (unsigned long i = 0; i < a2; ++i)
    a1[i] ^= static_cast<unsigned char>(kKey[i % (sizeof(kKey) - 1)]);
}

// address=[0x14895f0]
unsigned int __cdecl CGameSettings::Crc(unsigned char *a1, unsigned long a2)
{
  unsigned int crc = 0;
  constexpr unsigned int poly = 0x8005;

  for (unsigned long i = 0; i < a2; ++i)
  {
    crc ^= (static_cast<unsigned int>(a1[i]) << 8);
    for (int b = 0; b < 8; ++b)
    {
      if (crc & 0x8000)
        crc = (crc << 1) ^ poly;
      else
        crc <<= 1;
      crc &= 0xFFFF;
    }
  }

  return crc;
}

// address=[0x148abd0]
int __cdecl CGameSettings::GetWebHelpMode(void) { return CGameSettings::m_iWebHelpMode; }
// address=[0x148abf0]
void __cdecl CGameSettings::SetWebHelpMode(int a1)
{
  CGameSettings::m_iWebHelpMode = a1;
  CGameSettings::Save();
}
// address=[0x148fd60]
bool __cdecl CGameSettings::GetGfxFiltering(void) { return CGameSettings::m_iFiltering != 0; }
// address=[0x148fd90]
int __cdecl CGameSettings::GetGfxForceBlit(void) { return CGameSettings::m_iForceBlit; }
// address=[0x148fdb0]
bool __cdecl CGameSettings::GetGfxLandscapeHardware(void) { return true; }
// address=[0x148fdc0]
bool __cdecl CGameSettings::GetGfxObjectHardware(void) { return true; }
// address=[0x148fdd0]
int __cdecl CGameSettings::GetGfxPureSoftwareMode(void) { return 0; }
// address=[0x148fde0]
int __cdecl CGameSettings::GetGfxTextureQuality(void) { return CGameSettings::m_iTextureQuality; }
// address=[0x148fe00]
bool __cdecl CGameSettings::GetShowVideos(void) { return CGameSettings::m_iShowVideos != 0; }
// address=[0x148ff20]
void __cdecl CGameSettings::SetAlwaysHardwareImpossible(bool a1) { CGameSettings::m_iHardwareAlwaysImpossible = a1; }
// address=[0x148ff40]
void __cdecl CGameSettings::SetAlwaysHardwareObjectImpossible(bool a1) { CGameSettings::m_iHardwareObjectAlwaysImpossible = a1; }
// address=[0x148ff60]
void __cdecl CGameSettings::SetGfxFiltering(bool a1)
{
  CGameSettings::m_iFiltering = a1;
  CGameSettings::Save();
}
// address=[0x148ffa0]
void __cdecl CGameSettings::SetGfxTextureQuality(int a1)
{
  CGameSettings::m_iTextureQuality = a1;
  CGameSettings::Save();
}

// address=[0x1494480]
std::wstring __cdecl CGameSettings::GetAIName(int a1)
{
  if (a1 <= 0 || a1 > sizeof(m_wstrAINames) / sizeof(m_wstrAINames[0]))
    return std::wstring();
  return CGameSettings::m_wstrAINames[a1 - 1];
}

// address=[0x149f540]
std::wstring __cdecl CGameSettings::GetPlayerName(void) { return CGameSettings::m_wstrPlayerName; }

// address=[0x14a0ab0]
int __cdecl CGameSettings::GetAIDifficulty(void) { return CGameSettings::m_iAIDifficulty; }
// address=[0x14a0ad0]
void __cdecl CGameSettings::SetAIDifficulty(int a1)
{
  CGameSettings::m_iAIDifficulty = a1;
  CGameSettings::Save();
}
// address=[0x14aaa90]
bool __cdecl CGameSettings::GetAlwaysUrgentMsg(void) { return CGameSettings::m_iAlwaysUrgentMsg != 0; }
// address=[0x14aaac0]
int __cdecl CGameSettings::GetAutosaveInterval(void) { return CGameSettings::m_iAutoSaveInterval; }
// address=[0x14aaae0]
bool __cdecl CGameSettings::GetBorderScrollEnabled(void) { return CGameSettings::m_iBorderScroll != 0; }
// address=[0x14aab80]
int __cdecl CGameSettings::GetChatMessageFilter(void) { return CGameSettings::m_iChatMessageFilter; }
// address=[0x14aabf0]
int __cdecl CGameSettings::GetExtendedTooltip(void) { return CGameSettings::m_iExtendedTooltip; }
// address=[0x14aac10]
int __cdecl CGameSettings::GetGfxHighestResolution(void) { return CGameSettings::m_iHighestPossibleResolution; }
// address=[0x14aac80]
int __cdecl CGameSettings::GetMsgHistory(void) { return CGameSettings::m_iMsgHistory; }
// address=[0x14aaca0]
int __cdecl CGameSettings::GetMsgLevelMask(void) { return CGameSettings::m_iMsgLevelMask; }
// address=[0x14aacc0]
int __cdecl CGameSettings::GetMusicOn(void) { return CGameSettings::m_iMusicOn; }
// address=[0x14aace0]
int __cdecl CGameSettings::GetMusicVolume(void) { return CGameSettings::m_iMusicVolume; }
// address=[0x14aad00]
int __cdecl CGameSettings::GetScrollStepValue(void) { return CGameSettings::m_iScrollStepValue; }
// address=[0x14aad20]
int __cdecl CGameSettings::GetSoundFXVolume(void) { return CGameSettings::m_iSoundFXVolume; }
// address=[0x14aad40]
int __cdecl CGameSettings::GetSoundFxOn(void) { return CGameSettings::m_iSoundFXOn; }
// address=[0x14aadc0]
int __cdecl CGameSettings::GetVoiceChatMicro(void) { return CGameSettings::m_iVoiceChatMicro; }
// address=[0x14aade0]
int __cdecl CGameSettings::GetVoiceChatOn(void) { return CGameSettings::m_iVoiceChatOn; }
// address=[0x14aae00]
int __cdecl CGameSettings::GetVoiceChatVolume(void) { return CGameSettings::m_iVoiceChatVolume; }

// address=[0x14aaeb0]
void __cdecl CGameSettings::SetAlwaysUrgentMsg(bool a1) { CGameSettings::m_iAlwaysUrgentMsg = a1; }
// address=[0x14aaed0]
void __cdecl CGameSettings::SetBorderScrollEnabled(bool a1)
{
  CGameSettings::m_iBorderScroll = a1;
  CGameSettings::Save();
}
// address=[0x14aaef0]
void __cdecl CGameSettings::SetChatMessageFilter(int a1) { CGameSettings::m_iChatMessageFilter = a1; }
// address=[0x14aaf10]
void __cdecl CGameSettings::SetExtendedTooltip(int a1) { CGameSettings::m_iExtendedTooltip = a1; }
// address=[0x14aaf50]
void __cdecl CGameSettings::SetMsgHistory(int a1)
{
  CGameSettings::m_iMsgHistory = a1;
  CGameSettings::Save();
}
// address=[0x14aaf70]
void __cdecl CGameSettings::SetMsgLevelMask(int a1)
{
  CGameSettings::m_iMsgLevelMask = a1;
  CGameSettings::Save();
}
// address=[0x14aaf90]
void __cdecl CGameSettings::SetMusicOn(int a1)
{
  CGameSettings::m_iMusicOn = a1;
  CGameSettings::Save();
}
// address=[0x14aafb0]
void __cdecl CGameSettings::SetMusicVolume(int a1)
{
  CGameSettings::m_iMusicVolume = a1;
  CGameSettings::Save();
}
// address=[0x14aafd0]
void __cdecl CGameSettings::SetScrollStepValue(int a1)
{
  CGameSettings::m_iScrollStepValue = a1;
  CGameSettings::Save();
}
// address=[0x14aaff0]
void __cdecl CGameSettings::SetSoundFXOn(int a1)
{
  CGameSettings::m_iSoundFXOn = a1;
  CGameSettings::Save();
}
// address=[0x14ab010]
void __cdecl CGameSettings::SetSoundFXVolume(int a1)
{
  CGameSettings::m_iSoundFXVolume = a1;
  CGameSettings::Save();
}
// address=[0x14ab050]
void __cdecl CGameSettings::SetUserMP3(int a1) { CGameSettings::m_iUserMP3 = a1; }
// address=[0x14ab070]
void __cdecl CGameSettings::SetVoiceChatMicro(int a1)
{
  CGameSettings::m_iVoiceChatMicro = a1;
  CGameSettings::Save();
}
// address=[0x14ab090]
void __cdecl CGameSettings::SetVoiceChatOn(int a1)
{
  CGameSettings::m_iVoiceChatOn = a1;
  CGameSettings::Save();
}
// address=[0x14ab0b0]
void __cdecl CGameSettings::SetVoiceChatVolume(int a1)
{
  CGameSettings::m_iVoiceChatVolume = a1;
  CGameSettings::Save();
}

// address=[0x14c1000]
std::string __cdecl CGameSettings::GetHelpURLenglish() { return CGameSettings::m_strHelpURLenglish; }
// address=[0x14c1040]
std::string __cdecl CGameSettings::GetHelpURLgerman() { return CGameSettings::m_strHelpURLgerman; }
// address=[0x14c1080]
std::string __cdecl CGameSettings::GetNormURLenglish() { return CGameSettings::m_strNormURLenglish; }
// address=[0x14c10c0]
std::string __cdecl CGameSettings::GetNormURLgerman() { return CGameSettings::m_strNormURLgerman; }
// address=[0x14cb750]
int __cdecl CGameSettings::GetTutorialStatus(void) { return CGameSettings::m_uiTutorialSave; }

// address=[0x1487680]
void __cdecl CGameSettings::LoadAINames(void)
{
  IConfigManager *cfg = CConfigManagerPtr::GetInstance();
  if (!cfg)
    return;

  for (int i = 0; i < 9; ++i)
  {
    char key[16] = {};
    std::snprintf(key, std::size(key), "Player%d", i + 1);

    std::string name = cfg->GetStringValue("AINAMES", key, "AI Player");
    name = std::string("(AI) ") + name;

    if (name.length() >= 32 &&
        BBSupportDbgReport(2, "main\\GameSettings.cpp", 275, "strlen( strTemp.c_str() ) < MAX_PLAYERNAME_LENGTH") == 1)
    {
      __debugbreak();
    }

    m_wstrAINames[i] = ToWide(name);
  }
}

int CGameSettings::m_iHardwareAlwaysImpossible = 0;
int CGameSettings::m_iHardwareObjectAlwaysImpossible = 0;
int CGameSettings::m_iHighestPossibleResolution = 3;
unsigned char CGameSettings::m_uiCampaignSave[4] = {};
unsigned int CGameSettings::m_uiMDCampaignSave = 0;
unsigned int CGameSettings::m_uiAOCampaignSave = 0;
unsigned int CGameSettings::m_uiMD2CampaignSave = 0;

// Static initializer list starts here: address=0x366AE48

CStaticConfigVarInt CGameSettings::m_iFullscreenEnabled("GAMESETTINGS", "Fullscreen", 1);
CStaticConfigVarInt CGameSettings::m_iTextureQuality("GAMESETTINGS", "TextureQuality", 1);
CStaticConfigVarInt CGameSettings::m_iFiltering("GAMESETTINGS", "Filtering", 1);
CStaticConfigVarInt CGameSettings::m_iWindowWidth("GAMESETTINGS", "WindowWidth", 800);
CStaticConfigVarInt CGameSettings::m_iWindowHeight("GAMESETTINGS", "WindowHeight", 600);
CStaticConfigVarInt CGameSettings::m_iWindowPosX("GAMESETTINGS", "WindowPosX", 0);
CStaticConfigVarInt CGameSettings::m_iWindowPosY("GAMESETTINGS", "WindowPosY", 0);
CStaticConfigVarInt CGameSettings::m_iForceBlit("GAMESETTINGS", "ForceBlit", 0);
CStaticConfigVarInt CGameSettings::m_iShowVideos("GAMESETTINGS", "ShowVideos", 1);
CStaticConfigVarInt CGameSettings::m_iMsgLevelMask("GAMESETTINGS", "MsgLevelMask", -1);
CStaticConfigVarInt CGameSettings::m_iMsgHistory("GAMESETTINGS", "MsgHistory", 100);
CStaticConfigVarInt CGameSettings::m_iBorderScroll("GAMESETTINGS", "BorderScroll", 0);
CStaticConfigVarInt CGameSettings::m_iExtendedTooltip("GAMESETTINGS", "ExtendedTooltip", 1);
CStaticConfigVarInt CGameSettings::m_iScrollStepValue("GAMESETTINGS", "ScrollStepValue", 10);
CStaticConfigVarInt CGameSettings::m_iChatMessageFilter("GAMESETTINGS", "ChatMessageFilter", -1);
CStaticConfigVarInt CGameSettings::m_iWebHelpMode("GAMESETTINGS", "WebHelpMode", 1);
CStaticConfigVarInt CGameSettings::m_iAIDifficulty("GAMESETTINGS", "AILevel", 0);
CStaticConfigVarInt CGameSettings::m_iAlwaysUrgentMsg("GAMESETTINGS", "PopupAllMsgs", 0);
CStaticConfigVarInt CGameSettings::m_iLanguage("GAMESETTINGS", "Language", 0);
CStaticConfigVarInt CGameSettings::m_iAutoSaveInterval("GAMESETTINGS", "AutosaveInterval", 15);
CStaticConfigVarInt CGameSettings::m_iMusicVolume("GAMESETTINGS", "MusicVolume", 100);
CStaticConfigVarInt CGameSettings::m_iMusicOn("GAMESETTINGS", "MusicEnabled", 1);
CStaticConfigVarInt CGameSettings::m_iSoundFXVolume("GAMESETTINGS", "SoundFXVolume", 100);
CStaticConfigVarInt CGameSettings::m_iSoundFXOn("GAMESETTINGS", "SoundFXEnabled", 1);
CStaticConfigVarInt CGameSettings::m_iVoiceChatOn("GAMESETTINGS", "VoiceChatEnabled", 0);
CStaticConfigVarInt CGameSettings::m_iVoiceChatVolume("GAMESETTINGS", "VoiceChatVolume", 100);
CStaticConfigVarInt CGameSettings::m_iVoiceChatMicro("GAMESETTINGS", "VoiceChatMicro", 100);
CStaticConfigVarInt CGameSettings::m_iUserMP3("GAMESETTINGS", "MP3UserFolder", 0);

std::wstring CGameSettings::m_wstrPlayerName{};
std::string CGameSettings::m_strHelpURLenglish{};

std::wstring CGameSettings::m_wstrAINames[9] = {}; // std::array<std::wstring, 9>().data();
std::string CGameSettings::m_strHelpURLgerman{};
std::string CGameSettings::m_strNormURLenglish{};
std::string CGameSettings::m_strNormURLgerman{};
std::string CGameSettings::m_strManualURL_DE{};
std::string CGameSettings::m_strManualURL_FR{};
std::string CGameSettings::m_strManualURL_EN{};
std::string CGameSettings::m_strTipsURL_DE{};
std::string CGameSettings::m_strTipsURL_FR{};
std::string CGameSettings::m_strTipsURL_EN{};
CStaticConfigVarInt CGameSettings::m_uiTutorialSave("GAMESETTINGS", "Tutorial", 0);
