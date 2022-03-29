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
 * @LastEditTime : 2022-03-25 14:14:07
 * @FilePath     : /My_Cpp_test/Practice/文件与流/文件与流.cpp
 * @Description  : 用cin输入字符串数据时，如果字符串中含有空白就不能完整输入。因为遇到空白字符时，cin就认为字符串结束了。
 * 
 * ******************************************
 */

#include <climits>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // 1
#if 0
    char a[50];
    cout << "please input a string: ";
    cin >> a; // 输入this is a string!，  只输出 this
    cout << a << endl;
#endif

// 2
#if 0
    char stu[5][10];
    int i;
    for (i = 0; i < 5; i++) {
        cin.getline(stu[i], 10, ',');
    }
    for (i = 0; i < 5; i++) {
        cout << stu[i] << endl;
    }
#endif

    // 3
    char c;
    char b[50] = "this is a string...";
    cout << "use get() input char : ";
    while ((c = cin.get()) != '\n') {
        cout.put(c);
        cout.put('\n');
        cout.put('t').put('h').put('i').put('s').put('\n');
        cout.write(b, 50).put('\n');
        cout << "look"
             << "\t there" << endl;
    }

    return 0;
}
/*
若a的内容是：
this is a string! 
就难以输入啦！
这样的数据应用输入流类的成员函数输入
*/