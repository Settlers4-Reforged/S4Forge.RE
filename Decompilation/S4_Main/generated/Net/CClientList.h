#ifndef CCLIENTLIST_H
#define CCLIENTLIST_H

#include "defines.h"

class CClientList {
public:
    // address=[0x15b1d30]
    long  GetPlayerIP(int a2);

    // address=[0x15b1d60]
    unsigned int  GetPlayerPeerId(int a2);

    // address=[0x15b1d90]
    bool  ContainsPeerId(unsigned int a2);

    // address=[0x15b1e50]
    bool  Add(unsigned int a2, int a3, int a4);

    // address=[0x15b1f30]
    unsigned int  GetPlayerPing(unsigned int a2);

    // address=[0x15b1f90]
     CClientList(void);

    // address=[0x15b1fc0]
    virtual  ~CClientList(void);

    // address=[0x15b1fe0]
    int  CreateNewPlayerID(void);

    // address=[0x15b2000]
    bool  RemoveClientAt(int a2);

    // address=[0x15b20c0]
    bool  RemoveClientPeerId(unsigned int a2);

    // address=[0x15b21d0]
    bool  AllClientsReady(void);

    // address=[0x15b2220]
    void  SetClientReadyFromPeerId(unsigned int a2, bool a3);

    // address=[0x15b2320]
    int  GetClientIndexPerPeerId(unsigned int a2);

    // address=[0x15b3b90]
    int  GetSize(void);

    // address=[0x15c4d90]
    void  SetClientLastAck(unsigned int a2, unsigned int a3);

};


#endif // CCLIENTLIST_H
