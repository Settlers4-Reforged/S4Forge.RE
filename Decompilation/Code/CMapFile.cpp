#include "CMapFile.h"

// Definitions for class CMapFile

// address=[0x13da7f0]
// Decompiled from struct CMapFile *__thiscall S4::CMapFile::CMapFile(CHandleMap *this, bool a2)
 S4::CMapFile::CMapFile(bool) {
  
  *(_DWORD *)this = &S4::CMapFile::_vftable_;
  *((_BYTE *)this + 4) = 0;
  *((_BYTE *)this + 5) = 0;
  S4::CSaveFile::CSaveFile((CHandleMap *)((char *)this + 8), a2);
  std::wstring::wstring((char *)this + 88);
  *((_DWORD *)this + 29) = 0;
  *((_DWORD *)this + 31) = 0;
  std::map<unsigned int,void *>::map<unsigned int,void *>((char *)this + 128);
  std::map<unsigned int,int>::map<unsigned int,int>((char *)this + 140);
  j__memset((char *)this + 152, 0, 0x400u);
  *((_BYTE *)this + 6) = 0;
  return this;
}


// address=[0x13da8d0]
// Decompiled from void __thiscall S4::CMapFile::~CMapFile(CHandleMap *this)
 S4::CMapFile::~CMapFile(void) {
  
  *(_DWORD *)this = &S4::CMapFile::_vftable_;
  if ( *((_BYTE *)this + 5) )
    S4::CMapFile::Close(this);
  std::map<unsigned int,int>::~map<unsigned int,int>((char *)this + 140);
  std::map<unsigned int,void *>::~map<unsigned int,void *>((char *)this + 128);
  std::wstring::~wstring((char *)this + 88);
  S4::CSaveFile::~CSaveFile((CHandleMap *)((char *)this + 8));
}


