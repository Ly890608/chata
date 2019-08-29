#pragma once
#include "chata/base/Export.h"
#include "chata/base/MathConstant.h"

namespace chata
{
inline constexpr float DegreesToRadians(const float degrees)
{
    return degrees * gDegreesToRadians<float>;
}

inline constexpr float RadiansToDegrees(const float radians)
{
    return radians * gRadiansToDegrees<float>;
}
} // namespace chata