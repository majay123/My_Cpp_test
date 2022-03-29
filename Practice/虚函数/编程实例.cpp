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
 * @LastEditTime : 2022-03-24 15:33:13
 * @FilePath     : /My_Cpp_test/Practice/虚函数/编程实例.cpp
 * @Description  : 
 * 某公司有经理、销售员、小时工等多类人员。经理按周计算薪金；销售员每月底薪800元，
 * 然后加销售提成，每销售1件产品提取销售利润的5%；小时工按小时计算薪金。每类人员都有姓名和身份证号等数据。
 * 为简化问题，把各类人员的共有信息抽象成基类Employee，其他人员则继承该类的功能。 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

class Employee
{
public:
    Employee(string name, string id)
    {
        Name = name;
        Id = id;
    }
    string getName() const { return Name; }
    string getId() const { return Id; }
    float getSalary() { return 0.0; }
    void print()
    {
        cout << "Employee: " << Name << "\t\t Id: " << Id << endl;
    }

private:
    string Name, Id;
};

class Manager : public Employee
{
public:
    Manager(string name, string id, int weeks) : Employee(name, id)
    {
        weeklySalary = weeks * 2000;
    }
    float getWeeklySalary() { return weeklySalary; }
    void print()
    {
        cout << "Manager: " << getName() << "\t\t Id: " << getId() << "\t\t allSalary: " << getWeeklySalary() << endl;
    }

private:
    float weeklySalary;
};

class SaleWorker : public Employee
{
public:
    SaleWorker(string name, string id, int profit, int x) : Employee(name, id)
    {
        workerMoney = baseMoney + x * profit * 0.05;
    }
    float getSalary()
    {
        return workerMoney;
    }
    void print()
    {
        cout << "SaleWorker: " << getName() << "\t\t Id: " << getId() << "\t\t allSalary: " << getSalary() << endl;
    }

private:
    float baseMoney = 800.0;
    float workerMoney;
};

class HourWorker : public Employee
{
public:
    HourWorker(string name, string Id, int hours) : Employee(name, Id)
    {
        totalMoney = hours * HourMoney;
    }
    float getSalary()
    {
        return totalMoney;
    }
    void print()
    {
        cout << "HourWorker: " << getName() << "\t\t Id: " << getId() << "\t\t allSalary: " << getSalary() << endl;
    }

private:
    float totalMoney;
    float HourMoney = 100.0;
};

int main(int argc, char const *argv[])
{
    cout << "Please enter work weeks: ";
    int weeks = 0;
    cin >> weeks;
    // weeks = 4;
    Manager m("mcd", "ID0001", weeks);
    m.print();

    cout << "Please enter Sales profit: ";
    int profit = 0, x = 0;
    cin >> profit;
    cout << "Please enter sales volume: ";
    cin >> x;
    SaleWorker s("mxd", "ID0002", profit, x);
    s.print();

    cout << "Please enter Working hours: ";
    int hours = 0;
    cin >> hours;
    HourWorker h("msd", "ID0003", hours);
    h.print();

    return 0;
}