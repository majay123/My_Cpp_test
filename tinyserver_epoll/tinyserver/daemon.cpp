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
 * @LastEditTime : 2022-04-27 14:41:55
 * @FilePath     : /My_Cpp_test/tinyserver_epoll/tinyserver/daemon.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dbg.h>

#include "daemon.h"

int daemon_init(void)
{
    pid_t pid;

    pid = fork();
    if(pid < 0) {
        dbg("daemon fork error");
        return -1;
    } else if(pid) {
        exit(EXIT_SUCCESS);
    }

    if(setsid() < 0) {
        dbg("daemon setsid error");
        return -1;
    }
    signal(SIGHUP, SIG_IGN);

    pid = fork();
    if(pid < 0) {
        dbg("daemon second fork error");
        return -1;
    } else if(pid) {
        exit(EXIT_SUCCESS);
    }

    for(int i = 0; i < MAX_DATA_LENGTH; i++) {
        close(i);
    }
    open("/dev/null", O_RDONLY);
    open("/dev/null", O_RDWR);
    open("/dev/null", O_RDWR);

    return 0;
}