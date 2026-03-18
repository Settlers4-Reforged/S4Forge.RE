#if FALSE
#include "CTile.h"

// Definitions for class CTile

// address=[0x12fd600]
// Decompiled from int __thiscall CTile::SectorId(CTile *this)
int  CTile::SectorId(void)const {
  
  return (unsigned __int16)this->m_iSectorId;
}


// address=[0x13064a0]
// Decompiled from int __thiscall CTile::CenterX(CTile *this)
int  CTile::CenterX(void)const {
  
  return (unsigned __int16)this->m_uCenter;
}


// address=[0x13064c0]
// Decompiled from int __thiscall CTile::CenterY(CTile *this)
int  CTile::CenterY(void)const {
  
  return (int)this->m_uCenter >> 16;
}


// address=[0x1306770]
// Decompiled from int __thiscall CTile::NextSquareTile(CTile *this)
int  CTile::NextSquareTile(void)const {
  
  return this->m_uSquareNext;
}


// address=[0x13068f0]
// Decompiled from DWORD __thiscall CTile::OwnerId(CTile *this)
int  CTile::OwnerId(void)const {
  
  return this->m_iType & 0xF;
}


// address=[0x130eaf0]
// Decompiled from DWORD __thiscall CTile::EcoSectorId(CTile *this)
int  CTile::EcoSectorId(void)const {
  
  return HIWORD(this->m_iSectorId);
}


// address=[0x133a160]
// Decompiled from BOOL __thiscall CTile::TilingType(CTile *this)
enum T_TILING_TYPE  CTile::TilingType(void)const {
  
  return (this->m_iType & 0x8000000) != 0;
}


// address=[0x1346870]
// Decompiled from struct CLinkList *__thiscall CTile::LinkList(CTile *this)
class CLinkList &  CTile::LinkList(void)const {
  
  return this->m_pLinkList;
}


// address=[0x13469c0]
// Decompiled from int __thiscall CTile::Type(CTile *this)
int  CTile::Type(void)const {
  
  return this->m_iType;
}


// address=[0x1351a90]
// Decompiled from DWORD __thiscall CTile::CenterXY(CTile *this)
int  CTile::CenterXY(void)const {
  
  return this->m_uCenter;
}


// address=[0x15d6e90]
// Decompiled from int __cdecl CTile::TileTypeOwnerCheckMask(char a1, int a2)
int __cdecl CTile::TileTypeOwnerCheckMask(int a1, int a2) {
  
  int v3; // [esp+0h] [ebp-4h]

  v3 = 0;
  if ( a2 )
    return (16 << a1) ^ 0x1FF0;
  return v3;
}


// address=[0x15d6ed0]
// Decompiled from int __cdecl CTile::TileTypeOwnerCheckMaskFromPlayerBits(int a1)
int __cdecl CTile::TileTypeOwnerCheckMaskFromPlayerBits(int a1) {
  
  if ( ((32 * a1) & 0xFFFFE00F) != 0
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\pathing\\Tile.h",
         292,
         "(iOwnerBits & ~TILE_TYPE_OWNER_BITS_ALL) == 0") == 1 )
  {
    __debugbreak();
  }
  return (32 * a1) ^ 0x1FF0;
}


// address=[0x15e7360]
// Decompiled from void __thiscall CTile::SetLinkList(CTile *this, struct CLinkList *a2)
void  CTile::SetLinkList(class CLinkList & a2) {
  
  this->m_pLinkList = a2;
}


// address=[0x15e7380]
// Decompiled from DWORD __thiscall CTile::SetSize(CTile *this, int a2)
void  CTile::SetSize(int a2) {
  
  DWORD result; // eax

  if ( a2 >= 0 )
  {
    if ( a2 > 256 )
      a2 = 256;
  }
  else
  {
    a2 = 0;
  }
  if ( ((a2 << 13) & 0xFFC01FFF) != 0
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\pathing\\Tile.h",
         311,
         "((_iSize << TILE_TYPE_SIZE_SHIFT) & ~TILE_TYPE_SIZE_MASK) == 0") == 1 )
  {
    __debugbreak();
  }
  result = (a2 << 13) | this->m_iType & 0xFFC01FFF;
  this->m_iType = result;
  return result;
}


