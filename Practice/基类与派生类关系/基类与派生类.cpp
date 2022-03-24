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
 * @Date         : 2022-03-23 16:54:24
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-24 10:16:14
 * @FilePath     : /My_Cpp_test/Practice/基类与派生类关系/基类与派生类.cpp
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

void f1(A a, int x)
{
    a.setA(x);
}

void f2(A *a, int x)
{
    a->setA(x);
}

void f3(A &a, int x)
{
    a.setA(x);
}

int main(int argc, char const *argv[])
{
    A a1, *pA;
    B b1, *pB;

    a1.setA(1);
    b1.setA(2);

    // 把派生类对象赋值给基类对象
    a1 = b1;
    cout << a1.getA() << endl;
    cout << b1.getA() << endl;

    a1.setA(10);
    cout << a1.getA() << endl;
    cout << b1.getA() << endl;

    // 把派生类对象的地址赋值给基类指针
    pA = &b1;
    pA->setA(20);
    cout << pA->getA() << endl;
    cout << b1.getA() << endl;

    // 用派生类对象初始化基类对象的引用
    A &ra = b1;
    ra.setA(30);
    cout << ra.getA() << endl;
    cout << pA->getA() << endl;
    cout <<b1.getA() << endl;
    b1.setA(7);
    cout << b1.getA() << endl;

    f1(b1, 100);    //无法实现对 a的赋值
    cout << "==============" << endl;
    cout << b1.getA() << endl;

    f2(&b1, 200);
    cout << "==============" << endl;
    cout << b1.getA() << endl;

    f3(b1, 300);
    cout << "==============" << endl;
    cout << b1.getA() << endl;

    return 0;

    return 0;
}