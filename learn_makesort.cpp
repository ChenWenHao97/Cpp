#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool isShorter(const string &s1,const string &s2)//按照长度大小排序
{
    return s1.size() < s2.size();
}
int main()
{
    vector<string> arr{"111","112","4fasf","5afdsffa","5afasdfasfffff","712","712"};
    stable_sort(arr.begin(),arr.end(),isShorter);
    for(string i:arr)
        cout <<i<<" "<<endl;

    return 0;
}