#include "MapObjects/SPoint.h"

namespace Y16X16
{
    // address=[0x1307190]
    int __cdecl UnpackXFast(int);

    // address=[0x13071a0]
    int __cdecl UnpackYFast(int);

    // address=[0x130f2a0]
    int __cdecl PackXYFast(int, int);

    // address=[0x130f460]
    void __cdecl UnpackXYFast(int, int &, int &);

    // address=[0x15d7190]
    int __cdecl XYNotNegative(int);
} // namespace Y16X16

namespace Grid
{
    // address=[0x13066c0]
    bool __cdecl InQuadrat(int, int, int);

    // address=[0x15dc4b0]
    int __cdecl Direction(int, int);

    // address=[0x15dc4d0]
    int __cdecl Direction(float, float);

    // address=[0x15dc500]
    int __cdecl DirectionFast(int, int);

    // address=[0x15dc520]
    int __cdecl DirectionFast(float, float);

    // address=[0x15dc550]
    int __cdecl Area(int, int);

    // address=[0x15dc620]
    int __cdecl AreaFast(int, int);

    // address=[0x15dc6a0]
    int __cdecl Distance(int, int);

    // address=[0x15dc700]
    float __cdecl Distance(float, float);

    // address=[0x15ddbe0]
    int __cdecl Distance(struct SPoint const &, struct SPoint const &);

    // address=[0x15ddc10]
    int __cdecl Distance(struct SPoint const &);

    // address=[0x130ea40]
    int __cdecl Distance(int, int, int, int);

    // address=[0x130ea70]
    int __cdecl DistanceInline(int, int);
    // address=[0x141db20]
    int __cdecl TurnLeft(int);

    // address=[0x141db60]
    int __cdecl TurnRight(int);
} // namespace Grid

namespace Squares
{
    // address=[0x1306b00]
    int __cdecl XYToVW(int);

    // address=[0x130f4d0]
    bool __cdecl ValidVW(int);

    // address=[0x131ca50]
    int __cdecl VWToXY(int);

    // address=[0x131ca60]
    bool __cdecl ValidVW(int, int);
} // namespace Squares
