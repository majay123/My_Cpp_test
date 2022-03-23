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
 * @LastEditTime : 2022-03-23 10:22:11
 * @FilePath     : /My_Cpp_test/Practice/拷贝构造函数/clock.h
 * @Description  : 
 * 
 * ******************************************
 */

#ifndef CLOCK
#define CLOCK

class Clock
{
public:
    Clock(int NewH, int NewM, int NewS);
    Clock(Clock &c);    //  拷贝构造函数,如果不加，编译器会自动生成一个拷贝构造函数，因此加不加都可以直接使用。
    void SetTime(int NewH, int NewM, int NewS);
    void ShowTime();

    ~Clock();   // 析构函数，编译器会自动产生一个默认的析构函数。
private:
    int Hour, Minute, Second;
};


#endif