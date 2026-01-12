#include "CDebugInfo.h"

// Definitions for class CDebugInfo

// address=[0x135e070]
// Decompiled from bool CDebugInfo::IsMMX()
static bool __cdecl CDebugInfo::IsMMX(void) {
  
  return byte_3F44EC0 == 1;
}


// address=[0x1480a00]
// Decompiled from char __cdecl CDebugInfo::CheckEnvironment(bool a1)
static bool __cdecl CDebugInfo::CheckEnvironment(bool) {
  
  DWORD LastError; // eax
  DWORD v2; // eax
  DWORD v3; // eax

  memset(&CDebugInfo::m_EnvInfo, 0, 0x74u);
  if ( !(unsigned __int8)CDebugInfo::CheckOS() )
  {
    LastError = GetLastError();
    CTrace::Print("DebugInfo.cpp: Error calling CheckOS(); LastError: %d", LastError);
  }
  if ( !(unsigned __int8)CDebugInfo::CheckCPU() )
  {
    v2 = GetLastError();
    CTrace::Print("DebugInfo.cpp: Error calling CheckCPU(); LastError: %d", v2);
  }
  if ( !(unsigned __int8)CDebugInfo::CheckMemory() )
  {
    v3 = GetLastError();
    CTrace::Print("DebugInfo.cpp: Error calling CheckMemory(); LastError: %d", v3);
  }
  if ( a1 )
    CDebugInfo::LogEnvironment();
  if ( !(unsigned __int8)CDebugInfo::IsWindowsNT40() || (unsigned __int8)CDebugInfo::IsMMX() )
  {
    if ( (unsigned __int8)CDebugInfo::IsTargetPlatform() )
    {
      byte_3F44F00 = ImportWSAFunctions();
      if ( !byte_3F44F00 )
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
static bool __cdecl CDebugInfo::IsTargetPlatform(void) {
  
  if ( dword_3F44E94 == 2 )
    return dword_3F44E98 >= 4;
  if ( dword_3F44E94 == 1 )
    return dword_3F44E98 >= 4;
  return dword_3F44E94 != 0;
}


// address=[0x1481080]
// Decompiled from bool CDebugInfo::IsWindowsNT40()
static bool __cdecl CDebugInfo::IsWindowsNT40(void) {
  
  return CDebugInfo::m_EnvInfo == 10;
}


// address=[0x14c2e70]
// Decompiled from char CDebugInfo::IsNetworkAvailable()
static bool __cdecl CDebugInfo::IsNetworkAvailable(void) {
  
  return byte_3F44F00;
}


// address=[0x147f840]
// Decompiled from int CDebugInfo::LogEnvironment()
static void __cdecl CDebugInfo::LogEnvironment(void) {
  
  const char *v0; // eax
  const char *v1; // eax

  BBSupportTracePrintF(1, "=====================================================================");
  BBSupportTracePrintF(1, "SYSTEM INFORMATION");
  BBSupportTracePrintF(1, "---------------------------------------------------------------------");
  BBSupportTracePrintF(1, "CPU Vendor: %s", asc_3D89A08);
  BBSupportTracePrintF(1, "CPU Family: %d", (unsigned __int16)word_3D89A28);
  BBSupportTracePrintF(1, "CPU Model : %d", (unsigned __int8)byte_3F44E8D);
  BBSupportTracePrintF(1, "CPU Steppg: %d", (unsigned __int8)byte_3F44E8C);
  BBSupportTracePrintF(1, "# of CPUs : %d", dword_3F44EC4);
  BBSupportTracePrintF(1, "CPU Speed : %d", dword_3F44EC8);
  if ( byte_3F44EC0 )
    BBSupportTracePrintF(1, "MMX Ext.  : %s", "Yes");
  else
    BBSupportTracePrintF(1, "MMX Ext.  : %s", "No");
  BBSupportTracePrintF(1, (char *)&byte_36BE55A);
  BBSupportTracePrintF(1, "OPERATING SYSTEM INFORMATION");
  BBSupportTracePrintF(1, "---------------------------------------------------------------------");
  v0 = (const char *)std::string::c_str((char *)&CDebugInfo::m_strOS + 28 * CDebugInfo::m_EnvInfo);
  BBSupportTracePrintF(1, "Detected OS: %s", v0);
  BBSupportTracePrintF(1, "VersionMajor: %d", dword_3F44E98);
  BBSupportTracePrintF(1, "VersionMinor: %d", dword_3F44E9C);
  v1 = (const char *)std::string::c_str(&unk_3F44EA0);
  BBSupportTracePrintF(1, "Additional Info: %s", v1);
  BBSupportTracePrintF(1, (char *)&byte_36BE55B);
  BBSupportTracePrintF(1, "MEMORY INFORMATION");
  BBSupportTracePrintF(1, "---------------------------------------------------------------------");
  BBSupportTracePrintF(1, "Total Physical Memory: %d MBytes", ((unsigned int)dword_3F44ECC >> 20) + 1);
  BBSupportTracePrintF(1, "Free  Physical Memory: %d MBytes", (unsigned int)dword_3F44ED4 >> 20);
  BBSupportTracePrintF(1, "Total Virtual  Memory: %d MBytes", (unsigned int)dword_3F44ED0 >> 20);
  BBSupportTracePrintF(1, "Free  Virtual  Memory: %d MBytes", (unsigned int)dword_3F44ED8 >> 20);
  return BBSupportTracePrintF(1, "=====================================================================");
}


// address=[0x147fa70]
// Decompiled from char CDebugInfo::CheckOS()
static bool __cdecl CDebugInfo::CheckOS(void) {
  
  _OSVERSIONINFOA VersionInformation; // [esp+8h] [ebp-98h] BYREF

  memset(&VersionInformation, 0, sizeof(VersionInformation));
  VersionInformation.dwOSVersionInfoSize = 148;
  if ( GetVersionExA(&VersionInformation) )
  {
    dword_3F44E94 = VersionInformation.dwPlatformId;
    dword_3F44E98 = VersionInformation.dwMajorVersion;
    dword_3F44E9C = VersionInformation.dwMinorVersion;
    std::string::operator=(&unk_3F44EA0, VersionInformation.szCSDVersion);
    if ( dword_3F44E94 )
    {
      if ( dword_3F44E94 == 1 )
      {
        if ( dword_3F44E98 > 4 || dword_3F44E98 == 4 && dword_3F44E9C > 0 )
          CDebugInfo::m_EnvInfo = 4;
        else
          CDebugInfo::m_EnvInfo = 3;
      }
      else if ( dword_3F44E94 == 2 )
      {
        switch ( dword_3F44E98 )
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
            if ( dword_3F44E98 <= 5 )
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
    dword_3F44E94 = -1;
    dword_3F44E98 = -1;
    dword_3F44E9C = -1;
    return 0;
  }
}


// address=[0x147fc10]
// Decompiled from char CDebugInfo::CheckCPU()
static bool __cdecl CDebugInfo::CheckCPU(void) {
  
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
  dword_3F44EC8 = v11;
  memset(&SystemInfo, 0, sizeof(SystemInfo));
  GetSystemInfo(&SystemInfo);
  dword_3F44EC4 = SystemInfo.dwNumberOfProcessors;
  byte_3F44EC0 = ((unsigned int)dword_800000 & CDebugInfo::wincpufeatures()) != 0;
  return 1;
}


// address=[0x147fd80]
// Decompiled from char CDebugInfo::CheckGraphicsAdapter()
static bool __cdecl CDebugInfo::CheckGraphicsAdapter(void) {
  
  return 1;
}


// address=[0x147fd90]
// Decompiled from _DWORD *__cdecl CDebugInfo::CPUSpeed(_DWORD *a1, int a2)
static struct SFreqInfo __cdecl CDebugInfo::CPUSpeed(int) {
  
  int *RDTSCCpuSpeed; // eax
  int *CmosCpuSpeed; // eax
  int *BSFCpuSpeed; // eax
  _BYTE v6[16]; // [esp+0h] [ebp-84h] BYREF
  _BYTE v7[16]; // [esp+10h] [ebp-74h] BYREF
  _BYTE v8[16]; // [esp+20h] [ebp-64h] BYREF
  int v9; // [esp+30h] [ebp-54h]
  int v10; // [esp+34h] [ebp-50h]
  int v11; // [esp+38h] [ebp-4Ch]
  unsigned __int16 v12; // [esp+3Ch] [ebp-48h]
  _DWORD v13[4]; // [esp+40h] [ebp-44h] BYREF
  int v14; // [esp+50h] [ebp-34h]
  int v15; // [esp+54h] [ebp-30h]
  int v16; // [esp+58h] [ebp-2Ch]
  int v17; // [esp+5Ch] [ebp-28h]
  int v18; // [esp+60h] [ebp-24h]
  int v19; // [esp+64h] [ebp-20h]
  int v20; // [esp+68h] [ebp-1Ch]
  int v21; // [esp+6Ch] [ebp-18h]
  int v22; // [esp+70h] [ebp-14h]
  int v23; // [esp+74h] [ebp-10h]
  int v24; // [esp+78h] [ebp-Ch]
  int v25; // [esp+7Ch] [ebp-8h]

  v12 = CDebugInfo::wincpuid();
  v9 = CDebugInfo::wincpufeatures();
  v11 = 0;
  memset(v13, 0, sizeof(v13));
  if ( a2 > 0 )
  {
    if ( a2 <= 150 )
    {
      v10 = 4000 * a2;
      v11 = 1;
    }
  }
  else
  {
    v10 = 4000000;
  }
  if ( (v9 & 0x10) == 0 || v11 )
  {
    if ( v12 < 3u )
    {
      *a1 = v13[0];
      a1[1] = v13[1];
      a1[2] = v13[2];
      a1[3] = v13[3];
    }
    else
    {
      BSFCpuSpeed = (int *)CDebugInfo::GetBSFCpuSpeed(v6, v10);
      v14 = *BSFCpuSpeed;
      v15 = BSFCpuSpeed[1];
      v16 = BSFCpuSpeed[2];
      v17 = BSFCpuSpeed[3];
      *a1 = v14;
      a1[1] = v15;
      a1[2] = v16;
      a1[3] = v17;
    }
    return a1;
  }
  else
  {
    if ( a2 )
    {
      CmosCpuSpeed = (int *)CDebugInfo::GetCmosCpuSpeed(v7);
      v18 = *CmosCpuSpeed;
      v19 = CmosCpuSpeed[1];
      v20 = CmosCpuSpeed[2];
      v21 = CmosCpuSpeed[3];
      *a1 = v18;
      a1[1] = v19;
      a1[2] = v20;
      a1[3] = v21;
    }
    else
    {
      RDTSCCpuSpeed = (int *)CDebugInfo::GetRDTSCCpuSpeed(v8);
      v22 = *RDTSCCpuSpeed;
      v23 = RDTSCCpuSpeed[1];
      v24 = RDTSCCpuSpeed[2];
      v25 = RDTSCCpuSpeed[3];
      *a1 = v22;
      a1[1] = v23;
      a1[2] = v24;
      a1[3] = v25;
    }
    return a1;
  }
}


// address=[0x147ff20]
// Decompiled from char CDebugInfo::CheckMemory()
static bool __cdecl CDebugInfo::CheckMemory(void) {
  
  _MEMORYSTATUS Buffer; // [esp+0h] [ebp-24h] BYREF

  memset(&Buffer, 0, sizeof(Buffer));
  GlobalMemoryStatus(&Buffer);
  dword_3F44ECC = Buffer.dwTotalPhys;
  dword_3F44ED0 = Buffer.dwTotalPageFile;
  dword_3F44ED4 = Buffer.dwAvailPhys;
  dword_3F44ED8 = Buffer.dwAvailPageFile;
  return 1;
}


// address=[0x147ff80]
// Decompiled from _DWORD *__cdecl CDebugInfo::GetBSFCpuSpeed(_DWORD *a1, unsigned int a2)
static struct SFreqInfo __cdecl CDebugInfo::GetBSFCpuSpeed(unsigned int) {
  
  __int16 v3; // bx
  LARGE_INTEGER PerformanceCount; // [esp+4h] [ebp-40h] BYREF
  LARGE_INTEGER v5; // [esp+Ch] [ebp-38h] BYREF
  LARGE_INTEGER Frequency; // [esp+14h] [ebp-30h] BYREF
  DWORD v7; // [esp+1Ch] [ebp-28h]
  DWORD v8; // [esp+20h] [ebp-24h]
  int i; // [esp+24h] [ebp-20h]
  int v10; // [esp+28h] [ebp-1Ch]
  DWORD v11; // [esp+2Ch] [ebp-18h]
  _DWORD v12[4]; // [esp+30h] [ebp-14h] BYREF

  v10 = 0;
  v8 = 0;
  v7 = -1;
  memset(v12, 0, sizeof(v12));
  if ( QueryPerformanceFrequency(&Frequency) )
  {
    for ( i = 0; i < 10; ++i )
    {
      QueryPerformanceCounter(&PerformanceCount);
      v3 = 4000;
      do
        --v3;
      while ( v3 );
      QueryPerformanceCounter(&v5);
      v8 = v5.LowPart - PerformanceCount.LowPart;
      if ( v5.LowPart - PerformanceCount.LowPart < v7 )
        v7 = v8;
    }
    v11 = 100000 * v7 / (Frequency.LowPart / 0xA);
    if ( v11 % Frequency.LowPart > Frequency.LowPart >> 1 )
      ++v11;
    v10 = a2 / v11;
    v12[2] = a2 / v11;
    if ( a2 % v11 > v11 >> 1 )
      ++v10;
    v12[1] = v11;
    v12[3] = v10;
    *a1 = a2;
    a1[1] = v12[1];
    a1[2] = v12[2];
    a1[3] = v12[3];
    return a1;
  }
  else
  {
    *a1 = v12[0];
    a1[1] = v12[1];
    a1[2] = v12[2];
    a1[3] = v12[3];
    return a1;
  }
}


// address=[0x14800f0]
// Decompiled from _DWORD *__cdecl CDebugInfo::GetRDTSCCpuSpeed(_DWORD *a1)
static struct SFreqInfo __cdecl CDebugInfo::GetRDTSCCpuSpeed(void) {
  
  unsigned __int64 v2; // rax
  unsigned __int64 v3; // rax
  LARGE_INTEGER Frequency; // [esp+Ch] [ebp-60h] BYREF
  int v5; // [esp+14h] [ebp-58h]
  int v6; // [esp+18h] [ebp-54h]
  LARGE_INTEGER PerformanceCount; // [esp+1Ch] [ebp-50h] BYREF
  unsigned int v8; // [esp+24h] [ebp-48h]
  unsigned int v9; // [esp+28h] [ebp-44h]
  HANDLE hThread; // [esp+2Ch] [ebp-40h]
  int nPriority; // [esp+30h] [ebp-3Ch]
  LARGE_INTEGER v12; // [esp+34h] [ebp-38h] BYREF
  int v13; // [esp+3Ch] [ebp-30h]
  unsigned int v14; // [esp+40h] [ebp-2Ch]
  unsigned int v15; // [esp+44h] [ebp-28h]
  unsigned int v16; // [esp+48h] [ebp-24h]
  int v17; // [esp+4Ch] [ebp-20h]
  unsigned int v18; // [esp+50h] [ebp-1Ch]
  DWORD v19; // [esp+54h] [ebp-18h]
  _DWORD v20[4]; // [esp+58h] [ebp-14h] BYREF

  v17 = 0;
  v16 = 0;
  v18 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  hThread = GetCurrentThread();
  memset(v20, 0, sizeof(v20));
  if ( QueryPerformanceFrequency(&Frequency) )
  {
    do
    {
      ++v13;
      v18 = v16;
      v16 = v17;
      QueryPerformanceCounter(&PerformanceCount);
      v12 = PerformanceCount;
      nPriority = GetThreadPriority(hThread);
      if ( nPriority != 0x7FFFFFFF )
        SetThreadPriority(hThread, 15);
      while ( v12.LowPart - PerformanceCount.LowPart < 0x32 )
      {
        QueryPerformanceCounter(&v12);
        v2 = __rdtsc();
        v5 = v2;
      }
      PerformanceCount = v12;
      while ( v12.LowPart - PerformanceCount.LowPart < 0x3E8 )
      {
        QueryPerformanceCounter(&v12);
        v3 = __rdtsc();
        v6 = v3;
      }
      if ( nPriority != 0x7FFFFFFF )
        SetThreadPriority(hThread, nPriority);
      v9 = v6 - v5;
      v19 = 100000 * (v12.LowPart - PerformanceCount.LowPart) / (Frequency.LowPart / 0xA);
      v15 += v19;
      v14 += v6 - v5;
      if ( v19 % Frequency.LowPart > Frequency.LowPart >> 1 )
        ++v19;
      v17 = v9 / v19;
      if ( v9 % v19 > v19 >> 1 )
        ++v17;
      v8 = v18 + v16 + v17;
    }
    while ( v13 < 3 || v13 < 20 && (j__abs(3 * v17 - v8) > 3 || j__abs(3 * v16 - v8) > 3 || j__abs(3 * v18 - v8) > 3) );
    v18 = 10 * v14 / v15;
    v16 = 100 * v14 / v15;
    if ( v16 - 10 * v18 >= 6 )
      ++v18;
    v20[2] = v14 / v15;
    v20[3] = v14 / v15;
    v17 = 10 * (v14 / v15);
    if ( v18 - v17 >= 6 )
      ++v20[3];
    v20[1] = v15;
    *a1 = v14;
    a1[1] = v20[1];
    a1[2] = v20[2];
    a1[3] = v20[3];
    return a1;
  }
  else
  {
    *a1 = v20[0];
    a1[1] = v20[1];
    a1[2] = v20[2];
    a1[3] = v20[3];
    return a1;
  }
}


// address=[0x14803b0]
// Decompiled from __int16 __thiscall CDebugInfo::wincpuid(void *this)
static unsigned short __cdecl CDebugInfo::wincpuid(void) {
  
  __int16 v2; // [esp+0h] [ebp-4h]

  if ( (unsigned __int16)CDebugInfo::wincpuidsupport(this) )
  {
    v2 = CDebugInfo::check_IDProc();
  }
  else
  {
    CDebugInfo::m_iClone = (unsigned __int16)CDebugInfo::check_clone();
    v2 = CDebugInfo::check_8086();
    if ( v2 )
    {
      v2 = CDebugInfo::check_80286();
      if ( v2 != 2 )
      {
        v2 = CDebugInfo::check_80386();
        if ( v2 != 3 )
          v2 = 4;
      }
    }
  }
  if ( CDebugInfo::m_iClone )
    return v2 | 0x8000;
  return v2;
}


// address=[0x1480450]
// Decompiled from int CDebugInfo::wincpufeatures()
static unsigned int __cdecl CDebugInfo::wincpufeatures(void) {
  
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
// Decompiled from _DWORD *__cdecl CDebugInfo::GetCmosCpuSpeed(_DWORD *a1)
static struct SFreqInfo __cdecl CDebugInfo::GetCmosCpuSpeed(void) {
  
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
  _DWORD v19[4]; // [esp+4Ch] [ebp-14h] BYREF

  v16 = 0;
  hThread = GetCurrentThread();
  memset(v19, 0, sizeof(v19));
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
  v19[0] = v7;
  v2[1] = v7 / 0x186A0;
  v13 = 10 * (v7 / 0xF4240);
  v16 = v7 / 0xF4240;
  v19[2] = v7 / 0xF4240;
  if ( v7 / 0x186A0 - v13 >= 6 )
    ++v16;
  v19[3] = v16;
  v19[1] = 1000000 * (v18 - CmosTick);
  *a1 = v19[0];
  a1[1] = v19[1];
  a1[2] = v19[2];
  a1[3] = v19[3];
  return a1;
}


// address=[0x1480700]
// Decompiled from _BOOL2 CDebugInfo::wincpuidsupport()
static unsigned short __cdecl CDebugInfo::wincpuidsupport(void) {
  
  unsigned int v0; // kr00_4
  unsigned int v1; // kr04_4

  v0 = __readeflags();
  __writeeflags(v0 ^ 0x200000);
  v1 = __readeflags();
  return v0 != v1;
}


// address=[0x1480730]
// Decompiled from __int16 CDebugInfo::check_8086()
static unsigned short __cdecl CDebugInfo::check_8086(void) {
  
  return -1;
}


// address=[0x1480780]
// Decompiled from __int16 CDebugInfo::check_80286()
static unsigned short __cdecl CDebugInfo::check_80286(void) {
  
  return -1;
}


// address=[0x14807d0]
// Decompiled from int CDebugInfo::check_80386()
static unsigned short __cdecl CDebugInfo::check_80386(void) {
  
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
static unsigned short __cdecl CDebugInfo::check_IDProc(void) {
  
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
static unsigned short __cdecl CDebugInfo::check_clone(void) {
  
  char v5; // [esp-2h] [ebp-6h]

  _CF = !_ZF;
  __asm { pushfw }
  return !(v5 & 1);
}


// address=[0x1480960]
// Decompiled from int CDebugInfo::GetCmosTick()
static int __cdecl CDebugInfo::GetCmosTick(void) {
  
  int result; // eax

  __outbyte(0x70u, 0);
  LOBYTE(result) = __inbyte(0x71u);
  return (unsigned __int8)result;
}


// address=[0x1480980]
// Decompiled from int __cdecl CDebugInfo::cpuTimeStamp(unsigned int *a1, unsigned int *a2)
static unsigned int __cdecl CDebugInfo::cpuTimeStamp(unsigned long *,unsigned long *) {
  
  unsigned __int64 v2; // kr00_8

  v2 = __rdtsc();
  *a1 = HIDWORD(v2);
  *a2 = v2;
  return v2;
}


// address=[0x14809c0]
// Decompiled from int __cdecl CDebugInfo::diffTime64(  unsigned int a1,  unsigned int a2,  unsigned int a3,  unsigned int a4,  unsigned int *a5,  unsigned int *a6)
static unsigned int __cdecl CDebugInfo::diffTime64(unsigned long,unsigned long,unsigned long,unsigned long,unsigned long *,unsigned long *) {
  
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

