#include <list-pick-out.hpp>
#include <cassert>
#include <cstddef>


List * remove_next_node(List *previous_node) {
  List *removed_node = previous_node->next;
  if (removed_node) {
    previous_node->next = removed_node->next;
  }
  return removed_node;
}

List * prepend_node(List *list_root, List *new_node) {
  if (new_node) {
    new_node->next = list_root;
  }
  return new_node;
}

List * remove_every_nth(List *list_root, std::size_t n) {
  assert(n > 1);
  std::size_t node_num{1};
  List *current_node{list_root}, *removed_list{nullptr};
  while (current_node) {
    if (node_num + 1 >= n) {
      List *removed_node = remove_next_node(current_node);
      // Reattach removed nodes to new list.
      // Let client choose how to free allocated memory
      removed_list = prepend_node(removed_list, removed_node);
      node_num = 0;
    }
    current_node = current_node->next;
    ++node_num;
  }
  return removed_list;
}

List * remove_every_fifth(List *list_root) {
  static constexpr std::size_t FIFTH{5};
  return remove_every_nth(list_root, FIFTH);
}
