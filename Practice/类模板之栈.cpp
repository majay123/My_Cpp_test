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
 * @Date         : 2022-03-28 15:18:05
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-28 15:30:16
 * @FilePath     : /My_Cpp_test/Practice/类模板之栈.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <climits>
#include <iostream>

using namespace std;

template <typename T, int MAXSIZE>

class Stack
{
  public:
    Stack(){};
    void init()
    {
        top = -1;
    }
    bool ifFull() const
    {
        if (top >= MAXSIZE - 1)
            return true;
        else
            return false;
    }

    bool isEmpty()
    {
        if (top < 0)
            return true;
        else
            return false;
    }

    void push(T e);
    T pop();

  private:
    int top;
    T elems[MAXSIZE];
};

template <typename T, int MAXSIZE>
void Stack<T, MAXSIZE>::push(T e)
{
    if (!ifFull())
        elems[++top] = e;
    else
        cout << "stack is full, can not push any elem" << endl;

    return;
}

template <typename T, int MAXSIZE>
T Stack<T, MAXSIZE>::pop()
{
    if (!isEmpty())
        return elems[top--];
    else
        cout << "stack is empty, please do not pop any elem" << endl;

    return 0;
}

int main(int argc, char const *argv[])
{
    Stack<int, 10> s1;

    s1.init();
    int i = 0;
    for (i = 1; i < 12; i++) {
        s1.push(i);
    }
    for (i = 1; i < 12; i++)
        cout << s1.pop() << "\t";
    cout << endl;

    return 0;
}