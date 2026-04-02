#include "CDebugInfo.h"
#include "../../generated/Debug/CDebugInfo.h"

#include "CTrace.h"
#include "Framework.h"
#include "CBB/CBBSupport.h"

// Definitions for class CDebugInfo

SEnvironmentInfo CDebugInfo::m_EnvInfo = {};

// init at 0x012E1E80
std::string *CDebugInfo::m_strOS = new std::string[]{
  "UNDEFINED",
  "Windows 3.1 w/ win32s",
  "Windows 95A",
  "Windows 95",
  "Windows 98",
  "Windows 98SE",
  "Windows ME",
  "Windows 2xxx",
  "Windows 2000",
  "Windows NT 3.5",
  "Windows NT 4.0",
};

// address=[0x135e070]
// Decompiled from bool CDebugInfo::IsMMX()
bool __cdecl CDebugInfo::IsMMX(void) {
  return CDebugInfo::m_EnvInfo.bIsMMX;
}

//415B940 ;
HMODULE hWSALib;

//15CC720
bool __cdecl ImportWSAFunctions(void) {
  hWSALib = LoadLibraryA("WS2_32.DLL");
  _controlfp(0xA031Fu, 0x30F031Fu);
  if(!hWSALib && !(hWSALib = LoadLibraryA("wsock32.DLL"), _controlfp(0xA031Fu, 0x30F031Fu), hWSALib)) {
    BBSupportTracePrintF(3, "Error loading WS2_32.DLL or WSOCK32.DLL!");
    return 0;
  }
  // We just link agains these symbols, as we can just use winsock
  /*
  WSACleanup = GetProcAddress(hLibModule, "WSACleanup");
  if(!WSACleanup) {
    BBSupportTracePrintF(3, "Error getting WSACleanup!");
    return 0;
  }
  WSAGetLastError = GetProcAddress(hLibModule, "WSAGetLastError");
  if(!WSAGetLastError) {
    BBSupportTracePrintF(3, "Error getting WSAGetLastError!");
    return 0;
  }
  inet_addr = (unsigned int (__stdcall *)(const char *)) GetProcAddress(hLibModule, "inet_addr");
  if(!inet_addr) {
    BBSupportTracePrintF(3, "Error getting inet_addr!");
    return 0;
  }
  closesocket = (int (__stdcall *)(SOCKET)) GetProcAddress(hLibModule, "closesocket");
  if(!closesocket) {
    BBSupportTracePrintF(3, "Error getting closesocket!");
    return 0;
  }
  shutdown = (int (__stdcall *)(SOCKET, int)) GetProcAddress(hLibModule, "shutdown");
  if(!shutdown) {
    BBSupportTracePrintF(3, "Error getting shutdown!");
    return 0;
  }
  inet_ntoa = (char *(__stdcall *)(struct in_addr)) GetProcAddress(hLibModule, "inet_ntoa");
  if(!inet_ntoa) {
    BBSupportTracePrintF(3, "Error getting inet_ntoa!");
    return 0;
  }
  socket = (SOCKET (__stdcall *)(int, int, int)) GetProcAddress(hLibModule, "socket");
  if(!socket) {
    BBSupportTracePrintF(3, "Error getting socket!");
    return 0;
  }
  getsockname = (int (__stdcall *)(SOCKET, struct sockaddr *, int *)) GetProcAddress(
    hLibModule,
    "getsockname");
  if(!getsockname) {
    BBSupportTracePrintF(3, "Error getting getsockname!");
    return 0;
  }
  getsockopt = (int (__stdcall *)(SOCKET, int, int, char *, int *)) GetProcAddress(
    hLibModule,
    "getsockopt");
  if(!getsockopt) {
    BBSupportTracePrintF(3, "Error getting getsockopt!");
    return 0;
  }
  setsockopt = (int (__stdcall *)(SOCKET, int, int, const char *, int)) GetProcAddress(
    hLibModule,
    "setsockopt");
  if(!setsockopt) {
    BBSupportTracePrintF(3, "Error getting setsockopt!");
    return 0;
  }
  bind = (int (__stdcall *)(SOCKET, const struct sockaddr *, int)) GetProcAddress(
    hLibModule,
    "bind");
  if(!bind) {
    BBSupportTracePrintF(3, "Error getting bind!");
    return 0;
  }
  htons = (u_short (__stdcall *)(u_short)) GetProcAddress(hLibModule, "htons");
  if(!htons) {
    BBSupportTracePrintF(3, "Error getting htons!");
    return 0;
  }
  select = (int (__stdcall *)(int, fd_set *, fd_set *, fd_set *, const struct timeval *)) GetProcAddress(hLibModule, "select");
  if(!select) {
    BBSupportTracePrintF(3, "Error getting select!");
    return 0;
  }
  sendto = (int (__stdcall *)(SOCKET, const char *, int, int, const struct sockaddr *, int)) GetProcAddress(hLibModule, "sendto");
  if(!sendto) {
    BBSupportTracePrintF(3, "Error getting sendto!");
    return 0;
  }
  recvfrom = (int (__stdcall *)(SOCKET, char *, int, int, struct sockaddr *, int *)) GetProcAddress(hLibModule, "recvfrom");
  if(!recvfrom) {
    BBSupportTracePrintF(3, "Error getting recvfrom!");
    return 0;
  }
  WSAIoctl = (int (__stdcall *)(SOCKET, DWORD, LPVOID, DWORD, LPVOID, DWORD, LPDWORD, LPWSAOVERLAPPED, LPWSAOVERLAPPED_COMPLETION_ROUTINE)) GetProcAddress(hLibModule, "WSAIoctl");
  if(!WSAIoctl)
    BBSupportTracePrintF(3, "Error getting WSAIoctl!");
  WSAStartup = (int (__stdcall *)(WORD, LPWSADATA)) GetProcAddress(
    hLibModule,
    "WSAStartup");
  if(!WSAStartup) {
    BBSupportTracePrintF(3, "Error getting WSAStartup!");
    return 0;
  }
  gethostname = (int (__stdcall *)(char *, int)) GetProcAddress(
    hLibModule,
    "gethostname");
  if(!gethostname) {
    BBSupportTracePrintF(3, "Error getting WSAStartup!");
    return 0;
  }
  gethostbyname = (struct hostent *(__stdcall *)(const char *)) GetProcAddress(
    hLibModule,
    "gethostbyname");
  if(!gethostbyname) {
    BBSupportTracePrintF(3, "Error getting WSAStartup!");
    return 0;
  }
  ntohl = (u_long (__stdcall *)(u_long)) GetProcAddress(hLibModule, "ntohl");
  if(!ntohl) {
    BBSupportTracePrintF(3, "Error getting ntohl!");
    return 0;
  }
*/
  return 1;
}

