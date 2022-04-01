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
 * @Date         : 2022-04-01 14:07:08
 * @LastEditors  : MCD
 * @LastEditTime : 2022-04-01 14:32:46
 * @FilePath     : /My_Cpp_test/Practice/functionLambda/adder.cpp
 * @Description  :
 *
 * ******************************************
 */

#include <climits>
#include <iostream>
#include <thread>

using namespace std;

struct addr {
    addr(int n) : n_(n) {}

    int operator()(int n) const { return n_ + n; }

  private:
    int n_;
};

int main(int argc, char const *argv[])
{
    auto add_2 = addr(2);

    cout << add_2(3) << endl;

    auto t = bind1st(plus<int>(), 2);
    cout << t(1) << endl;
    // 上述的是C++98

    binder2nd<plus<int>> a2(plus<int>(), 2);
    // binder2nd<plus<int> > a2(plus<int>(), 2);
    cout << a2(3) << endl;

    cout << [](int x) { return x * x; }(3) << endl;
    return 0;
}