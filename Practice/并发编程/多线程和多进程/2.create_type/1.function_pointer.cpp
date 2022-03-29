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
 * @Date         : 2022-03-29 15:01:41
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-29 15:02:45
 * @FilePath     : /My_Cpp_test/Practice/并发编程/多线程和多进程/2.create_type/1.function_pointer.cpp
 * @Description  : 1.函数指针
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>
#include <thread>

using namespace std;

void func(int x)
{
    while(x-- > 0)
        cout << x << endl;
}

// 注意：如果我们创建多线程 并不会保证哪一个先开始
int main (int argc, char const *argv[])
{
    thread t1(func, 10);
    t1.join();

    return 0;
}