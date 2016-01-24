template <typename T>
void __merge (std::iterator_traits <T> b1, std::iterator_traits <T> e1, std::iterator_traits <T> b2, std::iterator_traits <T> e2)
{
	std::vector <int> arr;

}

template <typename T>
void __tim_sort (std::iterator_traits <T> Begin, std::iterator_traits <T> End)
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
	__tim_sort (Begin, mid);
	__tim_sort (mid, End);
	__merge (Begin, mid, std::next (mid), End);
}

template <typename T>
void tim_sort (std::iterator_traits <T> Begin, std::iterator_traits <T> End)
{
	if (typeid (std::iterator_traits <T>::iterator_category) != typeid (std::random_access_iterator_tag))
		throw std::invalid_argument ("Given iterator is not random access iterator");

	__tim_sort (Begin, End);
}
