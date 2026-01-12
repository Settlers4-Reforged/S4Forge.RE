#include "CEntityToDoListMgr.h"

// Definitions for class CEntityToDoListMgr

// address=[0x154c610]
// Decompiled from CEntityToDoListMgr *__thiscall CEntityToDoListMgr::CEntityToDoListMgr(CEntityToDoListMgr *this)
 CEntityToDoListMgr::CEntityToDoListMgr(void) {
  
  CEntityTask *v1; // eax
  CEntityTask *v2; // eax
  CEntityTask *v3; // eax
  int v4; // eax
  const char *v5; // eax
  int v6; // eax
  const char *v7; // eax
  int v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  int v16; // eax
  char *v17; // eax
  char *v18; // eax
  const char *v19; // eax
  const char *v20; // eax
  int v21; // eax
  int v22; // eax
  char *v23; // eax
  int v24; // eax
  const char *v25; // eax
  char v26; // al
  const char *v27; // eax
  char v28; // al
  const char *v30; // [esp-8h] [ebp-B8Ch]
  const char *v31; // [esp-4h] [ebp-B88h]
  int v32; // [esp+0h] [ebp-B84h] BYREF
  char v33[24]; // [esp+10h] [ebp-B74h] BYREF
  char v34[24]; // [esp+28h] [ebp-B5Ch] BYREF
  char v35[24]; // [esp+40h] [ebp-B44h] BYREF
  char v36[24]; // [esp+58h] [ebp-B2Ch] BYREF
  _BYTE v37[28]; // [esp+70h] [ebp-B14h] BYREF
  _BYTE v38[28]; // [esp+8Ch] [ebp-AF8h] BYREF
  _BYTE v39[16]; // [esp+A8h] [ebp-ADCh] BYREF
  _BYTE v40[16]; // [esp+C8h] [ebp-ABCh] BYREF
  _BYTE v41[16]; // [esp+E8h] [ebp-A9Ch] BYREF
  _BYTE v42[16]; // [esp+F8h] [ebp-A8Ch] BYREF
  _BYTE v43[16]; // [esp+108h] [ebp-A7Ch] BYREF
  _BYTE v44[16]; // [esp+118h] [ebp-A6Ch] BYREF
  _BYTE v45[16]; // [esp+128h] [ebp-A5Ch] BYREF
  _BYTE v46[16]; // [esp+138h] [ebp-A4Ch] BYREF
  _BYTE v47[16]; // [esp+148h] [ebp-A3Ch] BYREF
  _BYTE v48[16]; // [esp+158h] [ebp-A2Ch] BYREF
  _BYTE v49[16]; // [esp+168h] [ebp-A1Ch] BYREF
  _BYTE v50[16]; // [esp+178h] [ebp-A0Ch] BYREF
  int v51; // [esp+188h] [ebp-9FCh]
  int v52; // [esp+18Ch] [ebp-9F8h]
  int v53; // [esp+190h] [ebp-9F4h]
  int v54; // [esp+194h] [ebp-9F0h]
  int v55; // [esp+198h] [ebp-9ECh]
  int v56; // [esp+19Ch] [ebp-9E8h]
  int v57; // [esp+1A0h] [ebp-9E4h]
  int v58; // [esp+1A4h] [ebp-9E0h]
  int v59; // [esp+1A8h] [ebp-9DCh]
  int v60; // [esp+1ACh] [ebp-9D8h]
  int v61; // [esp+1B0h] [ebp-9D4h]
  void *v62; // [esp+1B4h] [ebp-9D0h]
  void *v63; // [esp+1B8h] [ebp-9CCh]
  int v64; // [esp+1BCh] [ebp-9C8h]
  int v65; // [esp+1C0h] [ebp-9C4h]
  void *v66; // [esp+1C4h] [ebp-9C0h]
  int v67; // [esp+1C8h] [ebp-9BCh]
  int v68; // [esp+1CCh] [ebp-9B8h]
  int v69; // [esp+1D0h] [ebp-9B4h]
  int v70; // [esp+1D4h] [ebp-9B0h]
  int v71; // [esp+1D8h] [ebp-9ACh]
  int v72; // [esp+1DCh] [ebp-9A8h]
  int v73; // [esp+1E0h] [ebp-9A4h]
  int v74; // [esp+1E4h] [ebp-9A0h]
  int v75; // [esp+1E8h] [ebp-99Ch]
  void *v76; // [esp+1ECh] [ebp-998h]
  int v77; // [esp+1F0h] [ebp-994h]
  _BYTE v78[16]; // [esp+1F4h] [ebp-990h] BYREF
  _BYTE v79[16]; // [esp+204h] [ebp-980h] BYREF
  int v80; // [esp+214h] [ebp-970h]
  int v81; // [esp+218h] [ebp-96Ch]
  int v82; // [esp+21Ch] [ebp-968h]
  int v83; // [esp+220h] [ebp-964h]
  CConfigManager *Instance; // [esp+224h] [ebp-960h]
  int v85; // [esp+228h] [ebp-95Ch]
  int v86; // [esp+22Ch] [ebp-958h]
  int v87; // [esp+230h] [ebp-954h]
  int v88; // [esp+234h] [ebp-950h]
  int v89; // [esp+238h] [ebp-94Ch]
  int v90; // [esp+23Ch] [ebp-948h]
  int v91; // [esp+240h] [ebp-944h]
  int v92; // [esp+244h] [ebp-940h]
  unsigned int ValueOfDefine; // [esp+248h] [ebp-93Ch]
  int v94; // [esp+24Ch] [ebp-938h]
  int v95; // [esp+250h] [ebp-934h]
  int v96; // [esp+254h] [ebp-930h]
  int v97; // [esp+258h] [ebp-92Ch]
  int v98; // [esp+25Ch] [ebp-928h]
  int v99; // [esp+260h] [ebp-924h]
  int v100; // [esp+264h] [ebp-920h]
  int Root; // [esp+268h] [ebp-91Ch]
  struct Document *v102; // [esp+26Ch] [ebp-918h]
  int v103; // [esp+270h] [ebp-914h]
  int v104; // [esp+274h] [ebp-910h]
  void *v105; // [esp+278h] [ebp-90Ch]
  void *v106; // [esp+27Ch] [ebp-908h]
  int v107; // [esp+280h] [ebp-904h]
  int v108; // [esp+284h] [ebp-900h]
  int v109; // [esp+288h] [ebp-8FCh]
  void *v110; // [esp+28Ch] [ebp-8F8h]
  int v111; // [esp+290h] [ebp-8F4h]
  int v112; // [esp+294h] [ebp-8F0h]
  int v113; // [esp+298h] [ebp-8ECh]
  int v114; // [esp+29Ch] [ebp-8E8h]
  CConfigManager *v115; // [esp+2A0h] [ebp-8E4h]
  void *v116; // [esp+2A4h] [ebp-8E0h]
  void *v117; // [esp+2A8h] [ebp-8DCh]
  int v118; // [esp+2ACh] [ebp-8D8h]
  int v119; // [esp+2B0h] [ebp-8D4h]
  int v120; // [esp+2B4h] [ebp-8D0h]
  int v121; // [esp+2B8h] [ebp-8CCh]
  int v122; // [esp+2BCh] [ebp-8C8h]
  CConfigManager *v123; // [esp+2C0h] [ebp-8C4h]
  int v124; // [esp+2C4h] [ebp-8C0h]
  int v125; // [esp+2C8h] [ebp-8BCh]
  int v126; // [esp+2CCh] [ebp-8B8h]
  int v127; // [esp+2D0h] [ebp-8B4h]
  int v128; // [esp+2D4h] [ebp-8B0h]
  int v129; // [esp+2D8h] [ebp-8ACh]
  int v130; // [esp+2DCh] [ebp-8A8h]
  int v131; // [esp+2E0h] [ebp-8A4h]
  int v132; // [esp+2E4h] [ebp-8A0h]
  struct Document *v133; // [esp+2E8h] [ebp-89Ch]
  void *C; // [esp+2ECh] [ebp-898h]
  CEntityTask *v135; // [esp+2F0h] [ebp-894h]
  int v136; // [esp+2F4h] [ebp-890h]
  int v137; // [esp+2F8h] [ebp-88Ch]
  int v138; // [esp+2FCh] [ebp-888h]
  unsigned int v139; // [esp+300h] [ebp-884h]
  void *v140; // [esp+304h] [ebp-880h]
  void *v141; // [esp+308h] [ebp-87Ch]
  int v142; // [esp+30Ch] [ebp-878h]
  int v143; // [esp+310h] [ebp-874h]
  void *v144; // [esp+314h] [ebp-870h]
  void *v145; // [esp+318h] [ebp-86Ch]
  int v146; // [esp+31Ch] [ebp-868h]
  int v147; // [esp+320h] [ebp-864h]
  int v148; // [esp+324h] [ebp-860h]
  int v149; // [esp+328h] [ebp-85Ch]
  void *v150; // [esp+32Ch] [ebp-858h]
  unsigned int v151; // [esp+330h] [ebp-854h]
  void *v152; // [esp+334h] [ebp-850h]
  void *v153; // [esp+338h] [ebp-84Ch]
  int v154; // [esp+33Ch] [ebp-848h]
  int v155; // [esp+340h] [ebp-844h]
  int v156; // [esp+344h] [ebp-840h]
  void *v157; // [esp+348h] [ebp-83Ch]
  void *v158; // [esp+34Ch] [ebp-838h]
  int v159; // [esp+350h] [ebp-834h]
  int v160; // [esp+354h] [ebp-830h]
  int v161; // [esp+358h] [ebp-82Ch]
  CConfigManager *v162; // [esp+35Ch] [ebp-828h]
  int v163; // [esp+360h] [ebp-824h]
  int v164; // [esp+364h] [ebp-820h]
  int v165; // [esp+368h] [ebp-81Ch]
  void *v166; // [esp+36Ch] [ebp-818h]
  int v167; // [esp+370h] [ebp-814h]
  int v168; // [esp+374h] [ebp-810h]
  unsigned int v169; // [esp+378h] [ebp-80Ch]
  void *v170; // [esp+37Ch] [ebp-808h]
  int v171; // [esp+380h] [ebp-804h]
  int v172; // [esp+384h] [ebp-800h]
  int v173; // [esp+388h] [ebp-7FCh]
  void *v174; // [esp+38Ch] [ebp-7F8h]
  void *v175; // [esp+390h] [ebp-7F4h]
  int v176; // [esp+394h] [ebp-7F0h]
  int v177; // [esp+398h] [ebp-7ECh]
  void *v178; // [esp+39Ch] [ebp-7E8h]
  int v179; // [esp+3A0h] [ebp-7E4h]
  int v180; // [esp+3A4h] [ebp-7E0h]
  void *v181; // [esp+3A8h] [ebp-7DCh]
  int v182; // [esp+3ACh] [ebp-7D8h]
  int v183; // [esp+3B0h] [ebp-7D4h]
  int v184; // [esp+3B4h] [ebp-7D0h]
  int v185; // [esp+3B8h] [ebp-7CCh]
  CConfigManager *v186; // [esp+3BCh] [ebp-7C8h]
  int v187; // [esp+3C0h] [ebp-7C4h]
  int v188; // [esp+3C4h] [ebp-7C0h]
  int v189; // [esp+3C8h] [ebp-7BCh]
  int v190; // [esp+3CCh] [ebp-7B8h]
  int v191; // [esp+3D0h] [ebp-7B4h]
  int v192; // [esp+3D4h] [ebp-7B0h]
  _BYTE v193[16]; // [esp+3D8h] [ebp-7ACh] BYREF
  void *v194; // [esp+3E8h] [ebp-79Ch]
  int v195; // [esp+3ECh] [ebp-798h]
  int v196; // [esp+3F0h] [ebp-794h]
  int v197; // [esp+3F4h] [ebp-790h]
  void *v198; // [esp+3F8h] [ebp-78Ch]
  int v199; // [esp+3FCh] [ebp-788h]
  int v200; // [esp+400h] [ebp-784h]
  int v201; // [esp+404h] [ebp-780h]
  void *v202; // [esp+408h] [ebp-77Ch]
  int v203; // [esp+40Ch] [ebp-778h]
  int v204; // [esp+410h] [ebp-774h]
  int v205; // [esp+414h] [ebp-770h]
  int v206; // [esp+418h] [ebp-76Ch]
  int v207; // [esp+41Ch] [ebp-768h]
  CConfigManager *v208; // [esp+420h] [ebp-764h]
  int v209; // [esp+424h] [ebp-760h]
  CConfigManager *v210; // [esp+428h] [ebp-75Ch]
  int v211; // [esp+42Ch] [ebp-758h]
  int v212; // [esp+430h] [ebp-754h]
  int v213; // [esp+434h] [ebp-750h]
  int v214; // [esp+438h] [ebp-74Ch]
  unsigned int v215; // [esp+43Ch] [ebp-748h]
  CConfigManager *v216; // [esp+440h] [ebp-744h]
  int v217; // [esp+444h] [ebp-740h]
  char v218[4]; // [esp+448h] [ebp-73Ch] BYREF
  int v219; // [esp+44Ch] [ebp-738h]
  int v220; // [esp+450h] [ebp-734h]
  CConfigManager *v221; // [esp+454h] [ebp-730h]
  int v222; // [esp+458h] [ebp-72Ch]
  CConfigManager *v223; // [esp+45Ch] [ebp-728h]
  int v224; // [esp+460h] [ebp-724h]
  int v225; // [esp+464h] [ebp-720h]
  char v226[4]; // [esp+468h] [ebp-71Ch] BYREF
  _BYTE v227[16]; // [esp+46Ch] [ebp-718h] BYREF
  int v228; // [esp+47Ch] [ebp-708h]
  int v229; // [esp+480h] [ebp-704h]
  unsigned int v230; // [esp+484h] [ebp-700h]
  int v231; // [esp+488h] [ebp-6FCh]
  int v232; // [esp+48Ch] [ebp-6F8h]
  int v233; // [esp+490h] [ebp-6F4h]
  int v234; // [esp+494h] [ebp-6F0h]
  int m; // [esp+498h] [ebp-6ECh]
  int j; // [esp+49Ch] [ebp-6E8h]
  int v237; // [esp+4A0h] [ebp-6E4h] BYREF
  int v238; // [esp+4A4h] [ebp-6E0h]
  unsigned int v239; // [esp+4A8h] [ebp-6DCh]
  int SettlerJobFrameCount; // [esp+4ACh] [ebp-6D8h]
  char *v241; // [esp+4B0h] [ebp-6D4h]
  int *v242; // [esp+4B4h] [ebp-6D0h]
  int v247; // [esp+4BCh] [ebp-6C8h]
  int SettlerFirstJob; // [esp+4C0h] [ebp-6C4h]
  int k; // [esp+4C4h] [ebp-6C0h]
  bool v250; // [esp+4CAh] [ebp-6BAh]
  bool v251; // [esp+4CBh] [ebp-6B9h]
  CEntityToDoListMgr *v252; // [esp+4CCh] [ebp-6B8h]
  int i; // [esp+4D0h] [ebp-6B4h]
  _BYTE v254[28]; // [esp+924h] [ebp-260h] BYREF
  _BYTE v255[28]; // [esp+940h] [ebp-244h] BYREF
  _BYTE v256[28]; // [esp+95Ch] [ebp-228h] BYREF
  _BYTE v257[28]; // [esp+978h] [ebp-20Ch] BYREF
  _BYTE v258[28]; // [esp+994h] [ebp-1F0h] BYREF
  _BYTE v259[28]; // [esp+9B0h] [ebp-1D4h] BYREF
  _BYTE v260[28]; // [esp+9CCh] [ebp-1B8h] BYREF
  _BYTE v261[28]; // [esp+9E8h] [ebp-19Ch] BYREF
  _BYTE v262[28]; // [esp+A04h] [ebp-180h] BYREF
  _BYTE v263[28]; // [esp+A20h] [ebp-164h] BYREF
  _BYTE v264[28]; // [esp+A3Ch] [ebp-148h] BYREF
  _BYTE v265[28]; // [esp+A58h] [ebp-12Ch] BYREF
  _BYTE v266[28]; // [esp+A74h] [ebp-110h] BYREF
  _BYTE v267[28]; // [esp+A90h] [ebp-F4h] BYREF
  _BYTE v268[28]; // [esp+AACh] [ebp-D8h] BYREF
  char v269[28]; // [esp+AC8h] [ebp-BCh] BYREF
  char v270[28]; // [esp+AE4h] [ebp-A0h] BYREF
  _BYTE v271[28]; // [esp+B00h] [ebp-84h] BYREF
  _BYTE v272[28]; // [esp+B1Ch] [ebp-68h] BYREF
  _BYTE v273[28]; // [esp+B38h] [ebp-4Ch] BYREF
  _BYTE v274[28]; // [esp+B54h] [ebp-30h] BYREF
  int *v275; // [esp+B74h] [ebp-10h]
  int v276; // [esp+B80h] [ebp-4h]

  v275 = &v32;
  v252 = this;
  for ( i = 0; i < 5; ++i )
  {
    for ( j = 0; j < 267; ++j )
      *((_DWORD *)v252 + 267 * i + j) = 0;
  }
  SettlerFirstJob = 0;
  SettlerJobFrameCount = 0;
  for ( i = 0; i < 5; ++i )
  {
    for ( k = 1; k < 67; ++k )
    {
      SettlerFirstJob = CGfxManager::GetSettlerFirstJob(i, k);
      if ( !SettlerFirstJob || *((_DWORD *)v252 + k) )
      {
        *((_DWORD *)v252 + 267 * i + k) = *((_DWORD *)v252 + k);
      }
      else
      {
        v194 = operator new(0xCu);
        v276 = 0;
        if ( v194 )
          v201 = std::list<CEntityTask>::list<CEntityTask>(v194);
        else
          v201 = 0;
        v104 = v201;
        v276 = -1;
        *((_DWORD *)v252 + 267 * i + k) = v201;
        std::list<CEntityTask>::clear();
        SettlerJobFrameCount = CGfxManager::GetSettlerJobFrameCount(
                                 (CGfxManager *)g_pGfxManager,
                                 i,
                                 SettlerFirstJob,
                                 2u);
        if ( SettlerJobFrameCount <= 0
          && BBSupportDbgReport(2, "MapObjects\\EntityToDoListMgr.cpp", 103, "frames>0") == 1 )
        {
          __debugbreak();
        }
        v1 = CEntityTask::CEntityTask(
               (CEntityTask *)v36,
               17,
               SettlerFirstJob,
               0,
               0,
               1,
               SettlerJobFrameCount,
               -1,
               1,
               1,
               0,
               0,
               0,
               0);
        std::list<CEntityTask>::push_back(v1);
      }
    }
  }
  v247 = 67;
  for ( m = 1; m < 66; ++m )
  {
    for ( i = 0; i < 5; ++i )
    {
      SettlerFirstJob = CGfxManager::GetSettlerFirstJob(i, m);
      if ( !SettlerFirstJob || *((_DWORD *)v252 + v247) )
      {
        *((_DWORD *)v252 + 267 * i + v247) = *((_DWORD *)v252 + v247);
      }
      else
      {
        v202 = operator new(0xCu);
        v276 = 1;
        if ( v202 )
          v203 = std::list<CEntityTask>::list<CEntityTask>(v202);
        else
          v203 = 0;
        v103 = v203;
        v276 = -1;
        *((_DWORD *)v252 + 267 * i + v247) = v203;
        std::list<CEntityTask>::clear();
        SettlerJobFrameCount = CGfxManager::GetSettlerJobFrameCount(
                                 (CGfxManager *)g_pGfxManager,
                                 i,
                                 SettlerFirstJob,
                                 2u);
        v2 = CEntityTask::CEntityTask(
               (CEntityTask *)v35,
               10,
               SettlerFirstJob,
               0,
               0,
               -1,
               SettlerJobFrameCount,
               1,
               1,
               1,
               0,
               0,
               0,
               0);
        std::list<CEntityTask>::push_back(v2);
        v3 = CEntityTask::CEntityTask(
               (CEntityTask *)v34,
               24,
               SettlerFirstJob,
               0,
               0,
               -1,
               SettlerJobFrameCount,
               1,
               0,
               1,
               0,
               0,
               0,
               0);
        std::list<CEntityTask>::push_back(v3);
      }
    }
    ++v247;
  }
  v237 = 0;
  v241 = AdvXMLParser::Parser::OpenXMLFile(aGamedataJobinf, &v237);
  if ( !v241 )
    return v252;
  v276 = 2;
  v67 = AdvXMLParser::Parser::Parser(v37);
  LOBYTE(v276) = 3;
  v102 = AdvXMLParser::Parser::Parse((AdvXMLParser::Parser *)v37, v241, v237);
  std::auto_ptr<AdvXMLParser::Document>::auto_ptr<AdvXMLParser::Document>(v102);
  LOBYTE(v276) = 4;
  v4 = std::auto_ptr<AdvXMLParser::Document>::operator->(v32);
  Root = AdvXMLParser::Document::GetRoot(v4);
  v205 = Root;
  v100 = CDefineTranslator::Instance();
  v234 = v100;
  v99 = AdvXMLParser::NodeContainer::Begin(v205, v46);
  v98 = v99;
  LOBYTE(v276) = 5;
  v75 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v99);
  LOBYTE(v276) = 7;
  AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v46);
  v97 = AdvXMLParser::NodeContainer::End(v205, v45);
  v96 = v97;
  LOBYTE(v276) = 8;
  v74 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v97);
  LOBYTE(v276) = 10;
  AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v45);
  while ( (unsigned __int8)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v49) )
  {
    v95 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v78);
    v94 = AdvXMLParser::Element::operator[]("id");
    v200 = v94;
    v73 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v94 + 8))(v94, v274);
    LOBYTE(v276) = 11;
    ValueOfDefine = CDefineTranslator::GetValueOfDefine(v274);
    v239 = ValueOfDefine;
    if ( ValueOfDefine == -1 )
    {
      v5 = (const char *)std::string::c_str(v274);
      CTrace::Print("This race define: %s used in JobInfo.xml but isn't part of S4_Defines.h", v5);
    }
    v92 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v78);
    v91 = AdvXMLParser::NodeContainer::Begin(v92, v44);
    v90 = v91;
    LOBYTE(v276) = 12;
    v54 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v91);
    LOBYTE(v276) = 14;
    AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v44);
    v89 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v78);
    v88 = AdvXMLParser::NodeContainer::End(v89, v43);
    v87 = v88;
    LOBYTE(v276) = 15;
    v53 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v88);
    LOBYTE(v276) = 17;
    AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v43);
    while ( (unsigned __int8)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v50) )
    {
      v86 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v79);
      v85 = AdvXMLParser::Element::operator[]("id");
      v207 = v85;
      v52 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v85 + 8))(v85, v273);
      LOBYTE(v276) = 18;
      Instance = CConfigManagerPtr::GetInstance();
      v208 = Instance;
      v6 = std::string::c_str(v273);
      v83 = ((int (__thiscall *)(CConfigManager *, int))v208->j_?GetDefineValue@CConfigManager@@UAEHPBD@Z)(v208, v6);
      v238 = v83;
      if ( v83 == -1 )
      {
        v7 = (const char *)std::string::c_str(v273);
        CTrace::Print("This job list define: %s used in JobInfo.xml but isn't part of S4_AnimListDefines.h", v7);
      }
      if ( v238 == -1 )
      {
        v82 = BBSupportDbgReport(2, "MapObjects\\EntityToDoListMgr.cpp", 218, "iJobListIdx != -1");
        if ( v82 == 1 )
          __debugbreak();
      }
      v51 = 0;
      v72 = 0;
      v71 = 0;
      v70 = 0;
      v81 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v79);
      v80 = AdvXMLParser::NodeContainer::Begin(v81, v42);
      v192 = v80;
      LOBYTE(v276) = 19;
      v69 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v80);
      LOBYTE(v276) = 21;
      AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v42);
      v191 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v79);
      v190 = AdvXMLParser::NodeContainer::End(v191, v41);
      v189 = v190;
      LOBYTE(v276) = 22;
      v68 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v190);
      LOBYTE(v276) = 24;
      AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v41);
      while ( (unsigned __int8)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v47) )
      {
        v188 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v227);
        v187 = AdvXMLParser::Element::operator()("jobPart", 0);
        v209 = v187;
        v61 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v187 + 8))(v187, v272);
        LOBYTE(v276) = 25;
        v186 = CConfigManagerPtr::GetInstance();
        v210 = v186;
        v8 = std::string::c_str(v272);
        v185 = ((int (__thiscall *)(CConfigManager *, int))v210->j_?GetDefineValue@CConfigManager@@UAEHPBD@Z)(v210, v8);
        v232 = v185;
        if ( v185 == -1 )
        {
          v9 = (const char *)std::string::c_str(v272);
          CTrace::Print("This job define: %s used in JobInfo.xml but isn't part of SettlerDefines.h", v9);
        }
        if ( v232 == -1 )
        {
          v184 = BBSupportDbgReport(2, "MapObjects\\EntityToDoListMgr.cpp", 239, "iJobNr != -1");
          if ( v184 == 1 )
            __debugbreak();
        }
        v183 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v227);
        v182 = AdvXMLParser::Element::operator()("x", 0);
        v211 = v182;
        v181 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v182 + 8))(v182, v262);
        v10 = (const char *)std::string::c_str(v181);
        v137 = j__atoi(v10);
        std::string::~string(v262);
        v180 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v227);
        v179 = AdvXMLParser::Element::operator()("y", 0);
        v212 = v179;
        v178 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v179 + 8))(v179, v263);
        v11 = (const char *)std::string::c_str(v178);
        v138 = j__atoi(v11);
        std::string::~string(v263);
        v177 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v227);
        v176 = AdvXMLParser::Element::operator()("task", 0);
        v213 = v176;
        v175 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v176 + 8))(v176, v261);
        v174 = v175;
        LOBYTE(v276) = 26;
        v12 = (char *)std::string::c_str(v175);
        v66 = std::string::string(v266, v12);
        LOBYTE(v276) = 27;
        v173 = CDefineTranslator::GetValueOfDefine(v266);
        v65 = v173;
        LOBYTE(v276) = 26;
        std::string::~string(v266);
        LOBYTE(v276) = 25;
        std::string::~string(v261);
        v172 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v227);
        v171 = AdvXMLParser::Element::operator()("dir", 0);
        v214 = v171;
        v170 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v171 + 8))(v171, v264);
        v13 = (const char *)std::string::c_str(v170);
        v229 = j__atoi(v13);
        std::string::~string(v264);
        if ( v229 == -1 )
          v215 = 0;
        else
          v215 = v229;
        v169 = CGfxManager::GetSettlerJobFrameCount((CGfxManager *)g_pGfxManager, v239, v232, v215);
        v230 = v169;
        if ( v169 == 1 )
        {
          v31 = (const char *)std::string::c_str(v272);
          v30 = (const char *)std::string::c_str(v274);
          v14 = (const char *)std::string::c_str(v273);
          BBSupportTracePrintF(3, "WARNING: There is a problem in job %s of race %s with job part %s!", v14, v30, v31);
        }
        v168 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v227);
        v167 = AdvXMLParser::Element::operator()("duration", 0);
        v217 = v167;
        v166 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v167 + 8))(v167, v265);
        v15 = (const char *)std::string::c_str(v166);
        v233 = j__atoi(v15);
        std::string::~string(v265);
        if ( v233 >= 128 )
        {
          v165 = BBSupportDbgReport(2, "MapObjects\\EntityToDoListMgr.cpp", 294, "duration < 128");
          if ( v165 == 1 )
            __debugbreak();
        }
        if ( !v233 )
          v233 = v230;
        v164 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v227);
        v163 = AdvXMLParser::Element::operator()("entity", 0);
        v204 = v163;
        v64 = (*(int (__thiscall **)(int, char *))(*(_DWORD *)v163 + 8))(v163, v269);
        LOBYTE(v276) = 28;
        v162 = CConfigManagerPtr::GetInstance();
        v216 = v162;
        v16 = std::string::c_str(v269);
        v161 = ((int (__thiscall *)(CConfigManager *, int))v216->j_?GetDefineValue@CConfigManager@@UAEHPBD@Z)(v216, v16);
        v228 = v161;
        if ( v161 == -1 )
          v228 = 0;
        v160 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v227);
        v159 = AdvXMLParser::Element::operator()("task", 0);
        v206 = v159;
        v158 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v159 + 8))(v159, v254);
        v157 = v158;
        LOBYTE(v276) = 29;
        v17 = (char *)std::string::c_str(v158);
        v63 = std::string::string(v267, v17);
        LOBYTE(v276) = 30;
        v156 = CDefineTranslator::GetValueOfDefine(v267);
        v136 = v156;
        LOBYTE(v276) = 29;
        std::string::~string(v267);
        LOBYTE(v276) = 28;
        std::string::~string(v254);
        v155 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v227);
        v154 = AdvXMLParser::Element::operator()("trigger", 0);
        v199 = v154;
        v153 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v154 + 8))(v154, v255);
        v152 = v153;
        LOBYTE(v276) = 31;
        v18 = (char *)std::string::c_str(v153);
        v62 = std::string::string(v268, v18);
        LOBYTE(v276) = 32;
        v151 = CDefineTranslator::GetValueOfDefine(v268);
        v139 = v151;
        LOBYTE(v276) = 31;
        std::string::~string(v268);
        LOBYTE(v276) = 28;
        std::string::~string(v255);
        if ( !*((_DWORD *)v252 + 267 * v239 + v238) )
        {
          v150 = operator new(0xCu);
          v198 = v150;
          LOBYTE(v276) = 33;
          if ( v150 )
          {
            v149 = std::list<CEntityTask>::list<CEntityTask>(v198);
            v197 = v149;
          }
          else
          {
            v197 = 0;
          }
          v148 = v197;
          LOBYTE(v276) = 28;
          *((_DWORD *)v252 + 267 * v239 + v238) = v197;
          std::list<CEntityTask>::clear();
        }
        v147 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v227);
        v146 = AdvXMLParser::Element::operator()("visible", 0);
        v196 = v146;
        v145 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v146 + 8))(v146, v257);
        v144 = v145;
        LOBYTE(v276) = 34;
        v19 = (const char *)std::string::c_str(v145);
        v251 = j__atoi(v19) != 0;
        v143 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v227);
        v142 = AdvXMLParser::Element::operator()("forward", 0);
        v195 = v142;
        v141 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v142 + 8))(v142, v256);
        v140 = v141;
        LOBYTE(v276) = 35;
        v20 = (const char *)std::string::c_str(v141);
        v250 = j__atoi(v20) != 0;
        v135 = CEntityTask::CEntityTask(
                 (CEntityTask *)v33,
                 v136,
                 v232,
                 v137,
                 v138,
                 v233,
                 v230,
                 v229,
                 v250,
                 v251,
                 v228,
                 0,
                 0,
                 v139);
        std::list<CEntityTask>::push_back(v135);
        LOBYTE(v276) = 34;
        std::string::~string(v256);
        LOBYTE(v276) = 28;
        std::string::~string(v257);
        LOBYTE(v276) = 25;
        std::string::~string(v269);
        LOBYTE(v276) = 24;
        std::string::~string(v272);
        AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v227);
      }
      LOBYTE(v276) = 21;
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v47);
      LOBYTE(v276) = 18;
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v227);
      LOBYTE(v276) = 17;
      std::string::~string(v273);
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v79);
    }
    LOBYTE(v276) = 14;
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v50);
    LOBYTE(v276) = 11;
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v79);
    LOBYTE(v276) = 10;
    std::string::~string(v274);
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v78);
  }
  LOBYTE(v276) = 7;
  AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v49);
  LOBYTE(v276) = 4;
  AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v78);
  LOBYTE(v276) = 3;
  std::auto_ptr<AdvXMLParser::Document>::~auto_ptr<AdvXMLParser::Document>(v226);
  LOBYTE(v276) = 2;
  AdvXMLParser::Parser::~Parser(v37);
  v276 = -1;
  C = v241;
  operator delete[](v241);
  memset(CEntityToDoListMgr::m_vJobSoundInfo, 0, 0xB78u);
  v237 = 0;
  v241 = AdvXMLParser::Parser::OpenXMLFile(aGamedataJobsou, &v237);
  if ( !v241 )
    return v252;
  v276 = 38;
  v55 = AdvXMLParser::Parser::Parser(v38);
  LOBYTE(v276) = 39;
  v133 = AdvXMLParser::Parser::Parse((AdvXMLParser::Parser *)v38, v241, v237);
  std::auto_ptr<AdvXMLParser::Document>::auto_ptr<AdvXMLParser::Document>(v133);
  LOBYTE(v276) = 40;
  v21 = std::auto_ptr<AdvXMLParser::Document>::operator->(v32);
  v132 = AdvXMLParser::Document::GetRoot(v21);
  v225 = v132;
  v131 = CDefineTranslator::Instance();
  v60 = v131;
  v59 = 0;
  v130 = AdvXMLParser::NodeContainer::Begin(v225, v40);
  v129 = v130;
  LOBYTE(v276) = 41;
  v58 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v130);
  LOBYTE(v276) = 43;
  AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v40);
  v128 = AdvXMLParser::NodeContainer::End(v225, v39);
  v127 = v128;
  LOBYTE(v276) = 44;
  v57 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v128);
  LOBYTE(v276) = 46;
  AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v39);
  while ( (unsigned __int8)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v48) )
  {
    v126 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v193);
    v56 = v126;
    v125 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v193);
    v124 = AdvXMLParser::Element::operator[]("id");
    v224 = v124;
    v77 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v124 + 8))(v124, v271);
    LOBYTE(v276) = 47;
    v123 = CConfigManagerPtr::GetInstance();
    v223 = v123;
    v22 = std::string::c_str(v271);
    v122 = ((int (__thiscall *)(CConfigManager *, int))v223->j_?GetDefineValue@CConfigManager@@UAEHPBD@Z)(v223, v22);
    v231 = v122;
    if ( v122 <= 0 || v231 >= 367 )
    {
      v121 = BBSupportDbgReport(2, "MapObjects\\EntityToDoListMgr.cpp", 417, "( index > 0) && ( index < SIV_MAX_JOB )");
      if ( v121 == 1 )
        __debugbreak();
    }
    v242 = &CEntityToDoListMgr::m_vJobSoundInfo[2 * v231];
    v120 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v193);
    v119 = AdvXMLParser::Element::operator()("sound", 0);
    v118 = AdvXMLParser::Element::operator[]("id");
    v222 = v118;
    v117 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v118 + 8))(v118, v258);
    v116 = v117;
    LOBYTE(v276) = 48;
    v23 = (char *)std::string::c_str(v117);
    v76 = std::string::string(v270, v23);
    LOBYTE(v276) = 50;
    std::string::~string(v258);
    v115 = CConfigManagerPtr::GetInstance();
    v221 = v115;
    v24 = std::string::c_str(v270);
    v114 = ((int (__thiscall *)(CConfigManager *, int))v221->j_?GetDefineValue@CConfigManager@@UAEHPBD@Z)(v221, v24);
    *v242 = v114;
    if ( *v242 == -1 )
      *v242 = 0;
    v113 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v193);
    v112 = AdvXMLParser::Element::operator()("sound", 0);
    v111 = AdvXMLParser::Element::operator()("frame", 0);
    v220 = v111;
    v110 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v111 + 8))(v111, v259);
    v25 = (const char *)std::string::c_str(v110);
    v26 = j__atoi(v25);
    *((_BYTE *)v242 + 5) = v26;
    std::string::~string(v259);
    v109 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v193);
    v108 = AdvXMLParser::Element::operator()("sound", 0);
    v107 = AdvXMLParser::Element::operator()("random", 0);
    v219 = v107;
    v106 = (void *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v107 + 8))(v107, v260);
    v27 = (const char *)std::string::c_str(v106);
    v28 = j__atoi(v27);
    *((_BYTE *)v242 + 4) = v28;
    std::string::~string(v260);
    if ( !*((_BYTE *)v242 + 4) )
      *((_BYTE *)v242 + 4) = 100;
    LOBYTE(v276) = 47;
    std::string::~string(v270);
    LOBYTE(v276) = 46;
    std::string::~string(v271);
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v193);
  }
  LOBYTE(v276) = 43;
  AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v48);
  LOBYTE(v276) = 40;
  AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v193);
  LOBYTE(v276) = 39;
  std::auto_ptr<AdvXMLParser::Document>::~auto_ptr<AdvXMLParser::Document>(v218);
  LOBYTE(v276) = 38;
  AdvXMLParser::Parser::~Parser(v38);
  v276 = -1;
  v105 = v241;
  operator delete[](v241);
  return v252;
}


