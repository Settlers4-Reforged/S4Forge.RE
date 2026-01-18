#include "CTile.h"

// Definitions for class CTile

// address=[0x12fd600]
// Decompiled from int __thiscall CTile::SectorId(CTile *this)
int  CTile::SectorId(void)const {
  
  return (unsigned __int16)*((_DWORD *)this + 1);
}


// address=[0x13064a0]
// Decompiled from int __thiscall CTile::CenterX(CTile *this)
int  CTile::CenterX(void)const {
  
  return (unsigned __int16)this->center;
}


// address=[0x13064c0]
// Decompiled from int __thiscall CTile::CenterY(CTile *this)
int  CTile::CenterY(void)const {
  
  return (int)this->center >> 16;
}


// address=[0x1306770]
// Decompiled from int __thiscall CTile::NextSquareTile(CTile *this)
int  CTile::NextSquareTile(void)const {
  
  return this->nextSquareTile;
}


// address=[0x13068f0]
// Decompiled from DWORD __thiscall CTile::OwnerId(CTile *this)
int  CTile::OwnerId(void)const {
  
  return this->type & 0xF;
}


// address=[0x130eaf0]
// Decompiled from DWORD __thiscall CTile::EcoSectorId(CTile *this)
int  CTile::EcoSectorId(void)const {
  
  return HIWORD(this->ecoSectorId);
}


// address=[0x133a160]
// Decompiled from BOOL __thiscall CTile::TilingType(CTile *this)
enum T_TILING_TYPE  CTile::TilingType(void)const {
  
  return (this->type & 0x8000000) != 0;
}


// address=[0x1346870]
// Decompiled from DWORD __thiscall CTile::LinkList(CTile *this)
class CLinkList &  CTile::LinkList(void)const {
  
  return this->LinkList;
}


// address=[0x13469c0]
// Decompiled from DWORD __thiscall CTile::Type(CTile *this)
int  CTile::Type(void)const {
  
  return this->type;
}


// address=[0x1351a90]
// Decompiled from DWORD __thiscall CTile::CenterXY(CTile *this)
int  CTile::CenterXY(void)const {
  
  return this->center;
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
// Decompiled from CTile *__thiscall CTile::SetLinkList(CTile *this, struct CLinkList *a2)
void  CTile::SetLinkList(class CLinkList & a2) {
  
  CTile *result; // eax

  result = this;
  this->LinkList = (DWORD)a2;
  return result;
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
  result = (a2 << 13) | this->type & 0xFFC01FFF;
  this->type = result;
  return result;
}


// address=[0x15e7410]
// Decompiled from CTile *__thiscall CTile::SetType(CTile *this, DWORD a2)
void  CTile::SetType(int a2) {
  
  CTile *result; // eax

  result = this;
  this->type = a2;
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
  
  return this->type == -1;
}


// address=[0x15e7590]
// Decompiled from bool __thiscall CTile::Used(CTile *this)
bool  CTile::Used(void)const {
  
  return this->type < 0xFFFFFFFD;
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
  
  return this->center;
}


// address=[0x15f5340]
// Decompiled from DWORD __thiscall CTile::PrevFree(CTile *this)
int  CTile::PrevFree(void)const {
  
  return this->ecoSectorId;
}


// address=[0x15f56f0]
// Decompiled from CTile *__thiscall CTile::SetCenterXY(CTile *this, DWORD a2)
void  CTile::SetCenterXY(int a2) {
  
  CTile *result; // eax

  result = this;
  this->center = a2;
  return result;
}


// address=[0x15f5710]
// Decompiled from CTile *__thiscall CTile::SetEcoSectorId(CTile *this, __int16 a2)
void  CTile::SetEcoSectorId(int a2) {
  
  CTile *result; // eax

  result = this;
  HIWORD(this->ecoSectorId) = a2;
  return result;
}


// address=[0x15f5840]
// Decompiled from CTile *__thiscall CTile::SetSectorId(CTile *this, __int16 a2)
void  CTile::SetSectorId(int a2) {
  
  CTile *result; // eax

  result = this;
  LOWORD(this->ecoSectorId) = a2;
  return result;
}


// address=[0x15f5900]
// Decompiled from DWORD __thiscall CTile::Size(CTile *this)
int  CTile::Size(void)const {
  
  return (this->type & 0x3FE000) >> 13;
}


// address=[0x15f59d0]
// Decompiled from int __cdecl CTile::TileTypeToOwnerId(char a1)
int __cdecl CTile::TileTypeToOwnerId(int a1) {
  
  return a1 & 0xF;
}


// address=[0x15e6f80]
// Decompiled from CTile *__thiscall CTile::Init(CTile *this, DWORD a2, DWORD a3, struct CLinkList *a4)
void  CTile::Init(int a2, int a3, class CLinkList & a4) {
  
  CTile *result; // eax

  this->type = a2;
  this->center = a3;
  this->LinkList = (DWORD)a4;
  result = this;
  this->ecoSectorId = 0;
  return result;
}


// address=[0x15e6fc0]
// Decompiled from CTile *__thiscall CTile::InitPseudoTile(CTile *this, int a2, struct CLinkList *a3)
void  CTile::InitPseudoTile(int a2, class CLinkList & a3) {
  
  CTile *result; // eax

  this->type = CTile::TileType(a2);
  this->center = 0;
  result = this;
  this->LinkList = (DWORD)a3;
  this->ecoSectorId = 0;
  return result;
}