// address=[0x1480a00]
// Decompiled from bool __cdecl CDebugInfo::CheckEnvironment(bool _bLogEnv)
bool __cdecl CDebugInfo::CheckEnvironment(bool _bLogEnv) {
  DWORD LastError; // eax MAPDST

  //memset(&CDebugInfo::m_EnvInfo, 0, 0x74u);
  if(!CDebugInfo::CheckOS()) {
    LastError = GetLastError();
    CTrace::Print("DebugInfo.cpp: Error calling CheckOS(); LastError: %d", LastError);
  }
  if(!CDebugInfo::CheckCPU()) {
    LastError = GetLastError();
    CTrace::Print("DebugInfo.cpp: Error calling CheckCPU(); LastError: %d", LastError);
  }
  if(!CDebugInfo::CheckMemory()) {
    LastError = GetLastError();
    CTrace::Print("DebugInfo.cpp: Error calling CheckMemory(); LastError: %d", LastError);
  }
  if(_bLogEnv)
    CDebugInfo::LogEnvironment();
  if(!CDebugInfo::IsWindowsNT40() || CDebugInfo::IsMMX()) {
    if(CDebugInfo::IsTargetPlatform()) {
      CDebugInfo::m_EnvInfo.bLoadedWSA = ImportWSAFunctions();
      if(!CDebugInfo::m_EnvInfo.bLoadedWSA)
        CTrace::Print("DebugInfo.cpp: Winsock2 not found !!!!");
      CDebugInfo::CheckGraphicsAdapter();
      return 1;
    } else {
      MessageBoxA(g_hWnd, "Settlers IV needs at least Windows NT4.0 or Windows 95!\nSiedler IV benötigt zumindest Windows NT4.0 oder Windows 95", "S4", 0x30u);
      return 0;
    }
  } else {
    MessageBoxA(g_hWnd, "Settlers IV running on Windows NT4.0 requires processor with MMX!\nSiedler IV unter Windows NT4.0 benötigt einen Prozessor mit MMX!", "S4", 0x30u);
    return 0;
  }
}


// address=[0x1480b10]
// Decompiled from bool CDebugInfo::IsTargetPlatform()
bool __cdecl CDebugInfo::IsTargetPlatform(void) {
  if(CDebugInfo::m_EnvInfo.sPlatformId == 2)
    return CDebugInfo::m_EnvInfo.sOSVersionMayor >= 4;
  if(CDebugInfo::m_EnvInfo.sPlatformId == 1)
    return CDebugInfo::m_EnvInfo.sOSVersionMayor >= 4;
  return CDebugInfo::m_EnvInfo.sPlatformId != 0;
}


