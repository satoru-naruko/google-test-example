#include <gtest/gtest.h>

// Global setup
class GlobalEnvironment : public ::testing::Environment {
public:
   void SetUp() override {
       // Code for global setup
   }

   void TearDown() override {
       // Code for global teardown
   }
};

int main(int argc, char **argv) {
   ::testing::InitGoogleTest(&argc, argv);
   ::testing::AddGlobalTestEnvironment(new GlobalEnvironment);
   return RUN_ALL_TESTS();
}