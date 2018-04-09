#include<iostream>
#include<iterator>
#include<vector>
using namespace std;
int main()
{
    istream_iterator<int> in_iter(cin),eof;
    vector<int> vec(in_iter,eof);

    // for(int i:vec)
    //     cout << i <<endl;

    ostream_iterator<int> out_iter(cout," ");//每个输出后面加一个空格
    for(int i:vec)
        *out_iter++ = i;
    


    return 0;
}