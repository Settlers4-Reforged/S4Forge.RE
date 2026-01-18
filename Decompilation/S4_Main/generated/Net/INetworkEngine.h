#ifndef INETWORKENGINE_H
#define INETWORKENGINE_H

#include "defines.h"

class INetworkEngine {
public:
    // address=[0x13a4250]
    bool  StormDidEnterSession(void)const;

    // address=[0x1486f50]
    int  GetVirtualTick(void);

    // address=[0x149f500]
    long  GetLocalIP(void);

    // address=[0x14aaa40]
    bool  EndTick(void);

    // address=[0x14aaa70]
    void  GameInitalized(void);

    // address=[0x14aab60]
    unsigned int  GetBytesPerSecond(void);

    // address=[0x14aada0]
    int  GetValidTick(void);

    // address=[0x14aae30]
    bool  IsHost(void);

    // address=[0x14ab0d0]
    bool  StartNewTick(bool a2);

    // address=[0x14b46a0]
    std::string  ConvertIPAddress(unsigned int a2);

    // address=[0x14b46f0]
    bool  EndGame(int a2);

    // address=[0x14b4760]
    bool  KickPlayerPeerId(unsigned int a2);

    // address=[0x14b4860]
    bool  RemovePlayerPeerId(unsigned int a2);

    // address=[0x14bce40]
    void  StormResetEnterSessionFlag(void);

    // address=[0x15c8460]
     INetworkEngine(bool);

    // address=[0x15c84d0]
    virtual  ~INetworkEngine(void);

    // address=[0x15c8530]
    bool  SendNetMessage(class CEvn_Logic & a2);

    // address=[0x15c8690]
    bool  SendNetMessage(unsigned int a2, unsigned int a3, unsigned int a4, int a5);

    // address=[0x15c87e0]
    bool  SendAsyncNetMessage(class CEvn_Logic & a2, unsigned char a3);

    // address=[0x15c8890]
    bool  DeliverNetMessages(void);

    // address=[0x15c8990]
    bool  CheckForMsg(void);

    // address=[0x15c89c0]
    bool  Start(bool a2, unsigned int a3, unsigned int a4, wchar_t const * Source);

    // address=[0x15c8bf0]
    void  ContinueSearchForHost(void);

    // address=[0x15c8c10]
    void  OnEndSaving(void);

    // address=[0x15c8c70]
    void  StormJoinSessionSucceeded(void);

    // address=[0x15c8cb0]
    void  StormHost_NewPlayerMessage(unsigned int a2, std::wstring & a3, int a4);

    // address=[0x15c8d00]
    void  StormOnPeerGone(unsigned int a2);

    // address=[0x15c8d20]
    void  StormOnHost(void);

    // address=[0x15c8d60]
    void  OnQuickMatched(bool a2);

    // address=[0x15c8d80]
    void  OnJoinedFromInvite(void);

    // address=[0x16227a0]
    void  StormEnteredSession(void);

private:
    // address=[0x15c9030]
    class CNet_Event  PopMsg(void a2);

    // address=[0x15c9070]
    void  PushAsyncMsg(class CNet_Event & Src, unsigned char a2);

    // address=[0x15c90a0]
    bool  PushMsg(class CNet_Event & a2);

};


#endif // INETWORKENGINE_H
