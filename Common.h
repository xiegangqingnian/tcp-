#ifndef CHATROOM_COMMON_H
#define CHATROOM_COMMON_h

#include<iostream>
#include<list>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/epoll.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h> //pipe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 服务器ip
#define SERVER_IP "127.0.0.1"
// 服务器端口
#define SERVER_PORT 8888
//epoll支持最大句柄数
#define EPOLL_SIZE 5000
//缓冲区大小 65535
#define BUF_SIZE 0xFFFF
// 欢迎加入聊天室
#define SERVER_WELCOME "Welcome you join to the chat room! Your chat ID is: Client #%d "

#define SERVER_MESSAGE "ClientID %d say >> %s "
#define SERVER_PRIVATE_MESSAGE "Client %d say to you privately >> %s "
#define SERVER_PRIVATE_ERROR_MESSAGE "Client %d is not in the chat room yet~"

#define EXIT "EXIT"

#define CAUTION "There is only one int the char room!"

static void addfd(int epollfd, int fd, bool enable_et)
{
	struct epoll_event ev;
	ev.data.fd = fd;
	ev.events = EPOLLIN;
	
	if(enable_et)
		ev.events = EPOLLIN | EPOLLET;
			//句柄      动作           要监听的标识符            
	epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev); //时间注册函数
	fcntl(fd, F_SETFL, fcntl(fd,F_GETFD, 0)| O_NONBLOCK);//将文件描述符设置为非阻塞
	printf("fd added to epoll!\n\n");
}
struct  Msg
{
	int type;
	int fromID;
	int toID;
	char content[BUF_SIZE];

};
#endif //CHATROOM_COMMON_H

