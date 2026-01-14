#include "all_headers.h"

// Definitions for class CDefineTranslator

// address=[0x141dbe0]
// Decompiled from int __thiscall CDefineTranslator::GetValueOfDefine(struct CDefineTranslator *this, struct std::string *a2)
int  CDefineTranslator::GetValueOfDefine(std::string const &)const {
  
  _BYTE v3[12]; // [esp+4h] [ebp-54h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-48h] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-3Ch] BYREF
  int v6; // [esp+28h] [ebp-30h]
  std::_Iterator_base12 *v7; // [esp+2Ch] [ebp-2Ch]
  std::_Iterator_base12 *v8; // [esp+30h] [ebp-28h]
  int v9; // [esp+34h] [ebp-24h]
  int v10; // [esp+38h] [ebp-20h]
  struct CDefineTranslator *v12; // [esp+40h] [ebp-18h]
  int v13; // [esp+44h] [ebp-14h]
  char v14; // [esp+4Bh] [ebp-Dh]
  int v15; // [esp+54h] [ebp-4h]

  v12 = this;
  if ( !std::string::compare((char *)&byte_369F007) )
    return 0;
  std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>(v5);
  v15 = 0;
  v13 = 0;
  v10 = std::_Tree<std::_Tmap_traits<std::string,int,std::less<std::string>,std::allocator<std::pair<std::string const,int>>,0>>::find(
          v4,
          a2);
  v9 = v10;
  LOBYTE(v15) = 1;
  std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>::operator=(v10);
  LOBYTE(v15) = 0;
  std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>::~_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>(v4);
  v8 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<std::string,int,std::less<std::string>,std::allocator<std::pair<std::string const,int>>,0>>::end(v3);
  v7 = v8;
  LOBYTE(v15) = 2;
  v14 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>::operator!=(v8);
  LOBYTE(v15) = 0;
  std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>::~_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>(v3);
  if ( v14 )
    v13 = *(_DWORD *)(std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>::operator*(v5)
                    + 28);
  else
    v13 = 0;
  v6 = v13;
  v15 = -1;
  std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>::~_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>(v5);
  return v6;
}


// address=[0x14f3f70]
// Decompiled from int CDefineTranslator::Instance()
static class CDefineTranslator & __cdecl CDefineTranslator::Instance(void) {
  
  _DWORD *Instance; // eax

  Instance = CDefineTranslator::GetInstance();
  return std::auto_ptr<CDefineTranslator>::operator*(Instance);
}


// address=[0x141dcf0]
// Decompiled from void *CDefineTranslator::GetInstance()
static class std::auto_ptr<class CDefineTranslator> & __cdecl CDefineTranslator::GetInstance(void) {
  
  CDefineTranslator *v1; // [esp+8h] [ebp-14h]
  CDefineTranslator *C; // [esp+Ch] [ebp-10h]

