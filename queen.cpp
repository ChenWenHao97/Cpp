#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int x[20];
int n;
int count;
void swap(int *a,int *b)
{
    *a ^= *b;
    *b ^= *a;   
    *a ^= *b;
}
int Place(int k)
{
	for(int j=0;j<k;j++)
		if(abs(k-j)==abs(x[k]-x[j]) || x[j]==x[k])
			return 0;
	return 1;
}

void Backtrack1(int t) 
{     //t 表示当前是树的第t层，即对集合 S 中的第 t 个元素进行判断
    if (t >=n)
    {
        for(int i=0;i<n;i++)
            cout <<x[i]+1<<" ";
		cout <<endl;
        ::count++;

    }      //大于S中总的元素个数 ，遍历完成 
    else
        for (int i = 0; i < n; i++) {     // 两种可能 加入或者不加入到解集合 
            x[t] = i;
            if (Place(t))
            {
                Backtrack1(t + 1);           //对 t+1 层进行判断 
            } 
        }
}
void Backtrack2(int t) 
{     //t 表示当前是树的第t层，即对集合 S 中的第 t 个元素进行判断
    if (t >=n)
        {
            for(int i=0;i<n;i++)
                cout <<x[i]+1<<" ";
		cout <<endl;
        ::count++;

        }      //大于S中总的元素个数 ，遍历完成 
    else
        for (int i = t; i < n; i++) 
        {     // 两种可能 加入或者不加入到解集合 
            std::swap(x[i], x[t]);
            if (Place(t))
            {
                Backtrack2(t + 1);           //对 t+1 层进行判断 
            } 
            std::swap(x[t], x[i]);
        }
}
int main()
{
    cout <<"input n:";
    cin >> n;
    for(int i = 0;i < n;i++)
        x[i] = i;
    Backtrack2(0);
    //Backtrack1(0);
    cout <<"count is "<<::count<<endl;

    return 0;
}