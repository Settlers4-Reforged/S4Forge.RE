#ifndef CGOODTRANSPORTPRIORITY_H
#define CGOODTRANSPORTPRIORITY_H

class CGoodTransportPriority : public CPersistence {
public:
    // address=[0x1400d60]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x1439ae0]
    int  GetNumberOfPriorities(void);

    // address=[0x1439b40]
    int  GetPriority(enum PILE_TYPES);

    // address=[0x1452ac0]
     CGoodTransportPriority(std::istream &);

    // address=[0x1452b80]
    virtual void  Store(std::ostream &);

    // address=[0x1452bf0]
     CGoodTransportPriority(unsigned char);

    // address=[0x1452c70]
    void  ChangePriority(enum PILE_TYPES,int);

    // address=[0x1452e30]
    void  GetSortedGoods(int * const);

    // address=[0x1454260]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d895f0]
    static unsigned long m_iClassID;

private:
    // address=[0x1452f50]
    void  CreateRomanPriorities(void);

    // address=[0x1453250]
    void  CreateVikingPriorities(void);

    // address=[0x1453570]
    void  CreateMayaPriorities(void);

    // address=[0x14538b0]
    void  CreateTrojanPriorities(void);

    // address=[0x3f1de00]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_BOARD;

    // address=[0x3f1de0c]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_STONE;

    // address=[0x3f1de18]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_LOG;

    // address=[0x3f1de24]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_IRONBAR;

    // address=[0x3f1de30]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_IRONORE;

    // address=[0x3f1de3c]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_COAL;

    // address=[0x3f1de48]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_BREAD;

    // address=[0x3f1de54]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_FISH;

    // address=[0x3f1de60]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_MEAT;

    // address=[0x3f1de6c]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_FLOUR;

    // address=[0x3f1de78]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_GRAIN;

    // address=[0x3f1de84]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_SHEEP;

    // address=[0x3f1de90]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_WATER;

    // address=[0x3f1de9c]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_SWORD;

    // address=[0x3f1dea8]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_BOW;

    // address=[0x3f1deb4]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_ARMOR;

    // address=[0x3f1dec0]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_AMMO;

    // address=[0x3f1decc]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_SHOVEL;

    // address=[0x3f1ded8]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_HAMMER;

    // address=[0x3f1dee4]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_AXE;

    // address=[0x3f1def0]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_PICKAXE;

    // address=[0x3f1defc]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_SAW;

    // address=[0x3f1df08]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_ROD;

    // address=[0x3f1df14]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_SCYTHE;

    // address=[0x3f1df20]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_GOLDBAR;

    // address=[0x3f1df2c]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_GOLDORE;

    // address=[0x3f1df38]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_WINE;

    // address=[0x3f1df44]
    static class CStaticConfigVarInt m_iDefault_ROMAN_TP_SULFUR;

    // address=[0x3f1df50]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_BOARD;

    // address=[0x3f1df5c]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_STONE;

    // address=[0x3f1df68]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_LOG;

    // address=[0x3f1df74]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_IRONBAR;

    // address=[0x3f1df80]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_IRONORE;

    // address=[0x3f1df8c]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_COAL;

    // address=[0x3f1df98]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_BREAD;

    // address=[0x3f1dfa4]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_FISH;

    // address=[0x3f1dfb0]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_MEAT;

    // address=[0x3f1dfbc]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_FLOUR;

    // address=[0x3f1dfc8]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_GRAIN;

    // address=[0x3f1dfd4]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_PIG;

    // address=[0x3f1dfe0]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_WATER;

    // address=[0x3f1dfec]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_SWORD;

    // address=[0x3f1dff8]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_BOW;

    // address=[0x3f1e004]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_BATTLEAXE;

    // address=[0x3f1e010]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_ARMOR;

    // address=[0x3f1e01c]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_SHOVEL;

    // address=[0x3f1e028]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_HAMMER;

    // address=[0x3f1e034]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_AXE;

    // address=[0x3f1e040]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_PICKAXE;

    // address=[0x3f1e04c]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_SAW;

    // address=[0x3f1e058]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_ROD;

