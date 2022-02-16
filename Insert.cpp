#include <vector>
namespace Insert
{
int InterpolationInsert(std::vector<int>& vector, int target)
{
    int begin = 0, end = vector.size() - 1;
    while (begin < end)
    {
        int mid = begin + (end - begin) * (target - vector[begin]) / (vector[end] - vector[begin]);
        if (mid < begin)
            mid = begin + 1;
        if (mid > end)
            mid = end - 1;
        if (target == vector[mid])
        {
            begin = mid;
            break;
        }
        if (target < vector[mid])
        {
            end = mid - 1;
        }
        else
        {
            begin = mid + 1;
        }
    }
    vector.insert(vector.begin() + begin, target);
    return begin;
}

int BinaryInsert(std::vector<int>& vector, int target)
{
    int begin = 0, end = vector.size() - 1;
    if (begin == end)
        return begin;
    int devider = (begin + end) / 2;
    while (begin - end)
    {
        if (vector[devider] == target)
        {
            begin = devider;
            break;
        }
        if (vector[devider] < target)
        {
            begin = ++devider;
        }
        if (vector[devider] > target)
        {
            end = devider;
        }
        devider = (begin + end) / 2;
    }
    vector.insert(vector.begin() + begin, target);
    return begin;
}
}
