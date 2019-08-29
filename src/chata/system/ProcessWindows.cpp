#include "chata/system/Process.h"
#include "chata/windows/MinWindows.h"

namespace chata
{
void *Process::GetLibrary(const char *name)
{
    return ::LoadLibraryA(name);
}

void Process::FreeLibrary(void *handle)
{
    ::FreeLibrary((HMODULE)handle);
}
} // namespace chata