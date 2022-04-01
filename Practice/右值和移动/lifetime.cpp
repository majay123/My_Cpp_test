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
 * @Date         : 2022-03-31 14:39:36
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-31 15:12:22
 * @FilePath     : /My_Cpp_test/Practice/右值和移动/lifetime.cpp
 * @Description  :
 *
 * ******************************************
 */

#include <climits>
#include <iostream>
#include <thread>

using namespace std;

class shape
{
  public:
    shape() { cout << "shape" << endl; }

    ~shape() { cout << "Destroying shape" << endl; }
};

class circle : public shape
{
  public:
    circle() { cout << "circle" << endl; }

    ~circle() { cout << "Destroying circle" << endl; }
};

class triangle : public shape
{
  public:
    triangle() { cout << "triangle" << endl; }

    ~triangle() { cout << "Destroying triangle" << endl; }
};

class rectangle : public shape
{
  public:
    rectangle() { cout << "rectangle" << endl; }

    ~rectangle() { cout << "Destroying rectangle" << endl; }
};

class result
{
  public:
    result() { puts("result()"); }

    ~result() { puts("~result()"); }
};

result process_shape(const shape &shape1, const shape &shape2)
{
    puts("process_shape()");
    return result();
}

class Base
{
  public:
    Base() { cout << "Base()" << endl; }

    ~Base() { cout << "Destroying Base()" << endl; }
};

class Derived : public Base
{
  public:
    Derived() { cout << "Derived()" << endl; }

    ~Derived() { cout << "Destroying Derived()" << endl; }
};

string f() { return "abc"; }

void g()
{
    const string &s = f();
    cout << s << endl;
}

Derived factory()
{
    return Derived();
}

// glvalue ==> 泛左值   glvalue = lvalue + xvalue
// lvalue ==> 传统意义上的左值
// xvalue ==> 消亡值，通过右值应用产生
// rvalue ==> 传统意义上的右值  rvalue = prvalue + xvalue
// praluev ==> 纯右值 纯右值是传统右值的一部分，纯右值是表达式产生的中间值，不能取地址。


int main(int argc, char const *argv[])
{ 
    process_shape(circle(), triangle());
    cout << endl;

    // 临时对象延迟
    // result &&r = process_shape(circle(), triangle());
    // 临时对象延迟只对rvalue有用，而对xvalue无用
    result &&r = move(process_shape(circle(), triangle()));

    // const Base &b1 = factory();

    Base *b1 =  new Derived();
    delete b1;
    cout << endl;
    Derived d;
    Base &b2 = d;

    return 0;
}