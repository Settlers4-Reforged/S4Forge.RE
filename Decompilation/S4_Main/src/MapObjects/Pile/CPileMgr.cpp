#include "CPileMgr.h"

#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"
#include "CPile.h"
#include "Defines/Goods.h"
#include "Defines/Map.h"
#include "Defines/Object.h"
#include "Defines/Races.h"
#include "IPileRole.h"
#include "Main/Players/CPlayerManager.h"
#include "MapObjects/CMapObjectMgr.h"
#include "MapObjects/CSpiralOffsets.h"
#include "MapObjects/IEntity.h"
#include "World/CWorldManager.h"
#include "World/helper.h"

#include <sstream>
#include <strstream>

// Definitions for class CPileMgr

CPileMgr g_cPileMgr{};

// address=[0x12fd1f0]
// Decompiled from IEntity *__cdecl CPileMgr::GetPilePtr(int _iPileId)
CPile *__cdecl CPileMgr::GetPilePtr(int _iPileId) {
    // [esp+8h] [ebp-4h]
    IEntity *pPile = CMapObjectMgr::EntityPtr(_iPileId);
    if(!pPile || pPile->ObjType() != PILE_OBJ)
        return 0;

    return dynamic_cast<CPile *>(pPile);
}

// address=[0x1438a40]
// Decompiled from IEntity *__stdcall CPileMgr::operator[](int _iPileId)
class CPile &CPileMgr::operator[](int _iPileId) {
    IEntity *pEntity = CMapObjectMgr::EntityPtr(_iPileId);
    BB_ASSERT(pEntity != 0);
    BB_ASSERT(pEntity->ObjType() == PILE_OBJ);

    CPile *pPile = dynamic_cast<CPile *>(pEntity);
    return *pPile; // NOTE: should these be like this?
}

// address=[0x155e900]
// Decompiled from CPileMgr *__thiscall CPileMgr::CPileMgr(CPileMgr *this)
CPileMgr::CPileMgr(void) : m_cAllocator(0x7Cu, 0x20u, 0) {
    this->m_iPileCount = 0;
    this->m_iU1 = 0;
}

// address=[0x155e930]
// Decompiled from void __thiscall CPileMgr::~CPileMgr(CPileMgr *this)
CPileMgr::~CPileMgr(void) = default;

// address=[0x155e950]
// Decompiled from void __thiscall CPileMgr::Clear(CPileMgr *this)
void CPileMgr::Clear(void) {
    this->m_iPileCount = 0;
}

// address=[0x155e970]
// Decompiled from void __thiscall CPileMgr::LoadPileData(CPileMgr *this, struct S4::CMapFile *a2, int a3)
void CPileMgr::LoadPileData(class S4::CMapFile &_rMap, int a3) {
    int iChunkCount = 0;
    auto pChunks = static_cast<SPileData const *>(_rMap.LoadChunk(MAP_CHUNK_PILES, 0, iChunkCount, 0));
    for(int i = 0; i < iChunkCount; ++i) {
        CPileMgr::SPileData const *pPile = &pChunks[i];

        int iType = pPile->m_uPileType == 254 ? IPileRole::PILE_ANYWHERE : IPileRole::PILE_STORAGE;
        CPileMgr::AddPile(pPile->m_iX, pPile->m_iY, pPile->m_iGood, pPile->m_iAmount, iType, 0, 0, 0, 0);
    }
}

