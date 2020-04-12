#pragma once

#include <random>
#include <type_traits>

class Random {
public:
  template <typename T>
  static T generate_value (const T min_val, const T max_val) {
    if (std::is_same <T, int>::value) {
      return generate <T> (min_val, max_val);
    }
    if (std::is_same <T, float>::value) {
      return generate <T> (min_val, max_val);
    }
    if (std::is_same <T, double>::value) {
      return generate <T> (min_val, max_val);
    }
    if (std::is_same <T, char>::value) {
      return generate_char();
    }
    throw "Data type not supported";
  }

private:
  template <typename T>
  static T generate (const T min_val, const T max_val);
  static char generate_char ();
};
