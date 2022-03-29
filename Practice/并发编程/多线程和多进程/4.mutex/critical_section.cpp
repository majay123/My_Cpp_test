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
 * @Date         : 2022-03-29 15:31:34
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-29 16:22:36
 * @FilePath     : /My_Cpp_test/Practice/并发编程/多线程和多进程/4.mutex/critical_section.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>
#include <thread>
#include <mutex>
// #include <dbg.h>

using namespace std;

int sum = 0;    //shared
mutex m;

void *countgold()
{
    int i;
    for (i = 0; i <= 100; i++){
        m.lock();
        sum +=i;
        m.unlock();
    }
    cout << "sum: " << sum << endl;
    // dbg(sum);

    return NULL;
}

int main (int argc, char const *argv[])
{
    thread t1 (countgold);
    thread t2 (countgold);

    t1.join();
    t2.join(); 

    return 0;
}