#include <vector>

/******Count inversions**********
*  Time complexity: O(nLog(n))  *
*  Auxiliary space: O(n)        *
*********************************/

int merge(std::vector<int>& data, int begin, int mid, int end);

int count_inversions(std::vector<int>& data, int begin, int end)
{
    if (begin >= end)
        return 0;

    int mid = (begin + end)/2;

    int res(0);
    res += count_inversions(data, begin, mid);
    res += count_inversions(data, mid + 1, end);

    res += merge(data, begin, mid, end);

    return res;
}

int merge(std::vector<int>& data, int begin, int mid, int end)
{
    int res(0);

    std::vector<int> temp(end + 1);
    int i(begin), j(mid + 1), k(begin);

    for (; i <= mid && j <= end; ++k)
    {
        if (data[i] <= data[j])
        {
            temp[k] = data[i];
            ++i;
        }
        else 
        {
            temp[k] = data[j];
            ++j;

            res += mid - i + 1;
        }
    }

    return res;
}   