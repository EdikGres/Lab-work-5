#include <stdio.h>
#include <stdlib.h>
#include "LibForLab.h"
/*
	���� ��������� ������ � �������. (ok)
	������� ����� ������ �������, ���� ��������� ������� (SET) (ok)
	


*/
using namespace mylib;
int main() {
	printf("Input your text: ");
	int len_text = 0;
	char* text = get_string(&len_text);
	printf("Input your word: ");
	int len_word = 0;
	char* word = get_string(&len_word);
	int i = 0;
	word = get_word(word, &i);
	int len_mass = 0;
	char** mass = get_words(text, &len_mass);
	printf("\nYour word: %s\nAll words from text: ", word);
	for (int i = 0; i < len_mass; i++)
	{
		printf("%s ", mass[i]);
	}
	printf("\n\nResult: ");
	for (int i = 0; i < len_mass; i++)
	{
		if (my_strcmp(mass[i], word) == (-1))
		{
			printf("%s ", mass[i]);
		}
	}
	int len_set = 0;
	char** set_words = get_set_words(mass, len_mass, &len_set);
	printf("\n\nSET words: ");
	for (int  i = 0; i < len_set; i++)
	{
		printf("%s ", set_words[i]);
	}

	free(set_words);
	free(text);
	free(word);
	for (int i = len_mass; i >= 0; i--)
	{
		free(mass[i]);
	}
	return 0;
}
