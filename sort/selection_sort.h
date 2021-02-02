#pragma once

#include <algorithm>

/*******Selection sort***********
*  Time complexity: O(n * n)    *
*  Auxiliary space: O(1)        *
*********************************/

//C-style

template <typename T>
void selection_sort(T* data, size_t size)
{
	int min = 0;
	for (int i(0); i < size; ++i)
	{
		min = i;
		for (int j(i); j < size; ++j)
		{
			if (data[j] < data[min])
				min = j;
		}

		std::swap(data[i], data[min]);
	}
}

//STL-style

template <typename ForwardIt>
void selection_sort(ForwardIt begin, ForwardIt end)
{
	for (auto iter(begin); iter != end; ++iter)
		std::iter_swap(iter, std::min_element(iter, end));
}