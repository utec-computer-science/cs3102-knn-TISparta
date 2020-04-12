#include <iostream>

#include <gtest/gtest.h>

#include "../src/util/util.hpp"

typedef int value_t;

const value_t MIN_VAL = -100;
const value_t MAX_VAL = +100;

TEST(util, random_points_generation) {
  int n = 10;
  std::vector <Point <value_t>> points = util::generate_n_random_points <value_t> (n, MIN_VAL, MAX_VAL);
  for (auto point: points) {
    std::cout << point;
  }
}

int main (int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
