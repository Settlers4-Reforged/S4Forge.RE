#include "CVehicleInfoMgr.h"

// Definitions for class CVehicleInfoMgr

// address=[0x15aae80]
// Decompiled from void __thiscall CVehicleInfoMgr::InitializeVehicleProperties(CVehicleInfoMgr *this, bool a2, bool _bKeepData)
void  CVehicleInfoMgr::InitializeVehicleProperties(bool a2, bool _bKeepData) {
  
  SVehicleProperties *v3; // eax
  unsigned int uRace; // [esp+Ch] [ebp-10h]
  unsigned int uType; // [esp+10h] [ebp-Ch]
  SVehicleDefinition *i; // [esp+18h] [ebp-4h]

  if ( a2 || !IVehicleInfoMgr::m_bInitialized )
  {
    IVehicleInfoMgr::m_bInitialized = 1;
    memset(IVehicleInfoMgr::m_sVehicleProperties, 0, sizeof(IVehicleInfoMgr::m_sVehicleProperties));
    for ( i = IVehicleInfoMgr::m_sVehicleDefinitions; i->m_pProperty; ++i )
    {
      uRace = i->m_uType;
      uType = i->m_uRace;
      if ( uRace >= 5 && BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 420, "uRace < RACE_MAX") == 1 )
        __debugbreak();
      if ( uType >= 6 && BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 421, "uType < VEHICLE_MAX") == 1 )
        __debugbreak();
      qmemcpy(
        (void *)&IVehicleInfoMgr::m_sVehicleProperties[uRace][uType],
        i->m_pProperty,
        sizeof(IVehicleInfoMgr::m_sVehicleProperties[uRace][uType]));
      v3 = &IVehicleInfoMgr::m_sVehicleProperties[uRace][uType];
      v3->m_bInitialized = 1;
      if ( v3->m_tVehicleType != uType
        && BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 428, "rProperties.m_tVehicleType == uType") == 1 )
      {
        __debugbreak();
      }
    }
    if ( !_bKeepData )
      CVehicleInfoMgr::ReadXMLFile(this);
  }
}


// address=[0x15ac350]
// Decompiled from CVehicleInfoMgr *__thiscall CVehicleInfoMgr::CVehicleInfoMgr(CVehicleInfoMgr *this)
 CVehicleInfoMgr::CVehicleInfoMgr(void) {
  
  IVehicleInfoMgr::IVehicleInfoMgr((IVehicleInfoMgr *)this);
  this->__vftable = (CVehicleInfoMgr_vtbl *)&CVehicleInfoMgr::_vftable_;
  return this;
}


