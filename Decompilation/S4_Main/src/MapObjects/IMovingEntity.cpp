#include "IMovingEntity.h"
#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"
#include "CEntityTask.h"
#include "Pathing/CWalking.h"
#include "Pathing/CWalkingBase.h"

#include <iostream>

// Definitions for class IMovingEntity

// address=[0x130eb80]
// Decompiled from CEntityTask *__thiscall IMovingEntity::GetActualTask(IMovingEntity *this)
CEntityTask const &IMovingEntity::GetActualTask() const {
    return *this->m_cCurrentToDoItemIter;
}

// address=[0x130f500]
// Decompiled from struct CWalking *__thiscall IMovingEntity::Walking(IMovingEntity *this)
CWalking *IMovingEntity::Walking() {
    return this->m_pWalking.get();
}

// address=[0x1351ad0]
// Decompiled from int __thiscall IMovingEntity::Direction(IMovingEntity *this)
int IMovingEntity::Direction() const {
    return this->m_iDirection;
}

// address=[0x1351af0]
// Decompiled from int __thiscall IMovingEntity::Distance(IMovingEntity *this)
int IMovingEntity::Distance() const {
    return this->m_iDistance;
}

// address=[0x1460610]
// Decompiled from int __thiscall IMovingEntity::GetJobPart(IMovingEntity *this)
int IMovingEntity::GetJobPart() const {
    return this->m_iJobPart;
}

// address=[0x1470a80]
// Decompiled from bool __thiscall IMovingEntity::IsFree(IMovingEntity *this, int a2)
bool IMovingEntity::IsFree(int a2) {
    if(IsNotBlocked(a2))
        return IsNotOccupied(a2);

    return false;
}

// address=[0x14d86e0]
// Decompiled from char __thiscall IMovingEntity::IsUnEmployed(IMovingEntity *this)
bool IMovingEntity::IsUnEmployed() const {
    BB_REPORT("Nearly virtual function IMovingEntity::IsUnEmployed called");
    return false;
}

// address=[0x14e2fd0]
// Decompiled from int __thiscall IMovingEntity::IncToDoListIter(IMovingEntity *this)
void IMovingEntity::IncToDoListIter() {
    ++this->m_cCurrentToDoItemIter;
}

// address=[0x150b590]
// Decompiled from void __thiscall IMovingEntity::SetDisplacementCosts(IMovingEntity *this, char a2)
void IMovingEntity::SetDisplacementCosts(int a2) {
    this->m_iDisplacementCosts = a2;
}

// address=[0x1513b10]
// Decompiled from void __thiscall IMovingEntity::SetDirection(IMovingEntity *this, char a2)
void IMovingEntity::SetDirection(int a2) {
    this->m_iDirection = static_cast<char>(a2);
}

// address=[0x15590a0]
// Decompiled from IMovingEntity *__thiscall IMovingEntity::IMovingEntity(IMovingEntity *this, int id)
IMovingEntity::IMovingEntity(int id) : IAnimatedEntity(id), m_pWalking(), m_cCurrentToDoItemIter() {
    this->m_iDirection = 0;
    this->m_iDistance = 0;
    this->m_iDisplacementCosts = 0;
}

// address=[0x1559130]
// Decompiled from int __thiscall IMovingEntity::~IMovingEntity(IMovingEntity *this)
IMovingEntity::~IMovingEntity() = default;

// address=[0x1559170]
// Decompiled from void __thiscall IMovingEntity::WalkToXY(IMovingEntity *this, int a2, int a3)
void IMovingEntity::WalkToXY(int a2, int a3) {
    this->m_pWalking->Init(a2, a3);
}

// address=[0x15591b0]
// Decompiled from void __thiscall IMovingEntity::NewToDoList(IMovingEntity *this, DWORD _toDo, __int16 a3)
void IMovingEntity::NewToDoList(std::list<CEntityTask> *_toDo, int _iSize) {
    BB_ASSERT(_toDo != NULL)
    this->m_pToDoList = _toDo;
    this->m_cCurrentToDoItemIter = _toDo->begin();
    this->m_iToDoSize = _iSize;
}

// address=[0x1559260]
// Decompiled from int __thiscall IMovingEntity::ResetToDoList(IMovingEntity *this)
void IMovingEntity::ResetToDoList() {
    BB_ASSERT(m_pToDoList != NULL)

    if(this->m_pToDoList) {
        m_cCurrentToDoItemIter = m_pToDoList->begin();
    } else {
        m_cCurrentToDoItemIter = std::list<CEntityTask>::iterator();
    }
}

// address=[0x1559340]
// Decompiled from void __thiscall IMovingEntity::SetToDoList(IMovingEntity *this, DWORD a2)
void IMovingEntity::SetToDoList(std::list<CEntityTask> *_pToDo) {
    this->m_pToDoList = _pToDo;
    this->m_iToDoSize = -1;
    BB_ASSERT(m_pToDoList != nullptr)
    m_cCurrentToDoItemIter = m_pToDoList->begin();
}

