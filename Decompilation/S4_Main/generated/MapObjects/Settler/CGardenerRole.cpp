#include "CGardenerRole.h"

// Definitions for class CGardenerRole

// address=[0x1400b80]
// Decompiled from int __cdecl CGardenerRole::New(int a1)
class CPersistence * __cdecl CGardenerRole::New(std::istream & a1) {
  
  if ( operator new(0x54u) )
    return CGardenerRole::CGardenerRole(a1);
  else
    return 0;
}


// address=[0x1570050]
// Decompiled from int __thiscall CGardenerRole::InitWalking(CGardenerRole *this, struct CSettler *a2)
class CWalking *  CGardenerRole::InitWalking(class CSettler * a2) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  v4 = CWalking::Create(0, v2);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 8))(v4, -1, 0);
  return v4;
}


// address=[0x1570090]
// Decompiled from int __thiscall CGardenerRole::LogicUpdateJob(CGardenerRole *this, struct CSettler *a2)
void  CGardenerRole::LogicUpdateJob(class CSettler * a2) {
  
  int result; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // [esp-8h] [ebp-14h]
  int v7; // [esp-8h] [ebp-14h]
  int v8; // [esp-8h] [ebp-14h]
  int v9; // [esp-4h] [ebp-10h]
  int v10; // [esp+0h] [ebp-Ch]

  switch ( *((_BYTE *)this + 4) )
  {
    case 6:
      IMovingEntity::SetDistance(a2, 0);
      result = (*(int (__thiscall **)(CGardenerRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
      break;
    case 0xD:
      if ( debug && DEBUG_FLAGS[dword_41520C8] )
        BBSupportTracePrint(0, "LogicUpdateJob RESOURCE_GATHERING");
      if ( *((_WORD *)this + 17) )
      {
        v10 = CMapObjectMgr::EntityPtr(*((unsigned __int16 *)this + 17));
        if ( v10 )
        {
          (*(void (__thiscall **)(int, int))(*(_DWORD *)v10 + 32))(v10, 1);
          *((_DWORD *)this + 17) = -1;
          *((_DWORD *)this + 18) = -1;
          v6 = IEntity::Y(a2);
          v3 = IEntity::X(a2);
          CWorldManager::ClearFlagBits(v3, v6, 32);
        }
        *((_WORD *)this + 17) = 0;
      }
      goto LABEL_11;
    case 0x10:
      if ( debug && DEBUG_FLAGS[dword_41520C8] )
        BBSupportTracePrint(0, "LogicUpdateJob WORK");
      v7 = IEntity::Y(a2);
      v4 = IEntity::X(a2);
      CWorldManager::ClearFlagBits(v4, v7, 32);
      *((_DWORD *)this + 17) = -1;
      *((_DWORD *)this + 18) = -1;
      v9 = IEntity::OwnerId((unsigned __int8 *)a2);
      v8 = IEntity::Y(a2);
      v5 = IEntity::X(a2);
      (*(void (__thiscall **)(void *, int, int, int))(*(_DWORD *)g_pDarkTribe + 16))(g_pDarkTribe, v5, v8, v9);
      result = (*(int (__thiscall **)(CGardenerRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
      break;
    case 0x1F:
LABEL_11:
      result = (*(int (__thiscall **)(CGardenerRole *, struct CSettler *))(*(_DWORD *)this + 36))(this, a2);
      break;
    default:
      result = CTrace::Print("GardenerRole - LogicUpdate unknown task");
      break;
  }
  return result;
}


// address=[0x1570280]
// Decompiled from int __thiscall CGardenerRole::PostLoadInit(int this, CPropertySet *a2)
void  CGardenerRole::PostLoadInit(class CSettler * a2) {
  
  int result; // eax
  int v4; // [esp+0h] [ebp-4h]

  CWarMap::AddEntity(a2);
  if ( std::list<CEntityTask>::size((void *)(this + 48)) )
    IMovingEntity::SetToDoList(a2, this + 48);
  IMovingEntity::ResetToDoList(this);
  while ( 1 )
  {
    result = *(unsigned __int8 *)(v4 + 12);
    if ( !*(_BYTE *)(v4 + 12) )
      break;
    IMovingEntity::IncToDoListIter(a2);
    --*(_BYTE *)(v4 + 12);
  }
  return result;
}


// address=[0x15702f0]
// Decompiled from _DWORD *__thiscall CGardenerRole::CGardenerRole(_DWORD *this, int a2)
 CGardenerRole::CGardenerRole(std::istream & a2) {
  
  int v2; // eax
  _DWORD v4[2]; // [esp+4h] [ebp-24h] BYREF
  int v5; // [esp+Ch] [ebp-1Ch] BYREF
  int pExceptionObject; // [esp+10h] [ebp-18h] BYREF
  unsigned int i; // [esp+14h] [ebp-14h]
  _DWORD *v8; // [esp+18h] [ebp-10h]
  int v9; // [esp+24h] [ebp-4h]

  v8 = this;
  ISelectableSettlerRole::ISelectableSettlerRole(a2);
  v9 = 0;
  *v8 = &CGardenerRole::_vftable_;
  std::list<CEntityTask>::list<CEntityTask>(v8 + 12);
  LOBYTE(v9) = 1;
  operator^<unsigned int>(a2, &v5);
  v4[1] = v5;
  if ( v5 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CGardenerRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned int>(a2, v4);
  for ( i = 0; i < v4[0]; ++i )
  {
    v2 = CEntityTask::Load(a2);
    std::list<CEntityTask>::push_back(v2);
  }
  operator^<unsigned char>(a2, v8 + 3);
  operator^<int>(a2, (int)(v8 + 15));
  operator^<int>(a2, (int)(v8 + 16));
  operator^<int>(a2, (int)(v8 + 17));
  operator^<int>(a2, (int)(v8 + 18));
  operator^<int>(a2, (int)(v8 + 19));
  operator^<int>(a2, (int)(v8 + 20));
  v9 = -1;
  return v8;
}


// address=[0x1570480]
// Decompiled from int __thiscall CGardenerRole::Store(int *this, struct std::ostream *a2)
void  CGardenerRole::Store(std::ostream & a2) {
  
  unsigned int v2; // esi
  int v4; // [esp+0h] [ebp-80h]
  int v5; // [esp+4h] [ebp-7Ch]
  _BYTE v6[12]; // [esp+8h] [ebp-78h] BYREF
  _BYTE v7[12]; // [esp+14h] [ebp-6Ch] BYREF
  _BYTE v8[12]; // [esp+20h] [ebp-60h] BYREF
  _BYTE v9[12]; // [esp+2Ch] [ebp-54h] BYREF
  _BYTE v10[12]; // [esp+38h] [ebp-48h] BYREF
  std::_Iterator_base12 *v11; // [esp+44h] [ebp-3Ch]
  std::_Iterator_base12 *ActualIter; // [esp+48h] [ebp-38h]
  char *v13; // [esp+4Ch] [ebp-34h]
  std::_Iterator_base12 *v14; // [esp+50h] [ebp-30h]
  std::_Iterator_base12 *v15; // [esp+54h] [ebp-2Ch]
  std::_Iterator_base12 *v16; // [esp+58h] [ebp-28h]
  std::_Iterator_base12 *v17; // [esp+5Ch] [ebp-24h]
  int v18; // [esp+60h] [ebp-20h] BYREF
  int v19; // [esp+64h] [ebp-1Ch] BYREF
  int v20; // [esp+68h] [ebp-18h]
  int *v21; // [esp+6Ch] [ebp-14h]
  char v22; // [esp+70h] [ebp-10h]
  char v23; // [esp+71h] [ebp-Fh]
  char v24; // [esp+72h] [ebp-Eh]
  int v25; // [esp+73h] [ebp-Dh] BYREF
  int v26; // [esp+7Ch] [ebp-4h]

  v21 = this;
  ISelectableSettlerRole::Store(a2);
  v18 = 1;
  operator^<unsigned int>(a2, &v18);
  v19 = std::list<CEntityTask>::size(v21 + 12);
  operator^<unsigned int>(a2, &v19);
  std::list<CEntityTask>::begin(v10);
  v26 = 0;
  while ( 1 )
  {
    v17 = (std::_Iterator_base12 *)std::list<CEntityTask>::end(v8);
    v16 = v17;
    LOBYTE(v26) = 1;
    v24 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator!=(v17);
    LOBYTE(v26) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v8);
    if ( !v24 )
      break;
    v20 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator->(v10, v4, v5);
    (*(void (__thiscall **)(int, struct std::ostream *))(*(_DWORD *)v20 + 4))(v20, a2);
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v10);
  }
  v26 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v10);
  v13 = (char *)CSettlerMgr::operator[](*((unsigned __int16 *)v21 + 9));
  LOBYTE(v25) = 0;
  if ( v19 )
  {
    std::list<CEntityTask>::begin(v9);
    v26 = 2;
    while ( 1 )
    {
      v15 = (std::_Iterator_base12 *)std::list<CEntityTask>::end(v7);
      v14 = v15;
      LOBYTE(v26) = 3;
      v23 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator!=(v15);
      LOBYTE(v26) = 2;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v7);
      if ( !v23 )
        break;
      ActualIter = (std::_Iterator_base12 *)IMovingEntity::GetActualIter(v13, (int)v6);
      v11 = ActualIter;
      LOBYTE(v26) = 4;
      v22 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator==(ActualIter);
      LOBYTE(v26) = 2;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v6);
      if ( v22 )
        break;
      LOBYTE(v25) = v25 + 1;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v9);
    }
    v26 = -1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v9);
  }
  v2 = (unsigned __int8)v25;
  if ( v2 >= std::list<CEntityTask>::size(v21 + 12) )
    LOBYTE(v25) = 0;
  operator^<unsigned char>(a2, (int)&v25);
  operator^<int>((int)a2, v21 + 15);
  operator^<int>((int)a2, v21 + 16);
  operator^<int>((int)a2, v21 + 17);
  operator^<int>((int)a2, v21 + 18);
  operator^<int>((int)a2, v21 + 19);
  return operator^<int>((int)a2, v21 + 20);
}


