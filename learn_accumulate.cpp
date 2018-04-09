#include<iostream>
#include<numeric>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int arr[] = {1,2,3,4,5,6};
    int sum = accumulate(begin(arr),end(arr),0);
    cout  <<sum<<endl;
    string word[] = {"1","2","3","4"};
    vector<string> str(word,word+sizeof(word)/(sizeof(word[0])));//构造出来一个vector
    string sum2 = accumulate(str.begin(),str.end(),string(""));
    //这里“”必须用string构造，因为单纯的“”是字符串常量，是没有+运算符的
    cout <<sum2 <<endl;



}