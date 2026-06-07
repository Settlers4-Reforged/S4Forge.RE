#include "CMsgStacks.h"

#include "CBB/CBBSupport.h"
#include "CMsgStack.h"
#include "Debug/CTrace.h"
#include "Defines/Net.h"

#include <cmath>

// Definitions for class CMsgStacks

// address=[0x15c4910]
// Decompiled from void __thiscall CMsgStacks::AdvanceValidTick(CMsgStacks *this)
void CMsgStacks::AdvanceValidTick(void) {
    ++this->m_iValidTick;
}

// address=[0x15c4940]
// Decompiled from void __thiscall CMsgStacks::AdvanceVirtualTick(CMsgStacks *this)
void CMsgStacks::AdvanceVirtualTick(void) {
    ++this->m_iVirtualTick;
}

// address=[0x15c4a20]
// Decompiled from int __thiscall CMsgStacks::GetLastMsgTime(CMsgStacks *this, unsigned int a2)
unsigned int CMsgStacks::GetLastMsgTime(unsigned int a2) {
    return this->m_pMsgStacks[1][a2]->m_uChangeTime;
}

// address=[0x15c4aa0]
// Decompiled from int __thiscall CMsgStacks::GetNumberOfStacks(CMsgStacks *this)
int CMsgStacks::GetNumberOfStacks(void) {
    return this->m_iNumberMsgStacks;
}

// address=[0x15c4ca0]
// Decompiled from int __thiscall CMsgStacks::GetValidTick(CMsgStacks *this)
int CMsgStacks::GetValidTick(void) {
    return this->m_iValidTick;
}

// address=[0x15c4cc0]
// Decompiled from int __thiscall CMsgStacks::GetVirtualTick(CMsgStacks *this)
int CMsgStacks::GetVirtualTick(void) {
    return this->m_iVirtualTick;
}

// address=[0x15c4ce0]
// Decompiled from int __thiscall CMsgStacks::Getdt(CMsgStacks *this)
int CMsgStacks::Getdt(void) {
    return this->m_iDeltaTme;
}

// address=[0x15c4d60]
// Decompiled from bool __thiscall CMsgStacks::IsStackAI(CMsgStacks *this, unsigned int a2)
bool CMsgStacks::IsStackAI(unsigned int a2) {
    return this->m_pMsgStacks[0][a2]->GetAI();
}

// address=[0x15c4e10]
// Decompiled from void __thiscall CMsgStacks::SetLastMsgTime(CMsgStacks *this, int a2, int a3, char a4)
void CMsgStacks::SetLastMsgTime(unsigned int a2, unsigned int a3, bool a4) {
    int iNumberMsgStacks; // [esp+8h] [ebp-8h]
    if(a4)
        iNumberMsgStacks = this->m_iNumberMsgStacks;
    else
        iNumberMsgStacks = 2;
    for(int i = 1; i < iNumberMsgStacks; ++i)
        this->m_pMsgStacks[i][a2]->m_uChangeTime = a3;
}

// address=[0x15cb660]
// Decompiled from char __thiscall CMsgStacks::TriggerTime(CMsgStacks *this)
bool CMsgStacks::TriggerTime(void) {

    // [esp+4h] [ebp-10h]
    // [esp+8h] [ebp-Ch]
    // [esp+Ch] [ebp-8h]

    for(int j = 0; j < this->m_iNumberPlayers; ++j) {
        BB_ASSERT(m_pMsgStacks[0][j]->IsEmpty())
        CMsgStack *pOldStack = this->m_pMsgStacks[0][j];
        for(int i = 0; i < this->m_iNumberMsgStacks - 1; ++i)
            this->m_pMsgStacks[i][j] = this->m_pMsgStacks[i + 1][j];
        this->m_pMsgStacks[this->m_iNumberMsgStacks - 1][j] = pOldStack;
        this->m_pMsgStacks[this->m_iNumberMsgStacks - 1][j]->Invalidate();
    }
    return 1;
}

// address=[0x15cb780]
// Decompiled from CMsgStacks *__thiscall CMsgStacks::CMsgStacks(CMsgStacks *this, int _iPlayers, int _iDeltaTime, int a4)
CMsgStacks::CMsgStacks(int _iPlayers, int _iDeltaTime, int _iTick) {
    this->m_iDeltaTme = _iDeltaTime;
    this->m_iNumberMsgStacks = static_cast<int>(static_cast<double>(2 * _iDeltaTime + 1) + std::pow<int, int>(COMMUNICATION_TICK_VALUE, 2));
    if(this->m_iNumberMsgStacks == 1)
        ++this->m_iNumberMsgStacks;
    this->m_iNumberPlayers = _iPlayers;
    BB_ASSERT(m_iNumberMsgStacks < MAX_NUMBER_MESSAGE_STACKS)
    this->m_bInited = CMsgStacks::InitStacks();
    this->m_iVirtualTick = _iTick + 1;
    this->m_iValidTick = _iTick;
}

