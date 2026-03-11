#include "LuaExports.h"

#include "../CLua.h"

#include "GameExports.h"

// address=[0x1603a90]
// Decompiled from void __cdecl ScriptExportFunctions(struct CLua *a1)
void __cdecl ScriptExportFunctions(CLua &a1)
{
  a1.ExportTableFunctions("Buildings", sBuildingFunctions);
  a1.ExportTableFunctions("dbg", sDbgFunctions);
  a1.ExportTableFunctions("Debug", sDebugFunctions);
  a1.ExportTableFunctions("Effects", sEffectFunctions);
  a1.ExportTableFunctions("Game", sGameFunctions);
  a1.ExportTableFunctions("Goods", sGoodsFunctions);
  a1.ExportTableFunctions("Magic", sMagicFunctions);
  a1.ExportTableFunctions("Map", sMapFunctions);
  a1.ExportTableFunctions("Sounds", sSoundsFunctions);
  a1.ExportTableFunctions("Statistic", sStatisticFunctions);
  a1.ExportTableFunctions("Tutorial", sTutorialFunctions);
  a1.ExportTableFunctions("Vehicles", sVehicleFunctions);
  a1.ExportTableFunctions("Settlers", sSettlerFunctions);
  a1.ExportTableFunctions("DarkTribe", sDarkTribeFunctions);
}

// address=[0x1603910]
// Decompiled from void __cdecl ScriptExportVars(struct CLua *a1)
void __cdecl ScriptExportVars(CLua &a1)
{
  a1.ExportTableTypes("Buildings", "BUILDING_", sBuildingDefines, 379u);
  a1.ExportTableTypes("Effects", "EFFECT_", sEffectDefines, 86u);
  a1.ExportTableTypes("Goods", "GOOD_", sGoodDefines, 43u);
  a1.ExportTableTypes("Settlers", "SETTLER_", sSettlerDefines, 434u);
  a1.ExportTableTypes("Sounds", "SOUND_", sSoundDefines, 109u);
  a1.ExportTableTypes("Vehicles", "VEHICLE_", sVehicleDefines, 59u);
  a1.ExportTableVar("Vehicles", "FOUNDATION_CART", 1030.0);
  a1.ExportTableVars("Buildings", sBuildingsVarTable);
  a1.ExportTableVars("Game", sGameVarTable);
  a1.ExportTableVars("Goods", sGoodsVarTable);
  a1.ExportTableVars("Control", sControlVarTable);
  a1.ExportTableVars("Dialog", sDialogVarTable);
  a1.ExportTableVars("Menu", sMenuVarTable);
  a1.ExportTableVars("Magic", sMagicVarTable);
  a1.ExportTableVars("Events", sEventsVarTable);
  a1.ExportTableVars("Settlers", sSettlersVarTable);
  a1.ExportTableVars("Vehicles", sVehiclesVarTable);
}