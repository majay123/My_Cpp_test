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
 * @Date         : 2022-03-22 09:29:52
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-22 09:35:26
 * @FilePath     : /My_Cpp_test/struct_test/ext_struct_func.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>
#include <stdio.h>

using namespace std;

struct Base
{
    int v;
    // private:     // error!
    int v3;

public:
    int v2;

    virtual void print() { printf("%s\n", "Base"); };
    Base() { cout << "Base constructor" << endl; };
    virtual ~Base() { cout << "Base destructor" << endl; };
};

struct Derived : Base
{
    Derived() { cout << "Derived constructor" << endl; };
    virtual ~Derived() { cout << "Derived destructor" << endl; };

public:
    int v2;
    void print() { printf("%s\n", "Derived"); };
};

int main(void)
{
    Base *b = new Derived();

    b->print();

    delete b;
}
