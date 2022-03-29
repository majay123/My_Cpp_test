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
 * @Date         : 2022-03-25 11:14:29
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-25 11:22:40
 * @FilePath     : /My_Cpp_test/Practice/模板与STL/函数模板/模板特化.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <climits>
#include <cstring>
#include <iostream>

using namespace std;

template <class T>

T Max(T a, T b)
{
    return (a > b) ? a : b;
}

//特化
//template <> 返回类型 函数名<特化的数据类型>(参数表) {}
template <>
char *Max<char *>(char *a, char *b)
{
    return (strcmp(a, b) > 0) ? a : b;
}

int main(int argc, char const *argv[])
{
    float c = 1.54, d = 3.2;

    cout << "2, 3的最大值是：" << Max(2, 3) << endl;
    cout << "c,d 的最大值是：" << Max(c, d) << endl;
    cout << Max("adb", "aacd") << endl;

    return 0;
}