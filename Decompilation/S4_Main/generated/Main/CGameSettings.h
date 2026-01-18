#ifndef CGAMESETTINGS_H
#define CGAMESETTINGS_H

#include "defines.h"

class CGameSettings {
public:
    // address=[0x13558a0]
    static void __cdecl Save(void);

    // address=[0x1355980]
    static void __cdecl SetGfxFullscreenEnabled(bool a1);

    // address=[0x13559a0]
    static void __cdecl SetWindowsDimensions(int a1, int a2, int a3, int a4);

    // address=[0x135df70]
    static int __cdecl GetGfxFullscreenEnabled(void);

    // address=[0x135df90]
    static int __cdecl GetGfxHeight(void);

    // address=[0x135dfb0]
    static int __cdecl GetGfxWidth(void);

    // address=[0x135dfd0]
    static int __cdecl GetLanguage(void);

    // address=[0x135e030]
    static int __cdecl GetWindowsPosX(void);

    // address=[0x135e050]
    static int __cdecl GetWindowsPosY(void);

    // address=[0x146ad50]
    static int __cdecl GetUserMP3(void);

    // address=[0x14878c0]
    static void __cdecl LoadCommandLineValues(void);

    // address=[0x14884c0]
    static void __cdecl Validate(void);

    // address=[0x14884d0]
    static void __cdecl DetermineHighestResolution(void);

    // address=[0x1488560]
    static std::wstring __cdecl GetUserConfigDirectory(void a1);

    // address=[0x1488600]
    static std::wstring __cdecl GetConfigFilePath(wchar_t const * a1, bool String);

    // address=[0x14887b0]
    static void __cdecl SetPlayerName(std::wstring a1);

    // address=[0x14888f0]
    static std::string __cdecl GetManualURL(void a1);

    // address=[0x1488970]
    static std::string __cdecl GetTipsURL(void a1);

    // address=[0x14889f0]
    static int __cdecl GetCampaignStatus(int a1);

    // address=[0x1488dc0]
    static void __cdecl SetCampaignStatus(int a1, int a2);

    // address=[0x1489530]
    static void __cdecl Cryption(unsigned char *,unsigned long);

    // address=[0x14895f0]
    static unsigned int __cdecl Crc(unsigned char *,unsigned long);

    // address=[0x148abd0]
    static int __cdecl GetWebHelpMode(void);

    // address=[0x148abf0]
    static void __cdecl SetWebHelpMode(int a1);

    // address=[0x148fd60]
    static bool __cdecl GetGfxFiltering(void);

    // address=[0x148fd90]
    static int __cdecl GetGfxForceBlit(void);

    // address=[0x148fdb0]
    static bool __cdecl GetGfxLandscapeHardware(void);

    // address=[0x148fdc0]
    static bool __cdecl GetGfxObjectHardware(void);

    // address=[0x148fdd0]
    static int __cdecl GetGfxPureSoftwareMode(void);

    // address=[0x148fde0]
    static int __cdecl GetGfxTextureQuality(void);

    // address=[0x148fe00]
    static bool __cdecl GetShowVideos(void);

    // address=[0x148ff20]
    static void __cdecl SetAlwaysHardwareImpossible(bool a1);

    // address=[0x148ff40]
    static void __cdecl SetAlwaysHardwareObjectImpossible(bool a1);

    // address=[0x148ff60]
    static void __cdecl SetGfxFiltering(bool a1);

    // address=[0x148ffa0]
    static void __cdecl SetGfxTextureQuality(int a1);

    // address=[0x1494480]
    static std::wstring __cdecl GetAIName(int a1);

    // address=[0x149f540]
    static std::wstring __cdecl GetPlayerName(void a1);

    // address=[0x14a0ab0]
    static int __cdecl GetAIDifficulty(void);

    // address=[0x14a0ad0]
    static void __cdecl SetAIDifficulty(int a1);

