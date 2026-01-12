#ifndef S4_H
#define S4_H

class S4 {
public:
    // address=[0x16a7240]
    void  TMap<unsigned char>::LoadMap(class CMapFile &,int,int);

    // address=[0x16a72d0]
    void  TMap<unsigned short>::LoadMap(class CMapFile &,int,int);

    // address=[0x16a7370]
    void  TMap<struct T_GFX_MAP_ELEMENT>::LoadMap(class CMapFile &,int,int);

    // address=[0x16a7410]
    bool  TSparseMap<unsigned char>::LoadMap(class CMapFile &,int);

    // address=[0x16a7580]
    void  TMap<unsigned char>::SaveMap(class CMapFile &,int,int);

    // address=[0x16a75d0]
    void  TMap<unsigned short>::SaveMap(class CMapFile &,int,int);

    // address=[0x16a7620]
    void  TMap<struct T_GFX_MAP_ELEMENT>::SaveMap(class CMapFile &,int,int);

    // address=[0x16a7670]
    bool  TSparseMap<unsigned char>::SaveMap(class CMapFile &,int);

};


#endif // S4_H
