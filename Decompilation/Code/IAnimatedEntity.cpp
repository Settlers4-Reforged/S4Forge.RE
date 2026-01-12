#include "IAnimatedEntity.h"

// Definitions for class IAnimatedEntity

// address=[0x1307150]
// Decompiled from int __thiscall IAnimatedEntity::Next(IAnimatedEntity *this)
int  IAnimatedEntity::Next(void)const {
  
  return *((unsigned __int16 *)this + 21);
}


// address=[0x1351b10]
// Decompiled from int __thiscall IAnimatedEntity::Frame(IAnimatedEntity *this)
int  IAnimatedEntity::Frame(void)const {
  
  return *((unsigned __int8 *)this + 36);
}


// address=[0x1351b30]
// Decompiled from int __thiscall IAnimatedEntity::GetLastLogicUpdateTick(CPaneContainer *this)
int  IAnimatedEntity::GetLastLogicUpdateTick(void)const {
  
  return *((_DWORD *)this + 12);
}


// address=[0x1439c70]
// Decompiled from int __thiscall IAnimatedEntity::Previous(unsigned __int16 *this)
int  IAnimatedEntity::Previous(void)const {
  
  return this[20];
}


// address=[0x1439e10]
// Decompiled from int __thiscall IAnimatedEntity::SetNext(_WORD *this, int a2)
void  IAnimatedEntity::SetNext(int) {
  
  int result; // eax

  if ( IEntity::ID() == a2
    && BBSupportDbgReport(
         2,
         (int)"D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\AnimatedEntity.h",
         93,
         (int)"ID() != _id") == 1 )
  {
    __debugbreak();
  }
  result = 0;
  this[21] = a2;
  return result;
}


// address=[0x1439eb0]
// Decompiled from IAnimatedEntity *__thiscall IAnimatedEntity::SetPrevious(IAnimatedEntity *this, __int16 a2)
void  IAnimatedEntity::SetPrevious(int) {
  
  IAnimatedEntity *result; // eax

  result = this;
  *((_WORD *)this + 20) = a2;
  return result;
}


// address=[0x14d87d0]
// Decompiled from void __thiscall IAnimatedEntity::SetLastUpdateTick(CMFCCaptionButton *this, int a2)
void  IAnimatedEntity::SetLastUpdateTick(unsigned int) {
  
  *((_DWORD *)this + 11) = a2;
}


// address=[0x14e31a0]
// Decompiled from int __stdcall IAnimatedEntity::RegisterForLogicUpdate(int a1)
int  IAnimatedEntity::RegisterForLogicUpdate(int) {
  
  int v1; // eax
  int v2; // eax

  v1 = IEntity::ID();
  v2 = CMapObjectMgr::RegisterForLogicUpdate(a1, v1);
  return IAnimatedEntity::SetLastLogicUpdate(v2);
}


// address=[0x14e31d0]
// Decompiled from int __thiscall IAnimatedEntity::UnRegisterFromLogicUpdate(IAnimatedEntity *this)
void  IAnimatedEntity::UnRegisterFromLogicUpdate(void) {
  
  int LastLogicUpdateTick; // eax
  int v3; // [esp-4h] [ebp-8h]

  v3 = IEntity::ID();
  LastLogicUpdateTick = IAnimatedEntity::GetLastLogicUpdateTick(this);
  CMapObjectMgr::UnRegisterFromLogicUpdate(g_pMapObjectMgr, LastLogicUpdateTick, v3);
  return IAnimatedEntity::SetLastLogicUpdate(-1);
}


// address=[0x14e3210]
// Decompiled from int __thiscall IAnimatedEntity::SetEvent(unsigned __int16 *this, int a2)
void  IAnimatedEntity::SetEvent(class CEntityEvent const &) {
  
  int v2; // eax
  int v4; // [esp-8h] [ebp-Ch]
  int v5; // [esp-4h] [ebp-8h]

  v5 = *(_DWORD *)(a2 + 8);
  v4 = *(_DWORD *)(a2 + 4);
  v2 = IEntity::EntityId(this);
  IMessageTracer::PushFormatedInts(g_pMsgTracer, "SetEvent(): id %u, event %u, type %u", v2, v4, v5);
  if ( !IEntity::FlagBits(this, Registered) )
    IAnimatedEntity::RegisterForLogicUpdate(1);
  return std::vector<CEntityEvent>::push_back(a2);
}


