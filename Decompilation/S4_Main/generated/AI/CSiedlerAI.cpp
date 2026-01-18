#include "CSiedlerAI.h"

// Definitions for class CSiedlerAI

// address=[0x2f34cd0]
// Decompiled from void __thiscall CSiedlerAI::InitNetAI(CSiedlerAI *this, int a2)
void  CSiedlerAI::InitNetAI(int a2) {
  
  *((_DWORD *)this + 7) = a2;
  IAI_Module::NewSolutionEdge(this, 1, 1);
  IAI_Module::NewSolutionEdge(this, 2, 2);
  IAI_Module::NewSolutionEdge(this, 4, 3);
  IAI_Module::NewSolutionEdge(this, 8, 8);
  IAI_Module::NewSolutionEdge(this, 3, 10);
  IAI_Module::NewSolutionEdge(this, 5, 4);
  IAI_Module::NewSolutionEdge(this, 6, 5);
  IAI_Module::NewSolutionEdge(this, 9, 9);
  IAI_Module::NewSolutionEdge(this, 10, 11);
}


// address=[0x2f34d60]
// Decompiled from CSiedlerAI *__thiscall CSiedlerAI::CSiedlerAI(CSiedlerAI *this, struct CEcoSectorAI *a2, int a3)
 CSiedlerAI::CSiedlerAI(class CEcoSectorAI * a2, int a3) {
  
  int v3; // eax
  CSiedlerAI *v6; // [esp+8h] [ebp-10h]

  IAI_Module::IAI_Module(this);
  *(_DWORD *)this = &CSiedlerAI::_vftable_;
  *((_DWORD *)this + 12) = a2;
  *((_DWORD *)this + 10) = *(_DWORD *)(*((_DWORD *)this + 12) + 24);
  *((_DWORD *)this + 11) = *(_DWORD *)(*((_DWORD *)this + 12) + 4);
  *((_DWORD *)this + 13) = *(_DWORD *)(*((_DWORD *)this + 12) + 16);
  *((_DWORD *)this + 14) = *(_DWORD *)(*((_DWORD *)this + 12) + 20);
  *((_DWORD *)this + 15) = *(_DWORD *)(*((_DWORD *)this + 12) + 12);
  v3 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 10) + 136))(*((_DWORD *)this + 10));
  *((_DWORD *)v6 + 16) = v3;
  *((_DWORD *)v6 + 17) = 0;
  CSiedlerAI::InitNetAI(v6, a3);
  return v6;
}


// address=[0x2f34e50]
// Decompiled from void __thiscall CSiedlerAI::~CSiedlerAI(CSiedlerAI *this)
 CSiedlerAI::~CSiedlerAI(void) {
  
  *(_DWORD *)this = &CSiedlerAI::_vftable_;
  IAI_Module::~IAI_Module(this);
}


// address=[0x2f34e70]
// Decompiled from CParameterSet *__thiscall CSiedlerAI::GenerateAlternatives(CSiedlerAI *this, int a2, struct CParam *a3)
class CParameterSet *  CSiedlerAI::GenerateAlternatives(int a2, class CParam * a3) {
  
  int ProdIdForGoodType; // eax
  int v4; // eax
  int v5; // eax
  struct SBUILDINFODATA *v6; // eax
  int v7; // eax
  struct SBUILDINFODATA *v8; // eax
  int v9; // eax
  struct SBUILDINFODATA *v10; // eax
  unsigned int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  _DWORD *v15; // eax
  int v16; // eax
  struct SBUILDINFODATA *v17; // eax
  int v18; // eax
  struct SBUILDINFODATA *v19; // eax
  int v20; // eax
  struct SBUILDINFODATA *v21; // eax
  int v23; // [esp-18h] [ebp-2550h]
  int v24; // [esp-14h] [ebp-254Ch]
  int v25; // [esp-10h] [ebp-2548h]
  int v26; // [esp-Ch] [ebp-2544h]
  int v27; // [esp-Ch] [ebp-2544h]
  int v28; // [esp-Ch] [ebp-2544h]
  int v29; // [esp-Ch] [ebp-2544h]
  int v30; // [esp-Ch] [ebp-2544h]
  int v31; // [esp-Ch] [ebp-2544h]
  int v32; // [esp-Ch] [ebp-2544h]
  int v33; // [esp-Ch] [ebp-2544h]
  int v34; // [esp-Ch] [ebp-2544h]
  int v35; // [esp-Ch] [ebp-2544h]
  int v36; // [esp-Ch] [ebp-2544h]
  int v37; // [esp-8h] [ebp-2540h]
  int v38; // [esp-8h] [ebp-2540h]
  int v39; // [esp-8h] [ebp-2540h]
  int v40; // [esp-8h] [ebp-2540h]
  int v41; // [esp-8h] [ebp-2540h]
  int v42; // [esp-8h] [ebp-2540h]
  int v43; // [esp-8h] [ebp-2540h]
  int v44; // [esp-8h] [ebp-2540h]
  int v45; // [esp-8h] [ebp-2540h]
  int v46; // [esp-8h] [ebp-2540h]
  int v47; // [esp-8h] [ebp-2540h]
  int v48; // [esp-8h] [ebp-2540h]
  int v49; // [esp-4h] [ebp-253Ch]
  int v50; // [esp-4h] [ebp-253Ch]
  int v51; // [esp-4h] [ebp-253Ch]
  int v52; // [esp-4h] [ebp-253Ch]
  int v53; // [esp-4h] [ebp-253Ch]
  int v54; // [esp-4h] [ebp-253Ch]
  int v55; // [esp-4h] [ebp-253Ch]
  int v56; // [esp-4h] [ebp-253Ch]
  int v57; // [esp-4h] [ebp-253Ch]
  int v58; // [esp-4h] [ebp-253Ch]
  _BYTE v59[16]; // [esp+24h] [ebp-2514h] BYREF
  int v60; // [esp+34h] [ebp-2504h]
  struct CParam *v61; // [esp+38h] [ebp-2500h]
  CFilter *v62; // [esp+3Ch] [ebp-24FCh]
  struct CParam *v63; // [esp+40h] [ebp-24F8h]
  _BYTE v64[16]; // [esp+44h] [ebp-24F4h] BYREF
  struct IFilterEntry *v65; // [esp+54h] [ebp-24E4h]
  CFilter *v66; // [esp+58h] [ebp-24E0h]
  CParameterSet *v67; // [esp+5Ch] [ebp-24DCh]
  int v68; // [esp+60h] [ebp-24D8h]
  CFilter *v69; // [esp+64h] [ebp-24D4h]
  struct CParam *v70; // [esp+68h] [ebp-24D0h]
  struct IFilterEntry *v71; // [esp+6Ch] [ebp-24CCh]
  CParameterSet *v72; // [esp+70h] [ebp-24C8h]
  CFilter *v73; // [esp+74h] [ebp-24C4h]
  int v74; // [esp+78h] [ebp-24C0h]
  CFilter *v75; // [esp+7Ch] [ebp-24BCh]
  CParameterSet *v76; // [esp+80h] [ebp-24B8h]
  struct IFilterEntry *v77; // [esp+84h] [ebp-24B4h]
  CFilter *v78; // [esp+88h] [ebp-24B0h]
  CParameterSet *v79; // [esp+8Ch] [ebp-24ACh]
  struct CParam *v80; // [esp+90h] [ebp-24A8h]
  int v81; // [esp+94h] [ebp-24A4h]
  CFilter *v82; // [esp+98h] [ebp-24A0h]
  struct CParam *v83; // [esp+9Ch] [ebp-249Ch]
  struct IFilterEntry *v84; // [esp+A0h] [ebp-2498h]
  CFilter *v85; // [esp+A4h] [ebp-2494h]
  CParameterSet *v86; // [esp+A8h] [ebp-2490h]
  struct CParam *v87; // [esp+ACh] [ebp-248Ch]
  struct CParam *v88; // [esp+B0h] [ebp-2488h]
  _DWORD v89[3]; // [esp+B4h] [ebp-2484h] BYREF
  int v90; // [esp+C0h] [ebp-2478h]
  CFilter *v91; // [esp+C4h] [ebp-2474h]
  struct CParam *v92; // [esp+C8h] [ebp-2470h]
  struct IFilterEntry *v93; // [esp+CCh] [ebp-246Ch]
  CFilter *v94; // [esp+D0h] [ebp-2468h]
  CParameterSet *v95; // [esp+D4h] [ebp-2464h]
  struct CParam *v96; // [esp+D8h] [ebp-2460h]
  int v97; // [esp+DCh] [ebp-245Ch]
  CFilter *v98; // [esp+E0h] [ebp-2458h]
  struct CParam *v99; // [esp+E4h] [ebp-2454h]
  struct IFilterEntry *v100; // [esp+E8h] [ebp-2450h]
  CFilter *v101; // [esp+ECh] [ebp-244Ch]
  CParameterSet *v102; // [esp+F0h] [ebp-2448h]
  struct CParam *v103; // [esp+F4h] [ebp-2444h]
  int v104; // [esp+F8h] [ebp-2440h]
  CFilterPlaceScoring *v105; // [esp+FCh] [ebp-243Ch]
  CFilter *v106; // [esp+100h] [ebp-2438h]
  CFilter *v107; // [esp+104h] [ebp-2434h]
  CParameterSet *v108; // [esp+108h] [ebp-2430h]
  CParameterSet *v109; // [esp+10Ch] [ebp-242Ch]
  struct CParam *v110; // [esp+110h] [ebp-2428h]
  CParam *v111; // [esp+114h] [ebp-2424h]
  struct IFilterEntry *v112; // [esp+118h] [ebp-2420h]
  CFilterPlaceScoring *v113; // [esp+11Ch] [ebp-241Ch]
  int v114; // [esp+120h] [ebp-2418h]
  int v115; // [esp+124h] [ebp-2414h]
  CParameterSet *v116; // [esp+128h] [ebp-2410h]
  CParameterSet *v117; // [esp+12Ch] [ebp-240Ch]
  CFilter *v118; // [esp+130h] [ebp-2408h]
  CFilter *v119; // [esp+134h] [ebp-2404h]
  struct CParam *v120; // [esp+138h] [ebp-2400h]
  CParam *v121; // [esp+13Ch] [ebp-23FCh]
  int v122; // [esp+140h] [ebp-23F8h]
  struct IFilterEntry *v123; // [esp+144h] [ebp-23F4h]
  CFilterPlaceScoring *v124; // [esp+148h] [ebp-23F0h]
  CFilter *v125; // [esp+14Ch] [ebp-23ECh]
  CFilter *v126; // [esp+150h] [ebp-23E8h]
  CParameterSet *v127; // [esp+154h] [ebp-23E4h]
  CParameterSet *v128; // [esp+158h] [ebp-23E0h]
  struct CParam *v129; // [esp+15Ch] [ebp-23DCh]
  CParam *v130; // [esp+160h] [ebp-23D8h]
  struct CParam *v131; // [esp+164h] [ebp-23D4h]
  CParam *v132; // [esp+168h] [ebp-23D0h]
  struct IFilterEntry *v133; // [esp+16Ch] [ebp-23CCh]
  CFilterPlaceScoring *v134; // [esp+170h] [ebp-23C8h]
  CFilter *v135; // [esp+174h] [ebp-23C4h]
  CFilter *v136; // [esp+178h] [ebp-23C0h]
  int v137; // [esp+17Ch] [ebp-23BCh]
  CParameterSet *v138; // [esp+180h] [ebp-23B8h]
  CParameterSet *v139; // [esp+184h] [ebp-23B4h]
  struct CParam *v140; // [esp+188h] [ebp-23B0h]
  CParam *v141; // [esp+18Ch] [ebp-23ACh]
  struct CParam *v142; // [esp+190h] [ebp-23A8h]
  CParam *v143; // [esp+194h] [ebp-23A4h]
  CParameterSet *v144; // [esp+198h] [ebp-23A0h]
  CParameterSet *v145; // [esp+19Ch] [ebp-239Ch]
  struct CParam *v146; // [esp+1A0h] [ebp-2398h]
  CParam *v147; // [esp+1A4h] [ebp-2394h]
  struct CParam *v148; // [esp+1A8h] [ebp-2390h]
  CParam *v149; // [esp+1ACh] [ebp-238Ch]
  struct IFilterEntry *v150; // [esp+1B0h] [ebp-2388h]
  CFilterPlaceScoring *v151; // [esp+1B4h] [ebp-2384h]
  CFilter *v152; // [esp+1B8h] [ebp-2380h]
  CFilter *v153; // [esp+1BCh] [ebp-237Ch]
  CParameterSet *v154; // [esp+1C0h] [ebp-2378h]
  CParameterSet *v155; // [esp+1C4h] [ebp-2374h]
  struct CParam *v156; // [esp+1C8h] [ebp-2370h]
  CParam *v157; // [esp+1CCh] [ebp-236Ch]
  struct CParam *v158; // [esp+1D0h] [ebp-2368h]
  CParam *v159; // [esp+1D4h] [ebp-2364h]
  struct IFilterEntry *v160; // [esp+1D8h] [ebp-2360h]
  CFilterPlaceScoring *v161; // [esp+1DCh] [ebp-235Ch]
  CFilter *v162; // [esp+1E0h] [ebp-2358h]
  CFilter *v163; // [esp+1E4h] [ebp-2354h]
  CParameterSet *v164; // [esp+1E8h] [ebp-2350h]
  CParameterSet *v165; // [esp+1ECh] [ebp-234Ch]
  struct CParam *v166; // [esp+1F0h] [ebp-2348h]
  CParam *v167; // [esp+1F4h] [ebp-2344h]
  struct CParam *v168; // [esp+1F8h] [ebp-2340h]
  CParam *v169; // [esp+1FCh] [ebp-233Ch]
  struct IFilterEntry *v170; // [esp+200h] [ebp-2338h]
  _BYTE v171[16]; // [esp+204h] [ebp-2334h] BYREF
  int v172; // [esp+214h] [ebp-2324h]
  CFilter *v173; // [esp+218h] [ebp-2320h]
  CFilter *v174; // [esp+21Ch] [ebp-231Ch]
  CFilter *v175; // [esp+220h] [ebp-2318h]
  CFilter *v176; // [esp+224h] [ebp-2314h]
  CFilter *v177; // [esp+228h] [ebp-2310h]
  CFilter *v178; // [esp+22Ch] [ebp-230Ch]
  int v179; // [esp+230h] [ebp-2308h]
  int v180; // [esp+234h] [ebp-2304h]
  struct CExpandationEvent *ExpandationEvent; // [esp+238h] [ebp-2300h]
  int j; // [esp+23Ch] [ebp-22FCh]
  int v183; // [esp+240h] [ebp-22F8h]
  struct IFilterEntry *v184; // [esp+244h] [ebp-22F4h]
  int v185; // [esp+248h] [ebp-22F0h]
  int v186; // [esp+24Ch] [ebp-22ECh]
  _BYTE v187[18]; // [esp+250h] [ebp-22E8h] BYREF
  struct CGrpReserveEntry *GrpResBuilding; // [esp+268h] [ebp-22D0h]
  int v195; // [esp+26Ch] [ebp-22CCh]
  int v196; // [esp+270h] [ebp-22C8h]
  int v197; // [esp+274h] [ebp-22C4h]
  int k; // [esp+278h] [ebp-22C0h]
  int v199; // [esp+27Ch] [ebp-22BCh] BYREF
  int v200; // [esp+280h] [ebp-22B8h] BYREF
  char v201; // [esp+287h] [ebp-22B1h]
  int v202; // [esp+288h] [ebp-22B0h] BYREF
  int v203; // [esp+28Ch] [ebp-22ACh] BYREF
  int ResGrpNr; // [esp+290h] [ebp-22A8h]
  int v205; // [esp+294h] [ebp-22A4h]
  int v206; // [esp+298h] [ebp-22A0h]
  unsigned __int8 v207; // [esp+29Fh] [ebp-2299h]
  CParameterSet *v208; // [esp+2A0h] [ebp-2298h]
  int v209; // [esp+2A4h] [ebp-2294h]
  int GrpNumber; // [esp+2A8h] [ebp-2290h]
  struct CParam *v211; // [esp+2ACh] [ebp-228Ch]
  int ReserveBuilding; // [esp+2B0h] [ebp-2288h]
  CFilter *v213; // [esp+2B4h] [ebp-2284h]
  char v214; // [esp+2BBh] [ebp-227Dh]
  struct IFilterEntry *FilterEntry; // [esp+2BCh] [ebp-227Ch]
  int ProdBuildingByProdIndex; // [esp+2C0h] [ebp-2278h]
  int i; // [esp+2C4h] [ebp-2274h]
  CSiedlerAI *v218; // [esp+2C8h] [ebp-2270h]
  int v219; // [esp+2CCh] [ebp-226Ch] BYREF
  int v220; // [esp+2D0h] [ebp-2268h]
  int ResBuildingType; // [esp+2D4h] [ebp-2264h]
  int v222; // [esp+2D8h] [ebp-2260h]
  _DWORD v223[1520]; // [esp+318h] [ebp-2220h] BYREF
  _DWORD v224[660]; // [esp+1AD8h] [ebp-A60h] BYREF
  int v225; // [esp+2534h] [ebp-4h]

