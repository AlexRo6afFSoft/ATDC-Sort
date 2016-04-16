#ifndef atdc_sort

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <functional>

#define atdcSort atdc_sort
#define atdcsort atdc_sort
#define AtdcSort atdc_sort
#define Atdcsort atdc_sort

template <typename RAI, typename X>
void __merge (RAI b1, RAI e1, RAI b2, RAI e2, X comp)
{
	std::vector <typename RAI::value_type> __arr;
	RAI it1 = b1, it2 = b2;
	while (it1 != e1 && it2 != e2)
	{
		if (comp (*it1, *it2) == 1)
		{
			__arr.push_back (*it1);
			it1 ++;
		}
		else if (comp (*it1, *it2) == 2)
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

template <typename RAI, typename X = std::less<typename RAI::value_type> >
void __atdc_sort (RAI Begin, RAI End, X comp)
{
	int dist = std::distance (Begin, End);
	if (dist == 0)
		return ;
	if (dist == 1)
		return ;
	if (dist == 2)
	{
		RAI last = prev (End);
		typename RAI::value_type b = *Begin;
		if (comp (*Begin, *last) == 2)
		{
			*Begin = *last;
			*last = b;
		}
		return ;
	}
	
	dist /= 2;
	RAI mid = Begin + dist;
	__atdc_sort (Begin, mid, comp);
	__atdc_sort (mid, End, comp);
	__merge (Begin, mid, mid, End, comp);
}

template <typename RAI, typename X = std::less<typename RAI::value_type> >
void atdc_sort (RAI Begin, RAI End, X comp = X())
{
	__atdc_sort (Begin, End, comp);
}
#endif
