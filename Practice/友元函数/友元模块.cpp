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
 * @Date         : 2022-03-23 10:00:29
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-23 10:10:58
 * @FilePath     : /My_Cpp_test/Practice/友元函数/友元模块.cpp
 * @Description  : 使用友元函数计算两点之间的距离
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class Point
{
public:
    Point(int x = 0, int y = 0) : X(x), Y(y) {}
    int Getx()
    {
        return X;
    }
    int Gety()
    {
        return Y;
    }
    friend float Distance(Point &p1, Point &p2);

private:
    int X, Y; // 私有成员
};

// 通过将一个模块申明为另一个模块的友元，一个模块能够引用到另一个模块中本是被隐藏的信息
float Distance(Point &a, Point &b)
{
    double dx = a.X - b.X;
    double dy = a.Y - b.Y;
    return sqrt(dx * dx + dy * dy);
}

int main(int argc, char const *argv[])
{
    Point p1(3.0, 5.0), p2(4.0, 6.0);
    cout << "两点距离为：" << Distance(p1, p2) << endl;
    return 0;
}