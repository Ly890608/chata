#include "chata/String.h"
#include <gtest/gtest.h>

TEST(String, Split)
{
    auto sp = chata::String::Split("abc.edf", ".");
    EXPECT_EQ(sp[0], "abc");
    EXPECT_EQ(sp[1], "edf");
}
