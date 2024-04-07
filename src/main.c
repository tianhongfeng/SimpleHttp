#include <stdio.h>
#include <unistd.h>
#include "Server.h"
#include <stdlib.h>

int main(int argc, char* argv[]) {
  
    if (argc < 3) {
        printf("port path\n");
        return -1;
    }
    unsigned short int  port = atoi(argv[1]);
    // 切换服务器工作目录
    chdir(argv[2]);
    // 初始化用于监听的套接字
    int lfd = initListenFd(10000);

    // 启动服务程序
    epollRun(lfd);

    return 0;
}
