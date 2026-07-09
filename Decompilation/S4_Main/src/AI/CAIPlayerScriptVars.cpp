#include "CAIPlayerScriptVars.h"

#include "CAIConfigIntEx.h"
#include "CBB/CBBSupport.h"
#include "Defines/AI.h"
#include "LoadSave/IS4Chunk.h"

// Definitions for class CAIPlayerScriptVars

int s_iDefaultScriptVars[4][23];

// address=[0x12fcaf0]
// Decompiled from int __thiscall CAIPlayerScriptVars::operator[](CAIPlayerScriptVars *this, unsigned int _tVarIndex)
int CAIPlayerScriptVars::operator[](enum T_AI_PLAYER_SCRIPT_VAR_INDEX _tVarIndex) const {
    BB_ASSERT(static_cast<unsigned int>(_tVarIndex) <= AI_PLAYER_SCRIPT_VAR_LAST)
    return this->m_pActiveVars->m_iVars[_tVarIndex];
}

// address=[0x1303840]
// Decompiled from int __thiscall CAIPlayerScriptVars::Flags(CAIPlayerScriptVars *this)
int CAIPlayerScriptVars::Flags(void) const {
    return this->m_iFlags;
}

// address=[0x1306500]
// Decompiled from int __thiscall CAIPlayerScriptVars::DifficultyLevel(CAIPlayerScriptVars *this)
enum T_AI_DIFFICULTY_LEVEL CAIPlayerScriptVars::DifficultyLevel(void) const {
    return this->m_iDifficultyLevel;
}

// address=[0x1309800]
// Decompiled from void __thiscall CAIPlayerScriptVars::SetDifficultyLevel(CAIPlayerScriptVars *this, int _tDifficultyLevel)
void CAIPlayerScriptVars::SetDifficultyLevel(enum T_AI_DIFFICULTY_LEVEL _tDifficultyLevel) {

    BB_ASSERT(static_cast<unsigned int>(_tDifficultyLevel) <= AI_DIFFICULTY_LEVEL_LAST)

    this->m_iDifficultyLevel = _tDifficultyLevel;
    this->m_pActiveVars = &this->m_vVars[_tDifficultyLevel];
}

// address=[0x131cad0]
// Decompiled from void __thiscall CAIPlayerScriptVars::Init(CAIPlayerScriptVars *this)
void CAIPlayerScriptVars::Init(void) {
    CAIPlayerScriptVars::SetDifficultyLevel(static_cast<enum T_AI_DIFFICULTY_LEVEL>(2));
    this->m_iFlags = 0;
    for(int i = 0; i <= 3; ++i) {
        for(int j = 0; j <= 22; ++j)
            this->m_vVars[i].m_iVars[j] = s_iDefaultScriptVars[i][j];
    }
}

// address=[0x131cb50]
// Decompiled from void __thiscall CAIPlayerScriptVars::Load(CAIPlayerScriptVars *this, struct IS4Chunk *rChunk)
void CAIPlayerScriptVars::Load(class IS4Chunk &rChunk) {

    T_AI_DIFFICULTY_LEVEL iDifficultyLevel = static_cast<enum T_AI_DIFFICULTY_LEVEL>(rChunk.LoadUnsigned32(0, 3));
    int iFlags = rChunk.LoadUnsigned32();
    CAIPlayerScriptVars::SetDifficultyLevel(iDifficultyLevel);
    CAIPlayerScriptVars::SetFlags(iFlags);
    signed int iAvailableVars = rChunk.LoadUnsigned32(0, 22);
    for(int i = 0; i <= 3; ++i) {
        int j = 0; // [esp+18h] [ebp-4h]
        for(; j <= iAvailableVars; ++j)
            this->m_vVars[i].m_iVars[j] = rChunk.LoadUnsigned32();
        while(j <= 22) {
            this->m_vVars[i].m_iVars[j] = s_iDefaultScriptVars[i][j];
            ++j;
        }
    }
}

