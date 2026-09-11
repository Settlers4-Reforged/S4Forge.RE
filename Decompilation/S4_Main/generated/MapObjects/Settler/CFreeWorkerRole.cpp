#include "CFreeWorkerRole.h"

// Definitions for class CFreeWorkerRole

// address=[0x1400ae0]
// Decompiled from int __cdecl CFreeWorkerRole::New(int a1)
class CPersistence * __cdecl CFreeWorkerRole::New(std::istream & a1) {
  
  if ( operator new(0x38u) != 0 )
  {
    return ((_DWORD (__stdcall *)(int))CFreeWorkerRole::CFreeWorkerRole)(a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x156dc10]
// Decompiled from int __thiscall CFreeWorkerRole::InitWalking(CFreeWorkerRole *this, struct CSettler *a2)
class CWalking *  CFreeWorkerRole::InitWalking(class CSettler * a2) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId(a2);
  v4 = (int)CWalking::Create(1, v2);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 8))(v4, -1, 0);
  return v4;
}


// address=[0x156dc50]
// Decompiled from void __thiscall CFreeWorkerRole::LogicUpdateJob(CFreeWorkerRole *this, CSettler *arg0)
void  CFreeWorkerRole::LogicUpdateJob(class CSettler * arg0) {
  
  CBuilding *v2; // eax
  CPile *v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  unsigned int v7; // eax
  std::list *v8; // eax
  int v9; // eax
  int v10; // esi
  int v11; // esi
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // [esp-8h] [ebp-5Ch]
  unsigned int v17; // [esp-8h] [ebp-5Ch]
  int v18; // [esp-8h] [ebp-5Ch]
  int v19; // [esp-8h] [ebp-5Ch]
  int v20; // [esp-4h] [ebp-58h]
  int v21; // [esp-4h] [ebp-58h]
  int v22; // [esp-4h] [ebp-58h]
  int v23; // [esp-4h] [ebp-58h]
  int v24; // [esp-4h] [ebp-58h]
  int m_iTask; // [esp-4h] [ebp-58h]
  int PileIdWithGood; // [esp+4h] [ebp-50h]
  int v27; // [esp+Ch] [ebp-48h]
  int m_iWalkspeed; // [esp+14h] [ebp-40h]
  unsigned int v29; // [esp+18h] [ebp-3Ch]
  unsigned int v30; // [esp+1Ch] [ebp-38h]
  CSettlerMgr::SSettlerInfos *v31; // [esp+20h] [ebp-34h]
  int v32; // [esp+28h] [ebp-2Ch]
  CSettlerMgr::SSettlerInfos *SettlerInfo; // [esp+2Ch] [ebp-28h]
  int m_iCycleFrames; // [esp+34h] [ebp-20h]
  IEntity *v35; // [esp+3Ch] [ebp-18h]
  int a2; // [esp+40h] [ebp-14h]
  int v37; // [esp+44h] [ebp-10h]
  IEntity *v38; // [esp+48h] [ebp-Ch]
  IEntity *v39; // [esp+4Ch] [ebp-8h]

  if ( this->CheckHome(this, arg0) != 0 )
  {
    ISettlerRole::Update(this, arg0);
    switch ( this->m_iTask )
    {
      case 0:
        this->m_iWalkspeed -= 9;
        if ( this->m_iWalkspeed > 0 )
        {
          IAnimatedEntity::RegisterForLogicUpdate(arg0, 9);
        }
        else
        {
          this->GetNextJob(this, arg0);
        }
        CheckRegister("LogicUpdateJob - GoVirtual - not registered settler", arg0);
        break;
      case 1:
      case 0x10:
        if ( this->m_iWalkspeed <= (int)this->m_uCycleFrames )
        {
          m_iWalkspeed = this->m_iWalkspeed;
        }
        else
        {
          m_iWalkspeed = this->m_uCycleFrames;
        }
        this->m_iWalkspeed -= m_iWalkspeed;
        if ( this->m_iWalkspeed <= 0 )
        {
          if ( this->m_iDestinationPosition != 0 )
          {
            v18 = Y16X16::UnpackYFast(this->m_iDestinationPosition);
            v13 = Y16X16::UnpackXFast(this->m_iDestinationPosition);
            CWorldManager::ClearFlagBits(v13, v18, 32);
          }
          goto LABEL_3;
        }
        IAnimatedEntity::RegisterForLogicUpdate(arg0, m_iWalkspeed);
        break;
      case 2:
        goto LABEL_3;
      case 4:
      case 0x15:
        v37 = this->m_uCycleFrames / 2;
        this->m_iWalkspeed -= v37;
        if ( this->m_iWalkspeed < v37 )
        {
LABEL_3:
          this->GetNextJob(this, arg0);
        }
        else
        {
          v20 = *((unsigned __int8 *)this + 44);
          v2 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_uHomeEntityId);
          PileIdWithGood = CBuilding::GetPileIdWithGood(v2, v20);
          v3 = CPileMgr::operator[](PileIdWithGood);
          CPile::IncreaseUnforeseen(v3, 1);
          *((_BYTE *)this + 44) = 0;
          IAnimatedEntity::RegisterForLogicUpdate(arg0, v37 - 1);
          CheckRegister("LogicUpdateJob - PutGood - not registered settler ", arg0);
        }
        break;
      case 5:
      case 0x16:
        a2 = this->m_uCycleFrames / 2;
        this->m_iWalkspeed -= a2;
        if ( this->m_iWalkspeed < a2 )
        {
          this->GetNextJob(this, arg0);
          CheckRegister("LogicUpdateJob - GetGood ready - not registered settler", arg0);
        }
        else
        {
          v38 = CMapObjectMgr::EntityPtr(this->m_uEntityId);
          if ( v38 == 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\FreeWorkerRole.cpp", 270, "pSupplier != 0") == 1 )
          {
            __debugbreak();
          }
          *((_BYTE *)this + 44) = ((int (__thiscall *)(IEntity *))v38->GetGoodType)(v38);
          if ( (*((_BYTE *)this + 44) == 0 || *((unsigned __int8 *)this + 44) >= 0x2Bu) && BBSupportDbgReport(2, "MapObjects\\Settler\\FreeWorkerRole.cpp", 274, "m_uGood>0 && m_uGood <GOOD_MAX") == 1 )
          {
            __debugbreak();
          }
          if ( *((unsigned __int8 *)this + 44) >= 0x2Bu )
          {
            *((_BYTE *)this + 44) = 0;
          }
          if ( *((_BYTE *)this + 44) != 0 )
          {
            ((void (__thiscall *)(IEntity *, int))v38->Decrease)(v38, 1);
          }
          IAnimatedEntity::RegisterForLogicUpdate(arg0, a2);
          CheckRegister("LogicUpdateJob - GetGood - not registered settler", arg0);
        }
        break;
      case 6:
        IMovingEntity::SetDistance(arg0, 0);
        this->Go(this, arg0);
        break;
      case 0xD:
      case 0x1E:
        if ( this->m_iWalkspeed <= (int)this->m_uCycleFrames )
        {
          m_iCycleFrames = this->m_iWalkspeed;
        }
        else
        {
          m_iCycleFrames = this->m_uCycleFrames;
        }
        this->m_iWalkspeed -= m_iCycleFrames;
        if ( this->m_iWalkspeed <= 0 )
        {
          if ( this->m_uEntityId == 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\FreeWorkerRole.cpp", 315, "m_uEntityId != 0") == 1 )
          {
            __debugbreak();
          }
          v39 = CMapObjectMgr::EntityPtr(this->m_uEntityId);
          if ( v39 == 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\FreeWorkerRole.cpp", 319, "pSupplier != 0") == 1 )
          {
            __debugbreak();
          }
          if ( v39 != 0 )
          {
            *((_BYTE *)this + 44) = ((int (__thiscall *)(IEntity *))v39->GetGoodType)(v39);
            if ( (*((_BYTE *)this + 44) == 0 || *((unsigned __int8 *)this + 44) >= 0x2Bu) && BBSupportDbgReport(2, "MapObjects\\Settler\\FreeWorkerRole.cpp", 325, "m_uGood > 0 && m_uGood < GOOD_MAX") == 1 )
            {
              __debugbreak();
            }
            if ( *((unsigned __int8 *)this + 44) >= 0x2Bu )
            {
              *((_BYTE *)this + 44) = 0;
            }
          }
          else
          {
            *((_BYTE *)this + 44) = 0;
          }
          this->m_uEntityId = 0;
          *((_BYTE *)this + 45) = 0;
          if ( this->m_iDestinationPosition >= 0 )
          {
            v16 = Y16X16::UnpackYFast(this->m_iDestinationPosition);
            v4 = Y16X16::UnpackXFast(this->m_iDestinationPosition);
            CWorldManager::ClearFlagBits(v4, v16, 32);
          }
          if ( *((_BYTE *)this + 44) != 0 )
          {
            ((void (__thiscall *)(IEntity *, int))v39->Take)(v39, 1);
            this->GetNextJob(this, arg0);
          }
          else
          {
            v21 = IEntity::Type(arg0);
            v5 = IEntity::Race(arg0);
            CTrace::Print("FreeworkerRole: Could not get good! Race %d, Type %d", v5, v21);
            this->m_iDestinationPosition = this->m_iStartPosition;
            v22 = IEntity::Type(arg0);
            v6 = IEntity::Race(arg0);
            SettlerInfo = CSettlerMgr::GetSettlerInfo(v6, v22);
            v23 = *std::vector<unsigned short>::operator[](&SettlerInfo->g_vAnimLists, 0);
            v17 = *std::vector<unsigned short>::operator[](&SettlerInfo->g_vAnimLists, 0);
            v7 = IEntity::Race(arg0);
            v8 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v7, v17);
            arg0->NewToDoList(arg0, (int)v8, v23);
          }
        }
        else
        {
          IAnimatedEntity::RegisterForLogicUpdate(arg0, m_iCycleFrames);
        }
        CheckRegister("LogicUpdateJob - ResourceGather - not registered settler", arg0);
        break;
      case 0xE:
        return;
      case 0x19:
        if ( this->m_iWalkspeed <= (int)this->m_uCycleFrames )
        {
          v32 = this->m_iWalkspeed;
        }
        else
        {
          v32 = this->m_uCycleFrames;
        }
        this->m_iWalkspeed -= v32;
        if ( this->m_iWalkspeed <= 0 )
        {
          v24 = IEntity::Type(arg0);
          v9 = IEntity::Race(arg0);
          v31 = CSettlerMgr::GetSettlerInfo(v9, v24);
          v10 = IEntity::X(arg0);
          v29 = v10 - std::vector<CSettlerMgr::SSearchInfos>::operator[](&v31->m_vSearches, 1u)->m_iOffsetX;
          v11 = IEntity::Y(arg0);
          v30 = v11 - std::vector<CSettlerMgr::SSearchInfos>::operator[](&v31->m_vSearches, 1u)->m_iOffsetY;
          if ( debug != 0 && DEBUG_FLAGS[dword_41520C4] != 0 )
          {
            v12 = IEntity::ID(arg0);
            BBSupportTracePrintF(0, "FreeWorker nr %u - Set plant to pos x %u, y %u", v12, v29, v30);
          }
          CDecoObjMgr::AddDecoObjWithoutFlags(&g_cDecoObjMgr, v29, v30, (T_OBJECT_TYPE)*((unsigned __int16 *)this + 23), 0, 0);
          *((_WORD *)this + 23) = 0;
          this->GetNextJob(this, arg0);
        }
        else
        {
          IAnimatedEntity::RegisterForLogicUpdate(arg0, v32);
        }
        CheckRegister("LogicUpdateJob - Plant - not registered settler ", arg0);
        break;
      case 0x1C:
      case 0x1D:
        if ( this->m_iWalkspeed <= (int)this->m_uCycleFrames )
        {
          v27 = this->m_iWalkspeed;
        }
        else
        {
          v27 = this->m_uCycleFrames;
        }
        this->m_iWalkspeed -= v27;
        if ( this->m_iWalkspeed <= 0 )
        {
          v35 = CMapObjectMgr::EntityPtr(this->m_uEntityId);
          if ( v35 != 0 )
          {
            ((void (__thiscall *)(IEntity *, int))v35->Decrease)(v35, 1);
          }
          else if ( BBSupportDbgReportF(1, "MapObjects\\Settler\\FreeWorkerRole.cpp", 479, "CFreeWorkerRole::LogicUpdateJob(): Invalid target entity %i!", this->m_uEntityId) == 1 )
          {
            __debugbreak();
          }
          if ( this->m_iDestinationPosition != 0 )
          {
            v19 = Y16X16::UnpackYFast(this->m_iDestinationPosition);
            v14 = Y16X16::UnpackXFast(this->m_iDestinationPosition);
            CWorldManager::ClearFlagBits(v14, v19, 32);
          }
          this->GetNextJob(this, arg0);
        }
        else
        {
          IAnimatedEntity::RegisterForLogicUpdate(arg0, v27);
        }
        CheckRegister("LogicUpdateJob - Work - not registered settler", arg0);
        break;
      default:
        if ( debug != 0 && DEBUG_FLAGS[dword_41520C4] != 0 )
        {
          m_iTask = this->m_iTask;
          v15 = IEntity::ID(arg0);
          BBSupportTracePrintF(0, "LogicUpdateJob FreeWorker nr %u - unknown task %u", v15, m_iTask);
        }
        break;
    }
  }
}


// address=[0x156e4c0]
// Decompiled from int __fastcall CFreeWorkerRole::UpdateJob(CFreeWorkerRole *this, int a2, struct CSettler *a3)
void  CFreeWorkerRole::UpdateJob(class CSettler * a2) {
  
  int result; // eax
  int v4; // [esp+8h] [ebp-28h]
  unsigned int v5; // [esp+Ch] [ebp-24h]
  unsigned int v6; // [esp+10h] [ebp-20h]
  unsigned int v7; // [esp+14h] [ebp-1Ch]
  int v8; // [esp+20h] [ebp-10h]
  int i; // [esp+28h] [ebp-8h]

  result = (int)this;
  switch ( this->m_iTask )
  {
    case 0:
      if ( this->m_uCycleFrames != 0 )
      {
        v8 = (this->m_uTick + IAnimatedEntity::Frame(a3)) % this->m_uCycleFrames;
        if ( v8 != 0 || this->m_uCycleFrames <= 1u )
        {
          ((void (__stdcall *)(char))IAnimatedEntity::SetFrame)(v8);
        }
        else
        {
          ((void (__stdcall *)(char))IAnimatedEntity::SetFrame)(1);
        }
      }
      else
      {
        ((void (__stdcall *)(char))IAnimatedEntity::SetFrame)(0);
      }
      result = this->m_uTick;
      v4 = result;
      for ( i = 0;
            i < v4;
            ++i )
      {
        this->m_fOffsetX = this->m_fOffsetX + *((float *)this + 12);
        this->m_fOffsetY = this->m_fOffsetY + *((float *)this + 13);
        result = i + 1;
      }
      break;
    case 4:
    case 0x15:
      v7 = IAnimatedEntity::Frame(a3);
      v6 = this->m_uTick;
      if ( v7 <= v6 )
      {
        goto LABEL_18;
      }
      result = ((int (__stdcall *)(char))IAnimatedEntity::SetFrame)(v7 - v6);
      break;
    case 5:
    case 0x16:
      v5 = this->m_uTick + IAnimatedEntity::Frame(a3);
      if ( v5 >= this->m_uCycleFrames )
      {
        if ( this->m_uCycleFrames != 0 )
        {
          result = ((int (__stdcall *)(char))IAnimatedEntity::SetFrame)(this->m_uCycleFrames - 1);
        }
        else
        {
LABEL_18:
          result = ((int (__stdcall *)(char))IAnimatedEntity::SetFrame)(0);
        }
      }
      else
      {
        result = ((int (__stdcall *)(char))IAnimatedEntity::SetFrame)(v5);
      }
      break;
    default:
      return result;
  }
  return result;
}


// address=[0x156e690]
// Decompiled from int __stdcall CFreeWorkerRole::PostLoadInit(IEntity *a1)
void  CFreeWorkerRole::PostLoadInit(class CSettler * a1) {
  
  return ((int (__cdecl *)(CPropertySet *))CWarMap::AddEntity)((CPropertySet *)a1);
}


// address=[0x156e6b0]
// Decompiled from char *__thiscall CFreeWorkerRole::CFreeWorkerRole(char *this, int a2)
 CFreeWorkerRole::CFreeWorkerRole(std::istream & a2) {
  
  unsigned int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  char *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  ISettlerRole::ISettlerRole((ISettlerRole *)this, (struct std::istream *)a2);
  v6 = 0;
  *(_DWORD *)v5 = &CFreeWorkerRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CFreeWorkerRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a2, (unsigned __int8 *)v5 + 44);
  operator^<unsigned char>(a2, (unsigned __int8 *)v5 + 45);
  operator^<float>(a2, (int)(v5 + 48));
  operator^<float>(a2, (int)(v5 + 52));
  operator^<unsigned short>(a2, (unsigned __int16 *)v5 + 23);
  if ( (unsigned __int8)v5[44] >= 0x2Bu && BBSupportDbgReport(2, "MapObjects\\Settler\\FreeWorkerRole.cpp", 117, "m_uGood < GOOD_MAX") == 1 )
  {
    __debugbreak();
  }
  return v5;
}


