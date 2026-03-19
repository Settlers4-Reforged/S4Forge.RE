#ifndef VAR_AI_H
#define VAR_AI_H

#include "AI/CAIConfigInt.h"

// address=[0x3E8DD50]
CAIConfigInt CAIAgentDarkTribeAttack::s_iMaxSoldiersPerTaskForce{"DTMaxSoldiersPerTaskForce", 6};
// address=[0x3E8DD6C]
CAIConfigInt s_iDTBowmanToSwordsmanRatio256{"DTBowmanToSwordsmanRatio256", 128};
// address=[0x3E8DD84]
CAIConfigInt s_iDTGardenerMax1A256{"DTGardenerMax1A256", 16};
// address=[0x3E8DD90]
CAIConfigInt s_iDTGardenerMax1B{"DTGardenerMax1B", 0};
// address=[0x3E8DD9C]
CAIConfigInt s_iDTGardenerMax2A256{"DTGardenerMax2A256", 8};
// address=[0x3E8DDA8]
CAIConfigInt s_iDTGardenerMax2B{"DTGardenerMax2B", 5};
// address=[0x3E8DDB4]
CAIConfigInt s_iDTGardenerMax{"DTGardenerMax", 21};
// address=[0x3E8DDC0]
CAIConfigInt s_iDTShamanMax1A256{"DTShamanMax1A256", 16};
// address=[0x3E8DDCC]
CAIConfigInt s_iDTShamanMax1B{"DTShamanMax1B", 0};
// address=[0x3E8DDD8]
CAIConfigInt s_iDTShamanMax2A256{"DTShamanMax2A256", 8};
// address=[0x3E8DDE4]
CAIConfigInt s_iDTShamanMax2B{"DTShamanMax2B", 5};
// address=[0x3E8DDF0]
CAIConfigInt s_iDTShamanMax{"DTShamanMax", 21};
// address=[0x3E8DD78]
CAIConfigInt s_iDTFightersMin{"DTFightersMin", 10};
// address=[0x3E8DE30]
CAIConfigInt s_iSquadMaxRecruits{"SquadMaxRecruits", 5};
// address=[0x3E8DE24]
CAIConfigInt s_iSquadMinExtraFighters{"SquadMinExtraFighters", 2};
// address=[0x3E8DE18]
CAIConfigInt s_iSquadMinFighters{"SquadMinFighters", 10};
// address=[0x3E95834]
CAIConfigInt g_cAIDarkTribeCostBowman{"DTCostBowman", 15};
// address=[0x3E95810]
CAIConfigInt g_cAIDarkTribeCostDarkGardener{"DTCostDarkGardener", 5};
// address=[0x3E95804]
CAIConfigInt g_cAIDarkTribeCostMushroomFarmer{"DTCostMushroomFarmer", 5};
// address=[0x3E9581C]
CAIConfigInt g_cAIDarkTribeCostShaman{"DTCostShaman", 10};
// address=[0x3E95828]
CAIConfigInt g_cAIDarkTribeCostSwordsman{"DTCostSwordman", 15};
// address=[0x3E95840]
CAIConfigInt g_cAIDarkTribeMushroomFarmCreationDelay{"DTMushroomFarmDelay", 300};
// address=[0x3ECCCAC]
CAIConfigInt s_iPortTowerMaxDist{"PortTowerMaxDist", 12};
// address=[0x3ECCCA0]
CAIConfigInt s_iProtectPorts{"ProtectPorts", 1};
// address=[0x3ECCCD0]
CAIConfigInt s_iMaxNoWarShipsMode1{"MaxNoWarShipsMode1", 10};
// address=[0x3ECCCC4]
CAIConfigInt s_iMinNoWarShipsMode1{"MinNoWarShipsMode1", 2};
// address=[0x3ECCCDC]
CAIConfigInt s_iUseWarMachines{"UseWarMachines", 1};
// address=[0x3ECCCB8]
CAIConfigInt s_iUseWarShipsMode{"UseWarShipsMode", 1};


// address=[0x40F229C]
CAIConfigInt CManakopterHallRole::s_iRequiredBoard{"DTManakopterRequiredBoards", 5};
// address=[0x40F22A8]
CAIConfigInt CManakopterHallRole::s_iRequiredIron{"DTManakopterRequiredIron", 5};
// address=[0x40F2290]
CAIConfigInt CManakopterHallRole::s_iRequiredMana{"DTManakopterRequiredMana", 4};
// address=[0x410536C]
CAIConfigInt CManakopter::s_iManakopterArmor{"DTManakopterArmor", 10};
// address=[0x4105360]
CAIConfigInt CManakopter::s_iManakopterHitPoints{"DTManakopterHitpoints", 250};
// address=[0x4158C64]
CAIConfigInt CShamanRole::s_iManaCostEnslave{"DTManaCostEnslave", 5};
// address=[0x4158C4C]
CAIConfigInt CShamanRole::s_iManaCostRot{"DTManaCostRot", 5};
// address=[0x4158C58]
CAIConfigInt CShamanRole::s_iManaCostTeleport{"DTManaCostTeleport", 5};
// address=[0x4158C70]
CAIConfigInt CShamanRole::s_iShamanManaPool{"DTShamanManaPool", 10};

#endif //VAR_AI_H
