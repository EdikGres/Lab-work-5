#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "LibForLab.h"
/*
	блок выделения памяти в функцию. (ok)
	ДОП:
	вывести слова меньше данного, если случаются повторы (SET) (ok)
	Доп к допу:
	просим длину и в результате попадают SET слова меньше или равно длины

	Чтение входных данных из файла.


*/
using namespace mylib;
int main() {
	FILE* input = fopen("input.txt", "rt");
	if (input == NULL)
	{
		FILE* input2 = fopen("input.txt", "wt");
		if (input2 == NULL)
		{
			printf("ERROR! We can't open the file!");
			exit(5);
		}
		fprintf(input2, "text=\nword=\nmax_len=");
		printf("File input.txt was not found.\nAn empty file has been created, please fill it in.\nAnd then run the program again.");
		fclose(input2);
		exit(1);
	}
	int len_text = 0;
	//printf("Input text: ");
	//char* text = get_string(&len_text);
	fseek(input, 5, SEEK_CUR);
	char* text = fget_string(input, &len_text);
	printf("Your text: %s\n", text);
	if (len_text == 0)
	{
		exit(2);
	}

	//printf("Input your word: ");
	int len_word = 0;
	//char* word = get_string(&len_word);
	fseek(input, 5, SEEK_CUR);
	char* word = fget_string(input, &len_word);
	if (len_word == 0 || word == 0)
	{
		exit(3);
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
	printf("\n\nResult(<%s): ", word);
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
	//int len = get_integer("\n\nInput max lenght: ");
	int len = 0;
	fseek(input, 8, SEEK_CUR);
	char* str_len = fget_string(input, &len);
	len = makeInteger(str_len);
	printf("\n\nMax lenght: %d\n", len);
	printf("Result: ");
	for (int i = 0; i < len_set; i++)
	{
		if (my_len_text(set_words[i]) <= len)
		{
			printf("%s ", set_words[i]);
		}
	}
	//------
	fclose(input);
	free(set_words);
	free(text);
	free(word);
	for (int i = len_mass; i >= 0; i--)
	{
		free(mass[i]);
	}
	return 0;
}
