#include "CDefineTranslator.h"

#include "Defines/Buildings.h"
#include "Defines/Job.h"
#include "Defines/Races.h"
#include "Defines/Tasks.h"
#include "Defines/Triggers.h"

// Definitions for class CDefineTranslator

CDefineTranslator CDefineTranslator::s_cDefineTranslator{};
CDefineTranslator *g_pDefineTranslator = &CDefineTranslator::s_cDefineTranslator;

// address=[0x141dbe0]
// Decompiled from int __thiscall CDefineTranslator::GetValueOfDefine(struct CDefineTranslator *this, struct std::string *a2)
int CDefineTranslator::GetValueOfDefine(std::string const &rDefine) const {
    if(rDefine.empty())
        return 0;

    const auto &rIt = this->m_mDefines.find(rDefine);
    if(rIt != this->m_mDefines.end())
        return rIt->second;

    return 0;
}

// address=[0x14f3f70]
// Decompiled from int CDefineTranslator::Instance()
// class CDefineTranslator & __cdecl CDefineTranslator::Instance(void) {
//   return *CDefineTranslator::GetInstance();
// }

// address=[0x141dcf0]
// Decompiled from void *CDefineTranslator::GetInstance()
// std::shared_ptr<CDefineTranslator> __cdecl CDefineTranslator::GetInstance(void) {
//   static std::shared_ptr<CDefineTranslator> s_pInstance(new CDefineTranslator());
//   if(s_pInstance != nullptr) return s_pInstance;
//
//   s_pInstance =;
//   return s_pInstance;
// }

// address=[0x141ddd0]
// Decompiled from CDefineTranslator *__thiscall CDefineTranslator::CDefineTranslator(CDefineTranslator *this)
CDefineTranslator::CDefineTranslator(void) {
    // NOTE: CDestructionPhase was used here. An only used here class that destroys on end of CGameStateHandler::Kill
    // As we moved to a static instance with global pointer access, this will just be skipped.

#define X_DEFAULT(id, name) this->m_mDefines.insert(std::make_pair(#name, id));

#define X X_DEFAULT
    RACES

    TRIGGERS
    // Some random samples
    static_assert(TRIGGER_COALMINE_PUSHIN == 2);
    static_assert(TRIGGER_CLEAR_SLOT8 == 45);

    HOUSE_KINDS
    static_assert(HOUSE_KIND_ANIMALRANCH == 3);
    static_assert(HOUSE_KIND_CASTLE == 15);

    SEARCHES
    static_assert(SEARCH_MUSHROOM_SEED_POS == 13);
    static_assert(SEARCH_IRON == 19);

#undef X
#define X(id, name) this->m_mDefines.insert(std::make_pair("CDecoObjMgr::" #name, id));
    // TODO: CDecoObjMgr::
#undef X
    /*
  0, CDecoObjMgr::VINE
  1, CDecoObjMgr::AGAVE
  2, CDecoObjMgr::TREE
  3, CDecoObjMgr::GRAIN
  6, CDecoObjMgr::HIVE
  4, CDecoObjMgr::MUSHROOM
  7, CDecoObjMgr::SUNFLOWER
    */

#define X X_DEFAULT
    ROLES
    static_assert(SQUAD_LEADER_ROLE == 23);
    static_assert(MUSHROOMFARMER_ROLE == 15);

#undef X
#define X(id, name) this->m_mDefines.insert(std::make_pair("CEntityTask::" #name, id));
    TASKS
    static_assert(HEAL_ENTITY_VIRTUAL == 35);
    static_assert(GO_TO_POS_ROUGHLY == 33);

#undef X
}

// address=[0x1422bf0]
// Decompiled from int __thiscall CDefineTranslator::~CDefineTranslator(CDefineTranslator *this)
CDefineTranslator::~CDefineTranslator(void) {
    this->Status();
    this->m_mDefines.clear();
}

// address=[0x1422c40]
// Decompiled from char __thiscall CDefineTranslator::Status(CDefineTranslator *this)
bool CDefineTranslator::Status(void) {
    return 0;
}

// address=[0x14269c0]
// Decompiled from CDefineTranslator *CDefineTranslator::DestroyInstance()
// void __cdecl CDefineTranslator::DestroyInstance(void) {
//   int                Instance; // eax
//   CDefineTranslator *result; // eax
//
//   Instance = CDefineTranslator::GetInstance();
//   result = (CDefineTranslator *) std::auto_ptr<CDefineTranslator>::release(Instance);
//   if(result)
//     return (CDefineTranslator *) delete result;
//   return result;
// }
