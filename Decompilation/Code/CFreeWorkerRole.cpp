#include "CFreeWorkerRole.h"

// Definitions for class CFreeWorkerRole

// address=[0x1400ae0]
// Decompiled from int __cdecl CFreeWorkerRole::New(int a1)

static class CPersistence * __cdecl CFreeWorkerRole::New(std::istream &) {
  
  if ( operator new(0x38u) )
    return CFreeWorkerRole::CFreeWorkerRole(a1);
  else
    return 0;
}


// address=[0x156dc10]
// Decompiled from int __thiscall CFreeWorkerRole::InitWalking(CFreeWorkerRole *this, struct CSettler *a2)

class CWalking *  CFreeWorkerRole::InitWalking(class CSettler *) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  v4 = CWalking::Create(1, v2);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 8))(v4, -1, 0);
  return v4;
}


// address=[0x156dc50]
// Decompiled from void __thiscall CFreeWorkerRole::LogicUpdateJob(char *this, CMFCCaptionButton *a2)

void  CFreeWorkerRole::LogicUpdateJob(class CSettler *) {
  
  CBuilding *v2; // eax
  unsigned __int8 *v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // esi
  int v11; // esi
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // [esp-8h] [ebp-5Ch]
  int v17; // [esp-8h] [ebp-5Ch]
  int v18; // [esp-8h] [ebp-5Ch]
  int v19; // [esp-8h] [ebp-5Ch]
  int v20; // [esp-4h] [ebp-58h]
  int v21; // [esp-4h] [ebp-58h]
  int v22; // [esp-4h] [ebp-58h]
  int v23; // [esp-4h] [ebp-58h]
  int v24; // [esp-4h] [ebp-58h]
  int v25; // [esp-4h] [ebp-58h]
  int PileIdWithGood; // [esp+4h] [ebp-50h]
  int v27; // [esp+Ch] [ebp-48h]
  int v28; // [esp+14h] [ebp-40h]
  int v29; // [esp+18h] [ebp-3Ch]
  int v30; // [esp+1Ch] [ebp-38h]
  int v31; // [esp+28h] [ebp-2Ch]
  int v32; // [esp+34h] [ebp-20h]
  int v33; // [esp+3Ch] [ebp-18h]
  int v34; // [esp+40h] [ebp-14h]
  int v35; // [esp+44h] [ebp-10h]
  int v36; // [esp+48h] [ebp-Ch]
  int v37; // [esp+4Ch] [ebp-8h]

  if ( (*(unsigned __int8 (__thiscall **)(char *, CMFCCaptionButton *))(*(_DWORD *)this + 124))(this, a2) )
  {
    ISettlerRole::Update(a2);
    switch ( this[4] )
    {
      case 0:
        this[6] -= 9;
        if ( this[6] > 0 )
          IAnimatedEntity::RegisterForLogicUpdate(9);
        else
          (*(void (__thiscall **)(char *, CMFCCaptionButton *))(*(_DWORD *)this + 36))(this, a2);
        CheckRegister("LogicUpdateJob - GoVirtual - not registered settler", a2);
        break;
      case 1:
      case 16:
        if ( this[6] <= (int)(unsigned __int8)this[7] )
          v28 = this[6];
        else
          v28 = (unsigned __int8)this[7];
        this[6] -= v28;
        if ( this[6] <= 0 )
        {
          if ( *((_DWORD *)this + 6) )
          {
            v18 = Y16X16::UnpackYFast(*((_DWORD *)this + 6));
            v13 = Y16X16::UnpackXFast(*((_DWORD *)this + 6));
            CWorldManager::ClearFlagBits(v13, v18, 32);
          }
          goto LABEL_3;
        }
        IAnimatedEntity::RegisterForLogicUpdate(v28);
        break;
      case 2:
        goto LABEL_3;
      case 4:
      case 21:
        v35 = (unsigned __int8)this[7] / 2;
        this[6] -= v35;
        if ( this[6] < v35 )
        {
LABEL_3:
          (*(void (__thiscall **)(char *, CMFCCaptionButton *))(*(_DWORD *)this + 36))(this, a2);
        }
        else
        {
          v20 = (unsigned __int8)this[44];
          v2 = (CBuilding *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
          PileIdWithGood = CBuilding::GetPileIdWithGood(v2, v20);
          v3 = CPileMgr::operator[](PileIdWithGood);
          CPile::IncreaseUnforeseen((CPile *)v3, 1);
          this[44] = 0;
          IAnimatedEntity::RegisterForLogicUpdate(v35 - 1);
          CheckRegister("LogicUpdateJob - PutGood - not registered settler ", a2);
        }
        break;
      case 5:
      case 22:
        v34 = (unsigned __int8)this[7] / 2;
        this[6] -= v34;
        if ( this[6] < v34 )
        {
          (*(void (__thiscall **)(char *, CMFCCaptionButton *))(*(_DWORD *)this + 36))(this, a2);
          CheckRegister("LogicUpdateJob - GetGood ready - not registered settler", a2);
        }
        else
        {
          v36 = CMapObjectMgr::EntityPtr(*((unsigned __int16 *)this + 17));
          if ( !v36 && BBSupportDbgReport(2, "MapObjects\\Settler\\FreeWorkerRole.cpp", 270, "pSupplier != 0") == 1 )
            __debugbreak();
          this[44] = (*(int (__thiscall **)(int))(*(_DWORD *)v36 + 60))(v36);
          if ( (!this[44] || (unsigned __int8)this[44] >= 0x2Bu)
            && BBSupportDbgReport(2, "MapObjects\\Settler\\FreeWorkerRole.cpp", 274, "m_uGood>0 && m_uGood <GOOD_MAX") == 1 )
          {
            __debugbreak();
          }
          if ( (unsigned __int8)this[44] >= 0x2Bu )
            this[44] = 0;
          if ( this[44] )
            (*(void (__thiscall **)(int, int))(*(_DWORD *)v36 + 32))(v36, 1);
          IAnimatedEntity::RegisterForLogicUpdate(v34);
          CheckRegister("LogicUpdateJob - GetGood - not registered settler", a2);
        }
        break;
      case 6:
        IMovingEntity::SetDistance(a2, 0);
        (*(void (__thiscall **)(char *, CMFCCaptionButton *))(*(_DWORD *)this + 16))(this, a2);
        break;
      case 13:
      case 30:
        if ( this[6] <= (int)(unsigned __int8)this[7] )
          v32 = this[6];
        else
          v32 = (unsigned __int8)this[7];
        this[6] -= v32;
        if ( this[6] <= 0 )
        {
          if ( !*((_WORD *)this + 17)
            && BBSupportDbgReport(2, "MapObjects\\Settler\\FreeWorkerRole.cpp", 315, "m_uEntityId != 0") == 1 )
          {
            __debugbreak();
          }
          v37 = CMapObjectMgr::EntityPtr(*((unsigned __int16 *)this + 17));
          if ( !v37 && BBSupportDbgReport(2, "MapObjects\\Settler\\FreeWorkerRole.cpp", 319, "pSupplier != 0") == 1 )
            __debugbreak();
          if ( v37 )
          {
            this[44] = (*(int (__thiscall **)(int))(*(_DWORD *)v37 + 60))(v37);
            if ( (!this[44] || (unsigned __int8)this[44] >= 0x2Bu)
              && BBSupportDbgReport(
                   2,
                   "MapObjects\\Settler\\FreeWorkerRole.cpp",
                   325,
                   "m_uGood > 0 && m_uGood < GOOD_MAX") == 1 )
            {
              __debugbreak();
            }
            if ( (unsigned __int8)this[44] >= 0x2Bu )
              this[44] = 0;
          }
          else
          {
            this[44] = 0;
          }
          *((_WORD *)this + 17) = 0;
          this[45] = 0;
          if ( *((int *)this + 6) >= 0 )
          {
            v16 = Y16X16::UnpackYFast(*((_DWORD *)this + 6));
            v4 = Y16X16::UnpackXFast(*((_DWORD *)this + 6));
            CWorldManager::ClearFlagBits(v4, v16, 32);
          }
          if ( this[44] )
          {
            (*(void (__thiscall **)(int, int))(*(_DWORD *)v37 + 36))(v37, 1);
            (*(void (__thiscall **)(char *, CMFCCaptionButton *))(*(_DWORD *)this + 36))(this, a2);
          }
          else
          {
            v21 = IEntity::Type((unsigned __int16 *)a2);
            v5 = IEntity::Race(a2);
            CTrace::Print("FreeworkerRole: Could not get good! Race %d, Type %d", v5, v21);
            *((_DWORD *)this + 6) = *((_DWORD *)this + 7);
            v22 = IEntity::Type((unsigned __int16 *)a2);
            v6 = IEntity::Race(a2);
            CSettlerMgr::GetSettlerInfo(v6, v22);
            v23 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
            v17 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
            v7 = IEntity::Race(a2);
            v8 = CEntityToDoListMgr::SettlerJobList(v7, v17);
            (*(void (__thiscall **)(CMFCCaptionButton *, int, int))(*(_DWORD *)a2 + 112))(a2, v8, v23);
          }
        }
        else
        {
          IAnimatedEntity::RegisterForLogicUpdate(v32);
        }
        CheckRegister("LogicUpdateJob - ResourceGather - not registered settler", a2);
        break;
      case 14:
        return;
      case 25:
        if ( this[6] <= (int)(unsigned __int8)this[7] )
          v31 = this[6];
        else
          v31 = (unsigned __int8)this[7];
        this[6] -= v31;
        if ( this[6] <= 0 )
        {
          v24 = IEntity::Type((unsigned __int16 *)a2);
          v9 = IEntity::Race(a2);
          CSettlerMgr::GetSettlerInfo(v9, v24);
          v10 = IEntity::X(a2);
          v29 = v10 - *(char *)(std::vector<CSettlerMgr::SSearchInfos>::operator[](1) + 5);
          v11 = IEntity::Y(a2);
          v30 = v11 - *(char *)(std::vector<CSettlerMgr::SSearchInfos>::operator[](1) + 6);
          if ( debug && DEBUG_FLAGS[dword_41520C4] )
          {
            v12 = IEntity::ID();
            BBSupportTracePrintF(0, "FreeWorker nr %u - Set plant to pos x %u, y %u", v12, v29, v30);
          }
          CDecoObjMgr::AddDecoObjWithoutFlags(&g_cDecoObjMgr, v29, v30, *((unsigned __int16 *)this + 23), 0, 0);
          *((_WORD *)this + 23) = 0;
          (*(void (__thiscall **)(char *, CMFCCaptionButton *))(*(_DWORD *)this + 36))(this, a2);
        }
        else
        {
          IAnimatedEntity::RegisterForLogicUpdate(v31);
        }
        CheckRegister("LogicUpdateJob - Plant - not registered settler ", a2);
        break;
      case 28:
      case 29:
        if ( this[6] <= (int)(unsigned __int8)this[7] )
          v27 = this[6];
        else
          v27 = (unsigned __int8)this[7];
        this[6] -= v27;
        if ( this[6] <= 0 )
        {
          v33 = CMapObjectMgr::EntityPtr(*((unsigned __int16 *)this + 17));
          if ( v33 )
          {
            (*(void (__thiscall **)(int, int))(*(_DWORD *)v33 + 32))(v33, 1);
          }
          else if ( BBSupportDbgReportF(
                      1,
                      "MapObjects\\Settler\\FreeWorkerRole.cpp",
                      479,
                      "CFreeWorkerRole::LogicUpdateJob(): Invalid target entity %i!",
                      *((unsigned __int16 *)this + 17)) == 1 )
          {
            __debugbreak();
          }
          if ( *((_DWORD *)this + 6) )
          {
            v19 = Y16X16::UnpackYFast(*((_DWORD *)this + 6));
            v14 = Y16X16::UnpackXFast(*((_DWORD *)this + 6));
            CWorldManager::ClearFlagBits(v14, v19, 32);
          }
          (*(void (__thiscall **)(char *, CMFCCaptionButton *))(*(_DWORD *)this + 36))(this, a2);
        }
        else
        {
          IAnimatedEntity::RegisterForLogicUpdate(v27);
        }
        CheckRegister("LogicUpdateJob - Work - not registered settler", a2);
        break;
      default:
        if ( debug && DEBUG_FLAGS[dword_41520C4] )
        {
          v25 = this[4];
          v15 = IEntity::ID();
          BBSupportTracePrintF(0, "LogicUpdateJob FreeWorker nr %u - unknown task %u", v15, v25);
        }
        break;
    }
  }
}


// address=[0x156e4c0]
// Decompiled from int __fastcall CFreeWorkerRole::UpdateJob(CFreeWorkerRole *this, int a2, struct CSettler *a3)

void  CFreeWorkerRole::UpdateJob(class CSettler *) {
  
  int result; // eax
  int v4; // [esp+8h] [ebp-28h]
  unsigned int v5; // [esp+Ch] [ebp-24h]
  unsigned int v6; // [esp+10h] [ebp-20h]
  unsigned int v7; // [esp+14h] [ebp-1Ch]
  int v8; // [esp+20h] [ebp-10h]
  int i; // [esp+28h] [ebp-8h]

  result = (int)this;
  switch ( *((_BYTE *)this + 4) )
  {
    case 0:
      if ( *((_BYTE *)this + 7) )
      {
        v8 = (*((unsigned __int16 *)this + 4) + IAnimatedEntity::Frame(a3)) % *((unsigned __int8 *)this + 7);
        if ( v8 || *((unsigned __int8 *)this + 7) <= 1u )
          IAnimatedEntity::SetFrame(v8);
        else
          IAnimatedEntity::SetFrame(1);
      }
      else
      {
        IAnimatedEntity::SetFrame(0);
      }
      result = *((unsigned __int16 *)this + 4);
      v4 = result;
      for ( i = 0; i < v4; ++i )
      {
        *((float *)this + 9) = *((float *)this + 9) + *((float *)this + 12);
        *((float *)this + 10) = *((float *)this + 10) + *((float *)this + 13);
        result = i + 1;
      }
      break;
    case 4:
    case 0x15:
      v7 = IAnimatedEntity::Frame(a3);
      v6 = *((unsigned __int16 *)this + 4);
      if ( v7 <= v6 )
        goto LABEL_18;
      result = IAnimatedEntity::SetFrame(v7 - v6);
      break;
    case 5:
    case 0x16:
      v5 = *((unsigned __int16 *)this + 4) + IAnimatedEntity::Frame(a3);
      if ( v5 >= *((unsigned __int8 *)this + 7) )
      {
        if ( *((_BYTE *)this + 7) )
          result = IAnimatedEntity::SetFrame(*((_BYTE *)this + 7) - 1);
        else
LABEL_18:
          result = IAnimatedEntity::SetFrame(0);
      }
      else
      {
        result = IAnimatedEntity::SetFrame(v5);
      }
      break;
    default:
      return result;
  }
  return result;
}


// address=[0x156e690]
// Decompiled from int __stdcall CFreeWorkerRole::PostLoadInit(CPropertySet *a1)

void  CFreeWorkerRole::PostLoadInit(class CSettler *) {
  
  return CWarMap::AddEntity(a1);
}


// address=[0x156e6b0]
// Decompiled from char *__thiscall CFreeWorkerRole::CFreeWorkerRole(char *this, int a2)

 CFreeWorkerRole::CFreeWorkerRole(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  char *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  ISettlerRole::ISettlerRole(this, a2);
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
  operator^<unsigned char>(a2, v5 + 44);
  operator^<unsigned char>(a2, v5 + 45);
  operator^<float>(a2, v5 + 48);
  operator^<float>(a2, v5 + 52);
  operator^<unsigned short>(a2, v5 + 46);
  if ( (unsigned __int8)v5[44] >= 0x2Bu
    && BBSupportDbgReport(2, "MapObjects\\Settler\\FreeWorkerRole.cpp", 117, "m_uGood < GOOD_MAX") == 1 )
  {
    __debugbreak();
  }
  return v5;
}


// address=[0x156e7f0]
// Decompiled from int __thiscall CFreeWorkerRole::Store(struct CPersistence *this, struct std::ostream *a2)

void  CFreeWorkerRole::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  struct CPersistence *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  ISettlerRole::Store(this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  operator^<unsigned char>(a2, (int)v4 + 44);
  operator^<unsigned char>(a2, (int)v4 + 45);
  operator^<float>(a2, (char *)v4 + 48);
  operator^<float>(a2, (char *)v4 + 52);
  return operator^<unsigned short>((int)a2, (__int16 *)v4 + 23);
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
// Decompiled from int __cdecl CFreeWorkerRole::Load(int a1)

static class CFreeWorkerRole * __cdecl CFreeWorkerRole::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CFreeWorkerRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bec0]
// [Decompilation failed for static unsigned long CFreeWorkerRole::m_iClassID]

// address=[0x156e890]
// Decompiled from CFreeWorkerRole *__thiscall CFreeWorkerRole::CFreeWorkerRole(CFreeWorkerRole *this)

 CFreeWorkerRole::CFreeWorkerRole(void) {
  
  ISettlerRole::ISettlerRole(this);
  *(_DWORD *)this = &CFreeWorkerRole::_vftable_;
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
  
  *(_DWORD *)this = &CFreeWorkerRole::_vftable_;
  return ISettlerRole::~ISettlerRole(this);
}


// address=[0x156e900]
// Decompiled from int __thiscall CFreeWorkerRole::GetNextJob(CFreeWorkerRole *this, struct CSettler *a2)

void  CFreeWorkerRole::GetNextJob(class CSettler *) {
  
  int result; // eax

  IMovingEntity::IncToDoListIter(a2);
  result = IMovingEntity::IsEndIter(a2);
  if ( !(_BYTE)result )
    return (*(int (__thiscall **)(CFreeWorkerRole *, struct CSettler *))(*(_DWORD *)this + 40))(this, a2);
  *((_BYTE *)this + 4) = 17;
  return result;
}


// address=[0x156e940]
// Decompiled from void __thiscall CFreeWorkerRole::TakeJob(ISettlerRole *this, CMFCCaptionButton *a2)

void  CFreeWorkerRole::TakeJob(class CSettler *) {
  
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
  ISettlerRole *v47; // [esp+74h] [ebp-4h]

  v47 = this;
  TickCounter = CStateGame::GetTickCounter(g_pGame);
  IAnimatedEntity::SetLastUpdateTick(a2, TickCounter);
  ActualTask = (const struct CEntityTask *)IMovingEntity::GetActualTask(a2);
  ISettlerRole::InitCommonTaskValues(v47, a2, ActualTask);
  v41 = *((char *)v47 + 4);
  switch ( v41 )
  {
    case 0:
      if ( (*(unsigned __int8 (__thiscall **)(ISettlerRole *, CMFCCaptionButton *))(*(_DWORD *)v47 + 124))(v47, a2) )
      {
        IMovingEntity::SetDisplacementCosts(10);
        v38 = (float)*((__int16 *)v47 + 8) * 255.0;
        v29 = (float)((float)*((__int16 *)v47 + 7) * 255.0) - (float)(0.5 * v38);
        v37 = v29 - (float)(*((float *)v47 + 9) + 127.5);
        v42 = v38 - (float)(*((float *)v47 + 10) + 255.0);
        v28 = abs(v42);
        v26 = (int)(float)((float)(v28 * 0.0039215689) + 0.5);
        v27 = abs(v37 - (float)(0.5 * v42));
        v25 = (int)((float)(v27 * 0.0039215689) + 0.5);
        v44 = 9 * *(_DWORD *)BB::Max<int>(&v25, &v26);
        if ( v44 < 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\FreeWorkerRole.cpp", 930, "iJobCounter >= 0") == 1 )
          __debugbreak();
        if ( v44 >= 128
          && BBSupportDbgReport(2, "MapObjects\\Settler\\FreeWorkerRole.cpp", 931, "iJobCounter < 128") == 1 )
        {
          __debugbreak();
        }
        *((_BYTE *)v47 + 6) = v44;
        if ( v44 <= 0 )
        {
          *((_DWORD *)v47 + 12) = 0;
          *((_DWORD *)v47 + 13) = 0;
          IAnimatedEntity::RegisterForLogicUpdate(1);
        }
        else
        {
          v36 = 1.0 / (float)v44;
          *((float *)v47 + 12) = v37 * v36;
          *((float *)v47 + 13) = v42 * v36;
          IAnimatedEntity::RegisterForLogicUpdate(9);
        }
      }
      break;
    case 1:
    case 2:
    case 13:
    case 16:
    case 30:
      if ( (*(unsigned __int8 (__thiscall **)(ISettlerRole *, CMFCCaptionButton *))(*(_DWORD *)v47 + 124))(v47, a2) )
      {
        IMovingEntity::SetDisplacementCosts(10);
        if ( *((unsigned __int8 *)v47 + 7) <= 1u )
        {
          v17 = IEntity::Race(a2);
          v14 = *((unsigned __int16 *)ActualTask + 7);
          v3 = IEntity::Type((unsigned __int16 *)a2);
          BBSupportTracePrintF(
            3,
            "### CFreeWorkerRole::TakeJob(): Invalid cycle frames %i! Settler type %i, job %i, race %i.",
            *((unsigned __int8 *)v47 + 7),
            v3,
            v14,
            v17);
          IAnimatedEntity::RegisterForLogicUpdate(1);
        }
        else
        {
          IAnimatedEntity::RegisterForLogicUpdate(*((unsigned __int8 *)v47 + 7) - 1);
        }
        if ( IEntity::Type((unsigned __int16 *)a2) == 9 && IAnimatedEntity::JobPart(a2) == 82 )
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
            if ( !CWorldManager::ResourceType(v45) && CWorldManager::ResourceAmount(v45, 0) )
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
      if ( (*(unsigned __int8 (__thiscall **)(ISettlerRole *, CMFCCaptionButton *))(*(_DWORD *)v47 + 124))(v47, a2) )
      {
        IMovingEntity::SetDisplacementCosts(10);
        IAnimatedEntity::SetFrame(*((_BYTE *)v47 + 7) - 1);
        IAnimatedEntity::RegisterForLogicUpdate(*((char *)v47 + 6) / 2);
      }
      break;
    case 5:
    case 22:
      if ( (*(unsigned __int8 (__thiscall **)(ISettlerRole *, CMFCCaptionButton *))(*(_DWORD *)v47 + 124))(v47, a2) )
      {
        IMovingEntity::SetDisplacementCosts(10);
        IAnimatedEntity::RegisterForLogicUpdate(*((char *)v47 + 6) / 2 - 1);
      }
      break;
    case 10:
      IAnimatedEntity::SetFrame(1);
      IMovingEntity::WalkToXY(a2, *((_DWORD *)v47 + 6), 0);
      *((_BYTE *)v47 + 4) = 6;
      IMovingEntity::SetDisplacementCosts(5);
      (*(void (__thiscall **)(ISettlerRole *, CMFCCaptionButton *))(*(_DWORD *)v47 + 16))(v47, a2);
      break;
    case 14:
      if ( (*(unsigned __int8 (__thiscall **)(ISettlerRole *, CMFCCaptionButton *))(*(_DWORD *)v47 + 124))(v47, a2) )
      {
        IAnimatedEntity::SetFrame(0);
        v9 = (CMFCToolBarButton *)CBuildingMgr::operator[](*((unsigned __int16 *)v47 + 16));
        v10 = CBuilding::DoorPackedXY(v9);
        IMovingEntity::WalkToXY(a2, v10, 0);
        *((_BYTE *)v47 + 4) = 6;
        IMovingEntity::SetDisplacementCosts(5);
        (*(void (__thiscall **)(ISettlerRole *, CMFCCaptionButton *))(*(_DWORD *)v47 + 16))(v47, a2);
      }
      break;
    case 17:
      IMovingEntity::SetDisplacementCosts(0);
      IAnimatedEntity::RegisterForLogicUpdate(1);
      break;
    case 19:
      if ( (*(unsigned __int8 (__thiscall **)(ISettlerRole *, CMFCCaptionButton *))(*(_DWORD *)v47 + 124))(v47, a2) )
      {
        v21 = *((unsigned __int8 *)v47 + 44);
        v11 = (CBuilding *)CBuildingMgr::operator[](*((unsigned __int16 *)v47 + 16));
        PileIdWithGood = CBuilding::GetPileIdWithGood(v11, v21);
        v12 = CMapObjectMgr::EntityPtr(PileIdWithGood);
        v23 = IEntity::PackedXY(v12);
        IMovingEntity::WalkToXY(a2, v23, 4096);
        *((_BYTE *)v47 + 4) = 6;
        IMovingEntity::SetDisplacementCosts(5);
        (*(void (__thiscall **)(ISettlerRole *, CMFCCaptionButton *))(*(_DWORD *)v47 + 16))(v47, a2);
      }
      break;
    case 24:
      if ( (*(unsigned __int8 (__thiscall **)(ISettlerRole *, CMFCCaptionButton *))(*(_DWORD *)v47 + 124))(v47, a2) )
      {
        *((_DWORD *)v47 + 9) = 0;
        *((_DWORD *)v47 + 10) = 0;
        *((_DWORD *)v47 + 6) = 0;
        *((_BYTE *)v47 + 45) = 0;
        IMovingEntity::SetDisplacementCosts(10);
        v22 = IEntity::ID();
        v13 = (CBuilding *)CBuildingMgr::operator[](*((unsigned __int16 *)v47 + 16));
        CBuilding::SettlerEnter(v13, v22);
      }
      break;
    case 25:
      if ( (*(unsigned __int8 (__thiscall **)(ISettlerRole *, CMFCCaptionButton *))(*(_DWORD *)v47 + 124))(v47, a2) )
      {
        if ( *((unsigned __int8 *)v47 + 7) <= 1u
          && BBSupportDbgReport(2, "MapObjects\\Settler\\FreeWorkerRole.cpp", 817, "m_iCycleFrames > 1") == 1 )
        {
          __debugbreak();
        }
        goto LABEL_28;
      }
      break;
    case 28:
    case 29:
      if ( (*(unsigned __int8 (__thiscall **)(ISettlerRole *, CMFCCaptionButton *))(*(_DWORD *)v47 + 124))(v47, a2) )
      {
        if ( CFreeWorkerRole::CheckResource(v47, a2, 0) == *((unsigned __int16 *)v47 + 17) )
        {
          *((_BYTE *)v47 + 45) = 1;
          if ( *((unsigned __int8 *)v47 + 7) <= 1u
            && BBSupportDbgReport(2, "MapObjects\\Settler\\FreeWorkerRole.cpp", 861, "m_iCycleFrames > 1") == 1 )
          {
            __debugbreak();
          }
LABEL_28:
          IMovingEntity::SetDisplacementCosts(10);
          IAnimatedEntity::RegisterForLogicUpdate(*((unsigned __int8 *)v47 + 7) - 1);
        }
        else
        {
          v18 = *((unsigned __int16 *)v47 + 17);
          v15 = IEntity::Race(a2);
          v4 = IEntity::Type((unsigned __int16 *)a2);
          CTrace::Print(
            "Freeworkerrole: Working entity differs from stored entity! Should not happen! Settler %u, Race %u, Entity %u",
            v4,
            v15,
            v18);
          v19 = IEntity::Type((unsigned __int16 *)a2);
          v5 = IEntity::Race(a2);
          SettlerInfo = CSettlerMgr::GetSettlerInfo(v5, v19);
          v30 = (CMFCToolBarButton *)CBuildingMgr::operator[](*((unsigned __int16 *)v47 + 16));
          v6 = CBuilding::DoorPackedXY(v30);
          ISettlerRole::NewDestination(v47, a2, v6, 0);
          v20 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
          v16 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
          v7 = IEntity::Race(a2);
          v8 = CEntityToDoListMgr::SettlerJobList(v7, v16);
          (*(void (__thiscall **)(CMFCCaptionButton *, int, int))(*(_DWORD *)a2 + 112))(a2, v8, v20);
        }
      }
      break;
    default:
      CTrace::Print("FreeWorkerJob - TakeJob unknown task");
      break;
  }
}


// address=[0x156f1e0]
// Decompiled from int __thiscall CFreeWorkerRole::Init(int this, CPropertySet *a2)

void  CFreeWorkerRole::Init(class CSettler *) {
  
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
// Decompiled from int __thiscall CFreeWorkerRole::ConvertEventIntoGoal(
        CFreeWorkerRole *this,
        struct CSettler *a2,
        struct CEntityEvent *a3)

void  CFreeWorkerRole::ConvertEventIntoGoal(class CSettler *,class CEntityEvent *) {
  
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

  switch ( *((_DWORD *)a3 + 1) )
  {
    case 1:
      v17 = IEntity::Type((unsigned __int16 *)a2);
      v4 = IEntity::Race(a2);
      CSettlerMgr::GetSettlerInfo(v4, v17);
      v23 = (CMFCToolBarButton *)CBuildingMgr::operator[](*((_DWORD *)a3 + 3));
      *((_WORD *)this + 16) = IEntity::ID();
      result = (*(int (__thiscall **)(CFreeWorkerRole *, struct CSettler *))(*(_DWORD *)this + 124))(this, a2);
      if ( (_BYTE)result )
      {
        v5 = CBuilding::DoorPackedXY(v23);
        ISettlerRole::NewDestination(this, a2, v5, 0);
        v18 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
        v14 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](0);
        v6 = IEntity::Race(a2);
        v7 = CEntityToDoListMgr::SettlerJobList(v6, v14);
        result = (*(int (__thiscall **)(struct CSettler *, int, int))(*(_DWORD *)a2 + 112))(a2, v7, v18);
      }
      break;
    case 5:
      result = (*(unsigned __int8 (__thiscall **)(CFreeWorkerRole *, struct CSettler *))(*(_DWORD *)this + 124))(
                 this,
                 a2);
      if ( (_BYTE)result )
      {
        v21 = IEntity::Type((unsigned __int16 *)a2);
        v11 = IEntity::Race(a2);
        CSettlerMgr::GetSettlerInfo(v11, v21);
        ISettlerRole::NewDestination(this, a2, *((_DWORD *)a3 + 5), 0);
        if ( IEntity::Type((unsigned __int16 *)a2) != 10 && IEntity::Type((unsigned __int16 *)a2) != 9 )
          (*(void (__thiscall **)(CFreeWorkerRole *, _DWORD))(*(_DWORD *)this + 52))(this, *((_DWORD *)a3 + 4));
        v22 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](1);
        v16 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](1);
        v12 = IEntity::Race(a2);
        v13 = CEntityToDoListMgr::SettlerJobList(v12, v16);
        result = (*(int (__thiscall **)(struct CSettler *, int, int))(*(_DWORD *)a2 + 112))(a2, v13, v22);
      }
      break;
    case 6:
      result = (*(int (__thiscall **)(CFreeWorkerRole *, struct CSettler *))(*(_DWORD *)this + 124))(this, a2);
      if ( (_BYTE)result )
      {
        *((_WORD *)this + 23) = *((_WORD *)a3 + 8);
        v19 = IEntity::Type((unsigned __int16 *)a2);
        v8 = IEntity::Race(a2);
        CSettlerMgr::GetSettlerInfo(v8, v19);
        ISettlerRole::NewDestination(this, a2, *((_DWORD *)a3 + 5), 0);
        v20 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](2);
        v15 = *(unsigned __int16 *)std::vector<unsigned short>::operator[](2);
        v9 = IEntity::Race(a2);
        v10 = CEntityToDoListMgr::SettlerJobList(v9, v15);
        result = (*(int (__thiscall **)(struct CSettler *, int, int))(*(_DWORD *)a2 + 112))(a2, v10, v20);
      }
      break;
    case 9:
      if ( *((_BYTE *)this + 4) == 17 )
        (*(void (__thiscall **)(CFreeWorkerRole *, struct CSettler *, _DWORD))(*(_DWORD *)this + 64))(
          this,
          a2,
          *((_DWORD *)a3 + 5));
      result = IEntity::FlagBits(a2, Registered);
      if ( !result )
        result = IAnimatedEntity::RegisterForLogicUpdate(1);
      break;
    default:
      result = IEntity::FlagBits(a2, Registered);
      if ( !result )
      {
        CTrace::Print("ConvertEventIntoGoal FreeWorkerRole - unknown event %u", *((_DWORD *)a3 + 1));
        result = IAnimatedEntity::RegisterForLogicUpdate(1);
      }
      break;
  }
  return result;
}


