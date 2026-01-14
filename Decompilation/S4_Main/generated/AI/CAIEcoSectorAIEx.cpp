#include "all_headers.h"

// Definitions for class CAIEcoSectorAIEx

// address=[0x13098e0]
// Decompiled from CAIEcoSectorAIEx *__thiscall CAIEcoSectorAIEx::CAIEcoSectorAIEx(CAIEcoSectorAIEx *this, struct IAISectorAI *a2, int a3)
 CAIEcoSectorAIEx::CAIEcoSectorAIEx(class IAISectorAI *,int) {
  
  int v3; // eax
  CEcoSector *EcoSectorPtr; // [esp+4h] [ebp-14h]

  IAIUnknown::IAIUnknown(this);
  *(_DWORD *)this = CAIEcoSectorAIEx::_vftable_;
  CAIEventQueue::CAIEventQueue((CAIEcoSectorAIEx *)((char *)this + 16));
  *((_DWORD *)this + 1) = a3;
  *((_DWORD *)this + 2) = IAIEnvironment::EcoSectorGetUniqueId(a3);
  EcoSectorPtr = CEcoSectorMgr::GetEcoSectorPtr((CEcoSectorMgr *)g_cESMgr, *((_DWORD *)this + 1));
  if ( EcoSectorPtr )
    CEcoSector::SetWeaponAutoProduction(EcoSectorPtr, 0);
  *((_DWORD *)this + 3) = IAIEnvironment::TickCounter();
  BBSupportTracePrintF(
    0,
    "CAIEcoSectorAIEx::CAIEcoSectorAIEx(): eco-sector id %i, unique id 0x%08x.",
    *((_DWORD *)this + 1),
    *((_DWORD *)this + 2));
  *((_DWORD *)this + 10) = IAIEcoManager::CreateEcoManager(a3, a2, (CAIEcoSectorAIEx *)((char *)this + 16));
  *((_DWORD *)this + 11) = IAIEcoSectorAI::CreateEcoSectorAI(*((struct IAIEcoManager **)this + 10));
  if ( !*((_DWORD *)this + 11) && BBSupportDbgReport(2, "AI\\AI_EcoSectorAIEx.cpp", 54, "m_pEcoSectorAI != 0") == 1 )
    __debugbreak();
  if ( !off_3D7A214 && BBSupportDbgReport(2, "AI\\AI_EcoSectorAIEx.cpp", 55, "g_pAIEnv != 0") == 1 )
    __debugbreak();
  v3 = IAIEnvironment::GlobalEcoAIFlags();
  (*(void (__cdecl **)(int))(**((_DWORD **)this + 11) + 16))(v3);
  return this;
}


// address=[0x1309a50]
// Decompiled from void __thiscall CAIEcoSectorAIEx::~CAIEcoSectorAIEx(CAIEcoSectorAIEx *this)
 CAIEcoSectorAIEx::~CAIEcoSectorAIEx(void) {
  
  *(_DWORD *)this = CAIEcoSectorAIEx::_vftable_;
  BBSupportTracePrintF(
    0,
    "CAIEcoSectorAIEx::~CAIEcoSectorAIEx(): eco-sector id %i, unique id 0x%08x.",
    *((_DWORD *)this + 1),
    *((_DWORD *)this + 2));
  if ( *((_DWORD *)this + 11) )
  {
    (***((void (__thiscall ****)(_DWORD))this + 11))(*((_DWORD *)this + 11));
    *((_DWORD *)this + 11) = 0;
  }
  if ( *((_DWORD *)this + 10) )
  {
    (*(void (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 10) + 4))(*((_DWORD *)this + 10), 1);
    *((_DWORD *)this + 10) = 0;
  }
  CAIEventQueue::Clear((CAIEcoSectorAIEx *)((char *)this + 16));
  CAIEventQueue::~CAIEventQueue((CAIEcoSectorAIEx *)((char *)this + 16));
}


// address=[0x1309b30]
// Decompiled from CAIEcoSectorAIEx *__cdecl CAIEcoSectorAIEx::CreateEcoSectorAIEx(struct IAISectorAI *a1, int a2)
static class CAIEcoSectorAIEx * __cdecl CAIEcoSectorAIEx::CreateEcoSectorAIEx(class IAISectorAI *,int) {
  
  void *Memory; // [esp+8h] [ebp-18h]
  CAIEcoSectorAIEx *v5; // [esp+10h] [ebp-10h]

