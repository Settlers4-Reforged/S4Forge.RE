#ifndef CLOGIC_H
#define CLOGIC_H

class CLogic : public CBBObject {
public:
    // address=[0x141d890]
    class IEffects &  Effects(void);

    // address=[0x14609a0]
    void  SetFillDialogInfos(void (__cdecl*)(class CInfoExchange *,bool,bool),class CInfoExchange *,bool);

    // address=[0x14609e0]
    void  SetFillSideBarInfos(void (__cdecl*)(class CInfoExchange *,bool,int),class CInfoExchange *,int);

    // address=[0x1460a50]
    void  SetLocalGlobalSwitch(bool);

    // address=[0x1460a70]
    void  SwitchExtraInfoMenu(bool);

    // address=[0x1469c90]
     CLogic(void);

    // address=[0x1469d90]
    virtual  ~CLogic(void);

    // address=[0x1469e80]
    void  PostLoadMap(class CGameType &);

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
