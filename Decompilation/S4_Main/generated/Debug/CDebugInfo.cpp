#include "CDebugInfo.h"

// Definitions for class CDebugInfo

// address=[0x135e070]
// Decompiled from bool CDebugInfo::IsMMX()
bool __cdecl CDebugInfo::IsMMX(void) {
  
  return bIsMMX == 1;
}


// address=[0x1480a00]
// Decompiled from bool __cdecl CDebugInfo::CheckEnvironment(bool _bLogEnv)
bool __cdecl CDebugInfo::CheckEnvironment(bool _bLogEnv) {
  
  DWORD LastError; // eax MAPDST

  memset(&CDebugInfo::m_EnvInfo, 0, 0x74u);
  if ( !CDebugInfo::CheckOS() )
  {
    LastError = GetLastError();
    CTrace::Print("DebugInfo.cpp: Error calling CheckOS(); LastError: %d", LastError);
  }
  if ( !CDebugInfo::CheckCPU() )
  {
    LastError = GetLastError();
    CTrace::Print("DebugInfo.cpp: Error calling CheckCPU(); LastError: %d", LastError);
  }
  if ( !CDebugInfo::CheckMemory() )
  {
    LastError = GetLastError();
    CTrace::Print("DebugInfo.cpp: Error calling CheckMemory(); LastError: %d", LastError);
  }
  if ( _bLogEnv )
    CDebugInfo::LogEnvironment();
  if ( !CDebugInfo::IsWindowsNT40() || CDebugInfo::IsMMX() )
  {
    if ( CDebugInfo::IsTargetPlatform() )
    {
      g_bLoadedWSA = ImportWSAFunctions();
      if ( !g_bLoadedWSA )
        CTrace::Print("DebugInfo.cpp: Winsock2 not found !!!!");
      CDebugInfo::CheckGraphicsAdapter();
      return 1;
    }
    else
    {
      MessageBoxA(g_hWnd, aSettlersIvNeed, "S4", 0x30u);
      return 0;
    }
  }
  else
  {
    MessageBoxA(g_hWnd, aSettlersIvRunn, "S4", 0x30u);
    return 0;
  }
}


// address=[0x1480b10]
// Decompiled from bool CDebugInfo::IsTargetPlatform()
bool __cdecl CDebugInfo::IsTargetPlatform(void) {
  
  if ( sPlatformId == 2 )
    return sOSVersionMajor >= 4;
  if ( sPlatformId == 1 )
    return sOSVersionMajor >= 4;
  return sPlatformId != 0;
}


// address=[0x1481080]
// Decompiled from bool CDebugInfo::IsWindowsNT40()
bool __cdecl CDebugInfo::IsWindowsNT40(void) {
  
  return CDebugInfo::m_EnvInfo == 10;
}


// address=[0x14c2e70]
// Decompiled from char CDebugInfo::IsNetworkAvailable()
bool __cdecl CDebugInfo::IsNetworkAvailable(void) {
  
  return g_bLoadedWSA;
}


