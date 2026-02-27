#if FALSE
#include "CSavedPlayer.h"

// Definitions for class CSavedPlayer

// address=[0x13eb720]
// Decompiled from void __thiscall CSavedPlayer::Load(CSavedPlayer *this, struct IS4Chunk *a2)
void  CSavedPlayer::Load(class IS4Chunk & a2) {
  
  int uVersion; // [esp+0h] [ebp-8h] BYREF

  uVersion = 0;
  a2->Load(&uVersion, 4);
  if ( uVersion != 1 && BBSupportDbgReport(2, "LoadSave\\GeneralChunk.cpp", 38, "VERSION==1") == 1 )
    __debugbreak();
  if ( uVersion == 1 )
  {
    a2->Load(this, 4);
    a2->Load(this->m_swName, 64);
    a2->Load(&this->m_uColor, 4);
    a2->Load(&this->m_uStartX, 4);
    a2->Load(&this->m_uStartY, 4);
    a2->Load(&this->m_uTeam, 1);
  }
}


// address=[0x13eb7f0]
// Decompiled from void __thiscall CSavedPlayer::Save(CSavedPlayer *this, struct IS4Chunk *a2)
void  CSavedPlayer::Save(class IS4Chunk & a2) {
  
  int uVersion; // [esp+0h] [ebp-8h] BYREF

  uVersion = 1;
  a2->Save(&uVersion, 4);
  a2->Save(this, 4);
  a2->Save(this->m_swName, 64u);
  a2->Save(&this->m_uColor, 4);
  a2->Save(&this->m_uStartX, 4);
  a2->Save(&this->m_uStartY, 4);
  a2->Save(&this->m_uTeam, 1);
}


#endif // Already implemented
