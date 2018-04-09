#include<iostream>
#include<memory>
using namespace std;
int main()
{
    // int *p = new int[10]{0,1,2,3,4,5,6,7,8,9};
    // cout <<p[0];
    allocator<string> alloc;
    auto const p = alloc.allocate(10);
    auto q = p;  
    alloc.construct(q++,10,'c');
    while(q!=p)
        alloc.destroy(--q);
}