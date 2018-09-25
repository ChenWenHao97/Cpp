//load preoblem p124
#include<iostream>
using namespace std;
int MaxLoading(int w[],int c,int n,int bestx[]);
int main()
{

}
int MaxLoading(int w[],int c,int n,int bestx[])
{
    int i = 1;
    int *x = new int [n+1];
    int bestw = 0,//当前装载最优载重量
        cw = 0,//当前载重量
        r = 0;//剩余集装箱的重量
    for(int j = 1;j <= n;j++)
        r += w[j];
    while(true)
    {
        while(i <= n && cw + w[i]<= c)
        {//进入左子树
            r -= w[i];
            cw += w[i];
            x[i] = 1;
            i++;
        }
        if(i > n)
        {
            for(int j = 1;j <= n;j++)
                bestx[j] = x[j];
            bestw = cw;
        }
        else//进入右子数
        {
            r -= w[i];
            x[i] =0;
            i++;
        }
        while(cw + r <= bestw)
        {
            i--;
            while(i > 0 && !x[i])
            {
                r += w[i];
                i--;
            }
            if(i == 0)
            {
                delete[] x;
                return bestw;
            }
            //进入右子数
            x[i] = 0;
            cw -= w[i];
            i++;
        }
    }

}
