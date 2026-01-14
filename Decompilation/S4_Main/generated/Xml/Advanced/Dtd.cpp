#include "all_headers.h"

// Definitions for class Dtd

// address=[0x2f249c0]
// Decompiled from AdvXMLParser::Dtd *__thiscall AdvXMLParser::Dtd::Dtd(AdvXMLParser::Dtd *this, struct Document *a2)
 AdvXMLParser::Dtd::Dtd(class AdvXMLParser::Document &) {
  
  *(_DWORD *)this = a2;
  return this;
}


// address=[0x2f249e0]
// Decompiled from char __thiscall AdvXMLParser::Dtd::ParseDoctypedecl(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParseDoctypedecl(class AdvXMLParser::Parser &) {
  
  _BYTE v4[28]; // [esp+Ch] [ebp-2Ch] BYREF
  int v5; // [esp+34h] [ebp-4h]

  if ( !AdvXMLParser::Parser::ParseString(a2, "<!DOCTYPE") )
    return 0;
  if ( !AdvXMLParser::Parser::ParseSpaces(a2) )
    AdvXMLParser::Parser::SyntaxError(a2, 26);
  std::string::string();
  v5 = 0;
  if ( !(unsigned __int8)AdvXMLParser::Parser::ParseName(v4) )
    AdvXMLParser::Parser::SyntaxError(a2, 26);
  AdvXMLParser::Parser::ParseSpaces(a2);
  if ( AdvXMLParser::Dtd::ParseExternalID(this, a2) )
    AdvXMLParser::Parser::ParseSpaces(a2);
  if ( AdvXMLParser::Parser::ParseChar(a2, 91) )
  {
    while ( !AdvXMLParser::Parser::ParseChar(a2, 93) )
    {
      if ( !AdvXMLParser::Parser::ParseSpaces(a2)
        && !AdvXMLParser::Dtd::ParseMarkupdecl(this, a2)
        && !AdvXMLParser::Dtd::ParsePEReference(this, a2) )
      {
        AdvXMLParser::Parser::SyntaxError(a2, 26);
      }
    }
    AdvXMLParser::Parser::ParseSpaces(a2);
  }
  if ( !AdvXMLParser::Parser::ParseChar(a2, 62) )
    AdvXMLParser::Parser::SyntaxError(a2, 26);
  v5 = -1;
  std::string::~string(v4);
  return 1;
}


// address=[0x2f24b50]
// Decompiled from char __thiscall AdvXMLParser::Dtd::ParsePEReference(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParsePEReference(class AdvXMLParser::Parser &) {
  
  _BYTE v3[28]; // [esp+Ch] [ebp-2Ch] BYREF
  int v4; // [esp+34h] [ebp-4h]

  if ( !AdvXMLParser::Parser::ParseChar(a2, 37) )
    return 0;
  std::string::string();
  v4 = 0;
  if ( !(unsigned __int8)AdvXMLParser::Parser::ParseName(v3) || !AdvXMLParser::Parser::ParseChar(a2, 59) )
    AdvXMLParser::Parser::SyntaxError(a2, 27);
  v4 = -1;
  std::string::~string(v3);
  return 1;
}


// address=[0x2f24c00]
// Decompiled from char __thiscall AdvXMLParser::Dtd::ParseSystemLiteral(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParseSystemLiteral(class AdvXMLParser::Parser &) {
  
  char Char; // [esp+Ah] [ebp-2h]
  unsigned __int8 v4; // [esp+Bh] [ebp-1h]

  Char = AdvXMLParser::Parser::NextChar(a2);
  if ( Char != 39 && Char != 34 )
    return 0;
  while ( 1 )
  {
    v4 = AdvXMLParser::Parser::NextChar(a2);
    if ( (char)v4 == Char )
      break;
    if ( !v4 )
      AdvXMLParser::Parser::SyntaxError(a2, 1);
    if ( !AdvXMLParser::IsXmlChar((AdvXMLParser *)v4) )
      AdvXMLParser::Parser::SyntaxError(a2, 2);
  }
  return 1;
}


