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
 * @Date         : 2022-03-29 14:03:53
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-29 15:00:04
 * @FilePath     : /My_Cpp_test/Practice/并发编程/多线程和多进程/1.thread/thread.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <chrono>
#include <climits>
#include <iostream>
#include <thread>

using namespace std::chrono;
using namespace std;

/**
 * 1.普通函数指针
 * 2.Lambda函数
 * 3.Functors
 * 4.非静态成员函数
 * 5.静态成员函数
 */

using ull = unsigned long long;
ull OddSum = 0;
ull EvenSum = 0;

void findEven(ull start, ull end)
{
    for (ull i = start; i <= end; i++) {
        if ((i & 1) == 0)
            EvenSum += i;
    }
}

void findOdd(ull start, ull end)
{
    for (ull i = start; i <= end; i++) {
        if ((i & 1) == 1)
            OddSum += i;
    }
}

int main(int argc, char const *argv[])
{
    ull start = 0, end = 1900000000;

    auto startTime = high_resolution_clock::now();
#if 1
    thread t1(findEven, start, end);
    thread t2(findOdd, start, end);

    t1.join();
    t2.join();
#else
    findOdd(start, end);
    findEven(start, end);
#endif

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    cout << "OddSum: " << OddSum << endl;
    cout << "EvenSum: " << EvenSum << endl;
    cout << "Sec: " << duration.count() / 1000000 << endl;

    return 0;
}