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
 * @LastEditTime : 2022-03-25 12:55:01
 * @FilePath     : /My_Cpp_test/Practice/异常处理/异常处理3.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <climits>
#include <iostream>

using namespace std;

void temperature(int i)
{
    try {
        if (i == 100)
            throw "It's at the boiling point.";
        else if (i == 0)
            throw "It reached the freezing point";
        else
            cout << "The temperature is ok.." << endl;
    } catch (int x) {
        cout << "temperature = " << x << endl;
    } catch (const char *s) {
        cout << s << endl;
    }
}

void temperature1(int i)
{

    if (i == 100)
        throw "1-It's at the boiling point.";
    else if (i == 0)
        throw "2-It reached the freezing point";
    else
        cout << "3-The temperature = " << i << endl;
}

int main(int argc, char const *argv[])
{
    temperature(0);
    temperature(10);
    temperature(100);

    try {
        temperature1(0);
        temperature1(10);
        temperature1(100);
    } catch (char const *s) {
        cout << s << endl;
    }

    return 0;
}