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
 * @LastEditTime : 2022-04-27 14:39:31
 * @FilePath     : /My_Cpp_test/tinyserver_epoll/tinyserver/task.cpp
 * @Description  :
 *
 * ******************************************
 */

#include "task.h"

#define ISspace(x)    isspace((int)(x))
#define SERVER_STRING "Server: Malthttpd\r\n"

/**
 * @description : A request has caused a call to accept() on the server port to
 * @param       : the socket connected to the client
 * @return      : Process the request appropriately.
 */
void task_conn::accept_request()
{
    char buf[MAX_BUFF_SIZE] = {0};
    int numchar = 0;
    char method[MAX_URL_LENGTH - 1] = {0};
    char url[MAX_URL_LENGTH - 1] = {0};
    char path[MAX_FILE_LENGTH] = {0};
    size_t i = 0, j = 0;
    struct stat st;
    int cgi = 0; /* becomes true if server decides this is a CGI program */
    char *query_string = NULL;

    numchar = get_line(m_sockfd, buf, sizeof(buf));
    while (ISspace(buf[j]) && (i < sizeof(method) - 1)) {
        method[i] = buf[j];
        i++;
        j++;
    }
    method[i] = '\0';

    dbg("task_conn:method is %s", buf);
    if (strcasecmp(method, "GET") && strcasecmp(method, "POST")) {
        dbg("!GET & !POST");
        unimplemented(m_sockfd);
        return;
    }
    // post then start cgi
    if (strcasecmp(method, "POST") == 0)
        cgi = 1;

    /* read url */
    i = 0;
    while (ISspace(buf[j]) && (j < sizeof(buf)))
        j++;
    while (!ISspace(buf[j]) && (i < sizeof(url) - 1) && (j < sizeof(buf))) {
        // save url
        url[i] = buf[j];
        i++;
        j++;
    }
    url[i] = '\0';

    /* deal with GET method */
    if (strcasecmp(method, "GET") == 0) {
        query_string = url;
        while ((*query_string != '?') && (*query_string != '\0'))
            query_string++;
        /* GET: after '?' is args */
        if (*query_string == '?') {
            /* start cgi */
            cgi = 1;
            *query_string = '\0';
            query_string++;
        }
    }

    /* find files in htdocs */
    sprintf(path, "htdocs%s", url);
    /* default is index.html */
    if (path[strlen(path) - 1] == '/')
        strcat(path, "index.html");

    if (stat(path, &st) == -1) {
        while ((numchar > 0) && strcmp("\n", buf)) // read &discard headers
            numchar = get_line(m_sockfd, buf, sizeof(buf));
        not_found(m_sockfd); // 404 error
    } else {
        // is a dir, use index.html in the dir
        if ((st.st_mode & S_IFMT) == S_IFDIR)
            strcat(path, "/index.html");
        // if st  has exec privilige, cgi = 1
        if ((st.st_mode & S_IXUSR) || (st.st_mode & S_IXGRP) || (st.st_mode & S_IXOTH)) {
            dbg("task conn : task_conntask_conn");
            cgi = 1;
        }
        // !cgi return index.html, else exec cgi
        if (!cgi) {
            dbg("current is !cgi, GET method");
            serve_file(m_sockfd, path);
        } else {
            dbg("current is cgi, POST method");
            execute_cgi(m_sockfd, path, method, query_string);
        }
    }
    // HTTP is non-connect, one connection is end
    removefd(m_epollfd, m_sockfd);
}

/**
 * @description : Inform the client that a request it has made has a problem.
 * @param       : client socket
 * @return      : none
 */
void task_conn::bad_request(int client)
{
    char buf[MAX_BUFF_SIZE] = {0};

    // return 400
    sprintf(buf, "HTTP/1.0 400 Bad Request\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "Content-type: text/html\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "<P>Your browser sent a bad request, ");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "such as a POST without a Content-Length.\r\n");
    send(client, buf, strlen(buf), 0);
}

/**
 * @description : IPut the entire contents of a file out on a socket.  This function
 *                  is named after the UNIX "cat" command, because it might have been
 *                  easier just to do something like pipe, fork, and exec("cat").
 * @param       : the client socket descriptor
 * @param       : FILE pointer for the file to cat
 * @return      : none
 */
