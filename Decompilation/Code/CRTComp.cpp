#include "CRTComp.h"

// Definitions for class CRTComp

// address=[0x2fcd4a0]
// Decompiled from CRTComp *__thiscall CRTComp::CRTComp(CRTComp *this)

 CRTComp::CRTComp(void) {
  
  IRTComp::IRTComp(this);
  *(_DWORD *)this = &CRTComp::_vftable_;
  j__memset((char *)this + 4, 0, 0x4Cu);
  return this;
}


// address=[0x2fcd4e0]
// Decompiled from // public: __thiscall CRTComp::~CRTComp(void)
void __thiscall CRTComp::_CRTComp(void **this)

 CRTComp::~CRTComp(void) {
  
  *this = &CRTComp::_vftable_;
  if ( this[1] )
    operator delete(this[1]);
  if ( this[2] )
    operator delete(this[2]);
}


// address=[0x2fcd540]
// Decompiled from int __thiscall CRTComp::SetWorkPath(void **this, wchar_t *String)

enum RTCOMP_ERROR  CRTComp::SetWorkPath(wchar_t *) {
  
  size_t v3; // [esp+8h] [ebp-80Ch]
  WCHAR Buffer[1024]; // [esp+10h] [ebp-804h] BYREF

  if ( !String )
    return 1;
  v3 = j__wcslen(String);
  if ( !v3 )
    return 1;
  GetCurrentDirectoryW(0x400u, Buffer);
  if ( !SetCurrentDirectoryW(String) )
    return 1;
  SetCurrentDirectoryW(Buffer);
  if ( this[1] )
    operator delete[](this[1]);
  this[1] = operator new[](2 * (v3 + 1));
  j__wcscpy((wchar_t *)this[1], String);
  return 0;
}


// address=[0x2fcd650]
// Decompiled from int __thiscall CRTComp::SetPlayerColors(_BYTE *this, int a2)

enum RTCOMP_ERROR  CRTComp::SetPlayerColors(struct SCOLOR * const) {
  
  int v2; // ecx
  int v3; // edx
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 8; ++i )
  {
    v2 = a2 + 3 * i;
    v3 = (int)&this[3 * i + 12];
    *(_WORD *)v3 = *(_WORD *)v2;
    *(_BYTE *)(v3 + 2) = *(_BYTE *)(v2 + 2);
  }
  this[36] = 1;
  return 0;
}


// address=[0x2fcd6a0]
// Decompiled from int __thiscall CRTComp::Compile(CRTComp *this, int a2)

enum RTCOMP_ERROR  CRTComp::Compile(int) {
  
  FILE *v3; // eax
  FILE *v4; // eax
  FILE *v5; // eax
  FILE *v6; // eax
  FILE *v7; // eax
  FILE *v8; // eax
  FILE *v9; // eax
  FILE *v10; // eax
  FILE *v11; // eax
  FILE *v12; // eax
  _BYTE v13[80]; // [esp+8h] [ebp-A60h] BYREF
  SM_SIV_PaletteBlock *v14; // [esp+58h] [ebp-A10h]
  int v15; // [esp+5Ch] [ebp-A0Ch]
  int v16; // [esp+60h] [ebp-A08h]
  int v17; // [esp+64h] [ebp-A04h]
  int v18; // [esp+68h] [ebp-A00h]
  int v19; // [esp+6Ch] [ebp-9FCh]
  void *v20; // [esp+70h] [ebp-9F8h]
  SM_SIV_PaletteBlock *v21; // [esp+74h] [ebp-9F4h]
  void *v22; // [esp+78h] [ebp-9F0h]
  SM_SIV_PaletteBlock *v23; // [esp+7Ch] [ebp-9ECh]
  void *v24; // [esp+80h] [ebp-9E8h]
  SM_SIV_PaletteBlock *v25; // [esp+84h] [ebp-9E4h]
  void *v26; // [esp+88h] [ebp-9E0h]
  SM_SIV_PaletteBlock *v27; // [esp+8Ch] [ebp-9DCh]
  SM_SIV_PaletteBlock *v28; // [esp+90h] [ebp-9D8h]
  void *v29; // [esp+94h] [ebp-9D4h]
  SM_SIV_PaletteBlock *v30; // [esp+98h] [ebp-9D0h]
  void *v31; // [esp+9Ch] [ebp-9CCh]
  SM_SIV_PaletteBlock *v32; // [esp+A0h] [ebp-9C8h]
  void *v33; // [esp+A4h] [ebp-9C4h]
  SM_SIV_PaletteBlock *v34; // [esp+A8h] [ebp-9C0h]
  SM_SIV_PaletteBlock *v35; // [esp+ACh] [ebp-9BCh]
  SM_SIV_PaletteBlock *v36; // [esp+B0h] [ebp-9B8h]
  SM_SIV_PaletteBlock *v37; // [esp+B4h] [ebp-9B4h]
  void *v38; // [esp+B8h] [ebp-9B0h]
  unsigned __int8 *v39; // [esp+BCh] [ebp-9ACh]
  int v40; // [esp+C0h] [ebp-9A8h]
  SM_SIV_PaletteBlock *v41; // [esp+C4h] [ebp-9A4h]
  void *v42; // [esp+C8h] [ebp-9A0h]
  SM_SIV_PaletteBlock *v43; // [esp+CCh] [ebp-99Ch]
  void *v44; // [esp+D0h] [ebp-998h]
  SM_SIV_PaletteBlock *v45; // [esp+D4h] [ebp-994h]
  SM_SIV_PaletteBlock *v46; // [esp+D8h] [ebp-990h]
  SM_SIV_PaletteBlock *v47; // [esp+DCh] [ebp-98Ch]
  SM_SIV_PaletteBlock *v48; // [esp+E0h] [ebp-988h]
  void *v49; // [esp+E4h] [ebp-984h]
  SM_SIV_PaletteBlock *v50; // [esp+E8h] [ebp-980h]
  void *v51; // [esp+ECh] [ebp-97Ch]
  SM_SIV_PaletteBlock *v52; // [esp+F0h] [ebp-978h]
  void *v53; // [esp+F4h] [ebp-974h]
  SM_SIV_PaletteBlock *v54; // [esp+F8h] [ebp-970h]
  SM_SIV_PaletteBlock *v55; // [esp+FCh] [ebp-96Ch]
  SM_SIV_PaletteBlock *v56; // [esp+100h] [ebp-968h]
  SM_SIV_PaletteBlock *v57; // [esp+104h] [ebp-964h]
  void *C; // [esp+108h] [ebp-960h]
  unsigned __int8 *v59; // [esp+10Ch] [ebp-95Ch]
  int v60; // [esp+110h] [ebp-958h]
  unsigned __int8 *v61; // [esp+114h] [ebp-954h]
  int v62; // [esp+118h] [ebp-950h]
  int v63; // [esp+11Ch] [ebp-94Ch]
  int v64; // [esp+120h] [ebp-948h]
  int v65; // [esp+124h] [ebp-944h]
  int v66; // [esp+128h] [ebp-940h]
  int v67; // [esp+12Ch] [ebp-93Ch]
  int v68; // [esp+130h] [ebp-938h]
  int v69; // [esp+134h] [ebp-934h]
  int v70; // [esp+138h] [ebp-930h]
  SM_SIV_PaletteBlock *v71; // [esp+13Ch] [ebp-92Ch]
  SM_SIV_PaletteBlock *v72; // [esp+140h] [ebp-928h]
  void *v73; // [esp+144h] [ebp-924h]
  SM_SIV_PaletteBlock *v74; // [esp+148h] [ebp-920h]
  void *v75; // [esp+14Ch] [ebp-91Ch]
  SM_SIV_PaletteBlock *v76; // [esp+150h] [ebp-918h]
  SM_SIV_PaletteBlock *v77; // [esp+154h] [ebp-914h]
  SM_SIV_PaletteBlock *v78; // [esp+158h] [ebp-910h]
  SM_SIV_PaletteBlock *v79; // [esp+15Ch] [ebp-90Ch]
  void *v80; // [esp+160h] [ebp-908h]
  SM_SIV_PaletteBlock *v81; // [esp+164h] [ebp-904h]
  void *v82; // [esp+168h] [ebp-900h]
  int Png; // [esp+16Ch] [ebp-8FCh]
  void *v84; // [esp+170h] [ebp-8F8h]
  SM_SIV_PaletteBlock *v85; // [esp+174h] [ebp-8F4h]
  SM_SIV_PaletteBlock *v86; // [esp+178h] [ebp-8F0h]
  SM_SIV_PaletteBlock *v87; // [esp+17Ch] [ebp-8ECh]
  SM_SIV_PaletteBlock *v88; // [esp+180h] [ebp-8E8h]
  void *v89; // [esp+184h] [ebp-8E4h]
  SM_SIV_PaletteBlock *v90; // [esp+188h] [ebp-8E0h]
  void *v91; // [esp+18Ch] [ebp-8DCh]
  SM_SIV_PaletteBlock *v92; // [esp+190h] [ebp-8D8h]
  void *v93; // [esp+194h] [ebp-8D4h]
  SM_SIV_PaletteBlock *v94; // [esp+198h] [ebp-8D0h]
  SM_SIV_PaletteBlock *v95; // [esp+19Ch] [ebp-8CCh]
  SM_SIV_PaletteBlock *v96; // [esp+1A0h] [ebp-8C8h]
  SM_SIV_PaletteBlock *v97; // [esp+1A4h] [ebp-8C4h]
  void *v98; // [esp+1A8h] [ebp-8C0h]
  SM_SIV_PaletteBlock *v99; // [esp+1ACh] [ebp-8BCh]
  void *v100; // [esp+1B0h] [ebp-8B8h]
  SM_SIV_PaletteBlock *v101; // [esp+1B4h] [ebp-8B4h]
  void *v102; // [esp+1B8h] [ebp-8B0h]
  SM_SIV_PaletteBlock *v103; // [esp+1BCh] [ebp-8ACh]
  SM_SIV_PaletteBlock *v104; // [esp+1C0h] [ebp-8A8h]
  SM_SIV_PaletteBlock *v105; // [esp+1C4h] [ebp-8A4h]
  SM_SIV_PaletteBlock *v106; // [esp+1C8h] [ebp-8A0h]
  void *v107; // [esp+1CCh] [ebp-89Ch]
  __int16 v108[8]; // [esp+1D0h] [ebp-898h] BYREF
  int v109; // [esp+1E0h] [ebp-888h]
  wchar_t *FileName; // [esp+1E4h] [ebp-884h]
  int i; // [esp+1E8h] [ebp-880h]
  size_t ElementSize; // [esp+1ECh] [ebp-87Ch]
  void *v113; // [esp+1F0h] [ebp-878h]
  int v114; // [esp+1F4h] [ebp-874h] BYREF
  SM_SIV_PaletteBlock *v115; // [esp+1F8h] [ebp-870h]
  SM_SIV_PaletteBlock *v116; // [esp+1FCh] [ebp-86Ch]
  SM_SIV_PaletteBlock *v117; // [esp+200h] [ebp-868h]
  int v118; // [esp+204h] [ebp-864h]
  int v119; // [esp+208h] [ebp-860h]
  CRTComp *v120; // [esp+20Ch] [ebp-85Ch]
  int v121[11]; // [esp+210h] [ebp-858h] BYREF
  _WORD v122[6]; // [esp+23Ch] [ebp-82Ch] BYREF
  void *v123[4]; // [esp+248h] [ebp-820h] BYREF
  WCHAR Buffer[1024]; // [esp+258h] [ebp-810h] BYREF
  int v125; // [esp+A64h] [ebp-4h]

