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
 * @Date         : 2022-03-21 09:30:56
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-21 10:15:41
 * @FilePath     : /My_Cpp_test/virtual/set1/emp.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>

using namespace std;

class Employee
{
public:
    virtual void raiseSalary()
    {
        cout << 0 << endl;
    }

    virtual void promote(){};
};

class Manager : public Employee
{
    virtual void raiseSalary()
    {
        cout << 100 << endl;
    }

    virtual void promote(){};
};

class Engineer : public Employee
{
    virtual void raiseSalary()
    {
        cout << 200 << endl;
    }

    virtual void promote(){};
};

// Similarly, there may be other types of employees 
// We need a very simple function to increment salary of all employees 
// Note that emp[] is an array of pointers and actual pointed objects can 
// be any type of employees. This function should ideally be in a class  
// like Organization, we have made it global to keep things simple 
void globalRaiseSalary(Employee *emp[], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        emp[i]->raiseSalary();
    }
    
}

int main(void)
{
    Employee *emp[] = {new Manager, new Engineer};

    globalRaiseSalary(emp, 2);

    return 0;
}