// address=[0x155ea20]
// Decompiled from int __thiscall CPileMgr::AddPile(  CPileMgr *this,  int _iX,  int _iY,  int _iGood,  int _iAmount,  int _iType,  int a7,  int a8,  int a9,  int a11)
int CPileMgr::AddPile(int _iX, int _iY, int _iGood, int _iAmount, int _iType, int a7, int a8, int a9, int a11) {
    BB_ASSERT(g_cWorld.InWorld(_iX, _iY))
    BB_ASSERT(_iGood >= 0 && _iGood < GOOD_MAX)
    BB_ASSERT(_iAmount >= 0 && _iAmount <= CPile::MAX_PILE_AMOUNT)
    BB_ASSERT(_iType >= 0 && _iType <= IPileRole::PILE_BUILDINGSITE)

    // if(debug && DEBUG_FLAGS[dword_415207C])
    //     BBSupportTracePrintF(0, "New pile  at %u %u good %u type %u", _iX, _iY, _iGood, _iType);

    if(this->m_iPileCount >= MAX_PILE_COUNT) {
        BBSupportTracePrintF(0, "NO more piles!!!");
        return 0;
    }

    ++this->m_iPileCount;

    std::unique_ptr<IPileRole> pPileRole(CPileMgr::CreatePileRole(_iType));

    int iSlot = CMapObjectMgr::GetFreeSlot();
    new CPile(_iX, _iY, _iGood, _iAmount, std::move(pPileRole), iSlot, a7, a8, a9, a11);
    return iSlot;
}

// address=[0x155ec40]
// Decompiled from void __thiscall CPileMgr::DeletePile(CPileMgr *this, int _iPileId)
void CPileMgr::DeletePile(int _iPileId) {
    BB_ASSERT(_iPileId > 0)
    BB_ASSERT(g_cPileMgr[_iPileId].AmountLeaving() == 0)
    BB_ASSERT(g_cPileMgr[_iPileId].AmountComing() == 0)
    // if(debug && DEBUG_FLAGS[dword_4152080]) {
    //     BBSupportTracePrintF(0, "DeletePile");
    //     CPileMgr::TracePile(_iPileId);
    // }

    if(!_iPileId)
        return;

    --this->m_iPileCount;
    g_pMapObjectMgr->Kill(_iPileId, 0);
}

// address=[0x155ed50]
// Decompiled from void __thiscall CPileMgr::DeletePileUnforeseen(CPileMgr *this, int _iPileId)
void CPileMgr::DeletePileUnforeseen(int _iPileId) {

    BB_ASSERT(_iPileId > 0)

    // if(debug && DEBUG_FLAGS[dword_4152080]) {
    //     BBSupportTracePrintF(0, "DeletePile");
    //     CPileMgr::TracePile(this, _iPileId);
    // }

    if(!_iPileId)
        return;

    --this->m_iPileCount;
    g_pMapObjectMgr->Kill(_iPileId, 0);
}

// address=[0x155ede0]
// Decompiled from int __thiscall CPileMgr::GetNearestPile(CPileMgr *this, int a2, int a3, int a4)
int CPileMgr::GetNearestPile(int _iPileId, int _iX, int _iY) {
    if(!_iPileId)
        return 0;

    int iPileSearch = _iPileId;
    int iFoundPile = 0;
    unsigned int iShortestPileDistance = -1;

    CPile *pPile = GetPilePtr(_iPileId);
    BB_ASSERT(pPile != 0)
    while(pPile) {
        if(pPile->Amount() != pPile->AmountLeaving()) {
            int iPileDistance = Grid::Distance(_iX - pPile->X(), _iY - pPile->Y());
            pPile->ReassessDistance(iPileDistance);
            if(iPileDistance < iShortestPileDistance) {
                iShortestPileDistance = iPileDistance;
                iFoundPile = iPileSearch;
            }
        }

        iPileSearch = pPile->Next();
        if(iPileSearch)
            pPile = GetPilePtr(iPileSearch);
        else
            pPile = 0;
    }

    return iFoundPile;
}

