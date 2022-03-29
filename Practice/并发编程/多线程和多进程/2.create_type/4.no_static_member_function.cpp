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
 * @Date         : 2022-03-29 15:08:14
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-29 15:14:18
 * @FilePath     : /My_Cpp_test/Practice/并发编程/多线程和多进程/2.create_type/4.no_static_member_function.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>
#include <thread>

using namespace std;

class Base
{
    public:
    void func(int x) {
        while(x-- > 0)
            cout << x << endl;
    }
};

int main (int argc, char const *argv[])
{
    Base b;

    thread t(&Base::func, &b, 10);
    t.join();

    return 0;
}