#include "StormManager.h"

// Definitions for class StormManager

// address=[0x164db60]
// Decompiled from int StormManager::CreateInstance()
static void __cdecl StormManager::CreateInstance(void) {
  
  int result; // eax
  int v1; // [esp+8h] [ebp-14h]
  void *C; // [esp+Ch] [ebp-10h]

  C = operator new(0xAA4u);
  if ( C )
  {
    j__memset(C, 0, 0xAA4u);
    v1 = StormManager::StormManager();
  }
  else
  {
    v1 = 0;
  }
  StormManager::m_instance = v1;
  result = v1;
  *(_BYTE *)(v1 + 2720) = 0;
  return result;
}


// address=[0x164dc00]
// Decompiled from void StormManager::DestroyInstance()
static void __cdecl StormManager::DestroyInstance(void) {
  
  if ( StormManager::m_instance )
    StormManager::`scalar deleting destructor'((StormManager *)StormManager::m_instance, 1u);
}


// address=[0x164dc40]
// Decompiled from int StormManager::GetInstance()
static class StormManager * __cdecl StormManager::GetInstance(void) {
  
  return StormManager::m_instance;
}


// address=[0x164dc50]
// Decompiled from int __thiscall StormManager::Initialize(_DWORD *this)
void  StormManager::Initialize(void) {
  
  int v2; // [esp+4h] [ebp-54h]
  unsigned int v3; // [esp+Ch] [ebp-4Ch]
  void *v4; // [esp+18h] [ebp-40h]
  int v5; // [esp+1Ch] [ebp-3Ch]
  _BYTE v7[16]; // [esp+28h] [ebp-30h] BYREF
  _BYTE v8[16]; // [esp+38h] [ebp-20h] BYREF
  int v9; // [esp+54h] [ebp-4h]

  v4 = (void *)storm::memory::internal::EalAllocator::New(
                 8,
                 4,
                 1093636132,
                 "StormSampleFramework",
                 "TGOnline\\StormManager.cpp",
                 36);
  v9 = 0;
  if ( operator new(8u, v4) )
    v5 = StormSampleFramework::StormSampleFramework(this, 0);
  else
    v5 = 0;
  this[676] = v5;
  v3 = storm::ApplicationId::ApplicationId("48725ec3-179d-415a-9ff0-a51e42cecdaa");
  storm::ApplicationDescriptor::SetApplicationId((Concurrency::details::stl_critical_section_concrt *)(this + 646), v3);
  v9 = -1;
  storm::ApplicationId::~ApplicationId(v8);
  v2 = storm::ApplicationId::ApplicationId("48725ec3-179d-415a-9ff0-a51e42cecdaa");
  v9 = 2;
  storm::ApplicationDescriptor::SetCompatibilityId(v2);
  v9 = -1;
  storm::ApplicationId::~ApplicationId(v7);
  StormManager::InitControllers(this);
  StormManager::SetupStormLogs(this);
  StormManager::StartupStormCore();
  StormManager::CreateStormControllers();
  return StormManager::InitAndStartupEcho();
}


// address=[0x164ddb0]
// Decompiled from void __thiscall StormManager::UpdateGlobalController(StormManager *this)
void  StormManager::UpdateGlobalController(void) {
  
  _BYTE v2[44]; // [esp+4h] [ebp-5Ch] BYREF
  _BYTE v3[44]; // [esp+30h] [ebp-30h] BYREF

  if ( !*((_BYTE *)this + 20) )
  {
    storm::SimpleGlobalController::NetworkUpdate((char *)this + 68, v3, 1);
    storm::EResult::~EResult((CDHtmlElementEventSink *)v3);
  }
  storm::SimpleGlobalController::Update((StormManager *)((char *)this + 68), utDriver|utSoftware);
  if ( !*((_BYTE *)this + 20) )
  {
    storm::SimpleGlobalController::NetworkUpdate((char *)this + 68, v2, 2);
    storm::EResult::~EResult((CDHtmlElementEventSink *)v2);
  }
}


// address=[0x164de30]
// Decompiled from void __thiscall StormManager::Update(storm::SimpleConnectivityFacade **this)
void  StormManager::Update(void) {
  
  storm::SimpleController *SessionController; // eax
  _BYTE v3[44]; // [esp+4h] [ebp-30h] BYREF

  StormManager::UpdateGlobalController((StormManager *)this);
  (*(void (__thiscall **)(storm::SimpleConnectivityFacade *))(*(_DWORD *)this[678] + 12))(this[678]);
  storm::Core::Update(this[4], v3, 3);
  storm::EResult::~EResult((CDHtmlElementEventSink *)v3);
  SessionController = storm::SimpleConnectivityFacade::GetSessionController(this[663]);
  storm::SimpleController::Update(SessionController);
}


// address=[0x164dea0]
// Decompiled from void __thiscall StormManager::Shutdown(StormManager *this)
void  StormManager::Shutdown(void) {
  
  struct storm::SimpleSessionController *SessionController; // eax
  _DWORD v2[10]; // [esp-50h] [ebp-B0h] BYREF
  _DWORD v3[16]; // [esp-28h] [ebp-88h] BYREF
  int v4; // [esp+18h] [ebp-48h]
  int v5; // [esp+1Ch] [ebp-44h]
  StormManager *v6; // [esp+20h] [ebp-40h]
  _BYTE v7[44]; // [esp+24h] [ebp-3Ch] BYREF
  int v8; // [esp+5Ch] [ebp-4h]

  v6 = this;
  StormManager::DeleteSessionHandler(this);
  v3[15] = v3;
  v5 = std::function<void __cdecl (storm::SimpleSessionHandler *)>::function<void __cdecl (storm::SimpleSessionHandler *)>(0);
  v3[14] = v5;
  v8 = 0;
  v3[13] = v2;
  v4 = std::function<storm::SimpleSessionHandler * __cdecl (storm::StringId const &)>::function<storm::SimpleSessionHandler * __cdecl (storm::StringId const &)>(0);
  v3[12] = v4;
  LOBYTE(v8) = 1;
  SessionController = storm::SimpleConnectivityFacade::GetSessionController(*((storm::SimpleConnectivityFacade **)v6
                                                                            + 663));
  v8 = -1;
  v3[11] = storm::SimpleSessionController::RegisterCreateAndDeleteSessionHandlerCallback(
             SessionController,
             v7,
             v2[0],
             v2[1],
             v2[2],
             v2[3],
             v2[4],
             v2[5],
             v2[6],
             v2[7],
             v2[8],
             v2[9],
             v3[0],
             v3[1],
             v3[2],
             v3[3],
             v3[4],
             v3[5],
             v3[6],
             v3[7],
             v3[8],
             v3[9]);
  storm::EResult::~EResult((CDHtmlElementEventSink *)v7);
  StormManager::ShutdownEcho(v6);
  storm::memory::internal::EalAllocator::Delete<StormSampleFramework>(
    *((void ***)v6 + 676),
    (int)"TGOnline\\StormManager.cpp",
    55);
  StormManager::DestroyStormControllers(v6);
  StormManager::StopStormCore(v6);
  if ( *((_DWORD *)v6 + 678) )
  {
    storm::memory::internal::EalAllocator::Delete<storm::SimpleUbiServicesControllerClientImpl>(
      *((void ***)v6 + 678),
      (int)"TGOnline\\StormManager.cpp",
      61);
    *((_DWORD *)v6 + 678) = 0;
  }
  if ( *((_DWORD *)v6 + 679) )
  {
    storm::memory::internal::EalAllocator::Delete<storm::PeerChannelController>(
      *((void ***)v6 + 679),
      (int)"TGOnline\\StormManager.cpp",
      62);
    *((_DWORD *)v6 + 679) = 0;
  }
  if ( *((_DWORD *)v6 + 663) )
  {
    storm::memory::internal::EalAllocator::Delete<storm::SimpleConnectivityFacade>(
      *((void ***)v6 + 663),
      (int)"TGOnline\\StormManager.cpp",
      63);
    *((_DWORD *)v6 + 663) = 0;
  }
  StormManager::ShutdownStormLogs(v6);
}


// address=[0x164e3d0]
// Decompiled from void __thiscall StormManager::CloseSession(StormManager *this)
void  StormManager::CloseSession(void) {
  
  _DWORD *v1; // eax
  const char *v2; // eax
  char v3; // [esp-28h] [ebp-A4h] BYREF
  int v4; // [esp-24h] [ebp-A0h]
  int v5; // [esp-20h] [ebp-9Ch]
  int v6; // [esp-1Ch] [ebp-98h]
  int v7; // [esp-18h] [ebp-94h]
  int v8; // [esp-14h] [ebp-90h]
  int v9; // [esp-10h] [ebp-8Ch] BYREF
  int v10; // [esp-Ch] [ebp-88h]
  const char *v11; // [esp-8h] [ebp-84h]
  int v12; // [esp-4h] [ebp-80h]
  storm::assert *v13; // [esp+0h] [ebp-7Ch]
  int v14; // [esp+4h] [ebp-78h]
  int v15; // [esp+8h] [ebp-74h]
  char *v16; // [esp+Ch] [ebp-70h]
  int *v17; // [esp+14h] [ebp-68h]
  int v18; // [esp+18h] [ebp-64h]
  int v19; // [esp+1Ch] [ebp-60h]
  char v20; // [esp+23h] [ebp-59h]
  _BYTE v21[44]; // [esp+24h] [ebp-58h] BYREF
  _BYTE v22[28]; // [esp+50h] [ebp-2Ch] BYREF
  int v23; // [esp+78h] [ebp-4h]

  v19 = (int)this;
  if ( *((_DWORD *)this + 677) )
  {
    v12 = 1092677632;
    v11 = (_BYTE *)(_enc_textbss_begin + 5904);
    v17 = &v9;
    storm::BasicStringView<char,std::char_traits<char>>::BasicStringView<char,std::char_traits<char>>("Leave Session");
    v18 = storm::SimpleAsyncOp::New(v9, v10, v11, v12);
    v1 = (_DWORD *)unknown_libname_12627(v19);
    v16 = &v3;
    v15 = std::function<storm::EResult __cdecl (storm::SimpleAsyncOp &)>::function<storm::EResult __cdecl (storm::SimpleAsyncOp &)>(*v1);
    v14 = storm::SimpleAsyncOp::Launch((CDHtmlElementEventSink *)v21, v3, v4, v5, v6, v7, v8, v9, v10, (int)v11, v12);
    v23 = 0;
    if ( storm::EResult::GetErrorCode(v21) < 0 )
    {
      *(_BYTE *)(v19 + 2720) = 0;
      if ( storm::assert::IsAssertEnabled(v13) )
      {
        v20 = 1;
        storm::StringStream::StringStream((storm::StringStream *)v22);
        LOBYTE(v23) = 1;
        v12 = (int)" - Failed to leave current session!";
        storm::StringStream::operator<<("StormManager::CloseSession");
        storm::StringStream::operator<<((char *)v12);
        v12 = 455;
        v2 = (const char *)std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::c_str("TGOnline\\StormManager.cpp");
        storm::assert::AssertFunction((storm::assert *)"false", v2, v11, (const char *)v12, v13);
        LOBYTE(v23) = 0;
        storm::StringStream::~StringStream((storm::StringStream *)v22);
      }
    }
    v23 = -1;
    storm::EResult::~EResult((CDHtmlElementEventSink *)v21);
  }
}


// address=[0x164e530]
// Decompiled from void __thiscall StormManager::SearchForSessions(StormManager *this)
void  StormManager::SearchForSessions(void) {
  
  _DWORD *v1; // eax
  const char *v2; // eax
  char v3; // [esp-3Ch] [ebp-B8h] BYREF
  int v4; // [esp-38h] [ebp-B4h]
  int v5; // [esp-34h] [ebp-B0h]
  int v6; // [esp-30h] [ebp-ACh]
  CDHtmlElementEventSink *v7; // [esp-2Ch] [ebp-A8h]
  char v8; // [esp-28h] [ebp-A4h] BYREF
  int v9; // [esp-24h] [ebp-A0h]
  int v10; // [esp-20h] [ebp-9Ch]
  int v11; // [esp-1Ch] [ebp-98h]
  int v12; // [esp-18h] [ebp-94h]
  int v13; // [esp-14h] [ebp-90h]
  int v14; // [esp-10h] [ebp-8Ch]
  int v15; // [esp-Ch] [ebp-88h]
  const char *v16; // [esp-8h] [ebp-84h]
  int v17; // [esp-4h] [ebp-80h]
  storm::assert *v18; // [esp+0h] [ebp-7Ch]
  int v19; // [esp+4h] [ebp-78h]
  char *v20; // [esp+8h] [ebp-74h]
  int v21; // [esp+Ch] [ebp-70h]
  char *v22; // [esp+10h] [ebp-6Ch]
  int v23; // [esp+18h] [ebp-64h]
  int v24; // [esp+1Ch] [ebp-60h]
  char v25; // [esp+23h] [ebp-59h]
  _BYTE v26[44]; // [esp+24h] [ebp-58h] BYREF
  _BYTE v27[28]; // [esp+50h] [ebp-2Ch] BYREF
  int v28; // [esp+78h] [ebp-4h]

  v24 = (int)this;
  if ( StormManager::IsLoggedIn(this) && StormManager::IsNATReady((StormManager *)v24) )
  {
    storm::SimpleConnectivityFacade::CopySandboxNameIntoStrategy(*(storm::SimpleConnectivityFacade **)(v24 + 2652));
    v1 = (_DWORD *)unknown_libname_12626(v24);
    v22 = &v8;
    v23 = std::function<storm::EResult __cdecl (storm::SimpleAsyncOp &)>::function<storm::EResult __cdecl (storm::SimpleAsyncOp &)>(*v1);
    v21 = v23;
    v28 = 0;
    v7 = (CDHtmlElementEventSink *)v26;
    v6 = 1092677632;
    v5 = 10000;
    v20 = &v3;
    storm::BasicStringView<char,std::char_traits<char>>::BasicStringView<char,std::char_traits<char>>("Session Search");
    storm::SimpleAsyncOp::New(v3, v4, v5, v6);
    v28 = -1;
    v19 = storm::SimpleAsyncOp::Launch(v7, v8, v9, v10, v11, v12, v13, v14, v15, (int)v16, v17);
    v28 = 1;
    if ( storm::EResult::GetErrorCode(v26) < 0 && storm::assert::IsAssertEnabled(v18) )
    {
      v25 = 1;
      storm::StringStream::StringStream((storm::StringStream *)v27);
      LOBYTE(v28) = 2;
      v17 = (int)" - Failed to search sessions ";
      storm::StringStream::operator<<("StormManager::SearchForSessions");
      storm::StringStream::operator<<((char *)v17);
      v17 = 551;
      v2 = (const char *)std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::c_str("TGOnline\\StormManager.cpp");
      storm::assert::AssertFunction((storm::assert *)"false", v2, v16, (const char *)v17, v18);
      LOBYTE(v28) = 1;
      storm::StringStream::~StringStream((storm::StringStream *)v27);
    }
    v28 = -1;
    storm::EResult::~EResult((CDHtmlElementEventSink *)v26);
  }
}


// address=[0x164ea30]
// Decompiled from void __thiscall StormManager::LeaveSession(StormManager *this)
void  StormManager::LeaveSession(void) {
  
  storm::GUID *SessionGUID; // eax
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  char v6; // [esp-A4h] [ebp-140h] BYREF
  int v7; // [esp-A0h] [ebp-13Ch]
  int v8; // [esp-9Ch] [ebp-138h]
  int v9; // [esp-98h] [ebp-134h]
  int v10; // [esp-94h] [ebp-130h]
  int v11; // [esp-90h] [ebp-12Ch]
  int v12; // [esp-8Ch] [ebp-128h]
  int v13; // [esp-88h] [ebp-124h]
  int v14; // [esp-84h] [ebp-120h]
  int v15; // [esp-80h] [ebp-11Ch]
  char v16; // [esp-7Ch] [ebp-118h] BYREF
  int v17; // [esp-78h] [ebp-114h]
  int v18; // [esp-74h] [ebp-110h]
  int v19; // [esp-70h] [ebp-10Ch]
  int v20; // [esp-6Ch] [ebp-108h]
  int v21; // [esp-68h] [ebp-104h]
  int v22; // [esp-64h] [ebp-100h]
  int v23; // [esp-60h] [ebp-FCh]
  int v24; // [esp-5Ch] [ebp-F8h]
  int v25; // [esp-58h] [ebp-F4h]
  char v26; // [esp-54h] [ebp-F0h] BYREF
  int v27; // [esp-50h] [ebp-ECh]
  int v28; // [esp-4Ch] [ebp-E8h]
  int v29; // [esp-48h] [ebp-E4h]
  int v30; // [esp-44h] [ebp-E0h]
  int v31; // [esp-40h] [ebp-DCh]
  int v32; // [esp-3Ch] [ebp-D8h]
  int v33; // [esp-38h] [ebp-D4h]
  int v34; // [esp-34h] [ebp-D0h]
  int v35; // [esp-30h] [ebp-CCh]
  CDHtmlElementEventSink *v36; // [esp-2Ch] [ebp-C8h]
  char v37; // [esp-28h] [ebp-C4h] BYREF
  int v38; // [esp-24h] [ebp-C0h]
  int v39; // [esp-20h] [ebp-BCh]
  int v40; // [esp-1Ch] [ebp-B8h]
  int v41; // [esp-18h] [ebp-B4h]
  int v42; // [esp-14h] [ebp-B0h]
  int v43; // [esp-10h] [ebp-ACh] BYREF
  int v44; // [esp-Ch] [ebp-A8h]
  int v45; // [esp-8h] [ebp-A4h]
  int v46; // [esp-4h] [ebp-A0h]
  int v47; // [esp+4h] [ebp-98h]
  int v48; // [esp+8h] [ebp-94h]
  char *v49; // [esp+Ch] [ebp-90h]
  int v50; // [esp+14h] [ebp-88h]
  char *v51; // [esp+18h] [ebp-84h]
  int v52; // [esp+20h] [ebp-7Ch]
  char *v53; // [esp+24h] [ebp-78h]
  int v54; // [esp+2Ch] [ebp-70h]
  char *v55; // [esp+30h] [ebp-6Ch]
  int *v56; // [esp+38h] [ebp-64h]
  int v57; // [esp+3Ch] [ebp-60h]
  int v58; // [esp+40h] [ebp-5Ch]
  int v59; // [esp+44h] [ebp-58h]
  int v60; // [esp+48h] [ebp-54h]
  int v61; // [esp+4Ch] [ebp-50h]
  int v62; // [esp+50h] [ebp-4Ch]
  int v63; // [esp+54h] [ebp-48h]
  int v64; // [esp+58h] [ebp-44h]
  char v65; // [esp+5Fh] [ebp-3Dh] BYREF
  _BYTE v66[44]; // [esp+60h] [ebp-3Ch] BYREF
  int v67; // [esp+98h] [ebp-4h]

  v64 = (int)this;
  if ( *((_DWORD *)this + 677) )
  {
    SessionGUID = (storm::GUID *)storm::SimpleSessionHandler::GetSessionGUID(*(storm::SimpleSessionHandler **)(v64 + 2708));
    if ( storm::GUID::IsValid(SessionGUID)
      && !storm::SimpleSessionHandler::IsLeaving(*(storm::SimpleSessionHandler **)(v64 + 2708)) )
    {
      v46 = 1092677632;
      v45 = 10000;
      v56 = &v43;
      storm::BasicStringView<char,std::char_traits<char>>::BasicStringView<char,std::char_traits<char>>("Leave Session");
      v60 = storm::SimpleAsyncOp::New(v43, v44, v45, v46);
      v65 = 0;
      v2 = (_DWORD *)unknown_libname_12612(v64);
      v55 = &v37;
      v63 = std::function<storm::EResult __cdecl (storm::SimpleAsyncOp &)>::function<storm::EResult __cdecl (storm::SimpleAsyncOp &)>(*v2);
      v54 = v63;
      v67 = 0;
      v36 = (CDHtmlElementEventSink *)v66;
      v3 = (_DWORD *)unknown_libname_12614(&v65);
      v53 = &v26;
      v62 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(*v3);
      v52 = v62;
      LOBYTE(v67) = 1;
      v4 = (_DWORD *)unknown_libname_12617(&v65);
      v51 = &v16;
      v61 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(*v4);
      v50 = v61;
      LOBYTE(v67) = 2;
      v5 = (_DWORD *)unknown_libname_12622(&v65);
      v49 = &v6;
      v48 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(*v5);
      v59 = storm::SimpleAsyncOp::OnFailureDo(v6, v7, v8, v9, v10, v11, v12, v13, v14, v15);
      LOBYTE(v67) = 1;
      v58 = storm::SimpleAsyncOp::OnTimeoutDo(v16, v17, v18, v19, v20, v21, v22, v23, v24, v25);
      LOBYTE(v67) = 0;
      v57 = storm::SimpleAsyncOp::OnSuccessDo(v26, v27, v28, v29, v30, v31, v32, v33, v34, v35);
      v67 = -1;
      v47 = storm::SimpleAsyncOp::Launch(v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46);
      v67 = 3;
      if ( storm::EResult::GetErrorCode(v66) >= 0 )
      {
        while ( !v65 )
        {
          StormManager::UpdateGlobalController((StormManager *)v64);
          storm::ThisThread::SleepFor(30);
        }
      }
      StormManager::DeleteSessionHandler((StormManager *)v64);
      v67 = -1;
      storm::EResult::~EResult((CDHtmlElementEventSink *)v66);
    }
  }
}


// address=[0x164ef80]
// Decompiled from void __thiscall StormManager::SetJoinAndDiscoveryOverride(StormManager *this, int a2)
void  StormManager::SetJoinAndDiscoveryOverride(bool) {
  
  _DWORD *v2; // eax
  char v3; // [esp-A4h] [ebp-138h] BYREF
  int v4; // [esp-A0h] [ebp-134h]
  int v5; // [esp-9Ch] [ebp-130h]
  int v6; // [esp-98h] [ebp-12Ch]
  int v7; // [esp-94h] [ebp-128h]
  int v8; // [esp-90h] [ebp-124h]
  int v9; // [esp-8Ch] [ebp-120h]
  int v10; // [esp-88h] [ebp-11Ch]
  int v11; // [esp-84h] [ebp-118h]
  int v12; // [esp-80h] [ebp-114h]
  char v13; // [esp-7Ch] [ebp-110h] BYREF
  int v14; // [esp-78h] [ebp-10Ch]
  int v15; // [esp-74h] [ebp-108h]
  int v16; // [esp-70h] [ebp-104h]
  int v17; // [esp-6Ch] [ebp-100h]
  int v18; // [esp-68h] [ebp-FCh]
  int v19; // [esp-64h] [ebp-F8h]
  int v20; // [esp-60h] [ebp-F4h]
  int v21; // [esp-5Ch] [ebp-F0h]
  int v22; // [esp-58h] [ebp-ECh]
  char v23; // [esp-54h] [ebp-E8h] BYREF
  int v24; // [esp-50h] [ebp-E4h]
  int v25; // [esp-4Ch] [ebp-E0h]
  int v26; // [esp-48h] [ebp-DCh]
  int v27; // [esp-44h] [ebp-D8h]
  int v28; // [esp-40h] [ebp-D4h]
  int v29; // [esp-3Ch] [ebp-D0h]
  int v30; // [esp-38h] [ebp-CCh]
  int v31; // [esp-34h] [ebp-C8h]
  int v32; // [esp-30h] [ebp-C4h]
  CDHtmlElementEventSink *v33; // [esp-2Ch] [ebp-C0h]
  char v34; // [esp-28h] [ebp-BCh] BYREF
  int v35; // [esp-24h] [ebp-B8h]
  int v36; // [esp-20h] [ebp-B4h]
  int v37; // [esp-1Ch] [ebp-B0h]
  int v38; // [esp-18h] [ebp-ACh]
  int v39; // [esp-14h] [ebp-A8h]
  int v40; // [esp-10h] [ebp-A4h] BYREF
  int v41; // [esp-Ch] [ebp-A0h]
  int v42; // [esp-8h] [ebp-9Ch]
  int v43; // [esp-4h] [ebp-98h]
  int v44; // [esp+Ch] [ebp-88h]
  int v45; // [esp+10h] [ebp-84h]
  char *v46; // [esp+14h] [ebp-80h]
  int v47; // [esp+18h] [ebp-7Ch]
  char *v48; // [esp+1Ch] [ebp-78h]
  int v49; // [esp+20h] [ebp-74h]
  char *v50; // [esp+24h] [ebp-70h]
  int v51; // [esp+28h] [ebp-6Ch]
  char *v52; // [esp+2Ch] [ebp-68h]
  int *v53; // [esp+30h] [ebp-64h]
  int v54; // [esp+34h] [ebp-60h]
  int v55; // [esp+38h] [ebp-5Ch]
  int v56; // [esp+3Ch] [ebp-58h]
  int v57; // [esp+40h] [ebp-54h]
  int v58; // [esp+44h] [ebp-50h]
  int v59; // [esp+48h] [ebp-4Ch]
  int v60; // [esp+4Ch] [ebp-48h]
  int v61; // [esp+50h] [ebp-44h]
  char v62; // [esp+55h] [ebp-3Fh]
  char v63; // [esp+56h] [ebp-3Eh]
  char v64; // [esp+57h] [ebp-3Dh]
  _BYTE v65[44]; // [esp+58h] [ebp-3Ch] BYREF
  int v66; // [esp+90h] [ebp-4h]

  v61 = (int)this;
  v43 = 1092677632;
  v42 = 10000;
  v53 = &v40;
  storm::BasicStringView<char,std::char_traits<char>>::BasicStringView<char,std::char_traits<char>>("SetJoinAndDiscoveryOverride");
  v57 = storm::SimpleAsyncOp::New(v40, v41, v42, v43);
  v64 = 0;
  v63 = 0;
  v62 = 0;
  v2 = (_DWORD *)sub_12FC1B0(v61, &a2);
  v52 = &v34;
  v60 = std::function<storm::EResult __cdecl (storm::SimpleAsyncOp &)>::function<storm::EResult __cdecl (storm::SimpleAsyncOp &)>(
          *v2,
          v2[1]);
  v51 = v60;
  v66 = 0;
  v33 = (CDHtmlElementEventSink *)v65;
  v50 = &v23;
  v59 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(v64);
  v49 = v59;
  LOBYTE(v66) = 1;
  v48 = &v13;
  v58 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(v63);
  v47 = v58;
  LOBYTE(v66) = 2;
  v46 = &v3;
  v45 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(v62);
  v56 = storm::SimpleAsyncOp::OnFailureDo(v3, v4, v5, v6, v7, v8, v9, v10, v11, v12);
  LOBYTE(v66) = 1;
  v55 = storm::SimpleAsyncOp::OnSuccessDo(v13, v14, v15, v16, v17, v18, v19, v20, v21, v22);
  LOBYTE(v66) = 0;
  v54 = storm::SimpleAsyncOp::OnTimeoutDo(v23, v24, v25, v26, v27, v28, v29, v30, v31, v32);
  v66 = -1;
  v44 = storm::SimpleAsyncOp::Launch(v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43);
  storm::EResult::~EResult((CDHtmlElementEventSink *)v65);
}


// address=[0x164f240]
// Decompiled from void __thiscall StormManager::DeleteSessionHandler(StormManager *this)
void  StormManager::DeleteSessionHandler(void) {
  
  CMFCRibbonPanel *SessionController; // eax
  unsigned int v2; // [esp-4h] [ebp-38h]
  int v4; // [esp+0h] [ebp-34h]
  unsigned int v5[11]; // [esp+4h] [ebp-30h] BYREF

  if ( *((_DWORD *)this + 677) )
  {
    v2 = *((_DWORD *)this + 677);
    SessionController = storm::SimpleConnectivityFacade::GetSessionController(*((storm::SimpleConnectivityFacade **)this
                                                                              + 663));
    storm::SimpleSessionController::DeleteSessionHandler(
      SessionController,
      (unsigned int)v5,
      v2,
      (unsigned int)this,
      v5[0]);
    storm::EResult::~EResult((CDHtmlElementEventSink *)v5);
    *(_DWORD *)(v4 + 2708) = 0;
  }
}


// address=[0x164fc90]
// Decompiled from void __thiscall StormManager::SetFreeSlotCount(StormManager *this, unsigned int a2)
void  StormManager::SetFreeSlotCount(int) {
  
  const struct storm::echo::SessionDescriptor *SessionDescriptor; // eax
  unsigned int v3; // [esp+4h] [ebp-340h] BYREF
  StormManager *v4; // [esp+8h] [ebp-33Ch]
  _BYTE v5[764]; // [esp+Ch] [ebp-338h] BYREF
  int v6[11]; // [esp+308h] [ebp-3Ch] BYREF
  int v7; // [esp+340h] [ebp-4h]

  v4 = this;
  if ( *((_DWORD *)this + 677) )
  {
    GameSessionDescriptor::GameSessionDescriptor((GameSessionDescriptor *)v5);
    v7 = 0;
    SessionDescriptor = storm::SimpleSessionHandler::GetSessionDescriptor(*((storm::SimpleSessionHandler **)v4 + 677));
    storm::DataContainer::CopyAllNetData(v6, v5, SessionDescriptor);
    storm::EResult::~EResult((CDHtmlElementEventSink *)v6);
    GameSessionDescriptor::GetFreeSlots((GameSessionDescriptor *)v5, &v3);
    if ( a2 != v3 )
    {
      GameSessionDescriptor::SetFreeSlots((GameSessionDescriptor *)v5, a2);
      GameSessionHandler::UpdateSessionDescriptor(
        *((GameSessionHandler **)v4 + 677),
        (const struct storm::echo::SessionDescriptor *)v5);
    }
    v7 = -1;
    GameSessionDescriptor::~GameSessionDescriptor((GameSessionDescriptor *)v5);
  }
}


// address=[0x164fd90]
// Decompiled from unsigned int __thiscall StormManager::GetLocalPeerId(storm::SimpleSessionHandler **this)
int  StormManager::GetLocalPeerId(void)const {
  
  return storm::SimpleSessionHandler::GetLocalSessionPeerId(this[677]);
}


// address=[0x164fdb0]
// Decompiled from int __thiscall StormManager::GetHostPeerId(storm::SimpleSessionHandler **this)
int  StormManager::GetHostPeerId(void)const {
  
  return storm::SimpleSessionHandler::GetHostSessionPeerId(this[677]);
}


// address=[0x164fdd0]
// Decompiled from bool __thiscall StormManager::IsLocalPeerId(void *this, int a2)
bool  StormManager::IsLocalPeerId(int)const {
  
  return StormManager::GetLocalPeerId(this) == a2;
}


// address=[0x164fe00]
// Decompiled from char __thiscall StormManager::IsLoggedIn(StormManager *this)
bool  StormManager::IsLoggedIn(void)const {
  
  if ( *((_DWORD *)this + 678) )
    return (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 678) + 84))(*((_DWORD *)this + 678));
  else
    return 0;
}


// address=[0x164fe40]
// Decompiled from bool __thiscall StormManager::IsNATReady(storm::SimpleConnectivityFacade **this)
bool  StormManager::IsNATReady(void)const {
  
  return storm::SimpleConnectivityFacade::IsStormReadyForMatchmaking(this[663]);
}


// address=[0x164fe60]
// Decompiled from int __thiscall StormManager::GetSessionState(storm::SimpleSessionHandler **this)
enum StormManager::SESSION_STATE  StormManager::GetSessionState(void)const {
  
  unsigned int HostSessionPeerId; // esi

  if ( !this[677] )
    return 2;
  HostSessionPeerId = storm::SimpleSessionHandler::GetHostSessionPeerId(this[677]);
  return HostSessionPeerId != storm::SimpleSessionHandler::GetLocalSessionPeerId(this[677]);
}


// address=[0x1682f40]
// Decompiled from StormManager *__thiscall StormManager::StormManager(StormManager *this)
 StormManager::StormManager(void) {
  
  _DWORD *v1; // eax
  _BYTE v3[20]; // [esp+4h] [ebp-3Ch] BYREF
  StormManager *v4; // [esp+18h] [ebp-28h]
  _DWORD v5[5]; // [esp+1Ch] [ebp-24h] BYREF
  int v6; // [esp+3Ch] [ebp-4h]

  v4 = this;
  storm::CoreParams::CoreParams((StormManager *)((char *)this + 20));
  v6 = 0;
  v1 = (_DWORD *)storm::DefineSimpleControllersLibCompilParams<int>(v3);
  v5[0] = *v1;
  v5[1] = v1[1];
  v5[2] = v1[2];
  v5[3] = v1[3];
  v5[4] = v1[4];
  storm::SimpleGlobalController::SimpleGlobalController(
    (StormManager *)((char *)v4 + 68),
    (const struct storm::SimpleControllersLibCompilParams *)v5);
  LOBYTE(v6) = 1;
  storm::null_SimpleTrackingController::null_SimpleTrackingController((StormManager *)((char *)v4 + 1340));
  LOBYTE(v6) = 2;
  storm::echo::engine::SEngineParamInit::SEngineParamInit((StormManager *)((char *)v4 + 1384));
  LOBYTE(v6) = 3;
  storm::echo::engine::SEngineParamStartUp::SEngineParamStartUp((StormManager *)((char *)v4 + 1428));
  LOBYTE(v6) = 4;
  storm::DefaultApplicationDescriptor::DefaultApplicationDescriptor((StormManager *)((char *)v4 + 2584));
  LOBYTE(v6) = 5;
  storm::punch::ClientParams::ClientParams((StormManager *)((char *)v4 + 2656));
  return v4;
}


// address=[0x1684f90]
// Decompiled from void __thiscall StormManager::~StormManager(StormManager *this)
 StormManager::~StormManager(void) {
  
  storm::punch::ClientParams::~ClientParams((StormManager *)((char *)this + 2656));
  storm::DefaultApplicationDescriptor::~DefaultApplicationDescriptor((StormManager *)((char *)this + 2584));
  storm::echo::engine::SEngineParamStartUp::~SEngineParamStartUp((StormManager *)((char *)this + 1428));
  storm::echo::engine::SEngineParamInit::~SEngineParamInit((StormManager *)((char *)this + 1384));
  storm::null_SimpleTrackingController::~null_SimpleTrackingController((StormManager *)((char *)this + 1340));
  storm::SimpleGlobalController::~SimpleGlobalController((StormManager *)((char *)this + 68));
  storm::CoreParams::~CoreParams((StormManager *)((char *)this + 20));
}


// address=[0x164ff50]
// Decompiled from int __thiscall StormManager::InitControllers(StormManager *this)
void  StormManager::InitControllers(void) {
  
  WSAData WSAData; // [esp+8h] [ebp-194h] BYREF

  return WSAStartup(0x202u, &WSAData);
}


// address=[0x164ffa0]
// Decompiled from void __thiscall StormManager::SetupStormLogs(StormManager *this)
void  StormManager::SetupStormLogs(void) {
  
  *((_DWORD *)this + 3) = storm::LogDeviceContainer::CreateAndAcquireInstance();
  *(_DWORD *)this = storm::LogDeviceDebugOutput::CreateAndAcquireInstance();
  *((_DWORD *)this + 1) = storm::LogDeviceFile::CreateAndAcquireInstance(
                            byte_382F2C2,
                            "StormLog",
                            1,
                            1u,
                            storm::LogDeviceFile::UNLIMITED_FILE_SIZE);
  storm::LogDeviceContainer::AddLogDevice(*((storm::LogDeviceContainer **)this + 3), *(struct storm::LogDevice **)this);
  storm::LogDeviceContainer::AddLogDevice(
    *((storm::LogDeviceContainer **)this + 3),
    *((struct storm::LogDevice **)this + 1));
}


// address=[0x1650020]
// Decompiled from int __thiscall StormManager::ShutdownStormLogs(storm::RefCountedObject **this)
void  StormManager::ShutdownStormLogs(void) {
  
  int result; // eax

  storm::RefCountedObject::ReleaseInstance(this[3]);
  this[3] = 0;
  storm::RefCountedObject::ReleaseInstance(*this);
  *this = 0;
  storm::RefCountedObject::ReleaseInstance(this[1]);
  this[1] = 0;
  return result;
}


// address=[0x1650070]
// Decompiled from void __thiscall StormManager::StartupStormCore(StormManager *this)
void  StormManager::StartupStormCore(void) {
  
  _DWORD *v1; // eax
  struct storm::Core *v2; // eax
  const char *v3; // eax
  const char *v4; // [esp-8h] [ebp-C0h]
  _BYTE v5[16]; // [esp+4h] [ebp-B4h] BYREF
  _BYTE v6[20]; // [esp+14h] [ebp-A4h] BYREF
  int v7; // [esp+28h] [ebp-90h]
  BOOL v8; // [esp+44h] [ebp-74h]
  StormManager *v9; // [esp+48h] [ebp-70h]
  bool v10; // [esp+4Fh] [ebp-69h]
  _BYTE v11[44]; // [esp+50h] [ebp-68h] BYREF
  _BYTE v12[28]; // [esp+7Ch] [ebp-3Ch] BYREF
  _DWORD v13[4]; // [esp+98h] [ebp-20h] BYREF
  int v14; // [esp+B4h] [ebp-4h]

  v9 = this;
  storm::CoreParams::CoreParams((storm::CoreParams *)v6);
  v14 = 0;
  v7 = *((_DWORD *)v9 + 3);
  v1 = (_DWORD *)storm::DefineStormCommonLibCompilParams<int>(v5);
  v13[0] = *v1;
  v13[1] = v1[1];
  v13[2] = v1[2];
  v13[3] = v1[3];
  v2 = storm::Core::CreateAndAcquireInstance((const struct storm::StormCommonLibCompilParams *)v13);
  *((_DWORD *)v9 + 4) = v2;
  storm::Core::Startup(*((_DWORD *)v9 + 4), v11, v6);
  LOBYTE(v14) = 1;
  if ( storm::assert::IsAssertEnabled() )
  {
    v8 = storm::EResult::GetErrorCode(v11) < 0;
    v10 = v8;
    if ( v8 )
    {
      storm::StringStream::StringStream((storm::StringStream *)v12);
      LOBYTE(v14) = 2;
      storm::operator<<(v12, v11);
      v3 = (const char *)std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::c_str("TGOnline\\StormManager.cpp");
      storm::assert::AssertFunction((storm::assert *)"!( (_eres).GetErrorCode() < 0 )", v3, v4, (const char *)0x77);
      LOBYTE(v14) = 1;
      storm::StringStream::~StringStream((storm::StringStream *)v12);
    }
  }
  LOBYTE(v14) = 0;
  storm::EResult::~EResult((CDHtmlElementEventSink *)v11);
  v14 = -1;
  storm::CoreParams::~CoreParams((storm::CoreParams *)v6);
}


// address=[0x16501d0]
// Decompiled from int __thiscall StormManager::StopStormCore(StormManager *this)
void  StormManager::StopStormCore(void) {
  
  const char *v1; // eax
  const char *v3; // [esp-8h] [ebp-A8h]
  int v4; // [esp+0h] [ebp-A0h]
  struct storm::SimpleSessionController *SessionController; // [esp+4h] [ebp-9Ch]
  int v6; // [esp+Ch] [ebp-94h]
  _BYTE v8[44]; // [esp+1Ch] [ebp-84h] BYREF
  _BYTE v9[44]; // [esp+48h] [ebp-58h] BYREF
  _BYTE v10[28]; // [esp+74h] [ebp-2Ch] BYREF
  int v11; // [esp+9Ch] [ebp-4h]

  storm::Core::RemoveHandler(*((_DWORD *)this + 4), v8, *((_DWORD *)this + 679));
  storm::EResult::~EResult((CDHtmlElementEventSink *)v8);
  storm::Core::Shutdown(*((_DWORD *)this + 4), v9);
  v11 = 0;
  if ( storm::assert::IsAssertEnabled() && storm::EResult::GetErrorCode(v9) < 0 )
  {
    storm::StringStream::StringStream((storm::StringStream *)v10);
    LOBYTE(v11) = 1;
    storm::operator<<(v10, v9);
    v1 = (const char *)std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::c_str("TGOnline\\StormManager.cpp");
    storm::assert::AssertFunction((storm::assert *)"!( (_eres).GetErrorCode() < 0 )", v1, v3, (const char *)0x7E);
    LOBYTE(v11) = 0;
    storm::StringStream::~StringStream((storm::StringStream *)v10);
  }
  v11 = -1;
  storm::EResult::~EResult((CDHtmlElementEventSink *)v9);
  storm::RefCountedObject::ReleaseInstance(*((storm::RefCountedObject **)this + 4));
  *((_DWORD *)this + 4) = 0;
  SessionController = storm::SimpleConnectivityFacade::GetSessionController(*((storm::SimpleConnectivityFacade **)this
                                                                            + 663));
  v6 = *((_DWORD *)this + 679);
  if ( v6 )
    return storm::SimpleSessionController::RemoveSessionHandlerObserver(SessionController, v6 + 60, v4);
  else
    return storm::SimpleSessionController::RemoveSessionHandlerObserver(SessionController, 0, v4);
}


// address=[0x1650390]
// Decompiled from void __thiscall StormManager::CreateStormControllers(StormManager *this)
void  StormManager::CreateStormControllers(void) {
  
  const struct storm::ApplicationId *v1; // eax
  struct storm::SimpleGroupController *GroupController; // eax
  storm::SimpleGroupController *v3; // eax
  struct storm::SimpleSessionController *v4; // eax
  char v5; // [esp-5Ch] [ebp-23Ch] BYREF
  int v6; // [esp-58h] [ebp-238h]
  _BYTE *v7; // [esp-54h] [ebp-234h]
  _DWORD v8[7]; // [esp-50h] [ebp-230h] BYREF
  int v9; // [esp-34h] [ebp-214h] BYREF
  int v10; // [esp-30h] [ebp-210h]
  int v11; // [esp-2Ch] [ebp-20Ch]
  int v12; // [esp-28h] [ebp-208h] BYREF
  int v13; // [esp-24h] [ebp-204h]
  int v14; // [esp-20h] [ebp-200h]
  int v15; // [esp-1Ch] [ebp-1FCh]
  int v16; // [esp-18h] [ebp-1F8h]
  int v17; // [esp-14h] [ebp-1F4h]
  int v18; // [esp-10h] [ebp-1F0h]
  int v19; // [esp-Ch] [ebp-1ECh]
  int v20; // [esp-8h] [ebp-1E8h]
  struct storm::SimpleGroupHandler::Observer *v21; // [esp-4h] [ebp-1E4h]
  int v22; // [esp+0h] [ebp-1E0h]
  int v23; // [esp+4h] [ebp-1DCh]
  int v24; // [esp+8h] [ebp-1D8h]
  int *v25; // [esp+Ch] [ebp-1D4h]
  int *v26; // [esp+10h] [ebp-1D0h]
  int v27; // [esp+38h] [ebp-1A8h]
  int *v28; // [esp+3Ch] [ebp-1A4h]
  int *v29; // [esp+40h] [ebp-1A0h]
  int v30; // [esp+44h] [ebp-19Ch]
  int *v31; // [esp+48h] [ebp-198h]
  int *v32; // [esp+4Ch] [ebp-194h]
  int *v33; // [esp+54h] [ebp-18Ch]
  int *v34; // [esp+58h] [ebp-188h]
  int v35; // [esp+5Ch] [ebp-184h]
  int v36; // [esp+60h] [ebp-180h]
  char *v37; // [esp+64h] [ebp-17Ch]
  _DWORD *v38; // [esp+68h] [ebp-178h]
  int v39; // [esp+6Ch] [ebp-174h]
  _BYTE v40[8]; // [esp+80h] [ebp-160h] BYREF
  _BYTE v41[8]; // [esp+88h] [ebp-158h] BYREF
  int (__stdcall *v42)(CDaoIndexFieldInfo *, int); // [esp+A0h] [ebp-140h] BYREF
  void *v43; // [esp+A4h] [ebp-13Ch]
  int v44; // [esp+A8h] [ebp-138h]
  int v45; // [esp+B4h] [ebp-12Ch]
  void (__thiscall *v46)(OnlineManager *__hidden, const struct storm::StormGameSetupMessage *, unsigned int); // [esp+B8h] [ebp-128h] BYREF
  int v47; // [esp+BCh] [ebp-124h] BYREF
  void (__thiscall *v48)(OnlineManager *__hidden, const struct storm::StormPlayerMessage *, unsigned int); // [esp+C0h] [ebp-120h] BYREF
  int v49; // [esp+C4h] [ebp-11Ch] BYREF
  void *v50; // [esp+C8h] [ebp-118h]
  int v51; // [esp+CCh] [ebp-114h] BYREF
  int v52; // [esp+D0h] [ebp-110h]
  struct storm::SimpleSessionHandler *(__thiscall *v53)(StormManager *__hidden, const struct storm::StringId *); // [esp+D4h] [ebp-10Ch] BYREF
  StormManager *v54; // [esp+D8h] [ebp-108h] BYREF
  int v55; // [esp+DCh] [ebp-104h]
  int (__stdcall *v56)(void **); // [esp+E0h] [ebp-100h] BYREF
  _DWORD v57[2]; // [esp+E4h] [ebp-FCh] BYREF
  void *v58; // [esp+ECh] [ebp-F4h]
  int v59; // [esp+F0h] [ebp-F0h]
  struct storm::SimpleGroupHandler::Observer *v60; // [esp+F4h] [ebp-ECh]
  int v61; // [esp+F8h] [ebp-E8h]
  storm::SimpleSessionController *SessionController; // [esp+FCh] [ebp-E4h]
  struct storm::SimpleSessionHandler::Observer *v63; // [esp+100h] [ebp-E0h]
  int v64; // [esp+104h] [ebp-DCh]
  int v65; // [esp+108h] [ebp-D8h]
  storm::PeerChannelController *v66; // [esp+10Ch] [ebp-D4h]
  int v67; // [esp+110h] [ebp-D0h]
  storm::SimpleConnectivityFacade *v68; // [esp+114h] [ebp-CCh]
  int Instance; // [esp+118h] [ebp-C8h]
  storm::SimpleUbiServicesControllerClientImpl *v70; // [esp+11Ch] [ebp-C4h]
  _BYTE *v71; // [esp+120h] [ebp-C0h]
  _BYTE v72[12]; // [esp+124h] [ebp-BCh] BYREF
  StormManager *v73; // [esp+130h] [ebp-B0h]
  _BYTE v74[44]; // [esp+134h] [ebp-ACh] BYREF
  int v75; // [esp+1DCh] [ebp-4h]

  v73 = this;
  storm::SimpleConnectivityFacade::DesiredState::DesiredState((storm::SimpleConnectivityFacade::DesiredState *)v72);
  v72[0] = 1;
  v72[4] = 1;
  v72[3] = 1;
  v72[1] = 1;
  v72[2] = 1;
  v43 = storm::memory::internal::EalAllocator::New(
          0xE8u,
          8u,
          1093636239,
          "storm::SimpleUbiServicesControllerClientImpl",
          "TGOnline\\StormManager.cpp",
          0x8Fu);
  v70 = (storm::SimpleUbiServicesControllerClientImpl *)operator new(0xE8u, v43);
  v75 = 0;
  if ( v70 )
  {
    storm::ApplicationDescriptor::GetApplicationId((StormManager *)((char *)v73 + 2584));
    v59 = storm::SimpleUbiServicesControllerClientImpl::SimpleUbiServicesControllerClientImpl(v70, v1, 0);
  }
  else
  {
    v59 = 0;
  }
  v44 = v59;
  v75 = -1;
  *((_DWORD *)v73 + 678) = v59;
  v72[11] = 1;
  Instance = UPlay::UPlayManager::GetInstance(1);
  v71 = (_BYTE *)(*(int (__thiscall **)(int))(*(_DWORD *)Instance + 12))(Instance);
  if ( v71 && *v71 )
  {
    storm::memory::MakeShared<storm::SimpleOnlinePlayerUplay,char const *>(v41, (char)v71);
    v75 = 1;
    std::shared_ptr<storm::SimpleOnlinePlayerInterface>::shared_ptr<storm::SimpleOnlinePlayerInterface>(v41);
    LOBYTE(v75) = 2;
    storm::SimpleUbiServicesControllerClientImpl::SetOnlinePlayer(v40);
    LOBYTE(v75) = 1;
    std::shared_ptr<storm::SimpleOnlinePlayerInterface>::~shared_ptr<storm::SimpleOnlinePlayerInterface>(v22, v23);
    v75 = -1;
    std::shared_ptr<storm::SimpleOnlinePlayerUplay>::~shared_ptr<storm::SimpleOnlinePlayerUplay>(v22, v23);
  }
  v50 = storm::memory::internal::EalAllocator::New(
          0x418u,
          8u,
          1093636267,
          "storm::SimpleConnectivityFacade",
          "TGOnline\\StormManager.cpp",
          0xABu);
  v68 = (storm::SimpleConnectivityFacade *)operator new(0x418u, v50);
  v75 = 13;
  if ( v68 )
    v67 = storm::SimpleConnectivityFacade::SimpleConnectivityFacade(
            v68,
            *((_BYTE *)v73 + 1638),
            *((struct storm::SimpleUbiServicesControllerBase **)v73 + 678),
            (StormManager *)((char *)v73 + 1340),
            (const struct storm::SimpleConnectivityFacade::DesiredState *)v72,
            0);
  else
    v67 = 0;
  v45 = v67;
  v75 = -1;
  *((_DWORD *)v73 + 663) = v67;
  storm::SimpleConnectivityFacade::UseStormMatchmaking(*((storm::SimpleConnectivityFacade **)v73 + 663));
  v58 = storm::memory::internal::EalAllocator::New(
          0x108u,
          8u,
          1093636270,
          "storm::PeerChannelController",
          "TGOnline\\StormManager.cpp",
          0xAEu);
  v66 = (storm::PeerChannelController *)operator new(0x108u, v58);
  v75 = 14;
  if ( v66 )
    v65 = storm::PeerChannelController::PeerChannelController(v66);
  else
    v65 = 0;
  v57[1] = v65;
  v75 = -1;
  *((_DWORD *)v73 + 679) = v65;
  SessionController = storm::SimpleConnectivityFacade::GetSessionController(*((storm::SimpleConnectivityFacade **)v73
                                                                            + 663));
  v64 = *((_DWORD *)v73 + 679);
  if ( v64 )
    v63 = (struct storm::SimpleSessionHandler::Observer *)(v64 + 60);
  else
    v63 = 0;
  storm::SimpleSessionController::AddSessionHandlerObserver(SessionController, v63);
  storm::SimpleResilientPeerChannelController::SetSessionController(
    *((storm::SimpleResilientPeerChannelController **)v73 + 679),
    SessionController);
  GroupController = storm::SimpleConnectivityFacade::GetGroupController(*((COleIPFrameWnd **)v73 + 663));
  storm::SimpleResilientPeerChannelController::SetGroupController(
    *((storm::SimpleResilientPeerChannelController **)v73 + 679),
    GroupController);
  v61 = *((_DWORD *)v73 + 679);
  if ( v61 )
    v60 = (struct storm::SimpleGroupHandler::Observer *)(v61 + 64);
  else
    v60 = 0;
  v21 = v60;
  v3 = storm::SimpleConnectivityFacade::GetGroupController(*((COleIPFrameWnd **)v73 + 663));
  storm::SimpleGroupController::AddGroupHandlerObserver(v3, v21);
  v57[0] = v73;
  v56 = StormManager::DeleteSessionHandlerCallback;
  v54 = v73;
  v53 = StormManager::CreateSessionHandler;
  v26 = &v12;
  v25 = &v9;
  std::bind<void (__thiscall StormManager::*)(storm::SimpleSessionHandler *),StormManager * const,std::_Ph<1> const &>(
    &v9,
    &v56,
    v57,
    &unk_382F26B);
  v55 = std::function<void __cdecl (storm::SimpleSessionHandler *)>::function<void __cdecl (storm::SimpleSessionHandler *)>(
          v9,
          v10,
          v11);
  v39 = v55;
  v75 = 15;
  v38 = v8;
  v37 = &v5;
  std::bind<storm::SimpleSessionHandler * (__thiscall StormManager::*)(storm::StringId const &),StormManager * const,std::_Ph<1> const &>(
    &v5,
    &v53,
    &v54,
    &unk_382F26B);
  v52 = std::function<storm::SimpleSessionHandler * __cdecl (storm::StringId const &)>::function<storm::SimpleSessionHandler * __cdecl (storm::StringId const &)>(
          v5,
          v6,
          v7);
  v36 = v52;
  LOBYTE(v75) = 16;
  v7 = v74;
  v4 = storm::SimpleConnectivityFacade::GetSessionController(*((storm::SimpleConnectivityFacade **)v73 + 663));
  v75 = -1;
  v35 = storm::SimpleSessionController::RegisterCreateAndDeleteSessionHandlerCallback(
          v4,
          v7,
          v8[0],
          v8[1],
          v8[2],
          v8[3],
          v8[4],
          v8[5],
          v8[6],
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21);
  storm::EResult::~EResult((CDHtmlElementEventSink *)v74);
  v51 = OnlineManager::GetInstance();
  v42 = OnlineManager::OnNewMessage;
  v34 = &v12;
  v33 = &v9;
  std::bind<void (__thiscall OnlineManager::*)(storm::StormMessage const *,unsigned long),OnlineManager *,std::_Ph<1> const &,std::_Ph<2> const &>(
    &v9,
    &v42,
    &v51,
    &unk_382F26B,
    &unk_382F2C1);
  v24 = std::function<void __cdecl (storm::StormMessage const *,unsigned long)>::function<void __cdecl (storm::StormMessage const *,unsigned long)>(
          v9,
          v10,
          v11);
  (*(void (__thiscall **)(_DWORD, int, int, int, int, int, int, int, int, int, struct storm::SimpleGroupHandler::Observer *))(**((_DWORD **)v73 + 679) + 404))(
    *((_DWORD *)v73 + 679),
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21);
  v49 = OnlineManager::GetInstance();
  v48 = OnlineManager::OnNewPlayerMessage;
  v32 = &v12;
  v31 = &v9;
  std::bind<void (__thiscall OnlineManager::*)(storm::StormPlayerMessage const *,unsigned long),OnlineManager *,std::_Ph<1> const &,std::_Ph<2> const &>(
    &v9,
    &v48,
    &v49,
    &unk_382F26B,
    &unk_382F2C1);
  v30 = std::function<void __cdecl (storm::StormPlayerMessage const *,unsigned long)>::function<void __cdecl (storm::StormPlayerMessage const *,unsigned long)>(
          v9,
          v10,
          v11);
  (*(void (__thiscall **)(_DWORD, int, int, int, int, int, int, int, int, int, struct storm::SimpleGroupHandler::Observer *))(**((_DWORD **)v73 + 679) + 408))(
    *((_DWORD *)v73 + 679),
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21);
  v47 = OnlineManager::GetInstance();
  v46 = OnlineManager::OnNewGameSetupMessage;
  v29 = &v12;
  v28 = &v9;
  std::bind<void (__thiscall OnlineManager::*)(storm::StormGameSetupMessage const *,unsigned long),OnlineManager *,std::_Ph<1> const &,std::_Ph<2> const &>(
    &v9,
    &v46,
    &v47,
    &unk_382F26B,
    &unk_382F2C1);
  v27 = std::function<void __cdecl (storm::StormGameSetupMessage const *,unsigned long)>::function<void __cdecl (storm::StormGameSetupMessage const *,unsigned long)>(
          v9,
          v10,
          v11);
  (*(void (__thiscall **)(_DWORD, int, int, int, int, int, int, int, int, int, struct storm::SimpleGroupHandler::Observer *))(**((_DWORD **)v73 + 679) + 412))(
    *((_DWORD *)v73 + 679),
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21);
  StormManager::RegisterStormControllers(v73);
}


// address=[0x1650c50]
// Decompiled from void __thiscall StormManager::DestroyStormControllers(StormManager *this)
void  StormManager::DestroyStormControllers(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // [esp-8h] [ebp-94h]
  int v5; // [esp-4h] [ebp-90h]
  int v6; // [esp-4h] [ebp-90h]
  _BYTE v8[44]; // [esp+4h] [ebp-88h] BYREF
  _BYTE v9[44]; // [esp+30h] [ebp-5Ch] BYREF
  _BYTE v10[44]; // [esp+5Ch] [ebp-30h] BYREF

  v1 = storm::SimpleAsyncOp::Registry(v10);
  storm::SimpleController::Teardown(v1, v5);
  storm::EResult::~EResult((CDHtmlElementEventSink *)v10);
  v2 = storm::SimpleAsyncOp::Registry(v9);
  storm::SimpleController::Shutdown(v2, v6);
  storm::EResult::~EResult((CDHtmlElementEventSink *)v9);
  v3 = storm::SimpleAsyncOp::Registry("TGOnline\\StormManager.cpp");
  storm::memory::internal::EalAllocator::Delete<storm::SimpleAsyncOp::AORegistry>(v3, v4, 377);
  StormManager::UnregisterStormControllers(this);
  storm::SimpleGlobalController::Teardown((char *)this + 68, v8);
  storm::EResult::~EResult((CDHtmlElementEventSink *)v8);
}


// address=[0x1650cf0]
// Decompiled from void __thiscall StormManager::RegisterStormControllers(struct storm::SimpleController **this)
void  StormManager::RegisterStormControllers(void) {
  
  storm::SimpleGlobalController::AddEchoController((storm::SimpleGlobalController *)(this + 17), this[663]);
  storm::SimpleGlobalController::AddEchoController((storm::SimpleGlobalController *)(this + 17), this[679]);
}


// address=[0x1650d30]
// Decompiled from void __thiscall StormManager::UnregisterStormControllers(struct storm::SimpleController **this)
void  StormManager::UnregisterStormControllers(void) {
  
  storm::SimpleGlobalController::RemoveEchoController((storm::SimpleGlobalController *)(this + 17), this[663]);
  storm::SimpleGlobalController::RemoveEchoController((storm::SimpleGlobalController *)(this + 17), this[679]);
}


// address=[0x1650d70]
// Decompiled from void __thiscall StormManager::InitAndStartupEcho(StormManager *this)
void  StormManager::InitAndStartupEcho(void) {
  
  int ClassTypeId; // eax
  int v2; // eax
  struct storm::SimpleController *v3; // eax
  int v4; // ecx
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  int v8; // eax
  _DWORD *v9; // eax
  storm::SimpleAsyncOp *v10; // eax
  struct storm::SimpleAsyncOp *v11; // eax
  char v12; // [esp-78h] [ebp-3E0h] BYREF
  int v13; // [esp-74h] [ebp-3DCh]
  int v14; // [esp-70h] [ebp-3D8h]
  int v15; // [esp-6Ch] [ebp-3D4h]
  int v16; // [esp-68h] [ebp-3D0h]
  int v17; // [esp-64h] [ebp-3CCh]
  int v18; // [esp-60h] [ebp-3C8h]
  int v19; // [esp-5Ch] [ebp-3C4h]
  int v20; // [esp-58h] [ebp-3C0h]
  int v21; // [esp-54h] [ebp-3BCh]
  char v22; // [esp-50h] [ebp-3B8h] BYREF
  int v23; // [esp-4Ch] [ebp-3B4h]
  int v24; // [esp-48h] [ebp-3B0h]
  int v25; // [esp-44h] [ebp-3ACh]
  int v26; // [esp-40h] [ebp-3A8h]
  int v27; // [esp-3Ch] [ebp-3A4h]
  int v28; // [esp-38h] [ebp-3A0h]
  int v29; // [esp-34h] [ebp-39Ch]
  int v30; // [esp-30h] [ebp-398h]
  int v31; // [esp-2Ch] [ebp-394h]
  char v32; // [esp-28h] [ebp-390h] BYREF
  int v33; // [esp-24h] [ebp-38Ch]
  int v34; // [esp-20h] [ebp-388h]
  void (__cdecl *v35)(struct storm::SimpleResultRelayer *, void *); // [esp-1Ch] [ebp-384h]
  StormManager *v36; // [esp-18h] [ebp-380h]
  _BYTE *v37; // [esp-14h] [ebp-37Ch]
  int v38; // [esp-10h] [ebp-378h] BYREF
  int v39; // [esp-Ch] [ebp-374h]
  int v40; // [esp-8h] [ebp-370h]
  int v41; // [esp-4h] [ebp-36Ch]
  int v42; // [esp+0h] [ebp-368h]
  char *v43; // [esp+10h] [ebp-358h]
  int v44; // [esp+18h] [ebp-350h]
  char *v45; // [esp+1Ch] [ebp-34Ch]
  int v46; // [esp+20h] [ebp-348h]
  char *v47; // [esp+24h] [ebp-344h]
  int v48; // [esp+28h] [ebp-340h]
  int v49; // [esp+2Ch] [ebp-33Ch]
  int *v50; // [esp+30h] [ebp-338h]
  int v51; // [esp+34h] [ebp-334h]
  int v52; // [esp+38h] [ebp-330h]
  char *v53; // [esp+3Ch] [ebp-32Ch]
  int v54; // [esp+44h] [ebp-324h]
  char *v55; // [esp+48h] [ebp-320h]
  int v56; // [esp+4Ch] [ebp-31Ch]
  char *v57; // [esp+50h] [ebp-318h]
  int v58; // [esp+54h] [ebp-314h]
  int v59; // [esp+58h] [ebp-310h]
  char *v60; // [esp+5Ch] [ebp-30Ch]
  int v61; // [esp+64h] [ebp-304h]
  char *v62; // [esp+68h] [ebp-300h]
  int v63; // [esp+6Ch] [ebp-2FCh]
  char *v64; // [esp+70h] [ebp-2F8h]
  int v65; // [esp+74h] [ebp-2F4h]
  int v66; // [esp+78h] [ebp-2F0h]
  int v67; // [esp+7Ch] [ebp-2ECh]
  int v68; // [esp+80h] [ebp-2E8h]
  int v69; // [esp+84h] [ebp-2E4h]
  int v70; // [esp+88h] [ebp-2E0h]
  int v71; // [esp+8Ch] [ebp-2DCh]
  int v72; // [esp+90h] [ebp-2D8h]
  int v73; // [esp+94h] [ebp-2D4h]
  int Instance; // [esp+98h] [ebp-2D0h]
  char v75; // [esp+9Dh] [ebp-2CBh] BYREF
  char v76; // [esp+9Eh] [ebp-2CAh]
  char v77; // [esp+9Fh] [ebp-2C9h]
  char v78; // [esp+A0h] [ebp-2C8h]
  char v79; // [esp+A1h] [ebp-2C7h]
  char v80; // [esp+A2h] [ebp-2C6h]
  char v81; // [esp+A3h] [ebp-2C5h]
  StormManager *v82; // [esp+A4h] [ebp-2C4h]
  _BYTE v83[160]; // [esp+A8h] [ebp-2C0h] BYREF
  _BYTE v84[4]; // [esp+288h] [ebp-E0h] BYREF
  _BYTE v85[44]; // [esp+28Ch] [ebp-DCh] BYREF
  _BYTE v86[44]; // [esp+2B8h] [ebp-B0h] BYREF
  _BYTE v87[44]; // [esp+2E4h] [ebp-84h] BYREF
  _BYTE v88[44]; // [esp+310h] [ebp-58h] BYREF
  _BYTE v89[28]; // [esp+33Ch] [ebp-2Ch] BYREF
  int v90; // [esp+364h] [ebp-4h]

  v82 = this;
  *((_BYTE *)this + 2145) = 0;
  *((_BYTE *)v82 + 1639) = 1;
  *((_WORD *)v82 + 717) = 2;
  *((_WORD *)v82 + 967) = 0;
  *((_BYTE *)v82 + 1928) = 1;
  *((_DWORD *)v82 + 640) = storm::Handler::GetHandlerRefId(*((storm::Handler **)v82 + 679));
  ClassTypeId = storm::SimplePeerDescriptor_Matchmaking::GetClassTypeId();
  storm::StringId::operator=(ClassTypeId);
  storm::SimpleGlobalController::GeneratePeerGUID((StormManager *)((char *)v82 + 1428));
  storm::SimpleGlobalController::SetDefaultStartUpParameters((StormManager *)((char *)v82 + 1428));
  v41 = 0;
  v40 = 0;
  v39 = *((_DWORD *)v82 + 4);
  v2 = storm::SimpleAsyncOp::Registry(v88);
  storm::SimpleController::Init(v2, v38, v39, 0, 0);
  storm::EResult::~EResult((CDHtmlElementEventSink *)v88);
  v3 = (struct storm::SimpleController *)storm::SimpleAsyncOp::Registry(v42);
  storm::SimpleGlobalController::AddEchoController((StormManager *)((char *)v82 + 68), v3);
  storm::SimpleGlobalController::Init((char *)v82 + 68, v87, *((_DWORD *)v82 + 4), *((_DWORD *)v82 + 3));
  storm::EResult::~EResult((CDHtmlElementEventSink *)v87);
  storm::Core::AddHandler(*((_DWORD *)v82 + 4), v86, *((_DWORD *)v82 + 679), "TGOnline\\StormManager.cpp", 408);
  storm::EResult::~EResult((CDHtmlElementEventSink *)v86);
  Instance = UPlay::UPlayManager::GetInstance(v4);
  if ( !(*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)Instance + 32))(Instance) )
  {
    v81 = 0;
    v80 = 0;
    v53 = &v32;
    v73 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(0);
    v46 = v73;
    v90 = 0;
    v45 = &v22;
    v72 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(v80);
    v44 = v72;
    LOBYTE(v90) = 1;
    v5 = (_DWORD *)unknown_libname_12621(v82);
    v43 = &v12;
    v66 = std::function<storm::EResult __cdecl (storm::SimpleAsyncOp &)>::function<storm::EResult __cdecl (storm::SimpleAsyncOp &)>(*v5);
    v90 = -1;
    v65 = storm::SimpleAsyncOp::LinkOp::LinkOp(
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41);
    v90 = 2;
    v79 = 0;
    v78 = 0;
    v64 = &v32;
    v71 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(0);
    v63 = v71;
    LOBYTE(v90) = 3;
    v62 = &v22;
    v70 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(v78);
    v61 = v70;
    LOBYTE(v90) = 4;
    v6 = (_DWORD *)unknown_libname_12619(v82);
    v60 = &v12;
    v59 = std::function<storm::EResult __cdecl (storm::SimpleAsyncOp &)>::function<storm::EResult __cdecl (storm::SimpleAsyncOp &)>(*v6);
    LOBYTE(v90) = 2;
    v58 = storm::SimpleAsyncOp::LinkOp::LinkOp(
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41);
    LOBYTE(v90) = 5;
    v77 = 0;
    v76 = 0;
    v57 = &v32;
    v69 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(0);
    v56 = v69;
    LOBYTE(v90) = 6;
    v55 = &v22;
    v68 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(v76);
    v54 = v68;
    LOBYTE(v90) = 7;
    v7 = (_DWORD *)unknown_libname_12625(v82);
    v47 = &v12;
    v52 = std::function<storm::EResult __cdecl (storm::SimpleAsyncOp &)>::function<storm::EResult __cdecl (storm::SimpleAsyncOp &)>(*v7);
    LOBYTE(v90) = 5;
    v51 = storm::SimpleAsyncOp::LinkOp::LinkOp(
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41);
    v90 = 8;
    std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>("Startup ECHO");
    LOBYTE(v90) = 9;
    v8 = std::allocator<storm::SimpleAsyncOp::LinkOp>::allocator<storm::SimpleAsyncOp::LinkOp>(&v75);
    v50 = &v38;
    v37 = (_BYTE *)v8;
    v9 = (_DWORD *)std::initializer_list<storm::SimpleAsyncOp::LinkOp>::initializer_list<storm::SimpleAsyncOp::LinkOp>(
                     v83,
                     v84);
    v67 = std::vector<storm::SimpleAsyncOp::LinkOp>::vector<storm::SimpleAsyncOp::LinkOp>(*v9, v9[1], v37);
    v49 = v67;
    LOBYTE(v90) = 10;
    v37 = v85;
    v36 = v82;
    v35 = StormManager::StartEchoFinished;
    v10 = (storm::SimpleAsyncOp *)(*(int (__thiscall **)(_DWORD, _BYTE *, int))(**((_DWORD **)v82 + 676) + 16))(
                                    *((_DWORD *)v82 + 676),
                                    v89,
                                    50000);
    v11 = storm::SimpleAsyncOp::WithCompletionCB(v10, v35, v36);
    LOBYTE(v90) = 9;
    v48 = storm::SimpleAsyncOp::Launch(v11, v37, v38, v39, v40, v41);
    storm::EResult::~EResult((CDHtmlElementEventSink *)v85);
    LOBYTE(v90) = 8;
    std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::~basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>(v89);
    v90 = -1;
    `eh vector destructor iterator'(v83, 0xA0u, 3u, storm::SimpleAsyncOp::LinkOp::~LinkOp);
  }
}