// address=[0x147f840]
// Decompiled from int CDebugInfo::LogEnvironment()
void __cdecl CDebugInfo::LogEnvironment(void) {
  
  char *v0; // eax
  char *v1; // eax

  BBSupportTracePrintF(1, "=====================================================================");
  BBSupportTracePrintF(1, "SYSTEM INFORMATION");
  BBSupportTracePrintF(1, "---------------------------------------------------------------------");
  BBSupportTracePrintF(1, "CPU Vendor: %s", asc_3D89A08);
  BBSupportTracePrintF(1, "CPU Family: %d", (unsigned __int16)word_3D89A28);
  BBSupportTracePrintF(1, "CPU Model : %d", (unsigned __int8)byte_3F44E8D);
  BBSupportTracePrintF(1, "CPU Steppg: %d", (unsigned __int8)byte_3F44E8C);
  BBSupportTracePrintF(1, "# of CPUs : %d", sProcessorCount);
  BBSupportTracePrintF(1, "CPU Speed : %d", sProcessorSpeed);
  if ( bIsMMX )
    BBSupportTracePrintF(1, "MMX Ext.  : %s", "Yes");
  else
    BBSupportTracePrintF(1, "MMX Ext.  : %s", "No");
  BBSupportTracePrintF(1, (char *)&sEmpty4);
  BBSupportTracePrintF(1, "OPERATING SYSTEM INFORMATION");
  BBSupportTracePrintF(1, "---------------------------------------------------------------------");
  v0 = std::string::c_str((std::string *)&CDebugInfo::m_strOS + CDebugInfo::m_EnvInfo);
  BBSupportTracePrintF(1, "Detected OS: %s", v0);
  BBSupportTracePrintF(1, "VersionMajor: %d", sOSVersionMajor);
  BBSupportTracePrintF(1, "VersionMinor: %d", sOSVersionMinor);
  v1 = std::string::c_str(&sOSAdditionalInfo);
  BBSupportTracePrintF(1, "Additional Info: %s", v1);
  BBSupportTracePrintF(1, (char *)&sEmpty5);
  BBSupportTracePrintF(1, "MEMORY INFORMATION");
  BBSupportTracePrintF(1, "---------------------------------------------------------------------");
  BBSupportTracePrintF(1, "Total Physical Memory: %d MBytes", ((unsigned int)uTotalPhyMemory >> 20) + 1);
  BBSupportTracePrintF(1, "Free  Physical Memory: %d MBytes", (unsigned int)uFreePhyMemory >> 20);
  BBSupportTracePrintF(1, "Total Virtual  Memory: %d MBytes", (unsigned int)uTotalVirMemory >> 20);
  BBSupportTracePrintF(1, "Free  Virtual  Memory: %d MBytes", (unsigned int)uFreeVirMemory >> 20);
  return BBSupportTracePrintF(1, "=====================================================================");
}


// address=[0x147fa70]
// Decompiled from char CDebugInfo::CheckOS()
bool __cdecl CDebugInfo::CheckOS(void) {
  
  _OSVERSIONINFOA VersionInformation; // [esp+8h] [ebp-98h] BYREF

  memset(&VersionInformation, 0, sizeof(VersionInformation));
  VersionInformation.dwOSVersionInfoSize = 148;
  if ( GetVersionExA(&VersionInformation) )
  {
    sPlatformId = VersionInformation.dwPlatformId;
    sOSVersionMajor = VersionInformation.dwMajorVersion;
    sOSVersionMinor = VersionInformation.dwMinorVersion;
    std::string::operator=(&sOSAdditionalInfo, VersionInformation.szCSDVersion);
    if ( sPlatformId )
    {
      if ( sPlatformId == 1 )
      {
        if ( sOSVersionMajor > 4 || sOSVersionMajor == 4 && sOSVersionMinor > 0 )
          CDebugInfo::m_EnvInfo = 4;
        else
          CDebugInfo::m_EnvInfo = 3;
      }
      else if ( sPlatformId == 2 )
      {
        switch ( sOSVersionMajor )
        {
          case 3:
            CDebugInfo::m_EnvInfo = 9;
            break;
          case 4:
            CDebugInfo::m_EnvInfo = 10;
            break;
          case 5:
            CDebugInfo::m_EnvInfo = 8;
            break;
          default:
            if ( sOSVersionMajor <= 5 )
              CDebugInfo::m_EnvInfo = 0;
            else
              CDebugInfo::m_EnvInfo = 7;
            break;
        }
      }
      else
      {
        CDebugInfo::m_EnvInfo = 0;
      }
    }
    else
    {
      CDebugInfo::m_EnvInfo = 1;
    }
    return 1;
  }
  else
  {
    sPlatformId = -1;
    sOSVersionMajor = -1;
    sOSVersionMinor = -1;
    return 0;
  }
}


