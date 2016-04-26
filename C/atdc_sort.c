#ifndef atdc_sort

#include "STL/vector.h"

#define atdcSort atdc_sort
#define atdcsort atdc_sort
#define AtdcSort atdc_sort
#define Atdcsort atdc_sort

void __merge (void * b1, void * e1, void * b2, void * e2, int (*comp) (void*, void*) )
{
	vector v;
	vector_init(&v);
	void* it1 = b1;
	void* it2 = b2;
	while (it1 != e1 && it2 != e2)
	{
		if (comp (it1, it2) == 1)
		{
			__arr.push_back (*it1);
			it1 ++;
		}
		else if (comp (it1, it2) == 2)
		{
			__arr.push_back (*it2);
			it2 ++;
		}
	}
	
	if (it1 == e1)
	{
		while (it2 != e2)
		{
			__arr.push_back (*it2);
			it2 ++;
		}
	}
	else if (it2 == e2)
	{
		while (it1 != e1)
		{
			__arr.push_back (*it1);
			it1 ++;
		}
	}
	
	it1 = b1;
	for (size_t i = 0 ; i < (size_t)distance (b1, e1) ; i ++)
	{
		*it1 = __arr [i];
		it1 ++;
	}
	
	it2 = b2;
	for (size_t i = (size_t)distance (b1, e1) ; i < __arr.size () ; i ++)
	{
		*it2 = __arr [i];
		it2 ++;
	}
}

void __atdc_sort (void * Begin, void * End, int (*comp) (void*, void*))
{
	int dist = std::distance (Begin, End);
	if (dist == 0)
		return ;
	if (dist == 1)
		return ;
	if (dist == 2)
	{
		void * last = prev (End);
		typename void *::value_type b = *Begin;
		if (comp (*Begin, *last) == 2)
		{
			*Begin = *last;
			*last = b;
		}
		return ;
	}
	
	dist /= 2;
	void * mid = Begin + dist;
	__atdc_sort (Begin, mid, comp);
	__atdc_sort (mid, End, comp);
	__merge (Begin, mid, mid, End, comp);
}

int def_less (void* a, void* b)
{
	typename void *::value_type A = *a;
	typename void *::value_type B = *b;
	return (A < B) + 1;
}

void atdc_sort (void * Begin, void * End, int (*comp)(void*, void*) = &def_less)
{
	__atdc_sort (Begin, End, comp);
}
#endif
