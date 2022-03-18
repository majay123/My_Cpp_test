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
 * @Date         : 2022-03-17 10:26:23
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-17 10:53:48
 * @FilePath     : /My_C++_Test/const_test/const.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include "apple.cpp"

using namespace std;

Apple::Apple(int i)
{
}

// 非const对象可以访问任意的成员函数,包括const成员函数
int Apple::add(int num)
{
    take(num);
    return num;
}

int Apple::add(int num) const
{
    take(num);
    return num;
}

void Apple::take(int num) const
{
    cout << "take func " << num << endl;
}

// const对象只能访问const成员函数
int Apple::getCount() const
{
    take(1);
    return apple_number;
}

int main(int argc, const char **argv)
{
    cout << "hello c++ for mac" << endl;
    Apple a(2);
    cout << a.getCount() << endl;
    a.add(10);
    const Apple b(3);
    // 这里打印的参数还是10
    // cout << a.getCount() << endl;

    // const对象默认调用const成员函数
    b.add(100);
    return 0;
}