// address=[0x131cc40]
// Decompiled from void __thiscall CAIPlayerScriptVars::Save(CAIPlayerScriptVars *this, struct IS4Chunk *a2)
void CAIPlayerScriptVars::Save(class IS4Chunk &a2) {
    a2.SaveUnsigned32(this->m_iDifficultyLevel);
    a2.SaveUnsigned32(this->m_iFlags);
    a2.SaveUnsigned32(22);
    for(int i = 0; i <= 3; ++i) {
        for(int j = 0; j <= 22; ++j)
            a2.SaveUnsigned32(this->m_vVars[i].m_iVars[j]);
    }
}

// address=[0x131ed70]
// Decompiled from void __thiscall CAIPlayerScriptVars::SetFlags(CAIPlayerScriptVars *this, int _iFlags)
void CAIPlayerScriptVars::SetFlags(int _iFlags) {

    this->m_iFlags = _iFlags;
}

// address=[0x3ECC5C8]
CAIConfigIntEx s_sAIPlayerScriptVarAttackChancePartial{ "AttackChancePartial", 20, USE_PREV_CONFIG_VALUE, USE_PREV_CONFIG_VALUE };
// address=[0x3ECC5B0]
CAIConfigIntEx s_sAIPlayerScriptVarAttackDelay{ "AttackDelay", 75, 45, 30 };
// address=[0x3ECC598]
CAIConfigIntEx s_sAIPlayerScriptVarAttackMode{ "AttackMode", 2, USE_PREV_CONFIG_VALUE, USE_PREV_CONFIG_VALUE };
// address=[0x3ECC5E0]
CAIConfigIntEx s_sAIPlayerScriptVarAttackThresholdPartial{ "AttackThresholdPartial", 175, USE_PREV_CONFIG_VALUE, USE_PREV_CONFIG_VALUE };
// address=[0x3ECC5F8]
CAIConfigIntEx s_sAIPlayerScriptVarAttackThresholdTotal{ "AttackThresholdTotal", 225, USE_PREV_CONFIG_VALUE, USE_PREV_CONFIG_VALUE };
// address=[0x3ECC7A8]
CAIConfigIntEx s_sAIPlayerScriptVarDTAttackCheckDelay{ "DTAttackCheckDelay", 10, 5, 1 };
// address=[0x3ECC700]
CAIConfigIntEx s_sAIPlayerScriptVarDTExtraManaAmountPerFarm2{ "DTExtraManaAmountPerFarm2", 1, 2, 3 };
// address=[0x3ECC6E8]
CAIConfigIntEx s_sAIPlayerScriptVarDTExtraManaBaseAmount{ "DTExtraManaBaseAmount", 1, 2, 3 };
// address=[0x3ECC718]
CAIConfigIntEx s_sAIPlayerScriptVarDTExtraManaDelay{ "DTExtraManaDelay", 60, 60, 60 };
// address=[0x3ECC730]
CAIConfigIntEx s_sAIPlayerScriptVarDTExtraManaLimit{ "DTExtraManaLimit", 100, 200, 0 };
// address=[0x3ECC6A0]
CAIConfigIntEx s_sAIPlayerScriptVarDTManaPerSphere{ "DTManaPerSphere", 2, 6, 8 };
// address=[0x3ECC778]
CAIConfigIntEx s_sAIPlayerScriptVarDTManakopterDelay{ "DTManakopterDelay", 600, 300, 150 };
// address=[0x3ECC760]
CAIConfigIntEx s_sAIPlayerScriptVarDTManakopterHallDelay{ "DTManakopterHallDelay", 240, 120, 60 };
// address=[0x3ECC790]
CAIConfigIntEx s_sAIPlayerScriptVarDTManakopterLimit{ "DTManakopterLimit", 1, 1, 1 };
// address=[0x3ECC6B8]
CAIConfigIntEx s_sAIPlayerScriptVarDTMaxFarmsBase{ "DTMaxFarmsBase", 3, 5, 0 };
// address=[0x3ECC6D0]
CAIConfigIntEx s_sAIPlayerScriptVarDTMaxFarmsPerHour{ "DTMaxFarmsPerHour", 12, 15, 0 };
// address=[0x3ECC658]
CAIConfigIntEx s_sAIPlayerScriptVarMagicMode{ "MagicMode", 0, 0, 0 };
// address=[0x3ECC688]
CAIConfigIntEx s_sAIPlayerScriptVarSpellFlags{ "SpellFlags", 0, 0, 0 };
// address=[0x3ECC670]
CAIConfigIntEx s_sAIPlayerScriptVarSpellMask{ "SpellMask", 127, 255, 255 };
// address=[0x3ECC610]
CAIConfigIntEx s_sAIPlayerScriptVarSoldierLimitAbsolute{ "SoldierLimitAbsolute", 250, 500, 0 };
// address=[0x3ECC628]
CAIConfigIntEx s_sAIPlayerScriptVarSoldierLimitRelative{ "SoldierLimitRelative", 200, 250, 0 };
// address=[0x3ECC748]
CAIConfigIntEx s_sAIPlayerScriptVarUsePioneers{ "UsePioneers", 1, 2, 2 };
// address=[0x3ECC640]
CAIConfigIntEx s_sAIPlayerScriptVarWarmachineMode{ "WarmachineMode", 0, 0, 0 };

