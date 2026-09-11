#include "CAnimal.h"

// Definitions for class CAnimal

// address=[0x14d60e0]
// Decompiled from _DWORD *__thiscall CAnimal::CAnimal(_DWORD *this, int a2)
 CAnimal::CAnimal(std::istream & a2) {
  
  int pExceptionObject; // [esp+4h] [ebp-1Ch] BYREF
  unsigned int v4; // [esp+8h] [ebp-18h] BYREF
  _DWORD *v5; // [esp+Ch] [ebp-14h]
  __int16 v6; // [esp+10h] [ebp-10h] BYREF
  int v7; // [esp+1Ch] [ebp-4h]

  v5 = this;
  IMovingEntity::IMovingEntity(this, a2);
  v7 = 0;
  *v5 = &CAnimal::_vftable_;
  std::list<CEntityTask>::list<CEntityTask>(v5 + 26);
  LOBYTE(v7) = 1;
  operator^<unsigned int>(a2, &v4);
  if ( v4 != 0 )
  {
    operator^<unsigned char>(a2, (unsigned __int8 *)v5 + 120);
    operator^<unsigned char>(a2, (unsigned __int8 *)v5 + 121);
    operator^<unsigned char>(a2, (unsigned __int8 *)v5 + 122);
    operator^<unsigned char>(a2, (unsigned __int8 *)v5 + 123);
    operator^<unsigned char>(a2, (unsigned __int8 *)v5 + 124);
    operator^<unsigned char>(a2, (unsigned __int8 *)v5 + 125);
    operator^<int>((struct std::istream *)a2, v5 + 34);
    operator^<int>((struct std::istream *)a2, v5 + 32);
  }
  if ( v4 < 2 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CAnimal");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<short>(a2, (int)&v6);
  v5[25] = v6;
  v7 = -1;
  return v5;
}


// address=[0x14d6260]
// Decompiled from void __thiscall CAnimal::Store(CAnimal *this, struct std::ostream *a1)
void  CAnimal::Store(std::ostream & a1) {
  
  int v2; // [esp+0h] [ebp-Ch] BYREF
  __int16 unk_64; // [esp+Ah] [ebp-2h] BYREF

  IMovingEntity::Store((CSettler *)this, a1);
  v2 = 2;
  operator^<unsigned int>(a1, (unsigned int *)&v2);
  operator^<unsigned char>(a1, &this->unk_78);
  operator^<unsigned char>(a1, &this->unk_79);
  operator^<unsigned char>(a1, &this->unk_7a);
  operator^<unsigned char>(a1, &this->unk_7b);
  operator^<unsigned char>(a1, &this->unk_7c);
  operator^<unsigned char>(a1, &this->unk_7d);
  operator^<int>(a1, &this->unk_88);
  operator^<int>(a1, &this->unk_80);
  unk_64 = this->unk_64;
  operator^<short>(a1, &unk_64);
}


// address=[0x14d6350]
// Decompiled from void __thiscall CAnimal::LogicUpdate(CAnimal *this)
void  CAnimal::LogicUpdate(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+0h] [ebp-Ch]
  int v5; // [esp+4h] [ebp-8h]

  if ( !IAnimatedEntity::ProcessAllEvents(this) )
  {
    if ( *(_DWORD *)&this->unk_64 == 5 )
    {
      if ( IEntity::FlagBits(this, (EntityFlag)&s_iMsgTracer2.m_aMessages[15456]) == 0 )
      {
        this->unk_80 += 15;
        if ( this->unk_80 < 450 )
        {
          ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(15);
        }
        else
        {
          v1 = IEntity::EntityId(this);
          CAnimalMgr::DeleteAnimal((CAnimalMgr *)&g_cAnimalMgr, v1);
        }
      }
    }
    else
    {
      v5 = ((_DWORD (__cdecl *)(_DWORD))std::auto_ptr<CWalking>::operator->)(v3);
      v2 = IEntity::PackedXY(this);
      v4 = (*(int (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v5 + 16))(v5, v2, 0);
      if ( (v4 & 8) != 0 )
      {
        ((void (__thiscall *)(CAnimal *))this->j___purecall)(this);
      }
      else
      {
        CAnimal::TakeWalkJobAndWalkDir(this, v4);
      }
    }
  }
}


// address=[0x14d6420]
// Decompiled from SGfxObjectInfo *__thiscall CAnimal::GetGfxInfos(struct CAnimal *this)
struct SGfxObjectInfo *  CAnimal::GetGfxInfos(void) {
  
  this->Update();
  CGfxManager::GetAnimalGfxInfo(g_pGfxManager, &IEntity::m_sGfxInfo, this->m_iJobPart, this->m_iDirection, this->m_iFrame);
  IEntity::m_sGfxInfo.m_iDirection = this->m_iDirection;
  IEntity::m_sGfxInfo.m_iDistance = this->m_iDistance;
  IEntity::m_sGfxInfo.m_uObjType = this->m_uObjType;
  IEntity::m_sGfxInfo.m_bIsVisible = IEntity::IsVisible(this);
  return &IEntity::m_sGfxInfo;
}


// address=[0x14d64a0]
// Decompiled from int __thiscall CAnimal::AddTask(CAnimal *this, struct CEntityTask *a2)
void  CAnimal::AddTask(class CEntityTask & a2) {
  
  return std::list<CEntityTask>::push_back((int)a2);
}


// address=[0x14d8660]
// Decompiled from void __thiscall CAnimal::Decrease(CAnimal *this, int a2)
void  CAnimal::Decrease(int a2) {
  
  ;
}


// address=[0x14d8890]
// Decompiled from void __thiscall CAnimal::Take(CAnimal *this, int a2)
void  CAnimal::Take(int a2) {
  
  ;
}


// address=[0x14d64c0]
// Decompiled from CAnimal *__thiscall CAnimal::CAnimal(CAnimal *this, int a2, int a3, unsigned int a4, int a5)
 CAnimal::CAnimal(int a2, int a3, int a4, int a5) {
  
  IMovingEntity::IMovingEntity(this, a5);
  this->__vftable = (CAnimal_vtbl *)&CAnimal::_vftable_;
  std::list<CEntityTask>::list<CEntityTask>(&this->unk_66[2]);
  IEntity::SetPosition(this, a2, a3);
  this->m_uObjType = Animal;
  this->m_iType = a4;
  *(_DWORD *)&this->unk_64 = 0;
  this->m_iDistance = 0;
  this->unk_79 = 10;
  this->unk_80 = 0;
  this->unk_84 = -1;
  this->m_iJobPart = CGfxManager::GetAnimalFirstJob(g_pGfxManager, a4);
  return this;
}


// address=[0x14d65a0]
// Decompiled from int __thiscall CAnimal::Delete(IAnimatedEntity *this)
void  CAnimal::Delete(void) {
  
  int v1; // eax
  int v2; // esi
  int v3; // eax
  int result; // eax
  int LastLogicUpdateTick; // eax
  int v6; // [esp-4h] [ebp-Ch]

  CWarMap::RemoveEntity(this);
  if ( IEntity::FlagBits(this, ENTITY_FLAG_ON_BOARD) == 0 )
  {
    IEntity::SetFlagBits(this, ENTITY_FLAG_ON_BOARD);
    v1 = ((int (__stdcall *)())IEntity::WorldIdx)();
    v2 = CWorldManager::MapObjectId(v1);
    if ( v2 != IEntity::EntityId(this) && BBSupportDbgReport(2, "MapObjects\\Animal\\Animal.cpp", 700, "g_cWorld.MapObjectId( WorldIdx() ) == EntityId()") == 1 )
    {
      __debugbreak();
    }
    v3 = ((int (__stdcall *)())IEntity::WorldIdx)();
    CWorldManager::SetMapObjectId(v3, 0);
  }
  result = IEntity::FlagBits(this, ENTITY_FLAG_Registered);
  if ( result != 0 )
  {
    v6 = IEntity::EntityId(this);
    LastLogicUpdateTick = IAnimatedEntity::GetLastLogicUpdateTick(this);
    CMapObjectMgr::UnRegisterFromLogicUpdate(g_pMapObjectMgr, LastLogicUpdateTick, v6);
    result = IEntity::FlagBits(this, ENTITY_FLAG_Registered);
    if ( result != 0 )
    {
      result = BBSupportDbgReport(2, "MapObjects\\Animal\\Animal.cpp", 710, "FlagBits(ENTITY_FLAG_REGISTERED) == 0");
      if ( result == 1 )
      {
        __debugbreak();
      }
    }
  }
  return result;
}


// address=[0x14d6690]
// Decompiled from int __thiscall CAnimal::Update(CAnimal *this)
void  CAnimal::Update(void) {
  
  int result; // eax
  int TickCounter; // eax
  int v3; // edx
  int v4; // eax
  int v5; // eax
  int v6; // [esp-8h] [ebp-18h]
  int v7; // [esp-4h] [ebp-14h]
  int v8; // [esp+4h] [ebp-Ch]

  this->unk_7d = CStateGame::GetTickCounter(g_pGame) - LOBYTE(this->m_uLastUpdateTick);
  result = (int)this;
  if ( this->unk_7d != 0 && *(_DWORD *)&this->unk_64 != 5 )
  {
    TickCounter = CStateGame::GetTickCounter(g_pGame);
    IAnimatedEntity::SetLastUpdateTick(this, TickCounter);
    result = this->unk_7a - 6;
    switch ( this->unk_7a )
    {
      case 6u:
        result = (int)this;
        if ( (this->unk_78 & 8) != 0 )
        {
          this->m_iFrame = 0;
        }
        else
        {
          this->m_iFrame = (this->unk_7d + this->m_iFrame) % this->unk_7c;
          if ( this->unk_79 != 0 )
          {
            v8 = this->unk_79;
          }
          else
          {
            v8 = 1;
          }
          result = (int)((IMovingEntity *(__thiscall *)(IMovingEntity *, unsigned int))IMovingEntity::DecDistance)(this, (this->unk_7d << 8) / v8);
        }
        break;
      case 0x10u:
      case 0x1Bu:
        result = (int)this;
        this->m_iFrame = (this->unk_7d + this->m_iFrame) % this->unk_7c;
        if ( *(_DWORD *)(*(_DWORD *)&this->unk_74 + 32) != 0 )
        {
          if ( *(_BYTE *)(*(_DWORD *)&this->unk_74 + 36) == 100 || (v3 = j__rand() % 100 + 1, result = *(unsigned __int8 *)(*(_DWORD *)&this->unk_74 + 36), v3 <= result) )
          {
            result = CSoundManager::IsPlaying(g_pSoundManager, this->unk_84);
            if ( (_BYTE)result == 0 )
            {
              v7 = IEntity::Y(this);
              v4 = IEntity::X(this);
              result = ((int (__thiscall *)(CFogging *, int, int))g_pFogging->IsPositionVisible)(g_pFogging, v4, v7);
              if ( (_BYTE)result != 0 )
              {
                v6 = IEntity::Y(this);
                v5 = IEntity::X(this);
                result = CSoundManager::PlayEnvironmentSound(g_pSoundManager, *(_DWORD *)(*(_DWORD *)&this->unk_74 + 32), v5, v6, 0);
                this->unk_84 = result;
              }
            }
          }
        }
        break;
      case 0x11u:
        this->m_iFrame = 0;
        break;
      default:
        return result;
    }
  }
  return result;
}


// address=[0x14d6890]
// Decompiled from int __thiscall CAnimal::NewToDoList(IEntity *this, int a2)
void  CAnimal::NewToDoList(class std::list<class CEntityTask,class std::allocator<class CEntityTask> > * a2) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-24h] BYREF
  int v4; // [esp+10h] [ebp-18h]
  int v5; // [esp+14h] [ebp-14h]
  IEntity *v6; // [esp+18h] [ebp-10h]
  int v7; // [esp+24h] [ebp-4h]

  v6 = this;
  if ( a2 == 0 && BBSupportDbgReport(2, "MapObjects\\Animal\\Animal.cpp", 407, "_toDo != NULL") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::FlagBits(v6, ENTITY_FLAG_Registered) != 0 && BBSupportDbgReport(2, "MapObjects\\Animal\\Animal.cpp", 408, "FlagBits( ENTITY_FLAG_REGISTERED ) == 0") == 1 )
  {
    __debugbreak();
  }
  *(_DWORD *)&v6[2].m_iType = a2;
  v5 = ((int (__stdcall *)(_BYTE *))std::list<CEntityTask>::begin)(v3);
  v4 = v5;
  v7 = 0;
  ((void (__stdcall *)(int))std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=)(v5);
  v7 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v3);
  return ((int (__cdecl *)(int))v6->__vftable[1].j_?Decrease@IEntity@@UAEXHH@Z)(1);
}


