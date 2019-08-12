#pragma once

namespace chata
{
template <typename T>
constexpr T gE = static_cast<T>(2.71828182845904523536); // e
template <typename T>
constexpr T gLog2E = static_cast<T>(1.44269504088896340736); // log2(e)
template <typename T>
constexpr T gLog10E = static_cast<T>(0.434294481903251827651); // log10(e)
template <typename T>
constexpr T gLn2 = static_cast<T>(0.693147180559945309417); // ln(2)
template <typename T>
constexpr T gLn10 = static_cast<T>(2.30258509299404568402); // ln(10)
template <typename T>
constexpr T gPI = static_cast<T>(3.14159265358979323846); // pi
template <typename T>
constexpr T gHalfPI = static_cast<T>(1.57079632679489661923); // pi/2
template <typename T>
constexpr T gQuarterPI = static_cast<T>(0.785398163397448309616); // pi/4
template <typename T>
constexpr T gInvPI = static_cast<T>(0.318309886183790671538); // 1/pi
template <typename T>
constexpr T gTwoInvPI = static_cast<T>(0.636619772367581343076); // 2/pi
template <typename T>
constexpr T gTwoInvSqrtPI =
    static_cast<T>(1.12837916709551257390); // 2/sqrt(pi)
template <typename T>
constexpr T gSqrt2 = static_cast<T>(1.41421356237309504880); // sqrt(2)
template <typename T>
constexpr T gInvSqrt2 = static_cast<T>(0.707106781186547524401); // 1/sqrt(2)

template <typename T>
constexpr T gDegreesToRadians = static_cast<T>(3.14159265358979323846) /
                                static_cast<T>(180.0);
template <typename T>
constexpr T gRadiansToDegrees = static_cast<T>(180.0) /
                                static_cast<T>(3.14159265358979323846);
} // namespace chata

/* MATH_DEFINES */
#ifndef CHATA_MATH_DEFINES_TYPE
#define CHATA_MATH_DEFINES_TYPE float
#endif

#ifndef M_E
#define M_E chata::gE<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_LOG2E
#define M_LOG2E chata::gLog2E<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_LOG10E
#define M_LOG10E chata::gLog10E<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_LN2
#define M_LN2 chata::gLn2<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_LN10
#define M_LN10 chata::gLn10<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_PI
#define M_PI chata::gPI<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_PI_2
#define M_PI_2 chata::gHalfPI<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_PI_4
#define M_PI_4 chata::gQuarterPI<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_1_PI
#define M_1_PI chata::gInvPI<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_2_PI
#define M_2_PI chata::gTwoInvPI<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_2_SQRTPI
#define M_2_SQRTPI chata::gTwoInvSqrtPI<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_SQRT2
#define M_SQRT2 chata::gSqrt2<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_SQRT1_2
#define M_SQRT1_2 chata::gInvSqrt2<CHATA_MATH_DEFINES_TYPE>
#endif