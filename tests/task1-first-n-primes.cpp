#include <gtest/gtest.h>
#include <first-n-primes.hpp>
#include <limits>


class TestPrimes : public testing::Test {
  public:
    TestPrimes() { /* init protected members here */
    }

    void SetUp() { /* do nothing */
    }

    void TearDown() { /* do nothing */
    }

    ~TestPrimes() { /* free protected members here */
    }
};

TEST(TestPrimes, Simpliest) {
  using ELEMTYPE = int;
  std::array<ELEMTYPE, 1> array;
  fill_array_with_primes(array);
  EXPECT_EQ(array[0], 2);
}

TEST(TestPrimes, Harder) {
  using ELEMTYPE = int;
  std::array<ELEMTYPE, 3> array;
  fill_array_with_primes(array);
  EXPECT_EQ(array[2], 5);
}

TEST(TestPrimes, NumericLimits) {
  constexpr std::size_t max_size = 10000;
  using ELEMTYPE = int;
  using MaxSizedArray = std::array<ELEMTYPE, max_size>;
  auto array_ptr = std::make_unique<MaxSizedArray>();
  MaxSizedArray & array = *array_ptr;

  fill_array_with_primes(array);
  ASSERT_GT(array[max_size - 1], 0);
}
