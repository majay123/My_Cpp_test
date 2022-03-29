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
 * @Date         : 2022-03-24 16:25:10
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-24 17:12:55
 * @FilePath     : /My_Cpp_test/Practice/运算符重载/方括号运算符.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

struct Person       // 职工基本信息结构
{
    double salary;
    char *name;
};

class SalaryManager
{
    Person *employ;     // 存放职工信息的数组
    int max;            // 数组下标上限
    int n;              // 数组中的实际职工人数

public:
    SalaryManager(int Max = 0)
    {
        max = Max;
        n = 0;
        employ = new Person[max];
    }
    double &operator[](char *name){     // 重载[]， 返回引用
        Person *p;
        double d = 0.0;
        if(n <= max) {
                for (p = employ; p < employ + n; p++)
            {
                if(strcmp(p->name, name) == 0)
                    return p->salary;
            }

            p = employ + n++;
            p->name = new char[strlen(name) + 1];
            strcpy(p->name, name);
            p->salary = 0;
            
            return p->salary;
        }else {
            cout << "member is out of max" << endl;
            p->salary = 0;
        }

        return p->salary;
    }

    void display()
    {
        cout << n << endl;
        for (int i = 0; i < (n > max ? max : n); i++)
            cout << employ[i].name << "\t\t"<< employ[i].salary << endl;
    }

    ~SalaryManager(){ 
        cout << n << endl;
        for(int i = 0; i < (n > max ? max : n); i++)
            delete employ[i].name;
        delete employ;
    }

};

int main(int argc, char const *argv[])
{
    SalaryManager s(3);

    // s[(char *)"xm"] = 100000;
    // s[(char *)"xd"] = 2000;
    // s[(char *)"xc"] = 300;

    s[(char *)"张三"]=2188.88;
    s[(char *)"里斯"]=1230.07;
    s.display();
    // s[(char *)"王无"]=3200.97;
    // cout<<"张三\t"<<s[(char *)"张三"]<<endl;          
    // cout<<"里斯\t"<<s[(char *)"里斯"]<<endl;
    // cout<<"王无\t"<<s[(char *)"王无"]<<endl;
    // cout<<"王无1\t"<<s[(char *)"王无1"]<<endl;

    return 0;
}