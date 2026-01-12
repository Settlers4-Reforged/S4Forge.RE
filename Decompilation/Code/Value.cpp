#include "Value.h"

// Definitions for class Value

// address=[0x2f2d7c0]
// Decompiled from void __thiscall AdvXMLParser::Value::Add(AdvXMLParser::NodeContainer **this, char *Str)

void  AdvXMLParser::Value::Add(char const *) {
  
  _BYTE v3[28]; // [esp+8h] [ebp-2Ch] BYREF
  int v4; // [esp+30h] [ebp-4h]

  std::string::string(v3, Str);
  v4 = 0;
  AdvXMLParser::NodeContainer::AddText(*this, (int)v3);
  v4 = -1;
  std::string::~string(v3);
}


