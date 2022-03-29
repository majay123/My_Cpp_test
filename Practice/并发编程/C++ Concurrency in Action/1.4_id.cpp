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
 * @Date         : 2022-03-29 13:50:26
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-29 13:55:53
 * @FilePath     : /My_Cpp_test/Practice/并发编程/1.4_id.cpp
 * @Description  : 
 * 
 * ******************************************
 */
#include <climits>
#include <iostream>
#include <thread>

using namespace std;

thread::id master_thread;

void do_master_thread_work()
{
    cout << "Master thread" << endl;
}

void do_common_work()
{
    cout << "Common thread" << endl;
}

void some_core_part_of_algorithm()
{
    if (this_thread::get_id() == master_thread) {
        do_master_thread_work();
    }

    do_common_work();
}

int main(int argc, char const *argv[])
{
    master_thread = this_thread::get_id();
    cout << "master_thread = " << master_thread << endl;
    cout << "master_thread 中运行: " << endl;
    some_core_part_of_algorithm();
    cout << "thread 中运行: " << endl;
    thread t(some_core_part_of_algorithm);
    t.join();

    return 0;
}
