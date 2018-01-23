#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
class PersonInfo
{
    public:
        string name;
        vector<string> phones;
    friend ostream &operator <<(ostream &os,PersonInfo result);
    
};
// ostream &operator <<(ostream &os,vector<string> phones);
ostream &operator <<(ostream &os,PersonInfo result)
{
    os << result.name <<endl;
    // os << result.phones;//不换行防止多换行，因为vector输出的时候已经每行换过了
    for(auto p = result.phones.begin();p!=result.phones.end();p++)
        os << *p <<endl;
    return os;
}
// ostream &operator <<(ostream &os,vector<string> phones)
// {
//     for(auto p = phones.begin();p!=phones.end();p++)
//         os << *p <<endl;
//     return os;
// }
int main()
{
    string line,word;
    vector<PersonInfo> people;
    while(getline(cin,line))
    {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while(record >> word)
        {
            info.phones.push_back(word);
        }
        cout << info;//输出一个对象，需要重载运算符

        people.push_back(info);
    }
}