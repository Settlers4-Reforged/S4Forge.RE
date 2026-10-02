#include "CHeightAndTypeTable.h"

// Definitions for class CHeightAndTypeTable

// address=[0x03ACD510]
unsigned __int8 LandTypeTranslation[256] = {
    9,
    0x0A,
    0x0B,
    0x0C,
    0x0D,
    0x0E,
    0x0F,
    0x10,
    0x1D,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0x13,
    0x20,
    0,
    0x11,
    0x12,
    0,
    0x16,
    0x1E,
    0x1F,
    0,
    0,
    0x21,
    0x22,
    0,
    0,
    3,
    0x19,
    0,
    0x15,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    6,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    0x17,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    2,
    0x18,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0x23,
    0x24,
    0x25,
    0x26,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    4,
    0x1A,
    0x14,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    5,
    0x1B,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    7,
    0x1C,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

unsigned __int8 LandFogColors[16] = {
    0x19,
    0x33,
    0x4C,
    0x66,
    0x7F,
    0x99,
    0x0B2,
    0x0CC,
    0x0FF,
    0x0FF,
    0x0FF,
    0x0FF,
    0x0FF,
    0x0FF,
    0x0FF,
    0x0FF,
};

class CHeightAndTypeTable g_cHeightAndTypeTable{};

// address=[0x2f71cc0]
// Decompiled from int __thiscall CHeightAndTypeTable::GetObjectFog(CHeightAndTypeTable *this, int a2, int a3, int a4)
int CHeightAndTypeTable::GetObjectFog(int a2, int a3, int a4) {
    return static_cast<unsigned __int8>(this->uFogTable[a2][8][a3][a4].m_uShadowFog);
}

// address=[0x2f7c6a0]
// Decompiled from CHeightAndTypeTable *__thiscall CHeightAndTypeTable::CHeightAndTypeTable(CHeightAndTypeTable *this)
CHeightAndTypeTable::CHeightAndTypeTable(void) {

    // [esp+0h] [ebp-1Ch] BYREF
    // [esp+4h] [ebp-18h] BYREF
    // [esp+8h] [ebp-14h]
    // [esp+Ch] [ebp-10h]
    // [esp+10h] [ebp-Ch]
    // [esp+14h] [ebp-8h]

    InitShadeTables();

    memset(this->FromToTable, 0, sizeof(this->FromToTable));
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[18]].x = 3;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[18]].y = 2;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[18]].Page = 3;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[18]].Flags = -127;
    this->FromToTable[LandTypeTranslation[18]][LandTypeTranslation[16]].x = 2;
    this->FromToTable[LandTypeTranslation[18]][LandTypeTranslation[16]].y = 2;
    this->FromToTable[LandTypeTranslation[18]][LandTypeTranslation[16]].Page = 3;
    this->FromToTable[LandTypeTranslation[18]][LandTypeTranslation[16]].Flags = -127;
    this->FromToTable[LandTypeTranslation[24]][LandTypeTranslation[25]].x = 1;
    this->FromToTable[LandTypeTranslation[24]][LandTypeTranslation[25]].y = 2;
    this->FromToTable[LandTypeTranslation[24]][LandTypeTranslation[25]].Page = 3;
    this->FromToTable[LandTypeTranslation[24]][LandTypeTranslation[25]].Flags = -127;
    this->FromToTable[LandTypeTranslation[25]][LandTypeTranslation[24]].x = 0;
    this->FromToTable[LandTypeTranslation[25]][LandTypeTranslation[24]].y = 2;
    this->FromToTable[LandTypeTranslation[25]][LandTypeTranslation[24]].Page = 3;
    this->FromToTable[LandTypeTranslation[25]][LandTypeTranslation[24]].Flags = -127;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[25]].x = 1;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[25]].y = 0;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[25]].Page = 3;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[25]].Flags = -127;
    this->FromToTable[LandTypeTranslation[25]][LandTypeTranslation[16]].x = 0;
    this->FromToTable[LandTypeTranslation[25]][LandTypeTranslation[16]].y = 0;
    this->FromToTable[LandTypeTranslation[25]][LandTypeTranslation[16]].Page = 3;
    this->FromToTable[LandTypeTranslation[25]][LandTypeTranslation[16]].Flags = -127;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[28]].x = 1;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[28]].y = 0;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[28]].Page = 19;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[28]].Flags = -127;
    this->FromToTable[LandTypeTranslation[28]][LandTypeTranslation[16]].x = 0;
    this->FromToTable[LandTypeTranslation[28]][LandTypeTranslation[16]].y = 0;
    this->FromToTable[LandTypeTranslation[28]][LandTypeTranslation[16]].Page = 19;
    this->FromToTable[LandTypeTranslation[28]][LandTypeTranslation[16]].Flags = -127;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[29]].x = 3;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[29]].y = 0;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[29]].Page = 19;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[29]].Flags = -127;
    this->FromToTable[LandTypeTranslation[29]][LandTypeTranslation[16]].x = 2;
    this->FromToTable[LandTypeTranslation[29]][LandTypeTranslation[16]].y = 0;
    this->FromToTable[LandTypeTranslation[29]][LandTypeTranslation[16]].Page = 19;
    this->FromToTable[LandTypeTranslation[29]][LandTypeTranslation[16]].Flags = -127;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[0]].x = 3;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[0]].y = 0;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[0]].Page = 18;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[0]].Flags = -127;
    this->FromToTable[LandTypeTranslation[0]][LandTypeTranslation[16]].x = 3;
    this->FromToTable[LandTypeTranslation[0]][LandTypeTranslation[16]].y = 2;
    this->FromToTable[LandTypeTranslation[0]][LandTypeTranslation[16]].Page = 18;
    this->FromToTable[LandTypeTranslation[0]][LandTypeTranslation[16]].Flags = -127;
    this->FromToTable[LandTypeTranslation[0]][LandTypeTranslation[99]].x = 0;
    this->FromToTable[LandTypeTranslation[0]][LandTypeTranslation[99]].y = 0;
    this->FromToTable[LandTypeTranslation[0]][LandTypeTranslation[99]].Page = 5;
    this->FromToTable[LandTypeTranslation[0]][LandTypeTranslation[99]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[0]].x = 0;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[0]].y = 0;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[0]].Page = 5;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[0]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[96]].x = 0;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[96]].y = 0;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[96]].Page = 18;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[96]].Flags = -127;
    this->FromToTable[LandTypeTranslation[96]][LandTypeTranslation[16]].x = 0;
    this->FromToTable[LandTypeTranslation[96]][LandTypeTranslation[16]].y = 2;
    this->FromToTable[LandTypeTranslation[96]][LandTypeTranslation[16]].Page = 18;
    this->FromToTable[LandTypeTranslation[96]][LandTypeTranslation[16]].Flags = -127;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[97]].x = 1;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[97]].y = 0;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[97]].Page = 18;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[97]].Flags = -127;
    this->FromToTable[LandTypeTranslation[97]][LandTypeTranslation[16]].x = 1;
    this->FromToTable[LandTypeTranslation[97]][LandTypeTranslation[16]].y = 2;
    this->FromToTable[LandTypeTranslation[97]][LandTypeTranslation[16]].Page = 18;
    this->FromToTable[LandTypeTranslation[97]][LandTypeTranslation[16]].Flags = -127;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[98]].x = 2;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[98]].y = 0;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[98]].Page = 18;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[98]].Flags = -127;
    this->FromToTable[LandTypeTranslation[98]][LandTypeTranslation[16]].x = 2;
    this->FromToTable[LandTypeTranslation[98]][LandTypeTranslation[16]].y = 2;
    this->FromToTable[LandTypeTranslation[98]][LandTypeTranslation[16]].Page = 18;
    this->FromToTable[LandTypeTranslation[98]][LandTypeTranslation[16]].Flags = -127;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[99]].x = 3;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[99]].y = 0;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[99]].Page = 18;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[99]].Flags = -127;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[16]].x = 3;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[16]].y = 2;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[16]].Page = 18;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[16]].Flags = -127;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[17]].x = 2;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[17]].y = 0;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[17]].Page = 9;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[17]].Flags = -127;
    this->FromToTable[LandTypeTranslation[17]][LandTypeTranslation[16]].x = 3;
    this->FromToTable[LandTypeTranslation[17]][LandTypeTranslation[16]].y = 0;
    this->FromToTable[LandTypeTranslation[17]][LandTypeTranslation[16]].Page = 9;
    this->FromToTable[LandTypeTranslation[17]][LandTypeTranslation[16]].Flags = -127;
    this->FromToTable[LandTypeTranslation[17]][LandTypeTranslation[33]].x = 0;
    this->FromToTable[LandTypeTranslation[17]][LandTypeTranslation[33]].y = 2;
    this->FromToTable[LandTypeTranslation[17]][LandTypeTranslation[33]].Page = 9;
    this->FromToTable[LandTypeTranslation[17]][LandTypeTranslation[33]].Flags = -127;
    this->FromToTable[LandTypeTranslation[33]][LandTypeTranslation[17]].x = 1;
    this->FromToTable[LandTypeTranslation[33]][LandTypeTranslation[17]].y = 2;
    this->FromToTable[LandTypeTranslation[33]][LandTypeTranslation[17]].Page = 9;
    this->FromToTable[LandTypeTranslation[33]][LandTypeTranslation[17]].Flags = -127;
    this->FromToTable[LandTypeTranslation[33]][LandTypeTranslation[32]].x = 2;
    this->FromToTable[LandTypeTranslation[33]][LandTypeTranslation[32]].y = 2;
    this->FromToTable[LandTypeTranslation[33]][LandTypeTranslation[32]].Page = 9;
    this->FromToTable[LandTypeTranslation[33]][LandTypeTranslation[32]].Flags = -127;
    this->FromToTable[LandTypeTranslation[32]][LandTypeTranslation[33]].x = 3;
    this->FromToTable[LandTypeTranslation[32]][LandTypeTranslation[33]].y = 2;
    this->FromToTable[LandTypeTranslation[32]][LandTypeTranslation[33]].Page = 9;
    this->FromToTable[LandTypeTranslation[32]][LandTypeTranslation[33]].Flags = -127;
    this->FromToTable[LandTypeTranslation[32]][LandTypeTranslation[35]].x = 2;
    this->FromToTable[LandTypeTranslation[32]][LandTypeTranslation[35]].y = 0;
    this->FromToTable[LandTypeTranslation[32]][LandTypeTranslation[35]].Page = 16;
    this->FromToTable[LandTypeTranslation[32]][LandTypeTranslation[35]].Flags = -127;
    this->FromToTable[LandTypeTranslation[35]][LandTypeTranslation[32]].x = 3;
    this->FromToTable[LandTypeTranslation[35]][LandTypeTranslation[32]].y = 0;
    this->FromToTable[LandTypeTranslation[35]][LandTypeTranslation[32]].Page = 16;
    this->FromToTable[LandTypeTranslation[35]][LandTypeTranslation[32]].Flags = -127;
    this->FromToTable[LandTypeTranslation[35]][LandTypeTranslation[129]].x = 0;
    this->FromToTable[LandTypeTranslation[35]][LandTypeTranslation[129]].y = 2;
    this->FromToTable[LandTypeTranslation[35]][LandTypeTranslation[129]].Page = 16;
    this->FromToTable[LandTypeTranslation[35]][LandTypeTranslation[129]].Flags = -127;
    this->FromToTable[LandTypeTranslation[129]][LandTypeTranslation[35]].x = 1;
    this->FromToTable[LandTypeTranslation[129]][LandTypeTranslation[35]].y = 2;
    this->FromToTable[LandTypeTranslation[129]][LandTypeTranslation[35]].Page = 16;
    this->FromToTable[LandTypeTranslation[129]][LandTypeTranslation[35]].Flags = -127;
    this->FromToTable[LandTypeTranslation[129]][LandTypeTranslation[128]].x = 2;
    this->FromToTable[LandTypeTranslation[129]][LandTypeTranslation[128]].y = 2;
    this->FromToTable[LandTypeTranslation[129]][LandTypeTranslation[128]].Page = 16;
    this->FromToTable[LandTypeTranslation[129]][LandTypeTranslation[128]].Flags = -127;
    this->FromToTable[LandTypeTranslation[128]][LandTypeTranslation[129]].x = 3;
    this->FromToTable[LandTypeTranslation[128]][LandTypeTranslation[129]].y = 2;
    this->FromToTable[LandTypeTranslation[128]][LandTypeTranslation[129]].Page = 16;
    this->FromToTable[LandTypeTranslation[128]][LandTypeTranslation[129]].Flags = -127;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[21]].x = 2;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[21]].y = 0;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[21]].Page = 14;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[21]].Flags = -127;
    this->FromToTable[LandTypeTranslation[21]][LandTypeTranslation[16]].x = 3;
    this->FromToTable[LandTypeTranslation[21]][LandTypeTranslation[16]].y = 0;
    this->FromToTable[LandTypeTranslation[21]][LandTypeTranslation[16]].Page = 14;
    this->FromToTable[LandTypeTranslation[21]][LandTypeTranslation[16]].Flags = -127;
    this->FromToTable[LandTypeTranslation[21]][LandTypeTranslation[81]].x = 0;
    this->FromToTable[LandTypeTranslation[21]][LandTypeTranslation[81]].y = 2;
    this->FromToTable[LandTypeTranslation[21]][LandTypeTranslation[81]].Page = 14;
    this->FromToTable[LandTypeTranslation[21]][LandTypeTranslation[81]].Flags = -127;
    this->FromToTable[LandTypeTranslation[81]][LandTypeTranslation[21]].x = 1;
    this->FromToTable[LandTypeTranslation[81]][LandTypeTranslation[21]].y = 2;
    this->FromToTable[LandTypeTranslation[81]][LandTypeTranslation[21]].Page = 14;
    this->FromToTable[LandTypeTranslation[81]][LandTypeTranslation[21]].Flags = -127;
    this->FromToTable[LandTypeTranslation[81]][LandTypeTranslation[80]].x = 2;
    this->FromToTable[LandTypeTranslation[81]][LandTypeTranslation[80]].y = 2;
    this->FromToTable[LandTypeTranslation[81]][LandTypeTranslation[80]].Page = 14;
    this->FromToTable[LandTypeTranslation[81]][LandTypeTranslation[80]].Flags = -127;
    this->FromToTable[LandTypeTranslation[80]][LandTypeTranslation[81]].x = 3;
    this->FromToTable[LandTypeTranslation[80]][LandTypeTranslation[81]].y = 2;
    this->FromToTable[LandTypeTranslation[80]][LandTypeTranslation[81]].Page = 14;
    this->FromToTable[LandTypeTranslation[80]][LandTypeTranslation[81]].Flags = -127;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[23]].x = 2;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[23]].y = 2;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[23]].Page = 12;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[23]].Flags = -127;
    this->FromToTable[LandTypeTranslation[23]][LandTypeTranslation[16]].x = 3;
    this->FromToTable[LandTypeTranslation[23]][LandTypeTranslation[16]].y = 2;
    this->FromToTable[LandTypeTranslation[23]][LandTypeTranslation[16]].Page = 12;
    this->FromToTable[LandTypeTranslation[23]][LandTypeTranslation[16]].Flags = -127;
    this->FromToTable[LandTypeTranslation[23]][LandTypeTranslation[145]].x = 0;
    this->FromToTable[LandTypeTranslation[23]][LandTypeTranslation[145]].y = 2;
    this->FromToTable[LandTypeTranslation[23]][LandTypeTranslation[145]].Page = 12;
    this->FromToTable[LandTypeTranslation[23]][LandTypeTranslation[145]].Flags = -127;
    this->FromToTable[LandTypeTranslation[145]][LandTypeTranslation[23]].x = 1;
    this->FromToTable[LandTypeTranslation[145]][LandTypeTranslation[23]].y = 2;
    this->FromToTable[LandTypeTranslation[145]][LandTypeTranslation[23]].Page = 12;
    this->FromToTable[LandTypeTranslation[145]][LandTypeTranslation[23]].Flags = -127;
    this->FromToTable[LandTypeTranslation[145]][LandTypeTranslation[144]].x = 2;
    this->FromToTable[LandTypeTranslation[145]][LandTypeTranslation[144]].y = 0;
    this->FromToTable[LandTypeTranslation[145]][LandTypeTranslation[144]].Page = 12;
    this->FromToTable[LandTypeTranslation[145]][LandTypeTranslation[144]].Flags = -127;
    this->FromToTable[LandTypeTranslation[144]][LandTypeTranslation[145]].x = 3;
    this->FromToTable[LandTypeTranslation[144]][LandTypeTranslation[145]].y = 0;
    this->FromToTable[LandTypeTranslation[144]][LandTypeTranslation[145]].Page = 12;
    this->FromToTable[LandTypeTranslation[144]][LandTypeTranslation[145]].Flags = -127;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[20]].x = 2;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[20]].y = 2;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[20]].Page = 11;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[20]].Flags = -127;
    this->FromToTable[LandTypeTranslation[20]][LandTypeTranslation[16]].x = 3;
    this->FromToTable[LandTypeTranslation[20]][LandTypeTranslation[16]].y = 2;
    this->FromToTable[LandTypeTranslation[20]][LandTypeTranslation[16]].Page = 11;
    this->FromToTable[LandTypeTranslation[20]][LandTypeTranslation[16]].Flags = -127;
    this->FromToTable[LandTypeTranslation[20]][LandTypeTranslation[65]].x = 0;
    this->FromToTable[LandTypeTranslation[20]][LandTypeTranslation[65]].y = 2;
    this->FromToTable[LandTypeTranslation[20]][LandTypeTranslation[65]].Page = 11;
    this->FromToTable[LandTypeTranslation[20]][LandTypeTranslation[65]].Flags = -127;
    this->FromToTable[LandTypeTranslation[65]][LandTypeTranslation[20]].x = 1;
    this->FromToTable[LandTypeTranslation[65]][LandTypeTranslation[20]].y = 2;
    this->FromToTable[LandTypeTranslation[65]][LandTypeTranslation[20]].Page = 11;
    this->FromToTable[LandTypeTranslation[65]][LandTypeTranslation[20]].Flags = -127;
    this->FromToTable[LandTypeTranslation[65]][LandTypeTranslation[64]].x = 2;
    this->FromToTable[LandTypeTranslation[65]][LandTypeTranslation[64]].y = 0;
    this->FromToTable[LandTypeTranslation[65]][LandTypeTranslation[64]].Page = 11;
    this->FromToTable[LandTypeTranslation[65]][LandTypeTranslation[64]].Flags = -127;
    this->FromToTable[LandTypeTranslation[64]][LandTypeTranslation[65]].x = 3;
    this->FromToTable[LandTypeTranslation[64]][LandTypeTranslation[65]].y = 0;
    this->FromToTable[LandTypeTranslation[64]][LandTypeTranslation[65]].Page = 11;
    this->FromToTable[LandTypeTranslation[64]][LandTypeTranslation[65]].Flags = -127;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[48]].x = 3;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[48]].y = 0;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[48]].Page = 3;
    this->FromToTable[LandTypeTranslation[16]][LandTypeTranslation[48]].Flags = -127;
    this->FromToTable[LandTypeTranslation[48]][LandTypeTranslation[16]].x = 2;
    this->FromToTable[LandTypeTranslation[48]][LandTypeTranslation[16]].y = 0;
    this->FromToTable[LandTypeTranslation[48]][LandTypeTranslation[16]].Page = 3;
    this->FromToTable[LandTypeTranslation[48]][LandTypeTranslation[16]].Flags = -127;
    this->FromToTable[LandTypeTranslation[48]][LandTypeTranslation[0]].x = 0;
    this->FromToTable[LandTypeTranslation[48]][LandTypeTranslation[0]].y = 2;
    this->FromToTable[LandTypeTranslation[48]][LandTypeTranslation[0]].Page = 5;
    this->FromToTable[LandTypeTranslation[48]][LandTypeTranslation[0]].Flags = -127;
    this->FromToTable[LandTypeTranslation[0]][LandTypeTranslation[48]].x = 1;
    this->FromToTable[LandTypeTranslation[0]][LandTypeTranslation[48]].y = 2;
    this->FromToTable[LandTypeTranslation[0]][LandTypeTranslation[48]].Page = 5;
    this->FromToTable[LandTypeTranslation[0]][LandTypeTranslation[48]].Flags = -127;
    this->FromToTable[LandTypeTranslation[0]][LandTypeTranslation[1]].x = 0;
    this->FromToTable[LandTypeTranslation[0]][LandTypeTranslation[1]].y = 0;
    this->FromToTable[LandTypeTranslation[0]][LandTypeTranslation[1]].Page = 6;
    this->FromToTable[LandTypeTranslation[0]][LandTypeTranslation[1]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[1]][LandTypeTranslation[0]].x = 0;
    this->FromToTable[LandTypeTranslation[1]][LandTypeTranslation[0]].y = 1;
    this->FromToTable[LandTypeTranslation[1]][LandTypeTranslation[0]].Page = 6;
    this->FromToTable[LandTypeTranslation[1]][LandTypeTranslation[0]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[1]][LandTypeTranslation[2]].x = 1;
    this->FromToTable[LandTypeTranslation[1]][LandTypeTranslation[2]].y = 0;
    this->FromToTable[LandTypeTranslation[1]][LandTypeTranslation[2]].Page = 6;
    this->FromToTable[LandTypeTranslation[1]][LandTypeTranslation[2]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[2]][LandTypeTranslation[1]].x = 1;
    this->FromToTable[LandTypeTranslation[2]][LandTypeTranslation[1]].y = 1;
    this->FromToTable[LandTypeTranslation[2]][LandTypeTranslation[1]].Page = 6;
    this->FromToTable[LandTypeTranslation[2]][LandTypeTranslation[1]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[2]][LandTypeTranslation[3]].x = 2;
    this->FromToTable[LandTypeTranslation[2]][LandTypeTranslation[3]].y = 0;
    this->FromToTable[LandTypeTranslation[2]][LandTypeTranslation[3]].Page = 6;
    this->FromToTable[LandTypeTranslation[2]][LandTypeTranslation[3]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[3]][LandTypeTranslation[2]].x = 2;
    this->FromToTable[LandTypeTranslation[3]][LandTypeTranslation[2]].y = 1;
    this->FromToTable[LandTypeTranslation[3]][LandTypeTranslation[2]].Page = 6;
    this->FromToTable[LandTypeTranslation[3]][LandTypeTranslation[2]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[3]][LandTypeTranslation[4]].x = 3;
    this->FromToTable[LandTypeTranslation[3]][LandTypeTranslation[4]].y = 0;
    this->FromToTable[LandTypeTranslation[3]][LandTypeTranslation[4]].Page = 6;
    this->FromToTable[LandTypeTranslation[3]][LandTypeTranslation[4]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[4]][LandTypeTranslation[3]].x = 3;
    this->FromToTable[LandTypeTranslation[4]][LandTypeTranslation[3]].y = 1;
    this->FromToTable[LandTypeTranslation[4]][LandTypeTranslation[3]].Page = 6;
    this->FromToTable[LandTypeTranslation[4]][LandTypeTranslation[3]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[4]][LandTypeTranslation[5]].x = 0;
    this->FromToTable[LandTypeTranslation[4]][LandTypeTranslation[5]].y = 2;
    this->FromToTable[LandTypeTranslation[4]][LandTypeTranslation[5]].Page = 6;
    this->FromToTable[LandTypeTranslation[4]][LandTypeTranslation[5]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[5]][LandTypeTranslation[4]].x = 0;
    this->FromToTable[LandTypeTranslation[5]][LandTypeTranslation[4]].y = 3;
    this->FromToTable[LandTypeTranslation[5]][LandTypeTranslation[4]].Page = 6;
    this->FromToTable[LandTypeTranslation[5]][LandTypeTranslation[4]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[5]][LandTypeTranslation[6]].x = 1;
    this->FromToTable[LandTypeTranslation[5]][LandTypeTranslation[6]].y = 2;
    this->FromToTable[LandTypeTranslation[5]][LandTypeTranslation[6]].Page = 6;
    this->FromToTable[LandTypeTranslation[5]][LandTypeTranslation[6]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[6]][LandTypeTranslation[5]].x = 1;
    this->FromToTable[LandTypeTranslation[6]][LandTypeTranslation[5]].y = 3;
    this->FromToTable[LandTypeTranslation[6]][LandTypeTranslation[5]].Page = 6;
    this->FromToTable[LandTypeTranslation[6]][LandTypeTranslation[5]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[6]][LandTypeTranslation[7]].x = 2;
    this->FromToTable[LandTypeTranslation[6]][LandTypeTranslation[7]].y = 2;
    this->FromToTable[LandTypeTranslation[6]][LandTypeTranslation[7]].Page = 6;
    this->FromToTable[LandTypeTranslation[6]][LandTypeTranslation[7]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[7]][LandTypeTranslation[6]].x = 2;
    this->FromToTable[LandTypeTranslation[7]][LandTypeTranslation[6]].y = 3;
    this->FromToTable[LandTypeTranslation[7]][LandTypeTranslation[6]].Page = 6;
    this->FromToTable[LandTypeTranslation[7]][LandTypeTranslation[6]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[25]][LandTypeTranslation[25]].x = 0;
    this->FromToTable[LandTypeTranslation[25]][LandTypeTranslation[25]].y = 1;
    this->FromToTable[LandTypeTranslation[25]][LandTypeTranslation[25]].Page = 9;
    this->FromToTable[LandTypeTranslation[25]][LandTypeTranslation[25]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[17]][LandTypeTranslation[17]].x = 0;
    this->FromToTable[LandTypeTranslation[17]][LandTypeTranslation[17]].y = 0;
    this->FromToTable[LandTypeTranslation[17]][LandTypeTranslation[17]].Page = 9;
    this->FromToTable[LandTypeTranslation[17]][LandTypeTranslation[17]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[33]][LandTypeTranslation[33]].x = 1;
    this->FromToTable[LandTypeTranslation[33]][LandTypeTranslation[33]].y = 0;
    this->FromToTable[LandTypeTranslation[33]][LandTypeTranslation[33]].Page = 9;
    this->FromToTable[LandTypeTranslation[33]][LandTypeTranslation[33]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[35]][LandTypeTranslation[35]].x = 0;
    this->FromToTable[LandTypeTranslation[35]][LandTypeTranslation[35]].y = 0;
    this->FromToTable[LandTypeTranslation[35]][LandTypeTranslation[35]].Page = 16;
    this->FromToTable[LandTypeTranslation[35]][LandTypeTranslation[35]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[129]][LandTypeTranslation[129]].x = 1;
    this->FromToTable[LandTypeTranslation[129]][LandTypeTranslation[129]].y = 0;
    this->FromToTable[LandTypeTranslation[129]][LandTypeTranslation[129]].Page = 16;
    this->FromToTable[LandTypeTranslation[129]][LandTypeTranslation[129]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[21]][LandTypeTranslation[21]].x = 0;
    this->FromToTable[LandTypeTranslation[21]][LandTypeTranslation[21]].y = 0;
    this->FromToTable[LandTypeTranslation[21]][LandTypeTranslation[21]].Page = 14;
    this->FromToTable[LandTypeTranslation[21]][LandTypeTranslation[21]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[81]][LandTypeTranslation[81]].x = 1;
    this->FromToTable[LandTypeTranslation[81]][LandTypeTranslation[81]].y = 0;
    this->FromToTable[LandTypeTranslation[81]][LandTypeTranslation[81]].Page = 14;
    this->FromToTable[LandTypeTranslation[81]][LandTypeTranslation[81]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[23]][LandTypeTranslation[23]].x = 0;
    this->FromToTable[LandTypeTranslation[23]][LandTypeTranslation[23]].y = 0;
    this->FromToTable[LandTypeTranslation[23]][LandTypeTranslation[23]].Page = 12;
    this->FromToTable[LandTypeTranslation[23]][LandTypeTranslation[23]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[145]][LandTypeTranslation[145]].x = 1;
    this->FromToTable[LandTypeTranslation[145]][LandTypeTranslation[145]].y = 0;
    this->FromToTable[LandTypeTranslation[145]][LandTypeTranslation[145]].Page = 12;
    this->FromToTable[LandTypeTranslation[145]][LandTypeTranslation[145]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[20]][LandTypeTranslation[20]].x = 0;
    this->FromToTable[LandTypeTranslation[20]][LandTypeTranslation[20]].y = 0;
    this->FromToTable[LandTypeTranslation[20]][LandTypeTranslation[20]].Page = 11;
    this->FromToTable[LandTypeTranslation[20]][LandTypeTranslation[20]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[65]][LandTypeTranslation[65]].x = 1;
    this->FromToTable[LandTypeTranslation[65]][LandTypeTranslation[65]].y = 0;
    this->FromToTable[LandTypeTranslation[65]][LandTypeTranslation[65]].Page = 11;
    this->FromToTable[LandTypeTranslation[65]][LandTypeTranslation[65]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[0]][LandTypeTranslation[0]].x = 0;
    this->FromToTable[LandTypeTranslation[0]][LandTypeTranslation[0]].y = 0;
    this->FromToTable[LandTypeTranslation[0]][LandTypeTranslation[0]].Page = 5;
    this->FromToTable[LandTypeTranslation[0]][LandTypeTranslation[0]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[1]][LandTypeTranslation[1]].x = 1;
    this->FromToTable[LandTypeTranslation[1]][LandTypeTranslation[1]].y = 0;
    this->FromToTable[LandTypeTranslation[1]][LandTypeTranslation[1]].Page = 5;
    this->FromToTable[LandTypeTranslation[1]][LandTypeTranslation[1]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[2]][LandTypeTranslation[2]].x = 2;
    this->FromToTable[LandTypeTranslation[2]][LandTypeTranslation[2]].y = 0;
    this->FromToTable[LandTypeTranslation[2]][LandTypeTranslation[2]].Page = 5;
    this->FromToTable[LandTypeTranslation[2]][LandTypeTranslation[2]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[3]][LandTypeTranslation[3]].x = 3;
    this->FromToTable[LandTypeTranslation[3]][LandTypeTranslation[3]].y = 0;
    this->FromToTable[LandTypeTranslation[3]][LandTypeTranslation[3]].Page = 5;
    this->FromToTable[LandTypeTranslation[3]][LandTypeTranslation[3]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[4]][LandTypeTranslation[4]].x = 0;
    this->FromToTable[LandTypeTranslation[4]][LandTypeTranslation[4]].y = 1;
    this->FromToTable[LandTypeTranslation[4]][LandTypeTranslation[4]].Page = 5;
    this->FromToTable[LandTypeTranslation[4]][LandTypeTranslation[4]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[5]][LandTypeTranslation[5]].x = 1;
    this->FromToTable[LandTypeTranslation[5]][LandTypeTranslation[5]].y = 1;
    this->FromToTable[LandTypeTranslation[5]][LandTypeTranslation[5]].Page = 5;
    this->FromToTable[LandTypeTranslation[5]][LandTypeTranslation[5]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[6]][LandTypeTranslation[6]].x = 2;
    this->FromToTable[LandTypeTranslation[6]][LandTypeTranslation[6]].y = 1;
    this->FromToTable[LandTypeTranslation[6]][LandTypeTranslation[6]].Page = 5;
    this->FromToTable[LandTypeTranslation[6]][LandTypeTranslation[6]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[96]][LandTypeTranslation[96]].x = 0;
    this->FromToTable[LandTypeTranslation[96]][LandTypeTranslation[96]].y = 0;
    this->FromToTable[LandTypeTranslation[96]][LandTypeTranslation[96]].Page = 5;
    this->FromToTable[LandTypeTranslation[96]][LandTypeTranslation[96]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[96]][LandTypeTranslation[97]].x = 0;
    this->FromToTable[LandTypeTranslation[96]][LandTypeTranslation[97]].y = 0;
    this->FromToTable[LandTypeTranslation[96]][LandTypeTranslation[97]].Page = 5;
    this->FromToTable[LandTypeTranslation[96]][LandTypeTranslation[97]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[96]][LandTypeTranslation[98]].x = 0;
    this->FromToTable[LandTypeTranslation[96]][LandTypeTranslation[98]].y = 0;
    this->FromToTable[LandTypeTranslation[96]][LandTypeTranslation[98]].Page = 5;
    this->FromToTable[LandTypeTranslation[96]][LandTypeTranslation[98]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[96]][LandTypeTranslation[99]].x = 0;
    this->FromToTable[LandTypeTranslation[96]][LandTypeTranslation[99]].y = 0;
    this->FromToTable[LandTypeTranslation[96]][LandTypeTranslation[99]].Page = 5;
    this->FromToTable[LandTypeTranslation[96]][LandTypeTranslation[99]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[97]][LandTypeTranslation[96]].x = 0;
    this->FromToTable[LandTypeTranslation[97]][LandTypeTranslation[96]].y = 0;
    this->FromToTable[LandTypeTranslation[97]][LandTypeTranslation[96]].Page = 5;
    this->FromToTable[LandTypeTranslation[97]][LandTypeTranslation[96]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[97]][LandTypeTranslation[97]].x = 0;
    this->FromToTable[LandTypeTranslation[97]][LandTypeTranslation[97]].y = 0;
    this->FromToTable[LandTypeTranslation[97]][LandTypeTranslation[97]].Page = 5;
    this->FromToTable[LandTypeTranslation[97]][LandTypeTranslation[97]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[97]][LandTypeTranslation[98]].x = 0;
    this->FromToTable[LandTypeTranslation[97]][LandTypeTranslation[98]].y = 0;
    this->FromToTable[LandTypeTranslation[97]][LandTypeTranslation[98]].Page = 5;
    this->FromToTable[LandTypeTranslation[97]][LandTypeTranslation[98]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[97]][LandTypeTranslation[99]].x = 0;
    this->FromToTable[LandTypeTranslation[97]][LandTypeTranslation[99]].y = 0;
    this->FromToTable[LandTypeTranslation[97]][LandTypeTranslation[99]].Page = 5;
    this->FromToTable[LandTypeTranslation[97]][LandTypeTranslation[99]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[98]][LandTypeTranslation[96]].x = 0;
    this->FromToTable[LandTypeTranslation[98]][LandTypeTranslation[96]].y = 0;
    this->FromToTable[LandTypeTranslation[98]][LandTypeTranslation[96]].Page = 5;
    this->FromToTable[LandTypeTranslation[98]][LandTypeTranslation[96]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[98]][LandTypeTranslation[97]].x = 0;
    this->FromToTable[LandTypeTranslation[98]][LandTypeTranslation[97]].y = 0;
    this->FromToTable[LandTypeTranslation[98]][LandTypeTranslation[97]].Page = 5;
    this->FromToTable[LandTypeTranslation[98]][LandTypeTranslation[97]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[98]][LandTypeTranslation[98]].x = 0;
    this->FromToTable[LandTypeTranslation[98]][LandTypeTranslation[98]].y = 0;
    this->FromToTable[LandTypeTranslation[98]][LandTypeTranslation[98]].Page = 5;
    this->FromToTable[LandTypeTranslation[98]][LandTypeTranslation[98]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[98]][LandTypeTranslation[99]].x = 0;
    this->FromToTable[LandTypeTranslation[98]][LandTypeTranslation[99]].y = 0;
    this->FromToTable[LandTypeTranslation[98]][LandTypeTranslation[99]].Page = 5;
    this->FromToTable[LandTypeTranslation[98]][LandTypeTranslation[99]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[96]].x = 0;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[96]].y = 0;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[96]].Page = 5;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[96]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[97]].x = 0;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[97]].y = 0;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[97]].Page = 5;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[97]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[98]].x = 0;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[98]].y = 0;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[98]].Page = 5;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[98]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[99]].x = 0;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[99]].y = 0;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[99]].Page = 5;
    this->FromToTable[LandTypeTranslation[99]][LandTypeTranslation[99]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[7]][LandTypeTranslation[5]].x = 2;
    this->FromToTable[LandTypeTranslation[7]][LandTypeTranslation[5]].y = 2;
    this->FromToTable[LandTypeTranslation[7]][LandTypeTranslation[5]].Page = 5;
    this->FromToTable[LandTypeTranslation[7]][LandTypeTranslation[5]].Flags = 0x80;
    this->FromToTable[LandTypeTranslation[7]][LandTypeTranslation[4]].x = 2;
    this->FromToTable[LandTypeTranslation[7]][LandTypeTranslation[4]].y = 3;
    this->FromToTable[LandTypeTranslation[7]][LandTypeTranslation[4]].Page = 5;
    this->FromToTable[LandTypeTranslation[7]][LandTypeTranslation[4]].Flags = 0x80;
    for(int i = 0;
        i < 16;
        ++i) {
        for(int j = 0;
            j < 16;
            ++j) {
            for(int k = 0;
                k < 8;
                ++k) {
                for(int m = 0;
                    m < 8;
                    ++m) {
                    unsigned int iShadow = LandFogColors[j];
                    iShadow += (LandFogColors[j] << 8) + (LandFogColors[j] << 16);
                    if(j == 0) {
                        iShadow = 0xFF472449;
                    }
                    unsigned int iLight = this->uLightColor[j];
                    CHeightAndTypeTable::CalcFogging(i, k, m, j, iShadow, iLight);
                    this->uFogTable[i][j][k][m].m_uShadowFog = iShadow;
                    this->uFogTable[i][j][k][m].m_uLightFog = iLight;
                }
            }
        }
    }
}