// address=[0x1572060]
// Decompiled from int __thiscall CGardenerRole::ClassID(CGardenerRole *this)
unsigned long  CGardenerRole::ClassID(void)const {
  
  return CGardenerRole::m_iClassID;
}


// address=[0x1572080]
// Decompiled from int __thiscall CGardenerRole::GetSettlerRole(CMFCVisualManagerWindows7 *this)
int  CGardenerRole::GetSettlerRole(void)const {
  
  return 13;
}


// address=[0x1588640]
// Decompiled from int __cdecl CGardenerRole::Load(int a1)
class CGardenerRole * __cdecl CGardenerRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CGardenerRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bec4]
// [Decompilation failed for static unsigned long CGardenerRole::m_iClassID]

// address=[0x1570700]
// Decompiled from CGardenerRole *__thiscall CGardenerRole::CGardenerRole(CGardenerRole *this)
 CGardenerRole::CGardenerRole(void) {
  
  ISelectableSettlerRole::ISelectableSettlerRole(this);
  *(_DWORD *)this = &CGardenerRole::_vftable_;
  std::list<CEntityTask>::list<CEntityTask>((char *)this + 48);
  return this;
}


// address=[0x1570770]
// Decompiled from void __thiscall CGardenerRole::~CGardenerRole(CGardenerRole *this)
 CGardenerRole::~CGardenerRole(void) {
  
  CPropertySet *v1; // [esp+4h] [ebp-14h]

  *(_DWORD *)this = &CGardenerRole::_vftable_;
  v1 = (CPropertySet *)CSettlerMgr::operator[](*((unsigned __int16 *)this + 9));
  if ( !IEntity::FlagBits(v1, EntityFlag_OnBoard) )
    CWarMap::RemoveEntity(v1);
  if ( *((_DWORD *)this + 17) != -1 )
    CWorldManager::ClearFlagBits(*((_DWORD *)this + 17), *((_DWORD *)this + 18), 32);
  std::list<CEntityTask>::~list<CEntityTask>();
  ISelectableSettlerRole::~ISelectableSettlerRole(this);
}


