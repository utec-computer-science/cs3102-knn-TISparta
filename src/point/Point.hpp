#pragma once

#include <iostream>

#include "../random/Random.hpp"

template <typename T>
class Point {
public:
  Point () {}
  Point (T x, T y): x(x), y(y) {}
  ~Point () {}
  T get_x () const { return x; }
  T get_y () const { return y; }

  friend std::ostream& operator << (std::ostream& stream, const Point& point) {
    stream << '(' << point.x << ',' << point.y << ')' << '\n';
    stream << std::flush;
  }

private:
  T x;
  T y;
};
