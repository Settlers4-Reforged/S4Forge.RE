#include "IAnimatedEntity.h"

#include <iostream>

#include "Logic/Events/CEntityEvent.h"
#include "CMapObjectMgr.h"
#include "CBB/CS4InvalidMapException.h"
#include "CBB/CBBSupport.h"
#include "Debug/IMessageTracer.h"

// Definitions for class IAnimatedEntity

// address=[0x1307150]
// Decompiled from int __thiscall IAnimatedEntity::Next(IAnimatedEntity *this)
int IAnimatedEntity::Next(void) const {
  return this->m_wNextEntity;
}


// address=[0x1351b10]
// Decompiled from int __thiscall IAnimatedEntity::Frame(IAnimatedEntity *this)
int IAnimatedEntity::Frame(void) const {
  return this->m_cFrame;
}


// address=[0x1351b30]
// Decompiled from int __thiscall IAnimatedEntity::GetLastLogicUpdateTick(IAnimatedEntity *this)
int IAnimatedEntity::GetLastLogicUpdateTick(void) const {
  return this->m_uLastLogicUpdate;
}


// address=[0x1439c70]
// Decompiled from int __thiscall IAnimatedEntity::Previous(IAnimatedEntity *this)
int IAnimatedEntity::Previous(void) const {
  return this->m_wPrevEntity;
}


// address=[0x1439e10]
// Decompiled from void __thiscall IAnimatedEntity::SetNext(IAnimatedEntity *this, int _id)
void IAnimatedEntity::SetNext(int _id) {
  BB_ASSERT(ID() != _id)
  this->m_wNextEntity = _id;
}


// address=[0x1439eb0]
// Decompiled from void __thiscall IAnimatedEntity::SetPrevious(IAnimatedEntity *this, WORD a2)
void IAnimatedEntity::SetPrevious(int a2) {
  this->m_wPrevEntity = a2;
}


// address=[0x14d87d0]
// Decompiled from void __thiscall IAnimatedEntity::SetLastUpdateTick(IAnimatedEntity *this, DWORD a2)
void IAnimatedEntity::SetLastUpdateTick(unsigned int a2) {
  this->m_uLastUpdateTick = a2;
}


// address=[0x14e31a0]
// Decompiled from int __thiscall IAnimatedEntity::RegisterForLogicUpdate(IAnimatedEntity *this, int _iDeltaTicks)
int IAnimatedEntity::RegisterForLogicUpdate(int _iDeltaTicks) {
  int v3 = g_pMapObjectMgr->RegisterForLogicUpdate(_iDeltaTicks, IEntity::ID());
  return IAnimatedEntity::SetLastLogicUpdate(v3);
}


// address=[0x14e31d0]
// Decompiled from void __thiscall IAnimatedEntity::UnRegisterFromLogicUpdate(IAnimatedEntity *this)
void IAnimatedEntity::UnRegisterFromLogicUpdate(void) {
  // eax
  // [esp-4h] [ebp-8h]

  int          iEntityId = IEntity::ID();
  unsigned int iLastLogicUpdateTick = IAnimatedEntity::GetLastLogicUpdateTick();
  g_pMapObjectMgr->UnRegisterFromLogicUpdate(iLastLogicUpdateTick, iEntityId);
  IAnimatedEntity::SetLastLogicUpdate(-1);
}


// address=[0x14e3210]
// Decompiled from void __thiscall IAnimatedEntity::SetEvent(IAnimatedEntity *this, const struct CEntityEvent *a1)
void IAnimatedEntity::SetEvent(CEntityEvent const &a1) {
  // eax
  // [esp-8h] [ebp-Ch]
  // [esp-4h] [ebp-8h]

  DWORD m_iType = a1.m_iType;
  DWORD m_iEvent = a1.m_iEvent;
  DWORD v2 = IEntity::EntityId();
  g_pMsgTracer->PushFormatedInts("SetEvent(): id %u, event %u, type %u", v2, m_iEvent, m_iType);
  if(!IEntity::FlagBits(EntityFlag_Registered))
    IAnimatedEntity::RegisterForLogicUpdate(1);
  this->m_iEventQueue.push_back(a1);
}


// address=[0x14e3270]
// Decompiled from void __thiscall IAnimatedEntity::ClearAllQueuedEvents(IAnimatedEntity *this)
void IAnimatedEntity::ClearAllQueuedEvents(void) {
  this->m_iEventQueue.clear();
}


