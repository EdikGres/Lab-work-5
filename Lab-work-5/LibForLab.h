#ifndef LIBLAB_H
#define LIBLAB_H

namespace mylib {
	char* get_string(int* len);
	int isalpha(char ch);
	int my_strcmp(const char* str1, const char* str2);
	int number_words(char* text);
	char* get_word(char* text, int* iterator);
	char** get_words(char* text, int* len);
}

#endif