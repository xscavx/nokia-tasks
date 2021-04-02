#include "words-counter.hpp"


// You can complete this list of word's delimeters
constexpr std::wstring_view WORDS_DELIMETERS{ L" ,:?;()" };
constexpr std::size_t DELIMETER_SIZE{ 1 };

std::wstring_view cut_last_word(std::wstring_view & text) {
  auto found_pos = text.find_last_of(WORDS_DELIMETERS);
  if (found_pos == std::wstring_view::npos) {
    std::wstring_view word{};
    text.swap(word);
    return word;
  }

  auto word = text.substr(found_pos);
  text.remove_suffix(word.size());
  word.remove_prefix(DELIMETER_SIZE);
  return word;
}
