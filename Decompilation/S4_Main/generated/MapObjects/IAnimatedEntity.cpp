#if FALSE
#include "IAnimatedEntity.h"

// Definitions for class IAnimatedEntity

// address=[0x1307150]
// Decompiled from int __thiscall IAnimatedEntity::Next(IAnimatedEntity *this)
int  IAnimatedEntity::Next(void)const {
  
  return this->m_wNextEntity;
}


// address=[0x1351b10]
// Decompiled from int __thiscall IAnimatedEntity::Frame(IAnimatedEntity *this)
int  IAnimatedEntity::Frame(void)const {
  
  return this->m_cFrame;
}


// address=[0x1351b30]
// Decompiled from int __thiscall IAnimatedEntity::GetLastLogicUpdateTick(IAnimatedEntity *this)
int  IAnimatedEntity::GetLastLogicUpdateTick(void)const {
  
  return this->m_uLastLogicUpdate;
}


// address=[0x1439c70]
// Decompiled from int __thiscall IAnimatedEntity::Previous(IAnimatedEntity *this)
int  IAnimatedEntity::Previous(void)const {
  
  return this->m_wPrevEntity;
}


// address=[0x1439e10]
// Decompiled from void __thiscall IAnimatedEntity::SetNext(IAnimatedEntity *this, int _id)
void  IAnimatedEntity::SetNext(int _id) {
  
  if ( IEntity::ID(this) == _id
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\AnimatedEntity.h",
         93,
         "ID() != _id") == 1 )
  {
    __debugbreak();
  }
  this->m_wNextEntity = _id;
}


// address=[0x1439eb0]
// Decompiled from void __thiscall IAnimatedEntity::SetPrevious(IAnimatedEntity *this, WORD a2)
void  IAnimatedEntity::SetPrevious(int a2) {
  
  this->m_wPrevEntity = a2;
}


// address=[0x14d87d0]
// Decompiled from void __thiscall IAnimatedEntity::SetLastUpdateTick(IAnimatedEntity *this, DWORD a2)
void  IAnimatedEntity::SetLastUpdateTick(unsigned int a2) {
  
  this->m_uLastUpdateTick = a2;
}


// address=[0x14e31a0]
// Decompiled from int __thiscall IAnimatedEntity::RegisterForLogicUpdate(IAnimatedEntity *this, int _iDeltaTicks)
int  IAnimatedEntity::RegisterForLogicUpdate(int _iDeltaTicks) {
  
  int id; // eax
  int v3; // eax

  id = IEntity::ID(this);
  v3 = CMapObjectMgr::RegisterForLogicUpdate(g_pMapObjectMgr, _iDeltaTicks, id);
  return IAnimatedEntity::SetLastLogicUpdate(v3);
}


// address=[0x14e31d0]
// Decompiled from void __thiscall IAnimatedEntity::UnRegisterFromLogicUpdate(IAnimatedEntity *this)
void  IAnimatedEntity::UnRegisterFromLogicUpdate(void) {
  
  unsigned int iLastLogicUpdateTick; // eax
  int iEntityId; // [esp-4h] [ebp-8h]

  iEntityId = IEntity::ID(this);
  iLastLogicUpdateTick = IAnimatedEntity::GetLastLogicUpdateTick(this);
  CMapObjectMgr::UnRegisterFromLogicUpdate(g_pMapObjectMgr, iLastLogicUpdateTick, iEntityId);
  IAnimatedEntity::SetLastLogicUpdate(-1);
}


// address=[0x14e3210]
// Decompiled from void __thiscall IAnimatedEntity::SetEvent(IAnimatedEntity *this, const struct CEntityEvent *a1)
void  IAnimatedEntity::SetEvent(class CEntityEvent const & a1) {
  
  DWORD v2; // eax
  DWORD m_iEvent; // [esp-8h] [ebp-Ch]
  DWORD m_iType; // [esp-4h] [ebp-8h]

  m_iType = a1->m_iType;
  m_iEvent = a1->m_iEvent;
  v2 = IEntity::EntityId(this);
  IMessageTracer::PushFormatedInts(g_pMsgTracer, "SetEvent(): id %u, event %u, type %u", v2, m_iEvent, m_iType);
  if ( !IEntity::FlagBits(this, EntityFlag_Registered) )
    IAnimatedEntity::RegisterForLogicUpdate(this, 1);
  std::vector<CEntityEvent>::push_back(&this->m_iEventQueue, a1);
}


