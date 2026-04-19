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

// address=[0x1568700]
// Decompiled from int __cdecl Y16X16::DeltaXFast(int x, int a2)
int __cdecl Y16X16::DeltaXFast(int x, int a2) {
    return (unsigned __int16) a2 - (unsigned __int16) x;
}


// address=[0x1568720]
// Decompiled from int __cdecl Y16X16::DeltaYFast(int this, int a2)
int __cdecl Y16X16::DeltaYFast(int a1, int a2) {
    return (a2 >> 16) - (a1 >> 16);
}


// address=[0x1568740]
// Decompiled from int __cdecl Y16X16::DirectionFast(int x, int y)
int __cdecl Y16X16::DirectionFast(int x, int y) {
    int v3; // [esp+0h] [ebp-8h]
    int v4; // [esp+4h] [ebp-4h]

    v3 = Y16X16::DeltaXFast(x, y);
    v4 = Y16X16::DeltaYFast(x, y);
    return Grid::DirectionFast(v3, v4);
}


// address=[0x1592da0]
// Decompiled from int __cdecl Y16X16::DistanceFast(int _iAXY, int _iBXY)
int __cdecl Y16X16::DistanceFast(int _iAXY, int _iBXY) {
    int v3; // [esp+0h] [ebp-8h]
    int v4; // [esp+4h] [ebp-4h]

    v3 = Y16X16::DeltaXFast(_iAXY, _iBXY);
    v4 = Y16X16::DeltaYFast(_iAXY, _iBXY);
    return Grid::Distance(v3, v4);
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
