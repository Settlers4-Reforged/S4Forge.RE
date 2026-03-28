#ifndef  LZHL_LZHLCompressor_HPP
#define  LZHL_LZHLCompressor_HPP

#include "LZBuffer.h"
#include "LZHLEncoder.h"
#include "LZHLEncoderStat.h"
#include "LZHMacro.h"

class LZHLCompressor : private LZBuffer {
public:
  LZHLCompressor();
  virtual ~LZHLCompressor();

public:
  static size_t calcMaxBuf( size_t rawSz ) {
    return LZHLEncoder::calcMaxBuf( rawSz );
  }

  size_t compress( uint8_t* dst, const uint8_t* src, size_t sz );

private:
  void _wrapTable();
  LZHASH _updateTable( LZHASH hash, const uint8_t* src, LZPOS pos, ptrdiff_t len );

private:
  LZHLEncoderStat stat;
  LZTableItem* table;
};

#endif
