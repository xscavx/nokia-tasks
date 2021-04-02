#include <gtest/gtest.h>
#include "tree-paths.hpp"


class TreePaths : public testing::Test {
  public:
    TreePaths() { /* init protected members here */
    }

    void SetUp() { /* do nothing */
    }

    void TearDown() { /* do nothing */
    }

    ~TreePaths() { /* free protected members here */
    }
};

GTEST_TEST(TreePaths, Simpliest)
{
  ASSERT_EQ(0, 0);
}
