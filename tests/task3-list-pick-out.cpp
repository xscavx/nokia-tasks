#include <gtest/gtest.h>
#include <list-pick-out.hpp>
#include <memory>

static constexpr std::size_t REMOVE_EVERY_NODE{5};

class ListPickOut : public testing::Test {
  protected:
    std::vector<std::unique_ptr<List>> allocated_nodes;
    List * AllocateListNode() {
      return allocated_nodes.emplace_back(std::make_unique<List>()).get();
    }
};

TEST_F(ListPickOut, Simpliest) {
  static std::array const list_sizes{0, 1, 2, 3, 4, 5, 30, 31, 32, 33, 34, 35};
  for (auto list_size : list_sizes) {
    List *source_list_root{nullptr};
    for (int idx = list_size; idx >= 1; --idx) {
      List * node = AllocateListNode();
      node->payload = idx;
      node->next = source_list_root;
      source_list_root = node;
    }
    List *removed_nodes_root = remove_every_nth(source_list_root, REMOVE_EVERY_NODE);
    while (removed_nodes_root) {
      EXPECT_EQ(removed_nodes_root->payload % REMOVE_EVERY_NODE, 0);
      removed_nodes_root = removed_nodes_root->next;
    }
  }
}
