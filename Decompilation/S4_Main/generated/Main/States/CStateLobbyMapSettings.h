#ifndef CSTATELOBBYMAPSETTINGS_H
#define CSTATELOBBYMAPSETTINGS_H

#include "defines.h"

class CStateLobbyMapSettings : public CGuiGameState {
public:
    // address=[0x14bd6f0]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14bd770]
     CStateLobbyMapSettings(void *);

    // address=[0x14bda80]
    virtual  ~CStateLobbyMapSettings(void);

    // address=[0x14bdb10]
    virtual bool  Perform(void);

    // address=[0x14bdbb0]
    virtual bool  OnEvent(class CEvn_Event & a2);

private:
    // address=[0x14be980]
    void  AddMapList(std::wstring a2, std::wstring a3);

    // address=[0x14bf100]
    int  RefreshMapList(void);

    // address=[0x14bf350]
    void  ClearMapList(void);

    // address=[0x14bf3e0]
    void  SetupGUI(void);

    // address=[0x14bf470]
    void  UpdateData(void);

    // address=[0x14bf490]
    void  ApplyMapData(int a2);

    // address=[0x14bf8c0]
    void  Sort(void);

    // address=[0x14bf970]
    int  Compare(int a2, int a3);

    // address=[0x4030938]
    static struct CLanLobbyMapSettings::SMapEntry * * m_stempMapPtr;

};


#endif // CSTATELOBBYMAPSETTINGS_H
