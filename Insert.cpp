#include <vector>
namespace Insert
{
int InterpolationInsert(std::vector<int>& vector, int target)
{
    int begin = 0, end = vector.size() - 1;
    int mid = begin + (end - begin) * (target - vector[begin]) / (vector[end] - vector[begin]);
    while (begin < end)
    {
        if (target == vector[mid])
            return mid;
        if (target < vector[mid])
        {
            end = mid;
        }
        else
        {
            begin = mid;
        }
        mid = begin + (end - begin) * (target - vector[begin]) / (vector[end] - vector[begin]);
    }
    return begin;
}

int BinaryInsert(std::vector<int>& vector, int begin, int end, int target)
{
    if (begin == end)
        return begin;
    int devider = (begin + end) / 2;
    while (begin - end)
    {
        if (vector[devider] == target)
        {
            vector.insert(vector.begin() + devider, target);
            return devider;
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
