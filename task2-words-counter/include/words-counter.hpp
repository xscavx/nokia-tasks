#pragma once

#include <string_view>


std::wstring_view cut_next_word(std::wstring_view & text);
void count_words_by_length(std::wstring_view text);
