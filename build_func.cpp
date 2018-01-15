/*************************************************************************
	> File Name: build_func.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月23日 星期六 22时38分58秒
 ************************************************************************/

#include<iostream>
using namespace std;
class ConstRef{
    public:
        ConstRef(int ii);
    private:
        int i;
        const int ci;
        int &ri;
};
ConstRef::ConstRef(int ii):i(ii),ci(ii),ri(i)
{
    cout << i << ci << ri<<endl;
}
int main()
{
    ConstRef test(11);

    return 0;

}