  Memory = (void *)TAIStaticMemoryPool<48,512>::AllocateMemory(48);
  v5 = (CAIEcoSectorAIEx *)operator new(0x30u, Memory);
  if ( v5 )
    return CAIEcoSectorAIEx::CAIEcoSectorAIEx(v5, a1, a2);
  else
    return 0;
}


// address=[0x1309bc0]
// Decompiled from void __thiscall CAIEcoSectorAIEx::Execute(CAIEcoSectorAIEx *this)
void  CAIEcoSectorAIEx::Execute(void) {
  
  CRandom16 *v1; // eax
  int NumberOfRandCalls; // eax
  CRandom16 *v3; // eax
  int v4; // eax

  if ( *((_DWORD *)this + 11) )
  {
    if ( IAIEnvironment::EcoSectorCheckId(*((_DWORD *)this + 1), *((_DWORD *)this + 2)) )
    {
      v1 = (CRandom16 *)IAIEnvironment::RandomPtr();
      NumberOfRandCalls = CRandom16::GetNumberOfRandCalls(v1);
      IMessageTracer::PushFormatedInts(
        g_pMsgTracer,
        "Before IAIEcoSectorAI->Execute(): eco-sector %u, rand counter %u",
        *((_DWORD *)this + 1),
        NumberOfRandCalls);
      (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 11) + 4))(*((_DWORD *)this + 11));
      v3 = (CRandom16 *)IAIEnvironment::RandomPtr();
      v4 = CRandom16::GetNumberOfRandCalls(v3);
      IMessageTracer::PushFormatedInts(g_pMsgTracer, "After IAIEcoSectorAI->Execute(): rand counter %u", v4);
    }
    else
    {
      BBSupportTracePrintF(
        3,
        "### CAIEcoSectorAIEx::Execute(): Invalid eco-sector! Eco-sector %i, unique id 0x%08x. ###",
        *((_DWORD *)this + 1),
        *((_DWORD *)this + 2));
      if ( BBSupportDbgReport(1, "AI\\AI_EcoSectorAIEx.cpp", 107, "CAIEcoSectorAIEx::Execute(): Invalid eco-sector!") == 1 )
        __debugbreak();
    }
  }
  else
  {
    BBSupportTracePrintF(3, "### CAIEcoSectorAIEx::Execute(): Invalid economy-ai! ###");
    if ( BBSupportDbgReport(1, "AI\\AI_EcoSectorAIEx.cpp", 114, "CAIEcoSectorAIEx::Execute(): Invalid economy-ai!") == 1 )
      __debugbreak();
  }
}


// address=[0x1309cc0]
// Decompiled from int __thiscall CAIEcoSectorAIEx::Release(CAIEcoSectorAIEx *this)
void  CAIEcoSectorAIEx::Release(void) {
  
  return TAIStaticObjectMemoryPool<CAIEcoSectorAIEx,48,512>::Delete(this);
}


// address=[0x1309ce0]
// Decompiled from bool __thiscall CAIEcoSectorAIEx::IsEcoSectorValid(CAIEcoSectorAIEx *this)
bool  CAIEcoSectorAIEx::IsEcoSectorValid(void)const {
  
  return IAIEnvironment::EcoSectorCheckId(*((_DWORD *)this + 1), *((_DWORD *)this + 2));
}


// address=[0x13260f0]
// Decompiled from void __thiscall CAIEcoSectorAIEx::ClearEventQueue(CAIEcoSectorAIEx *this)
void  CAIEcoSectorAIEx::ClearEventQueue(void) {
  
  CAIEventQueue::Clear((CAIEcoSectorAIEx *)((char *)this + 16));
}


// address=[0x1326110]
// Decompiled from int __thiscall CAIEcoSectorAIEx::CreationTime(pairNode *this)
unsigned int  CAIEcoSectorAIEx::CreationTime(void)const {
  
  return *((_DWORD *)this + 3);
}


// address=[0x1326150]
// Decompiled from int __thiscall CAIEcoSectorAIEx::EcoSectorId(CAIEcoSectorAIEx *this)
int  CAIEcoSectorAIEx::EcoSectorId(void)const {
  
  return *((_DWORD *)this + 1);
}


// address=[0x13261b0]
// Decompiled from void __thiscall CAIEcoSectorAIEx::PostAIEvent(CAIEcoSectorAIEx *this, int a2, int a3, int a4, int a5)
void  CAIEcoSectorAIEx::PostAIEvent(int,int,int,int) {
  
  CAIEventQueue::PostAIEvent((CAIEcoSectorAIEx *)((char *)this + 16), a2, a3, a4, a5);
}


