#include "CVehicleInfoMgr.h"

// Definitions for class CVehicleInfoMgr

// address=[0x15aae80]
// Decompiled from void __thiscall CVehicleInfoMgr::InitializeVehicleProperties(CVehicleInfoMgr *this, bool a2, bool a3)

void  CVehicleInfoMgr::InitializeVehicleProperties(bool,bool) {
  
  char *v3; // eax
  unsigned int v5; // [esp+Ch] [ebp-10h]
  unsigned int v6; // [esp+10h] [ebp-Ch]
  char *i; // [esp+18h] [ebp-4h]

  if ( a2 || !IVehicleInfoMgr::m_bInitialized )
  {
    IVehicleInfoMgr::m_bInitialized = 1;
    j__memset(&IVehicleInfoMgr::m_sVehicleProperties, 0, 0xAC8u);
    for ( i = (char *)&unk_37C03B8; *((_DWORD *)i + 2); i += 12 )
    {
      v5 = *((_DWORD *)i + 1);
      v6 = *(_DWORD *)i;
      if ( v5 >= 5 && BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 420, "uRace < RACE_MAX") == 1 )
        __debugbreak();
      if ( v6 >= 6 && BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 421, "uType < VEHICLE_MAX") == 1 )
        __debugbreak();
      qmemcpy((char *)&IVehicleInfoMgr::m_sVehicleProperties + 552 * v5 + 92 * v6, *((const void **)i + 2), 0x5Cu);
      v3 = (char *)&IVehicleInfoMgr::m_sVehicleProperties + 552 * v5 + 92 * v6;
      v3[88] = 1;
      if ( *((_DWORD *)v3 + 3) != v6
        && BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 428, "rProperties.m_tVehicleType == uType") == 1 )
      {
        __debugbreak();
      }
    }
    if ( !a3 )
      CVehicleInfoMgr::ReadXMLFile(this);
  }
}


// address=[0x15ac350]
// Decompiled from CVehicleInfoMgr *__thiscall CVehicleInfoMgr::CVehicleInfoMgr(CVehicleInfoMgr *this)

 CVehicleInfoMgr::CVehicleInfoMgr(void) {
  
  IVehicleInfoMgr::IVehicleInfoMgr(this);
  *(_DWORD *)this = &CVehicleInfoMgr::_vftable_;
  return this;
}


// address=[0x15aafc0]
// Decompiled from char *__thiscall CVehicleInfoMgr::ReadXMLFile(CVehicleInfoMgr *this)

