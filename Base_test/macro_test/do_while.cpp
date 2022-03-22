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
 * @Date         : 2022-03-22 15:27:28
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-22 16:11:02
 * @FilePath     : /My_Cpp_test/Base_test/macro_test/do_while.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>
#include <malloc/malloc.h>

using namespace std;

#define f1() cout << "f1()" << endl;
#define f2() cout << "f2()" << endl;

#define fun() \
    {         \
        f1(); \
        f2(); \
    }

#define fun1() \
    do         \
    {          \
        f1();  \
        f2();  \
    } while (0)

int f()
{
    int *p = (int *)malloc(sizeof(int));
    *p = 10;
    cout << *p << endl;
#ifndef DEBUG
    int error = 1;
#endif
    if (error)
        goto END;
    // TODO
END:
    cout << "free" << endl;
    free(p);
    return 0;
}

int ff()
{
    int *p = (int *)malloc(sizeof(int));
    *p = 20;
    cout << *p << endl;
    do
    {
#ifndef DEBUG
        int error = 1;
#endif
        if (error)
            break;
        // TODO
    }while(0);

    cout << "free" << endl;
    free(p);
    return 0;
}

int fc()
{
    int k1 = 10;
    cout << k1 << endl;
    do{
        int k1 = 100;
        cout << k1 << endl;
    }while(0);

    cout << k1 << endl;

    return 0;
}

int main(int argc, const char *argv[])
{
    fun();
    fun1();

    f();
    ff();
    fc();

    return 0;
}