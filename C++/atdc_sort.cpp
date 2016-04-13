#ifndef atdc_sort

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
//	if (RAI::iterator_category != std::random_access_iterator_tag())
//		throw std::invalid_argument ("Given iterator is not random access iterator");

	std::vector <typename RAI::value_type> arr;
	RAI it1 = b1, it2 = b2;
	while (it1 != e1 and it2 != e2)
	{
		if (it1 == e1)
		{
			arr.push_back (*it2);
			it2 ++;
		}
		else if (it2 == e2)
		{
			arr.push_back (*it1);
			it1 ++;
		}
		else
		{
			if (comp (*it1, *it2))
			{
				arr.push_back (*it1);
				it1 ++;
			}
			else
			{
				arr.push_back (*it2);
				it2 ++;
			}
		}
	}
	it1 = b1, it2 = b2;
	for (size_t i = 0 ; i < arr.size () ; i ++)
	{
		if (it1 == e1)
		{
			*it2 = arr [i];
			it2 ++;
		}
		else if (it2 == e2)
		{
			return ;
		}
		else
		{
			*it1 = arr [i];
			it1 ++;
		}
	}
}

template <typename RAI, typename X = std::less<typename RAI::value_type> >
void __atdc_sort (RAI Begin, RAI End, X comp)
{
////if (RAI::iterator_category != std::random_access_iterator_tag())
////	throw std::invalid_argument ("Given iterator is not random access iterator");

	int dist = std::distance (Begin, End);
	if (dist == 0)
		return ;
	if (dist == 1)
		return ;
	if (dist == 2)
	{
		if (!comp (*Begin, *prev (End)))
			std::iter_swap (Begin, prev (End));
		return ;
	}
	dist /= 2;
	RAI mid = Begin + dist;
	__atdc_sort (Begin, mid, comp);
	__atdc_sort (mid, End, comp);
	__merge (Begin, mid, std::next (mid), End, comp);
}

template <typename RAI, typename X = std::less<typename RAI::value_type> >
void atdc_sort (RAI Begin, RAI End, X comp = X())
{
////if (RAI::iterator_category != std::random_access_iterator_tag())
////	throw std::invalid_argument ("Given iterator is not random access iterator");

	__atdc_sort (Begin, End, comp);
}
#endif