// address=[0x1481080]
// Decompiled from bool CDebugInfo::IsWindowsNT40()
bool __cdecl CDebugInfo::IsWindowsNT40(void) {
  return CDebugInfo::m_EnvInfo.sVersion == 10;
}


// address=[0x14c2e70]
// Decompiled from char CDebugInfo::IsNetworkAvailable()
bool __cdecl CDebugInfo::IsNetworkAvailable(void) {
  return CDebugInfo::m_EnvInfo.bLoadedWSA;
}


// address=[0x147f840]
// Decompiled from int CDebugInfo::LogEnvironment()
void __cdecl CDebugInfo::LogEnvironment(void) {
  char *v0; // eax
  char *v1; // eax

  BBSupportTracePrintF(1, "=====================================================================");
  BBSupportTracePrintF(1, "SYSTEM INFORMATION");
  BBSupportTracePrintF(1, "---------------------------------------------------------------------");
  BBSupportTracePrintF(1, "CPU Vendor: %s", "sCPUVendor");
  BBSupportTracePrintF(1, "CPU Family: %d", 0);
  BBSupportTracePrintF(1, "CPU Model : %d", 0);
  BBSupportTracePrintF(1, "CPU Steppg: %d", 0);
  BBSupportTracePrintF(1, "# of CPUs : %d", CDebugInfo::m_EnvInfo.sProcessorCount);
  BBSupportTracePrintF(1, "CPU Speed : %d", CDebugInfo::m_EnvInfo.sProcessorSpeed);
  if(CDebugInfo::m_EnvInfo.bIsMMX)
    BBSupportTracePrintF(1, "MMX Ext.  : %s", "Yes");
  else
    BBSupportTracePrintF(1, "MMX Ext.  : %s", "No");
  BBSupportTracePrintF(1, "");
  BBSupportTracePrintF(1, "OPERATING SYSTEM INFORMATION");
  BBSupportTracePrintF(1, "---------------------------------------------------------------------");
  BBSupportTracePrintF(1, "Detected OS: %s", CDebugInfo::m_strOS[CDebugInfo::m_EnvInfo.sVersion].c_str());
  BBSupportTracePrintF(1, "VersionMajor: %d", CDebugInfo::m_EnvInfo.sOSVersionMayor);
  BBSupportTracePrintF(1, "VersionMinor: %d", CDebugInfo::m_EnvInfo.sOSVersionMinor);
  BBSupportTracePrintF(1, "Additional Info: %s", CDebugInfo::m_EnvInfo.sOSAdditionalInfo.c_str());
  BBSupportTracePrintF(1, "");
  BBSupportTracePrintF(1, "MEMORY INFORMATION");
  BBSupportTracePrintF(1, "---------------------------------------------------------------------");
  BBSupportTracePrintF(1, "Total Physical Memory: %d MBytes", (CDebugInfo::m_EnvInfo.uTotalPhyMemory >> 20) + 1);
  BBSupportTracePrintF(1, "Free  Physical Memory: %d MBytes", CDebugInfo::m_EnvInfo.uFreePhyMemory >> 20);
  BBSupportTracePrintF(1, "Total Virtual  Memory: %d MBytes", CDebugInfo::m_EnvInfo.uTotalVirtMemory >> 20);
  BBSupportTracePrintF(1, "Free  Virtual  Memory: %d MBytes", CDebugInfo::m_EnvInfo.uFreeVirtMemory >> 20);
  return BBSupportTracePrintF(1, "=====================================================================");
}


