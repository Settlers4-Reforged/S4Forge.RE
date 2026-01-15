#include "CGameChunkGeneral.h"

// Definitions for class CGameChunkGeneral

// address=[0x13eb8a0]
// Decompiled from CGameChunkGeneral *__thiscall CGameChunkGeneral::CGameChunkGeneral(CGameChunkGeneral *this)
 CGameChunkGeneral::CGameChunkGeneral(void) {
  
  IS4ChunkObject::IS4ChunkObject(this);
  *(_DWORD *)this = CGameChunkGeneral::_vftable_;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 160) = 0;
  *((_DWORD *)this + 161) = 0;
  *((_DWORD *)this + 330) = 0;
  *((_BYTE *)this + 2348) = 0;
  *((_BYTE *)this + 2356) = 0;
  *((_DWORD *)this + 590) = 0;
  *((_BYTE *)this + 2364) = 0;
  *((_BYTE *)this + 2365) = 0;
  *((_DWORD *)this + 592) = 0;
  *((_BYTE *)this + 2372) = 0;
  *((_DWORD *)this + 594) = 0;
  *((_DWORD *)this + 595) = 0;
  *((_DWORD *)this + 596) = 0;
  *((_DWORD *)this + 597) = 0;
  *((_DWORD *)this + 598) = 0;
  *((_DWORD *)this + 599) = 0;
  *((_DWORD *)this + 600) = 0;
  *((_BYTE *)this + 2404) = 0;
  return this;
}


// address=[0x13eb9f0]
// Decompiled from int __thiscall CGameChunkGeneral::Load(CGameChunkGeneral *this, struct IS4Chunk *a2)
void  CGameChunkGeneral::Load(class IS4Chunk &) {
  
  int result; // eax
  const wchar_t *v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int pExceptionObject; // [esp+4h] [ebp-498h] BYREF
  int i; // [esp+8h] [ebp-494h]
  int v11; // [esp+Ch] [ebp-490h] BYREF
  unsigned __int8 v12; // [esp+13h] [ebp-489h] BYREF
  CGameChunkGeneral *v13; // [esp+14h] [ebp-488h]
  char v14[88]; // [esp+18h] [ebp-484h] BYREF
  int v15[7]; // [esp+70h] [ebp-42Ch] BYREF
  char Str[1024]; // [esp+8Ch] [ebp-410h] BYREF
  int v17; // [esp+498h] [ebp-4h]

  v13 = this;
  memset((char *)this + 1324, 0, 0x400u);
  *((_BYTE *)v13 + 2356) = 0;
  *((_BYTE *)v13 + 2348) = 0;
  memset((char *)v13 + 2349, 0, 7u);
  *((_BYTE *)v13 + 2364) = -1;
  *((_BYTE *)v13 + 2365) = 0;
  *((_DWORD *)v13 + 592) = 0;
  *((_BYTE *)v13 + 2372) = 0;
  *((_DWORD *)v13 + 596) = (char *)&loc_1BB7352 + 1;
  *((_DWORD *)v13 + 597) = 0;
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 761539483);
  v11 = 0;
  result = (**(int (__thiscall ***)(struct IS4Chunk *, int *, int))a2)(a2, &v11, 4);
  if ( v11 >= 3 )
  {
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 4, 4);
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 16, 4);
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 20, 4);
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 24, 4);
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 28, 4);
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 32, 4);
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 36, 64);
    if ( v11 < 10 )
    {
      (**(void (__thiscall ***)(struct IS4Chunk *, char *, int))a2)(a2, Str, 1024);
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v14);
      v17 = 0;
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::from_bytes(
        (int)v15,
        Str);
      v3 = (const wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v15);
      j__wcscpy((wchar_t *)v13 + 50, v3);
      std::wstring::~wstring(v15);
      v17 = -1;
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v14);
    }
    else
    {
      (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 100, 512);
    }
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 612, 26);
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 640, 4);
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 644, 4);
    for ( i = 0; i < 8; ++i )
      CSavedPlayer::Load((CGameChunkGeneral *)((char *)v13 + 84 * i + 648), a2);
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 1320, 4);
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 2360, 4);
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 2376, 4);
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 2380, 4);
    v12 = 0;
    (**(void (__thiscall ***)(struct IS4Chunk *, unsigned __int8 *, int))a2)(a2, &v12, 1);
    if ( v12 >= 0x19u )
    {
      if ( BBSupportDbgReport(1, "LoadSave\\GeneralChunk.cpp", 143, "Load(): Invalid campaign type!") == 1 )
        __debugbreak();
      v12 = 0;
    }
    *((_DWORD *)v13 + 2) = v12;
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 12, 4);
    result = (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 761539484);
  }
  if ( v11 >= 4 )
  {
    (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 2103716763);
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 1324, 1024);
    result = (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1922815076);
  }
  if ( v11 >= 5 )
  {
    (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 224668571);
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 2356, 1);
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 2348, 1);
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 2349, 7);
    result = (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 493104027);
  }
  if ( v11 >= 6 )
  {
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 2364, 1);
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 2365, 1);
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 2368, 4);
    result = (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 493104029);
  }
  if ( v11 >= 7 )
  {
    (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v13 + 2372, 1);
    result = (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 493104030);
  }
  if ( v11 >= 8 )
  {
    v4 = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
    *((_DWORD *)v13 + 596) = v4;
    v5 = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
    *((_DWORD *)v13 + 597) = v5;
    result = (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 493104031);
  }
  if ( v11 >= 9 )
  {
    v6 = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
    *((_DWORD *)v13 + 598) = v6;
    v7 = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
    *((_DWORD *)v13 + 599) = v7;
    v8 = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
    *((_DWORD *)v13 + 600) = v8;
    *((_BYTE *)v13 + 2404) = 1;
    result = (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 493104032);
  }
  if ( v11 >= 1 && v11 <= 10 )
    return result;
  BBSupportTracePrintF(3, "Defect CGameChunkGeneral data!");
  pExceptionObject = 0;
  CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
  _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  return result;
}