void  CVehicleInfoMgr::ReadXMLFile(void) {
  
  char *result; // eax
  int v2; // eax
  const char *v3; // eax
  int v4; // eax
  const char *v5; // eax
  int v6; // eax
  const char *v7; // eax
  int v8; // eax
  const char *v9; // eax
  int v10; // eax
  const char *v11; // eax
  int v12; // eax
  const char *v13; // eax
  int v14; // eax
  const char *v15; // eax
  int v16; // eax
  const char *v17; // eax
  int v18; // [esp+0h] [ebp-594h] BYREF
  _BYTE v19[28]; // [esp+10h] [ebp-584h] BYREF
  _BYTE v20[16]; // [esp+2Ch] [ebp-568h] BYREF
  _BYTE v21[16]; // [esp+3Ch] [ebp-558h] BYREF
  _BYTE v22[16]; // [esp+4Ch] [ebp-548h] BYREF
  _BYTE v23[16]; // [esp+5Ch] [ebp-538h] BYREF
  _BYTE v24[16]; // [esp+6Ch] [ebp-528h] BYREF
  _BYTE v25[16]; // [esp+7Ch] [ebp-518h] BYREF
  int v26; // [esp+8Ch] [ebp-508h]
  int v27; // [esp+90h] [ebp-504h]
  int v28; // [esp+94h] [ebp-500h]
  int v29; // [esp+98h] [ebp-4FCh]
  int v30; // [esp+9Ch] [ebp-4F8h]
  CVehicleInfoMgr *v31; // [esp+A0h] [ebp-4F4h]
  int v32; // [esp+A4h] [ebp-4F0h]
  int v33; // [esp+A8h] [ebp-4ECh]
  int v34; // [esp+ACh] [ebp-4E8h]
  int v35; // [esp+B0h] [ebp-4E4h]
  int v36; // [esp+B4h] [ebp-4E0h]
  int v37; // [esp+B8h] [ebp-4DCh]
  int v38; // [esp+C0h] [ebp-4D4h]
  int v39; // [esp+C4h] [ebp-4D0h]
  int v40; // [esp+C8h] [ebp-4CCh]
  int v41; // [esp+CCh] [ebp-4C8h]
  _BYTE v42[16]; // [esp+D0h] [ebp-4C4h] BYREF
  int v43; // [esp+E0h] [ebp-4B4h]
  int ValueOfDefine; // [esp+E4h] [ebp-4B0h]
  int v45; // [esp+E8h] [ebp-4ACh]
  int v46; // [esp+ECh] [ebp-4A8h]
  int v47; // [esp+F0h] [ebp-4A4h]
  int v48; // [esp+F4h] [ebp-4A0h]
  int v49; // [esp+F8h] [ebp-49Ch]
  int v50; // [esp+FCh] [ebp-498h]
  int v51; // [esp+100h] [ebp-494h]
  int Root; // [esp+104h] [ebp-490h]
  int v53; // [esp+108h] [ebp-48Ch]
  struct Document *v54; // [esp+10Ch] [ebp-488h]
  void *C; // [esp+110h] [ebp-484h]
  int v56; // [esp+114h] [ebp-480h]
  struct Document *v57; // [esp+118h] [ebp-47Ch]
  int v58; // [esp+11Ch] [ebp-478h]
  int v59; // [esp+120h] [ebp-474h]
  int v60; // [esp+124h] [ebp-470h]
  int v61; // [esp+128h] [ebp-46Ch]
  int v62; // [esp+12Ch] [ebp-468h]
  int v63; // [esp+130h] [ebp-464h]
  int v64; // [esp+134h] [ebp-460h]
  int v65; // [esp+138h] [ebp-45Ch]
  int v66; // [esp+13Ch] [ebp-458h]
  int v67; // [esp+140h] [ebp-454h]
  int v68; // [esp+144h] [ebp-450h]
  int v69; // [esp+148h] [ebp-44Ch]
  int v70; // [esp+14Ch] [ebp-448h]
  int v71; // [esp+150h] [ebp-444h]
  int v72; // [esp+154h] [ebp-440h]
  int v73; // [esp+158h] [ebp-43Ch]
  int v74; // [esp+15Ch] [ebp-438h]
  int v75; // [esp+160h] [ebp-434h]
  int v76; // [esp+164h] [ebp-430h]
  int v77; // [esp+168h] [ebp-42Ch]
  int v78; // [esp+170h] [ebp-424h]
  int v79; // [esp+174h] [ebp-420h]
  int v80; // [esp+178h] [ebp-41Ch]
  int v81; // [esp+17Ch] [ebp-418h]
  int v82; // [esp+180h] [ebp-414h]
  int v83; // [esp+184h] [ebp-410h]
  int v84; // [esp+188h] [ebp-40Ch]
  int v85; // [esp+18Ch] [ebp-408h]
  int v86; // [esp+194h] [ebp-400h]
  int v87; // [esp+198h] [ebp-3FCh]
  int v88; // [esp+19Ch] [ebp-3F8h]
  int v89; // [esp+1A4h] [ebp-3F0h]
  int v90; // [esp+1A8h] [ebp-3ECh]
  int v91; // [esp+1ACh] [ebp-3E8h]
  int v92; // [esp+1B0h] [ebp-3E4h]
  int v93; // [esp+1B4h] [ebp-3E0h]
  CConfigManager *Instance; // [esp+1B8h] [ebp-3DCh]
  int v95; // [esp+1BCh] [ebp-3D8h]
  int v96; // [esp+1C0h] [ebp-3D4h]
  int v97; // [esp+1C4h] [ebp-3D0h]
  int v98; // [esp+1C8h] [ebp-3CCh]
  int v99; // [esp+1CCh] [ebp-3C8h]
  int v100; // [esp+1D0h] [ebp-3C4h]
  int v101; // [esp+1D4h] [ebp-3C0h]
  int v102; // [esp+1D8h] [ebp-3BCh]
  int v103; // [esp+1DCh] [ebp-3B8h]
  int v104; // [esp+1E0h] [ebp-3B4h] BYREF
  int v105; // [esp+1E4h] [ebp-3B0h]
  int v106; // [esp+1E8h] [ebp-3ACh]
  int v107; // [esp+1ECh] [ebp-3A8h]
  CConfigManager *v108; // [esp+1F0h] [ebp-3A4h]
  int v109; // [esp+1F4h] [ebp-3A0h]
  int v110; // [esp+1F8h] [ebp-39Ch]
  int v111; // [esp+1FCh] [ebp-398h]
  int v112; // [esp+200h] [ebp-394h]
  int v113; // [esp+204h] [ebp-390h]
  int v114; // [esp+208h] [ebp-38Ch]
  int v115; // [esp+20Ch] [ebp-388h]
  _BYTE v116[16]; // [esp+210h] [ebp-384h] BYREF
  int v117; // [esp+220h] [ebp-374h]
  struct Document *v118; // [esp+224h] [ebp-370h]
  char *v119; // [esp+228h] [ebp-36Ch]
  int v120; // [esp+22Ch] [ebp-368h]
  struct Document *v121; // [esp+230h] [ebp-364h]
  int v122; // [esp+234h] [ebp-360h]
  bool v125; // [esp+23Ah] [ebp-35Ah]
  bool v126; // [esp+23Bh] [ebp-359h]
  char *v127; // [esp+23Ch] [ebp-358h]
  _BYTE v128[28]; // [esp+468h] [ebp-12Ch] BYREF
  _BYTE v129[28]; // [esp+484h] [ebp-110h] BYREF
  _BYTE v130[28]; // [esp+4A0h] [ebp-F4h] BYREF
  _BYTE v131[28]; // [esp+4BCh] [ebp-D8h] BYREF
  _BYTE v132[28]; // [esp+4D8h] [ebp-BCh] BYREF
  _BYTE v133[28]; // [esp+4F4h] [ebp-A0h] BYREF
  _BYTE v134[28]; // [esp+510h] [ebp-84h] BYREF
  _BYTE v135[28]; // [esp+52Ch] [ebp-68h] BYREF
  _BYTE v136[28]; // [esp+548h] [ebp-4Ch] BYREF
  _BYTE v137[28]; // [esp+564h] [ebp-30h] BYREF
  int *v138; // [esp+584h] [ebp-10h]
  int v139; // [esp+590h] [ebp-4h]

  v138 = &v18;
  v31 = this;
  v104 = 0;
  result = AdvXMLParser::Parser::OpenXMLFile(aGamedataVehicl, &v104);
  v119 = result;
  if ( !result )
    return result;
  v45 = CDefineTranslator::Instance();
  v121 = 0;
  v139 = 0;
  v37 = AdvXMLParser::Parser::Parser(v19);
  LOBYTE(v139) = 1;
  v54 = AdvXMLParser::Parser::Parse((AdvXMLParser::Parser *)v19, v119, v104);
  v121 = v54;
  if ( !v54 )
  {
    v53 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 471, "pDocument != 0");
    if ( v53 == 1 )
      __debugbreak();
  }
  Root = AdvXMLParser::Document::GetRoot(v121);
  v105 = Root;
  v51 = AdvXMLParser::NodeContainer::Begin(Root, v20);
  v50 = v51;
  LOBYTE(v139) = 2;
  v35 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v51);
  LOBYTE(v139) = 4;
  AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v20);
  v49 = AdvXMLParser::NodeContainer::End(v105, v23);
  v48 = v49;
  LOBYTE(v139) = 5;
  v34 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v49);
  LOBYTE(v139) = 7;
  AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v23);
  while ( (unsigned __int8)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v24) )
  {
    v47 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v42);
    v46 = AdvXMLParser::Element::operator[]("id");
    v106 = v46;
    v33 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v46 + 8))(v46, v129);
    LOBYTE(v139) = 8;
    ValueOfDefine = CDefineTranslator::GetValueOfDefine(v129);
    v120 = ValueOfDefine;
    if ( ValueOfDefine < 0 || v120 >= 5 )
    {
      v43 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 486, "(iRaceId >= 0) && (iRaceId < RACE_MAX)");
      if ( v43 == 1 )
        __debugbreak();
    }
    v102 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v42);
    v101 = AdvXMLParser::NodeContainer::Begin(v102, v22);
    v100 = v101;
    LOBYTE(v139) = 9;
    v32 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v101);
    LOBYTE(v139) = 11;
    AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v22);
    v99 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v42);
    v98 = AdvXMLParser::NodeContainer::End(v99, v21);
    v97 = v98;
    LOBYTE(v139) = 12;
    v36 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v98);
    LOBYTE(v139) = 14;
    AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v21);
    while ( (unsigned __int8)AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v25) )
    {
      v96 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v116);
      v95 = AdvXMLParser::Element::operator[]("id");
      v107 = v95;
      v30 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v95 + 8))(v95, v128);
      LOBYTE(v139) = 15;
      Instance = CConfigManagerPtr::GetInstance();
      v108 = Instance;
      v2 = std::string::c_str(v128);
      v93 = ((int (__thiscall *)(CConfigManager *, int))v108->j_?GetDefineValue@CConfigManager@@UAEHPBD@Z)(v108, v2);
      v122 = v93;
      if ( v93 <= 0 || v122 >= 6 )
      {
        v92 = BBSupportDbgReport(
                2,
                "MapObjects\\VehicleProperties.cpp",
                498,
                "(iVehicleType > VEHICLE_NO_VEHICLE) && (iVehicleType < VEHICLE_MAX)");
        if ( v92 == 1 )
          __debugbreak();
      }
      v125 = v122 == 4 || v122 == 1;
      v126 = v125;
      v127 = (char *)&IVehicleInfoMgr::m_sVehicleProperties + 552 * v120 + 92 * v122;
      if ( !v127[88] )
      {
        v91 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 504, "rProperties.m_bInitialized");
        if ( v91 == 1 )
          __debugbreak();
      }
      v90 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v116);
      v89 = AdvXMLParser::Element::operator()("Boards", 0);
      v109 = v89;
      v29 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v89 + 8))(v89, v133);
      LOBYTE(v139) = 16;
      if ( std::string::length(v133) )
      {
        v3 = (const char *)std::string::c_str(v133);
        v4 = j__atoi(v3);
        *(_DWORD *)v127 = v4;
        if ( *(_DWORD *)v127 > 0x10u )
        {
          v88 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 516, "rProperties.m_uBoards <= 16");
          if ( v88 == 1 )
            __debugbreak();
        }
      }
      LOBYTE(v139) = 15;
      std::string::~string(v133);
      v87 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v116);
      v86 = AdvXMLParser::Element::operator()("Ironbars", 0);
      v110 = v86;
      v28 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v86 + 8))(v86, v134);
      LOBYTE(v139) = 17;
      if ( std::string::length(v134) )
      {
        v5 = (const char *)std::string::c_str(v134);
        v6 = j__atoi(v5);
        *((_DWORD *)v127 + 1) = v6;
        if ( *((_DWORD *)v127 + 1) > 0x10u )
        {
          v85 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 530, "rProperties.m_uIronbars <= 16");
          if ( v85 == 1 )
            __debugbreak();
        }
      }
      LOBYTE(v139) = 15;
      std::string::~string(v134);
      if ( !(*((_DWORD *)v127 + 1) + *(_DWORD *)v127) )
      {
        v84 = BBSupportDbgReport(
                2,
                "MapObjects\\VehicleProperties.cpp",
                534,
                "(rProperties.m_uBoards + rProperties.m_uIronbars) > 0");
        if ( v84 == 1 )
          __debugbreak();
      }
      v83 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v116);
      v82 = AdvXMLParser::Element::operator()("Hitpoints", 0);
      v103 = v82;
      v27 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v82 + 8))(v82, v135);
      LOBYTE(v139) = 18;
      if ( std::string::length(v135) )
      {
        v7 = (const char *)std::string::c_str(v135);
        v8 = j__atoi(v7);
        *((_DWORD *)v127 + 12) = v8 / 2;
        if ( !*((_DWORD *)v127 + 12) )
        {
          v81 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 545, "rProperties.m_uHitpoints > 0");
          if ( v81 == 1 )
            __debugbreak();
        }
        if ( *((_DWORD *)v127 + 12) >= 0x100u )
        {
          v80 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 546, "rProperties.m_uHitpoints < 256");
          if ( v80 == 1 )
            __debugbreak();
        }
      }
      LOBYTE(v139) = 15;
      std::string::~string(v135);
      v79 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v116);
      v78 = AdvXMLParser::Element::operator()("Armor", 0);
      v115 = v78;
      v26 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v78 + 8))(v78, v136);
      LOBYTE(v139) = 19;
      if ( std::string::length(v136) )
      {
        v9 = (const char *)std::string::c_str(v136);
        v10 = j__atoi(v9);
        *((_DWORD *)v127 + 13) = v10;
        if ( *((_DWORD *)v127 + 13) >= 0x100u )
        {
          v77 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 560, "rProperties.m_uArmor < 256");
          if ( v77 == 1 )
            __debugbreak();
        }
      }
      LOBYTE(v139) = 15;
      std::string::~string(v136);
      v76 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v116);
      v75 = AdvXMLParser::Element::operator()("Damage", 0);
      v114 = v75;
      v41 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v75 + 8))(v75, v137);
      LOBYTE(v139) = 20;
      if ( std::string::length(v137) )
      {
        v11 = (const char *)std::string::c_str(v137);
        v12 = j__atoi(v11);
        *((_DWORD *)v127 + 14) = v12;
        if ( v126 )
        {
          if ( !*((_DWORD *)v127 + 14) )
          {
            v74 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 575, "rProperties.m_uDamage > 0");
            if ( v74 == 1 )
              __debugbreak();
          }
          if ( *((_DWORD *)v127 + 14) >= 0x100u )
          {
            v73 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 576, "rProperties.m_uDamage < 256");
            if ( v73 == 1 )
              __debugbreak();
          }
        }
        else if ( *((_DWORD *)v127 + 14) )
        {
          v72 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 580, "rProperties.m_uDamage == 0");
          if ( v72 == 1 )
            __debugbreak();
        }
      }
      LOBYTE(v139) = 15;
      std::string::~string(v137);
      v71 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v116);
      v70 = AdvXMLParser::Element::operator()("ReadyToFireDelay", 0);
      v113 = v70;
      v40 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v70 + 8))(v70, v130);
      LOBYTE(v139) = 21;
      if ( std::string::length(v130) )
      {
        v13 = (const char *)std::string::c_str(v130);
        v14 = j__atoi(v13);
        *((_DWORD *)v127 + 19) = v14;
        if ( v126 )
        {
          if ( !*((_DWORD *)v127 + 19) )
          {
            v69 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 596, "rProperties.m_uReadyToFireDelay > 0");
            if ( v69 == 1 )
              __debugbreak();
          }
          if ( *((_DWORD *)v127 + 19) >= 0x100u )
          {
            v68 = BBSupportDbgReport(
                    2,
                    "MapObjects\\VehicleProperties.cpp",
                    597,
                    "rProperties.m_uReadyToFireDelay < 256");
            if ( v68 == 1 )
              __debugbreak();
          }
        }
        else if ( *((_DWORD *)v127 + 19) )
        {
          v67 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 601, "rProperties.m_uReadyToFireDelay == 0");
          if ( v67 == 1 )
            __debugbreak();
        }
      }
      LOBYTE(v139) = 15;
      std::string::~string(v130);
      v66 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v116);
      v65 = AdvXMLParser::Element::operator()("MaxAmmo", 0);
      v112 = v65;
      v39 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v65 + 8))(v65, v131);
      LOBYTE(v139) = 22;
      if ( std::string::length(v131) )
      {
        v15 = (const char *)std::string::c_str(v131);
        v16 = j__atoi(v15);
        *((_DWORD *)v127 + 21) = v16;
        if ( v126 )
        {
          if ( !*((_DWORD *)v127 + 21) )
          {
            v64 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 617, "rProperties.m_uMaxAmmo > 0");
            if ( v64 == 1 )
              __debugbreak();
          }
          if ( *((_DWORD *)v127 + 21) >= 0x100u )
          {
            v63 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 618, "rProperties.m_uMaxAmmo < 256");
            if ( v63 == 1 )
              __debugbreak();
          }
        }
        else if ( *((_DWORD *)v127 + 21) )
        {
          v62 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 622, "rProperties.m_uMaxAmmo == 0");
          if ( v62 == 1 )
            __debugbreak();
        }
      }
      LOBYTE(v139) = 15;
      std::string::~string(v131);
      v61 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v116);
      v60 = AdvXMLParser::Element::operator()("WalkSteps", 0);
      v111 = v60;
      v38 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v60 + 8))(v60, v132);
      LOBYTE(v139) = 23;
      if ( std::string::length(v132) )
      {
        v17 = (const char *)std::string::c_str(v132);
        v117 = j__atoi(v17);
        if ( v117 <= 0 )
        {
          v59 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 636, "iWalkSteps > 0");
          if ( v59 == 1 )
            __debugbreak();
        }
        if ( v117 > 16 )
        {
          v58 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 637, "iWalkSteps <= 16");
          if ( v58 == 1 )
            __debugbreak();
        }
        *((_DWORD *)v127 + 11) = v117;
      }
      LOBYTE(v139) = 15;
      std::string::~string(v132);
      LOBYTE(v139) = 14;
      std::string::~string(v128);
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v116);
    }
    LOBYTE(v139) = 11;
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v25);
    LOBYTE(v139) = 8;
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v116);
    LOBYTE(v139) = 7;
    std::string::~string(v129);
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v42);
  }
  LOBYTE(v139) = 4;
  AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v24);
  LOBYTE(v139) = 1;
  AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>((CDaoIndexFieldInfo *)v42);
  LOBYTE(v139) = 0;
  AdvXMLParser::Parser::~Parser(v19);
  v139 = -1;
  if ( v121 )
  {
    v57 = v121;
    v118 = v121;
    v56 = ((int (__thiscall *)(struct Document *, int))v118->lpVtbl->QueryInterface)(v118, 1);
  }
  C = v119;
  return (char *)operator delete[](v119);
}


