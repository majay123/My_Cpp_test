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
 * @Date         : 2022-03-17 14:32:50
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-18 10:46:31
 * @FilePath     : /My_Cpp_test/this_test/person.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <cstring>

// for test
// for test1
using namespace std;

class Person
{
public:
    typedef enum
    {
        BOY = 0,
        GIRL,
    } SexType;

    Person(char *n, int a, SexType s)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        age = a;
        sex = s;
    }

    // this，变为const A* const
    // 因为这个函数是const函数，那么针对const函数，它只能访问const变量与const函数，不能修改其他变量的值，所以需要一个this指向不能修改的变量，那就是const A*,
    // 又由于本身this是const指针，所以就为const A* const
    int get_age() const
    {
        return this->age;
    }

    char *get_name() const
    {
        return this->name;
    }

    Person &add_age(int a)
    {
        age += a;
        return *this;
    }

    ~Person()
    {
        delete[] name;
    }

private:
    char *name;
    int age;
    SexType sex;
};

int main(int argc, char **argv)
{
    Person p((char *)"machendong", 22, Person::BOY);
    cout << p.get_name() << " "<< p.get_age() << endl;
    cout << p.get_name() << " "<<  p.add_age(10).get_age() << endl;

    return 0;
}