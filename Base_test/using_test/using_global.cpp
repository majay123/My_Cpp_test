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
 * @Date         : 2022-03-22 13:15:39
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-22 13:19:56
 * @FilePath     : /My_Cpp_test/Base_test/using_test/using_global.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

#define isNs1       (1)

using namespace std;

void func()
{
    cout << "::func" << endl;
}

namespace ns1 {
    void func()
    {
        cout << "ns1::func" << endl;
    }
}

namespace ns2 {
    #ifdef isNs1
        using ns1::func;    // ns1种的函数
    #elif
        using ::func;       // 全局中的函数
    #else
        void func()
        {
            cout << "other::func" << endl;
        }
    #endif
}

int main(int argc, const char *argv[])
{
    /**
     * 这就是为什么在c++中使用了cmath而不是math.h头文件
     */
    ns2::func();    // 会根据当前环境定义宏的不同来调用不同命名空间下的func()函数
    return 0;
}