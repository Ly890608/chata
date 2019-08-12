#pragma once
#include "chata/base/Export.h"
#include "chata/base/MathConstant.h"

namespace chata
{
constexpr float DegreesToRadians(const float degrees)
{
    return degrees * gDegreesToRadians<float>;
}

constexpr float RadiansToDegrees(const float radians)
{
    return radians * gRadiansToDegrees<float>;
}

CHATA_API float Test(float a);
} // namespace chata