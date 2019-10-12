#include "chata/String.h"
#include <gtest/gtest.h>

TEST(String, Split)
{
    auto result = chata::String::Split(".abc.edf.123456..", ".");
    EXPECT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "abc");
    EXPECT_EQ(result[1], "edf");
    EXPECT_EQ(result[2], "123456");
}

TEST(String, Split_MultyDelims)
{
    auto result = chata::String::Split(".abc+edf/.123456..", "./+");
    EXPECT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "abc");
    EXPECT_EQ(result[1], "edf");
    EXPECT_EQ(result[2], "123456");
}
