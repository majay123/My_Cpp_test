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
 * @LastEditTime : 2022-03-25 14:39:25
 * @FilePath     : /My_Cpp_test/Practice/文件与流/文件与流1.cpp
 * @Description  : 用cin输入字符串数据时，如果字符串中含有空白就不能完整输入。因为遇到空白字符时，cin就认为字符串结束了。
 * 
 * ******************************************
 */

#include <climits>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
    // 1
#if 0
    char c[30]="this is string";
    double d = -1231.232;
    cout.width(30);
    cout.fill('*');
    cout.setf(ios::left);
    cout<<c<<"----L1"<<endl;

    cout.width(30);
    cout.fill('~');
    cout.setf(ios::right);
    cout<<c<<"----L2"<<endl;

    cout.setf(ios::dec|ios::showbase|ios::showpoint);
    cout.width(30);
    cout<<d<<"----L3"<<"\n";

    cout.setf(ios::showpoint);
    cout.precision(10);
    cout.width(30);
    cout<<d<<"----L4"<<"\n";

    cout.width(30);
    cout.setf(ios::oct,ios::basefield); // 8进制
    cout<<100<<"----L5"<<"\n";
#endif

    char c[30] = "this is string";
    double d = -1234.8976;
    cout << setw(30) << left << setfill('*') << c << "----L1" << endl;
    cout << setw(30) << right << setfill('*') << c << "----L2" << endl;
    //showbase显示数值的基数前缀
    cout << dec << showbase << showpoint << setw(30) << d << "----L3"
         << "\n";
    //showpoint显示小数点
    cout << setw(30) << showpoint << setprecision(10) << d << "----L4"
         << "\n";
    //setbase(8)设置八进制
    cout << setw(30) << setbase(16) << 100 << "----L5"
         << "\n";

    return 0;
}
