#include "CPersistence.h"

#include <istream>
#include <ostream>

#include "MapObjects/Settler/CSquadLeaderRole.h"

// Definitions for class CPersistence

std::map<unsigned long, DeserializerFunc> g_mPersistenceClassDeserializer;

// address=[0x130e9f0]
// Decompiled from int CPersistence::ClassID()
unsigned long CPersistence::ClassID(void) const
{
  return CPersistence::m_iClassID;
}

// address=[0x13ed840]
// Decompiled from void __thiscall CPersistence::Store(struct CPersistence *this, struct std::ostream *a2)
void CPersistence::Store(std::ostream &a2)
{

  unsigned int classId; // [esp+0h] [ebp-8h] BYREF
  classId = this->ClassID();
  a2 << classId;
}

// address=[0x13ed870]
// Decompiled from void __cdecl CPersistence::RegisterClassWhithId(  unsigned int *_rClassId,  struct CPersistence *(__cdecl *_rClassDeserializer)(struct std::istrstream *),  unsigned int _iOverrideClassId)
void __cdecl CPersistence::RegisterClassWhithId(unsigned long &_rClassId, DeserializerFunc _rClassDeserializer, unsigned long _iOverrideClassId)
{

  if (!_iOverrideClassId)
    _iOverrideClassId = CPersistence::m_iNextClassID++;
  _rClassId = _iOverrideClassId;
  g_mPersistenceClassDeserializer[_iOverrideClassId] = _rClassDeserializer;
}

// address=[0x13ed8b0]
// Decompiled from int __cdecl CPersistence::New(struct std::istream *stream)
class CPersistence *__cdecl CPersistence::New(std::istream &stream)
{
  unsigned long classId = 0;
  stream >> classId;
  if (stream.fail())
  {
    throw new CPersistence::SerialError();
  }

  auto it = g_mPersistenceClassDeserializer.find(classId);

  if (it == g_mPersistenceClassDeserializer.end())
  {
    throw new CPersistence::BadClassID();
  }

  return it->second(stream);
}

// address=[0x13ed9d0]
// Decompiled from struct CPersistence *__cdecl CPersistence::New_HACK_VERSION(struct std::istream *stream)
class CPersistence *__cdecl CPersistence::New_HACK_VERSION(std::istream &stream)
{
  unsigned long classId = 0;
  stream >> classId;
  if (stream.fail())
  {
    throw new CPersistence::SerialError();
  }

  // TODO: This is so weird... The hack should not be necessary, as the class ID should be correctly set...

  return new CSquadLeaderRole(stream);
}

// address=[0x14d7f80]
// Decompiled from CPersistence *__thiscall CPersistence::CPersistence(CPersistence *this)
// CPersistence::CPersistence(class CPersistence const &){}

// address=[0x14e4760]
// Decompiled from void *__thiscall CPersistence::operator=(void *this, int a2)
// class CPersistence &CPersistence::operator=(class CPersistence const &a2){}

// address=[0x154edd0]
// Decompiled from CPersistence *__thiscall CPersistence::CPersistence(  CPersistence *this,  const struct boost::exception_detail::clone_base *a2)
// CPersistence::CPersistence(class CPersistence &&a2){}

// address=[0x130e3c0]
// Decompiled from CPersistence *__thiscall CPersistence::CPersistence(CPersistence *this)
// CPersistence::CPersistence(void){}

// address=[0x13eda90]
// Decompiled from char __cdecl CPersistence::LOAD_UINT8(int a1)
unsigned char __cdecl CPersistence::LOAD_UINT8(std::istream &a1)
{
  uint8_t loadedValue;
  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x13edae0]
// Decompiled from __int16 __cdecl CPersistence::LOAD_UINT16(int a1)
unsigned short __cdecl CPersistence::LOAD_UINT16(std::istream &a1)
{
  uint16_t loadedValue;
  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x13edb30]
// Decompiled from int __cdecl CPersistence::LOAD_UINT32(int a1)
unsigned int __cdecl CPersistence::LOAD_UINT32(std::istream &a1)
{
  uint32_t loadedValue;
  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x13edb80]
// Decompiled from char __cdecl CPersistence::LOAD_INT8(int a1)
signed char __cdecl CPersistence::LOAD_INT8(std::istream &a1)
{
  int8_t loadedValue;
  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x13edbd0]
// Decompiled from __int16 __cdecl CPersistence::LOAD_INT16(int a1)
short __cdecl CPersistence::LOAD_INT16(std::istream &a1)
{
  int16_t loadedValue;
  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x13edc20]
// Decompiled from int __cdecl CPersistence::LOAD_INT32(int a1)
int __cdecl CPersistence::LOAD_INT32(std::istream &a1)
{
  int32_t loadedValue;
  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x13edc70]
// Decompiled from int __cdecl CPersistence::LOAD_ID(int a1)
unsigned long __cdecl CPersistence::LOAD_ID(std::istream &a1)
{
  int32_t loadedValue;
  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x13edcc0]
// Decompiled from double __cdecl CPersistence::LOAD_FLOAT64(int a1)
double __cdecl CPersistence::LOAD_FLOAT64(std::istream &a1)
{
  double_t loadedValue;
  static_assert(sizeof(loadedValue) == 8, "Size mismatch");

  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x13edd10]
// Decompiled from double __cdecl CPersistence::LOAD_FLOAT32(int a1)
float __cdecl CPersistence::LOAD_FLOAT32(std::istream &a1)
{
  float_t loadedValue;
  static_assert(sizeof(loadedValue) == 4, "Size mismatch");

  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x13edd60]
// Decompiled from char __cdecl CPersistence::LOAD_char(int a1)
char __cdecl CPersistence::LOAD_char(std::istream &a1)
{
  int8_t loadedValue;
  static_assert(sizeof(loadedValue) == 1, "Size mismatch");

  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x13eddb0]
// Decompiled from int __cdecl CPersistence::LOAD_string(int a1, int a2)
std::string __cdecl CPersistence::LOAD_string(std::istream &a1)
{
  std::string loadedValue;
  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x13ede70]
// Decompiled from char __cdecl CPersistence::LOAD_bool(int a1)
bool __cdecl CPersistence::LOAD_bool(std::istream &a1)
{
  bool loadedValue;
  static_assert(sizeof(loadedValue) == 1, "Size mismatch");

  a1 >> loadedValue;
  if (a1.fail())
    throw new CPersistence::SerialError();

  return loadedValue;
}

// address=[0x3d89400]
// [Decompilation failed for static unsigned long CPersistence::m_iNextClassID]

// address=[0x3efe474]
// [Decompilation failed for static unsigned long CPersistence::m_iClassID]