// address=[0x14d6980]
// Decompiled from void __thiscall CAnimal::NewDestination(CAnimal *this, int a2, int a3, int a4)
void  CAnimal::NewDestination(int a2, int a3, int a4) {
  
  ;
}


// address=[0x14d6990]
// Decompiled from CAnimal *__thiscall CAnimal::ConvertEventIntoGoal(CAnimal *this, struct CEntityEvent *a2)
void  CAnimal::ConvertEventIntoGoal(class CEntityEvent * a2) {
  
  CAnimal *result; // eax

  result = this;
  *((_DWORD *)this + 5) |= 0x80000000;
  return result;
}


// address=[0x14d69b0]
// Decompiled from int __thiscall CAnimal::TakeWaitJob(CAnimal *this, bool a2)
void  CAnimal::TakeWaitJob(bool a2) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-1Ch] BYREF
  CAnimal *v4; // [esp+10h] [ebp-10h]
  int v5; // [esp+1Ch] [ebp-4h]

  v4 = this;
  ((void (__stdcall *)(_BYTE *))std::list<CEntityTask>::begin)(v3);
  v5 = 0;
  if ( (unsigned __int8)std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator!=((std::_Iterator_base12 *)v3) != 0 )
  {
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=((int)v3);
    ((void (__thiscall *)(CAnimal *, bool))v4->j_?TakeJob@CAnimal@@MAEX_N@Z)(v4, a2);
  }
  else if ( a2 )
  {
    ((void (__thiscall *)(CAnimal *, int))v4->j_?TakeJob@CAnimal@@MAEX_N@Z)(v4, 1);
  }
  *(_DWORD *)&v4->unk_64 = 0;
  v5 = -1;
  return std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v3);
}


