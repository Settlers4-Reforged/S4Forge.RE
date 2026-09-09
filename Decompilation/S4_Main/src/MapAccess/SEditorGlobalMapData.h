#ifndef SEDITORGLOBALMAPDATA_H
#define SEDITORGLOBALMAPDATA_H

#include "defines.h"

struct SEditorGlobalMapData {
    int m_iGameType;
    int m_uNumberOfPlayers;
    int m_iStartResources;
    short m_iWidthHeight;
    int m_iUnused;
    unsigned __int16 m_iFlags;
};

static_assert(sizeof(SEditorGlobalMapData) == 0x18, "sizeof(SEditorGlobalMapData)");
static_assert(offsetof(SEditorGlobalMapData, m_iFlags) == 0x14, "offsetof(SEditorGlobalMapData, m_iFlags)");
static_assert(offsetof(SEditorGlobalMapData, m_iWidthHeight) == 0xc, "offsetof(SEditorGlobalMapData, m_iFlags)");

#endif // SEDITORGLOBALMAPDATA_H