// address=[0x147fc10]
// Decompiled from char CDebugInfo::CheckCPU()
bool __cdecl CDebugInfo::CheckCPU(void) {
  
  int *v0; // eax
  _BYTE v2[16]; // [esp+0h] [ebp-7Ch] BYREF
  _SYSTEM_INFO SystemInfo; // [esp+20h] [ebp-5Ch] BYREF
  DWORD cbData; // [esp+44h] [ebp-38h] BYREF
  BYTE Data[4]; // [esp+48h] [ebp-34h] BYREF
  HKEY phkResult; // [esp+4Ch] [ebp-30h] BYREF
  LSTATUS v7; // [esp+50h] [ebp-2Ch]
  int v8; // [esp+68h] [ebp-14h]
  int v9; // [esp+6Ch] [ebp-10h]
  int v10; // [esp+70h] [ebp-Ch]
  int v11; // [esp+74h] [ebp-8h]

  if ( !RegOpenKeyExA(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, 0x20019u, &phkResult) )
  {
    *(_DWORD *)Data = 0;
    cbData = 4;
    v7 = RegQueryValueExA(phkResult, "~MHz", 0, 0, Data, &cbData);
    if ( v7 )
      v7 = RegQueryValueExA(phkResult, "~Mhz", 0, 0, Data, &cbData);
    if ( v7 )
      v7 = RegQueryValueExA(phkResult, "~mhz", 0, 0, Data, &cbData);
    RegCloseKey(phkResult);
  }
  v7 = 1;
  v0 = (int *)CDebugInfo::CPUSpeed(v2, 0);
  v8 = *v0;
  v9 = v0[1];
  v10 = v0[2];
  v11 = v0[3];
  sProcessorSpeed = v11;
  memset(&SystemInfo, 0, sizeof(SystemInfo));
  GetSystemInfo(&SystemInfo);
  sProcessorCount = SystemInfo.dwNumberOfProcessors;
  bIsMMX = (CDebugInfo::wincpufeatures() & 0x800000) != 0;
  return 1;
}


// address=[0x147fd80]
// Decompiled from char CDebugInfo::CheckGraphicsAdapter()
bool __cdecl CDebugInfo::CheckGraphicsAdapter(void) {
  
  return 1;
}


// address=[0x147fd90]
// Decompiled from SFreqInfo *__cdecl CDebugInfo::CPUSpeed(SFreqInfo *__return_ptr retstr, _DWORD *a1, int a2)
struct SFreqInfo __cdecl CDebugInfo::CPUSpeed(int retstr) {
  
  _BYTE v4[16]; // [esp+0h] [ebp-84h] BYREF
  _BYTE v5[16]; // [esp+10h] [ebp-74h] BYREF
  _BYTE v6[16]; // [esp+20h] [ebp-64h] BYREF
  int v7; // [esp+30h] [ebp-54h]
  int v8; // [esp+34h] [ebp-50h]
  int v9; // [esp+38h] [ebp-4Ch]
  unsigned __int16 v10; // [esp+3Ch] [ebp-48h]
  SFreqInfo v11; // [esp+40h] [ebp-44h] BYREF
  SFreqInfo v12; // [esp+50h] [ebp-34h]
  SFreqInfo v13; // [esp+60h] [ebp-24h]
  SFreqInfo v14; // [esp+70h] [ebp-14h]

  v10 = CDebugInfo::wincpuid();
  v7 = CDebugInfo::wincpufeatures();
  v9 = 0;
  memset(&v11, 0, sizeof(v11));
  if ( (int)a1 > 0 )
  {
    if ( (int)a1 <= 150 )
    {
      v8 = 4000 * (_DWORD)a1;
      v9 = 1;
    }
  }
  else
  {
    v8 = 4000000;
  }
  if ( (v7 & 0x10) == 0 || v9 )
  {
    if ( v10 < 3u )
    {
      *retstr = v11;
    }
    else
    {
      v12 = *(SFreqInfo *)CDebugInfo::GetBSFCpuSpeed(v4, v8);
      *retstr = v12;
    }
    return retstr;
  }
  else
  {
    if ( a1 )
    {
      v13 = *(SFreqInfo *)CDebugInfo::GetCmosCpuSpeed(v5);
      *retstr = v13;
    }
    else
    {
      v14 = *(SFreqInfo *)CDebugInfo::GetRDTSCCpuSpeed(v6);
      *retstr = v14;
    }
    return retstr;
  }
}


