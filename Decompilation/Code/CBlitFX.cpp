#include "CBlitFX.h"

// Definitions for class CBlitFX

// address=[0x2f69900]
// Decompiled from CBlitFX *__thiscall CBlitFX::GetBlitStructPtr(CBlitFX *this)
struct _DDBLTFX *  CBlitFX::GetBlitStructPtr(void) {
  
  return this;
}


// address=[0x2f86400]
// Decompiled from CBlitFX *__thiscall CBlitFX::CBlitFX(CBlitFX *this)
 CBlitFX::CBlitFX(void) {
  
  j__memset(this, 0, 0x64u);
  *(_DWORD *)this = 100;
  return this;
}


// address=[0x2f86430]
// Decompiled from CBlitFX *__thiscall CBlitFX::SetFillColor(CBlitFX *this, int a2, int a3, int a4, bool a5)
void  CBlitFX::SetFillColor(int,int,int,bool) {
  
  int v5; // edx
  CBlitFX *result; // eax

  if ( a5 )
    v5 = 32 * (unsigned __int16)(int)(float)((float)a3 * 0.12156863)
       + ((unsigned __int16)(int)(float)((float)a2 * 0.12156863) << 10);
  else
    v5 = 32 * (unsigned __int16)(int)(float)((float)a3 * 0.24705882)
       + ((unsigned __int16)(int)(float)((float)a2 * 0.12156863) << 11);
  result = this;
  *((_DWORD *)this + 20) = (unsigned __int16)(int)(float)((float)a4 * 0.12156863) + v5;
  return result;
}


// address=[0x2f864e0]
// Decompiled from int __thiscall CBlitFX::SetFillColorAlpha(CBlitFX *this, int a2, int a3, int a4, int a5)
void  CBlitFX::SetFillColorAlpha(int,int,int,int) {
  
  int result; // eax

  result = (unsigned __int16)(int)(float)((float)a4 * 0.05882353);
  *((_DWORD *)this + 20) = result
                         + 16 * (unsigned __int16)(int)(float)((float)a3 * 0.05882353)
                         + ((unsigned __int16)(int)(float)((float)a2 * 0.05882353) << 8)
                         + ((unsigned __int16)(int)(float)((float)a5 * 0.05882353) << 12);
  return result;
}


