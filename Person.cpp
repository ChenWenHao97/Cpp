/*************************************************************************
	> File Name: Person.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月20日 星期三 17时26分04秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include<string.h>
class Person{
    string name;
    string address;
public :
    const string& getName() const{return name};
    const string& getAddress() const{return address};
}
