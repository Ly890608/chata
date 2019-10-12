#include "chata/String.h"
#include <gtest/gtest.h>

TEST(String, Split)
{
    auto sp = chata::String::Split(".abc.edf.123456..", ".");
    EXPECT_EQ(sp.size(), 3);
    EXPECT_EQ(sp[0], "abc");
    EXPECT_EQ(sp[1], "edf");
    EXPECT_EQ(sp[2], "123456");
}

TEST(String, Split_MultyDelims)
{
    auto sp = chata::String::Split(".abc+edf/.123456..", "./+");
    EXPECT_EQ(sp.size(), 3);
    EXPECT_EQ(sp[0], "abc");
    EXPECT_EQ(sp[1], "edf");
    EXPECT_EQ(sp[2], "123456");
}
