#include <tree-paths.hpp>


std::vector<TreePath> find_all_deepest_paths(TreeNode *root) {
  std::vector<TreePath> all_paths;
  if (!root) {
    return all_paths;
  }

  TreePath current_path{{root}};
  std::size_t max_path_size{0};
  auto save_path = [&all_paths, &max_path_size](TreePath &path) {
    if (path.size() < max_path_size) {
      return;
    } else if (path.size() > max_path_size) {
      all_paths.clear();
      max_path_size = path.size();
    }
    all_paths.emplace_back(path);
  };

  TreeNode *prev_node{nullptr};
  while (!current_path.empty()) {
    TreeNode *current_node = current_path.top();
    TreeNode *left_child = current_node->leftChild;
    TreeNode *right_child = current_node->rightChild;
    bool const right_visited = prev_node == right_child;
    bool const left_visited = right_visited || prev_node == left_child;

    if (left_child && !left_visited) {
      current_path.push(left_child);
    } else if (right_child && !right_visited) {
      current_path.push(right_child);
    } else {
      save_path(current_path);
      current_path.pop();
    }
    prev_node = current_node;
  }
  return all_paths;
}
