#ifndef CDEBUGINFO_H
#define CDEBUGINFO_H

#include "defines.h"

class CDebugInfo {
public:
    // address=[0x135e070]
    static bool __cdecl IsMMX(void);

    // address=[0x1480a00]
    static bool __cdecl CheckEnvironment(bool a1);

    // address=[0x1480b10]
    static bool __cdecl IsTargetPlatform(void);

    // address=[0x1481080]
    static bool __cdecl IsWindowsNT40(void);

    // address=[0x14c2e70]
    static bool __cdecl IsNetworkAvailable(void);

private:
    // address=[0x147f840]
    static void __cdecl LogEnvironment(void);

    // address=[0x147fa70]
    static bool __cdecl CheckOS(void);

    // address=[0x147fc10]
    static bool __cdecl CheckCPU(void);

    // address=[0x147fd80]
    static bool __cdecl CheckGraphicsAdapter(void);

    // address=[0x147fd90]
    static struct SFreqInfo __cdecl CPUSpeed(int a1);

    // address=[0x147ff20]
    static bool __cdecl CheckMemory(void);

    // address=[0x147ff80]
    static struct SFreqInfo __cdecl GetBSFCpuSpeed(unsigned int a1);

    // address=[0x14800f0]
    static struct SFreqInfo __cdecl GetRDTSCCpuSpeed(void a1);

    // address=[0x14803b0]
    static unsigned short __cdecl wincpuid(void);

    // address=[0x1480450]
    static unsigned int __cdecl wincpufeatures(void);

    // address=[0x14804f0]
    static struct SFreqInfo __cdecl GetCmosCpuSpeed(void a1);

    // address=[0x1480700]
    static unsigned short __cdecl wincpuidsupport(void);

    // address=[0x1480730]
    static unsigned short __cdecl check_8086(void);

    // address=[0x1480780]
    static unsigned short __cdecl check_80286(void);

    // address=[0x14807d0]
    static unsigned short __cdecl check_80386(void);

    // address=[0x1480820]
    static unsigned short __cdecl check_IDProc(void);

    // address=[0x1480920]
    static unsigned short __cdecl check_clone(void);

    // address=[0x1480960]
    static int __cdecl GetCmosTick(void);

    // address=[0x1480980]
    static unsigned int __cdecl cpuTimeStamp(unsigned long * a1, unsigned long * a2);

    // address=[0x14809c0]
    static unsigned int __cdecl diffTime64(unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long * a5, unsigned long * a6);

    // address=[0x3d899d8]
    static unsigned int * processor_cycles;

    // address=[0x3f44e88]
    static unsigned int m_iClone;

    // address=[0x3f44e90]
    static struct SEnvironmentInfo m_EnvInfo;

    // address=[0x3f44f08]
    static std::string * m_strOS;

};


#endif // CDEBUGINFO_H
