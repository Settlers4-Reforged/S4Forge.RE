#ifndef  LZHL_HuffStat_HPP
#define  LZHL_HuffStat_HPP

#include "LZHMacro.h"
#include "HuffStatTmp.h"

class HuffStat {
public:
  HuffStat();
  virtual ~HuffStat();
public:
  HUFFINT* stat;

protected:
  int makeSortedTmp( HuffStatTmpStruct* );

};

#endif
