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
TEST(LibForLab, uniqueWords) {

	char t1[] = "abcd";
	char t2[] = "abcd";
	char t3[] = "bitch";

	char** mass = (char**)malloc(sizeof(char**) * 5);
	for (int i = 0; i < 5; i++)
	{
		mass[i] = t1;
	}
	mass[2] == NULL;
	mass[3] == NULL;
	ASSERT_EQ(uniqueWord(mass, 3, t3), 1);


}
