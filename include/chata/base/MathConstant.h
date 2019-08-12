#pragma once

namespace chata
{
template <typename T>
constexpr T kE = static_cast<T>(2.71828182845904523536); // e
template <typename T>
constexpr T kLog2E = static_cast<T>(1.44269504088896340736); // log2(e)
template <typename T>
constexpr T kLog10E = static_cast<T>(0.434294481903251827651); // log10(e)
template <typename T>
constexpr T kLn2 = static_cast<T>(0.693147180559945309417); // ln(2)
template <typename T>
constexpr T kLn10 = static_cast<T>(2.30258509299404568402); // ln(10)
template <typename T>
constexpr T kPI = static_cast<T>(3.14159265358979323846); // pi
template <typename T>
constexpr T kHalfPI = static_cast<T>(1.57079632679489661923); // pi/2
template <typename T>
constexpr T kQuarterPI = static_cast<T>(0.785398163397448309616); // pi/4
template <typename T>
constexpr T kInvPI = static_cast<T>(0.318309886183790671538); // 1/pi
template <typename T>
constexpr T kTwoInvPI = static_cast<T>(0.636619772367581343076); // 2/pi
template <typename T>
constexpr T kTwoInvSqrtPI =
    static_cast<T>(1.12837916709551257390); // 2/sqrt(pi)
template <typename T>
constexpr T kSqrt2 = static_cast<T>(1.41421356237309504880); // sqrt(2)
template <typename T>
constexpr T kInvSqrt2 = static_cast<T>(0.707106781186547524401); // 1/sqrt(2)

template <typename T>
constexpr T kDegreesToRadians = static_cast<T>(3.14159265358979323846) /
                                static_cast<T>(180.0);
template <typename T>
constexpr T kRadiansToDegrees = static_cast<T>(180.0) /
                                static_cast<T>(3.14159265358979323846);
} // namespace chata

/* MATH_DEFINES */
#ifndef CHATA_MATH_DEFINES_TYPE
#define CHATA_MATH_DEFINES_TYPE float
#endif

#ifndef M_E
#define M_E chata::kE<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_LOG2E
#define M_LOG2E chata::kLog2E<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_LOG10E
#define M_LOG10E chata::kLog10E<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_LN2
#define M_LN2 chata::kLn2<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_LN10
#define M_LN10 chata::kLn10<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_PI
#define M_PI chata::kPI<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_PI_2
#define M_PI_2 chata::kHalfPI<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_PI_4
#define M_PI_4 chata::kQuarterPI<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_1_PI
#define M_1_PI chata::kInvPI<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_2_PI
#define M_2_PI chata::kTwoInvPI<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_2_SQRTPI
#define M_2_SQRTPI chata::kTwoInvSqrtPI<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_SQRT2
#define M_SQRT2 chata::kSqrt2<CHATA_MATH_DEFINES_TYPE>
#endif

#ifndef M_SQRT1_2
#define M_SQRT1_2 chata::kInvSqrt2<CHATA_MATH_DEFINES_TYPE>
#endif