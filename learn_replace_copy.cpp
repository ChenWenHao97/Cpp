#include<iostream>
#include<cstring>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int arr[] = {1,2,2,4,2,6,7,8};

    int num[sizeof(arr)/sizeof(*arr)];
    replace_copy(begin(arr), end(arr), num, 2, 4);
    for(int i:num)
        cout <<i<<endl;

    return 0;
}