// address=[0x14e3290]
// Decompiled from void __thiscall IAnimatedEntity::BoxSelection(IAnimatedEntity *this)
void IAnimatedEntity::BoxSelection(void) {
  if(IEntity::OwnerId() == g_cInputProcessor.m_iSelectionLocalPlayerId) {
    int v6 = g_cInputProcessor.StrictSelection();
    int mask = 0xFF0000;
    if(v6 == 1) {
      mask = 0xFFFF00;
    } else if(v6 == 2) {
      mask = 0xFFFFFF;
    }
    int EntitySelectionType = g_cInputProcessor.GetEntitySelectionType(this);
    int SelectionType = g_cInputProcessor.GetSelectionType();
    if(IEntity::FlagBits(EntityFlag_Selectable) || IEntity::ObjType() == 8) {
      bool v10 = 0;
      if(v6) {
        v10 = (mask & EntitySelectionType) == (mask & SelectionType);
      } else if((EntitySelectionType & 0xFF0000) <= (SelectionType & 0xFF0000)) {
        if((EntitySelectionType & 0xFF0000) == (SelectionType & 0xFF0000))
          v10 = (EntitySelectionType & 0xFF00) == (SelectionType & 0xFF00);
      } else {
        v10 = 1;
      }
      if(v10) {
        int xScreenOffset = -1;
        int yScreenOffset = -1;
        if(IGfxEngine::GetScreenOffsetsByMapIndices(IEntity::X(), IEntity::Y(), &xScreenOffset, &yScreenOffset)) {
          if(g_cInputProcessor.m_iSelectionXStart <= xScreenOffset
             && g_cInputProcessor.m_iSelectionXEnd >= xScreenOffset
             && g_cInputProcessor.m_iSelectionYStart <= yScreenOffset
             && g_cInputProcessor.m_iSelectionYEnd >= yScreenOffset) {
            if(!g_cInputProcessor.BoxSelectAllSettler())
              g_cInputProcessor.SetSelectionType(EntitySelectionType);
            g_cInputProcessor.NewCandidate(IEntity::EntityId());
          }
        }
      }
    }
  }
}


// address=[0x14e46c0]
// Decompiled from int __thiscall IAnimatedEntity::~IAnimatedEntity(IAnimatedEntity *this)
IAnimatedEntity::~IAnimatedEntity(void) = default;


// address=[0x14eb000]
// Decompiled from IAnimatedEntity *__thiscall IAnimatedEntity::IAnimatedEntity(IAnimatedEntity *this, int id)
IAnimatedEntity::IAnimatedEntity(int id) : IEntity(id), m_iEventQueue() {
  this->m_cFrame = 0;
  this->m_cAttackerPlayerId = 0;
  this->m_iJobPart = 0;
  this->m_wPrevEntity = 0;
  this->m_wNextEntity = 0;
  this->m_uLastUpdateTick = 0;
  this->m_uLastLogicUpdate = -1;
}


// address=[0x14eb2a0]
// Decompiled from int __thiscall IAnimatedEntity::AttackerPlayerId(IAnimatedEntity *this)
int IAnimatedEntity::AttackerPlayerId(void) const {
  return this->m_cAttackerPlayerId;
}


// address=[0x1501170]
// Decompiled from DWORD __thiscall IAnimatedEntity::LastUpdateTick(IAnimatedEntity *this)
unsigned int IAnimatedEntity::LastUpdateTick(void) const {
  return this->m_uLastUpdateTick;
}


// address=[0x1548370]
// Decompiled from int __thiscall IAnimatedEntity::JobPart(IAnimatedEntity *this)
int IAnimatedEntity::JobPart(void) const {
  return this->m_iJobPart;
}


// address=[0x15639c0]
// Decompiled from void __thiscall IAnimatedEntity::SetFrame(IAnimatedEntity *this, BYTE a2)
void IAnimatedEntity::SetFrame(int a2) {
  this->m_cFrame = a2;
}


// address=[0x15670a0]
// Decompiled from void __thiscall IAnimatedEntity::EventQueueEmpty(IAnimatedEntity *this)
bool IAnimatedEntity::EventQueueEmpty(void) const {
  std::vector<CEntityEvent>::empty(&this->m_iEventQueue);
}


// address=[0x1567140]
// Decompiled from void __thiscall IAnimatedEntity::SetJobPart(IAnimatedEntity *this, WORD a2)
void IAnimatedEntity::SetJobPart(int a2) {
  this->m_iJobPart = a2;
}


