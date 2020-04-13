#include <iostream>
#include <utility>

#include <gtest/gtest.h>

#include "../src/util/util.hpp"

using value_t = int;
const value_t MIN_VAL = -100;
const value_t MAX_VAL = +100;

auto getter = [&] (Point <value_t> point) -> std::pair <value_t, value_t> {
  return {point.get_x(), point.get_y()};
};

TEST(util, random_points_generation) {
  const int n = 10;
  std::vector <Point <value_t>> points = util::generate_n_random_points <value_t> (n, MIN_VAL, MAX_VAL);
  for (auto point: points) {
    std::cout << point;
  }
}

TEST(util, negative_argument_in_n_points) {
  const int n = -1;
  EXPECT_ANY_THROW({
      std::vector <Point <value_t>> points = util::generate_n_random_points <value_t> (n, MIN_VAL, MAX_VAL);
  });
}

TEST(util, knn_test_1) {
  const int n = 5;
  std::vector <Point <value_t>> points(n);
  points[0] = Point <value_t> (0, 0);
  points[1] = Point <value_t> (1, 1);
  points[2] = Point <value_t> (2, 2);
  points[3] = Point <value_t> (3, 3);
  points[4] = Point <value_t> (4, 4);
  const int k = 3;
  Point <value_t> center(2, 2);
  std::vector <Point <value_t>> knn = util::knn(k, points, center, getter);
  for (auto p: knn) {
    std::cout << p;
  }
}

TEST(util, knn_test_2) {
  const int n = 5;
  std::vector <Point <value_t>> points(n);
  points[0] = Point <value_t> (0, 0);
  points[1] = Point <value_t> (1, 1);
  points[2] = Point <value_t> (2, 2);
  points[3] = Point <value_t> (3, 3);
  points[4] = Point <value_t> (4, 4);
  const int k = 3;
  Point <value_t> center(5, 5);
  std::vector <Point <value_t>> knn = util::knn(k, points, center, getter);
  for (auto p: knn) {
    std::cout << p;
  }
}


int main (int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
