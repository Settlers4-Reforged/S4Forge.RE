#include "CAIGoalCache.h"

// Definitions for class CAIGoalCache

// address=[0x1301470]
// Decompiled from char *__thiscall CAIGoalCache::Goal(CAIGoalCache *this, int a2)
class CAIGoal const &  CAIGoalCache::Goal(int a2) {
  
  return (char *)this + 12 * a2 + 20;
}


// address=[0x13015a0]
// Decompiled from int __thiscall CAIGoalCache::NumberOfCachedGoals(CAIGoalCache *this)
int  CAIGoalCache::NumberOfCachedGoals(void)const {
  
  return *((_DWORD *)this + 1);
}


// address=[0x13140c0]
// Decompiled from CAIGoal *__thiscall CAIGoalCache::Init(CAIGoalCache *this)
void  CAIGoalCache::Init(void) {
  
  CAIGoal *result; // eax

  *((_DWORD *)this + 1) = 0;
  result = CAIGoal::Maximum((CAIGoalCache *)((char *)this + 8));
  *((_DWORD *)this + 98) = 0;
  return result;
}


// address=[0x1314100]
// Decompiled from CAIGoalCache *__thiscall CAIGoalCache::Insert(CAIGoalCache *this, int a2, int a3)
void  CAIGoalCache::Insert(int a2, int a3) {
  
  _DWORD *v3; // ecx
  CAIGoalCache *result; // eax
  int v5; // [esp+18h] [ebp-10h]
  int i; // [esp+1Ch] [ebp-Ch]
  int j; // [esp+20h] [ebp-8h]

  if ( a2 <= 0 && BBSupportDbgReport(2, "AI\\AI_Military.cpp", 120, "_iEntityId > 0") == 1 )
    __debugbreak();
  if ( (*((_DWORD *)this + 1) > 31 || *((_DWORD *)this + 1) < 0)
    && BBSupportDbgReport(2, "AI\\AI_Military.cpp", 122, "(m_iSize >= 0) & (m_iSize <= (AI_GOAL_CACHE_MAX - 1))") == 1 )
  {
    __debugbreak();
  }
  CAIGoalCache::Delete(this, a2);
  if ( (*((_DWORD *)this + 1) > 31 || *((_DWORD *)this + 1) < 0)
    && BBSupportDbgReport(2, "AI\\AI_Military.cpp", 126, "(m_iSize >= 0) & (m_iSize <= (AI_GOAL_CACHE_MAX - 1))") == 1 )
  {
    __debugbreak();
  }
  v5 = IAIEnvironment::EntityUniqueId(a2);
  if ( v5 > 0 )
  {
    if ( *((int *)this + 1) > 0 )
    {
      if ( *((int *)this + 1) >= 31 )
        *((_DWORD *)this + 1) = 30;
      for ( i = *((_DWORD *)this + 1) + 1; a3 > CAIGoal::Value((CAIGoalCache *)((char *)this + 12 * i - 4)); --i )
        ;
      for ( j = *((_DWORD *)this + 1); j >= i; --j )
      {
        v3 = (_DWORD *)((char *)this + 12 * j + 20);
        *v3 = *((_DWORD *)this + 3 * j + 2);
        v3[1] = *((_DWORD *)this + 3 * j + 3);
        v3[2] = *((_DWORD *)this + 3 * j + 4);
      }
      CAIGoal::Set((CAIGoalCache *)((char *)this + 12 * i + 8), a2, v5, a3);
      ++*((_DWORD *)this + 1);
    }
    else
    {
      *((_DWORD *)this + 1) = 1;
      CAIGoal::Set((CAIGoalCache *)((char *)this + 20), a2, v5, a3);
    }
  }
  result = this;
  if ( *((_DWORD *)this + 1) <= 31 && *((_DWORD *)this + 1) >= 0 )
    return result;
  result = (CAIGoalCache *)BBSupportDbgReport(
                             2,
                             "AI\\AI_Military.cpp",
                             159,
                             "(m_iSize >= 0) & (m_iSize <= (AI_GOAL_CACHE_MAX - 1))");
  if ( result == (CAIGoalCache *)1 )
    __debugbreak();
  return result;
}


// address=[0x1314350]
// Decompiled from void __thiscall CAIGoalCache::Delete(CAIGoalCache *this, int a2)
void  CAIGoalCache::Delete(int a2) {
  
  int v3; // [esp+4h] [ebp-4h]

  v3 = CAIGoalCache::Search(this, a2);
  if ( v3 )
    CAIGoalCache::DeleteIdx(this, v3);
}


