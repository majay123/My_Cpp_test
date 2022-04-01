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
 * @Date         : 2022-03-31 15:33:59
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-31 17:13:39
 * @FilePath     : /My_Cpp_test/Practice/右值和移动/forward.cpp
 * @Description  :
 *
 * ******************************************
 */

#include <climits>
#include <iostream>
#include <thread>

#include "shape.h"

using namespace std;

void overloaded(int const &arg) { cout << "by lvalude \n"; }
void overloaded(int &&arg) { cout << "by rvalue\n"; }

template <typename t>
/* "t &&" with "t" being template param is special, and  adjusts "t" to be
   (for example) "int &" or non-ref "int" so std::forward knows what to do. */
void forwarding(t &&arg)
{
    cout << "via forward: ";
    overloaded(forward<t>(arg));
    cout << "via move: ";
    overloaded(move(arg)); // conceptually this would invalidate arg
    cout << "by simple passing: ";
    overloaded(arg);
}

void foo(const shape &)
{
    puts("foo (const shape&)");
}

void foo(shape &&)
{
    puts("foo (shape &&)");
}

template <typename T>
void bar(T &&s)
{
    foo(forward<T>(s));
}

int main(int argc, char const *argv[])
{
#if 0
    cout << "initial caller passes rvalue: \n";
    forwarding(5);
    cout << "================================"<< endl;
    cout << "initial caller passes lvalue: \n";
    int x = 5;
    forwarding(x);
    cout << "================================"<< endl;

    circle temp;
    bar(temp);
    cout << "================================"<< endl;
    bar(circle());
    cout << "================================"<< endl;
#else
    int i = 10;
    int&& k = 10;
    cout << "&i = " << &i << endl;
    cout << "&&i = " << &k << endl;
#endif
    

    return 0;
}