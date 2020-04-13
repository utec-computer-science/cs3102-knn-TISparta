#include <cmath>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <type_traits>

#include "../random/Random.hpp"
#include "../point/Point.hpp"

/*
 * Utility functions
 */
namespace util {

  /**
   * Generate a random point
   */
  template <typename value_t>
  static Point <value_t> generate_random_point (const value_t min_val, const value_t max_val) {
    value_t x = Random::generate_value <value_t> (min_val, max_val);
    value_t y = Random::generate_value <value_t> (min_val, max_val);
    return Point <value_t> (x, y);
  }

  /*
   * Generate n random points
   */
  template <typename value_t>
  static std::vector <Point <value_t>> generate_n_random_points (const int n,
                                                                 const value_t min_val,
                                                                 const value_t max_val) {
    if (n < 0) {
      throw std::out_of_range("n points must be non negative");
    }
    std::vector <Point <value_t>> points(n);
    for (int i = 0; i < n; i++) {
      points[i] = generate_random_point <value_t> (min_val, max_val);
    }
    return points;
  }

  /*
   * Find the k-nearest neighbors of point center
   */
  template <typename Point>
  static std::vector <Point> knn (int k,
                                  std::vector <Point> points,
                                  Point center,
                                  auto getter) {
    using value_t = double;
    int n = points.size();
    std::vector <std::pair <value_t, int>> dist_index(n);
    for (int i = 0; i < n; i++) {
      value_t x = getter(points[i]).first;
      value_t y = getter(points[i]).second;
      // sqrt is a increasing function, then there is not necessary to compute
      // it to compare the distances
      value_t d = std::pow(x - getter(center).first, 2) + 
                  std::pow(y - getter(center).second, 2); 
      dist_index[i] = {d, i};
    }
    std::sort(std::begin(dist_index), std::end(dist_index));
    k = std::min(k, n);
    std::vector <Point> ret(k);
    for (int i = 0; i < k; i++) {
      ret[i] = points[dist_index[i].second];
    }
    return ret;
  }
};
