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
 * @Date         : 2022-03-22 14:47:38
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-22 15:14:52
 * @FilePath     : /My_Cpp_test/Base_test/pointer_refer_test/copy_construct.cpp
 * @Description  : g++ -o copy_construct copy_construct.cpp -fno-elide-constructors -fno-elide-constructors选项(关闭返回值优化)
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

class Copyable
{
public:
    Copyable() {}
    Copyable(const Copyable &o)
    {
        cout << "Copied" << endl;
    }
};

Copyable ReturnRvalue()
{
    return Copyable(); // 返回一个临时对象
}

void AcceptVal(Copyable a)
{
}

void AcceptRef(const Copyable &a)
{
}

int main(int argc, const char *argv[])
{
    cout << "pass by value" << endl;
    AcceptVal(ReturnRvalue()); //应该调用两次考呗构造函数
    cout << "pass by reference" << endl;
    AcceptRef(ReturnRvalue()); //应该调用一次考呗构造函数

    return 0;
}