    // address=[0x14aaa90]
    static bool __cdecl GetAlwaysUrgentMsg(void);

    // address=[0x14aaac0]
    static int __cdecl GetAutosaveInterval(void);

    // address=[0x14aaae0]
    static bool __cdecl GetBorderScrollEnabled(void);

    // address=[0x14aab80]
    static int __cdecl GetChatMessageFilter(void);

    // address=[0x14aabf0]
    static int __cdecl GetExtendedTooltip(void);

    // address=[0x14aac10]
    static int __cdecl GetGfxHighestResolution(void);

    // address=[0x14aac80]
    static int __cdecl GetMsgHistory(void);

    // address=[0x14aaca0]
    static int __cdecl GetMsgLevelMask(void);

    // address=[0x14aacc0]
    static int __cdecl GetMusicOn(void);

    // address=[0x14aace0]
    static int __cdecl GetMusicVolume(void);

    // address=[0x14aad00]
    static int __cdecl GetScrollStepValue(void);

    // address=[0x14aad20]
    static int __cdecl GetSoundFXVolume(void);

    // address=[0x14aad40]
    static int __cdecl GetSoundFxOn(void);

    // address=[0x14aadc0]
    static int __cdecl GetVoiceChatMicro(void);

    // address=[0x14aade0]
    static int __cdecl GetVoiceChatOn(void);

    // address=[0x14aae00]
    static int __cdecl GetVoiceChatVolume(void);

    // address=[0x14aaeb0]
    static void __cdecl SetAlwaysUrgentMsg(bool a1);

    // address=[0x14aaed0]
    static void __cdecl SetBorderScrollEnabled(bool a1);

    // address=[0x14aaef0]
    static void __cdecl SetChatMessageFilter(int a1);

    // address=[0x14aaf10]
    static void __cdecl SetExtendedTooltip(int a1);

    // address=[0x14aaf50]
    static void __cdecl SetMsgHistory(int a1);

    // address=[0x14aaf70]
    static void __cdecl SetMsgLevelMask(int a1);

    // address=[0x14aaf90]
    static void __cdecl SetMusicOn(int a1);

    // address=[0x14aafb0]
    static void __cdecl SetMusicVolume(int a1);

    // address=[0x14aafd0]
    static void __cdecl SetScrollStepValue(int a1);

    // address=[0x14aaff0]
    static void __cdecl SetSoundFXOn(int a1);

    // address=[0x14ab010]
    static void __cdecl SetSoundFXVolume(int a1);

    // address=[0x14ab050]
    static void __cdecl SetUserMP3(int a1);

    // address=[0x14ab070]
    static void __cdecl SetVoiceChatMicro(int a1);

    // address=[0x14ab090]
    static void __cdecl SetVoiceChatOn(int a1);

    // address=[0x14ab0b0]
    static void __cdecl SetVoiceChatVolume(int a1);

    // address=[0x14c1000]
    static std::string __cdecl GetHelpURLenglish(void a1);

    // address=[0x14c1040]
    static std::string __cdecl GetHelpURLgerman(void a1);

    // address=[0x14c1080]
    static std::string __cdecl GetNormURLenglish(void a1);

    // address=[0x14c10c0]
    static std::string __cdecl GetNormURLgerman(void a1);

    // address=[0x14cb750]
    static int __cdecl GetTutorialStatus(void);

private:
    // address=[0x1487680]
    static void __cdecl LoadAINames(void);

    // address=[0x3f45118]
    static int m_iHardwareAlwaysImpossible;

    // address=[0x3f4511c]
    static int m_iHardwareObjectAlwaysImpossible;

    // address=[0x3f45120]
    static int m_iHighestPossibleResolution;

    // address=[0x3f45124]
    static unsigned char * m_uiCampaignSave;

    // address=[0x3f45134]
    static unsigned int m_uiMDCampaignSave;

    // address=[0x3f45138]
    static unsigned int m_uiAOCampaignSave;

