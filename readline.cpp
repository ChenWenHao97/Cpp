/*************************************************************************
	> File Name: readline.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月04日 星期六 15时20分16秒
 ************************************************************************/

#include<iostream>
#include<iostream>
#include <readline/readline.h>
#include <readline/history.h>
using namespace std;
int main()
{
    while(true)
    {
        char * p =readline("myshell:")  ;
        add_history(p);//加入历史列表
        p = readline("myshell:");
    }
}