// address=[0x2f24c90]
// Decompiled from char __thiscall AdvXMLParser::Dtd::ParsePubidLiteral(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParsePubidLiteral(class AdvXMLParser::Parser &) {
  
  char Char; // [esp+6h] [ebp-2h]
  char v4; // [esp+7h] [ebp-1h]

  Char = AdvXMLParser::Parser::NextChar(a2);
  if ( Char != 39 && Char != 34 )
    return 0;
  while ( 1 )
  {
    v4 = AdvXMLParser::Parser::NextChar(a2);
    if ( v4 == Char )
      break;
    if ( !v4 )
      AdvXMLParser::Parser::SyntaxError(a2, 1);
    if ( !(unsigned __int8)sub_2F26F60(v4) )
      AdvXMLParser::Parser::SyntaxError(a2, 28);
  }
  return 1;
}


// address=[0x2f24d20]
// Decompiled from bool __thiscall AdvXMLParser::Dtd::ParseMarkupdecl(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParseMarkupdecl(class AdvXMLParser::Parser &) {
  
  return AdvXMLParser::Dtd::ParseElementDecl(this, a2)
      || AdvXMLParser::Dtd::ParseAttlistDecl(this, a2)
      || AdvXMLParser::Dtd::ParseEntityDecl(this, a2)
      || AdvXMLParser::Dtd::ParseNotationDecl(this, a2);
}


// address=[0x2f24d90]
// Decompiled from char __thiscall AdvXMLParser::Dtd::ParseElementDecl(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParseElementDecl(class AdvXMLParser::Parser &) {
  
  _BYTE v4[28]; // [esp+Ch] [ebp-2Ch] BYREF
  int v5; // [esp+34h] [ebp-4h]

  if ( !AdvXMLParser::Parser::ParseString(a2, "<!ELEMENT") )
    return 0;
  std::string::string();
  v5 = 0;
  if ( !AdvXMLParser::Parser::ParseSpaces(a2)
    || !(unsigned __int8)AdvXMLParser::Parser::ParseName(v4)
    || !AdvXMLParser::Parser::ParseSpaces(a2)
    || !AdvXMLParser::Dtd::ParseContentspec(this, a2) )
  {
    AdvXMLParser::Parser::SyntaxError(a2, 29);
  }
  AdvXMLParser::Parser::ParseSpaces(a2);
  if ( AdvXMLParser::Parser::NextChar(a2) != 62 )
    AdvXMLParser::Parser::SyntaxError(a2, 29);
  v5 = -1;
  std::string::~string(v4);
  return 1;
}


// address=[0x2f24e90]
// Decompiled from bool __thiscall AdvXMLParser::Dtd::ParseContentspec(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParseContentspec(class AdvXMLParser::Parser &) {
  
  if ( AdvXMLParser::Parser::ParseString(a2, "EMPTY") )
    return 1;
  if ( AdvXMLParser::Parser::ParseString(a2, "ANY") )
    return 1;
  return AdvXMLParser::Dtd::ParseMixed(this, a2) || AdvXMLParser::Dtd::ParseChildren(this, a2);
}


// address=[0x2f24f00]
// Decompiled from char __thiscall AdvXMLParser::Dtd::ParseMixed(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParseMixed(class AdvXMLParser::Parser &) {
  
  _BYTE v3[16]; // [esp+4h] [ebp-40h] BYREF
  AdvXMLParser::Dtd *v4; // [esp+14h] [ebp-30h]
  _BYTE v5[28]; // [esp+18h] [ebp-2Ch] BYREF
  int v6; // [esp+40h] [ebp-4h]

  v4 = this;
  AdvXMLParser::Bookmark::Bookmark((AdvXMLParser::Bookmark *)v3, a2);
  if ( !AdvXMLParser::Parser::ParseChar(a2, 40) )
    return 0;
  AdvXMLParser::Parser::ParseSpaces(a2);
  if ( AdvXMLParser::Parser::ParseString(a2, "#PCDATA") )
  {
    AdvXMLParser::Parser::ParseSpaces(a2);
    if ( AdvXMLParser::Parser::ParseString(a2, ")*") )
    {
      return 1;
    }
    else if ( AdvXMLParser::Parser::ParseChar(a2, 41) )
    {
      return 1;
    }
    else
    {
      while ( 1 )
      {
        if ( !AdvXMLParser::Parser::ParseChar(a2, 124) )
          AdvXMLParser::Parser::SyntaxError(a2, 30);
        std::string::string();
        v6 = 0;
        AdvXMLParser::Parser::ParseSpaces(a2);
        AdvXMLParser::Parser::ParseName(v5);
        AdvXMLParser::Parser::ParseSpaces(a2);
        if ( AdvXMLParser::Parser::ParseString(a2, ")*") )
          break;
        v6 = -1;
        std::string::~string(v5);
      }
      v6 = -1;
      std::string::~string(v5);
      return 1;
    }
  }
  else
  {
    AdvXMLParser::Bookmark::Restore((AdvXMLParser::Bookmark *)v3);
    return 0;
  }
}


