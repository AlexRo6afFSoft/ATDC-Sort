#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define vector(type) \
struct vector_##type\
{\
	type * arr;\
	size_t size;\
	size_t capacity;\
};\
\
struct vector_##type new_vector_##type ()\
{\
	struct vector_##type ans;\
	ans.arr = malloc (sizeof (type [1]));\
	ans.size = 0;\
	ans.capacity = 1;\
	return ans;\
} \
\
void push_back_##type (struct vector_##type* a, type val)\
{\
	if (a->capacity < a->size + 1)\
	{\
		a->size ++;\
		a->capacity *= 2;\
		type* arr = malloc (sizeof (type [a->capacity]));\
		for (size_t i = 0 ; i < a->size ; i ++)\
			arr [i] = a->arr [i];\
		free (a->arr);\
		a->arr = malloc (sizeof (type [a->capacity]));\
		for (size_t i = 0 ; i < a->size ; i ++)\
			a->arr [i] = arr [i];\
		free (arr);\
	}\
	else\
	{\
		a->size ++;\
		a->arr [a->size - 1] = val;\
	}\
}