// address=[0x2f81cd0]
// Decompiled from int __thiscall CHeightAndTypeTable::InitShadeTables(CHeightAndTypeTable *this)
void CHeightAndTypeTable::InitShadeTables(void) {

    float v2; // [esp+4h] [ebp-24h]
    float v3; // [esp+Ch] [ebp-1Ch]
              // [esp+10h] [ebp-18h]
              // [esp+14h] [ebp-14h]
              // [esp+18h] [ebp-10h]
              // [esp+1Ch] [ebp-Ch]
              // [esp+24h] [ebp-4h]
              // [esp+24h] [ebp-4h]
              // [esp+24h] [ebp-4h]

    float v5 = 71.0;
    float v6 = 48.0;
    float v7 = 23.0;
    if(48.0 >= 23.0) {
        v3 = 48.0;
    } else {
        v3 = 23.0;
    }
    if(v3 <= 71.0) {
        v2 = 71.0;
    } else {
        v2 = v3;
    }
    float v4 = v2 / 8.0;
    for(int i = 15;
        i > 8;
        --i) {
        this->uLightColor[i] = (int)(float)((float)(v7 / 256.0) * 255.0) | ((int)(float)((float)(v6 / 256.0) * 255.0) << 8) | ((int)(float)((float)(v5 / 256.0) * 255.0) << 16) | 0xFF000000;
        v7 = v7 - v4;
        if(v7 < 0.0) {
            v7 = 0.0;
        }
        v6 = v6 - v4;
        if(v6 < 0.0) {
            v6 = 0.0;
        }
        v5 = v5 - v4;
        if(v5 < 0.0) {
            v5 = 0.0;
        }
    }
    for(int j = 8;
        j >= 0;
        --j) {
        this->uLightColor[j] = 0xFF000000;
    }
    for(int k = 15;
        k > 8;
        --k) {
        this->uShadeColor[k] = 0xFFFFFFFF;
    }
    this->uShadeColor[8] = 0xFFFFFFFF;
    this->uShadeColor[7] = 0xFFA5A5A5;
    this->uShadeColor[6] = 0xFF666666;
    this->uShadeColor[5] = 0xFF3F3F3F;
    this->uShadeColor[4] = 0xFF232323;
    this->uShadeColor[3] = 0xFF161616;
    this->uShadeColor[2] = 0xFF0A0A0A;
    this->uShadeColor[1] = 0xFF000000;
    this->uShadeColor[0] = 0xFF472449;
}

