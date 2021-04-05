#pragma once

#include <vector>
#include <stack>


struct TreeNode {
  struct TreeNode *leftChild;
  struct TreeNode *rightChild;
};

using TreePath = std::stack<TreeNode *>;

std::vector<TreePath> find_all_deepest_paths(TreeNode *root);