// address=[0x147ff20]
// Decompiled from char CDebugInfo::CheckMemory()
bool __cdecl CDebugInfo::CheckMemory(void) {
  
  _MEMORYSTATUS Buffer; // [esp+0h] [ebp-24h] BYREF

  memset(&Buffer, 0, sizeof(Buffer));
  GlobalMemoryStatus(&Buffer);
  uTotalPhyMemory = Buffer.dwTotalPhys;
  uTotalVirMemory = Buffer.dwTotalPageFile;
  uFreePhyMemory = Buffer.dwAvailPhys;
  uFreeVirMemory = Buffer.dwAvailPageFile;
  return 1;
}


// address=[0x147ff80]
// Decompiled from SFreqInfo *__cdecl CDebugInfo::GetBSFCpuSpeed(SFreqInfo *__return_ptr retstr, _DWORD *a1, unsigned int a2)
struct SFreqInfo __cdecl CDebugInfo::GetBSFCpuSpeed(unsigned int retstr) {
  
  __int16 v4; // bx
  LARGE_INTEGER PerformanceCount; // [esp+4h] [ebp-40h] BYREF
  LARGE_INTEGER v6; // [esp+Ch] [ebp-38h] BYREF
  LARGE_INTEGER Frequency; // [esp+14h] [ebp-30h] BYREF
  DWORD v8; // [esp+1Ch] [ebp-28h]
  DWORD v9; // [esp+20h] [ebp-24h]
  int i; // [esp+24h] [ebp-20h]
  unsigned int v11; // [esp+28h] [ebp-1Ch]
  DWORD v12; // [esp+2Ch] [ebp-18h]
  SFreqInfo v13; // [esp+30h] [ebp-14h] BYREF

  v11 = 0;
  v9 = 0;
  v8 = -1;
  memset(&v13, 0, sizeof(v13));
  if ( QueryPerformanceFrequency(&Frequency) )
  {
    for ( i = 0; i < 10; ++i )
    {
      QueryPerformanceCounter(&PerformanceCount);
      v4 = 4000;
      do
        --v4;
      while ( v4 );
      QueryPerformanceCounter(&v6);
      v9 = v6.LowPart - PerformanceCount.LowPart;
      if ( v6.LowPart - PerformanceCount.LowPart < v8 )
        v8 = v9;
    }
    v12 = 100000 * v8 / (Frequency.LowPart / 0xA);
    if ( v12 % Frequency.LowPart > Frequency.LowPart >> 1 )
      ++v12;
    v11 = (unsigned int)a1 / v12;
    v13.m_uSpeed2 = (unsigned int)a1 / v12;
    if ( (unsigned int)a1 % v12 > v12 >> 1 )
      ++v11;
    v13.m_uSpeed1 = v12;
    v13.m_uSpeed3 = v11;
    retstr->m_uSpeed0 = (int)a1;
    retstr->m_uSpeed1 = v13.m_uSpeed1;
    retstr->m_uSpeed2 = v13.m_uSpeed2;
    retstr->m_uSpeed3 = v13.m_uSpeed3;
    return retstr;
  }
  else
  {
    *retstr = v13;
    return retstr;
  }
}


// address=[0x14800f0]
// Decompiled from SFreqInfo *__cdecl CDebugInfo::GetRDTSCCpuSpeed(SFreqInfo *__return_ptr retstr, _DWORD *a1)
struct SFreqInfo __cdecl CDebugInfo::GetRDTSCCpuSpeed(void retstr) {
  
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // rax
  LARGE_INTEGER Frequency; // [esp+Ch] [ebp-60h] BYREF
  int v6; // [esp+14h] [ebp-58h]
  int v7; // [esp+18h] [ebp-54h]
  LARGE_INTEGER PerformanceCount; // [esp+1Ch] [ebp-50h] BYREF
  unsigned int v9; // [esp+24h] [ebp-48h]
  unsigned int v10; // [esp+28h] [ebp-44h]
  HANDLE hThread; // [esp+2Ch] [ebp-40h]
  int nPriority; // [esp+30h] [ebp-3Ch]
  LARGE_INTEGER v13; // [esp+34h] [ebp-38h] BYREF
  int v14; // [esp+3Ch] [ebp-30h]
  unsigned int v15; // [esp+40h] [ebp-2Ch]
  unsigned int v16; // [esp+44h] [ebp-28h]
  unsigned int v17; // [esp+48h] [ebp-24h]
  int v18; // [esp+4Ch] [ebp-20h]
  unsigned int v19; // [esp+50h] [ebp-1Ch]
  DWORD v20; // [esp+54h] [ebp-18h]
  SFreqInfo v21; // [esp+58h] [ebp-14h] BYREF