// address=[0x14d6a70]
// Decompiled from int __thiscall CAnimal::TakeEatJob(CAnimal *this, bool a2)
void  CAnimal::TakeEatJob(bool a2) {
  
  int v2; // eax
  _BYTE v4[12]; // [esp+4h] [ebp-30h] BYREF
  _BYTE v5[12]; // [esp+10h] [ebp-24h] BYREF
  int v6; // [esp+1Ch] [ebp-18h]
  int v7; // [esp+20h] [ebp-14h]
  CAnimal *v8; // [esp+24h] [ebp-10h]
  int v9; // [esp+30h] [ebp-4h]

  v8 = this;
  v7 = ((int (__stdcall *)(_BYTE *))std::list<CEntityTask>::begin)(v4);
  v6 = v7;
  v9 = 0;
  v2 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v7);
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v2);
  LOBYTE(v9) = 2;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v4);
  if ( (unsigned __int8)std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator!=((std::_Iterator_base12 *)v5) != 0 )
  {
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=((int)v5);
    ((void (__thiscall *)(CAnimal *, bool))v8->j_?TakeJob@CAnimal@@MAEX_N@Z)(v8, a2);
  }
  else if ( a2 )
  {
    ((void (__thiscall *)(CAnimal *, int))v8->j_?TakeJob@CAnimal@@MAEX_N@Z)(v8, 1);
  }
  *(_DWORD *)&v8->unk_64 = 1;
  v9 = -1;
  return std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v5);
}


