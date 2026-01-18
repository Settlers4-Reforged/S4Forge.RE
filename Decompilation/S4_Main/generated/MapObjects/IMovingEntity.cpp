#include "IMovingEntity.h"

// Definitions for class IMovingEntity

// address=[0x130eb80]
// Decompiled from int __thiscall IMovingEntity::GetActualTask(IMovingEntity *this)
class CEntityTask const &  IMovingEntity::GetActualTask(void)const {
  
  return std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator*((char *)this + 88);
}


// address=[0x130f500]
// Decompiled from int __thiscall IMovingEntity::Walking(IMovingEntity *this)
class CWalking *  IMovingEntity::Walking(void) {
  
  return std::auto_ptr<CWalking>::get((char *)this + 80, this);
}


// address=[0x1351ad0]
// Decompiled from int __thiscall IMovingEntity::Direction(IMovingEntity *this)
int  IMovingEntity::Direction(void)const {
  
  return *((char *)this + 68);
}


// address=[0x1351af0]
// Decompiled from int __thiscall IMovingEntity::Distance(IMovingEntity *this)
int  IMovingEntity::Distance(void)const {
  
  return *((unsigned __int8 *)this + 69);
}


// address=[0x1460610]
// Decompiled from int __thiscall IMovingEntity::GetJobPart(IMovingEntity *this)
int  IMovingEntity::GetJobPart(void)const {
  
  return *((unsigned __int16 *)this + 19);
}


// address=[0x1470a80]
// Decompiled from bool __thiscall IMovingEntity::IsFree(IMovingEntity *this, int a2)
bool  IMovingEntity::IsFree(int a2) {
  
  if ( IMovingEntity::IsNotBlocked(this, a2) )
    return IMovingEntity::IsNotOccupied(this, a2);
  else
    return 0;
}


// address=[0x14d86e0]
// Decompiled from char __thiscall IMovingEntity::IsUnEmployed(IMovingEntity *this)
bool  IMovingEntity::IsUnEmployed(void)const {
  
  if ( BBSupportDbgReport(
         0,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\mapobjects\\MovingEntity.h",
         174,
         "Nearly virtual function IMovingEntity::IsUnEmployed called") == 1 )
    __debugbreak();
  return 0;
}


// address=[0x14e2fd0]
// Decompiled from int __thiscall IMovingEntity::IncToDoListIter(IMovingEntity *this)
void  IMovingEntity::IncToDoListIter(void) {
  
  return std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++((char *)this + 88);
}


// address=[0x150b590]
// Decompiled from void __thiscall IMovingEntity::SetDisplacementCosts(IMovingEntity *this, char a2)
void  IMovingEntity::SetDisplacementCosts(int a2) {
  
  this->displacementCosts = a2;
}


// address=[0x1513b10]
// Decompiled from IMovingEntity *__thiscall IMovingEntity::SetDirection(IMovingEntity *this, char a2)
void  IMovingEntity::SetDirection(int a2) {
  
  IMovingEntity *result; // eax

  result = this;
  *((_BYTE *)this + 68) = a2;
  return result;
}


// address=[0x15590a0]
// Decompiled from IMovingEntity *__thiscall IMovingEntity::IMovingEntity(IMovingEntity *this, int a2)
 IMovingEntity::IMovingEntity(int a2) {
  
  IAnimatedEntity::IAnimatedEntity(this, a2);
  this->__vftable = (IMovingEntity_vtbl *)&IMovingEntity::_vftable_;
  std::auto_ptr<CWalking>::auto_ptr<CWalking>(&this->walking, 0);
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(&this->unk_58);
  this->someRandomNumber = 0;
  LOBYTE(this->displacementCosts) = 0;
  return this;
}


