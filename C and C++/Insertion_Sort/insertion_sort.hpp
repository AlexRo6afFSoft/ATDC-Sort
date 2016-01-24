#ifndef insertion_sort
#define insetrion_sort

template<typename T>
void insertion_sort (T begin, T end)
{
	for(int i=1; i<5; i++)
	{
		int index = array[i];
		int dec = i;
		while(dec>0 && array[dec-1]>=index)
		{
			array[dec]=array[dec-1];
			--dec;
		}
		array[dec]=index;
	}
}

#endif
