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
 * @Date         : 2022-03-24 13:16:38
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-24 13:23:02
 * @FilePath     : /My_Cpp_test/Practice/纯虚函数和抽象类/抽象类.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

class Figure
{
protected:
    double x, y;

public:
    void set(double a, double b)
    {
        x = a;
        y = b;
    }
    virtual void area() = 0;
};

class Triangle : public Figure
{
public:
    void area()
    {
        cout << "Triangle Area = " << x * y * 0.5 << endl;
    }
};

class Rectangle : public Figure
{
public:
    void area() { cout << "Rect Area = " << x * y << endl; }
};

int main(int argc, char const *argv[])
{
    // 定义抽象类指针
    Figure *pF = NULL;
    Rectangle r;
    Triangle t;

    t.set(12.1, 22.8);
    pF = &t;
    pF->area();

    r.set(9.5, 7.4);
    pF = &r;
    pF->area();

    // 定义抽象引用
    Figure &pF1 = t;
    pF1.set(11.0, 10.8);
    pF1.area();

    return 0;
}