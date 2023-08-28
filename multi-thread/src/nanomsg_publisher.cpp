#include <stdio.h>
#include <string.h>

#include "nn.h"
#include "pubsub.h"
#include "common.hpp"



//inproc 标识用于多线程通信




//发送数据的socket初始化
int send_sock_init(int *sock, const char *url)
{
  *sock = nn_socket (AF_SP, NN_PUB);
  if (*sock < 0) {
    printf("create send data sock failed\r\n");
    return 1;
  }
  if (nn_bind(*sock, url) < 0) {
    printf("bind send data sock failed\r\n");
    return 1;
  }
  printf("send data socket init success...\r\n");
  return 0;
}



//发送数据
int send_data(int sock)
{
    string message;
    message = kb_message(1);

    if (nn_send(sock, message.c_str(), message.size(), 0) < 0) {
       std::cout << "send_data 40" << std::endl;
       return 1;
    }
    //std::cout << "send_data 44" << std::endl;

    //printf("Main Server Send:%s\r\n\r\n", message.c_str());
    return 0;
}




