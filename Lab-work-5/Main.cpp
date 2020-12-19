#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "LibForLab.h"
/*
	блок выделения памяти в функцию. (ok)
	вывести слова меньше данного, если случаются повторы (SET) (ok)

	просим длину и в результате попадают SET слова меньше или равно длины


*/
using namespace mylib;
int main() {
	printf("Input your text: ");
	int len_text = 0;
	char* text = get_string(&len_text);
	if (len_text == 0)
	{
		exit(1);
	}
	printf("Input your word: ");
	int len_word = 0;
	char* word = get_string(&len_word);
	if (len_word == 0 || word == 0)
	{
		exit(2);
	}
	int i = 0;
	word = get_word(word, &i);
	int len_mass = 0;
	char** mass = get_words(text, &len_mass);
	printf("\nYour word: %s\n\nAll words from text: ", word);
	for (int i = 0; i < len_mass; i++)
	{
		printf("%s ", mass[i]);
	}
	printf("\n\nResult: ");
	int len_words_less = 0;
	char** words_less = get_words_less(mass, word, len_mass, &len_words_less);
	for (int i = 0; i < len_words_less; i++)
	{
		printf("%s ", words_less[i]);
	}
	int len_set = 0;
	char** set_words = get_set_words(words_less, len_words_less, &len_set);
	printf("\n\nSET words: ");
	for (int i = 0; i < len_set; i++)
	{
		printf("%s ", set_words[i]);
	}
	//------
	int len = get_integer("\n\nInput max lenght: ");
	printf("Result: ");
	for (int i = 0; i < len_set; i++)
	{
		if (my_len_text(set_words[i]) <= len)
		{
			printf("%s ", set_words[i]);
		}
	}
	//------

	free(set_words);
	free(text);
	free(word);
	for (int i = len_mass; i >= 0; i--)
	{
		free(mass[i]);
	}
	return 0;
}