// address=[0x2f25050]
// Decompiled from char __thiscall AdvXMLParser::Dtd::ParseChildren(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParseChildren(class AdvXMLParser::Parser &) {
  
  char Char; // [esp+4h] [ebp-8h]
  bool v4; // [esp+Bh] [ebp-1h] BYREF

  if ( !AdvXMLParser::Dtd::ParseChoiceSeq(this, a2, &v4) )
    return 0;
  Char = AdvXMLParser::Parser::NextChar(a2);
  if ( Char < 42 || Char > 43 && Char != 63 )
    AdvXMLParser::Parser::PreviousChar(a2);
  return 1;
}


// address=[0x2f250b0]
// Decompiled from char __thiscall AdvXMLParser::Dtd::ParseChoiceSeq(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2, bool *a3)
bool  AdvXMLParser::Dtd::ParseChoiceSeq(class AdvXMLParser::Parser &,bool &) {
  
  char v5; // [esp+Eh] [ebp-2h]
  char Char; // [esp+Fh] [ebp-1h]

  if ( !AdvXMLParser::Parser::ParseChar(a2, 40) )
    return 0;
  AdvXMLParser::Parser::ParseSpaces(a2);
  if ( !AdvXMLParser::Dtd::ParseCp(this, a2) )
    AdvXMLParser::Parser::SyntaxError(a2, 32);
  AdvXMLParser::Parser::ParseSpaces(a2);
  Char = AdvXMLParser::Parser::NextChar(a2);
  v5 = Char;
  while ( Char != 41 )
  {
    if ( !Char )
      AdvXMLParser::Parser::SyntaxError(a2, 1);
    if ( Char != v5 )
    {
      if ( v5 == 124 )
        AdvXMLParser::Parser::SyntaxError(a2, 30);
      AdvXMLParser::Parser::SyntaxError(a2, 31);
    }
    AdvXMLParser::Parser::ParseSpaces(a2);
    if ( !AdvXMLParser::Dtd::ParseCp(this, a2) )
      AdvXMLParser::Parser::SyntaxError(a2, 32);
    AdvXMLParser::Parser::ParseSpaces(a2);
    Char = AdvXMLParser::Parser::NextChar(a2);
  }
  return 1;
}


// address=[0x2f251b0]
// Decompiled from char __thiscall AdvXMLParser::Dtd::ParseCp(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParseCp(class AdvXMLParser::Parser &) {
  
  char Char; // [esp+8h] [ebp-34h]
  bool v5; // [esp+Dh] [ebp-2Fh] BYREF
  char v6; // [esp+Eh] [ebp-2Eh]
  char v7; // [esp+Fh] [ebp-2Dh]
  _BYTE v8[28]; // [esp+10h] [ebp-2Ch] BYREF
  int v9; // [esp+38h] [ebp-4h]

  std::string::string();
  v9 = 0;
  if ( (unsigned __int8)AdvXMLParser::Parser::ParseName(v8) || AdvXMLParser::Dtd::ParseChoiceSeq(this, a2, &v5) )
  {
    Char = AdvXMLParser::Parser::NextChar(a2);
    if ( Char < 42 || Char > 43 && Char != 63 )
      AdvXMLParser::Parser::PreviousChar(a2);
    v6 = 1;
    v9 = -1;
    std::string::~string(v8);
    return v6;
  }
  else
  {
    v7 = 0;
    v9 = -1;
    std::string::~string(v8);
    return v7;
  }
}


// address=[0x2f25290]
// Decompiled from char __thiscall AdvXMLParser::Dtd::ParseAttlistDecl(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParseAttlistDecl(class AdvXMLParser::Parser &) {
  
  _BYTE v4[28]; // [esp+Ch] [ebp-2Ch] BYREF
  int v5; // [esp+34h] [ebp-4h]

  if ( !AdvXMLParser::Parser::ParseString(a2, "<!ATTLIST") )
    return 0;
  std::string::string();
  v5 = 0;
  if ( !AdvXMLParser::Parser::ParseSpaces(a2) || !(unsigned __int8)AdvXMLParser::Parser::ParseName(v4) )
    AdvXMLParser::Parser::SyntaxError(a2, 33);
  while ( AdvXMLParser::Dtd::ParseAttDef(this, a2) )
    ;
  AdvXMLParser::Parser::ParseSpaces(a2);
  if ( AdvXMLParser::Parser::NextChar(a2) != 62 )
    AdvXMLParser::Parser::SyntaxError(a2, 33);
  v5 = -1;
  std::string::~string(v4);
  return 1;
}


