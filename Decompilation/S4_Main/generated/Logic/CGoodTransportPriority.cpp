#include "CGoodTransportPriority.h"

// Definitions for class CGoodTransportPriority

// address=[0x1400d60]
// Decompiled from int __cdecl CGoodTransportPriority::New(int a1)
class CPersistence * __cdecl CGoodTransportPriority::New(std::istream & a1) {
  
  if ( operator new(0x64u) )
    return CGoodTransportPriority::CGoodTransportPriority(a1);
  else
    return 0;
}


// address=[0x1439ae0]
// Decompiled from int __thiscall CGoodTransportPriority::GetNumberOfPriorities(CGoodTransportPriority *this)
int  CGoodTransportPriority::GetNumberOfPriorities(void) {
  
  return *((_DWORD *)this + 23);
}


// address=[0x1439b40]
// Decompiled from int __thiscall CGoodTransportPriority::GetPriority(unsigned __int16 *this, int a2)
int  CGoodTransportPriority::GetPriority(enum PILE_TYPES a2) {
  
  if ( (a2 <= 0 || a2 >= 43)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\logic\\GoodTransportPriority.h",
         195,
         "_iGoodType > GOOD_NO_GOOD && _iGoodType< GOOD_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a2 <= 0 || a2 >= 43 )
    return -1;
  else
    return this[a2 + 2];
}


// address=[0x1452ac0]
// Decompiled from _DWORD *__thiscall CGoodTransportPriority::CGoodTransportPriority(_DWORD *this, int a2)
 CGoodTransportPriority::CGoodTransportPriority(std::istream & a2) {
  
  _BYTE v3[4]; // [esp+0h] [ebp-14h] BYREF
  int v4; // [esp+4h] [ebp-10h]
  int v5; // [esp+8h] [ebp-Ch] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-8h] BYREF
  _DWORD *v7; // [esp+10h] [ebp-4h]

  v7 = this;
  CPersistence::CPersistence(this);
  *v7 = &CGoodTransportPriority::_vftable_;
  operator^<unsigned long>(a2, v3);
  operator^<unsigned int>(a2, &v5);
  v4 = v5;
  if ( v5 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect CGoodTransportPriority::CGoodTransportPriority");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<bool>(a2, v7 + 24);
  operator^<int>(a2, (int)(v7 + 23));
  LoadArray<unsigned short>(a2, v7 + 1, 86);
  return v7;
}


// address=[0x1452b80]
// Decompiled from int __thiscall CGoodTransportPriority::Store(struct CPersistence *this, struct std::ostream *a2)
void  CGoodTransportPriority::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  struct CPersistence *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  CPersistence::Store(this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  operator^<bool>((int)a2, (int)v4 + 96);
  operator^<int>((int)a2, (int *)v4 + 23);
  return StoreArray<unsigned short>(a2, (char *)v4 + 4, 86);
}


// address=[0x1452bf0]
// Decompiled from CGoodTransportPriority *__thiscall CGoodTransportPriority::CGoodTransportPriority(  CGoodTransportPriority *this,  unsigned __int8 a2)
 CGoodTransportPriority::CGoodTransportPriority(unsigned char) {
  
  CPersistence::CPersistence(this);
  *(_DWORD *)this = &CGoodTransportPriority::_vftable_;
  switch ( a2 )
  {
    case 0u:
      CGoodTransportPriority::CreateRomanPriorities(this);
      break;
    case 1u:
      CGoodTransportPriority::CreateVikingPriorities(this);
      break;
    case 2u:
      CGoodTransportPriority::CreateMayaPriorities(this);
      break;
    case 4u:
      CGoodTransportPriority::CreateTrojanPriorities(this);
      break;
    default:
      break;
  }
  *((_BYTE *)this + 96) = 1;
  return this;
}


// address=[0x1452c70]
// Decompiled from int __thiscall CGoodTransportPriority::ChangePriority(_WORD *this, int a2, int a3)
void  CGoodTransportPriority::ChangePriority(enum PILE_TYPES a2, int a3) {
  
  int result; // eax
  int v4; // [esp+8h] [ebp-14h]
  int j; // [esp+Ch] [ebp-10h]
  int i; // [esp+10h] [ebp-Ch]
  int k; // [esp+14h] [ebp-8h]

  if ( (a2 <= 0 || a2 >= 43)
    && BBSupportDbgReport(
         2,
         "Logic\\GoodTransportPriority.cpp",
         109,
         "_iGoodType > GOOD_NO_GOOD && _iGoodType< GOOD_MAX") == 1 )
  {
    __debugbreak();
  }
  result = 0;
  if ( a2 <= 0 || a2 >= 43 )
    return result;
  if ( a3 == 100 )
  {
    for ( i = 0; i < 43; ++i )
    {
      if ( (unsigned __int16)this[i + 2] > (int)(unsigned __int16)this[a2 + 2] )
        --this[i + 2];
    }
    result = (int)this;
    this[a2 + 2] = this[46];
  }
  else if ( a3 )
  {
    result = a2;
    v4 = -1;
    for ( j = 0; j < 43 && v4 == -1; ++j )
    {
      if ( (unsigned __int16)this[j + 2] == a3 + (unsigned __int16)this[a2 + 2] )
        v4 = j;
      result = j + 1;
    }
    if ( v4 > 0 )
    {
      this[v4 + 2] = this[a2 + 2];
      result = (int)this;
      this[a2 + 2] += a3;
    }
  }
  else
  {
    for ( k = 0; k < 43; ++k )
    {
      if ( this[k + 2] && (unsigned __int16)this[k + 2] < (int)(unsigned __int16)this[a2 + 2] )
        ++this[k + 2];
    }
    result = 1;
    this[a2 + 2] = 1;
  }
  return result;
}


// address=[0x1452e30]
// Decompiled from CGoodTransportPriority *__thiscall CGoodTransportPriority::GetSortedGoods(CGoodTransportPriority *this, int *const a2)
void  CGoodTransportPriority::GetSortedGoods(int * const a2) {
  
  CGoodTransportPriority *result; // eax
  int v3; // [esp+4h] [ebp-18h]
  int v4; // [esp+8h] [ebp-14h]
  int i; // [esp+Ch] [ebp-10h]
  int v6; // [esp+10h] [ebp-Ch]
  int j; // [esp+18h] [ebp-4h]

  if ( !*((_BYTE *)this + 96) && BBSupportDbgReport(2, "Logic\\GoodTransportPriority.cpp", 78, "m_bIsInit") == 1 )
    __debugbreak();
  if ( !*((_DWORD *)this + 23)
    && BBSupportDbgReport(2, "Logic\\GoodTransportPriority.cpp", 79, "m_iNumberOfPriorities!= 0") == 1 )
  {
    __debugbreak();
  }
  v3 = 0;
  for ( i = 0; ; ++i )
  {
    result = this;
    if ( i >= *((_DWORD *)this + 23) )
      break;
    v6 = -1;
    v4 = 0xFFFF;
    for ( j = 0; j < 43; ++j )
    {
      if ( *((unsigned __int16 *)this + j + 2) > v3 && *((unsigned __int16 *)this + j + 2) <= v4 )
      {
        v4 = *((unsigned __int16 *)this + j + 2);
        v6 = j;
      }
    }
    if ( v6 >= 0 )
    {
      a2[i] = v6;
      v3 = *((unsigned __int16 *)this + v6 + 2);
    }
  }
  return result;
}


// address=[0x1454260]
// Decompiled from int __thiscall CGoodTransportPriority::ClassID(CGoodTransportPriority *this)
unsigned long  CGoodTransportPriority::ClassID(void)const {
  
  return CGoodTransportPriority::m_iClassID;
}


// address=[0x3d895f0]
// [Decompilation failed for static unsigned long CGoodTransportPriority::m_iClassID]

// address=[0x1452f50]
// Decompiled from int __thiscall CGoodTransportPriority::CreateRomanPriorities(CGoodTransportPriority *this)
void  CGoodTransportPriority::CreateRomanPriorities(void) {
  
  int result; // eax

  memset((char *)this + 4, 0, 0x56u);
  *((_WORD *)this + 4) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_AMMO);
  *((_WORD *)this + 5) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_ARMOR);
  *((_WORD *)this + 6) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_AXE);
  *((_WORD *)this + 9) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_BOARD);
  *((_WORD *)this + 10) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_BOW);
  *((_WORD *)this + 11) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_BREAD);
  *((_WORD *)this + 12) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_COAL);
  *((_WORD *)this + 13) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_FISH);
  *((_WORD *)this + 14) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_FLOUR);
  *((_WORD *)this + 16) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_GOLDBAR);
  *((_WORD *)this + 17) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_GOLDORE);
  *((_WORD *)this + 18) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_GRAIN);
  *((_WORD *)this + 20) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_HAMMER);
  *((_WORD *)this + 22) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_IRONBAR);
  *((_WORD *)this + 23) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_IRONORE);
  *((_WORD *)this + 24) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_LOG);
  *((_WORD *)this + 26) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_MEAT);
  *((_WORD *)this + 27) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_PICKAXE);
  *((_WORD *)this + 29) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_ROD);
  *((_WORD *)this + 30) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_SAW);
  *((_WORD *)this + 31) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_SCYTHE);
  *((_WORD *)this + 32) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_SHEEP);
  *((_WORD *)this + 33) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_SHOVEL);
  *((_WORD *)this + 34) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_STONE);
  *((_WORD *)this + 35) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_SULFUR);
  *((_WORD *)this + 36) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_SWORD);
  *((_WORD *)this + 38) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_WATER);
  result = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_ROMAN_TP_WINE);
  *((_WORD *)this + 39) = result;
  *((_DWORD *)this + 23) = 28;
  return result;
}


