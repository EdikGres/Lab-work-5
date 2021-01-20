#ifndef LIBLAB_H
#define LIBLAB_H

namespace mylib {
	char* get_string(int* len);
	int get_integer(const char* msg);
	int isalpha(char ch);
	int my_strcmp(const char* str1, const char* str2);
	int number_words(char* text);
	char* get_word(char* text, int* iterator);
	char** get_words(char* text, int* len);
	void* get_memory(void* p1, int* len, size_t sizeInBytes);
	//char** set_words(char** words, int len_words, int* len_set);
	int isContainsWord(char** set, int len_set, char* word);
	char** get_set_words(char** text, int len_text, int* len_set);
	int my_len_text(char* text);
	char** get_words_less(char** mass, char* word, int len_words, int* len);
	char* fget_string(FILE* file, int* len);
	int isNumber(char ch);
	int makeInteger(const char* c);
}

#endif