// address=[0x14d6b60]
// Decompiled from int __thiscall CAnimal::TakeWalkJob(CAnimal *this, bool a2)
void  CAnimal::TakeWalkJob(bool a2) {
  
  int v2; // eax
  _BYTE v4[12]; // [esp+4h] [ebp-30h] BYREF
  _BYTE v5[12]; // [esp+10h] [ebp-24h] BYREF
  int v6; // [esp+1Ch] [ebp-18h]
  int v7; // [esp+20h] [ebp-14h]
  CAnimal *v8; // [esp+24h] [ebp-10h]
  int v9; // [esp+30h] [ebp-4h]

  v8 = this;
  v7 = ((int (__stdcall *)(_BYTE *))std::list<CEntityTask>::begin)(v4);
  v6 = v7;
  v9 = 0;
  v2 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v7);
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v2);
  LOBYTE(v9) = 2;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v4);
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v5);
  if ( (unsigned __int8)std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator!=((std::_Iterator_base12 *)v5) != 0 )
  {
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=((int)v5);
  }
  ((void (__thiscall *)(CAnimal *, bool))v8->j_?TakeJob@CAnimal@@MAEX_N@Z)(v8, a2);
  *(_DWORD *)&v8->unk_64 = 2;
  v9 = -1;
  return std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v5);
}


