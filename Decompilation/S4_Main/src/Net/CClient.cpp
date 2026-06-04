#include "CClient.h"

// Definitions for class CClient

// address=[0x15b1b00]
// Decompiled from CClient *__thiscall CClient::CClient(CClient *this)
CClient::CClient(void) {
    this->m_bReady = 0;
    this->m_uPeerId = -1;
    this->m_uLastAckTime = 0;
    this->m_uLastPingTime = 0;
    this->m_uCreationTick2 = 0;
    this->field_1C = 0;
    this->m_uPlayerId = -1;
}

// address=[0x15b1b60]
// Decompiled from CClient *__thiscall CClient::CClient(CClient *this, const struct CClient *a2)
CClient::CClient(class CClient const &a2) {
    this->m_uIp = a2.m_uIp;
    this->m_uPeerId = a2.m_uPeerId;
    this->m_uLastPingTime = a2.m_uLastPingTime;
    this->m_uCreationTick2 = a2.m_uCreationTick2;
    this->m_uPlayerId = a2.m_uPlayerId;
    this->m_uLastAckTime = 0;
    this->m_bReady = a2.m_bReady;
}

// address=[0x15b1bd0]
// Decompiled from CClient *__thiscall CClient::CClient(CClient *this, int _uIp, int _uPlayerId, int _uPeerId)
CClient::CClient(long _uIp, int _uPlayerId, int _uPeerId) {
    this->m_uCreationTick2 = 0;
    this->m_uIp = _uIp;
    this->m_uPeerId = _uPeerId;
    this->m_uLastPingTime = timeGetTime();
    this->m_uCreationTick2 = timeGetTime();
    this->m_uPlayerId = _uPlayerId;
    this->m_uLastAckTime = 0;
    this->m_bReady = 0;
}

// address=[0x15b1c40]
// Decompiled from CClient *__thiscall CClient::~CClient(CClient *this)
CClient::~CClient(void) = default;

// address=[0x15b1c60]
// Decompiled from bool __thiscall CClient::operator==(CClient *this, int a2)
bool CClient::operator==(unsigned int _uPeerId) {
    return this->m_uPeerId == _uPeerId;
}

// address=[0x15b3530]
// Decompiled from int __thiscall CClient::operator=(int this, int a2)
class CClient &CClient::operator=(class CClient const &a2) {
    this->m_bReady = a2.m_bReady;
    this->m_uIp = a2.m_uIp;
    this->m_uPeerId = a2.m_uPeerId;
    this->m_uLastAckTime = a2.m_uLastAckTime;
    this->m_uLastPingTime = a2.m_uLastPingTime;
    this->m_uCreationTick2 = a2.m_uCreationTick2;
    this->field_1C = a2.field_1C;
    this->m_uPlayerId = a2.m_uPlayerId;
}

// address=[0x15b3b30]
// Decompiled from int __thiscall CClient::GetIP(CClient *this)
long CClient::GetIP(void) {
    return this->m_uIp;
}

// address=[0x15b3b50]
// Decompiled from int __thiscall CClient::GetLastPingTime(CClient *this)
unsigned int CClient::GetLastPingTime(void) {
    return this->m_uLastPingTime;
}

// address=[0x15b3b70]
// Decompiled from int __thiscall CClient::GetPeerId(CClient *this)
unsigned int CClient::GetPeerId(void) {
    return this->m_uPeerId;
}

// address=[0x15c4df0]
// Decompiled from void __thiscall CClient::SetLastAckTime(CClient *this, unsigned int a2)
void CClient::SetLastAckTime(unsigned int _uAckTime) {
    this->m_uLastAckTime = _uAckTime;
}
