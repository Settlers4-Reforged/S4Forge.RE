#include "CMsgStack.h"

#include "Debug/CTrace.h"

// Definitions for class CMsgStack

// address=[0x15c49f0]
// Decompiled from bool __thiscall CMsgStack::GetAI(CMsgStack *this)
bool CMsgStack::GetAI(void) {
    return this->m_bAI;
}

// address=[0x15c9d30]
// Decompiled from CMsgStack *__thiscall CMsgStack::CMsgStack(CMsgStack *this)
CMsgStack::CMsgStack(void) : list<CNet_Event>() {
    this->m_iExpectedSize = -1;
    this->m_bAI = 0;
    this->m_uChangeTime = 0;
}

// address=[0x15c9d70]
// Decompiled from void __thiscall CMsgStack::~CMsgStack(boost::exception *this)
CMsgStack::~CMsgStack(void) = default;

// address=[0x15c9d90]
// Decompiled from int __thiscall CMsgStack::Clear(CMsgStack *this)
void CMsgStack::Clear(void) {
    // TODO: should probably be just ->clear()...
    while(!this->empty()) {
        this->pop_front();
    }
}

// address=[0x15c9dc0]
// Decompiled from struct CNet_Event *__thiscall CMsgStack::GetMsg(CMsgStack *this, struct CNet_Event *__return_ptr retstr)
class CNet_Event CMsgStack::GetMsg(void) {
    CNet_Event cEvent = this->front();
    this->pop_front();
    return cEvent;
}

// address=[0x15c9e60]
// Decompiled from void __thiscall CMsgStack::AddMsg(CMsgStack *this, struct CNet_Event *a2)
void CMsgStack::AddMsg(class CNet_Event &a2) {
    std::list<CNet_Event>::push_back(a2);
    this->m_uChangeTime = timeGetTime();
}

// address=[0x15c9e90]
// Decompiled from bool __thiscall CMsgStack::IsValid(CMsgStack *this)
bool CMsgStack::IsValid(void) {
    if(!CMsgStack::IsSizeAlreadySet())
        return 0;
    int v2 = std::list<CNet_Event>::size();
    if(v2 > this->m_iExpectedSize)
        CTrace::Print("MsgStacks.cpp: Message stack is: %d expected: %d!", v2, this->m_iExpectedSize);
    return this->m_iExpectedSize == v2;
}

// address=[0x15c9f00]
// Decompiled from void __thiscall CMsgStack::SetExpectedSize(CMsgStack *this, int a2)
void CMsgStack::SetExpectedSize(int a2) {
    this->m_iExpectedSize = a2;
    this->m_uChangeTime = timeGetTime();
}

// address=[0x15c9f30]
// Decompiled from void __thiscall CMsgStack::Sort(CMsgStack *this)
void CMsgStack::Sort(void) {
    std::list<CNet_Event>::sort();
}

// address=[0x15c9f50]
// Decompiled from char __thiscall CMsgStack::IsInStack(CMsgStack *this, unsigned __int8 _iId)
bool CMsgStack::IsInStack(unsigned char _iId) {
    for(auto &rMsg : *this) {
        if(rMsg.m_iMsgNr == _iId) {
            return true;
        }
    }

    return false;
}

// address=[0x15cadc0]
// Decompiled from bool __thiscall CMsgStack::IsSizeAlreadySet(CMsgStack *this)
bool CMsgStack::IsSizeAlreadySet(void) {

    return this->m_iExpectedSize != -1;
}

// address=[0x15cc590]
// Decompiled from int __thiscall CMsgStack::ClearAndValidate(CMsgStack *this)
void CMsgStack::ClearAndValidate(void) {
    this->m_iExpectedSize = 0;
    return CMsgStack::Clear();
}

// address=[0x15cc5c0]
// Decompiled from int __thiscall CMsgStack::GetExpectedSize(CMsgStack *this)
int CMsgStack::GetExpectedSize(void) {
    return this->m_iExpectedSize;
}

// address=[0x15cc5e0]
// Decompiled from int __thiscall CMsgStack::Invalidate(CMsgStack *this)
void CMsgStack::Invalidate(void) {
    this->m_iExpectedSize = -1;
    return CMsgStack::Clear();
}

// address=[0x15cc610]
// Decompiled from bool __thiscall CMsgStack::IsEmpty(CMsgStack *this)
bool CMsgStack::IsEmpty(void) {
    return std::list<CNet_Event>::size() == 0;
}

// address=[0x15cc650]
// Decompiled from void __thiscall CMsgStack::SetAI(CMsgStack *this, bool a2)
void CMsgStack::SetAI(bool a2) {
    this->m_bAI = a2;
}
