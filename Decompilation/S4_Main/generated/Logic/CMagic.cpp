#include "CMagic.h"

// Definitions for class CMagic

// address=[0x146af50]
// Decompiled from void __cdecl CMagic::InitPlayerMagicData(int a1)
void __cdecl CMagic::InitPlayerMagicData(int a1) {
  
  type_info *v1; // eax
  int v2; // eax
  int v3; // [esp+0h] [ebp-Ch]
  CPlayerMagicData *v4; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  if ( CPlayerManager::ValidUsedPlayerId(a1) )
  {
    v1 = CPlayerManager::PlayerGameData(a1);
    v4 = (CPlayerMagicData *)CPlayerGameData::MagicData(v1);
    CPlayerMagicData::Clear(v4);
    CPlayerMagicData::SetManaAmountChangedFlag(v4);
    v3 = sub_146C560(a1);
    if ( (unsigned __int8)sub_146C530(v3) )
    {
      for ( i = 0; i < 8; ++i )
      {
        v2 = sub_146C580(v3, i);
        CPlayerMagicData::SetSpellCategoryCost(v4, i, v2);
      }
    }
  }
  else if ( BBSupportDbgReport(1, "Logic\\Magic.cpp", 2860, "CMagic::ResetSpellCategoryCosts(): Invalid player id!") == 1 )
  {
    __debugbreak();
  }
}


// address=[0x146b040]
// Decompiled from int CMagic::InitMagicData()
void __cdecl CMagic::InitMagicData(void) {
  
  int result; // eax
  int v1; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  result = CPlayerManager::LastPlayerId();
  v1 = result;
  for ( i = 1; i <= v1; ++i )
  {
    CMagic::InitPlayerMagicData(i);
    result = i + 1;
  }
  return result;
}


