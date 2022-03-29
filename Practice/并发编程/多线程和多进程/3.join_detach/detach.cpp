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
 * @Date         : 2022-03-29 15:16:14
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-29 15:29:06
 * @FilePath     : /My_Cpp_test/Practice/并发编程/多线程和多进程/3.join_detach/detach.cpp
 * @Description  : detach   分离式
 * 这用于从父线程分离新创建的线程
 * 在分离线程之前，请务必检查它是否可以joinable，
 * 否则可能会导致两次分离，并且双重detach()将导致程序终止
 * 如果我们有分离的线程并且main函数正在返回，那么分离的线程执行将被挂起
 * 
 * ******************************************
 */

#include <chrono>
#include <climits>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

void run(int count)
{
    while (count-- > 0)
        cout << count << endl;
    this_thread::sleep_for(chrono::seconds(3));
}

int main(int argc, char const *argv[])
{
    thread t1(run, 10);
    cout << "main()" << endl;
    t1.detach();
    if(t1.joinable())
        t1.detach();
    cout << "main() after" << endl;
    return 0;
}