  v18 = 0;
  v17 = 0;
  v19 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  hThread = GetCurrentThread();
  memset(&v21, 0, sizeof(v21));
  if ( QueryPerformanceFrequency(&Frequency) )
  {
    do
    {
      ++v14;
      v19 = v17;
      v17 = v18;
      QueryPerformanceCounter(&PerformanceCount);
      v13 = PerformanceCount;
      nPriority = GetThreadPriority(hThread);
      if ( nPriority != 0x7FFFFFFF )
        SetThreadPriority(hThread, 15);
      while ( v13.LowPart - PerformanceCount.LowPart < 0x32 )
      {
        QueryPerformanceCounter(&v13);
        v3 = __rdtsc();
        v6 = v3;
      }
      PerformanceCount = v13;
      while ( v13.LowPart - PerformanceCount.LowPart < 0x3E8 )
      {
        QueryPerformanceCounter(&v13);
        v4 = __rdtsc();
        v7 = v4;
      }
      if ( nPriority != 0x7FFFFFFF )
        SetThreadPriority(hThread, nPriority);
      v10 = v7 - v6;
      v20 = 100000 * (v13.LowPart - PerformanceCount.LowPart) / (Frequency.LowPart / 0xA);
      v16 += v20;
      v15 += v7 - v6;
      if ( v20 % Frequency.LowPart > Frequency.LowPart >> 1 )
        ++v20;
      v18 = v10 / v20;
      if ( v10 % v20 > v20 >> 1 )
        ++v18;
      v9 = v19 + v17 + v18;
    }
    while ( v14 < 3 || v14 < 20 && (j__abs(3 * v18 - v9) > 3 || j__abs(3 * v17 - v9) > 3 || j__abs(3 * v19 - v9) > 3) );
    v19 = 10 * v15 / v16;
    v17 = 100 * v15 / v16;
    if ( v17 - 10 * v19 >= 6 )
      ++v19;
    v21.m_uSpeed2 = v15 / v16;
    v21.m_uSpeed3 = v15 / v16;
    v18 = 10 * (v15 / v16);
    if ( v19 - v18 >= 6 )
      ++v21.m_uSpeed3;
    v21.m_uSpeed1 = v16;
    retstr->m_uSpeed0 = v15;
    retstr->m_uSpeed1 = v21.m_uSpeed1;
    retstr->m_uSpeed2 = v21.m_uSpeed2;
    retstr->m_uSpeed3 = v21.m_uSpeed3;
    return retstr;
  }
  else
  {
    *retstr = v21;
    return retstr;
  }
}


// address=[0x14803b0]
// Decompiled from __int16 __thiscall CDebugInfo::wincpuid(void *this)
unsigned short __cdecl CDebugInfo::wincpuid(void) {
  
  __int16 v3; // [esp+0h] [ebp-4h]

  if ( (unsigned __int16)CDebugInfo::wincpuidsupport() )
  {
    v3 = CDebugInfo::check_IDProc(this);
  }
  else
  {
    CDebugInfo::m_iClone = (unsigned __int16)CDebugInfo::check_clone(this);
    v3 = CDebugInfo::check_8086();
    if ( v3 )
    {
      v3 = CDebugInfo::check_80286();
      if ( v3 != 2 )
      {
        v3 = CDebugInfo::check_80386();
        if ( v3 != 3 )
          v3 = 4;
      }
    }
  }
  if ( CDebugInfo::m_iClone )
    return v3 | 0x8000;
  return v3;
}