// address=[0x1453250]
// Decompiled from int __thiscall CGoodTransportPriority::CreateVikingPriorities(CGoodTransportPriority *this)
void  CGoodTransportPriority::CreateVikingPriorities(void) {
  
  int result; // eax

  memset((char *)this + 4, 0, 0x56u);
  *((_WORD *)this + 5) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_ARMOR);
  *((_WORD *)this + 6) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_AXE);
  *((_WORD *)this + 7) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_BATTLEAXE);
  *((_WORD *)this + 9) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_BOARD);
  *((_WORD *)this + 10) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_BOW);
  *((_WORD *)this + 11) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_BREAD);
  *((_WORD *)this + 12) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_COAL);
  *((_WORD *)this + 13) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_FISH);
  *((_WORD *)this + 14) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_FLOUR);
  *((_WORD *)this + 16) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_GOLDBAR);
  *((_WORD *)this + 17) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_GOLDORE);
  *((_WORD *)this + 18) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_GRAIN);
  *((_WORD *)this + 20) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_HAMMER);
  *((_WORD *)this + 21) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_HONEY);
  *((_WORD *)this + 22) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_IRONBAR);
  *((_WORD *)this + 23) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_IRONORE);
  *((_WORD *)this + 24) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_LOG);
  *((_WORD *)this + 25) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_MEAD);
  *((_WORD *)this + 26) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_MEAT);
  *((_WORD *)this + 27) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_PICKAXE);
  *((_WORD *)this + 28) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_PIG);
  *((_WORD *)this + 29) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_ROD);
  *((_WORD *)this + 30) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_SAW);
  *((_WORD *)this + 31) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_SCYTHE);
  *((_WORD *)this + 33) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_SHOVEL);
  *((_WORD *)this + 34) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_STONE);
  *((_WORD *)this + 35) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_SULFUR);
  *((_WORD *)this + 36) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_SWORD);
  result = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_VIKING_TP_WATER);
  *((_WORD *)this + 38) = result;
  *((_DWORD *)this + 23) = 29;
  return result;
}