  v120 = this;
  IA_ColorReduction::IA_ColorReduction((IA_ColorReduction *)v13);
  v125 = 0;
  BB_SIV_ChunkHeader::BB_SIV_ChunkHeader((BB_SIV_ChunkHeader *)v108);
  j__memset(v122, 0, sizeof(v122));
  if ( a2 >= 1 && a2 <= 8 )
  {
    if ( *((_DWORD *)v120 + 1) )
    {
      GetCurrentDirectoryW(0x400u, Buffer);
      if ( SetCurrentDirectoryW(*((LPCWSTR *)v120 + 1)) )
      {
        j__memset(v121, 0, sizeof(v121));
        v118 = 0;
        v119 = 0;
        v114 = 0;
        v3 = j___wfopen(L"1.gfx", L"wb");
        *((_DWORD *)v120 + 10) = v3;
        if ( *((_DWORD *)v120 + 10) )
        {
          v108[0] = 0x8000;
          v109 = 1;
          BB_SIV_ChunkHeader::Save(*((FILE **)v120 + 10));
          v114 += 20;
          v4 = j___wfopen(L"1.gil", L"wb");
          *((_DWORD *)v120 + 11) = v4;
          if ( *((_DWORD *)v120 + 11) )
          {
            v108[0] = -32765;
            BB_SIV_ChunkHeader::Save(*((FILE **)v120 + 11));
            v5 = j___wfopen(L"1.pi2", L"wb");
            *((_DWORD *)v120 + 12) = v5;
            if ( *((_DWORD *)v120 + 12) )
            {
              v108[0] = -32765;
              BB_SIV_ChunkHeader::Save(*((FILE **)v120 + 12));
              v6 = j___wfopen(L"1.p25", L"wb");
              *((_DWORD *)v120 + 13) = v6;
              if ( *((_DWORD *)v120 + 13) )
              {
                v108[0] = -32767;
                BB_SIV_ChunkHeader::Save(*((FILE **)v120 + 13));
                v7 = j___wfopen(L"1.p26", L"wb");
                *((_DWORD *)v120 + 14) = v7;
                if ( *((_DWORD *)v120 + 14) )
                {
                  v108[0] = -32767;
                  BB_SIV_ChunkHeader::Save(*((FILE **)v120 + 14));
                  v8 = j___wfopen(L"1.p24", L"wb");
                  *((_DWORD *)v120 + 15) = v8;
                  if ( *((_DWORD *)v120 + 15) )
                  {
                    v108[0] = -32767;
                    BB_SIV_ChunkHeader::Save(*((FILE **)v120 + 15));
                    v118 += 20;
                    v9 = j___wfopen(L"1.pi4", L"wb");
                    *((_DWORD *)v120 + 16) = v9;
                    if ( *((_DWORD *)v120 + 16) )
                    {
                      v108[0] = -32765;
                      BB_SIV_ChunkHeader::Save(*((FILE **)v120 + 16));
                      v10 = j___wfopen(L"1.p45", L"wb");
                      *((_DWORD *)v120 + 17) = v10;
                      if ( *((_DWORD *)v120 + 17) )
                      {
                        v108[0] = -32767;
                        BB_SIV_ChunkHeader::Save(*((FILE **)v120 + 17));
                        v11 = j___wfopen(L"1.p46", L"wb");
                        *((_DWORD *)v120 + 18) = v11;
                        if ( *((_DWORD *)v120 + 18) )
                        {
                          v108[0] = -32767;
                          BB_SIV_ChunkHeader::Save(*((FILE **)v120 + 18));
                          v12 = j___wfopen(L"1.p44", L"wb");
                          *((_DWORD *)v120 + 19) = v12;
                          if ( *((_DWORD *)v120 + 19) )
                          {
                            v108[0] = -32767;
                            BB_SIV_ChunkHeader::Save(*((FILE **)v120 + 19));
                            v119 += 20;
                            v122[5] = 5900;
                            for ( i = 0; i < a2; ++i )
                            {
                              FileName = CRTComp::CreateCurFilename(v120, i);
                              Png = CRTComp::LoadPng(FileName, (int)v121);
                              if ( Png )
                              {
                                SetCurrentDirectoryW(Buffer);
                                CRTComp::SetErrorFilename(FileName);
                                CRTComp::DeleteCurFilename(v120, FileName);
                                j___fcloseall();
                                v62 = Png;
                                v125 = -1;
                                IA_ColorReduction::~IA_ColorReduction((IA_ColorReduction *)v13);
                                return v62;
                              }
                              IA_ColorReduction::InitTree((IA_ColorReduction *)v13);
                              CRTComp::CreateColorField((int)v123, 0x100u);
                              CRTComp::ConvertTo555(v120, (unsigned __int8 **const)v121, 400);
                              IA_ColorReduction::BuildTree(
                                (IA_ColorReduction *)v13,
                                (unsigned __int8 **const)v121,
                                0x190u);
                              IA_ColorReduction::ReduceIt((IA_ColorReduction *)v13, 0xFDu);
                              IA_ColorReduction::InitPalette(
                                (IA_ColorReduction *)v13,
                                (unsigned __int8 **const)v123,
                                0xFDu);
                              v60 = CRTComp::PutColorMapColorKeyToFront(v120, (unsigned __int8 **const)v123);
                              CRTComp::FreeColormapShadowColor(v120, (unsigned __int8 **const)v123);
                              CRTComp::FreeColormapPlayerColor(v120, (unsigned __int8 **const)v123);
                              v61 = (unsigned __int8 *)operator new[](0x191u);
                              v121[4] = (int)v61;
                              IA_ColorReduction::MapColors(
                                (IA_ColorReduction *)v13,
                                (unsigned __int8 **const)v121,
                                v61,
                                0x190u);
                              CRTComp::PutBitmapColorKeyToFront(v120, (unsigned __int8 *)v121[4], 0x190u, v60);
                              CRTComp::FreeBitmapShadowColor(v120, (unsigned __int8 *)v121[4], 0x190u);
                              CRTComp::FreeBitmapPlayerColor(v120, (unsigned __int8 *)v121[4], 0x190u);
                              IA_ColorReduction::DeleteTree((IA_ColorReduction *)v13);
                              CRTComp::CenterBitmap(v120, (struct SM_S_BF_BITMAP_DATA *)v121);
                              CRTComp::CreateMagBorder(v120, (struct SM_S_BF_BITMAP_DATA *)v121);
                              j__fwrite(&v114, 4u, 1u, *((FILE **)v120 + 11));
                              v122[0] = v121[9];
                              v122[1] = v121[10];
                              v122[2] = 1 - ((unsigned int)v121[9] >> 1);
                              v122[3] = 1 - ((unsigned int)v121[10] >> 1);
                              ++v122[5];
                              j__fwrite(v122, 0xCu, 1u, *((FILE **)v120 + 10));
                              v114 += 12;
                              v59 = (unsigned __int8 *)operator new[](v122[1] * v122[0] + 1);
                              v113 = v59;
                              ElementSize = CRTComp::EncodeImage(
                                              v120,
                                              (unsigned __int8 *)v121[4],
                                              v59,
                                              v122[0],
                                              v122[1]);
                              j__fwrite(v113, ElementSize, 1u, *((FILE **)v120 + 10));
                              v114 += ElementSize;
                              C = v113;
                              operator delete[](v113);
                              j__memset(v123[3], 255, 0x100u);
                              v75 = operator new(0x1005u);
                              LOBYTE(v125) = 1;
                              if ( v75 )
                                v74 = SM_SIV_PaletteBlock::SM_SIV_PaletteBlock((SM_SIV_PaletteBlock *)v75, 1, 0);
                              else
                                v74 = 0;
                              v57 = v74;
                              LOBYTE(v125) = 0;
                              v117 = v74;
                              v73 = operator new(0x1005u);
                              LOBYTE(v125) = 2;
                              if ( v73 )
                                v72 = SM_SIV_PaletteBlock::SM_SIV_PaletteBlock((SM_SIV_PaletteBlock *)v73, 0, 0);
                              else
                                v72 = 0;
                              v56 = v72;
                              LOBYTE(v125) = 0;
                              v116 = v72;
                              v107 = operator new(0x1005u);
                              LOBYTE(v125) = 3;
                              if ( v107 )
                                v106 = SM_SIV_PaletteBlock::SM_SIV_PaletteBlock((SM_SIV_PaletteBlock *)v107, 2, 0);
                              else
                                v106 = 0;
                              v55 = v106;
                              LOBYTE(v125) = 0;
                              v115 = v106;
                              SM_SIV_PaletteBlock::FillPalette(v117, 0, v123, 0, 256);
                              SM_SIV_PaletteBlock::FillPalette(v116, 0, v123, 0, 256);
                              SM_SIV_PaletteBlock::FillPalette(v115, 0, v123, 0, 256);
                              v119 = SM_SIV_PaletteBlock::Save(*((FILE **)v120 + 17), *((FILE **)v120 + 16), v119, 1, 1);
                              v119 = SM_SIV_PaletteBlock::Save(*((FILE **)v120 + 18), 0, v119, 1, 1);
                              v119 = SM_SIV_PaletteBlock::Save(*((FILE **)v120 + 19), 0, v119, 1, 1);
                              v54 = v117;
                              v105 = v117;
                              if ( v117 )
                                v53 = SM_SIV_PaletteBlock::`scalar deleting destructor'(v105, 1u);
                              else
                                v53 = 0;
                              v52 = v116;
                              v104 = v116;
                              if ( v116 )
                                v51 = SM_SIV_PaletteBlock::`scalar deleting destructor'(v104, 1u);
                              else
                                v51 = 0;
                              v50 = v115;
                              v103 = v115;
                              if ( v115 )
                                v49 = SM_SIV_PaletteBlock::`scalar deleting destructor'(v103, 1u);
                              else
                                v49 = 0;
                              v102 = operator new(0x1005u);
                              LOBYTE(v125) = 4;
                              if ( v102 )
                                v101 = SM_SIV_PaletteBlock::SM_SIV_PaletteBlock((SM_SIV_PaletteBlock *)v102, 1, 1);
                              else
                                v101 = 0;
                              v48 = v101;
                              LOBYTE(v125) = 0;
                              v117 = v101;
                              v100 = operator new(0x1005u);
                              LOBYTE(v125) = 5;
                              if ( v100 )
                                v99 = SM_SIV_PaletteBlock::SM_SIV_PaletteBlock((SM_SIV_PaletteBlock *)v100, 0, 1);
                              else
                                v99 = 0;
                              v47 = v99;
                              LOBYTE(v125) = 0;
                              v116 = v99;
                              v98 = operator new(0x1005u);
                              LOBYTE(v125) = 6;
                              if ( v98 )
                                v97 = SM_SIV_PaletteBlock::SM_SIV_PaletteBlock((SM_SIV_PaletteBlock *)v98, 2, 1);
                              else
                                v97 = 0;
                              v46 = v97;
                              LOBYTE(v125) = 0;
                              v115 = v97;
                              SM_SIV_PaletteBlock::FillPalette(v117, 0, v123, 0, 256);
                              SM_SIV_PaletteBlock::FillPalette(v116, 0, v123, 0, 256);
                              SM_SIV_PaletteBlock::FillPalette(v115, 0, v123, 0, 256);
                              v118 = SM_SIV_PaletteBlock::Save(*((FILE **)v120 + 13), *((FILE **)v120 + 12), v118, 1, 1);
                              v118 = SM_SIV_PaletteBlock::Save(*((FILE **)v120 + 14), 0, v118, 1, 1);
                              v118 = SM_SIV_PaletteBlock::Save(*((FILE **)v120 + 15), 0, v118, 1, 1);
                              v45 = v117;
                              v96 = v117;
                              if ( v117 )
                                v44 = SM_SIV_PaletteBlock::`scalar deleting destructor'(v96, 1u);
                              else
                                v44 = 0;
                              v43 = v116;
                              v95 = v116;
                              if ( v116 )
                                v42 = SM_SIV_PaletteBlock::`scalar deleting destructor'(v95, 1u);
                              else
                                v42 = 0;
                              v41 = v115;
                              v94 = v115;
                              if ( v115 )
                                v26 = SM_SIV_PaletteBlock::`scalar deleting destructor'(v94, 1u);
                              else
                                v26 = 0;
                              j__fwrite(&v114, 4u, 1u, *((FILE **)v120 + 11));
                              v122[0] = v121[9];
                              v122[1] = v121[10];
                              v122[2] = 1 - ((unsigned int)v121[9] >> 1);
                              v122[3] = 1 - ((unsigned int)v121[10] >> 1);
                              ++v122[5];
                              j__fwrite(v122, 0xCu, 1u, *((FILE **)v120 + 10));
                              v114 += 12;
                              v39 = (unsigned __int8 *)operator new[](v122[1] * v122[0] + 1);
                              v113 = v39;
                              ElementSize = CRTComp::EncodeImage(
                                              v120,
                                              (unsigned __int8 *)v121[4],
                                              v39,
                                              v122[0],
                                              v122[1]);
                              j__fwrite(v113, ElementSize, 1u, *((FILE **)v120 + 10));
                              v114 += ElementSize;
                              v38 = v113;
                              operator delete[](v113);
                              v93 = operator new(0x1005u);
                              LOBYTE(v125) = 7;
                              if ( v93 )
                                v92 = SM_SIV_PaletteBlock::SM_SIV_PaletteBlock((SM_SIV_PaletteBlock *)v93, 1, 0);
                              else
                                v92 = 0;
                              v37 = v92;
                              LOBYTE(v125) = 0;
                              v117 = v92;
                              v91 = operator new(0x1005u);
                              LOBYTE(v125) = 8;
                              if ( v91 )
                                v90 = SM_SIV_PaletteBlock::SM_SIV_PaletteBlock((SM_SIV_PaletteBlock *)v91, 0, 0);
                              else
                                v90 = 0;
                              v36 = v90;
                              LOBYTE(v125) = 0;
                              v116 = v90;
                              v89 = operator new(0x1005u);
                              LOBYTE(v125) = 9;
                              if ( v89 )
                                v88 = SM_SIV_PaletteBlock::SM_SIV_PaletteBlock((SM_SIV_PaletteBlock *)v89, 2, 0);
                              else
                                v88 = 0;
                              v35 = v88;
                              LOBYTE(v125) = 0;
                              v115 = v88;
                              SM_SIV_PaletteBlock::FillPalette(v117, 0, v123, 0, 256);
                              SM_SIV_PaletteBlock::FillPalette(v116, 0, v123, 0, 256);
                              SM_SIV_PaletteBlock::FillPalette(v115, 0, v123, 0, 256);
                              v119 = SM_SIV_PaletteBlock::Save(*((FILE **)v120 + 17), *((FILE **)v120 + 16), v119, 1, 1);
                              v119 = SM_SIV_PaletteBlock::Save(*((FILE **)v120 + 18), 0, v119, 1, 1);
                              v119 = SM_SIV_PaletteBlock::Save(*((FILE **)v120 + 19), 0, v119, 1, 1);
                              v34 = v117;
                              v87 = v117;
                              if ( v117 )
                                v33 = SM_SIV_PaletteBlock::`scalar deleting destructor'(v87, 1u);
                              else
                                v33 = 0;
                              v32 = v116;
                              v86 = v116;
                              if ( v116 )
                                v31 = SM_SIV_PaletteBlock::`scalar deleting destructor'(v86, 1u);
                              else
                                v31 = 0;
                              v30 = v115;
                              v85 = v115;
                              if ( v115 )
                                v29 = SM_SIV_PaletteBlock::`scalar deleting destructor'(v85, 1u);
                              else
                                v29 = 0;
                              v84 = operator new(0x1005u);
                              LOBYTE(v125) = 10;
                              if ( v84 )
                                v77 = SM_SIV_PaletteBlock::SM_SIV_PaletteBlock((SM_SIV_PaletteBlock *)v84, 1, 1);
                              else
                                v77 = 0;
                              v28 = v77;
                              LOBYTE(v125) = 0;
                              v117 = v77;
                              v82 = operator new(0x1005u);
                              LOBYTE(v125) = 11;
                              if ( v82 )
                                v81 = SM_SIV_PaletteBlock::SM_SIV_PaletteBlock((SM_SIV_PaletteBlock *)v82, 0, 1);
                              else
                                v81 = 0;
                              v27 = v81;
                              LOBYTE(v125) = 0;
                              v116 = v81;
                              v80 = operator new(0x1005u);
                              LOBYTE(v125) = 12;
                              if ( v80 )
                                v79 = SM_SIV_PaletteBlock::SM_SIV_PaletteBlock((SM_SIV_PaletteBlock *)v80, 2, 1);
                              else
                                v79 = 0;
                              v14 = v79;
                              LOBYTE(v125) = 0;
                              v115 = v79;
                              SM_SIV_PaletteBlock::FillPalette(v117, 0, v123, 0, 256);
                              SM_SIV_PaletteBlock::FillPalette(v116, 0, v123, 0, 256);
                              SM_SIV_PaletteBlock::FillPalette(v115, 0, v123, 0, 256);
                              v118 = SM_SIV_PaletteBlock::Save(*((FILE **)v120 + 13), *((FILE **)v120 + 12), v118, 1, 1);
                              v118 = SM_SIV_PaletteBlock::Save(*((FILE **)v120 + 14), 0, v118, 1, 1);
                              v118 = SM_SIV_PaletteBlock::Save(*((FILE **)v120 + 15), 0, v118, 1, 1);
                              v25 = v117;
                              v78 = v117;
                              if ( v117 )
                                v24 = SM_SIV_PaletteBlock::`scalar deleting destructor'(v78, 1u);
                              else
                                v24 = 0;
                              v23 = v116;
                              v71 = v116;
                              if ( v116 )
                                v22 = SM_SIV_PaletteBlock::`scalar deleting destructor'(v71, 1u);
                              else
                                v22 = 0;
                              v21 = v115;
                              v76 = v115;
                              if ( v115 )
                                v20 = SM_SIV_PaletteBlock::`scalar deleting destructor'(v76, 1u);
                              else
                                v20 = 0;
                              CRTComp::DeleteCurFilename(v120, FileName);
                              CRTComp::DestroyContent(v120, (struct SM_S_BF_BITMAP_DATA *)v121);
                              CRTComp::DestroyColorField(v120, (unsigned __int8 **const)v123);
                            }
                            j__fclose(*((FILE **)v120 + 10));
                            j__fclose(*((FILE **)v120 + 11));
                            j__fclose(*((FILE **)v120 + 13));
                            j__fclose(*((FILE **)v120 + 17));
                            j__fclose(*((FILE **)v120 + 14));
                            j__fclose(*((FILE **)v120 + 18));
                            j__fclose(*((FILE **)v120 + 15));
                            j__fclose(*((FILE **)v120 + 19));
                            j__fclose(*((FILE **)v120 + 12));
                            j__fclose(*((FILE **)v120 + 16));
                            SetCurrentDirectoryW(Buffer);
                            v19 = 0;
                            v125 = -1;
                            IA_ColorReduction::~IA_ColorReduction((IA_ColorReduction *)v13);
                            return v19;
                          }
                          else
                          {
                            SetCurrentDirectoryW(Buffer);
                            CRTComp::SetErrorFilename((wchar_t *)L"1.p44");
                            j___fcloseall();
                            v63 = 12;
                            v125 = -1;
                            IA_ColorReduction::~IA_ColorReduction((IA_ColorReduction *)v13);
                            return v63;
                          }
                        }
                        else
                        {
                          SetCurrentDirectoryW(Buffer);
                          CRTComp::SetErrorFilename((wchar_t *)L"1.p46");
                          j___fcloseall();
                          v64 = 12;
                          v125 = -1;
                          IA_ColorReduction::~IA_ColorReduction((IA_ColorReduction *)v13);
                          return v64;
                        }
                      }
                      else
                      {
                        SetCurrentDirectoryW(Buffer);
                        CRTComp::SetErrorFilename((wchar_t *)L"1.p45");
                        j___fcloseall();
                        v65 = 12;
                        v125 = -1;
                        IA_ColorReduction::~IA_ColorReduction((IA_ColorReduction *)v13);
                        return v65;
                      }
                    }
                    else
                    {
                      SetCurrentDirectoryW(Buffer);
                      CRTComp::SetErrorFilename((wchar_t *)L"1.pi4");
                      j___fcloseall();
                      v66 = 12;
                      v125 = -1;
                      IA_ColorReduction::~IA_ColorReduction((IA_ColorReduction *)v13);
                      return v66;
                    }
                  }
                  else
                  {
                    SetCurrentDirectoryW(Buffer);
                    CRTComp::SetErrorFilename((wchar_t *)L"1.p24");
                    j___fcloseall();
                    v67 = 12;
                    v125 = -1;
                    IA_ColorReduction::~IA_ColorReduction((IA_ColorReduction *)v13);
                    return v67;
                  }
                }
                else
                {
                  SetCurrentDirectoryW(Buffer);
                  CRTComp::SetErrorFilename((wchar_t *)L"1.p26");
                  j___fcloseall();
                  v68 = 12;
                  v125 = -1;
                  IA_ColorReduction::~IA_ColorReduction((IA_ColorReduction *)v13);
                  return v68;
                }
              }
              else
              {
                SetCurrentDirectoryW(Buffer);
                CRTComp::SetErrorFilename((wchar_t *)L"1.p25");
                j___fcloseall();
                v69 = 12;
                v125 = -1;
                IA_ColorReduction::~IA_ColorReduction((IA_ColorReduction *)v13);
                return v69;
              }
            }
            else
            {
              SetCurrentDirectoryW(Buffer);
              CRTComp::SetErrorFilename((wchar_t *)L"1.pi2");
              j___fcloseall();
              v70 = 12;
              v125 = -1;
              IA_ColorReduction::~IA_ColorReduction((IA_ColorReduction *)v13);
              return v70;
            }
          }
          else
          {
            SetCurrentDirectoryW(Buffer);
            CRTComp::SetErrorFilename((wchar_t *)L"1.gil");
            j___fcloseall();
            v15 = 12;
            v125 = -1;
            IA_ColorReduction::~IA_ColorReduction((IA_ColorReduction *)v13);
            return v15;
          }
        }
        else
        {
          SetCurrentDirectoryW(Buffer);
          CRTComp::SetErrorFilename((wchar_t *)L"1.gfx");
          v16 = 12;
          v125 = -1;
          IA_ColorReduction::~IA_ColorReduction((IA_ColorReduction *)v13);
          return v16;
        }
      }
      else
      {
        v17 = 1;
        v125 = -1;
        IA_ColorReduction::~IA_ColorReduction((IA_ColorReduction *)v13);
        return v17;
      }
    }
    else
    {
      v18 = 2;
      v125 = -1;
      IA_ColorReduction::~IA_ColorReduction((IA_ColorReduction *)v13);
      return v18;
    }
  }
  else
  {
    v40 = 13;
    v125 = -1;
    IA_ColorReduction::~IA_ColorReduction((IA_ColorReduction *)v13);
    return v40;
  }
}


