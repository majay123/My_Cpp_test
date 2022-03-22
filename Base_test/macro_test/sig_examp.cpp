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
 * @Date         : 2022-03-22 15:27:28
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-22 15:56:05
 * @FilePath     : /My_Cpp_test/Base_test/macro_test/sig_examp.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

// （#）字符串操作符
#define exp(s) printf("test s is : %s\n", s)
#define exp1(s) printf("test s is : %s\n", #s)
#define exp2(s) #s

// (##) 符号连接操作符
#define expA(s) printf("前缀加上后的字符串为: %s\n", gc_##s) // gc_s必须存在
#define expB(s) printf("前缀加上后的字符串为: %s\n", gc_##s) // gc_s必须存在
#define gc_hello1 "i am gc_hello1"

// (\) 续行操作符
#define MAX(a, b) ((a) > (b) ? (a) \
                             : (b))

int main(int argc, const char *argv[])
{

    exp("hello");
    exp1(hello);

    // 忽略传入参数名前面和后面的空格。
    string str = exp2(bac);
    cout << str << " " << str.size() << endl;

    // 当传入参数名间存在空格时，编译器将会自动连接各个子字符串，
    // 用每个子字符串之间以一个空格连接，忽略剩余空格。
    string str1 = exp2(asda bac);
    cout << str1 << " " << str1.size() << endl;

    const char *gc_hello = "i am gc_hello";
    expA(hello);
    expB(hello1);

    char var1_p[20];
    char var2_p[20];
    
    // 连接后的实际参数名赋值
    strcpy(var1_p, "aaaa");
    strcpy(var2_p, "bbbb");

    int max = MAX(10, 100);
    cout << max << endl;

    return 0;
}