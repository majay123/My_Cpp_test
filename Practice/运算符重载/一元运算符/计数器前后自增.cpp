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
 * @LastEditTime : 2022-03-25 09:14:52
 * @FilePath     : /My_Cpp_test/Practice/运算符重载/一元运算符/计数器前后自增.cpp
 * @Description  : 设计一个计数器counter，用类成员重载自增运算符实现计数器的自增，用友元重载实现计数器的自减。
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

class Counter
{
    private:
        int n;
    public:
        Counter(int i = 0) : n(i) {};
        Counter operator++();
        Counter operator++(int);
        friend Counter operator--(Counter &c);
        friend Counter operator--(Counter &c, int);
        void display();
};

Counter Counter::operator++()
{
    ++n;
    return *this;
}

Counter Counter::operator++(int)
{
    n++;
    return *this;
}

Counter operator--(Counter &c)
{
    --c.n;
    return c;
}

Counter operator--(Counter &c, int)
{
    c.n--;
    return c;
}

void Counter::display()
{
    cout << "counter: " << n << endl;
}

int main (int argc, char const *argv[])
{
    Counter a; 

    a.display();
    ++a;
    a.display();
    a++;
    a.display();
    --a;
    a.display();
    a--;
    a.display();

    return 0;
}