// address=[0x2fceeb0]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
int __thiscall CRTComp::GetErrorFileName(CRTComp *this)

wchar_t *  CRTComp::GetErrorFileName(void) {
  
  return *((_DWORD *)this + 2);
}


// address=[0x2fceed0]
// Decompiled from char __stdcall CRTComp::GetPictureInfos(wchar_t *FileName, _DWORD *a2, _DWORD *a3, _DWORD *a4)

bool  CRTComp::GetPictureInfos(wchar_t *,int &,int &,int &) {
  
  FILE *Stream; // [esp+4h] [ebp-Ch]
  int info_struct; // [esp+8h] [ebp-8h] BYREF
  void **v7; // [esp+Ch] [ebp-4h] BYREF

  v7 = j__png_create_read_struct("1.0.6", 0, 0, 0);
  if ( !v7 )
    return 0;
  info_struct = j__png_create_info_struct(v7);
  if ( j___setjmp3(v7, 0) || (Stream = j___wfopen(FileName, L"rb")) == 0 )
  {
    j__png_destroy_read_struct(&v7, &info_struct, 0);
    return 0;
  }
  else
  {
    j__png_init_io(v7, Stream);
    j__png_read_info(v7, info_struct);
    *a2 = *(_DWORD *)info_struct;
    *a3 = *(_DWORD *)(info_struct + 4);
    *a4 = *(unsigned __int8 *)(info_struct + 30);
    j__png_destroy_read_struct(&v7, &info_struct, 0);
    j__fclose(Stream);
    return 1;
  }
}


