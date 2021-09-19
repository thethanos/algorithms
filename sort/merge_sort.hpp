#pragma once

#include <thread>
#include <vector>

/*********Merge sort*************
*  Time complexity: O(nLog(n))  *
*  Auxiliary space: O(n)        *
*********************************/

//C-style

template <typename T>
void merge_sort_mt(T* data, int begin, int end, int* temp);

template <typename T>
void merge_sort(T* data, int begin, int end, int* temp);

template <typename T>
void merge(T* data, int begin, int mid, int end, int* temp);

template <typename T, size_t size>
void improved_merge_sort_mt(T(&data)[size])
{
	int* temp = new int[size];
	merge_sort_mt(data, 0, size - 1, temp);
	delete[] temp;
}

template <typename T>
void improved_merge_sort_mt(T* data, size_t size)
{
	int* temp = new int[size];
	merge_sort_mt(data, 0, size - 1, temp);
	delete[] temp;
}

template <typename T>
void merge_sort_mt(T* data, int begin, int end, int* temp)
{
	if (begin >= end) return;

	int mid = (begin + end) / 2;

	std::thread th(merge_sort<T>, data, begin, mid, temp);
	merge_sort(data, mid + 1, end, temp);

	th.join();
	merge(data, begin, mid, end, temp);
}

template <typename T>
void merge_sort(T* data, int begin, int end, int* temp)
{
	if (begin >= end) return;

	int mid = (begin + end) / 2;

	merge_sort(data, begin, mid, temp);
	merge_sort(data, mid + 1, end, temp);

	merge(data, begin, mid, end, temp);
}

template <typename T>
void merge(T* data, int begin, int mid, int end, int* temp)
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


//STL-style

template <typename ForwardIt, typename value_type = int>
void merge(ForwardIt begin, ForwardIt mid, ForwardIt end, std::vector<value_type>& temp);

template <typename ForwardIt, typename value_type = int>
void merge_sort(ForwardIt begin, ForwardIt end, std::vector<value_type>& temp);

template <typename ForwardIt, typename value_type = int>
void improved_merge_sort_mt(ForwardIt begin, ForwardIt end)
{
	size_t dist = std::distance(begin, end);

	if (dist < 2) return;
	
	std::vector<value_type> temp(dist);

	ForwardIt mid = std::next(begin, dist / 2);

	std::thread th(merge_sort<ForwardIt, value_type>, begin, mid, std::ref(temp));
	merge_sort<ForwardIt, value_type>(mid, end, std::ref(temp));

	th.join();
	merge<ForwardIt, value_type>(begin, mid, end, std::ref(temp));
}

template <typename ForwardIt, typename value_type>
void merge_sort(ForwardIt begin, ForwardIt end, std::vector<value_type>& temp)
{
	size_t dist = std::distance(begin, end);

	if (dist < 2) return;

	ForwardIt mid = std::next(begin, dist / 2);

	merge_sort<ForwardIt, value_type>(begin, mid, std::ref(temp));
	merge_sort<ForwardIt, value_type>(mid, end, std::ref(temp));
	
	merge<ForwardIt, value_type>(begin, mid, end, std::ref(temp));
}

template <typename ForwardIt, typename value_type>
void merge(ForwardIt begin, ForwardIt mid, ForwardIt end, std::vector<value_type>& temp)
{
	ForwardIt iter1(begin), iter2(mid);
	typename std::vector<value_type>::iterator iter3(temp.begin());

	for (; iter1 != mid && iter2 != end; ++iter3)
	{
		if (*iter1 < *iter2)
		{
			std::iter_swap(iter3, iter1);
			++iter1;
		}
		else
		{
			std::iter_swap(iter3, iter2);
			++iter2;
		}
	}

	for (; iter1 != mid; ++iter1, ++iter3)
		std::iter_swap(iter3, iter1);

	for (; iter2 != end; ++iter2, ++iter3)
		std::iter_swap(iter3, iter2);

	std::copy(temp.begin(), iter3, begin);
}