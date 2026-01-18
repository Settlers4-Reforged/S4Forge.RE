#ifndef CANIMALRANCHROLE_H
#define CANIMALRANCHROLE_H

#include "defines.h"

class CAnimalRanchRole : public CWorkUpBuildingRole {
public:
    // address=[0x13ffa00]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x14e5d70]
    virtual void  LogicUpdate(class CBuilding * a2);

    // address=[0x14e62d0]
    virtual void  Init(class CBuilding * a2);

    // address=[0x14e6390]
    virtual void  PostLoadInit(class CBuilding * a2);

    // address=[0x14e63b0]
     CAnimalRanchRole(std::istream & a2);

    // address=[0x14e6470]
    virtual void  Store(std::ostream & a2);

    // address=[0x14e6690]
    virtual  ~CAnimalRanchRole(void);

    // address=[0x14e6780]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14e67b0]
    virtual int  GetBuildingRole(void);

    // address=[0x14fc8a0]
     CAnimalRanchRole(void);

    // address=[0x14fd7f0]
    static class CAnimalRanchRole * __cdecl Load(std::istream & a1);

    // address=[0x3d8a964]
    static unsigned long m_iClassID;

};


#endif // CANIMALRANCHROLE_H