  v218 = this;
  v208 = 0;
  v196 = 0;
  v209 = 0;
  v186 = 0;
  v195 = 0;
  ReserveBuilding = 0;
  v137 = 0;
  v114 = 0;
  ResGrpNr = 0;
  v205 = 0;
  _vec_ctor(v223, 0x4Cu, 0x50u, SBUILDINFODATA::SBUILDINFODATA, SBUILDINFODATA::~SBUILDINFODATA);
  v225 = 0;
  std::vector<SBUILDINFODATA>::vector<SBUILDINFODATA>();
  LOBYTE(v225) = 1;
  std::vector<SMakroEntry>::vector<SMakroEntry>();
  LOBYTE(v225) = 2;
  _vec_ctor(v224, 0x2Cu, 0x3Cu, CReserveEntry::CReserveEntry, CReserveEntry::~CReserveEntry);
  LOBYTE(v225) = 3;
  SBUILDINFODATA::SBUILDINFODATA(&v219);
  LOBYTE(v225) = 4;
  std::vector<SBUILDINFODATA>::vector<SBUILDINFODATA>();
  LOBYTE(v225) = 5;
  std::vector<SBuildId>::vector<SBuildId>();
  LOBYTE(v225) = 6;
  std::vector<int>::vector<int>(v59);
  LOBYTE(v225) = 7;
  v172 = 0;
  v201 = 0;
  v206 = 0;
  v207 = 0;
  v89[0] = 0;
  for ( i = 0; i < 60; ++i )
    memset(&v224[11 * i], 0, 0x2Cu);
  CSchedule::GetBuildingInPlannedStatus(*((CSchedule **)v218 + 11), (struct CReserveEntry *)v224);
  v183 = a2 - 3;
  switch ( a2 )
  {
    case 3:
      ProdIdForGoodType = CProductionTab::GetProdIdForGoodType(
                            *((_DWORD *)v218 + 13),
                            *((_DWORD *)a3 + 3),
                            *((_DWORD *)v218 + 16));
      *((_DWORD *)v218 + 8) = ProdIdForGoodType;
      v195 = 0;
      if ( *((_DWORD *)a3 + 5) )
      {
        *((_DWORD *)v218 + 17) = *((_DWORD *)a3 + 5);
        if ( !CProductionTab::GetProdBuildingByProdIndex(
                *((_DWORD *)v218 + 13),
                *((_DWORD *)v218 + 8),
                1,
                *((_DWORD *)v218 + 16)) )
          v207 = 1;
      }
      else
      {
        *((_DWORD *)v218 + 17) = 0;
      }
      ProdBuildingByProdIndex = CProductionTab::GetProdBuildingByProdIndex(
                                  *((_DWORD *)v218 + 13),
                                  *((_DWORD *)v218 + 8),
                                  0,
                                  *((_DWORD *)v218 + 16));
      v109 = (CParameterSet *)operator new(0x10u);
      LOBYTE(v225) = 8;
      if ( v109 )
        v108 = CParameterSet::CParameterSet(v109);
      else
        v108 = 0;
      v95 = v108;
      LOBYTE(v225) = 7;
      v208 = v108;
      if ( CReserveDatabase::GetReserveBuilding(*((_DWORD *)v218 + 15), 1, ProdBuildingByProdIndex) )
      {
        ReserveBuilding = CReserveDatabase::GetReserveBuilding(*((_DWORD *)v218 + 15), 1, ProdBuildingByProdIndex);
        i = 0;
        while ( ReserveBuilding )
        {
          ReserveBuilding = CReserveDatabase::GetReserveBuilding(*((_DWORD *)v218 + 15), i + 1, ProdBuildingByProdIndex);
          if ( ReserveBuilding )
          {
            v167 = (CParam *)operator new(0x1Cu);
            LOBYTE(v225) = 12;
            if ( v167 )
              v166 = CParam::CParam(v167, v195, ReserveBuilding, 0, 0);
            else
              v166 = 0;
            v103 = v166;
            LOBYTE(v225) = 7;
            v211 = v166;
            CParameterSet::NewParameterSet(v208, v166);
          }
          ++i;
        }
      }
      else
      {
        v206 = CSchedule::GetInvokeEvent(*((_DWORD *)v218 + 11), ProdBuildingByProdIndex);
        if ( v206 && !*(_DWORD *)(v206 + 48) )
        {
          v209 = (*(int (__thiscall **)(_DWORD, int, int, _BYTE *))(**((_DWORD **)v218 + 10) + 32))(
                   *((_DWORD *)v218 + 10),
                   64,
                   ProdBuildingByProdIndex,
                   v187);
          CReserveDatabase::GetResBuildingInGroup(*((CReserveDatabase **)v218 + 15), 0, (struct CReserveEntry *)v224);
          v107 = (CFilter *)operator new(0x18u);
          LOBYTE(v225) = 9;
          if ( v107 )
            v106 = CFilter::CFilter(v107, 5);
          else
            v106 = 0;
          v66 = v106;
          LOBYTE(v225) = 7;
          v213 = v106;
          for ( i = 0; i < v209; ++i )
          {
            v4 = std::vector<SBUILDINFODATA>::operator[](i);
            v186 = (*(int (__thiscall **)(_DWORD, int, int, int, _DWORD *))(**((_DWORD **)v218 + 10) + 264))(
                     *((_DWORD *)v218 + 10),
                     ProdBuildingByProdIndex,
                     16,
                     v4,
                     v223);
            if ( v186 >= 0 )
            {
              std::vector<SBUILDINFODATA>::clear();
              for ( j = 0; j < v186; ++j )
                std::vector<SBUILDINFODATA>::push_back(&v223[19 * j]);
            }
            else
            {
              v186 = CSchedule::PreSelect16Grid(ProdBuildingByProdIndex, v223, v224, v64, v186, *((_DWORD *)v218 + 17));
            }
            for ( k = 0; k < v186; ++k )
            {
              v49 = v207;
              v37 = *((_DWORD *)v218 + 17);
              v5 = std::vector<SBUILDINFODATA>::operator[](k);
              if ( (unsigned __int8)CSchedule::BestAndPossiblePlaceOf8Grid(
                                      *((_DWORD *)v218 + 11),
                                      ProdBuildingByProdIndex,
                                      v5,
                                      v224,
                                      &v200,
                                      &v199,
                                      0,
                                      v37,
                                      v49) )
              {
                v105 = (CFilterPlaceScoring *)operator new(0x38u);
                LOBYTE(v225) = 10;
                if ( v105 )
                {
                  v50 = v200;
                  v38 = v205;
                  v26 = v199;
                  v6 = (struct SBUILDINFODATA *)std::vector<SBUILDINFODATA>::operator[](k);
                  v170 = CFilterPlaceScoring::CFilterPlaceScoring(
                           v105,
                           *((struct CSchedule **)v218 + 11),
                           v6,
                           v26,
                           v38,
                           v50);
                }
                else
                {
                  v170 = 0;
                }
                v65 = v170;
                LOBYTE(v225) = 7;
                CFilter::AddFilterEntry(v213, v170);
              }
            }
            std::vector<SBUILDINFODATA>::clear();
          }
          std::vector<SBUILDINFODATA>::clear();
          for ( i = 0; i < *((_DWORD *)v213 + 2); ++i )
          {
            FilterEntry = CFilter::GetFilterEntry(v213, i);
            v197 = CReserveDatabase::ReserveBuilding(
                     *((_DWORD *)v218 + 15),
                     *((_DWORD *)FilterEntry + 4),
                     *((_DWORD *)FilterEntry + 5),
                     *((_DWORD *)FilterEntry + 6),
                     *((_DWORD *)FilterEntry + 10),
                     *((unsigned __int8 *)FilterEntry + 48),
                     (int)*((double *)FilterEntry + 4),
                     ++v196);
            v169 = (CParam *)operator new(0x1Cu);
            LOBYTE(v225) = 11;
            if ( v169 )
              v168 = CParam::CParam(v169, v195, v197, 0, 0);
            else
              v168 = 0;
            v63 = v168;
            LOBYTE(v225) = 7;
            v211 = v168;
            CParameterSet::NewParameterSet(v208, v168);
          }
          v62 = v213;
          v178 = v213;
          if ( v213 )
            v104 = (**(int (__thiscall ***)(CFilter *, int))v178)(v178, 1);
          else
            v104 = 0;
          if ( !i )
            *((_DWORD *)v218 + 9) = 3;
        }
        else
        {
          *((_DWORD *)v218 + 9) = 1;
        }
      }
      goto CSiedlerAI__GenerateAlternatives___def_3335063;
    case 4:
      v145 = (CParameterSet *)operator new(0x10u);
      LOBYTE(v225) = 23;
      if ( v145 )
        v144 = CParameterSet::CParameterSet(v145);
      else
        v144 = 0;
      v89[1] = v144;
      LOBYTE(v225) = 7;
      v208 = v144;
      ProdBuildingByProdIndex = CProductionDataTab::GoodTypeProducedBy(
                                  *((_DWORD *)v218 + 14),
                                  *((_DWORD *)a3 + 3),
                                  0,
                                  *((_DWORD *)v218 + 16));
      CSchedule::UnmarkBuildings(*((CSchedule **)v218 + 11));
      i = 0;
      v214 = 1;
      CSchedule::GetWeakBuilding(ProdBuildingByProdIndex, v171, 0, v89);
      for ( i = 0; ; ++i )
      {
        v11 = std::vector<SMakroEntry>::size(v171);
        if ( i >= v11 )
          break;
        if ( !CReserveDatabase::GetReserveBuilding(*((_DWORD *)v218 + 15), 1, 0) )
          v201 = 1;
        if ( v201 )
        {
          std::vector<SMakroEntry>::operator[](i);
          std::vector<SMakroEntry>::operator[](i);
          v12 = std::vector<SMakroEntry>::operator[](i);
          CReserveDatabase::UnpackPosition(*((CReserveDatabase **)v218 + 15), *(_DWORD *)(v12 + 12), &v203, &v202);
          v54 = i + 1;
          v25 = *(_DWORD *)(std::vector<SMakroEntry>::operator[](i) + 12);
          v24 = v202;
          v23 = v203;
          v13 = std::vector<SMakroEntry>::operator[](i);
          ReserveBuilding = CReserveDatabase::ReserveBuilding(
                              *((_DWORD *)v218 + 15),
                              *(_DWORD *)(v13 + 8),
                              v23,
                              v24,
                              v25,
                              0,
                              0,
                              v54);
          v143 = (CParam *)operator new(0x1Cu);
          LOBYTE(v225) = 24;
          if ( v143 )
          {
            v55 = *(_DWORD *)std::vector<SMakroEntry>::operator[](i);
            v31 = ReserveBuilding;
            v14 = std::vector<SMakroEntry>::operator[](i);
            v142 = CParam::CParam(v143, *(_DWORD *)(v14 + 8), v31, 0, v55);
          }
          else
          {
            v142 = 0;
          }
          v88 = v142;
          LOBYTE(v225) = 7;
          v211 = v142;
          CParameterSet::NewParameterSet(v208, v142);
          v214 = 0;
        }
        else
        {
          v197 = CReserveDatabase::GetReserveBuilding(*((_DWORD *)v218 + 15), i + 1, 0);
          if ( v197 )
          {
            v141 = (CParam *)operator new(0x1Cu);
            LOBYTE(v225) = 25;
            if ( v141 )
            {
              v15 = (_DWORD *)std::vector<SMakroEntry>::operator[](i);
              v140 = CParam::CParam(v141, ProdBuildingByProdIndex, v197, 0, *v15);
            }
            else
            {
              v140 = 0;
            }
            v87 = v140;
            LOBYTE(v225) = 7;
            v211 = v140;
            CParameterSet::NewParameterSet(v208, v140);
            v214 = 0;
          }
        }
      }
      std::vector<SMakroEntry>::clear();
      if ( v214 )
        *((_DWORD *)v218 + 9) = 3;
      goto CSiedlerAI__GenerateAlternatives___def_3335063;
    case 5:
      v195 = *((_DWORD *)a3 + 3);
      v205 = *((_DWORD *)a3 + 6);
      GrpResBuilding = CReserveDatabase::GetGrpResBuilding(*((CReserveDatabase **)v218 + 15), v205);
      if ( GrpResBuilding )
      {
        ProdBuildingByProdIndex = CProductionTab::GetProdBuildingByProdIndex(
                                    *((_DWORD *)v218 + 13),
                                    *((_DWORD *)v218 + 8),
                                    v195,
                                    *((_DWORD *)v218 + 16));
        if ( *((_DWORD *)v218 + 17)
          && !CProductionTab::GetProdBuildingByProdIndex(
                *((_DWORD *)v218 + 13),
                *((_DWORD *)v218 + 8),
                v195 + 1,
                *((_DWORD *)v218 + 16)) )
        {
          v207 = 1;
        }
        v222 = 16;
        v219 = *((_DWORD *)GrpResBuilding + 4);
        v220 = *((_DWORD *)GrpResBuilding + 5);
        ResBuildingType = *((_DWORD *)GrpResBuilding + 3);
        v165 = (CParameterSet *)operator new(0x10u);
        LOBYTE(v225) = 13;
        if ( v165 )
          v164 = CParameterSet::CParameterSet(v165);
        else
          v164 = 0;
        v102 = v164;
        LOBYTE(v225) = 7;
        v208 = v164;
        ResGrpNr = *((_DWORD *)GrpResBuilding + 11);
        GrpNumber = CReserveDatabase::CreateGrpNumber(*((CReserveDatabase **)v218 + 15), ResGrpNr, 1);
        if ( CReserveDatabase::GetReserveBuilding(*((_DWORD *)v218 + 15), GrpNumber, ProdBuildingByProdIndex) )
        {
          ReserveBuilding = CReserveDatabase::GetReserveBuilding(
                              *((_DWORD *)v218 + 15),
                              GrpNumber,
                              ProdBuildingByProdIndex);
          i = 0;
          while ( ReserveBuilding )
          {
            v157 = (CParam *)operator new(0x1Cu);
            LOBYTE(v225) = 17;
            if ( v157 )
              v156 = CParam::CParam(v157, v195, ReserveBuilding, 0, v205);
            else
              v156 = 0;
            v96 = v156;
            LOBYTE(v225) = 7;
            v211 = v156;
            CParameterSet::NewParameterSet(v208, v156);
            GrpNumber = CReserveDatabase::CreateGrpNumber(*((CReserveDatabase **)v218 + 15), ResGrpNr, i + 2);
            ReserveBuilding = CReserveDatabase::GetReserveBuilding(
                                *((_DWORD *)v218 + 15),
                                GrpNumber,
                                ProdBuildingByProdIndex);
            ++i;
          }
        }
        else
        {
          v206 = CSchedule::GetInvokeEvent(*((_DWORD *)v218 + 11), ProdBuildingByProdIndex);
          if ( v206 && !*(_DWORD *)(v206 + 48) )
          {
            v185 = CProductionDataTab::GetMaxDistance(
                     *((_DWORD *)v218 + 14),
                     ProdBuildingByProdIndex,
                     *((_DWORD *)v218 + 16))
                 / 16
                 + 1;
            v209 = (*(int (__thiscall **)(_DWORD, int, int *, _BYTE *, int))(**((_DWORD **)v218 + 10) + 28))(
                     *((_DWORD *)v218 + 10),
                     ProdBuildingByProdIndex,
                     &v219,
                     v187,
                     v185);
            if ( v209 < 2 )
              v209 = (*(int (__thiscall **)(_DWORD, int, int *, _BYTE *, int))(**((_DWORD **)v218 + 10) + 28))(
                       *((_DWORD *)v218 + 10),
                       ProdBuildingByProdIndex,
                       &v219,
                       v187,
                       3);
            v163 = (CFilter *)operator new(0x18u);
            LOBYTE(v225) = 14;
            if ( v163 )
              v162 = CFilter::CFilter(v163, 5);
            else
              v162 = 0;
            v101 = v162;
            LOBYTE(v225) = 7;
            v213 = v162;
            CReserveDatabase::GetResBuildingInGroup(
              *((CReserveDatabase **)v218 + 15),
              ResGrpNr,
              (struct CReserveEntry *)v224);
            for ( i = 0; i < v209; ++i )
            {
              v51 = v207;
              v39 = *((_DWORD *)v218 + 17);
              v27 = *((_DWORD *)GrpResBuilding + 8);
              v7 = std::vector<SBUILDINFODATA>::operator[](i);
              if ( (unsigned __int8)CSchedule::BestAndPossiblePlaceOf8Grid(
                                      *((_DWORD *)v218 + 11),
                                      ProdBuildingByProdIndex,
                                      v7,
                                      v224,
                                      &v200,
                                      &v199,
                                      v27,
                                      v39,
                                      v51) )
              {
                v161 = (CFilterPlaceScoring *)operator new(0x38u);
                LOBYTE(v225) = 15;
                if ( v161 )
                {
                  v52 = v200;
                  v40 = v205;
                  v28 = v199;
                  v8 = (struct SBUILDINFODATA *)std::vector<SBUILDINFODATA>::operator[](i);
                  v160 = CFilterPlaceScoring::CFilterPlaceScoring(
                           v161,
                           *((struct CSchedule **)v218 + 11),
                           v8,
                           v28,
                           v40,
                           v52);
                }
                else
                {
                  v160 = 0;
                }
                v100 = v160;
                LOBYTE(v225) = 7;
                CFilter::AddFilterEntry(v213, v160);
              }
            }
            std::vector<SBUILDINFODATA>::clear();
            for ( i = 0; i < *((_DWORD *)v213 + 2); ++i )
            {
              GrpNumber = CReserveDatabase::CreateGrpNumber(*((CReserveDatabase **)v218 + 15), ResGrpNr, i + 1);
              FilterEntry = CFilter::GetFilterEntry(v213, i);
              ++v196;
              v197 = CReserveDatabase::ReserveBuilding(
                       *((_DWORD *)v218 + 15),
                       *((_DWORD *)FilterEntry + 4),
                       *((_DWORD *)FilterEntry + 5),
                       *((_DWORD *)FilterEntry + 6),
                       *((_DWORD *)FilterEntry + 10),
                       *((unsigned __int8 *)FilterEntry + 48),
                       (int)*((double *)FilterEntry + 4),
                       GrpNumber);
              v159 = (CParam *)operator new(0x1Cu);
              LOBYTE(v225) = 16;
              if ( v159 )
                v158 = CParam::CParam(v159, v195, v197, 0, v205);
              else
                v158 = 0;
              v99 = v158;
              LOBYTE(v225) = 7;
              v211 = v158;
              CParameterSet::NewParameterSet(v208, v158);
            }
            if ( !i )
              *((_DWORD *)v218 + 9) = 3;
            v98 = v213;
            v177 = v213;
            if ( v213 )
              v97 = (**(int (__thiscall ***)(CFilter *, int))v177)(v177, 1);
            else
              v97 = 0;
          }
          else
          {
            *((_DWORD *)v218 + 9) = 3;
          }
        }
      }
      else
      {
        *((_DWORD *)v218 + 9) = 3;
      }
      goto CSiedlerAI__GenerateAlternatives___def_3335063;
    case 6:
      ProdBuildingByProdIndex = *((_DWORD *)a3 + 3);
      v205 = *((_DWORD *)a3 + 6);
      CReserveDatabase::GetResPosition(*((CReserveDatabase **)v218 + 15), v205, &v203, &v202);
      GrpResBuilding = CReserveDatabase::GetGrpResBuilding(*((CReserveDatabase **)v218 + 15), v205);
      v222 = 16;
      v219 = v203;
      v220 = v202;
      ResBuildingType = CReserveDatabase::GetResBuildingType(*((_DWORD *)v218 + 15), v205);
      v155 = (CParameterSet *)operator new(0x10u);
      LOBYTE(v225) = 18;
      if ( v155 )
        v154 = CParameterSet::CParameterSet(v155);
      else
        v154 = 0;
      v76 = v154;
      LOBYTE(v225) = 7;
      v208 = v154;
      ResGrpNr = CReserveDatabase::GetResGrpNr(*((CReserveDatabase **)v218 + 15), v205);
      GrpNumber = CReserveDatabase::CreateGrpNumber(*((CReserveDatabase **)v218 + 15), ResGrpNr, 1);
      if ( CReserveDatabase::GetReserveBuilding(*((_DWORD *)v218 + 15), GrpNumber, ProdBuildingByProdIndex) )
      {
        GrpNumber = CReserveDatabase::CreateGrpNumber(*((CReserveDatabase **)v218 + 15), ResGrpNr, 1);
        ReserveBuilding = CReserveDatabase::GetReserveBuilding(
                            *((_DWORD *)v218 + 15),
                            GrpNumber,
                            ProdBuildingByProdIndex);
        i = 0;
        while ( ReserveBuilding )
        {
          v147 = (CParam *)operator new(0x1Cu);
          LOBYTE(v225) = 22;
          if ( v147 )
            v146 = CParam::CParam(v147, ProdBuildingByProdIndex, ReserveBuilding, 0, v205);
          else
            v146 = 0;
          v89[2] = v146;
          LOBYTE(v225) = 7;
          v211 = v146;
          CParameterSet::NewParameterSet(v208, v146);
          GrpNumber = CReserveDatabase::CreateGrpNumber(*((CReserveDatabase **)v218 + 15), ResGrpNr, i + 2);
          ReserveBuilding = CReserveDatabase::GetReserveBuilding(
                              *((_DWORD *)v218 + 15),
                              GrpNumber,
                              ProdBuildingByProdIndex);
          ++i;
        }
      }
      else
      {
        CReserveDatabase::GetResBuildingInGroup(
          *((CReserveDatabase **)v218 + 15),
          ResGrpNr,
          (struct CReserveEntry *)v224);
        v206 = CSchedule::GetInvokeEvent(*((_DWORD *)v218 + 11), ProdBuildingByProdIndex);
        if ( v206 && !*(_DWORD *)(v206 + 48) )
        {
          v185 = CProductionDataTab::GetMaxDistance(
                   *((_DWORD *)v218 + 14),
                   ProdBuildingByProdIndex,
                   *((_DWORD *)v218 + 16))
               / 16
               + 1;
          v209 = (*(int (__thiscall **)(_DWORD, int, int *, _BYTE *, int))(**((_DWORD **)v218 + 10) + 28))(
                   *((_DWORD *)v218 + 10),
                   ProdBuildingByProdIndex,
                   &v219,
                   v187,
                   v185);
          if ( !v209 )
            v209 = (*(int (__thiscall **)(_DWORD, int, int *, _BYTE *, int))(**((_DWORD **)v218 + 10) + 28))(
                     *((_DWORD *)v218 + 10),
                     ProdBuildingByProdIndex,
                     &v219,
                     v187,
                     3);
          v153 = (CFilter *)operator new(0x18u);
          LOBYTE(v225) = 19;
          if ( v153 )
            v152 = CFilter::CFilter(v153, 5);
          else
            v152 = 0;
          v94 = v152;
          LOBYTE(v225) = 7;
          v213 = v152;
          for ( i = 0; i < v209; ++i )
          {
            v41 = *((_DWORD *)v218 + 17);
            v29 = *((_DWORD *)GrpResBuilding + 8);
            v9 = std::vector<SBUILDINFODATA>::operator[](i);
            if ( (unsigned __int8)CSchedule::BestAndPossiblePlaceOf8Grid(
                                    *((_DWORD *)v218 + 11),
                                    ProdBuildingByProdIndex,
                                    v9,
                                    v224,
                                    &v200,
                                    &v199,
                                    v29,
                                    v41,
                                    1) )
            {
              v151 = (CFilterPlaceScoring *)operator new(0x38u);
              LOBYTE(v225) = 20;
              if ( v151 )
              {
                v53 = v200;
                v42 = v205;
                v30 = v199;
                v10 = (struct SBUILDINFODATA *)std::vector<SBUILDINFODATA>::operator[](i);
                v150 = CFilterPlaceScoring::CFilterPlaceScoring(
                         v151,
                         *((struct CSchedule **)v218 + 11),
                         v10,
                         v30,
                         v42,
                         v53);
              }
              else
              {
                v150 = 0;
              }
              v93 = v150;
              LOBYTE(v225) = 7;
              CFilter::AddFilterEntry(v213, v150);
            }
            std::vector<SBUILDINFODATA>::clear();
          }
          for ( i = 0; i < *((_DWORD *)v213 + 2); ++i )
          {
            GrpNumber = CReserveDatabase::CreateGrpNumber(*((CReserveDatabase **)v218 + 15), ResGrpNr, i + 1);
            FilterEntry = CFilter::GetFilterEntry(v213, i);
            ++v196;
            v197 = CReserveDatabase::ReserveBuilding(
                     *((_DWORD *)v218 + 15),
                     *((_DWORD *)FilterEntry + 4),
                     *((_DWORD *)FilterEntry + 5),
                     *((_DWORD *)FilterEntry + 6),
                     *((_DWORD *)FilterEntry + 10),
                     *((unsigned __int8 *)FilterEntry + 48),
                     (int)*((double *)FilterEntry + 4),
                     GrpNumber);
            v149 = (CParam *)operator new(0x1Cu);
            LOBYTE(v225) = 21;
            if ( v149 )
              v148 = CParam::CParam(v149, ProdBuildingByProdIndex, v197, 0, v205);
            else
              v148 = 0;
            v92 = v148;
            LOBYTE(v225) = 7;
            v211 = v148;
            CParameterSet::NewParameterSet(v208, v148);
          }
          if ( !i )
            *((_DWORD *)v218 + 9) = 3;
          v91 = v213;
          v176 = v213;
          if ( v213 )
            v90 = (**(int (__thiscall ***)(CFilter *, int))v176)(v176, 1);
          else
            v90 = 0;
        }
        else
        {
          *((_DWORD *)v218 + 9) = 1;
        }
      }
      goto CSiedlerAI__GenerateAlternatives___def_3335063;
    case 8:
      ProdBuildingByProdIndex = *((_DWORD *)a3 + 3);
      ReserveBuilding = *((_DWORD *)a3 + 4);
      CReserveDatabase::GetResPosition(*((CReserveDatabase **)v218 + 15), ReserveBuilding, &v203, &v202);
      ResGrpNr = CReserveDatabase::GetResGrpNr(*((CReserveDatabase **)v218 + 15), ReserveBuilding);
      v60 = *((_DWORD *)a3 + 6);
      v139 = (CParameterSet *)operator new(0x10u);
      LOBYTE(v225) = 26;
      if ( v139 )
        v138 = CParameterSet::CParameterSet(v139);
      else
        v138 = 0;
      v86 = v138;
      LOBYTE(v225) = 7;
      v208 = v138;
      v137 = CReserveDatabase::CreateGrpNumber(*((CReserveDatabase **)v218 + 15), ResGrpNr, 1);
      v214 = 1;
      if ( CReserveDatabase::GetReserveBuilding(*((_DWORD *)v218 + 15), v137, 0) )
      {
        GrpNumber = CReserveDatabase::CreateGrpNumber(*((CReserveDatabase **)v218 + 15), ResGrpNr, 1);
        ReserveBuilding = CReserveDatabase::GetReserveBuilding(*((_DWORD *)v218 + 15), GrpNumber, 0);
        i = 0;
        while ( ReserveBuilding )
        {
          v130 = (CParam *)operator new(0x1Cu);
          LOBYTE(v225) = 30;
          if ( v130 )
            v129 = CParam::CParam(v130, ProdBuildingByProdIndex, ReserveBuilding, 0, v205);
          else
            v129 = 0;
          v80 = v129;
          LOBYTE(v225) = 7;
          v211 = v129;
          CParameterSet::NewParameterSet(v208, v129);
          v214 = 0;
          GrpNumber = CReserveDatabase::CreateGrpNumber(*((CReserveDatabase **)v218 + 15), ResGrpNr, i + 2);
          ReserveBuilding = CReserveDatabase::GetReserveBuilding(*((_DWORD *)v218 + 15), GrpNumber, 0);
          ++i;
        }
      }
      else
      {
        v222 = 16;
        v219 = v203 / 16;
        v220 = v202 / 16;
        ResBuildingType = 0;
        v206 = CSchedule::GetInvokeEvent(*((_DWORD *)v218 + 11), ProdBuildingByProdIndex);
        if ( !v206 || *(_DWORD *)(v206 + 48) )
        {
          *((_DWORD *)v218 + 9) = 1;
          goto CSiedlerAI__GenerateAlternatives___def_3335063;
        }
        v185 = CProductionDataTab::GetMaxDistance(
                 *((_DWORD *)v218 + 14),
                 ProdBuildingByProdIndex,
                 *((_DWORD *)v218 + 16))
             / 16
             + 1;
        std::vector<SBUILDINFODATA>::clear();
        v209 = (*(int (__thiscall **)(_DWORD, int, int *, _BYTE *, int))(**((_DWORD **)v218 + 10) + 28))(
                 *((_DWORD *)v218 + 10),
                 ProdBuildingByProdIndex,
                 &v219,
                 v187,
                 v185);
        if ( !v209 )
          v209 = (*(int (__thiscall **)(_DWORD, int, int *, _BYTE *, int))(**((_DWORD **)v218 + 10) + 28))(
                   *((_DWORD *)v218 + 10),
                   ProdBuildingByProdIndex,
                   &v219,
                   v187,
                   2);
        v136 = (CFilter *)operator new(0x18u);
        LOBYTE(v225) = 27;
        if ( v136 )
          v135 = CFilter::CFilter(v136, 5);
        else
          v135 = 0;
        v85 = v135;
        LOBYTE(v225) = 7;
        v213 = v135;
        for ( i = 0; i < v209; ++i )
        {
          v43 = *((_DWORD *)v218 + 17);
          v32 = CReserveDatabase::PackPosition(*((CReserveDatabase **)v218 + 15), v203, v202);
          v16 = std::vector<SBUILDINFODATA>::operator[](i);
          if ( (unsigned __int8)CSchedule::BestAndPossiblePlaceOf8Grid(
                                  *((_DWORD *)v218 + 11),
                                  ProdBuildingByProdIndex,
                                  v16,
                                  v224,
                                  &v200,
                                  &v199,
                                  v32,
                                  v43,
                                  1) )
          {
            v134 = (CFilterPlaceScoring *)operator new(0x38u);
            LOBYTE(v225) = 28;
            if ( v134 )
            {
              v56 = v200;
              v44 = v205;
              v33 = v199;
              v17 = (struct SBUILDINFODATA *)std::vector<SBUILDINFODATA>::operator[](i);
              v133 = CFilterPlaceScoring::CFilterPlaceScoring(
                       v134,
                       *((struct CSchedule **)v218 + 11),
                       v17,
                       v33,
                       v44,
                       v56);
            }
            else
            {
              v133 = 0;
            }
            v84 = v133;
            LOBYTE(v225) = 7;
            CFilter::AddFilterEntry(v213, v133);
          }
        }
        std::vector<SBUILDINFODATA>::clear();
        for ( i = 0; i < *((_DWORD *)v213 + 2); ++i )
        {
          GrpNumber = CReserveDatabase::CreateGrpNumber(*((CReserveDatabase **)v218 + 15), ResGrpNr, i + 1);
          FilterEntry = CFilter::GetFilterEntry(v213, i);
          ++v196;
          v197 = CReserveDatabase::ReserveBuilding(
                   *((_DWORD *)v218 + 15),
                   *((_DWORD *)FilterEntry + 4),
                   *((_DWORD *)FilterEntry + 5),
                   *((_DWORD *)FilterEntry + 6),
                   *((_DWORD *)FilterEntry + 10),
                   *((unsigned __int8 *)FilterEntry + 48),
                   (int)*((double *)FilterEntry + 4),
                   GrpNumber);
          v132 = (CParam *)operator new(0x1Cu);
          LOBYTE(v225) = 29;
          if ( v132 )
            v131 = CParam::CParam(v132, *((_DWORD *)FilterEntry + 4), v197, 0, v205);
          else
            v131 = 0;
          v83 = v131;
          LOBYTE(v225) = 7;
          v211 = v131;
          CParameterSet::NewParameterSet(v208, v131);
          v214 = 0;
        }
        v82 = v213;
        v175 = v213;
        if ( v213 )
          v81 = (**(int (__thiscall ***)(CFilter *, int))v175)(v175, 1);
        else
          v81 = 0;
      }
      if ( v214 )
        *((_DWORD *)v218 + 9) = 3;
      goto CSiedlerAI__GenerateAlternatives___def_3335063;
    case 9:
      ProdBuildingByProdIndex = *((_DWORD *)a3 + 3);
      v122 = *((_DWORD *)a3 + 4);
      CReserveDatabase::UnpackPosition(*((CReserveDatabase **)v218 + 15), v122, &v203, &v202);
      v222 = 16;
      v219 = v203 / 16;
      v220 = v202 / 16;
      ResBuildingType = 0;
      v128 = (CParameterSet *)operator new(0x10u);
      LOBYTE(v225) = 31;
      if ( v128 )
        v127 = CParameterSet::CParameterSet(v128);
      else
        v127 = 0;
      v79 = v127;
      LOBYTE(v225) = 7;
      v208 = v127;
      v206 = CSchedule::GetInvokeEvent(*((_DWORD *)v218 + 11), ProdBuildingByProdIndex);
      if ( v206 && !*(_DWORD *)(v206 + 48) )
      {
        v209 = (*(int (__thiscall **)(_DWORD, int, int *, _BYTE *, int))(**((_DWORD **)v218 + 10) + 28))(
                 *((_DWORD *)v218 + 10),
                 ProdBuildingByProdIndex,
                 &v219,
                 v187,
                 4);
        if ( v209 < 5 )
          v209 = (*(int (__thiscall **)(_DWORD, int, int *, _BYTE *, int))(**((_DWORD **)v218 + 10) + 28))(
                   *((_DWORD *)v218 + 10),
                   ProdBuildingByProdIndex,
                   &v219,
                   v187,
                   8);
        v126 = (CFilter *)operator new(0x18u);
        LOBYTE(v225) = 32;
        if ( v126 )
          v125 = CFilter::CFilter(v126, 5);
        else
          v125 = 0;
        v78 = v125;
        LOBYTE(v225) = 7;
        v213 = v125;
        for ( i = 0; i < v209; ++i )
        {
          v45 = *((_DWORD *)v218 + 17);
          v34 = CReserveDatabase::PackPosition(*((CReserveDatabase **)v218 + 15), v203, v202);
          v18 = std::vector<SBUILDINFODATA>::operator[](i);
          if ( (unsigned __int8)CSchedule::BestAndPossiblePlaceOf8Grid(
                                  *((_DWORD *)v218 + 11),
                                  ProdBuildingByProdIndex,
                                  v18,
                                  v224,
                                  &v200,
                                  &v199,
                                  v34,
                                  v45,
                                  1) )
          {
            v124 = (CFilterPlaceScoring *)operator new(0x38u);
            LOBYTE(v225) = 33;
            if ( v124 )
            {
              v57 = v200;
              v46 = v205;
              v35 = v199;
              v19 = (struct SBUILDINFODATA *)std::vector<SBUILDINFODATA>::operator[](i);
              v123 = CFilterPlaceScoring::CFilterPlaceScoring(
                       v124,
                       *((struct CSchedule **)v218 + 11),
                       v19,
                       v35,
                       v46,
                       v57);
            }
            else
            {
              v123 = 0;
            }
            v77 = v123;
            LOBYTE(v225) = 7;
            CFilter::AddFilterEntry(v213, v123);
          }
        }
        std::vector<SBUILDINFODATA>::clear();
        for ( i = 0; i < *((_DWORD *)v213 + 2); ++i )
        {
          FilterEntry = CFilter::GetFilterEntry(v213, i);
          v121 = (CParam *)operator new(0x1Cu);
          LOBYTE(v225) = 34;
          if ( v121 )
            v120 = CParam::CParam(v121, ProdBuildingByProdIndex, *((_DWORD *)FilterEntry + 10), 0, v122);
          else
            v120 = 0;
          v61 = v120;
          LOBYTE(v225) = 7;
          v211 = v120;
          CParameterSet::NewParameterSet(v208, v120);
        }
        if ( !i )
          *((_DWORD *)v218 + 9) = 3;
        v75 = v213;
        v174 = v213;
        if ( v213 )
          v74 = (**(int (__thiscall ***)(CFilter *, int))v174)(v174, 1);
        else
          v74 = 0;
      }
      else
      {
        *((_DWORD *)v218 + 9) = 1;
      }
      goto CSiedlerAI__GenerateAlternatives___def_3335063;
    case 10:
      v179 = *((_DWORD *)a3 + 3);
      ExpandationEvent = CSchedule::GetExpandationEvent(*((CSchedule **)v218 + 11), v179);
      if ( !ExpandationEvent )
      {
        *((_DWORD *)v218 + 9) = 3;
        goto CSiedlerAI__GenerateAlternatives___def_3335063;
      }
      v119 = (CFilter *)operator new(0x18u);
      LOBYTE(v225) = 35;
      if ( v119 )
        v118 = CFilter::CFilter(v119, 5);
      else
        v118 = 0;
      v73 = v118;
      LOBYTE(v225) = 7;
      v213 = v118;
      if ( v179 == -5 )
      {
        v172 = CSchedule::GetNearExpandationPositionOutside(-5, 0, v59);
      }
      else
      {
        if ( !*((_DWORD *)ExpandationEvent + 11) )
        {
          *((_DWORD *)v218 + 9) = 3;
          goto CSiedlerAI__GenerateAlternatives___def_3335063;
        }
        v172 = *(_DWORD *)(*((_DWORD *)ExpandationEvent + 11) + 8);
      }
      i = 0;
      break;
    default:
      goto CSiedlerAI__GenerateAlternatives___def_3335063;
  }
  while ( i < v172 )
  {
    if ( v179 == -5 )
    {
      v180 = *(_DWORD *)std::vector<int>::operator[](i);
      CReserveDatabase::UnpackPosition(*((CReserveDatabase **)v218 + 15), v180, &v203, &v202);
      v115 = CReserveDatabase::PackPosition(*((CReserveDatabase **)v218 + 15), 16 * v203 + 8, 16 * v202 + 8);
    }
    else
    {
      v184 = CFilter::GetFilterEntry(*((CFilter **)ExpandationEvent + 11), i);
      v180 = *((_DWORD *)v184 + 6);
      if ( !v180 )
        goto LABEL_239;
      v114 = CReserveDatabase::PackPosition(
               *((CReserveDatabase **)v218 + 15),
               16 * *((_DWORD *)v184 + 3) + 8,
               16 * *((_DWORD *)v184 + 4) + 8);
      v115 = CReserveDatabase::PackPosition(
               *((CReserveDatabase **)v218 + 15),
               16 * *((_DWORD *)v184 + 3) + 8,
               16 * *((_DWORD *)v184 + 4) + 8);
      CReserveDatabase::UnpackPosition(*((CReserveDatabase **)v218 + 15), v180, &v203, &v202);
    }
    v222 = 16;
    v219 = v203;
    v220 = v202;
    ResBuildingType = 0;
    v117 = (CParameterSet *)operator new(0x10u);
    LOBYTE(v225) = 36;
    if ( v117 )
      v116 = CParameterSet::CParameterSet(v117);
    else
      v116 = 0;
    v72 = v116;
    LOBYTE(v225) = 7;
    v208 = v116;
    v206 = CSchedule::GetInvokeEvent(*((_DWORD *)v218 + 11), 46);
    if ( !v206 || *(_DWORD *)(v206 + 48) )
    {
      *((_DWORD *)v218 + 9) = 1;
      break;
    }
    std::vector<SBUILDINFODATA>::clear();
    v209 = (*(int (__thiscall **)(_DWORD, int, int *, _BYTE *, int))(**((_DWORD **)v218 + 10) + 28))(
             *((_DWORD *)v218 + 10),
             46,
             &v219,
             v187,
             1);
    for ( k = 0; k < v209; ++k )
    {
      v47 = v115;
      v20 = std::vector<SBUILDINFODATA>::operator[](k);
      if ( (unsigned __int8)CSchedule::BestAndPossiblePlaceOf8Grid(
                              *((_DWORD *)v218 + 11),
                              46,
                              v20,
                              v224,
                              &v200,
                              &v199,
                              0,
                              v47,
                              1) )
      {
        v113 = (CFilterPlaceScoring *)operator new(0x38u);
        LOBYTE(v225) = 37;
        if ( v113 )
        {
          v58 = v200;
          v48 = v114;
          v36 = v199;
          v21 = (struct SBUILDINFODATA *)std::vector<SBUILDINFODATA>::operator[](k);
          v112 = CFilterPlaceScoring::CFilterPlaceScoring(v113, *((struct CSchedule **)v218 + 11), v21, v36, v48, v58);
        }
        else
        {
          v112 = 0;
        }
        v71 = v112;
        LOBYTE(v225) = 7;
        CFilter::AddFilterEntry(v213, v112);
      }
    }
    std::vector<SBUILDINFODATA>::clear();
LABEL_239:
    ++i;
  }
  for ( i = 0; i < *((_DWORD *)v213 + 2); ++i )
  {
    FilterEntry = CFilter::GetFilterEntry(v213, i);
    v111 = (CParam *)operator new(0x1Cu);
    LOBYTE(v225) = 38;
    if ( v111 )
      v110 = CParam::CParam(
               v111,
               46,
               *((_DWORD *)FilterEntry + 10),
               *((char *)FilterEntry + 48),
               *((_DWORD *)FilterEntry + 11));
    else
      v110 = 0;
    v70 = v110;
    LOBYTE(v225) = 7;
    v211 = v110;
    CParameterSet::NewParameterSet(v208, v110);
  }
  if ( !i )
    *((_DWORD *)v218 + 9) = 3;
  v69 = v213;
  v173 = v213;
  if ( v213 )
    v68 = (**(int (__thiscall ***)(CFilter *, int))v173)(v173, 1);
  else
    v68 = 0;
CSiedlerAI__GenerateAlternatives___def_3335063:
  v67 = v208;
  LOBYTE(v225) = 6;
  std::vector<int>::~vector<int>();
  LOBYTE(v225) = 5;
  std::vector<SBuildId>::~vector<SBuildId>();
  LOBYTE(v225) = 4;
  std::vector<SBUILDINFODATA>::~vector<SBUILDINFODATA>();
  LOBYTE(v225) = 3;
  SBUILDINFODATA::~SBUILDINFODATA(&v219);
  LOBYTE(v225) = 2;
  `eh vector destructor iterator'(v224, 0x2Cu, 0x3Cu, CReserveEntry::~CReserveEntry);
  LOBYTE(v225) = 1;
  std::vector<SMakroEntry>::~vector<SMakroEntry>();
  LOBYTE(v225) = 0;
  std::vector<SBUILDINFODATA>::~vector<SBUILDINFODATA>();
  v225 = -1;
  `eh vector destructor iterator'(v223, 0x4Cu, 0x50u, SBUILDINFODATA::~SBUILDINFODATA);
  return v67;
}


