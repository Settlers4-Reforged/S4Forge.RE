#ifndef S4_MAIN_GOODS_H
#define S4_MAIN_GOODS_H

#include "DefineTransformers.h"

#define GOODS \
    X(0, GOOD_NO_GOOD) \
    X(1, GOOD_AGAVE) \
    X(2, GOOD_AMMO) \
    X(3, GOOD_ARMOR) \
    X(4, GOOD_AXE) \
    X(5, GOOD_BATTLEAXE) \
    X(6, GOOD_BLOWGUN) \
    X(7, GOOD_BOARD) \
    X(8, GOOD_BOW) \
    X(9, GOOD_BREAD) \
    X(10, GOOD_COAL) \
    X(11, GOOD_FISH) \
    X(12, GOOD_FLOUR) \
    X(13, GOOD_GOAT) \
    X(14, GOOD_GOLDBAR) \
    X(15, GOOD_GOLDORE) \
    X(16, GOOD_GRAIN) \
    X(17, GOOD_GUNPOWDER) \
    X(18, GOOD_HAMMER) \
    X(19, GOOD_HONEY) \
    X(20, GOOD_IRONBAR) \
    X(21, GOOD_IRONORE) \
    X(22, GOOD_LOG) \
    X(23, GOOD_MEAD) \
    X(24, GOOD_MEAT) \
    X(25, GOOD_PICKAXE) \
    X(26, GOOD_PIG) \
    X(27, GOOD_ROD) \
    X(28, GOOD_SAW) \
    X(29, GOOD_SCYTHE) \
    X(30, GOOD_SHEEP) \
    X(31, GOOD_SHOVEL) \
    X(32, GOOD_STONE) \
    X(33, GOOD_SULFUR) \
    X(34, GOOD_SWORD) \
    X(35, GOOD_TEQUILA) \
    X(36, GOOD_WATER) \
    X(37, GOOD_WINE) \
    X(38, GOOD_BACKPACKCATAPULT) \
    X(39, GOOD_GOOSE) \
    X(40, GOOD_EXPLOSIVEARROW) \
    X(41, GOOD_SUNFLOWEROIL) \
    X(42, GOOD_SUNFLOWER)

#define X(id, name) TO_ENUM(id, name)

enum S4_GOOD_ENUM {
    GOODS
    GOOD_MAX
};
#undef X

#define X TO_PAIR
SConfigTypeString s_sGoodDefines[] = {
    GOODS
};
#undef X


#endif //S4_MAIN_GOODS_H