// address=[0x2fcefd0]
// Decompiled from char *__thiscall CRTComp::CreateCurFilename(CRTComp *this, char a2)

wchar_t *  CRTComp::CreateCurFilename(int) {
  
  char *Buffer; // [esp+8h] [ebp-4h]

  Buffer = (char *)operator new[](0xC8u);
  swprintf(Buffer, (char *)L"HerFig_%d.png", a2);
  return Buffer;
}


// address=[0x2fcf010]
// Decompiled from int __thiscall CRTComp::DeleteCurFilename(CRTComp *this, wchar_t *a2)

void  CRTComp::DeleteCurFilename(wchar_t *) {
  
  int result; // eax

  if ( a2 )
    return operator delete[](a2);
  return result;
}


// address=[0x2fcf040]
// Decompiled from wchar_t *__thiscall CRTComp::SetErrorFilename(void **this, wchar_t *String)

void  CRTComp::SetErrorFilename(wchar_t *) {
  
  wchar_t *result; // eax
  size_t v3; // [esp+4h] [ebp-Ch]

  result = (wchar_t *)this;
  if ( this[2] )
    result = (wchar_t *)operator delete[](this[2]);
  this[2] = 0;
  if ( !String )
    return result;
  v3 = j__wcslen(String);
  this[2] = operator new[](2 * (v3 + 1));
  return j__wcscpy((wchar_t *)this[2], String);
}


