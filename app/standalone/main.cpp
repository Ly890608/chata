#include "chata/system/Process.h"

int main()
{
    void *opengl = chata::Process::GetLibrary("opengl32.dll");
    return 0;
}