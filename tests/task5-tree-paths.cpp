#include <gtest/gtest.h>
#include <tree-paths.hpp>
#include <memory>


class TreePaths : public testing::Test {
  protected:
    std::vector<std::unique_ptr<TreeNode>> allocated_nodes;
    TreeNode * AllocateTreeNode() {
      return allocated_nodes.emplace_back(std::make_unique<TreeNode>()).get();
    }
};

TEST_F(TreePaths, Simpliest) {
  TreeNode * root = AllocateTreeNode();
  root->leftChild = AllocateTreeNode();
  root->rightChild = AllocateTreeNode();
  TreeNode * cur = root->leftChild;
  cur->leftChild = AllocateTreeNode();
  cur->rightChild = AllocateTreeNode();

  cur = root->rightChild;
  cur->leftChild = AllocateTreeNode();
  cur->rightChild = AllocateTreeNode();

  cur = cur->rightChild;
  cur->leftChild = AllocateTreeNode();
  auto paths1 = find_all_deepest_paths(root);

  cur->rightChild = cur->leftChild;
  cur->leftChild = nullptr;
  auto paths2 = find_all_deepest_paths(root);

  cur->leftChild = AllocateTreeNode();
  auto paths3 = find_all_deepest_paths(root);

  EXPECT_EQ(0, 0);
}
