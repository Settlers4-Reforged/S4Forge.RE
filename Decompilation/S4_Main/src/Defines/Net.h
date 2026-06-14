#ifndef NET_H
#define NET_H

constexpr int MAX_RECEIVER_SOCKETS = 32;
constexpr int COMMUNICATION_TICK_VALUE = 1;

constexpr int MAX_NUMBER_MESSAGE_STACKS = 50;

constexpr int PLAYERDATA_UPDATE = 0;
constexpr int PLAYERDATA_FINAL = 1;

constexpr int MAP_UPLOAD_CHUNK_SIZE = 0x300u;

constexpr int MSG_BUFFER_SIZE = 0x400u;

enum T_HOST_HANDLERS {
    StartState = 0x22,
    InitHostNetwork = 0x1,
    InitClientNetwork = 0x2,
    OnHostWait = 0x3,
    SearchHost = 0x4,
    WaitingForGameConnect = 0x10,
    HostInitGame = 0x12,
    HostStartTick = 0x13,
    RegClientConnect = 0x17,
    WereConnectedForGame = 0x18,
    ClientStartingGame = 0x1A,
    ClientGameInited = 0x1C,
    ClientStartTick = 0x1D,
    HostGameInited = 0x1F,
    GameSyncMsgGot = 0x20,
    GameInGameMsgGot = 0x21,
    ErrorState = 0x0,
    DoNothing = 0x24,
    ClientSearchesGameHost = 0x23,
    ClientReceivesGameInfo = 0x26,
    ClientLoginHost = 0x28,
    ClientJoins = 0x27,
    ClientReceivePlayerData = 0x2A,
    ClientReceivePlayerPing = 0x2B,
    ClientLobbyPrepare = 0x29,
    ResendPlayerData = 0x6,
    ResendPlayerPing = 0x2C,
    InitGameStruct = 0x7,
    HostPressedStart = 0x8,
    ResendFinalPData = 0x9,
    ChatLine = 0x2D,
    GameAlreadyFull = 0x2E,
    GameAsyncMsgGot = 0x2F,
    AmIStillAlive = 0x30,
    HeIsStillAlive = 0x31,
    InitHostAfterLobby = 0x32,
    InitClientAfterLobby = 0x33,
    SendMapToClient = 0x34,
    ClientReceiveMap = 0x35,
    ClientLeavesMyGame = 0x38,
    ClientWrongVersion = 0x39,
    ClientWrongVersionAfterLobby = 0x3A,
    PerformLeaveGame = 0x3B,
    SendChatLine = 0x3D,
    HostChoseMap = 0x3C,
    QuickMatchChoseMap = 0x44,
    InviteAccepted = 0x47,
    UserDataChange = 0x3E,
    KickClient = 0x3F,
    WereKicked = 0x40,
    GameInGamePackedGot = 0x41,
    GameSync0MsgGot = 0x42,
    UserChangeSlots = 0x43,
};

#endif // NET_H