// address=[0x2f25380]
// Decompiled from char __thiscall AdvXMLParser::Dtd::ParseAttDef(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParseAttDef(class AdvXMLParser::Parser &) {
  
  _BYTE v3[16]; // [esp+4h] [ebp-44h] BYREF
  AdvXMLParser::Dtd *v4; // [esp+14h] [ebp-34h]
  char v5; // [esp+1Ah] [ebp-2Eh]
  char v6; // [esp+1Bh] [ebp-2Dh]
  _BYTE v7[28]; // [esp+1Ch] [ebp-2Ch] BYREF
  int v8; // [esp+44h] [ebp-4h]

  v4 = this;
  AdvXMLParser::Bookmark::Bookmark((AdvXMLParser::Bookmark *)v3, a2);
  std::string::string();
  v8 = 0;
  if ( AdvXMLParser::Parser::ParseSpaces(a2) && (unsigned __int8)AdvXMLParser::Parser::ParseName(v7) )
  {
    if ( !AdvXMLParser::Parser::ParseSpaces(a2)
      || !AdvXMLParser::Dtd::ParseAttType(v4, a2)
      || !AdvXMLParser::Parser::ParseSpaces(a2)
      || !AdvXMLParser::Dtd::ParseDefaultDecl(v4, a2) )
    {
      AdvXMLParser::Parser::SyntaxError(a2, 34);
    }
    v5 = 1;
    v8 = -1;
    std::string::~string(v7);
    return v5;
  }
  else
  {
    AdvXMLParser::Bookmark::Restore((AdvXMLParser::Bookmark *)v3);
    v6 = 0;
    v8 = -1;
    std::string::~string(v7);
    return v6;
  }
}


// address=[0x2f25490]
// Decompiled from bool __thiscall AdvXMLParser::Dtd::ParseAttType(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParseAttType(class AdvXMLParser::Parser &) {
  
  if ( AdvXMLParser::Parser::ParseString(a2, "CDATA") )
    return 1;
  if ( AdvXMLParser::Parser::ParseString(a2, "IDREFS")
    || AdvXMLParser::Parser::ParseString(a2, "IDREF")
    || AdvXMLParser::Parser::ParseString(a2, "ID")
    || AdvXMLParser::Parser::ParseString(a2, "ENTITIES")
    || AdvXMLParser::Parser::ParseString(a2, "ENTITY")
    || AdvXMLParser::Parser::ParseString(a2, "NMTOKENS")
    || AdvXMLParser::Parser::ParseString(a2, "NMTOKEN") )
  {
    return 1;
  }
  return AdvXMLParser::Dtd::ParseNotationType(this, a2) || AdvXMLParser::Dtd::ParseEnumeration(this, a2);
}


// address=[0x2f25580]
// Decompiled from char __thiscall AdvXMLParser::Dtd::ParseNotationType(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParseNotationType(class AdvXMLParser::Parser &) {
  
  _BYTE v3[28]; // [esp+Ch] [ebp-48h] BYREF
  _BYTE v4[28]; // [esp+28h] [ebp-2Ch] BYREF
  int v5; // [esp+50h] [ebp-4h]

  if ( !AdvXMLParser::Parser::ParseString(a2, "NOTATION") )
    return 0;
  if ( !AdvXMLParser::Parser::ParseSpaces(a2) || !AdvXMLParser::Parser::ParseChar(a2, 40) )
    AdvXMLParser::Parser::SyntaxError(a2, 35);
  AdvXMLParser::Parser::ParseSpaces(a2);
  std::string::string();
  v5 = 0;
  if ( !(unsigned __int8)AdvXMLParser::Parser::ParseName(v3) )
    AdvXMLParser::Parser::SyntaxError(a2, 35);
  AdvXMLParser::Parser::ParseSpaces(a2);
  while ( AdvXMLParser::Parser::ParseChar(a2, 124) )
  {
    AdvXMLParser::Parser::ParseSpaces(a2);
    std::string::string();
    LOBYTE(v5) = 1;
    if ( !(unsigned __int8)AdvXMLParser::Parser::ParseName(v4) )
      AdvXMLParser::Parser::SyntaxError(a2, 35);
    AdvXMLParser::Parser::ParseSpaces(a2);
    LOBYTE(v5) = 0;
    std::string::~string(v4);
  }
  if ( !AdvXMLParser::Parser::ParseChar(a2, 41) )
    AdvXMLParser::Parser::SyntaxError(a2, 35);
  v5 = -1;
  std::string::~string(v3);
  return 1;
}


