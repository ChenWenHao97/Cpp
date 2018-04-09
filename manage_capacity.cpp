#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // vector<int> c;
    // c.reserve(10);
    // cout << c.capacity();
    // const char *cp = "hello world!!!";//以空字符结束
    // char noNULL[] = {'h','i'};//不是以空字符结束
    // string s1(cp);//拷贝cp中的字符知道遇到空字符
    // string s2(noNULL,2);
    // string s3(noNULL);
    // string s4(cp + 6,5);//从cp【6】往后复制5个
    // string s5(s1,6,5);
    // string s6(s1,6);//从cp【6】开始复制到结束符
    // string s7(s1,6,20);//从cp【6】开始复制到结尾
    // string s8(s1,16);//抛出异常
    // cout <<s1<<endl;
    // cout <<s2<<endl;
    // cout <<s3<<endl;
    // cout <<s4<<endl;
    // cout <<s5<<endl;
    // cout <<s6<<endl;
    // cout <<s7<<endl;
    // cout <<s8<<endl;
    // string str = "hello world!!!";
    // str.insert(str.size(),5,'@');
    // cout << str <<endl;
    // str.erase(str.size()-5,5);
    // cout <<str <<endl;
    string s = "some string",s2 = "some other string";
    cout << s2.size() << endl;
    s.insert(0,s2,0,s2.size());
    cout << s <<endl;
    return 0;
}

