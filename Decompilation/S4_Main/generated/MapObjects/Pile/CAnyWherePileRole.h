#ifndef CANYWHEREPILEROLE_H
#define CANYWHEREPILEROLE_H

#include "defines.h"

class CAnyWherePileRole : public IPileRole {
public:
    // address=[0x13ffaa0]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x155af40]
    virtual void  Init(class CPile * a2);

    // address=[0x155afc0]
    virtual void  LogicUpdate(class CPile * a2);

    // address=[0x155afe0]
    virtual void  Empty(class CPile * a2);

    // address=[0x155b000]
    virtual bool  ChangeGoodTypeUnforseen(class CPile * a2, int a3);

    // address=[0x155b020]
    virtual void  Occupied(class CPile * a2, int a3);

    // address=[0x155b040]
    virtual bool  SetFree(class CPile * a2, int a3);

    // address=[0x155b060]
     CAnyWherePileRole(std::istream & a2);

    // address=[0x155b110]
    virtual void  Store(std::ostream & a2);

    // address=[0x155b1c0]
    virtual  ~CAnyWherePileRole(void);

    // address=[0x155b2a0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x155b380]
    virtual void  SubjectDie(class CPile * a2, int a3);

    // address=[0x155b390]
    virtual void  SubjectStarted(class CPile * a2);

    // address=[0x155b3a0]
    virtual void  SubjectStopped(class CPile * a2);

    // address=[0x1560340]
    static class CAnyWherePileRole * __cdecl Load(std::istream & a1);

    // address=[0x3d8bbb4]
    static unsigned long m_iClassID;

private:
    // address=[0x1560110]
     CAnyWherePileRole(void);

};


#endif // CANYWHEREPILEROLE_H
