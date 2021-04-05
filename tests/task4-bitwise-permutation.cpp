#include <gtest/gtest.h>
#include <bitwise-permutation.hpp>


class BitwisePermutation : public testing::Test {
  public:
    BitwisePermutation() { /* init protected members here */
    }

    void SetUp() { /* do nothing */
    }

    void TearDown() { /* do nothing */
    }

    ~BitwisePermutation() { /* free protected members here */
    }
};

GTEST_TEST(BitwisePermutation, Simpliest) {
  auto res = permutation_for_min_max(0b0);
  res = permutation_for_min_max(0b1);
  res = permutation_for_min_max(0b11);
  res = permutation_for_min_max(0b1111111111);
  ASSERT_EQ(0, 0);
}
