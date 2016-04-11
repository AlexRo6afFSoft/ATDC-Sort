#ifndef atdc_sort

#include <iterator>
#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
void atdc_sort (std::iterator_traits <T> Begin, std::iterator_traits <T> End);

template <typename T>
void __atdc_sort (std::iterator_traits <T> Begin, std::iterator_traits <T>  End);

template <typename T>
void __merge (std::iterator_traits <T>, std::iterator_traits <T>, std::iterator_traits <T>, std::iterator_traits <T>);

#define atdcSort atdc_sort
#define atdcsort atdc_sort
#define AtdcSort atdc_sort
#define Atdcsort atdc_sort
#endif


template <typename T, typename X>
void __merge (std::iterator_traits <T> b1, std::iterator_traits <T> e1, std::iterator_traits <T> b2, std::iterator_traits <T> e2, X comp)
{
	std::vector <T> arr;
	std::iterator_traits <T> it1 = b1, it2 = b2;
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

template <typename T, typename X = std::less<T> >
void __atdc_sort (std::iterator_traits <T> Begin, std::iterator_traits <T> End, X comp)
{
	int dist = std::distance (Begin, End);
	if (dist == 0)
		return ;
	if (dist == 1)
		return ;
	if (dist == 2)
	{
		if (!comp (*Begin, *prev (End)))
			swap (*Begin, *End);
		return ;
	}
	dist /= 2;
	std::iterator_traits <T> mid = Begin + dist;
	__atdc_sort (Begin, mid);
	__atdc_sort (mid, End);
	__merge (Begin, mid, std::next (mid), End, comp);
}

template <typename T, typename X>
void atdc_sort (std::iterator_traits <T> Begin, std::iterator_traits <T> End, X comp)
{
	if (std::iterator_traits <T>::iterator_category != std::random_access_iterator_tag())
		throw std::invalid_argument ("Given iterator is not random access iterator");

	__atdc_sort (Begin, End, comp);
}