// address=[0x156e7f0]
// Decompiled from int __thiscall CFreeWorkerRole::Store(struct CPersistence *this, struct std::ostream *a2)
void  CFreeWorkerRole::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  struct CPersistence *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  ISettlerRole::Store((ISettlerRole *)this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, (unsigned int *)&v3);
  operator^<unsigned char>(a2, (unsigned __int8 *)&v4[11]);
  operator^<unsigned char>(a2, (unsigned __int8 *)&v4[11].__vftable + 1);
  operator^<float>(a2, (float *)&v4[12]);
  operator^<float>(a2, (float *)&v4[13]);
  return operator^<unsigned short>(a2, (WORD *)&v4[11].__vftable + 1);
}


// address=[0x156ffc0]
// Decompiled from int __thiscall CFreeWorkerRole::ClassID(CFreeWorkerRole *this)
unsigned long  CFreeWorkerRole::ClassID(void)const {
  
  return CFreeWorkerRole::m_iClassID;
}


// address=[0x156ffe0]
// Decompiled from int __thiscall CFreeWorkerRole::GetSettlerRole(CFreeWorkerRole *this)
int  CFreeWorkerRole::GetSettlerRole(void)const {
  
  return 5;
}


// address=[0x1588600]
// Decompiled from int __cdecl CFreeWorkerRole::Load(struct std::istream *a1)
class CFreeWorkerRole * __cdecl CFreeWorkerRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)((void **(__cdecl *)(struct std::istream *, struct TypeDescriptor *))CPersistence::New)(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CFreeWorkerRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bec0]
// [Decompilation failed for static unsigned long CFreeWorkerRole::m_iClassID]

