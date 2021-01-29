#pragma once

#include <thread>

/*********Quick sort*************
*  Time complexity: O(nLog(n))  *
*  Auxiliary space: O(1)		*
*********************************/

//C-style

template <typename T>
int partition(T* data, int begin, int end);

template <typename T>
void quick_sort(T* data, int begin, int end);

template <typename T>
void quick_sort_mt(T* data, int begin, int end)
{
	if (begin >= end) return;

	int mid = partition(data, begin, end);

	std::thread th(quick_sort<T>, data, begin, mid - 1);
	quick_sort(data, mid + 1, end);
	th.join();
}

template <typename T>
void quick_sort(T* data, int begin, int end)
{
	if (begin >= end) return;

	int mid = partition(data, begin, end);

	quick_sort(data, begin, mid - 1);
	quick_sort(data, mid + 1, end);
}

template <typename T>
int partition(T* data, int begin, int end)
{
	int pivot = end;
	int i(begin), j(i - 1);

	for (; i < end; ++i)
	{
		if (data[i] < data[pivot])
		{
			++j;
			std::swap(data[i], data[j]);
		}
	}

	std::swap(data[pivot], data[j + 1]);
	return j + 1;
}

//STL-style

template <typename ForwardIt>
ForwardIt partition(ForwardIt begin, ForwardIt end);

template <typename ForwardIt>
void quick_sort(ForwardIt begin, ForwardIt end)
{
	if (std::distance(begin, end) < 2) return;

	ForwardIt mid = partition(begin, end);

	quick_sort(begin, mid);
	quick_sort(mid, end);
}

template <typename ForwardIt>
ForwardIt partition(ForwardIt begin, ForwardIt end)
{
	ForwardIt pivot = begin;
	ForwardIt iter1(begin), iter2(begin);

	for (++iter1; iter1 != end; ++iter1)
	{
		if (*iter1 < *pivot)
		{
			++iter2;
			std::iter_swap(iter1, iter2);
		}
	}

	std::iter_swap(iter2, pivot);
	return ++iter2;
}