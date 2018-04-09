/*
给矩阵相乘加括号，让相乘的次数最少
*/

#include<iostream>
using namespace std;
void matrix_chain_order(int *p,int m[][1000],int s[][1000],int n);
void print(int s[][1000],int i,int j);
int main()
{
    int p[1000];//存储第一个行，和其他的列
    cout <<"请输入要输入矩阵的个数:";
    int num = 0 ;
    cin >> num;
    int row = 0,column = 0;
    cout <<"请依次输入矩阵的行和列:";
    cin >> row >> column;
    //因为p[0]要存第一个矩阵的行，之后的p都是存矩阵的列
    //这里我刚开始也不懂，但是找了一个例子
    //a1是30*35,a2是35*15,a3是15*15
    //a1和a2乘积次数是30*35*15,之后再和a3是15*15
    //总之只用到了第一个矩阵的行，其余矩阵的列（包括第一个矩阵自己的列）
    p[0] = row,p[1] = column;
    for(int i = 2;i <= num;i++)
    {
        cin >> row >> column;
        p[i] = column;
    }
    int m[1000][1000]={0};//存储最少乘积次数
    int s[1000][1000]={0};//存储加括号的位置
    matrix_chain_order(p,m,s,num);
    print(s,1,num);
    return 0;
}
void matrix_chain_order(int *p,int m[][1000],int s[][1000],int n)
{
    for(int i = 0;i <= n;i++)
        m[i][i] = 0;//i=i，此时只有一个矩阵，所以不用算
    for(int l = 2;l <= n;l++)//l是以有两个链为开始
        for(int i = 1;i <= n-l+1;i++)//有m[i，j]时j-i+1是整个矩阵链的长度,同时i也是左边界
        {
            int j = i+l-1;//这个是右边界
            m[i][j] = m[i][i] + m[i+1][j] + p[i-1]*p[i]*p[j];
            s[i][j] = i;
        //算法导论里这里写的是m[i][j]无穷大，无穷大不好表示，所以感觉m提前用公式算出来，会好一点。
            for(int k = i+1;k < j;k++)//k就是放括号的位置
            {
                int tmp = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(tmp < m[i][j])
                {
                    m[i][j] = tmp;
                    s[i][j] = k;
                }
            }
        }
}
void print(int s[][1000],int i,int j)
{
    if(i == j)
        cout << "A"<<i<<" ";
    else 
    {
        cout <<"(";
        print(s,i,s[i][j]);
        print(s,s[i][j]+1,j);
        cout <<")";
    }
}