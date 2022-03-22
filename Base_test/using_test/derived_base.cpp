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
 * @LastEditTime : 2022-03-22 13:30:13
 * @FilePath     : /My_Cpp_test/Base_test/using_test/derived_base.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

class Base1
{
public:
    Base1() : value(10) {}
    virtual ~Base1() {}

    void test1() { cout << "Base1 test1 ..." << endl; }

protected:
    int value;
};

// 默认为私有继承
class Derived1 : Base1
{
public:
    void test2() { cout << "value is " << value << endl; }
};

class Base
{
public:
    Base() : value(20) {}
    virtual ~Base() {}

    void test1() { cout << "Base test1 ..." << endl; }

private:
    int value;
};

/**
 * 子类对父类成员的访问权限跟如何继承没有任何关系，
 * “子类可以访问父类的public和protected成员，不可以访问父类的private成员”——这句话对任何一种继承都是成立的。
 */
class Derived : Base
{
public:
    using Base::value;  // 所以这个是错误的，子类无法访问父类的private成员
    void test2() { cout << "value is " << value << endl; }
};

int main(int argc, const char *argv[])
{
    Derived1 d1;
    d1.test2();

    Derived d;
    d.test2();

    return 0;
}