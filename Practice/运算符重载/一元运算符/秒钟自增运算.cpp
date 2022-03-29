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
 * @Date         : 2022-03-25 08:55:52
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-25 09:04:46
 * @FilePath     : /My_Cpp_test/Practice/运算符重载/一元运算符/秒钟自增运算.cpp
 * @Description  : /设计一个时间类Time，它能够完成秒钟的自增运算。
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

class Time
{
    private:
    int hour, minute, second;
    public:
    Time(int h, int m, int s);
    Time operator++();
    // 友元重载需要参数
    friend Time operator--(Time &t);
    void display();
};

Time::Time(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
    if(hour >= 24)
        hour = 0;
    if(minute >= 60)
        minute = 0;
    if(second >= 60)
        second = 0;
}

Time Time::operator++()
{
    ++second;
    if(second >= 60) {
        second = 0;
        minute++;
        if(minute >= 60){
            minute = 0;
            hour++;
            if(hour >= 24){
                hour = 0;
            }
        }
    }
    return *this;
}

Time operator--(Time &t)
{
    --t.second;
    if (t.second>=60){
        t.second=0;
        ++t.minute;
        if(t.minute>=60){
            t.minute=0;
            ++t.hour;
            if(t.hour>=24)
                t.hour=0;
        }
    }
    return t; 
}

void Time::display()
{
    cout << hour << ":" << minute << ":" << second << endl;
}

int main (int argc, char const *argv[])
{
    Time t1(23,59,59);
    t1.display();
    ++t1; //隐式调用
    t1.display();
    t1.operator++(); //显式调用
    t1.display();
    Time t2(24,60,60);
    t2.display();
    ++t2;
    t2.display();
    --t2;
    t2.display();
    return 0;
}