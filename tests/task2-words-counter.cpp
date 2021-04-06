#include <gtest/gtest.h>
#include <words-counter.hpp>


class TestWordsCounter : public testing::Test {
  public:
    TestWordsCounter() { /* init protected members here */
    }

    void SetUp() { /* do nothing */
    }

    void TearDown() { /* do nothing */
    }

    ~TestWordsCounter() { /* free protected members here */
    }
};

TEST(TestWordsCounter, Simpliest) {
  constexpr std::size_t MAX_WORD_LEN{ 10 };
  auto count_array = count_words_by_length<MAX_WORD_LEN>(L"FIVE words in this text");
  EXPECT_EQ(count_array[4], 3);

  count_array = count_words_by_length<MAX_WORD_LEN>(L"1 2 3  4  1a 2a    3a");
  EXPECT_EQ(count_array[1], 4);
}

TEST(TestWordsCounter, LongWords) {
  // TODO: generate text, count words
  EXPECT_EQ(0, 0);
}