// address=[0x14d6c50]
// Decompiled from int __thiscall CAnimal::TakeFleeJob(CAnimal *this, bool a2)
void  CAnimal::TakeFleeJob(bool a2) {
  
  int v2; // eax
  _BYTE v4[12]; // [esp+4h] [ebp-30h] BYREF
  _BYTE v5[12]; // [esp+10h] [ebp-24h] BYREF
  int v6; // [esp+1Ch] [ebp-18h]
  int v7; // [esp+20h] [ebp-14h]
  CAnimal *v8; // [esp+24h] [ebp-10h]
  int v9; // [esp+30h] [ebp-4h]

  v8 = this;
  v7 = ((int (__stdcall *)(_BYTE *))std::list<CEntityTask>::begin)(v4);
  v6 = v7;
  v9 = 0;
  v2 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v7);
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v2);
  LOBYTE(v9) = 2;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v4);
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v5);
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v5);
  if ( (unsigned __int8)std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator!=((std::_Iterator_base12 *)v5) != 0 )
  {
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=((int)v5);
  }
  ((void (__thiscall *)(CAnimal *, bool))v8->j_?TakeJob@CAnimal@@MAEX_N@Z)(v8, a2);
  *(_DWORD *)&v8->unk_64 = 3;
  v9 = -1;
  return std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v5);
}


// address=[0x14d6d40]
// Decompiled from int __thiscall CAnimal::TakeDieJob(CAnimal *this)
void  CAnimal::TakeDieJob(void) {
  
  int v1; // eax
  _BYTE v3[12]; // [esp+4h] [ebp-30h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-24h] BYREF
  int v5; // [esp+1Ch] [ebp-18h]
  int v6; // [esp+20h] [ebp-14h]
  CAnimal *v7; // [esp+24h] [ebp-10h]
  int v8; // [esp+30h] [ebp-4h]

  v7 = this;
  v6 = ((int (__stdcall *)(_BYTE *))std::list<CEntityTask>::begin)(v3);
  v5 = v6;
  v8 = 0;
  v1 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v6);
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v1);
  LOBYTE(v8) = 2;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v3);
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v4);
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v4);
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v4);
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=((int)v4);
  *(_DWORD *)&v7->unk_64 = 4;
  ((void (__thiscall *)(CAnimal *, int))v7->j_?TakeJob@CAnimal@@MAEX_N@Z)(v7, 1);
  v7->m_iDisplacementCosts = 10;
  v8 = -1;
  return std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v4);
}


