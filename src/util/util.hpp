#include <cmath>
#include <stdexcept>
#include <utility>
#include <algorithm>

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
  template <typename value_t>
  static std::vector <Point <value_t>> knn (int k,
                                            std::vector <Point <value_t>> points,
                                            Point <value_t> center) {
    int n = points.size();
    std::vector <std::pair <value_t, int>> dist_index(n);
    for (int i = 0; i < n; i++) {
      value_t x = points[i].get_x();
      value_t y = points[i].get_y();
      value_t d = std::pow(x - center.get_x(), 2) + std::pow(y - center.get_y(), 2); 
      dist_index[i] = {d, i};
    }
    std::sort(std::begin(dist_index), std::end(dist_index));
    k = std::min(k, n);
    std::vector <Point <value_t>> ret(k);
    for (int i = 0; i < k; i++) {
      ret[i] = points[dist_index[i].second];
    }
    return ret;
  }
};