// address=[0x2fcf0d0]
// Decompiled from int __thiscall CRTComp::LoadPng(CRTComp *this, wchar_t *FileName, int a3)

enum RTCOMP_ERROR  CRTComp::LoadPng(wchar_t *,struct SM_S_BF_BITMAP_DATA *) {
  
  int v4; // [esp+24h] [ebp-54h]
  int rowbytes; // [esp+28h] [ebp-50h]
  unsigned int i; // [esp+30h] [ebp-48h]
  _DWORD *v8; // [esp+34h] [ebp-44h]
  unsigned __int8 *v9; // [esp+38h] [ebp-40h]
  FILE *Stream; // [esp+3Ch] [ebp-3Ch]
  void **v11; // [esp+40h] [ebp-38h] BYREF
  _DWORD v12[12]; // [esp+44h] [ebp-34h] BYREF

  j__memset(&v12[1], 0, 0x2Cu);
  v11 = j__png_create_read_struct("1.0.6", 0, 0, 0);
  if ( !v11 )
    return 4;
  v12[0] = j__png_create_info_struct(v11);
  if ( j___setjmp3(v11, 0) )
  {
    j__png_destroy_read_struct(&v11, v12, 0);
    return 4;
  }
  else
  {
    Stream = j___wfopen(FileName, L"rb");
    if ( Stream )
    {
      j__png_init_io(v11, Stream);
      j__png_read_info(v11, v12[0]);
      if ( *(_BYTE *)(v12[0] + 30) == 24 || *(_BYTE *)(v12[0] + 30) == 8 )
      {
        if ( *(_BYTE *)(v12[0] + 25) == 3 || *(_BYTE *)(v12[0] + 25) == 2 )
        {
          if ( *(_BYTE *)(v12[0] + 29) == 1 || *(_BYTE *)(v12[0] + 29) == 3 )
          {
            if ( *(_BYTE *)(v12[0] + 25) != 3 || *(_WORD *)(v12[0] + 20) == 256 )
            {
              v4 = *(_DWORD *)(v12[0] + 4) * *(_DWORD *)v12[0];
              rowbytes = j__png_get_rowbytes(v11, v12[0]);
              if ( v4 && rowbytes )
              {
                v9 = (unsigned __int8 *)operator new[](*(_DWORD *)(v12[0] + 4) * rowbytes);
                if ( v9 )
                {
                  v8 = operator new[](4 * *(_DWORD *)(v12[0] + 4));
                  if ( v8 )
                  {
                    for ( i = 0; i < *(_DWORD *)(v12[0] + 4); ++i )
                      v8[i] = &v9[rowbytes * i];
                    j__png_set_bgr(v11);
                    j__png_read_image(v11, v8);
                    j__png_read_end(v11, 0);
                    *(_DWORD *)(a3 + 36) = *(_DWORD *)v12[0];
                    *(_DWORD *)(a3 + 40) = *(_DWORD *)(v12[0] + 4);
                    if ( *(_DWORD *)(a3 + 36) == 20 && *(_DWORD *)(a3 + 40) == 20 )
                    {
                      if ( *(_BYTE *)(v12[0] + 30) == 24 )
                        CRTComp::Decompose24(this, (struct SM_S_BF_BITMAP_DATA *)a3, v9);
                      else
                        CRTComp::Decompose8(this, (struct SM_S_BF_BITMAP_DATA *)a3, v9, *(char **)(v12[0] + 16));
                      CRTComp::CreateBoundingBox(this, (struct SM_S_BF_BITMAP_DATA *)a3);
                      if ( *(_DWORD *)(a3 + 28) == *(_DWORD *)(a3 + 20) || *(_DWORD *)(a3 + 32) == *(_DWORD *)(a3 + 24) )
                      {
                        CRTComp::DestroyContent(this, (struct SM_S_BF_BITMAP_DATA *)a3);
                        j__png_destroy_read_struct(&v11, v12, 0);
                        j__fclose(Stream);
                        operator delete(v9);
                        operator delete[](v8);
                        return 11;
                      }
                      else
                      {
                        j__png_destroy_read_struct(&v11, v12, 0);
                        j__fclose(Stream);
                        operator delete(v9);
                        operator delete[](v8);
                        return 0;
                      }
                    }
                    else
                    {
                      CRTComp::DestroyContent(this, (struct SM_S_BF_BITMAP_DATA *)a3);
                      j__png_destroy_read_struct(&v11, v12, 0);
                      j__fclose(Stream);
                      operator delete(v9);
                      operator delete[](v8);
                      return 10;
                    }
                  }
                  else
                  {
                    j__png_destroy_read_struct(&v11, v12, 0);
                    j__fclose(Stream);
                    operator delete(v9);
                    return 5;
                  }
                }
                else
                {
                  j__png_destroy_read_struct(&v11, v12, 0);
                  j__fclose(Stream);
                  return 5;
                }
              }
              else
              {
                j__png_destroy_read_struct(&v11, v12, 0);
                j__fclose(Stream);
                return 4;
              }
            }
            else
            {
              j__png_destroy_read_struct(&v11, v12, 0);
              j__fclose(Stream);
              return 9;
            }
          }
          else
          {
            j__png_destroy_read_struct(&v11, v12, 0);
            j__fclose(Stream);
            return 8;
          }
        }
        else
        {
          j__png_destroy_read_struct(&v11, v12, 0);
          j__fclose(Stream);
          return 7;
        }
      }
      else
      {
        j__png_destroy_read_struct(&v11, v12, 0);
        j__fclose(Stream);
        return 6;
      }
    }
    else
    {
      return 3;
    }
  }
}


