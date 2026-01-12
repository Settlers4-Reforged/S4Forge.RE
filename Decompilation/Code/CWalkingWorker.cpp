#include "CWalkingWorker.h"

// Definitions for class CWalkingWorker

// address=[0x15f90b0]
// Decompiled from CWalkingWorker *__thiscall CWalkingWorker::CWalkingWorker(CWalkingWorker *this, int a2)
 CWalkingWorker::CWalkingWorker(int) {
  
  CWalkingBase::CWalkingBase(this, 0, a2);
  *(_DWORD *)this = &CWalkingWorker::_vftable_;
  *((_DWORD *)this + 13) |= 0x10u;
  return this;
}


// address=[0x15fafd0]
// Decompiled from CWalking *__thiscall CWalkingWorker::~CWalkingWorker(CWalkingWorker *this)
 CWalkingWorker::~CWalkingWorker(void) {
  
  return CWalkingBase::~CWalkingBase(this);
}


// address=[0x15fb290]
// Decompiled from int CWalkingWorker::GetWalkingType()
enum T_WALKING_TYPE const  CWalkingWorker::GetWalkingType(void) {
  
  return 1;
}


// address=[0x15f90f0]
// Decompiled from bool __thiscall CWalkingWorker::IsNotBlocked(CWalkingWorker *this, int a2)
bool  CWalkingWorker::IsNotBlocked(int) {
  
  CTile *v2; // eax
  int v3; // esi
  int v6; // [esp+Ch] [ebp-4h]

  v6 = ITiling::NormalTileId(a2);
  if ( v6 < 10 )
    return 0;
  v2 = (CTile *)ITiling::Tile(v6);
  v3 = CTile::OwnerId(v2);
  return v3 == CWalkingBase::OwnerId(this);
}


// address=[0x15f9150]
// Decompiled from int __thiscall CWalkingWorker::SectorId(CWalkingWorker *this, int a2)
int  CWalkingWorker::SectorId(int) {
  
  return ITiling::EcoSectorId(a2);
}


// address=[0x15f9170]
// Decompiled from char __thiscall CWalkingWorker::FindPathAStar64(CWalkingWorker *this, int a2, int a3, struct CDirCache *a4)
bool  CWalkingWorker::FindPathAStar64(int,int,class CDirCache &) {
  
  return CAStar64::FindPath((CAStar64 *)&g_cAStar64Worker, a2, a3, a4);
}


