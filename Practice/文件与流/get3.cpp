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
 * @Date         : 2022-03-25 15:56:53
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-25 16:14:21
 * @FilePath     : /My_Cpp_test/Practice/文件与流/get3.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <climits>
#include <iostream>

using namespace std;
/*
（1）cin.getline(arrayname,size)与cin.get(arrayname,size)的区别
cin.get(arrayname,size)当遇到[enter]时会结束目前输入，他不会删除缓冲区中的[enter]
cin.getline(arrayname,size)当遇到[enter]时会结束当前输入，但是会删除缓冲区中的[enter]
*/

int main(int argc, char const *argv[])
{
    /*
	char a[10];
    char b;
    cin.get(a,10);
	cin.get(b);
    cout<<a<<endl<<int(b);//输入：12345[enter] 输出：12345 【换行】 10*/
    /*char c[10];
    char d;
    cin.getline(c,10);
    cin.get(d);
	cout<<c<<endl<<int(d);//输入：12345[enter]a[enter] 输出：12345【换行】97*/
    //cin.getline(arrayname,size,s)与cin.gei(arrayname,size,s)的区别
    /*
    cin.getline(arrayname,size,s)当遇到s时会结束输入，并把s从缓冲区中删除
    cin.get（arrayname,size,s）当遇到s时会结束输入，但不会删除缓冲区中的s
    */
   
    // char e[10];
    // char f;
    // cin.get(e,10,',');
	// cin.get(f);
	// cout<<e<<endl<<f;//输入：12345,[enter] 输出：12345【换行】，说明：cin,get不会删除缓冲区的，

    char e1[10];
    char f1;
    cin.getline(e1, 10, ',');
    cin.get(f1);
    cout << e1 << endl
         << f1 << endl; //输入：asd,wqe 输出：asd【换行】w

    return 0;
}
