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
 * @Date         : 2022-03-25 14:01:06
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-25 15:28:28
 * @FilePath     : /My_Cpp_test/Practice/文件与流/文件与流3.cpp
 * @Description  : 用cin输入字符串数据时，如果字符串中含有空白就不能完整输入。因为遇到空白字符时，cin就认为字符串结束了。
 * 
 * ******************************************
 */

#include <climits>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

class Employee
{
  private:
    int number, age;
    char name[20];
    double sal;

  public:
    Employee(){};
    Employee(int num, char *Name, int Age, double salary)
    {
        number = num;
        age = Age;
        strcpy(name, Name);
        sal = salary;
    }

    void display()
    {
        cout << number << "\t" << name << "\t" << age << "\t" << sal << endl;
    }
};

int main(int argc, char const *argv[])
{
    ofstream out ("./test.txt", ios::out);  // 定义随机输出文件
    Employee e1(1, "mcd", 23, 22230);
    Employee e2(2, "mxd", 26, 12450);
    Employee e3(3, "mzz", 29, 12230);
    Employee e4(4, "msa", 21, 32330);
    Employee e5(5, "mg", 32, 22440);
    out.write((char *)&e1, sizeof(e1));
    out.write((char *)&e2, sizeof(e2));
    out.write((char *)&e3, sizeof(e3));
    out.write((char *)&e4, sizeof(e4));
    out.write((char *)&e5, sizeof(e5));

    // 下面的代码将a3 的年龄改为44
    Employee e6(3, "mzz", 44, 12230);
    out.seekp(3 *sizeof(e1));               //指针定位到第3（起始为0）个数据块
    out.write((char *)&e6, sizeof(e6));     //将e5写到第3个数据块位置，覆盖e3
    out.close();

    return 0;
}
