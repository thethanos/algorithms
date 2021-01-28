#pragma once

/*********Heap sort**************
*  Time complexity: O(nLog(n))  *
*  Auxiliary space: O(1)		*
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