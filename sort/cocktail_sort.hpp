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

	while (swapped)
	{
		for (auto iter1(begin), iter2 = std::next(iter1, 1); iter2 != end; ++iter1, ++iter2)
		{
			if (*iter1 > * iter2)
			{
				std::iter_swap(iter1, iter2);
				swapped = true;
			}
		}

		if (!swapped) return;

		swapped = false;
		--end;

		for (auto iter1(end), iter2 = std::prev(iter1); ; --iter1, --iter2)
		{
			if (*iter1 < *iter2)
			{
				std::iter_swap(iter1, iter2);
				swapped = true;
			}

			if (iter2 == begin) break;
		}

		++begin;
	}
}