// address=[0x2f256d0]
// Decompiled from char __thiscall AdvXMLParser::Dtd::ParseEnumeration(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParseEnumeration(class AdvXMLParser::Parser &) {
  
  _BYTE v3[28]; // [esp+Ch] [ebp-48h] BYREF
  _BYTE v4[28]; // [esp+28h] [ebp-2Ch] BYREF
  int v5; // [esp+50h] [ebp-4h]

  if ( !AdvXMLParser::Parser::ParseChar(a2, 40) )
    return 0;
  AdvXMLParser::Parser::ParseSpaces(a2);
  std::string::string();
  v5 = 0;
  if ( !(unsigned __int8)AdvXMLParser::Parser::ParseNmtoken(v3) )
    AdvXMLParser::Parser::SyntaxError(a2, 36);
  AdvXMLParser::Parser::ParseSpaces(a2);
  while ( AdvXMLParser::Parser::ParseChar(a2, 124) )
  {
    AdvXMLParser::Parser::ParseSpaces(a2);
    std::string::string();
    LOBYTE(v5) = 1;
    if ( !(unsigned __int8)AdvXMLParser::Parser::ParseNmtoken(v4) )
      AdvXMLParser::Parser::SyntaxError(a2, 36);
    AdvXMLParser::Parser::ParseSpaces(a2);
    LOBYTE(v5) = 0;
    std::string::~string(v4);
  }
  if ( !AdvXMLParser::Parser::ParseChar(a2, 41) )
    AdvXMLParser::Parser::SyntaxError(a2, 36);
  v5 = -1;
  std::string::~string(v3);
  return 1;
}


// address=[0x2f25800]
// Decompiled from char __thiscall AdvXMLParser::Dtd::ParseDefaultDecl(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParseDefaultDecl(class AdvXMLParser::Parser &) {
  
  _BYTE v3[56]; // [esp+Ch] [ebp-64h] BYREF
  _BYTE v4[28]; // [esp+44h] [ebp-2Ch] BYREF
  int v5; // [esp+6Ch] [ebp-4h]

  if ( AdvXMLParser::Parser::ParseString(a2, "#REQUIRED") || AdvXMLParser::Parser::ParseString(a2, "#IMPLIED") )
    return 1;
  if ( AdvXMLParser::Parser::ParseString(a2, "#FIXED") && !AdvXMLParser::Parser::ParseSpaces(a2) )
    AdvXMLParser::Parser::SyntaxError(a2, 37);
  std::string::string(v4, (char *)byte_3AB88DA);
  v5 = 0;
  AdvXMLParser::Attribute::Attribute(AdvXMLParser::Node::null, v4);
  LOBYTE(v5) = 2;
  std::string::~string(v4);
  if ( AdvXMLParser::Attribute::ParseAttValue((AdvXMLParser::Attribute *)v3, a2) )
  {
    v5 = -1;
    AdvXMLParser::Attribute::~Attribute((AdvXMLParser::Attribute *)v3);
    return 1;
  }
  else
  {
    v5 = -1;
    AdvXMLParser::Attribute::~Attribute((AdvXMLParser::Attribute *)v3);
    return 0;
  }
}