// address=[0x1559130]
// Decompiled from void __thiscall IMovingEntity::~IMovingEntity(IMovingEntity *this)
 IMovingEntity::~IMovingEntity(void) {
  
  *(_DWORD *)this = &IMovingEntity::_vftable_;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>((char *)this + 88);
  std::auto_ptr<CWalking>::~auto_ptr<CWalking>((char *)this + 80);
  IAnimatedEntity::~IAnimatedEntity(this);
}


// address=[0x1559170]
// Decompiled from int __thiscall IMovingEntity::WalkToXY(IMovingEntity *this, int a2, int a3)
void  IMovingEntity::WalkToXY(int a2, int a3) {
  
  int v3; // eax

  v3 = std::auto_ptr<CWalking>::operator->(this);
  return (*(int (__thiscall **)(int, int, int))(*(_DWORD *)v3 + 8))(v3, a2, a3);
}


// address=[0x15591b0]
// Decompiled from int __thiscall IMovingEntity::NewToDoList(_DWORD *this, int a2, __int16 a3)
void  IMovingEntity::NewToDoList(class std::list<class CEntityTask,class std::allocator<class CEntityTask> > * a2, int a3) {
  
  int result; // eax
  _BYTE v4[12]; // [esp+4h] [ebp-24h] BYREF
  int v5; // [esp+10h] [ebp-18h]
  int v6; // [esp+14h] [ebp-14h]
  _DWORD *v7; // [esp+18h] [ebp-10h]
  int v8; // [esp+24h] [ebp-4h]

  v7 = this;
  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\MovingEntity.cpp", 152, "_toDo != NULL") == 1 )
    __debugbreak();
  v7[21] = a2;
  v6 = std::list<CEntityTask>::begin(v4);
  v5 = v6;
  v8 = 0;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=(v6);
  v8 = -1;
  result = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v4);
  *((_WORD *)v7 + 36) = a3;
  return result;
}


// address=[0x1559260]
// Decompiled from int __thiscall IMovingEntity::ResetToDoList(IMovingEntity *this)
void  IMovingEntity::ResetToDoList(void) {
  
  _BYTE v2[12]; // [esp+4h] [ebp-38h] BYREF
  _BYTE v3[12]; // [esp+10h] [ebp-2Ch] BYREF
  int v4; // [esp+1Ch] [ebp-20h]
  int v5; // [esp+20h] [ebp-1Ch]
  int v6; // [esp+24h] [ebp-18h]
  int v7; // [esp+28h] [ebp-14h]
  IMovingEntity *v8; // [esp+2Ch] [ebp-10h]
  int v9; // [esp+38h] [ebp-4h]

  v8 = this;
  if ( !*((_DWORD *)this + 21) && BBSupportDbgReport(2, "MapObjects\\MovingEntity.cpp", 183, "m_toDoList != NULL") == 1 )
    __debugbreak();
  if ( *((_DWORD *)v8 + 21) )
  {
    v7 = std::list<CEntityTask>::begin(v3);
    v6 = v7;
    v9 = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=(v7);
    v9 = -1;
    return std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v3);
  }
  else
  {
    v5 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v2);
    v4 = v5;
    v9 = 1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=(v5);
    v9 = -1;
    return std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v2);
  }
}


// address=[0x1559340]
// Decompiled from int __thiscall IMovingEntity::SetToDoList(_DWORD *this, int a2)
void  IMovingEntity::SetToDoList(class std::list<class CEntityTask,class std::allocator<class CEntityTask> > * a2) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-24h] BYREF
  int v4; // [esp+10h] [ebp-18h]
  int v5; // [esp+14h] [ebp-14h]
  _DWORD *v6; // [esp+18h] [ebp-10h]
  int v7; // [esp+24h] [ebp-4h]

  v6 = this;
  this[21] = a2;
  *((_WORD *)v6 + 36) = -1;
  if ( !v6[21] && BBSupportDbgReport(2, "MapObjects\\MovingEntity.cpp", 171, "m_toDoList != nullptr") == 1 )
    __debugbreak();
  v5 = std::list<CEntityTask>::begin(v3);
  v4 = v5;
  v7 = 0;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=(v5);
  v7 = -1;
  return std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v3);
}


