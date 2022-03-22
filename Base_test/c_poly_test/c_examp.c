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
 * @Date         : 2022-03-22 09:53:51
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-22 10:04:25
 * @FilePath     : /My_Cpp_test/c_poly_test/c_examp.c
 * @Description  : 
 * 
 * ******************************************
 */

#include <stdio.h>

typedef void (*pf)();

typedef struct _A
{
    pf _f;
} A;

typedef struct _B
{
    A _b;
} B;

void funcA()
{
    printf("Base A::func()\n");
}

void funcB()
{
    printf("Derived B::func()\n");
}

int main()
{
    A a;
    B b;

    a._f = funcA;
    b._b._f = funcB;

    A *pa = &a;
    pa->_f();
    pa = (A *)&b;
    pa->_f();
}