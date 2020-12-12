#include <stdio.h>
#include <stdlib.h>
#include "LibForLab.h"

namespace mylib {
	char* get_string(int* len) {
		*len = 0;
		int capacity = 1;
		char* tmp;
		char* s = (char*)malloc(sizeof(char));
		char c = getchar();
		while (c != '\n' && s != NULL) {
			s[(*len)++] = c;
			if (s != NULL && *len >= capacity) {
				capacity *= 2;
				tmp = (char*)realloc(s, capacity * sizeof(char));
				if (tmp != NULL)
				{
					s = tmp;
				}
			}
			c = getchar();
		}
		if (s != NULL)
		{
			s[*len] = 0;
		}
		return s;
	}
	int isalpha(char ch) {
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int my_strcmp(const char* str1, const char* str2)
	{
		int s1;
		int s2;
		do {
			s1 = *str1++;
			s2 = *str2++;
			if (s1 == 0)
				break;
		} while (s1 == s2);
		return (s1 < s2) ? -1 : (s1 > s2);
	}
	int number_words(char* text) {
		int quantity = 0;
		int i = 0;
		while (text[i] != 0)
		{
			if (isalpha(text[i])) {
				quantity++;
				while (text[i] != 0 && isalpha(text[i]))
				{
					i++;
				}
			}
			i++;
		}
		return quantity;
	}

	char* get_word(char* text, int* iterator) {
		char* s = (char*)malloc(sizeof(char));
		char* tmp;
		int capacity = 1;
		int i = 0;
		while (text[*iterator] != 0 && !isalpha(text[(*iterator)]))
		{
			(*iterator)++;
		}
		while (text[*iterator] != 0 && isalpha(text[*iterator]))
		{
			if (s)
			{
				s[i++] = text[*iterator];
			}
			if (i >= capacity) {
				capacity *= 2;
				tmp = (char*)realloc(s, capacity * sizeof(char));
				if (tmp != NULL)
				{
					s = tmp;
				}
			}
			(*iterator)++;
		}
		if (s)
		{
			s[i] = '\0';
		}
		return s;
	}

	char** get_words(char* text, int* len) {
		*len = number_words(text);

		char** mass = (char**)malloc(sizeof(char**) * (*len));
		int it = 0;
		//mass[0] = get_word(text, &it);
		for (int i = 0; i <= *len; i++)
		{
			if (mass)
			{
				mass[i] = get_word(text, &it);
			}
		}
		return mass;
	}







}