// address=[0x1559400]
// Decompiled from int __thiscall IMovingEntity::IsNotOccupied(IMovingEntity *this, int a2)
bool  IMovingEntity::IsNotOccupied(int a2) {
  
  int v3; // [esp+4h] [ebp-4h]

  v3 = std::auto_ptr<CWalking>::operator->(&this->walking);
  return (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 24))(v3, a2);
}


// address=[0x1559430]
// Decompiled from bool __thiscall IMovingEntity::IsNotBlocked(IMovingEntity *this, int a2)
bool  IMovingEntity::IsNotBlocked(int a2) {
  
  int v3; // [esp+4h] [ebp-4h]

  v3 = std::auto_ptr<CWalking>::operator->(&this->walking);
  return (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 20))(v3, a2);
}


// address=[0x1563870]
// Decompiled from bool __thiscall IMovingEntity::IsEndIter(IMovingEntity *this)
bool  IMovingEntity::IsEndIter(void) {
  
  _BYTE v2[12]; // [esp+4h] [ebp-28h] BYREF
  std::_Iterator_base12 *v3; // [esp+10h] [ebp-1Ch]
  std::_Iterator_base12 *v4; // [esp+14h] [ebp-18h]
  IMovingEntity *v5; // [esp+18h] [ebp-14h]
  bool v6; // [esp+1Eh] [ebp-Eh]
  bool v7; // [esp+1Fh] [ebp-Dh]
  int v8; // [esp+28h] [ebp-4h]

  v5 = this;
  v4 = (std::_Iterator_base12 *)std::list<CEntityTask>::end(v2);
  v3 = v4;
  v8 = 0;
  v7 = (unsigned __int8)std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator==(v4) != 0;
  v6 = v7;
  v8 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v2);
  return v6;
}


// address=[0x1563980]
// Decompiled from IMovingEntity *__thiscall IMovingEntity::SetDistance(IMovingEntity *this, char a2)
void  IMovingEntity::SetDistance(int a2) {
  
  IMovingEntity *result; // eax

  result = this;
  *((_BYTE *)this + 69) = a2;
  return result;
}


// address=[0x1568790]
// Decompiled from int __thiscall IMovingEntity::GetActualIter(char *this, int a2)
class std::_List_iterator<class std::_List_val<struct std::_List_simple_types<class CEntityTask> > > const  IMovingEntity::GetActualIter(void a2)const {
  
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(this + 88);
  return a2;
}


// address=[0x15d6230]
// Decompiled from int __thiscall IMovingEntity::DisplacementCosts(IMovingEntity *this)
int  IMovingEntity::DisplacementCosts(void)const {
  
  return this->displacementCosts;
}


// address=[0x14d8840]
// Decompiled from char __thiscall IMovingEntity::SetPositionAndDir(IMovingEntity *this, int a2, char a3)
void  IMovingEntity::SetPositionAndDir(int a2, int a3) {
  
  char result; // al

  *((_DWORD *)this + 6) = a2;
  result = a3;
  *((_BYTE *)this + 68) = a3;
  return result;
}