// address=[0x2f37a70]
// Decompiled from CConditionSet *__thiscall CSiedlerAI::Condition(CSiedlerAI *this, int a2, struct CParam *a3)
class CConditionSet *  CSiedlerAI::Condition(int a2, class CParam * a3) {
  
  int v4; // [esp+8h] [ebp-18Ch]
  int v5; // [esp+14h] [ebp-180h]
  struct CParam *v6; // [esp+78h] [ebp-11Ch]
  CParam *v7; // [esp+7Ch] [ebp-118h]
  struct CParam *v8; // [esp+80h] [ebp-114h]
  CParam *v9; // [esp+84h] [ebp-110h]
  struct CParam *v10; // [esp+88h] [ebp-10Ch]
  CParam *v11; // [esp+8Ch] [ebp-108h]
  struct CParam *v12; // [esp+90h] [ebp-104h]
  CParam *v13; // [esp+94h] [ebp-100h]
  struct CParam *v14; // [esp+98h] [ebp-FCh]
  CParam *v15; // [esp+9Ch] [ebp-F8h]
  struct CParam *v16; // [esp+A0h] [ebp-F4h]
  CParam *v17; // [esp+A4h] [ebp-F0h]
  struct CParam *v18; // [esp+A8h] [ebp-ECh]
  CParam *v19; // [esp+ACh] [ebp-E8h]
  struct CParam *v20; // [esp+B0h] [ebp-E4h]
  CParam *v21; // [esp+B4h] [ebp-E0h]
  struct IScheduleEntry *v22; // [esp+B8h] [ebp-DCh]
  CSubProblemSolveEvent *v23; // [esp+BCh] [ebp-D8h]
  struct COptimizeOptions *v24; // [esp+C0h] [ebp-D4h]
  COptimizeOptions *v25; // [esp+C4h] [ebp-D0h]
  struct CParam *v26; // [esp+C8h] [ebp-CCh]
  CParam *v27; // [esp+CCh] [ebp-C8h]
  struct CParam *v28; // [esp+D0h] [ebp-C4h]
  CParam *v29; // [esp+D4h] [ebp-C0h]
  int v30; // [esp+D8h] [ebp-BCh]
  struct CParam *v31; // [esp+DCh] [ebp-B8h]
  CParam *v32; // [esp+E0h] [ebp-B4h]
  struct CParam *v33; // [esp+E4h] [ebp-B0h]
  CParam *v34; // [esp+E8h] [ebp-ACh]
  struct CParam *v35; // [esp+ECh] [ebp-A8h]
  CParam *v36; // [esp+F0h] [ebp-A4h]
  struct CParam *v37; // [esp+F4h] [ebp-A0h]
  CParam *v38; // [esp+F8h] [ebp-9Ch]
  struct IScheduleEntry *v39; // [esp+FCh] [ebp-98h]
  CSubProblemSolveEvent *v40; // [esp+100h] [ebp-94h]
  struct COptimizeOptions *v41; // [esp+104h] [ebp-90h]
  COptimizeOptions *v42; // [esp+108h] [ebp-8Ch]
  struct CParam *v43; // [esp+10Ch] [ebp-88h]
  CParam *v44; // [esp+110h] [ebp-84h]
  struct CParam *v45; // [esp+114h] [ebp-80h]
  CParam *v46; // [esp+118h] [ebp-7Ch]
  struct CParam *v47; // [esp+11Ch] [ebp-78h]
  CParam *v48; // [esp+120h] [ebp-74h]
  struct CParam *v49; // [esp+124h] [ebp-70h]
  CParam *v50; // [esp+128h] [ebp-6Ch]
  struct IScheduleEntry *v51; // [esp+12Ch] [ebp-68h]
  CSubProblemSolveEvent *v52; // [esp+130h] [ebp-64h]
  struct COptimizeOptions *v53; // [esp+134h] [ebp-60h]
  COptimizeOptions *v54; // [esp+138h] [ebp-5Ch]
  struct CParam *v55; // [esp+13Ch] [ebp-58h]
  CParam *v56; // [esp+140h] [ebp-54h]
  struct CParam *v57; // [esp+144h] [ebp-50h]
  CParam *v58; // [esp+148h] [ebp-4Ch]
  CConditionSet *v59; // [esp+14Ch] [ebp-48h]
  CConditionSet *C; // [esp+150h] [ebp-44h]
  struct CGrpReserveEntry *GrpResBuilding; // [esp+154h] [ebp-40h]
  int v62; // [esp+158h] [ebp-3Ch]
  int v63; // [esp+15Ch] [ebp-38h]
  int v64; // [esp+15Ch] [ebp-38h]
  int v65; // [esp+168h] [ebp-2Ch]
  int v66; // [esp+168h] [ebp-2Ch]
  int v67; // [esp+170h] [ebp-24h]
  int v68; // [esp+170h] [ebp-24h]
  int v69; // [esp+170h] [ebp-24h]
  int v70; // [esp+170h] [ebp-24h]
  int v71; // [esp+174h] [ebp-20h]
  int v72; // [esp+174h] [ebp-20h]
  int v73; // [esp+174h] [ebp-20h]
  int v74; // [esp+174h] [ebp-20h]
  int v75; // [esp+174h] [ebp-20h]
  int ProdBuildingByProdIndex; // [esp+178h] [ebp-1Ch]
  int v77; // [esp+178h] [ebp-1Ch]
  int v78; // [esp+178h] [ebp-1Ch]
  int v79; // [esp+178h] [ebp-1Ch]
  int v80; // [esp+178h] [ebp-1Ch]