// address=[0x2fcf5a0]
// Decompiled from int __thiscall CRTComp::Decompose24(CRTComp *this, struct SM_S_BF_BITMAP_DATA *a2, unsigned __int8 *a3)

void  CRTComp::Decompose24(struct SM_S_BF_BITMAP_DATA *,unsigned char *) {
  
  int result; // eax
  int Size; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  unsigned __int8 *v7; // [esp+Ch] [ebp-4h]

  Size = *((_DWORD *)a2 + 10) * *((_DWORD *)a2 + 9);
  result = CRTComp::CreateColorField((int)a2, Size);
  for ( i = 0; i < Size; ++i )
  {
    *(_BYTE *)(*(_DWORD *)a2 + i) = *a3;
    v7 = a3 + 1;
    *(_BYTE *)(*((_DWORD *)a2 + 1) + i) = *v7;
    *(_BYTE *)(*((_DWORD *)a2 + 2) + i) = v7[1];
    a3 = v7 + 2;
    result = i + 1;
  }
  return result;
}


// address=[0x2fcf660]
// Decompiled from int __thiscall CRTComp::Decompose8(CRTComp *this, struct SM_S_BF_BITMAP_DATA *a2, unsigned __int8 *a3, char *a4)

void  CRTComp::Decompose8(struct SM_S_BF_BITMAP_DATA *,unsigned char *,char *) {
  
  int result; // eax
  int Size; // [esp+8h] [ebp-10h]
  int i; // [esp+10h] [ebp-8h]
  unsigned __int8 v8; // [esp+17h] [ebp-1h]

  Size = *((_DWORD *)a2 + 10) * *((_DWORD *)a2 + 9);
  result = CRTComp::CreateColorField((int)a2, Size);
  for ( i = 0; i < Size; ++i )
  {
    v8 = *a3++;
    *(_BYTE *)(*(_DWORD *)a2 + i) = a4[3 * v8];
    *(_BYTE *)(*((_DWORD *)a2 + 1) + i) = a4[3 * v8 + 1];
    *(_BYTE *)(*((_DWORD *)a2 + 2) + i) = a4[3 * v8 + 2];
    result = i + 1;
  }
  return result;
}


// address=[0x2fcf730]
// Decompiled from void __thiscall CRTComp::DestroyContent(CRTComp *this, struct SM_S_BF_BITMAP_DATA *a2)

void  CRTComp::DestroyContent(struct SM_S_BF_BITMAP_DATA *) {
  
  if ( a2 )
  {
    CRTComp::DestroyColorField(this, (unsigned __int8 **const)a2);
    if ( *((_DWORD *)a2 + 4) )
      operator delete[](*((void **)a2 + 4));
  }
}


// address=[0x2fcf780]
// Decompiled from unsigned int __thiscall CRTComp::CreateBoundingBox(CRTComp *this, struct SM_S_BF_BITMAP_DATA *a2)

void  CRTComp::CreateBoundingBox(struct SM_S_BF_BITMAP_DATA *) {
  
  unsigned int result; // eax
  unsigned int i; // [esp+4h] [ebp-Ch]
  unsigned int j; // [esp+8h] [ebp-8h]

  *((_DWORD *)a2 + 5) = 1000;
  *((_DWORD *)a2 + 6) = 1000;
  *((_DWORD *)a2 + 7) = 0;
  *((_DWORD *)a2 + 8) = 0;
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( i >= *((_DWORD *)a2 + 10) )
      break;
    for ( j = 0; j < *((_DWORD *)a2 + 9); ++j )
    {
      if ( *(unsigned __int8 *)(*(_DWORD *)a2 + j + *((_DWORD *)a2 + 9) * i) != 255
        || *(_BYTE *)(*((_DWORD *)a2 + 1) + j + *((_DWORD *)a2 + 9) * i)
        || *(unsigned __int8 *)(*((_DWORD *)a2 + 2) + j + *((_DWORD *)a2 + 9) * i) != 255 )
      {
        if ( j < *((_DWORD *)a2 + 5) )
          *((_DWORD *)a2 + 5) = j;
        if ( j > *((_DWORD *)a2 + 7) )
          *((_DWORD *)a2 + 7) = j;
        if ( i < *((_DWORD *)a2 + 6) )
          *((_DWORD *)a2 + 6) = i;
        if ( i > *((_DWORD *)a2 + 8) )
          *((_DWORD *)a2 + 8) = i;
      }
    }
  }
  return result;
}


// address=[0x2fcf8e0]
// Decompiled from void __stdcall CRTComp::CreateColorField(int a1, size_t Size)

void  CRTComp::CreateColorField(unsigned char * * const,int) {
  
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < 4; ++i )
  {
    *(_DWORD *)(a1 + 4 * i) = operator new[](Size + 1);
    j__memset(*(void **)(a1 + 4 * i), 0, Size);
  }
}


// address=[0x2fcf940]
// Decompiled from int __thiscall CRTComp::DestroyColorField(CRTComp *this, unsigned __int8 **const a2)

void  CRTComp::DestroyColorField(unsigned char * * const) {
  
  int result; // eax
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < 4; ++i )
  {
    if ( a2[i] )
      operator delete[](a2[i]);
    result = i + 1;
  }
  return result;
}


// address=[0x2fcf990]
// Decompiled from int __thiscall CRTComp::ConvertTo555(CRTComp *this, unsigned __int8 **const a2, int a3)

void  CRTComp::ConvertTo555(unsigned char * * const,int) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-8h]
  unsigned __int8 v5; // [esp+8h] [ebp-4h]
  unsigned __int8 v6; // [esp+9h] [ebp-3h]
  unsigned __int8 v7; // [esp+Ah] [ebp-2h]

  for ( i = 0; i < a3; ++i )
  {
    v6 = (*a2)[i];
    v5 = a2[1][i];
    v7 = a2[2][i];
    if ( v6 > 0xC8u && v5 < 0x6Eu && v7 > 0xC8u )
    {
      v7 = -1;
      v6 = -1;
      v5 = 0;
    }
    (*a2)[i] = 8 * (int)(float)((float)v6 * 0.12156863);
    a2[1][i] = 8 * (int)(float)((float)v5 * 0.12156863);
    a2[2][i] = 8 * (int)(float)((float)v7 * 0.12156863);
    result = i + 1;
  }
  return result;
}


// address=[0x2fcfad0]
// Decompiled from unsigned __int8 __thiscall CRTComp::PutBitmapColorKeyToFront(
        CRTComp *this,
        unsigned __int8 *a2,
        unsigned int a3,
        unsigned __int8 a4)

void  CRTComp::PutBitmapColorKeyToFront(unsigned char *,unsigned int,unsigned char) {
  
  unsigned __int8 result; // al
  unsigned int i; // [esp+4h] [ebp-4h]
  unsigned int j; // [esp+4h] [ebp-4h]

  result = a4;
  if ( a4 )
  {
    for ( i = 0; i < a3; ++i )
    {
      if ( a2[i] )
      {
        result = a4;
        if ( a2[i] == a4 )
          a2[i] = 0;
      }
      else
      {
        result = a4;
        a2[i] = a4;
      }
    }
  }
  else
  {
    for ( j = 0; ; ++j )
    {
      result = j;
      if ( j >= a3 )
        break;
      ++a2[j];
    }
  }
  return result;
}


// address=[0x2fcfb70]
// Decompiled from int __thiscall CRTComp::PutColorMapColorKeyToFront(CRTComp *this, unsigned __int8 **const a2)

int  CRTComp::PutColorMapColorKeyToFront(unsigned char * * const) {
  
  int v3; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  int j; // [esp+Ch] [ebp-8h]

  v3 = 0;
  for ( i = 0; i < 256; ++i )
  {
    if ( (*a2)[i] == 248 && !a2[1][i] && a2[2][i] == 248 && (**a2 != 248 || *a2[1] || *a2[2] != 248) )
    {
      (*a2)[i] = **a2;
      a2[1][i] = *a2[1];
      a2[2][i] = *a2[2];
      a2[3][i] = *a2[3];
      **a2 = -8;
      *a2[1] = 0;
      *a2[2] = -8;
      *a2[3] = 0;
      v3 = i;
    }
  }
  if ( !v3 )
  {
    for ( j = 254; j >= 0; --j )
    {
      (*a2)[j + 1] = (*a2)[j];
      a2[1][j + 1] = a2[1][j];
      a2[2][j + 1] = a2[2][j];
      a2[3][j + 1] = a2[3][j];
    }
  }
  return v3;
}


