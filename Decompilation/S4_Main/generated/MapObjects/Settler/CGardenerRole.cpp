#include "CGardenerRole.h"

// Definitions for class CGardenerRole

// address=[0x1400b80]
// Decompiled from CGardenerRole *__cdecl CGardenerRole::New(struct std::istream *a1)
class CPersistence * __cdecl CGardenerRole::New(std::istream & a1) {
  
  CGardenerRole *C; // [esp+Ch] [ebp-10h]

  C = (CGardenerRole *)operator new(0x54u);
  if ( C )
    return CGardenerRole::CGardenerRole(C, a1);
  else
    return 0;
}


// address=[0x1570050]
// Decompiled from CWalkingNormal *__thiscall CGardenerRole::InitWalking(CGardenerRole *this, IEntity *a2)
class CWalking *  CGardenerRole::InitWalking(class CSettler * a2) {
  
  int v2; // eax
  CWalkingNormal *v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId(a2);
  v4 = CWalking::Create(0, v2);
  v4->InitB(v4, -1, 0);
  return v4;
}


// address=[0x1570090]
// Decompiled from void __thiscall CGardenerRole::LogicUpdateJob(CGardenerRole *this, struct CSettler *pSettler)
void  CGardenerRole::LogicUpdateJob(class CSettler * pSettler) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // [esp-8h] [ebp-14h]
  int v6; // [esp-8h] [ebp-14h]
  int v7; // [esp-8h] [ebp-14h]
  int v8; // [esp-4h] [ebp-10h]
  IEntity *v9; // [esp+0h] [ebp-Ch]

  switch ( this->m_iTask )
  {
    case 6:
      IMovingEntity::SetDistance(pSettler, 0);
      this->Go(this, pSettler);
      break;
    case 0xD:
      if ( debug && DEBUG_FLAGS[g_iGardenerDebugFlags] )
        BBSupportTracePrint(0, "LogicUpdateJob RESOURCE_GATHERING");
      if ( this->m_uEntityId )
      {
        v9 = CMapObjectMgr::EntityPtr(this->m_uEntityId);
        if ( v9 )
        {
          v9->Decrease(1);
          this->m_iTargetMushroomX = -1;
          this->m_iTargetMushroomY = -1;
          v5 = IEntity::Y(pSettler);
          v2 = IEntity::X(pSettler);
          CWorldManager::ClearFlagBits(v2, v5, 32);
        }
        this->m_uEntityId = 0;
      }
      goto LABEL_11;
    case 0x10:
      if ( debug && DEBUG_FLAGS[g_iGardenerDebugFlags] )
        BBSupportTracePrint(0, "LogicUpdateJob WORK");
      v6 = IEntity::Y(pSettler);
      v3 = IEntity::X(pSettler);
      CWorldManager::ClearFlagBits(v3, v6, 32);
      this->m_iTargetMushroomX = -1;
      this->m_iTargetMushroomY = -1;
      v8 = IEntity::OwnerId(pSettler);
      v7 = IEntity::Y(pSettler);
      v4 = IEntity::X(pSettler);
      (*(void (__thiscall **)(void *, int, int, int))(*(_DWORD *)g_pDarkTribe + 16))(g_pDarkTribe, v4, v7, v8);
      this->GetNextJob(this, pSettler);
      break;
    case 0x1F:
LABEL_11:
      this->GetNextJob(this, pSettler);
      break;
    default:
      CTrace::Print("GardenerRole - LogicUpdate unknown task");
      break;
  }
}


// address=[0x1570280]
// Decompiled from void __thiscall CGardenerRole::PostLoadInit(CGardenerRole *this, IMovingEntity *a1)
void  CGardenerRole::PostLoadInit(class CSettler * a1) {
  
  CWarMap::AddEntity(a1);
  if ( std::list<CEntityTask>::size(&this->m_vTasks) )
    IMovingEntity::SetToDoList(a1, (DWORD)&this->m_vTasks);
  IMovingEntity::ResetToDoList(a1);
  while ( this->m_uToDoCount )
  {
    IMovingEntity::IncToDoListIter(a1);
    --this->m_uToDoCount;
  }
}


