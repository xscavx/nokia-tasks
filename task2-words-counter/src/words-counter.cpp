#include "words-counter.hpp"
#include <unordered_map>


// You can complete this list of word's delimeters
constexpr std::wstring_view WORDS_DELIMETERS{ L" ,:?;()" };

std::wstring_view cut_next_word(std::wstring_view & text) {
  auto found_pos = text.find_last_of(WORDS_DELIMETERS);
  if (found_pos == std::wstring_view::npos) {
    std::wstring_view word{};
    text.swap(word);
    return word;
  }
  auto word = text.substr(found_pos);
  text.remove_suffix(word.size());
  return word;
}

void count_words_by_length(std::wstring_view text_src) {
  // unordered_map cause of we don't care about order while iterating
  std::unordered_map<std::size_t, std::size_t> length_to_count;
  std::wstring_view text = text_src;
  while (!text.empty()) {
    auto word = cut_next_word(text);
    length_to_count[word.size()] += 1;
  }
}
