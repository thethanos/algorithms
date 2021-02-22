#pragma once

#include <algorithm>

/*********Heap sort**************
*  Time complexity: O(nLog(n))  *
*  Auxiliary space: O(1)        *
*********************************/

//C-style

template <typename T>
void heapify(size_t cur, T* data, size_t size);

template <typename T>
void heap_sort(T* data, size_t size)
{
	for (int i = (size/ 2)-1; i >= 0; --i)
		heapify(i, data, size);

	for (int i(size-1); i > 0; --i)
	{
		std::swap(data[0], data[i]);
		heapify(0, data, i);
	}
}

template <typename T>
void heapify(size_t cur, T* data, size_t size)
{
	int left = 2 * cur + 1;
	int right = 2 * cur + 2;

	int max = cur;

	if (left < size && data[left] > data[cur])
		max = left;

	if (right < size && data[right] > data[max])
		max = right;

	if (cur != max)
	{
		std::swap(data[cur], data[max]);
		heapify(max, data, size);
	}
}

//STL-style

template <typename RandomIt>
void heapify(RandomIt begin, RandomIt end, RandomIt item);

template <typename RandomIt>
void heap_sort(RandomIt begin, RandomIt end)
{
	RandomIt iter = std::next(begin, std::distance(begin, end) / 2 - 1);

	while (true)
	{
		heapify(begin, end, iter);
		if (iter == begin) break;
		--iter;
	}
	
	for (auto iter(--end); iter != begin; --iter, --end)
	{
		std::iter_swap(begin, iter);
		heapify(begin, end, begin);
	}
}

template <typename RandomIt>
void heapify(RandomIt begin, RandomIt end, RandomIt item)
{
	size_t cur_index = 2 * std::distance(begin, item);
	RandomIt max = item, left = end, right = end;

	if(std::distance(begin, end) > cur_index + 1)
		left  = std::next(begin, cur_index + 1);

	if(std::distance(begin, end) > cur_index + 2)
		right = std::next(begin, cur_index + 2);

	if (left < end && *item < *left)
		max = left;

	if (right < end && *max < *right)
		max = right;

	if (max != item)
	{
		std::iter_swap(item, max);
		heapify(begin, end, max);
	}
}