// address=[0x1559460]
// Decompiled from _DWORD *__thiscall sub_1959460(_DWORD *this, int a2)
 IMovingEntity::IMovingEntity(std::istream & a2) {
  
  int v2; // eax
  _DWORD *v3; // eax
  _BYTE v5[4]; // [esp+4h] [ebp-2Ch] BYREF
  _BYTE v6[4]; // [esp+8h] [ebp-28h] BYREF
  int v7; // [esp+Ch] [ebp-24h]
  int v8; // [esp+10h] [ebp-20h]
  int v9; // [esp+14h] [ebp-1Ch] BYREF
  int pExceptionObject; // [esp+18h] [ebp-18h] BYREF
  _DWORD *v11; // [esp+1Ch] [ebp-14h]
  char v12; // [esp+23h] [ebp-Dh] BYREF
  int v13; // [esp+2Ch] [ebp-4h]

  v11 = this;
  IAnimatedEntity::IAnimatedEntity(a2);
  v13 = 0;
  *v11 = &IMovingEntity::_vftable_;
  std::auto_ptr<CWalking>::auto_ptr<CWalking>(0);
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v11 + 22);
  LOBYTE(v13) = 2;
  v11[21] = 0;
  operator^<unsigned int>(a2, &v9);
  v8 = v9;
  if ( v9 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for IMovingEntity");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<signed char>(a2, v11 + 17);
  operator^<unsigned char>(a2, (char *)v11 + 69);
  operator^<unsigned char>(a2, (char *)v11 + 70);
  operator^<int>(a2, (int)(v11 + 19));
  v12 = 0;
  operator^<bool>(a2, &v12);
  if ( v12 )
  {
    v2 = CWalking::Create(a2);
    v7 = std::auto_ptr<CWalking>::auto_ptr<CWalking>(v2);
    v3 = (_DWORD *)std::auto_ptr<CWalking>::operator<CWalking> std::auto_ptr_ref<CWalking>(v5);
    std::auto_ptr<CWalking>::operator=(*v3);
    std::auto_ptr<CWalking>::~auto_ptr<CWalking>(v6);
  }
  v13 = -1;
  return v11;
}


// address=[0x15595e0]
// Decompiled from struct std::ostream *__thiscall IMovingEntity::Store(IMovingEntity *this, struct std::ostream *a1)
void  IMovingEntity::Store(std::ostream & a2) {
  
  struct std::ostream *result; // eax
  int v3; // [esp+0h] [ebp-14h] BYREF
  int (__thiscall ***v4)(_DWORD, struct std::ostream *); // [esp+4h] [ebp-10h]
  BOOL v5; // [esp+8h] [ebp-Ch]
  bool v7; // [esp+13h] [ebp-1h] BYREF

  IAnimatedEntity::Store(this, a1);
  v3 = 1;
  operator^<unsigned int>(a1, &v3);
  operator^<signed char>(a1, &this->someRandomNumber);
  operator^<unsigned char>(a1, &this->unk_45);
  operator^<unsigned char>(a1, &this->displacementCosts);
  operator^<int>(a1, (int *)&this->unk_4c);
  v5 = std::auto_ptr<CWalking>::get(&this->walking) != 0;
  v7 = v5;
  result = operator^<bool>(a1, (char *)&v7);
  if ( !v7 )
    return result;
  v4 = (int (__thiscall ***)(_DWORD, struct std::ostream *))std::auto_ptr<CWalking>::operator->(&this->walking);
  return (struct std::ostream *)(**v4)(v4, a1);
}


// address=[0x15596c0]
// Decompiled from IMovingEntity *__thiscall IMovingEntity::InitDistance(IMovingEntity *this)
void  IMovingEntity::InitDistance(void) {
  
  IMovingEntity *result; // eax

  result = this;
  *((_BYTE *)this + 69) = -1;
  return result;
}


// address=[0x15596e0]
// Decompiled from IMovingEntity *__thiscall IMovingEntity::DecDistance(IMovingEntity *this, unsigned int a2)
void  IMovingEntity::DecDistance(unsigned int a2) {
  
  IMovingEntity *result; // eax
  char v3; // dl

  result = this;
  if ( a2 >= *((unsigned __int8 *)this + 69) )
  {
    *((_BYTE *)this + 69) = 0;
  }
  else
  {
    if ( *((unsigned __int8 *)this + 69) == 255 )
      v3 = *((_BYTE *)this + 69) + 1;
    else
      v3 = *((_BYTE *)this + 69);
    result = this;
    *((_BYTE *)this + 69) = v3 - a2;
  }
  return result;
}