  C = (CConditionSet *)operator new(4u);
  if ( C )
    v59 = CConditionSet::CConditionSet(C);
  else
    v59 = 0;
  switch ( a2 )
  {
    case 3:
      ProdBuildingByProdIndex = CProductionTab::GetProdBuildingByProdIndex(
                                  *((_DWORD *)this + 13),
                                  *((_DWORD *)this + 8),
                                  0,
                                  *((_DWORD *)this + 16));
      v65 = *((_DWORD *)a3 + 3);
      v71 = *((_DWORD *)a3 + 4);
      if ( v71 || *((_DWORD *)a3 + 5) )
      {
        v56 = (CParam *)operator new(0x1Cu);
        if ( v56 )
          v55 = CParam::CParam(v56, ProdBuildingByProdIndex, v71, 0, 0);
        else
          v55 = 0;
        CConditionSet::NewProblem(v59, 1, v55);
        if ( CProductionTab::GetProdBuildingByProdIndex(
               *((_DWORD *)this + 13),
               *((_DWORD *)this + 8),
               1,
               *((_DWORD *)this + 16)) )
        {
          v54 = (COptimizeOptions *)operator new(0x18u);
          if ( v54 )
            v53 = COptimizeOptions::COptimizeOptions(v54);
          else
            v53 = 0;
          IAI_Module::SetMaxSolution(this, v53, 5);
          if ( CSchedule::SearchExternSolution(*((CSchedule **)this + 11), *((_DWORD *)this + 7), 4, v65 + 1, 0, 0, v71) )
          {
            v48 = (CParam *)operator new(0x1Cu);
            if ( v48 )
              v47 = CParam::CParam(v48, v65 + 1, 0, 0, v71);
            else
              v47 = 0;
            CConditionSet::NewProblem(v59, 4, v47, v53);
          }
          else
          {
            v52 = (CSubProblemSolveEvent *)operator new(0x6Cu);
            if ( v52 )
              v51 = CSubProblemSolveEvent::CSubProblemSolveEvent(
                      v52,
                      this,
                      *((_DWORD *)this + 7),
                      4,
                      v65 + 1,
                      0,
                      0,
                      v71,
                      v53);
            else
              v51 = 0;
            CSchedule::NewSchedEntry(*((CSchedule **)this + 11), v51);
            *((_DWORD *)this + 9) = 2;
            v50 = (CParam *)operator new(0x1Cu);
            if ( v50 )
              v49 = CParam::CParam(v50, 0, 0, 0, 0);
            else
              v49 = 0;
            CConditionSet::NewProblem(v59, 20, v49);
          }
        }
      }
      else
      {
        *((_DWORD *)this + 9) = 3;
        v58 = (CParam *)operator new(0x1Cu);
        if ( v58 )
          v57 = CParam::CParam(v58, 0, 0, 0, 0);
        else
          v57 = 0;
        CConditionSet::NewProblem(v59, 20, v57);
      }
      break;
    case 4:
      v74 = *((_DWORD *)a3 + 4);
      v62 = *((_DWORD *)a3 + 6);
      if ( v74 )
      {
        v25 = (COptimizeOptions *)operator new(0x18u);
        if ( v25 )
          v24 = COptimizeOptions::COptimizeOptions(v25);
        else
          v24 = 0;
        IAI_Module::SetMaxSolution(this, v24, 5);
        GrpResBuilding = CReserveDatabase::GetGrpResBuilding(*((CReserveDatabase **)this + 15), v74);
        if ( CSchedule::SearchExternSolution(
               *((CSchedule **)this + 11),
               *((_DWORD *)this + 7),
               8,
               *((_DWORD *)GrpResBuilding + 3),
               v74,
               0,
               v62) )
        {
          v19 = (CParam *)operator new(0x1Cu);
          if ( v19 )
            v18 = CParam::CParam(v19, *((_DWORD *)GrpResBuilding + 3), v74, 0, v62);
          else
            v18 = 0;
          CConditionSet::NewProblem(v59, 8, v18);
        }
        else
        {
          v23 = (CSubProblemSolveEvent *)operator new(0x6Cu);
          if ( v23 )
            v22 = CSubProblemSolveEvent::CSubProblemSolveEvent(
                    v23,
                    this,
                    *((_DWORD *)this + 7),
                    8,
                    *((_DWORD *)GrpResBuilding + 3),
                    v74,
                    0,
                    v62,
                    v24);
          else
            v22 = 0;
          CSchedule::NewSchedEntry(*((CSchedule **)this + 11), v22);
          *((_DWORD *)this + 9) = 2;
          v21 = (CParam *)operator new(0x1Cu);
          if ( v21 )
            v20 = CParam::CParam(v21, 0, 0, 0, 0);
          else
            v20 = 0;
          CConditionSet::NewProblem(v59, 20, v20);
        }
      }
      else
      {
        v27 = (CParam *)operator new(0x1Cu);
        if ( v27 )
          v26 = CParam::CParam(v27);
        else
          v26 = 0;
        *((_DWORD *)this + 9) = 3;
        CConditionSet::NewProblem(v59, 20, v26);
      }
      break;
    case 5:
      v66 = *((_DWORD *)a3 + 3);
      v72 = *((_DWORD *)a3 + 4);
      v77 = CProductionTab::GetProdBuildingByProdIndex(
              *((_DWORD *)this + 13),
              *((_DWORD *)this + 8),
              v66,
              *((_DWORD *)this + 16));
      v67 = CSchedule::GetInvokeEvent(*((_DWORD *)this + 11), v77);
      if ( v67 && !*(_DWORD *)(v67 + 48) )
      {
        v44 = (CParam *)operator new(0x1Cu);
        if ( v44 )
          v43 = CParam::CParam(v44, v77, v72, 0, 0);
        else
          v43 = 0;
        CConditionSet::NewProblem(v59, 1, v43);
        if ( CProductionTab::GetProdBuildingByProdIndex(
               *((_DWORD *)this + 13),
               *((_DWORD *)this + 8),
               v66 + 1,
               *((_DWORD *)this + 16)) )
        {
          v42 = (COptimizeOptions *)operator new(0x18u);
          if ( v42 )
            v41 = COptimizeOptions::COptimizeOptions(v42);
          else
            v41 = 0;
          IAI_Module::SetMaxSolution(this, v41, 5);
          if ( CSchedule::SearchExternSolution(*((CSchedule **)this + 11), *((_DWORD *)this + 7), 4, v66 + 1, 0, 0, v72) )
          {
            v36 = (CParam *)operator new(0x1Cu);
            if ( v36 )
              v35 = CParam::CParam(v36, v66 + 1, 0, 0, v72);
            else
              v35 = 0;
            CConditionSet::NewProblem(v59, 4, v35, v41);
          }
          else
          {
            v40 = (CSubProblemSolveEvent *)operator new(0x6Cu);
            if ( v40 )
              v39 = CSubProblemSolveEvent::CSubProblemSolveEvent(
                      v40,
                      this,
                      *((_DWORD *)this + 7),
                      4,
                      v66 + 1,
                      0,
                      0,
                      v72,
                      v41);
            else
              v39 = 0;
            CSchedule::NewSchedEntry(*((CSchedule **)this + 11), v39);
            *((_DWORD *)this + 9) = 2;
            v38 = (CParam *)operator new(0x1Cu);
            if ( v38 )
              v37 = CParam::CParam(v38, 0, 0, 0, 0);
            else
              v37 = 0;
            CConditionSet::NewProblem(v59, 20, v37);
          }
        }
      }
      else
      {
        *((_DWORD *)this + 9) = 1;
        v46 = (CParam *)operator new(0x1Cu);
        if ( v46 )
          v45 = CParam::CParam(v46, 0, 0, 0, 0);
        else
          v45 = 0;
        CConditionSet::NewProblem(v59, 20, v45);
      }
      break;
    case 6:
      v78 = *((_DWORD *)a3 + 3);
      v68 = CSchedule::GetInvokeEvent(*((_DWORD *)this + 11), v78);
      if ( v68 && !*(_DWORD *)(v68 + 48) )
      {
        if ( *((_DWORD *)a3 + 4) || *((_DWORD *)a3 + 6) )
        {
          v73 = *((_DWORD *)a3 + 4);
          v30 = *((_DWORD *)a3 + 6);
          v29 = (CParam *)operator new(0x1Cu);
          if ( v29 )
            v28 = CParam::CParam(v29, v78, v73, 0, v30);
          else
            v28 = 0;
          CConditionSet::NewProblem(v59, 1, v28);
        }
        else
        {
          *((_DWORD *)this + 9) = 3;
          v32 = (CParam *)operator new(0x1Cu);
          if ( v32 )
            v31 = CParam::CParam(v32, 0, 0, 0, 0);
          else
            v31 = 0;
          CConditionSet::NewProblem(v59, 20, v31);
        }
      }
      else
      {
        *((_DWORD *)this + 9) = 1;
        v34 = (CParam *)operator new(0x1Cu);
        if ( v34 )
          v33 = CParam::CParam(v34, 0, 0, 0, 0);
        else
          v33 = 0;
        CConditionSet::NewProblem(v59, 20, v33);
      }
      break;
    case 8:
      v79 = *((_DWORD *)a3 + 3);
      v69 = CSchedule::GetInvokeEvent(*((_DWORD *)this + 11), v79);
      if ( v69 && !*(_DWORD *)(v69 + 48) )
      {
        v75 = *((_DWORD *)a3 + 4);
        v15 = (CParam *)operator new(0x1Cu);
        if ( v15 )
          v14 = CParam::CParam(v15, v79, v75, 0, 0);
        else
          v14 = 0;
        CConditionSet::NewProblem(v59, 1, v14);
      }
      else
      {
        *((_DWORD *)this + 9) = 1;
        v17 = (CParam *)operator new(0x1Cu);
        if ( v17 )
          v16 = CParam::CParam(v17, 0, 0, 0, 0);
        else
          v16 = 0;
        CConditionSet::NewProblem(v59, 20, v16);
      }
      break;
    case 9:
      v80 = *((_DWORD *)a3 + 3);
      v70 = CSchedule::GetInvokeEvent(*((_DWORD *)this + 11), v80);
      if ( v70 && !*(_DWORD *)(v70 + 48) )
      {
        v63 = *((_DWORD *)a3 + 4);
        v5 = *((_DWORD *)a3 + 6);
        v11 = (CParam *)operator new(0x1Cu);
        if ( v11 )
          v10 = CParam::CParam(v11, v80, 0, v63, v5);
        else
          v10 = 0;
        CConditionSet::NewProblem(v59, 1, v10);
      }
      else
      {
        *((_DWORD *)this + 9) = 1;
        v13 = (CParam *)operator new(0x1Cu);
        if ( v13 )
          v12 = CParam::CParam(v13, 0, 0, 0, 0);
        else
          v12 = 0;
        CConditionSet::NewProblem(v59, 20, v12);
      }
      break;
    case 10:
      v64 = *((_DWORD *)a3 + 4);
      if ( v64 )
      {
        v4 = *((_DWORD *)a3 + 6);
        v7 = (CParam *)operator new(0x1Cu);
        if ( v7 )
          v6 = CParam::CParam(v7, 46, 0, v64, v4);
        else
          v6 = 0;
        CConditionSet::NewProblem(v59, 1, v6);
      }
      else
      {
        v9 = (CParam *)operator new(0x1Cu);
        if ( v9 )
          v8 = CParam::CParam(v9);
        else
          v8 = 0;
        *((_DWORD *)this + 9) = 3;
        CConditionSet::NewProblem(v59, 20, v8);
      }
      break;
    default:
      return v59;
  }
  return v59;
}


