/*************************************************************************
	> File Name: name_find.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月23日 星期六 22时06分11秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
class Screen{
    public:
    typedef std::string::size_type pos;
        void dummy_fcn(pos ht)
        {
            cursor =  height;//使用类中成员
            cout << cursor << endl;
        }
    private:
        pos cursor = 0;
        pos height = 0,width = 0;

};
int main()
{
    Screen test;
    test.dummy_fcn(1);
    return 0;

}
