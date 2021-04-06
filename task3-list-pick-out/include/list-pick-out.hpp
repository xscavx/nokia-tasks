#pragma once

#include <cstddef>


struct List {
  using SomeDataType = int;
  struct List *next;
  SomeDataType payload;
};

List * remove_next_node(List *previous_node);
List * prepend_node(List *list_root, List *new_node);
List * remove_every_nth(List *list_root, std::size_t n);
