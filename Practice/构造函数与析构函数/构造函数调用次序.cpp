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
 * @LastEditTime : 2022-03-24 11:05:16
 * @FilePath     : /My_Cpp_test/Practice/构造函数与析构函数/构造函数调用次序.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

class A
{
    int x;

public:
    A(int i = 19)
    {
        x = i;
        cout << "A------" << x << endl;
    }
};

class B
{
    int y;

public:
    B(int i = 100)
    {
        y = i;
        cout << "B------" << y << endl;
    }
};

class C
{
    int z;

public:
    C(int i)
    {
        z = i;
        cout << "C------" << z << endl;
    }
};

class D : public B
{
public:
    C c1, c2;
    A *a1 = new A(10);
    A a0, a4;
    D() : B(2),a4(4), c2(2), c1(1)
    {
        cout << "D------5" << endl;
    }
};

int main(int argc, char const *argv[])
{
    // B->c1->c2->a1->a0->a4->D
    D d;
    return 0;
}