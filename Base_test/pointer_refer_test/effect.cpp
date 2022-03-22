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
 * @Date         : 2022-03-22 14:47:38
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-22 15:25:31
 * @FilePath     : /My_Cpp_test/Base_test/pointer_refer_test/effect.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

void test1(int *p)
{
    *p = 3;      //此处应该首先判断p是否为空，为了测试的需要，此处我们没加。
    return ;
}

void test2(int& p)
{
    p = 3;       //此处应该首先判断p是否为空，为了测试的需要，此处我们没加。
    return;
}

int main()
{
    int a = 10;
    int *p = &a;

    cout << a << endl;
    test1(p);
    cout << a << endl;
    test2(a);
    cout << a << endl;

    return 0;
}