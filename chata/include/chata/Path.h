#pragma once
#include "chata/BaseDefines.h"
#include <string>
#include <string_view>

namespace chata
{
struct CHATA_API Path
{
    static std::string Combine(std::string_view lhs, std::string_view rhs);
};
} // namespace chata
