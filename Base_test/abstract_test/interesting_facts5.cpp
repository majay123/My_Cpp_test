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
 * @Date         : 2022-03-18 09:21:07
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-18 10:00:41
 * @FilePath     : /My_C++_Test/abstract_test/interesting_facts5.cpp
 * @Description  : 构造函数不能是虚函数，而析构函数可以是虚析构函数。
 * 例如：当基类指针指向派生类对象并删除对象时，我们可能希望调用适当的析构函数。如果析构函数不是虚拟的，则只能调用基类析构函数。
 * 
 * ******************************************
 */

#include <iostream>

using namespace std;

class Base
{
public:
    Base() { cout << "Constructor: Base" << endl; }
    virtual ~Base() { cout << " Destructor: Base" << endl; }
};

class Derived : public Base
{
public:
    Derived() { cout << "Constructor: Derived" << endl; }
    ~Derived() { cout << " Destructor: Derived" << endl; }
};

int main(void)
{
    Base *Ver = new Derived();
    delete Ver;
    return 0;
}