// address=[0x147fa70]
// Decompiled from char CDebugInfo::CheckOS()
bool __cdecl CDebugInfo::CheckOS(void) {
  _OSVERSIONINFOA VersionInformation; // [esp+8h] [ebp-98h] BYREF

  memset(&VersionInformation, 0, sizeof(VersionInformation));
  VersionInformation.dwOSVersionInfoSize = 148;
  if(!GetVersionExA(&VersionInformation)) {
    CDebugInfo::m_EnvInfo.sPlatformId = -1;
    CDebugInfo::m_EnvInfo.sOSVersionMayor = -1;
    CDebugInfo::m_EnvInfo.sOSVersionMinor = -1;
    return 0;
  }

  CDebugInfo::m_EnvInfo.sPlatformId = VersionInformation.dwPlatformId;
  CDebugInfo::m_EnvInfo.sOSVersionMayor = VersionInformation.dwMajorVersion;
  CDebugInfo::m_EnvInfo.sOSVersionMinor = VersionInformation.dwMinorVersion;

  CDebugInfo::m_EnvInfo.sOSAdditionalInfo = VersionInformation.szCSDVersion;
  if(CDebugInfo::m_EnvInfo.sPlatformId) {
    if(CDebugInfo::m_EnvInfo.sPlatformId == 1) {
      if(CDebugInfo::m_EnvInfo.sOSVersionMayor > 4
         || CDebugInfo::m_EnvInfo.sOSVersionMayor == 4 && CDebugInfo::m_EnvInfo.sOSVersionMinor > 0) {
        CDebugInfo::m_EnvInfo.sVersion = 4;
      } else {
        CDebugInfo::m_EnvInfo.sVersion = 3;
      }
    } else if(CDebugInfo::m_EnvInfo.sPlatformId == 2) {
      switch(CDebugInfo::m_EnvInfo.sOSVersionMayor) {
        case 3:
          CDebugInfo::m_EnvInfo.sVersion = 9;
          break;
        case 4:
          CDebugInfo::m_EnvInfo.sVersion = 10;
          break;
        case 5:
          CDebugInfo::m_EnvInfo.sVersion = 8;
          break;
        default:
          if(CDebugInfo::m_EnvInfo.sOSVersionMayor <= 5)
            CDebugInfo::m_EnvInfo.sVersion = 0;
          else
            CDebugInfo::m_EnvInfo.sVersion = 7;
          break;
      }
    } else {
      CDebugInfo::m_EnvInfo.sVersion = 0;
    }
  } else {
    CDebugInfo::m_EnvInfo.sVersion = 1;
  }
  return 1;
}


// address=[0x147fc10]
// Decompiled from char CDebugInfo::CheckCPU()
bool __cdecl CDebugInfo::CheckCPU(void) {
  _SYSTEM_INFO SystemInfo; // [esp+20h] [ebp-5Ch] BYREF
  DWORD        cbData; // [esp+44h] [ebp-38h] BYREF
  BYTE         Data[4]; // [esp+48h] [ebp-34h] BYREF
  HKEY         phkResult; // [esp+4Ch] [ebp-30h] BYREF
  LSTATUS      v6; // [esp+50h] [ebp-2Ch]
  // [esp+68h] [ebp-14h]

  if(!RegOpenKeyExA(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, 0x20019u, &phkResult)) {
    *(_DWORD *) Data = 0;
    cbData = 4;
    v6 = RegQueryValueExA(phkResult, "~MHz", 0, 0, Data, &cbData);
    if(v6)
      v6 = RegQueryValueExA(phkResult, "~Mhz", 0, 0, Data, &cbData);
    if(v6)
      v6 = RegQueryValueExA(phkResult, "~mhz", 0, 0, Data, &cbData);
    RegCloseKey(phkResult);
  }
  v6 = 1;
  SFreqInfo v7 = CDebugInfo::CPUSpeed(0);
  CDebugInfo::m_EnvInfo.sProcessorSpeed = v7.m_uSpeed3;
  memset(&SystemInfo, 0, sizeof(SystemInfo));
  GetSystemInfo(&SystemInfo);
  CDebugInfo::m_EnvInfo.sProcessorCount = SystemInfo.dwNumberOfProcessors;
  CDebugInfo::m_EnvInfo.bIsMMX = (CDebugInfo::wincpufeatures() & 0x800000) != 0;
  return 1;
}


// address=[0x147fd80]
// Decompiled from char CDebugInfo::CheckGraphicsAdapter()
bool __cdecl CDebugInfo::CheckGraphicsAdapter(void) {
  return 1;
}


// address=[0x147fd90]
// Decompiled from SFreqInfo *__cdecl CDebugInfo::CPUSpeed(SFreqInfo *__return_ptr retstr, _DWORD *a1, int a2)
struct SFreqInfo __cdecl CDebugInfo::CPUSpeed(int a1) {
  return SFreqInfo{}; // TODO: implement?
  /*
  SFreqInfo        v3; // [esp+0h] [ebp-84h] BYREF
  SFreqInfo        v4; // [esp+10h] [ebp-74h] BYREF
  SFreqInfo        v5; // [esp+20h] [ebp-64h] BYREF
  int              v6; // [esp+30h] [ebp-54h]
  unsigned int     v7; // [esp+34h] [ebp-50h]
  int              v8; // [esp+38h] [ebp-4Ch]
  unsigned __int16 v9; // [esp+3Ch] [ebp-48h]
  struct SFreqInfo v10; // [esp+40h] [ebp-44h] BYREF
  SFreqInfo        v11; // [esp+50h] [ebp-34h]
  SFreqInfo        v12; // [esp+60h] [ebp-24h]
  SFreqInfo        v13; // [esp+70h] [ebp-14h]

  v9 = CDebugInfo::wincpuid();
  v6 = CDebugInfo::wincpufeatures();
  v8 = 0;
  memset(&v10, 0, sizeof(v10));
  if(a1 > 0) {
    if(a1 <= 150) {
      v7 = 4000 * a1;
      v8 = 1;
    }
  } else {
    v7 = 4000000;
  }
  if((v6 & 0x10) == 0 || v8) {
    if(v9 < 3u) {
      return v10;
    } else {
      return CDebugInfo::GetBSFCpuSpeed(v7);
    }
    return retstr;
  } else {
    if(a1) {
      return CDebugInfo::GetCmosCpuSpeed();
    } else {
      return CDebugInfo::GetRDTSCCpuSpeed();
    }
    return retstr;
  }*/
}


