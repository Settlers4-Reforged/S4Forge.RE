#include "helper.h"
#include "defines.h"
#include "MapObjects/SPoint.h"

// address=[0x13066c0]
bool __cdecl Grid::InQuadrat(int grid, int a2, int a3)
{
    int v4; // [esp+4h] [ebp-8h]
    int v5; // [esp+8h] [ebp-4h]

    if (grid < a3)
        v5 = -1;
    else
        v5 = 0;
    if (a2 < a3)
        v4 = -1;
    else
        v4 = 0;
    return (v4 & v5) != 0;
}

// address=[0x15dc4b0]
int __cdecl Grid::Direction(int x, int y)
{
    int v3;  // [esp+8h] [ebp-20h]
    int dx;  // [esp+20h] [ebp-8h]
    int sum; // [esp+24h] [ebp-4h]

    dx = x - y;
    sum = y + x;
    v3 = y + x < 0 || x - y < 0 && y + x == 0;
    if (!v3)
        return 3 * v3 + (2 * dx <= -sum) + (2 * dx <= sum);
    dx = y - x;
    sum = -sum;
    return 3 * v3 + (2 * dx <= -sum) + (2 * dx <= sum);
}

// address=[0x15dc4d0]
int __cdecl Grid::Direction(float x, float y)
{
    float v3;  // [esp+8h] [ebp-20h]
    float dx;  // [esp+20h] [ebp-8h]
    float sum; // [esp+24h] [ebp-4h]

    dx = x - y;
    sum = y + x;
    v3 = y + x < 0.0 || x - y < 0.0 && y + x == 0.0;
    if (!v3)
        return 3.0 * v3 + (2.0 * dx <= -sum) + (2.0 * dx <= sum);
    dx = y - x;
    sum = -sum;
    return 3.0 * v3 + (2.0 * dx <= -sum) + (2.0 * dx <= sum);
}

const int DIRECTION_LUT[8] = {
    0,
    1,
    2,
    2,
    5,
    3,
    4,
    3,
};

// address=[0x15dc500]
int __cdecl Grid::DirectionFast(int a1, int a2)
{
    return DIRECTION_LUT[(a1 <= 2 * a2) | (2 * (2 * a1 <= a2)) | (4 * (a1 < -a2))];
}

// address=[0x15dc520]
int __cdecl Grid::DirectionFast(float a1, float a2)
{
    return DIRECTION_LUT[(a1 <= 2.0 * a2) | (2 * (2.0 * a1 <= a2)) | (4 * (a1 < -a2))];
}

// address=[0x15dc550]
int __cdecl Grid::Area(int width, int height)
{
    int v3; // [esp+8h] [ebp-18h]

    if (height == 0 && width == 0)
        return 0;
    v3 = height < 0 || width < 0 && height == 0;
    if (!v3)
        return 3 * v3 + (width <= height) + (width <= 0);
    width = -width;
    height = -height;
    return 3 * v3 + (width <= height) + (width <= 0);
}

// address=[0x15dc620]
int __cdecl Grid::AreaFast(int, int)
{
    return 0; // not used(?)
}

// address=[0x15dc6a0]
int __cdecl Grid::Distance(int a1, int a2)
{
    int v3;     // [esp+0h] [ebp-8h]
    int Number; // [esp+10h] [ebp+8h]
    int v6;     // [esp+14h] [ebp+Ch]

    v3 = a2 ^ a1;
    Number = std::abs(a1);
    v6 = std::abs(a2);
    if (v3 < 0)
        return v6 + Number;
    else
        return std::max(Number, v6);
}

// address=[0x15dc700]
float __cdecl Grid::Distance(float, float)
{
    return 0; // not used(?)
}

// address=[0x15ddbe0]
int __cdecl Grid::Distance(struct SPoint const &a, struct SPoint const &b)
{
    return Grid::Distance(b.x - a.x, b.y - a.y);
}

// address=[0x15ddc10]
int __cdecl Grid::Distance(struct SPoint const &pos)
{
    return Grid::Distance(pos.x, pos.y);
}

// address=[0x130ea40]
int __cdecl Grid::Distance(int x1, int y1, int x2, int y2)
{
    return Grid::Distance(x2 - x1, y2 - y1);
}

// address=[0x130ea70]
int __cdecl Grid::DistanceInline(int a1, int a2)
{
    // Probably a version with inline keyword, lets just ignore it
    return Grid::Distance(a1, a2);
}

// address=[0x141db20]
int __cdecl Grid::TurnLeft(int pos)
{
    int dir; // [esp+0h] [ebp-4h]

    if (pos)
        dir = 0;
    else
        dir = 6;
    return pos + dir - 1;
}

// address=[0x141db60]
int __cdecl Grid::TurnRight(int pos)
{
    return pos == 5 ? 0 : pos + 1;
}