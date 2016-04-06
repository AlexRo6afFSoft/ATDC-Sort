#ifndef atdc_sort
#define atdc_sort

#include <iterator>
#include <vector>
#include <algorithm>

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


template <typename T>
void __merge (std::iterator_traits <T> b1, std::iterator_traits <T> e1, std::iterator_traits <T> b2, std::iterator_traits <T> e2)
{
	std::vector <int> arr;

}

template <typename T>
void __atdc_sort (std::iterator_traits <T> Begin, std::iterator_traits <T> End)
{
	int dist = std::distance (Begin, End);
	if (dist == 0)
		return ;
	if (dist == 1)
		return ;
	if (dist == 2)
	{
		if (*Begin > *prev (End))
			swap (*Begin, *End);
		return ;
	}
	dist /= 2;
	std::iterator_traits <T> mid = Begin + dist;
	__atdc_sort (Begin, mid);
	__atdc_sort (mid, End);
	__merge (Begin, mid, std::next (mid), End);
}

template <typename T>
void atdc_sort (std::iterator_traits <T> Begin, std::iterator_traits <T> End)
{
	if (std::iterator_traits <T>::iterator_category != std::random_access_iterator_tag())
		throw std::invalid_argument ("Given iterator is not random access iterator");

	__atdc_sort (Begin, End);
}
