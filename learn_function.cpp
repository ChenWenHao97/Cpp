#include<iostream>
#include<functional>
using namespace std;
int add(int i,int j) { return i + j; };
struct divide{
    int operator()(int denominator,int divisor){
        return denominator / divisor;
    }
};
int main()
{
    function<int(int,int)> f1 = add;
    function<int(int,int)> f2 = divide();
    function<int(int,int)> f3 = [](int i,int j){return i*j;};

    cout << f1(4,2) << endl;
    cout << f2(4,2) << endl;
    cout << f3(4,2) << endl;
}
