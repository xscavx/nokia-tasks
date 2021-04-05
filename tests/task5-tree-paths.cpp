#include <gtest/gtest.h>
#include <tree-paths.hpp>
#include <memory>


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

GTEST_TEST(TreePaths, Simpliest) {
  std::vector<std::unique_ptr<TreeNode>> allocated_nodes;
  auto alloc_node = [&allocated_nodes]() -> TreeNode * {
    return allocated_nodes.emplace_back(std::make_unique<TreeNode>()).get();
  };

  TreeNode * root = alloc_node();
  root->leftChild = alloc_node();
  root->rightChild = alloc_node();
  TreeNode * cur = root->leftChild;
  cur->leftChild = alloc_node();
  cur->rightChild = alloc_node();

  cur = root->rightChild;
  cur->leftChild = alloc_node();
  cur->rightChild = alloc_node();

  cur = cur->rightChild;
  cur->leftChild = alloc_node();
  auto paths1 = find_all_deepest_paths(root);

  cur->rightChild = cur->leftChild;
  cur->leftChild = nullptr;
  auto paths2 = find_all_deepest_paths(root);

  cur->leftChild = alloc_node();
  auto paths3 = find_all_deepest_paths(root);

  ASSERT_EQ(0, 0);
}
