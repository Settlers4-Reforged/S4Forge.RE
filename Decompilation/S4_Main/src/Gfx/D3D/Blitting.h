#ifndef BLITTING_H
#define BLITTING_H

// address=[0x2f92ac0]
bool __cdecl BlitSettlerHardware(int, int, int, struct SGfxObjectInfo *);

// address=[0x2f93180]
bool __cdecl BlitWaveHardware(int, int, int, int, int);

// address=[0x2f932d0]
bool __cdecl BlitBuildingHardware(int, int, int, struct SGfxObjectInfo *, int *, int &);

// address=[0x2f951e0]
bool __cdecl BlitObjectHardware(int, int, int, struct SGfxObjectInfo *);

// address=[0x2f95660]
bool __cdecl BlitBorderstoneHardware(int, int, int, int);

// address=[0x2f957f0]
bool __cdecl BlitVehicleHardware(int, int, int, struct SGfxObjectInfo *);

// address=[0x2f96960]
bool __cdecl BlitAccessoryIconHardware(int, int, int, int);

// address=[0x2f69ee0]
bool __cdecl BlitSettler(int, int, int, struct SGfxObjectInfo *);

// address=[0x2f6a540]
bool __cdecl BlitObject(int, int, int, struct SGfxObjectInfo *);

// address=[0x2f6a900]
bool __cdecl BlitVehicle(int, int, int, struct SGfxObjectInfo *);

// address=[0x2f6b180]
bool __cdecl BlitBuilding(int, int, int, struct SGfxObjectInfo *, int *, int &);

// address=[0x2f6c700]
bool __cdecl BlitBorderstone(int, int, int, int);

// address=[0x2f6c870]
bool __cdecl BlitAccessoryIcon(int, int, int, int);

// address=[0x2f6c9b0]
bool __cdecl BlitWave(int, int, int, int, int);

#endif // BLITTING_H
