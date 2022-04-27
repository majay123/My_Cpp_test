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
 * @Date         : 2022-04-26 13:28:33
 * @LastEditors  : MCD
 * @LastEditTime : 2022-04-27 14:37:35
 * @FilePath     : /My_Cpp_test/tinyserver_epoll/tinyserver/task.h
 * @Description  :
 *
 * ******************************************
 */

#ifndef __TASK_H__
#define __TASK_H__

#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "predefine.h"
#include "processpool.h"

#define MAX_BUFF_SIZE   (1024)
#define MAX_URL_LENGTH  (256)
#define MAX_FILE_LENGTH (512)

class task_conn
{
  public:
    task_conn(){};
    ~task_conn(){};
    void init(int epollfd, int sockfd, const sockaddr_in &client_addr)
    {
        m_epollfd = epollfd;
        m_sockfd = sockfd;
        m_address = client_addr;
        memset(m_buf, 0, sizeof(m_buf));
        m_read_idx = 0;
    }

    void accept_request();
    void bad_request(int clinet);
    void cat(int client, FILE *resource);
    void cannot_execute(int client);
    void error_die(const char *sc);
    void execute_cgi(int client, const char *path, const char *method, const char *query_string);
    int get_line(int sock, char *buf, int size);
    void headers(int client, const char *filename);
    void not_found(int client);
    void serve_file(int client, const char *filename);
    void unimplemented(int client);

  private:
    static const int BUFFER_SIZE = MAX_BUFF_SIZE;
    int m_epollfd;
    int m_sockfd;
    sockaddr_in m_address;
    char m_buf[BUFFER_SIZE];
    int m_read_idx;
};

#endif // __TASK_H__