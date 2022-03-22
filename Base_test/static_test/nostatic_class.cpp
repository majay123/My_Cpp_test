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
 * @Date         : 2022-03-17 14:03:18
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-17 14:08:05
 * @FilePath     : /My_C++_Test/static_test/nostatic_class.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>

using namespace std;

class Apple
{
    int i;

public:
    Apple()
    {
        i = 0;
        cout << "Inside Constructor\n";
    }

    ~Apple()
    {
        cout << "Inside Destructor\n";
    }
};

int main()
{
    int x= 0;

    if(x == 0)
        Apple obj;

    cout << "end of main\n";
}