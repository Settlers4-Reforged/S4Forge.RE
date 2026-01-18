#ifndef CGUIEVENTHANDLER_H
#define CGUIEVENTHANDLER_H

#include "defines.h"

class CGuiEventHandler : public IEvn_Handle {
public:
    // address=[0x139da10]
     CGuiEventHandler(bool a2);

    // address=[0x139daf0]
    virtual  ~CGuiEventHandler(void);

    // address=[0x139dbc0]
    virtual void *  GetEventFunction(void);

    // address=[0x139dbd0]
    virtual bool  OnEvent(class CEvn_Event & a2);

    // address=[0x139eaa0]
    void  RecalcDialogPos(bool a2);

private:
    // address=[0x139c480]
    bool  HandleMsgKeyPress(class CEvn_Event & a2);

    // address=[0x139c960]
    bool  HandleMsgKeyDown(class CEvn_Event & a2);

    // address=[0x139cae0]
    void  HandleMsgNewDialog(class CEvn_Event & a2);

    // address=[0x139d020]
    void  HandleMsgOpenSettings(class CEvn_Event & a2);

    // address=[0x139d150]
    void  HandleMsgOpenSidebar(class CEvn_Event & a2);

    // address=[0x139d340]
    void  HandleMsgCloseAllDialogs(void);

    // address=[0x139d5c0]
    void  HandleMsgRefreshDialog(class CEvn_Event & a2);

    // address=[0x139d830]
    void  HandleMsgRefreshSettingsDialog(class CEvn_Event & a2);

    // address=[0x139d8b0]
    void  ResetMainMenu(void);

    // address=[0x139d8e0]
    void  ResetMainMenuForContext(void);

    // address=[0x139f020]
    struct GuiDialogParameters  CGuiEventHandler::GetTextMessageDialogParameters(void a2)const;

};


#endif // CGUIEVENTHANDLER_H
