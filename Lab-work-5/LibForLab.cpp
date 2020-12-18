#include <stdio.h>
#include <stdlib.h>
#include "LibForLab.h"

namespace mylib {
	void* get_memory(void* p1, int* len, size_t sizeInBytes) {
		if (p1 != NULL)
		{
			void* tmp;
			*len *= 2;
			tmp = (void*)realloc(p1, sizeInBytes * (*len));
			if (tmp != NULL)
			{
				return tmp;
			}
		}
		return NULL;
	}
	char* get_string(int* len) {
		*len = 0;
		int capacity = 1;
		char* s = (char*)malloc(sizeof(char));
		char c = getchar();
		while (c != '\n' && s != NULL) {
			s[(*len)++] = c;
			if (s != NULL && *len >= capacity) {
				s = (char*)get_memory(s, &capacity, sizeof(char*));
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
			if (i >= capacity && s != NULL) {
				s = (char*)get_memory(s, &capacity, sizeof(char*));
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
	int isContainsWord(char** set, int len_set, char* word) {
		int i = 0;
		while (i < len_set)
		{
			if (my_strcmp(set[i], word) == 0)
			{
				return 1;
			}
			i++;

		}
		return 0;
	}
	char** get_set_words(char** text, int len_text, int* len_set) {
		int i = 0, j = 0;
		char** set_words = (char**)malloc(sizeof(char**) * len_text);
		set_words[j++] = text[i++];
		while (i < len_text)
		{
			if (isContainsWord(set_words, j, text[i]) == 0)
			{
				set_words[j++] = text[i];
			}
			i++;
		}
		*len_set = j;
		return set_words;
	}
	
	


	
	



}