// address=[0x15aafc0]
// Decompiled from void __thiscall CVehicleInfoMgr::ReadXMLFile(CVehicleInfoMgr *this)
void  CVehicleInfoMgr::ReadXMLFile(void) {
  
  char *v1; // eax
  char *v2; // eax
  int v3; // eax
  char *v4; // eax
  int v5; // eax
  char *v6; // eax
  int v7; // eax
  char *v8; // eax
  int v9; // eax
  char *v10; // eax
  int v11; // eax
  char *v12; // eax
  int v13; // eax
  char *v14; // eax
  int v15; // eax
  char *v16; // eax
  int v17; // [esp+0h] [ebp-594h] BYREF
  _BYTE v18[28]; // [esp+10h] [ebp-584h] BYREF
  _BYTE v19[16]; // [esp+2Ch] [ebp-568h] BYREF
  _DWORD v20[4]; // [esp+3Ch] [ebp-558h] BYREF
  _BYTE v21[16]; // [esp+4Ch] [ebp-548h] BYREF
  _DWORD v22[4]; // [esp+5Ch] [ebp-538h] BYREF
  _DWORD v23[4]; // [esp+6Ch] [ebp-528h] BYREF
  int v24[4]; // [esp+7Ch] [ebp-518h] BYREF
  std::string *v25; // [esp+8Ch] [ebp-508h]
  std::string *v26; // [esp+90h] [ebp-504h]
  std::string *v27; // [esp+94h] [ebp-500h]
  std::string *v28; // [esp+98h] [ebp-4FCh]
  int v29; // [esp+9Ch] [ebp-4F8h]
  _DWORD *v31; // [esp+A4h] [ebp-4F0h]
  int v32; // [esp+A8h] [ebp-4ECh]
  _DWORD *v33; // [esp+ACh] [ebp-4E8h]
  _DWORD *v34; // [esp+B0h] [ebp-4E4h]
  _DWORD *v35; // [esp+B4h] [ebp-4E0h]
  int v36; // [esp+B8h] [ebp-4DCh]
  std::string *v37; // [esp+C0h] [ebp-4D4h]
  std::string *v38; // [esp+C4h] [ebp-4D0h]
  std::string *v39; // [esp+C8h] [ebp-4CCh]
  std::string *v40; // [esp+CCh] [ebp-4C8h]
  char v41[16]; // [esp+D0h] [ebp-4C4h] BYREF
  int v42; // [esp+E0h] [ebp-4B4h]
  int iRaceId; // [esp+E4h] [ebp-4B0h] MAPDST
  struct CDefineTranslator *v44; // [esp+E8h] [ebp-4ACh]
  const struct AdvXMLParser::Attribute *v45; // [esp+ECh] [ebp-4A8h]
  AdvXMLParser::Element *v46; // [esp+F0h] [ebp-4A4h]
  _DWORD *v47; // [esp+F4h] [ebp-4A0h]
  _DWORD *v48; // [esp+F8h] [ebp-49Ch]
  _DWORD *v49; // [esp+FCh] [ebp-498h]
  _DWORD *v50; // [esp+100h] [ebp-494h]
  void *Root; // [esp+104h] [ebp-490h]
  int v52; // [esp+108h] [ebp-48Ch]
  int pDocument; // [esp+10Ch] [ebp-488h] MAPDST
  void *C; // [esp+110h] [ebp-484h]
  int v55; // [esp+114h] [ebp-480h]
  int v56; // [esp+118h] [ebp-47Ch]
  int v57; // [esp+11Ch] [ebp-478h]
  int v58; // [esp+120h] [ebp-474h]
  AdvXMLParser::Element *v59; // [esp+124h] [ebp-470h]
  AdvXMLParser::Element *v60; // [esp+128h] [ebp-46Ch]
  int v61; // [esp+12Ch] [ebp-468h]
  int v62; // [esp+130h] [ebp-464h]
  int v63; // [esp+134h] [ebp-460h]
  AdvXMLParser::Element *v64; // [esp+138h] [ebp-45Ch]
  AdvXMLParser::Element *v65; // [esp+13Ch] [ebp-458h]
  int v66; // [esp+140h] [ebp-454h]
  int v67; // [esp+144h] [ebp-450h]
  int v68; // [esp+148h] [ebp-44Ch]
  AdvXMLParser::Element *v69; // [esp+14Ch] [ebp-448h]
  AdvXMLParser::Element *v70; // [esp+150h] [ebp-444h]
  int v71; // [esp+154h] [ebp-440h]
  int v72; // [esp+158h] [ebp-43Ch]
  int v73; // [esp+15Ch] [ebp-438h]
  AdvXMLParser::Element *v74; // [esp+160h] [ebp-434h]
  AdvXMLParser::Element *v75; // [esp+164h] [ebp-430h]
  int v76; // [esp+168h] [ebp-42Ch]
  AdvXMLParser::Element *v77; // [esp+170h] [ebp-424h]
  AdvXMLParser::Element *v78; // [esp+174h] [ebp-420h]
  int v79; // [esp+178h] [ebp-41Ch]
  int v80; // [esp+17Ch] [ebp-418h]
  AdvXMLParser::Element *v81; // [esp+180h] [ebp-414h]
  AdvXMLParser::Element *v82; // [esp+184h] [ebp-410h]
  int v83; // [esp+188h] [ebp-40Ch]
  int v84; // [esp+18Ch] [ebp-408h]
  AdvXMLParser::Element *v85; // [esp+194h] [ebp-400h]
  AdvXMLParser::Element *v86; // [esp+198h] [ebp-3FCh]
  int v87; // [esp+19Ch] [ebp-3F8h]
  AdvXMLParser::Element *v88; // [esp+1A4h] [ebp-3F0h]
  AdvXMLParser::Element *v89; // [esp+1A8h] [ebp-3ECh]
  int v90; // [esp+1ACh] [ebp-3E8h]
  int v91; // [esp+1B0h] [ebp-3E4h]
  int iVehicleType; // [esp+1B4h] [ebp-3E0h] MAPDST
  CConfigManager *Instance; // [esp+1B8h] [ebp-3DCh]
  const struct AdvXMLParser::Attribute *v94; // [esp+1BCh] [ebp-3D8h]
  AdvXMLParser::Element *v95; // [esp+1C0h] [ebp-3D4h]
  _DWORD *v96; // [esp+1C4h] [ebp-3D0h]
  _DWORD *v97; // [esp+1C8h] [ebp-3CCh]
  AdvXMLParser::Element *v98; // [esp+1CCh] [ebp-3C8h]
  _DWORD *v99; // [esp+1D0h] [ebp-3C4h]
  _DWORD *v100; // [esp+1D4h] [ebp-3C0h]
  AdvXMLParser::Element *v101; // [esp+1D8h] [ebp-3BCh]
  AdvXMLParser::Element *v102; // [esp+1DCh] [ebp-3B8h]
  int v103; // [esp+1E0h] [ebp-3B4h] BYREF
  void *v104; // [esp+1E4h] [ebp-3B0h]
  const struct AdvXMLParser::Attribute *v105; // [esp+1E8h] [ebp-3ACh]
  const struct AdvXMLParser::Attribute *v106; // [esp+1ECh] [ebp-3A8h]
  CConfigManager *v107; // [esp+1F0h] [ebp-3A4h]
  AdvXMLParser::Element *v108; // [esp+1F4h] [ebp-3A0h]
  AdvXMLParser::Element *v109; // [esp+1F8h] [ebp-39Ch]
  AdvXMLParser::Element *v110; // [esp+1FCh] [ebp-398h]
  AdvXMLParser::Element *v111; // [esp+200h] [ebp-394h]
  AdvXMLParser::Element *v112; // [esp+204h] [ebp-390h]
  AdvXMLParser::Element *v113; // [esp+208h] [ebp-38Ch]
  AdvXMLParser::Element *v114; // [esp+20Ch] [ebp-388h]
  char v115[16]; // [esp+210h] [ebp-384h] BYREF
  int iWalkSteps; // [esp+220h] [ebp-374h]
  int (__thiscall ***v117)(_DWORD, int); // [esp+224h] [ebp-370h]
  char *v118; // [esp+228h] [ebp-36Ch]
  bool bIsAttackVehicle; // [esp+23Ah] [ebp-35Ah] MAPDST
  SVehicleProperties *rProperties; // [esp+23Ch] [ebp-358h]
  std::string v127; // [esp+468h] [ebp-12Ch] BYREF
  struct std::string v128; // [esp+484h] [ebp-110h] BYREF
  std::string v129; // [esp+4A0h] [ebp-F4h] BYREF
  std::string v130; // [esp+4BCh] [ebp-D8h] BYREF
  std::string v131; // [esp+4D8h] [ebp-BCh] BYREF
  std::string v132; // [esp+4F4h] [ebp-A0h] BYREF
  std::string v133; // [esp+510h] [ebp-84h] BYREF
  std::string v134; // [esp+52Ch] [ebp-68h] BYREF
  std::string v135; // [esp+548h] [ebp-4Ch] BYREF
  std::string v136; // [esp+564h] [ebp-30h] BYREF
  int *v137; // [esp+584h] [ebp-10h]
  int exceptionBlock; // [esp+590h] [ebp-4h]

  v137 = &v17;
  v103 = 0;
  v118 = (char *)AdvXMLParser::Parser::OpenXMLFile(aGamedataVehicl, &v103);
  if ( v118 )
  {
    v44 = (struct CDefineTranslator *)CDefineTranslator::Instance();
    pDocument = 0;
    exceptionBlock = 0;
    v36 = AdvXMLParser::Parser::Parser(v18);
    LOBYTE(exceptionBlock) = 1;
    pDocument = AdvXMLParser::Parser::Parse((AdvXMLParser::Parser *)v18, v118, v103);
    if ( !pDocument )
    {
      v52 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 471, "pDocument != 0");
      if ( v52 == 1 )
        __debugbreak();
    }
    Root = (void *)AdvXMLParser::Document::GetRoot(pDocument);
    v104 = Root;
    v50 = (_DWORD *)AdvXMLParser::NodeContainer::Begin(Root, v19);
    v49 = v50;
    LOBYTE(exceptionBlock) = 2;
    v34 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v41, v50);
    LOBYTE(exceptionBlock) = 4;
    AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v19);
    v48 = AdvXMLParser::NodeContainer::End(v104, v22);
    v47 = v48;
    LOBYTE(exceptionBlock) = 5;
    v33 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v23, v48);
    LOBYTE(exceptionBlock) = 7;
    AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v22);
    while ( AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v41, (int)v23) )
    {
      v46 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v41);
      v45 = AdvXMLParser::Element::operator[](v46, "id");
      v105 = v45;
      v32 = v45->GetValue(v45, &v128);
      LOBYTE(exceptionBlock) = 8;
      iRaceId = CDefineTranslator::GetValueOfDefine(v44, &v128);
      if ( iRaceId < 0 || iRaceId >= 5 )
      {
        v42 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 486, "(iRaceId >= 0) && (iRaceId < RACE_MAX)");
        if ( v42 == 1 )
          __debugbreak();
      }
      v101 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v41);
      v100 = (_DWORD *)AdvXMLParser::NodeContainer::Begin(v101, v21);
      v99 = v100;
      LOBYTE(exceptionBlock) = 9;
      v31 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v115, v100);
      LOBYTE(exceptionBlock) = 11;
      AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v21);
      v98 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v41);
      v97 = AdvXMLParser::NodeContainer::End(v98, v20);
      v96 = v97;
      LOBYTE(exceptionBlock) = 12;
      v35 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(v24, v97);
      LOBYTE(exceptionBlock) = 14;
      AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef((CDaoIndexFieldInfo *)v20);
      while ( AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(v115, (int)v24) )
      {
        v95 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v115);
        v94 = AdvXMLParser::Element::operator[](v95, "id");
        v106 = v94;
        v29 = v94->GetValue(v94, &v127);
        LOBYTE(exceptionBlock) = 15;
        Instance = CConfigManagerPtr::GetInstance();
        v107 = Instance;
        v1 = std::string::c_str(&v127);
        iVehicleType = v107->GetDefineValue(v107, v1);
        if ( iVehicleType <= 0 || iVehicleType >= 6 )
        {
          v91 = BBSupportDbgReport(
                  2,
                  "MapObjects\\VehicleProperties.cpp",
                  498,
                  "(iVehicleType > VEHICLE_NO_VEHICLE) && (iVehicleType < VEHICLE_MAX)");
          if ( v91 == 1 )
            __debugbreak();
        }
        bIsAttackVehicle = iVehicleType == 4 || iVehicleType == 1;
        rProperties = &IVehicleInfoMgr::m_sVehicleProperties[iRaceId][iVehicleType];
        if ( !rProperties->m_bInitialized )
        {
          v90 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 504, "rProperties.m_bInitialized");
          if ( v90 == 1 )
            __debugbreak();
        }
        v89 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v115);
        v88 = AdvXMLParser::Element::operator()(v89, "Boards", 0);
        v108 = v88;
        v28 = v88->GetValue(v88);
        LOBYTE(exceptionBlock) = 16;
        if ( std::string::length(&v132) )
        {
          v2 = std::string::c_str(&v132);
          v3 = j__atoi(v2);
          rProperties->m_uBoards = v3;
          if ( rProperties->m_uBoards > 16u )
          {
            v87 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 516, "rProperties.m_uBoards <= 16");
            if ( v87 == 1 )
              __debugbreak();
          }
        }
        LOBYTE(exceptionBlock) = 15;
        std::string::~string(&v132);
        v86 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v115);
        v85 = AdvXMLParser::Element::operator()(v86, "Ironbars", 0);
        v109 = v85;
        v27 = v85->GetValue(v85);
        LOBYTE(exceptionBlock) = 17;
        if ( std::string::length(&v133) )
        {
          v4 = std::string::c_str(&v133);
          v5 = j__atoi(v4);
          rProperties->m_uIronbars = v5;
          if ( rProperties->m_uIronbars > 0x10u )
          {
            v84 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 530, "rProperties.m_uIronbars <= 16");
            if ( v84 == 1 )
              __debugbreak();
          }
        }
        LOBYTE(exceptionBlock) = 15;
        std::string::~string(&v133);
        if ( !(rProperties->m_uIronbars + rProperties->m_uBoards) )
        {
          v83 = BBSupportDbgReport(
                  2,
                  "MapObjects\\VehicleProperties.cpp",
                  534,
                  "(rProperties.m_uBoards + rProperties.m_uIronbars) > 0");
          if ( v83 == 1 )
            __debugbreak();
        }
        v82 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v115);
        v81 = AdvXMLParser::Element::operator()(v82, "Hitpoints", 0);
        v102 = v81;
        v26 = v81->GetValue(v81);
        LOBYTE(exceptionBlock) = 18;
        if ( std::string::length(&v134) )
        {
          v6 = std::string::c_str(&v134);
          v7 = j__atoi(v6);
          rProperties->m_uHitpoints = v7 / 2;
          if ( !rProperties->m_uHitpoints )
          {
            v80 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 545, "rProperties.m_uHitpoints > 0");
            if ( v80 == 1 )
              __debugbreak();
          }
          if ( rProperties->m_uHitpoints >= 0x100u )
          {
            v79 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 546, "rProperties.m_uHitpoints < 256");
            if ( v79 == 1 )
              __debugbreak();
          }
        }
        LOBYTE(exceptionBlock) = 15;
        std::string::~string(&v134);
        v78 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v115);
        v77 = AdvXMLParser::Element::operator()(v78, "Armor", 0);
        v114 = v77;
        v25 = v77->GetValue(v77);
        LOBYTE(exceptionBlock) = 19;
        if ( std::string::length(&v135) )
        {
          v8 = std::string::c_str(&v135);
          v9 = j__atoi(v8);
          rProperties->m_uArmor = v9;
          if ( rProperties->m_uArmor >= 0x100u )
          {
            v76 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 560, "rProperties.m_uArmor < 256");
            if ( v76 == 1 )
              __debugbreak();
          }
        }
        LOBYTE(exceptionBlock) = 15;
        std::string::~string(&v135);
        v75 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v115);
        v74 = AdvXMLParser::Element::operator()(v75, "Damage", 0);
        v113 = v74;
        v40 = v74->GetValue(v74);
        LOBYTE(exceptionBlock) = 20;
        if ( std::string::length(&v136) )
        {
          v10 = std::string::c_str(&v136);
          v11 = j__atoi(v10);
          rProperties->m_uDamage = v11;
          if ( bIsAttackVehicle )
          {
            if ( !rProperties->m_uDamage )
            {
              v73 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 575, "rProperties.m_uDamage > 0");
              if ( v73 == 1 )
                __debugbreak();
            }
            if ( rProperties->m_uDamage >= 0x100u )
            {
              v72 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 576, "rProperties.m_uDamage < 256");
              if ( v72 == 1 )
                __debugbreak();
            }
          }
          else if ( rProperties->m_uDamage )
          {
            v71 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 580, "rProperties.m_uDamage == 0");
            if ( v71 == 1 )
              __debugbreak();
          }
        }
        LOBYTE(exceptionBlock) = 15;
        std::string::~string(&v136);
        v70 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v115);
        v69 = AdvXMLParser::Element::operator()(v70, "ReadyToFireDelay", 0);
        v112 = v69;
        v39 = v69->GetValue(v69);
        LOBYTE(exceptionBlock) = 21;
        if ( std::string::length(&v129) )
        {
          v12 = std::string::c_str(&v129);
          v13 = j__atoi(v12);
          rProperties->m_uReadyToFireDelay = v13;
          if ( bIsAttackVehicle )
          {
            if ( !rProperties->m_uReadyToFireDelay )
            {
              v68 = BBSupportDbgReport(
                      2,
                      "MapObjects\\VehicleProperties.cpp",
                      596,
                      "rProperties.m_uReadyToFireDelay > 0");
              if ( v68 == 1 )
                __debugbreak();
            }
            if ( rProperties->m_uReadyToFireDelay >= 0x100u )
            {
              v67 = BBSupportDbgReport(
                      2,
                      "MapObjects\\VehicleProperties.cpp",
                      597,
                      "rProperties.m_uReadyToFireDelay < 256");
              if ( v67 == 1 )
                __debugbreak();
            }
          }
          else if ( rProperties->m_uReadyToFireDelay )
          {
            v66 = BBSupportDbgReport(
                    2,
                    "MapObjects\\VehicleProperties.cpp",
                    601,
                    "rProperties.m_uReadyToFireDelay == 0");
            if ( v66 == 1 )
              __debugbreak();
          }
        }
        LOBYTE(exceptionBlock) = 15;
        std::string::~string(&v129);
        v65 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v115);
        v64 = AdvXMLParser::Element::operator()(v65, "MaxAmmo", 0);
        v111 = v64;
        v38 = v64->GetValue(v64);
        LOBYTE(exceptionBlock) = 22;
        if ( std::string::length(&v130) )
        {
          v14 = std::string::c_str(&v130);
          v15 = j__atoi(v14);
          rProperties->m_uMaxAmmo = v15;
          if ( bIsAttackVehicle )
          {
            if ( !rProperties->m_uMaxAmmo )
            {
              v63 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 617, "rProperties.m_uMaxAmmo > 0");
              if ( v63 == 1 )
                __debugbreak();
            }
            if ( rProperties->m_uMaxAmmo >= 0x100u )
            {
              v62 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 618, "rProperties.m_uMaxAmmo < 256");
              if ( v62 == 1 )
                __debugbreak();
            }
          }
          else if ( rProperties->m_uMaxAmmo )
          {
            v61 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 622, "rProperties.m_uMaxAmmo == 0");
            if ( v61 == 1 )
              __debugbreak();
          }
        }
        LOBYTE(exceptionBlock) = 15;
        std::string::~string(&v130);
        v60 = AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator*(v115);
        v59 = AdvXMLParser::Element::operator()(v60, "WalkSteps", 0);
        v110 = v59;
        v37 = v59->GetValue(v59);
        LOBYTE(exceptionBlock) = 23;
        if ( std::string::length(&v131) )
        {
          v16 = std::string::c_str(&v131);
          iWalkSteps = j__atoi(v16);
          if ( iWalkSteps <= 0 )
          {
            v58 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 636, "iWalkSteps > 0");
            if ( v58 == 1 )
              __debugbreak();
          }
          if ( iWalkSteps > 16 )
          {
            v57 = BBSupportDbgReport(2, "MapObjects\\VehicleProperties.cpp", 637, "iWalkSteps <= 16");
            if ( v57 == 1 )
              __debugbreak();
          }
          rProperties->m_iWalkSteps = iWalkSteps;
        }
        LOBYTE(exceptionBlock) = 15;
        std::string::~string(&v131);
        LOBYTE(exceptionBlock) = 14;
        std::string::~string(&v127);
        AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v115);
      }
      LOBYTE(exceptionBlock) = 11;
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>(v24);
      LOBYTE(exceptionBlock) = 8;
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>(v115);
      LOBYTE(exceptionBlock) = 7;
      std::string::~string(&v128);
      AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator++(v41);
    }
    LOBYTE(exceptionBlock) = 4;
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>(v23);
    LOBYTE(exceptionBlock) = 1;
    AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>(v41);
    LOBYTE(exceptionBlock) = 0;
    AdvXMLParser::Parser::~Parser(v18);
    exceptionBlock = -1;
    if ( pDocument )
    {
      v56 = pDocument;
      v117 = (int (__thiscall ***)(_DWORD, int))pDocument;
      v55 = (**v117)(v117, 1);
    }
    C = v118;
    operator delete[](v118);
  }
}


