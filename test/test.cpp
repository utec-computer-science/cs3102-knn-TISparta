#include <iostream>

#include <gtest/gtest.h>

#include "../src/util/util.hpp"

typedef int T;

const T MIN_VAL = -100;
const T MAX_VAL = +100;

TEST(CNN, test1) {
  Point <T> p = util::generate_random_point(MIN_VAL, MAX_VAL); 
  std::cout << p;
}

int main (int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
