#include "IMovingEntity.h"

// Definitions for class IMovingEntity

// address=[0x130eb80]
// Decompiled from CEntityTask *__thiscall IMovingEntity::GetActualTask(IMovingEntity *this)
class CEntityTask const &  IMovingEntity::GetActualTask(void)const {
  
  return (CEntityTask *)std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator*(&this->m_cCurrentToDoItemIter);
}


// address=[0x130f500]
// Decompiled from struct CWalking *__thiscall IMovingEntity::Walking(IMovingEntity *this)
class CWalking *  IMovingEntity::Walking(void) {
  
  return (struct CWalking *)std::auto_ptr<CWalking>::get(&this->m_pWalkin);
}


// address=[0x1351ad0]
// Decompiled from int __thiscall IMovingEntity::Direction(IMovingEntity *this)
int  IMovingEntity::Direction(void)const {
  
  return this->m_iDirection;
}


// address=[0x1351af0]
// Decompiled from int __thiscall IMovingEntity::Distance(IMovingEntity *this)
int  IMovingEntity::Distance(void)const {
  
  return this->m_iDistance;
}


// address=[0x1460610]
// Decompiled from int __thiscall IMovingEntity::GetJobPart(IMovingEntity *this)
int  IMovingEntity::GetJobPart(void)const {
  
  return this->m_iJobPart;
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
  
  return std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(&this->m_cCurrentToDoItemIter);
}


// address=[0x150b590]
// Decompiled from void __thiscall IMovingEntity::SetDisplacementCosts(IMovingEntity *this, char a2)
void  IMovingEntity::SetDisplacementCosts(int a2) {
  
  this->m_iDisplacementCosts = a2;
}


// address=[0x1513b10]
// Decompiled from void __thiscall IMovingEntity::SetDirection(IMovingEntity *this, char a2)
void  IMovingEntity::SetDirection(int a2) {
  
  this->m_iDirection = a2;
}


// address=[0x15590a0]
// Decompiled from IMovingEntity *__thiscall IMovingEntity::IMovingEntity(IMovingEntity *this, int id)
 IMovingEntity::IMovingEntity(int id) {
  
  IAnimatedEntity::IAnimatedEntity(this, id);
  this->__vftable = (IMovingEntity_vtbl *)&IMovingEntity::_vftable_;
  std::auto_ptr<CWalking>::auto_ptr<CWalking>(&this->m_pWalkin, 0);
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(&this->m_cCurrentToDoItemIter);
  this->m_iDirection = 0;
  this->m_iDistance = 0;
  this->m_iDisplacementCosts = 0;
  return this;
}


// address=[0x1559130]
// Decompiled from int __thiscall IMovingEntity::~IMovingEntity(IMovingEntity *this)
 IMovingEntity::~IMovingEntity(void) {
  
  this->__vftable = (IMovingEntity_vtbl *)&IMovingEntity::_vftable_;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(&this->m_cCurrentToDoItemIter);
  std::auto_ptr<CWalking>::~auto_ptr<CWalking>(&this->m_pWalkin);
  return IAnimatedEntity::~IAnimatedEntity(this);
}


// address=[0x1559170]
// Decompiled from int __thiscall IMovingEntity::WalkToXY(IMovingEntity *this, int a2, int a3)
void  IMovingEntity::WalkToXY(int a2, int a3) {
  
  int v3; // eax

  v3 = std::auto_ptr<CWalking>::operator->(&this->m_pWalkin);
  return (*(int (__thiscall **)(int, int, int))(*(_DWORD *)v3 + 8))(v3, a2, a3);
}


// address=[0x15591b0]
// Decompiled from void __thiscall IMovingEntity::NewToDoList(IMovingEntity *this, DWORD _toDo, __int16 a3)
void  IMovingEntity::NewToDoList(class std::list<class CEntityTask,class std::allocator<class CEntityTask> > * _toDo, int a3) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-24h] BYREF
  int v4; // [esp+10h] [ebp-18h]
  int v5; // [esp+14h] [ebp-14h]
  int v7; // [esp+24h] [ebp-4h]

  if ( !_toDo && BBSupportDbgReport(2, "MapObjects\\MovingEntity.cpp", 152, "_toDo != NULL") == 1 )
    __debugbreak();
  this->m_pToDoList = _toDo;
  v5 = std::list<CEntityTask>::begin((void *)this->m_pToDoList, (int)v3);
  v4 = v5;
  v7 = 0;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=(
    &this->m_cCurrentToDoItemIter,
    v5);
  v7 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v3);
  this->m_iToDoSize = a3;
}