// address=[0x15702f0]
// Decompiled from CGardenerRole *__thiscall CGardenerRole::CGardenerRole(CGardenerRole *this, struct std::istream *stream)
 CGardenerRole::CGardenerRole(std::istream & stream) {
  
  struct CEntityTask *v2; // eax
  int v4; // [esp+4h] [ebp-24h] BYREF
  unsigned int v6; // [esp+Ch] [ebp-1Ch] MAPDST BYREF
  int pExceptionObject; // [esp+10h] [ebp-18h] BYREF
  unsigned int i; // [esp+14h] [ebp-14h]
  int exceptionBlock; // [esp+24h] [ebp-4h]

  ISelectableSettlerRole::ISelectableSettlerRole(this, (int)stream);
  exceptionBlock = 0;
  this->__vftable = (ISettlerRole_vtbl *)&CGardenerRole::_vftable_;
  std::list<CEntityTask>::list<CEntityTask>(&this->m_vTasks);
  LOBYTE(exceptionBlock) = 1;
  operator^<unsigned int>(stream, &v6);
  if ( v6 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CGardenerRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned int>(stream, (unsigned int *)&v4);
  for ( i = 0; i < v4; ++i )
  {
    v2 = CEntityTask::Load(stream);
    std::list<CEntityTask>::push_back(v2);
  }
  operator^<unsigned char>(stream, &this->m_uToDoCount);
  operator^<int>(stream, &this->m_iEventX);
  operator^<int>(stream, &this->m_iEventY);
  operator^<int>(stream, &this->m_iTargetMushroomX);
  operator^<int>(stream, &this->m_iTargetMushroomY);
  operator^<int>(stream, &this->m_iWorkTick);
  operator^<int>(stream, &this->m_iNextSearchTick);
  exceptionBlock = -1;
  return this;
}


// address=[0x1570480]
// Decompiled from void __thiscall CGardenerRole::Store(CGardenerRole *this, struct std::ostream *a1)
void  CGardenerRole::Store(std::ostream & a1) {
  
  unsigned int v2; // esi
  _BYTE v3[12]; // [esp+8h] [ebp-78h] BYREF
  _BYTE v4[12]; // [esp+14h] [ebp-6Ch] BYREF
  _BYTE v5[12]; // [esp+20h] [ebp-60h] BYREF
  _BYTE v6[12]; // [esp+2Ch] [ebp-54h] BYREF
  _BYTE v7[12]; // [esp+38h] [ebp-48h] BYREF
  std::_Iterator_base12 *v8; // [esp+44h] [ebp-3Ch]
  std::_Iterator_base12 *ActualIter; // [esp+48h] [ebp-38h]
  CSettler *v10; // [esp+4Ch] [ebp-34h]
  std::_Iterator_base12 *v11; // [esp+50h] [ebp-30h]
  std::_Iterator_base12 *v12; // [esp+54h] [ebp-2Ch]
  std::_Iterator_base12 *v13; // [esp+58h] [ebp-28h]
  std::_Iterator_base12 *v14; // [esp+5Ch] [ebp-24h]
  int v15; // [esp+60h] [ebp-20h] BYREF
  int v16; // [esp+64h] [ebp-1Ch] BYREF
  int v17; // [esp+68h] [ebp-18h]
  bool v19; // [esp+70h] [ebp-10h]
  char v20; // [esp+71h] [ebp-Fh]
  char v21; // [esp+72h] [ebp-Eh]
  BYTE a2; // [esp+73h] [ebp-Dh] BYREF
  int v23; // [esp+7Ch] [ebp-4h]

  ISelectableSettlerRole::Store((__int16 *)this, a1);
  v15 = 1;
  operator^<unsigned int>(a1, &v15);
  v16 = std::list<CEntityTask>::size(&this->m_vTasks);
  operator^<unsigned int>(a1, &v16);
  std::list<CEntityTask>::begin(&this->m_vTasks);
  v23 = 0;
  while ( 1 )
  {
    v14 = (std::_Iterator_base12 *)std::list<CEntityTask>::end(&this->m_vTasks);
    v13 = v14;
    LOBYTE(v23) = 1;
    v21 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator!=(v14);
    LOBYTE(v23) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v5);
    if ( !v21 )
      break;
    v17 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator->(v7);
    (*(void (__thiscall **)(int, struct std::ostream *))(*(_DWORD *)v17 + 4))(v17, a1);
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v7);
  }
  v23 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v7);
  v10 = CSettlerMgr::operator[](this->m_uAttachedSettlerId);
  a2 = 0;
  if ( v16 )
  {
    std::list<CEntityTask>::begin(&this->m_vTasks);
    v23 = 2;
    while ( 1 )
    {
      v12 = (std::_Iterator_base12 *)std::list<CEntityTask>::end(&this->m_vTasks);
      v11 = v12;
      LOBYTE(v23) = 3;
      v20 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator!=(v12);
      LOBYTE(v23) = 2;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v4);
      if ( !v20 )
        break;
      ActualIter = (std::_Iterator_base12 *)IMovingEntity::GetActualIter(v10, (int)v3);
      v8 = ActualIter;
      LOBYTE(v23) = 4;
      v19 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator==(
              (std::_Iterator_base12 *)v6,
              ActualIter);
      LOBYTE(v23) = 2;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v3);
      if ( v19 )
        break;
      ++a2;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v6);
    }
    v23 = -1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v6);
  }
  v2 = a2;
  if ( v2 >= std::list<CEntityTask>::size(&this->m_vTasks) )
    a2 = 0;
  operator^<unsigned char>(a1, &a2);
  operator^<int>(a1, &this->m_iEventX);
  operator^<int>(a1, &this->m_iEventY);
  operator^<int>(a1, &this->m_iTargetMushroomX);
  operator^<int>(a1, &this->m_iTargetMushroomY);
  operator^<int>(a1, &this->m_iWorkTick);
  operator^<int>(a1, &this->m_iNextSearchTick);
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
// Decompiled from int __cdecl CGardenerRole::Load(struct std::istream *a1)
class CGardenerRole * __cdecl CGardenerRole::Load(std::istream & a1) {
  
