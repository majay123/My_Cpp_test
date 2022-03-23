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
 * @Date         : 2022-03-23 13:32:59
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-23 14:29:37
 * @FilePath     : /My_Cpp_test/Practice/时钟练习题/重载的operator.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <iostream>
#include <climits>

using namespace std;

class person
{
private:
    int age;

public:
    person(int a)
    {
        this->age = a;
    }
    inline bool operator==(const person &other) const;
};

// class person1
// {
// public:
//     int age;

// public:
//     person1(int _age = 0):age(_age)
//     {
//         cout << "person1 (int _age)" << endl;
//     }

//     person1(person1& ps)
//     {
//         *this = ps;
//     }

//     // bool operator==(const person1 &other, person1 const &other1);
// };

class Test
{
    public:
        Test(int x = 3){m_value = x;}
        Test &operator ++();    // 前增量
        Test &operator ++(int); // 后增量
    private:
        int m_value;
};

Test &Test::operator ++()
{
    m_value++;      // 先增加
    return *this;   // 返回当前对象
}

Test &Test::operator ++(int)
{
    Test temp(*this);   // 创建临时对象
    m_value++;          // 再增量
    return temp;        // 返回临时对象
}

inline bool person::operator==(const person &other) const
{
    if (this->age == other.age)
        return true;
    else
        return false;
}

// bool person1::operator==(const person1 &other, person1 const &other1)
// {
//     if(other.age == other1.age)
//         return true;
//     else
//         return false;
// }

int main(int argc, char const *argv[])
{
    person p1(10);
    person p2(20);

    if (p1 == p2)
        cout << "age is equal!" << endl;
    else
        cout << "age is not equal!" << endl;

    return 0;
}