// address=[0x1559400]
// Decompiled from bool __thiscall IMovingEntity::IsNotOccupied(IMovingEntity *this, int a2)
bool IMovingEntity::IsNotOccupied(int a2) {
    return this->m_pWalking->IsNotOccupied(a2);
}

// address=[0x1559430]
// Decompiled from bool __thiscall IMovingEntity::IsNotBlocked(IMovingEntity *this, int a2)
bool IMovingEntity::IsNotBlocked(int a2) {
    return this->m_pWalking->IsNotBlocked(a2);
}

// address=[0x1563870]
// Decompiled from bool __thiscall IMovingEntity::IsEndIter(IMovingEntity *this)
bool IMovingEntity::IsEndIter() {
    return this->m_cCurrentToDoItemIter == this->m_pToDoList->end();
}

// address=[0x1563980]
// Decompiled from void __thiscall IMovingEntity::SetDistance(IMovingEntity *this, BYTE a2)
void IMovingEntity::SetDistance(int a2) {
    this->m_iDistance = a2;
}

// address=[0x1568790]
// Decompiled from int __thiscall IMovingEntity::GetActualIter(IMovingEntity *this, int a2)
std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>> const IMovingEntity::GetActualIter() const {
    return m_cCurrentToDoItemIter; // TODO: probably best to turn into reference...
}

// address=[0x15d6230]
// Decompiled from int __thiscall IMovingEntity::DisplacementCosts(IMovingEntity *this)
int IMovingEntity::DisplacementCosts() const {
    return this->m_iDisplacementCosts;
}

// address=[0x14d8840]
// Decompiled from void __thiscall IMovingEntity::SetPositionAndDir(IMovingEntity *this, int a2, BYTE a3)
void IMovingEntity::SetPositionAndDir(int a2, int a3) {
    this->m_uPackedXY = a2;
    this->m_iDirection = a3;
}

// address=[0x1559460]
// Decompiled from IMovingEntity *__thiscall IMovingEntity::IMovingEntity(IMovingEntity *this, struct std::istream
// *_pStream)
IMovingEntity::IMovingEntity(std::istream &_rStream) : IAnimatedEntity(_rStream), m_pWalking(), m_cCurrentToDoItemIter() {
    unsigned int fileFormatVersion; // [esp+14h] [ebp-1Ch] BYREF

    this->m_pToDoList = 0;
    _rStream >> fileFormatVersion;

    if(fileFormatVersion != 1) {
        BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for IMovingEntity");
        throw CS4InvalidMapException();
    }
    _rStream >> this->m_iDirection;
    static_assert(sizeof(this->m_iDirection) == sizeof(signed char), "must match orginal size");
    _rStream >> this->m_iDistance;
    static_assert(sizeof(this->m_iDistance) == sizeof(unsigned char), "must match orginal size");
    _rStream >> this->m_iDisplacementCosts;
    static_assert(sizeof(this->m_iDisplacementCosts) == sizeof(unsigned char), "must match orginal size");
    _rStream >> this->unk_4c;
    static_assert(sizeof(this->unk_4c) == sizeof(int), "must match orginal size");

    bool bHasWalking = false;
    _rStream >> bHasWalking;
    if(bHasWalking) {
        m_pWalking = std::unique_ptr<CWalking>(CWalking::Create(_rStream));
    }
}

// address=[0x15595e0]
// Decompiled from void __thiscall IMovingEntity::Store(IMovingEntity *this, struct std::ostream *a1)
void IMovingEntity::Store(std::ostream &_rStream) {
    int v2;       // [esp+0h] [ebp-14h] BYREF
    CWalking *v3; // [esp+4h] [ebp-10h]
    BOOL v4;      // [esp+8h] [ebp-Ch]
    bool v6;      // [esp+13h] [ebp-1h] BYREF

    IAnimatedEntity::Store(_rStream);
    unsigned int fileFormatVersion = 1;
    _rStream << fileFormatVersion;

    _rStream << this->m_iDirection;
    _rStream << this->m_iDistance;
    _rStream << this->m_iDisplacementCosts;
    _rStream << this->unk_4c;

    bool bHasWalking = this->m_pWalking != nullptr;
    _rStream << bHasWalking;
    if(bHasWalking) {
        this->m_pWalking->Store(_rStream);
    }
}

// address=[0x15596c0]
// Decompiled from void __thiscall IMovingEntity::InitDistance(IMovingEntity *this)
void IMovingEntity::InitDistance() {
    this->m_iDistance = -1;
}

// address=[0x15596e0]
// Decompiled from void __thiscall IMovingEntity::DecDistance(IMovingEntity *this, unsigned int a2)
void IMovingEntity::DecDistance(unsigned int a2) {
    unsigned __int8 m_iDistance; // dl

    if(a2 >= this->m_iDistance) {
        this->m_iDistance = 0;
    } else {
        if(this->m_iDistance == 255)
            m_iDistance = this->m_iDistance + 1;
        else
            m_iDistance = this->m_iDistance;
        this->m_iDistance = m_iDistance - a2;
    }
}
