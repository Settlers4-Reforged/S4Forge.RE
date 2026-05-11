#ifndef CCONFIGMANAGERPTR_H
#define CCONFIGMANAGERPTR_H

#include "defines.h"

#include "IConfigManager.h"

class CConfigManagerPtr {
public:
    // address=[0x2eef110]
    static IConfigManager *__cdecl GetInstance(void);

    // address=[0x2eef1e0]
    static void __cdecl DeleteConfigManager(void);

private:
    // address=[0x46851a4]
    static IConfigManager *m_pConfigManager;

    // address=[0x46851a8]
    static bool m_bWasDeleted;
};

#endif // CCONFIGMANAGERPTR_H
