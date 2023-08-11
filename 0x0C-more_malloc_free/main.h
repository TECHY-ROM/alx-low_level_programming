#ifndef MAIN_H
#define MAIN_H

void *malloc_checked(unsigned int b);

char *string_nconcat(char *s1, char *s2, unsigned int n);

void *_calloc(unsigned int nmemb, unsigned int size);

int *array_range(int min, int max);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

int _putchar(char c);

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int is_positive_integer(const char *str);

void multiply_strings(const char *str1, const char *str2, char *result, int len1, int len2);

int main(int argc, char *argv[]);

int _strlen(char *s);

int is_digit(char *s);

void init(char *str, int l);

void _print(char *str, int l);

#endif
