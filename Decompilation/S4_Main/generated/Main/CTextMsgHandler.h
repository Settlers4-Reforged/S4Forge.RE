#ifndef CTEXTMSGHANDLER_H
#define CTEXTMSGHANDLER_H

class CTextMsgHandler : public IEvn_Handle {
public:
    // address=[0x14cf8e0]
    static void __cdecl Init(void);

    // address=[0x14cf900]
    static bool __cdecl AddChatMsg(char const *,int);

    // address=[0x14cf9f0]
    static bool __cdecl AddTextMsg(int,int,int,int,bool,bool,...);

    // address=[0x14cfbe0]
    static bool __cdecl AddTextMsg(int,int,bool,bool,...);

    // address=[0x14cfd80]
    static bool __cdecl AddTextMsg(int,int,bool);

    // address=[0x14cfe80]
    static bool __cdecl AddTextMsg(char const *,int,int,int,bool);

    // address=[0x14cff70]
    static bool __cdecl AddWarningMsg(int,int,int,int);

    // address=[0x14d00a0]
    static bool __cdecl AddWarningMsg(int,int);

    // address=[0x14d01c0]
    static void __cdecl ExecuteMsg(int);

    // address=[0x14d0310]
    static void __cdecl ExecuteLastMsg(void);

    // address=[0x14d0390]
    static void __cdecl Update(void);

    // address=[0x14d0530]
    static void __cdecl SendAllMessages(bool,bool,bool);

    // address=[0x14d0830]
    static void __cdecl RefreshList(void);

    // address=[0x14d09f0]
    static void __cdecl Kill(void);

    // address=[0x14d0ae0]
    static void __cdecl SetMaxMsgCount(int);

    // address=[0x14d0ca0]
    void *  GetEventFunction(void);

    // address=[0x14d1b20]
     CTextMsgHandler(void);

protected:
    // address=[0x3d8a80c]
    static int m_iMaxMsgs;

    // address=[0x4032218]
    static int m_iUpdateTrigger;

    // address=[0x4032228]
    static class std::vector<struct STextMessage *,class std::allocator<struct STextMessage *> > m_vMsgs;

private:
    // address=[0x14cf3e0]
    static bool __cdecl CheckWarning(char const *,int *);

    // address=[0x14cf4d0]
    static bool __cdecl CheckExists(struct STextMessage *);

    // address=[0x14cf600]
    virtual bool  OnEvent(class CEvn_Event &);

    // address=[0x14cf6d0]
    static void __cdecl AddMsgToVector(struct STextMessage *);

    // address=[0x14cf800]
    static int __cdecl GetPlayerIcon(int);

    // address=[0x14cf890]
    static unsigned int __cdecl GetSwitchMask(unsigned int);

};


#endif // CTEXTMSGHANDLER_H
