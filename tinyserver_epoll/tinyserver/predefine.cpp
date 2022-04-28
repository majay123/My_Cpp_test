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
 * @LastEditTime : 2022-04-28 10:16:40
 * @FilePath     : /My_Cpp_test/tinyserver_epoll/tinyserver/predefine.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include "predefine.h"

int sig_pipefd[2];

/**
 * @brief setnoblock
 * @param fd
 * @return
 */
int setnonblock(int fd)
{
    int old_option = fcntl(fd, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd, F_SETFL, new_option);
    return old_option;
}

/**
 * @brief addfd
 * @param epollfd
 * @param fd
 */
void addfd(int epollfd, int fd)
{
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
    setnonblock(fd);
}

/**
 * @brief removefd
 * @param epollfd
 * @param fd
 */
void removefd(int epollfd, int fd)
{
    epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, 0);
    close(fd);
}

/**
 * @brief sig_handler
 * @param sig
 */
void sig_handler(int sig)
{
    if (sig == SIGTERM)
        dbg("sig_handle SIGTERM");
    if (sig == SIGCHLD)
        dbg("sig_handle SIGCHLD");

    int save_errno = errno;
    int msg = sig;
    send(sig_pipefd[1], (char *)&msg, sizeof(msg), 0);
    errno = save_errno;
}

/**
 * @brief
 *
 * @param sig
 * @param handler
 */
void addsig(int sig, void(handler)(int))
{
    dbg("addsig test begin");
    if(sig == SIGTERM)
        dbg("addsig signal SIGTERM");
    
    struct sigaction action;
    memset(&action, 0, sizeof(action));
    action.sa_handler = handler;
    sigfillset(&action.sa_mask);
    assert(sigaction(sig, &action, NULL) != -1);
}