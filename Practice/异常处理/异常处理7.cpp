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
 * @LastEditTime : 2022-03-25 13:42:46
 * @FilePath     : /My_Cpp_test/Practice/异常处理/异常处理7.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <climits>
#include <iostream>

using namespace std;

const int MAX_STACK_SIZE = 3;

class Full
{
}; //L1  堆栈满时抛出的异常类
class Empty
{
}; //L2  堆栈空时抛出的异常类

class Stack
{
  private:
    int s[MAX_STACK_SIZE];
    int top;

  public:
    void push(int a);
    int pop();
    Stack() { top = -1; }
};

void Stack::push(int a)
{
    if (top >= MAX_STACK_SIZE - 1)
        throw Full();
    s[++top] = a;
}

int Stack::pop()
{
    if (top < 0)
        throw Empty();
    return s[top--];
}

int main(int argc, char const *argv[])
{
    Stack s;
    try{
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);

        cout << "stack(0) = " << s.pop() << endl;
        cout << "stack(1) = " << s.pop() << endl;
        cout << "stack(2) = " << s.pop() << endl;
        cout << "stack(3) = " << s.pop() << endl;
    }
    catch (Full) {cout << "Exception: Stack Full" << endl;}
    catch (Empty) {cout << "Exception: Stack Empty" << endl;}

    return 0;
}