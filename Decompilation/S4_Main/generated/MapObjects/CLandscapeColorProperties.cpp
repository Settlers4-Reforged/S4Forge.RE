#include "CLandscapeColorProperties.h"

// Definitions for class CLandscapeColorProperties

// address=[0x2f8dcb0]
// Decompiled from CLandscapeColorProperties *__thiscall CLandscapeColorProperties::CLandscapeColorProperties(CLandscapeColorProperties *this)
 CLandscapeColorProperties::CLandscapeColorProperties(void) {
  
  int i; // [esp+10h] [ebp-Ch]

  this->m_vColorEntries[16].uRed = 0;
  this->m_vColorEntries[16].uGreen = 100;
  this->m_vColorEntries[16].uBlue = 0;
  this->m_vHiColorEntry[16] = 0;
  this->m_vColorEntries[0].uRed = 0;
  this->m_vColorEntries[0].uGreen = 85;
  this->m_vColorEntries[0].uBlue = 110;
  this->m_vHiColorEntry[0] = 0;
  this->m_vColorEntries[1].uRed = 0;
  this->m_vColorEntries[1].uGreen = 76;
  this->m_vColorEntries[1].uBlue = 101;
  this->m_vHiColorEntry[1] = 0;
  this->m_vColorEntries[2].uRed = 0;
  this->m_vColorEntries[2].uGreen = 67;
  this->m_vColorEntries[2].uBlue = 92;
  this->m_vHiColorEntry[2] = 0;
  this->m_vColorEntries[3].uRed = 0;
  this->m_vColorEntries[3].uGreen = 58;
  this->m_vColorEntries[3].uBlue = 83;
  this->m_vHiColorEntry[3] = 0;
  this->m_vColorEntries[4].uRed = 0;
  this->m_vColorEntries[4].uGreen = 49;
  this->m_vColorEntries[4].uBlue = 74;
  this->m_vHiColorEntry[4] = 0;
  this->m_vColorEntries[5].uRed = 0;
  this->m_vColorEntries[5].uGreen = 40;
  this->m_vColorEntries[5].uBlue = 65;
  this->m_vHiColorEntry[5] = 0;
  this->m_vColorEntries[6].uRed = 0;
  this->m_vColorEntries[6].uGreen = 31;
  this->m_vColorEntries[6].uBlue = 54;
  this->m_vHiColorEntry[6] = 0;
  this->m_vColorEntries[7].uRed = 0;
  this->m_vColorEntries[7].uGreen = 22;
  this->m_vColorEntries[7].uBlue = 47;
  this->m_vHiColorEntry[7] = 0;
  this->m_vColorEntries[48].uRed = 100;
  this->m_vColorEntries[48].uGreen = 90;
  this->m_vColorEntries[48].uBlue = 50;
  this->m_vHiColorEntry[48] = 0;
  this->m_vColorEntries[8].uRed = 100;
  this->m_vColorEntries[8].uGreen = 90;
  this->m_vColorEntries[8].uBlue = 50;
  this->m_vHiColorEntry[8] = 0;
  this->m_vColorEntries[32].uRed = 40;
  this->m_vColorEntries[32].uGreen = 40;
  this->m_vColorEntries[32].uBlue = 30;
  this->m_vHiColorEntry[32] = 0;
  this->m_vColorEntries[17].uRed = 10;
  this->m_vColorEntries[17].uGreen = 80;
  this->m_vColorEntries[17].uBlue = 10;
  this->m_vHiColorEntry[17] = 0;
  this->m_vColorEntries[33].uRed = 20;
  this->m_vColorEntries[33].uGreen = 60;
  this->m_vColorEntries[33].uBlue = 20;
  this->m_vHiColorEntry[33] = 0;
  this->m_vColorEntries[129].uRed = 76;
  this->m_vColorEntries[129].uGreen = 80;
  this->m_vColorEntries[129].uBlue = 82;
  this->m_vHiColorEntry[129] = 0;
  this->m_vColorEntries[35].uRed = 65;
  this->m_vColorEntries[35].uGreen = 70;
  this->m_vColorEntries[35].uBlue = 65;
  this->m_vHiColorEntry[35] = 0;
  this->m_vColorEntries[24].uRed = 40;
  this->m_vColorEntries[24].uGreen = 80;
  this->m_vColorEntries[24].uBlue = 20;
  this->m_vHiColorEntry[24] = 0;
  this->m_vColorEntries[25].uRed = 60;
  this->m_vColorEntries[25].uGreen = 100;
  this->m_vColorEntries[25].uBlue = 30;
  this->m_vHiColorEntry[25] = 0;
  this->m_vColorEntries[18].uRed = 30;
  this->m_vColorEntries[18].uGreen = 100;
  this->m_vColorEntries[18].uBlue = 70;
  this->m_vHiColorEntry[18] = 0;
  this->m_vColorEntries[128].uRed = 88;
  this->m_vColorEntries[128].uGreen = 92;
  this->m_vColorEntries[128].uBlue = 98;
  this->m_vHiColorEntry[128] = 0;
  this->m_vColorEntries[80].uRed = 60;
  this->m_vColorEntries[80].uGreen = 0;
  this->m_vColorEntries[80].uBlue = 0;
  this->m_vHiColorEntry[80] = 0;
  this->m_vColorEntries[81].uRed = 40;
  this->m_vColorEntries[81].uGreen = 50;
  this->m_vColorEntries[81].uBlue = 0;
  this->m_vHiColorEntry[81] = 0;
  this->m_vColorEntries[21].uRed = 30;
  this->m_vColorEntries[21].uGreen = 80;
  this->m_vColorEntries[21].uBlue = 0;
  this->m_vHiColorEntry[21] = 0;
  this->m_vColorEntries[64].uRed = 100;
  this->m_vColorEntries[64].uGreen = 70;
  this->m_vColorEntries[64].uBlue = 0;
  this->m_vHiColorEntry[64] = 0;
  this->m_vColorEntries[65].uRed = 80;
  this->m_vColorEntries[65].uGreen = 70;
  this->m_vColorEntries[65].uBlue = 0;
  this->m_vHiColorEntry[65] = 0;
  this->m_vColorEntries[20].uRed = 50;
  this->m_vColorEntries[20].uGreen = 80;
  this->m_vColorEntries[20].uBlue = 0;
  this->m_vHiColorEntry[20] = 0;
  this->m_vColorEntries[144].uRed = 40;
  this->m_vColorEntries[144].uGreen = 25;
  this->m_vColorEntries[144].uBlue = 55;
  this->m_vHiColorEntry[144] = 0;
  this->m_vColorEntries[145].uRed = 30;
  this->m_vColorEntries[145].uGreen = 45;
  this->m_vColorEntries[145].uBlue = 50;
  this->m_vHiColorEntry[145] = 0;
  this->m_vColorEntries[23].uRed = 20;
  this->m_vColorEntries[23].uGreen = 70;
  this->m_vColorEntries[23].uBlue = 40;
  this->m_vHiColorEntry[23] = 0;
  qmemcpy(&this->m_vColorEntries[96], "2Fd2Pd<Fd22d", 12);
  this->m_vHiColorEntry[96] = 0;
  this->m_vHiColorEntry[97] = 0;
  this->m_vHiColorEntry[98] = 0;
  this->m_vHiColorEntry[99] = 0;
  this->m_vColorEntries[28].uRed = 98;
  this->m_vColorEntries[28].uGreen = 90;
  this->m_vColorEntries[28].uBlue = 90;
  this->m_vHiColorEntry[28] = 0;
  this->m_vColorEntries[29].uRed = 70;
  this->m_vColorEntries[29].uGreen = 60;
  this->m_vColorEntries[29].uBlue = 60;
  this->m_vHiColorEntry[29] = 0;
  for ( i = 0;
        i < 256;
        ++i )
  {
    this->m_vHiColorEntry[i] = (unsigned __int8)(int)(float)((float)this->m_vColorEntries[i].uBlue * 0.12156863) + 32 * (unsigned __int8)(int)(float)((float)this->m_vColorEntries[i].uGreen * 0.12156863) + ((unsigned __int8)(int)(float)((float)this->m_vColorEntries[i].uRed * 0.12156863) << 10);
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