// address=[0x2f389f0]
// Decompiled from double __thiscall CSiedlerAI::Valuation(CSiedlerAI *this, int a2, struct CParam *a3, int a4, int a5)
double  CSiedlerAI::Valuation(int a2, class CParam * a3, int a4, int a5) {
  
  double v6; // [esp+0h] [ebp-48h]
  float v7; // [esp+10h] [ebp-38h]
  float v8; // [esp+14h] [ebp-34h]
  float v9; // [esp+18h] [ebp-30h]
  float v10; // [esp+1Ch] [ebp-2Ch]
  int v11; // [esp+20h] [ebp-28h]
  int v12; // [esp+30h] [ebp-18h]
  int v13; // [esp+38h] [ebp-10h]
  int v14; // [esp+38h] [ebp-10h]
  int ProdBuildingByProdIndex; // [esp+3Ch] [ebp-Ch]
  int v16; // [esp+3Ch] [ebp-Ch]
  bool v18; // [esp+47h] [ebp-1h]
  bool v19; // [esp+47h] [ebp-1h]

  v6 = DOUBLE_1_0;
  switch ( a2 )
  {
    case 1:
      v6 = 0.0;
      break;
    case 3:
      ProdBuildingByProdIndex = CProductionTab::GetProdBuildingByProdIndex(
                                  *((_DWORD *)this + 13),
                                  *((_DWORD *)this + 8),
                                  0,
                                  *((_DWORD *)this + 16));
      v13 = *((_DWORD *)a3 + 4);
      v18 = CProductionTab::GetProdBuildingByProdIndex(
              *((_DWORD *)this + 13),
              *((_DWORD *)this + 8),
              1,
              *((_DWORD *)this + 16)) == 0;
      v10 = CSiedlerAI::GeneralValuation(this, ProdBuildingByProdIndex, v13, 0, v18);
      v6 = v10;
      break;
    case 5:
      v11 = *((_DWORD *)a3 + 3);
      v14 = *((_DWORD *)a3 + 4);
      v16 = CProductionTab::GetProdBuildingByProdIndex(
              *((_DWORD *)this + 13),
              *((_DWORD *)this + 8),
              v11,
              *((_DWORD *)this + 16));
      v12 = *((_DWORD *)a3 + 6);
      v19 = CProductionTab::GetProdBuildingByProdIndex(
              *((_DWORD *)this + 13),
              *((_DWORD *)this + 8),
              v11 + 1,
              *((_DWORD *)this + 16)) == 0;
      v9 = CSiedlerAI::GeneralValuation(this, v16, v14, v12, v19);
      v6 = v9;
      break;
    case 6:
      v8 = CSiedlerAI::GeneralValuation(this, *((_DWORD *)a3 + 3), *((_DWORD *)a3 + 4), *((_DWORD *)a3 + 6), 1);
      v6 = v8;
      break;
    case 8:
      v7 = CSiedlerAI::GeneralValuation(this, *((_DWORD *)a3 + 3), *((_DWORD *)a3 + 4), *((_DWORD *)a3 + 4), 1);
      v6 = v7;
      break;
    case 9:
      v6 = (float)CSchedule::GeneralValuation(
                    *((_DWORD *)this + 11),
                    *((_DWORD *)a3 + 3),
                    1,
                    *((_DWORD *)a3 + 4),
                    *((_DWORD *)a3 + 6),
                    *((_DWORD *)a3 + 6),
                    1,
                    *((_DWORD *)a3 + 5));
      break;
    case 10:
      v6 = (float)CSchedule::GeneralValuation(
                    *((_DWORD *)this + 11),
                    *((_DWORD *)a3 + 3),
                    1,
                    *((_DWORD *)a3 + 4),
                    0,
                    *((_DWORD *)a3 + 6),
                    1,
                    *((_DWORD *)a3 + 5));
      break;
    default:
      return v6;
  }
  return v6;
}


