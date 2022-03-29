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
 * @Date         : 2022-03-29 15:03:41
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-29 15:06:47
 * @FilePath     : /My_Cpp_test/Practice/并发编程/多线程和多进程/2.create_type/2.lambda_function.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <climits>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

// 注意：如果我们创建多线程 并不会保证哪一个先开始
int main(int argc, char const *argv[])
{
    // 2.Lambda函数
    auto fun = [](int x) {
        while (x-- > 0)
            cout << x << endl;
    };

    thread t1(fun, 6);
    t1.join();

    thread t2([](int x) {
        while (x-- > 0)
            cout << x << endl;
    }, 11);
    t2.join();

    return 0;
}