// address=[0x1559260]
// Decompiled from int __thiscall IMovingEntity::ResetToDoList(IMovingEntity *this)
void  IMovingEntity::ResetToDoList(void) {
  
  _BYTE v2[12]; // [esp+4h] [ebp-38h] BYREF
  _BYTE v3[12]; // [esp+10h] [ebp-2Ch] BYREF
  void *v5; // [esp+20h] [ebp-1Ch] MAPDST
  int v7; // [esp+28h] [ebp-14h] MAPDST
  int exceptionBlock; // [esp+38h] [ebp-4h]

  if ( !this->m_pToDoList && BBSupportDbgReport(2, "MapObjects\\MovingEntity.cpp", 183, "m_toDoList != NULL") == 1 )
    __debugbreak();
  if ( this->m_pToDoList )
  {
    v7 = std::list<CEntityTask>::begin((void *)this->m_pToDoList, (int)v3);
    exceptionBlock = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=(
      &this->m_cCurrentToDoItemIter,
      v7);
    exceptionBlock = -1;
    return std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v3);
  }
  else
  {
    v5 = std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v2);
    exceptionBlock = 1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=(
      &this->m_cCurrentToDoItemIter,
      (int)v5);
    exceptionBlock = -1;
    return std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v2);
  }
}


// address=[0x1559340]
// Decompiled from void __thiscall IMovingEntity::SetToDoList(IMovingEntity *this, DWORD a2)
void  IMovingEntity::SetToDoList(class std::list<class CEntityTask,class std::allocator<class CEntityTask> > * a2) {
  
  _BYTE v2[12]; // [esp+4h] [ebp-24h] BYREF
  int v3; // [esp+10h] [ebp-18h]
  int v4; // [esp+14h] [ebp-14h]
  int v6; // [esp+24h] [ebp-4h]

  this->m_pToDoList = (std::list *)a2;
  this->m_iToDoSize = -1;
  if ( !this->m_pToDoList && BBSupportDbgReport(2, "MapObjects\\MovingEntity.cpp", 171, "m_toDoList != nullptr") == 1 )
    __debugbreak();
  v4 = std::list<CEntityTask>::begin(this->m_pToDoList, (int)v2);
  v3 = v4;
  v6 = 0;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=(
    &this->m_cCurrentToDoItemIter,
    v4);
  v6 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v2);
}


// address=[0x1559400]
// Decompiled from int __thiscall IMovingEntity::IsNotOccupied(IMovingEntity *this, int a2)
bool  IMovingEntity::IsNotOccupied(int a2) {
  
  int v3; // [esp+4h] [ebp-4h]

  v3 = std::auto_ptr<CWalking>::operator->(&this->m_pWalkin);
  return (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 24))(v3, a2);
}


// address=[0x1559430]
// Decompiled from bool __thiscall IMovingEntity::IsNotBlocked(IMovingEntity *this, int a2)
bool  IMovingEntity::IsNotBlocked(int a2) {
  
  int v3; // [esp+4h] [ebp-4h]

  v3 = std::auto_ptr<CWalking>::operator->(&this->m_pWalkin);
  return (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 20))(v3, a2);
}


// address=[0x1563870]
// Decompiled from bool __thiscall IMovingEntity::IsEndIter(IMovingEntity *this)
bool  IMovingEntity::IsEndIter(void) {
  
  _BYTE v2[12]; // [esp+4h] [ebp-28h] BYREF
  std::_Iterator_base12 *v4; // [esp+14h] [ebp-18h] MAPDST
  bool v7; // [esp+1Fh] [ebp-Dh] MAPDST
  int v8; // [esp+28h] [ebp-4h]

  v4 = (std::_Iterator_base12 *)std::list<CEntityTask>::end(this->m_pToDoList);
  v8 = 0;
  v7 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator==(
         (std::_Iterator_base12 *)&this->m_cCurrentToDoItemIter,
         v4);
  v8 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v2);
  return v7;
}


// address=[0x1563980]
// Decompiled from void __thiscall IMovingEntity::SetDistance(IMovingEntity *this, BYTE a2)
void  IMovingEntity::SetDistance(int a2) {
  
  this->m_iDistance = a2;
}


// address=[0x1568790]
// Decompiled from int __thiscall IMovingEntity::GetActualIter(IMovingEntity *this, int a2)
class std::_List_iterator<class std::_List_val<struct std::_List_simple_types<class CEntityTask> > > const  IMovingEntity::GetActualIter(void a2)const {
  
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(&this->m_cCurrentToDoItemIter);
  return a2;
}


// address=[0x15d6230]
// Decompiled from int __thiscall IMovingEntity::DisplacementCosts(IMovingEntity *this)
int  IMovingEntity::DisplacementCosts(void)const {
  
  return this->m_iDisplacementCosts;
}


