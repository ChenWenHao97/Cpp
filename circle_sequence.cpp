/*
环状序列，输入ctcc，输出ccct，就是按字典序输出
*/
#include<iostream>
#include<string.h>
#define maxn 105
using namespace std;
int les(const char *s,int p,int q);
int main()
{
    int T;
    char s[maxn];
    cin >> T;
    while(T--)
    {
        cin >> s;
        int ans = 0;
        int n  =strlen(s);
        for(int i=1;i < n;i++)
        {
            if(les(s,i,ans))
                ans = i;
        }
        cout << "ans:"<<ans<<endl;
        for(int i=0;i < n;i++)
            putchar(s[(i+ans)%n]);
        putchar('\n');
    }
    return 0;
}
int les(const char *s,int p,int q)
{
    int n = strlen(s);
    for(int i = 0;i < n;i++)
    {
        if(s[(p+i)%n] != s[(q+i)%n])
            return s[(p+i)%n] < s[(q+i)%n];
    }
    return 0;
}