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
 * @LastEditTime : 2022-03-25 15:52:11
 * @FilePath     : /My_Cpp_test/Practice/文件与流/文件与流练习.cpp
 * @Description  : 用cin输入字符串数据时，如果字符串中含有空白就不能完整输入。因为遇到空白字符时，cin就认为字符串结束了。
 * 
 * ******************************************
 */

#include <climits>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
//向量是一个能够存放任意类型的动态数组
#include <vector>

using namespace std;

class Person
{
  private:
    char name[20];
    char id[20];
    int age;
    char addr[20];

  public:
    Person() {}
    Person(char *n, char *pid, int a, char *add)
    {
        strcpy(name, n);
        strcpy(id, pid);
        strcpy(add, addr);
        age = a;
    }

    void display()
    {
        cout << name << "\t" << id << "\t" << age << "\t" << addr << endl;
    }
};

int main(int argc, char const *argv[])
{
    vector<Person> v;
    vector<Person>::iterator pos; // 声明一个迭代器，来访问vector容器，作用：遍历或者指向vector容器的元素
    char ch;
    ofstream out("./test.txt", ios::out | ios::binary | ios::app);
    char Name[20], ID[20], Addr[20];
    int Age;

    cout << "=======输入个人档案=======" << endl
         << endl;
    do {
        cout << "姓名: ";
        cin >> Name;
        cout << "身份证号: ";
        cin >> ID;
        cout << "年龄: ";
        cin >> Age;
        cout << "地址: ";
        cin >> Addr;

        Person per(Name, ID, Age, Addr);
        out.write((char *)&per, sizeof(per));
        cout << "Enter another Person(y/n)?";
        cin >> ch;
    } while (ch == 'y');
    out.close();

    ifstream in("./test.txt", ios::in | ios::binary);
    Person s;
    in.read((char *)&s, sizeof(s));
    while (!in.eof()) {
        v.push_back(s); // 取一个Person放入容器
        in.read((char *)&s, sizeof(s));
    }
    cout << "\n---------从文件中读出的数据--------" << endl
         << endl;
    pos = v.begin();
    for (pos = v.begin(); pos != v.end(); pos++)
        (*pos).display();

    in.close();

    return 0;
}
