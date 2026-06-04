#ifndef CCLIENTLIST_H
#define CCLIENTLIST_H

#include "defines.h"

class CClient;
class CClientList {
  public:
    // address=[0x15b1d30]
    long GetPlayerIP(int a1);

    // address=[0x15b1d60]
    unsigned int GetPlayerPeerId(int a2);

    // address=[0x15b1d90]
    bool ContainsPeerId(unsigned int _uPeerId);

    // address=[0x15b1e50]
    bool Add(unsigned int _uIp, int _uPlayerId, int _uPeerId);

    // address=[0x15b1f30]
    unsigned int GetPlayerPing(unsigned int _id);

    // address=[0x15b1f90]
    CClientList(void);

    // address=[0x15b1fc0]
    virtual ~CClientList(void);

    // address=[0x15b1fe0]
    int CreateNewPlayerID(void);

    // address=[0x15b2000]
    bool RemoveClientAt(int a2);

    // address=[0x15b20c0]
    bool RemoveClientPeerId(unsigned int _uPeerId);

    // address=[0x15b21d0]
    bool AllClientsReady(void);

    // address=[0x15b2220]
    void SetClientReadyFromPeerId(unsigned int _uPeerId, bool _bReady);

    // address=[0x15b2320]
    int GetClientIndexPerPeerId(unsigned int _uPeerId);

    // address=[0x15b3b90]
    int GetSize(void);

    // address=[0x15c4d90]
    void SetClientLastAck(unsigned int _uPlayerId, unsigned int _uAckTime);

    // Type information members
  public:
    std::vector<CClient> m_vClients;
};

#endif // CCLIENTLIST_H
