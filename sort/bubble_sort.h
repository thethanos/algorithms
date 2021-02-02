#pragma once

/*********Bubble sort************
*  Time complexity: O(n * n)    *
*  Auxiliary space: O(1)		*
*********************************/

//C-style

template <typename T>
void bubble_sort(T* data, size_t size)
{
	for (int i(0); i < size - 1; ++i)
	{
		for (int j(0); j < size - 1; ++j)
		{
			if (data[j] > data[j + 1])
				std::swap(data[j], data[j + 1]);
		}
	}
}

//STL-style

template <typename ForwardIt>
void bubble_sort(ForwardIt begin, ForwardIt end)
{
	for (auto iter1(begin); iter1 != end; ++iter1)
	{
		for (auto iter2(begin), iter3 = std::next(begin); iter3 != end; ++iter2, ++iter3)
		{
			if (*iter2 > * iter3)
				std::iter_swap(iter2, iter3);
		}
	}
}