// address=[0x14e3270]
// Decompiled from void __thiscall IAnimatedEntity::ClearAllQueuedEvents(COleCmdUI *this)
void  IAnimatedEntity::ClearAllQueuedEvents(void) {
  
  std::vector<CEntityEvent>::clear((char *)this + 52);
}


// address=[0x14e3290]
// Decompiled from void __thiscall IAnimatedEntity::BoxSelection(struct IEntity *this)
void  IAnimatedEntity::BoxSelection(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // [esp-Ch] [ebp-48h]
  int ScreenOffsetsByMapIndices; // [esp+0h] [ebp-3Ch]
  int v5; // [esp+1Ch] [ebp-20h] BYREF
  int v6; // [esp+20h] [ebp-1Ch] BYREF
  int SelectionType; // [esp+24h] [ebp-18h]
  int v8; // [esp+28h] [ebp-14h]
  int EntitySelectionType; // [esp+2Ch] [ebp-10h]
  int v10; // [esp+30h] [ebp-Ch]
  struct IEntity *v11; // [esp+34h] [ebp-8h]
  bool v12; // [esp+3Bh] [ebp-1h]

  v11 = this;
  if ( IEntity::OwnerId((unsigned __int8 *)this) == dword_3F1F680 )
  {
    v8 = CInputProcessor::StrictSelection(&g_cInputProcessor);
    v10 = 16711680;
    if ( v8 == 1 )
    {
      v10 = 16776960;
    }
    else if ( v8 == 2 )
    {
      v10 = 0xFFFFFF;
    }
    EntitySelectionType = CInputProcessor::GetEntitySelectionType(v11);
    SelectionType = CInputProcessor::GetSelectionType(&g_cInputProcessor);
    if ( IEntity::FlagBits(v11, Selectable) || IEntity::ObjType((unsigned __int8 *)v11) == 8 )
    {
      v12 = 0;
      if ( v8 )
      {
        v12 = (v10 & EntitySelectionType) == (v10 & SelectionType);
      }
      else if ( (EntitySelectionType & 0xFF0000) <= (SelectionType & 0xFF0000) )
      {
        if ( (EntitySelectionType & 0xFF0000) == (SelectionType & 0xFF0000) )
          v12 = (EntitySelectionType & 0xFF00) == (SelectionType & 0xFF00);
      }
      else
      {
        v12 = 1;
      }
      if ( v12 )
      {
        v6 = -1;
        v5 = -1;
        v3 = IEntity::Y(v11);
        v1 = IEntity::X(v11);
        ScreenOffsetsByMapIndices = IGfxEngine::GetScreenOffsetsByMapIndices(v1, v3, &v6, &v5);
        if ( ScreenOffsetsByMapIndices )
        {
          if ( dword_3F1F684 <= v6 && dword_3F1F68C >= v6 && dword_3F1F688 <= v5 && dword_3F1F690 >= v5 )
          {
            if ( !(unsigned __int8)CInputProcessor::BoxSelectAllSettler(&g_cInputProcessor, ScreenOffsetsByMapIndices) )
              CInputProcessor::SetSelectionType((CInputProcessor *)&g_cInputProcessor, EntitySelectionType);
            v2 = IEntity::EntityId((unsigned __int16 *)v11);
            CInputProcessor::NewCandidate((CInputProcessor *)&g_cInputProcessor, v2);
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
// Decompiled from IAnimatedEntity *__thiscall IAnimatedEntity::IAnimatedEntity(IAnimatedEntity *this, int a2)
 IAnimatedEntity::IAnimatedEntity(int) {
  
  std::bad_function_call *v4; // [esp+0h] [ebp-4h]

  IEntity::IEntity((IEntity *)this, a2);
  *(_DWORD *)this = &IAnimatedEntity::_vftable_;
  *((_BYTE *)this + 36) = 0;
  *((_BYTE *)this + 37) = 0;
  *((_WORD *)this + 19) = 0;
  *((_WORD *)this + 20) = 0;
  *((_WORD *)this + 21) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = -1;
  std::vector<CEntityEvent>::vector<CEntityEvent>(this);
  return v4;
}


// address=[0x14eb2a0]
// Decompiled from int __thiscall IAnimatedEntity::AttackerPlayerId(unsigned __int8 *this)
int  IAnimatedEntity::AttackerPlayerId(void)const {
  
  return this[37];
}


// address=[0x1501170]
// Decompiled from int __thiscall IAnimatedEntity::LastUpdateTick(_DWORD *this)
unsigned int  IAnimatedEntity::LastUpdateTick(void)const {
  
  return this[11];
}


// address=[0x1548370]
// Decompiled from int __thiscall IAnimatedEntity::JobPart(unsigned __int16 *this)
int  IAnimatedEntity::JobPart(void)const {
  
  return this[19];
}


// address=[0x15639c0]
// Decompiled from _BYTE *__thiscall IAnimatedEntity::SetFrame(_BYTE *this, char a2)
void  IAnimatedEntity::SetFrame(int) {
  
  _BYTE *result; // eax

  result = this;
  this[36] = a2;
  return result;
}


// address=[0x15670a0]
// Decompiled from void __thiscall IAnimatedEntity::EventQueueEmpty(COleCmdUI *this)
bool  IAnimatedEntity::EventQueueEmpty(void)const {
  
  std::vector<CEntityEvent>::empty((char *)this + 52);
}


// address=[0x1567140]
// Decompiled from _WORD *__thiscall IAnimatedEntity::SetJobPart(_WORD *this, __int16 a2)
void  IAnimatedEntity::SetJobPart(int) {
  
  _WORD *result; // eax

  result = this;
  this[19] = a2;
  return result;
}


// address=[0x14e3460]
// Decompiled from struct IEntity *__thiscall IAnimatedEntity::IAnimatedEntity(struct IEntity *this, struct std::istream *a2)
 IAnimatedEntity::IAnimatedEntity(std::istream &) {
  
  int v2; // eax
  int v4; // [esp+0h] [ebp-28h]
  _DWORD v5[2]; // [esp+4h] [ebp-24h] BYREF
  int v6; // [esp+Ch] [ebp-1Ch] BYREF
  int pExceptionObject; // [esp+10h] [ebp-18h] BYREF
  unsigned int i; // [esp+14h] [ebp-14h]
  struct IEntity *v9; // [esp+18h] [ebp-10h]
  int v10; // [esp+24h] [ebp-4h]

  v9 = this;
  IEntity::IEntity(this, a2);
  v10 = 0;
  v9->CPersistence = (struct IEntityVtbl *)&IAnimatedEntity::_vftable_;
  std::vector<CEntityEvent>::vector<CEntityEvent>(v4);
  LOBYTE(v10) = 1;
  operator^<unsigned int>(a2, &v6);
  v5[1] = v6;
  if ( v6 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect IAnimatedEntity::IAnimatedEntity");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a2, &v9[9]);
  operator^<unsigned char>(a2, (char *)&v9[9].CPersistence + 1);
  operator^<unsigned short>(a2, (char *)&v9[9].CPersistence + 2);
  operator^<unsigned short>(a2, &v9[10]);
  operator^<unsigned short>(a2, (char *)&v9[10].CPersistence + 2);
  operator^<unsigned int>(a2, &v9[11]);
  operator^<int>((int)a2, (int)&v9[12]);
  operator^<unsigned int>(a2, v5);
  for ( i = 0; i < v5[0]; ++i )
  {
    v2 = CEntityEvent::Load(a2);
    std::vector<CEntityEvent>::push_back(v2);
  }
  v10 = -1;
  return v9;
}


// address=[0x14e35f0]
// Decompiled from int __thiscall IAnimatedEntity::Store(char *this, struct std::ostream *a2)
void  IAnimatedEntity::Store(std::ostream &) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-40h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-34h] BYREF
  std::_Iterator_base12 *v5; // [esp+1Ch] [ebp-28h]
  std::_Iterator_base12 *v6; // [esp+20h] [ebp-24h]
  int v7; // [esp+24h] [ebp-20h] BYREF
  int v8; // [esp+28h] [ebp-1Ch] BYREF
  int v9; // [esp+2Ch] [ebp-18h]
  char *v10; // [esp+30h] [ebp-14h]
  char v11; // [esp+37h] [ebp-Dh]
  int v12; // [esp+40h] [ebp-4h]

  v10 = this;
  IEntity::Store(this, (int)a2);
  v8 = 1;
  operator^<unsigned int>(a2, &v8);
  operator^<unsigned char>(a2, (int)(v10 + 36));
  operator^<unsigned char>(a2, (int)(v10 + 37));
  operator^<unsigned short>((int)a2, (__int16 *)v10 + 19);
  operator^<unsigned short>((int)a2, (__int16 *)v10 + 20);
  operator^<unsigned short>((int)a2, (__int16 *)v10 + 21);
  operator^<unsigned int>(a2, (int *)v10 + 11);
  operator^<int>((int)a2, (int *)v10 + 12);
  v7 = std::vector<CEntityEvent>::size(v10 + 52);
  operator^<unsigned int>(a2, &v7);
  std::vector<CEntityEvent>::begin(v4);
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
    v9 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityEvent>>>::operator->(v4);
    (*(void (__thiscall **)(int, struct std::ostream *))(*(_DWORD *)v9 + 4))(v9, a2);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityEvent>>>::operator++(v4);
  }
  v12 = -1;
  return std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityEvent>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityEvent>>>(v4);
}


// address=[0x14e3780]
// Decompiled from bool __thiscall IAnimatedEntity::ProcessAllEvents(_DWORD *this)
bool  IAnimatedEntity::ProcessAllEvents(void) {
  
  struct boost::exception_detail::clone_base *v1; // eax
  _DWORD v3[4]; // [esp-Ch] [ebp-6Ch] BYREF
  _DWORD v4[6]; // [esp+4h] [ebp-5Ch] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-44h] BYREF
  _BYTE v6[12]; // [esp+28h] [ebp-38h] BYREF
  int v7; // [esp+34h] [ebp-2Ch]
  int v8; // [esp+38h] [ebp-28h]
  _DWORD *v9; // [esp+3Ch] [ebp-24h]
  struct std::_Iterator_base12 *v10; // [esp+40h] [ebp-20h]
  struct std::_Iterator_base12 *v11; // [esp+44h] [ebp-1Ch]
  BOOL v12; // [esp+48h] [ebp-18h]
  bool v14; // [esp+53h] [ebp-Dh]
  int v15; // [esp+5Ch] [ebp-4h]

  v14 = 0;
  while ( !(unsigned __int8)std::vector<CEntityEvent>::empty(this + 13) )
  {
    v1 = (struct boost::exception_detail::clone_base *)std::vector<CEntityEvent>::front(v3[3], v4[0]);
    CEntityEvent::CEntityEvent(v1);
    v15 = 0;
    v11 = (struct std::_Iterator_base12 *)std::vector<CEntityEvent>::begin(v5);
    v10 = v11;
    LOBYTE(v15) = 1;
    v9 = v3;
    v8 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CEntityEvent>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CEntityEvent>>>(v11);
    v7 = std::vector<CEntityEvent>::erase(v6, v3[0], v3[1], v3[2]);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityEvent>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityEvent>>>(v6);
    LOBYTE(v15) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityEvent>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityEvent>>>(v5);
    this[5] &= ~0x80000000;
    IMessageTracer::PushFormatedInts(
      g_pMsgTracer,
      "ConvertEventIntoGoal(): event %u, type %u, data %u, %u, %u",
      v4[1],
      v4[2],
      v4[3],
      v4[4],
      v4[5]);
    (*(void (__thiscall **)(_DWORD *, _DWORD *))(*this + 108))(this, v4);
    v12 = this[5] >= 0;
    v14 = v12;
    v15 = -1;
    CEntityEvent::~CEntityEvent(v4);
  }
  return v14;
}


// address=[0x14e4ae0]
// Decompiled from void __stdcall IAnimatedEntity::ConvertEventIntoGoal(int a1)
void  IAnimatedEntity::ConvertEventIntoGoal(class CEntityEvent *) {
  
  ;
}


// address=[0x14e4b90]
// Decompiled from int __thiscall IAnimatedEntity::SetLastLogicUpdate(_DWORD *this, int a2)
int  IAnimatedEntity::SetLastLogicUpdate(int) {
  
  this[12] = a2;
  return a2;
}


