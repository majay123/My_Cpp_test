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
 * @Date         : 2022-03-21 10:37:20
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-21 14:04:47
 * @FilePath     : /My_Cpp_test/virtual/set3/full_virde.cpp
 * @Description  : 将基类的析构函数声明为虚函数
 * 输出结果：
 *      Constructing base
 *      Constructing derived
 *      Destructing derived
 *      Destructing base
 * 
 * ******************************************
 */

#include <iostream>

using namespace std;

class Base {
    public:
        Base() { cout << "Constructing base \n"; }
        ~Base() { cout << " Destructing base \n"; }
};

class Derived : public Base{
    public:
        Derived() {cout << "Constructing Derived \n";}
        ~Derived() { cout << " Destructing Derived \n";}
};

int main(void)
{
    Derived *d = new Derived();
    Base *b = d;

    delete d;
    return 0;
}