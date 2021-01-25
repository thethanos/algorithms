#pragma once

#include <thread>

/*********Merge sort*************
*  Time complexity: O(nLog(n))  *
*  Auxiliary space: O(n)		*
*********************************/

void merge_sort_mt(int* data, int begin, int end, int* temp);
void merge(int* data, int begin, int mid, int end, int* temp);

template <typename T, size_t size>
void improved_merge_sort_mt(T(&data)[size])
{
	int* temp = new int[size];
	merge_sort_mt(data, 0, size - 1, temp);
	delete[] temp;
}

void merge_sort(int* data, int begin, int end, int* temp)
{
	if (begin >= end) return;

	int mid = (begin + end) / 2;

	merge_sort(data, begin, mid, temp);
	merge_sort(data, mid + 1, end, temp);

	merge(data, begin, mid, end, temp);
}

void merge_sort_mt(int* data, int begin, int end, int* temp)
{
	if (begin >= end) return;

	int mid = (begin + end) / 2;

	std::thread th(merge_sort, data, begin, mid, temp);
	merge_sort(data, mid + 1, end, temp);

	th.join();
	merge(data, begin, mid, end, temp);
}

void merge(int* data, int begin, int mid, int end, int* temp)
{
	int i(begin), j(mid + 1), k(begin);

	for (; i <= mid && j <= end; ++k)
	{
		if (data[i] < data[j])
		{
			temp[k] = data[i];
			++i;
		}
		else
		{
			temp[k] = data[j];
			++j;
		}
	}

	for (; i <= mid; ++i, ++k)
		temp[k] = data[i];

	for (; j <= end; ++j, ++k)
		temp[k] = data[j];

	for (i = begin; i < k; ++i)
		data[i] = temp[i];
}