// address=[0x155eef0]
// Decompiled from void __thiscall CPileMgr::SearchSpaceForGoods(  CPileMgr *this,  unsigned int _iX,  unsigned int _iY,  unsigned int _iGood,  unsigned int _iAmount)
void CPileMgr::SearchSpaceForGoods(int _iX, int _iY, int _iGood, int _iAmount) {
    BB_ASSERT(g_cWorld.InWorld(_iX, _iY))
    BB_ASSERT(_iGood >= 0 && _iGood < GOOD_MAX)
    BB_ASSERT(_iAmount >= 0 && _iAmount <= CPile::MAX_PILE_AMOUNT)

    int iAmountLeftToSearch;
    int iIter = 0;
    signed int iAmount = _iAmount;
    while(iAmount && iIter <= 9999) {
        unsigned int iX = _iX + CSpiralOffsets::DeltaX(iIter);
        unsigned int iY = _iY + CSpiralOffsets::DeltaY(iIter);
        if(CWorldManager::InWorld(iX, iY)) {
            int iPileId = CWorldManager::PileId(iX, iY);
            if(iPileId) {
                unsigned int iTargetGood = _iGood;
                int iOwner = CWorldManager::OwnerId(iX, iY);
                if(iOwner) {
                    iTargetGood = CPileMgr::ConvertGoodType(_iGood, CPlayerManager::Race(iOwner));
                }
                CPile &rPile = g_cPileMgr[iPileId];
                if(rPile.GetGoodType() == iTargetGood && rPile.GetRoleType() == IPileRole::PILE_ANYWHERE) {
                    if(rPile.AmountComing() + rPile.Amount() < CPile::MAX_PILE_AMOUNT) {
                        signed int iAmountLeft = CPile::MAX_PILE_AMOUNT - rPile.Amount() - rPile.AmountComing();
                        if(iAmountLeft >= iAmount)
                            iAmountLeftToSearch = iAmount;
                        else
                            iAmountLeftToSearch = iAmountLeft;
                        rPile.IncreaseUnforeseen(iAmountLeftToSearch);
                        iAmount -= iAmountLeftToSearch;
                    }
                }
            }
        }

        BB_ASSERT(iAmount <= CPile::MAX_PILE_AMOUNT)

        if(iAmount && iIter >= 50) {
            // If we're 50 spots out, try to create new random pile
            unsigned int iSpotX = _iX + CSpiralOffsets::DeltaX(iIter - 50);
            unsigned int iSpotY = _iY + CSpiralOffsets::DeltaY(iIter - 50);
            if(CWorldManager::InWorld(iSpotX, iSpotY) && !CWorldManager::FlagBits(iSpotX, iSpotY, 0x39u) && !CWorldManager::ObjectId(iSpotX, iSpotY) && !CWorldManager::MapObjectId(iSpotX, iSpotY) && CWorldManager::SectorId(iSpotX, iSpotY)) {
                unsigned int iTargetGood = _iGood;
                int iOwner = CWorldManager::OwnerId(iSpotX, iSpotY);
                if(iOwner) {
                    iTargetGood = CPileMgr::ConvertGoodType(_iGood, CPlayerManager::Race(iOwner));
                }
                int iActPileId = CPileMgr::AddPile(iSpotX, iSpotY, iTargetGood, iAmount, IPileRole::PILE_ANYWHERE, 0, 0, 0, 0);
                BB_ASSERT(iActPileId != 0)
                iAmount = 0;
            }
        }

        ++iIter;
    }
}

// address=[0x155f280]
// Decompiled from void __thiscall CPileMgr::Store(CPileMgr *this, struct S4::CMapFile *_rMapFile)
void CPileMgr::Store(class S4::CMapFile &_rMapFile) {
    // TODO: fix deprecation
    std::ostrstream cStream{};
    unsigned int iFileVersion = 1;
    cStream << iFileVersion;
    int iLastId = CMapObjectMgr::LastUsedId();
    unsigned int iPileCount = 0;
    for(int i = 0; i <= iLastId; ++i) {
        IEntity *pEntity = CMapObjectMgr::EntityPtr(i);
        if(pEntity) {
            if(pEntity->ObjType() == PILE_OBJ)
                ++iPileCount;
        }
    }
    cStream << iPileCount;
    for(int i = 0; i <= iLastId; ++i) {
        IEntity *pEntity = CMapObjectMgr::EntityPtr(i);
        if(pEntity) {
            if(pEntity->ObjType() == PILE_OBJ)
                pEntity->Store(cStream);
        }
    }
    cStream.put(0);

    cStream.freeze(true);
    _rMapFile.SaveChunk(MAP_CHUNK_SAVE_PILES, 0, cStream.rdbuf()->pcount(), cStream.str(), 0);
    cStream.freeze(false);
}

