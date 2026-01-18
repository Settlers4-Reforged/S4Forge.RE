#ifndef CGUIMSGLIST_H
#define CGUIMSGLIST_H

#include "defines.h"

class CGuiMsgList {
public:
    // address=[0x13b8320]
     CGuiMsgList(void);

    // address=[0x13b8370]
    bool  AddListItem(int a2, char const * Str);

    // address=[0x13b8400]
    bool  SetListindex(int a2);

    // address=[0x13b8440]
    bool  SetTopindex(int a2);

    // address=[0x13b8560]
    bool  ShowLastMessage(void);

    // address=[0x13b8570]
    bool  RemoveListItem(int a2);

    // address=[0x13b8670]
    bool  Clear(void);

    // address=[0x13b86a0]
    bool  SetOutputControls(int a2, struct CGuiMsgList::SControl * a3);

    // address=[0x13b8780]
    int  SetListentry(int a2, int a3);

    // address=[0x13b9e80]
     ~CGuiMsgList(void);

    // address=[0x13b9ed0]
    int  GetListindexFromControlindex(int a2);

    // address=[0x13b9ef0]
    int  GetTopindex(void);

    // address=[0x13b9f10]
    int  Listcount(void);

};


#endif // CGUIMSGLIST_H
