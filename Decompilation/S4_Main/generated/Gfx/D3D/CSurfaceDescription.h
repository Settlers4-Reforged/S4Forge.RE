#ifndef CSURFACEDESCRIPTION_H
#define CSURFACEDESCRIPTION_H

#include "defines.h"

class CSurfaceDescription {
public:
    // address=[0x2f87700]
     CSurfaceDescription(void);

    // Type information members
public:
    _DDSURFACEDESC2 m_sSurfaceDescription;
    _DDSURFACEDESC m_sSurfaceDescriptionOld;

};


#endif // CSURFACEDESCRIPTION_H