// address=[0x156e890]
// Decompiled from CFreeWorkerRole *__thiscall CFreeWorkerRole::CFreeWorkerRole(CFreeWorkerRole *this)
 CFreeWorkerRole::CFreeWorkerRole(void) {
  
  ISettlerRole::ISettlerRole(this);
  this->__vftable = (ISettlerRole_vtbl *)&CFreeWorkerRole::_vftable_;
  *((_BYTE *)this + 44) = 0;
  *((_BYTE *)this + 45) = 0;
  *((_WORD *)this + 23) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  return this;
}


// address=[0x156e8e0]
// Decompiled from ISettlerRole *__thiscall CFreeWorkerRole::~CFreeWorkerRole(CFreeWorkerRole *this)
 CFreeWorkerRole::~CFreeWorkerRole(void) {
  
  this->__vftable = (ISettlerRole_vtbl *)&CFreeWorkerRole::_vftable_;
  return ISettlerRole::~ISettlerRole(this);
}


// address=[0x156e900]
// Decompiled from int __thiscall CFreeWorkerRole::GetNextJob(CFreeWorkerRole *this, struct CSettler *a2)
void  CFreeWorkerRole::GetNextJob(class CSettler * a2) {
  
  int result; // eax

  IMovingEntity::IncToDoListIter(a2);
  result = IMovingEntity::IsEndIter(a2);
  if ( (_BYTE)result == 0 )
  {
    return ((int (__thiscall *)(CFreeWorkerRole *, struct CSettler *))this->TakeJob)(this, a2);
  }
  this->m_iTask = 17;
  return result;
}


