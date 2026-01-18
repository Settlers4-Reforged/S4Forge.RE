#include "helper.h"

// address=[0x1307190]
int __cdecl Y16X16::UnpackXFast(int packed)
{
    return static_cast<unsigned short>(packed);
}

// address=[0x13071a0]
int __cdecl Y16X16::UnpackYFast(int packed)
{
    return packed >> 16;
}

// address=[0x130f2a0]
int __cdecl Y16X16::PackXYFast(int x, int y)
{
    return x + (y << 16);
}

// address=[0x130f460]
void __cdecl Y16X16::UnpackXYFast(int packed, int &x, int &y)
{
    x = static_cast<unsigned short>(packed);
    y = packed >> 16;
}

// address=[0x15d7190]
int __cdecl Y16X16::XYNotNegative(int packed)
{
    int x = UnpackXFast(packed);
    int y = UnpackYFast(packed);
    if (x < 0 || y < 0)
    {
        return -1;
    }
}