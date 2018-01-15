#include<iostream>
#include<vector>
using namespace std;
void shellsort(vector<int> &arr);
int main()
{
    vector<int> arr{0,9,8,7,6,5,4,3,2,1};
    shellsort(arr);
    for(auto i = arr.begin() + 1;i!=arr.end();i++)
        cout << *i <<" ";
}
void shellsort(vector<int> &arr)
{
    int i,j;
    int increment = arr.size();
    do{
        increment = increment / 3 + 1;//增量
        for(int i = increment + 1;i < arr.size();i++)//之后和冒泡差不多
        {
            if(arr[i] < arr[i-increment])//中间差一个增量
            {
                arr[0] = arr[i];
                for(j = i -increment;j > 0&&arr[0]<arr[j];j-=increment)
                    arr[j+increment] = arr[j];
                arr[j+increment] = arr[0];
            }
        }
    }while(increment > 1);
}
