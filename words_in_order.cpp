/*
单词按照固定规则进行装换
*/
#include<iostream>
#include<sstream>
#include<istream>
#include <fstream> 
#include<string>
#include<map>
#include<cstdio>
using namespace std;
const string & transform(const string &s,const map<string,string> &m)
{
    auto map_it = m.find(s);//找到应有的键
    if(map_it!=m.end())//容器存在对应法则
    {
        return map_it->second;
    }
    else
        return s;
}
map<string,string>buildMap(ifstream &map_file)//建立对应关系
{
    map<string,string> trans_map;
    string key;
    string value;
    while( map_file >> key && getline(map_file,value))
    {
        if(value.size() > 1)//看大小
        {
            trans_map[key] = value.substr(1);
        }
        else
        {
            throw runtime_error("no rule for" + key);
        }
    }
    return trans_map;
}
void word_transform(ifstream &map_file,ifstream &input)
{
    auto trans_map = buildMap(map_file);//得到对应关系
    string text;
    while(getline(input,text))
    {
        istringstream stream(text);//处理单个单词
        string word;
        bool firstword = true;//为了空格使用
        while(stream >> word)
        {
            if(firstword)
            {
                firstword = false;
            }
            else
            {
                cout << " ";
            }
            cout  << transform(word,trans_map);
        }
        cout << endl;
    }
}


int main()
{
    ifstream file_open;
    ifstream file_input;
    file_open.open("order.txt",ios::in);
    file_input.open("target.txt",ios::in);
    word_transform(file_open,file_input);
    return 0;
}