// address=[0x156f520]
// Decompiled from int __thiscall CFreeWorkerRole::CheckResource(CFreeWorkerRole *this, struct CSettler *a2, int a3)

int  CFreeWorkerRole::CheckResource(class CSettler *,int) {
  
  int v3; // eax
  int v5; // [esp-4h] [ebp-20h]
  int v6; // [esp+8h] [ebp-14h]
  int v7; // [esp+Ch] [ebp-10h]
  int v8; // [esp+10h] [ebp-Ch]
  int v9; // [esp+14h] [ebp-8h]

  v5 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::Race(a2);
  CSettlerMgr::GetSettlerInfo(v3, v5);
  v9 = *(char *)(std::vector<CSettlerMgr::SSearchInfos>::operator[](a3) + 5);
  v8 = *(char *)(std::vector<CSettlerMgr::SSearchInfos>::operator[](a3) + 6);
  v6 = IEntity::X(a2) - v9;
  v7 = IEntity::Y(a2) - v8;
  return CWorldManager::ObjectId(v6, v7);
}


// address=[0x156f5b0]
// Decompiled from // private: int __thiscall CFreeWorkerRole::CheckSpaceForPlant(class CSettler *)
int __stdcall CFreeWorkerRole::CheckSpaceForPlant(unsigned __int16 *a1)

