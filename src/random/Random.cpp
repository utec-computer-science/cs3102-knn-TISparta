#include "Random.hpp"

template <typename T>
T Random::generate (const T min_val, const T max_val) {
  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution <T> distribution(min_val, max_val);
  return distribution(rng);
}

char Random::generate_char () {
  std::mt19937 rng;
  rng.seed(std::random_device()());
  int increment = generate <int> (0, 52) % 26;
  return 'a' + increment;
}