// address=[0x1570820]
// Decompiled from int __thiscall CGardenerRole::GetNextJob(CGardenerRole *this, struct CSettler *a2)
void  CGardenerRole::GetNextJob(class CSettler * a2) {
  
  CGardenerRole *v3; // [esp+0h] [ebp-4h]

  v3 = this;
  IMovingEntity::IncToDoListIter(a2);
  if ( IMovingEntity::IsEndIter(a2) )
    IMovingEntity::ResetToDoList(v3);
  return (*(int (__thiscall **)(CGardenerRole *, struct CSettler *))(*(_DWORD *)v3 + 40))(v3, a2);
}


// address=[0x1570860]
// Decompiled from void __thiscall CGardenerRole::TakeJob(int this, COleCmdUI *a2)
void  CGardenerRole::TakeJob(class CSettler * a2) {
  
  const struct CEntityTask *ActualTask; // eax
  unsigned int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // [esp-Ch] [ebp-4Ch]
  int v11; // [esp-Ch] [ebp-4Ch]
  int v12; // [esp-8h] [ebp-48h]
  int v13; // [esp-4h] [ebp-44h]
  int v14; // [esp-4h] [ebp-44h]
  int v15; // [esp+8h] [ebp-38h]
  int v16; // [esp+Ch] [ebp-34h]
  int v17; // [esp+10h] [ebp-30h]
  int v18; // [esp+14h] [ebp-2Ch]
  int v19; // [esp+18h] [ebp-28h]
  CMushroom *v20; // [esp+20h] [ebp-20h]
  IDecoObject *v21; // [esp+24h] [ebp-1Ch]
  int v22; // [esp+2Ch] [ebp-14h]
  int FreeSlot; // [esp+2Ch] [ebp-14h]

  if ( !(unsigned __int8)ISelectableSettlerRole::TakeCommonJob(a2) )
  {
    ActualTask = (const struct CEntityTask *)IMovingEntity::GetActualTask(a2);
    ISettlerRole::InitCommonTaskValues((ISettlerRole *)this, a2, ActualTask);
    switch ( *(_BYTE *)(this + 4) )
    {
      case 7:
        if ( debug && DEBUG_FLAGS[dword_41520C8] )
          BBSupportTracePrint(0, "TakeJob GO_TO_POS");
        IAnimatedEntity::SetFrame(1);
        if ( *(__int16 *)(this + 14) > 0 || *(__int16 *)(this + 16) > 0 )
          ISettlerRole::NewDestination((ISettlerRole *)this, a2, *(__int16 *)(this + 14), *(__int16 *)(this + 16), 0);
        v17 = *(__int16 *)(this + 14) + Y16X16::UnpackXFast(*(_DWORD *)(this + 24));
        v18 = *(__int16 *)(this + 16) + Y16X16::UnpackYFast(*(_DWORD *)(this + 24));
        *(_DWORD *)(this + 24) = Y16X16::PackXYFast(v17, v18);
        IMovingEntity::WalkToXY(a2, *(_DWORD *)(this + 24), 0);
        *(_BYTE *)(this + 4) = 6;
        IMovingEntity::SetDisplacementCosts(5);
        (*(void (__thiscall **)(int, COleCmdUI *))(*(_DWORD *)this + 16))(this, a2);
        break;
      case 0xA:
        if ( debug && DEBUG_FLAGS[dword_41520C8] )
          BBSupportTracePrint(0, "TakeJob GO");
        IAnimatedEntity::SetFrame(1);
        if ( *(__int16 *)(this + 14) > 0 || *(__int16 *)(this + 16) > 0 )
          ISettlerRole::NewDestination((ISettlerRole *)this, a2, *(__int16 *)(this + 14), *(__int16 *)(this + 16), 0);
        v15 = *(__int16 *)(this + 14) + Y16X16::UnpackXFast(*(_DWORD *)(this + 24));
        v16 = *(__int16 *)(this + 16) + Y16X16::UnpackYFast(*(_DWORD *)(this + 24));
        *(_DWORD *)(this + 24) = Y16X16::PackXYFast(v15, v16);
        IMovingEntity::WalkToXY(a2, *(_DWORD *)(this + 24), 0);
        *(_BYTE *)(this + 4) = 6;
        IMovingEntity::SetDisplacementCosts(5);
        (*(void (__thiscall **)(int, COleCmdUI *))(*(_DWORD *)this + 16))(this, a2);
        break;
      case 0xD:
        if ( debug && DEBUG_FLAGS[dword_41520C8] )
          BBSupportTracePrint(0, "TakeJob RESOURCE_GATHERING");
        v11 = IEntity::Y(a2);
        v5 = IEntity::X(a2);
        if ( !CGardenerRole::CheckPosition((CGardenerRole *)this, v5, v11, 0, 1) )
          goto LABEL_29;
        if ( debug && DEBUG_FLAGS[dword_41520C8] )
          BBSupportTracePrint(0, "TakeJob RESOURCE_GATHERING doit");
        IMovingEntity::SetDisplacementCosts(10);
        IAnimatedEntity::RegisterForLogicUpdate(*(char *)(this + 6));
        v13 = IEntity::Y(a2) - 1;
        v6 = IEntity::X(a2);
        v22 = CWorldManager::ObjectId(v6 + 1, v13);
        if ( !v22 )
          goto LABEL_29;
        v21 = (IDecoObject *)CMapObjectMgr::EntityPtr(v22);
        if ( !v21 && BBSupportDbgReport(2, "MapObjects\\Settler\\GardenerRole.cpp", 418, "pSrcMushroom") == 1 )
          __debugbreak();
        if ( !v21 || !IDecoObject::IsStaticInstance(v21) )
        {
LABEL_29:
          if ( *(_DWORD *)(this + 68) != -1 )
          {
            v12 = IEntity::Y(a2);
            v8 = IEntity::X(a2);
            CWorldManager::ClearFlagBits(v8, v12, 32);
            *(_DWORD *)(this + 68) = -1;
            *(_DWORD *)(this + 72) = -1;
            CTrace::Print("GardenerRole: Funghi disappeared! This should not happen!");
          }
          goto LABEL_31;
        }
        FreeSlot = CMapObjectMgr::GetFreeSlot();
        v20 = (CMushroom *)CMushroom::operator new(0x50u);
        if ( v20 )
        {
          v14 = IEntity::Y(a2) - 1;
          v7 = IEntity::X(a2);
          CMushroom::CMushroom(v20, v21, FreeSlot, v7 + 1, v14);
        }
        (*(void (__thiscall **)(int, int))(*(_DWORD *)this + 52))(this, FreeSlot);
        break;
      case 0x10:
        if ( debug && DEBUG_FLAGS[dword_41520C8] )
          BBSupportTracePrint(0, "TakeJob WORK");
        v10 = IEntity::Y(a2);
        v4 = IEntity::X(a2);
        if ( CGardenerRole::CheckPosition((CGardenerRole *)this, v4, v10, 1, 1) )
        {
          IMovingEntity::SetDisplacementCosts(10);
          IAnimatedEntity::RegisterForLogicUpdate(*(char *)(this + 6));
        }
        else
        {
LABEL_31:
          (*(void (__thiscall **)(int, COleCmdUI *))(*(_DWORD *)this + 36))(this, a2);
        }
        break;
      case 0x11:
        IMovingEntity::SetDisplacementCosts(0);
        v3 = CStateGame::Rand(g_pGame);
        IAnimatedEntity::RegisterForLogicUpdate(v3 % 0x10 + 1);
        break;
      case 0x18:
        v19 = CVehicleMgr::operator[](*(unsigned __int16 *)(this + 32));
        v9 = IEntity::ID();
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v19 + 128))(v19, v9);
        break;
      case 0x1F:
        if ( !CGardenerRole::SearchPosition((CGardenerRole *)this, a2, 0)
          && !CGardenerRole::SearchPosition((CGardenerRole *)this, a2, 1) )
        {
          *(_DWORD *)(this + 80) += 48;
          if ( (int)++*(_DWORD *)(this + 76) <= 56 )
          {
            IAnimatedEntity::SetFrame(0);
            IAnimatedEntity::RegisterForLogicUpdate(1);
          }
          else
          {
            CGardenerRole::WorkIsDone((CGardenerRole *)this, a2);
          }
        }
        break;
      default:
        CTrace::Print("GardenerRole - TakeJob unknown task");
        break;
    }
  }
}