// address=[0x1480450]
// Decompiled from int CDebugInfo::wincpufeatures()
unsigned int __cdecl CDebugInfo::wincpufeatures(void) {
  
  int v11; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v11 = 0;
  if ( !(unsigned __int16)CDebugInfo::wincpuidsupport() )
    return v11;
  _EAX = 0;
  __asm { cpuid }
  *(_DWORD *)asc_3D89A08 = _EBX;
  *(_DWORD *)&asc_3D89A08[4] = _EDX;
  *(_DWORD *)&asc_3D89A08[8] = _ECX;
  for ( i = 0; i < 12; ++i )
  {
    if ( asc_3D89A08[i] != byte_3D89A18[i] )
      CDebugInfo::m_iClone = 1;
  }
  if ( _EAX < 1 )
    return v11;
  _EAX = 1;
  __asm { cpuid }
  return _EDX;
}


// address=[0x14804f0]
// Decompiled from SFreqInfo *__cdecl CDebugInfo::GetCmosCpuSpeed(SFreqInfo *a1)
struct SFreqInfo __cdecl CDebugInfo::GetCmosCpuSpeed(void a1) {
  
  unsigned int v2[2]; // [esp+4h] [ebp-5Ch] BYREF
  unsigned int v3; // [esp+Ch] [ebp-54h] BYREF
  unsigned int v4; // [esp+10h] [ebp-50h] BYREF
  unsigned int v5; // [esp+14h] [ebp-4Ch] BYREF
  unsigned int v6; // [esp+18h] [ebp-48h] BYREF
  unsigned int v7; // [esp+1Ch] [ebp-44h] BYREF
  int v8; // [esp+20h] [ebp-40h]
  int v9; // [esp+24h] [ebp-3Ch]
  BOOL v10; // [esp+28h] [ebp-38h]
  int v11; // [esp+2Ch] [ebp-34h]
  BOOL v12; // [esp+30h] [ebp-30h]
  unsigned int v13; // [esp+34h] [ebp-2Ch]
  HANDLE hThread; // [esp+38h] [ebp-28h]
  int nPriority; // [esp+3Ch] [ebp-24h]
  unsigned int v16; // [esp+40h] [ebp-20h]
  int CmosTick; // [esp+44h] [ebp-1Ch]
  int v18; // [esp+48h] [ebp-18h]
  SFreqInfo v19; // [esp+4Ch] [ebp-14h] BYREF

  v16 = 0;
  hThread = GetCurrentThread();
  memset(&v19, 0, sizeof(v19));
  nPriority = GetThreadPriority(hThread);
  if ( nPriority != 0x7FFFFFFF )
    SetThreadPriority(hThread, nPriority + 1);
  CmosTick = CDebugInfo::GetCmosTick();
  do
  {
    v18 = CDebugInfo::GetCmosTick();
    if ( v18 >= CmosTick )
    {
      v12 = v18 - CmosTick > 0;
      v11 = v12;
    }
    else
    {
      v11 = v18 + 10 - CmosTick;
    }
  }
  while ( !v11 );
  CDebugInfo::cpuTimeStamp(&v3, &v4);
  CmosTick = v18;
  do
  {
    v18 = CDebugInfo::GetCmosTick();
    if ( v18 >= CmosTick )
    {
      v10 = v18 - CmosTick > 0;
      v9 = v10;
    }
    else
    {
      v9 = v18 + 10 - CmosTick;
    }
  }
  while ( !v9 );
  CDebugInfo::cpuTimeStamp(&v5, &v6);
  if ( nPriority != 0x7FFFFFFF )
    SetThreadPriority(hThread, nPriority);
  CDebugInfo::diffTime64(v3, v4, v5, v6, v2, &v7);
  if ( v18 >= CmosTick )
    v8 = v18 - CmosTick;
  else
    v8 = v18 + 10 - CmosTick;
  v19.m_uSpeed0 = v7;
  v2[1] = v7 / 0x186A0;
  v13 = 10 * (v7 / 0xF4240);
  v16 = v7 / 0xF4240;
  v19.m_uSpeed2 = v7 / 0xF4240;
  if ( v7 / 0x186A0 - v13 >= 6 )
    ++v16;
  v19.m_uSpeed3 = v16;
  v19.m_uSpeed1 = 1000000 * (v18 - CmosTick);
  *a1 = v19;
  return a1;
}