// address=[0x147ff20]
// Decompiled from char CDebugInfo::CheckMemory()
bool __cdecl CDebugInfo::CheckMemory(void) {
  _MEMORYSTATUS Buffer; // [esp+0h] [ebp-24h] BYREF

  memset(&Buffer, 0, sizeof(Buffer));
  GlobalMemoryStatus(&Buffer);
  CDebugInfo::m_EnvInfo.uTotalPhyMemory = Buffer.dwTotalPhys;
  CDebugInfo::m_EnvInfo.uTotalVirtMemory = Buffer.dwTotalPageFile;
  CDebugInfo::m_EnvInfo.uFreePhyMemory = Buffer.dwAvailPhys;
  CDebugInfo::m_EnvInfo.uFreeVirtMemory = Buffer.dwAvailPageFile;
  return 1;
}


// address=[0x147ff80]
// Decompiled from SFreqInfo *__cdecl CDebugInfo::GetBSFCpuSpeed(SFreqInfo *__return_ptr retstr, _DWORD *a1, unsigned int a2)
struct SFreqInfo __cdecl CDebugInfo::GetBSFCpuSpeed(unsigned int retstr) {
  return SFreqInfo{}; // TODO: implement?
  /*
  __int16       v4; // bx
  LARGE_INTEGER PerformanceCount; // [esp+4h] [ebp-40h] BYREF
  LARGE_INTEGER v6; // [esp+Ch] [ebp-38h] BYREF
  LARGE_INTEGER Frequency; // [esp+14h] [ebp-30h] BYREF
  DWORD         v8; // [esp+1Ch] [ebp-28h]
  DWORD         v9; // [esp+20h] [ebp-24h]
  int           i; // [esp+24h] [ebp-20h]
  unsigned int  v11; // [esp+28h] [ebp-1Ch]
  DWORD         v12; // [esp+2Ch] [ebp-18h]
  SFreqInfo     v13; // [esp+30h] [ebp-14h] BYREF

  v11 = 0;
  v9 = 0;
  v8 = -1;
  memset(&v13, 0, sizeof(v13));
  if(QueryPerformanceFrequency(&Frequency)) {
    for(i = 0; i < 10; ++i) {
      QueryPerformanceCounter(&PerformanceCount);
      v4 = 4000;
      do
        --v4;
      while(v4);
      QueryPerformanceCounter(&v6);
      v9 = v6.LowPart - PerformanceCount.LowPart;
      if(v6.LowPart - PerformanceCount.LowPart < v8)
        v8 = v9;
    }
    v12 = 100000 * v8 / (Frequency.LowPart / 0xA);
    if(v12 % Frequency.LowPart > Frequency.LowPart >> 1)
      ++v12;
    v11 = (unsigned int) a1 / v12;
    v13.m_uSpeed2 = (unsigned int) a1 / v12;
    if((unsigned int) a1 % v12 > v12 >> 1)
      ++v11;
    v13.m_uSpeed1 = v12;
    v13.m_uSpeed3 = v11;
    retstr->m_uSpeed0 = (int) a1;
    retstr->m_uSpeed1 = v13.m_uSpeed1;
    retstr->m_uSpeed2 = v13.m_uSpeed2;
    retstr->m_uSpeed3 = v13.m_uSpeed3;
    return retstr;
  } else {
    *retstr = v13;
    return retstr;
  }*/
}


// address=[0x14800f0]
// Decompiled from SFreqInfo *__cdecl CDebugInfo::GetRDTSCCpuSpeed(SFreqInfo *__return_ptr retstr, _DWORD *a1)
struct SFreqInfo __cdecl CDebugInfo::GetRDTSCCpuSpeed(void) {
  return SFreqInfo{}; // TODO: implement?

