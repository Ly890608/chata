#pragma once
#include "chata/BaseDefines.h"
#include <string_view>
#include <vector>

namespace chata
{
struct CHATA_API String
{
    static std::vector<std::string_view> Split(std::string_view str, std::string_view delims = " ");
};
} // namespace chata
