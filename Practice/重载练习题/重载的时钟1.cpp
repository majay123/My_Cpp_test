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
 * @Date         : 2022-03-23 12:54:20
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-23 12:59:17
 * @FilePath     : /My_Cpp_test/Practice/时钟练习题/重载的时钟1.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

class Time
{
private:
    int hh, mm, ss;

public:
    Time(int h = 0, int m = 0, int s = 0) : hh(h), mm(m), ss(s) {}
    void operator()(int h, int m, int s)
    {
        hh = h;
        mm = m;
        ss = s;
    }

    void showTime()
    {
        cout << "Time: " << hh << ":" << mm << ":" << ss << endl;
    }
};

int main(int argc, char const *argv[])
{
    Time t1(12, 10, 20);
    t1.showTime();

    t1.operator()(12, 10, 30);
    t1.showTime();

    t1(10, 20, 30);
    t1.showTime();

    return 0;
}