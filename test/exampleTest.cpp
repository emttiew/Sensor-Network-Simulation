#include <gtest/gtest.h>

int add(int a, int b) {
    return a + b;
}

TEST(AddTest, PositiveNumbers) {
    EXPECT_EQ(add(2, 3), 5);
}