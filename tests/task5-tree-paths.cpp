#include <gtest/gtest.h>
#include <tree-paths.hpp>
#include <memory>
#include <random>


class TreePaths : public testing::Test {
  protected:
    std::vector<std::unique_ptr<TreeNode>> allocated_nodes;

    int RollRandomInt(int from, int to);
    TreeNode * AllocateTreeNode();
    TreeNode * AllocateMinimalTree();
    TreeNode * AllocateFullNTree(std::size_t depth);
    TreeNode * RemoveRandomSubtreeOnRandomDepth(TreeNode *root, std::size_t max_depth);
    std::pair<TreeNode *, TreeNode *> AllocateTinyTree();
};

int TreePaths::RollRandomInt(int from, int to) {
  static std::default_random_engine engine{};
  static std::uniform_int_distribution<int> dist{from, to};
  return dist(engine);
}

TreeNode * TreePaths::AllocateTreeNode() {
  return allocated_nodes.emplace_back(std::make_unique<TreeNode>()).get();
}

TreeNode * TreePaths::AllocateMinimalTree() {
  TreeNode *root = AllocateTreeNode();
  root->leftChild = AllocateTreeNode();
  root->rightChild = AllocateTreeNode();
  return root;
}

TreeNode * TreePaths::AllocateFullNTree(std::size_t depth) {
  if (depth < 1) {
    return nullptr;
  }
  TreeNode *root = AllocateTreeNode();
  root->leftChild = AllocateFullNTree(depth-1);
  root->rightChild = AllocateFullNTree(depth-1);
  return root;
}

TreeNode * TreePaths::RemoveRandomSubtreeOnRandomDepth(TreeNode *root, std::size_t max_depth) {
  if (max_depth < 2) {
    return nullptr;
  }
  std::size_t const random_depth = RollRandomInt(1, max_depth - 1);
  for (std::size_t d = 1; d < random_depth; ++d) {
    if (RollRandomInt(0, 1)) {
      root = root->leftChild;
    } else {
      root = root->rightChild;
    }
  }
  TreeNode *removed_root;
  if (RollRandomInt(0, 1)) {
    removed_root = root->leftChild;
    root->leftChild = nullptr;
  } else {
    removed_root = root->rightChild;
    root->rightChild = nullptr;
  }
  return removed_root;
}

std::pair<TreeNode *, TreeNode *> TreePaths::AllocateTinyTree() {
  TreeNode *root = AllocateTreeNode();
  root->leftChild = AllocateTreeNode();
  root->rightChild = AllocateTreeNode();

  TreeNode *leaf = root->leftChild;
  leaf->leftChild = AllocateTreeNode();
  leaf->rightChild = AllocateTreeNode();
  leaf = root->rightChild;
  leaf->leftChild = AllocateTreeNode();
  leaf->rightChild = AllocateTreeNode();

  leaf = leaf->rightChild;
  return std::pair{root, leaf};
}

TEST_F(TreePaths, Simpliest) {
  auto [root, leaf] = AllocateTinyTree();
  leaf->leftChild = AllocateTreeNode();
  auto paths_left = find_all_deepest_paths(root);

  leaf->rightChild = leaf->leftChild;
  leaf->leftChild = nullptr;
  auto paths_right = find_all_deepest_paths(root);

  leaf->leftChild = AllocateTreeNode();
  auto paths_both = find_all_deepest_paths(root);

  EXPECT_EQ(paths_left.size(), paths_right.size());
  EXPECT_EQ(paths_both.size(), 2);

  EXPECT_EQ(paths_left.back().size(), paths_right.back().size());
  EXPECT_EQ(paths_left.back().size(), paths_both.back().size());
}

TEST_F(TreePaths, DoubleDepth) {
  auto [root1, leaf1] = AllocateTinyTree();
  auto [root, leaf] = AllocateTinyTree();
  leaf->leftChild = root1;
  leaf = leaf1;

  leaf->leftChild = AllocateTreeNode();
  auto paths_left = find_all_deepest_paths(root);

  leaf->rightChild = leaf->leftChild;
  leaf->leftChild = nullptr;
  auto paths_right = find_all_deepest_paths(root);

  leaf->leftChild = AllocateTreeNode();
  auto paths_both = find_all_deepest_paths(root);

  EXPECT_EQ(paths_left.size(), paths_right.size());
  EXPECT_EQ(paths_both.size(), 2);

  EXPECT_EQ(paths_left.back().size(), paths_right.back().size());
  EXPECT_EQ(paths_left.back().size(), paths_both.back().size());
}

TEST_F(TreePaths, FullNTree) {
  TreeNode *root = AllocateFullNTree(0);
  EXPECT_EQ(root, nullptr);

  for (auto depth = 1; depth < 20; ++ depth) {
    TreeNode *root = AllocateFullNTree(depth);
    RemoveRandomSubtreeOnRandomDepth(root, depth);
    auto max_paths = find_all_deepest_paths(root);
    EXPECT_EQ(max_paths.back().size(), depth);
  }
}
