#ifndef CGAMEHOST_H
#define CGAMEHOST_H

class CGameHost : public IEventHandler {
public:
    // address=[0x14aab10]
    unsigned int  GetBytesPerSecond(void);

    // address=[0x15b4e60]
    bool  AllSend(void);

    // address=[0x15b51a0]
    bool  StartNewCycle(bool);

    // address=[0x15b5360]
    int  GetValidTick(void);

    // address=[0x15b5380]
    int  GetVirtualTick(void);

    // address=[0x15b53a0]
    bool  RegisterMsgStacks(class CMsgStacks *);

    // address=[0x15b53d0]
    bool  InitAsClient(unsigned int);

    // address=[0x15b5440]
    bool  InitAsHost(unsigned int);

    // address=[0x15b54b0]
     CGameHost(bool);

    // address=[0x15b5ed0]
    virtual  ~CGameHost(void);

    // address=[0x15b60d0]
    bool  PushMsg(class CNet_Event &);

    // address=[0x15b6190]
    void  PushAsyncMsg(class CNet_Event &,unsigned char);

    // address=[0x15b63b0]
    class CNet_Event  PopMsg(void);

    // address=[0x15b63f0]
    long  GetLocalIP(void);

    // address=[0x15b6420]
    unsigned short  GetMessageLength(void);

    // address=[0x15b6450]
    void  GameInitalized(void);

    // address=[0x15b64f0]
    void  ContinueSearchForHost(void);

    // address=[0x15b6510]
    bool  Run(void);

    // address=[0x15b6c60]
    bool  StartIniFileGame(wchar_t const *);

    // address=[0x15b88c0]
    void  PingClients(void);

    // address=[0x15b8990]
    void  DeliverSimpleMessage(void);

    // address=[0x15b8d70]
    std::string  ConvertIPAddress(unsigned int);

    // address=[0x15b8de0]
    bool  RemovePlayerPeerId(unsigned int);

    // address=[0x15b9000]
    bool  IsLocalIP(unsigned int);

    // address=[0x15b9040]
    bool  OnEndGame(int);

    // address=[0x15b9050]
    void  OnEndSaving(int);

    // address=[0x15b9080]
    void  StormJoinSessionSucceeded(void);

    // address=[0x15b91b0]
    void  StormHost_NewPlayerMessage(unsigned int,std::wstring &,int);

    // address=[0x15b9210]
    void  StormClientLeavesMyGame(unsigned int);

    // address=[0x15b9280]
    void  PromoteToHost(void);

    // address=[0x15b9300]
    void  OnQuickMatched(bool);

    // address=[0x15b9330]
    void  OnQuickMatchedHosted(void);

    // address=[0x15b9500]
    void  OnJoinedFromOnlineFlow(void);

protected:
    // address=[0x15b9860]
    virtual void  FillHandlersArray(void);

private:
    // address=[0x15b9cd0]
    bool  OnHostWait(void *);

    // address=[0x15b9ce0]
    bool  OnClientRun(void);

    // address=[0x15b9d20]
    void  OnHostRun(void);

    // address=[0x15b9da0]
    bool  InitHostNetwork(void *);

    // address=[0x15b9dc0]
    bool  InitClientNetwork(void *);

    // address=[0x15b9df0]
    bool  ErrorState(void *);

    // address=[0x15b9e70]
    void  ProcessPlayerData(struct SLobbyPlayerData &);

    // address=[0x15ba130]
    void  SendPlayerData(unsigned int);

    // address=[0x15ba420]
    void  SendToAll(unsigned int,short *,unsigned int,short *,unsigned int,bool);

    // address=[0x15ba650]
    void  SendToHost(unsigned int,short *,unsigned int,short *,unsigned int,bool);

    // address=[0x15ba860]
    bool  AddGame(struct SGameInfo &);

    // address=[0x15baa20]
    void  ValidateGameList(void);

    // address=[0x15baba0]
    unsigned int  GetLocalID(void);

    // address=[0x15bac30]
    int  GetSlot(unsigned int);