// address=[0x2fcfe70]
// Decompiled from int __thiscall CRTComp::FreeColormapShadowColor(CRTComp *this, unsigned __int8 **const a2)

void  CRTComp::FreeColormapShadowColor(unsigned char * * const) {
  
  int result; // eax
  int i; // [esp+8h] [ebp-4h]

  for ( i = 254; i; --i )
  {
    (*a2)[i + 1] = (*a2)[i];
    a2[1][i + 1] = a2[1][i];
    a2[2][i + 1] = a2[2][i];
    a2[3][i + 1] = a2[3][i];
  }
  a2[3][1] = 0;
  a2[2][1] = 0;
  a2[1][1] = 0;
  result = 1;
  (*a2)[1] = 0;
  return result;
}


// address=[0x2fcffb0]
// Decompiled from unsigned int __thiscall CRTComp::FreeBitmapShadowColor(CRTComp *this, unsigned __int8 *a2, unsigned int a3)

void  CRTComp::FreeBitmapShadowColor(unsigned char *,unsigned int) {
  
  unsigned int result; // eax
  unsigned int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < a3; ++i )
  {
    if ( a2[i] )
      ++a2[i];
    result = i + 1;
  }
  return result;
}


// address=[0x2fd0000]
// Decompiled from int __thiscall CRTComp::FreeColormapPlayerColor(CRTComp *this, unsigned __int8 **const a2)

void  CRTComp::FreeColormapPlayerColor(unsigned char * * const) {
  
  int result; // eax
  unsigned int i; // [esp+8h] [ebp-4h]

  for ( i = 254; i > 1; --i )
  {
    (*a2)[i + 1] = (*a2)[i];
    a2[1][i + 1] = a2[1][i];
    a2[2][i + 1] = a2[2][i];
    a2[3][i + 1] = a2[3][i];
  }
  a2[3][2] = 0;
  a2[2][2] = 0;
  a2[1][2] = 0;
  result = 2;
  (*a2)[2] = 0;
  return result;
}


// address=[0x2fd0140]
// Decompiled from unsigned int __thiscall CRTComp::FreeBitmapPlayerColor(CRTComp *this, unsigned __int8 *a2, unsigned int a3)

void  CRTComp::FreeBitmapPlayerColor(unsigned char *,unsigned int) {
  
  unsigned int result; // eax
  unsigned int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < a3; ++i )
  {
    if ( a2[i] )
    {
      if ( a2[i] != 1 )
        ++a2[i];
    }
    result = i + 1;
  }
  return result;
}


// address=[0x2fd01a0]
// Decompiled from struct SM_S_BF_BITMAP_DATA *__thiscall CRTComp::CenterBitmap(CRTComp *this, struct SM_S_BF_BITMAP_DATA *a2)

void  CRTComp::CenterBitmap(struct SM_S_BF_BITMAP_DATA *) {
  
  struct SM_S_BF_BITMAP_DATA *result; // eax
  void *Src; // [esp+1Ch] [ebp-14h]
  int v4; // [esp+20h] [ebp-10h]
  int v5; // [esp+24h] [ebp-Ch]
  int j; // [esp+28h] [ebp-8h]
  int i; // [esp+2Ch] [ebp-4h]

  result = a2;
  if ( *((_DWORD *)a2 + 7) - *((_DWORD *)a2 + 5) == 19 && *((_DWORD *)a2 + 8) - *((_DWORD *)a2 + 6) == 19 )
    return result;
  Src = operator new[](0x191u);
  j__memset(Src, 0, 0x191u);
  v5 = *((_DWORD *)a2 + 7) - *((_DWORD *)a2 + 5) + 1;
  v4 = *((_DWORD *)a2 + 8) - *((_DWORD *)a2 + 6) + 1;
  for ( i = 0; i < v5; ++i )
  {
    for ( j = 0; j < v4; ++j )
      *((_BYTE *)Src + 20 * (10 - (v4 >> 1)) + 20 * j + i + 10 - (v5 >> 1)) = *(_BYTE *)(*((_DWORD *)a2 + 4)
                                                                                       + 20 * (*((_DWORD *)a2 + 6) + j)
                                                                                       + i
                                                                                       + *((_DWORD *)a2 + 5));
  }
  j__memcpy(*((void **)a2 + 4), Src, 0x191u);
  return (struct SM_S_BF_BITMAP_DATA *)operator delete[](Src);
}


// address=[0x2fd0300]
// Decompiled from void *__thiscall CRTComp::CreateMagBorder(CRTComp *this, struct SM_S_BF_BITMAP_DATA *a2)

void  CRTComp::CreateMagBorder(struct SM_S_BF_BITMAP_DATA *) {
  
  void *result; // eax
  void *v3; // [esp+14h] [ebp-Ch]
  int j; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v3 = operator new[](0x1E5u);
  j__memset(v3, 0, 0x1E5u);
  for ( i = 0; i < 20; ++i )
  {
    for ( j = 0; j < 20; ++j )
      *((_BYTE *)v3 + 22 * i + j + 23) = *(_BYTE *)(*((_DWORD *)a2 + 4) + j + 20 * i);
  }
  operator delete[](*((void **)a2 + 4));
  result = v3;
  *((_DWORD *)a2 + 4) = v3;
  *((_DWORD *)a2 + 9) = 22;
  *((_DWORD *)a2 + 10) = 22;
  return result;
}


// address=[0x2fd03d0]
// Decompiled from // private: void __thiscall CRTComp::AddPlayerColor(struct SM_S_BF_BITMAP_DATA *)
void __thiscall CRTComp::AddPlayerColor(CRTComp *this, int a2)

void  CRTComp::AddPlayerColor(struct SM_S_BF_BITMAP_DATA *) {
  
  void *v3; // [esp+14h] [ebp-24h]
  int v4; // [esp+18h] [ebp-20h]
  int v5; // [esp+1Ch] [ebp-1Ch]
  int v6; // [esp+20h] [ebp-18h]
  int v7; // [esp+24h] [ebp-14h]
  int v8; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]
  int k; // [esp+2Ch] [ebp-Ch]
  int n; // [esp+2Ch] [ebp-Ch]
  int kk; // [esp+2Ch] [ebp-Ch]
  int nn; // [esp+2Ch] [ebp-Ch]
  int j; // [esp+30h] [ebp-8h]
  int m; // [esp+30h] [ebp-8h]
  int ii; // [esp+30h] [ebp-8h]
  int jj; // [esp+30h] [ebp-8h]
  int mm; // [esp+30h] [ebp-8h]

  v5 = *(_DWORD *)(a2 + 28) - *(_DWORD *)(a2 + 20) + 1;
  v4 = *(_DWORD *)(a2 + 32) - *(_DWORD *)(a2 + 24) + 1;
  if ( v5 > 18 || v4 > 18 )
  {
    v7 = *(_DWORD *)(a2 + 28) - *(_DWORD *)(a2 + 20) + 4;
    v3 = operator new[]((*(_DWORD *)(a2 + 32) - *(_DWORD *)(a2 + 24) + 4) * v7 + 1);
    j__memset(v3, 0, (v4 + 3) * (v5 + 3));
    for ( i = 0; i < v5; ++i )
    {
      for ( j = 0; j < v4; ++j )
        *((_BYTE *)v3 + v7 * (j + 1) + i + 1) = *(_BYTE *)(*(_DWORD *)(a2 + 16) + i + *(_DWORD *)(a2 + 36) * j);
    }
    operator delete[](*(void **)(a2 + 16));
    *(_DWORD *)(a2 + 16) = v3;
    *(_DWORD *)(a2 + 36) = v7;
    *(_DWORD *)(a2 + 40) = v4 + 3;
  }
  v6 = *(_DWORD *)(a2 + 36);
  v8 = *(_DWORD *)(a2 + 40);
  for ( k = 0; k < v6; ++k )
  {
    for ( m = 1; m < v8; ++m )
    {
      if ( *(unsigned __int8 *)(*(_DWORD *)(a2 + 16) + k + v8 * m) > 1u )
      {
        *(_BYTE *)(*(_DWORD *)(a2 + 16) + k + v8 * (m - 1)) = 2;
        break;
      }
    }
  }
  for ( n = 0; n < v6; ++n )
  {
    for ( ii = v8 - 2; ii > 0; --ii )
    {
      if ( *(unsigned __int8 *)(*(_DWORD *)(a2 + 16) + n + v8 * ii) > 1u )
      {
        *(_BYTE *)(*(_DWORD *)(a2 + 16) + n + v8 * (ii + 1)) = 2;
        break;
      }
    }
  }
  for ( jj = 0; jj < v8; ++jj )
  {
    for ( kk = v6 - 2; kk > 0; --kk )
    {
      if ( *(unsigned __int8 *)(*(_DWORD *)(a2 + 16) + kk + v8 * jj) > 1u )
      {
        *(_BYTE *)(*(_DWORD *)(a2 + 16) + kk + v8 * jj + 1) = 2;
        break;
      }
    }
  }
  for ( mm = v8 - 2; mm >= 0; --mm )
  {
    for ( nn = 1; nn < v6; ++nn )
    {
      if ( *(unsigned __int8 *)(*(_DWORD *)(a2 + 16) + nn + v8 * mm) > 1u )
      {
        *(_BYTE *)(*(_DWORD *)(a2 + 16) + nn + v8 * mm - 1) = 2;
        break;
      }
    }
  }
  CRTComp::CreateBoundingBox(this, (struct SM_S_BF_BITMAP_DATA *)a2);
}