// address=[0x1453570]
// Decompiled from int __thiscall CGoodTransportPriority::CreateMayaPriorities(CGoodTransportPriority *this)
void  CGoodTransportPriority::CreateMayaPriorities(void) {
  
  int result; // eax

  memset((char *)this + 4, 0, 0x56u);
  *((_WORD *)this + 3) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_AGAVE);
  *((_WORD *)this + 5) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_ARMOR);
  *((_WORD *)this + 6) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_AXE);
  *((_WORD *)this + 8) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_BLOWGUN);
  *((_WORD *)this + 9) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_BOARD);
  *((_WORD *)this + 10) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_BOW);
  *((_WORD *)this + 11) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_BREAD);
  *((_WORD *)this + 12) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_COAL);
  *((_WORD *)this + 13) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_FISH);
  *((_WORD *)this + 14) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_FLOUR);
  *((_WORD *)this + 15) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_GOAT);
  *((_WORD *)this + 16) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_GOLDBAR);
  *((_WORD *)this + 17) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_GOLDORE);
  *((_WORD *)this + 18) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_GRAIN);
  *((_WORD *)this + 19) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_GUNPOWDER);
  *((_WORD *)this + 20) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_HAMMER);
  *((_WORD *)this + 22) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_IRONBAR);
  *((_WORD *)this + 23) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_IRONORE);
  *((_WORD *)this + 24) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_LOG);
  *((_WORD *)this + 26) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_MEAT);
  *((_WORD *)this + 27) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_PICKAXE);
  *((_WORD *)this + 29) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_ROD);
  *((_WORD *)this + 30) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_SAW);
  *((_WORD *)this + 31) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_SCYTHE);
  *((_WORD *)this + 33) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_SHOVEL);
  *((_WORD *)this + 34) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_STONE);
  *((_WORD *)this + 35) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_SULFUR);
  *((_WORD *)this + 36) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_SWORD);
  *((_WORD *)this + 37) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_TEQUILA);
  result = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_MAYA_TP_WATER);
  *((_WORD *)this + 38) = result;
  *((_DWORD *)this + 23) = 30;
  return result;
}