// address=[0x154e090]
// Decompiled from void __thiscall CEntityToDoListMgr::~CEntityToDoListMgr(CEntityToDoListMgr *this)
 CEntityToDoListMgr::~CEntityToDoListMgr(void) {
  
  int k; // [esp+1Ch] [ebp-10h]
  int i; // [esp+20h] [ebp-Ch]
  int j; // [esp+24h] [ebp-8h]

  for ( i = 4; i >= 0; --i )
  {
    for ( j = 0; j < 267; ++j )
    {
      if ( *((_DWORD *)this + 267 * i + j) && *((_DWORD *)this + 267 * i + j) != *((_DWORD *)this + j) )
      {
        std::list<CEntityTask>::clear();
        if ( *((_DWORD *)this + 267 * i + j) )
          std::list<CEntityTask>::`scalar deleting destructor'(1);
        *((_DWORD *)this + 267 * i + j) = 0;
      }
    }
  }
  for ( k = 0; k < 267; ++k )
  {
    if ( *((_DWORD *)this + k) )
    {
      std::list<CEntityTask>::clear();
      if ( *((_DWORD *)this + k) )
        std::list<CEntityTask>::`scalar deleting destructor'(1);
      *((_DWORD *)this + k) = 0;
    }
  }
}


// address=[0x154e220]
// Decompiled from int __thiscall CEntityToDoListMgr::SettlerJobList(_DWORD *this, unsigned int a2, unsigned int a3)
class std::list<class CEntityTask,class std::allocator<class CEntityTask> > *  CEntityToDoListMgr::SettlerJobList(int,int) {
  
  if ( a2 > 4
    && BBSupportDbgReport(2, "MapObjects\\EntityToDoListMgr.cpp", 507, "_iRace >= 0 && _iRace < RACE_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a3 > 0x10A
    && BBSupportDbgReport(2, "MapObjects\\EntityToDoListMgr.cpp", 508, "_iJob >= 0 && _iJob < JOB_MAX") == 1 )
  {
    __debugbreak();
  }
  return this[267 * a2 + a3];
}


// address=[0x154e2a0]
// Decompiled from char __cdecl CEntityToDoListMgr::GetJobSoundInfo(int a1, struct SJobSoundInfo *a2)
static void __cdecl CEntityToDoListMgr::GetJobSoundInfo(int,struct SJobSoundInfo &) {
  
  char result; // al

  if ( (a1 <= 0 || a1 >= 367)
    && BBSupportDbgReport(2, "MapObjects\\EntityToDoListMgr.cpp", 536, "0<_iJobId && _iJobId<SIV_MAX_JOB") == 1 )
  {
    __debugbreak();
  }
  *(_DWORD *)a2 = CEntityToDoListMgr::m_vJobSoundInfo[2 * a1];
  *((_BYTE *)a2 + 5) = byte_40FE5BD[8 * a1];
  result = byte_40FE5BC[8 * a1];
  *((_BYTE *)a2 + 4) = result;
  return result;
}


// address=[0x40fe5b8]
// [Decompilation failed for static struct SJobSoundInfo * CEntityToDoListMgr::m_vJobSoundInfo]