  /*
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // rax
  LARGE_INTEGER    Frequency; // [esp+Ch] [ebp-60h] BYREF
  int              v6; // [esp+14h] [ebp-58h]
  int              v7; // [esp+18h] [ebp-54h]
  LARGE_INTEGER    PerformanceCount; // [esp+1Ch] [ebp-50h] BYREF
  unsigned int     v9; // [esp+24h] [ebp-48h]
  unsigned int     v10; // [esp+28h] [ebp-44h]
  HANDLE           hThread; // [esp+2Ch] [ebp-40h]
  int              nPriority; // [esp+30h] [ebp-3Ch]
  LARGE_INTEGER    v13; // [esp+34h] [ebp-38h] BYREF
  int              v14; // [esp+3Ch] [ebp-30h]
  unsigned int     v15; // [esp+40h] [ebp-2Ch]
  unsigned int     v16; // [esp+44h] [ebp-28h]
  unsigned int     v17; // [esp+48h] [ebp-24h]
  int              v18; // [esp+4Ch] [ebp-20h]
  unsigned int     v19; // [esp+50h] [ebp-1Ch]
  DWORD            v20; // [esp+54h] [ebp-18h]
  SFreqInfo        v21; // [esp+58h] [ebp-14h] BYREF

  v18 = 0;
  v17 = 0;
  v19 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  hThread = GetCurrentThread();
  memset(&v21, 0, sizeof(v21));
  if(QueryPerformanceFrequency(&Frequency)) {
    do {
      ++v14;
      v19 = v17;
      v17 = v18;
      QueryPerformanceCounter(&PerformanceCount);
      v13 = PerformanceCount;
      nPriority = GetThreadPriority(hThread);
      if(nPriority != 0x7FFFFFFF)
        SetThreadPriority(hThread, 15);
      while(v13.LowPart - PerformanceCount.LowPart < 0x32) {
        QueryPerformanceCounter(&v13);
        v3 = __rdtsc();
        v6 = v3;
      }
      PerformanceCount = v13;
      while(v13.LowPart - PerformanceCount.LowPart < 0x3E8) {
        QueryPerformanceCounter(&v13);
        v4 = __rdtsc();
        v7 = v4;
      }
      if(nPriority != 0x7FFFFFFF)
        SetThreadPriority(hThread, nPriority);
      v10 = v7 - v6;
      v20 = 100000 * (v13.LowPart - PerformanceCount.LowPart) / (Frequency.LowPart / 0xA);
      v16 += v20;
      v15 += v7 - v6;
      if(v20 % Frequency.LowPart > Frequency.LowPart >> 1)
        ++v20;
      v18 = v10 / v20;
      if(v10 % v20 > v20 >> 1)
        ++v18;
      v9 = v19 + v17 + v18;
    } while(v14 < 3 || v14 < 20 && (j__abs(3 * v18 - v9) > 3 || j__abs(3 * v17 - v9) > 3 || j__abs(3 * v19 - v9) > 3));
    v19 = 10 * v15 / v16;
    v17 = 100 * v15 / v16;
    if(v17 - 10 * v19 >= 6)
      ++v19;
    v21.m_uSpeed2 = v15 / v16;
    v21.m_uSpeed3 = v15 / v16;
    v18 = 10 * (v15 / v16);
    if(v19 - v18 >= 6)
      ++v21.m_uSpeed3;
    v21.m_uSpeed1 = v16;
    retstr->m_uSpeed0 = v15;
    retstr->m_uSpeed1 = v21.m_uSpeed1;
    retstr->m_uSpeed2 = v21.m_uSpeed2;
    retstr->m_uSpeed3 = v21.m_uSpeed3;
    return retstr;
  } else {
    *retstr = v21;
    return retstr;
  }*/
}


// address=[0x14803b0]
// Decompiled from __int16 __thiscall CDebugInfo::wincpuid(void *this)
unsigned short __cdecl CDebugInfo::wincpuid(void) {
  unsigned __int16 v3; // [esp+0h] [ebp-4h]

  if((unsigned __int16) CDebugInfo::wincpuidsupport()) {
    v3 = CDebugInfo::check_IDProc();
  } else {
    CDebugInfo::m_iClone = (unsigned __int16) CDebugInfo::check_clone();
    v3 = CDebugInfo::check_8086();
    if(v3) {
      v3 = CDebugInfo::check_80286();
      if(v3 != 2) {
        v3 = CDebugInfo::check_80386();
        if(v3 != 3)
          v3 = 4;
      }
    }
  }
  if(CDebugInfo::m_iClone)
    return v3 | 0x8000;
  return v3;
}


