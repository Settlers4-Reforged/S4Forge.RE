#include "helper.h"

// address=[0x1307190]
int __cdecl Y16X16::UnpackXFast(int packed) {
    return static_cast<unsigned short>(packed);
}

// address=[0x13071a0]
int __cdecl Y16X16::UnpackYFast(int packed) {
    return packed >> 16;
}

// address=[0x130f2a0]
int __cdecl Y16X16::PackXYFast(int x, int y) {
    return x + (y << 16);
}

// address=[0x130f460]
void __cdecl Y16X16::UnpackXYFast(int packed, int &x, int &y) {
    x = static_cast<unsigned short>(packed);
    y = packed >> 16;
}

// address=[0x15d7190]
int __cdecl Y16X16::XYNotNegative(int packed) {
    return (packed & 0x80008000) == 0;
    // int x = UnpackXFast(packed);
    // int y = UnpackYFast(packed);
    // if (x < 0 || y < 0)
    // {
    //     return FALSE;
    // }
    // return TRUE;
}


// address=[0x37D8C08]
SPoint g_sNeighborPoints[6] = {
    {1, 0},
    {1, 1},
    {0, 1},
    {-1, 0},
    {-1, -1},
    {0, -1},
};


// address=[0x37D8C38]
SPoint g_sNeighborOrthos[6] = {
    {0, 1},
    {-1, 1},
    {-1, 0},
    {0, -1},
    {1, -1},
    {1, 0},
};

// address=[0x037D8C68]
SPoint g_sSurroundingHexPoints[37] = {
    {0, 0},
    {1, 0},
    {1, 1},
    {0, 1},
    {-1, 0},
    {-1, -1},
    {0, -1},
    {2, 0},
    {2, 1},
    {2, 2},
    {1, 2},
    {0, 2},
    {-1, 1},
    {-2, 0},
    {-2, -1},
    {-2, -2},
    {-1, -2},
    {0, -2},
    {1, -1},
    {3, 0},
    {3, 1},
    {3, 2},
    {3, 3},
    {2, 3},
    {1, 3},
    {0, 3},
    {-1, 2},
    {-2, 1},
    {-3, 0},
    {-3, -1},
    {-3, -2},
    {-3, -3},
    {-2, -3},
    {-1, -3},
    {0, -3},
    {1, -2},
    {2, -1},
};