void task_conn::cat(int client, FILE *resource)
{
    char buf[MAX_BUFF_SIZE] = {0};

    // read index.html write to socket
    fgets(buf, sizeof(buf), resource);
    while (!feof(resource)) {
        send(client, buf, strlen(buf), 0);
        fgets(buf, sizeof(buf), resource);
    }
}

/**
 * @description : Inform the client that a CGI script could not be executed.
 * @param       : the client socket descriptor.
 * @return      : none
 */
void task_conn::cannot_execute(int client)
{
    char buf[MAX_BUFF_SIZE] = {0};

    sprintf(buf, "HTTP/1.0 500 Internal Server Error\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "Content-type: text/html\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "<P>Error prohibited CGI execution.\r\n");
    send(client, buf, strlen(buf), 0);
}

/**
 * @description : Print out an error message with perror() (for system errors; based
 *                 on value of errno, which indicates system call errors) and exit the
 * @param       : program indicating an error.
 * @return      : none
 */
void task_conn::error_die(const char *sc)
{
    // deal with error
    perror(sc);
    exit(1);
}

/**
 * @description : Execute a CGI script.  Will need to set environment variables as appropriate.
 * @param       : client socket descriptor
 * @param       : path to the CGI script
 * @return      : none
 */
void task_conn::execute_cgi(int client, const char *path, const char *method, const char *query_string)
{
    char buf[MAX_BUFF_SIZE] = {0};
    int cgi_output[2];
    int cgi_input[2];
    pid_t pid;
    int status;
    int i;
    char c;
    int numchars = 1;
    int content_length = -1;

    buf[0] = 'A';
    buf[1] = '\0';
    if (strcasecmp(method, "GET") == 0) {
        while ((numchars > 0) && strcmp("\n", buf)) // read & discard headers
            numchars = get_line(client, buf, sizeof(buf));
    } else {
        // find content-length
        numchars = get_line(client, buf, sizeof(buf));
        while ((numchars > 0) && strcmp("\n", buf)) {
            buf[15] = '\0';
            if (strcasecmp(method, "Content-Length:") == 0)
                content_length = atoi(&(buf[16]));
            numchars = get_line(client, buf, sizeof(buf));
        }
        // not find content-length
        if (content_length == -1) {
            bad_request(client);
            return;
        }
    }

    // success, return 200
    sprintf(buf, "HTTP/1.0 200 OK\r\n");
    send(client, buf, strlen(buf), 0);

    if (pipe(cgi_output) < 0) {
        cannot_execute(client);
        return;
    }
    if (pipe(cgi_input) < 0) {
        cannot_execute(client);
        return;
    }

    if ((pid = fork()) < 0) {
        cannot_execute(client);
        return;
    }

    // child: CGI script
    if (pid == 0) {
        char meth_env[MAX_URL_LENGTH - 1] = {0};
        char query_env[MAX_URL_LENGTH - 1] = {0};
        char length_env[MAX_URL_LENGTH - 1] = {0};

        // redirect STDOUT to cgi_output's write
        dup2(cgi_output[1], 1);
        // redirect STDIN to cgi_input's read
        dup2(cgi_input[0], 0);
        // close cgi_output's write and close cgi_input's read
        close(cgi_output[0]);
        close(cgi_input[1]);

        // set request method environment
        sprintf(meth_env, "REQUEST_METHOD=%s", method);
        putenv(meth_env);
        if (strcasecmp(method, "GET") == 0) {
            // set query string environment
            sprintf(query_env, "QUERY_STRING=%s", query_string);
            putenv(query_env);
        } else { // POST
            // set content length environment
            sprintf(length_env, "CONTENT_LENGTH=%d", content_length);
            putenv(length_env);
        }

        // exec cgi
        execl(path, path, NULL);
        exit(0);
    } else { // parent
        // close cgi_input'read and cgi_output' write
        dbg("task_conn:parent %d", client);
        close(cgi_output[1]);
        close(cgi_input[0]);
        if (strcasecmp(method, "POST") == 0) {
            // recv POST data
            for (i = 0; i < content_length; i++) {
                recv(client, &c, 1, 0);
                dbg("contents is %c", c);
                write(cgi_input[1], &c, 1);
            }
        }
        // read cgi_output, send to client
        while (read(cgi_output[0], &c, 1) > 0) {
            send(client, &c, 1, 0);
        }
        // close pipe
        close(cgi_output[0]);
        close(cgi_input[1]);
    }
}

