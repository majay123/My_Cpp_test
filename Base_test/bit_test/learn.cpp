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
 * @Date         : 2022-03-21 16:01:03
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-21 16:39:49
 * @FilePath     : /My_Cpp_test/bit_test/learn.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

struct stuffer
{
    unsigned int field1 : 30;
    unsigned int : 2;
    unsigned int field2 : 4;
    unsigned int : 0;
    unsigned int field3 : 3;
};

int main(void)
{
    struct stuffer s = {1, 7, 5};

    cout << s.field1 << endl;
    cout << s.field2 << endl;
    cout << s.field3 << endl;

    // cout << sizeof(s) << endl;
    // cout << sizeof(unsigned int) << endl;
    
    // cout << USHRT_MAX << endl;

    return 0;
}