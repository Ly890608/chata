#include "chata/String.h"

namespace chata
{
std::vector<std::string_view> String::Split(std::string_view str, std::string_view delims)
{
    std::vector<std::string_view> result;
    size_t first = 0;

    while (first < str.size())
    {
        const auto second = str.find_first_of(delims, first);

        if (first != second)
            result.emplace_back(str.substr(first, second - first));

        if (second == std::string_view::npos)
            break;

        first = second + 1;
    }

    result.shrink_to_fit();
    return std::move(result);
}
} // namespace chata
