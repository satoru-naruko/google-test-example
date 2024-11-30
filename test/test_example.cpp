#include <gtest/gtest.h>
#include "../src/add.h"

TEST(AdditionTest, HandlesPositiveInput) {
   EXPECT_EQ(add(1, 2), 3);
}

TEST(AdditionTest, HandlesNegativeInput) {
   EXPECT_EQ(add(-1, -1), -2);
}

TEST(AdditionTest, HandlesMixedInput) {
   EXPECT_EQ(add(-1, 1), 0);
}
