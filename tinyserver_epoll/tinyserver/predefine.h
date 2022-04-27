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
 * @LastEditTime : 2022-04-27 14:45:36
 * @FilePath     : /My_Cpp_test/tinyserver_epoll/tinyserver/predefine.h
 * @Description  : 
 * 
 * ******************************************
 */

#ifndef __PREDEFINE_H
#define __PREDEFINE_H

#include <unistd.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <assert.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/signal.h>
#include <errno.h>
#include <dbg.h> 

extern int sig_pipefd[2];

int setnonblock(int fd);
void addfd(int epollfd, int fd);
void removefd(int epollfd, int fd);
void sig_handler(int sig);
void addsig(int sig, void(handler)(int));

#endif /* __PREDEFINE_H */