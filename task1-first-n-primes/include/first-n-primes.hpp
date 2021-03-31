#pragma once

#include <array>


template<typename ELEMTYPE, std::size_t SIZE>
extern void fill_array_with_primes(std::array<ELEMTYPE, SIZE> & primes) {
  std::array<ELEMTYPE, SIZE> tmp_primes;
  tmp_primes.fill(0);

  ELEMTYPE num = 1;
  while (!tmp_primes.back()) {
    ++num;
    for (ELEMTYPE& prime : tmp_primes) {
      if (!prime)
      {
        prime = num;
        break;
      }
      else if (num % prime == 0) {
        break;
      }
    }
  }

  std::swap(primes, tmp_primes);
  return;
}