// address=[0x14e3460]
// Decompiled from IAnimatedEntity *__thiscall IAnimatedEntity::IAnimatedEntity(IAnimatedEntity *this, struct std::istream *a1)
IAnimatedEntity::IAnimatedEntity(std::istream &_rStream) : IEntity(_rStream), m_iEventQueue() {
  int fileVersion; // [esp+Ch] [ebp-1Ch] MAPDST BYREF
  _rStream >> fileVersion;
  if(fileVersion != 1) {
    BBSupportTracePrintF(3, "load output defect IAnimatedEntity::IAnimatedEntity");
    throw CS4InvalidMapException{};
  }
  _rStream >> this->m_cFrame;
  _rStream >> this->m_cAttackerPlayerId;
  _rStream >> this->m_iJobPart;
  _rStream >> this->m_wPrevEntity;
  _rStream >> this->m_wNextEntity;
  _rStream >> this->m_uLastUpdateTick;
  _rStream >> this->m_uLastLogicUpdate;
  unsigned int iQueueSize; // [esp+4h] [ebp-24h] BYREF
  _rStream >> iQueueSize;

  // Ensure loading compatibility from the binary
  static_assert(sizeof(m_cFrame) == sizeof(unsigned char));
  static_assert(sizeof(m_cAttackerPlayerId) == sizeof(unsigned char));
  static_assert(sizeof(m_iJobPart) == sizeof(unsigned short));
  static_assert(sizeof(m_wPrevEntity) == sizeof(unsigned short));
  static_assert(sizeof(m_wNextEntity) == sizeof(unsigned short));
  static_assert(sizeof(m_uLastUpdateTick) == sizeof(unsigned int));
  static_assert(sizeof(m_uLastLogicUpdate) == sizeof(int));
  static_assert(sizeof(iQueueSize) == sizeof(unsigned int));

  for(unsigned int i = 0; i < iQueueSize; ++i) {
    const CEntityEvent *v2 = CEntityEvent::Load(_rStream);
    this->m_iEventQueue.push_back(*v2);
  }
}


// address=[0x14e35f0]
// Decompiled from int __thiscall IAnimatedEntity::Store(IAnimatedEntity *this, struct std::ostream *a2)
void IAnimatedEntity::Store(std::ostream &_rStream) {
  IEntity::Store(_rStream);
  int iFileVersion = 1;
  _rStream << iFileVersion;
  _rStream << this->m_cFrame;
  _rStream << this->m_cAttackerPlayerId;
  _rStream << this->m_iJobPart;
  _rStream << this->m_wPrevEntity;
  _rStream << this->m_wNextEntity;
  _rStream << this->m_uLastUpdateTick;
  _rStream << this->m_uLastLogicUpdate;
  unsigned int iQueueSize = this->m_iEventQueue.size();
  _rStream << iQueueSize;

  static_assert(sizeof(iFileVersion) == sizeof(unsigned int));
  static_assert(sizeof(m_cFrame) == sizeof(unsigned char));
  static_assert(sizeof(m_cAttackerPlayerId) == sizeof(unsigned char));
  static_assert(sizeof(m_iJobPart) == sizeof(unsigned short));
  static_assert(sizeof(m_wPrevEntity) == sizeof(unsigned short));
  static_assert(sizeof(m_wNextEntity) == sizeof(unsigned short));
  static_assert(sizeof(m_uLastUpdateTick) == sizeof(unsigned int));
  static_assert(sizeof(m_uLastLogicUpdate) == sizeof(int));
  static_assert(sizeof(iQueueSize) == sizeof(unsigned int));

  for(auto &rEvent: this->m_iEventQueue) {
    rEvent.Store(_rStream);
  }
}


// address=[0x14e3780]
// Decompiled from bool __thiscall IAnimatedEntity::ProcessAllEvents(IAnimatedEntity *this)
bool IAnimatedEntity::ProcessAllEvents(void) {
  //NOTE: This was switched from a iterator with erase for every step to just iterating through it and then clearing
  //TODO: check for ConvertEventIntoGoal side effects that may have been lost with this change

  bool bFlagsSet = false;
  for(auto &rEvent: this->m_iEventQueue) {
    this->m_iFlags &= ~0x80000000;
    g_pMsgTracer->PushFormatedInts(
      "ConvertEventIntoGoal(): event %u, type %u, data %u, %u, %u",
      rEvent.m_iEvent,
      rEvent.m_iType,
      rEvent.m_iDataA,
      rEvent.m_iDataB,
      rEvent.m_iDataC);
    this->ConvertEventIntoGoal(&rEvent);

    bFlagsSet = this->m_iFlags >= 0;
  }
  this->m_iEventQueue.clear();

  return bFlagsSet;
}


// address=[0x14e4ae0]
// Decompiled from void __stdcall IAnimatedEntity::ConvertEventIntoGoal(int a1)
void IAnimatedEntity::ConvertEventIntoGoal(class CEntityEvent *a1) {
  ;
}


// address=[0x14e4b90]
// Decompiled from int __thiscall IAnimatedEntity::SetLastLogicUpdate(IAnimatedEntity *this, int a2)
int IAnimatedEntity::SetLastLogicUpdate(int a2) {
  this->m_uLastLogicUpdate = a2;
  return a2;
}


