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
 * @Date         : 2022-03-31 14:27:45
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-31 14:34:10
 * @FilePath     : /My_Cpp_test/Practice/右值和移动/reference.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>
#include <thread>

using namespace std;

int &&f()
{
    return 3;
}

struct As
{
    int i;
};

As&& ff()
{
    return As();
}

int main (int argc, char const *argv[])
{
    int x = 1;

    cout << "(x).addr = " << &x << endl;
    cout << "(x = 2).addr = " << &(x = 2) << endl;
    cout << "(++x).addr = " << &(++x) << endl;
    cout << "(cout << ' ').addr=" << &(cout << ' ') << endl;
    cout << "(\"hello\").addr=" << &("hello") << endl;

    cout<<true<<endl;

    // xvalue
    f(); // The expression f() belongs to the xvalue category, because f() return type is an rvalue reference to object type.
    static_cast<int&&>(7); // The expression static_cast<int&&>(7) belongs to the xvalue category, because it is a cast to an rvalue reference to object type.
    std::move(7); // std::move(7) is equivalent to static_cast<int&&>(7).

    ff().i; // The expression f().i belongs to the xvalue category, because As::i is a non-static data member of non-reference type, and the subexpression f() belongs to the xvlaue category.



    return 0;
}