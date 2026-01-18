#ifndef ISELECTABLESETTLERROLE_H
#define ISELECTABLESETTLERROLE_H

#include "defines.h"

class ISelectableSettlerRole : public ISettlerRole {
public:
    // address=[0x157c980]
     ISelectableSettlerRole(std::istream & a2);

    // address=[0x157ca10]
    virtual void  Store(std::ostream & a2);

    // address=[0x157ca50]
    virtual int  GetGroupFlags(void)const;

    // address=[0x157ca70]
    virtual int  SetGroupFlags(int a2);

    // address=[0x157cac0]
    virtual int  SetGroupFlagBits(int a2);

    // address=[0x157cb20]
    virtual int  ClearGroupFlagBits(int a2);

    // address=[0x1592df0]
    int  GetPrimaryGroupId(void)const;

protected:
    // address=[0x157c930]
     ISelectableSettlerRole(void);

    // address=[0x157c960]
    virtual  ~ISelectableSettlerRole(void);

    // address=[0x157cb80]
    bool  TakeCommonJob(class CSettler * a2);

    // address=[0x157cc70]
    virtual int  Decrease(int a2);

    // address=[0x157cd70]
    bool  ProcessGoToPosFerry(class CSettler * a2, class CEntityEvent const * a3);

    // address=[0x157ce70]
    unsigned int  ThiefCheckMasquerade(class CSettler * a2);

    // address=[0x157cfa0]
    void  ThiefExpose(class IEntity * a2);

    // address=[0x157cfd0]
    void  ThiefDisguise(class IEntity * a2);

    // address=[0x15921c0]
    int  GetGroupFlagsEx(void)const;

};


#endif // ISELECTABLESETTLERROLE_H
