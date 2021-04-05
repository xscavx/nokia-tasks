#pragma once

#include <array>


template<typename ELEMTYPE, std::size_t SIZE>
void fill_array_with_primes(std::array<ELEMTYPE, SIZE> & primes) {
  primes.fill(0);

  ELEMTYPE num = 1;
  while (!primes.back()) {
    ++num;
    for (ELEMTYPE& prime : primes) {
      if (!prime) {
        prime = num;
        break;
      }
      else if (num % prime == 0) {
        break;
      }
    }
  }

  return;
}