// address=[0x2f38ca0]
// Decompiled from int __thiscall CSiedlerAI::RepeatingBehaviour(CSiedlerAI *this, int a2, struct CParam *a3)
int  CSiedlerAI::RepeatingBehaviour(int a2, class CParam * a3) {
  
  int v4; // [esp+8h] [ebp-4h]

  v4 = 1;
  if ( a2 == 2 )
    return 2;
  return v4;
}


// address=[0x2f38cd0]
// Decompiled from int __thiscall CSiedlerAI::PreferExternSolution(CSiedlerAI *this, int a2, struct CParam *a3)
int  CSiedlerAI::PreferExternSolution(int a2, class CParam * a3) {
  
  int v4; // [esp+4h] [ebp-8h]

  v4 = 0;
  if ( a2 >= 4 && (a2 <= 5 || a2 == 8) )
    return 2;
  return v4;
}


// address=[0x2f38d10]
// Decompiled from struct CSolutionTree *__thiscall CSiedlerAI::ImportSolution(CSchedule **this, int a2, struct CParam *a3)
class CSolutionTree *  CSiedlerAI::ImportSolution(int a2, class CParam * a3) {
  
  int v4; // [esp+0h] [ebp-10h]
  int v6; // [esp+8h] [ebp-8h]

  v4 = 0;
  if ( a2 < 4 || a2 > 5 && a2 != 8 )
    return (struct CSolutionTree *)v4;
  v6 = CSchedule::SearchExternSolution(
         this[11],
         this[7],
         a2,
         *((_DWORD *)a3 + 3),
         *((_DWORD *)a3 + 4),
         *((_DWORD *)a3 + 5),
         *((_DWORD *)a3 + 6));
  if ( v6 )
    return CSchedule::GetSolution(this[11], v6);
  return (struct CSolutionTree *)v4;
}


