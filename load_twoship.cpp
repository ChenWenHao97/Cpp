#include<iostream>
using namespace std;
class MaxLoading{
public:
    void BackTrack(int t);
    void output(void);
    
    int n;
    int w[100];
    int x[100];
    int c1= 0 ,c2 = 0;
    int cw1= 0 ,cw2 = 0;
};

int main()
{

    MaxLoading test;
    cout<<"请输入物品个数:";
    cin >> test.n;
    cout <<"请输入物品重量:";
    for(int i = 0;i < test.n;i++)
    {
        cin >>test.w[i];
    }
    cout <<"请输入c1和c2的载重";
    cin >>test.c1>>test.c2;
    test.BackTrack(0);
}
void MaxLoading::output(void)
{
    for(int i = 0;i < n;i++)
        cout <<x[i]<<" ";
    cout<<endl;
}
void MaxLoading::BackTrack(int t)
{
    if(t > n)
        output();
    for(int i = 0;i <=2 ;i++)
    {
        x[t] = i;
        if(i==0 ? 0:(cw1+w[t]<=c1||cw2+w[t]<=c2))
        {

            if(i==1 && cw1+w[t] <= c1)
                cw1 += w[t];
            if(i==2 && cw2+w[t] <= c2)
                cw2 += w[t];
            BackTrack(t+1);
            if(i==1)
                cw1-=w[t];
            if(i==2)
                cw2-=w[t];
        }
    }
}
