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
 * @LastEditTime : 2022-04-27 14:44:25
 * @FilePath     : /My_Cpp_test/tinyserver_epoll/tinyserver/processpool.h
 * @Description  :
 *
 * ******************************************
 */

#ifndef __PROCESSPOOL_H__
#define __PROCESSPOOL_H__

#include <dbg.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <sys/epoll.h>
#include <sys/signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "predefine.h"
#include "task.h"

#define DEFAULT_PROCESS_NUMBER (8)

class process
{
  public:
    process() : m_pid(-1) {}
    pid_t m_pid;
    int m_pipefd[2];
};

template <typename T>
class processpool
{
  private:
    processpool(int listen_fd, int process_number = DEFAULT_PROCESS_NUMBER);
    void run_parent(void);
    void run_child(void);
    void setup_sig_pipe(void);

  public:
    static processpool<T> *create(int listenfd, int process_number = DEFAULT_PROCESS_NUMBER);
    ~processpool(void);
    void run();

  private:
    static const int MAX_PROCESS_NUMBER = 16;
    static const int USER_PER_PROCESS = 65536;
    static const int MAX_EVENT_NUMBER = 10000;
    int m_process_number;
    int m_epollfd;
    int m_listenfd;
    int m_stop;
    int m_idx;
    process *m_sub_process;
    static processpool<T> *m_instance;
};

template <typename T>
processpool<T> *processpool<T>::m_instance = NULL;

template <typename T>
processpool<T> *processpool<T>::create(int listenfd, int process_number)
{
    if (!m_instance) {
        m_instance = new processpool<T>(listenfd, process_number);
    }

    return m_instance;
}

template <typename T>
processpool<T>::~processpool()
{
    delete[] m_sub_process;
}

template <typename T>
processpool<T>::processpool(int listenfd, int process_number)
    : m_listenfd(listenfd), m_process_number(process_number), m_idx(-1), m_stop(false)
{
    assert((process_number > 0) && (process_number <= MAX_PROCESS_NUMBER));
    m_sub_process = new process[process_number];

    for (int i = 0; i < process_number; i++) {
        int ret = socketpair(PF_INET, SOCK_STREAM, 0, m_sub_process[i].m_pipefd);
        assert(ret == 0);

        m_sub_process[i].m_pid = fork();
        assert(m_sub_process[i].m_pid >= 0);
        if (m_sub_process[i].m_pid > 0) {
            close(m_sub_process[i].m_pipefd[1]);
            continue;
        } else {
            close(m_sub_process[i].m_pipefd[0]);
            m_idx = i;
            break;
        }
    }
}

template <typename T>
void processpool<T>::run()
{
    if (m_idx != -1) {
        dbg("child pid is %d", getpid());
        run_child();
        return;
    }
    dbg("parent pid is %d", getpid());
    run_parent();
}

template <typename T>
void processpool<T>::run_parent()
{
    setup_sig_pipe();
    addfd(m_epollfd, m_listenfd);

    epoll_event events[MAX_EVENT_NUMBER];
    int sub_process_counter = 0;
    int number;
    int new_conn = 1;
    int ret;

    while (!m_stop) {
        number = epoll_wait(m_epollfd, events, MAX_EVENT_NUMBER, -1);
        if ((number < 0) && (errno != EINTR)) {
            dbg("parent epoll failure");
            break;
        }

        for (int i = 0; i < number; i++) {
            int sockfd = events[i].data.fd;
            if (sockfd == m_listenfd) {
                int sn = sub_process_counter;
                do {
                    if (m_sub_process[sn].m_pid != -1) {
                        break;
                    }
                    sn = (sn + 1) % m_process_number;
                } while (sn != sub_process_counter);

                if (m_sub_process[sn].m_pid < 0) {
                    m_stop = true;
                    break;
                }
                sub_process_counter = (sn + 1) % m_process_number;
                send(m_sub_process[sn].m_pipefd[0], (char *)&new_conn, sizeof(new_conn), 0);
                dbg("new_conn send to child process");
            } else if ((sockfd == sig_pipefd[0]) && (events[i].events & EPOLLIN)) {
                dbg("recv signal parent process");
                int signal = 0;
                ret = recv(sig_pipefd[0], (char *)&signal, sizeof(signal), 0);
                if (ret < 0)
                    continue;
                else {
                    switch (signal) {
                    case SIGCHLD: {
                        pid_t pid;
                        int stat;

                        while ((pid = waitpid(-1, &stat, WNOHANG)) > 0) {
                            for (int s = 0; s < m_process_number; s++) {
                                if (m_sub_process[s].m_pid == pid) {
                                    dbg("child process %d exit", pid);
                                    m_sub_process[s].m_pid = -1;
                                    close(m_sub_process[s].m_pipefd[0]);
                                }
                            }
                        }
                        m_stop = true;
                        for (int s = 0; s < m_process_number; s++) {
                            if (m_sub_process[s].m_pid != -1)
                                m_stop = false;
                        }
                        break;
                    }
                    case SIGINT:
                    case SIGTERM: {
                        dbg("all the child will be killed");
                        for (int s = 0; s < m_process_number; s++) {
                            kill(m_sub_process[i].m_pid, SIGTERM);
                        }
                        m_stop = true;
                        break;
                    }
                    }
                }
            } else
                continue;
        }
    }
    dbg("process is stopped");

    removefd(m_epollfd, m_listenfd);
    close(m_epollfd);
}

