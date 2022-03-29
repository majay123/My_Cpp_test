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
 * @Date         : 2022-03-25 12:38:16
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-25 13:26:12
 * @FilePath     : /My_Cpp_test/Practice/异常处理/异常处理6.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <climits>
#include <iostream>

using namespace std;

class A
{
    int a;

  public:
    A(int i = 0) : a(i){};
    ~A() { cout << "in A destructor..." << endl; }
};

class B
{
    A obj[3];
    double *pb[10];

  public:
    B(int k)
    {
        cout << "int B constructor..." << endl;
        for (int i = 0; i < 10; i++) {
            pb[i] = new double[20000000];
            if (pb[i] == 0)
                throw i;
            else
                cout << "Allocated 20000000 doubles  in pb [" << i << "]" << " = "<< pb[i] << endl;
        }
    }
    ~B (){
        delete [] *pb;
    }
};

int main(int argc, char const *argv[])
{
    try {
        B b(2);
        // Errhandler(10);
    } catch (int x) {
        cout << "catch int an exception when allocate pb[" << x << "]" << endl;
    }
    cout << "...end..." << endl;

    return 0;
}