int  CFreeWorkerRole::CheckSpaceForPlant(class CSettler *) {
  
  int v1; // eax
  int v3; // [esp-4h] [ebp-20h]
  int v4; // [esp+4h] [ebp-18h]
  int v5; // [esp+8h] [ebp-14h]
  int v6; // [esp+Ch] [ebp-10h]
  int v7; // [esp+10h] [ebp-Ch]

  v3 = IEntity::Type(a1);
  v1 = IEntity::Race(a1);
  CSettlerMgr::GetSettlerInfo(v1, v3);
  if ( !*(_DWORD *)std::vector<CSettlerMgr::SSearchInfos>::operator[](0)
    && BBSupportDbgReport(2, "MapObjects\\Settler\\FreeWorkerRole.cpp", 1344, "pSearchFkt != 0") == 1 )
  {
    __debugbreak();
  }
  v7 = *(char *)(std::vector<CSettlerMgr::SSearchInfos>::operator[](1) + 5);
  v6 = *(char *)(std::vector<CSettlerMgr::SSearchInfos>::operator[](1) + 5);
  v4 = IEntity::X(a1) - v7;
  v5 = IEntity::Y(a1) - v6;
  return CWorldManager::ObjectId(v4, v5);
}


// address=[0x156f670]
// Decompiled from char __thiscall CFreeWorkerRole::SetFree(CFreeWorkerRole *this, struct CSettler *a2, int a3)

