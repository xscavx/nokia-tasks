#include <gtest/gtest.h>
#include <list-pick-out.hpp>


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

GTEST_TEST(ListPickOut, Simpliest) {
  List * last_node{};
  for (int idx = 100; idx >= 1; --idx) {
    List * node = new List;
    node->payload = idx;
    node->next = last_node;
    last_node = node;
  }
  remove_every_nth(last_node, 5);
  ASSERT_EQ(0, 0);
}
