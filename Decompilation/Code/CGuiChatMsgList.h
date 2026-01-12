#ifndef CGUICHATMSGLIST_H
#define CGUICHATMSGLIST_H

class CGuiChatMsgList {
public:
    // address=[0x139fea0]
     CGuiChatMsgList(void);

    // address=[0x139fef0]
    bool  AddListItem(char const *);

    // address=[0x139ff70]
    bool  SetListindex(int);

    // address=[0x139ffb0]
    bool  SetTopindex(int);

    // address=[0x13a0090]
    bool  RemoveListItem(int);

    // address=[0x13a0160]
    bool  Clear(void);

    // address=[0x13a01d0]
    bool  SetOutputControls(int,struct CGuiChatMsgList::SControl *);

    // address=[0x13a0270]
    int  SetListentry(int,int);

    // address=[0x13a40f0]
     ~CGuiChatMsgList(void);

    // address=[0x13a4120]
    int  GetTopindex(void);

    // address=[0x13a4230]
    int  Listcount(void);

};


#endif // CGUICHATMSGLIST_H
