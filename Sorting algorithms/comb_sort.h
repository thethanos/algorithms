#pragma once

/***********Comb sort************
*  Time complexity: O(n * n)    *
*  Auxiliary space: O(1)		*
*********************************/

//C-style

int new_gap(int old_gap);

template <typename T>
void comb_sort(T* data, size_t size)
{
	int gap = size;
	bool swapped = true;


	while (swapped || gap != 1)
	{
		swapped = false;
		gap = new_gap(gap);

		for (int i(0); i < size - gap; ++i)
		{
			if (data[i] > data[i + gap])
			{
				std::swap(data[i], data[i + gap]);
				swapped = true;
			}
		}
	}
}

int new_gap(int old_gap)
{
	if (old_gap > 1)
		return old_gap / 1.3;
	else
		return 1;
}

//STL-style

template <typename ForwardIt>
void comb_sort(ForwardIt begin, ForwardIt end)
{
	int gap = std::distance(begin, end);
	bool swapped = true;

	while (swapped || gap != 1)
	{
		gap = new_gap(gap);
		swapped = false;

		ForwardIt iter1(begin), iter2(begin);
		std::advance(iter2, gap);

		for (;iter2 != end; iter1++, iter2++)
		{
			if (*iter1 > *iter2)
			{
				std::iter_swap(iter1, iter2);
				swapped = true;
			}
		}
	}
}