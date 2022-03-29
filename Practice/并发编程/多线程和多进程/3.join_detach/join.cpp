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
 * @Date         : 2022-03-29 15:16:22
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-29 15:23:18
 * @FilePath     : /My_Cpp_test/Practice/并发编程/多线程和多进程/3.join_detach/join.cpp
 * @Description  : join 注意点
 * 一旦线程开始，我们要想等待线程完成，需要在该对象上调用join()
 * 双重join将导致程序终止
 * 在join之前我们应该检查显示是否可以被join,通过使用joinable()
 * 
 * ******************************************
 */

#include <chrono>
#include <climits>
#include <iostream>
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
    thread t1(run, 20);
    cout << "main()" << endl;
    t1.join();

    if(t1.joinable()) {
        cout << "double join" << endl;
        t1.join();
    }
    cout << "main() after " << endl;

    return 0;
}