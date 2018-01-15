/*************************************************************************
	> File Name: use_cin_cout.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月20日 星期三 17时36分05秒
 ************************************************************************/

#include<iostream>
using namespace std;
int a,b,c;
void read(istream &is);
void print(ostream &os);
int main()
{
    read(cin);
    print(cout);
}
void read(istream &is)
{
    is >> a >> b >>c;
}
void print(ostream &os)
{
    os << a << b << c << endl;
}
