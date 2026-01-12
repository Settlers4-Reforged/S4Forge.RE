#include "CHeightAndTypeTable.h"

// Definitions for class CHeightAndTypeTable

// address=[0x2f71cc0]
// Decompiled from int __thiscall CHeightAndTypeTable::GetObjectFog(CHeightAndTypeTable *this, int a2, int a3, int a4)
int  CHeightAndTypeTable::GetObjectFog(int,int,int) {
  
  return (unsigned __int8)*((_DWORD *)this + 2048 * a2 + 16 * a3 + 2 * a4 + 2577);
}


// address=[0x2f7c6a0]
// Decompiled from CHeightAndTypeTable *__thiscall CHeightAndTypeTable::CHeightAndTypeTable(CHeightAndTypeTable *this)
 CHeightAndTypeTable::CHeightAndTypeTable(void) {
  
  unsigned int v2; // [esp+0h] [ebp-1Ch] BYREF
  unsigned int v3; // [esp+4h] [ebp-18h] BYREF
  int m; // [esp+8h] [ebp-14h]
  int k; // [esp+Ch] [ebp-10h]
  int i; // [esp+10h] [ebp-Ch]
  int j; // [esp+14h] [ebp-8h]
  CHeightAndTypeTable *v8; // [esp+18h] [ebp-4h]

  v8 = this;
  CHeightAndTypeTable::InitShadeTables(this);
  j__memset((char *)v8 + 128, 0, 0x17C4u);
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[18] + 128) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[18] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[18] + 130) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[18] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[18] + 4 * (unsigned __int8)byte_3ACD510[16] + 128) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[18] + 4 * (unsigned __int8)byte_3ACD510[16] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[18] + 4 * (unsigned __int8)byte_3ACD510[16] + 130) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[18] + 4 * (unsigned __int8)byte_3ACD510[16] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[24] + 4 * (unsigned __int8)byte_3ACD510[25] + 128) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[24] + 4 * (unsigned __int8)byte_3ACD510[25] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[24] + 4 * (unsigned __int8)byte_3ACD510[25] + 130) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[24] + 4 * (unsigned __int8)byte_3ACD510[25] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[25] + 4 * (unsigned __int8)byte_3ACD510[24] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[25] + 4 * (unsigned __int8)byte_3ACD510[24] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[25] + 4 * (unsigned __int8)byte_3ACD510[24] + 130) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[25] + 4 * (unsigned __int8)byte_3ACD510[24] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[25] + 128) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[25] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[25] + 130) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[25] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[25] + 4 * (unsigned __int8)byte_3ACD510[16] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[25] + 4 * (unsigned __int8)byte_3ACD510[16] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[25] + 4 * (unsigned __int8)byte_3ACD510[16] + 130) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[25] + 4 * (unsigned __int8)byte_3ACD510[16] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[28] + 128) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[28] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[28] + 130) = 19;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[28] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[28] + 4 * (unsigned __int8)byte_3ACD510[16] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[28] + 4 * (unsigned __int8)byte_3ACD510[16] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[28] + 4 * (unsigned __int8)byte_3ACD510[16] + 130) = 19;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[28] + 4 * (unsigned __int8)byte_3ACD510[16] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[29] + 128) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[29] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[29] + 130) = 19;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[29] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[29] + 4 * (unsigned __int8)byte_3ACD510[16] + 128) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[29] + 4 * (unsigned __int8)byte_3ACD510[16] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[29] + 4 * (unsigned __int8)byte_3ACD510[16] + 130) = 19;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[29] + 4 * (unsigned __int8)byte_3ACD510[16] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 164) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 165) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 166) = 18;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 167) = -127;
  *((_BYTE *)v8 + 4 * (unsigned __int8)byte_3ACD510[16] + 1532) = 3;
  *((_BYTE *)v8 + 4 * (unsigned __int8)byte_3ACD510[16] + 1533) = 2;
  *((_BYTE *)v8 + 4 * (unsigned __int8)byte_3ACD510[16] + 1534) = 18;
  *((_BYTE *)v8 + 4 * (unsigned __int8)byte_3ACD510[16] + 1535) = -127;
  *((_BYTE *)v8 + 4 * (unsigned __int8)byte_3ACD510[99] + 1532) = 0;
  *((_BYTE *)v8 + 4 * (unsigned __int8)byte_3ACD510[99] + 1533) = 0;
  *((_BYTE *)v8 + 4 * (unsigned __int8)byte_3ACD510[99] + 1534) = 5;
  *((_BYTE *)v8 + 4 * (unsigned __int8)byte_3ACD510[99] + 1535) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 164) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 165) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 166) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 167) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[96] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[96] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[96] + 130) = 18;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[96] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[96] + 4 * (unsigned __int8)byte_3ACD510[16] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[96] + 4 * (unsigned __int8)byte_3ACD510[16] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[96] + 4 * (unsigned __int8)byte_3ACD510[16] + 130) = 18;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[96] + 4 * (unsigned __int8)byte_3ACD510[16] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[97] + 128) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[97] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[97] + 130) = 18;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[97] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[97] + 4 * (unsigned __int8)byte_3ACD510[16] + 128) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[97] + 4 * (unsigned __int8)byte_3ACD510[16] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[97] + 4 * (unsigned __int8)byte_3ACD510[16] + 130) = 18;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[97] + 4 * (unsigned __int8)byte_3ACD510[16] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[98] + 128) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[98] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[98] + 130) = 18;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[98] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[98] + 4 * (unsigned __int8)byte_3ACD510[16] + 128) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[98] + 4 * (unsigned __int8)byte_3ACD510[16] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[98] + 4 * (unsigned __int8)byte_3ACD510[16] + 130) = 18;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[98] + 4 * (unsigned __int8)byte_3ACD510[16] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[99] + 128) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[99] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[99] + 130) = 18;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[99] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 4 * (unsigned __int8)byte_3ACD510[16] + 128) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 4 * (unsigned __int8)byte_3ACD510[16] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 4 * (unsigned __int8)byte_3ACD510[16] + 130) = 18;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 4 * (unsigned __int8)byte_3ACD510[16] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[17] + 128) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[17] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[17] + 130) = 9;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[17] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[17] + 4 * (unsigned __int8)byte_3ACD510[16] + 128) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[17] + 4 * (unsigned __int8)byte_3ACD510[16] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[17] + 4 * (unsigned __int8)byte_3ACD510[16] + 130) = 9;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[17] + 4 * (unsigned __int8)byte_3ACD510[16] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[17] + 4 * (unsigned __int8)byte_3ACD510[33] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[17] + 4 * (unsigned __int8)byte_3ACD510[33] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[17] + 4 * (unsigned __int8)byte_3ACD510[33] + 130) = 9;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[17] + 4 * (unsigned __int8)byte_3ACD510[33] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[33] + 4 * (unsigned __int8)byte_3ACD510[17] + 128) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[33] + 4 * (unsigned __int8)byte_3ACD510[17] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[33] + 4 * (unsigned __int8)byte_3ACD510[17] + 130) = 9;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[33] + 4 * (unsigned __int8)byte_3ACD510[17] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[33] + 4 * (unsigned __int8)byte_3ACD510[32] + 128) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[33] + 4 * (unsigned __int8)byte_3ACD510[32] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[33] + 4 * (unsigned __int8)byte_3ACD510[32] + 130) = 9;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[33] + 4 * (unsigned __int8)byte_3ACD510[32] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[32] + 4 * (unsigned __int8)byte_3ACD510[33] + 128) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[32] + 4 * (unsigned __int8)byte_3ACD510[33] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[32] + 4 * (unsigned __int8)byte_3ACD510[33] + 130) = 9;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[32] + 4 * (unsigned __int8)byte_3ACD510[33] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[32] + 4 * (unsigned __int8)byte_3ACD510[35] + 128) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[32] + 4 * (unsigned __int8)byte_3ACD510[35] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[32] + 4 * (unsigned __int8)byte_3ACD510[35] + 130) = 16;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[32] + 4 * (unsigned __int8)byte_3ACD510[35] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[35] + 4 * (unsigned __int8)byte_3ACD510[32] + 128) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[35] + 4 * (unsigned __int8)byte_3ACD510[32] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[35] + 4 * (unsigned __int8)byte_3ACD510[32] + 130) = 16;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[35] + 4 * (unsigned __int8)byte_3ACD510[32] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[35] + 4 * (unsigned __int8)byte_3ACD510[129] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[35] + 4 * (unsigned __int8)byte_3ACD510[129] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[35] + 4 * (unsigned __int8)byte_3ACD510[129] + 130) = 16;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[35] + 4 * (unsigned __int8)byte_3ACD510[129] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[129] + 4 * (unsigned __int8)byte_3ACD510[35] + 128) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[129] + 4 * (unsigned __int8)byte_3ACD510[35] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[129] + 4 * (unsigned __int8)byte_3ACD510[35] + 130) = 16;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[129] + 4 * (unsigned __int8)byte_3ACD510[35] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[129] + 4 * (unsigned __int8)byte_3ACD510[128] + 128) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[129] + 4 * (unsigned __int8)byte_3ACD510[128] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[129] + 4 * (unsigned __int8)byte_3ACD510[128] + 130) = 16;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[129] + 4 * (unsigned __int8)byte_3ACD510[128] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[128] + 4 * (unsigned __int8)byte_3ACD510[129] + 128) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[128] + 4 * (unsigned __int8)byte_3ACD510[129] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[128] + 4 * (unsigned __int8)byte_3ACD510[129] + 130) = 16;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[128] + 4 * (unsigned __int8)byte_3ACD510[129] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[21] + 128) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[21] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[21] + 130) = 14;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[21] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[21] + 4 * (unsigned __int8)byte_3ACD510[16] + 128) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[21] + 4 * (unsigned __int8)byte_3ACD510[16] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[21] + 4 * (unsigned __int8)byte_3ACD510[16] + 130) = 14;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[21] + 4 * (unsigned __int8)byte_3ACD510[16] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[21] + 4 * (unsigned __int8)byte_3ACD510[81] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[21] + 4 * (unsigned __int8)byte_3ACD510[81] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[21] + 4 * (unsigned __int8)byte_3ACD510[81] + 130) = 14;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[21] + 4 * (unsigned __int8)byte_3ACD510[81] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[81] + 4 * (unsigned __int8)byte_3ACD510[21] + 128) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[81] + 4 * (unsigned __int8)byte_3ACD510[21] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[81] + 4 * (unsigned __int8)byte_3ACD510[21] + 130) = 14;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[81] + 4 * (unsigned __int8)byte_3ACD510[21] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[81] + 4 * (unsigned __int8)byte_3ACD510[80] + 128) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[81] + 4 * (unsigned __int8)byte_3ACD510[80] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[81] + 4 * (unsigned __int8)byte_3ACD510[80] + 130) = 14;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[81] + 4 * (unsigned __int8)byte_3ACD510[80] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[80] + 4 * (unsigned __int8)byte_3ACD510[81] + 128) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[80] + 4 * (unsigned __int8)byte_3ACD510[81] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[80] + 4 * (unsigned __int8)byte_3ACD510[81] + 130) = 14;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[80] + 4 * (unsigned __int8)byte_3ACD510[81] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[23] + 128) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[23] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[23] + 130) = 12;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[23] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[23] + 4 * (unsigned __int8)byte_3ACD510[16] + 128) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[23] + 4 * (unsigned __int8)byte_3ACD510[16] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[23] + 4 * (unsigned __int8)byte_3ACD510[16] + 130) = 12;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[23] + 4 * (unsigned __int8)byte_3ACD510[16] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[23] + 4 * (unsigned __int8)byte_3ACD510[145] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[23] + 4 * (unsigned __int8)byte_3ACD510[145] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[23] + 4 * (unsigned __int8)byte_3ACD510[145] + 130) = 12;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[23] + 4 * (unsigned __int8)byte_3ACD510[145] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[145] + 4 * (unsigned __int8)byte_3ACD510[23] + 128) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[145] + 4 * (unsigned __int8)byte_3ACD510[23] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[145] + 4 * (unsigned __int8)byte_3ACD510[23] + 130) = 12;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[145] + 4 * (unsigned __int8)byte_3ACD510[23] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[145] + 4 * (unsigned __int8)byte_3ACD510[144] + 128) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[145] + 4 * (unsigned __int8)byte_3ACD510[144] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[145] + 4 * (unsigned __int8)byte_3ACD510[144] + 130) = 12;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[145] + 4 * (unsigned __int8)byte_3ACD510[144] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[144] + 4 * (unsigned __int8)byte_3ACD510[145] + 128) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[144] + 4 * (unsigned __int8)byte_3ACD510[145] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[144] + 4 * (unsigned __int8)byte_3ACD510[145] + 130) = 12;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[144] + 4 * (unsigned __int8)byte_3ACD510[145] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[20] + 128) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[20] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[20] + 130) = 11;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[20] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[20] + 4 * (unsigned __int8)byte_3ACD510[16] + 128) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[20] + 4 * (unsigned __int8)byte_3ACD510[16] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[20] + 4 * (unsigned __int8)byte_3ACD510[16] + 130) = 11;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[20] + 4 * (unsigned __int8)byte_3ACD510[16] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[20] + 4 * (unsigned __int8)byte_3ACD510[65] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[20] + 4 * (unsigned __int8)byte_3ACD510[65] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[20] + 4 * (unsigned __int8)byte_3ACD510[65] + 130) = 11;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[20] + 4 * (unsigned __int8)byte_3ACD510[65] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[65] + 4 * (unsigned __int8)byte_3ACD510[20] + 128) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[65] + 4 * (unsigned __int8)byte_3ACD510[20] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[65] + 4 * (unsigned __int8)byte_3ACD510[20] + 130) = 11;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[65] + 4 * (unsigned __int8)byte_3ACD510[20] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[65] + 4 * (unsigned __int8)byte_3ACD510[64] + 128) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[65] + 4 * (unsigned __int8)byte_3ACD510[64] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[65] + 4 * (unsigned __int8)byte_3ACD510[64] + 130) = 11;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[65] + 4 * (unsigned __int8)byte_3ACD510[64] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[64] + 4 * (unsigned __int8)byte_3ACD510[65] + 128) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[64] + 4 * (unsigned __int8)byte_3ACD510[65] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[64] + 4 * (unsigned __int8)byte_3ACD510[65] + 130) = 11;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[64] + 4 * (unsigned __int8)byte_3ACD510[65] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[48] + 128) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[48] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[48] + 130) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[16] + 4 * (unsigned __int8)byte_3ACD510[48] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[48] + 4 * (unsigned __int8)byte_3ACD510[16] + 128) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[48] + 4 * (unsigned __int8)byte_3ACD510[16] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[48] + 4 * (unsigned __int8)byte_3ACD510[16] + 130) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[48] + 4 * (unsigned __int8)byte_3ACD510[16] + 131) = -127;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[48] + 164) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[48] + 165) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[48] + 166) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[48] + 167) = -127;
  *((_BYTE *)v8 + 4 * (unsigned __int8)byte_3ACD510[48] + 1532) = 1;
  *((_BYTE *)v8 + 4 * (unsigned __int8)byte_3ACD510[48] + 1533) = 2;
  *((_BYTE *)v8 + 4 * (unsigned __int8)byte_3ACD510[48] + 1534) = 5;
  *((_BYTE *)v8 + 4 * (unsigned __int8)byte_3ACD510[48] + 1535) = -127;
  *((_BYTE *)v8 + 4 * (unsigned __int8)byte_3ACD510[1] + 1532) = 0;
  *((_BYTE *)v8 + 4 * (unsigned __int8)byte_3ACD510[1] + 1533) = 0;
  *((_BYTE *)v8 + 4 * (unsigned __int8)byte_3ACD510[1] + 1534) = 6;
  *((_BYTE *)v8 + 4 * (unsigned __int8)byte_3ACD510[1] + 1535) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[1] + 164) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[1] + 165) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[1] + 166) = 6;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[1] + 167) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[1] + 4 * (unsigned __int8)byte_3ACD510[2] + 128) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[1] + 4 * (unsigned __int8)byte_3ACD510[2] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[1] + 4 * (unsigned __int8)byte_3ACD510[2] + 130) = 6;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[1] + 4 * (unsigned __int8)byte_3ACD510[2] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[2] + 4 * (unsigned __int8)byte_3ACD510[1] + 128) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[2] + 4 * (unsigned __int8)byte_3ACD510[1] + 129) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[2] + 4 * (unsigned __int8)byte_3ACD510[1] + 130) = 6;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[2] + 4 * (unsigned __int8)byte_3ACD510[1] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[2] + 4 * (unsigned __int8)byte_3ACD510[3] + 128) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[2] + 4 * (unsigned __int8)byte_3ACD510[3] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[2] + 4 * (unsigned __int8)byte_3ACD510[3] + 130) = 6;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[2] + 4 * (unsigned __int8)byte_3ACD510[3] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[3] + 4 * (unsigned __int8)byte_3ACD510[2] + 128) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[3] + 4 * (unsigned __int8)byte_3ACD510[2] + 129) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[3] + 4 * (unsigned __int8)byte_3ACD510[2] + 130) = 6;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[3] + 4 * (unsigned __int8)byte_3ACD510[2] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[3] + 4 * (unsigned __int8)byte_3ACD510[4] + 128) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[3] + 4 * (unsigned __int8)byte_3ACD510[4] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[3] + 4 * (unsigned __int8)byte_3ACD510[4] + 130) = 6;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[3] + 4 * (unsigned __int8)byte_3ACD510[4] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[4] + 4 * (unsigned __int8)byte_3ACD510[3] + 128) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[4] + 4 * (unsigned __int8)byte_3ACD510[3] + 129) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[4] + 4 * (unsigned __int8)byte_3ACD510[3] + 130) = 6;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[4] + 4 * (unsigned __int8)byte_3ACD510[3] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[4] + 4 * (unsigned __int8)byte_3ACD510[5] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[4] + 4 * (unsigned __int8)byte_3ACD510[5] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[4] + 4 * (unsigned __int8)byte_3ACD510[5] + 130) = 6;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[4] + 4 * (unsigned __int8)byte_3ACD510[5] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[5] + 4 * (unsigned __int8)byte_3ACD510[4] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[5] + 4 * (unsigned __int8)byte_3ACD510[4] + 129) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[5] + 4 * (unsigned __int8)byte_3ACD510[4] + 130) = 6;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[5] + 4 * (unsigned __int8)byte_3ACD510[4] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[5] + 4 * (unsigned __int8)byte_3ACD510[6] + 128) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[5] + 4 * (unsigned __int8)byte_3ACD510[6] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[5] + 4 * (unsigned __int8)byte_3ACD510[6] + 130) = 6;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[5] + 4 * (unsigned __int8)byte_3ACD510[6] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[6] + 4 * (unsigned __int8)byte_3ACD510[5] + 128) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[6] + 4 * (unsigned __int8)byte_3ACD510[5] + 129) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[6] + 4 * (unsigned __int8)byte_3ACD510[5] + 130) = 6;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[6] + 4 * (unsigned __int8)byte_3ACD510[5] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[6] + 4 * (unsigned __int8)byte_3ACD510[7] + 128) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[6] + 4 * (unsigned __int8)byte_3ACD510[7] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[6] + 4 * (unsigned __int8)byte_3ACD510[7] + 130) = 6;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[6] + 4 * (unsigned __int8)byte_3ACD510[7] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[7] + 4 * (unsigned __int8)byte_3ACD510[6] + 128) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[7] + 4 * (unsigned __int8)byte_3ACD510[6] + 129) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[7] + 4 * (unsigned __int8)byte_3ACD510[6] + 130) = 6;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[7] + 4 * (unsigned __int8)byte_3ACD510[6] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[25] + 4 * (unsigned __int8)byte_3ACD510[25] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[25] + 4 * (unsigned __int8)byte_3ACD510[25] + 129) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[25] + 4 * (unsigned __int8)byte_3ACD510[25] + 130) = 9;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[25] + 4 * (unsigned __int8)byte_3ACD510[25] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[17] + 4 * (unsigned __int8)byte_3ACD510[17] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[17] + 4 * (unsigned __int8)byte_3ACD510[17] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[17] + 4 * (unsigned __int8)byte_3ACD510[17] + 130) = 9;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[17] + 4 * (unsigned __int8)byte_3ACD510[17] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[33] + 4 * (unsigned __int8)byte_3ACD510[33] + 128) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[33] + 4 * (unsigned __int8)byte_3ACD510[33] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[33] + 4 * (unsigned __int8)byte_3ACD510[33] + 130) = 9;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[33] + 4 * (unsigned __int8)byte_3ACD510[33] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[35] + 4 * (unsigned __int8)byte_3ACD510[35] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[35] + 4 * (unsigned __int8)byte_3ACD510[35] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[35] + 4 * (unsigned __int8)byte_3ACD510[35] + 130) = 16;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[35] + 4 * (unsigned __int8)byte_3ACD510[35] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[129] + 4 * (unsigned __int8)byte_3ACD510[129] + 128) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[129] + 4 * (unsigned __int8)byte_3ACD510[129] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[129] + 4 * (unsigned __int8)byte_3ACD510[129] + 130) = 16;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[129] + 4 * (unsigned __int8)byte_3ACD510[129] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[21] + 4 * (unsigned __int8)byte_3ACD510[21] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[21] + 4 * (unsigned __int8)byte_3ACD510[21] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[21] + 4 * (unsigned __int8)byte_3ACD510[21] + 130) = 14;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[21] + 4 * (unsigned __int8)byte_3ACD510[21] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[81] + 4 * (unsigned __int8)byte_3ACD510[81] + 128) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[81] + 4 * (unsigned __int8)byte_3ACD510[81] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[81] + 4 * (unsigned __int8)byte_3ACD510[81] + 130) = 14;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[81] + 4 * (unsigned __int8)byte_3ACD510[81] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[23] + 4 * (unsigned __int8)byte_3ACD510[23] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[23] + 4 * (unsigned __int8)byte_3ACD510[23] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[23] + 4 * (unsigned __int8)byte_3ACD510[23] + 130) = 12;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[23] + 4 * (unsigned __int8)byte_3ACD510[23] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[145] + 4 * (unsigned __int8)byte_3ACD510[145] + 128) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[145] + 4 * (unsigned __int8)byte_3ACD510[145] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[145] + 4 * (unsigned __int8)byte_3ACD510[145] + 130) = 12;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[145] + 4 * (unsigned __int8)byte_3ACD510[145] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[20] + 4 * (unsigned __int8)byte_3ACD510[20] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[20] + 4 * (unsigned __int8)byte_3ACD510[20] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[20] + 4 * (unsigned __int8)byte_3ACD510[20] + 130) = 11;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[20] + 4 * (unsigned __int8)byte_3ACD510[20] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[65] + 4 * (unsigned __int8)byte_3ACD510[65] + 128) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[65] + 4 * (unsigned __int8)byte_3ACD510[65] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[65] + 4 * (unsigned __int8)byte_3ACD510[65] + 130) = 11;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[65] + 4 * (unsigned __int8)byte_3ACD510[65] + 131) = 0x80;
  *((_BYTE *)v8 + 1568) = 0;
  *((_BYTE *)v8 + 1569) = 0;
  *((_BYTE *)v8 + 1570) = 5;
  *((_BYTE *)v8 + 1571) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[1] + 4 * (unsigned __int8)byte_3ACD510[1] + 128) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[1] + 4 * (unsigned __int8)byte_3ACD510[1] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[1] + 4 * (unsigned __int8)byte_3ACD510[1] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[1] + 4 * (unsigned __int8)byte_3ACD510[1] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[2] + 4 * (unsigned __int8)byte_3ACD510[2] + 128) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[2] + 4 * (unsigned __int8)byte_3ACD510[2] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[2] + 4 * (unsigned __int8)byte_3ACD510[2] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[2] + 4 * (unsigned __int8)byte_3ACD510[2] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[3] + 4 * (unsigned __int8)byte_3ACD510[3] + 128) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[3] + 4 * (unsigned __int8)byte_3ACD510[3] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[3] + 4 * (unsigned __int8)byte_3ACD510[3] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[3] + 4 * (unsigned __int8)byte_3ACD510[3] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[4] + 4 * (unsigned __int8)byte_3ACD510[4] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[4] + 4 * (unsigned __int8)byte_3ACD510[4] + 129) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[4] + 4 * (unsigned __int8)byte_3ACD510[4] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[4] + 4 * (unsigned __int8)byte_3ACD510[4] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[5] + 4 * (unsigned __int8)byte_3ACD510[5] + 128) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[5] + 4 * (unsigned __int8)byte_3ACD510[5] + 129) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[5] + 4 * (unsigned __int8)byte_3ACD510[5] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[5] + 4 * (unsigned __int8)byte_3ACD510[5] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[6] + 4 * (unsigned __int8)byte_3ACD510[6] + 128) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[6] + 4 * (unsigned __int8)byte_3ACD510[6] + 129) = 1;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[6] + 4 * (unsigned __int8)byte_3ACD510[6] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[6] + 4 * (unsigned __int8)byte_3ACD510[6] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[96] + 4 * (unsigned __int8)byte_3ACD510[96] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[96] + 4 * (unsigned __int8)byte_3ACD510[96] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[96] + 4 * (unsigned __int8)byte_3ACD510[96] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[96] + 4 * (unsigned __int8)byte_3ACD510[96] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[96] + 4 * (unsigned __int8)byte_3ACD510[97] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[96] + 4 * (unsigned __int8)byte_3ACD510[97] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[96] + 4 * (unsigned __int8)byte_3ACD510[97] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[96] + 4 * (unsigned __int8)byte_3ACD510[97] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[96] + 4 * (unsigned __int8)byte_3ACD510[98] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[96] + 4 * (unsigned __int8)byte_3ACD510[98] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[96] + 4 * (unsigned __int8)byte_3ACD510[98] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[96] + 4 * (unsigned __int8)byte_3ACD510[98] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[96] + 4 * (unsigned __int8)byte_3ACD510[99] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[96] + 4 * (unsigned __int8)byte_3ACD510[99] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[96] + 4 * (unsigned __int8)byte_3ACD510[99] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[96] + 4 * (unsigned __int8)byte_3ACD510[99] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[97] + 4 * (unsigned __int8)byte_3ACD510[96] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[97] + 4 * (unsigned __int8)byte_3ACD510[96] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[97] + 4 * (unsigned __int8)byte_3ACD510[96] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[97] + 4 * (unsigned __int8)byte_3ACD510[96] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[97] + 4 * (unsigned __int8)byte_3ACD510[97] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[97] + 4 * (unsigned __int8)byte_3ACD510[97] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[97] + 4 * (unsigned __int8)byte_3ACD510[97] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[97] + 4 * (unsigned __int8)byte_3ACD510[97] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[97] + 4 * (unsigned __int8)byte_3ACD510[98] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[97] + 4 * (unsigned __int8)byte_3ACD510[98] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[97] + 4 * (unsigned __int8)byte_3ACD510[98] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[97] + 4 * (unsigned __int8)byte_3ACD510[98] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[97] + 4 * (unsigned __int8)byte_3ACD510[99] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[97] + 4 * (unsigned __int8)byte_3ACD510[99] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[97] + 4 * (unsigned __int8)byte_3ACD510[99] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[97] + 4 * (unsigned __int8)byte_3ACD510[99] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[98] + 4 * (unsigned __int8)byte_3ACD510[96] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[98] + 4 * (unsigned __int8)byte_3ACD510[96] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[98] + 4 * (unsigned __int8)byte_3ACD510[96] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[98] + 4 * (unsigned __int8)byte_3ACD510[96] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[98] + 4 * (unsigned __int8)byte_3ACD510[97] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[98] + 4 * (unsigned __int8)byte_3ACD510[97] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[98] + 4 * (unsigned __int8)byte_3ACD510[97] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[98] + 4 * (unsigned __int8)byte_3ACD510[97] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[98] + 4 * (unsigned __int8)byte_3ACD510[98] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[98] + 4 * (unsigned __int8)byte_3ACD510[98] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[98] + 4 * (unsigned __int8)byte_3ACD510[98] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[98] + 4 * (unsigned __int8)byte_3ACD510[98] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[98] + 4 * (unsigned __int8)byte_3ACD510[99] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[98] + 4 * (unsigned __int8)byte_3ACD510[99] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[98] + 4 * (unsigned __int8)byte_3ACD510[99] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[98] + 4 * (unsigned __int8)byte_3ACD510[99] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 4 * (unsigned __int8)byte_3ACD510[96] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 4 * (unsigned __int8)byte_3ACD510[96] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 4 * (unsigned __int8)byte_3ACD510[96] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 4 * (unsigned __int8)byte_3ACD510[96] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 4 * (unsigned __int8)byte_3ACD510[97] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 4 * (unsigned __int8)byte_3ACD510[97] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 4 * (unsigned __int8)byte_3ACD510[97] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 4 * (unsigned __int8)byte_3ACD510[97] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 4 * (unsigned __int8)byte_3ACD510[98] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 4 * (unsigned __int8)byte_3ACD510[98] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 4 * (unsigned __int8)byte_3ACD510[98] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 4 * (unsigned __int8)byte_3ACD510[98] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 4 * (unsigned __int8)byte_3ACD510[99] + 128) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 4 * (unsigned __int8)byte_3ACD510[99] + 129) = 0;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 4 * (unsigned __int8)byte_3ACD510[99] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[99] + 4 * (unsigned __int8)byte_3ACD510[99] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[7] + 4 * (unsigned __int8)byte_3ACD510[5] + 128) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[7] + 4 * (unsigned __int8)byte_3ACD510[5] + 129) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[7] + 4 * (unsigned __int8)byte_3ACD510[5] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[7] + 4 * (unsigned __int8)byte_3ACD510[5] + 131) = 0x80;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[7] + 4 * (unsigned __int8)byte_3ACD510[4] + 128) = 2;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[7] + 4 * (unsigned __int8)byte_3ACD510[4] + 129) = 3;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[7] + 4 * (unsigned __int8)byte_3ACD510[4] + 130) = 5;
  *((_BYTE *)v8 + 156 * (unsigned __int8)byte_3ACD510[7] + 4 * (unsigned __int8)byte_3ACD510[4] + 131) = 0x80;
  for ( i = 0; i < 16; ++i )
  {
    for ( j = 0; j < 16; ++j )
    {
      for ( k = 0; k < 8; ++k )
      {
        for ( m = 0; m < 8; ++m )
        {
          v3 = (unsigned __int8)byte_3ACD720[j];
          v3 += ((unsigned __int8)byte_3ACD720[j] << 8) + ((unsigned __int8)byte_3ACD720[j] << 16);
          if ( !j )
            v3 = -12114871;
          v2 = *((_DWORD *)v8 + j + 16);
          CHeightAndTypeTable::CalcFogging(v8, i, k, m, j, &v3, &v2);
          *((_DWORD *)v8 + 2048 * i + 128 * j + 16 * k + 2 * m + 1553) = v3;
          *((_DWORD *)v8 + 2048 * i + 128 * j + 16 * k + 2 * m + 1554) = v2;
        }
      }
    }
  }
  return v8;
}


