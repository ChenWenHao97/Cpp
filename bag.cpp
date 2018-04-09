#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
   int dp[21][75000];
   memset(dp,0,sizeof(dp));
   dp[0][7500] = 1;//当没有挂钩的时候就是平衡状态
   int hook[21];
   int value[21];
   int c,g;
   while(cin >>c >>g)
   {
        for(int i =1 ;i <= c;i++)
            cin >> hook[i];
        for(int i = 1; i <= g;i++)
            cin >> value[i];
        for(int i = 1;i <= g;i++)
            for(int j = 1;j <= 15000;j++)
            {
                if(dp[i-1][j])//如果之前这个状态有值，证明有方法
                {
                    for(int k = 1;k <= c;k++)
                        dp[i][j+hook[k]*value[i]] += dp[i-1][j];
                        //之前的挂钩值加上之后的挂钩值，如果之前挂钩有方法，就把这些方法加上
                }
            }
        cout << dp[g][7500]<<endl;
   }


    return 0;
}