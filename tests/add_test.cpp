// tests.cpp
#include "../src/add.cpp"
#include <gtest/gtest.h>

TEST(SquareRootTest, add_test)
{
    std::unique_ptr<Add> s = std::make_unique<Add>();
    ASSERT_EQ(7, s->add(6, 1));
}
