/*************************************************************************
	> File Name: inforeser.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月17日 星期日 22时25分27秒
 ************************************************************************/

#include<iostream>
using namespace std;
void reset(int &i)
{
    i = 0;
}
int main()
{
    int i = 42;
    reset(i);
    cout << i <<endl;

    return 0;
}
