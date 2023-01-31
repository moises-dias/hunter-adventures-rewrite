// SubtractTest.cpp
#include "../src/subtract.cpp"
#include "gtest/gtest.h"

TEST(SubtractTest, SubtractTwoNumbers)
{
    std::unique_ptr<Subtract> s = std::make_unique<Subtract>();
    ASSERT_EQ(5, s->subtract(6, 1));
}