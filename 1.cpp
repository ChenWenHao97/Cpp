#include<iostream>
#include <readline/readline.h>
#include <readline/history.h>
using namespace std;
int main()
{
	while(true)
	{
		char * p =readline("myshell:")	;
		add_history(p);
		p = readline("myshell:");
	}
}
