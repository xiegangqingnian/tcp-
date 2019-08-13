#ifndef CHATROOM_CLIENT_H
#define CHATROOM_CLIENT_H

#include<string>
#include"Common.h"

using namespace std;


class Client
{
private:
    int sock;
    int pid;
    int epfd;
    int pipe_fd[2];

    bool isClientwork;

    Msg msg;

    char send_buf[BUF_SIZE];
    char recv_buf[BUF_SIZE];

    struct sockaddr_in serverAddr;
    
public:
    Client();

    void Connect();
    void Close();
    void Start();
};




#endif // !CHATROOM_CLIEN

