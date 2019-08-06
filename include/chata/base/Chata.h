#pragma once
#include "chata/base/PlatformMacros.h"

#if CHATA_PLATFORM_ANDROID
#	define CHATA_DLLEXPORT	__attribute__((visibility("default")))
#	define CHATA_DLLIMPORT	__attribute__((visibility("default")))
#elif CHATA_PLATFORM_IOS
#	define CHATA_DLLEXPORT
#	define CHATA_DLLIMPORT
#elif CHATA_PLATFORM_WINDOWS
#	define CHATA_DLLEXPORT	__declspec(dllexport)
#	define CHATA_DLLIMPORT	__declspec(dllimport)
#endif

#ifndef CHATA_EXPORT
#	define CHATA_API		CHATA_DLLIMPORT
#else
#	define CHATA_API		CHATA_DLLEXPORT
#endif

namespace chata
{
	struct Module
	{
		CHATA_API static const char* Name();
	};
}