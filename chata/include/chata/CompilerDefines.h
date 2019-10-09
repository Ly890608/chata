#pragma once
#ifndef CHATA_COMPILERDEFINES_H
#define CHATA_COMPILERDEFINES_H

#if defined(__ANDROID__)
#define CHATA_PLATFORM_ANDROID
#elif defined(__APPLE__)
#define CHATA_PLATFORM_APPLE
#elif defined(_WIN32) || defined(_WIN64)
#define CHATA_PLATFORM_WINDOWS
#elif defined(__EMSCRIPTEN__)
#define CHATA_PLATFROM_WEB
#endif

#if defined(CHATA_PLATFORM_WINDOWS)
#define CHATA_DLLEXPORT __declspec(dllexport)
#define CHATA_DLLIMPORT __declspec(dllimport)
#define CHATA_FORCEINLINE __forceinline
#else
#define CHATA_DLLEXPORT __attribute__((visibility("default")))
#define CHATA_DLLIMPORT
#define CHATA_FORCEINLINE __attribute__((always_inline))
#endif

#if defined(CHATA_STATIC)
#define CHATA_API
#else
#if defined(CHATA_EXPORT)
#define CHATA_API CHATA_DLLEXPORT
#else
#define CHATA_API CHATA_DLLIMPORT
#endif
#endif

#endif
