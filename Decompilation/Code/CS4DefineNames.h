#ifndef CS4DEFINENAMES_H
#define CS4DEFINENAMES_H

class CS4DefineNames {
public:
    // address=[0x149ab50]
    static char const * __cdecl GetAnimalName(int);

    // address=[0x149ab70]
    static char const * __cdecl GetBuildingName(int);

    // address=[0x149ab90]
    static char const * __cdecl GetGoodName(int);

    // address=[0x149abb0]
    static char const * __cdecl GetObjectName(int);

    // address=[0x149abe0]
    static char const * __cdecl GetRaceName(int);

    // address=[0x149ac00]
    static char const * __cdecl GetSettlerName(int);

    // address=[0x149ac20]
    static char const * __cdecl GetSettlerJobName(int);

    // address=[0x149ac60]
    static char const * __cdecl GetSoundName(int);

    // address=[0x149ac80]
    static char const * __cdecl GetStringName(int);

    // address=[0x149acb0]
    static int __cdecl GetStringId(char const *);

};


#endif // CS4DEFINENAMES_H