// address=[0x2f38da0]
// Decompiled from void __thiscall CSiedlerAI::Consequence(CSiedlerAI *this, int a2, struct CParam *a3)
void  CSiedlerAI::Consequence(int a2, class CParam * a3) {
  
  ;
}


// address=[0x2f38db0]
// Decompiled from int __thiscall CSiedlerAI::ExecuteAction(CSiedlerAI *this, int a2, struct CParam *a3)
void  CSiedlerAI::ExecuteAction(int a2, class CParam * a3) {
  
  int result; // eax
  int v4; // [esp+4h] [ebp-44h] BYREF
  int v5; // [esp+Ch] [ebp-3Ch] BYREF
  int v6[3]; // [esp+10h] [ebp-38h] BYREF
  struct IScheduleEntry *SchedEntry; // [esp+1Ch] [ebp-2Ch]
  int v8; // [esp+20h] [ebp-28h]
  struct IScheduleEntry *v9; // [esp+24h] [ebp-24h]
  void *C; // [esp+28h] [ebp-20h]
  int PackWorldPosition; // [esp+2Ch] [ebp-1Ch]
  int v12; // [esp+30h] [ebp-18h] BYREF
  int v13; // [esp+34h] [ebp-14h] BYREF
  CSiedlerAI *v14; // [esp+38h] [ebp-10h]
  int v15; // [esp+44h] [ebp-4h]

  v14 = this;
  v6[1] = 0;
  PackWorldPosition = 0;
  SchedEntry = 0;
  result = a2;
  v8 = a2;
  if ( a2 != 1 )
    return result;
  if ( *((_DWORD *)a3 + 4) )
  {
    CReserveDatabase::GetResPosition(*((CReserveDatabase **)v14 + 15), *((_DWORD *)a3 + 4), &v12, &v13);
    PackWorldPosition = CReserveDatabase::GetPackWorldPosition(*((CReserveDatabase **)v14 + 15), *((_DWORD *)a3 + 4));
  }
  else
  {
    CReserveDatabase::UnpackPosition(*((CReserveDatabase **)v14 + 15), *((_DWORD *)a3 + 5), &v12, &v13);
    PackWorldPosition = *((_DWORD *)a3 + 5);
  }
  if ( *((_DWORD *)a3 + 3) == 46 )
  {
    CReserveDatabase::UnpackPosition(*((CReserveDatabase **)v14 + 15), *((_DWORD *)a3 + 6), &v5, v6);
    (*(void (__thiscall **)(_DWORD, int, int, _DWORD, int *))(**(_DWORD **)(*(_DWORD *)(*((_DWORD *)v14 + 11) + 36) + 28)
                                                            + 8))(
      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v14 + 11) + 36) + 28),
      v12,
      v13,
      0,
      &v4);
    SchedEntry = CSchedule::GetSchedEntry(*((CSchedule **)v14 + 11), *((_DWORD *)v14 + 7));
    if ( v4 )
      *((_DWORD *)a3 + 3) = 47;
    CSchedule::SetPositionOfTower(*((CSchedule **)v14 + 11), *((_DWORD *)v14 + 7), *((_DWORD *)a3 + 3), v12, v13);
  }
  C = operator new(0x58u);
  v15 = 0;
  if ( C )
    v9 = (struct IScheduleEntry *)CBuildingEvent::CBuildingEvent(
                                    C,
                                    *((_DWORD *)a3 + 3),
                                    0,
                                    v12,
                                    v13,
                                    PackWorldPosition,
                                    0,
                                    1);
  else
    v9 = 0;
  v6[2] = (int)v9;
  v15 = -1;
  return CSchedule::NewSchedEntry(*((CSchedule **)v14 + 11), v9);
}