// address=[0x156e940]
// Decompiled from void __thiscall CFreeWorkerRole::TakeJob(ISettlerRole *this, struct CSettler *a2)
void  CFreeWorkerRole::TakeJob(class CSettler * a2) {
  
  int TickCounter; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  CMFCToolBarButton *v9; // eax
  int v10; // eax
  CBuilding *v11; // eax
  int v12; // eax
  CBuilding *v13; // eax
  int v14; // [esp+0h] [ebp-78h]
  int v15; // [esp+0h] [ebp-78h]
  int v16; // [esp+0h] [ebp-78h]
  int v17; // [esp+4h] [ebp-74h]
  int v18; // [esp+4h] [ebp-74h]
  int v19; // [esp+4h] [ebp-74h]
  int v20; // [esp+4h] [ebp-74h]
  int v21; // [esp+4h] [ebp-74h]
  int v22; // [esp+4h] [ebp-74h]
  int v23; // [esp+14h] [ebp-64h]
  int PileIdWithGood; // [esp+18h] [ebp-60h]
  int v25; // [esp+1Ch] [ebp-5Ch] BYREF
  int v26; // [esp+20h] [ebp-58h] BYREF
  float v27; // [esp+24h] [ebp-54h]
  float v28; // [esp+28h] [ebp-50h]
  float v29; // [esp+2Ch] [ebp-4Ch]
  CMFCToolBarButton *v30; // [esp+30h] [ebp-48h]
  int v31; // [esp+34h] [ebp-44h]
  int v32; // [esp+38h] [ebp-40h]
  int v33; // [esp+3Ch] [ebp-3Ch]
  int v34; // [esp+40h] [ebp-38h]
  int v35; // [esp+44h] [ebp-34h]
  float v36; // [esp+48h] [ebp-30h]
  float v37; // [esp+4Ch] [ebp-2Ch]
  float v38; // [esp+50h] [ebp-28h]
  int SettlerInfo; // [esp+54h] [ebp-24h]
  const struct CEntityTask *ActualTask; // [esp+58h] [ebp-20h]
  int v41; // [esp+5Ch] [ebp-1Ch]
  float v42; // [esp+60h] [ebp-18h]
  int v43; // [esp+64h] [ebp-14h]
  int v44; // [esp+68h] [ebp-10h]
  int v45; // [esp+6Ch] [ebp-Ch]
  int v46; // [esp+70h] [ebp-8h]
  CFreeWorkerRole *v47; // [esp+74h] [ebp-4h]

  v47 = (CFreeWorkerRole *)this;
  TickCounter = CStateGame::GetTickCounter(g_pGame);
  IAnimatedEntity::SetLastUpdateTick(a2, TickCounter);
  ActualTask = IMovingEntity::GetActualTask(a2);
  ISettlerRole::InitCommonTaskValues(v47, a2, ActualTask);
  v41 = v47->m_iTask;
  switch ( v41 )
  {
    case 0:
      if ( v47->CheckHome(v47, a2) != 0 )
      {
        ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(10);
        v38 = (float)v47->m_iDestinationOffsetY * 255.0;
        v29 = (float)((float)v47->m_iDestinationOffsetX * 255.0) - (float)(0.5 * v38);
        v37 = v29 - (float)(v47->m_fOffsetX + 127.5);
        v42 = v38 - (float)(v47->m_fOffsetY + 255.0);
        v28 = abs(v42);
        v26 = (int)(float)((float)(v28 * 0.0039215689) + 0.5);
        v27 = abs(v37 - (float)(0.5 * v42));
        v25 = (int)((float)(v27 * 0.0039215689) + 0.5);
        v44 = 9 * *BB::Max<int>(&v25, &v26);
        if ( v44 < 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\FreeWorkerRole.cpp", 930, "iJobCounter >= 0") == 1 )
        {
          __debugbreak();
        }
        if ( v44 >= 128 && BBSupportDbgReport(2, "MapObjects\\Settler\\FreeWorkerRole.cpp", 931, "iJobCounter < 128") == 1 )
        {
          __debugbreak();
        }
        v47->m_iWalkspeed = v44;
        if ( v44 <= 0 )
        {
          *(_DWORD *)&v47[1].m_iTask = 0;
          *(_DWORD *)&v47[1].m_uTick = 0;
          ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
        }
        else
        {
          v36 = 1.0 / (float)v44;
          *(float *)&v47[1].m_iTask = v37 * v36;
          *(float *)&v47[1].m_uTick = v42 * v36;
          ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(9);
        }
      }
      break;
    case 1:
    case 2:
    case 13:
    case 16:
    case 30:
      if ( v47->CheckHome(v47, a2) != 0 )
      {
        ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(10);
        if ( v47->m_uCycleFrames <= 1u )
        {
          v17 = IEntity::Race(a2);
          v14 = ActualTask->m_iJobNr;
          v3 = IEntity::Type(a2);
          BBSupportTracePrintF(3, "### CFreeWorkerRole::TakeJob(): Invalid cycle frames %i! Settler type %i, job %i, race %i.", v47->m_uCycleFrames, v3, v14, v17);
          ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
        }
        else
        {
          ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(v47->m_uCycleFrames - 1);
        }
        if ( IEntity::Type(a2) == 9 && IAnimatedEntity::JobPart(a2) == 82 )
        {
          v46 = 0;
          v35 = IEntity::X(a2);
          v34 = IEntity::Y(a2);
          v31 = 0;
          v43 = 0;
          while ( v46 < 19 )
          {
            v32 = v35 + CSpiralOffsets::DeltaX(v46);
            v33 = v34 + CSpiralOffsets::DeltaY(v46);
            v45 = CWorldManager::Index(v32, v33);
            if ( CWorldManager::IsWater(v45) || (CWorldManager::Ground(v45) & 0xF0) == 0x60 )
            {
              v31 = v45;
              v43 = CSpiralOffsets::Direction(v46);
            }
            if ( CWorldManager::ResourceType(v45) == 0 && CWorldManager::ResourceAmount(v45, 0) != 0 )
            {
              v43 = CSpiralOffsets::Direction(v46);
              break;
            }
            ++v46;
          }
          IMovingEntity::SetDirection(a2, v43);
        }
      }
      break;
    case 4:
    case 21:
      if ( v47->CheckHome(v47, a2) != 0 )
      {
        ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(10);
        ((void (__stdcall *)(char))IAnimatedEntity::SetFrame)(v47->m_uCycleFrames - 1);
        ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(v47->m_iWalkspeed / 2);
      }
      break;
    case 5:
    case 22:
      if ( v47->CheckHome(v47, a2) != 0 )
      {
        ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(10);
        ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(v47->m_iWalkspeed / 2 - 1);
      }
      break;
    case 10:
      ((void (__stdcall *)(char))IAnimatedEntity::SetFrame)(1);
      IMovingEntity::WalkToXY(a2, v47->m_iDestinationPosition, 0);
      v47->m_iTask = 6;
      ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(5);
      v47->Go(v47, a2);
      break;
    case 14:
      if ( v47->CheckHome(v47, a2) != 0 )
      {
        ((void (__stdcall *)(char))IAnimatedEntity::SetFrame)(0);
        v9 = (CMFCToolBarButton *)((CMFCToolBarButton *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(v47->m_uHomeEntityId);
        v10 = CBuilding::DoorPackedXY((CBuilding *)v9);
        IMovingEntity::WalkToXY(a2, v10, 0);
        v47->m_iTask = 6;
        ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(5);
        v47->Go(v47, a2);
      }
      break;
    case 17:
      ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(0);
      ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
      break;
    case 19:
      if ( v47->CheckHome(v47, a2) != 0 )
      {
        v21 = LOBYTE(v47[1].__vftable);
        v11 = (CBuilding *)((CBuilding *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(v47->m_uHomeEntityId);
        PileIdWithGood = CBuilding::GetPileIdWithGood(v11, v21);
        v12 = (int)CMapObjectMgr::EntityPtr(PileIdWithGood);
        v23 = IEntity::PackedXY((IEntity *)v12);
        IMovingEntity::WalkToXY(a2, v23, 4096);
        v47->m_iTask = 6;
        ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(5);
        v47->Go(v47, a2);
      }
      break;
    case 24:
      if ( v47->CheckHome(v47, a2) != 0 )
      {
        v47->m_fOffsetX = 0.0;
        v47->m_fOffsetY = 0.0;
        v47->m_iDestinationPosition = 0;
        BYTE1(v47[1].__vftable) = 0;
        ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(10);
        v22 = ((int (__stdcall *)())IEntity::ID)();
        v13 = (CBuilding *)((CBuilding *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(v47->m_uHomeEntityId);
        CBuilding::SettlerEnter(v13, v22);
      }
      break;
    case 25:
      if ( v47->CheckHome(v47, a2) != 0 )
      {
        if ( v47->m_uCycleFrames <= 1u && BBSupportDbgReport(2, "MapObjects\\Settler\\FreeWorkerRole.cpp", 817, "m_iCycleFrames > 1") == 1 )
        {
          __debugbreak();
        }
        goto LABEL_28;
      }
      break;
    case 28:
    case 29:
      if ( v47->CheckHome(v47, a2) != 0 )
      {
        if ( CFreeWorkerRole::CheckResource(v47, a2, 0) == v47->m_uEntityId )
        {
          BYTE1(v47[1].__vftable) = 1;
          if ( v47->m_uCycleFrames <= 1u && BBSupportDbgReport(2, "MapObjects\\Settler\\FreeWorkerRole.cpp", 861, "m_iCycleFrames > 1") == 1 )
          {
            __debugbreak();
          }
LABEL_28:
          ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(10);
          ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(v47->m_uCycleFrames - 1);
        }
        else
        {
          v18 = v47->m_uEntityId;
          v15 = IEntity::Race(a2);
          v4 = IEntity::Type(a2);
          CTrace::Print("Freeworkerrole: Working entity differs from stored entity! Should not happen! Settler %u, Race %u, Entity %u", v4, v15, v18);
          v19 = IEntity::Type(a2);
          v5 = IEntity::Race(a2);
          SettlerInfo = (int)CSettlerMgr::GetSettlerInfo(v5, v19);
          v30 = (CMFCToolBarButton *)((CMFCToolBarButton *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(v47->m_uHomeEntityId);
          v6 = CBuilding::DoorPackedXY((CBuilding *)v30);
          ISettlerRole::NewDestination(v47, a2, v6, 0);
          v20 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(_DWORD))std::vector<unsigned short>::operator[])(0);
          v16 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(_DWORD))std::vector<unsigned short>::operator[])(0);
          v7 = IEntity::Race(a2);
          v8 = ((int (__stdcall *)(int, int))CEntityToDoListMgr::SettlerJobList)(v7, v16);
          a2->NewToDoList(a2, v8, v20);
        }
      }
      break;
    default:
      CTrace::Print("FreeWorkerJob - TakeJob unknown task");
      break;
  }
}


// address=[0x156f1e0]
// Decompiled from int __thiscall CFreeWorkerRole::Init(int this, IEntity *a2)
void  CFreeWorkerRole::Init(class CSettler * a2) {
  
  int result; // eax

  CWarMap::AddEntity(a2);
  *(_DWORD *)(this + 36) = 0;
  *(_DWORD *)(this + 40) = 0;
  result = this;
  *(_BYTE *)(this + 45) = 0;
  *(_BYTE *)(this + 44) = 0;
  return result;
}


// address=[0x156f220]
// Decompiled from int __thiscall CFreeWorkerRole::ConvertEventIntoGoal(CFreeWorkerRole *this, struct CSettler *a2, struct CEntityEvent *a3)
void  CFreeWorkerRole::ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3) {
  
  int result; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // [esp-8h] [ebp-20h]
  int v15; // [esp-8h] [ebp-20h]
  int v16; // [esp-8h] [ebp-20h]
  int v17; // [esp-4h] [ebp-1Ch]
  int v18; // [esp-4h] [ebp-1Ch]
  int v19; // [esp-4h] [ebp-1Ch]
  int v20; // [esp-4h] [ebp-1Ch]
  int v21; // [esp-4h] [ebp-1Ch]
  int v22; // [esp-4h] [ebp-1Ch]
  CMFCToolBarButton *v23; // [esp+Ch] [ebp-Ch]

  switch ( a3->m_iEvent )
  {
    case 1:
      v17 = IEntity::Type(a2);
      v4 = IEntity::Race(a2);
      CSettlerMgr::GetSettlerInfo(v4, v17);
      v23 = (CMFCToolBarButton *)((CMFCToolBarButton *(__stdcall *)(int))CBuildingMgr::operator[])(a3->m_iDataA);
      this->m_uHomeEntityId = ((int (__stdcall *)())IEntity::ID)();
      result = ((int (__thiscall *)(CFreeWorkerRole *, struct CSettler *))this->CheckHome)(this, a2);
      if ( (_BYTE)result != 0 )
      {
        v5 = CBuilding::DoorPackedXY((CBuilding *)v23);
        ISettlerRole::NewDestination(this, a2, v5, 0);
        v18 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(_DWORD))std::vector<unsigned short>::operator[])(0);
        v14 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(_DWORD))std::vector<unsigned short>::operator[])(0);
        v6 = IEntity::Race(a2);
        v7 = ((int (__stdcall *)(int, int))CEntityToDoListMgr::SettlerJobList)(v6, v14);
        result = a2->NewToDoList(a2, v7, v18);
      }
      break;
    case 5:
      result = this->CheckHome(this, a2);
      if ( (_BYTE)result != 0 )
      {
        v21 = IEntity::Type(a2);
        v11 = IEntity::Race(a2);
        CSettlerMgr::GetSettlerInfo(v11, v21);
        ISettlerRole::NewDestination(this, a2, a3->m_iDataC, 0);
        if ( IEntity::Type(a2) != 10 && IEntity::Type(a2) != 9 )
        {
          this->SetEntity(this, a3->m_iDataB);
        }
        v22 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(int))std::vector<unsigned short>::operator[])(1);
        v16 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(int))std::vector<unsigned short>::operator[])(1);
        v12 = IEntity::Race(a2);
        v13 = ((int (__stdcall *)(int, int))CEntityToDoListMgr::SettlerJobList)(v12, v16);
        result = a2->NewToDoList(a2, v13, v22);
      }
      break;
    case 6:
      result = ((int (__thiscall *)(CFreeWorkerRole *, struct CSettler *))this->CheckHome)(this, a2);
      if ( (_BYTE)result != 0 )
      {
        *((_WORD *)this + 23) = a3->m_iDataB;
        v19 = IEntity::Type(a2);
        v8 = IEntity::Race(a2);
        CSettlerMgr::GetSettlerInfo(v8, v19);
        ISettlerRole::NewDestination(this, a2, a3->m_iDataC, 0);
        v20 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(int))std::vector<unsigned short>::operator[])(2);
        v15 = *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(int))std::vector<unsigned short>::operator[])(2);
        v9 = IEntity::Race(a2);
        v10 = ((int (__stdcall *)(int, int))CEntityToDoListMgr::SettlerJobList)(v9, v15);
        result = a2->NewToDoList(a2, v10, v20);
      }
      break;
    case 9:
      if ( this->m_iTask == 17 )
      {
        this->SetFree(this, a2, a3->m_iDataC);
      }
      result = IEntity::FlagBits(a2, ENTITY_FLAG_Registered);
      if ( result == 0 )
      {
        result = ((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
      }
      break;
    default:
      result = IEntity::FlagBits(a2, ENTITY_FLAG_Registered);
      if ( result == 0 )
      {
        CTrace::Print("ConvertEventIntoGoal FreeWorkerRole - unknown event %u", a3->m_iEvent);
        result = ((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
      }
      break;
  }
  return result;
}


// address=[0x156f520]
// Decompiled from int __thiscall CFreeWorkerRole::CheckResource(CFreeWorkerRole *this, IEntity *a2, unsigned int a3)
int  CFreeWorkerRole::CheckResource(class CSettler * a2, int a3) {
  
  int v3; // eax
  int v5; // [esp-4h] [ebp-20h]
  int v6; // [esp+8h] [ebp-14h]
  int v7; // [esp+Ch] [ebp-10h]
  int m_iU7; // [esp+10h] [ebp-Ch]
  int m_iU6; // [esp+14h] [ebp-8h]
  CSettlerMgr::SSettlerInfos *SettlerInfo; // [esp+18h] [ebp-4h]

  v5 = IEntity::Type(a2);
  v3 = IEntity::Race(a2);
  SettlerInfo = CSettlerMgr::GetSettlerInfo(v3, v5);
  m_iU6 = std::vector<CSettlerMgr::SSearchInfos>::operator[](&SettlerInfo->m_vSearches, a3)->m_iOffsetX;
  m_iU7 = std::vector<CSettlerMgr::SSearchInfos>::operator[](&SettlerInfo->m_vSearches, a3)->m_iOffsetY;
  v6 = IEntity::X(a2) - m_iU6;
  v7 = IEntity::Y(a2) - m_iU7;
  return CWorldManager::ObjectId(v6, v7);
}


// address=[0x156f5b0]
// Decompiled from int __stdcall CFreeWorkerRole::CheckSpaceForPlant(IEntity *a1)
int  CFreeWorkerRole::CheckSpaceForPlant(class CSettler * a1) {
  
  int v1; // eax
  int v3; // [esp-4h] [ebp-20h]
  int v4; // [esp+4h] [ebp-18h]
  int v5; // [esp+8h] [ebp-14h]
  int v6; // [esp+Ch] [ebp-10h]
  int m_iU6; // [esp+10h] [ebp-Ch]
  CSettlerMgr::SSettlerInfos *SettlerInfo; // [esp+18h] [ebp-4h]

  v3 = IEntity::Type(a1);
  v1 = IEntity::Race(a1);
  SettlerInfo = CSettlerMgr::GetSettlerInfo(v1, v3);
  if ( std::vector<CSettlerMgr::SSearchInfos>::operator[](&SettlerInfo->m_vSearches, 0)->m_pSearchFkt == 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\FreeWorkerRole.cpp", 1344, "pSearchFkt != 0") == 1 )
  {
    __debugbreak();
  }
  m_iU6 = std::vector<CSettlerMgr::SSearchInfos>::operator[](&SettlerInfo->m_vSearches, 1u)->m_iOffsetX;
  v6 = std::vector<CSettlerMgr::SSearchInfos>::operator[](&SettlerInfo->m_vSearches, 1u)->m_iOffsetX;
  v4 = IEntity::X(a1) - m_iU6;
  v5 = IEntity::Y(a1) - v6;
  return CWorldManager::ObjectId(v4, v5);
}


// address=[0x156f670]
// Decompiled from char __thiscall CFreeWorkerRole::SetFree(CFreeWorkerRole *this, struct CSettler *a2, int a3)
bool  CFreeWorkerRole::SetFree(class CSettler * a2, int a3) {
  
  int v3; // eax
  int v4; // eax
  int v5; // esi
  int v6; // esi
  int v7; // eax
  int v8; // eax
  int v10; // [esp-Ch] [ebp-24h]
  int v11; // [esp-Ch] [ebp-24h]
  int v12; // [esp-8h] [ebp-20h]
  unsigned int v13; // [esp-8h] [ebp-20h]
  int v14; // [esp-4h] [ebp-1Ch]
  int v15; // [esp-4h] [ebp-1Ch]
  int v16; // [esp+4h] [ebp-14h]
  unsigned __int16 *DecoObjPtr; // [esp+10h] [ebp-8h]

  if ( *((_BYTE *)this + 45) == 0 )
  {
    if ( this->m_uEntityId != 0 )
    {
      DecoObjPtr = (unsigned __int16 *)CDecoObjMgr::GetDecoObjPtr(this->m_uEntityId);
      if ( DecoObjPtr != 0 && !IDecoObject::IsStaticInstance((IDecoObject *)DecoObjPtr) )
      {
        v14 = (*(int (__thiscall **)(unsigned __int16 *))(*(_DWORD *)DecoObjPtr + 40))(DecoObjPtr);
        v12 = IEntity::Type((IEntity *)DecoObjPtr);
        v10 = IEntity::Y(DecoObjPtr);
        v3 = IEntity::X(DecoObjPtr);
        CDecoObjMgr::ChangeToStaticInstance(&g_cDecoObjMgr, v3, v10, (T_OBJECT_TYPE)v12, v14);
      }
      this->m_uEntityId = 0;
    }
    IEntity::SetFlagBits(a2, ENTITY_FLAG_Visible);
  }
  if ( *((_WORD *)this + 23) != 0 )
  {
    v15 = IEntity::Type(a2);
    v4 = IEntity::Race(a2);
    CSettlerMgr::GetSettlerInfo(v4, v15);
    v5 = Y16X16::UnpackXFast(this->m_iDestinationPosition);
    v16 = v5 - *(char *)(((int (__stdcall *)(int))std::vector<CSettlerMgr::SSearchInfos>::operator[])(1) + 5);
    v6 = Y16X16::UnpackYFast(this->m_iDestinationPosition);
    v7 = ((int (__stdcall *)(int))std::vector<CSettlerMgr::SSearchInfos>::operator[])(1);
    CDecoObjMgr::ClearFlagsForObject(&g_cDecoObjMgr, v16, v6 - *(char *)(v7 + 6), *((unsigned __int16 *)this + 23), 0);
    *((_WORD *)this + 23) = 0;
  }
  if ( *((_BYTE *)this + 44) != 0 )
  {
    if ( *((unsigned __int8 *)this + 44) >= 0x2Bu && BBSupportDbgReport(2, "MapObjects\\Settler\\FreeWorkerRole.cpp", 1282, "m_uGood < GOOD_MAX") == 1 )
    {
      __debugbreak();
    }
    if ( *((unsigned __int8 *)this + 44) < 0x2Bu )
    {
      v13 = *((unsigned __int8 *)this + 44);
      v11 = IEntity::Y(a2);
      v8 = IEntity::X(a2);
      CPileMgr::SearchSpaceForGoods(&g_cPileMgr, v8, v11, v13, 1u);
    }
    *((_BYTE *)this + 44) = 0;
  }
  return ISettlerRole::SetFree(this, a2, a3);
}