  void **v1; // eax

  v1 = (void **)CPersistence::New(a1);
  return j____RTDynamicCast(v1, 0, &CPersistence__RTTI_Type_Descriptor_, &CGardenerRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bec4]
// [Decompilation failed for static unsigned long CGardenerRole::m_iClassID]

// address=[0x1570700]
// Decompiled from CGardenerRole *__thiscall CGardenerRole::CGardenerRole(CGardenerRole *this)
 CGardenerRole::CGardenerRole(void) {
  
  ISelectableSettlerRole::ISelectableSettlerRole(this);
  this->__vftable = (ISettlerRole_vtbl *)&CGardenerRole::_vftable_;
  std::list<CEntityTask>::list<CEntityTask>(&this->m_vTasks);
  return this;
}


// address=[0x1570770]
// Decompiled from void __thiscall CGardenerRole::~CGardenerRole(CGardenerRole *this)
 CGardenerRole::~CGardenerRole(void) {
  
  CPropertySet *v1; // [esp+4h] [ebp-14h]

  *(_DWORD *)this = &CGardenerRole::_vftable_;
  v1 = (CPropertySet *)CSettlerMgr::operator[](*((unsigned __int16 *)this + 9));
  if ( !IEntity::FlagBits(v1, ENTITY_FLAG_ON_BOARD) )
    CWarMap::RemoveEntity(v1);
  if ( *((_DWORD *)this + 17) != -1 )
    CWorldManager::ClearFlagBits(*((_DWORD *)this + 17), *((_DWORD *)this + 18), 32);
  std::list<CEntityTask>::~list<CEntityTask>();
  ISelectableSettlerRole::~ISelectableSettlerRole(this);
}


// address=[0x1570820]
// Decompiled from void __thiscall CGardenerRole::GetNextJob(CGardenerRole *this, struct CSettler *a2)
void  CGardenerRole::GetNextJob(class CSettler * a2) {
  
  IMovingEntity::IncToDoListIter(a2);
  if ( IMovingEntity::IsEndIter(a2) )
    IMovingEntity::ResetToDoList(a2);
  this->TakeJob(this, a2);
}


// address=[0x1570860]
// Decompiled from void __thiscall CGardenerRole::TakeJob(CGardenerRole *this, struct CSettler *pSettler)
void  CGardenerRole::TakeJob(class CSettler * pSettler) {
  
  CEntityTask *ActualTask; // eax
  DWORD v3; // eax
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
  unsigned int v14; // [esp-4h] [ebp-44h]
  int v15; // [esp+8h] [ebp-38h]
  int v16; // [esp+Ch] [ebp-34h]
  int v17; // [esp+10h] [ebp-30h]
  int v18; // [esp+14h] [ebp-2Ch]
  CVehicle *v19; // [esp+18h] [ebp-28h]
  CMushroom *v20; // [esp+20h] [ebp-20h]
  struct CMushroom *pSrcMushroom; // [esp+24h] [ebp-1Ch]
  int v22; // [esp+2Ch] [ebp-14h]
  int FreeSlot; // [esp+2Ch] [ebp-14h]

  if ( !ISelectableSettlerRole::TakeCommonJob(this, pSettler) )
  {
    ActualTask = IMovingEntity::GetActualTask(pSettler);
    ISettlerRole::InitCommonTaskValues(this, pSettler, ActualTask);
    switch ( this->m_iTask )
    {
      case 7:
        if ( debug && DEBUG_FLAGS[g_iGardenerDebugFlags] )
          BBSupportTracePrint(0, "TakeJob GO_TO_POS");
        IAnimatedEntity::SetFrame(pSettler, 1u);
        if ( this->m_iDestinationOffsetX > 0 || this->m_iDestinationOffsetY > 0 )
          ISettlerRole::NewDestination(this, pSettler, this->m_iDestinationOffsetX, this->m_iDestinationOffsetY, 0);
        v17 = this->m_iDestinationOffsetX + Y16X16::UnpackXFast(this->m_iDestinationPosition);
        v18 = this->m_iDestinationOffsetY + Y16X16::UnpackYFast(this->m_iDestinationPosition);
        this->m_iDestinationPosition = Y16X16::PackXYFast(v17, v18);
        IMovingEntity::WalkToXY(pSettler, this->m_iDestinationPosition, 0);
        this->m_iTask = 6;
        IMovingEntity::SetDisplacementCosts(pSettler, 5);
        this->Go(this, pSettler);
        break;
      case 0xA:
        if ( debug && DEBUG_FLAGS[g_iGardenerDebugFlags] )
          BBSupportTracePrint(0, "TakeJob GO");
        IAnimatedEntity::SetFrame(pSettler, 1u);
        if ( this->m_iDestinationOffsetX > 0 || this->m_iDestinationOffsetY > 0 )
          ISettlerRole::NewDestination(this, pSettler, this->m_iDestinationOffsetX, this->m_iDestinationOffsetY, 0);
        v15 = this->m_iDestinationOffsetX + Y16X16::UnpackXFast(this->m_iDestinationPosition);
        v16 = this->m_iDestinationOffsetY + Y16X16::UnpackYFast(this->m_iDestinationPosition);
        this->m_iDestinationPosition = Y16X16::PackXYFast(v15, v16);
        IMovingEntity::WalkToXY(pSettler, this->m_iDestinationPosition, 0);
        this->m_iTask = 6;
        IMovingEntity::SetDisplacementCosts(pSettler, 5);
        this->Go(this, pSettler);
        break;
      case 0xD:
        if ( debug && DEBUG_FLAGS[g_iGardenerDebugFlags] )
          BBSupportTracePrint(0, "TakeJob RESOURCE_GATHERING");
        v11 = IEntity::Y(pSettler);
        v5 = IEntity::X(pSettler);
        if ( !CGardenerRole::CheckPosition(this, v5, v11, 0, 1) )
          goto LABEL_29;
        if ( debug && DEBUG_FLAGS[g_iGardenerDebugFlags] )
          BBSupportTracePrint(0, "TakeJob RESOURCE_GATHERING doit");
        IMovingEntity::SetDisplacementCosts(pSettler, 10);
        IAnimatedEntity::RegisterForLogicUpdate(pSettler, this->m_iWalkspeed);
        v13 = IEntity::Y(pSettler) - 1;
        v6 = IEntity::X(pSettler);
        v22 = CWorldManager::ObjectId(v6 + 1, v13);
        if ( !v22 )
          goto LABEL_29;
        pSrcMushroom = (struct CMushroom *)CMapObjectMgr::EntityPtr(v22);
        if ( !pSrcMushroom && BBSupportDbgReport(2, "MapObjects\\Settler\\GardenerRole.cpp", 418, "pSrcMushroom") == 1 )
          __debugbreak();
        if ( !pSrcMushroom || !IDecoObject::IsStaticInstance(pSrcMushroom) )
        {
LABEL_29:
          if ( this->m_iTargetMushroomX != -1 )
          {
            v12 = IEntity::Y(pSettler);
            v8 = IEntity::X(pSettler);
            CWorldManager::ClearFlagBits(v8, v12, 32);
            this->m_iTargetMushroomX = -1;
            this->m_iTargetMushroomY = -1;
            CTrace::Print("GardenerRole: Funghi disappeared! This should not happen!");
          }
          goto LABEL_31;
        }
        FreeSlot = CMapObjectMgr::GetFreeSlot();
        v20 = (CMushroom *)CMushroom::operator new(0x50u);
        if ( v20 )
        {
          v14 = IEntity::Y(pSettler) - 1;
          v7 = IEntity::X(pSettler);
          CMushroom::CMushroom(v20, pSrcMushroom, FreeSlot, v7 + 1, v14);
        }
        this->SetEntity(this, FreeSlot);
        break;
      case 0x10:
        if ( debug && DEBUG_FLAGS[g_iGardenerDebugFlags] )
          BBSupportTracePrint(0, "TakeJob WORK");
        v10 = IEntity::Y(pSettler);
        v4 = IEntity::X(pSettler);
        if ( CGardenerRole::CheckPosition(this, v4, v10, 1, 1) )
        {
          IMovingEntity::SetDisplacementCosts(pSettler, 10);
          IAnimatedEntity::RegisterForLogicUpdate(pSettler, this->m_iWalkspeed);
        }
        else
        {
LABEL_31:
          this->GetNextJob(this, pSettler);
        }
        break;
      case 0x11:
        IMovingEntity::SetDisplacementCosts(pSettler, 0);
        v3 = CStateGame::Rand(g_pGame);
        IAnimatedEntity::RegisterForLogicUpdate(pSettler, v3 % 0x10 + 1);
        break;
      case 0x18:
        v19 = CVehicleMgr::operator[](this->m_uHomeEntityId);
        v9 = IEntity::ID(pSettler);
        v19->EntityEnter(v19, v9);
        break;
      case 0x1F:
        if ( !CGardenerRole::SearchPosition(this, pSettler, 0) && !CGardenerRole::SearchPosition(this, pSettler, 1) )
        {
          this->m_iNextSearchTick += 48;
          if ( ++this->m_iWorkTick <= 56 )
          {
            IAnimatedEntity::SetFrame(pSettler, 0);
            IAnimatedEntity::RegisterForLogicUpdate(pSettler, 1);
          }
          else
          {
            CGardenerRole::WorkIsDone(this, pSettler);
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
// Decompiled from void __thiscall CGardenerRole::Init(CGardenerRole *this, IEntity *a1)
void  CGardenerRole::Init(class CSettler * a1) {
  
  this->m_uAttachedSettlerId = IEntity::ID(a1);
  IEntity::SetFlagBits(a1, ENTITY_FLAG_VulnerableMask|ENTITY_FLAG_Selectable);
  CWarMap::AddEntity(a1);
  this->m_iTargetMushroomX = -1;
  this->m_iTargetMushroomY = -1;
  this->m_iEventX = 0;
  this->m_iEventY = 0;
  this->m_iWorkTick = 0;
  this->m_iNextSearchTick = 0;
  this->m_uEntityId = 0;
}


// address=[0x1570ed0]
// Decompiled from void __thiscall CGardenerRole::ConvertEventIntoGoal(  CGardenerRole *this,  CSettler *pSettler,  const struct CEntityEvent *pEvent)
void  CGardenerRole::ConvertEventIntoGoal(class CSettler * pSettler, class CEntityEvent * pEvent) {
  
  unsigned int v3; // eax
  unsigned int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  unsigned int v8; // eax
  int v9; // eax
  int v10; // esi
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  unsigned int v19; // eax
  int v20; // eax
  int v21; // eax
  unsigned int v22; // [esp-Ch] [ebp-48h]
  T_OBJECT_TYPE v23; // [esp-8h] [ebp-44h]
  unsigned int v24; // [esp-8h] [ebp-44h]
  int v25; // [esp-8h] [ebp-44h]
  unsigned int v26; // [esp-8h] [ebp-44h]
  unsigned int v27; // [esp-8h] [ebp-44h]
  int v28; // [esp-8h] [ebp-44h]
  unsigned int v29; // [esp-8h] [ebp-44h]
  int v30; // [esp-8h] [ebp-44h]
  unsigned int v31; // [esp-4h] [ebp-40h]
  int v32; // [esp-4h] [ebp-40h]
  int v33; // [esp-4h] [ebp-40h]
  int m_uHomeEntityId; // [esp-4h] [ebp-40h]
  int v35; // [esp-4h] [ebp-40h]
  unsigned int v36; // [esp-4h] [ebp-40h]
  int v37; // [esp-4h] [ebp-40h]
  int v38; // [esp-4h] [ebp-40h]
  int m_iDataA; // [esp+4h] [ebp-38h]
  int v40; // [esp+8h] [ebp-34h]
  int v41; // [esp+10h] [ebp-2Ch]
  CSettlerMgr::SSettlerInfos *SettlerInfo; // [esp+14h] [ebp-28h]
  DWORD v43; // [esp+18h] [ebp-24h]
  int v44; // [esp+1Ch] [ebp-20h]
  int v45; // [esp+20h] [ebp-1Ch]
  int m_iDataB; // [esp+24h] [ebp-18h]
  unsigned int v47; // [esp+28h] [ebp-14h]
  CVehicle *v48; // [esp+30h] [ebp-Ch]
  IDecoObject *pDeco; // [esp+34h] [ebp-8h]

  switch ( pEvent->m_iEvent )
  {
    case 7:
      m_iDataA = pEvent->m_iDataA;
      IEntity::SetFlagBits(pSettler, ENTITY_FLAG_Selectable);
      IEntity::ClearFlagBits(pSettler, ENTITY_FLAG_ON_BOARD);
      v38 = IEntity::Type(pSettler);
      v29 = IEntity::Type(pSettler);
      v19 = IEntity::Race(pSettler);
      v20 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v19, v29);
      pSettler->NewToDoList(pSettler, v20, v38);
      this->m_iTask = 27;
      v30 = IEntity::ID(pSettler);
      v21 = IEntity::OwnerId(pSettler);
      g_pAI->PostAIEvent(g_pAI, 21, v21, v30, m_iDataA);
      break;
    case 0xD:
      CTrace::Print("CGardenerRole - NewDestinationEx called from ConvertEventIntoGoal-GO_TO_POS");
      this->NewDestinationEx(this, pSettler, &this->m_vTasks, pEvent->m_iDataB, pEvent->m_iDataC, pEvent->m_iDataA);
      break;
    case 0x11:
      if ( this->m_iTargetMushroomX != -1 )
      {
        CWorldManager::ClearFlagBits(this->m_iTargetMushroomX, this->m_iTargetMushroomY, 32);
        this->m_iTargetMushroomX = -1;
        this->m_iTargetMushroomY = -1;
      }
      if ( pEvent->m_iType == 13 && !ISelectableSettlerRole::ProcessGoToPosFerry(this, pSettler, pEvent) )
      {
        if ( this->m_uEntityId )
        {
          pDeco = (IDecoObject *)CDecoObjMgr::GetDecoObjPtr(this->m_uEntityId);
          if ( pDeco && !IDecoObject::IsStaticInstance(pDeco) )
          {
            v31 = pDeco->Amount(pDeco);
            v23 = IEntity::Type(pDeco);
            v22 = IEntity::Y(pDeco);
            v3 = IEntity::X(pDeco);
            CDecoObjMgr::ChangeToStaticInstance(&g_cDecoObjMgr, v3, v22, v23, v31);
          }
          this->m_uEntityId = 0;
        }
        if ( this->m_iTargetMushroomX != -1 )
        {
          CWorldManager::ClearFlagBits(this->m_iTargetMushroomX, this->m_iTargetMushroomY, 32);
          this->m_iTargetMushroomX = -1;
          this->m_iTargetMushroomY = -1;
        }
        v40 = pEvent->m_iDataA;
        m_iDataB = pEvent->m_iDataB;
        v44 = Y16X16::UnpackXFast(m_iDataB);
        v45 = Y16X16::UnpackYFast(m_iDataB);
        if ( (v40 & 4) != 0 )
        {
          v47 = 176;
        }
        else
        {
          this->m_iEventX = v44;
          this->m_iEventY = v45;
          this->m_iNextSearchTick = 0;
          this->m_iWorkTick = 0;
          v47 = 174;
        }
        ISettlerRole::NewDestination(this, pSettler, v44, v45, 0);
        v4 = IEntity::Race(pSettler);
        v5 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v4, v47);
        pSettler->NewToDoList(pSettler, v5, v47);
      }
      break;
    case 0x18:
      v32 = IEntity::Type(pSettler);
      v6 = IEntity::Race(pSettler);
      SettlerInfo = CSettlerMgr::GetSettlerInfo(v6, v32);
      v48 = CVehicleMgr::operator[](pEvent->m_iDataA);
      v7 = IEntity::ID(pSettler);
      v43 = v48->GetMeetingPointXY(v48, SETTLER_OBJ, v7);
      if ( v43 && IEntity::FlagBits(v48, (EntityFlag)&loc_3000000) )
      {
        ISettlerRole::NewDestination(this, pSettler, v43, 0);
        v33 = *std::vector<unsigned short>::operator[](SettlerInfo->g_vAnimLists, 0);
        v24 = *std::vector<unsigned short>::operator[](SettlerInfo->g_vAnimLists, 0);
        v8 = IEntity::Race(pSettler);
        v9 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v8, v24);
        pSettler->NewToDoList(pSettler, v9, v33);
        v10 = IEntity::OwnerId(pSettler);
        if ( v10 == CPlayerManager::GetLocalPlayerId() )
        {
          v11 = IEntity::ID(pSettler);
          CInputProcessor::DeSelectEntity(&g_cInputProcessor, v11);
        }
        v12 = IEntity::ID(pSettler);
        v48->Attach(v48, v12);
        IEntity::ClearFlagBits(pSettler, ENTITY_FLAG_Selectable|ENTITY_FLAG_Selected);
        v13 = IEntity::ID(pSettler);
        ((void (__thiscall *)(CGroupMgr *, int))g_pGroupMgr->DetachEntityFromAllGroups)(g_pGroupMgr, v13);
        m_uHomeEntityId = this->m_uHomeEntityId;
        v25 = IEntity::ID(pSettler);
        v14 = IEntity::OwnerId(pSettler);
        g_pAI->PostAIEvent(g_pAI, 18, v14, v25, m_uHomeEntityId);
      }
      else
      {
        IEntity::SetFlagBits(pSettler, ENTITY_FLAG_Selectable);
        v35 = IEntity::Type(pSettler);
        v26 = IEntity::Type(pSettler);
        v15 = IEntity::Race(pSettler);
        v16 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v15, v26);
        pSettler->NewToDoList(pSettler, v16, v35);
      }
      break;
    case 0x19:
      v41 = pEvent->m_iDataB;
      this->m_uHomeEntityId = 0;
      v36 = Y16X16::UnpackYFast(v41);
      v27 = Y16X16::UnpackXFast(v41);
      v17 = IEntity::ID(pSettler);
      CSettlerMgr::SearchSpaceForSettler(&g_cSettlerMgr, v17, v27, v36);
      CWarMap::AddEntity(pSettler);
      IEntity::SetFlagBits(pSettler, ENTITY_FLAG_Selectable|ENTITY_FLAG_Visible);
      IEntity::ClearFlagBits(pSettler, ENTITY_FLAG_ON_BOARD);
      this->m_iTask = 27;
      v37 = this->m_uHomeEntityId;
      v28 = IEntity::ID(pSettler);
      v18 = IEntity::OwnerId(pSettler);
      g_pAI->PostAIEvent(g_pAI, 21, v18, v28, v37);
      break;
    default:
      if ( !IEntity::FlagBits(pSettler, ENTITY_FLAG_Registered) )
      {
        CTrace::Print("ConvertEventIntoGoal GardenerRole - unknown event %u", pEvent->m_iEvent);
        IAnimatedEntity::RegisterForLogicUpdate(pSettler, 1);
      }
      break;
  }
}


// address=[0x1571440]
// Decompiled from void __thiscall CGardenerRole::WorkIsDone(CGardenerRole *this, CSettler *a2)
void  CGardenerRole::WorkIsDone(class CSettler * a2) {
  
  unsigned int v2; // eax
  int v3; // eax
  unsigned int v4; // [esp-8h] [ebp-Ch]
  int v5; // [esp-4h] [ebp-8h]

  v5 = IEntity::Type(a2);
  v4 = IEntity::Type(a2);
  v2 = IEntity::Race(a2);
  v3 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v2, v4);
  a2->NewToDoList(a2, v3, v5);
}


// address=[0x1571490]
// Decompiled from char __thiscall CGardenerRole::SetFree(CGardenerRole *this, CSettler *a2, int a3)
bool  CGardenerRole::SetFree(class CSettler * a2, int a3) {
  
  unsigned int v3; // eax
  unsigned int v5; // [esp-Ch] [ebp-14h]
  T_OBJECT_TYPE v6; // [esp-8h] [ebp-10h]
  unsigned int v7; // [esp-4h] [ebp-Ch]
  IDecoObject *DecoObjPtr; // [esp+4h] [ebp-4h]

  if ( !this->m_uEntityId )
    return ISettlerRole::SetFree(this, a2, a3);
  DecoObjPtr = (IDecoObject *)CDecoObjMgr::GetDecoObjPtr(this->m_uEntityId);
  if ( DecoObjPtr && !IDecoObject::IsStaticInstance(DecoObjPtr) )
  {
    v7 = DecoObjPtr->Amount(DecoObjPtr);
    v6 = IEntity::Type(DecoObjPtr);
    v5 = IEntity::Y(DecoObjPtr);
    v3 = IEntity::X(DecoObjPtr);
    CDecoObjMgr::ChangeToStaticInstance(&g_cDecoObjMgr, v3, v5, v6, v7);
  }
  this->m_uEntityId = 0;
  return ISettlerRole::SetFree(this, a2, a3);
}


// address=[0x1571520]
// Decompiled from bool __thiscall CGardenerRole::CheckPosition(  CGardenerRole *this,  unsigned int a2,  unsigned int a3,  int iSearchType,  bool a5)
bool  CGardenerRole::CheckPosition(int a2, int a3, int iSearchType, bool a5) {
  
  IDecoObject *v6; // [esp+8h] [ebp-20h]
  int v7; // [esp+18h] [ebp-10h]
  int v8; // [esp+1Ch] [ebp-Ch]
  unsigned __int8 v9; // [esp+20h] [ebp-8h]
  IEntity *v10; // [esp+24h] [ebp-4h]

  v7 = CWorldManager::Index(a2, a3);
  if ( !CWorldManager::InWorld(a2, a3) )
    return 0;
  v9 = iSearchType != 0;
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
  if ( !iSearchType )
  {
    if ( !CWorldManager::InWorld(a2 + 1, a3 - 1) )
      return 0;
    v8 = CWorldManager::ObjectId(a2 + 1, a3 - 1);
    if ( !v8 )
      return 0;
    v10 = CMapObjectMgr::Entity(v8);
    if ( IEntity::ObjType(v10) != DECO_OBJ_2
      || !IEntity::FlagBits(v10, ENTITY_FLAG_Ready)
      || IEntity::Type(v10) != OBJECT_MUSHROOM_DARK1
      && IEntity::Type(v10) != OBJECT_MUSHROOM_DARK2
      && IEntity::Type(v10) != OBJECT_MUSHROOM_DARK3 )
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
  if ( iSearchType == 1 )
    return (!CWorldManager::MapObjectId(a2, a3) || a5) && CWorldManager::FlagBits(v7, 4u) == 4;
  CTrace::Print("GardernerRole: Unknown Searchtype %d", iSearchType);
  return 0;
}


// address=[0x1571710]
// Decompiled from char __thiscall CGardenerRole::SearchPosition(CGardenerRole *this, CSettler *pSettler, int _iSearchType)
bool  CGardenerRole::SearchPosition(class CSettler * pSettler, int _iSearchType) {
  
  int v3; // eax
  int iSettlerX; // esi
  int iSettlerY; // esi
  int v6; // eax
  unsigned int v7; // eax
  int v8; // eax
  unsigned int v9; // eax
  int v10; // eax
  int v12; // [esp-4h] [ebp-40h]
  int v13; // [esp-4h] [ebp-40h]
  int v14; // [esp+4h] [ebp-38h]
  int iCurrentSector; // [esp+Ch] [ebp-30h]
  unsigned int uShortestDistance; // [esp+18h] [ebp-24h]
  int v17; // [esp+1Ch] [ebp-20h]
  int v18; // [esp+20h] [ebp-1Ch]
  unsigned int uDistance; // [esp+20h] [ebp-1Ch]
  int iFoundY; // [esp+24h] [ebp-18h]
  int i; // [esp+28h] [ebp-14h]
  int iFoundX; // [esp+2Ch] [ebp-10h]
  unsigned int iY; // [esp+30h] [ebp-Ch]
  unsigned int iX; // [esp+34h] [ebp-8h]

  iFoundX = -1;
  iFoundY = -1;
  uShortestDistance = 4294967295;
  v17 = 0;
  v12 = IEntity::Y(pSettler);
  v3 = IEntity::X(pSettler);
  iCurrentSector = CWorldManager::SectorId(v3, v12);
  for ( i = this->m_iNextSearchTick; i < this->m_iNextSearchTick + 48; ++i )
  {
    iSettlerX = IEntity::X(pSettler);
    iX = CSpiralOffsets::DeltaX(i) + iSettlerX;
    iSettlerY = IEntity::Y(pSettler);
    iY = CSpiralOffsets::DeltaY(i) + iSettlerY;
    if ( CWorldManager::InWorld(iX, iY) && CWorldManager::SectorId(iX, iY) == iCurrentSector )
    {
      if ( CGardenerRole::CheckPosition(this, iX, iY, _iSearchType, 0) )
      {
        ++v17;
        v18 = CSpiralOffsets::PseudoDistanceSquareEx(iX - this->m_iEventX, iY - this->m_iEventY);
        v13 = iY - IEntity::Y(pSettler);
        v6 = IEntity::X(pSettler);
        uDistance = v18 + 2 * CSpiralOffsets::PseudoDistanceSquareEx(iX - v6, v13);
        if ( uDistance < uShortestDistance )
        {
          uShortestDistance = uDistance;
          iFoundX = iX;
          iFoundY = iY;
        }
      }
      if ( v17 > 31 )
        break;
    }
  }
  if ( iFoundX == -1 )
    return 0;
  if ( this->m_iTargetMushroomX != -1 )
    CWorldManager::ClearFlagBits(this->m_iTargetMushroomX, this->m_iTargetMushroomY, 32);
  v14 = CWorldManager::Index(iFoundX, iFoundY);
  CWorldManager::SetFlagBits(v14, 0x20u);
  this->m_iTargetMushroomX = iFoundX;
  this->m_iTargetMushroomY = iFoundY;
  this->m_iNextSearchTick = 0;
  this->m_iWorkTick = 0;
  if ( _iSearchType )
  {
    if ( _iSearchType == 1 )
    {
      ISettlerRole::NewDestination(this, pSettler, iFoundX, iFoundY, 0);
      v9 = IEntity::Race(pSettler);
      v10 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v9, 0xAFu);
      pSettler->NewToDoList(pSettler, v10, 175);
    }
    else
    {
      CTrace::Print("GardenerRole: Unknown Searchtype %d", _iSearchType);
    }
  }
  else
  {
    ISettlerRole::NewDestination(this, pSettler, iFoundX, iFoundY, 0);
    v7 = IEntity::Race(pSettler);
    v8 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v7, 0xAEu);
    pSettler->NewToDoList(pSettler, v8, 174);
  }
  return 1;
}


