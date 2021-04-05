#pragma once

#include <cstddef>


struct List {
  using SomeDataType = int;
  struct List *next;
  SomeDataType payload;
};

void remove_next(List *previous_node);
void remove_every_nth(List *root, std::size_t n);
