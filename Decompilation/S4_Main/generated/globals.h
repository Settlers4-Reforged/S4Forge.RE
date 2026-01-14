#ifndef GLOBALS_H
#define GLOBALS_H

// address=[0x0]
___guard_longjmp_count;

// address=[0x0]
___guard_fids_table;

// address=[0x0]
___safe_se_handler_count;

// address=[0x0]
___safe_se_handler_table;

// address=[0x0]
___guard_fids_count;

// address=[0x0]
__except_list;

// address=[0x0]
___guard_iat_table;

// address=[0x0]
___dynamic_value_reloc_table;

// address=[0x0]
___guard_longjmp_table;

// address=[0x0]
___guard_iat_count;

// address=[0x0]
___ImageBase;

// address=[0x2c]
__tls_array;

// address=[0x100]
___guard_flags;

// address=[0x1000]
__enc$textbss$begin;

// address=[0x11a0edd]
__enc$textbss$end;

// address=[0x1297924]
_BinkGetError@0;

// address=[0x129792a]
_BinkOpen@8;

// address=[0x1297930]
_BinkDoFrame@4;

// address=[0x1297936]
_BinkNextFrame@4;

// address=[0x129793c]
_BinkWait@4;

// address=[0x1297942]
_BinkClose@4;

// address=[0x1297948]
_BinkPause@8;

// address=[0x129794e]
_BinkCopyToBuffer@28;

// address=[0x1297954]
_BinkSetSoundSystem@8;

// address=[0x129795a]
_BinkOpenMiles@4;

// address=[0x129aec0]
_inflateReset;

// address=[0x129af2b]
_inflateEnd;

// address=[0x129af94]
_inflateInit2_;

// address=[0x129b0fa]
_inflateInit_;

// address=[0x129b115]
_inflate;

// address=[0x129b7e6]
_inflateSetDictionary;

// address=[0x129b8a4]
_inflateSync;

// address=[0x129b9f6]
_inflateSyncPoint;

// address=[0x12a9d10]
_get_crc_table;

// address=[0x12a9d1a]
_crc32;

// address=[0x12a9f70]
_inflate_blocks_reset;

// address=[0x12aa027]
_inflate_blocks_new;

// address=[0x12aa11f]
_inflate_blocks;

// address=[0x12ab492]
_inflate_blocks_free;

// address=[0x12ab4ed]
_inflate_set_dictionary;

// address=[0x12ab524]
_inflate_blocks_sync_point;

// address=[0x12abab0]
_adler32;

// address=[0x12abdd0]
_zlibVersion;

// address=[0x12abdda]
_zError;

// address=[0x12abdee]
_zcalloc;

// address=[0x12abe17]
_zcfree;

// address=[0x12ad1d0]
_inflate_codes_new;

// address=[0x12ad225]
_inflate_codes;

// address=[0x12adf8d]
_inflate_codes_free;

// address=[0x12ae320]
_inflate_trees_bits;

// address=[0x12aec96]
_inflate_trees_dynamic;

// address=[0x12aee1b]
_inflate_trees_fixed;

// address=[0x12af120]
_inflate_flush;

// address=[0x12af370]
_inflate_fast;

// address=[0x12afc0c]
_RIB_request_interface@16;

// address=[0x12afc12]
_RIB_find_file_provider@12;

// address=[0x12afcb0]
_MSS_auto_cleanup;

// address=[0x12fcae0]
void * __cdecl operator new(unsigned int,void *);

// address=[0x12fe7d0]
void __cdecl __empty_global_delete(void *);

// address=[0x12fe7e0]
void __cdecl __global_array_delete(void *,unsigned int);

// address=[0x12fe7e0]
void __cdecl __global_delete(void *,unsigned int);

// address=[0x12fe7e0]
void __cdecl __empty_global_delete(void *,unsigned int);

// address=[0x1300fa0]
public: __thiscall TPriorityQueue<struct SSquadValue,51>::TPriorityQueue<struct SSquadValue,51>(void);

// address=[0x1301220]
protected: void __thiscall TPriorityQueue<struct SSquadValue,51>::DownHeap(int);

// address=[0x1301330]
public: bool __thiscall TPriorityQueue<struct SSquadValue,51>::Empty(void)const;

// address=[0x1301680]
public: void __thiscall TPriorityQueue<struct SSquadValue,51>::Pop(void);

// address=[0x13016e0]
public: void __thiscall TPriorityQueue<struct SSquadValue,51>::Push(struct SSquadValue const &);

// address=[0x1301830]
public: struct SSquadValue const & __thiscall TPriorityQueue<struct SSquadValue,51>::Top(void)const;

// address=[0x1301870]
protected: void __thiscall TPriorityQueue<struct SSquadValue,51>::UpHeap(int);

// address=[0x13066c0]
bool __cdecl Grid::InQuadrat(int,int,int);

// address=[0x1306b00]
int __cdecl Squares::XYToVW(int);

// address=[0x1307190]
int __cdecl Y16X16::UnpackXFast(int);

// address=[0x13071a0]
int __cdecl Y16X16::UnpackYFast(int);

// address=[0x1309eb0]
public: __thiscall TAIStaticMemoryPool<48,512>::TAIStaticMemoryPool<48,512>(void);

// address=[0x1309f90]
public: __thiscall TAIStaticObjectMemoryPool<class CAIEcoSectorAIEx,48,512>::TAIStaticObjectMemoryPool<class CAIEcoSectorAIEx,48,512>(void);

// address=[0x130a0f0]
void __cdecl operator delete(void *,void *);

// address=[0x130a140]
public: void * __thiscall TAIStaticMemoryPool<48,512>::AllocateMemory(unsigned int);

// address=[0x130a270]
public: void __thiscall TAIStaticObjectMemoryPool<class CAIEcoSectorAIEx,48,512>::Delete(class CAIEcoSectorAIEx *);

// address=[0x130a2b0]
public: void __thiscall TAIStaticMemoryPool<48,512>::FreeMemory(void *);

// address=[0x130a4c0]
protected: struct TAIStaticMemoryPool<48,512>::SFreeEntry * __thiscall TAIStaticMemoryPool<48,512>::PoolFreeEntryPtr(int);

// address=[0x130e310]
void __cdecl __vcrt_va_start_verify_argument_type<char const *>(void);

// address=[0x130ea40]
int __cdecl Grid::Distance(int,int,int,int);

// address=[0x130ea70]
int __cdecl Grid::DistanceInline(int,int);

// address=[0x130f2a0]
int __cdecl Y16X16::PackXYFast(int,int);

// address=[0x130f460]
void __cdecl Y16X16::UnpackXYFast(int,int &,int &);

// address=[0x130f4d0]
bool __cdecl Squares::ValidVW(int);

// address=[0x130f670]
___local_stdio_printf_options;

// address=[0x130f680]
__vsnprintf;

// address=[0x130f6b0]
__vsnprintf_l;

// address=[0x1315f10]
void __cdecl DebugIteratorTest(void);

// address=[0x1319010]
public: __thiscall TAIStaticMemoryPool<692,9>::TAIStaticMemoryPool<692,9>(void);

// address=[0x13190e0]
public: __thiscall TAIStaticObjectMemoryPool<class CAIPlayerAI,692,9>::TAIStaticObjectMemoryPool<class CAIPlayerAI,692,9>(void);

// address=[0x1319100]
public: __thiscall TAIStaticPtrVector<class CAISectorAI,8>::TAIStaticPtrVector<class CAISectorAI,8>(void);

// address=[0x1319140]
public: __thiscall TStaticArray<int,8>::TStaticArray<int,8>(void);

// address=[0x1319210]
public: __thiscall TAIStaticPtrVector<class CAISectorAI,8>::~TAIStaticPtrVector<class CAISectorAI,8>(void);

// address=[0x1319320]
public: class CAISectorAI * __thiscall TAIStaticPtrVector<class CAISectorAI,8>::operator[](int)const;

// address=[0x13194c0]
public: void * __thiscall TAIStaticMemoryPool<692,9>::AllocateMemory(unsigned int);

// address=[0x1319660]
public: void __thiscall TAIStaticObjectMemoryPool<class CAIPlayerAI,692,9>::Delete(class CAIPlayerAI *);

// address=[0x13196b0]
public: void __thiscall TAIStaticMemoryPool<692,9>::FreeMemory(void *);

// address=[0x13197d0]
public: void __thiscall TStaticArray<int,8>::Init(void);

// address=[0x1319850]
protected: struct TAIStaticMemoryPool<692,9>::SFreeEntry * __thiscall TAIStaticMemoryPool<692,9>::PoolFreeEntryPtr(int);

// address=[0x13198c0]
public: void __thiscall TAIStaticPtrVector<class CAISectorAI,8>::PushBack(class CAISectorAI *);

// address=[0x1319990]
public: void __thiscall TStaticArray<int,8>::PushBack(int const &);

// address=[0x1319a00]
public: void __thiscall TAIStaticPtrVector<class CAISectorAI,8>::ReleaseAll(void);

// address=[0x1319ab0]
public: bool __thiscall TStaticArray<int,8>::SearchBackwards(int const &);

// address=[0x1319b10]
public: int __thiscall TAIStaticPtrVector<class CAISectorAI,8>::Size(void)const;

// address=[0x131a520]
double __cdecl sqrt<int>(int);

// address=[0x131b520]
bool __cdecl operator==(struct SAIResourceData const &,struct SAIResourceData const &);

// address=[0x131bcc0]
void __cdecl InitResourceGroundInfoMap(void);

// address=[0x131ca50]
int __cdecl Squares::VWToXY(int);

// address=[0x131ca60]
bool __cdecl Squares::ValidVW(int,int);

// address=[0x131d8c0]
void __cdecl AILuaGlobalFuncDebugTest(void);

// address=[0x131e5d0]
public: __thiscall TStaticConfigIntArray<3>::TStaticConfigIntArray<3>(char const *,char const *,int,int,int);

// address=[0x131e650]
private: __thiscall TStaticConfigIntArrayBase<3>::TStaticConfigIntArrayBase<3>(char const *,char const *);

// address=[0x131e930]
public: virtual __thiscall TStaticConfigIntArray<3>::~TStaticConfigIntArray<3>(void);

// address=[0x131e950]
public: virtual __thiscall TStaticConfigIntArrayBase<3>::~TStaticConfigIntArrayBase<3>(void);

// address=[0x131eab0]
public: int & __thiscall TStaticConfigIntArrayBase<3>::operator[](int);

// address=[0x131ec40]
public: virtual int * __thiscall TStaticConfigIntArrayBase<3>::GetIntArray(void);

// address=[0x131ec60]
public: virtual int const * __thiscall TStaticConfigIntArrayBase<3>::GetIntArray(void)const;

// address=[0x131fef0]
_wmemcpy;

// address=[0x131ff20]
_wmemmove;

// address=[0x1325a00]
public: __thiscall TAIStaticPtrVector<class CAIEcoSectorAIEx,512>::TAIStaticPtrVector<class CAIEcoSectorAIEx,512>(void);

// address=[0x1325be0]
public: __thiscall TAIStaticPtrVector<class CAIEcoSectorAIEx,512>::~TAIStaticPtrVector<class CAIEcoSectorAIEx,512>(void);

// address=[0x1325ea0]
public: class CAIEcoSectorAIEx * __thiscall TAIStaticPtrVector<class CAIEcoSectorAIEx,512>::operator[](int)const;

// address=[0x13261f0]
public: void __thiscall TAIStaticPtrVector<class CAIEcoSectorAIEx,512>::PushBack(class CAIEcoSectorAIEx *);

// address=[0x13262d0]
public: void __thiscall TAIStaticPtrVector<class CAIEcoSectorAIEx,512>::Release(int);

// address=[0x1326420]
public: void __thiscall TAIStaticPtrVector<class CAIEcoSectorAIEx,512>::ReleaseAll(void);

// address=[0x13264d0]
public: int __thiscall TAIStaticPtrVector<class CAIEcoSectorAIEx,512>::Size(void)const;

// address=[0x132f920]
int __cdecl SurroundingHexPointsCount(int);

// address=[0x1338f40]
__tcsicmp;

// address=[0x1339ef0]
protected: __thiscall TPowerOf2Wrap<1024>::TPowerOf2Wrap<1024>(void);

// address=[0x1339f10]
public: __thiscall TStaticFIFO<unsigned short,1024>::TStaticFIFO<unsigned short,1024>(void);

// address=[0x1339f70]
public: bool __thiscall TStaticFIFO<unsigned short,1024>::Empty(void);

// address=[0x1339fb0]
public: void __thiscall TStaticFIFO<unsigned short,1024>::Init(void);

// address=[0x133a070]
public: void __thiscall TStaticFIFO<unsigned short,1024>::Pop(void);

// address=[0x133a0a0]
public: void __thiscall TStaticFIFO<unsigned short,1024>::Push(unsigned short const &);

// address=[0x133a1a0]
public: unsigned short & __thiscall TStaticFIFO<unsigned short,1024>::Top(void);

// address=[0x133a1c0]
protected: static int __cdecl TPowerOf2Wrap<1024>::Wrap(int);

// address=[0x1346cf0]
char * __cdecl _tcsstr(char *,char const *);

// address=[0x134dba0]
int __cdecl GetAvailableSection(void);

// address=[0x134dbe0]
std::wstring __cdecl Bugreport::GetBugReportsDirectoryPath(void);

// address=[0x134dc80]
std::wstring __cdecl Bugreport::GetBugReportScreenshotPath(void);

// address=[0x134dd20]
std::wstring __cdecl Bugreport::GetBugReportMessageFilePath(void);

// address=[0x134ddc0]
std::wstring __cdecl Bugreport::BuildAutoReporterCmdLineArgsForDebugReports(void);

// address=[0x134de90]
std::wstring __cdecl Bugreport::BuildAutoReporterCmdLineArgsForUserReports(void);

// address=[0x134df60]
std::wstring __cdecl Bugreport::BuildTraceFilePath(std::wstring const &);

// address=[0x134e050]
void __cdecl Bugreport::LaunchAutoreport(bool,std::wstring const &);

// address=[0x134e470]
void __cdecl __vcrt_va_start_verify_argument_type<wchar_t const *>(void);

// address=[0x134f1e0]
__snwprintf;

// address=[0x134f230]
__vsnwprintf_l;

// address=[0x134f6d0]
void __cdecl S4DebugTest(void);

// address=[0x1350c00]
void __cdecl __vcrt_va_start_verify_argument_type<char const * const>(void);

// address=[0x1351960]
class String __cdecl operator+(class String const &,class String const &);

// address=[0x1352b00]
__snprintf;

// address=[0x1352b50]
__vsprintf_l;

// address=[0x1352b80]
_sprintf;

// address=[0x1352bd0]
int __cdecl GetEvnInterfaceVersion(void);

// address=[0x1353b80]
void __cdecl SaveWindowsPositionAndSize(struct HWND__ *);

// address=[0x1353c30]
long __stdcall WndMsgProc(struct HWND__ *,unsigned int,unsigned int,long);

// address=[0x13568e0]
char * __cdecl strstr(char * const,char const * const);

// address=[0x1357310]
_WinMain@16;

// address=[0x1359410]
unsigned short __cdecl RegisterWindowClass(struct HINSTANCE__ *);

// address=[0x13594d0]
bool __cdecl ExistsExtractCommand(void);

// address=[0x1359940]
void __cdecl WriteIniFile(void);

// address=[0x1359be0]
void __cdecl ShowFingerprint(void);

// address=[0x1359d70]
void __cdecl ErrorMessageBox(char const *);

// address=[0x1359db0]
unsigned long __cdecl GetSystemLanguage(void);

// address=[0x135b9c0]
void __cdecl __vcrt_va_start_verify_argument_type<wchar_t const * const>(void);

// address=[0x1360e20]
int __cdecl swprintf(wchar_t * const,wchar_t const * const,...);

// address=[0x1360e70]
wchar_t * __cdecl wcsstr(wchar_t *,wchar_t const *);

// address=[0x1360ed0]
__vswprintf_c_l;

// address=[0x1360f50]
_vswprintf;

// address=[0x1360f80]
_wmemset;

// address=[0x136b250]
std::wstring __cdecl MapFilePaths::GetMapDirectoryPath(int);

// address=[0x136b340]
std::wstring __cdecl MapFilePaths::GetMapFilePatternOfDirectory(int);

// address=[0x136b3e0]
std::wstring __cdecl MapFilePaths::GetFilePathForMapName(std::wstring const &);

// address=[0x1372900]
void __cdecl UpdateGuiDlgAddSoldierBar(void);

// address=[0x1372d50]
bool __cdecl GuiDlgAddSoldierBarProc(int,int,int);

// address=[0x1373750]
void __cdecl UpdateGuiDlgAddStorageBar(void);

// address=[0x13737e0]
void __cdecl InitGuiDlgAddStorageBar(void);

// address=[0x1373e00]
bool __cdecl GuiDlgAddStorageBarProc(int,int,int);

// address=[0x1375e70]
unsigned int __cdecl S4HiWord(unsigned int);

// address=[0x1375e90]
unsigned int __cdecl S4LoWord(unsigned int);

// address=[0x1375ea0]
void __cdecl SetAmountToolBar(int,int);

// address=[0x1375f60]
void __cdecl UpdateGuiDlgAddToolBar(void);

// address=[0x1376000]
bool __cdecl GuiDlgAddToolBarProc(int,int,int);

// address=[0x1376800]
void __cdecl SetVehicleBuildCosts(int,bool);

// address=[0x13768c0]
void __cdecl SetAmountVehicleBar(int,int);

// address=[0x13769a0]
void __cdecl UpdateGuiDlgAddVehicleBar(void);

// address=[0x1376b50]
bool __cdecl GuiDlgAddVehicleBarProc(int,int,int);

// address=[0x13778b0]
void __cdecl InitGuiDlgAOBriefing(void);

// address=[0x13779b0]
bool __cdecl GuiDlgAOBriefingProc(int,int,int);

// address=[0x1377dd0]
void __cdecl InitGuiDlgAOCampaignBonus(void);

// address=[0x1377e40]
bool __cdecl GuiDlgAOCampaignBonusProc(int,int,int);

// address=[0x13780f0]
void __cdecl InitGuiDlgAOCampaignMayan(void);

// address=[0x1378240]
bool __cdecl GuiDlgAOCampaignMayanProc(int,int,int);

// address=[0x13786f0]
void __cdecl InitGuiDlgAOCampaignRoman(void);

// address=[0x1378840]
bool __cdecl GuiDlgAOCampaignRomanProc(int,int,int);

// address=[0x1378cf0]
void __cdecl InitGuiDlgAOCampaigns(void);

// address=[0x1378db0]
bool __cdecl GuiDlgAOCampaignsProc(int,int,int);

// address=[0x13793a0]
void __cdecl InitGuiDlgAOCampaignsSettle(void);

// address=[0x13794f0]
bool __cdecl GuiDlgAOCampaignsSettleProc(int,int,int);

// address=[0x13799a0]
void __cdecl InitGuiDlgAOCampaignTrojan(void);

// address=[0x1379d40]
bool __cdecl GuiDlgAOCampaignTrojanProc(int,int,int);

// address=[0x137a680]
void __cdecl InitGuiDlgAOCampaignViking(void);

// address=[0x137a7f0]
bool __cdecl GuiDlgAOCampaignVikingProc(int,int,int);

// address=[0x137aca0]
void __cdecl InitGuiDlgAOSplash(void);

// address=[0x137b0c0]
bool __cdecl GuiDlgAOSplashProc(int,int,int);

// address=[0x137b4a0]
void __cdecl UpdateGuiDlgAvailableGoods(void);

// address=[0x137b560]
void __cdecl InitGuiDlgAvailableGoods(void);

// address=[0x137b870]
bool __cdecl GuiDlgAvailableGoodsProc(int,int,int);

// address=[0x137bc40]
void __cdecl UpdateGuiDlgBarracksContext(void);

// address=[0x137c010]
bool __cdecl GuiDlgBarracksContextProc(int,int,int);

// address=[0x137c7d0]
void __cdecl InitGuiDlgWinLoss(void);

// address=[0x137c7e0]
bool __cdecl UpdateGuiDlgWinLoss(int);

// address=[0x137c850]
bool __cdecl GuiDlgWinLossProc(int,int,int);

// address=[0x137c9c0]
void __cdecl InitGuiDlgBriefing(void);

// address=[0x137ca20]
bool __cdecl GuiDlgBriefingProc(int,int,int);

// address=[0x137cb80]
void __cdecl SetBuildBasicProperties(int,int,int,int);

// address=[0x137cc20]
void __cdecl UpdateGuiDlgBuildBasic(void);

// address=[0x137ce30]
void __cdecl SetBasicBuildCosts(int,bool);

// address=[0x137cf20]
bool __cdecl GuiDlgBuildBasicProc(int,int,int);

// address=[0x137e530]
void __cdecl UpdateGuiDlgBuildContext(void);

// address=[0x137eaa0]
bool __cdecl GuiDlgBuildContextProc(int,int,int);

// address=[0x137f1d0]
void __cdecl SetEyecatcherProperties(int,int,int,int);

// address=[0x137f270]
void __cdecl SetEyecatcherBuildCosts(int,bool);

// address=[0x137f360]
void __cdecl UpdateGuiDlgBuildEyecatcher(void);

// address=[0x137f590]
bool __cdecl GuiDlgBuildEyecatcherProc(int,int,int);

// address=[0x1380ca0]
void __cdecl SetBuildFoodProperties(int,int,int,int);

// address=[0x1380d40]
void __cdecl UpdateGuiDlgBuildFood(void);

// address=[0x1381070]
void __cdecl SetFoodBuildCosts(int,bool);

// address=[0x1381160]
bool __cdecl GuiDlgBuildFoodProc(int,int,int);

// address=[0x1383820]
void __cdecl UpdateGuiDlgBuildingContext(void);

// address=[0x13839b0]
bool __cdecl GuiDlgBuildingContextProc(int,int,int);

// address=[0x1383d10]
void __cdecl SetBuildMetalProperties(int,int,int,int);

// address=[0x1383db0]
void __cdecl UpdateGuiDlgBuildMetal(void);

// address=[0x1383fb0]
void __cdecl SetMetalBuildCosts(int,bool);

// address=[0x13840a0]
bool __cdecl GuiDlgBuildMetalProc(int,int,int);

// address=[0x1385930]
void __cdecl SetBuildMilitaryProperties(int,int,int,int);

// address=[0x13859d0]
void __cdecl UpdateGuiDlgBuildMilitary(void);

// address=[0x1385bd0]
void __cdecl SetMilitaryBuildCosts(int,bool);

// address=[0x1385cc0]
bool __cdecl GuiDlgBuildMilitaryProc(int,int,int);

// address=[0x13872b0]
bool __cdecl GuiDlgBuildSubmenuProc(int,int,int);

// address=[0x1388490]
void __cdecl SetBuildTownProperties(int,int,int,int);

// address=[0x1388530]
void __cdecl UpdateGuiDlgBuildTown(void);

// address=[0x1388710]
void __cdecl SetTownBuildCosts(int,bool);

// address=[0x1388800]
bool __cdecl GuiDlgBuildTownProc(int,int,int);

// address=[0x138a580]
void __cdecl UpdateGuiDlgChat(void);

// address=[0x138a950]
bool __cdecl GuiDlgChatProc(int,int,int);

// address=[0x138b520]
void __cdecl GuiDlgClockSetCountdown(unsigned int);

// address=[0x138b560]
void __cdecl UpdateGuiDlgClock(unsigned int);

// address=[0x138b6a0]
bool __cdecl GuiDlgClockProc(int,int,int);

// address=[0x138b7a0]
void __cdecl InitGuiDlgEconomy(void);

// address=[0x138b810]
void __cdecl UpdateGuiDlgEconomy(void);

// address=[0x138ba10]
bool __cdecl GuiDlgEconomyProc(int,int,int);

// address=[0x138bc00]
void __cdecl UpdateGuiDlgFerryLoadContext(void);

// address=[0x138bd70]
bool __cdecl GuiDlgFerryLoadContextProc(int,int,int);

// address=[0x138c100]
bool __cdecl GuiDlgFiguresSubmenuProc(int,int,int);

// address=[0x138cb60]
void __cdecl UpdateGuiDlgFreeCarrierMenu(void);

// address=[0x138cf60]
bool __cdecl GuiDlgFreeCarrierMenuProc(int,int,int);

// address=[0x138d590]
void __cdecl GetGoodSliderVals(void);

// address=[0x138d640]
void __cdecl UpdateGuiDlgGoodDistribution(void);

// address=[0x138d8f0]
void __cdecl InitGuiDlgGoodDistribution(void);

// address=[0x138d970]
bool __cdecl GuiDlgGoodDistributionProc(int,int,int);

// address=[0x138e1f0]
void __cdecl GoodsoutBarDisplaySubmenu(void);

// address=[0x138e360]
void __cdecl UpdateGuiDlgGoodsoutBar(void);

// address=[0x138e630]
void __cdecl InitGuiDlgGoodsoutBar(void);

// address=[0x138f080]
void __cdecl GoodsoutBarGoodSelected(int);

// address=[0x138f0e0]
bool __cdecl GuiDlgGoodsoutBarProc(int,int,int);

// address=[0x138fca0]
void __cdecl UpdateGuiDlgGoodstradeBar(void);

// address=[0x1390020]
void __cdecl GoodstradeBarDisplaySubmenu(void);

// address=[0x1390180]
void __cdecl InitGuiDlgGoodstradeBar(void);

// address=[0x1390bc0]
void __cdecl GoodstradeBarGoodSelected(int);

// address=[0x1390ca0]
bool __cdecl GuiDlgGoodstradeBarProc(int,int,int);

// address=[0x1391a40]
void __cdecl UpdateGuiDlgGroup(void);

// address=[0x1391bc0]
bool __cdecl GuiDlgGroupProc(int,int,int);

// address=[0x1392c60]
bool __cdecl GuiDlgIncomingMessageProc(int,int,int);

// address=[0x1392ee0]
void __cdecl GuiDlgLanLobbyJoingame(int);

// address=[0x1392f90]
void __cdecl GuiDlgLanLobbyConnectFillList(void);

// address=[0x13934c0]
void __cdecl GuiDlgLanLobbyConnectUpdate(void);

// address=[0x13935f0]
void __cdecl InitGuiDlgLanLobbyConnect(void);

// address=[0x1393720]
bool __cdecl GuiDlgLanLobbyConnectMenuProc(int,int,int);

// address=[0x1393fd0]
void __cdecl InitGuiDlgLoadSave(void);

// address=[0x13941e0]
void __cdecl GuiDlgLoadSaveUpdateProgress(int);

// address=[0x1394250]
void __cdecl GuiDlgLoadSaveNameSelected(int);

// address=[0x1394370]
void __cdecl GuiDlgLoadSaveFillList(void);

// address=[0x1394530]
void __cdecl UpdateGuiDlgLoadSave(void);

// address=[0x1394550]
bool __cdecl GuiDlgLoadSaveProc(int,int,int);

// address=[0x1395070]
_wmemcmp;

// address=[0x13950f0]
bool __cdecl GuiDlgLoadSaveSubmenuProc(int,int,int);

// address=[0x1395990]
void __cdecl UpdateGuiDlgMagicSpellBar(void);

// address=[0x1395be0]
bool __cdecl GuiDlgMagicSpellBarProc(int,int,int);

// address=[0x13966b0]
void __cdecl InitGuiDlgMain3x3Campaign(void);

// address=[0x1396950]
bool __cdecl GuiDlgMain3x3CampaignProc(int,int,int);

// address=[0x13970b0]
void __cdecl InitGuiDlgMainBarExt1(void);

// address=[0x13971c0]
void __cdecl UpdateGuiDlgMainBarExt1(void);

// address=[0x13973e0]
bool __cdecl GuiDlgMainBarExt1Proc(int,int,int);

// address=[0x1397600]
void __cdecl InitGuiDlgMainBarExt2(void);

// address=[0x1397650]
bool __cdecl GuiDlgMainBarExt2Proc(int,int,int);

// address=[0x1397b60]
void __cdecl InitGuiDlgMainBriefing(void);

// address=[0x1397c70]
bool __cdecl GuiDlgMainBriefingProc(int,int,int);

// address=[0x1398150]
void __cdecl GuiDlgMainCreditsInitText(void);

// address=[0x13983a0]
bool __cdecl GuiDlgMainCreditsBottomProc(int,int,int);

// address=[0x13983b0]
bool __cdecl GuiDlgMainCreditsTopProc(int,int,int);

// address=[0x13983c0]
bool __cdecl GuiDlgMainCreditsPaperProc(int,int,int);

// address=[0x1398420]
int __cdecl ConvertXCoord(int,struct SGuiRect const &);

// address=[0x1398480]
int __cdecl ConvertYCoord(int,struct SGuiRect const &);

// address=[0x13984e0]
void __cdecl ApplyCreditYPosToDialogs(void);

// address=[0x13985d0]
void __cdecl UpdateGuiDlgMainCredits(void);

// address=[0x1398700]
bool __cdecl GuiDlgMainCreditsProc(int,int,int);

// address=[0x13989d0]
void __cdecl InitGuiDlgMainDarktribeCampaign(void);

// address=[0x1398d50]
bool __cdecl GuiDlgMainDarktribeCampaignProc(int,int,int);

// address=[0x1399650]
void __cdecl GuiDlgDeteilStatisticFillList(void);

// address=[0x1399790]
void __cdecl InitGuiDlgMainDetailStatistic(void);

// address=[0x1399830]
void __cdecl UpdateGuiDlgMainDetailStatistic(int);

// address=[0x139b890]
bool __cdecl GuiDlgMainDetailStatisticProc(int,int,int);

// address=[0x13a05a0]
void __cdecl GuiDlgMainGameSettingsAddChatline(char const *);

// address=[0x13a05e0]
void __cdecl GuiDlgMainGameSettingsUpdateChangeSlot(int);

// address=[0x13a0840]
void __cdecl GuiDlgMainGameSettingstUpdate(void);

// address=[0x13a1af0]
void __cdecl InitGuiDlgMainGameSettings(void);

// address=[0x13a1eb0]
bool __cdecl GuiDlgMainGameSettingsProc(int,int,int);

// address=[0x13a4270]
void __cdecl GuiDlgLoadFillList(void);

// address=[0x13a4520]
void __cdecl HighlightEntryDlgMainLoad(int,int,bool);

// address=[0x13a45b0]
void __cdecl InitGuiDlgMainLoad(void);

// address=[0x13a45f0]
bool __cdecl GuiDlgMainLoadProc(int,int,int);

// address=[0x13a4ec0]
void __cdecl InitGuiDlgMainLoadType(void);

// address=[0x13a4f60]
bool __cdecl GuiDlgMainLoadTypeProc(int,int,int);

// address=[0x13a5340]
void __cdecl InitGuiDlgMainLocalType(void);

// address=[0x13a53f0]
bool __cdecl GuiDlgMainLocalTypeProc(int,int,int);

// address=[0x13a5820]
void __cdecl GuiDlgMapSettingsFillPlayerTeams(void);

// address=[0x13a58c0]
void __cdecl GuiDlgMapSettingsFillList(void);

// address=[0x13a5f00]
void __cdecl GuiDlgMapSettingsMapSelect(int);

// address=[0x13a5fb0]
void __cdecl GuiDlgMapSettingsUpdate(void);

// address=[0x13a63a0]
void __cdecl InitGuiDlgMainMapSettings(void);

// address=[0x13a6a40]
bool __cdecl GuiDlgMainMapSettingsProc(int,int,int);

// address=[0x13a8550]
void __cdecl InitGuiDlgMainMessageBox(void);

// address=[0x13a85e0]
bool __cdecl GuiDlgMainMessageBoxProc(int,int,int);

// address=[0x13a8810]
bool __cdecl GuiDlgMainscreenProc(int,int,int);

// address=[0x13a8ea0]
void __cdecl InitGuiDlgMainscreen(void);

// address=[0x13abf50]
void __cdecl InitGuiDlgMainSplash(void);

// address=[0x13abfd0]
bool __cdecl GuiDlgMainSplashProc(int,int,int);

// address=[0x13ac140]
void __cdecl InitGuiDlgMainStatisticDisplayMode(void);

// address=[0x13ac860]
void __cdecl InitGuiDlgMainStatistic(void);

// address=[0x13ad050]
bool __cdecl GuiDlgMainStatisticProc(int,int,int);

// address=[0x13ade30]
wchar_t * __cdecl wcschr(wchar_t *,wchar_t);

// address=[0x13ade50]
unsigned int __cdecl GetGuiGoodImage(enum PILE_TYPES);

// address=[0x13ae150]
void __cdecl InitGuiDlgMainStatisticEcoDisplayMode(void);

// address=[0x13af240]
void __cdecl InitGuiDlgMainStatisticEco(void);

// address=[0x13af260]
bool __cdecl GuiDlgMainStatisticEcoProc(int,int,int);

// address=[0x13afcf0]
wchar_t * __cdecl wcsrchr(wchar_t *,wchar_t);

// address=[0x13afd10]
void __cdecl InitGuiDlgMainTutorial(void);

// address=[0x13aff60]
bool __cdecl GuiDlgMainTutorialProc(int,int,int);

// address=[0x13b0a00]
void __cdecl InitGuiDlgMD2Briefing(void);

// address=[0x13b0b10]
bool __cdecl GuiDlgMD2BriefingProc(int,int,int);

// address=[0x13b0f30]
void __cdecl InitGuiDlgMD2Campaigns(void);

// address=[0x13b15b0]
bool __cdecl GuiDlgMD2CampaignsProc(int,int,int);

// address=[0x13b23e0]
void __cdecl InitGuiDlgMDBriefing(void);

// address=[0x13b24f0]
bool __cdecl GuiDlgMDBriefingProc(int,int,int);

// address=[0x13b2910]
void __cdecl InitGuiDlgMDCampaignMayan(void);

// address=[0x13b2ae0]
bool __cdecl GuiDlgMDCampaignMayanProc(int,int,int);

// address=[0x13b3050]
void __cdecl InitGuiDlgMDCampaignRoman(void);

// address=[0x13b3220]
bool __cdecl GuiDlgMDCampaignRomanProc(int,int,int);

// address=[0x13b3790]
void __cdecl InitGuiDlgMDCampaigns(void);

// address=[0x13b3880]
bool __cdecl GuiDlgMDCampaignsProc(int,int,int);

// address=[0x13b3de0]
void __cdecl InitGuiDlgMDCampaignsEcoConflict(void);

// address=[0x13b3ff0]
bool __cdecl GuiDlgMDCampaignsEcoConflictProc(int,int,int);

// address=[0x13b45d0]
void __cdecl InitGuiDlgMDCampaignViking(void);

// address=[0x13b47a0]
bool __cdecl GuiDlgMDCampaignVikingProc(int,int,int);

// address=[0x13b4cf0]
void __cdecl GuiDlgMDRandomMapParametersFillPlayerTeams(void);

// address=[0x13b4e60]
void __cdecl GuiDlgMDRandomMapParametersUpdate(void);

// address=[0x13b5d80]
void __cdecl InitGuiDlgMDRandomMapParameters(void);

// address=[0x13b6490]
bool __cdecl GuiDlgMDRandomMapParametersProc(int,int,int);

// address=[0x13b8be0]
void __cdecl UpdateGuiDlgMessages(class CEvn_Event *);

// address=[0x13b8d40]
void __cdecl InitGuiDlgMessages(void);

// address=[0x13b8ea0]
bool __cdecl OpenChatentry(void);

// address=[0x13b8fd0]
bool __cdecl CloseChatentry(void);

// address=[0x13b9130]
void __cdecl HighlightEntryDlgMessages(int,bool);

// address=[0x13b9290]
bool __cdecl GuiDlgMessagesProc(int,int,int);

// address=[0x13b9e90]
bool __cdecl operator!=(class String const &,char const *);

// address=[0x13b9f30]
void __cdecl UpdateGuiDlgMilitaryBuildingContext(void);

// address=[0x13bb6c0]
bool __cdecl GuiDlgMilitaryBuildingContextProc(int,int,int);

// address=[0x13bcc70]
void __cdecl MinimpapResetOpenDialogs(void);

// address=[0x13bccb0]
void __cdecl UpdateGuiDlgMinimap(int);

// address=[0x13bcd70]
void __cdecl InitGuiDlgMinimap(void);

// address=[0x13bcd80]
bool __cdecl GuiDlgMinimapProc(int,int,int);

// address=[0x13bdd30]
void __cdecl InitGuiDlgMultiplayerType(void);

// address=[0x13bdd70]
bool __cdecl GuiDlgMultiplayerTypeMenuProc(int,int,int);

// address=[0x13be010]
bool __cdecl GuiDlgOptionsSubmenuProc(int,int,int);

// address=[0x13be6b0]
void __cdecl UpdateGuiDlgPortContext(void);

// address=[0x13bea80]
bool __cdecl GuiDlgPortContextProc(int,int,int);

// address=[0x13bf3c0]
bool __cdecl GuiDlgProductionSubmenuProc(int,int,int);

// address=[0x13bf880]
void __cdecl InitGuiDlgQuitGame(void);

// address=[0x13bf8c0]
bool __cdecl GuiDlgQuitGameProc(int,int,int);

// address=[0x13bfb60]
void __cdecl UpdateGuiDlgResourceCollectorContext(void);

// address=[0x13bfe50]
bool __cdecl GuiDlgResourceCollectorContextProc(int,int,int);

// address=[0x13c03b0]
unsigned int __cdecl GetGuiHouseImageID(int,enum BUILDING_TYPES,bool);

// address=[0x13c2c70]
unsigned int __cdecl GetGuiHouseButtonID(int,enum BUILDING_TYPES);

// address=[0x13c3310]
unsigned int __cdecl GetGuiGoodImageID(enum PILE_TYPES);

// address=[0x13c3610]
char const * __cdecl GetGuiHouseString(int,enum BUILDING_TYPES);

// address=[0x13c4bf0]
void __cdecl UpdateGuiDlgResourceUpgradeContext(void);

// address=[0x13c5220]
bool __cdecl GuiDlgResourceUpgradeContextProc(int,int,int);

// address=[0x13c5a20]
void __cdecl UpdateGuiDlgSettingsGame(void);

// address=[0x13c5b40]
void __cdecl InitGuiDlgSettingsGame(void);

// address=[0x13c5c70]
bool __cdecl GuiDlgSettingsGameProc(int,int,int);

// address=[0x13c6260]
void __cdecl UpdateGuiDlgSettingsGraphic(void);

// address=[0x13c6530]
void __cdecl InitGuiDlgSettingsGraphic(void);

// address=[0x13c67a0]
bool __cdecl GuiDlgSettingsGraphicProc(int,int,int);

// address=[0x13c6d00]
void __cdecl UpdateGuiDlgSettingsMessages(void);

// address=[0x13c7030]
void __cdecl InitGuiDlgSettingsMessages(void);

// address=[0x13c72a0]
bool __cdecl GuiDlgSettingsMessagesProc(int,int,int);

// address=[0x13c82a0]
void __cdecl UpdateGuiDlgSettingsSound(void);

// address=[0x13c83c0]
void __cdecl InitGuiDlgSettingsSound(void);

// address=[0x13c84e0]
bool __cdecl GuiDlgSettingsSoundProc(int,int,int);

// address=[0x13c8fa0]
void __cdecl InitGuiDlgSettlerFindMenu(void);

// address=[0x13c9000]
bool __cdecl GuiDlgSettlerFindMenuProc(int,int,int);

// address=[0x13c9580]
void __cdecl SetAmountGuiDlgSettlerProductionMenu(int,int,int,int,int,int,int,int);

// address=[0x13c9680]
void __cdecl UpdateGuiDlgSettlerProductionMenu(void);

// address=[0x13c99d0]
void __cdecl InitGuiDlgSettlerProductionMenu(void);

// address=[0x13c9ab0]
bool __cdecl GuiDlgSettlerProductionMenuProc(int,int,int);

// address=[0x13ca140]
void __cdecl UpdateGuiDlgSettlerStatisticMenu(void);

// address=[0x13ca340]
bool __cdecl GuiDlgSettlerStatisticMenuProc(int,int,int);

// address=[0x13ca690]
void __cdecl UpdateGuiDlgShipVehicleContext(void);

// address=[0x13cab80]
bool __cdecl GuiDlgShipVehicleContextProc(int,int,int);

// address=[0x13cb2f0]
void __cdecl UpdateGuiDlgSmallTempleContext(void);

// address=[0x13cb5f0]
bool __cdecl GuiDlgSmallTempleContextProc(int,int,int);

// address=[0x13cbac0]
void __cdecl SetSoldierProperties(struct SHealthState *,int,int);

// address=[0x13cbbb0]
void __cdecl UpdateGuiDlgSoldierContext(void);

// address=[0x13cbeb0]
bool __cdecl GuiDlgSoldierContextProc(int,int,int);

// address=[0x13cc770]
void __cdecl PlayGuiSound(int);

// address=[0x13cc7a0]
void __cdecl SetSpecialistProperties(struct SHealthState *,int,int);

// address=[0x13cc880]
void __cdecl UpdateGuiDlgSpecialistsContext(void);

// address=[0x13cc910]
bool __cdecl GuiDlgSpecialistsContextProc(int,int,int);

// address=[0x13cce00]
void __stdcall LineCallbackGoods(int,int,long);

// address=[0x13cce40]
void __cdecl InitMaxvalueGoods(void);

// address=[0x13cceb0]
void __cdecl DrawGoodsGrid(void);

// address=[0x13ccf60]
void __cdecl DrawGoodsGraph(void);

// address=[0x13cdac0]
void __cdecl UpdateGuiDlgStatisticGoods(void);

// address=[0x13cdad0]
void __cdecl InitGuiDlgStatisticGoods(void);

// address=[0x13cdb30]
void __cdecl InitGoodsRange(void);

// address=[0x13cdd10]
bool __cdecl GuiDlgStatisticGoodsProc(int,int,int);

// address=[0x13ced20]
void __stdcall LineCallbackLand(int,int,long);

// address=[0x13ced60]
void __cdecl InitMaxvalue(void);

// address=[0x13cedd0]
void __cdecl DrawLandGrid(void);

// address=[0x13cee80]
void __cdecl DrawLandGraph(void);

// address=[0x13cfb30]
void __cdecl UpdateGuiDlgStatisticLand(void);

// address=[0x13cfb40]
void __cdecl InitGuiDlgStatisticLand(void);

// address=[0x13d00a0]
void __cdecl InitLandRange(void);

// address=[0x13d0280]
bool __cdecl GuiDlgStatisticLandProc(int,int,int);

// address=[0x13d12d0]
bool __cdecl GuiDlgStatisticSubmenuProc(int,int,int);

// address=[0x13d1750]
void __stdcall LineCallback(int,int,long);

// address=[0x13d1790]
void __cdecl InitMaxvalueWarrior(void);

// address=[0x13d1800]
void __cdecl DrawGrid(void);

// address=[0x13d18b0]
void __cdecl DrawGraph(void);

// address=[0x13d2560]
void __cdecl UpdateGuiDlgStatisticWarrior(void);

// address=[0x13d2570]
void __cdecl InitGuiDlgStatisticWarrior(void);

// address=[0x13d2ae0]
void __cdecl InitWarriorRange(void);

// address=[0x13d2cc0]
bool __cdecl GuiDlgStatisticWarriorProc(int,int,int);

// address=[0x13d3cc0]
void __cdecl UpdateGuiDlgStorageContext(void);

// address=[0x13d4060]
bool __cdecl GuiDlgStorageContextProc(int,int,int);

// address=[0x13d4700]
void __cdecl UpdateGuiDlgTransportpriority(void);

// address=[0x13d4870]
void __cdecl InitGuiDlgTransportpriority(void);

// address=[0x13d48c0]
bool __cdecl GuiDlgTransportpriorityProc(int,int,int);

// address=[0x13d5550]
void __cdecl InitGuiDlgTutorial(void);

// address=[0x13d5620]
void __cdecl HighlightEntryDlgTutorialMessages(int,bool);

// address=[0x13d5670]
bool __cdecl GuiDlgTutorialProc(int,int,int);

// address=[0x13d5a20]
void __cdecl UpdateGuiDlgTutorialCursor(void);

// address=[0x13d5ad0]
void __cdecl InitGuiDlgTutorialCursor(void);

// address=[0x13d5af0]
bool __cdecl GuiDlgTutorialCursorProc(int,int,int);

// address=[0x13d5c10]
void __cdecl UpdateGuiDlgVehicleLoadContext(void);

// address=[0x13d61e0]
bool __cdecl GuiDlgVehicleLoadContextProc(int,int,int);

// address=[0x13d6810]
void __cdecl UpdateGuiDlgVehiclesContext(void);

// address=[0x13d69e0]
void __cdecl InitGuiDlgVehiclesContext(void);

// address=[0x13d6a20]
bool __cdecl GuiDlgVehiclesContextProc(int,int,int);

// address=[0x13d7020]
void __cdecl GetSliderVals(void);

// address=[0x13d71c0]
void __cdecl SetAmountWeaponsmithBar(int,int);

// address=[0x13d72a0]
void __cdecl UpdateGuiDlgWeaponsmithBar(void);

// address=[0x13d7570]
bool __cdecl GuiDlgWeaponsmithBarProc(int,int,int);

// address=[0x13d8c30]
void __cdecl InitGuiDlgXMD3Briefing(void);

// address=[0x13d8d10]
bool __cdecl GuiDlgXMD3BriefingProc(int,int,int);

// address=[0x13d9210]
void __cdecl InitGuiDlgXMD3Campaigns(void);

// address=[0x13d9270]
bool __cdecl GuiDlgXMD3CampaignsProc(int,int,int);

// address=[0x13d9ce0]
__tcsncpy_s;

// address=[0x13d9d20]
void __cdecl InitGuiDlgYesNo(void);

// address=[0x13d9dc0]
bool __cdecl GuiDlgYesNoProc(int,int,int);

// address=[0x13e42d0]
public: __thiscall cdm_crc::CRCGenerator<16,32773,0,0,1,1>::CRCGenerator<16,32773,0,0,1,1>(void);

// address=[0x13e6450]
private: static unsigned long __cdecl cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Bitmask(int);

// address=[0x13e6560]
public: unsigned long __thiscall cdm_crc::CRCGenerator<16,32773,0,0,1,1>::GetCRC(void)const;

// address=[0x13e65b0]
public: unsigned long __thiscall cdm_crc::CRCGenerator<16,32773,0,0,1,1>::GetNormalCRC(void)const;

// address=[0x13e6650]
public: int __thiscall cdm_crc::CRCGenerator<16,32773,0,0,1,1>::GetWidth(void)const;

// address=[0x13e6670]
public: void __thiscall cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process(unsigned char);

// address=[0x13e67a0]
public: void __thiscall cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process(unsigned char *,int);

// address=[0x13e6800]
private: static unsigned long __cdecl cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Reflect(unsigned long,int);

// address=[0x13e68b0]
private: static unsigned long __cdecl cdm_crc::CRCGenerator<16,32773,0,0,1,1>::WidthMask(int);

// address=[0x13ee6d0]
std::istream & __cdecl operator^<signed char>(std::istream &,signed char &);

// address=[0x13ee6f0]
std::istream & __cdecl operator^<char>(std::istream &,char &);

// address=[0x13ee710]
std::istream & __cdecl operator^<unsigned char>(std::istream &,unsigned char &);

// address=[0x13ee730]
std::istream & __cdecl operator^<short>(std::istream &,short &);

// address=[0x13ee750]
std::istream & __cdecl operator^<unsigned short>(std::istream &,unsigned short &);

// address=[0x13ee770]
std::istream & __cdecl operator^<int>(std::istream &,int &);

// address=[0x13ee790]
std::istream & __cdecl operator^<unsigned int>(std::istream &,unsigned int &);

// address=[0x13ee7b0]
std::istream & __cdecl operator^<unsigned long>(std::istream &,unsigned long &);

// address=[0x13ee7d0]
std::ostream & __cdecl operator^<unsigned long>(std::ostream &,unsigned long const &);

// address=[0x13ee7f0]
std::istream & __cdecl operator^<float>(std::istream &,float &);

// address=[0x13ee810]
std::istream & __cdecl operator^<double>(std::istream &,double &);

// address=[0x13ee830]
std::istream & __cdecl operator^<std::string >(std::istream &,std::string &);

// address=[0x13ee850]
std::istream & __cdecl operator^<bool>(std::istream &,bool &);

// address=[0x13ee870]
void __cdecl Serial::Serialize<int>(std::istream &,int &);

// address=[0x13ee890]
void __cdecl Serial::Serialize<unsigned int>(std::istream &,unsigned int &);

// address=[0x13f5350]
void __cdecl Serial::Serialize(std::istream &,signed char &);

// address=[0x13f5380]
void __cdecl Serial::Serialize(std::istream &,unsigned char &);

// address=[0x13f53b0]
void __cdecl Serial::Serialize(std::istream &,short &);

// address=[0x13f53d0]
void __cdecl Serial::Serialize(std::istream &,unsigned short &);

// address=[0x13f53f0]
void __cdecl Serial::Serialize(std::istream &,unsigned long &);

// address=[0x13f5410]
void __cdecl Serial::Serialize(std::istream &,float &);

// address=[0x13f5560]
void __cdecl Serial::Serialize(std::istream &,double &);

// address=[0x13f5580]
void __cdecl Serial::Serialize(std::istream &,bool &);

// address=[0x13f55a0]
void __cdecl Serial::Serialize(std::ostream &,unsigned long const &);

// address=[0x13ff0a0]
__vsprintf_s_l;

// address=[0x13ff100]
_fabsl;

// address=[0x13ff120]
_frexpl;

// address=[0x13ff150]
_ldexpf;

// address=[0x13ff180]
_ldexpl;

// address=[0x13ff1b0]
_powf;

// address=[0x13ff1f0]
_sprintf_s;

// address=[0x13ff240]
void __cdecl RegisterClasses(void);

// address=[0x1402ac0]
void __cdecl Serial::Serialize(std::ostream &,char,char);

// address=[0x1402b90]
void __cdecl Serial::Serialize(std::ostream &,char const * &);

// address=[0x1402c00]
void __cdecl Serial::Serialize(std::ostream &,std::string const &);

// address=[0x1402c80]
bool __cdecl Serial::Serialize(std::istream &,char &,bool);

// address=[0x1402e20]
void __cdecl Serial::Serialize(std::istream &,std::string &);

// address=[0x140e460]
std::ostream & __cdecl operator^<int>(std::ostream &,int const &);

// address=[0x140e480]
std::ostream & __cdecl operator^<unsigned int>(std::ostream &,unsigned int const &);

// address=[0x140e4a0]
void __cdecl Serial::Serialize<int>(std::ostream &,int const &);

// address=[0x140e4e0]
void __cdecl Serial::Serialize<unsigned int>(std::ostream &,unsigned int const &);

// address=[0x14147e0]
public: __thiscall TStaticConfigIntArray<6>::TStaticConfigIntArray<6>(char const *,char const *,int,int,int,int,int,int);

// address=[0x14148a0]
private: __thiscall TStaticConfigIntArrayBase<6>::TStaticConfigIntArrayBase<6>(char const *,char const *);

// address=[0x1415250]
public: virtual __thiscall TStaticConfigIntArray<6>::~TStaticConfigIntArray<6>(void);

// address=[0x1415270]
public: virtual __thiscall TStaticConfigIntArrayBase<6>::~TStaticConfigIntArrayBase<6>(void);

// address=[0x1417130]
public: virtual int * __thiscall TStaticConfigIntArrayBase<6>::GetIntArray(void);

// address=[0x1417150]
public: virtual int const * __thiscall TStaticConfigIntArrayBase<6>::GetIntArray(void)const;

// address=[0x141db20]
int __cdecl Grid::TurnLeft(int);

// address=[0x141db60]
int __cdecl Grid::TurnRight(int);

// address=[0x14258b0]
public: __thiscall TDestructor<class CDefineTranslator>::TDestructor<class CDefineTranslator>(class CDefineTranslator *,class CDestructionPhase);

// address=[0x14269a0]
public: virtual void __thiscall TDestructor<class CDefineTranslator>::Destroy(void);

// address=[0x14326b0]
std::ostream & __cdecl operator^<signed char>(std::ostream &,signed char const &);

// address=[0x14326d0]
std::ostream & __cdecl operator^<unsigned char>(std::ostream &,unsigned char const &);

// address=[0x14326f0]
std::ostream & __cdecl operator^<short>(std::ostream &,short const &);

// address=[0x1432720]
std::ostream & __cdecl operator^<unsigned short>(std::ostream &,unsigned short const &);

// address=[0x1432750]
std::istream & __cdecl LoadArray<signed char>(std::istream &,signed char * const,unsigned int);

// address=[0x1432940]
std::istream & __cdecl LoadArray<unsigned short>(std::istream &,unsigned short * const,unsigned int);

// address=[0x1432b60]
std::istream & __cdecl LoadVector<unsigned short>(std::istream &,class std::vector<unsigned short,class std::allocator<unsigned short> > &);

// address=[0x1432c10]
std::ostream & __cdecl StoreArray<signed char>(std::ostream &,signed char const * const,unsigned int);

// address=[0x1432ca0]
std::ostream & __cdecl StoreArray<unsigned short>(std::ostream &,unsigned short const * const,unsigned int);

// address=[0x1432d30]
std::ostream & __cdecl StoreVector<unsigned short>(std::ostream &,class std::vector<unsigned short,class std::allocator<unsigned short> > &);

// address=[0x1439c20]
unsigned int __cdecl Serial::LoadVersion(std::istream &);

// address=[0x1439d10]
void __cdecl Serial::Serialize(std::ostream &,signed char const &);

// address=[0x1439d50]
void __cdecl Serial::Serialize(std::ostream &,unsigned char const &);

// address=[0x1439d90]
void __cdecl Serial::Serialize(std::ostream &,short);

// address=[0x1439dd0]
void __cdecl Serial::Serialize(std::ostream &,unsigned short);

// address=[0x1439f50]
void __cdecl Serial::StoreVersion(std::ostream &,unsigned int);

// address=[0x1445fd0]
std::istream & __cdecl LoadArray<int>(std::istream &,int * const,unsigned int);

// address=[0x14461f0]
int const & __cdecl BB::Max<int>(int const &,int const &);

// address=[0x1446230]
std::ostream & __cdecl StoreArray<int>(std::ostream &,int const * const,unsigned int);

// address=[0x144f800]
float __cdecl sqrt(float);

// address=[0x144f820]
_sqrtf;

// address=[0x1454030]
std::ostream & __cdecl operator^<bool>(std::ostream &,bool const &);

// address=[0x1454200]
___insecure_wcscpy;

// address=[0x1454280]
void __cdecl Serial::Serialize(std::ostream &,bool);

// address=[0x145daf0]
int __cdecl sign(int);

// address=[0x145fe50]
int const & __cdecl BB::Min<int>(int const &,int const &);

// address=[0x1460380]
public: void __thiscall TSparseMap<unsigned char>::Clear(void);

// address=[0x1460510]
public: unsigned char __thiscall TSparseMap<unsigned char>::Get(unsigned int,unsigned int);

// address=[0x1460700]
private: bool __thiscall TSparseMap<unsigned char>::IsValidCoordinate(unsigned int,unsigned int)const;

// address=[0x1460800]
public: void __thiscall TSparseMap<unsigned char>::Set(unsigned int,unsigned int,unsigned char const &);

// address=[0x1470380]
public: __thiscall TStaticConfigIntArray<8>::TStaticConfigIntArray<8>(char const *,char const *,int,int,int,int,int,int,int,int);

// address=[0x1470470]
private: __thiscall TStaticConfigIntArrayBase<8>::TStaticConfigIntArrayBase<8>(char const *,char const *);

// address=[0x14705b0]
public: virtual __thiscall TStaticConfigIntArray<8>::~TStaticConfigIntArray<8>(void);

// address=[0x14705d0]
public: virtual __thiscall TStaticConfigIntArrayBase<8>::~TStaticConfigIntArrayBase<8>(void);

// address=[0x14705f0]
public: int & __thiscall TStaticConfigIntArrayBase<8>::operator[](int);

// address=[0x1470610]
public: int const & __thiscall TStaticConfigIntArrayBase<8>::operator[](int)const;

// address=[0x14709a0]
public: virtual int * __thiscall TStaticConfigIntArrayBase<8>::GetIntArray(void);

// address=[0x14709c0]
public: virtual int const * __thiscall TStaticConfigIntArrayBase<8>::GetIntArray(void)const;

// address=[0x147e550]
public: bool __thiscall TBitArray<22>::operator[](unsigned int);

// address=[0x147e5a0]
public: bool __thiscall TBitArray<78>::operator[](unsigned int);

// address=[0x147e5f0]
public: bool __thiscall TBitArray<2956>::operator[](unsigned int);

// address=[0x147e640]
public: void __thiscall TBitArray<2956>::Clear(unsigned int);

// address=[0x147e690]
public: void __thiscall TBitArray<22>::ClearArray(void);

// address=[0x147e6c0]
public: void __thiscall TBitArray<78>::ClearArray(void);

// address=[0x147e6f0]
public: void __thiscall TBitArray<2956>::ClearArray(void);

// address=[0x147e8c0]
public: void __thiscall TBitArray<22>::Set(unsigned int);

// address=[0x147e900]
public: void __thiscall TBitArray<78>::Set(unsigned int);

// address=[0x147e940]
public: void __thiscall TBitArray<2956>::Set(unsigned int);

// address=[0x147e980]
public: void __thiscall TBitArray<2956>::SetArray(void);

// address=[0x147e9b0]
public: void __thiscall TBitArray<2956>::SetValue(unsigned int,bool);

// address=[0x147f2f0]
bool __cdecl S4CheckGfx(int);

// address=[0x1481410]
bool __cdecl ExtraCD::IsGermanOnlyContentEnabled(void);

// address=[0x1485340]
void __cdecl SetCamWndViewPosition(void);

// address=[0x14859b0]
void __cdecl UpdateReefBlockingBits(void);

// address=[0x14868c0]
public: __thiscall CRingBuffer<class CEvn_Logic>::CRingBuffer<class CEvn_Logic>(int);

// address=[0x1486a80]
public: virtual __thiscall CRingBuffer<class CEvn_Logic>::~CRingBuffer<class CEvn_Logic>(void);

// address=[0x1486d70]
public: virtual bool __thiscall CRingBuffer<class CEvn_Logic>::Check(void)const;

// address=[0x1486db0]
public: virtual bool __thiscall CRingBuffer<class CEvn_Logic>::CheckVirtual(void)const;

// address=[0x1487220]
public: virtual class CEvn_Logic & __thiscall CRingBuffer<class CEvn_Logic>::Read(void);

// address=[0x1487280]
public: virtual class CEvn_Logic & __thiscall CRingBuffer<class CEvn_Logic>::ReadVirtual(void);

// address=[0x14875c0]
public: virtual void __thiscall CRingBuffer<class CEvn_Logic>::StartVirtual(void);

// address=[0x14875e0]
public: virtual bool __thiscall CRingBuffer<class CEvn_Logic>::Write(class CEvn_Logic &);

// address=[0x148a890]
void __cdecl ChangeScreenSize(int,int);

// address=[0x14944c0]
unsigned char * __cdecl _mbsstr(unsigned char * const,unsigned char const * const);

// address=[0x1497120]
char * __cdecl MyStrNCopy(char *,char const *,unsigned int);

// address=[0x14971c0]
wchar_t * __cdecl MyWStrNCopy(wchar_t *,wchar_t const *,unsigned int);

// address=[0x149a3d0]
void __cdecl DecodeMapKey(struct SRandomMapParams *,wchar_t *);

// address=[0x149a5e0]
void __cdecl GenerateMapKey(struct SRandomMapParams *,wchar_t *);

// address=[0x149a7c0]
bool __cdecl IsValidMapKey(wchar_t *);

// address=[0x14a8b70]
int __stdcall DlgProc(struct HWND__ *,unsigned int,unsigned int,long);

// address=[0x14b4db0]
long __cdecl abs(long);

// address=[0x14c07b0]
_swprintf;

// address=[0x14c3080]
_wmemchr;

// address=[0x14d15c0]
void __cdecl __vcrt_va_start_verify_argument_type<bool>(void);

// address=[0x14d8770]
int __cdecl Y16X16::NeighborModifier(int);

// address=[0x14e7ab0]
int __cdecl SettlerTypePrioLevel(int);

// address=[0x14e7b40]
int __cdecl SettlerTypePrioClass(int);

// address=[0x14f3930]
public: class AdvXMLParser::Element const & __thiscall AdvXMLParser::ConstIterator<class AdvXMLParser::Element>::operator*(void)const;

// address=[0x14f3ab0]
public: struct AdvXMLParser::ConstIterator<class AdvXMLParser::Element> & __thiscall AdvXMLParser::ConstIterator<class AdvXMLParser::Element>::operator++(void);

// address=[0x14f3da0]
private: void __thiscall AdvXMLParser::ConstIterator<class AdvXMLParser::Element>::FirstValid(void);

// address=[0x1506110]
std::ostream & __cdecl operator^<float>(std::ostream &,float const &);

// address=[0x1506670]
void __cdecl Serial::Serialize(std::ostream &,float);

// address=[0x1516000]
std::ostream & __cdecl operator^<char>(std::ostream &,char const &);

// address=[0x151f680]
std::istream & __cdecl LoadArray<unsigned char>(std::istream &,unsigned char * const,unsigned int);

// address=[0x151f870]
std::ostream & __cdecl StoreArray<unsigned char>(std::ostream &,unsigned char const * const,unsigned int);

// address=[0x1536260]
std::istream & __cdecl operator^<struct SLoadInfo>(std::istream &,struct SLoadInfo &);

// address=[0x1536280]
std::ostream & __cdecl operator^<struct SLoadInfo>(std::ostream &,struct SLoadInfo const &);

// address=[0x15362a0]
std::istream & __cdecl LoadArray<struct SLoadInfo>(std::istream &,struct SLoadInfo * const,unsigned int);

// address=[0x15364c0]
std::ostream & __cdecl StoreArray<struct SLoadInfo>(std::ostream &,struct SLoadInfo const * const,unsigned int);

// address=[0x153a580]
void __cdecl Serial::Serialize(std::istream &,struct SLoadInfo &);

// address=[0x153a5d0]
void __cdecl Serial::Serialize(std::ostream &,struct SLoadInfo const &);

// address=[0x1548110]
class TArgv<unsigned int,class std::vector<unsigned int,class std::allocator<unsigned int> > > __cdecl CreateArgv<unsigned int>(unsigned int const &);

// address=[0x1548340]
public: class TArgv<unsigned int,class std::vector<unsigned int,class std::allocator<unsigned int> > > & __thiscall TArgv<unsigned int,class std::vector<unsigned int,class std::allocator<unsigned int> > >::operator()(unsigned int const &);

// address=[0x1552570]
public: __thiscall TStaticArray<unsigned short,100>::TStaticArray<unsigned short,100>(void);

// address=[0x1552610]
public: unsigned short & __thiscall TStaticArray<unsigned short,100>::operator[](int);

// address=[0x1552630]
public: unsigned short const & __thiscall TStaticArray<unsigned short,100>::operator[](int)const;

// address=[0x15526b0]
public: int __thiscall TStaticArray<unsigned short,100>::FindEntry(unsigned short const &);

// address=[0x1552770]
public: void __thiscall TStaticArray<unsigned short,100>::Init(void);

// address=[0x1552790]
public: void __thiscall TStaticArray<unsigned short,100>::PopBack(void);

// address=[0x15527e0]
public: void __thiscall TStaticArray<unsigned short,100>::PushBack(unsigned short const &);

// address=[0x1552850]
public: bool __thiscall TStaticArray<unsigned short,100>::RemoveEntry(unsigned short const &);

// address=[0x15528a0]
public: void __thiscall TStaticArray<unsigned short,100>::RemoveIndex(int);

// address=[0x1552960]
public: int __thiscall TStaticArray<unsigned short,100>::Size(void)const;

// address=[0x1558300]
struct SGfxObjectInfo * __cdecl MapObjectGetGfxInfo(unsigned int,int);

// address=[0x1568700]
int __cdecl Y16X16::DeltaXFast(int,int);

// address=[0x1568720]
int __cdecl Y16X16::DeltaYFast(int,int);

// address=[0x1568740]
int __cdecl Y16X16::DirectionFast(int,int);

// address=[0x156f830]
void __cdecl CheckRegister(char *,class CSettler *);

// address=[0x1570000]
float __cdecl abs(float);

// address=[0x1570020]
_fabsf;

// address=[0x1592da0]
int __cdecl Y16X16::DistanceFast(int,int);

// address=[0x15998c0]
std::ostream & __cdecl operator^<enum CFerryShip::TFerryJob>(std::ostream &,enum CFerryShip::TFerryJob const &);

// address=[0x15998e0]
void __cdecl Serial::Serialize<enum CFerryShip::TFerryJob>(std::ostream &,enum CFerryShip::TFerryJob const &);

// address=[0x15b1910]
public: __thiscall TStaticConfigIntArray<4>::TStaticConfigIntArray<4>(char const *,char const *,int,int,int,int);

// address=[0x15b19a0]
private: __thiscall TStaticConfigIntArrayBase<4>::TStaticConfigIntArrayBase<4>(char const *,char const *);

// address=[0x15b19e0]
public: virtual __thiscall TStaticConfigIntArray<4>::~TStaticConfigIntArray<4>(void);

// address=[0x15b1a00]
public: virtual __thiscall TStaticConfigIntArrayBase<4>::~TStaticConfigIntArrayBase<4>(void);

// address=[0x15b1a20]
public: int & __thiscall TStaticConfigIntArrayBase<4>::operator[](int);

// address=[0x15b1ac0]
public: virtual int * __thiscall TStaticConfigIntArrayBase<4>::GetIntArray(void);

// address=[0x15b1ae0]
public: virtual int const * __thiscall TStaticConfigIntArrayBase<4>::GetIntArray(void)const;

// address=[0x15cc520]
double __cdecl pow<int,int>(int,int);

// address=[0x15cc670]
class ISimpleNet * __cdecl CreateSimpleNet(void);

// address=[0x15cc720]
bool __cdecl ImportWSAFunctions(void);

// address=[0x15ccbc0]
void __cdecl ExitWSAFunctions(void);

// address=[0x15d2fa0]
__tcscmp;

// address=[0x15d5e20]
public: __thiscall TPriorityQueue<class COpenListEntry16,32768>::TPriorityQueue<class COpenListEntry16,32768>(void);

// address=[0x15d5e60]
public: __thiscall TPriorityQueue<class COpenListEntry24,8192>::TPriorityQueue<class COpenListEntry24,8192>(void);

// address=[0x15d5fb0]
public: bool __thiscall TBitArray<8192>::operator[](unsigned int);

// address=[0x15d6000]
public: bool __thiscall TBitArray<32768>::operator[](unsigned int);

// address=[0x15d6050]
public: class COpenListEntry16 const & __thiscall TPriorityQueue<class COpenListEntry16,32768>::operator[](int)const;

// address=[0x15d6070]
public: class COpenListEntry24 const & __thiscall TPriorityQueue<class COpenListEntry24,8192>::operator[](int)const;

// address=[0x15d6130]
public: void __thiscall TPriorityQueue<class COpenListEntry24,8192>::Clear(void);

// address=[0x15d6150]
public: void __thiscall TBitArray<8192>::ClearArray(void);

// address=[0x15d6180]
public: void __thiscall TBitArray<32768>::ClearArray(void);

// address=[0x15d62a0]
protected: void __thiscall TPriorityQueue<class COpenListEntry16,32768>::DownHeap(int);

// address=[0x15d63b0]
protected: void __thiscall TPriorityQueue<class COpenListEntry24,8192>::DownHeap(int);

// address=[0x15d64c0]
public: bool __thiscall TPriorityQueue<class COpenListEntry16,32768>::Empty(void)const;

// address=[0x15d6500]
public: bool __thiscall TPriorityQueue<class COpenListEntry24,8192>::Empty(void)const;

// address=[0x15d6540]
public: static int __cdecl TPriorityQueue<class COpenListEntry16,32768>::First(void);

// address=[0x15d6550]
public: static int __cdecl TPriorityQueue<class COpenListEntry24,8192>::First(void);

// address=[0x15d6700]
public: int __thiscall TPriorityQueue<class COpenListEntry16,32768>::Last(void)const;

// address=[0x15d6720]
public: int __thiscall TPriorityQueue<class COpenListEntry24,8192>::Last(void)const;

// address=[0x15d6820]
public: void __thiscall TPriorityQueue<class COpenListEntry16,32768>::Pop(void);

// address=[0x15d6880]
public: void __thiscall TPriorityQueue<class COpenListEntry24,8192>::Pop(void);

// address=[0x15d68e0]
public: void __thiscall TPriorityQueue<class COpenListEntry16,32768>::Push(class COpenListEntry16 const &);

// address=[0x15d6940]
public: void __thiscall TPriorityQueue<class COpenListEntry24,8192>::Push(class COpenListEntry24 const &);

// address=[0x15d6b70]
public: void __thiscall TPriorityQueue<class COpenListEntry16,32768>::Remove(int);

// address=[0x15d6bd0]
public: void __thiscall TPriorityQueue<class COpenListEntry24,8192>::Remove(int);

// address=[0x15d6c30]
public: void __thiscall TBitArray<8192>::Set(unsigned int);

// address=[0x15d6c70]
public: void __thiscall TBitArray<32768>::Set(unsigned int);

// address=[0x15d6f30]
public: class COpenListEntry16 const & __thiscall TPriorityQueue<class COpenListEntry16,32768>::Top(void)const;

// address=[0x15d6f50]
public: class COpenListEntry24 const & __thiscall TPriorityQueue<class COpenListEntry24,8192>::Top(void)const;

// address=[0x15d6f70]
protected: void __thiscall TPriorityQueue<class COpenListEntry16,32768>::UpHeap(int);

// address=[0x15d7010]
protected: void __thiscall TPriorityQueue<class COpenListEntry24,8192>::UpHeap(int);

// address=[0x15d7190]
int __cdecl Y16X16::XYNotNegative(int);

// address=[0x15dc4b0]
int __cdecl Grid::Direction(int,int);

// address=[0x15dc4d0]
int __cdecl Grid::Direction(float,float);

// address=[0x15dc500]
int __cdecl Grid::DirectionFast(int,int);

// address=[0x15dc520]
int __cdecl Grid::DirectionFast(float,float);

// address=[0x15dc550]
int __cdecl Grid::Area(int,int);

// address=[0x15dc620]
int __cdecl Grid::AreaFast(int,int);

// address=[0x15dc6a0]
int __cdecl Grid::Distance(int,int);

// address=[0x15dc700]
float __cdecl Grid::Distance(float,float);

// address=[0x15ddbe0]
int __cdecl Grid::Distance(struct SPoint const &,struct SPoint const &);

// address=[0x15ddc10]
int __cdecl Grid::Distance(struct SPoint const &);

// address=[0x15ddc30]
int __cdecl Max(int,int);

// address=[0x15ddc60]
float __cdecl Max(float,float);

// address=[0x15ddd50]
float __cdecl fabs(float);

// address=[0x15f10f0]
void __cdecl NeighborAnalysis::CalcTileAreas(void);

// address=[0x15f11f0]
void __cdecl NeighborAnalysis::Init(enum T_TILING_TYPE,int,int);

// address=[0x15f12f0]
void __cdecl NeighborAnalysis::ReInit(void);

// address=[0x15f1370]
void __cdecl NeighborAnalysis::InitOld(int,int);

// address=[0x15f14e0]
void __cdecl NeighborAnalysis::InitNew(int,int,bool);

// address=[0x15f3d10]
public: __thiscall TLimitedFIFO<int,256>::TLimitedFIFO<int,256>(void);

// address=[0x15f3d30]
public: __thiscall TLimitedFIFO<int,576>::TLimitedFIFO<int,576>(void);

// address=[0x15f3d50]
public: __thiscall TLimitedFIFO<int,32768>::TLimitedFIFO<int,32768>(void);

// address=[0x15f3d70]
protected: __thiscall TPowerOf2Wrap<256>::TPowerOf2Wrap<256>(void);

// address=[0x15f3d90]
protected: __thiscall TPowerOf2Wrap<4096>::TPowerOf2Wrap<4096>(void);

// address=[0x15f3db0]
protected: __thiscall TPowerOf2Wrap<32768>::TPowerOf2Wrap<32768>(void);

// address=[0x15f3dd0]
public: __thiscall TStaticArray<int,63>::TStaticArray<int,63>(void);

// address=[0x15f3df0]
public: __thiscall TStaticFIFO<int,256>::TStaticFIFO<int,256>(void);

// address=[0x15f3e20]
public: __thiscall TStaticFIFO<int,4096>::TStaticFIFO<int,4096>(void);

// address=[0x15f3e50]
public: __thiscall TStaticList<int,32768>::TStaticList<int,32768>(void);

// address=[0x15f3f80]
public: bool __thiscall TBitArray<262144>::operator[](unsigned int);

// address=[0x15f3fd0]
public: bool & __thiscall TBoolArray<6>::operator[](int);

// address=[0x15f3ff0]
public: int & __thiscall TStaticArray<int,63>::operator[](int);

// address=[0x15f4250]
public: void __thiscall TBitArray<262144>::ClearArray(void);

// address=[0x15f4320]
public: int __thiscall TStaticArray<int,63>::Count(void)const;

// address=[0x15f4360]
void __cdecl NeighborAnalysis::Done(void);

// address=[0x15f4420]
public: bool __thiscall TLimitedFIFO<int,256>::Empty(void);

// address=[0x15f4460]
public: bool __thiscall TLimitedFIFO<int,576>::Empty(void);

// address=[0x15f44a0]
public: bool __thiscall TLimitedFIFO<int,32768>::Empty(void);

// address=[0x15f44e0]
public: bool __thiscall TStaticArray<int,63>::Empty(void)const;

// address=[0x15f4520]
public: bool __thiscall TStaticFIFO<int,256>::Empty(void);

// address=[0x15f4560]
public: bool __thiscall TStaticFIFO<int,4096>::Empty(void);

// address=[0x15f45a0]
public: bool __thiscall TStaticList<int,32768>::Empty(void);

// address=[0x15f45e0]
public: int & __thiscall TStaticList<int,32768>::Front(void);

// address=[0x15f4680]
public: void __thiscall TLimitedFIFO<int,256>::Init(void);

// address=[0x15f46b0]
public: void __thiscall TLimitedFIFO<int,576>::Init(void);

// address=[0x15f46e0]
public: void __thiscall TLimitedFIFO<int,32768>::Init(void);

// address=[0x15f4710]
public: void __thiscall TStaticArray<int,63>::Init(void);

// address=[0x15f4730]
public: void __thiscall TStaticFIFO<int,256>::Init(void);

// address=[0x15f4760]
public: void __thiscall TStaticFIFO<int,4096>::Init(void);

// address=[0x15f4790]
public: void __thiscall TStaticList<int,32768>::Init(void);

// address=[0x15f5250]
public: void __thiscall TLimitedFIFO<int,256>::Pop(void);

// address=[0x15f5270]
public: void __thiscall TLimitedFIFO<int,576>::Pop(void);

// address=[0x15f5290]
public: void __thiscall TLimitedFIFO<int,32768>::Pop(void);

// address=[0x15f52b0]
public: void __thiscall TStaticFIFO<int,256>::Pop(void);

// address=[0x15f52e0]
public: void __thiscall TStaticFIFO<int,4096>::Pop(void);

// address=[0x15f5310]
public: void __thiscall TStaticList<int,32768>::PopFront(void);

// address=[0x15f53a0]
public: void __thiscall TLimitedFIFO<int,256>::Push(int const &);

// address=[0x15f53e0]
public: void __thiscall TLimitedFIFO<int,576>::Push(int const &);

// address=[0x15f5420]
public: void __thiscall TLimitedFIFO<int,32768>::Push(int const &);

// address=[0x15f5460]
public: void __thiscall TStaticFIFO<int,256>::Push(int const &);

// address=[0x15f54b0]
public: void __thiscall TStaticFIFO<int,4096>::Push(int const &);

// address=[0x15f5500]
public: void __thiscall TStaticArray<int,63>::PushBack(int const &);

// address=[0x15f5570]
public: void __thiscall TStaticList<int,32768>::PushBack(int const &);

// address=[0x15f5680]
public: void __thiscall TBitArray<262144>::Set(unsigned int);

// address=[0x15f5730]
public: bool __thiscall TBitArray<32768>::SetIfNotSet(int);

// address=[0x15f5a10]
public: int & __thiscall TLimitedFIFO<int,256>::Top(void);

// address=[0x15f5a30]
public: int & __thiscall TLimitedFIFO<int,576>::Top(void);

// address=[0x15f5a50]
public: int & __thiscall TLimitedFIFO<int,32768>::Top(void);

// address=[0x15f5a70]
public: int & __thiscall TStaticFIFO<int,256>::Top(void);

// address=[0x15f5a90]
public: int & __thiscall TStaticFIFO<int,4096>::Top(void);

// address=[0x15f5ab0]
public: void __thiscall TLimitedFIFO<int,576>::UndoPush(int);

// address=[0x15f6080]
protected: static int __cdecl TPowerOf2Wrap<256>::Wrap(int);

// address=[0x15f6090]
protected: static int __cdecl TPowerOf2Wrap<4096>::Wrap(int);

// address=[0x15f60a0]
protected: static int __cdecl TPowerOf2Wrap<32768>::Wrap(int);

// address=[0x15f60f0]
void __cdecl BB::ZeroMemPtr(void *,unsigned int);

// address=[0x15f65a0]
int __cdecl DbgGetFlags(int,int);

// address=[0x15f65c0]
int __cdecl DbgGetSectorId(int,int);

// address=[0x15fe840]
std::wstring __cdecl SaveFilePath::BuildSaveFilePath(std::wstring const &);

// address=[0x15fe950]
std::wstring __cdecl SaveFilePath::BuildSaveFilePathWithExtension(std::wstring const &);

// address=[0x15fe9f0]
std::wstring __cdecl SaveFilePath::GetSaveFileMapPattern(void);

// address=[0x16038b0]
void __cdecl __vcrt_va_start_verify_argument_type<enum EScriptType>(void);

// address=[0x1603910]
void __cdecl ScriptExportVars(class CLua &);

// address=[0x1603a90]
void __cdecl ScriptExportFunctions(class CLua &);

// address=[0x1603ba0]
void __cdecl ScriptDefaultVictoryConditionCheck(void);

// address=[0x1603bc0]
void __cdecl ScriptEconomyModeVictoryConditionCheck(void);

// address=[0x1603ef0]
void __cdecl ScriptTracePrintF(unsigned int,char const *,...);

// address=[0x1608150]
void __cdecl GameEnableLandExploredCheck(void);

// address=[0x1608960]
void __cdecl GameResetFogging(void);

// address=[0x1608980]
void __cdecl GameSetAlliesDontRevealFog(void);

// address=[0x160aa80]
void __cdecl StatisticMushroomFarmsDestroyed(void);

// address=[0x160ab00]
void __cdecl StatisticServantsFreed(void);

// address=[0x1615c30]
bool __cdecl storm_if_constexpr(bool);

// address=[0x1634440]
float __cdecl ceil(float);

// address=[0x1635eb0]
_ceilf;

// address=[0x16a20a0]
unsigned int __cdecl GetVideoInterfaceVersion(void);

// address=[0x16a5830]
public: __thiscall TMap<unsigned char>::TMap<unsigned char>(void);

// address=[0x16a5850]
public: __thiscall TMap<unsigned short>::TMap<unsigned short>(void);

// address=[0x16a5870]
public: __thiscall TMap<struct T_GFX_MAP_ELEMENT>::TMap<struct T_GFX_MAP_ELEMENT>(void);

// address=[0x16a5890]
public: __thiscall TSparseMap<unsigned char>::TSparseMap<unsigned char>(unsigned int,unsigned int,unsigned char);

// address=[0x16a5930]
public: __thiscall TStaticFIFO<int,1024>::TStaticFIFO<int,1024>(void);

// address=[0x16a6110]
public: __thiscall TMap<unsigned char>::~TMap<unsigned char>(void);

// address=[0x16a6160]
public: __thiscall TMap<unsigned short>::~TMap<unsigned short>(void);

// address=[0x16a61b0]
public: __thiscall TMap<struct T_GFX_MAP_ELEMENT>::~TMap<struct T_GFX_MAP_ELEMENT>(void);

// address=[0x16a6200]
public: __thiscall TSparseMap<unsigned char>::~TSparseMap<unsigned char>(void);

// address=[0x16a6b60]
private: void __thiscall TSparseMap<unsigned char>::Construct(void);

// address=[0x16a6cf0]
private: void __thiscall TSparseMap<unsigned char>::Destruct(void);

// address=[0x16a6dc0]
public: void __thiscall TMap<unsigned char>::Done(void);

// address=[0x16a6e00]
public: void __thiscall TMap<unsigned short>::Done(void);

// address=[0x16a6e40]
public: void __thiscall TMap<struct T_GFX_MAP_ELEMENT>::Done(void);

// address=[0x16a6e80]
public: bool __thiscall TStaticFIFO<int,1024>::Empty(void);

// address=[0x16a6ec0]
public: unsigned char __thiscall TSparseMap<unsigned char>::GetByX(int);

// address=[0x16a6fe0]
public: void __thiscall TMap<unsigned char>::Init(int);

// address=[0x16a7040]
public: void __thiscall TMap<unsigned short>::Init(int);

// address=[0x16a70c0]
public: void __thiscall TMap<struct T_GFX_MAP_ELEMENT>::Init(int);

// address=[0x16a7140]
public: void __thiscall TStaticFIFO<int,1024>::Init(void);

// address=[0x16a7500]
public: void __thiscall TStaticFIFO<int,1024>::Pop(void);

// address=[0x16a7530]
public: void __thiscall TStaticFIFO<int,1024>::Push(int const &);

// address=[0x16a78c0]
public: void __thiscall TSparseMap<unsigned char>::SetNewLine(int);

// address=[0x16a7900]
public: int & __thiscall TStaticFIFO<int,1024>::Top(void);

// address=[0x16a9198]
_timeGetTime@0;

// address=[0x16a919e]
_timeBeginPeriod@4;

// address=[0x16a91a4]
_timeEndPeriod@4;

// address=[0x17db000]
double __cdecl nextafter<int,int>(int,int);

// address=[0x19104b0]
void __stdcall `vector destructor iterator'(void *,unsigned int,unsigned int,void (*)(void *));

// address=[0x191d250]
void __cdecl TriggerAssert(bool,std::string const &,char const *,int,char const *,unsigned int);

// address=[0x1aefbc0]
bool __cdecl isUbiServicesSdkInitialized(void);

// address=[0x1c0cb80]
___local_stdio_scanf_options;

// address=[0x1c0cb90]
__snprintf_s;

// address=[0x1c0cc00]
__vfprintf_l;

// address=[0x1c0cc40]
__vfwprintf_l;

// address=[0x1c0cc80]
__vsnprintf_s_l;

// address=[0x1c0cd10]
__vsscanf_l;

// address=[0x1c0cdf0]
_printf;

// address=[0x1c0ce60]
_sscanf;

// address=[0x1c0cef0]
_vsnprintf;

// address=[0x1c0cf70]
_wprintf;

// address=[0x1c0cfe0]
_curl_easy_cleanup;

// address=[0x1c0d020]
_curl_easy_duphandle;

// address=[0x1c0d490]
_curl_easy_getinfo;

// address=[0x1c0d510]
_curl_easy_init;

// address=[0x1c0d5d0]
_curl_easy_pause;

// address=[0x1c0d850]
_curl_easy_perform;

// address=[0x1c0d870]
_curl_easy_recv;

// address=[0x1c0d970]
_curl_easy_reset;

// address=[0x1c0dac0]
_curl_easy_send;

// address=[0x1c0dbf0]
_curl_easy_setopt;

// address=[0x1c0dc60]
_curl_global_cleanup;

// address=[0x1c0dce0]
_curl_global_init;

// address=[0x1c0dd00]
_curl_global_init_mem;

// address=[0x1c0e500]
_Curl_slist_append_nodup;

// address=[0x1c0e5b0]
_Curl_slist_duplicate;

// address=[0x1c0e640]
_curl_slist_append;

// address=[0x1c0e6d0]
_curl_slist_free_all;

// address=[0x1c0e7d0]
_Curl_strerror;

// address=[0x1c0e9a0]
_curl_easy_strerror;

// address=[0x1c0ef90]
_curl_multi_strerror;

// address=[0x1c0f050]
_curl_share_strerror;

// address=[0x1c0f720]
_Curl_expire;

// address=[0x1c0f980]
_Curl_expire_clear;

// address=[0x1c0fa90]
_Curl_expire_done;

// address=[0x1c0fac0]
_Curl_multi_add_perform;

// address=[0x1c0fb70]
_Curl_multi_chunk_length_penalty_size;

// address=[0x1c0fbb0]
_Curl_multi_closed;

// address=[0x1c0fc80]
_Curl_multi_connchanged;

// address=[0x1c0fc90]
_Curl_multi_content_length_penalty_size;

// address=[0x1c0fcd0]
_Curl_multi_handle;

// address=[0x1c0ff00]
_Curl_multi_handlePipeBreak;

// address=[0x1c0ff20]
_Curl_multi_max_host_connections;

// address=[0x1c0ff60]
_Curl_multi_max_total_connections;

// address=[0x1c0ffa0]
_Curl_multi_pipelining_server_bl;

// address=[0x1c0ffb0]
_Curl_multi_pipelining_site_bl;

// address=[0x1c0ffc0]
_Curl_multi_process_pending_handles;

// address=[0x1c10080]
_Curl_pipeline_wanted;

// address=[0x1c10320]
_curl_multi_add_handle;

// address=[0x1c10580]
_curl_multi_assign;

// address=[0x1c105f0]
_curl_multi_cleanup;

// address=[0x1c10820]
_curl_multi_fdset;

// address=[0x1c10ad0]
_curl_multi_info_read;

// address=[0x1c10ba0]
_curl_multi_init;

// address=[0x1c10bd0]
_curl_multi_perform;

// address=[0x1c10d60]
_curl_multi_remove_handle;

// address=[0x1c11100]
_curl_multi_setopt;

// address=[0x1c114b0]
_curl_multi_socket;

// address=[0x1c11510]
_curl_multi_socket_action;

// address=[0x1c11570]
_curl_multi_socket_all;

// address=[0x1c115d0]
_curl_multi_timeout;

// address=[0x1c11620]
_curl_multi_wait;

// address=[0x1c159d0]
_decrementNumberOfLibcurlGetAddrInfoThreads;

// address=[0x1c159f0]
_getNumberOfLibcurlGetAddrInfoThreads;

// address=[0x1c15a00]
_incrementNumberOfLibcurlGetAddrInfoThreads;

// address=[0x1c15a20]
_initNumberOfLibcurlGetAddrInfoThreads;

// address=[0x1c15a40]
_Curl_cookie_add;

// address=[0x1c17370]
_Curl_cookie_cleanup;

// address=[0x1c173e0]
_Curl_cookie_clearall;

// address=[0x1c17420]
_Curl_cookie_clearsess;

// address=[0x1c17530]
_Curl_cookie_freelist;

// address=[0x1c17580]
_Curl_cookie_getlist;

// address=[0x1c178d0]
_Curl_cookie_init;

// address=[0x1c17c00]
_Curl_cookie_list;

// address=[0x1c17d30]
_Curl_cookie_loadfiles;

// address=[0x1c17e50]
_Curl_flush_cookies;

// address=[0x1c18fe0]
_curlx_tvdiff;

// address=[0x1c19030]
_curlx_tvdiff_secs;

// address=[0x1c190b0]
_curlx_tvnow;

// address=[0x1c19190]
_Curl_resolver_cancel;

// address=[0x1c191c0]
_Curl_resolver_cleanup;

// address=[0x1c191d0]
_Curl_resolver_duphandle;

// address=[0x1c191e0]
_Curl_resolver_getaddrinfo;

// address=[0x1c19430]
_Curl_resolver_getsock;

// address=[0x1c19440]
_Curl_resolver_global_cleanup;

// address=[0x1c19450]
_Curl_resolver_global_init;

// address=[0x1c19460]
_Curl_resolver_init;

// address=[0x1c19470]
_Curl_resolver_is_resolved;

// address=[0x1c196c0]
_Curl_resolver_wait_resolv;

// address=[0x1c197c0]
_Curl_set_dns_interface;

// address=[0x1c197d0]
_Curl_set_dns_local_ip4;

// address=[0x1c197e0]
_Curl_set_dns_local_ip6;

// address=[0x1c197f0]
_Curl_set_dns_servers;

// address=[0x1c19fe0]
_Curl_cache_addr;

// address=[0x1c1a1a0]
_Curl_fetch_addr;

// address=[0x1c1a260]
_Curl_global_host_cache_dtor;

// address=[0x1c1a2a0]
_Curl_global_host_cache_init;

// address=[0x1c1a340]
_Curl_hostcache_clean;

// address=[0x1c1a3b0]
_Curl_hostcache_prune;

// address=[0x1c1a4b0]
_Curl_loadhostpairs;

// address=[0x1c1a9a0]
_Curl_mk_dnscache;

// address=[0x1c1a9e0]
_Curl_num_addresses;

// address=[0x1c1aa20]
_Curl_printable_address;

// address=[0x1c1aab0]
_Curl_resolv;

// address=[0x1c1ad20]
_Curl_resolv_timeout;

// address=[0x1c1ad90]
_Curl_resolv_unlock;

// address=[0x1c1b270]
_Curl_clone_primary_ssl_config;

// address=[0x1c1b520]
_Curl_free_primary_ssl_config;

// address=[0x1c1b660]
_Curl_pin_peer_pubkey;

// address=[0x1c1bc20]
_Curl_ssl_addsessionid;

// address=[0x1c1c060]
_Curl_ssl_backend;

// address=[0x1c1c070]
_Curl_ssl_cert_status_request;

// address=[0x1c1c090]
_Curl_ssl_check_cxn;

// address=[0x1c1c0b0]
_Curl_ssl_cleanup;

// address=[0x1c1c0e0]
_Curl_ssl_close;

// address=[0x1c1c110]
_Curl_ssl_close_all;

// address=[0x1c1c1f0]
_Curl_ssl_config_matches;

// address=[0x1c1c2e0]
_Curl_ssl_connect;

// address=[0x1c1c3c0]
_Curl_ssl_connect_nonblocking;

// address=[0x1c1c4a0]
_Curl_ssl_data_pending;

// address=[0x1c1c4d0]
_Curl_ssl_delsessionid;

// address=[0x1c1c570]
_Curl_ssl_engines_list;

// address=[0x1c1c590]
_Curl_ssl_false_start;

// address=[0x1c1c5a0]
_Curl_ssl_free_certinfo;

// address=[0x1c1c670]
_Curl_ssl_getsessionid;

// address=[0x1c1ca50]
_Curl_ssl_getsock;

// address=[0x1c1cb10]
_Curl_ssl_init;

// address=[0x1c1cb50]
_Curl_ssl_init_certinfo;

// address=[0x1c1cbf0]
_Curl_ssl_initsessions;

// address=[0x1c1cc90]
_Curl_ssl_kill_session;

// address=[0x1c1cd50]
_Curl_ssl_md5sum;

// address=[0x1c1cd80]
_Curl_ssl_push_certinfo;

// address=[0x1c1cde0]
_Curl_ssl_push_certinfo_len;

// address=[0x1c1cf60]
_Curl_ssl_random;

// address=[0x1c1cf90]
_Curl_ssl_sessionid_lock;

// address=[0x1c1cfe0]
_Curl_ssl_sessionid_unlock;

// address=[0x1c1d030]
_Curl_ssl_set_engine;

// address=[0x1c1d060]
_Curl_ssl_set_engine_default;

// address=[0x1c1d080]
_Curl_ssl_shutdown;

// address=[0x1c1d110]
_Curl_ssl_version;

// address=[0x1c1e250]
_Curl_close;

// address=[0x1c1e6f0]
_Curl_connect;

// address=[0x1c1e7e0]
_Curl_connected_proxy;

// address=[0x1c1ea30]
_Curl_disconnect;

// address=[0x1c1ec50]
_Curl_doing_getsock;

// address=[0x1c1ecb0]
_Curl_dupset;

// address=[0x1c1ee60]
_Curl_free_request_state;

// address=[0x1c1eef0]
_Curl_freeset;

// address=[0x1c1f050]
_Curl_getoff_all_pipelines;

// address=[0x1c1f1c0]
_Curl_init_do;

// address=[0x1c1f310]
_Curl_init_userdefined;

// address=[0x1c1f650]
_Curl_oldest_idle_connection;

// address=[0x1c1f7f0]
_Curl_open;

// address=[0x1c1faa0]
_Curl_protocol_connect;

// address=[0x1c1fc40]
_Curl_protocol_connecting;

// address=[0x1c1fcd0]
_Curl_protocol_doing;

// address=[0x1c1fd60]
_Curl_protocol_getsock;

// address=[0x1c1fdc0]
_Curl_removeHandleFromPipeline;

// address=[0x1c1fe40]
_Curl_setopt;

// address=[0x1c25150]
_Curl_setup_conn;

// address=[0x1c253a0]
_Curl_verboseconnect;

// address=[0x1c2d3a0]
_Curl_getinfo;

// address=[0x1c2d5f0]
_Curl_initinfo;

// address=[0x1c2e310]
_Curl_poll;

// address=[0x1c2ec40]
_Curl_socket_check;

// address=[0x1c2f580]
_Curl_wait_ms;

// address=[0x1c2f610]
_Curl_client_chop_write;

// address=[0x1c2f8e0]
_Curl_client_write;

// address=[0x1c2f9a0]
_Curl_debug;

// address=[0x1c2fbb0]
_Curl_failf;

// address=[0x1c2fd60]
_Curl_infof;

// address=[0x1c2fe80]
_Curl_read;

// address=[0x1c301a0]
_Curl_read_plain;

// address=[0x1c30270]
_Curl_recv_has_postponed_data;

// address=[0x1c30310]
_Curl_recv_plain;

// address=[0x1c30450]
_Curl_send_plain;

// address=[0x1c30570]
_Curl_sendf;

// address=[0x1c30720]
_Curl_write;

// address=[0x1c30860]
_Curl_write_plain;

// address=[0x1c30fb0]
_Curl_closesocket;

// address=[0x1c310a0]
_Curl_conn_data_pending;

// address=[0x1c31180]
_Curl_connalive;

// address=[0x1c31290]
_Curl_conncontrol;

// address=[0x1c31370]
_Curl_connecthost;

// address=[0x1c31630]
_Curl_getconnectinfo;

// address=[0x1c317a0]
_Curl_is_connected;

// address=[0x1c31ee0]
_Curl_persistconninfo;

// address=[0x1c31fb0]
_Curl_sndbufset;

// address=[0x1c32130]
_Curl_socket;

// address=[0x1c32320]
_Curl_tcpnodelay;

// address=[0x1c32430]
_Curl_timeleft;

// address=[0x1c32690]
_Curl_updateconninfo;

// address=[0x1c33e90]
_Curl_version_init;

// address=[0x1c33ec0]
_curl_version;

// address=[0x1c33fd0]
_curl_version_info;

// address=[0x1c34230]
_curl_maprintf;

// address=[0x1c34370]
_curl_mfprintf;

// address=[0x1c343e0]
_curl_mprintf;

// address=[0x1c34450]
_curl_msnprintf;

// address=[0x1c344b0]
_curl_msprintf;

// address=[0x1c34520]
_curl_mvaprintf;

// address=[0x1c34650]
_curl_mvfprintf;

// address=[0x1c34680]
_curl_mvprintf;

// address=[0x1c346c0]
_curl_mvsnprintf;

// address=[0x1c347b0]
_curl_mvsprintf;

// address=[0x1c371e0]
_Curl_fillreadbuffer;

// address=[0x1c37550]
_Curl_follow;

// address=[0x1c37a10]
_Curl_init_CONNECT;

// address=[0x1c37a50]
_Curl_meets_timecondition;

// address=[0x1c37b80]
_Curl_posttransfer;

// address=[0x1c37b90]
_Curl_pretransfer;

// address=[0x1c37f20]
_Curl_readrewind;

// address=[0x1c38110]
_Curl_readwrite;

// address=[0x1c38750]
_Curl_retry_request;

// address=[0x1c38920]
_Curl_setup_transfer;

// address=[0x1c38b90]
_Curl_single_getsock;

// address=[0x1c3ab10]
_Curl_llist_count;

// address=[0x1c3ab20]
_Curl_llist_destroy;

// address=[0x1c3ab70]
_Curl_llist_init;

// address=[0x1c3abb0]
_Curl_llist_insert_next;

// address=[0x1c3acc0]
_Curl_llist_move;

// address=[0x1c3ae20]
_Curl_llist_remove;

// address=[0x1c3af60]
_Curl_hash_add;

// address=[0x1c3b0d0]
_Curl_hash_clean;

// address=[0x1c3b100]
_Curl_hash_clean_with_criterium;

// address=[0x1c3b210]
_Curl_hash_delete;

// address=[0x1c3b320]
_Curl_hash_destroy;

// address=[0x1c3b3d0]
_Curl_hash_init;

// address=[0x1c3b4e0]
_Curl_hash_next_element;

// address=[0x1c3b5e0]
_Curl_hash_pick;

// address=[0x1c3b6d0]
_Curl_hash_start_iterate;

// address=[0x1c3b700]
_Curl_hash_str;

// address=[0x1c3b790]
_Curl_str_key_compare;

// address=[0x1c3b910]
_Curl_addrinfo_callback;

// address=[0x1c3ba40]
_Curl_async_resolved;

// address=[0x1c3bad0]
_Curl_getaddrinfo;

// address=[0x1c3bb00]
_Curl_splay;

// address=[0x1c3be70]
_Curl_splaygetbest;

// address=[0x1c3c010]
_Curl_splayinsert;

// address=[0x1c3c2a0]
_Curl_splayremovebyaddr;

// address=[0x1c3c5d0]
_Curl_http;

// address=[0x1c3f320]
_Curl_http_done;

// address=[0x1c3f540]
_Curl_http_connect;

// address=[0x1c3f650]
_Curl_http_setup_conn;

// address=[0x1c3f6c0]
_Curl_add_buffer;

// address=[0x1c3f890]
_Curl_add_buffer_free;

// address=[0x1c3f8f0]
_Curl_add_buffer_init;

// address=[0x1c3f920]
_Curl_add_buffer_send;

// address=[0x1c3fcc0]
_Curl_add_bufferf;

// address=[0x1c3fdb0]
_Curl_add_custom_headers;

// address=[0x1c40260]
_Curl_add_timecondition;

// address=[0x1c404c0]
_Curl_checkProxyheaders;

// address=[0x1c405a0]
_Curl_checkheaders;

// address=[0x1c40650]
_Curl_compareheader;

// address=[0x1c407b0]
_Curl_copy_header_value;

// address=[0x1c40950]
_Curl_http_auth_act;

// address=[0x1c40ce0]
_Curl_http_input_auth;

// address=[0x1c41040]
_Curl_http_output_auth;

// address=[0x1c41250]
_Curl_http_readwrite_headers;

// address=[0x1c44340]
_Curl_wildcard_dtor;

// address=[0x1c44430]
_Curl_wildcard_init;

// address=[0x1c44470]
_Curl_conncache_add_conn;

// address=[0x1c44670]
_Curl_conncache_destroy;

// address=[0x1c446a0]
_Curl_conncache_find_bundle;

// address=[0x1c44790]
_Curl_conncache_find_first_connection;

// address=[0x1c44880]
_Curl_conncache_foreach;

// address=[0x1c449b0]
_Curl_conncache_init;

// address=[0x1c449f0]
_Curl_conncache_remove_conn;

// address=[0x1c44f30]
_Curl_pgrsDone;

// address=[0x1c45000]
_Curl_pgrsLimitWaitTime;

// address=[0x1c45110]
_Curl_pgrsResetTimesSizes;

// address=[0x1c45190]
_Curl_pgrsSetDownloadCounter;

// address=[0x1c45300]
_Curl_pgrsSetDownloadSize;

// address=[0x1c45390]
_Curl_pgrsSetUploadCounter;

// address=[0x1c45500]
_Curl_pgrsSetUploadSize;

// address=[0x1c45590]
_Curl_pgrsStartNow;

// address=[0x1c45630]
_Curl_pgrsTime;

// address=[0x1c458c0]
_Curl_pgrsUpdate;

// address=[0x1c47070]
_curlx_read;

// address=[0x1c470b0]
_curlx_sitosk;

// address=[0x1c470c0]
_curlx_sitouz;

// address=[0x1c470d0]
_curlx_sktosi;

// address=[0x1c470e0]
_curlx_sltosi;

// address=[0x1c47100]
_curlx_sltoui;

// address=[0x1c47110]
_curlx_sltous;

// address=[0x1c47130]
_curlx_sotouz;

// address=[0x1c47150]
_curlx_sztosi;

// address=[0x1c47170]
_curlx_uitosi;

// address=[0x1c47190]
_curlx_uitouc;

// address=[0x1c471b0]
_curlx_uitous;

// address=[0x1c471d0]
_curlx_ultosi;

// address=[0x1c471f0]
_curlx_ultouc;

// address=[0x1c47210]
_curlx_ultous;

// address=[0x1c47230]
_curlx_uztosi;

// address=[0x1c47250]
_curlx_uztoso;

// address=[0x1c47270]
_curlx_uztosz;

// address=[0x1c47290]
_curlx_uztoui;

// address=[0x1c472a0]
_curlx_uztoul;

// address=[0x1c472b0]
_curlx_write;

// address=[0x1c472f0]
_Curl_speedcheck;

// address=[0x1c474c0]
_Curl_speedinit;

// address=[0x1c474f0]
_Curl_add_handle_to_pipeline;

// address=[0x1c475b0]
_Curl_move_handle_from_send_to_recv_pipe;

// address=[0x1c47680]
_Curl_pipeline_checkget_read;

// address=[0x1c476f0]
_Curl_pipeline_checkget_write;

// address=[0x1c47760]
_Curl_pipeline_leave_read;

// address=[0x1c47780]
_Curl_pipeline_leave_write;

// address=[0x1c477a0]
_Curl_pipeline_penalized;

// address=[0x1c47930]
_Curl_pipeline_server_blacklisted;

// address=[0x1c47a10]
_Curl_pipeline_set_server_blacklist;

// address=[0x1c47b40]
_Curl_pipeline_set_site_blacklist;

// address=[0x1c47cd0]
_Curl_pipeline_site_blacklisted;

// address=[0x1c47dd0]
_Curl_recvpipe_head;

// address=[0x1c47e00]
_Curl_sendpipe_head;

// address=[0x1c47f80]
_Curl_raw_toupper;

// address=[0x1c47fb0]
_Curl_safe_strcasecompare;

// address=[0x1c48020]
_Curl_strcasecompare;

// address=[0x1c48100]
_Curl_strncasecompare;

// address=[0x1c48200]
_Curl_strntoupper;

// address=[0x1c48280]
_curl_strequal;

// address=[0x1c482b0]
_curl_strnequal;

// address=[0x1c482e0]
_Curl_gmtime;

// address=[0x1c485c0]
_curl_getdate;

// address=[0x1c491c0]
_Curl_strtok_r;

// address=[0x1c492c0]
_Curl_share_lock;

// address=[0x1c49360]
_Curl_share_unlock;

// address=[0x1c493f0]
_curl_share_cleanup;

// address=[0x1c49590]
_curl_share_init;

// address=[0x1c49630]
_curl_share_setopt;

// address=[0x1c49970]
_Curl_memrchr;

// address=[0x1c499e0]
_Curl_inet_pton;

// address=[0x1c49c30]
_Curl_freeaddrinfo;

// address=[0x1c49ce0]
_Curl_getaddrinfo_ex;

// address=[0x1c4a060]
_Curl_he2ai;

// address=[0x1c4a310]
_Curl_ip2addr;

// address=[0x1c4a520]
_Curl_str2addr;

// address=[0x1c4a5d0]
_Curl_thread_create;

// address=[0x1c4a630]
_Curl_thread_destroy;

// address=[0x1c4a660]
_Curl_thread_join;

// address=[0x1c4a6f0]
_Curl_ipv4_resolve_r;

// address=[0x1c4a8d0]
_Curl_ipvalid;

// address=[0x1c4a8f0]
_Curl_inet_ntop;

// address=[0x1c4ab00]
_Curl_ossl_cert_status_request;

// address=[0x1c4ab10]
_Curl_ossl_check_cxn;

// address=[0x1c4ac80]
_Curl_ossl_cleanup;

// address=[0x1c4acc0]
_Curl_ossl_close;

// address=[0x1c4ad10]
_Curl_ossl_close_all;

// address=[0x1c4ad30]
_Curl_ossl_connect;

// address=[0x1c4add0]
_Curl_ossl_connect_nonblocking;

// address=[0x1c4ae00]
_Curl_ossl_data_pending;

// address=[0x1c4aed0]
_Curl_ossl_engines_list;

// address=[0x1c4aef0]
_Curl_ossl_init;

// address=[0x1c4af40]
_Curl_ossl_md5sum;

// address=[0x1c4b000]
_Curl_ossl_random;

// address=[0x1c4b360]
_Curl_ossl_session_free;

// address=[0x1c4b380]
_Curl_ossl_set_engine;

// address=[0x1c4b3b0]
_Curl_ossl_set_engine_default;

// address=[0x1c4b3c0]
_Curl_ossl_sha256sum;

// address=[0x1c4b480]
_Curl_ossl_shutdown;

// address=[0x1c4b820]
_Curl_ossl_version;

// address=[0x1c52270]
_Curl_base64_decode;

// address=[0x1c524a0]
_Curl_base64_encode;

// address=[0x1c524e0]
_Curl_base64url_encode;

// address=[0x1c52ce0]
_curl_getenv;

// address=[0x1c52dc0]
_Curl_urldecode;

// address=[0x1c530a0]
_curl_easy_escape;

// address=[0x1c53290]
_curl_easy_unescape;

// address=[0x1c533d0]
_curl_escape;

// address=[0x1c53400]
_curl_free;

// address=[0x1c53430]
_curl_unescape;

// address=[0x1c53460]
_Curl_parsenetrc;

// address=[0x1c539b0]
_Curl_digest_cleanup;

// address=[0x1c539f0]
_Curl_input_digest;

// address=[0x1c53ae0]
_Curl_output_digest;

// address=[0x1c53e30]
_Curl_http_ntlm_cleanup;

// address=[0x1c53e70]
_Curl_input_ntlm;

// address=[0x1c54060]
_Curl_output_ntlm;

// address=[0x1c54410]
_Curl_SOCKS4;

// address=[0x1c550f0]
_Curl_SOCKS5;

// address=[0x1c56560]
_Curl_blockread_all;

// address=[0x1c57a30]
_Curl_proxyCONNECT;

// address=[0x1c57b30]
_Curl_proxy_connect;

// address=[0x1c57e10]
_Curl_dedotdotify;

// address=[0x1c58240]
_Curl_memdup;

// address=[0x1c582b0]
_Curl_saferealloc;

// address=[0x1c58330]
_Curl_if2ip;

// address=[0x1c58340]
_Curl_if_is_interface_name;

// address=[0x1c58350]
_Curl_ipv6_scope;

// address=[0x1c58360]
_curlx_nonblock;

// address=[0x1c58410]
_Curl_verify_windows_version;

// address=[0x1c58750]
_Curl_chunked_strerror;

// address=[0x1c587f0]
_Curl_httpchunk_init;

// address=[0x1c58840]
_Curl_httpchunk_read;

// address=[0x1c598f0]
_Curl_FormInit;

// address=[0x1c59940]
_Curl_FormReader;

// address=[0x1c59bc0]
_Curl_formclean;

// address=[0x1c59c70]
_Curl_formpostheader;

// address=[0x1c59ce0]
_Curl_getformdata;

// address=[0x1c5b680]
_curl_formadd;

// address=[0x1c5b6e0]
_curl_formfree;

// address=[0x1c5b800]
_curl_formget;

// address=[0x1c5bf20]
_Curl_auth_create_digest_http_message;

// address=[0x1c5c740]
_Curl_auth_create_digest_md5_message;

// address=[0x1c5d130]
_Curl_auth_decode_digest_http_message;

// address=[0x1c5d7c0]
_Curl_auth_digest_cleanup;

// address=[0x1c5d920]
_Curl_auth_digest_get_pair;

// address=[0x1c5dbd0]
_Curl_auth_is_digest_supported;

// address=[0x1c5e280]
_Curl_auth_create_ntlm_type1_message;

// address=[0x1c5e4e0]
_Curl_auth_create_ntlm_type3_message;

// address=[0x1c5f0c0]
_Curl_auth_decode_ntlm_type2_message;

// address=[0x1c5f350]
_Curl_auth_is_ntlm_supported;

// address=[0x1c5f360]
_Curl_auth_ntlm_cleanup;

// address=[0x1c5f540]
_Curl_fileinfo_alloc;

// address=[0x1c5f570]
_Curl_fileinfo_dtor;

// address=[0x1c5f5f0]
_Curl_cert_hostcheck;

// address=[0x1c5f9d0]
_Curl_rand;

// address=[0x1c5faf0]
_Curl_rand_hex;

// address=[0x1c5fe20]
_Curl_auth_build_spn;

// address=[0x1c5fed0]
_Curl_auth_user_contains_domain;

// address=[0x1c5ffa0]
_Curl_MD5_final;

// address=[0x1c60020]
_Curl_MD5_init;

// address=[0x1c600f0]
_Curl_MD5_update;

// address=[0x1c60140]
_Curl_md5it;

// address=[0x1c60210]
_Curl_hmac_md5;

// address=[0x1c60290]
_Curl_ntlm_core_lm_resp;

// address=[0x1c603d0]
_Curl_ntlm_core_mk_lm_hash;

// address=[0x1c60590]
_Curl_ntlm_core_mk_lmv2_resp;

// address=[0x1c606f0]
_Curl_ntlm_core_mk_nt_hash;

// address=[0x1c60860]
_Curl_ntlm_core_mk_ntlmv2_hash;

// address=[0x1c60970]
_Curl_ntlm_core_mk_ntlmv2_resp;

// address=[0x1c61000]
_Curl_gethostname;

// address=[0x1c610b0]
_Curl_read16_be;

// address=[0x1c610f0]
_Curl_read16_le;

// address=[0x1c61130]
_Curl_read32_le;

// address=[0x1c611a0]
_Curl_write32_le;

// address=[0x1c61230]
_Curl_write64_le;

// address=[0x1c61280]
_Curl_HMAC_final;

// address=[0x1c61370]
_Curl_HMAC_init;

// address=[0x1c61660]
_Curl_HMAC_update;

// address=[0x1c62010]
_CRYPTO_cleanup_all_ex_data;

// address=[0x1c62050]
_CRYPTO_dup_ex_data;

// address=[0x1c620a0]
_CRYPTO_ex_data_new_class;

// address=[0x1c620e0]
_CRYPTO_free_ex_data;

// address=[0x1c62130]
_CRYPTO_get_ex_data;

// address=[0x1c62190]
_CRYPTO_get_ex_data_implementation;

// address=[0x1c621c0]
_CRYPTO_get_ex_new_index;

// address=[0x1c62250]
_CRYPTO_new_ex_data;

// address=[0x1c622a0]
_CRYPTO_set_ex_data;

// address=[0x1c623b0]
_CRYPTO_set_ex_data_implementation;

// address=[0x1c62a40]
_CRYPTO_THREADID_cmp;

// address=[0x1c62a70]
_CRYPTO_THREADID_cpy;

// address=[0x1c62aa0]
_CRYPTO_THREADID_current;

// address=[0x1c62b30]
_CRYPTO_THREADID_get_callback;

// address=[0x1c62b40]
_CRYPTO_THREADID_hash;

// address=[0x1c62b50]
_CRYPTO_THREADID_set_callback;

// address=[0x1c62b80]
_CRYPTO_THREADID_set_numeric;

// address=[0x1c62bb0]
_CRYPTO_THREADID_set_pointer;

// address=[0x1c62cf0]
_CRYPTO_add_lock;

// address=[0x1c62dc0]
_CRYPTO_destroy_dynlockid;

// address=[0x1c62f40]
_CRYPTO_get_add_lock_callback;

// address=[0x1c62f50]
_CRYPTO_get_dynlock_create_callback;

// address=[0x1c62f60]
_CRYPTO_get_dynlock_destroy_callback;

// address=[0x1c62f70]
_CRYPTO_get_dynlock_lock_callback;

// address=[0x1c62f80]
_CRYPTO_get_dynlock_value;

// address=[0x1c63070]
_CRYPTO_get_id_callback;

// address=[0x1c63080]
_CRYPTO_get_lock_name;

// address=[0x1c63110]
_CRYPTO_get_locking_callback;

// address=[0x1c63120]
_CRYPTO_get_new_dynlockid;

// address=[0x1c633f0]
_CRYPTO_get_new_lockid;

// address=[0x1c63530]
_CRYPTO_lock;

// address=[0x1c63640]
_CRYPTO_memcmp;

// address=[0x1c636d0]
_CRYPTO_num_locks;

// address=[0x1c636e0]
_CRYPTO_set_add_lock_callback;

// address=[0x1c636f0]
_CRYPTO_set_dynlock_create_callback;

// address=[0x1c63700]
_CRYPTO_set_dynlock_destroy_callback;

// address=[0x1c63710]
_CRYPTO_set_dynlock_lock_callback;

// address=[0x1c63720]
_CRYPTO_set_id_callback;

// address=[0x1c63730]
_CRYPTO_set_locking_callback;

// address=[0x1c63750]
_CRYPTO_thread_id;

// address=[0x1c637d0]
_OPENSSL_cpuid_setup;

// address=[0x1c637e0]
_OPENSSL_ia32cap_loc;

// address=[0x1c63830]
_OPENSSL_isservice;

// address=[0x1c63ad0]
_OPENSSL_showfatal;

// address=[0x1c641e0]
_OPENSSL_stderr;

// address=[0x1c64200]
_OpenSSLDie;

// address=[0x1c642f0]
_CRYPTO_free;

// address=[0x1c64370]
_CRYPTO_free_locked;

// address=[0x1c643f0]
_CRYPTO_get_locked_mem_ex_functions;

// address=[0x1c64460]
_CRYPTO_get_locked_mem_functions;

// address=[0x1c644d0]
_CRYPTO_get_mem_debug_functions;

// address=[0x1c64540]
_CRYPTO_get_mem_debug_options;

// address=[0x1c64580]
_CRYPTO_get_mem_ex_functions;

// address=[0x1c64630]
_CRYPTO_get_mem_functions;

// address=[0x1c646e0]
_CRYPTO_malloc;

// address=[0x1c647f0]
_CRYPTO_malloc_locked;

// address=[0x1c64900]
_CRYPTO_realloc;

// address=[0x1c64a20]
_CRYPTO_realloc_clean;

// address=[0x1c64ba0]
_CRYPTO_remalloc;

// address=[0x1c64bf0]
_CRYPTO_set_locked_mem_ex_functions;

// address=[0x1c64c50]
_CRYPTO_set_locked_mem_functions;

// address=[0x1c64cb0]
_CRYPTO_set_mem_debug_functions;

// address=[0x1c64d20]
_CRYPTO_set_mem_debug_options;

// address=[0x1c64d60]
_CRYPTO_set_mem_ex_functions;

// address=[0x1c64e00]
_CRYPTO_set_mem_functions;

// address=[0x1c64eb0]
_CRYPTO_strdup;

// address=[0x1c64f30]
_FIPS_mode;

// address=[0x1c64f50]
_FIPS_mode_set;

// address=[0x1c65410]
_BIO_new_socket;

// address=[0x1c65480]
_BIO_s_socket;

// address=[0x1c65490]
_BIO_sock_non_fatal_error;

// address=[0x1c655b0]
_BIO_sock_should_retry;

// address=[0x1c65620]
_EVP_CIPHER_do_all;

// address=[0x1c656b0]
_EVP_CIPHER_do_all_sorted;

// address=[0x1c65740]
_EVP_MD_do_all;

// address=[0x1c657d0]
_EVP_MD_do_all_sorted;

// address=[0x1c65860]
_EVP_add_cipher;

// address=[0x1c65910]
_EVP_add_digest;

// address=[0x1c65a70]
_EVP_cleanup;

// address=[0x1c65ad0]
_EVP_get_cipherbyname;

// address=[0x1c65b20]
_EVP_get_digestbyname;

// address=[0x1c65cd0]
_SHA224;

// address=[0x1c65dc0]
_SHA224_Final;

// address=[0x1c65df0]
_SHA224_Init;

// address=[0x1c65ee0]
_SHA224_Update;

// address=[0x1c65f10]
_SHA256;

// address=[0x1c66000]
_SHA256_Final;

// address=[0x1c664b0]
_SHA256_Init;

// address=[0x1c665a0]
_SHA256_Transform;

// address=[0x1c665d0]
_SHA256_Update;

// address=[0x1c6a600]
_X509_CRL_diff;

// address=[0x1c6ab00]
_X509_STORE_CTX_cleanup;

// address=[0x1c6ac10]
_X509_STORE_CTX_free;

// address=[0x1c6ac50]
_X509_STORE_CTX_get0_current_crl;

// address=[0x1c6ac60]
_X509_STORE_CTX_get0_current_issuer;

// address=[0x1c6ac70]
_X509_STORE_CTX_get0_param;

// address=[0x1c6ac80]
_X509_STORE_CTX_get0_parent_ctx;

// address=[0x1c6ac90]
_X509_STORE_CTX_get0_policy_tree;

// address=[0x1c6aca0]
_X509_STORE_CTX_get1_chain;

// address=[0x1c6ace0]
_X509_STORE_CTX_get_chain;

// address=[0x1c6acf0]
_X509_STORE_CTX_get_current_cert;

// address=[0x1c6ad00]
_X509_STORE_CTX_get_error;

// address=[0x1c6ad10]
_X509_STORE_CTX_get_error_depth;

// address=[0x1c6ad20]
_X509_STORE_CTX_get_ex_data;

// address=[0x1c6ad50]
_X509_STORE_CTX_get_ex_new_index;

// address=[0x1c6ad90]
_X509_STORE_CTX_get_explicit_policy;

// address=[0x1c6ada0]
_X509_STORE_CTX_init;

// address=[0x1c6b250]
_X509_STORE_CTX_new;

// address=[0x1c6b2f0]
_X509_STORE_CTX_purpose_inherit;

// address=[0x1c6b4b0]
_X509_STORE_CTX_set0_crls;

// address=[0x1c6b4d0]
_X509_STORE_CTX_set0_param;

// address=[0x1c6b510]
_X509_STORE_CTX_set_cert;

// address=[0x1c6b530]
_X509_STORE_CTX_set_chain;

// address=[0x1c6b550]
_X509_STORE_CTX_set_default;

// address=[0x1c6b5c0]
_X509_STORE_CTX_set_depth;

// address=[0x1c6b5f0]
_X509_STORE_CTX_set_error;

// address=[0x1c6b610]
_X509_STORE_CTX_set_ex_data;

// address=[0x1c6b640]
_X509_STORE_CTX_set_flags;

// address=[0x1c6b670]
_X509_STORE_CTX_set_purpose;

// address=[0x1c6b6a0]
_X509_STORE_CTX_set_time;

// address=[0x1c6b6d0]
_X509_STORE_CTX_set_trust;

// address=[0x1c6b700]
_X509_STORE_CTX_set_verify_cb;

// address=[0x1c6b720]
_X509_STORE_CTX_trusted_stack;

// address=[0x1c6b740]
_X509_cmp_current_time;

// address=[0x1c6b760]
_X509_cmp_time;

// address=[0x1c6bd80]
_X509_get_pubkey_parameters;

// address=[0x1c6bf60]
_X509_gmtime_adj;

// address=[0x1c6bf90]
_X509_time_adj;

// address=[0x1c6bfc0]
_X509_time_adj_ex;

// address=[0x1c6c0f0]
_X509_verify_cert;

// address=[0x1c707a0]
_X509_PUBKEY_free;

// address=[0x1c707d0]
_X509_PUBKEY_get;

// address=[0x1c70a40]
_X509_PUBKEY_get0_param;

// address=[0x1c70aa0]
_X509_PUBKEY_it;

// address=[0x1c70ab0]
_X509_PUBKEY_new;

// address=[0x1c70ad0]
_X509_PUBKEY_set;

// address=[0x1c70c20]
_X509_PUBKEY_set0_param;

// address=[0x1c70ce0]
_d2i_DSA_PUBKEY;

// address=[0x1c70de0]
_d2i_EC_PUBKEY;

// address=[0x1c70ee0]
_d2i_PUBKEY;

// address=[0x1c70fe0]
_d2i_RSA_PUBKEY;

// address=[0x1c710e0]
_d2i_X509_PUBKEY;

// address=[0x1c71110]
_i2d_DSA_PUBKEY;

// address=[0x1c711d0]
_i2d_EC_PUBKEY;

// address=[0x1c71290]
_i2d_PUBKEY;

// address=[0x1c71360]
_i2d_RSA_PUBKEY;

// address=[0x1c71420]
_i2d_X509_PUBKEY;

// address=[0x1c71450]
_X509_CRL_check_suiteb;

// address=[0x1c714c0]
_X509_CRL_cmp;

// address=[0x1c714f0]
_X509_CRL_match;

// address=[0x1c71520]
_X509_NAME_cmp;

// address=[0x1c71610]
_X509_NAME_hash;

// address=[0x1c71760]
_X509_NAME_hash_old;

// address=[0x1c71910]
_X509_chain_check_suiteb;

// address=[0x1c71bc0]
_X509_chain_up_ref;

// address=[0x1c71c80]
_X509_check_private_key;

// address=[0x1c71db0]
_X509_cmp;

// address=[0x1c71ea0]
_X509_find_by_issuer_and_serial;

// address=[0x1c71ff0]
_X509_find_by_subject;

// address=[0x1c720a0]
_X509_get0_pubkey_bitstr;

// address=[0x1c720c0]
_X509_get_issuer_name;

// address=[0x1c720d0]
_X509_get_pubkey;

// address=[0x1c72110]
_X509_get_serialNumber;

// address=[0x1c72120]
_X509_get_subject_name;

// address=[0x1c72130]
_X509_issuer_and_serial_cmp;

// address=[0x1c721d0]
_X509_issuer_and_serial_hash;

// address=[0x1c723d0]
_X509_issuer_name_cmp;

// address=[0x1c72400]
_X509_issuer_name_hash;

// address=[0x1c72430]
_X509_issuer_name_hash_old;

// address=[0x1c72460]
_X509_subject_name_cmp;

// address=[0x1c72490]
_X509_subject_name_hash;

// address=[0x1c724c0]
_X509_subject_name_hash_old;

// address=[0x1c72630]
_X509_NAME_ENTRY_create_by_NID;

// address=[0x1c726e0]
_X509_NAME_ENTRY_create_by_OBJ;

// address=[0x1c727d0]
_X509_NAME_ENTRY_create_by_txt;

// address=[0x1c728a0]
_X509_NAME_ENTRY_get_data;

// address=[0x1c728c0]
_X509_NAME_ENTRY_get_object;

// address=[0x1c728e0]
_X509_NAME_ENTRY_set_data;

// address=[0x1c72a30]
_X509_NAME_ENTRY_set_object;

// address=[0x1c72ae0]
_X509_NAME_add_entry;

// address=[0x1c72d60]
_X509_NAME_add_entry_by_NID;

// address=[0x1c72e00]
_X509_NAME_add_entry_by_OBJ;

// address=[0x1c72ea0]
_X509_NAME_add_entry_by_txt;

// address=[0x1c72f40]
_X509_NAME_delete_entry;

// address=[0x1c730c0]
_X509_NAME_entry_count;

// address=[0x1c730f0]
_X509_NAME_get_entry;

// address=[0x1c73150]
_X509_NAME_get_index_by_NID;

// address=[0x1c731c0]
_X509_NAME_get_index_by_OBJ;

// address=[0x1c732a0]
_X509_NAME_get_text_by_NID;

// address=[0x1c73310]
_X509_NAME_get_text_by_OBJ;

// address=[0x1c73410]
_ssl_undefined_function;

// address=[0x1c73450]
_OBJ_bsearch_ssl_cipher_id;

// address=[0x1c73480]
_SSL_CTX_callback_ctrl;

// address=[0x1c73500]
_SSL_CTX_check_private_key;

// address=[0x1c735e0]
_SSL_CTX_ctrl;

// address=[0x1c73af0]
_SSL_CTX_free;

// address=[0x1c73e10]
_SSL_CTX_get0_certificate;

// address=[0x1c73e40]
_SSL_CTX_get0_param;

// address=[0x1c73e60]
_SSL_CTX_get0_privatekey;

// address=[0x1c73e90]
_SSL_CTX_get_cert_store;

// address=[0x1c73ea0]
_SSL_CTX_get_ex_data;

// address=[0x1c73ed0]
_SSL_CTX_get_ex_new_index;

// address=[0x1c73f10]
_SSL_CTX_get_quiet_shutdown;

// address=[0x1c73f30]
_SSL_CTX_get_ssl_method;

// address=[0x1c73f40]
_SSL_CTX_get_verify_callback;

// address=[0x1c73f60]
_SSL_CTX_get_verify_depth;

// address=[0x1c73f90]
_SSL_CTX_get_verify_mode;

// address=[0x1c73fb0]
_SSL_CTX_load_verify_locations;

// address=[0x1c73fe0]
_SSL_CTX_new;

// address=[0x1c747f0]
_SSL_CTX_sessions;

// address=[0x1c74800]
_SSL_CTX_set1_param;

// address=[0x1c74830]
_SSL_CTX_set_alpn_protos;

// address=[0x1c748e0]
_SSL_CTX_set_alpn_select_cb;

// address=[0x1c74910]
_SSL_CTX_set_cert_cb;

// address=[0x1c74940]
_SSL_CTX_set_cert_store;

// address=[0x1c74980]
_SSL_CTX_set_cert_verify_callback;

// address=[0x1c749a0]
_SSL_CTX_set_cipher_list;

// address=[0x1c74a60]
_SSL_CTX_set_default_passwd_cb;

// address=[0x1c74a80]
_SSL_CTX_set_default_passwd_cb_userdata;

// address=[0x1c74aa0]
_SSL_CTX_set_default_verify_paths;

// address=[0x1c74ad0]
_SSL_CTX_set_ex_data;

// address=[0x1c74b00]
_SSL_CTX_set_generate_session_id;

// address=[0x1c74b60]
_SSL_CTX_set_msg_callback;

// address=[0x1c74b90]
_SSL_CTX_set_next_proto_select_cb;

// address=[0x1c74bc0]
_SSL_CTX_set_next_protos_advertised_cb;

// address=[0x1c74bf0]
_SSL_CTX_set_psk_client_callback;

// address=[0x1c74c10]
_SSL_CTX_set_psk_server_callback;

// address=[0x1c74c30]
_SSL_CTX_set_purpose;

// address=[0x1c74c60]
_SSL_CTX_set_quiet_shutdown;

// address=[0x1c74c80]
_SSL_CTX_set_session_id_context;

// address=[0x1c74d00]
_SSL_CTX_set_ssl_version;

// address=[0x1c74de0]
_SSL_CTX_set_tmp_dh_callback;

// address=[0x1c74e10]
_SSL_CTX_set_tmp_ecdh_callback;

// address=[0x1c74e40]
_SSL_CTX_set_tmp_rsa_callback;

// address=[0x1c74e70]
_SSL_CTX_set_trust;

// address=[0x1c74ea0]
_SSL_CTX_set_verify;

// address=[0x1c74ed0]
_SSL_CTX_set_verify_depth;

// address=[0x1c74f00]
_SSL_CTX_use_psk_identity_hint;

// address=[0x1c74fd0]
_SSL_accept;

// address=[0x1c75020]
_SSL_cache_hit;

// address=[0x1c75030]
_SSL_callback_ctrl;

// address=[0x1c750b0]
_SSL_certs_clear;

// address=[0x1c750e0]
_SSL_check_private_key;

// address=[0x1c75210]
_SSL_clear;

// address=[0x1c75550]
_SSL_connect;

// address=[0x1c755a0]
_SSL_copy_session_id;

// address=[0x1c75710]
_SSL_ctrl;

// address=[0x1c75b10]
_SSL_do_handshake;

// address=[0x1c75c00]
_SSL_dup;

// address=[0x1c761e0]
_SSL_export_keying_material;

// address=[0x1c76260]
_SSL_free;

// address=[0x1c766e0]
_SSL_get0_alpn_selected;

// address=[0x1c76740]
_SSL_get0_next_proto_negotiated;

// address=[0x1c76790]
_SSL_get0_param;

// address=[0x1c767a0]
_SSL_get_SSL_CTX;

// address=[0x1c767c0]
_SSL_get_certificate;

// address=[0x1c767f0]
_SSL_get_cipher_list;

// address=[0x1c76890]
_SSL_get_ciphers;

// address=[0x1c768f0]
_SSL_get_current_cipher;

// address=[0x1c76940]
_SSL_get_current_compression;

// address=[0x1c76970]
_SSL_get_current_expansion;

// address=[0x1c769a0]
_SSL_get_default_timeout;

// address=[0x1c769d0]
_SSL_get_error;

// address=[0x1c76ca0]
_SSL_get_ex_data;

// address=[0x1c76cd0]
_SSL_get_ex_new_index;

// address=[0x1c76d10]
_SSL_get_fd;

// address=[0x1c76d30]
_SSL_get_finished;

// address=[0x1c76dc0]
_SSL_get_info_callback;

// address=[0x1c76de0]
_SSL_get_peer_cert_chain;

// address=[0x1c76e60]
_SSL_get_peer_certificate;

// address=[0x1c76f00]
_SSL_get_peer_finished;

// address=[0x1c76f90]
_SSL_get_privatekey;

// address=[0x1c76fc0]
_SSL_get_psk_identity;

// address=[0x1c77000]
_SSL_get_psk_identity_hint;

// address=[0x1c77040]
_SSL_get_quiet_shutdown;

// address=[0x1c77050]
_SSL_get_rbio;

// address=[0x1c77060]
_SSL_get_read_ahead;

// address=[0x1c77070]
_SSL_get_rfd;

// address=[0x1c77140]
_SSL_get_servername;

// address=[0x1c771c0]
_SSL_get_servername_type;

// address=[0x1c77260]
_SSL_get_shared_ciphers;

// address=[0x1c77400]
_SSL_get_shutdown;

// address=[0x1c77410]
_SSL_get_ssl_method;

// address=[0x1c77420]
_SSL_get_verify_callback;

// address=[0x1c77440]
_SSL_get_verify_depth;

// address=[0x1c77470]
_SSL_get_verify_mode;

// address=[0x1c77490]
_SSL_get_verify_result;

// address=[0x1c774b0]
_SSL_get_version;

// address=[0x1c77590]
_SSL_get_wbio;

// address=[0x1c775a0]
_SSL_get_wfd;

// address=[0x1c77670]
_SSL_has_matching_session_id;

// address=[0x1c77820]
_SSL_is_server;

// address=[0x1c77830]
_SSL_new;

// address=[0x1c77ee0]
_SSL_peek;

// address=[0x1c77f70]
_SSL_pending;

// address=[0x1c77fb0]
_SSL_read;

// address=[0x1c78050]
_SSL_renegotiate;

// address=[0x1c780b0]
_SSL_renegotiate_abbreviated;

// address=[0x1c78110]
_SSL_renegotiate_pending;

// address=[0x1c78160]
_SSL_select_next_proto;

// address=[0x1c782c0]
_SSL_set1_param;

// address=[0x1c782f0]
_SSL_set_SSL_CTX;

// address=[0x1c78690]
_SSL_set_accept_state;

// address=[0x1c78720]
_SSL_set_alpn_protos;

// address=[0x1c787d0]
_SSL_set_bio;

// address=[0x1c788a0]
_SSL_set_cert_cb;

// address=[0x1c788d0]
_SSL_set_cipher_list;

// address=[0x1c78990]
_SSL_set_connect_state;

// address=[0x1c78a20]
_SSL_set_debug;

// address=[0x1c78a40]
_SSL_set_ex_data;

// address=[0x1c78a70]
_SSL_set_fd;

// address=[0x1c78b40]
_SSL_set_generate_session_id;

// address=[0x1c78ba0]
_SSL_set_info_callback;

// address=[0x1c78bc0]
_SSL_set_msg_callback;

// address=[0x1c78bf0]
_SSL_set_psk_client_callback;

// address=[0x1c78c10]
_SSL_set_psk_server_callback;

// address=[0x1c78c30]
_SSL_set_purpose;

// address=[0x1c78c60]
_SSL_set_quiet_shutdown;

// address=[0x1c78c80]
_SSL_set_read_ahead;

// address=[0x1c78ca0]
_SSL_set_rfd;

// address=[0x1c78df0]
_SSL_set_session_id_context;

// address=[0x1c78e70]
_SSL_set_shutdown;

// address=[0x1c78e90]
_SSL_set_ssl_method;

// address=[0x1c78fe0]
_SSL_set_state;

// address=[0x1c79000]
_SSL_set_tmp_dh_callback;

// address=[0x1c79030]
_SSL_set_tmp_ecdh_callback;

// address=[0x1c79060]
_SSL_set_tmp_rsa_callback;

// address=[0x1c79090]
_SSL_set_trust;

// address=[0x1c790c0]
_SSL_set_verify;

// address=[0x1c790f0]
_SSL_set_verify_depth;

// address=[0x1c79120]
_SSL_set_verify_result;

// address=[0x1c79140]
_SSL_set_wfd;

// address=[0x1c79290]
_SSL_shutdown;

// address=[0x1c79340]
_SSL_state;

// address=[0x1c79350]
_SSL_use_psk_identity_hint;

// address=[0x1c79470]
_SSL_version;

// address=[0x1c79480]
_SSL_want;

// address=[0x1c79490]
_SSL_write;

// address=[0x1c79550]
_ssl_bad_method;

// address=[0x1c79610]
_ssl_bytes_to_cipher_list;

// address=[0x1c79a40]
_ssl_check_srvr_ecc_cert_and_alg;

// address=[0x1c79d90]
_ssl_cipher_id_cmp;

// address=[0x1c79e60]
_ssl_cipher_list_to_bytes;

// address=[0x1c7a060]
_ssl_cipher_ptr_id_cmp;

// address=[0x1c7a0d0]
_ssl_clear_cipher_ctx;

// address=[0x1c7a1f0]
_ssl_clear_hash_ctx;

// address=[0x1c7a230]
_ssl_free_wbio_buffer;

// address=[0x1c7a2a0]
_ssl_get_ciphers_by_id;

// address=[0x1c7a3b0]
_ssl_get_server_cert_serverinfo;

// address=[0x1c7a480]
_ssl_get_server_send_pkey;

// address=[0x1c7a540]
_ssl_get_sign_pkey;

// address=[0x1c7a6a0]
_ssl_init_wbio_buffer;

// address=[0x1c7a800]
_ssl_ok;

// address=[0x1c7a810]
_ssl_replace_hash;

// address=[0x1c7ab00]
_ssl_set_cert_masks;

// address=[0x1c7b3c0]
_ssl_undefined_const_function;

// address=[0x1c7b400]
_ssl_undefined_void_function;

// address=[0x1c7b440]
_ssl_update_cache;

// address=[0x1c7b620]
_SSL_load_error_strings;

// address=[0x1c7b6b0]
_ssl23_connect;

// address=[0x1c7bbd0]
_SSLv23_client_method;

// address=[0x1c7d090]
_ssl_fill_hello_random;

// address=[0x1c7d220]
_SSL_library_init;

// address=[0x1c7d4a0]
_SSL_CIPHER_description;

// address=[0x1c7dd80]
_SSL_CIPHER_find;

// address=[0x1c7ddc0]
_SSL_CIPHER_get_bits;

// address=[0x1c7de20]
_SSL_CIPHER_get_id;

// address=[0x1c7de30]
_SSL_CIPHER_get_name;

// address=[0x1c7de50]
_SSL_CIPHER_get_version;

// address=[0x1c7dec0]
_SSL_COMP_add_compression_method;

// address=[0x1c7e0e0]
_SSL_COMP_free_compression_methods;

// address=[0x1c7e140]
_SSL_COMP_get_compression_methods;

// address=[0x1c7e160]
_SSL_COMP_get_name;

// address=[0x1c7e180]
_SSL_COMP_set0_compression_methods;

// address=[0x1c7e890]
_ssl3_comp_find;

// address=[0x1c7f130]
_ssl_cipher_get_cert_index;

// address=[0x1c7f7a0]
_ssl_cipher_get_evp;

// address=[0x1c807f0]
_ssl_create_cipher_list;

// address=[0x1c80f40]
_ssl_get_cipher_by_char;

// address=[0x1c80fb0]
_ssl_get_handshake_digest;

// address=[0x1c81010]
_ssl_load_ciphers;

// address=[0x1c814f0]
_CONF_get1_default_config_file;

// address=[0x1c81620]
_CONF_imodule_get_flags;

// address=[0x1c81630]
_CONF_imodule_get_module;

// address=[0x1c81640]
_CONF_imodule_get_name;

// address=[0x1c81650]
_CONF_imodule_get_usr_data;

// address=[0x1c81660]
_CONF_imodule_get_value;

// address=[0x1c81670]
_CONF_imodule_set_flags;

// address=[0x1c81690]
_CONF_imodule_set_usr_data;

// address=[0x1c816b0]
_CONF_module_add;

// address=[0x1c816f0]
_CONF_module_get_usr_data;

// address=[0x1c81700]
_CONF_module_set_usr_data;

// address=[0x1c81720]
_CONF_modules_finish;

// address=[0x1c817b0]
_CONF_modules_free;

// address=[0x1c817e0]
_CONF_modules_load;

// address=[0x1c81960]
_CONF_modules_load_file;

// address=[0x1c81a90]
_CONF_modules_unload;

// address=[0x1c81b90]
_CONF_parse_list;

// address=[0x1c83030]
_ERR_add_error_data;

// address=[0x1c83080]
_ERR_add_error_vdata;

// address=[0x1c83210]
_ERR_clear_error;

// address=[0x1c83380]
_ERR_error_string;

// address=[0x1c833c0]
_ERR_error_string_n;

// address=[0x1c83750]
_ERR_free_strings;

// address=[0x1c83780]
_ERR_func_error_string;

// address=[0x1c83890]
_ERR_get_err_state_table;

// address=[0x1c838d0]
_ERR_get_error;

// address=[0x1c83900]
_ERR_get_error_line;

// address=[0x1c83930]
_ERR_get_error_line_data;

// address=[0x1c83970]
_ERR_get_implementation;

// address=[0x1c83990]
_ERR_get_next_error_library;

// address=[0x1c839c0]
_ERR_get_state;

// address=[0x1c83c30]
_ERR_get_string_table;

// address=[0x1c83c70]
_ERR_lib_error_string;

// address=[0x1c83d60]
_ERR_load_ERR_strings;

// address=[0x1c83dd0]
_ERR_load_strings;

// address=[0x1c83e00]
_ERR_peek_error;

// address=[0x1c83e30]
_ERR_peek_error_line;

// address=[0x1c83e60]
_ERR_peek_error_line_data;

// address=[0x1c83ea0]
_ERR_peek_last_error;

// address=[0x1c83ed0]
_ERR_peek_last_error_line;

// address=[0x1c83f00]
_ERR_peek_last_error_line_data;

// address=[0x1c83f40]
_ERR_pop_to_mark;

// address=[0x1c84170]
_ERR_put_error;

// address=[0x1c84350]
_ERR_reason_error_string;

// address=[0x1c844a0]
_ERR_release_err_state_table;

// address=[0x1c844e0]
_ERR_remove_state;

// address=[0x1c84500]
_ERR_remove_thread_state;

// address=[0x1c845f0]
_ERR_set_error_data;

// address=[0x1c846f0]
_ERR_set_implementation;

// address=[0x1c84780]
_ERR_set_mark;

// address=[0x1c84820]
_ERR_unload_strings;

// address=[0x1c85070]
_ENGINE_cleanup;

// address=[0x1c850d0]
_ENGINE_free;

// address=[0x1c850f0]
_ENGINE_get_cmd_defns;

// address=[0x1c85100]
_ENGINE_get_ctrl_function;

// address=[0x1c85110]
_ENGINE_get_destroy_function;

// address=[0x1c85120]
_ENGINE_get_ex_data;

// address=[0x1c85150]
_ENGINE_get_ex_new_index;

// address=[0x1c85190]
_ENGINE_get_finish_function;

// address=[0x1c851a0]
_ENGINE_get_flags;

// address=[0x1c851b0]
_ENGINE_get_id;

// address=[0x1c851c0]
_ENGINE_get_init_function;

// address=[0x1c851d0]
_ENGINE_get_name;

// address=[0x1c851e0]
_ENGINE_get_static_state;

// address=[0x1c851f0]
_ENGINE_new;

// address=[0x1c852a0]
_ENGINE_set_cmd_defns;

// address=[0x1c852c0]
_ENGINE_set_ctrl_function;

// address=[0x1c852e0]
_ENGINE_set_destroy_function;

// address=[0x1c85300]
_ENGINE_set_ex_data;

// address=[0x1c85330]
_ENGINE_set_finish_function;

// address=[0x1c85350]
_ENGINE_set_flags;

// address=[0x1c85370]
_ENGINE_set_id;

// address=[0x1c853c0]
_ENGINE_set_init_function;

// address=[0x1c853e0]
_ENGINE_set_name;

// address=[0x1c85430]
_engine_cleanup_add_first;

// address=[0x1c854b0]
_engine_cleanup_add_last;

// address=[0x1c85560]
_engine_free_util;

// address=[0x1c856a0]
_engine_set_all_null;

// address=[0x1c85980]
_sk_deep_copy;

// address=[0x1c85bb0]
_sk_delete;

// address=[0x1c85c90]
_sk_delete_ptr;

// address=[0x1c85d10]
_sk_dup;

// address=[0x1c85e30]
_sk_find;

// address=[0x1c85e60]
_sk_find_ex;

// address=[0x1c85e90]
_sk_free;

// address=[0x1c85ee0]
_sk_insert;

// address=[0x1c86060]
_sk_is_sorted;

// address=[0x1c86080]
_sk_new;

// address=[0x1c861a0]
_sk_new_null;

// address=[0x1c861c0]
_sk_num;

// address=[0x1c861e0]
_sk_pop;

// address=[0x1c86230]
_sk_pop_free;

// address=[0x1c862e0]
_sk_push;

// address=[0x1c86310]
_sk_set;

// address=[0x1c86350]
_sk_set_cmp_func;

// address=[0x1c863b0]
_sk_shift;

// address=[0x1c863f0]
_sk_sort;

// address=[0x1c86480]
_sk_unshift;

// address=[0x1c864b0]
_sk_value;

// address=[0x1c864f0]
_sk_zero;

// address=[0x1c86550]
_SSLeay;

// address=[0x1c86560]
_SSLeay_version;

// address=[0x1c865c0]
_BIO_callback_ctrl;

// address=[0x1c86710]
_BIO_clear_flags;

// address=[0x1c86730]
_BIO_copy_next_retry;

// address=[0x1c86780]
_BIO_ctrl;

// address=[0x1c868d0]
_BIO_ctrl_pending;

// address=[0x1c86900]
_BIO_ctrl_wpending;

// address=[0x1c86930]
_BIO_dup_chain;

// address=[0x1c86ad0]
_BIO_find_type;

// address=[0x1c86b70]
_BIO_free;

// address=[0x1c86ca0]
_BIO_free_all;

// address=[0x1c86d20]
_BIO_get_callback;

// address=[0x1c86d30]
_BIO_get_callback_arg;

// address=[0x1c86d40]
_BIO_get_ex_data;

// address=[0x1c86d70]
_BIO_get_ex_new_index;

// address=[0x1c86db0]
_BIO_get_retry_BIO;

// address=[0x1c86e50]
_BIO_get_retry_reason;

// address=[0x1c86e60]
_BIO_gets;

// address=[0x1c86fd0]
_BIO_indent;

// address=[0x1c87060]
_BIO_int_ctrl;

// address=[0x1c87100]
_BIO_method_name;

// address=[0x1c87110]
_BIO_method_type;

// address=[0x1c87120]
_BIO_new;

// address=[0x1c871d0]
_BIO_next;

// address=[0x1c871f0]
_BIO_number_read;

// address=[0x1c87210]
_BIO_number_written;

// address=[0x1c87230]
_BIO_pop;

// address=[0x1c872f0]
_BIO_ptr_ctrl;

// address=[0x1c873a0]
_BIO_push;

// address=[0x1c87440]
_BIO_puts;

// address=[0x1c875c0]
_BIO_read;

// address=[0x1c87750]
_BIO_set;

// address=[0x1c87880]
_BIO_set_callback;

// address=[0x1c878a0]
_BIO_set_callback_arg;

// address=[0x1c878c0]
_BIO_set_ex_data;

// address=[0x1c878f0]
_BIO_set_flags;

// address=[0x1c87910]
_BIO_test_flags;

// address=[0x1c87930]
_BIO_vfree;

// address=[0x1c87950]
_BIO_write;

// address=[0x1c88320]
_BIO_new_mem_buf;

// address=[0x1c88420]
_BIO_s_mem;

// address=[0x1c88430]
_BIO_printf;

// address=[0x1c884a0]
_BIO_snprintf;

// address=[0x1c88510]
_BIO_vprintf;

// address=[0x1c88740]
_BIO_vsnprintf;

// address=[0x1c8a440]
_BN_bin2bn;

// address=[0x1c8a6a0]
_BN_bn2bin;

// address=[0x1c8a780]
_BN_clear;

// address=[0x1c8a7d0]
_BN_clear_bit;

// address=[0x1c8a900]
_BN_clear_free;

// address=[0x1c8a9c0]
_BN_cmp;

// address=[0x1c8ab40]
_BN_consttime_swap;

// address=[0x1c8b220]
_BN_copy;

// address=[0x1c8b4a0]
_BN_dup;

// address=[0x1c8b520]
_BN_free;

// address=[0x1c8b5b0]
_BN_get_params;

// address=[0x1c8b610]
_BN_get_word;

// address=[0x1c8b650]
_BN_init;

// address=[0x1c8b680]
_BN_is_bit_set;

// address=[0x1c8b710]
_BN_mask_bits;

// address=[0x1c8b860]
_BN_new;

// address=[0x1c8b920]
_BN_num_bits;

// address=[0x1c8b990]
_BN_num_bits_word;

// address=[0x1c8ba20]
_BN_set_bit;

// address=[0x1c8bb60]
_BN_set_negative;

// address=[0x1c8bba0]
_BN_set_params;

// address=[0x1c8bc80]
_BN_set_word;

// address=[0x1c8bd40]
_BN_swap;

// address=[0x1c8be50]
_BN_ucmp;

// address=[0x1c8bf30]
_BN_value_one;

// address=[0x1c8bf40]
_bn_cmp_part_words;

// address=[0x1c8c020]
_bn_cmp_words;

// address=[0x1c8c110]
_bn_dup_expand;

// address=[0x1c8c1f0]
_bn_expand2;

// address=[0x1c8c540]
_BN_asc2bn;

// address=[0x1c8c650]
_BN_bn2dec;

// address=[0x1c8c980]
_BN_bn2hex;

// address=[0x1c8cb40]
_BN_dec2bn;

// address=[0x1c8ce90]
_BN_hex2bn;

// address=[0x1c8d250]
_BN_options;

// address=[0x1c8d2a0]
_BN_print;

// address=[0x1c8d400]
_BN_print_fp;

// address=[0x1c8d4a0]
_ASN1_STRING_clear_free;

// address=[0x1c8d500]
_ASN1_STRING_cmp;

// address=[0x1c8d590]
_ASN1_STRING_copy;

// address=[0x1c8d600]
_ASN1_STRING_data;

// address=[0x1c8d610]
_ASN1_STRING_dup;

// address=[0x1c8d690]
_ASN1_STRING_free;

// address=[0x1c8d6f0]
_ASN1_STRING_length;

// address=[0x1c8d700]
_ASN1_STRING_length_set;

// address=[0x1c8d710]
_ASN1_STRING_new;

// address=[0x1c8d730]
_ASN1_STRING_set;

// address=[0x1c8d8a0]
_ASN1_STRING_set0;

// address=[0x1c8d8f0]
_ASN1_STRING_type;

// address=[0x1c8d900]
_ASN1_STRING_type_new;

// address=[0x1c8d9b0]
_ASN1_check_infinite_end;

// address=[0x1c8d9e0]
_ASN1_const_check_infinite_end;

// address=[0x1c8da10]
_ASN1_get_object;

// address=[0x1c8dcb0]
_ASN1_object_size;

// address=[0x1c8dd90]
_ASN1_put_eoc;

// address=[0x1c8ddf0]
_ASN1_put_object;

// address=[0x1c8e100]
_asn1_Finish;

// address=[0x1c8e120]
_asn1_GetSequence;

// address=[0x1c8e240]
_asn1_add_error;

// address=[0x1c8e340]
_asn1_const_Finish;

// address=[0x1c8e630]
_ASN1_OBJECT_create;

// address=[0x1c8e6f0]
_ASN1_OBJECT_free;

// address=[0x1c8e7d0]
_ASN1_OBJECT_new;

// address=[0x1c8e890]
_a2d_ASN1_OBJECT;

// address=[0x1c8ee60]
_c2i_ASN1_OBJECT;

// address=[0x1c8f160]
_d2i_ASN1_OBJECT;

// address=[0x1c8f2d0]
_i2a_ASN1_OBJECT;

// address=[0x1c8f460]
_i2d_ASN1_OBJECT;

// address=[0x1c8f580]
_i2t_ASN1_OBJECT;

// address=[0x1c8f5b0]
_ASN1_INTEGER_cmp;

// address=[0x1c8f660]
_ASN1_INTEGER_dup;

// address=[0x1c8f680]
_ASN1_INTEGER_get;

// address=[0x1c8f780]
_ASN1_INTEGER_set;

// address=[0x1c8f990]
_ASN1_INTEGER_to_BN;

// address=[0x1c8fa30]
_BN_to_ASN1_INTEGER;

// address=[0x1c8fc10]
_c2i_ASN1_INTEGER;

// address=[0x1c8ff70]
_d2i_ASN1_UINTEGER;

// address=[0x1c90220]
_i2c_ASN1_INTEGER;

// address=[0x1c90520]
_ASN1_STRING_print_ex;

// address=[0x1c90550]
_ASN1_STRING_print_ex_fp;

// address=[0x1c90580]
_ASN1_STRING_to_UTF8;

// address=[0x1c906d0]
_X509_NAME_print_ex;

// address=[0x1c90730]
_X509_NAME_print_ex_fp;

// address=[0x1c91ca0]
_ASN1_GENERALIZEDTIME_print;

// address=[0x1c920f0]
_ASN1_STRING_print;

// address=[0x1c922a0]
_ASN1_TIME_print;

// address=[0x1c92310]
_ASN1_UTCTIME_print;

// address=[0x1c92680]
_X509_NAME_print;

// address=[0x1c928c0]
_X509_ocspid_print;

// address=[0x1c92b70]
_X509_print;

// address=[0x1c92ba0]
_X509_print_ex;

// address=[0x1c93370]
_X509_print_ex_fp;

// address=[0x1c93430]
_X509_print_fp;

// address=[0x1c93460]
_X509_signature_dump;

// address=[0x1c935b0]
_X509_signature_print;

// address=[0x1c93770]
_OPENSSL_add_all_algorithms_noconf;

// address=[0x1c937a0]
_EVP_PKEY_assign;

// address=[0x1c93820]
_EVP_PKEY_base_id;

// address=[0x1c93840]
_EVP_PKEY_bits;

// address=[0x1c938a0]
_EVP_PKEY_cmp;

// address=[0x1c93980]
_EVP_PKEY_cmp_parameters;

// address=[0x1c939f0]
_EVP_PKEY_copy_parameters;

// address=[0x1c93b10]
_EVP_PKEY_free;

// address=[0x1c93c50]
_EVP_PKEY_get0;

// address=[0x1c93c60]
_EVP_PKEY_get1_DH;

// address=[0x1c93cd0]
_EVP_PKEY_get1_DSA;

// address=[0x1c93d30]
_EVP_PKEY_get1_EC_KEY;

// address=[0x1c93da0]
_EVP_PKEY_get1_RSA;

// address=[0x1c93e00]
_EVP_PKEY_get_default_digest_nid;

// address=[0x1c93e60]
_EVP_PKEY_id;

// address=[0x1c93e70]
_EVP_PKEY_missing_parameters;

// address=[0x1c93ed0]
_EVP_PKEY_new;

// address=[0x1c93fb0]
_EVP_PKEY_print_params;

// address=[0x1c94030]
_EVP_PKEY_print_private;

// address=[0x1c940b0]
_EVP_PKEY_print_public;

// address=[0x1c94130]
_EVP_PKEY_save_parameters;

// address=[0x1c941c0]
_EVP_PKEY_set1_DH;

// address=[0x1c94220]
_EVP_PKEY_set1_DSA;

// address=[0x1c94280]
_EVP_PKEY_set1_EC_KEY;

// address=[0x1c942f0]
_EVP_PKEY_set1_RSA;

// address=[0x1c94350]
_EVP_PKEY_set_type;

// address=[0x1c94380]
_EVP_PKEY_set_type_str;

// address=[0x1c943b0]
_EVP_PKEY_size;

// address=[0x1c94410]
_EVP_PKEY_type;

// address=[0x1c946e0]
_X509_LOOKUP_by_alias;

// address=[0x1c94750]
_X509_LOOKUP_by_fingerprint;

// address=[0x1c947c0]
_X509_LOOKUP_by_issuer_serial;

// address=[0x1c94830]
_X509_LOOKUP_by_subject;

// address=[0x1c948b0]
_X509_LOOKUP_ctrl;

// address=[0x1c94930]
_X509_LOOKUP_free;

// address=[0x1c949a0]
_X509_LOOKUP_init;

// address=[0x1c94a00]
_X509_LOOKUP_new;

// address=[0x1c94ae0]
_X509_LOOKUP_shutdown;

// address=[0x1c94b40]
_X509_OBJECT_free_contents;

// address=[0x1c94bb0]
_X509_OBJECT_idx_by_subject;

// address=[0x1c94be0]
_X509_OBJECT_retrieve_by_subject;

// address=[0x1c94c50]
_X509_OBJECT_retrieve_match;

// address=[0x1c94df0]
_X509_OBJECT_up_ref_count;

// address=[0x1c94e90]
_X509_STORE_CTX_get0_store;

// address=[0x1c94ea0]
_X509_STORE_CTX_get1_issuer;

// address=[0x1c95170]
_X509_STORE_add_cert;

// address=[0x1c95330]
_X509_STORE_add_crl;

// address=[0x1c954f0]
_X509_STORE_add_lookup;

// address=[0x1c95600]
_X509_STORE_free;

// address=[0x1c95760]
_X509_STORE_get1_certs;

// address=[0x1c95a20]
_X509_STORE_get1_crls;

// address=[0x1c95cb0]
_X509_STORE_get_by_subject;

// address=[0x1c95e90]
_X509_STORE_new;

// address=[0x1c96080]
_X509_STORE_set1_param;

// address=[0x1c960b0]
_X509_STORE_set_depth;

// address=[0x1c960e0]
_X509_STORE_set_flags;

// address=[0x1c96110]
_X509_STORE_set_lookup_crls_cb;

// address=[0x1c96130]
_X509_STORE_set_purpose;

// address=[0x1c96160]
_X509_STORE_set_trust;

// address=[0x1c96190]
_X509_STORE_set_verify_cb;

// address=[0x1c96720]
_X509_LOOKUP_file;

// address=[0x1c96730]
_X509_load_cert_crl_file;

// address=[0x1c96910]
_X509_load_cert_file;

// address=[0x1c96b80]
_X509_load_crl_file;

// address=[0x1c96df0]
_X509_verify_cert_error_string;

// address=[0x1c972c0]
_X509_CINF_it;

// address=[0x1c974d0]
_X509_CINF_free;

// address=[0x1c97500]
_X509_CINF_new;

// address=[0x1c97520]
_X509_dup;

// address=[0x1c97550]
_X509_free;

// address=[0x1c97580]
_X509_get0_signature;

// address=[0x1c975b0]
_X509_get_ex_data;

// address=[0x1c975e0]
_X509_get_ex_new_index;

// address=[0x1c97620]
_X509_get_signature_nid;

// address=[0x1c97650]
_X509_it;

// address=[0x1c97660]
_X509_new;

// address=[0x1c97680]
_X509_set_ex_data;

// address=[0x1c976b0]
_d2i_X509;

// address=[0x1c976e0]
_d2i_X509_AUX;

// address=[0x1c97820]
_d2i_X509_CINF;

// address=[0x1c97850]
_i2d_X509;

// address=[0x1c97880]
_i2d_X509_AUX;

// address=[0x1c979b0]
_i2d_X509_CINF;

// address=[0x1c979e0]
_i2d_re_X509_tbs;

// address=[0x1c97b40]
_X509_CRL_add1_ext_i2d;

// address=[0x1c97b80]
_X509_CRL_add_ext;

// address=[0x1c97bf0]
_X509_CRL_delete_ext;

// address=[0x1c97c20]
_X509_CRL_get_ext;

// address=[0x1c97c50]
_X509_CRL_get_ext_by_NID;

// address=[0x1c97c80]
_X509_CRL_get_ext_by_OBJ;

// address=[0x1c97cb0]
_X509_CRL_get_ext_by_critical;

// address=[0x1c97ce0]
_X509_CRL_get_ext_count;

// address=[0x1c97d10]
_X509_CRL_get_ext_d2i;

// address=[0x1c97d50]
_X509_REVOKED_add1_ext_i2d;

// address=[0x1c97d90]
_X509_REVOKED_add_ext;

// address=[0x1c97e00]
_X509_REVOKED_delete_ext;

// address=[0x1c97e30]
_X509_REVOKED_get_ext;

// address=[0x1c97e60]
_X509_REVOKED_get_ext_by_NID;

// address=[0x1c97e90]
_X509_REVOKED_get_ext_by_OBJ;

// address=[0x1c97ec0]
_X509_REVOKED_get_ext_by_critical;

// address=[0x1c97ef0]
_X509_REVOKED_get_ext_count;

// address=[0x1c97f20]
_X509_REVOKED_get_ext_d2i;

// address=[0x1c97f50]
_X509_add1_ext_i2d;

// address=[0x1c97f90]
_X509_add_ext;

// address=[0x1c98000]
_X509_delete_ext;

// address=[0x1c98030]
_X509_get_ext;

// address=[0x1c98060]
_X509_get_ext_by_NID;

// address=[0x1c98090]
_X509_get_ext_by_OBJ;

// address=[0x1c980c0]
_X509_get_ext_by_critical;

// address=[0x1c980f0]
_X509_get_ext_count;

// address=[0x1c98120]
_X509_get_ext_d2i;

// address=[0x1c98160]
_X509_EXTENSION_create_by_NID;

// address=[0x1c98210]
_X509_EXTENSION_create_by_OBJ;

// address=[0x1c98330]
_X509_EXTENSION_get_critical;

// address=[0x1c98360]
_X509_EXTENSION_get_data;

// address=[0x1c98380]
_X509_EXTENSION_get_object;

// address=[0x1c983a0]
_X509_EXTENSION_set_critical;

// address=[0x1c98400]
_X509_EXTENSION_set_data;

// address=[0x1c98470]
_X509_EXTENSION_set_object;

// address=[0x1c984c0]
_X509v3_add_ext;

// address=[0x1c98640]
_X509v3_delete_ext;

// address=[0x1c986b0]
_X509v3_get_ext;

// address=[0x1c98700]
_X509v3_get_ext_by_NID;

// address=[0x1c98770]
_X509v3_get_ext_by_OBJ;

// address=[0x1c98840]
_X509v3_get_ext_by_critical;

// address=[0x1c98910]
_X509v3_get_ext_count;

// address=[0x1c98940]
_PEM_read_X509;

// address=[0x1c98980]
_PEM_read_bio_X509;

// address=[0x1c989c0]
_PEM_write_X509;

// address=[0x1c98a00]
_PEM_write_bio_X509;

// address=[0x1c99a00]
_BIO_f_ssl;

// address=[0x1c99a10]
_BIO_new_buffer_ssl_connect;

// address=[0x1c99b00]
_BIO_new_ssl;

// address=[0x1c99bd0]
_BIO_new_ssl_connect;

// address=[0x1c99cb0]
_BIO_ssl_copy_session_id;

// address=[0x1c99d50]
_BIO_ssl_shutdown;

// address=[0x1c99dc0]
_SSL_CTX_use_PrivateKey;

// address=[0x1c99e60]
_SSL_CTX_use_PrivateKey_ASN1;

// address=[0x1c99f50]
_SSL_CTX_use_PrivateKey_file;

// address=[0x1c9a120]
_SSL_CTX_use_RSAPrivateKey;

// address=[0x1c9a280]
_SSL_CTX_use_RSAPrivateKey_ASN1;

// address=[0x1c9a370]
_SSL_CTX_use_RSAPrivateKey_file;

// address=[0x1c9a540]
_SSL_CTX_use_certificate;

// address=[0x1c9a5e0]
_SSL_CTX_use_certificate_ASN1;

// address=[0x1c9a690]
_SSL_CTX_use_certificate_chain_file;

// address=[0x1c9a900]
_SSL_CTX_use_certificate_file;

// address=[0x1c9aad0]
_SSL_CTX_use_serverinfo;

// address=[0x1c9ad10]
_SSL_CTX_use_serverinfo_file;

// address=[0x1c9b220]
_SSL_use_PrivateKey;

// address=[0x1c9b2e0]
_SSL_use_PrivateKey_ASN1;

// address=[0x1c9b3d0]
_SSL_use_PrivateKey_file;

// address=[0x1c9b5b0]
_SSL_use_RSAPrivateKey;

// address=[0x1c9b710]
_SSL_use_RSAPrivateKey_ASN1;

// address=[0x1c9b800]
_SSL_use_RSAPrivateKey_file;

// address=[0x1c9b9e0]
_SSL_use_certificate;

// address=[0x1c9ba80]
_SSL_use_certificate_ASN1;

// address=[0x1c9bb30]
_SSL_use_certificate_file;

// address=[0x1c9c700]
_PEM_read_SSL_SESSION;

// address=[0x1c9c740]
_PEM_read_bio_SSL_SESSION;

// address=[0x1c9c780]
_PEM_write_SSL_SESSION;

// address=[0x1c9c7c0]
_PEM_write_bio_SSL_SESSION;

// address=[0x1c9c800]
_SSL_CTX_add_session;

// address=[0x1c9ca00]
_SSL_CTX_flush_sessions;

// address=[0x1c9cb10]
_SSL_CTX_get_client_cert_cb;

// address=[0x1c9cb20]
_SSL_CTX_get_info_callback;

// address=[0x1c9cb40]
_SSL_CTX_get_timeout;

// address=[0x1c9cb60]
_SSL_CTX_remove_session;

// address=[0x1c9cb90]
_SSL_CTX_sess_get_get_cb;

// address=[0x1c9cba0]
_SSL_CTX_sess_get_new_cb;

// address=[0x1c9cbb0]
_SSL_CTX_sess_get_remove_cb;

// address=[0x1c9cbc0]
_SSL_CTX_sess_set_get_cb;

// address=[0x1c9cbe0]
_SSL_CTX_sess_set_new_cb;

// address=[0x1c9cc00]
_SSL_CTX_sess_set_remove_cb;

// address=[0x1c9cc20]
_SSL_CTX_set_client_cert_cb;

// address=[0x1c9cc40]
_SSL_CTX_set_client_cert_engine;

// address=[0x1c9ccf0]
_SSL_CTX_set_cookie_generate_cb;

// address=[0x1c9cd10]
_SSL_CTX_set_cookie_verify_cb;

// address=[0x1c9cd30]
_SSL_CTX_set_info_callback;

// address=[0x1c9cd50]
_SSL_CTX_set_timeout;

// address=[0x1c9cda0]
_SSL_SESSION_free;

// address=[0x1c9d030]
_SSL_SESSION_get0_peer;

// address=[0x1c9d050]
_SSL_SESSION_get_compress_id;

// address=[0x1c9d070]
_SSL_SESSION_get_ex_data;

// address=[0x1c9d0a0]
_SSL_SESSION_get_ex_new_index;

// address=[0x1c9d0e0]
_SSL_SESSION_get_id;

// address=[0x1c9d110]
_SSL_SESSION_get_time;

// address=[0x1c9d130]
_SSL_SESSION_get_timeout;

// address=[0x1c9d380]
_SSL_SESSION_new;

// address=[0x1c9d540]
_SSL_SESSION_set1_id_context;

// address=[0x1c9d5c0]
_SSL_SESSION_set_ex_data;

// address=[0x1c9d5f0]
_SSL_SESSION_set_time;

// address=[0x1c9d620]
_SSL_SESSION_set_timeout;

// address=[0x1c9d650]
_SSL_get1_session;

// address=[0x1c9d6f0]
_SSL_get_session;

// address=[0x1c9d710]
_SSL_set_session;

// address=[0x1c9d930]
_SSL_set_session_secret_cb;

// address=[0x1c9d970]
_SSL_set_session_ticket_ext;

// address=[0x1c9dac0]
_SSL_set_session_ticket_ext_cb;

// address=[0x1c9dd10]
_ssl_clear_bad_session;

// address=[0x1c9dda0]
_ssl_get_new_session;

// address=[0x1c9e3b0]
_ssl_get_prev_session;

// address=[0x1c9eb10]
_ssl_session_dup;

// address=[0x1c9f0e0]
_ssl3_connect;

// address=[0x1ca02b0]
_SSLv3_client_method;

// address=[0x1ca03d0]
_ssl3_check_cert_and_algorithm;

// address=[0x1ca0fc0]
_ssl3_client_hello;

// address=[0x1ca1730]
_ssl3_get_cert_status;

// address=[0x1ca1ad0]
_ssl3_get_certificate_request;

// address=[0x1ca2430]
_ssl3_get_key_exchange;

// address=[0x1ca4bd0]
_ssl3_get_new_session_ticket;

// address=[0x1ca50a0]
_ssl3_get_server_certificate;

// address=[0x1ca59b0]
_ssl3_get_server_done;

// address=[0x1ca5ae0]
_ssl3_get_server_hello;

// address=[0x1ca6690]
_ssl3_send_client_certificate;

// address=[0x1ca6ab0]
_ssl3_send_client_key_exchange;

// address=[0x1ca85e0]
_ssl3_send_client_verify;

// address=[0x1ca8ee0]
_ssl3_send_next_proto;

// address=[0x1ca90b0]
_ssl_do_client_cert_cb;

// address=[0x1ca91a0]
_RAND_add;

// address=[0x1ca9230]
_RAND_bytes;

// address=[0x1ca92b0]
_RAND_cleanup;

// address=[0x1ca9320]
_RAND_get_rand_method;

// address=[0x1ca93d0]
_RAND_pseudo_bytes;

// address=[0x1ca9450]
_RAND_seed;

// address=[0x1ca94c0]
_RAND_set_rand_engine;

// address=[0x1ca9570]
_RAND_set_rand_method;

// address=[0x1ca95c0]
_RAND_status;

// address=[0x1ca9630]
_RAND_file_name;

// address=[0x1ca97c0]
_RAND_load_file;

// address=[0x1ca9aa0]
_RAND_write_file;

// address=[0x1ca9db0]
_OPENSSL_load_builtin_modules;

// address=[0x1ca9de0]
_GENERAL_NAME_it;

// address=[0x1ca9df0]
_OTHERNAME_it;

// address=[0x1ca9e00]
_EDIPARTYNAME_it;

// address=[0x1ca9e10]
_EDIPARTYNAME_free;

// address=[0x1ca9e40]
_EDIPARTYNAME_new;

// address=[0x1ca9e60]
_GENERAL_NAMES_free;

// address=[0x1ca9e90]
_GENERAL_NAMES_it;

// address=[0x1ca9ea0]
_GENERAL_NAMES_new;

// address=[0x1ca9ec0]
_GENERAL_NAME_cmp;

// address=[0x1caa050]
_GENERAL_NAME_dup;

// address=[0x1caa080]
_GENERAL_NAME_free;

// address=[0x1caa0b0]
_GENERAL_NAME_get0_otherName;

// address=[0x1caa100]
_GENERAL_NAME_get0_value;

// address=[0x1caa1c0]
_GENERAL_NAME_new;

// address=[0x1caa1e0]
_GENERAL_NAME_set0_othername;

// address=[0x1caa270]
_GENERAL_NAME_set0_value;

// address=[0x1caa340]
_OTHERNAME_cmp;

// address=[0x1caa3e0]
_OTHERNAME_free;

// address=[0x1caa410]
_OTHERNAME_new;

// address=[0x1caa430]
_d2i_EDIPARTYNAME;

// address=[0x1caa460]
_d2i_GENERAL_NAME;

// address=[0x1caa490]
_d2i_GENERAL_NAMES;

// address=[0x1caa4c0]
_d2i_OTHERNAME;

// address=[0x1caa4f0]
_i2d_EDIPARTYNAME;

// address=[0x1caa520]
_i2d_GENERAL_NAME;

// address=[0x1caa550]
_i2d_GENERAL_NAMES;

// address=[0x1caa580]
_i2d_OTHERNAME;

// address=[0x1caa5b0]
_X509V3_EXT_print;

// address=[0x1caa900]
_X509V3_EXT_print_fp;

// address=[0x1caa990]
_X509V3_EXT_val_prn;

// address=[0x1caab60]
_X509V3_extensions_print;

// address=[0x1cab370]
_X509_PURPOSE_add;

// address=[0x1cab5e0]
_X509_PURPOSE_cleanup;

// address=[0x1cab670]
_X509_PURPOSE_get0;

// address=[0x1cab6c0]
_X509_PURPOSE_get0_name;

// address=[0x1cab6d0]
_X509_PURPOSE_get0_sname;

// address=[0x1cab6e0]
_X509_PURPOSE_get_by_id;

// address=[0x1cab7b0]
_X509_PURPOSE_get_by_sname;

// address=[0x1cab850]
_X509_PURPOSE_get_count;

// address=[0x1cab890]
_X509_PURPOSE_get_id;

// address=[0x1cab8a0]
_X509_PURPOSE_get_trust;

// address=[0x1cab8b0]
_X509_PURPOSE_set;

// address=[0x1cab910]
_X509_check_akid;

// address=[0x1cabaa0]
_X509_check_ca;

// address=[0x1cabb20]
_X509_check_issued;

// address=[0x1cabc40]
_X509_check_purpose;

// address=[0x1cabd40]
_X509_supported_extension;

// address=[0x1cacb60]
_MD5_Final;

// address=[0x1cacfc0]
_MD5_Init;

// address=[0x1cad020]
_MD5_Transform;

// address=[0x1cad050]
_MD5_Update;

// address=[0x1cad280]
_md5_block_data_order;

// address=[0x1caebb0]
_OCSP_check_validity;

// address=[0x1caee40]
_OCSP_request_add0_id;

// address=[0x1caef00]
_OCSP_request_add1_cert;

// address=[0x1caeff0]
_OCSP_request_set1_name;

// address=[0x1caf0b0]
_OCSP_request_sign;

// address=[0x1caf280]
_OCSP_resp_count;

// address=[0x1caf2c0]
_OCSP_resp_find;

// address=[0x1caf3a0]
_OCSP_resp_find_status;

// address=[0x1caf450]
_OCSP_resp_get0;

// address=[0x1caf490]
_OCSP_response_get1_basic;

// address=[0x1caf550]
_OCSP_response_status;

// address=[0x1caf570]
_OCSP_single_get0_status;

// address=[0x1caf670]
_OCSP_RESPDATA_it;

// address=[0x1caf680]
_OCSP_RESPBYTES_it;

// address=[0x1caf690]
_OCSP_ONEREQ_it;

// address=[0x1caf6a0]
_OCSP_CERTID_it;

// address=[0x1caf6b0]
_OCSP_SIGNATURE_it;

// address=[0x1caf6c0]
_OCSP_REQINFO_it;

// address=[0x1caf6d0]
_OCSP_RESPID_it;

// address=[0x1caf6e0]
_OCSP_SINGLERESP_it;

// address=[0x1caf6f0]
_OCSP_CERTSTATUS_it;

// address=[0x1caf700]
_OCSP_REVOKEDINFO_it;

// address=[0x1caf710]
_OCSP_BASICRESP_free;

// address=[0x1caf740]
_OCSP_BASICRESP_it;

// address=[0x1caf750]
_OCSP_BASICRESP_new;

// address=[0x1caf770]
_OCSP_CERTID_free;

// address=[0x1caf7a0]
_OCSP_CERTID_new;

// address=[0x1caf7c0]
_OCSP_CERTSTATUS_free;

// address=[0x1caf7f0]
_OCSP_CERTSTATUS_new;

// address=[0x1caf810]
_OCSP_CRLID_free;

// address=[0x1caf840]
_OCSP_CRLID_it;

// address=[0x1caf850]
_OCSP_CRLID_new;

// address=[0x1caf870]
_OCSP_ONEREQ_free;

// address=[0x1caf8a0]
_OCSP_ONEREQ_new;

// address=[0x1caf8c0]
_OCSP_REQINFO_free;

// address=[0x1caf8f0]
_OCSP_REQINFO_new;

// address=[0x1caf910]
_OCSP_REQUEST_free;

// address=[0x1caf940]
_OCSP_REQUEST_it;

// address=[0x1caf950]
_OCSP_REQUEST_new;

// address=[0x1caf970]
_OCSP_RESPBYTES_free;

// address=[0x1caf9a0]
_OCSP_RESPBYTES_new;

// address=[0x1caf9c0]
_OCSP_RESPDATA_free;

// address=[0x1caf9f0]
_OCSP_RESPDATA_new;

// address=[0x1cafa10]
_OCSP_RESPID_free;

// address=[0x1cafa40]
_OCSP_RESPID_new;

// address=[0x1cafa60]
_OCSP_RESPONSE_free;

// address=[0x1cafa90]
_OCSP_RESPONSE_it;

// address=[0x1cafaa0]
_OCSP_RESPONSE_new;

// address=[0x1cafac0]
_OCSP_REVOKEDINFO_free;

// address=[0x1cafaf0]
_OCSP_REVOKEDINFO_new;

// address=[0x1cafb10]
_OCSP_SERVICELOC_free;

// address=[0x1cafb40]
_OCSP_SERVICELOC_it;

// address=[0x1cafb50]
_OCSP_SERVICELOC_new;

// address=[0x1cafb70]
_OCSP_SIGNATURE_free;

// address=[0x1cafba0]
_OCSP_SIGNATURE_new;

// address=[0x1cafbc0]
_OCSP_SINGLERESP_free;

// address=[0x1cafbf0]
_OCSP_SINGLERESP_new;

// address=[0x1cafc10]
_d2i_OCSP_BASICRESP;

// address=[0x1cafc40]
_d2i_OCSP_CERTID;

// address=[0x1cafc70]
_d2i_OCSP_CERTSTATUS;

// address=[0x1cafca0]
_d2i_OCSP_CRLID;

// address=[0x1cafcd0]
_d2i_OCSP_ONEREQ;

// address=[0x1cafd00]
_d2i_OCSP_REQINFO;

// address=[0x1cafd30]
_d2i_OCSP_REQUEST;

// address=[0x1cafd60]
_d2i_OCSP_RESPBYTES;

// address=[0x1cafd90]
_d2i_OCSP_RESPDATA;

// address=[0x1cafdc0]
_d2i_OCSP_RESPID;

// address=[0x1cafdf0]
_d2i_OCSP_RESPONSE;

// address=[0x1cafe20]
_d2i_OCSP_REVOKEDINFO;

// address=[0x1cafe50]
_d2i_OCSP_SERVICELOC;

// address=[0x1cafe80]
_d2i_OCSP_SIGNATURE;

// address=[0x1cafeb0]
_d2i_OCSP_SINGLERESP;

// address=[0x1cafee0]
_i2d_OCSP_BASICRESP;

// address=[0x1caff10]
_i2d_OCSP_CERTID;

// address=[0x1caff40]
_i2d_OCSP_CERTSTATUS;

// address=[0x1caff70]
_i2d_OCSP_CRLID;

// address=[0x1caffa0]
_i2d_OCSP_ONEREQ;

// address=[0x1caffd0]
_i2d_OCSP_REQINFO;

// address=[0x1cb0000]
_i2d_OCSP_REQUEST;

// address=[0x1cb0030]
_i2d_OCSP_RESPBYTES;

// address=[0x1cb0060]
_i2d_OCSP_RESPDATA;

// address=[0x1cb0090]
_i2d_OCSP_RESPID;

// address=[0x1cb00c0]
_i2d_OCSP_RESPONSE;

// address=[0x1cb00f0]
_i2d_OCSP_REVOKEDINFO;

// address=[0x1cb0120]
_i2d_OCSP_SERVICELOC;

// address=[0x1cb0150]
_i2d_OCSP_SIGNATURE;

// address=[0x1cb0180]
_i2d_OCSP_SINGLERESP;

// address=[0x1cb01b0]
_OCSP_REQUEST_print;

// address=[0x1cb0470]
_OCSP_RESPONSE_print;

// address=[0x1cb0ae0]
_OCSP_cert_status_str;

// address=[0x1cb0b10]
_OCSP_crl_reason_str;

// address=[0x1cb0b40]
_OCSP_response_status_str;

// address=[0x1cb0d20]
_OCSP_basic_verify;

// address=[0x1cb1250]
_OCSP_request_verify;

// address=[0x1cb1e90]
_DES_ecb_encrypt;

// address=[0x1cb21a0]
_DES_options;

// address=[0x1cb2260]
_DES_check_key_parity;

// address=[0x1cb22d0]
_DES_is_weak_key;

// address=[0x1cb2350]
_DES_key_sched;

// address=[0x1cb2380]
_DES_set_key;

// address=[0x1cb23d0]
_DES_set_key_checked;

// address=[0x1cb2430]
_DES_set_key_unchecked;

// address=[0x1cb2950]
_DES_set_odd_parity;

// address=[0x1cb29b0]
__shadow_DES_check_key;

// address=[0x1cb29c0]
_MD4_Final;

// address=[0x1cb2e20]
_MD4_Init;

// address=[0x1cb2e80]
_MD4_Transform;

// address=[0x1cb2eb0]
_MD4_Update;

// address=[0x1cb30e0]
_md4_block_data_order;

// address=[0x1cb4a40]
_lh_delete;

// address=[0x1cb4ba0]
_lh_doall;

// address=[0x1cb4bd0]
_lh_doall_arg;

// address=[0x1cb4c00]
_lh_free;

// address=[0x1cb4cd0]
_lh_insert;

// address=[0x1cb4e80]
_lh_new;

// address=[0x1cb50c0]
_lh_num_items;

// address=[0x1cb5100]
_lh_retrieve;

// address=[0x1cb51f0]
_lh_strhash;

// address=[0x1cb52e0]
_OPENSSL_init;

// address=[0x1cb5300]
_BUF_memdup;

// address=[0x1cb53a0]
_BUF_strdup;

// address=[0x1cb53e0]
_BUF_strlcat;

// address=[0x1cb5470]
_BUF_strlcpy;

// address=[0x1cb5520]
_BUF_strndup;

// address=[0x1cb55f0]
_BUF_strnlen;

// address=[0x1cb5690]
_OPENSSL_cleanse;

// address=[0x1cb56d0]
_OBJ_NAME_add;

// address=[0x1cb5870]
_OBJ_NAME_cleanup;

// address=[0x1cb5950]
_OBJ_NAME_do_all;

// address=[0x1cb5a00]
_OBJ_NAME_do_all_sorted;

// address=[0x1cb5b50]
_OBJ_NAME_get;

// address=[0x1cb5ca0]
_OBJ_NAME_init;

// address=[0x1cb5d40]
_OBJ_NAME_new_index;

// address=[0x1cb5f30]
_OBJ_NAME_remove;

// address=[0x1cb6550]
_OBJ_add_object;

// address=[0x1cb6870]
_OBJ_bsearch_;

// address=[0x1cb68b0]
_OBJ_bsearch_ex_;

// address=[0x1cb6ad0]
_OBJ_cleanup;

// address=[0x1cb6b80]
_OBJ_create;

// address=[0x1cb6ce0]
_OBJ_create_objects;

// address=[0x1cb70a0]
_OBJ_ln2nid;

// address=[0x1cb71d0]
_OBJ_new_nid;

// address=[0x1cb7210]
_OBJ_nid2ln;

// address=[0x1cb7370]
_OBJ_nid2obj;

// address=[0x1cb74d0]
_OBJ_nid2sn;

// address=[0x1cb7630]
_OBJ_obj2nid;

// address=[0x1cb7760]
_OBJ_obj2txt;

// address=[0x1cb7cc0]
_OBJ_sn2nid;

// address=[0x1cb7df0]
_OBJ_txt2nid;

// address=[0x1cb7e60]
_OBJ_txt2obj;

// address=[0x1cb83c0]
_check_defer;

// address=[0x1cb8880]
_OBJ_add_sigid;

// address=[0x1cb8a40]
_OBJ_find_sigid_algs;

// address=[0x1cb8b90]
_OBJ_find_sigid_by_algs;

// address=[0x1cb8cf0]
_OBJ_sigid_free;

// address=[0x1cb8ee0]
_EVP_PBE_CipherInit;

// address=[0x1cb91d0]
_EVP_PBE_alg_add;

// address=[0x1cb9270]
_EVP_PBE_alg_add_type;

// address=[0x1cb9370]
_EVP_PBE_cleanup;

// address=[0x1cb93b0]
_EVP_PBE_find;

// address=[0x1cb9680]
_ASN1_UTCTIME_adj;

// address=[0x1cb9900]
_ASN1_UTCTIME_check;

// address=[0x1cb9920]
_ASN1_UTCTIME_cmp_time_t;

// address=[0x1cb9a90]
_ASN1_UTCTIME_set;

// address=[0x1cb9ac0]
_ASN1_UTCTIME_set_string;

// address=[0x1cb9bb0]
_asn1_utctime_to_tm;

// address=[0x1cba060]
_ASN1_GENERALIZEDTIME_adj;

// address=[0x1cba290]
_ASN1_GENERALIZEDTIME_check;

// address=[0x1cba2b0]
_ASN1_GENERALIZEDTIME_set;

// address=[0x1cba2e0]
_ASN1_GENERALIZEDTIME_set_string;

// address=[0x1cba3d0]
_asn1_generalizedtime_to_tm;

// address=[0x1cba910]
_ASN1_TIME_adj;

// address=[0x1cbaa70]
_ASN1_TIME_check;

// address=[0x1cbaac0]
_ASN1_TIME_diff;

// address=[0x1cbabc0]
_ASN1_TIME_free;

// address=[0x1cbabf0]
_ASN1_TIME_it;

// address=[0x1cbac00]
_ASN1_TIME_new;

// address=[0x1cbac20]
_ASN1_TIME_set;

// address=[0x1cbac50]
_ASN1_TIME_set_string;

// address=[0x1cbad50]
_ASN1_TIME_to_generalizedtime;

// address=[0x1cbb020]
_d2i_ASN1_TIME;

// address=[0x1cbb050]
_i2d_ASN1_TIME;

// address=[0x1cbb080]
_ASN1_OCTET_STRING_cmp;

// address=[0x1cbb0b0]
_ASN1_OCTET_STRING_dup;

// address=[0x1cbb0d0]
_ASN1_OCTET_STRING_set;

// address=[0x1cbb130]
_X509_VERIFY_PARAM_add0_policy;

// address=[0x1cbb190]
_X509_VERIFY_PARAM_add0_table;

// address=[0x1cbb290]
_X509_VERIFY_PARAM_add1_host;

// address=[0x1cbb2c0]
_X509_VERIFY_PARAM_clear_flags;

// address=[0x1cbb2f0]
_X509_VERIFY_PARAM_free;

// address=[0x1cbb340]
_X509_VERIFY_PARAM_get0;

// address=[0x1cbb3b0]
_X509_VERIFY_PARAM_get0_name;

// address=[0x1cbb3c0]
_X509_VERIFY_PARAM_get0_peername;

// address=[0x1cbb3e0]
_X509_VERIFY_PARAM_get_count;

// address=[0x1cbb440]
_X509_VERIFY_PARAM_get_depth;

// address=[0x1cbb450]
_X509_VERIFY_PARAM_get_flags;

// address=[0x1cbb460]
_X509_VERIFY_PARAM_inherit;

// address=[0x1cbb800]
_X509_VERIFY_PARAM_lookup;

// address=[0x1cbb8d0]
_X509_VERIFY_PARAM_new;

// address=[0x1cbb9e0]
_X509_VERIFY_PARAM_set1;

// address=[0x1cbba60]
_X509_VERIFY_PARAM_set1_email;

// address=[0x1cbbaa0]
_X509_VERIFY_PARAM_set1_host;

// address=[0x1cbbad0]
_X509_VERIFY_PARAM_set1_ip;

// address=[0x1cbbb30]
_X509_VERIFY_PARAM_set1_ip_asc;

// address=[0x1cbbc10]
_X509_VERIFY_PARAM_set1_name;

// address=[0x1cbbc70]
_X509_VERIFY_PARAM_set1_policies;

// address=[0x1cbbde0]
_X509_VERIFY_PARAM_set_depth;

// address=[0x1cbbe00]
_X509_VERIFY_PARAM_set_flags;

// address=[0x1cbbe50]
_X509_VERIFY_PARAM_set_hostflags;

// address=[0x1cbbe70]
_X509_VERIFY_PARAM_set_purpose;

// address=[0x1cbbea0]
_X509_VERIFY_PARAM_set_time;

// address=[0x1cbbed0]
_X509_VERIFY_PARAM_set_trust;

// address=[0x1cbbf00]
_X509_VERIFY_PARAM_table_cleanup;

// address=[0x1cbc4c0]
_X509_policy_check;

// address=[0x1cbc770]
_X509_policy_tree_free;

// address=[0x1cbdae0]
_NETSCAPE_SPKI_sign;

// address=[0x1cbdb30]
_NETSCAPE_SPKI_verify;

// address=[0x1cbdb70]
_PKCS7_ISSUER_AND_SERIAL_digest;

// address=[0x1cbdbb0]
_X509_CRL_digest;

// address=[0x1cbdbf0]
_X509_CRL_http_nbio;

// address=[0x1cbdc20]
_X509_CRL_sign;

// address=[0x1cbdc80]
_X509_CRL_sign_ctx;

// address=[0x1cbdce0]
_X509_NAME_digest;

// address=[0x1cbdd20]
_X509_REQ_digest;

// address=[0x1cbdd60]
_X509_REQ_sign;

// address=[0x1cbddb0]
_X509_REQ_sign_ctx;

// address=[0x1cbde00]
_X509_REQ_verify;

// address=[0x1cbde40]
_X509_digest;

// address=[0x1cbde80]
_X509_http_nbio;

// address=[0x1cbdeb0]
_X509_pubkey_digest;

// address=[0x1cbdf30]
_X509_sign;

// address=[0x1cbdf90]
_X509_sign_ctx;

// address=[0x1cbdff0]
_X509_verify;

// address=[0x1cbe060]
_d2i_DSAPrivateKey_bio;

// address=[0x1cbe090]
_d2i_DSAPrivateKey_fp;

// address=[0x1cbe0c0]
_d2i_DSA_PUBKEY_bio;

// address=[0x1cbe0f0]
_d2i_DSA_PUBKEY_fp;

// address=[0x1cbe120]
_d2i_ECPrivateKey_bio;

// address=[0x1cbe150]
_d2i_ECPrivateKey_fp;

// address=[0x1cbe180]
_d2i_EC_PUBKEY_bio;

// address=[0x1cbe1b0]
_d2i_EC_PUBKEY_fp;

// address=[0x1cbe1e0]
_d2i_PKCS7_bio;

// address=[0x1cbe210]
_d2i_PKCS7_fp;

// address=[0x1cbe240]
_d2i_PKCS8_PRIV_KEY_INFO_bio;

// address=[0x1cbe270]
_d2i_PKCS8_PRIV_KEY_INFO_fp;

// address=[0x1cbe2a0]
_d2i_PKCS8_bio;

// address=[0x1cbe2d0]
_d2i_PKCS8_fp;

// address=[0x1cbe300]
_d2i_PUBKEY_bio;

// address=[0x1cbe330]
_d2i_PUBKEY_fp;

// address=[0x1cbe360]
_d2i_PrivateKey_bio;

// address=[0x1cbe390]
_d2i_PrivateKey_fp;

// address=[0x1cbe3c0]
_d2i_RSAPrivateKey_bio;

// address=[0x1cbe3f0]
_d2i_RSAPrivateKey_fp;

// address=[0x1cbe420]
_d2i_RSAPublicKey_bio;

// address=[0x1cbe450]
_d2i_RSAPublicKey_fp;

// address=[0x1cbe480]
_d2i_RSA_PUBKEY_bio;

// address=[0x1cbe4b0]
_d2i_RSA_PUBKEY_fp;

// address=[0x1cbe4e0]
_d2i_X509_CRL_bio;

// address=[0x1cbe510]
_d2i_X509_CRL_fp;

// address=[0x1cbe540]
_d2i_X509_REQ_bio;

// address=[0x1cbe570]
_d2i_X509_REQ_fp;

// address=[0x1cbe5a0]
_d2i_X509_bio;

// address=[0x1cbe5d0]
_d2i_X509_fp;

// address=[0x1cbe600]
_i2d_DSAPrivateKey_bio;

// address=[0x1cbe630]
_i2d_DSAPrivateKey_fp;

// address=[0x1cbe660]
_i2d_DSA_PUBKEY_bio;

// address=[0x1cbe690]
_i2d_DSA_PUBKEY_fp;

// address=[0x1cbe6c0]
_i2d_ECPrivateKey_bio;

// address=[0x1cbe6f0]
_i2d_ECPrivateKey_fp;

// address=[0x1cbe720]
_i2d_EC_PUBKEY_bio;

// address=[0x1cbe750]
_i2d_EC_PUBKEY_fp;

// address=[0x1cbe780]
_i2d_PKCS7_bio;

// address=[0x1cbe7b0]
_i2d_PKCS7_fp;

// address=[0x1cbe7e0]
_i2d_PKCS8PrivateKeyInfo_bio;

// address=[0x1cbe860]
_i2d_PKCS8PrivateKeyInfo_fp;

// address=[0x1cbe8e0]
_i2d_PKCS8_PRIV_KEY_INFO_bio;

// address=[0x1cbe910]
_i2d_PKCS8_PRIV_KEY_INFO_fp;

// address=[0x1cbe940]
_i2d_PKCS8_bio;

// address=[0x1cbe970]
_i2d_PKCS8_fp;

// address=[0x1cbe9a0]
_i2d_PUBKEY_bio;

// address=[0x1cbe9d0]
_i2d_PUBKEY_fp;

// address=[0x1cbea00]
_i2d_PrivateKey_bio;

// address=[0x1cbea30]
_i2d_PrivateKey_fp;

// address=[0x1cbea60]
_i2d_RSAPrivateKey_bio;

// address=[0x1cbea90]
_i2d_RSAPrivateKey_fp;

// address=[0x1cbeac0]
_i2d_RSAPublicKey_bio;

// address=[0x1cbeaf0]
_i2d_RSAPublicKey_fp;

// address=[0x1cbeb20]
_i2d_RSA_PUBKEY_bio;

// address=[0x1cbeb50]
_i2d_RSA_PUBKEY_fp;

// address=[0x1cbeb80]
_i2d_X509_CRL_bio;

// address=[0x1cbebb0]
_i2d_X509_CRL_fp;

// address=[0x1cbebe0]
_i2d_X509_REQ_bio;

// address=[0x1cbec10]
_i2d_X509_REQ_fp;

// address=[0x1cbec40]
_i2d_X509_bio;

// address=[0x1cbec70]
_i2d_X509_fp;

// address=[0x1cbeca0]
_X509_REVOKED_it;

// address=[0x1cbecb0]
_X509_CRL_INFO_it;

// address=[0x1cbf340]
_X509_CRL_INFO_free;

// address=[0x1cbf370]
_X509_CRL_INFO_new;

// address=[0x1cbf390]
_X509_CRL_METHOD_free;

// address=[0x1cbf3c0]
_X509_CRL_METHOD_new;

// address=[0x1cbf450]
_X509_CRL_add0_revoked;

// address=[0x1cbf510]
_X509_CRL_dup;

// address=[0x1cbf540]
_X509_CRL_free;

// address=[0x1cbf570]
_X509_CRL_get0_by_cert;

// address=[0x1cbf5e0]
_X509_CRL_get0_by_serial;

// address=[0x1cbf640]
_X509_CRL_get_meth_data;

// address=[0x1cbf650]
_X509_CRL_it;

// address=[0x1cbf660]
_X509_CRL_new;

// address=[0x1cbf680]
_X509_CRL_set_default_method;

// address=[0x1cbf6b0]
_X509_CRL_set_meth_data;

// address=[0x1cbf6d0]
_X509_CRL_verify;

// address=[0x1cbf750]
_X509_REVOKED_dup;

// address=[0x1cbf780]
_X509_REVOKED_free;

// address=[0x1cbf7b0]
_X509_REVOKED_new;

// address=[0x1cbfbb0]
_d2i_X509_CRL;

// address=[0x1cbfbe0]
_d2i_X509_CRL_INFO;

// address=[0x1cbfc10]
_d2i_X509_REVOKED;

// address=[0x1cbfc40]
_i2d_X509_CRL;

// address=[0x1cbfc70]
_i2d_X509_CRL_INFO;

// address=[0x1cbfca0]
_i2d_X509_REVOKED;

// address=[0x1cc04d0]
_X509_NAME_ENTRIES_it;

// address=[0x1cc04e0]
_X509_NAME_ENTRY_it;

// address=[0x1cc04f0]
_X509_NAME_ENTRY_dup;

// address=[0x1cc0520]
_X509_NAME_ENTRY_free;

// address=[0x1cc0550]
_X509_NAME_ENTRY_new;

// address=[0x1cc0570]
_X509_NAME_INTERNAL_it;

// address=[0x1cc0580]
_X509_NAME_dup;

// address=[0x1cc05b0]
_X509_NAME_free;

// address=[0x1cc05e0]
_X509_NAME_it;

// address=[0x1cc05f0]
_X509_NAME_new;

// address=[0x1cc0610]
_X509_NAME_set;

// address=[0x1cc0910]
_d2i_X509_NAME;

// address=[0x1cc0940]
_d2i_X509_NAME_ENTRY;

// address=[0x1cc0970]
_i2d_X509_NAME;

// address=[0x1cc09a0]
_i2d_X509_NAME_ENTRY;

// address=[0x1cc1060]
_X509_CRL_set_issuer_name;

// address=[0x1cc10a0]
_X509_CRL_set_lastUpdate;

// address=[0x1cc1160]
_X509_CRL_set_nextUpdate;

// address=[0x1cc1220]
_X509_CRL_set_version;

// address=[0x1cc12b0]
_X509_CRL_sort;

// address=[0x1cc1370]
_X509_REVOKED_set_revocationDate;

// address=[0x1cc1420]
_X509_REVOKED_set_serialNumber;

// address=[0x1cc1720]
_X509_TRUST_add;

// address=[0x1cc1970]
_X509_TRUST_cleanup;

// address=[0x1cc1a00]
_X509_TRUST_get0;

// address=[0x1cc1a50]
_X509_TRUST_get0_name;

// address=[0x1cc1a60]
_X509_TRUST_get_by_id;

// address=[0x1cc1b50]
_X509_TRUST_get_count;

// address=[0x1cc1b90]
_X509_TRUST_get_flags;

// address=[0x1cc1ba0]
_X509_TRUST_get_trust;

// address=[0x1cc1bb0]
_X509_TRUST_set;

// address=[0x1cc1c10]
_X509_TRUST_set_default;

// address=[0x1cc1c50]
_X509_check_trust;

// address=[0x1cc1df0]
_GENERAL_SUBTREE_it;

// address=[0x1cc1e00]
_NAME_CONSTRAINTS_it;

// address=[0x1cc2150]
_GENERAL_SUBTREE_free;

// address=[0x1cc2180]
_GENERAL_SUBTREE_new;

// address=[0x1cc21a0]
_NAME_CONSTRAINTS_check;

// address=[0x1cc23a0]
_NAME_CONSTRAINTS_free;

// address=[0x1cc23d0]
_NAME_CONSTRAINTS_new;

// address=[0x1cc3040]
_X509V3_NAME_from_section;

// address=[0x1cc31c0]
_X509V3_add_value;

// address=[0x1cc3360]
_X509V3_add_value_bool;

// address=[0x1cc33b0]
_X509V3_add_value_bool_nf;

// address=[0x1cc33f0]
_X509V3_add_value_int;

// address=[0x1cc3490]
_X509V3_add_value_uchar;

// address=[0x1cc34c0]
_X509V3_conf_free;

// address=[0x1cc3540]
_X509V3_get_value_bool;

// address=[0x1cc3750]
_X509V3_get_value_int;

// address=[0x1cc37f0]
_X509V3_parse_list;

// address=[0x1cc3b90]
_X509_REQ_get1_email;

// address=[0x1cc3c50]
_X509_check_email;

// address=[0x1cc3d40]
_X509_check_host;

// address=[0x1cc3e30]
_X509_check_ip;

// address=[0x1cc3e80]
_X509_check_ip_asc;

// address=[0x1cc3f80]
_X509_email_free;

// address=[0x1cc3fb0]
_X509_get1_email;

// address=[0x1cc4040]
_X509_get1_ocsp;

// address=[0x1cc4190]
_a2i_IPADDRESS;

// address=[0x1cc42a0]
_a2i_IPADDRESS_NC;

// address=[0x1cc4480]
_a2i_ipadd;

// address=[0x1cc5060]
_hex_to_string;

// address=[0x1cc51c0]
_i2s_ASN1_ENUMERATED;

// address=[0x1cc5280]
_i2s_ASN1_INTEGER;

// address=[0x1cc5970]
_name_cmp;

// address=[0x1cc5a20]
_s2i_ASN1_INTEGER;

// address=[0x1cc5da0]
_string_to_hex;

// address=[0x1cc6650]
_ASN1_ANY_it;

// address=[0x1cc6660]
_ASN1_BIT_STRING_free;

// address=[0x1cc6690]
_ASN1_BIT_STRING_it;

// address=[0x1cc66a0]
_ASN1_BIT_STRING_new;

// address=[0x1cc66c0]
_ASN1_BMPSTRING_free;

// address=[0x1cc66f0]
_ASN1_BMPSTRING_it;

// address=[0x1cc6700]
_ASN1_BMPSTRING_new;

// address=[0x1cc6720]
_ASN1_BOOLEAN_it;

// address=[0x1cc6730]
_ASN1_ENUMERATED_free;

// address=[0x1cc6760]
_ASN1_ENUMERATED_it;

// address=[0x1cc6770]
_ASN1_ENUMERATED_new;

// address=[0x1cc6790]
_ASN1_FBOOLEAN_it;

// address=[0x1cc67a0]
_ASN1_GENERALIZEDTIME_free;

// address=[0x1cc67d0]
_ASN1_GENERALIZEDTIME_it;

// address=[0x1cc67e0]
_ASN1_GENERALIZEDTIME_new;

// address=[0x1cc6800]
_ASN1_GENERALSTRING_free;

// address=[0x1cc6830]
_ASN1_GENERALSTRING_it;

// address=[0x1cc6840]
_ASN1_GENERALSTRING_new;

// address=[0x1cc6860]
_ASN1_IA5STRING_free;

// address=[0x1cc6890]
_ASN1_IA5STRING_it;

// address=[0x1cc68a0]
_ASN1_IA5STRING_new;

// address=[0x1cc68c0]
_ASN1_INTEGER_free;

// address=[0x1cc68f0]
_ASN1_INTEGER_it;

// address=[0x1cc6900]
_ASN1_INTEGER_new;

// address=[0x1cc6920]
_ASN1_NULL_free;

// address=[0x1cc6950]
_ASN1_NULL_it;

// address=[0x1cc6960]
_ASN1_NULL_new;

// address=[0x1cc6980]
_ASN1_OBJECT_it;

// address=[0x1cc6990]
_ASN1_OCTET_STRING_NDEF_it;

// address=[0x1cc69a0]
_ASN1_OCTET_STRING_free;

// address=[0x1cc69d0]
_ASN1_OCTET_STRING_it;

// address=[0x1cc69e0]
_ASN1_OCTET_STRING_new;

// address=[0x1cc6a00]
_ASN1_PRINTABLESTRING_free;

// address=[0x1cc6a30]
_ASN1_PRINTABLESTRING_it;

// address=[0x1cc6a40]
_ASN1_PRINTABLESTRING_new;

// address=[0x1cc6a60]
_ASN1_PRINTABLE_free;

// address=[0x1cc6a90]
_ASN1_PRINTABLE_it;

// address=[0x1cc6aa0]
_ASN1_PRINTABLE_new;

// address=[0x1cc6ac0]
_ASN1_SEQUENCE_ANY_it;

// address=[0x1cc6ad0]
_ASN1_SEQUENCE_it;

// address=[0x1cc6ae0]
_ASN1_SET_ANY_it;

// address=[0x1cc6af0]
_ASN1_T61STRING_free;

// address=[0x1cc6b20]
_ASN1_T61STRING_it;

// address=[0x1cc6b30]
_ASN1_T61STRING_new;

// address=[0x1cc6b50]
_ASN1_TBOOLEAN_it;

// address=[0x1cc6b60]
_ASN1_TYPE_free;

// address=[0x1cc6b90]
_ASN1_TYPE_new;

// address=[0x1cc6bb0]
_ASN1_UNIVERSALSTRING_free;

// address=[0x1cc6be0]
_ASN1_UNIVERSALSTRING_it;

// address=[0x1cc6bf0]
_ASN1_UNIVERSALSTRING_new;

// address=[0x1cc6c10]
_ASN1_UTCTIME_free;

// address=[0x1cc6c40]
_ASN1_UTCTIME_it;

// address=[0x1cc6c50]
_ASN1_UTCTIME_new;

// address=[0x1cc6c70]
_ASN1_UTF8STRING_free;

// address=[0x1cc6ca0]
_ASN1_UTF8STRING_it;

// address=[0x1cc6cb0]
_ASN1_UTF8STRING_new;

// address=[0x1cc6cd0]
_ASN1_VISIBLESTRING_free;

// address=[0x1cc6d00]
_ASN1_VISIBLESTRING_it;

// address=[0x1cc6d10]
_ASN1_VISIBLESTRING_new;

// address=[0x1cc6d30]
_DIRECTORYSTRING_free;

// address=[0x1cc6d60]
_DIRECTORYSTRING_it;

// address=[0x1cc6d70]
_DIRECTORYSTRING_new;

// address=[0x1cc6d90]
_DISPLAYTEXT_free;

// address=[0x1cc6dc0]
_DISPLAYTEXT_it;

// address=[0x1cc6dd0]
_DISPLAYTEXT_new;

// address=[0x1cc6df0]
_d2i_ASN1_BIT_STRING;

// address=[0x1cc6e20]
_d2i_ASN1_BMPSTRING;

// address=[0x1cc6e50]
_d2i_ASN1_ENUMERATED;

// address=[0x1cc6e80]
_d2i_ASN1_GENERALIZEDTIME;

// address=[0x1cc6eb0]
_d2i_ASN1_GENERALSTRING;

// address=[0x1cc6ee0]
_d2i_ASN1_IA5STRING;

// address=[0x1cc6f10]
_d2i_ASN1_INTEGER;

// address=[0x1cc6f40]
_d2i_ASN1_NULL;

// address=[0x1cc6f70]
_d2i_ASN1_OCTET_STRING;

// address=[0x1cc6fa0]
_d2i_ASN1_PRINTABLE;

// address=[0x1cc6fd0]
_d2i_ASN1_PRINTABLESTRING;

// address=[0x1cc7000]
_d2i_ASN1_SEQUENCE_ANY;

// address=[0x1cc7030]
_d2i_ASN1_SET_ANY;

// address=[0x1cc7060]
_d2i_ASN1_T61STRING;

// address=[0x1cc7090]
_d2i_ASN1_TYPE;

// address=[0x1cc70c0]
_d2i_ASN1_UNIVERSALSTRING;

// address=[0x1cc70f0]
_d2i_ASN1_UTCTIME;

// address=[0x1cc7120]
_d2i_ASN1_UTF8STRING;

// address=[0x1cc7150]
_d2i_ASN1_VISIBLESTRING;

// address=[0x1cc7180]
_d2i_DIRECTORYSTRING;

// address=[0x1cc71b0]
_d2i_DISPLAYTEXT;

// address=[0x1cc71e0]
_i2d_ASN1_BIT_STRING;

// address=[0x1cc7210]
_i2d_ASN1_BMPSTRING;

// address=[0x1cc7240]
_i2d_ASN1_ENUMERATED;

// address=[0x1cc7270]
_i2d_ASN1_GENERALIZEDTIME;

// address=[0x1cc72a0]
_i2d_ASN1_GENERALSTRING;

// address=[0x1cc72d0]
_i2d_ASN1_IA5STRING;

// address=[0x1cc7300]
_i2d_ASN1_INTEGER;

// address=[0x1cc7330]
_i2d_ASN1_NULL;

// address=[0x1cc7360]
_i2d_ASN1_OCTET_STRING;

// address=[0x1cc7390]
_i2d_ASN1_PRINTABLE;

// address=[0x1cc73c0]
_i2d_ASN1_PRINTABLESTRING;

// address=[0x1cc73f0]
_i2d_ASN1_SEQUENCE_ANY;

// address=[0x1cc7420]
_i2d_ASN1_SET_ANY;

// address=[0x1cc7450]
_i2d_ASN1_T61STRING;

// address=[0x1cc7480]
_i2d_ASN1_TYPE;

// address=[0x1cc74b0]
_i2d_ASN1_UNIVERSALSTRING;

// address=[0x1cc74e0]
_i2d_ASN1_UTCTIME;

// address=[0x1cc7510]
_i2d_ASN1_UTF8STRING;

// address=[0x1cc7540]
_i2d_ASN1_VISIBLESTRING;

// address=[0x1cc7570]
_i2d_DIRECTORYSTRING;

// address=[0x1cc75a0]
_i2d_DISPLAYTEXT;

// address=[0x1cc75d0]
_X509_ALGOR_it;

// address=[0x1cc75e0]
_X509_ALGORS_it;

// address=[0x1cc75f0]
_X509_ALGOR_cmp;

// address=[0x1cc7680]
_X509_ALGOR_dup;

// address=[0x1cc76b0]
_X509_ALGOR_free;

// address=[0x1cc76e0]
_X509_ALGOR_get0;

// address=[0x1cc7750]
_X509_ALGOR_new;

// address=[0x1cc7770]
_X509_ALGOR_set0;

// address=[0x1cc7860]
_X509_ALGOR_set_md;

// address=[0x1cc78e0]
_d2i_X509_ALGOR;

// address=[0x1cc7910]
_d2i_X509_ALGORS;

// address=[0x1cc7940]
_i2d_X509_ALGOR;

// address=[0x1cc7970]
_i2d_X509_ALGORS;

// address=[0x1cc79a0]
_ASN1_item_ex_new;

// address=[0x1cc79d0]
_ASN1_item_new;

// address=[0x1cc7a70]
_ASN1_primitive_new;

// address=[0x1cc7c80]
_ASN1_template_new;

// address=[0x1cc8520]
_ASN1_item_ex_free;

// address=[0x1cc8550]
_ASN1_item_free;

// address=[0x1cc8580]
_ASN1_primitive_free;

// address=[0x1cc8770]
_ASN1_template_free;

// address=[0x1cc88c0]
_asn1_item_combine_free;

// address=[0x1cc8ce0]
_ASN1_item_d2i;

// address=[0x1cc8de0]
_ASN1_item_ex_d2i;

// address=[0x1cc9c70]
_ASN1_tag2bit;

// address=[0x1cc9ca0]
_ASN1_template_d2i;

// address=[0x1cca930]
_asn1_ex_c2i;

// address=[0x1ccb8f0]
_ASN1_item_ex_i2d;

// address=[0x1ccbf30]
_ASN1_item_i2d;

// address=[0x1ccbf60]
_ASN1_item_ndef_i2d;

// address=[0x1ccbf90]
_ASN1_template_i2d;

// address=[0x1ccbfc0]
_asn1_ex_i2c;

// address=[0x1cccf60]
_EC_KEY_check_key;

// address=[0x1ccd2f0]
_EC_KEY_clear_flags;

// address=[0x1ccd310]
_EC_KEY_copy;

// address=[0x1ccd5f0]
_EC_KEY_dup;

// address=[0x1ccd670]
_EC_KEY_free;

// address=[0x1ccd770]
_EC_KEY_generate_key;

// address=[0x1ccd9c0]
_EC_KEY_get0_group;

// address=[0x1ccd9d0]
_EC_KEY_get0_private_key;

// address=[0x1ccd9e0]
_EC_KEY_get0_public_key;

// address=[0x1ccd9f0]
_EC_KEY_get_conv_form;

// address=[0x1ccda00]
_EC_KEY_get_enc_flags;

// address=[0x1ccda10]
_EC_KEY_get_flags;

// address=[0x1ccda20]
_EC_KEY_get_key_method_data;

// address=[0x1ccdab0]
_EC_KEY_insert_key_method_data;

// address=[0x1ccdb70]
_EC_KEY_new;

// address=[0x1ccdc60]
_EC_KEY_new_by_curve_name;

// address=[0x1ccdce0]
_EC_KEY_precompute_mult;

// address=[0x1ccdd20]
_EC_KEY_set_asn1_flag;

// address=[0x1ccdd60]
_EC_KEY_set_conv_form;

// address=[0x1ccdda0]
_EC_KEY_set_enc_flags;

// address=[0x1ccddc0]
_EC_KEY_set_flags;

// address=[0x1ccdde0]
_EC_KEY_set_group;

// address=[0x1ccde70]
_EC_KEY_set_private_key;

// address=[0x1ccdf00]
_EC_KEY_set_public_key;

// address=[0x1ccdf90]
_EC_KEY_set_public_key_affine_coordinates;

// address=[0x1cce290]
_EC_KEY_up_ref;

// address=[0x1cce310]
_RSA_free;

// address=[0x1cce550]
_RSA_get_default_method;

// address=[0x1cce580]
_RSA_get_ex_data;

// address=[0x1cce5b0]
_RSA_get_ex_new_index;

// address=[0x1cce5f0]
_RSA_get_method;

// address=[0x1cce600]
_RSA_memory_lock;

// address=[0x1cce8e0]
_RSA_new;

// address=[0x1cce920]
_RSA_new_method;

// address=[0x1ccec70]
_RSA_set_default_method;

// address=[0x1ccec80]
_RSA_set_ex_data;

// address=[0x1ccecb0]
_RSA_set_method;

// address=[0x1cced80]
_RSA_up_ref;

// address=[0x1ccee00]
_DSA_dup_DH;

// address=[0x1ccefc0]
_DSA_free;

// address=[0x1ccf180]
_DSA_get_default_method;

// address=[0x1ccf1b0]
_DSA_get_ex_data;

// address=[0x1ccf1e0]
_DSA_get_ex_new_index;

// address=[0x1ccf220]
_DSA_new;

// address=[0x1ccf240]
_DSA_new_method;

// address=[0x1ccf500]
_DSA_set_default_method;

// address=[0x1ccf510]
_DSA_set_ex_data;

// address=[0x1ccf540]
_DSA_set_method;

// address=[0x1ccf610]
_DSA_size;

// address=[0x1ccf720]
_DSA_up_ref;

// address=[0x1ccf7a0]
_EVP_Digest;

// address=[0x1ccf8c0]
_EVP_DigestFinal;

// address=[0x1ccf920]
_EVP_DigestFinal_ex;

// address=[0x1ccfa40]
_EVP_DigestInit;

// address=[0x1ccfa80]
_EVP_DigestInit_ex;

// address=[0x1ccfdc0]
_EVP_DigestUpdate;

// address=[0x1ccfe00]
_EVP_MD_CTX_cleanup;

// address=[0x1ccff20]
_EVP_MD_CTX_copy;

// address=[0x1ccff60]
_EVP_MD_CTX_copy_ex;

// address=[0x1cd01b0]
_EVP_MD_CTX_create;

// address=[0x1cd0220]
_EVP_MD_CTX_destroy;

// address=[0x1cd0260]
_EVP_MD_CTX_init;

// address=[0x1cd0290]
_EVP_CIPHER_CTX_block_size;

// address=[0x1cd02a0]
_EVP_CIPHER_CTX_cipher;

// address=[0x1cd02b0]
_EVP_CIPHER_CTX_clear_flags;

// address=[0x1cd02d0]
_EVP_CIPHER_CTX_flags;

// address=[0x1cd02e0]
_EVP_CIPHER_CTX_get_app_data;

// address=[0x1cd02f0]
_EVP_CIPHER_CTX_iv_length;

// address=[0x1cd0300]
_EVP_CIPHER_CTX_key_length;

// address=[0x1cd0310]
_EVP_CIPHER_CTX_nid;

// address=[0x1cd0320]
_EVP_CIPHER_CTX_set_app_data;

// address=[0x1cd0340]
_EVP_CIPHER_CTX_set_flags;

// address=[0x1cd0360]
_EVP_CIPHER_CTX_test_flags;

// address=[0x1cd0380]
_EVP_CIPHER_asn1_to_param;

// address=[0x1cd0490]
_EVP_CIPHER_block_size;

// address=[0x1cd04a0]
_EVP_CIPHER_flags;

// address=[0x1cd04b0]
_EVP_CIPHER_get_asn1_iv;

// address=[0x1cd05b0]
_EVP_CIPHER_iv_length;

// address=[0x1cd05c0]
_EVP_CIPHER_key_length;

// address=[0x1cd05d0]
_EVP_CIPHER_nid;

// address=[0x1cd05e0]
_EVP_CIPHER_param_to_asn1;

// address=[0x1cd0730]
_EVP_CIPHER_set_asn1_iv;

// address=[0x1cd07f0]
_EVP_CIPHER_type;

// address=[0x1cd0b70]
_EVP_Cipher;

// address=[0x1cd0bc0]
_EVP_MD_CTX_clear_flags;

// address=[0x1cd0be0]
_EVP_MD_CTX_md;

// address=[0x1cd0c00]
_EVP_MD_CTX_set_flags;

// address=[0x1cd0c20]
_EVP_MD_CTX_test_flags;

// address=[0x1cd0c40]
_EVP_MD_block_size;

// address=[0x1cd0c50]
_EVP_MD_flags;

// address=[0x1cd0c60]
_EVP_MD_pkey_type;

// address=[0x1cd0c70]
_EVP_MD_size;

// address=[0x1cd0cc0]
_EVP_MD_type;

// address=[0x1cd0d60]
_EVP_md5;

// address=[0x1cd0f80]
_EVP_sha1;

// address=[0x1cd0f90]
_EVP_sha224;

// address=[0x1cd0fa0]
_EVP_sha256;

// address=[0x1cd0fb0]
_EVP_sha384;

// address=[0x1cd0fc0]
_EVP_sha512;

// address=[0x1cd0fd0]
_EC_EX_DATA_clear_free_all_data;

// address=[0x1cd1080]
_EC_EX_DATA_clear_free_data;

// address=[0x1cd1170]
_EC_EX_DATA_free_all_data;

// address=[0x1cd1220]
_EC_EX_DATA_free_data;

// address=[0x1cd1310]
_EC_EX_DATA_get_data;

// address=[0x1cd1390]
_EC_EX_DATA_set_data;

// address=[0x1cd14c0]
_EC_GROUP_check_discriminant;

// address=[0x1cd1530]
_EC_GROUP_clear_free;

// address=[0x1cd16a0]
_EC_GROUP_cmp;

// address=[0x1cd1ac0]
_EC_GROUP_copy;

// address=[0x1cd1f10]
_EC_GROUP_dup;

// address=[0x1cd1fd0]
_EC_GROUP_free;

// address=[0x1cd20e0]
_EC_GROUP_get0_generator;

// address=[0x1cd20f0]
_EC_GROUP_get0_seed;

// address=[0x1cd2100]
_EC_GROUP_get_asn1_flag;

// address=[0x1cd2120]
_EC_GROUP_get_cofactor;

// address=[0x1cd2190]
_EC_GROUP_get_curve_GF2m;

// address=[0x1cd2210]
_EC_GROUP_get_curve_GFp;

// address=[0x1cd2290]
_EC_GROUP_get_curve_name;

// address=[0x1cd22a0]
_EC_GROUP_get_degree;

// address=[0x1cd2310]
_EC_GROUP_get_mont_data;

// address=[0x1cd2360]
_EC_GROUP_get_order;

// address=[0x1cd23d0]
_EC_GROUP_get_point_conversion_form;

// address=[0x1cd23e0]
_EC_GROUP_get_seed_len;

// address=[0x1cd23f0]
_EC_GROUP_have_precompute_mult;

// address=[0x1cd2460]
_EC_GROUP_method_of;

// address=[0x1cd2470]
_EC_GROUP_new;

// address=[0x1cd2610]
_EC_GROUP_precompute_mult;

// address=[0x1cd2690]
_EC_GROUP_set_asn1_flag;

// address=[0x1cd26d0]
_EC_GROUP_set_curve_GF2m;

// address=[0x1cd2750]
_EC_GROUP_set_curve_GFp;

// address=[0x1cd27d0]
_EC_GROUP_set_curve_name;

// address=[0x1cd27f0]
_EC_GROUP_set_generator;

// address=[0x1cd2920]
_EC_GROUP_set_point_conversion_form;

// address=[0x1cd2940]
_EC_GROUP_set_seed;

// address=[0x1cd2a20]
_EC_METHOD_get_field_type;

// address=[0x1cd2a30]
_EC_POINT_add;

// address=[0x1cd2b00]
_EC_POINT_clear_free;

// address=[0x1cd2ba0]
_EC_POINT_cmp;

// address=[0x1cd2c60]
_EC_POINT_copy;

// address=[0x1cd2d10]
_EC_POINT_dbl;

// address=[0x1cd2dd0]
_EC_POINT_dup;

// address=[0x1cd2e70]
_EC_POINT_free;

// address=[0x1cd2ed0]
_EC_POINT_get_Jprojective_coordinates_GFp;

// address=[0x1cd2f80]
_EC_POINT_get_affine_coordinates_GF2m;

// address=[0x1cd3030]
_EC_POINT_get_affine_coordinates_GFp;

// address=[0x1cd30e0]
_EC_POINT_invert;

// address=[0x1cd3190]
_EC_POINT_is_at_infinity;

// address=[0x1cd3230]
_EC_POINT_is_on_curve;

// address=[0x1cd32d0]
_EC_POINT_make_affine;

// address=[0x1cd3370]
_EC_POINT_method_of;

// address=[0x1cd3380]
_EC_POINT_mul;

// address=[0x1cd3490]
_EC_POINT_new;

// address=[0x1cd35b0]
_EC_POINT_set_Jprojective_coordinates_GFp;

// address=[0x1cd3660]
_EC_POINT_set_affine_coordinates_GF2m;

// address=[0x1cd3710]
_EC_POINT_set_affine_coordinates_GFp;

// address=[0x1cd37c0]
_EC_POINT_set_to_infinity;

// address=[0x1cd3860]
_EC_POINTs_make_affine;

// address=[0x1cd3960]
_EC_POINTs_mul;

// address=[0x1cd39f0]
_ec_precompute_mont_data;

// address=[0x1cd3b30]
_X509_NAME_oneline;

// address=[0x1cd42a0]
_ASN1_PRINTABLE_type;

// address=[0x1cd4450]
_ASN1_UNIVERSALSTRING_to_string;

// address=[0x1cd45f0]
_ASN1_STRING_TABLE_add;

// address=[0x1cd47a0]
_ASN1_STRING_TABLE_cleanup;

// address=[0x1cd4800]
_ASN1_STRING_TABLE_get;

// address=[0x1cd4910]
_ASN1_STRING_get_default_mask;

// address=[0x1cd4920]
_ASN1_STRING_set_by_NID;

// address=[0x1cd4a70]
_ASN1_STRING_set_default_mask;

// address=[0x1cd4a80]
_ASN1_STRING_set_default_mask_asc;

// address=[0x1cd4d10]
_OBJ_cmp;

// address=[0x1cd4d80]
_OBJ_dup;

// address=[0x1cd5040]
_BUF_MEM_free;

// address=[0x1cd50b0]
_BUF_MEM_grow;

// address=[0x1cd5260]
_BUF_MEM_grow_clean;

// address=[0x1cd5450]
_BUF_MEM_new;

// address=[0x1cd54f0]
_BUF_reverse;

// address=[0x1cd55f0]
_COMP_CTX_free;

// address=[0x1cd5650]
_COMP_CTX_new;

// address=[0x1cd5710]
_COMP_compress_block;

// address=[0x1cd57c0]
_COMP_expand_block;

// address=[0x1cd6a70]
_BIO_f_buffer;

// address=[0x1cd6a80]
_RSA_blinding_off;

// address=[0x1cd6af0]
_RSA_blinding_on;

// address=[0x1cd6ba0]
_RSA_flags;

// address=[0x1cd6bf0]
_RSA_private_decrypt;

// address=[0x1cd6c40]
_RSA_private_encrypt;

// address=[0x1cd6c90]
_RSA_public_decrypt;

// address=[0x1cd6ce0]
_RSA_public_encrypt;

// address=[0x1cd6d30]
_RSA_setup_blinding;

// address=[0x1cd7060]
_RSA_size;

// address=[0x1cd71e0]
_DH_free;

// address=[0x1cd73c0]
_DH_get_default_method;

// address=[0x1cd73f0]
_DH_get_ex_data;

// address=[0x1cd7420]
_DH_get_ex_new_index;

// address=[0x1cd7460]
_DH_new;

// address=[0x1cd7480]
_DH_new_method;

// address=[0x1cd7760]
_DH_set_default_method;

// address=[0x1cd7770]
_DH_set_ex_data;

// address=[0x1cd77a0]
_DH_set_method;

// address=[0x1cd7870]
_DH_size;

// address=[0x1cd78a0]
_DH_up_ref;

// address=[0x1cd7920]
_EVP_CIPHER_CTX_cleanup;

// address=[0x1cd7a00]
_EVP_CIPHER_CTX_copy;

// address=[0x1cd7bf0]
_EVP_CIPHER_CTX_ctrl;

// address=[0x1cd7cf0]
_EVP_CIPHER_CTX_free;

// address=[0x1cd7d30]
_EVP_CIPHER_CTX_init;

// address=[0x1cd7d60]
_EVP_CIPHER_CTX_new;

// address=[0x1cd7dd0]
_EVP_CIPHER_CTX_rand_key;

// address=[0x1cd7e40]
_EVP_CIPHER_CTX_set_key_length;

// address=[0x1cd7ef0]
_EVP_CIPHER_CTX_set_padding;

// address=[0x1cd7f40]
_EVP_CipherFinal;

// address=[0x1cd7fa0]
_EVP_CipherFinal_ex;

// address=[0x1cd8000]
_EVP_CipherInit;

// address=[0x1cd8050]
_EVP_CipherInit_ex;

// address=[0x1cd8600]
_EVP_CipherUpdate;

// address=[0x1cd8670]
_EVP_DecryptFinal;

// address=[0x1cd86c0]
_EVP_DecryptFinal_ex;

// address=[0x1cd8970]
_EVP_DecryptInit;

// address=[0x1cd89a0]
_EVP_DecryptInit_ex;

// address=[0x1cd89e0]
_EVP_DecryptUpdate;

// address=[0x1cd8c40]
_EVP_EncryptFinal;

// address=[0x1cd8c90]
_EVP_EncryptFinal_ex;

// address=[0x1cd8e90]
_EVP_EncryptInit;

// address=[0x1cd8ec0]
_EVP_EncryptInit_ex;

// address=[0x1cd8f00]
_EVP_EncryptUpdate;

// address=[0x1cd9270]
_X509_STORE_load_locations;

// address=[0x1cd9360]
_X509_STORE_set_default_paths;

// address=[0x1cd9420]
_X509_EXTENSION_it;

// address=[0x1cd9430]
_X509_EXTENSIONS_it;

// address=[0x1cd9440]
_X509_EXTENSION_dup;

// address=[0x1cd9470]
_X509_EXTENSION_free;

// address=[0x1cd94a0]
_X509_EXTENSION_new;

// address=[0x1cd94c0]
_d2i_X509_EXTENSION;

// address=[0x1cd94f0]
_d2i_X509_EXTENSIONS;

// address=[0x1cd9520]
_i2d_X509_EXTENSION;

// address=[0x1cd9550]
_i2d_X509_EXTENSIONS;

// address=[0x1cd9580]
_SRP_Calc_A_param;

// address=[0x1cd96c0]
_SRP_generate_client_master_secret;

// address=[0x1cd9a20]
_SRP_generate_server_master_secret;

// address=[0x1cd9c90]
_SSL_CTX_SRP_CTX_free;

// address=[0x1cd9e90]
_SSL_CTX_SRP_CTX_init;

// address=[0x1cd9fb0]
_SSL_CTX_set_srp_cb_arg;

// address=[0x1cd9fe0]
_SSL_CTX_set_srp_client_pwd_callback;

// address=[0x1cda010]
_SSL_CTX_set_srp_password;

// address=[0x1cda040]
_SSL_CTX_set_srp_strength;

// address=[0x1cda070]
_SSL_CTX_set_srp_username;

// address=[0x1cda0a0]
_SSL_CTX_set_srp_username_callback;

// address=[0x1cda0d0]
_SSL_CTX_set_srp_verify_param_callback;

// address=[0x1cda100]
_SSL_SRP_CTX_free;

// address=[0x1cda300]
_SSL_SRP_CTX_init;

// address=[0x1cda810]
_SSL_get_srp_N;

// address=[0x1cda850]
_SSL_get_srp_g;

// address=[0x1cda890]
_SSL_get_srp_userinfo;

// address=[0x1cda8d0]
_SSL_get_srp_username;

// address=[0x1cda910]
_SSL_set_srp_server_param;

// address=[0x1cdab60]
_SSL_set_srp_server_param_pw;

// address=[0x1cdacb0]
_SSL_srp_server_param_with_username;

// address=[0x1cdaeb0]
_srp_verify_server_param;

// address=[0x1cdb000]
_SSL_CTX_add_client_CA;

// address=[0x1cdb030]
_SSL_CTX_get_client_CA_list;

// address=[0x1cdb050]
_SSL_CTX_set_client_CA_list;

// address=[0x1cdb080]
_SSL_add_client_CA;

// address=[0x1cdb0b0]
_SSL_add_dir_cert_subjects_to_stack;

// address=[0x1cdb340]
_SSL_add_file_cert_subjects_to_stack;

// address=[0x1cdb550]
_SSL_dup_CA_list;

// address=[0x1cdb630]
_SSL_get_client_CA_list;

// address=[0x1cdb6b0]
_SSL_get_ex_data_X509_STORE_CTX_idx;

// address=[0x1cdb870]
_SSL_load_client_CA_file;

// address=[0x1cdbb00]
_SSL_set_client_CA_list;

// address=[0x1cdbc30]
_ssl_add_cert_chain;

// address=[0x1cdc110]
_ssl_build_cert_chain;

// address=[0x1cdc660]
_ssl_cert_add0_chain_cert;

// address=[0x1cdc6f0]
_ssl_cert_add1_chain_cert;

// address=[0x1cdc750]
_ssl_cert_clear_certs;

// address=[0x1cdc8a0]
_ssl_cert_dup;

// address=[0x1cdd200]
_ssl_cert_free;

// address=[0x1cdd470]
_ssl_cert_inst;

// address=[0x1cdd500]
_ssl_cert_new;

// address=[0x1cdd5d0]
_ssl_cert_select_current;

// address=[0x1cdd6f0]
_ssl_cert_set0_chain;

// address=[0x1cdd770]
_ssl_cert_set1_chain;

// address=[0x1cdd810]
_ssl_cert_set_cert_cb;

// address=[0x1cdd840]
_ssl_cert_set_cert_store;

// address=[0x1cdd8f0]
_ssl_cert_set_current;

// address=[0x1cdd9e0]
_ssl_cert_set_default_md;

// address=[0x1cdda60]
_ssl_sess_cert_free;

// address=[0x1cddbc0]
_ssl_sess_cert_new;

// address=[0x1cddc80]
_ssl_set_peer_cert_type;

// address=[0x1cddca0]
_ssl_verify_cert_chain;

// address=[0x1cde6e0]
_ssl3_dispatch_alert;

// address=[0x1cde8e0]
_ssl3_do_change_cipher_spec;

// address=[0x1cdeb20]
_ssl3_do_compress;

// address=[0x1cdebd0]
_ssl3_do_uncompress;

// address=[0x1cdf5b0]
_ssl3_read_bytes;

// address=[0x1ce0890]
_ssl3_read_n;

// address=[0x1ce0d30]
_ssl3_send_alert;

// address=[0x1ce0e60]
_ssl3_write_bytes;

// address=[0x1ce1200]
_ssl3_write_pending;

// address=[0x1ce1400]
_SSL_check_chain;

// address=[0x1ce1430]
_SSL_get_shared_sigalgs;

// address=[0x1ce1520]
_SSL_get_sigalgs;

// address=[0x1ce1a80]
_ssl_add_clienthello_tlsext;

// address=[0x1ce3270]
_ssl_add_serverhello_tlsext;

// address=[0x1ce4310]
_ssl_check_clienthello_tlsext_late;

// address=[0x1ce46b0]
_ssl_check_serverhello_tlsext;

// address=[0x1ce4ba0]
_ssl_parse_clienthello_tlsext;

// address=[0x1ce4d10]
_ssl_parse_serverhello_tlsext;

// address=[0x1ce4e30]
_ssl_prepare_clienthello_tlsext;

// address=[0x1ce4e60]
_ssl_prepare_serverhello_tlsext;

// address=[0x1ce6d60]
_ssl_set_client_disabled;

// address=[0x1ce7030]
_tls12_check_peer_sigalg;

// address=[0x1ce7780]
_tls12_get_hash;

// address=[0x1ce7890]
_tls12_get_psigalgs;

// address=[0x1ce79f0]
_tls12_get_sigandhash;

// address=[0x1ce7ac0]
_tls12_get_sigid;

// address=[0x1ce81c0]
_tls1_check_chain;

// address=[0x1ce8ac0]
_tls1_check_curve;

// address=[0x1ce8f60]
_tls1_check_ec_tmp_key;

// address=[0x1ce92f0]
_tls1_clear;

// address=[0x1ce9320]
_tls1_default_timeout;

// address=[0x1ce9330]
_tls1_ec_curve_id2nid;

// address=[0x1ce9360]
_tls1_ec_nid2curve_id;

// address=[0x1ce96c0]
_tls1_free;

// address=[0x1ce9950]
_tls1_heartbeat;

// address=[0x1ce9e30]
_tls1_new;

// address=[0x1ce9e90]
_tls1_process_heartbeat;

// address=[0x1cea240]
_tls1_process_sigalgs;

// address=[0x1cea460]
_tls1_process_ticket;

// address=[0x1cea810]
_tls1_save_sigalgs;

// address=[0x1cea910]
_tls1_set_cert_validity;

// address=[0x1cea9c0]
_tls1_set_curves;

// address=[0x1ceab50]
_tls1_set_curves_list;

// address=[0x1ceae00]
_tls1_set_server_sigalgs;

// address=[0x1ceb280]
_tls1_set_sigalgs;

// address=[0x1ceb490]
_tls1_set_sigalgs_list;

// address=[0x1ceb590]
_tls1_shared_curve;

// address=[0x1cebf50]
_SSL_CTX_add_client_custom_ext;

// address=[0x1cebfa0]
_SSL_CTX_add_server_custom_ext;

// address=[0x1cebff0]
_SSL_extension_supported;

// address=[0x1cec090]
_custom_ext_add;

// address=[0x1cec480]
_custom_ext_init;

// address=[0x1cec650]
_custom_ext_parse;

// address=[0x1cec7b0]
_custom_exts_copy;

// address=[0x1cec810]
_custom_exts_copy_flags;

// address=[0x1cec8d0]
_custom_exts_free;

// address=[0x1cec900]
_ENGINE_finish;

// address=[0x1cec9e0]
_ENGINE_init;

// address=[0x1ceca90]
_engine_unlocked_finish;

// address=[0x1cecba0]
_engine_unlocked_init;

// address=[0x1cecc40]
_ERR_load_crypto_strings;

// address=[0x1cecd00]
_ERR_load_SSL_strings;

// address=[0x1cecff0]
_ssl3_do_write;

// address=[0x1ced130]
_ssl3_get_finished;

// address=[0x1ced440]
_ssl3_get_message;

// address=[0x1ceda10]
_ssl3_output_cert_chain;

// address=[0x1cedbb0]
_ssl3_release_read_buffer;

// address=[0x1cedc30]
_ssl3_release_write_buffer;

// address=[0x1cedcb0]
_ssl3_send_change_cipher_spec;

// address=[0x1cedd40]
_ssl3_send_finished;

// address=[0x1cedfb0]
_ssl3_setup_buffers;

// address=[0x1cee000]
_ssl3_setup_read_buffer;

// address=[0x1cee1a0]
_ssl3_setup_write_buffer;

// address=[0x1cee410]
_ssl_cert_type;

// address=[0x1cee5a0]
_ssl_verify_alarm_type;

// address=[0x1cee6f0]
_ssl3_set_handshake_header;

// address=[0x1cee7c0]
_ssl3_handshake_write;

// address=[0x1cee810]
_ssl3_callback_ctrl;

// address=[0x1cee990]
_ssl3_choose_cipher;

// address=[0x1ceecd0]
_ssl3_clear;

// address=[0x1cef060]
_ssl3_ctrl;

// address=[0x1cf0370]
_ssl3_ctx_callback_ctrl;

// address=[0x1cf0580]
_ssl3_ctx_ctrl;

// address=[0x1cf1100]
_ssl3_default_timeout;

// address=[0x1cf1110]
_ssl3_free;

// address=[0x1cf1310]
_ssl3_get_cipher;

// address=[0x1cf1340]
_ssl3_get_cipher_by_char;

// address=[0x1cf1410]
_ssl3_get_req_cert_type;

// address=[0x1cf17a0]
_ssl3_new;

// address=[0x1cf1890]
_ssl3_num_ciphers;

// address=[0x1cf18a0]
_ssl3_peek;

// address=[0x1cf18d0]
_ssl3_pending;

// address=[0x1cf1940]
_ssl3_put_cipher_by_char;

// address=[0x1cf19e0]
_ssl3_read;

// address=[0x1cf1b50]
_ssl3_renegotiate;

// address=[0x1cf1ba0]
_ssl3_renegotiate_check;

// address=[0x1cf1d80]
_ssl3_shutdown;

// address=[0x1cf1f00]
_ssl3_write;

// address=[0x1cf20c0]
_ssl_get_algorithm2;

// address=[0x1cf2150]
_ssl23_default_timeout;

// address=[0x1cf2160]
_ssl23_get_cipher;

// address=[0x1cf21c0]
_ssl23_get_cipher_by_char;

// address=[0x1cf2210]
_ssl23_num_ciphers;

// address=[0x1cf2230]
_ssl23_peek;

// address=[0x1cf2330]
_ssl23_put_cipher_by_char;

// address=[0x1cf2410]
_ssl23_read;

// address=[0x1cf2510]
_ssl23_write;

// address=[0x1cf2660]
_TLSv1_1_client_method;

// address=[0x1cf2670]
_TLSv1_2_client_method;

// address=[0x1cf2680]
_TLSv1_client_method;

// address=[0x1cf2690]
_n_ssl3_mac;

// address=[0x1cf2d00]
_ssl3_alert_code;

// address=[0x1cf2fc0]
_ssl3_cert_verify_mac;

// address=[0x1cf2ff0]
_ssl3_change_cipher_state;

// address=[0x1cf3bd0]
_ssl3_cleanup_key_block;

// address=[0x1cf3c60]
_ssl3_digest_cached_records;

// address=[0x1cf3fa0]
_ssl3_enc;

// address=[0x1cf4270]
_ssl3_final_finish_mac;

// address=[0x1cf4320]
_ssl3_finish_mac;

// address=[0x1cf4400]
_ssl3_free_digest_list;

// address=[0x1cf48d0]
_ssl3_generate_master_secret;

// address=[0x1cf4ff0]
_ssl3_init_finished_mac;

// address=[0x1cf50b0]
_ssl3_record_sequence_update;

// address=[0x1cf5120]
_ssl3_setup_key_block;

// address=[0x1cf5420]
_ssl23_read_bytes;

// address=[0x1cf5500]
_ssl23_write_bytes;

// address=[0x1cf5680]
_EVP_dss1;

// address=[0x1cf5720]
_EVP_ecdsa;

// address=[0x1cf5ed0]
_EVP_des_cbc;

// address=[0x1cf5ee0]
_EVP_des_cfb1;

// address=[0x1cf5ef0]
_EVP_des_cfb64;

// address=[0x1cf5f00]
_EVP_des_cfb8;

// address=[0x1cf5f10]
_EVP_des_ecb;

// address=[0x1cf5f20]
_EVP_des_ofb;

// address=[0x1cf6aa0]
_EVP_des_ede;

// address=[0x1cf6ab0]
_EVP_des_ede3;

// address=[0x1cf6ac0]
_EVP_des_ede3_cbc;

// address=[0x1cf6ad0]
_EVP_des_ede3_cfb1;

// address=[0x1cf6ae0]
_EVP_des_ede3_cfb64;

// address=[0x1cf6af0]
_EVP_des_ede3_cfb8;

// address=[0x1cf6b00]
_EVP_des_ede3_ecb;

// address=[0x1cf6b10]
_EVP_des_ede3_ofb;

// address=[0x1cf6b20]
_EVP_des_ede3_wrap;

// address=[0x1cf6b30]
_EVP_des_ede_cbc;

// address=[0x1cf6b40]
_EVP_des_ede_cfb64;

// address=[0x1cf6b50]
_EVP_des_ede_ecb;

// address=[0x1cf6b60]
_EVP_des_ede_ofb;

// address=[0x1cf70a0]
_EVP_rc4;

// address=[0x1cf70b0]
_EVP_rc4_40;

// address=[0x1cf7530]
_EVP_idea_cbc;

// address=[0x1cf7540]
_EVP_idea_cfb64;

// address=[0x1cf7550]
_EVP_idea_ecb;

// address=[0x1cf7560]
_EVP_idea_ofb;

// address=[0x1cf7c20]
_EVP_rc2_40_cbc;

// address=[0x1cf7c30]
_EVP_rc2_64_cbc;

// address=[0x1cf7c40]
_EVP_rc2_cbc;

// address=[0x1cf7c50]
_EVP_rc2_cfb64;

// address=[0x1cf7c60]
_EVP_rc2_ecb;

// address=[0x1cf7c70]
_EVP_rc2_ofb;

// address=[0x1cf9ff0]
_EVP_aes_128_cbc;

// address=[0x1cfa000]
_EVP_aes_128_ccm;

// address=[0x1cfa010]
_EVP_aes_128_cfb1;

// address=[0x1cfa020]
_EVP_aes_128_cfb128;

// address=[0x1cfa030]
_EVP_aes_128_cfb8;

// address=[0x1cfa040]
_EVP_aes_128_ctr;

// address=[0x1cfa050]
_EVP_aes_128_ecb;

// address=[0x1cfa060]
_EVP_aes_128_gcm;

// address=[0x1cfa070]
_EVP_aes_128_ofb;

// address=[0x1cfa080]
_EVP_aes_128_wrap;

// address=[0x1cfa090]
_EVP_aes_128_xts;

// address=[0x1cfa0a0]
_EVP_aes_192_cbc;

// address=[0x1cfa0b0]
_EVP_aes_192_ccm;

// address=[0x1cfa0c0]
_EVP_aes_192_cfb1;

// address=[0x1cfa0d0]
_EVP_aes_192_cfb128;

// address=[0x1cfa0e0]
_EVP_aes_192_cfb8;

// address=[0x1cfa0f0]
_EVP_aes_192_ctr;

// address=[0x1cfa100]
_EVP_aes_192_ecb;

// address=[0x1cfa110]
_EVP_aes_192_gcm;

// address=[0x1cfa120]
_EVP_aes_192_ofb;

// address=[0x1cfa130]
_EVP_aes_192_wrap;

// address=[0x1cfa140]
_EVP_aes_256_cbc;

// address=[0x1cfa150]
_EVP_aes_256_ccm;

// address=[0x1cfa160]
_EVP_aes_256_cfb1;

// address=[0x1cfa170]
_EVP_aes_256_cfb128;

// address=[0x1cfa180]
_EVP_aes_256_cfb8;

// address=[0x1cfa190]
_EVP_aes_256_ctr;

// address=[0x1cfa1a0]
_EVP_aes_256_ecb;

// address=[0x1cfa1b0]
_EVP_aes_256_gcm;

// address=[0x1cfa1c0]
_EVP_aes_256_ofb;

// address=[0x1cfa1d0]
_EVP_aes_256_wrap;

// address=[0x1cfa1e0]
_EVP_aes_256_xts;

// address=[0x1cfa5a0]
_EVP_aes_128_cbc_hmac_sha1;

// address=[0x1cfa5b0]
_EVP_aes_256_cbc_hmac_sha1;

// address=[0x1cfa5c0]
_EVP_aes_128_cbc_hmac_sha256;

// address=[0x1cfa5d0]
_EVP_aes_256_cbc_hmac_sha256;

// address=[0x1cfa5e0]
_CRYPTO_dbg_free;

// address=[0x1cfa6f0]
_CRYPTO_dbg_get_options;

// address=[0x1cfa700]
_CRYPTO_dbg_malloc;

// address=[0x1cfaa10]
_CRYPTO_dbg_realloc;

// address=[0x1cfab60]
_CRYPTO_dbg_set_options;

// address=[0x1cfab70]
_CRYPTO_is_mem_check_on;

// address=[0x1cfac90]
_CRYPTO_mem_ctrl;

// address=[0x1cfaef0]
_CRYPTO_mem_leaks;

// address=[0x1cfb0d0]
_CRYPTO_mem_leaks_cb;

// address=[0x1cfb150]
_CRYPTO_mem_leaks_fp;

// address=[0x1cfb200]
_CRYPTO_pop_info;

// address=[0x1cfb290]
_CRYPTO_push_info_;

// address=[0x1cfb400]
_CRYPTO_remove_all_info;

// address=[0x1cfbf50]
_COMP_zlib;

// address=[0x1cfbf80]
_COMP_zlib_cleanup;

// address=[0x1cfbfe0]
_EVP_enc_null;

// address=[0x1cfbff0]
_EVP_PKEY_asn1_add0;

// address=[0x1cfc070]
_EVP_PKEY_asn1_add_alias;

// address=[0x1cfc100]
_EVP_PKEY_asn1_copy;

// address=[0x1cfc250]
_EVP_PKEY_asn1_find;

// address=[0x1cfc310]
_EVP_PKEY_asn1_find_str;

// address=[0x1cfc4a0]
_EVP_PKEY_asn1_free;

// address=[0x1cfc510]
_EVP_PKEY_asn1_get0;

// address=[0x1cfc590]
_EVP_PKEY_asn1_get0_info;

// address=[0x1cfc620]
_EVP_PKEY_asn1_get_count;

// address=[0x1cfc680]
_EVP_PKEY_asn1_new;

// address=[0x1cfc8b0]
_EVP_PKEY_asn1_set_ctrl;

// address=[0x1cfc8d0]
_EVP_PKEY_asn1_set_free;

// address=[0x1cfc8f0]
_EVP_PKEY_asn1_set_item;

// address=[0x1cfc910]
_EVP_PKEY_asn1_set_param;

// address=[0x1cfc960]
_EVP_PKEY_asn1_set_private;

// address=[0x1cfc990]
_EVP_PKEY_asn1_set_public;

// address=[0x1cfc9e0]
_EVP_PKEY_get0_asn1;

// address=[0x1cfcbd0]
_CONF_dump_bio;

// address=[0x1cfcc70]
_CONF_dump_fp;

// address=[0x1cfcd10]
_CONF_free;

// address=[0x1cfcdb0]
_CONF_get_number;

// address=[0x1cfced0]
_CONF_get_section;

// address=[0x1cfcf80]
_CONF_get_string;

// address=[0x1cfd040]
_CONF_load;

// address=[0x1cfd0f0]
_CONF_load_bio;

// address=[0x1cfd1b0]
_CONF_load_fp;

// address=[0x1cfd250]
_CONF_set_default_method;

// address=[0x1cfd270]
_CONF_set_nconf;

// address=[0x1cfd2d0]
_NCONF_dump_bio;

// address=[0x1cfd340]
_NCONF_dump_fp;

// address=[0x1cfd3e0]
_NCONF_free;

// address=[0x1cfd420]
_NCONF_free_data;

// address=[0x1cfd460]
_NCONF_get_number_e;

// address=[0x1cfd570]
_NCONF_get_section;

// address=[0x1cfd5f0]
_NCONF_get_string;

// address=[0x1cfd6c0]
_NCONF_load;

// address=[0x1cfd730]
_NCONF_load_bio;

// address=[0x1cfd7a0]
_NCONF_load_fp;

// address=[0x1cfd850]
_NCONF_new;

// address=[0x1cfd8e0]
_DSO_bind_func;

// address=[0x1cfd9d0]
_DSO_bind_var;

// address=[0x1cfdac0]
_DSO_convert_filename;

// address=[0x1cfdc70]
_DSO_ctrl;

// address=[0x1cfdd90]
_DSO_flags;

// address=[0x1cfddd0]
_DSO_free;

// address=[0x1cfdf80]
_DSO_get_default_method;

// address=[0x1cfdf90]
_DSO_get_filename;

// address=[0x1cfdfe0]
_DSO_get_loaded_filename;

// address=[0x1cfe030]
_DSO_get_method;

// address=[0x1cfe040]
_DSO_global_lookup;

// address=[0x1cfe0e0]
_DSO_load;

// address=[0x1cfe300]
_DSO_merge;

// address=[0x1cfe400]
_DSO_new;

// address=[0x1cfe420]
_DSO_new_method;

// address=[0x1cfe5a0]
_DSO_pathbyaddr;

// address=[0x1cfe650]
_DSO_set_default_method;

// address=[0x1cfe660]
_DSO_set_filename;

// address=[0x1cfe7b0]
_DSO_set_method;

// address=[0x1cfe7f0]
_DSO_set_name_converter;

// address=[0x1cfe850]
_DSO_up_ref;

// address=[0x1cfe8c0]
_X509_get_default_cert_area;

// address=[0x1cfe8d0]
_X509_get_default_cert_dir;

// address=[0x1cfe8e0]
_X509_get_default_cert_dir_env;

// address=[0x1cfe8f0]
_X509_get_default_cert_file;

// address=[0x1cfe900]
_X509_get_default_cert_file_env;

// address=[0x1cfe910]
_X509_get_default_private_dir;

// address=[0x1cfe920]
_ENGINE_get_pkey_meth;

// address=[0x1cfea00]
_ENGINE_get_pkey_meth_engine;

// address=[0x1cfea30]
_ENGINE_get_pkey_meths;

// address=[0x1cfea40]
_ENGINE_register_all_pkey_meths;

// address=[0x1cfeab0]
_ENGINE_register_pkey_meths;

// address=[0x1cfeb90]
_ENGINE_set_default_pkey_meths;

// address=[0x1cfec70]
_ENGINE_set_pkey_meths;

// address=[0x1cfec90]
_ENGINE_unregister_pkey_meths;

// address=[0x1cfecc0]
_engine_pkey_meths_free;

// address=[0x1cfee20]
_ENGINE_get_pkey_asn1_meth;

// address=[0x1cfef00]
_ENGINE_get_pkey_asn1_meth_engine;

// address=[0x1cfef30]
_ENGINE_get_pkey_asn1_meth_str;

// address=[0x1cff0c0]
_ENGINE_get_pkey_asn1_meths;

// address=[0x1cff0d0]
_ENGINE_pkey_asn1_find_str;

// address=[0x1cff1e0]
_ENGINE_register_all_pkey_asn1_meths;

// address=[0x1cff250]
_ENGINE_register_pkey_asn1_meths;

// address=[0x1cff330]
_ENGINE_set_default_pkey_asn1_meths;

// address=[0x1cff410]
_ENGINE_set_pkey_asn1_meths;

// address=[0x1cff430]
_ENGINE_unregister_pkey_asn1_meths;

// address=[0x1cff460]
_engine_pkey_asn1_meths_free;

// address=[0x1d00180]
_BIO_new_file;

// address=[0x1d00300]
_BIO_new_fp;

// address=[0x1d00380]
_BIO_s_file;

// address=[0x1d00640]
_BN_add_word;

// address=[0x1d00830]
_BN_div_word;

// address=[0x1d009c0]
_BN_mod_word;

// address=[0x1d00a90]
_BN_mul_word;

// address=[0x1d00bb0]
_BN_sub_word;

// address=[0x1d00da0]
_UTF8_getc;

// address=[0x1d014b0]
_UTF8_putc;

// address=[0x1d01880]
_ASN1_parse;

// address=[0x1d018c0]
_ASN1_parse_dump;

// address=[0x1d01900]
_ASN1_tag2str;

// address=[0x1d02870]
_ASN1_mbstring_copy;

// address=[0x1d028b0]
_ASN1_mbstring_ncopy;

// address=[0x1d035f0]
_ERR_print_errors;

// address=[0x1d03620]
_ERR_print_errors_cb;

// address=[0x1d03870]
_ERR_print_errors_fp;

// address=[0x1d03990]
_X509_CERT_AUX_print;

// address=[0x1d03d60]
_OpenSSL_add_all_ciphers;

// address=[0x1d04530]
_OpenSSL_add_all_digests;

// address=[0x1d04740]
_X509_ATTRIBUTE_SET_it;

// address=[0x1d04750]
_X509_ATTRIBUTE_create;

// address=[0x1d04880]
_X509_ATTRIBUTE_dup;

// address=[0x1d048b0]
_X509_ATTRIBUTE_free;

// address=[0x1d048e0]
_X509_ATTRIBUTE_it;

// address=[0x1d048f0]
_X509_ATTRIBUTE_new;

// address=[0x1d04910]
_d2i_X509_ATTRIBUTE;

// address=[0x1d04940]
_i2d_X509_ATTRIBUTE;

// address=[0x1d04970]
_X509_INFO_free;

// address=[0x1d04a60]
_X509_INFO_new;

// address=[0x1d04b30]
_PEM_X509_INFO_read;

// address=[0x1d04bf0]
_PEM_X509_INFO_read_bio;

// address=[0x1d05520]
_PEM_X509_INFO_write_bio;

// address=[0x1d05900]
_PEM_read_X509_AUX;

// address=[0x1d05940]
_PEM_read_X509_CERT_PAIR;

// address=[0x1d05980]
_PEM_read_bio_X509_AUX;

// address=[0x1d059c0]
_PEM_read_bio_X509_CERT_PAIR;

// address=[0x1d05a00]
_PEM_write_X509_AUX;

// address=[0x1d05a40]
_PEM_write_X509_CERT_PAIR;

// address=[0x1d05a80]
_PEM_write_bio_X509_AUX;

// address=[0x1d05ac0]
_PEM_write_bio_X509_CERT_PAIR;

// address=[0x1d05b00]
_PEM_read_DSAPrivateKey;

// address=[0x1d05b60]
_PEM_read_DSA_PUBKEY;

// address=[0x1d05ba0]
_PEM_read_DSAparams;

// address=[0x1d05be0]
_PEM_read_ECPKParameters;

// address=[0x1d05c20]
_PEM_read_ECPrivateKey;

// address=[0x1d05c80]
_PEM_read_EC_PUBKEY;

// address=[0x1d05cc0]
_PEM_read_NETSCAPE_CERT_SEQUENCE;

// address=[0x1d05d00]
_PEM_read_PKCS7;

// address=[0x1d05d40]
_PEM_read_PUBKEY;

// address=[0x1d05d80]
_PEM_read_RSAPrivateKey;

// address=[0x1d05de0]
_PEM_read_RSAPublicKey;

// address=[0x1d05e20]
_PEM_read_RSA_PUBKEY;

// address=[0x1d05e60]
_PEM_read_X509_CRL;

// address=[0x1d05ea0]
_PEM_read_X509_REQ;

// address=[0x1d05ee0]
_PEM_read_bio_DSAPrivateKey;

// address=[0x1d05f40]
_PEM_read_bio_DSA_PUBKEY;

// address=[0x1d05f80]
_PEM_read_bio_DSAparams;

// address=[0x1d05fc0]
_PEM_read_bio_ECPKParameters;

// address=[0x1d06000]
_PEM_read_bio_ECPrivateKey;

// address=[0x1d06060]
_PEM_read_bio_EC_PUBKEY;

// address=[0x1d060a0]
_PEM_read_bio_NETSCAPE_CERT_SEQUENCE;

// address=[0x1d060e0]
_PEM_read_bio_PKCS7;

// address=[0x1d06120]
_PEM_read_bio_PUBKEY;

// address=[0x1d06160]
_PEM_read_bio_RSAPrivateKey;

// address=[0x1d061c0]
_PEM_read_bio_RSAPublicKey;

// address=[0x1d06200]
_PEM_read_bio_RSA_PUBKEY;

// address=[0x1d06240]
_PEM_read_bio_X509_CRL;

// address=[0x1d06280]
_PEM_read_bio_X509_REQ;

// address=[0x1d062c0]
_PEM_write_DHparams;

// address=[0x1d06300]
_PEM_write_DHxparams;

// address=[0x1d06340]
_PEM_write_DSAPrivateKey;

// address=[0x1d06390]
_PEM_write_DSA_PUBKEY;

// address=[0x1d063d0]
_PEM_write_DSAparams;

// address=[0x1d06410]
_PEM_write_ECPKParameters;

// address=[0x1d06450]
_PEM_write_ECPrivateKey;

// address=[0x1d064a0]
_PEM_write_EC_PUBKEY;

// address=[0x1d064e0]
_PEM_write_NETSCAPE_CERT_SEQUENCE;

// address=[0x1d06520]
_PEM_write_PKCS7;

// address=[0x1d06560]
_PEM_write_PUBKEY;

// address=[0x1d065a0]
_PEM_write_RSAPrivateKey;

// address=[0x1d065f0]
_PEM_write_RSAPublicKey;

// address=[0x1d06630]
_PEM_write_RSA_PUBKEY;

// address=[0x1d06670]
_PEM_write_X509_CRL;

// address=[0x1d066b0]
_PEM_write_X509_REQ;

// address=[0x1d066f0]
_PEM_write_X509_REQ_NEW;

// address=[0x1d06730]
_PEM_write_bio_DHparams;

// address=[0x1d06770]
_PEM_write_bio_DHxparams;

// address=[0x1d067b0]
_PEM_write_bio_DSAPrivateKey;

// address=[0x1d06800]
_PEM_write_bio_DSA_PUBKEY;

// address=[0x1d06840]
_PEM_write_bio_DSAparams;

// address=[0x1d06880]
_PEM_write_bio_ECPKParameters;

// address=[0x1d068c0]
_PEM_write_bio_ECPrivateKey;

// address=[0x1d06910]
_PEM_write_bio_EC_PUBKEY;

// address=[0x1d06950]
_PEM_write_bio_NETSCAPE_CERT_SEQUENCE;

// address=[0x1d06990]
_PEM_write_bio_PKCS7;

// address=[0x1d069d0]
_PEM_write_bio_PUBKEY;

// address=[0x1d06a10]
_PEM_write_bio_RSAPrivateKey;

// address=[0x1d06a60]
_PEM_write_bio_RSAPublicKey;

// address=[0x1d06aa0]
_PEM_write_bio_RSA_PUBKEY;

// address=[0x1d06ae0]
_PEM_write_bio_X509_CRL;

// address=[0x1d06b20]
_PEM_write_bio_X509_REQ;

// address=[0x1d06b60]
_PEM_write_bio_X509_REQ_NEW;

// address=[0x1d06d50]
_X509_VAL_free;

// address=[0x1d06d80]
_X509_VAL_it;

// address=[0x1d06d90]
_X509_VAL_new;

// address=[0x1d06db0]
_d2i_X509_VAL;

// address=[0x1d06de0]
_i2d_X509_VAL;

// address=[0x1d06e10]
_ASN1_dup;

// address=[0x1d06f80]
_ASN1_item_dup;

// address=[0x1d070b0]
_X509_CERT_AUX_free;

// address=[0x1d070e0]
_X509_CERT_AUX_it;

// address=[0x1d070f0]
_X509_CERT_AUX_new;

// address=[0x1d07110]
_X509_CERT_PAIR_free;

// address=[0x1d07140]
_X509_CERT_PAIR_it;

// address=[0x1d07150]
_X509_CERT_PAIR_new;

// address=[0x1d07170]
_X509_add1_reject_object;

// address=[0x1d07240]
_X509_add1_trust_object;

// address=[0x1d07300]
_X509_alias_get0;

// address=[0x1d07350]
_X509_alias_set1;

// address=[0x1d07450]
_X509_keyid_get0;

// address=[0x1d074a0]
_X509_keyid_set1;

// address=[0x1d075a0]
_X509_reject_clear;

// address=[0x1d07600]
_X509_trust_clear;

// address=[0x1d076d0]
_d2i_X509_CERT_AUX;

// address=[0x1d07700]
_d2i_X509_CERT_PAIR;

// address=[0x1d07730]
_i2d_X509_CERT_AUX;

// address=[0x1d07760]
_i2d_X509_CERT_PAIR;

// address=[0x1d07790]
_AUTHORITY_KEYID_free;

// address=[0x1d077c0]
_AUTHORITY_KEYID_it;

// address=[0x1d077d0]
_AUTHORITY_KEYID_new;

// address=[0x1d077f0]
_d2i_AUTHORITY_KEYID;

// address=[0x1d07820]
_i2d_AUTHORITY_KEYID;

// address=[0x1d07ce0]
_CRL_DIST_POINTS_it;

// address=[0x1d07cf0]
_DIST_POINT_it;

// address=[0x1d07d00]
_DIST_POINT_NAME_it;

// address=[0x1d07d10]
_ISSUING_DIST_POINT_it;

// address=[0x1d081a0]
_CRL_DIST_POINTS_free;

// address=[0x1d081d0]
_CRL_DIST_POINTS_new;

// address=[0x1d081f0]
_DIST_POINT_NAME_free;

// address=[0x1d08220]
_DIST_POINT_NAME_new;

// address=[0x1d08240]
_DIST_POINT_free;

// address=[0x1d08270]
_DIST_POINT_new;

// address=[0x1d08290]
_DIST_POINT_set_dpname;

// address=[0x1d08410]
_ISSUING_DIST_POINT_free;

// address=[0x1d08440]
_ISSUING_DIST_POINT_new;

// address=[0x1d085f0]
_d2i_CRL_DIST_POINTS;

// address=[0x1d08620]
_d2i_DIST_POINT;

// address=[0x1d08650]
_d2i_DIST_POINT_NAME;

// address=[0x1d08680]
_d2i_ISSUING_DIST_POINT;

// address=[0x1d087b0]
_i2d_CRL_DIST_POINTS;

// address=[0x1d087e0]
_i2d_DIST_POINT;

// address=[0x1d08810]
_i2d_DIST_POINT_NAME;

// address=[0x1d08840]
_i2d_ISSUING_DIST_POINT;

// address=[0x1d09240]
_policy_cache_find_data;

// address=[0x1d09300]
_policy_cache_free;

// address=[0x1d09690]
_policy_cache_set;

// address=[0x1d097b0]
_X509V3_EXT_add;

// address=[0x1d09850]
_X509V3_EXT_add_alias;

// address=[0x1d09950]
_X509V3_EXT_add_list;

// address=[0x1d099a0]
_X509V3_EXT_cleanup;

// address=[0x1d099e0]
_X509V3_EXT_d2i;

// address=[0x1d09af0]
_X509V3_EXT_free;

// address=[0x1d09c00]
_X509V3_EXT_get;

// address=[0x1d09c60]
_X509V3_EXT_get_nid;

// address=[0x1d09d80]
_X509V3_add1_i2d;

// address=[0x1d0a010]
_X509V3_add_standard_extensions;

// address=[0x1d0a020]
_X509V3_get_d2i;

// address=[0x1d0a280]
_PEM_ASN1_read_bio;

// address=[0x1d0a3d0]
_PEM_ASN1_read;

// address=[0x1d0a4a0]
_PEM_ASN1_write;

// address=[0x1d0a580]
_PEM_ASN1_write_bio;

// address=[0x1d0acd0]
_PEM_bytes_read_bio;

// address=[0x1d0af40]
_PEM_def_callback;

// address=[0x1d0b0e0]
_PEM_dek_info;

// address=[0x1d0b240]
_PEM_do_header;

// address=[0x1d0b560]
_PEM_get_EVP_CIPHER_INFO;

// address=[0x1d0b870]
_PEM_proc_type;

// address=[0x1d0b930]
_PEM_read;

// address=[0x1d0ba00]
_PEM_read_bio;

// address=[0x1d0c580]
_PEM_write;

// address=[0x1d0c650]
_PEM_write_bio;

// address=[0x1d0ce00]
_fprintf;

// address=[0x1d0d050]
_pem_check_suffix;

// address=[0x1d0db60]
_BIO_CONNECT_free;

// address=[0x1d0dbd0]
_BIO_CONNECT_new;

// address=[0x1d0dce0]
_BIO_new_connect;

// address=[0x1d0dd70]
_BIO_s_connect;

// address=[0x1d0e6d0]
_RSAPrivateKey_dup;

// address=[0x1d0e700]
_RSAPrivateKey_it;

// address=[0x1d0e710]
_RSAPublicKey_dup;

// address=[0x1d0e740]
_RSAPublicKey_it;

// address=[0x1d0e750]
_RSA_OAEP_PARAMS_free;

// address=[0x1d0e780]
_RSA_OAEP_PARAMS_it;

// address=[0x1d0e790]
_RSA_OAEP_PARAMS_new;

// address=[0x1d0e7b0]
_RSA_PSS_PARAMS_free;

// address=[0x1d0e7e0]
_RSA_PSS_PARAMS_it;

// address=[0x1d0e7f0]
_RSA_PSS_PARAMS_new;

// address=[0x1d0e810]
_d2i_RSAPrivateKey;

// address=[0x1d0e840]
_d2i_RSAPublicKey;

// address=[0x1d0e870]
_d2i_RSA_OAEP_PARAMS;

// address=[0x1d0e8a0]
_d2i_RSA_PSS_PARAMS;

// address=[0x1d0e8d0]
_i2d_RSAPrivateKey;

// address=[0x1d0e900]
_i2d_RSAPublicKey;

// address=[0x1d0e930]
_i2d_RSA_OAEP_PARAMS;

// address=[0x1d0e960]
_i2d_RSA_PSS_PARAMS;

// address=[0x1d0e990]
_d2i_AutoPrivateKey;

// address=[0x1d0eb90]
_d2i_PrivateKey;

// address=[0x1d0ee10]
_PEM_read_DHparams;

// address=[0x1d0eee0]
_PEM_read_PrivateKey;

// address=[0x1d0efa0]
_PEM_read_bio_DHparams;

// address=[0x1d0f150]
_PEM_read_bio_Parameters;

// address=[0x1d0f390]
_PEM_read_bio_PrivateKey;

// address=[0x1d0f7d0]
_PEM_write_PrivateKey;

// address=[0x1d0f890]
_PEM_write_bio_Parameters;

// address=[0x1d0f990]
_PEM_write_bio_PrivateKey;

// address=[0x1d0fad0]
_ENGINE_get_load_privkey_function;

// address=[0x1d0fae0]
_ENGINE_get_load_pubkey_function;

// address=[0x1d0faf0]
_ENGINE_get_ssl_client_cert_function;

// address=[0x1d0fb00]
_ENGINE_load_private_key;

// address=[0x1d0fc70]
_ENGINE_load_public_key;

// address=[0x1d0fdf0]
_ENGINE_load_ssl_client_cert;

// address=[0x1d0ff30]
_ENGINE_set_load_privkey_function;

// address=[0x1d0ff50]
_ENGINE_set_load_pubkey_function;

// address=[0x1d0ff70]
_ENGINE_set_load_ssl_client_cert_function;

// address=[0x1d0ff90]
_d2i_SSL_SESSION;

// address=[0x1d120c0]
_i2d_SSL_SESSION;

// address=[0x1d132f0]
_BN_CTX_end;

// address=[0x1d133a0]
_BN_CTX_free;

// address=[0x1d133f0]
_BN_CTX_get;

// address=[0x1d134b0]
_BN_CTX_init;

// address=[0x1d13510]
_BN_CTX_new;

// address=[0x1d135d0]
_BN_CTX_start;

// address=[0x1d13d70]
_RSA_sign;

// address=[0x1d140f0]
_RSA_verify;

// address=[0x1d14190]
_int_rsa_verify;

// address=[0x1d155d0]
_DHparams_dup;

// address=[0x1d15650]
_DHparams_print;

// address=[0x1d16710]
_DH_OpenSSL;

// address=[0x1d16720]
_DH_compute_key;

// address=[0x1d16760]
_DH_compute_key_padded;

// address=[0x1d16840]
_DH_generate_key;

// address=[0x1d169a0]
_dsa_pub_internal_it;

// address=[0x1d169b0]
_DSAPrivateKey_it;

// address=[0x1d169c0]
_DSAPublicKey_it;

// address=[0x1d169d0]
_DSA_SIG_it;

// address=[0x1d169e0]
_DSA_sign;

// address=[0x1d16a90]
_DSA_verify;

// address=[0x1d16c20]
_DSAparams_dup;

// address=[0x1d16c50]
_DSAparams_it;

// address=[0x1d16c60]
_d2i_DSAPrivateKey;

// address=[0x1d16c90]
_d2i_DSAPublicKey;

// address=[0x1d16cc0]
_d2i_DSA_SIG;

// address=[0x1d16cf0]
_d2i_DSAparams;

// address=[0x1d16d20]
_i2d_DSAPrivateKey;

// address=[0x1d16d50]
_i2d_DSAPublicKey;

// address=[0x1d16d80]
_i2d_DSA_SIG;

// address=[0x1d16db0]
_i2d_DSAparams;

// address=[0x1d16de0]
_EVP_SignFinal;

// address=[0x1d17150]
_EVP_VerifyFinal;

// address=[0x1d17460]
_EVP_PKEY_CTX_ctrl;

// address=[0x1d175e0]
_EVP_PKEY_CTX_ctrl_str;

// address=[0x1d17720]
_EVP_PKEY_CTX_dup;

// address=[0x1d17900]
_EVP_PKEY_CTX_free;

// address=[0x1d179c0]
_EVP_PKEY_CTX_get0_peerkey;

// address=[0x1d179d0]
_EVP_PKEY_CTX_get0_pkey;

// address=[0x1d179e0]
_EVP_PKEY_CTX_get_app_data;

// address=[0x1d179f0]
_EVP_PKEY_CTX_get_data;

// address=[0x1d17a00]
_EVP_PKEY_CTX_get_operation;

// address=[0x1d17a10]
_EVP_PKEY_CTX_new;

// address=[0x1d17a40]
_EVP_PKEY_CTX_new_id;

// address=[0x1d17a70]
_EVP_PKEY_CTX_set0_keygen_info;

// address=[0x1d17a90]
_EVP_PKEY_CTX_set_app_data;

// address=[0x1d17ab0]
_EVP_PKEY_CTX_set_data;

// address=[0x1d17ad0]
_EVP_PKEY_meth_add0;

// address=[0x1d17b50]
_EVP_PKEY_meth_copy;

// address=[0x1d17cd0]
_EVP_PKEY_meth_find;

// address=[0x1d17e00]
_EVP_PKEY_meth_free;

// address=[0x1d17e40]
_EVP_PKEY_meth_get0_info;

// address=[0x1d17e70]
_EVP_PKEY_meth_get_cleanup;

// address=[0x1d17e90]
_EVP_PKEY_meth_get_copy;

// address=[0x1d17eb0]
_EVP_PKEY_meth_get_ctrl;

// address=[0x1d17ee0]
_EVP_PKEY_meth_get_decrypt;

// address=[0x1d17f10]
_EVP_PKEY_meth_get_derive;

// address=[0x1d17f40]
_EVP_PKEY_meth_get_encrypt;

// address=[0x1d17f70]
_EVP_PKEY_meth_get_init;

// address=[0x1d17f90]
_EVP_PKEY_meth_get_keygen;

// address=[0x1d17fc0]
_EVP_PKEY_meth_get_paramgen;

// address=[0x1d17ff0]
_EVP_PKEY_meth_get_sign;

// address=[0x1d18020]
_EVP_PKEY_meth_get_signctx;

// address=[0x1d18050]
_EVP_PKEY_meth_get_verify;

// address=[0x1d18080]
_EVP_PKEY_meth_get_verify_recover;

// address=[0x1d180b0]
_EVP_PKEY_meth_get_verifyctx;

// address=[0x1d180e0]
_EVP_PKEY_meth_new;

// address=[0x1d18170]
_EVP_PKEY_meth_set_cleanup;

// address=[0x1d18190]
_EVP_PKEY_meth_set_copy;

// address=[0x1d181b0]
_EVP_PKEY_meth_set_ctrl;

// address=[0x1d181d0]
_EVP_PKEY_meth_set_decrypt;

// address=[0x1d181f0]
_EVP_PKEY_meth_set_derive;

// address=[0x1d18210]
_EVP_PKEY_meth_set_encrypt;

// address=[0x1d18230]
_EVP_PKEY_meth_set_init;

// address=[0x1d18250]
_EVP_PKEY_meth_set_keygen;

// address=[0x1d18270]
_EVP_PKEY_meth_set_paramgen;

// address=[0x1d18290]
_EVP_PKEY_meth_set_sign;

// address=[0x1d182b0]
_EVP_PKEY_meth_set_signctx;

// address=[0x1d182d0]
_EVP_PKEY_meth_set_verify;

// address=[0x1d182f0]
_EVP_PKEY_meth_set_verify_recover;

// address=[0x1d18310]
_EVP_PKEY_meth_set_verifyctx;

// address=[0x1d18660]
_EVP_PKEY_decrypt;

// address=[0x1d187f0]
_EVP_PKEY_decrypt_init;

// address=[0x1d188d0]
_EVP_PKEY_derive;

// address=[0x1d18a70]
_EVP_PKEY_derive_init;

// address=[0x1d18b50]
_EVP_PKEY_derive_set_peer;

// address=[0x1d18e20]
_EVP_PKEY_encrypt;

// address=[0x1d18fb0]
_EVP_PKEY_encrypt_init;

// address=[0x1d19090]
_EVP_PKEY_sign;

// address=[0x1d19220]
_EVP_PKEY_sign_init;

// address=[0x1d19300]
_EVP_PKEY_verify;

// address=[0x1d193d0]
_EVP_PKEY_verify_init;

// address=[0x1d194b0]
_EVP_PKEY_verify_recover;

// address=[0x1d19650]
_EVP_PKEY_verify_recover_init;

// address=[0x1d19730]
_EC_GROUP_new_by_curve_name;

// address=[0x1d19850]
_EC_curve_nid2nist;

// address=[0x1d198c0]
_EC_curve_nist2nid;

// address=[0x1d19940]
_EC_get_builtin_curves;

// address=[0x1d19ff0]
_EC_POINT_oct2point;

// address=[0x1d1a120]
_EC_POINT_point2oct;

// address=[0x1d1a260]
_EC_POINT_set_compressed_coordinates_GF2m;

// address=[0x1d1a390]
_EC_POINT_set_compressed_coordinates_GFp;

// address=[0x1d1a4c0]
_ECDSA_do_sign;

// address=[0x1d1a4f0]
_ECDSA_do_sign_ex;

// address=[0x1d1a580]
_ECDSA_sign;

// address=[0x1d1a5c0]
_ECDSA_sign_ex;

// address=[0x1d1a670]
_ECDSA_sign_setup;

// address=[0x1d1a6f0]
_ECDH_compute_key;

// address=[0x1d1a780]
_X509_certificate_type;

// address=[0x1d1aa00]
_dtls1_connect;

// address=[0x1d1bc30]
_DTLS_client_method;

// address=[0x1d1bc40]
_DTLSv1_2_client_method;

// address=[0x1d1bc50]
_DTLSv1_client_method;

// address=[0x1d1c7b0]
_RAND_SSLeay;

// address=[0x1d1c7c0]
_ssleay_rand_bytes;

// address=[0x1d1cee0]
_ENGINE_get_RAND;

// address=[0x1d1cef0]
_ENGINE_get_default_RAND;

// address=[0x1d1cf20]
_ENGINE_register_RAND;

// address=[0x1d1cf70]
_ENGINE_register_all_RAND;

// address=[0x1d1cfe0]
_ENGINE_set_RAND;

// address=[0x1d1d000]
_ENGINE_set_default_RAND;

// address=[0x1d1d050]
_ENGINE_unregister_RAND;

// address=[0x1d1d0a0]
_OPENSSL_issetugid;

// address=[0x1d1d0b0]
_ASN1_add_oid_module;

// address=[0x1d1d430]
_EVP_add_alg_module;

// address=[0x1d1d660]
_ENGINE_add_conf_module;

// address=[0x1d1ddb0]
_ASN1_TYPE_cmp;

// address=[0x1d1dea0]
_ASN1_TYPE_get;

// address=[0x1d1ded0]
_ASN1_TYPE_set;

// address=[0x1d1df70]
_ASN1_TYPE_set1;

// address=[0x1d1e060]
_BIO_dump;

// address=[0x1d1e090]
_BIO_dump_cb;

// address=[0x1d1e0c0]
_BIO_dump_fp;

// address=[0x1d1e0f0]
_BIO_dump_indent;

// address=[0x1d1e130]
_BIO_dump_indent_cb;

// address=[0x1d1e740]
_BIO_dump_indent_fp;

// address=[0x1d1e780]
_BIO_hex_string;

// address=[0x1d1e930]
_PROXY_POLICY_it;

// address=[0x1d1e940]
_PROXY_CERT_INFO_EXTENSION_free;

// address=[0x1d1e970]
_PROXY_CERT_INFO_EXTENSION_it;

// address=[0x1d1e980]
_PROXY_CERT_INFO_EXTENSION_new;

// address=[0x1d1e9a0]
_PROXY_POLICY_free;

// address=[0x1d1e9d0]
_PROXY_POLICY_new;

// address=[0x1d1e9f0]
_d2i_PROXY_CERT_INFO_EXTENSION;

// address=[0x1d1ea20]
_d2i_PROXY_POLICY;

// address=[0x1d1ea50]
_i2d_PROXY_CERT_INFO_EXTENSION;

// address=[0x1d1ea80]
_i2d_PROXY_POLICY;

// address=[0x1d1eab0]
_BASIC_CONSTRAINTS_it;

// address=[0x1d1ecd0]
_BASIC_CONSTRAINTS_free;

// address=[0x1d1ed00]
_BASIC_CONSTRAINTS_new;

// address=[0x1d1ed20]
_d2i_BASIC_CONSTRAINTS;

// address=[0x1d1ed50]
_i2d_BASIC_CONSTRAINTS;

// address=[0x1d1ed80]
_ASN1_ENUMERATED_get;

// address=[0x1d1ee80]
_ASN1_ENUMERATED_set;

// address=[0x1d1f080]
_ASN1_ENUMERATED_to_BN;

// address=[0x1d1f120]
_BN_to_ASN1_ENUMERATED;

// address=[0x1d1f2d0]
_ASN1_item_pack;

// address=[0x1d1f430]
_ASN1_item_unpack;

// address=[0x1d1f500]
_ASN1_pack_string;

// address=[0x1d1f6e0]
_ASN1_seq_pack;

// address=[0x1d1f830]
_ASN1_seq_unpack;

// address=[0x1d1f900]
_ASN1_unpack_string;

// address=[0x1d1f9d0]
_ASN1_item_sign;

// address=[0x1d1fac0]
_ASN1_item_sign_ctx;

// address=[0x1d1ff70]
_ASN1_sign;

// address=[0x1d203e0]
_OCSP_CERTID_dup;

// address=[0x1d20410]
_OCSP_cert_id_new;

// address=[0x1d206b0]
_OCSP_cert_to_id;

// address=[0x1d20780]
_OCSP_id_cmp;

// address=[0x1d207f0]
_OCSP_id_issuer_cmp;

// address=[0x1d208a0]
_OCSP_parse_url;

// address=[0x1d211b0]
_ACCESS_DESCRIPTION_it;

// address=[0x1d211c0]
_AUTHORITY_INFO_ACCESS_it;

// address=[0x1d211d0]
_ACCESS_DESCRIPTION_free;

// address=[0x1d21200]
_ACCESS_DESCRIPTION_new;

// address=[0x1d21220]
_AUTHORITY_INFO_ACCESS_free;

// address=[0x1d21250]
_AUTHORITY_INFO_ACCESS_new;

// address=[0x1d21270]
_d2i_ACCESS_DESCRIPTION;

// address=[0x1d212a0]
_d2i_AUTHORITY_INFO_ACCESS;

// address=[0x1d212d0]
_i2a_ACCESS_DESCRIPTION;

// address=[0x1d21300]
_i2d_ACCESS_DESCRIPTION;

// address=[0x1d21330]
_i2d_AUTHORITY_INFO_ACCESS;

// address=[0x1d21360]
_a2i_ASN1_INTEGER;

// address=[0x1d218a0]
_i2a_ASN1_INTEGER;

// address=[0x1d21ac0]
_a2i_ASN1_STRING;

// address=[0x1d21fa0]
_i2a_ASN1_STRING;

// address=[0x1d22510]
_i2v_GENERAL_NAMES;

// address=[0x1d225c0]
_GENERAL_NAME_print;

// address=[0x1d228e0]
_a2i_GENERAL_NAME;

// address=[0x1d23330]
_i2v_GENERAL_NAME;

// address=[0x1d23810]
_v2i_GENERAL_NAME;

// address=[0x1d23840]
_v2i_GENERAL_NAMES;

// address=[0x1d23960]
_v2i_GENERAL_NAME_ex;

// address=[0x1d23b60]
_ASN1_item_verify;

// address=[0x1d23fd0]
_ASN1_verify;

// address=[0x1d242a0]
_DES_decrypt3;

// address=[0x1d245a0]
_DES_ede3_cbc_encrypt;

// address=[0x1d25580]
_DES_encrypt1;

// address=[0x1d25db0]
_DES_encrypt2;

// address=[0x1d263f0]
_DES_encrypt3;

// address=[0x1d266f0]
_DES_ncbc_encrypt;

// address=[0x1d27660]
_BN_lshift;

// address=[0x1d27920]
_BN_lshift1;

// address=[0x1d27b00]
_BN_rshift;

// address=[0x1d27d90]
_BN_rshift1;

// address=[0x1d27f70]
_PKCS5_PBE_add;

// address=[0x1d27f80]
_PKCS5_PBE_keyivgen;

// address=[0x1d284c0]
_PKCS5_PBKDF2_HMAC;

// address=[0x1d28950]
_PKCS5_PBKDF2_HMAC_SHA1;

// address=[0x1d289a0]
_PKCS5_v2_PBE_keyivgen;

// address=[0x1d28c20]
_PKCS5_v2_PBKDF2_keyivgen;

// address=[0x1d29080]
_PKCS12_PBE_add;

// address=[0x1d29090]
_PKCS12_PBE_keyivgen;

// address=[0x1d29380]
_OPENSSL_gmtime;

// address=[0x1d29400]
_OPENSSL_gmtime_adj;

// address=[0x1d295c0]
_OPENSSL_gmtime_diff;

// address=[0x1d29aa0]
_X509_policy_level_get0_node;

// address=[0x1d29b00]
_X509_policy_level_node_count;

// address=[0x1d29b80]
_X509_policy_node_get0_parent;

// address=[0x1d29ba0]
_X509_policy_node_get0_policy;

// address=[0x1d29bc0]
_X509_policy_node_get0_qualifiers;

// address=[0x1d29be0]
_X509_policy_tree_get0_level;

// address=[0x1d29c20]
_X509_policy_tree_get0_policies;

// address=[0x1d29c40]
_X509_policy_tree_get0_user_policies;

// address=[0x1d29c80]
_X509_policy_tree_level_count;

// address=[0x1d29ca0]
_policy_data_free;

// address=[0x1d29d10]
_policy_data_new;

// address=[0x1d29e90]
_level_add_node;

// address=[0x1d2a010]
_level_find_node;

// address=[0x1d2a110]
_policy_node_cmp_new;

// address=[0x1d2a130]
_policy_node_free;

// address=[0x1d2a150]
_policy_node_match;

// address=[0x1d2a250]
_tree_find_sk;

// address=[0x1d2a320]
_ASN1_d2i_bio;

// address=[0x1d2a430]
_ASN1_d2i_fp;

// address=[0x1d2a4f0]
_ASN1_item_d2i_bio;

// address=[0x1d2a600]
_ASN1_item_d2i_fp;

// address=[0x1d2ac00]
_ASN1_i2d_bio;

// address=[0x1d2ad90]
_ASN1_i2d_fp;

// address=[0x1d2ae50]
_ASN1_item_i2d_bio;

// address=[0x1d2afa0]
_ASN1_item_i2d_fp;

// address=[0x1d2b060]
_i2d_PrivateKey;

// address=[0x1d2b170]
_X9_62_PENTANOMIAL_it;

// address=[0x1d2b190]
_X9_62_CHARACTERISTIC_TWO_it;

// address=[0x1d2b1b0]
_X9_62_FIELDID_it;

// address=[0x1d2b1c0]
_X9_62_CURVE_it;

// address=[0x1d2b1d0]
_ECPARAMETERS_it;

// address=[0x1d2b1e0]
_ECPKPARAMETERS_it;

// address=[0x1d2b1f0]
_ECPARAMETERS_free;

// address=[0x1d2b220]
_ECPARAMETERS_new;

// address=[0x1d2b240]
_ECPKPARAMETERS_free;

// address=[0x1d2b270]
_ECPKPARAMETERS_new;

// address=[0x1d2b290]
_EC_GROUP_get_basis_type;

// address=[0x1d2b340]
_EC_GROUP_get_pentanomial_basis;

// address=[0x1d2b480]
_EC_GROUP_get_trinomial_basis;

// address=[0x1d2b550]
_EC_PRIVATEKEY_free;

// address=[0x1d2b580]
_EC_PRIVATEKEY_it;

// address=[0x1d2b590]
_EC_PRIVATEKEY_new;

// address=[0x1d2b5b0]
_X9_62_CHARACTERISTIC_TWO_free;

// address=[0x1d2b5e0]
_X9_62_CHARACTERISTIC_TWO_new;

// address=[0x1d2b600]
_X9_62_PENTANOMIAL_free;

// address=[0x1d2b630]
_X9_62_PENTANOMIAL_new;

// address=[0x1d2b650]
_d2i_ECPKPARAMETERS;

// address=[0x1d2b680]
_d2i_ECPKParameters;

// address=[0x1d2b810]
_d2i_ECParameters;

// address=[0x1d2b950]
_d2i_ECPrivateKey;

// address=[0x1d2bdd0]
_d2i_EC_PRIVATEKEY;

// address=[0x1d2dbd0]
_i2d_ECPKPARAMETERS;

// address=[0x1d2dc00]
_i2d_ECPKParameters;

// address=[0x1d2dcf0]
_i2d_ECParameters;

// address=[0x1d2dd50]
_i2d_ECPrivateKey;

// address=[0x1d2e2b0]
_i2d_EC_PRIVATEKEY;

// address=[0x1d2e2e0]
_i2o_ECPublicKey;

// address=[0x1d2e4b0]
_o2i_ECPublicKey;

// address=[0x1d2e690]
_PKCS7_ISSUER_AND_SERIAL_it;

// address=[0x1d2e700]
_PKCS7_SIGNER_INFO_it;

// address=[0x1d2e710]
_PKCS7_RECIP_INFO_it;

// address=[0x1d2e720]
_PKCS7_SIGNED_it;

// address=[0x1d2e730]
_PKCS7_ENC_CONTENT_it;

// address=[0x1d2e740]
_PKCS7_ENVELOPE_it;

// address=[0x1d2e750]
_PKCS7_SIGN_ENVELOPE_it;

// address=[0x1d2e760]
_PKCS7_DIGEST_it;

// address=[0x1d2e770]
_PKCS7_ENCRYPT_it;

// address=[0x1d2e780]
_PKCS7_it;

// address=[0x1d2e8b0]
_PKCS7_ATTR_SIGN_it;

// address=[0x1d2e8c0]
_PKCS7_ATTR_VERIFY_it;

// address=[0x1d2e8d0]
_PKCS7_DIGEST_free;

// address=[0x1d2e900]
_PKCS7_DIGEST_new;

// address=[0x1d2e920]
_PKCS7_ENCRYPT_free;

// address=[0x1d2e950]
_PKCS7_ENCRYPT_new;

// address=[0x1d2e970]
_PKCS7_ENC_CONTENT_free;

// address=[0x1d2e9a0]
_PKCS7_ENC_CONTENT_new;

// address=[0x1d2e9c0]
_PKCS7_ENVELOPE_free;

// address=[0x1d2e9f0]
_PKCS7_ENVELOPE_new;

// address=[0x1d2ea10]
_PKCS7_ISSUER_AND_SERIAL_free;

// address=[0x1d2ea40]
_PKCS7_ISSUER_AND_SERIAL_new;

// address=[0x1d2ea60]
_PKCS7_RECIP_INFO_free;

// address=[0x1d2ea90]
_PKCS7_RECIP_INFO_new;

// address=[0x1d2eab0]
_PKCS7_SIGNED_free;

// address=[0x1d2eae0]
_PKCS7_SIGNED_new;

// address=[0x1d2eb00]
_PKCS7_SIGNER_INFO_free;

// address=[0x1d2eb30]
_PKCS7_SIGNER_INFO_new;

// address=[0x1d2eb50]
_PKCS7_SIGN_ENVELOPE_free;

// address=[0x1d2eb80]
_PKCS7_SIGN_ENVELOPE_new;

// address=[0x1d2eba0]
_PKCS7_dup;

// address=[0x1d2ebd0]
_PKCS7_free;

// address=[0x1d2ec00]
_PKCS7_new;

// address=[0x1d2ec20]
_PKCS7_print_ctx;

// address=[0x1d2ec60]
_d2i_PKCS7;

// address=[0x1d2ec90]
_d2i_PKCS7_DIGEST;

// address=[0x1d2ecc0]
_d2i_PKCS7_ENCRYPT;

// address=[0x1d2ecf0]
_d2i_PKCS7_ENC_CONTENT;

// address=[0x1d2ed20]
_d2i_PKCS7_ENVELOPE;

// address=[0x1d2ed50]
_d2i_PKCS7_ISSUER_AND_SERIAL;

// address=[0x1d2ed80]
_d2i_PKCS7_RECIP_INFO;

// address=[0x1d2edb0]
_d2i_PKCS7_SIGNED;

// address=[0x1d2ede0]
_d2i_PKCS7_SIGNER_INFO;

// address=[0x1d2ee10]
_d2i_PKCS7_SIGN_ENVELOPE;

// address=[0x1d2ee40]
_i2d_PKCS7;

// address=[0x1d2ee70]
_i2d_PKCS7_DIGEST;

// address=[0x1d2eea0]
_i2d_PKCS7_ENCRYPT;

// address=[0x1d2eed0]
_i2d_PKCS7_ENC_CONTENT;

// address=[0x1d2ef00]
_i2d_PKCS7_ENVELOPE;

// address=[0x1d2ef30]
_i2d_PKCS7_ISSUER_AND_SERIAL;

// address=[0x1d2ef60]
_i2d_PKCS7_NDEF;

// address=[0x1d2ef90]
_i2d_PKCS7_RECIP_INFO;

// address=[0x1d2efc0]
_i2d_PKCS7_SIGNED;

// address=[0x1d2eff0]
_i2d_PKCS7_SIGNER_INFO;

// address=[0x1d2f020]
_i2d_PKCS7_SIGN_ENVELOPE;

// address=[0x1d2f050]
_X509_SIG_free;

// address=[0x1d2f080]
_X509_SIG_it;

// address=[0x1d2f090]
_X509_SIG_new;

// address=[0x1d2f0b0]
_d2i_X509_SIG;

// address=[0x1d2f0e0]
_i2d_X509_SIG;

// address=[0x1d2f110]
_X509_REQ_INFO_it;

// address=[0x1d2f180]
_X509_REQ_INFO_free;

// address=[0x1d2f1b0]
_X509_REQ_INFO_new;

// address=[0x1d2f1d0]
_X509_REQ_dup;

// address=[0x1d2f200]
_X509_REQ_free;

// address=[0x1d2f230]
_X509_REQ_it;

// address=[0x1d2f240]
_X509_REQ_new;

// address=[0x1d2f260]
_d2i_X509_REQ;

// address=[0x1d2f290]
_d2i_X509_REQ_INFO;

// address=[0x1d2f2c0]
_i2d_X509_REQ;

// address=[0x1d2f2f0]
_i2d_X509_REQ_INFO;

// address=[0x1d2f320]
_NETSCAPE_SPKAC_it;

// address=[0x1d2f330]
_NETSCAPE_SPKAC_free;

// address=[0x1d2f360]
_NETSCAPE_SPKAC_new;

// address=[0x1d2f380]
_NETSCAPE_SPKI_free;

// address=[0x1d2f3b0]
_NETSCAPE_SPKI_it;

// address=[0x1d2f3c0]
_NETSCAPE_SPKI_new;

// address=[0x1d2f3e0]
_d2i_NETSCAPE_SPKAC;

// address=[0x1d2f410]
_d2i_NETSCAPE_SPKI;

// address=[0x1d2f440]
_i2d_NETSCAPE_SPKAC;

// address=[0x1d2f470]
_i2d_NETSCAPE_SPKI;

// address=[0x1d2f4a0]
_ASN1_digest;

// address=[0x1d2f5f0]
_ASN1_item_digest;

// address=[0x1d2f780]
_PKCS8_PRIV_KEY_INFO_free;

// address=[0x1d2f7b0]
_PKCS8_PRIV_KEY_INFO_it;

// address=[0x1d2f7c0]
_PKCS8_PRIV_KEY_INFO_new;

// address=[0x1d2f7e0]
_PKCS8_pkey_get0;

// address=[0x1d2f8c0]
_PKCS8_pkey_set0;

// address=[0x1d2fa00]
_d2i_PKCS8_PRIV_KEY_INFO;

// address=[0x1d2fa30]
_i2d_PKCS8_PRIV_KEY_INFO;

// address=[0x1d2fa60]
_EVP_PKCS82PKEY;

// address=[0x1d2fc70]
_EVP_PKEY2PKCS8;

// address=[0x1d2fc90]
_EVP_PKEY2PKCS8_broken;

// address=[0x1d2fe10]
_EVP_PKEY_add1_attr;

// address=[0x1d2fe50]
_EVP_PKEY_add1_attr_by_NID;

// address=[0x1d2fea0]
_EVP_PKEY_add1_attr_by_OBJ;

// address=[0x1d2fef0]
_EVP_PKEY_add1_attr_by_txt;

// address=[0x1d2ff40]
_EVP_PKEY_delete_attr;

// address=[0x1d2ff70]
_EVP_PKEY_get_attr;

// address=[0x1d2ffa0]
_EVP_PKEY_get_attr_by_NID;

// address=[0x1d2ffd0]
_EVP_PKEY_get_attr_by_OBJ;

// address=[0x1d30000]
_EVP_PKEY_get_attr_count;

// address=[0x1d30030]
_PKCS8_set_broken;

// address=[0x1d300d0]
_OCSP_REQ_CTX_add1_header;

// address=[0x1d301a0]
_OCSP_REQ_CTX_free;

// address=[0x1d30200]
_OCSP_REQ_CTX_get0_mem_bio;

// address=[0x1d30210]
_OCSP_REQ_CTX_http;

// address=[0x1d30270]
_OCSP_REQ_CTX_i2d;

// address=[0x1d30320]
_OCSP_REQ_CTX_nbio;

// address=[0x1d30a40]
_OCSP_REQ_CTX_nbio_d2i;

// address=[0x1d30b40]
_OCSP_REQ_CTX_new;

// address=[0x1d30c60]
_OCSP_REQ_CTX_set1_req;

// address=[0x1d30c90]
_OCSP_sendreq_bio;

// address=[0x1d30d90]
_OCSP_sendreq_nbio;

// address=[0x1d30dc0]
_OCSP_sendreq_new;

// address=[0x1d30e80]
_OCSP_set_max_response_length;

// address=[0x1d311c0]
_X509_REQ_add1_attr;

// address=[0x1d31200]
_X509_REQ_add1_attr_by_NID;

// address=[0x1d31250]
_X509_REQ_add1_attr_by_OBJ;

// address=[0x1d312a0]
_X509_REQ_add1_attr_by_txt;

// address=[0x1d312f0]
_X509_REQ_add_extensions;

// address=[0x1d31320]
_X509_REQ_add_extensions_nid;

// address=[0x1d314e0]
_X509_REQ_check_private_key;

// address=[0x1d31690]
_X509_REQ_delete_attr;

// address=[0x1d316c0]
_X509_REQ_extension_nid;

// address=[0x1d31740]
_X509_REQ_get_attr;

// address=[0x1d31770]
_X509_REQ_get_attr_by_NID;

// address=[0x1d317a0]
_X509_REQ_get_attr_by_OBJ;

// address=[0x1d317d0]
_X509_REQ_get_attr_count;

// address=[0x1d31800]
_X509_REQ_get_extension_nids;

// address=[0x1d31810]
_X509_REQ_get_extensions;

// address=[0x1d319c0]
_X509_REQ_get_pubkey;

// address=[0x1d31a00]
_X509_REQ_set_extension_nids;

// address=[0x1d31a10]
_X509_to_X509_REQ;

// address=[0x1d31ba0]
_asn1_do_adb;

// address=[0x1d31d20]
_asn1_do_lock;

// address=[0x1d31e00]
_asn1_enc_free;

// address=[0x1d31e90]
_asn1_enc_init;

// address=[0x1d31f00]
_asn1_enc_restore;

// address=[0x1d31fc0]
_asn1_enc_save;

// address=[0x1d320a0]
_asn1_get_choice_selector;

// address=[0x1d32150]
_asn1_get_field_ptr;

// address=[0x1d321a0]
_asn1_set_choice_selector;

// address=[0x1d321f0]
_ASN1_BIT_STRING_check;

// address=[0x1d322e0]
_ASN1_BIT_STRING_get_bit;

// address=[0x1d323a0]
_ASN1_BIT_STRING_set;

// address=[0x1d323d0]
_ASN1_BIT_STRING_set_bit;

// address=[0x1d32600]
_c2i_ASN1_BIT_STRING;

// address=[0x1d32890]
_i2c_ASN1_BIT_STRING;

// address=[0x1d32ae0]
_BN_bntest_rand;

// address=[0x1d32b10]
_BN_pseudo_rand;

// address=[0x1d32b40]
_BN_pseudo_rand_range;

// address=[0x1d32b70]
_BN_rand;

// address=[0x1d32ba0]
_BN_rand_range;

// address=[0x1d33280]
_BN_BLINDING_convert;

// address=[0x1d332b0]
_BN_BLINDING_convert_ex;

// address=[0x1d333c0]
_BN_BLINDING_create_param;

// address=[0x1d336e0]
_BN_BLINDING_free;

// address=[0x1d33780]
_BN_BLINDING_get_flags;

// address=[0x1d33790]
_BN_BLINDING_get_thread_id;

// address=[0x1d337a0]
_BN_BLINDING_invert;

// address=[0x1d337d0]
_BN_BLINDING_invert_ex;

// address=[0x1d33890]
_BN_BLINDING_new;

// address=[0x1d33a20]
_BN_BLINDING_set_flags;

// address=[0x1d33a40]
_BN_BLINDING_set_thread_id;

// address=[0x1d33a60]
_BN_BLINDING_thread_id;

// address=[0x1d33a70]
_BN_BLINDING_update;

// address=[0x1d35fa0]
_RSA_PKCS1_SSLeay;

// address=[0x1d362d0]
_ENGINE_get_RSA;

// address=[0x1d362e0]
_ENGINE_get_default_RSA;

// address=[0x1d36310]
_ENGINE_register_RSA;

// address=[0x1d36360]
_ENGINE_register_all_RSA;

// address=[0x1d363d0]
_ENGINE_set_RSA;

// address=[0x1d363f0]
_ENGINE_set_default_RSA;

// address=[0x1d36440]
_ENGINE_unregister_RSA;

// address=[0x1d37380]
_DSA_OpenSSL;

// address=[0x1d37390]
_ENGINE_get_DSA;

// address=[0x1d373a0]
_ENGINE_get_default_DSA;

// address=[0x1d373d0]
_ENGINE_register_DSA;

// address=[0x1d37420]
_ENGINE_register_all_DSA;

// address=[0x1d37490]
_ENGINE_set_DSA;

// address=[0x1d374b0]
_ENGINE_set_default_DSA;

// address=[0x1d37500]
_ENGINE_unregister_DSA;

// address=[0x1d37550]
_ENGINE_get_digest;

// address=[0x1d37630]
_ENGINE_get_digest_engine;

// address=[0x1d37660]
_ENGINE_get_digests;

// address=[0x1d37670]
_ENGINE_register_all_digests;

// address=[0x1d376e0]
_ENGINE_register_digests;

// address=[0x1d377c0]
_ENGINE_set_default_digests;

// address=[0x1d378a0]
_ENGINE_set_digests;

// address=[0x1d378c0]
_ENGINE_unregister_digests;

// address=[0x1d37910]
_ASN1_TYPE_get_int_octetstring;

// address=[0x1d37be0]
_ASN1_TYPE_get_octetstring;

// address=[0x1d37cb0]
_ASN1_TYPE_set_int_octetstring;

// address=[0x1d37ec0]
_ASN1_TYPE_set_octetstring;

// address=[0x1d37f60]
_SHA1_Final;

// address=[0x1d38450]
_SHA1_Init;

// address=[0x1d384c0]
_SHA1_Transform;

// address=[0x1d384f0]
_SHA1_Update;

// address=[0x1d3ba10]
_SHA384;

// address=[0x1d3bb10]
_SHA384_Final;

// address=[0x1d3bb40]
_SHA384_Init;

// address=[0x1d3bca0]
_SHA384_Update;

// address=[0x1d3bcd0]
_SHA512;

// address=[0x1d3bdd0]
_SHA512_Final;

// address=[0x1d3c3e0]
_SHA512_Init;

// address=[0x1d3c540]
_SHA512_Transform;

// address=[0x1d3c570]
_SHA512_Update;

// address=[0x1d3d6b0]
_BN_MONT_CTX_copy;

// address=[0x1d3d7b0]
_BN_MONT_CTX_free;

// address=[0x1d3d820]
_BN_MONT_CTX_init;

// address=[0x1d3d8b0]
_BN_MONT_CTX_new;

// address=[0x1d3d930]
_BN_MONT_CTX_set;

// address=[0x1d3dce0]
_BN_MONT_CTX_set_locked;

// address=[0x1d3de20]
_BN_from_montgomery;

// address=[0x1d3e420]
_BN_mod_mul_montgomery;

// address=[0x1d3ec80]
_ec_wNAF_have_precompute_mult;

// address=[0x1d3ecd0]
_ec_wNAF_mul;

// address=[0x1d3fd90]
_ec_wNAF_precompute_mult;

// address=[0x1d40530]
_BN_add;

// address=[0x1d40660]
_BN_sub;

// address=[0x1d40850]
_BN_uadd;

// address=[0x1d40a80]
_BN_usub;

// address=[0x1d40e80]
_BN_mul;

// address=[0x1d413a0]
_bn_add_part_words;

// address=[0x1d41be0]
_bn_mul_high;

// address=[0x1d42590]
_bn_mul_low_normal;

// address=[0x1d42720]
_bn_mul_low_recursive;

// address=[0x1d42980]
_bn_mul_normal;

// address=[0x1d42c10]
_bn_mul_part_recursive;

// address=[0x1d43410]
_bn_mul_recursive;

// address=[0x1d43b60]
_bn_sub_part_words;

// address=[0x1d44110]
_BN_gcd;

// address=[0x1d44280]
_BN_mod_inverse;

// address=[0x1d453e0]
_ENGINE_get_DH;

// address=[0x1d453f0]
_ENGINE_get_default_DH;

// address=[0x1d45420]
_ENGINE_register_DH;

// address=[0x1d45470]
_ENGINE_register_all_DH;

// address=[0x1d454e0]
_ENGINE_set_DH;

// address=[0x1d45500]
_ENGINE_set_default_DH;

// address=[0x1d45550]
_ENGINE_unregister_DH;

// address=[0x1d455a0]
_ENGINE_get_cipher;

// address=[0x1d45680]
_ENGINE_get_cipher_engine;

// address=[0x1d456b0]
_ENGINE_get_ciphers;

// address=[0x1d456c0]
_ENGINE_register_all_ciphers;

// address=[0x1d45730]
_ENGINE_register_ciphers;

// address=[0x1d45810]
_ENGINE_set_ciphers;

// address=[0x1d45830]
_ENGINE_set_default_ciphers;

// address=[0x1d45910]
_ENGINE_unregister_ciphers;

// address=[0x1d463f0]
_X509_LOOKUP_hash_dir;

// address=[0x1d467d0]
_SRP_VBASE_free;

// address=[0x1d46830]
_SRP_VBASE_get1_by_user;

// address=[0x1d46ac0]
_SRP_VBASE_get_by_user;

// address=[0x1d46af0]
_SRP_VBASE_init;

// address=[0x1d46fc0]
_SRP_VBASE_new;

// address=[0x1d47100]
_SRP_create_verifier;

// address=[0x1d475c0]
_SRP_create_verifier_BN;

// address=[0x1d47bb0]
_SRP_user_pwd_free;

// address=[0x1d48720]
_SRP_Calc_A;

// address=[0x1d487f0]
_SRP_Calc_B;

// address=[0x1d489b0]
_SRP_Calc_client_key;

// address=[0x1d48c30]
_SRP_Calc_server_key;

// address=[0x1d48da0]
_SRP_Calc_u;

// address=[0x1d49010]
_SRP_Calc_x;

// address=[0x1d49280]
_SRP_Verify_A_mod_N;

// address=[0x1d492b0]
_SRP_Verify_B_mod_N;

// address=[0x1d493a0]
_SRP_check_known_gN_param;

// address=[0x1d49460]
_SRP_get_default_gN;

// address=[0x1d49710]
_OPENSSL_DIR_end;

// address=[0x1d49790]
_OPENSSL_DIR_read;

// address=[0x1d49d10]
_ssl3_cbc_copy_mac;

// address=[0x1d4a170]
_ssl3_cbc_digest_record;

// address=[0x1d4b380]
_ssl3_cbc_record_digest_supported;

// address=[0x1d4b410]
_ssl3_cbc_remove_padding;

// address=[0x1d4b540]
_tls1_cbc_remove_padding;

// address=[0x1d4c850]
_tls1_alert_code;

// address=[0x1d4cb10]
_tls1_cert_verify_mac;

// address=[0x1d4ccf0]
_tls1_change_cipher_state;

// address=[0x1d4db50]
_tls1_enc;

// address=[0x1d4e430]
_tls1_export_keying_material;

// address=[0x1d4e7b0]
_tls1_final_finish_mac;

// address=[0x1d4ec20]
_tls1_generate_master_secret;

// address=[0x1d4ed60]
_tls1_mac;

// address=[0x1d4f320]
_tls1_setup_key_block;

// address=[0x1d4f700]
_HMAC;

// address=[0x1d4f850]
_HMAC_CTX_cleanup;

// address=[0x1d4f8b0]
_HMAC_CTX_copy;

// address=[0x1d4f970]
_HMAC_CTX_init;

// address=[0x1d4f9d0]
_HMAC_CTX_set_flags;

// address=[0x1d4fa30]
_HMAC_Final;

// address=[0x1d4fb70]
_HMAC_Init;

// address=[0x1d4fbc0]
_HMAC_Init_ex;

// address=[0x1d4ffb0]
_HMAC_Update;

// address=[0x1d4fff0]
_SSL_CTX_set_tlsext_use_srtp;

// address=[0x1d50020]
_SSL_get_selected_srtp_profile;

// address=[0x1d50040]
_SSL_get_srtp_profiles;

// address=[0x1d500b0]
_SSL_set_tlsext_use_srtp;

// address=[0x1d50180]
_ssl_add_clienthello_use_srtp_ext;

// address=[0x1d50370]
_ssl_add_serverhello_use_srtp_ext;

// address=[0x1d506c0]
_ssl_parse_clienthello_use_srtp_ext;

// address=[0x1d509a0]
_ssl_parse_serverhello_use_srtp_ext;

// address=[0x1d50c30]
_ssl_add_clienthello_renegotiate_ext;

// address=[0x1d50d00]
_ssl_add_serverhello_renegotiate_ext;

// address=[0x1d50e60]
_ssl_parse_clienthello_renegotiate_ext;

// address=[0x1d51000]
_ssl_parse_serverhello_renegotiate_ext;

// address=[0x1d512e0]
_ERR_load_CRYPTO_strings;

// address=[0x1d51340]
_ERR_load_BIO_strings;

// address=[0x1d513a0]
_ERR_load_BN_strings;

// address=[0x1d51400]
_ERR_load_ASN1_strings;

// address=[0x1d51460]
_ERR_load_EC_strings;

// address=[0x1d514c0]
_ERR_load_BUF_strings;

// address=[0x1d51520]
_ERR_load_COMP_strings;

// address=[0x1d51580]
_ERR_load_RSA_strings;

// address=[0x1d515e0]
_ERR_load_DH_strings;

// address=[0x1d51640]
_ERR_load_DSA_strings;

// address=[0x1d516a0]
_ERR_load_ECDSA_strings;

// address=[0x1d51700]
_ERR_load_ECDH_strings;

// address=[0x1d51760]
_ERR_load_OBJ_strings;

// address=[0x1d517c0]
_ERR_load_EVP_strings;

// address=[0x1d51820]
_ERR_load_PEM_strings;

// address=[0x1d51880]
_ERR_load_PKCS7_strings;

// address=[0x1d518e0]
_ERR_load_X509_strings;

// address=[0x1d51940]
_ERR_load_CONF_strings;

// address=[0x1d519a0]
_ERR_load_X509V3_strings;

// address=[0x1d51a00]
_ERR_load_PKCS12_strings;

// address=[0x1d51a60]
_ERR_load_RAND_strings;

// address=[0x1d51ac0]
_ERR_load_DSO_strings;

// address=[0x1d51b20]
_ERR_load_UI_strings;

// address=[0x1d51b80]
_ERR_load_ENGINE_strings;

// address=[0x1d51be0]
_ERR_load_OCSP_strings;

// address=[0x1d51c40]
_ERR_load_TS_strings;

// address=[0x1d51d10]
_SSLv23_method;

// address=[0x1d51d20]
_dtls1_buffer_message;

// address=[0x1d520a0]
_dtls1_do_write;

// address=[0x1d52930]
_dtls1_get_ccs_header;

// address=[0x1d52970]
_dtls1_get_message;

// address=[0x1d53300]
_dtls1_get_message_header;

// address=[0x1d53480]
_dtls1_get_queue_priority;

// address=[0x1d534a0]
_dtls1_heartbeat;

// address=[0x1d53810]
_dtls1_hm_fragment_free;

// address=[0x1d53a00]
_dtls1_link_min_mtu;

// address=[0x1d53a70]
_dtls1_min_mtu;

// address=[0x1d53cc0]
_dtls1_process_heartbeat;

// address=[0x1d54610]
_dtls1_read_failed;

// address=[0x1d54d50]
_dtls1_retransmit_buffered_messages;

// address=[0x1d54ea0]
_dtls1_retransmit_message;

// address=[0x1d55540]
_dtls1_send_change_cipher_spec;

// address=[0x1d556e0]
_dtls1_set_message_header;

// address=[0x1d55810]
_dtls1_shutdown;

// address=[0x1d55a60]
_ECDSA_do_verify;

// address=[0x1d55ae0]
_ECDSA_verify;

// address=[0x1d55c70]
_DES_cfb_encrypt;

// address=[0x1d568c0]
_DES_cfb64_encrypt;

// address=[0x1d56f90]
_DES_ofb64_encrypt;

// address=[0x1d575a0]
_DES_ecb3_encrypt;

// address=[0x1d578b0]
_DES_ede3_cfb64_encrypt;

// address=[0x1d57f90]
_DES_ede3_cfb_encrypt;

// address=[0x1d591b0]
_DES_ede3_ofb64_encrypt;

// address=[0x1d597a0]
_SHA1;

// address=[0x1d59890]
_RC4_set_key;

// address=[0x1d598c0]
_RC4;

// address=[0x1d5a320]
_idea_ecb_encrypt;

// address=[0x1d5a610]
_idea_options;

// address=[0x1d5a640]
_idea_set_decrypt_key;

// address=[0x1d5a8b0]
_idea_set_encrypt_key;

// address=[0x1d5af30]
_idea_cbc_encrypt;

// address=[0x1d5be60]
_idea_encrypt;

// address=[0x1d5d270]
_idea_cfb64_encrypt;

// address=[0x1d5d910]
_idea_ofb64_encrypt;

// address=[0x1d5df00]
_RC2_set_key;

// address=[0x1d5e150]
_RC2_ecb_encrypt;

// address=[0x1d5e450]
_RC2_cbc_encrypt;

// address=[0x1d5f380]
_RC2_decrypt;

// address=[0x1d5f6b0]
_RC2_encrypt;

// address=[0x1d5f990]
_RC2_cfb64_encrypt;

// address=[0x1d60030]
_RC2_ofb64_encrypt;

// address=[0x1d60620]
_AES_options;

// address=[0x1d60630]
_AES_set_decrypt_key;

// address=[0x1d60660]
_AES_set_encrypt_key;

// address=[0x1d60690]
_AES_decrypt;

// address=[0x1d60e70]
_AES_encrypt;

// address=[0x1d61690]
_private_AES_set_decrypt_key;

// address=[0x1d61be0]
_private_AES_set_encrypt_key;

// address=[0x1d625e0]
_AES_cbc_encrypt;

// address=[0x1d62650]
_CRYPTO_cbc128_decrypt;

// address=[0x1d62b00]
_CRYPTO_cbc128_encrypt;

// address=[0x1d62d70]
_CRYPTO_ctr128_encrypt;

// address=[0x1d63010]
_CRYPTO_ctr128_encrypt_ctr32;

// address=[0x1d635a0]
_CRYPTO_ofb128_encrypt;

// address=[0x1d63810]
_CRYPTO_cfb128_1_encrypt;

// address=[0x1d639d0]
_CRYPTO_cfb128_8_encrypt;

// address=[0x1d63a50]
_CRYPTO_cfb128_encrypt;

// address=[0x1d641f0]
_CRYPTO_gcm128_aad;

// address=[0x1d64450]
_CRYPTO_gcm128_decrypt;

// address=[0x1d64d00]
_CRYPTO_gcm128_decrypt_ctr32;

// address=[0x1d65350]
_CRYPTO_gcm128_encrypt;

// address=[0x1d65c10]
_CRYPTO_gcm128_encrypt_ctr32;

// address=[0x1d66260]
_CRYPTO_gcm128_finish;

// address=[0x1d666e0]
_CRYPTO_gcm128_init;

// address=[0x1d66a00]
_CRYPTO_gcm128_new;

// address=[0x1d66a70]
_CRYPTO_gcm128_release;

// address=[0x1d66ab0]
_CRYPTO_gcm128_setiv;

// address=[0x1d670e0]
_CRYPTO_gcm128_tag;

// address=[0x1d68630]
_CRYPTO_ccm128_aad;

// address=[0x1d68b60]
_CRYPTO_ccm128_decrypt;

// address=[0x1d69060]
_CRYPTO_ccm128_decrypt_ccm64;

// address=[0x1d69450]
_CRYPTO_ccm128_encrypt;

// address=[0x1d699e0]
_CRYPTO_ccm128_encrypt_ccm64;

// address=[0x1d69e60]
_CRYPTO_ccm128_init;

// address=[0x1d69ef0]
_CRYPTO_ccm128_setiv;

// address=[0x1d6a090]
_CRYPTO_ccm128_tag;

// address=[0x1d6a250]
_CRYPTO_xts128_encrypt;

// address=[0x1d6ac50]
_CRYPTO_128_unwrap;

// address=[0x1d6af60]
_CRYPTO_128_wrap;

// address=[0x1d713b0]
_NCONF_WIN32;

// address=[0x1d713c0]
_NCONF_default;

// address=[0x1d720a0]
__CONF_add_string;

// address=[0x1d72190]
__CONF_free_data;

// address=[0x1d72220]
__CONF_get_section;

// address=[0x1d722e0]
__CONF_get_section_values;

// address=[0x1d72340]
__CONF_get_string;

// address=[0x1d724b0]
__CONF_new_data;

// address=[0x1d72530]
__CONF_new_section;

// address=[0x1d72ac0]
_DSO_METHOD_openssl;

// address=[0x1d72ae0]
_ENGINE_add;

// address=[0x1d72bf0]
_ENGINE_by_id;

// address=[0x1d72eb0]
_ENGINE_get_first;

// address=[0x1d72f40]
_ENGINE_get_last;

// address=[0x1d72fd0]
_ENGINE_get_next;

// address=[0x1d730a0]
_ENGINE_get_prev;

// address=[0x1d73170]
_ENGINE_remove;

// address=[0x1d73250]
_ENGINE_up_ref;

// address=[0x1d73790]
_ENGINE_get_table_flags;

// address=[0x1d737a0]
_ENGINE_set_table_flags;

// address=[0x1d73890]
_engine_table_cleanup;

// address=[0x1d73920]
_engine_table_doall;

// address=[0x1d739c0]
_engine_table_register;

// address=[0x1d73c80]
_engine_table_select;

// address=[0x1d73ef0]
_engine_table_unregister;

// address=[0x1d74250]
_bn_add_words;

// address=[0x1d74520]
_bn_div_words;

// address=[0x1d74560]
_bn_mul_add_words;

// address=[0x1d74810]
_bn_mul_comba4;

// address=[0x1d75290]
_bn_mul_comba8;

// address=[0x1d77f80]
_bn_mul_mont;

// address=[0x1d77f90]
_bn_mul_words;

// address=[0x1d781d0]
_bn_sqr_comba4;

// address=[0x1d78af0]
_bn_sqr_comba8;

// address=[0x1d7b150]
_bn_sqr_words;

// address=[0x1d7b3e0]
_bn_sub_words;

// address=[0x1d7b710]
_d2i_ASN1_BOOLEAN;

// address=[0x1d7b8a0]
_i2d_ASN1_BOOLEAN;

// address=[0x1d7bb60]
_EVP_desx_cbc;

// address=[0x1d7c280]
_EVP_rc4_hmac_md5;

// address=[0x1d7c5f0]
_EVP_bf_cbc;

// address=[0x1d7c600]
_EVP_bf_cfb64;

// address=[0x1d7c610]
_EVP_bf_ecb;

// address=[0x1d7c620]
_EVP_bf_ofb;

// address=[0x1d7c990]
_EVP_cast5_cbc;

// address=[0x1d7c9a0]
_EVP_cast5_cfb64;

// address=[0x1d7c9b0]
_EVP_cast5_ecb;

// address=[0x1d7c9c0]
_EVP_cast5_ofb;

// address=[0x1d7ca60]
_EVP_md4;

// address=[0x1d7cb00]
_EVP_sha;

// address=[0x1d7cba0]
_EVP_dss;

// address=[0x1d7cc40]
_EVP_mdc2;

// address=[0x1d7cce0]
_EVP_ripemd160;

// address=[0x1d7cd80]
_EVP_whirlpool;

// address=[0x1d7cd90]
_X509_PKEY_free;

// address=[0x1d7ce90]
_X509_PKEY_new;

// address=[0x1d7d020]
_d2i_X509_PKEY;

// address=[0x1d7d360]
_i2d_X509_PKEY;

// address=[0x1d7d3e0]
_DHvparams_it;

// address=[0x1d7d3f0]
_DHparams_it;

// address=[0x1d7d400]
_DHxparams_it;

// address=[0x1d7d410]
_d2i_DHparams;

// address=[0x1d7d440]
_d2i_DHxparams;

// address=[0x1d7d5f0]
_d2i_int_dhx;

// address=[0x1d7d620]
_i2d_DHparams;

// address=[0x1d7d650]
_i2d_DHxparams;

// address=[0x1d7d790]
_i2d_int_dhx;

// address=[0x1d7d820]
_NETSCAPE_CERT_SEQUENCE_free;

// address=[0x1d7d850]
_NETSCAPE_CERT_SEQUENCE_it;

// address=[0x1d7d860]
_NETSCAPE_CERT_SEQUENCE_new;

// address=[0x1d7d880]
_d2i_NETSCAPE_CERT_SEQUENCE;

// address=[0x1d7d8b0]
_i2d_NETSCAPE_CERT_SEQUENCE;

// address=[0x1d7d9a0]
_X509V3_EXT_CRL_add_conf;

// address=[0x1d7da50]
_X509V3_EXT_CRL_add_nconf;

// address=[0x1d7dac0]
_X509V3_EXT_REQ_add_conf;

// address=[0x1d7db70]
_X509V3_EXT_REQ_add_nconf;

// address=[0x1d7dc70]
_X509V3_EXT_add_conf;

// address=[0x1d7dd20]
_X509V3_EXT_add_nconf;

// address=[0x1d7dd90]
_X509V3_EXT_add_nconf_sk;

// address=[0x1d7dea0]
_X509V3_EXT_conf;

// address=[0x1d7df50]
_X509V3_EXT_conf_nid;

// address=[0x1d7e000]
_X509V3_EXT_i2d;

// address=[0x1d7e090]
_X509V3_EXT_nconf;

// address=[0x1d7e1a0]
_X509V3_EXT_nconf_nid;

// address=[0x1d7e260]
_X509V3_get_section;

// address=[0x1d7e300]
_X509V3_get_string;

// address=[0x1d7e3b0]
_X509V3_section_free;

// address=[0x1d7e410]
_X509V3_set_conf_lhash;

// address=[0x1d7e430]
_X509V3_set_ctx;

// address=[0x1d7e470]
_X509V3_set_nconf;

// address=[0x1d7e490]
_X509V3_string_free;

// address=[0x1d7f4b0]
_CERTIFICATEPOLICIES_it;

// address=[0x1d7f4c0]
_POLICYINFO_it;

// address=[0x1d7f4d0]
_POLICYQUALINFO_it;

// address=[0x1d7f4e0]
_USERNOTICE_it;

// address=[0x1d7f4f0]
_NOTICEREF_it;

// address=[0x1d7f500]
_CERTIFICATEPOLICIES_free;

// address=[0x1d7f530]
_CERTIFICATEPOLICIES_new;

// address=[0x1d7f550]
_NOTICEREF_free;

// address=[0x1d7f580]
_NOTICEREF_new;

// address=[0x1d7f5a0]
_POLICYINFO_free;

// address=[0x1d7f5d0]
_POLICYINFO_new;

// address=[0x1d7f5f0]
_POLICYQUALINFO_free;

// address=[0x1d7f620]
_POLICYQUALINFO_new;

// address=[0x1d7f640]
_USERNOTICE_free;

// address=[0x1d7f670]
_USERNOTICE_new;

// address=[0x1d7f690]
_X509_POLICY_NODE_print;

// address=[0x1d7f7c0]
_d2i_CERTIFICATEPOLICIES;

// address=[0x1d7f7f0]
_d2i_NOTICEREF;

// address=[0x1d7f820]
_d2i_POLICYINFO;

// address=[0x1d7f850]
_d2i_POLICYQUALINFO;

// address=[0x1d7f880]
_d2i_USERNOTICE;

// address=[0x1d7f8b0]
_i2d_CERTIFICATEPOLICIES;

// address=[0x1d7f8e0]
_i2d_NOTICEREF;

// address=[0x1d7f910]
_i2d_POLICYINFO;

// address=[0x1d7f940]
_i2d_POLICYQUALINFO;

// address=[0x1d7f970]
_i2d_USERNOTICE;

// address=[0x1d807d0]
_POLICY_CONSTRAINTS_it;

// address=[0x1d80a50]
_POLICY_CONSTRAINTS_free;

// address=[0x1d80a80]
_POLICY_CONSTRAINTS_new;

// address=[0x1d80aa0]
_policy_cache_set_mapping;

// address=[0x1d80d00]
_v2i_ASN1_BIT_STRING;

// address=[0x1d80f00]
_i2v_ASN1_BIT_STRING;

// address=[0x1d81230]
_EXTENDED_KEY_USAGE_it;

// address=[0x1d81240]
_EXTENDED_KEY_USAGE_free;

// address=[0x1d81270]
_EXTENDED_KEY_USAGE_new;

// address=[0x1d81290]
_d2i_EXTENDED_KEY_USAGE;

// address=[0x1d812c0]
_i2d_EXTENDED_KEY_USAGE;

// address=[0x1d813c0]
_PKEY_USAGE_PERIOD_it;

// address=[0x1d813d0]
_PKEY_USAGE_PERIOD_free;

// address=[0x1d81400]
_PKEY_USAGE_PERIOD_new;

// address=[0x1d81420]
_d2i_PKEY_USAGE_PERIOD;

// address=[0x1d81450]
_i2d_PKEY_USAGE_PERIOD;

// address=[0x1d81480]
_SXNET_it;

// address=[0x1d81490]
_SXNETID_it;

// address=[0x1d816d0]
_SXNETID_free;

// address=[0x1d81700]
_SXNETID_new;

// address=[0x1d81720]
_SXNET_add_id_INTEGER;

// address=[0x1d81960]
_SXNET_add_id_asc;

// address=[0x1d81a00]
_SXNET_add_id_ulong;

// address=[0x1d81ac0]
_SXNET_free;

// address=[0x1d81af0]
_SXNET_get_id_INTEGER;

// address=[0x1d81ba0]
_SXNET_get_id_asc;

// address=[0x1d81c50]
_SXNET_get_id_ulong;

// address=[0x1d81d20]
_SXNET_new;

// address=[0x1d81d40]
_d2i_SXNET;

// address=[0x1d81d70]
_d2i_SXNETID;

// address=[0x1d81da0]
_i2d_SXNET;

// address=[0x1d81dd0]
_i2d_SXNETID;

// address=[0x1d821f0]
_i2s_ASN1_OCTET_STRING;

// address=[0x1d82220]
_s2i_ASN1_OCTET_STRING;

// address=[0x1d82880]
_i2s_ASN1_ENUMERATED_TABLE;

// address=[0x1d83fd0]
_POLICY_MAPPING_it;

// address=[0x1d83fe0]
_POLICY_MAPPINGS_it;

// address=[0x1d843e0]
_POLICY_MAPPING_free;

// address=[0x1d84410]
_POLICY_MAPPING_new;

// address=[0x1d85030]
_EVP_BytesToKey;

// address=[0x1d854a0]
_EVP_get_pw_prompt;

// address=[0x1d854d0]
_EVP_read_pw_string;

// address=[0x1d85500]
_EVP_read_pw_string_min;

// address=[0x1d856f0]
_EVP_set_pw_prompt;

// address=[0x1d857a0]
_EVP_DecodeBlock;

// address=[0x1d85a50]
_EVP_DecodeFinal;

// address=[0x1d85af0]
_EVP_DecodeInit;

// address=[0x1d85b30]
_EVP_DecodeUpdate;

// address=[0x1d85e90]
_EVP_EncodeBlock;

// address=[0x1d860d0]
_EVP_EncodeFinal;

// address=[0x1d86170]
_EVP_EncodeInit;

// address=[0x1d861a0]
_EVP_EncodeUpdate;

// address=[0x1d86460]
_BIO_accept;

// address=[0x1d868f0]
_BIO_get_accept_socket;

// address=[0x1d87200]
_BIO_get_host_ip;

// address=[0x1d873e0]
_BIO_get_port;

// address=[0x1d876a0]
_BIO_gethostbyname;

// address=[0x1d876d0]
_BIO_set_tcp_ndelay;

// address=[0x1d87720]
_BIO_sock_cleanup;

// address=[0x1d87760]
_BIO_sock_error;

// address=[0x1d87850]
_BIO_sock_init;

// address=[0x1d87940]
_BIO_socket_ioctl;

// address=[0x1d879d0]
_BIO_socket_nbio;

// address=[0x1d87f30]
_BIGNUM_it;

// address=[0x1d87f40]
_CBIGNUM_it;

// address=[0x1d883f0]
_LONG_it;

// address=[0x1d88400]
_ZLONG_it;

// address=[0x1d88410]
_PKCS8_decrypt;

// address=[0x1d88450]
_PEM_read_PKCS8;

// address=[0x1d88490]
_PEM_read_PKCS8_PRIV_KEY_INFO;

// address=[0x1d884d0]
_PEM_read_bio_PKCS8;

// address=[0x1d88510]
_PEM_read_bio_PKCS8_PRIV_KEY_INFO;

// address=[0x1d88550]
_PEM_write_PKCS8;

// address=[0x1d88590]
_PEM_write_PKCS8PrivateKey;

// address=[0x1d885e0]
_PEM_write_PKCS8PrivateKey_nid;

// address=[0x1d88630]
_PEM_write_PKCS8_PRIV_KEY_INFO;

// address=[0x1d88670]
_PEM_write_bio_PKCS8;

// address=[0x1d886b0]
_PEM_write_bio_PKCS8PrivateKey;

// address=[0x1d88700]
_PEM_write_bio_PKCS8PrivateKey_nid;

// address=[0x1d88750]
_PEM_write_bio_PKCS8_PRIV_KEY_INFO;

// address=[0x1d88790]
_d2i_PKCS8PrivateKey_bio;

// address=[0x1d889b0]
_d2i_PKCS8PrivateKey_fp;

// address=[0x1d88de0]
_i2d_PKCS8PrivateKey_bio;

// address=[0x1d88e30]
_i2d_PKCS8PrivateKey_fp;

// address=[0x1d88e80]
_i2d_PKCS8PrivateKey_nid_bio;

// address=[0x1d88ed0]
_i2d_PKCS8PrivateKey_nid_fp;

// address=[0x1d88f20]
_ASN1_bn_print;

// address=[0x1d89250]
_BN_exp;

// address=[0x1d894a0]
_BN_mod_exp;

// address=[0x1d895e0]
_BN_mod_exp_mont;

// address=[0x1d89f70]
_BN_mod_exp_mont_consttime;

// address=[0x1d8a870]
_BN_mod_exp_mont_word;

// address=[0x1d8aeb0]
_BN_mod_exp_recp;

// address=[0x1d8b5a0]
_BN_mod_exp_simple;

// address=[0x1d8c070]
_DH_check;

// address=[0x1d8c4f0]
_DH_check_pub_key;

// address=[0x1d8c6f0]
_DSA_SIG_free;

// address=[0x1d8c750]
_DSA_SIG_new;

// address=[0x1d8c7c0]
_DSA_do_sign;

// address=[0x1d8c800]
_DSA_sign_setup;

// address=[0x1d8c850]
_DSA_do_verify;

// address=[0x1d91d70]
_EC_GROUP_new_curve_GF2m;

// address=[0x1d91e10]
_EC_GROUP_new_curve_GFp;

// address=[0x1d91f80]
_ec_GFp_simple_oct2point;

// address=[0x1d92400]
_ec_GFp_simple_point2oct;

// address=[0x1d928d0]
_ec_GFp_simple_set_compressed_coordinates;

// address=[0x1d92fb0]
_ec_GF2m_simple_oct2point;

// address=[0x1d934b0]
_ec_GF2m_simple_point2oct;

// address=[0x1d939e0]
_ec_GF2m_simple_set_compressed_coordinates;

// address=[0x1d93de0]
_ECDSA_SIG_free;

// address=[0x1d93e10]
_ECDSA_SIG_it;

// address=[0x1d93e20]
_ECDSA_SIG_new;

// address=[0x1d93e40]
_d2i_ECDSA_SIG;

// address=[0x1d93e70]
_i2d_ECDSA_SIG;

// address=[0x1d94000]
_ECDSA_METHOD_free;

// address=[0x1d94030]
_ECDSA_METHOD_get_app_data;

// address=[0x1d94040]
_ECDSA_METHOD_new;

// address=[0x1d94150]
_ECDSA_METHOD_set_app_data;

// address=[0x1d94170]
_ECDSA_METHOD_set_flags;

// address=[0x1d94190]
_ECDSA_METHOD_set_name;

// address=[0x1d941a0]
_ECDSA_METHOD_set_sign;

// address=[0x1d941c0]
_ECDSA_METHOD_set_sign_setup;

// address=[0x1d941e0]
_ECDSA_METHOD_set_verify;

// address=[0x1d94200]
_ECDSA_get_default_method;

// address=[0x1d94230]
_ECDSA_get_ex_data;

// address=[0x1d942a0]
_ECDSA_get_ex_new_index;

// address=[0x1d942e0]
_ECDSA_set_default_method;

// address=[0x1d942f0]
_ECDSA_set_ex_data;

// address=[0x1d94360]
_ECDSA_set_method;

// address=[0x1d943f0]
_ECDSA_size;

// address=[0x1d94590]
_ecdsa_check;

// address=[0x1d94900]
_ECDH_get_default_method;

// address=[0x1d94930]
_ECDH_get_ex_data;

// address=[0x1d949a0]
_ECDH_get_ex_new_index;

// address=[0x1d949e0]
_ECDH_set_default_method;

// address=[0x1d949f0]
_ECDH_set_ex_data;

// address=[0x1d94a60]
_ECDH_set_method;

// address=[0x1d94af0]
_ecdh_check;

// address=[0x1d94d00]
_do_dtls1_write;

// address=[0x1d95740]
_dtls1_dispatch_alert;

// address=[0x1d95ab0]
_dtls1_get_record;

// address=[0x1d967f0]
_dtls1_read_bytes;

// address=[0x1d97d50]
_dtls1_reset_seq_numbers;

// address=[0x1d97f30]
_dtls1_write_app_data_bytes;

// address=[0x1d98040]
_dtls1_write_bytes;

// address=[0x1d985a0]
_dtls1_check_timeout_num;

// address=[0x1d986b0]
_dtls1_clear;

// address=[0x1d98ab0]
_dtls1_clear_received_buffer;

// address=[0x1d98b50]
_dtls1_clear_sent_buffer;

// address=[0x1d98bf0]
_dtls1_ctrl;

// address=[0x1d98ec0]
_dtls1_default_timeout;

// address=[0x1d98ed0]
_dtls1_double_timeout;

// address=[0x1d98f40]
_dtls1_free;

// address=[0x1d99010]
_dtls1_get_cipher;

// address=[0x1d99070]
_dtls1_get_timeout;

// address=[0x1d99230]
_dtls1_handle_timeout;

// address=[0x1d99320]
_dtls1_is_timer_expired;

// address=[0x1d993d0]
_dtls1_listen;

// address=[0x1d99490]
_dtls1_new;

// address=[0x1d99710]
_dtls1_start_timer;

// address=[0x1d997e0]
_dtls1_stop_timer;

// address=[0x1d999d0]
_RAND_poll;

// address=[0x1d99dd0]
_ENGINE_cmd_is_executable;

// address=[0x1d99e80]
_ENGINE_ctrl;

// address=[0x1d9a0a0]
_ENGINE_ctrl_cmd;

// address=[0x1d9a1b0]
_ENGINE_ctrl_cmd_string;

// address=[0x1d9aa80]
_ENGINE_register_all_complete;

// address=[0x1d9ab00]
_ENGINE_register_complete;

// address=[0x1d9abb0]
_ENGINE_set_default;

// address=[0x1d9ad40]
_ENGINE_set_default_string;

// address=[0x1d9b1e0]
_d2i_ASN1_SET;

// address=[0x1d9b540]
_i2d_ASN1_SET;

// address=[0x1d9b980]
_EVP_DigestSignFinal;

// address=[0x1d9bd00]
_EVP_DigestSignInit;

// address=[0x1d9bd40]
_EVP_DigestVerifyFinal;

// address=[0x1d9bf30]
_EVP_DigestVerifyInit;

// address=[0x1d9c240]
_ASN1_generate_nconf;

// address=[0x1d9c310]
_ASN1_generate_v3;

// address=[0x1d9dfb0]
_PBEPARAM_free;

// address=[0x1d9dfe0]
_PBEPARAM_it;

// address=[0x1d9dff0]
_PBEPARAM_new;

// address=[0x1d9e010]
_PKCS5_pbe_set;

// address=[0x1d9e0c0]
_PKCS5_pbe_set0_algor;

// address=[0x1d9e340]
_d2i_PBEPARAM;

// address=[0x1d9e370]
_i2d_PBEPARAM;

// address=[0x1d9e3a0]
_PBE2PARAM_free;

// address=[0x1d9e3d0]
_PBE2PARAM_it;

// address=[0x1d9e3e0]
_PBE2PARAM_new;

// address=[0x1d9e400]
_PBKDF2PARAM_free;

// address=[0x1d9e430]
_PBKDF2PARAM_it;

// address=[0x1d9e440]
_PBKDF2PARAM_new;

// address=[0x1d9e460]
_PKCS5_pbe2_set;

// address=[0x1d9e4a0]
_PKCS5_pbe2_set_iv;

// address=[0x1d9e8f0]
_PKCS5_pbkdf2_set;

// address=[0x1d9ebf0]
_d2i_PBE2PARAM;

// address=[0x1d9ec20]
_d2i_PBKDF2PARAM;

// address=[0x1d9ec50]
_i2d_PBE2PARAM;

// address=[0x1d9ec80]
_i2d_PBKDF2PARAM;

// address=[0x1d9ecb0]
_PKCS12_key_gen_asc;

// address=[0x1d9ee20]
_PKCS12_key_gen_uni;

// address=[0x1d9f4a0]
_ASN1_PCTX_free;

// address=[0x1d9f4c0]
_ASN1_PCTX_get_cert_flags;

// address=[0x1d9f4d0]
_ASN1_PCTX_get_flags;

// address=[0x1d9f4e0]
_ASN1_PCTX_get_nm_flags;

// address=[0x1d9f4f0]
_ASN1_PCTX_get_oid_flags;

// address=[0x1d9f500]
_ASN1_PCTX_get_str_flags;

// address=[0x1d9f510]
_ASN1_PCTX_new;

// address=[0x1d9f5c0]
_ASN1_PCTX_set_cert_flags;

// address=[0x1d9f5e0]
_ASN1_PCTX_set_flags;

// address=[0x1d9f5f0]
_ASN1_PCTX_set_nm_flags;

// address=[0x1d9f610]
_ASN1_PCTX_set_oid_flags;

// address=[0x1d9f630]
_ASN1_PCTX_set_str_flags;

// address=[0x1d9f650]
_ASN1_item_print;

// address=[0x1da0600]
_asn1_template_print_ctx;

// address=[0x1da0920]
_PKCS7_SIGNER_INFO_sign;

// address=[0x1da0c40]
_PKCS7_add_attribute;

// address=[0x1da0c70]
_PKCS7_add_signed_attribute;

// address=[0x1da0e00]
_PKCS7_dataDecode;

// address=[0x1da1850]
_PKCS7_dataFinal;

// address=[0x1da2020]
_PKCS7_dataInit;

// address=[0x1da27b0]
_PKCS7_dataVerify;

// address=[0x1da2a00]
_PKCS7_digest_from_attributes;

// address=[0x1da2b40]
_PKCS7_get_attribute;

// address=[0x1da2b70]
_PKCS7_get_issuer_and_serial;

// address=[0x1da2cb0]
_PKCS7_get_signed_attribute;

// address=[0x1da2ce0]
_PKCS7_set_attributes;

// address=[0x1da2dd0]
_PKCS7_set_signed_attributes;

// address=[0x1da2ec0]
_PKCS7_signatureVerify;

// address=[0x1da3e90]
_PKCS7_RECIP_INFO_get0_alg;

// address=[0x1da3eb0]
_PKCS7_RECIP_INFO_set;

// address=[0x1da40f0]
_PKCS7_SIGNER_INFO_get0_algs;

// address=[0x1da4140]
_PKCS7_SIGNER_INFO_set;

// address=[0x1da4330]
_PKCS7_add_certificate;

// address=[0x1da4480]
_PKCS7_add_crl;

// address=[0x1da45d0]
_PKCS7_add_recipient;

// address=[0x1da4670]
_PKCS7_add_recipient_info;

// address=[0x1da4750]
_PKCS7_add_signature;

// address=[0x1da48c0]
_PKCS7_add_signer;

// address=[0x1da4b10]
_PKCS7_cert_from_signer_info;

// address=[0x1da4b70]
_PKCS7_content_new;

// address=[0x1da4c10]
_PKCS7_ctrl;

// address=[0x1da4dc0]
_PKCS7_get_signer_info;

// address=[0x1da4e40]
_PKCS7_set0_type_other;

// address=[0x1da4e80]
_PKCS7_set_cipher;

// address=[0x1da4f90]
_PKCS7_set_content;

// address=[0x1da5090]
_PKCS7_set_digest;

// address=[0x1da5190]
_PKCS7_set_type;

// address=[0x1da54d0]
_PKCS7_stream;

// address=[0x1da5640]
_X509_ATTRIBUTE_count;

// address=[0x1da5690]
_X509_ATTRIBUTE_create_by_NID;

// address=[0x1da5750]
_X509_ATTRIBUTE_create_by_OBJ;

// address=[0x1da5860]
_X509_ATTRIBUTE_create_by_txt;

// address=[0x1da5930]
_X509_ATTRIBUTE_get0_data;

// address=[0x1da59d0]
_X509_ATTRIBUTE_get0_object;

// address=[0x1da59f0]
_X509_ATTRIBUTE_get0_type;

// address=[0x1da5a60]
_X509_ATTRIBUTE_set1_data;

// address=[0x1da5cc0]
_X509_ATTRIBUTE_set1_object;

// address=[0x1da5d10]
_X509at_add1_attr;

// address=[0x1da5e50]
_X509at_add1_attr_by_NID;

// address=[0x1da5ee0]
_X509at_add1_attr_by_OBJ;

// address=[0x1da5f70]
_X509at_add1_attr_by_txt;

// address=[0x1da6000]
_X509at_delete_attr;

// address=[0x1da6070]
_X509at_get0_data_by_OBJ;

// address=[0x1da6150]
_X509at_get_attr;

// address=[0x1da61a0]
_X509at_get_attr_by_NID;

// address=[0x1da6210]
_X509at_get_attr_by_OBJ;

// address=[0x1da62e0]
_X509at_get_attr_count;

// address=[0x1da6300]
_X509_REQ_set_pubkey;

// address=[0x1da6340]
_X509_REQ_set_subject_name;

// address=[0x1da6380]
_X509_REQ_set_version;

// address=[0x1da63c0]
_BN_mod_add;

// address=[0x1da6410]
_BN_mod_add_quick;

// address=[0x1da6480]
_BN_mod_lshift;

// address=[0x1da6580]
_BN_mod_lshift1;

// address=[0x1da65d0]
_BN_mod_lshift1_quick;

// address=[0x1da6640]
_BN_mod_lshift_quick;

// address=[0x1da67b0]
_BN_mod_mul;

// address=[0x1da68b0]
_BN_mod_sqr;

// address=[0x1da6910]
_BN_mod_sub;

// address=[0x1da6960]
_BN_mod_sub_quick;

// address=[0x1da69c0]
_BN_nnmod;

// address=[0x1da6a70]
_BN_div;

// address=[0x1da7480]
_RSA_padding_add_PKCS1_type_1;

// address=[0x1da7580]
_RSA_padding_add_PKCS1_type_2;

// address=[0x1da76e0]
_RSA_padding_check_PKCS1_type_1;

// address=[0x1da78d0]
_RSA_padding_check_PKCS1_type_2;

// address=[0x1da7bd0]
_PKCS1_MGF1;

// address=[0x1da7e80]
_RSA_padding_add_PKCS1_OAEP;

// address=[0x1da7ec0]
_RSA_padding_add_PKCS1_OAEP_mgf1;

// address=[0x1da8250]
_RSA_padding_check_PKCS1_OAEP;

// address=[0x1da82a0]
_RSA_padding_check_PKCS1_OAEP_mgf1;

// address=[0x1da8940]
_RSA_padding_add_SSLv23;

// address=[0x1da8ac0]
_RSA_padding_check_SSLv23;

// address=[0x1da8d10]
_RSA_padding_add_none;

// address=[0x1da8d90]
_RSA_padding_check_none;

// address=[0x1da8e10]
_RSA_X931_hash_id;

// address=[0x1da8ea0]
_RSA_padding_add_X931;

// address=[0x1da8fc0]
_RSA_padding_check_X931;

// address=[0x1da91e0]
_BN_mod_exp2_mont;

// address=[0x1daa000]
_d2i_ASN1_bytes;

// address=[0x1daa0e0]
_d2i_ASN1_type_bytes;

// address=[0x1daa3a0]
_i2d_ASN1_bytes;

// address=[0x1daa880]
_BN_sqr;

// address=[0x1daac60]
_bn_sqr_normal;

// address=[0x1daae20]
_bn_sqr_recursive;

// address=[0x1dab130]
_TXT_DB_create_index;

// address=[0x1dab350]
_TXT_DB_free;

// address=[0x1dab5b0]
_TXT_DB_get_by_index;

// address=[0x1dab660]
_TXT_DB_insert;

// address=[0x1dab920]
_TXT_DB_read;

// address=[0x1dabf40]
_TXT_DB_write;

// address=[0x1dac1c0]
_EVP_PKEY_CTX_get_cb;

// address=[0x1dac1d0]
_EVP_PKEY_CTX_get_keygen_info;

// address=[0x1dac220]
_EVP_PKEY_CTX_set_cb;

// address=[0x1dac240]
_EVP_PKEY_keygen;

// address=[0x1dac380]
_EVP_PKEY_keygen_init;

// address=[0x1dac460]
_EVP_PKEY_new_mac_key;

// address=[0x1dac580]
_EVP_PKEY_paramgen;

// address=[0x1dac6e0]
_EVP_PKEY_paramgen_init;

// address=[0x1dac7c0]
_evp_pkey_set_cb_translate;

// address=[0x1dac910]
_ssl23_accept;

// address=[0x1dacd10]
_SSLv23_server_method;

// address=[0x1dacd20]
_ssl23_get_client_hello;

// address=[0x1dadd40]
_SSLv3_method;

// address=[0x1dadda0]
_TLSv1_1_method;

// address=[0x1daddb0]
_TLSv1_2_method;

// address=[0x1daddc0]
_TLSv1_method;

// address=[0x1daddd0]
_pitem_free;

// address=[0x1dade00]
_pitem_new;

// address=[0x1dade90]
_pqueue_find;

// address=[0x1dadf60]
_pqueue_free;

// address=[0x1dadf90]
_pqueue_insert;

// address=[0x1dae0a0]
_pqueue_iterator;

// address=[0x1dae0c0]
_pqueue_new;

// address=[0x1dae130]
_pqueue_next;

// address=[0x1dae190]
_pqueue_peek;

// address=[0x1dae1a0]
_pqueue_pop;

// address=[0x1dae1f0]
_pqueue_print;

// address=[0x1dae300]
_pqueue_size;

// address=[0x1dae360]
_RC4_options;

// address=[0x1dae380]
_private_RC4_set_key;

// address=[0x1dae620]
_EC_POINT_bn2point;

// address=[0x1dae7a0]
_EC_POINT_hex2point;

// address=[0x1dae880]
_EC_POINT_point2bn;

// address=[0x1dae990]
_EC_POINT_point2hex;

// address=[0x1daeb70]
_ECPKParameters_print;

// address=[0x1daf4d0]
_ECPKParameters_print_fp;

// address=[0x1daf590]
_ECParameters_print;

// address=[0x1daf630]
_ECParameters_print_fp;

// address=[0x1daf6f0]
_EC_KEY_print;

// address=[0x1daf790]
_EC_KEY_print_fp;

// address=[0x1dafac0]
_CMAC_CTX_cleanup;

// address=[0x1dafb60]
_CMAC_CTX_copy;

// address=[0x1dafc90]
_CMAC_CTX_free;

// address=[0x1dafcd0]
_CMAC_CTX_get0_cipher_ctx;

// address=[0x1dafce0]
_CMAC_CTX_new;

// address=[0x1dafd60]
_CMAC_Final;

// address=[0x1daff30]
_CMAC_Init;

// address=[0x1db01c0]
_CMAC_Update;

// address=[0x1db03b0]
_CMAC_resume;

// address=[0x1db17b0]
_DSO_METHOD_win32;

// address=[0x1db2180]
_DES_xcbc_encrypt;

// address=[0x1db3310]
_BF_set_key;

// address=[0x1db35f0]
_BF_ecb_encrypt;

// address=[0x1db38f0]
_BF_options;

// address=[0x1db3900]
_BF_cbc_encrypt;

// address=[0x1db4820]
_BF_decrypt;

// address=[0x1db5130]
_BF_encrypt;

// address=[0x1db5a40]
_BF_cfb64_encrypt;

// address=[0x1db60e0]
_BF_ofb64_encrypt;

// address=[0x1db66d0]
_CAST_set_key;

// address=[0x1db87b0]
_CAST_ecb_encrypt;

// address=[0x1db8ab0]
_CAST_cbc_encrypt;

// address=[0x1db99d0]
_CAST_decrypt;

// address=[0x1dba770]
_CAST_encrypt;

// address=[0x1dbb520]
_CAST_cfb64_encrypt;

// address=[0x1dbbbc0]
_CAST_ofb64_encrypt;

// address=[0x1dbc1b0]
_SHA_Final;

// address=[0x1dbc6a0]
_SHA_Init;

// address=[0x1dbc710]
_SHA_Transform;

// address=[0x1dbc740]
_SHA_Update;

// address=[0x1dbf710]
_RSA_sign_ASN1_OCTET_STRING;

// address=[0x1dbf8e0]
_RSA_verify_ASN1_OCTET_STRING;

// address=[0x1dbfae0]
_MDC2_Final;

// address=[0x1dbfbe0]
_MDC2_Init;

// address=[0x1dbfc60]
_MDC2_Update;

// address=[0x1dc0420]
_RIPEMD160_Final;

// address=[0x1dc0910]
_RIPEMD160_Init;

// address=[0x1dc0980]
_RIPEMD160_Transform;

// address=[0x1dc09b0]
_RIPEMD160_Update;

// address=[0x1dc0be0]
_ripemd160_block_data_order;

// address=[0x1dc45c0]
_WHIRLPOOL;

// address=[0x1dc46b0]
_WHIRLPOOL_BitUpdate;

// address=[0x1dc4c90]
_WHIRLPOOL_Final;

// address=[0x1dc4ec0]
_WHIRLPOOL_Init;

// address=[0x1dc4ef0]
_WHIRLPOOL_Update;

// address=[0x1dc4fa0]
_UI_add_error_string;

// address=[0x1dc4fe0]
_UI_add_info_string;

// address=[0x1dc5020]
_UI_add_input_boolean;

// address=[0x1dc5070]
_UI_add_input_string;

// address=[0x1dc50b0]
_UI_add_user_data;

// address=[0x1dc50f0]
_UI_add_verify_string;

// address=[0x1dc5140]
_UI_construct_prompt;

// address=[0x1dc53c0]
_UI_create_method;

// address=[0x1dc5440]
_UI_ctrl;

// address=[0x1dc5580]
_UI_destroy_method;

// address=[0x1dc55c0]
_UI_dup_error_string;

// address=[0x1dc5660]
_UI_dup_info_string;

// address=[0x1dc5700]
_UI_dup_input_boolean;

// address=[0x1dc5900]
_UI_dup_input_string;

// address=[0x1dc59b0]
_UI_dup_verify_string;

// address=[0x1dc5a60]
_UI_free;

// address=[0x1dc5ac0]
_UI_get0_action_string;

// address=[0x1dc5b10]
_UI_get0_output_string;

// address=[0x1dc5b30]
_UI_get0_result;

// address=[0x1dc5bd0]
_UI_get0_result_string;

// address=[0x1dc5c30]
_UI_get0_test_string;

// address=[0x1dc5c80]
_UI_get0_user_data;

// address=[0x1dc5c90]
_UI_get_default_method;

// address=[0x1dc5cc0]
_UI_get_ex_data;

// address=[0x1dc5cf0]
_UI_get_ex_new_index;

// address=[0x1dc5d30]
_UI_get_input_flags;

// address=[0x1dc5d50]
_UI_get_method;

// address=[0x1dc5d60]
_UI_get_result_maxsize;

// address=[0x1dc5dc0]
_UI_get_result_minsize;

// address=[0x1dc5e20]
_UI_get_string_type;

// address=[0x1dc5e40]
_UI_method_get_closer;

// address=[0x1dc5e60]
_UI_method_get_flusher;

// address=[0x1dc5e80]
_UI_method_get_opener;

// address=[0x1dc5ea0]
_UI_method_get_prompt_constructor;

// address=[0x1dc5ec0]
_UI_method_get_reader;

// address=[0x1dc5ee0]
_UI_method_get_writer;

// address=[0x1dc5f00]
_UI_method_set_closer;

// address=[0x1dc5f30]
_UI_method_set_flusher;

// address=[0x1dc5f60]
_UI_method_set_opener;

// address=[0x1dc5f90]
_UI_method_set_prompt_constructor;

// address=[0x1dc5fc0]
_UI_method_set_reader;

// address=[0x1dc5ff0]
_UI_method_set_writer;

// address=[0x1dc6020]
_UI_new;

// address=[0x1dc6040]
_UI_new_method;

// address=[0x1dc6110]
_UI_process;

// address=[0x1dc63b0]
_UI_set_default_method;

// address=[0x1dc63c0]
_UI_set_ex_data;

// address=[0x1dc63f0]
_UI_set_method;

// address=[0x1dc6410]
_UI_set_result;

// address=[0x1dc6d50]
_PKCS12_item_decrypt_d2i;

// address=[0x1dc6ec0]
_PKCS12_item_i2d_encrypt;

// address=[0x1dc7080]
_PKCS12_pbe_crypt;

// address=[0x1dc72f0]
_PKCS8_encrypt;

// address=[0x1dc74c0]
_BN_RECP_CTX_free;

// address=[0x1dc7520]
_BN_RECP_CTX_init;

// address=[0x1dc7580]
_BN_RECP_CTX_new;

// address=[0x1dc75f0]
_BN_RECP_CTX_set;

// address=[0x1dc7660]
_BN_div_recp;

// address=[0x1dc7a40]
_BN_mod_mul_reciprocal;

// address=[0x1dc7b60]
_BN_reciprocal;

// address=[0x1dc7c30]
_BN_GENCB_call;

// address=[0x1dc7d00]
_BN_generate_prime_ex;

// address=[0x1dc8120]
_BN_is_prime_ex;

// address=[0x1dc8150]
_BN_is_prime_fasttest_ex;

// address=[0x1dc8ed0]
_RSA_generate_key_ex;

// address=[0x1dc9990]
_RSA_padding_add_PKCS1_PSS;

// address=[0x1dc99d0]
_RSA_padding_add_PKCS1_PSS_mgf1;

// address=[0x1dc9e40]
_RSA_verify_PKCS1_PSS;

// address=[0x1dc9e80]
_RSA_verify_PKCS1_PSS_mgf1;

// address=[0x1dca450]
_DH_generate_parameters_ex;

// address=[0x1dca7b0]
_DH_get_1024_160;

// address=[0x1dca880]
_DH_get_2048_224;

// address=[0x1dca950]
_DH_get_2048_256;

// address=[0x1dcaa20]
_DSA_generate_parameters_ex;

// address=[0x1dcab30]
_dsa_builtin_paramgen;

// address=[0x1dcb8d0]
_dsa_builtin_paramgen2;

// address=[0x1dcc780]
_dsa_paramgen_check_g;

// address=[0x1dcc940]
_DSA_generate_key;

// address=[0x1dccc20]
_ECDH_KDF_X9_62;

// address=[0x1dccef0]
_ec_GFp_mont_group_init;

// address=[0x1dccf60]
_ec_GFp_mont_group_set_curve;

// address=[0x1dcd1f0]
_ec_GFp_mont_group_finish;

// address=[0x1dcd280]
_ec_GFp_mont_group_clear_finish;

// address=[0x1dcd310]
_ec_GFp_mont_group_copy;

// address=[0x1dcd4a0]
_ec_GFp_mont_field_mul;

// address=[0x1dcd510]
_ec_GFp_mont_field_sqr;

// address=[0x1dcd580]
_ec_GFp_mont_field_encode;

// address=[0x1dcd600]
_ec_GFp_mont_field_decode;

// address=[0x1dcd670]
_ec_GFp_mont_field_set_to_one;

// address=[0x1dcd6e0]
_EC_GFp_mont_method;

// address=[0x1dcd6f0]
_ec_GFp_nist_group_copy;

// address=[0x1dcd730]
_ec_GFp_nist_group_set_curve;

// address=[0x1dcd940]
_ec_GFp_nist_field_mul;

// address=[0x1dcda80]
_ec_GFp_nist_field_sqr;

// address=[0x1dcdbb0]
_EC_GFp_nist_method;

// address=[0x1dcdbc0]
_ec_GF2m_simple_group_init;

// address=[0x1dcdc20]
_ec_GF2m_simple_group_finish;

// address=[0x1dcdc70]
_ec_GF2m_simple_group_clear_finish;

// address=[0x1dcdd50]
_ec_GF2m_simple_group_copy;

// address=[0x1dce090]
_ec_GF2m_simple_group_set_curve;

// address=[0x1dce350]
_ec_GF2m_simple_group_get_curve;

// address=[0x1dce410]
_ec_GF2m_simple_group_get_degree;

// address=[0x1dce440]
_ec_GF2m_simple_group_check_discriminant;

// address=[0x1dce580]
_ec_GF2m_simple_point_init;

// address=[0x1dce5d0]
_ec_GF2m_simple_point_finish;

// address=[0x1dce620]
_ec_GF2m_simple_point_clear_finish;

// address=[0x1dce680]
_ec_GF2m_simple_point_copy;

// address=[0x1dce720]
_ec_GF2m_simple_point_set_to_infinity;

// address=[0x1dce760]
_ec_GF2m_simple_point_set_affine_coordinates;

// address=[0x1dce890]
_ec_GF2m_simple_point_get_affine_coordinates;

// address=[0x1dce9d0]
_ec_GF2m_simple_add;

// address=[0x1dcf030]
_ec_GF2m_simple_dbl;

// address=[0x1dcf070]
_ec_GF2m_simple_invert;

// address=[0x1dcf100]
_ec_GF2m_simple_is_at_infinity;

// address=[0x1dcf150]
_ec_GF2m_simple_is_on_curve;

// address=[0x1dcf410]
_ec_GF2m_simple_cmp;

// address=[0x1dcf6c0]
_ec_GF2m_simple_make_affine;

// address=[0x1dcf870]
_ec_GF2m_simple_points_make_affine;

// address=[0x1dcf910]
_ec_GF2m_simple_field_mul;

// address=[0x1dcf950]
_ec_GF2m_simple_field_sqr;

// address=[0x1dcf980]
_ec_GF2m_simple_field_div;

// address=[0x1dcf9c0]
_EC_GF2m_simple_method;

// address=[0x1dcf9d0]
_BN_kronecker;

// address=[0x1dcff20]
_BN_mod_sqrt;

// address=[0x1dd0b80]
_BN_GF2m_add;

// address=[0x1dd0d60]
_BN_GF2m_arr2poly;

// address=[0x1dd0df0]
_BN_GF2m_mod;

// address=[0x1dd0ef0]
_BN_GF2m_mod_arr;

// address=[0x1dd1430]
_BN_GF2m_mod_div;

// address=[0x1dd1510]
_BN_GF2m_mod_div_arr;

// address=[0x1dd15d0]
_BN_GF2m_mod_exp;

// address=[0x1dd1700]
_BN_GF2m_mod_exp_arr;

// address=[0x1dd1900]
_BN_GF2m_mod_inv;

// address=[0x1dd1fd0]
_BN_GF2m_mod_inv_arr;

// address=[0x1dd2090]
_BN_GF2m_mod_mul;

// address=[0x1dd21c0]
_BN_GF2m_mod_mul_arr;

// address=[0x1dd2560]
_BN_GF2m_mod_solve_quad;

// address=[0x1dd2680]
_BN_GF2m_mod_solve_quad_arr;

// address=[0x1dd2b90]
_BN_GF2m_mod_sqr;

// address=[0x1dd2cb0]
_BN_GF2m_mod_sqr_arr;

// address=[0x1dd2fa0]
_BN_GF2m_mod_sqrt;

// address=[0x1dd30c0]
_BN_GF2m_mod_sqrt_arr;

// address=[0x1dd31c0]
_BN_GF2m_poly2arr;

// address=[0x1dd4a60]
_ECDSA_OpenSSL;

// address=[0x1dd4a70]
_ENGINE_get_ECDSA;

// address=[0x1dd4a80]
_ENGINE_get_default_ECDSA;

// address=[0x1dd4ab0]
_ENGINE_register_ECDSA;

// address=[0x1dd4b00]
_ENGINE_register_all_ECDSA;

// address=[0x1dd4b70]
_ENGINE_set_ECDSA;

// address=[0x1dd4b90]
_ENGINE_set_default_ECDSA;

// address=[0x1dd4be0]
_ENGINE_unregister_ECDSA;

// address=[0x1dd5230]
_ECDH_OpenSSL;

// address=[0x1dd5240]
_ENGINE_get_ECDH;

// address=[0x1dd5250]
_ENGINE_get_default_ECDH;

// address=[0x1dd5280]
_ENGINE_register_ECDH;

// address=[0x1dd52d0]
_ENGINE_register_all_ECDH;

// address=[0x1dd5340]
_ENGINE_set_ECDH;

// address=[0x1dd5360]
_ENGINE_set_default_ECDH;

// address=[0x1dd53b0]
_ENGINE_unregister_ECDH;

// address=[0x1dd5460]
_DTLS_method;

// address=[0x1dd5470]
_DTLSv1_2_method;

// address=[0x1dd5480]
_DTLSv1_method;

// address=[0x1dd5490]
_OPENSSL_asc2uni;

// address=[0x1dd55b0]
_OPENSSL_uni2asc;

// address=[0x1dd56b0]
_PKCS12_certbag2x509;

// address=[0x1dd5720]
_PKCS12_certbag2x509crl;

// address=[0x1dd5790]
_PKCS12_x5092certbag;

// address=[0x1dd57d0]
_PKCS12_x509crl2certbag;

// address=[0x1dd5810]
_d2i_PKCS12_bio;

// address=[0x1dd5840]
_d2i_PKCS12_fp;

// address=[0x1dd5870]
_i2d_PKCS12_bio;

// address=[0x1dd58a0]
_i2d_PKCS12_fp;

// address=[0x1dd5a30]
_BIO_s_null;

// address=[0x1dd61a0]
_BIO_f_md;

// address=[0x1dd6e40]
_BIO_f_cipher;

// address=[0x1dd6e50]
_BIO_set_cipher;

// address=[0x1dd6f50]
_PKCS7_add0_attrib_signing_time;

// address=[0x1dd6fc0]
_PKCS7_add1_attrib_digest;

// address=[0x1dd7060]
_PKCS7_add_attrib_content_type;

// address=[0x1dd70c0]
_PKCS7_add_attrib_smimecap;

// address=[0x1dd7160]
_PKCS7_get_smimecap;

// address=[0x1dd7230]
_PKCS7_simple_smimecap;

// address=[0x1dd73c0]
_ssl3_accept;

// address=[0x1dd8ad0]
_SSLv3_server_method;

// address=[0x1dd8ae0]
_ssl3_get_cert_verify;

// address=[0x1dd9450]
_ssl3_get_client_certificate;

// address=[0x1dd9c30]
_ssl3_get_client_hello;

// address=[0x1ddb350]
_ssl3_get_client_key_exchange;

// address=[0x1ddd2a0]
_ssl3_get_next_proto;

// address=[0x1ddd550]
_ssl3_send_cert_status;

// address=[0x1ddd730]
_ssl3_send_certificate_request;

// address=[0x1dddd00]
_ssl3_send_hello_request;

// address=[0x1dddd80]
_ssl3_send_newsession_ticket;

// address=[0x1dde8d0]
_ssl3_send_server_certificate;

// address=[0x1ddea10]
_ssl3_send_server_done;

// address=[0x1ddea90]
_ssl3_send_server_hello;

// address=[0x1ddee40]
_ssl3_send_server_key_exchange;

// address=[0x1de0800]
_TLSv1_1_server_method;

// address=[0x1de0810]
_TLSv1_2_server_method;

// address=[0x1de0820]
_TLSv1_server_method;

// address=[0x1de0830]
_whirlpool_block;

// address=[0x1de2b60]
_UI_OpenSSL;

// address=[0x1de3220]
_ec_GFp_simple_group_init;

// address=[0x1de3290]
_ec_GFp_simple_group_finish;

// address=[0x1de32e0]
_ec_GFp_simple_group_clear_finish;

// address=[0x1de3330]
_ec_GFp_simple_group_copy;

// address=[0x1de33e0]
_ec_GFp_simple_group_set_curve;

// address=[0x1de36e0]
_ec_GFp_simple_group_get_curve;

// address=[0x1de38c0]
_ec_GFp_simple_group_get_degree;

// address=[0x1de38f0]
_ec_GFp_simple_group_check_discriminant;

// address=[0x1de3c60]
_ec_GFp_simple_point_init;

// address=[0x1de3cc0]
_ec_GFp_simple_point_finish;

// address=[0x1de3d10]
_ec_GFp_simple_point_clear_finish;

// address=[0x1de3d70]
_ec_GFp_simple_point_copy;

// address=[0x1de3e10]
_ec_GFp_simple_point_set_to_infinity;

// address=[0x1de3e50]
_ec_GFp_simple_set_Jprojective_coordinates_GFp;

// address=[0x1de4150]
_ec_GFp_simple_get_Jprojective_coordinates_GFp;

// address=[0x1de4350]
_ec_GFp_simple_point_set_affine_coordinates;

// address=[0x1de43c0]
_ec_GFp_simple_point_get_affine_coordinates;

// address=[0x1de48c0]
_ec_GFp_simple_add;

// address=[0x1de51f0]
_ec_GFp_simple_dbl;

// address=[0x1de5970]
_ec_GFp_simple_invert;

// address=[0x1de59d0]
_ec_GFp_simple_is_at_infinity;

// address=[0x1de5a20]
_ec_GFp_simple_is_on_curve;

// address=[0x1de5f30]
_ec_GFp_simple_cmp;

// address=[0x1de63e0]
_ec_GFp_simple_make_affine;

// address=[0x1de6580]
_ec_GFp_simple_points_make_affine;

// address=[0x1de6d40]
_ec_GFp_simple_field_mul;

// address=[0x1de6d80]
_ec_GFp_simple_field_sqr;

// address=[0x1de6db0]
_EC_GFp_simple_method;

// address=[0x1de6dc0]
_BN_get0_nist_prime_192;

// address=[0x1de6dd0]
_BN_get0_nist_prime_224;

// address=[0x1de6de0]
_BN_get0_nist_prime_256;

// address=[0x1de6df0]
_BN_get0_nist_prime_384;

// address=[0x1de6e00]
_BN_get0_nist_prime_521;

// address=[0x1de6e10]
_BN_nist_mod_192;

// address=[0x1de7570]
_BN_nist_mod_224;

// address=[0x1de7eb0]
_BN_nist_mod_256;

// address=[0x1de9090]
_BN_nist_mod_384;

// address=[0x1dea8e0]
_BN_nist_mod_521;

// address=[0x1deada0]
_ec_GF2m_have_precompute_mult;

// address=[0x1deb360]
_ec_GF2m_precompute_mult;

// address=[0x1deb390]
_ec_GF2m_simple_mul;

// address=[0x1dec140]
_dtls1_accept;

// address=[0x1ded780]
_DTLS_server_method;

// address=[0x1ded790]
_DTLSv1_2_server_method;

// address=[0x1ded7a0]
_DTLSv1_server_method;

// address=[0x1ded9b0]
_PKCS12_MAKE_KEYBAG;

// address=[0x1deda30]
_PKCS12_MAKE_SHKEYBAG;

// address=[0x1dedb70]
_PKCS12_decrypt_skey;

// address=[0x1dedba0]
_PKCS12_item_pack_safebag;

// address=[0x1dedcd0]
_PKCS12_pack_authsafes;

// address=[0x1dedd20]
_PKCS12_pack_p7data;

// address=[0x1dede40]
_PKCS12_pack_p7encdata;

// address=[0x1dee050]
_PKCS12_unpack_authsafes;

// address=[0x1dee0c0]
_PKCS12_unpack_p7data;

// address=[0x1dee130]
_PKCS12_unpack_p7encdata;

// address=[0x1dee1a0]
_PKCS12_MAC_DATA_it;

// address=[0x1dee1b0]
_PKCS12_SAFEBAG_it;

// address=[0x1dee1c0]
_PKCS12_BAGS_it;

// address=[0x1dee1f0]
_PKCS12_AUTHSAFES_it;

// address=[0x1dee200]
_PKCS12_BAGS_free;

// address=[0x1dee230]
_PKCS12_BAGS_new;

// address=[0x1dee250]
_PKCS12_MAC_DATA_free;

// address=[0x1dee280]
_PKCS12_MAC_DATA_new;

// address=[0x1dee2a0]
_PKCS12_SAFEBAGS_it;

// address=[0x1dee2b0]
_PKCS12_SAFEBAG_free;

// address=[0x1dee2e0]
_PKCS12_SAFEBAG_new;

// address=[0x1dee300]
_PKCS12_free;

// address=[0x1dee330]
_PKCS12_it;

// address=[0x1dee340]
_PKCS12_new;

// address=[0x1dee360]
_d2i_PKCS12;

// address=[0x1dee390]
_d2i_PKCS12_BAGS;

// address=[0x1dee3c0]
_d2i_PKCS12_MAC_DATA;

// address=[0x1dee3f0]
_d2i_PKCS12_SAFEBAG;

// address=[0x1dee420]
_i2d_PKCS12;

// address=[0x1dee450]
_i2d_PKCS12_BAGS;

// address=[0x1dee480]
_i2d_PKCS12_MAC_DATA;

// address=[0x1dee4b0]
_i2d_PKCS12_SAFEBAG;

// address=[0x1dee4da]
_WSAStartup@8;

// address=[0x1dee4e0]
___WSAFDIsSet@8;

// address=[0x1dee4e6]
_accept@12;

// address=[0x1dee4ec]
_bind@12;

// address=[0x1dee4f2]
_closesocket@4;

// address=[0x1dee4f8]
_connect@12;

// address=[0x1dee4fe]
_ioctlsocket@12;

// address=[0x1dee504]
_getsockname@12;

// address=[0x1dee50a]
_getsockopt@20;

// address=[0x1dee510]
_htonl@4;

// address=[0x1dee516]
_htons@4;

// address=[0x1dee51c]
_inet_addr@4;

// address=[0x1dee522]
_inet_ntoa@4;

// address=[0x1dee528]
_listen@8;

// address=[0x1dee52e]
_ntohl@4;

// address=[0x1dee534]
_ntohs@4;

// address=[0x1dee53a]
_recv@16;

// address=[0x1dee540]
_recvfrom@24;

// address=[0x1dee546]
_select@20;

// address=[0x1dee54c]
_send@16;

// address=[0x1dee552]
_sendto@24;

// address=[0x1dee558]
_setsockopt@20;

// address=[0x1dee55e]
_socket@12;

// address=[0x1dee564]
_gethostbyname@4;

// address=[0x1dee56a]
_gethostname@8;

// address=[0x1dee570]
_WSAGetLastError@0;

// address=[0x1dee576]
_getnameinfo@28;

// address=[0x1dee57c]
_WSACleanup@0;

// address=[0x1dee582]
_WSASetLastError@4;

// address=[0x1dee588]
_getpeername@12;

// address=[0x1dee58e]
_WSAIoctl@36;

// address=[0x1dee594]
_getaddrinfo@16;

// address=[0x1dee59a]
_freeaddrinfo@4;

// address=[0x1dee5a0]
_shutdown@8;

// address=[0x1dee5a6]
_getservbyname@8;

// address=[0x1dee5ac]
_GetIfEntry@4;

// address=[0x1dee5b2]
_GetBestInterface@8;

// address=[0x1dee5b8]
_GetAdaptersAddresses@20;

// address=[0x1dee5c0]
_USZlib_inflate;

// address=[0x1df0fc0]
_USZlib_inflateCopy;

// address=[0x1df1240]
_USZlib_inflateEnd;

// address=[0x1df1310]
_USZlib_inflateGetDictionary;

// address=[0x1df13e0]
_USZlib_inflateGetHeader;

// address=[0x1df1450]
_USZlib_inflateInit2_;

// address=[0x1df15d0]
_USZlib_inflateInit_;

// address=[0x1df1600]
_USZlib_inflateMark;

// address=[0x1df16b0]
_USZlib_inflatePrime;

// address=[0x1df1780]
_USZlib_inflateReset;

// address=[0x1df1800]
_USZlib_inflateReset2;

// address=[0x1df1930]
_USZlib_inflateResetKeep;

// address=[0x1df1a80]
_USZlib_inflateSetDictionary;

// address=[0x1df1ba0]
_USZlib_inflateSync;

// address=[0x1df1df0]
_USZlib_inflateSyncPoint;

// address=[0x1df1e70]
_USZlib_inflateUndermine;

// address=[0x1df2230]
_USZlib_adler32;

// address=[0x1df2950]
_USZlib_adler32_combine;

// address=[0x1df2980]
_USZlib_adler32_combine64;

// address=[0x1df2b20]
_USZlib_crc32;

// address=[0x1df2e10]
_USZlib_crc32_combine;

// address=[0x1df2e40]
_USZlib_crc32_combine64;

// address=[0x1df2e70]
_USZlib_get_crc_table;

// address=[0x1df3f60]
_USZlib_zError;

// address=[0x1df3f80]
_USZlib_zcalloc;

// address=[0x1df3fc0]
_USZlib_zcfree;

// address=[0x1df3fe0]
_USZlib_zlibCompileFlags;

// address=[0x1df4150]
_USZlib_zlibVersion;

// address=[0x1df4160]
_USZlib_inflate_table;

// address=[0x1df4980]
_USZlib_inflate_fast;

// address=[0x1eb40a0]
__int64 __cdecl _InterlockedOr64_INLINE(__int64 volatile *,__int64);

// address=[0x1ec7b20]
_atomic_thread_fence;

// address=[0x1ec7b80]
_snprintf;

// address=[0x207f280]
_vsscanf;

// address=[0x242aa70]
_HRESULT_FROM_WIN32;

// address=[0x242aac0]
__vscprintf;

// address=[0x242aaf0]
__vscprintf_l;

// address=[0x242ab70]
__vsnprintf_s;

// address=[0x242abb0]
__vswprintf_s_l;

// address=[0x242ac30]
_swprintf_s;

// address=[0x269fb70]
float __cdecl pow(float,float);

// address=[0x26a4030]
_!=;

// address=[0x26a4090]
_==;

// address=[0x26a40e0]
_IsEqualGUID;

// address=[0x26a4150]
_PropVariantInit;

// address=[0x26a42b0]
_opus_encoder_get_size;

// address=[0x26a4370]
_opus_encoder_create;

// address=[0x26a4470]
_opus_encoder_init;

// address=[0x26a4830]
_opus_encode;

// address=[0x26a49c0]
_opus_encode_float;

// address=[0x26a4a80]
_opus_encoder_destroy;

// address=[0x26a4aa0]
_opus_encoder_ctl;

// address=[0x26a5780]
_downmix_float;

// address=[0x26a5920]
_downmix_int;

// address=[0x26a5ab0]
_optimize_framesize;

// address=[0x26a5f90]
_frame_size_select;

// address=[0x26a60c0]
_compute_frame_size;

// address=[0x26a6190]
_opus_encode_native;

// address=[0x26aa820]
_compute_stereo_width;

// address=[0x26ac8b0]
_float2int;

// address=[0x26ac970]
_opus_decoder_get_size;

// address=[0x26aca30]
_opus_decoder_create;

// address=[0x26acb10]
_opus_decoder_init;

// address=[0x26acce0]
_opus_decode;

// address=[0x26ace20]
_opus_decode_float;

// address=[0x26ace60]
_opus_decoder_ctl;

// address=[0x26ad110]
_opus_decoder_destroy;

// address=[0x26ad130]
_opus_packet_get_bandwidth;

// address=[0x26ad200]
_opus_packet_get_samples_per_frame;

// address=[0x26ad300]
_opus_packet_get_nb_channels;

// address=[0x26ad340]
_opus_packet_get_nb_frames;

// address=[0x26ad3b0]
_opus_packet_get_nb_samples;

// address=[0x26ad420]
_opus_decoder_get_nb_samples;

// address=[0x26ad510]
_opus_decode_native;

// address=[0x26af6c0]
_opus_custom_encoder_ctl;

// address=[0x26afd30]
_celt_encoder_get_size;

// address=[0x26afd70]
_celt_encode_with_ec;

// address=[0x26b3220]
_celt_encoder_init;

// address=[0x26b3290]
_celt_preemphasis;

// address=[0x26b3d10]
_patch_transient_decision;

// address=[0x26b8fa0]
_ec_enc_init;

// address=[0x26b9020]
_ec_encode;

// address=[0x26b90b0]
_ec_encode_bin;

// address=[0x26b9140]
_ec_enc_bit_logp;

// address=[0x26b91d0]
_ec_enc_icdf;

// address=[0x26b9270]
_ec_enc_uint;

// address=[0x26b9340]
_ec_enc_bits;

// address=[0x26b9400]
_ec_enc_patch_initial_bits;

// address=[0x26b94e0]
_ec_enc_shrink;

// address=[0x26b9550]
_ec_enc_done;

// address=[0x26b9c60]
_silk_Get_Encoder_Size;

// address=[0x26b9c90]
_silk_InitEncoder;

// address=[0x26b9da0]
_silk_Encode;

// address=[0x26bc310]
_opus_repacketizer_get_size;

// address=[0x26bc320]
_opus_repacketizer_init;

// address=[0x26bc340]
_opus_repacketizer_create;

// address=[0x26bc380]
_opus_repacketizer_destroy;

// address=[0x26bc3a0]
_opus_repacketizer_cat;

// address=[0x26bc3d0]
_opus_repacketizer_out_range;

// address=[0x26bc400]
_opus_repacketizer_get_nb_frames;

// address=[0x26bc410]
_opus_repacketizer_out;

// address=[0x26bc440]
_opus_packet_pad;

// address=[0x26bc570]
_opus_packet_unpad;

// address=[0x26bc660]
_opus_multistream_packet_pad;

// address=[0x26bc7d0]
_opus_multistream_packet_unpad;

// address=[0x26bca10]
_opus_repacketizer_out_range_impl;

// address=[0x26bd4e0]
_tonality_analysis;

// address=[0x26bfbc0]
_tonality_get_info;

// address=[0x26bfe00]
_run_analysis;

// address=[0x26c0e10]
_silk_lin2log;

// address=[0x26c1030]
_silk_log2lin;

// address=[0x26c1280]
_opus_custom_decoder_ctl;

// address=[0x26c1690]
_celt_decoder_get_size;

// address=[0x26c16d0]
_celt_decoder_init;

// address=[0x26c1740]
_celt_decode_with_ec;

// address=[0x26c5000]
_ec_dec_init;

// address=[0x26c50a0]
_ec_decode;

// address=[0x26c5120]
_ec_decode_bin;

// address=[0x26c51b0]
_ec_dec_update;

// address=[0x26c5230]
_ec_dec_bit_logp;

// address=[0x26c52e0]
_ec_dec_icdf;

// address=[0x26c5380]
_ec_dec_uint;

// address=[0x26c5490]
_ec_dec_bits;

// address=[0x26c5850]
_opus_packet_parse;

// address=[0x26c5880]
_opus_pcm_soft_clip;

// address=[0x26c5eb0]
_encode_size;

// address=[0x26c5f20]
_opus_packet_parse_impl;

// address=[0x26c6790]
_silk_Get_Decoder_Size;

// address=[0x26c67c0]
_silk_InitDecoder;

// address=[0x26c6850]
_silk_Decode;

// address=[0x26c7c10]
_clt_mdct_forward;

// address=[0x26c81c0]
_clt_mdct_backward;

// address=[0x26c89c0]
_opus_custom_mode_create;

// address=[0x26c8b00]
_ec_tell_frac;

// address=[0x26c8c20]
_opus_strerror;

// address=[0x26c8c50]
_opus_get_version_string;

// address=[0x26c8c60]
_resampling_factor;

// address=[0x26c8cf0]
_comb_filter;

// address=[0x26c9080]
_init_caps;

// address=[0x26c9770]
_pitch_downsample;

// address=[0x26c9c00]
_pitch_search;

// address=[0x26c9ff0]
_remove_doubling;

// address=[0x26ca730]
_celt_pitch_xcorr_c;

// address=[0x26cb490]
_compute_allocation;

// address=[0x26ccd80]
_compute_band_energies;

// address=[0x26cce80]
_normalise_bands;

// address=[0x26ccf80]
_denormalise_bands;

// address=[0x26cd140]
_spreading_decision;

// address=[0x26cd520]
_haar1;

// address=[0x26cd610]
_quant_all_bands;

// address=[0x26ce080]
_anti_collapse;

// address=[0x26ce450]
_celt_lcg_rand;

// address=[0x26ce470]
_hysteresis_decision;

// address=[0x26d1c20]
_amp2Log2;

// address=[0x26d1d00]
_quant_coarse_energy;

// address=[0x26d2350]
_quant_fine_energy;

// address=[0x26d2510]
_quant_energy_finalise;

// address=[0x26d2680]
_unquant_coarse_energy;

// address=[0x26d2920]
_unquant_fine_energy;

// address=[0x26d2a20]
_unquant_energy_finalise;

// address=[0x26d3680]
_silk_resampler_init;

// address=[0x26d3b90]
_silk_resampler;

// address=[0x26d4350]
_silk_stereo_LR_to_MS;

// address=[0x26d56c0]
_silk_stereo_encode_pred;

// address=[0x26d5840]
_silk_stereo_encode_mid_only;

// address=[0x26d58d0]
_check_control_input;

// address=[0x26d5d70]
_silk_control_SNR;

// address=[0x26d5f60]
_silk_encode_pulses;

// address=[0x26d6920]
_silk_encode_indices;

// address=[0x26d7530]
_silk_HP_variable_cutoff;

// address=[0x26d7a10]
_silk_encode_do_VAD_FLP;

// address=[0x26d7af0]
_silk_encode_frame_FLP;

// address=[0x26d8de0]
_silk_init_encoder;

// address=[0x26d9010]
_silk_control_encoder;

// address=[0x26da420]
_opus_fft;

// address=[0x26da710]
_opus_ifft;

// address=[0x26ddf10]
_mlp_process;

// address=[0x26de390]
__celt_lpc;

// address=[0x26de590]
_celt_fir;

// address=[0x26de8b0]
_celt_iir;

// address=[0x26dede0]
__celt_autocorr;

// address=[0x26df520]
_alg_quant;

// address=[0x26dfad0]
_alg_unquant;

// address=[0x26dfc30]
_renormalise_vector;

// address=[0x26dfd10]
_stereo_itheta;

// address=[0x26e06d0]
_silk_stereo_MS_to_LR;

// address=[0x26e0c60]
_silk_stereo_decode_pred;

// address=[0x26e0ec0]
_silk_stereo_decode_mid_only;

// address=[0x26e0f90]
_silk_init_decoder;

// address=[0x26e1000]
_silk_decoder_set_fs;

// address=[0x26e13e0]
_silk_decode_frame;

// address=[0x26e1810]
_silk_decode_indices;

// address=[0x26e1e80]
_silk_decode_pulses;

// address=[0x26e22d0]
_isqrt32;

// address=[0x26e23b0]
_ec_laplace_encode;

// address=[0x26e2550]
_ec_laplace_decode;

// address=[0x26e27a0]
_silk_resampler_private_IIR_FIR;

// address=[0x26e2cc0]
_silk_resampler_private_down_FIR;

// address=[0x26e4a20]
_silk_resampler_private_up2_HQ_wrapper;

// address=[0x26e4a60]
_silk_resampler_private_up2_HQ;

// address=[0x26e55e0]
_silk_stereo_find_predictor;

// address=[0x26e5be0]
_silk_stereo_quant_pred;

// address=[0x26e5e70]
_silk_encode_signs;

// address=[0x26e5fd0]
_silk_decode_signs;

// address=[0x26e61e0]
_silk_shell_encoder;

// address=[0x26e6560]
_silk_shell_decoder;

// address=[0x26e6c50]
_silk_NLSF_unpack;

// address=[0x26e6df0]
_silk_gains_quant;

// address=[0x26e7110]
_silk_gains_dequant;

// address=[0x26e7250]
_silk_gains_ID;

// address=[0x26e76f0]
_silk_VAD_Init;

// address=[0x26e77f0]
_silk_VAD_GetSA_Q8;

// address=[0x26e8940]
_silk_LP_variable_cutoff;

// address=[0x26e9020]
_silk_prefilter_FLP;

// address=[0x26e9a80]
_silk_noise_shape_analysis_FLP;

// address=[0x26eb260]
_silk_find_pitch_lags_FLP;

// address=[0x26eb880]
_silk_find_pred_coefs_FLP;

// address=[0x26ebf10]
_silk_process_gains_FLP;

// address=[0x26ec4b0]
_silk_quant_LTP_gains_FLP;

// address=[0x26ec630]
_silk_A2NLSF_FLP;

// address=[0x26ec700]
_silk_NLSF2A_FLP;

// address=[0x26ec7c0]
_silk_process_NLSFs_FLP;

// address=[0x26ec8b0]
_silk_NSQ_wrapper_FLP;

// address=[0x26ed080]
_silk_control_audio_bandwidth;

// address=[0x26ed410]
_encode_pulses;

// address=[0x26ed4e0]
_decode_pulses;

// address=[0x26ee090]
_silk_PLC_Reset;

// address=[0x26ee0f0]
_silk_PLC;

// address=[0x26ee170]
_silk_PLC_glue_frames;

// address=[0x26f0520]
_silk_CNG_Reset;

// address=[0x26f05c0]
_silk_CNG;

// address=[0x26f13e0]
_silk_decode_parameters;

// address=[0x26f1de0]
_silk_decode_core;

// address=[0x26f3470]
_silk_resampler_private_AR2;

// address=[0x26f35c0]
_silk_sum_sqr_shift;

// address=[0x26f3790]
_silk_inner_prod_aligned_scale;

// address=[0x26f3810]
_silk_ana_filt_bank_1;

// address=[0x26f3a90]
_silk_sigm_Q15;

// address=[0x26f3b50]
_silk_biquad_alt;

// address=[0x26f3f20]
_silk_bwexpander_FLP;

// address=[0x26f3fd0]
_silk_LPC_inverse_pred_gain_FLP;

// address=[0x26f42b0]
_silk_levinsondurbin_FLP;

// address=[0x26f4610]
_silk_autocorrelation_FLP;

// address=[0x26f46a0]
_silk_energy_FLP;

// address=[0x26f4840]
_silk_warped_autocorrelation_FLP;

// address=[0x26f4cc0]
_silk_apply_sine_window_FLP;

// address=[0x26f4f10]
_silk_schur_FLP;

// address=[0x26f5280]
_silk_k2a_FLP;

// address=[0x26f5440]
_silk_pitch_analysis_core_FLP;

// address=[0x26f82b0]
_silk_LPC_analysis_filter_FLP;

// address=[0x26f9090]
_silk_scale_copy_vector_FLP;

// address=[0x26f91b0]
_silk_LTP_scale_ctrl_FLP;

// address=[0x26f9300]
_silk_find_LPC_FLP;

// address=[0x26f97a0]
_silk_find_LTP_FLP;

// address=[0x26f9ef0]
_silk_LTP_analysis_filter_FLP;

// address=[0x26fa100]
_silk_residual_energy_FLP;

// address=[0x26fa3b0]
_silk_residual_energy_covar_FLP;

// address=[0x26fa780]
_silk_A2NLSF;

// address=[0x26fb0c0]
_silk_NLSF2A;

// address=[0x26fb9d0]
_silk_quant_LTP_gains;

// address=[0x26fc2d0]
_silk_NSQ;

// address=[0x26fe8a0]
_silk_NSQ_del_dec;

// address=[0x2702140]
_silk_process_NLSFs;

// address=[0x2702660]
_silk_LPC_analysis_filter;

// address=[0x27029a0]
_silk_bwexpander;

// address=[0x2702b10]
_silk_LPC_inverse_pred_gain;

// address=[0x2703400]
_silk_decode_pitch;

// address=[0x2703910]
_silk_NLSF_decode;

// address=[0x2703d90]
_silk_inner_product_FLP;

// address=[0x2703ef0]
_silk_resampler_down2;

// address=[0x2704190]
_silk_resampler_down2_3;

// address=[0x27047d0]
_silk_insertion_sort_decreasing_FLP;

// address=[0x2704a90]
_silk_burg_modified_FLP;

// address=[0x2705680]
_silk_interpolate;

// address=[0x2705780]
_silk_scale_vector_FLP;

// address=[0x27058a0]
_silk_corrMatrix_FLP;

// address=[0x2705aa0]
_silk_corrVector_FLP;

// address=[0x2705bb0]
_silk_regularize_correlations_FLP;

// address=[0x2705c60]
_silk_solve_LDL_FLP;

// address=[0x27064a0]
_silk_bwexpander_32;

// address=[0x27065e0]
_silk_VQ_WMat_EC;

// address=[0x2707000]
_silk_NLSF_VQ_weights_laroia;

// address=[0x2707680]
_silk_NLSF_encode;

// address=[0x2707eb0]
_silk_NLSF_stabilize;

// address=[0x27085b0]
_silk_insertion_sort_increasing;

// address=[0x27087c0]
_silk_insertion_sort_increasing_all_values_int16;

// address=[0x2708950]
_silk_NLSF_VQ;

// address=[0x2708b50]
_silk_NLSF_del_dec_quant;

// address=[0x27ca2c0]
bool __cdecl isfinite<float>(float);

// address=[0x284f440]
int __cdecl fpclassify(float);

// address=[0x29233e0]
void __stdcall `vector copy constructor iterator'(void *,void *,unsigned int,unsigned int,void * (*)(void *,void *));

// address=[0x296dcd0]
float __cdecl acos(float);

// address=[0x296f540]
float __cdecl asin(float);

// address=[0x296f570]
float __cdecl atan2(float,float);

// address=[0x2971ef0]
float __cdecl cos(float);

// address=[0x298b750]
float __cdecl sin(float);

// address=[0x298bda0]
_acosf;

// address=[0x298bde0]
_asinf;

// address=[0x298be20]
_atan2f;

// address=[0x298be70]
_cosf;

// address=[0x298beb0]
_sinf;

// address=[0x298bef0]
_speex_resampler_init;

// address=[0x298bf20]
_speex_resampler_init_frac;

// address=[0x298c1e0]
_speex_resampler_destroy;

// address=[0x298c3d0]
_speex_resampler_process_float;

// address=[0x298c400]
_speex_resampler_process_int;

// address=[0x298c750]
_speex_resampler_process_interleaved_float;

// address=[0x298c840]
_speex_resampler_process_interleaved_int;

// address=[0x298c930]
_speex_resampler_set_rate;

// address=[0x298c960]
_speex_resampler_get_rate;

// address=[0x298c980]
_speex_resampler_set_rate_frac;

// address=[0x298cb10]
_speex_resampler_get_ratio;

// address=[0x298cb30]
_speex_resampler_set_quality;

// address=[0x298cb80]
_speex_resampler_get_quality;

// address=[0x298cb90]
_speex_resampler_set_input_stride;

// address=[0x298cba0]
_speex_resampler_get_input_stride;

// address=[0x298cbb0]
_speex_resampler_set_output_stride;

// address=[0x298cbc0]
_speex_resampler_get_output_stride;

// address=[0x298cbd0]
_speex_resampler_get_input_latency;

// address=[0x298cbe0]
_speex_resampler_get_output_latency;

// address=[0x298cc10]
_speex_resampler_skip_zeros;

// address=[0x298cc60]
_speex_resampler_reset_mem;

// address=[0x298ccb0]
_speex_resampler_strerror;

// address=[0x298fb90]
_internal_speex_alloc;

// address=[0x298fbb0]
_internal_speex_realloc;

// address=[0x298fbd0]
_internal_speex_free;

// address=[0x29bf0f0]
__int64 __cdecl _InterlockedExchange64_INLINE(__int64 volatile *,__int64);

// address=[0x29c27c0]
__int64 __cdecl abs(__int64);

// address=[0x2bb3170]
float __cdecl pow(float,int);

// address=[0x2d59560]
bool __cdecl EalFileLibInit(unsigned long);

// address=[0x2d59580]
void __cdecl EalFileLibShutdown(void);

// address=[0x2d595c0]
void __cdecl EalFileClose(void *);

// address=[0x2d595e0]
bool __cdecl EalFileExists(int,char const *);

// address=[0x2d59a80]
unsigned __int64 __cdecl EalFileGetSize(void *);

// address=[0x2d59b50]
unsigned long __cdecl EalFileGetBufferAlignment(void *);

// address=[0x2d59b70]
unsigned long __cdecl EalFileGetSectorSize(void *);

// address=[0x2d59b90]
char __cdecl EalFileGetSeparator(void);

// address=[0x2d59bb0]
bool __cdecl EalMemLibInit(unsigned long);

// address=[0x2d59bd0]
void __cdecl EalMemLibShutdown(void);

// address=[0x2d59bf0]
void * __cdecl EalMemAlloc(unsigned long,unsigned long,unsigned long,int);

// address=[0x2d59cf0]
void * __cdecl EalMemAllocWithContext(unsigned long,unsigned long,unsigned long,int,void * &);

// address=[0x2d59d20]
void * __cdecl EalMemRealloc(void *,unsigned long,unsigned long);

// address=[0x2d59ea0]
void * __cdecl EalMemReallocWithContext(void *,unsigned long,unsigned long,void * const &);

// address=[0x2d59ec0]
void __cdecl EalMemFree(void *);

// address=[0x2d59f90]
void __cdecl EalMemFreeWithContext(void *,void * const &);

// address=[0x2d59fb0]
unsigned long __cdecl EalMemGetPageSize(void);

// address=[0x2d59fc0]
unsigned long __cdecl EalMemGetAllocatedSize(void const *);

// address=[0x2d5a090]
unsigned long __cdecl EalMemGetAllocated(void);

// address=[0x2d5a1a0]
void * __cdecl EalMemDebugRealloc(void *,unsigned long,unsigned long,char const *,unsigned long);

// address=[0x2d5a200]
void * __cdecl EalMemDebugReallocWithContext(void *,unsigned long,unsigned long,void * const &,char const *,unsigned long);

// address=[0x2d5a280]
void __cdecl EalMemDebugSetTagName(int,char const *);

// address=[0x2d5a300]
void * __cdecl SimplAlloc(unsigned long,unsigned int,unsigned long,int);

// address=[0x2d5a4a0]
void __cdecl SimplFree(void *);

// address=[0x2d5a5f0]
bool __cdecl SimplPS::FileSystemInit(void);

// address=[0x2d5a600]
bool __cdecl SimplPS::FileSystemDeinit(void);

// address=[0x2d5a7b0]
void __cdecl SimplPS::FileClose(void *);

// address=[0x2d5acd0]
unsigned long __cdecl SimplPS::FileGetBufferAlignment(void *);

// address=[0x2d5ace0]
unsigned long __cdecl SimplPS::FileGetSectorSize(void *);

// address=[0x2d5acf0]
char __cdecl SimplPS::FileGetSeparator(void);

// address=[0x2d5ad00]
bool __cdecl SimplPS::FileDelete(char const *);

// address=[0x2d5af80]
bool __cdecl EalInputLibInit(unsigned long);

// address=[0x2d5afa0]
void __cdecl EalInputLibShutdown(void);

// address=[0x2d5afd0]
unsigned char * __cdecl EalInputGetKeyboardState(long &);

// address=[0x2d5afe0]
unsigned long __cdecl EalInputGetKeyboardModState(void);

// address=[0x2d5aff0]
unsigned long __cdecl EalInputGetNumGamepads(void);

// address=[0x2d5b000]
void * __cdecl EalInputGetGamepad(unsigned long);

// address=[0x2d5b010]
unsigned long __cdecl EalInputGamepadGetNumAxis(void *);

// address=[0x2d5b020]
unsigned long __cdecl EalInputGamepadGetNumButtons(void *);

// address=[0x2d5b030]
short __cdecl EalInputGamepadGetAxis(void *,long);

// address=[0x2d5b040]
unsigned char __cdecl EalInputGamepadGetButton(void *,long);

// address=[0x2d5b070]
bool __cdecl EalJobLibInit(unsigned long);

// address=[0x2d5b090]
void __cdecl EalJobLibShutdown(void);

// address=[0x2d5b0d0]
void __cdecl EalJobStart(void *);

// address=[0x2d5b0e0]
void __cdecl EalJobFree(void *);

// address=[0x2d5b0f0]
bool __cdecl EalJobCancel(void *);

// address=[0x2d5b100]
bool __cdecl EalJobCompleted(void * *,unsigned long);

// address=[0x2d5b110]
void __cdecl EalJobWaitForJob(void * *,unsigned long);

// address=[0x2d5b120]
void * __cdecl EalJobGetCurrentJob(void);

// address=[0x2d5b130]
unsigned long __cdecl EalParallelizeLargeItemCount(int,unsigned long);

// address=[0x2d5b160]
void __cdecl EalJobParallelize(int,void (__cdecl*)(void *,unsigned __int64,unsigned __int64),void *,unsigned __int64,long);

// address=[0x2d5b190]
bool __cdecl EalLogLibInit(unsigned long);

// address=[0x2d5b1b0]
void __cdecl EalLogLibShutdown(void);

// address=[0x2d5b1d0]
bool __cdecl EalLogIsEnabled(int,unsigned long);

// address=[0x2d5b1e0]
void __cdecl EalLogOutput(int,unsigned long,char const *,char const *,unsigned long);

// address=[0x2d5b220]
void __cdecl EalLogOutputWithFormatVa(int,unsigned long,char const *,unsigned long,char const *,char *);

// address=[0x2d5b310]
bool __cdecl EalLogAssert(int,char const *,char const *,char const *,unsigned long,unsigned long *);

// address=[0x2d5b560]
void __cdecl EalLogSetTagName(int,char const *);

// address=[0x2d5b570]
char const * __cdecl EalLogGetTagName(int);

// address=[0x2d5b580]
bool __cdecl TgoEalHelper::Log::IsLastAssertShouldBreak(void);

// address=[0x2d5b590]
void __cdecl TgoEalHelper::Log::SkipNextAssert(void);

// address=[0x2d5b5a0]
void __cdecl TgoEalHelper::Log::NeverBreak(void);

// address=[0x2d5b5b0]
void __cdecl TgoEalHelper::Log::Register(bool (__cdecl*)(char const *,char const *,char const *,unsigned long,bool,bool));

// address=[0x2d5b5c0]
bool (__cdecl*__cdecl TgoEalHelper::Log::GetRegisteredLogAssertFunction(void))(char const *,char const *,char const *,unsigned long,bool,bool);

// address=[0x2d5b5d0]
void __cdecl TgoEalHelper::Log::Reset(void);

// address=[0x2d5b600]
unsigned __int64 __cdecl TgoEalHelper::Mem::GetAllocatedByTag(int);

// address=[0x2d5b650]
unsigned __int64 __cdecl TgoEalHelper::Mem::GetAllocatedByProduct(int);

// address=[0x2d5b6a0]
void __cdecl TgoEalHelper::Mem::AllocationReport(unsigned __int64,int);

// address=[0x2d5b6d0]
void __cdecl TgoEalHelper::Mem::AllocationReportByProduct(unsigned __int64,int);

// address=[0x2d5b700]
void __cdecl TgoEalHelper::Mem::RegisterOutputForAllocationReport(void (__cdecl*)(char const *));

// address=[0x2d5b980]
bool __cdecl EalNetLibInit(unsigned long);

// address=[0x2d5b9a0]
void __cdecl EalNetLibShutdown(void);

// address=[0x2d5c730]
unsigned long __cdecl EalMemGetAllocatedByTag(int);

// address=[0x2d5c770]
bool __cdecl SimplPS::NetInit(void);

// address=[0x2d5c830]
bool __cdecl SimplPS::NetDeinit(void);

// address=[0x2d5c8c0]
bool __cdecl EalThreadLibInit(unsigned long);

// address=[0x2d5c8d0]
void __cdecl EalThreadLibShutdown(void);

// address=[0x2d5ca80]
void __cdecl EalThreadClose(void *);

// address=[0x2d5cb50]
unsigned int __stdcall _WindowsThreadCallback(void *);

// address=[0x2d5cdc0]
bool __cdecl EalPerfLibInit(unsigned long);

// address=[0x2d5d0e0]
void __cdecl EalPerfLibShutdown(void);

// address=[0x2d5d290]
char const * __cdecl EalPerfConvertDynamicString(char const *);

// address=[0x2d5d520]
void __cdecl EalPerfSetTrackInfo(int,char const *);

// address=[0x2d5d560]
char const * __cdecl EalPerfConvertTemporaryStringVa(char const *,char *);

// address=[0x2d5d990]
void __cdecl EalPerfLogThreadName(unsigned __int64,char const *);

// address=[0x2d5dbd0]
bool __cdecl EalPerfData(int,void const *,unsigned long);

// address=[0x2d5dcb0]
bool __cdecl EalPerfUnregisterMetaDataProvider(void (__cdecl*)(void *));

// address=[0x2d5ddd0]
unsigned __int64 __cdecl EalPerfGetCurrentFrameNo(void);

// address=[0x2d5ddf0]
unsigned __int64 __cdecl EalPerfGetCurrentFrameBeginTime(void);

// address=[0x2d5de10]
void __cdecl EalPerfDetachTrackFromThread(int);

// address=[0x2d61c50]
void __cdecl EnableDisableTrack(int,bool);

// address=[0x2d61cc0]
void __cdecl DetachTrackMetaDataCallBack(void *);

// address=[0x2d7a0c0]
int __cdecl SimplEalRound<int,unsigned int>(int,unsigned int);

// address=[0x2da5850]
void __cdecl __vcrt_va_start_verify_argument_type<double>(void);

// address=[0x2da5860]
void __cdecl __vcrt_va_start_verify_argument_type<unsigned __int64>(void);

// address=[0x2da5870]
int __cdecl _snprintf_s<256>(char (&)[256],unsigned int,char const *,...);

// address=[0x2da58d0]
int __cdecl _snprintf_s<512>(char (&)[512],unsigned int,char const *,...);

// address=[0x2da5930]
int __cdecl _snprintf_s<64>(char (&)[64],unsigned int,char const *,...);

// address=[0x2dd0a20]
unsigned __int64 __cdecl ConvertToFAPTime(unsigned __int64);

// address=[0x2dd2990]
bool __cdecl MetaDataTrackEnabled(int);

// address=[0x2dd4030]
long __stdcall StringCbCopyA(char *,unsigned int,char const *);

// address=[0x2dd4570]
bool __cdecl TrackEnabled(int);

// address=[0x2dd50e0]
unsigned __int64 __cdecl ValidateTime(unsigned __int64);

// address=[0x2debb70]
__int64 __cdecl _InterlockedExchangeAdd64_INLINE(__int64 volatile *,__int64);

// address=[0x2dfec60]
public: struct std::_Tree_node<struct std::pair<int const ,unsigned __int64>,void *> * __thiscall SIMPL_NS::EalStdAllocator<struct std::_Tree_node<struct std::pair<int const ,unsigned __int64>,void *>,1111490559>::allocate(unsigned int,void const *);

// address=[0x2dfece0]
public: struct std::_Container_proxy * __thiscall SIMPL_NS::EalStdAllocator<struct std::_Container_proxy,1111490559>::allocate(unsigned int,void const *);

// address=[0x2e14590]
public: unsigned int __thiscall SIMPL_NS::EalStdAllocator<struct std::_Tree_node<struct std::pair<int const ,unsigned __int64>,void *>,1111490559>::max_size(void)const;

// address=[0x2e1aff0]
_vsnprintf_s;

// address=[0x2ebf05e]
_BCryptOpenAlgorithmProvider@16;

// address=[0x2ebf064]
_BCryptGetProperty@24;

// address=[0x2ebf06a]
_BCryptSetProperty@20;

// address=[0x2ebf070]
_BCryptCloseAlgorithmProvider@8;

// address=[0x2ebf076]
_BCryptGenerateSymmetricKey@28;

// address=[0x2ebf07c]
_BCryptGenerateKeyPair@16;

// address=[0x2ebf082]
_BCryptEncrypt@40;

// address=[0x2ebf088]
_BCryptDecrypt@40;

// address=[0x2ebf08e]
_BCryptExportKey@28;

// address=[0x2ebf094]
_BCryptImportKeyPair@28;

// address=[0x2ebf09a]
_BCryptFinalizeKeyPair@8;

// address=[0x2ebf0a0]
_BCryptDestroyKey@4;

// address=[0x2ebf0a6]
_BCryptDestroySecret@4;

// address=[0x2ebf0ac]
_BCryptVerifySignature@28;

// address=[0x2ebf0b2]
_BCryptSecretAgreement@16;

// address=[0x2ebf0b8]
_BCryptDeriveKey@28;

// address=[0x2ebf0be]
_BCryptCreateHash@28;

// address=[0x2ebf0c4]
_BCryptHashData@16;

// address=[0x2ebf0ca]
_BCryptFinishHash@16;

// address=[0x2ebf0d0]
_BCryptDestroyHash@4;

// address=[0x2ebf0d6]
_BCryptGenRandom@16;

// address=[0x2ebf0dc]
_NCryptSignHash@32;

// address=[0x2ebf0e2]
_NCryptFreeObject@4;

// address=[0x2ebf0e8]
_CertOpenStore@20;

// address=[0x2ebf0ee]
_CertCloseStore@8;

// address=[0x2ebf0f4]
_CertEnumCertificatesInStore@8;

// address=[0x2ebf0fa]
_CertFreeCertificateContext@4;

// address=[0x2ebf100]
_CertGetCertificateContextProperty@16;

// address=[0x2ebf106]
_CryptAcquireCertificatePrivateKey@24;

// address=[0x2ed6af0]
int __cdecl strncpy_s<256>(char (&)[256],char const *,unsigned int);

// address=[0x2ed6b30]
int __cdecl strncpy_s<1024>(char (&)[1024],char const *,unsigned int);

// address=[0x2eee87a]
_UPLAY_USER_GetNameUtf8;

// address=[0x2eee880]
_UPLAY_USER_SetGameSession;

// address=[0x2eee886]
_UPLAY_USER_ClearGameSession;

// address=[0x2eee88c]
_UPLAY_USER_IsInOfflineMode;

// address=[0x2eee892]
_UPLAY_USER_GetTicketUtf8;

// address=[0x2eee898]
_UPLAY_FRIENDS_Init;

// address=[0x2eee89e]
_UPLAY_FRIENDS_ShowInviteFriendsToGameUI;

// address=[0x2eee8a4]
_UPLAY_PARTY_Init;

// address=[0x2eee8aa]
_UPLAY_Start;

// address=[0x2eee8b0]
_UPLAY_GetNextEvent;

// address=[0x2eee8b6]
_UPLAY_Update;

// address=[0x2eee8bc]
_UPLAY_Quit;

// address=[0x2eee8c2]
_UPLAY_HasOverlappedOperationCompleted;

// address=[0x2eee8c8]
_UPLAY_GetOverlappedOperationResult;

// address=[0x2eee8ce]
_UPLAY_ACH_ReleaseAchievementList;

// address=[0x2eee8d4]
_UPLAY_AVATAR_Release;

// address=[0x2eee8da]
_UPLAY_USER_ReleaseCdKeyList;

// address=[0x2eee8e0]
_UPLAY_USER_ReleaseConsumeItemResult;

// address=[0x2eee8e6]
_UPLAY_USER_ReleaseProfile;

// address=[0x2eee8ec]
_UPLAY_SAVE_ReleaseGameList;

// address=[0x2eee8f2]
_UPLAY_STORE_ReleaseProductsList;

// address=[0x2eee8f8]
_UPLAY_WIN_ReleaseActionList;

// address=[0x2eee8fe]
_UPLAY_WIN_ReleaseRewardList;

// address=[0x2eee904]
_UPLAY_GetLastError;

// address=[0x2eee90a]
_UPLAY_ACH_GetAchievements;

// address=[0x2eee910]
_UPLAY_ACH_EarnAchievement;

// address=[0x2eee916]
_UPLAY_AVATAR_Get;

// address=[0x2eee91c]
_UPLAY_USER_GetCdKeys;

// address=[0x2eee922]
_UPLAY_USER_GetCdKeyUtf8;

// address=[0x2eee928]
_UPLAY_USER_GetAccountIdUtf8;

// address=[0x2eee92e]
_UPLAY_USER_GetEmailUtf8;

// address=[0x2eee934]
_UPLAY_USER_IsOwned;

// address=[0x2eee93a]
_UPLAY_USER_GetConsumableItems;

// address=[0x2eee940]
_UPLAY_USER_ConsumeItem;

// address=[0x2eee946]
_UPLAY_USER_GetCPUScore;

// address=[0x2eee94c]
_UPLAY_USER_GetGPUScore;

// address=[0x2eee952]
_UPLAY_USER_GetGPUScoreConfidenceLevel;

// address=[0x2eee958]
_UPLAY_USER_GetProfile;

// address=[0x2eee95e]
_UPLAY_PRESENCE_SetPresence;

// address=[0x2eee964]
_UPLAY_FRIENDS_GetFriendList;

// address=[0x2eee96a]
_UPLAY_FRIENDS_RequestFriendship;

// address=[0x2eee970]
_UPLAY_FRIENDS_IsFriend;

// address=[0x2eee976]
_UPLAY_FRIENDS_AddToBlackList;

// address=[0x2eee97c]
_UPLAY_FRIENDS_RemoveFromBlackList;

// address=[0x2eee982]
_UPLAY_FRIENDS_IsBlackListed;

// address=[0x2eee988]
_UPLAY_FRIENDS_ShowFriendSelectionUI;

// address=[0x2eee98e]
_UPLAY_FRIENDS_InviteToGame;

// address=[0x2eee994]
_UPLAY_FRIENDS_AddPlayedWith;

// address=[0x2eee99a]
_UPLAY_FRIENDS_RemoveFriendship;

// address=[0x2eee9a0]
_UPLAY_METADATA_SetSingleEventTag;

// address=[0x2eee9a6]
_UPLAY_METADATA_SetContinuousTag;

// address=[0x2eee9ac]
_UPLAY_METADATA_ClearContinuousTag;

// address=[0x2eee9b2]
_UPLAY_OVERLAY_Show;

// address=[0x2eee9b8]
_UPLAY_OVERLAY_SetShopUrl;

// address=[0x2eee9be]
_UPLAY_OVERLAY_ShowBrowserUrl;

// address=[0x2eee9c4]
_UPLAY_OVERLAY_ShowShopUrl;

// address=[0x2eee9ca]
_UPLAY_OVERLAY_ShowNotification;

// address=[0x2eee9d0]
_UPLAY_PARTY_InviteToParty;

// address=[0x2eee9d6]
_UPLAY_PARTY_RespondToGameInvite;

// address=[0x2eee9dc]
_UPLAY_PARTY_ShowGameInviteOverlayUI;

// address=[0x2eee9e2]
_UPLAY_PARTY_GetInGameMemberList;

// address=[0x2eee9e8]
_UPLAY_PARTY_GetFullMemberList;

// address=[0x2eee9ee]
_UPLAY_PARTY_SetUserData;

// address=[0x2eee9f4]
_UPLAY_PARTY_IsInParty;

// address=[0x2eee9fa]
_UPLAY_PARTY_IsPartyLeader;

// address=[0x2eeea00]
_UPLAY_PARTY_GetId;

// address=[0x2eeea06]
_UPLAY_PARTY_PromoteToLeader;

// address=[0x2eeea0c]
_UPLAY_PARTY_InvitePartyToGame;

// address=[0x2eeea12]
_UPLAY_SAVE_GetSavegames;

// address=[0x2eeea18]
_UPLAY_SAVE_Open;

// address=[0x2eeea1e]
_UPLAY_SAVE_Close;

// address=[0x2eeea24]
_UPLAY_SAVE_Read;

// address=[0x2eeea2a]
_UPLAY_SAVE_Write;

// address=[0x2eeea30]
_UPLAY_SAVE_SetName;

// address=[0x2eeea36]
_UPLAY_SAVE_Remove;

// address=[0x2eeea3c]
_UPLAY_STORE_GetProducts;

// address=[0x2eeea42]
_UPLAY_STORE_Checkout;

// address=[0x2eeea48]
_UPLAY_STORE_ShowProductDetails;

// address=[0x2eeea4e]
_UPLAY_WIN_SetActionsCompleted;

// address=[0x2eeea54]
_UPLAY_WIN_GetActions;

// address=[0x2eeea5a]
_UPLAY_WIN_GetRewards;

// address=[0x2eeea60]
_UPLAY_WIN_GetUnitBalance;

// address=[0x2eeea66]
_UPLAY_WIN_RefreshActions;

// address=[0x2eeea6c]
_UPLAY_SetLanguage;

// address=[0x2eeea72]
_GetExitCodeProcess@8;

// address=[0x2eeea78]
_CreateProcessW@40;

// address=[0x2eeea7e]
_CreateFileA@28;

// address=[0x2eeea84]
_ReadFile@20;

// address=[0x2eeea8a]
_SetFilePointer@16;

// address=[0x2eeea90]
_WriteFile@20;

// address=[0x2eeea96]
_CloseHandle@4;

// address=[0x2eeea9c]
_GetCommandLineA@0;

// address=[0x2eeeaa2]
_GetEnvironmentVariableW@12;

// address=[0x2eeeaa8]
_SetCurrentDirectoryA@4;

// address=[0x2eeeaae]
_SetCurrentDirectoryW@4;

// address=[0x2eeeab4]
_GetCurrentDirectoryW@8;

// address=[0x2eeeaba]
_CreateDirectoryW@8;

// address=[0x2eeeac0]
_DeleteFileW@4;

// address=[0x2eeeac6]
_FindClose@4;

// address=[0x2eeeacc]
_FindFirstFileW@8;

// address=[0x2eeead2]
_FindNextFileW@8;

// address=[0x2eeead8]
_GetFileAttributesW@4;

// address=[0x2eeeade]
_SetFileAttributesW@8;

// address=[0x2eeeae4]
_GetModuleFileNameW@12;

// address=[0x2eeeaea]
_CopyFileW@12;

// address=[0x2eeeaf0]
_GetComputerNameA@8;

// address=[0x2eeeaf6]
_GetLocaleInfoA@16;

// address=[0x2eeeafc]
_GetLastError@0;

// address=[0x2eeeb02]
_OutputDebugStringA@4;

// address=[0x2eeeb08]
_GetDriveTypeA@4;

// address=[0x2eeeb0e]
_GlobalAlloc@8;

// address=[0x2eeeb14]
_GlobalLock@4;

// address=[0x2eeeb1a]
_GlobalUnlock@4;

// address=[0x2eeeb20]
_QueryPerformanceCounter@4;

// address=[0x2eeeb26]
_QueryPerformanceFrequency@4;

// address=[0x2eeeb2c]
_GetCurrentThread@0;

// address=[0x2eeeb32]
_SetThreadPriority@8;

// address=[0x2eeeb38]
_GetThreadPriority@4;

// address=[0x2eeeb3e]
_GetSystemInfo@4;

// address=[0x2eeeb44]
_GetVersionExA@4;

// address=[0x2eeeb4a]
_GlobalMemoryStatus@4;

// address=[0x2eeeb50]
_GetFileSize@8;

// address=[0x2eeeb56]
_MultiByteToWideChar@24;

// address=[0x2eeeb5c]
_CreateFileW@28;

// address=[0x2eeeb62]
_Sleep@4;

// address=[0x2eeeb68]
_FreeLibrary@4;

// address=[0x2eeeb6e]
_GetProcAddress@8;

// address=[0x2eeeb74]
_LoadLibraryA@4;

// address=[0x2eeeb7a]
_GetEnvironmentVariableA@12;

// address=[0x2eeeb80]
_RaiseException@16;

// address=[0x2eeeb86]
_InitializeCriticalSection@4;

// address=[0x2eeeb8c]
_EnterCriticalSection@4;

// address=[0x2eeeb92]
_LeaveCriticalSection@4;

// address=[0x2eeeb98]
_TryEnterCriticalSection@4;

// address=[0x2eeeb9e]
_DeleteCriticalSection@4;

// address=[0x2eeeba4]
_SetEvent@4;

// address=[0x2eeebaa]
_ResetEvent@4;

// address=[0x2eeebb0]
_WaitForSingleObject@8;

// address=[0x2eeebb6]
_CreateEventA@16;

// address=[0x2eeebbc]
_GetCurrentProcess@0;

// address=[0x2eeebc2]
_GetCurrentProcessId@0;

// address=[0x2eeebc8]
_GetCurrentThreadId@0;

// address=[0x2eeebce]
_GlobalFree@4;

// address=[0x2eeebd4]
_SetThreadAffinityMask@8;

// address=[0x2eeebda]
_GetUserPreferredUILanguages@16;

// address=[0x2eeebe0]
_GetLocaleInfoEx@16;

// address=[0x2eeebe6]
_SetLastError@4;

// address=[0x2eeebec]
_FormatMessageA@28;

// address=[0x2eeebf2]
_GetTickCount64@0;

// address=[0x2eeebf8]
_InitializeCriticalSectionEx@12;

// address=[0x2eeebfe]
_SleepEx@8;

// address=[0x2eeec04]
_WaitForSingleObjectEx@12;

// address=[0x2eeec0a]
_ExpandEnvironmentStringsA@12;

// address=[0x2eeec10]
_VerSetConditionMask@16;

// address=[0x2eeec16]
_VerifyVersionInfoA@16;

// address=[0x2eeec1c]
_GetStdHandle@4;

// address=[0x2eeec22]
_GetFileType@4;

// address=[0x2eeec28]
_GetModuleHandleW@4;

// address=[0x2eeec2e]
_WideCharToMultiByte@32;

// address=[0x2eeec34]
_GetSystemTime@4;

// address=[0x2eeec3a]
_SystemTimeToFileTime@8;

// address=[0x2eeec40]
_GetTickCount@0;

// address=[0x2eeec46]
_LoadLibraryW@4;

// address=[0x2eeec4c]
_FlushConsoleInputBuffer@4;

// address=[0x2eeec52]
_DecodePointer@4;

// address=[0x2eeec58]
_VirtualQuery@12;

// address=[0x2eeec5e]
_DeleteFileA@4;

// address=[0x2eeec64]
_FlushFileBuffers@4;

// address=[0x2eeec6a]
_GetFileAttributesA@4;

// address=[0x2eeec70]
_GetFileSizeEx@8;

// address=[0x2eeec76]
_SetFilePointerEx@20;

// address=[0x2eeec7c]
_OpenThread@12;

// address=[0x2eeec82]
_ResumeThread@4;

// address=[0x2eeec88]
_MessageBoxA@16;

// address=[0x2eeec8e]
_GetMessageA@16;

// address=[0x2eeec94]
_TranslateMessage@4;

// address=[0x2eeec9a]
_DispatchMessageA@4;

// address=[0x2eeeca0]
_PeekMessageA@20;

// address=[0x2eeeca6]
_DefWindowProcA@16;

// address=[0x2eeecac]
_GetKeyState@4;

// address=[0x2eeecb2]
_GetAsyncKeyState@4;

// address=[0x2eeecb8]
_SetCursorPos@8;

// address=[0x2eeecbe]
_ClientToScreen@8;

// address=[0x2eeecc4]
_GetWindowInfo@8;

// address=[0x2eeecca]
_wsprintfA;

// address=[0x2eeecd0]
_wsprintfW;

// address=[0x2eeecd6]
_RegisterClassExA@4;

// address=[0x2eeecdc]
_CreateWindowExA@48;

// address=[0x2eeece2]
_DestroyWindow@4;

// address=[0x2eeece8]
_ShowWindow@8;

// address=[0x2eeecee]
_GetActiveWindow@0;

// address=[0x2eeecf4]
_GetLastActivePopup@4;

// address=[0x2eeecfa]
_LoadCursorA@8;

// address=[0x2eeed00]
_LoadIconA@8;

// address=[0x2eeed06]
_OpenClipboard@4;

// address=[0x2eeed0c]
_CloseClipboard@0;

// address=[0x2eeed12]
_SetClipboardData@8;

// address=[0x2eeed18]
_GetClipboardData@4;

// address=[0x2eeed1e]
_EmptyClipboard@0;

// address=[0x2eeed24]
_PostQuitMessage@4;

// address=[0x2eeed2a]
_SetWindowPos@28;

// address=[0x2eeed30]
_DialogBoxParamA@20;

// address=[0x2eeed36]
_GetWindowLongA@8;

// address=[0x2eeed3c]
_SetWindowLongA@12;

// address=[0x2eeed42]
_GetClientRect@8;

// address=[0x2eeed48]
_GetCursorPos@4;

// address=[0x2eeed4e]
_ScreenToClient@8;

// address=[0x2eeed54]
_OffsetRect@12;

// address=[0x2eeed5a]
_MonitorFromWindow@8;

// address=[0x2eeed60]
_GetMonitorInfoA@8;

// address=[0x2eeed66]
_GetDC@4;

// address=[0x2eeed6c]
_ReleaseDC@8;

// address=[0x2eeed72]
_LoadImageA@24;

// address=[0x2eeed78]
_EndDialog@8;

// address=[0x2eeed7e]
_SetDlgItemTextA@12;

// address=[0x2eeed84]
_GetDlgItemTextA@16;

// address=[0x2eeed8a]
_IsDlgButtonChecked@8;

// address=[0x2eeed90]
_SetCapture@4;

// address=[0x2eeed96]
_ReleaseCapture@0;

// address=[0x2eeed9c]
_GetProcessWindowStation@0;

// address=[0x2eeeda2]
_GetUserObjectInformationW@20;

// address=[0x2eeeda8]
_MessageBoxW@16;

// address=[0x2eeedae]
_UnregisterClassA@8;

// address=[0x2eeedb4]
_CreateSolidBrush@4;

// address=[0x2eeedba]
_LineDDA@24;

// address=[0x2eeedc0]
_BitBlt@36;

// address=[0x2eeedc6]
_CreateCompatibleBitmap@12;

// address=[0x2eeedcc]
_CreateCompatibleDC@4;

// address=[0x2eeedd2]
_DeleteDC@4;

// address=[0x2eeedd8]
_DeleteObject@4;

// address=[0x2eeedde]
_GetDIBits@28;

// address=[0x2eeede4]
_SelectObject@8;

// address=[0x2eeedea]
_GetObjectA@12;

// address=[0x2eeedf0]
_RegCloseKey@4;

// address=[0x2eeedf6]
_RegCreateKeyExA@36;

// address=[0x2eeedfc]
_RegOpenKeyExA@20;

// address=[0x2eeee02]
_RegQueryValueExA@24;

// address=[0x2eeee08]
_GetUserNameA@8;

// address=[0x2eeee0e]
_DeregisterEventSource@4;

// address=[0x2eeee14]
_RegisterEventSourceW@8;

// address=[0x2eeee1a]
_ReportEventW@36;

// address=[0x2eeee20]
_CryptAcquireContextW@20;

// address=[0x2eeee26]
_CryptReleaseContext@8;

// address=[0x2eeee2c]
_CryptGenRandom@12;

// address=[0x2eeee32]
_StartTraceA@12;

// address=[0x2eeee38]
_ControlTraceA@20;

// address=[0x2eeee3e]
_OpenTraceW@4;

// address=[0x2eeee44]
_ProcessTrace@16;

// address=[0x2eeee4a]
_CloseTrace@8;

// address=[0x2eeee50]
_ShellExecuteA@24;

// address=[0x2eeee56]
_CoUninitialize@0;

// address=[0x2eeee5c]
_CoInitializeEx@8;

// address=[0x2eeee62]
_CoCreateInstance@20;

// address=[0x2eeee68]
_StringFromGUID2@12;

// address=[0x2eeee6e]
_CoCreateGuid@4;

// address=[0x2eeee74]
_PropVariantClear@4;

// address=[0x2eeee7a]
_CoTaskMemFree@4;

// address=[0x2eeee80]
_SysFreeString@4;

// address=[0x2eeee86]
_SysStringLen@4;

// address=[0x2eeee8c]
_VariantInit@4;

// address=[0x2eeee92]
_VariantClear@4;

// address=[0x2efe0d0]
struct FilePaths::PathSplitResult __cdecl FilePaths::SplitPath(std::wstring const &);

// address=[0x2efe3b0]
std::wstring __cdecl FilePaths::GetCurrentWorkingDirectory(void);

// address=[0x2efe3e0]
std::wstring __cdecl FilePaths::GetUserDirectoryPath(void);

// address=[0x2efe550]
void __cdecl FilePaths::EnsurePathExists(std::wstring const &);

// address=[0x2efe8b0]
bool __cdecl FilePaths::FileExists(std::wstring const &);

// address=[0x2f025d0]
void __cdecl __vcrt_va_start_verify_argument_type<int>(void);

// address=[0x2f025e0]
_vsprintf;

// address=[0x2f02610]
_LZHLCreateCompressor;

// address=[0x2f02650]
_LZHLCompressorCalcMaxBuf;

// address=[0x2f02670]
_LZHLCompress;

// address=[0x2f02690]
_LZHLDestroyCompressor;

// address=[0x2f026d0]
_LZHLCreateDecompressor;

// address=[0x2f02720]
_LZHLDecompress;

// address=[0x2f02740]
_LZHLDestroyDecompressor;

// address=[0x2f03690]
unsigned int __stdcall Adler32(void const *,unsigned int,unsigned int);

// address=[0x2f055d0]
public: bool __thiscall greater_ptr<class CDestructor>::operator()(class CDestructor * const &,class CDestructor * const &)const;

// address=[0x2f05d40]
unsigned int const & __cdecl BB::Max<unsigned int>(unsigned int const &,unsigned int const &);

// address=[0x2f11800]
public: void __thiscall cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Reset(void);

// address=[0x2f174d0]
void __cdecl AdvXMLParser::NormalizeWhiteSpaces(std::string &);

// address=[0x2f17580]
void __cdecl AdvXMLParser::TrimSpaces(std::string &);

// address=[0x2f17600]
void __cdecl AdvXMLParser::FillMap(void);

// address=[0x2f17760]
void __cdecl BreakInDebugger(void);

// address=[0x2f28260]
int __cdecl AdvXMLParser::HexDigitValue(char);

// address=[0x2f282d0]
bool __cdecl AdvXMLParser::IsAlpha(char);

// address=[0x2f28320]
bool __cdecl AdvXMLParser::IsAlphaDigit(char);

// address=[0x2f28380]
bool __cdecl AdvXMLParser::IsCombiningChar(char);

// address=[0x2f28390]
bool __cdecl AdvXMLParser::IsDigit(char);

// address=[0x2f283d0]
bool __cdecl AdvXMLParser::IsExtender(char);

// address=[0x2f28410]
bool __cdecl AdvXMLParser::IsHexDigit(char);

// address=[0x2f28480]
bool __cdecl AdvXMLParser::IsLetter(char);

// address=[0x2f28530]
bool __cdecl AdvXMLParser::IsNameChar(char);

// address=[0x2f285f0]
bool __cdecl AdvXMLParser::IsSpace(char);

// address=[0x2f28640]
bool __cdecl AdvXMLParser::IsXmlChar(char);

// address=[0x2f28690]
char __cdecl AdvXMLParser::LowCase(char);

// address=[0x2f2a440]
unsigned long __cdecl _calcHash(unsigned char const *);

// address=[0x2f2bce0]
void __cdecl shellSort(struct HuffStatTmpStruct *,int);

// address=[0x2f2c320]
int __cdecl operator<(struct HuffStatTmpStruct const &,struct HuffStatTmpStruct const &);

// address=[0x2f2c980]
int __cdecl cmpHuffStatTmpStruct(struct HuffStatTmpStruct const &,struct HuffStatTmpStruct const &);

// address=[0x2f2d320]
void __cdecl AdvXMLParser::operator<<(class AdvXMLParser::Value,int);

// address=[0x2f2d360]
void __cdecl AdvXMLParser::operator<<(class AdvXMLParser::Value,unsigned int);

// address=[0x2f2d3a0]
void __cdecl AdvXMLParser::operator<<(class AdvXMLParser::Value,double);

// address=[0x2f2d3f0]
char * __cdecl AdvXMLParser::Int2Chars(int,char *,int);

// address=[0x2f2d880]
void __stdcall BBSupportActivateDbgReportHook(void);

// address=[0x2f2d8c0]
int __stdcall BBSupportDbgReport(int,char const *,unsigned int,char const *);

// address=[0x2f2df30]
int __cdecl BBSupportDbgReportF(int,char const *,unsigned int,char const *,...);

// address=[0x2f2dfe0]
void __stdcall BBSupportWarningMessageBoxes(bool);

// address=[0x2f2e210]
void __stdcall BBSupportOpenTraceFile(int,wchar_t const *);

// address=[0x2f2e270]
void __stdcall BBSupportSmartOpenTraceFile(wchar_t const *,wchar_t const *);

// address=[0x2f2e770]
bool __stdcall BBSupportGetTraceFilePath(wchar_t *,unsigned int);

// address=[0x2f2e7d0]
void __stdcall BBSupportTracePrint(unsigned int,char const *);

// address=[0x2f2ea40]
void __stdcall BBSupportTracePrint(unsigned int,wchar_t const *);

// address=[0x2f2ecc0]
void __cdecl BBSupportTracePrintF(unsigned int,char const *,...);

// address=[0x2f2ed60]
unsigned int __stdcall BBSupportReserveTraceLevel(void);

// address=[0x2f2edb0]
void __stdcall BBSupportEnableTraceLevel(unsigned int);

// address=[0x2f2ee20]
void __stdcall BBSupportDisableTraceLevel(unsigned int);

// address=[0x2f2f800]
void __stdcall BBSupportLib::BBSCopyString<wchar_t>(wchar_t *,wchar_t const *,unsigned int);

// address=[0x2f2f9e0]
int __stdcall BBSupportLib::BBSGetDevelopmentFlags(void);

// address=[0x2f2fa10]
bool __cdecl BBSupportLib::BBSIsNumber(char);

// address=[0x2f2fa40]
unsigned int __cdecl BBSupportLib::BBSNumberValue(char);

// address=[0x2f2fa80]
unsigned int __stdcall BBSupportDllVersion(void);

// address=[0x2f2fa90]
char const * __cdecl BBSupportDllVersionString(void);

// address=[0x2f2faa0]
void __stdcall BBSupportSetErrorHandlingMode(int);

// address=[0x2f2fb40]
bool __stdcall BBSupportIsDevelopmentMachine(void);

// address=[0x2f2fca0]
unsigned int __stdcall BBSupportDevelopmentMachineId(void);

// address=[0x2f2fe10]
unsigned int __stdcall BBSupportGetModuleTimeDateStamp(void *);

// address=[0x2f2feb0]
wchar_t const * __stdcall BBSupportLib::BBSGetFileNameFromFilePath(wchar_t const *);

// address=[0x2f2ff70]
unsigned int __stdcall BBSupportLib::BBSGetModuleFileDir(struct HINSTANCE__ *,wchar_t *,unsigned int);

// address=[0x2f30040]
unsigned int __stdcall BBSupportLib::BBSGetModuleFileName(struct HINSTANCE__ *,wchar_t *,unsigned int);

// address=[0x2f30160]
bool __stdcall BBSupportLib::BBSIsDirectory(wchar_t const *);

// address=[0x2f301d0]
int __stdcall BBSupportLib::BBSGetDevelopmentFlagsEx(void);

// address=[0x2f30370]
int __stdcall BBSupportLib::BBSGetSupportFlagsEx(void);

// address=[0x2f30410]
bool __stdcall BBSupportLib::BBSIsDevelopmentMachine(void);

// address=[0x2f30470]
bool __stdcall BBSupportLib::BBSIsFullscreenWindow(struct HWND__ *);

// address=[0x2f30510]
void __stdcall BBSupportLib::BBSCopyTextToClipboard(char const *);

// address=[0x2f305b0]
void __stdcall BBSupportLib::BBSCopyTextToClipboard(wchar_t const *);

// address=[0x2f30ca0]
void __stdcall BBSupportLib::BBSCopyString<char>(char *,char const *,unsigned int);

// address=[0x2f30da0]
int __stdcall BBSupportLoadDbgHelpDll(int);

// address=[0x2f30e00]
void __stdcall BBSupportTraceDumpModules(void);

// address=[0x2f31050]
bool __stdcall BBSupportLib::BBSSymbolHandlerInitialized(void);

// address=[0x2f31080]
void * __stdcall BBSupportLib::BBSSymbolHandlerProcessHandle(void);

// address=[0x2f310b0]
int __stdcall BBSupportLib::BBSGetSymbolAndLine(char *,unsigned int);

// address=[0x2f312e0]
bool __stdcall BBSupportLib::BBSTraceStackDump(void);

// address=[0x2f32070]
bool __cdecl TGetProcAddress<int __stdcall(unsigned long,void *,void *,struct _tagSTACKFRAME *,void *,int (__stdcall*)(void *,unsigned long,void *,unsigned long,unsigned long *),void * (__stdcall*)(void *,unsigned long),unsigned long (__stdcall*)(void *,unsigned long),unsigned long (__stdcall*)(void *,void *,struct _tagADDRESS *))>(int (__stdcall*&)(unsigned long,void *,void *,struct _tagSTACKFRAME *,void *,int (__stdcall*)(void *,unsigned long,void *,unsigned long,unsigned long *),void * (__stdcall*)(void *,unsigned long),unsigned long (__stdcall*)(void *,unsigned long),unsigned long (__stdcall*)(void *,void *,struct _tagADDRESS *)),struct HINSTANCE__ *,char const *);

// address=[0x2f320c0]
bool __cdecl TGetProcAddress<int __stdcall(void *)>(int (__stdcall*&)(void *),struct HINSTANCE__ *,char const *);

// address=[0x2f32110]
bool __cdecl TGetProcAddress<int __stdcall(void *,unsigned long,unsigned long *,struct _IMAGEHLP_LINE *)>(int (__stdcall*&)(void *,unsigned long,unsigned long *,struct _IMAGEHLP_LINE *),struct HINSTANCE__ *,char const *);

// address=[0x2f32160]
bool __cdecl TGetProcAddress<int __stdcall(void *,unsigned long,unsigned long *,struct _IMAGEHLP_SYMBOL *)>(int (__stdcall*&)(void *,unsigned long,unsigned long *,struct _IMAGEHLP_SYMBOL *),struct HINSTANCE__ *,char const *);

// address=[0x2f321b0]
bool __cdecl TGetProcAddress<int __stdcall(void *,char *,int)>(int (__stdcall*&)(void *,char *,int),struct HINSTANCE__ *,char const *);

// address=[0x2f32200]
bool __cdecl TGetProcAddress<int __stdcall(void *,wchar_t const *)>(int (__stdcall*&)(void *,wchar_t const *),struct HINSTANCE__ *,char const *);

// address=[0x2f32250]
bool __cdecl TGetProcAddress<unsigned long __stdcall(unsigned long)>(unsigned long (__stdcall*&)(unsigned long),struct HINSTANCE__ *,char const *);

// address=[0x2f322a0]
bool __cdecl TGetProcAddress<unsigned long __stdcall(void *,unsigned long)>(unsigned long (__stdcall*&)(void *,unsigned long),struct HINSTANCE__ *,char const *);

// address=[0x2f322f0]
bool __cdecl TGetProcAddress<struct API_VERSION * __stdcall(void)>(struct API_VERSION * (__stdcall*&)(void),struct HINSTANCE__ *,char const *);

// address=[0x2f32340]
bool __cdecl TGetProcAddress<void * __stdcall(void *,unsigned long)>(void * (__stdcall*&)(void *,unsigned long),struct HINSTANCE__ *,char const *);

// address=[0x2f32390]
void __stdcall BBSupportActivateUnhandledExceptionFilter(void);

// address=[0x2f323b0]
void __stdcall BBSupportActivateSETranslator(void);

// address=[0x2f33210]
void __cdecl SETranslator(unsigned int,struct _EXCEPTION_POINTERS *);

// address=[0x2f33610]
void __stdcall BBSupportActivateNewHandler(void);

// address=[0x2f33650]
void * __stdcall BBMalloc(unsigned int);

// address=[0x2f33680]
void __stdcall BBFree(void *);

// address=[0x2f34640]
int __stdcall BBSupportLib::BBSGetSupportFlags(void);

// address=[0x2f49cf0]
double __cdecl min(double,double);

// address=[0x2f5a380]
unsigned int __cdecl GetGfxInterfaceVersion(void);

// address=[0x2f5d0f0]
void __cdecl ConvertMapIndexToScreenPosition(int,int,int &,int &,int &,int &);

// address=[0x2f5d3a0]
void __cdecl ConvertMapIndexToScreenPosition(int,int,int &,int &);

// address=[0x2f5d520]
int __cdecl CalculateDistance(int,int,int,int);

// address=[0x2f5d550]
int __cdecl SearchMapPoint(int,int,int &,int &,bool);

// address=[0x2f5dd20]
void __cdecl InitGradientTable(void);

// address=[0x2f5dd60]
void __cdecl InitCamGradientTable(void);

// address=[0x2f5dda0]
void __cdecl RenderTmpText(void);

// address=[0x2f5dee0]
void __cdecl EnableCamRenderSettings(bool);

// address=[0x2f5f2f0]
int __cdecl CalcFinalHeightOffset(int);

// address=[0x2f5f320]
int __cdecl CalcStaticHeightOffset(int);

// address=[0x2f5f350]
int __cdecl CalcStaticHeightOffsetInt(int);

// address=[0x2f5f440]
void __cdecl Swap32Bit(void *,void *);

// address=[0x2f5f510]
bool __cdecl ReadTextureBitmap(int,void *,bool,bool);

// address=[0x2f5f640]
void __cdecl SetWindowPositionToRenderer(int,int);

// address=[0x2f5f660]
bool __cdecl BlitRenderedSurfaceToDIB(struct HWND__ *,struct HBITMAP__ *);

// address=[0x2f5f690]
bool __cdecl Initialize(void);

// address=[0x2f5f760]
bool __cdecl DeleteEngine(void);

// address=[0x2f5f7d0]
bool __cdecl HardwareIsRunning(void);

// address=[0x2f5f810]
bool __cdecl SoftwareIsRunning(void);

// address=[0x2f606c0]
bool __cdecl ReadTextureBitmapSet(bool,bool,bool,int);

// address=[0x2f608c0]
void __cdecl WriteError(int,char *);

// address=[0x2f62280]
bool __cdecl CheckConfiguration(struct SGfxRenderConfiguration &);

// address=[0x2f69ee0]
bool __cdecl BlitSettler(int,int,int,struct SGfxObjectInfo *);

// address=[0x2f6a540]
bool __cdecl BlitObject(int,int,int,struct SGfxObjectInfo *);

// address=[0x2f6a900]
bool __cdecl BlitVehicle(int,int,int,struct SGfxObjectInfo *);

// address=[0x2f6b180]
bool __cdecl BlitBuilding(int,int,int,struct SGfxObjectInfo *,int *,int &);

// address=[0x2f6c700]
bool __cdecl BlitBorderstone(int,int,int,int);

// address=[0x2f6c870]
bool __cdecl BlitAccessoryIcon(int,int,int,int);

// address=[0x2f6c9b0]
bool __cdecl BlitWave(int,int,int,int,int);

// address=[0x2f6cb10]
bool __cdecl RenderObjectLayer(bool);

// address=[0x2f6fab0]
int __cdecl EncodeImage(unsigned char *,unsigned char *,int,int);

// address=[0x2f71c50]
int __cdecl CalcCurrentFog(struct T_GFX_MAP_ELEMENT *);

// address=[0x2f71c80]
bool __cdecl FastIndexValidation(int);

// address=[0x2f71d20]
void __cdecl ZoomBobBuildState(void *,void *,int,int,int,int,int,void *,void *);

// address=[0x2f72630]
void __cdecl ZoomBobNormal(void *,void *,int,int,int,int,int,void *,int);

// address=[0x2f73b40]
bool __cdecl AddGuiPatches(void);

// address=[0x2f73f90]
void __cdecl AddDebugStrings(int);

// address=[0x2f744d0]
void __cdecl ClipGuiSurface(int);

// address=[0x2f750f0]
bool __cdecl DrawTexturedLandscapeDelta(int,int);

// address=[0x2f77130]
bool __cdecl DrawTexturedLandscape(int,int);

// address=[0x2f796a0]
bool __cdecl DrawCameraLandscape(int,int);

// address=[0x2f81f50]
void __cdecl CalcMaxHeights(struct T_GFX_MAP_ELEMENT *,int);

// address=[0x2f89640]
void __cdecl SetObjectMovement(int,int);

// address=[0x2f8be20]
struct tagDDDEVICEIDENTIFIER2 * __cdecl GetDeviceInfoPtr(void *);

// address=[0x2f8be90]
long __stdcall D3DEnumPixelFormatsCallback(struct _DDPIXELFORMAT *,void *);

// address=[0x2f8c570]
bool __cdecl DrawMiniMapLandscapeLayer(void);

// address=[0x2f8c950]
bool __cdecl DrawMiniMapObjectLayer(void);

// address=[0x2f8cc60]
bool __cdecl MarkCurrentArea(void);

// address=[0x2f8d020]
bool __cdecl DrawCompleteMiniMap(void);

// address=[0x2f8d5b0]
void __cdecl SetMiniMapGradient(void);

// address=[0x2f8d610]
void __cdecl SetMiniMapAreaSize(void);

// address=[0x2f8d670]
void __cdecl CalcMaxTimeStamps(void);

// address=[0x2f8d7b0]
void __cdecl GetNextLayer(void);

// address=[0x2f8eae0]
void __cdecl SetCrossingSystemMapAccess(int,struct T_GFX_MAP_ELEMENT *);

// address=[0x2f8eb10]
void __cdecl RefreshShading(int,bool);

// address=[0x2f8ec40]
bool __cdecl CheckField(int,int,int,int);

// address=[0x2f8efc0]
void __cdecl SetDarkLandFlag(int,int,bool,int &,int &);

// address=[0x2f8f090]
bool __cdecl EnsureFogging(int,int);

// address=[0x2f8f230]
void __cdecl EnsureDarkCrossingBit(int,int,int,bool);

// address=[0x2f90e70]
_TRI_init_engine;

// address=[0x2f90eea]
_TRI_calculate_LUT_from_palette;

// address=[0x2f90efa]
_TRI_set_window;

// address=[0x2f90f2b]
_TRI_draw_triangle;

// address=[0x2f90f6f]
clip_polygon_2d_2_xtras;

// address=[0x2f914f4]
calc_texture_polygon;

// address=[0x2f91b04]
calc_constant_slope_pow8;

// address=[0x2f91cac]
draw_texture_polygon;

// address=[0x2f92494]
_TRI_palette_LUT;

// address=[0x2f92498]
init_8bit_picture_palette;

// address=[0x2f924c8]
init_FPU;

// address=[0x2f92aa0]
void __cdecl InitRenderStates(void);

// address=[0x2f92ac0]
bool __cdecl BlitSettlerHardware(int,int,int,struct SGfxObjectInfo *);

// address=[0x2f93180]
bool __cdecl BlitWaveHardware(int,int,int,int,int);

// address=[0x2f932d0]
bool __cdecl BlitBuildingHardware(int,int,int,struct SGfxObjectInfo *,int *,int &);

// address=[0x2f951e0]
bool __cdecl BlitObjectHardware(int,int,int,struct SGfxObjectInfo *);

// address=[0x2f95660]
bool __cdecl BlitBorderstoneHardware(int,int,int,int);

// address=[0x2f957f0]
bool __cdecl BlitVehicleHardware(int,int,int,struct SGfxObjectInfo *);

// address=[0x2f96960]
bool __cdecl BlitAccessoryIconHardware(int,int,int,int);

// address=[0x2f96ac0]
void __cdecl RenderGfx(int,void *,void *,int,int,float,float,int,int,unsigned char,unsigned char);

// address=[0x2f97030]
bool __cdecl CacheRenderingStandard(void *,void *,int,int,int,int,float,float,unsigned int,int,int,unsigned char);

// address=[0x2f973b0]
void __cdecl FlushCacheList(void);

// address=[0x2f99880]
bool __cdecl GuiEngine2_EventProc(struct SEventStruct &);

// address=[0x2f9b750]
bool __cdecl IsTextControl(int);

// address=[0x2f9b7a0]
bool __cdecl CanHilightControl(int);

// address=[0x2f9b7f0]
bool __cdecl HasImage(int);

// address=[0x2f9b840]
int __cdecl GetSurfaceID(struct SGuiControl *);

// address=[0x2f9b870]
struct SGuiControl * __cdecl GetControlPtr(int,int);

// address=[0x2f9b8f0]
int __cdecl CalcSliderPosition(int,int,int,bool);

// address=[0x2f9b950]
int __cdecl CalcPercentageValue(int,int,int,bool);

// address=[0x2f9b9c0]
int __cdecl AddKeyStates(int);

// address=[0x2f9ba00]
bool __cdecl IsNonTransparentGuiArea(int,int);

// address=[0x2f9bc00]
bool __cdecl DeleteCharacter(unsigned char *,int);

// address=[0x2f9bd50]
bool __cdecl InsertCharacter(unsigned char *,int,int,int);

// address=[0x2f9bee0]
void __cdecl DoScrolling(struct SGuiControl *,int);

// address=[0x2f9c0c0]
bool __cdecl DrawControl(void *,unsigned int,int,int,struct SGuiControl *);

// address=[0x2f9cb10]
bool __cdecl DrawControlText(struct HDC__ *,struct SGuiControl *);

// address=[0x2f9d020]
bool __cdecl SetControlState(struct SGuiControl *,int,bool);

// address=[0x2f9d1b0]
void __cdecl ChangeMultisliders(struct SGuiControl *,int);

// address=[0x2f9d3c0]
void __cdecl EnsureMultisliders(struct SGuiControl *);

// address=[0x2f9d580]
bool __cdecl CanLockMultislider(struct SGuiControl *);

// address=[0x2f9d670]
void __cdecl StoreMultisliderSettings(struct SGuiControl *);

// address=[0x2f9d720]
void __cdecl RestoreMultisliderSettings(struct SGuiControl *);

// address=[0x2f9d850]
bool __cdecl SelectRadioGroup(struct SGuiControl *);

// address=[0x2f9d9b0]
bool __cdecl FindControlUnderCursor(int,int,struct SGuiControl * &,int &,int &);

// address=[0x2f9dc20]
bool __cdecl FindDialogUnderCursor(int,int,struct GUI_MENU_DIALOG_HEADER * &);

// address=[0x2f9dce0]
void __cdecl UpdateGui(int);

// address=[0x2f9e2c0]
void __cdecl CalcCharWidths(struct SGuiControl *);

// address=[0x2f9e430]
bool __cdecl SelectEditControl(struct SGuiControl *,int);

// address=[0x2f9e5e0]
bool __cdecl IsValidInput(int,int);

// address=[0x2f9fe90]
unsigned int __cdecl GetGuiInterfaceVersion(void);

// address=[0x2fa2f90]
bool __cdecl CalcTextSize(int,char *,struct tagSIZE &,int,int);

// address=[0x2fa4040]
void __cdecl InitTables(void);

// address=[0x2fa4150]
void __cdecl FastBlit(void *,int,int,int,int,int,void *,int,int,int);

// address=[0x2fa4300]
void __cdecl FastBlit8Bit(void *,int,int,int,int,int,void *,int,int,int,void *);

// address=[0x2fa4580]
void __cdecl UnpackGfx(void *,void *,void *,int,int,int);

// address=[0x2fa4990]
void __cdecl UnpackGfxTransparent(void *,void *,void *,int,int,int);

// address=[0x2fa4b30]
void __cdecl UnpackGfxTransparentHiLight555(void *,void *,void *,int,int,int);

// address=[0x2fa4d10]
void __cdecl UnpackGfxTransparentHiLight565(void *,void *,void *,int,int,int);

// address=[0x2fa4ef0]
void __cdecl UnpackGfxTransparentGrayed555(void *,void *,void *,int,int,int);

// address=[0x2fa50c0]
void __cdecl UnpackGfxTransparentGrayed565(void *,void *,void *,int,int,int);

// address=[0x2fa5290]
void __cdecl FastRectangle(unsigned short *,int,int,int,int,int,unsigned short);

// address=[0x2fa5350]
void __cdecl FastHLine(unsigned short *,int,int,int,int,unsigned short);

// address=[0x2fa53e0]
void __cdecl FastVLine(unsigned short *,int,int,int,int,unsigned short);

// address=[0x2fa5470]
void __cdecl FastRaster(void *,int,int,int,int,int,int);

// address=[0x2fa55c0]
void __cdecl FastRasterSolid(void *,int,int,int,int,int,int,int);

// address=[0x2fa5d40]
_lua_setstate;

// address=[0x2fa5d60]
_lua_settagmethod;

// address=[0x2fa5d90]
_lua_gettagmethod;

// address=[0x2fa5db0]
_lua_settag;

// address=[0x2fa5e50]
_lua_callfunction;

// address=[0x2fa5ec0]
_lua_beginblock;

// address=[0x2fa5f40]
_lua_endblock;

// address=[0x2fa5fa0]
_lua_lua2C;

// address=[0x2fa5fd0]
_lua_isnil;

// address=[0x2fa6010]
_lua_istable;

// address=[0x2fa6050]
_lua_isuserdata;

// address=[0x2fa6090]
_lua_iscfunction;

// address=[0x2fa60c0]
_lua_isnumber;

// address=[0x2fa6130]
_lua_isstring;

// address=[0x2fa6170]
_lua_isfunction;

// address=[0x2fa61b0]
_lua_getnumber;

// address=[0x2fa6220]
_lua_getstring;

// address=[0x2fa6290]
_lua_strlen;

// address=[0x2fa6300]
_lua_getcfunction;

// address=[0x2fa6340]
_lua_getuserdata;

// address=[0x2fa6380]
_lua_pushnil;

// address=[0x2fa63d0]
_lua_pushnumber;

// address=[0x2fa6430]
_lua_pushlstring;

// address=[0x2fa64a0]
_lua_pushstring;

// address=[0x2fa64d0]
_lua_pushcclosure;

// address=[0x2fa6550]
_lua_pushusertag;

// address=[0x2fa65d0]
_lua_pushobject;

// address=[0x2fa6640]
_lua_pop;

// address=[0x2fa6660]
_lua_getglobal;

// address=[0x2fa6690]
_lua_rawgetglobal;

// address=[0x2fa66c0]
_lua_setglobal;

// address=[0x2fa66f0]
_lua_rawsetglobal;

// address=[0x2fa6740]
_lua_settable;

// address=[0x2fa6780]
_lua_rawsettable;

// address=[0x2fa67b0]
_lua_gettable;

// address=[0x2fa67d0]
_lua_rawgettable;

// address=[0x2fa6860]
_lua_tag;

// address=[0x2fa6920]
_lua_nextvar;

// address=[0x2fa6990]
_lua_next;

// address=[0x2fa6a00]
_lua_ref;

// address=[0x2fa6a50]
_lua_getref;

// address=[0x2fa6a90]
_lua_createtable;

// address=[0x2fa6ac0]
_lua_seterrormethod;

// address=[0x2fa6b00]
_luaA_Address;

// address=[0x2fa6b30]
_luaA_pushobject;

// address=[0x2fa6b90]
_luaA_packresults;

// address=[0x2fa6bf0]
_luaA_passresults;

// address=[0x2fa6c10]
_luaA_nextvar;

// address=[0x2fa6cd0]
_luaA_next;

// address=[0x2fa6d40]
_lua_stackedfunction;

// address=[0x2fa6de0]
_lua_funcinfo;

// address=[0x2fa6e70]
_lua_currentline;

// address=[0x2fa6ec0]
_lua_getobjname;

// address=[0x2fa6f40]
_lua_getlocal;

// address=[0x2fa6fe0]
_lua_setlocal;

// address=[0x2fa70b0]
_lua_nups;

// address=[0x2fa7100]
_lua_setlinehook;

// address=[0x2fa7130]
_lua_setcallhook;

// address=[0x2fa7160]
_lua_setdebug;

// address=[0x2fa79e0]
_lua_open;

// address=[0x2fa7b70]
_lua_close;

// address=[0x2fa7d20]
_lua_error;

// address=[0x2fa7d70]
_lua_dofile;

// address=[0x2fa7ee0]
_lua_dostring;

// address=[0x2fa7f10]
_lua_dobuffer;

// address=[0x2fa7fa0]
_luaD_init;

// address=[0x2fa7ff0]
_luaD_adjusttop;

// address=[0x2fa8080]
_luaD_openstack;

// address=[0x2fa80f0]
_luaD_lineHook;

// address=[0x2fa81b0]
_luaD_callHook;

// address=[0x2fa82f0]
_luaD_calln;

// address=[0x2fa8520]
_luaD_callTM;

// address=[0x2fa8570]
_luaD_protectedrun;

// address=[0x2fa86a0]
_luaD_gcIM;

// address=[0x2fa8740]
_luaD_travstack;

// address=[0x2fa8790]
_luaD_checkstack;

// address=[0x2fa9060]
_luaO_equalval;

// address=[0x2fa91b0]
_luaO_redimension;

// address=[0x2fa9210]
_luaO_insertlist;

// address=[0x2fa9240]
_luaO_str2d;

// address=[0x2fa95f0]
_lua_iolibopen;

// address=[0x2faae00]
__vfscanf_l;

// address=[0x2faae40]
_fscanf;

// address=[0x2faae80]
_lua_strlibopen;

// address=[0x2faaea0]
_luaI_classend;

// address=[0x2faaf50]
_luaI_singlematch;

// address=[0x2facf70]
_luaL_openlib;

// address=[0x2facfc0]
_luaL_argerror;

// address=[0x2fad040]
_luaL_check_lstr;

// address=[0x2fad0a0]
_luaL_opt_lstr;

// address=[0x2fad0e0]
_luaL_check_number;

// address=[0x2fad130]
_luaL_opt_number;

// address=[0x2fad170]
_luaL_functionarg;

// address=[0x2fad1b0]
_luaL_tablearg;

// address=[0x2fad1f0]
_luaL_nonnullarg;

// address=[0x2fad230]
_luaL_verror;

// address=[0x2fad290]
_luaL_findstring;

// address=[0x2fad2e0]
_luaL_chunkid;

// address=[0x2fad3b0]
_luaL_filesource;

// address=[0x2fad500]
_luaF_newproto;

// address=[0x2fad590]
_luaF_newclosure;

// address=[0x2fad5f0]
_luaF_freeproto;

// address=[0x2fad630]
_luaF_freeclosure;

// address=[0x2fad680]
_luaF_getlocalname;

// address=[0x2fad7f0]
_lua_unref;

// address=[0x2fad820]
_lua_collectgarbage;

// address=[0x2fad940]
_luaC_checkGC;

// address=[0x2fad970]
_luaC_getref;

// address=[0x2fad9d0]
_luaC_ref;

// address=[0x2fadad0]
_luaC_hashcallIM;

// address=[0x2fadb10]
_luaC_strcallIM;

// address=[0x2fae150]
_luaM_realloc;

// address=[0x2fae1c0]
_luaM_growaux;

// address=[0x2fae290]
_luaS_init;

// address=[0x2fae310]
_luaS_createudata;

// address=[0x2fae350]
_luaS_collector;

// address=[0x2fae420]
_luaS_free;

// address=[0x2fae490]
_luaS_newlstr;

// address=[0x2fae4f0]
_luaS_new;

// address=[0x2fae510]
_luaS_newfixedstring;

// address=[0x2fae540]
_luaS_rawsetglobal;

// address=[0x2fae590]
_luaS_travsymbol;

// address=[0x2fae5d0]
_luaS_globaldefined;

// address=[0x2fae610]
_luaS_collectudata;

// address=[0x2fae6c0]
_luaS_freeall;

// address=[0x2faefa0]
_luaH_new;

// address=[0x2faf040]
_luaH_free;

// address=[0x2faf0b0]
_luaH_present;

// address=[0x2faf190]
_luaH_set;

// address=[0x2faf270]
_luaH_pos;

// address=[0x2faf2c0]
_luaH_setint;

// address=[0x2faf2f0]
_luaH_getint;

// address=[0x2faf730]
_lua_newtag;

// address=[0x2faf7a0]
_lua_copytagmethods;

// address=[0x2faf850]
_luaT_init;

// address=[0x2faf8c0]
_luaT_realtag;

// address=[0x2faf8f0]
_luaT_effectivetag;

// address=[0x2faf970]
_luaT_settagmethod;

// address=[0x2fafa80]
_luaT_gettagmethod;

// address=[0x2fafaf0]
_luaT_travtagmethods;

// address=[0x2fafdb0]
_luaV_pack;

// address=[0x2fafe50]
_luaV_tonumber;

// address=[0x2faff40]
_luaV_tostring;

// address=[0x2faffb0]
_luaV_setn;

// address=[0x2fb0000]
_luaV_gettable;

// address=[0x2fb0140]
_luaV_settable;

// address=[0x2fb0290]
_luaV_rawsettable;

// address=[0x2fb02f0]
_luaV_getglobal;

// address=[0x2fb03f0]
_luaV_setglobal;

// address=[0x2fb0510]
_luaV_execute;

// address=[0x2fb15a0]
_luaV_closure;

// address=[0x2fb1660]
_luaV_comparison;

// address=[0x2fb2100]
_luaB_predefine;

// address=[0x2fb3f80]
_luaX_init;

// address=[0x2fb3fd0]
_luaX_setinput;

// address=[0x2fb4040]
_luaX_lex;

// address=[0x2fb5870]
_luaX_syntaxerror;

// address=[0x2fb58e0]
_luaX_error;

// address=[0x2fb5910]
_luaX_token2str;

// address=[0x2fb6ee0]
_luaZ_Fopen;

// address=[0x2fb6f30]
_luaZ_sopen;

// address=[0x2fb6f60]
_luaZ_mopen;

// address=[0x2fb6fa0]
_luaZ_read;

// address=[0x2fb7180]
_luaY_parser;

// address=[0x2fbb020]
_luaU_undump1;

// address=[0x2fbb0b0]
_luaU_badconstant;

// address=[0x2fbb120]
_luaU_str2d;

// address=[0x2fbbb50]
_luaL_openspace;

// address=[0x2fbbb90]
_luaL_resetbuffer;

// address=[0x2fbbbb0]
_luaL_addchar;

// address=[0x2fbbc00]
_luaL_getsize;

// address=[0x2fbbc20]
_luaL_addsize;

// address=[0x2fbbc40]
_luaL_newbuffer;

// address=[0x2fbbc90]
_luaL_oldbuffer;

// address=[0x2fbbcc0]
_luaL_buffer;

// address=[0x2fbbdb0]
unsigned long __cdecl CalcChecksumOfFile(void *,int *);

// address=[0x2fbbe50]
int __cdecl GetMapAccessInterfaceVersion(void);

// address=[0x2fbbe60]
void __cdecl MA_OpenMapFile(wchar_t *,int *,int *,int);

// address=[0x2fbdbf0]
void __cdecl MA_CloseMapFile(void);

// address=[0x2fbdc00]
void __cdecl MA_IsCampaignMap(int *);

// address=[0x2fbdc10]
void __cdecl MA_IsEditorMap(int *);

// address=[0x2fbdc20]
void __cdecl MA_GetNumberOfPlayers(int *);

// address=[0x2fbdc50]
void __cdecl MA_GetNumberOfSetups(int *);

// address=[0x2fbdc80]
void __cdecl MA_GetMapData(int *,int *,int *,int *,int *);

// address=[0x2fbdd10]
void __cdecl MA_GetPlayerData(int,int,int *,int *,int *,wchar_t * *,wchar_t * *,int *,int *,int *);

// address=[0x2fbdf20]
void __cdecl MA_GetDataChecksums(int *,int *);

// address=[0x2fbdf60]
void __cdecl MA_GetDescriptionText(int,wchar_t * *);

// address=[0x2fbe080]
void __cdecl MA_GetPreviewMapRawData(int *,int *,struct tagVARIANT *);

// address=[0x2fbe0f0]
void __cdecl MA_GetMapProperty(int,int *);

// address=[0x2fbe180]
void __cdecl InitVariables(void);

// address=[0x2fbe220]
void __cdecl ReleaseMemory(void);

// address=[0x2fbfeb0]
unsigned int __cdecl Crc(unsigned char *,unsigned long);

// address=[0x2fbff00]
void __cdecl Cryption(unsigned char *,unsigned long);

// address=[0x2fbffd0]
int __cdecl CreateChunk(unsigned short,unsigned short,unsigned int,void *,int);

// address=[0x2fc0150]
bool __cdecl ReadChunk(void *,int,int);

// address=[0x2fc0340]
int __stdcall GetRandomMapGeneratorInterfaceVersion(void);

// address=[0x2fc0350]
void __cdecl InitRandomMap(class IMapGeneratorHost *,struct SRandomMapParams *);

// address=[0x2fc09f0]
void __cdecl CreatePreview(class IMapGeneratorHost *,unsigned short *,int);

// address=[0x2fc17f0]
bool __cdecl GenerateRandomMap(class IMapGeneratorHost *);

// address=[0x2fc3800]
void __cdecl repairHeights(void);

// address=[0x2fc3b90]
void __cdecl mirrorMapDiag(void);

// address=[0x2fc3c30]
void __cdecl mirrorMapOppDiag(void);

// address=[0x2fc3d10]
void __cdecl CreateBorder(int,int,int);

// address=[0x2fc3e40]
void __cdecl CreateSpeckledBorder(int,int,int);

// address=[0x2fc4140]
void __cdecl ChangeBorder(int,int);

// address=[0x2fc5260]
int __cdecl GetGroundType(int,int);

// address=[0x2fc52b0]
void __cdecl SetGroundType(int,int,int);

// address=[0x2fc52e0]
int __cdecl ValidateMapIndex(int,int);

// address=[0x2fc9950]
protected: __thiscall TPowerOf2Wrap<512>::TPowerOf2Wrap<512>(void);

// address=[0x2fc9970]
public: __thiscall TStaticFIFO<int,512>::TStaticFIFO<int,512>(void);

// address=[0x2fc99a0]
public: bool __thiscall TStaticFIFO<int,512>::Empty(void);

// address=[0x2fc99e0]
public: void __thiscall TStaticFIFO<int,512>::Init(void);

// address=[0x2fc9a10]
public: void __thiscall TStaticFIFO<int,512>::Pop(void);

// address=[0x2fc9a40]
public: void __thiscall TStaticFIFO<int,512>::Push(int const &);

// address=[0x2fc9a90]
public: int & __thiscall TStaticFIFO<int,512>::Top(void);

// address=[0x2fc9ab0]
protected: static int __cdecl TPowerOf2Wrap<512>::Wrap(int);

// address=[0x2fca4a0]
void __cdecl MakeRiverMouth(int,int);

// address=[0x2fca920]
int __cdecl CheckForRiverNeighbours(int,int,int);

// address=[0x2fcb540]
int __cdecl ValidateXMapIndex(int);

// address=[0x2fcb570]
int __cdecl ValidateYMapIndex(int);

// address=[0x2fcd3e0]
unsigned int __cdecl GetLibVersion(void);

// address=[0x2fcd3f0]
class IRTComp * __cdecl GetLibInstance(void);

// address=[0x2fd5540]
unsigned int __cdecl GetSoundInterfaceVersion(void);

// address=[0x2fdbab0]
void __stdcall PlaylistCallback(struct _STREAM *);

// address=[0x2fdbad0]
void __stdcall SoundCallback(struct _SAMPLE *);

// address=[0x2fdbaf0]
int __stdcall SoundEnumCallback(struct _GUID *,char const *,char const *,void *);

// address=[0x2fdea70]
__Lock_at_thread_exit_mutex;

// address=[0x2fdeaa0]
__Unlock_at_thread_exit_mutex;

// address=[0x2fdf430]
__Getcvt;

// address=[0x2fdf560]
__Wcrtomb;

// address=[0x2fdf660]
___Wcrtomb_lk;

// address=[0x2fdf690]
__Mbrtowc;

// address=[0x2fe05c0]
__Deletegloballocale;

// address=[0x2fe12c0]
__Getctype;

// address=[0x2fe13b0]
__Tolower;

// address=[0x2fe1620]
__Toupper;

// address=[0x2fe1c20]
__Stolx;

// address=[0x2fe1da0]
__Stoul;

// address=[0x2fe1dd0]
__Stoulx;

// address=[0x2fe20f0]
__Stoll;

// address=[0x2fe2120]
__Stollx;

// address=[0x2fe22e0]
__Stoull;

// address=[0x2fe2310]
__Stoullx;

// address=[0x2fe35a0]
__Mtx_clear_owner;

// address=[0x2fe35d0]
__Mtx_current_owns;

// address=[0x2fe3610]
__Mtx_destroy;

// address=[0x2fe3640]
__Mtx_destroy_in_situ;

// address=[0x2fe36a0]
__Mtx_getconcrtcs;

// address=[0x2fe36b0]
__Mtx_init;

// address=[0x2fe3720]
__Mtx_init_in_situ;

// address=[0x2fe3760]
__Mtx_lock;

// address=[0x2fe3780]
__Mtx_reset_owner;

// address=[0x2fe37b0]
__Mtx_timedlock;

// address=[0x2fe3820]
__Mtx_trylock;

// address=[0x2fe3890]
__Mtx_unlock;

// address=[0x2fe3930]
___set_stl_sync_api_mode;

// address=[0x2fe3c10]
__Query_perf_counter;

// address=[0x2fe3c30]
__Query_perf_frequency;

// address=[0x2fe3c50]
__Xtime_diff_to_millis;

// address=[0x2fe3ca0]
__Xtime_diff_to_millis2;

// address=[0x2fe3d40]
__Xtime_get_ticks;

// address=[0x2fe3f30]
_xtime_get;

// address=[0x2fe4230]
__Thrd_abort;

// address=[0x2fe4280]
__Thrd_create;

// address=[0x2fe4360]
__Thrd_current;

// address=[0x2fe43d0]
__Thrd_detach;

// address=[0x2fe4410]
__Thrd_equal;

// address=[0x2fe4440]
__Thrd_exit;

// address=[0x2fe4460]
__Thrd_hardware_concurrency;

// address=[0x2fe4480]
__Thrd_id;

// address=[0x2fe4490]
__Thrd_join;

// address=[0x2fe4510]
__Thrd_sleep;

// address=[0x2fe45d0]
__Thrd_start;

// address=[0x2fe4630]
__Thrd_yield;

// address=[0x2fe46f0]
__Getwctype;

// address=[0x2fe4740]
__Getwctypes;

// address=[0x2fe4770]
__Towlower;

// address=[0x2fe4820]
__Towupper;

// address=[0x2fe50a0]
__Cnd_broadcast;

// address=[0x2fe50c0]
__Cnd_destroy;

// address=[0x2fe50f0]
__Cnd_destroy_in_situ;

// address=[0x2fe5130]
__Cnd_init;

// address=[0x2fe51a0]
__Cnd_init_in_situ;

// address=[0x2fe51c0]
__Cnd_signal;

// address=[0x2fe51e0]
__Cnd_timedwait;

// address=[0x2fe5200]
__Cnd_wait;

// address=[0x2fe57c0]
__Mtxdst;

// address=[0x2fe57e0]
__Mtxinit;

// address=[0x2fe5800]
__Mtxlock;

// address=[0x2fe5820]
__Mtxunlock;

// address=[0x2fe58f0]
void __cdecl _Atexit(void (__cdecl*)(void));

// address=[0x30127a0]
__MallocaComputeSize;

// address=[0x30127e0]
__MarkAllocaS;

// address=[0x3012c90]
__freea_crt;

// address=[0x3014260]
__Cnd_do_broadcast_at_thread_exit;

// address=[0x30143c0]
__Cnd_register_at_thread_exit;

// address=[0x30144f0]
__Cnd_unregister_at_thread_exit;

// address=[0x3014610]
__Getcoll;

// address=[0x3014670]
__Strcoll;

// address=[0x30147d0]
__Getdateorder;

// address=[0x30148a0]
__Wcscoll;

// address=[0x3014a70]
__Wcsxfrm;

// address=[0x3014c10]
__Strxfrm;

// address=[0x3014d40]
_GetTableIndexFromLcid;

// address=[0x3014dc0]
_GetTableIndexFromLocaleName;

// address=[0x3015150]
___wcsnicmp_ascii;

// address=[0x30158b0]
void * __cdecl operator new(unsigned int);

// address=[0x3015910]
void __cdecl operator delete(void *);

// address=[0x3015930]
void __cdecl operator delete(void *,unsigned int);

// address=[0x3015b30]
_NtCurrentTeb;

// address=[0x3016090]
__onexit;

// address=[0x3016120]
_at_quick_exit;

// address=[0x30161c0]
@__security_check_cookie@4;

// address=[0x3016240]
void __stdcall `eh vector destructor iterator'(void *,unsigned int,int,void (*)(void *));

// address=[0x3016270]
void __stdcall `eh vector destructor iterator'(void *,unsigned int,unsigned int,void (*)(void *));

// address=[0x30163a0]
void __stdcall __ArrayUnwind(void *,unsigned int,unsigned int,void (*)(void *));

// address=[0x3016470]
void __cdecl operator delete[](void *,unsigned int);

// address=[0x3016490]
___raise_securityfailure;

// address=[0x30164d0]
___report_gsfailure;

// address=[0x3016620]
___report_rangecheckfailure;

// address=[0x3016630]
___report_securityfailure;

// address=[0x3016740]
___report_securityfailureEx;

// address=[0x30168b0]
__ftol2_sse;

// address=[0x30168b9]
__ftol2_pentium4;

// address=[0x30168cc]
__ftol2_sse_excpt;

// address=[0x30168f0]
__ftol2;

// address=[0x30169a0]
__alloca_probe;

// address=[0x30169a0]
__chkstk;

// address=[0x30169e0]
void * __cdecl operator new[](unsigned int);

// address=[0x3016d70]
__Init_thread_abort;

// address=[0x3016da0]
__Init_thread_footer;

// address=[0x3016e00]
__Init_thread_header;

// address=[0x3016e90]
__Init_thread_lock;

// address=[0x3016eb0]
__Init_thread_notify;

// address=[0x3016f20]
__Init_thread_unlock;

// address=[0x3016f40]
__Init_thread_wait;

// address=[0x3017030]
void __cdecl operator delete[](void *);

// address=[0x3017090]
__ftoui3;

// address=[0x301709f]
__ftoul3;

// address=[0x30170ae]
__ftol3;

// address=[0x30170bb]
__ftol3_NaN;

// address=[0x30170d3]
__ftol3_work;

// address=[0x3017159]
__ftol3_common;

// address=[0x301721b]
__ftol3_arg_error;

// address=[0x301722d]
__ftol3_except;

// address=[0x3017271]
__dtoui3;

// address=[0x3017280]
__dtoul3;

// address=[0x301728f]
__dtol3;

// address=[0x301729c]
__dtol3_NaN;

// address=[0x30172b9]
__dtol3_work;

// address=[0x30173a0]
__ultod3;

// address=[0x30173e0]
__ltod3;

// address=[0x30174f0]
__aullrem;

// address=[0x3017590]
__allmul;

// address=[0x30175e0]
__allshl;

// address=[0x3017610]
__allshr;

// address=[0x3017640]
__alldiv;

// address=[0x3017720]
__aulldiv;

// address=[0x30177b0]
__allrem;

// address=[0x3017cb0]
_WinMainCRTStartup;

// address=[0x3017cc0]
@_RTC_AllocaHelper@12;

// address=[0x3017d00]
@_RTC_CheckStackVars2@12;

// address=[0x3017e10]
@_RTC_CheckStackVars@8;

// address=[0x3017e80]
__RTC_CheckEsp;

// address=[0x3017ec0]
__CRT_RTC_INIT;

// address=[0x3017ed0]
__CRT_RTC_INITW;

// address=[0x3017ee0]
__RTC_InitBase;

// address=[0x3017f20]
__RTC_Shutdown;

// address=[0x3017f40]
__aullshr;

// address=[0x3017f70]
__alloca_probe_16;

// address=[0x3017f86]
__alloca_probe_8;

// address=[0x3018150]
void __cdecl _RTC_AllocaFailure(void *,struct _RTC_ALLOCA_NODE *,int);

// address=[0x30182c0]
void __cdecl _RTC_Failure(void *,int);

// address=[0x3018330]
void __cdecl _RTC_StackFailure(void *,char const *);

// address=[0x30187b0]
__RTC_UninitUse;

// address=[0x30188e0]
void * __cdecl operator new(unsigned int,struct std::nothrow_t const &);

// address=[0x3018980]
void * __cdecl operator new(unsigned int,int,char const *,int);

// address=[0x30189f0]
void * __cdecl operator new[](unsigned int,int,char const *,int);

// address=[0x3018a20]
void __cdecl operator delete(void *,int,char const *,int);

// address=[0x3018a40]
void __cdecl operator delete[](void *,int,char const *,int);

// address=[0x3018a70]
@_guard_check_icall@4;

// address=[0x3018be0]
___isa_available_init;

// address=[0x3018f70]
__get_startup_argv_mode;

// address=[0x3019310]
___security_init_cookie;

// address=[0x3019430]
__matherr;

// address=[0x3019440]
__get_startup_commit_mode;

// address=[0x3019450]
__get_startup_file_mode;

// address=[0x3019460]
__get_startup_new_mode;

// address=[0x3019470]
__get_startup_thread_locale_mode;

// address=[0x3019480]
__should_initialize_environment;

// address=[0x3019490]
__initialize_default_precision;

// address=[0x30194c0]
__initialize_invalid_parameter_handler;

// address=[0x30194d0]
__initialize_denormal_control;

// address=[0x3019580]
__RTC_Initialize;

// address=[0x30195c0]
__RTC_Terminate;

// address=[0x3019600]
int (__cdecl*__cdecl _RTC_GetErrorFunc(void const *))(int,char const *,int,char const *,char const *,...);

// address=[0x3019610]
int (__cdecl*__cdecl _RTC_GetErrorFuncW(void const *))(int,wchar_t const *,int,wchar_t const *,wchar_t const *,...);

// address=[0x3019620]
__RTC_GetErrDesc;

// address=[0x3019640]
__RTC_NumErrors;

// address=[0x3019650]
__RTC_SetErrorFunc;

// address=[0x3019680]
__RTC_SetErrorFuncW;

// address=[0x30196b0]
__RTC_SetErrorType;

// address=[0x3019ca0]
int __cdecl _RTC_GetSrcLine(unsigned char *,wchar_t *,unsigned long,int *,wchar_t *,unsigned long);

// address=[0x301a0d0]
@_guard_check_icall_nop@4;

// address=[0x301a0e0]
__guard_icall_checks_enforced;

// address=[0x301a110]
_GetFileVersionInfoSizeW@8;

// address=[0x301a116]
_GetFileVersionInfoW@16;

// address=[0x301a11c]
_VerQueryValueW@16;

// address=[0x301a122]
_UnDecorateSymbolName@16;

// address=[0x301a128]
_StackWalk@36;

// address=[0x301a12e]
_SymSetOptions@4;

// address=[0x301a134]
_SymGetOptions@0;

// address=[0x301a13a]
_SymCleanup@4;

// address=[0x301a140]
_SymFunctionTableAccess@8;

// address=[0x301a146]
_SymGetModuleInfo@12;

// address=[0x301a14c]
_SymGetModuleBase@8;

// address=[0x301a152]
_SymGetLineFromAddr@16;

// address=[0x301a158]
_SymInitialize@12;

// address=[0x301a15e]
_SymGetSymFromAddr@16;

// address=[0x301a164]
_MiniDumpWriteDump@28;

// address=[0x301a710]
void __stdcall __vcrt_va_start_verify_argument_type<unsigned short>(void);

// address=[0x301a720]
void __stdcall __vcrt_va_start_verify_argument_type<wchar_t const *>(void);

// address=[0x301a730]
long __cdecl _com_dispatch_method(struct IDispatch *,long,unsigned short,unsigned short,void *,wchar_t const *,...);

// address=[0x301a830]
long __stdcall _com_dispatch_propget(struct IDispatch *,long,unsigned short,void *);

// address=[0x301a870]
long __cdecl _com_dispatch_propput(struct IDispatch *,long,unsigned short,...);

// address=[0x301a9f0]
void __stdcall _com_issue_error(long);

// address=[0x301aa40]
void __stdcall _com_issue_errorex(long,struct IUnknown *,struct _GUID const &);

// address=[0x301ad40]
char * __stdcall _com_util::ConvertBSTRToString(wchar_t *);

// address=[0x301af30]
wchar_t * __stdcall _com_util::ConvertStringToBSTR(char const *);

// address=[0x301b230]
long __stdcall HRESULT_FROM_WIN32(unsigned long);

// address=[0x301b4e0]
void __stdcall _com_raise_error(long,struct IErrorInfo *);

// address=[0x301b540]
long __cdecl _com_dispatch_raw_method(struct IDispatch *,long,unsigned short,unsigned short,void *,wchar_t const *,...);

// address=[0x301b630]
long __stdcall _com_dispatch_raw_propget(struct IDispatch *,long,unsigned short,void *);

// address=[0x301b670]
long __cdecl _com_dispatch_raw_propput(struct IDispatch *,long,unsigned short,...);

// address=[0x301b7e0]
long __cdecl _com_invoke_helper(struct IDispatch *,long,unsigned short,unsigned short,void *,wchar_t const *,char *,struct IErrorInfo * *);

// address=[0x301cc90]
long __stdcall _com_handle_excepinfo(struct tagEXCEPINFO &,struct IErrorInfo * *);

// address=[0x3020c20]
void * __cdecl operator new(unsigned int,class _ConcRTNewMoniker,char const *,int);

// address=[0x3020c50]
void __cdecl operator delete(void *,class _ConcRTNewMoniker,char const *,int);

// address=[0x3020cb0]
void * __cdecl operator new[](unsigned int,class _ConcRTNewMoniker,char const *,int);

// address=[0x3023040]
__freea;

// address=[0x3023f30]
__concrt_static_cleanup;

// address=[0x3024aa0]
_fwprintf;

// address=[0x3024af0]
_vswprintf_s;

// address=[0x3026ad0]
void __cdecl operator delete[](void *,class _ConcRTNewMoniker,char const *,int);

// address=[0x3027d60]
struct Concurrency::IResourceManager * __cdecl Concurrency::CreateResourceManager(void);

// address=[0x302ce50]
unsigned int __cdecl Concurrency::GetExecutionContextId(void);

// address=[0x302d330]
enum Concurrency::IResourceManager::OSVersion __cdecl Concurrency::GetOSVersion(void);

// address=[0x302d340]
unsigned int __cdecl Concurrency::GetProcessorCount(void);

// address=[0x302d350]
unsigned int __cdecl Concurrency::GetProcessorNodeCount(void);

// address=[0x302d380]
unsigned int __cdecl Concurrency::GetSchedulerId(void);

// address=[0x30346a0]
void __cdecl Concurrency::set_task_execution_resources(unsigned short,struct _GROUP_AFFINITY *);

// address=[0x30346c0]
void __cdecl Concurrency::set_task_execution_resources(unsigned long);

// address=[0x3049f00]
_MemoryBarrier;

// address=[0x304fcc0]
void __cdecl __vcrt_va_start_verify_argument_type<unsigned int>(void);

// address=[0x3052640]
double __cdecl abs(double);

// address=[0x3058710]
void __cdecl __vcrt_va_start_verify_argument_type<__int64>(void);

// address=[0x30589d0]
long __cdecl Concurrency::DisableTracing(void);

// address=[0x30589e0]
long __cdecl Concurrency::EnableTracing(void);

// address=[0x3058ec0]
void __cdecl Concurrency::_Trace_agents(enum Concurrency::Agents_EventType,__int64,...);

// address=[0x30590e0]
void __cdecl Concurrency::_Trace_ppl_function(struct _GUID const &,unsigned char,enum Concurrency::ConcRT_EventType);

// address=[0x3061e70]
void * __cdecl Concurrency::Alloc(unsigned int);

// address=[0x3062160]
void __cdecl Concurrency::Free(void *);

// address=[0x3077b40]
__get_purecall_handler;

// address=[0x3077b70]
__purecall;

// address=[0x3077bb0]
__set_purecall_handler;

// address=[0x3077bf0]
_memcpy;

// address=[0x30782d0]
_memmove;

// address=[0x30789b0]
__CxxThrowException@8;

// address=[0x3078a90]
void * __cdecl _CallCatchBlock2(struct EHRegistrationNode *,struct _s_FuncInfo const *,void *,int,unsigned long);

// address=[0x3078b20]
int __cdecl _CallSETranslator(struct EHExceptionRecord *,struct EHRegistrationNode *,void *,void *,struct _s_FuncInfo const *,int,struct EHRegistrationNode *);

// address=[0x3078c50]
struct _s_TryBlockMapEntry const * __cdecl _GetRangeOfTrysToCheck(struct _s_FuncInfo const *,int,int,unsigned int *,unsigned int *);

// address=[0x3078d50]
void __stdcall _JumpToContinuation(void *,struct EHRegistrationNode *);

// address=[0x3078d90]
void __stdcall _UnwindNestedFrames(struct EHRegistrationNode *,struct EHExceptionRecord *);

// address=[0x3078e00]
__CatchGuardHandler;

// address=[0x3078e60]
__CreateFrameInfo;

// address=[0x3078ea0]
__FindAndUnlinkFrame;

// address=[0x3078f30]
__IsExceptionObjectToBeDestroyed;

// address=[0x3078f80]
__TranslatorGuardHandler;

// address=[0x3079060]
___CxxFrameHandler;

// address=[0x30790b0]
___CxxFrameHandler2;

// address=[0x3079100]
___CxxFrameHandler3;

// address=[0x3079150]
___CxxLongjmpUnwind@4;

// address=[0x3079a80]
___RTCastToVoid;

// address=[0x3079b80]
___RTDynamicCast;

// address=[0x3079db0]
___RTtypeid;

// address=[0x3079f20]
_memset;

// address=[0x307a2e0]
_memcmp;

// address=[0x307ade0]
_strstr;

// address=[0x307b0e0]
_wcsstr;

// address=[0x307b820]
___std_exception_copy;

// address=[0x307b940]
___std_exception_destroy;

// address=[0x307c070]
_wcschr;

// address=[0x307c230]
_wcsrchr;

// address=[0x307c420]
_memchr;

// address=[0x307c500]
_strchr;

// address=[0x307c56e]
___from_strstr_to_strchr;

// address=[0x307c700]
__except_handler4;

// address=[0x307c950]
_strrchr;

// address=[0x307cae0]
void (__cdecl*__cdecl _set_se_translator(int))(unsigned int,struct _EXCEPTION_POINTERS *);

// address=[0x307cb00]
__set_se_translator;

// address=[0x307cb30]
_longjmp;

// address=[0x307cb60]
__setjmp3;

// address=[0x307cc00]
___DestructExceptionObject;

// address=[0x307dd20]
void __stdcall _CallMemberFunction0(void * const,void * const);

// address=[0x307dd30]
void __stdcall _CallMemberFunction1(void * const,void * const,void * const);

// address=[0x307dd40]
void __stdcall _CallMemberFunction2(void * const,void * const,void * const,int);

// address=[0x307dd50]
bool __cdecl _ValidateExecute(int (__stdcall*)(void));

// address=[0x307dd70]
bool __cdecl _ValidateRead(void const *,unsigned int);

// address=[0x307dd90]
bool __cdecl _ValidateWrite(void *,unsigned int);

// address=[0x307ddd0]
__SetWinRTOutOfMemoryExceptionCallback;

// address=[0x307dde0]
___AdjustPointer;

// address=[0x307de40]
___BuildCatchObject;

// address=[0x307df90]
___BuildCatchObjectHelper;

// address=[0x307e380]
___CxxDetectRethrow;

// address=[0x307e420]
___CxxExceptionFilter;

// address=[0x307e690]
___CxxQueryExceptionSize;

// address=[0x307e6a0]
___CxxRegisterExceptionObject;

// address=[0x307e810]
___CxxUnregisterExceptionObject;

// address=[0x307e9c0]
___FrameUnwindFilter;

// address=[0x307ea50]
___FrameUnwindToState;

// address=[0x307ec30]
___GetPlatformExceptionInfo;

// address=[0x307ecd0]
___InternalCxxFrameHandler;

// address=[0x307eee0]
___TypeMatch;

// address=[0x307eff0]
___current_exception;

// address=[0x307f000]
___current_exception_context;

// address=[0x307f010]
___processing_throw;

// address=[0x307f020]
___std_terminate;

// address=[0x307f030]
___uncaught_exception;

// address=[0x307f060]
___uncaught_exceptions;

// address=[0x307f070]
__is_exception_typeof;

// address=[0x307f180]
___vcrt_initialize;

// address=[0x307f1d0]
___vcrt_thread_attach;

// address=[0x307f1f0]
___vcrt_thread_detach;

// address=[0x307f210]
___vcrt_uninitialize;

// address=[0x307f240]
___vcrt_uninitialize_critical;

// address=[0x307f930]
___vcrt_EventRegister;

// address=[0x307f980]
___vcrt_EventSetInformation;

// address=[0x307f9e0]
___vcrt_EventUnregister;

// address=[0x307fa30]
___vcrt_EventWriteTransfer;

// address=[0x307fa90]
___vcrt_FlsAlloc;

// address=[0x307fae0]
___vcrt_FlsFree;

// address=[0x307fb30]
___vcrt_FlsGetValue;

// address=[0x307fb80]
___vcrt_FlsSetValue;

// address=[0x307fbe0]
___vcrt_InitializeCriticalSectionEx;

// address=[0x307fc40]
___vcrt_initialize_winapi_thunks;

// address=[0x307fcc0]
___vcrt_uninitialize_winapi_thunks;

// address=[0x307fd50]
___vcrt_GetModuleFileNameW;

// address=[0x307fd70]
___vcrt_GetModuleHandleW;

// address=[0x307fd90]
___vcrt_LoadLibraryExW;

// address=[0x307fdd0]
___vcrt_initialize_pure_virtual_call_handler;

// address=[0x307ffc0]
___vcrt_freefls@4;

// address=[0x307fff0]
___vcrt_freeptd;

// address=[0x3080060]
___vcrt_getptd;

// address=[0x3080090]
___vcrt_getptd_noexit;

// address=[0x3080250]
___vcrt_initialize_ptd;

// address=[0x30802b0]
___vcrt_uninitialize_ptd;

// address=[0x30802f0]
__CallSettingFrame@12;

// address=[0x3080317]
__NLG_Return;

// address=[0x3080350]
___except_validate_context_record;

// address=[0x30803b0]
___except_validate_jump_buffer;

// address=[0x3081d90]
class DName __cdecl operator+(char,class DName const &);

// address=[0x3081dd0]
class DName __cdecl operator+(char const *,class DName const &);

// address=[0x3081e10]
class DName __cdecl operator+(enum DNameStatus,class DName const &);

// address=[0x308a8e0]
char * __cdecl getStringHelper(char *,char *,char *,int);

// address=[0x308d3b0]
___unDName;

// address=[0x308d4b0]
___unDNameEx;

// address=[0x308d5b0]
__local_unwind4;

// address=[0x308d686]
__seh_longjmp_unwind4@4;

// address=[0x308d6ae]
@_EH4_CallFilterFunc@8;

// address=[0x308d6c5]
@_EH4_TransferToHandler@8;

// address=[0x308d6de]
@_EH4_GlobalUnwind2@8;

// address=[0x308d6f7]
@_EH4_LocalUnwind@16;

// address=[0x308d770]
___longjmp_internal;

// address=[0x308d850]
__global_unwind2;

// address=[0x308d8b5]
__local_unwind2;

// address=[0x308d939]
__abnormal_termination;

// address=[0x308d95c]
__NLG_Notify1;

// address=[0x308d965]
__NLG_Notify;

// address=[0x308d97c]
__NLG_Dispatch;

// address=[0x308d97c]
__NLG_Dispatch2;

// address=[0x308d984]
__NLG_Call;

// address=[0x308d986]
__NLG_Return2;

// address=[0x308da10]
__get_unexpected;

// address=[0x308da30]
_set_unexpected;

// address=[0x308da70]
_unexpected;

// address=[0x308dab0]
___vcrt_initialize_locks;

// address=[0x308db20]
___vcrt_lock;

// address=[0x308db40]
___vcrt_uninitialize_locks;

// address=[0x308dba0]
___vcrt_unlock;

// address=[0x308dbc0]
__rt_probe_read4@4;

// address=[0x308df60]
__get_invalid_parameter_handler;

// address=[0x308df90]
__get_thread_local_invalid_parameter_handler;

// address=[0x308dfc0]
__invalid_parameter;

// address=[0x308e0c0]
__invalid_parameter_noinfo;

// address=[0x308e0e0]
__invalid_parameter_noinfo_noreturn;

// address=[0x308e120]
__invoke_watson;

// address=[0x308e170]
__set_invalid_parameter_handler;

// address=[0x308e1d0]
__set_thread_local_invalid_parameter_handler;

// address=[0x308e210]
_strlen;

// address=[0x308ffb0]
__CrtDbgReport;

// address=[0x3090010]
__CrtDbgReportW;

// address=[0x3090070]
__CrtSetReportHook2;

// address=[0x3090090]
__CrtSetReportHookW2;

// address=[0x3090110]
__invoke_watson_if_error;

// address=[0x3090150]
__invoke_watson_if_oneof;

// address=[0x30901a0]
__snwprintf_s;

// address=[0x3090200]
__vsnwprintf_s_l;

// address=[0x3090270]
__abs64;

// address=[0x30902d0]
_abs;

// address=[0x30bf350]
___stdio_common_vfprintf;

// address=[0x30bf380]
___stdio_common_vfprintf_p;

// address=[0x30bf3b0]
___stdio_common_vfprintf_s;

// address=[0x30bf3e0]
___stdio_common_vfwprintf;

// address=[0x30bf410]
___stdio_common_vfwprintf_p;

// address=[0x30bf440]
___stdio_common_vfwprintf_s;

// address=[0x30bf470]
___stdio_common_vsnprintf_s;

// address=[0x30bf4b0]
___stdio_common_vsnwprintf_s;

// address=[0x30bf4f0]
___stdio_common_vsprintf;

// address=[0x30bf530]
___stdio_common_vsprintf_p;

// address=[0x30bf570]
___stdio_common_vsprintf_s;

// address=[0x30bf5b0]
___stdio_common_vswprintf;

// address=[0x30bf5f0]
___stdio_common_vswprintf_p;

// address=[0x30bf630]
___stdio_common_vswprintf_s;

// address=[0x30bf670]
__CIsqrt;

// address=[0x30bf684]
_sqrt;

// address=[0x30bf760]
_wcslen;

// address=[0x30bf7b0]
___ascii_stricmp;

// address=[0x30bf850]
__stricmp;

// address=[0x30bf9e0]
__stricmp_l;

// address=[0x30c24c0]
__assert;

// address=[0x30c24f0]
__wassert;

// address=[0x30c4510]
__CrtCheckMemory;

// address=[0x30c4700]
__CrtDoForAllClientObjects;

// address=[0x30c48b0]
__CrtDumpMemoryLeaks;

// address=[0x30c4970]
__CrtGetAllocHook;

// address=[0x30c4980]
__CrtGetDumpClient;

// address=[0x30c4990]
__CrtIsMemoryBlock;

// address=[0x30c4b30]
__CrtIsValidHeapPointer;

// address=[0x30c4b70]
__CrtIsValidPointer;

// address=[0x30c4ba0]
__CrtMemCheckpoint;

// address=[0x30c4e60]
__CrtMemDifference;

// address=[0x30c5170]
__CrtMemDumpAllObjectsSince;

// address=[0x30c5230]
__CrtMemDumpStatistics;

// address=[0x30c53a0]
__CrtReportBlockType;

// address=[0x30c53e0]
__CrtSetAllocHook;

// address=[0x30c5410]
__CrtSetBreakAlloc;

// address=[0x30c5440]
__CrtSetDbgBlockType;

// address=[0x30c5550]
__CrtSetDbgFlag;

// address=[0x30c5720]
__CrtSetDumpClient;

// address=[0x30c5790]
__aligned_free_dbg;

// address=[0x30c5870]
__aligned_malloc_dbg;

// address=[0x30c58a0]
__aligned_msize_dbg;

// address=[0x30c5a10]
__aligned_offset_malloc_dbg;

// address=[0x30c5c60]
__aligned_offset_realloc_dbg;

// address=[0x30c6030]
__aligned_offset_recalloc_dbg;

// address=[0x30c6120]
__aligned_realloc_dbg;

// address=[0x30c6150]
__aligned_recalloc_dbg;

// address=[0x30c6190]
__calloc_dbg;

// address=[0x30c6220]
__chvalidchk_l;

// address=[0x30c6250]
__expand_dbg;

// address=[0x30c63d0]
__free_dbg;

// address=[0x30c64b0]
__ischartype_l;

// address=[0x30c6510]
__malloc_dbg;

// address=[0x30c6540]
__msize_dbg;

// address=[0x30c6730]
__realloc_dbg;

// address=[0x30c6800]
__recalloc_dbg;

// address=[0x30c68e0]
_wcsncpy;

// address=[0x30c6f60]
__wcsupr;

// address=[0x30c6f60]
_wcsupr;

// address=[0x30c7090]
__wcsupr_l;

// address=[0x30c70c0]
__wcsupr_s;

// address=[0x30c70e0]
__wcsupr_s_l;

// address=[0x30c7130]
_strcmp;

// address=[0x30c71e0]
_free;

// address=[0x30c7200]
_malloc;

// address=[0x30c9360]
__splitpath;

// address=[0x30c9390]
__splitpath_s;

// address=[0x30c93f0]
__wsplitpath;

// address=[0x30c9420]
__wsplitpath_s;

// address=[0x30c9480]
_rand;

// address=[0x30c94d0]
_srand;

// address=[0x30c9780]
___control87_2;

// address=[0x30c98f0]
___fpreset_sse2;

// address=[0x30c9d40]
__clearfp;

// address=[0x30c9da0]
__control87;

// address=[0x30c9e80]
__controlfp;

// address=[0x30c9eb0]
__fpreset;

// address=[0x30ca0e0]
__set_controlfp;

// address=[0x30ca190]
__statusfp;

// address=[0x30ca1f0]
__statusfp2;

// address=[0x30cad70]
___getgmtimebuf;

// address=[0x30cae20]
__gmtime32;

// address=[0x30cae40]
__gmtime32_s;

// address=[0x30cae60]
__gmtime64;

// address=[0x30cae80]
__gmtime64_s;

// address=[0x30cb674]
__getcwd;

// address=[0x30cb697]
__getcwd_dbg;

// address=[0x30cb6bf]
__getdcwd;

// address=[0x30cb6e4]
__getdcwd_dbg;

// address=[0x30cb6f1]
__wgetcwd;

// address=[0x30cb714]
__wgetcwd_dbg;

// address=[0x30cb73c]
__wgetdcwd;

// address=[0x30cb761]
__wgetdcwd_dbg;

// address=[0x30cbcdf]
__chdir;

// address=[0x30cbcec]
__wchdir;

// address=[0x30cc340]
__Exit;

// address=[0x30cc380]
__c_exit;

// address=[0x30cc3a0]
__cexit;

// address=[0x30cc3c0]
__exit;

// address=[0x30cc3e0]
__is_c_termination_complete;

// address=[0x30cc450]
_exit;

// address=[0x30cc470]
_quick_exit;

// address=[0x30cc490]
_strncpy;

// address=[0x30cc600]
__mbscpy;

// address=[0x30cc600]
_strcpy;

// address=[0x30cc610]
_strcat;

// address=[0x30ccbb0]
__mbstowcs_l;

// address=[0x30ccbe0]
__mbstowcs_s_l;

// address=[0x30cd090]
_mbstowcs;

// address=[0x30cd0f0]
_mbstowcs_s;

// address=[0x30cd910]
__wcstombs_l;

// address=[0x30cd940]
__wcstombs_s_l;

// address=[0x30cdd80]
_wcstombs;

// address=[0x30cddb0]
_wcstombs_s;

// address=[0x30cf310]
__i64toa;

// address=[0x30cf380]
__i64toa_s;

// address=[0x30cf3f0]
__i64tow;

// address=[0x30cf460]
__i64tow_s;

// address=[0x30cf4d0]
__itoa;

// address=[0x30cf530]
__itoa_s;

// address=[0x30cf590]
__itow;

// address=[0x30cf5f0]
__itow_s;

// address=[0x30cf650]
__ltoa;

// address=[0x30cf6b0]
__ltoa_s;

// address=[0x30cf710]
__ltow;

// address=[0x30cf770]
__ltow_s;

// address=[0x30cf7d0]
__ui64toa;

// address=[0x30cf800]
__ui64toa_s;

// address=[0x30cf830]
__ui64tow;

// address=[0x30cf860]
__ui64tow_s;

// address=[0x30cf890]
__ultoa;

// address=[0x30cf8c0]
__ultoa_s;

// address=[0x30cf8f0]
__ultow;

// address=[0x30cf920]
__ultow_s;

// address=[0x30cf949]
__mbsdec;

// address=[0x30cf965]
__mbsdec_l;

// address=[0x30cfa89]
__mbsinc;

// address=[0x30cfb1c]
__mbsinc_l;

// address=[0x30cfb4c]
__mbsncmp;

// address=[0x30cfb6c]
__mbsncmp_l;

// address=[0x30cfd25]
__mbsninc;

// address=[0x30cfd41]
__mbsninc_l;

// address=[0x30cfd70]
_wcscpy;

// address=[0x30d1e70]
__atoi64;

// address=[0x30d1e90]
__atoi64_l;

// address=[0x30d1ec0]
__atoi_l;

// address=[0x30d1ef0]
__atol_l;

// address=[0x30d1f20]
__atoll_l;

// address=[0x30d1f50]
__wtoi;

// address=[0x30d1f70]
__wtoi64;

// address=[0x30d1f90]
__wtoi64_l;

// address=[0x30d1fc0]
__wtoi_l;

// address=[0x30d1ff0]
__wtol;

// address=[0x30d2010]
__wtol_l;

// address=[0x30d2040]
__wtoll;

// address=[0x30d2060]
__wtoll_l;

// address=[0x30d2090]
_atoi;

// address=[0x30d20b0]
_atol;

// address=[0x30d20d0]
_atoll;

// address=[0x30d21d0]
___doserrno;

// address=[0x30d2200]
__errno;

// address=[0x30d2230]
__get_doserrno;

// address=[0x30d22e0]
__get_errno;

// address=[0x30d2390]
__set_doserrno;

// address=[0x30d23d0]
__set_errno;

// address=[0x30d2410]
_strcspn;

// address=[0x30d8c80]
__atodbl;

// address=[0x30d8ca0]
__atodbl_l;

// address=[0x30d8cd0]
__atof_l;

// address=[0x30d8cf0]
__atoflt;

// address=[0x30d8d10]
__atoflt_l;

// address=[0x30d8d40]
__wtof;

// address=[0x30d8d60]
__wtof_l;

// address=[0x30d8d80]
_atof;

// address=[0x30d99c0]
__strtod_l;

// address=[0x30d99f0]
__strtof_l;

// address=[0x30d9a20]
__strtold_l;

// address=[0x30d9a50]
__wcstod_l;

// address=[0x30d9a80]
__wcstof_l;

// address=[0x30d9ab0]
__wcstold_l;

// address=[0x30d9c30]
_strtod;

// address=[0x30d9c50]
_strtof;

// address=[0x30d9c70]
_strtold;

// address=[0x30d9c90]
_wcstod;

// address=[0x30d9cb0]
_wcstof;

// address=[0x30d9cd0]
_wcstold;

// address=[0x30d9cf0]
_fabs;

// address=[0x30d9e10]
_pow;

// address=[0x30d9e50]
__CIpow;

// address=[0x30d9e8b]
__CIpow_default;

// address=[0x30d9ea4]
__pow_default;

// address=[0x30da140]
_frexp;

// address=[0x30da390]
_ldexp;

// address=[0x30da720]
_localeconv;

// address=[0x30da790]
___isascii;

// address=[0x30da7c0]
___iscsym;

// address=[0x30da810]
___iscsymf;

// address=[0x30da850]
___toascii;

// address=[0x30da860]
__isalnum_l;

// address=[0x30da8b0]
__isalpha_l;

// address=[0x30da900]
__isblank_l;

// address=[0x30da970]
__iscntrl_l;

// address=[0x30da9c0]
__iscsym_l;

// address=[0x30daa10]
__iscsymf_l;

// address=[0x30daa60]
__isdigit_l;

// address=[0x30daab0]
__isgraph_l;

// address=[0x30dab00]
__islower_l;

// address=[0x30dab50]
__isprint_l;

// address=[0x30daba0]
__ispunct_l;

// address=[0x30dabf0]
__isspace_l;

// address=[0x30dac40]
__isupper_l;

// address=[0x30dac90]
__isxdigit_l;

// address=[0x30dace0]
_isalnum;

// address=[0x30dad30]
_isalpha;

// address=[0x30dad80]
_isblank;

// address=[0x30dadf0]
_iscntrl;

// address=[0x30dae40]
_isdigit;

// address=[0x30dae90]
_isgraph;

// address=[0x30daee0]
_islower;

// address=[0x30daf30]
_isprint;

// address=[0x30daf80]
_ispunct;

// address=[0x30dafd0]
_isspace;

// address=[0x30db020]
_isupper;

// address=[0x30db070]
_isxdigit;

// address=[0x30db6a0]
__tolower;

// address=[0x30db6b0]
__tolower_l;

// address=[0x30db6e0]
__toupper;

// address=[0x30db6f0]
__toupper_l;

// address=[0x30db720]
_tolower;

// address=[0x30db790]
_toupper;

// address=[0x30db800]
_wcscmp;

// address=[0x30db875]
__mbsstr;

// address=[0x30db891]
__mbsstr_l;

// address=[0x30dc030]
__wcslwr;

// address=[0x30dc160]
__wcslwr_l;

// address=[0x30dc190]
__wcslwr_s;

// address=[0x30dc1b0]
__wcslwr_s_l;

// address=[0x30dc200]
_wcscat;

// address=[0x30dc270]
_labs;

// address=[0x30df180]
__findclose;

// address=[0x30df1b0]
__findfirst32;

// address=[0x30df1d0]
__findfirst32i64;

// address=[0x30df1f0]
__findfirst64;

// address=[0x30df210]
__findfirst64i32;

// address=[0x30df230]
__findnext32;

// address=[0x30df250]
__findnext32i64;

// address=[0x30df270]
__findnext64;

// address=[0x30df290]
__findnext64i32;

// address=[0x30df2b0]
__wfindfirst32;

// address=[0x30df2d0]
__wfindfirst32i64;

// address=[0x30df2f0]
__wfindfirst64;

// address=[0x30df310]
__wfindfirst64i32;

// address=[0x30df330]
__wfindnext32;

// address=[0x30df350]
__wfindnext32i64;

// address=[0x30df370]
__wfindnext64;

// address=[0x30df390]
__wfindnext64i32;

// address=[0x30e01f0]
__localtime32;

// address=[0x30e0210]
__localtime32_s;

// address=[0x30e0230]
__localtime64;

// address=[0x30e0250]
__localtime64_s;

// address=[0x30e0660]
__time32;

// address=[0x30e0680]
__time64;

// address=[0x30e06a0]
__timespec32_get;

// address=[0x30e06c0]
__timespec64_get;

// address=[0x30e1740]
___threadhandle;

// address=[0x30e1750]
___threadid;

// address=[0x30e1ad0]
__get_stream_buffer_pointers;

// address=[0x30e1be0]
__lock_file;

// address=[0x30e1c10]
__unlock_file;

// address=[0x30e1c80]
__fclose_nolock;

// address=[0x30e1e10]
_fclose;

// address=[0x30e2250]
__fflush_nolock;

// address=[0x30e22f0]
__flushall;

// address=[0x30e2510]
_fflush;

// address=[0x30e25e0]
__fgetc_nolock;

// address=[0x30e2730]
__fgetchar;

// address=[0x30e2750]
__getc_nolock;

// address=[0x30e2770]
_fgetc;

// address=[0x30e2a60]
_getc;

// address=[0x30e2a80]
_getchar;

// address=[0x30e2a90]
_fgetpos;

// address=[0x30e2c10]
__fputc_nolock;

// address=[0x30e2cc0]
__fputchar;

// address=[0x30e2cf0]
__putc_nolock;

// address=[0x30e2d10]
_fputc;

// address=[0x30e2fe0]
_putc;

// address=[0x30e3000]
_putchar;

// address=[0x30e3020]
_fsetpos;

// address=[0x30e3180]
long __cdecl LongLongSub(__int64,__int64,__int64 *);

// address=[0x30e38b0]
__fseek_nolock;

// address=[0x30e38f0]
__fseeki64;

// address=[0x30e3930]
__fseeki64_nolock;

// address=[0x30e3970]
_fseek;

// address=[0x30e3c30]
__fwrite_nolock;

// address=[0x30e41d0]
_fwrite;

// address=[0x30e46e0]
_setvbuf;

// address=[0x30e4930]
__ungetc_nolock;

// address=[0x30e4c70]
_ungetc;

// address=[0x30e4dc0]
__CrtGetReportHook;

// address=[0x30e4dd0]
__CrtSetReportFile;

// address=[0x30e4f00]
__CrtSetReportHook;

// address=[0x30e4f30]
__CrtSetReportMode;

// address=[0x30e50c0]
__VCrtDbgReportA;

// address=[0x30e5b80]
__VCrtDbgReportW;

// address=[0x30e67a0]
__vsnwprintf_s;

// address=[0x30e67d0]
__chgsign;

// address=[0x30e6810]
__chgsignf;

// address=[0x30e6860]
__copysign;

// address=[0x30e68a0]
__copysignf;

// address=[0x30e6900]
__finite;

// address=[0x30e6930]
__fpclass;

// address=[0x30e6a60]
__isnan;

// address=[0x30e6ac0]
__logb;

// address=[0x30e6c20]
__nextafter;

// address=[0x30e6c50]
__scalb;

// address=[0x30e6f00]
__strtoi64;

// address=[0x30e6f30]
__strtoi64_l;

// address=[0x30e6f60]
__strtoimax_l;

// address=[0x30e6f90]
__strtol_l;

// address=[0x30e6fc0]
__strtoll_l;

// address=[0x30e6ff0]
__strtoui64;

// address=[0x30e7020]
__strtoui64_l;

// address=[0x30e7050]
__strtoul_l;

// address=[0x30e7080]
__strtoull_l;

// address=[0x30e70b0]
__strtoumax_l;

// address=[0x30e70e0]
__wcstoi64;

// address=[0x30e7110]
__wcstoi64_l;

// address=[0x30e7140]
__wcstoimax_l;

// address=[0x30e7170]
__wcstol_l;

// address=[0x30e71a0]
__wcstoll_l;

// address=[0x30e71d0]
__wcstoui64;

// address=[0x30e7200]
__wcstoui64_l;

// address=[0x30e7230]
__wcstoul_l;

// address=[0x30e7260]
__wcstoull_l;

// address=[0x30e7290]
__wcstoumax_l;

// address=[0x30e72c0]
_strtoimax;

// address=[0x30e72f0]
_strtol;

// address=[0x30e7320]
_strtoll;

// address=[0x30e7350]
_strtoul;

// address=[0x30e7380]
_strtoull;

// address=[0x30e73b0]
_strtoumax;

// address=[0x30e73e0]
_wcstoimax;

// address=[0x30e7410]
_wcstol;

// address=[0x30e7440]
_wcstoll;

// address=[0x30e7470]
_wcstoul;

// address=[0x30e74a0]
_wcstoull;

// address=[0x30e74d0]
_wcstoumax;

// address=[0x30e74f4]
__mbscmp;

// address=[0x30e7510]
__mbscmp_l;

// address=[0x30e76d0]
__wcsicmp;

// address=[0x30e7910]
__wcsicmp_l;

// address=[0x30e7c10]
__byteswap_uint64;

// address=[0x30e7d60]
__byteswap_ulong;

// address=[0x30e7dc0]
__byteswap_ushort;

// address=[0x30e7e00]
_ceil;

// address=[0x30e7e40]
__ceil_pentium4;

// address=[0x30e8340]
_strcpy_s;

// address=[0x30e8370]
_strncmp;

// address=[0x30e8410]
__set_abort_behavior;

// address=[0x30e8450]
_abort;

// address=[0x30e84e0]
_floor;

// address=[0x30e8520]
__floor_pentium4;

// address=[0x30e8620]
_nextafter;

// address=[0x30f9b40]
___stdio_common_vfscanf;

// address=[0x30f9b70]
___stdio_common_vfwscanf;

// address=[0x30f9ba0]
___stdio_common_vsscanf;

// address=[0x30f9be0]
___stdio_common_vswscanf;

// address=[0x30fa4e0]
__beginthread;

// address=[0x30fa6c0]
__beginthreadex;

// address=[0x30fa850]
__endthread;

// address=[0x30fa870]
__endthreadex;

// address=[0x30fa890]
_calloc;

// address=[0x30fa8c0]
_realloc;

// address=[0x30faf40]
__get_sys_err_msg;

// address=[0x30faf80]
__wcserror;

// address=[0x30fafa0]
__wcserror_s;

// address=[0x30fafd0]
_strerror;

// address=[0x30faff0]
_strerror_s;

// address=[0x30fb020]
___sys_errlist;

// address=[0x30fb030]
___sys_nerr;

// address=[0x30fb6d0]
_fgets;

// address=[0x30fb710]
_fgetws;

// address=[0x30fbf80]
__fsopen;

// address=[0x30fbfb0]
__wfopen;

// address=[0x30fbfd0]
__wfopen_s;

// address=[0x30fc000]
__wfsopen;

// address=[0x30fc030]
_fopen;

// address=[0x30fc050]
_fopen_s;

// address=[0x30fc320]
_fputs;

// address=[0x30fc780]
_qsort;

// address=[0x30fcfa0]
__fread_nolock;

// address=[0x30fcfd0]
__fread_nolock_s;

// address=[0x30fd7e0]
_fread;

// address=[0x30fd810]
_fread_s;

// address=[0x30fe940]
__ftell_nolock;

// address=[0x30fe970]
__ftelli64;

// address=[0x30fe9a0]
__ftelli64_nolock;

// address=[0x30fe9d0]
_ftell;

// address=[0x30fea00]
_strpbrk;

// address=[0x30ff815]
__dupenv_s;

// address=[0x30ff83a]
__dupenv_s_dbg;

// address=[0x30ff847]
__wdupenv_s;

// address=[0x30ff86c]
__wdupenv_s_dbg;

// address=[0x30ff879]
__wgetenv;

// address=[0x30ff886]
__wgetenv_s;

// address=[0x30ff893]
_getenv;

// address=[0x30ff8a0]
_getenv_s;

// address=[0x30ff8f0]
_feof;

// address=[0x30ff9b0]
_ferror;

// address=[0x3104300]
__fstat32;

// address=[0x3104320]
__fstat32i64;

// address=[0x3104340]
__fstat64;

// address=[0x3104360]
__fstat64i32;

// address=[0x3104380]
__stat32;

// address=[0x31043a0]
__stat32i64;

// address=[0x31043c0]
__stat64;

// address=[0x31043e0]
__stat64i32;

// address=[0x3104400]
__wstat32;

// address=[0x3104420]
__wstat32i64;

// address=[0x3104440]
__wstat64;

// address=[0x3104460]
__wstat64i32;

// address=[0x3104b10]
___fpecode;

// address=[0x3104b30]
___pxcptinfoptrs;

// address=[0x3104b50]
_raise;

// address=[0x3105020]
_signal;

// address=[0x3105350]
__lrotl;

// address=[0x3105390]
__rotl;

// address=[0x31053d0]
__rotl64;

// address=[0x3107400]
__fdopen;

// address=[0x3107420]
__wfdopen;

// address=[0x3107440]
__chmod;

// address=[0x31074e0]
void __cdecl __vcrt_va_start_verify_argument_type<int const >(void);

// address=[0x3108ec0]
__open;

// address=[0x3108f20]
__sopen;

// address=[0x3108fb0]
__sopen_dispatch;

// address=[0x3108fe0]
__sopen_nolock;

// address=[0x3109070]
__sopen_s;

// address=[0x31090a0]
__wopen;

// address=[0x3109100]
__wsopen;

// address=[0x3109190]
__wsopen_dispatch;

// address=[0x31091c0]
__wsopen_nolock;

// address=[0x31098c0]
__wsopen_s;

// address=[0x31098f0]
__lrotr;

// address=[0x3109930]
__rotr;

// address=[0x3109970]
__rotr64;

// address=[0x31099d0]
_strnicmp;

// address=[0x31099d0]
__strnicmp;

// address=[0x3109c10]
__strnicmp_l;

// address=[0x3109f40]
__fileno;

// address=[0x310a030]
__get_fmode;

// address=[0x310a0f0]
__set_fmode;

// address=[0x310a1c0]
__setmode;

// address=[0x310a520]
__setmode_nolock;

// address=[0x310a7ef]
__getch;

// address=[0x310a846]
__getch_nolock;

// address=[0x310a94f]
__getche;

// address=[0x310a9a6]
__getche_nolock;

// address=[0x310a9ee]
__getextendedkeycode;

// address=[0x310aacd]
__kbhit;

// address=[0x310ab24]
__kbhit_nolock;

// address=[0x310ac6c]
__ungetch;

// address=[0x310acc8]
__ungetch_nolock;

// address=[0x310b210]
_strncpy_s;

// address=[0x310b620]
_wcscpy_s;

// address=[0x310b650]
__dlog;

// address=[0x310b8e0]
__dlogpoly;

// address=[0x310b980]
_log2;

// address=[0x310b9a0]
___libm_sse2_powf;

// address=[0x310c200]
___libm_sse2_exp;

// address=[0x310c4a0]
___libm_sse2_log;

// address=[0x310c750]
___libm_sse2_log10f;

// address=[0x310c930]
___libm_sse2_logf;

// address=[0x310cb10]
___libm_sse2_pow;

// address=[0x310d830]
___libm_sse2_atan2;

// address=[0x310de90]
___libm_sse2_cosf;

// address=[0x310e030]
___libm_sse2_log10;

// address=[0x310e300]
__d_int;

// address=[0x310e650]
__dtest;

// address=[0x310e7b0]
__fd_int;

// address=[0x310ea00]
__fdtest;

// address=[0x310eb00]
__fperrraise;

// address=[0x310eb40]
__ld_int;

// address=[0x310eb60]
__ldtest;

// address=[0x310eca0]
___libm_sse2_acosf;

// address=[0x310f180]
___libm_sse2_asinf;

// address=[0x310f630]
___libm_sse2_sinf;

// address=[0x310f7d0]
_strncat;

// address=[0x310f960]
_bsearch;

// address=[0x310fce0]
_wcsncmp;

// address=[0x310fdf0]
int (__cdecl*__cdecl _set_new_handler(int))(unsigned int);

// address=[0x310fef0]
__callnewh;

// address=[0x310ff60]
__query_new_handler;

// address=[0x3110020]
__set_new_handler;

// address=[0x3110120]
__query_new_mode;

// address=[0x3110140]
__set_new_mode;

// address=[0x3110400]
__mbstrlen;

// address=[0x3110440]
__mbstrlen_l;

// address=[0x3110460]
__mbstrnlen;

// address=[0x3110480]
__mbstrnlen_l;

// address=[0x31105d6]
__mbsncpy;

// address=[0x31105f6]
__mbsncpy_l;

// address=[0x3110755]
__mbsnset;

// address=[0x3110775]
__mbsnset_l;

// address=[0x31110c0]
__wfreopen;

// address=[0x3111110]
__wfreopen_s;

// address=[0x3111150]
_freopen;

// address=[0x31111a0]
_freopen_s;

// address=[0x31111e0]
__unlink;

// address=[0x3111200]
_remove;

// address=[0x31112a0]
_rename;

// address=[0x3112f10]
char * __cdecl strrchr(char * const,int);

// address=[0x3113020]
__wtmpnam;

// address=[0x3113060]
__wtmpnam_s;

// address=[0x3113130]
_tmpfile;

// address=[0x3113160]
_tmpfile_s;

// address=[0x3113180]
_tmpnam;

// address=[0x31131c0]
_tmpnam_s;

// address=[0x3113709]
__wsystem;

// address=[0x3113716]
_system;

// address=[0x3113890]
_clock;

// address=[0x3113950]
__Getdays;

// address=[0x3113970]
__Getdays_l;

// address=[0x3113bf0]
__Getmonths;

// address=[0x3113c10]
__Getmonths_l;

// address=[0x3113e90]
__Gettnames;

// address=[0x3113ea0]
__Strftime;

// address=[0x3113ed0]
__Strftime_l;

// address=[0x3114460]
__strftime_l;

// address=[0x3114490]
_strftime;

// address=[0x3114620]
_setlocale;

// address=[0x31149b0]
__strcoll_l;

// address=[0x3114c20]
_strcoll;

// address=[0x3114c40]
__fcloseall;

// address=[0x3114dc0]
__ftol;

// address=[0x3114f10]
__lock_locales;

// address=[0x3114f30]
__unlock_locales;

// address=[0x3115140]
____lc_codepage_func;

// address=[0x3115180]
____lc_collate_cp_func;

// address=[0x31151c0]
____lc_locale_name_func;

// address=[0x3115210]
____mb_cur_max_func;

// address=[0x3115250]
____mb_cur_max_l_func;

// address=[0x3115b40]
__ismbbalnum;

// address=[0x3115b61]
__ismbbalnum_l;

// address=[0x3115b84]
__ismbbalpha;

// address=[0x3115ba5]
__ismbbalpha_l;

// address=[0x3115bc8]
__ismbbblank;

// address=[0x3115bf3]
__ismbbblank_l;

// address=[0x3115c20]
__ismbbgraph;

// address=[0x3115c41]
__ismbbgraph_l;

// address=[0x3115c64]
__ismbbkalnum;

// address=[0x3115c82]
__ismbbkalnum_l;

// address=[0x3115ca1]
__ismbbkana;

// address=[0x3115cb8]
__ismbbkana_l;

// address=[0x3115d1d]
__ismbbkprint;

// address=[0x3115d3b]
__ismbbkprint_l;

// address=[0x3115d5a]
__ismbbkpunct;

// address=[0x3115d78]
__ismbbkpunct_l;

// address=[0x3115d97]
__ismbblead;

// address=[0x3115db5]
__ismbblead_l;

// address=[0x3115dd4]
__ismbbprint;

// address=[0x3115df5]
__ismbbprint_l;

// address=[0x3115e18]
__ismbbpunct;

// address=[0x3115e36]
__ismbbpunct_l;

// address=[0x3115e55]
__ismbbtrail;

// address=[0x3115e73]
__ismbbtrail_l;

// address=[0x3115ea0]
__wcsdup;

// address=[0x3115ec0]
__wcsdup_dbg;

// address=[0x3115f70]
___pctype_func;

// address=[0x3115fb0]
___pwctype_func;

// address=[0x3116000]
__get_terminate;

// address=[0x3116020]
_set_terminate;

// address=[0x3116060]
_terminate;

// address=[0x3116130]
_rand_s;

// address=[0x3119620]
__W_Getdays;

// address=[0x31198c0]
__W_Getmonths;

// address=[0x3119b60]
__W_Gettnames;

// address=[0x311aad0]
__Wcsftime;

// address=[0x311ab00]
__Wcsftime_l;

// address=[0x311b040]
__wcsftime_l;

// address=[0x311b070]
_wcsftime;

// address=[0x311b0a0]
___strncnt;

// address=[0x311bd40]
_strnlen;

// address=[0x311bd60]
_wcsnlen;

// address=[0x311bde0]
__seh_filter_dll;

// address=[0x311be10]
__seh_filter_exe;

// address=[0x311d5c0]
__configure_narrow_argv;

// address=[0x311d5e0]
__configure_wide_argv;

// address=[0x311d600]
__set_pgmptr;

// address=[0x311d620]
__set_wpgmptr;

// address=[0x311dfc8]
___dcrt_get_or_create_narrow_environment_nolock;

// address=[0x311dfcd]
___dcrt_get_or_create_wide_environment_nolock;

// address=[0x311dfd2]
___dcrt_uninitialize_environments_nolock;

// address=[0x311e016]
___p__environ;

// address=[0x311e01c]
___p__wenviron;

// address=[0x311e022]
__get_initial_narrow_environment;

// address=[0x311e03b]
__get_initial_wide_environment;

// address=[0x311e054]
__initialize_narrow_environment;

// address=[0x311e059]
__initialize_wide_environment;

// address=[0x311ea40]
__execute_onexit_table;

// address=[0x311ea70]
__initialize_onexit_table;

// address=[0x311eaf0]
__register_onexit_function;

// address=[0x311ee70]
__errcode;

// address=[0x311ef00]
__except1;

// address=[0x311f040]
__except2;

// address=[0x311f1f0]
__handle_exc;

// address=[0x311f5d0]
__handle_qnan2;

// address=[0x311f5f0]
__raise_exc;

// address=[0x311f630]
__raise_exc_ex;

// address=[0x311fd10]
__raise_excf;

// address=[0x311fd50]
__set_errno_from_matherr;

// address=[0x311fda0]
__umatherr;

// address=[0x31202f0]
__query_app_type;

// address=[0x3120300]
__set_app_type;

// address=[0x3120500]
___setusermatherr;

// address=[0x31207e0]
__get_narrow_winmain_command_line;

// address=[0x31207f0]
__get_wide_winmain_command_line;

// address=[0x3120800]
__initterm;

// address=[0x3120870]
__initterm_e;

// address=[0x31218d0]
___lc_lctowcs;

// address=[0x31219b0]
___lc_wcstolc;

// address=[0x3121c60]
__configthreadlocale;

// address=[0x3121e40]
__create_locale;

// address=[0x3121ed0]
__expandlocale;

// address=[0x31224d0]
__free_locale;

// address=[0x3122650]
__get_current_locale;

// address=[0x3122750]
__wcreate_locale;

// address=[0x3122a10]
__wcscats;

// address=[0x3122ab0]
__wsetlocale;

// address=[0x3123dc0]
___p__commode;

// address=[0x3123dd0]
__controlfp_s;

// address=[0x3124a70]
__makepath;

// address=[0x3124aa0]
__makepath_s;

// address=[0x3124ad0]
__wmakepath;

// address=[0x3124b00]
__wmakepath_s;

// address=[0x3124b30]
__strdup;

// address=[0x3124b30]
_strdup;

// address=[0x3124b50]
__strdup_dbg;

// address=[0x3125850]
__read;

// address=[0x3125850]
_read;

// address=[0x3125bf0]
__read_nolock;

// address=[0x3127870]
_write;

// address=[0x3127870]
__write;

// address=[0x3127b50]
__write_nolock;

// address=[0x31280b0]
__recalloc;

// address=[0x31280e0]
__recalloc_base;

// address=[0x31281a0]
_exp;

// address=[0x31281dc]
__CIexp;

// address=[0x3128217]
__exp_default;

// address=[0x3128221]
__CIexp_default;

// address=[0x3128780]
_wcsncpy_s;

// address=[0x3128dd0]
__CrtGetDebugFillThreshold;

// address=[0x3128de0]
__CrtSetDebugFillThreshold;

// address=[0x3128e10]
__mbtowc_l;

// address=[0x31290e0]
_mbtowc;

// address=[0x3129110]
__wctomb_l;

// address=[0x31291b0]
__wctomb_s_l;

// address=[0x31295c0]
_wctomb;

// address=[0x3129620]
_wctomb_s;

// address=[0x312b2a0]
__fputwc_nolock;

// address=[0x312b500]
__fputwchar;

// address=[0x312b530]
__putwc_nolock;

// address=[0x312b550]
_fputwc;

// address=[0x312b6a0]
_putwc;

// address=[0x312b6c0]
_putwchar;

// address=[0x312b6e0]
__get_printf_count_output;

// address=[0x312b720]
__set_printf_count_output;

// address=[0x312ba80]
___p___mb_cur_max;

// address=[0x312bf60]
__trandisp1;

// address=[0x312bfc7]
__trandisp2;

// address=[0x312c053]
__rttospopde;

// address=[0x312c058]
__rttospop;

// address=[0x312c05a]
__rtnospop;

// address=[0x312c05c]
__rttosnpop;

// address=[0x312c05d]
__rtnospopde;

// address=[0x312c064]
__rtzeropop;

// address=[0x312c066]
__rtzeronpop;

// address=[0x312c06b]
__rtzerospop;

// address=[0x312c078]
__rtonepop;

// address=[0x312c07a]
__rtonenpop;

// address=[0x312c07f]
__tosnan1;

// address=[0x312c0aa]
__nosnan2;

// address=[0x312c0ac]
__tosnan2;

// address=[0x312c0d4]
__nan2;

// address=[0x312c113]
__rtindfpop;

// address=[0x312c115]
__rtindfnpop;

// address=[0x312c126]
__rttosnpopde;

// address=[0x312c130]
__rtatan2inf;

// address=[0x312c14d]
__rtchsifneg;

// address=[0x312c1e0]
___setfflag;

// address=[0x312c210]
__startTwoArgErrorHandling;

// address=[0x312c227]
__startOneArgErrorHandling;

// address=[0x312c280]
__twoToTOS;

// address=[0x312c295]
__load_CW;

// address=[0x312c2ac]
__convertTOStoQNaN;

// address=[0x312c2c5]
__fload_withFB;

// address=[0x312c308]
__checkTOS_withFB;

// address=[0x312c31e]
__fast_exit;

// address=[0x312c32b]
__math_exit;

// address=[0x312c355]
__check_overflow_exit;

// address=[0x312c369]
__check_range_exit;

// address=[0x312c470]
__set_error_mode;

// address=[0x312ca90]
_wcscat_s;

// address=[0x312d0c0]
_wcsncat_s;

// address=[0x312d600]
_strcat_s;

// address=[0x312dc10]
_strncat_s;

// address=[0x312dd60]
__free_base;

// address=[0x312ddc0]
__msize;

// address=[0x312dde0]
__realloc_base;

// address=[0x312dea0]
__aligned_free;

// address=[0x312dec0]
__aligned_free_base;

// address=[0x312df10]
__aligned_malloc;

// address=[0x312df40]
__aligned_malloc_base;

// address=[0x312df60]
__aligned_msize;

// address=[0x312df90]
__aligned_msize_base;

// address=[0x312e110]
__aligned_offset_malloc;

// address=[0x312e140]
__aligned_offset_malloc_base;

// address=[0x312e360]
__aligned_offset_realloc;

// address=[0x312e390]
__aligned_offset_realloc_base;

// address=[0x312e770]
__aligned_offset_recalloc;

// address=[0x312e7a0]
__aligned_offset_recalloc_base;

// address=[0x312e880]
__aligned_realloc;

// address=[0x312e8b0]
__aligned_realloc_base;

// address=[0x312e8e0]
__aligned_recalloc;

// address=[0x312e910]
__aligned_recalloc_base;

// address=[0x312e940]
__chvalidator;

// address=[0x312e9a0]
__chvalidator_l;

// address=[0x312ea60]
__isctype;

// address=[0x312eab0]
__isctype_l;

// address=[0x312ecf0]
__expand;

// address=[0x312ed20]
__expand_base;

// address=[0x312eea0]
__CrtDefaultAllocHook;

// address=[0x312ef50]
__get_heap_handle;

// address=[0x312f020]
___clrfp_sse2;

// address=[0x312f070]
___ctrlfp_sse2;

// address=[0x312f0e0]
___fclrf_sse2;

// address=[0x312f110]
___get_fpsr_sse2;

// address=[0x312f140]
___set_fpsr_sse2;

// address=[0x312f250]
___set_statfp_sse2;

// address=[0x312f290]
___statfp_sse2;

// address=[0x312f2d0]
__clrfp;

// address=[0x312f2f0]
__ctrlfp;

// address=[0x312f330]
__set_statfp;

// address=[0x312f3b0]
__statfp;

// address=[0x312f3fe]
__chdrive;

// address=[0x312f4e2]
__getdrive;

// address=[0x3131510]
___iswcsym;

// address=[0x3131560]
___iswcsymf;

// address=[0x31315b0]
__isleadbyte_l;

// address=[0x3131600]
__iswalnum_l;

// address=[0x3131620]
__iswalpha_l;

// address=[0x3131640]
__iswblank_l;

// address=[0x3131680]
__iswcntrl_l;

// address=[0x31316a0]
__iswcsym_l;

// address=[0x31316f0]
__iswcsymf_l;

// address=[0x3131740]
__iswdigit_l;

// address=[0x3131760]
__iswgraph_l;

// address=[0x3131780]
__iswlower_l;

// address=[0x31317a0]
__iswprint_l;

// address=[0x31317c0]
__iswpunct_l;

// address=[0x31317e0]
__iswspace_l;

// address=[0x3131800]
__iswupper_l;

// address=[0x3131820]
__iswxdigit_l;

// address=[0x3131840]
_isleadbyte;

// address=[0x3131860]
_iswalnum;

// address=[0x3131880]
_iswalpha;

// address=[0x31318a0]
_iswascii;

// address=[0x31318e0]
_iswblank;

// address=[0x3131920]
_iswcntrl;

// address=[0x3131940]
_iswdigit;

// address=[0x3131960]
_iswgraph;

// address=[0x3131980]
_iswlower;

// address=[0x31319a0]
_iswprint;

// address=[0x31319c0]
_iswpunct;

// address=[0x31319e0]
_iswspace;

// address=[0x3131a00]
_iswupper;

// address=[0x3131a20]
_iswxdigit;

// address=[0x3131a3f]
__mbsnbcnt;

// address=[0x3131a5b]
__mbsnbcnt_l;

// address=[0x3131b40]
__iswctype_l;

// address=[0x3131b60]
_iswctype;

// address=[0x3131bf0]
___fpe_flt_rounds;

// address=[0x3131c70]
_fegetround;

// address=[0x3131ca0]
__add_exp;

// address=[0x3131ce0]
__decomp;

// address=[0x3131e50]
__get_exp;

// address=[0x3131e90]
__set_bexp;

// address=[0x3131ed0]
__set_exp;

// address=[0x3131f20]
__sptype;

// address=[0x3131fe0]
__set_SSE2_enable;

// address=[0x3132040]
__CIpow_pentium4;

// address=[0x3132059]
__pow_pentium4;

// address=[0x3132e41]
__fFEXP;

// address=[0x3132e98]
__rtinfpopse;

// address=[0x3132e9a]
__rtinfnpopse;

// address=[0x3132eaa]
__fFLN;

// address=[0x3132f5f]
__rtinfpop;

// address=[0x3132f61]
__rtinfnpop;

// address=[0x3132f7e]
__ffexpm1;

// address=[0x31330b0]
__d_inttype;

// address=[0x3133160]
__powhlp;

// address=[0x3133370]
__dclass;

// address=[0x3133390]
__dpcomp;

// address=[0x3133410]
__dsign;

// address=[0x3133430]
_nan;

// address=[0x3134620]
___loctotime32_t;

// address=[0x3134660]
___loctotime64_t;

// address=[0x3134810]
___daylight;

// address=[0x3134830]
___dstbias;

// address=[0x3134850]
___timezone;

// address=[0x3134870]
___tzname;

// address=[0x3134890]
__get_daylight;

// address=[0x3134950]
__get_dstbias;

// address=[0x3134a10]
__get_timezone;

// address=[0x3134ad0]
__get_tzname;

// address=[0x31351a0]
void __cdecl _set_daylight(int);

// address=[0x31351c0]
void __cdecl _set_dstbias(long);

// address=[0x31351e0]
void __cdecl _set_timezone(long);

// address=[0x3135de0]
___tzset;

// address=[0x3135eb0]
__isindst;

// address=[0x3135f60]
__tzset;

// address=[0x31367e0]
__updatetlocinfoEx_nolock;

// address=[0x3137630]
___p__mbcasemap;

// address=[0x3137650]
___p__mbctype;

// address=[0x3137670]
__getmbcp;

// address=[0x3137700]
__setmbcp;

// address=[0x3137720]
__setmbcp_nolock;

// address=[0x3138120]
__close;

// address=[0x31382f0]
__close_nolock;

// address=[0x3138b10]
__commit;

// address=[0x313a920]
__lseek;

// address=[0x313a950]
__lseek_nolock;

// address=[0x313a980]
__lseeki64;

// address=[0x313a9b0]
__lseeki64_nolock;

// address=[0x313ab40]
__towlower_l;

// address=[0x313ace0]
_towlower;

// address=[0x313ad00]
___libm_error_support;

// address=[0x313b440]
___libm_setusermatherr;

// address=[0x313b480]
__ceil_default;

// address=[0x313b5e0]
__floor_default;

// address=[0x313b740]
_nexttoward;

// address=[0x313bb60]
__fgetwc_nolock;

// address=[0x313bf00]
__fgetwchar;

// address=[0x313bf20]
__getwc_nolock;

// address=[0x313bf40]
_fgetwc;

// address=[0x313c090]
_getwc;

// address=[0x313c0b0]
_getwchar;

// address=[0x313c4a0]
__ungetwc_nolock;

// address=[0x313c640]
_ungetwc;

// address=[0x313cbf0]
__openfile;

// address=[0x313cc30]
__wopenfile;

// address=[0x313cc70]
__wcsnicoll;

// address=[0x313cf60]
__wcsnicoll_l;

// address=[0x313d300]
__strnicoll;

// address=[0x313d360]
__strnicoll_l;

// address=[0x313ddf0]
__fullpath;

// address=[0x313de20]
__fullpath_dbg;

// address=[0x313de50]
__wfullpath;

// address=[0x313de80]
__wfullpath_dbg;

// address=[0x313deb0]
_wcspbrk;

// address=[0x313e5b0]
__alloc_osfhnd;

// address=[0x313e800]
__free_osfhnd;

// address=[0x313e920]
__get_osfhandle;

// address=[0x313eb00]
__open_osfhandle;

// address=[0x313ed80]
__wcsnicmp;

// address=[0x313eff0]
__wcsnicmp_l;

// address=[0x313f2f0]
__wchmod;

// address=[0x313f6f0]
__chsize;

// address=[0x313f730]
__chsize_nolock;

// address=[0x313fa30]
__chsize_s;

// address=[0x313fcb0]
__umask;

// address=[0x313fcf0]
__umask_s;

// address=[0x313fe50]
___ascii_strnicmp;

// address=[0x313fed0]
___p__fmode;

// address=[0x313ffdf]
__putch;

// address=[0x3140003]
__putch_nolock;

// address=[0x31400fd]
___dcrt_lowio_initialize_console_input;

// address=[0x3140123]
___dcrt_terminate_console_input;

// address=[0x3140140]
__dunscale;

// address=[0x31402a0]
__fdunscale;

// address=[0x31403d0]
__ldunscale;

// address=[0x31403f0]
_cos;

// address=[0x3140430]
__CIcos;

// address=[0x314046b]
__CIcos_default;

// address=[0x314047f]
__cos_default;

// address=[0x3140560]
_fegetexceptflag;

// address=[0x31405c0]
_fesetexceptflag;

// address=[0x3140de0]
__getfpcontrolword;

// address=[0x3140e50]
__getfpstatusword;

// address=[0x3140ec0]
__setfpcontrolword;

// address=[0x3140fb0]
__setfpstatusword;

// address=[0x31410a0]
_sin;

// address=[0x31410e0]
__CIsin;

// address=[0x314111b]
__CIsin_default;

// address=[0x314112f]
__sin_default;

// address=[0x3141210]
__strnset;

// address=[0x3141250]
__wremove;

// address=[0x3141290]
__wunlink;

// address=[0x31412b0]
__wrename;

// address=[0x3141420]
__waccess;

// address=[0x3141460]
__waccess_s;

// address=[0x31416a0]
__access;

// address=[0x31416e0]
__access_s;

// address=[0x31417a0]
__rmtmp;

// address=[0x31430cc]
__execv;

// address=[0x31430eb]
__execve;

// address=[0x314310b]
__spawnv;

// address=[0x314312b]
__spawnve;

// address=[0x3143138]
__wexecv;

// address=[0x3143157]
__wexecve;

// address=[0x3143177]
__wspawnv;

// address=[0x3143197]
__wspawnve;

// address=[0x3143ef2]
char * __cdecl strchr(char * const,int);

// address=[0x3143eff]
__execvp;

// address=[0x3143f1e]
__execvpe;

// address=[0x3143f3e]
__spawnvp;

// address=[0x3143f5e]
__spawnvpe;

// address=[0x3143f6b]
__wexecvp;

// address=[0x3143f8a]
__wexecvpe;

// address=[0x3143faa]
__wspawnvp;

// address=[0x3143fca]
__wspawnvpe;

// address=[0x31463b0]
public: __thiscall `anonymous namespace'::argument_list<char>::argument_list<char>(void);

// address=[0x31463f0]
public: __thiscall `anonymous namespace'::argument_list<wchar_t>::argument_list<wchar_t>(void);

// address=[0x3146450]
public: __thiscall `anonymous namespace'::argument_list<char>::~argument_list<char>(void);

// address=[0x31464c0]
public: __thiscall `anonymous namespace'::argument_list<wchar_t>::~argument_list<wchar_t>(void);

// address=[0x3146610]
public: int __thiscall `anonymous namespace'::argument_list<char>::append(char * const);

// address=[0x3146680]
public: int __thiscall `anonymous namespace'::argument_list<wchar_t>::append(wchar_t * const);

// address=[0x31466f0]
public: char * * __thiscall `anonymous namespace'::argument_list<char>::begin(void)const;

// address=[0x3146710]
public: wchar_t * * __thiscall `anonymous namespace'::argument_list<wchar_t>::begin(void)const;

// address=[0x31467b0]
public: char * * __thiscall `anonymous namespace'::argument_list<char>::end(void)const;

// address=[0x31467d0]
public: wchar_t * * __thiscall `anonymous namespace'::argument_list<wchar_t>::end(void)const;

// address=[0x31467f0]
private: int __thiscall `anonymous namespace'::argument_list<char>::expand_if_necessary(void);

// address=[0x31469a0]
private: int __thiscall `anonymous namespace'::argument_list<wchar_t>::expand_if_necessary(void);

// address=[0x3146bb0]
public: unsigned int __thiscall `anonymous namespace'::argument_list<char>::size(void)const;

// address=[0x3146be0]
public: unsigned int __thiscall `anonymous namespace'::argument_list<wchar_t>::size(void)const;

// address=[0x3146c10]
char * __cdecl strpbrk(char * const,char const * const);

// address=[0x3146c30]
wchar_t * __cdecl wcspbrk(wchar_t *,wchar_t const *);

// address=[0x3146cd0]
___p___argc;

// address=[0x3146ce0]
___p___argv;

// address=[0x3146cf0]
___p___wargv;

// address=[0x3146d00]
___p__acmdln;

// address=[0x3146d10]
___p__pgmptr;

// address=[0x3146d20]
___p__wcmdln;

// address=[0x3146d30]
___p__wpgmptr;

// address=[0x3146d40]
__get_pgmptr;

// address=[0x3146ea0]
__get_wpgmptr;

// address=[0x31470b2]
___dcrt_get_narrow_environment_from_os;

// address=[0x3147167]
___dcrt_get_wide_environment_from_os;

// address=[0x3147e78]
___dcrt_set_variable_in_narrow_environment_nolock;

// address=[0x3147e85]
___dcrt_set_variable_in_wide_environment_nolock;

// address=[0x3149c10]
_wcscspn;

// address=[0x314c130]
__isatty;

// address=[0x314c32f]
__putwch;

// address=[0x314c353]
__putwch_nolock;

// address=[0x314c3b0]
__CIexp_pentium4;

// address=[0x314c3c8]
__exp_pentium4;

// address=[0x314c720]
__cintrindisp2;

// address=[0x314c764]
__cintrindisp1;

// address=[0x314c7a7]
__ctrandisp2;

// address=[0x314c936]
__ctrandisp1;

// address=[0x314c969]
__fload;

// address=[0x314dce0]
__87except;

// address=[0x314df50]
__malloc_base;

// address=[0x314e380]
__frnd;

// address=[0x314e4b0]
__dnorm;

// address=[0x314e8c0]
__fdnorm;

// address=[0x314eb50]
__CIcos_pentium4;

// address=[0x314eb68]
__cos_pentium4;

// address=[0x314ed70]
_fetestexcept;

// address=[0x314eda0]
__CIsin_pentium4;

// address=[0x314edb8]
__sin_pentium4;

// address=[0x31509b3]
___dcrt_lowio_initialize_console_output;

// address=[0x31509d9]
___dcrt_terminate_console_output;

// address=[0x3150a00]
_log10;

// address=[0x3150a40]
__CIlog10;

// address=[0x3150a7b]
__CIlog10_default;

// address=[0x3150a8f]
__log10_default;

// address=[0x3150bb0]
_fegetenv;

// address=[0x3150be0]
_fesetenv;

// address=[0x3150c60]
_feholdexcept;

// address=[0x3150ce0]
__CIlog10_pentium4;

// address=[0x3150cf8]
__log10_pentium4;

// address=[0x3151014]
_mixerGetNumDevs@0;

// address=[0x315101a]
_mixerGetDevCapsA@12;

// address=[0x3151020]
_mixerOpen@20;

// address=[0x3151026]
_mixerClose@4;

// address=[0x315102c]
_mixerGetLineInfoA@12;

// address=[0x3151032]
_mixerGetLineControlsA@12;

// address=[0x3151038]
_mixerGetControlDetailsA@12;

// address=[0x315103e]
_mixerSetControlDetails@12;

// address=[0x3151044]
_DirectDrawCreate@12;

// address=[0x315104a]
_DirectSoundEnumerateA@8;

// address=[0x3151050]
_WSAStringToAddressW@20;

// address=[0x3151056]
_inet_pton@12;

// address=[0x315105c]
_GetAdaptersInfo@8;

// address=[0x3151062]
_GetUnicastIpAddressEntry@4;

// address=[0x3151068]
_GetUnicastIpAddressTable@8;

// address=[0x315106e]
_NotifyUnicastIpAddressChange@20;

// address=[0x3151074]
_CancelMibChangeNotify2@4;

// address=[0x315107a]
_FreeMibTable@4;

// address=[0x3151080]
_UPNP_GetTotalBytesSent;

// address=[0x31511d0]
_UPNP_GetTotalBytesReceived;

// address=[0x3151320]
_UPNP_GetTotalPacketsSent;

// address=[0x3151470]
_UPNP_GetTotalPacketsReceived;

// address=[0x31515c0]
_UPNP_GetStatusInfo;

// address=[0x3151860]
_UPNP_GetConnectionTypeInfo;

// address=[0x3151a40]
_UPNP_GetExternalIPAddress;

// address=[0x3151c30]
_UPNP_GetLinkLayerMaxBitRates;

// address=[0x3151e80]
_UPNP_AddPortMapping;

// address=[0x3152230]
_UPNP_DeletePortMapping;

// address=[0x31524e0]
_UPNP_DeletePortMappingIgnoreAnswer;

// address=[0x3152680]
_UPNP_GetPortMappingNumberOfEntries;

// address=[0x3152850]
_UPNP_GetSpecificPortMappingEntry;

// address=[0x3152c70]
_UPNP_GetGenericPortMappingEntry;

// address=[0x3153990]
_simpleUPnPcommand;

// address=[0x31539e0]
_UPNP_Discover;

// address=[0x3154780]
_UPNP_FreeDevList;

// address=[0x3154800]
_UPNP_GetValidIGD;

// address=[0x3154d30]
_UPNP_GetIGDFromUrl;

// address=[0x3154e70]
_UPNP_GetUPNPUrls;

// address=[0x31556a0]
_UPNP_FreeUPNPUrls;

// address=[0x3155910]
_parserootdesc;

// address=[0x31559b0]
_IGD_IsConnected;

// address=[0x3155b70]
_simpleUPnPcommand2;

// address=[0x3156ec0]
_UPNP_RegisterLogger;

// address=[0x3156ed0]
_UPNP_UnRegisterLogger;

// address=[0x3156ee0]
_Log;

// address=[0x3156f10]
_LogFormat;

// address=[0x3157150]
_UPNP_RegisterShutdownHandler;

// address=[0x3157170]
_UPNP_UnRegisterShutdownHandler;

// address=[0x3157190]
_IsShuttingDown;

// address=[0x31571c0]
_SetShuttingDownState;

// address=[0x3157220]
_connecthostport;

// address=[0x31575c0]
_UPNP_RegisterConnectHostPortCallback;

// address=[0x31575e0]
_UPNP_UnRegisterConnectHostPortCallback;

// address=[0x3157700]
_ParseNameValue;

// address=[0x31577b0]
_ClearNameValueList;

// address=[0x31578a0]
_GetValueFromNameValueList;

// address=[0x3157960]
_DisplayNameValueList;

// address=[0x3157f00]
_IGDstartelt;

// address=[0x3157fe0]
_IGDendelt;

// address=[0x3158170]
_IGDdata;

// address=[0x3158520]
_printIGD;

// address=[0x3158980]
_getHTTPResponse;

// address=[0x3159ae0]
_miniwget;

// address=[0x3159bd0]
_miniwget_getaddr;

// address=[0x3159ce0]
_parseURL;

// address=[0x315aa50]
_soapPostSubmit;

// address=[0x315ae40]
_parsexml;

// address=[0x315b940]
_receivedata;

// address=[0x3209fe0]
unsigned char * __cdecl _mbsnbcpy<unsigned char *>(unsigned char * const &,unsigned char const *,unsigned int);

// address=[0x320a010]
char * __cdecl _tcsncpy<char *>(char * &,char const *,unsigned int);

// address=[0x3210200]
___insecure__mbsnbcpy;

// address=[0x3210230]
___insecure__tcsncpy;

// address=[0x32126d0]
char * __cdecl _tcsncpy<char *>(char * const &,char const *,unsigned int);

// address=[0x3212700]
wchar_t * __cdecl wcscpy<wchar_t *>(wchar_t * &,wchar_t const *);

// address=[0x3212730]
char * __cdecl _tcschr(char *,unsigned int);

// address=[0x3212770]
char * __cdecl _tcsrchr(char *,unsigned int);

// address=[0x32127d0]
__tcschr;

// address=[0x3212800]
__tcsrchr;

// address=[0x3212830]
__tcsstr;

// address=[0x322c510]
char * __cdecl strcat<char *>(char * &,char const *);

// address=[0x322c680]
___insecure_strcat;

// address=[0x32489b0]
__tcscspn;

// address=[0x325dfd0]
char * __cdecl strcat<260>(char (&)[260],char const *);

// address=[0x32a7c00]
_QuazalCZlibAlloc_MM;

// address=[0x32a7c20]
_QuazalCZlibFree_MM;

// address=[0x32c35b0]
_QuazalCRTAlloc;

// address=[0x32c3620]
_QuazalCRTRealloc;

// address=[0x32c36c0]
_QuazalCRTCalloc;

// address=[0x32c3720]
_QuazalCRTFree;

// address=[0x32c4850]
char * __cdecl strcat<512>(char (&)[512],char const *);

// address=[0x32e4540]
char * __cdecl strcat<64>(char (&)[64],char const *);

// address=[0x32ecdd0]
_quazal_deflate;

// address=[0x32edd40]
_quazal_deflateEnd;

// address=[0x32eded0]
_quazal_deflateSetDictionary;

// address=[0x32ee0c0]
_quazal_deflateCopy;

// address=[0x32ee370]
_quazal_deflateReset;

// address=[0x32ee4a0]
_quazal_deflateParams;

// address=[0x32ee5f0]
_quazal_deflateTune;

// address=[0x32ee650]
_quazal_deflateBound;

// address=[0x32ee800]
_quazal_deflatePrime;

// address=[0x32ee850]
_quazal_deflateSetHeader;

// address=[0x32ee890]
_quazal_deflateInit_;

// address=[0x32ee8c0]
_quazal_deflateInit2_;

// address=[0x32f1ce0]
_quazal_inflate;

// address=[0x32f4160]
_quazal_inflateEnd;

// address=[0x32f4220]
_quazal_inflateSetDictionary;

// address=[0x32f4380]
_quazal_inflateSync;

// address=[0x32f4560]
_quazal_inflateCopy;

// address=[0x32f4760]
_quazal_inflateReset;

// address=[0x32f48a0]
_quazal_inflateReset2;

// address=[0x32f4990]
_quazal_inflatePrime;

// address=[0x32f4a40]
_quazal_inflateMark;

// address=[0x32f4ad0]
_quazal_inflateGetHeader;

// address=[0x32f4b30]
_quazal_inflateInit_;

// address=[0x32f4b60]
_quazal_inflateInit2_;

// address=[0x32f4cc0]
_quazal_inflateSyncPoint;

// address=[0x32f4d20]
_quazal_inflateUndermine;

// address=[0x32f5d10]
_quazal_adler32;

// address=[0x32f62c0]
_quazal_adler32_combine;

// address=[0x32f62e0]
_quazal_adler32_combine64;

// address=[0x32f65b0]
_quazal_crc32;

// address=[0x32f6810]
_quazal_crc32_combine;

// address=[0x32f6830]
_quazal_get_crc_table;

// address=[0x32f6840]
_quazal_crc32_combine64;

// address=[0x32f7970]
_quazal_zlibVersion;

// address=[0x32f7980]
_quazal_zlibCompileFlags;

// address=[0x32f7ab0]
_quazal_zError;

// address=[0x32f7ad0]
_z_error;

// address=[0x32f7b00]
_quazal_zcalloc;

// address=[0x32f7b30]
_quazal_zcfree;

// address=[0x32f7bc0]
_quazal__tr_init;

// address=[0x32f7c80]
_quazal__tr_tally;

// address=[0x32f7e40]
_quazal__tr_flush_block;

// address=[0x32f8190]
_quazal__tr_align;

// address=[0x32f82d0]
_quazal__tr_stored_block;

// address=[0x32fa950]
_quazal_inflate_table;

// address=[0x32fb210]
_quazal_inflate_fast;

// address=[0x335a070]
char * __cdecl _tcsncpy<128>(char (&)[128],char const *,unsigned int);

// address=[0x335b32a]
_MapViewOfFile@20;

// address=[0x335b330]
_UnmapViewOfFile@4;

// address=[0x335b336]
_CreateFileMappingA@24;

// address=[0x335b33c]
_OutputDebugStringW@4;

// address=[0x335b342]
_GetLocalTime@4;

// address=[0x335b348]
_SetEnvironmentVariableW@8;

// address=[0x335b34e]
_DuplicateHandle@28;

// address=[0x335b354]
_CreateThread@24;

// address=[0x335b35a]
_GetExitCodeThread@8;

// address=[0x335b360]
_SuspendThread@4;

// address=[0x335b366]
_GetThreadContext@8;

// address=[0x335b36c]
_GetModuleHandleA@4;

// address=[0x335b372]
_SetUnhandledExceptionFilter@4;

// address=[0x335b378]
_ExitProcess@4;

// address=[0x335b37e]
_MulDiv@12;

// address=[0x335b384]
_FormatMessageW@28;

// address=[0x335b38a]
_GetNativeSystemInfo@4;

// address=[0x335b390]
_GetStringTypeW@16;

// address=[0x335b396]
_EncodePointer@4;

// address=[0x335b39c]
_InitializeCriticalSectionAndSpinCount@8;

// address=[0x335b3a2]
_CreateEventW@16;

// address=[0x335b3a8]
_TlsAlloc@0;

// address=[0x335b3ae]
_TlsGetValue@4;

// address=[0x335b3b4]
_TlsSetValue@8;

// address=[0x335b3ba]
_TlsFree@4;

// address=[0x335b3c0]
_GetSystemTimeAsFileTime@4;

// address=[0x335b3c6]
_CompareStringW@24;

// address=[0x335b3cc]
_LCMapStringW@24;

// address=[0x335b3d2]
_GetLocaleInfoW@16;

// address=[0x335b3d8]
_GetCPInfo@8;

// address=[0x335b3de]
_UnhandledExceptionFilter@4;

// address=[0x335b3e4]
_TerminateProcess@8;

// address=[0x335b3ea]
_IsProcessorFeaturePresent@4;

// address=[0x335b3f0]
_InitializeSListHead@4;

// address=[0x335b3f6]
_IsDebuggerPresent@0;

// address=[0x335b3fc]
_GetStartupInfoW@4;

// address=[0x335b402]
_HeapAlloc@12;

// address=[0x335b408]
_HeapFree@12;

// address=[0x335b40e]
_GetProcessHeap@0;

// address=[0x335b414]
_LocalFree@4;

// address=[0x335b41a]
_CreateTimerQueue@0;

// address=[0x335b420]
_SignalObjectAndWait@16;

// address=[0x335b426]
_SwitchToThread@0;

// address=[0x335b42c]
_GetLogicalProcessorInformation@8;

// address=[0x335b432]
_CreateTimerQueueTimer@28;

// address=[0x335b438]
_ChangeTimerQueueTimer@16;

// address=[0x335b43e]
_DeleteTimerQueueTimer@12;

// address=[0x335b444]
_GetNumaHighestNodeNumber@4;

// address=[0x335b44a]
_GetProcessAffinityMask@12;

// address=[0x335b450]
_RegisterWaitForSingleObject@24;

// address=[0x335b456]
_UnregisterWait@4;

// address=[0x335b45c]
_GetThreadTimes@20;

// address=[0x335b462]
_FreeLibraryAndExitThread@8;

// address=[0x335b468]
_LoadLibraryExW@12;

// address=[0x335b46e]
_GetVersionExW@4;

// address=[0x335b474]
_VirtualAlloc@16;

// address=[0x335b47a]
_VirtualFree@12;

// address=[0x335b480]
_VirtualProtect@16;

// address=[0x335b486]
_SetProcessAffinityMask@8;

// address=[0x335b48c]
_ReleaseSemaphore@12;

// address=[0x335b492]
_InterlockedPopEntrySList@4;

// address=[0x335b498]
_InterlockedPushEntrySList@8;

// address=[0x335b49e]
_InterlockedFlushSList@4;

// address=[0x335b4a4]
_QueryDepthSList@4;

// address=[0x335b4aa]
_UnregisterWaitEx@8;

// address=[0x335b4b0]
_WaitForMultipleObjectsEx@20;

// address=[0x335b4b6]
_RtlUnwind@16;

// address=[0x335b4bc]
_GetModuleFileNameA@12;

// address=[0x335b4c2]
_GetModuleHandleExW@12;

// address=[0x335b4c8]
_WriteConsoleW@20;

// address=[0x335b4ce]
_HeapValidate@12;

// address=[0x335b4d4]
_GetDriveTypeW@4;

// address=[0x335b4da]
_GetFullPathNameW@16;

// address=[0x335b4e0]
_GetFullPathNameA@16;

// address=[0x335b4e6]
_SetEnvironmentVariableA@8;

// address=[0x335b4ec]
_GetCurrentDirectoryA@8;

// address=[0x335b4f2]
_FindFirstFileExW@24;

// address=[0x335b4f8]
_SystemTimeToTzSpecificLocalTime@12;

// address=[0x335b4fe]
_FileTimeToSystemTime@8;

// address=[0x335b504]
_ExitThread@4;

// address=[0x335b50a]
_PeekNamedPipe@24;

// address=[0x335b510]
_SetConsoleCtrlHandler@8;

// address=[0x335b516]
_GetConsoleMode@8;

// address=[0x335b51c]
_GetNumberOfConsoleInputEvents@8;

// address=[0x335b522]
_PeekConsoleInputA@16;

// address=[0x335b528]
_ReadConsoleInputA@16;

// address=[0x335b52e]
_SetConsoleMode@8;

// address=[0x335b534]
_GetTempPathW@8;

// address=[0x335b53a]
_GetACP@0;

// address=[0x335b540]
_ReadConsoleW@20;

// address=[0x335b546]
_GetConsoleCP@0;

// address=[0x335b54c]
_HeapReAlloc@16;

// address=[0x335b552]
_HeapSize@12;

// address=[0x335b558]
_HeapQueryInformation@20;

// address=[0x335b55e]
_GetDateFormatW@24;

// address=[0x335b564]
_GetTimeFormatW@24;

// address=[0x335b56a]
_IsValidLocale@8;

// address=[0x335b570]
_GetUserDefaultLCID@0;

// address=[0x335b576]
_EnumSystemLocalesW@8;

// address=[0x335b57c]
_GetTimeZoneInformation@4;

// address=[0x335b582]
_IsValidCodePage@4;

// address=[0x335b588]
_GetOEMCP@0;

// address=[0x335b58e]
_SetStdHandle@8;

// address=[0x335b594]
_GetFileAttributesExW@12;

// address=[0x335b59a]
_SetEndOfFile@4;

// address=[0x335b5a0]
_MoveFileExW@12;

// address=[0x335b5a6]
_CreateProcessA@40;

// address=[0x335b5ac]
_FindFirstFileExA@24;

// address=[0x335b5b2]
_FindNextFileA@8;

// address=[0x335b5b8]
_GetCommandLineW@0;

// address=[0x335b5be]
_GetEnvironmentStringsW@0;

// address=[0x335b5c4]
_FreeEnvironmentStringsW@4;

// address=[0x335b5ca]
_CreateDirectoryA@8;

// address=[0x335b5d0]
_FindFirstFileA@8;

// address=[0x335b5d6]
_WaitForMultipleObjects@16;

// address=[0x335b5dc]
_GetSystemMetrics@4;

// address=[0x335b5e2]
_GetWindowRect@8;

// address=[0x335b5e8]
_wvsprintfA@12;

// address=[0x335b5ee]
_IsIconic@4;

// address=[0x335b5f4]
_ShowCursor@4;

// address=[0x335b5fa]
_SetCursor@4;

// address=[0x335b600]
_ClipCursor@4;

// address=[0x335b606]
_SetClassLongA@12;

// address=[0x335b60c]
_LoadBitmapA@8;

// address=[0x335b612]
_IntersectRect@12;

// address=[0x335b618]
_DrawTextA@20;

// address=[0x335b61e]
_CreateFontA@56;

// address=[0x335b624]
_SetBkMode@8;

// address=[0x335b62a]
_SetTextColor@8;

// address=[0x335b630]
_SetTextAlign@8;

// address=[0x335b636]
_TextOutA@20;

// address=[0x335b63c]
_GetPixel@12;

// address=[0x335b642]
_GetTextExtentPoint32A@16;

// address=[0x335b648]
_GetDeviceCaps@8;

// address=[0x335b64e]
_SHGetFolderPathW@20;

// address=[0x335b654]
_SysAllocString@4;

// address=[0x335b65a]
_GetErrorInfo@8;

// address=[0x335b660]
_VariantChangeType@16;

// address=[0x335b666]
_SetErrorInfo@8;

// address=[0x335b66c]
_CreateErrorInfo@4;

// address=[0x335d850]
__FindPESection;

// address=[0x335d8e0]
__IsNonwritableInCurrentImage;

// address=[0x335da60]
__ValidateImageBase;

// address=[0x335dae0]
__SEH_prolog4;

// address=[0x335db26]
__SEH_epilog4;

// address=[0x335db60]
__SEH_prolog4_GS;

// address=[0x335dba9]
__SEH_epilog4_GS;

// address=[0x335dbd0]
__memicmp;

// address=[0x335dd70]
__memicmp_l;

// address=[0x335e010]
_perror;

// address=[0x335e147]
__mbsnbcpy;

// address=[0x335e167]
__mbsnbcpy_l;

// address=[0x335e2d1]
__mbschr;

// address=[0x335e2ed]
__mbschr_l;

// address=[0x335e3fd]
__mbsrchr;

// address=[0x335e419]
__mbsrchr_l;

// address=[0x335e51a]
__mbscspn;

// address=[0x335e536]
__mbscspn_l;

// address=[0x335e6b8]
___dcrt_multibyte_check_type;

// address=[0x335e73b]
__ismbcspace;

// address=[0x335e752]
__ismbcspace_l;

// address=[0x335e7be]
__mbsicmp;

// address=[0x335e7da]
__mbsicmp_l;

// address=[0x335ea80]
__mbsnbcpy_s;

// address=[0x335eab0]
___ascii_memicmp;

// address=[0x335eb1f]
__mbsnbcpy_s_l;

// address=[0x335ef4c]
_WSAConnect@28;

// address=[0x335ef52]
_WSAEventSelect@12;

// address=[0x335ef58]
_WSAGetOverlappedResult@20;

// address=[0x335ef5e]
_WSARecvFrom@36;

// address=[0x335ef64]
_WSAResetEvent@4;

// address=[0x335ef6a]
_WSASendTo@36;

// address=[0x335ef70]
_WSASocketA@24;

// address=[0x335ef76]
_WSACloseEvent@4;

// address=[0x335ef7c]
_WSACreateEvent@0;

// address=[0x335ef82]
_WSAWaitForMultipleEvents@20;

// address=[0x335ef88]
_GetIpAddrTable@12;

// address=[0x335ef8e]
_GetBestRoute@12;

// address=[0x3425fb0]
char * __cdecl strcat<1024>(char (&)[1024],char const *);

// address=[0x342ea5e]
_RtlCaptureStackBackTrace@16;

// address=[0x366a000]
___xc_a;

// address=[0x366c554]
___xc_z;

// address=[0x366c658]
___xi_a;

// address=[0x366ca88]
___xi_z;

// address=[0x366cb8c]
___xl_a;

// address=[0x366cb90]
___xl_z;

// address=[0x366cb94]
___xp_a;

// address=[0x366cda0]
___dcrt_console_input_terminator;

// address=[0x366cda8]
___dcrt_console_output_terminator;

// address=[0x366cfb4]
___xp_z;

// address=[0x366d0b8]
___xt_a;

// address=[0x366d1bc]
___xt_z;

// address=[0x366e1c4]
__real@00000000;

// address=[0x3679264]
enum T_AI_TASK_FORCE_CLASS const * const g_tAITaskForceTypeToClassMap;

// address=[0x367b590]
class IAIWatchTowers * g_pWatchTowers;

// address=[0x36820c8]
__real@3f800000;

// address=[0x36828e0]
public: static unsigned int const std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >::npos;

// address=[0x36868d4]
public: static unsigned int const std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class std::allocator<wchar_t> >::npos;

// address=[0x3686a14]
const CFileEx::`vbtable';

// address=[0x3688de8]
__real@40000000;

// address=[0x3688dec]
__real@41c80000;

// address=[0x3689fb8]
__real@3fe0000000000000;

// address=[0x368abac]
__real@428e0000;

// address=[0x368abb0]
__real@447a0000;

// address=[0x368f918]
__real@3f000000;

// address=[0x368f91c]
__real@3fa66666;

// address=[0x368f920]
__real@41a00000;

// address=[0x368fb50]
__xmm@41f00000000000000000000000000000;

// address=[0x3698f40]
__real@41200000;

// address=[0x3698f44]
__real@41700000;

// address=[0x3698f48]
__real@419f7777;

// address=[0x3698f4c]
__real@42c80000;

// address=[0x3698f50]
__real@43320000;

// address=[0x3698f54]
__real@43330000;

// address=[0x3698f58]
__real@43958000;

// address=[0x3698f5c]
__real@43960000;

// address=[0x3698f60]
__real@461c3c00;

// address=[0x369c888]
__real@4024000000000000;

// address=[0x369c898]
__real@4202a05f20000000;

// address=[0x36aad68]
const std::basic_istream<char,struct std::char_traits<char> >::`vbtable';

// address=[0x36aaf4c]
const std::basic_ostream<char,struct std::char_traits<char> >::`vbtable';

// address=[0x36ab0bc]
const std::ostrstream::`vbtable';

// address=[0x36ab120]
const std::basic_istringstream<char,struct std::char_traits<char>,class std::allocator<char> >::`vbtable';

// address=[0x36ab8b0]
struct SPointF const * const g_sEffectDir16Deltas;

// address=[0x36acffc]
__real@3e4ccccd;

// address=[0x36ad000]
__real@3ed413cd;

// address=[0x36ad004]
__real@40800000;

// address=[0x36ad008]
__real@bf2b0dc1;

// address=[0x36ad00c]
__real@c1900000;

// address=[0x36ad010]
__real@c2400000;

// address=[0x36ad014]
__real@c2b40000;

// address=[0x36ad020]
__xmm@80000000800000008000000080000000;

// address=[0x36b6564]
class CStaticConfigVarInt const * const g_pMagicShieldDmgDecrease256;

// address=[0x36b6568]
class CStaticConfigVarInt const * const g_pMagicBloodlustDmgIncrease256;

// address=[0x36b656c]
class CStaticConfigVarInt const * const g_pMagicFasterCropsDecrease256;

// address=[0x36b6570]
class CStaticConfigVarInt const * const g_pMagicVikingWarmachineShotCost;

// address=[0x36c25c8]
__real@4000000000000000;

// address=[0x36c25d8]
__real@4038000000000000;

// address=[0x36c25e8]
__real@4044000000000000;

// address=[0x36c25f8]
__real@4055c00000000000;

// address=[0x36c2608]
__real@4057c00000000000;

// address=[0x36c2618]
__real@406fe00000000000;

// address=[0x36c2644]
wchar_t const * const DIRECTORY_CD_S4;

// address=[0x36c264c]
wchar_t const * const FILE_CD_ID;

// address=[0x36c2660]
wchar_t const * const DIRECTORY_SOUND_USER;

// address=[0x3701308]
__real@40f0000000000000;

// address=[0x3701318]
__real@4100000000000000;

// address=[0x3701328]
__real@4110000000000000;

// address=[0x3701338]
__real@4120000000000000;

// address=[0x3703ba4]
char const * const g_szRegKey;

// address=[0x3738ff4]
__real@358637bd;

// address=[0x3738ff8]
__real@3c23d70a;

// address=[0x3740a24]
__real@4a680000;

// address=[0x3743a10]
__real@4059000000000000;

// address=[0x3743a20]
__real@414d000000000000;

// address=[0x3743a2c]
__real@42200000;

// address=[0x3743a30]
__real@42700000;

// address=[0x3743a34]
__real@44160000;

// address=[0x3743a38]
__real@44480000;

// address=[0x3743a3c]
__real@44b40000;

// address=[0x3743a40]
__real@45200000;

// address=[0x37484d8]
__real@43200000;

// address=[0x3758148]
__real@43f00000;

// address=[0x375814c]
__real@44200000;

// address=[0x37745a8]
struct SConfigTypeString const * const asWarningTypeStrings;

// address=[0x3775074]
const std::basic_ofstream<char,struct std::char_traits<char> >::`vbtable';

// address=[0x3788e8c]
__real@41c00000;

// address=[0x3788e90]
__real@bf800000;

// address=[0x37a0548]
const std::istrstream::`vbtable';

// address=[0x37a1608]
__real@c1200000;

// address=[0x37a160c]
__real@c2480000;

// address=[0x37ab8f8]
__real@3b808081;

// address=[0x37ab8fc]
__real@42ff0000;

// address=[0x37ab900]
__real@437f0000;

// address=[0x37ae8d4]
__real@3d2aaaab;

// address=[0x37ae8d8]
__real@3daaaaab;

// address=[0x37ae8dc]
__real@41400000;

// address=[0x37bbe68]
__real@3fe8000000000000;

// address=[0x37bbe78]
__real@4008000000000000;

// address=[0x37bebf0]
struct SVehicleDirInfo const * const g_sVehicleDirInfos;

// address=[0x37bec08]
struct SVehicleDirExInfo const * const g_sVehicleDirExInfos;

// address=[0x37cd7e0]
__real@40400000;

// address=[0x37d330c]
wchar_t const * const NETGAME_INI_NAME;

// address=[0x37d8c08]
struct SPoint const * const g_sNeighborPoints;

// address=[0x37d8c38]
struct SPoint const * const g_sNeighborOrthos;

// address=[0x37d8c68]
struct SPoint const * const g_sSurroundingHexPoints;

// address=[0x37d8d90]
struct SSurroundingPoint8 const * const g_sSurroundingHexPoints8;

// address=[0x37d98d4]
int const * const Y16X16::g_iNeighborY16X16Modifiers;

// address=[0x37de3ac]
class ITiling * g_pTiling;

// address=[0x37e2010]
__real@40dffd4000000000;

// address=[0x37e2020]
__real@410fffe000000000;

// address=[0x37f48c8]
wchar_t const * const SCRIPT_START_RESOURCES_FILE;

// address=[0x381e390]
__real@37800000;

// address=[0x381e398]
__real@3ff0000000000000;

// address=[0x381e3a8]
__real@4090180000000000;

// address=[0x381e3b8]
__real@40c3880000000000;

// address=[0x3829568]
__real@3fe3333333333333;

// address=[0x3900964]
const std::basic_iostream<char,struct std::char_traits<char> >::`vbtable'{for `std::basic_istream<char,struct std::char_traits<char> >'};

// address=[0x3900970]
const std::basic_iostream<char,struct std::char_traits<char> >::`vbtable'{for `std::basic_ostream<char,struct std::char_traits<char> >'};

// address=[0x3900a00]
const std::basic_ostringstream<char,struct std::char_traits<char>,class std::allocator<char> >::`vbtable';

// address=[0x3944d28]
__real@0000000000000000;

// address=[0x3944d34]
__real@3a83126f;

// address=[0x3944d38]
__real@3cb0000000000000;

// address=[0x3944d48]
__real@3eb0c6f7a0b5ed8d;

// address=[0x3944d58]
__real@403e000000000000;

// address=[0x3944d68]
__real@41cdcd6500000000;

// address=[0x3944d78]
__real@41d5831de0000000;

// address=[0x3944d88]
__real@41d61a11a0000000;

// address=[0x3944d98]
__real@41dfffffffc00000;

// address=[0x3944da4]
__real@46fffe00;

// address=[0x3944da8]
__real@4c63e9e4e4c2f344;

// address=[0x3944db8]
__real@bff0000000000000;

// address=[0x3944dc8]
__real@c1e0000000000000;

// address=[0x3944de0]
__xmm@80000000000000008000000000000000;

// address=[0x3944e60]
__real@412e848000000000;

// address=[0x3944f88]
_Curl_handler_http;

// address=[0x3944fd0]
_Curl_handler_https;

// address=[0x3945030]
__real@408f400000000000;

// address=[0x3945070]
_Curl_wkday;

// address=[0x394508c]
_Curl_month;

// address=[0x39455c4]
_Curl_DIGEST_MD5;

// address=[0x39455d8]
_Curl_HMAC_MD5;

// address=[0x39456d8]
_SHA256_version;

// address=[0x3945844]
_X509_version;

// address=[0x3946c94]
_STACK_version;

// address=[0x3946cc8]
_BN_version;

// address=[0x3946e68]
_ASN1_version;

// address=[0x39473d4]
_MD5_version;

// address=[0x3947adc]
_OSSL_DES_version;

// address=[0x3947b04]
_OSSL_libdes_version;

// address=[0x39486f4]
_MD4_version;

// address=[0x3948724]
_lh_version;

// address=[0x3954e2c]
_x509_name_ff;

// address=[0x3954e90]
_v3_name_constraints;

// address=[0x395548c]
_RSA_version;

// address=[0x39554bc]
_DSA_version;

// address=[0x395572c]
_EC_version;

// address=[0x3955950]
_DH_version;

// address=[0x395598c]
_EVP_version;

// address=[0x3955a84]
_tls1_version_str;

// address=[0x3955b30]
_ssl3_version_str;

// address=[0x3956d00]
_CONF_version;

// address=[0x3957020]
_v3_crld;

// address=[0x3957058]
_v3_freshest_crl;

// address=[0x3957280]
_v3_idp;

// address=[0x395733c]
_PEM_version;

// address=[0x39575f0]
_dh_asn1_meth;

// address=[0x3957660]
_dhx_asn1_meth;

// address=[0x395cad4]
_RAND_version;

// address=[0x395cb08]
__real@4040000000000000;

// address=[0x395cbbc]
_v3_bcons;

// address=[0x395cc50]
_v3_info;

// address=[0x395cc88]
_v3_sinfo;

// address=[0x395cd68]
_v3_alt;

// address=[0x395ce38]
_DES_SPtrans;

// address=[0x395e60c]
_SHA1_version;

// address=[0x395e8c0]
_SHA512_version;

// address=[0x395ea1c]
_IDEA_version;

// address=[0x395eb84]
_RC2_version;

// address=[0x395ebb4]
_AES_version;

// address=[0x3961410]
_rsa_asn1_meths;

// address=[0x3961518]
_dsa_asn1_meths;

// address=[0x39617a0]
_eckey_asn1_meth;

// address=[0x3961828]
_hmac_asn1_meth;

// address=[0x39618b0]
_cmac_asn1_meth;

// address=[0x3961934]
_CONF_def_version;

// address=[0x3961fc4]
_v3_cpols;

// address=[0x39621fc]
_v3_policy_constraints;

// address=[0x3962290]
_v3_nscert;

// address=[0x39622c8]
_v3_key_usage;

// address=[0x3962318]
_v3_ext_ku;

// address=[0x3962350]
_v3_ocsp_accresp;

// address=[0x39623d8]
_v3_pkey_usage_period;

// address=[0x396246c]
_v3_sxnet;

// address=[0x3962558]
_v3_ns_ia5_list;

// address=[0x3962774]
_v3_skey_id;

// address=[0x39627b8]
_v3_akey_id;

// address=[0x39627fc]
_v3_crl_num;

// address=[0x3962834]
_v3_delta_crl;

// address=[0x396286c]
_v3_inhibit_anyp;

// address=[0x39628c8]
_v3_crl_reason;

// address=[0x396290c]
_v3_ocsp_crlid;

// address=[0x3962944]
_v3_ocsp_acutoff;

// address=[0x396297c]
_v3_crl_invdate;

// address=[0x39629b4]
_v3_crl_hold;

// address=[0x39629ec]
_v3_ocsp_nonce;

// address=[0x3962a24]
_v3_ocsp_nocheck;

// address=[0x3962a5c]
_v3_ocsp_serviceloc;

// address=[0x3962ae4]
_v3_pci;

// address=[0x3962b28]
_v3_policy_mappings;

// address=[0x3962bf8]
_v3_ct_scts;

// address=[0x3962df8]
_rsa_pkey_meth;

// address=[0x3962e80]
_dh_pkey_meth;

// address=[0x3962ef0]
_dhx_pkey_meth;

// address=[0x3962f88]
_dsa_pkey_meth;

// address=[0x3963010]
_ec_pkey_meth;

// address=[0x3963098]
_hmac_pkey_meth;

// address=[0x3963120]
_cmac_pkey_meth;

// address=[0x39631f8]
_ECDSA_version;

// address=[0x396322c]
_ECDH_version;

// address=[0x396325c]
_dtls1_version_str;

// address=[0x3963290]
__real@4050000000000000;

// address=[0x396368c]
_TXT_DB_version;

// address=[0x396398c]
_RC4_version;

// address=[0x3964d4c]
_BF_version;

// address=[0x3964d80]
_CAST_S_table0;

// address=[0x3965180]
_CAST_S_table1;

// address=[0x3965580]
_CAST_S_table2;

// address=[0x3965980]
_CAST_S_table3;

// address=[0x3965d80]
_CAST_S_table4;

// address=[0x3966180]
_CAST_S_table5;

// address=[0x3966580]
_CAST_S_table6;

// address=[0x3966980]
_CAST_S_table7;

// address=[0x39673e8]
_CAST_version;

// address=[0x3967418]
_SHA_version;

// address=[0x3967448]
_RMD160_version;

// address=[0x396e590]
_USZlib_z_errmsg;

// address=[0x396e5c0]
_USZlib_inflate_copyright;

// address=[0x397d920]
__real@3dcccccd;

// address=[0x397d924]
__real@3f4ccccd;

// address=[0x397d928]
__real@3f666666;

// address=[0x397d92c]
__real@3fc00000;

// address=[0x397d930]
__real@40200000;

// address=[0x397d934]
__real@bdcccccd;

// address=[0x397d938]
__real@bf000000;

// address=[0x39a5f18]
__real@3ea8f5c3;

// address=[0x39ca730]
_IID_IAxWinAmbientDispatch;

// address=[0x39cac54]
_IID_IAMFilterGraphCallback;

// address=[0x39cacb4]
_IID_IAxWinAmbientDispatchEx;

// address=[0x39cacc8]
_IID_IInternalConnection;

// address=[0x39cacdc]
_CLSID_Registrar;

// address=[0x39cacf0]
_IID_IRegistrar;

// address=[0x39cad04]
_IID_IDocHostUIHandlerDispatch;

// address=[0x39cad2c]
_IID_IAxWinHostWindow;

// address=[0x39cad40]
_IID_IAxWinHostWindowLic;

// address=[0x39e7944]
__real@3ca3d70a;

// address=[0x39e7948]
__real@3e19999a;

// address=[0x39e794c]
__real@3e800000;

// address=[0x39e7950]
__real@3f7d70a4;

// address=[0x39e7954]
__real@3f800347;

// address=[0x39e7958]
__real@3f8ccccd;

// address=[0x39e795c]
__real@3fa00000;

// address=[0x39e7960]
__real@42480000;

// address=[0x39e7964]
__real@42a00000;

// address=[0x39e7968]
__real@43480000;

// address=[0x39e796c]
__real@467a0000;

// address=[0x39f6884]
_MF_BYTESTREAM_ORIGIN_NAME;

// address=[0x39f6898]
_MF_BYTESTREAM_CONTENT_TYPE;

// address=[0x39f68ac]
_MF_BYTESTREAM_DURATION;

// address=[0x39f68c0]
_MF_BYTESTREAM_LAST_MODIFIED_TIME;

// address=[0x39f68d4]
_MF_BYTESTREAM_IFO_FILE_URI;

// address=[0x39f68e8]
_MF_BYTESTREAM_DLNA_PROFILE_ID;

// address=[0x39f68fc]
_MF_BYTESTREAM_EFFECTIVE_URL;

// address=[0x39f6910]
_MF_BYTESTREAM_TRANSCODED;

// address=[0x39f6924]
_CLSID_MFByteStreamProxyClassFactory;

// address=[0x39f71e8]
__GUID_bcde0395_e52f_467c_8e3d_c4579291692e;

// address=[0x39f71fc]
__GUID_a95664d2_9614_4f35_a746_de8db63617e6;

// address=[0x39f750c]
__GUID_657804fa_d6ad_4496_8a60_352752af4f89;

// address=[0x39f7520]
__GUID_5cdf2c82_841e_4546_9722_0cf74078229a;

// address=[0x39f7754]
__GUID_a09513ed_c709_4d21_bd7b_5f34c47f3947;

// address=[0x39f7768]
__GUID_ae2de0e4_5bca_4f2d_aa46_5d13f8fdb3a9;

// address=[0x39f777c]
__GUID_7fb7b48f_531d_44a2_bcb3_5ad5a134b3dc;

// address=[0x39f7790]
__GUID_7d8b1437_dd53_4350_9c1b_1ee2890bd938;

// address=[0x39f7918]
__GUID_2a07407e_6497_4a18_9787_32f79bd0d98f;

// address=[0x39f79a4]
__GUID_3a5acc00_c557_11d0_8a2b_00a0c9255ac1;

// address=[0x39f79b8]
__GUID_41887440_c558_11d0_8a2b_00a0c9255ac1;

// address=[0x39fa850]
__GUID_1cb9ad4c_dbfa_4c32_b178_c2f568a703b2;

// address=[0x39fa864]
__GUID_f294acfc_3146_4483_a7bf_addca7c260e2;

// address=[0x39fa878]
__GUID_87ce5498_68d6_44e5_9215_6da47ef883d8;

// address=[0x39fa88c]
__GUID_f4b1a599_7266_4319_a8ca_e70acb11e8cd;

// address=[0x39fb3d8]
__GUID_24918acc_64b3_37c1_8ca9_74a66e9957a8;

// address=[0x3a1a4c0]
__real@34000000;

// address=[0x3a1a4c8]
__real@404a800000000000;

// address=[0x3a1a4d8]
__real@41f0000000000000;

// address=[0x3a1a4f0]
__xmm@7fffffff7fffffff7fffffff7fffffff;

// address=[0x3a1a8ac]
__real@0da24260;

// address=[0x3a1a8b0]
__real@26901d7d;

// address=[0x3a1a8b4]
__real@31800000;

// address=[0x3a1a8b8]
__real@38000000;

// address=[0x3a1a8bc]
__real@38800000;

// address=[0x3a1a8c0]
__real@3a51b717;

// address=[0x3a1a8c4]
__real@3d4ccccd;

// address=[0x3a1a8c8]
__real@3e124925;

// address=[0x3a1a8cc]
__real@3f5b6db7;

// address=[0x3a1a8d0]
__real@47000000;

// address=[0x3a1a8d4]
__real@501502f9;

// address=[0x3a1a8d8]
__real@c0000000;

// address=[0x3a1a8dc]
__real@c7000000;

// address=[0x3a1a9d0]
__real@3a2a152d;

// address=[0x3a1a9d8]
__real@3fe62e42fefa39ef;

// address=[0x3a1ab64]
__real@36500998;

// address=[0x3a1ab68]
__real@38d1b717;

// address=[0x3a1ab6c]
__real@3bcb295f;

// address=[0x3a1ab70]
__real@3be21965;

// address=[0x3a1ab74]
__real@3cfdf3b6;

// address=[0x3a1ab78]
__real@3d23d70a;

// address=[0x3a1ab7c]
__real@3d800000;

// address=[0x3a1ab80]
__real@3db851ec;

// address=[0x3a1ab84]
__real@3dc00000;

// address=[0x3a1ab88]
__real@3e000000;

// address=[0x3a1ab8c]
__real@3ecccccd;

// address=[0x3a1ab90]
__real@3f0ccccd;

// address=[0x3a1ab94]
__real@3f2b851f;

// address=[0x3a1ab98]
__real@3f333333;

// address=[0x3a1ab9c]
__real@3f3504f7;

// address=[0x3a1aba0]
__real@3f400000;

// address=[0x3a1aba4]
__real@3f59999a;

// address=[0x3a1aba8]
__real@3f6b851f;

// address=[0x3a1abac]
__real@3f7eb852;

// address=[0x3a1abb0]
__real@3f8020c5;

// address=[0x3a1abb4]
__real@3f99999a;

// address=[0x3a1abb8]
__real@3fc1cac083126e98;

// address=[0x3a1abc8]
__real@3fd3333333333333;

// address=[0x3a1abd8]
__real@3fd999999999999a;

// address=[0x3a1abe8]
__real@3fe947ae147ae148;

// address=[0x3a1abf8]
__real@3ff428f5c28f5c29;

// address=[0x3a1ac08]
__real@3ff71547652b82fe;

// address=[0x3a1ac14]
__real@40a00000;

// address=[0x3a1ac18]
__real@40c00000;

// address=[0x3a1ac1c]
__real@41000000;

// address=[0x3a1ac20]
__real@42000000;

// address=[0x3a1ac24]
__real@42280000;

// address=[0x3a1ac28]
__real@42800000;

// address=[0x3a1ac2c]
__real@43230000;

// address=[0x3a1ac30]
__real@47800000;

// address=[0x3a1ac34]
__real@bcfdf3b6;

// address=[0x3a1ac38]
__real@be800000;

// address=[0x3a1ac3c]
__real@bfc00000;

// address=[0x3a1ac40]
__real@c0800000;

// address=[0x3a1ac44]
__real@c1e00000;

// address=[0x3a1ac48]
__real@c1ff3333;

// address=[0x3a1ac4c]
__real@c7800000;

// address=[0x3a1b8a4]
__real@1e3ce508;

// address=[0x3a1b8a8]
__real@2edbe6ff;

// address=[0x3a1b8ac]
__real@3089705f;

// address=[0x3a1b8b0]
__real@3851b717;

// address=[0x3a1b8b4]
__real@3a156c0d;

// address=[0x3a1b8b8]
__real@3c75c28f;

// address=[0x3a1b8c0]
__real@3cd203af9ee75616;

// address=[0x3a1b8cc]
__real@3cf5c28f;

// address=[0x3a1b8d0]
__real@3db00965;

// address=[0x3a1b8d4]
__real@3e22f983;

// address=[0x3a1b8d8]
__real@3e6b851f;

// address=[0x3a1b8dc]
__real@3e88d64d;

// address=[0x3a1b8e0]
__real@3ea1e8e6;

// address=[0x3a1b8e4]
__real@3edcf805;

// address=[0x3a1b8e8]
__real@3efbe0df;

// address=[0x3a1b8ec]
__real@3f08d64d;

// address=[0x3a1b8f0]
__real@3f21e8e6;

// address=[0x3a1b8f4]
__real@3f2db121;

// address=[0x3a1b8f8]
__real@3f326a01;

// address=[0x3a1b8fc]
__real@3f733333;

// address=[0x3a1b900]
__real@3f9ae148;

// address=[0x3a1b904]
__real@3fb7aace;

// address=[0x3a1b908]
__real@3fb999999999999a;

// address=[0x3a1b914]
__real@3fc90fdb;

// address=[0x3a1b918]
__real@3feccccccccccccd;

// address=[0x3a1b924]
__real@41100000;

// address=[0x3a1b928]
__real@41900000;

// address=[0x3a1b92c]
__real@41f00000;

// address=[0x3a1b930]
__real@42c2d174;

// address=[0x3a1b934]
__real@4e6e6b28;

// address=[0x3a1b938]
__real@5368d4a5;

// address=[0x3a1b93c]
__real@bdfbe22e;

// address=[0x3a1b940]
__real@be4ccccd;

// address=[0x3a1b944]
__real@bfc90fdb;

// address=[0x3a1b948]
__real@d01502f9;

// address=[0x3a1b964]
__real@388637be;

// address=[0x3a1bb00]
__real@3f490fdb;

// address=[0x3a1e7cc]
_tf_select_table;

// address=[0x3a1e934]
__real@2b8cbccc;

// address=[0x3a1e938]
__real@3c03126f;

// address=[0x3a1e93c]
__real@3e99999a;

// address=[0x3a1ea60]
__real@129e74d2;

// address=[0x3a1ea64]
__real@3a1d4952;

// address=[0x3a1ea68]
__real@3b800000;

// address=[0x3a1ea6c]
__real@3c800000;

// address=[0x3a1ea70]
__real@3f3504f3;

// address=[0x3a1ea74]
__real@3fb504f3;

// address=[0x3a1ea78]
__real@be000000;

// address=[0x3a1ec10]
_eMeans;

// address=[0x3a1ecd8]
__real@41800000;

// address=[0x3a1ecdc]
__real@c1100000;

// address=[0x3a1ece0]
__real@c1600000;

// address=[0x3a206fc]
_silk_lsb_iCDF;

// address=[0x3a20700]
_silk_uniform3_iCDF;

// address=[0x3a20704]
_silk_uniform4_iCDF;

// address=[0x3a20708]
_silk_uniform5_iCDF;

// address=[0x3a20710]
_silk_uniform6_iCDF;

// address=[0x3a20718]
_silk_uniform8_iCDF;

// address=[0x3a20720]
_silk_NLSF_EXT_iCDF;

// address=[0x3a20728]
_silk_LTPscale_iCDF;

// address=[0x3a2072c]
_silk_LTPScales_table_Q14;

// address=[0x3a20734]
_silk_type_offset_VAD_iCDF;

// address=[0x3a20738]
_silk_type_offset_no_VAD_iCDF;

// address=[0x3a2073c]
_silk_stereo_pred_quant_Q13;

// address=[0x3a2075c]
_silk_stereo_pred_joint_iCDF;

// address=[0x3a20778]
_silk_stereo_only_code_mid_iCDF;

// address=[0x3a2077c]
_silk_LBRR_flags_iCDF_ptr;

// address=[0x3a20784]
_silk_NLSF_interpolation_factor_iCDF;

// address=[0x3a2078c]
_silk_TargetRate_table_NB;

// address=[0x3a207ac]
_silk_TargetRate_table_MB;

// address=[0x3a207cc]
_silk_TargetRate_table_WB;

// address=[0x3a207ec]
_silk_SNR_table_Q1;

// address=[0x3a207fc]
_silk_Quantization_Offsets_Q10;

// address=[0x3a20804]
_silk_Transition_LP_B_Q28;

// address=[0x3a20840]
_silk_Transition_LP_A_Q28;

// address=[0x3a20c84]
__real@c1000000;

// address=[0x3a2132c]
_net;

// address=[0x3a214d0]
__real@40c45f30e0000000;

// address=[0x3a214dc]
__real@d8635fa9;

// address=[0x3a21f70]
_silk_Resampler_3_4_COEFS;

// address=[0x3a21fac]
_silk_Resampler_2_3_COEFS;

// address=[0x3a21fd4]
_silk_Resampler_1_2_COEFS;

// address=[0x3a21ff0]
_silk_Resampler_1_3_COEFS;

// address=[0x3a22018]
_silk_Resampler_1_4_COEFS;

// address=[0x3a22040]
_silk_Resampler_1_6_COEFS;

// address=[0x3a22068]
_silk_Resampler_2_3_COEFS_LQ;

// address=[0x3a22078]
_silk_resampler_frac_FIR_12;

// address=[0x3a22250]
_silk_pulses_per_block_iCDF;

// address=[0x3a22304]
_silk_rate_levels_iCDF;

// address=[0x3a22318]
_silk_pulses_per_block_BITS_Q5;

// address=[0x3a223bc]
_silk_rate_levels_BITS_Q5;

// address=[0x3a223d0]
_silk_max_pulses_table;

// address=[0x3a223d4]
_silk_shell_code_table_offsets;

// address=[0x3a223e8]
_silk_shell_code_table0;

// address=[0x3a22480]
_silk_shell_code_table1;

// address=[0x3a22518]
_silk_shell_code_table2;

// address=[0x3a225b0]
_silk_shell_code_table3;

// address=[0x3a22648]
_silk_sign_iCDF;

// address=[0x3a22748]
_silk_gain_iCDF;

// address=[0x3a22760]
_silk_delta_gain_iCDF;

// address=[0x3a22798]
_silk_pitch_lag_iCDF;

// address=[0x3a227b8]
_silk_pitch_delta_iCDF;

// address=[0x3a227d0]
_silk_pitch_contour_iCDF;

// address=[0x3a227f4]
_silk_pitch_contour_NB_iCDF;

// address=[0x3a22800]
_silk_pitch_contour_10_ms_iCDF;

// address=[0x3a2280c]
_silk_pitch_contour_10_ms_NB_iCDF;

// address=[0x3a22828]
_silk_LTP_per_index_iCDF;

// address=[0x3a2282c]
_silk_LTP_gain_iCDF_ptrs;

// address=[0x3a22838]
_silk_LTP_gain_BITS_Q5_ptrs;

// address=[0x3a22844]
_silk_LTP_gain_middle_avg_RD_Q14;

// address=[0x3a22848]
_silk_LTP_vq_ptrs_Q7;

// address=[0x3a22854]
_silk_LTP_vq_gain_ptrs_Q7;

// address=[0x3a22860]
_silk_LTP_vq_sizes;

// address=[0x3a231f4]
__real@3efffe00;

// address=[0x3a23300]
__real@3c000000;

// address=[0x3a23304]
__real@3e866666;

// address=[0x3a23308]
__real@3f19999a;

// address=[0x3a2330c]
__real@3f866666;

// address=[0x3a23310]
__real@3fd47ae140000000;

// address=[0x3a23320]
__real@400a934f0979a36c;

// address=[0x3a2332c]
__real@407fef9e;

// address=[0x3a23330]
__real@be23d70a;

// address=[0x3a23334]
__real@becccccd;

// address=[0x3a234a4]
__real@3b83126f;

// address=[0x3a236cc]
__real@461c4000;

// address=[0x3a23840]
__real@41a80000;

// address=[0x3a23844]
__real@44800000;

// address=[0x3a23848]
__real@bd4ccccd;

// address=[0x3a23968]
__real@39800000;

// address=[0x3a2396c]
__real@45800000;

// address=[0x3a23970]
__real@46000000;

// address=[0x3a23974]
__real@46800000;

// address=[0x3a23978]
__real@48800000;

// address=[0x3a23980]
_silk_NLSF_CB_WB;

// address=[0x3a23e90]
_silk_NLSF_CB_NB_MB;

// address=[0x3a25ed8]
__real@3fefff2e40000000;

// address=[0x3a25ee8]
__real@bfefff2e40000000;

// address=[0x3a26288]
__real@40490fdb;

// address=[0x3a26b90]
__real@3f50624dd2f1a9fc;

// address=[0x3a26b9c]
__real@457a0000;

// address=[0x3a26ba0]
__real@c47a0000;

// address=[0x3a26f08]
__real@7f7fffff;

// address=[0x3a27028]
__real@3c888889;

// address=[0x3a27154]
__real@322bcc77;

// address=[0x3a28278]
_silk_CB_lags_stage2;

// address=[0x3a282a4]
_silk_nb_cbk_searchs_stage3;

// address=[0x3a282a8]
_silk_CB_lags_stage3;

// address=[0x3a28330]
_silk_Lag_range_stage3;

// address=[0x3a28348]
_silk_CB_lags_stage2_10_ms;

// address=[0x3a28350]
_silk_CB_lags_stage3_10_ms;

// address=[0x3a28368]
_silk_Lag_range_stage3_10_ms;

// address=[0x3a28548]
__real@3e112e0be0000000;

// address=[0x3a28558]
__real@3ee4f8b580000000;

// address=[0x3a28568]
__real@c000000000000000;

// address=[0x3a287a8]
__real@36a7c5ac;

// address=[0x3a287b0]
_silk_LSFCosTab_FIX_Q12;

// address=[0x3a40e60]
__real@bfe0000000000000;

// address=[0x3a40e6c]
__real@ffc00000;

// address=[0x3a40e70]
__xmm@3f800000000000000000000000000000;

// address=[0x3a55d98]
__real@3f9c61aa;

// address=[0x3a55da0]
__real@4010000000000000;

// address=[0x3a55db0]
__real@4076800000000000;

// address=[0x3a55dc0]
__real@41747aad00000000;

// address=[0x3a55dcc]
__real@43340000;

// address=[0x3a55dd0]
__real@43b40000;

// address=[0x3a55dd4]
__real@44000000;

// address=[0x3a55dd8]
__real@4ba3d568;

// address=[0x3a55ddc]
__real@4f000000;

// address=[0x3a56008]
__real@3e2aab8a;

// address=[0x3a56010]
__real@3fc555555567a895;

// address=[0x3a56020]
__real@40dfffc000000000;

// address=[0x3a5602c]
__real@46fffd00;

// address=[0x3a56030]
__real@be2aab8a;

// address=[0x3a56034]
__real@beaaaa3b;

// address=[0x3a56038]
__real@bfc555555567a895;

// address=[0x3a56048]
__real@bfd55555554c2bb5;

// address=[0x3a56058]
__real@c0e0000000000000;

// address=[0x3a56064]
__real@c6ffff00;

// address=[0x3a56070]
__xmm@7fffffffffffffff7fffffffffffffff;

// address=[0x3a78e84]
__real@3ba3d70a;

// address=[0x3aac174]
const std::basic_stringstream<char,struct std::char_traits<char>,class std::allocator<char> >::`vbtable'{for `std::basic_istream<char,struct std::char_traits<char> >'};

// address=[0x3aac180]
const std::basic_stringstream<char,struct std::char_traits<char>,class std::allocator<char> >::`vbtable'{for `std::basic_ostream<char,struct std::char_traits<char> >'};

// address=[0x3ab038c]
_IID_IUnknown;

// address=[0x3ab03a0]
_IID_AsyncIUnknown;

// address=[0x3ab03b4]
_IID_IClassFactory;

// address=[0x3ab03c8]
_IID_ICreateTypeInfo;

// address=[0x3ab03dc]
_IID_ICreateTypeInfo2;

// address=[0x3ab03f0]
_IID_ICreateTypeLib;

// address=[0x3ab0404]
_IID_ICreateTypeLib2;

// address=[0x3ab0418]
_IID_IDispatch;

// address=[0x3ab042c]
_IID_IEnumVARIANT;

// address=[0x3ab0440]
_IID_ITypeComp;

// address=[0x3ab0454]
_IID_ITypeInfo;

// address=[0x3ab0468]
_IID_ITypeInfo2;

// address=[0x3ab047c]
_IID_ITypeLib;

// address=[0x3ab0490]
_IID_ITypeLib2;

// address=[0x3ab04a4]
_IID_ITypeChangeEvents;

// address=[0x3ab04b8]
_IID_IErrorInfo;

// address=[0x3ab04cc]
_IID_ICreateErrorInfo;

// address=[0x3ab04e0]
_IID_ISupportErrorInfo;

// address=[0x3ab04f4]
_IID_ITypeFactory;

// address=[0x3ab0508]
_IID_ITypeMarshal;

// address=[0x3ab051c]
_IID_IRecordInfo;

// address=[0x3ab0530]
_IID_IErrorLog;

// address=[0x3ab0544]
_IID_IPropertyBag;

// address=[0x3ab0558]
_PKEY_NAME;

// address=[0x3ab0570]
_PKEY_Device_DeviceDesc;

// address=[0x3ab0588]
_PKEY_Device_HardwareIds;

// address=[0x3ab05a0]
_PKEY_Device_CompatibleIds;

// address=[0x3ab05b8]
_PKEY_Device_Service;

// address=[0x3ab05d0]
_PKEY_Device_Class;

// address=[0x3ab05e8]
_PKEY_Device_ClassGuid;

// address=[0x3ab0600]
_PKEY_Device_Driver;

// address=[0x3ab0618]
_PKEY_Device_ConfigFlags;

// address=[0x3ab0630]
_PKEY_Device_Manufacturer;

// address=[0x3ab0648]
_PKEY_Device_FriendlyName;

// address=[0x3ab0660]
_PKEY_Device_LocationInfo;

// address=[0x3ab0678]
_PKEY_Device_PDOName;

// address=[0x3ab0690]
_PKEY_Device_Capabilities;

// address=[0x3ab06a8]
_PKEY_Device_UINumber;

// address=[0x3ab06c0]
_PKEY_Device_UpperFilters;

// address=[0x3ab06d8]
_PKEY_Device_LowerFilters;

// address=[0x3ab06f0]
_PKEY_Device_BusTypeGuid;

// address=[0x3ab0708]
_PKEY_Device_LegacyBusType;

// address=[0x3ab0720]
_PKEY_Device_BusNumber;

// address=[0x3ab0738]
_PKEY_Device_EnumeratorName;

// address=[0x3ab0750]
_PKEY_Device_Security;

// address=[0x3ab0768]
_PKEY_Device_SecuritySDS;

// address=[0x3ab0780]
_PKEY_Device_DevType;

// address=[0x3ab0798]
_PKEY_Device_Exclusive;

// address=[0x3ab07b0]
_PKEY_Device_Characteristics;

// address=[0x3ab07c8]
_PKEY_Device_Address;

// address=[0x3ab07e0]
_PKEY_Device_UINumberDescFormat;

// address=[0x3ab07f8]
_PKEY_Device_PowerData;

// address=[0x3ab0810]
_PKEY_Device_RemovalPolicy;

// address=[0x3ab0828]
_PKEY_Device_RemovalPolicyDefault;

// address=[0x3ab0840]
_PKEY_Device_RemovalPolicyOverride;

// address=[0x3ab0858]
_PKEY_Device_InstallState;

// address=[0x3ab0870]
_PKEY_Device_LocationPaths;

// address=[0x3ab0888]
_PKEY_Device_BaseContainerId;

// address=[0x3ab08a0]
_PKEY_Device_DevNodeStatus;

// address=[0x3ab08b8]
_PKEY_Device_ProblemCode;

// address=[0x3ab08d0]
_PKEY_Device_EjectionRelations;

// address=[0x3ab08e8]
_PKEY_Device_RemovalRelations;

// address=[0x3ab0900]
_PKEY_Device_PowerRelations;

// address=[0x3ab0918]
_PKEY_Device_BusRelations;

// address=[0x3ab0930]
_PKEY_Device_Parent;

// address=[0x3ab0948]
_PKEY_Device_Children;

// address=[0x3ab0960]
_PKEY_Device_Siblings;

// address=[0x3ab0978]
_PKEY_Device_TransportRelations;

// address=[0x3ab0990]
_PKEY_Device_Reported;

// address=[0x3ab09a8]
_PKEY_Device_Legacy;

// address=[0x3ab09c0]
_PKEY_Device_InstanceId;

// address=[0x3ab09d8]
_PKEY_Device_ContainerId;

// address=[0x3ab09f0]
_PKEY_Device_ModelId;

// address=[0x3ab0a08]
_PKEY_Device_FriendlyNameAttributes;

// address=[0x3ab0a20]
_PKEY_Device_ManufacturerAttributes;

// address=[0x3ab0a38]
_PKEY_Device_PresenceNotForDevice;

// address=[0x3ab0a50]
_PKEY_Device_SignalStrength;

// address=[0x3ab0a68]
_PKEY_Device_IsAssociateableByUserAction;

// address=[0x3ab0a80]
_PKEY_Numa_Proximity_Domain;

// address=[0x3ab0a98]
_PKEY_Device_DHP_Rebalance_Policy;

// address=[0x3ab0ab0]
_PKEY_Device_Numa_Node;

// address=[0x3ab0ac8]
_PKEY_Device_BusReportedDeviceDesc;

// address=[0x3ab0ae0]
_PKEY_Device_InstallInProgress;

// address=[0x3ab0af8]
_PKEY_Device_DriverDate;

// address=[0x3ab0b10]
_PKEY_Device_DriverVersion;

// address=[0x3ab0b28]
_PKEY_Device_DriverDesc;

// address=[0x3ab0b40]
_PKEY_Device_DriverInfPath;

// address=[0x3ab0b58]
_PKEY_Device_DriverInfSection;

// address=[0x3ab0b70]
_PKEY_Device_DriverInfSectionExt;

// address=[0x3ab0b88]
_PKEY_Device_MatchingDeviceId;

// address=[0x3ab0ba0]
_PKEY_Device_DriverProvider;

// address=[0x3ab0bb8]
_PKEY_Device_DriverPropPageProvider;

// address=[0x3ab0bd0]
_PKEY_Device_DriverCoInstallers;

// address=[0x3ab0be8]
_PKEY_Device_ResourcePickerTags;

// address=[0x3ab0c00]
_PKEY_Device_ResourcePickerExceptions;

// address=[0x3ab0c18]
_PKEY_Device_DriverRank;

// address=[0x3ab0c30]
_PKEY_Device_DriverLogoLevel;

// address=[0x3ab0c48]
_PKEY_Device_NoConnectSound;

// address=[0x3ab0c60]
_PKEY_Device_GenericDriverInstalled;

// address=[0x3ab0c78]
_PKEY_Device_AdditionalSoftwareRequested;

// address=[0x3ab0c90]
_PKEY_Device_SafeRemovalRequired;

// address=[0x3ab0ca8]
_PKEY_Device_SafeRemovalRequiredOverride;

// address=[0x3ab0cc0]
_PKEY_DrvPkg_Model;

// address=[0x3ab0cd8]
_PKEY_DrvPkg_VendorWebSite;

// address=[0x3ab0cf0]
_PKEY_DrvPkg_DetailedDescription;

// address=[0x3ab0d08]
_PKEY_DrvPkg_DocumentationLink;

// address=[0x3ab0d20]
_PKEY_DrvPkg_Icon;

// address=[0x3ab0d38]
_PKEY_DrvPkg_BrandingIcon;

// address=[0x3ab0d50]
_PKEY_DeviceClass_UpperFilters;

// address=[0x3ab0d68]
_PKEY_DeviceClass_LowerFilters;

// address=[0x3ab0d80]
_PKEY_DeviceClass_Security;

// address=[0x3ab0d98]
_PKEY_DeviceClass_SecuritySDS;

// address=[0x3ab0db0]
_PKEY_DeviceClass_DevType;

// address=[0x3ab0dc8]
_PKEY_DeviceClass_Exclusive;

// address=[0x3ab0de0]
_PKEY_DeviceClass_Characteristics;

// address=[0x3ab0df8]
_PKEY_DeviceClass_Name;

// address=[0x3ab0e10]
_PKEY_DeviceClass_ClassName;

// address=[0x3ab0e28]
_PKEY_DeviceClass_Icon;

// address=[0x3ab0e40]
_PKEY_DeviceClass_ClassInstaller;

// address=[0x3ab0e58]
_PKEY_DeviceClass_PropPageProvider;

// address=[0x3ab0e70]
_PKEY_DeviceClass_NoInstallClass;

// address=[0x3ab0e88]
_PKEY_DeviceClass_NoDisplayClass;

// address=[0x3ab0ea0]
_PKEY_DeviceClass_SilentInstall;

// address=[0x3ab0eb8]
_PKEY_DeviceClass_NoUseClass;

// address=[0x3ab0ed0]
_PKEY_DeviceClass_DefaultService;

// address=[0x3ab0ee8]
_PKEY_DeviceClass_IconPath;

// address=[0x3ab0f00]
_PKEY_DeviceClass_ClassCoInstallers;

// address=[0x3ab0f18]
_PKEY_DeviceInterface_FriendlyName;

// address=[0x3ab0f30]
_PKEY_DeviceInterface_Enabled;

// address=[0x3ab0f48]
_PKEY_DeviceInterface_ClassGuid;

// address=[0x3ab0f60]
_PKEY_DeviceInterfaceClass_DefaultInterface;

// address=[0x3ab0f78]
_PKEY_FunctionInstance;

// address=[0x3ab0f90]
_FMTID_FD;

// address=[0x3ab0fa4]
_PKEY_FD_Visibility;

// address=[0x3ab0fbc]
_FMTID_Device;

// address=[0x3ab0fd0]
_PKEY_Device_NotPresent;

// address=[0x3ab0fe8]
_PKEY_Device_QueueSize;

// address=[0x3ab1000]
_PKEY_Device_Status;

// address=[0x3ab1018]
_PKEY_Device_Comment;

// address=[0x3ab1030]
_PKEY_Device_Model;

// address=[0x3ab1048]
_FMTID_DeviceInterface;

// address=[0x3ab105c]
_PKEY_DeviceInterface_DevicePath;

// address=[0x3ab1074]
_PKEY_DeviceDisplay_Address;

// address=[0x3ab108c]
_PKEY_DeviceDisplay_DiscoveryMethod;

// address=[0x3ab10a4]
_PKEY_DeviceDisplay_IsEncrypted;

// address=[0x3ab10bc]
_PKEY_DeviceDisplay_IsAuthenticated;

// address=[0x3ab10d4]
_PKEY_DeviceDisplay_IsConnected;

// address=[0x3ab10ec]
_PKEY_DeviceDisplay_IsPaired;

// address=[0x3ab1104]
_PKEY_DeviceDisplay_Icon;

// address=[0x3ab111c]
_PKEY_DeviceDisplay_Version;

// address=[0x3ab1134]
_PKEY_DeviceDisplay_Last_Seen;

// address=[0x3ab114c]
_PKEY_DeviceDisplay_Last_Connected;

// address=[0x3ab1164]
_PKEY_DeviceDisplay_IsShowInDisconnectedState;

// address=[0x3ab117c]
_PKEY_DeviceDisplay_IsLocalMachine;

// address=[0x3ab1194]
_PKEY_DeviceDisplay_MetadataPath;

// address=[0x3ab11ac]
_PKEY_DeviceDisplay_IsMetadataSearchInProgress;

// address=[0x3ab11c4]
_PKEY_DeviceDisplay_MetadataChecksum;

// address=[0x3ab11dc]
_PKEY_DeviceDisplay_IsNotInterestingForDisplay;

// address=[0x3ab11f4]
_PKEY_DeviceDisplay_LaunchDeviceStageOnDeviceConnect;

// address=[0x3ab120c]
_PKEY_DeviceDisplay_LaunchDeviceStageFromExplorer;

// address=[0x3ab1224]
_PKEY_DeviceDisplay_BaselineExperienceId;

// address=[0x3ab123c]
_PKEY_DeviceDisplay_IsDeviceUniquelyIdentifiable;

// address=[0x3ab1254]
_PKEY_DeviceDisplay_AssociationArray;

// address=[0x3ab126c]
_PKEY_DeviceDisplay_DeviceDescription1;

// address=[0x3ab1284]
_PKEY_DeviceDisplay_DeviceDescription2;

// address=[0x3ab129c]
_PKEY_DeviceDisplay_IsNotWorkingProperly;

// address=[0x3ab12b4]
_PKEY_DeviceDisplay_IsSharedDevice;

// address=[0x3ab12cc]
_PKEY_DeviceDisplay_IsNetworkDevice;

// address=[0x3ab12e4]
_PKEY_DeviceDisplay_IsDefaultDevice;

// address=[0x3ab12fc]
_PKEY_DeviceDisplay_MetadataCabinet;

// address=[0x3ab1314]
_PKEY_DeviceDisplay_RequiresPairingElevation;

// address=[0x3ab132c]
_PKEY_DeviceDisplay_ExperienceId;

// address=[0x3ab1344]
_PKEY_DeviceDisplay_Category;

// address=[0x3ab135c]
_PKEY_DeviceDisplay_Category_Desc_Singular;

// address=[0x3ab1374]
_PKEY_DeviceDisplay_Category_Desc_Plural;

// address=[0x3ab138c]
_PKEY_DeviceDisplay_Category_Icon;

// address=[0x3ab13a4]
_PKEY_DeviceDisplay_CategoryGroup_Desc;

// address=[0x3ab13bc]
_PKEY_DeviceDisplay_CategoryGroup_Icon;

// address=[0x3ab13d4]
_PKEY_DeviceDisplay_PrimaryCategory;

// address=[0x3ab13ec]
_PKEY_DeviceDisplay_UnpairUninstall;

// address=[0x3ab1404]
_PKEY_DeviceDisplay_RequiresUninstallElevation;

// address=[0x3ab141c]
_PKEY_DeviceDisplay_DeviceFunctionSubRank;

// address=[0x3ab1434]
_PKEY_DeviceDisplay_AlwaysShowDeviceAsConnected;

// address=[0x3ab144c]
_PKEY_DeviceDisplay_FriendlyName;

// address=[0x3ab1464]
_PKEY_DeviceDisplay_Manufacturer;

// address=[0x3ab147c]
_PKEY_DeviceDisplay_ModelName;

// address=[0x3ab1494]
_PKEY_DeviceDisplay_ModelNumber;

// address=[0x3ab14ac]
_PKEY_DeviceDisplay_InstallInProgress;

// address=[0x3ab14c4]
_FMTID_Pairing;

// address=[0x3ab14d8]
_PKEY_Pairing_ListItemText;

// address=[0x3ab14f0]
_PKEY_Pairing_ListItemDescription;

// address=[0x3ab1508]
_PKEY_Pairing_ListItemIcon;

// address=[0x3ab1520]
_PKEY_Pairing_ListItemDefault;

// address=[0x3ab1538]
_PKEY_Pairing_IsWifiOnlyDevice;

// address=[0x3ab1550]
_PKEY_Device_BIOSVersion;

// address=[0x3ab1568]
_PKEY_Write_Time;

// address=[0x3ab1580]
_PKEY_Create_Time;

// address=[0x3ab1598]
_PKEY_Device_Interface;

// address=[0x3ab15b0]
_PKEY_ExposedIIDs;

// address=[0x3ab15c8]
_PKEY_ExposedCLSIDs;

// address=[0x3ab15e0]
_PKEY_InstanceValidatorClsid;

// address=[0x3ab15f8]
_FMTID_WSD;

// address=[0x3ab160c]
_PKEY_WSD_AddressURI;

// address=[0x3ab1624]
_PKEY_WSD_Types;

// address=[0x3ab163c]
_PKEY_WSD_Scopes;

// address=[0x3ab1654]
_PKEY_WSD_MetadataVersion;

// address=[0x3ab166c]
_PKEY_WSD_AppSeqInstanceID;

// address=[0x3ab1684]
_PKEY_WSD_AppSeqSessionID;

// address=[0x3ab169c]
_PKEY_WSD_AppSeqMessageNumber;

// address=[0x3ab16b4]
_PKEY_WSD_XAddrs;

// address=[0x3ab16cc]
_PKEY_WSD_MetadataClean;

// address=[0x3ab16e4]
_PKEY_WSD_ServiceInfo;

// address=[0x3ab16fc]
_PKEY_PUBSVCS_TYPE;

// address=[0x3ab1714]
_PKEY_PUBSVCS_SCOPE;

// address=[0x3ab172c]
_PKEY_PUBSVCS_METADATA;

// address=[0x3ab1744]
_PKEY_PUBSVCS_METADATA_VERSION;

// address=[0x3ab175c]
_PKEY_PUBSVCS_NETWORK_PROFILES_ALLOWED;

// address=[0x3ab1774]
_PKEY_PUBSVCS_NETWORK_PROFILES_DENIED;

// address=[0x3ab178c]
_PKEY_PUBSVCS_NETWORK_PROFILES_DEFAULT;

// address=[0x3ab17a4]
_FMTID_PNPX;

// address=[0x3ab17b8]
_PKEY_PNPX_GlobalIdentity;

// address=[0x3ab17d0]
_PKEY_PNPX_Types;

// address=[0x3ab17e8]
_PKEY_PNPX_Scopes;

// address=[0x3ab1800]
_PKEY_PNPX_XAddrs;

// address=[0x3ab1818]
_PKEY_PNPX_MetadataVersion;

// address=[0x3ab1830]
_PKEY_PNPX_ID;

// address=[0x3ab1848]
_PKEY_PNPX_RemoteAddress;

// address=[0x3ab1860]
_PKEY_PNPX_RootProxy;

// address=[0x3ab1878]
_PKEY_PNPX_ManufacturerUrl;

// address=[0x3ab1890]
_NETWORK_MANAGER_FIRST_IP_ADDRESS_ARRIVAL_GUID;

// address=[0x3ab18a4]
_PKEY_PNPX_ModelUrl;

// address=[0x3ab18bc]
_NETWORK_MANAGER_LAST_IP_ADDRESS_REMOVAL_GUID;

// address=[0x3ab18d0]
_PKEY_PNPX_Upc;

// address=[0x3ab18e8]
_DOMAIN_JOIN_GUID;

// address=[0x3ab18fc]
_DOMAIN_LEAVE_GUID;

// address=[0x3ab1910]
_PKEY_PNPX_PresentationUrl;

// address=[0x3ab1928]
_PKEY_PNPX_FirmwareVersion;

// address=[0x3ab1940]
_FIREWALL_PORT_OPEN_GUID;

// address=[0x3ab1954]
_PKEY_PNPX_SerialNumber;

// address=[0x3ab196c]
_FIREWALL_PORT_CLOSE_GUID;

// address=[0x3ab1980]
_MACHINE_POLICY_PRESENT_GUID;

// address=[0x3ab1994]
_PKEY_PNPX_DeviceCategory;

// address=[0x3ab19ac]
_PKEY_PNPX_SecureChannel;

// address=[0x3ab19c4]
_USER_POLICY_PRESENT_GUID;

// address=[0x3ab19d8]
_PKEY_PNPX_CompactSignature;

// address=[0x3ab19f0]
_RPC_INTERFACE_EVENT_GUID;

// address=[0x3ab1a04]
_PKEY_PNPX_DeviceCertHash;

// address=[0x3ab1a1c]
_NAMED_PIPE_EVENT_GUID;

// address=[0x3ab1a30]
_PKEY_PNPX_DeviceCategory_Desc;

// address=[0x3ab1a48]
_CUSTOM_SYSTEM_STATE_CHANGE_EVENT_GUID;

// address=[0x3ab1a5c]
_PKEY_PNPX_Category_Desc_NonPlural;

// address=[0x3ab1a74]
_PKEY_PNPX_PhysicalAddress;

// address=[0x3ab1a8c]
_PKEY_PNPX_NetworkInterfaceLuid;

// address=[0x3ab1aa4]
_PKEY_PNPX_NetworkInterfaceGuid;

// address=[0x3ab1abc]
_PKEY_PNPX_IpAddress;

// address=[0x3ab1ad4]
_PKEY_PNPX_ServiceAddress;

// address=[0x3ab1aec]
_PKEY_PNPX_ServiceId;

// address=[0x3ab1b04]
_PKEY_PNPX_ServiceTypes;

// address=[0x3ab1b1c]
_PKEY_PNPX_ServiceControlUrl;

// address=[0x3ab1b34]
_PKEY_PNPX_ServiceDescUrl;

// address=[0x3ab1b4c]
_PKEY_PNPX_ServiceEventSubUrl;

// address=[0x3ab1b64]
_PKEY_PNPX_Devnode;

// address=[0x3ab1b7c]
_PKEY_PNPX_AssociationState;

// address=[0x3ab1b94]
_PKEY_PNPX_AssociatedInstanceId;

// address=[0x3ab1bac]
_PKEY_PNPX_LastNotificationTime;

// address=[0x3ab1bc4]
_PKEY_PNPX_DomainName;

// address=[0x3ab1bdc]
_PKEY_PNPX_ShareName;

// address=[0x3ab1bf4]
_PKEY_SSDP_AltLocationInfo;

// address=[0x3ab1c0c]
_PKEY_SSDP_DevLifeTime;

// address=[0x3ab1c24]
_PKEY_SSDP_NetworkInterface;

// address=[0x3ab1c3c]
_FMTID_PNPXDynamicProperty;

// address=[0x3ab1c50]
_PKEY_PNPX_Installable;

// address=[0x3ab1c68]
_PKEY_PNPX_Associated;

// address=[0x3ab1c80]
_PKEY_PNPX_CompatibleTypes;

// address=[0x3ab1c98]
_PKEY_PNPX_InstallState;

// address=[0x3ab1cb0]
_PKEY_PNPX_Removable;

// address=[0x3ab1cc8]
_PKEY_PNPX_IPBusEnumerated;

// address=[0x3ab1ce0]
_PKEY_WNET_Scope;

// address=[0x3ab1cf8]
_PKEY_WNET_Type;

// address=[0x3ab1d10]
_PKEY_WNET_DisplayType;

// address=[0x3ab1d28]
_PKEY_WNET_Usage;

// address=[0x3ab1d40]
_PKEY_WNET_LocalName;

// address=[0x3ab1d58]
_PKEY_WNET_RemoteName;

// address=[0x3ab1d70]
_PKEY_WNET_Comment;

// address=[0x3ab1d88]
_PKEY_WNET_Provider;

// address=[0x3ab1da0]
_PKEY_WCN_Version;

// address=[0x3ab1db8]
_PKEY_WCN_RequestType;

// address=[0x3ab1dd0]
_PKEY_WCN_AuthType;

// address=[0x3ab1de8]
_PKEY_WCN_EncryptType;

// address=[0x3ab1e00]
_PKEY_WCN_ConnType;

// address=[0x3ab1e18]
_PKEY_WCN_ConfigMethods;

// address=[0x3ab1e30]
_PKEY_WCN_RfBand;

// address=[0x3ab1e48]
_PKEY_WCN_AssocState;

// address=[0x3ab1e60]
_PKEY_WCN_ConfigError;

// address=[0x3ab1e78]
_PKEY_WCN_ConfigState;

// address=[0x3ab1e90]
_PKEY_WCN_DevicePasswordId;

// address=[0x3ab1ea8]
_PKEY_WCN_OSVersion;

// address=[0x3ab1ec0]
_PKEY_WCN_VendorExtension;

// address=[0x3ab1ed8]
_PKEY_WCN_RegistrarType;

// address=[0x3ab1ef0]
_PKEY_Hardware_Devinst;

// address=[0x3ab1f08]
_PKEY_Hardware_DisplayAttribute;

// address=[0x3ab1f20]
_PKEY_Hardware_DriverDate;

// address=[0x3ab1f38]
_PKEY_Hardware_DriverProvider;

// address=[0x3ab1f50]
_PKEY_Hardware_DriverVersion;

// address=[0x3ab1f68]
_PKEY_Hardware_Function;

// address=[0x3ab1f80]
_PKEY_Hardware_Icon;

// address=[0x3ab1f98]
_PKEY_Hardware_Image;

// address=[0x3ab1fb0]
_PKEY_Hardware_Manufacturer;

// address=[0x3ab1fc8]
_PKEY_Hardware_Model;

// address=[0x3ab1fe0]
_PKEY_Hardware_Name;

// address=[0x3ab1ff8]
_PKEY_Hardware_SerialNumber;

// address=[0x3ab2010]
_PKEY_Hardware_ShellAttributes;

// address=[0x3ab2028]
_PKEY_Hardware_Status;

// address=[0x3ab2040]
_SID_PnpProvider;

// address=[0x3ab2054]
_SID_UPnPActivator;

// address=[0x3ab2068]
_SID_EnumInterface;

// address=[0x3ab207c]
_SID_PNPXPropertyStore;

// address=[0x3ab2090]
_SID_PNPXAssociation;

// address=[0x3ab20a4]
_SID_PNPXServiceCollection;

// address=[0x3ab20b8]
_SID_FDPairingHandler;

// address=[0x3ab20cc]
_SID_EnumDeviceFunction;

// address=[0x3ab20e0]
_SID_UnpairProvider;

// address=[0x3ab20f4]
_SID_DeviceDisplayStatusManager;

// address=[0x3ab2108]
_SID_FunctionDiscoveryProviderRefresh;

// address=[0x3ab211c]
_SID_UninstallDeviceFunction;

// address=[0x3ab2130]
_PPM_PERFSTATE_CHANGE_GUID;

// address=[0x3ab2144]
_PPM_PERFSTATE_DOMAIN_CHANGE_GUID;

// address=[0x3ab2158]
_PPM_IDLESTATE_CHANGE_GUID;

// address=[0x3ab216c]
_PPM_PERFSTATES_DATA_GUID;

// address=[0x3ab2180]
_PPM_IDLESTATES_DATA_GUID;

// address=[0x3ab2194]
_PPM_IDLE_ACCOUNTING_GUID;

// address=[0x3ab21a8]
_PPM_IDLE_ACCOUNTING_EX_GUID;

// address=[0x3ab21bc]
_PPM_THERMALCONSTRAINT_GUID;

// address=[0x3ab21d0]
_PPM_PERFMON_PERFSTATE_GUID;

// address=[0x3ab21e4]
_PPM_THERMAL_POLICY_CHANGE_GUID;

// address=[0x3ab21f8]
_GUID_MAX_POWER_SAVINGS;

// address=[0x3ab220c]
_GUID_MIN_POWER_SAVINGS;

// address=[0x3ab2220]
_GUID_TYPICAL_POWER_SAVINGS;

// address=[0x3ab2234]
_NO_SUBGROUP_GUID;

// address=[0x3ab2248]
_ALL_POWERSCHEMES_GUID;

// address=[0x3ab225c]
_GUID_POWERSCHEME_PERSONALITY;

// address=[0x3ab2270]
_GUID_ACTIVE_POWERSCHEME;

// address=[0x3ab2284]
_GUID_IDLE_RESILIENCY_SUBGROUP;

// address=[0x3ab2298]
_GUID_IDLE_RESILIENCY_PERIOD;

// address=[0x3ab22ac]
_GUID_IDLE_RESILIENCY_PLATFORM_STATE;

// address=[0x3ab22c0]
_GUID_DISK_COALESCING_POWERDOWN_TIMEOUT;

// address=[0x3ab22d4]
_GUID_EXECUTION_REQUIRED_REQUEST_TIMEOUT;

// address=[0x3ab22e8]
_GUID_VIDEO_SUBGROUP;

// address=[0x3ab22fc]
_GUID_VIDEO_POWERDOWN_TIMEOUT;

// address=[0x3ab2310]
_GUID_VIDEO_ANNOYANCE_TIMEOUT;

// address=[0x3ab2324]
_GUID_VIDEO_ADAPTIVE_PERCENT_INCREASE;

// address=[0x3ab2338]
_GUID_VIDEO_DIM_TIMEOUT;

// address=[0x3ab234c]
_GUID_VIDEO_ADAPTIVE_POWERDOWN;

// address=[0x3ab2360]
_GUID_MONITOR_POWER_ON;

// address=[0x3ab2374]
_GUID_DEVICE_POWER_POLICY_VIDEO_BRIGHTNESS;

// address=[0x3ab2388]
_GUID_DEVICE_POWER_POLICY_VIDEO_DIM_BRIGHTNESS;

// address=[0x3ab239c]
_GUID_VIDEO_CURRENT_MONITOR_BRIGHTNESS;

// address=[0x3ab23b0]
_GUID_VIDEO_ADAPTIVE_DISPLAY_BRIGHTNESS;

// address=[0x3ab23c4]
_GUID_CONSOLE_DISPLAY_STATE;

// address=[0x3ab23d8]
_GUID_ALLOW_DISPLAY_REQUIRED;

// address=[0x3ab23ec]
_GUID_VIDEO_CONSOLE_LOCK_TIMEOUT;

// address=[0x3ab2400]
_GUID_ADAPTIVE_POWER_BEHAVIOR_SUBGROUP;

// address=[0x3ab2414]
_GUID_NON_ADAPTIVE_INPUT_TIMEOUT;

// address=[0x3ab2428]
_GUID_DISK_SUBGROUP;

// address=[0x3ab243c]
_GUID_DISK_POWERDOWN_TIMEOUT;

// address=[0x3ab2450]
_GUID_DISK_IDLE_TIMEOUT;

// address=[0x3ab2464]
_GUID_DISK_BURST_IGNORE_THRESHOLD;

// address=[0x3ab2478]
_GUID_DISK_ADAPTIVE_POWERDOWN;

// address=[0x3ab248c]
_GUID_SLEEP_SUBGROUP;

// address=[0x3ab24a0]
_GUID_SLEEP_IDLE_THRESHOLD;

// address=[0x3ab24b4]
_GUID_STANDBY_TIMEOUT;

// address=[0x3ab24c8]
_GUID_UNATTEND_SLEEP_TIMEOUT;

// address=[0x3ab24dc]
_GUID_HIBERNATE_TIMEOUT;

// address=[0x3ab24f0]
_GUID_HIBERNATE_FASTS4_POLICY;

// address=[0x3ab2504]
_GUID_CRITICAL_POWER_TRANSITION;

// address=[0x3ab2518]
_GUID_SYSTEM_AWAYMODE;

// address=[0x3ab252c]
_GUID_ALLOW_AWAYMODE;

// address=[0x3ab2540]
_GUID_VIDEO_FULLSCREEN_PLAYBACK;

// address=[0x3ab2554]
_GUID_AUDIO_PLAYBACK;

// address=[0x3ab2568]
_GUID_ALLOW_STANDBY_STATES;

// address=[0x3ab257c]
_GUID_ALLOW_RTC_WAKE;

// address=[0x3ab2590]
_GUID_ALLOW_SYSTEM_REQUIRED;

// address=[0x3ab25a4]
_GUID_SYSTEM_BUTTON_SUBGROUP;

// address=[0x3ab25b8]
_GUID_POWERBUTTON_ACTION;

// address=[0x3ab25cc]
_GUID_SLEEPBUTTON_ACTION;

// address=[0x3ab25e0]
_GUID_USERINTERFACEBUTTON_ACTION;

// address=[0x3ab25f4]
_GUID_LIDCLOSE_ACTION;

// address=[0x3ab2608]
_GUID_LIDOPEN_POWERSTATE;

// address=[0x3ab261c]
_GUID_BATTERY_SUBGROUP;

// address=[0x3ab2630]
_GUID_BATTERY_DISCHARGE_ACTION_0;

// address=[0x3ab2644]
_GUID_BATTERY_DISCHARGE_LEVEL_0;

// address=[0x3ab2658]
_GUID_BATTERY_DISCHARGE_FLAGS_0;

// address=[0x3ab266c]
_GUID_BATTERY_DISCHARGE_ACTION_1;

// address=[0x3ab2680]
_GUID_BATTERY_DISCHARGE_LEVEL_1;

// address=[0x3ab2694]
_GUID_BATTERY_DISCHARGE_FLAGS_1;

// address=[0x3ab26a8]
_GUID_BATTERY_DISCHARGE_ACTION_2;

// address=[0x3ab26bc]
_GUID_BATTERY_DISCHARGE_LEVEL_2;

// address=[0x3ab26d0]
_GUID_BATTERY_DISCHARGE_FLAGS_2;

// address=[0x3ab26e4]
_GUID_BATTERY_DISCHARGE_ACTION_3;

// address=[0x3ab26f8]
_GUID_BATTERY_DISCHARGE_LEVEL_3;

// address=[0x3ab270c]
_GUID_BATTERY_DISCHARGE_FLAGS_3;

// address=[0x3ab2720]
_GUID_CS_BATTERY_SAVER_THRESHOLD;

// address=[0x3ab2734]
_GUID_CS_BATTERY_SAVER_ACTION;

// address=[0x3ab2748]
_GUID_CS_BATTERY_SAVER_TIMEOUT;

// address=[0x3ab275c]
_GUID_PROCESSOR_SETTINGS_SUBGROUP;

// address=[0x3ab2770]
_GUID_PROCESSOR_THROTTLE_POLICY;

// address=[0x3ab2784]
_GUID_PROCESSOR_THROTTLE_MAXIMUM;

// address=[0x3ab2798]
_GUID_PROCESSOR_THROTTLE_MINIMUM;

// address=[0x3ab27ac]
_GUID_PROCESSOR_ALLOW_THROTTLING;

// address=[0x3ab27c0]
_GUID_PROCESSOR_IDLESTATE_POLICY;

// address=[0x3ab27d4]
_GUID_PROCESSOR_PERFSTATE_POLICY;

// address=[0x3ab27e8]
_GUID_PROCESSOR_PERF_INCREASE_THRESHOLD;

// address=[0x3ab27fc]
_GUID_PROCESSOR_PERF_DECREASE_THRESHOLD;

// address=[0x3ab2810]
_GUID_PROCESSOR_PERF_INCREASE_POLICY;

// address=[0x3ab2824]
_GUID_PROCESSOR_PERF_DECREASE_POLICY;

// address=[0x3ab2838]
_GUID_PROCESSOR_PERF_INCREASE_TIME;

// address=[0x3ab284c]
_GUID_PROCESSOR_PERF_DECREASE_TIME;

// address=[0x3ab2860]
_GUID_PROCESSOR_PERF_TIME_CHECK;

// address=[0x3ab2874]
_GUID_PROCESSOR_PERF_BOOST_POLICY;

// address=[0x3ab2888]
_GUID_PROCESSOR_PERF_BOOST_MODE;

// address=[0x3ab289c]
_GUID_PROCESSOR_IDLE_ALLOW_SCALING;

// address=[0x3ab28b0]
_GUID_PROCESSOR_IDLE_DISABLE;

// address=[0x3ab28c4]
_GUID_PROCESSOR_IDLE_STATE_MAXIMUM;

// address=[0x3ab28d8]
_GUID_PROCESSOR_IDLE_TIME_CHECK;

// address=[0x3ab28ec]
_GUID_PROCESSOR_IDLE_DEMOTE_THRESHOLD;

// address=[0x3ab2900]
_GUID_PROCESSOR_IDLE_PROMOTE_THRESHOLD;

// address=[0x3ab2914]
_GUID_PROCESSOR_CORE_PARKING_INCREASE_THRESHOLD;

// address=[0x3ab2928]
_GUID_PROCESSOR_CORE_PARKING_DECREASE_THRESHOLD;

// address=[0x3ab293c]
_GUID_PROCESSOR_CORE_PARKING_INCREASE_POLICY;

// address=[0x3ab2950]
_GUID_PROCESSOR_CORE_PARKING_DECREASE_POLICY;

// address=[0x3ab2964]
_GUID_PROCESSOR_CORE_PARKING_MAX_CORES;

// address=[0x3ab2978]
_GUID_PROCESSOR_CORE_PARKING_MIN_CORES;

// address=[0x3ab298c]
_GUID_PROCESSOR_CORE_PARKING_INCREASE_TIME;

// address=[0x3ab29a0]
_GUID_PROCESSOR_CORE_PARKING_DECREASE_TIME;

// address=[0x3ab29b4]
_GUID_PROCESSOR_CORE_PARKING_AFFINITY_HISTORY_DECREASE_FACTOR;

// address=[0x3ab29c8]
_GUID_PROCESSOR_CORE_PARKING_AFFINITY_HISTORY_THRESHOLD;

// address=[0x3ab29dc]
_GUID_PROCESSOR_CORE_PARKING_AFFINITY_WEIGHTING;

// address=[0x3ab29f0]
_GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_HISTORY_DECREASE_FACTOR;

// address=[0x3ab2a04]
_GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_HISTORY_THRESHOLD;

// address=[0x3ab2a18]
_GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_WEIGHTING;

// address=[0x3ab2a2c]
_GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_THRESHOLD;

// address=[0x3ab2a40]
_GUID_PROCESSOR_PARKING_CORE_OVERRIDE;

// address=[0x3ab2a54]
_GUID_PROCESSOR_PARKING_PERF_STATE;

// address=[0x3ab2a68]
_GUID_PROCESSOR_PARKING_CONCURRENCY_THRESHOLD;

// address=[0x3ab2a7c]
_GUID_PROCESSOR_PARKING_HEADROOM_THRESHOLD;

// address=[0x3ab2a90]
_GUID_PROCESSOR_PERF_HISTORY;

// address=[0x3ab2aa4]
_GUID_PROCESSOR_PERF_INCREASE_HISTORY;

// address=[0x3ab2ab8]
_GUID_PROCESSOR_PERF_DECREASE_HISTORY;

// address=[0x3ab2acc]
_GUID_PROCESSOR_PERF_CORE_PARKING_HISTORY;

// address=[0x3ab2ae0]
_GUID_PROCESSOR_PERF_LATENCY_HINT;

// address=[0x3ab2af4]
_GUID_PROCESSOR_PERF_LATENCY_HINT_PERF;

// address=[0x3ab2b08]
_GUID_PROCESSOR_DISTRIBUTE_UTILITY;

// address=[0x3ab2b1c]
_GUID_SYSTEM_COOLING_POLICY;

// address=[0x3ab2b30]
_GUID_LOCK_CONSOLE_ON_WAKE;

// address=[0x3ab2b44]
_GUID_DEVICE_IDLE_POLICY;

// address=[0x3ab2b58]
_GUID_ACDC_POWER_SOURCE;

// address=[0x3ab2b6c]
_GUID_LIDSWITCH_STATE_CHANGE;

// address=[0x3ab2b80]
_GUID_BATTERY_PERCENTAGE_REMAINING;

// address=[0x3ab2b94]
_GUID_GLOBAL_USER_PRESENCE;

// address=[0x3ab2ba8]
_GUID_SESSION_DISPLAY_STATUS;

// address=[0x3ab2bbc]
_GUID_SESSION_USER_PRESENCE;

// address=[0x3ab2bd0]
_GUID_IDLE_BACKGROUND_TASK;

// address=[0x3ab2be4]
_GUID_BACKGROUND_TASK_NOTIFICATION;

// address=[0x3ab2bf8]
_GUID_APPLAUNCH_BUTTON;

// address=[0x3ab2c0c]
_GUID_PCIEXPRESS_SETTINGS_SUBGROUP;

// address=[0x3ab2c20]
_GUID_PCIEXPRESS_ASPM_POLICY;

// address=[0x3ab2c34]
_GUID_ENABLE_SWITCH_FORCED_SHUTDOWN;

// address=[0x3ab2c48]
_GUID_INTSTEER_SUBGROUP;

// address=[0x3ab2c5c]
_GUID_INTSTEER_MODE;

// address=[0x3ab2c70]
_GUID_INTSTEER_LOAD_PER_PROC_TRIGGER;

// address=[0x3ab2c84]
_GUID_INTSTEER_TIME_UNPARK_TRIGGER;

// address=[0x3ab5230]
const std::basic_ifstream<char,struct std::char_traits<char> >::`vbtable';

// address=[0x3ab9cec]
char const * const * const BBSupportLib::g_pBBSupportInfoStrings;

// address=[0x3abafb8]
__real@40f86a0000000000;

// address=[0x3abafc8]
__real@c0f86a0000000000;

// address=[0x3ac897c]
__real@3d533333;

// address=[0x3ac8980]
__real@3df8f8f9;

// address=[0x3ac8984]
__real@3e7cfcfd;

// address=[0x3ac8988]
__real@3ec00000;

// address=[0x3ac898c]
__real@3fd33333;

// address=[0x3ac8990]
__real@49c00000;

// address=[0x3accd44]
__real@3d70f0f1;

// address=[0x3acd744]
__real@3b000000;

// address=[0x3acd748]
__real@3e400000;

// address=[0x3acd74c]
__real@41b80000;

// address=[0x3acd750]
__real@42400000;

// address=[0x3acd754]
__real@42d20000;

// address=[0x3acd758]
__real@43800000;

// address=[0x3acdb08]
__real@3a800000;

// address=[0x3ad2c50]
__real@3da3d70a;

// address=[0x3ad2c54]
__real@43160000;

// address=[0x3ad3308]
__real@40efffe000000000;

// address=[0x3ad3318]
__real@41b2b9b0a15be612;

// address=[0x3ad3930]
__real@3ff8000000000000;

// address=[0x3ad3f2c]
int const * const FieldForRings;

// address=[0x3ad45c8]
__real@4@00000000000000000000;

// address=[0x3ad45cc]
__real@3ee66666;

// address=[0x3ad45e8]
__real@4@3feea7c5ac471b478800;

// address=[0x3ad45f0]
__real@8@00000000000000000000;

// address=[0x3ad4600]
__real@8@3ffaccccccccccccd000;

// address=[0x3ad4610]
__real@8@3fff8000000000000000;

// address=[0x3ad4620]
__real@8@3ffe8000000000000000;

// address=[0x3ad4630]
__real@8@400fc350000000000000;

// address=[0x3ad4640]
__real@8@4006ff00000000000000;

// address=[0x3ad4650]
__real@8@3ff78080808080808000;

// address=[0x3ad4660]
__real@8@400effff000000000000;

// address=[0x3ad4670]
__real@8@3fef8000800080008000;

// address=[0x3ad4680]
__real@8@3ff78000000000000000;

// address=[0x3ad4690]
__real@8@3feb8637bd05af6c6800;

// address=[0x3ad4bd0]
__real@8@3feea7c5ac471b478800;

// address=[0x3ad4be0]
_inflate_copyright;

// address=[0x3ad8730]
__int64 const std::_BADOFF;

// address=[0x3ad93a8]
public: static unsigned int const std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class std::allocator<unsigned short> >::npos;

// address=[0x3ad9c58]
__real@4733426172c74d82;

// address=[0x3adda08]
_MF_TOPONODE_LOCKED;

// address=[0x3adda1c]
_MFSampleExtension_CleanPoint;

// address=[0x3adda30]
_MF_TOPONODE_WORKQUEUE_ID;

// address=[0x3adda44]
_MFSampleExtension_QPCBasedStreamTime;

// address=[0x3adda58]
_MFSampleExtension_Discontinuity;

// address=[0x3adda6c]
_CLSID_CreateMediaExtensionObject;

// address=[0x3adda80]
_MFSampleExtension_Token;

// address=[0x3adda94]
_MF_DEVSOURCE_ATTRIBUTE_USE_STREAM_TIME;

// address=[0x3addaa8]
_MF_TOPONODE_WORKQUEUE_MMCSS_CLASS;

// address=[0x3addabc]
_MF_TOPONODE_DECRYPTOR;

// address=[0x3addad0]
_MFSampleExtension_DecodeTimestamp;

// address=[0x3addae4]
_MF_TRANSFORM_IS_CAMERA_PLUGIN;

// address=[0x3addaf8]
_MFSampleExtension_VideoEncodeQP;

// address=[0x3addb0c]
_MF_TOPONODE_DISCARDABLE;

// address=[0x3addb20]
_MF_XVP_PLAYBACK_MODE;

// address=[0x3addb34]
_MF_VIDEO_DECODER_DROPPED_FRAME_COUNT;

// address=[0x3addb48]
_MFSampleExtension_VideoEncodePictureType;

// address=[0x3addb5c]
_MF_TOPONODE_ERROR_MAJORTYPE;

// address=[0x3addb70]
_MF_TOPONODE_ERROR_SUBTYPE;

// address=[0x3addb84]
_MF_SESSION_PREROLL_FROM_RATE0;

// address=[0x3addb98]
_MFSampleExtension_FrameCorruption;

// address=[0x3addbac]
_MF_TOPONODE_WORKQUEUE_MMCSS_TASKID;

// address=[0x3addbc0]
_MFSampleExtension_DescrambleData;

// address=[0x3addbd4]
_MF_TOPONODE_WORKQUEUE_MMCSS_PRIORITY;

// address=[0x3addbe8]
_MFSampleExtension_SampleKeyID;

// address=[0x3addbfc]
_MFSampleExtension_GenKeyFunc;

// address=[0x3addc10]
_MF_TOPONODE_WORKQUEUE_ITEM_PRIORITY;

// address=[0x3addc24]
_MFSampleExtension_GenKeyCtx;

// address=[0x3addc38]
_MF_TOPONODE_MARKIN_HERE;

// address=[0x3addc4c]
_MFSampleExtension_PacketCrossOffsets;

// address=[0x3addc60]
_MF_TOPONODE_MARKOUT_HERE;

// address=[0x3addc74]
_MFWMIGUID_EVR_PRESENT_EVENT;

// address=[0x3addc88]
_MF_TOPONODE_DECODER;

// address=[0x3addc9c]
_MFSampleExtension_Encryption_SampleID;

// address=[0x3addcb0]
_MF_TOPONODE_MEDIASTART;

// address=[0x3addcc4]
_MFSampleExtension_Encryption_KeyID;

// address=[0x3addcd8]
_MFSampleExtension_Content_KeyID;

// address=[0x3addcec]
_MF_TOPONODE_MEDIASTOP;

// address=[0x3addd00]
_MF_TOPONODE_SOURCE;

// address=[0x3addd14]
_MFSampleExtension_Encryption_SubSampleMappingSplit;

// address=[0x3addd28]
_MFSampleExtension_Interlaced;

// address=[0x3addd3c]
_MF_TOPONODE_PRESENTATION_DESCRIPTOR;

// address=[0x3addd50]
_MF_TOPONODE_STREAM_DESCRIPTOR;

// address=[0x3addd64]
_MFSampleExtension_BottomFieldFirst;

// address=[0x3addd78]
_MF_TOPONODE_SEQUENCE_ELEMENTID;

// address=[0x3addd8c]
_MFSampleExtension_RepeatFirstField;

// address=[0x3addda0]
_MFSampleExtension_SingleField;

// address=[0x3adddb4]
_MF_TOPONODE_TRANSFORM_OBJECTID;

// address=[0x3adddc8]
_MFSampleExtension_DerivedFromTopField;

// address=[0x3addddc]
_MF_TOPONODE_STREAMID;

// address=[0x3adddf0]
_MF_TOPONODE_NOSHUTDOWN_ON_REMOVE;

// address=[0x3adde04]
_MFSampleExtension_MeanAbsoluteDifference;

// address=[0x3adde18]
_MF_TOPONODE_RATELESS;

// address=[0x3adde2c]
_MFSampleExtension_LongTermReferenceFrameInfo;

// address=[0x3adde40]
_MF_TOPONODE_DISABLE_PREROLL;

// address=[0x3adde54]
_MFSampleExtension_ROIRectangle;

// address=[0x3adde68]
_MFMediaType_Interleaved;

// address=[0x3adde7c]
_MF_TOPONODE_PRIMARYOUTPUT;

// address=[0x3adde90]
_MFWMIGUID_EVR_MONITOR_ESTIMATE_EVENT;

// address=[0x3addea4]
_MFMediaType_Line21;

// address=[0x3addeb8]
_MFMediaType_SMX;

// address=[0x3addecc]
_MFFormatNone;

// address=[0x3addee0]
_MFFormatVideoInfo;

// address=[0x3addef4]
_MFFormatVideoInfo2;

// address=[0x3addf08]
_MFFormatWaveFormatEx;

// address=[0x3addf1c]
_MFFormatMPEGVideo;

// address=[0x3addf30]
_MFFormatDvInfo;

// address=[0x3addf44]
_MFPROTECTION_WMDRMV1;

// address=[0x3addf58]
_MF_PMP_SERVICE;

// address=[0x3addf6c]
_MFPROTECTION_WMDRMV7;

// address=[0x3addf80]
_MFPROTECTION_WMDRMV7ForDevice;

// address=[0x3addf94]
_MFSampleExtension_PhotoThumbnail;

// address=[0x3addfa8]
_MFSampleExtension_PhotoThumbnailMediaType;

// address=[0x3addfbc]
_MFSampleExtension_CaptureMetadata;

// address=[0x3addfd0]
_MFWMIGUID_EVR_SLEEP_EVENT;

// address=[0x3addfe4]
_MF_CAPTURE_METADATA_PHOTO_FRAME_FLASH;

// address=[0x3addff8]
_MFT_CATEGORY_VIDEO_DECODER;

// address=[0x3ade00c]
_MF_TEST_HOOK_SERVICE;

// address=[0x3ade020]
_MF_PD_CONTAINER_FORMAT;

// address=[0x3ade034]
_MFT_CATEGORY_VIDEO_ENCODER;

// address=[0x3ade048]
_MF_CONTAINER_MPEG1;

// address=[0x3ade05c]
_MFT_CATEGORY_VIDEO_EFFECT;

// address=[0x3ade070]
_MFT_CATEGORY_MULTIPLEXER;

// address=[0x3ade084]
_MFWMIGUID_PROPERTYHANDLER_EVENT;

// address=[0x3ade098]
_MF_CONTAINER_MPEG2_PS;

// address=[0x3ade0ac]
_MFT_CATEGORY_DEMULTIPLEXER;

// address=[0x3ade0c0]
_MF_CONTAINER_MPEG2_TS;

// address=[0x3ade0d4]
_MF_CONTAINER_MPEG2_TS_TTS;

// address=[0x3ade0e8]
_MFT_CATEGORY_AUDIO_DECODER;

// address=[0x3ade0fc]
_MFT_CATEGORY_AUDIO_ENCODER;

// address=[0x3ade110]
_MF_CONTAINER_MPEG2_TS_TTS_ZERO;

// address=[0x3ade124]
_MF_CONTAINER_MPEG2_TS_TTS_ARIB;

// address=[0x3ade138]
_MFT_CATEGORY_AUDIO_EFFECT;

// address=[0x3ade14c]
_MFSourceReader_SampleAttribute_MediaType;

// address=[0x3ade160]
_MFT_CATEGORY_VIDEO_PROCESSOR;

// address=[0x3ade174]
_MFT_CATEGORY_OTHER;

// address=[0x3ade188]
_MF_BYTESTREAM_DOWNLOADRATE_SERVICE;

// address=[0x3ade19c]
_CLSID_MPEG2MuxMFT;

// address=[0x3ade1b0]
_MFWMIGUID_TRANSCODE_API_EVENT;

// address=[0x3ade1c4]
_MF_SAMI_SERVICE;

// address=[0x3ade1d8]
_MF_PD_SAMI_STYLELIST;

// address=[0x3ade1ec]
_MF_SD_SAMI_LANGUAGE;

// address=[0x3ade200]
_CLSID_DShowSourceResolver;

// address=[0x3ade214]
_CLSID_WTVByteStreamPlugin;

// address=[0x3ade228]
_MFWMIGUID_FIELDOFUSE_EVENT;

// address=[0x3ade23c]
_MF_TIME_FORMAT_SEGMENT_OFFSET;

// address=[0x3ade250]
_MF_DirectShow_ExcludeGuid;

// address=[0x3ade264]
_MF_DirectShow_MinFileVersion;

// address=[0x3ade278]
_MF_DirectShow_MaxFileVersion;

// address=[0x3ade28c]
_MF_DirectShow_GuidService;

// address=[0x3ade2a0]
_MF_DirectShow_ServiceProvider;

// address=[0x3ade2b4]
_CLSID_MFMPEG2Demultiplexer;

// address=[0x3ade2c8]
_CLSID_MFSourceFilter;

// address=[0x3ade2dc]
_CLSID_PsiParserFilter;

// address=[0x3ade2f0]
_MFWMIGUID_CAPTURE_SOURCE_EVENT;

// address=[0x3ade304]
_CLSID_DemuxRender;

// address=[0x3ade318]
_CLSID_MFDShowTransformWrapper;

// address=[0x3ade32c]
_MF_TRANSCODE_CONTAINERTYPE;

// address=[0x3ade340]
_MFTranscodeContainerType_ASF;

// address=[0x3ade354]
_MFTranscodeContainerType_MPEG4;

// address=[0x3ade368]
_MFTranscodeContainerType_MP3;

// address=[0x3ade37c]
_MFTranscodeContainerType_3GP;

// address=[0x3ade390]
_MFTranscodeContainerType_AC3;

// address=[0x3ade3a4]
_MF_TOPONODE_INTERNAL_WORKQUEUE_ID;

// address=[0x3ade3b8]
_MFTranscodeContainerType_ADTS;

// address=[0x3ade3cc]
_MFTranscodeContainerType_MPEG2;

// address=[0x3ade3e0]
_MF_TOPONODE_INTERNAL_MT_WORKQUEUE_ID;

// address=[0x3ade3f4]
_MF_TOPONODE_INTERNAL_DISCARDABLE_STREAMS;

// address=[0x3ade408]
_MFTranscodeContainerType_WAVE;

// address=[0x3ade41c]
_MFTranscodeContainerType_AVI;

// address=[0x3ade430]
_CLSID_MFVideoMixer9;

// address=[0x3ade444]
_CLSID_MFVideoPresenter9;

// address=[0x3ade458]
_MFTranscodeContainerType_FMPEG4;

// address=[0x3ade46c]
_MF_TRANSCODE_SKIP_METADATA_TRANSFER;

// address=[0x3ade480]
_CLSID_MFVideoMixerPassThru;

// address=[0x3ade494]
_MF_TRANSCODE_TOPOLOGYMODE;

// address=[0x3ade4a8]
_CLSID_MFVideoPresenterBitBlt;

// address=[0x3ade4bc]
_CLSID_ICMDecompressorDMO;

// address=[0x3ade4d0]
_CLSID_FileByteStream;

// address=[0x3ade4e4]
_MF_SOURCE_PRESENTATION_PROVIDER_SERVICE;

// address=[0x3ade4f8]
_CLSID_SequencerSourceRemoteStream;

// address=[0x3ade50c]
_CLSID_WmpRtspSinkActivate;

// address=[0x3ade520]
_CLSID_WinMDERtspSinkActivate;

// address=[0x3ade534]
_MF_TRANSCODE_ADJUST_PROFILE;

// address=[0x3ade548]
_CLSID_McRtspSinkActivate;

// address=[0x3ade55c]
_CLSID_WmpLPCMSinkActivate;

// address=[0x3ade570]
_CLSID_WinMDELPCMSinkActivate;

// address=[0x3ade584]
_CLSID_McLPCMSinkActivate;

// address=[0x3ade598]
_CLSID_WmpMPEG2SinkActivate;

// address=[0x3ade5ac]
_MF_TRANSCODE_ENCODINGPROFILE;

// address=[0x3ade5c0]
_MFT_SUPPORT_DYNAMIC_FORMAT_CHANGE;

// address=[0x3ade5d4]
_CLSID_WinMDEMPEG2SinkActivate;

// address=[0x3ade5e8]
_MFVideoFormat_Base;

// address=[0x3ade5fc]
_MF_TRANSCODE_QUALITYVSSPEED;

// address=[0x3ade610]
_MFVideoFormat_RGB32;

// address=[0x3ade624]
_MF_TRANSCODE_DONOT_INSERT_ENCODER;

// address=[0x3ade638]
_CLSID_McMPEG2SinkActivate;

// address=[0x3ade64c]
_CLSID_WmpNetChannelActivate;

// address=[0x3ade660]
_MFVideoFormat_ARGB32;

// address=[0x3ade674]
_CLSID_WinMDENetChannelActivate;

// address=[0x3ade688]
_MFVideoFormat_RGB24;

// address=[0x3ade69c]
_MFVideoFormat_RGB555;

// address=[0x3ade6b0]
_CLSID_McNetChannelActivate;

// address=[0x3ade6c4]
_CLSID_MFMediaSourceActivate;

// address=[0x3ade6d8]
_MFVideoFormat_RGB565;

// address=[0x3ade6ec]
_MFVideoFormat_RGB8;

// address=[0x3ade700]
_MF_VIDEO_PROCESSOR_ALGORITHM;

// address=[0x3ade714]
_CLSID_MFASFPropertyHandler;

// address=[0x3ade728]
_MF_XVP_DISABLE_FRC;

// address=[0x3ade73c]
_MFVideoFormat_AI44;

// address=[0x3ade750]
_CLSID_MFMP4PropertyHandler;

// address=[0x3ade764]
_CLSID_MFAVIPropertyHandler;

// address=[0x3ade778]
_CLSID_MFMP3PropertyHandler;

// address=[0x3ade78c]
_CLSID_MFM2TSPropertyHandler;

// address=[0x3ade7a0]
_CLSID_MFWAVPropertyHandler;

// address=[0x3ade7b4]
_CLSID_MFADTSPropertyHandler;

// address=[0x3ade7c8]
_MFVideoFormat_AYUV;

// address=[0x3ade7dc]
_CLSID_MFAC3PropertyHandler;

// address=[0x3ade7f0]
_CLSID_MFMP3SinkClassFactory;

// address=[0x3ade804]
_CLSID_MF3GPSinkClassFactory;

// address=[0x3ade818]
_CLSID_MFMPEG4SinkClassFactory;

// address=[0x3ade82c]
_CLSID_MFFMPEG4SinkClassFactory;

// address=[0x3ade840]
_MFVideoFormat_YUY2;

// address=[0x3ade854]
_CLSID_MFAC3SinkClassFactory;

// address=[0x3ade868]
_CLSID_MFAVISinkClassFactory;

// address=[0x3ade87c]
_MF_PD_PMPHOST_CONTEXT;

// address=[0x3ade890]
_MF_PD_APP_CONTEXT;

// address=[0x3ade8a4]
_CLSID_MFADTSSinkClassFactory;

// address=[0x3ade8b8]
_CLSID_MFTMuxSinkClassFactory;

// address=[0x3ade8cc]
_MF_PD_DURATION;

// address=[0x3ade8e0]
_MF_CLOCK_RATE_MATCH_SERVICE;

// address=[0x3ade8f4]
_MFVideoFormat_YVYU;

// address=[0x3ade908]
_CLSID_MFWAVESinkClassFactory;

// address=[0x3ade91c]
_MF_PD_TOTAL_FILE_SIZE;

// address=[0x3ade930]
_MF_PD_AUDIO_ENCODING_BITRATE;

// address=[0x3ade944]
_CLSID_AsfByteStreamPlugin;

// address=[0x3ade958]
_MF_PD_VIDEO_ENCODING_BITRATE;

// address=[0x3ade96c]
_CLSID_LPCMByteStreamPlugin;

// address=[0x3ade980]
_MF_PD_MIME_TYPE;

// address=[0x3ade994]
_CLSID_MP3ByteStreamPlugin;

// address=[0x3ade9a8]
_MF_PD_LAST_MODIFIED_TIME;

// address=[0x3ade9bc]
_CLSID_MPEG4ByteStreamPlugin;

// address=[0x3ade9d0]
_CLSID_MPEG4ParserClassFactory;

// address=[0x3ade9e4]
_MFVideoFormat_YVU9;

// address=[0x3ade9f8]
_MF_PD_PLAYBACK_ELEMENT_ID;

// address=[0x3adea0c]
_CLSID_AVIByteStreamPlugin;

// address=[0x3adea20]
_MF_PD_PREFERRED_LANGUAGE;

// address=[0x3adea34]
_CLSID_SAMIByteStreamPlugin;

// address=[0x3adea48]
_MF_PD_PLAYBACK_BOUNDARY_TIME;

// address=[0x3adea5c]
_MF_TOPONODE_ATTRIBUTE_EDITOR_SERVICE;

// address=[0x3adea70]
_CLSID_NSCByteStreamPlugin;

// address=[0x3adea84]
_MF_PD_AUDIO_ISVARIABLEBITRATE;

// address=[0x3adea98]
_CLSID_WAVByteStreamPlugin;

// address=[0x3adeaac]
_MFVideoFormat_UYVY;

// address=[0x3adeac0]
_CLSID_ADTSByteStreamPlugin;

// address=[0x3adead4]
_CLSID_AC3ByteStreamPlugin;

// address=[0x3adeae8]
_CLSID_FileSchemePlugin;

// address=[0x3adeafc]
_CLSID_SoundEventSchemePlugin;

// address=[0x3adeb10]
_CLSID_SecureHttpSchemePlugin;

// address=[0x3adeb24]
_CLSID_DrmNetNDSchemePlugin;

// address=[0x3adeb38]
_MFVideoFormat_NV11;

// address=[0x3adeb4c]
_CLSID_MsWwaSchemePlugin;

// address=[0x3adeb60]
_CLSID_MsAppDataSchemePlugin;

// address=[0x3adeb74]
_MF_CLOCK_SERVICE;

// address=[0x3adeb88]
_CLSID_AudioCaptureMFT;

// address=[0x3adeb9c]
_CLSID_DevProxyMFT;

// address=[0x3adebb0]
_CLSID_VideoProcessorMFT;

// address=[0x3adebc4]
_MFVideoFormat_NV12;

// address=[0x3adebd8]
_MFFormatMPEGStreams;

// address=[0x3adebec]
_MFASFBWSharingType_Exclusive;

// address=[0x3adec00]
_MFASFBWSharingType_Partial;

// address=[0x3adec14]
_PKEY_MFASF_STREAM_FLAGS;

// address=[0x3adec2c]
_MFVideoFormat_YV12;

// address=[0x3adec40]
_PKEY_MFASF_STREAM_LEAKYBUCKET1;

// address=[0x3adec58]
_PKEY_MFASF_STREAM_LEAKYBUCKET2;

// address=[0x3adec70]
_PKEY_MFASF_STREAM_PAYLOADEXTENSIONS;

// address=[0x3adec88]
_PKEY_MFASF_PROFILE_ASFOBJECTS;

// address=[0x3adeca0]
_PKEY_MFASF_PROFILE_MINPACKETSIZE;

// address=[0x3adecb8]
_PKEY_MFASF_PROFILE_MAXPACKETSIZE;

// address=[0x3adecd0]
_MFVideoFormat_I420;

// address=[0x3adece4]
_MFPKEY_BITMAPINFOHEADER_ExtraData;

// address=[0x3adecfc]
_ME_MEDIA_SOURCE_STARTED;

// address=[0x3aded10]
_ME_MEDIA_SOURCE_STOPPED;

// address=[0x3aded24]
_ME_MEDIA_SOURCE_PAUSED;

// address=[0x3aded38]
_ME_MEDIA_SOURCE_SEEKED;

// address=[0x3aded4c]
_MFVideoFormat_IYUV;

// address=[0x3aded60]
_ME_MEDIA_SOURCE_RATE_CHANGED;

// address=[0x3aded74]
_ME_NEW_PRESENTATION;

// address=[0x3aded88]
_ME_PRESENTATION_NEW_STREAM;

// address=[0x3aded9c]
_ME_END_OF_PRESENTATION;

// address=[0x3adedb0]
_MFVideoFormat_Y210;

// address=[0x3adedc4]
_ME_PRESENTATION_NEW_METADATA;

// address=[0x3adedd8]
_ME_MEDIA_SAMPLE;

// address=[0x3adedec]
_ME_FORMAT_CHANGED;

// address=[0x3adee00]
_ME_END_OF_STREAM;

// address=[0x3adee14]
_ME_STREAM_STARTED;

// address=[0x3adee28]
_MFVideoFormat_Y216;

// address=[0x3adee3c]
_ME_STREAM_STOPPED;

// address=[0x3adee50]
_MF_SD_LANGUAGE;

// address=[0x3adee64]
_ME_STREAM_PAUSED;

// address=[0x3adee78]
_ME_STREAM_SEEKED;

// address=[0x3adee8c]
_MF_SD_PROTECTED;

// address=[0x3adeea0]
_MF_SD_STREAM_NAME;

// address=[0x3adeeb4]
_MR_VOLUME_CONTROL_SERVICE;

// address=[0x3adeec8]
_MF_SD_MUTUALLY_EXCLUSIVE;

// address=[0x3adeedc]
_MF_SCREEN_CAPTURE_CONFIG_SERVICE;

// address=[0x3adeef0]
_MFVideoFormat_Y410;

// address=[0x3adef04]
_MF_SCRIPTTRANSFER_SERVICE;

// address=[0x3adef18]
_MF_FILETRANSFER_SERVICE;

// address=[0x3adef2c]
_MF_TIMESTAMP_SOURCE_SERVICE;

// address=[0x3adef40]
_IID_IMFNetSessionHandler;

// address=[0x3adef54]
_IID_IMFRequestHandler;

// address=[0x3adef68]
_SDPBUILDER_CONTAINERFLAGS;

// address=[0x3adef7c]
_MFVideoFormat_Y416;

// address=[0x3adef90]
_MSBBUILDER_SERVER_ADDRESS;

// address=[0x3adefa4]
_MSBBUILDER_MULTICAST_ADDRESS;

// address=[0x3adefb8]
_MSBBUILDER_MULTICAST_PORT;

// address=[0x3adefcc]
_MSBBUILDER_TTL;

// address=[0x3adefe0]
_MFVideoFormat_Y41P;

// address=[0x3adeff4]
_MSBBUILDER_LOGGING_URL;

// address=[0x3adf008]
_MSBBUILDER_UNICAST_ROLLOVER_URL;

// address=[0x3adf01c]
_MSBBUILDER_ALLOW_SPLITTING;

// address=[0x3adf030]
_MSBBUILDER_ALLOW_CACHING;

// address=[0x3adf044]
_MSBBUILDER_CACHE_EXPIRATION;

// address=[0x3adf058]
_MFVideoFormat_Y41T;

// address=[0x3adf06c]
_MFNETSESSION_MDE_PROFILE;

// address=[0x3adf080]
_MF_LOCAL_MFT_REGISTRATION_SERVICE;

// address=[0x3adf094]
_MFNETSESSION_SELECTED_PROTOCOL;

// address=[0x3adf0a8]
_PKEY_MFNETFEEDBACK_STREAM_ID;

// address=[0x3adf0c0]
_PKEY_MFNETFEEDBACK_BUFFERING;

// address=[0x3adf0d8]
_PKEY_MFNETFEEDBACK_BUFFERSIZE_MS;

// address=[0x3adf0f0]
_PKEY_MFNETFEEDBACK_RENDERRATE;

// address=[0x3adf108]
_MFVideoFormat_Y42T;

// address=[0x3adf11c]
_PKEY_MFNETFEEDBACK_TOTALPACKETSLOST;

// address=[0x3adf134]
_PKEY_MFNETFEEDBACK_TOTALPACKETSRECEIVED;

// address=[0x3adf14c]
_PKEY_MFNETFEEDBACK_NEWPACKETSLOST;

// address=[0x3adf164]
_PKEY_MFNETFEEDBACK_NEWPACKETSRECEIVED;

// address=[0x3adf17c]
_PKEY_MFSOURCE_FRAME_COUNT;

// address=[0x3adf194]
_MFVideoFormat_P210;

// address=[0x3adf1a8]
_PKEY_MFSOURCE_FRAME_RATE;

// address=[0x3adf1c0]
_PKEY_MFNETMSB_FORMATID;

// address=[0x3adf1d8]
_GUID_SEQUENCER_NODE_OFFSET;

// address=[0x3adf1ec]
_MF_TIME_FORMAT_NATIVE_TIMECODE;

// address=[0x3adf200]
_MFVideoFormat_P216;

// address=[0x3adf214]
_MF_SEQUENCER_SOURCE_SERVICE;

// address=[0x3adf228]
_MF_EVENT_EXTENDED_TYPE_SEQUENCER_NODE_CHANGE;

// address=[0x3adf23c]
_MFWMIGUID;

// address=[0x3adf250]
_MF_EVENT_EXTENDED_TYPE_SEQUENCER_EFFECT_INSERT;

// address=[0x3adf264]
_MFWMIGUID_OBJECT_EVENT;

// address=[0x3adf278]
_MF_EVENT_EXTENDED_TYPE_SEQUENCER_EFFECT_REMOVE;

// address=[0x3adf28c]
_MF_EVENT_EXTENDED_TYPE_SEQUENCER_EFFECT_CHANGE;

// address=[0x3adf2a0]
_MFVideoFormat_P010;

// address=[0x3adf2b4]
_MFOPUS_NAME;

// address=[0x3adf2c8]
_MFOPUS_URI;

// address=[0x3adf2dc]
_MFOPUS_TYPE;

// address=[0x3adf2f0]
_MFOPUS_ID;

// address=[0x3adf304]
_MFOPUS_CONTAINERFORMAT;

// address=[0x3adf318]
_MFVideoFormat_P016;

// address=[0x3adf32c]
_MFOPUS_DATASTREAM;

// address=[0x3adf340]
_MFOPUS_URITYPE;

// address=[0x3adf354]
_MFOPUS_PRESENTATION_LANGUAGE;

// address=[0x3adf368]
_MFOPUS_DURATION;

// address=[0x3adf37c]
_MF_ENGINE_PREVIOUS_STATE;

// address=[0x3adf390]
_MF_ENGINE_METHOD_ID;

// address=[0x3adf3a4]
_MFVideoFormat_v210;

// address=[0x3adf3b8]
_MF_ENGINE_SUSPENSION_REASON;

// address=[0x3adf3cc]
_MFTRANSFORM_MULTI_CHANNEL_AUDIO;

// address=[0x3adf3e0]
_MFTRANSFORM_ACM_WRAPPER;

// address=[0x3adf3f4]
_IID_IAcmWrapperConfigure;

// address=[0x3adf408]
_MFVideoFormat_v216;

// address=[0x3adf41c]
_MFMCLIP_BESTVIDEOSAMPLE;

// address=[0x3adf430]
_MFMPEGSampleExtension_MPEG_90KHZ_CLOCK_OFFSET;

// address=[0x3adf444]
_MFFORMATSPECIFIER_MPEGFormatHeader;

// address=[0x3adf458]
_MF_REMOTE_PD_CONTEXT;

// address=[0x3adf46c]
_MF_PMPHOST_PD_CONTEXT;

// address=[0x3adf480]
_MFVideoFormat_v410;

// address=[0x3adf494]
_MFVideoFormat_MP43;

// address=[0x3adf4a8]
_MFOUTPUT_COMPRESSEDDIGITALVIDEO;

// address=[0x3adf4bc]
_MFOUTPUT_UNCOMPRESSEDDIGITALVIDEO;

// address=[0x3adf4d0]
_MFOUTPUT_ANALOGVIDEO;

// address=[0x3adf4e4]
_MFVideoFormat_MP4S;

// address=[0x3adf4f8]
_MFOUTPUT_COMPRESSEDDIGITALAUDIO;

// address=[0x3adf50c]
_MFOUTPUT_UNCOMPRESSEDDIGITALAUDIO;

// address=[0x3adf520]
_MFOUTPUT_ANALOGAUDIO;

// address=[0x3adf534]
_MFVideoFormat_M4S2;

// address=[0x3adf548]
_MFVideoFormat_MP4V;

// address=[0x3adf55c]
_MFWMIGUID_AUDIORENDERER_STARVATION_EVENT;

// address=[0x3adf570]
_MFVideoFormat_WMV1;

// address=[0x3adf584]
_MFVideoFormat_WMV2;

// address=[0x3adf598]
_MFWMIGUID_VIDEO_FRAME_GLITCH_EVENT;

// address=[0x3adf5ac]
_MFVideoFormat_WMV3;

// address=[0x3adf5c0]
_MFVideoFormat_WVC1;

// address=[0x3adf5d4]
_MFWMIGUID_DATA_DROP_EVENT;

// address=[0x3adf5e8]
_MFVideoFormat_MSS1;

// address=[0x3adf5fc]
_MFVideoFormat_MSS2;

// address=[0x3adf610]
_MF_ACTIVATE_CUSTOM_VIDEO_MIXER_CLSID;

// address=[0x3adf624]
_MF_ACTIVATE_CUSTOM_VIDEO_MIXER_ACTIVATE;

// address=[0x3adf638]
_MF_ACTIVATE_CUSTOM_VIDEO_MIXER_FLAGS;

// address=[0x3adf64c]
_MFVideoFormat_MPG1;

// address=[0x3adf660]
_MF_ACTIVATE_CUSTOM_VIDEO_PRESENTER_CLSID;

// address=[0x3adf674]
_MF_WRAPPED_BUFFER_SERVICE;

// address=[0x3adf688]
_MF_WRAPPED_SAMPLE_SERVICE;

// address=[0x3adf69c]
_MF_ACTIVATE_CUSTOM_VIDEO_PRESENTER_ACTIVATE;

// address=[0x3adf6b0]
_MF_ACTIVATE_CUSTOM_VIDEO_PRESENTER_FLAGS;

// address=[0x3adf6c4]
_MF_WRAPPED_OBJECT;

// address=[0x3adf6d8]
_CLSID_HttpSchemePlugin;

// address=[0x3adf6ec]
_CLSID_UrlmonSchemePlugin;

// address=[0x3adf700]
_CLSID_NetSchemePlugin;

// address=[0x3adf714]
_MFVideoFormat_DVSL;

// address=[0x3adf728]
_MF_ACTIVATE_MFT_LOCKED;

// address=[0x3adf73c]
_MF_ACTIVATE_VIDEO_WINDOW;

// address=[0x3adf750]
_MFWMIGUID_CLOCK_GETTIME_EVENT;

// address=[0x3adf764]
_MFVideoFormat_DVSD;

// address=[0x3adf778]
_MFPKEY_CLSID;

// address=[0x3adf790]
_MFVideoFormat_DVHD;

// address=[0x3adf7a4]
_MFPKEY_CATEGORY;

// address=[0x3adf7bc]
_MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE;

// address=[0x3adf7d0]
_MFPKEY_EXATTRIBUTE_SUPPORTED;

// address=[0x3adf7e8]
_MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_HW_SOURCE;

// address=[0x3adf7fc]
_MF_DEVSOURCE_ATTRIBUTE_FRIENDLY_NAME;

// address=[0x3adf810]
_MFPKEY_MULTICHANNEL_CHANNEL_MASK;

// address=[0x3adf828]
_MF_DEVSOURCE_ATTRIBUTE_MEDIA_TYPE;

// address=[0x3adf83c]
_MF_SA_D3D_AWARE;

// address=[0x3adf850]
_MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_CATEGORY;

// address=[0x3adf864]
_MFWMIGUID_PREDICTED_VIDEO_SAMPLETIME_EVENT;

// address=[0x3adf878]
_MF_SA_REQUIRED_SAMPLE_COUNT;

// address=[0x3adf88c]
_MFVideoFormat_DV25;

// address=[0x3adf8a0]
_MF_SA_REQUIRED_SAMPLE_COUNT_PROGRESSIVE;

// address=[0x3adf8b4]
_MFWMIGUID_STREAM_EVENT;

// address=[0x3adf8c8]
_MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_SYMBOLIC_LINK;

// address=[0x3adf8dc]
_MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_AUDCAP_SYMBOLIC_LINK;

// address=[0x3adf8f0]
_MF_SA_MINIMUM_OUTPUT_SAMPLE_COUNT;

// address=[0x3adf904]
_EventTraceGuid;

// address=[0x3adf918]
_MF_SA_MINIMUM_OUTPUT_SAMPLE_COUNT_PROGRESSIVE;

// address=[0x3adf92c]
_MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_MAX_BUFFERS;

// address=[0x3adf940]
_SystemTraceControlGuid;

// address=[0x3adf954]
_MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_AUDCAP_ENDPOINT_ID;

// address=[0x3adf968]
_MFT_SUPPORT_3DVIDEO;

// address=[0x3adf97c]
_MFVideoFormat_DV50;

// address=[0x3adf990]
_MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_AUDCAP_ROLE;

// address=[0x3adf9a4]
_EventTraceConfigGuid;

// address=[0x3adf9b8]
_DefaultTraceSecurityGuid;

// address=[0x3adf9cc]
_MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_AUDCAP_GUID;

// address=[0x3adf9e0]
_MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID;

// address=[0x3adf9f4]
_MF_DEVICESTREAM_IMAGE_STREAM;

// address=[0x3adfa08]
_MF_ENABLE_3DVIDEO_OUTPUT;

// address=[0x3adfa1c]
_MF_DEVICESTREAM_INDEPENDENT_IMAGE_STREAM;

// address=[0x3adfa30]
_MF_DEVICESTREAM_STREAM_ID;

// address=[0x3adfa44]
_MFVideoFormat_DVH1;

// address=[0x3adfa58]
_MF_SA_D3D11_BINDFLAGS;

// address=[0x3adfa6c]
_MF_SA_D3D11_USAGE;

// address=[0x3adfa80]
_MFWMIGUID_MEDIATYPE_CHANGE_EVENT;

// address=[0x3adfa94]
_MF_DEVICESTREAM_STREAM_CATEGORY;

// address=[0x3adfaa8]
_MF_SA_D3D11_AWARE;

// address=[0x3adfabc]
_MF_DEVICESTREAM_TRANSFORM_STREAM_ID;

// address=[0x3adfad0]
_MF_DEVICESTREAM_EXTENSION_PLUGIN_CLSID;

// address=[0x3adfae4]
_MF_SA_D3D11_SHARED;

// address=[0x3adfaf8]
_MF_DEVICESTREAM_EXTENSION_PLUGIN_CONNECTION_POINT;

// address=[0x3adfb0c]
_MF_SA_D3D11_SHARED_WITHOUT_MUTEX;

// address=[0x3adfb20]
_MF_AUDIO_RENDERER_ATTRIBUTE_FLAGS;

// address=[0x3adfb34]
_MF_DEVICESTREAM_TAKEPHOTO_TRIGGER;

// address=[0x3adfb48]
_MF_SA_BUFFERS_PER_SAMPLE;

// address=[0x3adfb5c]
_MFVideoFormat_DVC;

// address=[0x3adfb70]
_MFT_DECODER_EXPOSE_OUTPUT_TYPES_IN_NATIVE_ORDER;

// address=[0x3adfb84]
_MF_AUDIO_RENDERER_ATTRIBUTE_SESSION_ID;

// address=[0x3adfb98]
_MF_DEVICESTREAM_MAX_FRAME_BUFFERS;

// address=[0x3adfbac]
_MFT_REMUX_MARK_I_PICTURE_AS_CLEAN_POINT;

// address=[0x3adfbc0]
_MFSampleExtension_DeviceTimestamp;

// address=[0x3adfbd4]
_MF_AUDIO_RENDERER_ATTRIBUTE_ENDPOINT_ID;

// address=[0x3adfbe8]
_MF_AUDIO_RENDERER_ATTRIBUTE_ENDPOINT_ROLE;

// address=[0x3adfbfc]
_MFT_DECODER_FINAL_VIDEO_RESOLUTION_HINT;

// address=[0x3adfc10]
_MF_AUDIO_RENDERER_ATTRIBUTE_STREAM_CATEGORY;

// address=[0x3adfc24]
_MFT_ENCODER_SUPPORTS_CONFIG_EVENT;

// address=[0x3adfc38]
_MFT_ENUM_HARDWARE_VENDOR_ID_Attribute;

// address=[0x3adfc4c]
_MFVideoFormat_H264;

// address=[0x3adfc60]
_MF_TRANSFORM_ASYNC;

// address=[0x3adfc74]
_MF_TRANSFORM_ASYNC_UNLOCK;

// address=[0x3adfc88]
_MF_TRANSFORM_FLAGS_Attribute;

// address=[0x3adfc9c]
_MF_TRANSFORM_CATEGORY_Attribute;

// address=[0x3adfcb0]
_MFVideoFormat_MJPG;

// address=[0x3adfcc4]
_MFT_TRANSFORM_CLSID_Attribute;

// address=[0x3adfcd8]
_MFWMIGUID_BUFFER_EVENT;

// address=[0x3adfcec]
_MFT_INPUT_TYPES_Attributes;

// address=[0x3adfd00]
_MFT_OUTPUT_TYPES_Attributes;

// address=[0x3adfd14]
_MFT_ENUM_HARDWARE_URL_Attribute;

// address=[0x3adfd28]
_MFT_FRIENDLY_NAME_Attribute;

// address=[0x3adfd3c]
_MFT_CONNECTED_STREAM_ATTRIBUTE;

// address=[0x3adfd50]
_MFVideoFormat_420O;

// address=[0x3adfd64]
_MFT_CONNECTED_TO_HW_STREAM;

// address=[0x3adfd78]
_MF_PRES_TARGET_PRES_DESC;

// address=[0x3adfd8c]
_MF_PRES_TARGET_ASF_PROFILE;

// address=[0x3adfda0]
_MFT_PREFERRED_OUTPUTTYPE_Attribute;

// address=[0x3adfdb4]
_MF_PRES_TARGET_ASF_HEADER;

// address=[0x3adfdc8]
_MFT_PROCESS_LOCAL_Attribute;

// address=[0x3adfddc]
_MFT_PREFERRED_ENCODER_PROFILE;

// address=[0x3adfdf0]
_MF_PRES_TARGET_SDP_RTSP_V9;

// address=[0x3adfe04]
_MFT_HW_TIMESTAMP_WITH_QPC_Attribute;

// address=[0x3adfe18]
_MFVideoFormat_HEVC;

// address=[0x3adfe2c]
_MF_PRES_TARGET_SDP_RTSP_V10;

// address=[0x3adfe40]
_MF_PRES_TARGET_SDP_MCAST;

// address=[0x3adfe54]
_MFT_FIELDOFUSE_UNLOCK_Attribute;

// address=[0x3adfe68]
_MFT_CODEC_MERIT_Attribute;

// address=[0x3adfe7c]
_MF_PRES_TARGET_SDP_HTTP_V10;

// address=[0x3adfe90]
_MFT_ENUM_TRANSCODE_ONLY_ATTRIBUTE;

// address=[0x3adfea4]
_MFNETSINK_STATISTICS;

// address=[0x3adfeb8]
_MF_MEDIA_EXTENSION_ACTIVATABLE_CLASS_ID;

// address=[0x3adfecc]
_MFNETSINK_STATISTICS_SERVICE;

// address=[0x3adfee0]
_MFNETSINK_CONFIG_SERVICE;

// address=[0x3adfef4]
_CLSID_MFMediaExtensionActivate;

// address=[0x3adff08]
_MFVideoFormat_HEVC_ES;

// address=[0x3adff1c]
_MFNETVROOT_BASIC_STATISTICS;

// address=[0x3adff30]
_MFNETVROOT_STATISTICS_SERVICE;

// address=[0x3adff44]
_MFWMIGUID_PROCESS_EVENT;

// address=[0x3adff58]
_MFNETVROOT_EVENTROUTER;

// address=[0x3adff6c]
_MFNETVROOT_DEVICEREGISTRATION;

// address=[0x3adff80]
_MFVideoFormat_H263;

// address=[0x3adff94]
_MFNETVROOT_TRANSCODEMANAGER;

// address=[0x3adffa8]
_MFNETVROOT_CONNECTIONMANAGER;

// address=[0x3adffbc]
_MFNETVROOT_NETSESSIONFACTORYPTR;

// address=[0x3adffd0]
_MFNETVROOT_SERVERPROPS;

// address=[0x3adffe4]
_MF_PD_NET_BROADCAST;

// address=[0x3adfff8]
_MF_PD_NET_SEEKABLE;

// address=[0x3ae000c]
_MFVideoFormat_H264_ES;

// address=[0x3ae0020]
_MF_PD_NET_STRIDABLE;

// address=[0x3ae0034]
_MF_PD_NET_RECORDABLE;

// address=[0x3ae0048]
_MFVideoFormat_MPEG2;

// address=[0x3ae005c]
_MF_PD_NET_PLAYLIST;

// address=[0x3ae0070]
_MFAudioFormat_Base;

// address=[0x3ae0084]
_MF_WVC1_PROG_SINGLE_SLICE_CONTENT;

// address=[0x3ae0098]
_MF_PROGRESSIVE_CODING_CONTENT;

// address=[0x3ae00ac]
_MF_PD_NET_SKIP_FORWARD;

// address=[0x3ae00c0]
_MFAudioFormat_PCM;

// address=[0x3ae00d4]
_MF_NALU_LENGTH_SET;

// address=[0x3ae00e8]
_MFAudioFormat_Float;

// address=[0x3ae00fc]
_MF_PD_NET_SKIP_BACKWARD;

// address=[0x3ae0110]
_MFAudioFormat_DTS;

// address=[0x3ae0124]
_MF_NALU_LENGTH_INFORMATION;

// address=[0x3ae0138]
_MF_PD_NET_MUXSTREAM;

// address=[0x3ae014c]
_MF_USER_DATA_PAYLOAD;

// address=[0x3ae0160]
_MFAudioFormat_Dolby_AC3_SPDIF;

// address=[0x3ae0174]
_MF_PD_NET_PAUSABLE;

// address=[0x3ae0188]
_MF_PD_NET_STRIDING_RATES;

// address=[0x3ae019c]
_MF_MPEG4SINK_SPSPPS_PASSTHROUGH;

// address=[0x3ae01b0]
_MFAudioFormat_DRM;

// address=[0x3ae01c4]
_MFAudioFormat_WMAudioV8;

// address=[0x3ae01d8]
_MF_MPEG4SINK_MOOV_BEFORE_MDAT;

// address=[0x3ae01ec]
_MF_PD_NET_SLOWEST_SPEED;

// address=[0x3ae0200]
_MF_PD_NET_FASTEST_SPEED;

// address=[0x3ae0214]
_MFAudioFormat_WMAudioV9;

// address=[0x3ae0228]
_MF_PD_NET_DLNA_PROFILE;

// address=[0x3ae023c]
_MFNETSOURCE_SSLCERTIFICATE_MANAGER;

// address=[0x3ae0250]
_MFWMIGUID_UNUSUAL_STREAMING_EVENT;

// address=[0x3ae0264]
_MFAudioFormat_WMAudio_Lossless;

// address=[0x3ae0278]
_MFAudioFormat_WMASPDIF;

// address=[0x3ae028c]
_MF_PD_NET_ENCRYPTED;

// address=[0x3ae02a0]
_MFAudioFormat_MSP1;

// address=[0x3ae02b4]
_MF_SD_NET_BITRATE;

// address=[0x3ae02c8]
_MF_SD_NET_PEAK_BITRATE;

// address=[0x3ae02dc]
_MFAudioFormat_MP3;

// address=[0x3ae02f0]
_MF_SD_NET_BUFFERSIZE;

// address=[0x3ae0304]
_MFAudioFormat_MPEG;

// address=[0x3ae0318]
_MFAudioFormat_AAC;

// address=[0x3ae032c]
_MF_SD_NET_PEAK_BUFFERSIZE;

// address=[0x3ae0340]
_MF_SD_MUTUALLY_EXCLUSIVE_BY_BITRATE;

// address=[0x3ae0354]
_MFAudioFormat_ADTS;

// address=[0x3ae0368]
_MF_TRANSCODE_SOURCE_PROPSTORE;

// address=[0x3ae037c]
_MFAudioFormat_AMR_NB;

// address=[0x3ae0390]
_MFAudioFormat_AMR_WB;

// address=[0x3ae03a4]
_MFAudioFormat_AMR_WP;

// address=[0x3ae03b8]
_MFAudioFormat_Dolby_AC3;

// address=[0x3ae03cc]
_MFAudioFormat_Dolby_DDPlus;

// address=[0x3ae03e0]
_MFWMIGUID_DISKIO_REQUEST_EVENT;

// address=[0x3ae03f4]
_MFMPEG4Format_Base;

// address=[0x3ae0408]
_MF_MT_MAJOR_TYPE;

// address=[0x3ae041c]
_MF_MT_SUBTYPE;

// address=[0x3ae0430]
_MFNETCONNECTION_REMOTEIPADDRESS;

// address=[0x3ae0444]
_MF_MT_ALL_SAMPLES_INDEPENDENT;

// address=[0x3ae0458]
_MF_MT_FIXED_SIZE_SAMPLES;

// address=[0x3ae046c]
_MFNETCONNECTION_SSLCLIENTCERTINFO;

// address=[0x3ae0480]
_MFNETCONNECTION_LISTENER;

// address=[0x3ae0494]
_MF_MT_COMPRESSED;

// address=[0x3ae04a8]
_MFNETSOURCE_RESOURCE_FILTER;

// address=[0x3ae04bc]
_MFNETCONNECTION_SHARED_LOCK;

// address=[0x3ae04d0]
_CLSID_MPEG2ByteStreamPlugin;

// address=[0x3ae04e4]
_MF_MT_SAMPLE_SIZE;

// address=[0x3ae04f8]
_MFNETCONNECTION_SHAREDFEEDBACKPORT;

// address=[0x3ae050c]
_MF_MEDIASOURCE_SERVICE;

// address=[0x3ae0520]
_MF_MT_WRAPPED_TYPE;

// address=[0x3ae0534]
_MF_MT_VIDEO_3D;

// address=[0x3ae0548]
_MFNETCONNECTION_SHAREDDATAPORT;

// address=[0x3ae055c]
_MFNETCONNECTION_FEEDBACKSOCKET;

// address=[0x3ae0570]
_MFNETCONNECTION_SESSIONID;

// address=[0x3ae0584]
_MFNETCONNECTION_NETCHANNEL;

// address=[0x3ae0598]
_MFWMIGUID_DISKIO_COMPLETE_EVENT;

// address=[0x3ae05ac]
_MFNETCONNECTION_LAST_ERROR;

// address=[0x3ae05c0]
_MFNETCONNECTION_FRIENDLY_NAME;

// address=[0x3ae05d4]
_MF_MT_VIDEO_3D_FORMAT;

// address=[0x3ae05e8]
_MF_MT_VIDEO_3D_NUM_VIEWS;

// address=[0x3ae05fc]
_MF_MT_VIDEO_3D_LEFT_IS_BASE;

// address=[0x3ae0610]
_MF_MT_VIDEO_3D_FIRST_IS_LEFT;

// address=[0x3ae0624]
_MFSampleExtension_3DVideo;

// address=[0x3ae0638]
_MF_SESSION_TOPOLOADER;

// address=[0x3ae064c]
_MFWMIGUID_FILE_OPEN_EVENT;

// address=[0x3ae0660]
_MF_SESSION_GLOBAL_TIME;

// address=[0x3ae0674]
_MFSampleExtension_3DVideo_SampleFormat;

// address=[0x3ae0688]
_MF_SESSION_QUALITY_MANAGER;

// address=[0x3ae069c]
_MF_SESSION_CONTENT_PROTECTION_MANAGER;

// address=[0x3ae06b0]
_MF_SESSION_SERVER_CONTEXT;

// address=[0x3ae06c4]
_MF_SESSION_REMOTE_SOURCE_MODE;

// address=[0x3ae06d8]
_MF_SESSION_APPROX_EVENT_OCCURRENCE_TIME;

// address=[0x3ae06ec]
_MF_PMP_SERVER_CONTEXT;

// address=[0x3ae0700]
_MF_MT_VIDEO_ROTATION;

// address=[0x3ae0714]
_MF_MT_AUDIO_NUM_CHANNELS;

// address=[0x3ae0728]
_MF_MT_AUDIO_SAMPLES_PER_SECOND;

// address=[0x3ae073c]
_MF_MT_AUDIO_FLOAT_SAMPLES_PER_SECOND;

// address=[0x3ae0750]
_MFWMIGUID_RENDER_REND_EVENT;

// address=[0x3ae0764]
_MF_MT_AUDIO_AVG_BYTES_PER_SECOND;

// address=[0x3ae0778]
_MF_MT_AUDIO_BLOCK_ALIGNMENT;

// address=[0x3ae078c]
_MF_MT_AUDIO_BITS_PER_SAMPLE;

// address=[0x3ae07a0]
_MF_MT_AUDIO_VALID_BITS_PER_SAMPLE;

// address=[0x3ae07b4]
_MF_MT_AUDIO_SAMPLES_PER_BLOCK;

// address=[0x3ae07c8]
_MF_MT_AUDIO_CHANNEL_MASK;

// address=[0x3ae07dc]
_GUID_COUNTER_SERVING_BASIC;

// address=[0x3ae07f0]
_GUID_COUNTER_NETWORKING_BASIC;

// address=[0x3ae0804]
_GUID_COUNTER_SINK;

// address=[0x3ae0818]
_GUID_COUNTER_ASFMEDIASINK;

// address=[0x3ae082c]
_MFWMIGUID_RENDER_SAMPLE_EVENT;

// address=[0x3ae0840]
_GUID_COUNTER_ASFMEDIASOURCE;

// address=[0x3ae0854]
_GUID_COUNTER_CDMEDIASOURCE;

// address=[0x3ae0868]
_MF_MT_AUDIO_FOLDDOWN_MATRIX;

// address=[0x3ae087c]
_MF_MT_AUDIO_WMADRC_PEAKREF;

// address=[0x3ae0890]
_MF_MT_AUDIO_WMADRC_PEAKTARGET;

// address=[0x3ae08a4]
_MF_MT_AUDIO_WMADRC_AVGREF;

// address=[0x3ae08b8]
_MF_MT_AUDIO_WMADRC_AVGTARGET;

// address=[0x3ae08cc]
_MF_MT_AUDIO_PREFER_WAVEFORMATEX;

// address=[0x3ae08e0]
_NETSERVER_TCP_PACKETPAIR_PACKET;

// address=[0x3ae08f4]
_MF_MT_AAC_PAYLOAD_TYPE;

// address=[0x3ae0908]
_MF_MT_AAC_AUDIO_PROFILE_LEVEL_INDICATION;

// address=[0x3ae091c]
_NETSERVER_UDP_PACKETPAIR_PACKET;

// address=[0x3ae0930]
_MF_MT_FRAME_SIZE;

// address=[0x3ae0944]
_MF_MT_FRAME_RATE;

// address=[0x3ae0958]
_MFWMIGUID_DXVA_EVENT;

// address=[0x3ae096c]
_MF_MT_PIXEL_ASPECT_RATIO;

// address=[0x3ae0980]
_MFRECORDQUEUE_STATISTICS;

// address=[0x3ae0994]
_MF_MT_DRM_FLAGS;

// address=[0x3ae09a8]
_MFRECORDQUEUE_STATISTICS_SERVICE;

// address=[0x3ae09bc]
_MF_MT_TIMESTAMP_CAN_BE_DTS;

// address=[0x3ae09d0]
_MFSampleExtension_MediatypeIndex;

// address=[0x3ae09e4]
_MFSampleExtension_TIMECODE;

// address=[0x3ae09f8]
_MFDEVICE_BASIC_STATISTICS;

// address=[0x3ae0a0c]
_MFSampleExtension_EOS;

// address=[0x3ae0a20]
_MFDEVICE_BASIC_STATISTICS_SERVICE;

// address=[0x3ae0a34]
_MFSampleExtension_StreamTick;

// address=[0x3ae0a48]
_NETSTREAMSINK_STATUS_DATAQUEUEDINMS;

// address=[0x3ae0a5c]
_MF_MT_PAD_CONTROL_FLAGS;

// address=[0x3ae0a70]
_NETSTREAMSINK_PACKETIZER;

// address=[0x3ae0a84]
_NETSTREAMSINK_NETCHANNEL;

// address=[0x3ae0a98]
_NETSTREAMSINK_SSRC;

// address=[0x3ae0aac]
_MFWMIGUID_CODEC_DXVA_EVENT;

// address=[0x3ae0ac0]
_NETSTREAMSINK_CHANNELID;

// address=[0x3ae0ad4]
_NETSTREAMSINK_NACKSSRC;

// address=[0x3ae0ae8]
_NETSTREAMSINK_MAXMTU;

// address=[0x3ae0afc]
_NETSTREAMSINK_PAYLOADFORMATTYPEINFO;

// address=[0x3ae0b10]
_MFNET_SAVEJOB_SERVICE;

// address=[0x3ae0b24]
_MF_MT_SOURCE_CONTENT_HINT;

// address=[0x3ae0b38]
_MFAUDIORENDERSINK_STATISTICS;

// address=[0x3ae0b4c]
_MFENABLETYPE_WMDRMV1_LicenseAcquisition;

// address=[0x3ae0b60]
_NETSTREAMSINK_NACKHANDLER;

// address=[0x3ae0b74]
_MFAUDIORENDERSINK_STATISTICS_SERVICE;

// address=[0x3ae0b88]
_MFENABLETYPE_WMDRMV7_LicenseAcquisition;

// address=[0x3ae0b9c]
_MFENABLETYPE_WMDRMV7_Individualization;

// address=[0x3ae0bb0]
_NETSTREAMSINK_BFRHANDLER;

// address=[0x3ae0bc4]
_MFENABLETYPE_MF_UpdateRevocationInformation;

// address=[0x3ae0bd8]
_NETSTREAMSINK_RECEIVERREPORTHANDLER;

// address=[0x3ae0bec]
_NETSTREAMSINK_RECEIVERDATAPORT;

// address=[0x3ae0c00]
_MFENABLETYPE_MF_UpdateUntrustedComponent;

// address=[0x3ae0c14]
_NETSTREAMSINK_RECEIVERFEEDBACKPORT;

// address=[0x3ae0c28]
_MFENABLETYPE_MF_RebootRequired;

// address=[0x3ae0c3c]
_NETSTREAMSINK_FECSTREAM;

// address=[0x3ae0c50]
_MF_MT_VIDEO_CHROMA_SITING;

// address=[0x3ae0c64]
_MF_MT_INTERLACE_MODE;

// address=[0x3ae0c78]
_NETSTREAMSINK_FECPACKETIZER;

// address=[0x3ae0c8c]
_NETSTREAMSINK_NACKPACKETIZER;

// address=[0x3ae0ca0]
_MF_MT_TRANSFER_FUNCTION;

// address=[0x3ae0cb4]
_MF_MT_VIDEO_PRIMARIES;

// address=[0x3ae0cc8]
_NETSTREAMSINK_USINGBFR;

// address=[0x3ae0cdc]
_MFWMIGUID_AUDIORENDERER_BUFFERFULLNESS_EVENT;

// address=[0x3ae0cf0]
_MF_MT_CUSTOM_VIDEO_PRIMARIES;

// address=[0x3ae0d04]
_NETSTREAMSINK_DEJITTERBUFFERSIZE;

// address=[0x3ae0d18]
_NETSTREAMSINK_CODEDDATABUFFERSIZE;

// address=[0x3ae0d2c]
_NETSTREAMSINK_TARGETBUFFERDURATION;

// address=[0x3ae0d40]
_NETSTREAMSINK_BURSTPAIRENABLED;

// address=[0x3ae0d54]
_NETSTREAMSINK_DATACHANNELSTUB;

// address=[0x3ae0d68]
_NETSTREAMSINK_FEEDBACKCHANNELSTUB;

// address=[0x3ae0d7c]
_NETMEDIASINK_SAMPLESWITHRTPTIMESTAMPS;

// address=[0x3ae0d90]
_MFNETLISTENER_FEEDBACKSPLITTER;

// address=[0x3ae0da4]
_MFNETLISTENER_RECEIVERREPORTSPLITTER;

// address=[0x3ae0db8]
_MFNETLISTENER_PMPSERVERCONTEXT;

// address=[0x3ae0dcc]
_MFWMIGUID_STATE_CHANGE_EVENT;

// address=[0x3ae0de0]
_MFNETLISTENER_UNPROTECTED_PMPSERVERCONTEXT;

// address=[0x3ae0df4]
_MFNETVROOT_ENABLENACK;

// address=[0x3ae0e08]
_MFNETVROOT_ENABLEFEC;

// address=[0x3ae0e1c]
_MFNETVROOT_ENABLEBFR;

// address=[0x3ae0e30]
_MFNETVROOT_STATISTICS;

// address=[0x3ae0e44]
_MFNETVROOT_TYPEOFSERVICE;

// address=[0x3ae0e58]
_MFNETVROOT_PORT;

// address=[0x3ae0e6c]
_MFNETVROOT_IDLESESSIONTIMEOUT;

// address=[0x3ae0e80]
_MF_MT_YUV_MATRIX;

// address=[0x3ae0e94]
_MF_MT_VIDEO_LIGHTING;

// address=[0x3ae0ea8]
_MFNETVROOT_CONTENTDESCRIPTONLIMIT;

// address=[0x3ae0ebc]
_MFNETVROOT_SSLCONFIGURATION;

// address=[0x3ae0ed0]
_MF_MT_VIDEO_NOMINAL_RANGE;

// address=[0x3ae0ee4]
_MF_MT_GEOMETRIC_APERTURE;

// address=[0x3ae0ef8]
_MFNETVROOT_ENABLEEDGETRAVERSAL;

// address=[0x3ae0f0c]
_MFWMIGUID_TRANSFORM_CREATION_EVENT;

// address=[0x3ae0f20]
_MFNETVROOT_HGMEDIAQUERY;

// address=[0x3ae0f34]
_MF_MT_MINIMUM_DISPLAY_APERTURE;

// address=[0x3ae0f48]
_MF_MT_PAN_SCAN_APERTURE;

// address=[0x3ae0f5c]
_MFNETVROOT_CLIENTTOKEN;

// address=[0x3ae0f70]
_MF_MT_PAN_SCAN_ENABLED;

// address=[0x3ae0f84]
_MFNETVROOT_SESSION_FACTORY;

// address=[0x3ae0f98]
_MF_MT_AVG_BITRATE;

// address=[0x3ae0fac]
_MFNETVROOT_IS_IMAGE_FACTORY;

// address=[0x3ae0fc0]
_MF_MT_AVG_BIT_ERROR_RATE;

// address=[0x3ae0fd4]
_PKEY_MFNETPUSH_URL;

// address=[0x3ae0fec]
_MF_MT_MAX_KEYFRAME_SPACING;

// address=[0x3ae1000]
_PKEY_MFNETPUSH_TEMPLATEURL;

// address=[0x3ae1018]
_MF_MT_USER_DATA;

// address=[0x3ae102c]
_PKEY_MFNETPUSH_AUTODESTROY;

// address=[0x3ae1044]
_PKEY_MFNETPUSH_CREDENTIALMANAGER;

// address=[0x3ae105c]
_MF_MT_DEFAULT_STRIDE;

// address=[0x3ae1070]
_MF_MT_PALETTE;

// address=[0x3ae1084]
_PKEY_RTPMCAST_ANN;

// address=[0x3ae109c]
_PKEY_RTPMCAST_ACC;

// address=[0x3ae10b4]
_MF_MT_AM_FORMAT_TYPE;

// address=[0x3ae10c8]
_MF_MT_VIDEO_PROFILE;

// address=[0x3ae10dc]
_PKEY_RTPMCAST_HV;

// address=[0x3ae10f4]
_MF_MT_VIDEO_LEVEL;

// address=[0x3ae1108]
_PKEY_RTPMCAST_HA;

// address=[0x3ae1120]
_MF_MT_MPEG_START_TIME_CODE;

// address=[0x3ae1134]
_PKEY_RTPMCAST_APP;

// address=[0x3ae114c]
_PKEY_RTPMCAST_AL;

// address=[0x3ae1164]
_MF_MT_MPEG2_PROFILE;

// address=[0x3ae1178]
_PKEY_RTPMCAST_AB;

// address=[0x3ae1190]
_MF_MT_MPEG2_LEVEL;

// address=[0x3ae11a4]
_MF_MT_MPEG2_FLAGS;

// address=[0x3ae11b8]
_PKEY_RTPMCAST_VB;

// address=[0x3ae11d0]
_PKEY_RTPMCAST_LAYOUT;

// address=[0x3ae11e8]
_MF_MT_MPEG_SEQUENCE_HEADER;

// address=[0x3ae11fc]
_MF_MT_MPEG2_STANDARD;

// address=[0x3ae1210]
_PKEY_RTPMCAST_UNICAST_URL;

// address=[0x3ae1228]
_MF_MT_MPEG2_TIMECODE;

// address=[0x3ae123c]
_PKEY_RTPMCAST_LOG_URL;

// address=[0x3ae1254]
_MF_MT_MPEG2_CONTENT_PACKET;

// address=[0x3ae1268]
_PKEY_RTPMCAST_DOMAIN;

// address=[0x3ae1280]
_PKEY_RTPMCAST_SIGN_DATA;

// address=[0x3ae1298]
_MF_MT_H264_MAX_CODEC_CONFIG_DELAY;

// address=[0x3ae12ac]
_PKEY_RTPMCAST_KEY_BLOB;

// address=[0x3ae12c4]
_MF_MT_H264_SUPPORTED_SLICE_MODES;

// address=[0x3ae12d8]
_MF_MT_H264_SUPPORTED_SYNC_FRAME_TYPES;

// address=[0x3ae12ec]
_PKEY_RTPMCAST_MULTICAST_URL;

// address=[0x3ae1304]
_MF_MT_H264_RESOLUTION_SCALING;

// address=[0x3ae1318]
_PKEY_RTPMCAST_CHANNEL_ENABLED;

// address=[0x3ae1330]
_MF_MT_H264_SIMULCAST_SUPPORT;

// address=[0x3ae1344]
_PKEY_RTPMCAST_CHANNEL_LANGUAGE;

// address=[0x3ae135c]
_PKEY_RTPMCAST_CHANNEL_BITRATE_KBPS;

// address=[0x3ae1374]
_MF_MT_H264_SUPPORTED_RATE_CONTROL_MODES;

// address=[0x3ae1388]
_MFWMIGUID_MEDIAENGINE_EVENT;

// address=[0x3ae139c]
_MF_MT_H264_MAX_MB_PER_SEC;

// address=[0x3ae13b0]
_PKEY_RTPMCAST_CHANNEL_ADDRESS;

// address=[0x3ae13c8]
_MF_MT_H264_SUPPORTED_USAGES;

// address=[0x3ae13dc]
_PKEY_RTPMCAST_CHANNEL_FEC_SPAN;

// address=[0x3ae13f4]
_PKEY_RTPMCAST_CHANNEL_FEC_PACKETS_PER_SPAN;

// address=[0x3ae140c]
_MF_MT_H264_CAPABILITIES;

// address=[0x3ae1420]
_PKEY_RTPMCAST_CHANNEL_ANNOUNCEMENT_INTERVAL;

// address=[0x3ae1438]
_MF_MT_H264_SVC_CAPABILITIES;

// address=[0x3ae144c]
_MF_MT_H264_USAGE;

// address=[0x3ae1460]
_PKEY_RTPMCAST_CHANNEL_ACCELERATION_RATE;

// address=[0x3ae1478]
_PKEY_RTPMCAST_CONFIGURATION;

// address=[0x3ae1490]
_MF_MT_H264_RATE_CONTROL_MODES;

// address=[0x3ae14a4]
_MFNETSESSION_SHARED_LOCK;

// address=[0x3ae14b8]
_MF_MT_H264_LAYOUT_PER_STREAM;

// address=[0x3ae14cc]
_MF_MT_DV_AAUX_SRC_PACK_0;

// address=[0x3ae14e0]
_MFNETSESSION_LINK_BANDWIDTH;

// address=[0x3ae14f4]
_MFNETSESSION_MDE_DATAPATH;

// address=[0x3ae1508]
_MF_BYTESTREAM_PROXY;

// address=[0x3ae151c]
_MF_MT_DV_AAUX_CTRL_PACK_0;

// address=[0x3ae1530]
_MF_MT_DV_AAUX_SRC_PACK_1;

// address=[0x3ae1544]
_MFNETSESSION_USEQOSFORRTP;

// address=[0x3ae1558]
_MF_WINRT_AUTO_PRESET;

// address=[0x3ae156c]
_SDPBUILDER_URL;

// address=[0x3ae1580]
_MF_MT_DV_AAUX_CTRL_PACK_1;

// address=[0x3ae1594]
_MEDeviceStreamCreated;

// address=[0x3ae15a8]
_MF_MT_DV_VAUX_SRC_PACK;

// address=[0x3ae15bc]
_MF_SAMPLEGRABBERSINK_DXMANAGER;

// address=[0x3ae15d0]
_SDPBUILDER_RTPTYPE;

// address=[0x3ae15e4]
_MF_SAMPLEGRABBERSINK_DXSHAREDTEXTURES;

// address=[0x3ae15f8]
_MF_MT_DV_VAUX_CTRL_PACK;

// address=[0x3ae160c]
_SDPBUILDER_ENABLERTX;

// address=[0x3ae1620]
_MFNETSOURCE_STATISTICS_SERVICE;

// address=[0x3ae1634]
_SDPBUILDER_ENABLERTXDUP;

// address=[0x3ae1648]
_MFNETSOURCE_STATISTICS;

// address=[0x3ae165c]
_SDPBUILDER_RTXTIME;

// address=[0x3ae1670]
_SDPBUILDER_ENABLEFEC;

// address=[0x3ae1684]
_MFWMIGUID_TOPOLOADER_EVENT;

// address=[0x3ae1698]
_MFNETSOURCE_BUFFERINGTIME;

// address=[0x3ae16ac]
_SDPBUILDER_ENABLEBFR;

// address=[0x3ae16c0]
_MFNETSOURCE_ACCELERATEDSTREAMINGDURATION;

// address=[0x3ae16d4]
_SDPBUILDER_BFRINTERVAL;

// address=[0x3ae16e8]
_MFNETSOURCE_MAXUDPACCELERATEDSTREAMINGDURATION;

// address=[0x3ae16fc]
_MFNETSOURCE_MAXBUFFERTIMEMS;

// address=[0x3ae1710]
_SDPBUILDER_RTPFORMATNAME;

// address=[0x3ae1724]
_SDPBUILDER_SSRC;

// address=[0x3ae1738]
_MFNETSOURCE_CONNECTIONBANDWIDTH;

// address=[0x3ae174c]
_SDPBUILDER_MULTICASTADDRESS;

// address=[0x3ae1760]
_MFNETSOURCE_CACHEENABLED;

// address=[0x3ae1774]
_SDPBUILDER_MULTICASTPORT;

// address=[0x3ae1788]
_MFNETSOURCE_AUTORECONNECTLIMIT;

// address=[0x3ae179c]
_SDPBUILDER_SOURCEADDRESS;

// address=[0x3ae17b0]
_MFNETSOURCE_RESENDSENABLED;

// address=[0x3ae17c4]
_MFNETSOURCE_THINNINGENABLED;

// address=[0x3ae17d8]
_SDPBUILDER_LOG_URL;

// address=[0x3ae17ec]
_MFNETSOURCE_PROTOCOL;

// address=[0x3ae1800]
_SDPBUILDER_FECSPAN;

// address=[0x3ae1814]
_MFNETSOURCE_TRANSPORT;

// address=[0x3ae1828]
_SDPBUILDER_FECPACKETSPERSPAN;

// address=[0x3ae183c]
_MFWMIGUID_LATENCY_EVENT;

// address=[0x3ae1850]
_MFNETSOURCE_PREVIEWMODEENABLED;

// address=[0x3ae1864]
_SDPBUILDER_SIGNPUBLICKEY;

// address=[0x3ae1878]
_MF_MT_ARBITRARY_HEADER;

// address=[0x3ae188c]
_SDPBUILDER_ALLOW_CACHING;

// address=[0x3ae18a0]
_MFNETSOURCE_CREDENTIAL_MANAGER;

// address=[0x3ae18b4]
_MF_MT_ARBITRARY_FORMAT;

// address=[0x3ae18c8]
_MF_CAPTURE_ENGINE_RECORD_DURATION_LIMITATION;

// address=[0x3ae18dc]
_MFNETSOURCE_PPBANDWIDTH;

// address=[0x3ae18f0]
_SDPBUILDER_ALLOW_SPLITTING;

// address=[0x3ae1904]
_MF_CAPTURE_ENGINE_RECORD_LIMITATION_EXCEEDED;

// address=[0x3ae1918]
_MF_MT_IMAGE_LOSS_TOLERANT;

// address=[0x3ae192c]
_MFNETSOURCE_AUTORECONNECTPROGRESS;

// address=[0x3ae1940]
_SDPBUILDER_CACHE_EXPIRATION;

// address=[0x3ae1954]
_SDPBUILDER_LICENSE_RESPONSE;

// address=[0x3ae1968]
_MFNETSOURCE_PROXYLOCATORFACTORY;

// address=[0x3ae197c]
_MFPKEY_SourceOpenMonitor;

// address=[0x3ae1994]
_MF_MT_MPEG4_SAMPLE_DESCRIPTION;

// address=[0x3ae19a8]
_MF_DEVICE_BROKER_THREADID;

// address=[0x3ae19bc]
_SDPBUILDER_LICENSE_KID;

// address=[0x3ae19d0]
_MF_CAPTURE_ENGINE_SHUTDOWN_EFFECTS;

// address=[0x3ae19e4]
_MF_MT_MPEG4_CURRENT_SAMPLE_ENTRY;

// address=[0x3ae19f8]
_MFNETSOURCE_BROWSERUSERAGENT;

// address=[0x3ae1a0c]
_MFPKEY_ASFMediaSource_ApproxSeek;

// address=[0x3ae1a24]
_MFNETSOURCE_USE_TEMPLOC_CACHING;

// address=[0x3ae1a38]
_MFPKEY_ASFMediaSource_IterativeSeekIfNoIndex;

// address=[0x3ae1a50]
_MFNETSOURCE_BROWSERWEBPAGE;

// address=[0x3ae1a64]
_MF_MT_ORIGINAL_4CC;

// address=[0x3ae1a78]
_SDPBUILDER_CONTENTDESCRIPTONLIMIT;

// address=[0x3ae1a8c]
_MEDIACACHE_DISK_QUOTA;

// address=[0x3ae1aa0]
_MFPKEY_ASFMediaSource_IterativeSeek_Max_Count;

// address=[0x3ae1ab8]
_MFNETSOURCE_PLAYERVERSION;

// address=[0x3ae1acc]
_MF_SESSION_INPROC;

// address=[0x3ae1ae0]
_MF_MT_ORIGINAL_WAVE_FORMAT_TAG;

// address=[0x3ae1af4]
_MF_SA_D3D11_USE_MULTIPLANE_OVERLAY;

// address=[0x3ae1b08]
_MFPKEY_ASFMediaSource_IterativeSeek_Tolerance_In_MilliSecond;

// address=[0x3ae1b20]
_MF_MT_FRAME_RATE_RANGE_MIN;

// address=[0x3ae1b34]
_MEDIACACHE_MEM_QUOTA;

// address=[0x3ae1b48]
_MFNETSOURCE_PLAYERID;

// address=[0x3ae1b5c]
_MF_SA_D3D11_USE_RESTRICTED_SURFACES;

// address=[0x3ae1b70]
_MEDIACACHE_TIME_QUOTA;

// address=[0x3ae1b84]
_MFNETSOURCE_HOSTEXE;

// address=[0x3ae1b98]
_MFPKEY_Content_DLNA_Profile_ID;

// address=[0x3ae1bb0]
_MF_MT_FRAME_RATE_RANGE_MAX;

// address=[0x3ae1bc4]
_MF_AUDIO_RENDERER_ATTRIBUTE_BUFFER_DURATION;

// address=[0x3ae1bd8]
_MF_METADATA_PROVIDER_SERVICE;

// address=[0x3ae1bec]
_MEDIACACHE_DISK_LOW_THRESHOLD;

// address=[0x3ae1c00]
_MF_LOW_LATENCY;

// address=[0x3ae1c14]
_MFNETSOURCE_HOSTVERSION;

// address=[0x3ae1c28]
_MFPKEY_MediaSource_DisableReadAhead;

// address=[0x3ae1c40]
_MFPKEY_SBESourceMode;

// address=[0x3ae1c58]
_MFWMIGUID_PACKETSINK_EVENT;

// address=[0x3ae1c6c]
_PKEY_MFNETRTPSTREAM_FECPARAMETERS;

// address=[0x3ae1c84]
_MF_VIDEO_MAX_MB_PER_SEC;

// address=[0x3ae1c98]
_MF_AUDIO_RENDERER_ATTRIBUTE_PHONE_STREAM_CATEGORY;

// address=[0x3ae1cac]
_MFNETSOURCE_PLAYERUSERAGENT;

// address=[0x3ae1cc0]
_MF_PROPERTY_HANDLER_SERVICE;

// address=[0x3ae1cd4]
_MF_BYTESTREAM_OPTICAL_MEDIA;

// address=[0x3ae1ce8]
_MFPKEY_PMP_Creation_Callback;

// address=[0x3ae1d00]
_MFNETSOURCE_CLIENTGUID;

// address=[0x3ae1d14]
_MFMediaType_Default;

// address=[0x3ae1d28]
_PKEY_MFNETRTPSTREAM_NACKPARAMETERS;

// address=[0x3ae1d40]
_PKEY_MFNETRTPSTREAM_LEAKYBUCKETPARAMETERS;

// address=[0x3ae1d58]
_MFASFINDEXER_TYPE_FRAME;

// address=[0x3ae1d6c]
_MFPKEY_HTTP_ByteStream_Enable_Urlmon;

// address=[0x3ae1d84]
_MFMediaType_Audio;

// address=[0x3ae1d98]
_MFNETSOURCE_LOGURL;

// address=[0x3ae1dac]
_MF_BYTESTREAM_CONTENT_TYPE_AUTHORITATIVE;

// address=[0x3ae1dc0]
_MFPKEY_HTTP_ByteStream_Urlmon_Bind_Flags;

// address=[0x3ae1dd8]
_MF_AUDIO_RENDERER_ATTRIBUTE_ONLY_AUDIO;

// address=[0x3ae1dec]
_MFMediaType_Video;

// address=[0x3ae1e00]
_MFPKEY_PmpSessionHost;

// address=[0x3ae1e18]
_PKEY_MFNETRTPSTREAM_ACCELERATIONPARAMETERS;

// address=[0x3ae1e30]
_MFNETSOURCE_ENABLE_UDP;

// address=[0x3ae1e44]
_MFMediaType_Protected;

// address=[0x3ae1e58]
_MFPKEY_HTTP_ByteStream_Urlmon_Security_Id;

// address=[0x3ae1e70]
_MF_AUDIO_RENDERER_ATTRIBUTE_DISABLE_OFFLOAD;

// address=[0x3ae1e84]
_MFNETSOURCE_ENABLE_TCP;

// address=[0x3ae1e98]
_PKEY_MFNETRTPSTREAM_RELIABLE_DELIVERY;

// address=[0x3ae1eb0]
_MFMediaType_SAMI;

// address=[0x3ae1ec4]
_PKEY_MFNETRTPSTREAM_RECEIVER_BUFFER_SIZE_MS;

// address=[0x3ae1edc]
_MF_CAPTURE_SOURCE_EVENT_DEVICE_EXTENDED_PROPERTY_COMMITTED;

// address=[0x3ae1ef0]
_MFNETSOURCE_ENABLE_MSB;

// address=[0x3ae1f04]
_MFPKEY_HTTP_ByteStream_Urlmon_Window;

// address=[0x3ae1f1c]
_MFPKEY_HTTP_ByteStream_Urlmon_Callback_QueryService;

// address=[0x3ae1f34]
_MFNETSOURCE_ENABLE_RTSP;

// address=[0x3ae1f48]
_MF_CAPTURE_ENGINE_EVENT_EXTENDEDPROP_CONTROL;

// address=[0x3ae1f5c]
_PKEY_MFNETRTPSTREAM_FEEDBACKINTERVAL;

// address=[0x3ae1f74]
_MFMediaType_Script;

// address=[0x3ae1f88]
_MFNETSOURCE_ENABLE_HTTP;

// address=[0x3ae1f9c]
_MFPKEY_MediaProtectionSystemId;

// address=[0x3ae1fb4]
_PKEY_MFNETCHFAC_SUPPORT_UNRELIABLE_DELIVERY;

// address=[0x3ae1fcc]
_MFMediaType_Image;

// address=[0x3ae1fe0]
_MF_CAPTURE_ENGINE_EVENT_EXTENDEDPROP_COOKIE;

// address=[0x3ae1ff4]
_MFMediaType_HTML;

// address=[0x3ae2008]
_MFNETSOURCE_ENABLE_STREAMING;

// address=[0x3ae201c]
_MF_INTERNAL_CAPTURESOURCE_DEVICECONTROL_COOKIE;

// address=[0x3ae2030]
_PKEY_MFNETCHFAC_SUPPORT_RELIABLE_DELIVERY;

// address=[0x3ae2048]
_MFPKEY_MediaProtectionSystemContext;

// address=[0x3ae2060]
_PKEY_MFNETCHFAC_ESTIMATED_BANDWIDTH_KBPS;

// address=[0x3ae2078]
_MFMediaType_Binary;

// address=[0x3ae208c]
_MFPKEY_MediaProtectionSystemIdMapping;

// address=[0x3ae20a4]
_MFNETSOURCE_ENABLE_DOWNLOAD;

// address=[0x3ae20b8]
_MFNETSOURCE_ENABLE_PRIVATEMODE;

// address=[0x3ae20cc]
_MFPKEY_MediaProtectionContainerGuid;

// address=[0x3ae20e4]
_PKEY_MFNETCHFAC_LOCAL_IP_ADDRESS;

// address=[0x3ae20fc]
_MFMediaType_FileTransfer;

// address=[0x3ae2110]
_MFNETSOURCE_UDP_PORT_RANGE;

// address=[0x3ae2124]
_MFWMIGUID_NETPLAT_EVENT;

// address=[0x3ae2138]
_PKEY_MFNETCHFAC_SESSION_ID;

// address=[0x3ae2150]
_MFPKEY_MediaProtectionSystemContextsPerTrack;

// address=[0x3ae2168]
_MFMediaType_Stream;

// address=[0x3ae217c]
_MFNETSOURCE_PROXYINFO;

// address=[0x3ae2190]
_MFPKEY_HTTP_ByteStream_Download_Mode;

// address=[0x3ae21a8]
_MFImageFormat_JPEG;

// address=[0x3ae21bc]
_MFNETSOURCE_DRMNET_LICENSE_REPRESENTATION;

// address=[0x3ae21d0]
_MFImageFormat_RGB32;

// address=[0x3ae21e4]
_MFNETSOURCE_PROXYSETTINGS;

// address=[0x3ae21f8]
_MFStreamFormat_MPEG2Transport;

// address=[0x3ae220c]
_MFNETSOURCE_PROXYHOSTNAME;

// address=[0x3ae2220]
_MFStreamFormat_MPEG2Program;

// address=[0x3ae2234]
_AM_MEDIA_TYPE_REPRESENTATION;

// address=[0x3ae2248]
_MFNETSOURCE_PROXYPORT;

// address=[0x3ae225c]
_MFNETSOURCE_PROXYEXCEPTIONLIST;

// address=[0x3ae2270]
_FORMAT_MFVideoFormat;

// address=[0x3ae2284]
_MFNETSOURCE_PROXYBYPASSFORLOCAL;

// address=[0x3ae2298]
_MFNETSOURCE_PROXYRERUNAUTODETECTION;

// address=[0x3ae22ac]
_MFNETSOURCE_STREAM_LANGUAGE;

// address=[0x3ae22c0]
_MFNETSOURCE_LOGPARAMS;

// address=[0x3ae22d4]
_MFNETSOURCE_PEERMANAGER;

// address=[0x3ae22e8]
_MFWMIGUID_NETCHANNEL_EVENT;

// address=[0x3ae22fc]
_MF_TIME_FORMAT_ENTRY_RELATIVE;

// address=[0x3ae2310]
_MFNETSOURCE_FRIENDLYNAME;

// address=[0x3ae2324]
_MF_RATE_CONTROL_SERVICE;

// address=[0x3ae2338]
_MFWMIGUID_NETSESSION_EVENT;

// address=[0x3ae234c]
_MFWMIGUID_NETCLIENT_EVENT;

// address=[0x3ae2360]
_MF_BYTESTREAMHANDLER_ACCEPTS_SHARE_WRITE;

// address=[0x3ae2374]
_MFWMIGUID_NETCLIENT_GUID;

// address=[0x3ae2388]
_MFWMIGUID_NETSOURCE_EVENT;

// address=[0x3ae239c]
_MF_TIMECODE_SERVICE;

// address=[0x3ae23b0]
_MFWMIGUID_HTTP_BYTESTREAM_EVENT;

// address=[0x3ae23c4]
_MF_SOURCE_STREAM_SUPPORTS_HW_CONNECTION;

// address=[0x3ae23d8]
_MF_BYTESTREAM_SERVICE;

// address=[0x3ae23ec]
_MFWMIGUID_BASE_REMOTE_BYTESTREAM_EVENT;

// address=[0x3ae2400]
_MFSampleExtension_VideoInterlace;

// address=[0x3ae2414]
_MF_SCRUBBING_SERVICE;

// address=[0x3ae2428]
_MFSampleExtension_ByteStreamOffset;

// address=[0x3ae243c]
_MFVIDEOFORMAT_DynamicData;

// address=[0x3ae2450]
_MFCAPTION_MASK;

// address=[0x3ae2464]
_MFCAPTION_NTSC;

// address=[0x3ae2478]
_MFCAPTION_ATSC;

// address=[0x3ae248c]
_MFCAPTION_StreamID;

// address=[0x3ae24a0]
_MFWMIGUID_URLMON_BYTESTREAM_EVENT;

// address=[0x3ae24b4]
_MF_STREAM_SINK_SUPPORTS_HW_CONNECTION;

// address=[0x3ae24c8]
_MF_STREAM_SINK_SUPPORTS_ROTATION;

// address=[0x3ae24dc]
_MR_POLICY_VOLUME_SERVICE;

// address=[0x3ae24f0]
_MR_CAPTURE_POLICY_VOLUME_SERVICE;

// address=[0x3ae2504]
_MFWMIGUID_HTTP_WEB_REQUEST;

// address=[0x3ae2518]
_MF_MEDIA_ENGINE_XAML_MODE;

// address=[0x3ae252c]
_MFWMIGUID_MEDIACACHE_EVENT;

// address=[0x3ae2540]
_MF_TIME_FORMAT_BYTESTREAM_OFFSET;

// address=[0x3ae2554]
_MR_STREAM_VOLUME_SERVICE;

// address=[0x3ae2568]
_MFWMIGUID_SOURCERESOLUTION_EVENT;

// address=[0x3ae257c]
_MFWMIGUID_SESSION_BITPUMP_EVENT;

// address=[0x3ae2590]
_MR_AUDIO_POLICY_SERVICE;

// address=[0x3ae25a4]
_MFWMIGUID_MEDIASESSION_EVENT;

// address=[0x3ae25b8]
_MFWMIGUID_SEQUENCER_EVENT;

// address=[0x3ae25cc]
_MF_SAMPLEGRABBERSINK_SAMPLE_TIME_OFFSET;

// address=[0x3ae25e0]
_MFWMIGUID_QM_EVENT;

// address=[0x3ae25f4]
_MF_SAMPLEGRABBERSINK_IGNORE_CLOCK;

// address=[0x3ae2608]
_MFWMIGUID_MEDIA_PROC_SOURCE_EVENT;

// address=[0x3ae261c]
_MFWMIGUID_FRAME_GRABBER_EVENT;

// address=[0x3ae2630]
_MFWMIGUID_ADJUST_SAMPLE_TIME_EVENT;

// address=[0x3ae2644]
_MF_QUALITY_SERVICES;

// address=[0x3ae2658]
_MFWMIGUID_MEDIACLIP_EVENT;

// address=[0x3ae266c]
_MFWMIGUID_VIDEO_RENDER_EVENT;

// address=[0x3ae2680]
_MFCONNECTOR_SPDIF;

// address=[0x3ae2694]
_MFCONNECTOR_UNKNOWN;

// address=[0x3ae26a8]
_MFCONNECTOR_PCI;

// address=[0x3ae26bc]
_MFCONNECTOR_PCIX;

// address=[0x3ae26d0]
_MFCONNECTOR_PCI_Express;

// address=[0x3ae26e4]
_MFCONNECTOR_AGP;

// address=[0x3ae26f8]
_MFCONNECTOR_VGA;

// address=[0x3ae270c]
_MFCONNECTOR_SVIDEO;

// address=[0x3ae2720]
_MFCONNECTOR_COMPOSITE;

// address=[0x3ae2734]
_MFCONNECTOR_COMPONENT;

// address=[0x3ae2748]
_MFCONNECTOR_DVI;

// address=[0x3ae275c]
_MFCONNECTOR_HDMI;

// address=[0x3ae2770]
_MFCONNECTOR_LVDS;

// address=[0x3ae2784]
_MFCONNECTOR_D_JPN;

// address=[0x3ae2798]
_MFCONNECTOR_SDI;

// address=[0x3ae27ac]
_MFCONNECTOR_DISPLAYPORT_EXTERNAL;

// address=[0x3ae27c0]
_MFCONNECTOR_DISPLAYPORT_EMBEDDED;

// address=[0x3ae27d4]
_MFCONNECTOR_UDI_EXTERNAL;

// address=[0x3ae27e8]
_MFCONNECTOR_UDI_EMBEDDED;

// address=[0x3ae27fc]
_MFCONNECTOR_MIRACAST;

// address=[0x3ae2810]
_MFWMI_GUID_AUDIO_RENDER_EVENT;

// address=[0x3ae2824]
_MF_FULL_TOPO_SERVICE;

// address=[0x3ae2838]
_MFWMIGUID_METADATA_EVENT;

// address=[0x3ae284c]
_MFPROTECTION_DISABLE;

// address=[0x3ae2860]
_MFPROTECTION_CONSTRICTVIDEO;

// address=[0x3ae2874]
_MFPROTECTION_CONSTRICTVIDEO_NOOPM;

// address=[0x3ae2888]
_MFPROTECTION_CONSTRICTAUDIO;

// address=[0x3ae289c]
_MFPROTECTION_TRUSTEDAUDIODRIVERS;

// address=[0x3ae28b0]
_MFPROTECTION_HDCP;

// address=[0x3ae28c4]
_MFPROTECTION_CGMSA;

// address=[0x3ae28d8]
_MFPROTECTION_ACP;

// address=[0x3ae28ec]
_MFPROTECTION_WMDRMOTA;

// address=[0x3ae2900]
_MFPROTECTION_FFT;

// address=[0x3ae2914]
_MFPROTECTION_PROTECTED_SURFACE;

// address=[0x3ae2928]
_MFPROTECTION_DISABLE_SCREEN_SCRAPE;

// address=[0x3ae293c]
_MFWMIGUID_MUXER_EVENT;

// address=[0x3ae2950]
_MESourceNeedKey;

// address=[0x3ae2964]
_CLSID_EMEStoreActivate;

// address=[0x3ae2978]
_GUID_PackageFullName;

// address=[0x3ae298c]
_GUID_ClassName;

// address=[0x3ae29a0]
_GUID_ObjectStream;

// address=[0x3ae29b4]
_MFPROTECTION_VIDEO_FRAMES;

// address=[0x3ae29c8]
_MFWMIGUID_TIMER_LATE_EVENT;

// address=[0x3ae29dc]
_MFPROTECTIONATTRIBUTE_BEST_EFFORT;

// address=[0x3ae29f0]
_MFPROTECTIONATTRIBUTE_FAIL_OVER;

// address=[0x3ae2a04]
_MFPROTECTION_GRAPHICS_TRANSFER_AES_ENCRYPTION;

// address=[0x3ae2a18]
_MFPROTECTIONATTRIBUTE_CONSTRICTVIDEO_IMAGESIZE;

// address=[0x3ae2a2c]
_MFPROTECTIONATTRIBUTE_HDCP_SRM;

// address=[0x3ae2a40]
_CEACTIVATE_ATTRIBUTE_DEFAULT_HRESULT;

// address=[0x3ae2a54]
_MFWMIGUID_LOCK_EVENT;

// address=[0x3ae2a68]
_MF_TOPOLOGY_PROJECTSTART;

// address=[0x3ae2a7c]
_MFWMIGUID_STACK_EVENT;

// address=[0x3ae2a90]
_MF_TOPOLOGY_PROJECTSTOP;

// address=[0x3ae2aa4]
_MF_TOPOLOGY_NO_MARKIN_MARKOUT;

// address=[0x3ae2ab8]
_MF_AUDIO_RENDERER_ATTRIBUTE_LIVE_STREAM;

// address=[0x3ae2acc]
_MF_TOPOLOGY_MFPLAYEX;

// address=[0x3ae2ae0]
_MF_PD_ADAPTIVE_STREAMING;

// address=[0x3ae2af4]
_MF_TOPOLOGY_DXVA_MODE;

// address=[0x3ae2b08]
_MF_TOPOLOGY_ENABLE_XVP_FOR_PLAYBACK;

// address=[0x3ae2b1c]
_MF_TOPOLOGY_STATIC_PLAYBACK_OPTIMIZATIONS;

// address=[0x3ae2b30]
_MF_TOPOLOGY_PLAYBACK_MAX_DIMS;

// address=[0x3ae2b44]
_MFWMIGUID_MFGRAPH_EVENT;

// address=[0x3ae2b58]
_MF_SampleProtectionSalt;

// address=[0x3ae2b6c]
_MF_TOPOLOGY_HARDWARE_MODE;

// address=[0x3ae2b80]
_MF_TOPOLOGY_PLAYBACK_FRAMERATE;

// address=[0x3ae2b94]
_MF_TOPOLOGY_DYNAMIC_CHANGE_NOT_ALLOWED;

// address=[0x3ae2ba8]
_MF_TOPOLOGY_ENUMERATE_SOURCE_TYPES;

// address=[0x3ae2bbc]
_CLSID_MFSourceResolver;

// address=[0x3ae2bd0]
_MF_TOPOLOGY_START_TIME_ON_PRESENTATION_SWITCH;

// address=[0x3ae2be4]
_MF_DISABLE_LOCALLY_REGISTERED_PLUGINS;

// address=[0x3ae2bf8]
_MF_LOCAL_PLUGIN_CONTROL_POLICY;

// address=[0x3ae2c0c]
_MF_WORKQUEUE_SERVICES;

// address=[0x3ae2c20]
_MF_DEVPROXY_EXTERNAL_ALLOCATOR;

// address=[0x3ae2c34]
_MF_DEVPROXY_EXTERNAL_ALLOCATOR_MAX_BUFFERS;

// address=[0x3ae2c48]
_MFWMIGUID_WMP_PLAYBACK;

// address=[0x3ae2c5c]
_MF_DEVPROXY_EXTERNAL_ALLOCATOR_PIN_CATEGORY;

// address=[0x3ae2c70]
_PKEY_MDEPROFILE_UNIQUE_PROFILEID;

// address=[0x3ae2c88]
_MF_DEVPROXY_EXTERNAL_ALLOCATOR_PIN_SUBTYPE;

// address=[0x3ae2c9c]
_PKEY_MDEPROFILE_UNIQUE_GROUPID;

// address=[0x3ae2cb4]
_MF_ALLOCATOR_SAMPLE_BUFFER_ALIGNMENT;

// address=[0x3ae2cc8]
_MF_ALLOCATOR_SAMPLE_BUFFER_SIZE;

// address=[0x3ae2cdc]
_PKEY_MDEPROFILE_TRANSCODING_PROFILE;

// address=[0x3ae2cf4]
_PKEY_MDEPROFILE_INPUTMIMETYPE;

// address=[0x3ae2d0c]
_PKEY_MDEPROFILE_OUTPUTMIMETYPE;

// address=[0x3ae2d24]
_PKEY_MDEPROFILE_DLNA_LABEL;

// address=[0x3ae2d3c]
_MF_TOPOLOGY_ENABLE_TRANSCODE_BRANCH_LOADER;

// address=[0x3ae2d50]
_MF_TOPOLOGY_ENABLE_DXGI_TRANSCODE_BRANCH_LOADER;

// address=[0x3ae2d64]
_PKEY_MDEPROFILE_RTSP_ENABLED;

// address=[0x3ae2d7c]
_MF_TOPOLOGY_D3D_MANAGER;

// address=[0x3ae2d90]
_PKEY_MDEPROFILE_RTSP_RTPPACKETIZER;

// address=[0x3ae2da8]
_PKEY_MDEPROFILE_RTSP_SDPGENERATOR;

// address=[0x3ae2dc0]
_MF_TOPOLOGY_APP_PRODUCT_ID;

// address=[0x3ae2dd4]
_PKEY_MDEPROFILE_HTTP_ENABLED;

// address=[0x3ae2dec]
_MF_TOPOLOGY_WRAP_SYNC_DECRYPTOR_MFTS;

// address=[0x3ae2e00]
_PKEY_MDEPROFILE_CARDEA_ENABLED;

// address=[0x3ae2e18]
_MF_TOPOLOGY_ENABLE_DRM_EOS_MODE;

// address=[0x3ae2e2c]
_PKEY_MDEPROFILE_DTCP_ENABLED;

// address=[0x3ae2e44]
_PKEY_MDEPROFILE_PMPUSAGE;

// address=[0x3ae2e5c]
_PKEY_MDEPROFILE_BYTESEEK_SUPPORTED;

// address=[0x3ae2e74]
_PKEY_MDEPROFILE_TIMESEEK_SUPPORTED;

// address=[0x3ae2e8c]
_PKEY_MDEPROFILE_PLAYSPEEDS;

// address=[0x3ae2ea4]
_PKEY_MDEPROFILE_AUDIO_SAMPLESPERSEC;

// address=[0x3ae2ebc]
_PKEY_MDEPROFILE_AUDIO_BITSPERSAMPLE;

// address=[0x3ae2ed4]
_PKEY_MDEPROFILE_AUDIO_AVGBYTESPERSECOND;

// address=[0x3ae2eec]
_PKEY_MDEPROFILE_AUDIO_NUMBEROFCHANNELS;

// address=[0x3ae2f04]
_PKEY_MDEPROFILE_AUDIO_DEVICECONFORMANCETEMPLATE;

// address=[0x3ae2f1c]
_PKEY_MDEPROFILE_VIDEO_DEVICECONFORMANCETEMPLATE;

// address=[0x3ae2f34]
_MFWMIGUID_PEAUTHCOMM_EVENT;

// address=[0x3ae2f48]
_PKEY_MDEPROFILE_VIDEO_WIDTH;

// address=[0x3ae2f60]
_PKEY_MDEPROFILE_VIDEO_HEIGHT;

// address=[0x3ae2f78]
_PKEY_MDEPROFILE_VIDEO_BITRATE;

// address=[0x3ae2f90]
_PKEY_MDEPROFILE_VIDEO_BUFFERWINDOW;

// address=[0x3ae2fa8]
_PKEY_MDEPROFILE_VIDEO_FRAMESPERSECOND;

// address=[0x3ae2fc0]
_PKEY_MDEPROFILE_VIDEO_KEYFRAMESINTERVAL;

// address=[0x3ae2fd8]
_PKEY_MDEPROFILE_VIDEO_ENCODERCOMPLEXITY;

// address=[0x3ae2ff0]
_PKEY_MDEPROFILE_VIDEO_ADAPTIVE_ENC;

// address=[0x3ae3008]
_MFWMIGUID_CACHEREADER_EVENT;

// address=[0x3ae301c]
_PKEY_MDEPROFILE_IMAGE_WIDTH;

// address=[0x3ae3034]
_PKEY_MDEPROFILE_IMAGE_HEIGHT;

// address=[0x3ae304c]
_PKEY_MDEPROFILE_IMAGE_ASPECT_RATIO_X;

// address=[0x3ae3064]
_PKEY_MDEPROFILE_IMAGE_ASPECT_RATIO_Y;

// address=[0x3ae307c]
_PKEY_MDEPROFILE_BACKGROUND_COLOR_R;

// address=[0x3ae3094]
_PKEY_MDEPROFILE_BACKGROUND_COLOR_G;

// address=[0x3ae30ac]
_PKEY_MDEPROFILE_BACKGROUND_COLOR_B;

// address=[0x3ae30c4]
_PKEY_MDEPROFILE_THUMBNAIL;

// address=[0x3ae30dc]
_PKEY_MDEPROFILE_BACKGROUNDTRANSFER;

// address=[0x3ae30f4]
_PKEY_MDEPROFILE_WINSAT_CPU;

// address=[0x3ae310c]
_PKEY_MDEPROFILE_WINSAT_MEMORY;

// address=[0x3ae3124]
_PKEY_MDEPROFILE_SOURCE_PRESENTATION;

// address=[0x3ae313c]
_PKEY_MDEPROFILE_RTP_PAYLOAD_FORMAT;

// address=[0x3ae3154]
_PKEY_MDEPROFILE_IFOFILEURI;

// address=[0x3ae316c]
_PKEY_MDEPROFILE_WINSAT_ENCODE;

// address=[0x3ae3184]
_MFWMIGUID_ASFSOURCE_EVENT;

// address=[0x3ae3198]
_PKEY_MDEPROFILE_AUDIO_SUBTYPE;

// address=[0x3ae31b0]
_PKEY_MDEPROFILE_VIDEO_SUBTYPE;

// address=[0x3ae31c8]
_PKEY_MDEPROFILE_AUDIO_PASSTHROUGH;

// address=[0x3ae31e0]
_PSA_KEY_STORE;

// address=[0x3ae31f8]
_PKEY_MDEPROFILE_VIDEO_PASSTHROUGH;

// address=[0x3ae3210]
_PSA_VAL_APPEND;

// address=[0x3ae3214]
_PKEY_MDEPROFILE_VIDEO_MIN_HEIGHT;

// address=[0x3ae322c]
_PKEY_MDEPROFILE_VIDEO_MIN_WIDTH;

// address=[0x3ae3244]
_PSA_VAL_PROPERTY;

// address=[0x3ae3248]
_PKEY_MDEPROFILE_VIDEO_MIN_BITRATE;

// address=[0x3ae3260]
_PKEY_MDEPROFILE_VIDEO_MIN_PIXELS;

// address=[0x3ae3278]
_PKEY_MDEPROFILE_VIDEO_MAX_PIXELS;

// address=[0x3ae3290]
_PKEY_MDEPROFILE_VIDEO_MAX_PIXEL_RATE;

// address=[0x3ae32a8]
_PKEY_MDEPROFILE_WINSAT_CPU_DELTA;

// address=[0x3ae32c0]
_MFWMIGUID_OPQUEUE_EVENT;

// address=[0x3ae32d4]
_PKEY_MDEPROFILE_STANDARD;

// address=[0x3ae32ec]
_MF_EVENT_SESSIONCAPS;

// address=[0x3ae3300]
_MDE_DEFAULT_DOWNLOADPROFILE;

// address=[0x3ae3314]
_MF_EVENT_SESSIONCAPS_DELTA;

// address=[0x3ae3328]
_MDE_DEFAULT_WMAUDIOVIDEOPROFILE;

// address=[0x3ae333c]
_MDE_DEFAULT_PCMPROFILE;

// address=[0x3ae3350]
_MDE_DEFAULT_JPEGPROFILE;

// address=[0x3ae3364]
_MDE_DEFAULT_YUVPROFILE;

// address=[0x3ae3378]
_PKEY_MFNETCONNECTION_DOWNLOADREQUEST;

// address=[0x3ae3390]
_PKEY_MDEPROFILES_ENABLE_RTSP_FOR_ALL_FORMATS;

// address=[0x3ae33a8]
_PKEY_MDEPROFILES_ENABLE_DRM_PASSTHROUGH;

// address=[0x3ae33c0]
_PKEY_MDEPROFILES_ENABLE_AUDIOONLYPROFILES_FOR_VIDEO;

// address=[0x3ae33d8]
_CLSID_TranscodeSinkActivate;

// address=[0x3ae33ec]
_CLSID_TV_PROFILEMGR;

// address=[0x3ae3400]
_MF_EVENT_TOPOLOGY_STATUS;

// address=[0x3ae3414]
_MFNETSOURCE_AUTHENTICATION_MANAGER;

// address=[0x3ae3428]
_MFWMIGUID_EVR_QUEUE_EVENT;

// address=[0x3ae343c]
_MF_EVENT_START_PRESENTATION_TIME;

// address=[0x3ae3450]
_MF_EVENT_PRESENTATION_TIME_OFFSET;

// address=[0x3ae3464]
_MFComponentID_ASFMediaSource;

// address=[0x3ae3478]
_MFNETSOURCE_ENABLE_RTPM;

// address=[0x3ae348c]
_MFComponentID_ASFMediaSink;

// address=[0x3ae34a0]
_MF_EVENT_START_PRESENTATION_TIME_AT_OUTPUT;

// address=[0x3ae34b4]
_MFSAMPLE_NetSequenceNumber;

// address=[0x3ae34c8]
_MF_REMOTE_PROXY;

// address=[0x3ae34dc]
_MFComponentID_MP3MediaSource;

// address=[0x3ae34f0]
_MF_EVENT_SOURCE_FAKE_START;

// address=[0x3ae3504]
_MF_MT_NODRM_RTP_PT;

// address=[0x3ae3518]
_MF_EVENT_SOURCE_PROJECTSTART;

// address=[0x3ae352c]
_PKEY_Media_FormatCompliance;

// address=[0x3ae3544]
_MFComponentID_MP3MediaSink;

// address=[0x3ae3558]
_MFComponentID_NetworkMediaSource;

// address=[0x3ae356c]
_MF_EVENT_SOURCE_ACTUAL_START;

// address=[0x3ae3580]
_MFComponentID_LPCMMediaSource;

// address=[0x3ae3594]
_MF_EVENT_SOURCE_TOPOLOGY_CANCELED;

// address=[0x3ae35a8]
_MFComponentID_ByteStreamMediaSource;

// address=[0x3ae35bc]
_MF_EVENT_SOURCE_CHARACTERISTICS;

// address=[0x3ae35d0]
_MFComponentID_AVIMediaSourcePlugin;

// address=[0x3ae35e4]
_MF_TOPONODE_FLUSH;

// address=[0x3ae35f8]
_MF_EVENT_SOURCE_CHARACTERISTICS_OLD;

// address=[0x3ae360c]
_MF_EVENT_DO_THINNING;

// address=[0x3ae3620]
_MFComponentID_MP4MediaSourcePlugin;

// address=[0x3ae3634]
_MF_EVENT_SCRUBSAMPLE_TIME;

// address=[0x3ae3648]
_MFComponentRole_MediaSource;

// address=[0x3ae365c]
_MFComponentRole_MediaSink;

// address=[0x3ae3670]
_MF_EVENT_OUTPUT_NODE;

// address=[0x3ae3684]
_MF_QUALITY_NOTIFY_PROCESSING_LATENCY;

// address=[0x3ae3698]
_MFWMIGUID_EVR_DWM_DEQUEUE_EVENT;

// address=[0x3ae36ac]
_MF_QUALITY_NOTIFY_SAMPLE_LAG;

// address=[0x3ae36c0]
_MF_EVENT_MFT_INPUT_STREAM_ID;

// address=[0x3ae36d4]
_MF_EVENT_MFT_CONTEXT;

// address=[0x3ae36e8]
_MF_TOPONODE_DRAIN;

// address=[0x3ae36fc]
_MF_EVENT_STREAM_METADATA_KEYDATA;

// address=[0x3ae3710]
_MF_TOPONODE_D3DAWARE;

// address=[0x3ae3724]
_MF_EVENT_STREAM_METADATA_CONTENT_KEYIDS;

// address=[0x3ae3738]
_MF_EVENT_STREAM_METADATA_SYSTEMID;

// address=[0x3ae374c]
_MF_TOPOLOGY_RESOLUTION_STATUS;

// address=[0x3ae3760]
_MF_TOPONODE_ERRORCODE;

// address=[0x3ae3774]
_MF_TOPONODE_CONNECT_METHOD;

// address=[0x3ae3788]
__GUID_df0b3d60_548f_101b_8e65_08002b2bd119;

// address=[0x3ae37a0]
__GUID_00000000_0000_0000_0000_000000000000;

// address=[0x3ae37b4]
__GUID_00020400_0000_0000_c000_000000000046;

// address=[0x3ae37c8]
__GUID_1cf2b120_547d_101b_8e65_08002b2bd119;

// address=[0x3aea2f8]
__real@3e7ad7f29abcaf48;

// address=[0x3aeeab0]
__real@3f1a36e2eb1c432d;

// address=[0x3aeeac0]
__real@3f70624dd2f1a9fc;

// address=[0x3aeead0]
__real@3fc3333333333333;

// address=[0x3aeeae0]
__real@3ffa3d70a3d70a3d;

// address=[0x3aeeaf0]
__real@3ffb333333333333;

// address=[0x3aeeb00]
__real@3ffc000000000000;

// address=[0x3aeeb10]
__real@3ffcf5c28f5c28f6;

// address=[0x3aeeb20]
__real@3ffe147ae147ae14;

// address=[0x3aeeb30]
__real@3fff5c28f5c28f5c;

// address=[0x3aeeb40]
__real@4000666666666666;

// address=[0x3aeeb50]
__real@40015c28f5c28f5c;

// address=[0x3aeeb60]
__real@40029c432ca57a78;

// address=[0x3aeeb70]
__real@40049ba5e353f7cf;

// address=[0x3af0c38]
struct _GUID const Concurrency::ConcRT_ProviderGuid;

// address=[0x3af0c48]
struct _GUID const Concurrency::ConcRTEventGuid;

// address=[0x3af0c68]
struct _GUID const Concurrency::ScheduleGroupEventGuid;

// address=[0x3af0c88]
struct _GUID const Concurrency::ChoreEventGuid;

// address=[0x3af0c98]
struct _GUID const Concurrency::VirtualProcessorEventGuid;

// address=[0x3af0ca8]
struct _GUID const Concurrency::LockEventGuid;

// address=[0x3af0cb8]
struct _GUID const Concurrency::ResourceManagerEventGuid;

// address=[0x3af0cc8]
struct _GUID const Concurrency::PPLParallelInvokeEventGuid;

// address=[0x3af0cd8]
struct _GUID const Concurrency::PPLParallelForEventGuid;

// address=[0x3af0ce8]
struct _GUID const Concurrency::PPLParallelForeachEventGuid;

// address=[0x3af0cf8]
struct _GUID const Concurrency::AgentEventGuid;

// address=[0x3af5bd8]
__pDestructExceptionObject;

// address=[0x3af75e8]
_standard_lookup_table;

// address=[0x3af7658]
_format_validation_lookup_table;

// address=[0x3b0761c]
_RtlNtPathSeperatorString;

// address=[0x3b0762c]
_RtlDosPathSeperatorsString;

// address=[0x3b07640]
_RtlAlternateDosPathSeperatorString;

// address=[0x3b07ef0]
__Fenv0;

// address=[0x3b09614]
__half;

// address=[0x3b096c8]
__real@8000000000000000;

// address=[0x3b0e5f0]
__sys_errlist;

// address=[0x3b0ea5c]
__sys_nerr;

// address=[0x3b16040]
__wctype;

// address=[0x3b162b0]
___newctype;

// address=[0x3b16650]
___newclmap;

// address=[0x3b16820]
___newcumap;

// address=[0x3b18db0]
___lc_category;

// address=[0x3b1b718]
___lc_time_c;

// address=[0x3b1b8d0]
__indefinite;

// address=[0x3b1b8da]
__piby2;

// address=[0x3b1b8e4]
__piby4;

// address=[0x3b1b928]
__DEFAULT_CW_in_mem;

// address=[0x3b1b92a]
__pi_by_2_to_61;

// address=[0x3b1be44]
__days;

// address=[0x3b1be84]
__lpdays;

// address=[0x3b1ca80]
__d_inf;

// address=[0x3b1ca90]
__d_ind;

// address=[0x3b1caa0]
__d_max;

// address=[0x3b1cab0]
__d_min;

// address=[0x3b1cac0]
__d_mzero;

// address=[0x3b1cbc0]
__infinity;

// address=[0x3b1cbca]
__minfinity;

// address=[0x3b1cbd4]
__logemax;

// address=[0x3b1cbfa]
__OP_EXPjmptab;

// address=[0x3b1ce78]
___dnames;

// address=[0x3b1ce94]
___mnames;

// address=[0x3b1e618]
__Denorm_C;

// address=[0x3b1e628]
__Inf_C;

// address=[0x3b1e638]
__Nan_C;

// address=[0x3b1e648]
__Snan_C;

// address=[0x3b1e658]
__Hugeval_C;

// address=[0x3b1e668]
__FDenorm_C;

// address=[0x3b1e678]
__FInf_C;

// address=[0x3b1e688]
__FNan_C;

// address=[0x3b1e698]
__FSnan_C;

// address=[0x3b1e6a8]
__LDenorm_C;

// address=[0x3b1e6b8]
__LInf_C;

// address=[0x3b1e6c8]
__LNan_C;

// address=[0x3b1e6d8]
__LSnan_C;

// address=[0x3b1e6e8]
__Eps_C;

// address=[0x3b1e6f8]
__Rteps_C;

// address=[0x3b1e708]
__FEps_C;

// address=[0x3b1e718]
__FRteps_C;

// address=[0x3b1e728]
__LEps_C;

// address=[0x3b1e738]
__LRteps_C;

// address=[0x3b1e748]
__Zero_C;

// address=[0x3b1e758]
__Xbig_C;

// address=[0x3b1e764]
__FZero_C;

// address=[0x3b1e768]
__FXbig_C;

// address=[0x3b1e770]
__LZero_C;

// address=[0x3b1e780]
__LXbig_C;

// address=[0x3b27af4]
___rglangidNotDefault;

// address=[0x3b2a7d4]
_IID_IDirectSoundFullDuplex;

// address=[0x3b2a7e8]
_GUID_KeyboardClass;

// address=[0x3b2a7fc]
_GUID_MediaClass;

// address=[0x3b2a810]
_GUID_MouseClass;

// address=[0x3b2a824]
_GUID_HIDClass;

// address=[0x3b2a838]
_IID_IDirectPlay;

// address=[0x3b2a84c]
_IID_IDirectPlayLobby;

// address=[0x3b2a860]
_IID_IDirectPlayLobbyA;

// address=[0x3b2a874]
_IID_IDirectPlayLobby2;

// address=[0x3b2a888]
_IID_IDirectPlayLobby2A;

// address=[0x3b2a89c]
_IID_IDirectPlayLobby3;

// address=[0x3b2a8b0]
_IID_IDirectPlayLobby3A;

// address=[0x3b2a8c4]
_CLSID_DirectPlayLobby;

// address=[0x3b2a8d8]
_IID_IReferenceClock;

// address=[0x3b2a8ec]
_DS3DALG_NO_VIRTUALIZATION;

// address=[0x3b2a900]
_DS3DALG_HRTF_FULL;

// address=[0x3b2a914]
_DS3DALG_HRTF_LIGHT;

// address=[0x3b2a928]
_GUID_DSFX_STANDARD_GARGLE;

// address=[0x3b2a93c]
_GUID_DSFX_STANDARD_CHORUS;

// address=[0x3b2a950]
_GUID_DSFX_STANDARD_FLANGER;

// address=[0x3b2a964]
_GUID_DSFX_STANDARD_ECHO;

// address=[0x3b2a978]
_GUID_DSFX_STANDARD_DISTORTION;

// address=[0x3b2a98c]
_GUID_DSFX_STANDARD_COMPRESSOR;

// address=[0x3b2a9a0]
_GUID_DSFX_STANDARD_PARAMEQ;

// address=[0x3b2a9b4]
_GUID_DSFX_STANDARD_I3DL2REVERB;

// address=[0x3b2a9c8]
_GUID_DSFX_WAVES_REVERB;

// address=[0x3b2a9dc]
_GUID_DSCFX_CLASS_AEC;

// address=[0x3b2a9f0]
_GUID_DSCFX_MS_AEC;

// address=[0x3b2aa04]
_GUID_DSCFX_SYSTEM_AEC;

// address=[0x3b2aa18]
_GUID_DSCFX_CLASS_NS;

// address=[0x3b2aa2c]
_GUID_DSCFX_MS_NS;

// address=[0x3b2aa40]
_GUID_DSCFX_SYSTEM_NS;

// address=[0x3b2aa54]
_IID_IDirectSound;

// address=[0x3b2aa68]
_IID_IDirectSound8;

// address=[0x3b2aa7c]
_IID_IDirectSoundBuffer;

// address=[0x3b2aa90]
_CLSID_DirectDraw;

// address=[0x3b2aaa4]
_CLSID_DirectDraw7;

// address=[0x3b2aab8]
_CLSID_DirectDrawClipper;

// address=[0x3b2aacc]
_IID_IDirectDraw;

// address=[0x3b2aae0]
_IID_IDirectDraw2;

// address=[0x3b2aaf4]
_IID_IDirectDraw4;

// address=[0x3b2ab08]
_IID_IDirectDraw7;

// address=[0x3b2ab1c]
_IID_IDirectDrawSurface;

// address=[0x3b2ab30]
_IID_IDirectDrawSurface2;

// address=[0x3b2ab44]
_IID_IDirectDrawSurface3;

// address=[0x3b2ab58]
_IID_IDirectDrawSurface4;

// address=[0x3b2ab6c]
_IID_IDirectDrawSurface7;

// address=[0x3b2ab80]
_IID_IDirectDrawSurfaceNew;

// address=[0x3b2ab94]
_CLSID_DirectDrawFactory2;

// address=[0x3b2aba8]
_IID_IDirectDrawFactory2;

// address=[0x3b2abbc]
_GUID_DirectDrawSurfaceStream;

// address=[0x3b2abd0]
_GUID_DirectDrawPaletteStream;

// address=[0x3b2abe4]
_IID_IDirectDrawOptSurface;

// address=[0x3b2abf8]
_IID_IDirectDrawPalette2;

// address=[0x3b2ac0c]
_IID_IDirectDrawPalette;

// address=[0x3b2ac20]
_IID_IDirectDrawClipper;

// address=[0x3b2ac34]
_IID_IDirectDrawColorControl;

// address=[0x3b2ac48]
_IID_IDirectDrawGammaControl;

// address=[0x3b2ac5c]
_IID_IDirectSoundBuffer8;

// address=[0x3b2ac70]
_GUID_MiscellaneousCallbacks;

// address=[0x3b2ac84]
_GUID_VideoPortCallbacks;

// address=[0x3b2ac98]
_GUID_ColorControlCallbacks;

// address=[0x3b2acac]
_GUID_VideoPortCaps;

// address=[0x3b2acc0]
_GUID_D3DCallbacks2;

// address=[0x3b2acd4]
_GUID_D3DCallbacks3;

// address=[0x3b2ace8]
_GUID_All_Objects;

// address=[0x3b2acfc]
_IID_IDirectSound3DListener;

// address=[0x3b2ad10]
_GUID_NonLocalVidMemCaps;

// address=[0x3b2ad24]
_GUID_KernelCallbacks;

// address=[0x3b2ad38]
_GUID_KernelCaps;

// address=[0x3b2ad4c]
_GUID_D3DExtendedCaps;

// address=[0x3b2ad60]
_GUID_ZPixelFormats;

// address=[0x3b2ad74]
_GUID_DDMoreSurfaceCaps;

// address=[0x3b2ad88]
_GUID_DDStereoMode;

// address=[0x3b2ad9c]
_GUID_OptSurfaceKmodeInfo;

// address=[0x3b2adb0]
_GUID_OptSurfaceUmodeInfo;

// address=[0x3b2adc4]
_GUID_UserModeDriverInfo;

// address=[0x3b2add8]
_GUID_UserModeDriverPassword;

// address=[0x3b2adec]
_GUID_D3DParseUnknownCommandCallback;

// address=[0x3b2ae00]
_GUID_MotionCompCallbacks;

// address=[0x3b2ae14]
_GUID_NTCallbacks;

// address=[0x3b2ae28]
_GUID_Miscellaneous2Callbacks;

// address=[0x3b2ae3c]
_GUID_DDMoreCaps;

// address=[0x3b2ae50]
_IID_IDDVideoPortContainer;

// address=[0x3b2ae64]
_IID_IDirectDrawVideoPort;

// address=[0x3b2ae78]
_IID_IDirectDrawVideoPortNotify;

// address=[0x3b2ae8c]
_DDVPTYPE_E_HREFH_VREFH;

// address=[0x3b2aea0]
_DDVPTYPE_E_HREFH_VREFL;

// address=[0x3b2aeb4]
_DDVPTYPE_E_HREFL_VREFH;

// address=[0x3b2aec8]
_DDVPTYPE_E_HREFL_VREFL;

// address=[0x3b2aedc]
_DDVPTYPE_CCIR656;

// address=[0x3b2aef0]
_DDVPTYPE_BROOKTREE;

// address=[0x3b2af04]
_DDVPTYPE_PHILIPS;

// address=[0x3b2af18]
_IID_IDirect3D8;

// address=[0x3b2af2c]
_IID_IDirect3DDevice8;

// address=[0x3b2af40]
_IID_IDirect3DResource8;

// address=[0x3b2af54]
_IID_IDirect3DBaseTexture8;

// address=[0x3b2af68]
_IID_IDirect3DTexture8;

// address=[0x3b2af7c]
_IID_IDirect3DCubeTexture8;

// address=[0x3b2af90]
_IID_IDirect3DVolumeTexture8;

// address=[0x3b2afa4]
_IID_IDirect3DVertexBuffer8;

// address=[0x3b2afb8]
_IID_IDirect3DIndexBuffer8;

// address=[0x3b2afcc]
_IID_IDirect3DSurface8;

// address=[0x3b2afe0]
_IID_IDirect3DVolume8;

// address=[0x3b2aff4]
_IID_IDirect3DSwapChain8;

// address=[0x3b2b008]
_TID_D3DRMInfo;

// address=[0x3b2b01c]
_TID_D3DRMMesh;

// address=[0x3b2b030]
_TID_D3DRMVector;

// address=[0x3b2b044]
_TID_D3DRMMeshFace;

// address=[0x3b2b058]
_TID_D3DRMMaterial;

// address=[0x3b2b06c]
_TID_D3DRMMaterialArray;

// address=[0x3b2b080]
_TID_D3DRMFrame;

// address=[0x3b2b094]
_TID_D3DRMFrameTransformMatrix;

// address=[0x3b2b0a8]
_TID_D3DRMMeshMaterialList;

// address=[0x3b2b0bc]
_TID_D3DRMMeshTextureCoords;

// address=[0x3b2b0d0]
_TID_D3DRMMeshNormals;

// address=[0x3b2b0e4]
_TID_D3DRMCoords2d;

// address=[0x3b2b0f8]
_TID_D3DRMMatrix4x4;

// address=[0x3b2b10c]
_TID_D3DRMAnimation;

// address=[0x3b2b120]
_TID_D3DRMAnimationSet;

// address=[0x3b2b134]
_IID_IDirectSound3DBuffer;

// address=[0x3b2b148]
_TID_D3DRMAnimationKey;

// address=[0x3b2b15c]
_TID_D3DRMFloatKeys;

// address=[0x3b2b170]
_TID_D3DRMMaterialAmbientColor;

// address=[0x3b2b184]
_TID_D3DRMMaterialDiffuseColor;

// address=[0x3b2b198]
_TID_D3DRMMaterialSpecularColor;

// address=[0x3b2b1ac]
_TID_D3DRMMaterialEmissiveColor;

// address=[0x3b2b1c0]
_TID_D3DRMMaterialPower;

// address=[0x3b2b1d4]
_TID_D3DRMColorRGBA;

// address=[0x3b2b1e8]
_TID_D3DRMColorRGB;

// address=[0x3b2b1fc]
_TID_D3DRMGuid;

// address=[0x3b2b210]
_TID_D3DRMTextureFilename;

// address=[0x3b2b224]
_TID_D3DRMTextureReference;

// address=[0x3b2b238]
_TID_D3DRMIndexedColor;

// address=[0x3b2b24c]
_TID_D3DRMMeshVertexColors;

// address=[0x3b2b260]
_TID_D3DRMMaterialWrap;

// address=[0x3b2b274]
_TID_D3DRMBoolean;

// address=[0x3b2b288]
_TID_D3DRMMeshFaceWraps;

// address=[0x3b2b29c]
_TID_D3DRMBoolean2d;

// address=[0x3b2b2b0]
_TID_D3DRMTimedFloatKeys;

// address=[0x3b2b2c4]
_TID_D3DRMAnimationOptions;

// address=[0x3b2b2d8]
_TID_D3DRMFramePosition;

// address=[0x3b2b2ec]
_TID_D3DRMFrameVelocity;

// address=[0x3b2b300]
_TID_D3DRMFrameRotation;

// address=[0x3b2b314]
_TID_D3DRMLight;

// address=[0x3b2b328]
_TID_D3DRMCamera;

// address=[0x3b2b33c]
_TID_D3DRMAppData;

// address=[0x3b2b350]
_TID_D3DRMLightUmbra;

// address=[0x3b2b364]
_TID_D3DRMLightRange;

// address=[0x3b2b378]
_TID_D3DRMLightPenumbra;

// address=[0x3b2b38c]
_TID_D3DRMLightAttenuation;

// address=[0x3b2b3a0]
_TID_D3DRMInlineData;

// address=[0x3b2b3b4]
_TID_D3DRMUrl;

// address=[0x3b2b3c8]
_TID_D3DRMProgressiveMesh;

// address=[0x3b2b3dc]
_TID_D3DRMExternalVisual;

// address=[0x3b2b3f0]
_TID_D3DRMStringProperty;

// address=[0x3b2b404]
_TID_D3DRMPropertyBag;

// address=[0x3b2b418]
_TID_D3DRMRightHanded;

// address=[0x3b2b42c]
_IID_IDirectSoundCapture;

// address=[0x3b2b440]
_IID_IDirectSoundCaptureBuffer;

// address=[0x3b2b454]
_IID_IDirectSoundCaptureBuffer8;

// address=[0x3b2b468]
_DPLPROPERTY_MessagesSupported;

// address=[0x3b2b47c]
_DPLPROPERTY_LobbyGuid;

// address=[0x3b2b490]
_DPLPROPERTY_PlayerGuid;

// address=[0x3b2b4a4]
_DPLPROPERTY_PlayerScore;

// address=[0x3b2b4b8]
_IID_IDirectSoundNotify;

// address=[0x3b2b4cc]
_IID_IKsPropertySet;

// address=[0x3b2b4e0]
_DPAID_TotalSize;

// address=[0x3b2b4f4]
_DPAID_ServiceProvider;

// address=[0x3b2b508]
_IID_IDirect3D;

// address=[0x3b2b51c]
_DPAID_LobbyProvider;

// address=[0x3b2b530]
_DPAID_Phone;

// address=[0x3b2b544]
_IID_IDirect3D2;

// address=[0x3b2b558]
_DPAID_PhoneW;

// address=[0x3b2b56c]
_IID_IDirect3D3;

// address=[0x3b2b580]
_DPAID_Modem;

// address=[0x3b2b594]
_IID_IDirect3D7;

// address=[0x3b2b5a8]
_IID_IDirect3DRampDevice;

// address=[0x3b2b5bc]
_DPAID_ModemW;

// address=[0x3b2b5d0]
_IID_IDirect3DRGBDevice;

// address=[0x3b2b5e4]
_DPAID_INet;

// address=[0x3b2b5f8]
_IID_IDirect3DHALDevice;

// address=[0x3b2b60c]
_DPAID_INetW;

// address=[0x3b2b620]
_DPAID_INetPort;

// address=[0x3b2b634]
_IID_IDirect3DMMXDevice;

// address=[0x3b2b648]
_IID_IDirect3DRefDevice;

// address=[0x3b2b65c]
_IID_IDirect3DNullDevice;

// address=[0x3b2b670]
_IID_IDirect3DTnLHalDevice;

// address=[0x3b2b684]
_IID_IDirect3DDevice;

// address=[0x3b2b698]
_CLSID_DirectMusic;

// address=[0x3b2b6ac]
_IID_IDirect3DDevice2;

// address=[0x3b2b6c0]
_IID_IDirect3DDevice3;

// address=[0x3b2b6d4]
_CLSID_DirectMusicCollection;

// address=[0x3b2b6e8]
_IID_IDirect3DDevice7;

// address=[0x3b2b6fc]
_CLSID_DirectMusicSynth;

// address=[0x3b2b710]
_IID_IDirectMusic;

// address=[0x3b2b724]
_IID_IDirect3DTexture;

// address=[0x3b2b738]
_IID_IDirect3DTexture2;

// address=[0x3b2b74c]
_IID_IDirectMusicBuffer;

// address=[0x3b2b760]
_IID_IDirectMusicPort;

// address=[0x3b2b774]
_IID_IDirect3DLight;

// address=[0x3b2b788]
_IID_IDirectMusicThru;

// address=[0x3b2b79c]
_IID_IDirect3DMaterial;

// address=[0x3b2b7b0]
_IID_IDirectMusicPortDownload;

// address=[0x3b2b7c4]
_IID_IDirect3DMaterial2;

// address=[0x3b2b7d8]
_IID_IDirectMusicDownload;

// address=[0x3b2b7ec]
_IID_IDirect3DMaterial3;

// address=[0x3b2b800]
_IID_IDirect3DExecuteBuffer;

// address=[0x3b2b814]
_IID_IDirectMusicCollection;

// address=[0x3b2b828]
_DPAID_ComPort;

// address=[0x3b2b83c]
_IID_IDirectMusicInstrument;

// address=[0x3b2b850]
_IID_IDirect3DViewport;

// address=[0x3b2b864]
_IID_IDirect3DViewport2;

// address=[0x3b2b878]
_IID_IDirectMusicDownloadedInstrument;

// address=[0x3b2b88c]
_IID_IDirectMusic2;

// address=[0x3b2b8a0]
_IID_IDirect3DViewport3;

// address=[0x3b2b8b4]
_IID_IDirect3DVertexBuffer;

// address=[0x3b2b8c8]
_IID_IDirectMusic8;

// address=[0x3b2b8dc]
_CLSID_DirectPlay8Address;

// address=[0x3b2b8f0]
_GUID_DMUS_PROP_GM_Hardware;

// address=[0x3b2b904]
_IID_IDirect3DVertexBuffer7;

// address=[0x3b2b918]
_GUID_DMUS_PROP_GS_Hardware;

// address=[0x3b2b92c]
_IID_IDirectPlay8Address;

// address=[0x3b2b940]
_IID_IDirectPlay8AddressIP;

// address=[0x3b2b954]
_GUID_DMUS_PROP_XG_Hardware;

// address=[0x3b2b968]
_GUID_DMUS_PROP_XG_Capable;

// address=[0x3b2b97c]
_GUID_DMUS_PROP_GS_Capable;

// address=[0x3b2b990]
_GUID_DMUS_PROP_DLS1;

// address=[0x3b2b9a4]
_GUID_DMUS_PROP_DLS2;

// address=[0x3b2b9b8]
_GUID_DMUS_PROP_INSTRUMENT2;

// address=[0x3b2b9cc]
_IID_IDirectSoundFXGargle;

// address=[0x3b2b9e0]
_GUID_DMUS_PROP_SynthSink_DSOUND;

// address=[0x3b2b9f4]
_GUID_DMUS_PROP_SynthSink_WAVE;

// address=[0x3b2ba08]
_GUID_DMUS_PROP_SampleMemorySize;

// address=[0x3b2ba1c]
_GUID_DMUS_PROP_SamplePlaybackRate;

// address=[0x3b2ba30]
_GUID_DMUS_PROP_WriteLatency;

// address=[0x3b2ba44]
_GUID_DMUS_PROP_WritePeriod;

// address=[0x3b2ba58]
_GUID_DMUS_PROP_MemorySize;

// address=[0x3b2ba6c]
_GUID_DMUS_PROP_WavesReverb;

// address=[0x3b2ba80]
_GUID_DMUS_PROP_Effects;

// address=[0x3b2ba94]
_GUID_DMUS_PROP_LegacyCaps;

// address=[0x3b2baa8]
_GUID_DMUS_PROP_Volume;

// address=[0x3b2babc]
_CLSID_CDirectXFile;

// address=[0x3b2bad0]
_IID_IDirectXFile;

// address=[0x3b2bae4]
_IID_IDirectXFileEnumObject;

// address=[0x3b2baf8]
_IID_IDirectXFileSaveObject;

// address=[0x3b2bb0c]
_IID_IDirectXFileObject;

// address=[0x3b2bb20]
_IID_IDirectXFileData;

// address=[0x3b2bb34]
_IID_IDirectXFileDataReference;

// address=[0x3b2bb48]
_IID_IDirectXFileBinary;

// address=[0x3b2bb5c]
_TID_DXFILEHeader;

// address=[0x3b2bb70]
_CLSID_DirectInput;

// address=[0x3b2bb84]
_IID_IDirectSoundFXChorus;

// address=[0x3b2bb98]
_CLSID_DirectInputDevice;

// address=[0x3b2bbac]
_CLSID_DirectInput8;

// address=[0x3b2bbc0]
_CLSID_DirectInputDevice8;

// address=[0x3b2bbd4]
_IID_IDirectInputA;

// address=[0x3b2bbe8]
_IID_IDirectInputW;

// address=[0x3b2bbfc]
_IID_IDirectInput2A;

// address=[0x3b2bc10]
_IID_IDirectInput2W;

// address=[0x3b2bc24]
_IID_IDirectInput7A;

// address=[0x3b2bc38]
_IID_IDirectInput7W;

// address=[0x3b2bc4c]
_IID_IDirectInput8A;

// address=[0x3b2bc60]
_IID_IDirectInput8W;

// address=[0x3b2bc74]
_IID_IDirectInputDeviceA;

// address=[0x3b2bc88]
_IID_IDirectInputDeviceW;

// address=[0x3b2bc9c]
_IID_IDirectInputDevice2A;

// address=[0x3b2bcb0]
_IID_IDirectInputDevice2W;

// address=[0x3b2bcc4]
_IID_IDirectInputDevice7A;

// address=[0x3b2bcd8]
_IID_IDirectInputDevice7W;

// address=[0x3b2bcec]
_IID_IDirectInputDevice8A;

// address=[0x3b2bd00]
_IID_IDirectInputDevice8W;

// address=[0x3b2bd14]
_IID_IDirectInputEffect;

// address=[0x3b2bd28]
_GUID_XAxis;

// address=[0x3b2bd3c]
_GUID_YAxis;

// address=[0x3b2bd50]
_GUID_ZAxis;

// address=[0x3b2bd64]
_GUID_RxAxis;

// address=[0x3b2bd78]
_GUID_RyAxis;

// address=[0x3b2bd8c]
_GUID_RzAxis;

// address=[0x3b2bda0]
_IID_IDirectInputEffectDriver;

// address=[0x3b2bdb4]
_IID_IDirectInputJoyConfig;

// address=[0x3b2bdc8]
_GUID_Slider;

// address=[0x3b2bddc]
_GUID_Button;

// address=[0x3b2bdf0]
_IID_IDirectInputPIDDriver;

// address=[0x3b2be04]
_GUID_Key;

// address=[0x3b2be18]
_IID_IDirectInputJoyConfig8;

// address=[0x3b2be2c]
_GUID_POV;

// address=[0x3b2be40]
_GUID_Unknown;

// address=[0x3b2be54]
_GUID_SysMouse;

// address=[0x3b2be68]
_GUID_SysKeyboard;

// address=[0x3b2be7c]
_GUID_Joystick;

// address=[0x3b2be90]
_GUID_SysMouseEm;

// address=[0x3b2bea4]
_GUID_SysMouseEm2;

// address=[0x3b2beb8]
_GUID_SysKeyboardEm;

// address=[0x3b2becc]
_IID_IDirectSoundFXFlanger;

// address=[0x3b2bee0]
_GUID_SysKeyboardEm2;

// address=[0x3b2bef4]
_GUID_ConstantForce;

// address=[0x3b2bf08]
_GUID_RampForce;

// address=[0x3b2bf1c]
_GUID_Square;

// address=[0x3b2bf30]
_GUID_Sine;

// address=[0x3b2bf44]
_GUID_Triangle;

// address=[0x3b2bf58]
_GUID_SawtoothUp;

// address=[0x3b2bf6c]
_GUID_SawtoothDown;

// address=[0x3b2bf80]
_GUID_Spring;

// address=[0x3b2bf94]
_GUID_Damper;

// address=[0x3b2bfa8]
_GUID_Inertia;

// address=[0x3b2bfbc]
_IID_IKsControl;

// address=[0x3b2bfd0]
_GUID_Friction;

// address=[0x3b2bfe4]
_KSDATAFORMAT_SUBTYPE_MIDI;

// address=[0x3b2bff8]
_GUID_CustomForce;

// address=[0x3b2c00c]
_KSDATAFORMAT_SUBTYPE_DIRECTMUSIC;

// address=[0x3b2c020]
_CLSID_DirectSound;

// address=[0x3b2c034]
_CLSID_DirectSound8;

// address=[0x3b2c048]
_CLSID_DirectSoundCapture;

// address=[0x3b2c05c]
_CLSID_DirectSoundCapture8;

// address=[0x3b2c070]
_CLSID_DirectSoundFullDuplex;

// address=[0x3b2c084]
_DSDEVID_DefaultPlayback;

// address=[0x3b2c098]
_DSDEVID_DefaultCapture;

// address=[0x3b2c0ac]
_DSDEVID_DefaultVoicePlayback;

// address=[0x3b2c0c0]
_DSDEVID_DefaultVoiceCapture;

// address=[0x3b2c0d4]
_IID_IDirectSoundFXEcho;

// address=[0x3b2c0e8]
_CLSID_DirectPlay8Client;

// address=[0x3b2c0fc]
_CLSID_DirectPlay8Server;

// address=[0x3b2c110]
_CLSID_DirectPlay8Peer;

// address=[0x3b2c124]
_CLSID_DirectPlay8ThreadPool;

// address=[0x3b2c138]
_CLSID_DirectPlay8NATResolver;

// address=[0x3b2c14c]
_IID_IDirectPlay8Client;

// address=[0x3b2c160]
_IID_IDirectPlay8Server;

// address=[0x3b2c174]
_IID_IDirectPlay8Peer;

// address=[0x3b2c188]
_IID_IDirectPlay8ThreadPool;

// address=[0x3b2c19c]
_IID_IDirectPlay8NATResolver;

// address=[0x3b2c1b0]
_CLSID_DP8SP_IPX;

// address=[0x3b2c1c4]
_CLSID_DP8SP_MODEM;

// address=[0x3b2c1d8]
_CLSID_DP8SP_SERIAL;

// address=[0x3b2c1ec]
_CLSID_DP8SP_TCPIP;

// address=[0x3b2c200]
_CLSID_DP8SP_BLUETOOTH;

// address=[0x3b2c214]
_CLSID_DirectPlay8LobbiedApplication;

// address=[0x3b2c228]
_CLSID_DirectPlay8LobbyClient;

// address=[0x3b2c23c]
_IID_IDirectPlay8LobbiedApplication;

// address=[0x3b2c250]
_IID_IDirectPlay8LobbyClient;

// address=[0x3b2c264]
_IID_IDirectSoundFXDistortion;

// address=[0x3b2c278]
_IID_IDirectSoundFXCompressor;

// address=[0x3b2c28c]
_IID_IDirectSoundFXParamEq;

// address=[0x3b2c2a0]
_IID_IDirectPlay2;

// address=[0x3b2c2b4]
_IID_IDirectPlay2A;

// address=[0x3b2c2c8]
_IID_IDirectPlay3;

// address=[0x3b2c2dc]
_IID_IDirectSoundFXI3DL2Reverb;

// address=[0x3b2c2f0]
_IID_IDirectPlay3A;

// address=[0x3b2c304]
_IID_IDirectPlay4;

// address=[0x3b2c318]
_IID_IDirectPlay4A;

// address=[0x3b2c32c]
_CLSID_DirectPlay;

// address=[0x3b2c340]
_DPSPGUID_IPX;

// address=[0x3b2c354]
_DPSPGUID_TCPIP;

// address=[0x3b2c368]
_DPSPGUID_SERIAL;

// address=[0x3b2c37c]
_DPSPGUID_MODEM;

// address=[0x3b2c390]
_IID_IDirectSoundFXWavesReverb;

// address=[0x3b2c3a4]
_IID_IDirectSoundCaptureFXAec;

// address=[0x3b2c3b8]
_IID_IDirectSoundCaptureFXNoiseSuppress;

// address=[0x3b2c3cc]
_CLSID_DxtKey;

// address=[0x3b2c3e0]
_IID_IAMTimelineGroup;

// address=[0x3b2c3f4]
_CODECAPI_AVEncH264SPSID;

// address=[0x3b2c408]
_IID_IMediaControl;

// address=[0x3b2c41c]
_CODECAPI_AVEncVideoOutputColorTransferFunction;

// address=[0x3b2c430]
_CLSID_CaptureGraphBuilder;

// address=[0x3b2c444]
_IID_IAMPushSource;

// address=[0x3b2c458]
_CLSID_SampleGrabber;

// address=[0x3b2c46c]
_IID_IAMVideoDecimationProperties;

// address=[0x3b2c480]
_PIN_CATEGORY_EDS;

// address=[0x3b2c494]
_CLSID_ACMWrapper;

// address=[0x3b2c4a8]
_AM_KSPROPSETID_AC3;

// address=[0x3b2c4bc]
_IID_IVMRFilterConfig9;

// address=[0x3b2c4d0]
_CODECAPI_AVEncMPAEmphasisType;

// address=[0x3b2c4e4]
_AM_KSPROPSETID_DvdSubPic;

// address=[0x3b2c4f8]
_IID_IAMVideoControl;

// address=[0x3b2c50c]
_CODECAPI_AVEncMPVGenerateHeaderSeqExt;

// address=[0x3b2c520]
_IID_IDeferredCommand;

// address=[0x3b2c534]
_CODECAPI_AVEncVideoDisplayDimension;

// address=[0x3b2c548]
_IID_IMixerPinConfig;

// address=[0x3b2c55c]
_CLSID_MJPGEnc;

// address=[0x3b2c570]
_CLSID_MOVReader;

// address=[0x3b2c584]
_MEDIASUBTYPE_None;

// address=[0x3b2c598]
_CODECAPI_AVEncMPAEnableRedundancyProtection;

// address=[0x3b2c5ac]
_IID_IMFVideoPositionMapper;

// address=[0x3b2c5c0]
_CLSID_DirectShowPluginControl;

// address=[0x3b2c5d4]
_CODECAPI_AVEncVideoNoOfFieldsToEncode;

// address=[0x3b2c5e8]
_CAPTION_FORMAT_ATSC;

// address=[0x3b2c5fc]
_CLSID_AMTimelineTrack;

// address=[0x3b2c610]
_CLSID_IVideoEncoderProxy;

// address=[0x3b2c624]
_CODECAPI_AVDecSoftwareDynamicFormatChange;

// address=[0x3b2c638]
_IID_IMediaSeeking;

// address=[0x3b2c64c]
_MEDIASUBTYPE_CPLA;

// address=[0x3b2c660]
_CODECAPI_AVEncDDDCHighPassFilter;

// address=[0x3b2c674]
_CODECAPI_AVEncMPACopyright;

// address=[0x3b2c688]
_AM_KSCATEGORY_CROSSBAR;

// address=[0x3b2c69c]
_MEDIATYPE_DVD_NAVIGATION;

// address=[0x3b2c6b0]
_IID_IMPEG2StreamIdMap;

// address=[0x3b2c6c4]
_CLSID_AMTimelineGroup;

// address=[0x3b2c6d8]
_MEDIASUBTYPE_TVMJ;

// address=[0x3b2c6ec]
_CODECAPI_GUID_AVDecAudioInputDolby;

// address=[0x3b2c700]
_IID_IDxtCompositor;

// address=[0x3b2c714]
_CODECAPI_AVEncAudioMapDestChannel4;

// address=[0x3b2c728]
_CLSID_DVSplitter;

// address=[0x3b2c73c]
_CODECAPI_AVEncStatVideoOutputFrameRate;

// address=[0x3b2c750]
_CODECAPI_AVEncVideoTemporalLayerCount;

// address=[0x3b2c764]
_CLSID_Xml2Dex;

// address=[0x3b2c778]
_IID_IAMMediaStream;

// address=[0x3b2c78c]
_CLSID_AudioInputMixerProperties;

// address=[0x3b2c7a0]
_MEDIASUBTYPE_AnalogVideo_PAL_M;

// address=[0x3b2c7b4]
_MEDIATYPE_DVD_ENCRYPTED_PACK;

// address=[0x3b2c7c8]
_IID_IAMAsyncReaderTimestampScaling;

// address=[0x3b2c7dc]
_IID_IAMLatency;

// address=[0x3b2c7f0]
_CLSID_TextRender;

// address=[0x3b2c804]
_CODECAPI_AVEncMuxOutputStreamType;

// address=[0x3b2c818]
_CODECAPI_AVEncCommonQuality;

// address=[0x3b2c82c]
_PIN_CATEGORY_NABTS;

// address=[0x3b2c840]
_CODECAPI_AVEncAudioMapDestChannel14;

// address=[0x3b2c854]
_DSATTRIB_TRANSPORT_PROPERTIES;

// address=[0x3b2c868]
_IID_IAMClockSlave;

// address=[0x3b2c87c]
_MEDIASUBTYPE_ISDB_CAPTIONS;

// address=[0x3b2c890]
_IID_IDvdControl2;

// address=[0x3b2c8a4]
_CLSID_TVEFilterStatsProperties;

// address=[0x3b2c8b8]
_MR_BUFFER_SERVICE;

// address=[0x3b2c8cc]
_MEDIASUBTYPE_TIF_SI;

// address=[0x3b2c8e0]
_CAPTION_FORMAT_DIRECTV;

// address=[0x3b2c8f4]
_IID_IAMMultiMediaStream;

// address=[0x3b2c908]
_CLSID_PerformanceProperties;

// address=[0x3b2c91c]
_MEDIASUBTYPE_A2B10G10R10;

// address=[0x3b2c930]
_CODECAPI_AVEncStatWMVDecoderComplexityProfile;

// address=[0x3b2c944]
_IID_IAMTVTuner;

// address=[0x3b2c958]
_MR_VIDEO_ACCELERATION_SERVICE;

// address=[0x3b2c96c]
_CODECAPI_AVEncStatAudioPeakPCMValue;

// address=[0x3b2c980]
_CODECAPI_AVEncDDDialogNormalization;

// address=[0x3b2c994]
_CLSID_URLReader;

// address=[0x3b2c9a8]
_IID_IBasicAudio;

// address=[0x3b2c9bc]
_FORMAT_CC_CONTAINER;

// address=[0x3b2c9d0]
_CLSID_AudioInputDeviceCategory;

// address=[0x3b2c9e4]
_IID_IMFVideoProcessor;

// address=[0x3b2c9f8]
_MEDIASUBTYPE_MPEG1System;

// address=[0x3b2ca0c]
_CODECAPI_AVDecVideoCodecType;

// address=[0x3b2ca20]
_IID_IMediaPosition;

// address=[0x3b2ca34]
_CLSID_MPEG1Doc;

// address=[0x3b2ca48]
_CODECAPI_AVEncVideoHeaderSeconds;

// address=[0x3b2ca5c]
_CODECAPI_AVEncAdaptiveMode;

// address=[0x3b2ca70]
_CLSID_MMSPLITTER;

// address=[0x3b2ca84]
_CLSID_InfTee;

// address=[0x3b2ca98]
_MEDIATYPE_DTVCCData;

// address=[0x3b2caac]
_CODECAPI_AVEncMP12MuxSysCSPS;

// address=[0x3b2cac0]
_MEDIASUBTYPE_ARGB32_D3D_DX7_RT;

// address=[0x3b2cad4]
_CLSID_DxtJpeg;

// address=[0x3b2cae8]
_MEDIASUBTYPE_IMC3;

// address=[0x3b2cafc]
_MEDIASUBTYPE_P216;

// address=[0x3b2cb10]
_CLSID_ModexProperties;

// address=[0x3b2cb24]
_PIN_CATEGORY_PREVIEW;

// address=[0x3b2cb38]
_CODECAPI_AVEncVideoHeaderMinutes;

// address=[0x3b2cb4c]
_MEDIASUBTYPE_MPEG2_WMDRM_TRANSPORT;

// address=[0x3b2cb60]
_MEDIASUBTYPE_708_608Data;

// address=[0x3b2cb74]
_CODECAPI_AVEncAudioIntervalToSkip;

// address=[0x3b2cb88]
_IID_IMemAllocator;

// address=[0x3b2cb9c]
_IID_IResourceConsumer;

// address=[0x3b2cbb0]
_CODECAPI_AVDecMmcssClass;

// address=[0x3b2cbc4]
_CODECAPI_AVEncAudioMapDestChannel9;

// address=[0x3b2cbd8]
_IID_IAMOverlayFX;

// address=[0x3b2cbec]
_CLSID_VBISurfaces;

// address=[0x3b2cc00]
_MEDIASUBTYPE_DOLBY_AC3_SPDIF;

// address=[0x3b2cc14]
_CLSID_SystemDeviceEnum;

// address=[0x3b2cc28]
_CODECAPI_AVEncMPAOriginalBitstream;

// address=[0x3b2cc3c]
_CAPTION_FORMAT_ECHOSTAR;

// address=[0x3b2cc50]
_CODECAPI_AVDecVideoInputScanType;

// address=[0x3b2cc64]
_CLSID_CDeviceMoniker;

// address=[0x3b2cc78]
_CODECAPI_AVEncSliceControlMode;

// address=[0x3b2cc8c]
_CODECAPI_AVEncMPVProfile;

// address=[0x3b2cca0]
_CLSID_FilterGraph;

// address=[0x3b2ccb4]
_IID_IAsyncReader;

// address=[0x3b2ccc8]
_CLSID_FileWriter;

// address=[0x3b2ccdc]
_MEDIASUBTYPE_Avi;

// address=[0x3b2ccf0]
_IID_IAMDecoderCaps;

// address=[0x3b2cd04]
_IID_IBPCSatelliteTuner;

// address=[0x3b2cd18]
_CODECAPI_AVLowLatencyMode;

// address=[0x3b2cd2c]
_MEDIASUBTYPE_DssVideo;

// address=[0x3b2cd40]
_CLSID_FileSource;

// address=[0x3b2cd54]
_CLSID_DVVideoCodec;

// address=[0x3b2cd68]
_MEDIASUBTYPE_Plum;

// address=[0x3b2cd7c]
_IID_IStreamBuilder;

// address=[0x3b2cd90]
_IID_IEnumPins;

// address=[0x3b2cda4]
_CODECAPI_AVDecVideoAcceleration_MPEG2;

// address=[0x3b2cdb8]
_CLSID_MediaEncoderCategory;

// address=[0x3b2cdcc]
_CODECAPI_AVEncStatAudioAveragePCMValue;

// address=[0x3b2cde0]
_EVRConfig_AllowDropToThrottle;

// address=[0x3b2cdf4]
_CLSID_ProtoFilterGraph;

// address=[0x3b2ce08]
_CODECAPI_AVEncAudioMapDestChannel12;

// address=[0x3b2ce1c]
_CODECAPI_AVEncDDRFPreEmphasisFilter;

// address=[0x3b2ce30]
_AM_KSPROPSETID_TSRateChange;

// address=[0x3b2ce44]
_IID_IQualProp;

// address=[0x3b2ce58]
_CODECAPI_AVEncMP12MuxPacketOverhead;

// address=[0x3b2ce6c]
_CLSID_Line21Decoder;

// address=[0x3b2ce80]
_IID_IMediaEventEx;

// address=[0x3b2ce94]
_IID_IDirectDrawKernel;

// address=[0x3b2cea8]
_CLSID_CWaveOutClassManager;

// address=[0x3b2cebc]
_IID_IVMRDeinterlaceControl9;

// address=[0x3b2ced0]
_CODECAPI_AVEncAudioDualMono;

// address=[0x3b2cee4]
_CLSID_QTDec;

// address=[0x3b2cef8]
_MEDIATYPE_File;

// address=[0x3b2cf0c]
_IID_IMediaStream;

// address=[0x3b2cf20]
_AM_KSCATEGORY_RENDER;

// address=[0x3b2cf34]
_IID_IDVRGB219;

// address=[0x3b2cf48]
_IID_IRegisterServiceProvider;

// address=[0x3b2cf5c]
_AMPROPSETID_Pin;

// address=[0x3b2cf70]
_CLSID_WstDecoderPropertyPage;

// address=[0x3b2cf84]
_IID_IQueueCommand;

// address=[0x3b2cf98]
_IID_IAudioStreamSample;

// address=[0x3b2cfac]
_IID_IDvdState;

// address=[0x3b2cfc0]
_IID_IAMTimelineTransable;

// address=[0x3b2cfd4]
_IID_IMFDesiredSample;

// address=[0x3b2cfe8]
_CODECAPI_AVEncDDSurround90DegreeePhaseShift;

// address=[0x3b2cffc]
_CODECAPI_GUID_AVDecAudioOutputFormat_PCM;

// address=[0x3b2d010]
_MEDIASUBTYPE_P408;

// address=[0x3b2d024]
_CLSID_AMTimelineSrc;

// address=[0x3b2d038]
_CLSID_StreamBufferSink;

// address=[0x3b2d04c]
_IID_IVMRImagePresenter;

// address=[0x3b2d060]
_CLSID_CVidCapClassManager;

// address=[0x3b2d074]
_CLSID_AMTimelineTrans;

// address=[0x3b2d088]
_CLSID_AMTimelineObj;

// address=[0x3b2d09c]
_CODECAPI_AVDecHEAACDynamicRangeControl;

// address=[0x3b2d0b0]
_CLSID_DVBTNetworkProvider;

// address=[0x3b2d0c4]
_MEDIATYPE_Stream;

// address=[0x3b2d0d8]
_CODECAPI_GUID_AVDecAudioInputWMAPro;

// address=[0x3b2d0ec]
_CLSID_CAcmCoClassManager;

// address=[0x3b2d100]
_MEDIASUBTYPE_Line21_BytePair;

// address=[0x3b2d114]
_IID_IVMRMixerBitmap;

// address=[0x3b2d128]
_CODECAPI_AVEncAudioMapDestChannel15;

// address=[0x3b2d13c]
_ENCAPIPARAM_SAP_MODE;

// address=[0x3b2d150]
_CODECAPI_GUID_AVEncWMAVoice;

// address=[0x3b2d164]
_CODECAPI_GUID_AVEncMPEG2Video;

// address=[0x3b2d178]
_CODECAPI_GUID_AVEncCommonFormatHighMAT;

// address=[0x3b2d18c]
_TIME_FORMAT_FIELD;

// address=[0x3b2d1a0]
_CODECAPI_AVEncMPACodingMode;

// address=[0x3b2d1b4]
_CLSID_DVDHWDecodersCategory;

// address=[0x3b2d1c8]
_IID_IConfigInterleaving;

// address=[0x3b2d1dc]
_IID_IVMRMixerControl9;

// address=[0x3b2d1f0]
_MEDIASUBTYPE_A2R10G10B10;

// address=[0x3b2d204]
_PIN_CATEGORY_VIDEOPORT_VBI;

// address=[0x3b2d218]
_CODECAPI_GUID_AVDecAudioInputPCM;

// address=[0x3b2d22c]
_MEDIASUBTYPE_MPEG2_VERSIONED_TABLES;

// address=[0x3b2d240]
_DVDTrace_SkipData_Event;

// address=[0x3b2d254]
_CLSID_DVMuxPropertyPage;

// address=[0x3b2d268]
_CODECAPI_AVEncMP12MuxMuxRate;

// address=[0x3b2d27c]
_CODECAPI_AVEncDDDynamicRangeCompressionControl;

// address=[0x3b2d290]
_IID_IKsPin;

// address=[0x3b2d2a4]
_CLSID_DvdGraphBuilder;

// address=[0x3b2d2b8]
_MEDIASUBTYPE_IYUV;

// address=[0x3b2d2cc]
_MEDIASUBTYPE_MJPG;

// address=[0x3b2d2e0]
_CODECAPI_AVEncVideoFieldSwap;

// address=[0x3b2d2f4]
_CLSID_SystemClock;

// address=[0x3b2d308]
_DVDTrace_DriveIOCTL_Event;

// address=[0x3b2d31c]
_CODECAPI_AVEncVideoEncodeQP;

// address=[0x3b2d330]
_CODECAPI_AVEncVideoNoOfFieldsToSkip;

// address=[0x3b2d344]
_MEDIASUBTYPE_DVD_NAVIGATION_PROVIDER;

// address=[0x3b2d358]
_CODECAPI_AVEncVideoInputChromaResolution;

// address=[0x3b2d36c]
_CODECAPI_GUID_AVDecAudioInputMPEG;

// address=[0x3b2d380]
_CLSID_DVBCNetworkProvider;

// address=[0x3b2d394]
_CLSID_DVDState;

// address=[0x3b2d3a8]
_IID_IGraphConfig;

// address=[0x3b2d3bc]
_DVDTrace_SetLatency_Event;

// address=[0x3b2d3d0]
_IID_IVMRImagePresenter9;

// address=[0x3b2d3e4]
_CODECAPI_ALLSETTINGS;

// address=[0x3b2d3f8]
_IID_IFileSourceFilter;

// address=[0x3b2d40c]
_CLSID_DirectDrawProperties;

// address=[0x3b2d420]
_IID_IAMTimelineTrans;

// address=[0x3b2d434]
_CODECAPI_AVEncMPVLevel;

// address=[0x3b2d448]
_MEDIASUBTYPE_AYUV;

// address=[0x3b2d45c]
_ENCAPIPARAM_BITRATE;

// address=[0x3b2d470]
_MEDIASUBTYPE_AI44;

// address=[0x3b2d484]
_IID_IAMStreamConfig;

// address=[0x3b2d498]
_MEDIASUBTYPE_IMC4;

// address=[0x3b2d4ac]
_IID_IMediaSample;

// address=[0x3b2d4c0]
_MEDIASUBTYPE_AnalogVideo_PAL_N;

// address=[0x3b2d4d4]
_IID_IVideoEncoder;

// address=[0x3b2d4e8]
_TIME_FORMAT_FRAME;

// address=[0x3b2d4fc]
_CLSID_StreamBufferRecordingAttributes;

// address=[0x3b2d510]
_IID_IDirectDrawMediaStream;

// address=[0x3b2d524]
_CODECAPI_GUID_AVEncCommonFormatVCD;

// address=[0x3b2d538]
_IID_IMemInputPin;

// address=[0x3b2d54c]
_CLSID_CQzFilterClassManager;

// address=[0x3b2d560]
_IID_IAMCrossbar;

// address=[0x3b2d574]
_IID_IRegFilterInfo;

// address=[0x3b2d588]
_CODECAPI_GUID_AVEncCommonFormatHighMPV;

// address=[0x3b2d59c]
_MEDIASUBTYPE_VBI;

// address=[0x3b2d5b0]
_MEDIASUBTYPE_YUYV;

// address=[0x3b2d5c4]
_CODECAPI_AVEncMP12MuxSysAudioLock;

// address=[0x3b2d5d8]
_CLSID_TVAudioFilterPropertyPage;

// address=[0x3b2d5ec]
_AM_KSCATEGORY_AUDIO;

// address=[0x3b2d600]
_MEDIASUBTYPE_DVD_NAVIGATION_PCI;

// address=[0x3b2d614]
_CODECAPI_AVEncDDService;

// address=[0x3b2d628]
_AM_KSPROPSETID_MPEG4_MediaType_Attributes;

// address=[0x3b2d63c]
_FORMAT_MPEGVideo;

// address=[0x3b2d650]
_CODECAPI_AVEncMPVGOPSInSeq;

// address=[0x3b2d664]
_CODECAPI_AVEncVideoROIEnabled;

// address=[0x3b2d678]
_MEDIASUBTYPE_MPEG2_TRANSPORT_STRIDE;

// address=[0x3b2d68c]
_CODECAPI_AVEncAudioMapDestChannel11;

// address=[0x3b2d6a0]
_CLSID_Colour;

// address=[0x3b2d6b4]
_IID_IOverlay;

// address=[0x3b2d6dc]
_CODECAPI_AVDecVideoAcceleration_VC1;

// address=[0x3b2d6f0]
_DVDTrace_APCheck_Event;

// address=[0x3b2d704]
_CODECAPI_GUID_AVEncMPEG1Video;

// address=[0x3b2d718]
_MEDIASUBTYPE_RGB8;

// address=[0x3b2d72c]
_IID_IVPNotify2;

// address=[0x3b2d740]
_CODECAPI_AVEncVideoInputColorPrimaries;

// address=[0x3b2d754]
_IID_IMFVideoRenderer;

// address=[0x3b2d768]
_DVDTrace_CompleteIO_Event;

// address=[0x3b2d77c]
_CODECAPI_AVEncCommonRateControlMode;

// address=[0x3b2d790]
_IID_IAMSetErrorLog;

// address=[0x3b2d7a4]
_IID_IResourceManager;

// address=[0x3b2d7b8]
_CODECAPI_AVEncStatWMVCBMax;

// address=[0x3b2d7cc]
_EVRConfig_AllowScaling;

// address=[0x3b2d7e0]
_MR_VIDEO_MIXER_SERVICE;

// address=[0x3b2d7f4]
_MEDIASUBTYPE_IJPG;

// address=[0x3b2d808]
_MEDIASUBTYPE_RGB32;

// address=[0x3b2d81c]
_IID_IPinConnection;

// address=[0x3b2d830]
_IID_IAMTimelineEffect;

// address=[0x3b2d844]
_CODECAPI_AVEncCommonMinBitRate;

// address=[0x3b2d858]
_FORMAT_CAPTIONED_H264VIDEO;

// address=[0x3b2d86c]
_MEDIASUBTYPE_MPEG1AudioPayload;

// address=[0x3b2d880]
_CODECAPI_AVEncMPVGenerateHeaderPicExt;

// address=[0x3b2d894]
_CLSID_DVDecPropertiesPage;

// address=[0x3b2d8a8]
_CODECAPI_AVEncCommonMeanBitRateInterval;

// address=[0x3b2d8bc]
_CODECAPI_AVEncAudioMapDestChannel1;

// address=[0x3b2d8d0]
_CODECAPI_GUID_AVDecAudioOutputFormat_SPDIF_PCM;

// address=[0x3b2d8e4]
_MEDIASUBTYPE_MPEG1Payload;

// address=[0x3b2d8f8]
_CLSID_StreamBufferComposeRecording;

// address=[0x3b2d90c]
_CODECAPI_AVEncAudioMapDestChannel13;

// address=[0x3b2d920]
_EVRConfig_AllowDropToHalfInterlace;

// address=[0x3b2d934]
_CLSID_QuickTimeParser;

// address=[0x3b2d948]
_CLSID_AVIMIDIRender;

// address=[0x3b2d95c]
_CLSID_CWaveinClassManager;

// address=[0x3b2d970]
_IID_IMediaStreamFilter;

// address=[0x3b2d984]
_IID_IGraphConfigCallback;

// address=[0x3b2d998]
_MEDIATYPE_ScriptCommand;

// address=[0x3b2d9ac]
_IID_IRenderEngine2;

// address=[0x3b2d9c0]
_IID_IDVSplitter;

// address=[0x3b2d9d4]
_CODECAPI_AVEncMPVAddSeqEndCode;

// address=[0x3b2d9e8]
_CLSID_SBE2Sink;

// address=[0x3b2d9fc]
_IID_IVMRSurfaceAllocatorNotify;

// address=[0x3b2da10]
_CODECAPI_AVEncMPVGenerateHeaderSeqScaleExt;

// address=[0x3b2da24]
_CODECAPI_AVEncVideoMeanAbsoluteDifference;

// address=[0x3b2da38]
_MEDIASUBTYPE_RGB16_D3D_DX9_RT;

// address=[0x3b2da4c]
_CODECAPI_AVEncStatCommonCompletedPasses;

// address=[0x3b2da60]
_CLSID_FGControl;

// address=[0x3b2da74]
_MEDIASUBTYPE_AnalogVideo_SECAM_D;

// address=[0x3b2da88]
_CODECAPI_SETALLDEFAULTS;

// address=[0x3b2da9c]
_IID_IIPDVDec;

// address=[0x3b2dab0]
_CLSID_AudioCompressorCategory;

// address=[0x3b2dac4]
_CODECAPI_AVEncVideoEncodeOffsetOrigin;

// address=[0x3b2dad8]
_CODECAPI_AVDecVideoAcceleration_H264;

// address=[0x3b2daec]
_CLSID_FilgraphManager;

// address=[0x3b2db00]
_CODECAPI_AVEncStatVideoCodedFrames;

// address=[0x3b2db14]
_MEDIASUBTYPE_DVD_SUBPICTURE;

// address=[0x3b2db28]
_CLSID_CaptureProperties;

// address=[0x3b2db3c]
_CODECAPI_AVEncVideoSourceIsBW;

// address=[0x3b2db50]
_IID_IVMRMonitorConfig9;

// address=[0x3b2db64]
_CODECAPI_AVEncCommonLowLatency;

// address=[0x3b2db78]
_CODECAPI_AVDecVideoImageSize;

// address=[0x3b2db8c]
_DSATTRIB_SAMPLE_LIVE_STREAM_TIME;

// address=[0x3b2dba0]
_CLSID_ATSCNetworkPropertyPage;

// address=[0x3b2dbb4]
_IID_IVPConfig;

// address=[0x3b2dbc8]
_IID_IVideoFrameStep;

// address=[0x3b2dbdc]
_CODECAPI_AVEncVideoHeaderFrames;

// address=[0x3b2dbf0]
_CLSID_DVDNavigator;

// address=[0x3b2dc04]
_IID_IDvdCmd;

// address=[0x3b2dc18]
_CODECAPI_GUID_AVEncCommonFormatUnSpecified;

// address=[0x3b2dc2c]
_IID_IAMMediaTypeSample;

// address=[0x3b2dc40]
_IID_IDvdInfo2;

// address=[0x3b2dc54]
_IID_IMFVideoDisplayControl;

// address=[0x3b2dc68]
_IID_IFileSinkFilter2;

// address=[0x3b2dc7c]
_PIN_CATEGORY_VBI;

// address=[0x3b2dc90]
_CLSID_AVIDoc;

// address=[0x3b2dca4]
_IID_IAMTVAudioNotification;

// address=[0x3b2dcb8]
_IID_IFilterMapper2;

// address=[0x3b2dccc]
_EVRConfig_ForceBob;

// address=[0x3b2dce0]
_IID_IStreamSample;

// address=[0x3b2dcf4]
_DSATTRIB_CC_CONTAINER_INFO;

// address=[0x3b2dd08]
_IID_IAMAnalogVideoEncoder;

// address=[0x3b2dd1c]
_CODECAPI_AVEncMP12PktzSTDBuffer;

// address=[0x3b2dd30]
_CODECAPI_GUID_AVEncDolbyDigitalPro;

// address=[0x3b2dd44]
_IID_IKsInterfaceHandler;

// address=[0x3b2dd58]
_MEDIASUBTYPE_QTRpza;

// address=[0x3b2dd6c]
_CLSID_VPVBIObject;

// address=[0x3b2dd80]
_CLSID_MediaLocator;

// address=[0x3b2dd94]
_CODECAPI_AVEncMPVFrameFieldMode;

// address=[0x3b2dda8]
_CODECAPI_AVDecVideoDropPicWithMissingRef;

// address=[0x3b2ddbc]
_IID_IFullScreenVideo;

// address=[0x3b2ddd0]
_AM_KSCATEGORY_SPLITTER;

// address=[0x3b2dde4]
_IID_IVPManager;

// address=[0x3b2ddf8]
_IID_IAMTimelineSrc;

// address=[0x3b2de0c]
_IID_IAMVideoAccelerator;

// address=[0x3b2de20]
_MEDIASUBTYPE_ARGB4444;

// address=[0x3b2de34]
_IID_IMediaEvent;

// address=[0x3b2de48]
_IID_ISeekingPassThru;

// address=[0x3b2de70]
_CODECAPI_AVDecCommonMeanBitRate;

// address=[0x3b2de84]
_MEDIASUBTYPE_WAKE;

// address=[0x3b2de98]
_IID_IFileSinkFilter;

// address=[0x3b2deac]
_CODECAPI_AVEncVideoMaxKeyframeDistance;

// address=[0x3b2dec0]
_CODECAPI_AVDecVideoFastDecodeMode;

// address=[0x3b2ded4]
_CODECAPI_AVEncVideoEncodeDimension;

// address=[0x3b2dee8]
_MEDIATYPE_Video;

// address=[0x3b2defc]
_CLSID_DVVideoEnc;

// address=[0x3b2df10]
_IID_IMemAllocatorNotifyCallbackTemp;

// address=[0x3b2df24]
_IID_IAMTimecodeGenerator;

// address=[0x3b2df38]
_MEDIASUBTYPE_RGB4;

// address=[0x3b2df4c]
_CODECAPI_AVEncMP12MuxPackSize;

// address=[0x3b2df60]
_CODECAPI_AVEncAudioMapDestChannel6;

// address=[0x3b2df74]
_CODECAPI_AVEncDDLtRtSurroundMixLvl_x10;

// address=[0x3b2df88]
_FORMAT_VideoInfo2;

// address=[0x3b2df9c]
_MEDIATYPE_Audio;

// address=[0x3b2dfb0]
_IID_IEVRTrustedVideoPlugin;

// address=[0x3b2dfc4]
_IID_IVMRImageCompositor;

// address=[0x3b2dfd8]
_CODECAPI_GUID_AVDecAudioInputDTS;

// address=[0x3b2dfec]
_DSATTRIB_PicSampleSeq;

// address=[0x3b2e000]
_CLSID_Line21Decoder2;

// address=[0x3b2e014]
_MEDIASUBTYPE_IA44;

// address=[0x3b2e028]
_CLSID_CMidiOutClassManager;

// address=[0x3b2e03c]
_MEDIASUBTYPE_DVB_SUBTITLES;

// address=[0x3b2e050]
_IID_IEncoderAPI;

// address=[0x3b2e064]
_IID_IMultiMediaStream;

// address=[0x3b2e078]
_MEDIASUBTYPE_RGB32_D3D_DX9_RT;

// address=[0x3b2e08c]
_VIDEO_ZOOM_RECT;

// address=[0x3b2e0a0]
_CODECAPI_AVEncMP12MuxSysRateBound;

// address=[0x3b2e0b4]
_IID_IMpegAudioDecoder;

// address=[0x3b2e0c8]
_IID_IAMTimelineTrack;

// address=[0x3b2e0dc]
_CODECAPI_AVEncVideoOutputColorNominalRange;

// address=[0x3b2e0f0]
_IID_IVMRSurfaceAllocatorEx9;

// address=[0x3b2e104]
_MEDIASUBTYPE_MPEG2_UDCR_TRANSPORT;

// address=[0x3b2e118]
_MEDIASUBTYPE_S342;

// address=[0x3b2e12c]
_DVDTrace_Cache_Event;

// address=[0x3b2e140]
_CODECAPI_AVEncMPVGenerateHeaderPicDispExt;

// address=[0x3b2e154]
_DSATTRIB_PBDATAG_ATTRIBUTE;

// address=[0x3b2e168]
_CLSID_VideoMixingRenderer9;

// address=[0x3b2e17c]
_CLSID_MPEG2Demultiplexer;

// address=[0x3b2e190]
_DVDTrace_PendIO_Event;

// address=[0x3b2e1a4]
_CLSID_LegacyAmFilterCategory;

// address=[0x3b2e1b8]
_CLSID_FilterMapper;

// address=[0x3b2e1cc]
_IID_IAMFilterMiscFlags;

// address=[0x3b2e1e0]
_IID_IKsPinFactory;

// address=[0x3b2e1f4]
_IID_IAMDevMemoryControl;

// address=[0x3b2e208]
_CODECAPI_AVEncVideoOutputChromaSubsampling;

// address=[0x3b2e21c]
_CODECAPI_GUID_AVEncMPEG2Audio;

// address=[0x3b2e230]
_FORMAT_DVD_LPCMAudio;

// address=[0x3b2e244]
_MEDIATYPE_MPEG2_SECTIONS;

// address=[0x3b2e258]
_MEDIATYPE_URL_STREAM;

// address=[0x3b2e26c]
_MEDIASUBTYPE_ARGB4444_D3D_DX7_RT;

// address=[0x3b2e280]
_CLSID_CameraControlPropertyPage;

// address=[0x3b2e294]
_CODECAPI_AVEncAudioMapDestChannel8;

// address=[0x3b2e2a8]
_CODECAPI_AVEncVideoInputColorTransferFunction;

// address=[0x3b2e2bc]
_EVRConfig_ForceHalfInterlace;

// address=[0x3b2e2d0]
_AM_KSPROPSETID_CopyProt;

// address=[0x3b2e2e4]
_MEDIASUBTYPE_QTMovie;

// address=[0x3b2e2f8]
_CLSID_CIcmCoClassManager;

// address=[0x3b2e30c]
_CLSID_AVICo;

// address=[0x3b2e320]
_CODECAPI_AVDecAudioDualMono;

// address=[0x3b2e334]
_AM_KSPROPSETID_FrameStep;

// address=[0x3b2e348]
_IID_IGraphVersion;

// address=[0x3b2e35c]
_CODECAPI_AVDSPSpeakerFill;

// address=[0x3b2e370]
_CODECAPI_AVEncInputVideoSystem;

// address=[0x3b2e384]
_CODECAPI_AVEncMPVQuantMatrixChromaNonIntra;

// address=[0x3b2e398]
_CODECAPI_AVEncVideoOutputFrameRate;

// address=[0x3b2e3ac]
_CLSID_OverlayMixer;

// address=[0x3b2e3c0]
_CODECAPI_AVEncDDHeadphoneMode;

// address=[0x3b2e3d4]
_IID_IQualityControl;

// address=[0x3b2e3e8]
_IID_ISampleGrabber;

// address=[0x3b2e3fc]
_AM_INTERFACESETID_Standard;

// address=[0x3b2e410]
_MEDIASUBTYPE_DTS;

// address=[0x3b2e424]
_CLSID_CMpegAudioCodec;

// address=[0x3b2e438]
_CODECAPI_AVEncAudioMapDestChannel3;

// address=[0x3b2e44c]
_AM_KSPROPSETID_DVD_RateChange;

// address=[0x3b2e460]
_MEDIASUBTYPE_S340;

// address=[0x3b2e474]
_CODECAPI_AVEncMPVIntraDCPrecision;

// address=[0x3b2e488]
_CODECAPI_AVEncAudioMapDestChannel10;

// address=[0x3b2e49c]
_MEDIASUBTYPE_MPEG1VideoCD;

// address=[0x3b2e4b0]
_UUID_WMDRMTagTables;

// address=[0x3b2e4c4]
_CLSID_CaptureGraphBuilder2;

// address=[0x3b2e4d8]
_CODECAPI_AVEncDDChannelBWLowPassFilter;

// address=[0x3b2e4ec]
_CODECAPI_AVEncMPVSceneDetection;

// address=[0x3b2e500]
_CODECAPI_AVEncMP12MuxSysVideoLock;

// address=[0x3b2e514]
_MEDIASUBTYPE_AnalogVideo_PAL_B;

// address=[0x3b2e528]
_IID_IVMRSurfaceAllocator;

// address=[0x3b2e53c]
_IID_IAMStreamControl;

// address=[0x3b2e550]
_CODECAPI_AVEncVideoLTRBufferControl;

// address=[0x3b2e564]
_CLSID_StreamBufferConfig;

// address=[0x3b2e578]
_CODECAPI_GUID_AVEncWMALossless;

// address=[0x3b2e58c]
_CODECAPI_AVEncVideoSupportedControls;

// address=[0x3b2e5a0]
_IID_IVMRVideoStreamControl;

// address=[0x3b2e5b4]
_FORMAT_None;

// address=[0x3b2e5c8]
_MEDIASUBTYPE_Y211;

// address=[0x3b2e5dc]
_CODECAPI_AVEncMP12MuxNumStreams;

// address=[0x3b2e5f0]
_CLSID_AudioRendererAdvancedProperties;

// address=[0x3b2e604]
_IID_IAMWstDecoder;

// address=[0x3b2e618]
_CLSID_VideoPortManager;

// address=[0x3b2e62c]
_MEDIASUBTYPE_AnalogVideo_PAL_D;

// address=[0x3b2e640]
_CODECAPI_AVEncDDSurroundExMode;

// address=[0x3b2e654]
_CODECAPI_GUID_AVDecAudioInputWMA;

// address=[0x3b2e668]
_CODECAPI_GUID_AVEndMPEG4Video;

// address=[0x3b2e67c]
_DSATTRIB_CAPTURE_STREAMTIME;

// address=[0x3b2e690]
_FORMAT_MPEGStreams;

// address=[0x3b2e6a4]
_MEDIASUBTYPE_VPS;

// address=[0x3b2e6b8]
_DVDTrace_KeyExchange_Event;

// address=[0x3b2e6cc]
_IID_IRenderEngine;

// address=[0x3b2e6e0]
_CODECAPI_AVEncVideoForceKeyFrame;

// address=[0x3b2e6f4]
_MEDIASUBTYPE_DssAudio;

// address=[0x3b2e708]
_MEDIASUBTYPE_RAW_SPORT;

// address=[0x3b2e71c]
_CODECAPI_AVEncVideoCodedVideoAccessUnitSize;

// address=[0x3b2e730]
_CODECAPI_AVEncVideoOutputColorTransferMatrix;

// address=[0x3b2e744]
_CODECAPI_GUID_AVEncWMV;

// address=[0x3b2e758]
_IID_IEnumFilters;

// address=[0x3b2e76c]
_CODECAPI_GUID_AVEncCommonFormatATSC;

// address=[0x3b2e780]
_CODECAPI_AVEncAudioMeanBitRate;

// address=[0x3b2e794]
_CODECAPI_AVEncCommonPassEnd;

// address=[0x3b2e7a8]
_MEDIASUBTYPE_420O;

// address=[0x3b2e7bc]
_IID_IAMDeviceRemoval;

// address=[0x3b2e7d0]
_MEDIASUBTYPE_Overlay;

// address=[0x3b2e7e4]
_MEDIASUBTYPE_YV12;

// address=[0x3b2e7f8]
_CODECAPI_AVEncMP12MuxTargetPacketizer;

// address=[0x3b2e80c]
_CODECAPI_AVEncStatWMVCBAvg;

// address=[0x3b2e820]
_TIME_FORMAT_NONE;

// address=[0x3b2e834]
_AM_KSCATEGORY_VIDEO;

// address=[0x3b2e848]
_CLSID_MidiRendererCategory;

// address=[0x3b2e85c]
_IID_IDirectDrawStreamSample;

// address=[0x3b2e870]
_CLSID_TransmitCategory;

// address=[0x3b2e884]
_MEDIASUBTYPE_NV24;

// address=[0x3b2e898]
_CODECAPI_AVEncDDDigitalDeemphasis;

// address=[0x3b2e8ac]
_IID_IDxtAlphaSetter;

// address=[0x3b2e8c0]
_MEDIASUBTYPE_TELETEXT;

// address=[0x3b2e8d4]
_IID_ICaptureGraphBuilder2;

// address=[0x3b2e8e8]
_CLSID_ColorSource;

// address=[0x3b2e8fc]
_CODECAPI_AVEncH264PPSID;

// address=[0x3b2e910]
_IID_IEnumStreamIdMap;

// address=[0x3b2e924]
_MEDIASUBTYPE_MPEG2_PBDA_TRANSPORT_RAW;

// address=[0x3b2e938]
_CODECAPI_AVEncMPVQuantMatrixChromaIntra;

// address=[0x3b2e94c]
_IID_IGrfCache;

// address=[0x3b2e960]
_FORMAT_DvInfo;

// address=[0x3b2e974]
_IID_IVMRAspectRatioControl;

// address=[0x3b2e988]
_CODECAPI_AVEncMPVUseConcealmentMotionVectors;

// address=[0x3b2e99c]
_MEDIASUBTYPE_NV11;

// address=[0x3b2e9b0]
_CODECAPI_SUPPORTSEVENTS;

// address=[0x3b2e9c4]
_MEDIASUBTYPE_MDVF;

// address=[0x3b2e9d8]
_IID_IMemAllocatorCallbackTemp;

// address=[0x3b2e9ec]
_MEDIATYPE_LMRT;

// address=[0x3b2ea00]
_MEDIATYPE_Text;

// address=[0x3b2ea14]
_CLSID_VideoInputDeviceCategory;

// address=[0x3b2ea28]
_CODECAPI_AVEncDDPreferredStereoDownMixMode;

// address=[0x3b2ea3c]
_MEDIASUBTYPE_MPEG2_AUDIO;

// address=[0x3b2ea50]
_DVDTrace_SendSampleLate_Event;

// address=[0x3b2ea64]
_IID_IAMTVAudio;

// address=[0x3b2ea78]
_IID_IAMCollection;

// address=[0x3b2ea8c]
_CODECAPI_AVEncDDSurroundDownMixLevel;

// address=[0x3b2eaa0]
_CLSID_VideoStreamConfigPropertyPage;

// address=[0x3b2eab4]
_IID_IMixerPinConfig2;

// address=[0x3b2eac8]
_FORMAT_MPEG2Audio;

// address=[0x3b2eadc]
_IID_IVMRMixerControl;

// address=[0x3b2eaf0]
_IID_IFilterGraph2;

// address=[0x3b2eb04]
_CODECAPI_AVEncVideoOutputChromaResolution;

// address=[0x3b2eb18]
_CLSID_AudMixer;

// address=[0x3b2eb2c]
_IID_IDirectDrawMediaSample;

// address=[0x3b2eb40]
_MR_VIDEO_RENDER_SERVICE;

// address=[0x3b2eb54]
_MEDIASUBTYPE_dvsd;

// address=[0x3b2eb68]
_IID_IAMStats;

// address=[0x3b2eb7c]
_EVRConfig_AllowDropToBob;

// address=[0x3b2eb90]
_CLSID_AviDest;

// address=[0x3b2eba4]
_IID_IAMTimelineSplittable;

// address=[0x3b2ebb8]
_CODECAPI_AVDecVideoMaxCodedHeight;

// address=[0x3b2ebcc]
_MEDIASUBTYPE_P208;

// address=[0x3b2ebe0]
_EVRConfig_ForceBatching;

// address=[0x3b2ebf4]
_AM_KSCATEGORY_TVAUDIO;

// address=[0x3b2ec08]
_MEDIASUBTYPE_SPDIF_TAG_241h;

// address=[0x3b2ec1c]
_CODECAPI_AVEncMP12PktzCopyright;

// address=[0x3b2ec30]
_IID_IEVRFilterConfig;

// address=[0x3b2ec44]
_CODECAPI_GUID_AVDecAudioInputHEAAC;

// address=[0x3b2ec58]
_CODECAPI_AVEncVideoSourceFilmContent;

// address=[0x3b2ec6c]
_PIN_CATEGORY_ANALOGVIDEOIN;

// address=[0x3b2ec80]
_MEDIATYPE_Midi;

// address=[0x3b2ec94]
_MEDIASUBTYPE_ISDB_SUPERIMPOSE;

// address=[0x3b2eca8]
_CLSID_SeekingPassThru;

// address=[0x3b2ecbc]
_CLSID_AudioProperties;

// address=[0x3b2ecd0]
_CODECAPI_AVAudioChannelConfig;

// address=[0x3b2ece4]
_CODECAPI_AVEncVideoCBRMotionTradeoff;

// address=[0x3b2ecf8]
_CODECAPI_AVDecVideoMaxCodedWidth;

// address=[0x3b2ed0c]
_CODECAPI_AVAudioSampleRate;

// address=[0x3b2ed20]
_CODECAPI_AVEncVideoOutputColorLighting;

// address=[0x3b2ed34]
_IID_IMFVideoDeviceID;

// address=[0x3b2ed48]
_CODECAPI_AVEncStatAverageBPS;

// address=[0x3b2ed5c]
_AM_KSCATEGORY_VBICODEC;

// address=[0x3b2ed70]
_MEDIASUBTYPE_IMC1;

// address=[0x3b2ed84]
_IID_IDecimateVideoImage;

// address=[0x3b2ed98]
_IID_IPropertySetter;

// address=[0x3b2edac]
_CLSID_AMTimelineEffect;

// address=[0x3b2edc0]
_MEDIASUBTYPE_RGB1;

// address=[0x3b2edd4]
_MEDIASUBTYPE_ARGB1555_D3D_DX9_RT;

// address=[0x3b2ede8]
_CLSID_DShowTVEFilter;

// address=[0x3b2edfc]
_CLSID_DtvCcFilter;

// address=[0x3b2ee10]
_MEDIASUBTYPE_ARGB1555;

// address=[0x3b2ee24]
_IID_ICaptureGraphBuilder;

// address=[0x3b2ee38]
_UUID_UdriTagTables;

// address=[0x3b2ee4c]
_CLSID_CrossbarFilterPropertyPage;

// address=[0x3b2ee60]
_IID_IDxtKey;

// address=[0x3b2ee74]
_IID_IAMTimecodeDisplay;

// address=[0x3b2ee88]
_IID_IAMAudioRendererStats;

// address=[0x3b2ee9c]
_CODECAPI_AVEncDDOriginalBitstream;

// address=[0x3b2eeb0]
_CLSID_AllocPresenter;

// address=[0x3b2eec4]
_IID_IAMBufferNegotiation;

// address=[0x3b2eed8]
_IID_ISmartRenderEngine;

// address=[0x3b2eeec]
_CODECAPI_AVDecAACDownmixMode;

// address=[0x3b2ef00]
_MEDIASUBTYPE_AIFF;

// address=[0x3b2ef14]
_CLSID_DVBSNetworkProvider;

// address=[0x3b2ef28]
_FORMAT_MPEG2_VIDEO;

// address=[0x3b2ef3c]
_CLSID_CCAFilter;

// address=[0x3b2ef50]
_MEDIASUBTYPE_YVYU;

// address=[0x3b2ef64]
_IID_IOverlayNotify2;

// address=[0x3b2ef78]
_CLSID_VideoRenderer;

// address=[0x3b2ef8c]
_MEDIASUBTYPE_RGB565;

// address=[0x3b2efa0]
_CODECAPI_AVEncDDLFELowPassFilter;

// address=[0x3b2efb4]
_MEDIASUBTYPE_ARGB4444_D3D_DX9_RT;

// address=[0x3b2efc8]
_MEDIASUBTYPE_AnalogVideo_SECAM_L;

// address=[0x3b2efdc]
_IID_IAMGraphStreams;

// address=[0x3b2eff0]
_CODECAPI_AVDDSurroundMode;

// address=[0x3b2f004]
_IID_IFindCompressorCB;

// address=[0x3b2f018]
_CODECAPI_GUID_AVEncCommonFormatDVD_V;

// address=[0x3b2f02c]
_MEDIASUBTYPE_MPEG2_TRANSPORT;

// address=[0x3b2f040]
_CODECAPI_AVDecVideoSWPowerLevel;

// address=[0x3b2f054]
_IID_IAMGraphBuilderCallback;

// address=[0x3b2f068]
_MEDIASUBTYPE_MPEG1Packet;

// address=[0x3b2f07c]
_IID_IAMCopyCaptureFileProgress;

// address=[0x3b2f090]
_CLSID_WMAsfWriter;

// address=[0x3b2f0a4]
_CODECAPI_AVDecVideoThumbnailGenerationMode;

// address=[0x3b2f0b8]
_CLSID_MPEG2Demultiplexer_NoClock;

// address=[0x3b2f0cc]
_MEDIASUBTYPE_Line21_VBIRawData;

// address=[0x3b2f0e0]
_CLSID_ModexRenderer;

// address=[0x3b2f0f4]
_IID_IFilterGraph3;

// address=[0x3b2f108]
_CLSID_TVEFilterCCProperties;

// address=[0x3b2f11c]
_IID_IVPControl;

// address=[0x3b2f130]
_IID_IPinFlowControl;

// address=[0x3b2f144]
_CLSID_DVEncPropertiesPage;

// address=[0x3b2f158]
_CODECAPI_AVEncMPVGOPSize;

// address=[0x3b2f16c]
_IID_IFullScreenVideoEx;

// address=[0x3b2f180]
_MEDIASUBTYPE_AnalogVideo_PAL_G;

// address=[0x3b2f194]
_CODECAPI_AVEncVideoInverseTelecineThreshold;

// address=[0x3b2f1a8]
_CLSID_QualityProperties;

// address=[0x3b2f1bc]
_MEDIASUBTYPE_dv25;

// address=[0x3b2f1d0]
_IID_ICodecAPI;

// address=[0x3b2f1e4]
_MEDIASUBTYPE_MPEG2_PROGRAM;

// address=[0x3b2f1f8]
_MEDIASUBTYPE_IMC2;

// address=[0x3b2f20c]
_CODECAPI_AVEncVideoMinQP;

// address=[0x3b2f220]
_AM_KSCATEGORY_DATACOMPRESSOR;

// address=[0x3b2f234]
_CODECAPI_AVEncVideoHeaderDropFrame;

// address=[0x3b2f248]
_CLSID_MediaDet;

// address=[0x3b2f25c]
_CODECAPI_AVEncMPVGOPOpen;

// address=[0x3b2f270]
_IID_IMediaTypeInfo;

// address=[0x3b2f284]
_MEDIASUBTYPE_P016;

// address=[0x3b2f298]
_CODECAPI_AVEncVideoUseLTRFrame;

// address=[0x3b2f2ac]
_CODECAPI_AVEncAudioMapDestChannel7;

// address=[0x3b2f2c0]
_CODECAPI_AVEncDDSurround3dBAttenuation;

// address=[0x3b2f2d4]
_IID_IEVRFilterConfigEx;

// address=[0x3b2f2e8]
_CODECAPI_AVEncMP12MuxLargestPacketSize;

// address=[0x3b2f2fc]
_CLSID_AviMuxProptyPage1;

// address=[0x3b2f310]
_IID_IAMTimelineVirtualTrack;

// address=[0x3b2f324]
_CLSID_AudioRender;

// address=[0x3b2f338]
_MEDIASUBTYPE_QTJpeg;

// address=[0x3b2f34c]
_IID_IVMRFilterConfig;

// address=[0x3b2f360]
_IID_IAMAudioInputMixer;

// address=[0x3b2f374]
_CODECAPI_GUID_AVEncDTS;

// address=[0x3b2f388]
_IID_IAMResourceControl;

// address=[0x3b2f39c]
_CODECAPI_AVEncCommonBufferInLevel;

// address=[0x3b2f3b0]
_IID_IVMRSurface9;

// address=[0x3b2f3c4]
_IID_IAMVideoCompression;

// address=[0x3b2f3d8]
_CODECAPI_AVDecVideoSoftwareDeinterlaceMode;

// address=[0x3b2f3ec]
_CODECAPI_AVEncCommonTranscodeEncodingProfile;

// address=[0x3b2f400]
_DSATTRIB_UDCRTag;

// address=[0x3b2f414]
_MEDIATYPE_MPEG1SystemStream;

// address=[0x3b2f428]
_AM_KSCATEGORY_TVTUNER;

// address=[0x3b2f43c]
_IID_IAMDroppedFrames;

// address=[0x3b2f450]
_CODECAPI_GUID_AVDecAudioOutputFormat_PCM_Headphones;

// address=[0x3b2f464]
_CODECAPI_AVEncVideoInputChromaSubsampling;

// address=[0x3b2f478]
_CODECAPI_AVEncVideoUsage;

// address=[0x3b2f48c]
_CODECAPI_GUID_AVDecAudioOutputFormat_SPDIF_Bitstream;

// address=[0x3b2f4a0]
_IID_IBaseFilter;

// address=[0x3b2f4b4]
_MEDIASUBTYPE_dvsl;

// address=[0x3b2f4c8]
_MEDIASUBTYPE_ARGB32_D3D_DX9_RT;

// address=[0x3b2f4dc]
_MEDIASUBTYPE_Y411;

// address=[0x3b2f4f0]
_DVDTrace_VOBUParsed_Event;

// address=[0x3b2f504]
_CODECAPI_AVEncVideoOutputColorPrimaries;

// address=[0x3b2f518]
_CODECAPI_AVEncMP12PktzOriginal;

// address=[0x3b2f52c]
_CODECAPI_AVEncMPVQuantMatrixNonIntra;

// address=[0x3b2f540]
_CLSID_DxtAlphaSetter;

// address=[0x3b2f554]
_CLSID_DxtCompositor;

// address=[0x3b2f568]
_CODECAPI_AVDecCommonInputFormat;

// address=[0x3b2f57c]
_CODECAPI_AVEncMP12PktzInitialPTS;

// address=[0x3b2f590]
_CLSID_ATSCNetworkProvider;

// address=[0x3b2f5a4]
_MEDIATYPE_MPEG2_PACK;

// address=[0x3b2f5b8]
_CODECAPI_GUID_AVEncH264Video;

// address=[0x3b2f5cc]
_CLSID_VideoProcAmpPropertyPage;

// address=[0x3b2f5e0]
_IID_IVPVBIConfig;

// address=[0x3b2f5f4]
_DSATTRIB_OptionalVideoAttributes;

// address=[0x3b2f608]
_CODECAPI_AVEncStatVideoTotalFrames;

// address=[0x3b2f61c]
_CLSID_MediaPropertyBag;

// address=[0x3b2f630]
_MEDIASUBTYPE_ARGB1555_D3D_DX7_RT;

// address=[0x3b2f644]
_CODECAPI_AVEncMP12MuxDVDNavPacks;

// address=[0x3b2f658]
_CODECAPI_AVDecVideoPixelAspectRatio;

// address=[0x3b2f66c]
_CODECAPI_AVEncVideoRateControlParams;

// address=[0x3b2f680]
_IID_IEVRVideoStreamControl;

// address=[0x3b2f694]
_IID_IMFTopologyServiceLookup;

// address=[0x3b2f6a8]
_IID_IVMRImageCompositor9;

// address=[0x3b2f6bc]
_IID_IMediaSample2Config;

// address=[0x3b2f6d0]
_CODECAPI_AVEncStatHardwareBandwidthUtilitization;

// address=[0x3b2f6e4]
_EVRConfig_AllowBatching;

// address=[0x3b2f6f8]
_IID_IVMRImagePresenterExclModeConfig;

// address=[0x3b2f70c]
_CLSID_AviMuxProptyPage;

// address=[0x3b2f720]
_CLSID_DVMux;

// address=[0x3b2f734]
_MEDIASUBTYPE_Y216;

// address=[0x3b2f748]
_MEDIASUBTYPE_MPEG2_VIDEO;

// address=[0x3b2f75c]
_CAPTION_FORMAT_DVB;

// address=[0x3b2f770]
_CODECAPI_AVDecVideoDXVAMode;

// address=[0x3b2f784]
_CODECAPI_AVEncCommonMultipassMode;

// address=[0x3b2f798]
_MEDIASUBTYPE_RGB32_D3D_DX7_RT;

// address=[0x3b2f7ac]
_IID_IDDrawExclModeVideoCallback;

// address=[0x3b2f7c0]
_CLSID_CMpegVideoCodec;

// address=[0x3b2f7d4]
_FORMAT_VIDEOINFO2;

// address=[0x3b2f7e8]
_IID_IMediaLocator;

// address=[0x3b2f7fc]
_CODECAPI_GUID_AVDecAudioOutputFormat_PCM_Stereo_MatrixEncoded;

// address=[0x3b2f810]
_EVRConfig_ForceScaling;

// address=[0x3b2f824]
_MEDIASUBTYPE_AnalogVideo_PAL_I;

// address=[0x3b2f838]
_IID_IVMRWindowlessControl9;

// address=[0x3b2f84c]
_CODECAPI_AVEncCommonPassStart;

// address=[0x3b2f860]
_CLSID_SubtitlesFilter;

// address=[0x3b2f874]
_CLSID_StreamBufferThumbnailHandler;

// address=[0x3b2f888]
_CODECAPI_AVEncCommonBufferSize;

// address=[0x3b2f89c]
_LOOK_UPSTREAM_ONLY;

// address=[0x3b2f8b0]
_IID_IAMStreamSelect;

// address=[0x3b2f8c4]
_CODECAPI_AVEncSliceControlSize;

// address=[0x3b2f8d8]
_CLSID_AllocPresenterDDXclMode;

// address=[0x3b2f8ec]
_MEDIATYPE_AUXTeletextPage;

// address=[0x3b2f900]
_CLSID_AviSplitter;

// address=[0x3b2f914]
_IID_IAudioData;

// address=[0x3b2f928]
_CODECAPI_AVEncWMVKeyFrameDistance;

// address=[0x3b2f93c]
_CODECAPI_AVEncDDProductionMixLevel;

// address=[0x3b2f950]
_CODECAPI_AVEncMPVGenerateHeaderSeqDispExt;

// address=[0x3b2f964]
_IID_IMFVideoMixerControl;

// address=[0x3b2f978]
_IID_IVMRMixerBitmap9;

// address=[0x3b2f98c]
_IID_IReferenceClock2;

// address=[0x3b2f9a0]
_CODECAPI_AVDSPLoudnessEqualization;

// address=[0x3b2f9b4]
_CODECAPI_AVEncAudioIntervalToEncode;

// address=[0x3b2f9c8]
_DVDTrace_SkipPTS_Event;

// address=[0x3b2f9dc]
_IID_IVMRSurface;

// address=[0x3b2f9f0]
_FORMAT_CAPTIONED_MPEG2VIDEO;

// address=[0x3b2fa04]
_CODECAPI_GUID_AVEncDV;

// address=[0x3b2fa18]
_CODECAPI_CHANGELISTS;

// address=[0x3b2fa2c]
_IID_IAMCameraControl;

// address=[0x3b2fa40]
_CODECAPI_AVEncMP12PktzPacketSize;

// address=[0x3b2fa54]
_IID_IMFVideoPresenter;

// address=[0x3b2fa68]
_CLSID_AMTimelineComp;

// address=[0x3b2fa7c]
_MEDIATYPE_CC_CONTAINER;

// address=[0x3b2fa90]
_CLSID_FilterMapper2;

// address=[0x3b2faa4]
_IID_IAMDirectSound;

// address=[0x3b2fab8]
_MEDIASUBTYPE_DVSD;

// address=[0x3b2facc]
_CODECAPI_AVDecVideoMPEG2ErrorConcealment;

// address=[0x3b2fae0]
_MEDIATYPE_MSTVCaption;

// address=[0x3b2faf4]
_CODECAPI_AVEncVideoOutputScanType;

// address=[0x3b2fb08]
_MEDIATYPE_AnalogVideo;

// address=[0x3b2fb1c]
_IID_IDirectDrawVideo;

// address=[0x3b2fb30]
_FORMAT_JPEGImage;

// address=[0x3b2fb44]
_IID_IResize;

// address=[0x3b2fb58]
_PIN_CATEGORY_STILL;

// address=[0x3b2fb6c]
_MEDIASUBTYPE_AnalogVideo_SECAM_H;

// address=[0x3b2fb80]
_MEDIASUBTYPE_CLPL;

// address=[0x3b2fb94]
_IID_IAMLine21Decoder;

// address=[0x3b2fba8]
_IID_IAMPluginControl;

// address=[0x3b2fbbc]
_IID_IMFVideoMixerControl2;

// address=[0x3b2fbd0]
_IID_IMpeg2Demultiplexer;

// address=[0x3b2fbe4]
_MEDIASUBTYPE_Asf;

// address=[0x3b2fbf8]
_IID_IMixerOCX;

// address=[0x3b2fc0c]
_CODECAPI_CURRENTCHANGELIST;

// address=[0x3b2fc20]
_CODECAPI_AVEncMPVQScaleType;

// address=[0x3b2fc34]
_MEDIASUBTYPE_CC_CONTAINER;

// address=[0x3b2fc48]
_MEDIASUBTYPE_QTRle;

// address=[0x3b2fc5c]
_CODECAPI_AVEncAudioMapDestChannel0;

// address=[0x3b2fc70]
_IID_IDDrawExclModeVideo;

// address=[0x3b2fc84]
_CODECAPI_AVEncWMVProduceDummyFrames;

// address=[0x3b2fc98]
_CODECAPI_AVEncNumWorkerThreads;

// address=[0x3b2fcac]
_CLSID_TVEFilterTuneProperties;

// address=[0x3b2fcc0]
_FORMAT_AnalogVideo;

// address=[0x3b2fcd4]
_CLSID_EVRPlaybackPipelineOptimizer;

// address=[0x3b2fce8]
_CODECAPI_AVEncMPAPrivateUserBit;

// address=[0x3b2fcfc]
_MEDIASUBTYPE_dvh1;

// address=[0x3b2fd10]
_CODECAPI_AVEncVideoInputColorTransferMatrix;

// address=[0x3b2fd24]
_IID_IAMAnalogVideoDecoder;

// address=[0x3b2fd38]
_CLSID_MediaMultiplexerCategory;

// address=[0x3b2fd4c]
_CODECAPI_AVEncVideoForceSourceScanType;

// address=[0x3b2fd60]
_FORMAT_VideoInfo;

// address=[0x3b2fd74]
_CODECAPI_AVEncCommonStreamEndHandling;

// address=[0x3b2fd88]
_MEDIASUBTYPE_CLJR;

// address=[0x3b2fd9c]
_MEDIASUBTYPE_YUY2;

// address=[0x3b2fdb0]
_MEDIASUBTYPE_DRM_Audio;

// address=[0x3b2fdc4]
_CODECAPI_AVEncCommonBufferOutLevel;

// address=[0x3b2fdd8]
_CODECAPI_AVEncCommonMeanBitRate;

// address=[0x3b2fdec]
_CLSID_VfwCapture;

// address=[0x3b2fe00]
_CLSID_VideoMixingRenderer;

// address=[0x3b2fe14]
_AM_KSPROPSETID_DvdKaraoke;

// address=[0x3b2fe28]
_MEDIASUBTYPE_RGB16_D3D_DX7_RT;

// address=[0x3b2fe3c]
_TIME_FORMAT_MEDIA_TIME;

// address=[0x3b2fe50]
_IID_IConfigAviMux;

// address=[0x3b2fe64]
_CLSID_PropertySetter;

// address=[0x3b2fe78]
_CODECAPI_VIDEO_ENCODER;

// address=[0x3b2fe8c]
_CODECAPI_AVEncVideoInverseTelecineEnable;

// address=[0x3b2fea0]
_CODECAPI_AVEncMPVQuantMatrixIntra;

// address=[0x3b2feb4]
_IID_IBasicVideo;

// address=[0x3b2fec8]
_CLSID_SBE2MediaTypeProfile;

// address=[0x3b2fedc]
_CODECAPI_AVEncH264CABACEnable;

// address=[0x3b2fef0]
_CLSID_NullRenderer;

// address=[0x3b2ff04]
_CODECAPI_AVEncVideoEncodeFrameTypeQP;

// address=[0x3b2ff18]
_CODECAPI_GUID_AVEncCommonFormatDVD_DashVR;

// address=[0x3b2ff2c]
_CLSID_NetworkProvider;

// address=[0x3b2ff40]
_MEDIASUBTYPE_dvhd;

// address=[0x3b2ff54]
_IID_IAMVfwCompressDialogs;

// address=[0x3b2ff68]
_IID_IMemoryData;

// address=[0x3b2ff7c]
_IID_IVMRImagePresenterConfig9;

// address=[0x3b2ff90]
_IID_IAMTimecodeReader;

// address=[0x3b2ffa4]
_MEDIASUBTYPE_AnalogVideo_SECAM_K;

// address=[0x3b2ffb8]
_IID_IPin;

// address=[0x3b2ffcc]
_CODECAPI_GUID_AVEncMPEG1Audio;

// address=[0x3b2ffe0]
_PIN_CATEGORY_TIMECODE;

// address=[0x3b2fff4]
_PIN_CATEGORY_CAPTURE;

// address=[0x3b30008]
_MEDIASUBTYPE_CFCC;

// address=[0x3b3001c]
_IID_IFilterChain;

// address=[0x3b30030]
_CODECAPI_AVEncAudioMapDestChannel5;

// address=[0x3b30044]
_IID_IVMRMonitorConfig;

// address=[0x3b30058]
_CODECAPI_AVDecDDOperationalMode;

// address=[0x3b3006c]
_MEDIATYPE_AnalogAudio;

// address=[0x3b30080]
_MEDIASUBTYPE_Y210;

// address=[0x3b30094]
_CODECAPI_GUID_AVEncMLP;

// address=[0x3b300a8]
_MEDIASUBTYPE_DVB_SI;

// address=[0x3b300bc]
_DSATTRIB_DSHOW_STREAM_DESC;

// address=[0x3b300d0]
_MEDIASUBTYPE_AnalogVideo_SECAM_G;

// address=[0x3b300e4]
_CODECAPI_AVEncVideoMaxQP;

// address=[0x3b300f8]
_CODECAPI_AVEncVideoDefaultUpperFieldDominant;

// address=[0x3b3010c]
_CLSID_StreamBufferSource;

// address=[0x3b30120]
_CLSID_DSoundRender;

// address=[0x3b30134]
_IID_IAMovieSetup;

// address=[0x3b30148]
_CODECAPI_GUID_AVDecAudioInputDolbyDigitalPlus;

// address=[0x3b3015c]
_CODECAPI_AVEncCommonMaxBitRate;

// address=[0x3b30170]
_CLSID_CaptionsFilter;

// address=[0x3b30184]
_IID_IAMTimelineEffectable;

// address=[0x3b30198]
_CODECAPI_GUID_AVEncWMAPro;

// address=[0x3b301ac]
_TIME_FORMAT_SAMPLE;

// address=[0x3b301c0]
_IID_IVPVBIObject;

// address=[0x3b301d4]
_IID_IVMRAspectRatioControl9;

// address=[0x3b301e8]
_IID_IAMErrorLog;

// address=[0x3b301fc]
_CODECAPI_AVDecVideoDXVABusEncryption;

// address=[0x3b30210]
_CODECAPI_AVAudioChannelCount;

// address=[0x3b30224]
_CODECAPI_GUID_AVEncCommonFormatDVB;

// address=[0x3b30238]
_FORMAT_MPEG2Video;

// address=[0x3b3024c]
_CODECAPI_AVEncMPVIntraVLCTable;

// address=[0x3b30260]
_CODECAPI_AVEncStatAudioAverageBPS;

// address=[0x3b30274]
_CODECAPI_AVDecVideoH264ErrorConcealment;

// address=[0x3b30288]
_MEDIASUBTYPE_AnalogVideo_SECAM_K1;

// address=[0x3b3029c]
_IID_IDxtJpeg;

// address=[0x3b302b0]
_MEDIASUBTYPE_ARGB32;

// address=[0x3b302c4]
_CODECAPI_AVEncWMVInterlacedEncoding;

// address=[0x3b302d8]
_IID_IMFVideoMixerBitmap;

// address=[0x3b302ec]
_IID_IAMExtTransport;

// address=[0x3b30300]
_IID_IDistributorNotify;

// address=[0x3b30314]
_CODECAPI_AVEncVideoContentType;

// address=[0x3b30328]
_IID_IKsDataTypeHandler;

// address=[0x3b3033c]
_CODECAPI_AVEncMP12MuxSysSTDBufferBound;

// address=[0x3b30350]
_CODECAPI_GUID_AVEncDolbyDigitalConsumer;

// address=[0x3b30364]
_CODECAPI_GUID_AVDecAudioOutputFormat_PCM_Stereo_Auto;

// address=[0x3b30378]
_CODECAPI_AVEncCommonQualityVsSpeed;

// address=[0x3b3038c]
_MEDIASUBTYPE_PCMAudio_Obsolete;

// address=[0x3b303a0]
_MEDIATYPE_AUXLine21Data;

// address=[0x3b303b4]
_IID_IVMRSurfaceAllocator9;

// address=[0x3b303c8]
_MEDIASUBTYPE_AnalogVideo_PAL_N_COMBO;

// address=[0x3b303dc]
_PIN_CATEGORY_CC;

// address=[0x3b303f0]
_IID_IAMTimeline;

// address=[0x3b30404]
_CODECAPI_AVEncVideoSelectLayer;

// address=[0x3b30418]
_CODECAPI_AVEncMP12PktzStreamID;

// address=[0x3b3042c]
_CLSID_ICodecAPIProxy;

// address=[0x3b30440]
_MEDIATYPE_Interleaved;

// address=[0x3b30454]
_CODECAPI_AVEncMP12MuxInitialSCR;

// address=[0x3b30468]
_MEDIASUBTYPE_AnalogVideo_PAL_H;

// address=[0x3b3047c]
_CLSID_AudioRecord;

// address=[0x3b30490]
_MEDIATYPE_Timecode;

// address=[0x3b304a4]
_AM_KSCATEGORY_CAPTURE;

// address=[0x3b304b8]
_MEDIASUBTYPE_PCM;

// address=[0x3b304cc]
_IID_IVPObject;

// address=[0x3b304e0]
_CODECAPI_AVDecAudioDualMonoReproMode;

// address=[0x3b304f4]
_MEDIASUBTYPE_P210;

// address=[0x3b30508]
_MEDIASUBTYPE_DVCS;

// address=[0x3b3051c]
_CODECAPI_AVDecCommonOutputFormat;

// address=[0x3b30530]
_IID_IMediaDet;

// address=[0x3b30544]
_CLSID_AviReader;

// address=[0x3b30558]
_EVRConfig_ForceThrottle;

// address=[0x3b3056c]
_CLSID_VideoRendererDefault;

// address=[0x3b30580]
_IID_IMFTopologyServiceLookupClient;

// address=[0x3b30594]
_CLSID_MPEG1PacketPlayer;

// address=[0x3b305a8]
_CLSID_MPEG1Splitter;

// address=[0x3b305bc]
_CODECAPI_AVEncVideoOutputFrameRateConversion;

// address=[0x3b305d0]
_MEDIASUBTYPE_MPEG2_PBDA_TRANSPORT_PROCESSED;

// address=[0x3b305e4]
_IID_IFilterGraph;

// address=[0x3b305f8]
_TIME_FORMAT_BYTE;

// address=[0x3b3060c]
_CLSID_Dither;

// address=[0x3b30620]
_MEDIASUBTYPE_YVU9;

// address=[0x3b30634]
_IID_ICreateDevEnum;

// address=[0x3b30648]
_MEDIASUBTYPE_H264;

// address=[0x3b3065c]
_CODECAPI_AVEncMPVDefaultBPictureCount;

// address=[0x3b30670]
_MEDIASUBTYPE_IF09;

// address=[0x3b30684]
_IID_IMediaSample2;

// address=[0x3b30698]
_CODECAPI_AVEncStatMPVSkippedEmptyFrames;

// address=[0x3b306ac]
_CODECAPI_AVEncCommonFormatConstraint;

// address=[0x3b306c0]
_IID_IBaseVideoMixer;

// address=[0x3b306d4]
_CODECAPI_AVEncAudioMapDestChannel2;

// address=[0x3b306e8]
_CODECAPI_AVEncDDLtRtCenterMixLvl_x10;

// address=[0x3b306fc]
_IID_IAMVideoProcAmp;

// address=[0x3b30710]
_IID_IXml2Dex;

// address=[0x3b30724]
_CODECAPI_AVEncWMVDecoderComplexity;

// address=[0x3b30738]
_IID_IAMVideoAcceleratorNotify;

// address=[0x3b3074c]
_LOOK_DOWNSTREAM_ONLY;

// address=[0x3b30760]
_CODECAPI_AVEncStatHardwareProcessorUtilitization;

// address=[0x3b30774]
_CODECAPI_GUID_AVEncCommonFormatDVD_PlusVR;

// address=[0x3b30788]
_FORMAT_Image;

// address=[0x3b3079c]
_CODECAPI_AVDecNumWorkerThreads;

// address=[0x3b307b0]
_CODECAPI_GUID_AVEncDTSHD;

// address=[0x3b307c4]
_MEDIASUBTYPE_ATSC_SI;

// address=[0x3b307d8]
_IID_IMediaPropertyBag;

// address=[0x3b307ec]
_IID_IVMRImagePresenterConfig;

// address=[0x3b30800]
_IID_IEnumMediaTypes;

// address=[0x3b30814]
_CLSID_EnhancedVideoRenderer;

// address=[0x3b30828]
_IID_IVPNotify;

// address=[0x3b3083c]
_CODECAPI_AVDecDDDynamicRangeScaleLow;

// address=[0x3b30850]
_MEDIATYPE_MPEG2_PES;

// address=[0x3b30864]
_CLSID_SBE2File;

// address=[0x3b30878]
_IID_IBasicVideo2;

// address=[0x3b3088c]
_MEDIASUBTYPE_XDS;

// address=[0x3b308a0]
_MEDIASUBTYPE_MPEG1Audio;

// address=[0x3b308b4]
_IID_IAudioMediaStream;

// address=[0x3b308c8]
_CODECAPI_AVDecCommonMeanBitRateInterval;

// address=[0x3b308dc]
_MEDIASUBTYPE_RGB24;

// address=[0x3b308f0]
_CLSID_VideoCompressorCategory;

// address=[0x3b30904]
_IID_IGetCapabilitiesKey;

// address=[0x3b30918]
_LIBID_QuartzTypeLib;

// address=[0x3b3092c]
_MEDIASUBTYPE_DVD_NAVIGATION_DSI;

// address=[0x3b30940]
_IID_IOverlayNotify;

// address=[0x3b30954]
_CLSID_ActiveMovieCategories;

// address=[0x3b30968]
_MEDIASUBTYPE_NV12;

// address=[0x3b3097c]
_CLSID_VPObject;

// address=[0x3b30990]
_MEDIASUBTYPE_AU;

// address=[0x3b309a4]
_CODECAPI_GUID_AVEncDolbyDigitalPlus;

// address=[0x3b309b8]
_CODECAPI_AVEncAudioInputContent;

// address=[0x3b309cc]
_CODECAPI_GUID_AVEncSDDS;

// address=[0x3b309e0]
_IID_IAMClockAdjust;

// address=[0x3b309f4]
_MEDIASUBTYPE_AnalogVideo_SECAM_B;

// address=[0x3b30a08]
_IID_IMediaEventSink;

// address=[0x3b30a1c]
_IID_IBitBltVideoDevice;

// address=[0x3b30a30]
_IID_IDVEnc;

// address=[0x3b30a44]
_IID_IMixerOCXNotify;

// address=[0x3b30a58]
_CLSID_StreamBufferPropertyHandler;

// address=[0x3b30a6c]
_IID_IAMPhysicalPinInfo;

// address=[0x3b30a80]
_IID_IAMTimelineObj;

// address=[0x3b30a94]
_CLSID_SBE2FileScan;

// address=[0x3b30aa8]
_IID_IDirectDrawMediaSampleAllocator;

// address=[0x3b30abc]
_CLSID_WMAsfReader;

// address=[0x3b30ad0]
_MEDIASUBTYPE_IEEE_FLOAT;

// address=[0x3b30ae4]
_CODECAPI_AUDIO_ENCODER;

// address=[0x3b30af8]
_IID_IAMTunerNotification;

// address=[0x3b30b0c]
_CODECAPI_AVDecDDDynamicRangeScaleHigh;

// address=[0x3b30b20]
_MEDIASUBTYPE_Y41P;

// address=[0x3b30b34]
_IID_IDvdInfo;

// address=[0x3b30b48]
_CLSID_AVIDraw;

// address=[0x3b30b5c]
_IID_IVMRVideoStreamControl9;

// address=[0x3b30b70]
_CODECAPI_AVEncMPALayer;

// address=[0x3b30b84]
_CLSID_IVideoEncoderCodecAPIProxy;

// address=[0x3b30b98]
_MEDIASUBTYPE_DtvCcData;

// address=[0x3b30bac]
_CODECAPI_AVEncVideoInputColorLighting;

// address=[0x3b30bc0]
_CLSID_RenderEngine;

// address=[0x3b30bd4]
_MEDIASUBTYPE_P010;

// address=[0x3b30be8]
_CLSID_AsyncReader;

// address=[0x3b30bfc]
_IID_IVMRWindowlessControl;

// address=[0x3b30c10]
_IID_IVMRDeinterlaceControl;

// address=[0x3b30c24]
_CODECAPI_AVDecDDStereoDownMixMode;

// address=[0x3b30c38]
_LIBID_DexterLib;

// address=[0x3b30c4c]
_IID_IDrawVideoImage;

// address=[0x3b30c60]
_IID_IAMVfwCaptureDialogs;

// address=[0x3b30c74]
_CLSID_SmartRenderEngine;

// address=[0x3b30c88]
_IID_IDirectDrawSurfaceKernel;

// address=[0x3b30c9c]
_CODECAPI_AVEncVideoPixelAspectRatio;

// address=[0x3b30cb0]
_CLSID_WSTDecoder;

// address=[0x3b30cc4]
_IID_IAMTuner;

// address=[0x3b30cd8]
_MEDIASUBTYPE_dv50;

// address=[0x3b30cec]
_MEDIASUBTYPE_WSS;

// address=[0x3b30d00]
_MEDIASUBTYPE_UYVY;

// address=[0x3b30d14]
_CODECAPI_AVEncDDCopyright;

// address=[0x3b30d28]
_CLSID_TVTunerFilterPropertyPage;

// address=[0x3b30d3c]
_CODECAPI_AVEncMP12MuxEarliestPTS;

// address=[0x3b30d50]
_PIN_CATEGORY_TELETEXT;

// address=[0x3b30d64]
_FORMAT_WaveFormatEx;

// address=[0x3b30d78]
_IID_IDvdControl;

// address=[0x3b30d8c]
_IID_IAMExtDevice;

// address=[0x3b30da0]
_CODECAPI_GUID_AVEncPCM;

// address=[0x3b30db4]
_FORMAT_DolbyAC3;

// address=[0x3b30dc8]
_IID_IFilterMapper3;

// address=[0x3b30ddc]
_IID_IFilterInfo;

// address=[0x3b30df0]
_CODECAPI_GUID_AVDecAudioInputAAC;

// address=[0x3b30e04]
_CODECAPI_AVEncMP12MuxSysFixed;

// address=[0x3b30e18]
_CLSID_PersistMonikerPID;

// address=[0x3b30e2c]
_DVDTrace_Control;

// address=[0x3b30e40]
_DVDTrace_SendSample_Event;

// address=[0x3b30e54]
_IID_IMediaFilter;

// address=[0x3b30e68]
_IID_IVMRSurfaceAllocatorNotify9;

// address=[0x3b30e7c]
_MEDIASUBTYPE_SDDS;

// address=[0x3b30e90]
_CODECAPI_AVEncDDLoRoCenterMixLvl_x10;

// address=[0x3b30ea4]
_CODECAPI_AVEncVideoMaxNumRefFrame;

// address=[0x3b30eb8]
_CODECAPI_AVEncVideoMarkLTRFrame;

// address=[0x3b30ecc]
_IID_IEnumRegFilters;

// address=[0x3b30ee0]
_MEDIASUBTYPE_MPEG2DATA;

// address=[0x3b30ef4]
_IID_IAMOpenProgress;

// address=[0x3b30f08]
_CODECAPI_GUID_AVEncCommonFormatSVCD;

// address=[0x3b30f1c]
_IID_IGraphBuilder;

// address=[0x3b30f30]
_CODECAPI_AVEncDDProductionRoomType;

// address=[0x3b30f44]
_CODECAPI_AVEncVideoInputColorNominalRange;

// address=[0x3b30f58]
_CLSID_DeviceControlCategory;

// address=[0x3b30f6c]
_CLSID_AVIDec;

// address=[0x3b30f80]
_IID_IAMTimelineComp;

// address=[0x3b30f94]
_CLSID_AMTimeline;

// address=[0x3b30fa8]
_IID_IFilterMapper;

// address=[0x3b30fbc]
_MEDIASUBTYPE_Line21_GOPPacket;

// address=[0x3b30fd0]
_IID_IPersistMediaPropertyBag;

// address=[0x3b30fe4]
_CODECAPI_AVRealtimeControl;

// address=[0x3b30ff8]
_CODECAPI_AVPriorityControl;

// address=[0x3b3100c]
_CODECAPI_AVEncCodecType;

// address=[0x3b31020]
_MEDIASUBTYPE_DOLBY_AC3;

// address=[0x3b31034]
_CLSID_EVRTearlessWindowPresenter9;

// address=[0x3b31048]
_CODECAPI_AVEncDDLoRoSurroundMixLvl_x10;

// address=[0x3b3105c]
_FORMAT_UVCH264Video;

// address=[0x3b31070]
_MEDIASUBTYPE_WAVE;

// address=[0x3b31084]
_CODECAPI_AVDecDDMatrixDecodingMode;

// address=[0x3b31098]
_CLSID_FilterGraphPrivateThread;

// address=[0x3b310ac]
_MEDIASUBTYPE_VPVBI;

// address=[0x3b310c0]
_MEDIATYPE_VBI;

// address=[0x3b310d4]
_CODECAPI_AVEncDDAtoDConverterType;

// address=[0x3b310e8]
_CODECAPI_AVEncCommonRealTime;

// address=[0x3b310fc]
_FORMAT_525WSS;

// address=[0x3b31110]
_IID_IPinInfo;

// address=[0x3b31124]
_IID_IReferenceClockTimerControl;

// address=[0x3b31138]
_CODECAPI_AVDecVideoProcDeinterlaceCSC;

// address=[0x3b3114c]
_ENCAPIPARAM_PEAK_BITRATE;

// address=[0x3b31160]
_IID_IVPVBINotify;

// address=[0x3b31174]
_CODECAPI_AVEncDDCentreDownMixLevel;

// address=[0x3b31188]
_IID_IAMCertifiedOutputProtection;

// address=[0x3b3119c]
_IID_IDvdGraphBuilder;

// address=[0x3b311b0]
_CLSID_FilterGraphNoThread;

// address=[0x3b311d8]
_PIN_CATEGORY_VIDEOPORT;

// address=[0x3b311ec]
_CODECAPI_AVEncWMVKeyFrameBufferLevelMarker;

// address=[0x3b31200]
_AM_KSCATEGORY_VBICODEC_MI;

// address=[0x3b31214]
_CODECAPI_AVEncDDProductionInfoExists;

// address=[0x3b31228]
_CODECAPI_AVEncVideoHeaderHours;

// address=[0x3b3123c]
_CODECAPI_AVEncMPVScanPattern;

// address=[0x3b31250]
_MEDIASUBTYPE_VPVideo;

// address=[0x3b31264]
_CLSID_SmartTee;

// address=[0x3b31278]
_CLSID_Mpeg2VideoStreamAnalyzer;

// address=[0x3b3128c]
_ENCAPIPARAM_BITRATE_MODE;

// address=[0x3b312a0]
_MEDIASUBTYPE_ISDB_SI;

// address=[0x3b312b4]
_IID_IVideoWindow;

// address=[0x3b312c8]
_DVDTrace_StateRestore_Event;

// address=[0x3b312dc]
_CLSID_AudioRendererCategory;

// address=[0x3b312f0]
_MEDIASUBTYPE_MPEG1Video;

// address=[0x3b31304]
_MEDIASUBTYPE_DVD_LPCM_AUDIO;

// address=[0x3b31318]
_CLSID_MjpegDec;

// address=[0x3b3132c]
_MEDIASUBTYPE_AnalogVideo_NTSC_M;

// address=[0x3b31340]
_MEDIASUBTYPE_QTSmc;

// address=[0x3b31354]
_MEDIASUBTYPE_RGB555;

// address=[0x3b31368]
_IID_IAMMediaTypeStream;

// address=[0x3b3137c]
_CLSID_AnalogVideoDecoderPropertyPage;

// address=[0x3b31390]
_CODECAPI_GUID_AVEncCommonFormatMP3;

// address=[0x3b313a4]
_in6addr_allmldv2routersonlink;

// address=[0x3b313b8]
_in6addr_multicastprefix;

// address=[0x3b313cc]
_in6addr_allroutersonlink;

// address=[0x3b313e0]
_in4addr_allroutersonlink;

// address=[0x3b313e4]
_in6addr_solicitednodemulticastprefix;

// address=[0x3b313f8]
_in6addr_linklocalprefix;

// address=[0x3b3140c]
_in4addr_alligmpv3routersonlink;

// address=[0x3b31410]
_in6addr_loopback;

// address=[0x3b31438]
_in6addr_teredoprefix_old;

// address=[0x3b3144c]
_in6addr_v4mappedprefix;

// address=[0x3b31490]
_in4addr_multicastprefix;

// address=[0x3b31494]
_in4addr_any;

// address=[0x3b314a4]
_in6addr_6to4prefix;

// address=[0x3b314b8]
_in6addr_any;

// address=[0x3b314cc]
_in4addr_allnodesonlink;

// address=[0x3b31500]
_in6addr_teredoprefix;

// address=[0x3b31520]
_in4addr_loopback;

// address=[0x3b31548]
_scopeid_unspecified;

// address=[0x3b3154c]
_in4addr_linklocalprefix;

// address=[0x3b31550]
_in4addr_allteredohostsonlink;

// address=[0x3b31554]
_in6addr_teredoinitiallinklocaladdress;

// address=[0x3b31574]
_in4addr_broadcast;

// address=[0x3b31578]
_in6addr_allnodesonlink;

// address=[0x3b3158c]
_eui48_broadcast;

// address=[0x3b31594]
_in6addr_allnodesonnode;

// address=[0x3b4d558]
_quazal_deflate_copyright;

// address=[0x3b50d08]
_quazal_z_errmsg;

// address=[0x3b51420]
_quazal__dist_code;

// address=[0x3b51620]
_quazal__length_code;

// address=[0x3b51cb0]
_quazal_inflate_copyright;

// address=[0x3b68ed8]
__load_config_used;

// address=[0x3b6e860]
__tls_used;

// address=[0x3bb2c40]
___rtc_iaa;

// address=[0x3bb3f64]
___rtc_izz;

// address=[0x3bb4068]
___rtc_taa;

// address=[0x3bb538c]
___rtc_tzz;

// address=[0x3bb5b8c]
__TI2?AVCS4InvalidMapException@@;

// address=[0x3bb5ba0]
__CTA2?AVCS4InvalidMapException@@;

// address=[0x3bb5bb0]
__CT??_R0?AVCS4InvalidMapException@@@8??0CS4InvalidMapException@@QAE@ABV0@@Z4;

// address=[0x3bb5bd0]
__CT??_R0?AVCBBException@@@8??0CBBException@@QAE@ABV0@@Z4;

// address=[0x3bb976c]
__TI2?AVruntime_error@std@@;

// address=[0x3bb9780]
__CTA2?AVruntime_error@std@@;

// address=[0x3bb9790]
__CT??_R0?AVruntime_error@std@@@8??0runtime_error@std@@QAE@ABV01@@Z12;

// address=[0x3bb97b0]
__CT??_R0?AVexception@std@@@8??0exception@std@@QAE@ABV01@@Z12;

// address=[0x3bb97d0]
__TI3?AVrange_error@std@@;

// address=[0x3bb97e4]
__CTA3?AVrange_error@std@@;

// address=[0x3bb97f8]
__CT??_R0?AVrange_error@std@@@8??0range_error@std@@QAE@ABV01@@Z12;

// address=[0x3bc076c]
__TI5?AVfailure@ios_base@std@@;

// address=[0x3bc0780]
__CTA5?AVfailure@ios_base@std@@;

// address=[0x3bc079c]
__CT??_R0?AVfailure@ios_base@std@@@8??0failure@ios_base@std@@QAE@ABV012@@Z20;

// address=[0x3bc07bc]
__CT??_R0?AVsystem_error@std@@@8??0system_error@std@@QAE@ABV01@@Z20;

// address=[0x3bc07dc]
__CT??_R0?AV_System_error@std@@@8??0_System_error@std@@QAE@ABV01@@Z20;

// address=[0x3bc07fc]
__TI2?AVbad_cast@std@@;

// address=[0x3bc0810]
__CTA2?AVbad_cast@std@@;

// address=[0x3bc0820]
__CT??_R0?AVbad_cast@std@@@8??0bad_cast@std@@QAE@ABV01@@Z12;

// address=[0x3bc0840]
__TI2?AVSerialError@CPersistence@@;

// address=[0x3bc0854]
__CTA2?AVSerialError@CPersistence@@;

// address=[0x3bc0864]
__CT??_R0?AVSerialError@CPersistence@@@8??0SerialError@CPersistence@@QAE@ABV01@@Z4;

// address=[0x3bc0884]
__CT??_R0?AVError@CPersistence@@@8??0Error@CPersistence@@QAE@ABV01@@Z4;

// address=[0x3bc08a4]
__TI2?AVBadClassID@CPersistence@@;

// address=[0x3bc08b8]
__CTA2?AVBadClassID@CPersistence@@;

// address=[0x3bc08c8]
__CT??_R0?AVBadClassID@CPersistence@@@8??0BadClassID@CPersistence@@QAE@ABV01@@Z4;

// address=[0x3bc6b2c]
__TI2PAD;

// address=[0x3bc6b40]
__CTA2PAD;

// address=[0x3bc6b50]
__CT??_R0PAD@84;

// address=[0x3bc6b70]
__CT??_R0PAX@84;

// address=[0x3bcd7c0]
__TI2?AVCBBFileException@@;

// address=[0x3bcd7d4]
__CTA2?AVCBBFileException@@;

// address=[0x3bcd7e4]
__CT??_R0?AVCBBFileException@@@8??0CBBFileException@@QAE@ABV0@@Z552;

// address=[0x3d09f90]
__TI2?AVInvalidRefException@AdvXMLParser@@;

// address=[0x3d09fa4]
__CTA2?AVInvalidRefException@AdvXMLParser@@;

// address=[0x3d09fb4]
__CT??_R0?AVInvalidRefException@AdvXMLParser@@@8??0InvalidRefException@AdvXMLParser@@QAE@ABV01@@Z32;

// address=[0x3d09fd4]
__CT??_R0?AVException@AdvXMLParser@@@8??0Exception@AdvXMLParser@@QAE@ABV01@@Z4;

// address=[0x3d0a714]
__TI2?AVParsingException@AdvXMLParser@@;

// address=[0x3d0a728]
__CTA2?AVParsingException@AdvXMLParser@@;

// address=[0x3d0a738]
__CT??_R0?AVParsingException@AdvXMLParser@@@8??0ParsingException@AdvXMLParser@@QAE@ABV01@@Z16;

// address=[0x3d0abe4]
__TI2?AVCBBMemoryException@@;

// address=[0x3d0abf8]
__CTA2?AVCBBMemoryException@@;

// address=[0x3d0ac08]
__CT??_R0?AVCBBMemoryException@@@8??0CBBMemoryException@@QAE@ABV0@@Z4;

// address=[0x3d0d344]
__TI2?AVbad_alloc@std@@;

// address=[0x3d0d358]
__CTA2?AVbad_alloc@std@@;

// address=[0x3d0d368]
__CT??_R0?AVbad_alloc@std@@@8??0bad_alloc@std@@QAE@ABV01@@Z12;

// address=[0x3d0d388]
__TI3?AVinvalid_argument@std@@;

// address=[0x3d0d39c]
__CTA3?AVinvalid_argument@std@@;

// address=[0x3d0d3b0]
__CT??_R0?AVinvalid_argument@std@@@8??0invalid_argument@std@@QAE@ABV01@@Z12;

// address=[0x3d0d3d0]
__CT??_R0?AVlogic_error@std@@@8??0logic_error@std@@QAE@ABV01@@Z12;

// address=[0x3d0d3f0]
__TI3?AVlength_error@std@@;

// address=[0x3d0d404]
__CTA3?AVlength_error@std@@;

// address=[0x3d0d418]
__CT??_R0?AVlength_error@std@@@8??0length_error@std@@QAE@ABV01@@Z12;

// address=[0x3d0d438]
__TI3?AVout_of_range@std@@;

// address=[0x3d0d44c]
__CTA3?AVout_of_range@std@@;

// address=[0x3d0d460]
__CT??_R0?AVout_of_range@std@@@8??0out_of_range@std@@QAE@ABV01@@Z12;

// address=[0x3d0d480]
__TI3?AVoverflow_error@std@@;

// address=[0x3d0d494]
__CTA3?AVoverflow_error@std@@;

// address=[0x3d0d4a8]
__CT??_R0?AVoverflow_error@std@@@8??0overflow_error@std@@QAE@ABV01@@Z12;

// address=[0x3d0d4c8]
__TI2?AVbad_function_call@std@@;

// address=[0x3d0d4dc]
__CTA2?AVbad_function_call@std@@;

// address=[0x3d0d4ec]
__CT??_R0?AVbad_function_call@std@@@8??0bad_function_call@std@@QAE@ABV01@@Z12;

// address=[0x3d0d50c]
__TI3?AVregex_error@std@@;

// address=[0x3d0d520]
__CTA3?AVregex_error@std@@;

// address=[0x3d0d534]
__CT??_R0?AVregex_error@std@@@8??0regex_error@std@@QAE@ABV01@@Z16;

// address=[0x3d0d95c]
__TI4?AVsystem_error@std@@;

// address=[0x3d0d970]
__CTA4?AVsystem_error@std@@;

// address=[0x3d11038]
__TI3?AVbad_array_new_length@std@@;

// address=[0x3d1104c]
__CTA3?AVbad_array_new_length@std@@;

// address=[0x3d11060]
__CT??_R0?AVbad_array_new_length@std@@@8??0bad_array_new_length@std@@QAE@ABV01@@Z12;

// address=[0x3d11378]
__TI2?AVimproper_lock@Concurrency@@;

// address=[0x3d1138c]
__CTA2?AVimproper_lock@Concurrency@@;

// address=[0x3d1139c]
__CT??_R0?AVimproper_lock@Concurrency@@@8??0improper_lock@Concurrency@@QAE@ABV01@@Z12;

// address=[0x3d1160c]
__TI2?AVscheduler_resource_allocation_error@Concurrency@@;

// address=[0x3d11620]
__CTA2?AVscheduler_resource_allocation_error@Concurrency@@;

// address=[0x3d11630]
__CT??_R0?AVscheduler_resource_allocation_error@Concurrency@@@8??0scheduler_resource_allocation_error@Concurrency@@QAE@ABV01@@Z16;

// address=[0x3d11b20]
__TI2?AVunsupported_os@Concurrency@@;

// address=[0x3d11b34]
__CTA2?AVunsupported_os@Concurrency@@;

// address=[0x3d11b44]
__CT??_R0?AVunsupported_os@Concurrency@@@8??0unsupported_os@Concurrency@@QAE@ABV01@@Z12;

// address=[0x3d11b64]
__TI2?AVinvalid_operation@Concurrency@@;

// address=[0x3d11b78]
__CTA2?AVinvalid_operation@Concurrency@@;

// address=[0x3d11b88]
__CT??_R0?AVinvalid_operation@Concurrency@@@8??0invalid_operation@Concurrency@@QAE@ABV01@@Z12;

// address=[0x3d12460]
__TI2?AVdefault_scheduler_exists@Concurrency@@;

// address=[0x3d12474]
__CTA2?AVdefault_scheduler_exists@Concurrency@@;

// address=[0x3d12484]
__CT??_R0?AVdefault_scheduler_exists@Concurrency@@@8??0default_scheduler_exists@Concurrency@@QAE@ABV01@@Z12;

// address=[0x3d124a4]
__TI2?AVimproper_scheduler_reference@Concurrency@@;

// address=[0x3d124b8]
__CTA2?AVimproper_scheduler_reference@Concurrency@@;

// address=[0x3d124c8]
__CT??_R0?AVimproper_scheduler_reference@Concurrency@@@8??0improper_scheduler_reference@Concurrency@@QAE@ABV01@@Z12;

// address=[0x3d124e8]
__TI2?AVimproper_scheduler_attach@Concurrency@@;

// address=[0x3d124fc]
__CTA2?AVimproper_scheduler_attach@Concurrency@@;

// address=[0x3d1250c]
__CT??_R0?AVimproper_scheduler_attach@Concurrency@@@8??0improper_scheduler_attach@Concurrency@@QAE@ABV01@@Z12;

// address=[0x3d1252c]
__TI2?AVimproper_scheduler_detach@Concurrency@@;

// address=[0x3d12540]
__CTA2?AVimproper_scheduler_detach@Concurrency@@;

// address=[0x3d12550]
__CT??_R0?AVimproper_scheduler_detach@Concurrency@@@8??0improper_scheduler_detach@Concurrency@@QAE@ABV01@@Z12;

// address=[0x3d125c8]
__TI3?AVscheduler_worker_creation_error@Concurrency@@;

// address=[0x3d125dc]
__CTA3?AVscheduler_worker_creation_error@Concurrency@@;

// address=[0x3d125f0]
__CT??_R0?AVscheduler_worker_creation_error@Concurrency@@@8??0scheduler_worker_creation_error@Concurrency@@QAE@ABV01@@Z16;

// address=[0x3d12e78]
__TI2?AVmissing_wait@Concurrency@@;

// address=[0x3d12e8c]
__CTA2?AVmissing_wait@Concurrency@@;

// address=[0x3d12e9c]
__CT??_R0?AVmissing_wait@Concurrency@@@8??0missing_wait@Concurrency@@QAE@ABV01@@Z12;

// address=[0x3d12ebc]
__TI2?AVinvalid_multiple_scheduling@Concurrency@@;

// address=[0x3d12ed0]
__CTA2?AVinvalid_multiple_scheduling@Concurrency@@;

// address=[0x3d12ee0]
__CT??_R0?AVinvalid_multiple_scheduling@Concurrency@@@8??0invalid_multiple_scheduling@Concurrency@@QAE@ABV01@@Z12;

// address=[0x3d12f00]
__TI2?AV_Interruption_exception@details@Concurrency@@;

// address=[0x3d12f14]
__CTA2?AV_Interruption_exception@details@Concurrency@@;

// address=[0x3d12f24]
__CT??_R0?AV_Interruption_exception@details@Concurrency@@@8??0_Interruption_exception@details@Concurrency@@QAE@ABV012@@Z12;

// address=[0x3d12fa4]
__TI2?AVinvalid_scheduler_policy_key@Concurrency@@;

// address=[0x3d12fb8]
__CTA2?AVinvalid_scheduler_policy_key@Concurrency@@;

// address=[0x3d12fc8]
__CT??_R0?AVinvalid_scheduler_policy_key@Concurrency@@@8??0invalid_scheduler_policy_key@Concurrency@@QAE@ABV01@@Z12;

// address=[0x3d12fe8]
__TI2?AVinvalid_scheduler_policy_value@Concurrency@@;

// address=[0x3d12ffc]
__CTA2?AVinvalid_scheduler_policy_value@Concurrency@@;

// address=[0x3d1300c]
__CT??_R0?AVinvalid_scheduler_policy_value@Concurrency@@@8??0invalid_scheduler_policy_value@Concurrency@@QAE@ABV01@@Z12;

// address=[0x3d1302c]
__TI2?AVinvalid_scheduler_policy_thread_specification@Concurrency@@;

// address=[0x3d13040]
__CTA2?AVinvalid_scheduler_policy_thread_specification@Concurrency@@;

// address=[0x3d13050]
__CT??_R0?AVinvalid_scheduler_policy_thread_specification@Concurrency@@@8??0invalid_scheduler_policy_thread_specification@Concurrency@@QAE@ABV01@@Z12;

// address=[0x3d136d4]
__TI2?AVcontext_unblock_unbalanced@Concurrency@@;

// address=[0x3d136e8]
__CTA2?AVcontext_unblock_unbalanced@Concurrency@@;

// address=[0x3d136f8]
__CT??_R0?AVcontext_unblock_unbalanced@Concurrency@@@8??0context_unblock_unbalanced@Concurrency@@QAE@ABV01@@Z12;

// address=[0x3d13718]
__TI2?AVcontext_self_unblock@Concurrency@@;

// address=[0x3d1372c]
__CTA2?AVcontext_self_unblock@Concurrency@@;

// address=[0x3d1373c]
__CT??_R0?AVcontext_self_unblock@Concurrency@@@8??0context_self_unblock@Concurrency@@QAE@ABV01@@Z12;

// address=[0x3d1375c]
__TI2?AVinvalid_oversubscribe_operation@Concurrency@@;

// address=[0x3d13770]
__CTA2?AVinvalid_oversubscribe_operation@Concurrency@@;

// address=[0x3d13780]
__CT??_R0?AVinvalid_oversubscribe_operation@Concurrency@@@8??0invalid_oversubscribe_operation@Concurrency@@QAE@ABV01@@Z12;

// address=[0x3d137a0]
__TI2?AVnested_scheduler_missing_detach@Concurrency@@;

// address=[0x3d137b4]
__CTA2?AVnested_scheduler_missing_detach@Concurrency@@;

// address=[0x3d137c4]
__CT??_R0?AVnested_scheduler_missing_detach@Concurrency@@@8??0nested_scheduler_missing_detach@Concurrency@@QAE@ABV01@@Z12;

// address=[0x3d149d8]
__TI3?AV__non_rtti_object@std@@;

// address=[0x3d149ec]
__CTA3?AV__non_rtti_object@std@@;

// address=[0x3d14a00]
__CT??_R0?AV__non_rtti_object@std@@@8??0__non_rtti_object@std@@QAE@ABV01@@Z12;

// address=[0x3d14a20]
__CT??_R0?AVbad_typeid@std@@@8??0bad_typeid@std@@QAE@ABV01@@Z12;

// address=[0x3d14a40]
__TI2?AVbad_typeid@std@@;

// address=[0x3d14a54]
__CTA2?AVbad_typeid@std@@;

// address=[0x3d14b88]
__TI2?AVbad_exception@std@@;

// address=[0x3d14b9c]
__CTA2?AVbad_exception@std@@;

// address=[0x3d14bac]
__CT??_R0?AVbad_exception@std@@@8??0bad_exception@std@@QAE@ABV01@@Z12;

// address=[0x3d788e8]
___pobjMapEntryFirst;

// address=[0x3d789ec]
___pobjMapEntryLast;

// address=[0x3d7a210]
class IAIDifficultyLevels * g_pAIDifficultyLevels;

// address=[0x3d7a214]
class IAIEnvironment * g_pAIEnv;

// address=[0x3d7a3d8]
class IAIMain * g_pAI;

// address=[0x3d7a560]
class IAIScripting * g_pAIScripting;

// address=[0x3d7a6a8]
class IAIShaman * g_pAIShaman;

// address=[0x3d7a758]
int volatile debug;

// address=[0x3d7a764]
bool g_bDbgIsValidHeapPointer;

// address=[0x3d7aae4]
struct SResolutionPair * g_pResolutions;

// address=[0x3d7ab28]
char const * * HACK_STRINGS_ENG;

// address=[0x3d7e738]
char const * * HACK_STRINGS_GER;

// address=[0x3d82348]
char const * * HACK_STRINGS_FRE;

// address=[0x3d885bc]
int g_iCamWndScale;

// address=[0x3d891b0]
bool g_bIsPrivateSession;

// address=[0x3d891b4]
int MAX_LISTENTRIES_COUNT;

// address=[0x3d89408]
wchar_t (* g_szExt)[5];

// address=[0x3d89490]
class IDarkTribe * g_pDarkTribe;

// address=[0x3d897c0]
class CMagic * g_pMagic;

// address=[0x3d897c8]
class INetInputProcessor * g_pNetInputProcessor;

// address=[0x3d899d0]
class ICDDrive * g_pCDDrive;

// address=[0x3d899d4]
class IClipboard * g_pClipboard;

// address=[0x3d89a3c]
class IErrorMessages * g_pErrorMessages;

// address=[0x3d89a58]
wchar_t const * * s_pMissionDiskFiles;

// address=[0x3d89a70]
wchar_t const * * s_pAddOnDiskFiles;

// address=[0x3d89ab4]
wchar_t const * * s_pMissionDisk2Files;

// address=[0x3d89adc]
wchar_t const * * s_pMissionDisk3Files;

// address=[0x3d89b30]
char * * g_pszMapMode;

// address=[0x3d89b4c]
char * * g_pszGameType;

// address=[0x3d89b6c]
class IInstallationInfo * g_pInstallationInfo;

// address=[0x3d89b70]
class IMapCheck * g_pMapCheck;

// address=[0x3d89b74]
wchar_t * FOUR_ISLES_NAME;

// address=[0x3d89b84]
unsigned int FOUR_ISLES_CRC2;

// address=[0x3d89b88]
unsigned int FOUR_ISLES_LEN;

// address=[0x3d89b8c]
wchar_t * AO_SETTLE1_NAME;

// address=[0x3d89ba4]
unsigned int AO_SETTLE1_CRC2;

// address=[0x3d89ba8]
unsigned int AO_SETTLE1_LEN;

// address=[0x3d89bf4]
class IMessageTracer * g_pMsgTracer;

// address=[0x3d89bf8]
class IMessageTracer * g_pMsgTracer2;

// address=[0x3d89c00]
class IRandomMaps * g_pRandomMaps;

// address=[0x3d89c04]
class IRegistry * g_pRegistry;

// address=[0x3d89c20]
char const * * aacMusicStyles;

// address=[0x3d8a084]
unsigned int g_iGameSpeed;

// address=[0x3d8a088]
wchar_t g_iAutosavePrefix;

// address=[0x3d8a08c]
wchar_t * MAP_FILE_EXTENSION;

// address=[0x3d8a810]
char (* g_aszMonthNamesEn)[6];

// address=[0x3d8a858]
char (* g_aszMonthNamesDe)[6];

// address=[0x3d8a968]
struct SRecruiteNeedDesc (* sRecruiteNeedDesc)[10];

// address=[0x3d8ae18]
struct STranslate * g_vSoldierProductionMap;

// address=[0x3d8aeb8]
struct STranslate * slotMap;

// address=[0x3d8b119]
bool g_bDbgDisableAdditionalWaterBuildingCheck;

// address=[0x3d8b590]
struct SSearchData * g_sSearchData;

// address=[0x3d8bb9c]
class IGroupMgr * g_pGroupMgr;

// address=[0x3d8becc]
class IHJBMgr * g_pHJBMgr;

// address=[0x3d8bf00]
int * g_iBackPackCatapultistPercent;

// address=[0x3d8c018]
class IVehicleInfoMgr * g_pVehicleInfoMgr;

// address=[0x3d8c0c8]
int COMMUNICATION_TICK_VALUE;

// address=[0x3d8c0e4]
class IFogging * g_pFogging;

// address=[0x3d8c0e8]
class CScanner * g_pScanner;

// address=[0x3d901d8]
_Curl_cmalloc;

// address=[0x3d901dc]
_Curl_cfree;

// address=[0x3d901e0]
_Curl_crealloc;

// address=[0x3d901e4]
_Curl_cstrdup;

// address=[0x3d901e8]
_Curl_ccalloc;

// address=[0x3d9d05c]
_SSL_version_str;

// address=[0x3d9d130]
_ssl3_undef_enc_method;

// address=[0x3da7068]
_x509_file_lookup;

// address=[0x3dcc738]
_TLSv1_enc_data;

// address=[0x3dcc780]
_TLSv1_1_enc_data;

// address=[0x3dcc7c8]
_TLSv1_2_enc_data;

// address=[0x3dd4e38]
_ssl3_ciphers;

// address=[0x3dd6248]
_SSLv3_enc_data;

// address=[0x3de5870]
_rand_ssleay_meth;

// address=[0x3df46a4]
_x509_dir_lookup;

// address=[0x3e17530]
_DTLSv1_enc_data;

// address=[0x3e17578]
_DTLSv1_2_enc_data;

// address=[0x3e1a450]
_default_pctx;

// address=[0x3e2e228]
int BBSupportLib::g_iBBSDevelopmentFlags;

// address=[0x3e2e22c]
int BBSupportLib::g_iBBSSupportFlags;

// address=[0x3e2e238]
int g_iCameraMode;

// address=[0x3e2e23c]
struct tagRECT g_sMiniMapSize;

// address=[0x3e2e260]
struct GFX_ENGINE_SETUP GfxEngineSetup;

// address=[0x3e2e328]
bool s_bCursorIsVisible;

// address=[0x3e2e32c]
int s_iCurrentCursor;

// address=[0x3e2e330]
struct _DDCOLORKEY g_sColorKeyMagenta555;

// address=[0x3e2e338]
struct _DDCOLORKEY g_sColorKeyMagenta565;

// address=[0x3e2e340]
struct _DDCOLORKEY g_sColorKeyGui;

// address=[0x3e2e378]
int g_iZoomGradient;

// address=[0x3e2e37c]
int g_iCamZoomGradient;

// address=[0x3e2e380]
int g_iZoomInit;

// address=[0x3e2e388]
struct SGfxObject g_sGfxObjectCursorBuilding;

// address=[0x3e2e700]
bool g_bRenderSuccess;

// address=[0x3e2e704]
int g_iFadeYBorder;

// address=[0x3e2e70c]
float g_fVertexSize;

// address=[0x3e2e710]
float g_fCamVertexSize;

// address=[0x3e2f130]
int g_iDialogToIgnore;

// address=[0x3e2f138]
_lua_ident;

// address=[0x3e2f504]
_luaO_typenames;

// address=[0x3e2f598]
_luaO_nilobject;

// address=[0x3e2ff88]
_luaT_eventname;

// address=[0x3e30950]
_reserved;

// address=[0x3e3133c]
int g_iPreviewSize;

// address=[0x3e31340]
unsigned char g_uSnowLimit;

// address=[0x3e32f30]
_LBCarryMask;

// address=[0x3e32f38]
_HBClearMask;

// address=[0x3e32ff0]
_z_errmsg;

// address=[0x3e346d8]
_inflate_mask;

// address=[0x3e519b8]
char * _PJP_CPP_Copyright;

// address=[0x3e51a24]
___security_cookie_complement;

// address=[0x3e51a28]
___security_cookie;

// address=[0x3e51a30]
__fltused;

// address=[0x3e51a40]
__Init_global_epoch;

// address=[0x3e51a50]
int * _RTC_ErrorLevels;

// address=[0x3e51a68]
___isa_enabled;

// address=[0x3e51a70]
void (__stdcall* __errorPfn)(long,struct IErrorInfo *);

// address=[0x3e51b50]
__NLG_Destination;

// address=[0x3e51c00]
__iob;

// address=[0x3e51ccc]
__CrtDbgMode;

// address=[0x3e51cdc]
__CrtDbgFile;

// address=[0x3e51cf0]
___abort_behavior;

// address=[0x3e51d10]
__pctype;

// address=[0x3e51d14]
__pwctype;

// address=[0x3e51d20]
__lookuptrailbytes;

// address=[0x3e51e64]
___mb_cur_max;

// address=[0x3e51f58]
___badioinfo;

// address=[0x3e51fa4]
__pfnAllocHook;

// address=[0x3e521a0]
__mbctype;

// address=[0x3e522d8]
__mbcasemap;

// address=[0x3e526a0]
___dcrt_lowio_console_input_handle;

// address=[0x3e526b0]
__tempoff;

// address=[0x3e526b8]
___globallocalestatus;

// address=[0x3e526c0]
___dcrt_lowio_console_output_handle;

// address=[0x3e526d0]
_AddressFamilyInformation;

// address=[0x3e86998]
??____@@_PchSym_@00@UkilqvxghUghsvUkfikovoznkUhEUhlfixvUxlnkrovPgvnkUhEPnzrmUwvyftUhgwzucOlyq@DAB0C180318CE37B;

// address=[0x3e951d8]
unsigned __int64 `__local_stdio_printf_options'::`2'::_OptionsStorage;

// address=[0x3e951e8]
class CAIPlayerEvaluations g_cAIPlayerEvaluations;

// address=[0x3e95500]
class CAIRegions g_cAIRegions;

// address=[0x3e95804]
class CAIConfigInt g_cAIDarkTribeCostMushroomFarmer;

// address=[0x3e95810]
class CAIConfigInt g_cAIDarkTribeCostDarkGardener;

// address=[0x3e9581c]
class CAIConfigInt g_cAIDarkTribeCostShaman;

// address=[0x3e95828]
class CAIConfigInt g_cAIDarkTribeCostSwordsman;

// address=[0x3e95834]
class CAIConfigInt g_cAIDarkTribeCostBowman;

// address=[0x3e95840]
class CAIConfigInt g_cAIDarkTribeMushroomFarmCreationDelay;

// address=[0x3e97780]
class CAIResourceMap g_cAIResourceMap;

// address=[0x3ecb830]
class CAIPlayersScriptVars g_cAIPlayersScriptVars;

// address=[0x3eccd20]
class CAITaskForces g_cAITaskForces;

// address=[0x3ecd470]
class CAIDarkTribe * g_pAIDarkTribe;

// address=[0x3ecd500]
int volatile * volatile DEBUG_FLAGS;

// address=[0x3ecd9d4]
int g_iDbgTickCounter;

// address=[0x3ecd9d8]
void * g_pDbgValidHeapPointer;

// address=[0x3ecda58]
unsigned int g_iApplicationVersionMajor;

// address=[0x3ecda5c]
unsigned int g_iApplicationVersionMinor;

// address=[0x3ecda60]
unsigned int g_iApplicationVersionBuild;

// address=[0x3ecda64]
unsigned int g_iScriptVersion;

// address=[0x3ecda68]
unsigned int g_iConfigVersion;

// address=[0x3ecda6c]
unsigned int g_iGfxVersion;

// address=[0x3ecda70]
struct HWND__ * g_hWnd;

// address=[0x3ecda74]
struct HINSTANCE__ * g_hInstance;

// address=[0x3ecda78]
char * g_strTitleEx;

// address=[0x3ecdadc]
unsigned int g_iFileVersionMS;

// address=[0x3ecdae0]
char * g_strSerial;

// address=[0x3ecdb44]
unsigned int g_iFileVersionLS;

// address=[0x3ecdb48]
char * * g_pArgv;

// address=[0x3ecdb4c]
unsigned int g_iArgc;

// address=[0x3ecdbe8]
class CGameData * g_pGameData;

// address=[0x3ecdbf1]
bool g_bGfxHJBLoadSpecialGfx;

// address=[0x3ecde90]
class CScrollMultiline s_cAOScrolltext;

// address=[0x3ece818]
bool g_bGuiSplashInitDone;

// address=[0x3ece820]
class CScrollMultiline s_cAOSplashScrolltext;

// address=[0x3ecfa3c]
unsigned short g_uCamWndEntityId;

// address=[0x3ecfa40]
int g_iCamWndUniqueId;

// address=[0x3ecfa44]
class IEntity * pCamWndEntity;

// address=[0x3ecfa48]
int g_iCamWndX;

// address=[0x3ecfa4c]
int g_iCamWndY;

// address=[0x3ecfa58]
class CScrollMultiline s_cScrolltext;

// address=[0x3ed0400]
int s_iMainDeteilStatisticTopOffset;

// address=[0x3ed0404]
int iItemNumber;

// address=[0x3ed0408]
struct SDetailStatisticItem * sDetailStatisticList;

// address=[0x3ed2070]
class CGuiChatMsgList s_cMsgLst;

// address=[0x3eddca0]
int s_iMainLoadTopOffset;

// address=[0x3eddcb0]
unsigned char g_uiExtrasAllowed;

// address=[0x3eddcb1]
bool g_bNewTextures;

// address=[0x3eddcb4]
int g_iMapListTopOffset;

// address=[0x3eddd04]
std::string g_iMessageBoxStringID;

// address=[0x3eddd28]
struct CONTROL (* aControls)[16];

// address=[0x3ede628]
int iStatus;

// address=[0x3ede800]
class CScrollMultiline s_cMD2Scrolltext;

// address=[0x3edf188]
class CScrollMultiline s_cMDScrolltext;

// address=[0x3edfb50]
class CGuiMsgList s_cMsgLst;

// address=[0x3efd446]
bool g_bOpenSidebar;

// address=[0x3efd620]
class CScrollMultiline s_cXMD3Scrolltext;

// address=[0x3efdfa8]
private: static class cdm_crc::CRCGenerator<16,32773,0,0,1,1>::CRCTable const cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Table;

// address=[0x3efe4c0]
class CAttackMsgList g_cAttackMsgList;

// address=[0x3efeb30]
class CEcoSectorMgr g_cESMgr;

// address=[0x3f122c8]
class CEndStatistic g_cEndStatistic;

// address=[0x3f1e498]
class CInfoExchangeEx g_cInfoExchange;

// address=[0x3f1e4a0]
class CInfoExchangeInt g_cInfoExchangeInt;

// address=[0x3f1e4ac]
class CBuildingInfoEx g_cBuildingInfo;

// address=[0x3f1e4c0]
class CBuildingSiteInfo g_cBuildingSiteInfo;

// address=[0x3f1e4e4]
class CResourceCollectorInfo g_cResourceCollectorInfo;

// address=[0x3f1e4fc]
class CResourceUpgradeInfo g_cResourceUpgradeInfo;

// address=[0x3f1e530]
class CMilitaryBuildingInfo g_cMilitaryBuildingInfo;

// address=[0x3f1e56c]
class CPortInfo g_cPortInfo;

// address=[0x3f1e5a0]
class CStorageInfo g_cStorageInfo;

// address=[0x3f1e5c8]
class CSmallTempleInfo g_cSmallTempleInfo;

// address=[0x3f1e5e4]
class CBarracksInfo g_cBarracksInfo;

// address=[0x3f1e604]
class CVehicleProductionInfo g_cVehicleProductionInfo;

// address=[0x3f1e62c]
class CExtendedMenuInfo g_cExtendedMenuInfo;

// address=[0x3f1e660]
class CSoldierInfo g_cSoldierInfo;

// address=[0x3f1e6f8]
class CSpecialistsInfo g_cSpecialistsInfo;

// address=[0x3f1e73c]
class CVehicleInfo g_cVehicleInfo;

// address=[0x3f1e75c]
class CGroupSideBarInfo g_cGroupSideBarInfo;

// address=[0x3f1e788]
class CVehicleLoadInfo g_cVehicleLoadInfo;

// address=[0x3f1e88c]
class CFerryLoadInfo g_cFerryLoadInfo;

// address=[0x3f1e8c4]
class CWeaponSideBarInfo g_cWeaponSideBarInfo;

// address=[0x3f1e900]
struct SBuildingMenu g_sBuildingMenu;

// address=[0x3f1e9ac]
class CPortGoodsOutBarInfo g_cPortGoodsOutBarInfo;

// address=[0x3f1e9e0]
class CSettlerStatisticInfo g_cSettlerStatisticInfo;

// address=[0x3f1eb28]
class CSettlerProductionInfo g_cSettlerProductionInfo;

// address=[0x3f1ebc8]
class CFreeCarrierInfo g_cFreeCarrierInfo;

// address=[0x3f1ec00]
class CGoodsStatisticInfo g_cGoodsStatisticInfo;

// address=[0x3f1ed64]
class CPortGoodsTradeBarInfo g_cPortTradeBarInfo;

// address=[0x3f1eda0]
class CTransportpriorityInfo g_cTransportpriorityInfo;

// address=[0x3f1ee28]
class CGoodDistributionInfo g_cGoodDistributionInfo;

// address=[0x3f1ee6c]
class CAddVehicleBarInfo g_cVehicleSideBarInfo;

// address=[0x3f1ee80]
class CEconomyGameInfo g_cEconomyGameInfo;

// address=[0x3f1eee0]
class CMagicSpellSideBarInfo g_cMagicSpellSideBarInfo;

// address=[0x3f1ef68]
class CAddSoldierSideBarInfo g_cAddSoldierSideBarInfo;

// address=[0x3f1ef80]
class CAddToolSideBarInfo g_cAddToolSideBarInfo;

// address=[0x3f1ef90]
class CEyeCatcherBarInfo g_cEyeCatcherBarInfo;

// address=[0x3f1f058]
class CStorageSideBarInfo g_cStorageSideBarInfo;

// address=[0x3f1f648]
class CInputProcessor g_cInputProcessor;

// address=[0x3f1f7d0]
double lastTime;

// address=[0x3f1f7d8]
class CPerformanceCounter cTimer;

// address=[0x3f20328]
class CStatistic g_cStatistic;

// address=[0x3f2bca0]
class CStatisticArchive g_cStatisticArchive;

// address=[0x3f44ac8]
class CTutorial g_cTutorial;

// address=[0x3f450a0]
class IExtraCD * g_pMissionCD;

// address=[0x3f450a4]
class IExtraCD * g_pAddOn;

// address=[0x3f450a8]
class IExtraCD * g_pMissionCD2;

// address=[0x3f450ac]
class IExtraCD * g_pMissionCD3;

// address=[0x3f450c0]
unsigned int g_iAITicks;

// address=[0x3f450c4]
unsigned int g_iLogicTicks;

// address=[0x3f450c8]
unsigned int g_iTilingTicks;

// address=[0x3f450cc]
unsigned int g_iScriptingTicks;

// address=[0x3f450d0]
unsigned int g_iAnimalTicks;

// address=[0x3f455f0]
class IGfxEngine * g_pGfxEngine;

// address=[0x3f455f4]
class IRTComp * g_pRTComp;

// address=[0x3f45628]
class CGfxManager * g_pGfxManager;

// address=[0x402bdc0]
class CPlayerManager g_cPlayerMgr;

// address=[0x402c930]
int g_iAOSplashType;

// address=[0x402c978]
class CBriefingSettings g_cBriefingSettings;

// address=[0x402cbb8]
class CCampaignSettings g_cCampaignSettings;

// address=[0x402cc54]
int iScreenFlag;

// address=[0x402cc60]
char * g_szBugReportText;

// address=[0x402ec60]
bool g_bBugReportScreenshot;

// address=[0x402ec68]
union _LARGE_INTEGER g_lFrequency;

// address=[0x402ec70]
class CGameType * g_pGameType;

// address=[0x4030370]
class CSaveGameContext g_cSaveGameContext;

// address=[0x4030710]
class CLanLobbyConnect g_cLobbyConnectInfo;

// address=[0x40307c8]
class CLanLobbyGameSettings g_cLobbyGameInfo;

// address=[0x4031910]
class CLanLobbyMapSettings g_cLobbyMapInfo;

// address=[0x4031cf8]
class CLocalTypeSettings g_cLocalTypeSettings;

// address=[0x4031d10]
char * g_pDialogData;

// address=[0x4031f80]
struct SRandomMapParams g_sRMP;

// address=[0x40320b8]
class CTutorialSettings g_cTutorialStatus;

// address=[0x403212c]
int g_iVictoryScreenCampaignType;

// address=[0x4032238]
class CTextMsgHandler g_cTextMsgHandler;

// address=[0x4032ee0]
class CAnimalMgr g_cAnimalMgr;

// address=[0x4035298]
class CBuildingInfoMgr g_cBuildingInfoMgr;

// address=[0x409cae0]
class CBuildingMgr g_cBuildingMgr;

// address=[0x40f2320]
class CDecoObjMgr g_cDecoObjMgr;

// address=[0x40ff380]
class CFlyingMgr g_cFlyingMgr;

// address=[0x415205c]
class CPileMgr g_cPileMgr;

// address=[0x41521dc]
unsigned int g_uSaboteurHitChange;

// address=[0x41521e0]
class CSettlerMgr g_cSettlerMgr;

// address=[0x4157a68]
int * g_iBlowgunWarriorFreezeChange;

// address=[0x4158d00]
class CVehicleMgr g_cVehicleMgr;

// address=[0x415ad38]
int Version;

// address=[0x415b804]
class CStaticConfigVarInt g_iNetClientTimeOut;

// address=[0x415b810]
class CStaticConfigVarInt g_iNetSearchHostRetries;

// address=[0x415b81c]
class CStaticConfigVarInt g_iNetSenderPort;

// address=[0x415b828]
class CStaticConfigVarInt g_iNetReceiverPort;

// address=[0x415b834]
class CStaticConfigVarInt g_iNotReadyWarnDelay;

// address=[0x415b840]
class CStaticConfigVarInt g_iNotReadyWarnAgainDelay;

// address=[0x415b84c]
class CStaticConfigVarInt g_iNotReadyKickDelay;

// address=[0x415b858]
class CStaticConfigVarInt g_iNotReadyGameStartTimeout;

// address=[0x415b864]
class CStaticConfigVarInt g_iNetworkTimeDelta;

// address=[0x415b870]
class CStaticConfigVarInt g_iNetAfterLobbyConnectTimeout;

// address=[0x415b87c]
class CStaticConfigVarInt g_iNetClientWaitingStartTick;

// address=[0x415b888]
class CStaticConfigVarInt g_iHostWaitAfterLobbyForClientsTimeout;

// address=[0x415b894]
class CStaticConfigVarInt g_iResendTimeout;

// address=[0x415b8a0]
class CStaticConfigVarInt g_iPingGood;

// address=[0x415b8ac]
class CStaticConfigVarInt g_iPingAverage;

// address=[0x415b8b8]
class CStaticConfigVarInt g_iSaveingTimeout;

// address=[0x415c3b0]
class CAlliances g_cAlliances;

// address=[0x415c768]
class CAStarTiling g_cAStarTiling;

// address=[0x415c778]
class CAStar64Normal g_cAStar64Normal;

// address=[0x415c77c]
class CAStar64Worker g_cAStar64Worker;

// address=[0x415c780]
class CAStar64Catapult g_cAStar64Catapult;

// address=[0x415c784]
class CAStar64Ship g_cAStar64Ship;

// address=[0x41799e8]
class CInfluMap g_cInfluMap;

// address=[0x418fe58]
class COwnerMapEx g_cOwnerMap;

// address=[0x45b2048]
class CWarMap g_cWarMap;

// address=[0x4617a98]
class CShipMap g_cShipMap;

// address=[0x4617a99]
class CWaterFlags g_cWaterFlags;

// address=[0x46282b0]
class CWater g_cWater;

// address=[0x462b784]
unsigned int g_uDbgTickCounter;

// address=[0x462b788]
class CSoundManager * g_pSoundManager;

// address=[0x462b78c]
class CMapObjectMgr * g_pMapObjectMgr;

// address=[0x462b790]
class CStateGame * g_pGame;

// address=[0x462b794]
class IGuiEngine * g_pGUIEngine;

// address=[0x462b798]
class ISoundEngine * g_pSoundEngine;

// address=[0x462b79c]
class IVideoEngine * g_pVideoEngine;

// address=[0x462b7a0]
class CStringEngine * g_pStringEngine;

// address=[0x462b7a4]
class CEntityToDoListMgr * g_pEntityToDoListMgr;

// address=[0x462b7a8]
class CLogic * g_pLogic;

// address=[0x462b7ac]
class CGuiEventHandler * g_pGuiMainEvents;

// address=[0x462b7b0]
class INetworkEngine * g_pNetworkEngine;

// address=[0x462b7b4]
class IConfigManager * g_pCfgMgr;

// address=[0x462b828]
class CGameScriptManager * g_pScriptMgr;

// address=[0x462b830]
int iType;

// address=[0x462b834]
char * pszTypeString;

// address=[0x462b874]
___@@_PchSym_@00@UkilqvxghUghsvUkfikovoznkUhEUhlfixvUxlnkrovPgvnkUhEPnzrmUwvyftUhgwzucOlyq@DAB0C180318CE37B;

// address=[0x462bcd4]
class CBinkInterface * g_pVideo;

// address=[0x462c858]
class CWorldManager g_cWorld;

// address=[0x462c860]
class CLandscapeProperties g_cLandscapeProperties;

// address=[0x462cc1d]
char JobRequestPrimaryStoreItemsCatalog_BF::dummy;

// address=[0x462cc1e]
char JobRequestPrimaryStoreInventory_BF::dummy;

// address=[0x462cf38]
unsigned __int64 `__local_stdio_scanf_options'::`2'::_OptionsStorage;

// address=[0x462d0a4]
_Curl_ack_eintr;

// address=[0x462d26c]
_OPENSSL_NONPIC_relocated;

// address=[0x462edf0]
_obj_cleanup_defer;

// address=[0x462eea4]
_app_pkey_methods;

// address=[0x463a52c]
_g_callbackAlloc;

// address=[0x463a530]
_g_callbackRealloc;

// address=[0x463a534]
_g_callbackFree;

// address=[0x46549e8]
bool SIMPL_NS::g_memoryLeakAtShutdown;

// address=[0x46549e9]
bool SIMPL_NS::g_memoryCorruption;

// address=[0x46549f0]
unsigned __int64 SIMPL_NS::g_allocations_current;

// address=[0x46549f8]
unsigned __int64 SIMPL_NS::g_allocations_total_count;

// address=[0x4654a00]
unsigned __int64 SIMPL_NS::g_allocations_total_size;

// address=[0x4654a09]
bool `anonymous namespace'::g_SimplThreadKill;

// address=[0x4654a10]
struct _RTL_CRITICAL_SECTION `anonymous namespace'::g_SimplLogLock;

// address=[0x4654a28]
struct _RTL_CRITICAL_SECTION `anonymous namespace'::g_SimplFileLock;

// address=[0x4654a40]
struct _RTL_CRITICAL_SECTION `anonymous namespace'::g_SimplRequestArrayLock;

// address=[0x4654a58]
unsigned int `anonymous namespace'::g_SimplFileThread;

// address=[0x4654a5c]
unsigned int `anonymous namespace'::SimplReqArrayRead;

// address=[0x4654a60]
struct A0xd84a0158::SRequest * `anonymous namespace'::SimplRequests;

// address=[0x4654c40]
unsigned int `anonymous namespace'::SimplReqArrayWrite;

// address=[0x4654c48]
unsigned __int64 g_InitCount;

// address=[0x4654ce8]
unsigned __int64 g_EalToFAPTimeFactor;

// address=[0x46851a9]
class CConfigManagerPtr g_cConfigManagerPtr;

// address=[0x46853c8]
class CFileLibrary g_cFileLibrary;

// address=[0x46856dc]
class std::map<std::string,char,struct std::less<std::string >,class std::allocator<struct std::pair<std::string const ,char> > > AdvXMLParser::s_mapReferences;

// address=[0x46869b0]
class CFileMgr g_cFileMgr;

// address=[0x4686d50]
class BBSupportLib::CBBSupportTraceFilePtr BBSupportLib::g_pBBSTraceFile;

// address=[0x4687114]
int BBSupportLib::g_iBBSErrorhandlingMode;

// address=[0x4687118]
int BBSupportLib::g_iBBSIsDevelopmentMachine;

// address=[0x468711c]
int BBSupportLib::g_iBBSDeveloperErrorHandling;

// address=[0x468719c]
class IConfigManager * l_pCfgMgr;

// address=[0x4689a68]
unsigned int * g_pTickCounter;

// address=[0x4689a6c]
bool g_bExclusive;

// address=[0x4689a70]
void * g_pDirectDraw;

// address=[0x4689a74]
int g_iTextTmpPosX;

// address=[0x4689a78]
char * g_cTextTmp;

// address=[0x4689b78]
int g_iTextTmpPosY;

// address=[0x4689b7c]
int g_iTextTmpWidth;

// address=[0x4689b80]
int g_iTextTmpHeight;

// address=[0x4689b84]
int g_iTextTmpColor;

// address=[0x4689b88]
int g_iRefreshWaitFrames;

// address=[0x4689b8c]
struct tagRECT g_sMiniMapRect;

// address=[0x4689be0]
class CInterfaceD3D * D3DObjectPtr;

// address=[0x4689be4]
void * g_pBorderstonePalette;

// address=[0x4689be8]
void * * g_pWavePalettes;

// address=[0x4689c30]
void * * g_pWaveGfx;

// address=[0x468a1d0]
void * * g_pBorderstoneGfx;

// address=[0x468a1f4]
unsigned char * g_uWaveFrames;

// address=[0x468a206]
unsigned char g_uBorderstoneFrames;

// address=[0x468a207]
bool s_bCursorIsFixed;

// address=[0x468a208]
int * g_iWaveIndices;

// address=[0x468a250]
int g_iBorderstoneIndices;

// address=[0x468a254]
struct HICON__ * s_hCursor;

// address=[0x468a258]
struct HICON__ * * s_hCursorHandles;

// address=[0x468a2e8]
struct _DDCOLORKEY g_sColorKeyBlack;

// address=[0x468a2f0]
void * (__cdecl* g_pfForceReload)(int,bool,bool);

// address=[0x468a2f8]
class CBlitFX g_cBlitFX;

// address=[0x468a5e0]
unsigned short * g_uColorPalette;

// address=[0x468a7e0]
void * g_pRenderAdress;

// address=[0x468a7e4]
void * g_pBeginOfRenderBuffer;

// address=[0x468a7e8]
void * g_pEndOfRenderBuffer;

// address=[0x468a7ec]
int g_iRenderPitch;

// address=[0x468a7f0]
int g_iScanlineLength;

// address=[0x468a7f4]
int * g_pPreCalculatedGradients;

// address=[0x468a7f8]
int * g_iDestSizeTable;

// address=[0x468aff8]
int * g_iCamDestSizeTable;

// address=[0x468b7f8]
int * g_pDestSizeTable;

// address=[0x468b7fc]
int * g_pZoomGradient;

// address=[0x468b800]
bool (__cdecl* g_pfBlitSettler)(int,int,int,struct SGfxObjectInfo *);

// address=[0x468b804]
bool (__cdecl* g_pfBlitObject)(int,int,int,struct SGfxObjectInfo *);

// address=[0x468b808]
bool (__cdecl* g_pfBlitVehicle)(int,int,int,struct SGfxObjectInfo *);

// address=[0x468b80c]
bool (__cdecl* g_pfBlitBuilding)(int,int,int,struct SGfxObjectInfo *,int *,int &);

// address=[0x468b810]
bool (__cdecl* g_pfBlitBorderstone)(int,int,int,int);

// address=[0x468b814]
bool (__cdecl* g_pfBlitAccessoryIcon)(int,int,int,int);

// address=[0x468b818]
bool (__cdecl* g_pfBlitWave)(int,int,int,int,int);

// address=[0x468b81c]
void * g_pIconPalette;

// address=[0x468b820]
void * * g_pIconGfx;

// address=[0x468bc20]
int (* g_iSettlerSelections)[3];

// address=[0x468c0dc]
int g_iSettlerSelectionCounter;

// address=[0x468c0e0]
int (* g_iSettlerFitness)[5];

// address=[0x468c8c4]
int g_iSettlerFitnessCounter;

// address=[0x468c8c8]
int (* g_iSettlerMagic)[5];

// address=[0x468d0ac]
int g_iSettlerMagicCounter;

// address=[0x468d0b0]
struct SGfxObjectInfo * (__cdecl* g_pfGetGfxObjectInfo)(unsigned int,int);

// address=[0x468d0b4]
void (__cdecl* g_pfSetNumberOfNextLine)(int);

// address=[0x468d0b8]
unsigned char (__cdecl* g_pfGetIconObjectByX)(int);

// address=[0x468d0bc]
int (__cdecl* g_pfGetOwnerID)(int);

// address=[0x468d0c0]
class IGfxEffects * s_pEffectSystem;

// address=[0x468d0c8]
class CColorGradient g_cColorGradient;

// address=[0x468dc44]
void * `void __cdecl ZoomBobBuildState(void *,void *,int,int,int,int,int,void *,void *)'::`2'::s_pSourceAdress;

// address=[0x468dc48]
void * `void __cdecl ZoomBobBuildState(void *,void *,int,int,int,int,int,void *,void *)'::`2'::s_pPaletteAdress;

// address=[0x468dc4c]
void * `void __cdecl ZoomBobBuildState(void *,void *,int,int,int,int,int,void *,void *)'::`2'::s_pUpperClippingBorder;

// address=[0x468dc50]
void * `void __cdecl ZoomBobBuildState(void *,void *,int,int,int,int,int,void *,void *)'::`2'::s_pLowerClippingBorder;

// address=[0x468dc54]
int `void __cdecl ZoomBobBuildState(void *,void *,int,int,int,int,int,void *,void *)'::`2'::s_iSourceWidth;

// address=[0x468dc58]
int `void __cdecl ZoomBobBuildState(void *,void *,int,int,int,int,int,void *,void *)'::`2'::s_iSourceHeight;

// address=[0x468dc5c]
int `void __cdecl ZoomBobBuildState(void *,void *,int,int,int,int,int,void *,void *)'::`2'::s_iDestWidth;

// address=[0x468dc60]
int `void __cdecl ZoomBobBuildState(void *,void *,int,int,int,int,int,void *,void *)'::`2'::s_iDestHeight;

// address=[0x468dc64]
int `void __cdecl ZoomBobBuildState(void *,void *,int,int,int,int,int,void *,void *)'::`2'::s_iDestX;

// address=[0x468dc68]
int `void __cdecl ZoomBobBuildState(void *,void *,int,int,int,int,int,void *,void *)'::`2'::s_iDestY;

// address=[0x468dc6c]
int `void __cdecl ZoomBobBuildState(void *,void *,int,int,int,int,int,void *,void *)'::`2'::s_iUpperClippingLine;

// address=[0x468dc70]
unsigned int `void __cdecl ZoomBobBuildState(void *,void *,int,int,int,int,int,void *,void *)'::`2'::s_pBeginOfScanline;

// address=[0x468dc74]
unsigned int `void __cdecl ZoomBobBuildState(void *,void *,int,int,int,int,int,void *,void *)'::`2'::s_pBeginOfScanlineQuery;

// address=[0x468dc78]
unsigned int `void __cdecl ZoomBobBuildState(void *,void *,int,int,int,int,int,void *,void *)'::`2'::s_pEndOfScanline;

// address=[0x468dc7c]
int `void __cdecl ZoomBobBuildState(void *,void *,int,int,int,int,int,void *,void *)'::`2'::s_iStartOfDestLine;

// address=[0x468dc80]
int `void __cdecl ZoomBobBuildState(void *,void *,int,int,int,int,int,void *,void *)'::`2'::s_iGradientY;

// address=[0x468dc84]
int `void __cdecl ZoomBobBuildState(void *,void *,int,int,int,int,int,void *,void *)'::`2'::s_iStartOfDestLineRest;

// address=[0x468dc88]
int `void __cdecl ZoomBobBuildState(void *,void *,int,int,int,int,int,void *,void *)'::`2'::s_iBufferedPixelCounterEbx;

// address=[0x468dc8c]
int `void __cdecl ZoomBobBuildState(void *,void *,int,int,int,int,int,void *,void *)'::`2'::s_iBufferedPixelCounterEcx;

// address=[0x468dc90]
int `void __cdecl ZoomBobBuildState(void *,void *,int,int,int,int,int,void *,void *)'::`2'::s_iSourceLineStart;

// address=[0x468dc94]
int `void __cdecl ZoomBobBuildState(void *,void *,int,int,int,int,int,void *,void *)'::`2'::s_iZoom;

// address=[0x468dc98]
void * `void __cdecl ZoomBobNormal(void *,void *,int,int,int,int,int,void *,int)'::`2'::s_pSourceAdress;

// address=[0x468dc9c]
void * `void __cdecl ZoomBobNormal(void *,void *,int,int,int,int,int,void *,int)'::`2'::s_pPaletteAdress;

// address=[0x468dca0]
void * `void __cdecl ZoomBobNormal(void *,void *,int,int,int,int,int,void *,int)'::`2'::s_pUpperClippingBorder;

// address=[0x468dca4]
void * `void __cdecl ZoomBobNormal(void *,void *,int,int,int,int,int,void *,int)'::`2'::s_pLowerClippingBorder;

// address=[0x468dca8]
int `void __cdecl ZoomBobNormal(void *,void *,int,int,int,int,int,void *,int)'::`2'::s_iSourceWidth;

// address=[0x468dcac]
int `void __cdecl ZoomBobNormal(void *,void *,int,int,int,int,int,void *,int)'::`2'::s_iSourceHeight;

// address=[0x468dcb0]
int `void __cdecl ZoomBobNormal(void *,void *,int,int,int,int,int,void *,int)'::`2'::s_iDestWidth;

// address=[0x468dcb4]
int `void __cdecl ZoomBobNormal(void *,void *,int,int,int,int,int,void *,int)'::`2'::s_iDestHeight;

// address=[0x468dcb8]
int `void __cdecl ZoomBobNormal(void *,void *,int,int,int,int,int,void *,int)'::`2'::s_iDestX;

// address=[0x468dcbc]
int `void __cdecl ZoomBobNormal(void *,void *,int,int,int,int,int,void *,int)'::`2'::s_iDestY;

// address=[0x468dcc0]
int `void __cdecl ZoomBobNormal(void *,void *,int,int,int,int,int,void *,int)'::`2'::s_iUpperClippingLine;

// address=[0x468dcc4]
unsigned int `void __cdecl ZoomBobNormal(void *,void *,int,int,int,int,int,void *,int)'::`2'::s_pBeginOfScanline;

// address=[0x468dcc8]
unsigned int `void __cdecl ZoomBobNormal(void *,void *,int,int,int,int,int,void *,int)'::`2'::s_pBeginOfScanlineQuery;

// address=[0x468dccc]
unsigned int `void __cdecl ZoomBobNormal(void *,void *,int,int,int,int,int,void *,int)'::`2'::s_pEndOfScanline;

// address=[0x468dcd0]
int `void __cdecl ZoomBobNormal(void *,void *,int,int,int,int,int,void *,int)'::`2'::s_iStartOfDestLine;

// address=[0x468dcd4]
int `void __cdecl ZoomBobNormal(void *,void *,int,int,int,int,int,void *,int)'::`2'::s_iGradientY;

// address=[0x468dcd8]
int `void __cdecl ZoomBobNormal(void *,void *,int,int,int,int,int,void *,int)'::`2'::s_iSourceLineStart;

// address=[0x468dcdc]
int `void __cdecl ZoomBobNormal(void *,void *,int,int,int,int,int,void *,int)'::`2'::s_iStartOfDestLineRest;

// address=[0x468dce0]
int `void __cdecl ZoomBobNormal(void *,void *,int,int,int,int,int,void *,int)'::`2'::s_iBufferedPixelCounterEbx;

// address=[0x468dce4]
int `void __cdecl ZoomBobNormal(void *,void *,int,int,int,int,int,void *,int)'::`2'::s_iBufferedPixelCounterEcx;

// address=[0x468dce8]
int `void __cdecl ZoomBobNormal(void *,void *,int,int,int,int,int,void *,int)'::`2'::s_iZoom;

// address=[0x468e3a8]
int g_iMapSize;

// address=[0x468e3ac]
unsigned char * g_pLuminanceTablesMemory;

// address=[0x468e3b0]
unsigned char * g_pLuminanceTablesStart;

// address=[0x468e3bc]
unsigned char * CurrentTexturePagePtr;

// address=[0x468e3c0]
unsigned char * * g_pTextureTable;

// address=[0x468e470]
unsigned char (* g_uColorPalettes)[768];

// address=[0x4696870]
unsigned char * g_pSoftwareTexturePages;

// address=[0x4696874]
bool g_bRiverMouth;

// address=[0x4696875]
bool g_bHalfLine;

// address=[0x4696876]
bool g_bSplitTriangle;

// address=[0x4696878]
struct TRIANGLE_CROSSING (* PatternTripleVertices)[4][6];

// address=[0x4697178]
unsigned char * g_uMaxYTable;

// address=[0x4697578]
int g_iLastUsedPage;

// address=[0x469757c]
float g_fPatternSuboffsetX;

// address=[0x4697580]
float g_fPatternSuboffsetY;

// address=[0x4697584]
int s_iDarkTribeElement;

// address=[0x4697588]
int g_iFogFadeStep;

// address=[0x469758c]
int g_iUsedFogFadeStep;

// address=[0x4697590]
class CHeightAndTypeTable g_cHeightAndTypeTable;

// address=[0x46c169c]
int s_iObjectOffsetX;

// address=[0x46c1ea4]
int s_iObjectOffsetY;

// address=[0x46c1ea8]
class CBlitFX s_cBlitFx;

// address=[0x46c6710]
class CSurfaceDescription s_cSurfaceDescription;

// address=[0x46c67f8]
class CBlitFX s_cBlitFxAlpha;

// address=[0x46c6860]
class CBlitFX s_cBlitFxAlphaDebug;

// address=[0x46c7e50]
struct SGfxColor * (__cdecl* g_pfGetGfxMiniMapColor)(unsigned int);

// address=[0x46c7e58]
class CLandscapeColorProperties g_cLandscapeColorProperties;

// address=[0x46f32d0]
class CCacheManager g_cCacheManager;

// address=[0x471f790]
struct GUI_MENU_FILE_HEADER * g_pFileHeader;

// address=[0x471f79c]
int * g_iOpenDialogs;

// address=[0x471f7d4]
bool (__cdecl** g_pfDialogCallbacks)(int,int,int);

// address=[0x471f80c]
struct SGuiControl * g_pCurrentSelectedControl;

// address=[0x471f810]
struct SGuiControl * g_pCurrentDragControl;

// address=[0x471f814]
struct SGuiControl * g_pCurrentEditControl;

// address=[0x471f818]
struct SGuiControl * g_pCurrentRepeatControl;

// address=[0x471f820]
int * g_iEditWidthTable;

// address=[0x471fcd0]
char (* g_mbstrTextTable)[300];

// address=[0x4725a90]
bool * g_bUsedTexts;

// address=[0x4726ec8]
struct HFONT__ * * g_hFonts;

// address=[0x4726f14]
bool g_bDisableEvents;

// address=[0x4726f15]
bool g_bGuiIsDirty;

// address=[0x4726f18]
bool (__cdecl* g_pfSetEnableStatus)(int,int,int,bool,int);

// address=[0x4726f1c]
int g_iAlignMode;

// address=[0x4726f20]
unsigned short * g_uShadeTable1;

// address=[0x4726f40]
unsigned short * g_uShadeTable2;

// address=[0x4726f60]
int g_iStdShadeColor;

// address=[0x4726f64]
int g_iLeftShadeColor;

// address=[0x4726f68]
int g_iRightShadeColor;

// address=[0x4726f90]
class CToolTip g_cToolTip;

// address=[0x47270e8]
class CToolTipExt g_cToolTipExt;

// address=[0x4727548]
_lua_state;

// address=[0x4727558]
struct EDITOR_INFO g_sEditorInfo;

// address=[0x472756c]
struct SEditorGlobalMapData g_sGeneralMapData;

// address=[0x4727584]
bool g_bMapIsLoaded;

// address=[0x4727588]
short * g_pPreviewGfx;

// address=[0x472758c]
char * g_pTextDescription;

// address=[0x4727590]
char * g_pTextTandT;

// address=[0x4727594]
char * g_pTextEnglishDescription;

// address=[0x4727598]
char * g_pTextEnglishTandT;

// address=[0x472759c]
int g_bEditorMap;

// address=[0x47275a0]
int g_bAddOnMap;

// address=[0x47275a4]
int g_bCampaign;

// address=[0x47275a8]
int g_bSettlersAvailable;

// address=[0x47275ac]
int g_bBuildingsAvailable;

// address=[0x47275b0]
int g_bPilesAvailable;

// address=[0x47275b8]
class CPlayerData g_cPlayerAndTeamData;

// address=[0x47279d4]
struct T_GFX_MAP_ELEMENT * g_pMapElement;

// address=[0x47279d8]
int g_iWorldSize;

// address=[0x47279dc]
struct SEditorElementMap * g_pEditorLayer;

// address=[0x47279e0]
class IMapGeneratorHost * g_pHost;

// address=[0x47279e4]
float g_fScaleFactor;

// address=[0x47279e8]
unsigned char g_uResourceWealth;

// address=[0x47279e9]
unsigned char g_iNumPlayers;

// address=[0x47279ea]
bool g_bNoObjects;

// address=[0x47279ec]
class CPlayerData * * g_pPlayerData;

// address=[0x47279f0]
class CBasicGrid * g_pBasicGrid;

// address=[0x47279f4]
class CFeatureGrid * g_pFeatureGrid;

// address=[0x47279f8]
int g_iLandMassPercent;

// address=[0x47279fc]
int g_iFlags;

// address=[0x4727a00]
unsigned short * g_pPreviewImage;

// address=[0x4727a04]
int g_iPreviewImageSize;

// address=[0x4727a08]
class CRandom16Ex * g_pRand;

// address=[0x4727a0c]
int g_iNumRivers;

// address=[0x4727a10]
class CCheckLayer * g_pCheckLayer;

// address=[0x4727a14]
int g_iRandomSeed;

// address=[0x4731050]
class CRTComp * pTheRTComp;

// address=[0x4731054]
void * hRTComHandle;

// address=[0x4731068]
class IEventEngine * g_pEvnEngine;

// address=[0x473106c]
class CVC_EventHandle g_cVC_EventHandle;

// address=[0x4731078]
class CSoundSystem * g_pcSoundSystem;

// address=[0x473107c]
class CVoiceChat * g_pcVoiceChat;

// address=[0x4731081]
class CSpiralOffsets g_cSpiralOffsets;

// address=[0x47311af]
struct std::nothrow_t const std::nothrow;

// address=[0x47311f4]
enum __stl_sync_api_modes_enum __stl_sync_api_impl_mode;

// address=[0x4731210]
std::ostream std::cout;

// address=[0x4731348]
std::istream std::cin;

// address=[0x47313d0]
std::istream * std::_Ptr_cin;

// address=[0x47313d4]
std::ostream * std::_Ptr_cout;

// address=[0x47313d8]
std::ostream * std::_Ptr_cerr;

// address=[0x47313dc]
std::ostream * std::_Ptr_clog;

// address=[0x47313e0]
std::wistream * std::_Ptr_wcin;

// address=[0x47313e4]
std::wostream * std::_Ptr_wcout;

// address=[0x47313e8]
std::wostream * std::_Ptr_wcerr;

// address=[0x47313ec]
std::wostream * std::_Ptr_wclog;

// address=[0x4731528]
___encodedKERNEL32Functions;

// address=[0x4731bec]
__tls_index;

// address=[0x4731bfc]
___isa_available;

// address=[0x4731c00]
___favor;

// address=[0x4731c64]
___@@_PchSym_@00@UwwUexgllohUexHoryhUhsrkUzgonuxUhixUzgoUzgohUlyqBiUrDIGUhgwzucOlyq@D30CF1FEFB9F8AE1;

// address=[0x4731df4]
void * (__stdcall* g_OutOfMemoryExceptionCallback)(void);

// address=[0x4731e38]
___pPurecall;

// address=[0x4731f18]
class DNameStatusNode * `public: static class DNameStatusNode * __cdecl DNameStatusNode::make(enum DNameStatus)'::`2'::nodes;

// address=[0x4731f54]
`public: static class DNameStatusNode * __cdecl DNameStatusNode::make(enum DNameStatus)'::`2'::`local static guard'{2}';

// address=[0x4731f9c]
__pfnDumpClient;

// address=[0x4731fb4]
__nstream;

// address=[0x4731fb8]
___piob;

// address=[0x4731fc0]
__cflush;

// address=[0x4731fc4]
__pReportHookListW;

// address=[0x4731fc8]
__pfnReportHook;

// address=[0x4731fcc]
__pReportHookList;

// address=[0x473255c]
__environ_table;

// address=[0x4732560]
__wenviron_table;

// address=[0x4732568]
___dcrt_initial_wide_environment;

// address=[0x473256c]
___dcrt_initial_narrow_environment;

// address=[0x4732d0c]
__commode;

// address=[0x4732d20]
___pioinfo;

// address=[0x4732f88]
__nhandle;

// address=[0x4732f8c]
___fastflag;

// address=[0x4733194]
___mbcodepage;

// address=[0x4733198]
___ismbcodepage;

// address=[0x473319c]
___mbulinfo;

// address=[0x47331b0]
___mblocalename;

// address=[0x47331bc]
__umaskval;

// address=[0x47331c0]
__fmode;

// address=[0x47331c4]
__old_pfxlen;

// address=[0x47331c8]
___argc;

// address=[0x47331cc]
___argv;

// address=[0x47331d0]
___wargv;

// address=[0x47331d4]
__acmdln;

// address=[0x47331d8]
__wcmdln;

// address=[0x47331dc]
__pgmptr;

// address=[0x47331e0]
__wpgmptr;

// address=[0x47331e4]
_scbMalloc;

// address=[0x47331e8]
_scbFree;

// address=[0x47331ec]
_scbRealloc;

// address=[0x47331f0]
_scbCalloc;

// address=[0x47331f8]
_scbLog;

// address=[0x47331fc]
_scbIsShuttingDown;

// address=[0x4733200]
_scbSetShuttingDownState;

// address=[0x4733208]
_scbCloseSocket;

// address=[0x473320c]
_scbUserContext;

// address=[0x4733210]
_scbConnectHostPort;

// address=[0x47340a0]
_z_verbose;

// address=[0x4734198]
int volatile `anonymous namespace'::g_iStaticObjRefCount;

// address=[0x4734298]
`__local_stdio_printf_options'::`2'::_OptionsStorage;

// address=[0x47342b0]
`__local_stdio_scanf_options'::`2'::_OptionsStorage;

// address=[0x47342c4]
_sigx_app;

// address=[0x47342d4]
_sig_app;

// address=[0x47342e0]
_OPENSSL_ia32cap_P;

// address=[0x4734300]
_ShiftRem;

// address=[0x4734318]
_ActiveMask2;

// address=[0x4734320]
_ActiveMask;

// address=[0x4734328]
_ActiveMaskEnd;

// address=[0x4734330]
_ShiftBpp;

// address=[0x4734338]
___dyn_tls_dtor_callback;

// address=[0x4734344]
___dyn_tls_init_callback;

// address=[0x473435c]
__setjmpexused;

// address=[0x4734368]
__pmatherr;

// address=[0x4734374]
___use_sse2_mathfcns;

// address=[0x4735040]
ADVAPI32_NULL_THUNK_DATA;

// address=[0x4735090]
CRYPT32_NULL_THUNK_DATA;

// address=[0x47350c4]
DDRAW_NULL_THUNK_DATA;

// address=[0x47350f4]
DSOUND_NULL_THUNK_DATA;

// address=[0x4735168]
GDI32_NULL_THUNK_DATA;

// address=[0x47351cc]
IPHLPAPI_NULL_THUNK_DATA;

// address=[0x4735534]
KERNEL32_NULL_THUNK_DATA;

// address=[0x4735628]
OLEAUT32_NULL_THUNK_DATA;

// address=[0x4735660]
SHELL32_NULL_THUNK_DATA;

// address=[0x4735780]
USER32_NULL_THUNK_DATA;

// address=[0x47357e8]
VERSION_NULL_THUNK_DATA;

// address=[0x4735840]
WINMM_NULL_THUNK_DATA;

// address=[0x4735930]
WS2_32_NULL_THUNK_DATA;

// address=[0x47359d4]
bcrypt_NULL_THUNK_DATA;

// address=[0x4735a38]
binkw32_NULL_THUNK_DATA;

// address=[0x4735a9c]
dbghelp_NULL_THUNK_DATA;

// address=[0x4735b90]
mss32_NULL_THUNK_DATA;

// address=[0x4735be8]
ncrypt_NULL_THUNK_DATA;

// address=[0x4735c30]
ole32_NULL_THUNK_DATA;

// address=[0x4735db0]
uplay_r1_loader_NULL_THUNK_DATA;

// address=[0x4735e1c]
__IMPORT_DESCRIPTOR_WINMM;

// address=[0x4735e30]
__IMPORT_DESCRIPTOR_WS2_32;

// address=[0x4735e44]
__IMPORT_DESCRIPTOR_IPHLPAPI;

// address=[0x4735e58]
__IMPORT_DESCRIPTOR_bcrypt;

// address=[0x4735e6c]
__IMPORT_DESCRIPTOR_ncrypt;

// address=[0x4735e80]
__IMPORT_DESCRIPTOR_CRYPT32;

// address=[0x4735e94]
__IMPORT_DESCRIPTOR_uplay_r1_loader;

// address=[0x4735ea8]
__IMPORT_DESCRIPTOR_KERNEL32;

// address=[0x4735ebc]
__IMPORT_DESCRIPTOR_USER32;

// address=[0x4735ed0]
__IMPORT_DESCRIPTOR_GDI32;

// address=[0x4735ee4]
__IMPORT_DESCRIPTOR_ADVAPI32;

// address=[0x4735ef8]
__IMPORT_DESCRIPTOR_SHELL32;

// address=[0x4735f0c]
__IMPORT_DESCRIPTOR_ole32;

// address=[0x4735f20]
__IMPORT_DESCRIPTOR_OLEAUT32;

// address=[0x4735f34]
__IMPORT_DESCRIPTOR_binkw32;

// address=[0x4735f48]
__IMPORT_DESCRIPTOR_mss32;

// address=[0x4735f5c]
__IMPORT_DESCRIPTOR_VERSION;

// address=[0x4735f70]
__IMPORT_DESCRIPTOR_dbghelp;

// address=[0x4735f84]
__IMPORT_DESCRIPTOR_DDRAW;

// address=[0x4735f98]
__IMPORT_DESCRIPTOR_DSOUND;

// address=[0x4735fac]
__NULL_IMPORT_DESCRIPTOR;

// address=[0x473b000]
__tls_start;

// address=[0x473ff48]
__Init_thread_epoch;

// address=[0x4740059]
__tls_end;

// address=[0x4744000]
___guard_check_icall_fptr;

#endif // GLOBALS_H
