/*************************************************************************
	> File Name: selfstring.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月31日 星期日 22时31分49秒
 ************************************************************************/
//问题：69行
#include<iostream>
#include<cstring>
using namespace std;
class String{
    public:
        String(const char *str=NULL);//通用构造函数
        String(const String &str);//拷贝函数
        ~String();//析构函数

        String operator+(String &str) const;//+
        String& operator=(const String &str);//=
        String& operator+=(const String &str);//+=
        bool operator==(const String &str);//==
        char& operator[](int n)const;//[]
        int find(const String &str);

        size_t size() const;//获取长度
        const char *c_str()const;

        friend istream& operator>>(istream &is,String &str);//cin
        friend ostream& operator<<(ostream &os, const String &str);//cout;
    private:
        char *data;
        size_t length;
};
String::String(const char*str)
{
    if(!str)
    {
        length = 0;
        data = new char[1];
        *data = '\0';
    }
    else 
    {
        length = strlen(str);
        data = new char[length+1];
        strcpy(data,str);
    }
}
String::String(const String &str)//拷贝的时候深复制
{
    length = str.size();
    data = new char[length +1 ];
    strcpy(data,str.c_str());
}
String::~String()
{
    delete []data;
    length = 0;
}

String String::operator+(String &str) const//重载+
{
    String newString;
    newString.length = length + str.size();
    delete[] newString.data;
    newString.data = new char[newString.length+1];
    strcpy(newString.data,data);
    strcat(newString.data,str.data);
    return newString;
}


String& String::operator=(const String &str)//=
{
    if(this == &str)//确定地址
        return *this;
    //防止内存泄露，
    //这里释放了原先申请的内存再重新申请一块适当大小的内存存放新的字符串
    delete []data;//a=b,delete a的data
    length = str.size();
    data = new char[length+1];
    strcpy(data, str.c_str());
    return *this;
}

String& String::operator+=(const String &str)//+=
{
    length += str.size();
    char *newData = new char[length+1];
    strcpy(newData,data);
    strcat(newData,str.data);
    delete []data;
    data = newData;
    return *this;
}
inline bool String::operator==(const String &str)//==
{
    if(length!=str.length)
        return false;
    return strcmp(data,str.data)?false:true;
}
inline size_t String::size()const//获取长度
{
    return length;
}
int String::find(const String &str)
{
    char *p = strstr(data,str.c_str());
    if(p!=NULL)
        return p-data;
    else 
        return -1;
}
istream& operator>>(istream &is,String &str)//cin
{
    char temp[1000];//先申请一个内存
    is >> temp;
    str.length = strlen(temp);
    delete[] str.data;
    str.data = new  char[str.length+1];
    strcpy(str.data,temp);
    return is;
}
ostream& operator<<(ostream &os, const String &str)//cout
{
    //因为a+b是一个常量
    //所以传入cout里时，如果String不是const，就变成常量给了非常量，就会出错
    os << str.c_str();
    return os;
}
inline const char* String::c_str()const//获取c字符串
{
    return data;
}

int main()
{
    String s;
    cin >> s;
    cout << s<<":"<<s.size()<<endl;

    char a[] = "happy",b[] = " new year!";
    cout << a<<b<<endl;
    String s1(a),s2(b);
    cout << s1<<"+"<<s2;
    cout<<(s1+s2)<<endl;

    String s3 = s1+s2;
    if(s1 == s3)
        cout << "Fist:s1 == s3"<<endl;
    s1+=s2;
    if(s1 == s3)
     cout << "Second:s1==s3"<<endl;
    
    String f1("dasfasdabcd"),f2("abcd");
    cout << f1.find(f2) << endl;
    return 0;
}

