#pragma once
#include "chata/base/Export.h"

namespace chata
{
struct CHATA_API Process
{
    static void *GetLibrary(const char *name);
    static void FreeLibrary(void *handle);
};
} // namespace chata