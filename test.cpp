#include<iostream>
#include<fstream>
#include<istream>
#include<cstring>
#include<sstream>
using namespace std;

int main()
{
    char m[234234];
    strcpy(m,"jkla  jflasj");
    stringstream s;
    s << m;
    string a;
    s >> a;
    cout <<a<<endl;

    return 0;
}
