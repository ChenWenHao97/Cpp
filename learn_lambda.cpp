#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
using namespace std::placeholders;
int add(int a, int b)
{
    return a + b;
}
bool isShortter(const string &s1,const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
//     vector<int> vi{-1,-2,-4,-5};
//     transform(vi.begin(),vi.end(),vi.begin(),
// [ ](int i) ->int { if(i < 0) return -i;else return i;});
//     for(int i:vi)
//         cout <<i<<endl; 
    auto add5 = bind(add, 5, _1);
    sort(words.begin(),words.end(),isShorter);
    sort(words.begin(),words.end(),bind(isShorter,_2,_1));//就可以实现从大小排序


    cout << add5(5, 6) << endl;
    return 0;
}