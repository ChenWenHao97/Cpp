/*************************************************************************
	> File Name: 2.5.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月06日 星期一 17时21分57秒
 ************************************************************************/

#include<iostream>
using namespace std;
typedef char* pstring;
int main()
{
    int a = 3,b = 4;
    decltype(a) c = a;
    decltype(a = b) d = a;
    ++d;
    cout << d << endl;
    cout << a <<endl;
using int = integer;
    integer q =10;
    cout << q <<endl;

    return 0;

}
