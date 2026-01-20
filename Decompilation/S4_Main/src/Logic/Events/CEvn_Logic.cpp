#include "CEvn_Logic.h"

#include "CBB/CBBSupport.h"
#include "../../LoadSave/IS4Chunk.h"

// Definitions for class CEvn_Logic

// address=[0x130e470]
// Decompiled from _DWORD *__thiscall CEvn_Logic::~CEvn_Logic(CEvn_Logic *this)
//  CEvn_Logic::~CEvn_Logic(void) {

//   return CEvn_Event::~CEvn_Event(this);
// }

// address=[0x1334e60]
// Decompiled from CEvn_Logic *__thiscall CEvn_Logic::CEvn_Logic(  CEvn_Logic *this,  uint a2,  uint a3,  uint a4,  uchar a5,  uint a6,  ushort a7)
CEvn_Logic::CEvn_Logic(unsigned int a2, unsigned int a3, unsigned int a4, unsigned char a5, unsigned int a6, unsigned short a7) : CEvn_Event(a2, a3, a4, 0)
{
  this->m_iOwner = a5;
  // This seeeeeems to be an array of values. At least it saves/loads it as such. Example of it being used as one: 0x1459E00 CInputProcessor::DefineGroup
  this->m_iData = reinterpret_cast<void *>(a6);
  this->m_iDataSize = a7;
}

// address=[0x1355030]
// Decompiled from CEvn_Logic *__thiscall CEvn_Logic::CEvn_Logic(CEvn_Logic *this)
CEvn_Logic::CEvn_Logic(void) : CEvn_Event(0, 0, 0, 0)
{
  this->m_iOwner = 0;
  this->m_iData = 0;
  this->m_iDataSize = 0;
}

// address=[0x13570f0]
// Decompiled from void __thiscall CEvn_Logic::Load(CEvn_Logic *this, struct IS4Chunk *a2)
void CEvn_Logic::Load(class IS4Chunk &a2)
{
  a2.Load(&this->m_iTick, 4);
  a2.Load(&this->m_iOwner, 1);
  a2.Load(&this->m_lParam, 4);
  a2.Load(&this->m_iEventId, 4);
  a2.Load(&this->m_wParam, 4);
  if (this->m_iDataSize)
  {
    this->m_iData = (BYTE *)operator new[](this->m_iDataSize);
    a2.Load(this->m_iData, this->m_iDataSize);
  }
}

// address=[0x13571b0]
// Decompiled from void __thiscall CEvn_Logic::Save(CEvn_Logic *this, struct IS4Chunk *a2)
void CEvn_Logic::Save(class IS4Chunk &a2)
{

  a2.Save(&this->m_iTick, 4);
  a2.Save(&this->m_iOwner, 1);
  a2.Save(&this->m_lParam, 4);
  a2.Save(&this->m_iEventId, 4);
  a2.Save(&this->m_wParam, 4);
  if (this->m_iDataSize)
  {
    if (!this->m_iData && BBSupportDbgReportF(2,"EventEngine\\Evn_HandleLogic.cpp",27,"m_iData != 0: m_iOwner: 0x%x, m_lParam: 0x%x, m_Message: 0x%x, m_wParam: 0x%x, m_iDataSize: 0x%x",this->m_iOwner,this->m_lParam,this->m_iEventId,this->m_wParam,this->m_iDataSize) == 1)
    {
      __debugbreak();
    }
    a2.Save(this->m_iData, this->m_iDataSize);
  }
}

// address=[0x145fff0]
// Decompiled from CEvn_Logic *__thiscall CEvn_Logic::CEvn_Logic(CEvn_Logic *this, CEvn_Logic *a2)
CEvn_Logic::CEvn_Logic(CEvn_Logic const &a2) : CEvn_Event(a2)
{
  this->m_iData = a2.m_iData;
  this->m_iDataSize = a2.m_iDataSize;
  this->m_iOwner = a2.m_iOwner;
  this->m_iUnknown = a2.m_iUnknown;
}

// address=[0x1486be0]
// Decompiled from CEvn_Logic *__thiscall CEvn_Logic::operator=(CEvn_Logic *this, CEvn_Logic *a2)
class CEvn_Logic &CEvn_Logic::operator=(class CEvn_Logic const &a2)
{
  CEvn_Event::operator=(a2);
  this->m_iData = a2.m_iData;
  this->m_iDataSize = a2.m_iDataSize;
  this->m_iOwner = a2.m_iOwner;
  this->m_iUnknown = a2.m_iUnknown;
  return *this;
}