// address=[0x14e3270]
// Decompiled from void __thiscall IAnimatedEntity::ClearAllQueuedEvents(IAnimatedEntity *this)
void  IAnimatedEntity::ClearAllQueuedEvents(void) {
  
  std::vector<CEntityEvent>::clear(&this->m_iEventQueue);
}


// address=[0x14e3290]
// Decompiled from void __thiscall IAnimatedEntity::BoxSelection(IAnimatedEntity *this)
void  IAnimatedEntity::BoxSelection(void) {
  
  __int16 v1; // ax
  __int64 packedXY; // [esp-10h] [ebp-4Ch]
  int yScreenOffset; // [esp+1Ch] [ebp-20h] BYREF
  int xScreenOffset; // [esp+20h] [ebp-1Ch] BYREF
  int SelectionType; // [esp+24h] [ebp-18h]
  int v6; // [esp+28h] [ebp-14h]
  int EntitySelectionType; // [esp+2Ch] [ebp-10h]
  int mask; // [esp+30h] [ebp-Ch]
  bool v10; // [esp+3Bh] [ebp-1h]

  if ( IEntity::OwnerId(this) == g_cInputProcessor.m_iSelectionLocalPlayerId )
  {
    v6 = CInputProcessor::StrictSelection(&g_cInputProcessor);
    mask = 0xFF0000;
    if ( v6 == 1 )
    {
      mask = 0xFFFF00;
    }
    else if ( v6 == 2 )
    {
      mask = 0xFFFFFF;
    }
    EntitySelectionType = CInputProcessor::GetEntitySelectionType(this);
    SelectionType = CInputProcessor::GetSelectionType(&g_cInputProcessor);
    if ( IEntity::FlagBits(this, EntityFlag_Selectable) || IEntity::ObjType(this) == 8 )
    {
      v10 = 0;
      if ( v6 )
      {
        v10 = (mask & EntitySelectionType) == (mask & SelectionType);
      }
      else if ( (EntitySelectionType & 0xFF0000) <= (SelectionType & 0xFF0000) )
      {
        if ( (EntitySelectionType & 0xFF0000) == (SelectionType & 0xFF0000) )
          v10 = (EntitySelectionType & 0xFF00) == (SelectionType & 0xFF00);
      }
      else
      {
        v10 = 1;
      }
      if ( v10 )
      {
        xScreenOffset = -1;
        yScreenOffset = -1;
        HIDWORD(packedXY) = IEntity::Y(this);
        LODWORD(packedXY) = IEntity::X(this);
        if ( IGfxEngine::GetScreenOffsetsByMapIndices(packedXY, &xScreenOffset, &yScreenOffset) )
        {
          if ( (int)g_cInputProcessor.m_iSelectionXStart <= xScreenOffset
            && (int)g_cInputProcessor.m_iSelectionXEnd >= xScreenOffset
            && (int)g_cInputProcessor.m_iSelectionYStart <= yScreenOffset
            && (int)g_cInputProcessor.m_iSelectionYEnd >= yScreenOffset )
          {
            if ( !CInputProcessor::BoxSelectAllSettler(&g_cInputProcessor) )
              CInputProcessor::SetSelectionType(&g_cInputProcessor, EntitySelectionType);
            v1 = IEntity::EntityId(this);
            CInputProcessor::NewCandidate(&g_cInputProcessor, v1);
          }
        }
      }
    }
  }
}


// address=[0x14e46c0]
// Decompiled from int __thiscall IAnimatedEntity::~IAnimatedEntity(IAnimatedEntity *this)
 IAnimatedEntity::~IAnimatedEntity(void) {
  
  _DWORD *v2; // [esp+0h] [ebp-4h]

  *(_DWORD *)this = &IAnimatedEntity::_vftable_;
  std::vector<CEntityEvent>::~vector<CEntityEvent>(this);
  return IEntity::~IEntity(v2);
}


// address=[0x14eb000]
// Decompiled from IAnimatedEntity *__thiscall IAnimatedEntity::IAnimatedEntity(IAnimatedEntity *this, int id)
 IAnimatedEntity::IAnimatedEntity(int id) {
  
  IEntity::IEntity(this, id);
  this->__vftable = (IAnimatedEntity_vtbl *)&IAnimatedEntity::_vftable_;
  this->m_cFrame = 0;
  this->m_cAttackerPlayerId = 0;
  this->m_wJobPart = 0;
  this->m_wPrevEntity = 0;
  this->m_wNextEntity = 0;
  this->m_uLastUpdateTick = 0;
  this->m_uLastLogicUpdate = -1;
  std::vector<CEntityEvent>::vector<CEntityEvent>(&this->m_iEventQueue);
  return this;
}