// address=[0x14d8840]
// Decompiled from void __thiscall IMovingEntity::SetPositionAndDir(IMovingEntity *this, int a2, BYTE a3)
void  IMovingEntity::SetPositionAndDir(int a2, int a3) {
  
  this->m_uPackedXY = a2;
  this->m_iDirection = a3;
}


// address=[0x1559460]
// Decompiled from IMovingEntity *__thiscall IMovingEntity::IMovingEntity(IMovingEntity *this, struct std::istream *_pStream)
 IMovingEntity::IMovingEntity(std::istream & _pStream) {
  
  CWalkingBase *v2; // eax
  _DWORD *v3; // eax
  _BYTE v5[4]; // [esp+4h] [ebp-2Ch] BYREF
  _DWORD v6[3]; // [esp+8h] [ebp-28h] BYREF
  int v7; // [esp+14h] [ebp-1Ch] BYREF
  int pExceptionObject; // [esp+18h] [ebp-18h] BYREF
  char v10; // [esp+23h] [ebp-Dh] BYREF
  int exceptionBlock; // [esp+2Ch] [ebp-4h]

  IAnimatedEntity::IAnimatedEntity(this, _pStream);
  exceptionBlock = 0;
  this->__vftable = (IMovingEntity_vtbl *)&IMovingEntity::_vftable_;
  std::auto_ptr<CWalking>::auto_ptr<CWalking>(&this->m_pWalkin, 0);
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(&this->m_cCurrentToDoItemIter);
  LOBYTE(exceptionBlock) = 2;
  this->m_pToDoList = 0;
  operator^<unsigned int>(_pStream, &v7);
  v6[2] = v7;
  if ( v7 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for IMovingEntity");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<signed char>(_pStream, &this->m_iDirection);
  operator^<unsigned char>(_pStream, &this->m_iDistance);
  operator^<unsigned char>(_pStream, &this->m_iDisplacementCosts);
  operator^<int>(_pStream, (int *)&this->unk_4c);
  v10 = 0;
  operator^<bool>(_pStream, &v10);
  if ( v10 )
  {
    v2 = CWalking::Create(_pStream);
    v6[1] = std::auto_ptr<CWalking>::auto_ptr<CWalking>(v6, (int)v2);
    v3 = (_DWORD *)std::auto_ptr<CWalking>::operator<CWalking> std::auto_ptr_ref<CWalking>(v5);
    std::auto_ptr<CWalking>::operator=(*v3);
    std::auto_ptr<CWalking>::~auto_ptr<CWalking>(v6);
  }
  exceptionBlock = -1;
  return this;
}


// address=[0x15595e0]
// Decompiled from void __thiscall IMovingEntity::Store(IMovingEntity *this, struct std::ostream *a1)
void  IMovingEntity::Store(std::ostream & a1) {
  
  int v2; // [esp+0h] [ebp-14h] BYREF
  void (__thiscall ***v3)(_DWORD, struct std::ostream *); // [esp+4h] [ebp-10h]
  BOOL v4; // [esp+8h] [ebp-Ch]
  bool v6; // [esp+13h] [ebp-1h] BYREF

  IAnimatedEntity::Store(this, a1);
  v2 = 1;
  operator^<unsigned int>(a1, &v2);
  operator^<signed char>(a1, &this->m_iDirection);
  operator^<unsigned char>(a1, &this->m_iDistance);
  operator^<unsigned char>(a1, &this->m_iDisplacementCosts);
  operator^<int>(a1, (int *)&this->unk_4c);
  v4 = std::auto_ptr<CWalking>::get(&this->m_pWalkin) != 0;
  v6 = v4;
  operator^<bool>(a1, (char *)&v6);
  if ( v6 )
  {
    v3 = (void (__thiscall ***)(_DWORD, struct std::ostream *))std::auto_ptr<CWalking>::operator->(&this->m_pWalkin);
    (**v3)(v3, a1);
  }
}


// address=[0x15596c0]
// Decompiled from void __thiscall IMovingEntity::InitDistance(IMovingEntity *this)
void  IMovingEntity::InitDistance(void) {
  
  this->m_iDistance = -1;
}


// address=[0x15596e0]
// Decompiled from void __thiscall IMovingEntity::DecDistance(IMovingEntity *this, unsigned int a2)
void  IMovingEntity::DecDistance(unsigned int a2) {
  
  BYTE m_iDistance; // dl

  if ( a2 >= this->m_iDistance )
  {
    this->m_iDistance = 0;
  }
  else
  {
    if ( this->m_iDistance == 255 )
      m_iDistance = this->m_iDistance + 1;
    else
      m_iDistance = this->m_iDistance;
    this->m_iDistance = m_iDistance - a2;
  }
}


