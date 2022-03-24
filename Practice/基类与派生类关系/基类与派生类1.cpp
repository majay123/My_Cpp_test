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
 * @Date         : 2022-03-24 10:07:32
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-24 10:48:43
 * @FilePath     : /My_Cpp_test/Practice/基类与派生类关系/基类与派生类1.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

class A
{
    int a;

public:
    void setA(int x) { a = x; }
    int getA() { return a; }
};

class B : public A
{
    int b;

public:
    void setB(int x) { b = x; }
    int getB() { return b; }
};

void f(A a, int x)
{
    a.setA(x);
}


int main(int argc, char const *argv[])
{
    A a;
    B b;

    a.setA(199);
    cout << a.getA() << endl;
    a = b;
    b.setA(100);
    cout << b.getA() << endl;

    b.setA(20);
    
    // 不明白 这个函数 为什么无法改a的值？？？？？？？
    f(b, 10);
    cout << b.getA() << endl;

    // cout << b << endl;
    // cout << &b << endl;
    // printf("%p, %p" , b, &b);

    return 0;
}