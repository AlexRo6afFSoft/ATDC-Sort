#ifndef tim_sort
#define tim_sort

#include "Insertion_Sort/insertion_sort.cpp"
#include <iterator>
#include <vector>

template <typename T>
void tim_sort (std::iterator_traits <T>, std::iterator_traits <T>);

template <typename T>
void __tim_sort (std::iterator_traits <T>, std::iterator_traits <T>);

template <typename T>
void __merge (std::iterator_traits <T>, std::iterator_traits <T>, std::iterator_traits <T>, std::iterator_traits <T>);

#include "tim_sort.cpp"

#define timSort tim_sort
#define timsort tim_sort
#define TimSort tim_sort
#define Timsort tim_sort
#endif

