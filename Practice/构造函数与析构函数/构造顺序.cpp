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
 * @LastEditTime : 2022-03-24 11:14:30
 * @FilePath     : /My_Cpp_test/Practice/构造函数与析构函数/构造顺序.cpp
 * @Description  : 
 * 
 * ******************************************
 */


#include <iostream>
#include <climits>

using namespace std;

/*
先构造成员
再构造自身（调用构造函数）
*/
class A
{
public:
    A() { cout << "Constructing A" << endl; }
    ~A() { cout << "Destroying A" << endl; }
};

class B
{
public:
    B() { cout << "Constructing B" << endl; }
    ~B() { cout << "Destroying B" << endl; }
};

class C
{
public:
    C() { cout << "Constructing C" << endl; }
    ~C() { cout << "Destroying C" << endl; }
    B b;
    A a;
};

int
main(int argc, char const *argv[])
{
    // B->A->C
    C c;
    // C->A->B
    return 0;
}