  if ( dword_3EFEB28 <= *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    return &unk_3EFEB24;
  j___Init_thread_header(&dword_3EFEB28);
  if ( dword_3EFEB28 != -1 )
    return &unk_3EFEB24;
  C = (CDefineTranslator *)operator new(0xCu);
  if ( C )
    v1 = CDefineTranslator::CDefineTranslator(C);
  else
    v1 = 0;
  std::auto_ptr<CDefineTranslator>::auto_ptr<CDefineTranslator>(v1);
  j__atexit(sub_3664110);
  j___Init_thread_footer(&dword_3EFEB28);
  return &unk_3EFEB24;
}


// address=[0x141ddd0]
// Decompiled from CDefineTranslator *__thiscall CDefineTranslator::CDefineTranslator(CDefineTranslator *this)
 CDefineTranslator::CDefineTranslator(void) {
  
  CDestructionPhase *v1; // eax
  _BYTE v3[16]; // [esp+4h] [ebp-2388h] BYREF
  _BYTE v4[16]; // [esp+14h] [ebp-2378h] BYREF
  _BYTE v5[16]; // [esp+24h] [ebp-2368h] BYREF
  _BYTE v6[16]; // [esp+34h] [ebp-2358h] BYREF
  _BYTE v7[16]; // [esp+44h] [ebp-2348h] BYREF
  _BYTE v8[16]; // [esp+54h] [ebp-2338h] BYREF
  _BYTE v9[16]; // [esp+64h] [ebp-2328h] BYREF
  _BYTE v10[16]; // [esp+74h] [ebp-2318h] BYREF
  _BYTE v11[16]; // [esp+84h] [ebp-2308h] BYREF
  _BYTE v12[16]; // [esp+94h] [ebp-22F8h] BYREF
  _BYTE v13[16]; // [esp+A4h] [ebp-22E8h] BYREF
  _BYTE v14[16]; // [esp+B4h] [ebp-22D8h] BYREF
  _BYTE v15[16]; // [esp+C4h] [ebp-22C8h] BYREF
  _BYTE v16[16]; // [esp+D4h] [ebp-22B8h] BYREF
  _BYTE v17[16]; // [esp+E4h] [ebp-22A8h] BYREF
  _BYTE v18[16]; // [esp+F4h] [ebp-2298h] BYREF
  _BYTE v19[16]; // [esp+104h] [ebp-2288h] BYREF
  _BYTE v20[16]; // [esp+114h] [ebp-2278h] BYREF
  _BYTE v21[16]; // [esp+124h] [ebp-2268h] BYREF
  _BYTE v22[16]; // [esp+134h] [ebp-2258h] BYREF
  _BYTE v23[16]; // [esp+144h] [ebp-2248h] BYREF
  _BYTE v24[16]; // [esp+154h] [ebp-2238h] BYREF
  _BYTE v25[16]; // [esp+164h] [ebp-2228h] BYREF
  _BYTE v26[16]; // [esp+174h] [ebp-2218h] BYREF
  _BYTE v27[16]; // [esp+184h] [ebp-2208h] BYREF
  _BYTE v28[16]; // [esp+194h] [ebp-21F8h] BYREF
  _BYTE v29[16]; // [esp+1A4h] [ebp-21E8h] BYREF
  _BYTE v30[16]; // [esp+1B4h] [ebp-21D8h] BYREF
  _BYTE v31[16]; // [esp+1C4h] [ebp-21C8h] BYREF
  _BYTE v32[16]; // [esp+1D4h] [ebp-21B8h] BYREF
  _BYTE v33[16]; // [esp+1E4h] [ebp-21A8h] BYREF
  _BYTE v34[16]; // [esp+1F4h] [ebp-2198h] BYREF
  _BYTE v35[16]; // [esp+204h] [ebp-2188h] BYREF
  _BYTE v36[16]; // [esp+214h] [ebp-2178h] BYREF
  _BYTE v37[16]; // [esp+224h] [ebp-2168h] BYREF
  _BYTE v38[16]; // [esp+234h] [ebp-2158h] BYREF
  _BYTE v39[16]; // [esp+244h] [ebp-2148h] BYREF
  _BYTE v40[16]; // [esp+254h] [ebp-2138h] BYREF
  _BYTE v41[16]; // [esp+264h] [ebp-2128h] BYREF
  _BYTE v42[16]; // [esp+274h] [ebp-2118h] BYREF
  _BYTE v43[16]; // [esp+284h] [ebp-2108h] BYREF
  _BYTE v44[16]; // [esp+294h] [ebp-20F8h] BYREF
  _BYTE v45[16]; // [esp+2A4h] [ebp-20E8h] BYREF
  _BYTE v46[16]; // [esp+2B4h] [ebp-20D8h] BYREF
  _BYTE v47[16]; // [esp+2C4h] [ebp-20C8h] BYREF
  _BYTE v48[16]; // [esp+2D4h] [ebp-20B8h] BYREF
  _BYTE v49[16]; // [esp+2E4h] [ebp-20A8h] BYREF
  _BYTE v50[16]; // [esp+2F4h] [ebp-2098h] BYREF
  _BYTE v51[16]; // [esp+304h] [ebp-2088h] BYREF
  _BYTE v52[16]; // [esp+314h] [ebp-2078h] BYREF
  _BYTE v53[16]; // [esp+324h] [ebp-2068h] BYREF
  _BYTE v54[16]; // [esp+334h] [ebp-2058h] BYREF
  _BYTE v55[16]; // [esp+344h] [ebp-2048h] BYREF
  _BYTE v56[16]; // [esp+354h] [ebp-2038h] BYREF
  _BYTE v57[16]; // [esp+364h] [ebp-2028h] BYREF
  _BYTE v58[16]; // [esp+374h] [ebp-2018h] BYREF
  _BYTE v59[16]; // [esp+384h] [ebp-2008h] BYREF
  _BYTE v60[16]; // [esp+394h] [ebp-1FF8h] BYREF
  _BYTE v61[16]; // [esp+3A4h] [ebp-1FE8h] BYREF
  _BYTE v62[16]; // [esp+3B4h] [ebp-1FD8h] BYREF
  _BYTE v63[16]; // [esp+3C4h] [ebp-1FC8h] BYREF
  _BYTE v64[16]; // [esp+3D4h] [ebp-1FB8h] BYREF
  _BYTE v65[16]; // [esp+3E4h] [ebp-1FA8h] BYREF
  _BYTE v66[16]; // [esp+3F4h] [ebp-1F98h] BYREF
  _BYTE v67[16]; // [esp+404h] [ebp-1F88h] BYREF
  _BYTE v68[16]; // [esp+414h] [ebp-1F78h] BYREF
  _BYTE v69[16]; // [esp+424h] [ebp-1F68h] BYREF
  _BYTE v70[16]; // [esp+434h] [ebp-1F58h] BYREF
  _BYTE v71[16]; // [esp+444h] [ebp-1F48h] BYREF
  _BYTE v72[16]; // [esp+454h] [ebp-1F38h] BYREF
  _BYTE v73[16]; // [esp+464h] [ebp-1F28h] BYREF
  _BYTE v74[16]; // [esp+474h] [ebp-1F18h] BYREF
  _BYTE v75[16]; // [esp+484h] [ebp-1F08h] BYREF
  _BYTE v76[16]; // [esp+494h] [ebp-1EF8h] BYREF
  _BYTE v77[16]; // [esp+4A4h] [ebp-1EE8h] BYREF
  _BYTE v78[16]; // [esp+4B4h] [ebp-1ED8h] BYREF
  _BYTE v79[16]; // [esp+4C4h] [ebp-1EC8h] BYREF
  _BYTE v80[16]; // [esp+4D4h] [ebp-1EB8h] BYREF
  _BYTE v81[16]; // [esp+4E4h] [ebp-1EA8h] BYREF
  _BYTE v82[16]; // [esp+4F4h] [ebp-1E98h] BYREF
  _BYTE v83[16]; // [esp+504h] [ebp-1E88h] BYREF
  _BYTE v84[16]; // [esp+514h] [ebp-1E78h] BYREF
  _BYTE v85[16]; // [esp+524h] [ebp-1E68h] BYREF
  _BYTE v86[16]; // [esp+534h] [ebp-1E58h] BYREF
  _BYTE v87[16]; // [esp+544h] [ebp-1E48h] BYREF
  _BYTE v88[16]; // [esp+554h] [ebp-1E38h] BYREF
  _BYTE v89[16]; // [esp+564h] [ebp-1E28h] BYREF
  _BYTE v90[16]; // [esp+574h] [ebp-1E18h] BYREF
  _BYTE v91[16]; // [esp+584h] [ebp-1E08h] BYREF
  _BYTE v92[16]; // [esp+594h] [ebp-1DF8h] BYREF
  _BYTE v93[16]; // [esp+5A4h] [ebp-1DE8h] BYREF
  _BYTE v94[16]; // [esp+5B4h] [ebp-1DD8h] BYREF
  _BYTE v95[16]; // [esp+5C4h] [ebp-1DC8h] BYREF
  _BYTE v96[16]; // [esp+5D4h] [ebp-1DB8h] BYREF
  _BYTE v97[16]; // [esp+5E4h] [ebp-1DA8h] BYREF
  _BYTE v98[16]; // [esp+5F4h] [ebp-1D98h] BYREF
  _BYTE v99[16]; // [esp+604h] [ebp-1D88h] BYREF
  _BYTE v100[16]; // [esp+614h] [ebp-1D78h] BYREF
  _BYTE v101[16]; // [esp+624h] [ebp-1D68h] BYREF
  _BYTE v102[16]; // [esp+634h] [ebp-1D58h] BYREF
  _BYTE v103[16]; // [esp+644h] [ebp-1D48h] BYREF
  _BYTE v104[16]; // [esp+654h] [ebp-1D38h] BYREF
  _BYTE v105[16]; // [esp+664h] [ebp-1D28h] BYREF
  _BYTE v106[16]; // [esp+674h] [ebp-1D18h] BYREF
  _BYTE v107[16]; // [esp+684h] [ebp-1D08h] BYREF
  _BYTE v108[16]; // [esp+694h] [ebp-1CF8h] BYREF
  _BYTE v109[16]; // [esp+6A4h] [ebp-1CE8h] BYREF
  _BYTE v110[16]; // [esp+6B4h] [ebp-1CD8h] BYREF
  _BYTE v111[16]; // [esp+6C4h] [ebp-1CC8h] BYREF
  _BYTE v112[16]; // [esp+6D4h] [ebp-1CB8h] BYREF
  _BYTE v113[16]; // [esp+6E4h] [ebp-1CA8h] BYREF
  _BYTE v114[16]; // [esp+6F4h] [ebp-1C98h] BYREF
  _BYTE v115[16]; // [esp+704h] [ebp-1C88h] BYREF
  _BYTE v116[16]; // [esp+714h] [ebp-1C78h] BYREF
  _BYTE v117[16]; // [esp+724h] [ebp-1C68h] BYREF
  _BYTE v118[16]; // [esp+734h] [ebp-1C58h] BYREF
  _BYTE v119[16]; // [esp+744h] [ebp-1C48h] BYREF
  _BYTE v120[16]; // [esp+754h] [ebp-1C38h] BYREF
  _BYTE v121[16]; // [esp+764h] [ebp-1C28h] BYREF
  _BYTE v122[16]; // [esp+774h] [ebp-1C18h] BYREF
  _BYTE v123[16]; // [esp+784h] [ebp-1C08h] BYREF
  _BYTE v124[16]; // [esp+794h] [ebp-1BF8h] BYREF
  _BYTE v125[16]; // [esp+7A4h] [ebp-1BE8h] BYREF
  _BYTE v126[16]; // [esp+7B4h] [ebp-1BD8h] BYREF
  _BYTE v127[16]; // [esp+7C4h] [ebp-1BC8h] BYREF
  _BYTE v128[16]; // [esp+7D4h] [ebp-1BB8h] BYREF
  _BYTE v129[16]; // [esp+7E4h] [ebp-1BA8h] BYREF
  _BYTE v130[16]; // [esp+7F4h] [ebp-1B98h] BYREF
  _BYTE v131[16]; // [esp+804h] [ebp-1B88h] BYREF
  _BYTE v132[16]; // [esp+814h] [ebp-1B78h] BYREF
  _BYTE v133[16]; // [esp+824h] [ebp-1B68h] BYREF
  _BYTE v134[16]; // [esp+834h] [ebp-1B58h] BYREF
  _BYTE v135[16]; // [esp+844h] [ebp-1B48h] BYREF
  _BYTE v136[16]; // [esp+854h] [ebp-1B38h] BYREF
  _BYTE v137[16]; // [esp+864h] [ebp-1B28h] BYREF
  _BYTE v138[16]; // [esp+874h] [ebp-1B18h] BYREF
  _BYTE v139[16]; // [esp+884h] [ebp-1B08h] BYREF
  _BYTE v140[16]; // [esp+894h] [ebp-1AF8h] BYREF
  _BYTE v141[16]; // [esp+8A4h] [ebp-1AE8h] BYREF
  _BYTE v142[16]; // [esp+8B4h] [ebp-1AD8h] BYREF
  _BYTE v143[16]; // [esp+8C4h] [ebp-1AC8h] BYREF
  _BYTE v144[16]; // [esp+8D4h] [ebp-1AB8h] BYREF
  _BYTE v145[16]; // [esp+8E4h] [ebp-1AA8h] BYREF
  _BYTE v146[16]; // [esp+8F4h] [ebp-1A98h] BYREF
  _BYTE v147[16]; // [esp+904h] [ebp-1A88h] BYREF
  _BYTE v148[16]; // [esp+914h] [ebp-1A78h] BYREF
  _BYTE v149[16]; // [esp+924h] [ebp-1A68h] BYREF
  _BYTE v150[16]; // [esp+934h] [ebp-1A58h] BYREF
  _BYTE v151[16]; // [esp+944h] [ebp-1A48h] BYREF
  _BYTE v152[16]; // [esp+954h] [ebp-1A38h] BYREF
  _BYTE v153[16]; // [esp+964h] [ebp-1A28h] BYREF
  _BYTE v154[16]; // [esp+974h] [ebp-1A18h] BYREF
  _BYTE v155[16]; // [esp+984h] [ebp-1A08h] BYREF
  _BYTE v156[16]; // [esp+994h] [ebp-19F8h] BYREF
  _BYTE v157[16]; // [esp+9A4h] [ebp-19E8h] BYREF
  _BYTE v158[16]; // [esp+9B4h] [ebp-19D8h] BYREF
  _BYTE v159[16]; // [esp+9C4h] [ebp-19C8h] BYREF
  _BYTE v160[16]; // [esp+9D4h] [ebp-19B8h] BYREF
  _BYTE v161[16]; // [esp+9E4h] [ebp-19A8h] BYREF
  _BYTE v162[16]; // [esp+9F4h] [ebp-1998h] BYREF
  _BYTE v163[16]; // [esp+A04h] [ebp-1988h] BYREF
  _BYTE v164[16]; // [esp+A14h] [ebp-1978h] BYREF
  _BYTE v165[16]; // [esp+A24h] [ebp-1968h] BYREF
  _BYTE v166[16]; // [esp+A34h] [ebp-1958h] BYREF
  _BYTE v167[16]; // [esp+A44h] [ebp-1948h] BYREF
  _BYTE v168[16]; // [esp+A54h] [ebp-1938h] BYREF
  _BYTE v169[16]; // [esp+A64h] [ebp-1928h] BYREF
  _BYTE v170[16]; // [esp+A74h] [ebp-1918h] BYREF
  _BYTE v171[16]; // [esp+A84h] [ebp-1908h] BYREF
  _BYTE v172[16]; // [esp+A94h] [ebp-18F8h] BYREF
  _BYTE v173[16]; // [esp+AA4h] [ebp-18E8h] BYREF
  _BYTE v174[16]; // [esp+AB4h] [ebp-18D8h] BYREF
  _BYTE v175[16]; // [esp+AC4h] [ebp-18C8h] BYREF
  _BYTE v176[4]; // [esp+AD4h] [ebp-18B8h] BYREF
  int v177; // [esp+AD8h] [ebp-18B4h]
  int v178; // [esp+ADCh] [ebp-18B0h]
  int v179; // [esp+AE0h] [ebp-18ACh]
  int v180; // [esp+AE4h] [ebp-18A8h]
  int v181; // [esp+AE8h] [ebp-18A4h]
  int v182; // [esp+AECh] [ebp-18A0h]
  int v183; // [esp+AF0h] [ebp-189Ch]
  int v184; // [esp+AF4h] [ebp-1898h]
  int v185; // [esp+AF8h] [ebp-1894h]
  int v186; // [esp+AFCh] [ebp-1890h]
  int v187; // [esp+B00h] [ebp-188Ch]
  int v188; // [esp+B04h] [ebp-1888h]
  int v189; // [esp+B08h] [ebp-1884h]
  int v190; // [esp+B0Ch] [ebp-1880h]
  int v191; // [esp+B10h] [ebp-187Ch]
  int v192; // [esp+B14h] [ebp-1878h]
  int v193; // [esp+B18h] [ebp-1874h]
  int v194; // [esp+B1Ch] [ebp-1870h]
  int v195; // [esp+B20h] [ebp-186Ch]
  int v196; // [esp+B24h] [ebp-1868h]
  int v197; // [esp+B28h] [ebp-1864h]
  int v198; // [esp+B2Ch] [ebp-1860h]
  int v199; // [esp+B30h] [ebp-185Ch]
  int v200; // [esp+B34h] [ebp-1858h]
  int v201; // [esp+B38h] [ebp-1854h]
  int v202; // [esp+B3Ch] [ebp-1850h]
  int v203; // [esp+B40h] [ebp-184Ch]
  int v204; // [esp+B44h] [ebp-1848h]
  int v205; // [esp+B48h] [ebp-1844h]
  int v206; // [esp+B4Ch] [ebp-1840h]
  int v207; // [esp+B50h] [ebp-183Ch]
  int v208; // [esp+B54h] [ebp-1838h]
  int v209; // [esp+B58h] [ebp-1834h]
  int v210; // [esp+B5Ch] [ebp-1830h]
  int v211; // [esp+B60h] [ebp-182Ch]
  int v212; // [esp+B64h] [ebp-1828h]
  int v213; // [esp+B68h] [ebp-1824h]
  int v214; // [esp+B6Ch] [ebp-1820h]
  int v215; // [esp+B70h] [ebp-181Ch]
  int v216; // [esp+B74h] [ebp-1818h]
  int v217; // [esp+B78h] [ebp-1814h]
  int v218; // [esp+B7Ch] [ebp-1810h]
  int v219; // [esp+B80h] [ebp-180Ch]
  int v220; // [esp+B84h] [ebp-1808h]
  int v221; // [esp+B88h] [ebp-1804h]
  int v222; // [esp+B8Ch] [ebp-1800h]
  int v223; // [esp+B90h] [ebp-17FCh]
  int v224; // [esp+B94h] [ebp-17F8h]
  int v225; // [esp+B98h] [ebp-17F4h]
  int v226; // [esp+B9Ch] [ebp-17F0h]
  int v227; // [esp+BA0h] [ebp-17ECh]
  int v228; // [esp+BA4h] [ebp-17E8h]
  int v229; // [esp+BA8h] [ebp-17E4h]
  int v230; // [esp+BACh] [ebp-17E0h]
  int v231; // [esp+BB0h] [ebp-17DCh]
  int v232; // [esp+BB4h] [ebp-17D8h]
  int v233; // [esp+BB8h] [ebp-17D4h]
  int v234; // [esp+BBCh] [ebp-17D0h]
  int v235; // [esp+BC0h] [ebp-17CCh]
  int v236; // [esp+BC4h] [ebp-17C8h]
  int v237; // [esp+BC8h] [ebp-17C4h]
  int v238; // [esp+BCCh] [ebp-17C0h]
  int v239; // [esp+BD0h] [ebp-17BCh]
  int v240; // [esp+BD4h] [ebp-17B8h]
  int v241; // [esp+BD8h] [ebp-17B4h]
  int v242; // [esp+BDCh] [ebp-17B0h]
  int v243; // [esp+BE0h] [ebp-17ACh]
  int v244; // [esp+BE4h] [ebp-17A8h]
  int v245; // [esp+BE8h] [ebp-17A4h]
  int v246; // [esp+BECh] [ebp-17A0h]
  int v247; // [esp+BF0h] [ebp-179Ch]
  int v248; // [esp+BF4h] [ebp-1798h]
  int v249; // [esp+BF8h] [ebp-1794h]
  int v250; // [esp+BFCh] [ebp-1790h]
  int v251; // [esp+C00h] [ebp-178Ch]
  int v252; // [esp+C04h] [ebp-1788h]
  int v253; // [esp+C08h] [ebp-1784h]
  int v254; // [esp+C0Ch] [ebp-1780h]
  int v255; // [esp+C10h] [ebp-177Ch]
  int v256; // [esp+C14h] [ebp-1778h]
  int v257; // [esp+C18h] [ebp-1774h]
  int v258; // [esp+C1Ch] [ebp-1770h]
  int v259; // [esp+C20h] [ebp-176Ch]
  int v260; // [esp+C24h] [ebp-1768h]
  int v261; // [esp+C28h] [ebp-1764h]
  int v262; // [esp+C2Ch] [ebp-1760h]
  int v263; // [esp+C30h] [ebp-175Ch]
  int v264; // [esp+C34h] [ebp-1758h]
  int v265; // [esp+C38h] [ebp-1754h]
  int v266; // [esp+C3Ch] [ebp-1750h]
  int v267; // [esp+C40h] [ebp-174Ch]
  int v268; // [esp+C44h] [ebp-1748h]
  int v269; // [esp+C48h] [ebp-1744h]
  int v270; // [esp+C4Ch] [ebp-1740h]
  int v271; // [esp+C50h] [ebp-173Ch]
  int v272; // [esp+C54h] [ebp-1738h]
  int v273; // [esp+C58h] [ebp-1734h]
  int v274; // [esp+C5Ch] [ebp-1730h]
  int v275; // [esp+C60h] [ebp-172Ch]
  int v276; // [esp+C64h] [ebp-1728h]
  int v277; // [esp+C68h] [ebp-1724h]
  int v278; // [esp+C6Ch] [ebp-1720h]
  int v279; // [esp+C70h] [ebp-171Ch]
  int v280; // [esp+C74h] [ebp-1718h]
  int v281; // [esp+C78h] [ebp-1714h]
  int v282; // [esp+C7Ch] [ebp-1710h]
  int v283; // [esp+C80h] [ebp-170Ch]
  int v284; // [esp+C84h] [ebp-1708h]
  int v285; // [esp+C88h] [ebp-1704h]
  int v286; // [esp+C8Ch] [ebp-1700h]
  int v287; // [esp+C90h] [ebp-16FCh]
  int v288; // [esp+C94h] [ebp-16F8h]
  int v289; // [esp+C98h] [ebp-16F4h]
  int v290; // [esp+C9Ch] [ebp-16F0h]
  int v291; // [esp+CA0h] [ebp-16ECh]
  int v292; // [esp+CA4h] [ebp-16E8h]
  int v293; // [esp+CA8h] [ebp-16E4h]
  int v294; // [esp+CACh] [ebp-16E0h]
  int v295; // [esp+CB0h] [ebp-16DCh]
  int v296; // [esp+CB4h] [ebp-16D8h]
  int v297; // [esp+CB8h] [ebp-16D4h]
  int v298; // [esp+CBCh] [ebp-16D0h]
  int v299; // [esp+CC0h] [ebp-16CCh]
  int v300; // [esp+CC4h] [ebp-16C8h]
  int v301; // [esp+CC8h] [ebp-16C4h]
  int v302; // [esp+CCCh] [ebp-16C0h]
  int v303; // [esp+CD0h] [ebp-16BCh]
  int v304; // [esp+CD4h] [ebp-16B8h]
  int v305; // [esp+CD8h] [ebp-16B4h]
  int v306; // [esp+CDCh] [ebp-16B0h]
  int v307; // [esp+CE0h] [ebp-16ACh]
  int v308; // [esp+CE4h] [ebp-16A8h]
  int v309; // [esp+CE8h] [ebp-16A4h]
  int v310; // [esp+CECh] [ebp-16A0h]
  int v311; // [esp+CF0h] [ebp-169Ch]
  int v312; // [esp+CF4h] [ebp-1698h]
  int v313; // [esp+CF8h] [ebp-1694h]
  int v314; // [esp+CFCh] [ebp-1690h]
  int v315; // [esp+D00h] [ebp-168Ch]
  int v316; // [esp+D04h] [ebp-1688h]
  int v317; // [esp+D08h] [ebp-1684h]
  int v318; // [esp+D0Ch] [ebp-1680h]
  int v319; // [esp+D10h] [ebp-167Ch]
  int v320; // [esp+D14h] [ebp-1678h]
  int v321; // [esp+D18h] [ebp-1674h]
  int v322; // [esp+D1Ch] [ebp-1670h]
  int v323; // [esp+D20h] [ebp-166Ch]
  int v324; // [esp+D24h] [ebp-1668h]
  int v325; // [esp+D28h] [ebp-1664h]
  int v326; // [esp+D2Ch] [ebp-1660h]
  int v327; // [esp+D30h] [ebp-165Ch]
  int v328; // [esp+D34h] [ebp-1658h]
  int v329; // [esp+D38h] [ebp-1654h]
  int v330; // [esp+D3Ch] [ebp-1650h]
  int v331; // [esp+D40h] [ebp-164Ch]
  int v332; // [esp+D44h] [ebp-1648h]
  int v333; // [esp+D48h] [ebp-1644h]
  int v334; // [esp+D4Ch] [ebp-1640h]
  int v335; // [esp+D50h] [ebp-163Ch]
  int v336; // [esp+D54h] [ebp-1638h]
  int v337; // [esp+D58h] [ebp-1634h]
  int v338; // [esp+D5Ch] [ebp-1630h]
  int v339; // [esp+D60h] [ebp-162Ch]
  int v340; // [esp+D64h] [ebp-1628h]
  int v341; // [esp+D68h] [ebp-1624h]
  int v342; // [esp+D6Ch] [ebp-1620h]
  int v343; // [esp+D70h] [ebp-161Ch]
  int v344; // [esp+D74h] [ebp-1618h]
  int v345; // [esp+D78h] [ebp-1614h]
  int v346; // [esp+D7Ch] [ebp-1610h]
  int v347; // [esp+D80h] [ebp-160Ch]
  int v348; // [esp+D84h] [ebp-1608h]
  int v349; // [esp+D88h] [ebp-1604h]
  int v350; // [esp+D8Ch] [ebp-1600h]
  int v351; // [esp+D90h] [ebp-15FCh]
  CDefineTranslator *v353; // [esp+D98h] [ebp-15F4h]
  int v354; // [esp+D9Ch] [ebp-15F0h] BYREF
  _BYTE v355[32]; // [esp+DA0h] [ebp-15ECh] BYREF
  _BYTE v356[32]; // [esp+DC0h] [ebp-15CCh] BYREF
  _BYTE v357[32]; // [esp+DE0h] [ebp-15ACh] BYREF
  _BYTE v358[32]; // [esp+E00h] [ebp-158Ch] BYREF
  _BYTE v359[32]; // [esp+E20h] [ebp-156Ch] BYREF
  _BYTE v360[32]; // [esp+E40h] [ebp-154Ch] BYREF
  _BYTE v361[32]; // [esp+E60h] [ebp-152Ch] BYREF
  _BYTE v362[32]; // [esp+E80h] [ebp-150Ch] BYREF
  _BYTE v363[32]; // [esp+EA0h] [ebp-14ECh] BYREF
  _BYTE v364[32]; // [esp+EC0h] [ebp-14CCh] BYREF
  _BYTE v365[32]; // [esp+EE0h] [ebp-14ACh] BYREF
  _BYTE v366[32]; // [esp+F00h] [ebp-148Ch] BYREF
  _BYTE v367[32]; // [esp+F20h] [ebp-146Ch] BYREF
  _BYTE v368[32]; // [esp+F40h] [ebp-144Ch] BYREF
  _BYTE v369[32]; // [esp+F60h] [ebp-142Ch] BYREF
  _BYTE v370[32]; // [esp+F80h] [ebp-140Ch] BYREF
  _BYTE v371[32]; // [esp+FA0h] [ebp-13ECh] BYREF
  _BYTE v372[32]; // [esp+FC0h] [ebp-13CCh] BYREF
  _BYTE v373[32]; // [esp+FE0h] [ebp-13ACh] BYREF
  _BYTE v374[32]; // [esp+1000h] [ebp-138Ch] BYREF
  _BYTE v375[32]; // [esp+1020h] [ebp-136Ch] BYREF
  _BYTE v376[32]; // [esp+1040h] [ebp-134Ch] BYREF
  _BYTE v377[32]; // [esp+1060h] [ebp-132Ch] BYREF
  _BYTE v378[32]; // [esp+1080h] [ebp-130Ch] BYREF
  _BYTE v379[32]; // [esp+10A0h] [ebp-12ECh] BYREF
  _BYTE v380[32]; // [esp+10C0h] [ebp-12CCh] BYREF
  _BYTE v381[32]; // [esp+10E0h] [ebp-12ACh] BYREF
  _BYTE v382[32]; // [esp+1100h] [ebp-128Ch] BYREF
  _BYTE v383[32]; // [esp+1120h] [ebp-126Ch] BYREF
  _BYTE v384[32]; // [esp+1140h] [ebp-124Ch] BYREF
  _BYTE v385[32]; // [esp+1160h] [ebp-122Ch] BYREF
  _BYTE v386[32]; // [esp+1180h] [ebp-120Ch] BYREF
  _BYTE v387[32]; // [esp+11A0h] [ebp-11ECh] BYREF
  _BYTE v388[32]; // [esp+11C0h] [ebp-11CCh] BYREF
  _BYTE v389[32]; // [esp+11E0h] [ebp-11ACh] BYREF
  _BYTE v390[32]; // [esp+1200h] [ebp-118Ch] BYREF
  _BYTE v391[32]; // [esp+1220h] [ebp-116Ch] BYREF
  _BYTE v392[32]; // [esp+1240h] [ebp-114Ch] BYREF
  _BYTE v393[32]; // [esp+1260h] [ebp-112Ch] BYREF
  _BYTE v394[32]; // [esp+1280h] [ebp-110Ch] BYREF
  _BYTE v395[32]; // [esp+12A0h] [ebp-10ECh] BYREF
  _BYTE v396[32]; // [esp+12C0h] [ebp-10CCh] BYREF
  _BYTE v397[32]; // [esp+12E0h] [ebp-10ACh] BYREF
  _BYTE v398[32]; // [esp+1300h] [ebp-108Ch] BYREF
  _BYTE v399[32]; // [esp+1320h] [ebp-106Ch] BYREF
  _BYTE v400[32]; // [esp+1340h] [ebp-104Ch] BYREF
  _BYTE v401[32]; // [esp+1360h] [ebp-102Ch] BYREF
  _BYTE v402[32]; // [esp+1380h] [ebp-100Ch] BYREF
  _BYTE v403[32]; // [esp+13A0h] [ebp-FECh] BYREF
  _BYTE v404[32]; // [esp+13C0h] [ebp-FCCh] BYREF
  _BYTE v405[32]; // [esp+13E0h] [ebp-FACh] BYREF
  _BYTE v406[32]; // [esp+1400h] [ebp-F8Ch] BYREF
  _BYTE v407[32]; // [esp+1420h] [ebp-F6Ch] BYREF
  _BYTE v408[32]; // [esp+1440h] [ebp-F4Ch] BYREF
  _BYTE v409[32]; // [esp+1460h] [ebp-F2Ch] BYREF
  _BYTE v410[32]; // [esp+1480h] [ebp-F0Ch] BYREF
  _BYTE v411[32]; // [esp+14A0h] [ebp-EECh] BYREF
  _BYTE v412[32]; // [esp+14C0h] [ebp-ECCh] BYREF
  _BYTE v413[32]; // [esp+14E0h] [ebp-EACh] BYREF
  _BYTE v414[32]; // [esp+1500h] [ebp-E8Ch] BYREF
  _BYTE v415[32]; // [esp+1520h] [ebp-E6Ch] BYREF
  _BYTE v416[32]; // [esp+1540h] [ebp-E4Ch] BYREF
  _BYTE v417[32]; // [esp+1560h] [ebp-E2Ch] BYREF
  _BYTE v418[32]; // [esp+1580h] [ebp-E0Ch] BYREF
  _BYTE v419[32]; // [esp+15A0h] [ebp-DECh] BYREF
  _BYTE v420[32]; // [esp+15C0h] [ebp-DCCh] BYREF
  _BYTE v421[32]; // [esp+15E0h] [ebp-DACh] BYREF
  _BYTE v422[32]; // [esp+1600h] [ebp-D8Ch] BYREF
  _BYTE v423[32]; // [esp+1620h] [ebp-D6Ch] BYREF
  _BYTE v424[32]; // [esp+1640h] [ebp-D4Ch] BYREF
  _BYTE v425[32]; // [esp+1660h] [ebp-D2Ch] BYREF
  _BYTE v426[32]; // [esp+1680h] [ebp-D0Ch] BYREF
  _BYTE v427[32]; // [esp+16A0h] [ebp-CECh] BYREF
  _BYTE v428[32]; // [esp+16C0h] [ebp-CCCh] BYREF
  _BYTE v429[32]; // [esp+16E0h] [ebp-CACh] BYREF
  _BYTE v430[32]; // [esp+1700h] [ebp-C8Ch] BYREF
  _BYTE v431[32]; // [esp+1720h] [ebp-C6Ch] BYREF
  _BYTE v432[32]; // [esp+1740h] [ebp-C4Ch] BYREF
  _BYTE v433[32]; // [esp+1760h] [ebp-C2Ch] BYREF
  _BYTE v434[32]; // [esp+1780h] [ebp-C0Ch] BYREF
  _BYTE v435[32]; // [esp+17A0h] [ebp-BECh] BYREF
  _BYTE v436[32]; // [esp+17C0h] [ebp-BCCh] BYREF
  _BYTE v437[32]; // [esp+17E0h] [ebp-BACh] BYREF
  _BYTE v438[32]; // [esp+1800h] [ebp-B8Ch] BYREF
  _BYTE v439[32]; // [esp+1820h] [ebp-B6Ch] BYREF
  _BYTE v440[32]; // [esp+1840h] [ebp-B4Ch] BYREF
  _BYTE v441[32]; // [esp+1860h] [ebp-B2Ch] BYREF
  _BYTE v442[32]; // [esp+1880h] [ebp-B0Ch] BYREF
  _BYTE v443[32]; // [esp+18A0h] [ebp-AECh] BYREF
  _BYTE v444[32]; // [esp+18C0h] [ebp-ACCh] BYREF
  _BYTE v445[32]; // [esp+18E0h] [ebp-AACh] BYREF
  _BYTE v446[32]; // [esp+1900h] [ebp-A8Ch] BYREF
  _BYTE v447[32]; // [esp+1920h] [ebp-A6Ch] BYREF
  _BYTE v448[32]; // [esp+1940h] [ebp-A4Ch] BYREF
  _BYTE v449[32]; // [esp+1960h] [ebp-A2Ch] BYREF
  _BYTE v450[32]; // [esp+1980h] [ebp-A0Ch] BYREF
  _BYTE v451[32]; // [esp+19A0h] [ebp-9ECh] BYREF
  _BYTE v452[32]; // [esp+19C0h] [ebp-9CCh] BYREF
  _BYTE v453[32]; // [esp+19E0h] [ebp-9ACh] BYREF
  _BYTE v454[32]; // [esp+1A00h] [ebp-98Ch] BYREF
  _BYTE v455[32]; // [esp+1A20h] [ebp-96Ch] BYREF
  _BYTE v456[32]; // [esp+1A40h] [ebp-94Ch] BYREF
  _BYTE v457[32]; // [esp+1A60h] [ebp-92Ch] BYREF
  _BYTE v458[32]; // [esp+1A80h] [ebp-90Ch] BYREF
  _BYTE v459[32]; // [esp+1AA0h] [ebp-8ECh] BYREF
  _BYTE v460[32]; // [esp+1AC0h] [ebp-8CCh] BYREF
  _BYTE v461[32]; // [esp+1AE0h] [ebp-8ACh] BYREF
  _BYTE v462[32]; // [esp+1B00h] [ebp-88Ch] BYREF
  _BYTE v463[32]; // [esp+1B20h] [ebp-86Ch] BYREF
  _BYTE v464[32]; // [esp+1B40h] [ebp-84Ch] BYREF
  _BYTE v465[32]; // [esp+1B60h] [ebp-82Ch] BYREF
  _BYTE v466[32]; // [esp+1B80h] [ebp-80Ch] BYREF
  _BYTE v467[32]; // [esp+1BA0h] [ebp-7ECh] BYREF
  _BYTE v468[32]; // [esp+1BC0h] [ebp-7CCh] BYREF
  _BYTE v469[32]; // [esp+1BE0h] [ebp-7ACh] BYREF
  _BYTE v470[32]; // [esp+1C00h] [ebp-78Ch] BYREF
  _BYTE v471[32]; // [esp+1C20h] [ebp-76Ch] BYREF
  _BYTE v472[32]; // [esp+1C40h] [ebp-74Ch] BYREF
  _BYTE v473[32]; // [esp+1C60h] [ebp-72Ch] BYREF
  _BYTE v474[32]; // [esp+1C80h] [ebp-70Ch] BYREF
  _BYTE v475[32]; // [esp+1CA0h] [ebp-6ECh] BYREF
  _BYTE v476[32]; // [esp+1CC0h] [ebp-6CCh] BYREF
  _BYTE v477[32]; // [esp+1CE0h] [ebp-6ACh] BYREF
  _BYTE v478[32]; // [esp+1D00h] [ebp-68Ch] BYREF
  _BYTE v479[32]; // [esp+1D20h] [ebp-66Ch] BYREF
  _BYTE v480[32]; // [esp+1D40h] [ebp-64Ch] BYREF
  _BYTE v481[32]; // [esp+1D60h] [ebp-62Ch] BYREF
  _BYTE v482[32]; // [esp+1D80h] [ebp-60Ch] BYREF
  _BYTE v483[32]; // [esp+1DA0h] [ebp-5ECh] BYREF
  _BYTE v484[32]; // [esp+1DC0h] [ebp-5CCh] BYREF
  _BYTE v485[32]; // [esp+1DE0h] [ebp-5ACh] BYREF
  _BYTE v486[32]; // [esp+1E00h] [ebp-58Ch] BYREF
  _BYTE v487[32]; // [esp+1E20h] [ebp-56Ch] BYREF
  _BYTE v488[32]; // [esp+1E40h] [ebp-54Ch] BYREF
  _BYTE v489[32]; // [esp+1E60h] [ebp-52Ch] BYREF
  _BYTE v490[32]; // [esp+1E80h] [ebp-50Ch] BYREF
  _BYTE v491[32]; // [esp+1EA0h] [ebp-4ECh] BYREF
  _BYTE v492[32]; // [esp+1EC0h] [ebp-4CCh] BYREF
  _BYTE v493[32]; // [esp+1EE0h] [ebp-4ACh] BYREF
  _BYTE v494[32]; // [esp+1F00h] [ebp-48Ch] BYREF
  _BYTE v495[32]; // [esp+1F20h] [ebp-46Ch] BYREF
  _BYTE v496[32]; // [esp+1F40h] [ebp-44Ch] BYREF
  _BYTE v497[32]; // [esp+1F60h] [ebp-42Ch] BYREF
  _BYTE v498[32]; // [esp+1F80h] [ebp-40Ch] BYREF
  _BYTE v499[32]; // [esp+1FA0h] [ebp-3ECh] BYREF
  _BYTE v500[32]; // [esp+1FC0h] [ebp-3CCh] BYREF
  _BYTE v501[32]; // [esp+1FE0h] [ebp-3ACh] BYREF
  _BYTE v502[32]; // [esp+2000h] [ebp-38Ch] BYREF
  _BYTE v503[32]; // [esp+2020h] [ebp-36Ch] BYREF
  _BYTE v504[32]; // [esp+2040h] [ebp-34Ch] BYREF
  _BYTE v505[32]; // [esp+2060h] [ebp-32Ch] BYREF
  _BYTE v506[32]; // [esp+2080h] [ebp-30Ch] BYREF
  _BYTE v507[32]; // [esp+20A0h] [ebp-2ECh] BYREF
  _BYTE v508[32]; // [esp+20C0h] [ebp-2CCh] BYREF
  _BYTE v509[32]; // [esp+20E0h] [ebp-2ACh] BYREF
  _BYTE v510[32]; // [esp+2100h] [ebp-28Ch] BYREF
  _BYTE v511[32]; // [esp+2120h] [ebp-26Ch] BYREF
  _BYTE v512[32]; // [esp+2140h] [ebp-24Ch] BYREF
  _BYTE v513[32]; // [esp+2160h] [ebp-22Ch] BYREF
  _BYTE v514[32]; // [esp+2180h] [ebp-20Ch] BYREF
  _BYTE v515[32]; // [esp+21A0h] [ebp-1ECh] BYREF
  _BYTE v516[32]; // [esp+21C0h] [ebp-1CCh] BYREF
  _BYTE v517[32]; // [esp+21E0h] [ebp-1ACh] BYREF
  _BYTE v518[32]; // [esp+2200h] [ebp-18Ch] BYREF
  _BYTE v519[32]; // [esp+2220h] [ebp-16Ch] BYREF
  _BYTE v520[32]; // [esp+2240h] [ebp-14Ch] BYREF
  _BYTE v521[32]; // [esp+2260h] [ebp-12Ch] BYREF
  _BYTE v522[32]; // [esp+2280h] [ebp-10Ch] BYREF
  _BYTE v523[32]; // [esp+22A0h] [ebp-ECh] BYREF
  _BYTE v524[32]; // [esp+22C0h] [ebp-CCh] BYREF
  _BYTE v525[32]; // [esp+22E0h] [ebp-ACh] BYREF
  _BYTE v526[32]; // [esp+2300h] [ebp-8Ch] BYREF
  _BYTE v527[32]; // [esp+2320h] [ebp-6Ch] BYREF
  _BYTE v528[32]; // [esp+2340h] [ebp-4Ch] BYREF
  _BYTE v529[28]; // [esp+2360h] [ebp-2Ch] BYREF
  int v530; // [esp+2388h] [ebp-4h]

  v353 = this;
  std::map<std::string,int>::map<std::string,int>(this);
  v530 = 1;
  if ( operator new(0xCu) )
  {
    v1 = CDestructionPhase::CDestructionPhase((CDestructionPhase *)v176, 1);
    v351 = TDestructor<CDefineTranslator>::TDestructor<CDefineTranslator>(v353, *(_DWORD *)v1);
  }
  else
  {
    v351 = 0;
  }
  v177 = v351;
  LOBYTE(v530) = 0;
  std::string::string();
  LOBYTE(v530) = 2;
  v354 = 0;
  std::make_pair<std::string &,int &>(v528, v529, &v354);
  LOBYTE(v530) = 3;
  std::string::operator=(v529, "RACE_ROMAN");
  v354 = 0;
  v265 = std::make_pair<std::string &,int &>(v441, v529, &v354);
  std::pair<std::string,int>::operator=(v265);
  std::pair<std::string,int>::~pair<std::string,int>(v441);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v92, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v92);
  std::string::operator=(v529, "RACE_VIKING");
  v354 = 1;
  v264 = std::make_pair<std::string &,int &>(v442, v529, &v354);
  std::pair<std::string,int>::operator=(v264);
  std::pair<std::string,int>::~pair<std::string,int>(v442);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v93, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v93);
  std::string::operator=(v529, "RACE_MAYA");
  v354 = 2;
  v263 = std::make_pair<std::string &,int &>(v443, v529, &v354);
  std::pair<std::string,int>::operator=(v263);
  std::pair<std::string,int>::~pair<std::string,int>(v443);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v94, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v94);
  std::string::operator=(v529, "RACE_DARK");
  v354 = 3;
  v262 = std::make_pair<std::string &,int &>(v444, v529, &v354);
  std::pair<std::string,int>::operator=(v262);
  std::pair<std::string,int>::~pair<std::string,int>(v444);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v95, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v95);
  std::string::operator=(v529, "RACE_TROJAN");
  v354 = 4;
  v261 = std::make_pair<std::string &,int &>(v445, v529, &v354);
  std::pair<std::string,int>::operator=(v261);
  std::pair<std::string,int>::~pair<std::string,int>(v445);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v96, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v96);
  std::string::operator=(v529, "PERMANENT");
  v354 = 0;
  v260 = std::make_pair<std::string &,int &>(v446, v529, &v354);
  std::pair<std::string,int>::operator=(v260);
  std::pair<std::string,int>::~pair<std::string,int>(v446);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v97, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v97);
  std::string::operator=(v529, "TIMED");
  v354 = 1;
  v259 = std::make_pair<std::string &,int &>(v447, v529, &v354);
  std::pair<std::string,int>::operator=(v259);
  std::pair<std::string,int>::~pair<std::string,int>(v447);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v98, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v98);
  std::string::operator=(v529, "EVENT");
  v354 = 2;
  v258 = std::make_pair<std::string &,int &>(v448, v529, &v354);
  std::pair<std::string,int>::operator=(v258);
  std::pair<std::string,int>::~pair<std::string,int>(v448);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v99, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v99);
  std::string::operator=(v529, "TRIGGER_MILLER_WORK");
  v354 = 3;
  v257 = std::make_pair<std::string &,int &>(v449, v529, &v354);
  std::pair<std::string,int>::operator=(v257);
  std::pair<std::string,int>::~pair<std::string,int>(v449);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v100, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v100);
  std::string::operator=(v529, "TRIGGER_BAKER_WORK");
  v354 = 4;
  v256 = std::make_pair<std::string &,int &>(v450, v529, &v354);
  std::pair<std::string,int>::operator=(v256);
  std::pair<std::string,int>::~pair<std::string,int>(v450);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v101, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v101);
  std::string::operator=(v529, "TRIGGER_BAKER_SMALLSMOKE");
  v354 = 5;
  v255 = std::make_pair<std::string &,int &>(v451, v529, &v354);
  std::pair<std::string,int>::operator=(v255);
  std::pair<std::string,int>::~pair<std::string,int>(v451);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v102, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v102);
  std::string::operator=(v529, "TRIGGER_COALMINE_PUSHOUT");
  v354 = 1;
  v254 = std::make_pair<std::string &,int &>(v452, v529, &v354);
  std::pair<std::string,int>::operator=(v254);
  std::pair<std::string,int>::~pair<std::string,int>(v452);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v103, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v103);
  std::string::operator=(v529, "TRIGGER_COALMINE_PUSHIN");
  v354 = 2;
  v253 = std::make_pair<std::string &,int &>(v453, v529, &v354);
  std::pair<std::string,int>::operator=(v253);
  std::pair<std::string,int>::~pair<std::string,int>(v453);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v104, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v104);
  std::string::operator=(v529, "TRIGGER_SMELTGOLD_MELTED");
  v354 = 6;
  v252 = std::make_pair<std::string &,int &>(v454, v529, &v354);
  std::pair<std::string,int>::operator=(v252);
  std::pair<std::string,int>::~pair<std::string,int>(v454);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v105, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v105);
  std::string::operator=(v529, "TRIGGER_SMELTGOLD_SMOKE");
  v354 = 7;
  v251 = std::make_pair<std::string &,int &>(v455, v529, &v354);
  std::pair<std::string,int>::operator=(v251);
  std::pair<std::string,int>::~pair<std::string,int>(v455);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v106, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v106);
  std::string::operator=(v529, "TRIGGER_SMELTIRON_MELTED");
  v354 = 8;
  v250 = std::make_pair<std::string &,int &>(v456, v529, &v354);
  std::pair<std::string,int>::operator=(v250);
  std::pair<std::string,int>::~pair<std::string,int>(v456);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v107, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v107);
  std::string::operator=(v529, "TRIGGER_SMELTIRON_SMOKE");
  v354 = 9;
  v249 = std::make_pair<std::string &,int &>(v457, v529, &v354);
  std::pair<std::string,int>::operator=(v249);
  std::pair<std::string,int>::~pair<std::string,int>(v457);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v108, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v108);
  std::string::operator=(v529, "TRIGGER_TOOLSMITH_SMOKE");
  v354 = 10;
  v248 = std::make_pair<std::string &,int &>(v458, v529, &v354);
  std::pair<std::string,int>::operator=(v248);
  std::pair<std::string,int>::~pair<std::string,int>(v458);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v109, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v109);
  std::string::operator=(v529, "TRIGGER_TOOLSMITH_SMALLSMOKE");
  v354 = 11;
  v247 = std::make_pair<std::string &,int &>(v459, v529, &v354);
  std::pair<std::string,int>::operator=(v247);
  std::pair<std::string,int>::~pair<std::string,int>(v459);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v110, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v110);
  std::string::operator=(v529, "TRIGGER_WEAPONSMITH_SMOKE");
  v354 = 12;
  v246 = std::make_pair<std::string &,int &>(v460, v529, &v354);
  std::pair<std::string,int>::operator=(v246);
  std::pair<std::string,int>::~pair<std::string,int>(v460);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v111, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v111);
  std::string::operator=(v529, "TRIGGER_WEAPONSMITH_SMALLSMOKE");
  v354 = 13;
  v245 = std::make_pair<std::string &,int &>(v461, v529, &v354);
  std::pair<std::string,int>::operator=(v245);
  std::pair<std::string,int>::~pair<std::string,int>(v461);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v112, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v112);
  std::string::operator=(v529, "TRIGGER_SMALLTOWER_DAMAGE_SMOKE");
  v354 = 14;
  v244 = std::make_pair<std::string &,int &>(v440, v529, &v354);
  std::pair<std::string,int>::operator=(v244);
  std::pair<std::string,int>::~pair<std::string,int>(v440);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v113, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v113);
  std::string::operator=(v529, "TRIGGER_BIGTOWER_DAMAGE_SMOKE");
  v354 = 15;
  v243 = std::make_pair<std::string &,int &>(v462, v529, &v354);
  std::pair<std::string,int>::operator=(v243);
  std::pair<std::string,int>::~pair<std::string,int>(v462);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v114, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v114);
  std::string::operator=(v529, "TRIGGER_LOOKOUT");
  v354 = 16;
  v242 = std::make_pair<std::string &,int &>(v464, v529, &v354);
  std::pair<std::string,int>::operator=(v242);
  std::pair<std::string,int>::~pair<std::string,int>(v464);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v115, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v115);
  std::string::operator=(v529, "TRIGGER_START_SLOT0");
  v354 = 17;
  v241 = std::make_pair<std::string &,int &>(v465, v529, &v354);
  std::pair<std::string,int>::operator=(v241);
  std::pair<std::string,int>::~pair<std::string,int>(v465);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v116, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v116);
  std::string::operator=(v529, "TRIGGER_START_SLOT1");
  v354 = 18;
  v240 = std::make_pair<std::string &,int &>(v466, v529, &v354);
  std::pair<std::string,int>::operator=(v240);
  std::pair<std::string,int>::~pair<std::string,int>(v466);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v117, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v117);
  std::string::operator=(v529, "TRIGGER_START_SLOT2");
  v354 = 19;
  v239 = std::make_pair<std::string &,int &>(v467, v529, &v354);
  std::pair<std::string,int>::operator=(v239);
  std::pair<std::string,int>::~pair<std::string,int>(v467);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v118, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v118);
  std::string::operator=(v529, "TRIGGER_START_SLOT3");
  v354 = 20;
  v238 = std::make_pair<std::string &,int &>(v468, v529, &v354);
  std::pair<std::string,int>::operator=(v238);
  std::pair<std::string,int>::~pair<std::string,int>(v468);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v119, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v119);
  std::string::operator=(v529, "TRIGGER_START_SLOT4");
  v354 = 21;
  v237 = std::make_pair<std::string &,int &>(v469, v529, &v354);
  std::pair<std::string,int>::operator=(v237);
  std::pair<std::string,int>::~pair<std::string,int>(v469);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v120, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v120);
  std::string::operator=(v529, "TRIGGER_START_SLOT5");
  v354 = 22;
  v236 = std::make_pair<std::string &,int &>(v470, v529, &v354);
  std::pair<std::string,int>::operator=(v236);
  std::pair<std::string,int>::~pair<std::string,int>(v470);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v121, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v121);
  std::string::operator=(v529, "TRIGGER_START_SLOT6");
  v354 = 23;
  v235 = std::make_pair<std::string &,int &>(v471, v529, &v354);
  std::pair<std::string,int>::operator=(v235);
  std::pair<std::string,int>::~pair<std::string,int>(v471);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v122, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v122);
  std::string::operator=(v529, "TRIGGER_START_SLOT7");
  v354 = 24;
  v234 = std::make_pair<std::string &,int &>(v472, v529, &v354);
  std::pair<std::string,int>::operator=(v234);
  std::pair<std::string,int>::~pair<std::string,int>(v472);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v123, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v123);
  std::string::operator=(v529, "TRIGGER_START_SLOT8");
  v354 = 25;
  v233 = std::make_pair<std::string &,int &>(v473, v529, &v354);
  std::pair<std::string,int>::operator=(v233);
  std::pair<std::string,int>::~pair<std::string,int>(v473);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v124, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v124);
  std::string::operator=(v529, "TRIGGER_START_SLOT9");
  v354 = 26;
  v232 = std::make_pair<std::string &,int &>(v474, v529, &v354);
  std::pair<std::string,int>::operator=(v232);
  std::pair<std::string,int>::~pair<std::string,int>(v474);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v125, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v125);
  std::string::operator=(v529, "TRIGGER_STOP_SLOT0");
  v354 = 27;
  v231 = std::make_pair<std::string &,int &>(v475, v529, &v354);
  std::pair<std::string,int>::operator=(v231);
  std::pair<std::string,int>::~pair<std::string,int>(v475);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v126, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v126);
  std::string::operator=(v529, "TRIGGER_STOP_SLOT1");
  v354 = 28;
  v230 = std::make_pair<std::string &,int &>(v476, v529, &v354);
  std::pair<std::string,int>::operator=(v230);
  std::pair<std::string,int>::~pair<std::string,int>(v476);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v127, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v127);
  std::string::operator=(v529, "TRIGGER_STOP_SLOT2");
  v354 = 29;
  v229 = std::make_pair<std::string &,int &>(v477, v529, &v354);
  std::pair<std::string,int>::operator=(v229);
  std::pair<std::string,int>::~pair<std::string,int>(v477);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v128, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v128);
  std::string::operator=(v529, "TRIGGER_STOP_SLOT3");
  v354 = 30;
  v228 = std::make_pair<std::string &,int &>(v478, v529, &v354);
  std::pair<std::string,int>::operator=(v228);
  std::pair<std::string,int>::~pair<std::string,int>(v478);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v129, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v129);
  std::string::operator=(v529, "TRIGGER_STOP_SLOT4");
  v354 = 31;
  v227 = std::make_pair<std::string &,int &>(v479, v529, &v354);
  std::pair<std::string,int>::operator=(v227);
  std::pair<std::string,int>::~pair<std::string,int>(v479);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v130, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v130);
  std::string::operator=(v529, "TRIGGER_STOP_SLOT5");
  v354 = 32;
  v226 = std::make_pair<std::string &,int &>(v480, v529, &v354);
  std::pair<std::string,int>::operator=(v226);
  std::pair<std::string,int>::~pair<std::string,int>(v480);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v131, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v131);
  std::string::operator=(v529, "TRIGGER_STOP_SLOT6");
  v354 = 33;
  v225 = std::make_pair<std::string &,int &>(v481, v529, &v354);
  std::pair<std::string,int>::operator=(v225);
  std::pair<std::string,int>::~pair<std::string,int>(v481);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v132, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v132);
  std::string::operator=(v529, "TRIGGER_STOP_SLOT7");
  v354 = 34;
  v224 = std::make_pair<std::string &,int &>(v482, v529, &v354);
  std::pair<std::string,int>::operator=(v224);
  std::pair<std::string,int>::~pair<std::string,int>(v482);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v133, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v133);
  std::string::operator=(v529, "TRIGGER_STOP_SLOT8");
  v354 = 35;
  v223 = std::make_pair<std::string &,int &>(v483, v529, &v354);
  std::pair<std::string,int>::operator=(v223);
  std::pair<std::string,int>::~pair<std::string,int>(v483);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v134, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v134);
  std::string::operator=(v529, "TRIGGER_STOP_SLOT9");
  v354 = 36;
  v222 = std::make_pair<std::string &,int &>(v505, v529, &v354);
  std::pair<std::string,int>::operator=(v222);
  std::pair<std::string,int>::~pair<std::string,int>(v505);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v135, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v135);
  std::string::operator=(v529, "TRIGGER_CLEAR_SLOT0");
  v354 = 37;
  v221 = std::make_pair<std::string &,int &>(v484, v529, &v354);
  std::pair<std::string,int>::operator=(v221);
  std::pair<std::string,int>::~pair<std::string,int>(v484);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v136, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v136);
  std::string::operator=(v529, "TRIGGER_CLEAR_SLOT1");
  v354 = 38;
  v220 = std::make_pair<std::string &,int &>(v485, v529, &v354);
  std::pair<std::string,int>::operator=(v220);
  std::pair<std::string,int>::~pair<std::string,int>(v485);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v137, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v137);
  std::string::operator=(v529, "TRIGGER_CLEAR_SLOT2");
  v354 = 39;
  v219 = std::make_pair<std::string &,int &>(v486, v529, &v354);
  std::pair<std::string,int>::operator=(v219);
  std::pair<std::string,int>::~pair<std::string,int>(v486);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v138, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v138);
  std::string::operator=(v529, "TRIGGER_CLEAR_SLOT3");
  v354 = 40;
  v218 = std::make_pair<std::string &,int &>(v487, v529, &v354);
  std::pair<std::string,int>::operator=(v218);
  std::pair<std::string,int>::~pair<std::string,int>(v487);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v139, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v139);
  std::string::operator=(v529, "TRIGGER_CLEAR_SLOT4");
  v354 = 41;
  v217 = std::make_pair<std::string &,int &>(v488, v529, &v354);
  std::pair<std::string,int>::operator=(v217);
  std::pair<std::string,int>::~pair<std::string,int>(v488);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v140, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v140);
  std::string::operator=(v529, "TRIGGER_CLEAR_SLOT5");
  v354 = 42;
  v216 = std::make_pair<std::string &,int &>(v489, v529, &v354);
  std::pair<std::string,int>::operator=(v216);
  std::pair<std::string,int>::~pair<std::string,int>(v489);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v141, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v141);
  std::string::operator=(v529, "TRIGGER_CLEAR_SLOT6");
  v354 = 43;
  v215 = std::make_pair<std::string &,int &>(v490, v529, &v354);
  std::pair<std::string,int>::operator=(v215);
  std::pair<std::string,int>::~pair<std::string,int>(v490);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v142, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v142);
  std::string::operator=(v529, "TRIGGER_CLEAR_SLOT7");
  v354 = 44;
  v214 = std::make_pair<std::string &,int &>(v491, v529, &v354);
  std::pair<std::string,int>::operator=(v214);
  std::pair<std::string,int>::~pair<std::string,int>(v491);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v143, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v143);
  std::string::operator=(v529, "TRIGGER_CLEAR_SLOT8");
  v354 = 45;
  v213 = std::make_pair<std::string &,int &>(v492, v529, &v354);
  std::pair<std::string,int>::operator=(v213);
  std::pair<std::string,int>::~pair<std::string,int>(v492);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v144, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v144);
  std::string::operator=(v529, "TRIGGER_CLEAR_SLOT9");
  v354 = 46;
  v212 = std::make_pair<std::string &,int &>(v493, v529, &v354);
  std::pair<std::string,int>::operator=(v212);
  std::pair<std::string,int>::~pair<std::string,int>(v493);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v145, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v145);
  std::string::operator=(v529, "HOUSE_KIND_BUILDINGSITE");
  v354 = 0;
  v211 = std::make_pair<std::string &,int &>(v494, v529, &v354);
  std::pair<std::string,int>::operator=(v211);
  std::pair<std::string,int>::~pair<std::string,int>(v494);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v146, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v146);
  std::string::operator=(v529, "HOUSE_KIND_SIMPLE");
  v354 = 1;
  v210 = std::make_pair<std::string &,int &>(v495, v529, &v354);
  std::pair<std::string,int>::operator=(v210);
  std::pair<std::string,int>::~pair<std::string,int>(v495);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v147, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v147);
  std::string::operator=(v529, "HOUSE_KIND_PRODUCTION");
  v354 = 4;
  v209 = std::make_pair<std::string &,int &>(v496, v529, &v354);
  std::pair<std::string,int>::operator=(v209);
  std::pair<std::string,int>::~pair<std::string,int>(v496);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v148, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v148);
  std::string::operator=(v529, "HOUSE_KIND_WORKSHOP");
  v354 = 5;
  v208 = std::make_pair<std::string &,int &>(v497, v529, &v354);
  std::pair<std::string,int>::operator=(v208);
  std::pair<std::string,int>::~pair<std::string,int>(v497);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v149, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v149);
  std::string::operator=(v529, "HOUSE_KIND_MILITARY");
  v354 = 10;
  v207 = std::make_pair<std::string &,int &>(v498, v529, &v354);
  std::pair<std::string,int>::operator=(v207);
  std::pair<std::string,int>::~pair<std::string,int>(v498);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v150, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v150);
  std::string::operator=(v529, "HOUSE_KIND_BARRACK");
  v354 = 11;
  v206 = std::make_pair<std::string &,int &>(v499, v529, &v354);
  std::pair<std::string,int>::operator=(v206);
  std::pair<std::string,int>::~pair<std::string,int>(v499);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v151, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v151);
  std::string::operator=(v529, "HOUSE_KIND_STORAGE");
  v354 = 12;
  v205 = std::make_pair<std::string &,int &>(v500, v529, &v354);
  std::pair<std::string,int>::operator=(v205);
  std::pair<std::string,int>::~pair<std::string,int>(v500);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v152, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v152);
  std::string::operator=(v529, "HOUSE_KIND_GATHER");
  v354 = 6;
  v266 = std::make_pair<std::string &,int &>(v501, v529, &v354);
  std::pair<std::string,int>::operator=(v266);
  std::pair<std::string,int>::~pair<std::string,int>(v501);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v153, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v153);
  std::string::operator=(v529, "HOUSE_KIND_TRADE");
  v354 = 13;
  v204 = std::make_pair<std::string &,int &>(v502, v529, &v354);
  std::pair<std::string,int>::operator=(v204);
  std::pair<std::string,int>::~pair<std::string,int>(v502);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v154, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v154);
  std::string::operator=(v529, "HOUSE_KIND_RESIDENCE");
  v354 = 14;
  v203 = std::make_pair<std::string &,int &>(v503, v529, &v354);
  std::pair<std::string,int>::operator=(v203);
  std::pair<std::string,int>::~pair<std::string,int>(v503);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v155, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v155);
  std::string::operator=(v529, "HOUSE_KIND_MINE");
  v354 = 7;
  v202 = std::make_pair<std::string &,int &>(v504, v529, &v354);
  std::pair<std::string,int>::operator=(v202);
  std::pair<std::string,int>::~pair<std::string,int>(v504);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v156, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v156);
  std::string::operator=(v529, "HOUSE_KIND_WORKUP");
  v354 = 2;
  v201 = std::make_pair<std::string &,int &>(v527, v529, &v354);
  std::pair<std::string,int>::operator=(v201);
  std::pair<std::string,int>::~pair<std::string,int>(v527);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v157, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v157);
  std::string::operator=(v529, "HOUSE_KIND_ANIMALRANCH");
  v354 = 3;
  v200 = std::make_pair<std::string &,int &>(v506, v529, &v354);
  std::pair<std::string,int>::operator=(v200);
  std::pair<std::string,int>::~pair<std::string,int>(v506);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v158, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v158);
  std::string::operator=(v529, "HOUSE_KIND_FARM");
  v354 = 8;
  v199 = std::make_pair<std::string &,int &>(v507, v529, &v354);
  std::pair<std::string,int>::operator=(v199);
  std::pair<std::string,int>::~pair<std::string,int>(v507);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v159, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v159);
  std::string::operator=(v529, "HOUSE_KIND_LOOKOUTTOWER");
  v354 = 9;
  v198 = std::make_pair<std::string &,int &>(v508, v529, &v354);
  std::pair<std::string,int>::operator=(v198);
  std::pair<std::string,int>::~pair<std::string,int>(v508);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v160, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v160);
  std::string::operator=(v529, "HOUSE_KIND_CASTLE");
  v354 = 15;
  v197 = std::make_pair<std::string &,int &>(v509, v529, &v354);
  std::pair<std::string,int>::operator=(v197);
  std::pair<std::string,int>::~pair<std::string,int>(v509);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v161, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v161);
  std::string::operator=(v529, "HOUSE_KIND_SMALLTEMPLE");
  v354 = 16;
  v196 = std::make_pair<std::string &,int &>(v510, v529, &v354);
  std::pair<std::string,int>::operator=(v196);
  std::pair<std::string,int>::~pair<std::string,int>(v510);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v162, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v162);
  std::string::operator=(v529, "HOUSE_KIND_BIGTEMPLE");
  v354 = 17;
  v195 = std::make_pair<std::string &,int &>(v511, v529, &v354);
  std::pair<std::string,int>::operator=(v195);
  std::pair<std::string,int>::~pair<std::string,int>(v511);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v163, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v163);
  std::string::operator=(v529, "HOUSE_KIND_DARKTEMPLE");
  v354 = 18;
  v194 = std::make_pair<std::string &,int &>(v512, v529, &v354);
  std::pair<std::string,int>::operator=(v194);
  std::pair<std::string,int>::~pair<std::string,int>(v512);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v164, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v164);
  std::string::operator=(v529, "HOUSE_KIND_EYECATCHER");
  v354 = 19;
  v193 = std::make_pair<std::string &,int &>(v513, v529, &v354);
  std::pair<std::string,int>::operator=(v193);
  std::pair<std::string,int>::~pair<std::string,int>(v513);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v165, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v165);
  std::string::operator=(v529, "HOUSE_KIND_MUSHROOMFARM");
  v354 = 20;
  v192 = std::make_pair<std::string &,int &>(v514, v529, &v354);
  std::pair<std::string,int>::operator=(v192);
  std::pair<std::string,int>::~pair<std::string,int>(v514);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v166, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v166);
  std::string::operator=(v529, "HOUSE_KIND_MANAKOPTERHALL");
  v354 = 21;
  v191 = std::make_pair<std::string &,int &>(v515, v529, &v354);
  std::pair<std::string,int>::operator=(v191);
  std::pair<std::string,int>::~pair<std::string,int>(v515);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v167, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v167);
  std::string::operator=(v529, "SEARCH_NO_SEARCH");
  v354 = 0;
  v190 = std::make_pair<std::string &,int &>(v516, v529, &v354);
  std::pair<std::string,int>::operator=(v190);
  std::pair<std::string,int>::~pair<std::string,int>(v516);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v168, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v168);
  std::string::operator=(v529, "SEARCH_FISH");
  v354 = 1;
  v189 = std::make_pair<std::string &,int &>(v517, v529, &v354);
  std::pair<std::string,int>::operator=(v189);
  std::pair<std::string,int>::~pair<std::string,int>(v517);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v169, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v169);
  std::string::operator=(v529, "SEARCH_GRAIN_SEED_POS");
  v354 = 2;
  v188 = std::make_pair<std::string &,int &>(v518, v529, &v354);
  std::pair<std::string,int>::operator=(v188);
  std::pair<std::string,int>::~pair<std::string,int>(v518);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v170, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v170);
  std::string::operator=(v529, "SEARCH_GRAIN");
  v354 = 3;
  v187 = std::make_pair<std::string &,int &>(v519, v529, &v354);
  std::pair<std::string,int>::operator=(v187);
  std::pair<std::string,int>::~pair<std::string,int>(v519);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v171, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v171);
  std::string::operator=(v529, "SEARCH_AGAVE_SEED_POS");
  v354 = 4;
  v186 = std::make_pair<std::string &,int &>(v520, v529, &v354);
  std::pair<std::string,int>::operator=(v186);
  std::pair<std::string,int>::~pair<std::string,int>(v520);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v172, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v172);
  std::string::operator=(v529, "SEARCH_AGAVE");
  v354 = 5;
  v185 = std::make_pair<std::string &,int &>(v521, v529, &v354);
  std::pair<std::string,int>::operator=(v185);
  std::pair<std::string,int>::~pair<std::string,int>(v521);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v173, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v173);
  std::string::operator=(v529, "SEARCH_SUNFLOWER_SEED_POS");
  v354 = 25;
  v184 = std::make_pair<std::string &,int &>(v522, v529, &v354);
  std::pair<std::string,int>::operator=(v184);
  std::pair<std::string,int>::~pair<std::string,int>(v522);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v174, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v174);
  std::string::operator=(v529, "SEARCH_SUNFLOWER");
  v354 = 26;
  v183 = std::make_pair<std::string &,int &>(v523, v529, &v354);
  std::pair<std::string,int>::operator=(v183);
  std::pair<std::string,int>::~pair<std::string,int>(v523);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v175, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v175);
  std::string::operator=(v529, "SEARCH_TREE_SEED_POS");
  v354 = 6;
  v182 = std::make_pair<std::string &,int &>(v439, v529, &v354);
  std::pair<std::string,int>::operator=(v182);
  std::pair<std::string,int>::~pair<std::string,int>(v439);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v68, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v68);
  std::string::operator=(v529, "SEARCH_TREE_SEED_POS_MAYA");
  v354 = 7;
  v181 = std::make_pair<std::string &,int &>(v438, v529, &v354);
  std::pair<std::string,int>::operator=(v181);
  std::pair<std::string,int>::~pair<std::string,int>(v438);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v91, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v91);
  std::string::operator=(v529, "SEARCH_TREE");
  v354 = 8;
  v180 = std::make_pair<std::string &,int &>(v437, v529, &v354);
  std::pair<std::string,int>::operator=(v180);
  std::pair<std::string,int>::~pair<std::string,int>(v437);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v90, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v90);
  std::string::operator=(v529, "SEARCH_VINE_SEED_POS");
  v354 = 9;
  v179 = std::make_pair<std::string &,int &>(v436, v529, &v354);
  std::pair<std::string,int>::operator=(v179);
  std::pair<std::string,int>::~pair<std::string,int>(v436);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v89, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v89);
  std::string::operator=(v529, "SEARCH_VINE");
  v354 = 10;
  v178 = std::make_pair<std::string &,int &>(v435, v529, &v354);
  std::pair<std::string,int>::operator=(v178);
  std::pair<std::string,int>::~pair<std::string,int>(v435);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v88, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v88);
  std::string::operator=(v529, "SEARCH_BEEHIVE_SEED_POS");
  v354 = 11;
  v350 = std::make_pair<std::string &,int &>(v434, v529, &v354);
  std::pair<std::string,int>::operator=(v350);
  std::pair<std::string,int>::~pair<std::string,int>(v434);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v87, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v87);
  std::string::operator=(v529, "SEARCH_BEEHIVE");
  v354 = 12;
  v349 = std::make_pair<std::string &,int &>(v433, v529, &v354);
  std::pair<std::string,int>::operator=(v349);
  std::pair<std::string,int>::~pair<std::string,int>(v433);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v86, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v86);
  std::string::operator=(v529, "SEARCH_MUSHROOM_SEED_POS");
  v354 = 13;
  v348 = std::make_pair<std::string &,int &>(v432, v529, &v354);
  std::pair<std::string,int>::operator=(v348);
  std::pair<std::string,int>::~pair<std::string,int>(v432);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v85, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v85);
  std::string::operator=(v529, "SEARCH_MUSHROOM");
  v354 = 14;
  v347 = std::make_pair<std::string &,int &>(v431, v529, &v354);
  std::pair<std::string,int>::operator=(v347);
  std::pair<std::string,int>::~pair<std::string,int>(v431);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v84, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v84);
  std::string::operator=(v529, "SEARCH_STONE");
  v354 = 15;
  v346 = std::make_pair<std::string &,int &>(v430, v529, &v354);
  std::pair<std::string,int>::operator=(v346);
  std::pair<std::string,int>::~pair<std::string,int>(v430);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v83, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v83);
  std::string::operator=(v529, "SEARCH_VENISON");
  v354 = 16;
  v345 = std::make_pair<std::string &,int &>(v429, v529, &v354);
  std::pair<std::string,int>::operator=(v345);
  std::pair<std::string,int>::~pair<std::string,int>(v429);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v82, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v82);
  std::string::operator=(v529, "SEARCH_WATER");
  v354 = 17;
  v344 = std::make_pair<std::string &,int &>(v428, v529, &v354);
  std::pair<std::string,int>::operator=(v344);
  std::pair<std::string,int>::~pair<std::string,int>(v428);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v81, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v81);
  std::string::operator=(v529, "SEARCH_GOLD");
  v354 = 18;
  v343 = std::make_pair<std::string &,int &>(v427, v529, &v354);
  std::pair<std::string,int>::operator=(v343);
  std::pair<std::string,int>::~pair<std::string,int>(v427);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v80, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v80);
  std::string::operator=(v529, "SEARCH_IRON");
  v354 = 19;
  v342 = std::make_pair<std::string &,int &>(v426, v529, &v354);
  std::pair<std::string,int>::operator=(v342);
  std::pair<std::string,int>::~pair<std::string,int>(v426);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v79, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v79);
  std::string::operator=(v529, "SEARCH_COAL");
  v354 = 20;
  v341 = std::make_pair<std::string &,int &>(v425, v529, &v354);
  std::pair<std::string,int>::operator=(v341);
  std::pair<std::string,int>::~pair<std::string,int>(v425);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v78, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v78);
  std::string::operator=(v529, "SEARCH_GRANITE");
  v354 = 21;
  v340 = std::make_pair<std::string &,int &>(v424, v529, &v354);
  std::pair<std::string,int>::operator=(v340);
  std::pair<std::string,int>::~pair<std::string,int>(v424);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v77, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v77);
  std::string::operator=(v529, "SEARCH_SULFUR");
  v354 = 22;
  v339 = std::make_pair<std::string &,int &>(v423, v529, &v354);
  std::pair<std::string,int>::operator=(v339);
  std::pair<std::string,int>::~pair<std::string,int>(v423);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v76, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v76);
  std::string::operator=(v529, "SEARCH_DARK_LAND");
  v354 = 23;
  v338 = std::make_pair<std::string &,int &>(v422, v529, &v354);
  std::pair<std::string,int>::operator=(v338);
  std::pair<std::string,int>::~pair<std::string,int>(v422);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v75, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v75);
  std::string::operator=(v529, "SEARCH_GREEN_LAND");
  v354 = 24;
  v337 = std::make_pair<std::string &,int &>(v421, v529, &v354);
  std::pair<std::string,int>::operator=(v337);
  std::pair<std::string,int>::~pair<std::string,int>(v421);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v74, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v74);
  std::string::operator=(v529, "CDecoObjMgr::VINE");
  v354 = 0;
  v336 = std::make_pair<std::string &,int &>(v420, v529, &v354);
  std::pair<std::string,int>::operator=(v336);
  std::pair<std::string,int>::~pair<std::string,int>(v420);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v73, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v73);
  std::string::operator=(v529, "CDecoObjMgr::AGAVE");
  v354 = 1;
  v335 = std::make_pair<std::string &,int &>(v419, v529, &v354);
  std::pair<std::string,int>::operator=(v335);
  std::pair<std::string,int>::~pair<std::string,int>(v419);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v72, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v72);
  std::string::operator=(v529, "CDecoObjMgr::TREE");
  v354 = 2;
  v334 = std::make_pair<std::string &,int &>(v418, v529, &v354);
  std::pair<std::string,int>::operator=(v334);
  std::pair<std::string,int>::~pair<std::string,int>(v418);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v71, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v71);
  std::string::operator=(v529, "CDecoObjMgr::GRAIN");
  v354 = 3;
  v333 = std::make_pair<std::string &,int &>(v417, v529, &v354);
  std::pair<std::string,int>::operator=(v333);
  std::pair<std::string,int>::~pair<std::string,int>(v417);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v70, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v70);
  std::string::operator=(v529, "CDecoObjMgr::HIVE");
  v354 = 6;
  v332 = std::make_pair<std::string &,int &>(v463, v529, &v354);
  std::pair<std::string,int>::operator=(v332);
  std::pair<std::string,int>::~pair<std::string,int>(v463);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v69, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v69);
  std::string::operator=(v529, "CDecoObjMgr::MUSHROOM");
  v354 = 4;
  v331 = std::make_pair<std::string &,int &>(v416, v529, &v354);
  std::pair<std::string,int>::operator=(v331);
  std::pair<std::string,int>::~pair<std::string,int>(v416);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v67, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v67);
  std::string::operator=(v529, "CDecoObjMgr::SUNFLOWER");
  v354 = 7;
  v330 = std::make_pair<std::string &,int &>(v415, v529, &v354);
  std::pair<std::string,int>::operator=(v330);
  std::pair<std::string,int>::~pair<std::string,int>(v415);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v66, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v66);
  std::string::operator=(v529, "CARRIER_ROLE");
  v354 = 1;
  v329 = std::make_pair<std::string &,int &>(v414, v529, &v354);
  std::pair<std::string,int>::operator=(v329);
  std::pair<std::string,int>::~pair<std::string,int>(v414);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v65, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v65);
  std::string::operator=(v529, "DIGGER_ROLE");
  v354 = 2;
  v328 = std::make_pair<std::string &,int &>(v413, v529, &v354);
  std::pair<std::string,int>::operator=(v328);
  std::pair<std::string,int>::~pair<std::string,int>(v413);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v64, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v64);
  std::string::operator=(v529, "BUILDER_ROLE");
  v354 = 3;
  v327 = std::make_pair<std::string &,int &>(v412, v529, &v354);
  std::pair<std::string,int>::operator=(v327);
  std::pair<std::string,int>::~pair<std::string,int>(v412);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v63, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v63);
  std::string::operator=(v529, "HOUSE_WORKER_ROLE");
  v354 = 4;
  v326 = std::make_pair<std::string &,int &>(v411, v529, &v354);
  std::pair<std::string,int>::operator=(v326);
  std::pair<std::string,int>::~pair<std::string,int>(v411);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v62, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v62);
  std::string::operator=(v529, "FREE_WORKER_ROLE");
  v354 = 5;
  v325 = std::make_pair<std::string &,int &>(v410, v529, &v354);
  std::pair<std::string,int>::operator=(v325);
  std::pair<std::string,int>::~pair<std::string,int>(v410);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v61, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v61);
  std::string::operator=(v529, "PLANTER_ROLE");
  v354 = 6;
  v324 = std::make_pair<std::string &,int &>(v409, v529, &v354);
  std::pair<std::string,int>::operator=(v324);
  std::pair<std::string,int>::~pair<std::string,int>(v409);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v60, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v60);
  std::string::operator=(v529, "SOLDIER_ROLE");
  v354 = 7;
  v323 = std::make_pair<std::string &,int &>(v408, v529, &v354);
  std::pair<std::string,int>::operator=(v323);
  std::pair<std::string,int>::~pair<std::string,int>(v408);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v59, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v59);
  std::string::operator=(v529, "HUNTER_ROLE");
  v354 = 8;
  v322 = std::make_pair<std::string &,int &>(v407, v529, &v354);
  std::pair<std::string,int>::operator=(v322);
  std::pair<std::string,int>::~pair<std::string,int>(v407);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v58, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v58);
  std::string::operator=(v529, "PRIEST_ROLE");
  v354 = 9;
  v321 = std::make_pair<std::string &,int &>(v406, v529, &v354);
  std::pair<std::string,int>::operator=(v321);
  std::pair<std::string,int>::~pair<std::string,int>(v406);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v57, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v57);
  std::string::operator=(v529, "SABOTEUR_ROLE");
  v354 = 10;
  v320 = std::make_pair<std::string &,int &>(v405, v529, &v354);
  std::pair<std::string,int>::operator=(v320);
  std::pair<std::string,int>::~pair<std::string,int>(v405);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v56, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v56);
  std::string::operator=(v529, "PIONEER_ROLE");
  v354 = 11;
  v319 = std::make_pair<std::string &,int &>(v404, v529, &v354);
  std::pair<std::string,int>::operator=(v319);
  std::pair<std::string,int>::~pair<std::string,int>(v404);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v55, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v55);
  std::string::operator=(v529, "GEOLOGIST_ROLE");
  v354 = 12;
  v318 = std::make_pair<std::string &,int &>(v403, v529, &v354);
  std::pair<std::string,int>::operator=(v318);
  std::pair<std::string,int>::~pair<std::string,int>(v403);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v54, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v54);
  std::string::operator=(v529, "GARDENER_ROLE");
  v354 = 13;
  v317 = std::make_pair<std::string &,int &>(v402, v529, &v354);
  std::pair<std::string,int>::operator=(v317);
  std::pair<std::string,int>::~pair<std::string,int>(v402);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v53, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v53);
  std::string::operator=(v529, "DARK_GARDENER_ROLE");
  v354 = 14;
  v316 = std::make_pair<std::string &,int &>(v401, v529, &v354);
  std::pair<std::string,int>::operator=(v316);
  std::pair<std::string,int>::~pair<std::string,int>(v401);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v52, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v52);
  std::string::operator=(v529, "MUSHROOMFARMER_ROLE");
  v354 = 15;
  v315 = std::make_pair<std::string &,int &>(v400, v529, &v354);
  std::pair<std::string,int>::operator=(v315);
  std::pair<std::string,int>::~pair<std::string,int>(v400);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v51, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v51);
  std::string::operator=(v529, "SHAMAN_ROLE");
  v354 = 16;
  v314 = std::make_pair<std::string &,int &>(v399, v529, &v354);
  std::pair<std::string,int>::operator=(v314);
  std::pair<std::string,int>::~pair<std::string,int>(v399);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v50, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v50);
  std::string::operator=(v529, "SLAVE_ROLE");
  v354 = 17;
  v313 = std::make_pair<std::string &,int &>(v398, v529, &v354);
  std::pair<std::string,int>::operator=(v313);
  std::pair<std::string,int>::~pair<std::string,int>(v398);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v49, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v49);
  std::string::operator=(v529, "FLEE_ROLE");
  v354 = 18;
  v312 = std::make_pair<std::string &,int &>(v397, v529, &v354);
  std::pair<std::string,int>::operator=(v312);
  std::pair<std::string,int>::~pair<std::string,int>(v397);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v48, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v48);
  std::string::operator=(v529, "THIEF_ROLE");
  v354 = 19;
  v311 = std::make_pair<std::string &,int &>(v396, v529, &v354);
  std::pair<std::string,int>::operator=(v311);
  std::pair<std::string,int>::~pair<std::string,int>(v396);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v47, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v47);
  std::string::operator=(v529, "DONKEY_ROLE");
  v354 = 20;
  v310 = std::make_pair<std::string &,int &>(v395, v529, &v354);
  std::pair<std::string,int>::operator=(v310);
  std::pair<std::string,int>::~pair<std::string,int>(v395);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v46, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v46);
  std::string::operator=(v529, "DOOR_ROLE");
  v354 = 21;
  v309 = std::make_pair<std::string &,int &>(v394, v529, &v354);
  std::pair<std::string,int>::operator=(v309);
  std::pair<std::string,int>::~pair<std::string,int>(v394);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v45, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v45);
  std::string::operator=(v529, "TOWER_SOLDIER_ROLE");
  v354 = 22;
  v308 = std::make_pair<std::string &,int &>(v393, v529, &v354);
  std::pair<std::string,int>::operator=(v308);
  std::pair<std::string,int>::~pair<std::string,int>(v393);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v44, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v44);
  std::string::operator=(v529, "SQUAD_LEADER_ROLE");
  v354 = 23;
  v307 = std::make_pair<std::string &,int &>(v392, v529, &v354);
  std::pair<std::string,int>::operator=(v307);
  std::pair<std::string,int>::~pair<std::string,int>(v392);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v43, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v43);
  std::string::operator=(v529, "HJB_ROLE");
  v354 = 24;
  v306 = std::make_pair<std::string &,int &>(v391, v529, &v354);
  std::pair<std::string,int>::operator=(v306);
  std::pair<std::string,int>::~pair<std::string,int>(v391);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v42, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v42);
  std::string::operator=(v529, "CEntityTask::GO_VIRTUAL");
  v354 = 0;
  v305 = std::make_pair<std::string &,int &>(v390, v529, &v354);
  std::pair<std::string,int>::operator=(v305);
  std::pair<std::string,int>::~pair<std::string,int>(v390);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v41, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v41);
  std::string::operator=(v529, "CEntityTask::WORK_VIRTUAL");
  v354 = 1;
  v304 = std::make_pair<std::string &,int &>(v389, v529, &v354);
  std::pair<std::string,int>::operator=(v304);
  std::pair<std::string,int>::~pair<std::string,int>(v389);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v40, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v40);
  std::string::operator=(v529, "CEntityTask::WAIT_VIRTUAL");
  v354 = 2;
  v303 = std::make_pair<std::string &,int &>(v388, v529, &v354);
  std::pair<std::string,int>::operator=(v303);
  std::pair<std::string,int>::~pair<std::string,int>(v388);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v39, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v39);
  std::string::operator=(v529, "CEntityTask::PRODUCE_VIRTUAL");
  v354 = 3;
  v302 = std::make_pair<std::string &,int &>(v387, v529, &v354);
  std::pair<std::string,int>::operator=(v302);
  std::pair<std::string,int>::~pair<std::string,int>(v387);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v38, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v38);
  std::string::operator=(v529, "CEntityTask::PUT_GOOD_VIRTUAL");
  v354 = 4;
  v301 = std::make_pair<std::string &,int &>(v386, v529, &v354);
  std::pair<std::string,int>::operator=(v301);
  std::pair<std::string,int>::~pair<std::string,int>(v386);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v37, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v37);
  std::string::operator=(v529, "CEntityTask::GET_GOOD_VIRTUAL");
  v354 = 5;
  v300 = std::make_pair<std::string &,int &>(v385, v529, &v354);
  std::pair<std::string,int>::operator=(v300);
  std::pair<std::string,int>::~pair<std::string,int>(v385);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v36, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v36);
  std::string::operator=(v529, "CEntityTask::GO");
  v354 = 6;
  v299 = std::make_pair<std::string &,int &>(v384, v529, &v354);
  std::pair<std::string,int>::operator=(v299);
  std::pair<std::string,int>::~pair<std::string,int>(v384);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v35, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v35);
  std::string::operator=(v529, "CEntityTask::GO_TO_POS");
  v354 = 7;
  v298 = std::make_pair<std::string &,int &>(v383, v529, &v354);
  std::pair<std::string,int>::operator=(v298);
  std::pair<std::string,int>::~pair<std::string,int>(v383);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v34, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v34);
  std::string::operator=(v529, "CEntityTask::GO_TO_POS_ROUGHLY");
  v354 = 33;
  v297 = std::make_pair<std::string &,int &>(v382, v529, &v354);
  std::pair<std::string,int>::operator=(v297);
  std::pair<std::string,int>::~pair<std::string,int>(v382);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v33, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v33);
  std::string::operator=(v529, "CEntityTask::GO_TO_DESTINATION");
  v354 = 8;
  v296 = std::make_pair<std::string &,int &>(v381, v529, &v354);
  std::pair<std::string,int>::operator=(v296);
  std::pair<std::string,int>::~pair<std::string,int>(v381);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v32, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v32);
  std::string::operator=(v529, "CEntityTask::GUARD_DESTINATION");
  v354 = 9;
  v295 = std::make_pair<std::string &,int &>(v380, v529, &v354);
  std::pair<std::string,int>::operator=(v295);
  std::pair<std::string,int>::~pair<std::string,int>(v380);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v31, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v31);
  std::string::operator=(v529, "CEntityTask::GO_TO_TARGET");
  v354 = 10;
  v294 = std::make_pair<std::string &,int &>(v379, v529, &v354);
  std::pair<std::string,int>::operator=(v294);
  std::pair<std::string,int>::~pair<std::string,int>(v379);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v30, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v30);
  std::string::operator=(v529, "CEntityTask::ENTER_TARGET");
  v354 = 11;
  v293 = std::make_pair<std::string &,int &>(v378, v529, &v354);
  std::pair<std::string,int>::operator=(v293);
  std::pair<std::string,int>::~pair<std::string,int>(v378);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v29, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v29);
  std::string::operator=(v529, "CEntityTask::ATTACK_TARGET");
  v354 = 12;
  v292 = std::make_pair<std::string &,int &>(v377, v529, &v354);
  std::pair<std::string,int>::operator=(v292);
  std::pair<std::string,int>::~pair<std::string,int>(v377);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v28, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v28);
  std::string::operator=(v529, "CEntityTask::RESOURCE_GATHERING");
  v354 = 13;
  v291 = std::make_pair<std::string &,int &>(v376, v529, &v354);
  std::pair<std::string,int>::operator=(v291);
  std::pair<std::string,int>::~pair<std::string,int>(v376);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v27, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v27);
  std::string::operator=(v529, "CEntityTask::GO_HOME");
  v354 = 14;
  v290 = std::make_pair<std::string &,int &>(v375, v529, &v354);
  std::pair<std::string,int>::operator=(v290);
  std::pair<std::string,int>::~pair<std::string,int>(v375);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v26, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v26);
  std::string::operator=(v529, "CEntityTask::GO_TARGET_OFFSET");
  v354 = 15;
  v289 = std::make_pair<std::string &,int &>(v374, v529, &v354);
  std::pair<std::string,int>::operator=(v289);
  std::pair<std::string,int>::~pair<std::string,int>(v374);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v25, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v25);
  std::string::operator=(v529, "CEntityTask::WORK");
  v354 = 16;
  v288 = std::make_pair<std::string &,int &>(v373, v529, &v354);
  std::pair<std::string,int>::operator=(v288);
  std::pair<std::string,int>::~pair<std::string,int>(v373);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v24, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v24);
  std::string::operator=(v529, "CEntityTask::WAIT");
  v354 = 17;
  v287 = std::make_pair<std::string &,int &>(v372, v529, &v354);
  std::pair<std::string,int>::operator=(v287);
  std::pair<std::string,int>::~pair<std::string,int>(v372);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v23, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v23);
  std::string::operator=(v529, "CEntityTask::GO_TO_SOURCE_PILE");
  v354 = 18;
  v286 = std::make_pair<std::string &,int &>(v371, v529, &v354);
  std::pair<std::string,int>::operator=(v286);
  std::pair<std::string,int>::~pair<std::string,int>(v371);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v22, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v22);
  std::string::operator=(v529, "CEntityTask::GO_TO_DESTINATION_PILE");
  v354 = 19;
  v285 = std::make_pair<std::string &,int &>(v370, v529, &v354);
  std::pair<std::string,int>::operator=(v285);
  std::pair<std::string,int>::~pair<std::string,int>(v370);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v21, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v21);
  std::string::operator=(v529, "CEntityTask::GET_GOOD_CHANGE_JOB");
  v354 = 20;
  v284 = std::make_pair<std::string &,int &>(v369, v529, &v354);
  std::pair<std::string,int>::operator=(v284);
  std::pair<std::string,int>::~pair<std::string,int>(v369);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v20, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v20);
  std::string::operator=(v529, "CEntityTask::PUT_GOOD");
  v354 = 21;
  v283 = std::make_pair<std::string &,int &>(v368, v529, &v354);
  std::pair<std::string,int>::operator=(v283);
  std::pair<std::string,int>::~pair<std::string,int>(v368);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v19, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v19);
  std::string::operator=(v529, "CEntityTask::GET_GOOD");
  v354 = 22;
  v282 = std::make_pair<std::string &,int &>(v367, v529, &v354);
  std::pair<std::string,int>::operator=(v282);
  std::pair<std::string,int>::~pair<std::string,int>(v367);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v18, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v18);
  std::string::operator=(v529, "CEntityTask::LOAD_GOOD");
  v354 = 23;
  v281 = std::make_pair<std::string &,int &>(v366, v529, &v354);
  std::pair<std::string,int>::operator=(v281);
  std::pair<std::string,int>::~pair<std::string,int>(v366);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v17, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v17);
  std::string::operator=(v529, "CEntityTask::CHECKIN");
  v354 = 24;
  v280 = std::make_pair<std::string &,int &>(v365, v529, &v354);
  std::pair<std::string,int>::operator=(v280);
  std::pair<std::string,int>::~pair<std::string,int>(v365);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v16, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v16);
  std::string::operator=(v529, "CEntityTask::PLANT");
  v354 = 25;
  v279 = std::make_pair<std::string &,int &>(v364, v529, &v354);
  std::pair<std::string,int>::operator=(v279);
  std::pair<std::string,int>::~pair<std::string,int>(v364);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v15, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v15);
  std::string::operator=(v529, "CEntityTask::CHANGE_JOB");
  v354 = 26;
  v278 = std::make_pair<std::string &,int &>(v363, v529, &v354);
  std::pair<std::string,int>::operator=(v278);
  std::pair<std::string,int>::~pair<std::string,int>(v363);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v14, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v14);
  std::string::operator=(v529, "CEntityTask::IDLE");
  v354 = 27;
  v277 = std::make_pair<std::string &,int &>(v362, v529, &v354);
  std::pair<std::string,int>::operator=(v277);
  std::pair<std::string,int>::~pair<std::string,int>(v362);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v13, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v13);
  std::string::operator=(v529, "CEntityTask::WORK_ON_ENTITY");
  v354 = 28;
  v276 = std::make_pair<std::string &,int &>(v361, v529, &v354);
  std::pair<std::string,int>::operator=(v276);
  std::pair<std::string,int>::~pair<std::string,int>(v361);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v12, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v12);
  std::string::operator=(v529, "CEntityTask::WORK_ON_ENTITY_VIRTUAL");
  v354 = 29;
  v275 = std::make_pair<std::string &,int &>(v360, v529, &v354);
  std::pair<std::string,int>::operator=(v275);
  std::pair<std::string,int>::~pair<std::string,int>(v360);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v11, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v11);
  std::string::operator=(v529, "CEntityTask::RESOURCE_GATHERING_VIRTUAL");
  v354 = 30;
  v274 = std::make_pair<std::string &,int &>(v359, v529, &v354);
  std::pair<std::string,int>::operator=(v274);
  std::pair<std::string,int>::~pair<std::string,int>(v359);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v10, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v10);
  std::string::operator=(v529, "CEntityTask::SEARCH");
  v354 = 31;
  v273 = std::make_pair<std::string &,int &>(v358, v529, &v354);
  std::pair<std::string,int>::operator=(v273);
  std::pair<std::string,int>::~pair<std::string,int>(v358);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v9, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v9);
  std::string::operator=(v529, "CEntityTask::ATTACK_REACTION");
  v354 = 32;
  v272 = std::make_pair<std::string &,int &>(v357, v529, &v354);
  std::pair<std::string,int>::operator=(v272);
  std::pair<std::string,int>::~pair<std::string,int>(v357);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v8, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v8);
  std::string::operator=(v529, "CEntityTask::HEAL_ENTITY");
  v354 = 34;
  v271 = std::make_pair<std::string &,int &>(v356, v529, &v354);
  std::pair<std::string,int>::operator=(v271);
  std::pair<std::string,int>::~pair<std::string,int>(v356);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v7, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v7);
  std::string::operator=(v529, "CEntityTask::HEAL_ENTITY_VIRTUAL");
  v354 = 35;
  v270 = std::make_pair<std::string &,int &>(v355, v529, &v354);
  std::pair<std::string,int>::operator=(v270);
  std::pair<std::string,int>::~pair<std::string,int>(v355);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v6, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v6);
  std::string::operator=(v529, "CEntityTask::GO_TO_TARGET_ROUGHLY");
  v354 = 37;
  v269 = std::make_pair<std::string &,int &>(v526, v529, &v354);
  std::pair<std::string,int>::operator=(v269);
  std::pair<std::string,int>::~pair<std::string,int>(v526);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v5, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v5);
  std::string::operator=(v529, "CEntityTask::CHANGE_TYPE_AT_BARRACKS");
  v354 = 38;
  v268 = std::make_pair<std::string &,int &>(v525, v529, &v354);
  std::pair<std::string,int>::operator=(v268);
  std::pair<std::string,int>::~pair<std::string,int>(v525);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v4, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v4);
  std::string::operator=(v529, "CEntityTask::CHANGE_JOB_COME_TO_WORK");
  v354 = 39;
  v267 = std::make_pair<std::string &,int &>(v524, v529, &v354);
  std::pair<std::string,int>::operator=(v267);
  std::pair<std::string,int>::~pair<std::string,int>(v524);
  std::map<std::string,int>::insert<std::pair<std::string,int> &,void>(v3, v528);
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>,bool>(v3);
  LOBYTE(v530) = 2;
  std::pair<std::string,int>::~pair<std::string,int>(v528);
  LOBYTE(v530) = 0;
  std::string::~string(v529);
  return v353;
}


// address=[0x1422bf0]
// Decompiled from int __thiscall CDefineTranslator::~CDefineTranslator(CDefineTranslator *this)
 CDefineTranslator::~CDefineTranslator(void) {
  
  CDefineTranslator::Status(this);
  std::_Tree<std::_Tmap_traits<std::string,int,std::less<std::string>,std::allocator<std::pair<std::string const,int>>,0>>::clear();
  return std::map<std::string,int>::~map<std::string,int>(this);
}


// address=[0x1422c40]
// Decompiled from char __thiscall CDefineTranslator::Status(CDefineTranslator *this)
bool  CDefineTranslator::Status(void) {
  
  return 0;
}


// address=[0x14269c0]
// Decompiled from CDefineTranslator *CDefineTranslator::DestroyInstance()
static void __cdecl CDefineTranslator::DestroyInstance(void) {
  
  int Instance; // eax
  CDefineTranslator *result; // eax

  Instance = CDefineTranslator::GetInstance();
  result = (CDefineTranslator *)std::auto_ptr<CDefineTranslator>::release(Instance);
  if ( result )
    return (CDefineTranslator *)CDefineTranslator::`scalar deleting destructor'(result, 1u);
  return result;
}


