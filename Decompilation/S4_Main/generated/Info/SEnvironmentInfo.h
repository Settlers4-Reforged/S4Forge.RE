#ifndef SENVIRONMENTINFO_H
#define SENVIRONMENTINFO_H

#include "defines.h"

class SEnvironmentInfo {
public:
    // address=[0x1481020]
     SEnvironmentInfo(void);

    // address=[0x1481050]
     ~SEnvironmentInfo(void);

    // Type information members
public:
    int sVersion;
    int sPlatformId;
    int sOSVersionMayor;
    int sOSVersionMinor;
    std::string sOSAdditionalInfo;
    int gap;
    bool bIsMMX;
    int sProcessorCount;
    int sProcessorSpeed;
    unsigned int uTotalPhyMemory;
    unsigned int uTotalVirtMemory;
    unsigned int uFreePhyMemory;
    unsigned int uFreeVirtMemory;
    int[9] gpuGap;
    bool bLoadedWSA;

};


#endif // SENVIRONMENTINFO_H