// address=[0x15e7410]
// Decompiled from CTile *__thiscall CTile::SetType(CTile *this, DWORD a2)
void  CTile::SetType(int a2) {
  
  CTile *result; // eax

  result = this;
  this->m_iType = a2;
  return result;
}


// address=[0x15e74b0]
// Decompiled from int __cdecl CTile::TileType(int a1)
int __cdecl CTile::TileType(int a1) {
  
  return a1 | (16 << a1);
}


// address=[0x15e7510]
// Decompiled from bool __thiscall CTile::Unused(CTile *this)
bool  CTile::Unused(void)const {
  
  return this->m_iType == -1;
}


// address=[0x15e7590]
// Decompiled from bool __thiscall CTile::Used(CTile *this)
bool  CTile::Used(void)const {
  
  return this->m_iType < 0xFFFFFFFD;
}


// address=[0x15f4220]
// Decompiled from void __thiscall CTile::ChangeSize(CTile *this, int a2)
void  CTile::ChangeSize(int a2) {
  
  int v2; // eax

  v2 = CTile::Size(this);
  CTile::SetSize(this, a2 + v2);
}


// address=[0x15f4a70]
// Decompiled from DWORD __thiscall CTile::NextFree(CTile *this)
int  CTile::NextFree(void)const {
  
  return this->m_uCenter;
}


// address=[0x15f5340]
// Decompiled from DWORD __thiscall CTile::PrevFree(CTile *this)
int  CTile::PrevFree(void)const {
  
  return this->m_iSectorId;
}


// address=[0x15f56f0]
// Decompiled from CTile *__thiscall CTile::SetCenterXY(CTile *this, DWORD a2)
void  CTile::SetCenterXY(int a2) {
  
  CTile *result; // eax

  result = this;
  this->m_uCenter = a2;
  return result;
}


// address=[0x15f5710]
// Decompiled from CTile *__thiscall CTile::SetEcoSectorId(CTile *this, int a2)
void  CTile::SetEcoSectorId(int a2) {
  
  CTile *result; // eax

  result = this;
  this->m_iEcoSectorId = a2;
  return result;
}


// address=[0x15f5840]
// Decompiled from CTile *__thiscall CTile::SetSectorId(CTile *this, WORD a2)
void  CTile::SetSectorId(int a2) {
  
  CTile *result; // eax

  result = this;
  this->m_iSectorId = a2;
  return result;
}


// address=[0x15f5900]
// Decompiled from DWORD __thiscall CTile::Size(CTile *this)
int  CTile::Size(void)const {
  
  return (this->m_iType & 0x3FE000) >> 13;
}


// address=[0x15f59d0]
// Decompiled from int __cdecl CTile::TileTypeToOwnerId(char a1)
int __cdecl CTile::TileTypeToOwnerId(int a1) {
  
  return a1 & 0xF;
}


// address=[0x15e6f80]
// Decompiled from void __thiscall CTile::Init(CTile *this, int a2, DWORD a3, struct CLinkList *a4)
void  CTile::Init(int a2, int a3, class CLinkList & a4) {
  
  this->m_iType = a2;
  this->m_uCenter = a3;
  this->m_pLinkList = a4;
  *(_DWORD *)&this->m_iSectorId = 0;
}


// address=[0x15e6fc0]
// Decompiled from CTile *__thiscall CTile::InitPseudoTile(CTile *this, int a2, struct CLinkList *a3)
void  CTile::InitPseudoTile(int a2, class CLinkList & a3) {
  
  CTile *result; // eax

  this->m_iType = CTile::TileType(a2);
  this->m_uCenter = 0;
  result = this;
  this->m_pLinkList = (DWORD)a3;
  this->m_iSectorId = 0;
  return result;
}


#endif // Already implemented
