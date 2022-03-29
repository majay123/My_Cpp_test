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
 * @Date         : 2022-03-25 12:38:16
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-25 13:59:46
 * @FilePath     : /My_Cpp_test/Practice/异常处理/异常处理10.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <climits>
#include <iostream>

using namespace std;

const int Max = 3;

class Full
{
    int a;

  public:
    Full(int i = 0) : a(i) {}
    int getValue() { return a; }
};

class Empty{};

class Stack{
    private:
    int s[Max];
    int top;
    public:
    Stack() { top = -1; }
    void push(int a){
        if( top >= Max -1)
            throw Full(a);
        s[++top] = a;
    }
    int pop() { 
        if(top < 0)
            throw Empty();
        return s[top--];
    }
};

int main(int argc, char const *argv[])
{
    Stack s;
    try{
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
    }catch(Full e) {
        cout << "Exception: Stack Full..." << endl;
        cout << "The value not push in stack: "<< e .getValue() << endl;
    }
    return 0;
}