// address=[0x2f85c90]
// Decompiled from void __thiscall CHeightAndTypeTable::CalcFogging(CHeightAndTypeTable *this, int a2, int a3, int a4, int a5, unsigned int *a6, unsigned int *a7)
void CHeightAndTypeTable::CalcFogging(int a2, int a3, int a4, int a5, unsigned int &_rShadow, unsigned int &_rLight) {

    // xmm0_4
    unsigned int iShade; // [esp+10h] [ebp-2Ch]
                         // [esp+18h] [ebp-24h]
                         // [esp+20h] [ebp-1Ch]
                         // [esp+34h] [ebp-8h]

    int v10 = 16 * (a3 * (15 - a2) + a4 * a2) / 15;
    if(v10 == 0)
        return;

    int v9 = (unsigned __int8)this->uShadeColor[8 - (v10 >> 4)];
    if(v10 >> 4 != 8) {
        v9 = (unsigned __int8)this->uShadeColor[8 - (v10 >> 4) - 1];
    }
    if(((unsigned __int8)this->uShadeColor[8 - (v10 >> 4)] * (15 - (v10 & 0xF)) + v9 * (v10 & 0xFu)) >> 4 >= (unsigned __int8)_rShadow) {
        iShade = (unsigned __int8)_rShadow;
    } else {
        iShade = ((unsigned __int8)this->uShadeColor[8 - (v10 >> 4)] * (15 - (v10 & 0xF)) + v9 * (v10 & 0xFu)) >> 4;
    }

    const unsigned __int8 iShadowA = _rShadow;
    const unsigned __int8 iShadowB = _rShadow >> 8;
    const unsigned __int8 iShadowC = _rShadow >> 16;

    const unsigned __int8 iLightA = _rLight;
    const unsigned __int8 iLightB = _rLight >> 8;
    const unsigned __int8 iLightC = _rLight >> 16;

    _rShadow = static_cast<int>(iShadowA * (iShade / 255.0f)) + (static_cast<int>(iShadowC * (iShade / 255.0f)) << 16) + (static_cast<int>(iShadowB * (iShade / 255.0f)) << 8);

    const float fLightness = 1.0f - (a3 * (15.0f - a2) + a4 * a2) / 105.0f;
    _rLight = static_cast<int>(iLightA * fLightness) + (static_cast<int>(iLightB * fLightness) << 16) + (static_cast<int>(iLightC * fLightness) << 8);

    // _rShadow = (int)((float)(unsigned __int8)_rShadow * (float)(v7 / 255.0)) + ((int)((float)(unsigned __int8)BYTE2(_rShadow) * (float)(v7 / 255.0)) << 16) + ((int)((float)(unsigned __int8)BYTE1(_rShadow) * (float)(v7 / 255.0)) << 8);
    // const float v11 = 1.0 - (float)((float)(a3 * (15 - a2) + a4 * a2) / 105.0);
    // _rLight = (int)((float)(unsigned __int8)_rLight * v11) + ((int)((float)(unsigned __int8)BYTE2(_rLight) * v11) << 16) + ((int)((float)(unsigned __int8)BYTE1(_rLight) * v11) << 8);
}