// address=[0x13da960]
// Decompiled from S4::CMapFile *__thiscall S4::CMapFile::Open(S4::CMapFile *this, int a2, int a3, char a4)
void  S4::CMapFile::Open(std::wstring const &,int,bool) {
  
  S4::CMapFile *result; // eax
  unsigned int FileSize; // [esp+0h] [ebp-18h]
  int v6; // [esp+4h] [ebp-14h] BYREF
  unsigned int v7; // [esp+8h] [ebp-10h]
  int pExceptionObject; // [esp+Ch] [ebp-Ch] BYREF
  int Buffer; // [esp+10h] [ebp-8h] BYREF
  S4::CMapFile *v10; // [esp+14h] [ebp-4h]

  v10 = this;
  v7 = 0;
  if ( *((_BYTE *)this + 4) && BBSupportDbgReport(2, "LoadSave\\CMapFile.cpp", 143, "! m_bVirtual") == 1 )
    __debugbreak();
  std::wstring::operator=(a2);
  *((_DWORD *)v10 + 30) = a3;
  result = v10;
  *((_BYTE *)v10 + 5) = 1;
  if ( (a3 & 1) != 0 )
  {
    S4::CSaveFile::Open(a2, a3);
    *((_DWORD *)v10 + 29) = S4::CSaveFile::GetFilePos((S4::CMapFile *)((char *)v10 + 8));
    S4::CSaveFile::Read((char *)v10 + 124, 4u);
    S4::CSaveFile::Read(&Buffer, 4u);
    if ( Buffer != 31 && Buffer != 40 )
    {
      S4::CSaveFile::Close((S4::CMapFile *)((char *)v10 + 8));
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    FileSize = S4::CSaveFile::GetFileSize((S4::CMapFile *)((char *)v10 + 8));
    result = (S4::CMapFile *)S4::CSaveFile::SetFilePos(*((_DWORD *)v10 + 29) + 8, 0);
    if ( a4 )
    {
      v7 = S4::CMapFile::FileCRC(v10, *((_DWORD *)v10 + 29) + 8, FileSize);
      result = v10;
      if ( v7 != *((_DWORD *)v10 + 31) )
      {
        S4::CSaveFile::Close((S4::CMapFile *)((char *)v10 + 8));
        v6 = 0;
        CS4InvalidMapException::CS4InvalidMapException(&v6);
        _CxxThrowException(&v6, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
      }
    }
  }
  else if ( (a3 & 2) != 0 )
  {
    S4::CSaveFile::Open(a2, 3);
    Buffer = 31;
    *((_DWORD *)v10 + 29) = S4::CSaveFile::GetFileSize((S4::CMapFile *)((char *)v10 + 8));
    S4::CSaveFile::Write((char *)v10 + 124, 4u);
    return (S4::CMapFile *)S4::CSaveFile::Write(&Buffer, 4u);
  }
  return result;
}


// address=[0x13dab20]
// Decompiled from int __thiscall S4::CMapFile::Close(S4::CMapFile *this)
void  S4::CMapFile::Close(void) {
  
  _BYTE v2[12]; // [esp+4h] [ebp-54h] BYREF
  _BYTE v3[12]; // [esp+10h] [ebp-48h] BYREF
  _BYTE v4[12]; // [esp+1Ch] [ebp-3Ch] BYREF
  unsigned int Buffer; // [esp+28h] [ebp-30h] BYREF
  unsigned int FileSize; // [esp+2Ch] [ebp-2Ch]
  void *C; // [esp+30h] [ebp-28h]
  std::_Iterator_base12 *v8; // [esp+34h] [ebp-24h]
  std::_Iterator_base12 *v9; // [esp+38h] [ebp-20h]
  int v10; // [esp+3Ch] [ebp-1Ch]
  int v11; // [esp+40h] [ebp-18h]
  S4::CMapFile *v12; // [esp+44h] [ebp-14h]
  char v13; // [esp+4Bh] [ebp-Dh]
  int v14; // [esp+54h] [ebp-4h]

  v12 = this;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>(v4);
  v14 = 0;
  v11 = std::_Tree<std::_Tmap_traits<unsigned int,void *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,void *>>,0>>::begin(v3);
  v10 = v11;
  LOBYTE(v14) = 1;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::operator=(v11);
  LOBYTE(v14) = 0;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>(v3);
  while ( 1 )
  {
    v9 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned int,void *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,void *>>,0>>::end(v2);
    v8 = v9;
    LOBYTE(v14) = 2;
    v13 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::operator!=(v9);
    LOBYTE(v14) = 0;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>(v2);
    if ( !v13 )
      break;
    C = *(void **)(std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::operator->(v4)
                 + 4);
    operator delete[](C);
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::operator++(v4);
  }
  std::_Tree<std::_Tmap_traits<unsigned int,void *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,void *>>,0>>::clear();
  std::_Tree<std::_Tmap_traits<unsigned int,int,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,int>>,0>>::clear();
  if ( *((_DWORD *)v12 + 30) == 2 )
  {
    FileSize = S4::CSaveFile::GetFileSize((S4::CMapFile *)((char *)v12 + 8));
    S4::CSaveFile::SetFilePos(*((_DWORD *)v12 + 29) + 8, 0);
    Buffer = S4::CMapFile::FileCRC(v12, *((_DWORD *)v12 + 29) + 8, FileSize);
    S4::CSaveFile::SetFilePos(*((_DWORD *)v12 + 29), 0);
    S4::CSaveFile::Write(&Buffer, 4u);
  }
  S4::CSaveFile::Close((S4::CMapFile *)((char *)v12 + 8));
  *((_BYTE *)v12 + 4) = 0;
  *((_DWORD *)v12 + 31) = 0;
  *((_BYTE *)v12 + 5) = 0;
  j__memset((char *)v12 + 152, 0, 0x400u);
  v14 = -1;
  return std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>(v4);
}


// address=[0x13dace0]
// Decompiled from S4::CMapFile *__thiscall S4::CMapFile::Virtualize(S4::CMapFile *this)
void  S4::CMapFile::Virtualize(void) {
  
  S4::CMapFile *result; // eax

  if ( *((_BYTE *)this + 4) && BBSupportDbgReport(2, "LoadSave\\CMapFile.cpp", 243, "! m_bVirtual") == 1 )
    __debugbreak();
  result = this;
  *((_BYTE *)this + 4) = 1;
  return result;
}


// address=[0x13dad20]
// Decompiled from int __thiscall S4::CMapFile::GetChecksum(S4::CMapFile *this)
unsigned int  S4::CMapFile::GetChecksum(void)const {
  
  return *((_DWORD *)this + 31);
}


// address=[0x13dad40]
// Decompiled from void *__thiscall S4::CMapFile::LoadChunk(S4::CMapFile *this, unsigned __int16 a2, unsigned __int16 a3)
void const *  S4::CMapFile::LoadChunk(unsigned int,unsigned int) {
  
  int v4; // [esp+4h] [ebp-4h] BYREF

  v4 = 0;
  return S4::CMapFile::LoadChunk(this, a2, a3, &v4, 0);
}


// address=[0x13dad70]
// Decompiled from void *__thiscall S4::CMapFile::LoadChunk(  S4::CMapFile *this,  unsigned __int16 a2,  unsigned __int16 a3,  int *a4,  size_t *a5)
void const *  S4::CMapFile::LoadChunk(unsigned short,unsigned short,int &,int *) {
  
  void **v6; // eax
  std::_Iterator_base12 *v7; // [esp-4h] [ebp-11Ch]
  std::_Iterator_base12 *v8; // [esp-4h] [ebp-11Ch]
  std::_Iterator_base12 *v9; // [esp-4h] [ebp-11Ch]
  _BYTE v10[12]; // [esp+4h] [ebp-114h] BYREF
  _BYTE v11[12]; // [esp+10h] [ebp-108h] BYREF
  _BYTE v12[12]; // [esp+1Ch] [ebp-FCh] BYREF
  _BYTE v13[12]; // [esp+28h] [ebp-F0h] BYREF
  _BYTE v14[12]; // [esp+34h] [ebp-E4h] BYREF
  _BYTE v15[12]; // [esp+40h] [ebp-D8h] BYREF
  void *v16; // [esp+4Ch] [ebp-CCh]
  void *v17; // [esp+50h] [ebp-C8h]
  void *v18; // [esp+54h] [ebp-C4h]
  size_t v20; // [esp+5Ch] [ebp-BCh]
  char *v21; // [esp+60h] [ebp-B8h]
  std::_Iterator_base12 *v22; // [esp+64h] [ebp-B4h]
  void *v23; // [esp+68h] [ebp-B0h]
  unsigned int v24; // [esp+6Ch] [ebp-ACh]
  void *C; // [esp+70h] [ebp-A8h]
  int v26; // [esp+74h] [ebp-A4h]
  void *v27; // [esp+78h] [ebp-A0h]
  int v28; // [esp+7Ch] [ebp-9Ch]
  int v29; // [esp+80h] [ebp-98h]
  std::_Iterator_base12 *v30; // [esp+84h] [ebp-94h]
  std::_Iterator_base12 *v31; // [esp+88h] [ebp-90h]
  int v32; // [esp+90h] [ebp-88h]
  int v33; // [esp+94h] [ebp-84h]
  std::_Iterator_base12 *v34; // [esp+98h] [ebp-80h]
  std::_Iterator_base12 *v35; // [esp+9Ch] [ebp-7Ch]
  int v36; // [esp+A0h] [ebp-78h]
  int v37; // [esp+A4h] [ebp-74h]
  std::_Iterator_base12 *v38; // [esp+A8h] [ebp-70h]
  int v39; // [esp+ACh] [ebp-6Ch]
  int v40; // [esp+B0h] [ebp-68h] BYREF
  size_t v41; // [esp+B4h] [ebp-64h] BYREF
  int pExceptionObject; // [esp+B8h] [ebp-60h] BYREF
  BOOL v43; // [esp+BCh] [ebp-5Ch]
  _DWORD *v44; // [esp+C0h] [ebp-58h]
  BOOL v45; // [esp+C4h] [ebp-54h]
  size_t v46; // [esp+C8h] [ebp-50h] BYREF
  int v47; // [esp+CCh] [ebp-4Ch]
  int v48; // [esp+D0h] [ebp-48h]
  void *v49; // [esp+D4h] [ebp-44h]
  size_t Size; // [esp+D8h] [ebp-40h]
  char v51; // [esp+DDh] [ebp-3Bh]
  bool v52; // [esp+DEh] [ebp-3Ah]
  bool v53; // [esp+DFh] [ebp-39h]
  int v54; // [esp+E0h] [ebp-38h] BYREF
  void *Src; // [esp+E4h] [ebp-34h]
  S4::CMapFile *v56; // [esp+E8h] [ebp-30h]
  int v57; // [esp+ECh] [ebp-2Ch]
  _WORD Buffer[2]; // [esp+F0h] [ebp-28h] BYREF
  size_t ElementSize; // [esp+F4h] [ebp-24h]
  size_t v60; // [esp+F8h] [ebp-20h]
  int v61; // [esp+FCh] [ebp-1Ch]
  int v62; // [esp+104h] [ebp-14h]
  int v63; // [esp+114h] [ebp-4h]

  v56 = this;
  v57 = 0;
  v54 = a2 + (a3 << 16);
  v22 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned int,int,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,int>>,0>>::end(v15);
  v38 = v22;
  v63 = 0;
  v7 = v22;
  v37 = std::_Tree<std::_Tmap_traits<unsigned int,int,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,int>>,0>>::find(
          v10,
          &v54);
  v36 = v37;
  LOBYTE(v63) = 1;
  v51 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>::operator!=(v7);
  LOBYTE(v63) = 0;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>(v10);
  v63 = -1;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>(v15);
  if ( v51 )
  {
    v35 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned int,void *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,void *>>,0>>::end(v13);
    v34 = v35;
    v63 = 2;
    v57 |= 1u;
    v8 = v35;
    v33 = std::_Tree<std::_Tmap_traits<unsigned int,void *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,void *>>,0>>::find(
            v14,
            &v54);
    v32 = v33;
    v63 = 3;
    v57 |= 2u;
    v45 = !(unsigned __int8)std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::operator!=(v8)
       && BBSupportDbgReport(
            2,
            "LoadSave\\CMapFile.cpp",
            269,
            "vLoadedChunks.find(uRequestedType) != vLoadedChunks.end()") == 1;
    v53 = v45;
    v63 = 2;
    if ( (v57 & 2) != 0 )
    {
      v57 &= ~2u;
      std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>(v14);
    }
    v63 = -1;
    if ( (v57 & 1) != 0 )
    {
      v57 &= ~1u;
      std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>(v13);
    }
    if ( v53 )
      __debugbreak();
    v44 = (_DWORD *)std::map<unsigned int,int>::operator[](&v54);
    ++*v44;
    if ( a2 < 0x100u && !a3 )
      *a4 = *((_DWORD *)v56 + a2 + 38);
    return *(void **)std::map<unsigned int,void *>::operator[](&v54);
  }
  else
  {
    v49 = 0;
    if ( *((_BYTE *)v56 + 4) )
      return v49;
    v31 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned int,void *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,void *>>,0>>::end(v11);
    v30 = v31;
    v63 = 4;
    v57 |= 4u;
    v9 = v31;
    v29 = std::_Tree<std::_Tmap_traits<unsigned int,void *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,void *>>,0>>::find(
            v12,
            &v54);
    v28 = v29;
    v63 = 5;
    v57 |= 8u;
    v43 = !(unsigned __int8)std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::operator==(v9)
       && BBSupportDbgReport(
            2,
            "LoadSave\\CMapFile.cpp",
            287,
            "vLoadedChunks.find(uRequestedType) == vLoadedChunks.end()") == 1;
    v52 = v43;
    v63 = 4;
    if ( (v57 & 8) != 0 )
    {
      v57 &= ~8u;
      std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>(v12);
    }
    v63 = -1;
    if ( (v57 & 4) != 0 )
    {
      v57 &= ~4u;
      std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>(v11);
    }
    if ( v52 )
      __debugbreak();
    Src = 0;
    v48 = 0;
    v47 = 0;
    S4::CSaveFile::SetFilePos(*((_DWORD *)v56 + 29) + 8, 0);
    do
    {
      v48 = S4::CSaveFile::Read(Buffer, 0x18u);
      S4::CMapFile::Cryption(v56, Buffer, 0x18u);
      v47 = Buffer[0] + (Buffer[1] << 16);
      if ( v48 == 24 && v47 == v54 )
      {
        v27 = operator new[](ElementSize);
        Src = v27;
        v26 = S4::CSaveFile::Read(v27, ElementSize);
        if ( v26 != ElementSize )
        {
          C = Src;
          operator delete[](Src);
          Src = 0;
        }
      }
      else if ( v48 == 24 )
      {
        S4::CSaveFile::SetFilePos(ElementSize, 1);
      }
    }
    while ( !S4::CSaveFile::Eof((S4::CMapFile *)((char *)v56 + 8)) && v48 == 24 && v47 != v54 );
    if ( !Src )
      return 0;
    *a4 = v62;
    v24 = S4::CMapFile::Crc(v56, Src, ElementSize);
    if ( v24 != v61 )
    {
      BBSupportTracePrintF(3, "Invalid chunk CRC!");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    Size = 0;
    if ( v60 == -1 )
    {
      Size = ElementSize;
      v18 = operator new[](ElementSize);
      v49 = v18;
      j__memcpy(v18, Src, Size);
    }
    else
    {
      Size = v60;
      v23 = operator new[](v60);
      v49 = v23;
      v16 = Src;
      v41 = v60;
      v46 = ElementSize;
      v20 = (size_t)v23 + v60;
      v21 = (char *)Src + ElementSize;
      v39 = j__LZHLCreateDecompressor();
      do
      {
        if ( !j__LZHLDecompress(v39, (void *)(v20 - v41), &v41, &v21[-v46], &v46) )
        {
          BBSupportTracePrintF(3, "Decompression of chunk failed!");
          v40 = 0;
          CS4InvalidMapException::CS4InvalidMapException(&v40);
          _CxxThrowException(&v40, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
        }
      }
      while ( v46 );
      j__LZHLDestroyDecompressor(v39);
    }
    if ( a5 )
      *a5 = Size;
    if ( Src )
    {
      v17 = Src;
      operator delete[](Src);
      Src = 0;
    }
    v6 = (void **)std::map<unsigned int,void *>::operator[](&v54);
    *v6 = v49;
    *(_DWORD *)std::map<unsigned int,int>::operator[](&v54) = 1;
    return v49;
  }
}


// address=[0x13db3e0]
// Decompiled from _DWORD *__thiscall S4::CMapFile::CloseChunk(S4::CMapFile *this, unsigned __int16 a2, unsigned __int16 a3)
void  S4::CMapFile::CloseChunk(unsigned short,unsigned short) {
  
  _DWORD *result; // eax
  std::_Iterator_base12 *v4; // [esp-4h] [ebp-80h]
  std::_Iterator_base12 *v5; // [esp-4h] [ebp-80h]
  _BYTE v6[12]; // [esp+4h] [ebp-78h] BYREF
  _BYTE v7[12]; // [esp+10h] [ebp-6Ch] BYREF
  _BYTE v8[12]; // [esp+1Ch] [ebp-60h] BYREF
  _BYTE v9[12]; // [esp+28h] [ebp-54h] BYREF
  void *C; // [esp+34h] [ebp-48h]
  int v11; // [esp+38h] [ebp-44h]
  int v12; // [esp+3Ch] [ebp-40h]
  std::_Iterator_base12 *v13; // [esp+40h] [ebp-3Ch]
  std::_Iterator_base12 *v14; // [esp+44h] [ebp-38h]
  int v15; // [esp+48h] [ebp-34h]
  int v16; // [esp+4Ch] [ebp-30h]
  std::_Iterator_base12 *v17; // [esp+50h] [ebp-2Ch]
  std::_Iterator_base12 *v18; // [esp+54h] [ebp-28h]
  _DWORD *v19; // [esp+58h] [ebp-24h]
  BOOL v20; // [esp+5Ch] [ebp-20h]
  _DWORD v21[2]; // [esp+60h] [ebp-1Ch] BYREF
  int v22; // [esp+68h] [ebp-14h]
  bool v23; // [esp+6Eh] [ebp-Eh]
  char v24; // [esp+6Fh] [ebp-Dh]
  int v25; // [esp+78h] [ebp-4h]

  v21[1] = this;
  v22 = 0;
  v21[0] = a2 + (a3 << 16);
  v18 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned int,int,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,int>>,0>>::end(v8);
  v17 = v18;
  v25 = 0;
  v4 = v18;
  v16 = std::_Tree<std::_Tmap_traits<unsigned int,int,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,int>>,0>>::find(
          v9,
          v21);
  v15 = v16;
  LOBYTE(v25) = 1;
  v24 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>::operator!=(v4);
  LOBYTE(v25) = 0;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>(v9);
  v25 = -1;
  result = (_DWORD *)std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>(v8);
  if ( !v24 )
    return result;
  v14 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned int,void *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,void *>>,0>>::end(v6);
  v13 = v14;
  v25 = 2;
  v22 |= 1u;
  v5 = v14;
  v12 = std::_Tree<std::_Tmap_traits<unsigned int,void *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,void *>>,0>>::find(
          v7,
          v21);
  v11 = v12;
  v25 = 3;
  v22 |= 2u;
  v20 = !(unsigned __int8)std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::operator!=(v5)
     && BBSupportDbgReport(2, "LoadSave\\CMapFile.cpp", 446, "vLoadedChunks.find(requestedtype) != vLoadedChunks.end()") == 1;
  v23 = v20;
  v25 = 2;
  if ( (v22 & 2) != 0 )
  {
    v22 &= ~2u;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>(v7);
  }
  v25 = -1;
  if ( (v22 & 1) != 0 )
  {
    v22 &= ~1u;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>(v6);
  }
  if ( v23 )
    __debugbreak();
  if ( *(int *)std::map<unsigned int,int>::operator[](v21) < 1
    && BBSupportDbgReport(2, "LoadSave\\CMapFile.cpp", 447, "vRefCounts [requestedtype] >= 1") == 1 )
  {
    __debugbreak();
  }
  v19 = (_DWORD *)std::map<unsigned int,int>::operator[](v21);
  --*v19;
  result = (_DWORD *)std::map<unsigned int,int>::operator[](v21);
  if ( *result )
    return result;
  C = *(void **)std::map<unsigned int,void *>::operator[](v21);
  operator delete[](C);
  std::_Tree<std::_Tmap_traits<unsigned int,void *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,void *>>,0>>::erase(v21);
  return (_DWORD *)std::_Tree<std::_Tmap_traits<unsigned int,int,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,int>>,0>>::erase(v21);
}


// address=[0x13db650]
// Decompiled from void **__thiscall S4::CMapFile::UploadBuffer(void **this, unsigned int a2, int a3, void *Src, size_t Size, void *a6)
void  S4::CMapFile::UploadBuffer(unsigned int,unsigned int,void const *,unsigned int,int) {
  
  void **result; // eax
  int v7; // eax
  int v8; // eax
  std::_Iterator_base12 *v9; // [esp-4h] [ebp-8Ch]
  _BYTE v10[16]; // [esp+4h] [ebp-84h] BYREF
  _BYTE v11[16]; // [esp+14h] [ebp-74h] BYREF
  _BYTE v12[12]; // [esp+24h] [ebp-64h] BYREF
  _BYTE v13[12]; // [esp+30h] [ebp-58h] BYREF
  int v14; // [esp+4Ch] [ebp-3Ch] BYREF
  void *C; // [esp+50h] [ebp-38h]
  int v16; // [esp+54h] [ebp-34h]
  int v17; // [esp+58h] [ebp-30h]
  std::_Iterator_base12 *v18; // [esp+5Ch] [ebp-2Ch]
  std::_Iterator_base12 *v19; // [esp+60h] [ebp-28h]
  void *v20; // [esp+64h] [ebp-24h]
  _DWORD *v21; // [esp+68h] [ebp-20h]
  void *v22; // [esp+6Ch] [ebp-1Ch] BYREF
  unsigned int v23; // [esp+70h] [ebp-18h] BYREF
  void **v24; // [esp+74h] [ebp-14h]
  char v25; // [esp+7Bh] [ebp-Dh]
  int v26; // [esp+84h] [ebp-4h]

  v24 = this;
  v23 = a2 + (a3 << 16);
  v20 = operator new[](Size);
  v22 = v20;
  j__memcpy(v20, Src, Size);
  v19 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned int,int,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,int>>,0>>::end(v12);
  v18 = v19;
  v26 = 0;
  v9 = v19;
  v17 = std::_Tree<std::_Tmap_traits<unsigned int,int,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,int>>,0>>::find(
          v13,
          &v23);
  v16 = v17;
  LOBYTE(v26) = 1;
  v25 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>::operator!=(v9);
  LOBYTE(v26) = 0;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>(v13);
  v26 = -1;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>(v12);
  if ( v25 )
  {
    C = *(void **)std::map<unsigned int,void *>::operator[](&v23);
    operator delete[](C);
    v21 = (_DWORD *)std::map<unsigned int,int>::operator[](&v23);
    ++*v21;
    result = (void **)std::map<unsigned int,void *>::operator[](&v23);
    *result = v22;
    if ( a2 < 0x100 && !a3 )
    {
      result = v24;
      v24[a2 + 38] = a6;
    }
  }
  else
  {
    v14 = 1;
    v7 = std::pair<unsigned int const,int>::pair<unsigned int const,int>(&v23, &v14);
    std::_Tree<std::_Tmap_traits<unsigned int,int,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,int>>,0>>::insert<0,0>(
      v11,
      v7);
    std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>,bool>(v11);
    v8 = std::pair<unsigned int const,void *>::pair<unsigned int const,void *>(&v23, &v22);
    std::_Tree<std::_Tmap_traits<unsigned int,void *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,void *>>,0>>::insert<0,0>(
      v10,
      v8);
    return (void **)std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>,bool>(v10);
  }
  return result;
}


// address=[0x13db820]
// Decompiled from int __thiscall S4::CMapFile::SaveChunk(  S4::CMapFile *this,  __int16 a2,  __int16 a3,  size_t Size,  void *Src,  unsigned __int8 a6)
void  S4::CMapFile::SaveChunk(unsigned short,unsigned short,unsigned int,void const *,bool) {
  
  unsigned int v6; // eax
  int v8; // [esp+10h] [ebp-34h]
  size_t v9; // [esp+14h] [ebp-30h]
  size_t ElementSize; // [esp+18h] [ebp-2Ch]
  void *v12; // [esp+20h] [ebp-24h]
  _WORD Buffer[2]; // [esp+28h] [ebp-1Ch] BYREF
  size_t v14; // [esp+2Ch] [ebp-18h]
  size_t v15; // [esp+30h] [ebp-14h]
  unsigned int v16; // [esp+34h] [ebp-10h]
  int v17; // [esp+38h] [ebp-Ch]

  if ( !Src )
  {
    Size = 0;
    Src = &unk_369A12A;
  }
  if ( a6 | *((_BYTE *)this + 6) )
  {
    v8 = j__LZHLCompressorCalcMaxBuf(Size) + 32;
    v12 = operator new[](v8);
    ElementSize = sub_13DBDF0((int)v12, Src, Size);
    v9 = Size;
    v6 = S4::CMapFile::Crc(this, v12, ElementSize);
  }
  else
  {
    v12 = operator new[](Size);
    j__memcpy(v12, Src, Size);
    ElementSize = Size;
    v9 = -1;
    v6 = S4::CMapFile::Crc(this, v12, Size);
  }
  Buffer[0] = a2;
  Buffer[1] = a3;
  v14 = ElementSize;
  v15 = v9;
  v16 = v6;
  v17 = 0;
  S4::CMapFile::Cryption(this, Buffer, 0x18u);
  S4::CSaveFile::SetFilePos(0, 2);
  S4::CSaveFile::Write(Buffer, 0x18u);
  S4::CSaveFile::Write(v12, ElementSize);
  return operator delete[](v12);
}


// address=[0x13db990]
// Decompiled from char __thiscall S4::CMapFile::LoadChunkObject(  S4::CMapFile *this,  unsigned __int16 a2,  unsigned __int16 a3,  void (__thiscall ***a4)(_DWORD, _BYTE *),  int a5)
bool  S4::CMapFile::LoadChunkObject(unsigned short,unsigned short,class IS4ChunkObject &,enum T_S4_MAP_CHUNK_STATUS) {
  
  _BYTE v6[28]; // [esp+4h] [ebp-48h] BYREF
  S4::CMapFile *v7; // [esp+20h] [ebp-2Ch]
  int v8; // [esp+24h] [ebp-28h] BYREF
  int pExceptionObject; // [esp+28h] [ebp-24h] BYREF
  const void *chunkData; // [esp+2Ch] [ebp-20h]
  BOOL v11; // [esp+30h] [ebp-1Ch]
  BOOL v12; // [esp+34h] [ebp-18h]
  int chunkSize; // [esp+38h] [ebp-14h] BYREF
  char v14; // [esp+3Fh] [ebp-Dh]
  int v15; // [esp+48h] [ebp-4h]

  v7 = this;
  v8 = 0;
  chunkSize = 0;
  chunkData = S4::CMapFile::LoadChunk(this, a2, a3, &v8, &chunkSize);
  v12 = chunkData != 0;
  v11 = chunkSize > 0;
  if ( v11 && v12 )
  {
    CS4MemChunk::CS4MemChunk((CS4MemChunk *)v6);
    v15 = 0;
    CS4MemChunk::InitLoadData((CS4MemChunk *)v6, chunkData, chunkSize);
    (**a4)(a4, v6);
    v14 = 1;
    v15 = -1;
    CS4MemChunk::~CS4MemChunk((CS4MemChunk *)v6);
    return v14;
  }
  else
  {
    if ( a5 )
      return 0;
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    return 0;
  }
}


// address=[0x13dbaa0]
// Decompiled from void __thiscall S4::CMapFile::SaveChunkObject(  S4::CMapFile *this,  __int16 a2,  __int16 a3,  struct IS4ChunkObject *a4,  char a5)
void  S4::CMapFile::SaveChunkObject(unsigned short,unsigned short,class IS4ChunkObject &,bool) {
  
  size_t v5; // eax
  void *v6; // [esp-Ch] [ebp-3Ch]
  _BYTE v7[28]; // [esp+4h] [ebp-2Ch] BYREF
  S4::CMapFile *v8; // [esp+20h] [ebp-10h]
  int v9; // [esp+2Ch] [ebp-4h]

  v8 = this;
  CS4MemChunk::CS4MemChunk((CS4MemChunk *)v7);
  v9 = 0;
  CS4MemChunk::InitSaveCalcSize((CS4MemChunk *)v7);
  (*(void (__thiscall **)(struct IS4ChunkObject *, _BYTE *))(*(_DWORD *)a4 + 4))(a4, v7);
  CS4MemChunk::InitSaveData((CS4MemChunk *)v7, 1);
  (*(void (__thiscall **)(struct IS4ChunkObject *, _BYTE *))(*(_DWORD *)a4 + 4))(a4, v7);
  v6 = (void *)CS4MemChunk::Data((pairNode *)v7);
  v5 = CS4MemChunk::Size((CS4MemChunk *)v7);
  S4::CMapFile::SaveChunk(a2, a3, v5, v6, a5);
  v9 = -1;
  CS4MemChunk::~CS4MemChunk((CS4MemChunk *)v7);
}


// address=[0x13dbb60]
// Decompiled from int __thiscall S4::CMapFile::SaveDbgInfoChunk(S4::CMapFile *this, const char *a2)
void  S4::CMapFile::SaveDbgInfoChunk(char const *) {
  
  int i; // [esp+8h] [ebp-28h]
  _BYTE Src[32]; // [esp+Ch] [ebp-24h] BYREF

  j__memset(Src, 32, sizeof(Src));
  memset(Src, 33, 4);
  if ( a2 )
  {
    for ( i = 0; i < 20 && a2[i]; ++i )
      Src[i + 8] = a2[i];
  }
  return S4::CMapFile::SaveChunk(250, 0, 0x20u, Src, 0);
}


// address=[0x13dbc20]
// Decompiled from void __thiscall S4::CMapFile::Cryption(S4::CMapFile *this, unsigned __int8 *a2, unsigned int a3)
void  S4::CMapFile::Cryption(void *,unsigned int) {
  
  unsigned int i; // [esp+14h] [ebp-7Ch]
  _BYTE v4[76]; // [esp+18h] [ebp-78h] BYREF
  _BYTE v5[28]; // [esp+64h] [ebp-2Ch] BYREF
  int v6; // [esp+8Ch] [ebp-4h]

  Cryptor::Cryptor((Cryptor *)v4);
  v6 = 0;
  std::string::string(v5, "01234567890123456789");
  LOBYTE(v6) = 1;
  Cryptor::Set_Key(v5);
  for ( i = 0; i < a3; ++i )
    Cryptor::Transform_Char((Cryptor *)v4, &a2[i]);
  LOBYTE(v6) = 0;
  std::string::~string(v5);
  v6 = -1;
  Cryptor::~Cryptor((Cryptor *)v4);
}


// address=[0x13dbd00]
// Decompiled from unsigned int __thiscall S4::CMapFile::Crc(S4::CMapFile *this, void *a2, unsigned int a3)
unsigned int  S4::CMapFile::Crc(void *,unsigned int) {
  
  unsigned int NormalCRC; // [esp+8h] [ebp-8h]
  _BYTE v5[4]; // [esp+Ch] [ebp-4h] BYREF

  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::CRCGenerator<16,32773,0,0,1,1>(v5);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process(a2, a3);
  NormalCRC = cdm_crc::CRCGenerator<16,32773,0,0,1,1>::GetNormalCRC(v5);
  return NormalCRC >> (32 - cdm_crc::CRCGenerator<16,32773,0,0,1,1>::GetWidth(v5));
}


// address=[0x13dbd60]
// Decompiled from unsigned int __thiscall S4::CMapFile::FileCRC(S4::CMapFile *this, int a2, int a3)
unsigned int  S4::CMapFile::FileCRC(int,int) {
  
  unsigned int NormalCRC; // [esp+0h] [ebp-10h]
  _BYTE v5[4]; // [esp+4h] [ebp-Ch] BYREF
  S4::CMapFile *v6; // [esp+8h] [ebp-8h]
  char Buffer; // [esp+Fh] [ebp-1h] BYREF

  v6 = this;
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::CRCGenerator<16,32773,0,0,1,1>(v5);
  while ( a2 < a3 )
  {
    S4::CSaveFile::Read(&Buffer, 1u);
    ++a2;
    cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process(Buffer);
  }
  S4::CSaveFile::SetFilePos(*((_DWORD *)v6 + 29), 0);
  NormalCRC = cdm_crc::CRCGenerator<16,32773,0,0,1,1>::GetNormalCRC(v5);
  return NormalCRC >> (32 - cdm_crc::CRCGenerator<16,32773,0,0,1,1>::GetWidth(v5));
}


