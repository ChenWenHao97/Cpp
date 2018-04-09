1、考察优先级
#include<stdio.h>
int main()
{
   char c;
   while(c =getchar()!=EOF)
     putchar(c);
}

2、不能没有分配空间就使用
#include<stdio.h>
#include<string.h>
int main()
{
    char *s;
    char arr[]="hello";
    strcpy(s,arr);
}
3、宏定义只是文本替换
#include<stdio.h>
#define CUBE(x) x*x*x
int main()
{
    int a = 5;
    printf("%d",CUBE(a+10));
}
4、缓冲区大小位1024，所以Group统计出来是1024个
#include<stdio.h>  
int  main()  
{  
    for(int i=1;i<=1000;i++)  
    {  
        fprintf(stdout,"Group");  
        fprintf(stderr,"XiYouLinux\n");  
              
    }  
    return 0;  
}  
5、-1是取了4个字节，而不是数组任何一个值
#include<stdio.h>
int main(int argc, char *argv[])
{
    char n[] = { -1, -1, -1, -1 };
    printf("%d\n", *(int *)n);
}

春风十里，我在小组等你