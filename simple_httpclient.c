#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
int main()
{
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    char buf[400];
    memset(buf, 0, sizeof(buf));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr.s_addr = inet_addr("45.76.192.193"); //服务器地址

    int client_fd;
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) //创建客户端套接字
    {
       // my_error("client socket", __LINE__);
    }
    if (connect(client_fd, (struct sockaddr *)&addr, sizeof(struct sockaddr)) < 0) //将套接字绑定到服务器地址
    {
        //my_error("connect", __LINE__);
    }
    char buff[] = "GET / HTTP/1.1\r\nHost: hepangda.com\r\n\r\n";
    send(client_fd, buff, sizeof(buff), 0);
    char recvb[20000];
    recv(client_fd,recvb, 20000, 0);
    puts(recvb);
    close(client_fd);
    return 0;
}