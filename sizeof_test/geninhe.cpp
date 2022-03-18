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
 * @Date         : 2022-03-17 15:10:57
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-17 16:09:17
 * @FilePath     : /My_C++_Test/sizeof_test/geninhe.cpp
 * @Description  : 1.普通单继承,继承就是基类+派生类自身的大小(注意字节对齐)
 * 注意：类的数据成员按其声明顺序加入内存，与访问权限无关，只看声明顺序。
 * 2.虚单继承，派生类继承基类vptr
 * 
 * ******************************************
 */

#include <iostream>

using namespace std;

class A
{
public:
    char a;
    int b;
};

/**
 * @brief 此时B按照顺序：
 * char a
 * int b
 * short a
 * long b
 * 根据字节对齐4+4=8+8+8=24
 */
class B : A
{
public:
    short a;    // 字节对齐
    long b;
};

class C
{
    A a;
    char c;
};

class A1
{
    virtual void func(){};
};

class C1 : public A1
{
};

int main(){
    cout << sizeof(A) <<endl;   // 8
    cout << sizeof(B) <<endl;   // 24
    cout << sizeof(C) <<endl;   // 12
    
    // 对于虚单函数继承，派生类也继承了基类的vptr，所以是8字节
    cout << sizeof(C1) <<endl;  // 8

    cout << sizeof(int) << endl; //

    return 0;
}