// address=[0x03676210]
SPlayerScriptVar s_sDefaultScriptVars[23] = {
    { &s_sAIPlayerScriptVarAttackMode, 0, 3 },                    //; 0
    { &s_sAIPlayerScriptVarAttackDelay, 1, 0x258 },               //; 1
    { &s_sAIPlayerScriptVarAttackChancePartial, 1, 0x14 },        //; 2
    { &s_sAIPlayerScriptVarAttackThresholdPartial, 1, 0x3E8 },    //; 3
    { &s_sAIPlayerScriptVarAttackThresholdTotal, 1, 0x3E8 },      //; 4
    { &s_sAIPlayerScriptVarSoldierLimitAbsolute, 0, 0x2710 },     //; 5
    { &s_sAIPlayerScriptVarSoldierLimitRelative, 0, 0x3E8 },      //; 6
    { &s_sAIPlayerScriptVarWarmachineMode, 0, 0x63 },             //; 7
    { &s_sAIPlayerScriptVarMagicMode, 0, 0x63 },                  //; 8
    { &s_sAIPlayerScriptVarSpellMask, 0, 0x0FF },                 //; 9
    { &s_sAIPlayerScriptVarSpellFlags, 0, 0x7FFFFFFF },           //; 10
    { &s_sAIPlayerScriptVarDTManaPerSphere, 1, 0x3E8 },           //; 11
    { &s_sAIPlayerScriptVarDTMaxFarmsBase, 0, 0x3E8 },            //; 12
    { &s_sAIPlayerScriptVarDTMaxFarmsPerHour, 0, 0x3E8 },         //; 13
    { &s_sAIPlayerScriptVarDTExtraManaBaseAmount, 0, 0x3E8 },     //; 14
    { &s_sAIPlayerScriptVarDTExtraManaAmountPerFarm2, 0, 0x3E8 }, //; 15
    { &s_sAIPlayerScriptVarDTExtraManaDelay, 1, 0x3E8 },          //; 16
    { &s_sAIPlayerScriptVarDTExtraManaLimit, 0, 0x2710 },         //; 17
    { &s_sAIPlayerScriptVarUsePioneers, 0, 2 },                   //; 18
    { &s_sAIPlayerScriptVarDTManakopterHallDelay, 0, 0x0E10 },    //; 19
    { &s_sAIPlayerScriptVarDTManakopterDelay, 0, 0x0E10 },        //; 20
    { &s_sAIPlayerScriptVarDTManakopterLimit, 1, 1 },             //; 21
    { &s_sAIPlayerScriptVarDTAttackCheckDelay, 1, 0x3E8 },        //; 22
};