// address=[0x14eb2a0]
// Decompiled from int __thiscall IAnimatedEntity::AttackerPlayerId(IAnimatedEntity *this)
int  IAnimatedEntity::AttackerPlayerId(void)const {
  
  return this->m_cAttackerPlayerId;
}


// address=[0x1501170]
// Decompiled from DWORD __thiscall IAnimatedEntity::LastUpdateTick(IAnimatedEntity *this)
unsigned int  IAnimatedEntity::LastUpdateTick(void)const {
  
  return this->m_uLastUpdateTick;
}


// address=[0x1548370]
// Decompiled from int __thiscall IAnimatedEntity::JobPart(IAnimatedEntity *this)
int  IAnimatedEntity::JobPart(void)const {
  
  return this->m_wJobPart;
}


// address=[0x15639c0]
// Decompiled from void __thiscall IAnimatedEntity::SetFrame(IAnimatedEntity *this, BYTE a2)
void  IAnimatedEntity::SetFrame(int a2) {
  
  this->m_cFrame = a2;
}


// address=[0x15670a0]
// Decompiled from void __thiscall IAnimatedEntity::EventQueueEmpty(IAnimatedEntity *this)
bool  IAnimatedEntity::EventQueueEmpty(void)const {
  
  std::vector<CEntityEvent>::empty(&this->m_iEventQueue);
}


// address=[0x1567140]
// Decompiled from void __thiscall IAnimatedEntity::SetJobPart(IAnimatedEntity *this, WORD a2)
void  IAnimatedEntity::SetJobPart(int a2) {
  
  this->m_wJobPart = a2;
}


// address=[0x14e3460]
// Decompiled from IAnimatedEntity *__thiscall IAnimatedEntity::IAnimatedEntity(IAnimatedEntity *this, struct std::istream *a1)
 IAnimatedEntity::IAnimatedEntity(std::istream & a1) {
  
  const struct CEntityEvent *v2; // eax
  unsigned int iQueueSize; // [esp+4h] [ebp-24h] BYREF
  int fileVersion; // [esp+Ch] [ebp-1Ch] MAPDST BYREF
  int pExceptionObject; // [esp+10h] [ebp-18h] BYREF
  unsigned int i; // [esp+14h] [ebp-14h]
  int ExceptionBlock; // [esp+24h] [ebp-4h]

  IEntity::IEntity(this, a1);
  ExceptionBlock = 0;
  this->__vftable = (IAnimatedEntity_vtbl *)&IAnimatedEntity::_vftable_;
  std::vector<CEntityEvent>::vector<CEntityEvent>(&this->m_iEventQueue);
  LOBYTE(ExceptionBlock) = 1;
  operator^<unsigned int>(a1, &fileVersion);
  if ( fileVersion != 1 )
  {
    BBSupportTracePrintF(3, "load output defect IAnimatedEntity::IAnimatedEntity");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a1, &this->m_cFrame);
  operator^<unsigned char>(a1, &this->m_cAttackerPlayerId);
  operator^<unsigned short>(a1, &this->m_wJobPart);
  operator^<unsigned short>(a1, &this->m_wPrevEntity);
  operator^<unsigned short>(a1, &this->m_wNextEntity);
  operator^<unsigned int>(a1, &this->m_uLastUpdateTick);
  operator^<int>(a1, &this->m_uLastLogicUpdate);
  operator^<unsigned int>(a1, &iQueueSize);
  for ( i = 0; i < iQueueSize; ++i )
  {
    v2 = (const struct CEntityEvent *)CEntityEvent::Load(a1);
    std::vector<CEntityEvent>::push_back(&this->m_iEventQueue, v2);
  }
  ExceptionBlock = -1;
  return this;
}


