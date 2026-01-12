#ifndef CLANDANIMAL_H
#define CLANDANIMAL_H

class CLandAnimal : public CAnimal {
public:
    // address=[0x1400fe0]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x14e0eb0]
    void  Init(struct SAnimalData *);

    // address=[0x14e1030]
    static void * __cdecl operator new(unsigned int);

    // address=[0x14e1050]
    static void __cdecl operator delete(void *);

    // address=[0x14e1090]
    virtual int  GetGoodType(void)const;

    // address=[0x14e10a0]
    virtual void  Decrease(int);

    // address=[0x14e10d0]
    virtual void  Take(int);

    // address=[0x14e10f0]
     CLandAnimal(std::istream &);

    // address=[0x14e12f0]
    virtual void  Store(std::ostream &);

    // address=[0x14e2f90]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d8a960]
    static unsigned long m_iClassID;

protected:
    // address=[0x14e14c0]
     CLandAnimal(int,int,int,int);

    // address=[0x14e1570]
    virtual  ~CLandAnimal(void);

    // address=[0x14e1590]
    void  PostLoadInit(struct SAnimalData *,int);

    // address=[0x14e1690]
    virtual void  LogicUpdateSpec(void);

    // address=[0x14e1a10]
    int  GetMoveDir(void);

    // address=[0x14e1f60]
    int  GetFleeDir(void);

    // address=[0x14e2100]
    int  GetTerritoryDir(void);

    // address=[0x14e21d0]
    int  GetDirection(int);

    // address=[0x14e22d0]
    bool  CheckForEnemies(void);

    // address=[0x14e23a0]
    bool  CheckTerritory(void);

    // address=[0x14e23f0]
    bool  IsValidSquare(int,int);

    // address=[0x14e2510]
    bool  CheckTile(int);

    // address=[0x14e2540]
    bool  IsTileFree(int);

    // address=[0x14e25a0]
    bool  CheckGround(int);

    // address=[0x14e26c0]
    bool  IsSettlerAroundTile(int);

};


#endif // CLANDANIMAL_H
