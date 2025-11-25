#include "statistics.hpp"
#include "gtest/gtest.h"

#include <stdexcept>

TEST(StatisticsTest, MeanEmptyVector) {
  const std::vector<double> data;
  EXPECT_THROW(
      {
        try {
          Statistics::mean(data);
        } catch (const std::runtime_error &exc) {
          EXPECT_STREQ("Input data is empty.", exc.what());

          throw;
        }
      },
      std::runtime_error);
}

TEST(StatisticsTest, FailingTestEmptyVector) {
  const std::vector<double> data;
  EXPECT_EQ(Statistics::mean(data), 0.0);
}

TEST(StatisticsTest, MeanSingleElement) {
  const std::vector<double> data = {5.0};
  EXPECT_EQ(Statistics::mean(data), 5.0);
}

TEST(StatisticsTest, MeanMultipleElements) {
  const std::vector<double> data = {1.0, 2.0, 3.0, 4.0, 5.0};
  EXPECT_EQ(Statistics::mean(data), 3.0);
}

TEST(StatisticsTest, MeanWithNegativeValues) {
  const std::vector<double> data = {-1.0, 2.0, -3.0, 4.0, -5.0};
  EXPECT_EQ(Statistics::mean(data), -0.6);
}

TEST(StatisticsTest, MeanZero) {
  const std::vector<double> data = {-5.0, -4.0, -3.0, -2.0, -1.0,
                                    1.0,  2.0,  3.0,  4.0,  5.0};
  EXPECT_EQ(Statistics::mean(data), 0.0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
