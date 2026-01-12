#include "CPortGoodsTradeBarInfo.h"

// Definitions for class CPortGoodsTradeBarInfo

// address=[0x1454770]
// Decompiled from CPortGoodsTradeBarInfo *__thiscall CPortGoodsTradeBarInfo::CPortGoodsTradeBarInfo(CPortGoodsTradeBarInfo *this)
 CPortGoodsTradeBarInfo::CPortGoodsTradeBarInfo(void) {
  
  CInfoExchange::CInfoExchange(this);
  *(_DWORD *)this = &CPortGoodsTradeBarInfo::_vftable_;
  return this;
}


// address=[0x1454cf0]
// Decompiled from int __thiscall CPortGoodsTradeBarInfo::Size(CPortGoodsTradeBarInfo *this)
unsigned int  CPortGoodsTradeBarInfo::Size(void)const {
  
  return 60;
}


