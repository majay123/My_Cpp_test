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
 * @Date         : 2022-03-24 13:27:39
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-24 14:15:15
 * @FilePath     : /My_Cpp_test/Practice/虚函数/虚函数例子.cpp
 * @Description  : 基类指针或引用指向派生类对象时,虚函数与非虚函数区别：
 * 声明Employee的print为虚函数，则可访问到Manager的print函数，非虚函数，则只能访问到Employee的print
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

class Employee
{
public:
    Employee(string name, string id);
    string getName();
    string getId();
    float getSalary();
    virtual void print();

private:
    string Name;
    string Id;
};

Employee::Employee(string name, string id)
{
    Name = name;
    Id = id;
}

string Employee::getName()
{
    return Name;
}

string Employee::getId()
{
    return Id;
}

float Employee::getSalary()
{
    return 0.0;
}

void Employee::print()
{
    cout << "NAME: " << Name << "\t"
         << "ID: " << Id << endl;
}

class Manager : public Employee
{
public:
    Manager(string name, string id, float s = 0.0) : Employee(name, id)
    {
        weeklySalary = s;
    }
    void setSalary(float s) { weeklySalary = s; }
    float getSalary() { return weeklySalary; }
    void print()
    {
        cout << "Manager: " << getName() << "\t\t ID: " << getId() << "\t\t weeklySalary: " << getSalary() << endl;
    }

private:
    float weeklySalary; // 周薪
};

/*
不论哪种赋值方式，都只能通过基类对象（或基类对象的指针或引用）访问到派生类对象从基类中继承到的成员， 
不能借此访问派生类定义的成员。而虚函数使得可以通过基类对象的指针或引用访问派生类定义的成员。
*/
// Virtual关键字其实质是告知编译系统，被指定为virtual的函数采用动态联编的形式编译。
int main(int argc, char const *argv[])
{
    Employee e("mxd", "NO0002"), *pM;
    Manager m("mcd", "NO0001", 256);
    m.print();
    pM= &m;
    pM->print();
    Employee &rM = m;
    rM.print();
    return 0;
}