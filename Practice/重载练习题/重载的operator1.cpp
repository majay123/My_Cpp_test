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
 * @LastEditTime : 2022-03-23 15:49:08
 * @FilePath     : /My_Cpp_test/Practice/时钟练习题/重载的operator1.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

class rectangle
{

public:
    rectangle()
    {
        length = 0;
        width = 0;
    }
    rectangle(int l, int w)
    {
        length = l;
        width = w;
    }

public:
    bool IsSame(const rectangle &); // 比较函数
    bool operator==(const rectangle &);
    friend rectangle operator+(const rectangle &a, const rectangle &b);
    void display();
private:
    int length, width;
};

// rectangle::rectangle():length(0), width(0) {}
// rectangle::rectangle(int l, int w):length(l), width(w){}

bool rectangle::operator==(const rectangle &a)
{
    if (length == a.length && width == a.width)
        return true;
    return false;
}

bool rectangle::IsSame(const rectangle &a)
{
    if (length == a.length && width == a.width)
        return true;
    return false;
}
rectangle operator+(const rectangle &a, const rectangle &b)
{
    rectangle c;
    c.length = a.length + b.length;
    c.width = a.width + b.width;

    return c;

}

void rectangle::display()
{
    cout << "length: " << length << endl;
    cout << "width: " << width << endl;
}

int main(int argc, char const *argv[])
{
    rectangle p1(10, 20);
    rectangle p2(10, 20);

    if (p1 == p2)
        cout << "rect is equal!" << endl;
    else
        cout << "rect is not equal!" << endl;

    if (p1.IsSame(p2))
        cout << "rect is equal!" << endl;
    else
        cout << "rect is not equal!" << endl;

    rectangle p3 = p1+p2;
    p3.display();
    

    return 0;
}