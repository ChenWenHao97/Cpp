#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void elimDups(vector<string> &words)
{
    sort(words.begin(),words.end());
    auto end_unique = unique(words.begin(),words.end());
    words.erase(end_unique,words.end());
    for(string i:words)
        cout <<i<<" ";
}
int main()
{
    vector<string> arr{"1","7","2","2","3","3","4","7","5"};
    elimDups(arr);
    return 0;
}