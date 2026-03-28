#ifndef  LZHL_LZHLDecoderStat_HPP
#define  LZHL_LZHLDecoderStat_HPP

#include "HuffStat.h"
#include "LZHMacro.h"

class LZHLDecoderStat : public HuffStat {
public:
  LZHLDecoderStat();
  virtual ~LZHLDecoderStat();

public:
  struct Group { int nBits; int pos; };

public:
  static Group groupTable0[];
  Group groupTable[ 16 ];

  static HUFFINT symbolTable0[];
  HUFFINT* symbolTable;
};

#endif
