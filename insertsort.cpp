#include<iostream>
#include<typeinfo>
#include<vector>
using namespace std;

// 使用 int[]
template <typename T>
inline int get_array_len(T &p)
{
    return sizeof(T) / sizeof(*p);
}

void insertsort(int arr[], int n)
{
    int j = 0;
    for(int i = 2; i < n; i++)
    {
        if(arr[i] < arr[i-1])
        {
            arr[0] = arr[i];
            for(j = i-1; arr[0] < arr[j]; j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = arr[0];
        }
    }
}

template <typename T>
inline void insertsort(T &arr)
{
    insertsort(arr,  (arr));
}

// 使用 vector<int> *
void insertsort_vec(vector<int> *arr)
{
    for(int i = 2; i < arr->size(); i++)
    {
        if(arr->at(i) < arr->at(i-1))
        {
            arr->at(0) = arr->at(i);
            int j;
            for(j = i - 1; arr->at(0) < arr->at(j); j--)
            {
                arr->at(j+1) = arr->at(j);
            }
            arr->at(j+1) = arr->at(0);
        }
    }
}

int main()
{
    vector<int> vec {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr[] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    insertsort(arr);
    insertsort_vec(&vec);

    cout << "使用vector *的insertsort函数后，结果为：" << endl;
    for (auto i = vec.begin() + 1; i != vec.end(); ++i) 
    {
        cout << *i << (i + 1 != vec.end() ? ' ': '\n');
    }

    cout << endl << "使用int[]的insertsort函数后，结果为：" << endl;
    int len = get_array_len(arr);
    for (int i = 1; i < len; i++)
    {
        cout << arr[i] << (i + 1 != len ? ' ': '\n');
    }

    int ar[30];
    int *p = ar;
    cout << endl;
    cout << "int ar[30];  // ar的类型是：" << typeid(ar).name() << endl;
    cout << "int *p = ar; // p的类型是：" << typeid(p).name() << endl;
    return 0;
}
