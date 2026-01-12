#include "CColorGradient.h"

// Definitions for class CColorGradient

// address=[0x2f6ff70]
// Decompiled from int __thiscall CColorGradient::SetupGradients(_WORD *this, int a2, int a3, int a4, int a5, int a6)
void  CColorGradient::SetupGradients(int,struct SGfxColor,int) {
  
  int result; // eax
  int i; // [esp+8h] [ebp-1Ch]
  int k; // [esp+Ch] [ebp-18h]
  int j; // [esp+10h] [ebp-14h]

  result = a6;
  if ( a6 )
  {
    if ( a6 == 1 )
    {
      for ( i = 31; i >= 0; --i )
      {
        this[32 * a2 + i] = (int)(float)((float)a5 * 0.12156863)
                          + 32 * (int)(float)((float)a4 * 0.12156863)
                          + ((unsigned __int16)(int)(float)((float)a3 * 0.12156863) << 10);
        a3 -= 8;
        a5 -= 8;
        result = a4 - 8;
        a4 -= 8;
        if ( a3 < 0 )
          a3 = 0;
        if ( a4 < 0 )
          a4 = 0;
        if ( a5 < 0 )
          a5 = 0;
      }
    }
    else if ( a6 == 2 )
    {
      for ( j = 31; j >= 0; --j )
      {
        this[32 * a2 + j] = (int)(float)((float)a5 * 0.05882353)
                          + ((unsigned __int16)(int)(float)((float)a3 * 0.05882353) << 8)
                          + 16 * (int)(float)((float)a4 * 0.05882353)
                          - 4096;
        result = a3 - 8;
        a3 -= 8;
        a5 -= 8;
        a4 -= 8;
        if ( a3 < 0 )
          a3 = 0;
        if ( a4 < 0 )
          a4 = 0;
        if ( a5 < 0 )
          a5 = 0;
      }
    }
  }
  else
  {
    for ( k = 31; k >= 0; --k )
    {
      this[32 * a2 + k] = (int)(float)((float)a5 * 0.12156863)
                        + 32 * (int)(float)((float)a4 * 0.24705882)
                        + ((unsigned __int16)(int)(float)((float)a3 * 0.12156863) << 11);
      a3 -= 8;
      a5 -= 8;
      a4 -= 8;
      if ( a3 < 0 )
        a3 = 0;
      if ( a4 < 0 )
        a4 = 0;
      if ( a5 < 0 )
        a5 = 0;
      result = k - 1;
    }
  }
  return result;
}


// address=[0x2f71c10]
// Decompiled from CColorGradient *__thiscall CColorGradient::CColorGradient(CColorGradient *this)
 CColorGradient::CColorGradient(void) {
  
  j__memcpy((char *)this + 524, &unk_3ACC190, 0x6Cu);
  return this;
}