// address=[0x16513d0]
// Decompiled from void __thiscall StormManager::OnStartEchoFinished(StormManager *this)
void  StormManager::OnStartEchoFinished(void) {
  
  ;
}


// address=[0x16513e0]
// Decompiled from void __thiscall StormManager::ShutdownEcho(StormManager *this)
void  StormManager::ShutdownEcho(void) {
  
  const struct storm::StringId *ClassTypeId; // eax
  struct storm::SimpleController *v2; // eax
  int v3; // ecx
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  int v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // eax
  _DWORD *v11; // eax
  _DWORD *v12; // eax
  _DWORD *v13; // eax
  storm::SimpleController *v14; // eax
  char v15; // [esp-B8h] [ebp-4F0h] BYREF
  int v16; // [esp-B4h] [ebp-4ECh]
  int v17; // [esp-B0h] [ebp-4E8h]
  int v18; // [esp-ACh] [ebp-4E4h]
  int v19; // [esp-A8h] [ebp-4E0h]
  int v20; // [esp-A4h] [ebp-4DCh]
  int v21; // [esp-A0h] [ebp-4D8h]
  int v22; // [esp-9Ch] [ebp-4D4h]
  int v23; // [esp-98h] [ebp-4D0h]
  int v24; // [esp-94h] [ebp-4CCh]
  int v25; // [esp-90h] [ebp-4C8h]
  char v26; // [esp-8Ch] [ebp-4C4h] BYREF
  int v27; // [esp-88h] [ebp-4C0h]
  int v28; // [esp-84h] [ebp-4BCh]
  int v29; // [esp-80h] [ebp-4B8h]
  int v30; // [esp-7Ch] [ebp-4B4h]
  int v31; // [esp-78h] [ebp-4B0h] BYREF
  int v32; // [esp-74h] [ebp-4ACh]
  int v33; // [esp-70h] [ebp-4A8h]
  int v34; // [esp-6Ch] [ebp-4A4h]
  int v35; // [esp-68h] [ebp-4A0h]
  int v36; // [esp-64h] [ebp-49Ch] BYREF
  int v37; // [esp-60h] [ebp-498h]
  int v38; // [esp-5Ch] [ebp-494h]
  int v39; // [esp-58h] [ebp-490h]
  int v40; // [esp-54h] [ebp-48Ch]
  int v41; // [esp-50h] [ebp-488h] BYREF
  int v42; // [esp-4Ch] [ebp-484h]
  int v43; // [esp-48h] [ebp-480h]
  int v44; // [esp-44h] [ebp-47Ch]
  int v45; // [esp-40h] [ebp-478h]
  int v46; // [esp-3Ch] [ebp-474h] BYREF
  int v47; // [esp-38h] [ebp-470h]
  int v48; // [esp-34h] [ebp-46Ch]
  int v49; // [esp-30h] [ebp-468h]
  int v50; // [esp-2Ch] [ebp-464h]
  int v51; // [esp-28h] [ebp-460h] BYREF
  int v52; // [esp-24h] [ebp-45Ch]
  int v53; // [esp-20h] [ebp-458h]
  int v54; // [esp-1Ch] [ebp-454h]
  int v55; // [esp-18h] [ebp-450h]
  _BYTE *v56; // [esp-14h] [ebp-44Ch]
  int v57; // [esp-10h] [ebp-448h] BYREF
  int v58; // [esp-Ch] [ebp-444h]
  int v59; // [esp-8h] [ebp-440h]
  double v60; // [esp-4h] [ebp-43Ch]
  double v61; // [esp+4h] [ebp-434h]
  int v62; // [esp+Ch] [ebp-42Ch]
  unsigned int v63[48]; // [esp+10h] [ebp-428h] BYREF
  unsigned int v64; // [esp+D4h] [ebp-364h]
  unsigned int v65; // [esp+D8h] [ebp-360h]
  unsigned int v66; // [esp+DCh] [ebp-35Ch]
  unsigned int v67; // [esp+E0h] [ebp-358h]
  int v68; // [esp+E4h] [ebp-354h]
  int v69; // [esp+E8h] [ebp-350h]
  int v70; // [esp+ECh] [ebp-34Ch]
  int v71; // [esp+F0h] [ebp-348h]
  unsigned int v72; // [esp+F4h] [ebp-344h]
  unsigned int v73; // [esp+F8h] [ebp-340h]
  unsigned int v74; // [esp+FCh] [ebp-33Ch]
  unsigned int v75; // [esp+100h] [ebp-338h]
  unsigned int v76; // [esp+104h] [ebp-334h]
  unsigned int v77; // [esp+108h] [ebp-330h]
  unsigned int v78; // [esp+10Ch] [ebp-32Ch]
  unsigned int v79; // [esp+110h] [ebp-328h]
  unsigned int v80; // [esp+114h] [ebp-324h]
  int Instance; // [esp+118h] [ebp-320h]
  char v82; // [esp+11Fh] [ebp-319h] BYREF
  char v83; // [esp+120h] [ebp-318h]
  char v84; // [esp+121h] [ebp-317h]
  char v85; // [esp+122h] [ebp-316h]
  char v86; // [esp+123h] [ebp-315h]
  char v87; // [esp+124h] [ebp-314h]
  char v88; // [esp+125h] [ebp-313h]
  char v89; // [esp+126h] [ebp-312h]
  char v90; // [esp+127h] [ebp-311h]
  StormManager *v91; // [esp+128h] [ebp-310h]
  char v92; // [esp+12Fh] [ebp-309h] BYREF
  _BYTE v93[160]; // [esp+130h] [ebp-308h] BYREF
  _BYTE v94[4]; // [esp+3B0h] [ebp-88h] BYREF
  _BYTE v95[44]; // [esp+3B4h] [ebp-84h] BYREF
  _BYTE v96[44]; // [esp+3E0h] [ebp-58h] BYREF
  _BYTE v97[28]; // [esp+40Ch] [ebp-2Ch] BYREF
  int v98; // [esp+434h] [ebp-4h]

  v91 = this;
  ClassTypeId = (const struct storm::StringId *)GameSessionDescriptor::GetClassTypeId();
  LODWORD(v60) = storm::StringId::StringId((storm::StringId *)v63, ClassTypeId);
  storm::echo::registry::RemoveDataContainerType((struct CDataExchange *)v95, v60, v61, v62, v63[0]);
  storm::EResult::~EResult((CDHtmlElementEventSink *)v95);
  v2 = (struct storm::SimpleController *)storm::SimpleAsyncOp::Registry(HIDWORD(v60));
  storm::SimpleGlobalController::RemoveEchoController((StormManager *)((char *)v91 + 68), v2);
  Instance = UPlay::UPlayManager::GetInstance(v3);
  if ( !(*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)Instance + 32))(Instance) )
  {
    v92 = 0;
    v90 = 0;
    v89 = 0;
    v63[20] = (unsigned int)&v51;
    v80 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(0);
    v63[5] = v80;
    v98 = 0;
    v63[4] = (unsigned int)&v41;
    v65 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(v89);
    v63[3] = v65;
    LOBYTE(v98) = 1;
    v4 = (_DWORD *)unknown_libname_12629(v91);
    v63[47] = (unsigned int)&v31;
    v63[46] = std::function<storm::EResult __cdecl (storm::SimpleAsyncOp &)>::function<storm::EResult __cdecl (storm::SimpleAsyncOp &)>(*v4);
    v98 = -1;
    v63[45] = storm::SimpleAsyncOp::LinkOp::LinkOp(
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                v55,
                v56,
                v57,
                v58,
                v59,
                LODWORD(v60));
    v98 = 2;
    v88 = 0;
    v87 = 0;
    v63[44] = (unsigned int)&v51;
    v66 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(0);
    v63[43] = v66;
    LOBYTE(v98) = 3;
    v63[42] = (unsigned int)&v41;
    v67 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(v87);
    v63[41] = v67;
    LOBYTE(v98) = 4;
    v5 = (_DWORD *)unknown_libname_12613(v91);
    v63[39] = (unsigned int)&v31;
    v63[38] = std::function<storm::EResult __cdecl (storm::SimpleAsyncOp &)>::function<storm::EResult __cdecl (storm::SimpleAsyncOp &)>(*v5);
    LOBYTE(v98) = 2;
    v63[37] = storm::SimpleAsyncOp::LinkOp::LinkOp(
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                v55,
                v56,
                v57,
                v58,
                v59,
                LODWORD(v60));
    LOBYTE(v98) = 5;
    v86 = 0;
    v85 = 0;
    v63[36] = (unsigned int)&v51;
    v64 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(0);
    v63[35] = v64;
    LOBYTE(v98) = 6;
    v63[34] = (unsigned int)&v41;
    v79 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(v85);
    v63[33] = v79;
    LOBYTE(v98) = 7;
    v6 = (_DWORD *)unknown_libname_12610(v91);
    v63[31] = (unsigned int)&v31;
    v63[30] = std::function<storm::EResult __cdecl (storm::SimpleAsyncOp &)>::function<storm::EResult __cdecl (storm::SimpleAsyncOp &)>(*v6);
    LOBYTE(v98) = 5;
    v63[29] = storm::SimpleAsyncOp::LinkOp::LinkOp(
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                v55,
                v56,
                v57,
                v58,
                v59,
                LODWORD(v60));
    LOBYTE(v98) = 8;
    v84 = 0;
    v83 = 0;
    v63[28] = (unsigned int)&v51;
    v78 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(0);
    v63[27] = v78;
    LOBYTE(v98) = 9;
    v63[26] = (unsigned int)&v41;
    v77 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(v83);
    v63[25] = v77;
    LOBYTE(v98) = 10;
    v7 = (_DWORD *)unknown_libname_12605(v91);
    v63[23] = (unsigned int)&v31;
    v63[22] = std::function<storm::EResult __cdecl (storm::SimpleAsyncOp &)>::function<storm::EResult __cdecl (storm::SimpleAsyncOp &)>(*v7);
    LOBYTE(v98) = 8;
    v63[21] = storm::SimpleAsyncOp::LinkOp::LinkOp(
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                v55,
                v56,
                v57,
                v58,
                v59,
                LODWORD(v60));
    v98 = 11;
    std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>("Shutdown STORM");
    LOBYTE(v98) = 12;
    v8 = std::allocator<storm::SimpleAsyncOp::LinkOp>::allocator<storm::SimpleAsyncOp::LinkOp>(&v82);
    v63[10] = (unsigned int)&v57;
    v56 = (_BYTE *)v8;
    v9 = (_DWORD *)std::initializer_list<storm::SimpleAsyncOp::LinkOp>::initializer_list<storm::SimpleAsyncOp::LinkOp>(
                     v93,
                     v94);
    v76 = std::vector<storm::SimpleAsyncOp::LinkOp>::vector<storm::SimpleAsyncOp::LinkOp>(*v9, v9[1], v56);
    v63[19] = v76;
    LOBYTE(v98) = 13;
    v56 = v96;
    v10 = (_DWORD *)unknown_libname_12611(&v92);
    v63[17] = (unsigned int)&v46;
    v75 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(*v10);
    v63[16] = v75;
    LOBYTE(v98) = 14;
    v11 = (_DWORD *)unknown_libname_12609(&v92);
    v63[14] = (unsigned int)&v36;
    v74 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(*v11);
    v63[13] = v74;
    LOBYTE(v98) = 15;
    v12 = (_DWORD *)unknown_libname_12600(&v92);
    v63[11] = (unsigned int)&v26;
    v73 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(*v12);
    v63[2] = v73;
    LOBYTE(v98) = 16;
    v25 = 1;
    v13 = (_DWORD *)unknown_libname_12603(v91);
    v63[8] = (unsigned int)&v15;
    v72 = std::function<void __cdecl (storm::SimpleAsyncOp &)>::function<void __cdecl (storm::SimpleAsyncOp &)>(*v13);
    v63[7] = v72;
    LOBYTE(v98) = 17;
    (*(void (__thiscall **)(_DWORD, _BYTE *, int))(**((_DWORD **)v91 + 676) + 16))(*((_DWORD *)v91 + 676), v97, 10000);
    LOBYTE(v98) = 16;
    v71 = storm::SimpleAsyncOp::WithActivity(v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25);
    LOBYTE(v98) = 15;
    v70 = storm::SimpleAsyncOp::OnTimeoutDo(v26, v27, v28, v29, v30, v31, v32, v33, v34, v35);
    LOBYTE(v98) = 14;
    v69 = storm::SimpleAsyncOp::OnFailureDo(v36, v37, v38, v39, v40, v41, v42, v43, v44, v45);
    LOBYTE(v98) = 13;
    v68 = storm::SimpleAsyncOp::OnSuccessDo(v46, v47, v48, v49, v50, v51, v52, v53, v54, v55);
    LOBYTE(v98) = 12;
    v63[6] = storm::SimpleAsyncOp::Launch(v68, v56, v57, v58, v59, LODWORD(v60));
    storm::EResult::~EResult((CDHtmlElementEventSink *)v96);
    LOBYTE(v98) = 11;
    std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::~basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>(v97);
    v98 = -1;
    `eh vector destructor iterator'(v93, 0xA0u, 4u, storm::SimpleAsyncOp::LinkOp::~LinkOp);
    while ( !v92 )
    {
      v14 = (storm::SimpleController *)storm::SimpleAsyncOp::Registry(HIDWORD(v60));
      storm::SimpleController::Update(v14);
      storm::ThisThread::SleepFor(30);
    }
  }
}


// address=[0x462bb88]
// [Decompilation failed for static class StormManager * StormManager::m_instance]

