#include "CLandscapeColorProperties.h"

// Definitions for class CLandscapeColorProperties

// address=[0x2f8dcb0]
// Decompiled from CLandscapeColorProperties *__thiscall CLandscapeColorProperties::CLandscapeColorProperties(CLandscapeColorProperties *this)
 CLandscapeColorProperties::CLandscapeColorProperties(void) {
  
  int i; // [esp+10h] [ebp-Ch]

  this->m_vColorEntries[16].m_iRed = 0;
  this->m_vColorEntries[16].m_iGreen = 100;
  this->m_vColorEntries[16].m_iBlue = 0;
  this->m_vHiColorEntry[16] = 0;
  this->m_vColorEntries[0].m_iRed = 0;
  this->m_vColorEntries[0].m_iGreen = 85;
  this->m_vColorEntries[0].m_iBlue = 110;
  this->m_vHiColorEntry[0] = 0;
  this->m_vColorEntries[1].m_iRed = 0;
  this->m_vColorEntries[1].m_iGreen = 76;
  this->m_vColorEntries[1].m_iBlue = 101;
  this->m_vHiColorEntry[1] = 0;
  this->m_vColorEntries[2].m_iRed = 0;
  this->m_vColorEntries[2].m_iGreen = 67;
  this->m_vColorEntries[2].m_iBlue = 92;
  this->m_vHiColorEntry[2] = 0;
  this->m_vColorEntries[3].m_iRed = 0;
  this->m_vColorEntries[3].m_iGreen = 58;
  this->m_vColorEntries[3].m_iBlue = 83;
  this->m_vHiColorEntry[3] = 0;
  this->m_vColorEntries[4].m_iRed = 0;
  this->m_vColorEntries[4].m_iGreen = 49;
  this->m_vColorEntries[4].m_iBlue = 74;
  this->m_vHiColorEntry[4] = 0;
  this->m_vColorEntries[5].m_iRed = 0;
  this->m_vColorEntries[5].m_iGreen = 40;
  this->m_vColorEntries[5].m_iBlue = 65;
  this->m_vHiColorEntry[5] = 0;
  this->m_vColorEntries[6].m_iRed = 0;
  this->m_vColorEntries[6].m_iGreen = 31;
  this->m_vColorEntries[6].m_iBlue = 54;
  this->m_vHiColorEntry[6] = 0;
  this->m_vColorEntries[7].m_iRed = 0;
  this->m_vColorEntries[7].m_iGreen = 22;
  this->m_vColorEntries[7].m_iBlue = 47;
  this->m_vHiColorEntry[7] = 0;
  this->m_vColorEntries[48].m_iRed = 100;
  this->m_vColorEntries[48].m_iGreen = 90;
  this->m_vColorEntries[48].m_iBlue = 50;
  this->m_vHiColorEntry[48] = 0;
  this->m_vColorEntries[8].m_iRed = 100;
  this->m_vColorEntries[8].m_iGreen = 90;
  this->m_vColorEntries[8].m_iBlue = 50;
  this->m_vHiColorEntry[8] = 0;
  this->m_vColorEntries[32].m_iRed = 40;
  this->m_vColorEntries[32].m_iGreen = 40;
  this->m_vColorEntries[32].m_iBlue = 30;
  this->m_vHiColorEntry[32] = 0;
  this->m_vColorEntries[17].m_iRed = 10;
  this->m_vColorEntries[17].m_iGreen = 80;
  this->m_vColorEntries[17].m_iBlue = 10;
  this->m_vHiColorEntry[17] = 0;
  this->m_vColorEntries[33].m_iRed = 20;
  this->m_vColorEntries[33].m_iGreen = 60;
  this->m_vColorEntries[33].m_iBlue = 20;
  this->m_vHiColorEntry[33] = 0;
  this->m_vColorEntries[129].m_iRed = 76;
  this->m_vColorEntries[129].m_iGreen = 80;
  this->m_vColorEntries[129].m_iBlue = 82;
  this->m_vHiColorEntry[129] = 0;
  this->m_vColorEntries[35].m_iRed = 65;
  this->m_vColorEntries[35].m_iGreen = 70;
  this->m_vColorEntries[35].m_iBlue = 65;
  this->m_vHiColorEntry[35] = 0;
  this->m_vColorEntries[24].m_iRed = 40;
  this->m_vColorEntries[24].m_iGreen = 80;
  this->m_vColorEntries[24].m_iBlue = 20;
  this->m_vHiColorEntry[24] = 0;
  this->m_vColorEntries[25].m_iRed = 60;
  this->m_vColorEntries[25].m_iGreen = 100;
  this->m_vColorEntries[25].m_iBlue = 30;
  this->m_vHiColorEntry[25] = 0;
  this->m_vColorEntries[18].m_iRed = 30;
  this->m_vColorEntries[18].m_iGreen = 100;
  this->m_vColorEntries[18].m_iBlue = 70;
  this->m_vHiColorEntry[18] = 0;
  this->m_vColorEntries[128].m_iRed = 88;
  this->m_vColorEntries[128].m_iGreen = 92;
  this->m_vColorEntries[128].m_iBlue = 98;
  this->m_vHiColorEntry[128] = 0;
  this->m_vColorEntries[80].m_iRed = 60;
  this->m_vColorEntries[80].m_iGreen = 0;
  this->m_vColorEntries[80].m_iBlue = 0;
  this->m_vHiColorEntry[80] = 0;
  this->m_vColorEntries[81].m_iRed = 40;
  this->m_vColorEntries[81].m_iGreen = 50;
  this->m_vColorEntries[81].m_iBlue = 0;
  this->m_vHiColorEntry[81] = 0;
  this->m_vColorEntries[21].m_iRed = 30;
  this->m_vColorEntries[21].m_iGreen = 80;
  this->m_vColorEntries[21].m_iBlue = 0;
  this->m_vHiColorEntry[21] = 0;
  this->m_vColorEntries[64].m_iRed = 100;
  this->m_vColorEntries[64].m_iGreen = 70;
  this->m_vColorEntries[64].m_iBlue = 0;
  this->m_vHiColorEntry[64] = 0;
  this->m_vColorEntries[65].m_iRed = 80;
  this->m_vColorEntries[65].m_iGreen = 70;
  this->m_vColorEntries[65].m_iBlue = 0;
  this->m_vHiColorEntry[65] = 0;
  this->m_vColorEntries[20].m_iRed = 50;
  this->m_vColorEntries[20].m_iGreen = 80;
  this->m_vColorEntries[20].m_iBlue = 0;
  this->m_vHiColorEntry[20] = 0;
  this->m_vColorEntries[144].m_iRed = 40;
  this->m_vColorEntries[144].m_iGreen = 25;
  this->m_vColorEntries[144].m_iBlue = 55;
  this->m_vHiColorEntry[144] = 0;
  this->m_vColorEntries[145].m_iRed = 30;
  this->m_vColorEntries[145].m_iGreen = 45;
  this->m_vColorEntries[145].m_iBlue = 50;
  this->m_vHiColorEntry[145] = 0;
  this->m_vColorEntries[23].m_iRed = 20;
  this->m_vColorEntries[23].m_iGreen = 70;
  this->m_vColorEntries[23].m_iBlue = 40;
  this->m_vHiColorEntry[23] = 0;
  qmemcpy(&this->m_vColorEntries[96], "2Fd2Pd<Fd22d", 12);
  this->m_vHiColorEntry[96] = 0;
  this->m_vHiColorEntry[97] = 0;
  this->m_vHiColorEntry[98] = 0;
  this->m_vHiColorEntry[99] = 0;
  this->m_vColorEntries[28].m_iRed = 98;
  this->m_vColorEntries[28].m_iGreen = 90;
  this->m_vColorEntries[28].m_iBlue = 90;
  this->m_vHiColorEntry[28] = 0;
  this->m_vColorEntries[29].m_iRed = 70;
  this->m_vColorEntries[29].m_iGreen = 60;
  this->m_vColorEntries[29].m_iBlue = 60;
  this->m_vHiColorEntry[29] = 0;
  for ( i = 0;
        i < 256;
        ++i )
  {
    this->m_vHiColorEntry[i] = (unsigned __int8)(int)(float)((float)this->m_vColorEntries[i].m_iBlue * 0.12156863) + 32 * (unsigned __int8)(int)(float)((float)this->m_vColorEntries[i].m_iGreen * 0.12156863) + ((unsigned __int8)(int)(float)((float)this->m_vColorEntries[i].m_iRed * 0.12156863) << 10);
  }
  return this;
}


// address=[0x2f8eab0]
// Decompiled from CLandscapeColorProperties::SColorEntry *__thiscall CLandscapeColorProperties::ColorEntry(CLandscapeColorProperties *this, int a2)
struct CLandscapeColorProperties::SColorEntry const &  CLandscapeColorProperties::ColorEntry(int a2)const {
  
  return &this->m_vColorEntries[a2];
}


// address=[0x2fc5290]
// Decompiled from __int16 __thiscall CLandscapeColorProperties::HiColValue(CLandscapeColorProperties *this, int a2)
unsigned short  CLandscapeColorProperties::HiColValue(int a2)const {
  
  return this->m_vHiColorEntry[a2];
}


