#include <list-pick-out.hpp>
#include <cassert>
#include <cstddef>


void remove_next(List *previous_node) {
  List *remove_node = previous_node->next;
  if (remove_node) {
    previous_node->next = remove_node->next;
    remove_node->next = nullptr;
    // TODO: return outside for deletion
    delete remove_node;
  }
}

void remove_every_nth(List *root, std::size_t n) {
  assert(n > 1);
  std::size_t node_num{1};
  List * current_node{root};

  while (true) {
    if (!current_node) {
      break;
    }
    if (node_num + 1 >= n) {
      remove_next(current_node);
      node_num = 0;
    }
    current_node = current_node->next;
    ++node_num;
  }
}
