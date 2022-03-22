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
 * @LastEditTime : 2022-03-21 11:11:45
 * @FilePath     : /My_Cpp_test/virtual/set3/copy_construct.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>

using namespace std;

class Base
{
public:
public:
};

class Derived : public Base
{
public:
    Derived() {
        cout << "Derived cleate" << endl;
    }

    Derived(const Derived &rhs) {
        cout << "Derived created by deep copy" << endl;
    }

    ~Derived() {
        cout << "Derived destroyed" << endl;
    }
};

int
main(int argc, char **argv)
{
    Derived s1;

    return 0;
}