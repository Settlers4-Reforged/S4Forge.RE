#ifndef CAMPAIGN_H
#define CAMPAIGN_H

#include "DefineTransformers.h"

#define CAMPAIGNS       \
    X(0, CAMPAIGN_NONE) \
    X(0x18, CAMPAIGN_MAX)

#define X TO_ENUM

enum T_S4_CAMPAIGN {
    CAMPAIGNS
};

#undef X

#endif // CAMPAIGN_H
