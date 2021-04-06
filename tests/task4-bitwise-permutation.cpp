#include <gtest/gtest.h>
#include <bitwise-permutation.hpp>


class BitwisePermutation : public testing::Test {
};

TEST(BitwisePermutation, Simpliest) {
  using std::uint32_t;
  auto res = permutation_for_min_max(0b0);
  EXPECT_EQ(res, std::pair(uint32_t{0}, uint32_t{0}));

  res = permutation_for_min_max(0b1);
  EXPECT_EQ(res, std::pair(uint32_t{1}, uint32_t{2147483648}));

  res = permutation_for_min_max(0b11);
  EXPECT_EQ(res, std::pair(uint32_t{3}, uint32_t{3221225472}));

  res = permutation_for_min_max(0b1111111111);
  EXPECT_EQ(res, std::pair(uint32_t{1023}, uint32_t{4290772992}));
}