// address=[0x1480450]
// Decompiled from int CDebugInfo::wincpufeatures()
unsigned int __cdecl CDebugInfo::wincpufeatures(void) {
  CDebugInfo::m_iClone = 1;
  return 0;
  /*
  int v11; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v11 = 0;
  if(!(unsigned __int16) CDebugInfo::wincpuidsupport())
    return v11;
  _EAX = 0;
  __asm { cpuid }
  *(_DWORD *) asc_3D89A08 = _EBX;
  *(_DWORD *) &asc_3D89A08[4] = _EDX;
  *(_DWORD *) &asc_3D89A08[8] = _ECX;
  for(i = 0; i < 12; ++i) {
    if(asc_3D89A08[i] != byte_3D89A18[i])
      CDebugInfo::m_iClone = 1;
  }
  if(_EAX < 1)
    return v11;
  _EAX = 1;
  __asm { cpuid }
  return _EDX;
  */
}


// address=[0x14804f0]
// Decompiled from SFreqInfo *__cdecl CDebugInfo::GetCmosCpuSpeed(SFreqInfo *a1)
struct SFreqInfo __cdecl CDebugInfo::GetCmosCpuSpeed(void) {
  return SFreqInfo{}; // TODO: implement?
  /*
  unsigned int  v2[2]; // [esp+4h] [ebp-5Ch] BYREF
  unsigned long v3; // [esp+Ch] [ebp-54h] BYREF
  unsigned long v4; // [esp+10h] [ebp-50h] BYREF
  unsigned long v5; // [esp+14h] [ebp-4Ch] BYREF
  unsigned long v6; // [esp+18h] [ebp-48h] BYREF
  unsigned long v7; // [esp+1Ch] [ebp-44h] BYREF
  int           v8; // [esp+20h] [ebp-40h]
  int           v9; // [esp+24h] [ebp-3Ch]
  BOOL          v10; // [esp+28h] [ebp-38h]
  int           v11; // [esp+2Ch] [ebp-34h]
  BOOL          v12; // [esp+30h] [ebp-30h]
  unsigned int  v13; // [esp+34h] [ebp-2Ch]
  HANDLE        hThread; // [esp+38h] [ebp-28h]
  int           nPriority; // [esp+3Ch] [ebp-24h]
  unsigned int  v16; // [esp+40h] [ebp-20h]
  int           CmosTick; // [esp+44h] [ebp-1Ch]
  int           v18; // [esp+48h] [ebp-18h]
  SFreqInfo     v19; // [esp+4Ch] [ebp-14h] BYREF

  v16 = 0;
  hThread = GetCurrentThread();
  memset(&v19, 0, sizeof(v19));
  nPriority = GetThreadPriority(hThread);
  if(nPriority != 0x7FFFFFFF)
    SetThreadPriority(hThread, nPriority + 1);
  CmosTick = CDebugInfo::GetCmosTick();
  do {
    v18 = CDebugInfo::GetCmosTick();
    if(v18 >= CmosTick) {
      v12 = v18 - CmosTick > 0;
      v11 = v12;
    } else {
      v11 = v18 + 10 - CmosTick;
    }
  } while(!v11);
  CDebugInfo::cpuTimeStamp(&v3, &v4);
  CmosTick = v18;
  do {
    v18 = CDebugInfo::GetCmosTick();
    if(v18 >= CmosTick) {
      v10 = v18 - CmosTick > 0;
      v9 = v10;
    } else {
      v9 = v18 + 10 - CmosTick;
    }
  } while(!v9);
  CDebugInfo::cpuTimeStamp(&v5, &v6);
  if(nPriority != 0x7FFFFFFF)
    SetThreadPriority(hThread, nPriority);
  CDebugInfo::diffTime64(v3, v4, v5, v6, v2, &v7);
  if(v18 >= CmosTick)
    v8 = v18 - CmosTick;
  else
    v8 = v18 + 10 - CmosTick;
  v19.m_uSpeed0 = v7;
  v2[1] = v7 / 0x186A0;
  v13 = 10 * (v7 / 0xF4240);
  v16 = v7 / 0xF4240;
  v19.m_uSpeed2 = v7 / 0xF4240;
  if(v7 / 0x186A0 - v13 >= 6)
    ++v16;
  v19.m_uSpeed3 = v16;
  v19.m_uSpeed1 = 1000000 * (v18 - CmosTick);
  return v19;*/
}


// address=[0x1480700]
// Decompiled from _BOOL2 CDebugInfo::wincpuidsupport()
unsigned short __cdecl CDebugInfo::wincpuidsupport(void) {
  unsigned int v0 = __readeflags();
  __writeeflags(v0 ^ 0x200000);
  unsigned int v1 = __readeflags();

  BB_ASSERT(v0 != v1)
  return v0 != v1;
}


