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
 * @Date         : 2022-03-22 16:18:54
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-22 16:21:09
 * @FilePath     : /My_Cpp_test/Practice/Day1/test1.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int i, j, k, f;
    for (i = 1; i <= 4; i++)
    {
        for (j = 1; j <= 30; j++)
            cout << " ";
        for (k = 1; k <= 8 - 2 * i; k++)
            cout << " ";
        for (f = 1; f <= 2 * i; f++)
            cout << '*';
        cout << endl;
    }
    for (i = 1; i <= 3; i++)
    {
        for (j = 1; j <= 30; j++)
            cout << " ";
        for (f = 1; f <= 7 - 2 * i; f++)
            cout << '*';
        cout << endl;
    }
    // system("pause");
    return 0;
}