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
 * @Date         : 2022-03-24 10:51:01
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-24 12:36:54
 * @FilePath     : /My_Cpp_test/Practice/构造函数与析构函数/派生类构造函数调用顺序.cpp
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
    A() { cout << "Constructing A" << endl; };
    ~A() { cout << "Destroying A" << endl; };
};
class B
{
public:
    B() { cout << "Constructing B" << endl; };
    ~B() { cout << "Destroying B" << endl; };
};
class C
{
public:
    C() { cout << "Constructing C" << endl; };
    ~C() { cout << "Destroying C" << endl; };
};
class D : public C
{
public:
    D() { cout << "Constructing D" << endl; };
    ~D() { cout << "Destroying D" << endl; };

    B b;
    A a;
    C c;
};

int main(int argc, char const *argv[])
{
    // C->B->A->C->D
    D d;
    return 0;
}