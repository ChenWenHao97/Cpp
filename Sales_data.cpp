/*************************************************************************
	> File Name: Sales_data.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月24日 星期日 17时21分20秒
 ************************************************************************/

#include<iostream>
#include<typeinfo>
using namespace std;
class Sales_data{
    public:
        Sales_data(string s,unsigned cnt,double price):
            bookNo(s),units_sold(cnt),revenue(cnt*price) { cout<<"3"<<endl; };
        Sales_data():Sales_data("",0,0){ cout<<"empty"<<endl; };
        Sales_data(string s):Sales_data(s,0,0){cout<<"string"<<endl;};
        Sales_data &combine(Sales_data);
       // Sales_data &combine(Sales_data&);
       // Sales_data &combine(const Sales_data&) const;
    private:
        double revenue;
        unsigned units_sold;
        string bookNo;
};
Sales_data & Sales_data::combine(Sales_data)
{
    
}
int main()
{
    Sales_data test;
    Sales_data one("one");
    

}
