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
 * @Date         : 2022-03-31 15:19:09
 * @LastEditors  : MCD
 * @LastEditTime : 2022-04-01 08:52:14
 * @FilePath     : /My_Cpp_test/Practice/右值和移动/collapses.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>
#include <thread>

using namespace std;

/**
 * @brief  
 * 
 * @tparam T 
 * @param param 
 */
template<typename T>
void f(T &&param){
    static_assert(is_lvalue_reference<T>::value, "T& is lvalue reference");
    cout << "T& is lvalue reference" << endl;
}

/**
 * @brief 
 * 
 * @tparam T 
 */
template<typename T>
class Widget
{
    typedef T& LvalueRefType;
    typedef T&& RvalueRefType;
    public:
        void judge()
        {
            static_assert(is_lvalue_reference<LvalueRefType>::value, "LvalueRefType & is lvalue reference");
            static_assert(is_lvalue_reference<LvalueRefType>::value, "RvalueRefType & is lvalue reference");
            cout << "LvalueRefType and RvalueRefType is lvalue reference" << endl;
        }   

        void f(LvalueRefType&& param) {}
};


/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main (int argc, char const *argv[])
{
    int x;
    int &&r1 = 10;
    int &r2 = x;

    f(r1);
    f(r2);

    Widget<int &> w;
    w.judge();

    Widget<int>w1, w2;
    auto&& v1 = w1;     // v1 is an auto-based universal reference being

    return 0;
}