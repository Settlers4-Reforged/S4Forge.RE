#ifndef CSTATELOBBYLOADMP_H
#define CSTATELOBBYLOADMP_H

class CStateLobbyLoadMP : public CStateLobbyGameSettings {
public:
    // address=[0x14bce60]
    static class CGameState * __cdecl DynamicCreateFunc(void *);

    // address=[0x14bcee0]
     CStateLobbyLoadMP(void *);

    // address=[0x14bcfa0]
    virtual  ~CStateLobbyLoadMP(void);

    // address=[0x14bcfc0]
    virtual bool  Perform(void);

    // address=[0x14bd0b0]
    virtual bool  OnEvent(class CEvn_Event &);

protected:
    // address=[0x14bd0d0]
    virtual void  CreateLobbyGameInfo(class CLanLobbyGameSettings &,std::wstring &);

private:
    // address=[0x14bd200]
    void  UpdateGameTypeData(void);

};


#endif // CSTATELOBBYLOADMP_H
