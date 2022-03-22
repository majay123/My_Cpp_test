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
 * @Date         : 2022-03-22 10:30:36
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-22 10:55:32
 * @FilePath     : /My_Cpp_test/Base_test/firend_test/firend_class.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

class A
{
public:
    A(int _a) : a(_a){};
    friend class B;

private:
    int a;
};

class B
{
public:
    int geta(A ca)
    {
        return ca.a;
    }
};

int main(int argc, const char *argv[])
{
    A a(3);

    B b;

    cout << b.geta(a) << endl;
    return 0;
}