// address=[0x2f81cd0]
// Decompiled from int __thiscall CHeightAndTypeTable::InitShadeTables(CHeightAndTypeTable *this)
void  CHeightAndTypeTable::InitShadeTables(void) {
  
  int result; // eax
  float v2; // [esp+4h] [ebp-24h]
  float v3; // [esp+Ch] [ebp-1Ch]
  float v4; // [esp+10h] [ebp-18h]
  float v5; // [esp+14h] [ebp-14h]
  float v6; // [esp+18h] [ebp-10h]
  float v7; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+24h] [ebp-4h]
  int j; // [esp+24h] [ebp-4h]
  int k; // [esp+24h] [ebp-4h]

  v5 = FLOAT_71_0;
  v6 = FLOAT_48_0;
  v7 = FLOAT_23_0;
  if ( 48.0 >= 23.0 )
    v3 = FLOAT_48_0;
  else
    v3 = FLOAT_23_0;
  if ( v3 <= 71.0 )
    v2 = FLOAT_71_0;
  else
    v2 = v3;
  v4 = v2 / 8.0;
  for ( i = 15; i > 8; --i )
  {
    *((_DWORD *)this + i + 16) = (int)(float)((float)(v7 / 256.0) * 255.0) | ((int)(float)((float)(v6 / 256.0) * 255.0) << 8) | ((int)(float)((float)(v5 / 256.0) * 255.0) << 16) | 0xFF000000;
    v7 = v7 - v4;
    if ( v7 < 0.0 )
      v7 = 0.0;
    v6 = v6 - v4;
    if ( v6 < 0.0 )
      v6 = 0.0;
    v5 = v5 - v4;
    if ( v5 < 0.0 )
      v5 = 0.0;
  }
  for ( j = 8; j >= 0; --j )
    *((_DWORD *)this + j + 16) = -16777216;
  for ( k = 15; k > 8; --k )
    *((_DWORD *)this + k) = -1;
  *((_DWORD *)this + 8) = -1;
  *((_DWORD *)this + 7) = -5921371;
  *((_DWORD *)this + 6) = -10066330;
  *((_DWORD *)this + 5) = -12632257;
  *((_DWORD *)this + 4) = -14474461;
  *((_DWORD *)this + 3) = -15329770;
  *((_DWORD *)this + 2) = -16119286;
  *((_DWORD *)this + 1) = -16777216;
  result = 4;
  *(_DWORD *)this = -12114871;
  return result;
}


