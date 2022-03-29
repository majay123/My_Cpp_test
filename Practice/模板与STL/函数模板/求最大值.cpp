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
 * @LastEditTime : 2022-03-25 12:30:38
 * @FilePath     : /My_Cpp_test/Practice/模板与STL/函数模板/求最大值.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <climits>
#include <iostream>

using namespace std;

template <class T>

T Max(T a, T b)
{
    return (a > b) ? a : b;
}

// ++在实例化函数模板的过程中，只是简单地将模板参数替换成调用实参的类型，并以此生成模板函数，不会进行参数类型的任何转换
int main(int argc, char const *argv[])
{
    double a = 2, b = 3.4;
    float c = 5.1, d = 3.2;
    //在模板调用时进行参数类型的强制转换
    cout << "2, 3.2    的最大值是：" << Max(double(2), 3.2) << endl;
    cout << "a, c    的最大值是：" << Max(float(a), c) << endl;
    //显示指定函数模板实例化的参数类型
    cout << "'a', 3    的最大值是：" << Max<int>('a', 3) << endl;

    return 0;
}