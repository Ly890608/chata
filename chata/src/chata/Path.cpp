#include "chata/Path.h"

namespace chata
{
std::string Path::Combine(std::string_view lhs, std::string_view rhs)
{
    std::string result;
    const bool sp = lhs.empty() ? false : lhs.back() == '/' || lhs.back() == '\\';
    result.reserve(lhs.size() + rhs.size() + (sp ? 1 : 0));
    result += lhs;
    if (!sp)
        result += '/';
    result += rhs;
    return std::move(result);
}
} // namespace chata
