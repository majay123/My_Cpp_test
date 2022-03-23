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
 * @Date         : 2022-03-23 10:13:24
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-23 12:40:25
 * @FilePath     : /My_Cpp_test/Practice/拷贝构造函数/clock.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>
#include "clock.h"

using namespace std;

Clock::Clock(int NewH, int NewM, int NewS)
{
    this->Hour = NewH;
    this->Minute = NewM;
    this->Second = NewS;
}

Clock::Clock(Clock &c)
{
    this->Hour = c.Hour;
    this->Minute = c.Minute;
    this->Second = c.Second;
}

void Clock::SetTime(int NewH, int NewM, int NewS)
{
    // 加不加this指针都一样
    this->Hour = NewH;
    this->Minute = NewM;
    this->Second = NewS;
}

void Clock::ShowTime()
{
    // cout << this->Hour << endl;
    // cout << this->Minute << endl;
    // cout << this->Second << endl;
    cout << this->Hour << ":" << this->Minute << ":" << this->Second << endl;
}

Clock::~Clock()
{
    cout << "out" << endl;
}

int main(int argc, char const *argv[])
{
    Clock c(0, 0, 0);

    c.SetTime(10, 22, 19);
    c.ShowTime();

    // 拷贝构造函数调用
    Clock cl(c);
    cl.ShowTime();
    cl.SetTime(12, 41, 20);
    cl.ShowTime();

    return 0;
}