#pragma once
#include "chata/BaseDefines.h"
#include <string>
#include <string_view>
#include <vector>

namespace chata
{
using std::string;
using std::string_view;
using namespace std::literals;

struct CHATA_API String
{
    static std::vector<string_view> Split(string_view str, string_view delims = " ");
};
} // namespace chata
