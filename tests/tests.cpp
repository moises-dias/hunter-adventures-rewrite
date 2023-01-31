// // tests.cpp
// #include "../src/whattotest.cpp"
// #include "../src/subtract.cpp"
// #include "../src/add.cpp"
// #include <gtest/gtest.h>
 
// TEST(SquareRootTest, PositiveNos) { 
//     ASSERT_EQ(6, squareRoot(36.0));
//     ASSERT_EQ(18.0, squareRoot(324.0));
//     ASSERT_EQ(25.4, squareRoot(645.16));
//     ASSERT_EQ(0, squareRoot(0.0));
// }
 
// TEST(SquareRootTest, NegativeNos) {
//     ASSERT_EQ(-1.0, squareRoot(-15.0));
//     ASSERT_EQ(-1.0, squareRoot(-0.2));
// }

// TEST(SquareRootTest, SubtractTwoNumbers)
// {
//     std::unique_ptr<Subtract> s = std::make_unique<Subtract>();
//     ASSERT_EQ(5, s->subtract(6, 1));
// }

// TEST(SquareRootTest, add_test)
// {
//     std::unique_ptr<Add> s = std::make_unique<Add>();
//     ASSERT_EQ(7, s->add(6, 1));
// }
 
// int main(int argc, char **argv) {
//     // cout 
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }

// AllTests.cpp
#include "gtest/gtest.h"
#include "subtract_test.cpp"
#include "add_test.cpp"

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}