// address=[0x14d6e10]
// Decompiled from int __thiscall CAnimal::TakeDeadJob(CAnimal *this)
void  CAnimal::TakeDeadJob(void) {
  
  BYTE v2; // [esp+0h] [ebp-8h]

  if ( this->unk_7c != 0 )
  {
    v2 = this->unk_7c - 1;
  }
  else
  {
    v2 = 0;
  }
  this->m_iFrame = v2;
  *(_DWORD *)&this->unk_64 = 5;
  this->unk_80 = 0;
  return ((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
}


// address=[0x14d6e70]
// Decompiled from int __thiscall CAnimal::TakeWaitJobAndDoNothing(CAnimal *this, int a2)
void  CAnimal::TakeWaitJobAndDoNothing(int a2) {
  
  CAnimal::TakeWaitJob(this, 0);
  return ((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(a2);
}


// address=[0x14d6ea0]
// Decompiled from void __thiscall CAnimal::TakeWalkJobAndWalkDir(CAnimal *this, int a2)
void  CAnimal::TakeWalkJobAndWalkDir(int a2) {
  
  CAnimal::TakeWalkJob(this, 0);
  CAnimal::WalkDirAndRegister(this, a2);
}


// address=[0x14d6ed0]
// Decompiled from int __thiscall CAnimal::TakeJob(int this, char a2)
void  CAnimal::TakeJob(bool a2) {
  
  int result; // eax
  int v3; // [esp+4h] [ebp-10h]
  int v4; // [esp+Ch] [ebp-8h]

  v4 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator*(this + 88);
  if ( *(char *)(v4 + 6) >= 0 )
  {
    *(_BYTE *)(this + 68) = *(_BYTE *)(v4 + 6);
  }
  if ( *(_BYTE *)(v4 + 20) != 0 )
  {
    IEntity::SetFlagBits((_DWORD *)this, ENTITY_FLAG_Visible);
  }
  else
  {
    IEntity::ClearFlagBits((IEntity *)this, ENTITY_FLAG_Visible);
  }
  *(_BYTE *)(this + 122) = *(_BYTE *)(v4 + 4);
  *(_BYTE *)(this + 123) = *(_BYTE *)(v4 + 7);
  *(_BYTE *)(this + 124) = *(_BYTE *)(v4 + 8);
  *(_BYTE *)(this + 69) = 0;
  *(_BYTE *)(this + 36) = 0;
  *(_WORD *)(this + 38) = *(_WORD *)(v4 + 14);
  result = this;
  *(_BYTE *)(this + 120) = 72;
  *(_BYTE *)(this + 70) = 0;
  if ( a2 != 0 )
  {
    switch ( *(_BYTE *)(this + 122) )
    {
      case 6:
      case 0x10:
        result = ((int (__stdcall *)(_DWORD))IAnimatedEntity::RegisterForLogicUpdate)(*(unsigned __int8 *)(this + 124));
        break;
      case 0x1B:
        if ( *(unsigned __int8 *)(this + 124) <= 1u )
        {
          v3 = 1;
        }
        else
        {
          v3 = *(unsigned __int8 *)(this + 124) - 1;
        }
        result = ((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(v3);
        break;
      default:
        result = ((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
        break;
    }
  }
  return result;
}


// address=[0x14d7040]
// Decompiled from BYTE __thiscall CAnimal::WalkDir(CAnimal *this, BYTE a2)
void  CAnimal::WalkDir(int a2) {
  
  int v2; // esi
  CWalking *v3; // eax
  int v4; // eax
  BYTE result; // al
  int v6; // [esp-4h] [ebp-20h]
  int v7; // [esp+4h] [ebp-18h]
  int v8; // [esp+8h] [ebp-14h]
  int v9; // [esp+Ch] [ebp-10h]
  int v10; // [esp+10h] [ebp-Ch]
  Y16X16 *v11; // [esp+14h] [ebp-8h]

  v11 = (Y16X16 *)(a2 & 0xF);
  if ( (unsigned int)v11 < 6 )
  {
    if ( (a2 & 0x20) != 0 && BBSupportDbgReport(2, "MapObjects\\Animal\\Animal.cpp", 427, "(_iWalkResult & WALK_RESULT_FLAG_GOAL_REACHED) == 0") == 1 )
    {
      __debugbreak();
    }
    v7 = IEntity::PackedXY(this);
    v8 = ((int (__stdcall *)())IEntity::WorldIdx)();
    v2 = IEntity::PackedXY(this);
    v9 = Y16X16::NeighborModifier((int)v11) + v2;
    v10 = CWorldManager::Index(v9);
    v3 = (CWalking *)((_DWORD (__cdecl *)(_DWORD))std::auto_ptr<CWalking>::operator->)(v10);
    if ( CWalking::IsFree(v3, v6) )
    {
      CWorldManager::SetSettlerId(v8, 0);
      v4 = ((int (__stdcall *)())IEntity::ID)();
      CWorldManager::SetSettlerId(v10, v4);
      IMovingEntity::SetPositionAndDir(this, v9, (BYTE)v11);
      IMovingEntity::InitDistance(this);
      CWarMap::NotifyMove(this, v7);
    }
    else
    {
      a2 |= 0x88u;
    }
  }
  result = a2;
  this->unk_78 = a2;
  return result;
}


// address=[0x14d7150]
// Decompiled from int __thiscall CAnimal::WalkDirAndRegister(CAnimal *this, char a2)
void  CAnimal::WalkDirAndRegister(int a2) {
  
  CAnimal::WalkDir(this, a2);
  if ( (this->unk_78 & 0xFu) >= 6 )
  {
    return ((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
  }
  else
  {
    return ((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(this->unk_79);
  }
}


// address=[0x14d8150]
// Decompiled from void __thiscall CAnimal::~CAnimal(CAnimal *this)
 CAnimal::~CAnimal(void) {
  
  this->__vftable = (CAnimal_vtbl *)&CAnimal::_vftable_;
  std::list<CEntityTask>::~list<CEntityTask>();
  IMovingEntity::~IMovingEntity(this);
}


