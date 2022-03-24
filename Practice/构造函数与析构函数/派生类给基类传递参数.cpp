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
 * @Date         : 2022-03-24 10:51:01
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-24 12:41:31
 * @FilePath     : /My_Cpp_test/Practice/构造函数与析构函数/派生类给基类传递参数.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

class Point {
    protected:
    int x, y;
    public:
    Point(int a, int b)
    {
        x = a;
        y = b;
        cout << "constructing point {" << x << ", " << y <<"}" << endl;
    }
};

class Line : public Point {
    protected:
    int len;
    public:
    Line(int a, int b, int l) : Point(a, b)
    {
        len  = l;
        cout << "constructing line = " << len << endl;
    }
};


int main (int argc, char const *argv[])
{
    Line(1, 2, 4);
    return 0;
}