    // address=[0x3f1e064]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_SCYTHE;

    // address=[0x3f1e070]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_GOLDBAR;

    // address=[0x3f1e07c]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_GOLDORE;

    // address=[0x3f1e088]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_MEAD;

    // address=[0x3f1e094]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_HONEY;

    // address=[0x3f1e0a0]
    static class CStaticConfigVarInt m_iDefault_VIKING_TP_SULFUR;

    // address=[0x3f1e0ac]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_BOARD;

    // address=[0x3f1e0b8]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_STONE;

    // address=[0x3f1e0c4]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_LOG;

    // address=[0x3f1e0d0]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_IRONBAR;

    // address=[0x3f1e0dc]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_IRONORE;

    // address=[0x3f1e0e8]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_COAL;

    // address=[0x3f1e0f4]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_BREAD;

    // address=[0x3f1e100]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_FISH;

    // address=[0x3f1e10c]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_MEAT;

    // address=[0x3f1e118]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_FLOUR;

    // address=[0x3f1e124]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_GRAIN;

    // address=[0x3f1e130]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_GOAT;

    // address=[0x3f1e13c]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_WATER;

    // address=[0x3f1e148]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_SWORD;

    // address=[0x3f1e154]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_BOW;

    // address=[0x3f1e160]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_BLOWGUN;

    // address=[0x3f1e16c]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_ARMOR;

    // address=[0x3f1e178]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_GUNPOWDER;

    // address=[0x3f1e184]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_SULFUR;

    // address=[0x3f1e190]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_SHOVEL;

    // address=[0x3f1e19c]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_HAMMER;

    // address=[0x3f1e1a8]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_AXE;

    // address=[0x3f1e1b4]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_PICKAXE;

    // address=[0x3f1e1c0]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_SAW;

    // address=[0x3f1e1cc]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_ROD;

    // address=[0x3f1e1d8]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_SCYTHE;

    // address=[0x3f1e1e4]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_GOLDBAR;

    // address=[0x3f1e1f0]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_GOLDORE;

    // address=[0x3f1e1fc]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_TEQUILA;

    // address=[0x3f1e208]
    static class CStaticConfigVarInt m_iDefault_MAYA_TP_AGAVE;

    // address=[0x3f1e214]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_BOARD;

    // address=[0x3f1e220]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_STONE;

    // address=[0x3f1e22c]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_LOG;

    // address=[0x3f1e238]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_IRONBAR;

    // address=[0x3f1e244]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_IRONORE;

    // address=[0x3f1e250]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_COAL;

    // address=[0x3f1e25c]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_BREAD;

    // address=[0x3f1e268]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_FISH;

    // address=[0x3f1e274]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_MEAT;

    // address=[0x3f1e280]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_FLOUR;

    // address=[0x3f1e28c]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_GRAIN;

    // address=[0x3f1e298]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_GOOSE;

    // address=[0x3f1e2a4]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_WATER;

    // address=[0x3f1e2b0]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_SWORD;

    // address=[0x3f1e2bc]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_BOW;

    // address=[0x3f1e2c8]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_BACKPACKCATAPULT;

    // address=[0x3f1e2d4]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_ARMOR;

    // address=[0x3f1e2e0]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_EXPLOSIVEARROW;

    // address=[0x3f1e2ec]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_SULFUR;

    // address=[0x3f1e2f8]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_SHOVEL;

    // address=[0x3f1e304]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_HAMMER;

    // address=[0x3f1e310]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_AXE;

    // address=[0x3f1e31c]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_PICKAXE;

    // address=[0x3f1e328]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_SAW;

    // address=[0x3f1e334]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_ROD;

    // address=[0x3f1e340]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_SCYTHE;

    // address=[0x3f1e34c]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_GOLDBAR;

    // address=[0x3f1e358]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_GOLDORE;

    // address=[0x3f1e364]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_SUNFLOWEROIL;

    // address=[0x3f1e370]
    static class CStaticConfigVarInt m_iDefault_TROJAN_TP_SUNFLOWER;

};


#endif // CGOODTRANSPORTPRIORITY_H
