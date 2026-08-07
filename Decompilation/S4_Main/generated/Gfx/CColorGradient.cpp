#include "CColorGradient.h"

// Definitions for class CColorGradient

// address=[0x2f6ff70]
// Decompiled from void __thiscall CColorGradient::SetupGradients(CColorGradient *this, int a2, struct SGfxColor a3, int a6)
void  CColorGradient::SetupGradients(int a2, struct SGfxColor a3, int a4) {
  
  int i; // [esp+8h] [ebp-1Ch]
  int k; // [esp+Ch] [ebp-18h]
  int j; // [esp+10h] [ebp-14h]
  int m_iB; // [esp+18h] [ebp-Ch]
  int m_iG; // [esp+1Ch] [ebp-8h]

  m_iG = a3.m_iG;
  m_iB = a3.m_iB;
  if ( a6 )
  {
    if ( a6 == 1 )
    {
      for ( i = 31;
            i >= 0;
            --i )
      {
        *(_WORD *)&this->m_vGradients[a2][2 * i] = (int)(float)((float)m_iB * 0.12156863) + 32 * (int)(float)((float)m_iG * 0.12156863) + ((unsigned __int16)(int)(float)((float)a3.m_iR * 0.12156863) << 10);
        a3.m_iR -= 8;
        m_iB -= 8;
        m_iG -= 8;
        if ( a3.m_iR < 0 )
        {
          a3.m_iR = 0;
        }
        if ( m_iG < 0 )
        {
          m_iG = 0;
        }
        if ( m_iB < 0 )
        {
          m_iB = 0;
        }
      }
    }
    else if ( a6 == 2 )
    {
      for ( j = 31;
            j >= 0;
            --j )
      {
        *(_WORD *)&this->m_vGradients[a2][2 * j] = (int)(float)((float)m_iB * 0.05882353) + ((unsigned __int16)(int)(float)((float)a3.m_iR * 0.05882353) << 8) + 16 * (int)(float)((float)m_iG * 0.05882353) - 4096;
        a3.m_iR -= 8;
        m_iB -= 8;
        m_iG -= 8;
        if ( a3.m_iR < 0 )
        {
          a3.m_iR = 0;
        }
        if ( m_iG < 0 )
        {
          m_iG = 0;
        }
        if ( m_iB < 0 )
        {
          m_iB = 0;
        }
      }
    }
  }
  else
  {
    for ( k = 31;
          k >= 0;
          --k )
    {
      *(_WORD *)&this->m_vGradients[a2][2 * k] = (int)(float)((float)m_iB * 0.12156863) + 32 * (int)(float)((float)m_iG * 0.24705882) + ((unsigned __int16)(int)(float)((float)a3.m_iR * 0.12156863) << 11);
      a3.m_iR -= 8;
      m_iB -= 8;
      m_iG -= 8;
      if ( a3.m_iR < 0 )
      {
        a3.m_iR = 0;
      }
      if ( m_iG < 0 )
      {
        m_iG = 0;
      }
      if ( m_iB < 0 )
      {
        m_iB = 0;
      }
    }
  }
}


// address=[0x2f71c10]
// Decompiled from CColorGradient *__thiscall CColorGradient::CColorGradient(CColorGradient *this)
 CColorGradient::CColorGradient(void) {
  
  memcpy(&this->m_vPlayerColors[1], s_vOverrideColorGradient, 108u);// Not the correct size!
  return this;
}


