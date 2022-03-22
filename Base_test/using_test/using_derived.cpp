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
 * @Date         : 2022-03-22 13:15:39
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-22 13:36:40
 * @FilePath     : /My_Cpp_test/Base_test/using_test/using_derived.cpp
 * @Description  : 函数重载
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

class Base
{
public:
    void f() { cout << "Base func" << endl; }
    void f(int n) { cout << "Base::func(int n)" << endl; }
};

class Derived : private Base
{
public:
    using Base::f;
    void f(int n) { cout << "Derived func(int n)" << endl; }
};

int main(int argc, const char *argv[])
{
    Base b;
    Derived d;

    d.f();
    d.f(1);
    return 0;
}