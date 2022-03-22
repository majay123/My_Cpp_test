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
 * @Date         : 2022-03-22 13:45:04
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-22 13:45:22
 * @FilePath     : /My_Cpp_test/Base_test/maohao_test/maohao.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
using namespace std;

int count=0;    // 全局(::)的count

class A {
public:
    static int count;  // 类A的count (A::count)

};
// 静态变量必须在此处定义
int A::count;
int main() {
    ::count=1; // 设置全局的count为1
    A::count=5; // 设置类A的count为2
    cout<<A::count<<endl;
//    int count=3; // 局部count
//    count=4;     // 设置局部的count为4
    return 0;
}