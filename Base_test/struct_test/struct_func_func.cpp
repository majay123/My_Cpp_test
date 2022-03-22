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
 * @Date         : 2022-03-22 09:29:52
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-22 09:40:48
 * @FilePath     : /My_Cpp_test/struct_test/struct_func_func.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <stdio.h>

struct Base
{
    int v1;
    //    private:   //error!
    int v3;

public: //显示声明public
    int v2;
    void print()
    {
        printf("%s\n", "hello world");
    };
};

typedef struct Base1
{
    int v1;
    //    private:   //error!
    int v3;

public: //显示声明public
    int v2;
    void print()
    {
        printf("%s\n", "hello world");
    };
} B;
void Base()
{
    printf("%s\n", "I am Base func");
}
//void B() {}  //error! 符号 "B" 已经被定义为一个 "struct Base1" 的别名
int main()
{
    struct Base base; //ok
    //Base base1;  // error!
    base.v1 = 1;
    base.v3 = 2;
    base.print();
    printf("%d\n", base.v1);
    printf("%d\n", base.v3);
    Base();
    return 0;
}
