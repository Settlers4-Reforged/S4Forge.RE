#ifndef CCASTLEROLE_H
#define CCASTLEROLE_H

#include "defines.h"

class CCastleRole : public CMilitaryBuildingRole {
public:
    // address=[0x14000e0]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x14fc910]
     CCastleRole(void);

    // address=[0x14fcbb0]
    virtual  ~CCastleRole(void);

    // address=[0x14fd060]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14fd440]
    virtual int  GetBuildingRole(void);

    // address=[0x14fd8f0]
    static class CCastleRole * __cdecl Load(std::istream & a1);

    // address=[0x1506870]
    virtual void  FillGfxInfo(class CBuilding * a1, struct SGfxObjectInfo & a2);

    // address=[0x15068f0]
    virtual void  Init(class CBuilding * a2);

    // address=[0x1506960]
    virtual void  PostLoadInit(class CBuilding * a2);

    // address=[0x1506990]
    virtual int  Decrease(int a2);

    // address=[0x15069b0]
     CCastleRole(std::istream & a2);

    // address=[0x15069e0]
    virtual void  Store(std::ostream & a2);

    // address=[0x3d8b120]
    static unsigned long m_iClassID;

};


#endif // CCASTLEROLE_H
