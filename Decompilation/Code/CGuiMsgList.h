#ifndef CGUIMSGLIST_H
#define CGUIMSGLIST_H

class CGuiMsgList {
public:
    // address=[0x13b8320]
     CGuiMsgList(void);

    // address=[0x13b8370]
    bool  AddListItem(int,char const *);

    // address=[0x13b8400]
    bool  SetListindex(int);

    // address=[0x13b8440]
    bool  SetTopindex(int);

    // address=[0x13b8560]
    bool  ShowLastMessage(void);

    // address=[0x13b8570]
    bool  RemoveListItem(int);

    // address=[0x13b8670]
    bool  Clear(void);

    // address=[0x13b86a0]
    bool  SetOutputControls(int,struct CGuiMsgList::SControl *);

    // address=[0x13b8780]
    int  SetListentry(int,int);

    // address=[0x13b9e80]
     ~CGuiMsgList(void);

    // address=[0x13b9ed0]
    int  GetListindexFromControlindex(int);

    // address=[0x13b9ef0]
    int  GetTopindex(void);

    // address=[0x13b9f10]
    int  Listcount(void);

};


#endif // CGUIMSGLIST_H
