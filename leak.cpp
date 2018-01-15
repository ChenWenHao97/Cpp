/*************************************************************************
	> File Name: leak.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月05日 星期五 14时04分29秒
 ************************************************************************/

#include<iostream>
using namespace std;

class a {
    public:
    a() {int *p = new int;}
};

int main()
{
    a b;
}
