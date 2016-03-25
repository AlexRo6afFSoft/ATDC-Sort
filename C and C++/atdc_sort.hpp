#ifndef tim_sort
#define tim_sort

#include <iterator>
#include <vector>

template <typename T>
void atdc_sort (std::iterator_traits <T>, std::iterator_traits <T>);

template <typename T>
void __atdc_sort (std::iterator_traits <T>, std::iterator_traits <T>);

template <typename T>
void __merge (std::iterator_traits <T>, std::iterator_traits <T>, std::iterator_traits <T>, std::iterator_traits <T>);

#include "atdc_sort.cpp"

#define atdcSort atdc_sort
#define atdcsort atdc_sort
#define AtdcSort atdc_sort
#define Atdcsort atdc_sort
#endif

