#include "chata/Path.h"
#include <gtest/gtest.h>

TEST(Path, Combine)
{
    auto path = chata::Path::Combine("abc", "def");
    EXPECT_EQ(path, "abc/def");
}