// address=[0x2f85c90]
// Decompiled from int __thiscall CHeightAndTypeTable::CalcFogging(  CHeightAndTypeTable *this,  int a2,  int a3,  int a4,  int a5,  unsigned int *a6,  unsigned int *a7)
void  CHeightAndTypeTable::CalcFogging(int,int,int,int,unsigned int &,unsigned int &) {
  
  int result; // eax
  float v8; // xmm0_4
  unsigned int v9; // [esp+10h] [ebp-2Ch]
  int v10; // [esp+18h] [ebp-24h]
  float v11; // [esp+34h] [ebp-8h]

  result = 16 * (a3 * (15 - a2) + a4 * a2) / 15;
  if ( !result )
    return result;
  v10 = (unsigned __int8)*((_DWORD *)this + 8 - (result >> 4));
  if ( result >> 4 != 8 )
    v10 = (unsigned __int8)*((_DWORD *)this + 8 - (result >> 4) - 1);
  if ( ((unsigned __int8)*((_DWORD *)this + 8 - (result >> 4)) * (15 - (result & 0xF)) + v10 * (result & 0xFu)) >> 4 >= (unsigned __int8)*a6 )
    v9 = (unsigned __int8)*a6;
  else
    v9 = ((unsigned __int8)*((_DWORD *)this + 8 - (result >> 4)) * (15 - (result & 0xF)) + v10 * (result & 0xFu)) >> 4;
  v8 = (float)v9;
  *a6 = (int)(float)((float)(unsigned __int8)*a6 * (float)(v8 / 255.0))
      + ((int)(float)((float)(unsigned __int8)BYTE2(*a6) * (float)(v8 / 255.0)) << 16)
      + ((int)(float)((float)(unsigned __int8)BYTE1(*a6) * (float)(v8 / 255.0)) << 8);
  v11 = 1.0 - (float)((float)(a3 * (15 - a2) + a4 * a2) / 105.0);
  result = (int)(float)((float)(unsigned __int8)*a7 * v11)
         + ((int)(float)((float)(unsigned __int8)BYTE2(*a7) * v11) << 16);
  *a7 = result + ((int)(float)((float)(unsigned __int8)BYTE1(*a7) * v11) << 8);
  return result;
}