// address=[0x155f4c0]
// Decompiled from void __thiscall CPileMgr::Load(CPileMgr *this, struct S4::CMapFile *_rMapFile)
void CPileMgr::Load(class S4::CMapFile &_rMapFile) {

    int iChunkB = 0;
    const char *pChunk = static_cast<const char *>(_rMapFile.LoadChunk(MAP_CHUNK_SAVE_PILES, 0, iChunkB, 0));
    if(!pChunk)
        return;

    // TODO: find better way to load data, instead of copy to string...
    std::istringstream cStream{ pChunk };

    unsigned int iFileVersion;
    cStream >> iFileVersion;
    if(iFileVersion != 1) {
        BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CPileMgr");
        throw CS4InvalidMapException();
    }

    unsigned int iPileCount; // [esp+C0h] [ebp-3Ch] BYREF
    iPileCount = 0;
    cStream >> iPileCount;
    for(unsigned int i = 0; i < iPileCount; ++i) {
        CPersistence::New(cStream);
        ++this->m_iPileCount;
    }
}

// address=[0x155f670]
// Decompiled from int __thiscall CPileMgr::DbgCheckPiles(CPileMgr *this, int a2)
int CPileMgr::DbgCheckPiles(int a2) {

    // [esp+0h] [ebp-1Ch]
    IEntity *PilePtr; // [esp+8h] [ebp-14h]
                      // [esp+Ch] [ebp-10h]
                      // [esp+14h] [ebp-8h]
                      // [esp+18h] [ebp-4h]

    BBSupportTracePrintF(1, "CPileMgr::DbgCheckPiles()...");
    int iError = 0;
    int iPileCount = 0;
    int iLastId = CMapObjectMgr::LastUsedId();
    for(int i = 1; i <= iLastId; ++i) {
        PilePtr = CPileMgr::GetPilePtr(i);
        if(PilePtr) {
            ++iPileCount;
            PilePtr->FlagBits(ENTITY_FLAG_AliveMask); // dont know why this is here...
        }
    }
    if(this->m_iPileCount) {
        iError = 1;
        BBSupportTracePrintF(3, " Invalid number of piles: Is %i, should be %i!", this->m_iPileCount, 0);
    }
    BBSupportTracePrintF(1, " %i pile(s) checked.", 0);
    if(iError)
        BBSupportTracePrintF(1, " %i error(s).", iError);
    else
        BBSupportTracePrintF(1, " No errors.");
    return iError;
}

struct SPileConversionMap {
    int m_iFromGood;
    int m_iToGood;
};

