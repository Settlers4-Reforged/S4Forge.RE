#include "GameSessionHandler.h"

// Definitions for class GameSessionHandler

// address=[0x164d6e0]
// Decompiled from GameSessionHandler *__thiscall GameSessionHandler::GameSessionHandler(GameSessionHandler *this)
 GameSessionHandler::GameSessionHandler(void) {
  
  storm::SimpleSessionHandler::SimpleSessionHandler(this);
  *(_DWORD *)this = &GameSessionHandler::_vftable_;
  *((_DWORD *)this + 7) = &GameSessionHandler::`vftable';
  *((_BYTE *)this + 236) = 0;
  return this;
}


// address=[0x1684b00]
// Decompiled from void __thiscall GameSessionHandler::~GameSessionHandler(GameSessionHandler *this)
 GameSessionHandler::~GameSessionHandler(void) {
  
  storm::SimpleSessionHandler::~SimpleSessionHandler(this);
}


// address=[0x1689550]
// Decompiled from int *GameSessionHandler::GetClassTypeName()
char const * __cdecl GameSessionHandler::GetClassTypeName(void) {
  
  return &dword_3834C88[1];
}


// address=[0x16895c0]
// Decompiled from int GameSessionHandler::GetClassTypeStaticCrc()
unsigned long __cdecl GameSessionHandler::GetClassTypeStaticCrc(void) {
  
  return 1608834342;
}