// address=[0x14538b0]
// Decompiled from CGoodTransportPriority *__thiscall CGoodTransportPriority::CreateTrojanPriorities(CGoodTransportPriority *this)
void  CGoodTransportPriority::CreateTrojanPriorities(void) {
  
  CGoodTransportPriority *result; // eax

  memset((char *)this + 4, 0, 0x56u);
  *((_WORD *)this + 44) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_SUNFLOWER);
  *((_WORD *)this + 5) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_ARMOR);
  *((_WORD *)this + 6) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_AXE);
  *((_WORD *)this + 40) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_BACKPACKCATAPULT);
  *((_WORD *)this + 9) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_BOARD);
  *((_WORD *)this + 10) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_BOW);
  *((_WORD *)this + 11) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_BREAD);
  *((_WORD *)this + 42) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_EXPLOSIVEARROW);
  *((_WORD *)this + 12) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_COAL);
  *((_WORD *)this + 13) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_FISH);
  *((_WORD *)this + 14) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_FLOUR);
  *((_WORD *)this + 41) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_GOOSE);
  *((_WORD *)this + 16) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_GOLDBAR);
  *((_WORD *)this + 17) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_GOLDORE);
  *((_WORD *)this + 18) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_GRAIN);
  *((_WORD *)this + 20) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_HAMMER);
  *((_WORD *)this + 22) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_IRONBAR);
  *((_WORD *)this + 23) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_IRONORE);
  *((_WORD *)this + 24) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_LOG);
  *((_WORD *)this + 26) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_MEAT);
  *((_WORD *)this + 27) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_PICKAXE);
  *((_WORD *)this + 29) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_ROD);
  *((_WORD *)this + 30) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_SAW);
  *((_WORD *)this + 31) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_SCYTHE);
  *((_WORD *)this + 33) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_SHOVEL);
  *((_WORD *)this + 34) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_STONE);
  *((_WORD *)this + 35) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_SULFUR);
  *((_WORD *)this + 43) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_SUNFLOWEROIL);
  *((_WORD *)this + 36) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_SWORD);
  *((_WORD *)this + 38) = CStaticConfigVarInt::operator int(&CGoodTransportPriority::m_iDefault_TROJAN_TP_WATER);
  result = this;
  *((_DWORD *)this + 23) = 30;
  return result;
}


// address=[0x3f1de00]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_BOARD]

// address=[0x3f1de0c]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_STONE]

// address=[0x3f1de18]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_LOG]

// address=[0x3f1de24]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_IRONBAR]

// address=[0x3f1de30]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_IRONORE]

// address=[0x3f1de3c]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_COAL]

// address=[0x3f1de48]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_BREAD]

// address=[0x3f1de54]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_FISH]

// address=[0x3f1de60]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_MEAT]

// address=[0x3f1de6c]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_FLOUR]

// address=[0x3f1de78]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_GRAIN]

// address=[0x3f1de84]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_SHEEP]

// address=[0x3f1de90]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_WATER]

// address=[0x3f1de9c]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_SWORD]

// address=[0x3f1dea8]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_BOW]

// address=[0x3f1deb4]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_ARMOR]

// address=[0x3f1dec0]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_AMMO]

// address=[0x3f1decc]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_SHOVEL]

// address=[0x3f1ded8]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_HAMMER]

// address=[0x3f1dee4]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_AXE]

// address=[0x3f1def0]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_PICKAXE]

// address=[0x3f1defc]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_SAW]

// address=[0x3f1df08]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_ROD]

// address=[0x3f1df14]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_SCYTHE]

// address=[0x3f1df20]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_GOLDBAR]

// address=[0x3f1df2c]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_GOLDORE]

// address=[0x3f1df38]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_WINE]

// address=[0x3f1df44]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_ROMAN_TP_SULFUR]

// address=[0x3f1df50]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_BOARD]

// address=[0x3f1df5c]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_STONE]

// address=[0x3f1df68]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_LOG]

// address=[0x3f1df74]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_IRONBAR]

// address=[0x3f1df80]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_IRONORE]

// address=[0x3f1df8c]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_COAL]

// address=[0x3f1df98]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_BREAD]

// address=[0x3f1dfa4]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_FISH]

// address=[0x3f1dfb0]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_MEAT]

