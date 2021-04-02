#pragma once

#include <array>
#include <string_view>


std::wstring_view cut_last_word(std::wstring_view & text);

template<std::size_t MAX_LENGTH>
auto count_words_by_length(std::wstring_view text) {
  // std::array - the most efficient for real text words
  std::array<std::size_t, MAX_LENGTH+1> length_to_count;
  length_to_count.fill({});

  while (!text.empty()) {
    auto word_size = cut_last_word(text).size();
    if (word_size > 0 && word_size <= MAX_LENGTH)
      ++length_to_count[word_size];
  }
  return length_to_count;
}