// address=[0x2f38f70]
// Decompiled from int __thiscall CSiedlerAI::PreExecuteAction(CSiedlerAI *this, int a2, struct CParam *a3)
void  CSiedlerAI::PreExecuteAction(int a2, class CParam * a3) {
  
  return a2;
}


// address=[0x2f38f90]
// Decompiled from int __thiscall CSiedlerAI::GetInvokeBuildingType(CSiedlerAI *this, struct IScheduleEntry *a2, enum BUILDING_TYPES *a3)
void  CSiedlerAI::GetInvokeBuildingType(class IScheduleEntry * a2, enum BUILDING_TYPES * a3) {
  
  int result; // eax
  int v4; // [esp+4h] [ebp-1Ch]
  int i; // [esp+14h] [ebp-Ch]
  int v6; // [esp+18h] [ebp-8h]

  for ( i = 0; i < 6; ++i )
    *((_DWORD *)a3 + i) = 0;
  if ( *((_DWORD *)a2 + 4) == 11 )
  {
    v4 = *((_DWORD *)a2 + 15);
    v6 = *((_DWORD *)a2 + 11);
  }
  if ( *((_DWORD *)a2 + 4) == 10 )
  {
    v4 = *((_DWORD *)a2 + 15);
    v6 = *((_DWORD *)a2 + 11);
  }
  result = v4 - 3;
  switch ( v4 )
  {
    case 3:
      result = 4;
      *(_DWORD *)a3 = 0;
      break;
    case 4:
      result = CProductionTab::GetProdBuildingByProdIndex(
                 *((_DWORD *)this + 13),
                 *((_DWORD *)this + 8),
                 v6,
                 *((_DWORD *)this + 16));
      *(_DWORD *)a3 = result;
      break;
    case 5:
      result = 0;
      *(_DWORD *)a3 = v6;
      break;
    case 8:
      result = v6;
      *(_DWORD *)a3 = v6;
      break;
    case 9:
      result = (int)a3;
      *(_DWORD *)a3 = v6;
      break;
    case 10:
      *((_DWORD *)this + 8) = CProductionTab::GetProdIdForGoodType(*((_DWORD *)this + 13), v6, *((_DWORD *)this + 16));
      result = CProductionTab::GetProdBuildingByProdIndex(
                 *((_DWORD *)this + 13),
                 *((_DWORD *)this + 8),
                 0,
                 *((_DWORD *)this + 16));
      *(_DWORD *)a3 = result;
      break;
    case 11:
      result = 0;
      *(_DWORD *)a3 = 46;
      break;
    default:
      return result;
  }
  return result;
}


// address=[0x2f39150]
// Decompiled from int __thiscall CSiedlerAI::GetInvokePosition(CSiedlerAI *this, int a2, int a3, int a4, int a5, int a6)
int  CSiedlerAI::GetInvokePosition(int a2, int a3, int a4, int a5, int a6) {
  
  int v7; // [esp+4h] [ebp-10h]
  int v8; // [esp+8h] [ebp-Ch] BYREF
  int v9; // [esp+Ch] [ebp-8h] BYREF
  CSiedlerAI *v10; // [esp+10h] [ebp-4h]

  v10 = this;
  v7 = 0;
  switch ( a2 )
  {
    case 4:
    case 5:
      CReserveDatabase::GetResPosition(*((CReserveDatabase **)v10 + 15), a6, &v8, &v9);
      v7 = CReserveDatabase::PackPosition(*((CReserveDatabase **)v10 + 15), v8, v9);
      break;
    case 8:
      CReserveDatabase::GetResPosition(*((CReserveDatabase **)v10 + 15), a4, &v8, &v9);
      v7 = CReserveDatabase::PackPosition(*((CReserveDatabase **)v10 + 15), v8 / 16, v9 / 16);
      break;
    case 9:
      v7 = a4;
      break;
    default:
      return v7;
  }
  return v7;
}


// address=[0x2f39260]
// Decompiled from int __thiscall CSiedlerAI::GetBestBuilding(CSiedlerAI *this, int a2, int a3, _DWORD *a4)
int  CSiedlerAI::GetBestBuilding(struct SBUILDINFODATA * a2, int a3, int & a4) {
  
  int v6; // [esp+8h] [ebp-10h]
  int v7; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v7 = 0;
  for ( i = 0; i < a3; ++i )
  {
    v6 = CSiedlerAI::ScoringBuilding(this, (struct SBUILDINFODATA *)(a2 + 76 * i));
    if ( v6 > v7 )
    {
      v7 = v6;
      *a4 = i;
    }
  }
  return v7;
}


// address=[0x2f392f0]
// Decompiled from int __thiscall CSiedlerAI::ScoringBuilding(CSiedlerAI *this, struct SBUILDINFODATA *a2)
int  CSiedlerAI::ScoringBuilding(struct SBUILDINFODATA * a2) {
  
  return 500;
}


// address=[0x2f39310]
// Decompiled from double __thiscall CSiedlerAI::GeneralValuation(int this, int a2, int a3, int a4, unsigned __int8 a5)
double  CSiedlerAI::GeneralValuation(enum BUILDING_TYPES a2, int a3, int a4, bool a5) {
  
  int PackWorldPosition; // eax
  int v7; // [esp-Ch] [ebp-2Ch]
  int v8; // [esp-4h] [ebp-24h]
  struct CGrpReserveEntry *GrpResBuilding; // [esp+18h] [ebp-8h]

  GrpResBuilding = CReserveDatabase::GetGrpResBuilding(*(CReserveDatabase **)(this + 60), a3);
  v8 = *((char *)GrpResBuilding + 40);
  v7 = *(_DWORD *)(this + 68);
  PackWorldPosition = CReserveDatabase::GetPackWorldPosition(*(CReserveDatabase **)(this + 60), a4);
  return (double)CSchedule::GeneralValuation(
                   *(_DWORD *)(this + 44),
                   a2,
                   1,
                   *((_DWORD *)GrpResBuilding + 8),
                   PackWorldPosition,
                   v7,
                   a5,
                   v8);
}


// address=[0x2f393a0]
// Decompiled from int __thiscall CSiedlerAI::CloneMemory(CSiedlerAI *this)
class CDynList *  CSiedlerAI::CloneMemory(void) {
  
  return 0;
}


// address=[0x2f393b0]
// Decompiled from int __thiscall CSiedlerAI::tmp_speichern(CSiedlerAI *this)
class tmp_mem *  CSiedlerAI::tmp_speichern(void) {
  
  return 0;
}


// address=[0x2f393c0]
// Decompiled from void __thiscall CSiedlerAI::tmp_rueckspeichern(CSiedlerAI *this, struct tmp_mem *a2)
void  CSiedlerAI::tmp_rueckspeichern(class tmp_mem *) {
  
  ;
}