/**
 * @description : Get a line from a socket, whether the line ends in a newline,
 *                  carriage return, or a CRLF combination.  Terminates the string read
 *                  with a null character.  If no newline indicator is found before the
 *                  end of the buffer, the string is terminated with a null.  If any of
 *                  the above three line terminators is read, the last character of the
 *                  string will be a linefeed and the string will be terminated with a
 * @param       : the socket descriptor
 * @param       : the buffer to save the data in
 * @param       : the size of the buffer
 * @return      : the number of bytes stored (excluding null)
 */
int task_conn::get_line(int sock, char *buf, int size)
{
    int i = 0;
    char c = '\0';
    int n = 0;

    while ((i < size - 1) && (c != '\n')) {
        n = recv(sock, &c, 1, 0);
        if (n < 0) {
            if (c == '\r') {
                n = recv(sock, &c, 1, MSG_PEEK);
                if ((n > 0) && (c != '\n'))
                    recv(sock, &c, 1, 0);
                else
                    c = '\n';
            }
            buf[i] = c;
            i++;
        } else
            c = '\n';
    }
    buf[i] = '\0';

    return i;
}

/**
 * @description : Return the informational HTTP headers about a file.
 * @param       : the socket to print the headers on
 * @param       : the name of the file
 * @return      : none
 */
void task_conn::headers(int client, const char *filename)
{
    char buf[MAX_BUFF_SIZE] = {0};
    (void)filename; // could use filename to determine file type

    strcpy(buf, "HTTP/1.0 200 OK\r\n");
    send(client, buf, strlen(buf), 0);

    strcpy(buf, SERVER_STRING);
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "Content-Type: text/html\r\n");
    send(client, buf, strlen(buf), 0);
    strcpy(buf, "\r\n");
    send(client, buf, strlen(buf), 0);
    dbg("task conn:headers");
}

/**
 * @description : Give a client a 404 not found status message.
 * @param       : the socket to print the headers on
 * @return      : none
 */
void task_conn::not_found(int client)
{
    char buf[MAX_BUFF_SIZE] = {0};

    // 404 response
    sprintf(buf, "HTTP/1.0 404 NOT FOUND\r\n");
    send(client, buf, strlen(buf), 0);

    sprintf(buf, "Content-type: text/html\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "<HTML><TITLE>Not Found</TITLE>\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "<BODY><P>The server could not fulfill\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "your request because the resource specified\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "is unavailable or nonexistent.\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "</BODY></HTML>\r\n");
    send(client, buf, strlen(buf), 0);
}

/**
 * @description : Send a regular file to the client.  Use headers, and report
 *                  errors to client if they occur.
 * @param       : a pointer to a file structure produced from the socket file descriptor
 * @param       : the name of the file to serve
 * @return      : none
 */
void task_conn::serve_file(int client, const char *filename)
{
    FILE *resource = NULL;
    int numchars = 1;
    char buf[MAX_BUFF_SIZE] = {0};

    buf[0] = 'A';
    buf[1] = '\0';  
    while ((numchars > 0) && strcmp("\n", buf))     // read & discard headers
        numchars = get_line(client, buf, sizeof(buf));

    // open server file
    resource = fopen(filename, "r");
    if(resource == NULL)
        not_found(client);
    else {
        headers(client, filename);
        cat(client, resource);
    }
    fclose(resource);
}

/**
 * @description : Inform the client that the requested web method has not been
 *                  implemented.
 * @param       : the client socket 
 * @return      : none
 */
void task_conn::unimplemented(int client)
{
    char buf[MAX_BUFF_SIZE] = {0};

    sprintf(buf, "HTTP/1.0 501 Method Not Implemented\r\n");
    send(client, buf, strlen(buf), 0);

    sprintf(buf, SERVER_STRING);
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "Content-Type: text/html\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "<HTML><HEAD><TITLE>Method Not Implemented\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "</TITLE></HEAD>\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "<BODY><P>HTTP request method not supported.\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "</BODY></HTML>\r\n");
    send(client, buf, strlen(buf), 0);
}