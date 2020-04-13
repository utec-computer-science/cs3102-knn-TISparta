#include <fstream>
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

#include "../src/util/util.hpp"

const std::string FILE_NAME = "input.in";

using value_t = float;

const int K = 1000;
const int MIN_VALUE = -1000;
const int MAX_VALUE = +1000;

int main () {
  // reading
  std::fstream file;
  file.open(FILE_NAME, std::ios::in);
  int n;
  file >> n;
  std::vector <Point <value_t>> points(n);
  for (int i = 0; i < n; i++) {
    value_t x, y, z;
    file >> x >> y >> z;
    points[i] = Point <value_t> (x, y);
  }
  file.close();
  // declaring a getter function
  auto getter = [&] (Point <value_t> point) -> std::pair <value_t, value_t> {
    return {point.get_x(), point.get_y()};
  };
  // defining the center of knn
  Point <value_t> center = util::generate_random_point <value_t> (MIN_VALUE, MAX_VALUE);
  // finding knn
  auto start = std::chrono::high_resolution_clock::now();
  std::vector <Point <value_t>> knn = util::knn(K, points, center, getter);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast <std::chrono::microseconds> (stop - start);
  std::cout << "Time: " << duration.count() << std::endl;
  std::cout << "KNN: " << std::endl;
  for (auto point: knn) {
    std::cout << point;
  }
  return (0);
}
