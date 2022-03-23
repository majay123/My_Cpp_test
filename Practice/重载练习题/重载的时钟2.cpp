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
 * @LastEditTime : 2022-03-23 13:02:55
 * @FilePath     : /My_Cpp_test/Practice/时钟练习题/重载的时钟2.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

class Time
{
public:
    Time(int h = 0, int m = 0, int s = 0)
    {
        hour = h;
        minute = m;
        second = s;
    }

    void operator++();
    void showTime()
    {
        cout << "Time: " << hour << ":" << minute << ":" << second << endl;
    }

private:
    int hour, minute, second;
};

void Time::operator++()
{
    ++second;
    if (second == 60)
    {
        second = 0;
        ++minute;
        if (minute == 60)
        {
            minute = 0;
            ++hour;
            if (hour == 24)
            {
                hour = 0;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    Time t(23, 59, 59);

    ++t;
    t.showTime();
    return 0;
}