#ifndef IENTITY_H
#define IENTITY_H

class IEntity : public CPersistence {
public:
    // address=[0x12fd110]
    int  FlagBits(int)const;

    // address=[0x12fd480]
    int  ObjType(void)const;

    // address=[0x1309650]
    int  PackedXY(void)const;

    // address=[0x130e8a0]
    class CAIEntityInfo *  AIEntityInfoPtr(void)const;

    // address=[0x130ea10]
    void  ClearFlagBits(int);

    // address=[0x130eb60]
    int  Flags(void)const;

    // address=[0x130f060]
    int  ID(void)const;

    // address=[0x130f250]
    int  OwnerId(void)const;

    // address=[0x130f390]
    void  SetFlagBits(int);

    // address=[0x130f420]
    int  Type(void)const;

    // address=[0x130f440]
    int  UniqueId(void)const;

    // address=[0x130f520]
    int  WarriorType(void)const;

    // address=[0x130f550]
    int  X(void)const;

    // address=[0x130f570]
    int  Y(void)const;

    // address=[0x1336860]
    class CWarMapNode const &  WarMapNode(void)const;

    // address=[0x13469e0]
    class CWarMapNode &  WarMapNode(void);

    // address=[0x141d8b0]
    int  EntityId(void)const;

    // address=[0x141da20]
    int  Race(void)const;

    // address=[0x1460630]
    int  Hitpoints(void)const;

    // address=[0x14d8640]
    virtual int  ClearGroupFlagBits(int);

    // address=[0x14d8670]
    virtual int  GetGoodType(void)const;

    // address=[0x14d8680]
    virtual int  GetGroupFlags(void)const;

    // address=[0x14d8720]
    bool  IsVisible(void)const;

    // address=[0x14d8790]
    virtual int  SetGroupFlagBits(int);

    // address=[0x14d87b0]
    virtual int  SetGroupFlags(int);

    // address=[0x14d8810]
    void  SetPosition(int,int);

    // address=[0x14e4af0]
    virtual void  Delete(void);

    // address=[0x14e4bf0]
    virtual void  Take(int);

    // address=[0x14eb780]
    void  SetOwnerId(unsigned char);

    // address=[0x14eb7e0]
    void  SetRace(unsigned char);

    // address=[0x1508220]
    void  SetPosition(int);

    // address=[0x15191b0]
    bool  IsSelected(void)const;

    // address=[0x154b3d0]
     IEntity(int);

    // address=[0x154b4a0]
    virtual  ~IEntity(void);

    // address=[0x154b570]
     IEntity(std::istream &);

    // address=[0x154b6e0]
    virtual void  Store(std::ostream &);

    // address=[0x154b7b0]
    virtual void  PostLoadInit(void);

    // address=[0x154b7e0]
    int  WorldIdx(void)const;

    // address=[0x154b800]
    virtual int  Increase(int);

    // address=[0x154b850]
    virtual void  Decrease(int);

    // address=[0x154b8b0]
    virtual void  Decrease(int,int);

    // address=[0x154b8e0]
    virtual int  Amount(void)const;

    // address=[0x154b900]
    virtual int  MaxHitpoints(void)const;

    // address=[0x154b910]
    void  SetAIEntityInfoPtr(class CAIEntityInfo *);

    // address=[0x154b960]
    virtual void  DbgPrint(int,char const *);

    // address=[0x154ba00]
    virtual void  PlaceInMapObjectLayer(int);

    // address=[0x154bb50]
    virtual void  RemoveFromMapObjectLayer(void);

    // address=[0x154bc60]
    void  RemoveFromMapObjectLayerIfNecessary(void);

    // address=[0x154bd00]
    virtual void  Detach(int);

    // address=[0x154bd30]
    virtual void  SetObserverTarget(enum T_OBSERVER_TARGET,int);

    // address=[0x154bd40]
    virtual int  GetObserverTarget(enum T_OBSERVER_TARGET);

    // address=[0x154bd50]
    virtual void  AddToWarMap(void);

    // address=[0x154bd80]
    void  RemoveFromAllGroups(void);

    // address=[0x154c100]
    virtual void  SetEvent(class CEntityEvent const &);

    // address=[0x1552650]
    bool  CheckType(int,int)const;

    // address=[0x156d340]
    void  SetHitpoints(unsigned int);

protected:
    // address=[0x40fe240]
    static struct SGfxColor m_sGfxColor;

    // address=[0x40fe250]
    static struct SGfxObjectInfo m_sGfxInfo;

};


#endif // IENTITY_H
