#include "vector.h"
#include <stdio.h>

vector (int);

int main ()
{
	struct vector_int arr = new_vector_int ();
	push_back_int (&arr, 1);
	printf ("%d\n", arr.arr [0]);
}
