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
 * @Date         : 2022-03-25 12:38:16
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-25 13:05:58
 * @FilePath     : /My_Cpp_test/Practice/异常处理/异常处理4.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <climits>
#include <iostream>

using namespace std;

void handler(int n) throw(int, char, double)
{
    if (n == 1)
        throw n;
    if (n == 2)
        throw 'x';
    if (n == 3)
        throw 1.1;
}

void errhandler(int n)
{
    try {
        if (n == 1)
            throw n;
        if (n == 2)
            throw 'x';
        if (n == 3)
            throw 1.1;
    }catch (...) {
        cout << "catch an exception..." << endl;
    }
}

int main(int argc, char const *argv[])
{
    cout << "before handler..." << endl;
    try {
        handler(1);
    } catch (int i) {
        cout << "catch an integer..." << endl;
    } catch (char c) {
        cout << "catch a char..." << endl;
    } catch (double d) {
        cout << "catch a double..." << endl;
    }

    errhandler(1);
    errhandler(2);
    errhandler(3);

    return 0;
}