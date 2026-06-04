#include "CClientList.h"

#include "CBB/CBBSupport.h"
#include "CClient.h"

#include <algorithm>

// Definitions for class CClientList

// address=[0x15b1d30]
// Decompiled from int __thiscall CClientList::GetPlayerIP(CClientList *this, unsigned int a1)
long CClientList::GetPlayerIP(int a1) {
    return this->m_vClients[a1].GetIP();
}

// address=[0x15b1d60]
// Decompiled from int __thiscall CClientList::GetPlayerPeerId(CClientList *this, unsigned int a1)
unsigned int CClientList::GetPlayerPeerId(int a2) {
    return this->m_vClients[a2].GetPeerId();
}

// address=[0x15b1d90]
// Decompiled from char __thiscall CClientList::ContainsPeerId(CClientList *this, uint _uPeerId)
bool CClientList::ContainsPeerId(unsigned int _uPeerId) {
    for(auto &rClient : this->m_vClients) {
        if(rClient.GetPeerId() == _uPeerId)
            return true;
    }
    return false;
}

// address=[0x15b1e50]
// Decompiled from char __thiscall CClientList::Add(CClientList *this, int _uIp, int _uPlayerId, int _uPeerId)
bool CClientList::Add(unsigned int _uIp, int _uPlayerId, int _uPeerId) {
    if(CClientList::ContainsPeerId(_uPeerId))
        return false;

    this->m_vClients.emplace_back(_uIp, _uPlayerId, _uPeerId);
    return false; // huh?
}

// address=[0x15b1f30]
// Decompiled from int __thiscall CClientList::GetPlayerPing(CClientList *this, unsigned int _id)
unsigned int CClientList::GetPlayerPing(unsigned int _id) {
    BB_ASSERT(_id <= GetSize() - 1)
    return this->m_vClients[_id].GetLastPingTime();
}

// address=[0x15b1f90]
// Decompiled from void __thiscall CClientList::CClientList(CClientList *this)
CClientList::CClientList(void) : m_vClients() {
}

// address=[0x15b1fc0]
// Decompiled from void __thiscall CClientList::~CClientList(boost::exception *this)
CClientList::~CClientList(void) = default;

// address=[0x15b1fe0]
// Decompiled from int __thiscall CClientList::CreateNewPlayerID(CClientList *this)
int CClientList::CreateNewPlayerID(void) {
    return this->m_vClients.size();
}

// address=[0x15b2000]
// Decompiled from char __thiscall CClientList::RemoveClientAt(CClientList *this, unsigned int a2)
bool CClientList::RemoveClientAt(int a2) {
    if(a2 > this->m_vClients.size() - 1)
        return false;

    this->m_vClients.erase(this->m_vClients.begin() + a2);
    return true;
}

// address=[0x15b20c0]
// Decompiled from char __thiscall CClientList::RemoveClientPeerId(CClientList *this, int a2)
bool CClientList::RemoveClientPeerId(unsigned int _uPeerId) {
    for(auto pIt = this->m_vClients.begin(); pIt != this->m_vClients.end(); ++pIt) {
        if(*pIt == _uPeerId) {
            this->m_vClients.erase(pIt);
            return true;
        }
    }

    return false;
}

// address=[0x15b21d0]
// Decompiled from char __thiscall CClientList::AllClientsReady(CClientList *this)
bool CClientList::AllClientsReady(void) {
    for(const auto &rClient : this->m_vClients) {
        if(!rClient.m_bReady)
            return false;
    }
    return true;
}

// address=[0x15b2220]
// Decompiled from void __thiscall CClientList::SetClientReadyFromPeerId(CClientList *this, int _uPeerId, bool _bReady)
void CClientList::SetClientReadyFromPeerId(unsigned int _uPeerId, bool _bReady) {
    for(auto &rClient : this->m_vClients) {
        if(rClient == _uPeerId) {
            rClient.m_bReady = _bReady;
            return;
        }
    }

    BB_REPORT("Client not found !!!");
}

// address=[0x15b2320]
// Decompiled from unsigned int __thiscall CClientList::GetClientIndexPerPeerId(CClientList *this, uint _uPeerId)
int CClientList::GetClientIndexPerPeerId(unsigned int _uPeerId) {
    int i = 0;
    for(auto &rClient : this->m_vClients) {
        if(rClient == _uPeerId) {
            return i;
        }

        ++i;
    }

    return -1;
}

// address=[0x15b3b90]
// Decompiled from int __thiscall CClientList::GetSize(CClientList *this)
int CClientList::GetSize(void) {
    return this->m_vClients.size();
}

// address=[0x15c4d90]
// Decompiled from void __thiscall CClientList::SetClientLastAck(CClientList *this, unsigned int a1, unsigned int a3)
void CClientList::SetClientLastAck(unsigned int _uPlayerId, unsigned int _uAckTime) {
    this->m_vClients[_uPlayerId].SetLastAckTime(_uAckTime);
}