// address=[0x2f86020]
// Decompiled from int __thiscall CHeightAndTypeTable::GetAverageShadingValue(CHeightAndTypeTable *this, int a2, int a3)
int CHeightAndTypeTable::GetAverageShadingValue(int _iShadeA, int _iShadeB) {
    const unsigned __int8 iShadeA0 = _iShadeA;
    const unsigned __int8 iShadeA1 = _iShadeA >> 8;
    const unsigned __int8 iShadeA2 = _iShadeA >> 16;
    const unsigned __int8 iShadeB0 = _iShadeB;
    const unsigned __int8 iShadeB1 = _iShadeB >> 8;
    const unsigned __int8 iShadeB2 = _iShadeB >> 16;

    return (iShadeB0 + iShadeA0) / 2 + (((iShadeB2 + iShadeA2) / 2) << 16) + (((iShadeB1 + iShadeA1) / 2) << 8);
}

// address=[0x2f860e0]
// Decompiled from int __thiscall CHeightAndTypeTable::GetLightFog(CHeightAndTypeTable *this, int a2, int a3, int a4, int a5)
int CHeightAndTypeTable::GetLightFog(int a2, int a3, int a4, int a5) {
    return this->uFogTable[a2][a3][a4][a5].m_uLightFog;
}

// address=[0x2f86130]
// Decompiled from unsigned int __thiscall CHeightAndTypeTable::GetShadowFog(CHeightAndTypeTable *this, int a2, int a3, int a4, int a5)
int CHeightAndTypeTable::GetShadowFog(int a2, int a3, int a4, int a5) {
    return this->uFogTable[a2][a3][a4][a5].m_uShadowFog;
}
