#include <gtest/gtest.h>
#include "words-counter.hpp"
#include <string_view>


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

GTEST_TEST(TestWordsCounter, Simpliest)
{
  count_words_by_length(L"FIVE words in this text");
  count_words_by_length(L"ONE");
  ASSERT_EQ(0, 0);
}