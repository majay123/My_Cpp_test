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
 * @Date         : 2022-03-23 10:00:29
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-23 10:03:45
 * @FilePath     : /My_Cpp_test/Practice/友元函数/友元类.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

/*
若一个类为另一个类的友元，则此类的所有成员都能访问对方类的私有成员。
声明语法：将友元类名在另一个类中使用friend修饰说明。
*/

/*
如果声明B类是A类的友元，B类的成员函数就可以访问A类的私有和保护数据，
但A类的成员函数却不能访问B类的私有、保护数据。
*/
class A
{
    friend class B;

public:
    void display()
    {
        cout << x << endl;
    }

private:
    int x;
};

class B
{
public:
    void set(int i);
    void display();

private:
    A a;
};

void B::set(int i)
{
    a.x = i;
}

void B::display()
{
    a.display();
}

int main(int argc, char const *argv[])
{
    B b;
    b.set(10);
    b.display();
    return 0;
}
/*
如果声明B类是A类的友元，B类的成员函数就可以访问A类的私有和保护数据，但A类的成员函数却不能访问B类的私有、保护数据
*/