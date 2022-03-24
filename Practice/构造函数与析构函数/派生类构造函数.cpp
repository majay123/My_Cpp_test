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
 * @LastEditTime : 2022-03-24 11:21:59
 * @FilePath     : /My_Cpp_test/Practice/构造函数与析构函数/派生类构造函数.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

class Base
{
private:
    int x;

public:
    Base(int a)
    {
        x = a;
        cout << "Base constructor x = " << x << endl;
    }

    ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base
{
private:
    int y;

public:
    Derived(int a, int b) : Base(a)
    {
        y = b;
        cout << "Derived constructor y = " << y << endl;
    }
    ~Derived() { cout << "Derived destructor" << endl; }
};

int main(int argc, char const *argv[])
{
    Derived(1, 2);
    return 0;
}