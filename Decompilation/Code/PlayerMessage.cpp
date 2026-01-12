#include "PlayerMessage.h"

// Definitions for class PlayerMessage

// address=[0x161cee0]
// Decompiled from OnlineManager::PlayerMessage *__thiscall OnlineManager::PlayerMessage::PlayerMessage(
        OnlineManager::PlayerMessage *this)

 OnlineManager::PlayerMessage::PlayerMessage(void) {
  
  std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>((char *)this + 24);
  std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>((char *)this + 52);
  return this;
}


// address=[0x161d950]
// Decompiled from void __thiscall OnlineManager::PlayerMessage::~PlayerMessage(OnlineManager::PlayerMessage *this)

 OnlineManager::PlayerMessage::~PlayerMessage(void) {
  
  std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::~basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>((char *)this + 52);
  std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::~basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>((char *)this + 24);
}


// address=[0x161de20]
// Decompiled from _DWORD *__thiscall OnlineManager::PlayerMessage::operator=(_DWORD *this, int a2)

struct OnlineManager::PlayerMessage &  OnlineManager::PlayerMessage::operator=(struct OnlineManager::PlayerMessage const &) {
  
  *(_BYTE *)this = *(_BYTE *)a2;
  this[1] = *(_DWORD *)(a2 + 4);
  this[2] = *(_DWORD *)(a2 + 8);
  this[3] = *(_DWORD *)(a2 + 12);
  this[4] = *(_DWORD *)(a2 + 16);
  this[5] = *(_DWORD *)(a2 + 20);
  std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::operator=(a2 + 24);
  std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::operator=(a2 + 52);
  return this;
}