// address=[0x15cb850]
// Decompiled from int __thiscall CMsgStacks::~CMsgStacks(CMsgStacks *this)
CMsgStacks::~CMsgStacks(void) {
    for(int i = 0; i < this->m_iNumberMsgStacks; ++i) {
        for(int j = 0; j < this->m_iNumberPlayers; ++j) {
            if(this->m_pMsgStacks[i][j]) {
                CMsgStack *v2 = this->m_pMsgStacks[i][j];
                delete v2;
                this->m_pMsgStacks[i][j] = 0;
            }
        }
    }
}

// address=[0x15cb920]
// Decompiled from char __thiscall CMsgStacks::PushMsg(CMsgStacks *this, struct CNet_Event *a2)
bool CMsgStacks::PushMsg(class CNet_Event &rMsg) {
    int PlayerNr = rMsg.m_iOwner - 1;
    BB_ASSERT(PlayerNr < m_iNumberPlayers)

    int iMsgTick = rMsg.m_iTick - CMsgStacks::GetValidTick();
    if(iMsgTick >= 0) {
        BB_REPORT("MsgStacks.cpp: Future netmsg got !")
        this->m_pMsgStacks[iMsgTick][PlayerNr]->AddMsg(rMsg);
        return true;
    }

    CTrace::Print(
        "MsgStacks.cpp: Old msg discarded: index#%d, Tick %d, Msg# %d!",
        rMsg.m_iOwner - 1,
        rMsg.m_iTick,
        rMsg.m_iMsgNr);
    return 1;
}

// address=[0x15cba00]
// Decompiled from CNet_Event *__thiscall CMsgStacks::PopMsg(CMsgStacks *this, CNet_Event *a2)
class CNet_Event CMsgStacks::PopMsg(void) {
    for(int i = 0; i < this->m_iNumberPlayers; ++i) {
        if(!this->m_pMsgStacks[0][i]->IsEmpty()) {
            CNet_Event v5 = this->m_pMsgStacks[0][i]->GetMsg();
            v5.m_iOwner = i + 1;
            return v5;
        }
    }
    return {0, 0, 0, 0, 0, 0, 0};
}

// address=[0x15cbae0]
// Decompiled from char __thiscall CMsgStacks::AddNewPlayer(CMsgStacks *this)
bool CMsgStacks::AddNewPlayer(void) {
    for(int i = 0; i < this->m_iDeltaTme; ++i) {
        this->m_pMsgStacks[i][this->m_iNumberPlayers] = new CMsgStack();
    }
    ++this->m_iNumberPlayers;
    return true;
}

// address=[0x15cbba0]
// Decompiled from int __thiscall CMsgStacks::GetNumPlayers(CMsgStacks *this)
int CMsgStacks::GetNumPlayers(void) {
    return this->m_iNumberPlayers;
}

// address=[0x15cbbc0]
// Decompiled from char __thiscall CMsgStacks::SetNumberOfClients(CMsgStacks *this, unsigned int a2)
bool CMsgStacks::SetNumberOfClients(unsigned int a2) {
    for(unsigned int i = this->m_iNumberPlayers; i < a2; ++i)
        CMsgStacks::AddNewPlayer();
    return 1;
}

// address=[0x15cbc00]
// Decompiled from CMsgStack *__thiscall CMsgStacks::Get(CMsgStacks *this, unsigned int a2, unsigned __int8 a3)
class CMsgStack *CMsgStacks::Get(unsigned int a2, unsigned char a3) {
    return this->m_pMsgStacks[a2][a3];
}

// address=[0x15cbc30]
// Decompiled from char __thiscall CMsgStacks::IsEmpty(CMsgStacks *this, unsigned int a2)
bool CMsgStacks::IsEmpty(unsigned int a2) {
    for(int i = 0; i < this->m_iNumberPlayers; ++i) {
        if(!Get(a2, i)->empty())
            return 0;
    }
    return 1;
}

// address=[0x15cbc90]
// Decompiled from CNet_Event *__thiscall CMsgStacks::GetMsgToSend(CMsgStacks *this, CNet_Event *a2)
class CNet_Event CMsgStacks::GetMsgToSend(void) {
    for(int i = 0; i < this->m_iNumberPlayers; ++i) {
        CMsgStack *pStack = CMsgStacks::Get(0, i);
        if(!pStack->empty()) {
            return pStack->GetMsg();
        }
    }
    return {0, 0, 0, 0, 0, 0, 0};
}

