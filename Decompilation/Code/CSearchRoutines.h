#ifndef CSEARCHROUTINES_H
#define CSEARCHROUTINES_H

class CSearchRoutines {
public:
    // address=[0x15191f0]
    static struct SSearchData const & __cdecl GetSearchData(int);

    // address=[0x1519220]
    static int __cdecl SearchNoSearch(int,int,int);

    // address=[0x1519230]
    static int __cdecl SearchTree(int,int,int);

    // address=[0x1519360]
    static int __cdecl SearchTreeSeedPos(int,int,int);

    // address=[0x1519480]
    static int __cdecl SearchTreeSeedPosMaya(int,int,int);

    // address=[0x15195a0]
    static int __cdecl SearchAgave(int,int,int);

    // address=[0x15196b0]
    static int __cdecl SearchAgaveSeedPos(int,int,int);

    // address=[0x15197a0]
    static int __cdecl SearchSunflower(int,int,int);

    // address=[0x15198b0]
    static int __cdecl SearchSunflowerSeedPos(int,int,int);

    // address=[0x15199a0]
    static int __cdecl SearchVine(int,int,int);

    // address=[0x1519ab0]
    static int __cdecl SearchVineSeedPos(int,int,int);

    // address=[0x1519b90]
    static int __cdecl SearchGrain(int,int,int);

    // address=[0x1519cb0]
    static int __cdecl SearchGrainSeedPos(int,int,int);

    // address=[0x1519da0]
    static int __cdecl SearchBeehive(int,int,int);

    // address=[0x1519e50]
    static int __cdecl SearchBeehivePos(int,int,int);

    // address=[0x1519eb0]
    static int __cdecl SearchMushroom(int,int,int);

    // address=[0x1519f60]
    static int __cdecl SearchMushroomSeedPos(int,int,int);

    // address=[0x1519fc0]
    static int __cdecl SearchVenison(int,int,int);

    // address=[0x151a040]
    static int __cdecl SearchWater(int,int,int);

    // address=[0x151a070]
    static int __cdecl SearchStone(int,int,int);

    // address=[0x151a190]
    static int __cdecl SearchFish(int,int,int);

    // address=[0x151a300]
    static int __cdecl SearchGold(int,int,int);

    // address=[0x151a330]
    static int __cdecl SearchCoal(int,int,int);

    // address=[0x151a360]
    static int __cdecl SearchIron(int,int,int);

    // address=[0x151a390]
    static int __cdecl SearchSulfur(int,int,int);

    // address=[0x151a3c0]
    static int __cdecl SearchGranit(int,int,int);

    // address=[0x151a3f0]
    static int __cdecl SearchDarkLand(int,int,int);

    // address=[0x151a430]
    static int __cdecl SearchGreenLand(int,int,int);

    // address=[0x151a470]
    static int __cdecl CalcRawness(int);

};


#endif // CSEARCHROUTINES_H
