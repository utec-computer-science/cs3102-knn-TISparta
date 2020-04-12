#include "../random/Random.hpp"
#include "../point/Point.hpp"

namespace util {

  template <typename value_t>
  static Point <value_t> generate_random_point (const value_t min_val, const value_t max_val) {
    value_t x = Random::generate_value <value_t> (min_val, max_val);
    value_t y = Random::generate_value <value_t> (min_val, max_val);
    return Point <value_t> (x, y);
  }
};
