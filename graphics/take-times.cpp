#include <fstream>
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

#include "../src/util/util.hpp"

const std::string FILE_NAME = "data.in";

using value_t = float;
const value_t MIN_VAL = -100000;
const value_t MAX_VAL = +100000;

auto simulate (int n) {
  std::vector <Point <value_t>> points = util::generate_n_random_points(n, MIN_VAL, MAX_VAL);
  // declaring a getter function
  auto getter = [&] (Point <value_t> point) -> std::pair <value_t, value_t> {
    return {point.get_x(), point.get_y()};
  };
  // defining the center of knn
  Point <value_t> center = util::generate_random_point(MIN_VAL, MAX_VAL);
  // finding knn
  const int k = Random::generate_value <int> (0, n);
  auto start = std::chrono::high_resolution_clock::now();
  std::vector <Point <value_t>> knn = util::knn(k, points, center, getter);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast <std::chrono::microseconds> (stop - start);
  return duration.count();
}

int main () {
  // reading
  std::ofstream file;
  file.open(FILE_NAME, std::ios::out | std::ios::trunc);
  const int N = 1e6;
  const int ITERATIONS = 5;
  int n = 1;
  while (n <= N) {
    file << n;
    for (int it = 0; it < ITERATIONS; it++) {
      file << ' ' << simulate(n);
    }
    file << '\n';
    file.flush();
    int log = std::log10(n);
    n += pow(10, log);
  }
  file.close();
  return (0);
}
