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
 * @Date         : 2022-03-23 13:32:59
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-23 15:15:13
 * @FilePath     : /My_Cpp_test/Practice/时钟练习题/重载的operator2.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

class complex
{
public:
    complex();
    complex(double x, double y);

public:
    void display() const;
    // 声明为友元函数
    friend complex operator+(const complex &a, const complex &b);
    friend bool operator==(const complex &a, const complex &b);

private:
    double m_real, m_imag;
};

complex operator+(const complex &a, const complex &b);

complex::complex() : m_real(0.0), m_imag(0.0) {}
complex::complex(double x, double y) : m_real(x), m_imag(y) {}

void complex::display() const
{
    cout << m_real << "+" << m_imag << "i" << endl;
}

// 全局范围内重载+
complex operator+(const complex &a, const complex &b)
{
    complex c;
    c.m_real = a.m_real + b.m_real;
    c.m_imag = a.m_imag + b.m_imag;

    return c;
}

bool operator==(const complex &a, const complex &b)
{
    if ((a.m_imag == b.m_imag) && (a.m_real == b.m_real))
        return true;
    return false;
}

int main(int argc, char const *argv[])
{
    complex a(3.3, 2.4);
    complex b(2.3, 6.4);
    complex c = a + b;
    c.display();

    if(a == b)
        cout << "is ok" << endl;
    else
        cout << "not ok"<< endl;

    return 0;
}