// address=[0x2fd06d0]
// Decompiled from // private: unsigned char * __thiscall CRTComp::MakePanel(struct SM_S_BF_BITMAP_DATA *,bool)
void *__stdcall CRTComp::MakePanel(_DWORD *a1, char a2)

unsigned char *  CRTComp::MakePanel(struct SM_S_BF_BITMAP_DATA *,bool) {
  
  int v3; // [esp+8h] [ebp-20h]
  void *v4; // [esp+14h] [ebp-14h]
  int v5; // [esp+18h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  int k; // [esp+20h] [ebp-8h]
  int j; // [esp+24h] [ebp-4h]
  int m; // [esp+24h] [ebp-4h]

  v4 = operator new[](2 * a1[10] * a1[9] + 1);
  j__memset(v4, 0, 2 * a1[10] * a1[9]);
  v6 = a1[9];
  v3 = a1[10];
  if ( a2 )
  {
    for ( i = 0; i < v3; ++i )
    {
      v5 = i;
      for ( j = 0; j < v6; ++j )
      {
        if ( j > 0 )
        {
          if ( j % 3 )
          {
            if ( (j & 1) == 0 )
              ++v5;
          }
          else
          {
            ++v5;
          }
        }
        *((_BYTE *)v4 + j + v6 * v5) = *(_BYTE *)(a1[4] + j + v6 * i);
      }
    }
  }
  else
  {
    for ( k = 0; k < v3; ++k )
    {
      for ( m = 0; m < v6; ++m )
        *((_BYTE *)v4 + m + v6 * (k + v6 - m - 1)) = *(_BYTE *)(a1[4] + m + v6 * k);
    }
  }
  return v4;
}


// address=[0x2fd0870]
// Decompiled from // private: void __thiscall CRTComp::HalfColorMap(unsigned char * * const)
int __stdcall CRTComp::HalfColorMap(int a1)

void  CRTComp::HalfColorMap(unsigned char * * const) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-8h]
  int j; // [esp+8h] [ebp-4h]

  for ( i = 1; i < 256; ++i )
  {
    for ( j = 0; j < 4; ++j )
      *(_BYTE *)(*(_DWORD *)(a1 + 4 * j) + i) = (int)(float)((float)*(unsigned __int8 *)(*(_DWORD *)(a1 + 4 * j) + i)
                                                           * 0.5);
    result = i + 1;
  }
  return result;
}


// address=[0x2fd08f0]
// Decompiled from int __thiscall CRTComp::EncodeImage(CRTComp *this, unsigned __int8 *a2, unsigned __int8 *a3, int a4, int a5)

int  CRTComp::EncodeImage(unsigned char *,unsigned char *,int,int) {
  
  unsigned __int8 *v7; // [esp+8h] [ebp-20h]
  int v8; // [esp+10h] [ebp-18h]
  int v9; // [esp+14h] [ebp-14h]
  int v10; // [esp+18h] [ebp-10h]
  int v11; // [esp+1Ch] [ebp-Ch]
  int v12; // [esp+20h] [ebp-8h]
  unsigned __int8 *v13; // [esp+24h] [ebp-4h]
  unsigned __int8 *v14; // [esp+24h] [ebp-4h]

  v13 = a3;
  v9 = 255;
  if ( a4 <= 255 )
    v9 = a4;
  v12 = 0;
  v11 = 2;
  v7 = &a2[a5 * a4];
  v10 = a4;
  while ( a2 < v7 )
  {
    v8 = *a2++;
    if ( !v10-- )
      v10 = a4 - 1;
    if ( v8 )
    {
      if ( v8 == 1 )
      {
        if ( v11 == 1 )
        {
          if ( ++v12 > v9 )
          {
            *v13 = v12 - 1;
            v11 = 1;
            v12 = 1;
            v13[1] = 1;
            v13 += 2;
          }
          if ( !v10 )
          {
            *v13++ = v12;
            v11 = 2;
          }
        }
        else
        {
          if ( !v11 )
            *v13++ = v12;
          v11 = 1;
          v12 = 1;
          *v13++ = 1;
        }
      }
      else
      {
        if ( v11 != 2 )
        {
          *v13++ = v12;
          v11 = 2;
        }
        *v13++ = v8;
      }
    }
    else if ( v11 )
    {
      if ( v11 == 1 )
        *v13++ = v12;
      v11 = 0;
      v12 = 1;
      *v13++ = 0;
    }
    else if ( ++v12 > v9 )
    {
      *v13 = v12 - 1;
      v11 = 0;
      v12 = 1;
      v13[1] = 0;
      v13 += 2;
    }
  }
  v14 = v13 - 1;
  *v14 = 1;
  v14[1] = 0;
  return v14 + 1 - a3 + 1;
}


// address=[0x2fd0b30]
// Decompiled from // private: void __thiscall CRTComp::Save8Bitmap(unsigned int,unsigned int,unsigned char *,unsigned char * * const)
FILE *__stdcall CRTComp::Save8Bitmap(size_t ElementCount, unsigned int a2, int a3, _DWORD *a4)

void  CRTComp::Save8Bitmap(unsigned int,unsigned int,unsigned char *,unsigned char * * const) {
  
  FILE *result; // eax
  size_t j; // [esp+4h] [ebp-50h]
  _BYTE v6[4]; // [esp+8h] [ebp-4Ch] BYREF
  FILE *Stream; // [esp+Ch] [ebp-48h]
  char v8; // [esp+13h] [ebp-41h] BYREF
  unsigned int i; // [esp+14h] [ebp-40h]
  _DWORD v10[3]; // [esp+18h] [ebp-3Ch] BYREF
  __int16 v11; // [esp+24h] [ebp-30h]
  __int16 v12; // [esp+26h] [ebp-2Eh]
  int v13; // [esp+28h] [ebp-2Ch]
  size_t v14; // [esp+2Ch] [ebp-28h]
  int v15; // [esp+30h] [ebp-24h]
  int v16; // [esp+34h] [ebp-20h]
  int v17; // [esp+38h] [ebp-1Ch]
  int v18; // [esp+3Ch] [ebp-18h]
  _WORD Buffer[8]; // [esp+40h] [ebp-14h] BYREF

  result = j__fopen("Testbitmap.bmp", "wb");
  Stream = result;
  if ( !result )
    return result;
  j__memset(Buffer, 0, 0xEu);
  Buffer[0] = 19778;
  *(_DWORD *)&Buffer[5] = 1078;
  *(_DWORD *)&Buffer[1] = a2 * ElementCount + 1078;
  v12 = 8;
  v17 = 256;
  v18 = 256;
  v10[1] = 64;
  v10[2] = a2;
  v11 = 1;
  v13 = 0;
  v10[0] = 40;
  v14 = a2 * ElementCount;
  v15 = 1;
  v16 = 1;
  j__fwrite(Buffer, 0xEu, 1u, Stream);
  j__fwrite(v10, 0x28u, 1u, Stream);
  v6[3] = 0;
  for ( i = 0; i < 0x100; ++i )
  {
    v6[2] = *(_BYTE *)(*a4 + i);
    v6[1] = *(_BYTE *)(a4[1] + i);
    v6[0] = *(_BYTE *)(a4[2] + i);
    j__fwrite(v6, 4u, 1u, Stream);
  }
  v8 = 0;
  for ( i = a2; i; --i )
  {
    j__fwrite((const void *)(a3 + ElementCount * (i - 1)), 1u, ElementCount, Stream);
    if ( ElementCount < 0x40 )
    {
      for ( j = 0; j < 64 - ElementCount; ++j )
        j__fwrite(&v8, 1u, 1u, Stream);
    }
  }
  return (FILE *)j__fclose(Stream);
}


