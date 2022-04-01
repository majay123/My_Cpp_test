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
 * @Date         : 2022-04-01 10:24:50
 * @LastEditors  : MCD
 * @LastEditTime : 2022-04-01 10:26:52
 * @FilePath     : /My_Cpp_test/Practice/design_pattern/singleton/static_local_singleton.cpp
 * @Description  : 《Effective C++》中提出了一种简洁的singleton写法
 * 单线程下，正确。
 * C++11及以后的版本（如C++14）的多线程下，正确。
 * C++11之前的多线程下，不一定正确。
 * ******************************************
 */

#include <iostream>
#include <climits>
#include <thread>

using namespace std;

class singleton 
{
    private:
    static singleton *p;
    singleton() {}

    public:
    singleton *instance();
};

singleton *singleton::instance()
{
    static singleton p;
    return &p;
}

int main (int argc, char const *argv[])
{
    
    return 0;
}