// address=[0x13ec060]
// Decompiled from int __thiscall CGameChunkGeneral::Save(CGameChunkGeneral *this, struct IS4Chunk *a2)
void  CGameChunkGeneral::Save(class IS4Chunk &) {
  
  int i; // [esp+0h] [ebp-Ch]
  char v5; // [esp+Bh] [ebp-1h] BYREF

  if ( *((_DWORD *)this + 2) > 0x18u
    && BBSupportDbgReport(
         2,
         "LoadSave\\GeneralChunk.cpp",
         206,
         "m_uCampaneID >= CAMPAIGN_NONE && m_uCampaneID<CAMPAIGN_MAX") == 1 )
  {
    __debugbreak();
  }
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 761539483);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 10);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 4, 4);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 16, 4);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 20, 4);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 24, 4);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 28, 4);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 32, 4);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 36, 64);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 100, 512);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 612, 26);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 640, 4);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 644, 4);
  for ( i = 0; i < 8; ++i )
    CSavedPlayer::Save((CGameChunkGeneral *)((char *)this + 84 * i + 648), a2);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 1320, 4);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 2360, 4);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 2376, 4);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 2380, 4);
  v5 = *((_BYTE *)this + 8);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, &v5, 1);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 12, 4);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 761539484);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 2103716763);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 1324, 1024);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1922815076);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 224668571);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 2356, 1);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 2348, 1);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 2349, 7);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 493104027);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 2364, 1);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 2365, 1);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 2368, 4);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 493104029);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 2372, 1);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 493104030);
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 596));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 597));
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 493104031);
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 598));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 599));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 600));
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 493104032);
}


// address=[0x13ec470]
// Decompiled from CGameChunkGeneral *__thiscall CGameChunkGeneral::GenerateCRC(CGameChunkGeneral *this)
void  CGameChunkGeneral::GenerateCRC(void) {
  
  CGameChunkGeneral *result; // eax
  unsigned int NormalCRC; // [esp+0h] [ebp-14h]
  unsigned int v3; // [esp+0h] [ebp-14h]
  unsigned int i; // [esp+8h] [ebp-Ch]
  _BYTE v6[4]; // [esp+10h] [ebp-4h] BYREF

  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::CRCGenerator<16,32773,0,0,1,1>(v6);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 4, 4);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 16, 4);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 20, 4);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 24, 4);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 28, 4);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 32, 4);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 1320, 4);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 36, 64);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 640, 4);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 644, 4);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 2376, 4);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 2380, 4);
  for ( i = 0; i < *((_DWORD *)this + 161); ++i )
  {
    cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 84 * i + 648, 4);
    cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 84 * i + 716, 4);
    cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 84 * i + 728, 1);
    cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 84 * i + 652, 64);
  }
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 2384, 4);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process((char *)this + 2388, 4);
  NormalCRC = cdm_crc::CRCGenerator<16,32773,0,0,1,1>::GetNormalCRC(v6);
  v3 = NormalCRC >> (32 - cdm_crc::CRCGenerator<16,32773,0,0,1,1>::GetWidth(v6));
  result = this;
  *((_DWORD *)this + 592) = v3;
  return result;
}


