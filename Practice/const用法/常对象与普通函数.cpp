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
 * @Date         : 2022-03-23 09:49:33
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-23 09:58:26
 * @FilePath     : /My_Cpp_test/Practice/const用法/常对象与普通函数.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

class R
{
public:
    R(int r1, int r2) { R1 = r1, R2 = r2 ;}
    // const 区分成员重载函数
    void print();
    void print() const;

private:
    int R1, R2;
};


/*
常成员函数说明格式：类型说明符  函数名（参数表）const;
这里，const是函数类型的一个组成部分，因此在实现部分也要带const关键字。
const关键字可以被用于参与对重载函数的区分
通过常对象只能调用它的常成员函数
*/
void R::print()
{
    cout << "普通调用" << endl;
    cout << R1 << " " << R2 << endl;
}

void R::print() const
{
    cout << "常对象调用" << endl;
    cout << R1 << " " << R2 << endl;
}

int main(int argc, char const *argv[])
{
    R a(5, 3);
    a.print();  //调用void print()

    //通过常对象只能调用它的常成员函数
    const R b(10 ,6);
    b.print();  //调用void print() const

    return 0;
}