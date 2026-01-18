#ifndef CLOGIC_H
#define CLOGIC_H

#include "defines.h"

class CLogic : public CBBObject {
public:
    // address=[0x141d890]
    class IEffects &  Effects(void);

    // address=[0x14609a0]
    void  SetFillDialogInfos(void (__cdecl*)(class CInfoExchange *,bool,bool) a2, class CInfoExchange * a3, bool a4);

    // address=[0x14609e0]
    void  SetFillSideBarInfos(void (__cdecl*)(class CInfoExchange *,bool,int) a2, class CInfoExchange * a3, int a4);

    // address=[0x1460a50]
    void  SetLocalGlobalSwitch(bool a2);

    // address=[0x1460a70]
    void  SwitchExtraInfoMenu(bool a2);

    // address=[0x1469c90]
     CLogic(void);

    // address=[0x1469d90]
    virtual  ~CLogic(void);

    // address=[0x1469e80]
    void  PostLoadMap(class CGameType & a2);

    // address=[0x1469f30]
    void  LogicUpdate(void);

    // address=[0x1470980]
    class IFutureEvents &  FutureEvents(void);

    // address=[0x158b9a0]
    void  SetWarAction(void);

private:
    // address=[0x146a0b0]
    void  ChangeWorldPosition(void);

    // address=[0x146a380]
    void  HandleCursor(void);

    // address=[0x146a770]
    void  HandleSoundtracks(void);

};


#endif // CLOGIC_H