    // address=[0x15bacb0]
    void  NotifyClients(unsigned int);

    // address=[0x15bb0e0]
    bool  IsExclusiveColor(int);

    // address=[0x15bb160]
    bool  HostChoseMap(void *);

    // address=[0x15bb380]
    bool  QuickMatchChoseMap(void *);

    // address=[0x15bb3b0]
    bool  InviteAccepted(void *);

    // address=[0x15bb430]
    bool  StartState(void *);

    // address=[0x15bb440]
    bool  SearchHost(void *);

    // address=[0x15bb5b0]
    bool  ClientSearchesGameHost(void *);

    // address=[0x15bb880]
    bool  ClientReceivesGameInfo(void *);

    // address=[0x15bba10]
    bool  ClientLoginHost(void *);

    // address=[0x15bbdf0]
    bool  ClientJoins(void *);

    // address=[0x15bc010]
    bool  ClientWrongVersion(void *);

    // address=[0x15bc040]
    bool  ClientWrongVersionAfterLobby(void *);

    // address=[0x15bc070]
    bool  ClientReceivePlayerData(void *);

    // address=[0x15bc320]
    bool  ClientReceivePlayerPing(void *);

    // address=[0x15bc370]
    bool  ClientLobbyPrepare(void *);

    // address=[0x15bc3a0]
    bool  ResendPlayerData(void *);

    // address=[0x15bc3c0]
    bool  ResendPlayerPing(void *);

    // address=[0x15bc450]
    bool  HostPressedStart(void *);

    // address=[0x15bc560]
    bool  InitGameStruct(void *);

    // address=[0x15bc680]
    bool  ResendFinalPData(void *);

    // address=[0x15bc720]
    bool  ChatLine(void *);

    // address=[0x15bc7c0]
    bool  GameAlreadyFull(void *);

    // address=[0x15bc7f0]
    bool  SendMapToClient(void *);

    // address=[0x15bce20]
    bool  ClientReceiveMap(void *);

    // address=[0x15bd220]
    bool  ClientLeavesMyGame(void *);

    // address=[0x15bd290]
    bool  PerformLeaveGame(void *);

    // address=[0x15bd2b0]
    bool  SendChatLine(void *);

    // address=[0x15bd420]
    bool  UserDataChange(void *);

    // address=[0x15bd980]
    bool  KickClient(void *);

    // address=[0x15bda30]
    bool  WereKicked(void *);

    // address=[0x15bda70]
    bool  UserChangeSlots(void *);

    // address=[0x15bde60]
    bool  InitHostAfterLobby(void *);

    // address=[0x15bde90]
    bool  InitClientAfterLobby(void *);

    // address=[0x15bdec0]
    bool  WaitingForGameConnect(void *);

    // address=[0x15be220]
    bool  HostInitGame(void *);

    // address=[0x15be3c0]
    bool  HostStartTick(void *);

    // address=[0x15be460]
    bool  RegClientConnect(void *);

    // address=[0x15be750]
    bool  WereConnectedForGame(void *);

    // address=[0x15be760]
    bool  ClientStartingGame(void *);

    // address=[0x15be8b0]
    bool  ClientGameInited(void *);

    // address=[0x15be8e0]
    bool  ClientStartTick(void *);

    // address=[0x15be980]
    bool  HostGameInited(void *);

    // address=[0x15beaf0]
    bool  GameSyncMsgGot(void *);

    // address=[0x15beba0]
    bool  GameSync0MsgGot(void *);

    // address=[0x15bec60]
    bool  GameInGameMsgGot(void *);

    // address=[0x15bed50]
    bool  GameAsyncMsgGot(void *);

    // address=[0x15bee60]
    bool  AmIStillAlive(void *);

    // address=[0x15bef30]
    bool  HeIsStillAlive(void *);

    // address=[0x15bef60]
    bool  GameInGamePackedGot(void *);

    // address=[0x15bf0e0]
    bool  IsValidSaveGame(struct SGameInfo &);

    // address=[0x15c4970]
    bool  DoNothing(void *);

};


#endif // CGAMEHOST_H