// address=[0x2f25920]
// Decompiled from char __thiscall AdvXMLParser::Dtd::ParseEntityDecl(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParseEntityDecl(class AdvXMLParser::Parser &) {
  
  _BYTE v4[28]; // [esp+8h] [ebp-48h] BYREF
  _BYTE v5[28]; // [esp+24h] [ebp-2Ch] BYREF
  int v6; // [esp+4Ch] [ebp-4h]

  if ( !AdvXMLParser::Parser::ParseString(a2, "<!ENTITY") )
    return 0;
  if ( !AdvXMLParser::Parser::ParseSpaces(a2) )
    AdvXMLParser::Parser::SyntaxError(a2, 38);
  if ( AdvXMLParser::Parser::ParseChar(a2, 37) )
  {
    std::string::string();
    v6 = 0;
    if ( !AdvXMLParser::Parser::ParseSpaces(a2)
      || !(unsigned __int8)AdvXMLParser::Parser::ParseName(v5)
      || !AdvXMLParser::Parser::ParseSpaces(a2)
      || !AdvXMLParser::Dtd::ParsePEDef(this, a2) )
    {
      AdvXMLParser::Parser::SyntaxError(a2, 38);
    }
    v6 = -1;
    std::string::~string(v5);
  }
  else
  {
    std::string::string();
    v6 = 1;
    if ( !(unsigned __int8)AdvXMLParser::Parser::ParseName(v4)
      || !AdvXMLParser::Parser::ParseSpaces(a2)
      || !AdvXMLParser::Dtd::ParseEntityDef(this, a2) )
    {
      AdvXMLParser::Parser::SyntaxError(a2, 38);
    }
    v6 = -1;
    std::string::~string(v4);
  }
  AdvXMLParser::Parser::ParseSpaces(a2);
  if ( !AdvXMLParser::Parser::ParseChar(a2, 62) )
    AdvXMLParser::Parser::SyntaxError(a2, 38);
  return 1;
}


// address=[0x2f25aa0]
// Decompiled from char __thiscall AdvXMLParser::Dtd::ParseEntityDef(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParseEntityDef(class AdvXMLParser::Parser &) {
  
  if ( AdvXMLParser::Dtd::ParseEntityValue(this, a2) )
    return 1;
  if ( !AdvXMLParser::Dtd::ParseExternalID(this, a2) )
    return 0;
  AdvXMLParser::Dtd::ParseNDataDecl(this, a2);
  return 1;
}


// address=[0x2f25af0]
// Decompiled from char __thiscall AdvXMLParser::Dtd::ParseNDataDecl(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParseNDataDecl(class AdvXMLParser::Parser &) {
  
  _BYTE v3[16]; // [esp+4h] [ebp-44h] BYREF
  AdvXMLParser::Dtd *v4; // [esp+14h] [ebp-34h]
  char v5; // [esp+1Bh] [ebp-2Dh]
  _BYTE v6[28]; // [esp+1Ch] [ebp-2Ch] BYREF
  int v7; // [esp+44h] [ebp-4h]

  v4 = this;
  AdvXMLParser::Bookmark::Bookmark((AdvXMLParser::Bookmark *)v3, a2);
  if ( !AdvXMLParser::Parser::ParseSpaces(a2) )
    return 0;
  if ( AdvXMLParser::Parser::ParseString(a2, "NDATA") )
  {
    std::string::string();
    v7 = 0;
    if ( !AdvXMLParser::Parser::ParseSpaces(a2) || !(unsigned __int8)AdvXMLParser::Parser::ParseName(v6) )
      AdvXMLParser::Parser::SyntaxError(a2, 39);
    v5 = 1;
    v7 = -1;
    std::string::~string(v6);
    return v5;
  }
  else
  {
    AdvXMLParser::Bookmark::Restore((AdvXMLParser::Bookmark *)v3);
    return 0;
  }
}


// address=[0x2f25bd0]
// Decompiled from bool __thiscall AdvXMLParser::Dtd::ParsePEDef(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParsePEDef(class AdvXMLParser::Parser &) {
  
  return AdvXMLParser::Dtd::ParseEntityValue(this, a2) || AdvXMLParser::Dtd::ParseExternalID(this, a2);
}