// address=[0x1480730]
// Decompiled from __int16 CDebugInfo::check_8086()
unsigned short __cdecl CDebugInfo::check_8086(void) {
  return -1;
}


// address=[0x1480780]
// Decompiled from __int16 CDebugInfo::check_80286()
unsigned short __cdecl CDebugInfo::check_80286(void) {
  return -1;
}


// address=[0x14807d0]
// Decompiled from int CDebugInfo::check_80386()
unsigned short __cdecl CDebugInfo::check_80386(void) {
  // kr00_4
  // kr04_4
  // [esp+4h] [ebp-4h]

  unsigned int v0 = __readeflags();
  __writeeflags(v0 ^ 0x40000);
  unsigned int     v1 = __readeflags();
  unsigned __int16 v3 = 3;
  if(v0 != v1)
    v3 = -1;
  __writeeflags(v0);
  return v3;
}


// address=[0x1480820]
// Decompiled from __int16 CDebugInfo::check_IDProc()
unsigned short __cdecl CDebugInfo::check_IDProc(void) {
  return 0;
  // int    i; // [esp+10h] [ebp-28h]
  // char   v12[16]; // [esp+14h] [ebp-24h] BYREF
  // _DWORD v13[3]; // [esp+24h] [ebp-14h]
  // char   v14; // [esp+30h] [ebp-8h]
  //
  // v14 = 0;
  // strcpy(v12, "GenuineIntel");
  // _EAX = 0;
  // __asm { cpuid }
  // v13[0] = _EBX;
  // v13[1] = _EDX;
  // v13[2] = _ECX;
  // for(i = 0; i < 12; ++i) {
  //   if(*((unsigned __int8 *) v13 + i) != (unsigned __int8) v12[i])
  //     CDebugInfo::m_iClone = 1;
  // }
  // if(_EAX < 1)
  //   return word_3D89A28;
  // _EAX = 1;
  // __asm { cpuid }
  // byte_3F44E8C = _EAX & 0xF;
  // LOBYTE(_EAX) = (unsigned __int8) (_EAX & 0xF0) >> 4;
  // byte_3F44E8D = _EAX;
  // word_3D89A28 = ((unsigned __int16) (_EAX & 0xF00) >> 8) & 0xF;
  // return word_3D89A28;
}


// address=[0x1480920]
// Decompiled from _BOOL2 CDebugInfo::check_clone()
unsigned short __cdecl CDebugInfo::check_clone(void) {
  return 1;
  // char v5; // [esp-2h] [ebp-6h]
  //
  // _CF = !_ZF;
  // __asm { pushfw }
  // return !(v5 & 1);
}


// address=[0x1480960]
// Decompiled from int CDebugInfo::GetCmosTick()
int __cdecl CDebugInfo::GetCmosTick(void) {
  return 0;
  // int result; // eax
  //
  // __outbyte(0x70u, 0);
  // LOBYTE(result) = __inbyte(0x71u);
  // return (unsigned __int8) result;
}


// address=[0x1480980]
// Decompiled from int __cdecl CDebugInfo::cpuTimeStamp(unsigned int *a1, unsigned int *a2)
unsigned int __cdecl CDebugInfo::cpuTimeStamp(unsigned long *a1, unsigned long *a2) {
  return 0;
  // // kr00_8
  //
  // unsigned __int64 v2 = __rdtsc();
  // *a1 = HIDWORD(v2);
  // *a2 = v2;
  // return v2;
}


// address=[0x14809c0]
// Decompiled from int __cdecl CDebugInfo::diffTime64(  unsigned int a1,  unsigned int a2,  unsigned int a3,  unsigned int a4,  unsigned int *a5,  unsigned int *a6)
unsigned int __cdecl CDebugInfo::diffTime64(unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long *a5, unsigned long *a6) {
  return 0;
  // *a6 = a4 - a2;
  // *a5 = (__PAIR64__(a3, a4) - __PAIR64__(a1, a2)) >> 32;
  // return *a6;
}


// address=[0x3d899d8]
// [Decompilation failed for static unsigned int * CDebugInfo::processor_cycles]

// address=[0x3f44e88]
// [Decompilation failed for static unsigned int CDebugInfo::m_iClone]

// address=[0x3f44e90]
// [Decompilation failed for static struct SEnvironmentInfo CDebugInfo::m_EnvInfo]

// address=[0x3f44f08]
// [Decompilation failed for static std::string * CDebugInfo::m_strOS]

