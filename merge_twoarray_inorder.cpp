#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename CONT>
void reverse(CONT &arr, int begin, int end)
{
    for (int i = 0; i < (end - begin + 1) / 2; i++)
    {
        auto temp = arr[begin + i];
        arr[begin + i] = arr[end - i];
        arr[end - i] = temp;
    }
}

template<class CONT>
void swap(CONT &a, int left, int middle, int right)//三次翻转，就可以转换两个位置数组
{
    reverse(a, left, middle - 1);
    reverse(a, middle, right - 1);
    reverse(a, left, right - 1);
}

template <class CONT>
void merge_twoarray(CONT &arr, int arr2_begin)
{
    int i = 0;
    int j = arr2_begin;
    int index;

    while (i < j && j <= arr.size())
    {
        while (arr[i] < arr[j])
            i++;
        index = j;
        while (arr[j] < arr[i] && j != arr.size())
        {
            j++;
        }
        // rotate(arr.begin() + i, arr.begin() + index, arr.begin() + j);
        //库函数可以代替swap
        swap(arr, i, index, j);
        i += j - index;
    }
}
int main()
{
    vector<int> arr{1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    int arr2_begin;
    cout << "请输出数组2的起始位置:";
    cin >> arr2_begin;
    merge_twoarray(arr, arr2_begin);
    for (int i : arr)
        cout << i << " ";

    return 0;
}