// address=[0x3f1dfbc]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_FLOUR]

// address=[0x3f1dfc8]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_GRAIN]

// address=[0x3f1dfd4]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_PIG]

// address=[0x3f1dfe0]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_WATER]

// address=[0x3f1dfec]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_SWORD]

// address=[0x3f1dff8]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_BOW]

// address=[0x3f1e004]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_BATTLEAXE]

// address=[0x3f1e010]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_ARMOR]

// address=[0x3f1e01c]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_SHOVEL]

// address=[0x3f1e028]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_HAMMER]

// address=[0x3f1e034]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_AXE]

// address=[0x3f1e040]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_PICKAXE]

// address=[0x3f1e04c]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_SAW]

// address=[0x3f1e058]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_ROD]

// address=[0x3f1e064]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_SCYTHE]

// address=[0x3f1e070]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_GOLDBAR]

// address=[0x3f1e07c]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_GOLDORE]

// address=[0x3f1e088]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_MEAD]

// address=[0x3f1e094]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_HONEY]

// address=[0x3f1e0a0]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_VIKING_TP_SULFUR]

// address=[0x3f1e0ac]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_BOARD]

// address=[0x3f1e0b8]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_STONE]

// address=[0x3f1e0c4]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_LOG]

// address=[0x3f1e0d0]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_IRONBAR]

// address=[0x3f1e0dc]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_IRONORE]

// address=[0x3f1e0e8]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_COAL]

// address=[0x3f1e0f4]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_BREAD]

// address=[0x3f1e100]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_FISH]

// address=[0x3f1e10c]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_MEAT]

// address=[0x3f1e118]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_FLOUR]

// address=[0x3f1e124]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_GRAIN]

// address=[0x3f1e130]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_GOAT]

// address=[0x3f1e13c]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_WATER]

// address=[0x3f1e148]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_SWORD]

// address=[0x3f1e154]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_BOW]

// address=[0x3f1e160]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_BLOWGUN]

// address=[0x3f1e16c]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_ARMOR]

// address=[0x3f1e178]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_GUNPOWDER]

// address=[0x3f1e184]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_SULFUR]

// address=[0x3f1e190]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_SHOVEL]

// address=[0x3f1e19c]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_HAMMER]

// address=[0x3f1e1a8]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_AXE]

// address=[0x3f1e1b4]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_PICKAXE]

// address=[0x3f1e1c0]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_SAW]

// address=[0x3f1e1cc]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_ROD]

// address=[0x3f1e1d8]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_SCYTHE]

// address=[0x3f1e1e4]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_GOLDBAR]

// address=[0x3f1e1f0]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_GOLDORE]

// address=[0x3f1e1fc]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_TEQUILA]

// address=[0x3f1e208]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_MAYA_TP_AGAVE]

// address=[0x3f1e214]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_BOARD]

// address=[0x3f1e220]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_STONE]

// address=[0x3f1e22c]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_LOG]

// address=[0x3f1e238]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_IRONBAR]

// address=[0x3f1e244]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_IRONORE]

// address=[0x3f1e250]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_COAL]

// address=[0x3f1e25c]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_BREAD]

// address=[0x3f1e268]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_FISH]

// address=[0x3f1e274]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_MEAT]

// address=[0x3f1e280]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_FLOUR]

// address=[0x3f1e28c]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_GRAIN]

// address=[0x3f1e298]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_GOOSE]

// address=[0x3f1e2a4]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_WATER]

// address=[0x3f1e2b0]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_SWORD]

// address=[0x3f1e2bc]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_BOW]

// address=[0x3f1e2c8]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_BACKPACKCATAPULT]

// address=[0x3f1e2d4]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_ARMOR]

// address=[0x3f1e2e0]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_EXPLOSIVEARROW]

// address=[0x3f1e2ec]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_SULFUR]

// address=[0x3f1e2f8]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_SHOVEL]

// address=[0x3f1e304]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_HAMMER]

// address=[0x3f1e310]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_AXE]

// address=[0x3f1e31c]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_PICKAXE]

// address=[0x3f1e328]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_SAW]

// address=[0x3f1e334]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_ROD]

// address=[0x3f1e340]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_SCYTHE]

// address=[0x3f1e34c]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_GOLDBAR]

// address=[0x3f1e358]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_GOLDORE]

// address=[0x3f1e364]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_SUNFLOWEROIL]

// address=[0x3f1e370]
// [Decompilation failed for static class CStaticConfigVarInt CGoodTransportPriority::m_iDefault_TROJAN_TP_SUNFLOWER]

