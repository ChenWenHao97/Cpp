#include<iostream>
#include<set>
#include<map>
using namespace std;
int main()
{
    // set<int> set2;
    // set2.insert({1,3,5,7,1,3,5,7});

    // for(int i:set2)
    //     cout << i <<endl;

    map<string,int> cmap;  
    cmap["op1"] = 1;  
    cmap["op2"] = 2;  
    string str = "samy";  
    cmap.insert(make_pair(str,3));  
  
//  for(map<string,int>::iterator ite = cmap.begin(); ite!=cmap.end();++ite)  
//  {  
//      cout<<ite->first<<" "<<ite->second<<endl;  
//  }  
    //cout<<cmap.count("Annaa")<<endl;  
    map<string,int>::iterator key = cmap.find("samy");  
    if(key!=cmap.end())  
    {  
        cout<<key->second<<endl;  
    }  
    return 0;
}