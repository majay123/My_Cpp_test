/*
 *
 * 　　┏┓　　　┏┓+ +
 * 　┏┛┻━━━┛┻┓ + +
 * 　┃　　　　　　　┃ 　
 * 　┃　　　━　　　┃ ++ + + +
 *  ████━████ ┃+
 * 　┃　　　　　　　┃ +
 * 　┃　　　┻　　　┃
 * 　┃　　　　　　　┃ + +
 * 　┗━┓　　　┏━┛
 * 　　　┃　　　┃　　　　　　　　　　　
 * 　　　┃　　　┃ + + + +
 * 　　　┃　　　┃
 * 　　　┃　　　┃ +  神兽保佑
 * 　　　┃　　　┃    代码无bug　　
 * 　　　┃　　　┃　　+　　　　　　　　　
 * 　　　┃　 　　┗━━━┓ + +
 * 　　　┃ 　　　　　　　┣┓
 * 　　　┃ 　　　　　　　┏┛
 * 　　　┗┓┓┏━┳┓┏┛ + + + +
 * 　　　　┃┫┫　┃┫┫
 * 　　　　┗┻┛　┗┻┛+ + + +
 *
 *
 *
 * ************Copyright 2022 MCD************
 *
 * @version      :
 * @Company      : HOPE
 * @Author       : MCD
 * @Date         : 2022-04-26 09:37:35
 * @LastEditors  : MCD
 * @LastEditTime : 2022-04-28 10:15:35
 * @FilePath     : /My_Cpp_test/tinyserver_epoll/tinyserver/main.cpp
 * @Description  :
 *
 * ******************************************
 */

#include <arpa/inet.h>
#include <assert.h>
#include <dbg.h>
#include <errno.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "daemon.h"
#include "predefine.h"
#include "processpool.h"
#include "task.h"

#define DEFAULT_PORT (8001)

using namespace std;

int main(int argc, char const *argv[])
{
    int listen_fd, reuse, ret;
    struct sockaddr_in servaddr;

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        dbg("create socket error");
        exit(EXIT_FAILURE);
    }

    if(setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
        dbg("reuse setsockopt error");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(DEFAULT_PORT);
    
    ret = bind(listen_fd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if(ret < 0) {
        dbg("bind socket error");
        exit(EXIT_FAILURE);
    }

    ret = listen(listen_fd, SOMAXCONN);
    if(ret < 0) {
        dbg("listen socket error");
        exit(EXIT_FAILURE);
    }

    // 创建进程池
    processpool<task_conn> *pool = processpool<task_conn>::create(listen_fd);
    if(pool) {
        pool->run();
    }

    delete pool;
    close(listen_fd);

    return 0;
}
