#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pthread.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define BUFFER_SIZE 512

int Socket(int ,int,int);
void Bind(int ,const struct sockaddr*sa,socklen_t salen);
void Listen(int ,int);
int Accept(int,struct sockaddr*,socklen_t*);
void handleAccept(int);
void handleHttp(int);
int getRequest(int);


int main(int argc,char **argv)
{
    const int port = 1024;//listen port
    int listenfd=Socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in serverAddr;
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_addr.s_addr=INADDR_ANY;
    serverAddr.sin_port=htons(port);
    Bind(listenfd,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
    Listen(listenfd,5);

    while(true)
    {
        handleAccept(listenfd);
    }

}

int Socket(int family , int type,int protocol)
{
    int     n;
    if ( (n = socket(family, type, protocol)) < 0)
    {
        printf("socket error\r\n");
        return -1;
    }
    return(n);

}
void
Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
    if (bind(fd, sa, salen) < 0)
    {
        printf("bind error\r\n");
        exit(-1);
    }
}
void
Listen(int fd, int backlog)
{
    char    *ptr;

        /*4can override 2nd argument with environment variable */
    if ( (ptr = getenv("LISTENQ")) != NULL)
        backlog = atoi(ptr);

    if (listen(fd, backlog) < 0)
    {
        printf("listen error\r\n");
        return ;
    }
}
int
Accept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
    int     n;

again:
    if ( (n = accept(fd, sa, salenptr)) < 0) {
#ifdef  EPROTO
        if (errno == EPROTO || errno == ECONNABORTED)
#else
        if (errno == ECONNABORTED)
#endif
            goto again;
        else
        {
            printf("accept error\r\n");
            return -1;
        }
    }
    return(n);
}

void handleAccept(int listenfd)
{
    sockaddr_in clientAddr;
    socklen_t clientLen=sizeof(clientAddr);
    int connfd=Accept(listenfd,(sockaddr *)&clientAddr,&clientLen);
    handleHttp(connfd);
    close(connfd);
}

void handleHttp(int connfd)
{
    if(getRequest(connfd)<0)
    {
        perror("http request get error");
        exit(-1);
    }
}
int getRequest(int socket)
{
    int msgLen=0;
    char buffer[BUFFER_SIZE];
    memset (buffer,'\0', BUFFER_SIZE);
    if ((msgLen = recv(socket, buffer, BUFFER_SIZE, 0)) == -1)
    {
        printf("Error handling incoming request");
        return -1;
    }
    stringstream ss;
    ss<<buffer;
    string method;
    ss>>method;
    string uri;
    ss>>uri;
    string version;
    ss>>version;
    //
    string statusCode("200 OK");
    string contentType("text/html");
    string content("<html><head><title>my simple httpserver</title></head><h1>hello zx world</h1></body></html>");
    string contentSize(std::to_string(content.size()));
    string head("\r\nHTTP/1.1 ");
    string ContentType("\r\nContent-Type: ");
    string ServerHead("\r\nServer: localhost");
    string ContentLength("\r\nContent-Length: ");
    string Date("\r\nDate: ");
    string Newline("\r\n");
    time_t rawtime;
    time(&rawtime);
    string message;
    message+=head;
    message+=statusCode;
    message+=ContentType;
    message+=contentType;
    message+=ServerHead;
    message+=ContentLength;
    message+=contentSize;
    message+=Date;
    message+=(string)ctime(&rawtime);
    message+=Newline;

    int messageLength=message.size();
    int n;
    n=send(socket,message.c_str(),messageLength,0);
    n=send(socket,content.c_str(),content.size(),0);   
    return n;
}