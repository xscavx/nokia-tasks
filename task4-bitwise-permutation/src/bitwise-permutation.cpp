#include "bitwise-permutation.hpp"
#include <bitset>


using std::size_t, std::uint8_t, std::uint32_t;
constexpr std::size_t INT32_BITS{32};

std::pair<uint32_t, uint32_t> permutation_for_min_max(uint32_t source_number) {
  std::bitset<INT32_BITS> const source_bitset{source_number};
  std::bitset<INT32_BITS> result_bitset;
  size_t const source_high_count = source_bitset.count();

  for (uint8_t hb = 0; hb < source_high_count; ++hb) {
    result_bitset.set(hb);
  }

  uint32_t const result_min = result_bitset.to_ulong();
  result_bitset <<= (INT32_BITS - source_high_count);
  uint32_t const result_max = result_bitset.to_ulong();
  return {result_min, result_max};
}
