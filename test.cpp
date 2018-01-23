#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    string file = "1.txt";
    fstream in(file,ios::in|ios::binary);
    in << "write";
    in.close();
    fstream out(file);
    string buffer;
    getline(out,buffer);
    cout << buffer <<endl;
    return 0;
}