// address=[0x1314380]
// Decompiled from CAIGoalCache *__thiscall CAIGoalCache::DbgPrint(CAIGoalCache *this, const char *a2)
void  CAIGoalCache::DbgPrint(char const * const a2) {
  
  CAIGoalCache *result; // eax
  int v3; // eax
  int v4; // [esp-8h] [ebp-18h]
  int v5; // [esp-4h] [ebp-14h]
  int i; // [esp+8h] [ebp-8h]

  if ( (*((_DWORD *)this + 1) > 31 || *((_DWORD *)this + 1) < 0)
    && BBSupportDbgReport(2, "AI\\AI_Military.cpp", 31, "(m_iSize >= 0) & (m_iSize <= (AI_GOAL_CACHE_MAX - 1))") == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)this + 1) )
  {
    if ( *((_DWORD *)this + 1) == 1 )
      IAIEnvironment::DbgTracePrintF("%s: 1 entry.", a2);
    else
      IAIEnvironment::DbgTracePrintF("%s: %i entries.", a2, *((_DWORD *)this + 1));
  }
  else
  {
    IAIEnvironment::DbgTracePrintF("%s: No entries.", a2);
  }
  for ( i = 1; ; ++i )
  {
    result = this;
    if ( i > *((_DWORD *)this + 1) )
      break;
    v5 = CAIGoal::Value((CAIGoalCache *)((char *)this + 12 * i + 8));
    v4 = CAIGoal::UniqueId((CAIGoalCache *)((char *)this + 12 * i + 8));
    v3 = CAIGoal::EntityId((CAIGoalCache *)((char *)this + 12 * i + 8));
    IAIEnvironment::DbgTracePrintF(" %2i. entry: id %i, unique id: %i, value %i.", i, v3, v4, v5);
  }
  return result;
}


// address=[0x13144a0]
// Decompiled from int __thiscall CAIGoalCache::DeleteInvalidGoals(CAIGoalCache *this)
void  CAIGoalCache::DeleteInvalidGoals(void) {
  
  int result; // eax
  int v2; // [esp+4h] [ebp-14h]
  int v3; // [esp+8h] [ebp-10h]
  int v5; // [esp+14h] [ebp-4h]

  v5 = 1;
  while ( v5 <= *((_DWORD *)this + 1) )
  {
    v3 = CAIGoal::EntityId((CAIGoalCache *)((char *)this + 12 * v5 + 8));
    v2 = CAIGoal::UniqueId((CAIGoalCache *)((char *)this + 12 * v5 + 8));
    if ( v2 == IAIEnvironment::EntityUniqueId(v3) )
      ++v5;
    else
      CAIGoalCache::DeleteIdx(this, v5);
  }
  result = IAIEnvironment::TickCounter();
  *((_DWORD *)this + 98) = result;
  return result;
}


// address=[0x1314530]
// Decompiled from int __thiscall CAIGoalCache::DeleteInvalidGoalsIfNecessary(CAIGoalCache *this)
void  CAIGoalCache::DeleteInvalidGoalsIfNecessary(void) {
  
  int result; // eax

  result = IAIEnvironment::TickCounter();
  if ( *((_DWORD *)this + 98) != result )
    return CAIGoalCache::DeleteInvalidGoals(this);
  return result;
}


// address=[0x1314560]
// Decompiled from int __thiscall CAIGoalCache::Load(CAIGoalCache *this, struct IS4Chunk *a2)
void  CAIGoalCache::Load(class IS4Chunk & a2) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 1, 1);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 32, 32);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 12, 12);
  *((_DWORD *)this + 1) = (*(int (__thiscall **)(struct IS4Chunk *, _DWORD, int))(*(_DWORD *)a2 + 4))(a2, 0, 32);
  return (**(int (__thiscall ***)(struct IS4Chunk *, char *, int))a2)(a2, (char *)this + 8, 384);
}


// address=[0x13145d0]
// Decompiled from int __thiscall CAIGoalCache::Save(CAIGoalCache *this, struct IS4Chunk *a2)
void  CAIGoalCache::Save(class IS4Chunk & a2) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 1);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 32);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 12);
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 1));
  return (*(int (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 8, 384);
}


// address=[0x1325b90]
// Decompiled from CAIGoalCache *__thiscall CAIGoalCache::CAIGoalCache(CAIGoalCache *this)
 CAIGoalCache::CAIGoalCache(void) {
  
  IS4ChunkObject::IS4ChunkObject(this);
  *(_DWORD *)this = CAIGoalCache::_vftable_;
  CAIGoalCache::Init(this);
  return this;
}


// address=[0x1314640]
// Decompiled from int __thiscall CAIGoalCache::Search(CAIGoalCache *this, int a2)
int  CAIGoalCache::Search(int a2)const {
  
  int v3; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  v3 = *((_DWORD *)this + 1);
  for ( i = 1; i <= v3; ++i )
  {
    if ( CAIGoal::EntityId((CAIGoalCache *)((char *)this + 12 * i + 8)) == a2 )
      return i;
  }
  return 0;
}


// address=[0x1314690]
// Decompiled from CAIGoalCache *__thiscall CAIGoalCache::DeleteIdx(CAIGoalCache *this, int a2)
void  CAIGoalCache::DeleteIdx(int a2) {
  
  _DWORD *v2; // edx
  CAIGoalCache *result; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = a2 + 1; i <= *((_DWORD *)this + 1); ++i )
  {
    v2 = (_DWORD *)((char *)this + 12 * i - 4);
    *v2 = *((_DWORD *)this + 3 * i + 2);
    v2[1] = *((_DWORD *)this + 3 * i + 3);
    v2[2] = *((_DWORD *)this + 3 * i + 4);
  }
  result = this;
  --*((_DWORD *)this + 1);
  return result;
}