// 03D8BBC8 ; SPileConversionMap s_sGoodConversionMap[5][15]
SPileConversionMap s_sGoodConversionMap[5][15] = {
    {
        { 1, 0x10 },    //; 0
        { 5, 0x22 },    //; 1
        { 6, 8 },       //; 2
        { 0x0D, 0x1E }, //; 3
        { 0x13, 0x10 }, //; 4
        { 0x17, 0x25 }, //; 5
        { 0x23, 0x25 }, //; 6
        { 0x1A, 0x1E }, //; 7
        { 0x27, 0x1E }, //; 8
        { 0x2A, 0x10 }, //; 9
        { 0x29, 0x25 }, //; 10
        { 0x26, 0x22 }, //; 11
        { 0, 0 },       //; 12
        { 0, 0 },       //; 13
        { 0, 0 },       //; 14
    },                  // RACE_ROMAN

    {
        { 1, 0x13 },    //; 15
        { 6, 5 },       //; 16
        { 0x0D, 0x1A }, //; 17
        { 0x1E, 0x1A }, //; 18
        { 0x23, 0x17 }, //; 19
        { 0x25, 0x17 }, //; 20
        { 0x27, 0x1A }, //; 21
        { 0x2A, 0x13 }, //; 22
        { 0x29, 0x17 }, //; 23
        { 0x26, 5 },    //; 24
        { 0, 0 },       //; 25
        { 0, 0 },       //; 26
        { 0, 0 },       //; 27
        { 0, 0 },       //; 28
        { 0, 0 },       //; 29
    },                  // 1

    {
        { 5, 6 },       //; 30
        { 0x13, 1 },    //; 31
        { 0x17, 0x23 }, //; 32
        { 0x1E, 0x0D }, //; 33
        { 0x1A, 0x0D }, //; 34
        { 0x25, 0x23 }, //; 35
        { 0x27, 0x0D }, //; 36
        { 0x2A, 1 },    //; 37
        { 0x29, 0x23 }, //; 38
        { 0x26, 6 },    //; 39
        { 0, 0 },       //; 40
        { 0, 0 },       //; 41
        { 0, 0 },       //; 42
        { 0, 0 },       //; 43
        { 0, 0 },       //; 44
    },                  // 2
    {
        { 0, 0 }, //; 45
        { 0, 0 }, //; 46
        { 0, 0 }, //; 47
        { 0, 0 }, //; 48
        { 0, 0 }, //; 49
        { 0, 0 }, //; 50
        { 0, 0 }, //; 51
        { 0, 0 }, //; 52
        { 0, 0 }, //; 53
        { 0, 0 }, //; 54
        { 0, 0 }, //; 55
        { 0, 0 }, //; 56
        { 0, 0 }, //; 57
        { 0, 0 }, //; 58
        { 0, 0 }, //; 59
    },            // 3

    {
        { 0x1E, 0x27 }, //; 60
        { 0x1A, 0x27 }, //; 61
        { 0x0D, 0x27 }, //; 62
        { 5, 0x26 },    //; 63
        { 6, 0x26 },    //; 64
        { 0x25, 0x29 }, //; 65
        { 0x17, 0x29 }, //; 66
        { 0x23, 0x29 }, //; 67
        { 0x13, 0x2A }, //; 68
        { 1, 0x2A },    //; 69
        { 0, 0 },       //; 70
        { 0, 0 },       //; 71
        { 0, 0 },       //; 72
        { 0, 0 },       //; 73
        { 0, 0 },       //; 74
    },                  // 4

};

// address=[0x155f760]
// Decompiled from int __thiscall CPileMgr::ConvertGoodType(CPileMgr *this, int a2, int _iTargetRace)
int CPileMgr::ConvertGoodType(int a2, int _iTargetRace) {
    BB_ASSERT(_iTargetRace >= RACE_ROMAN)
    BB_ASSERT(_iTargetRace < RACE_MAX)

    int iGood = 0;
    int iNewGoodType = a2;
    char bFoundCustomGoodConversion = 0;
    while(s_sGoodConversionMap[_iTargetRace][iGood].m_iFromGood && !bFoundCustomGoodConversion) {
        if(s_sGoodConversionMap[_iTargetRace][iGood].m_iFromGood == a2) {
            iNewGoodType = s_sGoodConversionMap[_iTargetRace][iGood].m_iToGood;
            bFoundCustomGoodConversion = 1;
        } else {
            ++iGood;
        }
    }
    return iNewGoodType;
}

