#pragma once

/********Cocktail sort***********
*  Time complexity: O(n * n)    *
*  Auxiliary space: O(1)        *
*********************************/

//C-style

template <typename T>
void cocktail_sort(T* data, size_t size)
{
	bool swapped = true;

	int begin(0), end = size - 1;
	while (swapped)
	{
		swapped = false;
		for (int i(begin); i < end; ++i)
		{
			if (data[i] > data[i + 1])
			{
				std::swap(data[i], data[i + 1]);
				swapped = true;
			}
		}

		if (!swapped) return;

		swapped = false;
		--end;

		for (int i(end); i > begin; --i)
		{
			if (data[i] < data[i - 1])
			{
				std::swap(data[i], data[i - 1]);
				swapped = true;
			}
		}

		++begin;
	}
}

//STL-style

template <typename BidirectIt>
void cocktail_sort(BidirectIt begin, BidirectIt end)
{
	bool swapped = true;

	auto iter_beg(begin), iter_end(end);
	while (swapped)
	{
		for (auto iter1(iter_beg), iter2 = std::next(iter_beg, 1); iter2 != iter_end; ++iter1, ++iter2)
		{
			if (*iter1 > * iter2)
			{
				std::iter_swap(iter1, iter2);
				swapped = true;
			}
		}

		if (!swapped) return;

		swapped = false;

		auto iter1 = --iter_end;
		for (auto iter2 = std::prev(iter1); iter1 != begin; --iter1, --iter2)
		{
			if (*iter1 < *iter2)
			{
				std::iter_swap(iter1, iter2);
				swapped = true;
			}
		}

		++iter_beg;
	}
}