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
 * @Date         : 2022-03-22 09:42:24
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-22 09:52:45
 * @FilePath     : /My_Cpp_test/union_test/union.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

union UnionTest
{
    // 可以含有构造函数 析构函数
    UnionTest() : i(10) { print(i); };
    ~UnionTest(){};
    int i;

private:
    void print(int i) { cout << i << endl; };
};


// 全局匿名联合必须是静态的
static union {
    int i;
    double d;
};

int main(int argc, char* argv[])
{
    UnionTest test;
    
    union {
        int i;
        double d;
    };

    cout << test.i << endl; // 输出UnionTest联合的i值

    ::i = 20;
    cout << ::i << endl;    // 输出全局静态匿名联合的i值

// 匿名union在定义所在的作用域可以直接访问union的成员
    i = 30;
    cout << i << endl;      // 输出局部匿名联合的i值

    return 0;
}