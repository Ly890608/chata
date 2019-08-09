#pragma once

#define CHATA_COMPILER_CLANG 0
#define CHATA_COMPILER_MSVC 0
#define CHATA_COMPILER_GCC 0

#if defined(__clang__)
#undef CHATA_COMPILER_CLANG
#define CHATA_COMPILER_CLANG 1
#elif defined(_MSC_VER)
#undef CHATA_COMPILER_MSVC
#define CHATA_COMPILER_MSVC 1
#elif defined(__GNUC__)
#undef CHATA_COMPILER_GCC
#define CHATA_COMPILER_GCC 1
#else
#error "Unknown COMPILER"
#endif