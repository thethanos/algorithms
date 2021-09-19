#pragma once

/*******Insertion sort***********
*  Time complexity: O(n * n)    *
*  Auxiliary space: O(1)        *
*********************************/

//C-style

template <typename T>
void insertion_sort(T* data, size_t size)
{
	for (int i(1); i < size; ++i)
	{
		for (int j(i); j > 0 && data[j] < data[j - 1]; --j)
			std::swap(data[j], data[j - 1]);
	}
}

//STL-style

template <typename BidirectIt>
void insertion_sort(BidirectIt begin, BidirectIt end)
{
	for (auto iter1(std::next(begin, 1)); iter1 != end; ++iter1)
	{
		for (auto iter2(iter1), iter3 = std::prev(iter1, 1); iter2 != begin; --iter2, --iter3)
		{
			if(*iter2 < *iter3)
				std::iter_swap(iter2, iter3);
		}
	}
}