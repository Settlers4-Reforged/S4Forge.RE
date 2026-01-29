#ifndef CMILITARYBUILDINGINFO_H
#define CMILITARYBUILDINGINFO_H

#include "defines.h"

class CMilitaryBuildingInfo : public CBuildingInfo {
public:
    // address=[0x1454710]
     CMilitaryBuildingInfo(void);

    // address=[0x1454cb0]
    virtual unsigned int  Size(void)const;

    // Type information members
public:
    CMilitaryBuildingInfo::Pair[10] m_aStationedArchers;
    CMilitaryBuildingInfo::Pair[10] m_aStationedSoldiers;

};


#endif // CMILITARYBUILDINGINFO_H