// address=[0x15cbd50]
// Decompiled from void __thiscall CMsgStacks::SetNumberOfExpectedMsgs(  CMsgStacks *this,  int _iTick,  unsigned __int8 _iPlayerID,  unsigned __int8 _iCount)
void CMsgStacks::SetNumberOfExpectedMsgs(unsigned int _iTick, unsigned char _iPlayerID, unsigned char _iCount) {

    // [esp+8h] [ebp-8h]

    BB_ASSERT(!IsSizeAlreadySet(_iTick, _iPlayerID))

    unsigned int iMsgTick = _iTick - CMsgStacks::GetValidTick();
    if(iMsgTick >= this->m_iNumberMsgStacks) {
        BB_REPORTF("MsgStacks:Future Netmsg got: Tick %d, Player %d size %d!", _iTick, _iPlayerID, _iCount)
        __debugbreak();
    }
    if(iMsgTick >= 1)
        this->m_pMsgStacks[iMsgTick][_iPlayerID]->SetExpectedSize(_iCount);
}

// address=[0x15cbe20]
// Decompiled from bool __thiscall CMsgStacks::IsSizeAlreadySet(CMsgStacks *this, int a2, unsigned __int8 a3)
bool CMsgStacks::IsSizeAlreadySet(unsigned int a2, unsigned char a3) {

    // [esp+0h] [ebp-14h]

    int ValidTick = CMsgStacks::GetValidTick();
    return a2 - ValidTick < 1 || this->m_pMsgStacks[a2 - ValidTick][a3]->GetExpectedSize() != -1;
}

// address=[0x15cbe90]
// Decompiled from char __thiscall CMsgStacks::IsMsgStackValid(CMsgStacks *this, unsigned int a2, unsigned int *a3)
bool CMsgStacks::IsMsgStackValid(unsigned int _iTick, unsigned int &a3) {

    // [esp+0h] [ebp-1Ch]
    // [esp+4h] [ebp-18h]
    // [esp+14h] [ebp-8h]
    // [esp+1Bh] [ebp-1h]

    int iMsgTick = _iTick - CMsgStacks::GetValidTick();
    unsigned int uTime = timeGetTime();
    char v8 = 1;
    for(signed int i = 0; i < this->m_iNumberPlayers; ++i) {
        if(!this->m_pMsgStacks[0][i]->GetAI() && !this->m_pMsgStacks[iMsgTick][i]->IsValid()) {
            v8 = 0;
            a3 |= 1 << i;
            if(71 * this->m_iDeltaTme + CMsgStacks::GetLastMsgTime(i) < uTime)
                a3 |= 1 << i;
        }
    }
    return v8;
}

// address=[0x15cbf80]
// Decompiled from void __thiscall CMsgStacks::SetStackAI(CMsgStacks *this, unsigned int a2, bool a3)
void CMsgStacks::SetStackAI(unsigned int _iId, bool _bAI) {
    BB_ASSERT(_iId < m_iNumberPlayers)
    for(int i = 0; i < this->m_iNumberMsgStacks; ++i)
        this->m_pMsgStacks[i][_iId]->SetAI(_bAI);
}

// address=[0x15cc000]
// Decompiled from char __thiscall CMsgStacks::IsInStack(CMsgStacks *this, struct CNet_Event *a2)
bool CMsgStacks::IsInStack(class CNet_Event &a2) {

    // [esp+4h] [ebp-10h]
    // [esp+8h] [ebp-Ch]
    // [esp+Ch] [ebp-8h]

    int iPlayer = a2.m_iOwner - 1;
    BB_ASSERT(iPlayer < m_iNumberPlayers)

    int iTick = a2.m_iTick;
    int iMsgTick = iTick - CMsgStacks::GetValidTick();
    if(iMsgTick < 0 || iMsgTick > this->m_iNumberMsgStacks)
        return 0;

    return this->m_pMsgStacks[iMsgTick][iPlayer]->IsInStack(a2.m_iMsgNr);
}

// address=[0x15cc0a0]
// Decompiled from void __thiscall CMsgStacks::ClearAndValidate(CMsgStacks *this, int a2)
void CMsgStacks::ClearAndValidate(int a2) {
    for(int i = 0; i < this->m_iNumberMsgStacks; ++i)
        this->m_pMsgStacks[i][a2]->ClearAndValidate();
}

// address=[0x15cc0f0]
// Decompiled from void __thiscall CMsgStacks::OnEndSaving(CMsgStacks *this, int a2, int a3)
void CMsgStacks::OnEndSaving(int a2, int a3) {
    for(int i = 0; i < a2; ++i) {
        DWORD Time = timeGetTime();
        CMsgStacks::SetLastMsgTime(i, a3 + Time, 1);
    }
}

// address=[0x15cc140]
// Decompiled from bool __thiscall CMsgStacks::InitStacks(CMsgStacks *this)
bool CMsgStacks::InitStacks(void) {
    for(int i = 0; i < this->m_iNumberMsgStacks; ++i) {
        for(int j = 0; j < this->m_iNumberPlayers; ++j) {
            this->m_pMsgStacks[i][j] = new CMsgStack();
        }
    }

    return m_pMsgStacks[0][0] != 0;
}
