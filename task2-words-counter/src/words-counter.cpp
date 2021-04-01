#include "words-counter.hpp"
#include <unordered_map>


constexpr wchar_t WORDS_DELIMETER{ L' ' };

std::wstring_view cut_next_word(std::wstring_view & text) {
  auto found_pos = text.find(WORDS_DELIMETER);
  auto word = text.substr(0, found_pos);
  text.remove_prefix(word.size());
  return word;
}

void count_words_by_length(std::wstring_view text) {
  // unordered_map cause of we don't care about order while iterating
  std::unordered_map<std::size_t, std::size_t> length_to_count;
  while (!text.empty()) {
    auto word = cut_next_word(text);
    length_to_count[word.size()] += 1;
  }
}
