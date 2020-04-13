#pragma once

#include <iostream>

#include "../random/Random.hpp"

template <typename value_t>
class Point {
public:
  Point () {}
  Point (value_t x, value_t y): x(x), y(y) {}
  ~Point () {}
  value_t get_x () const { return x; }
  value_t get_y () const { return y; }

  friend std::ostream& operator << (std::ostream& stream, const Point <value_t> & point) {
    stream << '(' << point.x << ',' << point.y << ')' << '\n';
    stream << std::flush;
  }

private:
  value_t x;
  value_t y;
};
