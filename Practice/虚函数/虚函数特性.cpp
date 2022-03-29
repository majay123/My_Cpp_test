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
 * @Date         : 2022-03-24 13:27:39
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-24 13:47:58
 * @FilePath     : /My_Cpp_test/Practice/虚函数/虚函数特性.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

class A
{
public:
    void f(int i) { cout << "A::f()" << endl; }
};

class B : public A
{
public:
    virtual void f(int i) { cout << "B::f()" << endl; }
};

class C : public B
{
public:
    void f(int i) { cout << "C::f()" << endl; }
};

//一旦将某个成员函数声明为虚函数后，它在继承体系中就永远为虚函数了
class D : public C
{
public:
    void f(int i) { cout << "D::f()" << endl; }
};

int main(int argc, char const *argv[])
{
    A *pA, a;
    B *pB, b;
    C c;
    D d;
    pA = &a;    pA->f(1);   // A::f()   
    pB = &b;    pB->f(1);   // B::f()
    pB = &c;    pB->f(1);   // C::f()
    pB = &d;    pB->f(1);   // D::f()
    return 0;
}