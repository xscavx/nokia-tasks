#include <gtest/gtest.h>
#include "list-pick-out.hpp"


class ListPickOut : public testing::Test {
  public:
    ListPickOut() { /* init protected members here */
    }

    void SetUp() { /* do nothing */
    }

    void TearDown() { /* do nothing */
    }

    ~ListPickOut() { /* free protected members here */
    }
};


GTEST_TEST(ListPickOut, Simpliest)
{
  ASSERT_EQ(0, 0);
}
