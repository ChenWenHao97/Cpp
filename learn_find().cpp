#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int val = 42;
    vector<int> vec;
    auto result = find(vec.begin(),vec.end(),val);
    cout << "the value is:" <<val
        << (result == vec.end()
            ?",is not present":"is present") <<endl;

    // int val = 32;
    // int arr[] ={1,2,3,32};
    // auto result = find(begin(arr),end(arr),val);
    // if(result!=end(arr))
    //     cout <<"可以用数组"<<endl;
    return 0;
}