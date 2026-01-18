#include "CDestructionManager.h"

// Definitions for class CDestructionManager

// address=[0x1426a10]
// Decompiled from int CDestructionManager::Instance()
class CDestructionManager & __cdecl CDestructionManager::Instance(void) {
  
  _DWORD *Instance; // eax

  Instance = CDestructionManager::GetInstance();
  return std::auto_ptr<CDestructionManager>::operator*(Instance);
}


// address=[0x1426a30]
// Decompiled from int __thiscall CDestructionManager::RegisterDestructor(CDestructionManager *this, struct CDestructor *a2)
void  CDestructionManager::RegisterDestructor(class CDestructor * a2) {
  
  return std::vector<CDestructor *>::push_back(&a2);
}


// address=[0x2f03a10]
// Decompiled from unsigned int __thiscall CDestructionManager::DestroyObjects(CDestructionManager *this)
void  CDestructionManager::DestroyObjects(void) {
  
  unsigned int result; // eax
  char v2; // [esp-1Ch] [ebp-3Ch] BYREF
  int v3; // [esp-18h] [ebp-38h]
  int v4; // [esp-14h] [ebp-34h]
  _DWORD v5[3]; // [esp-10h] [ebp-30h] BYREF
  int v6; // [esp-4h] [ebp-24h]
  int v7; // [esp+0h] [ebp-20h]
  char *v8; // [esp+4h] [ebp-1Ch]
  int v9; // [esp+8h] [ebp-18h]
  _DWORD *v10; // [esp+Ch] [ebp-14h]
  void (__thiscall ***v11)(_DWORD); // [esp+10h] [ebp-10h]
  CDestructionManager *v12; // [esp+14h] [ebp-Ch]
  unsigned int i; // [esp+18h] [ebp-8h]
  unsigned __int8 v14; // [esp+1Fh] [ebp-1h]

  v12 = this;
  v6 = v14;
  v10 = v5;
  v9 = std::vector<CDestructor *>::end(v5);
  v8 = &v2;
  v7 = std::vector<CDestructor *>::begin(&v2);
  std::sort<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CDestructor *>>>,greater_ptr<CDestructor>>(
    v2,
    v3,
    v4,
    v5[0],
    v5[1],
    v5[2],
    v6);
  for ( i = 0; ; ++i )
  {
    result = std::vector<CDestructor *>::size(v12);
    if ( i >= result )
      break;
    v11 = *(void (__thiscall ****)(_DWORD))std::vector<CDestructor *>::operator[](i);
    (**v11)(v11);
  }
  return result;
}


// address=[0x2f03a90]
// Decompiled from void *CDestructionManager::GetInstance()
class std::auto_ptr<class CDestructionManager> & __cdecl CDestructionManager::GetInstance(void) {
  
  CDestructionManager *v1; // [esp+8h] [ebp-14h]
  CDestructionManager *C; // [esp+Ch] [ebp-10h]

  if ( dword_46853C4 <= *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    return &unk_46853C0;
  j___Init_thread_header(&dword_46853C4);
  if ( dword_46853C4 != -1 )
    return &unk_46853C0;
  C = (CDestructionManager *)operator new(0x10u);
  if ( C )
    v1 = CDestructionManager::CDestructionManager(C);
  else
    v1 = 0;
  std::auto_ptr<CDestructionManager>::auto_ptr<CDestructionManager>(v1);
  j__atexit(sub_3667EB0);
  j___Init_thread_footer(&dword_46853C4);
  return &unk_46853C0;
}


// address=[0x2f03b70]
// Decompiled from int __thiscall CDestructionManager::~CDestructionManager(CDestructionManager *this)
 CDestructionManager::~CDestructionManager(void) {
  
  unsigned int i; // eax
  void **v2; // eax
  unsigned int v5; // [esp+Ch] [ebp-10h]

  v5 = 0;
  for ( i = std::vector<CDestructor *>::size(this); v5 < i; i = std::vector<CDestructor *>::size(this) )
  {
    v2 = (void **)std::vector<CDestructor *>::operator[](v5);
    operator delete(*v2);
    *(_DWORD *)std::vector<CDestructor *>::operator[](v5++) = 0;
  }
  return std::vector<CDestructor *>::~vector<CDestructor *>();
}


// address=[0x2f051e0]
// Decompiled from CDestructionManager *__thiscall CDestructionManager::CDestructionManager(CDestructionManager *this)
 CDestructionManager::CDestructionManager(void) {
  
  CDestructionManager *v2; // [esp+0h] [ebp-4h]

  std::vector<CDestructor *>::vector<CDestructor *>(this);
  return v2;
}