    // address=[0x3f4513c]
    static unsigned int m_uiMD2CampaignSave;

    // address=[0x3f45140]
    static class CStaticConfigVarInt m_iFullscreenEnabled;

    // address=[0x3f4514c]
    static class CStaticConfigVarInt m_iTextureQuality;

    // address=[0x3f45158]
    static class CStaticConfigVarInt m_iFiltering;

    // address=[0x3f45164]
    static class CStaticConfigVarInt m_iWindowWidth;

    // address=[0x3f45170]
    static class CStaticConfigVarInt m_iWindowHeight;

    // address=[0x3f4517c]
    static class CStaticConfigVarInt m_iWindowPosX;

    // address=[0x3f45188]
    static class CStaticConfigVarInt m_iWindowPosY;

    // address=[0x3f45194]
    static class CStaticConfigVarInt m_iForceBlit;

    // address=[0x3f451a0]
    static class CStaticConfigVarInt m_iShowVideos;

    // address=[0x3f451ac]
    static class CStaticConfigVarInt m_iMsgLevelMask;

    // address=[0x3f451b8]
    static class CStaticConfigVarInt m_iMsgHistory;

    // address=[0x3f451c4]
    static class CStaticConfigVarInt m_iBorderScroll;

    // address=[0x3f451d0]
    static class CStaticConfigVarInt m_iExtendedTooltip;

    // address=[0x3f451dc]
    static class CStaticConfigVarInt m_iScrollStepValue;

    // address=[0x3f451e8]
    static class CStaticConfigVarInt m_iChatMessageFilter;

    // address=[0x3f451f4]
    static class CStaticConfigVarInt m_iWebHelpMode;

    // address=[0x3f45200]
    static class CStaticConfigVarInt m_iAIDifficulty;

    // address=[0x3f4520c]
    static class CStaticConfigVarInt m_iAlwaysUrgentMsg;

    // address=[0x3f45218]
    static class CStaticConfigVarInt m_iLanguage;

    // address=[0x3f45224]
    static class CStaticConfigVarInt m_iAutoSaveInterval;

    // address=[0x3f45230]
    static class CStaticConfigVarInt m_iMusicVolume;

    // address=[0x3f4523c]
    static class CStaticConfigVarInt m_iMusicOn;

    // address=[0x3f45248]
    static class CStaticConfigVarInt m_iSoundFXVolume;

    // address=[0x3f45254]
    static class CStaticConfigVarInt m_iSoundFXOn;

    // address=[0x3f45260]
    static class CStaticConfigVarInt m_iVoiceChatOn;

    // address=[0x3f4526c]
    static class CStaticConfigVarInt m_iVoiceChatVolume;

    // address=[0x3f45278]
    static class CStaticConfigVarInt m_iVoiceChatMicro;

    // address=[0x3f45284]
    static class CStaticConfigVarInt m_iUserMP3;

    // address=[0x3f45290]
    static std::wstring m_wstrPlayerName;

    // address=[0x3f452ac]
    static std::string m_strHelpURLenglish;

    // address=[0x3f452c8]
    static std::wstring * m_wstrAINames;

    // address=[0x3f453c4]
    static std::string m_strHelpURLgerman;

    // address=[0x3f453e0]
    static std::string m_strNormURLenglish;

    // address=[0x3f453fc]
    static std::string m_strNormURLgerman;

    // address=[0x3f45418]
    static std::string m_strManualURL_DE;

    // address=[0x3f45434]
    static std::string m_strManualURL_FR;

    // address=[0x3f45450]
    static std::string m_strManualURL_EN;

    // address=[0x3f4546c]
    static std::string m_strTipsURL_DE;

    // address=[0x3f45488]
    static std::string m_strTipsURL_FR;

    // address=[0x3f454a4]
    static std::string m_strTipsURL_EN;

    // address=[0x3f454c0]
    static class CStaticConfigVarInt m_uiTutorialSave;

};


#endif // CGAMESETTINGS_H
