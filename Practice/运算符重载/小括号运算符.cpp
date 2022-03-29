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
 * @Date         : 2022-03-24 16:06:47
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-24 16:10:43
 * @FilePath     : /My_Cpp_test/Practice/运算符重载/()运算符.cpp
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
    Time(int h, int m, int s) : hh(h), mm(m), ss(s){}
    void operator()(int h, int m, int s)
    {
        hh = h;
        mm = m;
        ss = s;
    }

    void showTime()
    {
        cout << hh << ":" << mm << ":" << ss << endl;
    }
};

int main (int argc, char const *argv[])
{
    Time t1(10, 2, 29);
    t1.showTime();

    t1.operator()(10,2,30);
    t1.showTime();

    t1(10, 2, 31);
    t1.showTime();
    
    return 0;
}