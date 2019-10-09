#include "chata/String.h"

namespace chata
{
std::vector<string_view> String::Split(string_view str, string_view delims)
{
    std::vector<string_view> output;
    size_t first = 0;

    while (first < str.size())
    {
        const auto second = str.find_first_of(delims, first);

        if (first != second)
            output.emplace_back(str.substr(first, second - first));

        if (second == string_view::npos)
            break;

        first = second + 1;
    }

    return output;
}
} // namespace chata