// address=[0x14e35f0]
// Decompiled from int __thiscall IAnimatedEntity::Store(IAnimatedEntity *this, struct std::ostream *a2)
void  IAnimatedEntity::Store(std::ostream & a2) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-40h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-34h] BYREF
  std::_Iterator_base12 *v5; // [esp+1Ch] [ebp-28h]
  std::_Iterator_base12 *v6; // [esp+20h] [ebp-24h]
  int iQueueSize; // [esp+24h] [ebp-20h] BYREF
  int v8; // [esp+28h] [ebp-1Ch] BYREF
  CEntityEvent *v9; // [esp+2Ch] [ebp-18h]
  char v11; // [esp+37h] [ebp-Dh]
  int v12; // [esp+40h] [ebp-4h]

  IEntity::Store((char *)this, (int)a2);
  v8 = 1;
  operator^<unsigned int>(a2, &v8);
  operator^<unsigned char>(a2, &this->m_cFrame);
  operator^<unsigned char>(a2, &this->m_cAttackerPlayerId);
  operator^<unsigned short>(a2, &this->m_wJobPart);
  operator^<unsigned short>(a2, &this->m_wPrevEntity);
  operator^<unsigned short>(a2, &this->m_wNextEntity);
  operator^<unsigned int>(a2, (int *)&this->m_uLastUpdateTick);
  operator^<int>(a2, &this->m_uLastLogicUpdate);
  iQueueSize = std::vector<CEntityEvent>::size(&this->m_iEventQueue);
  operator^<unsigned int>(a2, &iQueueSize);
  std::vector<CEntityEvent>::begin(&this->m_iEventQueue, (int)v4);
  v12 = 0;
  while ( 1 )
  {
    v6 = (std::_Iterator_base12 *)std::vector<CEntityEvent>::end(v3);
    v5 = v6;
    LOBYTE(v12) = 1;
    v11 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CEntityEvent>>>::operator!=(v6);
    LOBYTE(v12) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityEvent>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityEvent>>>(v3);
    if ( !v11 )
      break;
    v9 = (CEntityEvent *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityEvent>>>::operator->(v4);
    v9->Store(v9, a2);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityEvent>>>::operator++(v4);
  }
  v12 = -1;
  return std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityEvent>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityEvent>>>(v4);
}


// address=[0x14e3780]
// Decompiled from bool __thiscall IAnimatedEntity::ProcessAllEvents(IAnimatedEntity *this)
bool  IAnimatedEntity::ProcessAllEvents(void) {
  
  CEntityEvent *v1; // eax
  int v3[4]; // [esp-Ch] [ebp-6Ch] BYREF
  CEntityEvent v4; // [esp+4h] [ebp-5Ch] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-44h] BYREF
  _BYTE v6[12]; // [esp+28h] [ebp-38h] BYREF
  int v7; // [esp+34h] [ebp-2Ch]
  int v8; // [esp+38h] [ebp-28h]
  int *v9; // [esp+3Ch] [ebp-24h]
  struct std::_Iterator_base12 *v11; // [esp+44h] [ebp-1Ch] MAPDST
  BOOL v12; // [esp+48h] [ebp-18h]
  bool v14; // [esp+53h] [ebp-Dh]
  int v15; // [esp+5Ch] [ebp-4h]

  v14 = 0;
  while ( !(unsigned __int8)std::vector<CEntityEvent>::empty(&this->m_iEventQueue) )
  {
    v1 = std::vector<CEntityEvent>::front(&this->m_iEventQueue);
    CEntityEvent::CEntityEvent((struct boost::exception_detail::clone_base *)v1);
    v15 = 0;
    v11 = (struct std::_Iterator_base12 *)std::vector<CEntityEvent>::begin(&this->m_iEventQueue, (int)v5);
    LOBYTE(v15) = 1;
    v9 = v3;
    v8 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CEntityEvent>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CEntityEvent>>>(v11);
    v7 = std::vector<CEntityEvent>::erase(&this->m_iEventQueue, (int)v6, v3[0], v3[1], v3[2]);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityEvent>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityEvent>>>(v6);
    LOBYTE(v15) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityEvent>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityEvent>>>(v5);
    this->m_iFlags &= ~0x80000000;
    IMessageTracer::PushFormatedInts(
      g_pMsgTracer,
      "ConvertEventIntoGoal(): event %u, type %u, data %u, %u, %u",
      v4.m_iEvent,
      v4.m_iType,
      v4.m_iDataA,
      v4.m_iDataB,
      v4.m_iDataC);
    this->ConvertEventIntoGoal(this, &v4);
    v12 = this->m_iFlags >= 0;
    v14 = v12;
    v15 = -1;
    CEntityEvent::~CEntityEvent(&v4);
  }
  return v14;
}


// address=[0x14e4ae0]
// Decompiled from void __stdcall IAnimatedEntity::ConvertEventIntoGoal(int a1)
void  IAnimatedEntity::ConvertEventIntoGoal(class CEntityEvent * a1) {
  
  ;
}


// address=[0x14e4b90]
// Decompiled from int __thiscall IAnimatedEntity::SetLastLogicUpdate(IAnimatedEntity *this, int a2)
int  IAnimatedEntity::SetLastLogicUpdate(int a2) {
  
  this->m_uLastLogicUpdate = a2;
  return a2;
}


#endif // Already implemented
