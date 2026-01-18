#include "GameMessage.h"

// Definitions for class GameMessage

// address=[0x161ce80]
// Decompiled from OnlineManager::GameMessage *__thiscall OnlineManager::GameMessage::GameMessage(  OnlineManager::GameMessage *this,  const struct OnlineManager::GameMessage *a2)
 OnlineManager::GameMessage::GameMessage(struct OnlineManager::GameMessage const & a2) {
  
  storm::DataBuffer::DataBuffer(this, a2);
  *((_DWORD *)this + 8) = *((_DWORD *)a2 + 8);
  return this;
}


// address=[0x161cec0]
// Decompiled from OnlineManager::GameMessage *__thiscall OnlineManager::GameMessage::GameMessage(OnlineManager::GameMessage *this)
 OnlineManager::GameMessage::GameMessage(void) {
  
  storm::DataBuffer::DataBuffer(this);
  return this;
}


// address=[0x161d8f0]
// Decompiled from void __thiscall OnlineManager::GameMessage::~GameMessage(OnlineManager::GameMessage *this)
 OnlineManager::GameMessage::~GameMessage(void) {
  
  storm::DataBuffer::~DataBuffer(this);
}