// address=[0x2f25c20]
// Decompiled from char __thiscall AdvXMLParser::Dtd::ParseEntityValue(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParseEntityValue(class AdvXMLParser::Parser &) {
  
  struct AdvXMLParser::Reference *v3; // eax
  unsigned __int8 v4; // al
  _BYTE v6[4]; // [esp+8h] [ebp-18h] BYREF
  char v7; // [esp+Ch] [ebp-14h]
  char v8; // [esp+12h] [ebp-Eh]
  char Char; // [esp+13h] [ebp-Dh]
  int v10; // [esp+1Ch] [ebp-4h]

  Char = AdvXMLParser::Parser::NextChar(a2);
  if ( Char == 39 || Char == 34 )
  {
    v8 = AdvXMLParser::Parser::NextChar(a2);
    while ( v8 != Char )
    {
      v7 = v8;
      if ( !v8 )
        AdvXMLParser::Parser::SyntaxError(a2, 1);
      if ( v7 == 37 )
      {
        AdvXMLParser::Parser::PreviousChar(a2);
        if ( !AdvXMLParser::Dtd::ParsePEReference(this, a2) )
          AdvXMLParser::Parser::SyntaxError(a2, 6);
      }
      else if ( v7 == 38 )
      {
        AdvXMLParser::Parser::PreviousChar(a2);
        v3 = AdvXMLParser::Reference::Parse(a2, (struct AdvXMLParser::NodeContainer *)AdvXMLParser::Node::null);
        std::auto_ptr<AdvXMLParser::Reference>::auto_ptr<AdvXMLParser::Reference>(v3);
        v10 = 0;
        if ( !std::auto_ptr<AdvXMLParser::Reference>::get(v6) )
          AdvXMLParser::Parser::SyntaxError(a2, 6);
        v10 = -1;
        std::auto_ptr<AdvXMLParser::Reference>::~auto_ptr<AdvXMLParser::Reference>(v6);
      }
      else
      {
        v4 = AdvXMLParser::Parser::NextChar(a2);
        if ( !AdvXMLParser::IsXmlChar((AdvXMLParser *)v4) )
          AdvXMLParser::Parser::SyntaxError(a2, 2);
      }
    }
    return 1;
  }
  else
  {
    AdvXMLParser::Parser::PreviousChar(a2);
    return 0;
  }
}


// address=[0x2f25d80]
// Decompiled from char __thiscall AdvXMLParser::Dtd::ParseNotationDecl(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParseNotationDecl(class AdvXMLParser::Parser &) {
  
  _BYTE v4[28]; // [esp+Ch] [ebp-2Ch] BYREF
  int v5; // [esp+34h] [ebp-4h]

  if ( !AdvXMLParser::Parser::ParseString(a2, "<!NOTATION") )
    return 0;
  std::string::string();
  v5 = 0;
  if ( !AdvXMLParser::Parser::ParseSpaces(a2)
    || !(unsigned __int8)AdvXMLParser::Parser::ParseName(v4)
    || !AdvXMLParser::Parser::ParseSpaces(a2) )
  {
    AdvXMLParser::Parser::SyntaxError(a2, 40);
  }
  if ( !AdvXMLParser::Dtd::ParseExternalID(this, a2) && !AdvXMLParser::Dtd::ParsePublicID(this, a2) )
    AdvXMLParser::Parser::SyntaxError(a2, 40);
  AdvXMLParser::Parser::ParseSpaces(a2);
  if ( !AdvXMLParser::Parser::ParseChar(a2, 62) )
    AdvXMLParser::Parser::SyntaxError(a2, 40);
  v5 = -1;
  std::string::~string(v4);
  return 1;
}


// address=[0x2f25ea0]
// Decompiled from char __thiscall AdvXMLParser::Dtd::ParseExternalID(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParseExternalID(class AdvXMLParser::Parser &) {
  
  if ( AdvXMLParser::Parser::ParseString(a2, "SYSTEM") )
  {
    if ( !AdvXMLParser::Parser::ParseSpaces(a2) || !AdvXMLParser::Dtd::ParseSystemLiteral(this, a2) )
      AdvXMLParser::Parser::SyntaxError(a2, 41);
  }
  else
  {
    if ( !AdvXMLParser::Parser::ParseString(a2, "PUBLIC") )
      return 0;
    if ( !AdvXMLParser::Parser::ParseSpaces(a2)
      || !AdvXMLParser::Dtd::ParsePubidLiteral(this, a2)
      || !AdvXMLParser::Parser::ParseSpaces(a2)
      || !AdvXMLParser::Dtd::ParseSystemLiteral(this, a2) )
    {
      AdvXMLParser::Parser::SyntaxError(a2, 41);
    }
  }
  return 1;
}


// address=[0x2f25f60]
// Decompiled from char __thiscall AdvXMLParser::Dtd::ParsePublicID(AdvXMLParser::Dtd *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Dtd::ParsePublicID(class AdvXMLParser::Parser &) {
  
  if ( !AdvXMLParser::Parser::ParseString(a2, "PUBLIC") )
    return 0;
  if ( !AdvXMLParser::Parser::ParseSpaces(a2) || !AdvXMLParser::Dtd::ParsePubidLiteral(this, a2) )
    AdvXMLParser::Parser::SyntaxError(a2, 42);
  return 1;
}


