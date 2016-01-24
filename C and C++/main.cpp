//#include "tim_sort.cpp"
#include <iostream>
#include <random>

int main()
{
	/////////////////////////////////////////////////////////////////////
	/// Exmaple for use:
	/////////////////////////////////////////////////////////////////////
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis (-100, 100);
	int* arr = new int [100];
	for(int i = 0 ; i < 100; i++)
	{
		arr[i] = dis (gen);
		std::cout << arr [i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------\n";
	std::cout << std::endl;
	std::cout << std::endl;
	/////////////////////////////////////////////////////////////////////
	/// Use timsort
	/////////////////////////////////////////////////////////////////////
	
	for(int i = 0 ; i < 100 ; i ++)
	{
		std::cout << arr [i] << " ";
	}
	return 0;
}
