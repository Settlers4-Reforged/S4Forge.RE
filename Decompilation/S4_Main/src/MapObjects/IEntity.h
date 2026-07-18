#ifndef IENTITY_H
#define IENTITY_H

#include "LoadSave/CPersistence.h"
#include "Pathing/CWarMapNode.h"

#include "defines.h"

enum EntityFlag : int {
    ENTITY_FLAG_ATTACHED = 0x20,
    ENTITY_FLAG_Offered = 0x40,
    ENTITY_FLAG_Visible = 0x100,
    ENTITY_FLAG_Selected = 0x200,
    ENTITY_FLAG_Selectable = 0x2000,
    ENTITY_FLAG_OnBoard = 0x8000,
    ENTITY_FLAG_VulnerableMask = 0x30000,
    ENTITY_FLAG_MagicInvisible = 0x80000,
    ENTITY_FLAG_Birth = 0x1000000,
    ENTITY_FLAG_Ready = 0x2000000,
    ENTITY_FLAG_AliveMask = 0x3000000,
    ENTITY_FLAG_Died = 0x4000000,
    ENTITY_FLAG_Ownerless = 0x10000000,  // Maybe? In world checks, where if the flag is set, no owner is asked from - or rather the local player is asked from
    ENTITY_FLAG_Registered = 0x20000000, // aka. registered for logic update in x ticks - see CMapObjectMgr
    ENTITY_FLAG_GlobalOffered = 0x40000000,
};

/// @brief Current entity attacker id for damage handling
extern int g_CurrentEntityAttacker;

class IEntity : public CPersistence {
  public:
    // address=[0x12fd110]
    int FlagBits(int a2) const;

    // address=[0x12fd480]
    int ObjType(void) const;

    // address=[0x1309650]
    int PackedXY(void) const;

    // address=[0x130e8a0]
    class CAIEntityInfo *AIEntityInfoPtr(void) const;

    // address=[0x130ea10]
    void ClearFlagBits(int a2);

    // address=[0x130eb60]
    int Flags(void) const;

    // address=[0x130f060]
    int ID(void) const;

    // address=[0x130f250]
    int OwnerId(void) const;

    // address=[0x130f390]
    void SetFlagBits(int a2);

    // address=[0x130f420]
    int Type(void) const;

    // address=[0x130f440]
    int UniqueId(void) const;

    // address=[0x130f520]
    int WarriorType(void) const;

    // address=[0x130f550]
    int X(void) const;

    // address=[0x130f570]
    int Y(void) const;

    // address=[0x1336860]
    class CWarMapNode const *WarMapNode(void) const;

    // address=[0x13469e0]
    class CWarMapNode *WarMapNode(void);

    // address=[0x141d8b0]
    int EntityId(void) const;

    // address=[0x141da20]
    int Race(void) const;

    // address=[0x1460630]
    int Hitpoints(void) const;

    virtual struct SGfxObjectInfo *__thiscall GetGfxInfos(void) = 0;

    // address=[0x14d8640]
    virtual int ClearGroupFlagBits(int a2);

    // address=[0x14d8670]
    virtual int GetGoodType(void) const;

    // address=[0x14d8680]
    virtual int GetGroupFlags(void) const;

    // address=[0x14d8720]
    bool IsVisible(void) const;

    // address=[0x14d8790]
    virtual int SetGroupFlagBits(int a2);

    // address=[0x14d87b0]
    virtual int SetGroupFlags(int a2);

    // address=[0x14d8810]
    void SetPosition(int x, int y);

    // address=[0x14e4af0]
    virtual void Delete(void);

    // address=[0x14e4bf0]
    virtual void Take(int a1);

    // address=[0x14eb780]
    void SetOwnerId(unsigned char owner);

    // address=[0x14eb7e0]
    void SetRace(unsigned char a2);

    // address=[0x1508220]
    void SetPosition(int a2);

    // address=[0x15191b0]
    bool IsSelected(void) const;

    // address=[0x154b3d0]
    IEntity(int id);

    // address=[0x154b4a0]
    virtual ~IEntity(void);

    // address=[0x154b570]
    IEntity(std::istream &inputFile);

    // address=[0x154b6e0]
    virtual void Store(std::ostream &a2);

    // address=[0x154b7b0]
    virtual void PostLoadInit(void);

    // address=[0x154b7e0]
    int WorldIdx(void) const;

    // address=[0x154b800]
    virtual int Increase(int byAmount);

    // address=[0x154b850]
    virtual void Decrease(int byAmount);

    // address=[0x154b8b0]
    virtual void Decrease(int a2, int attackerId);

    // address=[0x154b8e0]
    virtual int Amount(void) const;

    // address=[0x154b900]
    virtual int MaxHitpoints(void) const;

    // address=[0x154b910]
    void SetAIEntityInfoPtr(class CAIEntityInfo *a2);

    // address=[0x154b960]
    virtual void DbgPrint(int logLevel, char const *customMessage);

    // address=[0x154ba00]
    virtual void PlaceInMapObjectLayer(int packedXY);

    // address=[0x154bb50]
    virtual void RemoveFromMapObjectLayer(void);

    // address=[0x154bc60]
    void RemoveFromMapObjectLayerIfNecessary(void);

    // address=[0x154bd00]
    virtual void Detach(int a1);

    // address=[0x154bd30]
    virtual void SetObserverTarget(enum T_OBSERVER_TARGET a1, int a2);

    // address=[0x154bd40]
    virtual int GetObserverTarget(enum T_OBSERVER_TARGET a2);

    // address=[0x154bd50]
    virtual void AddToWarMap(void);

    // address=[0x154bd80]
    void RemoveFromAllGroups(void);

    // address=[0x154c100]
    virtual void SetEvent(class CEntityEvent const &a1);

    // address=[0x1552650]
    bool CheckType(int a2, int a3) const;

    // address=[0x156d340]
    void SetHitpoints(unsigned int hp);

    enum EntityType : int8_t {
        Settler = 0x1,
        Ship = 0x2,
        Landvehicle = 0x4,
        Building = 0x8,
        Good = 0x10,
        LANDSCAPE_OBJ = 0x20,
        Unknown = 0x40,
        Animal = 0x80,
    };

  protected:
    // address=[0x40fe240]
    static struct SGfxColor m_sGfxColor;

    // address=[0x40fe250]
    static struct SGfxObjectInfo m_sGfxInfo;

    // Type information members
  protected:
    friend class CMapObjectMgr;
    friend class CDecoObjMgr;

    int m_iUniqueId;
    short m_iEntityId;
    EntityType m_uObjType;
    short m_iType;
    struct CAIEntityInfo *m_psAIEntityInfo;
    int m_iFlags; // EntityFlag
    int m_uPackedXY;
    CWarMapNode m_warMapNode;

    union {
        struct {
            BYTE m_cRace : 4;
            BYTE m_cPlayer : 4;
        };

        BYTE m_cPacked;
    } m_packedTribePlayer;

    BYTE m_cHealth;
    BYTE pad_22;
    BYTE pad_23;

    static int const FILE_FORMAT_VERSION = 0x2;
};

static_assert(sizeof(IEntity) == 0x24, "sizeof(IEntity) != 0x24");

#endif // IENTITY_H
