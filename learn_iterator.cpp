#include<iostream>
#include<list>

using namespace std;
int main()
{
    list<int> lst = {1,2,3,4};
    list<int> lst2,lst3 = {5};
    copy(lst.cbegin(),lst.cend(),front_inserter(lst3));

    for(int i:lst3)
        cout <<i <<endl;
    return 0;
}