#include<iostream>
#include<array>
#include<vector>
#include<list>
using namespace std;
int main()
{
    array<int,10> digits = {0,1,2,3,4,5,6,7,8,9};
    array<int,10> copy = digits;
    list<const char*> l{ "hello", "world" };
    vector<string> v;
    v.assign(l.cbegin(), l.cend());

    for(auto p = v.begin();p!=v.end();p++)
        cout << *p <<endl;

    return 0;
}