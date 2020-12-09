#include "pch.h"
#include "../Lab-work-5/LibForLab.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
using namespace mylib;
TEST(LibForLab, number_words_tests) {

	char text1[] = "hello my name is edik!"; // 5

	ASSERT_EQ(number_words(text1), 5);

	char text2[] = "hello141/wf my2name91is !edik!"; // 6

	ASSERT_EQ(number_words(text2), 6);
}