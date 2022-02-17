#include<vector>
namespace Sort
{
void SelectionSort(std::vector<int>& vector)
{
    int n = vector.size();
    for (int i = 0; i < n - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j < n; j++)
        {
            if (vector[j] < vector[k])
            {
                k = j;
            }
        }
        std::swap(vector[i], vector[k]);
    }
}
void BubbleSort(std::vector<int>& vector)
{
    int n = vector.size();
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j >0; j--)
        {
            if (vector[j-1] > vector[j ])
                std::swap(vector[j-1], vector[j]);
        }
    }
}
void QuickSort(std::vector<int>& vector, int begin, int end)
{
    if (begin >= end)
        return;
    int partition = (begin + end) / 2;
    int i = begin, j = end;
    while (true)
    {
        while (vector[i] < vector[partition])
            ++i;
        while (vector[j] > vector[partition])
            --j;
        if (j <= i)
        {
            QuickSort(vector, begin, j);
            QuickSort(vector, ++j, end);
            return;
        }
        std::swap(vector[i], vector[j]);
        ++i, --j;
    }
}
void MergeSort(std::vector<int>& vector, std::vector<int>& buffer, int begin, int end)
{
    if (begin == end)
        return;
    int mid = (begin + end) / 2;
    MergeSort(vector, buffer, begin, mid);
    MergeSort(vector, buffer, mid + 1, end);

    int left = begin;
    int right = mid + 1;
    int bufferIterator = left;
    while (left <= mid && right <= end)
    {
        if (vector[left] <= vector[right])
        {
            buffer[bufferIterator] = vector[left];
            ++left;
        }
        else
        {
            buffer[bufferIterator] = vector[right];
            ++right;
        }
        ++bufferIterator;
    }
    for (int i = left; i <= mid; ++i)
    {
        buffer[bufferIterator] = vector[i];
        ++bufferIterator;
    }
    for (int i = right; i <= end; ++i)
    {
        buffer[bufferIterator] = vector[i];
        ++bufferIterator;
    }
    for (int i = begin; i <= end; ++i)
    {
        vector[i] = buffer[i];
    }
}
}