template <typename T>
void processpool<T>::run_child()
{
    setup_sig_pipe();
    int pipefd = m_sub_process[m_idx].m_pipefd[1];
    addfd(m_epollfd, pipefd);

    epoll_event events[MAX_EVENT_NUMBER];
    T *users = new T[USER_PER_PROCESS];
    assert(users);

    int number = 0;
    int ret = -1;

    while (!m_stop) {
        number = epoll_wait(m_epollfd, events, MAX_EVENT_NUMBER, -1);
        dbg("child process %d get %d events", getpid(), number);
        if ((number < 0) && (errno == EINTR)) {
            dbg("child process epoll failed");
            break;
        }

        for (int i = 0; i < number; i++) {
            int sockfd = events[i].data.fd;
            dbg("processpool sockfd is %d", sockfd);

            if ((sockfd == pipefd) && (events[i].events & EPOLLIN)) {
                int client = 0;
                ret = recv(sockfd, (char *)&client, sizeof(client), 0);
                if ((ret < 0) && (errno != EINTR) || (ret == 0))
                    continue;
                else {
                    struct sockaddr_in client_address;
                    socklen_t client_addrlength = sizeof(client_address);
                    int connfd = accept(m_listenfd, (struct sockaddr *)&client_address, &client_addrlength);
                    if (connfd < 0) {
                        dbg("accpet error, errno is %d", errno);
                        continue;
                    }
                    addfd(m_epollfd, connfd);
                    users[connfd].init(m_epollfd, connfd, client_address);
                }
            } else if ((sockfd == sig_pipefd[0]) && (events[i].events & EPOLLIN)) {
                int signal;
                int ret = recv(sig_pipefd[0], (char *)&signal, sizeof(signal), 0);
                if (ret < 0) {
                    dbg("recv error!");
                    continue;
                } else {
                    switch (signal) {
                    case SIGCHLD: {
                        dbg("get signal SIGCHLD");
                        pid_t pid;
                        int stat;
                        while ((pid = waitpid(-1, &stat, WNOHANG)) > 0) {
                            dbg("child process %d exit", pid);
                            continue;
                        }
                        break;
                    }
                    case SIGINT:
                    case SIGTERM: {
                        dbg("process in pool will be stopped");
                        m_stop = true;
                        break;
                    }
                    }
                }
            } else if (events[i].events & EPOLLIN) {
                users[sockfd].accept_request();
            } else
                continue;
        }
    }

    delete[] users;
    users = NULL;
    close(pipefd);
    close(m_epollfd);
}

template <typename T>
void processpool<T>::setup_sig_pipe()
{
    m_epollfd = epoll_create(5);
    assert(m_epollfd != -1);
    int ret = socketpair(PF_INET, SOCK_STREAM, 0, sig_pipefd);
    setnonblock(sig_pipefd[1]);
    addfd(m_epollfd, sig_pipefd[0]);
    addsig(SIGCHLD, sig_handler);
    addsig(SIGTERM, sig_handler);
    addsig(SIGINT, sig_handler);
}

#endif // !_