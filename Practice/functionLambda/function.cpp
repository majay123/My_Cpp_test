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
 * @Date         : 2022-04-01 14:07:27
 * @LastEditors  : MCD
 * @LastEditTime : 2022-04-01 14:10:37
 * @FilePath     : /My_Cpp_test/Practice/functionLambda/function.cpp
 * @Description  :
 *
 * ******************************************
 */

#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <thread>

using namespace std;

int main(int argc, char const *argv[])
{
    map<string, function<int(int, int)>> op_dict{
        {"+",
         [](int x, int y) {
             return x + y;
         }},
        {"-",
         [](int x, int y) {
             return x - y;
         }},
        {"*",
         [](int x, int y) {
             return x * y;
         }},
        {"/",
         [](int x, int y) {
             return x / y;
         }}};

    return 0;
}