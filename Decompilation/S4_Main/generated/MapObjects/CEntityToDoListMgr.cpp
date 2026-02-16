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
  _DWORD v39[4]; // [esp+A8h] [ebp-ADCh] BYREF
  _BYTE v40[16]; // [esp+C8h] [ebp-ABCh] BYREF
  _DWORD v41[4]; // [esp+E8h] [ebp-A9Ch] BYREF
  _BYTE v42[16]; // [esp+F8h] [ebp-A8Ch] BYREF
  _DWORD v43[4]; // [esp+108h] [ebp-A7Ch] BYREF
  _BYTE v44[16]; // [esp+118h] [ebp-A6Ch] BYREF
  _DWORD v45[4]; // [esp+128h] [ebp-A5Ch] BYREF
  _BYTE v46[16]; // [esp+138h] [ebp-A4Ch] BYREF
  _DWORD v47[4]; // [esp+148h] [ebp-A3Ch] BYREF
  _DWORD v48[4]; // [esp+158h] [ebp-A2Ch] BYREF
  _DWORD v49[4]; // [esp+168h] [ebp-A1Ch] BYREF
  _DWORD v50[31]; // [esp+178h] [ebp-A0Ch] BYREF
  _DWORD v51[4]; // [esp+1F4h] [ebp-990h] BYREF
  _DWORD v52[4]; // [esp+204h] [ebp-980h] BYREF
  _DWORD *v53; // [esp+214h] [ebp-970h]
  int v54; // [esp+218h] [ebp-96Ch]
  int v55; // [esp+21Ch] [ebp-968h]
  int v56; // [esp+220h] [ebp-964h]
  CConfigManager *Instance; // [esp+224h] [ebp-960h]
  const struct AdvXMLParser::Attribute *v58; // [esp+228h] [ebp-95Ch]
  AdvXMLParser::Element *v59; // [esp+22Ch] [ebp-958h]
  _DWORD *v60; // [esp+230h] [ebp-954h]
  _DWORD *v61; // [esp+234h] [ebp-950h]
  void *v62; // [esp+238h] [ebp-94Ch]
  _DWORD *v63; // [esp+23Ch] [ebp-948h]
  _DWORD *v64; // [esp+240h] [ebp-944h]
  int v65; // [esp+244h] [ebp-940h]
  int ValueOfDefine; // [esp+248h] [ebp-93Ch]
  const struct AdvXMLParser::Attribute *v67; // [esp+24Ch] [ebp-938h]
  AdvXMLParser::Element *v68; // [esp+250h] [ebp-934h]
  _DWORD *v69; // [esp+254h] [ebp-930h]
  _DWORD *v70; // [esp+258h] [ebp-92Ch]
  _DWORD *v71; // [esp+25Ch] [ebp-928h]
  _DWORD *v72; // [esp+260h] [ebp-924h]
  struct CDefineTranslator *v73; // [esp+264h] [ebp-920h]
  void *Root; // [esp+268h] [ebp-91Ch]
  int v75; // [esp+26Ch] [ebp-918h]
  int v76; // [esp+270h] [ebp-914h]
  int v77; // [esp+274h] [ebp-910h]
  void *v78; // [esp+278h] [ebp-90Ch]
  void *v79; // [esp+27Ch] [ebp-908h]
  const struct AdvXMLParser::Element *v80; // [esp+280h] [ebp-904h]
  AdvXMLParser::Element *v81; // [esp+284h] [ebp-900h]
  AdvXMLParser::Element *v82; // [esp+288h] [ebp-8FCh]
  void *v83; // [esp+28Ch] [ebp-8F8h]
  const struct AdvXMLParser::Element *v84; // [esp+290h] [ebp-8F4h]
  AdvXMLParser::Element *v85; // [esp+294h] [ebp-8F0h]
  AdvXMLParser::Element *v86; // [esp+298h] [ebp-8ECh]
  int v87; // [esp+29Ch] [ebp-8E8h]
  CConfigManager *v88; // [esp+2A0h] [ebp-8E4h]
  void *v89; // [esp+2A4h] [ebp-8E0h]
  void *v90; // [esp+2A8h] [ebp-8DCh]
  const struct AdvXMLParser::Attribute *v91; // [esp+2ACh] [ebp-8D8h]
  AdvXMLParser::Element *v92; // [esp+2B0h] [ebp-8D4h]
  AdvXMLParser::Element *v93; // [esp+2B4h] [ebp-8D0h]
  int v94; // [esp+2B8h] [ebp-8CCh]
  int v95; // [esp+2BCh] [ebp-8C8h]
  CConfigManager *v96; // [esp+2C0h] [ebp-8C4h]
  const struct AdvXMLParser::Attribute *v97; // [esp+2C4h] [ebp-8C0h]
  AdvXMLParser::Element *v98; // [esp+2C8h] [ebp-8BCh]
  int v99; // [esp+2CCh] [ebp-8B8h]
  _DWORD *v100; // [esp+2D0h] [ebp-8B4h]
  _DWORD *v101; // [esp+2D4h] [ebp-8B0h]
  _DWORD *v102; // [esp+2D8h] [ebp-8ACh]
  _DWORD *v103; // [esp+2DCh] [ebp-8A8h]
  int v104; // [esp+2E0h] [ebp-8A4h]
  void *v105; // [esp+2E4h] [ebp-8A0h]
  int v106; // [esp+2E8h] [ebp-89Ch]
  void *C; // [esp+2ECh] [ebp-898h]
  CEntityTask *v108; // [esp+2F0h] [ebp-894h]
  int v109; // [esp+2F4h] [ebp-890h]
  int v110; // [esp+2F8h] [ebp-88Ch]
  int v111; // [esp+2FCh] [ebp-888h]
  int v112; // [esp+300h] [ebp-884h]
  void *v113; // [esp+304h] [ebp-880h]
  void *v114; // [esp+308h] [ebp-87Ch]
  const struct AdvXMLParser::Element *v115; // [esp+30Ch] [ebp-878h]
  AdvXMLParser::Element *v116; // [esp+310h] [ebp-874h]
  void *v117; // [esp+314h] [ebp-870h]
  void *v118; // [esp+318h] [ebp-86Ch]
  const struct AdvXMLParser::Element *v119; // [esp+31Ch] [ebp-868h]
  AdvXMLParser::Element *v120; // [esp+320h] [ebp-864h]
  int v121; // [esp+324h] [ebp-860h]
  int v122; // [esp+328h] [ebp-85Ch]
  void *v123; // [esp+32Ch] [ebp-858h]
  int v124; // [esp+330h] [ebp-854h]
  void *v125; // [esp+334h] [ebp-850h]
  void *v126; // [esp+338h] [ebp-84Ch]
  const struct AdvXMLParser::Element *v127; // [esp+33Ch] [ebp-848h]
  AdvXMLParser::Element *v128; // [esp+340h] [ebp-844h]
  int v129; // [esp+344h] [ebp-840h]
  void *v130; // [esp+348h] [ebp-83Ch]
  void *v131; // [esp+34Ch] [ebp-838h]
  const struct AdvXMLParser::Element *v132; // [esp+350h] [ebp-834h]
  AdvXMLParser::Element *v133; // [esp+354h] [ebp-830h]
  int v134; // [esp+358h] [ebp-82Ch]
  CConfigManager *v135; // [esp+35Ch] [ebp-828h]
  const struct AdvXMLParser::Element *v136; // [esp+360h] [ebp-824h]
  AdvXMLParser::Element *v137; // [esp+364h] [ebp-820h]
  int v138; // [esp+368h] [ebp-81Ch]
  void *v139; // [esp+36Ch] [ebp-818h]
  const struct AdvXMLParser::Element *v140; // [esp+370h] [ebp-814h]
  AdvXMLParser::Element *v141; // [esp+374h] [ebp-810h]
  int v142; // [esp+378h] [ebp-80Ch]
  void *v143; // [esp+37Ch] [ebp-808h]
  const struct AdvXMLParser::Element *v144; // [esp+380h] [ebp-804h]
  AdvXMLParser::Element *v145; // [esp+384h] [ebp-800h]
  int v146; // [esp+388h] [ebp-7FCh]
  void *v147; // [esp+38Ch] [ebp-7F8h]
  void *v148; // [esp+390h] [ebp-7F4h]
  const struct AdvXMLParser::Element *v149; // [esp+394h] [ebp-7F0h]
  AdvXMLParser::Element *v150; // [esp+398h] [ebp-7ECh]
  void *v151; // [esp+39Ch] [ebp-7E8h]
  const struct AdvXMLParser::Element *v152; // [esp+3A0h] [ebp-7E4h]
  AdvXMLParser::Element *v153; // [esp+3A4h] [ebp-7E0h]
  void *v154; // [esp+3A8h] [ebp-7DCh]
  const struct AdvXMLParser::Element *v155; // [esp+3ACh] [ebp-7D8h]
  AdvXMLParser::Element *v156; // [esp+3B0h] [ebp-7D4h]
  int v157; // [esp+3B4h] [ebp-7D0h]
  int v158; // [esp+3B8h] [ebp-7CCh]
  CConfigManager *v159; // [esp+3BCh] [ebp-7C8h]
  const struct AdvXMLParser::Element *v160; // [esp+3C0h] [ebp-7C4h]
  AdvXMLParser::Element *v161; // [esp+3C4h] [ebp-7C0h]
  _DWORD *v162; // [esp+3C8h] [ebp-7BCh]
  _DWORD *v163; // [esp+3CCh] [ebp-7B8h]
  void *v164; // [esp+3D0h] [ebp-7B4h]
  _DWORD *v165; // [esp+3D4h] [ebp-7B0h]
  void *v166[4]; // [esp+3D8h] [ebp-7ACh] BYREF
  void *v167; // [esp+3E8h] [ebp-79Ch]
  const struct AdvXMLParser::Element *v168; // [esp+3ECh] [ebp-798h]
  const struct AdvXMLParser::Element *v169; // [esp+3F0h] [ebp-794h]
  int v170; // [esp+3F4h] [ebp-790h]
  void *v171; // [esp+3F8h] [ebp-78Ch]
  const struct AdvXMLParser::Element *v172; // [esp+3FCh] [ebp-788h]
  const struct AdvXMLParser::Attribute *v173; // [esp+400h] [ebp-784h]
  int v174; // [esp+404h] [ebp-780h]
  void *v175; // [esp+408h] [ebp-77Ch]
  int v176; // [esp+40Ch] [ebp-778h]
  const struct AdvXMLParser::Element *v177; // [esp+410h] [ebp-774h]
  void *v178; // [esp+414h] [ebp-770h]
  const struct AdvXMLParser::Element *v179; // [esp+418h] [ebp-76Ch]
  const struct AdvXMLParser::Attribute *v180; // [esp+41Ch] [ebp-768h]
  CConfigManager *v181; // [esp+420h] [ebp-764h]
  const struct AdvXMLParser::Element *v182; // [esp+424h] [ebp-760h]
  CConfigManager *v183; // [esp+428h] [ebp-75Ch]
  const struct AdvXMLParser::Element *v184; // [esp+42Ch] [ebp-758h]
  const struct AdvXMLParser::Element *v185; // [esp+430h] [ebp-754h]
  const struct AdvXMLParser::Element *v186; // [esp+434h] [ebp-750h]
  const struct AdvXMLParser::Element *v187; // [esp+438h] [ebp-74Ch]
  int v188; // [esp+43Ch] [ebp-748h]
  CConfigManager *v189; // [esp+440h] [ebp-744h]
  const struct AdvXMLParser::Element *v190; // [esp+444h] [ebp-740h]
  char v191[4]; // [esp+448h] [ebp-73Ch] BYREF
  const struct AdvXMLParser::Element *v192; // [esp+44Ch] [ebp-738h]
  const struct AdvXMLParser::Element *v193; // [esp+450h] [ebp-734h]
  CConfigManager *v194; // [esp+454h] [ebp-730h]
  const struct AdvXMLParser::Attribute *v195; // [esp+458h] [ebp-72Ch]
  CConfigManager *v196; // [esp+45Ch] [ebp-728h]
  const struct AdvXMLParser::Attribute *v197; // [esp+460h] [ebp-724h]
  void *v198; // [esp+464h] [ebp-720h]
  char v199[4]; // [esp+468h] [ebp-71Ch] BYREF
  _DWORD v200[4]; // [esp+46Ch] [ebp-718h] BYREF
  int v201; // [esp+47Ch] [ebp-708h]
  int v202; // [esp+480h] [ebp-704h]
  int v203; // [esp+484h] [ebp-700h]
  int v204; // [esp+488h] [ebp-6FCh]
  int v205; // [esp+48Ch] [ebp-6F8h]
  int v206; // [esp+490h] [ebp-6F4h]
  struct CDefineTranslator *v207; // [esp+494h] [ebp-6F0h]
  int m; // [esp+498h] [ebp-6ECh]
  int j; // [esp+49Ch] [ebp-6E8h]
  int v210; // [esp+4A0h] [ebp-6E4h] BYREF
  int v211; // [esp+4A4h] [ebp-6E0h]
  unsigned int v212; // [esp+4A8h] [ebp-6DCh]
  int SettlerJobFrameCount; // [esp+4ACh] [ebp-6D8h]
  char *v214; // [esp+4B0h] [ebp-6D4h]
  int *v215; // [esp+4B4h] [ebp-6D0h]
  int v220; // [esp+4BCh] [ebp-6C8h]
  int SettlerFirstJob; // [esp+4C0h] [ebp-6C4h]
  int k; // [esp+4C4h] [ebp-6C0h]
  bool v223; // [esp+4CAh] [ebp-6BAh]
  bool v224; // [esp+4CBh] [ebp-6B9h]
  CEntityToDoListMgr *v225; // [esp+4CCh] [ebp-6B8h]
  int i; // [esp+4D0h] [ebp-6B4h]
  _BYTE v227[28]; // [esp+924h] [ebp-260h] BYREF
  _BYTE v228[28]; // [esp+940h] [ebp-244h] BYREF
  _BYTE v229[28]; // [esp+95Ch] [ebp-228h] BYREF
  _BYTE v230[28]; // [esp+978h] [ebp-20Ch] BYREF
  _BYTE v231[28]; // [esp+994h] [ebp-1F0h] BYREF
  _BYTE v232[28]; // [esp+9B0h] [ebp-1D4h] BYREF
  _BYTE v233[28]; // [esp+9CCh] [ebp-1B8h] BYREF
  _BYTE v234[28]; // [esp+9E8h] [ebp-19Ch] BYREF
  _BYTE v235[28]; // [esp+A04h] [ebp-180h] BYREF
  _BYTE v236[28]; // [esp+A20h] [ebp-164h] BYREF
  _BYTE v237[28]; // [esp+A3Ch] [ebp-148h] BYREF
  _BYTE v238[28]; // [esp+A58h] [ebp-12Ch] BYREF
  _BYTE v239[28]; // [esp+A74h] [ebp-110h] BYREF
  _BYTE v240[28]; // [esp+A90h] [ebp-F4h] BYREF
  _BYTE v241[28]; // [esp+AACh] [ebp-D8h] BYREF
  char v242[28]; // [esp+AC8h] [ebp-BCh] BYREF
  char v243[28]; // [esp+AE4h] [ebp-A0h] BYREF
  _BYTE v244[28]; // [esp+B00h] [ebp-84h] BYREF
  _BYTE v245[28]; // [esp+B1Ch] [ebp-68h] BYREF
  _BYTE v246[28]; // [esp+B38h] [ebp-4Ch] BYREF
  _BYTE v247[28]; // [esp+B54h] [ebp-30h] BYREF
  int *v248; // [esp+B74h] [ebp-10h]
  int v249; // [esp+B80h] [ebp-4h]

  v248 = &v32;
  v225 = this;
  for ( i = 0; i < 5; ++i )
  {
    for ( j = 0; j < 267; ++j )
      *((_DWORD *)v225 + 267 * i + j) = 0;
  }
  SettlerFirstJob = 0;
  SettlerJobFrameCount = 0;
  for ( i = 0; i < 5; ++i )
  {
    for ( k = 1; k < 67; ++k )
    {
      SettlerFirstJob = CGfxManager::GetSettlerFirstJob(i, k);
      if ( !SettlerFirstJob || *((_DWORD *)v225 + k) )
      {
        *((_DWORD *)v225 + 267 * i + k) = *((_DWORD *)v225 + k);
      }
      else
      {
        v167 = operator new(0xCu);
        v249 = 0;
        if ( v167 )
          v174 = std::list<CEntityTask>::list<CEntityTask>(v167);
        else
          v174 = 0;
        v77 = v174;
        v249 = -1;
        *((_DWORD *)v225 + 267 * i + k) = v174;
        std::list<CEntityTask>::clear();
        SettlerJobFrameCount = CGfxManager::GetSettlerJobFrameCount((CGfxManager *)g_pGfxManager, i, SettlerFirstJob, 2);
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
  v220 = 67;
  for ( m = 1; m < 66; ++m )
  {
    for ( i = 0; i < 5; ++i )
    {
      SettlerFirstJob = CGfxManager::GetSettlerFirstJob(i, m);
      if ( !SettlerFirstJob || *((_DWORD *)v225 + v220) )
      {
        *((_DWORD *)v225 + 267 * i + v220) = *((_DWORD *)v225 + v220);
      }
      else
      {
        v175 = operator new(0xCu);
        v249 = 1;
        if ( v175 )
          v176 = std::list<CEntityTask>::list<CEntityTask>(v175);
        else
          v176 = 0;
        v76 = v176;
        v249 = -1;
        *((_DWORD *)v225 + 267 * i + v220) = v176;
        std::list<CEntityTask>::clear();
        SettlerJobFrameCount = CGfxManager::GetSettlerJobFrameCount((CGfxManager *)g_pGfxManager, i, SettlerFirstJob, 2);
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
    ++v220;
  }
  v210 = 0;
  v214 = (char *)AdvXMLParser::Parser::OpenXMLFile(aGamedataJobinf, &v210);
  if ( !v214 )
    return v225;
  v249 = 2;
  v50[20] = AdvXMLParser::Parser::Parser(v37);
  LOBYTE(v249) = 3;
  v75 = AdvXMLParser::Parser::Parse((AdvXMLParser::Parser *)v37, v214, v210);
  std::auto_ptr<AdvXMLParser::Document>::auto_ptr<AdvXMLParser::Document>(v75);
  LOBYTE(v249) = 4;
  v4 = std::auto_ptr<AdvXMLParser::Document>::operator->(v32);
  Root = (void *)AdvXMLParser::Document::GetRoot(v4);
  v178 = Root;
  v73 = (struct CDefineTranslator *)CDefineTranslator::Instance();
  v207 = v73;
  v72 = (_DWORD *)AdvXMLParser::NodeContainer::Begin(v178, v46);
  v71 = v72;
  LOBYTE(v249) = 5;
  v50[28] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v51, v72);
  LOBYTE(v249) = 7;
  AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v46);
  v70 = AdvXMLParser::NodeContainer::End(v178, v45);
  v69 = v70;
  LOBYTE(v249) = 8;
  v50[27] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v49, v70);
  LOBYTE(v249) = 10;
  AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v45);
  while ( AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v51, (int)v49) )
  {
    v68 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v51);
    v67 = AdvXMLParser::Element::operator[](v68, "id");
    v173 = v67;
    v50[26] = (*(int (__thiscall **)(const struct AdvXMLParser::Attribute *, _BYTE *))(*(_DWORD *)v67 + 8))(v67, v247);
    LOBYTE(v249) = 11;
    ValueOfDefine = CDefineTranslator::GetValueOfDefine(v207, (struct std::string *)v247);
    v212 = ValueOfDefine;
    if ( ValueOfDefine == -1 )
    {
      v5 = (const char *)std::string::c_str(v247);
      CTrace::Print("This race define: %s used in JobInfo.xml but isn't part of S4_Defines.h", v5);
    }
    v65 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v51);
    v64 = (_DWORD *)AdvXMLParser::NodeContainer::Begin(v65, v44);
    v63 = v64;
    LOBYTE(v249) = 12;
    v50[7] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v52, v64);
    LOBYTE(v249) = 14;
    AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v44);
    v62 = (void *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v51);
    v61 = AdvXMLParser::NodeContainer::End(v62, v43);
    v60 = v61;
    LOBYTE(v249) = 15;
    v50[6] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v50, v61);
    LOBYTE(v249) = 17;
    AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v43);
    while ( AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v52, (int)v50) )
    {
      v59 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v52);
      v58 = AdvXMLParser::Element::operator[](v59, "id");
      v180 = v58;
      v50[5] = (*(int (__thiscall **)(const struct AdvXMLParser::Attribute *, _BYTE *))(*(_DWORD *)v58 + 8))(v58, v246);
      LOBYTE(v249) = 18;
      Instance = CConfigManagerPtr::GetInstance();
      v181 = Instance;
      v6 = std::string::c_str(v246);
      v56 = ((int (__thiscall *)(CConfigManager *, int))v181->?)(v181, v6);
      v211 = v56;
      if ( v56 == -1 )
      {
        v7 = (const char *)std::string::c_str(v246);
        CTrace::Print("This job list define: %s used in JobInfo.xml but isn't part of S4_AnimListDefines.h", v7);
      }
      if ( v211 == -1 )
      {
        v55 = BBSupportDbgReport(2, "MapObjects\\EntityToDoListMgr.cpp", 218, "iJobListIdx != -1");
        if ( v55 == 1 )
          __debugbreak();
      }
      v50[4] = 0;
      memset(&v50[23], 0, 12);
      v54 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v52);
      v53 = (_DWORD *)AdvXMLParser::NodeContainer::Begin(v54, v42);
      v165 = v53;
      LOBYTE(v249) = 19;
      v50[22] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v200, v53);
      LOBYTE(v249) = 21;
      AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v42);
      v164 = (void *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v52);
      v163 = AdvXMLParser::NodeContainer::End(v164, v41);
      v162 = v163;
      LOBYTE(v249) = 22;
      v50[21] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v47, v163);
      LOBYTE(v249) = 24;
      AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v41);
      while ( AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v200, (int)v47) )
      {
        v161 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v200);
        v160 = AdvXMLParser::Element::operator()(v161, "jobPart", 0);
        v182 = v160;
        v50[14] = (*(int (__thiscall **)(const struct AdvXMLParser::Element *, _BYTE *))(*(_DWORD *)v160 + 8))(
                    v160,
                    v245);
        LOBYTE(v249) = 25;
        v159 = CConfigManagerPtr::GetInstance();
        v183 = v159;
        v8 = std::string::c_str(v245);
        v158 = ((int (__thiscall *)(CConfigManager *, int))v183->?)(v183, v8);
        v205 = v158;
        if ( v158 == -1 )
        {
          v9 = (const char *)std::string::c_str(v245);
          CTrace::Print("This job define: %s used in JobInfo.xml but isn't part of SettlerDefines.h", v9);
        }
        if ( v205 == -1 )
        {
          v157 = BBSupportDbgReport(2, "MapObjects\\EntityToDoListMgr.cpp", 239, "iJobNr != -1");
          if ( v157 == 1 )
            __debugbreak();
        }
        v156 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v200);
        v155 = AdvXMLParser::Element::operator()(v156, "x", 0);
        v184 = v155;
        v154 = (void *)(*(int (__thiscall **)(const struct AdvXMLParser::Element *, _BYTE *))(*(_DWORD *)v155 + 8))(
                         v155,
                         v235);
        v10 = (const char *)std::string::c_str(v154);
        v110 = j__atoi(v10);
        std::string::~string(v235);
        v153 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v200);
        v152 = AdvXMLParser::Element::operator()(v153, "y", 0);
        v185 = v152;
        v151 = (void *)(*(int (__thiscall **)(const struct AdvXMLParser::Element *, _BYTE *))(*(_DWORD *)v152 + 8))(
                         v152,
                         v236);
        v11 = (const char *)std::string::c_str(v151);
        v111 = j__atoi(v11);
        std::string::~string(v236);
        v150 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v200);
        v149 = AdvXMLParser::Element::operator()(v150, "task", 0);
        v186 = v149;
        v148 = (void *)(*(int (__thiscall **)(const struct AdvXMLParser::Element *, _BYTE *))(*(_DWORD *)v149 + 8))(
                         v149,
                         v234);
        v147 = v148;
        LOBYTE(v249) = 26;
        v12 = (char *)std::string::c_str(v148);
        v50[19] = std::string::string((struct std::string *)v239, v12);
        LOBYTE(v249) = 27;
        v146 = CDefineTranslator::GetValueOfDefine(v207, (struct std::string *)v239);
        v50[18] = v146;
        LOBYTE(v249) = 26;
        std::string::~string(v239);
        LOBYTE(v249) = 25;
        std::string::~string(v234);
        v145 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v200);
        v144 = AdvXMLParser::Element::operator()(v145, "dir", 0);
        v187 = v144;
        v143 = (void *)(*(int (__thiscall **)(const struct AdvXMLParser::Element *, _BYTE *))(*(_DWORD *)v144 + 8))(
                         v144,
                         v237);
        v13 = (const char *)std::string::c_str(v143);
        v202 = j__atoi(v13);
        std::string::~string(v237);
        if ( v202 == -1 )
          v188 = 0;
        else
          v188 = v202;
        v142 = CGfxManager::GetSettlerJobFrameCount((CGfxManager *)g_pGfxManager, v212, v205, v188);
        v203 = v142;
        if ( v142 == 1 )
        {
          v31 = (const char *)std::string::c_str(v245);
          v30 = (const char *)std::string::c_str(v247);
          v14 = (const char *)std::string::c_str(v246);
          BBSupportTracePrintF(3, "WARNING: There is a problem in job %s of race %s with job part %s!", v14, v30, v31);
        }
        v141 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v200);
        v140 = AdvXMLParser::Element::operator()(v141, "duration", 0);
        v190 = v140;
        v139 = (void *)(*(int (__thiscall **)(const struct AdvXMLParser::Element *, _BYTE *))(*(_DWORD *)v140 + 8))(
                         v140,
                         v238);
        v15 = (const char *)std::string::c_str(v139);
        v206 = j__atoi(v15);
        std::string::~string(v238);
        if ( v206 >= 128 )
        {
          v138 = BBSupportDbgReport(2, "MapObjects\\EntityToDoListMgr.cpp", 294, "duration < 128");
          if ( v138 == 1 )
            __debugbreak();
        }
        if ( !v206 )
          v206 = v203;
        v137 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v200);
        v136 = AdvXMLParser::Element::operator()(v137, "entity", 0);
        v177 = v136;
        v50[17] = (*(int (__thiscall **)(const struct AdvXMLParser::Element *, char *))(*(_DWORD *)v136 + 8))(
                    v136,
                    v242);
        LOBYTE(v249) = 28;
        v135 = CConfigManagerPtr::GetInstance();
        v189 = v135;
        v16 = std::string::c_str(v242);
        v134 = ((int (__thiscall *)(CConfigManager *, int))v189->?)(v189, v16);
        v201 = v134;
        if ( v134 == -1 )
          v201 = 0;
        v133 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v200);
        v132 = AdvXMLParser::Element::operator()(v133, "task", 0);
        v179 = v132;
        v131 = (void *)(*(int (__thiscall **)(const struct AdvXMLParser::Element *, _BYTE *))(*(_DWORD *)v132 + 8))(
                         v132,
                         v227);
        v130 = v131;
        LOBYTE(v249) = 29;
        v17 = (char *)std::string::c_str(v131);
        v50[16] = std::string::string((struct std::string *)v240, v17);
        LOBYTE(v249) = 30;
        v129 = CDefineTranslator::GetValueOfDefine(v207, (struct std::string *)v240);
        v109 = v129;
        LOBYTE(v249) = 29;
        std::string::~string(v240);
        LOBYTE(v249) = 28;
        std::string::~string(v227);
        v128 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v200);
        v127 = AdvXMLParser::Element::operator()(v128, "trigger", 0);
        v172 = v127;
        v126 = (void *)(*(int (__thiscall **)(const struct AdvXMLParser::Element *, _BYTE *))(*(_DWORD *)v127 + 8))(
                         v127,
                         v228);
        v125 = v126;
        LOBYTE(v249) = 31;
        v18 = (char *)std::string::c_str(v126);
        v50[15] = std::string::string((struct std::string *)v241, v18);
        LOBYTE(v249) = 32;
        v124 = CDefineTranslator::GetValueOfDefine(v207, (struct std::string *)v241);
        v112 = v124;
        LOBYTE(v249) = 31;
        std::string::~string(v241);
        LOBYTE(v249) = 28;
        std::string::~string(v228);
        if ( !*((_DWORD *)v225 + 267 * v212 + v211) )
        {
          v123 = operator new(0xCu);
          v171 = v123;
          LOBYTE(v249) = 33;
          if ( v123 )
          {
            v122 = std::list<CEntityTask>::list<CEntityTask>(v171);
            v170 = v122;
          }
          else
          {
            v170 = 0;
          }
          v121 = v170;
          LOBYTE(v249) = 28;
          *((_DWORD *)v225 + 267 * v212 + v211) = v170;
          std::list<CEntityTask>::clear();
        }
        v120 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v200);
        v119 = AdvXMLParser::Element::operator()(v120, "visible", 0);
        v169 = v119;
        v118 = (void *)(*(int (__thiscall **)(const struct AdvXMLParser::Element *, _BYTE *))(*(_DWORD *)v119 + 8))(
                         v119,
                         v230);
        v117 = v118;
        LOBYTE(v249) = 34;
        v19 = (const char *)std::string::c_str(v118);
        v224 = j__atoi(v19) != 0;
        v116 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v200);
        v115 = AdvXMLParser::Element::operator()(v116, "forward", 0);
        v168 = v115;
        v114 = (void *)(*(int (__thiscall **)(const struct AdvXMLParser::Element *, _BYTE *))(*(_DWORD *)v115 + 8))(
                         v115,
                         v229);
        v113 = v114;
        LOBYTE(v249) = 35;
        v20 = (const char *)std::string::c_str(v114);
        v223 = j__atoi(v20) != 0;
        v108 = CEntityTask::CEntityTask(
                 (CEntityTask *)v33,
                 v109,
                 v205,
                 v110,
                 v111,
                 v206,
                 v203,
                 v202,
                 v223,
                 v224,
                 v201,
                 0,
                 0,
                 v112);
        std::list<CEntityTask>::push_back(v108);
        LOBYTE(v249) = 34;
        std::string::~string(v229);
        LOBYTE(v249) = 28;
        std::string::~string(v230);
        LOBYTE(v249) = 25;
        std::string::~string(v242);
        LOBYTE(v249) = 24;
        std::string::~string(v245);
        AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v200);
      }
      LOBYTE(v249) = 21;
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v47);
      LOBYTE(v249) = 18;
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v200);
      LOBYTE(v249) = 17;
      std::string::~string(v246);
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v52);
    }
    LOBYTE(v249) = 14;
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v50);
    LOBYTE(v249) = 11;
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v52);
    LOBYTE(v249) = 10;
    std::string::~string(v247);
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v51);
  }
  LOBYTE(v249) = 7;
  AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v49);
  LOBYTE(v249) = 4;
  AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v51);
  LOBYTE(v249) = 3;
  std::auto_ptr<AdvXMLParser::Document>::~auto_ptr<AdvXMLParser::Document>(v199);
  LOBYTE(v249) = 2;
  AdvXMLParser::Parser::~Parser(v37);
  v249 = -1;
  C = v214;
  operator delete[](v214);
  memset(CEntityToDoListMgr::m_vJobSoundInfo, 0, 0xB78u);
  v210 = 0;
  v214 = (char *)AdvXMLParser::Parser::OpenXMLFile(aGamedataJobsou, &v210);
  if ( !v214 )
    return v225;
  v249 = 38;
  v50[8] = AdvXMLParser::Parser::Parser(v38);
  LOBYTE(v249) = 39;
  v106 = AdvXMLParser::Parser::Parse((AdvXMLParser::Parser *)v38, v214, v210);
  std::auto_ptr<AdvXMLParser::Document>::auto_ptr<AdvXMLParser::Document>(v106);
  LOBYTE(v249) = 40;
  v21 = std::auto_ptr<AdvXMLParser::Document>::operator->(v32);
  v105 = (void *)AdvXMLParser::Document::GetRoot(v21);
  v198 = v105;
  v104 = CDefineTranslator::Instance();
  v50[13] = v104;
  v50[12] = 0;
  v103 = (_DWORD *)AdvXMLParser::NodeContainer::Begin(v198, v40);
  v102 = v103;
  LOBYTE(v249) = 41;
  v50[11] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v166, v103);
  LOBYTE(v249) = 43;
  AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v40);
  v101 = AdvXMLParser::NodeContainer::End(v198, v39);
  v100 = v101;
  LOBYTE(v249) = 44;
  v50[10] = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v48, v101);
  LOBYTE(v249) = 46;
  AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v39);
  while ( AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v166, (int)v48) )
  {
    v99 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v166);
    v50[9] = v99;
    v98 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v166);
    v97 = AdvXMLParser::Element::operator[](v98, "id");
    v197 = v97;
    v50[30] = (*(int (__thiscall **)(const struct AdvXMLParser::Attribute *, _BYTE *))(*(_DWORD *)v97 + 8))(v97, v244);
    LOBYTE(v249) = 47;
    v96 = CConfigManagerPtr::GetInstance();
    v196 = v96;
    v22 = std::string::c_str(v244);
    v95 = ((int (__thiscall *)(CConfigManager *, int))v196->?)(v196, v22);
    v204 = v95;
    if ( v95 <= 0 || v204 >= 367 )
    {
      v94 = BBSupportDbgReport(2, "MapObjects\\EntityToDoListMgr.cpp", 417, "( index > 0) && ( index < SIV_MAX_JOB )");
      if ( v94 == 1 )
        __debugbreak();
    }
    v215 = &CEntityToDoListMgr::m_vJobSoundInfo[2 * v204];
    v93 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v166);
    v92 = AdvXMLParser::Element::operator()(v93, "sound", 0);
    v91 = AdvXMLParser::Element::operator[](v92, "id");
    v195 = v91;
    v90 = (void *)(*(int (__thiscall **)(const struct AdvXMLParser::Attribute *, _BYTE *))(*(_DWORD *)v91 + 8))(
                    v91,
                    v231);
    v89 = v90;
    LOBYTE(v249) = 48;
    v23 = (char *)std::string::c_str(v90);
    v50[29] = std::string::string((struct std::string *)v243, v23);
    LOBYTE(v249) = 50;
    std::string::~string(v231);
    v88 = CConfigManagerPtr::GetInstance();
    v194 = v88;
    v24 = std::string::c_str(v243);
    v87 = ((int (__thiscall *)(CConfigManager *, int))v194->?)(v194, v24);
    *v215 = v87;
    if ( *v215 == -1 )
      *v215 = 0;
    v86 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v166);
    v85 = AdvXMLParser::Element::operator()(v86, "sound", 0);
    v84 = AdvXMLParser::Element::operator()(v85, "frame", 0);
    v193 = v84;
    v83 = (void *)(*(int (__thiscall **)(const struct AdvXMLParser::Element *, _BYTE *))(*(_DWORD *)v84 + 8))(v84, v232);
    v25 = (const char *)std::string::c_str(v83);
    v26 = j__atoi(v25);
    *((_BYTE *)v215 + 5) = v26;
    std::string::~string(v232);
    v82 = (AdvXMLParser::Element *)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v166);
    v81 = AdvXMLParser::Element::operator()(v82, "sound", 0);
    v80 = AdvXMLParser::Element::operator()(v81, "random", 0);
    v192 = v80;
    v79 = (void *)(*(int (__thiscall **)(const struct AdvXMLParser::Element *, _BYTE *))(*(_DWORD *)v80 + 8))(v80, v233);
    v27 = (const char *)std::string::c_str(v79);
    v28 = j__atoi(v27);
    *((_BYTE *)v215 + 4) = v28;
    std::string::~string(v233);
    if ( !*((_BYTE *)v215 + 4) )
      *((_BYTE *)v215 + 4) = 100;
    LOBYTE(v249) = 47;
    std::string::~string(v243);
    LOBYTE(v249) = 46;
    std::string::~string(v244);
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v166);
  }
  LOBYTE(v249) = 43;
  AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v48);
  LOBYTE(v249) = 40;
  AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v166);
  LOBYTE(v249) = 39;
  std::auto_ptr<AdvXMLParser::Document>::~auto_ptr<AdvXMLParser::Document>(v191);
  LOBYTE(v249) = 38;
  AdvXMLParser::Parser::~Parser(v38);
  v249 = -1;
  v78 = v214;
  operator delete[](v214);
  return v225;
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
class std::list<class CEntityTask,class std::allocator<class CEntityTask> > *  CEntityToDoListMgr::SettlerJobList(int a2, int a3) {
  
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
void __cdecl CEntityToDoListMgr::GetJobSoundInfo(int a1, struct SJobSoundInfo & a2) {
  
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