// address=[0x146b080]
// Decompiled from int __cdecl CMagic::CastSpell(int a1, int a2, unsigned int a3, unsigned int a4, unsigned int a5, int a6)
int __cdecl CMagic::CastSpell(int a1, int a2, int a3, int a4, int a5, int a6) {
  
  type_info *v6; // eax
  _DWORD *v8; // eax
  int v9; // eax
  void *v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // [esp-10h] [ebp-74h]
  int v14; // [esp-Ch] [ebp-70h]
  _BYTE v15[36]; // [esp+0h] [ebp-64h] BYREF
  int v16; // [esp+24h] [ebp-40h]
  int v17; // [esp+28h] [ebp-3Ch]
  int v18; // [esp+2Ch] [ebp-38h]
  int v19; // [esp+30h] [ebp-34h]
  int SpellRange; // [esp+34h] [ebp-30h]
  int v21; // [esp+38h] [ebp-2Ch]
  int v22; // [esp+3Ch] [ebp-28h]
  BOOL v23; // [esp+40h] [ebp-24h]
  BOOL v24; // [esp+44h] [ebp-20h]
  int v25; // [esp+48h] [ebp-1Ch]
  int v26; // [esp+4Ch] [ebp-18h]
  int v27; // [esp+50h] [ebp-14h]
  int v28; // [esp+54h] [ebp-10h]
  CPlayerMagicData *v29; // [esp+58h] [ebp-Ch]
  unsigned __int8 *v30; // [esp+5Ch] [ebp-8h]
  int v31; // [esp+60h] [ebp-4h]

  if ( !CPlayerManager::ValidUsedPlayerId(a1) )
  {
    if ( BBSupportDbgReport(1, "Logic\\Magic.cpp", 3036, "CMagic::CastSpell(): Invalid player id!") == 1 )
      __debugbreak();
    return 0;
  }
  if ( !(unsigned __int8)sub_146C500(a2) )
  {
    if ( BBSupportDbgReport(1, "Logic\\Magic.cpp", 3031, "CMagic::CastSpell(): Invalid spell category!") == 1 )
      __debugbreak();
    return 0;
  }
  v31 = sub_146C560(a1);
  if ( (a5 & 0x8000000) != 0 )
  {
    v31 = (int)(a5 & 0x7000000) >> 24;
    a5 = a5 & 0xEFFFFFF8 | 5;
    a6 = 0;
  }
  if ( !(unsigned __int8)sub_146C530(v31) )
  {
    if ( BBSupportDbgReport(1, "Logic\\Magic.cpp", 3025, "CMagic::CastSpell(): Invalid race!") == 1 )
      __debugbreak();
    return 0;
  }
  v6 = CPlayerManager::PlayerGameData(a1);
  v29 = (CPlayerMagicData *)CPlayerGameData::MagicData(v6);
  v26 = CPlayerMagicData::ManaAmount(v29);
  v28 = CPlayerMagicData::SpellCategoryCost(v29, a2);
  if ( v26 < 0 && BBSupportDbgReport(2, "Logic\\Magic.cpp", 2908, "iCurMana >= 0") == 1 )
    __debugbreak();
  if ( v28 < 1 && BBSupportDbgReport(2, "Logic\\Magic.cpp", 2909, "iCurCost >= MAGIC_COST_MIN") == 1 )
    __debugbreak();
  if ( v28 > 1000 && BBSupportDbgReport(2, "Logic\\Magic.cpp", 2910, "iCurCost <= MAGIC_COST_MAX") == 1 )
    __debugbreak();
  v25 = sub_146C710(v28, a5);
  if ( v26 < v25 )
    return -1;
  if ( !(unsigned __int8)CWorldManager::InWorld(a3, a4) )
  {
    if ( BBSupportDbgReport(1, "Logic\\Magic.cpp", 3020, "CMagic::CastSpell(): Invalid destination!") == 1 )
      __debugbreak();
    return 0;
  }
  v24 = a6 > 0;
  v23 = (a5 & 4) == 0;
  if ( !v23 || !v24 )
    goto LABEL_32;
  v30 = (unsigned __int8 *)CMapObjectMgr::Entity(a6);
  if ( IEntity::ObjType(v30) != 1
    && BBSupportDbgReport(2, "Logic\\Magic.cpp", 2927, "rPriestEntity.ObjType() == SETTLER_OBJ") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::WarriorType() != 6
    && (IEntity::WarriorType() != 4 || IEntity::Race(v30) != 3)
    && BBSupportDbgReport(
         2,
         "Logic\\Magic.cpp",
         2933,
         "rPriestEntity.WarriorType() == WARRIOR_TYPE_PRIEST || ( rPriestEntity.WarriorType() == WARRIOR_TYPE_FIGHTER_UNI"
         "QUE && rPriestEntity.Race() == RACE_DARK )") == 1 )
  {
    __debugbreak();
  }
  v21 = IEntity::X(v30);
  v22 = IEntity::Y(v30);
  if ( !(unsigned __int8)CWorldManager::InWorld(v21, v22)
    && BBSupportDbgReport(2, "Logic\\Magic.cpp", 2938, "g_cWorld.InWorld(iPriestX, iPriestY)") == 1 )
  {
    __debugbreak();
  }
  v19 = Grid::Distance((Grid *)(a3 - v21), a4 - v22);
  SpellRange = CMagic::MagicGetSpellRange(v31, a2);
  if ( SpellRange < v19 )
    return 0;
LABEL_32:
  v27 = 0;
  if ( (a5 & 0x10000000) != 0 )
  {
    v10 = (void *)CLogic::FutureEvents(g_pLogic);
    IFutureEvents::AddFutureEvent16(v10, 3, 12, a6, a1 | (a2 << 8), a3, a4, (unsigned __int16)a5);
    v27 = 1;
  }
  else
  {
    v14 = sub_146C8C0(v31, a2);
    v13 = sub_146C7D0(v31, a2);
    v8 = (_DWORD *)TStaticConfigIntArrayBase<8>::operator[](a2);
    v9 = sub_146C4C0(*v8, 0, 30);
    CMagicSpell::CMagicSpell((CMagicSpell *)v15, a1, v31, a3, a4, v9, v13, v14, a5, a6);
    v27 = CMagicSpell::CastSpell((CMagicSpell *)v15, v31, a2);
  }
  if ( !v27 )
    return 0;
  if ( v25 > 0 )
  {
    CPlayerMagicData::SetManaAmount(v29, v26 - v25);
    v17 = sub_146C620(a5);
    v18 = sub_146C670(v31, a2);
    v16 = sub_146C6B0(v28, v17, v18);
    CPlayerMagicData::SetSpellCategoryCost(v29, a2, v16);
  }
  v11 = CPlayerMagicData::SpellCategoryCounter(v29, a2);
  CPlayerMagicData::SetSpellCategoryCounter(v29, a2, v11 + 1);
  v12 = Y16X16::PackXYFast(a3, a4);
  (*(void (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(off_3D7A3D8, 1, a1, a2, v12);
  if ( g_pScriptMgr )
    CGameScriptManager::SendGameEvent((CGameScriptManager *)g_pScriptMgr, 0x16u, a1, a2, a3, a4);
  return 1;
}


// address=[0x146b580]
// Decompiled from int __cdecl CMagic::CheckManaForCastSpell(int a1, int a2, int a3)
int __cdecl CMagic::CheckManaForCastSpell(int a1, int a2, int a3) {
  
  type_info *v3; // eax
  CPlayerMagicData *v4; // eax
  type_info *v5; // eax
  CPlayerMagicData *v6; // eax
  int v7; // eax
  int v9; // [esp+8h] [ebp-8h]

  if ( !CAlliances::IsValidUsedPlayerId(a1)
    && BBSupportDbgReport(2, "Logic\\Magic.cpp", 3052, "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)sub_146C500(a2)
    && BBSupportDbgReport(2, "Logic\\Magic.cpp", 3053, "MagicIsValidSpellCategory(_iSpellCategory)") == 1 )
  {
    __debugbreak();
  }
  v3 = CPlayerManager::PlayerGameData(a1);
  v4 = (CPlayerMagicData *)CPlayerGameData::MagicData(v3);
  v9 = CPlayerMagicData::ManaAmount(v4);
  v5 = CPlayerManager::PlayerGameData(a1);
  v6 = (CPlayerMagicData *)CPlayerGameData::MagicData(v5);
  v7 = CPlayerMagicData::SpellCategoryCost(v6, a2);
  return v9 - sub_146C710(v7, a3);
}


// address=[0x146b650]
// Decompiled from int __cdecl CMagic::GetSpellRange(int a1, int a2)
int __cdecl CMagic::GetSpellRange(int a1, int a2) {
  
  int v3; // [esp+4h] [ebp-4h]

  if ( !CAlliances::IsValidUsedPlayerId(a1)
    && BBSupportDbgReport(2, "Logic\\Magic.cpp", 3072, "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)sub_146C500(a2)
    && BBSupportDbgReport(2, "Logic\\Magic.cpp", 3073, "MagicIsValidSpellCategory(_iSpellCategory)") == 1 )
  {
    __debugbreak();
  }
  v3 = sub_146C560(a1);
  return CMagic::MagicGetSpellRange(v3, a2);
}


// address=[0x146b6f0]
// Decompiled from int __cdecl CMagic::GetCurrentManaAmount(int a1)
int __cdecl CMagic::GetCurrentManaAmount(int a1) {
  
  type_info *v1; // eax
  CPlayerMagicData *v2; // eax

  if ( !CAlliances::IsValidUsedPlayerId(a1)
    && BBSupportDbgReport(2, "Logic\\Magic.cpp", 3088, "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  v1 = CPlayerManager::PlayerGameData(a1);
  v2 = (CPlayerMagicData *)CPlayerGameData::MagicData(v1);
  return CPlayerMagicData::ManaAmount(v2);
}


// address=[0x146b750]
// Decompiled from int __cdecl CMagic::GetCurrentSpellCategoryCost(int a1, int a2)
int __cdecl CMagic::GetCurrentSpellCategoryCost(int a1, int a2) {
  
  type_info *v2; // eax
  CPlayerMagicData *v3; // eax
  int v5; // [esp+0h] [ebp-4h]

  v5 = 1;
  if ( CPlayerManager::ValidUsedPlayerId(a1) )
  {
    if ( (unsigned __int8)sub_146C500(a2) )
    {
      v2 = CPlayerManager::PlayerGameData(a1);
      v3 = (CPlayerMagicData *)CPlayerGameData::MagicData(v2);
      v5 = CPlayerMagicData::SpellCategoryCost(v3, a2);
      if ( v5 < 1 )
        return 1;
    }
    else if ( BBSupportDbgReport(
                1,
                "Logic\\Magic.cpp",
                3117,
                "CMagic::GetCurrentSpellCategoryCost(): Invalid spell category!") == 1 )
    {
      __debugbreak();
    }
  }
  else if ( BBSupportDbgReport(1, "Logic\\Magic.cpp", 3122, "CMagic::GetCurrentSpellCategoryCost(): Invalid player id!") == 1 )
  {
    __debugbreak();
  }
  return v5;
}


// address=[0x146b800]
// Decompiled from int __cdecl CMagic::GetCurrentSpellCategoryCounter(int a1, int a2)
int __cdecl CMagic::GetCurrentSpellCategoryCounter(int a1, int a2) {
  
  type_info *v2; // eax
  CPlayerMagicData *v3; // eax
  int v5; // [esp+0h] [ebp-4h]

  v5 = 0;
  if ( CPlayerManager::ValidUsedPlayerId(a1) )
  {
    if ( (unsigned __int8)sub_146C500(a2) )
    {
      v2 = CPlayerManager::PlayerGameData(a1);
      v3 = (CPlayerMagicData *)CPlayerGameData::MagicData(v2);
      return CPlayerMagicData::SpellCategoryCounter(v3, a2);
    }
    else if ( BBSupportDbgReport(
                1,
                "Logic\\Magic.cpp",
                3145,
                "CMagic::GetCurrentSpellCategoryCounter(): Invalid spell category!") == 1 )
    {
      __debugbreak();
    }
  }
  else if ( BBSupportDbgReport(
              1,
              "Logic\\Magic.cpp",
              3150,
              "CMagic::GetCurrentSpellCategoryCounter(): Invalid player id!") == 1 )
  {
    __debugbreak();
  }
  return v5;
}


// address=[0x146b8a0]
// Decompiled from int __cdecl CMagic::CalculatePossibleNumberOfCastSpell(int a1, int a2, int a3)
int __cdecl CMagic::CalculatePossibleNumberOfCastSpell(int a1, int a2, int a3) {
  
  type_info *v4; // eax
  type_info *v5; // eax
  CPlayerMagicData *v6; // eax
  type_info *v7; // eax
  CPlayerMagicData *v8; // eax
  int v9; // [esp+0h] [ebp-3Ch]
  int v10; // [esp+Ch] [ebp-30h]
  int v11; // [esp+18h] [ebp-24h]
  int v12; // [esp+1Ch] [ebp-20h]
  int i; // [esp+20h] [ebp-1Ch]
  int j; // [esp+28h] [ebp-14h]
  CPlayerMagicData *v15; // [esp+2Ch] [ebp-10h]
  int v16; // [esp+30h] [ebp-Ch]
  int v17; // [esp+34h] [ebp-8h]
  int v18; // [esp+38h] [ebp-4h]

  if ( !CPlayerManager::ValidUsedPlayerId(a1) )
    return 0;
  v11 = sub_146C560(a1);
  if ( !(unsigned __int8)sub_146C530(v11) || !(unsigned __int8)sub_146C500(a2) )
    return 0;
  if ( (a3 & 1) != 0 )
    return 99;
  v4 = CPlayerManager::PlayerGameData(a1);
  v15 = (CPlayerMagicData *)CPlayerGameData::MagicData(v4);
  if ( CPlayerMagicData::ManaAmountChanged(v15) )
  {
    CPlayerMagicData::ClearManaAmountChangedFlag(v15);
    CPlayerMagicData::MarkMaxSpellCastNumbersAsInvalid(v15);
  }
  v18 = CPlayerMagicData::MaxSpellCastNumber(v15, a2);
  if ( v18 >= 0 )
    return v18;
  if ( (a3 & 2) != 0 )
    v12 = 2;
  else
    v12 = 0;
  v10 = sub_146C620(v12);
  v9 = sub_146C670(v11, a2);
  v18 = 0;
  v5 = CPlayerManager::PlayerGameData(a1);
  v6 = (CPlayerMagicData *)CPlayerGameData::MagicData(v5);
  v16 = CPlayerMagicData::ManaAmount(v6);
  v7 = CPlayerManager::PlayerGameData(a1);
  v8 = (CPlayerMagicData *)CPlayerGameData::MagicData(v7);
  v17 = CPlayerMagicData::SpellCategoryCost(v8, a2);
  if ( v10 <= 0 )
  {
    for ( i = sub_146C710(v17, v12); v18 < 99 && v16 >= i; i = sub_146C710(v17, v12) )
    {
      if ( i <= 0 && BBSupportDbgReport(2, "Logic\\Magic.cpp", 3308, "iActualCosts > 0") == 1 )
        __debugbreak();
      v16 -= i;
      ++v18;
      v17 = sub_146C6B0(v17, 0, v9);
    }
  }
  else
  {
    for ( j = sub_146C710(v17, a3); v18 < 99 && v16 >= j; j = sub_146C710(v17, v12) )
    {
      if ( j <= 0 && BBSupportDbgReport(2, "Logic\\Magic.cpp", 3293, "iActualCosts > 0") == 1 )
        __debugbreak();
      v16 -= j;
      ++v18;
      v17 = sub_146C6B0(v17, v10, v9);
    }
  }
  CPlayerMagicData::SetMaxSpellCastNumber(v15, a2, v18);
  return v18;
}


// address=[0x146bb70]
// Decompiled from int __cdecl CMagic::GetConvertGoodInfo(int a1, int a2, int a3)
void __cdecl CMagic::GetConvertGoodInfo(int a1, int & a2, int & a3) {
  
  int v4; // [esp+0h] [ebp-4h]

  if ( CPlayerManager::ValidUsedPlayerId(a1) )
  {
    v4 = sub_146C560(a1);
    return sub_146C750(v4, a2, a3);
  }
  else
  {
    if ( BBSupportDbgReport(1, "Logic\\Magic.cpp", 3171, "CMagic::MagicGetConvertGoodInfo(): Invalid player id!") == 1 )
      __debugbreak();
    return sub_146C750(5, a2, a3);
  }
}


// address=[0x146bbe0]
// Decompiled from void __cdecl CMagic::IncreaseManaByDonation(int a1)
void __cdecl CMagic::IncreaseManaByDonation(int a1) {
  
  int v1; // eax
  type_info *v2; // eax
  int v3; // eax
  CPlayerMagicData *v4; // [esp+0h] [ebp-8h]
  int v5; // [esp+4h] [ebp-4h]

  if ( !CPlayerManager::ValidUsedPlayerId(a1)
    && BBSupportDbgReport(2, "Logic\\Magic.cpp", 3184, "g_cPlayerMgr.ValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  v1 = CStaticConfigVarInt::operator int(&unk_3F2011C);
  v5 = sub_146C4C0(v1, 1, 99);
  CMagic::IncreaseMana(a1, v5);
  v2 = CPlayerManager::PlayerGameData(a1);
  v4 = (CPlayerMagicData *)CPlayerGameData::MagicData(v2);
  v3 = CPlayerMagicData::TotalAmountOfCollectedMana(v4);
  CPlayerMagicData::SetTotalAmountOfCollectedMana(v4, v5 + v3);
}


// address=[0x146bc80]
// Decompiled from void __cdecl CMagic::IncreaseManaByBigTemple(int a1)
void __cdecl CMagic::IncreaseManaByBigTemple(int a1) {
  
  int v1; // eax
  type_info *v2; // eax
  int v3; // eax
  CPlayerMagicData *v4; // [esp+0h] [ebp-8h]
  int v5; // [esp+4h] [ebp-4h]

  if ( !CPlayerManager::ValidUsedPlayerId(a1)
    && BBSupportDbgReport(2, "Logic\\Magic.cpp", 3201, "g_cPlayerMgr.ValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  v1 = CStaticConfigVarInt::operator int(&unk_3F20128);
  v5 = sub_146C4C0(v1, 0, 999);
  CMagic::IncreaseMana(a1, v5);
  v2 = CPlayerManager::PlayerGameData(a1);
  v4 = (CPlayerMagicData *)CPlayerGameData::MagicData(v2);
  v3 = CPlayerMagicData::TotalAmountOfCollectedMana(v4);
  CPlayerMagicData::SetTotalAmountOfCollectedMana(v4, v5 + v3);
}


// address=[0x146bd20]
// Decompiled from int __cdecl CMagic::TotalAmountOfCollectedMana(int a1)
int __cdecl CMagic::TotalAmountOfCollectedMana(int a1) {
  
  type_info *v1; // eax
  CPlayerMagicData *v3; // [esp+0h] [ebp-8h]
  int v4; // [esp+4h] [ebp-4h]

  v4 = 0;
  if ( CPlayerManager::ValidUsedPlayerId(a1) )
  {
    v1 = CPlayerManager::PlayerGameData(a1);
    v3 = (CPlayerMagicData *)CPlayerGameData::MagicData(v1);
    return CPlayerMagicData::TotalAmountOfCollectedMana(v3);
  }
  else if ( BBSupportDbgReport(1, "Logic\\Magic.cpp", 3228, "CMagic::TotalAmountOfCollectedMana(): Invalid player id!") == 1 )
  {
    __debugbreak();
  }
  return v4;
}


// address=[0x146bd90]
// Decompiled from void __cdecl CMagic::DecreaseManaAfterWarmachineShot(int a1)
void __cdecl CMagic::DecreaseManaAfterWarmachineShot(int a1) {
  
  int v1; // eax
  int v2; // [esp+0h] [ebp-4h]

  v1 = CStaticConfigVarInt::operator int(&unk_3F200F8);
  v2 = sub_146C4C0(v1, 1, 999);
  CMagic::DecreaseMana(a1, v2);
}


// address=[0x146bdd0]
// Decompiled from void __cdecl CMagic::IncreaseMana(int a1, int a2)
void __cdecl CMagic::IncreaseMana(int a1, int a2) {
  
  type_info *v2; // eax
  int v3; // [esp+0h] [ebp-Ch]
  CPlayerMagicData *v4; // [esp+8h] [ebp-4h]

  if ( a2 < 0 && BBSupportDbgReport(2, "Logic\\Magic.cpp", 3336, "_iDeltaAmount >= 0") == 1 )
    __debugbreak();
  if ( CPlayerManager::ValidUsedPlayerId(a1) )
  {
    v2 = CPlayerManager::PlayerGameData(a1);
    v4 = (CPlayerMagicData *)CPlayerGameData::MagicData(v2);
    v3 = a2 + CPlayerMagicData::ManaAmount(v4);
    CPlayerMagicData::SetManaAmount(v4, v3);
  }
  else if ( BBSupportDbgReport(1, "Logic\\Magic.cpp", 3349, "CMagic::IncreaseMana(): Invalid player id!") == 1 )
  {
    __debugbreak();
  }
}


// address=[0x146be70]
// Decompiled from void __cdecl CMagic::DecreaseMana(int a1, int a2)
void __cdecl CMagic::DecreaseMana(int a1, int a2) {
  
  type_info *v2; // eax
  CPlayerMagicData *v3; // [esp+4h] [ebp-Ch]
  unsigned int v4; // [esp+8h] [ebp-8h]
  unsigned int v5; // [esp+Ch] [ebp-4h]

  if ( a2 < 0 && BBSupportDbgReport(2, "Logic\\Magic.cpp", 3360, "_iDeltaAmount >= 0") == 1 )
    __debugbreak();
  if ( CPlayerManager::ValidUsedPlayerId(a1) )
  {
    v2 = CPlayerManager::PlayerGameData(a1);
    v3 = (CPlayerMagicData *)CPlayerGameData::MagicData(v2);
    v5 = CPlayerMagicData::ManaAmount(v3);
    if ( v5 < a2 )
      v4 = 0;
    else
      v4 = v5 - a2;
    CPlayerMagicData::SetManaAmount(v3, v4);
  }
  else if ( BBSupportDbgReport(1, "Logic\\Magic.cpp", 3373, "CMagic::DecreaseMana(): Invalid player id!") == 1 )
  {
    __debugbreak();
  }
}


// address=[0x146bf30]
// Decompiled from char __cdecl CMagic::CheckAndDecreaseMana(int a1, int a2)
bool __cdecl CMagic::CheckAndDecreaseMana(int a1, int a2) {
  
  type_info *v2; // eax
  CPlayerMagicData *v4; // [esp+4h] [ebp-Ch]
  unsigned int v5; // [esp+Ch] [ebp-4h]

  if ( a2 < 0 && BBSupportDbgReport(2, "Logic\\Magic.cpp", 3384, "_iDeltaAmount >= 0") == 1 )
    __debugbreak();
  if ( CPlayerManager::ValidUsedPlayerId(a1) )
  {
    v2 = CPlayerManager::PlayerGameData(a1);
    v4 = (CPlayerMagicData *)CPlayerGameData::MagicData(v2);
    v5 = CPlayerMagicData::ManaAmount(v4);
    if ( v5 < a2 )
    {
      return 0;
    }
    else
    {
      CPlayerMagicData::SetManaAmount(v4, v5 - a2);
      return 1;
    }
  }
  else
  {
    if ( BBSupportDbgReport(1, "Logic\\Magic.cpp", 3408, "CMagic::CheckAndDecreaseMana(): Invalid player id!") == 1 )
      __debugbreak();
    return 0;
  }
}


// address=[0x146bff0]
// Decompiled from void __cdecl CMagic::DbgPrint(int a1)
void __cdecl CMagic::DbgPrint(int a1) {
  
  type_info *v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // [esp-1Ch] [ebp-28h]
  int v9; // [esp-1Ch] [ebp-28h]
  int v10; // [esp-1Ch] [ebp-28h]
  int v11; // [esp-18h] [ebp-24h]
  int v12; // [esp-18h] [ebp-24h]
  int v13; // [esp-18h] [ebp-24h]
  int v14; // [esp-14h] [ebp-20h]
  int v15; // [esp-14h] [ebp-20h]
  int v16; // [esp-14h] [ebp-20h]
  int v17; // [esp-10h] [ebp-1Ch]
  int v18; // [esp-10h] [ebp-1Ch]
  int v19; // [esp-10h] [ebp-1Ch]
  int v20; // [esp-Ch] [ebp-18h]
  int v21; // [esp-Ch] [ebp-18h]
  int v22; // [esp-Ch] [ebp-18h]
  int v23; // [esp-8h] [ebp-14h]
  int v24; // [esp-8h] [ebp-14h]
  int v25; // [esp-8h] [ebp-14h]
  int v26; // [esp-4h] [ebp-10h]
  int v27; // [esp-4h] [ebp-10h]
  int v28; // [esp-4h] [ebp-10h]
  int i; // [esp+0h] [ebp-Ch]
  int j; // [esp+4h] [ebp-8h]
  CPlayerMagicData *v31; // [esp+8h] [ebp-4h]

  if ( a1 )
  {
    if ( CPlayerManager::ValidUsedPlayerId(a1) )
    {
      for ( i = 0; i < 8; ++i )
        CMagic::CalculatePossibleNumberOfCastSpell(a1, i, 0);
      v1 = CPlayerManager::PlayerGameData(a1);
      v31 = (CPlayerMagicData *)CPlayerGameData::MagicData(v1);
      BBSupportTracePrintF(0, "Magic data for player %i:", a1);
      v2 = CPlayerMagicData::ManaAmount(v31);
      BBSupportTracePrintF(0, "  Mana amount:     %i", v2);
      v3 = CPlayerMagicData::TotalAmountOfCollectedMana(v31);
      BBSupportTracePrintF(0, "  Total collected: %i", v3);
      v4 = CPlayerMagicData::MaxNumberOfBigTemples(v31);
      BBSupportTracePrintF(0, "  Max big temples: %i", v4);
      v26 = CPlayerMagicData::SpellCategoryCost(v31, 7);
      v23 = CPlayerMagicData::SpellCategoryCost(v31, 6);
      v20 = CPlayerMagicData::SpellCategoryCost(v31, 5);
      v17 = CPlayerMagicData::SpellCategoryCost(v31, 4);
      v14 = CPlayerMagicData::SpellCategoryCost(v31, 3);
      v11 = CPlayerMagicData::SpellCategoryCost(v31, 2);
      v8 = CPlayerMagicData::SpellCategoryCost(v31, 1);
      v5 = CPlayerMagicData::SpellCategoryCost(v31, 0);
      BBSupportTracePrintF(0, "  Spell costs:     %i, %i, %i, %i, %i, %i, %i, %i", v5, v8, v11, v14, v17, v20, v23, v26);
      v27 = CPlayerMagicData::SpellCategoryCounter(v31, 7);
      v24 = CPlayerMagicData::SpellCategoryCounter(v31, 6);
      v21 = CPlayerMagicData::SpellCategoryCounter(v31, 5);
      v18 = CPlayerMagicData::SpellCategoryCounter(v31, 4);
      v15 = CPlayerMagicData::SpellCategoryCounter(v31, 3);
      v12 = CPlayerMagicData::SpellCategoryCounter(v31, 2);
      v9 = CPlayerMagicData::SpellCategoryCounter(v31, 1);
      v6 = CPlayerMagicData::SpellCategoryCounter(v31, 0);
      BBSupportTracePrintF(0, "  Spell counters:  %i, %i, %i, %i, %i, %i, %i, %i", v6, v9, v12, v15, v18, v21, v24, v27);
      v28 = CPlayerMagicData::MaxSpellCastNumber(v31, 7);
      v25 = CPlayerMagicData::MaxSpellCastNumber(v31, 6);
      v22 = CPlayerMagicData::MaxSpellCastNumber(v31, 5);
      v19 = CPlayerMagicData::MaxSpellCastNumber(v31, 4);
      v16 = CPlayerMagicData::MaxSpellCastNumber(v31, 3);
      v13 = CPlayerMagicData::MaxSpellCastNumber(v31, 2);
      v10 = CPlayerMagicData::MaxSpellCastNumber(v31, 1);
      v7 = CPlayerMagicData::MaxSpellCastNumber(v31, 0);
      BBSupportTracePrintF(
        0,
        "  Max cast:        %i, %i, %i, %i, %i, %i, %i, %i",
        v7,
        v10,
        v13,
        v16,
        v19,
        v22,
        v25,
        v28);
    }
  }
  else
  {
    for ( j = 1; j <= 8; ++j )
      CMagic::DbgPrint(j);
  }
}


// address=[0x146c220]
// Decompiled from int __cdecl CMagic::MagicGetSpellRange(int a1, int a2)
int __cdecl CMagic::MagicGetSpellRange(int a1, int a2) {
  
  int v3; // eax

  if ( !(unsigned __int8)sub_146C530(a1)
    && BBSupportDbgReport(2, "Logic\\Magic.cpp", 2811, "MagicIsValidRace(_iRace)") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)sub_146C500(a2)
    && BBSupportDbgReport(2, "Logic\\Magic.cpp", 2812, "MagicIsValidSpellCategory(_iSpellCategory)") == 1 )
  {
    __debugbreak();
  }
  if ( a2 == 4 && a1 == 2 || a2 == 7 && a1 == 4 )
    return 2048;
  v3 = CStaticConfigVarInt::operator int(&unk_3F20134);
  return sub_146C4C0(v3, 5, 50);
}


// address=[0x146c320]
// Decompiled from void __cdecl CMagic::ExecuteCastSpell(unsigned int a1, unsigned int a2, unsigned int a3)
void __cdecl CMagic::ExecuteCastSpell(unsigned int a1, unsigned int a2, unsigned int a3) {
  
  _DWORD *v3; // eax
  int v4; // eax
  int v5; // [esp-10h] [ebp-4Ch]
  int v6; // [esp-Ch] [ebp-48h]
  _BYTE v7[36]; // [esp+0h] [ebp-3Ch] BYREF
  unsigned int v8; // [esp+24h] [ebp-18h]
  unsigned int v9; // [esp+28h] [ebp-14h]
  int v10; // [esp+2Ch] [ebp-10h]
  int v11; // [esp+30h] [ebp-Ch]
  int v12; // [esp+34h] [ebp-8h]
  int v13; // [esp+38h] [ebp-4h]

  v11 = (unsigned __int8)a2;
  v12 = BYTE1(a2);
  v9 = HIWORD(a2);
  v10 = (unsigned __int16)a3;
  v8 = HIWORD(a3);
  if ( CPlayerManager::ValidUsedPlayerId((unsigned __int8)a2) )
  {
    v13 = sub_146C560(v11);
    if ( !(unsigned __int8)sub_146C530(v13)
      && BBSupportDbgReport(2, "Logic\\Magic.cpp", 3431, "MagicIsValidRace(iRace)") == 1 )
    {
      __debugbreak();
    }
    if ( !(unsigned __int8)sub_146C500(v12)
      && BBSupportDbgReport(2, "Logic\\Magic.cpp", 3432, "MagicIsValidSpellCategory(iSpellCategory)") == 1 )
    {
      __debugbreak();
    }
    if ( !(unsigned __int8)CWorldManager::InWorld(v9, v10)
      && BBSupportDbgReport(2, "Logic\\Magic.cpp", 3433, "g_cWorld.InWorld(iDestX, iDestY)") == 1 )
    {
      __debugbreak();
    }
    v6 = sub_146C8C0(v13, v12);
    v5 = sub_146C7D0(v13, v12);
    v3 = (_DWORD *)TStaticConfigIntArrayBase<8>::operator[](v12);
    v4 = sub_146C4C0(*v3, 0, 30);
    CMagicSpell::CMagicSpell((CMagicSpell *)v7, v11, v13, v9, v10, v4, v5, v6, v8, a1);
    CMagicSpell::CastSpell((CMagicSpell *)v7, v13, v12);
    CMagicSpell::ShowSpellEffect(v13, v12, v9, v10);
  }
}


