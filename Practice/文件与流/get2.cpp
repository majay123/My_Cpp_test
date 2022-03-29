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
 * @LastEditTime : 2022-03-25 16:02:19
 * @FilePath     : /My_Cpp_test/Practice/文件与流/get2.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <climits>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    //get()两个参数

    //1.输入串长<size，输入串长>arraylength，会自动扩张arrayname大小，使能保存所有数据
	// char a[10];
	// cin.get(a,20);
	// cout<<a<<endl;
    // cout<<sizeof(a)<<endl;
    //2.输入串长<size，输入串长<arraylength，把串全部输入，后面补‘\0’
    // char b[10];
	// cin.get(b,20);
	// cout<<b<<endl;//12345，此时数组内数据为‘12345'\0’
    // cout<<sizeof(b)<<endl;
    //3.输入串长>size，先截取size个字符，若还是大于arraylength，则输入前arraylength-1个字符，最后补充‘\0’
    // char c[5];
	// cin.get(c,10);
	// cout<<c<<endl;
    // cout<<sizeof(c)<<endl;
    //4.输入串长>size，先截取size个字符，若小于arraylength，则把截取串放入数组中，最后补充‘\0’
    // char d[10];
	// cin.get(d,5);
	// cout<<d<<endl;
    // cout<<sizeof(d)<<endl;
    
    //get()三个参数
    
    /*
        用法：cin.get(arrayname,size,s) ?把数据输入到arrayname字符数组中，当到达长度size时结束或者遇到字符s时结束
        注释：a必须是字符数组，即char a[]l类型，不可为string类型；size为最大的输入长度；s为控制，遇到s则当前输入结束缓存区里的s将被舍弃
    */
    int i;
    char e[10];
    cin.get(e, 8, ','); // 获取输入的头8个字符，如果有','的话 就取','前面的
    cout << e;

    return 0;
}