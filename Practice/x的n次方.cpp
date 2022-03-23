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
 * @Date         : 2022-03-22 16:32:24
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-22 16:55:46
 * @FilePath     : /My_Cpp_test/Practice/Day2/x的n次方.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

#define ABS(x) ((x) < 0 ? (-x) : (x))

static double _power(double x, int n)
{
    double result = 1.0;
    int tp = 0;
    if (n < 0) {
        tp = ABS(n);
    }
    else
        tp = n;

    // cout << tp << endl;
    for (int i = 0; i < tp; i++)
        result *= x;
    if (n < 0)
        result = 1 / result;

    return result;
}

int main(int argc, char const *argv[])
{
    int n = -100;
    cout << "abs = " << ABS(n) << endl;
    cout << "date = " << _power(2, -2) << endl;
    // int x;
    // cin >> x;
    // int wei = 0;
    // int sum = 0;
    // int each, chu;
    // for (int i = 0; i < 8; i++)
    // {
    //     each = x % 10;
    //     chu = x / 10;
    //     sum += each * _power(2, wei);
    //     x = chu;
    //     wei++;
    // }
    // cout << sum << endl;
    return 0;
}