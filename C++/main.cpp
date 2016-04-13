#include "atdc_sort.cpp"
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
struct cmp1
{
	int operator () (int a, int b)
	{
		return (a > b) + 1;
	}
};
struct cmp2
{
	bool operator () (int a, int b)
	{
		return (a < b);
	}
};
int main()
{
	/////////////////////////////////////////////////////////////////////
	/// Exmaple for use:
	/////////////////////////////////////////////////////////////////////
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis (0, 100);
	std::vector <int> arr (16);
	std::vector <int> arr1 (16);
	std::vector <int> arr2 (16);
	for(int i = 0 ; i < 16; i++)
	{
		arr  [i] = dis (gen);
		arr1 [i] = arr [i];
		arr2 [i] = arr [i];
	}
	for (int i = 0 ; i < 16 ; i ++)
	{
		std::cout << arr [i] << " ";
	}
	std::cout << std::endl;

	////////////////////////////////////////////////////////////////////
	/// Use Standart Sort
	////////////////////////////////////////////////////////////////////
	std::sort (begin (arr1), end (arr1), cmp2 ());
	for (int i = 0 ; i < 16 ; i ++)
	{
		std::cout << arr1 [i] << " ";
	}
	std::cout << std::endl;

	/////////////////////////////////////////////////////////////////////
	/// Use atdc sort
	/////////////////////////////////////////////////////////////////////
	atdc_sort (std::begin (arr2), std::end (arr2), cmp1 ());
	
	for(int i = 0 ; i < (int)arr2.size () ; i ++)
	{
		std::cout << arr2 [i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