bool  CFreeWorkerRole::SetFree(class CSettler *,int) {
  
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

  if ( !*((_BYTE *)this + 45) )
  {
    if ( *((_WORD *)this + 17) )
    {
      DecoObjPtr = (unsigned __int16 *)CDecoObjMgr::GetDecoObjPtr(*((unsigned __int16 *)this + 17));
      if ( DecoObjPtr && !IDecoObject::IsStaticInstance((IDecoObject *)DecoObjPtr) )
      {
        v14 = (*(int (__thiscall **)(unsigned __int16 *))(*(_DWORD *)DecoObjPtr + 40))(DecoObjPtr);
        v12 = IEntity::Type(DecoObjPtr);
        v10 = IEntity::Y(DecoObjPtr);
        v3 = IEntity::X(DecoObjPtr);
        CDecoObjMgr::ChangeToStaticInstance((CDecoObjMgr *)&g_cDecoObjMgr, v3, v10, v12, v14);
      }
      *((_WORD *)this + 17) = 0;
    }
    IEntity::SetFlagBits(a2, Visible);
  }
  if ( *((_WORD *)this + 23) )
  {
    v15 = IEntity::Type((unsigned __int16 *)a2);
    v4 = IEntity::Race(a2);
    CSettlerMgr::GetSettlerInfo(v4, v15);
    v5 = Y16X16::UnpackXFast(*((_DWORD *)this + 6));
    v16 = v5 - *(char *)(std::vector<CSettlerMgr::SSearchInfos>::operator[](1) + 5);
    v6 = Y16X16::UnpackYFast(*((_DWORD *)this + 6));
    v7 = std::vector<CSettlerMgr::SSearchInfos>::operator[](1);
    CDecoObjMgr::ClearFlagsForObject(
      (CDecoObjMgr *)&g_cDecoObjMgr,
      v16,
      v6 - *(char *)(v7 + 6),
      *((unsigned __int16 *)this + 23),
      0);
    *((_WORD *)this + 23) = 0;
  }
  if ( !*((_BYTE *)this + 44) )
    return ISettlerRole::SetFree(this, a2, a3);
  if ( *((unsigned __int8 *)this + 44) >= 0x2Bu
    && BBSupportDbgReport(2, "MapObjects\\Settler\\FreeWorkerRole.cpp", 1282, "m_uGood < GOOD_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( *((unsigned __int8 *)this + 44) < 0x2Bu )
  {
    v13 = *((unsigned __int8 *)this + 44);
    v11 = IEntity::Y(a2);
    v8 = IEntity::X(a2);
    CPileMgr::SearchSpaceForGoods((CPileMgr *)&g_cPileMgr, v8, v11, v13, 1u);
  }
  *((_BYTE *)this + 44) = 0;
  return ISettlerRole::SetFree(this, a2, a3);
}


