#include "CWalkingWorker.h"

#include "CTile.h"
#include "ITiling.h"
#include "Defines/Walking.h"

// Definitions for class CWalkingWorker

// address=[0x15f90b0]
// Decompiled from CWalkingWorker *__thiscall CWalkingWorker::CWalkingWorker(CWalkingWorker *this, int a2)
CWalkingWorker::CWalkingWorker(int a2) : CWalkingBase(0, a2) {
  this->m_sData.m_iEntityFlags |= 0x10u;
}


// address=[0x15fafd0]
// Decompiled from CWalking *__thiscall CWalkingWorker::~CWalkingWorker(CWalkingWorker *this)
CWalkingWorker::~CWalkingWorker(void) {
  return CWalkingBase::~CWalkingBase(this);
}


// address=[0x15fb290]
// Decompiled from int CWalkingWorker::GetWalkingType()
T_WALKING_TYPE const CWalkingWorker::GetWalkingType(void) {
  return WALKING_TYPE_WORKER;
}


// address=[0x15f90f0]
// Decompiled from bool __thiscall CWalkingWorker::IsNotBlocked(CWalkingWorker *this, int a2)
bool CWalkingWorker::IsNotBlocked(int a2) {
  int iTileId = ITiling::NormalTileId(a2);
  if(iTileId < 10)
    return 0;
  const CTile &rTile = ITiling::Tile(iTileId);
  return rTile.OwnerId() == CWalkingBase::OwnerId();
}


// address=[0x15f9150]
// Decompiled from int __thiscall CWalkingWorker::SectorId(CWalkingWorker *this, int a2)
int CWalkingWorker::SectorId(int a2) {
  return ITiling::EcoSectorId(a2);
}


// address=[0x15f9170]
// Decompiled from char __thiscall CWalkingWorker::FindPathAStar64(  CWalkingWorker *this,  unsigned int a2,  unsigned int a3,  struct CDirCache *a4)
bool CWalkingWorker::FindPathAStar64(int a2, int a3, class CDirCache &a4) {
  return g_cAStar64Worker->FindPath(a2, a3, a4);
}


