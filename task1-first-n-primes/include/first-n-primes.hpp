#pragma once

#include <array>


template<typename ELEMTYPE, long unsigned int SIZE>
extern void fill_array_with_primes(std::array<ELEMTYPE, SIZE> & primes)
{
  std::array<ELEMTYPE, SIZE> tmp_primes;
  std::swap(primes, tmp_primes);
  return;
}
