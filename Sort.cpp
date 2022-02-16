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
}
