/*************************************************************************
	> File Name: verfiy_literal.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月26日 星期二 23时12分05秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <string>
#include <type_traits>

struct Data {
    int ival;
    std::string s;
};

int main()
{
    std::cout << std::boolalpha;
    std::cout << std::is_literal_type<Data>::value << std::endl;
    // output: false
}
