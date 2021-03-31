#include <gtest/gtest.h>

#include <first-n-primes.hpp>

class TestProtocol : public ::testing::Test {
 public:
  TestProtocol() { /* init protected members here */
  }

  void SetUp() { /* do nothing */
  }

  void TearDown() { /* do nothing */
  }

  ~TestProtocol() { /* free protected members here */
  }

 protected:
  /* none */
};

GTEST_TEST(TestProtocol, Simpliest)
{
  std::array<int, 1> array;
  fill_array_with_primes(array);
  ASSERT_EQ(array.size(), 1);
}


int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
