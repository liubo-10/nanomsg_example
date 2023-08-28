#include <stdio.h>


#include "nn.h"
#include "pubsub.h"




//接收数据的socket初始化
int recieve_sock_init(int *sock, const char *url)
{
    *sock = nn_socket (AF_SP, NN_SUB);
    if (*sock < 0) {
      printf("create recieve data sock failed\r\n");
      return 1;
    }
    //设置订阅主题为全部
    nn_setsockopt(*sock, NN_SUB, NN_SUB_SUBSCRIBE, "", 0);
  
    if (nn_connect(*sock, url) < 0) {
    printf("connect recieve data sock failed\r\n");
    return 1;
    }
    printf("recieve data socket init success...\r\n");
    return 0;

}







 