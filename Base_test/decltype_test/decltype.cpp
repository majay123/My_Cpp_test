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
 * @Date         : 2022-03-22 14:17:50
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-22 14:44:59
 * @FilePath     : /My_Cpp_test/Base_test/decltype_test/decltype.cpp
 * @Description  :  g++ -o decltype decltype.cpp -std=c++11
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

/**
 * 泛型编程中结合auto，用于追踪函数的返回值类型
 */
template <typename T>

auto multiply(T x, T y) -> decltype(x * y)
{
    return x * y;
}

int main(int argc, const char *argv[])
{
    int nums[] = {0, 1, 2, 3, 4, 5, 6};
    vector<int> vec(nums, nums + sizeof(nums) / sizeof(int));
    vector<int>::iterator it;

    for (it = vec.begin(); it != vec.end(); it++)
        cout << *it << " ";
    cout << endl;

    using nullptr_t = decltype(nullptr);
    nullptr_t nu;
    int *p = NULL;
    if (p == nu)
        cout << "NULL" << endl;

    typedef decltype(vec.begin()) vectype;

    for (vectype i = vec.begin(); i != vec.end(); i++)
        cout << *i << " ";
    cout << endl;

    // 匿名结构体
    struct
    {
        int d;
        double b;
    } anon_s;

    decltype(anon_s) as; // 定义了一个上名匿名的结构体

    cout << multiply(11, 2) << endl;
    return 0;
}