// address=[0x155f820]
// Decompiled from CProductionPileRole *__cdecl CPileMgr::CreatePileRole(int _iRole)
class IPileRole *__cdecl CPileMgr::CreatePileRole(int _iRole) {
    switch(_iRole) {
    case IPileRole::PILE_PRODUCTION /* 0 */:
        return new CProductionPileRole();
    case IPileRole::PILE_DELIVER /* 1 */:
        return new CDeliverPileRole();
    case IPileRole::PILE_STORAGE /* 2 */:
        return new CStoragePileRole();
    case IPileRole::PILE_ANYWHERE /* 3 */:
        return new CAnyWherePileRole();
    case IPileRole::PILE_TRADE /* 4 */:
        return new CTradePileRole();
    case IPileRole::PILE_BUILDINGSITE /* 5 */:
        return new CBuildingSitePileRole();
    default:
        BB_REPORT("The programm can't use this pile role at the moment (P0)!")
        BB_REPORT("Internal Error (P0)! Aborting!\nInterner Fehler (P0) aufgetreten! Programm wird beendet!")
        break;
    }
    return nullptr;
}

// address=[0x155e750]
// Decompiled from uint __thiscall CPileMgr::Alloc(CPileMgr *this, uint a2)
void *CPileMgr::Alloc(unsigned int a2) {
    return this->m_cAllocator.allocate(a2);
}

// address=[0x155e7b0]
// Decompiled from void __thiscall CPileMgr::Dealloc(CPileMgr *this, uint *a2)
void CPileMgr::Dealloc(void *a2) {
    this->m_cAllocator.deallocate(a2);
}

// address=[0x155fa90]
// Decompiled from void __thiscall CPileMgr::TracePile(CPileMgr *this, int iPileId)
void CPileMgr::TracePile(int iPileId) {
    CPile &rPile = g_cPileMgr[iPileId];
    int iNext = rPile.Next();
    int iPrev = rPile.Previous();
    int v8 = rPile.Y();
    int v2 = rPile.X();
    int iES = CWorldManager::EcoSectorId(v2, v8);
    int iAmountComing = rPile.AmountComing();
    int iAmountLeaving = rPile.AmountLeaving();
    int iAmount = rPile.Amount();
    int iGood = rPile.GetGoodType();
    int RoleType = rPile.GetRoleType();
    BBSupportTracePrintF(
        0,
        "Pile Nr: %u, Type: %u ,Good: %u, am: %u, aml: %u, amc: %u, es: %u, prev: %u, next: %u",
        iPileId,
        RoleType,
        iGood,
        iAmount,
        iAmountLeaving,
        iAmountComing,
        iES,
        iPrev,
        iNext);
}

// address=[0x155fb30]
// Decompiled from int __cdecl CPileMgr::LoadPileRole(int _rStream, int _iRole)
class IPileRole *__cdecl CPileMgr::LoadPileRole(std::istream &_rStream, int _iRole) {
    switch(_iRole) {
    case IPileRole::PILE_PRODUCTION /* 0 */:
        return CProductionPileRole::Load(_rStream);
    case IPileRole::PILE_DELIVER /* 1 */:
        return CDeliverPileRole::Load(_rStream);
    case IPileRole::PILE_STORAGE /* 2 */:
        return CStoragePileRole::Load(_rStream);
    case IPileRole::PILE_ANYWHERE /* 3 */:
        return CAnyWherePileRole::Load(_rStream);
    case IPileRole::PILE_TRADE /* 4 */:
        return CTradePileRole::Load(_rStream);
    case IPileRole::PILE_BUILDINGSITE /* 5 */:
        return CBuildingSitePileRole::Load(_rStream);
    default:
        BB_REPORT("The programm can't use this pile role at the moment!")
        throw CS4InvalidMapException();
    }

    return nullptr;
}

// address=[0x155fc30]
// Decompiled from void __thiscall CPileMgr::CheckOutPile(CPileMgr *this, int a2)
void CPileMgr::CheckOutPile(int a2) {
    ;
}