// address=[0x1480700]
// Decompiled from _BOOL2 CDebugInfo::wincpuidsupport()
unsigned short __cdecl CDebugInfo::wincpuidsupport(void) {
  
  unsigned int v0; // kr00_4
  unsigned int v1; // kr04_4

  v0 = __readeflags();
  __writeeflags(v0 ^ 0x200000);
  v1 = __readeflags();
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
  
  unsigned int v0; // kr00_4
  unsigned int v1; // kr04_4
  unsigned __int16 v3; // [esp+4h] [ebp-4h]

  v0 = __readeflags();
  __writeeflags(v0 ^ 0x40000);
  v1 = __readeflags();
  v3 = 3;
  if ( v0 != v1 )
    v3 = -1;
  __writeeflags(v0);
  return v3;
}


// address=[0x1480820]
// Decompiled from __int16 CDebugInfo::check_IDProc()
unsigned short __cdecl CDebugInfo::check_IDProc(void) {
  
  int i; // [esp+10h] [ebp-28h]
  char v12[16]; // [esp+14h] [ebp-24h] BYREF
  _DWORD v13[3]; // [esp+24h] [ebp-14h]
  char v14; // [esp+30h] [ebp-8h]

  v14 = 0;
  strcpy(v12, "GenuineIntel");
  _EAX = 0;
  __asm { cpuid }
  v13[0] = _EBX;
  v13[1] = _EDX;
  v13[2] = _ECX;
  for ( i = 0; i < 12; ++i )
  {
    if ( *((unsigned __int8 *)v13 + i) != (unsigned __int8)v12[i] )
      CDebugInfo::m_iClone = 1;
  }
  if ( _EAX < 1 )
    return word_3D89A28;
  _EAX = 1;
  __asm { cpuid }
  byte_3F44E8C = _EAX & 0xF;
  LOBYTE(_EAX) = (unsigned __int8)(_EAX & 0xF0) >> 4;
  byte_3F44E8D = _EAX;
  word_3D89A28 = ((unsigned __int16)(_EAX & 0xF00) >> 8) & 0xF;
  return word_3D89A28;
}


// address=[0x1480920]
// Decompiled from _BOOL2 CDebugInfo::check_clone()
unsigned short __cdecl CDebugInfo::check_clone(void) {
  
  char v5; // [esp-2h] [ebp-6h]

  _CF = !_ZF;
  __asm { pushfw }
  return !(v5 & 1);
}


// address=[0x1480960]
// Decompiled from int CDebugInfo::GetCmosTick()
int __cdecl CDebugInfo::GetCmosTick(void) {
  
  int result; // eax

  __outbyte(0x70u, 0);
  LOBYTE(result) = __inbyte(0x71u);
  return (unsigned __int8)result;
}


// address=[0x1480980]
// Decompiled from int __cdecl CDebugInfo::cpuTimeStamp(unsigned int *a1, unsigned int *a2)
unsigned int __cdecl CDebugInfo::cpuTimeStamp(unsigned long * a1, unsigned long * a2) {
  
  unsigned __int64 v2; // kr00_8

  v2 = __rdtsc();
  *a1 = HIDWORD(v2);
  *a2 = v2;
  return v2;
}


// address=[0x14809c0]
// Decompiled from int __cdecl CDebugInfo::diffTime64(  unsigned int a1,  unsigned int a2,  unsigned int a3,  unsigned int a4,  unsigned int *a5,  unsigned int *a6)
unsigned int __cdecl CDebugInfo::diffTime64(unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long * a5, unsigned long * a6) {
  
  *a6 = a4 - a2;
  *a5 = (__PAIR64__(a3, a4) - __PAIR64__(a1, a2)) >> 32;
  return *a6;
}


// address=[0x3d899d8]
// [Decompilation failed for static unsigned int * CDebugInfo::processor_cycles]

// address=[0x3f44e88]
// [Decompilation failed for static unsigned int CDebugInfo::m_iClone]

// address=[0x3f44e90]
// [Decompilation failed for static struct SEnvironmentInfo CDebugInfo::m_EnvInfo]

// address=[0x3f44f08]
// [Decompilation failed for static std::string * CDebugInfo::m_strOS]