// address=[0x1570e50]
// Decompiled from int __thiscall CGardenerRole::Init(int this, CPropertySet *a2)
void  CGardenerRole::Init(class CSettler * a2) {
  
  int result; // eax

  *(_WORD *)(this + 18) = IEntity::ID();
  IEntity::SetFlagBits(a2, EntityFlag_VulnerableMask|EntityFlag_Selectable);
  CWarMap::AddEntity(a2);
  *(_DWORD *)(this + 68) = -1;
  *(_DWORD *)(this + 72) = -1;
  *(_DWORD *)(this + 60) = 0;
  *(_DWORD *)(this + 64) = 0;
  *(_DWORD *)(this + 76) = 0;
  *(_DWORD *)(this + 80) = 0;
  result = 0;
  *(_WORD *)(this + 34) = 0;
  return result;
}


// address=[0x1570ed0]
// Decompiled from int __thiscall CGardenerRole::ConvertEventIntoGoal(int this, CPropertySet *a2, const struct CEntityEvent *a3)
void  CGardenerRole::ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3) {
  
  int result; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // esi
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // [esp-Ch] [ebp-48h]
  int v24; // [esp-8h] [ebp-44h]
  int v25; // [esp-8h] [ebp-44h]
  int v26; // [esp-8h] [ebp-44h]
  int v27; // [esp-8h] [ebp-44h]
  int v28; // [esp-8h] [ebp-44h]
  int v29; // [esp-8h] [ebp-44h]
  int v30; // [esp-8h] [ebp-44h]
  int v31; // [esp-8h] [ebp-44h]
  int v32; // [esp-4h] [ebp-40h]
  int v33; // [esp-4h] [ebp-40h]
  int v34; // [esp-4h] [ebp-40h]
  int v35; // [esp-4h] [ebp-40h]
  int v36; // [esp-4h] [ebp-40h]
  int v37; // [esp-4h] [ebp-40h]
  int v38; // [esp-4h] [ebp-40h]
  int v39; // [esp-4h] [ebp-40h]
  int v40; // [esp+4h] [ebp-38h]
  int v41; // [esp+8h] [ebp-34h]
  int v42; // [esp+10h] [ebp-2Ch]
  int v43; // [esp+18h] [ebp-24h]
  int v44; // [esp+1Ch] [ebp-20h]
  int v45; // [esp+20h] [ebp-1Ch]
  int v46; // [esp+24h] [ebp-18h]
  int v47; // [esp+28h] [ebp-14h]
  _DWORD *v48; // [esp+30h] [ebp-Ch]
  unsigned __int16 *DecoObjPtr; // [esp+34h] [ebp-8h]

  switch ( *((_DWORD *)a3 + 1) )
  {
    case 7:
      v40 = *((_DWORD *)a3 + 3);
      IEntity::SetFlagBits(a2, EntityFlag_Selectable);
      IEntity::ClearFlagBits(a2, EntityFlag_OnBoard);
      v39 = IEntity::Type((unsigned __int16 *)a2);
      v30 = IEntity::Type((unsigned __int16 *)a2);
      v20 = IEntity::Race(a2);
      v21 = CEntityToDoListMgr::SettlerJobList(v20, v30);
      (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v21, v39);
      *(_BYTE *)(this + 4) = 27;
      v31 = IEntity::ID();
      v22 = IEntity::OwnerId((unsigned __int8 *)a2);
      result = (*(int (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(
                 off_3D7A3D8,
                 21,
                 v22,
                 v31,
                 v40);
      break;
    case 0xD:
      CTrace::Print("CGardenerRole - NewDestinationEx called from ConvertEventIntoGoal-GO_TO_POS");
      result = (*(int (__thiscall **)(int, CPropertySet *, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this + 128))(
                 this,
                 a2,
                 this + 48,
                 *((_DWORD *)a3 + 4),
                 *((_DWORD *)a3 + 5),
                 *((_DWORD *)a3 + 3));
      break;
    case 0x11:
      if ( *(_DWORD *)(this + 68) != -1 )
      {
        CWorldManager::ClearFlagBits(*(_DWORD *)(this + 68), *(_DWORD *)(this + 72), 32);
        *(_DWORD *)(this + 68) = -1;
        *(_DWORD *)(this + 72) = -1;
      }
      result = *((_DWORD *)a3 + 2);
      if ( result == 13 )
      {
        result = ISelectableSettlerRole::ProcessGoToPosFerry((ISelectableSettlerRole *)this, a2, a3);
        if ( !(_BYTE)result )
        {
          if ( *(_WORD *)(this + 34) )
          {
            DecoObjPtr = (unsigned __int16 *)CDecoObjMgr::GetDecoObjPtr(*(unsigned __int16 *)(this + 34));
            if ( DecoObjPtr && !IDecoObject::IsStaticInstance((IDecoObject *)DecoObjPtr) )
            {
              v32 = (*(int (__thiscall **)(unsigned __int16 *))(*(_DWORD *)DecoObjPtr + 40))(DecoObjPtr);
              v24 = IEntity::Type(DecoObjPtr);
              v23 = IEntity::Y(DecoObjPtr);
              v4 = IEntity::X(DecoObjPtr);
              CDecoObjMgr::ChangeToStaticInstance((CDecoObjMgr *)&g_cDecoObjMgr, v4, v23, v24, v32);
            }
            *(_WORD *)(this + 34) = 0;
          }
          if ( *(_DWORD *)(this + 68) != -1 )
          {
            CWorldManager::ClearFlagBits(*(_DWORD *)(this + 68), *(_DWORD *)(this + 72), 32);
            *(_DWORD *)(this + 68) = -1;
            *(_DWORD *)(this + 72) = -1;
          }
          v41 = *((_DWORD *)a3 + 3);
          v46 = *((_DWORD *)a3 + 4);
          v44 = Y16X16::UnpackXFast(v46);
          v45 = Y16X16::UnpackYFast(v46);
          if ( (v41 & 4) != 0 )
          {
            v47 = 176;
          }
          else
          {
            *(_DWORD *)(this + 60) = v44;
            *(_DWORD *)(this + 64) = v45;
            *(_DWORD *)(this + 80) = 0;
            *(_DWORD *)(this + 76) = 0;
            v47 = 174;
          }
          ISettlerRole::NewDestination((ISettlerRole *)this, a2, v44, v45, 0);
          v5 = IEntity::Race(a2);
          v6 = CEntityToDoListMgr::SettlerJobList(v5, v47);
          result = (*(int (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v6, v47);
        }
      }
      break;
    case 0x18:
      v33 = IEntity::Type((unsigned __int16 *)a2);
      v7 = IEntity::Race(a2);
      CSettlerMgr::GetSettlerInfo(v7, v33);
      v48 = (_DWORD *)CVehicleMgr::operator[](*((_DWORD *)a3 + 3));
      v8 = IEntity::ID();
      v43 = (*(int (__thiscall **)(_DWORD *, int, int))(*v48 + 140))(v48, 1, v8);
      if ( v43 && IEntity::FlagBits(v48, (EntityFlag)&loc_3000000) )
      {
        ISettlerRole::NewDestination((ISettlerRole *)this, a2, v43, 0);
        v34 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
        v25 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
        v9 = IEntity::Race(a2);
        v10 = CEntityToDoListMgr::SettlerJobList(v9, v25);
        (*(void (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v10, v34);
        v11 = IEntity::OwnerId((unsigned __int8 *)a2);
        if ( v11 == CPlayerManager::GetLocalPlayerId() )
        {
          v12 = IEntity::ID();
          CInputProcessor::DeSelectEntity(&g_cInputProcessor, v12);
        }
        v13 = IEntity::ID();
        (*(void (__thiscall **)(_DWORD *, int))(*v48 + 164))(v48, v13);
        IEntity::ClearFlagBits(a2, EntityFlag_Selectable|EntityFlag_Selected);
        v14 = IEntity::ID();
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)g_pGroupMgr + 28))(g_pGroupMgr, v14);
        v35 = *(unsigned __int16 *)(this + 32);
        v26 = IEntity::ID();
        v15 = IEntity::OwnerId((unsigned __int8 *)a2);
        result = (*(int (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(
                   off_3D7A3D8,
                   18,
                   v15,
                   v26,
                   v35);
      }
      else
      {
        IEntity::SetFlagBits(a2, EntityFlag_Selectable);
        v36 = IEntity::Type((unsigned __int16 *)a2);
        v27 = IEntity::Type((unsigned __int16 *)a2);
        v16 = IEntity::Race(a2);
        v17 = CEntityToDoListMgr::SettlerJobList(v16, v27);
        result = (*(int (__thiscall **)(CPropertySet *, int, int))(*(_DWORD *)a2 + 112))(a2, v17, v36);
      }
      break;
    case 0x19:
      v42 = *((_DWORD *)a3 + 4);
      *(_WORD *)(this + 32) = 0;
      v37 = Y16X16::UnpackYFast(v42);
      v28 = Y16X16::UnpackXFast(v42);
      v18 = IEntity::ID();
      CSettlerMgr::SearchSpaceForSettler((CSettlerMgr *)g_cSettlerMgr, v18, v28, v37);
      CWarMap::AddEntity(a2);
      IEntity::SetFlagBits(a2, EntityFlag_Selectable|EntityFlag_Visible);
      IEntity::ClearFlagBits(a2, EntityFlag_OnBoard);
      *(_BYTE *)(this + 4) = 27;
      v38 = *(unsigned __int16 *)(this + 32);
      v29 = IEntity::ID();
      v19 = IEntity::OwnerId((unsigned __int8 *)a2);
      result = (*(int (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(
                 off_3D7A3D8,
                 21,
                 v19,
                 v29,
                 v38);
      break;
    default:
      result = IEntity::FlagBits(a2, EntityFlag_Registered);
      if ( !result )
      {
        CTrace::Print("ConvertEventIntoGoal GardenerRole - unknown event %u", *((_DWORD *)a3 + 1));
        result = IAnimatedEntity::RegisterForLogicUpdate(1);
      }
      break;
  }
  return result;
}


// address=[0x1571440]
// Decompiled from int __thiscall CGardenerRole::WorkIsDone(CGardenerRole *this, struct CSettler *a2)
void  CGardenerRole::WorkIsDone(class CSettler * a2) {
  
  int v2; // eax
  int v3; // eax
  int v5; // [esp-8h] [ebp-Ch]
  int v6; // [esp-4h] [ebp-8h]

  v6 = IEntity::Type((unsigned __int16 *)a2);
  v5 = IEntity::Type((unsigned __int16 *)a2);
  v2 = IEntity::Race(a2);
  v3 = CEntityToDoListMgr::SettlerJobList(v2, v5);
  return (*(int (__thiscall **)(struct CSettler *, int, int))(*(_DWORD *)a2 + 112))(a2, v3, v6);
}


// address=[0x1571490]
// Decompiled from char __thiscall CGardenerRole::SetFree(CGardenerRole *this, struct CSettler *a2, int a3)
bool  CGardenerRole::SetFree(class CSettler * a2, int a3) {
  
  int v3; // eax
  int v5; // [esp-Ch] [ebp-14h]
  int v6; // [esp-8h] [ebp-10h]
  int v7; // [esp-4h] [ebp-Ch]
  unsigned __int16 *DecoObjPtr; // [esp+4h] [ebp-4h]

  if ( !*((_WORD *)this + 17) )
    return ISettlerRole::SetFree(this, a2, a3);
  DecoObjPtr = (unsigned __int16 *)CDecoObjMgr::GetDecoObjPtr(*((unsigned __int16 *)this + 17));
  if ( DecoObjPtr && !IDecoObject::IsStaticInstance((IDecoObject *)DecoObjPtr) )
  {
    v7 = (*(int (__thiscall **)(unsigned __int16 *))(*(_DWORD *)DecoObjPtr + 40))(DecoObjPtr);
    v6 = IEntity::Type(DecoObjPtr);
    v5 = IEntity::Y(DecoObjPtr);
    v3 = IEntity::X(DecoObjPtr);
    CDecoObjMgr::ChangeToStaticInstance((CDecoObjMgr *)&g_cDecoObjMgr, v3, v5, v6, v7);
  }
  *((_WORD *)this + 17) = 0;
  return ISettlerRole::SetFree(this, a2, a3);
}


// address=[0x1571520]
// Decompiled from bool __thiscall CGardenerRole::CheckPosition(CGardenerRole *this, int a2, int a3, int a4, bool a5)
bool  CGardenerRole::CheckPosition(int a2, int a3, int a4, bool a5) {
  
  IDecoObject *v6; // [esp+8h] [ebp-20h]
  int v7; // [esp+18h] [ebp-10h]
  int v8; // [esp+1Ch] [ebp-Ch]
  unsigned int v9; // [esp+20h] [ebp-8h]
  unsigned __int8 *v10; // [esp+24h] [ebp-4h]

  v7 = CWorldManager::Index(a2, a3);
  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3) )
    return 0;
  v9 = a4 != 0;
  if ( a5 )
  {
    if ( !CWorldManager::FlagBits(v7, 0x20u) )
      return 0;
  }
  else
  {
    v9 |= 0x20u;
  }
  if ( CWorldManager::FlagBits(v7, v9) )
    return 0;
  if ( !a4 )
  {
    if ( !(unsigned __int8)CWorldManager::InWorld(a2 + 1, a3 - 1) )
      return 0;
    v8 = CWorldManager::ObjectId(a2 + 1, a3 - 1);
    if ( !v8 )
      return 0;
    v10 = (unsigned __int8 *)CMapObjectMgr::Entity(v8);
    if ( IEntity::ObjType(v10) != 32
      || !IEntity::FlagBits(v10, (EntityFlag)((char *)&loc_1FFFFFF + 1))
      || IEntity::Type((unsigned __int16 *)v10) != 212
      && IEntity::Type((unsigned __int16 *)v10) != 213
      && IEntity::Type((unsigned __int16 *)v10) != 214 )
    {
      return 0;
    }
    v6 = (IDecoObject *)CMapObjectMgr::EntityPtr(v8);
    if ( !v6 )
      return 0;
    if ( IDecoObject::IsStaticInstance(v6) )
      return 1;
    return 0;
  }
  if ( a4 == 1 )
    return (!CWorldManager::MapObjectId(a2, a3) || a5) && CWorldManager::FlagBits(v7, 4u) == 4;
  CTrace::Print("GardernerRole: Unknown Searchtype %d", a4);
  return 0;
}


// address=[0x1571710]
// Decompiled from char __thiscall CGardenerRole::SearchPosition(CGardenerRole *this, struct CSettler *a2, int a3)
bool  CGardenerRole::SearchPosition(class CSettler * a2, int a3) {
  
  int v3; // eax
  int v4; // esi
  int v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v12; // [esp-4h] [ebp-40h]
  int v13; // [esp-4h] [ebp-40h]
  int v14; // [esp+4h] [ebp-38h]
  int v15; // [esp+Ch] [ebp-30h]
  unsigned int v16; // [esp+18h] [ebp-24h]
  int v17; // [esp+1Ch] [ebp-20h]
  int v18; // [esp+20h] [ebp-1Ch]
  unsigned int v19; // [esp+20h] [ebp-1Ch]
  int v20; // [esp+24h] [ebp-18h]
  int i; // [esp+28h] [ebp-14h]
  int v22; // [esp+2Ch] [ebp-10h]
  int v23; // [esp+30h] [ebp-Ch]
  int v24; // [esp+34h] [ebp-8h]

  v22 = -1;
  v20 = -1;
  v16 = -1;
  v17 = 0;
  v12 = IEntity::Y(a2);
  v3 = IEntity::X(a2);
  v15 = CWorldManager::SectorId(v3, v12);
  for ( i = *((_DWORD *)this + 20); i < *((_DWORD *)this + 20) + 48; ++i )
  {
    v4 = IEntity::X(a2);
    v24 = CSpiralOffsets::DeltaX(i) + v4;
    v5 = IEntity::Y(a2);
    v23 = CSpiralOffsets::DeltaY(i) + v5;
    if ( (unsigned __int8)CWorldManager::InWorld(v24, v23) )
    {
      if ( CWorldManager::SectorId(v24, v23) == v15 )
      {
        if ( CGardenerRole::CheckPosition(this, v24, v23, a3, 0) )
        {
          ++v17;
          v18 = CSpiralOffsets::PseudoDistanceSquareEx(v24 - *((_DWORD *)this + 15), v23 - *((_DWORD *)this + 16));
          v13 = v23 - IEntity::Y(a2);
          v6 = IEntity::X(a2);
          v19 = v18 + 2 * CSpiralOffsets::PseudoDistanceSquareEx(v24 - v6, v13);
          if ( v19 < v16 )
          {
            v16 = v19;
            v22 = v24;
            v20 = v23;
          }
        }
        if ( v17 > 31 )
          break;
      }
    }
  }
  if ( v22 == -1 )
    return 0;
  if ( *((_DWORD *)this + 17) != -1 )
    CWorldManager::ClearFlagBits(*((_DWORD *)this + 17), *((_DWORD *)this + 18), 32);
  v14 = CWorldManager::Index(v22, v20);
  CWorldManager::SetFlagBits(v14, 0x20u);
  *((_DWORD *)this + 17) = v22;
  *((_DWORD *)this + 18) = v20;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 19) = 0;
  if ( a3 )
  {
    if ( a3 == 1 )
    {
      ISettlerRole::NewDestination(this, a2, v22, v20, 0);
      v9 = IEntity::Race(a2);
      v10 = CEntityToDoListMgr::SettlerJobList(v9, 175);
      (*(void (__thiscall **)(struct CSettler *, int, int))(*(_DWORD *)a2 + 112))(a2, v10, 175);
    }
    else
    {
      CTrace::Print("GardenerRole: Unknown Searchtype %d", a3);
    }
  }
  else
  {
    ISettlerRole::NewDestination(this, a2, v22, v20, 0);
    v7 = IEntity::Race(a2);
    v8 = CEntityToDoListMgr::SettlerJobList(v7, 174);
    (*(void (__thiscall **)(struct CSettler *, int, int))(*(_DWORD *)a2 + 112))(a2, v8, 174);
  }
  return 1;
}


