#ifndef CCLIENT_H
#define CCLIENT_H

#include "defines.h"

class CClient {
  public:
    // address=[0x15b1b00]
    CClient(void);

    // address=[0x15b1b60]
    CClient(class CClient const &a2);

    // address=[0x15b1bd0]
    CClient(long _uIp, int _uPlayerId, int _uPeerId);

    // address=[0x15b1c40]
    virtual ~CClient(void);

    // address=[0x15b1c60]
    bool operator==(unsigned int _uPeerId);

    // address=[0x15b3530]
    class CClient &operator=(class CClient const &a2);

    // address=[0x15b3b30]
    long GetIP(void);

    // address=[0x15b3b50]
    unsigned int GetLastPingTime(void);

    // address=[0x15b3b70]
    unsigned int GetPeerId(void);

    // address=[0x15c4df0]
    void SetLastAckTime(unsigned int _uAckTime);

    // Type information members
  public:
    _BYTE m_bReady;
    int m_uIp;
    _DWORD m_uPeerId;
    uint m_uLastAckTime;
    _DWORD m_uLastPingTime;
    _DWORD m_uCreationTick2;
    _DWORD field_1C;
    _DWORD m_uPlayerId;
};

#endif // CCLIENT_H
