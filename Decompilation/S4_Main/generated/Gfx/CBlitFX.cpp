#if FALSE
#include "CBlitFX.h"

// Definitions for class CBlitFX

// address=[0x2f69900]
// Decompiled from _DDBLTFX *__thiscall CBlitFX::GetBlitStructPtr(CBlitFX *this)
struct _DDBLTFX *  CBlitFX::GetBlitStructPtr(void) {
  
  return &this->m_sBlitFX;
}


// address=[0x2f86400]
// Decompiled from CBlitFX *__thiscall CBlitFX::CBlitFX(CBlitFX *this)
 CBlitFX::CBlitFX(void) {
  
  memset(this, 0, sizeof(CBlitFX));
  this->m_sBlitFX.dwSize = 100;
  return this;
}


// address=[0x2f86430]
// Decompiled from void __thiscall CBlitFX::SetFillColor(CBlitFX *this, int _iRed, int _iGreen, int _iBlue, bool _bIs555)
void  CBlitFX::SetFillColor(int _iRed, int _iGreen, int _iBlue, bool _bIs555) {
  
  int v5; // edx

  if ( _bIs555 )
  {
    v5 = 32 * (unsigned __int16)(int)(float)((float)_iGreen * 0.12156863) + ((unsigned __int16)(int)(float)((float)_iRed * 0.12156863) << 10);
  }
  else
  {
    v5 = 32 * (unsigned __int16)(int)(float)((float)_iGreen * 0.24705882) + ((unsigned __int16)(int)(float)((float)_iRed * 0.12156863) << 11);
  }
  this->m_sBlitFX.dwFillColor = (unsigned __int16)(int)(float)((float)_iBlue * 0.12156863) + v5;
}


// address=[0x2f864e0]
// Decompiled from void __thiscall CBlitFX::SetFillColorAlpha(CBlitFX *this, int a2, int a3, int a4, int a5)
void  CBlitFX::SetFillColorAlpha(int a2, int a3, int a4, int a5) {
  
  this->m_sBlitFX.dwFillColor = (unsigned __int16)(int)(float)((float)a4 * 0.05882353) + 16 * (unsigned __int16)(int)(float)((float)a3 * 0.05882353) + ((unsigned __int16)(int)(float)((float)a2 * 0.05882353) << 8) + ((unsigned __int16)(int)(float)((float)a5 * 0.05882353) << 12);
}


#endif // Already implemented