// address=[0x2f86020]
// Decompiled from int __thiscall CHeightAndTypeTable::GetAverageShadingValue(CHeightAndTypeTable *this, int a2, int a3)
int  CHeightAndTypeTable::GetAverageShadingValue(int,int) {
  
  return ((unsigned __int8)a3 + (unsigned __int8)a2) / 2
       + (((BYTE2(a3) + BYTE2(a2)) / 2) << 16)
       + (((BYTE1(a3) + BYTE1(a2)) / 2) << 8);
}


// address=[0x2f860e0]
// Decompiled from int __thiscall CHeightAndTypeTable::GetLightFog(CHeightAndTypeTable *this, int a2, int a3, int a4, int a5)
int  CHeightAndTypeTable::GetLightFog(int,int,int,int) {
  
  return *((_DWORD *)this + 2048 * a2 + 128 * a3 + 16 * a4 + 2 * a5 + 1554);
}


// address=[0x2f86130]
// Decompiled from int __thiscall CHeightAndTypeTable::GetShadowFog(CHeightAndTypeTable *this, int a2, int a3, int a4, int a5)
int  CHeightAndTypeTable::GetShadowFog(int,int,int,int) {
  
  return *((_DWORD *)this + 2048 * a2 + 128 * a3 + 16 * a4 + 2 * a5 + 1553);
}


