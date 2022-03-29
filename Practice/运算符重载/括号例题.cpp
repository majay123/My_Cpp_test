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
 * @Date         : 2022-03-25 08:47:35
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-25 08:54:06
 * @FilePath     : /My_Cpp_test/Practice/运算符重载/括号例题.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

class X
{
public:
    int operator()(int i = 0)
    {
        cout << "X::operator(" << i << ")" << endl;
        return i;
    }
    int operator()(int i, int j)
    {
        cout << "X::operator(" << i << ","<< j << ")" << endl;
        return i;
    }

    int operator[](int i)
    {
        cout << "X::operator[ " << i << "]" << endl;
        return i;
    }

    int operator[](char *cp)
    {
        cout << "X::operator[ " << cp << "]" << endl;
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    X obj; int i = obj(obj(1), 2);
    int a = obj[i];
    int b = obj["abcd"];
    cout << "a="<< a<< endl;
    cout << "b="<< b<< endl;
    return 0;
}