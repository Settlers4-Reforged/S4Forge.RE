#include "CHexIndices.h"

// Definitions for class CHexIndices

// address=[0x2fcabb0]
// Decompiled from CHexIndices *__thiscall CHexIndices::CHexIndices(CHexIndices *this)
 CHexIndices::CHexIndices(void) {
  
  _DWORD v3[6000]; // [esp+4h] [ebp-5DC4h] BYREF

  CHexIndices::SetFirst(this);
  *(_WORD *)this = 0;
  *((_WORD *)this + 1) = 0;
  *((_DWORD *)this + 8002) = 0;
  *((_DWORD *)this + 8006) = 1;
  *((_DWORD *)this + 8007) = 0;
  while ( *((_DWORD *)this + 8002) != 2000 )
  {
    v3[3 * *((_DWORD *)this + 8002) + 1] = *((_DWORD *)this + 8006);
    v3[3 * *((_DWORD *)this + 8002) + 2] = *((_DWORD *)this + 8007);
    v3[3 * (*((_DWORD *)this + 8002))++] = 87 * *((_DWORD *)this + 8007) * 87 * *((_DWORD *)this + 8007)
                                         + (100 * *((_DWORD *)this + 8006) - 50 * *((_DWORD *)this + 8007))
                                         * (100 * *((_DWORD *)this + 8006) - 50 * *((_DWORD *)this + 8007));
    if ( ++*((_DWORD *)this + 8007) == *((_DWORD *)this + 8006) )
    {
      *((_DWORD *)this + 8007) = 0;
      ++*((_DWORD *)this + 8006);
    }
  }
  for ( *((_DWORD *)this + 8002) = 1; *((int *)this + 8002) < 7995; *((_DWORD *)this + 8002) += 6 )
  {
    *((_DWORD *)this + 8003) = 0x7FFFFFFF;
    for ( *((_DWORD *)this + 8006) = 0; *((int *)this + 8006) < 2000; ++*((_DWORD *)this + 8006) )
    {
      if ( v3[3 * *((_DWORD *)this + 8006)] < *((_DWORD *)this + 8003) )
      {
        *((_DWORD *)this + 8003) = v3[3 * *((_DWORD *)this + 8006)];
        *((_DWORD *)this + 8007) = *((_DWORD *)this + 8006);
      }
    }
    v3[3 * *((_DWORD *)this + 8007)] = 0x7FFFFFFF;
    *((_DWORD *)this + 8004) = v3[3 * *((_DWORD *)this + 8007) + 1];
    *((_DWORD *)this + 8005) = v3[3 * *((_DWORD *)this + 8007) + 2];
    *((_WORD *)this + 2 * *((_DWORD *)this + 8002)) = *((_WORD *)this + 16008);
    *((_WORD *)this + 2 * *((_DWORD *)this + 8002) + 1) = *((_WORD *)this + 16010);
    *((_WORD *)this + 2 * *((_DWORD *)this + 8002) + 2) = *((_WORD *)this + 16008) - *((_WORD *)this + 16010);
    *((_WORD *)this + 2 * *((_DWORD *)this + 8002) + 3) = *((_WORD *)this + 16008);
    *((_WORD *)this + 2 * *((_DWORD *)this + 8002) + 4) = -*((_WORD *)this + 16010);
    *((_WORD *)this + 2 * *((_DWORD *)this + 8002) + 5) = *((_WORD *)this + 16008) - *((_WORD *)this + 16010);
    *((_WORD *)this + 2 * *((_DWORD *)this + 8002) + 6) = -*((_WORD *)this + 16008);
    *((_WORD *)this + 2 * *((_DWORD *)this + 8002) + 7) = -*((_WORD *)this + 16010);
    *((_WORD *)this + 2 * *((_DWORD *)this + 8002) + 8) = *((_WORD *)this + 16010) - *((_WORD *)this + 16008);
    *((_WORD *)this + 2 * *((_DWORD *)this + 8002) + 9) = -*((_WORD *)this + 16008);
    *((_WORD *)this + 2 * *((_DWORD *)this + 8002) + 10) = *((_WORD *)this + 16010);
    *((_WORD *)this + 2 * *((_DWORD *)this + 8002) + 11) = *((_WORD *)this + 16010) - *((_WORD *)this + 16008);
  }
  return this;
}


// address=[0x2fcb110]
// Decompiled from CHexIndices *__thiscall CHexIndices::SetFirst(CHexIndices *this)
void  CHexIndices::SetFirst(void) {
  
  CHexIndices *result; // eax

  result = this;
  *((_DWORD *)this + 8000) = 0;
  *((_DWORD *)this + 8001) = 0;
  return result;
}


// address=[0x2fcb140]
// Decompiled from int __thiscall CHexIndices::GetIndex(CHexIndices *this)
int  CHexIndices::GetIndex(void) {
  
  if ( *((_DWORD *)this + 8001) )
  {
    *((_DWORD *)this + 8001) = 0;
    return *((__int16 *)this + 2 * (*((_DWORD *)this + 8000))++ + 1);
  }
  else
  {
    *((_DWORD *)this + 8001) = *((_DWORD *)this + 8001) == 0;
    return *((__int16 *)this + 2 * *((_DWORD *)this + 8000));
  }
}


