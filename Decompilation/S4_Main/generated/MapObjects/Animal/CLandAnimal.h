#ifndef CLANDANIMAL_H
#define CLANDANIMAL_H

#include "defines.h"

class CLandAnimal : public CAnimal {
public:
    // address=[0x1400fe0]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x14e0eb0]
    void  Init(struct SAnimalData * a2);

    // address=[0x14e1030]
    static void * __cdecl operator new(unsigned int a1);

    // address=[0x14e1050]
    static void __cdecl operator delete(void *);

    // address=[0x14e1090]
    virtual int  GetGoodType(void)const;

    // address=[0x14e10a0]
    virtual void  Decrease(int a2);

    // address=[0x14e10d0]
    virtual void  Take(int a2);

    // address=[0x14e10f0]
     CLandAnimal(std::istream & a2);

    // address=[0x14e12f0]
    virtual void  Store(std::ostream & a2);

    // address=[0x14e2f90]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d8a960]
    static unsigned long m_iClassID;

protected:
    // address=[0x14e14c0]
     CLandAnimal(int a2, int a3, int a4, int a5);

    // address=[0x14e1570]
    virtual  ~CLandAnimal(void);

    // address=[0x14e1590]
    void  PostLoadInit(struct SAnimalData * a2, int a3);

    // address=[0x14e1690]
    virtual void  LogicUpdateSpec(void);

    // address=[0x14e1a10]
    int  GetMoveDir(void);

    // address=[0x14e1f60]
    int  GetFleeDir(void);

    // address=[0x14e2100]
    int  GetTerritoryDir(void);

    // address=[0x14e21d0]
    int  GetDirection(int a2);

    // address=[0x14e22d0]
    bool  CheckForEnemies(void);

    // address=[0x14e23a0]
    bool  CheckTerritory(void);

    // address=[0x14e23f0]
    bool  IsValidSquare(int a2, int a3);

    // address=[0x14e2510]
    bool  CheckTile(int a2);

    // address=[0x14e2540]
    bool  IsTileFree(int a2);

    // address=[0x14e25a0]
    bool  CheckGround(int a2);

    // address=[0x14e26c0]
    bool  IsSettlerAroundTile(int a2);

    // Type information members
private:
    DWORD unk_7c;
    DWORD unk_80;
    DWORD unk_84;
    DWORD unk_88;
    DWORD unk_8c;
    DWORD unk_90;
    DWORD unk_94;
    DWORD unk_98;
    DWORD unk_9c;

};


#endif // CLANDANIMAL_H
